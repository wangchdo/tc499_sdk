/**
 * \file IfxAdc_PinMap_LFBGA436_COM.h
 * \brief ADC  details
 * \ingroup IfxLld_Adc
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
 * \defgroup IfxLld_Adc_
 * \ingroup IfxLld_Adc
 * \defgroup IfxLld_Adc__Pinmap Variables Default
 * \ingroup IfxLld_Adc_
 * \defgroup IfxLld_Adc__PinTables Default
 * \ingroup IfxLld_Adc_
 */

#ifndef IFXADC_PINMAP_LFBGA436_COM_H
#define IFXADC_PINMAP_LFBGA436_COM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxAdc_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXADC_PINMAP_NUM_MODULES            1

#define IFXADC_PINMAP_BFL_OUT_NUM_ITEMS      20

#define IFXADC_PINMAP_CLKIN_IN_NUM_ITEMS     8

#define IFXADC_PINMAP_CLKOUT_OUT_NUM_ITEMS   9

#define IFXADC_PINMAP_DATA_IN_NUM_ITEMS      8

#define IFXADC_PINMAP_DSADCN_IN_NUM_ITEMS    24

#define IFXADC_PINMAP_DSADCP_IN_NUM_ITEMS    24

#define IFXADC_PINMAP_EMUXCTRL_OUT_NUM_ITEMS 12

#define IFXADC_PINMAP_PWM_OUT_NUM_ITEMS      6

#define IFXADC_PINMAP_SIGN_IN_NUM_ITEMS      2

#define IFXADC_PINMAP_TRIG_IN_NUM_ITEMS      8

#define IFXADC_FCC_PINMAP_NUM_MODULES        1

#define IFXADC_PINMAP_FCC_IN_NUM_ITEMS       10

#define IFXADC_TMADC_PINMAP_NUM_MODULES      8

#define IFXADC_TMADC_PINMAP_NUM_CHANNELS     16

#define IFXADC_PINMAP_TMADCCH_IN_NUM_ITEMS   1

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief Boundary flags from FCC
 */
IFX_EXTERN IfxAdc_Bfl_Out      IfxAdc_BFL0_P00_5_OUT;

/** \brief Boundary flags from FCC
 */
IFX_EXTERN IfxAdc_Bfl_Out      IfxAdc_BFL0_P33_4_OUT;

/** \brief Boundary flags from FCC
 */
IFX_EXTERN IfxAdc_Bfl_Out      IfxAdc_BFL1_P10_1_OUT;

/** \brief Boundary flags from FCC
 */
IFX_EXTERN IfxAdc_Bfl_Out      IfxAdc_BFL1_P33_6_OUT;

/** \brief Boundary flags from FCC
 */
IFX_EXTERN IfxAdc_Bfl_Out      IfxAdc_BFL2_P33_0_OUT;

/** \brief Boundary flags from FCC
 */
IFX_EXTERN IfxAdc_Bfl_Out      IfxAdc_BFL2_P33_5_OUT;

/** \brief Boundary flags from FCC
 */
IFX_EXTERN IfxAdc_Bfl_Out      IfxAdc_BFL3_P10_2_OUT;

/** \brief Boundary flags from FCC
 */
IFX_EXTERN IfxAdc_Bfl_Out      IfxAdc_BFL3_P33_2_OUT;

/** \brief Boundary flags from FCC
 */
IFX_EXTERN IfxAdc_Bfl_Out      IfxAdc_BFL4_P01_8_OUT;

/** \brief Boundary flags from FCC
 */
IFX_EXTERN IfxAdc_Bfl_Out      IfxAdc_BFL4_P33_1_OUT;

/** \brief Boundary flags from FCC
 */
IFX_EXTERN IfxAdc_Bfl_Out      IfxAdc_BFL5_P01_9_OUT;

/** \brief Boundary flags from FCC
 */
IFX_EXTERN IfxAdc_Bfl_Out      IfxAdc_BFL5_P33_3_OUT;

/** \brief Boundary flags from FCC
 */
IFX_EXTERN IfxAdc_Bfl_Out      IfxAdc_BFL6_P01_10_OUT;

/** \brief Boundary flags from FCC
 */
