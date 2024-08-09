/**
 * \file Ifx_TypesReg.h
 * \brief
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 * Version: IFXREGTYPES_V1.0.R0
 *
 * MAY BE CHANGED BY USER [yes/no]: No
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
 *
 * Data type access rules for peripheral space
 * data type                               | Allowed access size   | Alignment of address in memory
 * ----------------------------------------|-----------------------|-----------------------------------
 * Ifx_UReg_8Bit, Ifx_SReg_8Bit            | Byte                  | Byte (1H)                         
 * Ifx_UReg_16Bit, Ifx_SReg_16Bit          | Byte, Half-Word       | 2 bytes (2H)                      
 * Ifx_UReg_32Bit, Ifx_SReg_32Bit          | Byte, Half-Word, Word | 4 bytes (4H)                      
 * Ifx_Strict_16Bit                        | Half-Word             | 2 bytes (2H)                      
 * Ifx_Strict_32Bit                        | Word                  | 4 bytes (4H)                      
 * 
 * 
 * Alignment rules for peripheral space (From TriCoreTM TC1.6.2 core architecture manual, 2.2.1 Alignment Requirements)
 * Access type                             | Access size           | Required alignment of address in memory    
 * ----------------------------------------|-----------------------|-----------------------------------
 * Load, Store Data Register               | Byte (8-bits)         | Byte (1H)                         
 * Load, Store Data Register               | Half-Word (16-bits)   | 2 bytes (2H)                      
 * Load, Store Data Register               | Word (32-bits)        | 4 bytes (4H)                      
 * Load, Store Data Register               | Double-Word (64-bits) | 8 bytes (8H)                      
 * Load, Store Address Register            | Word                  | 4 bytes (4H)                      
 * Load, Store Address Register            | Double-Word           | 8 bytes (8H)                      
 * SWAP.W, LDMST, ST.T                     | Word                  | 4 bytes (4H)                      
 * CMPSWAP.W, SWAPMSK.W                    | Word                  | 4 bytes (4H)                      
 * Context Load / Store / Restore / Save   | 16 x 32-bit registers | Not Permitted                     
 * 
 * 
 * 
 *  Peripheral space : segment F and E (From TriCoreTM TC1.6.2 core architecture manual, 8.3.4 Default Memory types for all segments)
 */

#ifndef IFX_TYPESREG_H
#define IFX_TYPESREG_H
/******************************************************************************/

#if defined(__TASKING__)
 #if defined(__CTC__) || defined(__CPTC__)
 #define Ifx_Strict_16Bit unsigned __sfrbit16
 #define Ifx_Strict_32Bit unsigned __sfrbit32
 #define Ifx_Strict_64Bit volatile unsigned long long /* compiler support needed */
 #else
 #define Ifx_Strict_16Bit volatile unsigned short
 #define Ifx_Strict_32Bit volatile unsigned int
 #define Ifx_Strict_64Bit volatile unsigned long long
 #endif
typedef unsigned __sfrbit32   Ifx_UReg_32Bit; /* Workaround for the VP, will be removed later */
#elif defined(__GNUC__) && !defined(__arc__)
#if defined(__cplusplus)
#define Ifx_Strict_16Bit unsigned short
#define Ifx_Strict_32Bit unsigned int
#define Ifx_Strict_64Bit unsigned long long
#else
#define Ifx_Strict_16Bit volatile unsigned short
#define Ifx_Strict_32Bit volatile unsigned int
#define Ifx_Strict_64Bit volatile unsigned long long
#endif
typedef unsigned int   Ifx_UReg_32Bit;
#elif defined(__DCC__)
#define Ifx_Strict_16Bit unsigned short
#define Ifx_Strict_32Bit unsigned int
#define Ifx_Strict_64Bit volatile unsigned long long
typedef unsigned int   Ifx_UReg_32Bit;
#elif defined(__ghs__)
#define Ifx_Strict_16Bit volatile unsigned short
#define Ifx_Strict_32Bit volatile unsigned int
#define Ifx_Strict_64Bit volatile unsigned long long
typedef unsigned int   Ifx_UReg_32Bit;
#elif defined(__arc__)
#define Ifx_Strict_16Bit volatile unsigned short
#define Ifx_Strict_32Bit volatile unsigned int
#define Ifx_Strict_64Bit volatile unsigned long long
typedef unsigned int   Ifx_UReg_32Bit;
#endif
typedef unsigned char  Ifx_UReg_8Bit;
typedef unsigned short Ifx_UReg_16Bit;
typedef unsigned long long Ifx_UReg_64Bit;
typedef signed char    Ifx_SReg_8Bit;
typedef signed short   Ifx_SReg_16Bit;
typedef signed int     Ifx_SReg_32Bit;
typedef signed long long Ifx_SReg_64Bit;
 

/* Access types for registers */
#define __I /*!< defines 'read only' permissions */
#define __O /*!< defines 'write only' permissions */
#define __IO /*!< defines 'read / write' permissions */

/******************************************************************************/
#endif /* IFX_TYPESREG_H */
