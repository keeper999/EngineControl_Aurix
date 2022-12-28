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
**  $FILENAME   : Port.h $                                                   **
**                                                                            **
**  $CC VERSION : \main\41 $                                                 **
**                                                                            **
**  $DATE       : 2014-01-10 $                                               **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - functionality of Port driver.                            **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/
/* Traceability : [cover parentID=DS_AS_PORT129,
                  DS_AS_PORT051,DS_AS_PORT116,DS_AS40X_PORT001_PI,
                  DS_NAS_PORT_PR912_2,DS_AS_PORT072_1,DS_AS_PORT072_2,
                  DS_AS_PORT072_3,DS_AS_PORT072_4,DS_AS_PORT072_5,
                  DS_AS_PORT072_6,DS_AS_PORT072_7,DS_AS_PORT072_8,
                  DS_AS_PORT072_9,DS_AS_PORTConfigType,DS_AS_PORT073,
                  DS_AS_PORTPinType,DS_AS_PORT219,DS_AS_PORT013,
                  DS_AS_PORTPinDirectionType,DS_AS_PORT220,DS_AS_PORT046,
                  DS_AS_PORTPinModeType,DS_AS_PORT221,
                  DS_AS_PORT124,DS_AS_PORT212,DS_NAS_PORT_PR746]
                  [/cover]                                                    */

#ifndef PORT_H
#define PORT_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* PORT080: Inclusion structure */

/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"

/* Pre-compile/static configuration parameters for PORT  */
#include "Port_Cfg.h"

/* Global functions like Set/Reset END INIT protection bit, 
  Enable/Disable interrupts, Automic write function */
#include "Mcal.h"

/* Conditional Inclusion of Developement Error Tracer File */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */

/*******************************************************************************
**                      Global Macro Definitions                              **
*****************************************1*************************************/

/*
  PORT106: Published parameters
*/
/* PORT Vendor ID */
#define PORT_VENDOR_ID                     (17U)  
/* PORT Module ID */
#define PORT_MODULE_ID                     (124U)

/*
  PORT100: PORT101: Development error codes
*/
#if ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))

/* PORT116, PORT051 */
/* Service is called with invalid parameter Pin */
#define PORT_E_PARAM_PIN                ((uint8)0x0A)

/* Service is called for a Pin that is configured as direction 
   not changeable during runtime */
#define PORT_E_DIRECTION_UNCHANGEABLE   ((uint8)0x0B)

/* Init Service is called with NULL configuration pointer */
#define PORT_E_PARAM_CONFIG             ((uint8)0x0C)

/* Service is called for Pin with invalid mode */
#define PORT_E_PARAM_INVALID_MODE       ((uint8)0x0D)

/* Service is called for a Pin that is configured as mode 
   not changeable during runtime */
#define PORT_E_MODE_UNCHANGEABLE        ((uint8)0x0E)

/* Service is called before Port_Init (Vendor Specific) */
#define PORT_E_UNINIT                   ((uint8)0x0F)

/* Service is called with NULL_PTR */
#define PORT_E_PARAM_POINTER            ((uint8)0x10)

/* Report a safety error */
#if (PORT_SAFETY_ENABLE == STD_ON)
/* Service is called with invalid parameter Direction  */
#define PORT_E_PARAM_DIRECTION           ((uint8)0x11)
#endif


/* PORT038: no microcontroller specific development errors for PORT driver */


/* PORT037: no production errors for PORT driver */


/*
  Service ID number for all PORT driver services 
*/
/* Service ID for Port_Init */
#define PORT_SID_INIT                   ((uint8)0)
/* Service ID for Port_SetPinDirection */
#define PORT_SID_SETPINDIRECTION        ((uint8)1)
/* Service ID for Port_RefreshPortDirection */
#define PORT_SID_REFRESHPORTDIR         ((uint8)2)
/* Service ID for Port_GetVersionInfo */
#define PORT_SID_GETVERSIONINFO         ((uint8)3)
/* Service ID for Port_SetPinMode */
#define PORT_SID_SETPINMODE             ((uint8)4)

#endif /* PORT_DEV_ERROR_DETECT */

/* PORT MODULE INSTANCE ID */
#define PORT_INSTANCE_ID                ((uint8)0)
/*
  Macros required for configuring the PORT driver
*/

