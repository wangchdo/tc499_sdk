/**
 * \file IfxStm_cfg.h
 * \brief STM on-chip implementation data
 * \ingroup IfxLld_Stm
 *
 * \version iLLD_2_0_1_2_19
 * \copyright Copyright (c) 2021 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Stm STM
 * \ingroup IfxLld
 * \defgroup IfxLld_Stm_Impl Implementation
 * \ingroup IfxLld_Stm
 * \defgroup IfxLld_Stm_Std Standard Driver
 * \ingroup IfxLld_Stm
 * \defgroup IfxLld_Stm_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Stm_Impl
 * \defgroup IfxLld_Stm_Impl_Variables Global Variables
 * \ingroup IfxLld_Stm_Impl
 */

#ifndef IFXSTM_CFG_H
#define IFXSTM_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "IfxCpu_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief STM count
 */
#define IFXSTM_NUM_MODULES     7

/** \brief No Of Comparators per Stm
 */
#define IFXSTM_NUM_COMPARATORS (2)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Stm_Impl_Enumerations
 * \{ */
/** \brief List of the available STM resources
 */
typedef enum
{
    IfxStm_Index_none = -1,  /**< \brief Not Selected */
    IfxStm_Index_0    = 0,   /**< \brief STM index 0 */
    IfxStm_Index_1    = 1,   /**< \brief STM index 1 */
    IfxStm_Index_2    = 2,   /**< \brief STM index 2 */
    IfxStm_Index_3    = 3,   /**< \brief STM index 3 */
    IfxStm_Index_4    = 4,   /**< \brief STM index 4 */
    IfxStm_Index_5    = 5,   /**< \brief STM index 5 */
    IfxStm_Index_6    = 6    /**< \brief STM index 6 */
} IfxStm_Index;

/** \} */

/** \addtogroup IfxLld_Stm_Impl_Variables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxStm_cfg_indexMap[IFXSTM_NUM_MODULES];

/** \} */

#endif /* IFXSTM_CFG_H */
