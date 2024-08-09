/**
 * \file IfxCscu.h
 * \brief CSCU  basic functionality
 * \ingroup IfxLld_Cscu
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
 *
 * \defgroup IfxLld_Cscu_Usage How to use the CSCU driver?
 * \ingroup IfxLld_Cscu
 *
 * \section IfxLld_Cscu_Overview Overview
 * This standard layer provides APIs to interact with Cscu (Cyber Security Control Unit) sub-module of CSRM (Cyber Security Real-time Module).\n\n
 *
 * APIs for following functionalities are provided:
 *  -# PROT configuration
 *  -# Module clock and sleep control
 *  -# Communication between CSRM and host
 *  -# CS control
 *  -# SOTA control
 *  -# Pin control
 *  -# Configuration of startup memory
 *
 * <b>Note:</b> For more infromation, refer to individual API documentation.
 *
 * \defgroup IfxLld_Cscu_Std_StartupMemory Startup memory configuration
 * \ingroup IfxLld_Cscu_Std
 * \defgroup IfxLld_Cscu_Std_PROT PROT Configuration
 * \ingroup IfxLld_Cscu_Std
 * \defgroup IfxLld_Cscu_Std_PinControl Pin Control
 * \ingroup IfxLld_Cscu_Std
 * \defgroup IfxLld_Cscu_Std_ModuleControl Module Clock and Sleep Control
 * \ingroup IfxLld_Cscu_Std
 * \defgroup IfxLld_Cscu_Std_HostCommunication CSRM-Host Communication
 * \ingroup IfxLld_Cscu_Std
 */