IFX_EXTERN IfxAdc_Bfl_Out      IfxAdc_BFL6_P34_4_OUT;

/** \brief Boundary flags from FCC
 */
IFX_EXTERN IfxAdc_Bfl_Out      IfxAdc_BFL7_P01_11_OUT;

/** \brief Boundary flags from FCC
 */
IFX_EXTERN IfxAdc_Bfl_Out      IfxAdc_BFL7_P34_5_OUT;

/** \brief Boundary flags from FCC
 */
IFX_EXTERN IfxAdc_Bfl_Out      IfxAdc_BFL8_P10_3_OUT;

/** \brief Boundary flags from FCC
 */
IFX_EXTERN IfxAdc_Bfl_Out      IfxAdc_BFL8_P33_9_OUT;

/** \brief Boundary flags from FCC
 */
IFX_EXTERN IfxAdc_Bfl_Out      IfxAdc_BFL9_P10_4_OUT;

/** \brief Boundary flags from FCC
 */
IFX_EXTERN IfxAdc_Bfl_Out      IfxAdc_BFL9_P33_11_OUT;

/** \brief Clock input to EXMOD
 */
IFX_EXTERN IfxAdc_Clkin_In     IfxAdc_CLKIN0_P33_5_IN;

/** \brief Clock input to EXMOD
 */
IFX_EXTERN IfxAdc_Clkin_In     IfxAdc_CLKIN1_P33_3_IN;

/** \brief Clock input to EXMOD
 */
IFX_EXTERN IfxAdc_Clkin_In     IfxAdc_CLKIN2_P33_1_IN;

/** \brief Clock input to EXMOD
 */
IFX_EXTERN IfxAdc_Clkin_In     IfxAdc_CLKIN3_P10_0_IN;

/** \brief Clock input to EXMOD
 */
IFX_EXTERN IfxAdc_Clkin_In     IfxAdc_CLKIN4_P02_1_IN;

/** \brief Clock input to EXMOD
 */
IFX_EXTERN IfxAdc_Clkin_In     IfxAdc_CLKIN5_P02_3_IN;

/** \brief Clock input to EXMOD
 */
IFX_EXTERN IfxAdc_Clkin_In     IfxAdc_CLKIN6_P02_13_IN;

/** \brief Clock input to EXMOD
 */
IFX_EXTERN IfxAdc_Clkin_In     IfxAdc_CLKIN7_P02_15_IN;

/** \brief Clock output from EXMOD
 */
IFX_EXTERN IfxAdc_Clkout_Out   IfxAdc_CLKOUT0_P00_11_OUT;

/** \brief Clock output from EXMOD
 */
IFX_EXTERN IfxAdc_Clkout_Out   IfxAdc_CLKOUT0_P02_15_OUT;

/** \brief Clock output from EXMOD
 */
IFX_EXTERN IfxAdc_Clkout_Out   IfxAdc_CLKOUT0_P10_0_OUT;

/** \brief Clock output from EXMOD
 */
IFX_EXTERN IfxAdc_Clkout_Out   IfxAdc_CLKOUT1_P02_1_OUT;

/** \brief Clock output from EXMOD
 */
IFX_EXTERN IfxAdc_Clkout_Out   IfxAdc_CLKOUT1_P33_1_OUT;

/** \brief Clock output from EXMOD
 */
IFX_EXTERN IfxAdc_Clkout_Out   IfxAdc_CLKOUT2_P02_3_OUT;

/** \brief Clock output from EXMOD
 */
IFX_EXTERN IfxAdc_Clkout_Out   IfxAdc_CLKOUT2_P33_3_OUT;

/** \brief Clock output from EXMOD
 */
IFX_EXTERN IfxAdc_Clkout_Out   IfxAdc_CLKOUT3_P02_13_OUT;

/** \brief Clock output from EXMOD
 */
IFX_EXTERN IfxAdc_Clkout_Out   IfxAdc_CLKOUT3_P33_5_OUT;

/** \brief Modulated data to EXMOD
 */
IFX_EXTERN IfxAdc_Data_In      IfxAdc_DATA0_P33_6_IN;

/** \brief Modulated data to EXMOD
 */
IFX_EXTERN IfxAdc_Data_In      IfxAdc_DATA1_P33_4_IN;

