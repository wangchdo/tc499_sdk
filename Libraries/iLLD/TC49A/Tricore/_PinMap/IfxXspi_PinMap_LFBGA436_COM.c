/**
 * \file IfxXspi_PinMap_LFBGA436_COM.c
 * \brief XSPI  details
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
#ifdef IFX_PIN_PACKAGE_LFBGA436_COM
#include "IfxXspi_PinMap_LFBGA436_COM.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IfxXspi_Clk_Out    IfxXspi0_CLK_P16_0_OUT = {&MODULE_XSPI0, {&MODULE_P16, 0}, IfxPort_OutputIdx_general};

IfxXspi_Clk_Out    IfxXspi0_CLK_P16_1_OUT = {&MODULE_XSPI0, {&MODULE_P16, 1}, IfxPort_OutputIdx_general};

IfxXspi_Cs_Out     IfxXspi0_CS_P16_13_OUT = {&MODULE_XSPI0, {&MODULE_P16, 13}, IfxPort_OutputIdx_general};

IfxXspi_Cs_Out     IfxXspi0_CS_P16_4_OUT = {&MODULE_XSPI0, {&MODULE_P16, 4}, IfxPort_OutputIdx_general};

IfxXspi_Dm_InOut   IfxXspi0_DM_P16_2_INOUT = {&MODULE_XSPI0, {&MODULE_P16, 2}, Ifx_RxSel_a, IfxPort_OutputIdx_general};

IfxXspi_Txd0_InOut IfxXspi0_TXD0_P16_7_INOUT = {&MODULE_XSPI0, {&MODULE_P16, 7}, Ifx_RxSel_a, IfxPort_OutputIdx_general};

IfxXspi_Txd1_InOut IfxXspi0_TXD1_P16_3_INOUT = {&MODULE_XSPI0, {&MODULE_P16, 3}, Ifx_RxSel_a, IfxPort_OutputIdx_general};

IfxXspi_Txd2_InOut IfxXspi0_TXD2_P16_5_INOUT = {&MODULE_XSPI0, {&MODULE_P16, 5}, Ifx_RxSel_a, IfxPort_OutputIdx_general};

IfxXspi_Txd3_InOut IfxXspi0_TXD3_P16_6_INOUT = {&MODULE_XSPI0, {&MODULE_P16, 6}, Ifx_RxSel_a, IfxPort_OutputIdx_general};

IfxXspi_Txd4_InOut IfxXspi0_TXD4_P16_8_INOUT = {&MODULE_XSPI0, {&MODULE_P16, 8}, Ifx_RxSel_a, IfxPort_OutputIdx_general};

IfxXspi_Txd5_InOut IfxXspi0_TXD5_P16_9_INOUT = {&MODULE_XSPI0, {&MODULE_P16, 9}, Ifx_RxSel_a, IfxPort_OutputIdx_general};

IfxXspi_Txd6_InOut IfxXspi0_TXD6_P16_10_INOUT = {&MODULE_XSPI0, {&MODULE_P16, 10}, Ifx_RxSel_a, IfxPort_OutputIdx_general};

IfxXspi_Txd7_InOut IfxXspi0_TXD7_P16_12_INOUT = {&MODULE_XSPI0, {&MODULE_P16, 12}, Ifx_RxSel_a, IfxPort_OutputIdx_general};

/** \addtogroup IfxLld_Xspi__PinTables
 * \{ */

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxXspi_Clk_Out    *IfxXspi_Clk_Out_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_CLK_OUT_NUM_ITEMS] = {
    {
        &IfxXspi0_CLK_P16_0_OUT,
        &IfxXspi0_CLK_P16_1_OUT,
    },
};

IFX_CONST IfxXspi_Cs_Out     *IfxXspi_Cs_Out_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_CS_OUT_NUM_ITEMS] = {
    {
        &IfxXspi0_CS_P16_4_OUT,
        &IfxXspi0_CS_P16_13_OUT,
    },
};

IFX_CONST IfxXspi_Dm_InOut   *IfxXspi_Dm_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_DM_INOUT_NUM_ITEMS] = {
    {
        &IfxXspi0_DM_P16_2_INOUT,
    },
};

IFX_CONST IfxXspi_Txd0_InOut *IfxXspi_Txd0_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_TXD0_INOUT_NUM_ITEMS] = {
    {
        &IfxXspi0_TXD0_P16_7_INOUT,
    },
};

IFX_CONST IfxXspi_Txd1_InOut *IfxXspi_Txd1_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_TXD1_INOUT_NUM_ITEMS] = {
    {
        &IfxXspi0_TXD1_P16_3_INOUT,
    },
};

IFX_CONST IfxXspi_Txd2_InOut *IfxXspi_Txd2_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_TXD2_INOUT_NUM_ITEMS] = {
    {
        &IfxXspi0_TXD2_P16_5_INOUT,
    },
};

IFX_CONST IfxXspi_Txd3_InOut *IfxXspi_Txd3_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_TXD3_INOUT_NUM_ITEMS] = {
    {
        &IfxXspi0_TXD3_P16_6_INOUT,
    },
};

IFX_CONST IfxXspi_Txd4_InOut *IfxXspi_Txd4_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_TXD4_INOUT_NUM_ITEMS] = {
    {
        &IfxXspi0_TXD4_P16_8_INOUT,
    },
};

IFX_CONST IfxXspi_Txd5_InOut *IfxXspi_Txd5_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_TXD5_INOUT_NUM_ITEMS] = {
    {
        &IfxXspi0_TXD5_P16_9_INOUT,
    },
};

IFX_CONST IfxXspi_Txd6_InOut *IfxXspi_Txd6_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_TXD6_INOUT_NUM_ITEMS] = {
    {
        &IfxXspi0_TXD6_P16_10_INOUT,
    },
};

IFX_CONST IfxXspi_Txd7_InOut *IfxXspi_Txd7_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_TXD7_INOUT_NUM_ITEMS] = {
    {
        &IfxXspi0_TXD7_P16_12_INOUT,
    },
};

/** \} */

#endif
