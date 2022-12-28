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
**  $FILENAME   : Crc.h $                                                    **
**                                                                           **
**  $CC VERSION : \main\14 $                                                 **
**                                                                           **
**  $DATE       : 2013-10-25 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains functionality of CRC driver.            **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*  TRACEABILITY : [cover parentID=DS_AS_CRC021,DS_AS_CRC018,
        DS_AS_CRC011_CRC017,AUTOSAR:12921,ASW:1546,DS_NAS_PR912]
        [/cover]*/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Std_Types.h */
#include "Std_Types.h"

/* Pre-compile/static configuration parameters for CRC                        */
#include "Crc_Cfg.h"  

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

#if ( CRC_SAFETY_ENABLE == STD_ON ) 
  
/* API Service called with wrong data pointer */
#define CRC_E_PARAM_DATAPTR          ((uint8)4)

/* API Service called with invalid first call */
#define CRC_E_PARAM_FIRSTCALL        ((uint8)5)  

/* Service ID for Crc_CalculateCRC8 */
#define CRC_SID_CALCULATECRC8        ((uint8)1)

/* Service ID for Crc_CalculateCRC8H2F */
#define CRC_SID_CALCULATECRC8H2F     ((uint8)5)

/* Service ID for Crc_CalculateCRC16 */
#define CRC_SID_CALCULATECRC16       ((uint8)2)

/* Service ID for Crc_CalculateCRC32 */
#define CRC_SID_CALCULATECRC32       ((uint8)3)

#endif /* #if ( CRC_SAFETY_ENABLE == STD_ON ) */

/* Return value when Safety error found*/
#define CRC_ERR_FOUND                ((uint8)1)

/* return value when Safety error is not found*/
#define CRC_ERR_NOT_FOUND            ((uint8)0)

/*******************************************************************************
** Traceability:     [cover parentID=DS_AS_CRC021] 

** Syntax :          Crc_GetVersionInfo (VersionInfoPtr)                      **
**                                                                            **
** [/cover]                                                                   **
** Service ID:       0x12                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out):  versioninfo : Pointer to hold the version values        **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : 1. This service will return the version infos of CRC driver  **
*******************************************************************************/
  #if (CRC_VERSION_INFO_API == (STD_ON))                                       \

    #define Crc_GetVersionInfo(VersionInfoPtr)                                 \
   {                                                                           \
  /* Check if the passed parameter is a NULL_PTR.  If so, escalate... */       \
                                                                               \
    /* (pointer VersionInfoPtr is not checked for NULL pointer) */             \
    /* Get CRC Vendor ID */                                                    \
    ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = CRC_VENDOR_ID;        \
    /* Get CRC Module ID */                                                    \
    ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = CRC_MODULE_ID;        \
    /* Get CRC module Software major version */                                \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =               \
                                       (uint8)CRC_SW_MAJOR_VERSION;            \
    /* Get CRC module Software minor version */                                \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =               \
                                       (uint8)CRC_SW_MINOR_VERSION;            \
    /* Get CRC module Software patch version */                                \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =               \
                                       (uint8)CRC_SW_PATCH_VERSION;            \
                                                                               \
  }                                             
  #else
    #define Crc_GetVersionInfo(VersionInfoPtr)\
                                 ERROR_Crc_GetVersionInfo_NOT_SELECTED
  #endif /* #if (CRC_VERSION_INFO_API == (STD_ON)) */                          \
/* end of Crc_GetVersionInfo() */
/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/


/**********************************************************
 * Initial register values
 **********************************************************/



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
** Traceability   :                                                           **
** Syntax     : uint8 Crc_CalculateCRC8                                       **
**      (                                                                     **
**       const uint8* Crc_DataPtr,                                            **
**       uint32 Crc_Length,                                                   **
**       uint8 Crc_StartValue8,                                               **
**       boolean Crc_IsFirstCall                                              **
**      )                                                                     **
**                                                                            **
** Service ID     : 0x01                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters(in)   :  Crc_DataPtr  - Pointer to the start of the datablock   **
**        Crc_Length - Length of the input data to be fetched                 **
**        Crc_StartValue8 -Start value for CRC Calculation                    **
**        Crc_IsFirstCall -Boolean to decIDe the start value                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint8                                                     **
**                                                                            **
** Description    : This function:                                            **
** - This function takes the value of input data pointer, start value and     **
**   polynomial, calculates the crc taking the precomputed                    **
**    and reversed xor value  and returns the CRC xored with XOR value        **
*******************************************************************************/