/** \brief Modulated data to EXMOD
 */
IFX_EXTERN IfxAdc_Data_In      IfxAdc_DATA2_P33_2_IN;

/** \brief Modulated data to EXMOD
 */
IFX_EXTERN IfxAdc_Data_In      IfxAdc_DATA3_P02_8_IN;

/** \brief Modulated data to EXMOD
 */
IFX_EXTERN IfxAdc_Data_In      IfxAdc_DATA4_P02_6_IN;

/** \brief Modulated data to EXMOD
 */
IFX_EXTERN IfxAdc_Data_In      IfxAdc_DATA5_P02_4_IN;

/** \brief Modulated data to EXMOD
 */
IFX_EXTERN IfxAdc_Data_In      IfxAdc_DATA6_P02_12_IN;

/** \brief Modulated data to EXMOD
 */
IFX_EXTERN IfxAdc_Data_In      IfxAdc_DATA7_P02_14_IN;

/** \brief Analog Input for DSADC3 Negative Input A
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNA_AN1_IN;

/** \brief Analog Input for DSADC2 Negative Input A
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNA_AN21_IN;

/** \brief Analog Input for DSADC0 Negative Input A
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNA_AN3_IN;

/** \brief Analog Input for DSADC9 Negative Input
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNA_AN51_IN;

/** \brief Analog Input for DSADC6 Negative Input A
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNA_AN53_IN;

/** \brief Analog Input for DSADC10 Negative Input
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNA_AN59_IN;

/** \brief Analog Input for DSADC7 Negative Input A
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNA_AN61_IN;

/** \brief Analog Input for DSADC13 Negative Input
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNA_AN65_IN;

/** \brief Analog Input for DSADC5 Negative Input A
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNA_P00_1_IN;

/** \brief Analog Input for DSADC4 Negative Input A
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNA_P00_7_IN;

/** \brief Analog Input for DSADC1 Negative Input A
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNA_P40_7_IN;

/** \brief Analog Input for DSADC11 Negative Input
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNA_P41_0_IN;

/** \brief Analog Input for DSADC8 Negative Input
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNA_P41_2_IN;

/** \brief Analog Input for DSADC12 Negative Input
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNA_P41_4_IN;

/** \brief Analog Input for DSADC0 Negative Input B
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNB_AN13_IN;

/** \brief Analog Input for DSADC3 Negative Input B
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNB_AN15_IN;

/** \brief Analog Input for DSADC5 Negative Input B
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNB_P00_3_IN;

/** \brief Analog Input for DSADC4 Negative Input B
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNB_P00_9_IN;

/** \brief Analog Input for DSADC2 Negative Input B
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNB_P40_1_IN;

/** \brief Analog Input for DSADC1 Negative Input B
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNB_P40_9_IN;

/** \brief Analog Input for DSADC6 Negative Input B
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNB_P41_6_IN;

/** \brief Analog Input for DSADC7 Negative Input B
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNB_P41_8_IN;

/** \brief Analog Input for DSADC1 Negative Input C
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNC_AN45_IN;

/** \brief Analog Input for DSADC1 Negative Input D
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCND_AN47_IN;

/** \brief Analog Input for DSADC3 Positive Input A
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPA_AN0_IN;

/** \brief Analog Input for DSADC2 Positive Input A
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPA_AN20_IN;

/** \brief Analog Input for DSADC0 Positive Input A
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPA_AN2_IN;

/** \brief Analog Input for DSADC9 Positive Input
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPA_AN50_IN;

/** \brief Analog Input for DSADC6 Positive Input A
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPA_AN52_IN;

/** \brief Analog Input for DSADC10 Positive Input
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPA_AN58_IN;

/** \brief Analog Input for DSADC7 Positive Input A
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPA_AN60_IN;

/** \brief Analog Input for DSADC13 Positive Input
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPA_AN64_IN;

/** \brief Analog Input for DSADC11 Positive Input
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPA_AN66_IN;

/** \brief Analog Input for DSADC5 Positive Input A
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPA_P00_2_IN;

/** \brief Analog Input for DSADC4 Positive Input A
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPA_P00_8_IN;

/** \brief Analog Input for DSADC1 Positive Input A
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPA_P40_6_IN;

/** \brief Analog Input for DSADC8 Positive Input
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPA_P41_1_IN;

/** \brief Analog Input for DSADC12 Positive Input
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPA_P41_3_IN;

/** \brief Analog Input for DSADC0 Positive Input B
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPB_AN12_IN;

/** \brief Analog Input for DSADC3 Positive Input B
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPB_AN14_IN;

/** \brief Analog Input for DSADC4 Positive Input B
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPB_P00_10_IN;

/** \brief Analog Input for DSADC5 Positive Input B
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPB_P00_4_IN;

/** \brief Analog Input for DSADC2 Positive Input B
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPB_P40_0_IN;

/** \brief Analog Input for DSADC1 Positive Input B
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPB_P40_8_IN;

/** \brief Analog Input for DSADC6 Positive Input B
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPB_P41_5_IN;

/** \brief Analog Input for DSADC7 Positive Input B
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPB_P41_7_IN;

/** \brief Analog Input for DSADC1 Positive Input C
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPC_AN44_IN;

/** \brief Analog Input for DSADC1 Positive Input D
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPD_AN46_IN;

/** \brief EMUX0 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL00_P02_6_OUT;

/** \brief EMUX0 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL00_P33_3_OUT;

/** \brief EMUX0 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL01_P02_7_OUT;

/** \brief EMUX0 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL01_P33_2_OUT;

/** \brief EMUX0 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL02_P02_8_OUT;

/** \brief EMUX0 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL02_P33_1_OUT;

/** \brief EMUX1 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL10_P00_6_OUT;

/** \brief EMUX1 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL10_P33_6_OUT;

/** \brief EMUX1 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL11_P00_7_OUT;

/** \brief EMUX1 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL11_P33_5_OUT;

/** \brief EMUX1 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL12_P00_8_OUT;

/** \brief EMUX1 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL12_P33_4_OUT;

/** \brief Analog Input for FCC0
 */
