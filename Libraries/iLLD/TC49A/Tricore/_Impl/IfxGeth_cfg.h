/**
 * \file IfxGeth_cfg.h
 * \brief GETH on-chip implementation data
 * \ingroup IfxLld_Geth
 *
 * \version iLLD_2_0_1_2_19
 * \copyright Copyright (c) 2020 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such
 * terms of use are agreed, use of this file is subject to following:
 *
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or
 * organization obtaining a copy of the software and accompanying
 * documentation covered by this license (the "Software") to use, reproduce,
 * display, distribute, execute, and transmit the Software, and to prepare
 * derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
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
 * Implementation layer
 *
 * \defgroup IfxLld_Geth GETH
 * \ingroup IfxLld
 * \defgroup IfxLld_Geth_Impl Implementation
 * \ingroup IfxLld_Geth
 * \defgroup IfxLld_Geth_Std Standard Driver
 * \ingroup IfxLld_Geth
 * \defgroup IfxLld_Geth_Impl_Enum Enumerations
 * \ingroup IfxLld_Geth_Impl
 */

#ifndef IFXGETH_CFG_H
#define IFXGETH_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "IfxGeth_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of Tx queues in MTL block
 */
#define IFXGETH_NUM_TX_QUEUES     (8)

/** \brief Number of Rx queues in MTL block
 */
#define IFXGETH_NUM_RX_QUEUES     (8)

/** \brief Number of Geth instances
 */
#define IFXGETH_NUM_MODULES       (1)

/** \brief Number of Tx DMA channels of DMA
 */
#define IFXGETH_NUM_TX_CHANNELS   (8)

/** \brief Number of Rx Channels of DMA
 */
#define IFXGETH_NUM_RX_CHANNELS   (8)

/** \brief Maximum timeout value to wait against at
 */
#define IFXGETH_MAX_TIMEOUT_VALUE (1000)

/** \brief MAX wait time for polling the MDIO transfer to complete
 */
#define IFXGETH_MDIO_MAX_TIMEOUT (1000)

/** \brief Value to clear the LPI status bits
 */
#define IFXGETH_LPI_STATUS_CLEAR (0x030F)

/** \brief Value to clear the PMT status bits
 */
#define IFXGETH_PMT_STATUS_CLEAR (0x0060)

/** \brief Value to clear the DMA status bits
 */
#define IFXGETH_DMA_INTERRUPT_STATUS_CLEAR (0xF3C7)

/** \brief Number of remote wakeup filter block's
 */
#define IFXGETH_NUM_RWKUP_FILTER_BLOCK (1)

/** \brief Number of remote wakeup filter's in each block
 */
#define IFXGETH_NUM_RWKUP_FILTER (4)

/** \brief MAX wait time for polling the LPI mode entry/exit status
 */
#define IFXGETH_LPI_MAX_TIMEOUT (1000)

/** \brief MAX wait time for polling the pointer to remote wakeup filter
 */
#define IFXGETH_RWKFLTRPTR_MAX_TIMEOUT (1000)

/** \brief MAX wait time for polling the L3/L4 register read/write transfer to complete
 */
#define IFXGETH_L3L4FILTER_MAX_TIMEOUT (1000)

/** \brief Number of DMA channels
 */
#define IFXGETH_NUM_DMA_CHANNELS  (8)

/** \brief Number of Ports
 */
#define IFXGETH_NUM_PORTS         (2)

/** \brief Enables Advanced Prototype APIs. (Temporary hack to protect SoCV testing and enable test development for PSV).
 */
#define IFXGETH_ADVANCED

/** \brief Number of Tx traffic classes in MTL block
 */
#define IFXGETH_NUM_TX_TRAFFIC_CLASSES     (8)
/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Geth_Impl_Enum
 * \{ */
/** \brief List of the available Geth instances
 */
typedef enum
{
    IfxGeth_Index_none = -1,  /**< \brief Not Selected */
    IfxGeth_Index_0    = 0,   /**< \brief GETH index 0  */
} IfxGeth_Index;

/** \brief Tx Traffic Class Index
 */
typedef enum
{
	IfxGeth_TxTrafficClass_0 = 0,  /**< \brief Traffic Class 0 */
	IfxGeth_TxTrafficClass_1 = 1,  /**< \brief Traffic Class 1 */
	IfxGeth_TxTrafficClass_2 = 2,  /**< \brief Traffic Class 2 */
	IfxGeth_TxTrafficClass_3 = 3,  /**< \brief Traffic Class 3 */
	IfxGeth_TxTrafficClass_4 = 4,  /**< \brief Traffic Class 4 */
	IfxGeth_TxTrafficClass_5 = 5,  /**< \brief Traffic Class 5 */
	IfxGeth_TxTrafficClass_6 = 6,  /**< \brief Traffic Class 6 */
	IfxGeth_TxTrafficClass_7 = 7   /**< \brief Traffic Class 7 */
} IfxGeth_TxTrafficClass;

/** \brief Tx Traffic Class Type
 */
typedef enum
{
	IfxGeth_TxTrafficClassType_0 = 0,  /**< \brief Traffic Class Type 0 with minimum features supported by H/w  */
	IfxGeth_TxTrafficClassType_1 = 1,  /**< \brief Traffic Class Type 1 with maximum features supported by H/w  */
} IfxGeth_TxTrafficClassType;

/** \brief Traffic Class Group Address, type and index map */
typedef struct
{
    volatile void 			  *trafficClassAddress;     /**< \brief Traffic Class Register Group Address */
    IfxGeth_TxTrafficClass     index;      				/**< \brief Traffic Class Index */
    IfxGeth_TxTrafficClassType type;                    /**< \brief Traffic Class Type */
} IfxGeth_TxTrafficClassMap;

/** \} */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxGeth_cfg_indexMap[IFXGETH_NUM_MODULES];

IFX_EXTERN IFX_CONST IfxGeth_TxTrafficClassMap IfxGeth_cfg_trafficClassMap[IFXGETH_NUM_PORTS][IFXGETH_NUM_TX_TRAFFIC_CLASSES];

#endif /* IFXGETH_CFG_H */
