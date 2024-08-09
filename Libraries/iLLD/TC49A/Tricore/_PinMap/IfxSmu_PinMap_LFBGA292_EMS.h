/**
 * \file IfxSmu_PinMap_LFBGA292_EMS.h
 * \brief SMU  details
 * \ingroup IfxLld_Smu
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
 * \defgroup IfxLld_Smu_
 * \ingroup IfxLld_Smu
 * \defgroup IfxLld_Smu__Pinmap Variables Default
 * \ingroup IfxLld_Smu_
 * \defgroup IfxLld_Smu__PinTables Default
 * \ingroup IfxLld_Smu_
 */

#ifndef IFXSMU_PINMAP_LFBGA292_EMS_H
#define IFXSMU_PINMAP_LFBGA292_EMS_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxSmu_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXSMU_PINMAP_NUM_MODULES                        1

#define IFXSMU_PINMAP_EXT_EMERGENCYSTOP_REQ_IN_NUM_ITEMS 1

#define IFXSMU_PINMAP_FSP_OUT_NUM_ITEMS                  4

#define IFXSMU_PINMAP_FSPIN_IN_NUM_ITEMS                 4

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief Emergency Stop External Request
 */
IFX_EXTERN IfxSmu_Ext_emergencystop_req_In IfxSmu_EXT_EMERGENCYSTOP_REQ_P21_2_IN;

/** \brief FSP Output Signal - Generated by SMU
 */
IFX_EXTERN IfxSmu_Fsp_Out                  IfxSmu_FSP0_P33_8_OUT;

/** \brief FSP Output Signal - Generated by SMU
 */
IFX_EXTERN IfxSmu_Fsp_Out                  IfxSmu_FSP1_P33_12_OUT;

/** \brief FSP Output Signal - Generated by SMU
 */
IFX_EXTERN IfxSmu_Fsp_Out                  IfxSmu_FSP2_P32_2_OUT;

/** \brief FSP Output Signal - Generated by SMU
 */
IFX_EXTERN IfxSmu_Fsp_Out                  IfxSmu_FSP3_P32_5_OUT;

/** \brief FSP Status Input - Shows the actual state of the FSP ErroPin
 */
IFX_EXTERN IfxSmu_Fspin_In                 IfxSmu_FSPIN0_P33_8_IN;

/** \brief FSP Status Input - Shows the actual state of the FSP ErroPin
 */
IFX_EXTERN IfxSmu_Fspin_In                 IfxSmu_FSPIN1_P33_12_IN;

/** \brief FSP Status Input - Shows the actual state of the FSP ErroPin
 */
IFX_EXTERN IfxSmu_Fspin_In                 IfxSmu_FSPIN2_P32_2_IN;

/** \brief FSP Status Input - Shows the actual state of the FSP ErroPin
 */
IFX_EXTERN IfxSmu_Fspin_In                 IfxSmu_FSPIN3_P32_5_IN;

/** \addtogroup IfxLld_Smu__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxSmu_Ext_emergencystop_req_In Table
 */
IFX_EXTERN IFX_CONST IfxSmu_Ext_emergencystop_req_In *IfxSmu_Ext_emergencystop_req_In_pinTable[IFXSMU_PINMAP_NUM_MODULES][IFXSMU_PINMAP_EXT_EMERGENCYSTOP_REQ_IN_NUM_ITEMS];

/** \brief IfxSmu_Fsp_Out Table
 */
IFX_EXTERN IFX_CONST IfxSmu_Fsp_Out                  *IfxSmu_Fsp_Out_pinTable[IFXSMU_PINMAP_NUM_MODULES][IFXSMU_PINMAP_FSP_OUT_NUM_ITEMS];

/** \brief IfxSmu_Fspin_In Table
 */
IFX_EXTERN IFX_CONST IfxSmu_Fspin_In                 *IfxSmu_Fspin_In_pinTable[IFXSMU_PINMAP_NUM_MODULES][IFXSMU_PINMAP_FSPIN_IN_NUM_ITEMS];

/** \} */

#endif /* IFXSMU_PINMAP_LFBGA292_EMS_H */
