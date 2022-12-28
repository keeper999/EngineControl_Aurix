/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Port_Cfg.h                                                    **
**                                                                            **
**  $CC VERSION : \main\24 $                                                 **
**                                                                            **
**  DATE, TIME: 2014-09-29, 11:35:24                                      **
**                                                                            **
**  GENERATOR : Build b131017-0205                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Port configuration generated from 
                   ECU configuration file (Port.bmd )                         **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H


#define PORT_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_AR_RELEASE_REVISION_VERSION  (3U)

#define PORT_SW_MAJOR_VERSION  (3U)
#define PORT_SW_MINOR_VERSION  (0U)
#define PORT_SW_PATCH_VERSION  (1U)

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*
                     Container : PortGeneralConfiguration
*/


/*
Configuration: PORT_DEV_ERROR_DETECT
- if Selected, DET is Enabled 
- if Deselected, DET is Disabled 
*/
#define PORT_DEV_ERROR_DETECT       (STD_ON)

/*
Configuration: PORT_VERSION_INFO_API 
- if Selected,  Function Port_GetVersionInfo is available  
- if Deselected, Function Port_GetVersionInfo is not available 
*/
#define PORT_VERSION_INFO_API       (STD_OFF)

/*
Configuration: PORT_SET_PIN_MODE_API 
- if Selected,  Function Port_SetPinMode is available  
- if Deselected, Function Port_SetPinMode is not available 
*/
#define PORT_SET_PIN_MODE_API       (STD_ON)

/*
Configuration: PORT_SET_PIN_DIRECTION_API
- if Selected,  Function Port_SetPinDirection is available  
- if Deselected, Function Port_SetPinDirection is not available 
*/
#define PORT_SET_PIN_DIRECTION_API  (STD_ON)

/* Port Fixed Address usage */
#define PORT_PB_FIXEDADDR           (STD_OFF)



/*
Configuration: PORT_SAFETY_ENABLE
- if Selected,  Safety feature is enabled
- if Deselected, Safety features is disabled 
*/
#define PORT_SAFETY_ENABLE  (STD_OFF)


/*
Configuration: PORT_INIT_CHECK_API
- if Selected,  Safety feature is enabled
- if Deselected, Safety features is disabled 
*/
#define PORT_INIT_CHECK_API  (STD_OFF)

                                              
/* Definition to specify the ports available on the microcontroller
   Bit value = 0 implies the port is not available
   Bit value = 1 implies the port is available
   Bit 0 is for Port 0, Bit 1 is for Port 1, ... , Bit 31 is for Port 31 
*/
#define PORTS_AVAILABLE_00_31       (0x00f0fc07U)

/* Definition to specify the ports available on the microcontroller
   Bit value = 0 implies the port is not available
   Bit value = 1 implies the port is available
   Bit 0 is for Port 32, Bit 1 is for Port 33, ... , Bit 8 is for Port 40 
*/
#define PORTS_AVAILABLE_32_40       (0x00000107U)

/* Definition to specify the ports that are read only ports on the
   microcontroller
   Bit value = 0 implies the port readable/writable
   Bit value = 1 implies the port is read only port
   Bit 0 is for Port 0, Bit 1 is for Port 1, ... , Bit 31 is for Port 31 
*/
#define PORTS_READONLY_00_31        (0x00000000U)

/* Definition to specify the ports that are read only ports on the
   microcontroller
   Bit value = 0 implies the port readable/writable
   Bit value = 1 implies the port is read only port
   Bit 0 is for Port 32, Bit 1 is for Port 33, ... , Bit 8 is for Port 40 
*/
#define PORTS_READONLY_32_40        (0x00000100U)

/* Maximum Port Number(Hex) */
#define PORT_MAX_NUMBER             (40U)

/* Maximum PortPinID */
#define PORT_MAX_PIN_ID             (0x28fU)

/* Max Port Number available */
#define PORT_MAX_NUM                (17U)

/* Maximum number of LPCR register available */
#define PORT_MAX_LPCR_REG           (3U)

/* Definition to specify the ports that are LVDS ports on the
   microcontroller
   Bit value = 0 implies the port supports LVDS
   Bit value = 1 implies the port does not support LVDS
   Bit 0 is for Port 0, Bit 1 is for Port 1, ... , Bit 31 is for Port 31
*/
#define PORTS_LVDS_00_31        (0x00602000U)

/* Definition to specify the ports that are LVDS ports on the
   microcontroller
   Bit value = 0 implies the port supports LVDS
   Bit value = 1 implies the port does not support LVDS
   Bit 0 is for Port 32, Bit 1 is for Port 33, ... , Bit 8 is for Port 40 
*/
#define PORTS_LVDS_32_40        (0x00000000U)

/* Definition to specify the ports that support PCSR on the
   microcontroller
   Bit value = 0 implies the port supports PCSR
   Bit value = 1 implies the port does not support PCSR
   Bit 0 is for Port 0, Bit 1 is for Port 1, ... , Bit 31 is for Port 31
*/
#define PORTS_PCSR_00_31        (0x00000801U)

/* Definition to specify the ports that PCSR on the
   microcontroller
   Bit value = 0 implies the port supports PCSR
   Bit value = 1 implies the port does not support PCSR
   Bit 0 is for Port 32, Bit 1 is for Port 33, ... , Bit 8 is for Port 40 
*/
#define PORTS_PCSR_32_40        (0x00000100U)

