/**
 * \file IfxPcieEp.h
 * \brief PCIE  basic functionality
 * \ingroup IfxLld_Pcie
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
 * \defgroup IfxLld_Pcie_Std_Ep Ep Basic Functionality
 * \ingroup IfxLld_Pcie_Std
 * \defgroup IfxLld_Pcie_Std_Ep_Structures Structures
 * \ingroup IfxLld_Pcie_Std_Ep
 * \defgroup IfxLld_Pcie_Std_Ep_Functions Functions
 * \ingroup IfxLld_Pcie_Std_Ep
 */

#ifndef IFXPCIEEP_H
#define IFXPCIEEP_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Pcie/Std/IfxPcie.h"
#include "_Impl/IfxPcie_cfg.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "IfxPcie_usp_bf.h"
#include "Ap/Std/IfxApProt.h"
#include "Ap/Std/IfxApApu.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Pcie_Std_Ep_Structures
 * \{ */
/** \brief APU config strucuture
 */
typedef struct
{
    IfxApProt_ProtConfig proteConfig;        /**< \brief PROTE configuration */
    IfxApProt_ProtConfig protseConfig;       /**< \brief PROT SE configuration */
    IfxApApu_ApuConfig   apuConfig;          /**< \brief APU config */
} IfxPcieEp_ApConfig;

/** \brief ACK Nak Scheduling configuration
 */
typedef struct
{
    uint8  ackFreq;                       /**< \brief Ack frequency defines the number of ACKs to be accumulated before sending an Ack Request. */
    uint8  ackLatencyTimerModifier;       /**< \brief Increases the timer value of ACK latency timer in increments of 64 clock cycles */
    uint16 ackLatencyTimerLimit;          /**< \brief Ack Latency Timer Limit */
} IfxPcieEp_ackNackConfig;

/** \brief Reply timer configuration
 */
typedef struct
{
    uint8  replayTimerModifier;       /**< \brief Modification of transmit replay timer. Increases the timer value of replay timer in increments of 64 clock cycles */
    uint16 replayTimerLimit;          /**< \brief Replay timer Limit */
} IfxPcieEp_replayTimerConfig;

/** \} */

/** \addtogroup IfxLld_Pcie_Std_Ep_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Set the INT interrupt
 * \param pcieEpSFR Ptr to EP SFR
 * \param enable TRUE: Enable interrupt. FALSE: Disable interrupt
 * \return None
 */
IFX_INLINE void IfxPcieEp_setIntxInterrupt(Ifx_PCIE_USP *pcieEpSFR, boolean enable);

/** \brief Set MSI interrupt
 * \param pcieEpSFR Ptr to EP SFR
 * \param msiIndex index of MSI interrupt
 * \return None
 */
IFX_INLINE void IfxPcieEp_setMsiInterrupt(Ifx_PCIE_USP *pcieEpSFR, uint8 msiIndex);

/** \brief Set MSIx interrupt
 * \param pcieEpSFR Ptr to EP SFR
 * \param msixIndex index of MSI interrupt
 * \return None
 */
IFX_INLINE void IfxPcieEp_setMsixInterrupt(Ifx_PCIE_USP *pcieEpSFR, uint8 msixIndex);

/** \brief Get MSI interrupt statistics
 * \param pcieEpSFR Ptr to EP SFR
 * \return MSI Interrupt status
 */
IFX_INLINE uint32 IfxPcieEp_getMsiInterruptStat(Ifx_PCIE_USP *pcieEpSFR);

/** \brief Set the Enable Mask for Trigger Interrupts
 * \param pcieEpSFR Ptr to EP SFR
 * \param enableMask Mask to be set ( 1 << "POS" implies interrupt #"POS" is enabled )
 * \return None
 */
IFX_INLINE void IfxPcieEp_enableTriggerInt(Ifx_PCIE_USP *pcieEpSFR, uint32 enableMask);

/** \brief Set the Disable Mask for Trigger Interrupts
 * \param pcieEpSFR Ptr to EP SFR
 * \param disableMask Mask to be set ( 1 << "POS" implies interrupt #"POS" is disabled )
 * \return None
 */
IFX_INLINE void IfxPcieEp_disableTriggerInt(Ifx_PCIE_USP *pcieEpSFR, uint32 disableMask);

/** \brief Clear Pending Interrupts
 * \param pcieEpSFR Ptr to EP SFR
 * \param clearMask ( 1 << "POS" implies interrupt #"POS" is cleared )
 * \return None
 */
IFX_INLINE void IfxPcieEp_clearTriggerInt(Ifx_PCIE_USP *pcieEpSFR, uint32 clearMask);

/** \brief Get Pending Interrupts
 * \param pcieEpSFR Ptr to EP SFR
 * \param mask ( 1 << "POS" implies interrupt #"POS" is masked )
 * \return None
 */
IFX_INLINE uint32 IfxPcieEp_getPendingTriggerInt(Ifx_PCIE_USP *pcieEpSFR, uint32 mask);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Init APU config
 * \param config AP config Ptr
 * \return None
 */
IFX_EXTERN void IfxPcieEp_initApConfig(IfxPcieEp_ApConfig *config);

/** \brief Init AP
 * \param pcieEpSFR Ptr to EP SFR
 * \param config AP config Ptr
 * \return None
 */
IFX_EXTERN void IfxPcieEp_initAp(Ifx_PCIE_USP *pcieEpSFR, IfxPcieEp_ApConfig *config);

/** \brief Set Bar Mask value from Bar size
 * \param pcieSFR Ptr to EP Sfr
 * \param barIndex Index of BAR
 * \param barSize size of BAR (NOTE: 64 BIT)
 * \param addressWidth 32 or 64 Bit addressing
 * \param enabled if TRUE, BAR Region is enabled.
 * \return Status of Bar Mask Write
 */
IFX_EXTERN IfxPcie_Status IfxPcieEp_setBarMask(Ifx_PCIE_USP *pcieSFR, IfxPcie_BarNum barIndex, uint64 barSize, IfxPcie_AddressWidth addressWidth, boolean enabled);

/** \brief Set Bar Parameters
 * \param pcieSFR Ptr to EP Sfr
 * \param barIndex Index of BAR
 * \param addressWidth 32 or 64 Bit addressing
 * \param prefetch if TRUE, region is prefetchable
 * \return None
 */
IFX_EXTERN void IfxPcieEp_setBarParameters(Ifx_PCIE_USP *pcieSFR, IfxPcie_BarNum barIndex, IfxPcie_AddressWidth addressWidth, boolean prefetch);

/** \brief Reset link training
 * \param pcieEpSFR Ptr to EP Sfr
 * \return None
 */
IFX_EXTERN void IfxPcieEp_resetLinkTraining(Ifx_PCIE_USP *pcieEpSFR);

/** \brief Check if the link is Up
 * TODO: This is taken currently from debug registers and later to be sprovided to INTERNAL registers only
 * \param pcieEpSFR Ptr to EP SFR
 * \return TRUE: Link is up
 * FALSE: Link is down
 */
IFX_EXTERN boolean IfxPcieEp_isLinkUp(Ifx_PCIE_USP *pcieEpSFR);

/** \brief Check if the link is in state L0
 * \param pcieEpSFR Ptr to EP SFR
 * \return TRUE: Link in state L0
 * FALSE: Link state not in L0
 */
IFX_EXTERN boolean IfxPcieEp_isLinkStateL0(Ifx_PCIE_USP *pcieEpSFR);

/** \brief Enter local loopback
 * \param pcieEpSFR Ptr to EP SFR
 * \return None
 */
IFX_EXTERN void IfxPcieEp_enterLocalLoopback(Ifx_PCIE_USP *pcieEpSFR);

/** \brief Set SRIS operating mode
 * \param pcieEpSFR Ptr to EP SFR
 * \return None
 */
IFX_EXTERN void IfxPcieEp_setSrisOperatingMode(Ifx_PCIE_USP *pcieEpSFR);

/** \brief Exit Loopback
 * \param pcieEpSFR Ptr to EP SFR
 * \return None
 */
IFX_EXTERN void IfxPcieEp_exitLocalLoopback(Ifx_PCIE_USP *pcieEpSFR);

/** \brief Configure Ack Nak Timer configuration
 * \param pcieEpSFR Ptr to EP SFR
 * \param ackNackConfig Ack Nak Scheduling timer configuration
 * \return None
 */
IFX_EXTERN void IfxPcieEp_setAckNackScheduler(Ifx_PCIE_USP *pcieEpSFR, IfxPcieEp_ackNackConfig ackNackConfig);

/** \brief Set Tx replay timer configuration
 * \param pcieEpSFR Ptr to EP SFR
 * \param replayTimerConfig Reply timer configuration
 * \return None
 */
IFX_EXTERN void IfxPcieEp_setReplayTimerLimit(Ifx_PCIE_USP *pcieEpSFR, IfxPcieEp_replayTimerConfig replayTimerConfig);

/**
 * \return None
 */
IFX_EXTERN void IfxPcieEp_setIntrTriggerMsk(Ifx_PCIE_USP *pcieEpSFR, uint32 value);

/**
 */
IFX_EXTERN uint32 IfxPcieEp_getIntrTriggerStatus(Ifx_PCIE_USP *pcieEpSFR);

/**
 * \return None
 */
IFX_EXTERN void IfxPcieEp_clearIntrTriggerStatus(Ifx_PCIE_USP *pcieEpSFR, uint32 value);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxPcieEp_setIntxInterrupt(Ifx_PCIE_USP *pcieEpSFR, boolean enable)
{
    uint32 intxVal = (enable == TRUE) ? 1u : 0u;
    pcieEpSFR->INT.INTXCTRL.B.INTX = intxVal;
}


IFX_INLINE void IfxPcieEp_setMsiInterrupt(Ifx_PCIE_USP *pcieEpSFR, uint8 msiIndex)
{
    if (msiIndex < 32u)
    {
        pcieEpSFR->INT.MSICTRL.U = (uint32)(1u << msiIndex);
    }
}


IFX_INLINE void IfxPcieEp_setMsixInterrupt(Ifx_PCIE_USP *pcieEpSFR, uint8 msixIndex)
{
    if (msixIndex < IFXPCIE_CFG_MAX_NUM_EP_MSIX_INTERRUPTS)
    {
        pcieEpSFR->PORTLOGIC.MSIX_DOORBELL_OFF.B.MSIX_DOORBELL_VECTOR = msixIndex;
    }
}


IFX_INLINE uint32 IfxPcieEp_getMsiInterruptStat(Ifx_PCIE_USP *pcieEpSFR)
{
    return pcieEpSFR->INT.MSISTAT.U;
}


IFX_INLINE void IfxPcieEp_enableTriggerInt(Ifx_PCIE_USP *pcieEpSFR, uint32 enableMask)
{
    pcieEpSFR->INT.TRIGMSK.U |= enableMask;
}


IFX_INLINE void IfxPcieEp_disableTriggerInt(Ifx_PCIE_USP *pcieEpSFR, uint32 disableMask)
{
    pcieEpSFR->INT.TRIGMSK.U &= ~disableMask;
}


IFX_INLINE void IfxPcieEp_clearTriggerInt(Ifx_PCIE_USP *pcieEpSFR, uint32 clearMask)
{
    pcieEpSFR->INT.TRIGCLR.U = clearMask;
}


IFX_INLINE uint32 IfxPcieEp_getPendingTriggerInt(Ifx_PCIE_USP *pcieEpSFR, uint32 mask)
{
    return pcieEpSFR->INT.TRIGSTAT.U & ~(mask);
}


#endif /* IFXPCIEEP_H */
