/**
 * \file IfxVmt.h
 * \brief VMT  basic functionality
 * \ingroup IfxLld_Vmt
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
 * \defgroup IfxLld_Vmt_Usage How to use the VMT driver?
 * \ingroup IfxLld_Vmt
 *
 * The Volatile Memory Test (VMT)  controls and monitors the test, initialization and data integrity checking functions of the various internal memories in the device
 *
 * The VMT driver provides set of routines for various Mbist operations
 *
 * In the following sections it will be described, how to integrate the Vmt driver into the application framework.
 *
 * \section IfxLld_Vmt_SramInit Sram Initialisation
 * \subsection IfxLld_Vmt_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Vmt/IfxVmt.h>
 * // include below file only if interrupt mode is used.
 * #include "Src/Std/IfxSrc.h"
 * \endcode
 *
 * \subsection IfxLld_Vmt_Variables Variables
 *
 * \code
 * // used only if interrupt mode is used.
 * static IfxVmt_MbistSel mbistSel;
 * \endcode
 *
 * \subsection IfxLld_Vmt_Interrupt Interrupt Handler Installation
 *
 * See also \ref IfxLld_Cpu_Irq_Usage
 *
 * Define priorities for the Interrrupt handlers. This is normally done in the Ifx_IntPrioDef.h file:
 * \code
 * // priorities are normally defined in Ifx_IntPrioDef.h
 * #define IFX_INTPRIO_VMT  10
 *
 * \endcode
 *
 * Add the interrupt service routines to your C code. They have to call the Vmt interrupt handlers:
 * \code
 * IFX_INTERRUPT(vmtDoneISR, 0, IFX_INTPRIO_VMT)
 * {
 *     IfxVmt_isrDone();
 * }
 * \endcode
 *
 * Finally install the interrupt handlers in your initialisation function:
 * \code
 *         volatile Ifx_SRC_SRCR *src;
 *         src = &MODULE_SRC.VMT[0].MBDONE ;
 *         IfxSrc_init(src, IfxCpu_Irq_getTos(IfxCpu_getCoreIndex()) , IFX_INTPRIO_VMT );
 *         IfxSrc_enable(src);
 *
 *     // install interrupt handlers
 *     IfxCpu_Irq_installInterruptHandler(&vmtDoneISR, IFX_INTPRIO_VMT);
 *     IfxCpu_enableInterrupts();
 * \endcode
 *
 * \subsection IfxLld_Vmt_ClearSram_SyncPolling Clear Sram (Synchronous polling mode)
 *
 * The Sram initialisation in synchronous polling mode (i.e wait till the complete operation is done) can be used as:
 *
 * \code
 *     clearSram(IfxVmt_MbistSel_cpu0Dspr);
 * \endcode
 *
 * \subsection IfxLld_Vmt_ClearSram_ASyncPolling Clear Sram (Asynchronous polling mode)
 *
 * The Sram initialisation can be triggered by calling IfxVmt_clearSramStart() function, then can be queried for completion in a task using IfxVmt_isMbistDone. Once it's completed, then IfxVmt_clearSramContinue() has to be
 * called.
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE) for the IfxVmt_clearSramStart() and IfxVmt_clearSramContinue() functions.
 *
 * Following code triggers Sram initilisation.
 * \code
 *
 *     IfxVmt_clearSramStart(IfxVmt_MbistSel_cpu0Dspr);
 *
 * \endcode
 *
 * Sram initialisation status can be queried in a task and once done complete the operation using:
 * \code
 *     if (IfxVmt_isMbistDone(IfxVmt_MbistSel_cpu0Dspr))
 *     {
 *         // Sram Clear operation done
 *
 *
 *         IfxVmt_clearSramContinue(IfxVmt_MbistSel_cpu0Dspr);
 *
 *     }
 *     else
 *     {
 *         // Sram operation is still in progress
 *     }
 * \endcode
 *
 * \subsection IfxLld_Vmt_ClearSram_ASyncInterrupt Clear Sram (Asynchronous interrupt mode)
 * Do the interrupt configuration and initialisation as specified in \ref IfxLld_Vmt_Interrupt
 * The Sram initialisation can be triggered by calling IfxVmt_clearSramStart() function. Once the operation is completed, Vmt Done isr is raised. Inside the Isr IfxVmt_clearSramContinue() has to be called.
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE) for the IfxVmt_clearSramStart() and IfxVmt_clearSramContinue() functions.
 *
 * Following code triggers Sram initialisation.
 * \code
 *
 *     mbistSel = IfxVmt_MbistSel_cpu0Dspr; // mbistSel is a static / global variable.
 *     IfxVmt_clearSramStart(mbistSel);
 *
 * \endcode
 * In the Vmt done isr, the following code can be used.
 *
 * \code
 *     if (IfxVmt_isMbistDone(mbistSel))
 *     {
 *         // Sram Clear operation done
 *
 *         IfxVmt_clearSramContinue(mbistSel);
 *
 *     }
 *
 * \endcode
 *
 * \section IfxLld_Vmt_SramError Sram Error tracking
 * Example usage of Sram Error tracking
 * \code
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE)
 *
 * IfxVmt_MbistSel mbistSel = IfxVmt_MbistSel_cpu1Dspr;
 * Ifx_MC *mc = (Ifx_MC *)(IFXVMT_MC_ADDRESS_BASE + 0x100 * mbistSel);
 *
 * IfxVmt_enableMbistShell(mbistSel);
 *
 * // for auto-init memories: wait for the end of the clear operation
 * while (IfxVmt_isAutoInitRunning(mbistSel))
 * {}
 * IfxVmt_enableErrorTracking(mbistSel, TRUE);
 * uint32 numEtrr = 5;
 * // print tracked error address
 * {
 *  Ifx_MC_ETRR trackedSramAddresses[IFXVMT_MAX_TRACKED_ADDRESSES];
 *  uint8  numTrackedAddresses = IfxVmt_getTrackedSramAddresses(mbistSel, trackedSramAddresses);
 *  for(uint32 i=0; i<numEtrr; ++i) {
 *                         printf("%d: Error Address:0x%04x, Error System Address:0x%04x \n",
 *                                    i,
 *                                    trackedSramAddresses[i].B.ADDR,
 *                                    IfxVmt_getSystemAddress(mbistSel, trackedSramAddresses[i]));
 *                       }
 *        }
 * }
 *
 * IfxVmt_disableMbistShell(mbistSel);
 *
 * \endcode
 *
 * \section IfxLld_Vmt_MemoryTest Memory Tests
 * \subsection IfxLld_Vmt_MemoryTest_NDI Non Destructive Inversion Test
 *
 * Usage Example:
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE)
 * \code
 *     // Enable VMT clock
 *     {
 *         IfxVmt_enableModule();
 *     }
 *
 *
 *     {
 *         uint16 errAddr = 0;
 *
 *        // run Non distructive inversion test for cpu0 DSPR memory (Range selection disabled)
 *         IfxVmt_runNonDestructiveInversionTest(IfxVmt_MbistSel_cpu0Dspr, 0, 0xFF, 0, &errAddr);
 *       // Clear Error Flags which are set in case you want to run further tests
 *         IfxVmt_clearErrorTracking(IfxVmt_MbistSel_cpu0Dspr);
 *
 *     }
 * \endcode
 *
 * \subsection IfxLld_Vmt_MemoryTest_CheckerBoard Checker Board Test
 * Usage Example:
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE)
 * \code
 *     // Enable VMT clock
 *     {
 *         IfxVmt_enableModule();
 *     }
 *
 *
 *     {
 *         uint16 errAddr = 0;
 *        // run checkerboard test for cpu0 DSPR memory (Range selection disabled)
 *         IfxVmt_runCheckerBoardTest(IfxVmt_MbistSel_cpu0Dspr, 0, 0xFFFF, 0, &errAddr, 0);
 *     }
 * \endcode
 *
 * \subsection IfxLld_Vmt_MemoryTest_MarchU MarchU Test
 * Usage Example:
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE)
 * \code
 *     // Enable VMT clock
 *     {
 *         IfxVmt_enableModule();
 *     }
 *
 *     {
 *         uint16 errAddr = 0;
 *        // run March U test for cpu0 DSPR memory (Range selection disabled)
 *         IfxVmt_runMarchUTest(IfxVmt_MbistSel_cpu0Dspr, 0, 0xFFFF, 0, &errAddr);
 *     }
 * \endcode
 *
 * \defgroup IfxLld_Vmt_Std_Utility Utility Functions
 * \ingroup IfxLld_Vmt_Std
 * \defgroup IfxLld_Vmt_Std_Operative MBIST Operations
 * \ingroup IfxLld_Vmt_Std
 * \defgroup IfxLld_Vmt_Std_ErrorTracking MBIST Error Tracking
 * \ingroup IfxLld_Vmt_Std
 */

