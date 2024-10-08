/**
 * \file IfxGtm_Psm.h
 * \brief GTM  basic functionality
 * \ingroup IfxLld_Gtm
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
 *
 * This Module provides the standard interfaces to manipulate and read PSM sub-module registers in GTM.
 * This Module can be used to abstract the register names and addressing from higher layer software code.
 * PSM includes:
 * FIFO, A2F (AEI to FIFO) and F2A (FIFO to ARU) Interfaces.
 *
 * \defgroup IfxLld_Gtm_Std_Psm PSM
 * \ingroup IfxLld_Gtm_Std
 * \defgroup IfxLld_Gtm_Std_Psm_PSMDataStructures PSM Data Structures
 * \ingroup IfxLld_Gtm_Std_Psm
 * \defgroup IfxLld_Gtm_Std_Psm_PSMEnumerations PSM Enumerations
 * \ingroup IfxLld_Gtm_Std_Psm
 * \defgroup IfxLld_Gtm_Std_Psm_PSMFunctions PSM Functions
 * \ingroup IfxLld_Gtm_Std_Psm
 */

#ifndef IFXGTM_PSM_H
#define IFXGTM_PSM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxGtm_cfg.h"
#include "IfxGtm.h"
#include "_Utilities/Ifx_Assert.h"
#include "Src/Std/IfxSrc.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Gtm_Std_Psm_PSMEnumerations
 * \{ */
/** \brief Enumeration listing the F2A streams
 */
typedef enum
{
    IfxGtm_Psm_F2aStream_0,     /**< \brief F2A Stream 0  */
    IfxGtm_Psm_F2aStream_1,     /**< \brief F2A Stream 1  */
    IfxGtm_Psm_F2aStream_2,     /**< \brief F2A Stream 2  */
    IfxGtm_Psm_F2aStream_3,     /**< \brief F2A Stream 3  */
    IfxGtm_Psm_F2aStream_4,     /**< \brief F2A Stream 4  */
    IfxGtm_Psm_F2aStream_5,     /**< \brief F2A Stream 5  */
    IfxGtm_Psm_F2aStream_6,     /**< \brief F2A Stream 6  */
    IfxGtm_Psm_F2aStream_7      /**< \brief F2A Stream 7  */
} IfxGtm_Psm_F2aStream;

/** \brief Enumeration lisitng the enabled/disabled state of the F2A channel streams.
 */
typedef enum
{
    IfxGtm_Psm_F2aStreamState_readDisabled = 0,  /**< \brief Read as disabled. */
    IfxGtm_Psm_F2aStreamState_disabled     = 1,  /**< \brief Stream disabled and states reset */
    IfxGtm_Psm_F2aStreamState_enabled      = 2,  /**< \brief Stream enabled */
    IfxGtm_Psm_F2aStreamState_readEnabled  = 3   /**< \brief Read as enabled. */
} IfxGtm_Psm_F2aStreamState;

/** \brief Enumeration listing the transfer direction of the F2a Streams.
 * Definition in F2A_CH_STR_CFG.B.DIR
 */
typedef enum
{
    IfxGtm_Psm_F2aTransferDirection_aruToFifo = 0,  /**< \brief ARU to FIFO transfer */
    IfxGtm_Psm_F2aTransferDirection_fifoToAru = 1   /**< \brief FIFO to ARU transfer */
} IfxGtm_Psm_F2aTransferDirection;

/** \brief Enumeration listing the Transfer Mode of the F2A.
 * Definition in F2A_CH_STR_CFG.TMODE
 */
typedef enum
{
    IfxGtm_Psm_F2aTransferMode_transferLowWord   = 0, /**< \brief Transfer ARU bits 23:0 from/to FIFO */
    IfxGtm_Psm_F2aTransferMode_transferHighWord  = 1, /**< \brief Transfer ARU bits 47:24 from/to FIFO */
    IfxGtm_Psm_F2aTransferMode_transferBothWords = 2  /**< \brief Transfer Both words from/to FIFO */
} IfxGtm_Psm_F2aTransferMode;

/** \brief Enumeration lisiting Fifo Channels
 */
typedef enum
{
    IfxGtm_Psm_FifoChannel_0,     /**< \brief FIFO  Channel 0  */
    IfxGtm_Psm_FifoChannel_1,     /**< \brief FIFO  Channel 1  */
    IfxGtm_Psm_FifoChannel_2,     /**< \brief FIFO  Channel 2  */
    IfxGtm_Psm_FifoChannel_3,     /**< \brief FIFO  Channel 3  */
    IfxGtm_Psm_FifoChannel_4,     /**< \brief FIFO  Channel 4  */
    IfxGtm_Psm_FifoChannel_5,     /**< \brief FIFO  Channel 5  */
    IfxGtm_Psm_FifoChannel_6,     /**< \brief FIFO  Channel 6  */
    IfxGtm_Psm_FifoChannel_7      /**< \brief FIFO  Channel 7  */
} IfxGtm_Psm_FifoChannel;

/** \brief Enumeration list of the DMA direction in hysteresis modes.\n
 * definition in FIFO_CH_IRQ_MODE.DMA_HYST_DIR
 */
typedef enum
{
    IfxGtm_Psm_FifoChannelDmaHystDir_read  = 0, /**< \brief read direction */
    IfxGtm_Psm_FifoChannelDmaHystDir_write = 1  /**< \brief write */
} IfxGtm_Psm_FifoChannelDmaHystDir;

/** \brief Interrupts of the Fifo Channel
 */
typedef enum
{
    IfxGtm_Psm_FifoChannelInterrupt_empty   = 0,  /**< \brief empty Fifo Channel */
    IfxGtm_Psm_FifoChannelInterrupt_full    = 1,  /**< \brief full fifo channel */
    IfxGtm_Psm_FifoChannelInterrupt_lowerWm = 2,  /**< \brief Lower watermark reached */
    IfxGtm_Psm_FifoChannelInterrupt_upperWm = 3   /**< \brief Upper watermark reached, */
} IfxGtm_Psm_FifoChannelInterrupt;

/** \brief Enumeration list for modes of FIFO operation.\n
 * Definition in FIFO_CH_CTRL.RBM
 */
typedef enum
{
    IfxGtm_Psm_FifoChannelMode_normal     = 0, /**< \brief normal mode of operation */
    IfxGtm_Psm_FifoChannelMode_ringBuffer = 1  /**< \brief Ring Buffer Mode */
} IfxGtm_Psm_FifoChannelMode;

/** \brief Enumeration listing the Fifo Channel Status.\n
 * Definition in FIFO_CH_STATUS register.
 */
typedef enum
{
    IfxGtm_Psm_FifoChannelStatus_empty   = 0,  /**< \brief empty */
    IfxGtm_Psm_FifoChannelStatus_full    = 1,  /**< \brief full */
    IfxGtm_Psm_FifoChannelStatus_lowerWm = 2,  /**< \brief Lower Watermark reached */
    IfxGtm_Psm_FifoChannelStatus_upperWm = 3,  /**< \brief Upper Watermark reached */
    IfxGtm_Psm_FifoChannelStatus_normal  = 4   /**< \brief normal running status */
} IfxGtm_Psm_FifoChannelStatus;

/** \brief List of mode of interrupt
 * Definition in FIFO_CH_IRQ_MODE.IRQ_MODE
 */
typedef enum
{
    IfxGtm_Psm_InterruptMode_level       = 0,  /**< \brief level mode */
    IfxGtm_Psm_InterruptMode_pulse       = 1,  /**< \brief pulse mode */
    IfxGtm_Psm_InterruptMode_pulseNotify = 2,  /**< \brief pulse notify mode */
    IfxGtm_Psm_InterruptMode_singlePulse = 3   /**< \brief single pulse mode */
} IfxGtm_Psm_InterruptMode;

/** \} */

/** \addtogroup IfxLld_Gtm_Std_Psm_PSMFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief sets the mode of operation of FIFO
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \param mode Fifo Channel mode
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_Fifo_setChannelMode(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, IfxGtm_Psm_FifoChannelMode mode);

/** \brief get the Pointer to the Fifo Channel SFR
 * \param clsIndex fifo object
 * \param channel Fifo Channel
 * \return Pointer to the FIFO channel SFR
 */
IFX_INLINE Ifx_GTM_CLS_PSM_FIFO_CH *IfxGtm_Psm_Fifo_getChannelPointer(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel);

/** \brief get pointer to the FIFO object SFR block
 * \param clsIndex fifo object
 * \return Pointer to the FIFO SFR
 */
IFX_INLINE Ifx_GTM_CLS_PSM_FIFO *IfxGtm_Psm_Fifo_getPointer(IfxGtm_Cluster clsIndex);

/** \brief Flush the contents of the specified Fifo Channel.
 * \param clsIndex fifo object
 * \param channel Fifo Channel
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_Fifo_flushChannelFifo(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel);

/** \brief Unlock the direct RAM access to the FIFO specified.
 * This control bit applies RAM write access to all channels of the specified FIFO.
 * \param clsIndex fifo object
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_Fifo_enableRamAccess(IfxGtm_Cluster clsIndex);

/** \brief Disable Direct RAM access to the specified Fifo.
 * The setting is applicable to all channels of specified Fifo.
 * \param clsIndex fifo object
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_Fifo_disableRamAccess(IfxGtm_Cluster clsIndex);

/** \brief Set the logical end address for the specified Fifo Channel.
 * The address range is 0 - (IFXGTM_PSM_FIFORAMSIZE - 1).
 * END address should be in range: START address<address<IFXGTM_PSM_FIFORAMSIZE
 *
 * Caution: A modification of the address will flush the corresponding Fifo Channel.
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \param address End address of Fifo Channel
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_Fifo_setChannelEndAddress(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, uint32 address);

/** \brief get the logical start address of the Fifo Channel.
 * The address range is 0 - (IFXGTM_PSM_FIFORAMSIZE-1).
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \return start address of fifo channel
 */
IFX_INLINE uint32 IfxGtm_Psm_Fifo_getChannelStartAddress(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel);

/** \brief get the logical end address of the Fifo Channel.
 * The address range is 0 - (IFXGTM_PSM_FIFORAMSIZE-1).
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \return end address of the fifo channel
 */
IFX_INLINE uint32 IfxGtm_Psm_Fifo_getChannelEndAddress(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel);

/** \brief Set the logical start address for the specified Fifo Channel.
 * The address range is 0 - (IFXGTM_PSM_FIFORAMSIZE - 1).
 * START address should be in range: 0<address<IFXGTM_PSM_FIFORAMSIZE
 *
 * Caution: A modification of the address will flush the corresponding Fifo Channel.
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \param address Start address of Fifo Channel
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_Fifo_setChannelStartAddress(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, uint32 address);

/** \brief get the RAM size usage of the specified FIFO channel.
 * Returns the value : (END_ADDRESS - START_ADDRESS) + 1
 * Each unit is 29 bits wide.
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \return size of the Fifo Channel
 */
IFX_INLINE uint32 IfxGtm_Psm_Fifo_getChannelSize(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel);

/** \brief set the RAM size of the specified FIFO channel.
 * The RAM size should be in range: 0 - ((IFXGTM_PSM_FIFORAMSIZE - START address) + 1)
 * Caution: This will modify the END address of the Fifo Channel RAM.
 * This will also flush the FIFO as the END address gets modified.
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \param size size of Fifo Channel
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_Fifo_setChannelSize(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, uint32 size);

/** \brief get the Fill level of the Fifo Channel specified.
 * The Fill level is in range: 0 < Level <= ( (END_ADDRESS - START_ADDRESS) + 1 )
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \return Fill level of the Fifo channel
 */
IFX_INLINE uint32 IfxGtm_Psm_Fifo_getChannelFillLevel(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel);

/** \brief set the upper watermark of the specified Fifo Channel.
 * Upper watermark must be in range: 0 < addr < (END_ADDRESS - START_ADDRESS)
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \param upperWm Upper Watermark level
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_Fifo_setChannelUpperWatermark(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, uint32 upperWm);

/** \brief set the upper watermark of the specified Fifo Channel.
 * Upper watermark must be in range: 0 < addr < (END_ADDRESS - START_ADDRESS)
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \param lowerWm Lower Watermark level
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_Fifo_setChannelLowerWatermark(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, uint32 lowerWm);

/** \brief Get the upper watermark level of the Fifo Channel.
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \return Upper Watermark
 */
IFX_INLINE uint32 IfxGtm_Psm_Fifo_getChannelUpperWatermark(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel);

/** \brief Get the Lower watermark level of the Fifo Channel.
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \return Lower Watermark
 */
IFX_INLINE uint32 IfxGtm_Psm_Fifo_getChannelLowerWatermark(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel);

/** \brief get the write pointer of the specified Fifo Channel
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \return Write Pointer
 */
IFX_INLINE uint32 IfxGtm_Psm_Fifo_getChannelWritePtr(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel);

/** \brief get the read pointer of the specified Fifo Channel
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \return Read Pointer
 */
IFX_INLINE uint32 IfxGtm_Psm_Fifo_getChannelReadPtr(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel);

/** \brief get the Status of Interrupt raised.
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \param interrupt interrupt type
 * \return Interrupt Status
 */
IFX_INLINE boolean IfxGtm_Psm_Fifo_getChannelInterruptStatus(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, IfxGtm_Psm_FifoChannelInterrupt interrupt);

/** \brief enable the interrupt type
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \param interrupt interrupt type
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_Fifo_enableChannelInterrupt(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, IfxGtm_Psm_FifoChannelInterrupt interrupt);

/** \brief disable the interrupt for Fifo Channel
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \param interrupt interrupt type
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_Fifo_disableChannelInterrupt(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, IfxGtm_Psm_FifoChannelInterrupt interrupt);

/** \brief forces the Interrupt from Fifo Channel
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \param interrupt interrupt type
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_Fifo_setChannelInterrupt(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, IfxGtm_Psm_FifoChannelInterrupt interrupt);

/** \brief set the mode of interrupt
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \param irqmode Interrupt Mode
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_Fifo_setChannelInterruptMode(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, IfxGtm_Psm_InterruptMode irqmode);

/** \brief set the mode of DMA hysteresis.
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \param enabled DMA hysteresis enable
 * \param dir direction
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_Fifo_setChannelDmaHystMode(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, boolean enabled, IfxGtm_Psm_FifoChannelDmaHystDir dir);

/** \brief clear the interrupt of specified type.
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \param interrupt interrupt type
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_Fifo_clearChannelInterrupt(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, IfxGtm_Psm_FifoChannelInterrupt interrupt);

/** \brief clear all the interrupts for the Fifo Channel
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_Fifo_clearAllChannelInterrupts(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel);

/** \brief get the pointer to the F2A of the specified Fifo object.
 * \param clsIndex f2a object
 * \return pointer to f2a object sfr
 */
IFX_INLINE Ifx_GTM_CLS_PSM_F2A *IfxGtm_Psm_F2a_getPointer(IfxGtm_Cluster clsIndex);

/** \brief enable the selected stream of the F2A.
 * \param clsIndex Index of the CLS object used
 * \param f2aStream f2a stream number
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_F2a_enableStream(IfxGtm_Cluster clsIndex, IfxGtm_Psm_F2aStream f2aStream);

/** \brief disables the specified stream of the F2A
 * \param clsIndex Index of the CLS object used
 * \param f2aStream f2a stream number
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_F2a_disableStream(IfxGtm_Cluster clsIndex, IfxGtm_Psm_F2aStream f2aStream);

/** \brief get the state of the specified fifo stream.
 * \param clsIndex Index of the CLS object used
 * \param f2aStream f2a stream number
 * \return stream state
 */
IFX_INLINE IfxGtm_Psm_F2aStreamState IfxGtm_Psm_F2a_getStreamState(IfxGtm_Cluster clsIndex, IfxGtm_Psm_F2aStream f2aStream);

/** \brief set the ARU read address of the specified F2A stream
 * \param clsIndex Index of the CLS object used
 * \param f2aStream f2a stream number
 * \param address ARU read address
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_F2a_setAruReadAddress(IfxGtm_Cluster clsIndex, IfxGtm_Psm_F2aStream f2aStream, uint32 address);

/** \brief set the Transfer Mode of the F2A stream.
 * \param clsIndex Index of the CLS object used
 * \param f2aStream f2a stream number
 * \param mode transfer mode
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_F2a_setTransferMode(IfxGtm_Cluster clsIndex, IfxGtm_Psm_F2aStream f2aStream, IfxGtm_Psm_F2aTransferMode mode);

/** \brief get the Transfer mode of the specified F2A stream.
 * \param clsIndex Index of the CLS object used
 * \param f2aStream f2a stream number
 * \return transfer mode
 */
IFX_INLINE IfxGtm_Psm_F2aTransferMode IfxGtm_Psm_F2a_getTransferMode(IfxGtm_Cluster clsIndex, IfxGtm_Psm_F2aStream f2aStream);

/** \brief set the transfer direction of the F2A stream.
 * \param clsIndex Index of the CLS object used
 * \param f2aStream f2a stream number
 * \param dir transfer direction
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_F2a_setTransferDirection(IfxGtm_Cluster clsIndex, IfxGtm_Psm_F2aStream f2aStream, IfxGtm_Psm_F2aTransferDirection dir);

/** \brief get the transfer direction of the F2A stream.
 * \param clsIndex Index of the CLS object used
 * \param f2aStream f2a stream number
 * \return transfer direction
 */
IFX_INLINE IfxGtm_Psm_F2aTransferDirection IfxGtm_Psm_F2a_getTransferDirection(IfxGtm_Cluster clsIndex, IfxGtm_Psm_F2aStream f2aStream);

/** \brief get the SRC pointer for the specified FIFO channel.
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \return SRC pointer
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxGtm_Psm_Fifo_getChannelSrcPointer(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel);

/** \brief get the Pointer to the AFD buffer for Fifo channel.
 * \param clsIndex fifo object
 * \param channel Fifo Channel
 * \return afd channel pointer
 */
IFX_INLINE Ifx_GTM_CLS_PSM_AFD_CH *IfxGtm_Psm_Afd_getChannelPointer(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel);

/** \brief write the data into the Buffer access register of specified Fifo Channel
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \param data data to be written
 * \return None
 */
IFX_INLINE void IfxGtm_Psm_Afd_writeChannelBuffer(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, uint32 data);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief get the Status of the Fifo Channel.
 * Returns either Full, Empty, Upper WM or Lower WM reached status.
 * If none of the above, it will return "normal" status.
 * \param clsIndex Index of the CLS object used
 * \param channel Fifo Channel
 * \return Status of the Fifo Channel
 */
IFX_EXTERN IfxGtm_Psm_FifoChannelStatus IfxGtm_Psm_Fifo_getChannelStatus(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxGtm_Psm_Fifo_setChannelMode(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, IfxGtm_Psm_FifoChannelMode mode)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    fifoCh->CTRL.B.RBM = (uint8)mode;
}


IFX_INLINE Ifx_GTM_CLS_PSM_FIFO_CH *IfxGtm_Psm_Fifo_getChannelPointer(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel)
{
    return (Ifx_GTM_CLS_PSM_FIFO_CH *)&(MODULE_GTM.CLS[clsIndex].PSM.FIFO.CH[channel]);
}


IFX_INLINE Ifx_GTM_CLS_PSM_FIFO *IfxGtm_Psm_Fifo_getPointer(IfxGtm_Cluster clsIndex)
{
    return (Ifx_GTM_CLS_PSM_FIFO *)&(MODULE_GTM.CLS[clsIndex].PSM.FIFO);
}


IFX_INLINE void IfxGtm_Psm_Fifo_flushChannelFifo(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    fifoCh->CTRL.B.FLUSH = (uint8)1u;
}


IFX_INLINE void IfxGtm_Psm_Fifo_enableRamAccess(IfxGtm_Cluster clsIndex)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, (IfxGtm_Psm_FifoChannel)0);
    fifoCh->CTRL.B.WULOCK = (uint8)1u;
}