/* Definitions to specify the pins available in the port 
   Bit value = 0 implies the pin is not available
   Bit value = 1 implies the pin is available
   Bit 0 is for Pin 0, Bit 1 is for Pin 1, ... , Bit 15 is for Pin 15
*/
#define PORT_AVAILABLE_PINS_PORT0  (0x1fffU)
#define PORT_AVAILABLE_PINS_PORT1  (0x00f8U)
#define PORT_AVAILABLE_PINS_PORT2  (0x0fffU)
#define PORT_AVAILABLE_PINS_PORT3  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT4  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT5  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT6  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT7  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT8  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT9  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT10  (0x01ffU)
#define PORT_AVAILABLE_PINS_PORT11  (0xffffU)
#define PORT_AVAILABLE_PINS_PORT12  (0x0003U)
#define PORT_AVAILABLE_PINS_PORT13  (0x000fU)
#define PORT_AVAILABLE_PINS_PORT14  (0x07ffU)
#define PORT_AVAILABLE_PINS_PORT15  (0x01ffU)
#define PORT_AVAILABLE_PINS_PORT16  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT17  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT18  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT19  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT20  (0x7fcfU)
#define PORT_AVAILABLE_PINS_PORT21  (0x00ffU)
#define PORT_AVAILABLE_PINS_PORT22  (0x0fffU)
#define PORT_AVAILABLE_PINS_PORT23  (0x00ffU)
#define PORT_AVAILABLE_PINS_PORT24  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT25  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT26  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT27  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT28  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT29  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT30  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT31  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT32  (0x00fdU)
#define PORT_AVAILABLE_PINS_PORT33  (0xffffU)
#define PORT_AVAILABLE_PINS_PORT34  (0x003eU)
#define PORT_AVAILABLE_PINS_PORT35  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT36  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT37  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT38  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT39  (0x0000U)
#define PORT_AVAILABLE_PINS_PORT40  (0x03ffU)

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* 
  User Defined Symbolic names of all port pins Port_ConfigSet0
*/

/*
                                   Port0                                      
*/

/* Symbolic Name: Port0 Pin0 */
/* To prevent double declaration */
#ifndef  PORT_0_PIN_0
#define PORT_0_PIN_0                          (Port_PinType)(0x000)
#endif

/* Symbolic Name: Port0 Pin1 */
/* To prevent double declaration */
#ifndef  PORT_0_PIN_1
#define PORT_0_PIN_1                          (Port_PinType)(0x001)
#endif

/* Symbolic Name: Port0 Pin2 */
/* To prevent double declaration */
#ifndef  PORT_0_PIN_2
#define PORT_0_PIN_2                          (Port_PinType)(0x002)
#endif

/* Symbolic Name: Port0 Pin3 */
/* To prevent double declaration */
#ifndef  PORT_0_PIN_3
#define PORT_0_PIN_3                          (Port_PinType)(0x003)
#endif

/* Symbolic Name: Port0 Pin4 */
/* To prevent double declaration */
#ifndef  PORT_0_PIN_4
#define PORT_0_PIN_4                          (Port_PinType)(0x004)
#endif

/* Symbolic Name: Port0 Pin5 */
/* To prevent double declaration */
#ifndef  PORT_0_PIN_5
#define PORT_0_PIN_5                          (Port_PinType)(0x005)
#endif

/* Symbolic Name: Port0 Pin6 */
/* To prevent double declaration */
#ifndef  PORT_0_PIN_6
#define PORT_0_PIN_6                          (Port_PinType)(0x006)
#endif

/* Symbolic Name: Port0 Pin7 */
/* To prevent double declaration */
#ifndef  PORT_0_PIN_7
#define PORT_0_PIN_7                          (Port_PinType)(0x007)
#endif

/* Symbolic Name: Port0 Pin8 */
/* To prevent double declaration */
#ifndef  PORT_0_PIN_8
#define PORT_0_PIN_8                          (Port_PinType)(0x008)
#endif

/* Symbolic Name: Port0 Pin9 */
/* To prevent double declaration */
#ifndef  PORT_0_PIN_9
#define PORT_0_PIN_9                          (Port_PinType)(0x009)
#endif

/* Symbolic Name: Port0 Pin10 */
/* To prevent double declaration */
#ifndef  PORT_0_PIN_10
#define PORT_0_PIN_10                          (Port_PinType)(0x00a)
#endif

/* Symbolic Name: Port0 Pin11 */
/* To prevent double declaration */
#ifndef  PORT_0_PIN_11
#define PORT_0_PIN_11                          (Port_PinType)(0x00b)
#endif

/* Symbolic Name: Port0 Pin12 */
/* To prevent double declaration */
#ifndef  PORT_0_PIN_12
#define PORT_0_PIN_12                          (Port_PinType)(0x00c)
#endif

/*
                                   Port1                                      
*/

/* Symbolic Name: Port1 Pin3 */
/* To prevent double declaration */
#ifndef  PORT_1_PIN_3
#define PORT_1_PIN_3                          (Port_PinType)(0x013)
#endif

