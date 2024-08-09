/**
 * \file IfxFce.h
 * \brief FCE  basic functionality
 * \ingroup IfxLld_Fce
 *
 * \version iLLD_2_0_1_2_19
 * \copyright Copyright (c) 2022 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Fce_Std_Enum Enumerations
 * \ingroup IfxLld_Fce_Std
 * \defgroup IfxLld_Fce_Std_Module Module Functions
 * \ingroup IfxLld_Fce_Std
 * \defgroup IfxLld_Fce_Std_Support Support Function
 * \ingroup IfxLld_Fce_Std
 * \defgroup IfxLld_Fce_Std_InterruptStatus Interrupt Status Functions
 * \ingroup IfxLld_Fce_Std
 */

#ifndef IFXFCE_H
#define IFXFCE_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxFce_cfg.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "IfxFce_reg.h"
#include "Src/Std/IfxSrc.h"
#include "Ap/Std/IfxApProt.h"
#include "Ap/Std/IfxApApu.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Fce_Std_Enum
 * \{ */
/** \brief Ifx_FCE_CHx(x= 0,1), Specifies the channel used for CRC
 */
typedef enum
{
    IfxFce_CrcChannel_0 = 0,      /**< \brief Specifies the channel0 used for CRC  */
    IfxFce_CrcChannel_1,          /**< \brief Specifies the channel1 used for CRC  */
    IfxFce_CrcChannel_2,          /**< \brief Specifies the channel2 used for CRC  */
    IfxFce_CrcChannel_3,          /**< \brief Specifies the channel3 used for CRC  */
    IfxFce_CrcChannel_4,          /**< \brief Specifies the channel4 used for CRC  */
    IfxFce_CrcChannel_5,          /**< \brief Specifies the channel5 used for CRC  */
    IfxFce_CrcChannel_6,          /**< \brief Specifies the channel6 used for CRC  */
    IfxFce_CrcChannel_7           /**< \brief Specifies the channel7 used for CRC  */
} IfxFce_CrcChannel;

/** \} */

/** \brief Specify the CRC kernel used by the fce channel
 */
typedef enum
{
    IfxFce_CrcKernel_0 = 0,  /**< \brief Specifies to use kernel 0 */
    IfxFce_CrcKernel_1 = 1,  /**< \brief Specifies to use kernel 1 */
    IfxFce_CrcKernel_2 = 2,  /**< \brief Specifies to use kernel 2 */
    IfxFce_CrcKernel_3 = 3   /**< \brief Specifies to use kernel 3 */
} IfxFce_CrcKernel;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief PROT and APU configuration
 */
typedef struct
{
    IfxApProt_ProtConfig proteConfig;        /**< \brief PROTE configurations */
    IfxApProt_ProtConfig protseConfig;       /**< \brief PROTSE Configuration */
    IfxApApu_ApuConfig   apuConfig;          /**< \brief APU Configurations */
} IfxFce_ApConfig;

/** \addtogroup IfxLld_Fce_Std_Module
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Disable the control of FCE module
 * \param fce Specifies pointer to FCE module registers
 * \return None
 */
IFX_INLINE void IfxFce_disableModule(Ifx_FCE *fce);

/** \brief Enable the control of FCE module
 * \param fce Specifies pointer to FCE module registers
 * \return None
 */
IFX_INLINE void IfxFce_enableModule(Ifx_FCE *fce);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Reset the module by clearing the kernel
 * \param fce Specifies pointer to FCE module registers
 * \return None
 */
IFX_EXTERN void IfxFce_resetModule(Ifx_FCE *fce);

/** \} */

/** \addtogroup IfxLld_Fce_Std_Support
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Reflects the CRC data and returns it
 * \param crcStartValue start value for reflection
 * \param crcLength length of reflected value
 * \return Reflected CRC data
 */
IFX_EXTERN uint32 IfxFce_reflectCrc32(uint32 crcStartValue, uint8 crcLength);

/** \} */

/** \addtogroup IfxLld_Fce_Std_InterruptStatus
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the SRC pointer for FCE
 * \param fce Specifies pointer to FCE module registers
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxFce_getSrcPointer(Ifx_FCE *fce);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Specifies pointer to FCE module registers
 * \param fce Specifies the pointer to FCE module handler
 * \param channel Specifies the Channel
 * \return None
 */
IFX_INLINE void IfxFce_clearCrcErrorFlags(Ifx_FCE *fce, IfxFce_CrcChannel channel);

/** \brief Gets the CRC interrupt status
 * \param fce Specifies pointer to FCE module registers
 * \param channel Specifies the Channel
 * \return Return Crc Interrupt Status
 */
IFX_INLINE Ifx_FCE_IN_STS IfxFce_getCrcInterruptStatus(Ifx_FCE *fce, IfxFce_CrcChannel channel);

/** \brief Set the length of over which CRC checksum is calculated.
 * \param fce Specifies pointer to FCE module registers
 * \param channel Specifies the channel
 * \param crcLength Specifies the Length of CRC
 * \return None
 */
IFX_INLINE void IfxFce_setChannelCrcLength(Ifx_FCE *fce, IfxFce_CrcChannel channel, uint32 crcLength);

/** \brief Set the CRC start value
 * \param fce Specifies pointer to FCE module registers
 * \param channel Specifies the channel
 * \param crcStartValue Set the crc value
 * \return None
 */
IFX_INLINE void IfxFce_setCrcstartValue(Ifx_FCE *fce, IfxFce_CrcChannel channel, uint32 crcStartValue);

/** \brief Set expected crc value to be checked.
 * \param fce Specifies pointer to FCE module registers
 * \param channel Specifies the channel
 * \param expectedCrc Expected CRC value to be checked
 * \return None
 */
IFX_INLINE void IfxFce_setExpectedCrc(Ifx_FCE *fce, IfxFce_CrcChannel channel, uint32 expectedCrc);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initialize the PROTs and APUs with default configuration
 * \param config Configuration pointer for the Access Protection
 * \return None
 */
IFX_EXTERN void IfxFce_initApConfig(IfxFce_ApConfig *config);

/** \brief Initialize the PORTs and APU
 * \param fce FCE module pointer
 * \param config Configuration pointer to the AP
 * \return None
 */
IFX_EXTERN void IfxFce_initAp(Ifx_FCE *fce, IfxFce_ApConfig *config);

/** \brief Configures access to all masters to all the FCEs in the device
 * \param apConfig config pointer to configuration structure
 * \return None
 */
IFX_EXTERN void IfxFce_configureAccessToFce(IfxApApu_ApuConfig *apConfig);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxFce_clearCrcErrorFlags(Ifx_FCE *fce, IfxFce_CrcChannel channel)
{
    fce->IN[channel].STS.U = 0x00000000U;
}


IFX_INLINE void IfxFce_disableModule(Ifx_FCE *fce)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&fce->PROTE, IfxApProt_State_config);
#endif
    fce->CLC.B.DISR = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&fce->PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxFce_enableModule(Ifx_FCE *fce)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&fce->PROTE, IfxApProt_State_config);