IFX_INLINE void IfxGtm_Psm_Fifo_disableRamAccess(IfxGtm_Cluster clsIndex)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, (IfxGtm_Psm_FifoChannel)0);
    fifoCh->CTRL.B.WULOCK = (uint8)0u;
}


IFX_INLINE void IfxGtm_Psm_Fifo_setChannelEndAddress(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, uint32 address)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh        = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    uint32                   start_address = IfxGtm_Psm_Fifo_getChannelStartAddress(clsIndex, channel);

    if ((address > start_address) &&
        (address < IFXGTM_PSM_FIFORAMSIZE))
    {
        fifoCh->END_ADDR.B.ADDR = (uint16)address;
    }
    else
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }
}


IFX_INLINE uint32 IfxGtm_Psm_Fifo_getChannelStartAddress(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    return (uint32)fifoCh->START_ADDR.B.ADDR;
}


IFX_INLINE uint32 IfxGtm_Psm_Fifo_getChannelEndAddress(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    return (uint32)fifoCh->END_ADDR.B.ADDR;
}


IFX_INLINE void IfxGtm_Psm_Fifo_setChannelStartAddress(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, uint32 address)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);

    if (address < (IFXGTM_PSM_FIFORAMSIZE - 1))  /* START address should be within 0 - 1022 */
    {
        fifoCh->START_ADDR.B.ADDR = (uint16)address;
    }
    else
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }
}