IFX_EXTERN IfxAdc_Fcc_In       IfxAdc_Fcc_FCC0_AN16_IN;

/** \brief Analog Input for FCC1
 */
IFX_EXTERN IfxAdc_Fcc_In       IfxAdc_Fcc_FCC1_P40_10_IN;

/** \brief Analog Input for FCC2
 */
IFX_EXTERN IfxAdc_Fcc_In       IfxAdc_Fcc_FCC2_P00_12_IN;

/** \brief Analog Input for FCC3
 */
IFX_EXTERN IfxAdc_Fcc_In       IfxAdc_Fcc_FCC3_P00_11_IN;

/** \brief Analog Input for FCC4
 */
IFX_EXTERN IfxAdc_Fcc_In       IfxAdc_Fcc_FCC4_P00_6_IN;

/** \brief Analog Input for FCC5
 */
IFX_EXTERN IfxAdc_Fcc_In       IfxAdc_Fcc_FCC5_P00_5_IN;

/** \brief Analog Input for FCC6
 */
IFX_EXTERN IfxAdc_Fcc_In       IfxAdc_Fcc_FCC6_P02_11_IN;

/** \brief Analog Input for FCC7
 */
IFX_EXTERN IfxAdc_Fcc_In       IfxAdc_Fcc_FCC7_P01_3_IN;

/** \brief Analog Input for FCC8
 */
IFX_EXTERN IfxAdc_Fcc_In       IfxAdc_Fcc_FCC8_P01_4_IN;

/** \brief Analog Input for FCC9
 */
IFX_EXTERN IfxAdc_Fcc_In       IfxAdc_Fcc_FCC9_P01_5_IN;

/** \brief Positive PWM
 */
IFX_EXTERN IfxAdc_Pwm_Out      IfxAdc_PWM0_P00_6_OUT;

/** \brief Positive PWM
 */
IFX_EXTERN IfxAdc_Pwm_Out      IfxAdc_PWM0_P02_1_OUT;

/** \brief Positive PWM
 */
IFX_EXTERN IfxAdc_Pwm_Out      IfxAdc_PWM0_P33_12_OUT;

/** \brief Negative PWM
 */
IFX_EXTERN IfxAdc_Pwm_Out      IfxAdc_PWM1_P00_5_OUT;

/** \brief Negative PWM
 */
