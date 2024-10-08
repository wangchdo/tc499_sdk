/**
 * \file IfxGtm.h
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
 * \defgroup IfxLld_Gtm_Std_Basic_Functions Basic Functions
 * \ingroup IfxLld_Gtm_Std
 * \defgroup IfxLld_Gtm_Std_Enumerations Enumerations
 * \ingroup IfxLld_Gtm_Std
 * \defgroup IfxLld_Gtm_Std_Data_Structures0 Data Structures0
 * \ingroup IfxLld_Gtm_Std
 * \defgroup IfxLld_Gtm_Std_Data_Structures1 Data Structures1
 * \ingroup IfxLld_Gtm_Std
 */

#ifndef IFXGTM_H
#define IFXGTM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxGtm_cfg.h"
#include "IfxGtm_bf.h"
#include "Clock/Std/IfxClock.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Gtm_Std_Enumerations
 * \{ */
/** \brief Enum for GTM interrupt modes
 */
typedef enum
{
    IfxGtm_IrqMode_level       = 0,
    IfxGtm_IrqMode_pulse       = 1,
    IfxGtm_IrqMode_pulseNotify = 2,
    IfxGtm_IrqMode_singlePulse = 3
} IfxGtm_IrqMode;

/** \brief Enum for Msc Alt Input
 */
typedef enum
{
    IfxGtm_MscAltInput_low     = 0,
    IfxGtm_MscAltInput_lowext  = 1,
    IfxGtm_MscAltInput_high    = 2,
    IfxGtm_MscAltInput_highext = 3
} IfxGtm_MscAltInput;

/** \brief OCDS Suspend Control (OCDS.SUS)
 */
typedef enum
{
    IfxGtm_SuspendMode_none = 0,  /**< \brief No suspend */
    IfxGtm_SuspendMode_hard = 1,  /**< \brief Hard Suspend */
    IfxGtm_SuspendMode_soft = 2   /**< \brief Soft Suspend */
} IfxGtm_SuspendMode;

/** \} */

/** \brief Defines the operation mode for the AEI bridge
 * For CLSi_AEI_BRIDGE_MODE.BRG_MODE
 */
typedef enum
{
    IfxGtm_AeiBridgeOpMode_sync  = 0u, /**< \brief AEI bridge operates in sync_bridge mode */
    IfxGtm_AeiBridgeOpMode_async = 1u  /**< \brief AEI bridge operates in async_bridge mode */
} IfxGtm_AeiBridgeOpMode;

/** \brief Defines the cluster clock divider mode
 * For CLSi_ARCH_CLK_CFG.B.CLSj_CLK_DIV
 */
typedef enum
{
    IfxGtm_ClusterClockDiv_disable    = 0u, /**< \brief Cluster is disabled */
    IfxGtm_ClusterClockDiv_enable     = 1u, /**< \brief Cluster is enabled without clock divider */
    IfxGtm_ClusterClockDiv_enableDiv2 = 2u  /**< \brief Cluster is enabled with clock divider 2 */
} IfxGtm_ClusterClockDiv;

/** \brief Enum to specify operation status
 */
typedef enum
{
    IfxGtm_Status_success = 0,  /**< \brief Success */
    IfxGtm_Status_failure = 1   /**< \brief Failure */
} IfxGtm_Status;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Gtm_Std_Data_Structures0
 * \{ */
/** \brief Cluster PROT and APU configuration
 */
typedef struct
{
    IfxApApu_ApuConfig apuConfig;       /**< \brief APU configuration */
} IfxGtm_ClApConfig;

/** \brief CTRL PROT and APU configuration
 */
typedef struct
{
    IfxApProt_ProtConfig proteConfig;       /**< \brief PROTE configuration */
    IfxApApu_ApuConfig   apuConfig;         /**< \brief APU configuration */
} IfxGtm_CtrlApConfig;

/** \brief Wrap PROT and APU configuration
 */
typedef struct
{
    IfxApApu_ApuConfig apuConfig;       /**< \brief APU configuration */
} IfxGtm_WrapApConfig;

/** \} */

/** \addtogroup IfxLld_Gtm_Std_Data_Structures1
 * \{ */
/** \brief PROT and APU configuration for GTM
 */
typedef struct
{
    IfxApProt_ProtConfig protseConfig;                             /**< \brief PROTSE configuration */
    IfxGtm_ClApConfig    clApConfig[IFXGTM_NUM_CCM_OBJECTS];       /**< \brief Cluster APU configuration */
    IfxGtm_CtrlApConfig  ctrlApConfig;                             /**< \brief Ctrl PROT and APU configuration */
    IfxGtm_WrapApConfig  wrapApConfig;                             /**< \brief Wrap APU configuration */
} IfxGtm_ApConfig;

/** \} */

/** \brief MSc configuration Structure
 */
typedef struct
{
    IfxGtm_Cfg_MscSet       mscSet;             /**< \brief MSC set value */
    IfxGtm_Cfg_MscSetSignal mscSetSignal;       /**< \brief MSC set signal */
    IfxGtm_Cfg_MscModule    mscModule;          /**< \brief MSC module */
    IfxGtm_MscAltInput      mscAltIn;           /**< \brief MSC Alternat input selection */
} IfxGtm_MscOut;

/** \addtogroup IfxLld_Gtm_Std_Basic_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Disables the module
 * \param gtm Pointer to GTM module
 * \return None
 */
IFX_INLINE void IfxGtm_disable(Ifx_GTM *gtm);

/** \brief Enables the module
 * \param gtm Pointer to GTM module
 * \return None
 */
IFX_INLINE void IfxGtm_enable(Ifx_GTM *gtm);

/** \brief Returns the status of module enabled or disabled
 * \param gtm Pointer to GTM module
 * \return status: TRUE/FALSE
 */
IFX_INLINE boolean IfxGtm_isEnabled(Ifx_GTM *gtm);

/** \brief Returns the module's suspend state.
 * TRUE :if module is suspended.
 * FALSE:if module is not yet suspended.
 * \param gtm Pointer to GTM module registers
 * \return Suspend status (TRUE / FALSE)
 */
IFX_INLINE boolean IfxGtm_isModuleSuspended(Ifx_GTM *gtm);

/** \brief Configure the Module to Hard/Soft suspend mode.
 * Note: The api works only when the OCDS is enabled and in Supervisor Mode. When OCDS is disabled the OCS suspend control is ineffective.
 * \param gtm Pointer to GTM module registers
 * \param mode Module suspend mode
 * \return None
 */
IFX_INLINE void IfxGtm_setSuspendMode(Ifx_GTM *gtm, IfxGtm_SuspendMode mode);

/** \brief Convert timer ticks to seconds
 * \param clockFreq clockFreq Timer clock frequency
 * \param ticks ticks time value in ticks to be converted
 * \return Return the converted time in s
 */
IFX_INLINE float32 IfxGtm_tickToS(float32 clockFreq, uint32 ticks);

/** \brief Convert seconds to timer ticks
 * \param clockFreq clockFreq Timer clock frequency
 * \param seconds seconds time value in seconds to be converted
 * \return Return the converted time in timer ticks
 */
IFX_INLINE uint32 IfxGtm_sToTick(float32 clockFreq, float32 seconds);

/** \brief Initialize the PORT Safe Endinit
 * \param gtm Pointer to GTM module
 * \param protseConfig Configuration pointer for the Prot
 * \return None
 */
IFX_INLINE void IfxGtm_initProtSe(Ifx_GTM *gtm, IfxApProt_ProtConfig *protseConfig);

/** \brief Initialize the PORTE for Control logic
 * \param gtm Pointer to GTM module
 * \param ctrlProteConfig Configuration pointer for the Prot
 * \return None
 */
IFX_INLINE void IfxGtm_initCtrlProt(Ifx_GTM *gtm, IfxApProt_ProtConfig *ctrlProteConfig);

/** \brief Initialize the APU for the GTM Cluster
 * \param gtm Pointer to GTM module
 * \param cluster Cluster index of GTM
 * \param clApuConfig Configuration pointer for the Apu
 * \return None
 */
IFX_INLINE void IfxGtm_initClApu(Ifx_GTM *gtm, IfxGtm_Cluster cluster, IfxApApu_ApuConfig *clApuConfig);

/** \brief Initialize the APU for Control logic
 * \param gtm Pointer to GTM module
 * \param ctrlApuConfig Configuration pointer for the Apu
 * \return None
 */
IFX_INLINE void IfxGtm_initCtrlApu(Ifx_GTM *gtm, IfxApApu_ApuConfig *ctrlApuConfig);

/** \brief Initialize the APU for Wrapper logic
 * \param gtm Pointer to GTM module
 * \param wrapApuConfig Configuration pointer for the Apu
 * \return None
 */
IFX_INLINE void IfxGtm_initWrapApu(Ifx_GTM *gtm, IfxApApu_ApuConfig *wrapApuConfig);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief GTM connection to MSC
 * \param gtmCluster Cluster of GTM which contains the trigger source
 * \param gtmSource Trigger source selected (Atom or Tom)
 * \param Channel channel within the gtmSource
 * \param mscOut
 * \return TRUE on success else FALSE
 */
IFX_EXTERN boolean IfxGtm_ConnectToMsc(IfxGtm_Cluster gtmCluster, IfxGtm_TrigSource gtmSource, IfxGtm_TrigChannel Channel, IfxGtm_MscOut *mscOut);

/** \brief Initialize the PROTs and APUs with default configuration
 * \param config Configuration pointer for the Access Protection
 * \return None
 */
IFX_EXTERN void IfxGtm_initApConfig(IfxGtm_ApConfig *config);

/** \brief Initialize the PORTs and APU
 * \param gtm Pointer to GTM module
 * \param config Configuration pointer for the Access Protection
 * \return None
 */
IFX_EXTERN void IfxGtm_initAp(Ifx_GTM *gtm, IfxGtm_ApConfig *config);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief returns the GTM SYSCLK frequency.
 * Refer to the Clock distribution for details on GTM SYS CLK.
 * \return sysFreq
 */
IFX_INLINE uint32 IfxGtm_getSysClkFrequency(void);

/** \brief returns the cluster frequency of the GTM cluster.
 * If the cluster is disabled, then it will return 0 as frequency.
 * \param gtm pointer to gtm device
 * \param cluster index of cluster
 * \return cluster frequency
 */
IFX_INLINE uint32 IfxGtm_getClusterFrequency(Ifx_GTM *gtm, IfxGtm_Cluster cluster);

/** \brief Configure Cluster with clock divider
 * \param cluster Cluster of GTM which need to be set
 * \param clockDivider Choose the cluster clock divider mode
 * \return Operation status (TRUE / FALSE)
 */
IFX_INLINE boolean IfxGtm_setClusterClockDiv(IfxGtm_Cluster cluster, IfxGtm_ClusterClockDiv clockDivider);

/** \brief Disable clock of cluster
 * \param cluster Cluster of GTM which need to be cleared
 * \return Operation status (TRUE / FALSE)
 */
IFX_INLINE boolean IfxGtm_clearClusterClockDiv(IfxGtm_Cluster cluster);

/** \brief Set or clear RF PROT bit
 * \param value value to be set for the RF PORT bit
 * \return None
 */
IFX_INLINE void IfxGtm_setResetProtection(boolean value);

/** \brief Get the status of RF PROT bit
 * \return set status (TRUE / FALSE)
 */
IFX_INLINE boolean IfxGtm_getResetProtection(void);

/** \brief Activates write buffer of AEI Bridge
 * GTM_CLS0_AEI_BRIDGE_MODE.B.MSK_WR_RSP = 1
 * \param gtm Pointer to GTM module
 * \return None
 */
IFX_INLINE void IfxGtm_enableAeiBridgeWriteBuffer(Ifx_GTM *gtm);

/** \brief Disables write buffer of AEI Bridge
 * GTM_CLS0_AEI_BRIDGE_MODE.B.MSK_WR_RSP = 0
 * \param gtm Pointer to GTM module
 * \return None
 */
IFX_INLINE void IfxGtm_disableAeiBridgeWriteBuffer(Ifx_GTM *gtm);

/** \brief Writes the operation mode for the AEI bridge
 * GTM_CLS0_AEI_BRIDGE_MODE.B.BRG_MODE = mode
 * \param gtm Pointer to GTM module
 * \param mode Choose the operation mode
 * \return None
 */
IFX_INLINE void IfxGtm_setAeiBridgeOpMode(Ifx_GTM *gtm, IfxGtm_AeiBridgeOpMode mode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Configures access to all masters to all the GTMs in the device
 * \param apConfig pointer to configuration structure.
 * \return None
 */
IFX_EXTERN void IfxGtm_configureAccessToGtms(IfxApApu_ApuConfig *apConfig);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxGtm_disable(Ifx_GTM *gtm)
{
#if defined(IFX_PROT_ENABLED)
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gtm->CTRL.PROTE, IfxApProt_State_config);
#endif
#endif
    gtm->CLC.B.DISR = 1u;
#if defined(IFX_PROT_ENABLED)
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gtm->CTRL.PROTE, IfxApProt_State_run);
#endif
#endif
}


IFX_INLINE void IfxGtm_enable(Ifx_GTM *gtm)
{
#if defined(IFX_PROT_ENABLED)
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gtm->CTRL.PROTE, IfxApProt_State_config);
#endif
#endif
    gtm->CLC.B.DISR = 0u;
#if defined(IFX_PROT_ENABLED)
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gtm->CTRL.PROTE, IfxApProt_State_run);
#endif
#endif
}


