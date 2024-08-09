/**
 * \file IfxEgtm_Tim_Timer.h
 * \brief EGTM TIMER details
 * \ingroup IfxLld_Egtm
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
 * \defgroup IfxLld_Egtm_Tim_Timer Tim Timer Interface
 * \ingroup IfxLld_Egtm_Tim
 * \defgroup IfxLld_Egtm_Tim_Timer_Structures TIM Timer Structures
 * \ingroup IfxLld_Egtm_Tim_Timer
 * \defgroup IfxLld_Egtm_Tim_Timer_Functions TIM Timer Functions
 * \ingroup IfxLld_Egtm_Tim_Timer
 */

#ifndef IFXEGTM_TIM_TIMER_H
#define IFXEGTM_TIM_TIMER_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Egtm/Std/IfxEgtm_Tim.h"
#include "Egtm/Std/IfxEgtm_Cmu.h"
#include "_Impl/IfxEgtm_cfg.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Egtm_Tim_Timer_Structures
 * \{ */
/** \brief Tim handle data structure
 */
typedef struct
{
    Ifx_EGTM         *egtm;           /**< \brief Pointer to EGTM module */
    Ifx_EGTM_CLS_TIM *tim;            /**< \brief Pointer to TIM module */
    IfxEgtm_Cluster   clsIndex;       /**< \brief Specifies the CLS module no */
    IfxEgtm_Tim_Ch    channel;        /**< \brief Tim channel no */
} IfxEgtm_Tim_Timer;

/** \brief Tim configuration data structure
 */
typedef struct
{
    IfxEgtm_Cluster               clsIndex;                         /**< \brief Specifies the CLS instance number */
    IfxEgtm_Tim_Ch                channel;                          /**< \brief Tim channel no */
    IfxEgtm_Tim_ChannelControl    channelControl;                   /**< \brief Control configuration */
    uint32                        raisingEdgeFilterTime;            /**< \brief Filter Raising Edge parameter */
    uint32                        fallingEdgeFilterTime;            /**< \brief Filter Falling Edge parameter */
    uint32                        shadowCounter;                    /**< \brief Shadow counter value */
    boolean                       irqEnable;                        /**< \brief enable interrupt notification */
    IfxEgtm_IrqMode               irqMode;                          /**< \brief interrupt mode (level/pulse/pulse notify/single pulse) */
    IfxEgtm_Tim_IrqType           irqType;                          /**< \brief interrupt type (new value/ ecnt overflow/ gpr overflow/ cnt overflow / TO detect / glitch detect) */
    IfxEgtm_Tim_InputSourceSelect inputSourceSelect;                /**< \brief input source selection (mode , Value) */
    boolean                       enableAuxInputSourceSelect;       /**< \brief enable Auxiliary input source selection */
} IfxEgtm_Tim_Timer_Config;

/** \} */

/** \addtogroup IfxLld_Egtm_Tim_Timer_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief initializes the TIM channel object
 * \param driver TOM Timer interface Handle
 * \param config Configuration structure for TIM
 * \return None
 */
IFX_EXTERN void IfxEgtm_Tim_Timer_initChannel(IfxEgtm_Tim_Timer *driver, IfxEgtm_Tim_Timer_Config *config);

/** \brief initialize the config struct with default TIM channel configuration
 * \param config pointer to the TIM Channel configuration (it will be initialized by this function)
 * \param egtm Pointer to EGTM module
 * \return None
 */
IFX_EXTERN void IfxEgtm_Tim_Timer_initChannelConfig(IfxEgtm_Tim_Timer_Config *config, Ifx_EGTM *egtm);

/** \} */

#endif /* IFXEGTM_TIM_TIMER_H */