/* Symbolic Name: Port1 Pin4 */
/* To prevent double declaration */
#ifndef  PORT_1_PIN_4
#define PORT_1_PIN_4                          (Port_PinType)(0x014)
#endif

/* Symbolic Name: Port1 Pin5 */
/* To prevent double declaration */
#ifndef  PORT_1_PIN_5
#define PORT_1_PIN_5                          (Port_PinType)(0x015)
#endif

/* Symbolic Name: Port1 Pin6 */
/* To prevent double declaration */
#ifndef  PORT_1_PIN_6
#define PORT_1_PIN_6                          (Port_PinType)(0x016)
#endif

/* Symbolic Name: Port1 Pin7 */
/* To prevent double declaration */
#ifndef  PORT_1_PIN_7
#define PORT_1_PIN_7                          (Port_PinType)(0x017)
#endif

/*
                                   Port2                                      
*/

/* Symbolic Name: Port2 Pin0 */
/* To prevent double declaration */
#ifndef  PORT_2_PIN_0
#define PORT_2_PIN_0                          (Port_PinType)(0x020)
#endif

/* Symbolic Name: Port2 Pin1 */
/* To prevent double declaration */
#ifndef  PORT_2_PIN_1
#define PORT_2_PIN_1                          (Port_PinType)(0x021)
#endif

/* Symbolic Name: Port2 Pin2 */
/* To prevent double declaration */
#ifndef  PORT_2_PIN_2
#define PORT_2_PIN_2                          (Port_PinType)(0x022)
#endif

/* Symbolic Name: Port2 Pin3 */
/* To prevent double declaration */
#ifndef  PORT_2_PIN_3
#define PORT_2_PIN_3                          (Port_PinType)(0x023)
#endif

/* Symbolic Name: Port2 Pin4 */
/* To prevent double declaration */
#ifndef  PORT_2_PIN_4
#define PORT_2_PIN_4                          (Port_PinType)(0x024)
#endif

/* Symbolic Name: Port2 Pin5 */
/* To prevent double declaration */
#ifndef  PORT_2_PIN_5
#define PORT_2_PIN_5                          (Port_PinType)(0x025)
#endif

/* Symbolic Name: Port2 Pin6 */
/* To prevent double declaration */
#ifndef  PORT_2_PIN_6
#define PORT_2_PIN_6                          (Port_PinType)(0x026)
#endif

/* Symbolic Name: Port2 Pin7 */
/* To prevent double declaration */
#ifndef  PORT_2_PIN_7
#define PORT_2_PIN_7                          (Port_PinType)(0x027)
#endif

/* Symbolic Name: Port2 Pin8 */
/* To prevent double declaration */
#ifndef  PORT_2_PIN_8
#define PORT_2_PIN_8                          (Port_PinType)(0x028)
#endif

/* Symbolic Name: Port2 Pin9 */
/* To prevent double declaration */
#ifndef  PORT_2_PIN_9
#define PORT_2_PIN_9                          (Port_PinType)(0x029)
#endif

/* Symbolic Name: Port2 Pin10 */
/* To prevent double declaration */
#ifndef  PORT_2_PIN_10
#define PORT_2_PIN_10                          (Port_PinType)(0x02a)
#endif

/* Symbolic Name: Port2 Pin11 */
/* To prevent double declaration */
#ifndef  PORT_2_PIN_11
#define PORT_2_PIN_11                          (Port_PinType)(0x02b)
#endif

/*
                                   Port10                                      
*/

/* Symbolic Name: Port10 Pin0 */
/* To prevent double declaration */
#ifndef  PORT_10_PIN_0
#define PORT_10_PIN_0                          (Port_PinType)(0x0a0)
#endif

/* Symbolic Name: Port10 Pin1 */
/* To prevent double declaration */
#ifndef  PORT_10_PIN_1
#define PORT_10_PIN_1                          (Port_PinType)(0x0a1)
#endif

/* Symbolic Name: Port10 Pin2 */
/* To prevent double declaration */
#ifndef  PORT_10_PIN_2
#define PORT_10_PIN_2                          (Port_PinType)(0x0a2)
#endif

/* Symbolic Name: Port10 Pin3 */
/* To prevent double declaration */
#ifndef  PORT_10_PIN_3
#define PORT_10_PIN_3                          (Port_PinType)(0x0a3)
#endif

/* Symbolic Name: Port10 Pin4 */
/* To prevent double declaration */
#ifndef  PORT_10_PIN_4
#define PORT_10_PIN_4                          (Port_PinType)(0x0a4)
#endif

/* Symbolic Name: Port10 Pin5 */
/* To prevent double declaration */
#ifndef  PORT_10_PIN_5
#define PORT_10_PIN_5                          (Port_PinType)(0x0a5)
#endif

/* Symbolic Name: Port10 Pin6 */
/* To prevent double declaration */
#ifndef  PORT_10_PIN_6
#define PORT_10_PIN_6                          (Port_PinType)(0x0a6)
#endif

/* Symbolic Name: Port10 Pin7 */
/* To prevent double declaration */
#ifndef  PORT_10_PIN_7
#define PORT_10_PIN_7                          (Port_PinType)(0x0a7)
#endif

/* Symbolic Name: Port10 Pin8 */
/* To prevent double declaration */
#ifndef  PORT_10_PIN_8
#define PORT_10_PIN_8                          (Port_PinType)(0x0a8)
#endif

