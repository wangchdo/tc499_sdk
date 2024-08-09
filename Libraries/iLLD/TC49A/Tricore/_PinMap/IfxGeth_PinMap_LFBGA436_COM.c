/**
 * \file IfxGeth_PinMap_LFBGA436_COM.c
 * \brief GETH  details
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
#include "IfxGeth_PinMap_LFBGA436_COM.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IfxGeth_Col_In       IfxGeth0_COL_P15_8_IN = {&MODULE_GETH0, {&MODULE_P15, 8}, Ifx_RxSel_b};

IfxGeth_Col_In       IfxGeth0_COL_P21_6_IN = {&MODULE_GETH0, {&MODULE_P21, 6}, Ifx_RxSel_c};

IfxGeth_Crs_In       IfxGeth0_CRSC_P17_0_IN = {&MODULE_GETH0, {&MODULE_P17, 0}, Ifx_RxSel_c};

IfxGeth_Crsdv_In     IfxGeth0_CRSDVC_P16_1_IN = {&MODULE_GETH0, {&MODULE_P16, 1}, Ifx_RxSel_c};

IfxGeth_Crsdv_In     IfxGeth0_CRSDVD_P20_8_IN = {&MODULE_GETH0, {&MODULE_P20, 8}, Ifx_RxSel_d};

IfxGeth_Crs_In       IfxGeth0_CRSD_P20_1_IN = {&MODULE_GETH0, {&MODULE_P20, 1}, Ifx_RxSel_d};

IfxGeth_Grefclk_In   IfxGeth0_GREFCLK_P16_0_IN = {&MODULE_GETH0, {&MODULE_P16, 0}, Ifx_RxSel_a};

IfxGeth_Mdc_Out      IfxGeth0_MDC0_P02_8_OUT = {&MODULE_GETH0, {&MODULE_P02, 8}, IfxPort_OutputIdx_alt6};

IfxGeth_Mdc_Out      IfxGeth0_MDC0_P16_11_OUT = {&MODULE_GETH0, {&MODULE_P16, 11}, IfxPort_OutputIdx_alt7};

IfxGeth_Mdc_Out      IfxGeth0_MDC0_P21_2_OUT = {&MODULE_GETH0, {&MODULE_P21, 2}, IfxPort_OutputIdx_alt8};

IfxGeth_Mdc_Out      IfxGeth0_MDC1_P02_8_OUT = {&MODULE_GETH0, {&MODULE_P02, 8}, IfxPort_OutputIdx_alt8};

IfxGeth_Mdc_Out      IfxGeth0_MDC1_P16_11_OUT = {&MODULE_GETH0, {&MODULE_P16, 11}, IfxPort_OutputIdx_alt8};

IfxGeth_Mdc_Out      IfxGeth0_MDC1_P21_2_OUT = {&MODULE_GETH0, {&MODULE_P21, 2}, IfxPort_OutputIdx_alt7};

IfxGeth_Mdio_InOut   IfxGeth0_MDIO_P00_0_INOUT = {&MODULE_GETH0, {&MODULE_P00, 0}, Ifx_RxSel_a, IfxPort_OutputIdx_general};

IfxGeth_Mdio_InOut   IfxGeth0_MDIO_P16_14_INOUT = {&MODULE_GETH0, {&MODULE_P16, 14}, Ifx_RxSel_b, IfxPort_OutputIdx_general};

IfxGeth_Mdio_InOut   IfxGeth0_MDIO_P21_3_INOUT = {&MODULE_GETH0, {&MODULE_P21, 3}, Ifx_RxSel_d, IfxPort_OutputIdx_general};

IfxGeth_Pps_Out      IfxGeth0_PPS_P14_2_OUT = {&MODULE_GETH0, {&MODULE_P14, 2}, IfxPort_OutputIdx_alt8};

IfxGeth_Pps_Out      IfxGeth0_PPS_P14_3_OUT = {&MODULE_GETH0, {&MODULE_P14, 3}, IfxPort_OutputIdx_alt8};

IfxGeth_Pps_Out      IfxGeth0_PPS_P14_4_OUT = {&MODULE_GETH0, {&MODULE_P14, 4}, IfxPort_OutputIdx_alt8};

IfxGeth_Pps_Out      IfxGeth0_PPS_P14_8_OUT = {&MODULE_GETH0, {&MODULE_P14, 8}, IfxPort_OutputIdx_alt8};

IfxGeth_Refclk_In    IfxGeth0_REFCLKB_P21_4_IN = {&MODULE_GETH0, {&MODULE_P21, 4}, Ifx_RxSel_b};

IfxGeth_Refclk_In    IfxGeth0_REFCLKD_P16_2_IN = {&MODULE_GETH0, {&MODULE_P16, 2}, Ifx_RxSel_d};

IfxGeth_Rxclk_In     IfxGeth0_RXCLKB_P21_4_IN = {&MODULE_GETH0, {&MODULE_P21, 4}, Ifx_RxSel_b};

IfxGeth_Rxclk_In     IfxGeth0_RXCLKD_P16_2_IN = {&MODULE_GETH0, {&MODULE_P16, 2}, Ifx_RxSel_d};

IfxGeth_Rxclk_In     IfxGeth0_RXCLK_RGMII_P16_2_IN = {&MODULE_GETH0, {&MODULE_P16, 2}, Ifx_RxSel_a};

IfxGeth_Rxctl_In     IfxGeth0_RXCTL_P16_1_IN = {&MODULE_GETH0, {&MODULE_P16, 1}, Ifx_RxSel_a};

IfxGeth_Rxd_In       IfxGeth0_RXD0B_P16_4_IN = {&MODULE_GETH0, {&MODULE_P16, 4}, Ifx_RxSel_b};

IfxGeth_Rxd_In       IfxGeth0_RXD0C_P20_12_IN = {&MODULE_GETH0, {&MODULE_P20, 12}, Ifx_RxSel_c};

IfxGeth_Rxd_In       IfxGeth0_RXD1B_P16_3_IN = {&MODULE_GETH0, {&MODULE_P16, 3}, Ifx_RxSel_b};

IfxGeth_Rxd_In       IfxGeth0_RXD1C_P20_11_IN = {&MODULE_GETH0, {&MODULE_P20, 11}, Ifx_RxSel_c};

IfxGeth_Rxd_In       IfxGeth0_RXD2B_P16_5_IN = {&MODULE_GETH0, {&MODULE_P16, 5}, Ifx_RxSel_b};

IfxGeth_Rxd_In       IfxGeth0_RXD2C_P20_13_IN = {&MODULE_GETH0, {&MODULE_P20, 13}, Ifx_RxSel_c};

IfxGeth_Rxd_In       IfxGeth0_RXD3B_P16_7_IN = {&MODULE_GETH0, {&MODULE_P16, 7}, Ifx_RxSel_b};

IfxGeth_Rxd_In       IfxGeth0_RXD3C_P20_14_IN = {&MODULE_GETH0, {&MODULE_P20, 14}, Ifx_RxSel_c};

IfxGeth_Rxdv_In      IfxGeth0_RXDVC_P16_1_IN = {&MODULE_GETH0, {&MODULE_P16, 1}, Ifx_RxSel_c};

IfxGeth_Rxdv_In      IfxGeth0_RXDVD_P20_8_IN = {&MODULE_GETH0, {&MODULE_P20, 8}, Ifx_RxSel_d};

IfxGeth_Rxd_rgmii_In IfxGeth0_RXD_RGMII0_P16_4_IN = {&MODULE_GETH0, {&MODULE_P16, 4}, Ifx_RxSel_a};

IfxGeth_Rxd_rgmii_In IfxGeth0_RXD_RGMII1_P16_3_IN = {&MODULE_GETH0, {&MODULE_P16, 3}, Ifx_RxSel_a};

IfxGeth_Rxd_rgmii_In IfxGeth0_RXD_RGMII2_P16_5_IN = {&MODULE_GETH0, {&MODULE_P16, 5}, Ifx_RxSel_a};

IfxGeth_Rxd_rgmii_In IfxGeth0_RXD_RGMII3_P16_7_IN = {&MODULE_GETH0, {&MODULE_P16, 7}, Ifx_RxSel_a};

IfxGeth_Rxer_In      IfxGeth0_RXERB_P21_7_IN = {&MODULE_GETH0, {&MODULE_P21, 7}, Ifx_RxSel_b};

IfxGeth_Rxer_In      IfxGeth0_RXERC_P10_0_IN = {&MODULE_GETH0, {&MODULE_P10, 0}, Ifx_RxSel_c};

IfxGeth_Rxer_In      IfxGeth0_RXERD_P17_1_IN = {&MODULE_GETH0, {&MODULE_P17, 1}, Ifx_RxSel_d};

IfxGeth_Txclk_In     IfxGeth0_TXCLKC_P16_0_IN = {&MODULE_GETH0, {&MODULE_P16, 0}, Ifx_RxSel_c};

IfxGeth_Txclk_In     IfxGeth0_TXCLKD_P20_3_IN = {&MODULE_GETH0, {&MODULE_P20, 3}, Ifx_RxSel_d};

IfxGeth_Txclk_Out    IfxGeth0_TXCLK_P16_12_OUT = {&MODULE_GETH0, {&MODULE_P16, 12}, IfxPort_OutputIdx_general};

IfxGeth_Txctl_Out    IfxGeth0_TXCTL_P16_13_OUT = {&MODULE_GETH0, {&MODULE_P16, 13}, IfxPort_OutputIdx_general};

IfxGeth_Txd_Out      IfxGeth0_TXD_MII_P16_10_OUT = {&MODULE_GETH0, {&MODULE_P16, 10}, IfxPort_OutputIdx_alt8};

IfxGeth_Txd_Out      IfxGeth0_TXD_MII_P16_6_OUT = {&MODULE_GETH0, {&MODULE_P16, 6}, IfxPort_OutputIdx_alt8};

IfxGeth_Txd_Out      IfxGeth0_TXD_MII_P16_8_OUT = {&MODULE_GETH0, {&MODULE_P16, 8}, IfxPort_OutputIdx_alt8};

IfxGeth_Txd_Out      IfxGeth0_TXD_MII_P16_9_OUT = {&MODULE_GETH0, {&MODULE_P16, 9}, IfxPort_OutputIdx_alt8};

IfxGeth_Txd_Out      IfxGeth0_TXD_MII_P20_0_OUT = {&MODULE_GETH0, {&MODULE_P20, 0}, IfxPort_OutputIdx_alt8};

IfxGeth_Txd_Out      IfxGeth0_TXD_MII_P20_10_OUT = {&MODULE_GETH0, {&MODULE_P20, 10}, IfxPort_OutputIdx_alt8};

IfxGeth_Txd_Out      IfxGeth0_TXD_MII_P20_7_OUT = {&MODULE_GETH0, {&MODULE_P20, 7}, IfxPort_OutputIdx_alt8};

IfxGeth_Txd_Out      IfxGeth0_TXD_MII_P20_9_OUT = {&MODULE_GETH0, {&MODULE_P20, 9}, IfxPort_OutputIdx_alt8};

IfxGeth_Txd_Out      IfxGeth0_TXD_RGMII0_P16_6_OUT = {&MODULE_GETH0, {&MODULE_P16, 6}, IfxPort_OutputIdx_general};

IfxGeth_Txd_Out      IfxGeth0_TXD_RGMII1_P16_8_OUT = {&MODULE_GETH0, {&MODULE_P16, 8}, IfxPort_OutputIdx_general};

IfxGeth_Txd_Out      IfxGeth0_TXD_RGMII2_P16_9_OUT = {&MODULE_GETH0, {&MODULE_P16, 9}, IfxPort_OutputIdx_general};

IfxGeth_Txd_Out      IfxGeth0_TXD_RGMII3_P16_10_OUT = {&MODULE_GETH0, {&MODULE_P16, 10}, IfxPort_OutputIdx_general};

IfxGeth_Txd_Out      IfxGeth0_TXD_RMII_P16_6_OUT = {&MODULE_GETH0, {&MODULE_P16, 6}, IfxPort_OutputIdx_general};

IfxGeth_Txd_Out      IfxGeth0_TXD_RMII_P16_8_OUT = {&MODULE_GETH0, {&MODULE_P16, 8}, IfxPort_OutputIdx_general};

IfxGeth_Txd_Out      IfxGeth0_TXD_RMII_P20_10_OUT = {&MODULE_GETH0, {&MODULE_P20, 10}, IfxPort_OutputIdx_alt7};

IfxGeth_Txd_Out      IfxGeth0_TXD_RMII_P20_9_OUT = {&MODULE_GETH0, {&MODULE_P20, 9}, IfxPort_OutputIdx_alt7};

IfxGeth_Txen_Out     IfxGeth0_TXEN_MII_P16_13_OUT = {&MODULE_GETH0, {&MODULE_P16, 13}, IfxPort_OutputIdx_alt6};

IfxGeth_Txen_Out     IfxGeth0_TXEN_MII_P21_5_OUT = {&MODULE_GETH0, {&MODULE_P21, 5}, IfxPort_OutputIdx_alt12};

IfxGeth_Txen_Out     IfxGeth0_TXEN_RMII_P16_13_OUT = {&MODULE_GETH0, {&MODULE_P16, 13}, IfxPort_OutputIdx_general};

IfxGeth_Txen_Out     IfxGeth0_TXEN_RMII_P21_5_OUT = {&MODULE_GETH0, {&MODULE_P21, 5}, IfxPort_OutputIdx_alt13};

IfxGeth_Txer_Out     IfxGeth0_TXER_P16_12_OUT = {&MODULE_GETH0, {&MODULE_P16, 12}, IfxPort_OutputIdx_alt8};

IfxGeth_Txer_Out     IfxGeth0_TXER_P20_6_OUT = {&MODULE_GETH0, {&MODULE_P20, 6}, IfxPort_OutputIdx_alt8};

/** \addtogroup IfxLld_Geth__PinTables
 * \{ */

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxGeth_Col_In       *IfxGeth_Col_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_COL_IN_NUM_ITEMS] = {
    {
        NULL_PTR,
        &IfxGeth0_COL_P15_8_IN,
        &IfxGeth0_COL_P21_6_IN,
    },
};

