/**
 * \file IfxSmu_PinMap_LFBGA436_COM.c
 * \brief SMU  details
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
#include "IfxSmu_PinMap_LFBGA436_COM.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IfxSmu_Ext_emergencystop_req_In IfxSmu_EXT_EMERGENCYSTOP_REQ_P21_2_IN = {&MODULE_SMU, {&MODULE_P21, 2}, Ifx_RxSel_a};

IfxSmu_Fsp_Out                  IfxSmu_FSP0_P33_8_OUT = {&MODULE_SMU, {&MODULE_P33, 8}, IfxPort_OutputIdx_general};

IfxSmu_Fsp_Out                  IfxSmu_FSP1_P33_12_OUT = {&MODULE_SMU, {&MODULE_P33, 12}, IfxPort_OutputIdx_general};

IfxSmu_Fsp_Out                  IfxSmu_FSP2_P32_2_OUT = {&MODULE_SMU, {&MODULE_P32, 2}, IfxPort_OutputIdx_general};

IfxSmu_Fsp_Out                  IfxSmu_FSP3_P32_5_OUT = {&MODULE_SMU, {&MODULE_P32, 5}, IfxPort_OutputIdx_general};

IfxSmu_Fspin_In                 IfxSmu_FSPIN0_P33_8_IN = {&MODULE_SMU, {&MODULE_P33, 8}, Ifx_RxSel_a};

IfxSmu_Fspin_In                 IfxSmu_FSPIN1_P33_12_IN = {&MODULE_SMU, {&MODULE_P33, 12}, Ifx_RxSel_a};

IfxSmu_Fspin_In                 IfxSmu_FSPIN2_P32_2_IN = {&MODULE_SMU, {&MODULE_P32, 2}, Ifx_RxSel_a};

IfxSmu_Fspin_In                 IfxSmu_FSPIN3_P32_5_IN = {&MODULE_SMU, {&MODULE_P32, 5}, Ifx_RxSel_a};

/** \addtogroup IfxLld_Smu__PinTables
 * \{ */

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxSmu_Ext_emergencystop_req_In *IfxSmu_Ext_emergencystop_req_In_pinTable[IFXSMU_PINMAP_NUM_MODULES][IFXSMU_PINMAP_EXT_EMERGENCYSTOP_REQ_IN_NUM_ITEMS] = {
    {
        &IfxSmu_EXT_EMERGENCYSTOP_REQ_P21_2_IN,
    },
};

IFX_CONST IfxSmu_Fsp_Out                  *IfxSmu_Fsp_Out_pinTable[IFXSMU_PINMAP_NUM_MODULES][IFXSMU_PINMAP_FSP_OUT_NUM_ITEMS] = {
    {
        &IfxSmu_FSP2_P32_2_OUT,
        &IfxSmu_FSP3_P32_5_OUT,
        &IfxSmu_FSP0_P33_8_OUT,
        &IfxSmu_FSP1_P33_12_OUT,
    },
};

IFX_CONST IfxSmu_Fspin_In                 *IfxSmu_Fspin_In_pinTable[IFXSMU_PINMAP_NUM_MODULES][IFXSMU_PINMAP_FSPIN_IN_NUM_ITEMS] = {
    {
        &IfxSmu_FSPIN2_P32_2_IN,
        &IfxSmu_FSPIN3_P32_5_IN,
        &IfxSmu_FSPIN0_P33_8_IN,
        &IfxSmu_FSPIN1_P33_12_IN,
    },
};

/** \} */

#endif