#ifndef IFXCSCU_H
#define IFXCSCU_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxCscu_cfg.h"
#include "Cpu/Std/Ifx_Types.h"
#include "IfxCscu_reg.h"
#include "IfxCscu_bf.h"
#include "Ap/Std/IfxApApu.h"
#include "Ap/Std/IfxApProt.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Cscu_Std_StartupMemory
 * \{ */
/** \brief Enumeration to select index of the valid BHMD
 */
typedef enum
{
    IfxCscu_Stmem_bhmdIndex_0 = 0,      /**< \brief BHMD Index 0  */
    IfxCscu_Stmem_bhmdIndex_1,          /**< \brief BHMD Index 1  */
    IfxCscu_Stmem_bhmdIndex_2,          /**< \brief BHMD Index 2  */
    IfxCscu_Stmem_bhmdIndex_3           /**< \brief BHMD Index 3  */
} IfxCscu_Stmem_bhmdIndex;

/** \brief Enumeration to select Boot configuration (Start up mode effectively taken by SSW)
 */
typedef enum
{
    IfxCscu_Stmem_bootConfiguration_asc     = 3,  /**< \brief ASC Bootstrap loader */
    IfxCscu_Stmem_bootConfiguration_generic = 4,  /**< \brief Generic Bootstrap loader */
    IfxCscu_Stmem_bootConfiguration_abm1    = 5,  /**< \brief ABM (ASC BSL on fail, only selected via pins) */
    IfxCscu_Stmem_bootConfiguration_abm2    = 6,  /**< \brief ABM (Generic BSL on fail, when selected via pins) */
    IfxCscu_Stmem_bootConfiguration_flash   = 7   /**< \brief Boot from Flash */
} IfxCscu_Stmem_bootConfiguration;

/** \brief Enumeration to select Swap Configuration
 */
typedef enum
{
    IfxCscu_Stmem_swapConfiguration_none  = 0,  /**< \brief No SWAP configured by SSW (full address space active with the default map) */
    IfxCscu_Stmem_swapConfiguration_swapA = 1,  /**< \brief SWAP A configured (address region A active, B inactive) */
    IfxCscu_Stmem_swapConfiguration_swapB = 2   /**< \brief SWAP B configured (address region B active, A inactive) */
} IfxCscu_Stmem_swapConfiguration;

typedef enum
{
    IfxCscu_Stmem_swapIndex_0 = 0,      /**< \brief SWAP Index 0  */
    IfxCscu_Stmem_swapIndex_1,          /**< \brief SWAP Index 1  */
    IfxCscu_Stmem_swapIndex_2,          /**< \brief SWAP Index 2  */
    IfxCscu_Stmem_swapIndex_3,          /**< \brief SWAP Index 3  */
    IfxCscu_Stmem_swapIndex_4,          /**< \brief SWAP Index 4  */
    IfxCscu_Stmem_swapIndex_5,          /**< \brief SWAP Index 5  */
    IfxCscu_Stmem_swapIndex_6,          /**< \brief SWAP Index 6  */
    IfxCscu_Stmem_swapIndex_7,          /**< \brief SWAP Index 7  */
    IfxCscu_Stmem_swapIndex_8,          /**< \brief SWAP Index 8  */
    IfxCscu_Stmem_swapIndex_9,          /**< \brief SWAP Index 9  */
    IfxCscu_Stmem_swapIndex_10,         /**< \brief SWAP Index 10  */
    IfxCscu_Stmem_swapIndex_11,         /**< \brief SWAP Index 11  */
    IfxCscu_Stmem_swapIndex_12,         /**< \brief SWAP Index 12  */
    IfxCscu_Stmem_swapIndex_13,         /**< \brief SWAP Index 13  */
    IfxCscu_Stmem_swapIndex_14,         /**< \brief SWAP Index 14  */
    IfxCscu_Stmem_swapIndex_15,         /**< \brief SWAP Index 15  */
    IfxCscu_Stmem_swapIndex_16,         /**< \brief SWAP Index 16  */
    IfxCscu_Stmem_swapIndex_17,         /**< \brief SWAP Index 17  */
    IfxCscu_Stmem_swapIndex_18,         /**< \brief SWAP Index 18  */
    IfxCscu_Stmem_swapIndex_19,         /**< \brief SWAP Index 19  */
    IfxCscu_Stmem_swapIndex_20,         /**< \brief SWAP Index 20  */
    IfxCscu_Stmem_swapIndex_21,         /**< \brief SWAP Index 21  */
    IfxCscu_Stmem_swapIndex_22,         /**< \brief SWAP Index 22  */
    IfxCscu_Stmem_swapIndex_23,         /**< \brief SWAP Index 23  */
    IfxCscu_Stmem_swapIndex_24,         /**< \brief SWAP Index 24  */
    IfxCscu_Stmem_swapIndex_25,         /**< \brief SWAP Index 25  */
    IfxCscu_Stmem_swapIndex_26,         /**< \brief SWAP Index 26  */
    IfxCscu_Stmem_swapIndex_27,         /**< \brief SWAP Index 27  */
    IfxCscu_Stmem_swapIndex_28,         /**< \brief SWAP Index 28  */
    IfxCscu_Stmem_swapIndex_29,         /**< \brief SWAP Index 29  */
    IfxCscu_Stmem_swapIndex_30,         /**< \brief SWAP Index 30  */
    IfxCscu_Stmem_swapIndex_31          /**< \brief SWAP Index 31  */
} IfxCscu_Stmem_swapIndex;

/** \brief Enumeration to select Swap Target
 */
typedef enum
{
    IfxCscu_Stmem_swapTarget_orig = 0,  /**< \brief SWAP configuration done based on UCB_SWAP_ORIG */
    IfxCscu_Stmem_swapTarget_copy = 1   /**< \brief SWAP configuration done based on UCB_SWAP_COPY */
} IfxCscu_Stmem_swapTarget;

/** \} */

/** \addtogroup IfxLld_Cscu_Std_PinControl
 * \{ */
/** \brief Enumeration to select Pin
 */
typedef enum
{
    IfxCscu_pin_0 = 0,  /**< \brief Pin 0 */
    IfxCscu_pin_1 = 1   /**< \brief Pin 1 */
} IfxCscu_pin;

/** \brief Enumeration to select pin output level
 */
typedef enum
{
    IfxCscu_pinLevel_low  = 0, /**< \brief low level */
    IfxCscu_pinLevel_high = 1  /**< \brief high level */
} IfxCscu_pinLevel;

/** \} */

/** \brief Enumeration to select Cyber Security Activity Visibility level
 */
typedef enum
{
    IfxCscu_csActivityVisibility_none    = 0,  /**< \brief CS bus transactions are not captured and not traced */
    IfxCscu_csActivityVisibility_limited = 1,  /**< \brief Limited information is captured and traced for CS transactions */
    IfxCscu_csActivityVisibility_full    = 3   /**< \brief All information is captured and traced for CS transactions */
} IfxCscu_csActivityVisibility;

/** \brief Enumeration to select SOTA mode
 */
typedef enum
{
    IfxCscu_sotaMode_none = 0,  /**< \brief Not Set */
    IfxCscu_sotaMode_B025 = 1,  /**< \brief CPUcs in SOTA-B mode swapping at 0.25MB boundary */
    IfxCscu_sotaMode_B05  = 2,  /**< \brief CPUcs in SOTA-B mode swapping at 0.5MB boundary */
    IfxCscu_sotaMode_A    = 4   /**< \brief CPUcs in linear (= SOTA-A) mode */
} IfxCscu_sotaMode;

/** \brief Enumeration listing the status of an operation
 */
typedef enum
{
    IfxCscu_status_success,  /**< \brief Operation successful */
    IfxCscu_status_failure   /**< \brief Operation failed */
} IfxCscu_status;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Cscu_Std_PROT
 * \{ */
/** \brief PROT and APU Configuration for CSCU Module
 */
typedef struct
{
    IfxApProt_ProtConfig proteConfig;        /**< \brief PROTE related configuration */
    IfxApProt_ProtConfig protseConfig;       /**< \brief PROTSE related configuration */
    IfxApApu_ApuConfig   apuConfig;          /**< \brief APU Configuration */
} IfxCscu_ApConfig;

/** \} */

/** \addtogroup IfxLld_Cscu_Std_StartupMemory
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Function that checks whether BHMD is valid or not
 * \param cscuSFR Pointer to the CSCU SFR
 * \return returns TRUE: BHMD is valid
 * returns FALSE: BHMD is invalid
 */
IFX_INLINE boolean IfxCscu_Stmem_isBhmdValid(Ifx_CSCU *cscuSFR);

/** \brief Function that sets Bhmd Valid Flag to 1 (BHMD is valid)
 * \param cscuSFR Pointer to the CSCU SFR
 * \return None
 */
IFX_INLINE void IfxCscu_Stmem_enableBhmdValid(Ifx_CSCU *cscuSFR);

/** \brief Function that sets Bhmd Valid Flag to 0 (BHMD is invalid)
 * \param cscuSFR Pointer to the CSCU SFR
 * \return None
 */
IFX_INLINE void IfxCscu_Stmem_disableBhmdValid(Ifx_CSCU *cscuSFR);

/** \brief Function that checks whether HWCFG pins used for Boot confuguration were checked
 * \param cscuSFR Pointer to the CSCU SFR
 * \return returns TRUE: Pins were checked (1, HWCFG pins checked)
 * returns FALSE: Pins were not checked (0, HWCFG pins not checked)
 */
IFX_INLINE boolean IfxCscu_Stmem_areBootConfigPinsChecked(Ifx_CSCU *cscuSFR);

/** \brief Function that sets the boot configured from pins status to checked
 * \param cscuSFR Pointer to the CSCU SFR
 * \return None
 */
IFX_INLINE void IfxCscu_Stmem_enableBootConfigPinsCheckedFlag(Ifx_CSCU *cscuSFR);

/** \brief Function that sets the boot configured from pins status to  not checked
 * \param cscuSFR Pointer to the CSCU SFR
 * \return None
 */
IFX_INLINE void IfxCscu_Stmem_disableBootConfigPinsCheckedFlag(Ifx_CSCU *cscuSFR);

/** \brief Function that checks whether BMHD copy flag is set to 1 (copy was used)
 * \param cscuSFR Pointer to the CSCU SFR
 * \return returns TRUE: Copy was used
 * returns FALSE: Pins Copy was not used (original)
 */
IFX_INLINE boolean IfxCscu_Stmem_isBhmdCopyFlagSet(Ifx_CSCU *cscuSFR);

/** \brief Function that enables the BMHD copy flag
 * \param cscuSFR Pointer to the CSCU SFR
 * \return None
 */
IFX_INLINE void IfxCscu_Stmem_enableBhmdCopyFlag(Ifx_CSCU *cscuSFR);

/** \brief Function that disables the BHMD copy flag
 * \param cscuSFR Pointer to the CSCU SFR
 * \return None
 */
IFX_INLINE void IfxCscu_Stmem_disableBhmdCopyFlag(Ifx_CSCU *cscuSFR);

/** \brief Function that writes BHMD index
 * \param cscuSFR Pointer to the CSCU SFR
 * \param index index of the valid BHMD
 * \return None
 */
IFX_INLINE void IfxCscu_Stmem_setBhmdIndex(Ifx_CSCU *cscuSFR, IfxCscu_Stmem_bhmdIndex index);

/** \brief Function that reads BHMD index
 * \param cscuSFR Pointer to the CSCU SFR
 * \return Index of BHMD
 */
IFX_INLINE IfxCscu_Stmem_bhmdIndex IfxCscu_Stmem_getBhmdIndex(Ifx_CSCU *cscuSFR);

/** \brief Function that writes Boot Configuration
 * \param cscuSFR Pointer to the CSCU SFR
 * \param bootConfig Valid Boot Configuration
 * \return None
 */
IFX_INLINE void IfxCscu_Stmem_setBootConfiguration(Ifx_CSCU *cscuSFR, IfxCscu_Stmem_bootConfiguration bootConfig);

/** \brief Function that reads Boot Configuration
 * \param cscuSFR Pointer to the CSCU SFR
 * \return Boot Configuration
 */
IFX_INLINE IfxCscu_Stmem_bootConfiguration IfxCscu_Stmem_getBootConfiguration(Ifx_CSCU *cscuSFR);

/** \brief Function that checks whether HAR (Halt-After-Reset) was requested during last SSW execution
 * \param cscuSFR Pointer to the CSCU SFR
 * \return returns TRUE: HAR was requested during last SSW execution
 * returns FALSE: No HAR was requested
 */
IFX_INLINE boolean IfxCscu_Stmem_isHarRequestFlagEnabled(Ifx_CSCU *cscuSFR);

/** \brief Function that enables HAR (Halt-After-Reset) flag
 * \param cscuSFR Pointer to the CSCU SFR
 * \return None
 */
IFX_INLINE void IfxCscu_Stmem_enableHarRequestFlag(Ifx_CSCU *cscuSFR);

/** \brief Function that disbales HAR (Halt-After-Reset) flag
 * \param cscuSFR Pointer to the CSCU SFR
 * \return None
 */
IFX_INLINE void IfxCscu_Stmem_disableHarRequestFlag(Ifx_CSCU *cscuSFR);

/** \brief Function that reads SWAP configuration
 * \param cscuSFR Pointer to the CSCU SFR
 * \return SWAP Configuration
 */
IFX_INLINE IfxCscu_Stmem_swapConfiguration IfxCscu_Stmem_getSwapConfiguration(Ifx_CSCU *cscuSFR);

/** \brief Function that writes SWAP Configuration
 * \param cscuSFR Pointer to the CSCU SFR
 * \param configuration SWAP configuration
 * \return None
 */
IFX_INLINE void IfxCscu_Stmem_setSwapConfiguration(Ifx_CSCU *cscuSFR, IfxCscu_Stmem_swapConfiguration configuration);

/** \brief Function that reads SWAP target
 * \param cscuSFR Pointer to the CSCU SFR
 * \return SWAP Target
 */
IFX_INLINE IfxCscu_Stmem_swapTarget IfxCscu_Stmem_getSwapTarget(Ifx_CSCU *cscuSFR);

/** \brief Function that writes SWAP target
 * \param cscuSFR Pointer to the CSCU SFR
 * \param target SWAP Target
 * \return None
 */
IFX_INLINE void IfxCscu_Stmem_setSwapTarget(Ifx_CSCU *cscuSFR, IfxCscu_Stmem_swapTarget target);

/** \brief Function that reads SWAP Marker Index
 * \param cscuSFR Pointer to the CSCU SFR
 * \return SWAP Marker Index
 */
IFX_INLINE IfxCscu_Stmem_swapIndex IfxCscu_Stmem_getSwapIndex(Ifx_CSCU *cscuSFR);

/** \brief Function that writes SWAP Marker Index
 * \param cscuSFR Pointer to the CSCU SFR
 * \param index SWAP Marker index
 * \return None
 */
IFX_INLINE void IfxCscu_Stmem_setSwapIndex(Ifx_CSCU *cscuSFR, IfxCscu_Stmem_swapIndex index);

/** \brief Function that checks whether user configuration error flag is set
 * \param cscuSFR Pointer to the CSCU SFR
 * \return returns TRUE: An invalid set of configuration was provided to user configured UCBs
 * returns FALSE: Valid set of configuration was provided
 */
IFX_INLINE boolean IfxCscu_Stmem_isUserConfigurationInvalid(Ifx_CSCU *cscuSFR);

/** \brief Function that enables user configuration error flag
 * \param cscuSFR Pointer to the CSCU SFR
 * \return None
 */
IFX_INLINE void IfxCscu_Stmem_enableUserConfigErrorFlag(Ifx_CSCU *cscuSFR);

/** \brief Function that disables user configuration error flag
 * \param cscuSFR Pointer to the CSCU SFR
 * \return None
 */
IFX_INLINE void IfxCscu_Stmem_disableUserConfigErrorFlag(Ifx_CSCU *cscuSFR);

/** \brief Function that reads Boot address
 * \param cscuSFR Pointer to the CSCU SFR
 * \return Boot address
 */
IFX_INLINE uint32 IfxCscu_Stmem_getBootAddress(Ifx_CSCU *cscuSFR);

/** \brief Function that writes Boot address
 * \param cscuSFR Pointer to the CSCU SFR
 * \param address Boot Address
 * \return None
 */
IFX_INLINE void IfxCscu_Stmem_writeBootAddress(Ifx_CSCU *cscuSFR, uint32 *address);

/** \} */

/** \addtogroup IfxLld_Cscu_Std_PROT
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Function to initialize the PROT and APU Config of CSCU Module with default value
 * \param config PROT and APU Config
 * \return None
 */
IFX_INLINE void IfxCscu_initApConfig(IfxCscu_ApConfig *config);

/** \brief Function to initialize the PROT and APU of CSCU Module
 * \param cscuSFR Pointer to the CSCU SFR
 * \param config PROT and APU Config
 * \return None
 */
IFX_INLINE void IfxCscu_initAp(Ifx_CSCU *cscuSFR, IfxCscu_ApConfig *config);

/** \} */

/** \addtogroup IfxLld_Cscu_Std_PinControl
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Function that makes Pin Control register read-only
 * \param cscuSFR Pointer to the CSCU SFR
 * \return None
 */
IFX_INLINE void IfxCscu_lockPinControl(Ifx_CSCU *cscuSFR);

/** \brief Function that checks whether Pin Control register is locked/read-only
 * \param cscuSFR Pointer to the CSCU SFR
 * \return returns TRUE: Pin Control register is read-only
 * returns FALSE: Pin Control register bits can be written
 */
IFX_INLINE boolean IfxCscu_isPinControlLocked(Ifx_CSCU *cscuSFR);

/** \brief Function that enables Pin0/1 output
 * \param cscuSFR Pointer to the CSCU SFR
 * \param pin Select Pin 0/1
 * \return None
 */
IFX_INLINE void IfxCscu_enablePinOutput(Ifx_CSCU *cscuSFR, IfxCscu_pin pin);

/** \brief Function that disables Pin0/1 output
 * \param cscuSFR Pointer to the CSCU SFR
 * \param pin Select Pin 0/1
 * \return None
 */
IFX_INLINE void IfxCscu_disablePinOutput(Ifx_CSCU *cscuSFR, IfxCscu_pin pin);

/** \brief Function that checks if Pin0/1 output of CSRM is enabled
 * \param cscuSFR Pointer to the CSCU SFR
 * \param pin Select Pin 0/1
 * \return returns TRUE: Pin0/1 output of CSRM is enabled
 * returns FALSE: Pin0/1 output of CSRM is disabled
 */
IFX_INLINE boolean IfxCscu_isPinOutputEnabled(Ifx_CSCU *cscuSFR, IfxCscu_pin pin);

/** \brief Function that writes Pin0/1 output value
 * \param cscuSFR Pointer to the CSCU SFR
 * \param pin Select Pin 0/1
 * \param level desired pin output value
 * \return None
 */
IFX_INLINE void IfxCscu_writePinOutputValue(Ifx_CSCU *cscuSFR, IfxCscu_pin pin, IfxCscu_pinLevel level);

/** \brief Function that checks whether Pin0/1 output is high
 * \param cscuSFR Pointer to the CSCU SFR
 * \param pin Select Pin 0/1
 * \return returns TRUE: Pin is 1/high
 * returns FALSE: Pin is 0/low
 */
IFX_INLINE boolean IfxCscu_isPinOutputHigh(Ifx_CSCU *cscuSFR, IfxCscu_pin pin);

/** \} */

/** \addtogroup IfxLld_Cscu_Std_ModuleControl
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Function that requests to enable the module clock
 * \param cscuSFR Pointer to the CSCU SFR
 * \return None
 */
IFX_INLINE void IfxCscu_enableModule(Ifx_CSCU *cscuSFR);

/** \brief Function that requests to disable the module clock
 * \param cscuSFR Pointer to the CSCU SFR
 * \return None
 */
IFX_INLINE void IfxCscu_disableModule(Ifx_CSCU *cscuSFR);

/** \brief Function that checks whether the module clock is enabled
 * \param cscuSFR Pointer to the CSCU SFR
 * \return Returns TRUE: Module clock is enabled
 * returns FALSE: Off, module is not clocked
 */
IFX_INLINE boolean IfxCscu_isModuleEnabled(Ifx_CSCU *cscuSFR);

/** \brief Function that checks whether Sleep Mode Control is possible or not
 * \param cscuSFR Pointer to the CSCU SFR
 * \return Returns TRUE: Sleep mode request is enabled and functional
 * returns FALSE: Module disregards the sleep mode control signal
 */
IFX_INLINE boolean IfxCscu_isSleepModeControlEnabled(Ifx_CSCU *cscuSFR);

/** \brief Function that enables module to react to sleep mode requests
 * \param cscuSFR Pointer to the CSCU SFR
 * \return None
 */
IFX_INLINE void IfxCscu_enableSleepModeControl(Ifx_CSCU *cscuSFR);

/** \brief Function that disables the module reaction to sleep mode requests
 * \param cscuSFR Pointer to the CSCU SFR
 * \return None
 */
IFX_INLINE void IfxCscu_disableSleepModeControl(Ifx_CSCU *cscuSFR);

/** \} */

/** \addtogroup IfxLld_Cscu_Std_HostCommunication
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Function that writes data used for communication from CSRM to host
 * \param cscuSFR Pointer to the CSCU SFR
 * \param data 32 bits of information to signal CSRM internal status to Application Software
 * \return None
 */
IFX_INLINE void IfxCscu_writeHostData(Ifx_CSCU *cscuSFR, uint32 *data);

/** \brief Function that reads data used for communication from CSRM to host
 * \param cscuSFR Pointer to the CSCU SFR
 * \return 32 bits data
 */
IFX_INLINE uint32 IfxCscu_getHostData(Ifx_CSCU *cscuSFR);

/** \brief Function that writes data used for error communication from CSRM to host
 * \param cscuSFR Pointer to the CSCU SFR
 * \param data 32 bits of information to signal CSRM internal status to Application Software
 * \return None
 */
IFX_INLINE void IfxCscu_writeHostErrorData(Ifx_CSCU *cscuSFR, uint32 *data);

/** \brief Function that reads data used for error communication from CSRM to host
 * \param cscuSFR Pointer to the CSCU SFR
 * \return 32 bits data
 */
IFX_INLINE uint32 IfxCscu_getHostErrorData(Ifx_CSCU *cscuSFR);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Function that checks if CSV field of CS_Valid Control register is enabled
 * \param cscuSFR Pointer to the CSCU SFR
 * \return returns TRUE: cs_valid is 1
 * returns FALSE: cs_valid is 0
 */
IFX_INLINE boolean IfxCscu_isCsValidEnabled(Ifx_CSCU *cscuSFR);

/** \brief Function that writes 1 to the CSV field of CS_Valid Control register
 * \param cscuSFR Pointer to the CSCU SFR
 * \return None
 */
IFX_INLINE void IfxCscu_enableCsValid(Ifx_CSCU *cscuSFR);

/** \brief Function that writes 0 to the CSV field of CS_Valid Control register
 * \param cscuSFR Pointer to the CSCU SFR
 * \return None
 */
IFX_INLINE void IfxCscu_disableCsValid(Ifx_CSCU *cscuSFR);

/** \brief Function that checks if DONE field of INIT register is enabled
 * \param cscuSFR Pointer to the CSCU SFR
 * \return returns TRUE: DONE is 1 (Initialization Done)
 * returns FALSE: DONE is 0 (Initialization Phase)
 */
IFX_INLINE boolean IfxCscu_isInitDoneEnabled(Ifx_CSCU *cscuSFR);

/** \brief Function that sets DONE field of INIT register to 1
 * \param cscuSFR Pointer to the CSCU SFR
 * \return None
 */
IFX_INLINE void IfxCscu_enableInitDone(Ifx_CSCU *cscuSFR);

/** \brief Function that sets Cyber Security Activity Visibility level for trace and capture
 * \param cscuSFR Pointer to the CSCU SFR
 * \param visibility Cyber Security Activity Visibility level
 * \return None
 */
IFX_INLINE void IfxCscu_setCsActivityVisibility(Ifx_CSCU *cscuSFR, IfxCscu_csActivityVisibility visibility);

/** \brief Function that reads Cyber Security Activity Visibility level for trace and capture
 * \param cscuSFR Pointer to the CSCU SFR
 * \return Cyber Security Activity Visibility level
 */
IFX_INLINE IfxCscu_csActivityVisibility IfxCscu_getCsActivityVisibility(Ifx_CSCU *cscuSFR);

/** \brief Function that configures SOTA Mode
 * \param cscuSFR Pointer to the CSCU SFR
 * \param mode desired SOTA Mode
 * \return None
 */
IFX_INLINE void IfxCscu_setSotaMode(Ifx_CSCU *cscuSFR, IfxCscu_sotaMode mode);

/** \brief Function that reads currently set SOTA Mode
 * \param cscuSFR Pointer to the CSCU SFR
 * \return SOTA Mode
 */
IFX_INLINE IfxCscu_sotaMode IfxCscu_getSotaMode(Ifx_CSCU *cscuSFR);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Configures access to all masters to all the CSCUs in the device
 * \param apConfig pointer to configuration structure
 * \return None
 */
IFX_EXTERN void IfxCscu_configureAccessToCscu(IfxApApu_ApuConfig *apConfig);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxCscu_enableModule(Ifx_CSCU *cscuSFR)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTE, IfxApProt_State_config);
#endif

    cscuSFR->CLC.B.DISR = (uint32)0;

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTE, IfxApProt_State_run);
#endif

    while (cscuSFR->CLC.B.DISS == (uint32)1)
    {
        /* wait until module is enabled */
    }
}


