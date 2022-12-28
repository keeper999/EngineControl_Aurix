/*****************************************************************************
**                                                                          **
**  File-Name : ComStack_Types.h                                            **
**                                                                          **
**  Copyright (C) none (open standard)                                      **
**                                                                          **
**  TARGET    : all                                                         **
**                                                                          **
**  PROJECT   : AUTOSAR                                                     **
**                                                                          **
**  AUTHOR    : Jens Ruh                                                    **
**                                                                          **
**  PURPOSE   : Provision of Communication Stack Types                      **
**                                                                          **
**  REMARKS   : This file is partly ECU dependent.                          **
**              Implemented SWS: Communication Stack Types (ComStackTypes)  **
**                                                                          **
**  PLATFORM DEPENDANT [yes/no]: no                                         **
**                                                                          **
**  TO BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                          **
*****************************************************************************/

/*****************************************************************************
**                      Author Identity                                     **
******************************************************************************
**                                                                          **
** Initials     Name                       Company                          **
** --------     -------------------------  ---------------------------------**
** jru          Jens Ruh                   DaimlerChrysler AG               **
** fwg          Florian Wohlgemuth         DaimlerChrysler AG               **
*****************************************************************************/

/*****************************************************************************
**                      Revision Control History                            **
*****************************************************************************/

/*
 * V1.0.0:  30.05.2005, jru  : initial version
 * V1.0.1:  31.05.2005, jru  : Version number patch
 * V2.0.0:  28.01.2006, fwg  : Update to V1.0.0 of document: 
 *                               - Added General codes of COMTYPE018 
 *                               - Updated NotifResultType 
 * V2.0.1:  30.01.2006, jru  : Version info updated
 * V2.0.2:  24.02.2006, jru  : Version info updated
 */

#ifndef COMSTACK_TYPES_H
#define COMSTACK_TYPES_H

/*****************************************************************************
**                      Include Section                                     **
*****************************************************************************/

#include "Std_Types.h"                  /* standard AUTOSAR types           */
#include "ComStack_Cfg.h"               

/*****************************************************************************
**                      Global Symbols                                      **
*****************************************************************************/
/* Just for Com.h file : ticket StdSW#Autosar Com (Com)#06355 */
#define     COMSTACKTYPE_AR_RELEASE_MAJOR_VERSION        (4U)

/*
  COMTYPE002 File version information
*/
#define COMSTACKTYPE_AR_MAJOR_VERSION 2
#define COMSTACKTYPE_AR_MINOR_VERSION 0
#define COMSTACKTYPE_AR_PATCH_VERSION 0

/* COMTYPE018 General return codes for NotifResultType */
#define NTFRSLT_OK           0x00 
#define NTFRSLT_E_NOT_OK     0x01 
#define NTFRSLT_E_TIMEOUT_A  0x02 
#define NTFRSLT_E_TIMEOUT_Bs 0x03 
#define NTFRSLT_E_TIMEOUT_Cr 0x04
#define NTFRSLT_E_WRONG_SN   0x05
#define NTFRSLT_E_INVALID_FS 0x06
#define NTFRSLT_E_UNEXP_PDU  0x07
#define NTFRSLT_E_WFT_OVRN   0x08
#define NTFRSLT_E_NO_BUFFER  0x09

/* COMTYPE021 General return codes for BusTrcvErrorType */
#define BUSTRCV_NO_ERROR     0x00
#define BUSTRCV_E_ERROR      0x01


/*****************************************************************************
**                      Global Data Types (ECU dependent)                   **
*****************************************************************************/

/* Chapter 8.1.1.1 */
typedef uint8        PduIdType;     /* Type of PDU ID.
                                    Allowed ranges: uint8 .. uint16 */

/* Chapter 8.1.1.2 */
typedef uint16       PduLengthType; /* Type of PDU Length.
                                    Allowed ranges: uint8 .. uint32 */

/* Chapter 8.1.1.5 */
typedef uint8        NotifResultType;
#define     NTFRSLT_E_TIMEOUT_CR                0x04	
#define     NTFRSLT_E_CANCELATION_OK            0x0B
#define     NTFRSLT_E_TIMEOUT_BS                0x03


/* Chapter 8.1.1.6 */
typedef uint8        BusTrcvErrorType;

typedef uint16       NetworkHandleType;

typedef uint8        PNCHandleType;

typedef uint8        IcomConfigIdType;
typedef enum
{
  ICOM_SWITCH_E_OK = 0 ,
  ICOM_SWITCH_E_FAILED = 1 
} IcomSwitch_ErrorType;

typedef enum
{
/*! \Description  Separation Time
    */
  STMIN = 0,
/*! \Description   Block Size
  */
  BS = 1
} TPParameterType;

typedef enum
{
/*! \Description   TP_DATACONF indicates that all data, that have been \n
                   copied so far,are confirmed and can be removed \n
                   from the TP buffer. Data copied by this API \n
                   call are excluded and will be confirmed later.\n
 */
  TP_DATACONF = 0 ,
/*! \Description   TP_DATARETRY indicates that this API call shall copy \n
                   already copied data in order to recover from an error.\n
                   In this case TxTpDataCnt specifies the offset of the \n
                   first byte to be copied by the API call.
 */
  TP_DATARETRY = 1 ,
/*! \Description   TP_CONFPENDING indicates that the previously copied \n
                   data must remain in the TP      */
  TP_CONFPENDING = 2 ,
/*! \Description   TP_NORETRY indicate that the copied transmit data \n
                   can be removed from the buffer after it has been copied.
 */
  TP_NORETRY = 3
} TpDataStateType;

typedef struct
{
/*! \Description   enum – The enum type to be used to store the state of Tp\n
                   buffer.   \n
  */
  TpDataStateType    TpDataState;
/*! \Description   length of the SDU in bytes   \n
   */
  PduLengthType    TxTpDataCnt;
} RetryInfoType;

/*****************************************************************************
**                      Global Data Types (ECU independent)                 **
*****************************************************************************/

/* Chapter 8.1.1.3 */
typedef struct                        
{
        uint8          *SduDataPtr;
        PduLengthType  SduLength;
#if (COMSTACK_coPDU_INFO_TYPE_ADD_CANID == COMSTACK_coENABLE)
        Can_IdType udtCanId;
#endif
} PduInfoType;                        /* Basic information about a PDU of any 
                                      type*/
/* Chapter 8.1.1.4 */
typedef enum                          
{
         BUFREQ_OK,
         BUFREQ_E_NOT_OK,
         BUFREQ_E_BUSY,
         BUFREQ_E_OVFL
} BufReq_ReturnType;                 /* result of a buffer request          */


/*****************************************************************************
**                      Global Data                                         **
*****************************************************************************/
/* intentionally left open */

/*****************************************************************************
**                      Global Functions                                    **
*****************************************************************************/
/* intentionally left open */

#endif /* COMSTACK_TYPES_H */
