/**
 * \file IfxSent_PinMap_LFBGA292_EMS.c
 * \brief SENT  details
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
#ifdef IFX_PIN_PACKAGE_LFBGA292_EMS
#include "IfxSent_PinMap_LFBGA292_EMS.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IfxSent_Sent_In IfxSent_SENT0A_P40_0_IN = {&MODULE_SENT0, (IfxSent_ChannelId)0, {&MODULE_P40, 0}, Ifx_RxSel_a};

IfxSent_Sent_In IfxSent_SENT0B_P00_1_IN = {&MODULE_SENT0, (IfxSent_ChannelId)0, {&MODULE_P00, 1}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT0B_P33_4_IN = {&MODULE_SENT1, (IfxSent_ChannelId)0, {&MODULE_P33, 4}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT0C_P02_8_IN = {&MODULE_SENT0, (IfxSent_ChannelId)0, {&MODULE_P02, 8}, Ifx_RxSel_c};

IfxSent_Sent_In IfxSent_SENT0D_P21_4_IN = {&MODULE_SENT0, (IfxSent_ChannelId)0, {&MODULE_P21, 4}, Ifx_RxSel_d};

IfxSent_Sent_In IfxSent_SENT10A_P01_3_IN = {&MODULE_SENT1, (IfxSent_ChannelId)10, {&MODULE_P01, 3}, Ifx_RxSel_a};

IfxSent_Sent_In IfxSent_SENT10A_P40_10_IN = {&MODULE_SENT0, (IfxSent_ChannelId)10, {&MODULE_P40, 10}, Ifx_RxSel_a};

IfxSent_Sent_In IfxSent_SENT10B_P00_11_IN = {&MODULE_SENT0, (IfxSent_ChannelId)10, {&MODULE_P00, 11}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT10B_P10_6_IN = {&MODULE_SENT1, (IfxSent_ChannelId)10, {&MODULE_P10, 6}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT10C_P32_5_IN = {&MODULE_SENT0, (IfxSent_ChannelId)10, {&MODULE_P32, 5}, Ifx_RxSel_c};

IfxSent_Sent_In IfxSent_SENT10D_P15_2_IN = {&MODULE_SENT0, (IfxSent_ChannelId)10, {&MODULE_P15, 2}, Ifx_RxSel_d};

IfxSent_Sent_In IfxSent_SENT11A_P01_4_IN = {&MODULE_SENT1, (IfxSent_ChannelId)11, {&MODULE_P01, 4}, Ifx_RxSel_a};

IfxSent_Sent_In IfxSent_SENT11A_P40_11_IN = {&MODULE_SENT0, (IfxSent_ChannelId)11, {&MODULE_P40, 11}, Ifx_RxSel_a};

IfxSent_Sent_In IfxSent_SENT11B_P00_12_IN = {&MODULE_SENT0, (IfxSent_ChannelId)11, {&MODULE_P00, 12}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT11B_P10_0_IN = {&MODULE_SENT1, (IfxSent_ChannelId)11, {&MODULE_P10, 0}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT11C_P32_6_IN = {&MODULE_SENT0, (IfxSent_ChannelId)11, {&MODULE_P32, 6}, Ifx_RxSel_c};

IfxSent_Sent_In IfxSent_SENT11D_P15_4_IN = {&MODULE_SENT0, (IfxSent_ChannelId)11, {&MODULE_P15, 4}, Ifx_RxSel_d};

IfxSent_Sent_In IfxSent_SENT12A_P01_5_IN = {&MODULE_SENT1, (IfxSent_ChannelId)12, {&MODULE_P01, 5}, Ifx_RxSel_a};

IfxSent_Sent_In IfxSent_SENT12A_P40_12_IN = {&MODULE_SENT0, (IfxSent_ChannelId)12, {&MODULE_P40, 12}, Ifx_RxSel_a};

IfxSent_Sent_In IfxSent_SENT12B_P02_4_IN = {&MODULE_SENT0, (IfxSent_ChannelId)12, {&MODULE_P02, 4}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT12B_P34_4_IN = {&MODULE_SENT1, (IfxSent_ChannelId)12, {&MODULE_P34, 4}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT12C_P32_7_IN = {&MODULE_SENT0, (IfxSent_ChannelId)12, {&MODULE_P32, 7}, Ifx_RxSel_c};

IfxSent_Sent_In IfxSent_SENT13A_P02_1_IN = {&MODULE_SENT1, (IfxSent_ChannelId)13, {&MODULE_P02, 1}, Ifx_RxSel_a};

IfxSent_Sent_In IfxSent_SENT13A_P40_13_IN = {&MODULE_SENT0, (IfxSent_ChannelId)13, {&MODULE_P40, 13}, Ifx_RxSel_a};

IfxSent_Sent_In IfxSent_SENT13B_P02_3_IN = {&MODULE_SENT0, (IfxSent_ChannelId)13, {&MODULE_P02, 3}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT13B_P34_2_IN = {&MODULE_SENT1, (IfxSent_ChannelId)13, {&MODULE_P34, 2}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT14A_P10_8_IN = {&MODULE_SENT1, (IfxSent_ChannelId)14, {&MODULE_P10, 8}, Ifx_RxSel_a};

IfxSent_Sent_In IfxSent_SENT14A_P40_14_IN = {&MODULE_SENT0, (IfxSent_ChannelId)14, {&MODULE_P40, 14}, Ifx_RxSel_a};

IfxSent_Sent_In IfxSent_SENT14B_P02_2_IN = {&MODULE_SENT0, (IfxSent_ChannelId)14, {&MODULE_P02, 2}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT14B_P34_3_IN = {&MODULE_SENT1, (IfxSent_ChannelId)14, {&MODULE_P34, 3}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT1A_P40_1_IN = {&MODULE_SENT0, (IfxSent_ChannelId)1, {&MODULE_P40, 1}, Ifx_RxSel_a};

IfxSent_Sent_In IfxSent_SENT1B_P00_2_IN = {&MODULE_SENT0, (IfxSent_ChannelId)1, {&MODULE_P00, 2}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT1B_P33_3_IN = {&MODULE_SENT1, (IfxSent_ChannelId)1, {&MODULE_P33, 3}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT1C_P02_7_IN = {&MODULE_SENT0, (IfxSent_ChannelId)1, {&MODULE_P02, 7}, Ifx_RxSel_c};

IfxSent_Sent_In IfxSent_SENT1D_P20_7_IN = {&MODULE_SENT0, (IfxSent_ChannelId)1, {&MODULE_P20, 7}, Ifx_RxSel_d};

IfxSent_Sent_In IfxSent_SENT2A_P40_2_IN = {&MODULE_SENT0, (IfxSent_ChannelId)2, {&MODULE_P40, 2}, Ifx_RxSel_a};

IfxSent_Sent_In IfxSent_SENT2B_P00_3_IN = {&MODULE_SENT0, (IfxSent_ChannelId)2, {&MODULE_P00, 3}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT2B_P33_2_IN = {&MODULE_SENT1, (IfxSent_ChannelId)2, {&MODULE_P33, 2}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT2C_P02_6_IN = {&MODULE_SENT0, (IfxSent_ChannelId)2, {&MODULE_P02, 6}, Ifx_RxSel_c};

IfxSent_Sent_In IfxSent_SENT2D_P14_0_IN = {&MODULE_SENT1, (IfxSent_ChannelId)2, {&MODULE_P14, 0}, Ifx_RxSel_d};

IfxSent_Sent_In IfxSent_SENT2D_P21_5_IN = {&MODULE_SENT0, (IfxSent_ChannelId)2, {&MODULE_P21, 5}, Ifx_RxSel_d};

IfxSent_Sent_In IfxSent_SENT3A_P40_3_IN = {&MODULE_SENT0, (IfxSent_ChannelId)3, {&MODULE_P40, 3}, Ifx_RxSel_a};

IfxSent_Sent_In IfxSent_SENT3B_P00_4_IN = {&MODULE_SENT0, (IfxSent_ChannelId)3, {&MODULE_P00, 4}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT3B_P33_1_IN = {&MODULE_SENT1, (IfxSent_ChannelId)3, {&MODULE_P33, 1}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT3C_P02_5_IN = {&MODULE_SENT0, (IfxSent_ChannelId)3, {&MODULE_P02, 5}, Ifx_RxSel_c};

IfxSent_Sent_In IfxSent_SENT3D_P14_1_IN = {&MODULE_SENT1, (IfxSent_ChannelId)3, {&MODULE_P14, 1}, Ifx_RxSel_d};

IfxSent_Sent_In IfxSent_SENT3D_P20_0_IN = {&MODULE_SENT0, (IfxSent_ChannelId)3, {&MODULE_P20, 0}, Ifx_RxSel_d};

IfxSent_Sent_In IfxSent_SENT4A_P40_4_IN = {&MODULE_SENT0, (IfxSent_ChannelId)4, {&MODULE_P40, 4}, Ifx_RxSel_a};

IfxSent_Sent_In IfxSent_SENT4B_P00_5_IN = {&MODULE_SENT0, (IfxSent_ChannelId)4, {&MODULE_P00, 5}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT4B_P33_0_IN = {&MODULE_SENT1, (IfxSent_ChannelId)4, {&MODULE_P33, 0}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT4D_P21_2_IN = {&MODULE_SENT0, (IfxSent_ChannelId)4, {&MODULE_P21, 2}, Ifx_RxSel_d};

IfxSent_Sent_In IfxSent_SENT5A_P40_5_IN = {&MODULE_SENT0, (IfxSent_ChannelId)5, {&MODULE_P40, 5}, Ifx_RxSel_a};

IfxSent_Sent_In IfxSent_SENT5B_P00_6_IN = {&MODULE_SENT0, (IfxSent_ChannelId)5, {&MODULE_P00, 6}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT5B_P02_9_IN = {&MODULE_SENT1, (IfxSent_ChannelId)5, {&MODULE_P02, 9}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT5C_P33_5_IN = {&MODULE_SENT0, (IfxSent_ChannelId)5, {&MODULE_P33, 5}, Ifx_RxSel_c};

IfxSent_Sent_In IfxSent_SENT5D_P21_3_IN = {&MODULE_SENT0, (IfxSent_ChannelId)5, {&MODULE_P21, 3}, Ifx_RxSel_d};

IfxSent_Sent_In IfxSent_SENT6A_P40_6_IN = {&MODULE_SENT0, (IfxSent_ChannelId)6, {&MODULE_P40, 6}, Ifx_RxSel_a};

IfxSent_Sent_In IfxSent_SENT6B_P00_7_IN = {&MODULE_SENT0, (IfxSent_ChannelId)6, {&MODULE_P00, 7}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT6B_P02_10_IN = {&MODULE_SENT1, (IfxSent_ChannelId)6, {&MODULE_P02, 10}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT6D_P20_3_IN = {&MODULE_SENT0, (IfxSent_ChannelId)6, {&MODULE_P20, 3}, Ifx_RxSel_d};

IfxSent_Sent_In IfxSent_SENT7A_P40_7_IN = {&MODULE_SENT0, (IfxSent_ChannelId)7, {&MODULE_P40, 7}, Ifx_RxSel_a};

IfxSent_Sent_In IfxSent_SENT7B_P00_8_IN = {&MODULE_SENT0, (IfxSent_ChannelId)7, {&MODULE_P00, 8}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT7B_P02_11_IN = {&MODULE_SENT1, (IfxSent_ChannelId)7, {&MODULE_P02, 11}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT7D_P20_6_IN = {&MODULE_SENT0, (IfxSent_ChannelId)7, {&MODULE_P20, 6}, Ifx_RxSel_d};

IfxSent_Sent_In IfxSent_SENT8A_P40_8_IN = {&MODULE_SENT0, (IfxSent_ChannelId)8, {&MODULE_P40, 8}, Ifx_RxSel_a};

IfxSent_Sent_In IfxSent_SENT8B_P00_9_IN = {&MODULE_SENT0, (IfxSent_ChannelId)8, {&MODULE_P00, 9}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT8B_P33_7_IN = {&MODULE_SENT1, (IfxSent_ChannelId)8, {&MODULE_P33, 7}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT9A_P40_9_IN = {&MODULE_SENT0, (IfxSent_ChannelId)9, {&MODULE_P40, 9}, Ifx_RxSel_a};

IfxSent_Sent_In IfxSent_SENT9B_P00_10_IN = {&MODULE_SENT0, (IfxSent_ChannelId)9, {&MODULE_P00, 10}, Ifx_RxSel_b};

IfxSent_Sent_In IfxSent_SENT9B_P33_6_IN = {&MODULE_SENT1, (IfxSent_ChannelId)9, {&MODULE_P33, 6}, Ifx_RxSel_b};

IfxSent_Spc_Out IfxSent_SPC0_P00_1_OUT = {&MODULE_SENT0, (IfxSent_ChannelId)0, {&MODULE_P00, 1}, IfxPort_OutputIdx_alt6};

IfxSent_Spc_Out IfxSent_SPC0_P21_4_OUT = {&MODULE_SENT0, (IfxSent_ChannelId)0, {&MODULE_P21, 4}, IfxPort_OutputIdx_alt4};

IfxSent_Spc_Out IfxSent_SPC0_P33_4_OUT = {&MODULE_SENT1, (IfxSent_ChannelId)0, {&MODULE_P33, 4}, IfxPort_OutputIdx_alt8};

IfxSent_Spc_Out IfxSent_SPC1_P02_7_OUT = {&MODULE_SENT0, (IfxSent_ChannelId)1, {&MODULE_P02, 7}, IfxPort_OutputIdx_alt6};

IfxSent_Spc_Out IfxSent_SPC1_P20_7_OUT = {&MODULE_SENT0, (IfxSent_ChannelId)1, {&MODULE_P20, 7}, IfxPort_OutputIdx_alt6};

IfxSent_Spc_Out IfxSent_SPC1_P33_3_OUT = {&MODULE_SENT1, (IfxSent_ChannelId)1, {&MODULE_P33, 3}, IfxPort_OutputIdx_alt8};

IfxSent_Spc_Out IfxSent_SPC2_P00_3_OUT = {&MODULE_SENT0, (IfxSent_ChannelId)2, {&MODULE_P00, 3}, IfxPort_OutputIdx_alt6};

IfxSent_Spc_Out IfxSent_SPC2_P21_5_OUT = {&MODULE_SENT0, (IfxSent_ChannelId)2, {&MODULE_P21, 5}, IfxPort_OutputIdx_alt4};

IfxSent_Spc_Out IfxSent_SPC2_P33_2_OUT = {&MODULE_SENT1, (IfxSent_ChannelId)2, {&MODULE_P33, 2}, IfxPort_OutputIdx_alt8};

IfxSent_Spc_Out IfxSent_SPC3_P00_4_OUT = {&MODULE_SENT0, (IfxSent_ChannelId)3, {&MODULE_P00, 4}, IfxPort_OutputIdx_alt6};

IfxSent_Spc_Out IfxSent_SPC3_P20_0_OUT = {&MODULE_SENT0, (IfxSent_ChannelId)3, {&MODULE_P20, 0}, IfxPort_OutputIdx_alt4};

IfxSent_Spc_Out IfxSent_SPC3_P33_1_OUT = {&MODULE_SENT1, (IfxSent_ChannelId)3, {&MODULE_P33, 1}, IfxPort_OutputIdx_alt7};

IfxSent_Spc_Out IfxSent_SPC4_P00_5_OUT = {&MODULE_SENT0, (IfxSent_ChannelId)4, {&MODULE_P00, 5}, IfxPort_OutputIdx_alt6};

IfxSent_Spc_Out IfxSent_SPC4_P21_2_OUT = {&MODULE_SENT0, (IfxSent_ChannelId)4, {&MODULE_P21, 2}, IfxPort_OutputIdx_alt4};

IfxSent_Spc_Out IfxSent_SPC4_P33_0_OUT = {&MODULE_SENT1, (IfxSent_ChannelId)4, {&MODULE_P33, 0}, IfxPort_OutputIdx_alt3};

IfxSent_Spc_Out IfxSent_SPC5_P00_6_OUT = {&MODULE_SENT0, (IfxSent_ChannelId)5, {&MODULE_P00, 6}, IfxPort_OutputIdx_alt6};

IfxSent_Spc_Out IfxSent_SPC5_P02_9_OUT = {&MODULE_SENT1, (IfxSent_ChannelId)5, {&MODULE_P02, 9}, IfxPort_OutputIdx_alt6};

IfxSent_Spc_Out IfxSent_SPC5_P21_3_OUT = {&MODULE_SENT0, (IfxSent_ChannelId)5, {&MODULE_P21, 3}, IfxPort_OutputIdx_alt4};

IfxSent_Spc_Out IfxSent_SPC6_P00_7_OUT = {&MODULE_SENT0, (IfxSent_ChannelId)6, {&MODULE_P00, 7}, IfxPort_OutputIdx_alt6};

IfxSent_Spc_Out IfxSent_SPC6_P02_10_OUT = {&MODULE_SENT1, (IfxSent_ChannelId)6, {&MODULE_P02, 10}, IfxPort_OutputIdx_alt6};

IfxSent_Spc_Out IfxSent_SPC6_P20_3_OUT = {&MODULE_SENT0, (IfxSent_ChannelId)6, {&MODULE_P20, 3}, IfxPort_OutputIdx_alt8};

IfxSent_Spc_Out IfxSent_SPC7_P00_8_OUT = {&MODULE_SENT0, (IfxSent_ChannelId)7, {&MODULE_P00, 8}, IfxPort_OutputIdx_alt6};

IfxSent_Spc_Out IfxSent_SPC7_P02_11_OUT = {&MODULE_SENT1, (IfxSent_ChannelId)7, {&MODULE_P02, 11}, IfxPort_OutputIdx_alt6};

IfxSent_Spc_Out IfxSent_SPC7_P20_6_OUT = {&MODULE_SENT0, (IfxSent_ChannelId)7, {&MODULE_P20, 6}, IfxPort_OutputIdx_alt6};

IfxSent_Spc_Out IfxSent_SPC8_P00_9_OUT = {&MODULE_SENT0, (IfxSent_ChannelId)8, {&MODULE_P00, 9}, IfxPort_OutputIdx_alt6};

IfxSent_Spc_Out IfxSent_SPC8_P33_7_OUT = {&MODULE_SENT1, (IfxSent_ChannelId)8, {&MODULE_P33, 7}, IfxPort_OutputIdx_alt8};

IfxSent_Spc_Out IfxSent_SPC9_P00_10_OUT = {&MODULE_SENT0, (IfxSent_ChannelId)9, {&MODULE_P00, 10}, IfxPort_OutputIdx_alt6};

IfxSent_Spc_Out IfxSent_SPC9_P33_6_OUT = {&MODULE_SENT1, (IfxSent_ChannelId)9, {&MODULE_P33, 6}, IfxPort_OutputIdx_alt8};

/** \addtogroup IfxLld_Sent__PinTables
 * \{ */

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxSent_Sent_In *IfxSent_Sent_In_pinTable[IFXSENT_PINMAP_NUM_MODULES][IFXSENT_PINMAP_NUM_CHANNELS][IFXSENT_PINMAP_SENT_IN_NUM_ITEMS] = {
    {
        {
            &IfxSent_SENT0A_P40_0_IN,
            &IfxSent_SENT0B_P00_1_IN,
            &IfxSent_SENT0C_P02_8_IN,
            &IfxSent_SENT0D_P21_4_IN,
        },
        {
            &IfxSent_SENT1A_P40_1_IN,
            &IfxSent_SENT1B_P00_2_IN,
            &IfxSent_SENT1C_P02_7_IN,
            &IfxSent_SENT1D_P20_7_IN,
        },
        {
            &IfxSent_SENT2A_P40_2_IN,
            &IfxSent_SENT2B_P00_3_IN,
            &IfxSent_SENT2C_P02_6_IN,
            &IfxSent_SENT2D_P21_5_IN,
        },
        {
            &IfxSent_SENT3A_P40_3_IN,
            &IfxSent_SENT3B_P00_4_IN,
            &IfxSent_SENT3C_P02_5_IN,
            &IfxSent_SENT3D_P20_0_IN,
        },
        {
            &IfxSent_SENT4A_P40_4_IN,
            &IfxSent_SENT4B_P00_5_IN,
            NULL_PTR,
            &IfxSent_SENT4D_P21_2_IN,
        },
        {
            &IfxSent_SENT5A_P40_5_IN,
            &IfxSent_SENT5B_P00_6_IN,
            &IfxSent_SENT5C_P33_5_IN,
            &IfxSent_SENT5D_P21_3_IN,
        },
        {
            &IfxSent_SENT6A_P40_6_IN,
            &IfxSent_SENT6B_P00_7_IN,
            NULL_PTR,
            &IfxSent_SENT6D_P20_3_IN,
        },
        {
            &IfxSent_SENT7A_P40_7_IN,
            &IfxSent_SENT7B_P00_8_IN,
            NULL_PTR,
            &IfxSent_SENT7D_P20_6_IN,
        },
        {
            &IfxSent_SENT8A_P40_8_IN,
            &IfxSent_SENT8B_P00_9_IN,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxSent_SENT9A_P40_9_IN,
            &IfxSent_SENT9B_P00_10_IN,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxSent_SENT10A_P40_10_IN,
            &IfxSent_SENT10B_P00_11_IN,
            &IfxSent_SENT10C_P32_5_IN,
            &IfxSent_SENT10D_P15_2_IN,
        },
        {
            &IfxSent_SENT11A_P40_11_IN,
            &IfxSent_SENT11B_P00_12_IN,
            &IfxSent_SENT11C_P32_6_IN,
            &IfxSent_SENT11D_P15_4_IN,
        },
        {
            &IfxSent_SENT12A_P40_12_IN,
            &IfxSent_SENT12B_P02_4_IN,
            &IfxSent_SENT12C_P32_7_IN,
            NULL_PTR,
        },
        {
            &IfxSent_SENT13A_P40_13_IN,
            &IfxSent_SENT13B_P02_3_IN,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxSent_SENT14A_P40_14_IN,
            &IfxSent_SENT14B_P02_2_IN,
            NULL_PTR,
            NULL_PTR,
        },
    },
    {
        {
            NULL_PTR,
            &IfxSent_SENT0B_P33_4_IN,
            NULL_PTR,
            NULL_PTR,
        },
        {
            NULL_PTR,
            &IfxSent_SENT1B_P33_3_IN,
            NULL_PTR,
            NULL_PTR,
        },
        {
            NULL_PTR,
            &IfxSent_SENT2B_P33_2_IN,
            NULL_PTR,
            &IfxSent_SENT2D_P14_0_IN,
        },
        {
            NULL_PTR,
            &IfxSent_SENT3B_P33_1_IN,
            NULL_PTR,
            &IfxSent_SENT3D_P14_1_IN,
        },
        {
            NULL_PTR,
            &IfxSent_SENT4B_P33_0_IN,
            NULL_PTR,
            NULL_PTR,
        },
        {
            NULL_PTR,
            &IfxSent_SENT5B_P02_9_IN,
            NULL_PTR,
            NULL_PTR,
        },
        {
            NULL_PTR,
            &IfxSent_SENT6B_P02_10_IN,
            NULL_PTR,
            NULL_PTR,
        },
        {
            NULL_PTR,
            &IfxSent_SENT7B_P02_11_IN,
            NULL_PTR,
            NULL_PTR,
        },
        {
            NULL_PTR,
            &IfxSent_SENT8B_P33_7_IN,
            NULL_PTR,
            NULL_PTR,
        },
        {
            NULL_PTR,
            &IfxSent_SENT9B_P33_6_IN,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxSent_SENT10A_P01_3_IN,
            &IfxSent_SENT10B_P10_6_IN,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxSent_SENT11A_P01_4_IN,
            &IfxSent_SENT11B_P10_0_IN,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxSent_SENT12A_P01_5_IN,
            &IfxSent_SENT12B_P34_4_IN,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxSent_SENT13A_P02_1_IN,
            &IfxSent_SENT13B_P34_2_IN,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxSent_SENT14A_P10_8_IN,
            &IfxSent_SENT14B_P34_3_IN,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxSent_Spc_Out *IfxSent_Spc_Out_pinTable[IFXSENT_PINMAP_NUM_MODULES][IFXSENT_PINMAP_NUM_CHANNELS][IFXSENT_PINMAP_SPC_OUT_NUM_ITEMS] = {
    {
        {
            &IfxSent_SPC0_P00_1_OUT,
            &IfxSent_SPC0_P21_4_OUT,
        },
        {
            &IfxSent_SPC1_P02_7_OUT,
            &IfxSent_SPC1_P20_7_OUT,
        },
        {
            &IfxSent_SPC2_P00_3_OUT,
            &IfxSent_SPC2_P21_5_OUT,
        },
        {
            &IfxSent_SPC3_P00_4_OUT,
            &IfxSent_SPC3_P20_0_OUT,
        },
        {
            &IfxSent_SPC4_P00_5_OUT,
            &IfxSent_SPC4_P21_2_OUT,
        },
        {
            &IfxSent_SPC5_P00_6_OUT,
            &IfxSent_SPC5_P21_3_OUT,
        },
        {
            &IfxSent_SPC6_P00_7_OUT,
            &IfxSent_SPC6_P20_3_OUT,
        },
        {
            &IfxSent_SPC7_P00_8_OUT,
            &IfxSent_SPC7_P20_6_OUT,
        },
        {
            &IfxSent_SPC8_P00_9_OUT,
            NULL_PTR,
        },
        {
            &IfxSent_SPC9_P00_10_OUT,
            NULL_PTR,
        },
        {
            NULL_PTR,
            NULL_PTR,
        },
        {
            NULL_PTR,
            NULL_PTR,
        },
        {
            NULL_PTR,
            NULL_PTR,
        },
        {
            NULL_PTR,
            NULL_PTR,
        },
        {
            NULL_PTR,
            NULL_PTR,
        },
    },
    {
        {
            &IfxSent_SPC0_P33_4_OUT,
            NULL_PTR,
        },
        {
            &IfxSent_SPC1_P33_3_OUT,
            NULL_PTR,
        },
        {
            &IfxSent_SPC2_P33_2_OUT,
            NULL_PTR,
        },
        {
            &IfxSent_SPC3_P33_1_OUT,
            NULL_PTR,
        },
        {
            &IfxSent_SPC4_P33_0_OUT,
            NULL_PTR,
        },
        {
            &IfxSent_SPC5_P02_9_OUT,
            NULL_PTR,
        },
        {
            &IfxSent_SPC6_P02_10_OUT,
            NULL_PTR,
        },
        {
            &IfxSent_SPC7_P02_11_OUT,
            NULL_PTR,
        },
        {
            &IfxSent_SPC8_P33_7_OUT,
            NULL_PTR,
        },
        {
            &IfxSent_SPC9_P33_6_OUT,
            NULL_PTR,
        },
        {
            NULL_PTR,
            NULL_PTR,
        },
        {
            NULL_PTR,
            NULL_PTR,
        },
        {
            NULL_PTR,
            NULL_PTR,
        },
        {
            NULL_PTR,
            NULL_PTR,
        },
        {
            NULL_PTR,
            NULL_PTR,
        },
    },
};

/** \} */

#endif
