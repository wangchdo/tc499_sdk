/**
 * \file Ifx_Ssw_LegacySwCfg.h
 * \brief Startup Software to support legacy controller options.
 *
 * \version iLLD_2_0_1_2_19
 * \copyright Copyright (c) 2023 Infineon Technologies AG. All rights reserved.
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
 */

#ifndef IFX_SSW_DEFAULTCFG_H_
#define IFX_SSW_DEFAULTCFG_H_

#include "Ifx_Cfg.h"

/******************************************************************************/
/*                        Macros to support Legacy SW                         */
/******************************************************************************/
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE0
#   define IFX_CFG_SSW_ENABLE_TRICORE0        IFX_CFG_CPU_CSTART_ENABLE_TRICORE0
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE1
#   define IFX_CFG_SSW_ENABLE_TRICORE1        IFX_CFG_CPU_CSTART_ENABLE_TRICORE1
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE2
#   define IFX_CFG_SSW_ENABLE_TRICORE2        IFX_CFG_CPU_CSTART_ENABLE_TRICORE2
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE3
#   define IFX_CFG_SSW_ENABLE_TRICORE3        IFX_CFG_CPU_CSTART_ENABLE_TRICORE3
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE4
#   define IFX_CFG_SSW_ENABLE_TRICORE4        IFX_CFG_CPU_CSTART_ENABLE_TRICORE4
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE5
#   define IFX_CFG_SSW_ENABLE_TRICORE5        IFX_CFG_CPU_CSTART_ENABLE_TRICORE5
#endif

#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE0_PCACHE
#   define IFX_CFG_SSW_ENABLE_TRICORE0_PCACHE IFX_CFG_CPU_CSTART_ENABLE_TRICORE0_PCACHE
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE0_DCACHE
#   define IFX_CFG_SSW_ENABLE_TRICORE0_DCACHE IFX_CFG_CPU_CSTART_ENABLE_TRICORE0_DCACHE
#endif

#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE1_PCACHE
#   define IFX_CFG_SSW_ENABLE_TRICORE1_PCACHE IFX_CFG_CPU_CSTART_ENABLE_TRICORE1_PCACHE
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE1_DCACHE
#   define IFX_CFG_SSW_ENABLE_TRICORE1_DCACHE IFX_CFG_CPU_CSTART_ENABLE_TRICORE1_DCACHE
#endif

#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE2_PCACHE
#   define IFX_CFG_SSW_ENABLE_TRICORE2_PCACHE IFX_CFG_CPU_CSTART_ENABLE_TRICORE2_PCACHE
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE2_DCACHE
#   define IFX_CFG_SSW_ENABLE_TRICORE2_DCACHE IFX_CFG_CPU_CSTART_ENABLE_TRICORE2_DCACHE
#endif

#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE3_PCACHE
#   define IFX_CFG_SSW_ENABLE_TRICORE3_PCACHE IFX_CFG_CPU_CSTART_ENABLE_TRICORE3_PCACHE
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE3_DCACHE
#   define IFX_CFG_SSW_ENABLE_TRICORE3_DCACHE IFX_CFG_CPU_CSTART_ENABLE_TRICORE3_DCACHE
#endif

#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE4_PCACHE
#   define IFX_CFG_SSW_ENABLE_TRICORE4_PCACHE IFX_CFG_CPU_CSTART_ENABLE_TRICORE4_PCACHE
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE4_DCACHE
#   define IFX_CFG_SSW_ENABLE_TRICORE4_DCACHE IFX_CFG_CPU_CSTART_ENABLE_TRICORE4_DCACHE
#endif

#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE5_PCACHE
#   define IFX_CFG_SSW_ENABLE_TRICORE5_PCACHE IFX_CFG_CPU_CSTART_ENABLE_TRICORE5_PCACHE
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE5_DCACHE
#   define IFX_CFG_SSW_ENABLE_TRICORE5_DCACHE IFX_CFG_CPU_CSTART_ENABLE_TRICORE5_DCACHE
#endif