IFX_INLINE void IfxCscu_disableModule(Ifx_CSCU *cscuSFR)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTE, IfxApProt_State_config);
#endif

    cscuSFR->CLC.B.DISR = (uint32)1;

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTE, IfxApProt_State_run);
#endif

    while (cscuSFR->CLC.B.DISS == (uint32)0)
    {
        /* wait until module is disabled */
    }
}


IFX_INLINE boolean IfxCscu_isModuleEnabled(Ifx_CSCU *cscuSFR)
{
    boolean return_status = FALSE;
    return_status = (cscuSFR->CLC.B.DISS == (uint32)0);
    return return_status;
}


IFX_INLINE boolean IfxCscu_isSleepModeControlEnabled(Ifx_CSCU *cscuSFR)
{
    boolean return_status = FALSE;
    return_status = (cscuSFR->CLC.B.EDIS == (uint32)0);
    return return_status;
}


IFX_INLINE void IfxCscu_enableSleepModeControl(Ifx_CSCU *cscuSFR)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTE, IfxApProt_State_config);
#endif

    cscuSFR->CLC.B.EDIS = (uint32)0;

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxCscu_disableSleepModeControl(Ifx_CSCU *cscuSFR)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTE, IfxApProt_State_config);
#endif

    cscuSFR->CLC.B.EDIS = (uint32)1;

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxCscu_writeHostData(Ifx_CSCU *cscuSFR, uint32 *data)
{
    cscuSFR->CSRM2HT.U = *data;
}


