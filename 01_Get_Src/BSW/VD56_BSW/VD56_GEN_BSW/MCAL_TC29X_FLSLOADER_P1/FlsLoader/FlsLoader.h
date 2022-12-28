/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : FlsLoader.h $                                              **
**                                                                           **
**  $CC VERSION : \main\15 $                                                 **
**                                                                           **
**  $DATE       : 2013-11-27 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This header file exports                                  **
**                 - functionality of FlsLoader driver.                      **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
** Traceability : [cover parentID=DS_NAS_PR1619,DS_NAS_PR1620,DS_NAS_PR1621,
 DS_NAS_PR1622,DS_NAS_PR63_1,DS_NAS_PR63_2,DS_NAS_PR63_3,DS_NAS_PR63_4,
 DS_NAS_PR63_5,DS_NAS_PR63_6,DS_NAS_PR63_7,DS_NAS_PR63_8] **
**            [/cover]                                                        **
*******************************************************************************/
#ifndef FLSLOADER_H
#define FLSLOADER_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
#include "Mcal.h"


/* Pre-compile/static configuration parameters for FLASHLOADER */
#include "FlsLoader_Cfg.h"

/* Conditional Inclusion of Developement Error Tracer File */
#if  ( FLSLOADER_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/*
   Published parameters
*/

/*If there is no error  */
#define FLSLOADER_E_OK              ((FlsLoader_ReturnType)0x0)
/*If there is error */
#define FLSLOADER_E_NOT_OK          ((FlsLoader_ReturnType)0x1)
/* If locked segment */
#define FLSLOADER_E_LOCKED          ((FlsLoader_ReturnType)0x2)

/*If the memory is installed with OTP */
#define FLSLOADER_E_ROMVERSION      ((FlsLoader_ReturnType)0x3)
/*If Flash is suspended */
#define FLSLOADER_E_SUSPENDED       ((FlsLoader_ReturnType)0x4)
/*If the device is busy */
#define FLSLOADER_E_BUSY            ((FlsLoader_ReturnType)0x5)

/*
   FLASH LOADER Development error codes
*/
#if (FLSLOADER_DEV_ERROR_DETECT == STD_ON)

/*If Invalid Parameter   */
#define FLSLOADER_E_PARAM_IGNORED   ((uint8)0x0)
/*If the Value is incorrect */
#define FLSLOADER_E_UNLOCKED        ((uint8)0x1)
/*If the Size is incorrect */
#define FLSLOADER_E_PARAM_LENGTH    ((uint8)0x2)
/*If the Position is incorrect */
#define FLSLOADER_E_PARAM_ADDRESS   ((uint8)0x3)
/*If the Channel is not initialised */
#define FLSLOADER_E_UNINIT          ((uint8)0x4)
/*If the Channel is not initialised */
#define FLSLOADER_E_PARAM_POINTER   ((uint8)0x5)

/*
   API Service ID's
*/
/* API Service ID for FlsLoader_Init() */
#define FLSLOADER_SID_INIT           ((uint8)0x0)
/* API Service ID for FlsLoader_DeInit() */
#define FLSLOADER_SID_DEINIT         ((uint8)0x1)
/* API Service ID for FlsLoader_WriteSync() */
#define FLSLOADER_SID_WRITE         ((uint8)0x2)
/* API Service ID for FlsLoader_EraseSync() */
#define FLSLOADER_SID_ERASE         ((uint8)0x3)
/* API Service ID for FlsLoader_Lock() */
#define FLSLOADER_SID_LOCK          ((uint8)0x4)
/* API Service ID for FlsLoader_Unlock() */
#define FLSLOADER_SID_UNLOCK        ((uint8)0x5)
/* API Service ID for FlsLoader_SuspendSync() */
#define FLSLOADER_SID_SUSPEND       ((uint8)0x6)
/* API Service ID for FlsLoader_GetVersionInfo() */
#define FLSLOADER_SID_GETVERSIONINFO ((uint8)0x7)

#endif  /*(FLSLOADER_DEV_ERROR_DETECT == STD_ON) */

/* The flash sizes */
#define FLSLOADER_SIZE_16K          ((0x00004000U))
#define FLSLOADER_SIZE_64K          ((0x00010000U))
#define FLSLOADER_SIZE_128K         ((0x00020000U))

/*******************************************************************************
**                      Private Macro like functions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/*
Type: FlsLoader_ValueType
Specifies the values for Mode and Password
*/
typedef uint32 FlsLoader_ValueType;

/*
Type: FlsLoader_AddressType
This specifies the starting address of a sector of Flash
or starting address of a page
*/
typedef uint32 FlsLoader_AddressType;

