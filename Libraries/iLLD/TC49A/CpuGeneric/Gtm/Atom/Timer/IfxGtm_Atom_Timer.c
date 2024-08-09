/**
 * \file IfxGtm_Atom_Timer.c
 * \brief GTM TIMER details
 *
 * \version iLLD_2_0_1_2_19
 * \copyright Copyright (c) 2023 Infineon Technologies AG. All rights reserved.
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

#include "IfxGtm_Atom_Timer.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxGtm_Atom_Timer_acknowledgeTimerIrq(IfxGtm_Atom_Timer *driver)
{
    boolean event;
    event = IfxGtm_Atom_Ch_isZeroNotification(driver->atom, driver->timerChannel);

    if (event == TRUE)
    {
        IfxGtm_Atom_Ch_clearZeroNotification(driver->atom, driver->timerChannel);
    }

    return event;
}


boolean IfxGtm_Atom_Timer_acknowledgeTriggerIrq(IfxGtm_Atom_Timer *driver)
{
    boolean event;
    event = IfxGtm_Atom_Ch_isOneNotification(driver->atom, driver->triggerChannel);

    if (event == TRUE)
    {
        IfxGtm_Atom_Ch_clearOneNotification(driver->atom, driver->triggerChannel);
    }

    return event;
}


boolean IfxGtm_Atom_Timer_init(IfxGtm_Atom_Timer *driver, const IfxGtm_Atom_Timer_Config *config)
{
    boolean result = TRUE;

    /* Only count direction "up" is supported */
    if (config->countDir == IfxGtm_Atom_Timer_CountDir_up)
    {
        /* Initialize handle */
        {
            driver->gtm            = config->gtm;
            driver->clsIndex       = config->cluster;
            driver->atom           = &config->gtm->CLS[config->cluster].ATOM;
            driver->timerChannel   = config->timerChannel;
            driver->triggerEnabled = config->trigger.enabled;

            if (driver->triggerEnabled == TRUE)
            {
                if (config->triggerOut != NULL_PTR)
                {
                    driver->triggerChannel = config->triggerOut->channel;
                }
                else
                {
                    result = FALSE;
                    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, result); /* triggerOut is required */
                }
            }
            else
            {
                driver->triggerChannel = driver->timerChannel; // Set to timer channel to disable its use
            }

            driver->agc              = (Ifx_GTM_CLS_ATOM_AGC *)(volatile void *)&driver->atom->AGC.GLB_CTRL;

            driver->channelsMask     = 0;
            driver->agcApplyUpdate   = 0;
            driver->agcDisableUpdate = 0;
        }

        /* Initialize the timer part */
        {
            /* Set CTRL register */
            IfxGtm_Atom_Ch_configurePwmMode(driver->atom, driver->timerChannel, config->clock,
                (Ifx_ActiveState)config->trigger.risingEdgeAtPeriod, IfxGtm_Atom_Ch_ResetEvent_onCm0,
                IfxGtm_Atom_Ch_OutputTrigger_generate);

            /* Store Clock frequency in the driver */
            IfxGtm_Atom_Timer_updateInputFrequency(driver);

            /* This if block has no effect. TODO: Remove/review */
            if ((config->minResolution > 0.0f) && (driver->clockFreq > 0.0f) && ((1.0f / driver->clockFreq) > config->minResolution))
            {
                result = FALSE;
                IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
            }

            /* Set PWM frequency by setting CM0 register */
            (void)IfxGtm_Atom_Timer_setFrequency(driver, config->frequency);

            /* Initialize CN0 (counter register) with an initial offset configured by user */
            driver->offset = IfxGtm_sToTick(driver->clockFreq, (float32)1.0f / config->frequency * config->startOffset);
            IfxGtm_Atom_Ch_setCounterValue(driver->atom, driver->timerChannel, driver->offset);

            /* Initialize the trigger part */
            IfxGtm_Atom_Timer_addToChannelMask(driver, driver->timerChannel);
        }

        /* Initialize the trigger part */
        if (driver->triggerEnabled == TRUE)
        {
            IfxGtm_Atom_Ch triggerChannel     = driver->triggerChannel;
            uint16         triggerChannelMask = (uint16)((uint16)1u << (uint16)triggerChannel);

            /* Set channel signal level */
            IfxGtm_Atom_Ch_setSignalLevel(driver->atom, triggerChannel, (config->trigger.risingEdgeAtPeriod == TRUE) ? Ifx_ActiveState_high : Ifx_ActiveState_low);

            if (triggerChannel != driver->timerChannel)
            {
                /* Set CTRL register */
                IfxGtm_Atom_Ch_configurePwmMode(driver->atom, triggerChannel, config->clock,
                    (Ifx_ActiveState)config->trigger.risingEdgeAtPeriod, IfxGtm_Atom_Ch_ResetEvent_onTrigger,
                    IfxGtm_Atom_Ch_OutputTrigger_forward);

                /* Initialize CN0 (counter register) with an initial offset configured by user */
                IfxGtm_Atom_Ch_setCounterValue(driver->atom, triggerChannel, driver->offset);

                /* Set channels to start counter when trigger is received TODO: Remove? */
                IfxGtm_Atom_Agc_enableChannels(driver->agc, triggerChannelMask, 0, FALSE);

                /* Add trigger channel to channel mask */
                IfxGtm_Atom_Timer_addToChannelMask(driver, driver->triggerChannel);
            }

            /* Signal must go out of the GTM even if the port outpout is not enabled */
            IfxGtm_Atom_Agc_enableChannelsOutput(driver->agc, triggerChannelMask, 0, FALSE);

            /* Initialize the port */
            if ((config->trigger.outputEnabled == TRUE) && (config->initPins == TRUE))
            {
                IfxGtm_PinMap_setAtomTout(config->triggerOut, config->trigger.outputMode, config->trigger.outputDriver);
            }

            /* Set CM1 register */
            IfxGtm_Atom_Timer_setTrigger(driver, config->trigger.triggerPoint);
        }

        /* Interrupt configuration */
        {
            volatile Ifx_SRC_SRCR *src;
            boolean                timerHasIrq   = (config->interrupt.isrPriority > 0) ? TRUE : FALSE;
            boolean                triggerHasIrq = ((config->trigger.interrupt.isrPriority > 0) && (driver->triggerEnabled == TRUE)) ? TRUE : FALSE;

            if (driver->triggerChannel == driver->timerChannel)
            {
                IfxGtm_Atom_Ch_setNotification(driver->atom, driver->timerChannel, (timerHasIrq == TRUE) ? config->interrupt.irqMode : config->trigger.interrupt.irqMode, timerHasIrq, triggerHasIrq);
                src = IfxGtm_Atom_Ch_getSrcPointer(driver->gtm, config->cluster, driver->timerChannel);
                IfxSrc_init(src, (timerHasIrq == TRUE) ? config->interrupt.isrProvider : config->trigger.interrupt.isrProvider, (timerHasIrq == TRUE) ? config->interrupt.isrPriority : config->trigger.interrupt.isrPriority, config->interrupt.vmId);
                IfxSrc_enable(src);
            }
            else
            {
                IfxGtm_IrqMode irqMode = IfxGtm_IrqMode_pulseNotify;

                if (timerHasIrq == TRUE)
                {
                    IfxGtm_Atom_Ch_setNotification(driver->atom, driver->timerChannel, irqMode, TRUE, FALSE);
                    src = IfxGtm_Atom_Ch_getSrcPointer(driver->gtm, config->cluster, driver->timerChannel);
                    IfxSrc_init(src, config->interrupt.isrProvider, config->interrupt.isrPriority, config->interrupt.vmId);
                    IfxSrc_enable(src);
                }

                if (triggerHasIrq == TRUE)
                {
                    IfxGtm_Atom_Ch_setNotification(driver->atom, driver->triggerChannel, irqMode, FALSE, TRUE);
                    src = IfxGtm_Atom_Ch_getSrcPointer(driver->gtm, config->cluster, driver->triggerChannel);
                    IfxSrc_init(src, config->trigger.interrupt.isrProvider, config->trigger.interrupt.isrPriority, config->trigger.interrupt.vmId);
                    IfxSrc_enable(src);
                }
            }
        }

        /* Transfer values from shadow registers */
        {
            /* Enable force update from shadow of timer/trigger channel */
            IfxGtm_Atom_Agc_setChannelsForceUpdate(driver->agc, driver->channelsMask, 0, 0, 0);

            /* Give host trigger to start channel(s) */
            IfxGtm_Atom_Agc_trigger(driver->agc);

            /* Disable force update from shadow of timer/trigger channel */
            IfxGtm_Atom_Agc_setChannelsForceUpdate(driver->agc, 0, driver->channelsMask, 0, 0);
        }
    }
    else
    {
        result = FALSE;
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, config->countDir == IfxGtm_Atom_Timer_CountDir_up);    /* only this mode is supported */
    }

    return result;
}