IFX_CONST IfxGeth_Crs_In       *IfxGeth_Crs_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_CRS_IN_NUM_ITEMS] = {
    {
        NULL_PTR,
        NULL_PTR,
        &IfxGeth0_CRSC_P17_0_IN,
        &IfxGeth0_CRSD_P20_1_IN,
    },
};

IFX_CONST IfxGeth_Crsdv_In     *IfxGeth_Crsdv_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_CRSDV_IN_NUM_ITEMS] = {
    {
        NULL_PTR,
        NULL_PTR,
        &IfxGeth0_CRSDVC_P16_1_IN,
        &IfxGeth0_CRSDVD_P20_8_IN,
    },
};

IFX_CONST IfxGeth_Grefclk_In   *IfxGeth_Grefclk_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_GREFCLK_IN_NUM_ITEMS] = {
    {
        &IfxGeth0_GREFCLK_P16_0_IN,
    },
};

IFX_CONST IfxGeth_Mdc_Out      *IfxGeth_Mdc_Out_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_MDC_OUT_NUM_ITEMS] = {
    {
        &IfxGeth0_MDC0_P02_8_OUT,
        &IfxGeth0_MDC1_P02_8_OUT,
        &IfxGeth0_MDC0_P16_11_OUT,
        &IfxGeth0_MDC1_P16_11_OUT,
        &IfxGeth0_MDC0_P21_2_OUT,
        &IfxGeth0_MDC1_P21_2_OUT,
    },
};