#ifndef IFXVMT_H
#define IFXVMT_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxVmt_cfg.h"
#include "IfxVmt_reg.h"
#include "IfxVmt_bf.h"
#include "Ap/Std/IfxApProt.h"
#include "Ap/Std/IfxApApu.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXVMT_WAIT_TIMEOUTCOUNT                 (((sint32)0x1000))

#define IFXVMT_LOOP_TIMEOUT_CHECK(tVar, tErr) \
    {                                         \
        if (((sint32)--tVar) <= 0)            \
        {                                     \
            tErr = (uint8)1;                  \
            break;                            \
        }                                     \
        else                                  \
        {                                     \
        }                                     \
    }

/** \brief Configuration patterns for the MBIST
 * Array of configurations which are used by MCx_CONFIG0 register
 */
#define IFXVMT_MBIST_CONFIG_NONDISTTEST_MCONTROL {(0x4008U)}

#define IFXVMT_MBIST_CONFIG_NONDISTTEST_CONFIG0       \
    {                                                 \
        (                                             \
            (5U << IFX_VMT_MC_CONFIG0_ACCSTYPE_OFF) | \
            (4U << IFX_VMT_MC_CONFIG0_NUMACCS_OFF)    \
        )                                             \
    }

#define IFXVMT_MBIST_CONFIG_NONDISTTEST_CONFIG1       \
    {                                                 \
        (                                             \
            (8U << IFX_VMT_MC_CONFIG1_ACCSPAT_OFF) |  \
            (0U << IFX_VMT_MC_CONFIG1_SELFASTB_OFF) | \
            (5U << IFX_VMT_MC_CONFIG1_AG_MOD_OFF)     \
        )                                             \
    }

