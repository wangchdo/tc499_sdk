/**
 *
 * \version iLLD_2_0_1_2_19
 * \copyright Copyright (c) 2020 Infineon Technologies AG. All rights reserved.
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
 */

#ifndef TRICOREIPC_H_
#define TRICOREIPC_H_

#include "Common/IfxMailbox.h"

/** \brief Interrupt priority for TC0
 */
#define IFX_INTPRIO_IPC_TC0 1

/** \brief Interrupt priority for TC1
 */
#define IFX_INTPRIO_IPC_TC1 1

/** \brief Interrupt priority for TC2
 */
#define IFX_INTPRIO_IPC_TC2 1

/** \brief Interrupt priority for TC3
 */
#define IFX_INTPRIO_IPC_TC3 1

/** \brief Interrupt priority for TC4
 */
#define IFX_INTPRIO_IPC_TC4 1

/** \brief Interrupt priority for TC5
 */
#define IFX_INTPRIO_IPC_TC5 1

/** \brief Interrupt priority for PPU ICI
 */
#define IFX_INTPRIO_C2S 23

/** \brief Remote Procedure call API which is used to access the PPUC Service
 * This will first try to lock the PPU for the specific TCx.
 * If the Lock is acquired it will then fill the mailbox and trigger the PPUs service
 * \param kernel_id The specific PPU Kernel service to be requested
 * \param arg_cnt The number of arguments
 * \param *args[] Pointer to the arguments
 * \return Returns the status as 0 for Success or others if not successful
 */
IfxMailbox_Status IfxTcIpc_Rpc(unsigned int id, unsigned int arg_cnt, int *args[]);

/** \brief API to initialize the S2C interrupt for TC0
 */
void IfxTcIpc_initS2CInterruptTc0(void);

/** \brief API to initialize the S2C interrupt for TC1
 */
void IfxTcIpc_initS2CInterruptTc1(void);

/** \brief API to initialize the S2C interrupt for TC2
 */
void IfxTcIpc_initS2CInterruptTc2(void);

/** \brief API to initialize the S2C interrupt for TC3
 */
void IfxTcIpc_initS2CInterruptTc3(void);

/** \brief API to initialize the S2C interrupt for TC4
 */
void IfxTcIpc_initS2CInterruptTc4(void);

/** \brief API to initialize the S2C interrupt for TC5
 */
void IfxTcIpc_initS2CInterruptTc5(void);

#endif /* TRICOREIPC_H_ */