IFX_CONST IfxGeth_Mdio_InOut   *IfxGeth_Mdio_InOut_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_MDIO_INOUT_NUM_ITEMS] = {
    {
        &IfxGeth0_MDIO_P00_0_INOUT,
        &IfxGeth0_MDIO_P16_14_INOUT,
        NULL_PTR,
        &IfxGeth0_MDIO_P21_3_INOUT,
    },
};

IFX_CONST IfxGeth_Pps_Out      *IfxGeth_Pps_Out_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_PPS_OUT_NUM_ITEMS] = {
    {
        &IfxGeth0_PPS_P14_2_OUT,
        &IfxGeth0_PPS_P14_3_OUT,
        &IfxGeth0_PPS_P14_4_OUT,
        &IfxGeth0_PPS_P14_8_OUT,
    },
};

IFX_CONST IfxGeth_Refclk_In    *IfxGeth_Refclk_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_REFCLK_IN_NUM_ITEMS] = {
    {
        NULL_PTR,
        &IfxGeth0_REFCLKB_P21_4_IN,
        NULL_PTR,
        &IfxGeth0_REFCLKD_P16_2_IN,
    },
};

IFX_CONST IfxGeth_Rxclk_In     *IfxGeth_Rxclk_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_RXCLK_IN_NUM_ITEMS] = {
    {
        &IfxGeth0_RXCLK_RGMII_P16_2_IN,
        &IfxGeth0_RXCLKB_P21_4_IN,
        NULL_PTR,
        &IfxGeth0_RXCLKD_P16_2_IN,
    },
};

