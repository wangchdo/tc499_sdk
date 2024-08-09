/**
 * \file IfxCbs_PinMap_LFBGA292_COM.h
 * \brief CBS  details
 * \ingroup IfxLld_Cbs
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
 * \defgroup IfxLld_Cbs_
 * \ingroup IfxLld_Cbs
 * \defgroup IfxLld_Cbs__Pinmap Variables Default
 * \ingroup IfxLld_Cbs_
 * \defgroup IfxLld_Cbs__PinTables Default
 * \ingroup IfxLld_Cbs_
 */

#ifndef IFXCBS_PINMAP_LFBGA292_COM_H
#define IFXCBS_PINMAP_LFBGA292_COM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxCbs_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXCBS_PINMAP_NUM_MODULES       1

#define IFXCBS_PINMAP_NUM_CHANNELS      8

#define IFXCBS_PINMAP_TGI_IN_NUM_ITEMS  1

#define IFXCBS_PINMAP_TGO_OUT_NUM_ITEMS 1

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief Trigger input
 */
IFX_EXTERN IfxCbs_Tgi_In  IfxCbs_TGI0_P20_0_IN;

/** \brief Trigger input
 */
IFX_EXTERN IfxCbs_Tgi_In  IfxCbs_TGI1_P20_1_IN;

/** \brief Trigger input
 */
IFX_EXTERN IfxCbs_Tgi_In  IfxCbs_TGI2_P21_6_IN;

/** \brief Trigger input
 */
IFX_EXTERN IfxCbs_Tgi_In  IfxCbs_TGI3_P21_7_IN;

/** \brief Trigger input
 */
IFX_EXTERN IfxCbs_Tgi_In  IfxCbs_TGI4_P32_6_IN;

/** \brief Trigger input
 */
IFX_EXTERN IfxCbs_Tgi_In  IfxCbs_TGI5_P32_7_IN;

/** \brief Trigger input
 */
IFX_EXTERN IfxCbs_Tgi_In  IfxCbs_TGI6_P33_14_IN;

/** \brief Trigger input
 */
IFX_EXTERN IfxCbs_Tgi_In  IfxCbs_TGI7_P33_15_IN;

/** \brief Trigger output
 */
IFX_EXTERN IfxCbs_Tgo_Out IfxCbs_TGO0_P20_0_OUT;

/** \brief Trigger output
 */
IFX_EXTERN IfxCbs_Tgo_Out IfxCbs_TGO1_P20_1_OUT;

/** \brief Trigger output
 */
IFX_EXTERN IfxCbs_Tgo_Out IfxCbs_TGO2_P21_6_OUT;

/** \brief Trigger output
 */
IFX_EXTERN IfxCbs_Tgo_Out IfxCbs_TGO3_P21_7_OUT;

/** \brief Trigger output
 */
IFX_EXTERN IfxCbs_Tgo_Out IfxCbs_TGO4_P32_6_OUT;

/** \brief Trigger output
 */
IFX_EXTERN IfxCbs_Tgo_Out IfxCbs_TGO5_P32_7_OUT;

/** \brief Trigger output
 */
IFX_EXTERN IfxCbs_Tgo_Out IfxCbs_TGO6_P33_14_OUT;

/** \brief Trigger output
 */
IFX_EXTERN IfxCbs_Tgo_Out IfxCbs_TGO7_P33_15_OUT;

/** \addtogroup IfxLld_Cbs__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxCbs_Tgi_In Table
 */
IFX_EXTERN IFX_CONST IfxCbs_Tgi_In  *IfxCbs_Tgi_In_pinTable[IFXCBS_PINMAP_NUM_MODULES][IFXCBS_PINMAP_NUM_CHANNELS][IFXCBS_PINMAP_TGI_IN_NUM_ITEMS];

/** \brief IfxCbs_Tgo_Out Table
 */
IFX_EXTERN IFX_CONST IfxCbs_Tgo_Out *IfxCbs_Tgo_Out_pinTable[IFXCBS_PINMAP_NUM_MODULES][IFXCBS_PINMAP_NUM_CHANNELS][IFXCBS_PINMAP_TGO_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXCBS_PINMAP_LFBGA292_COM_H */