/*
                                   Port11                                      
*/

/* Symbolic Name: Port11 Pin0 */
/* To prevent double declaration */
#ifndef  PORT_11_PIN_0
#define PORT_11_PIN_0                          (Port_PinType)(0x0b0)
#endif

/* Symbolic Name: Port11 Pin1 */
/* To prevent double declaration */
#ifndef  PORT_11_PIN_1
#define PORT_11_PIN_1                          (Port_PinType)(0x0b1)
#endif

/* Symbolic Name: Port11 Pin2 */
/* To prevent double declaration */
#ifndef  PORT_11_PIN_2
#define PORT_11_PIN_2                          (Port_PinType)(0x0b2)
#endif

/* Symbolic Name: Port11 Pin3 */
/* To prevent double declaration */
#ifndef  PORT_11_PIN_3
#define PORT_11_PIN_3                          (Port_PinType)(0x0b3)
#endif

/* Symbolic Name: Port11 Pin4 */
/* To prevent double declaration */
#ifndef  PORT_11_PIN_4
#define PORT_11_PIN_4                          (Port_PinType)(0x0b4)
#endif

/* Symbolic Name: Port11 Pin5 */
/* To prevent double declaration */
#ifndef  PORT_11_PIN_5
#define PORT_11_PIN_5                          (Port_PinType)(0x0b5)
#endif

/* Symbolic Name: Port11 Pin6 */
/* To prevent double declaration */
#ifndef  PORT_11_PIN_6
#define PORT_11_PIN_6                          (Port_PinType)(0x0b6)
#endif

/* Symbolic Name: Port11 Pin7 */
/* To prevent double declaration */
#ifndef  PORT_11_PIN_7
#define PORT_11_PIN_7                          (Port_PinType)(0x0b7)
#endif

/* Symbolic Name: Port11 Pin8 */
/* To prevent double declaration */
#ifndef  PORT_11_PIN_8
#define PORT_11_PIN_8                          (Port_PinType)(0x0b8)
#endif

/* Symbolic Name: Port11 Pin9 */
/* To prevent double declaration */
#ifndef  PORT_11_PIN_9
#define PORT_11_PIN_9                          (Port_PinType)(0x0b9)
#endif

/* Symbolic Name: Port11 Pin10 */
/* To prevent double declaration */
#ifndef  PORT_11_PIN_10
#define PORT_11_PIN_10                          (Port_PinType)(0x0ba)
#endif

/* Symbolic Name: Port11 Pin11 */
/* To prevent double declaration */
#ifndef  PORT_11_PIN_11
#define PORT_11_PIN_11                          (Port_PinType)(0x0bb)
#endif

/* Symbolic Name: Port11 Pin12 */
/* To prevent double declaration */
#ifndef  PORT_11_PIN_12
#define PORT_11_PIN_12                          (Port_PinType)(0x0bc)
#endif

/* Symbolic Name: Port11 Pin13 */
/* To prevent double declaration */
#ifndef  PORT_11_PIN_13
#define PORT_11_PIN_13                          (Port_PinType)(0x0bd)
#endif

/* Symbolic Name: Port11 Pin14 */
/* To prevent double declaration */
#ifndef  PORT_11_PIN_14
#define PORT_11_PIN_14                          (Port_PinType)(0x0be)
#endif

/* Symbolic Name: Port11 Pin15 */
/* To prevent double declaration */
#ifndef  PORT_11_PIN_15
#define PORT_11_PIN_15                          (Port_PinType)(0x0bf)
#endif

/*
                                   Port12                                      
*/

/* Symbolic Name: Port12 Pin0 */
/* To prevent double declaration */
#ifndef  PORT_12_PIN_0
#define PORT_12_PIN_0                          (Port_PinType)(0x0c0)
#endif

/* Symbolic Name: Port12 Pin1 */
/* To prevent double declaration */
#ifndef  PORT_12_PIN_1
#define PORT_12_PIN_1                          (Port_PinType)(0x0c1)
#endif

/*
                                   Port13                                      
*/

/* Symbolic Name: Port13 Pin0 */
/* To prevent double declaration */
#ifndef  PORT_13_PIN_0
#define PORT_13_PIN_0                          (Port_PinType)(0x0d0)
#endif

/* Symbolic Name: Port13 Pin1 */
/* To prevent double declaration */
#ifndef  PORT_13_PIN_1
#define PORT_13_PIN_1                          (Port_PinType)(0x0d1)
#endif

/* Symbolic Name: Port13 Pin2 */
/* To prevent double declaration */
#ifndef  PORT_13_PIN_2
#define PORT_13_PIN_2                          (Port_PinType)(0x0d2)
#endif

/* Symbolic Name: Port13 Pin3 */
/* To prevent double declaration */
#ifndef  PORT_13_PIN_3
#define PORT_13_PIN_3                          (Port_PinType)(0x0d3)
#endif

/*
                                   Port14                                      
*/

/* Symbolic Name: Port14 Pin0 */
/* To prevent double declaration */
#ifndef  PORT_14_PIN_0
#define PORT_14_PIN_0                          (Port_PinType)(0x0e0)
#endif

