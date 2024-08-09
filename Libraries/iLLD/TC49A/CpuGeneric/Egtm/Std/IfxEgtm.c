/**
 * \file IfxEgtm.c
 * \brief EGTM  basic functionality
 *
 * \version iLLD_2_0_1_2_19
 * \copyright Copyright (c) 2023 Infineon Technologies AG. All rights reserved.
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

#include "IfxEgtm.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxEgtm_ConnectToMsc(IfxEgtm_Cluster egtmCluster, IfxEgtm_TrigSource egtmSource, IfxEgtm_TrigChannel Channel, IfxEgtm_MscOut *mscOut)
{
    boolean result     = FALSE;
    uint32  idx        = 0U;
    uint32  indexAltIn = 0U;

    /* 1. Check whether MSC Set is present in table */
    if (IfxEgtm_Cfg_MscSetTable[mscOut->mscSet] != NULL_PTR)
    {
        /* Get number of values in table from first index and loop through all entries */
        for (idx = 1u; idx <= IfxEgtm_Cfg_MscSetTable[mscOut->mscSet][0]; idx++)
        {
            if (IfxEgtm_Cfg_MscSetTable[mscOut->mscSet][idx] == IFXEGTM_CFG_GETTRIGENTRY(egtmCluster, egtmSource, Channel)) /* Check for valid combination */
            {
                result = TRUE;
                break;
            }
        }

        uint8 mscLevel2MuxIndex;
        mscLevel2MuxIndex = (uint8)mscOut->mscModule;

        /* 2. Check whether MSC module is present */
        if ((result == TRUE) && (IfxEgtm_Cfg_MscAltInputTable[mscLevel2MuxIndex] != NULL_PTR))
        {
            for (indexAltIn = 0u; indexAltIn < IFXEGTM_CFG_NUMMSCALTINPUT; indexAltIn++) /* loop through all AltInput SEL values */
            {
                /* 3. Check whether ALT input selection exists for MSC Set */
                if (*(IfxEgtm_Cfg_MscAltInputTable[mscLevel2MuxIndex] + (((uint32)mscOut->mscAltIn << 2u) + indexAltIn)) == (uint32)mscOut->mscSet)
                {
                    result = TRUE;
                    break;
                }
                else
                {
                    result = FALSE;
                }
            }
        }

        /* 4. Perform Multiplexer connection */
        if (result == TRUE)
        {
            uint32 shift, mask, sel;

            /* Connection 1: Connect GTM output channel to one of the MSC set */
            shift = ((uint32)mscOut->mscSetSignal & 0x3U) << 0x3u;
            sel   = idx << shift;
            mask  = (uint32)IFX_EGTM_MSCSET_CON0_SEL0_MSK << shift;

            switch ((uint8)mscOut->mscSetSignal >> 2)
            {
            case 0:
                Ifx__ldmst(&(MODULE_EGTM.MSCSET[mscOut->mscSet].CON0.U), mask, sel);
                break;
            case 1:
                Ifx__ldmst(&(MODULE_EGTM.MSCSET[mscOut->mscSet].CON1.U), mask, sel);
                break;
            case 2:
                Ifx__ldmst(&(MODULE_EGTM.MSCSET[mscOut->mscSet].CON2.U), mask, sel);
                break;
            case 3:
                Ifx__ldmst(&(MODULE_EGTM.MSCSET[mscOut->mscSet].CON3.U), mask, sel);
                break;
            default:
                /* do nothing */
                break;
            }

            /* Connection 2:
             * TC49x: Connect MSC Set to one of the MSC module and module's INLCON/INLECON/INHCON/INHECON
             * TC4Dx: Connect MSC Set to one of the MSC select and select's INLCON/INLECON/INHCON/INHECON
             */
            shift = ((uint32)mscOut->mscSetSignal << 1u);
            sel   = indexAltIn << shift;
            mask  = (uint32)IFX_EGTM_MSC_INLCON_SEL0_MSK << shift;

            switch ((uint8)mscOut->mscAltIn)
            {
            case 0:
                Ifx__ldmst(&(MODULE_EGTM.MSC[mscLevel2MuxIndex].INLCON.U), mask, sel);
                break;
            case 1:
                Ifx__ldmst(&(MODULE_EGTM.MSC[mscLevel2MuxIndex].INLECON.U), mask, sel);
                break;
            case 2:
                Ifx__ldmst(&(MODULE_EGTM.MSC[mscLevel2MuxIndex].INHCON.U), mask, sel);
                break;
            case 3:
                Ifx__ldmst(&(MODULE_EGTM.MSC[mscLevel2MuxIndex].INHECON.U), mask, sel);
                break;
            default:
                /* do nothing */
                break;
            }
        }
    }

    return result;
}


void IfxEgtm_initApConfig(IfxEgtm_ApConfig *config)
{
    uint8 i = 0U;
    IfxApProt_initConfig(&(config->protseConfig));

    IfxApProt_initConfig(&(config->ctrlApConfig.proteConfig));
    IfxApApu_initConfig(&(config->ctrlApConfig.apuConfig));

    IfxApApu_initConfig(&(config->wrapApConfig.apuConfig));

    for (i = 0u; i < IFXEGTM_NUM_CCM_OBJECTS; i++)
    {
        IfxApApu_initConfig(&(config->clApConfig[i].apuConfig));
    }
}


void IfxEgtm_initAp(Ifx_EGTM *egtm, IfxEgtm_ApConfig *config)
{
    uint8 i = 0U;
    /* Initialize the PROTs */
    IfxEgtm_initProtSe(egtm, &(config->protseConfig));

    IfxEgtm_initCtrlProt(egtm, &(config->ctrlApConfig.proteConfig));

    /* Change the state to CONFIG, Configure APU and set PROT state back to RUN */
    /* Initialize the APU */
    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(egtm->PROTSE), IfxApProt_State_config);
    IfxEgtm_initCtrlApu(egtm, &(config->ctrlApConfig.apuConfig));
    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(egtm->PROTSE), IfxApProt_State_run);

    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(egtm->PROTSE), IfxApProt_State_config);
    IfxEgtm_initWrapApu(egtm, &(config->wrapApConfig.apuConfig));
    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(egtm->PROTSE), IfxApProt_State_run);

    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(egtm->PROTSE), IfxApProt_State_config);

    for (i = 0u; i < IFXEGTM_NUM_CCM_OBJECTS; i++)
    {
        IfxEgtm_initClApu(egtm, (IfxEgtm_Cluster)i, &(config->clApConfig[i].apuConfig));
    }

    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(egtm->PROTSE), IfxApProt_State_run);
}


void IfxEgtm_configureAccessToEgtms(IfxApApu_ApuConfig *apConfig)
{
    uint8 cluster;
    IfxApApu_init((volatile Ifx_ACCEN_ACCEN *)(volatile void *)&MODULE_EGTM.CTRL.ACCEN, apConfig);

    for (cluster = 0u; cluster < IFXEGTM_NUM_CCM_OBJECTS; cluster++)
    {
        IfxApApu_init((volatile Ifx_ACCEN_ACCEN *)(volatile void *)&MODULE_EGTM.CL[cluster].ACCEN, apConfig);
    }

    IfxApApu_init((volatile Ifx_ACCEN_ACCEN *)(volatile void *)&MODULE_EGTM.WRAP.ACCEN, apConfig);
}
