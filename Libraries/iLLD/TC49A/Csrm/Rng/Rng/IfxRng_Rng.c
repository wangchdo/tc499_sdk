/**
 * \file IfxRng_Rng.c
 * \brief RNG RNG details
 *
 * \version iLLD_2_0_1_2_19
 * \copyright Copyright (c) 2021 Infineon Technologies AG. All rights reserved.
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxRng_Rng.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

IfxRng_status IfxRng_Rng_getAndUpdateError(IfxRng_Rng *rng)
{
    IfxRng_status status = IfxRng_status_success;

    if (IfxRng_getErrorStatus(rng->rngSFR) == TRUE)
    {
        status = IfxRng_status_failure;

        Ifx_RNG_STAT reg;
        reg.U                           = rng->rngSFR->STAT.U;

        rng->errors.Bits.entropyError   = (uint32)(reg.B.ERR_ENTROPY);
        rng->errors.Bits.statisticError = (uint32)(reg.B.ERR_STATISTIC);
        rng->errors.Bits.maxDataError   = (uint32)(reg.B.ERR_MAXDATA);
        rng->errors.Bits.seedingError   = (uint32)(reg.B.ERR_SEED);
    }

    return status;
}


void IfxRng_Rng_initConfig(Ifx_RNG *rngSFR, IfxRng_Rng_Config *config)
{
    const IfxRng_Rng_Config defaultConfig = {
        .mode            = IfxRng_operationMode_TRNG,
        .seedType        = IfxRng_seedType_internal,
        .seedLength      = IfxRng_seedLength_64Bits,
        .expansionRate   = IfxRng_expansionRate_1,
        .externalSeedPtr = NULL_PTR,
        .rngSFR          = NULL_PTR
    };

    *config        = defaultConfig;

    config->rngSFR = rngSFR;
}


IfxRng_status IfxRng_Rng_init(IfxRng_Rng *rng, IfxRng_Rng_Config *config)
{
    IfxRng_status status       = IfxRng_status_success;
    uint32        timeoutCount = IFXRNG_TIMEOUT_COUNT;
    rng->rngSFR = config->rngSFR;
    rng->state  = IfxRng_state_unknown;

    Ifx_RNG      *rngSFR = rng->rngSFR;

    /* clear all errors in handle */
    rng->errors.Word = 0U;

    /* Step 1: change to config mode */
    IfxRng_setModuleState(rngSFR, IfxRng_state_config);

    /* wait for module to get into configuration mode */
    while ((IfxRng_getModuleState(rngSFR) != IfxRng_state_config) && (timeoutCount > 0))
    {
        timeoutCount--;
    }

    /* Check if module is in configuration mode */
    if (timeoutCount > 0)
    {
        rng->state = IfxRng_state_config;

        /* Step 2: Write configuration */
        Ifx_RNG_CONFIG cfg;
        cfg.U = rngSFR->CONFIG.U;

        /* Step 2.1: Write operational mode */
        cfg.B.MODE = (uint32)(config->mode);

        /* Step 2.2: Write other configurations for HRNG mode */
        if (config->mode == IfxRng_operationMode_HRNG)
        {
            /* External seeding not allowed for expansionRate = 1 */
            if ((config->expansionRate == IfxRng_expansionRate_1) && (config->seedType == IfxRng_seedType_external))
            {
                rng->errors.Bits.invalidConfig = (uint32)1;
                status                         = IfxRng_status_failure;
            }
            else
            {
                cfg.B.SEED     = (uint32)(config->seedType);
                cfg.B.SEED_LEN = (uint32)(config->seedLength);
                cfg.B.EXP_RATE = (uint32)(config->expansionRate);
            }
        }
        /* Step 2.3: Write other configurations for DRNG mode */
        else if (config->mode == IfxRng_operationMode_DRNG)
        {
            cfg.B.SEED     = (uint32)(config->seedType);
            cfg.B.SEED_LEN = (uint32)(config->seedLength);
        }

        if (status != IfxRng_status_failure)
        {
#if (IFX_PROT_ENABLED == 1U)
            IfxApProt_setState((Ifx_PROT_PROT *)&rngSFR->PROTE, IfxApProt_State_config);
#endif

            rngSFR->CONFIG.U = cfg.U;

#if (IFX_PROT_ENABLED == 1U)
            IfxApProt_setState((Ifx_PROT_PROT *)&rngSFR->PROTE, IfxApProt_State_run);
#endif

            /* Step 3: Write external seed */
            if (config->seedType == IfxRng_seedType_external)
            {
                status |= IfxRng_Rng_writeExternalSeed(rng, config->externalSeedPtr, config->seedLength);
            }
        }

        if (status != IfxRng_status_failure)
        {
            /* Step 4: change to operation mode */
            IfxRng_setModuleState(rngSFR, IfxRng_state_operation);

            timeoutCount = IFXRNG_TIMEOUT_COUNT;

            /* wait for module to get into operation mode */
            while ((IfxRng_getModuleState(rngSFR) != IfxRng_state_operation) && (timeoutCount > 0))
            {
                timeoutCount--;
            }

            /* Check if module is in operation mode */
            if (timeoutCount > 0)
            {
                rng->state = IfxRng_state_operation;
            }
            else
            {
                (void)IfxRng_Rng_getAndUpdateError(rng);
                status = IfxRng_status_failure;
            }
        }
    }
    /* if module could not enter configuration mode */
    else
    {
        (void)IfxRng_Rng_getAndUpdateError(rng);
        status = IfxRng_status_failure;
    }

    return status;
}


