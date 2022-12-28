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
**  FILENAME  : Port_PBCfg.c                                                  **
**                                                                            **
**  $CC VERSION : \main\30 $                                                 **
**                                                                            **
**  DATE, TIME: 2014-09-29, 11:35:22                                      **
**                                                                            **
**  GENERATOR : Build b131017-0205                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Port configuration generated from ECU 
                   configuration file ( Port.bmd)                             **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

 
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Port Header file */
#include "Port.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
** Name             : Portx_lPdrConfig                                        **
**                                                                            **
** Description      : Macro to configure Portx Pdr register parameters        **
**                                                                            **
*******************************************************************************/
/* Macro definition for PORT pad drive control register Pn_PDR0 */
#define  Portx_lPdrConfig1(Pd0,Pd1,Pd2,Pd3,Pd4,Pd5,Pd6,Pd7)                    \
         ( ((uint32)(Pd7) << (uint32)28) | ((uint32)(Pd6) << (uint32)24) |     \
           ((uint32)(Pd5) << (uint32)20) | ((uint32)(Pd4) << (uint32)16) |     \
           ((uint32)(Pd3) << (uint32)12)|  ((uint32)(Pd2) << (uint32)8)  |     \
           ((uint32)(Pd1) << (uint32)4) | (uint32)(Pd0)                        \
         )

/* Macro definition for PORT pad drive control register Pn_PDR1 */
#define  Portx_lPdrConfig2(Pd8,Pd9,Pd10,Pd11,Pd12,Pd13,Pd14,Pd15)              \
         ( ((uint32)(Pd15) << (uint32)28) | ((uint32)(Pd14) << (uint32)24) |   \
           ((uint32)(Pd13) << (uint32)20) | ((uint32)(Pd12) << (uint32)16) |   \
           ((uint32)(Pd11) << (uint32)12)|  ((uint32)(Pd10) << (uint32)8)  |   \
           ((uint32)(Pd9) << (uint32)4) | (uint32)(Pd8)                        \
         )                  
         
/* Macro definition for PORT Pad Disable Control Register */
#define Port_lDiscSet(b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15)   \
  (uint16)(                                                                    \
            (uint32)(b0) | ((uint32)(b1) << (uint32)1) |                       \
            ((uint32)(b2) << (uint32)2) | ((uint32)(b3) << (uint32)3) |        \
            ((uint32)(b4) << (uint32)4) | ((uint32)(b5) << (uint32)5) |        \
            ((uint32)(b6) << (uint32)6) | ((uint32)(b7) << (uint32)7) |        \
            ((uint32)(b8) << (uint32)8) | ((uint32)(b9) << (uint32)9) |        \
            ((uint32)(b10) << (uint32)10) | ((uint32)(b11) << (uint32)11) |    \
            ((uint32)(b12) << (uint32)12) | ((uint32)(b13)<< (uint32)13) |     \
            ((uint32)(b14) << (uint32)14) | ((uint32)(b15) << (uint32)15)      \
           )

/* Macro definition for PORT LPCR register for LVDSH */
#define Port_lLvdsh(RDISCL,RDIS,TERM,LRTERM,Reduced_IEEE,TDISCL,TDIS,TPD,TPWD) \
  (uint32)(                                                                    \
            ((uint32)(RDISCL)) | ((uint32)(RDIS) << (uint32)1) |               \
            ((uint32)(TERM) << (uint32)2) | ((uint32)(LRTERM) << (uint32)3) |  \
            ((uint32)(Reduced_IEEE) << (uint32)8) |                            \
            ((uint32)(TDISCL) << (uint32)12) | ((uint32)(TDIS) << (uint32)13)| \
            ((uint32)(TPD) << (uint32)14) | ((uint32)(TPWD) << (uint32)15)     \
           )

/* Macro definition for PORT LPCR register for LVDSM */
#define Port_lLvdsm(PS1)                                                       \
  (uint32)(                                                                    \
            ((uint32)(PS1) << (uint32)1)                                       \
           )

/* Macro definition for PORT PCSR register */
#define Port_lPcsr(b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15)      \
  (uint32)(                                                                    \
            ((uint32)(b0)) | ((uint32)(b1) << (uint32)1) |                     \
            ((uint32)(b2) << (uint32)2) | ((uint32)(b3) << (uint32)3) |        \
            ((uint32)(b4) << (uint32)4) | ((uint32)(b5) << (uint32)5) |        \
            ((uint32)(b6) << (uint32)6) | ((uint32)(b7) << (uint32)7) |        \
            ((uint32)(b8) << (uint32)8) | ((uint32)(b9) << (uint32)9) |        \
            ((uint32)(b10) << (uint32)10) | ((uint32)(b11) << (uint32)11) |    \
            ((uint32)(b12) << (uint32)12) | ((uint32)(b13) << (uint32)13) |    \
            ((uint32)(b14) << (uint32)14) | ((uint32)(b15) << (uint32)15)      \
           )

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/* MISRA RULE 87 VIOLATION: Inclusion of MemMap.h in between the code can't 
   be avoided as it is required for mapping global variables, constants 
   and code
*/ 
/*lint -esym( 960, 87 ) Note 960: Violates MISRA Required Rule 87, 
                       only preprocessor statements and comments before 
                       '#include MemMap.h'
*/
/*lint -e537 Warning 537: Repeated include file MemMap.h */


#define PORT_START_SEC_POSTBUILDCFG
#include "MemMap.h"

/*******************************************************************************
**                      Configuration Options                                 **
*******************************************************************************/
/*
                     Container : PortPinConfiguration
*/

/* 
Configuration Options: Physical pin level
-LOW  (Low Volatage Level)
-HIGH (High Voltage Level) 
*/
#define  PORT_PIN_LOW                       (0x00U)
#define  PORT_PIN_HIGH                      (0x01U)

/* Macros to define pin Default Input Output control value */
#define  PORT_PIN_DEFAULT                   (0x10U)

/* 
Configuration Options: Pin input characteristics 
-NO PULL
-PULL DOWN
-PULL UP
*/
#define  PORT_PIN_IN_NO_PULL                (0x00U)
#define  PORT_PIN_IN_PULL_DOWN              (0x08U)
#define  PORT_PIN_IN_PULL_UP                (0x10U)

/* 
Configuration Options: Pin output characteristics 
-PUSHPULL
-OPENDRAIN
*/
#define  PORT_PIN_OUT_PUSHPULL              (0x00U)
#define  PORT_PIN_OUT_OPENDRAIN             (0x40U)

/*
Configuration Options: Pin Pad Level  
*/
#define  PORT_PDR_CMOS_AUTOMOTIVE_LEVEL     (0x0U)
#define  PORT_PDR_TTL_LEVEL                 (0x8U)

/*
Configuration Options: Pin driver strength
*/
#define  PORT_CMOS_SPEED_GRADE1             (0x0U)
#define  PORT_CMOS_SPEED_GRADE2             (0x1U)
#define  PORT_CMOS_SPEED_GRADE3             (0x2U)
#define  PORT_CMOS_SPEED_GRADE4             (0x3U)
#define  PORT_LVDS_SPEED_GRADE1             (0x4U)
#define  PORT_LVDS_SPEED_GRADE2             (0x5U)
#define  PORT_LVDS_SPEED_GRADE3             (0x6U)
#define  PORT_LVDS_SPEED_GRADE4             (0x7U)

/* Pin driver strength value for the non available pins*/
#define  PORT_PIN_PAD_LEVEL_DEFAULT         (0x0U)

/* Configuration Options: Pin drive strength, for class Adc type pad    */
#define  PORT_PDR_ADC                       (0x1U)

/*
  Some of the Pins doesn't have driver strength, To access the same
  pin this null value macro is introduced.
*/
#define  PORT_PDR_ZERO                      (0x0U)

/* For the Px_DISC register value set */
#define  PORT_PIN_ANALOG_INPUT_ENABLE       (0x1U)
#define  PORT_PIN_ANALOG_INPUT_DISABLE      (0x0U)

/* For Pn_LPCR registers wrt LVDSH pads */
#define Port_LVDS_PAD_SUPPLY_3_3_VOLT    (0x1U)
#define Port_LVDS_PAD_SUPPLY_5_VOLT      (0x0U)

/* For Pn_LPCR registers wrt LVDSH pads */
#define PORT_LVDS_PORT_CONTROLLED           (0x0U)
#define PORT_LVDS_HSCT_CONTROLLED           (0x1U)
#define PORT_LVDS_ENABLE                    (0x0U)
#define PORT_LVDS_DISABLE                   (0x1U)
#define PORT_LVDS_INTERNAML_TERMINATION     (0x1U)
#define PORT_LVDS_EXTERNAL_TERMINATION      (0x0U)
#define PORT_LVDS_POLY_RESISTOR_TERM        (0x8U)
#define PORT_LVDS_IEEE_GEN_PURPOSE_LINK     (0x0U)
#define PORT_LVDS_IEEE_REDUCED_LINK         (0x2U)
#define PORT_LVDS_SPECIAL_REDUCED_LINK      (0x1U)
#define PORT_LVDS_POWER_DOWN                (0x1U)
#define PORT_LVDS_POWER_ON                  (0x0U)
#define PORT_LVDS_POWDOWN_PULDOWN_EN        (0x1U)
#define PORT_LVDS_POWDOWN_PULDOWN_DIS       (0x0U)
#define PORT_LVDS_DEFAULT                   (0x0U)