#endif
    fce->CLC.B.DISR = 0;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&fce->PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE Ifx_FCE_IN_STS IfxFce_getCrcInterruptStatus(Ifx_FCE *fce, IfxFce_CrcChannel channel)
{
    Ifx_FCE_IN_STS interruptStatus;
    interruptStatus.U = fce->IN[channel].STS.U;

    return interruptStatus;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxFce_getSrcPointer(Ifx_FCE *fce)
{
    IFX_UNUSED_PARAMETER(fce);
    return &SRC_FCE;
}


IFX_INLINE void IfxFce_setChannelCrcLength(Ifx_FCE *fce, IfxFce_CrcChannel channel, uint32 crcLength)
{
    /*write the dafault value 0xFACECAFE to the register */
    fce->IN[channel].LENGTH.U = 0xFACECAFE;
    fce->IN[channel].LENGTH.U = crcLength;
}


IFX_INLINE void IfxFce_setCrcstartValue(Ifx_FCE *fce, IfxFce_CrcChannel channel, uint32 crcStartValue)
{
    fce->IN[channel].CRC.U = crcStartValue;
}


IFX_INLINE void IfxFce_setExpectedCrc(Ifx_FCE *fce, IfxFce_CrcChannel channel, uint32 expectedCrc)
{
    /*write the dafault value 0xFACECAFE to the register */
    fce->IN[channel].CHECK.U = 0xFACECAFE;
    fce->IN[channel].CHECK.U = expectedCrc;
}


#endif /* IFXFCE_H */