/* Symbolic Name: Port14 Pin1 */
/* To prevent double declaration */
#ifndef  PORT_14_PIN_1
#define PORT_14_PIN_1                          (Port_PinType)(0x0e1)
#endif

/* Symbolic Name: Port14 Pin2 */
/* To prevent double declaration */
#ifndef  PORT_14_PIN_2
#define PORT_14_PIN_2                          (Port_PinType)(0x0e2)
#endif

/* Symbolic Name: Port14 Pin3 */
/* To prevent double declaration */
#ifndef  PORT_14_PIN_3
#define PORT_14_PIN_3                          (Port_PinType)(0x0e3)
#endif

/* Symbolic Name: Port14 Pin4 */
/* To prevent double declaration */
#ifndef  PORT_14_PIN_4
#define PORT_14_PIN_4                          (Port_PinType)(0x0e4)
#endif

/* Symbolic Name: Port14 Pin5 */
/* To prevent double declaration */
#ifndef  PORT_14_PIN_5
#define PORT_14_PIN_5                          (Port_PinType)(0x0e5)
#endif

/* Symbolic Name: Port14 Pin6 */
/* To prevent double declaration */
#ifndef  PORT_14_PIN_6
#define PORT_14_PIN_6                          (Port_PinType)(0x0e6)
#endif

/* Symbolic Name: Port14 Pin7 */
/* To prevent double declaration */
#ifndef  PORT_14_PIN_7
#define PORT_14_PIN_7                          (Port_PinType)(0x0e7)
#endif

/* Symbolic Name: Port14 Pin8 */
/* To prevent double declaration */
#ifndef  PORT_14_PIN_8
#define PORT_14_PIN_8                          (Port_PinType)(0x0e8)
#endif

/* Symbolic Name: Port14 Pin9 */
/* To prevent double declaration */
#ifndef  PORT_14_PIN_9
#define PORT_14_PIN_9                          (Port_PinType)(0x0e9)
#endif

/* Symbolic Name: Port14 Pin10 */
/* To prevent double declaration */
#ifndef  PORT_14_PIN_10
#define PORT_14_PIN_10                          (Port_PinType)(0x0ea)
#endif

/*
                                   Port15                                      
*/

/* Symbolic Name: Port15 Pin0 */
/* To prevent double declaration */
#ifndef  PORT_15_PIN_0
#define PORT_15_PIN_0                          (Port_PinType)(0x0f0)
#endif

/* Symbolic Name: Port15 Pin1 */
/* To prevent double declaration */
#ifndef  PORT_15_PIN_1
#define PORT_15_PIN_1                          (Port_PinType)(0x0f1)
#endif

/* Symbolic Name: Port15 Pin2 */
/* To prevent double declaration */
#ifndef  PORT_15_PIN_2
#define PORT_15_PIN_2                          (Port_PinType)(0x0f2)
#endif

/* Symbolic Name: Port15 Pin3 */
/* To prevent double declaration */
#ifndef  PORT_15_PIN_3
#define PORT_15_PIN_3                          (Port_PinType)(0x0f3)
#endif

/* Symbolic Name: Port15 Pin4 */
/* To prevent double declaration */
#ifndef  PORT_15_PIN_4
#define PORT_15_PIN_4                          (Port_PinType)(0x0f4)
#endif

/* Symbolic Name: Port15 Pin5 */
/* To prevent double declaration */
#ifndef  PORT_15_PIN_5
#define PORT_15_PIN_5                          (Port_PinType)(0x0f5)
#endif

/* Symbolic Name: Port15 Pin6 */
/* To prevent double declaration */
#ifndef  PORT_15_PIN_6
#define PORT_15_PIN_6                          (Port_PinType)(0x0f6)
#endif

/* Symbolic Name: Port15 Pin7 */
/* To prevent double declaration */
#ifndef  PORT_15_PIN_7
#define PORT_15_PIN_7                          (Port_PinType)(0x0f7)
#endif

/* Symbolic Name: Port15 Pin8 */
/* To prevent double declaration */
#ifndef  PORT_15_PIN_8
#define PORT_15_PIN_8                          (Port_PinType)(0x0f8)
#endif

/*
                                   Port20                                      
*/

/* Symbolic Name: Port20 Pin0 */
/* To prevent double declaration */
#ifndef  PORT_20_PIN_0
#define PORT_20_PIN_0                          (Port_PinType)(0x140)
#endif

/* Symbolic Name: Port20 Pin1 */
/* To prevent double declaration */
#ifndef  PORT_20_PIN_1
#define PORT_20_PIN_1                          (Port_PinType)(0x141)
#endif

/* Symbolic Name: Port20 Pin2 */
/* To prevent double declaration */
#ifndef  PORT_20_PIN_2
#define PORT_20_PIN_2                          (Port_PinType)(0x142)
#endif

/* Symbolic Name: Port20 Pin3 */
/* To prevent double declaration */
#ifndef  PORT_20_PIN_3
#define PORT_20_PIN_3                          (Port_PinType)(0x143)
#endif

/* Symbolic Name: Port20 Pin6 */
/* To prevent double declaration */
#ifndef  PORT_20_PIN_6
#define PORT_20_PIN_6                          (Port_PinType)(0x146)
#endif

/* Symbolic Name: Port20 Pin7 */
/* To prevent double declaration */
#ifndef  PORT_20_PIN_7
#define PORT_20_PIN_7                          (Port_PinType)(0x147)
#endif

