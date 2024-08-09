/**
 * \file IfxGtm_Tom_Pwm.c
 * \brief GTM PWM details
 *
 * \version iLLD_2_0_1_2_19
 * \copyright Copyright (c) 2022 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxGtm_Tom_Pwm.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxGtm_Tom_Pwm_init(IfxGtm_Tom_Pwm_Driver *driver, const IfxGtm_Tom_Pwm_Config *config)
{
    boolean          result = TRUE;

    Ifx_GTM_CLS_TOM *tomSFR = &config->gtm->CLS[config->cluster].TOM;

    /* Copy config data into handle */
    driver->gtm        = config->gtm;
    driver->clsIndex   = config->cluster;
    driver->tom        = tomSFR;
    driver->tomChannel = config->tomChannel;

    if (config->tomChannel <= IfxGtm_Tom_Ch_7)
    {
        driver->tgc[0] = IfxGtm_Tom_Ch_getTgcPointer(driver->tom, 0);
        driver->tgc[1] = IfxGtm_Tom_Ch_getTgcPointer(driver->tom, 1);
    }
    else
    {
        driver->tgc[0] = IfxGtm_Tom_Ch_getTgcPointer(driver->tom, 1);
        driver->tgc[1] = NULL_PTR; /* NOTE currently no concatenation between TOMs */
    }

    /* Enable update of CM0/1 from shadow registers */
    if (config->synchronousUpdateEnabled == TRUE)
    {
        IfxGtm_Tom_Tgc_enableChannelUpdate(driver->tgc[0], config->tomChannel, TRUE);
    }

    /* Set channel to start counter when trigger is received */
    IfxGtm_Tom_Tgc_enableChannel(driver->tgc[0], config->tomChannel, TRUE, FALSE);

    /* Set channel to start PWM output when trigger is received */
    IfxGtm_Tom_Tgc_enableChannelOutput(driver->tgc[0], config->tomChannel, TRUE, FALSE);

    /* Set TOM channel clock source */
    IfxGtm_Tom_Ch_setClockSource(tomSFR, config->tomChannel, config->clock);

    /* Set Signal Polarity value here */
    IfxGtm_Tom_Ch_setSignalLevel(tomSFR, config->tomChannel, config->signalLevel);

    /* Reset counter to 0 */
    IfxGtm_Tom_Ch_setCounterValue(tomSFR, driver->tomChannel, 0);

    /* Enable and initialize interrupts if chosen */
    if ((config->interrupt.ccu0Enabled == TRUE) || (config->interrupt.ccu1Enabled == TRUE))
    {
        volatile Ifx_SRC_SRCR *src;
        IfxGtm_Tom_Ch_setNotification(tomSFR, config->tomChannel, config->interrupt.mode, config->interrupt.ccu0Enabled, config->interrupt.ccu1Enabled);

        src = IfxGtm_Tom_Ch_getSrcPointer(config->gtm, config->cluster, config->tomChannel);
        IfxSrc_init(src, config->interrupt.isrProvider, config->interrupt.isrPriority, config->interrupt.vmId);
        IfxSrc_enable(src);
    }
    /* Disable interrupt */
    else
    {
        Ifx_GTM_CLS_TOM_CH *channel = &tomSFR->CH[driver->tomChannel];
        channel->IRQ_EN.U = 0u;
    }

    /* Set CM0, CM1, SR0, SR1 registers */
    if (config->synchronousUpdateEnabled == TRUE)
    {
        IfxGtm_Tom_Ch_setCompareZeroShadow(tomSFR, config->tomChannel, config->period);
        IfxGtm_Tom_Ch_setCompareOneShadow(tomSFR, config->tomChannel, config->dutyCycle);
    }
    else
    {
        IfxGtm_Tom_Ch_setCompareZero(tomSFR, config->tomChannel, config->period);
        IfxGtm_Tom_Ch_setCompareOne(tomSFR, config->tomChannel, config->dutyCycle);
    }

    /* Connect output pin to Tom channel */
    if (config->pin.outputPin != NULL_PTR)
    {
        IfxGtm_PinMap_setTomTout(config->pin.outputPin, config->pin.outputMode, config->pin.padDriver);
    }

    /* Connect Msc to Tom channel */
    if (config->mscOut != NULL_PTR)
    {
        (void)IfxGtm_ConnectToMsc(config->cluster, IfxGtm_TrigSource_tom, (IfxGtm_TrigChannel)config->tomChannel, config->mscOut);
    }

    /* Start channel by giving a trigger */
    if (config->immediateStartEnabled == TRUE)
    {
        IfxGtm_Tom_Tgc_trigger(driver->tgc[0]);
    }

    return result;
}


void IfxGtm_Tom_Pwm_initConfig(IfxGtm_Tom_Pwm_Config *config, Ifx_GTM *gtm)
{
    const IfxGtm_Tom_Pwm_Config defaultConfig = {
        .gtm         = NULL_PTR,
        .cluster     = IfxGtm_Cluster_0,
        .tomChannel  = IfxGtm_Tom_Ch_0,
        .clock       = IfxGtm_Tom_Ch_ClkSrc_cmuFxclk0,
        .signalLevel = Ifx_ActiveState_high,
        .period      = 20,
        .dutyCycle   = 10,
        .interrupt   = {
            .ccu0Enabled = FALSE,
            .ccu1Enabled = FALSE,
            .mode        = IfxGtm_IrqMode_pulseNotify,
            .isrProvider = IfxSrc_Tos_cpu0,
            .isrPriority = 0,
            .vmId        = IfxSrc_VmId_0,
        },
        .pin                      = {
            .outputPin  = NULL_PTR,
            .outputMode = IfxPort_OutputMode_pushPull,
            .padDriver  = IfxPort_PadDriver_cmosAutomotiveSpeed1,
        },
        .mscOut                   = NULL_PTR,
        .dtmClockSource           = IfxGtm_Dtm_ClockSource_cmuClock0,
        .oneShotModeEnabled       = FALSE,
        .synchronousUpdateEnabled = FALSE,
        .immediateStartEnabled    = TRUE,
    };

    /* Default Configuration */
    *config = defaultConfig;

    /* Copy SFR */
    config->gtm = gtm;
}


void IfxGtm_Tom_Pwm_start(IfxGtm_Tom_Pwm_Driver *driver, boolean immediate)
{
    /* Enable channel if not enabled already */
    IfxGtm_Tom_Tgc_enableChannel(driver->tgc[0], driver->tomChannel, TRUE, immediate);
    IfxGtm_Tom_Tgc_enableChannelOutput(driver->tgc[0], driver->tomChannel, TRUE, immediate);

    /* Trigger the start now */
    IfxGtm_Tom_Tgc_trigger(driver->tgc[0]);
}


void IfxGtm_Tom_Pwm_stop(IfxGtm_Tom_Pwm_Driver *driver, boolean immediate)
{
    /* Disable channels */
    IfxGtm_Tom_Tgc_enableChannel(driver->tgc[0], driver->tomChannel, FALSE, immediate);
    IfxGtm_Tom_Tgc_enableChannelOutput(driver->tgc[0], driver->tomChannel, FALSE, immediate);

    /* Trigger the stop now */
    IfxGtm_Tom_Tgc_trigger(driver->tgc[0]);
}