/** \brief Mask for the ERROR flags
 */
#define IFXVMT_ERROR_FLAGS_MASK                                               \
    (((unsigned int)IFX_VMT_MC_ECCD_EOV_MSK << IFX_VMT_MC_ECCD_EOV_OFF) |     \
     ((unsigned int)IFX_VMT_MC_ECCD_CERR_MSK << IFX_VMT_MC_ECCD_CERR_OFF) |   \
     ((unsigned int)IFX_VMT_MC_ECCD_UCERR_MSK << IFX_VMT_MC_ECCD_UCERR_OFF) | \
     ((unsigned int)IFX_VMT_MC_ECCD_MERR_MSK << IFX_VMT_MC_ECCD_MERR_OFF))

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Vmt_Std_Operative
 * \{ */
typedef struct
{
    Ifx_VMT_MC_CONFIG0 config0;
    Ifx_VMT_MC_CONFIG1 config1;
} IfxVmt_MbistConfigPattern;

typedef struct
{
    IfxVmt_MbistSel sshSel;               /**< \brief Member (config0) */
    uint8           preClearEnable;       /**< \brief Enable SRAM clearing before the test */
} IfxVmt_MbistSshConfig;

/** \} */

/** \addtogroup IfxLld_Vmt_Std_Operative
 * \{ */
typedef struct
{
    Ifx_VMT_MC_MCONTROL                  mcontrol;                     /**< \brief Value of MCONTROL register except START bit */
    uint8                                numOfSshConfigurations;       /**< \brief Number of SSH Configurations in the memory test */
    uint8                                numOfConfigPatterns;          /**< \brief Number of configuration patterns */
    IFX_CONST IfxVmt_MbistSshConfig     *sshConfigurations;            /**< \brief Pointer to number of SSH configuration structures */
    IFX_CONST IfxVmt_MbistConfigPattern *configPatterns;               /**< \brief Pointer to number of configuration patterns */
} IfxVmt_MbistConfig;

/** \} */

/** \addtogroup IfxLld_Vmt_Std_Utility
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Disables the MBIST Shell of the given SRAM
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE).
 * \param mbistSel Memory Selection
 * \return None
 *
 * Usage Example
 * \code
 *
 *     IfxVmt_disableMbistShell(IfxVmt_MbistSel_cpu0Dtag);
 *
 *     // Note: Wait for Auto-initilisation to be completed for auto-init memories like cpu-Dtag, cpu-Ptag,  Cpu-Dcache, Cpu-Pcache
 *     while (IfxVmt_isAutoInitRunning(IfxVmt_MbistSel_cpu0Dtag))
 *     {}
 * \endcode
 *
 */
IFX_INLINE void IfxVmt_disableMbistShell(IfxVmt_MbistSel mbistSel);

/** \brief Enables the MBIST Shell of the given SRAM.
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE).
 * \param mbistSel Memory Selection
 * \return None
 *
 * Usage Example
 * \code
 *     // Enable VMT clock
 *     {
 *         IfxVmt_enableModule();
 *     }
 *
 *     {
 *       IfxVmt_enableMbistShell(IfxVmt_MbistSel_cpu0Dtag);
 *
 *       // Note: Wait for Auto-initilisation to be completed for auto-init memories like cpu-Dtag, cpu-Ptag,  Cpu-Dcache, Cpu-Pcache,
 *       while (IfxVmt_isAutoInitRunning(IfxVmt_MbistSel_cpu0Dtag))
 *       {}
 *     }
 * \endcode
 *
 */
IFX_INLINE void IfxVmt_enableMbistShell(IfxVmt_MbistSel mbistSel);

/** \brief Enables the VMT module
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE).
 * \param dmtuInstance this will point to the DMTU instance passed by th user(0 to 6)
 * \return None
 */
IFX_INLINE void IfxVmt_enableModule(Ifx_VMT *dmtuInstance);

/** \brief Returns TRUE if Auto-Initialisation is running for the given SRAM.
 *
 * Should be polled after MBIST enableMbistShell to ensure that an auto-init operation is finished before starting a new operation.
 * \param mbistSel Memory Selection
 * \return TRUE if auto-initialisation running.
 */
IFX_INLINE boolean IfxVmt_isAutoInitRunning(IfxVmt_MbistSel mbistSel);

/** \brief Returns the status of whether the module is enabled or not
 * \return
 */
IFX_INLINE boolean IfxVmt_isModuleEnabled(Ifx_VMT *dmtuInstance);

/** \brief Returns the CE alarms status registers
 * \param dmtu DMTU module pointer
 * \return CE Alarm register value
 */
IFX_INLINE uint32 IfxVmt_getDmtuCeAlarmStatus(Ifx_VMT *dmtu);

/** \brief Returns the UCE alarms status registers
 * \param dmtu DMTU module pointer
 * \return UCE Alarm register value
 */
IFX_INLINE uint32 IfxVmt_getDmtuUceAlarmStatus(Ifx_VMT *dmtu);

/** \brief Returns the ME alarms status registers
 * \param dmtu DMTU module pointer
 * \return ME Alarm register value
 */
IFX_INLINE uint32 IfxVmt_getDmtuMeAlarmStatus(Ifx_VMT *dmtu);

/** \} */

/** \addtogroup IfxLld_Vmt_Std_Operative
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief This function disables alarm-reporting flags
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE).
 * \param mbistSel Memory Selection
 * \return None
 */
IFX_INLINE void IfxVmt_disableErrorReporting(IfxVmt_MbistSel mbistSel);

/** \brief This function enables alarm-reporting flags
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE).
 * \param mbistSel Memory Selection
 * \return None
 */
IFX_INLINE void IfxVmt_enableErrorReporting(IfxVmt_MbistSel mbistSel);

/** \brief This Function returns the status of MBIST clear Sram operation.
 * Caution: It is recommended not to call this function continously in a loop. Use IfxVmt_clearSram() function for Synchronous polling mode.
 * \param mbistSel Memory Selection
 * \return status of Mbist Clear Sram operation (TRUE - Operation completed, FALSE - Operation still in progress)
 *
 * A coding example can be found in \ref IfxLld_Vmt_Usage
 *
 */
IFX_INLINE boolean IfxVmt_isMbistDone(IfxVmt_MbistSel mbistSel);

/** \brief Returns if MBIST enabled or not
 * \param mbistSel Memory Selection
 * \return MBIST enabled or not
 */
IFX_INLINE boolean IfxVmt_isMbistEnabled(IfxVmt_MbistSel mbistSel);

/** \brief Returns is the fail dump is available or not
 * \param mbistSel Memory Selection
 * \return Fail Dump available or not
 */
IFX_INLINE boolean IfxVmt_isMbistFda(IfxVmt_MbistSel mbistSel);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Function to Clear the MBIST SRAM (Synchronous mode).
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE).
 * \param mbistSel Memory Selection
 * \return None
 *
 * A coding example can be found in \ref IfxLld_Vmt_Usage
 *
 */