IFX_EXTERN IfxAdc_Pwm_Out      IfxAdc_PWM1_P02_0_OUT;

/** \brief Negative PWM
 */
IFX_EXTERN IfxAdc_Pwm_Out      IfxAdc_PWM1_P33_11_OUT;

/** \brief Sign for Carrier Cancellation
 */
IFX_EXTERN IfxAdc_Sign_In      IfxAdc_SIGN0_P32_7_IN;

/** \brief Sign for Carrier Cancellation
 */
IFX_EXTERN IfxAdc_Sign_In      IfxAdc_SIGN1_P33_13_IN;

/** \brief Triggers to ADC
 */
IFX_EXTERN IfxAdc_Trig_In      IfxAdc_TRIG54_P02_0_IN;

/** \brief Triggers to ADC
 */
IFX_EXTERN IfxAdc_Trig_In      IfxAdc_TRIG55_P02_1_IN;

/** \brief Triggers to ADC
 */
IFX_EXTERN IfxAdc_Trig_In      IfxAdc_TRIG56_P02_7_IN;

/** \brief Triggers to ADC
 */
IFX_EXTERN IfxAdc_Trig_In      IfxAdc_TRIG57_P02_8_IN;

/** \brief Triggers to ADC
 */
IFX_EXTERN IfxAdc_Trig_In      IfxAdc_TRIG58_P33_7_IN;

/** \brief Triggers to ADC
 */
IFX_EXTERN IfxAdc_Trig_In      IfxAdc_TRIG59_P23_1_IN;

/** \brief Triggers to ADC
 */
IFX_EXTERN IfxAdc_Trig_In      IfxAdc_TRIG60_P20_9_IN;

/** \brief Triggers to ADC
 */
IFX_EXTERN IfxAdc_Trig_In      IfxAdc_TRIG61_P15_1_IN;