/*
Type: FlsLoader_LengthType
This specifies the Length/size to programme /erase
*/
typedef uint32 FlsLoader_LengthType;

/*
Type: FlsLoader_ReturnType
This specifies the various Return types that can be specified by the APIs
*/
typedef uint32 FlsLoader_ReturnType;

/*
Type: FlsLoader_Configtype
*/
typedef void FlsLoader_ConfigType;

typedef struct{
  uint32 High;
  uint32 Low;
}FlashLoader_DataType;

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
** Syntax : void FlsLoader_GetVersionInfo(                                    **
**                                      Std_VersionInfoType *VersioninfoPtr ) **
**                                                                            **
** Service ID:      7                                                         **
**                                                                            **
** Sync/Async:      Synchronous                                               **
**                                                                            **
** Reentrancy:      non reentrant                                             **
**                                                                            **
** Parameters (in): none
**                                                                            **
** Parameters (out):VersioninfoPtr : Pointer to where to store the version    **
**                                   information of this module.              **
**                                                                            **
** Return value:    none                                                      **
**                                                                            **
** Description :    This service returns the version information of           **
**                  this module.                                              **
**                  The version information includes:                         **
**                  Module Id,Vendor Id , Vendor specific version numbers     **
**                                                                            **
*******************************************************************************/
#if ((FLSLOADER_VERSION_INFO_API == STD_ON) && \
     (FLSLOADER_DEV_ERROR_DETECT == STD_ON))
#define  FlsLoader_GetVersionInfo(VersionInfoPtr)                          \
{                                                                          \
  if (VersionInfoPtr != NULL_PTR)                                          \
  {                                                                        \
  /* Note that versioninfo pointer is not checked for NULL as the user     \
     is supposed to send the memory allocated pointer */                   \
  /* FLSLOADER Module ID */                                                \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = FLSLOADER_MODULE_ID;\
  /* FLSLOADER vendor ID */                                                \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = FLSLOADER_VENDOR_ID;\
  /* major version of FLSLOADER */                                         \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =             \
                                     (uint8)FLSLOADER_SW_MAJOR_VERSION;    \
  /* minor version of FLSLOADER */                                         \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =             \
                                     (uint8)FLSLOADER_SW_MINOR_VERSION;    \
  /* patch version of FLSLOADER */                                         \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =             \
                                     (uint8)FLSLOADER_SW_PATCH_VERSION;    \
  }                                                                        \
  else                                                                     \
  {                                                                        \
    Det_ReportError(                                                       \
                     (uint16)FLSLOADER_MODULE_ID,                          \
                     FLSLOADER_INSTANCE_ID,                                \
                     FLSLOADER_SID_GETVERSIONINFO,                         \
                     FLSLOADER_E_PARAM_POINTER                             \
                   );/* Report to  DET */                                  \
  }                                                                        \
                                                                           \
}
#elif (FLSLOADER_VERSION_INFO_API == STD_ON) && \
       (FLSLOADER_DEV_ERROR_DETECT == STD_OFF)
#define  FlsLoader_GetVersionInfo(VersionInfoPtr)                             \
{                                                                          \
  if (VersionInfoPtr != NULL_PTR)                                          \
  {                                                                        \
  /* Note that versioninfo pointer is not checked for NULL as the user     \
     is supposed to send the memory allocated pointer */                   \
  /* FLSLOADER Module ID */                                                \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = FLSLOADER_MODULE_ID;\
  /* FLSLOADER vendor ID */                                                \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = FLSLOADER_VENDOR_ID;\
  /* major version of FLSLOADER */                                         \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =             \
                                     (uint8)FLSLOADER_SW_MAJOR_VERSION;    \
  /* minor version of FLSLOADER */                                         \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =             \
                                     (uint8)FLSLOADER_SW_MINOR_VERSION;    \
  /* patch version of FLSLOADER */                                         \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =             \
                                     (uint8)FLSLOADER_SW_PATCH_VERSION;    \
  }                                                                        \
}

#else

#define FlsLoader_GetVersionInfo(VersioninfoPtr) \
ERROR_FlsLoader_GetVersionInfo_NOT_SELECTED

#endif

