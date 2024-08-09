/**
 * \file Ifx_LutLSincosF32.h
 * \brief Sin/Cos linear approximated lookup functions with fixed-point angle data type
 * \ingroup library_srvsw_sysse_math_lut_lsincos
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
 * \defgroup library_srvsw_sysse_math_lut_lsincos Linear trigonometric Look-ups
 * \ingroup library_srvsw_sysse_math_f32_lut
 *
 */

#ifndef IFX_LUTLSINCOSF32_H
#define IFX_LUTLSINCOSF32_H
//________________________________________________________________________________________

#include "SysSe/Math/IFX_Cf32.h"
#include "Ifx_Lut.h"
#include "Ifx_LutIndexedLinearF32.h"
//________________________________________________________________________________________

/**
 * \brief Look-up table for sin */
IFX_EXTERN const Ifx_LutIndexedLinearF32 Ifx_g_LutLSincosF32;

/**
 * \brief Sine lookup function
 * \param fxpAngle 0 .. (IFX_LUT_ANGLE_RESOLUTION - 1)
 * \return sin(2*IFX_PI*fxpAngle/IFX_LUT_ANGLE_RESOLUTION)
 * \ingroup library_srvsw_sysse_math_lut_lsincos
 */
IFX_INLINE float32 Ifx_LutLSincosF32_sin(Ifx_Lut_FxpAngle fxpAngle)
{
    fxpAngle = fxpAngle & (IFX_LUT_ANGLE_RESOLUTION - 1);

    return Ifx_LutIndexedLinearF32_search(&Ifx_g_LutLSincosF32, fxpAngle);
}


/**
 * \brief Cosine lookup function
 * \param fxpAngle 0 .. (IFX_LUT_ANGLE_RESOLUTION - 1), which represents 0 .. 2*IFX_PI
 * \return cos(2*IFX_PI*fxpAngle/IFX_LUT_ANGLE_RESOLUTION)
 * \ingroup library_srvsw_sysse_math_lut_lsincos
 */
IFX_INLINE float32 Ifx_LutLSincosF32_cos(Ifx_Lut_FxpAngle fxpAngle)
{
    return Ifx_LutLSincosF32_sin((IFX_LUT_ANGLE_PI / 2) - fxpAngle);
}


/**
 * \brief Sine and Cosine lookup function
 * \param fxpAngle 0 .. (IFX_LUT_ANGLE_RESOLUTION - 1), which represents 0 .. 2*IFX_PI
 * \retval real = cos(2*IFX_PI*fxpAngle/IFX_LUT_ANGLE_RESOLUTION)
 * \retval imag = sin(2*IFX_PI*fxpAngle/IFX_LUT_ANGLE_RESOLUTION)
 * \ingroup library_srvsw_sysse_math_lut_lsincos
 */
IFX_INLINE cfloat32 Ifx_LutLSincosF32_cossin(Ifx_Lut_FxpAngle fxpAngle)
{
    cfloat32 result;
    result.imag = Ifx_LutLSincosF32_sin(fxpAngle);
    result.real = Ifx_LutLSincosF32_sin((IFX_LUT_ANGLE_PI / 2) - fxpAngle);
    return result;
}


//________________________________________________________________________________________
#endif