IFX_INLINE uint32 IfxCscu_getHostData(Ifx_CSCU *cscuSFR)
{
    return cscuSFR->CSRM2HT.U;
}


IFX_INLINE void IfxCscu_writeHostErrorData(Ifx_CSCU *cscuSFR, uint32 *data)
{
    cscuSFR->CSRM2ERR.U = *data;
}


IFX_INLINE uint32 IfxCscu_getHostErrorData(Ifx_CSCU *cscuSFR)
{
    return cscuSFR->CSRM2ERR.U;
}


IFX_INLINE boolean IfxCscu_isCsValidEnabled(Ifx_CSCU *cscuSFR)
{
    boolean return_status = FALSE;
    return_status = (cscuSFR->CSVCTRL.B.CSV == (uint32)1);
    return return_status;
}


IFX_INLINE void IfxCscu_enableCsValid(Ifx_CSCU *cscuSFR)
{
    cscuSFR->CSVCTRL.B.CSV = (uint32)1;
}


IFX_INLINE void IfxCscu_disableCsValid(Ifx_CSCU *cscuSFR)
{
    cscuSFR->CSVCTRL.B.CSV = (uint32)0;
}


IFX_INLINE boolean IfxCscu_isInitDoneEnabled(Ifx_CSCU *cscuSFR)
{
    boolean return_status = FALSE;
    return_status = (cscuSFR->INIT.B.DONE == (uint32)1);
    return return_status;
}


