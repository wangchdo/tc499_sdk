/**
 * \file IfxPcieLib_Dma.h
 * \brief PCIE DMA details
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
 *
 * \defgroup IfxLld_Pcie_Dma_Usage How to use the DMA Interface layer?
 * \ingroup IfxLld_Pcie
 *
 * \section IfxLld_Pcie_Dma_Overview Overview
 *
 * Aurix provides DMA controller for doing memory transfers without engaging CPU.\n
 * This document describes how to use this DMA controller.\n
 * <b>NOTE:</b> Make sure to initialize the Aurix device as RC or EP before initializing/using DMA.
 *
 * \subsection IfxLld_Pcie_Dma_Overview_Func Functionalities Provided
 * The DMA interface layer provides the following functionalities:
 *     -# Configuring DMA in normal or linked list mode
 *     -# Configuring local(pin) and remote(IMWr) interrupts
 *     -# Configuring individual channel arbitration weights
 *     -# Starting/stopping any channel
 *     -# Updating channel context or transaction list pointer after channel initialization
 *
 * \section IfxLld_Pcie_Dma_Code Coding example
 *
 * \subsection IfxLld_Pcie_Dma_Step1 STEP 1: Initialize DMA module
 * <b>NOTE:</b> Make sure to initialize the Aurix device as RC or EP before initializing/using DMA.
 *
 * In this section, we will initialize DMA module by following these steps:
 *     - Include DMA interface layer file (see below: #0)
 *     - Instantiate necessary variables (see below: #1)
 *     - Define interrupt handlers (see below: #2)
 *     - Initialize DMA configuration structure (see below: #3)
 *     - Manually configure DMA configuration structure (see below: #4)
 *     - Initialize DMA module (see below: #5)
 *
 *     \code
 *     //=====================================
 *     // 0. Include DMA Interface
 *     //=====================================
 *
 *     #include "Pcie/Lib/Dma/IfxPcieLib_Dma.h"
 *
 *     //=====================================
 *     // 1. Variable Instantiation
 *     //=====================================
 *
 *     IfxPcie_Status status;
 *     // 1.1 Module Variables
 *     IfxPcieLib_Dma             dmaHandle;
 *     IfxPcieLib_Dma_Config      dmaConfig;
 *     // 1.2 Channel Variables
 *     IfxPcieLib_Dma_ChannelCfg  dmaWriteChannelConfig;
 *     IfxPcieLib_Dma_Channel     dmaWriteChannel;
 *
 *     //=====================================
 *     // 2.Interrupt handlers
 *     //=====================================
 *
 *     IFX_INTERRUPT(pcie_dmaWriteIsr, 0, 2)
 *     {
 *         // Call interrupt handler and check status of operation
 *         IfxPcieLib_Dma_interruptHandler(&dmaWriteChannel);
 *     }
 *
 *     // Attach this function when configuring write channel
 *     // Function will be executed when code hits above interrupt routine
 *     void DmaWriteDoneInterruptHandler(void)
 *     {
 *         // insert your code
 *     }
 *
 *     //=====================================
 *     // 3. Config structure initialization
 *     //=====================================
 *
 *     // 3.1 Assign default values to config structure members
 *     IfxPcieLib_Dma_initModuleConfig(&(MODULE_PCIE_DSP.DMACAP), &dmaConfig);
 *
 *     //=====================================
 *     // 4. Manually configure DMA
 *     //=====================================
 *
 *     // 4.1 [Optional] Configure channel arbitration weight
 *     for (int i = 0; i < IFXPCIE_CFG_NUM_DMA_READ_CHANNELS; i++)
 *     {
 *         config.arbitration.readChannel[i]  = IfxPcieDma_ChannelArbWeight_4;
 *         config.arbitration.writeChannel[i] = IfxPcieDma_ChannelArbWeight_4;
 *     }
 *
 *     // 4.2 [Optional] Configure MSI address for remote interrupt
 *     // E.g: config.msiAddress.readDone = 0xCAFECAFE;
 *
 *     //=====================================
 *     // 5. Initialize DMA Module
 *     //=====================================
 *
 *     status = IfxPcieLib_Dma_initModule(&dmaHandle, &dmaConfig);
 *
 *     \endcode
 *
 * \subsection IfxLld_Pcie_Dma_Step2 STEP 2: Initialize DMA write channel configuration
 * Note: Initialization of read channel is similar to write\n
 *
 * In this section, we will initialize DMA channel configuration structure (see below: #6)
 *
 *     \code
 *     //=====================================
 *     // 6. Initialize config structure
 *     //=====================================
 *
 *     IfxPcieLib_Dma_initChannelConfig(&(MODULE_PCIE_DSP.DMACAP), &dmaWriteChannelConfig);
 *
 *     \endcode
 *
 * \subsection IfxLld_Pcie_Dma_Step31 STEP 3: [Option 1] Configure channel for Normal operation
 *
 * In this section, we will configure DMA channel for normal operation (see below: #7)
 *
 *     \code
 *
 *     //=====================================
 *     // 7. Configure normal operation specific configuration of channel
 *     //=====================================
 *
 *     // 7.1 Configure normal mode variables
 *     dmaWriteChannelConfig.context.enableLocalInt = TRUE;                // Enable local interrupt
 *     dmaWriteChannelConfig.context.srcAddr        = (uint64)0x90300000;  // Source address of data (LMU in this case)
 *     dmaWriteChannelConfig.context.destAddr       = (uint64)0x00010000;  // Destination address of data (wire memory in this case)
 *     dmaWriteChannelConfig.context.size           = 0x1000;              // Transfer size
 *
 *     // 7.2 Configure channel mode
 *     dmaWriteChannelConfig.mode                   = IfxPcieDma_ChannelMode_contextBased;  // Transfer Mode
 *     \endcode
 *
 * \subsection IfxLld_Pcie_Dma_Step32 STEP 3: [Option 2] Configure channel for Linked list operation
 *
 * In this section, we will configure DMA channel for linked list operation (see below: #7).\n
 * We will first declare two variables for storing linked list table. (#7.1)\n
 * Then, we will configure each data and link element with some dummy values. (#7.2)\n
 * The first ll table points to the second one and second one points to first. \n
 * Second element of second table has local interrupt enabled for interrupt reception. \n
 * The last element of second table toggles the cycle but for recycling (no recycling is actually done) and the operation is then complete.
 *
 *     \code
 *     //=====================================
 *     // 7. Configure linked list specific configuration of channel
 *     //=====================================
 *
 *     //=====================================
 *     // 7.1 Linked list variables
 *     //=====================================
 *
 *     IfxPcieDma_TxListDataElement *dataElementPtr;
 *     IfxPcieDma_TxListLinkElement *linkElementPtr;
 *
 *     // Refer to macro definition in code
 *     // "Locate" inside LMU so that DMA has access
 *     uint32 dmaWriteTransferList_1[IFXPCIEDMA_TRANSFER_LIST_ELEMENT_WORD_COUNT(3)] = {
 *         IFXPCIEDMA_TRANSFER_LIST_DATA_ELEMENT(0, 0, 0, 0, 0, 0),                       // Data Element 1, no Interrupts
 *         IFXPCIEDMA_TRANSFER_LIST_DATA_ELEMENT(0, 0, 0, 0, 0, 0),                       // Data Element 2, no Interrupt
 *         IFXPCIEDMA_TRANSFER_LIST_LINK_ELEMENT(0, 0, 0) };                              // Link Element shall Point to the next list, no recycle
 *
 *     uint32 dmaWriteTransferList_2[IFXPCIEDMA_TRANSFER_LIST_ELEMENT_WORD_COUNT(3)] = {
 *         IFXPCIEDMA_TRANSFER_LIST_DATA_ELEMENT(0, 0, 0, 0, 0, 0),                       // Data Element 1, no Interrupts
 *         IFXPCIEDMA_TRANSFER_LIST_DATA_ELEMENT(0, 0, 0, 1, 0, 0),                       // Data Element 2, local Interrupt
 *         IFXPCIEDMA_TRANSFER_LIST_LINK_ELEMENT(0, 0, 1) };                              // Link Element shall Point back to the first list, recycle
 *
 *     // Other variables with sample data
 *     uint32 fillDataAddr    = 0xb0300000;
 *     uint32 memSize         = 0x200;
 *     uint32 wireMem         = 0x8200;
 *     uint32 memSizeIncrStep = memSize >> 3; // 40
 *
 *     //=====================================
 *     // 7.2 Prepare data and link element for sending via DMA
 *     //=====================================
 *
 *     // Data element 1
 *     dataElementPtr                  = (IfxPcieDma_TxListDataElement *)&dmaWriteTransferList_1[0];
 *     dataElementPtr->sarHigh         = 0u;
 *     dataElementPtr->sarLow          = fillDataAddr;
 *     dataElementPtr->darHigh         = 0u;
 *     dataElementPtr->darLow          = wireMem;
 *     dataElementPtr->transferSize    = memSizeIncrStep;
 *
 *     // Data element 2
 *     dataElementPtr                  = (IfxPcieDma_TxListDataElement *)&dmaWriteTransferList_1[IFXPCIE_DMA_TRANSFER_LIST_ELEMENT_WORD_COUNT(1)];
 *     dataElementPtr->sarHigh         = 0u;
 *     dataElementPtr->sarLow          = fillDataAddr + memSizeIncrStep;
 *     dataElementPtr->darHigh         = 0u;
 *     dataElementPtr->darLow          = (wireMem + memSizeIncrStep);
 *     dataElementPtr->transferSize    = memSizeIncrStep;
 *
 *     // Link element 1
 *     linkElementPtr                  = (IfxPcieDma_TxListLinkElement *)&dmaWriteTransferList_1[IFXPCIE_DMA_TRANSFER_LIST_ELEMENT_WORD_COUNT(2)];
 *     linkElementPtr->LinkPtrHigh     = 0x0u;
 *     linkElementPtr->LinkPtrLow      = (uint32)&(dmaWriteTransferList_2[0]); // Point to second list
 *
 *     fillDataAddr                    = (uint32)fillDataAddr + (memSize >>2); // b0300080
 *     wireMem                         = wireMem + (memSize >> 2);             // 8280
 *
 *     // Data element 3
 *     dataElementPtr                  = (IfxPcieDma_TxListDataElement *)&dmaWriteTransferList_2[0];
 *     dataElementPtr->sarHigh         = 0u;
 *     dataElementPtr->sarLow          = fillDataAddr;
 *     dataElementPtr->darHigh         = 0u;
 *     dataElementPtr->darLow          = wireMem;
 *     dataElementPtr->transferSize    = memSizeIncrStep;
 *
 *     // Data element 4
 *     dataElementPtr                  = (IfxPcieDma_TxListDataElement *)&dmaWriteTransferList_2[IFXPCIE_DMA_TRANSFER_LIST_ELEMENT_WORD_COUNT(1)];
 *     dataElementPtr->sarHigh         = 0u;
 *     dataElementPtr->sarLow          = fillDataAddr + memSizeIncrStep;       // b03000A0
 *     dataElementPtr->darHigh         = 0u;
 *     dataElementPtr->darLow          = (wireMem + memSizeIncrStep);          // 82A0
 *     dataElementPtr->transferSize    = memSizeIncrStep;
 *
 *     // Link element 2
 *     linkElementPtr                  = (IfxPcieDma_TxListLinkElement *)&dmaWriteTransferList_2[IFXPCIE_DMA_TRANSFER_LIST_ELEMENT_WORD_COUNT(2)];
 *     linkElementPtr->LinkPtrHigh     = 0x0u;
 *     linkElementPtr->LinkPtrLow      = (uint32)&(dmaWriteTransferList_1[0]); // Point to first list
 *
 *     //=====================================
 *     // 7.3 Complete linked list specific configuration of channel
 *     //=====================================
 *
 *     dmaWriteChannelConfig.mode                                  = IfxPcieDma_ChannelMode_txList;
 *     dmaWriteChannelConfig.transferList.enableLocalErrorInt      = TRUE;     // Enable local interrupt
 *     dmaWriteChannelConfig.transferList.txListPtr                = &(dmaWriteTransferList_1[0]);
 *
 *     \endcode
 *
 * \subsection IfxLld_Pcie_Dma_Step4 STEP 4: Complete configuration & intialize DMA write channel
 *
 * In this section, we will complete the configuration and initialize channel (see below: #8 and #9).\n
 *
 *     \code
 *     //=====================================
 *     // 8. Complete configuration
 *     //=====================================
 *
 *     // 8.1 Configure local interrupt
 *     dmaWriteChannelConfig.interrupt.localIntNode.intVector      = IfxPcie_IntVector_dmaWrInt0;
 *     dmaWriteChannelConfig.interrupt.localIntNode.priority       = 2;                            // Choose priority according to interrupt handler
 *     dmaWriteChannelConfig.interrupt.localIntNode.typeOfService  = IfxSrc_Tos_cpu0;
 *     dmaWriteChannelConfig.interrupt.localIntNode.vmNumber       = IfxSrc_VmId_0;
 *
 *     // 8.2 [Optional] interrupt handler function (Define yourself)
 *     dmaWriteChannelConfig.interrupt.doneIntCallBack  = DmaWriteDoneInterruptHandler;
 *     dmaWriteChannelConfig.interrupt.abortIntCallBack = DmaWriteAbortInterruptHandler;
 *
 *     // 8.3 Complete configuration
 *     dmaWriteChannelConfig.pcieSFR = (Ifx_PCIE *)&(MODULE_PCIE_DSP);       // PCIe SFR
 *     dmaWriteChannelConfig.type    = IfxPcieDma_ChannelType_write;         // Operation Type
 *     dmaWriteChannelConfig.id      = IfxPcieDma_Channel_0;                 // Channel
 *
 *     //=====================================
 *     // 9. Initialize DMA Channel
 *     //=====================================
 *
 *     status = IfxPcieLib_Dma_initChannel(&dmaWriteChannel, &dmaWriteChannelConfig);
 *     \endcode
 *
 * \subsection IfxLld_Pcie_Dma_Step5 STEP 5: Start DMA channel
 *
 * In this section, we will start the DMA write channel (see below: #10).\n
 *
 *     \code
 *     //=====================================
 *     // 10. Start DMA Channel
 *     //=====================================
 *
 *     IfxPcieLib_Dma_startChannel(&dmaWriteChannel);
 *
 *     // Channel is now started
 *     // Insert code to wait for transfer to complete
 *
 *     \endcode
 *
 * \defgroup IfxLld_Pcie_Lib_Dma DMA
 * \ingroup IfxLld_Pcie_Lib
 * \defgroup IfxLld_Pcie_Lib_Dma_Enumerations Enumerations
 * \ingroup IfxLld_Pcie_Lib_Dma
 * \defgroup IfxLld_Pcie_Lib_Dma_Structures Structures
 * \ingroup IfxLld_Pcie_Lib_Dma
 * \defgroup IfxLld_Pcie_Lib_Dma_Functions Functions
 * \ingroup IfxLld_Pcie_Lib_Dma
 */

