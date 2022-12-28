
/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : Common                                                  */
/* !Description     : Common Integration Files of DCM                         */
/*                                                                            */
/* !Module          : Common                                                  */
/* !Description     : Common Integration Files of DCM                         */
/*                                                                            */
/* !File            : Dcm_Types.h                                             */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VALEO                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2010 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/DCM_CONFIG/DCM_GEN/Dcm_Types.h_v$*/
/* $Revision::   1.15     $$Author::   pbakabad        $$Date::   Mar 11 2013 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef DCM_TYPES_H
#define DCM_TYPES_H

#include "Std_Types.h"
#include "ComStack_Types.h"

/******************************************************************************/
/*!  \Description Dcm_StatusType  \n
*******************************************************************************/  

typedef uint8 Dcm_StatusType;
#define DCM_E_OK                       0x00
#define DCM_E_COMPARE_KEY_FAILED       0x01
#define DCM_E_TI_PREPARE_LIMITS        0x02
#define DCM_E_TI_PREPARE_INCONSTENT    0x03
#define DCM_E_SESSION_NOT_ALLOWED      0x04
#define DCM_E_PROTOCOL_NOT_ALLOWED     0x05
#define DCM_E_ROE_NOT_ACCEPTED         0x06
#define DCM_E_PERIODICID_NOT_ACCEPTED  0x07
#define DCM_E_REQUEST_NOT_ACCEPTED     0x08
#define DCM_E_REQUEST_ENV_NOK          0x09





#define DCM_E_SERVICENOTSUPPORTED                       0x11
#define DCM_E_SUBFUNCTIONNOTSUPPORTED                   0x12
#define DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT     0x13
#define DCM_E_RESPONSEPENDING                           0x78
#define DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION        0x7F
#define DCM_u8E_SUPPRESS_RESPONSE                       0x00
#define DCM_E_RESPONSETOOLONG                           0x14

/******************************************************************************/
/*! \Description Dcm_CommunicationModeType  \n
*******************************************************************************/

typedef uint8 Dcm_CommunicationModeType;
#define DCM_ENABLE_RX_TX_NORM               0x00
#define DCM_ENABLE_RX_DISABLE_TX_NORM       0x01
#define DCM_DISABLE_RX_ENABLE_TX_NORM       0x02
#define DCM_DISABLE_RX_TX_NORMAL            0x03
#define DCM_ENABLE_RX_TX_NM                 0x04
#define DCM_ENABLE_RX_DISABLE_TX_NM         0x05
#define DCM_DISABLE_RX_ENABLE_TX_NM         0x06
#define DCM_DISABLE_RX_TX_NM                0x07
#define DCM_ENABLE_RX_TX_NORM_NM            0x08
#define DCM_ENABLE_RX_DISABLE_TX_NORM_NM    0x09
#define DCM_DISABLE_RX_ENABLE_TX_NORM_NM    0x0A
#define DCM_DISABLE_RX_TX_NORM_NM           0x0B

/******************************************************************************/
/*!  \Description Dcm_ConfirmationStatusType  \n
*******************************************************************************/

typedef uint8 Dcm_ConfirmationStatusType;
#define DCM_RES_POS_OK          0x00
#define DCM_RES_POS_NOT_OK      0x01
#define DCM_RES_NEG_OK          0x02
#define DCM_RES_NEG_NOT_OK      0x03

/******************************************************************************/
/*!  \Description Return values of Callout Dcm_ReadMemory  \n
*******************************************************************************/

typedef uint8 Dcm_ReturnReadMemoryType;
#define DCM_READ_OK         0x00
#define DCM_READ_PENDING    0x01
#define DCM_READ_FAILED     0x02

/******************************************************************************/
/*!  \Description Return type of callout Dcm_WriteMemory   \n
*******************************************************************************/

typedef uint8 Dcm_ReturnWriteMemoryType;
#define DCM_WRITE_OK        0x00
#define DCM_WRITE_PENDING   0x01
#define DCM_WRITE_FAILED    0x02

