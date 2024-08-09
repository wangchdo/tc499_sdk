/**
 * \file Ifx_LutIndexedLinearF32.h
 * \brief Look-up functionality
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
 * \defgroup library_srvsw_sysse_math_f32_lut_indexedLinear Indexes look-up table (with linear interpolation)
 * \ingroup library_srvsw_sysse_math_f32_lut
 *
 */

#ifndef IFX_LUTINDEXEDLINEARF32_H
#define IFX_LUTINDEXEDLINEARF32_H

//________________________________________________________________________________________
// INCLUDES
#include "Cpu/Std/Ifx_Types.h"

typedef struct
{
    float32 gain;        /**< \brief channel gain */
    float32 offset;      /**< \brief channel offset */
} Ifx_LutIndexedLinearF32_Item;

typedef struct
{
    uint16                                segmentCount;
    sint8                                 shift;
    const Ifx_LutIndexedLinearF32_Item *segments;
} Ifx_LutIndexedLinearF32;

//________________________________________________________________________________________
// FUNCTION PROTOTYPES

/** \addtogroup library_srvsw_sysse_math_f32_lut_indexedLinear
 * \{ */
IFX_INLINE float32 Ifx_LutIndexedLinearF32_search(const Ifx_LutIndexedLinearF32 *ml, uint32 index);
/** \} */

//________________________________________________________________________________________
// INLINE FUNCTION IMPLEMENTATION

/** \brief Look-up table search
*
*
* \param ml pointer to the multi-segment object
* \param index
* \return interpolated value */
IFX_INLINE float32 Ifx_LutIndexedLinearF32_search(const Ifx_LutIndexedLinearF32 *ml, uint32 index)
{
    uint32 i;
    i = index >> ml->shift;

    return (ml->segments[i].gain * index) + ml->segments[i].offset;
}


#endif /* IFX_LUTINDEXEDLINEARF32_H */
