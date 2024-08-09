/**
 * \file IfxEgtm_Tim_In.c
 * \brief EGTM IN details
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

#include "IfxEgtm_Tim_In.h"
#include "IfxEgtm_bf.h"
#include "string.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxEgtm_Tim_In_init(IfxEgtm_Tim_In *driver, const IfxEgtm_Tim_In_Config *config)
{
    boolean              result = TRUE;
    Ifx_EGTM_CLS_TIM_CH *channel;
    IfxEgtm_Tim_Ch       channelIndex;
    IfxEgtm_Cluster      clsIndex;
    IfxEgtm_Tim_In_Input input;

    if (config->filter.inputPin != NULL_PTR)
    {
        channelIndex = config->filter.inputPin->channel;
        clsIndex     = (IfxEgtm_Cluster)config->filter.inputPin->tim;

        input        = IfxEgtm_Tim_In_Input_currentChannel;
    }
    else
    {
        channelIndex = config->channelIndex;
        clsIndex     = config->cluster;
        input        = config->filter.input;
    }

    channel                  = IfxEgtm_Tim_getChannel(&config->egtm->CLS[clsIndex].TIM, channelIndex);
    driver->clsIndex         = config->cluster;
    driver->channelIndex     = config->channelIndex;
    driver->channel          = channel;
    driver->periodTick       = 0;
    driver->pulseLengthTick  = 0;
    driver->dataCoherent     = FALSE;
    driver->newData          = FALSE;
    driver->dataLost         = FALSE;
    driver->overflowCnt      = FALSE;
    driver->edgeCounterUpper = 0;

    channel->CTRL.B.TIM_MODE = (uint8)config->mode;

    IfxEgtm_Tim_Ch_setClockSource(channel, config->capture.clock);

    driver->captureClockFrequency = IfxEgtm_Tim_Ch_getCaptureClockFrequency(config->egtm, channel);

    if ((config->mode == IfxEgtm_Tim_Mode_inputEvent) || (config->mode == IfxEgtm_Tim_Mode_gatedPeriodic))
    {
        channel->CTRL.B.DSL = (config->capture.activeEdge != IfxEgtm_Tim_In_ActiveEdge_both) ? (uint8)config->capture.activeEdge : (uint8)0u;
        channel->CTRL.B.ISL = (config->capture.activeEdge == IfxEgtm_Tim_In_ActiveEdge_both) ? (uint8)1u : (uint8)0u;

        if (config->mode == IfxEgtm_Tim_Mode_gatedPeriodic)
        {
            IfxEgtm_Tim_Ch_setShadowCounter(channel, config->capture.gateCount);
        }
    }
    else
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, (config->mode == IfxEgtm_Tim_Mode_pwmMeasurement));
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, (config->capture.mode == Ifx_Pwm_Mode_leftAligned) || (config->capture.mode == Ifx_Pwm_Mode_rightAligned));
        result             &= ((config->capture.mode == Ifx_Pwm_Mode_leftAligned) || (config->capture.mode == Ifx_Pwm_Mode_rightAligned)) ? TRUE : FALSE;

        channel->CTRL.B.DSL = config->capture.mode == Ifx_Pwm_Mode_leftAligned ? (uint8)1u : (uint8)0u;
    }

    channel->CTRL.B.CNTS_SEL = (uint8)IfxEgtm_Tim_CntsSel_cntReg;
    channel->CTRL.B.GPR0_SEL = (uint8)IfxEgtm_Tim_GprSel_cnts; /* Use CNTS as input for GPR0 */
    channel->CTRL.B.GPR1_SEL = (uint8)IfxEgtm_Tim_GprSel_cnts; /* Use CNT as input for GPR1 */

    /* Interrupt configuration */

    if (config->isrPriority == TRUE)
    {
        volatile Ifx_SRC_SRCR *src;
        IfxEgtm_Tim_Ch_setNotificationMode(channel, config->irqMode);
        IfxEgtm_Tim_Ch_setChannelNotification(channel, config->capture.irqOnNewVal,
            config->capture.irqOnCntOverflow, config->capture.irqOnEcntOverflow, config->capture.irqOnDatalost);

        src = IfxEgtm_Tim_Ch_getSrcPointer(config->egtm, (IfxEgtm_Tim)clsIndex, channelIndex);
        IfxSrc_init(src, config->isrProvider, config->isrPriority, config->vmId);
        IfxSrc_enable(src);
    }

    /* Timeout configuration */
    if (config->timeout.timeout > (float32)0.0f)
    {
        float32 clockFrequency;
        sint32  timeout;
        channel->TDUV.B.TCS = (uint8)config->timeout.clock;
        clockFrequency      = IfxEgtm_Tim_Ch_getTimeoutClockFrequency(config->egtm, channel);

        timeout             = ((sint32)(float32)(config->timeout.timeout * clockFrequency) - 1);

        if (timeout < 0)
        {
            timeout = 0;
        }
        else if (timeout >= (0xFFFFFF))
        {
            timeout = 0xFFFFFF;
            result  = FALSE;
        }
        else
        {}

        channel->CTRL.B.TOCTRL = config->capture.mode == Ifx_Pwm_Mode_leftAligned ? (uint8)IfxEgtm_Tim_Timeout_risingEdge : (uint8)IfxEgtm_Tim_Timeout_fallingEdge;
        channel->TDUV.U       |= (0xFFFFFFu & (uint32)timeout); //24 bit timeout value

        IfxEgtm_Tim_Ch_setTimeoutNotification(channel, config->timeout.irqOnTimeout);
    }

    /* Input configuration */
    config->egtm->CLS[clsIndex].TIM.IN_SRC.U = ((uint32)1u << (IFX_EGTM_CLS_TIM_IN_SRC_MODE0_OFF + (uint8)channelIndex * (IFX_EGTM_CLS_TIM_IN_SRC_MODE1_OFF - IFX_EGTM_CLS_TIM_IN_SRC_MODE0_OFF))); // MODE 0

    switch (input)
    {
    case IfxEgtm_Tim_In_Input_currentChannel:
        config->egtm->CLS[clsIndex].TIM.IN_SRC.U = ((uint32)1u << (IFX_EGTM_CLS_TIM_IN_SRC_VAL0_OFF + (uint8)channelIndex * (IFX_EGTM_CLS_TIM_IN_SRC_VAL1_OFF - IFX_EGTM_CLS_TIM_IN_SRC_VAL0_OFF))); // VAL 0
        channel->CTRL.B.CICTRL                   = (uint8)IfxEgtm_Tim_Input_currentChannel;
        break;
    case IfxEgtm_Tim_In_Input_adjacentChannel:
        config->egtm->CLS[clsIndex].TIM.IN_SRC.U = ((uint32)1u << (IFX_EGTM_CLS_TIM_IN_SRC_VAL0_OFF + (uint8)channelIndex * (IFX_EGTM_CLS_TIM_IN_SRC_VAL1_OFF - IFX_EGTM_CLS_TIM_IN_SRC_VAL0_OFF))); // VAL 0
        channel->CTRL.B.CICTRL                   = (uint8)IfxEgtm_Tim_Input_adjacentChannel;
        break;
    case IfxEgtm_Tim_In_Input_aux:
        config->egtm->CLS[clsIndex].TIM.IN_SRC.U = ((uint32)2u << (IFX_EGTM_CLS_TIM_IN_SRC_VAL0_OFF + (uint8)channelIndex * (IFX_EGTM_CLS_TIM_IN_SRC_VAL1_OFF - IFX_EGTM_CLS_TIM_IN_SRC_VAL0_OFF))); // VAL 1
        break;
    default:
        /* do nothing */
        break;
    }

    if (config->filter.inputPin != NULL_PTR)
    {
        IfxEgtm_PinMap_setTimTin(config->filter.inputPin, config->filter.inputPinMode);
    }

    /*Filter configuration */
    if ((config->filter.fallingEdgeMode != IfxEgtm_Tim_In_ConfigFilterMode_none)
        || (config->filter.risingEdgeMode != IfxEgtm_Tim_In_ConfigFilterMode_none))
    {
        float32 clockFrequency;
        sint32  fallingfilterTime;
        sint32  risingfilterTime;

        channel->CTRL.B.FLT_EN      = 1;
        channel->CTRL.B.FLT_CNT_FRQ = (uint8)config->filter.clock;

        clockFrequency              = IfxEgtm_Tim_Ch_getFilterClockFrequency(config->egtm, channel);

        fallingfilterTime           = ((sint32)(float32)(config->filter.fallingEdgeFilterTime * clockFrequency) - 1);

        if (fallingfilterTime < 0)
        {
            fallingfilterTime = 0;
        }
        else if (fallingfilterTime > (sint32)IFX_EGTM_CLS_TIM_CH_FLT_FE_FLT_FE_MSK)
        {
            fallingfilterTime = (sint32)IFX_EGTM_CLS_TIM_CH_FLT_FE_FLT_FE_MSK;
            result            = FALSE;
        }
        else
        {}

        channel->FLT_FE.B.FLT_FE = (uint32)fallingfilterTime;

        risingfilterTime         = ((sint32)(float32)(config->filter.risingEdgeFilterTime * clockFrequency) - 1);

        if (risingfilterTime < 0)
        {
            risingfilterTime = 0;
        }
        else if (risingfilterTime > (sint32)IFX_EGTM_CLS_TIM_CH_FLT_FE_FLT_FE_MSK)
        {
            risingfilterTime = (sint32)IFX_EGTM_CLS_TIM_CH_FLT_FE_FLT_FE_MSK;
            result           = FALSE;
        }
        else
        {}

        channel->FLT_RE.B.FLT_RE = (uint32)risingfilterTime;

        if (config->filter.fallingEdgeMode != IfxEgtm_Tim_In_ConfigFilterMode_none)
        {
            if (config->filter.fallingEdgeMode == IfxEgtm_Tim_In_ConfigFilterMode_immediateEdgePropagation)
            {
                channel->CTRL.B.FLT_MODE_FE = (uint8)IfxEgtm_Tim_FilterMode_immediateEdgePropagation;
            }
            else
            {
                channel->CTRL.B.FLT_MODE_FE = (uint8)IfxEgtm_Tim_FilterMode_individualDeglitchTime;
                channel->CTRL.B.FLT_CTR_FE  = (config->filter.fallingEdgeMode == IfxEgtm_Tim_In_ConfigFilterMode_individualDeglitchTimeUpDown) ? (uint8)IfxEgtm_Tim_FilterCounter_upDown : (uint8)IfxEgtm_Tim_FilterCounter_hold;
            }
        }
        else
        {
            channel->CTRL.B.FLT_MODE_FE = (uint8)IfxEgtm_Tim_FilterMode_immediateEdgePropagation;
            channel->FLT_FE.B.FLT_FE    = 0;
        }

        if (config->filter.risingEdgeMode != IfxEgtm_Tim_In_ConfigFilterMode_none)
        {
            if (config->filter.risingEdgeMode == IfxEgtm_Tim_In_ConfigFilterMode_immediateEdgePropagation)
            {
                channel->CTRL.B.FLT_MODE_RE = (uint8)IfxEgtm_Tim_FilterMode_immediateEdgePropagation;
            }
            else
            {
                channel->CTRL.B.FLT_MODE_RE = (uint8)IfxEgtm_Tim_FilterMode_individualDeglitchTime;
                channel->CTRL.B.FLT_CTR_RE  = (config->filter.risingEdgeMode == IfxEgtm_Tim_In_ConfigFilterMode_individualDeglitchTimeUpDown) ? (uint8)IfxEgtm_Tim_FilterCounter_upDown : (uint8)IfxEgtm_Tim_FilterCounter_hold;
            }
        }
        else
        {
            channel->CTRL.B.FLT_MODE_RE = (uint8)IfxEgtm_Tim_FilterMode_immediateEdgePropagation;
            channel->FLT_RE.B.FLT_RE    = 0;
        }

        IfxEgtm_Tim_Ch_setFilterNotification(channel, config->filter.irqOnGlitch);
    }

    /* Enable TIM channel */
    channel->CTRL.B.TIM_EN = 1;

    return result;
}