IFX_EXTERN void IfxVmt_clearSram(IfxVmt_MbistSel mbistSel);

/** \brief This Function should be called after MBIST Clear SRAM operation is completed.
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE).
 * \param mbistSel Memory Selection
 * \return None
 *
 * A coding example can be found in \ref IfxLld_Vmt_Usage
 *
 */
IFX_EXTERN void IfxVmt_clearSramContinue(IfxVmt_MbistSel mbistSel);

/** \brief This Function triggers the Clear the MBIST SRAM operation (Asynchronous operation). It doesn't wait till the end of operation.
 * The application has to poll the Mbist status (IfxVmt_isMbistDone()) in a task and once the operation is done, the IfxVmt_clearSramContinue() function should be called to complete the operation.
 * Alternately the application can enable the "memory test done" interrupt. And in the ISR, the IfxVmt_clearSramContinue()  has to be called.
 * If Synchronous usage is need, use IfxVmt_clearSram() function.
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE).
 * \param mbistSel Memory Selection
 * \return None
 *
 * A coding example can be found in \ref IfxLld_Vmt_Usage
 *
 */
IFX_EXTERN void IfxVmt_clearSramStart(IfxVmt_MbistSel mbistSel);

/** \brief Check if the last MBIST Passed
 *  This function shall check for all the configured SSH cells if the tests were passed
 * \param mbistConfig pointer to the configuration structure for the RAM test
 * \return TRUE: Test passed; FALSE: Test failed.
 */
IFX_EXTERN boolean IfxVmt_isTestPass(const IfxVmt_MbistConfig *mbistConfig);

/**
 * \param mbistSel Memory Selection
 * \param sramAddress SRAM address which should be read
 * \return None
 *
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE).
 * A coding example can be found in \ref IfxLld_Vmt_Usage
 *
 */
IFX_EXTERN void IfxVmt_readSramAddress(IfxVmt_MbistSel mbistSel, uint16 sramAddress);

/** \brief Run CheckerBoard test.  This test consists of writing the physical checkerboard pattern into the memory, then reading it back for verification
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE).
 * \param mbistSel Memory Selection
 * \param rangeSel enable/disable range Selection (0 - disable, 1- enable)
 * \param rangeAddrUp when range mode is enabled, it specifies the upper logical block address limit in 64 word increments.
 * \param rangeAddrLow when range mode is enabled, it specifies the lower logical block address limit.
 * \param errorAddr If the test fails, it contains the error address (bit0 - bit12) and memory block index (Bit13 - Bit15)
 * \param numberRedundancyLines Number of redundancy lines
 * \return Test Status (0-PASS, 1- FAIL)
 */
IFX_EXTERN uint8 IfxVmt_runCheckerBoardTest(IfxVmt_MbistSel mbistSel, uint8 rangeSel, uint8 rangeAddrUp, uint8 rangeAddrLow, uint16 *errorAddr, uint32 numberRedundancyLines);