#ifdef CRC_8_MODE
        
         extern uint8 Crc_CalculateCRC8( const uint8* Crc_DataPtr,
         uint32 Crc_Length, uint8 Crc_StartValue8, boolean Crc_IsFirstCall) ;
        
#endif
/*******************************************************************************
** Traceability   :                                                           **
** Syntax     : uint8 Crc_CalculateCRC8H2F                                    **
**      (                                                                     **
**       const uint8* Crc_DataPtr,                                            **
**       uint32 Crc_Length,                                                   **
**       uint8 Crc_StartValue8H2F,                                            **
**       boolean Crc_IsFirstCall                                              **
**      )                                                                     **
**                                                                            **
** Service ID     : 0x05                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters(in)   :  Crc_DataPtr  - Pointer to the start of the datablock   **
**        Crc_Length - Length of the input data to be fetched                 **
**        Crc_StartValue8H2F -Start value for CRC Calculation                 **
**        Crc_IsFirstCall -Boolean to decIDe the start value                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint8                                                     **
**                                                                            **
** Description    : This function:                                            **
** - This function takes the value of input data pointer, start value and     **
**   polynomial, calculates the crc taking the precomputed                    **
**    and reversed xor value  and returns the CRC xored with XOR value        **
*******************************************************************************/

#ifdef CRC_8H2F_MODE
        
         extern uint8 Crc_CalculateCRC8H2F( const uint8* Crc_DataPtr, 
         uint32 Crc_Length, uint8 Crc_StartValue8H2F, boolean Crc_IsFirstCall);
        
#endif
/*******************************************************************************
** Traceability                                                               **
** Syntax     : uint8 Crc_CalculateCRC16                                      **
**      (                                                                     **
**       const uint8* Crc_DataPtr,                                            **
**       uint32 Crc_Length,                                                   **
**       uint8 Crc_StartValue16,                                              **
**       boolean Crc_IsFirstCall                                              **
**      )                                                                     **
**                                                                            **
** Service ID     : 0x02                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters(in)   :  Crc_DataPtr  - Pointer to the start of the datablock   **
**        Crc_Length - Length of the input data to be fetched                 **
**        Crc_StartValue16 -Start value for CRC Calculation                   **
**        Crc_IsFirstCall -Boolean to decIDe the start value                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint16                                                    **
**                                                                            **
** Description    : This function:                                            **
** - This function takes the value of input data pointer, start value and     **
**   polynomial, calculates the crc taking the precomputed                    **
**    and reversed xor value  and returns the CRC xored with XOR value        **
*******************************************************************************/
#ifdef CRC_16_MODE
        
         extern uint16 Crc_CalculateCRC16( const uint8* Crc_DataPtr,
          uint32 Crc_Length, uint16 Crc_StartValue16, boolean Crc_IsFirstCall);
        
#endif
/*******************************************************************************
** Traceability   :                                                           **
** Syntax     : uint32 Crc_CalculateCRC32                                     **
**      (                                                                     **
**       const uint8* Crc_DataPtr,                                            **
**       uint32 Crc_Length,                                                   **
**       uint32 Crc_StartValue32,                                             **
**       boolean Crc_IsFirstCall                                              **
**      )                                                                     **
**                                                                            **
** Service ID     : 0x03                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters(in)   :  Crc_DataPtr  - Pointer to the start of the datablock   **
**        Crc_Length - Length of the input data to be fetched                 **
**        Crc_StartValue32 -Start value for CRC Calculation                   **
**        Crc_IsFirstCall -Boolean to decIDe the start value                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint32                                                    **
**                                                                            **
** Description    : This function:                                            **
** - This function takes the value of input data pointer, start value and     **
**   polynomial, calculates the crc taking the precomputed                    **
**    and reversed xor value  and returns the CRC xored with XOR value        **
*******************************************************************************/
#ifdef CRC_32_MODE
        
         extern uint32 Crc_CalculateCRC32( const uint8* Crc_DataPtr,
         uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall);
        
#endif

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

/*******************************************************************************
**                            LOW Level Driver Definitions                    **
*******************************************************************************/

/*******************************************************************************
**                            LOW Level Driver Definitions                    **
*******************************************************************************/