IFX_INLINE uint32 IfxGtm_Psm_Fifo_getChannelSize(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    return (uint32)(((uint32)fifoCh->END_ADDR.B.ADDR - (uint32)fifoCh->START_ADDR.B.ADDR) + (uint32)1);
}


IFX_INLINE void IfxGtm_Psm_Fifo_setChannelSize(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, uint32 size)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh        = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    uint32                   start_address = IfxGtm_Psm_Fifo_getChannelStartAddress(clsIndex, channel);

    if (size < ((IFXGTM_PSM_FIFORAMSIZE - start_address) + (uint32)1))
    {
        fifoCh->END_ADDR.B.ADDR = (uint16)(start_address + size - (uint32)1);
    }
    else
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }
}


IFX_INLINE uint32 IfxGtm_Psm_Fifo_getChannelFillLevel(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    return (uint32)fifoCh->FILL_LEVEL.B.LEVEL;
}


IFX_INLINE void IfxGtm_Psm_Fifo_setChannelUpperWatermark(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, uint32 upperWm)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    uint32                   size   = IfxGtm_Psm_Fifo_getChannelSize(clsIndex, channel);

    if (upperWm < (size))  /* should be within 0 - 1023 */
    {
        fifoCh->UPPER_WM.B.ADDR = (uint16)upperWm;
    }
    else
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }
}