/** \brief Run March U test.  This test MARCHES 0 and 1 values through the memory array in an up and down direction. More precisely, 0 and 1 values are propagated through the memory in each direction; i.e. a single bit cell toggles into each direction with the neighboring cells having a given value and, in another run, the inverse given value.
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE).
 * \param mbistSel Memory Selection
 * \param rangeSel enable/disable range Selection (0 - disable, 1- enable)
 * \param rangeAddrUp when range mode is enabled, it specifies the upper logical block address limit in 64 word increments.
 * \param rangeAddrLow when range mode is enabled, it specifies the lower logical block address limit.
 * \param errorAddr If the test fails, it contains the error address (bit0 - bit12) and memory block index (Bit13 - Bit15)
 * \return Test Status (0-PASS, 1- FAIL)
 */
IFX_EXTERN uint8 IfxVmt_runMarchUTest(IfxVmt_MbistSel mbistSel, uint8 rangeSel, uint8 rangeAddrUp, uint8 rangeAddrLow, uint16 *errorAddr);

/** \brief This function runs the Non-Destructive Inversion test algorithm.
 * Non-Destructive Inversion test can be considered as a simple linear test that is able to find all Stuck-At faults (the cell remains stuck at a value for any operation) without destroying any user data. The test accesses every Word in the address range defined by the RANGE register, four times.
 * Test Steps:
 * 1. Read data Word including check bits
 * 2. write back all bits inverted
 * 3. Read data Word including check bits
 * 4. Write back all bits inverted
 * At the end of this procedure the user data remains unchanged and and every bit has been set to 0 and 1. Any single Stuck-At error will be visible as a correctable error.
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE).
 * The Error flags need to be cleared to enable further tracking after the test
 * \param mbistSel Memory Selection
 * \param rangeSel enable/disable range Selection (0 - disable, 1- enable)
 * \param rangeAddrUp when range mode is enabled, it specifies the upper logical block address limit in 64 word increments.
 * \param rangeAddrLow when range mode is enabled, it specifies the lower logical block address limit.
 * \param errorAddr If the test fails, it contains the error address (bit0 - bit12) and memory block index (Bit13 - Bit15)
 * \return Test Status (0-PASS, 1- FAIL)
 */
IFX_EXTERN uint8 IfxVmt_runNonDestructiveInversionTest(IfxVmt_MbistSel mbistSel, uint8 rangeSel, uint8 rangeAddrUp, uint8 rangeAddrLow, uint16 *errorAddr);

/**
 * \param mbistSel Memory Selection
 * \param sramAddress SRAM address which should be written
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE).
 * \return None
 */
IFX_EXTERN void IfxVmt_writeSramAddress(IfxVmt_MbistSel mbistSel, uint16 sramAddress);

/** \brief Configures access to all masters to all the VMTs in the device
 * \param apConfig config pointer to configuration structure.
 * \return None
 */
IFX_EXTERN void IfxVmt_configureAccessToVmts(IfxApApu_ApuConfig *apConfig);

/** \} */

/** \addtogroup IfxLld_Vmt_Std_ErrorTracking
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the status of the error tracking
 * \param mbistSel Memory Selection
 * \return TRUE if error tracking enabled.
 */
IFX_INLINE boolean IfxVmt_isErrorTrackingEnabled(IfxVmt_MbistSel mbistSel);

/** \brief Returns the error tracking overflow status.
 * \param mbistSel Memory Selection
 * \return TRUE if more errors were detected since last clear than error tracking registers are available, or if more than one memory block was in error at the same time.
 */
IFX_INLINE boolean IfxVmt_isErrorTrackingOverflow(IfxVmt_MbistSel mbistSel);

/** \brief Returns True if any Error Flags are set
 * \param mbistSel Memory slection
 * \return True if any error Flag is set
 */
IFX_INLINE boolean IfxVmt_checkErrorFlags(IfxVmt_MbistSel mbistSel);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Clears the error tracking registers (ETRR), valid and overflow bits.
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE).
 * \param mbistSel Memory Selection
 * \return None
 *
 * A coding example can be found in \ref IfxLld_Vmt_Usage
 *
 */
IFX_EXTERN void IfxVmt_clearErrorTracking(IfxVmt_MbistSel mbistSel);

/** \brief Enables the tracking of SRAM errors.
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE).
 * \param mbistSel Memory Selection
 * \param enable TRUE to enable error tracking, FALSE to disable error tracking.
 * \return None
 *
 * A coding example can be found in \ref IfxLld_Vmt_Usage
 *
 */
IFX_EXTERN void IfxVmt_enableErrorTracking(IfxVmt_MbistSel mbistSel, boolean enable);

