/**
 * \file IfxScu_PinMap_LFBGA436_COM.h
 * \brief SCU  details
 * \ingroup IfxLld_Scu
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
 * \defgroup IfxLld_Scu_
 * \ingroup IfxLld_Scu
 * \defgroup IfxLld_Scu__Pinmap Variables Default
 * \ingroup IfxLld_Scu_
 * \defgroup IfxLld_Scu__PinTables Default
 * \ingroup IfxLld_Scu_
 */

#ifndef IFXSCU_PINMAP_LFBGA436_COM_H
#define IFXSCU_PINMAP_LFBGA436_COM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxScu_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXSCU_PINMAP_NUM_MODULES      1

#define IFXSCU_PINMAP_NUM_REQUESTS     8

#define IFXSCU_PINMAP_REQ_IN_NUM_ITEMS 7

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief ERU channel 0 input A
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ0A_P15_4_IN;

/** \brief ERU channel 0 input B
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ0B_P10_7_IN;

/** \brief ERU channel 0 input F
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ0F_P02_7_IN;

/** \brief ERU channel 1 input A
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ1A_P14_3_IN;

/** \brief ERU channel 1 input B
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ1B_P10_8_IN;

/** \brief ERU channel 1 input G
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ1G_P16_1_IN;

/** \brief ERU channel 2 input A
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ2A_P10_2_IN;

/** \brief ERU channel 2 input B
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ2B_P02_1_IN;

/** \brief ERU channel 2 input C
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ2C_P00_4_IN;

/** \brief ERU channel 3 input A
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ3A_P10_3_IN;

/** \brief ERU channel 3 input B
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ3B_P14_1_IN;

/** \brief ERU channel 3 input C
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ3C_P02_0_IN;

/** \brief ERU channel 4 input A
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ4A_P33_7_IN;

/** \brief ERU channel 4 input D
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ4D_P15_5_IN;

/** \brief ERU channel 4 input G
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ4G_P25_1_IN;

/** \brief ERU channel 5 input A
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ5A_P15_8_IN;

/** \brief ERU channel 5 input E
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ5E_P22_4_IN;

/** \brief ERU channel 5 input G
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ5G_P02_8_IN;

/** \brief ERU channel 6 input A
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ6A_P20_0_IN;

/** \brief ERU channel 6 input F
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ6F_P23_1_IN;

/** \brief ERU channel 7 input A
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ7A_P20_9_IN;

/** \brief ERU channel 7 input B
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ7B_P15_1_IN;

/** \brief ERU channel 7 input G
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ7G_P02_11_IN;

/** \addtogroup IfxLld_Scu__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxScu_Req_In Table
 */
IFX_EXTERN IFX_CONST IfxScu_Req_In *IfxScu_Req_In_pinTable[IFXSCU_PINMAP_NUM_MODULES][IFXSCU_PINMAP_NUM_REQUESTS][IFXSCU_PINMAP_REQ_IN_NUM_ITEMS];

/** \} */

#endif /* IFXSCU_PINMAP_LFBGA436_COM_H */