IFX_INLINE void IfxCscu_enableInitDone(Ifx_CSCU *cscuSFR)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTE, IfxApProt_State_config);
#endif

    cscuSFR->INIT.B.DONE = (uint32)1;

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxCscu_setCsActivityVisibility(Ifx_CSCU *cscuSFR, IfxCscu_csActivityVisibility visibility)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTE, IfxApProt_State_config);
#endif

    cscuSFR->DBGCTRL.B.CSAV = (uint32)visibility;

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE IfxCscu_csActivityVisibility IfxCscu_getCsActivityVisibility(Ifx_CSCU *cscuSFR)
{
    IfxCscu_csActivityVisibility visibility;
    visibility = (IfxCscu_csActivityVisibility)(cscuSFR->DBGCTRL.B.CSAV);
    return visibility;
}


IFX_INLINE void IfxCscu_lockPinControl(Ifx_CSCU *cscuSFR)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTE, IfxApProt_State_config);
#endif
    cscuSFR->PINCTRL.B.LOCK = (uint32)1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE boolean IfxCscu_isPinControlLocked(Ifx_CSCU *cscuSFR)
{
    boolean return_status = FALSE;
    return_status = (cscuSFR->PINCTRL.B.LOCK == (uint32)1);
    return return_status;
}


IFX_INLINE void IfxCscu_enablePinOutput(Ifx_CSCU *cscuSFR, IfxCscu_pin pin)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTE, IfxApProt_State_config);
#endif

    if (pin == IfxCscu_pin_0)
    {
        cscuSFR->PINCTRL.B.OEN0 = (uint32)1;
    }
    else if (pin == IfxCscu_pin_1)
    {
        cscuSFR->PINCTRL.B.OEN1 = (uint32)1;
    }

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxCscu_disablePinOutput(Ifx_CSCU *cscuSFR, IfxCscu_pin pin)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTE, IfxApProt_State_config);
#endif

    if (pin == IfxCscu_pin_0)
    {
        cscuSFR->PINCTRL.B.OEN0 = (uint32)0;
    }
    else if (pin == IfxCscu_pin_1)
    {
        cscuSFR->PINCTRL.B.OEN1 = (uint32)0;
    }

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE boolean IfxCscu_isPinOutputEnabled(Ifx_CSCU *cscuSFR, IfxCscu_pin pin)
{
    boolean return_status = FALSE;

    if (pin == IfxCscu_pin_0)
    {
        return_status = (cscuSFR->PINCTRL.B.OEN0 == (uint32)1);
    }
    else if (pin == IfxCscu_pin_1)
    {
        return_status = (cscuSFR->PINCTRL.B.OEN1 == (uint32)1);
    }

    return return_status;
}


