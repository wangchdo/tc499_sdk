/**
 * \file IfxFsi_reg.h
 * \brief
 * \copyright Copyright (c) 2021 Infineon Technologies AG. All rights reserved.
 *
 *
 * Version: MC_ACE_A3G_HSI_NVM/V0.1.1.1.18
 * Specification: latest @ 2021-08-22 instance sheet @ MC_A3G_TC49x : V9.1.6.1.0 
 * MAY BE CHANGED BY USER [yes/no]: No
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Use of this file is subject to the terms of use agreed between (i) you or 
 * the company in which ordinary course of business you are acting and (ii) 
 * Infineon Technologies AG or its licensees. If and as long as no such 
 * terms of use are agreed, use of this file is subject to following:


 * Boost Software License - Version 1.0 - August 17th, 2003

 * Permission is hereby granted, free of charge, to any person or 
 * organization obtaining a copy of the software and accompanying 
 * documentation covered by this license (the "Software") to use, reproduce,
 * display, distribute, execute, and transmit the Software, and to prepare
 * derivative works of the Software, and to permit third-parties to whom the 
 * Software is furnished to do so, all subject to the following:

 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE 
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * \defgroup IfxSfr_Fsi_Registers_Cfg Fsi address
 * \ingroup IfxSfr_Fsi_Registers
 * 
 * \defgroup IfxSfr_Fsi_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Fsi_Registers_Cfg
 *
 * \defgroup IfxSfr_Fsi_Registers_Cfg_Fsi_csrm 2-FSI_CSRM
 * \ingroup IfxSfr_Fsi_Registers_Cfg
 *
 * \defgroup IfxSfr_Fsi_Registers_Cfg_Fsi_host 2-FSI_HOST
 * \ingroup IfxSfr_Fsi_Registers_Cfg
 *
 *
 */
#ifndef IFXFSI_REG_H
#define IFXFSI_REG_H 1
/******************************************************************************/
#include "IfxFsi_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Fsi_Registers_Cfg_BaseAddress
 * \{  */

/** \brief FSI object */
#define MODULE_FSI_CSRM /*lint --e(923, 9078)*/ ((*(Ifx_FSI*)0xF8028000u))
#define MODULE_FSI_HOST /*lint --e(923, 9078)*/ ((*(Ifx_FSI*)0xF8008000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Fsi_Registers_Cfg_Fsi_csrm
 * \{  */
/** \brief 0, Communication register 0 */
#define FSI_CSRM_COMM0 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_COMM0*)0xF8028000u)

/** \brief 1, Communication register 1 */
#define FSI_CSRM_COMM1 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_COMM1*)0xF8028001u)

/** \brief 2, Communication register 2 */
#define FSI_CSRM_COMM2 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_COMM2*)0xF8028002u)

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Fsi_Registers_Cfg_Fsi_host
 * \{  */
/** \brief 0, Communication register 0 */
#define FSI_HOST_COMM0 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_COMM0*)0xF8008000u)

/** \brief 1, Communication register 1 */
#define FSI_HOST_COMM1 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_COMM1*)0xF8008001u)

/** \brief 2, Communication register 2 */
#define FSI_HOST_COMM2 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_COMM2*)0xF8008002u)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXFSI_REG_H */