/* Symbolic Name: Port20 Pin8 */
/* To prevent double declaration */
#ifndef  PORT_20_PIN_8
#define PORT_20_PIN_8                          (Port_PinType)(0x148)
#endif

/* Symbolic Name: Port20 Pin9 */
/* To prevent double declaration */
#ifndef  PORT_20_PIN_9
#define PORT_20_PIN_9                          (Port_PinType)(0x149)
#endif

/* Symbolic Name: Port20 Pin10 */
/* To prevent double declaration */
#ifndef  PORT_20_PIN_10
#define PORT_20_PIN_10                          (Port_PinType)(0x14a)
#endif

/* Symbolic Name: Port20 Pin11 */
/* To prevent double declaration */
#ifndef  PORT_20_PIN_11
#define PORT_20_PIN_11                          (Port_PinType)(0x14b)
#endif

/* Symbolic Name: Port20 Pin12 */
/* To prevent double declaration */
#ifndef  PORT_20_PIN_12
#define PORT_20_PIN_12                          (Port_PinType)(0x14c)
#endif

/* Symbolic Name: Port20 Pin13 */
/* To prevent double declaration */
#ifndef  PORT_20_PIN_13
#define PORT_20_PIN_13                          (Port_PinType)(0x14d)
#endif

/* Symbolic Name: Port20 Pin14 */
/* To prevent double declaration */
#ifndef  PORT_20_PIN_14
#define PORT_20_PIN_14                          (Port_PinType)(0x14e)
#endif

/*
                                   Port21                                      
*/

/* Symbolic Name: Port21 Pin0 */
/* To prevent double declaration */
#ifndef  PORT_21_PIN_0
#define PORT_21_PIN_0                          (Port_PinType)(0x150)
#endif

/* Symbolic Name: Port21 Pin1 */
/* To prevent double declaration */
#ifndef  PORT_21_PIN_1
#define PORT_21_PIN_1                          (Port_PinType)(0x151)
#endif

/* Symbolic Name: Port21 Pin2 */
/* To prevent double declaration */
#ifndef  PORT_21_PIN_2
#define PORT_21_PIN_2                          (Port_PinType)(0x152)
#endif

/* Symbolic Name: Port21 Pin3 */
/* To prevent double declaration */
#ifndef  PORT_21_PIN_3
#define PORT_21_PIN_3                          (Port_PinType)(0x153)
#endif

/* Symbolic Name: Port21 Pin4 */
/* To prevent double declaration */
#ifndef  PORT_21_PIN_4
#define PORT_21_PIN_4                          (Port_PinType)(0x154)
#endif

/* Symbolic Name: Port21 Pin5 */
/* To prevent double declaration */
#ifndef  PORT_21_PIN_5
#define PORT_21_PIN_5                          (Port_PinType)(0x155)
#endif

/* Symbolic Name: Port21 Pin6 */
/* To prevent double declaration */
#ifndef  PORT_21_PIN_6
#define PORT_21_PIN_6                          (Port_PinType)(0x156)
#endif

/* Symbolic Name: Port21 Pin7 */
/* To prevent double declaration */
#ifndef  PORT_21_PIN_7
#define PORT_21_PIN_7                          (Port_PinType)(0x157)
#endif

/*
                                   Port22                                      
*/

/* Symbolic Name: Port22 Pin0 */
/* To prevent double declaration */
#ifndef  PORT_22_PIN_0
#define PORT_22_PIN_0                          (Port_PinType)(0x160)
#endif

/* Symbolic Name: Port22 Pin1 */
/* To prevent double declaration */
#ifndef  PORT_22_PIN_1
#define PORT_22_PIN_1                          (Port_PinType)(0x161)
#endif

/* Symbolic Name: Port22 Pin2 */
/* To prevent double declaration */
#ifndef  PORT_22_PIN_2
#define PORT_22_PIN_2                          (Port_PinType)(0x162)
#endif

/* Symbolic Name: Port22 Pin3 */
/* To prevent double declaration */
#ifndef  PORT_22_PIN_3
#define PORT_22_PIN_3                          (Port_PinType)(0x163)
#endif

/* Symbolic Name: Port22 Pin4 */
/* To prevent double declaration */
#ifndef  PORT_22_PIN_4
#define PORT_22_PIN_4                          (Port_PinType)(0x164)
#endif

/* Symbolic Name: Port22 Pin5 */
/* To prevent double declaration */
#ifndef  PORT_22_PIN_5
#define PORT_22_PIN_5                          (Port_PinType)(0x165)
#endif

/* Symbolic Name: Port22 Pin6 */
/* To prevent double declaration */
#ifndef  PORT_22_PIN_6
#define PORT_22_PIN_6                          (Port_PinType)(0x166)
#endif

/* Symbolic Name: Port22 Pin7 */
/* To prevent double declaration */
#ifndef  PORT_22_PIN_7
#define PORT_22_PIN_7                          (Port_PinType)(0x167)
#endif

/* Symbolic Name: Port22 Pin8 */
/* To prevent double declaration */
#ifndef  PORT_22_PIN_8
#define PORT_22_PIN_8                          (Port_PinType)(0x168)
#endif