/* 
  Position of the bit field Pn_IOCR.PC
*/
#define PORT_IOCR_PC_POS                (3U)

/* 
  Macros to define pin mode i.e. pin functionality
  These are used internally to define other macros
*/
#define  PORT_PIN_MODE_GPIO             (0x00U)
#define  PORT_PIN_MODE_ALT1             (0x08U)
#define  PORT_PIN_MODE_ALT2             (0x10U)
#define  PORT_PIN_MODE_ALT3             (0x18U)
#define  PORT_PIN_MODE_ALT4             (0x20U)
#define  PORT_PIN_MODE_ALT5             (0x28U)
#define  PORT_PIN_MODE_ALT6             (0x30U)
#define  PORT_PIN_MODE_ALT7             (0x38U)

/* Macros to define whether pin direction can be changed
   during runtime or not */
#define  PORT_PIN_DIR_NOT_CHANGEABLE    (0x00U)
#define  PORT_PIN_DIR_CHANGEABLE        (0x01U)

/* Macros to define whether pin mode can be changed 
   during runtime or not */
#define  PORT_PIN_MODE_NOT_CHANGEABLE   (0x00U)
#define  PORT_PIN_MODE_CHANGEABLE       (0x01U)

#define PORT_LVDSH_DEFAULT              (0xFFFF0000U)
#define PORT_LVDSM_DEFAULT              (0xFFFF0000U)

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/* Type definition for numeric id for port pins */
typedef uint32 Port_PinType;

/* Type definition for port pin direction */
typedef enum
{
  PORT_PIN_IN = 0x00U,
  PORT_PIN_OUT = 0x80U
}Port_PinDirectionType;

/* Type definition for Port pin mode */
typedef uint32 Port_PinModeType;

/* PORT082: Level inversion is not supported by the driver as per requirement */

/* Union definition for PORT n pins, Pn_IN and Pn_OUT registers */
typedef union Port_n_PinType
{
  struct
  {
    unsigned_int P0        : 1;    /* Pin 0  */
    unsigned_int P1        : 1;    /* Pin 1  */
    unsigned_int P2        : 1;    /* Pin 2  */
    unsigned_int P3        : 1;    /* Pin 3  */
    unsigned_int P4        : 1;    /* Pin 4  */
    unsigned_int P5        : 1;    /* Pin 5  */
    unsigned_int P6        : 1;    /* Pin 6  */
    unsigned_int P7        : 1;    /* Pin 7  */
    unsigned_int P8        : 1;    /* Pin 8  */
    unsigned_int P9        : 1;    /* Pin 9  */
    unsigned_int P10       : 1;    /* Pin 10 */
    unsigned_int P11       : 1;    /* Pin 11 */
    unsigned_int P12       : 1;    /* Pin 12 */
    unsigned_int P13       : 1;    /* Pin 13 */
    unsigned_int P14       : 1;    /* Pin 14 */
    unsigned_int P15       : 1;    /* Pin 15 */
  } B;

  uint32 U;

} Port_n_PinType;

/* Union definition for PORT n input output control register Pn_IOCRx */
typedef union Port_n_ControlType
{
  struct
  {
    uint8 PC0;      /* Pin 0  control */
    uint8 PC1;      /* Pin 1  control */
    uint8 PC2;      /* Pin 2  control */
    uint8 PC3;      /* Pin 3  control */
    uint8 PC4;      /* Pin 4  control */
    uint8 PC5;      /* Pin 5  control */
    uint8 PC6;      /* Pin 6  control */
    uint8 PC7;      /* Pin 7  control */
    uint8 PC8;      /* Pin 8  control */
    uint8 PC9;      /* Pin 9  control */
    uint8 PC10;     /* Pin 10 control */
    uint8 PC11;     /* Pin 11 control */
    uint8 PC12;     /* Pin 12 control */
    uint8 PC13;     /* Pin 13 control */
    uint8 PC14;     /* Pin 14 control */
    uint8 PC15;     /* Pin 15 control */
  }B;

  uint32 U[4];

}Port_n_ControlType;