IFX_INLINE boolean IfxGtm_isEnabled(Ifx_GTM *gtm)
{
    boolean enabled;
    enabled = (gtm->CLC.B.DISS == (uint8)0u) ? TRUE : FALSE;
    return enabled;
}


IFX_INLINE boolean IfxGtm_isModuleSuspended(Ifx_GTM *gtm)
{
    Ifx_GTM_OCS ocs;

    /* Read the status */
    ocs.U = gtm->OCS.U;

    /* Return the status */
    return ocs.B.SUSSTA;
}


IFX_INLINE void IfxGtm_setSuspendMode(Ifx_GTM *gtm, IfxGtm_SuspendMode mode)
{
    Ifx_GTM_OCS ocs;

    /* Remove protection and configure the suspend mode. */
    ocs.B.SUS_P = 1u;
    ocs.B.SUS   = (uint8)mode;

    gtm->OCS.U  = ocs.U;
}


IFX_INLINE uint32 IfxGtm_getSysClkFrequency(void)
{
    return IfxClock_getGtmFrequency();
}


IFX_INLINE uint32 IfxGtm_getClusterFrequency(Ifx_GTM *gtm, IfxGtm_Cluster cluster)
{
    uint32 Freq;
    uint8  clsDiv = 0u;
    clsDiv = (uint8)(((gtm->CLS->ARCH.CLK_CFG.U) >> ((uint8)cluster << 1u)) & 0x3U);

    if (clsDiv == 0u)
    {
        Freq = (uint32)0u; /* cluster is disabled - return 0 */
    }
    else
    {
        Freq = IfxGtm_getSysClkFrequency() / clsDiv;
    }

    return Freq;
}