IFX_CONST IfxGeth_Rxctl_In     *IfxGeth_Rxctl_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_RXCTL_IN_NUM_ITEMS] = {
    {
        &IfxGeth0_RXCTL_P16_1_IN,
    },
};

IFX_CONST IfxGeth_Rxd_In       *IfxGeth_Rxd_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_RXD_IN_NUM_ITEMS] = {
    {
        NULL_PTR,
        &IfxGeth0_RXD1B_P16_3_IN,
        &IfxGeth0_RXD0B_P16_4_IN,
        &IfxGeth0_RXD2B_P16_5_IN,
        &IfxGeth0_RXD3B_P16_7_IN,
        &IfxGeth0_RXD1C_P20_11_IN,
        &IfxGeth0_RXD0C_P20_12_IN,
        &IfxGeth0_RXD2C_P20_13_IN,
        &IfxGeth0_RXD3C_P20_14_IN,
    },
};

IFX_CONST IfxGeth_Rxd_rgmii_In *IfxGeth_Rxd_rgmii_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_RXD_RGMII_IN_NUM_ITEMS] = {
    {
        &IfxGeth0_RXD_RGMII1_P16_3_IN,
        &IfxGeth0_RXD_RGMII0_P16_4_IN,
        &IfxGeth0_RXD_RGMII2_P16_5_IN,
        &IfxGeth0_RXD_RGMII3_P16_7_IN,
    },
};

