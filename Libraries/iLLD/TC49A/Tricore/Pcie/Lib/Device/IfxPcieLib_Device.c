/**
 * \file IfxPcieLib_Device.c
 * \brief PCIE DEVICE details
 *
 * \version iLLD_2_0_1_2_19
 * \copyright Copyright (c) 2021 Infineon Technologies AG. All rights reserved.
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
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxPcieLib_Device.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

IfxPcie_Status IfxPcieLib_Device_initAtu(IfxPcie *pcieSFR, IfxPcieLib_Device_Atu *atu, IfxPcieLib_Device_AtuCfg *atuCfg)
{
    IfxPcie_Status status      = IfxPcie_Status_success;
    uint8          inboundReg  = 0u;
    uint8          outboundReg = 0u;

    if (atuCfg != NULL_PTR)     /* check if there is a valid atu Configuration */
    {
        for (inboundReg = 0; inboundReg <= atuCfg->numInboundRegion; inboundReg++)
        {
            IfxPcieLib_Device_initAtuRegion(pcieSFR, &(atu->inboundRegion[inboundReg]), &(atuCfg->inboundRegion[inboundReg]));
        }

        for (outboundReg = 0; outboundReg <= atuCfg->numOutboundRegion; outboundReg++)
        {
            if (atuCfg->outboundRegion[outboundReg].regionIndex != (IfxPcie_AtuRegion)IFXPCIE_CFG_ECAM_ATU_INDEX)
            {
                IfxPcieLib_Device_initAtuRegion(pcieSFR, &(atu->outboundRegion[outboundReg]), &(atuCfg->outboundRegion[outboundReg]));
            }
            else
            {
                status = IfxPcie_Status_failure;
            }
        }
    }

    return status;
}


void IfxPcieLib_Device_initAtuRegion(IfxPcie *pcieSFR, IfxPcieLib_Device_AtuRegion *atuRegion, IfxPcieLib_Device_AtuRegionCfg *atuCfg)
{
    uint8 atuIndex = (uint8)(atuCfg->regionIndex);

    if (atuCfg->direction == IfxPcie_AtuDirection_outBound)
    {
        Ifx_PCIE_DSP_ATU_OUTBOUND *outBoundPtr = &(pcieSFR->DSP.ATU[atuIndex].OUTBOUND);

        outBoundPtr->REGION_CTRL_2.B.REGION_EN = 0u;    /* Disable Region First */

        if (atuCfg->barMapped == FALSE)
        {
            /* Configure the CPU (local) address as original address */
            outBoundPtr->LWR_BASE_ADDR.U   = atuCfg->localMemBase;
            outBoundPtr->UPPER_BASE_ADDR.U = 0U;      /* set to 0 for AURIX 32 Bit */

            /* Configure the Wire address as target address */
            outBoundPtr->LWR_TARGET_ADD.U    = (uint32)(atuCfg->wireMemBase);
            outBoundPtr->UPPER_TARGET_ADDR.U = (uint32)(atuCfg->wireMemBase >> 32u);

            /* Configure the Limit */
            outBoundPtr->LIMIT_ADDR.U = atuCfg->localMemBase + (atuCfg->memSize - 1u);
        }
        else
        {
            /* Do nothing for OUTBOUND currently */
        }

        IfxPcieLib_Device_setupOutboundTlp(outBoundPtr, atuRegion, &(atuCfg->outboundTlp));
        outBoundPtr->REGION_CTRL_2.B.REGION_EN = (uint32)atuCfg->enable;    /* Enable the Region */
    }
    else /* in-bound */
    {
        Ifx_PCIE_DSP_ATU_INBOUND              *inBoundPtr = &(pcieSFR->DSP.ATU[atuIndex].INBOUND);

        inBoundPtr->REGION_CTRL_2.B.REGION_EN = 0u; /* Disable Region First */

        Ifx_PCIE_DSP_ATU_INBOUND_REGION_CTRL_1 regionCtrl1;
        Ifx_PCIE_DSP_ATU_INBOUND_REGION_CTRL_2 regionCtrl2;
        regionCtrl1.U = inBoundPtr->REGION_CTRL_1.U;
        regionCtrl2.U = inBoundPtr->REGION_CTRL_2.U;

        if (atuCfg->barMapped == FALSE)
        {
            /* Configure the CPU (local) address as target address */
            inBoundPtr->LWR_TARGET_ADD.U = (uint32)(atuCfg->localMemBase);

            /* Configure the Wire address as original address */
            inBoundPtr->LWR_BASE_ADDR.U   = (uint32)(atuCfg->wireMemBase);
            inBoundPtr->UPPER_BASE_ADDR.U = (uint32)(atuCfg->wireMemBase >> 32);

            /* Configure the Limit */
            inBoundPtr->LIMIT_ADDR.U = (uint32)(atuCfg->wireMemBase) + (atuCfg->memSize - 1u);
        }
        else
        {
            if (IfxPcie_getDeviceMode(pcieSFR) != IfxPcie_DeviceMode_rc)
            {
                /* Configure the CPU (local) address as target address */
                inBoundPtr->LWR_TARGET_ADD.U = (uint32)(atuCfg->localMemBase);

                regionCtrl2.B.MATCH_MODE     = 1u; /* BAR match mode */
                regionCtrl2.B.BAR_NUM        = (uint32)atuCfg->barIndex;
                atuRegion->barIndex          = atuCfg->barIndex;
            }
        }

        regionCtrl1.B.TYPE                    = atuCfg->outboundTlp.tlpHeader.type; /* Set the TLP Type for match mode */

        inBoundPtr->REGION_CTRL_1.U           = regionCtrl1.U;
        inBoundPtr->REGION_CTRL_2.U           = regionCtrl2.U;
        inBoundPtr->REGION_CTRL_2.B.REGION_EN = (uint32)atuCfg->enable; /* Enable */

        atuRegion->direction                  = IfxPcie_AtuDirection_inBound;
        atuRegion->tlpType                    = atuCfg->inboundTlp.tlpHeader.type;
    }

    atuRegion->localMemBase = atuCfg->localMemBase;
    atuRegion->wireMemBase  = atuCfg->wireMemBase;
    atuRegion->barMapped    = atuCfg->barMapped;
    atuRegion->memSize      = atuCfg->memSize;
    atuRegion->regionIndex  = atuCfg->regionIndex;

    atuRegion->enabled      = TRUE;
    atuRegion->lockStatus   = IfxPcie_AtuLock_locked;
}


