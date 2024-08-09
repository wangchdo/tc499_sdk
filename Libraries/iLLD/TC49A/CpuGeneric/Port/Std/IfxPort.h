/**
 * \file IfxPort.h
 * \brief PORT  basic functionality
 * \ingroup IfxLld_Port
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
 * \defgroup IfxLld_Port_Prot_Usage How to use the PORT driver along with PROT?
 * \ingroup IfxLld_Port
 *
 * As per the current POR, each PORT module will have a set/group of APU registers. And each pin in a PORT module can be assigned to one of these APU groups.
 *
 * The way to use the APIs to configure the APU for PORT is as follows:
 *
 * 1. Configure the PROT_SE Owner.
 * 2. Configure the PADCFG.ACCEN.GRP bit field to map the pin to the APU group.
 * 3. Configure the APU registers to enable the Access Protection.
 *
 * In your application you can do the following to enable the PROT and configure the APU for the PORT
 *
 * \code
 * IfxPort_ProtConfig protConfig;
 * IfxPort_ApuConfig apuConfig;
 *
 * IfxPort_initProtConfig(&protConfig);
 * IfxPort_initApuConfig(&apuConfig);
 *
 * //Which APU group needs to be initialised
 * apuConfig.grpNum = 1U;
 *
 * //Initialize the PROT with the Owner
 * IfxPort_initProt(&MODULE_P00, &protConfig);
 *
 * //Configure the specific pin to map to a APU group "1", for example pin "2" of P00
 * IfxPort_setApuGroupSelection(&MODULE_P00, 2, 1);
 *
 * //Configure the APU and initialize it
 * IfxPort_initApu(&MODULE_P00, &apuConfig);
 * \endcode
 *
 * In case you want to configure multiple pins of the same PORT, this can be done using the API IfxPort_initApuGroups
 *
 * \defgroup IfxLld_Port_Std_Enum Enumerations
 * \ingroup IfxLld_Port_Std
 * \defgroup IfxLld_Port_Std_DataStructures Data structures
 * \ingroup IfxLld_Port_Std
 * \defgroup IfxLld_Port_Std_SinglePin Single Pin Functions
 * \ingroup IfxLld_Port_Std
 * \defgroup IfxLld_Port_Std_PortGroup Group Access Functions
 * \ingroup IfxLld_Port_Std
 */

