/**
 * \file Ifx_Lut.h
 * \brief Lookup defintion with fixed-point angle data type
 *
 *
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
 * \defgroup library_srvsw_sysse_math_lut Look-ups
 * \ingroup library_srvsw_sysse_math
 *
 * \defgroup library_srvsw_sysse_math_f32_lut Look-ups float32
 * \ingroup library_srvsw_sysse_math_lut
 *
 */
#ifndef IFX_LUT_H
#define IFX_LUT_H
//________________________________________________________________________________________
#include "Cpu/Std/IfxCpu_Intrinsics.h"
//________________________________________________________________________________________
#ifndef IFX_LUT_TABLE_CONST
/** \brief 0 = Lookup tables are generated and stored in RAM,
 * 1 = Lookup tables are precompiled and stored in FLASH */
#define IFX_LUT_TABLE_CONST (1)
#endif

#if (IFX_LUT_TABLE_CONST != 0)
/** \brief Lookup table type modifier (stored in ROM) */
#   define IFX_LUT_TABLE    const
#else
/** \brief Lookup table type modifier (stored in RAM) */
#   define IFX_LUT_TABLE
#endif

/** \brief Define the resolution (in bits) of cosinus and sinus table \ingroup library_srvsw_sysse_math_lut */
#define IFX_LUT_ANGLE_BITS       (12)

/** \brief Define the cosinus and sinus table size \ingroup library_srvsw_sysse_math_lut */
#define IFX_LUT_ANGLE_RESOLUTION (1 << IFX_LUT_ANGLE_BITS)

/** \brief Value used as 180 degree angle */
#define IFX_LUT_ANGLE_PI         (IFX_LUT_ANGLE_RESOLUTION / 2)

//________________________________________________________________________________________
/** \brief Fixed-point angle type.
 *
 * Resolution is defined by \ref IFX_LUT_ANGLE_RESOLUTION */
typedef sint32 Ifx_Lut_FxpAngle;

/** \brief Convert from float32 angle in radian into fixed-point angle type */
#define IFX_LUT_F32_TO_FXPANGLE(f)  ((Ifx_Lut_FxpAngle)(f / IFX_PI * IFX_LUT_ANGLE_PI))

/** \brief Convert from fixed-point angle type to float32 angle in radian */
#define IFX_LUT_FXPANGLE_TO_F32(fx) ((float32)fx * IFX_PI / IFX_LUT_ANGLE_PI)

//________________________________________________________________________________________
#if (1U << IFX_LUT_ANGLE_BITS) != IFX_LUT_ANGLE_RESOLUTION
#error (1U << IFX_LUT_ANGLE_BITS) != IFX_LUT_ANGLE_RESOLUTION
#endif
//________________________________________________________________________________________
#endif /* IFX_LUT_H */