IFX_INLINE void IfxGtm_Psm_Fifo_setChannelLowerWatermark(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, uint32 lowerWm)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    uint32                   size   = IfxGtm_Psm_Fifo_getChannelSize(clsIndex, channel);

    if (lowerWm < (size))  /* should be within 0 - 1023 */
    {
        fifoCh->LOWER_WM.B.ADDR = (uint16)lowerWm;
    }
    else
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }
}


IFX_INLINE uint32 IfxGtm_Psm_Fifo_getChannelUpperWatermark(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    return (uint32)fifoCh->UPPER_WM.B.ADDR;
}


IFX_INLINE uint32 IfxGtm_Psm_Fifo_getChannelLowerWatermark(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    return (uint32)fifoCh->LOWER_WM.B.ADDR;
}


IFX_INLINE uint32 IfxGtm_Psm_Fifo_getChannelWritePtr(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);

    return (uint32)fifoCh->WR_PTR.B.ADDR;
}


IFX_INLINE uint32 IfxGtm_Psm_Fifo_getChannelReadPtr(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);

    return (uint32)fifoCh->RD_PTR.B.ADDR;
}


IFX_INLINE boolean IfxGtm_Psm_Fifo_getChannelInterruptStatus(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, IfxGtm_Psm_FifoChannelInterrupt interrupt)
{
    boolean                  status;
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh     = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    uint32                   irq_notify = (uint32)fifoCh->IRQ_NOTIFY.U;
    status = (((irq_notify >> (uint8)interrupt) & (uint32)1) == (uint32)1) ? TRUE : FALSE;
    return status;
}


