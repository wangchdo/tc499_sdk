/**
 * \file IfxEray_PinMap_LFBGA436_EMS.h
 * \brief ERAY  details
 * \ingroup IfxLld_Eray
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
 * Version: MC_ACE_A3G_HWA_Ports/V9.1.2.0.14
 * Document: A3G_Pin_Assignment_v0.67_TO.xls
 *
 * \defgroup IfxLld_Eray_
 * \ingroup IfxLld_Eray
 * \defgroup IfxLld_Eray__Pinmap Variables Default
 * \ingroup IfxLld_Eray_
 * \defgroup IfxLld_Eray__PinTables Default
 * \ingroup IfxLld_Eray_
 */

#ifndef IFXERAY_PINMAP_LFBGA436_EMS_H
#define IFXERAY_PINMAP_LFBGA436_EMS_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxEray_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXERAY_PINMAP_NUM_MODULES        2

#define IFXERAY_PINMAP_NUM_NODES          2

#define IFXERAY_PINMAP_RXD_IN_NUM_ITEMS   4

#define IFXERAY_PINMAP_TXD_OUT_NUM_ITEMS  4

#define IFXERAY_PINMAP_TXEN_OUT_NUM_ITEMS 5

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief Receive Channel A0
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray0_RXDA0_P14_8_IN;

/** \brief Receive Channel A1
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray0_RXDA1_P11_9_IN;

/** \brief Receive Channel A2
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray0_RXDA2_P02_1_IN;

/** \brief Receive Channel A3
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray0_RXDA3_P14_1_IN;

/** \brief Receive Channel B0
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray0_RXDB0_P14_7_IN;

/** \brief Receive Channel B1
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray0_RXDB1_P11_10_IN;

/** \brief Receive Channel B2
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray0_RXDB2_P02_3_IN;

/** \brief Receive Channel B3
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray0_RXDB3_P14_1_IN;

/** \brief Transmit Channel A
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray0_TXDA_P02_0_OUT;

/** \brief Transmit Channel A
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray0_TXDA_P11_3_OUT;

/** \brief Transmit Channel A
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray0_TXDA_P14_0_OUT;

/** \brief Transmit Channel A
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray0_TXDA_P14_10_OUT;

/** \brief Transmit Channel B
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray0_TXDB_P02_2_OUT;

/** \brief Transmit Channel B
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray0_TXDB_P11_12_OUT;

/** \brief Transmit Channel B
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray0_TXDB_P14_0_OUT;

/** \brief Transmit Channel B
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray0_TXDB_P14_5_OUT;

/** \brief Transmit Enable Channel A
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENA_P02_4_OUT;

/** \brief Transmit Enable Channel A
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENA_P11_6_OUT;

/** \brief Transmit Enable Channel A
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENA_P14_9_OUT;

/** \brief Transmit Enable Channel B
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENB_P02_5_OUT;

/** \brief Transmit Enable Channel B
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENB_P11_11_OUT;

/** \brief Transmit Enable Channel B
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENB_P11_6_OUT;

/** \brief Transmit Enable Channel B
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENB_P14_6_OUT;

/** \brief Transmit Enable Channel B
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENB_P14_9_OUT;

/** \brief Receive Channel A0
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray1_RXDA0_P14_8_IN;

/** \brief Receive Channel A1
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray1_RXDA1_P01_1_IN;

/** \brief Receive Channel A2
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray1_RXDA2_P11_10_IN;

/** \brief Receive Channel B0
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray1_RXDB0_P14_7_IN;

/** \brief Receive Channel B1
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray1_RXDB1_P01_8_IN;

/** \brief Transmit Channel A
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray1_TXDA_P01_12_OUT;

/** \brief Transmit Channel A
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray1_TXDA_P11_12_OUT;

/** \brief Transmit Channel A
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray1_TXDA_P14_10_OUT;

/** \brief Transmit Channel B
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray1_TXDB_P01_13_OUT;

/** \brief Transmit Channel B
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray1_TXDB_P14_5_OUT;

/** \brief Transmit Enable Channel A
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray1_TXENA_P01_14_OUT;

/** \brief Transmit Enable Channel A
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray1_TXENA_P11_11_OUT;

/** \brief Transmit Enable Channel A
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray1_TXENA_P14_9_OUT;

/** \brief Transmit Enable Channel B
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray1_TXENB_P02_15_OUT;

/** \brief Transmit Enable Channel B
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray1_TXENB_P14_6_OUT;

/** \addtogroup IfxLld_Eray__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxEray_Rxd_In Table
 */
IFX_EXTERN IFX_CONST IfxEray_Rxd_In   *IfxEray_Rxd_In_pinTable[IFXERAY_PINMAP_NUM_MODULES][IFXERAY_PINMAP_NUM_NODES][IFXERAY_PINMAP_RXD_IN_NUM_ITEMS];

/** \brief IfxEray_Txd_Out Table
 */
IFX_EXTERN IFX_CONST IfxEray_Txd_Out  *IfxEray_Txd_Out_pinTable[IFXERAY_PINMAP_NUM_MODULES][IFXERAY_PINMAP_NUM_NODES][IFXERAY_PINMAP_TXD_OUT_NUM_ITEMS];

/** \brief IfxEray_Txen_Out Table
 */
IFX_EXTERN IFX_CONST IfxEray_Txen_Out *IfxEray_Txen_Out_pinTable[IFXERAY_PINMAP_NUM_MODULES][IFXERAY_PINMAP_NUM_NODES][IFXERAY_PINMAP_TXEN_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXERAY_PINMAP_LFBGA436_EMS_H */
