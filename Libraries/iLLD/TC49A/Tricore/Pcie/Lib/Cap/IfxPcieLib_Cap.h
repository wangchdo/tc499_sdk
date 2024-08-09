/**
 * \file IfxPcieLib_Cap.h
 * \brief PCIE CAP details
 * \ingroup IfxLld_Pcie
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
 * \defgroup IfxLld_Pcie_Lib_Cap CAP
 * \ingroup IfxLld_Pcie_Lib
 * \defgroup IfxLld_Pcie_Lib_Cap_Structures Structures
 * \ingroup IfxLld_Pcie_Lib_Cap
 * \defgroup IfxLld_Pcie_Lib_Cap_Functions Functions
 * \ingroup IfxLld_Pcie_Lib_Cap
 */

#ifndef IFXPCIELIB_CAP_H
#define IFXPCIELIB_CAP_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Pcie/Std/IfxPcie.h"
#include "Pcie/Std/IfxPcieDevice.h"
#include "Pcie/Std/IfxPcieCap.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Pcie_Lib_Cap_Structures
 * \{ */
/** \brief AER capability Handle
 */
typedef struct
{
    IfxPcieCap_AerCap *capPtr;       /**< \brief Pointer to Capability */
} IfxPcieLib_Cap_Aer;

/** \brief LTR capability Handle
 */
typedef struct
{
    IfxPcieCap_LtrCap *capPtr;       /**< \brief Pointer to Capability */
} IfxPcieLib_Cap_Ltr;

/** \brief PTM capability Handle
 */
typedef struct
{
    IfxPcieCap_PtmCap *capPtr;       /**< \brief Pointer to Capability */
} IfxPcieLib_Cap_Ptm;

/** \brief SN capability Handle
 */
typedef struct
{
    IfxPcieCap_SnCap *capPtr;       /**< \brief Pointer to Capability */
} IfxPcieLib_Cap_Sn;

/** \brief VSEC capability Handle
 */
typedef struct
{
    void                         *capPtr;           /**< \brief Pointer to Capability */
    IfxPcieCap_ExtendedCapHeader *extHeader;        /**< \brief Extended Cap header */
    IfxPcieCap_VendorSpecHeader  *vsecHeader;       /**< \brief Vendor Specific Header */
} IfxPcieLib_Cap_Vsec;

/** \} */

/** \addtogroup IfxLld_Pcie_Lib_Cap_Structures
 * \{ */
/** \brief Extended Capabilities
 */
typedef struct
{
    IfxPcieLib_Cap_Aer  aer;                                      /**< \brief AER capabilities */
    IfxPcieLib_Cap_Ptm  ptm;                                      /**< \brief PTM capabilities */
    IfxPcieLib_Cap_Ltr  ltr;                                      /**< \brief LTR capabilities */
    IfxPcieLib_Cap_Sn   sn;                                       /**< \brief SN capabilities */
    IfxPcieLib_Cap_Vsec vsec[IFXPCIE_CFG_MAX_NUM_VSEC_CAP];       /**< \brief VSEC capabilities */
} IfxPcieLib_Cap_Extended;

/** \brief MSI capability Handle
 */
typedef struct
{
    IfxPcieCap_MsiCap *capPtr;       /**< \brief Pointer to Capability */
} IfxPcieLib_Cap_Msi;

/** \brief MSIX capability Handle
 */
typedef struct
{
    IfxPcieCap_MsixCap        *capPtr;           /**< \brief Pointer to Capability */
    IfxPcieCap_MsixTableEntry *tableAddr;        /**< \brief Pointer to MSIX Table */
    uint16                     usedEntries;      /**< \brief Used Table Entries */
} IfxPcieLib_Cap_Msix;

/** \brief PCIE capability Handle
 */
typedef struct
{
    IfxPcieCap_PcieCap *capPtr;       /**< \brief Pointer to Capability */
} IfxPcieLib_Cap_Pcie;

/** \brief Power Management capability Handle
 */
typedef struct
{
    IfxPcieCap_PmCap *capPtr;       /**< \brief Pointer to Capability */
} IfxPcieLib_Cap_Pm;

/** \} */

/** \addtogroup IfxLld_Pcie_Lib_Cap_Structures
 * \{ */
/** \brief Capability handler
 */
typedef struct
{
    IfxPcieLib_Cap_Msi      msi;               /**< \brief MSI capabilities */
    IfxPcieLib_Cap_Msix     msix;              /**< \brief MSIX capabilities */
    IfxPcieLib_Cap_Pcie     pcie;              /**< \brief PCI Express capabilities */
    IfxPcieLib_Cap_Pm       pmc;               /**< \brief PMC capabilities */
    IfxPcieLib_Cap_Extended extendedCap;       /**< \brief Extended capabilities */
} IfxPcieLib_Cap;

/** \brief AER capability Configurations
 */
typedef struct
{
    IfxPcieCap_AerCap *capPtr;                    /**< \brief Pointer to Capability Header */
    boolean            ecrcGenEnable;             /**< \brief Enable ECRC Generation */
    boolean            ecrcCheckEnable;           /**< \brief Enable ECRC Check */
    boolean            multipleHdrRecEnable;      /**< \brief Enable Multiple Header Recording */
} IfxPcieLib_Cap_AerCfg;

/** \brief MSI capability Configuration
 */
typedef struct
{
    IfxPcieCap_MsiCap   *capPtr;              /**< \brief Pointer to the Capability header */
    uint64               address;             /**< \brief MSI address (32 bit for AURIX) */
    uint16               dataPattern;         /**< \brief MSI DATA base pattern */
    IfxPcie_MsiInterrupt numInterrupts;       /**< \brief Number of Interrupts */
    uint32               initialMask;         /**< \brief Initial Mask */
} IfxPcieLib_Cap_MsiCfg;

/** \brief MSIx capability Configuration
 */
typedef struct
{
    IfxPcieCap_MsixCap        *capPtr;             /**< \brief Local Pointer to the Capability header */
    IfxPcieCap_MsixTableEntry *tableAddr;          /**< \brief Local Pointer to the MSIX Table */
    uint64                     address;            /**< \brief MSI address (32 bit for AURIX) */
    uint16                     dataPattern;        /**< \brief MSI DATA base pattern */
    uint16                     numInterrupts;      /**< \brief Number of Interrupts */
} IfxPcieLib_Cap_MsixCfg;

/** \} */

/** \addtogroup IfxLld_Pcie_Lib_Cap_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Probe capability structures
 * NOTE: ECAM ATU must be configured correctly prior to calling this function
 * \param cap Capability Handler
 * \param configHdr Pointer to the Config Header
 * \return None
 */
IFX_EXTERN void IfxPcieLib_Cap_probeCapabilities(IfxPcieLib_Cap *cap, IfxPcieDevice_CfgHdr *configHdr);

/** \brief Configure MSI capability header
 * NOTE: ECAM ATU must be properly configured before calling this function
 * NOTE: MSI is not enabled here - enable it separately using IfxPcieCap_enableMsi function
 * \param msiCap MSI Capability Ptr
 * \param msiCfgPtr MSI configuration Pointer
 * \return Status of initialization
 */
IFX_EXTERN IfxPcie_Status IfxPcieLib_Cap_configureMsiCap(IfxPcieLib_Cap_Msi *msiCap, IfxPcieLib_Cap_MsiCfg *msiCfgPtr);

/** \brief Configure MSIx capability header
 * NOTE: ECAM ATU must be properly configured before calling this function
 * NOTE: MSIX is not enabled here - enable it separately using IfxPcieCap_enableMsix function
 * \param msixCap MSI Capability Ptr
 * \param msixCfgPtr MSI configuration Pointer
 * \return Status of initialization
 */
IFX_EXTERN IfxPcie_Status IfxPcieLib_Cap_configureMsixCap(IfxPcieLib_Cap_Msix *msixCap, IfxPcieLib_Cap_MsixCfg *msixCfgPtr);

/** \brief Configure AER capability header
 * NOTE: ECAM ATU must be properly configured before calling this function
 * \param aerCap AER Capability Ptr
 * \param aerCfgPtr AER configuration Pointer
 * \return Status of initialization
 */
IFX_EXTERN IfxPcie_Status IfxPcieLib_Cap_configureAerCap(IfxPcieLib_Cap_Aer *aerCap, IfxPcieLib_Cap_AerCfg *aerCfgPtr);

/** \} */

#endif /* IFXPCIELIB_CAP_H */
