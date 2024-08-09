/**
 * \file IfxPpucCore.c
 * \brief PPUC  basic functionality
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

#include "IfxPpucCore.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxPpucCore_configureCoreAndRun(Ifx_PPUC *ppuc, uint32 intVectAddress)
{
    ppuc->CLC.U = 0U;

    IfxPpucCore_configureInterruptVectorBaseAddress(ppuc, intVectAddress);

    /* Trigger a Kernel reset once you configure the ivt base address */
    ppuc->RST.CTRLA.U = 0x1;
    ppuc->RST.CTRLB.U = 0x1;

    /* Wait until the reset status is updated */
    while (ppuc->RST.STAT.B.KRST != 2U)
    {}

    /* Clear the RST STATUS */
    ppuc->RST.CTRLB.B.STATCLR = 1U;

    /* Write into CTRL register to bring PPUC out of halt
     * Enable the PPUC-ICU interface
     * Enable the CBU interface
     * Enable the LBU interface
     * Enable the STU interface
     * Enable the STU-DMI interface
     * Enable the CSM-DMI interface
     * */
    ppuc->CTRL.U = 0x1f09U;
}


void IfxPpucCore_configureAccessToPpuc(IfxApApu_ApuConfig *apConfig)
{
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_PPUC.SFR.ACCEN, apConfig);
}