/** \brief Returns the tracked SRAM error addresses and memory blocks which are stored in the MBIST ETRR registers.
 * Note: The function should be called with adequate PROT and APU handling (PROTE/PROTCSE).
 * \param mbistSel Memory Selection
 * \param trackedSramAddresses will contain the tracked error addresses in trackedSramAdresses[x].B.ADDR and affected blocks in sramAddresses[x].B.MBI
 *
 * The array size shall be IFXVMT_MAX_TRACKED_ADDRESSES
 * \return number of tracked errors (0..IFXVMT_MAX_TRACKED_ADDRESSES)
 *
 * Example usage to print out tracked errors of a given memory:
 *
 * We assume that the VMT clock has already been enabled, and that the MBIST instance has been selected; e.g. for LMU:
 * \code
 *     uint16 password = IfxScuWdt_getCpuWatchdogPassword();
 *     IfxScuWdt_clearCpuEndinit(password);
 *
 *     IfxVmt_enableModule();
 *
 *     IfxVmt_MbistSel mbistSel = IfxVmt_MbistSel_lmu;
 *
 *     IfxVmt_enableMbistShell(mbistSel);
 *
 *     // for auto-init memories: wait for the end of the clear operation
 *     while (IfxVmt_isAutoInitRunning(mbistSel))
 *         {}
 * \endcode
 *
 * Now the tracking information can be retrieved with:
 *
 * \code
 *     {
 *         Ifx_MC_ETRR trackedSramAddresses[IFXVMT_MAX_TRACKED_ADDRESSES];
 *         uint8  numTrackedAddresses = IfxVmt_getTrackedSramAddresses(mbistSel, trackedSramAddresses);
 *
 *         for(int i=0; i<numTrackedAddresses; ++i) {
 *             clib_ver_printf("%d: A:0x%04x MBI:%d -> SystemAddress: 0x%08x\n",
 *                             i,
 *                             trackedSramAddresses[i].B.ADDR,
 *                             trackedSramAddresses[i].B.MBI,
 *                             IfxVmt_getSystemAddress(mbistSel, trackedSramAddresses[i]));
 *         }
 *     }
 * \endcode
 *
 */
IFX_EXTERN uint8 IfxVmt_getTrackedSramAddresses(IfxVmt_MbistSel mbistSel, Ifx_VMT_MC_ETRR *trackedSramAddresses);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief this API is used to get the DMTU Instance(0 to 6) corressponding to the ssh number passed
 */
IFX_INLINE uint32 IfxVmt_getSshInstance(IfxVmt_MbistSel sshNum);

/**
 * \return this API returns the pointer to the DMTU Instance corressponding to the SSH instance passed
 * If the SSH is a secure one it returns pointer to the secure DMTU Instance
 */
IFX_INLINE Ifx_VMT_MC *IfxVmt_getDmtuMcInstancePtr(IfxVmt_MbistSel mbistSel);

/** \brief Returns the DMTU base Address
 * \param mbistSel Memory Selection
 * \return DMTU base Address
 */
IFX_INLINE Ifx_VMT *IfxVmt_getDmtuAddress(IfxVmt_MbistSel mbistSel);

/** \brief Disables dmtuInstance
 * \param dmtuInstance this will point to the DMTU instance passed by th user(0 to 6)
 * \return None
 */
IFX_INLINE void IfxVmt_disableModule(Ifx_VMT *dmtuInstance);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Run the MBIST on all configured Gang configurations
 *      Requirements:
 *      1) This function shall run the tests on all SRAMs, which configured by the SSH structure array
 *       1.1) Address range (already scrambled address info) is made available through configuration
 *       1.2) Part of the test pattern is passed through MCONTROL
 *      2) For each cell, the test shall execute all the configuration patterns as passed through pattern array
 *       2.1) Test for each configuration pattern shall end either for the completion or for the failure
 *       2.2) Test shall only end if the test is finished (with or without pass) or timeout
 *       2.3) Failed test shall not be evaluated (this function only runs the tests)
 *     3) Function shall return TRUE if the test execution for one of the configuration patterns is not finished
 *     4) Function shall return FALSE if the test execution is finished
 * \param const mbistConfig[] mbistConfig pointer to the configuration structure for the SRAM test
 * \return TRUE: Test is successfully finished; FALSE: Test is not successfully finished.
 */
IFX_EXTERN boolean IfxVmt_runMbistAll(const IfxVmt_MbistConfig *const mbistConfig[]);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxVmt_disableErrorReporting(IfxVmt_MbistSel mbistSel)
{
    Ifx_VMT_MC *mc;
    mc                  = IfxVmt_getDmtuMcInstancePtr(mbistSel);
    mc->ALMSRCS.B.MISCE = 0;
    mc->ALMSRCS.B.OPENE = 0;
}


IFX_INLINE void IfxVmt_disableMbistShell(IfxVmt_MbistSel mbistSel)
{
    uint32           tempSel;
    uint32           sshSel;
    uint32           index;
    volatile uint32 *dmtuMemtest;
    uint32           mask;
    Ifx_VMT_MC      *mc;

    tempSel = mbistSel;

    if (((mbistSel & 0x100U) >> 8U) != 0U)
    {
        tempSel = (uint32)(mbistSel & 0xFFFFFEFFU);
    }

    sshSel = IfxVmt_getSshInstance((IfxVmt_MbistSel)tempSel);
    index  = (uint32)(sizeof(Ifx_VMT)) * (tempSel >> 5);
    mask   = 1 << (sshSel & 0x1F);

    if (((mbistSel & 0x100U) >> 8U) != 0U)
    {
        dmtuMemtest = (volatile uint32 *)((uint32)&VMT0_MEMTESTCS + index);
    }
    else
    {
        dmtuMemtest = (volatile uint32 *)((uint32)&VMT0_MEMTEST + index);
    }

    *dmtuMemtest &= ~mask;

    while (IfxVmt_isAutoInitRunning(mbistSel))
    {
        __nop();
    }

    /*Enable Error Reporting  */

    mc                  = IfxVmt_getDmtuMcInstancePtr(mbistSel);
    mc->ALMSRCS.B.MISCE = 1;
    mc->ALMSRCS.B.OPENE = 1;
}