/** \brief Analog Input for TMADC0 Channel 0
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH0_AN0_IN;

/** \brief Analog Input for TMADC0 Channel 10
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH10_AN10_IN;

/** \brief Analog Input for TMADC0 Channel 11
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH11_AN11_IN;

/** \brief Analog Input for TMADC0 Channel 12
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH12_AN12_IN;

/** \brief Analog Input for TMADC0 Channel 13
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH13_AN13_IN;

/** \brief Analog Input for TMADC0 Channel 14
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH14_AN14_IN;

/** \brief Analog Input for TMADC0 Channel 15
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH15_AN15_IN;

/** \brief Analog Input for TMADC0 Channel 1
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH1_AN1_IN;

/** \brief Analog Input for TMADC0 Channel 2
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH2_AN2_IN;

/** \brief Analog Input for TMADC0 Channel 3
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH3_AN3_IN;

/** \brief Analog Input for TMADC0 Channel 4
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH4_AN4_IN;

/** \brief Analog Input for TMADC0 Channel 5
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH5_AN5_IN;

/** \brief Analog Input for TMADC0 Channel 6
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH6_AN6_IN;

/** \brief Analog Input for TMADC0 Channel 7
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH7_AN7_IN;

/** \brief Analog Input for TMADC0 Channel 8
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH8_AN8_IN;

/** \brief Analog Input for TMADC0 Channel 9
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH9_AN9_IN;

/** \brief Analog Input for TMADC1 Channel 0
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH0_AN4_IN;

/** \brief Analog Input for TMADC1 Channel 10
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH10_AN22_IN;

/** \brief Analog Input for TMADC1 Channel 11
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH11_AN23_IN;

/** \brief Analog Input for TMADC1 Channel 12
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH12_P40_0_IN;

/** \brief Analog Input for TMADC1 Channel 13
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH13_P40_1_IN;

/** \brief Analog Input for TMADC1 Channel 14
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH14_P40_2_IN;

/** \brief Analog Input for TMADC1 Channel 15
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH15_P40_3_IN;

/** \brief Analog Input for TMADC1 Channel 1
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH1_AN5_IN;

/** \brief Analog Input for TMADC1 Channel 2
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH2_AN6_IN;

/** \brief Analog Input for TMADC1 Channel 3
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH3_AN7_IN;

/** \brief Analog Input for TMADC1 Channel 4
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH4_AN16_IN;

/** \brief Analog Input for TMADC1 Channel 5
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH5_P40_10_IN;

/** \brief Analog Input for TMADC1 Channel 6
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH6_P40_11_IN;

/** \brief Analog Input for TMADC1 Channel 7
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH7_P40_12_IN;

/** \brief Analog Input for TMADC1 Channel 8
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH8_AN20_IN;

/** \brief Analog Input for TMADC1 Channel 9
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH9_AN21_IN;

/** \brief Analog Input for TMADC2 Channel 0
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH0_P00_12_IN;

/** \brief Analog Input for TMADC2 Channel 10
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH10_P00_2_IN;

/** \brief Analog Input for TMADC2 Channel 11
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH11_P00_1_IN;

/** \brief Analog Input for TMADC2 Channel 12
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH12_P01_5_IN;

/** \brief Analog Input for TMADC2 Channel 13
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH13_P01_4_IN;

/** \brief Analog Input for TMADC2 Channel 14
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH14_P01_3_IN;

/** \brief Analog Input for TMADC2 Channel 15
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH15_P02_11_IN;

/** \brief Analog Input for TMADC2 Channel 1
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH1_P00_11_IN;

/** \brief Analog Input for TMADC2 Channel 2
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH2_P00_10_IN;

/** \brief Analog Input for TMADC2 Channel 3
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH3_P00_9_IN;

/** \brief Analog Input for TMADC2 Channel 4
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH4_P00_8_IN;

/** \brief Analog Input for TMADC2 Channel 5
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH5_P00_7_IN;

/** \brief Analog Input for TMADC2 Channel 6
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH6_P00_6_IN;

/** \brief Analog Input for TMADC2 Channel 7
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH7_P00_5_IN;

/** \brief Analog Input for TMADC2 Channel 8
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH8_P00_4_IN;

/** \brief Analog Input for TMADC2 Channel 9
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH9_P00_3_IN;

/** \brief Analog Input for TMADC3 Channel 0
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH0_P40_13_IN;

/** \brief Analog Input for TMADC3 Channel 10
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH10_P40_8_IN;

/** \brief Analog Input for TMADC3 Channel 11
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH11_P40_9_IN;

/** \brief Analog Input for TMADC3 Channel 12
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH12_AN40_IN;

/** \brief Analog Input for TMADC3 Channel 13
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH13_AN41_IN;

/** \brief Analog Input for TMADC3 Channel 14
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH14_AN42_IN;

/** \brief Analog Input for TMADC3 Channel 15
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH15_AN43_IN;

/** \brief Analog Input for TMADC3 Channel 1
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH1_P40_14_IN;

/** \brief Analog Input for TMADC3 Channel 2
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH2_AN30_IN;

/** \brief Analog Input for TMADC3 Channel 3
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH3_AN31_IN;

/** \brief Analog Input for TMADC3 Channel 4
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH4_P40_4_IN;

/** \brief Analog Input for TMADC3 Channel 5
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH5_P40_5_IN;

/** \brief Analog Input for TMADC3 Channel 6
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH6_AN34_IN;

/** \brief Analog Input for TMADC3 Channel 7
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH7_AN35_IN;

/** \brief Analog Input for TMADC3 Channel 8
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH8_P40_6_IN;

/** \brief Analog Input for TMADC3 Channel 9
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH9_P40_7_IN;

/** \brief Analog Input for TMADC4 Channel 0
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH0_P31_2_IN;

/** \brief Analog Input for TMADC4 Channel 10
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH10_P33_0_IN;

/** \brief Analog Input for TMADC4 Channel 11
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH11_P34_5_IN;

/** \brief Analog Input for TMADC4 Channel 12
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH12_P34_4_IN;

/** \brief Analog Input for TMADC4 Channel 13
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH13_P34_3_IN;

/** \brief Analog Input for TMADC4 Channel 14
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH14_P34_2_IN;

/** \brief Analog Input for TMADC4 Channel 15
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH15_P34_1_IN;

/** \brief Analog Input for TMADC4 Channel 1
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH1_P31_1_IN;

/** \brief Analog Input for TMADC4 Channel 2
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH2_P31_0_IN;

/** \brief Analog Input for TMADC4 Channel 3
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH3_P33_7_IN;

/** \brief Analog Input for TMADC4 Channel 4
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH4_P33_6_IN;

/** \brief Analog Input for TMADC4 Channel 5
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH5_P33_5_IN;

/** \brief Analog Input for TMADC4 Channel 6
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH6_P33_4_IN;

/** \brief Analog Input for TMADC4 Channel 7
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH7_P33_3_IN;

/** \brief Analog Input for TMADC4 Channel 8
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH8_P33_2_IN;

/** \brief Analog Input for TMADC4 Channel 9
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH9_P33_1_IN;

/** \brief Analog Input for TMADC5 Channel 0
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC5CH0_AN8_IN;

/** \brief Analog Input for TMADC5 Channel 10
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC5CH10_P40_13_IN;

/** \brief Analog Input for TMADC5 Channel 11
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC5CH11_P40_14_IN;

/** \brief Analog Input for TMADC5 Channel 12
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC5CH12_AN30_IN;

/** \brief Analog Input for TMADC5 Channel 13
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC5CH13_AN31_IN;

/** \brief Analog Input for TMADC5 Channel 14
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC5CH14_P40_4_IN;

/** \brief Analog Input for TMADC5 Channel 15
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC5CH15_P40_5_IN;

/** \brief Analog Input for TMADC5 Channel 1
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC5CH1_AN9_IN;

/** \brief Analog Input for TMADC5 Channel 2
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC5CH2_AN10_IN;

/** \brief Analog Input for TMADC5 Channel 3
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC5CH3_AN11_IN;

/** \brief Analog Input for TMADC5 Channel 4
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC5CH4_P40_11_IN;

/** \brief Analog Input for TMADC5 Channel 5
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC5CH5_P40_12_IN;

/** \brief Analog Input for TMADC5 Channel 6
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC5CH6_AN22_IN;

/** \brief Analog Input for TMADC5 Channel 7
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC5CH7_AN23_IN;

/** \brief Analog Input for TMADC5 Channel 8
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC5CH8_P40_2_IN;

/** \brief Analog Input for TMADC5 Channel 9
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC5CH9_P40_3_IN;

/** \brief Analog Input for TMADC6 Channel 0
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC6CH0_AN40_IN;

/** \brief Analog Input for TMADC6 Channel 10
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC6CH10_AN50_IN;

/** \brief Analog Input for TMADC6 Channel 11
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC6CH11_AN51_IN;

/** \brief Analog Input for TMADC6 Channel 12
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC6CH12_AN52_IN;

/** \brief Analog Input for TMADC6 Channel 13
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC6CH13_AN53_IN;

/** \brief Analog Input for TMADC6 Channel 14
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC6CH14_P41_5_IN;

/** \brief Analog Input for TMADC6 Channel 15
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC6CH15_P41_6_IN;

/** \brief Analog Input for TMADC6 Channel 1
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC6CH1_AN41_IN;

/** \brief Analog Input for TMADC6 Channel 2
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC6CH2_AN42_IN;

/** \brief Analog Input for TMADC6 Channel 3
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC6CH3_AN43_IN;

/** \brief Analog Input for TMADC6 Channel 4
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC6CH4_AN44_IN;

/** \brief Analog Input for TMADC6 Channel 5
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC6CH5_AN45_IN;

/** \brief Analog Input for TMADC6 Channel 6
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC6CH6_AN46_IN;

/** \brief Analog Input for TMADC6 Channel 7
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC6CH7_AN47_IN;

/** \brief Analog Input for TMADC6 Channel 8
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC6CH8_AN48_IN;

/** \brief Analog Input for TMADC6 Channel
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC6CH9_AN49_IN;

/** \brief Analog Input for TMADC7 Channel 0
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC7CH0_AN56_IN;

/** \brief Analog Input for TMADC7 Channel 10
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC7CH10_AN66_IN;

/** \brief Analog Input for TMADC7 Channel 11
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC7CH11_P41_0_IN;

/** \brief Analog Input for TMADC7 Channel 12
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC7CH12_P41_1_IN;

/** \brief Analog Input for TMADC7 Channel 13
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC7CH13_P41_2_IN;

/** \brief Analog Input for TMADC7 Channel 14
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC7CH14_P41_3_IN;

/** \brief Analog Input for TMADC7 Channel 15
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC7CH15_P41_4_IN;

/** \brief Analog Input for TMADC7 Channel 1
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC7CH1_AN57_IN;

/** \brief Analog Input for TMADC7 Channel 2
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC7CH2_AN58_IN;

/** \brief Analog Input for TMADC7 Channel 3
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC7CH3_AN59_IN;

/** \brief Analog Input for TMADC7 Channel 4
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC7CH4_AN60_IN;

/** \brief Analog Input for TMADC7 Channel 5
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC7CH5_AN61_IN;

/** \brief Analog Input for TMADC7 Channel 6
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC7CH6_P41_7_IN;

/** \brief Analog Input for TMADC7 Channel 7
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC7CH7_P41_8_IN;

/** \brief Analog Input for TMADC7 Channel 8
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC7CH8_AN64_IN;

/** \brief Analog Input for TMADC7 Channel 9
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC7CH9_AN65_IN;

/** \addtogroup IfxLld_Adc__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxAdc_Bfl_Out Table
 */
