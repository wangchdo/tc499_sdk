 /**********************************************************************************************************************
 * \file Ifx_Cfg_Ssw.h
 * \brief Configuration header file for the Startup Software
 * \copyright Copyright (C) Infineon Technologies AG 2019
 * 
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of 
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and 
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all 
 * derivative works of the Software, unless such copies or derivative works are solely in the form of 
 * machine-executable object code generated by a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN 
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE.
 *********************************************************************************************************************/


#ifndef IFX_CFG_SSW_H_
#define IFX_CFG_SSW_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Ifx_Cfg.h"
#include "Ifx_Ssw.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
/* Set this macro to 1, to configure the PMS EVR. */
#ifndef IFX_CFG_SSW_ENABLE_PMS_INIT
#define IFX_CFG_SSW_ENABLE_PMS_INIT                     (0U)
#endif

/* Set this macro to 1, to check the PMS EVR configuration. */
#ifndef IFX_CFG_SSW_ENABLE_PMS_INIT_CHECK
#define IFX_CFG_SSW_ENABLE_PMS_INIT_CHECK               (0U)
#endif

/* Set this macro to 1, to do LBIST checks. */
#ifndef IFX_CFG_SSW_ENABLE_LBIST
#define IFX_CFG_SSW_ENABLE_LBIST                        (0U)
#endif

/* Set this macro to 1, to do MONBIST checks. */
#ifndef IFX_CFG_SSW_ENABLE_MONBIST
#define IFX_CFG_SSW_ENABLE_MONBIST                      (0U)
#endif

/* Set this macro to 1, to shutdown unused power domains. */
#ifndef IFX_CFG_SSW_ENABLE_SHUTDOWN_UNUSED_PWRDOMAINS
#define IFX_CFG_SSW_ENABLE_SHUTDOWN_UNUSED_PWRDOMAINS   (0U)
#endif

/* Set this macro to 1, to do MBIST for DSPR0-5 and DMARAM. */
#ifndef IFX_CFG_SSW_ENABLE_MBIST_DSPRS_DMARAM
#define IFX_CFG_SSW_ENABLE_MBIST_DSPRS_DMARAM           (0U)
#endif

/* Set this macro to 1, to check for Stable clock e.g. MMIC. */
#ifndef IFX_CFG_SSW_ENABLE_XTALSRC_CHECK
#define IFX_CFG_SSW_ENABLE_XTALSRC_CHECK                (0U)
#endif

/* Set this macro to 1, to initialize the PLL. */
#ifndef IFX_CFG_SSW_ENABLE_PLL_INIT
#define IFX_CFG_SSW_ENABLE_PLL_INIT                     (1U)
#endif

/* Set this macro to 1, to configure PMIC Voltage Shift. */
#ifndef IFX_CFG_SSW_ENABLE_PMIC_VOLTAGESHIFT
#define IFX_CFG_SSW_ENABLE_PMIC_VOLTAGESHIFT            (0U)
#endif

/* Set this macro to 1, to do MBIST checks. */
#ifndef IFX_CFG_SSW_ENABLE_MBIST
#define IFX_CFG_SSW_ENABLE_MBIST                        (0U)
#endif

/* Set this macro to 1, to do AUTOSAR Services start. */
#ifndef IFX_CFG_SSW_ENABLE_AUTOSAR_SERVICESTART
#define IFX_CFG_SSW_ENABLE_AUTOSAR_SERVICESTART         (0U)
#endif

/* Set this macro to 1, to do SMU Alarm handling. */
#ifndef IFX_CFG_SSW_ENABLE_SMU
#define IFX_CFG_SSW_ENABLE_SMU                          (0U)
#endif

/* \brief Set this macro to 1, to do STL startup tests. */
#ifndef IFX_CFG_SSW_ENABLE_SAFETY_LIBRARY_TESTS
#define IFX_CFG_SSW_ENABLE_SAFETY_LIBRARY_TESTS         (0U)
#endif

/* Set this macro to 1, to initialize the AP. */
#ifndef IFX_CFG_SSW_ENABLE_AP_INIT
#define IFX_CFG_SSW_ENABLE_AP_INIT                      (1U)
#endif

#endif /* IFX_CFG_SSW_H_ */