IFX_INLINE void IfxGtm_Psm_Fifo_enableChannelInterrupt(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, IfxGtm_Psm_FifoChannelInterrupt interrupt)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    volatile Ifx_UReg_32Bit *irq_en = &(fifoCh->IRQ_EN.U);

    *irq_en |= ((uint32)1 << (uint32)interrupt);
}


IFX_INLINE void IfxGtm_Psm_Fifo_disableChannelInterrupt(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, IfxGtm_Psm_FifoChannelInterrupt interrupt)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    volatile Ifx_UReg_32Bit *irq_en = &(fifoCh->IRQ_EN.U);

    *irq_en ^= ((uint32)1 << (uint32)interrupt);
}


IFX_INLINE void IfxGtm_Psm_Fifo_setChannelInterrupt(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, IfxGtm_Psm_FifoChannelInterrupt interrupt)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh    = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    volatile Ifx_UReg_32Bit *irq_force = &(fifoCh->IRQ_FORCINT.U);

    *irq_force |= ((uint32)1 << (uint32)interrupt);
}


IFX_INLINE void IfxGtm_Psm_Fifo_setChannelInterruptMode(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, IfxGtm_Psm_InterruptMode irqmode)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    fifoCh->IRQ_MODE.B.IRQ_MODE = (uint8)irqmode;
}


