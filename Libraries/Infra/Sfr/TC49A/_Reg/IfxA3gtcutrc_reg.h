/**
 * \file IfxA3gtcutrc_reg.h
 * \brief
 * \copyright Copyright (c) 2020 Infineon Technologies AG. All rights reserved.
 *
 *
 * Version: MC_ACE_A3G_HSI_DFT/V9.1.1.1.7
 * Specification: latest @ 2020-07-15, instance sheet @ MC_A3G_TC49x : V9.1.3.1.0 
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
 * \defgroup IfxSfr_A3gtcutrc_Registers_Cfg A3gtcutrc address
 * \ingroup IfxSfr_A3gtcutrc_Registers
 * 
 * \defgroup IfxSfr_A3gtcutrc_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_A3gtcutrc_Registers_Cfg
 *
 * \defgroup IfxSfr_A3gtcutrc_Registers_Cfg_Tcu 2-TCU
 * \ingroup IfxSfr_A3gtcutrc_Registers_Cfg
 *
 *
 */
#ifndef IFXA3GTCUTRC_REG_H
#define IFXA3GTCUTRC_REG_H 1
/******************************************************************************/
#include "IfxA3gtcutrc_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_A3gtcutrc_Registers_Cfg_BaseAddress
 * \{  */

/** \brief A3GTCUTRC object */
#define MODULE_TCU /*lint --e(923, 9078)*/ ((*(Ifx_A3GTCUTRC*)0x0u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_A3gtcutrc_Registers_Cfg_Tcu
 * \{  */
/** \brief 4, JTAG_IDCODE Register [TC49x] */
#define TCU_IDCODE /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_IDCODE*)0x4u)

/** \brief 52, Global Test-Mode-Register */
#define TCU_TEST_GLOBTMC /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_GLOBTMC*)0x52u)

/** \brief 52, ATM-Initialization */
#define TCU_VIRTUAL_GLOBTMC /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_VIRTUAL_GLOBTMC*)0x52u)

/** \brief 53, Timing & RingO Control [TC49xA] */
#define TCU_TEST_TIMCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_TIMCTRL*)0x53u)

/** \brief 54, Firmware Test Selection Register */
#define TCU_TEST_MPTRC_FW /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MPTRC_FW*)0x54u)

/** \brief 54, Pad Driving Strength Control Register */
#define TCU_TEST_MPTRC_PAD /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MPTRC_PAD*)0x54u)

/** \brief 54, Oscillator Control Register */
#define TCU_TEST_MPTRC_OSC /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MPTRC_OSC*)0x54u)

/** \brief 54, Logic-BIST Control Register */
#define TCU_TEST_MPTRC_LBIST /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MPTRC_LBIST*)0x54u)

/** \brief 54, ADC TestMUX Control Register [TC49xA] */
#define TCU_TEST_MPTRC_ADC /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MPTRC_ADC*)0x54u)

/** \brief 55, System Test-Mode Register */
#define TCU_TEST_SYSTM /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_SYSTM*)0x55u)

/** \brief 56, SSH Enable Register dMTU #0 [TC49xA] */
#define TCU_TEST_SSHEN_MTU0 /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_SSHEN_MTU0*)0x56u)

/** \brief 57, SSH Enable Register dMTU #1 [TC49xA] */
#define TCU_TEST_SSHEN_MTU1 /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_SSHEN_MTU1*)0x57u)

/** \brief 58, SSH Enable Register dMTU #2 [TC49xA] */
#define TCU_TEST_SSHEN_MTU2 /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_SSHEN_MTU2*)0x58u)

/** \brief 59, SSH Enable Register dMTU #3 [TC49xA] */
#define TCU_TEST_SSHEN_MTU3 /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_SSHEN_MTU3*)0x59u)

/** \brief 5A, SSH Enable Register dMTU #4 [TC49xA] */
#define TCU_TEST_SSHEN_MTU4 /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_SSHEN_MTU4*)0x5Au)

/** \brief 5B, SSH Enable Register dMTU #5 [TC49xA] */
#define TCU_TEST_SSHEN_MTU5 /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_SSHEN_MTU5*)0x5Bu)

/** \brief 5C, SSH Enable Register dMTU #6 [TC49xA] */
#define TCU_TEST_SSHEN_MTU6 /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_SSHEN_MTU6*)0x5Cu)

/** \brief 60, SSH Test Ctrl. and Status Register dMTU #0 [Poll-Transaction: Not more than 21 shift-cycles] */
#define TCU_TEST_MBPJT_MTU0_POLL /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU0_POLL*)0x60u)

/** \brief 60, SSH Test Ctrl. and Status Register dMTU #0 [Write-Transaction: WEN=1] */
#define TCU_TEST_MBPJT_MTU0_WR /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU0_WR*)0x60u)

/** \brief 60, SSH Test Ctrl. and Status Register dMTU #0 [Read-Transaction: WEN=0] */
#define TCU_TEST_MBPJT_MTU0_RD /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU0_RD*)0x60u)

/** \brief 61, SSH Test Ctrl. and Status Register dMTU #1 [Poll-Transaction: Not more than 21 shift-cycles] */
#define TCU_TEST_MBPJT_MTU1_POLL /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU1_POLL*)0x61u)

/** \brief 61, SSH Test Ctrl. and Status Register dMTU #1 [Write-Transaction: WEN=1] */
#define TCU_TEST_MBPJT_MTU1_WR /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU1_WR*)0x61u)

/** \brief 61, SSH Test Ctrl. and Status Register dMTU #1 [Read-Transaction: WEN=0] */
#define TCU_TEST_MBPJT_MTU1_RD /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU1_RD*)0x61u)

/** \brief 62, SSH Test Ctrl. and Status Register dMTU #2 [Poll-Transaction: Not more than 21 shift-cycles] */
#define TCU_TEST_MBPJT_MTU2_POLL /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU2_POLL*)0x62u)

/** \brief 62, SSH Test Ctrl. and Status Register dMTU #2 [Write-Transaction: WEN=1] */
#define TCU_TEST_MBPJT_MTU2_WR /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU2_WR*)0x62u)

/** \brief 62, SSH Test Ctrl. and Status Register dMTU #2 [Read-Transaction: WEN=0] */
#define TCU_TEST_MBPJT_MTU2_RD /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU2_RD*)0x62u)

/** \brief 63, SSH Test Ctrl. and Status Register dMTU #3 [Poll-Transaction: Not more than 21 shift-cycles] */
#define TCU_TEST_MBPJT_MTU3_POLL /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU3_POLL*)0x63u)

/** \brief 63, SSH Test Ctrl. and Status Register dMTU #3 [Write-Transaction: WEN=1] */
#define TCU_TEST_MBPJT_MTU3_WR /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU3_WR*)0x63u)

/** \brief 63, SSH Test Ctrl. and Status Register dMTU #3 [Read-Transaction: WEN=0] */
#define TCU_TEST_MBPJT_MTU3_RD /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU3_RD*)0x63u)

/** \brief 64, SSH Test Ctrl. and Status Register dMTU #4 [Poll-Transaction: Not more than 21 shift-cycles] */
#define TCU_TEST_MBPJT_MTU4_POLL /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU4_POLL*)0x64u)

/** \brief 64, SSH Test Ctrl. and Status Register dMTU #4 [Write-Transaction: WEN=1] */
#define TCU_TEST_MBPJT_MTU4_WR /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU4_WR*)0x64u)

/** \brief 64, SSH Test Ctrl. and Status Register dMTU #4 [Read-Transaction: WEN=0] */
#define TCU_TEST_MBPJT_MTU4_RD /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU4_RD*)0x64u)

/** \brief 65, SSH Test Ctrl. and Status Register dMTU #5 [Poll-Transaction: Not more than 21 shift-cycles] */
#define TCU_TEST_MBPJT_MTU5_POLL /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU5_POLL*)0x65u)

/** \brief 65, SSH Test Ctrl. and Status Register dMTU #5 [Write-Transaction: WEN=1] */
#define TCU_TEST_MBPJT_MTU5_WR /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU5_WR*)0x65u)

/** \brief 65, SSH Test Ctrl. and Status Register dMTU #5 [Read-Transaction: WEN=0] */
#define TCU_TEST_MBPJT_MTU5_RD /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU5_RD*)0x65u)

/** \brief 66, SSH Test Ctrl. and Status Register dMTU #6 [Poll-Transaction: Not more than 21 shift-cycles] */
#define TCU_TEST_MBPJT_MTU6_POLL /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU6_POLL*)0x66u)

/** \brief 66, SSH Test Ctrl. and Status Register dMTU #6 [Write-Transaction: WEN=1] */
#define TCU_TEST_MBPJT_MTU6_WR /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU6_WR*)0x66u)

/** \brief 66, SSH Test Ctrl. and Status Register dMTU #6 [Read-Transaction: WEN=0] */
#define TCU_TEST_MBPJT_MTU6_RD /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_MBPJT_MTU6_RD*)0x66u)

/** \brief 6A, Package Configuration Control [TC49xA] */
#define TCU_TEST_PKGCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_PKGCTRL*)0x6Au)

/** \brief 6B, LVDSH Pad Overruling Control [TC49xA] */
#define TCU_TEST_LVDSCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_LVDSCTRL*)0x6Bu)

/** \brief AE, LBIST_HDI #0 Test-Mode-Register */
#define TCU_TEST_LBIST_HDI0 /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_LBIST_HDI*)0xAEu)

/** \brief AF, LBIST_HDI #1 Test-Mode-Register */
#define TCU_TEST_LBIST_HDI1 /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_LBIST_HDI*)0xAFu)

/** \brief B0, LBIST_HDI #2 Test-Mode-Register */
#define TCU_TEST_LBIST_HDI2 /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_LBIST_HDI*)0xB0u)

/** \brief B1, LBIST_HDI #3 Test-Mode-Register */
#define TCU_TEST_LBIST_HDI3 /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_LBIST_HDI*)0xB1u)

/** \brief B2, LBIST_HDI #4 Test-Mode-Register */
#define TCU_TEST_LBIST_HDI4 /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_LBIST_HDI*)0xB2u)

/** \brief B3, LBIST_HDI #5 Test-Mode-Register */
#define TCU_TEST_LBIST_HDI5 /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_LBIST_HDI*)0xB3u)

/** \brief B4, LBIST_HDI #6 Test-Mode-Register */
#define TCU_TEST_LBIST_HDI6 /*lint --e(923, 9078)*/ (*(volatile Ifx_A3GTCUTRC_TEST_LBIST_HDI*)0xB4u)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXA3GTCUTRC_REG_H */
