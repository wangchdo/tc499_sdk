/**
 * \file IfxHsct_PinMap_LFBGA436_EMS.c
 * \brief HSCT  details
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

#if defined(__TASKING__)
#pragma warning 508
#endif

#if defined(__ghs__)
#pragma ghs nowarning 96
#endif
#include "Ifx_PinMap.h"
#ifdef IFX_PIN_PACKAGE_LFBGA436_EMS
#include "IfxHsct_PinMap_LFBGA436_EMS.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IfxHsct_Rxdn_In    IfxHsct_RXDN_P21_0_IN = {&MODULE_HSCT1, {&MODULE_P21, 0}, Ifx_RxSel_a};

IfxHsct_Rxdn_In    IfxHsct_RXDN_P21_2_IN = {&MODULE_HSCT0, {&MODULE_P21, 2}, Ifx_RxSel_a};

IfxHsct_Rxdp_In    IfxHsct_RXDP_P21_1_IN = {&MODULE_HSCT1, {&MODULE_P21, 1}, Ifx_RxSel_a};

IfxHsct_Rxdp_In    IfxHsct_RXDP_P21_3_IN = {&MODULE_HSCT0, {&MODULE_P21, 3}, Ifx_RxSel_a};

IfxHsct_Sysclk_Out IfxHsct_SYSCLK_OUT_P20_0_OUT = {&MODULE_HSCT0, {&MODULE_P20, 0}, IfxPort_OutputIdx_alt5};

IfxHsct_Txdn_Out   IfxHsct_TXDN_P21_4_OUT = {&MODULE_HSCT0, {&MODULE_P21, 4}, IfxPort_OutputIdx_general};

IfxHsct_Txdn_Out   IfxHsct_TXDN_P22_2_OUT = {&MODULE_HSCT1, {&MODULE_P22, 2}, IfxPort_OutputIdx_general};

IfxHsct_Txdp_Out   IfxHsct_TXDP_P21_5_OUT = {&MODULE_HSCT0, {&MODULE_P21, 5}, IfxPort_OutputIdx_general};

IfxHsct_Txdp_Out   IfxHsct_TXDP_P22_3_OUT = {&MODULE_HSCT1, {&MODULE_P22, 3}, IfxPort_OutputIdx_general};

/** \addtogroup IfxLld_Hsct__PinTables
 * \{ */

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxHsct_Rxdn_In    *IfxHsct_Rxdn_In_pinTable[IFXHSCT_PINMAP_NUM_MODULES][IFXHSCT_PINMAP_RXDN_IN_NUM_ITEMS] = {
    {
        &IfxHsct_RXDN_P21_2_IN,
    },
    {
        &IfxHsct_RXDN_P21_0_IN,
    },
};

IFX_CONST IfxHsct_Rxdp_In    *IfxHsct_Rxdp_In_pinTable[IFXHSCT_PINMAP_NUM_MODULES][IFXHSCT_PINMAP_RXDP_IN_NUM_ITEMS] = {
    {
        &IfxHsct_RXDP_P21_3_IN,
    },
    {
        &IfxHsct_RXDP_P21_1_IN,
    },
};

IFX_CONST IfxHsct_Sysclk_Out *IfxHsct_Sysclk_Out_pinTable[IFXHSCT_PINMAP_NUM_MODULES][IFXHSCT_PINMAP_SYSCLK_OUT_NUM_ITEMS] = {
    {
        &IfxHsct_SYSCLK_OUT_P20_0_OUT,
    },
    {
        NULL_PTR,
    },
};

IFX_CONST IfxHsct_Txdn_Out   *IfxHsct_Txdn_Out_pinTable[IFXHSCT_PINMAP_NUM_MODULES][IFXHSCT_PINMAP_TXDN_OUT_NUM_ITEMS] = {
    {
        &IfxHsct_TXDN_P21_4_OUT,
    },
    {
        &IfxHsct_TXDN_P22_2_OUT,
    },
};

IFX_CONST IfxHsct_Txdp_Out   *IfxHsct_Txdp_Out_pinTable[IFXHSCT_PINMAP_NUM_MODULES][IFXHSCT_PINMAP_TXDP_OUT_NUM_ITEMS] = {
    {
        &IfxHsct_TXDP_P21_5_OUT,
    },
    {
        &IfxHsct_TXDP_P22_3_OUT,
    },
};

/** \} */

#endif