/******************************************************************************/
/*!  \Description Dcm_RoeStateType  \n
*******************************************************************************/

typedef uint8 Dcm_RoeStateType;
#define DCM_ROE_ACTIVE      0x00
#define DCM_ROE_UNACTIVE    0x01

/******************************************************************************/
/*!  \Description Allows the DCM to know if a diagnostic response shall 
            be sent in the case of a jump from bootloader   \n
*******************************************************************************/

typedef uint8 Dcm_EcuStartModeType;
#define DCM_COLD_START    0x00
#define DCM_WARM_START    0x01

/******************************************************************************/
/*!  \Description Used in Dcm_SetProgConditions() to allow the integrator \n
                  to store relevant information prior to jumping to boot-loader.
*******************************************************************************/

typedef struct{
  uint8 ProtocolId;
  uint8 TesterSourceAddr;
  uint8 Sid;
  uint8 SubFncId;
  PduIdType udtPduId;
}Dcm_ProgConditionsType;

/******************************************************************************/
/*!  \Description Base type for diagnostic message item  \n
*******************************************************************************/

typedef uint8 Dcm_MsgItemType;

/******************************************************************************/
/*!  \Description Base type for diagnostic message 
                    (request, positive or negative response)   \n
*******************************************************************************/

typedef P2VAR(Dcm_MsgItemType,TYPEDEF,TYPEDEF) Dcm_MsgType;

/******************************************************************************/
/*!  \Description Dcm_MsgLenType  \n
*******************************************************************************/

typedef uint32 Dcm_MsgLenType;


/******************************************************************************/
/*!  \Description Dcm_MsgAddInfoType  \n
*******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0635]: Bit fields uses typedef uint8
 *              specified by AUTOSAR                                          */
/* PRQA S 0635 ++                                                             */
/* !Deviation : Inhibit MISRA rule [3621]: Bit fields required by AUTOSAR     */
/* PRQA S 3621 ++                                                             */
typedef struct{
  uint8 reqType :1;
  uint8 suppressPosResponse :1;
  uint8 cancelOperation :1;
}Dcm_MsgAddInfoType;
/* PRQA S 3621 --                                                             */
/* PRQA S 0635 --                                                             */

/******************************************************************************/
/*!  \Description Dcm_IdContextType  \n
*******************************************************************************/

typedef uint8 Dcm_IdContextType;

/******************************************************************************/
/*!  \Description Dcm_MsgContextType  \n
*******************************************************************************/

typedef struct{
  Dcm_MsgType        reqData;
  Dcm_MsgLenType     reqDataLen;
  Dcm_MsgType        resData;
  Dcm_MsgLenType     resDataLen;
  Dcm_MsgAddInfoType msgAddInfo;
  Dcm_MsgLenType     resMaxDataLen;
  Dcm_IdContextType  idContext;
  PduIdType          dcmRxPduId;
}Dcm_MsgContextType;

/******************************************************************************/
/*!  \Description Dcm_ResetModeType  \n
*******************************************************************************/

typedef uint8 Dcm_ResetModeType;
#define DCM_NO_RESET                            0x00
#define DCM_HARD_RESET                          0x01
#define DCM_KEY_ON_OFF_RESET                    0x02
#define DCM_SOFT_RESET                          0x03
#define DCM_ENABLE_RAPID_POWER_SHUTDOWN_RESET   0x04
#define DCM_DISABLE_RAPID_POWER_SHUTDOWN_RESET  0x05
#define DCM_BOOTLOADER_RESET                    0x06
#define DCM_SS_BOOTLOADER_RESET                 0x07
#define DCM_RESET_EXECUTION                     0x08

/******************************************************************************/
/*!  \Description Dcm_SessionBootType  \n
*******************************************************************************/
typedef uint8 Dcm_SessionBootType;
#define DCM_NO_BOOT         0
#define DCM_OEM_BOOT        1
#define DCM_SYS_BOOT        2



#endif /*DCM_TYPES_H*/
      
