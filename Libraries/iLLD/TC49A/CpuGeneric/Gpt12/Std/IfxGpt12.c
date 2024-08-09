/**
 * \file IfxGpt12.c
 * \brief GPT12  basic functionality
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

#include "IfxGpt12.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

float32 IfxGpt12_T2_getFrequency(Ifx_GPT12 *gpt12)
{
    float32                      freq = IfxGpt12_getModuleFrequency(gpt12);

    IfxGpt12_Mode                mode;
    IfxGpt12_TimerInputPrescaler prescaler;

    IfxGpt12_Gpt1BlockPrescaler  bps1 = (IfxGpt12_Gpt1BlockPrescaler)gpt12->T3CON.B.BPS1;

    switch (bps1)
    {
    case IfxGpt12_Gpt1BlockPrescaler_4:
        freq = freq / 4;
        break;
    case IfxGpt12_Gpt1BlockPrescaler_8:
        freq = freq / 8;
        break;
    case IfxGpt12_Gpt1BlockPrescaler_16:
        freq = freq / 16;
        break;
    default: /* case IfxGpt12_Gpt1BlockPrescaler_32: */
        freq = freq / 32;
        break;
    }

    mode      = IfxGpt12_T2_getMode(gpt12);
    prescaler = (IfxGpt12_TimerInputPrescaler)gpt12->T2CON.B.T2I;

    if ((mode == IfxGpt12_Mode_timer) || (mode == IfxGpt12_Mode_highGatedTimer) || (mode == IfxGpt12_Mode_lowGatedTimer))
    {
        freq = freq / (1 << prescaler);
    }
    else
    {
        freq = freq / 2;
    }

    return freq;
}


float32 IfxGpt12_T3_getFrequency(Ifx_GPT12 *gpt12)
{
    float32                      freq = IfxGpt12_getModuleFrequency(gpt12);

    IfxGpt12_Mode                mode;
    IfxGpt12_TimerInputPrescaler prescaler;

    IfxGpt12_Gpt1BlockPrescaler  bps1 = (IfxGpt12_Gpt1BlockPrescaler)gpt12->T3CON.B.BPS1;

    switch (bps1)
    {
    case IfxGpt12_Gpt1BlockPrescaler_4:
        freq = freq / 4;
        break;
    case IfxGpt12_Gpt1BlockPrescaler_8:
        freq = freq / 8;
        break;
    case IfxGpt12_Gpt1BlockPrescaler_16:
        freq = freq / 16;
        break;
    default: /* case IfxGpt12_Gpt1BlockPrescaler_32: */
        freq = freq / 32;
        break;
    }

    mode      = (IfxGpt12_Mode)gpt12->T3CON.B.T3M;
    prescaler = (IfxGpt12_TimerInputPrescaler)gpt12->T3CON.B.T3I;

    if ((mode == IfxGpt12_Mode_timer) || (mode == IfxGpt12_Mode_highGatedTimer) || (mode == IfxGpt12_Mode_lowGatedTimer))
    {
        freq = freq / (1 << prescaler);
    }
    else
    {
        freq = freq / 2;
    }

    return freq;
}


float32 IfxGpt12_T4_getFrequency(Ifx_GPT12 *gpt12)
{
    float32                      freq = IfxGpt12_getModuleFrequency(gpt12);

    IfxGpt12_Mode                mode;
    IfxGpt12_TimerInputPrescaler prescaler;

    IfxGpt12_Gpt1BlockPrescaler  bps1 = (IfxGpt12_Gpt1BlockPrescaler)gpt12->T3CON.B.BPS1;

    switch (bps1)
    {
    case IfxGpt12_Gpt1BlockPrescaler_4:
        freq = freq / 4;
        break;
    case IfxGpt12_Gpt1BlockPrescaler_8:
        freq = freq / 8;
        break;
    case IfxGpt12_Gpt1BlockPrescaler_16:
        freq = freq / 16;
        break;
    default: /* case IfxGpt12_Gpt1BlockPrescaler_32: */
        freq = freq / 32;
        break;
    }

    mode      = (IfxGpt12_Mode)gpt12->T4CON.B.T4M;
    prescaler = (IfxGpt12_TimerInputPrescaler)gpt12->T4CON.B.T4I;

    if ((mode == IfxGpt12_Mode_timer) || (mode == IfxGpt12_Mode_highGatedTimer) || (mode == IfxGpt12_Mode_lowGatedTimer))
    {
        freq = freq / (1 << prescaler);
    }
    else
    {
        freq = freq / 2;
    }

    return freq;
}