IFX_EXTERN IFX_CONST IfxAdc_Bfl_Out      *IfxAdc_Bfl_Out_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_BFL_OUT_NUM_ITEMS];

/** \brief IfxAdc_Clkin_In Table
 */
IFX_EXTERN IFX_CONST IfxAdc_Clkin_In     *IfxAdc_Clkin_In_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_CLKIN_IN_NUM_ITEMS];

/** \brief IfxAdc_Clkout_Out Table
 */
IFX_EXTERN IFX_CONST IfxAdc_Clkout_Out   *IfxAdc_Clkout_Out_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_CLKOUT_OUT_NUM_ITEMS];

/** \brief IfxAdc_Data_In Table
 */
IFX_EXTERN IFX_CONST IfxAdc_Data_In      *IfxAdc_Data_In_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_DATA_IN_NUM_ITEMS];

/** \brief IfxAdc_Dsadcn_In Table
 */
IFX_EXTERN IFX_CONST IfxAdc_Dsadcn_In    *IfxAdc_Dsadcn_In_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_DSADCN_IN_NUM_ITEMS];

/** \brief IfxAdc_Dsadcp_In Table
 */
IFX_EXTERN IFX_CONST IfxAdc_Dsadcp_In    *IfxAdc_Dsadcp_In_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_DSADCP_IN_NUM_ITEMS];