IFX_CONST IfxGeth_Rxdv_In      *IfxGeth_Rxdv_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_RXDV_IN_NUM_ITEMS] = {
    {
        NULL_PTR,
        NULL_PTR,
        &IfxGeth0_RXDVC_P16_1_IN,
        &IfxGeth0_RXDVD_P20_8_IN,
    },
};

IFX_CONST IfxGeth_Rxer_In      *IfxGeth_Rxer_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_RXER_IN_NUM_ITEMS] = {
    {
        NULL_PTR,
        &IfxGeth0_RXERB_P21_7_IN,
        &IfxGeth0_RXERC_P10_0_IN,
        &IfxGeth0_RXERD_P17_1_IN,
    },
};

IFX_CONST IfxGeth_Txclk_In     *IfxGeth_Txclk_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_TXCLK_IN_NUM_ITEMS] = {
    {
        NULL_PTR,
        NULL_PTR,
        &IfxGeth0_TXCLKC_P16_0_IN,
        &IfxGeth0_TXCLKD_P20_3_IN,
    },
};

IFX_CONST IfxGeth_Txclk_Out    *IfxGeth_Txclk_Out_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_TXCLK_OUT_NUM_ITEMS] = {
    {
        &IfxGeth0_TXCLK_P16_12_OUT,
    },
};

IFX_CONST IfxGeth_Txctl_Out    *IfxGeth_Txctl_Out_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_TXCTL_OUT_NUM_ITEMS] = {
    {
        &IfxGeth0_TXCTL_P16_13_OUT,
    },
};

IFX_CONST IfxGeth_Txd_Out      *IfxGeth_Txd_Out_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_TXD_OUT_NUM_ITEMS] = {
    {
        &IfxGeth0_TXD_MII_P16_6_OUT,
        &IfxGeth0_TXD_RGMII0_P16_6_OUT,
        &IfxGeth0_TXD_RMII_P16_6_OUT,
        &IfxGeth0_TXD_MII_P16_8_OUT,
        &IfxGeth0_TXD_RGMII1_P16_8_OUT,
        &IfxGeth0_TXD_RMII_P16_8_OUT,
        &IfxGeth0_TXD_MII_P16_9_OUT,
        &IfxGeth0_TXD_RGMII2_P16_9_OUT,
        &IfxGeth0_TXD_MII_P16_10_OUT,
        &IfxGeth0_TXD_RGMII3_P16_10_OUT,
        &IfxGeth0_TXD_MII_P20_0_OUT,
        &IfxGeth0_TXD_MII_P20_7_OUT,
        &IfxGeth0_TXD_MII_P20_9_OUT,
        &IfxGeth0_TXD_RMII_P20_9_OUT,
        &IfxGeth0_TXD_MII_P20_10_OUT,
        &IfxGeth0_TXD_RMII_P20_10_OUT,
    },
};

IFX_CONST IfxGeth_Txen_Out     *IfxGeth_Txen_Out_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_TXEN_OUT_NUM_ITEMS] = {
    {
        &IfxGeth0_TXEN_MII_P16_13_OUT,
        &IfxGeth0_TXEN_RMII_P16_13_OUT,
        &IfxGeth0_TXEN_MII_P21_5_OUT,
        &IfxGeth0_TXEN_RMII_P21_5_OUT,
    },
};

IFX_CONST IfxGeth_Txer_Out     *IfxGeth_Txer_Out_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_TXER_OUT_NUM_ITEMS] = {
    {
        &IfxGeth0_TXER_P16_12_OUT,
        &IfxGeth0_TXER_P20_6_OUT,
    },
};

/** \} */

#endif