float32 IfxGpt12_T5_getFrequency(Ifx_GPT12 *gpt12)
{
    float32                      freq = IfxGpt12_getModuleFrequency(gpt12);

    IfxGpt12_Mode                mode;
    IfxGpt12_TimerInputPrescaler prescaler;

    IfxGpt12_Gpt2BlockPrescaler  bps2 = (IfxGpt12_Gpt2BlockPrescaler)gpt12->T6CON.B.BPS2;

    switch (bps2)
    {
    case IfxGpt12_Gpt2BlockPrescaler_2:
        freq = freq / 2;
        break;
    case IfxGpt12_Gpt2BlockPrescaler_4:
        freq = freq / 4;
        break;
    case IfxGpt12_Gpt2BlockPrescaler_8:
        freq = freq / 8;
        break;
    default: /* case IfxGpt12_Gpt2BlockPrescaler_16: */
        freq = freq / 16;
        break;
    }

    mode      = (IfxGpt12_Mode)gpt12->T5CON.B.T5M;
    prescaler = (IfxGpt12_TimerInputPrescaler)gpt12->T5CON.B.T5I;

    if ((mode == IfxGpt12_Mode_timer) || (mode == IfxGpt12_Mode_highGatedTimer) || (mode == IfxGpt12_Mode_lowGatedTimer))
    {
        freq = freq / (1 << prescaler);
    }
    else
    {
        freq = freq / 2;
    }

    return freq;
}


float32 IfxGpt12_T6_getFrequency(Ifx_GPT12 *gpt12)
{
    float32                      freq = IfxGpt12_getModuleFrequency(gpt12);

    IfxGpt12_Mode                mode;
    IfxGpt12_TimerInputPrescaler prescaler;

    IfxGpt12_Gpt2BlockPrescaler  bps2 = (IfxGpt12_Gpt2BlockPrescaler)gpt12->T6CON.B.BPS2;

    switch (bps2)
    {
    case IfxGpt12_Gpt2BlockPrescaler_2:
        freq = freq / 2;
        break;
    case IfxGpt12_Gpt2BlockPrescaler_4:
        freq = freq / 4;
        break;
    case IfxGpt12_Gpt2BlockPrescaler_8:
        freq = freq / 8;
        break;
    default: /* case IfxGpt12_Gpt2BlockPrescaler_16: */
        freq = freq / 16;
        break;
    }

    mode      = (IfxGpt12_Mode)gpt12->T6CON.B.T6M;
    prescaler = (IfxGpt12_TimerInputPrescaler)gpt12->T6CON.B.T6I;

    if ((mode == IfxGpt12_Mode_timer) || (mode == IfxGpt12_Mode_highGatedTimer) || (mode == IfxGpt12_Mode_lowGatedTimer))
    {
        freq = freq / (1 << prescaler);
    }
    else
    {
        freq = freq / 2;
    }

    return freq;
}


void IfxGpt12_disableModule(Ifx_GPT12 *gpt12)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gpt12->PROTE, IfxApProt_State_config);
#endif
    gpt12->CLC.B.DISR = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gpt12->PROTE, IfxApProt_State_run);
#endif
}


void IfxGpt12_enableModule(Ifx_GPT12 *gpt12)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gpt12->PROTE, IfxApProt_State_config);
#endif
    gpt12->CLC.B.DISR = 0;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gpt12->PROTE, IfxApProt_State_run);
#endif
}


void IfxGpt12_initTxEudInPin(const IfxGpt12_TxEud_In *txEudIn, IfxPort_InputMode inputMode)
{
    IfxPort_setPinModeInput(txEudIn->pin.port, txEudIn->pin.pinIndex, inputMode);

    switch (txEudIn->timer)
    {
    case 2:
        IfxGpt12_T2_setEudInput(txEudIn->module, (IfxGpt12_EudInput)txEudIn->select);
        break;
    case 3:
        IfxGpt12_T3_setEudInput(txEudIn->module, (IfxGpt12_EudInput)txEudIn->select);
        break;
    case 4:
        IfxGpt12_T4_setEudInput(txEudIn->module, (IfxGpt12_EudInput)txEudIn->select);
        break;
    case 5:
        IfxGpt12_T5_setEudInput(txEudIn->module, (IfxGpt12_EudInput)txEudIn->select);
        break;
    case 6:
        IfxGpt12_T6_setEudInput(txEudIn->module, (IfxGpt12_EudInput)txEudIn->select);
        break;
    default:
        break;
    }
}


void IfxGpt12_initTxEudInPinWithPadLevel(const IfxGpt12_TxEud_In *txEudIn, IfxPort_InputMode inputMode, IfxPort_PadDriver padDriver)
{
    IfxPort_setPinModeInput(txEudIn->pin.port, txEudIn->pin.pinIndex, inputMode);
    IfxPort_setPinPadDriver(txEudIn->pin.port, txEudIn->pin.pinIndex, padDriver);

    switch (txEudIn->timer)
    {
    case 2:
        IfxGpt12_T2_setEudInput(txEudIn->module, (IfxGpt12_EudInput)txEudIn->select);
        break;
    case 3:
        IfxGpt12_T3_setEudInput(txEudIn->module, (IfxGpt12_EudInput)txEudIn->select);
        break;
    case 4:
        IfxGpt12_T4_setEudInput(txEudIn->module, (IfxGpt12_EudInput)txEudIn->select);
        break;
    case 5:
        IfxGpt12_T5_setEudInput(txEudIn->module, (IfxGpt12_EudInput)txEudIn->select);
        break;
    case 6:
        IfxGpt12_T6_setEudInput(txEudIn->module, (IfxGpt12_EudInput)txEudIn->select);
        break;
    default:
        break;
    }
}


