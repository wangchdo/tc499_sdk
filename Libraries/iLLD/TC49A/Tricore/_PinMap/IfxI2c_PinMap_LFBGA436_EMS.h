/**
 * \file IfxI2c_PinMap_LFBGA436_EMS.h
 * \brief I2C  details
 * \ingroup IfxLld_I2c
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
 * \defgroup IfxLld_I2c_
 * \ingroup IfxLld_I2c
 * \defgroup IfxLld_I2c__Pinmap Variables Default
 * \ingroup IfxLld_I2c_
 * \defgroup IfxLld_I2c__PinTables Default
 * \ingroup IfxLld_I2c_
 */

#ifndef IFXI2C_PINMAP_LFBGA436_EMS_H
#define IFXI2C_PINMAP_LFBGA436_EMS_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxI2c_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXI2C_PINMAP_NUM_MODULES         2

#define IFXI2C_PINMAP_SCL_INOUT_NUM_ITEMS 4

#define IFXI2C_PINMAP_SDA_INOUT_NUM_ITEMS 4

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief Serial Clock Output and Serial Clock Input 0
 */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c0_SCL_P02_5_INOUT;

/** \brief Serial Clock Output and Serial Clock Input 1
 */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c0_SCL_P13_1_INOUT;

/** \brief Serial Clock Output and Serial Clock Input 2
 */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c0_SCL_P15_4_INOUT;

/** \brief Serial Clock Output and Serial Clock Input 3
 */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c0_SCL_P32_4_INOUT;

/** \brief Serial Data Output and Serial Data Input 0
 */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c0_SDA_P02_4_INOUT;

/** \brief Serial Data Output and Serial Data Input 1
 */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c0_SDA_P13_2_INOUT;

/** \brief Serial Data Output and Serial Data Input 2
 */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c0_SDA_P15_5_INOUT;

/** \brief Serial Data Output and Serial Data Input 3
 */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c0_SDA_P32_6_INOUT;

/** \brief Serial Clock Output and Serial Clock Input 0
 */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c1_SCL_P11_14_INOUT;

/** \brief Serial Clock Output and Serial Clock Input 1
 */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c1_SCL_P13_9_INOUT;

/** \brief Serial Clock Output and Serial Clock Input 3
 */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c1_SCL_P34_3_INOUT;

/** \brief Serial Data Output and Serial Data Input 0
 */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c1_SDA_P11_13_INOUT;

/** \brief Serial Data Output and Serial Data Input 1
 */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c1_SDA_P13_12_INOUT;

/** \brief Serial Data Output and Serial Data Input 3
 */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c1_SDA_P34_2_INOUT;

/** \addtogroup IfxLld_I2c__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxI2c_Scl_InOut Table
 */
IFX_EXTERN IFX_CONST IfxI2c_Scl_InOut *IfxI2c_Scl_InOut_pinTable[IFXI2C_PINMAP_NUM_MODULES][IFXI2C_PINMAP_SCL_INOUT_NUM_ITEMS];

/** \brief IfxI2c_Sda_InOut Table
 */
IFX_EXTERN IFX_CONST IfxI2c_Sda_InOut *IfxI2c_Sda_InOut_pinTable[IFXI2C_PINMAP_NUM_MODULES][IFXI2C_PINMAP_SDA_INOUT_NUM_ITEMS];

/** \} */

#endif /* IFXI2C_PINMAP_LFBGA436_EMS_H */