IFX_INLINE void IfxCscu_writePinOutputValue(Ifx_CSCU *cscuSFR, IfxCscu_pin pin, IfxCscu_pinLevel level)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTE, IfxApProt_State_config);
#endif

    if (pin == IfxCscu_pin_0)
    {
        cscuSFR->PINCTRL.B.VAL0 = (uint32)level;
    }
    else if (pin == IfxCscu_pin_1)
    {
        cscuSFR->PINCTRL.B.VAL1 = (uint32)level;
    }

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE boolean IfxCscu_isPinOutputHigh(Ifx_CSCU *cscuSFR, IfxCscu_pin pin)
{
    boolean return_status = FALSE;

    if (pin == IfxCscu_pin_0)
    {
        return_status = (cscuSFR->PINCTRL.B.VAL0 == (uint32)IfxCscu_pinLevel_high);
    }
    else if (pin == IfxCscu_pin_1)
    {
        return_status = (cscuSFR->PINCTRL.B.VAL1 == (uint32)IfxCscu_pinLevel_high);
    }

    return return_status;
}


IFX_INLINE void IfxCscu_setSotaMode(Ifx_CSCU *cscuSFR, IfxCscu_sotaMode mode)
{
    cscuSFR->SOTACTRL.B.SOTA = (uint32)mode;
}