IFX_INLINE void IfxGtm_Psm_Fifo_setChannelDmaHystMode(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, boolean enabled, IfxGtm_Psm_FifoChannelDmaHystDir dir)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    fifoCh->IRQ_MODE.B.DMA_HYSTERESIS = (uint8)enabled;
    fifoCh->IRQ_MODE.B.DMA_HYST_DIR   = (uint8)dir;
}


IFX_INLINE void IfxGtm_Psm_Fifo_clearChannelInterrupt(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, IfxGtm_Psm_FifoChannelInterrupt interrupt)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    fifoCh->IRQ_NOTIFY.U |= ((uint32)1 << (uint32)interrupt);
}


IFX_INLINE void IfxGtm_Psm_Fifo_clearAllChannelInterrupts(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel)
{
    Ifx_GTM_CLS_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    fifoCh->IRQ_NOTIFY.U |= (uint32)0xFu;
}


IFX_INLINE Ifx_GTM_CLS_PSM_F2A *IfxGtm_Psm_F2a_getPointer(IfxGtm_Cluster clsIndex)
{
    return (Ifx_GTM_CLS_PSM_F2A *)&(MODULE_GTM.CLS[clsIndex].PSM.F2A);
}


IFX_INLINE void IfxGtm_Psm_F2a_enableStream(IfxGtm_Cluster clsIndex, IfxGtm_Psm_F2aStream f2aStream)
{
    Ifx_GTM_CLS_PSM_F2A     *f2aPtr     = IfxGtm_Psm_F2a_getPointer(clsIndex);
    volatile Ifx_UReg_32Bit *f2a_enable = &(f2aPtr->ENABLE.U);
    uint32                   value      = (uint32)IfxGtm_Psm_F2aStreamState_enabled << (uint32)((uint32)f2aStream * 2);
    uint32                   mask       = (uint32)3 << ((uint8)f2aStream * 2U);

    Ifx__ldmst((volatile void *)f2a_enable, mask, value);
}