/* Symbolic Name: Port22 Pin9 */
/* To prevent double declaration */
#ifndef  PORT_22_PIN_9
#define PORT_22_PIN_9                          (Port_PinType)(0x169)
#endif

/* Symbolic Name: Port22 Pin10 */
/* To prevent double declaration */
#ifndef  PORT_22_PIN_10
#define PORT_22_PIN_10                          (Port_PinType)(0x16a)
#endif

/* Symbolic Name: Port22 Pin11 */
/* To prevent double declaration */
#ifndef  PORT_22_PIN_11
#define PORT_22_PIN_11                          (Port_PinType)(0x16b)
#endif

/*
                                   Port23                                      
*/

/* Symbolic Name: Port23 Pin0 */
/* To prevent double declaration */
#ifndef  PORT_23_PIN_0
#define PORT_23_PIN_0                          (Port_PinType)(0x170)
#endif

/* Symbolic Name: Port23 Pin1 */
/* To prevent double declaration */
#ifndef  PORT_23_PIN_1
#define PORT_23_PIN_1                          (Port_PinType)(0x171)
#endif

/* Symbolic Name: Port23 Pin2 */
/* To prevent double declaration */
#ifndef  PORT_23_PIN_2
#define PORT_23_PIN_2                          (Port_PinType)(0x172)
#endif

/* Symbolic Name: Port23 Pin3 */
/* To prevent double declaration */
#ifndef  PORT_23_PIN_3
#define PORT_23_PIN_3                          (Port_PinType)(0x173)
#endif

/* Symbolic Name: Port23 Pin4 */
/* To prevent double declaration */
#ifndef  PORT_23_PIN_4
#define PORT_23_PIN_4                          (Port_PinType)(0x174)
#endif

/* Symbolic Name: Port23 Pin5 */
/* To prevent double declaration */
#ifndef  PORT_23_PIN_5
#define PORT_23_PIN_5                          (Port_PinType)(0x175)
#endif

/* Symbolic Name: Port23 Pin6 */
/* To prevent double declaration */
#ifndef  PORT_23_PIN_6
#define PORT_23_PIN_6                          (Port_PinType)(0x176)
#endif

/* Symbolic Name: Port23 Pin7 */
/* To prevent double declaration */
#ifndef  PORT_23_PIN_7
#define PORT_23_PIN_7                          (Port_PinType)(0x177)
#endif

/*
                                   Port32                                      
*/

/* Symbolic Name: Port32 Pin0 */
/* To prevent double declaration */
#ifndef  PORT_32_PIN_0
#define PORT_32_PIN_0                          (Port_PinType)(0x200)
#endif

/* Symbolic Name: Port32 Pin2 */
/* To prevent double declaration */
#ifndef  PORT_32_PIN_2
#define PORT_32_PIN_2                          (Port_PinType)(0x202)
#endif

/* Symbolic Name: Port32 Pin3 */
/* To prevent double declaration */
#ifndef  PORT_32_PIN_3
#define PORT_32_PIN_3                          (Port_PinType)(0x203)
#endif

/* Symbolic Name: Port32 Pin4 */
/* To prevent double declaration */
#ifndef  PORT_32_PIN_4
#define PORT_32_PIN_4                          (Port_PinType)(0x204)
#endif

/* Symbolic Name: Port32 Pin5 */
/* To prevent double declaration */
#ifndef  PORT_32_PIN_5
#define PORT_32_PIN_5                          (Port_PinType)(0x205)
#endif

/* Symbolic Name: Port32 Pin6 */
/* To prevent double declaration */
#ifndef  PORT_32_PIN_6
#define PORT_32_PIN_6                          (Port_PinType)(0x206)
#endif

/* Symbolic Name: Port32 Pin7 */
/* To prevent double declaration */
#ifndef  PORT_32_PIN_7
#define PORT_32_PIN_7                          (Port_PinType)(0x207)
#endif

/*
                                   Port33                                      
*/

/* Symbolic Name: Port33 Pin0 */
/* To prevent double declaration */
#ifndef  PORT_33_PIN_0
#define PORT_33_PIN_0                          (Port_PinType)(0x210)
#endif

/* Symbolic Name: Port33 Pin1 */
/* To prevent double declaration */
#ifndef  PORT_33_PIN_1
#define PORT_33_PIN_1                          (Port_PinType)(0x211)
#endif

/* Symbolic Name: Port33 Pin2 */
/* To prevent double declaration */
#ifndef  PORT_33_PIN_2
#define PORT_33_PIN_2                          (Port_PinType)(0x212)
#endif

/* Symbolic Name: Port33 Pin3 */
/* To prevent double declaration */
#ifndef  PORT_33_PIN_3
#define PORT_33_PIN_3                          (Port_PinType)(0x213)
#endif

/* Symbolic Name: Port33 Pin4 */
/* To prevent double declaration */
#ifndef  PORT_33_PIN_4
#define PORT_33_PIN_4                          (Port_PinType)(0x214)
#endif

/* Symbolic Name: Port33 Pin5 */
/* To prevent double declaration */
#ifndef  PORT_33_PIN_5
#define PORT_33_PIN_5                          (Port_PinType)(0x215)
#endif

/* Symbolic Name: Port33 Pin6 */
/* To prevent double declaration */
#ifndef  PORT_33_PIN_6
#define PORT_33_PIN_6                          (Port_PinType)(0x216)
#endif