IFX_INLINE float32 IfxGtm_tickToS(float32 clockFreq, uint32 ticks)
{
    return (float32)ticks / clockFreq;
}


IFX_INLINE uint32 IfxGtm_sToTick(float32 clockFreq, float32 seconds)
{
    return (uint32)((float32)(seconds * clockFreq));
}


IFX_INLINE void IfxGtm_initProtSe(Ifx_GTM *gtm, IfxApProt_ProtConfig *protseConfig)
{
    (void)IfxApProt_init((volatile Ifx_PROT_PROT *)(volatile void *)&(gtm->PROTSE), protseConfig);
}


IFX_INLINE void IfxGtm_initCtrlProt(Ifx_GTM *gtm, IfxApProt_ProtConfig *ctrlProteConfig)
{
    (void)IfxApProt_init((volatile Ifx_PROT_PROT *)(volatile void *)&(gtm->CTRL.PROTE), ctrlProteConfig);
}


IFX_INLINE void IfxGtm_initClApu(Ifx_GTM *gtm, IfxGtm_Cluster cluster, IfxApApu_ApuConfig *clApuConfig)
{
    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(gtm->PROTSE), IfxApProt_State_config);
    IfxApApu_init((Ifx_ACCEN_ACCEN *)(volatile void *)&(gtm->CL[cluster].ACCEN), clApuConfig);
    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(gtm->PROTSE), IfxApProt_State_run);
}