IFX_INLINE void IfxGtm_Psm_F2a_disableStream(IfxGtm_Cluster clsIndex, IfxGtm_Psm_F2aStream f2aStream)
{
    Ifx_GTM_CLS_PSM_F2A     *f2aPtr     = IfxGtm_Psm_F2a_getPointer(clsIndex);
    volatile Ifx_UReg_32Bit *f2a_enable = &(f2aPtr->ENABLE.U);
    uint32                   value      = (uint32)IfxGtm_Psm_F2aStreamState_disabled << (uint32)((uint32)f2aStream * 2);
    uint32                   mask       = (uint32)3 << ((uint8)f2aStream * 2);

    Ifx__ldmst((volatile void *)f2a_enable, mask, value);
}


IFX_INLINE IfxGtm_Psm_F2aStreamState IfxGtm_Psm_F2a_getStreamState(IfxGtm_Cluster clsIndex, IfxGtm_Psm_F2aStream f2aStream)
{
    Ifx_GTM_CLS_PSM_F2A *f2aPtr     = IfxGtm_Psm_F2a_getPointer(clsIndex);
    uint32               f2a_enable = f2aPtr->ENABLE.U;

    f2a_enable &= ((uint32)3 << ((uint8)f2aStream * 2U));

    return (IfxGtm_Psm_F2aStreamState)((uint32)(f2a_enable >> ((uint32)f2aStream * 2U)));
}