/* Symbolic Name: Port33 Pin7 */
/* To prevent double declaration */
#ifndef  PORT_33_PIN_7
#define PORT_33_PIN_7                          (Port_PinType)(0x217)
#endif

/* Symbolic Name: Port33 Pin8 */
/* To prevent double declaration */
#ifndef  PORT_33_PIN_8
#define PORT_33_PIN_8                          (Port_PinType)(0x218)
#endif

/* Symbolic Name: Port33 Pin9 */
/* To prevent double declaration */
#ifndef  PORT_33_PIN_9
#define PORT_33_PIN_9                          (Port_PinType)(0x219)
#endif

/* Symbolic Name: Port33 Pin10 */
/* To prevent double declaration */
#ifndef  PORT_33_PIN_10
#define PORT_33_PIN_10                          (Port_PinType)(0x21a)
#endif

/* Symbolic Name: Port33 Pin11 */
/* To prevent double declaration */
#ifndef  PORT_33_PIN_11
#define PORT_33_PIN_11                          (Port_PinType)(0x21b)
#endif

/* Symbolic Name: Port33 Pin12 */
/* To prevent double declaration */
#ifndef  PORT_33_PIN_12
#define PORT_33_PIN_12                          (Port_PinType)(0x21c)
#endif

/* Symbolic Name: Port33 Pin13 */
/* To prevent double declaration */
#ifndef  PORT_33_PIN_13
#define PORT_33_PIN_13                          (Port_PinType)(0x21d)
#endif

/* Symbolic Name: Port33 Pin14 */
/* To prevent double declaration */
#ifndef  PORT_33_PIN_14
#define PORT_33_PIN_14                          (Port_PinType)(0x21e)
#endif

/* Symbolic Name: Port33 Pin15 */
/* To prevent double declaration */
#ifndef  PORT_33_PIN_15
#define PORT_33_PIN_15                          (Port_PinType)(0x21f)
#endif

/*
                                   Port34                                      
*/

/* Symbolic Name: Port34 Pin1 */
/* To prevent double declaration */
#ifndef  PORT_34_PIN_1
#define PORT_34_PIN_1                          (Port_PinType)(0x221)
#endif

/* Symbolic Name: Port34 Pin2 */
/* To prevent double declaration */
#ifndef  PORT_34_PIN_2
#define PORT_34_PIN_2                          (Port_PinType)(0x222)
#endif

/* Symbolic Name: Port34 Pin3 */
/* To prevent double declaration */
#ifndef  PORT_34_PIN_3
#define PORT_34_PIN_3                          (Port_PinType)(0x223)
#endif

/* Symbolic Name: Port34 Pin4 */
/* To prevent double declaration */
#ifndef  PORT_34_PIN_4
#define PORT_34_PIN_4                          (Port_PinType)(0x224)
#endif

/* Symbolic Name: Port34 Pin5 */
/* To prevent double declaration */
#ifndef  PORT_34_PIN_5
#define PORT_34_PIN_5                          (Port_PinType)(0x225)
#endif

/*
                                   Port40                                      
*/

/* Symbolic Name: Port40 Pin0 */
/* To prevent double declaration */
#ifndef  PORT_40_PIN_0
#define PORT_40_PIN_0                          (Port_PinType)(0x280)
#endif

/* Symbolic Name: Port40 Pin1 */
/* To prevent double declaration */
#ifndef  PORT_40_PIN_1
#define PORT_40_PIN_1                          (Port_PinType)(0x281)
#endif

/* Symbolic Name: Port40 Pin2 */
/* To prevent double declaration */
#ifndef  PORT_40_PIN_2
#define PORT_40_PIN_2                          (Port_PinType)(0x282)
#endif

/* Symbolic Name: Port40 Pin3 */
/* To prevent double declaration */
#ifndef  PORT_40_PIN_3
#define PORT_40_PIN_3                          (Port_PinType)(0x283)
#endif

/* Symbolic Name: Port40 Pin4 */
/* To prevent double declaration */
#ifndef  PORT_40_PIN_4
#define PORT_40_PIN_4                          (Port_PinType)(0x284)
#endif

/* Symbolic Name: Port40 Pin5 */
/* To prevent double declaration */
#ifndef  PORT_40_PIN_5
#define PORT_40_PIN_5                          (Port_PinType)(0x285)
#endif

/* Symbolic Name: Port40 Pin6 */
/* To prevent double declaration */
#ifndef  PORT_40_PIN_6
#define PORT_40_PIN_6                          (Port_PinType)(0x286)
#endif

/* Symbolic Name: Port40 Pin7 */
/* To prevent double declaration */
#ifndef  PORT_40_PIN_7
#define PORT_40_PIN_7                          (Port_PinType)(0x287)
#endif

/* Symbolic Name: Port40 Pin8 */
/* To prevent double declaration */
#ifndef  PORT_40_PIN_8
#define PORT_40_PIN_8                          (Port_PinType)(0x288)
#endif

/* Symbolic Name: Port40 Pin9 */
/* To prevent double declaration */
#ifndef  PORT_40_PIN_9
#define PORT_40_PIN_9                          (Port_PinType)(0x289)
#endif




/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif /* PORT_CFG_H */