IFX_INLINE void IfxVmt_enableErrorReporting(IfxVmt_MbistSel mbistSel)
{
    Ifx_VMT_MC *mc;
    mc                  = IfxVmt_getDmtuMcInstancePtr(mbistSel);
    mc->ALMSRCS.B.MISCE = 1;
    mc->ALMSRCS.B.OPENE = 1;
}


IFX_INLINE void IfxVmt_enableMbistShell(IfxVmt_MbistSel mbistSel)
{
    uint32           tempSel;
    uint32           sshSel;
    uint32           index;
    volatile uint32 *dmtuMemtest;
    uint32           mask;
    Ifx_VMT_MC      *mc;

    tempSel = mbistSel;

    if (((mbistSel & 0x100U) >> 8U) != 0U)
    {
        tempSel = (uint32)(mbistSel & 0xFFFFFEFFU);
    }

    sshSel              = IfxVmt_getSshInstance((IfxVmt_MbistSel)tempSel);
    index               = (uint32)(sizeof(Ifx_VMT)) * (tempSel >> 5);

    mc                  = IfxVmt_getDmtuMcInstancePtr(mbistSel);
    mc->ALMSRCS.B.MISCE = 0;
    mc->ALMSRCS.B.OPENE = 0;
    mask                = 1 << (sshSel & 0x1F);

    if (((mbistSel & 0x100U) >> 8U) != 0U)
    {
        dmtuMemtest = (volatile uint32 *)((uint32)&VMT0_MEMTESTCS + index);
    }
    else
    {
        dmtuMemtest = (volatile uint32 *)((uint32)&VMT0_MEMTEST + index);
    }

    *dmtuMemtest |= mask;
}


IFX_INLINE void IfxVmt_enableModule(Ifx_VMT *dmtuInstance)
{
    /*VMT clock enable */
    dmtuInstance->CLC.U = 0x0U;
}


IFX_INLINE boolean IfxVmt_isAutoInitRunning(IfxVmt_MbistSel mbistSel)
{
    uint32           tempSel;
    uint32           sshSel;
    uint32           index;
    volatile uint32 *vmtMemstat;
    uint32           mask;

    tempSel = mbistSel;

    if (((mbistSel & 0x100U) >> 8U) != 0U)
    {
        tempSel = (uint32)(mbistSel & 0xFFFFFEFFU);
    }

    sshSel = IfxVmt_getSshInstance((IfxVmt_MbistSel)tempSel);
    index  = (uint32)(sizeof(Ifx_VMT)) * (tempSel >> 5);
    mask   = 1 << (sshSel & 0x1f);

    if (((mbistSel & 0x100U) >> 8U) != 0U)
    {
        vmtMemstat = (volatile uint32 *)((uint32)&VMT0_MEMSTATCS + index);
    }
    else
    {
        vmtMemstat = (volatile uint32 *)((uint32)&VMT0_MEMSTAT + index);
    }

    return (*vmtMemstat & mask) != 0;
}


IFX_INLINE boolean IfxVmt_isErrorTrackingEnabled(IfxVmt_MbistSel mbistSel)
{
    Ifx_VMT_MC *mc;
    mc = IfxVmt_getDmtuMcInstancePtr(mbistSel);

    return mc->ECCS.B.TRE ? TRUE : FALSE;
}


IFX_INLINE boolean IfxVmt_isErrorTrackingOverflow(IfxVmt_MbistSel mbistSel)
{
    Ifx_VMT_MC *mc;
    mc = IfxVmt_getDmtuMcInstancePtr(mbistSel);
    return mc->ECCD.B.EOV ? TRUE : FALSE;
}


IFX_INLINE boolean IfxVmt_isMbistDone(IfxVmt_MbistSel mbistSel)
{
    uint32           tempSel;
    uint32           sshSel;
    uint32           index;
    volatile uint32 *memdone;
    uint32           mask;

    tempSel = mbistSel;

    if (((mbistSel & 0x100U) >> 8U) != 0U)
    {
        tempSel = (uint32)(mbistSel & 0xFFFFFEFFU);
    }

    sshSel = IfxVmt_getSshInstance((IfxVmt_MbistSel)tempSel);
    index  = (uint32)(sizeof(Ifx_VMT)) * (tempSel >> 5);
    mask   = 1 << (sshSel & 0x1f);

    if (((mbistSel & 0x100U) >> 8U) != 0U)
    {
        memdone = (volatile uint32 *)((uint32)&VMT0_MEMDONECS + index);
    }
    else
    {
        memdone = (volatile uint32 *)((uint32)&VMT0_MEMDONE + index);
    }

    return (*memdone & mask) != 0;
}


