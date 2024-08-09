/**
 * \file Ifx_Ssw_Compilers.h
 * \brief Startup Software for compiler options
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

#ifndef IFX_SSW_COMPILERS_H_
#define IFX_SSW_COMPILERS_H_

/*Macro definition to show HighTec macros with the editor*/
#if ((!defined(__ghs__)) && (!defined(__DCC__)) && (!defined(__TASKING__)) && (!defined(__GNUC__)))
#define __HIGHTEC__
#define __clang__
#endif

/*Include files for each compiler*/
#if defined(__TASKING__)
#include "Ifx_Ssw_CompilersTasking.h"

#elif __DCC__
#include "Ifx_Ssw_CompilersDcc.h"

#elif defined(__HIGHTEC__) && !defined(__clang__)
#include "Ifx_Ssw_CompilersGnuc.h"

#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#include "Ifx_Ssw_CompilersGcc.h"

#elif defined(__HIGHTEC__) && defined(__clang__)
#include "Ifx_Ssw_CompilersHighTec.h"

#elif defined(__ghs__)
#include "Ifx_Ssw_CompilersGhs.h"
#endif

#define IFX_SSW_USED __attribute__((used))

#ifndef NULL_PTR
#ifdef __cplusplus
#define NULL_PTR        (0)
#else /*#ifdef __cplusplus */
#define NULL_PTR        ((void *)0)
#endif /*#ifdef __cplusplus */
#endif /*#ifndef NULL_PTR */

#endif /* IFX_SSW_COMPILERS_H_ */