/*******************************************************************************
** Syntax           :  FlsLoader_ReturnType FlsLoader_Init                    **
**                    (                                                       **
**                      const FlsLoader_ConfigType* Address                   **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x00                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : address :NULL Expected                                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : FlsLoader_ReturnType:(If DET is not enabled)            **
**                    1.FLSLOADER_E_OK                                        **
**                    2.FLSLOADER_E_ROMVERSION                                **
**                    (If DET is enabled and an error has occured)            **
**                    1.FLSLOADER_E_NOT_OK                                    **
**                                                                            **
** Description      : This function initilizes the flash module and checks    **
**                    if all the flash sectors is configured as ROM           **
**                    (protected under user2)                                 **
**                                                                            **
*******************************************************************************/
extern FlsLoader_ReturnType FlsLoader_Init(const FlsLoader_ConfigType* Address);


/* Enable / Disable the use of the function */
#if (FLSLOADER_DEINIT_API == STD_ON)
/*******************************************************************************
** Syntax           :  FlsLoader_ReturnType FlsLoader_DeInit(void)            **
**                                                                            **
** Service ID       : 0x01                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : void                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : FlsLoader_ReturnType:(If DET is not enabled)            **
**                    1. FLSLOADER_E_OK                                       **
**                    2. FLSLOADER_E_BUSY                                     **
**                    (If DET is enabled and an error has occured)            **
**                    1. FLSLOADER_E_NOT_OK                                   **
**                    2. FLSLOADER_E_BUSY                                     **
**                                                                            **
** Description      : This function deinitilizes the flash module.            **
**                    This Function sets the registers to their default       **
**                    state and executes the reset to read command.           **
**                                                                            **
*******************************************************************************/

extern  FlsLoader_ReturnType FlsLoader_DeInit(void);

#else

#define FlsLoader_DeInit() \
ERROR_FlsLoader_DeInit_NOT_SELECTED

#endif /* (FLSLOADER_DEINIT_API == STD_ON) */

/*******************************************************************************
** Syntax           :  FlsLoader_ReturnType FlsLoader_Write                   **
**                    (                                                       **
**                                     FlsLoader_AddressType TargetAddress,   **
**                                     FlsLoader_LengthType Length,           **
**                                     const uint8 *SourceAddressPtr          **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x02                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : address:Source data address                             **
**                    size :Size of the data                                  **
**                    position :Destination address in Flash                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : FlsLoader_ReturnType (Det is not enabled)               **
**                    1.FLSLOADER_E_OK                                        **
**                    2.FLSLOADER_E_BUSY                                      **
**                    3.FLSLOADER_E_FAILURE                                   **
**                    4.FLSLOADER_E_LOCKED                                    **
**                    5.FLSLOADER_E_SUSPENDED                                 **
**                    (Det is enabled and an error has occurred)              **
**                    1.FLSLOADER_E_NOT_OK for all errors but for busy        **
**                      state, FLSLOADER_E_BUSY is returned.                  **
**                                                                            **
** Description      : This function is used to program a page of internal     **
**                    flash. Sectors of PFLASH and DFLASH can be programmed.  **
**                    The position parameter can be segment 8 or segment A    **
**                    Segment 8 means the segment will be cached.             **
**                    The size parameter has to be 256 or its multiple for    **
**                    PFLASH and 128 or its multiple for DFLASH               **
**                    FLSLOADER_E_LOCKED is returned if the call is made to   **
**                    a protected block.FLSLOADER_E_FAILURE is returned if    **
**                    error occurs.                                           **
**                    This function does not check whether the position       **
**                    crosses the boundry from one sector to another          **
*******************************************************************************/
extern FlsLoader_ReturnType FlsLoader_Write(
                                     FlsLoader_AddressType TargetAddress,
                                     FlsLoader_LengthType Length,
                                     const uint8 *SourceAddressPtr);

/*******************************************************************************
** Syntax           :  FlsLoader_ReturnType FlsLoader_Erase                   **
**                    (                                                       **
**                      FlsLoader_AddressType TargetAddress,                  **
**                      FlsLoader_LengthType Length                           **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x03                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Length -Number of Sectors                               **
**                    TargetAddress
                    - specifies the appropriate starting address of the sector**
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     :  FlsLoader_ReturnType(DET is not enabled)               **
**                     1.FLSLOADER_E_OK                                       **
**                     2.FLSLOADER_E_BUSY                                     **
**                     3.FLSLOADER_E_FAILURE                                  **
**                     4.FLSLOADER_E_LOCKED                                   **
**                     5.FLSLOADER_E_SUSPENDED                                **
**                     (DET is enabled and an error has occured )             **
**                     1.FLSLOADER_E_NOT_OK for all errors but for busy.      **
**                       For busy state FLSLOADER_E_BUSY is returned          **
**                                                                            **
** Description      : This function erases the sector of the internal flash   **
**                    in PFLASH and DFLASH                                    **
**                    The completion of this operation is denoted by clearing **
**                    of busy status flag or suspend operation or Error       **
**                    FLSLOADER_E_LOCKED is returned if a call is made to     **
**                    a protected sector                                      **
**                    FLSLOADER_E_FAILURE is returned if an error occurs      **
*******************************************************************************/
extern  FlsLoader_ReturnType FlsLoader_Erase(
                                     FlsLoader_AddressType TargetAddress,
                                     FlsLoader_LengthType Length
                                             );
