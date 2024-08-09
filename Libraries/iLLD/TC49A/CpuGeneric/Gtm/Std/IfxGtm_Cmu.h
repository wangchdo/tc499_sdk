/**
 * \file IfxGtm_Cmu.h
 * \brief GTM  basic functionality
 * \ingroup IfxLld_Gtm
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
 * \defgroup IfxLld_Gtm_Std_Cmu Cmu Basic Functionality
 * \ingroup IfxLld_Gtm_Std
 * \defgroup IfxLld_Gtm_Std_Cmu_CMUEnumerations CMU Enumerations
 * \ingroup IfxLld_Gtm_Std_Cmu
 * \defgroup IfxLld_Gtm_Std_Cmu_CMU_Basic_Functions CMU Basic Functions
 * \ingroup IfxLld_Gtm_Std_Cmu
 */

#ifndef IFXGTM_CMU_H
#define IFXGTM_CMU_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxGtm_cfg.h"
#include "IfxGtm_bf.h"
#include "IfxGtm.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Gtm_Std_Cmu_CMUEnumerations
 * \{ */
typedef enum
{
    IfxGtm_Cmu_Clk_0 = 0,
    IfxGtm_Cmu_Clk_1,
    IfxGtm_Cmu_Clk_2,
    IfxGtm_Cmu_Clk_3,
    IfxGtm_Cmu_Clk_4,
    IfxGtm_Cmu_Clk_5,
    IfxGtm_Cmu_Clk_6,
    IfxGtm_Cmu_Clk_7
} IfxGtm_Cmu_Clk;

typedef enum
{
    IfxGtm_Cmu_Eclk_0 = 0,
    IfxGtm_Cmu_Eclk_1,
    IfxGtm_Cmu_Eclk_2
} IfxGtm_Cmu_Eclk;

typedef enum
{
    IfxGtm_Cmu_Fxclk_0 = 0,
    IfxGtm_Cmu_Fxclk_1,
    IfxGtm_Cmu_Fxclk_2,
    IfxGtm_Cmu_Fxclk_3,
    IfxGtm_Cmu_Fxclk_4
} IfxGtm_Cmu_Fxclk;

/** \brief Tim Filter counter frequency select
 */
typedef enum
{
    IfxGtm_Cmu_Tim_Filter_Clk_0,  /**< \brief FLT_CNT counts with CMU_CLK0 */
    IfxGtm_Cmu_Tim_Filter_Clk_1,  /**< \brief FLT_CNT counts with CMU_CLK1 */
    IfxGtm_Cmu_Tim_Filter_Clk_6,  /**< \brief FLT_CNT counts with CMU_CLK6 */
    IfxGtm_Cmu_Tim_Filter_Clk_7   /**< \brief FLT_CNT counts with CMU_CLK7 */
} IfxGtm_Cmu_Tim_Filter_Clk;

/** \} */

/** \addtogroup IfxLld_Gtm_Std_Cmu_CMU_Basic_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Enable / Disable the configurable, fixed, and external clocks
 * \param gtm Pointer to GTM module
 * \param clkMask Enable / Disable mask.
 * \return None
 */
IFX_INLINE void IfxGtm_Cmu_enableClocks(Ifx_GTM *gtm, uint32 clkMask);

/** \brief Returns the GTM global clock frequency in Hz
 * \param gtm Pointer to GTM module
 * \return GTM global clock frequency in Hz
 */
IFX_INLINE float32 IfxGtm_Cmu_getGclkFrequency(Ifx_GTM *gtm);

/** \brief returns the CMU module frequency in Hz. This is only for CMU module frequency.
 * For GTM SYS frequency: IfxGtm_getSysClkFrequency() is to be used.
 * \param gtm Pointer to GTM module
 * \return GTM module frequency in Hz
 */
IFX_INLINE float32 IfxGtm_Cmu_getModuleFrequency(Ifx_GTM *gtm);

/** \brief Returns the configurable clock enable status
 * \param gtm Pointer to GTM module
 * \param clkIndex Index of the configurable clock 0=CMU_CLK0, 1=CMU_CLK1, ...
 * \return TRUE The clock is enabled, FALSE The clock is disabled
 */
IFX_INLINE boolean IfxGtm_Cmu_isClkClockEnabled(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex);

/** \brief Returns the external clock enable status
 * \param gtm Pointer to GTM module
 * \param clkIndex Index of the external clock 0=CMU_ECLK0, 1=CMU_ECLK1, ...
 * \return TRUE The clock is enabled, FALSE The clock is disabled
 */
IFX_INLINE boolean IfxGtm_Cmu_isEclkClockEnabled(Ifx_GTM *gtm, IfxGtm_Cmu_Eclk clkIndex);

/** \brief Returns the fixed clock enable status
 * \param gtm Pointer to GTM module
 * \return TRUE The clock is enabled, FALSE The clock is disabled
 */
IFX_INLINE boolean IfxGtm_Cmu_isFxClockEnabled(Ifx_GTM *gtm);

/** \brief Select the clock input for CLK6 and CLK7
 * note The frequency can only be modified when the corresponding clock is disabled using IfxGtm_Cmu_enableClocks()
 * \param gtm Pointer to GTM module
 * \param clkIndex Index of the configurable clock 0=CMU_CLK0, 1=CMU_CLK1, ...
 * \param useGlobal if TRUE, uses the global clock as an input, else use the SUB_INC input
 * \return None
 */
IFX_INLINE void IfxGtm_Cmu_selectClkInput(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex, boolean useGlobal);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the GTM configurable clock frequency in Hz
 * \param gtm Pointer to GTM module
 * \param clkIndex Index of the configurable clock 0=CMU_CLK0, 1=CMU_CLK1, ...
 * \param assumeEnabled When TRUE, attempt to calculate the frequency as if the clock is enabled.
 * \return GTM configurable clock frequency in Hz
 */
IFX_EXTERN float32 IfxGtm_Cmu_getClkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex, boolean assumeEnabled);