void IfxGpt12_initTxInPin(const IfxGpt12_TxIn_In *txIn, IfxPort_InputMode inputMode)
{
    IfxPort_setPinModeInput(txIn->pin.port, txIn->pin.pinIndex, inputMode);

    switch (txIn->timer)
    {
    case 2:
        IfxGpt12_T2_setInput(txIn->module, (IfxGpt12_Input)txIn->select);
        break;
    case 3:
        IfxGpt12_T3_setInput(txIn->module, (IfxGpt12_Input)txIn->select);
        break;
    case 4:
        IfxGpt12_T4_setInput(txIn->module, (IfxGpt12_Input)txIn->select);
        break;
    case 5:
        IfxGpt12_T5_setInput(txIn->module, (IfxGpt12_Input)txIn->select);
        break;
    case 6:
        IfxGpt12_T6_setInput(txIn->module, (IfxGpt12_Input)txIn->select);
        break;
    default:
        break;
    }
}


void IfxGpt12_initTxInPinWithPadLevel(const IfxGpt12_TxIn_In *txIn, IfxPort_InputMode inputMode, IfxPort_PadDriver padDriver)
{
    IfxPort_setPinModeInput(txIn->pin.port, txIn->pin.pinIndex, inputMode);
    IfxPort_setPinPadDriver(txIn->pin.port, txIn->pin.pinIndex, padDriver);

    switch (txIn->timer)
    {
    case 2:
        IfxGpt12_T2_setInput(txIn->module, (IfxGpt12_Input)txIn->select);
        break;
    case 3:
        IfxGpt12_T3_setInput(txIn->module, (IfxGpt12_Input)txIn->select);
        break;
    case 4:
        IfxGpt12_T4_setInput(txIn->module, (IfxGpt12_Input)txIn->select);
        break;
    case 5:
        IfxGpt12_T5_setInput(txIn->module, (IfxGpt12_Input)txIn->select);
        break;
    case 6:
        IfxGpt12_T6_setInput(txIn->module, (IfxGpt12_Input)txIn->select);
        break;
    default:
        break;
    }
}


void IfxGpt12_resetModule(Ifx_GPT12 *gpt12)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gpt12->PROTE, IfxApProt_State_config);
#endif
    gpt12->RST.CTRLA.B.KRST = 1;        /* Only if both Kernel reset bits are set a reset is executed */
    gpt12->RST.CTRLB.B.KRST = 1;

    while (0 == gpt12->RST.STAT.B.KRST) /* Wait until reset is executed */

    {}

    gpt12->RST.CTRLB.B.STATCLR = 1;       /* Clear Kernel reset status bit */

    while (gpt12->RST.STAT.B.KRST == 1)   /* Wait until KRST is cleared, only after this reset sequence is completed */
    {}

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gpt12->PROTE, IfxApProt_State_run);
#endif
}


IfxGpt12_Index IfxGpt12_getIndex(Ifx_GPT12 *gpt12)
{
    uint32         index;
    IfxGpt12_Index result;

    result = IfxGpt12_Index_none;

    for (index = 0; index < IFXGPT12_NUM_MODULES; index++)
    {
        if (IfxGpt12_cfg_indexMap[index].module == gpt12)
        {
            result = (IfxGpt12_Index)IfxGpt12_cfg_indexMap[index].index;
            break;
        }
    }

    return result;
}


void IfxGpt12_initApConfig(IfxGpt12_ApConfig *config)
{
    IfxApProt_initConfig(&config->proteConfig);
    IfxApProt_initConfig(&config->protseConfig);
    IfxApApu_initConfig(&config->apuConfig);
}


void IfxGpt12_initAp(Ifx_GPT12 *gpt12, IfxGpt12_ApConfig *config)
{
    /* Initialize the PROTs */
    IfxApProt_init((Ifx_PROT_PROT *)&gpt12->PROTE, &config->proteConfig);
    IfxApProt_init((Ifx_PROT_PROT *)&gpt12->PROTSE, &config->protseConfig);

    /* Change the state to CONFIG, Configure APU and set PROT state back to RUN */
    /* Initialize the APU */
    IfxApProt_setState((Ifx_PROT_PROT *)&gpt12->PROTSE, IfxApProt_State_config);
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&gpt12->ACCEN, &config->apuConfig);
    IfxApProt_setState((Ifx_PROT_PROT *)&gpt12->PROTSE, IfxApProt_State_run);
}


void IfxGpt12_configureAccessToGpt12s(IfxApApu_ApuConfig *apConfig)
{
    uint8 index;

    for (index = 0; index < IFXGPT12_NUM_MODULES; index++)
    {
        Ifx_GPT12 *gpt12 = (Ifx_GPT12 *)IfxGpt12_cfg_indexMap[index].module;
        IfxApApu_init((Ifx_ACCEN_ACCEN *)&gpt12->ACCEN, (IfxApApu_ApuConfig *)apConfig);
    }
}