/* Type definition for port pin Hardware Supported Mode structure
*/
typedef union Port_n_ModeType
{
  struct
  {
    uint8 P0;     /* Pin 0  */
    uint8 P1;     /* Pin 1  */
    uint8 P2;     /* Pin 2  */
    uint8 P3;     /* Pin 3  */
    uint8 P4;     /* Pin 4  */
    uint8 P5;     /* Pin 5  */
    uint8 P6;     /* Pin 6  */
    uint8 P7;     /* Pin 7  */
    uint8 P8;     /* Pin 8  */
    uint8 P9;     /* Pin 9  */
    uint8 P10;    /* Pin 10 */
    uint8 P11;    /* Pin 11 */
    uint8 P12;    /* Pin 12 */
    uint8 P13;    /* Pin 13 */
    uint8 P14;    /* Pin 14 */
    uint8 P15;    /* Pin 15 */
  } B;
  uint8 U[PORT_MAX_NUM];
}Port_n_ModeType;

/*
  PORT004: PORT079: PORT081: Structure definition for PORT n
  configuration
*/
typedef struct Port_n_ConfigType
{
  /* Port pins mode, direction and characteristics configuration */
  Port_n_ControlType  PinControl;
  /* Port pins initial level configuration */
  Port_n_PinType      PinLevel;
  /* Port pins drive strength configuration */
  uint32              DriverStrength0;  
  /* Port pins drive strength configuration */
  uint32              DriverStrength1;     
  /* If Mode changeable is enabled */
  #if (PORT_SET_PIN_MODE_API == STD_ON)
  /* Port pin run time mode changeable or not configuration */
  Port_n_PinType      ModeChangeControl;
  #endif /* PORT_SET_PIN_MODE_API */ 
  /* If Direction changeable is enabled */
  #if (PORT_SET_PIN_DIRECTION_API == STD_ON)
  /* Port pin run time direction changeable or not configuration */
  Port_n_PinType      DirChangeControl;
  /* Port pins mode, and characteristics configuration if 
     direction is changeable */
  Port_n_ControlType  PinControl2;
  #endif /* PORT_SET_PIN_DIRECTION_API */ 

}Port_n_ConfigType;

/* LVDS config type */
typedef struct Port_n_LVDSConfigType
{
  uint32 LPCR0; /* for Pinpair 0,1   */
  #if(PORT_MAX_LPCR_REG > 1)
  uint32 LPCR1; /* for Pinpair 2,3   */
  #endif
  #if(PORT_MAX_LPCR_REG > 2)
  uint32 LPCR2; /* for Pinpair 4,5   */
  #endif
  #if(PORT_MAX_LPCR_REG > 3)
  uint32 LPCR3; /* for Pinpair 6,7   */
  #endif
  #if(PORT_MAX_LPCR_REG > 4)
  uint32 LPCR4; /* for Pinpair 8,9   */
  #endif
  #if(PORT_MAX_LPCR_REG > 5)
  uint32 LPCR5; /* for Pinpair 10,11 */
  #endif
  #if(PORT_MAX_LPCR_REG > 6)
  uint32 LPCR6; /* for Pinpair 12,13 */
  #endif
  #if(PORT_MAX_LPCR_REG > 7)
  uint32 LPCR7; /* for Pinpair 14,15 */
  #endif
}Port_n_LVDSConfigType;

/* PCSR config type */
typedef uint32 Port_n_PCSRConfigType;

/* 
  PORT004: PORT005: PORT073: Structure definition for PORT driver
  configuration
*/
/* PORT005: All the ports and port pins must be configured even if they are not
            used */

typedef struct Port_ConfigType
{
  /* Port Marker used for checking configuration */
  #if (PORT_SAFETY_ENABLE == STD_ON)
  uint32 PortMarker;
  #endif
  /* Pointer to PORT SET configuration */
  const Port_n_ConfigType* PortConfigSetPtr;
  /* Pointer to PORT 40-th Disc configuration */
  const uint16* PDiscSet;
  #if (PORT_SET_PIN_MODE_API == STD_ON) 
  #if ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))
  /* Port pin Hardware supported modes configuration */
  const Port_n_ModeType *PortPinHwSupportedModes;
  #endif /*(PORT_SET_PIN_MODE_API==STD_ON) */
  #endif 
  /* ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))*/
  /* Configuration data for LVDS */
  const Port_n_LVDSConfigType* Port_LVDSConfigTypePtr;
  const Port_n_PCSRConfigType* Port_PCSRConfigTypePtr;
}Port_ConfigType;

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