void IfxEgtm_Tim_In_initConfig(IfxEgtm_Tim_In_Config *config, Ifx_EGTM *egtm)
{
    memset(config, 0, sizeof(IfxEgtm_Tim_In_Config));

    config->egtm                         = egtm;
    config->cluster                      = IfxEgtm_Cluster_0;
    config->channelIndex                 = IfxEgtm_Tim_Ch_0;
    config->irqMode                      = IfxEgtm_IrqMode_pulseNotify;
    config->isrProvider                  = IfxSrc_Tos_cpu0;
    config->isrPriority                  = 0;
    config->capture.irqOnNewVal          = FALSE;
    config->capture.irqOnCntOverflow     = FALSE;
    config->capture.irqOnEcntOverflow    = FALSE;
    config->capture.irqOnDatalost        = FALSE;
    config->capture.clock                = IfxEgtm_Cmu_Clk_0;
    config->capture.mode                 = Ifx_Pwm_Mode_leftAligned;
    config->capture.activeEdge           = IfxEgtm_Tim_In_ActiveEdge_both;
    config->capture.gateCount            = 0;
    config->timeout.irqOnTimeout         = FALSE;
    config->timeout.clock                = IfxEgtm_Cmu_Clk_0;
    config->timeout.timeout              = (float32)0.0f;
    config->filter.input                 = IfxEgtm_Tim_In_Input_currentChannel;
    config->filter.inputPin              = NULL_PTR;
    config->filter.inputPinMode          = IfxPort_InputMode_noPullDevice;
    config->filter.risingEdgeMode        = IfxEgtm_Tim_In_ConfigFilterMode_none;
    config->filter.fallingEdgeMode       = IfxEgtm_Tim_In_ConfigFilterMode_none;
    config->filter.risingEdgeFilterTime  = 0.0f;
    config->filter.fallingEdgeFilterTime = 0.0f;
    config->filter.clock                 = IfxEgtm_Cmu_Tim_Filter_Clk_0;
    config->mode                         = IfxEgtm_Tim_Mode_pwmMeasurement;
}


