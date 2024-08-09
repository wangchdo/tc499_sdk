/**
 * \file IfxCbs_reg.h
 * \brief
 * \copyright Copyright (c) 2021 Infineon Technologies AG. All rights reserved.
 *
 *
 * Version: MC_ACE_A3G_HSI_Debug/V0.1.1.2.6
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
 * \defgroup IfxSfr_Cbs_Registers_Cfg Cbs address
 * \ingroup IfxSfr_Cbs_Registers
 * 
 * \defgroup IfxSfr_Cbs_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Cbs_Registers_Cfg
 *
 * \defgroup IfxSfr_Cbs_Registers_Cfg_Cbs 2-CBS
 * \ingroup IfxSfr_Cbs_Registers_Cfg
 *
 *
 */
#ifndef IFXCBS_REG_H
#define IFXCBS_REG_H 1
/******************************************************************************/
#include "IfxCbs_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Cbs_Registers_Cfg_BaseAddress
 * \{  */

/** \brief CBS object */
#define MODULE_CBS /*lint --e(923, 9078)*/ ((*(Ifx_CBS*)0xFA180000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Cbs_Registers_Cfg_Cbs
 * \{  */
/** \brief 8, Module Identification Register */
#define CBS_ID /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_ID*)0xFA180008u)

/** \brief 20, PROT Register  */
#define CBS_PROTSE /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_PROT*)0xFA180020u)

/** \brief 40, Write access enable register A */
#define CBS_ACCENWRA /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_ACCEN_WRA*)0xFA180040u)

/** \brief 44, Write access enable register B */
#define CBS_ACCENWRB /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_ACCEN_WRB_FPI*)0xFA180044u)

/** \brief 48, Read access enable register A */
#define CBS_ACCENRDA /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_ACCEN_RDA*)0xFA180048u)

/** \brief 4C, Read access enable register B */
#define CBS_ACCENRDB /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_ACCEN_RDB_FPI*)0xFA18004Cu)

/** \brief 50, VM access enable register */
#define CBS_ACCENVM /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_ACCEN_VM*)0xFA180050u)

/** \brief 54, PRS access enable register */
#define CBS_ACCENPRS /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_ACCEN_PRS*)0xFA180054u)

/** \brief 60, OCDS Interface Mode Register */
#define CBS_OIFM /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_OIFM*)0xFA180060u)

/** \brief 64, OSCU Control Register */
#define CBS_OCNTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_OCNTRL*)0xFA180064u)

/** \brief 68, OCDS Enable Control Register */
#define CBS_OEC /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_OEC*)0xFA180068u)

/** \brief 6C, OSCU Status Register */
#define CBS_OSTATE /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_OSTATE*)0xFA18006Cu)

/** \brief 70, IFS Address Register */
#define CBS_IFSA /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_IFSA*)0xFA180070u)

/** \brief 74, IFS Control Register */
#define CBS_IFSC /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_IFSC*)0xFA180074u)

/** \brief 80, JTAG Device Identification Register */
#define CBS_JTAGID /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_JTAGID*)0xFA180080u)

/** \brief 84, Communication Mode Data Register */
#define CBS_COMDATA /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_COMDATA*)0xFA180084u)

/** \brief 88, IOClient Status and Control Register */
#define CBS_IOSR /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_IOSR*)0xFA180088u)

/** \brief 90, Tool Identification Register for DAP connections */
#define CBS_TIHDAP /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TIH*)0xFA180090u)

/** \brief 94, Tool Identification Register for DAPE connections */
#define CBS_TIHDAPE /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TIH*)0xFA180094u)

/** \brief 98, Tool Identification Register for General Purpose connections */
#define CBS_TIHGP /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TIH*)0xFA180098u)

/** \brief E0, TG Input Pins Routing */
#define CBS_TIPR /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TIPR*)0xFA1800E0u)

/** \brief E4, TG Output Pins Routing */
#define CBS_TOPR /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TOPR*)0xFA1800E4u)

/** \brief E8, TG Output Pins Pulse Stretcher */
#define CBS_TOPPS /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TOPPS*)0xFA1800E8u)

/** \brief 100, TG Routing for CPUCS Control */
#define CBS_TRCCS /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRCCS*)0xFA180100u)

/** \brief 104, TG Routing for CPU0 */
#define CBS_TRC0 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRC*)0xFA180104u)

/** \brief 108, TG Routing for CPU1 */
#define CBS_TRC1 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRC*)0xFA180108u)

/** \brief 10C, TG Routing for CPU2 */
#define CBS_TRC2 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRC*)0xFA18010Cu)

/** \brief 110, TG Routing for CPU3 */
#define CBS_TRC3 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRC*)0xFA180110u)

/** \brief 114, TG Routing for CPU4 */
#define CBS_TRC4 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRC*)0xFA180114u)

/** \brief 118, TG Routing for CPU5 */
#define CBS_TRC5 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRC*)0xFA180118u)

/** \brief 190, TG Routing for PPU */
#define CBS_TRPPU0 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRPPU*)0xFA180190u)

/** \brief 1A0, TG Routing for MCDS Control */
#define CBS_TRMC /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRMC*)0xFA1801A0u)

/** \brief 1A4, TG Routing for Special Signals */
#define CBS_TRSS /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRSS*)0xFA1801A4u)

/** \brief 1B0, OTGM OTGB0/1 Status */
#define CBS_OOBS /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_OOBS*)0xFA1801B0u)

/** \brief 1B8, OTGM MCDS I/F Sensitivity Posedge */
#define CBS_OMISP /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_OMISP*)0xFA1801B8u)

/** \brief 1BC, OTGM MCDS I/F Sensitivity Negedge */
#define CBS_OMISN /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_OMISN*)0xFA1801BCu)

/** \brief 1D0, TG Routing for OTGBi Bits [7:0] */
#define CBS_TRTGB0_L /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRTGB_L*)0xFA1801D0u)
/** Alias (User Manual Name) for CBS_TRTGB0_L */
#define CBS_TRTGB0L (CBS_TRTGB0_L)

/** \brief 1D4, TG Routing for OTGBi Bits [15:8] */
#define CBS_TRTGB0_H /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRTGB_H*)0xFA1801D4u)
/** Alias (User Manual Name) for CBS_TRTGB0_H */
#define CBS_TRTGB0H (CBS_TRTGB0_H)

/** \brief 1D8, TG Routing for OTGBi Bits [7:0] */
#define CBS_TRTGB1_L /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRTGB_L*)0xFA1801D8u)
/** Alias (User Manual Name) for CBS_TRTGB1_L */
#define CBS_TRTGB1L (CBS_TRTGB1_L)

/** \brief 1DC, TG Routing for OTGBi Bits [15:8] */
#define CBS_TRTGB1_H /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRTGB_H*)0xFA1801DCu)
/** Alias (User Manual Name) for CBS_TRTGB1_H */
#define CBS_TRTGB1H (CBS_TRTGB1_H)

/** \brief 204, TG Routing Events of CPU0 */
#define CBS_TREC0 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TREC*)0xFA180204u)

/** \brief 208, TG Routing Events of CPU1 */
#define CBS_TREC1 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TREC*)0xFA180208u)

/** \brief 20C, TG Routing Events of CPU2 */
#define CBS_TREC2 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TREC*)0xFA18020Cu)

/** \brief 210, TG Routing Events of CPU3 */
#define CBS_TREC3 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TREC*)0xFA180210u)

/** \brief 214, TG Routing Events of CPU4 */
#define CBS_TREC4 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TREC*)0xFA180214u)

/** \brief 218, TG Routing Events of CPU5 */
#define CBS_TREC5 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TREC*)0xFA180218u)

/** \brief 290, TG Routing Events of PPU */
#define CBS_TREPPU0 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TREPPU*)0xFA180290u)

/** \brief 2A0, TG Routing for MCDS Triggers */
#define CBS_TRMT /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRMT*)0xFA1802A0u)

/** \brief 2B0, TG Line State */
#define CBS_TLS /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TLS*)0xFA1802B0u)

/** \brief 2B4, TG Line Control */
#define CBS_TLC /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TLC*)0xFA1802B4u)

/** \brief 2B8, TG Line 1 Suspend Targets */
#define CBS_TL1ST /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TL1ST*)0xFA1802B8u)

/** \brief 2BC, TG Line Capture and Hold Enable */
#define CBS_TLCHE /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TLCHE*)0xFA1802BCu)

/** \brief 2C0, TG Line Capture and Hold Clear */
#define CBS_TLCHS /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TLCHS*)0xFA1802C0u)

/** \brief 2C4, TG Line Timer */
#define CBS_TLT /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TLT*)0xFA1802C4u)

/** \brief 2C8, TG Lines for Trigger to Host */
#define CBS_TLTTH /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TLTTH*)0xFA1802C8u)

/** \brief 2D0, TG Line Counter Control */
#define CBS_TLCC0 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TLCC*)0xFA1802D0u)

/** \brief 2D4, TG Line Counter Value */
#define CBS_TLCV0 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TLCV*)0xFA1802D4u)

/** \brief 2D8, TG Line Counter Control */
#define CBS_TLCC1 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TLCC*)0xFA1802D8u)

/** \brief 2DC, TG Line Counter Value */
#define CBS_TLCV1 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TLCV*)0xFA1802DCu)

/** \brief 2F0, TG Capture for MCDS */
#define CBS_TCM /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TCM*)0xFA1802F0u)

/** \brief 2F4, TG Capture for TG Lines */
#define CBS_TCTL /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TCTL*)0xFA1802F4u)

/** \brief 2F8, TG Capture for TG Input Pins */
#define CBS_TCIP /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TCIP*)0xFA1802F8u)

/** \brief 2FC, TG Capture for Cores - BRKOUT */
#define CBS_TCCB /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TCCB*)0xFA1802FCu)

/** \brief 300, TG Capture for Cores - HALT */
#define CBS_TCCH /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TCCH*)0xFA180300u)

/** \brief 304, TG Capture for OTGB0/1 */
#define CBS_TCTGB /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TCTGB*)0xFA180304u)

/** \brief 318, Set Trigger to Host Register */
#define CBS_TRIGS /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRIGS*)0xFA180318u)

/** \brief 31C, Clear Trigger to Host Register */
#define CBS_TRIGC /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRIGC*)0xFA18031Cu)

/** \brief 320, Trigger to Host Register 0 */
#define CBS_TRIG0 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRIG*)0xFA180320u)

/** \brief 324, Trigger to Host Register 1 */
#define CBS_TRIG1 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRIG*)0xFA180324u)

/** \brief 328, Trigger to Host Register 2 */
#define CBS_TRIG2 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRIG*)0xFA180328u)

/** \brief 32C, Trigger to Host Register 3 */
#define CBS_TRIG3 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRIG*)0xFA18032Cu)

/** \brief 330, Trigger to Host Register 4 */
#define CBS_TRIG4 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRIG*)0xFA180330u)

/** \brief 334, Trigger to Host Register 5 */
#define CBS_TRIG5 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRIG*)0xFA180334u)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXCBS_REG_H */