void IfxPcieLib_Device_freeAtuRegion(IfxPcie *pcieSFR, IfxPcieLib_Device_AtuRegion *atuRegion)
{
    uint8 atuIndex = (uint8)(atuRegion->regionIndex);

    // TODO: This needs improvement to support CTRL1, CTRL2 flags
    if (atuRegion->direction == IfxPcie_AtuDirection_outBound)
    {
        Ifx_PCIE_DSP_ATU_OUTBOUND *outBoundPtr = &(pcieSFR->DSP.ATU[atuIndex].OUTBOUND);

        outBoundPtr->REGION_CTRL_2.U = 0u;  /* Disable Region */

        if (atuRegion->barMapped == FALSE)
        {
            /* Configure the CPU (local) address as original address */
            outBoundPtr->LWR_BASE_ADDR.U   = 0U;
            outBoundPtr->UPPER_BASE_ADDR.U = 0U;      /* set to 0 for AURIX 32 Bit */

            /* Configure the Wire address as target address */
            outBoundPtr->LWR_TARGET_ADD.U    = 0U;
            outBoundPtr->UPPER_TARGET_ADDR.U = 0U;

            /* Configure the Limit */
            outBoundPtr->LIMIT_ADDR.U = 0U;
        }
        else
        {
            /* Do nothing for OUTBOUND currently */
        }
    }
    else /* in-bound */
    {
        Ifx_PCIE_DSP_ATU_INBOUND *inBoundPtr = &(pcieSFR->DSP.ATU[atuIndex].INBOUND);

        inBoundPtr->REGION_CTRL_2.U = 0u;   /* Disable Region First */

        if (atuRegion->barMapped == FALSE)
        {
            /* Configure the CPU (local) address as target address */
            inBoundPtr->LWR_TARGET_ADD.U = 0U;

            /* Configure the Wire address as original address */
            inBoundPtr->LWR_BASE_ADDR.U   = 0U;
            inBoundPtr->UPPER_BASE_ADDR.U = 0U;

            /* Configure the Limit */
            inBoundPtr->LIMIT_ADDR.U = 0U;
        }
    }

    atuRegion->localMemBase = 0U;
    atuRegion->wireMemBase  = 0U;
    atuRegion->barMapped    = FALSE;
    atuRegion->barIndex     = IfxPcie_BarNum_0;
    atuRegion->memSize      = 0U;

    atuRegion->enabled      = FALSE;
    atuRegion->lockStatus   = IfxPcie_AtuLock_unlocked;
}