/* For PCSR register */
#define PORT_PCSR_DEFAULT                   (0x0U)
#define PORT_PCSR_ENABLE                    (0x1U)
#define PORT_PCSR_DISABLE                   (0x0U)

/******************************************************************************/


static const Port_n_ConfigType Port_kConfiguration0[] = 
{
/*                              Port0                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      {
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 0*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 1*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 2*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 3*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 4*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 5*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 6*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 7*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 8*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 9*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 10*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 11*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 12*/
         (PORT_PIN_DEFAULT),/*Pin 13*/
         (PORT_PIN_DEFAULT),/*Pin 14*/
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    },
    {
      /* Port pins initial level configuration */
      {
         PORT_PIN_LOW,/* Pin 0 */ 
         PORT_PIN_LOW,/* Pin 1 */ 
         PORT_PIN_LOW,/* Pin 2 */ 
         PORT_PIN_LOW,/* Pin 3 */ 
         PORT_PIN_LOW,/* Pin 4 */ 
         PORT_PIN_LOW,/* Pin 5 */ 
         PORT_PIN_LOW,/* Pin 6 */ 
         PORT_PIN_LOW,/* Pin 7 */ 
         PORT_PIN_LOW,/* Pin 8 */ 
         PORT_PIN_LOW,/* Pin 9 */ 
         PORT_PIN_LOW,/* Pin 10 */ 
         PORT_PIN_LOW,/* Pin 11 */ 
         PORT_PIN_LOW,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      }
    },      
    /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 0 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 1 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 2 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 3 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 4 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 5 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 6 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1) /* Pin 7 */ 
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 8 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 9 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 10 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 11 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 12 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 13 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 14 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT) /* Pin 15 */ 
                     ),
    {/* Port pin run time mode changeable or not configuration */
      {
         PORT_PIN_MODE_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_MODE_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_MODE_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_MODE_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {/* Port pin run time direction changeable or not configuration */
      {
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {
      /* Port pins direction, characteristics and mode configuration if 
         direction is changeable */   
      {
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 0*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 1*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 2*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 3*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 4*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 5*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 6*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 7*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 8*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 9*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 10*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 11*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 12*/ 
         (PORT_PIN_DEFAULT),/*Pin 13*/ 
         (PORT_PIN_DEFAULT),/*Pin 14*/ 
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    } 
   },
/*                              Port1                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      {
         (PORT_PIN_DEFAULT),/*Pin 0*/
         (PORT_PIN_DEFAULT),/*Pin 1*/
         (PORT_PIN_DEFAULT),/*Pin 2*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 3*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 4*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 5*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 6*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 7*/
         (PORT_PIN_DEFAULT),/*Pin 8*/
         (PORT_PIN_DEFAULT),/*Pin 9*/
         (PORT_PIN_DEFAULT),/*Pin 10*/
         (PORT_PIN_DEFAULT),/*Pin 11*/
         (PORT_PIN_DEFAULT),/*Pin 12*/
         (PORT_PIN_DEFAULT),/*Pin 13*/
         (PORT_PIN_DEFAULT),/*Pin 14*/
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    },
    {
      /* Port pins initial level configuration */
      {
         0U,/* Pin 0 */ 
         0U,/* Pin 1 */ 
         0U,/* Pin 2 */ 
         PORT_PIN_LOW,/* Pin 3 */ 
         PORT_PIN_LOW,/* Pin 4 */ 
         PORT_PIN_LOW,/* Pin 5 */ 
         PORT_PIN_LOW,/* Pin 6 */ 
         PORT_PIN_LOW,/* Pin 7 */ 
         0U,/* Pin 8 */ 
         0U,/* Pin 9 */ 
         0U,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      }
    },      
    /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 0 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 1 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 2 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 3 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 4 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 5 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 6 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4) /* Pin 7 */ 
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 8 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 9 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 10 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 11 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 12 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 13 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 14 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT) /* Pin 15 */ 
                     ),
    {/* Port pin run time mode changeable or not configuration */
      {
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {/* Port pin run time direction changeable or not configuration */
      {
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {
      /* Port pins direction, characteristics and mode configuration if 
         direction is changeable */   
      {
         (PORT_PIN_DEFAULT),/*Pin 0*/ 
         (PORT_PIN_DEFAULT),/*Pin 1*/ 
         (PORT_PIN_DEFAULT),/*Pin 2*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 3*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 4*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 5*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 6*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 7*/ 
         (PORT_PIN_DEFAULT),/*Pin 8*/ 
         (PORT_PIN_DEFAULT),/*Pin 9*/ 
         (PORT_PIN_DEFAULT),/*Pin 10*/ 
         (PORT_PIN_DEFAULT),/*Pin 11*/ 
         (PORT_PIN_DEFAULT),/*Pin 12*/ 
         (PORT_PIN_DEFAULT),/*Pin 13*/ 
         (PORT_PIN_DEFAULT),/*Pin 14*/ 
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    } 
   },
/*                              Port2                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      {
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 0*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT2),/*Pin 1*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 2*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 3*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 4*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 5*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 6*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 7*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 8*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 9*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 10*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 11*/
         (PORT_PIN_DEFAULT),/*Pin 12*/
         (PORT_PIN_DEFAULT),/*Pin 13*/
         (PORT_PIN_DEFAULT),/*Pin 14*/
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    },
    {
      /* Port pins initial level configuration */
      {
         PORT_PIN_LOW,/* Pin 0 */ 
         PORT_PIN_HIGH,/* Pin 1 */ 
         PORT_PIN_LOW,/* Pin 2 */ 
         PORT_PIN_LOW,/* Pin 3 */ 
         PORT_PIN_LOW,/* Pin 4 */ 
         PORT_PIN_LOW,/* Pin 5 */ 
         PORT_PIN_LOW,/* Pin 6 */ 
         PORT_PIN_LOW,/* Pin 7 */ 
         PORT_PIN_LOW,/* Pin 8 */ 
         PORT_PIN_LOW,/* Pin 9 */ 
         PORT_PIN_LOW,/* Pin 10 */ 
         PORT_PIN_LOW,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      }
    },      
    /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 0 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 1 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 2 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 3 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 4 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 5 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 6 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1) /* Pin 7 */ 
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 8 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 9 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 10 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 11 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 12 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 13 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 14 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT) /* Pin 15 */ 
                     ),
    {/* Port pin run time mode changeable or not configuration */
      {
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_MODE_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_MODE_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_MODE_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {/* Port pin run time direction changeable or not configuration */
      {
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {
      /* Port pins direction, characteristics and mode configuration if 
         direction is changeable */   
      {
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 0*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT2),/*Pin 1*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 2*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 3*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 4*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 5*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 6*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 7*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 8*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 9*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 10*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 11*/ 
         (PORT_PIN_DEFAULT),/*Pin 12*/ 
         (PORT_PIN_DEFAULT),/*Pin 13*/ 
         (PORT_PIN_DEFAULT),/*Pin 14*/ 
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    } 
   },
/*                              Port10                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      {
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 0*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 1*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 2*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 3*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 4*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 5*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 6*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 7*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 8*/
         (PORT_PIN_DEFAULT),/*Pin 9*/
         (PORT_PIN_DEFAULT),/*Pin 10*/
         (PORT_PIN_DEFAULT),/*Pin 11*/
         (PORT_PIN_DEFAULT),/*Pin 12*/
         (PORT_PIN_DEFAULT),/*Pin 13*/
         (PORT_PIN_DEFAULT),/*Pin 14*/
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    },
    {
      /* Port pins initial level configuration */
      {
         PORT_PIN_LOW,/* Pin 0 */ 
         PORT_PIN_LOW,/* Pin 1 */ 
         PORT_PIN_LOW,/* Pin 2 */ 
         PORT_PIN_LOW,/* Pin 3 */ 
         PORT_PIN_LOW,/* Pin 4 */ 
         PORT_PIN_LOW,/* Pin 5 */ 
         PORT_PIN_LOW,/* Pin 6 */ 
         PORT_PIN_LOW,/* Pin 7 */ 
         PORT_PIN_LOW,/* Pin 8 */ 
         0U,/* Pin 9 */ 
         0U,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      }
    },      
    /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 0 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 1 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 2 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 3 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 4 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 5 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 6 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4) /* Pin 7 */ 
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 8 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 9 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 10 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 11 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 12 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 13 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 14 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT) /* Pin 15 */ 
                     ),
    {/* Port pin run time mode changeable or not configuration */
      {
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_MODE_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {/* Port pin run time direction changeable or not configuration */
      {
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {
      /* Port pins direction, characteristics and mode configuration if 
         direction is changeable */   
      {
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 0*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 1*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 2*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 3*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 4*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 5*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 6*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 7*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 8*/ 
         (PORT_PIN_DEFAULT),/*Pin 9*/ 
         (PORT_PIN_DEFAULT),/*Pin 10*/ 
         (PORT_PIN_DEFAULT),/*Pin 11*/ 
         (PORT_PIN_DEFAULT),/*Pin 12*/ 
         (PORT_PIN_DEFAULT),/*Pin 13*/ 
         (PORT_PIN_DEFAULT),/*Pin 14*/ 
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    } 
   },
/*                              Port11                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      {
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 0*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 1*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT5),/*Pin 2*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 3*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 4*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 5*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 6*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 7*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 8*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 9*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 10*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 11*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 12*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 13*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 14*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1) /*Pin 15*/ 
      }
    },
    {
      /* Port pins initial level configuration */
      {
         PORT_PIN_LOW,/* Pin 0 */ 
         PORT_PIN_LOW,/* Pin 1 */ 
         PORT_PIN_LOW,/* Pin 2 */ 
         PORT_PIN_LOW,/* Pin 3 */ 
         PORT_PIN_LOW,/* Pin 4 */ 
         PORT_PIN_LOW,/* Pin 5 */ 
         PORT_PIN_LOW,/* Pin 6 */ 
         PORT_PIN_LOW,/* Pin 7 */ 
         PORT_PIN_HIGH,/* Pin 8 */ 
         PORT_PIN_LOW,/* Pin 9 */ 
         PORT_PIN_LOW,/* Pin 10 */ 
         PORT_PIN_LOW,/* Pin 11 */ 
         PORT_PIN_LOW,/* Pin 12 */ 
         PORT_PIN_LOW,/* Pin 13 */ 
         PORT_PIN_LOW,/* Pin 14 */ 
         PORT_PIN_LOW /* Pin 15 */ 
      }
    },      
    /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 0 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 1 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 2 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 3 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 4 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 5 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 6 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4) /* Pin 7 */ 
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 8 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 9 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 10 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 11 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 12 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 13 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 14 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1) /* Pin 15 */ 
                     ),
    {/* Port pin run time mode changeable or not configuration */
      {
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_MODE_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_MODE_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_MODE_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_MODE_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_MODE_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_MODE_CHANGEABLE /* Pin 15 */ 
      }
    },
    {/* Port pin run time direction changeable or not configuration */
      {
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {
      /* Port pins direction, characteristics and mode configuration if 
         direction is changeable */   
      {
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 0*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 1*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT5),/*Pin 2*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 3*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 4*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 5*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 6*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 7*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 8*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 9*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 10*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 11*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 12*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 13*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 14*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1) /*Pin 15*/ 
      }
    } 
   },