#define PORT_START_SEC_POSTBUILDCFG
#include "MemMap.h"

/* Declaration of Port Post Build Configuration */
extern const struct Port_ConfigType Port_ConfigRoot[];

#define PORT_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

#define PORT_START_SEC_CODE
/*mapping of code and data to specific memory sections via memory mapping file*/
#include "MemMap.h"

/*******************************************************************************
** Traceability     : [cover parentID=DS_AS_PORT140,DS_AS_PORT003,
                       DS_AS_PORT101_PORT211_1,DS_AS_PORT107_PORT146_1,
                       DS_AS_PORT087_1,DS_AS_PORT105,DS_AS_PORT148,
                       DS_AS_PORT005,DS_AS_PORT077,DS_AS_PORT082]             **
**                                                                            **
** Syntax           : void Port_Init                                          **
**                    (                                                       **
**                      const Port_ConfigType * ConfigPtr                     **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x00                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ConfigPtr - Pointer to PORT configuration               **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - PORT041: PORT042: Initializes all the ports as per configuration       **
**   - PORT001: This API initializes the whole port structure of MCU          **
**   - PORT003: This API can be used to initialize and reinitialize the       **
**     port with different configuration                                      **
**   - PORT078: This function should be called first in order to initialize   **
**     the port for use                                                       **
**                                                                            **
*******************************************************************************/
extern void Port_Init 
( 
  const Port_ConfigType * ConfigPtr 
);



#if (PORT_INIT_CHECK_API == STD_ON)
/*******************************************************************************
** Syntax           : Std_ReturnType Port_InitCheck                           **
**                    (                                                       **
**                      const Port_ConfigType * ConfigPtr                     **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x00                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ConfigPtr - Pointer to PORT configuration               **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function checks Port SFR's and Global              **
**                      variables initialized by Port_Init Api                **
**                    This API is available only if PortInitCheckApi is TRUE  **
*******************************************************************************/
extern Std_ReturnType Port_InitCheck 
( 
  const Port_ConfigType * ConfigPtr 
);
#endif



/* Enable / Disable the use of the function */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/*******************************************************************************
** Syntax           : void Port_SetPinDirection                               **
**                    (                                                       **
**                      Port_PinType Pin,                                     **
**                      Port_PinDirectionType Direction                       **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x01                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                    (This function shall be re-entrant if accessing         **
**                     different pins, independent of port.)                  **
**                                                                            **
** Parameters (in)  : Pin - port pin ID whose direction has to be set         **
**                    Direction - port pin direction to be set                **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**  - PORT063: sets the port pin direction during runtime                     **
**  - PORT059: This functionality is available for parameter Pin              **
**     whose direction is configured as changeable during run time            **
**  - PORT086: This function is only available if the pre-compiler switch     **
**    PORT_PIN_DIRECTION_CHANGES_ALLOWED is set ON.                           **
*******************************************************************************/
extern void Port_SetPinDirection 
(
  Port_PinType Pin,
  Port_PinDirectionType Direction
);
#else

#define Port_SetPinDirection(Pin,Direction) \
ERROR_Port_SetPinDirection_NOT_SELECTED 

#endif /* (PORT_SET_PIN_DIRECTION_API) */

/*******************************************************************************
** Syntax           : void Port_RefreshPortDirection ( void )                 **
**                                                                            **
** Service ID       : 0x02                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - PORT060: PORT061: PORT066: refreshes the direction for all the port    **
**     pins that are configured as direction not changeable during run time   **
**                                                                            **
*******************************************************************************/
extern void Port_RefreshPortDirection(void);