void IfxPcieLib_Device_setupOutboundTlp(Ifx_PCIE_DSP_ATU_OUTBOUND *outBoundPtr, IfxPcieLib_Device_AtuRegion *atuRegion, IfxPcieLib_Device_OutboundTlpCfg *outboundTlp)
{
    Ifx_PCIE_DSP_ATU_OUTBOUND_REGION_CTRL_1 regionCtrl1;
    Ifx_PCIE_DSP_ATU_OUTBOUND_REGION_CTRL_2 regionCtrl2;
    regionCtrl1.U            = outBoundPtr->REGION_CTRL_1.U;
    regionCtrl2.U            = outBoundPtr->REGION_CTRL_2.U;

    regionCtrl2.B.DMA_BYPASS = outboundTlp->dmaBypass == TRUE ? 1u : 0u;
    regionCtrl1.B.TYPE       = outboundTlp->tlpHeader.type;

    switch (outboundTlp->tlpHeader.type)
    {
    case IfxPcie_TlpType_memRequest:                                                /* Memory Type */
    case IfxPcie_TlpType_memLockRequest:
        regionCtrl1.B.TC = outboundTlp->tlpHeader.trafficClass;

        if (outboundTlp->tlpHeader.tag != 0u)
        {
            regionCtrl2.B.TAG_SUBSTITUTE_EN = 1u;
            regionCtrl2.B.TAG               = outboundTlp->tlpHeader.tag;
        }

        if (outboundTlp->payloadInhibit == TRUE)
        {
            regionCtrl2.B.INHIBIT_PAYLOAD = 1u;
        }

        if (outboundTlp->tlpHeader.orderingAttr == IfxPcie_TlpOrdering_idBased)
        {
            regionCtrl1.B.IDO = (uint32)1u;
        }
        else if (outboundTlp->tlpHeader.orderingAttr == IfxPcie_TlpOrdering_relaxed)
        {
            regionCtrl1.B.ATTR = (uint32)2u;
        }
        else if (outboundTlp->tlpHeader.orderingAttr == IfxPcie_TlpOrdering_relaxedAndId)
        {
            regionCtrl1.B.IDO  = (uint32)1u;
            regionCtrl1.B.ATTR = (uint32)2u;
        }

        break;
    case IfxPcie_TlpType_msg:                                                             /* Messages Type */
        regionCtrl1.B.TYPE                 = (uint32)(outboundTlp->tlpHeader.type + outboundTlp->tlpHeader.messageRoute);
        regionCtrl1.B.TC                   = (uint32)outboundTlp->tlpHeader.trafficClass; /* Set Traffic Class */
        regionCtrl2.B.MSG_CODE             = (uint32)outboundTlp->tlpHeader.messageCode;  /* Set Message code */
        regionCtrl2.B.HEADER_SUBSTITUTE_EN = 1u;                                          /* Enable Header Substitution */

        outBoundPtr->UPPER_TARGET_ADDR.U   = outboundTlp->tlpHeader.dword3.U;             /* Write Bytes 8-11 */
        outBoundPtr->LWR_TARGET_ADD.U      = outboundTlp->tlpHeader.dword4;               /* Write Bytes 12-15 */

        if (outboundTlp->tlpHeader.tag != 0u)
        {
            regionCtrl2.B.TAG_SUBSTITUTE_EN = 1u;
            regionCtrl2.B.TAG               = outboundTlp->tlpHeader.tag;
        }

        if (outboundTlp->payloadInhibit == TRUE)
        {
            regionCtrl2.B.INHIBIT_PAYLOAD = 1u;
        }

        if (outboundTlp->tlpHeader.orderingAttr == IfxPcie_TlpOrdering_idBased)
        {
            regionCtrl1.B.IDO = (uint32)1u;
        }
        else if (outboundTlp->tlpHeader.orderingAttr == IfxPcie_TlpOrdering_relaxed)
        {
            regionCtrl1.B.ATTR = (uint32)2u;
        }
        else if (outboundTlp->tlpHeader.orderingAttr == IfxPcie_TlpOrdering_relaxedAndId)
        {
            regionCtrl1.B.IDO  = (uint32)1u;
            regionCtrl1.B.ATTR = (uint32)2u;
        }

        break;
    default:
        break;                                                                      /* For all other types, nothing special */
    }

    outBoundPtr->REGION_CTRL_1.U = regionCtrl1.U;
    outBoundPtr->REGION_CTRL_2.U = regionCtrl2.U;

    atuRegion->direction         = IfxPcie_AtuDirection_outBound;
    atuRegion->tlpType           = outboundTlp->tlpHeader.type;
}