#ifndef USE_LEGACY_ILLD_DEFINES
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE0
#error Unsupported legacy constant 'IFX_CFG_CPU_CSTART_ENABLE_TRICORE0' defined! Use 'IFX_CFG_SSW_CSTART_ENABLE_TRICORE0' instead!
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE1
#error Unsupported legacy constant 'IFX_CFG_CPU_CSTART_ENABLE_TRICORE1' defined! Use 'IFX_CFG_SSW_CSTART_ENABLE_TRICORE1' instead!
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE2
#error Unsupported legacy constant 'IFX_CFG_CPU_CSTART_ENABLE_TRICORE2' defined! Use 'IFX_CFG_SSW_CSTART_ENABLE_TRICORE2' instead!
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE3
#error Unsupported legacy constant 'IFX_CFG_CPU_CSTART_ENABLE_TRICORE3' defined! Use 'IFX_CFG_SSW_CSTART_ENABLE_TRICORE3' instead!
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE4
#error Unsupported legacy constant 'IFX_CFG_CPU_CSTART_ENABLE_TRICORE4' defined! Use 'IFX_CFG_SSW_CSTART_ENABLE_TRICORE4' instead!
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE5
#error Unsupported legacy constant 'IFX_CFG_CPU_CSTART_ENABLE_TRICORE5' defined! Use 'IFX_CFG_SSW_CSTART_ENABLE_TRICORE5' instead!
#endif

#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE0_PCACHE
#error Unsupported legacy constant 'IFX_CFG_CPU_CSTART_ENABLE_TRICORE0_PCACHE' defined! Use 'IFX_CFG_SSW_ENABLE_TRICORE0_PCACHE' instead!
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE0_DCACHE
#error Unsupported legacy constant 'IFX_CFG_CPU_CSTART_ENABLE_TRICORE0_DCACHE' defined! Use 'IFX_CFG_SSW_ENABLE_TRICORE0_DCACHE' instead!
#endif

#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE1_PCACHE
#error Unsupported legacy constant 'IFX_CFG_CPU_CSTART_ENABLE_TRICORE1_PCACHE' defined! Use 'IFX_CFG_SSW_ENABLE_TRICORE1_PCACHE' instead!
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE1_DCACHE
#error Unsupported legacy constant 'IFX_CFG_CPU_CSTART_ENABLE_TRICORE1_DCACHE' defined! Use 'IFX_CFG_SSW_ENABLE_TRICORE1_DCACHE' instead!
#endif

#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE2_PCACHE
#error Unsupported legacy constant 'IFX_CFG_CPU_CSTART_ENABLE_TRICORE2_PCACHE' defined! Use 'IFX_CFG_SSW_ENABLE_TRICORE2_PCACHE' instead!
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE2_DCACHE
#error Unsupported legacy constant 'IFX_CFG_CPU_CSTART_ENABLE_TRICORE2_DCACHE' defined! Use 'IFX_CFG_SSW_ENABLE_TRICORE2_DCACHE' instead!
#endif

#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE3_PCACHE
#error Unsupported legacy constant 'IFX_CFG_CPU_CSTART_ENABLE_TRICORE3_PCACHE' defined! Use 'IFX_CFG_SSW_ENABLE_TRICORE3_PCACHE' instead!
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE3_DCACHE
#error Unsupported legacy constant 'IFX_CFG_CPU_CSTART_ENABLE_TRICORE3_DCACHE' defined! Use 'IFX_CFG_SSW_ENABLE_TRICORE3_DCACHE' instead!
#endif

#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE4_PCACHE
#error Unsupported legacy constant 'IFX_CFG_CPU_CSTART_ENABLE_TRICORE4_PCACHE' defined! Use 'IFX_CFG_SSW_ENABLE_TRICORE4_PCACHE' instead!
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE4_DCACHE
#error Unsupported legacy constant 'IFX_CFG_CPU_CSTART_ENABLE_TRICORE4_DCACHE' defined! Use 'IFX_CFG_SSW_ENABLE_TRICORE4_DCACHE' instead!
#endif

#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE5_PCACHE
#error Unsupported legacy constant 'IFX_CFG_CPU_CSTART_ENABLE_TRICORE5_PCACHE' defined! Use 'IFX_CFG_SSW_ENABLE_TRICORE5_PCACHE' instead!
#endif
#ifdef IFX_CFG_CPU_CSTART_ENABLE_TRICORE5_DCACHE
#error Unsupported legacy constant 'IFX_CFG_CPU_CSTART_ENABLE_TRICORE5_DCACHE' defined! Use 'IFX_CFG_SSW_ENABLE_TRICORE5_DCACHE' instead!
#endif
#endif /* USE_LEGACY_ILLD_DEFINES */

#endif /* IFX_SSW_DEFAULTCFG_H_ */
