/**
 * \file IfxSdmmc_PinMap_LFBGA436_COM.h
 * \brief SDMMC  details
 * \ingroup IfxLld_Sdmmc
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
 * \defgroup IfxLld_Sdmmc_
 * \ingroup IfxLld_Sdmmc
 * \defgroup IfxLld_Sdmmc__Pinmap Variables Default
 * \ingroup IfxLld_Sdmmc_
 * \defgroup IfxLld_Sdmmc__PinTables Default
 * \ingroup IfxLld_Sdmmc_
 */

#ifndef IFXSDMMC_PINMAP_LFBGA436_COM_H
#define IFXSDMMC_PINMAP_LFBGA436_COM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxSdmmc_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXSDMMC_PINMAP_NUM_MODULES          1

#define IFXSDMMC_PINMAP_CLK_OUT_NUM_ITEMS    1

#define IFXSDMMC_PINMAP_CMD_INOUT_NUM_ITEMS  1

#define IFXSDMMC_PINMAP_DAT0_INOUT_NUM_ITEMS 1

#define IFXSDMMC_PINMAP_DAT1_INOUT_NUM_ITEMS 1

#define IFXSDMMC_PINMAP_DAT2_INOUT_NUM_ITEMS 1

#define IFXSDMMC_PINMAP_DAT3_INOUT_NUM_ITEMS 1

#define IFXSDMMC_PINMAP_DAT4_INOUT_NUM_ITEMS 1

#define IFXSDMMC_PINMAP_DAT5_INOUT_NUM_ITEMS 1

#define IFXSDMMC_PINMAP_DAT6_INOUT_NUM_ITEMS 1

#define IFXSDMMC_PINMAP_DAT7_INOUT_NUM_ITEMS 1

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief card clock
 */
IFX_EXTERN IfxSdmmc_Clk_Out    IfxSdmmc0_CLK_P15_1_OUT;

/** \brief command out and command in
 */
IFX_EXTERN IfxSdmmc_Cmd_InOut  IfxSdmmc0_CMD_P15_3_INOUT;

/** \brief write data out and read data in
 */
IFX_EXTERN IfxSdmmc_Dat0_InOut IfxSdmmc0_DAT0_P20_7_INOUT;

/** \brief write data out and read data in
 */
IFX_EXTERN IfxSdmmc_Dat1_InOut IfxSdmmc0_DAT1_P20_8_INOUT;

/** \brief write data out and read data in
 */
IFX_EXTERN IfxSdmmc_Dat2_InOut IfxSdmmc0_DAT2_P20_10_INOUT;

/** \brief write data out and read data in
 */
IFX_EXTERN IfxSdmmc_Dat3_InOut IfxSdmmc0_DAT3_P20_11_INOUT;

/** \brief write data out and read data in
 */
IFX_EXTERN IfxSdmmc_Dat4_InOut IfxSdmmc0_DAT4_P20_12_INOUT;

/** \brief write data out and read data in
 */
IFX_EXTERN IfxSdmmc_Dat5_InOut IfxSdmmc0_DAT5_P20_13_INOUT;

/** \brief write data out and read data in
 */
IFX_EXTERN IfxSdmmc_Dat6_InOut IfxSdmmc0_DAT6_P20_14_INOUT;

/** \brief write data out and read data in
 */
IFX_EXTERN IfxSdmmc_Dat7_InOut IfxSdmmc0_DAT7_P15_0_INOUT;

/** \addtogroup IfxLld_Sdmmc__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxSdmmc_Clk_Out Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Clk_Out    *IfxSdmmc_Clk_Out_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_CLK_OUT_NUM_ITEMS];

/** \brief IfxSdmmc_Cmd_InOut Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Cmd_InOut  *IfxSdmmc_Cmd_InOut_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_CMD_INOUT_NUM_ITEMS];

/** \brief IfxSdmmc_Dat0_InOut Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Dat0_InOut *IfxSdmmc_Dat0_InOut_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_DAT0_INOUT_NUM_ITEMS];

/** \brief IfxSdmmc_Dat1_InOut Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Dat1_InOut *IfxSdmmc_Dat1_InOut_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_DAT1_INOUT_NUM_ITEMS];

/** \brief IfxSdmmc_Dat2_InOut Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Dat2_InOut *IfxSdmmc_Dat2_InOut_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_DAT2_INOUT_NUM_ITEMS];

/** \brief IfxSdmmc_Dat3_InOut Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Dat3_InOut *IfxSdmmc_Dat3_InOut_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_DAT3_INOUT_NUM_ITEMS];

/** \brief IfxSdmmc_Dat4_InOut Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Dat4_InOut *IfxSdmmc_Dat4_InOut_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_DAT4_INOUT_NUM_ITEMS];

/** \brief IfxSdmmc_Dat5_InOut Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Dat5_InOut *IfxSdmmc_Dat5_InOut_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_DAT5_INOUT_NUM_ITEMS];

/** \brief IfxSdmmc_Dat6_InOut Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Dat6_InOut *IfxSdmmc_Dat6_InOut_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_DAT6_INOUT_NUM_ITEMS];

/** \brief IfxSdmmc_Dat7_InOut Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Dat7_InOut *IfxSdmmc_Dat7_InOut_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_DAT7_INOUT_NUM_ITEMS];

/** \} */

#endif /* IFXSDMMC_PINMAP_LFBGA436_COM_H */