IFX_INLINE IfxCscu_sotaMode IfxCscu_getSotaMode(Ifx_CSCU *cscuSFR)
{
    IfxCscu_sotaMode mode;
    mode = (IfxCscu_sotaMode)(cscuSFR->SOTACTRL.B.SOTA);
    return mode;
}


IFX_INLINE boolean IfxCscu_Stmem_isBhmdValid(Ifx_CSCU *cscuSFR)
{
    boolean return_status = FALSE;
    return_status = (cscuSFR->STMEM1.B.BV == (uint32)1);
    return return_status;
}


IFX_INLINE void IfxCscu_Stmem_enableBhmdValid(Ifx_CSCU *cscuSFR)
{
    cscuSFR->STMEM1.B.BV = (uint32)1;
}


IFX_INLINE void IfxCscu_Stmem_disableBhmdValid(Ifx_CSCU *cscuSFR)
{
    cscuSFR->STMEM1.B.BV = (uint32)0;
}


IFX_INLINE boolean IfxCscu_Stmem_areBootConfigPinsChecked(Ifx_CSCU *cscuSFR)
{
    boolean return_status = FALSE;
    return_status = (cscuSFR->STMEM1.B.BP == (uint32)1);
    return return_status;
}


IFX_INLINE void IfxCscu_Stmem_enableBootConfigPinsCheckedFlag(Ifx_CSCU *cscuSFR)
{
    cscuSFR->STMEM1.B.BP = (uint32)1;
}


IFX_INLINE void IfxCscu_Stmem_disableBootConfigPinsCheckedFlag(Ifx_CSCU *cscuSFR)
{
    cscuSFR->STMEM1.B.BP = (uint32)0;
}


IFX_INLINE boolean IfxCscu_Stmem_isBhmdCopyFlagSet(Ifx_CSCU *cscuSFR)
{
    boolean return_status = FALSE;
    return_status = (cscuSFR->STMEM1.B.BCV == (uint32)1);
    return return_status;
}


IFX_INLINE void IfxCscu_Stmem_enableBhmdCopyFlag(Ifx_CSCU *cscuSFR)
{
    cscuSFR->STMEM1.B.BCV = (uint32)1;
}


IFX_INLINE void IfxCscu_Stmem_disableBhmdCopyFlag(Ifx_CSCU *cscuSFR)
{
    cscuSFR->STMEM1.B.BCV = (uint32)0;
}


IFX_INLINE void IfxCscu_Stmem_setBhmdIndex(Ifx_CSCU *cscuSFR, IfxCscu_Stmem_bhmdIndex index)
{
    cscuSFR->STMEM1.B.BIDX = (uint32)index;
}


IFX_INLINE IfxCscu_Stmem_bhmdIndex IfxCscu_Stmem_getBhmdIndex(Ifx_CSCU *cscuSFR)
{
    IfxCscu_Stmem_bhmdIndex index;
    index = (IfxCscu_Stmem_bhmdIndex)(cscuSFR->STMEM1.B.BIDX);
    return index;
}


IFX_INLINE void IfxCscu_Stmem_setBootConfiguration(Ifx_CSCU *cscuSFR, IfxCscu_Stmem_bootConfiguration bootConfig)
{
    cscuSFR->STMEM1.B.BCFG = (uint32)bootConfig;
}