/*                              Port12                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      {
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 0*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 1*/
         (PORT_PIN_DEFAULT),/*Pin 2*/
         (PORT_PIN_DEFAULT),/*Pin 3*/
         (PORT_PIN_DEFAULT),/*Pin 4*/
         (PORT_PIN_DEFAULT),/*Pin 5*/
         (PORT_PIN_DEFAULT),/*Pin 6*/
         (PORT_PIN_DEFAULT),/*Pin 7*/
         (PORT_PIN_DEFAULT),/*Pin 8*/
         (PORT_PIN_DEFAULT),/*Pin 9*/
         (PORT_PIN_DEFAULT),/*Pin 10*/
         (PORT_PIN_DEFAULT),/*Pin 11*/
         (PORT_PIN_DEFAULT),/*Pin 12*/
         (PORT_PIN_DEFAULT),/*Pin 13*/
         (PORT_PIN_DEFAULT),/*Pin 14*/
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    },
    {
      /* Port pins initial level configuration */
      {
         PORT_PIN_LOW,/* Pin 0 */ 
         PORT_PIN_LOW,/* Pin 1 */ 
         0U,/* Pin 2 */ 
         0U,/* Pin 3 */ 
         0U,/* Pin 4 */ 
         0U,/* Pin 5 */ 
         0U,/* Pin 6 */ 
         0U,/* Pin 7 */ 
         0U,/* Pin 8 */ 
         0U,/* Pin 9 */ 
         0U,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      }
    },      
    /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 0 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 1 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 2 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 3 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 4 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 5 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 6 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT) /* Pin 7 */ 
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 8 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 9 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 10 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 11 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 12 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 13 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 14 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT) /* Pin 15 */ 
                     ),
    {/* Port pin run time mode changeable or not configuration */
      {
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {/* Port pin run time direction changeable or not configuration */
      {
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {
      /* Port pins direction, characteristics and mode configuration if 
         direction is changeable */   
      {
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 0*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 1*/ 
         (PORT_PIN_DEFAULT),/*Pin 2*/ 
         (PORT_PIN_DEFAULT),/*Pin 3*/ 
         (PORT_PIN_DEFAULT),/*Pin 4*/ 
         (PORT_PIN_DEFAULT),/*Pin 5*/ 
         (PORT_PIN_DEFAULT),/*Pin 6*/ 
         (PORT_PIN_DEFAULT),/*Pin 7*/ 
         (PORT_PIN_DEFAULT),/*Pin 8*/ 
         (PORT_PIN_DEFAULT),/*Pin 9*/ 
         (PORT_PIN_DEFAULT),/*Pin 10*/ 
         (PORT_PIN_DEFAULT),/*Pin 11*/ 
         (PORT_PIN_DEFAULT),/*Pin 12*/ 
         (PORT_PIN_DEFAULT),/*Pin 13*/ 
         (PORT_PIN_DEFAULT),/*Pin 14*/ 
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    } 
   },
/*                              Port13                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      {
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT5),/*Pin 0*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT5),/*Pin 1*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT5),/*Pin 2*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT5),/*Pin 3*/
         (PORT_PIN_DEFAULT),/*Pin 4*/
         (PORT_PIN_DEFAULT),/*Pin 5*/
         (PORT_PIN_DEFAULT),/*Pin 6*/
         (PORT_PIN_DEFAULT),/*Pin 7*/
         (PORT_PIN_DEFAULT),/*Pin 8*/
         (PORT_PIN_DEFAULT),/*Pin 9*/
         (PORT_PIN_DEFAULT),/*Pin 10*/
         (PORT_PIN_DEFAULT),/*Pin 11*/
         (PORT_PIN_DEFAULT),/*Pin 12*/
         (PORT_PIN_DEFAULT),/*Pin 13*/
         (PORT_PIN_DEFAULT),/*Pin 14*/
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    },
    {
      /* Port pins initial level configuration */
      {
         PORT_PIN_LOW,/* Pin 0 */ 
         PORT_PIN_LOW,/* Pin 1 */ 
         PORT_PIN_LOW,/* Pin 2 */ 
         PORT_PIN_LOW,/* Pin 3 */ 
         0U,/* Pin 4 */ 
         0U,/* Pin 5 */ 
         0U,/* Pin 6 */ 
         0U,/* Pin 7 */ 
         0U,/* Pin 8 */ 
         0U,/* Pin 9 */ 
         0U,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      }
    },      
    /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 0 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 1 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 2 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 3 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 4 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 5 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 6 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT) /* Pin 7 */ 
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 8 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 9 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 10 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 11 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 12 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 13 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 14 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT) /* Pin 15 */ 
                     ),
    {/* Port pin run time mode changeable or not configuration */
      {
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {/* Port pin run time direction changeable or not configuration */
      {
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {
      /* Port pins direction, characteristics and mode configuration if 
         direction is changeable */   
      {
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT5),/*Pin 0*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT5),/*Pin 1*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT5),/*Pin 2*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT5),/*Pin 3*/ 
         (PORT_PIN_DEFAULT),/*Pin 4*/ 
         (PORT_PIN_DEFAULT),/*Pin 5*/ 
         (PORT_PIN_DEFAULT),/*Pin 6*/ 
         (PORT_PIN_DEFAULT),/*Pin 7*/ 
         (PORT_PIN_DEFAULT),/*Pin 8*/ 
         (PORT_PIN_DEFAULT),/*Pin 9*/ 
         (PORT_PIN_DEFAULT),/*Pin 10*/ 
         (PORT_PIN_DEFAULT),/*Pin 11*/ 
         (PORT_PIN_DEFAULT),/*Pin 12*/ 
         (PORT_PIN_DEFAULT),/*Pin 13*/ 
         (PORT_PIN_DEFAULT),/*Pin 14*/ 
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    } 
   },
/*                              Port14                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      {
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT5),/*Pin 0*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 1*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 2*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 3*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 4*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 5*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 6*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT3),/*Pin 7*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 8*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT6),/*Pin 9*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT6),/*Pin 10*/
         (PORT_PIN_DEFAULT),/*Pin 11*/
         (PORT_PIN_DEFAULT),/*Pin 12*/
         (PORT_PIN_DEFAULT),/*Pin 13*/
         (PORT_PIN_DEFAULT),/*Pin 14*/
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    },
    {
      /* Port pins initial level configuration */
      {
         PORT_PIN_LOW,/* Pin 0 */ 
         PORT_PIN_LOW,/* Pin 1 */ 
         PORT_PIN_LOW,/* Pin 2 */ 
         PORT_PIN_LOW,/* Pin 3 */ 
         PORT_PIN_LOW,/* Pin 4 */ 
         PORT_PIN_LOW,/* Pin 5 */ 
         PORT_PIN_LOW,/* Pin 6 */ 
         PORT_PIN_HIGH,/* Pin 7 */ 
         PORT_PIN_LOW,/* Pin 8 */ 
         PORT_PIN_LOW,/* Pin 9 */ 
         PORT_PIN_LOW,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      }
    },      
    /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 0 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 1 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 2 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 3 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 4 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 5 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 6 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1) /* Pin 7 */ 
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 8 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 9 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 10 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 11 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 12 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 13 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 14 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT) /* Pin 15 */ 
                     ),
    {/* Port pin run time mode changeable or not configuration */
      {
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {/* Port pin run time direction changeable or not configuration */
      {
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {
      /* Port pins direction, characteristics and mode configuration if 
         direction is changeable */   
      {
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT5),/*Pin 0*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 1*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 2*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 3*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 4*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 5*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 6*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT3),/*Pin 7*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 8*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT6),/*Pin 9*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT6),/*Pin 10*/ 
         (PORT_PIN_DEFAULT),/*Pin 11*/ 
         (PORT_PIN_DEFAULT),/*Pin 12*/ 
         (PORT_PIN_DEFAULT),/*Pin 13*/ 
         (PORT_PIN_DEFAULT),/*Pin 14*/ 
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    } 
   },
/*                              Port15                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      {
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 0*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 1*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 2*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT3),/*Pin 3*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 4*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT3),/*Pin 5*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT2),/*Pin 6*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 7*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 8*/
         (PORT_PIN_DEFAULT),/*Pin 9*/
         (PORT_PIN_DEFAULT),/*Pin 10*/
         (PORT_PIN_DEFAULT),/*Pin 11*/
         (PORT_PIN_DEFAULT),/*Pin 12*/
         (PORT_PIN_DEFAULT),/*Pin 13*/
         (PORT_PIN_DEFAULT),/*Pin 14*/
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    },
    {
      /* Port pins initial level configuration */
      {
         PORT_PIN_LOW,/* Pin 0 */ 
         PORT_PIN_LOW,/* Pin 1 */ 
         PORT_PIN_LOW,/* Pin 2 */ 
         PORT_PIN_LOW,/* Pin 3 */ 
         PORT_PIN_LOW,/* Pin 4 */ 
         PORT_PIN_LOW,/* Pin 5 */ 
         PORT_PIN_LOW,/* Pin 6 */ 
         PORT_PIN_LOW,/* Pin 7 */ 
         PORT_PIN_LOW,/* Pin 8 */ 
         0U,/* Pin 9 */ 
         0U,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      }
    },      
    /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 0 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 1 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 2 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 3 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 4 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 5 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 6 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4) /* Pin 7 */ 
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 8 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 9 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 10 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 11 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 12 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 13 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 14 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT) /* Pin 15 */ 
                     ),
    {/* Port pin run time mode changeable or not configuration */
      {
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {/* Port pin run time direction changeable or not configuration */
      {
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {
      /* Port pins direction, characteristics and mode configuration if 
         direction is changeable */   
      {
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 0*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 1*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 2*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT3),/*Pin 3*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 4*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT3),/*Pin 5*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT2),/*Pin 6*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 7*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 8*/ 
         (PORT_PIN_DEFAULT),/*Pin 9*/ 
         (PORT_PIN_DEFAULT),/*Pin 10*/ 
         (PORT_PIN_DEFAULT),/*Pin 11*/ 
         (PORT_PIN_DEFAULT),/*Pin 12*/ 
         (PORT_PIN_DEFAULT),/*Pin 13*/ 
         (PORT_PIN_DEFAULT),/*Pin 14*/ 
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    } 
   },
/*                              Port20                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      {
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 0*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 1*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 2*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT4),/*Pin 3*/
         (PORT_PIN_DEFAULT),/*Pin 4*/
         (PORT_PIN_DEFAULT),/*Pin 5*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT4),/*Pin 6*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 7*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT5),/*Pin 8*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 9*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT4),/*Pin 10*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 11*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 12*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 13*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 14*/
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    },
    {
      /* Port pins initial level configuration */
      {
         PORT_PIN_LOW,/* Pin 0 */ 
         PORT_PIN_LOW,/* Pin 1 */ 
         PORT_PIN_LOW,/* Pin 2 */ 
         PORT_PIN_HIGH,/* Pin 3 */ 
         0U,/* Pin 4 */ 
         0U,/* Pin 5 */ 
         PORT_PIN_HIGH,/* Pin 6 */ 
         PORT_PIN_LOW,/* Pin 7 */ 
         PORT_PIN_LOW,/* Pin 8 */ 
         PORT_PIN_LOW,/* Pin 9 */ 
         PORT_PIN_HIGH,/* Pin 10 */ 
         PORT_PIN_LOW,/* Pin 11 */ 
         PORT_PIN_LOW,/* Pin 12 */ 
         PORT_PIN_LOW,/* Pin 13 */ 
         PORT_PIN_LOW,/* Pin 14 */ 
         0U /* Pin 15 */ 
      }
    },      
    /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 0 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 1 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 2 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 3 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 4 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 5 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 6 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4) /* Pin 7 */ 
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 8 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 9 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 10 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 11 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 12 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 13 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 14 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT) /* Pin 15 */ 
                     ),
    {/* Port pin run time mode changeable or not configuration */
      {
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_MODE_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {/* Port pin run time direction changeable or not configuration */
      {
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {
      /* Port pins direction, characteristics and mode configuration if 
         direction is changeable */   
      {
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 0*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 1*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 2*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT4),/*Pin 3*/ 
         (PORT_PIN_DEFAULT),/*Pin 4*/ 
         (PORT_PIN_DEFAULT),/*Pin 5*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT4),/*Pin 6*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 7*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT5),/*Pin 8*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 9*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT4),/*Pin 10*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 11*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 12*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 13*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 14*/ 
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    } 
   },
/*                              Port21                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      {
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 0*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 1*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 2*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 3*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 4*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 5*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 6*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT2),/*Pin 7*/
         (PORT_PIN_DEFAULT),/*Pin 8*/
         (PORT_PIN_DEFAULT),/*Pin 9*/
         (PORT_PIN_DEFAULT),/*Pin 10*/
         (PORT_PIN_DEFAULT),/*Pin 11*/
         (PORT_PIN_DEFAULT),/*Pin 12*/
         (PORT_PIN_DEFAULT),/*Pin 13*/
         (PORT_PIN_DEFAULT),/*Pin 14*/
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    },
    {
      /* Port pins initial level configuration */
      {
         PORT_PIN_LOW,/* Pin 0 */ 
         PORT_PIN_LOW,/* Pin 1 */ 
         PORT_PIN_LOW,/* Pin 2 */ 
         PORT_PIN_LOW,/* Pin 3 */ 
         PORT_PIN_LOW,/* Pin 4 */ 
         PORT_PIN_LOW,/* Pin 5 */ 
         PORT_PIN_LOW,/* Pin 6 */ 
         PORT_PIN_LOW,/* Pin 7 */ 
         0U,/* Pin 8 */ 
         0U,/* Pin 9 */ 
         0U,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      }
    },      
    /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 0 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 1 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 2 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 3 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 4 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 5 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 6 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1) /* Pin 7 */ 
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 8 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 9 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 10 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 11 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 12 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 13 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 14 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT) /* Pin 15 */ 
                     ),
    {/* Port pin run time mode changeable or not configuration */
      {
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {/* Port pin run time direction changeable or not configuration */
      {
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {
      /* Port pins direction, characteristics and mode configuration if 
         direction is changeable */   
      {
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 0*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 1*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 2*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 3*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 4*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 5*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 6*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT2),/*Pin 7*/ 
         (PORT_PIN_DEFAULT),/*Pin 8*/ 
         (PORT_PIN_DEFAULT),/*Pin 9*/ 
         (PORT_PIN_DEFAULT),/*Pin 10*/ 
         (PORT_PIN_DEFAULT),/*Pin 11*/ 
         (PORT_PIN_DEFAULT),/*Pin 12*/ 
         (PORT_PIN_DEFAULT),/*Pin 13*/ 
         (PORT_PIN_DEFAULT),/*Pin 14*/ 
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    } 
   },
/*                              Port22                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      {
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT3),/*Pin 0*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 1*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT3),/*Pin 2*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT3),/*Pin 3*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 4*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT4),/*Pin 5*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 6*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 7*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT4),/*Pin 8*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 9*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 10*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT4),/*Pin 11*/
         (PORT_PIN_DEFAULT),/*Pin 12*/
         (PORT_PIN_DEFAULT),/*Pin 13*/
         (PORT_PIN_DEFAULT),/*Pin 14*/
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    },
    {
      /* Port pins initial level configuration */
      {
         PORT_PIN_LOW,/* Pin 0 */ 
         PORT_PIN_HIGH,/* Pin 1 */ 
         PORT_PIN_HIGH,/* Pin 2 */ 
         PORT_PIN_LOW,/* Pin 3 */ 
         PORT_PIN_LOW,/* Pin 4 */ 
         PORT_PIN_LOW,/* Pin 5 */ 
         PORT_PIN_LOW,/* Pin 6 */ 
         PORT_PIN_HIGH,/* Pin 7 */ 
         PORT_PIN_LOW,/* Pin 8 */ 
         PORT_PIN_LOW,/* Pin 9 */ 
         PORT_PIN_LOW,/* Pin 10 */ 
         PORT_PIN_HIGH,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      }
    },      
    /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 0 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 1 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 2 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 3 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 4 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 5 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 6 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1) /* Pin 7 */ 
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 8 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 9 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 10 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 11 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 12 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 13 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 14 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT) /* Pin 15 */ 
                     ),
    {/* Port pin run time mode changeable or not configuration */
      {
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_MODE_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_MODE_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {/* Port pin run time direction changeable or not configuration */
      {
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {
      /* Port pins direction, characteristics and mode configuration if 
         direction is changeable */   
      {
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT3),/*Pin 0*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 1*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT3),/*Pin 2*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT3),/*Pin 3*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 4*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT4),/*Pin 5*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 6*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 7*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT4),/*Pin 8*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 9*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 10*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT4),/*Pin 11*/ 
         (PORT_PIN_DEFAULT),/*Pin 12*/ 
         (PORT_PIN_DEFAULT),/*Pin 13*/ 
         (PORT_PIN_DEFAULT),/*Pin 14*/ 
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    } 
   },
/*                              Port23                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      {
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 0*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT4),/*Pin 1*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 2*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 3*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 4*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 5*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 6*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 7*/
         (PORT_PIN_DEFAULT),/*Pin 8*/
         (PORT_PIN_DEFAULT),/*Pin 9*/
         (PORT_PIN_DEFAULT),/*Pin 10*/
         (PORT_PIN_DEFAULT),/*Pin 11*/
         (PORT_PIN_DEFAULT),/*Pin 12*/
         (PORT_PIN_DEFAULT),/*Pin 13*/
         (PORT_PIN_DEFAULT),/*Pin 14*/
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    },
    {
      /* Port pins initial level configuration */
      {
         PORT_PIN_LOW,/* Pin 0 */ 
         PORT_PIN_LOW,/* Pin 1 */ 
         PORT_PIN_LOW,/* Pin 2 */ 
         PORT_PIN_HIGH,/* Pin 3 */ 
         PORT_PIN_LOW,/* Pin 4 */ 
         PORT_PIN_LOW,/* Pin 5 */ 
         PORT_PIN_LOW,/* Pin 6 */ 
         PORT_PIN_LOW,/* Pin 7 */ 
         0U,/* Pin 8 */ 
         0U,/* Pin 9 */ 
         0U,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      }
    },      
    /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 0 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 1 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 2 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 3 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 4 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 5 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 6 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4) /* Pin 7 */ 
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 8 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 9 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 10 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 11 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 12 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 13 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 14 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT) /* Pin 15 */ 
                     ),
    {/* Port pin run time mode changeable or not configuration */
      {
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_MODE_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {/* Port pin run time direction changeable or not configuration */
      {
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_DIR_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {
      /* Port pins direction, characteristics and mode configuration if 
         direction is changeable */   
      {
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 0*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT4),/*Pin 1*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 2*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 3*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 4*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 5*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 6*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 7*/ 
         (PORT_PIN_DEFAULT),/*Pin 8*/ 
         (PORT_PIN_DEFAULT),/*Pin 9*/ 
         (PORT_PIN_DEFAULT),/*Pin 10*/ 
         (PORT_PIN_DEFAULT),/*Pin 11*/ 
         (PORT_PIN_DEFAULT),/*Pin 12*/ 
         (PORT_PIN_DEFAULT),/*Pin 13*/ 
         (PORT_PIN_DEFAULT),/*Pin 14*/ 
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    } 
   },
/*                              Port32                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      {
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 0*/
         (PORT_PIN_DEFAULT),/*Pin 1*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 2*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT5),/*Pin 3*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 4*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT6),/*Pin 5*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 6*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 7*/
         (PORT_PIN_DEFAULT),/*Pin 8*/
         (PORT_PIN_DEFAULT),/*Pin 9*/
         (PORT_PIN_DEFAULT),/*Pin 10*/
         (PORT_PIN_DEFAULT),/*Pin 11*/
         (PORT_PIN_DEFAULT),/*Pin 12*/
         (PORT_PIN_DEFAULT),/*Pin 13*/
         (PORT_PIN_DEFAULT),/*Pin 14*/
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    },
    {
      /* Port pins initial level configuration */
      {
         PORT_PIN_LOW,/* Pin 0 */ 
         0U,/* Pin 1 */ 
         PORT_PIN_LOW,/* Pin 2 */ 
         PORT_PIN_LOW,/* Pin 3 */ 
         PORT_PIN_LOW,/* Pin 4 */ 
         PORT_PIN_LOW,/* Pin 5 */ 
         PORT_PIN_LOW,/* Pin 6 */ 
         PORT_PIN_LOW,/* Pin 7 */ 
         0U,/* Pin 8 */ 
         0U,/* Pin 9 */ 
         0U,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      }
    },      
    /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 0 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 1 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 2 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 3 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 4 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 5 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 6 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4) /* Pin 7 */ 
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 8 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 9 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 10 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 11 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 12 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 13 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 14 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT) /* Pin 15 */ 
                     ),
    {/* Port pin run time mode changeable or not configuration */
      {
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {/* Port pin run time direction changeable or not configuration */
      {
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {
      /* Port pins direction, characteristics and mode configuration if 
         direction is changeable */   
      {
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 0*/ 
         (PORT_PIN_DEFAULT),/*Pin 1*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 2*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT5),/*Pin 3*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 4*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT6),/*Pin 5*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 6*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 7*/ 
         (PORT_PIN_DEFAULT),/*Pin 8*/ 
         (PORT_PIN_DEFAULT),/*Pin 9*/ 
         (PORT_PIN_DEFAULT),/*Pin 10*/ 
         (PORT_PIN_DEFAULT),/*Pin 11*/ 
         (PORT_PIN_DEFAULT),/*Pin 12*/ 
         (PORT_PIN_DEFAULT),/*Pin 13*/ 
         (PORT_PIN_DEFAULT),/*Pin 14*/ 
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    } 
   },
/*                              Port33                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      {
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 0*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 1*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 2*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 3*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 4*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 5*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 6*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 7*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 8*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 9*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 10*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 11*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 12*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 13*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 14*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO) /*Pin 15*/ 
      }
    },
    {
      /* Port pins initial level configuration */
      {
         PORT_PIN_LOW,/* Pin 0 */ 
         PORT_PIN_LOW,/* Pin 1 */ 
         PORT_PIN_LOW,/* Pin 2 */ 
         PORT_PIN_LOW,/* Pin 3 */ 
         PORT_PIN_LOW,/* Pin 4 */ 
         PORT_PIN_LOW,/* Pin 5 */ 
         PORT_PIN_LOW,/* Pin 6 */ 
         PORT_PIN_LOW,/* Pin 7 */ 
         PORT_PIN_LOW,/* Pin 8 */ 
         PORT_PIN_LOW,/* Pin 9 */ 
         PORT_PIN_LOW,/* Pin 10 */ 
         PORT_PIN_LOW,/* Pin 11 */ 
         PORT_PIN_LOW,/* Pin 12 */ 
         PORT_PIN_LOW,/* Pin 13 */ 
         PORT_PIN_LOW,/* Pin 14 */ 
         PORT_PIN_LOW /* Pin 15 */ 
      }
    },      
    /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 0 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 1 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 2 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 3 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 4 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 5 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 6 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4) /* Pin 7 */ 
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 8 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 9 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 10 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 11 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 12 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4),/* Pin 13 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 14 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE4) /* Pin 15 */ 
                     ),
    {/* Port pin run time mode changeable or not configuration */
      {
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_MODE_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {/* Port pin run time direction changeable or not configuration */
      {
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {
      /* Port pins direction, characteristics and mode configuration if 
         direction is changeable */   
      {
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 0*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 1*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 2*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 3*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 4*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 5*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 6*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 7*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 8*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 9*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 10*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_ALT1),/*Pin 11*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 12*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 13*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 14*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO) /*Pin 15*/ 
      }
    } 
   },
/*                              Port34                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      {
         (PORT_PIN_DEFAULT),/*Pin 0*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 1*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 2*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 3*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 4*/
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 5*/
         (PORT_PIN_DEFAULT),/*Pin 6*/
         (PORT_PIN_DEFAULT),/*Pin 7*/
         (PORT_PIN_DEFAULT),/*Pin 8*/
         (PORT_PIN_DEFAULT),/*Pin 9*/
         (PORT_PIN_DEFAULT),/*Pin 10*/
         (PORT_PIN_DEFAULT),/*Pin 11*/
         (PORT_PIN_DEFAULT),/*Pin 12*/
         (PORT_PIN_DEFAULT),/*Pin 13*/
         (PORT_PIN_DEFAULT),/*Pin 14*/
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    },
    {
      /* Port pins initial level configuration */
      {
         0U,/* Pin 0 */ 
         PORT_PIN_LOW,/* Pin 1 */ 
         PORT_PIN_LOW,/* Pin 2 */ 
         PORT_PIN_LOW,/* Pin 3 */ 
         PORT_PIN_LOW,/* Pin 4 */ 
         PORT_PIN_LOW,/* Pin 5 */ 
         0U,/* Pin 6 */ 
         0U,/* Pin 7 */ 
         0U,/* Pin 8 */ 
         0U,/* Pin 9 */ 
         0U,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      }
    },      
    /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 0 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 1 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 2 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 3 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 4 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 5 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 6 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT) /* Pin 7 */ 
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 8 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 9 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 10 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 11 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 12 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 13 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 14 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT) /* Pin 15 */ 
                     ),
    {/* Port pin run time mode changeable or not configuration */
      {
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {/* Port pin run time direction changeable or not configuration */
      {
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {
      /* Port pins direction, characteristics and mode configuration if 
         direction is changeable */   
      {
         (PORT_PIN_DEFAULT),/*Pin 0*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 1*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 2*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 3*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 4*/ 
         ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 5*/ 
         (PORT_PIN_DEFAULT),/*Pin 6*/ 
         (PORT_PIN_DEFAULT),/*Pin 7*/ 
         (PORT_PIN_DEFAULT),/*Pin 8*/ 
         (PORT_PIN_DEFAULT),/*Pin 9*/ 
         (PORT_PIN_DEFAULT),/*Pin 10*/ 
         (PORT_PIN_DEFAULT),/*Pin 11*/ 
         (PORT_PIN_DEFAULT),/*Pin 12*/ 
         (PORT_PIN_DEFAULT),/*Pin 13*/ 
         (PORT_PIN_DEFAULT),/*Pin 14*/ 
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    } 
   },
/*                              Port40                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      {
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 0*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 1*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 2*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 3*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 4*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 5*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 6*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 7*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 8*/
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 9*/
         (PORT_PIN_DEFAULT),/*Pin 10*/
         (PORT_PIN_DEFAULT),/*Pin 11*/
         (PORT_PIN_DEFAULT),/*Pin 12*/
         (PORT_PIN_DEFAULT),/*Pin 13*/
         (PORT_PIN_DEFAULT),/*Pin 14*/
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    },
    {
      /* Port pins initial level configuration */
      {
         PORT_PIN_LOW,/* Pin 0 */ 
         PORT_PIN_LOW,/* Pin 1 */ 
         PORT_PIN_LOW,/* Pin 2 */ 
         PORT_PIN_LOW,/* Pin 3 */ 
         PORT_PIN_LOW,/* Pin 4 */ 
         PORT_PIN_LOW,/* Pin 5 */ 
         PORT_PIN_LOW,/* Pin 6 */ 
         PORT_PIN_LOW,/* Pin 7 */ 
         PORT_PIN_LOW,/* Pin 8 */ 
         PORT_PIN_LOW,/* Pin 9 */ 
         0U,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      }
    },      
    /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 0 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 1 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 2 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 3 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 4 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 5 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 6 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1) /* Pin 7 */ 
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 8 */ 
         (PORT_PDR_CMOS_AUTOMOTIVE_LEVEL | PORT_CMOS_SPEED_GRADE1),/* Pin 9 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 10 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 11 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 12 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 13 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT),/* Pin 14 */ 
         (PORT_PIN_PAD_LEVEL_DEFAULT) /* Pin 15 */ 
                     ),
    {/* Port pin run time mode changeable or not configuration */
      {
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_MODE_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {/* Port pin run time direction changeable or not configuration */
      {
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 0 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 1 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 2 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 3 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 4 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 5 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 6 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 7 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 8 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 9 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 10 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 11 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 12 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 13 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE,/* Pin 14 */ 
         PORT_PIN_DIR_NOT_CHANGEABLE /* Pin 15 */ 
      }
    },
    {
      /* Port pins direction, characteristics and mode configuration if 
         direction is changeable */   
      {
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 0*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 1*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 2*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 3*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 4*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 5*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 6*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 7*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 8*/ 
         ((uint8)PORT_PIN_IN | PORT_PIN_IN_NO_PULL | PORT_PIN_MODE_GPIO),/*Pin 9*/ 
         (PORT_PIN_DEFAULT),/*Pin 10*/ 
         (PORT_PIN_DEFAULT),/*Pin 11*/ 
         (PORT_PIN_DEFAULT),/*Pin 12*/ 
         (PORT_PIN_DEFAULT),/*Pin 13*/ 
         (PORT_PIN_DEFAULT),/*Pin 14*/ 
         (PORT_PIN_DEFAULT) /*Pin 15*/ 
      }
    } 
   }
};

static const uint16 Port_DiscSet0[] = 
{     
/*                              Port40                       */
   Port_lDiscSet(
                 PORT_PIN_ANALOG_INPUT_ENABLE,/* Pin 0 */ 
                 PORT_PIN_ANALOG_INPUT_ENABLE,/* Pin 1 */ 
                 PORT_PIN_ANALOG_INPUT_ENABLE,/* Pin 2 */ 
                 PORT_PIN_ANALOG_INPUT_ENABLE,/* Pin 3 */ 
                 PORT_PIN_ANALOG_INPUT_ENABLE,/* Pin 4 */ 
                 PORT_PIN_ANALOG_INPUT_ENABLE,/* Pin 5 */ 
                 PORT_PIN_ANALOG_INPUT_ENABLE,/* Pin 6 */ 
                 PORT_PIN_ANALOG_INPUT_ENABLE,/* Pin 7 */ 
                 PORT_PIN_ANALOG_INPUT_ENABLE,/* Pin 8 */ 
                 PORT_PIN_ANALOG_INPUT_ENABLE,/* Pin 9 */ 
                 PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 10 */ 
                 PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 11 */ 
                 PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 12 */ 
                 PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 13 */ 
                 PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 14 */ 
                 PORT_PIN_ANALOG_INPUT_DISABLE /* Pin 15 */ 
                )
};

/* LVDS configuration */
static const Port_n_LVDSConfigType Port_kLVDSConfig0[] = 
{

  { /*             Port13            */
    Port_lLvdsm(
                  Port_LVDS_PAD_SUPPLY_5_VOLT
                ),
    Port_lLvdsm(
                  Port_LVDS_PAD_SUPPLY_5_VOLT
                ),
                  PORT_LVDSM_DEFAULT
  },

  { /*             Port21            */
     Port_lLvdsh(
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_SPECIAL_REDUCED_LINK,
                  PORT_LVDS_HSCT_CONTROLLED,
                  PORT_LVDS_ENABLE,
                  PORT_LVDS_POWER_ON,
                  PORT_LVDS_POWDOWN_PULDOWN_EN
                 ),
     Port_lLvdsh(
                  PORT_LVDS_PORT_CONTROLLED,
                  PORT_LVDS_DISABLE,
                  PORT_LVDS_INTERNAML_TERMINATION,
                  PORT_LVDS_POLY_RESISTOR_TERM,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT
                 ),
     Port_lLvdsh(
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_IEEE_GEN_PURPOSE_LINK,
                  PORT_LVDS_PORT_CONTROLLED,
                  PORT_LVDS_DISABLE,
                  PORT_LVDS_POWER_DOWN,
                  PORT_LVDS_POWDOWN_PULDOWN_DIS
                 )
  },

  { /*             Port22            */
    Port_lLvdsm(
                  Port_LVDS_PAD_SUPPLY_5_VOLT
                ),
    Port_lLvdsm(
                  Port_LVDS_PAD_SUPPLY_5_VOLT
                ),
                  PORT_LVDSM_DEFAULT
  }
};

/* PCSR configuration */
static const Port_n_PCSRConfigType Port_kPCSRConfig0[] = 
{

               /*           Port0            */
   Port_lPcsr(
               PORT_PCSR_DEFAULT,  /*Pin0*/
               PORT_PCSR_DEFAULT,  /*Pin1*/
               PORT_PCSR_DEFAULT,  /*Pin2*/
               PORT_PCSR_DEFAULT,  /*Pin3*/
               PORT_PCSR_DISABLE,  /*Pin4*/
               PORT_PCSR_DISABLE,  /*Pin5*/
               PORT_PCSR_DEFAULT,  /*Pin6*/
               PORT_PCSR_DEFAULT,  /*Pin7*/
               PORT_PCSR_DEFAULT,  /*Pin8*/
               PORT_PCSR_DEFAULT,  /*Pin9*/
               PORT_PCSR_DISABLE,  /*Pin10*/
               PORT_PCSR_DISABLE,  /*Pin11*/
               PORT_PCSR_DEFAULT,  /*Pin12*/
               PORT_PCSR_DEFAULT,  /*Pin13*/
               PORT_PCSR_DEFAULT,  /*Pin14*/
               PORT_PCSR_DEFAULT   /*Pin15*/
              ),

               /*           Port11            */
   Port_lPcsr(
               PORT_PCSR_DEFAULT,  /*Pin0*/
               PORT_PCSR_DEFAULT,  /*Pin1*/
               PORT_PCSR_DISABLE,  /*Pin2*/
               PORT_PCSR_DISABLE,  /*Pin3*/
               PORT_PCSR_DEFAULT,  /*Pin4*/
               PORT_PCSR_DEFAULT,  /*Pin5*/
               PORT_PCSR_DISABLE,  /*Pin6*/
               PORT_PCSR_DEFAULT,  /*Pin7*/
               PORT_PCSR_DEFAULT,  /*Pin8*/
               PORT_PCSR_DEFAULT,  /*Pin9*/
               PORT_PCSR_DEFAULT,  /*Pin10*/
               PORT_PCSR_DEFAULT,  /*Pin11*/
               PORT_PCSR_DEFAULT,  /*Pin12*/
               PORT_PCSR_DEFAULT,  /*Pin13*/
               PORT_PCSR_DEFAULT,  /*Pin14*/
               PORT_PCSR_DEFAULT   /*Pin15*/
              ),

               /*           Port40            */
   Port_lPcsr(
               PORT_PCSR_DEFAULT,  /*Pin0*/
               PORT_PCSR_DISABLE,  /*Pin1*/
               PORT_PCSR_DISABLE,  /*Pin2*/
               PORT_PCSR_DISABLE,  /*Pin3*/
               PORT_PCSR_DEFAULT,  /*Pin4*/
               PORT_PCSR_DISABLE,  /*Pin5*/
               PORT_PCSR_DEFAULT,  /*Pin6*/
               PORT_PCSR_DEFAULT,  /*Pin7*/
               PORT_PCSR_DEFAULT,  /*Pin8*/
               PORT_PCSR_DEFAULT,  /*Pin9*/
               PORT_PCSR_DEFAULT,  /*Pin10*/
               PORT_PCSR_DEFAULT,  /*Pin11*/
               PORT_PCSR_DEFAULT,  /*Pin12*/
               PORT_PCSR_DEFAULT,  /*Pin13*/
               PORT_PCSR_DEFAULT,  /*Pin14*/
               PORT_PCSR_DEFAULT   /*Pin15*/
              )
};


/*
   Array contains information on the modes supported by each port pin
*/
static const Port_n_ModeType Port_kPinSupportedModes0[] = 
{
/*     Port0      */
  {
    {     
      (uint8)(0x03U),/*Pin0*/
      (uint8)(0xf7U),/*Pin1*/
      (uint8)(0xffU),/*Pin2*/
      (uint8)(0xd7U),/*Pin3*/
      (uint8)(0x03U),/*Pin4*/
      (uint8)(0xffU),/*Pin5*/
      (uint8)(0x03U),/*Pin6*/
      (uint8)(0x03U),/*Pin7*/
      (uint8)(0xe7U),/*Pin8*/
      (uint8)(0xdfU),/*Pin9*/
      (uint8)(0xc3U),/*Pin10*/
      (uint8)(0x13U),/*Pin11*/
      (uint8)(0x83U),/*Pin12*/
      (uint8)(0x00U),/*Pin13*/
      (uint8)(0x00U),/*Pin14*/
      (uint8)(0x00U) /*Pin15*/
    }
  },
/*     Port1      */
  {
    {     
      (uint8)(0x00U),/*Pin0*/
      (uint8)(0x00U),/*Pin1*/
      (uint8)(0x00U),/*Pin2*/
      (uint8)(0x33U),/*Pin3*/
      (uint8)(0x13U),/*Pin4*/
      (uint8)(0x53U),/*Pin5*/
      (uint8)(0x13U),/*Pin6*/
      (uint8)(0x13U),/*Pin7*/
      (uint8)(0x00U),/*Pin8*/
      (uint8)(0x00U),/*Pin9*/
      (uint8)(0x00U),/*Pin10*/
      (uint8)(0x00U),/*Pin11*/
      (uint8)(0x00U),/*Pin12*/
      (uint8)(0x00U),/*Pin13*/
      (uint8)(0x00U),/*Pin14*/
      (uint8)(0x00U) /*Pin15*/
    }
  },
/*     Port2      */
  {
    {     
      (uint8)(0xffU),/*Pin0*/
      (uint8)(0x9fU),/*Pin1*/
      (uint8)(0x03U),/*Pin2*/
      (uint8)(0x03U),/*Pin3*/
      (uint8)(0xffU),/*Pin4*/
      (uint8)(0xffU),/*Pin5*/
      (uint8)(0xbfU),/*Pin6*/
      (uint8)(0x03U),/*Pin7*/
      (uint8)(0xf7U),/*Pin8*/
      (uint8)(0x27U),/*Pin9*/
      (uint8)(0x03U),/*Pin10*/
      (uint8)(0x03U),/*Pin11*/
      (uint8)(0x00U),/*Pin12*/
      (uint8)(0x00U),/*Pin13*/
      (uint8)(0x00U),/*Pin14*/
      (uint8)(0x00U) /*Pin15*/
    }
  },
/*     Port10      */
  {
    {     
      (uint8)(0x2bU),/*Pin0*/
      (uint8)(0x03U),/*Pin1*/
      (uint8)(0x7bU),/*Pin2*/
      (uint8)(0x7fU),/*Pin3*/
      (uint8)(0x7bU),/*Pin4*/
      (uint8)(0xffU),/*Pin5*/
      (uint8)(0xffU),/*Pin6*/
      (uint8)(0x3bU),/*Pin7*/
      (uint8)(0x0fU),/*Pin8*/
      (uint8)(0x00U),/*Pin9*/
      (uint8)(0x00U),/*Pin10*/
      (uint8)(0x00U),/*Pin11*/
      (uint8)(0x00U),/*Pin12*/
      (uint8)(0x00U),/*Pin13*/
      (uint8)(0x00U),/*Pin14*/
      (uint8)(0x00U) /*Pin15*/
    }
  },
/*     Port11      */
  {
    {     
      (uint8)(0x47U),/*Pin0*/
      (uint8)(0x4fU),/*Pin1*/
      (uint8)(0xffU),/*Pin2*/
      (uint8)(0xdbU),/*Pin3*/
      (uint8)(0x03U),/*Pin4*/
      (uint8)(0x03U),/*Pin5*/
      (uint8)(0xffU),/*Pin6*/
      (uint8)(0x03U),/*Pin7*/
      (uint8)(0x03U),/*Pin8*/
      (uint8)(0xabU),/*Pin9*/
      (uint8)(0x9bU),/*Pin10*/
      (uint8)(0xffU),/*Pin11*/
      (uint8)(0xffU),/*Pin12*/
      (uint8)(0x03U),/*Pin13*/
      (uint8)(0x03U),/*Pin14*/
      (uint8)(0x03U) /*Pin15*/
    }
  },
/*     Port12      */
  {
    {     
      (uint8)(0x43U),/*Pin0*/
      (uint8)(0x27U),/*Pin1*/
      (uint8)(0x00U),/*Pin2*/
      (uint8)(0x00U),/*Pin3*/
      (uint8)(0x00U),/*Pin4*/
      (uint8)(0x00U),/*Pin5*/
      (uint8)(0x00U),/*Pin6*/
      (uint8)(0x00U),/*Pin7*/
      (uint8)(0x00U),/*Pin8*/
      (uint8)(0x00U),/*Pin9*/
      (uint8)(0x00U),/*Pin10*/
      (uint8)(0x00U),/*Pin11*/
      (uint8)(0x00U),/*Pin12*/
      (uint8)(0x00U),/*Pin13*/
      (uint8)(0x00U),/*Pin14*/
      (uint8)(0x00U) /*Pin15*/
    }
  },
/*     Port13      */
  {
    {     
      (uint8)(0x7fU),/*Pin0*/
      (uint8)(0x6bU),/*Pin1*/
      (uint8)(0xfbU),/*Pin2*/
      (uint8)(0x2bU),/*Pin3*/
      (uint8)(0x00U),/*Pin4*/
      (uint8)(0x00U),/*Pin5*/
      (uint8)(0x00U),/*Pin6*/
      (uint8)(0x00U),/*Pin7*/
      (uint8)(0x00U),/*Pin8*/
      (uint8)(0x00U),/*Pin9*/
      (uint8)(0x00U),/*Pin10*/
      (uint8)(0x00U),/*Pin11*/
      (uint8)(0x00U),/*Pin12*/
      (uint8)(0x00U),/*Pin13*/
      (uint8)(0x00U),/*Pin14*/
      (uint8)(0x00U) /*Pin15*/
    }
  },
/*     Port14      */
  {
    {     
      (uint8)(0xffU),/*Pin0*/
      (uint8)(0x87U),/*Pin1*/
      (uint8)(0x4fU),/*Pin2*/
      (uint8)(0x3fU),/*Pin3*/
      (uint8)(0x03U),/*Pin4*/
      (uint8)(0xc3U),/*Pin5*/
      (uint8)(0xcbU),/*Pin6*/
      (uint8)(0x0fU),/*Pin7*/
      (uint8)(0x03U),/*Pin8*/
      (uint8)(0xefU),/*Pin9*/
      (uint8)(0xffU),/*Pin10*/
      (uint8)(0x00U),/*Pin11*/
      (uint8)(0x00U),/*Pin12*/
      (uint8)(0x00U),/*Pin13*/
      (uint8)(0x00U),/*Pin14*/
      (uint8)(0x00U) /*Pin15*/
    }
  },
/*     Port15      */
  {
    {     
      (uint8)(0x6fU),/*Pin0*/
      (uint8)(0x0fU),/*Pin1*/
      (uint8)(0x6fU),/*Pin2*/
      (uint8)(0x3fU),/*Pin3*/
      (uint8)(0xcfU),/*Pin4*/
      (uint8)(0xffU),/*Pin5*/
      (uint8)(0xffU),/*Pin6*/
      (uint8)(0x8fU),/*Pin7*/
      (uint8)(0xcbU),/*Pin8*/
      (uint8)(0x00U),/*Pin9*/
      (uint8)(0x00U),/*Pin10*/
      (uint8)(0x00U),/*Pin11*/
      (uint8)(0x00U),/*Pin12*/
      (uint8)(0x00U),/*Pin13*/
      (uint8)(0x00U),/*Pin14*/
      (uint8)(0x00U) /*Pin15*/
    }
  },
/*     Port20      */
  {
    {     
      (uint8)(0x2fU),/*Pin0*/
      (uint8)(0x03U),/*Pin1*/
      (uint8)(0x01U),/*Pin2*/
      (uint8)(0x7fU),/*Pin3*/
      (uint8)(0x00U),/*Pin4*/
      (uint8)(0x00U),/*Pin5*/
      (uint8)(0x5fU),/*Pin6*/
      (uint8)(0xc3U),/*Pin7*/
      (uint8)(0xffU),/*Pin8*/
      (uint8)(0xdbU),/*Pin9*/
      (uint8)(0xffU),/*Pin10*/
      (uint8)(0x8bU),/*Pin11*/
      (uint8)(0x9bU),/*Pin12*/
      (uint8)(0xbbU),/*Pin13*/
      (uint8)(0x03U),/*Pin14*/
      (uint8)(0x00U) /*Pin15*/
    }
  },
/*     Port21      */
  {
    {     
      (uint8)(0xc3U),/*Pin0*/
      (uint8)(0xc3U),/*Pin1*/
      (uint8)(0x67U),/*Pin2*/
      (uint8)(0x43U),/*Pin3*/
      (uint8)(0x43U),/*Pin4*/
      (uint8)(0x47U),/*Pin5*/
      (uint8)(0xe7U),/*Pin6*/
      (uint8)(0xcfU),/*Pin7*/
      (uint8)(0x00U),/*Pin8*/
      (uint8)(0x00U),/*Pin9*/
      (uint8)(0x00U),/*Pin10*/
      (uint8)(0x00U),/*Pin11*/
      (uint8)(0x00U),/*Pin12*/
      (uint8)(0x00U),/*Pin13*/
      (uint8)(0x00U),/*Pin14*/
      (uint8)(0x00U) /*Pin15*/
    }
  },
/*     Port22      */
  {
    {     
      (uint8)(0x7fU),/*Pin0*/
      (uint8)(0x3fU),/*Pin1*/
      (uint8)(0x7bU),/*Pin2*/
      (uint8)(0x3bU),/*Pin3*/
      (uint8)(0x33U),/*Pin4*/
      (uint8)(0x13U),/*Pin5*/
      (uint8)(0x13U),/*Pin6*/
      (uint8)(0x13U),/*Pin7*/
      (uint8)(0x13U),/*Pin8*/
      (uint8)(0x03U),/*Pin9*/
      (uint8)(0x03U),/*Pin10*/
      (uint8)(0x13U),/*Pin11*/
      (uint8)(0x00U),/*Pin12*/
      (uint8)(0x00U),/*Pin13*/
      (uint8)(0x00U),/*Pin14*/
      (uint8)(0x00U) /*Pin15*/
    }
  },
/*     Port23      */
  {
    {     
      (uint8)(0x03U),/*Pin0*/
      (uint8)(0x5fU),/*Pin1*/
      (uint8)(0x03U),/*Pin2*/
      (uint8)(0x03U),/*Pin3*/
      (uint8)(0x3bU),/*Pin4*/
      (uint8)(0x3bU),/*Pin5*/
      (uint8)(0x13U),/*Pin6*/
      (uint8)(0x03U),/*Pin7*/
      (uint8)(0x00U),/*Pin8*/
      (uint8)(0x00U),/*Pin9*/
      (uint8)(0x00U),/*Pin10*/
      (uint8)(0x00U),/*Pin11*/
      (uint8)(0x00U),/*Pin12*/
      (uint8)(0x00U),/*Pin13*/
      (uint8)(0x00U),/*Pin14*/
      (uint8)(0x00U) /*Pin15*/
    }
  },
/*     Port32      */
  {
    {     
      (uint8)(0x03U),/*Pin0*/
      (uint8)(0x00U),/*Pin1*/
      (uint8)(0x47U),/*Pin2*/
      (uint8)(0x77U),/*Pin3*/
      (uint8)(0xfbU),/*Pin4*/
      (uint8)(0x47U),/*Pin5*/
      (uint8)(0x13U),/*Pin6*/
      (uint8)(0x03U),/*Pin7*/
      (uint8)(0x00U),/*Pin8*/
      (uint8)(0x00U),/*Pin9*/
      (uint8)(0x00U),/*Pin10*/
      (uint8)(0x00U),/*Pin11*/
      (uint8)(0x00U),/*Pin12*/
      (uint8)(0x00U),/*Pin13*/
      (uint8)(0x00U),/*Pin14*/
      (uint8)(0x00U) /*Pin15*/
    }
  },
/*     Port33      */
  {
    {     
      (uint8)(0x43U),/*Pin0*/
      (uint8)(0x7fU),/*Pin1*/
      (uint8)(0x7fU),/*Pin2*/
      (uint8)(0x73U),/*Pin3*/
      (uint8)(0x7fU),/*Pin4*/
      (uint8)(0x7fU),/*Pin5*/
      (uint8)(0xffU),/*Pin6*/
      (uint8)(0x4fU),/*Pin7*/
      (uint8)(0xafU),/*Pin8*/
      (uint8)(0x9fU),/*Pin9*/
      (uint8)(0xbfU),/*Pin10*/
      (uint8)(0x03U),/*Pin11*/
      (uint8)(0xdfU),/*Pin12*/
      (uint8)(0xdfU),/*Pin13*/
      (uint8)(0x8bU),/*Pin14*/
      (uint8)(0x8bU) /*Pin15*/
    }
  },
/*     Port34      */
  {
    {     
      (uint8)(0x00U),/*Pin0*/
      (uint8)(0xb7U),/*Pin1*/
      (uint8)(0x83U),/*Pin2*/
      (uint8)(0x93U),/*Pin3*/
      (uint8)(0x93U),/*Pin4*/
      (uint8)(0x93U),/*Pin5*/
      (uint8)(0x00U),/*Pin6*/
      (uint8)(0x00U),/*Pin7*/
      (uint8)(0x00U),/*Pin8*/
      (uint8)(0x00U),/*Pin9*/
      (uint8)(0x00U),/*Pin10*/
      (uint8)(0x00U),/*Pin11*/
      (uint8)(0x00U),/*Pin12*/
      (uint8)(0x00U),/*Pin13*/
      (uint8)(0x00U),/*Pin14*/
      (uint8)(0x00U) /*Pin15*/
    }
  },
/*     Port40      */
  {
    {     
      (uint8)(0x01U),/*Pin0*/
      (uint8)(0x01U),/*Pin1*/
      (uint8)(0x01U),/*Pin2*/
      (uint8)(0x01U),/*Pin3*/
      (uint8)(0x01U),/*Pin4*/
      (uint8)(0x01U),/*Pin5*/
      (uint8)(0x01U),/*Pin6*/
      (uint8)(0x01U),/*Pin7*/
      (uint8)(0x01U),/*Pin8*/
      (uint8)(0x01U),/*Pin9*/
      (uint8)(0x00U),/*Pin10*/
      (uint8)(0x00U),/*Pin11*/
      (uint8)(0x00U),/*Pin12*/
      (uint8)(0x00U),/*Pin13*/
      (uint8)(0x00U),/*Pin14*/
      (uint8)(0x00U) /*Pin15*/
    }
  }
};




const Port_ConfigType Port_ConfigRoot[1] =
{

  {
        /* Port Configuration set 0 */
    &Port_kConfiguration0[0],
    /* Port 40-th Disc configuration set 0 */
    &Port_DiscSet0[0],
    &Port_kPinSupportedModes0[0],

    /* LVDS configuration */
    &Port_kLVDSConfig0[0],
    /* PCSR Configuration */
    &Port_kPCSRConfig0[0]
  }
};

#define PORT_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/