IFX_INLINE void IfxGtm_initCtrlApu(Ifx_GTM *gtm, IfxApApu_ApuConfig *ctrlApuConfig)
{
    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(gtm->PROTSE), IfxApProt_State_config);
    IfxApApu_init((Ifx_ACCEN_ACCEN *)(volatile void *)&(gtm->CTRL.ACCEN), ctrlApuConfig);
    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(gtm->PROTSE), IfxApProt_State_run);
}


IFX_INLINE void IfxGtm_initWrapApu(Ifx_GTM *gtm, IfxApApu_ApuConfig *wrapApuConfig)
{
    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(gtm->PROTSE), IfxApProt_State_config);
    IfxApApu_init((Ifx_ACCEN_ACCEN *)(volatile void *)&(gtm->WRAP.ACCEN), wrapApuConfig);
    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(gtm->PROTSE), IfxApProt_State_run);
}


IFX_INLINE boolean IfxGtm_setClusterClockDiv(IfxGtm_Cluster cluster, IfxGtm_ClusterClockDiv clockDivider)
{
    uint32  shift    = (uint32)cluster << 1u;
    uint32  setValue = (uint32)clockDivider << shift;
    uint32  mask     = (uint32)0x3U << shift;
    boolean result   = FALSE;

    boolean status   = IfxGtm_getResetProtection();

    if (status == FALSE)
    {
        Ifx__ldmst(&(MODULE_GTM.CLS[0].ARCH.CLK_CFG.U), mask, setValue);
        result = TRUE;
    }

    return result;
}