IFX_INLINE IfxCscu_Stmem_bootConfiguration IfxCscu_Stmem_getBootConfiguration(Ifx_CSCU *cscuSFR)
{
    IfxCscu_Stmem_bootConfiguration bootConfig;
    bootConfig = (IfxCscu_Stmem_bootConfiguration)(cscuSFR->STMEM1.B.BCFG);
    return bootConfig;
}


IFX_INLINE boolean IfxCscu_Stmem_isHarRequestFlagEnabled(Ifx_CSCU *cscuSFR)
{
    boolean return_status = FALSE;
    return_status = (cscuSFR->STMEM1.B.HAR == (uint32)1);
    return return_status;
}


IFX_INLINE void IfxCscu_Stmem_enableHarRequestFlag(Ifx_CSCU *cscuSFR)
{
    cscuSFR->STMEM1.B.HAR = (uint32)1;
}


IFX_INLINE void IfxCscu_Stmem_disableHarRequestFlag(Ifx_CSCU *cscuSFR)
{
    cscuSFR->STMEM1.B.HAR = (uint32)0;
}


IFX_INLINE IfxCscu_Stmem_swapConfiguration IfxCscu_Stmem_getSwapConfiguration(Ifx_CSCU *cscuSFR)
{
    IfxCscu_Stmem_swapConfiguration configuration;
    configuration = (IfxCscu_Stmem_swapConfiguration)(cscuSFR->STMEM1.B.SCFG);
    return configuration;
}


IFX_INLINE void IfxCscu_Stmem_setSwapConfiguration(Ifx_CSCU *cscuSFR, IfxCscu_Stmem_swapConfiguration configuration)
{
    cscuSFR->STMEM1.B.SCFG = (uint32)configuration;
}


IFX_INLINE IfxCscu_Stmem_swapTarget IfxCscu_Stmem_getSwapTarget(Ifx_CSCU *cscuSFR)
{
    IfxCscu_Stmem_swapTarget target;
    target = (IfxCscu_Stmem_swapTarget)(cscuSFR->STMEM1.B.ST);
    return target;
}


IFX_INLINE void IfxCscu_Stmem_setSwapTarget(Ifx_CSCU *cscuSFR, IfxCscu_Stmem_swapTarget target)
{
    cscuSFR->STMEM1.B.ST = (uint32)target;
}


IFX_INLINE IfxCscu_Stmem_swapIndex IfxCscu_Stmem_getSwapIndex(Ifx_CSCU *cscuSFR)
{
    IfxCscu_Stmem_swapIndex index;
    index = (IfxCscu_Stmem_swapIndex)(cscuSFR->STMEM1.B.SIDX);
    return index;
}


IFX_INLINE void IfxCscu_Stmem_setSwapIndex(Ifx_CSCU *cscuSFR, IfxCscu_Stmem_swapIndex index)
{
    cscuSFR->STMEM1.B.SIDX = (uint32)index;
}


IFX_INLINE boolean IfxCscu_Stmem_isUserConfigurationInvalid(Ifx_CSCU *cscuSFR)
{
    boolean return_status = FALSE;
    return_status = (cscuSFR->STMEM1.B.CON_E == (uint32)1);
    return return_status;
}


IFX_INLINE void IfxCscu_Stmem_enableUserConfigErrorFlag(Ifx_CSCU *cscuSFR)
{
    cscuSFR->STMEM1.B.CON_E = (uint32)1;
}


IFX_INLINE void IfxCscu_Stmem_disableUserConfigErrorFlag(Ifx_CSCU *cscuSFR)
{
    cscuSFR->STMEM1.B.CON_E = (uint32)0;
}


IFX_INLINE uint32 IfxCscu_Stmem_getBootAddress(Ifx_CSCU *cscuSFR)
{
    uint32 address;
    address = (uint32)(cscuSFR->STMEM2.U);
    return address;
}


IFX_INLINE void IfxCscu_Stmem_writeBootAddress(Ifx_CSCU *cscuSFR, uint32 *address)
{
    /* Boot address is word aligned. Hence, ignore last two bits and write 30 bits */
    cscuSFR->STMEM2.B.BOOT_ADDR = (uint32)(((uint32)address >> (uint32)2) & (uint32)IFX_CSCU_STMEM2_BOOT_ADDR_MSK);
}


IFX_INLINE void IfxCscu_initApConfig(IfxCscu_ApConfig *config)
{
    IfxApProt_initConfig(&config->proteConfig);
    IfxApProt_initConfig(&config->protseConfig);
    IfxApApu_initConfig(&config->apuConfig);
}


IFX_INLINE void IfxCscu_initAp(Ifx_CSCU *cscuSFR, IfxCscu_ApConfig *config)
{
    /* Initialize the PROT */
    IfxApProt_init((Ifx_PROT_PROT *)&cscuSFR->PROTE, &config->proteConfig);
    IfxApProt_init((Ifx_PROT_PROT *)&cscuSFR->PROTSE, &config->protseConfig);

    /* Change the state to CONFIG, Configure APU and set PROT state back to RUN */
    /* Initialize the APU */
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTSE, IfxApProt_State_config);
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&cscuSFR->ACCEN, &config->apuConfig);
    IfxApProt_setState((Ifx_PROT_PROT *)&cscuSFR->PROTSE, IfxApProt_State_run);
}


#endif /* IFXCSCU_H */
