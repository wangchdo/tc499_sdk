/**
 * \file IfxScu_cfg.h
 * \brief SCU on-chip implementation data
 * \ingroup IfxLld_Scu
 *
 * \version iLLD_2_0_1_2_19
 * \copyright Copyright (c) 2012 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup IfxLld_Scu SCU
 * \ingroup IfxLld
 * \defgroup IfxLld_Scu_Impl Implementation
 * \ingroup IfxLld_Scu
 * \defgroup IfxLld_Scu_Std Standard Driver
 * \ingroup IfxLld_Scu
 */

#ifndef IFXSCU_CFG_H
#define IFXSCU_CFG_H
/******************************************************************************/
#include "Ifx_Cfg.h"

/******************************************************************************/
/*                           Macro                                            */
/******************************************************************************/

/******************************************************************************/
/*---------------------------LBIST Config Macros------------------------------*/
/******************************************************************************/
#ifndef IFXSCULBIST_CFG_SIGNATURE_A
#ifndef IFX_CFG_LBIST_BODY_ENABLED
#define IFXSCULBIST_CFG_SIGNATURE_A         (0x01432DEBU)
#else
#define IFXSCULBIST_CFG_SIGNATURE_A         (0xF8097B38U)
#endif
#endif

#ifndef IFXSCULBIST_CFG_SIGNATURE_B
#ifndef IFX_CFG_LBIST_BODY_ENABLED
#define IFXSCULBIST_CFG_SIGNATURE_B         (0x80835418U)
#else
#define IFXSCULBIST_CFG_SIGNATURE_B         (0xDD5B50C5U)
#endif
#endif

#ifndef IFXSCULBIST_CFG_PATTERN_A
#define IFXSCULBIST_CFG_PATTERN_A           (0x80U)
#endif

#ifndef IFXSCULBIST_CFG_PATTERN_B
#define IFXSCULBIST_CFG_PATTERN_B           (0x500U)
#endif

#ifndef IFXSCULBIST_CFG_SCANCHAINLENGTH
#define IFXSCULBIST_CFG_SCANCHAINLENGTH     (0x86U)
#endif

#ifndef IFXSCULBIST_CFG_SEED
#define IFXSCULBIST_CFG_SEED                (0x07U)
#endif

/******************************************************************************/
/*                           Enum                                             */
/******************************************************************************/


/******************************************************************************/

#endif /* IFXSCU_CFG_H */