IFX_INLINE boolean IfxGtm_clearClusterClockDiv(IfxGtm_Cluster cluster)
{
    uint32  shift    = (uint32)cluster << 1u;
    uint32  setValue = 0u;
    uint32  mask     = (uint32)0x3U << shift;
    boolean result   = FALSE;

    boolean status   = IfxGtm_getResetProtection();

    if (status == FALSE)
    {
        Ifx__ldmst(&(MODULE_GTM.CLS[0].ARCH.CLK_CFG.U), mask, setValue);
        result = TRUE;
    }

    return result;
}


IFX_INLINE void IfxGtm_setResetProtection(boolean value)
{
    MODULE_GTM.CLS[0].ARCH.CTRL.B.RF_PROT = value;
}


IFX_INLINE boolean IfxGtm_getResetProtection(void)
{
    boolean result;
    result = MODULE_GTM.CLS[0].ARCH.CTRL.B.RF_PROT;
    return result;
}


IFX_INLINE void IfxGtm_enableAeiBridgeWriteBuffer(Ifx_GTM *gtm)
{
    gtm->CLS[0].AEI.BRIDGE_MODE.B.MSK_WR_RSP = (uint8)TRUE;
}


IFX_INLINE void IfxGtm_disableAeiBridgeWriteBuffer(Ifx_GTM *gtm)
{
    gtm->CLS[0].AEI.BRIDGE_MODE.B.MSK_WR_RSP = (uint8)FALSE;
}


IFX_INLINE void IfxGtm_setAeiBridgeOpMode(Ifx_GTM *gtm, IfxGtm_AeiBridgeOpMode mode)
{
    gtm->CLS[0].AEI.BRIDGE_MODE.B.BRG_MODE = (uint8)mode;
}


#endif /* IFXGTM_H */