void IfxEgtm_Tim_In_onIsr(IfxEgtm_Tim_In *driver)
{
    IfxEgtm_Tim_In_update(driver);
}


void IfxEgtm_Tim_In_update(IfxEgtm_Tim_In *driver)
{
    driver->dataLost = IfxEgtm_Tim_Ch_isDataLostEvent(driver->channel);

    if (driver->dataLost == TRUE)
    {
        IfxEgtm_Tim_Ch_clearDataLostEvent(driver->channel);
    }

    driver->glitch = IfxEgtm_Tim_Ch_isGlitchEvent(driver->channel);

    if (driver->glitch == TRUE)
    {
        IfxEgtm_Tim_Ch_clearGlitchEvent(driver->channel);
    }

    driver->newData = IfxEgtm_Tim_Ch_isNewValueEvent(driver->channel);

    if (driver->newData == TRUE)
    {
        Ifx_EGTM_CLS_TIM_CH_GPR0 gpr0;
        Ifx_EGTM_CLS_TIM_CH_GPR1 gpr1;

        gpr0.U                  = driver->channel->GPR0.U;
        gpr1.U                  = driver->channel->GPR1.U;
        driver->periodTick      = gpr1.B.GPR1;
        driver->pulseLengthTick = gpr0.B.GPR0;
        driver->dataCoherent    = (gpr0.B.ECNT == gpr1.B.ECNT) ? TRUE : FALSE;

        // read the edge counter
        driver->edgeCount = driver->channel->ECNT.B.ECNT;

        if (IfxEgtm_Tim_Ch_isEcntOverflowEvent(driver->channel) == TRUE)
        {
            driver->edgeCounterUpper++;
            IfxEgtm_Tim_Ch_clearEcntOverflowEvent(driver->channel);
        }

        driver->overflowCnt = IfxEgtm_Tim_Ch_isCntOverflowEvent(driver->channel);

        if (driver->overflowCnt == TRUE)
        {
            driver->newData = FALSE;
            IfxEgtm_Tim_Ch_clearCntOverflowEvent(driver->channel);
        }

        IfxEgtm_Tim_Ch_clearNewValueEvent(driver->channel);
    }
}