extern void FlsLoader_lEraseComSeq(FlsLoader_AddressType TargetAddress,
                                     FlsLoader_LengthType Length );
/* Enable / Disable the use of the function */
#if (FLSLOADER_LOCK_UNLOCK_API == STD_ON)
/*******************************************************************************
** Syntax           :  FlsLoader_ReturnType FlsLoader_Lock                    **
**                    (                                                       **
                          FlsLoader_AddressType TargetAddress,
                          FlsLoader_LengthType Length
                        );
**                                                                            **
** Service ID       : 0x04                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : FlsLoader_AddressType TargetAddress                     **
**                    FlsLoader_LengthType Length                             **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     :  FlsLoader_ReturnType:(DET is not enabled)              **
**                     1.FLSLOADER_E_OK                                       **
**                     2.FLSLOADER_E_BUSY                                     **
**                     3.FLSLOADER_E_LOCKED                                   **
**                     4.FLSLOADER_E_FAILURE                                  **
**                     (DET is enabled and an error has occured )             **
**                     1.FLSLOADER_E_NOT_OK for all errors but for busy.      **
**                       For busy state FLSLOADER_E_BUSY is returned          **
**                                                                            **
** Description      : This function is used to  lock(protect) the internal    **
**                    Flash of the microcontroller.The function LOCKSYNC is   **
**                    repeatedly called if more than one user level is        **
**                    configured.Possible user levels are User0,User1 and     **
**                    User2.User Level 2 is meant for One Time Programming    **
**                    If any sector is previously locked and the user         **
**                    desires to change the locking sectors,unlock command is **
**                    required.                                               **
**                    No valid parameters are expected here.                  **
**                    The User0 and User1 sectors can be programmed only four **
**                    times in its lifecycle.                                 **
**                    This API cannot be suspended                            **
*******************************************************************************/
extern FlsLoader_ReturnType FlsLoader_Lock(void);

#else
#define FlsLoader_Lock() ERROR_FlsLoader_Lock_NOT_SELECTED

#endif

/* Enable / Disable the use of the function */
#if (FLSLOADER_LOCK_UNLOCK_API == STD_ON)
/*******************************************************************************
** Syntax           :  FlsLoader_ReturnType FlsLoader_UnLock                  **
**                    (                                                       **
**                        FlsLoader_AddressType TargetAddress,                **
**                        FlsLoader_ValueType* Password                       **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x05                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Mode :Mode for which the flash should be unlocked       **
**                    Password :Password for User0 or User1                   **
**                    Size :Null expected                                     **
**                    Position:Null Expected                                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : FlsLoader_ReturnType:(DET is not enabled)               **
                      1.FLSLOADER_E_OK                                        **
                      2.FLSLOADER_E_BUSY                                      **
                      3.FLSLOADER_E_FAILURE                                   **
                      4.FLSLOADER_E_NOT_OK for all errors but for busy.       **
                         For busy state FLSLOADER_E_BUSY is returned          **
**                                                                            **
** Description      : This function is used to  unlock(protect) the protection
                      in                                PFLASH and DFLASH     **
                      protection.                                             **
**                    A wrong password will result in Protection Error        **
**                    This API needs to be called twice if the user needs to  **
**                    unlock both PFLASH and DFLASH protection                **
**                    This API cannot be suspended                            **
******************************************************************************/
extern FlsLoader_ReturnType FlsLoader_UnLock(
                                          FlsLoader_AddressType TargetAddress,
                                          FlsLoader_ValueType* Password);

#else
#define FlsLoader_UnLock() ERROR_FlsLoader_UnLock_NOT_SELECTED

#endif

/*******************************************************************************
** Syntax           :  FlsLoader_ReturnType FlsLoader_Suspend                 **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x06                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : void                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : FlsLoader_ReturnType:(DET is not enabled)               **
**                    FLSLOADER_E_OK                                          **
**                    (DET is enabled and an error has occured)               **
**                    FLSLOADER_E_NOT_OK                                      **
**                                                                            **
** Description      : This function is used to  suspend flash write or        **
                      erase operation.                                        **
*******************************************************************************/
extern FlsLoader_ReturnType FlsLoader_Suspend(void);
#endif
   /* #ifndef FLSLOADER_H */