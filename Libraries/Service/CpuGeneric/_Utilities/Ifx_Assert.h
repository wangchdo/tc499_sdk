/**
 * \file Ifx_Assert.h
 * \brief Assert functions.
 * \ingroup library_srvsw_utilities_assert
 *
 * \version iLLD_2_0_1_2_19
 * \copyright Copyright (c) 2019 Infineon Technologies AG. All rights reserved.
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
 * \defgroup library_srvsw_utilities_assert Assertion
 * This module implements assertion functions.
 * \ingroup library_srvsw_utilities
 *
 */

#ifndef IFX_ASSERT_H
#define IFX_ASSERT_H 1

#include "Ifx_Cfg.h"                           /* Do not remove this include */
#include "Cpu/Std/Ifx_Types.h"                 /* Do not remove this include */

/** \addtogroup library_srvsw_utilities_assert
 * \{ */

#define IFX_VERBOSE_LEVEL_OFF              (0) /**< \brief Assertion level off, assertion is disabled */
#define IFX_VERBOSE_LEVEL_FAILURE          (1) /**< \brief Assertion level failure, a debug instruction is inserted if enabled */
#define IFX_VERBOSE_LEVEL_ERROR            (2) /**< \brief Assertion level error, a debug instruction is inserted if enabled */
#define IFX_VERBOSE_LEVEL_WARNING          (3) /**< \brief Assertion level warning */
#define IFX_VERBOSE_LEVEL_INFO             (4) /**< \brief Assertion level info */
#define IFX_VERBOSE_LEVEL_DEBUG            (5) /**< \brief Assertion level debug */

/** \brief Constant to be used to indicate  not implemented feature */
#define IFX_ASSERT_FEATURE_NOT_IMPLEMENTED (FALSE)
/** \brief Feature is not available on the selected hardware */
#define IFX_ASSERT_FEATURE_NOT_AVAILABLE   (FALSE)

#ifndef IFX_ASSERT
#    define IFX_ASSERT(level, expr)   ((void)0)
#endif

#ifndef IFX_VALIDATE
#    define IFX_VALIDATE(level, expr) (expr)
#endif

#ifdef IFX_CFG_ASSERT_INCLUDE
/** Configuration switch: IFX_CFG_ASSERT_INCLUDE
 * This switch is used to enable user defined assertion implementation.
 * A usage exmaple is given below:
 *
 * \code
 * // File "Ifx_Cfg.h"
 * #define IFX_CFG_ASSERT_INCLUDE  "SysSe/Bsp/Assert.h"
 * \endcode
 */
#include IFX_CFG_ASSERT_INCLUDE
#endif
/** \} */

#endif