/** \brief Returns the GTM external clock frequency in Hz
 * \param gtm Pointer to GTM module
 * \param clkIndex Index of the external clock 0=CMU_ECLK0, 1=CMU_ECLK1, ...
 * \param assumeEnabled When TRUE, attempt to calculate the frequency as if the clock is enabled.
 * \return GTM external clock frequency in Hz
 */
IFX_EXTERN float32 IfxGtm_Cmu_getEclkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Eclk clkIndex, boolean assumeEnabled);

/** \brief Returns the GTM fixed clock frequency in Hz
 * \param gtm Pointer to GTM module
 * \param clkIndex Index of the fixed clock 0=CMU_FXCLK0, 1=CMU_FXCLK1, ...
 * \param assumeEnabled When TRUE, attempt to calculate the frequency as if the clock is enabled.
 * \return GTM fixed clock frequency in Hz
 */
IFX_EXTERN float32 IfxGtm_Cmu_getFxClkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Fxclk clkIndex, boolean assumeEnabled);

/** \brief Set the GTM configurable clock frequency in Hz
 * \param gtm Pointer to GTM module
 * \param clkIndex Index of the configurable clock 0=CMU_CLK0, 1=CMU_CLK1, ...
 * \param frequency Frequency in Hz
 * \return None
 */
IFX_EXTERN void IfxGtm_Cmu_setClkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex, float32 frequency);

/** \brief Set the GTM external clock frequency in Hz
 * \param gtm Pointer to GTM module
 * \param clkIndex Index of the external clock 0=CMU_ECLK0, 1=CMU_ECLK1, ...
 * \param frequency Frequency in Hz
 * \return None
 */
IFX_EXTERN void IfxGtm_Cmu_setEclkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Eclk clkIndex, float32 frequency);

/** \brief Set the GTM global clock frequency in Hz
 * \param gtm Pointer to GTM module
 * \param frequency Frequency in Hz
 * \return None
 */