/*******************************************************************************
** Traceability     : [cover parentID=DS_AS_PORT143,DS_AS_PORT103,
                       DS_AS_PORT144,DS_AS_PORT102,DS_AS_PORT075_2,
                       DS_AS_PORT101_PORT211_4,DS_AS_PORT107_PORT146_4,
                       DS_AS_PORT087_4,DS_AS_PORT225]                         **
**                                                                            **
** Syntax           : void Port_GetVersionInfo                                **
**                    (                                                       **
**                      Std_VersionInfoType *VersionInfoPtr                   **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x03                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : VersionInfoPtr - Pointer to where to store the          **
**                    version information of this module.                     **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - PORT102: This function returns the version information of this module  **
**     The version information include : Module ID, Vendor ID,                **
**     Vendor specific version numbers                                        **
**   - PORT103: This function is available if the PORT_VERSION_INFO_API is    **
**     set ON                                                                 **
**                                                                            **
*******************************************************************************/
/* Enable / Disable the use of the function */
#if ( ((PORT_VERSION_INFO_API == STD_ON) && (PORT_DEV_ERROR_DETECT == STD_ON)) )
#define Port_GetVersionInfo(VersionInfoPtr)                                    \
{                                                                              \
  /* Check for DET: PORT_E_PARAM_POINTER */                                    \
  if ((VersionInfoPtr) == NULL_PTR)                                            \
  {                                                                            \
    /* Report PORT_E_PARAM_POINTER DET if service called with                  \
       NULL_PTR                                                                \
    */                                                                         \
    Det_ReportError(                                                           \
      (uint16)PORT_MODULE_ID,                                                  \
      PORT_INSTANCE_ID,                                                        \
      PORT_SID_GETVERSIONINFO,                                                 \
      PORT_E_PARAM_POINTER);                                                   \
  }                                                                            \
  else                                                                         \
  {                                                                            \
        /* Vendor ID information */                                            \
        ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = PORT_VENDOR_ID;   \
        /* Port module ID information */                                       \
        ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = PORT_MODULE_ID;   \
        /* Port module Software major version information */                   \
        ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =           \
                                           (uint8)PORT_SW_MAJOR_VERSION;       \
        /* Port module Software minor version information */                   \
        ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =           \
                                           (uint8)PORT_SW_MINOR_VERSION;       \
        /* Port module Software patch version information */                   \
        ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =           \
                                           (uint8)PORT_SW_PATCH_VERSION;       \
  }                                                                            \
}
#elif((PORT_VERSION_INFO_API == STD_ON) && (PORT_DEV_ERROR_DETECT == STD_OFF))
#define Port_GetVersionInfo(VersionInfoPtr)                                    \
{                                                                              \
  /* Vendor ID information */                                                  \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = PORT_VENDOR_ID;         \
  /* Port module ID information */                                             \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = PORT_MODULE_ID;         \
  /* Port module Software major version information */                         \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =                 \
                                     (uint8)PORT_SW_MAJOR_VERSION;             \
  /* Port module Software minor version information */                         \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =                 \
                                     (uint8)PORT_SW_MINOR_VERSION;             \
  /* Port module Software patch version information */                         \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =                 \
                                     (uint8)PORT_SW_PATCH_VERSION;             \
}/* Port_GetVersionInfo */
#else /*(PORT_VERSION_INFO_API==STD_OFF)&&(PORT_DEV_ERROR_DETECT==STD_OFF)*/
#define Port_GetVersionInfo(VersionInfoPtr)                                    \
ERROR_Port_GetVersionInfo_NOT_SELECTED 

#endif /* (PORT_VERSION_INFO_API) */

/* Enable / Disable the use of the function */
#if (PORT_SET_PIN_MODE_API == STD_ON)
/*******************************************************************************
** Syntax           : void Port_SetPinMode                                    **
**                    (                                                       **
**                      Port_PinType Pin,                                     **
**                      Port_PinModeType Mode                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x04                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters (in)  : Pin - port pin ID whose mode has to be set              **
**                    Mode - port pin mode to be set                          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - PORT125: Sets the port pin mode during runtime.                        **
**   - This function is available if the PORT_SET_PIN_MODE_API is set ON      **
**                                                                            **
*******************************************************************************/
extern void Port_SetPinMode
(
  Port_PinType Pin,
  Port_PinModeType Mode
);
#else

#define Port_SetPinMode(Pin,Mode) ERROR_Port_SetPinMode_NOT_SELECTED

#endif /* (PORT_SET_PIN_MODE_API) */

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#define PORT_STOP_SEC_CODE
/*mapping of code and data to specific memory sections via memory mapping file*/
#include "MemMap.h"

#endif /* PORT_H */