uint32 IfxRng_Rng_readResult(IfxRng_Rng *rng)
{
    uint32 word         = 0;
    uint32 timeoutCount = IFXRNG_TIMEOUT_COUNT;

    /* check whether the module initialization was done */
    if (rng->state == IfxRng_state_operation)
    {
        /* Check if module is in operation mode */
        if (IfxRng_getModuleState(rng->rngSFR) == IfxRng_state_operation)
        {
            /* wait for data to be ready */
            while (timeoutCount > 0)
            {
                /* read data if it is ready */
                if (IfxRng_isRandomDataReady(rng->rngSFR))
                {
                    word = (uint32)(rng->rngSFR->RAND.B.DATA);
                    break;
                }

                /* assert error if any error bit is set */
                if (IfxRng_Rng_getAndUpdateError(rng) == IfxRng_status_failure)
                {
                    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
                }

                timeoutCount--;
            }

            if (timeoutCount == 0)
            {
                /* assert error if timeout is exceeded */
                IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
            }
        }
        else
        {
            (void)IfxRng_Rng_getAndUpdateError(rng);
            IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
        }
    }
    else
    {
        rng->errors.Bits.softwareError = (uint32)1;
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }

    return word;
}


IfxRng_status IfxRng_Rng_readResultFifo(IfxRng_Rng *rng, uint32 numWords)
{
    IfxRng_status status = IfxRng_status_success;
    uint32       *destPtr;
    uint32        word;
    uint32        index = 0;
    destPtr               = rng->resultPtr;
    rng->validResultWords = 0;

    for (index = 0; index < numWords; index++)
    {
        if (IfxRng_Rng_getAndUpdateError(rng) == IfxRng_status_failure)
        {
            status = IfxRng_status_failure;
            break;
        }

        word           = IfxRng_Rng_readResult(rng);
        destPtr[index] = word;
        rng->validResultWords++;
    }

    return status;
}


IfxRng_status IfxRng_Rng_writeExternalSeed(IfxRng_Rng *rng, uint32 *seedPtr, IfxRng_seedLength seedLength)
{
    IfxRng_status status = IfxRng_status_success;

    /* Write external seed only if module is in config mode */
    if (IfxRng_getModuleState(rng->rngSFR) == IfxRng_state_config)
    {
        uint8  seedLengthWords;
        uint32 timeoutCount;
        int    index;

        /* S = (SEED_LEN+2) words */
        seedLengthWords = (uint8)((uint32)(seedLength) + 2);

        for (index = 0; index < seedLengthWords; index++)
        {
            timeoutCount = IFXRNG_TIMEOUT_COUNT;

            /* wait for module to get ready to accept external seed */
            while ((IfxRng_isSeedInputReady(rng->rngSFR) == FALSE) && (timeoutCount > 0))
            {
                timeoutCount--;
            }

            /* write seed */
            if (timeoutCount > 0)
            {
                rng->rngSFR->SEED.U = *seedPtr;
                seedPtr++;
            }
            /* report failure and break */
            else
            {
                status = IfxRng_status_failure;
                break;
            }
        }

        /* Wait for register to be updated */
        timeoutCount = IFXRNG_TIMEOUT_COUNT;

        while (IfxRng_isExternalSeedingDone(rng->rngSFR) == FALSE && (timeoutCount > 0))
        {
            timeoutCount--;
        }

        /* Check if seeding is complete */
        if (IfxRng_isExternalSeedingDone(rng->rngSFR) == FALSE)
        {
            status = IfxRng_status_failure;
        }
    }
    /* module is not in config mode */
    else
    {
        status = IfxRng_status_failure;
    }

    return status;
}


IfxRng_status IfxRng_Rng_writeExtraInput(IfxRng_Rng *rng, uint32 data)
{
    IfxRng_status status = IfxRng_status_success;

    /* Write extra input only if module is in operational mode */
    if (IfxRng_getModuleState(rng->rngSFR) == IfxRng_state_operation)
    {
        uint32 timeoutCount;
        timeoutCount = IFXRNG_TIMEOUT_COUNT;

        /* wait for module to get ready to accept extra input */
        while ((IfxRng_isSeedInputReady(rng->rngSFR) == FALSE) && (timeoutCount > 0))
        {
            timeoutCount--;
        }

        /* write seed */
        if (timeoutCount > 0)
        {
            rng->rngSFR->SEED.U = data;
        }
        /* report failure and break */
        else
        {
            status = IfxRng_status_failure;
        }
    }
    /* module is not in operational mode */
    else
    {
        status = IfxRng_status_failure;
    }

    return status;
}