IFX_EXTERN void IfxGtm_Cmu_setGclkFrequency(Ifx_GTM *gtm, float32 frequency);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Sets the count value for the clock divider of a configurable clock divider block
 * Tcmu_clk[clkIndex] = (count + 1) * Tcmu_gclk_en
 * Note: Ensure CLSi_CMU_CLK_EN.EN_CLKx and CLSi_CMU_CLK_EN.EN_ECLKz (z=1) are disabled before calling this API. API doesn't perform any check.
 * \param gtm Pointer to GTM module
 * \param clkIndex Index of the configurable clock 0=CMU_CLK0, 1=CMU_CLK1, ...
 * \param count Count value for the clock divider
 * \return None
 */
IFX_INLINE void IfxGtm_Cmu_setClkCount(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex, uint32 count);

/** \brief Sets the numerator and denominator for External clock
 * Tcmu_eclk[clkIndex] = (numerator / denominator) * Tcls0_clk
 * Note: Ensure CLSi_CMU_CLK_EN.EN_ECLKz is disabled before calling this API. API doesn't perform any check.
 * \param gtm Pointer to GTM module
 * \param clkIndex Index of the external clock 0=CMU_ECLK0, 1=CMU_ECLK1, ...
 * \param numerator Numerator for external clock divider. Defines numerator of the fractional divider
 * \param denominator Denominator for external clock divider. Defines denominator of the fractional divider
 * \return None
 */
IFX_INLINE void IfxGtm_Cmu_setEclkDivider(Ifx_GTM *gtm, IfxGtm_Cmu_Eclk clkIndex, uint32 numerator, uint32 denominator);

/** \brief Sets the numerator and denominator for Global clock
 * Tcmu_gclk_en = (numerator / denominator) * Tcls0_clk
 * Note: Ensure CLSi_CMU_CLK_EN.EN_CLKx and CLSi_CMU_CLK_EN.EN_FXCLK are disabled before calling this API. API doesn't perform any check.
 * \param gtm Pointer to GTM module
 * \param numerator Numerator for global clock resolution generator. Defines numerator of the fractional divider.
 * \param denominator Denominator for global clock resolution generator. Defines denominator of the fractional divider.
 * \return None
 */
IFX_INLINE void IfxGtm_Cmu_setGclkDivider(Ifx_GTM *gtm, uint32 numerator, uint32 denominator);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxGtm_Cmu_enableClocks(Ifx_GTM *gtm, uint32 clkMask)
{
    gtm->CLS->CMU.CLK_EN.U = clkMask;
}


IFX_INLINE float32 IfxGtm_Cmu_getGclkFrequency(Ifx_GTM *gtm)
{
    uint32  N          = (uint32)gtm->CLS->CMU.GCLK_DEN.B.GCLK_DEN;
    uint32  Z          = (uint32)gtm->CLS->CMU.GCLK_NUM.B.GCLK_NUM;
    float32 multiplier = (float32)((float32)N / (float32)Z);

    return IfxGtm_Cmu_getModuleFrequency(gtm) * multiplier;
}


IFX_INLINE float32 IfxGtm_Cmu_getModuleFrequency(Ifx_GTM *gtm)
{
    return (float32)IfxGtm_getClusterFrequency(gtm, IfxGtm_Cluster_0); /* CMU module frequency is cluster 0 clock frequency */
}


IFX_INLINE boolean IfxGtm_Cmu_isClkClockEnabled(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex)
{
    boolean enabled;
    enabled = (((gtm->CLS->CMU.CLK_EN.U >> (2u * (uint8)clkIndex)) & IFX_GTM_CLS_CMU_CLK_EN_EN_CLK0_MSK) == 0x3) ? TRUE : FALSE;
    return enabled;
}


IFX_INLINE boolean IfxGtm_Cmu_isEclkClockEnabled(Ifx_GTM *gtm, IfxGtm_Cmu_Eclk clkIndex)
{
    boolean enabled;
    enabled = (((gtm->CLS->CMU.CLK_EN.U >> (2u * (uint8)clkIndex + 16u)) & IFX_GTM_CLS_CMU_CLK_EN_EN_CLK0_MSK) == 0x3) ? TRUE : FALSE;
    return enabled;
}


IFX_INLINE boolean IfxGtm_Cmu_isFxClockEnabled(Ifx_GTM *gtm)
{
    boolean enabled;
    enabled = (gtm->CLS->CMU.CLK_EN.B.EN_FXCLK == (uint8)0x3u) ? TRUE : FALSE;
    return enabled;
}