/** \brief IfxAdc_Emuxctrl_Out Table
 */
IFX_EXTERN IFX_CONST IfxAdc_Emuxctrl_Out *IfxAdc_Emuxctrl_Out_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_EMUXCTRL_OUT_NUM_ITEMS];

/** \brief IfxAdc_Fcc_In Table
 */
IFX_EXTERN IFX_CONST IfxAdc_Fcc_In       *IfxAdc_Fcc_In_pinTable[IFXADC_FCC_PINMAP_NUM_MODULES][IFXADC_PINMAP_FCC_IN_NUM_ITEMS];

/** \brief IfxAdc_Pwm_Out Table
 */
IFX_EXTERN IFX_CONST IfxAdc_Pwm_Out      *IfxAdc_Pwm_Out_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_PWM_OUT_NUM_ITEMS];

/** \brief IfxAdc_Sign_In Table
 */
IFX_EXTERN IFX_CONST IfxAdc_Sign_In      *IfxAdc_Sign_In_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_SIGN_IN_NUM_ITEMS];

/** \brief IfxAdc_TmadcCh_In Table
 */
IFX_EXTERN IFX_CONST IfxAdc_TmadcCh_In   *IfxAdc_TmadcCh_In_pinTable[IFXADC_TMADC_PINMAP_NUM_MODULES][IFXADC_TMADC_PINMAP_NUM_CHANNELS][IFXADC_PINMAP_TMADCCH_IN_NUM_ITEMS];

/** \brief IfxAdc_Trig_In Table
 */
IFX_EXTERN IFX_CONST IfxAdc_Trig_In      *IfxAdc_Trig_In_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_TRIG_IN_NUM_ITEMS];

/** \} */

#endif /* IFXADC_PINMAP_LFBGA436_COM_H */