void IfxGtm_Atom_Timer_initConfig(IfxGtm_Atom_Timer_Config *config, Ifx_GTM *gtm)
{
    const IfxGtm_Atom_Timer_Config defaultConfig = {
        .gtm            = NULL_PTR,
        .cluster        = IfxGtm_Cluster_0,
        .timerChannel   = IfxGtm_Atom_Ch_0,
        .triggerOut     = NULL_PTR,
        .clock          = IfxGtm_Atom_Ch_ClkSrc_cmuclk0,
        .dtmClockSource = IfxGtm_Dtm_ClockSource_cmuClock0,
        .frequency      = 1000.0f,
        .minResolution  = 0.0f,
        .startOffset    = 0.0f,
        .countDir       = IfxGtm_Atom_Timer_CountDir_up,
        .interrupt      = {
            .isrPriority = 0u,
            .isrProvider = IfxSrc_Tos_cpu0,
            .irqMode     = IfxGtm_IrqMode_level,
            .vmId        = IfxSrc_VmId_0,
        },
        .trigger                = {
            .enabled            = FALSE,
            .triggerPoint       = 0u,
            .outputMode         = IfxPort_OutputMode_pushPull,
            .outputDriver       = IfxPort_PadDriver_cmosAutomotiveSpeed1,
            .risingEdgeAtPeriod = FALSE,
            .outputEnabled      = FALSE,
            .interrupt          = {
                .isrPriority = 0u,
                .isrProvider = IfxSrc_Tos_cpu0,
                .irqMode     = IfxGtm_IrqMode_level,
                .vmId        = IfxSrc_VmId_0,
            },
        },
        .initPins               = TRUE,
    };

    /* Default Configuration */
    *config = defaultConfig;

    /* Copy SFR */
    config->gtm = gtm;
}


void IfxGtm_Atom_Timer_run(IfxGtm_Atom_Timer *driver)
{
    IfxGtm_Atom_Agc_enableChannels(driver->agc, driver->channelsMask, 0, TRUE);
}


void IfxGtm_Atom_Timer_stop(IfxGtm_Atom_Timer *driver)
{
    IfxGtm_Atom_Agc_enableChannels(driver->agc, 0, driver->channelsMask, TRUE);
}