IFX_INLINE void IfxGtm_Cmu_selectClkInput(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex, boolean useGlobal)
{
    switch (clkIndex)
    {
    case IfxGtm_Cmu_Clk_6:
        gtm->CLS->CMU.CLK_6_CTRL.B.CLK_SEL = (useGlobal == TRUE) ? (uint8)0u : (uint8)1u;
        break;
    case IfxGtm_Cmu_Clk_7:
        gtm->CLS->CMU.CLK_7_CTRL.B.CLK_SEL = (useGlobal == TRUE) ? (uint8)0u : (uint8)1u;
        break;
    default:
        /* do nothing */
        break;
    }
}


IFX_INLINE void IfxGtm_Cmu_setClkCount(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex, uint32 count)
{
    switch (clkIndex)
    {
    case IfxGtm_Cmu_Clk_0:
        gtm->CLS->CMU.CLK0.CTRL.B.CLK_CNT = count;
        break;
    case IfxGtm_Cmu_Clk_1:
        gtm->CLS->CMU.CLK1.CTRL.B.CLK_CNT = count;
        break;
    case IfxGtm_Cmu_Clk_2:
        gtm->CLS->CMU.CLK2.CTRL.B.CLK_CNT = count;
        break;
    case IfxGtm_Cmu_Clk_3:
        gtm->CLS->CMU.CLK3.CTRL.B.CLK_CNT = count;
        break;
    case IfxGtm_Cmu_Clk_4:
        gtm->CLS->CMU.CLK4.CTRL.B.CLK_CNT = count;
        break;
    case IfxGtm_Cmu_Clk_5:
        gtm->CLS->CMU.CLK5.CTRL.B.CLK_CNT = count;
        break;
    case IfxGtm_Cmu_Clk_6:
        gtm->CLS->CMU.CLK_6_CTRL.B.CLK_CNT = count;
        break;
    case IfxGtm_Cmu_Clk_7:
        gtm->CLS->CMU.CLK_7_CTRL.B.CLK_CNT = count;
        break;
    default:
        /* do nothing */
        break;
    }
}


IFX_INLINE void IfxGtm_Cmu_setEclkDivider(Ifx_GTM *gtm, IfxGtm_Cmu_Eclk clkIndex, uint32 numerator, uint32 denominator)
{
    /* From UM: The CMU hardware alters the content of CLSi_CMU_ECLKz_NUM and CLSi_CMU_ECLKz_DEN automatically to 1H,
     * if CLSi_CMU_ECLKz_NUM is specified less than CLSi_CMU_ECLKz_DEN or one of the values is specified with
     * a value zero. Thus, a secure way for altering the values is writing twice to the register
     * CLSi_CMU_ECLKz_NUM followed by a single write to register CLSi_CMU_ECLKz_DEN
     */
    gtm->CLS->CMU.ECLK[clkIndex].NUM.U = numerator;
    gtm->CLS->CMU.ECLK[clkIndex].NUM.U = numerator;
    gtm->CLS->CMU.ECLK[clkIndex].DEN.U = denominator;
}


IFX_INLINE void IfxGtm_Cmu_setGclkDivider(Ifx_GTM *gtm, uint32 numerator, uint32 denominator)
{
    /* From UM: The CMU hardware alters the content of CLSi_CMU_GCLK_NUM and CLSi_CMU_GCLK_DEN automatically to 1H,
     * if CLSi_CMU_GCLK_NUM.GCLK_NUM is specified less than CLSi_CMU_GCLK_DEN.GCLK_DEN or one of the
     * values is specified with a value zero. Thus, a secure way for altering the values is writing twice to the register
     * CLSi_CMU_GCLK_NUM followed by a single write to register CLSi_CMU_GCLK_DEN
     */
    gtm->CLS->CMU.GCLK_NUM.U = numerator;
    gtm->CLS->CMU.GCLK_NUM.U = numerator;
    gtm->CLS->CMU.GCLK_DEN.U = denominator;
}


#endif /* IFXGTM_CMU_H */