#ifndef IFXPCIELIB_DMA_H
#define IFXPCIELIB_DMA_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Pcie/Std/IfxPcieDma.h"
#include "Pcie/Lib/Device/IfxPcieLib_Device.h"
#include "_Impl/IfxPcie_cfg.h"

/******************************************************************************/
/*------------------------------Type Definitions------------------------------*/
/******************************************************************************/

/** \brief Type definition for DMA transfer interrupt callback functions
 * \return None
 */
typedef void (*IfxPcieLib_Dma_callback)(void);

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Pcie_Lib_Dma_Enumerations
 * \{ */
/** \brief DMA operation states
 */
typedef enum
{
    IfxPcieLib_Dma_State_unknown = -1,  /**< \brief Unknown state */
    IfxPcieLib_Dma_State_initialized,   /**< \brief DMA channel Initialized */
    IfxPcieLib_Dma_State_busy,          /**< \brief Channel busy */
    IfxPcieLib_Dma_State_halted,        /**< \brief Channel Halted */
    IfxPcieLib_Dma_State_error,         /**< \brief Driver fatal error */
    IfxPcieLib_Dma_State_configError    /**< \brief configuration Error */
} IfxPcieLib_Dma_State;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Pcie_Lib_Dma_Structures
 * \{ */
/** \brief DMA Channel TLP Config Bits
 */
typedef struct
{
    uint32 reserved_0 : 12;          /**< \brief Reserved */
    uint32 funcNum : 5;              /**< \brief Function Number */
    uint32 reserved_17 : 6;          /**< \brief Reserved */
    uint32 noSnoopWrite : 1;         /**< \brief No Snoop Write */
    uint32 noSnoopRead : 1;          /**< \brief No Snoop Read */
    uint32 relaxedOrdering : 1;      /**< \brief Relaxed Ordering Enabled */
    uint32 reserved_26 : 1;          /**< \brief Reserved */
    uint32 trafficClass : 3;         /**< \brief Traffic Class */
    uint32 addrTranslation : 2;      /**< \brief Address Translation Enabled */
} IfxPcieLib_Dma_TlpCfgBits;

/** \} */

/** \addtogroup IfxLld_Pcie_Lib_Dma_Structures
 * \{ */
/** \brief DMA Arbitration Configuration
 */
typedef struct
{
    IfxPcieDma_ChannelArbWeight readChannel[IFXPCIE_CFG_NUM_DMA_READ_CHANNELS];         /**< \brief Arbitration Weight for read channels */
    IfxPcieDma_ChannelArbWeight writeChannel[IFXPCIE_CFG_NUM_DMA_WRITE_CHANNELS];       /**< \brief Arbitration Weight for write channels */
} IfxPcieLib_Dma_ArbitrationCfg;

/** \brief DMA Channel Context
 */
typedef struct
{
    uint64 srcAddr;        /**< \brief Source Address */
    uint64 destAddr;       /**< \brief Destination Address */
    uint32 size;           /**< \brief Size in Bytes */
} IfxPcieLib_Dma_ChannelContext;

/** \brief DMA Channel Context Based configuration
 */
typedef struct
{
    uint64  srcAddr;               /**< \brief Source Address */
    uint64  destAddr;              /**< \brief Destination Address */
    uint32  size;                  /**< \brief Size of Transfer */
    boolean enableLocalInt;        /**< \brief if TRUE: Local Interrupt Enabled */
    boolean enableRemoteInt;       /**< \brief if TRUE: Remote Interrupt Enabled */
} IfxPcieLib_Dma_ChannelContextCfg;

/** \brief DMA Interrupt static configuration
 */
typedef struct
{
    IfxPcieLib_Device_IntNodeCfg localIntNode;            /**< \brief Local Interrupt node configuration */
    boolean                      maskLocalDoneInt;        /**< \brief Mask Local Done Interrupt */
    boolean                      maskLocalAbortInt;       /**< \brief Mask Local Abort Interrupt */
    IfxPcieLib_Dma_callback      doneIntCallBack;         /**< \brief Done Interrupt Callback Handler */
    IfxPcieLib_Dma_callback      abortIntCallBack;        /**< \brief Error Interrupt Callback Handler */
    uint16                       epModeMsiData;           /**< \brief Data to be written for (MSI(x)) Interrupt */
} IfxPcieLib_Dma_ChannelIntCfg;

/** \brief DMA MSI Address Configurations
 */
typedef struct
{
    uint64 readDone;         /**< \brief Remote Interrupt : Done MSI(x) Address */
    uint64 readAbort;        /**< \brief Remote Interrupt : Abort MSI(x) Address */
    uint64 writeDone;        /**< \brief Remote Interrupt : Done MSI(x) Address */
    uint64 writeAbort;       /**< \brief Remote Interrupt : Abort MSI(x) Address */
} IfxPcieLib_Dma_MsiAddrCfg;

/** \brief DMA Channel TLP configuration
 */
typedef union
{
    IfxPcieLib_Dma_TlpCfgBits B;       /**< \brief TLP Parameters Bits */
    uint32                    U;       /**< \brief TLP Parameters Word */
} IfxPcieLib_Dma_TlpCfg;

/** \brief DMA Transfer List Operation Context
 */
typedef struct
{
    uint32 *txListPtr;                 /**< \brief Transfer List Pointer */
    uint32 *currentTxElementPtr;       /**< \brief Current Transfer List Element */
} IfxPcieLib_Dma_TxList;

/** \brief DMA Transfer List Configuration
 */
typedef struct
{
    uint32 *txListPtr;                  /**< \brief Transfer List Pointer */
    boolean enableRemoteErrorInt;       /**< \brief Transfer List Remote Error Interrupt Enable */
    boolean enableLocalErrorInt;        /**< \brief Transfer List Local Error Interrupt Enable */
} IfxPcieLib_Dma_TxListCfg;

/** \} */

/** \addtogroup IfxLld_Pcie_Lib_Dma_Structures
 * \{ */
/** \brief DMA Handle
 */
typedef struct
{
    Ifx_PCIE_DSP_DMACAP *dmaSFR;       /**< \brief DMA SFR Pointer */
} IfxPcieLib_Dma;

/** \brief DMA Channel Handle
 */
typedef struct
{
    Ifx_PCIE_DSP_DMACAP          *dmaSFR;                 /**< \brief DMA SFR Pointer */
    IfxPcie                      *pcieSFR;                /**< \brief If locally configured, then PCIE SFR pointer is required. else, NULL_PTR */
    IfxPcieDma_Channel            id;                     /**< \brief DMA Channel ID */
    IfxPcieDma_ChannelType        type;                   /**< \brief Read/Write Type of Channel */
    IfxPcieDma_ChannelMode        mode;                   /**< \brief Mode of Operation */
    IfxPcieLib_Dma_ChannelContext context;                /**< \brief DMA Channel Operation Context */
    IfxPcieLib_Dma_TxList         transferList;           /**< \brief DMA Channel Operation Transfer List */
    IfxPcieDma_Error              errorStatus;            /**< \brief Enumeration Holding the current Error Status */
    IfxPcieLib_Dma_callback       doneIntCallBack;        /**< \brief Done Interrupt Callback Handler */
    IfxPcieLib_Dma_callback       abortIntCallBack;       /**< \brief Error Interrupt Callback Handler */
    IfxPcieLib_Dma_State          state;                  /**< \brief DMA Channel state */
} IfxPcieLib_Dma_Channel;

/** \brief DMA Channel configuration
 */
typedef struct
{
    Ifx_PCIE_DSP_DMACAP             *dmaSFR;             /**< \brief DMA SFR Pointer */
    IfxPcie                         *pcieSFR;            /**< \brief If locally configured, then PCIE SFR pointer is required. else, NULL_PTR */
    IfxPcieDma_Channel               id;                 /**< \brief DMA Channel ID */
    IfxPcieDma_ChannelType           type;               /**< \brief Read/Write Type of Channel */
    IfxPcieDma_ChannelMode           mode;               /**< \brief Mode of Operation */
    IfxPcieLib_Dma_TlpCfg            tlpParams;          /**< \brief DMA Channel TLP Parameters */
    IfxPcieLib_Dma_ChannelContextCfg context;            /**< \brief DMA Channel Operation Context Configuration */
    IfxPcieLib_Dma_TxListCfg         transferList;       /**< \brief DMA Channel Operation Transfer List */
    IfxPcieLib_Dma_ChannelIntCfg     interrupt;          /**< \brief DMA Channel Interrupt Configuration */
} IfxPcieLib_Dma_ChannelCfg;

/** \brief DMA configuration
 */
typedef struct
{
    Ifx_PCIE_DSP_DMACAP          *dmaSFR;            /**< \brief DMA SFR Pointer */
    IfxPcieLib_Dma_MsiAddrCfg     msiAddress;        /**< \brief MSI Address Configuration */
    IfxPcieLib_Dma_ArbitrationCfg arbitration;       /**< \brief Arbitration Weights */
} IfxPcieLib_Dma_Config;

/** \} */

/** \addtogroup IfxLld_Pcie_Lib_Dma_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Start the DMA Channel Transfers
 * \param dmaChannel pointer to the DMA Channel handle
 * \return None
 */
IFX_INLINE void IfxPcieLib_Dma_startChannel(IfxPcieLib_Dma_Channel *dmaChannel);

/** \brief Stop the DMA Channel Transfers
 * \param dmaChannel pointer to the DMA Channel handle
 * \return None
 */
IFX_INLINE void IfxPcieLib_Dma_stopChannel(IfxPcieLib_Dma_Channel *dmaChannel);

/** \brief Get the Transferred Size of data
 * \param dmaChannel pointer to the DMA Channel handle
 * \return number of bytes transferred
 */
IFX_INLINE uint32 IfxPcieLib_Dma_getTransferredSize(IfxPcieLib_Dma_Channel *dmaChannel);

/** \brief Get the Current Transfer List Pointer
 * \param dmaChannel pointer to the DMA Channel handle
 * \return pointer to the transfer list
 */
IFX_INLINE uint32 *IfxPcieLib_Dma_getCurrentTxListPtr(IfxPcieLib_Dma_Channel *dmaChannel);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initialize the DMA Module Configuration with default values
 * \param dmaCapSFR base pointer to the PCIE DMA SFR region
 * \param config pointer to the DMA module configuration
 * \return None
 */
IFX_EXTERN void IfxPcieLib_Dma_initModuleConfig(Ifx_PCIE_DSP_DMACAP *dmaCapSFR, IfxPcieLib_Dma_Config *config);

/** \brief Configure DMA module
 * \param dma pointer to the DMA handle
 * \param config pointer to the DMA configuration
 * \return Status of Initialization
 */
IFX_EXTERN IfxPcie_Status IfxPcieLib_Dma_initModule(IfxPcieLib_Dma *dma, IfxPcieLib_Dma_Config *config);

/** \brief Initialize the DMA Channel Configuration
 * \param dmaCapSFR base pointer to the PCIE DMA SFR region
 * \param dmaChannelCfg pointer to the DMA Channel configuration
 * \return None
 */
IFX_EXTERN void IfxPcieLib_Dma_initChannelConfig(Ifx_PCIE_DSP_DMACAP *dmaCapSFR, IfxPcieLib_Dma_ChannelCfg *dmaChannelCfg);

/** \brief Configure  DMA Channel
 * \param dmaChannel pointer to the DMA Channel handle
 * \param dmaChannelCfg pointer to the DMA Channel configuration
 * \return Status of Initialization
 */
IFX_EXTERN IfxPcie_Status IfxPcieLib_Dma_initChannel(IfxPcieLib_Dma_Channel *dmaChannel, IfxPcieLib_Dma_ChannelCfg *dmaChannelCfg);

/** \brief Update DMA Channel Context
 * \param dmaChannel pointer to the DMA Channel handle
 * \param srcAddr pointer to the Source Data
 * \param destAddr pointer to the Destination Data
 * \param size size of data to be transferred (in Bytes)
 * \return Status of Update
 */
IFX_EXTERN IfxPcie_Status IfxPcieLib_Dma_updateChannelContext(IfxPcieLib_Dma_Channel *dmaChannel, uint64 srcAddr, uint64 destAddr, uint32 size);

/** \brief Update DMA Channel Transfer List Pointer
 * \param dmaChannel pointer to the DMA Channel handle
 * \param txListPtr pointer to the Transfer List
 * \return Status of Update
 */
IFX_EXTERN IfxPcie_Status IfxPcieLib_Dma_updateChannelTxListPtr(IfxPcieLib_Dma_Channel *dmaChannel, uint32 *txListPtr);

/** \brief Interrupt Handler Function to do housekeeping, callback.
 * \param dmaChannel pointer to the DMA Channel handle
 * \return None
 */
IFX_EXTERN void IfxPcieLib_Dma_interruptHandler(IfxPcieLib_Dma_Channel *dmaChannel);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxPcieLib_Dma_startChannel(IfxPcieLib_Dma_Channel *dmaChannel)
{
    if (IfxPcieDma_getChannelStatus(dmaChannel->dmaSFR, dmaChannel->id, dmaChannel->type) != IfxPcieDma_ChannelStatus_running)
    {
        IfxPcieDma_startChannel(dmaChannel->dmaSFR, dmaChannel->id, dmaChannel->type);
        dmaChannel->state = IfxPcieLib_Dma_State_busy;
    }
}


IFX_INLINE void IfxPcieLib_Dma_stopChannel(IfxPcieLib_Dma_Channel *dmaChannel)
{
    IfxPcieDma_stopChannel(dmaChannel->dmaSFR, dmaChannel->id, dmaChannel->type);
    dmaChannel->state = IfxPcieLib_Dma_State_initialized;
}


IFX_INLINE uint32 IfxPcieLib_Dma_getTransferredSize(IfxPcieLib_Dma_Channel *dmaChannel)
{
    uint32 remaining_size   = 0x0u;
    uint32 transferred_size = 0x0u;

    remaining_size = IfxPcieDma_getTransferSize(dmaChannel->dmaSFR, dmaChannel->id, dmaChannel->type);

    if ((dmaChannel->mode == IfxPcieDma_ChannelMode_contextBased)
        && (dmaChannel->context.size != 0u))
    {
        transferred_size = dmaChannel->context.size - remaining_size;
    }

    return transferred_size;
}


IFX_INLINE uint32 *IfxPcieLib_Dma_getCurrentTxListPtr(IfxPcieLib_Dma_Channel *dmaChannel)
{
    uint32 *txListPtr = NULL_PTR;

    if ((dmaChannel->mode == IfxPcieDma_ChannelMode_txList)
        && (dmaChannel->transferList.txListPtr != 0x0u))
    {
        txListPtr = IfxPcieDma_getChannelCurrentTxListPtr(dmaChannel->dmaSFR, dmaChannel->id, dmaChannel->type);
    }

    dmaChannel->transferList.currentTxElementPtr = txListPtr;

    return txListPtr;
}


#endif /* IFXPCIELIB_DMA_H */