IFX_INLINE boolean IfxVmt_isModuleEnabled(Ifx_VMT *dmtuInstance)
{
    return dmtuInstance->CLC.B.DISS == 0;
}


IFX_INLINE boolean IfxVmt_checkErrorFlags(IfxVmt_MbistSel mbistSel)
{
    Ifx_VMT_MC *mc;
    mc = IfxVmt_getDmtuMcInstancePtr(mbistSel);
    return (boolean)((mc->ECCD.U & IFXVMT_ERROR_FLAGS_MASK) > 0);
}


IFX_INLINE uint32 IfxVmt_getSshInstance(IfxVmt_MbistSel sshNum)
{
    /* Clear the 8th bit which indicates if CS-SSH */
    uint32 tempSsh;
    tempSsh = (uint32)sshNum;

    /* Clear the 8th bit which indicates if CS-SSH */
    if ((tempSsh >> 8U) != 0U)
    {
        tempSsh = (uint32)(tempSsh & 0xFFFFFEFFU);
    }

    tempSsh = (uint32)(tempSsh % 32U);

    return tempSsh;
}


IFX_INLINE Ifx_VMT_MC *IfxVmt_getDmtuMcInstancePtr(IfxVmt_MbistSel mbistSel)
{
    uint32            tempSel;
    uint32            sshSel;
    uint32            index;
    volatile Ifx_VMT *dmtuInstance;
    Ifx_VMT_MC       *mc;

    tempSel = mbistSel;

    if ((mbistSel >> 8U) != 0U)
    {
        tempSel = (uint32)(mbistSel & 0xFFFFFEFFU);
    }

    sshSel       = IfxVmt_getSshInstance((IfxVmt_MbistSel)tempSel);
    index        = (uint32)(sizeof(Ifx_VMT)) * (tempSel >> 5);
    dmtuInstance = (volatile Ifx_VMT *)((uint32)&MODULE_VMT0 + index);

    if ((mbistSel >> 8U) != 0U)
    {
        mc = (Ifx_VMT_MC *)&dmtuInstance->MCCS[sshSel];
    }
    else
    {
        mc = &dmtuInstance->MC[sshSel];
    }

    return mc;
}


IFX_INLINE uint32 IfxVmt_getDmtuCeAlarmStatus(Ifx_VMT *dmtu)
{
    return dmtu->CEALARM.U;
}


IFX_INLINE uint32 IfxVmt_getDmtuUceAlarmStatus(Ifx_VMT *dmtu)
{
    return dmtu->UCEALARM.U;
}


IFX_INLINE uint32 IfxVmt_getDmtuMeAlarmStatus(Ifx_VMT *dmtu)
{
    return dmtu->MEALARM.U;
}


IFX_INLINE boolean IfxVmt_isMbistEnabled(IfxVmt_MbistSel mbistSel)
{
    uint32           tempSel;
    uint32           sshSel;
    uint32           index;
    volatile uint32 *vmtMemtest;
    uint32           mask;

    tempSel = mbistSel;

    if (((mbistSel & 0x100U) >> 8U) != 0U)
    {
        tempSel = (uint32)(mbistSel & 0xFFFFFEFFU);
    }

    sshSel = IfxVmt_getSshInstance((IfxVmt_MbistSel)tempSel);
    index  = (uint32)(sizeof(Ifx_VMT)) * (tempSel >> 5);
    mask   = 1 << (sshSel & 0x1f);

    if (((mbistSel & 0x100U) >> 8U) != 0U)
    {
        vmtMemtest = (volatile uint32 *)((uint32)&VMT0_MEMTESTCS + index);
    }
    else
    {
        vmtMemtest = (volatile uint32 *)((uint32)&VMT0_MEMTEST + index);
    }

    return (*vmtMemtest & mask) != 0U;
}


IFX_INLINE boolean IfxVmt_isMbistFda(IfxVmt_MbistSel mbistSel)
{
    /* Read MSTATUS to clear FDA when it has been set */
    Ifx_VMT_MC *mc     = IfxVmt_getDmtuMcInstancePtr(mbistSel);
    uint32      status = mc->MSTATUS.U;
    return (status & (1 << IFX_VMT_MC_MSTATUS_FDA_OFF)) > 0;
}


IFX_INLINE Ifx_VMT *IfxVmt_getDmtuAddress(IfxVmt_MbistSel mbistSel)
{
    uint32   index       = (uint32)(sizeof(Ifx_VMT)) * ((mbistSel & 0x0ff) >> 5);
    Ifx_VMT *dmtuAddress = (volatile Ifx_VMT *)((uint32)&MODULE_VMT0 + index);

    return dmtuAddress;
}


IFX_INLINE void IfxVmt_disableModule(Ifx_VMT *dmtuInstance)
{
    /*VMT clock disable */
    dmtuInstance->CLC.U = 0x1U;
}


#endif /* IFXVMT_H */