IFX_INLINE void IfxGtm_Psm_F2a_setAruReadAddress(IfxGtm_Cluster clsIndex, IfxGtm_Psm_F2aStream f2aStream, uint32 address)
{
    Ifx_GTM_CLS_PSM_F2A *f2aPtr = IfxGtm_Psm_F2a_getPointer(clsIndex);

    f2aPtr->CH_ARU_RD_FIFO[f2aStream].B.ADDR = (uint16)address;
}


IFX_INLINE void IfxGtm_Psm_F2a_setTransferMode(IfxGtm_Cluster clsIndex, IfxGtm_Psm_F2aStream f2aStream, IfxGtm_Psm_F2aTransferMode mode)
{
    Ifx_GTM_CLS_PSM_F2A *f2aPtr = IfxGtm_Psm_F2a_getPointer(clsIndex);

    f2aPtr->CH_STR_CFG[f2aStream].B.TMODE = (uint8)mode;
}


IFX_INLINE IfxGtm_Psm_F2aTransferMode IfxGtm_Psm_F2a_getTransferMode(IfxGtm_Cluster clsIndex, IfxGtm_Psm_F2aStream f2aStream)
{
    Ifx_GTM_CLS_PSM_F2A *f2aPtr = IfxGtm_Psm_F2a_getPointer(clsIndex);

    return (IfxGtm_Psm_F2aTransferMode)(f2aPtr->CH_STR_CFG[f2aStream].B.TMODE);
}


IFX_INLINE void IfxGtm_Psm_F2a_setTransferDirection(IfxGtm_Cluster clsIndex, IfxGtm_Psm_F2aStream f2aStream, IfxGtm_Psm_F2aTransferDirection dir)
{
    Ifx_GTM_CLS_PSM_F2A *f2aPtr = IfxGtm_Psm_F2a_getPointer(clsIndex);

    f2aPtr->CH_STR_CFG[f2aStream].B.DIR = (uint8)dir;
}


IFX_INLINE IfxGtm_Psm_F2aTransferDirection IfxGtm_Psm_F2a_getTransferDirection(IfxGtm_Cluster clsIndex, IfxGtm_Psm_F2aStream f2aStream)
{
    Ifx_GTM_CLS_PSM_F2A *f2aPtr = IfxGtm_Psm_F2a_getPointer(clsIndex);

    return (IfxGtm_Psm_F2aTransferDirection)f2aPtr->CH_STR_CFG[f2aStream].B.DIR;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxGtm_Psm_Fifo_getChannelSrcPointer(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel)
{
    return (volatile Ifx_SRC_SRCR *)&MODULE_SRC.GTM.PSM[clsIndex].SR[channel];
}


IFX_INLINE Ifx_GTM_CLS_PSM_AFD_CH *IfxGtm_Psm_Afd_getChannelPointer(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel)
{
    return (Ifx_GTM_CLS_PSM_AFD_CH *)&(MODULE_GTM.CLS[clsIndex].PSM.AFD.CH[channel]);
}


IFX_INLINE void IfxGtm_Psm_Afd_writeChannelBuffer(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel, uint32 data)
{
    Ifx_GTM_CLS_PSM_AFD_CH *AfdCh = IfxGtm_Psm_Afd_getChannelPointer(clsIndex, channel);

    AfdCh->BUF_ACC.B.DATA = data;
}


#endif /* IFXGTM_PSM_H */