#ifndef IFXPORT_H
#define IFXPORT_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxPort_cfg.h"
#include "Ap/Std/IfxApProt.h"
#include "Ap/Std/IfxApApu.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Port_Std_Enum
 * \{ */
/** \brief The LVDS RX_DIS control function can be selected from the Port (default) or
 * HSCT module.declared in MODULE_PORTx.LPCRx
 */
typedef enum
{
    IfxPort_ControlledBy_port = 0,  /**< \brief port controlled by PORT Module */
    IfxPort_ControlledBy_hsct = 1   /**< \brief Port controlled by HSCT Module */
} IfxPort_ControlledBy;

/** \brief Ifx_P output modification modes definition.
 */
typedef enum
{
    IfxPort_InputMode_undefined    = -1,
    IfxPort_InputMode_noPullDevice = ((0U << 4U) | (0U << 1U) | 0U),
    IfxPort_InputMode_pullDown     = ((1U << 4U) | (0U << 1U) | 0U),
    IfxPort_InputMode_pullUp       = ((2U << 4U) | (0U << 1U) | 0U)
} IfxPort_InputMode;

/** \brief specifies LVDS-M or LVDS-H mode as declare in Register MODULE_PORT.LPCRx.LVDSM
 */
typedef enum
{
    IfxPort_LvdsMode_high   = 0, /**< \brief LVDS-H Mode */
    IfxPort_LvdsMode_medium = 1  /**< \brief LVDS-M Mode */
} IfxPort_LvdsMode;

/** \brief specifies external or internal LVDS reciever Termination Mode
 */
typedef enum
{
    IfxPort_LvdsTerm_external = 0,  /**< \brief external termination */
    IfxPort_LvdsTerm_internal = 1   /**< \brief 100 Ohm internal termination */
} IfxPort_LvdsTerm;

/** \brief Ifx_P input / output mode definition.
 *
 * \see Ifx_P.IOCR, IfxPort_setPinMode()
 */
typedef enum
{
    IfxPort_Mode_inputNoPullDevice      = ((0U << 4U) | (0U << 1U) | 0U),  /**< \brief Input, No pull device connected. */
    IfxPort_Mode_inputPullDown          = ((1U << 4U) | (0U << 1U) | 0U),  /**< \brief Input, pull-down device connected. */
    IfxPort_Mode_inputPullUp            = ((2U << 4U) | (0U << 1U) | 0U),  /**< \brief Input, pull-up device connected. */
    IfxPort_Mode_outputPushPullGeneral  = ((0U << 4U) | (0U << 1U) | 1U),  /**< \brief Push-pull, General-purpose output */
    IfxPort_Mode_outputPushPullAlt1     = ((1U << 4U) | (0U << 1U) | 1U),  /**< \brief Push-pull, Alternate output function 1. */
    IfxPort_Mode_outputPushPullAlt2     = ((2U << 4U) | (0U << 1U) | 1U),  /**< \brief Push-pull, Alternate output function 2. */
    IfxPort_Mode_outputPushPullAlt3     = ((3U << 4U) | (0U << 1U) | 1U),  /**< \brief Push-pull, Alternate output function 3. */
    IfxPort_Mode_outputPushPullAlt4     = ((4U << 4U) | (0U << 1U) | 1U),  /**< \brief Push-pull, Alternate output function 4. */
    IfxPort_Mode_outputPushPullAlt5     = ((5U << 4U) | (0U << 1U) | 1U),  /**< \brief Push-pull, Alternate output function 5. */
    IfxPort_Mode_outputPushPullAlt6     = ((6U << 4U) | (0U << 1U) | 1U),  /**< \brief Push-pull, Alternate output function 6. */
    IfxPort_Mode_outputPushPullAlt7     = ((7U << 4U) | (0U << 1U) | 1U),  /**< \brief Push-pull, Alternate output function 7. */
    IfxPort_Mode_outputPushPullAlt8     = ((8U << 4U) | (0U << 1U) | 1U),  /**< \brief Push-pull, Alternate output function 8. */
    IfxPort_Mode_outputPushPullAlt9     = ((9U << 4U) | (0U << 1U) | 1U),  /**< \brief Push-pull, Alternate output function 9. */
    IfxPort_Mode_outputPushPullAlt10    = ((10U << 4U) | (0U << 1U) | 1U), /**< \brief Push-pull, Alternate output function 10. */
    IfxPort_Mode_outputPushPullAlt11    = ((11U << 4U) | (0U << 1U) | 1U), /**< \brief Push-pull, Alternate output function 11. */
    IfxPort_Mode_outputPushPullAlt12    = ((12U << 4U) | (0U << 1U) | 1U), /**< \brief Push-pull, Alternate output function 12. */
    IfxPort_Mode_outputPushPullAlt13    = ((13U << 4U) | (0U << 1U) | 1U), /**< \brief Push-pull, Alternate output function 13. */
    IfxPort_Mode_outputPushPullAlt14    = ((14U << 4U) | (0U << 1U) | 1U), /**< \brief Push-pull, Alternate output function 14. */
    IfxPort_Mode_outputPushPullAlt15    = ((15U << 4U) | (0U << 1U) | 1U), /**< \brief Push-pull, Alternate output function 15. */
    IfxPort_Mode_outputOpenDrainGeneral = ((0U << 4U) | (1U << 1U) | 1U),  /**< \brief Open-drain, General-purpose output. */
    IfxPort_Mode_outputOpenDrainAlt1    = ((1U << 4U) | (1U << 1U) | 1U),  /**< \brief Open-drain, Alternate output function 1. */
    IfxPort_Mode_outputOpenDrainAlt2    = ((2U << 4U) | (1U << 1U) | 1U),  /**< \brief Open-drain, Alternate output function 2. */
    IfxPort_Mode_outputOpenDrainAlt3    = ((3U << 4U) | (1U << 1U) | 1U),  /**< \brief Open-drain, Alternate output function 3. */
    IfxPort_Mode_outputOpenDrainAlt4    = ((4U << 4U) | (1U << 1U) | 1U),  /**< \brief Open-drain, Alternate output function 4. */
    IfxPort_Mode_outputOpenDrainAlt5    = ((5U << 4U) | (1U << 1U) | 1U),  /**< \brief Open-drain, Alternate output function 5. */
    IfxPort_Mode_outputOpenDrainAlt6    = ((6U << 4U) | (1U << 1U) | 1U),  /**< \brief Open-drain, Alternate output function 6. */
    IfxPort_Mode_outputOpenDrainAlt7    = ((7U << 4U) | (1U << 1U) | 1U),  /**< \brief Open-drain, Alternate output function 7. */
    IfxPort_Mode_outputOpenDrainAlt8    = ((8U << 4U) | (1U << 1U) | 1U),  /**< \brief Open-drain, Alternate output function 8. */
    IfxPort_Mode_outputOpenDrainAlt9    = ((9U << 4U) | (1U << 1U) | 1U),  /**< \brief Open-drain, Alternate output function 9. */
    IfxPort_Mode_outputOpenDrainAlt10   = ((10U << 4U) | (1U << 1U) | 1U), /**< \brief Open-drain, Alternate output function 10. */
    IfxPort_Mode_outputOpenDrainAlt11   = ((11U << 4U) | (1U << 1U) | 1U), /**< \brief Open-drain, Alternate output function 11. */
    IfxPort_Mode_outputOpenDrainAlt12   = ((12U << 4U) | (1U << 1U) | 1U), /**< \brief Open-drain, Alternate output function 12. */
    IfxPort_Mode_outputOpenDrainAlt13   = ((13U << 4U) | (1U << 1U) | 1U), /**< \brief Open-drain, Alternate output function 13. */
    IfxPort_Mode_outputOpenDrainAlt14   = ((14U << 4U) | (1U << 1U) | 1U), /**< \brief Open-drain, Alternate output function 14. */
    IfxPort_Mode_outputOpenDrainAlt15   = ((15U << 4U) | (1U << 1U) | 1U)  /**< \brief Open-drain, Alternate output function 15. */
} IfxPort_Mode;

/** \brief Pin output alternate index
 */
typedef enum
{
    IfxPort_OutputIdx_general = ((0U << 4U) | 1U),
    IfxPort_OutputIdx_alt1    = ((1U << 4U) | 1U),
    IfxPort_OutputIdx_alt2    = ((2U << 4U) | 1U),
    IfxPort_OutputIdx_alt3    = ((3U << 4U) | 1U),
    IfxPort_OutputIdx_alt4    = ((4U << 4U) | 1U),
    IfxPort_OutputIdx_alt5    = ((5U << 4U) | 1U),
    IfxPort_OutputIdx_alt6    = ((6U << 4U) | 1U),
    IfxPort_OutputIdx_alt7    = ((7U << 4U) | 1U),
    IfxPort_OutputIdx_alt8    = ((8U << 4U) | 1U),
    IfxPort_OutputIdx_alt9    = ((9U << 4U) | 1U),
    IfxPort_OutputIdx_alt10   = ((10U << 4U) | 1U),
    IfxPort_OutputIdx_alt11   = ((11U << 4U) | 1U),
    IfxPort_OutputIdx_alt12   = ((12U << 4U) | 1U),
    IfxPort_OutputIdx_alt13   = ((13U << 4U) | 1U),
    IfxPort_OutputIdx_alt14   = ((14U << 4U) | 1U),
    IfxPort_OutputIdx_alt15   = ((15U << 4U) | 1U)
} IfxPort_OutputIdx;

/** \brief Pin output mode definition
 */
typedef enum
{
    IfxPort_OutputMode_pushPull  = ((0U << 1U) | 1U),
    IfxPort_OutputMode_openDrain = ((1U << 1U) | 1U)
} IfxPort_OutputMode;

/** \brief MODULE_PORTx.LPCRx.B.PS1.Selects between 5v and 3.3v on Vext supply for the LVDSM pair
 */
typedef enum
{
    IfxPort_PadSupply_3v = 0,  /**< \brief select,3.3v */
    IfxPort_PadSupply_5v = 1   /**< \brief select,5V */
} IfxPort_PadSupply;

/** \brief enable analog/digital mode for port pin, as Defined in MODULE_PORTx.PDISC
 */
typedef enum
{
    IfxPort_PinFunctionMode_digital = 0,  /**< \brief Pad Pn.x is enabled and can be selected for digital function */
    IfxPort_PinFunctionMode_analog  = 1   /**< \brief Pad Pn.x is enabled and can be selected for analog function */
} IfxPort_PinFunctionMode;

/** \brief Ifx_P output modification modes definition.
 *
 * \see Ifx_P.OMR, IfxPort_setPinState()
 */
typedef enum
{
    IfxPort_State_notChanged = (0 << 16) | (0 << 0),  /**< \brief Ifx_P pin is left unchanged. */
    IfxPort_State_high       = (0 << 16) | (1U << 0), /**< \brief Ifx_P pin is set to high. */
    IfxPort_State_low        = (1U << 16) | (0 << 0), /**< \brief Ifx_P pin is set to low. */
    IfxPort_State_toggled    = (1U << 16) | (1U << 0) /**< \brief Ifx_P pin is toggled. */
} IfxPort_State;

/** \} */

/** \brief Emergency status Push-Pull level
 */
typedef enum
{
    IfxPort_EsrLevel_0 = 0,      /**< \brief ESR Level0  */
    IfxPort_EsrLevel_1           /**< \brief ESR Level1  */
} IfxPort_EsrLevel;

/** \brief Emergency status Pad configuration
 */
typedef enum
{
    IfxPort_EsrPadCfg_PP  = 0,  /**< \brief PAD in Push-PULL */
    IfxPort_EsrPadCfg_TPU = 1,  /**< \brief Tristate, weak pull-up */
    IfxPort_EsrPadCfg_TPD = 2   /**< \brief Tristate, weak pull-down */
} IfxPort_EsrPadCfg;

/** \brief Enable/DIsable LVDS direction TX or RX
 */
typedef enum
{
    IfxPort_LvdsDirection_rx = 0,  /**< \brief LVDS direction RX */
    IfxPort_LvdsDirection_tx = 1   /**< \brief LVDS direction TX */
} IfxPort_LvdsDirection;

/** \brief Enable/DIsable LVDS Path.declared in MODULE_PORTx.LPCRx.TX_EN and MODULE_PORTx.LPCRx.RX_EN
 */
typedef enum
{
    IfxPort_LvdsPath_enable  = 0, /**< \brief LVDS enabled */
    IfxPort_LvdsPath_disable = 1  /**< \brief LVDS disabled */
} IfxPort_LvdsPath;

/** \brief Specifies whether LVDS pull down resistor must be enabled/disabled as declared in Register MODULE_PORT.LPCRx.PWDPD
 */
typedef enum
{
    IfxPort_LvdsPullDown_disable = 0,  /**< \brief Disable Pull Down resistor */
    IfxPort_LvdsPullDown_enable  = 1   /**< \brief Enable Pull Down resistor */
} IfxPort_LvdsPullDown;

/** \brief Specifies LVDS-Termination mode as declare in Register MODULE_PORT.LPCRx.TERM
 */
typedef enum
{
    IfxPort_LvdsTerminationMode_external = 0,  /**< \brief Termination Mode External */
    IfxPort_LvdsTerminationMode_internal = 1   /**< \brief Termination Mode Internal */
} IfxPort_LvdsTerminationMode;

/** \brief Pad driver mode definition (strength and slew rate).
 * Note: The enum is as per the DS
 *
 * \see Ifx_P.PADCFG.DRVCFG, IfxPort_setPinPadDriver()
 */
typedef enum
{
    IfxPort_PadDriver_cmosAutomotiveSpeed1 = 0,  /**< \brief Speed grade 1. */
    IfxPort_PadDriver_cmosAutomotiveSpeed2 = 1,  /**< \brief Speed grade 2. */
    IfxPort_PadDriver_cmosAutomotiveSpeed3 = 2,  /**< \brief Speed grade 3. */
    IfxPort_PadDriver_ttlSpeed1            = 16, /**< \brief Speed grade 1. */
    IfxPort_PadDriver_ttlSpeed2            = 17, /**< \brief Speed grade 2. */
    IfxPort_PadDriver_ttlSpeed3            = 18, /**< \brief Speed grade 3. */
    IfxPort_PadDriver_ttl3v3Speed1         = 24, /**< \brief ttl3v3Speed1. */
    IfxPort_PadDriver_ttl3v3Speed2         = 25, /**< \brief ttl3v3Speed2. */
    IfxPort_PadDriver_ttl3v3Speed3         = 26  /**< \brief ttl3v3Speed3. */
} IfxPort_PadDriver;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief Configuration to map a specific pin to a APU group
 */
typedef struct
{
    uint8 pinIndex;       /**< \brief Pin index number */
    uint8 grpNum;         /**< \brief The APU group number to which the pin is mapped to. */
} IfxPort_Pin_ApuConfig;

/** \addtogroup IfxLld_Port_Std_DataStructures
 * \{ */
/** \brief To Configure LVDS mode
 */
typedef struct
{
    IfxPort_LvdsMode     lvdsMode;                   /**< \brief specifies LVDS-M or LVDS-H mode */
    IfxPort_ControlledBy enablePortControlled;       /**< \brief specifies whether LVDS is controlled by PORT or HSCT */
    IfxPort_PadSupply    padSupply;                  /**< \brief specify supply voltage */
    IfxPort_LvdsTerm     lvdsTerm;                   /**< \brief specifies external or internal LVDS reciever Termination Mode */
} IfxPort_LvdsConfig;

/** \brief Defines a pin
 */
typedef struct
{
    Ifx_P *port;
    uint8  pinIndex;
} IfxPort_Pin;

/** \brief To configure pins
 */
typedef struct
{
    Ifx_P            *port;
    uint8             pinIndex;
    IfxPort_OutputIdx mode;
    IfxPort_PadDriver padDriver;
} IfxPort_Pin_Config;

/** \} */

/** \brief APU Configuration
 */
typedef struct
{
    IfxApApu_ApuConfig apuConfig;       /**< \brief APU Configurations */
    uint8              grpNum;          /**< \brief The APU group number to which the pin is mapped to. */
} IfxPort_ApuConfig;

/** \brief APU configurations for All the APU groups
 * And mapping from a pin to a specific APU group
 */
typedef struct
{
    IfxApApu_ApuConfig    apuConfig[IFXPORT_NUM_APU];        /**< \brief APU Configurations for all the APUs */
    IfxPort_Pin_ApuConfig pinConfig[IFXPORT_NUM_PINS];       /**< \brief Configuration to map a specific pin to a APU group */
} IfxPort_ApuGroupConfig;

/** \brief PROT Configuration
 */
typedef struct
{
    IfxApProt_ProtConfig protseConfig;       /**< \brief PROT SE Configurations */
} IfxPort_ProtConfig;

/** \addtogroup IfxLld_Port_Std_SinglePin
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Return the port state.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin for which the state should be returned.
 * \return Returns TRUE the pin is high; FALSE the pin is low
 *
 * Coding example:
 * \code
 *    if( IfxPort_getPinState(&MODULE_P33, 0) ) {
 *      // ...
 *    }
 * \endcode
 *
 */
IFX_INLINE boolean IfxPort_getPinState(Ifx_P *port, uint8 pinIndex);

/** \brief Set analog/digital mode for pin
 * \param port Pointer to Port register space
 * \param pinIndex specifies the pin index
 * \param mode set analog/digital mode
 * \return None
 */
IFX_INLINE void IfxPort_setPinFunctionMode(Ifx_P *port, uint8 pinIndex, IfxPort_PinFunctionMode mode);

/** \brief Set the port output.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin to be set.
 * \return None
 *
 * Coding example:
 * \code
 * IfxPort_setPinHigh(&MODULE_P33, 0);
 * \endcode
 *
 * \see IfxPort_setPinState(), IfxPort_setPinLow(), IfxPort_togglePin()
 *
 */
IFX_INLINE void IfxPort_setPinHigh(Ifx_P *port, uint8 pinIndex);

/** \brief Reset the port output.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin to be reset.
 * \return None
 *
 * Coding example:
 * \code
 * IfxPort_setPinLow(&MODULE_P33, 0);
 * \endcode
 *
 * \see IfxPort_setPinState(), IfxPort_setPinHigh(), IfxPort_togglePin()
 *
 */
IFX_INLINE void IfxPort_setPinLow(Ifx_P *port, uint8 pinIndex);

/** \brief Configure the port input / output mode.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin to be configured.
 * \param mode Specifies the port pin mode.
 * \return None
 *
 * Coding example:
 * \code
 *     IfxPort_setPinModeInput(&MODULE_P33, 0, IfxPort_InputMode_pullUp);
 * \endcode
 *
 */
IFX_INLINE void IfxPort_setPinModeInput(Ifx_P *port, uint8 pinIndex, IfxPort_InputMode mode);

/** \brief Configure the port input / output mode.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin to be configured.
 * \param mode Specifies the port pin mode.
 * \param index Specifies the alternate (or general purpose) output channel.
 * \return None
 *
 * Coding example:
 * \code
 *     IfxPort_setPinModeOutput(&MODULE_P33, 0, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
 * \endcode
 *
 */
IFX_INLINE void IfxPort_setPinModeOutput(Ifx_P *port, uint8 pinIndex, IfxPort_OutputMode mode, IfxPort_OutputIdx index);

/** \brief Set / Resets / Toggle the port output.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin to modify.
 * \param action Specifies the action: set, reset, toggle.
 * \return None
 *
 * Coding example:
 * \code
 * IfxPort_setPinState(&MODULE_P33, 0, IfxPort_State_toggled);
 * IfxPort_setPinState(&MODULE_P33, 0, IfxPort_State_toggled);
 * IfxPort_setPinState(&MODULE_P33, 0, IfxPort_State_toggled);
 * \endcode
 *
 */
IFX_INLINE void IfxPort_setPinState(Ifx_P *port, uint8 pinIndex, IfxPort_State action);

/** \brief Toggle the port output.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin to be toggled.
 * \return None
 *
 * Coding example:
 * \code
 * IfxPort_togglePin(&MODULE_P33, 0);
 * \endcode
 *
 * \see IfxPort_setPinState(), IfxPort_setPinLow(), IfxPort_setPinHigh()
 *
 */
IFX_INLINE void IfxPort_togglePin(Ifx_P *port, uint8 pinIndex);

/** \brief Select the reduced frequency mode LVDS-M/LVDS-H
 * \param port pointer to Port Register space
 * \param pinIndex specifies pin index
 * \param lvdsMode specifies the LVDS mode
 * \return None
 */
IFX_INLINE void IfxPort_setPinLVDS(Ifx_P *port, uint8 pinIndex, IfxPort_LvdsMode lvdsMode);

/** \brief Returns the configured reduced frequency mode LVDS-M/LVDS-H
 * \param port pointer to Port Register space
 * \param pinIndex specifies pin index
 * \return specifies the lvds mode
 */
IFX_INLINE IfxPort_LvdsMode IfxPort_getPinLVDS(Ifx_P *port, uint8 pinIndex);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Disable the emergency stop function.
 * This function disables the emergency stop function. A check is done on port functionality.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin for which the emergency stop function should be disabled.
 * \return Returns TRUE if the emergency stop function has been disabled; FALSE if the emergency stop function could not be disabled
 *
 * Coding example:
 * /code
 *     if( !IfxPort_disableEmergencyStop(&MODULE_P33, 0) )
 *     {
 *         // failed to disable emergency stop for P33.0
 *     }
 * /endcode
 *
 * \see IfxPort_disableEmergencyStop(), IfxPort_resetESR()
 *
 */
IFX_EXTERN boolean IfxPort_disableEmergencyStop(Ifx_P *port, uint8 pinIndex);

/** \brief Enable the emergency stop function.
 * This function enables the emergency stop function. A check is done on port functionality.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin for which the emergency stop function should be enabled.
 * \return Returns TRUE if the emergency stop function has been enabled; FALSE if the emergency stop function could not be enabled
 *
 * Coding example:
 * \code
 *     if( !IfxPort_enableEmergencyStop(&MODULE_P33, 0) ) {
 *       // failed to enable emergency stop for P33.0
 *     }
 * \endcode
 *
 * \see IfxPort_disableEmergencyStop(), IfxPort_setESR()
 *
 */
IFX_EXTERN boolean IfxPort_enableEmergencyStop(Ifx_P *port, uint8 pinIndex);

/** \brief Disable the emergency stop function.
 * This function disables the emergency stop function. No check is done on port functionality.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin for which the emergency stop function should be disabled.
 * \return None
 *
 * \see IfxPort_disableEmergencyStop()
 *
 */
IFX_EXTERN void IfxPort_resetESR(Ifx_P *port, uint8 pinIndex);

/** \brief Enable the emergency stop function.
 * This function enables the emergency stop function. No check is done on port functionality.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin for which the emergency stop function should be enabled.
 * \return None
 *
 * \see IfxPort_enableEmergencyStop()
 *
 */
IFX_EXTERN void IfxPort_setESR(Ifx_P *port, uint8 pinIndex);

/** \brief Configure the port input / output mode.
 * Also Configures the P40/P41 Port for digital functionality
 * which bydefault support analog functionality.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin to be configured.
 * \param mode Specifies the port pin mode.
 * \return None
 *
 * Coding example:
 * \code
 *     IfxPort_setPinMode(&MODULE_P33, 0, IfxPort_Mode_outputPushPullGeneral);
 * \endcode
 *
 */
IFX_EXTERN void IfxPort_setPinMode(Ifx_P *port, uint8 pinIndex, IfxPort_Mode mode);

/** \brief Configure the pad driver mode.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin for which the mode will be set.
 * \param padDriver Specifies the driver mode.
 * \return None
 *
 * Coding example:
 * \code
 * // enable strong 3.3V driver
 * IfxPort_setPinPadDriver(&MODULE_P33, 0, IfxPort_PadDriver_cmosAutomotiveSpeed1);
 * \endcode
 *
 */
IFX_EXTERN void IfxPort_setPinPadDriver(Ifx_P *port, uint8 pinIndex, IfxPort_PadDriver padDriver);

/** \brief Enable the Pin Controller Selection.
 * \param port Pointer to the base of specified port's SFRs
 * \param pinIndex Specifies the pin for which the mode has to be set.
 * \return None
 */
IFX_EXTERN void IfxPort_setPinControllerSelection(Ifx_P *port, uint8 pinIndex);

/**
 * \param port Pointer to the base of specified port's SFRs
 * \param pinIndex Specifies the pin for which the mode has to be set.
 * \return None
 */
IFX_EXTERN void IfxPort_resetPinControllerSelection(Ifx_P *port, uint8 pinIndex);

/**
 * \param port Pointer to the base of specified port's SFRs
 * \param pinIndex Specifies the pin for which the mode has to be set.
 * \param mode Selects the controller for the port pin(Tricore,EVADC,GETH,SCR,HRPWM etc)
 * 0-> normal function
 * 1-> Alternate functionality(SCR pin,EVADC PDD,GETH RGMII/MII,HRPWM etc)
 * Note:It is the Users responsibility to pass correct port, pin and mode inputs
 * \return None
 */
IFX_EXTERN void IfxPort_modifyPinControllerSelection(Ifx_P *port, uint8 pinIndex, boolean mode);

/** \} */

/** \addtogroup IfxLld_Port_Std_PortGroup
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Return the port group state
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex start at the given pin
 * \param mask selects the pins which should be read (starting from pinIndex)
 * \return Returns the selected pin values
 *
 * Coding example:
 * \code
 * // read the current value of P33[7:0]
 * uint16 value = IfxPort_getGroupState(&MODULE_P33, 0, 0xff);
 * \endcode
 *
 */
IFX_INLINE uint32 IfxPort_getGroupState(Ifx_P *port, uint8 pinIndex, uint16 mask);

/** \brief Set the port group state.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex start at the given pin
 * \param mask selects the pins which should be modified (starting from pinIndex)
 * \param data specifies the value which should be set
 * \return None
 *
 * Coding example:
 * \code
 * // configure P33.[7:0] as GPIO outputs
 * IfxPort_setGroupModeOutput(&MODULE_P33, 0, 0xff, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
 *
 * // set initial value
 * IfxPort_setGroupState(&MODULE_P33, 0, 0xff, 0x42);
 * \endcode
 *
 */
IFX_INLINE void IfxPort_setGroupState(Ifx_P *port, uint8 pinIndex, uint16 mask, uint16 data);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the module address of the selected Port module
 * \param port Pointer to PORT module registers
 * \return PORT module register address
 */
IFX_EXTERN Ifx_P *IfxPort_getAddress(IfxPort_Index port);

/** \brief Return port index within IfxModule_IndexMap (defined in IfxPort_cfg.c)
 * \param port Pointer to the port for which the index number in IfxModule_IndexMap should be retrieved.
 * \return port index of IfxModule_IndexMap. return -1 in case of unknown port index.
 */
IFX_EXTERN IfxPort_Index IfxPort_getIndex(Ifx_P *port);

/** \brief Set pin modes to input at the pin location specified by '1' by the mask
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex start at the given pin
 * \param mask selects the pins which should be modified (starting from pinIndex)
 * \param mode Specifies the port pin mode.
 * \return None
 *
 * Coding example:
 * \code
 * // configure P33.[7:0] as GPIO inputs with Pull-Down enabled
 * IfxPort_setGroupModeInput(&MODULE_P33, 0, 0xff, IfxPort_InputMode_pullDown);
 *  \endcode
 *
 */
IFX_EXTERN void IfxPort_setGroupModeInput(Ifx_P *port, uint8 pinIndex, uint16 mask, IfxPort_InputMode mode);

/** \brief Set pin modes to output at the pin location specified by '1' by the mask starting at pinIndex
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex start at the given pin
 * \param mask selects the pins which should be modified (starting from pinIndex)
 * \param mode Specifies the port pin mode.
 * \param index Specifies the alternate (or general purpose) output channel.
 * \return None
 *
 * Coding example:
 * \code
 * // configure P33.[7:0] as GPIO outputs
 * IfxPort_setGroupModeOutput(&MODULE_P33, 0, 0xff, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
 * \endcode
 *
 */
IFX_EXTERN void IfxPort_setGroupModeOutput(Ifx_P *port, uint8 pinIndex, uint16 mask, IfxPort_OutputMode mode, IfxPort_OutputIdx index);

/** \brief Set pad driver strength at the pin location specified by '1' by the mask
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex start at the given pin
 * \param mask selects the pins which should be modified (starting from pinIndex)
 * \param padDriver Specifies the pad driver strength.
 * \return None
 *
 * Coding example:
 * \code
 * // configure P33.[7:0] to use CMOS pad driver with speed 1
 * IfxPort_setGroupPadDriver(&MODULE_P33, 0, 0xff, IfxPort_PadDriver_cmosAutomotiveSpeed1);
 * \endcode
 *
 */
IFX_EXTERN void IfxPort_setGroupPadDriver(Ifx_P *port, uint8 pinIndex, uint16 mask, IfxPort_PadDriver padDriver);

/** \brief Configure lvds mode
 * \param port pointer to Port Register space
 * \param pinIndex specifies pin index
 * \param pinMode specifes the mode of pin
 * \param lvds config LVDS
 * \return None
 */
IFX_EXTERN void IfxPort_setPinModeLVDS(Ifx_P *port, uint8 pinIndex, IfxPort_Mode pinMode, IfxPort_LvdsConfig *lvds);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initialise the PROT Config to default values
 * \param config PROT SE Config pointer
 * \return None
 */
IFX_INLINE void IfxPort_initProtConfig(IfxPort_ProtConfig *config);

/** \brief Initialize the PROT
 * \param port PORT module pointer
 * \param config PRTO SE Config pointer
 * \return None
 */
IFX_INLINE void IfxPort_initProt(Ifx_P *port, IfxPort_ProtConfig *config);

/** \brief Configures the specfic pin slice to a APU group
 * \param port PORT module pointer
 * \param pinIndex pin Index
 * \param grpNum APU group to which the pin is to be assigned
 * \return None
 */
IFX_INLINE void IfxPort_setApuGroupSelection(Ifx_P *port, uint8 pinIndex, uint8 grpNum);

/** \brief API to Enable the wake up feature.
 * \param port PORT module pointer
 * \param pinIndex pin index
 * \param enable Enable/Disable the wake up
 * \return None
 */
IFX_INLINE void IfxPort_setPinWakeUpEnable(Ifx_P *port, uint8 pinIndex, boolean enable);

/** \brief API to clear the wake up status
 * \param port Port module pointer
 * \param pinIndex pin index
 * \return None
 */
IFX_INLINE void IfxPort_clearPinWakeUpStatus(Ifx_P *port, uint8 pinIndex);

/** \brief API to enable the wake up status
 * \param port Port module pointer
 * \param pinIndex pin index
 * \param enable Enable/Disable the wake up status
 * \return None
 */
IFX_INLINE void IfxPort_setPinWakeUpStatusEnable(Ifx_P *port, uint8 pinIndex, boolean enable);

/** \brief API to return the wake up status of the port pin
 * \param port Port module pointer
 * \param pinIndex pin index
 * \return Return status enable/disable
 */
IFX_INLINE boolean IfxPort_getPinWakeUpStatus(Ifx_P *port, uint8 pinIndex);

/** \brief API to return the wake up status register
 * \param port Port module pointer
 * \return Returns the status value
 */
IFX_INLINE uint32 IfxPort_getRawPinWakeUpStatus(Ifx_P *port);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initialise the APU config to default values
 * \param config Apu Config pointer
 * \return None
 */
IFX_EXTERN void IfxPort_initApuConfig(IfxPort_ApuConfig *config);

/** \brief Initialise the APU
 * \param port PORT module pointer
 * \param config APU Config pointer
 * \return None
 */
IFX_EXTERN void IfxPort_initApu(Ifx_P *port, IfxPort_ApuConfig *config);

/** \brief Configures the Pins to the APU groups
 * \param port PORT module pointer
 * \param config APU group configuration pointer
 * \return None
 */
IFX_EXTERN void IfxPort_initApuGroups(Ifx_P *port, IfxPort_ApuGroupConfig *config);

/** \brief Configure the ESR PAD and push pull configuration
 * \param port PORT MODULE Pointer
 * \param pinIndex Pin Index
 * \param esrLevel ESR level
 * \param esrPadCfg ESR Pad configuration
 * \return None
 */
IFX_EXTERN void IfxPort_configureESR(Ifx_P *port, uint8 pinIndex, IfxPort_EsrLevel esrLevel, IfxPort_EsrPadCfg esrPadCfg);

/** \brief Configures access to all masters to all the Ports in the device
 * \param apConfig config pointer to configuration structure.
 * Note : By default the access protection group selected is 0 (PADCFG.ACCEN.B.GRP= 0) for all ports
 * \return None
 */
IFX_EXTERN void IfxPort_configureAccessToPorts(IfxApApu_ApuConfig *apConfig);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE uint32 IfxPort_getGroupState(Ifx_P *port, uint8 pinIndex, uint16 mask)
{
    return (uint32)((port->IN.U) >> (pinIndex)) & mask;
}


IFX_INLINE boolean IfxPort_getPinState(Ifx_P *port, uint8 pinIndex)
{
#if defined(IFX_ILLD_TC_USAGE)
    return __getbit(&port->IN.U, pinIndex);
#else
    return (boolean)(port->IN.U >> pinIndex) & 1U;
#endif /* defined(IFX_ILLD_TC_USAGE) */
}


IFX_INLINE void IfxPort_setGroupState(Ifx_P *port, uint8 pinIndex, uint16 mask, uint16 data)
{
    port->OUT.U = (port->OUT.U & ~((uint32)(mask)) << pinIndex) | (data << pinIndex);
}


IFX_INLINE void IfxPort_setPinFunctionMode(Ifx_P *port, uint8 pinIndex, IfxPort_PinFunctionMode mode)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_transitionState((Ifx_PROT_PROT *)&port->PROTSE, IfxApProt_State_config);
#endif
    port->PDISC.U = ((port->PDISC.U & ~(1 << pinIndex)) | (mode << pinIndex));

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_transitionState((Ifx_PROT_PROT *)&port->PROTSE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxPort_setPinHigh(Ifx_P *port, uint8 pinIndex)
{
    IfxPort_setPinState(port, pinIndex, IfxPort_State_high);
}


IFX_INLINE void IfxPort_setPinLow(Ifx_P *port, uint8 pinIndex)
{
    IfxPort_setPinState(port, pinIndex, IfxPort_State_low);
}


IFX_INLINE void IfxPort_setPinModeInput(Ifx_P *port, uint8 pinIndex, IfxPort_InputMode mode)
{
    IfxPort_setPinMode(port, pinIndex, (IfxPort_Mode)mode);
}


IFX_INLINE void IfxPort_setPinModeOutput(Ifx_P *port, uint8 pinIndex, IfxPort_OutputMode mode, IfxPort_OutputIdx index)
{
    IfxPort_setPinMode(port, pinIndex, (IfxPort_Mode)(index | mode));
}


IFX_INLINE void IfxPort_setPinState(Ifx_P *port, uint8 pinIndex, IfxPort_State action)
{
    port->OMR.U = action << pinIndex;
}


IFX_INLINE void IfxPort_togglePin(Ifx_P *port, uint8 pinIndex)
{
    IfxPort_setPinState(port, pinIndex, IfxPort_State_toggled);
}


IFX_INLINE void IfxPort_setPinLVDS(Ifx_P *port, uint8 pinIndex, IfxPort_LvdsMode lvdsMode)
{
    uint32               lpcrOffset = (pinIndex / 2);

    volatile Ifx_P_LPCR *lpcr       = &(port->LPCR[0]);

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_transitionState((Ifx_PROT_PROT *)&port->PROTSE, IfxApProt_State_config);
#endif
    lpcr[lpcrOffset].LPCR.B.LVDSM = lvdsMode;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_transitionState((Ifx_PROT_PROT *)&port->PROTSE, IfxApProt_State_run);
#endif
}


IFX_INLINE IfxPort_LvdsMode IfxPort_getPinLVDS(Ifx_P *port, uint8 pinIndex)
{
    uint32               lpcrOffset = (pinIndex / 2);

    volatile Ifx_P_LPCR *lpcr       = &(port->LPCR[0]);

    return (IfxPort_LvdsMode)(lpcr[lpcrOffset].LPCR.B.LVDSM);
}


IFX_INLINE void IfxPort_initProtConfig(IfxPort_ProtConfig *config)
{
    IfxApProt_initConfig(&config->protseConfig);
}


IFX_INLINE void IfxPort_initProt(Ifx_P *port, IfxPort_ProtConfig *config)
{
    IfxApProt_init((Ifx_PROT_PROT *)&port->PROTSE, &config->protseConfig);
}


IFX_INLINE void IfxPort_setApuGroupSelection(Ifx_P *port, uint8 pinIndex, uint8 grpNum)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_transitionState((Ifx_PROT_PROT *)&port->PROTSE, IfxApProt_State_config);
#endif
    port->PADCFG[pinIndex].ACCEN.B.GRP = grpNum;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_transitionState((Ifx_PROT_PROT *)&port->PROTSE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxPort_setPinWakeUpEnable(Ifx_P *port, uint8 pinIndex, boolean enable)
{
    port->WKEN.U = (enable << pinIndex);
}


IFX_INLINE void IfxPort_clearPinWakeUpStatus(Ifx_P *port, uint8 pinIndex)
{
    port->WKENSTSCLR.U = (1U << pinIndex);
}


IFX_INLINE void IfxPort_setPinWakeUpStatusEnable(Ifx_P *port, uint8 pinIndex, boolean enable)
{
    port->WKENSTS.U = (enable << pinIndex);
}


IFX_INLINE boolean IfxPort_getPinWakeUpStatus(Ifx_P *port, uint8 pinIndex)
{
#if defined(IFX_ILLD_TC_USAGE)
    return __getbit(&port->WKSTS.U, pinIndex);
#else
    return (boolean)(port->WKSTS.U >> pinIndex) & 1U;
#endif /* defined(IFX_ILLD_TC_USAGE) */
}


IFX_INLINE uint32 IfxPort_getRawPinWakeUpStatus(Ifx_P *port)
{
    return (uint32)(port->WKSTS.U);
}


#endif /* IFXPORT_H */
