/******************************************************************************/
/*                                                                            */
/* !Layer           : HAL                                                    */
/*                                                                            */
/* !Component       : CanIf                                                   */
/* !Description     : It represents the interface to the services of 
                      the CAN Driver for the upper communication layers.      */
/*                                                                            */
/*!\Module          : CanIf                                                   */
/*!\file            : CanIf.h                                                 \n
    \Description    : declaration of the provided interface functions         */
/*                                                                            */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/17_CanIf/0$*/
/* $Revision::   1.32     $$Author::   mamroussy      $$Date::   Aug 24 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
#ifndef CANIF_H
#define CANIF_H

#include "CanIf_Cfg.h"
#include "CanIf_Types.h"
#include "CanIf_PBCfg.h"
/******************************************************************************/
/*                                  DEFINES                                   */
/******************************************************************************/

/******************************************************************************/
/*                             DEVELOPMENT ERRORS                             */
/******************************************************************************/
/*!API service called with invalid parameter                                  */
#define CANIF_E_PARAM_CANID                 10
/*!API service called with invalid parameter                                  */
#define CANIF_E_PARAM_DLC                   11
/*!API service called with invalid parameter                                  */
#define CANIF_E_PARAM_HRH                   12
/*!API service called with invalid parameter                                  */
#define CANIF_E_PARAM_LPDU                  13
/*!API service called with invalid parameter                                  */
#define CANIF_E_PARAM_CONTROLLER            14
/*!API service called with invalid parameter                                  */
#define CANIF_E_PARAM_CONTROLLERID          15
/*!API service called with invalid parameter                                  */
#define CANIF_E_PARAM_WAKEUPSOURCE          16
/*!API service called with invalid parameter                                  */
#define CANIF_E_PARAM_TRCV                  17
/*!API service called with invalid parameter                                  */
#define CANIF_E_PARAM_TRCVMODE              18
/*!API service called with invalid parameter                                  */
#define CANIF_E_PARAM_TRCVWAKEUPMODE        19
/*!API service called with invalid pointer                                    */
#define CANIF_E_PARAM_POINTER               20
/*!API service used without module initialization                             */
#define CANIF_E_UNINIT                      30
/*!Requested API operation is not supported                                   */
#define CANIF_E_NOK_NOSUPPORT               40
/*!Transmit PDU ID invalid                                                    */
#define CANIF_E_INVALID_TXPDUID             50
/*!Receive PDU ID invalid                                                     */
#define CANIF_E_INVALID_RXPDUID             60

/******************************************************************************/
/*                                  API IDS                                   */
/******************************************************************************/

/*!Initialization API Id                                                      */
#define CanIf_u8INIT_API                    1
/*!Set Controller Mode API Id                                                 */
#define CanIf_u8SETCTRLMODE_API             3
/*!get Controoler Mode API Id                                                 */
#define CanIf_u8GETCTRLMODE_API             4
/*!Transmit API Id                                                            */
#define CanIf_u8TRANSMIT_API                5
/*!Read Rx Pdu Data API Id                                                    */
#define CanIf_u8READRXDATA_API              6
/*!Read Tx Notification Status API Id                                         */
#define CanIf_u8RDTXNTIFSTAT_API            7
/*!Read Rx Notification Status API Id                                         */
#define CanIf_u8RDRXNTIFSTAT_API            8
/*!Set Psu Mode API Id                                                        */
#define CanIf_u8SETPDUMODE_API              9
/*!Get Psu Mode API Id                                                        */
#define CanIf_u8GETPDUMODE_API              10
/*!Get Version Info API Id                                                    */
#define CanIf_u8GETVERSIONINFO_API          11
/*!Set Dynamic Tx Id API Id                                                   */
#define CanIf_u8SETDYNAMICTXID_API          12
/*!Set Transceiver Mode API Id                                                */
#define CanIf_u8SETTRCVMODE_API             13
/*!get Transceiver Mode API Id                                                */
#define CanIf_u8GETTRCVMODE_API             14
/*!Transceiver Wakeup Reason API Id                                           */
#define CanIf_u8TRCVWPREASON_API            15
/*!Set Transceiver Wakeup Mode API Id                                         */
#define CanIf_u8SETTRCVWPMODE_API           16
/*!Check Wakeup API Id                                                        */
#define CanIf_u8CHECKWAKEUP_API             17
/*!Check Validation API Id                                                    */
#define CanIf_u8CHECKVALIDWP_API            18
/*!Tx Confirmation API Id                                                     */
#define CanIf_u8TXCONF_API                  19
/*!Rx Indication API Id                                                       */
#define CanIf_u8RXINDICAT_API               20
/*!Cancel Tx Confirmation API Id                                              */
#define CanIf_u8CANCELTXCONF_API            21
/*!Controller Bus Off API Id                                                  */
#define CanIf_u8CTRLBUSOFF_API              22
/*!Controller Mode Indication API Id                                          */
#define CanIf_u8CTRLMODEINDIC_API           23
/*!Transceiver API Id                                                         */
#define CanIf_u8TRCVMODEINDIC_API           24
/*!Get Tx Confirmation State API Id                                           */
#define CanIf_u8GETTXCONFIRM_API            25
/*!Cancel Transmit API Id                                                     */
#define CanIf_u8CANCLTRANSMIT_API           24
/*!Clear Trcv Wakeup Flag API Id                                              */
#define CanIf_u8CONFPNAVAILABL_API          26
/*!Clear Trcv Wakeup Flag API Id                                              */
#define CanIf_u8CLRTRCVWUFFLAG_API          30
/*!Check Trcv Wakeup Flag API Id                                              */
#define CanIf_u8CHKTRCVWUFFLAG_API          31
/*!Clear Trcv Wakeup Flag Indication API Id                                   */
#define CanIf_u8CLRTRCVWUFINDIC_API       32
/*!Check Trcv Wakeup Flag Indication API Id                                   */
#define CanIf_u8CHKTRCVWUFINDIC_API       33
/*!Check Baudrate API Id				                                      */
#define CanIf_u8CHKBAUDRATE_API          28
/*!Change Baudrate API Id				                                      */
#define CanIf_u8CHANGEBAUDRATE_API          27
/*!Set Baudrate API Id														  */
#define CanIf_u8SETBAUDRATE_API          39								
/* !Deviation : Inhibit MISRA rule [0857]: Number of macros exceeds 1024    */
/* PRQA S 0857 ++                                                             */
/*!Set IComConfiguration API Id			                                      */
#define CanIf_u8SETICOMCONFIGURATION_API          37
/*!Set Baudrate API Id				                                      */
#define CanIf_u8CURRENTICOMCONFIGURATION_API          38


/******************************************************************************/
/*                            PUBLISHED INFORMATION                           */
/******************************************************************************/
/* !Module ID of CAN Interface                                                */
#define CANIF_MODULE_ID                     (uint16)60
/* !Vendor ID of CAN Interface                                                */
#define CANIF_VENDOR_ID                     (uint16)38
/* !Instance ID of CAN Interface                                              */
#define CANIF_INSTANCE_ID                   (uint16)0x0000
/* !Deviation : Inhibit MISRA rule [0857]: Number of Macro definitions exce-  */
/*              eds 1024 - Program is non-conforming                          */
/* PRQA S 0857 ++                                                             */
/* !Sw Major Version of CAN Interface                                         */
#define CANIF_SW_MAJOR_VERSION              0x02
/* !Sw Minor Version of CAN Interface                                         */
#define CANIF_SW_MINOR_VERSION              0x00
/* !Sw patch Version of CAN Interface                                         */
#define CANIF_SW_PATCH_VERSION              0x01
/* !Sw Ar release Major Version                                               */
#define CANIF_AR_RELEASE_MAJOR_VERSION      (4)
/* !Sw Ar release Minor Version                                               */
#define CANIF_AR_RELEASE_MINOR_VERSION      (1)
/* !Sw Ar release Revision Version                                            */
#define CANIF_AR_RELEASE_REVISION_VERSION   (2)
/******************************************************************************/
/*                          OFFERED SERVICES DECLARATION                      */
/******************************************************************************/
/******************************************************************************/
/*                                  CANIF GENERAL                             */
/******************************************************************************/
#define CANIF_START_SEC_CODE
#include "MemMap.h"
/******************************************************************************/
/* !\Function    : CanIf_Init                                                 \n
   !\Description : This service Initializes internal and external interfaces    
                   of the CAN Interface for the further processing.           \n
    \param[in]     ConfigPtr: Pointer to configuration parameter set,           
                   used e.g. for post build parameters                        \n
    \Range         Not Null                                                   \n
*******************************************************************************/
extern FUNC(void, CANIF_CODE)CanIf_Init(
                                        P2CONST(CanIf_ConfigType,
                                        AUTOMATIC,CANIF_APPL_CONST)ConfigPtr);

/******************************************************************************/
/*                             CANIF TRANSMISSION                             */
/******************************************************************************/

/******************************************************************************/
/* !\Function    : CanIf_Transmit                                             \n
   !\Description : This service initiates a request for transmission of the     
                   CAN L-PDU specified by the CanTxPduId and CAN related data \n
    \param[in]     CanTxPduId: L-PDU handle of CAN L-PDU to be transmitted.     
                   This handle specifies the corresponding CAN L-PDU ID and     
                   implicitly the CAN Driver instance as well as the            
                   corresponding CAN controller device.                       \n
    \Range         0.. PbCfg.CanIf_udtNumofTxPdus-1                           \n
    \param[in]     PduInfoPtr: Pointer to a structure with CAN L-PDU            
                   related data: DLC and pointer to CAN L-SDU buffer          \n
    \Range         not null                                                   \n
    \return        Transmit request has been accepted or not                  \n
    \Range         E_OK, E_NOT_OK                                             \n
*******************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_Transmit(
    VAR(PduIdType, AUTOMATIC) CanTxPduId,
    P2CONST(PduInfoType,AUTOMATIC,CANIF_APPL_CONST)PduInfoPtr);
/******************************************************************************/
/* !\Function    : CanIf_ReadTxNotifStatus                                    \n
   !\Description : This service returns the confirmation status (confirmation 
                   occured of not) of a specific static or dynamic CAN Tx L-PDU,
                   requested by the CanTxPduId.                               \n
    \param[in]     CanTxPduId: L-PDU handle of CAN L-PDU to be transmitted.     
                   This handle specifies the corresponding CAN L-PDU ID and     
                   implicitly the CAN Driver instance as well as the            
                   corresponding CAN controller device.                       \n
    \Range         0.. PbCfg.CanIf_udtNumofTxPdus-1                           \n
    \return        Current confirmation status of the corresponding CAN 
                   Tx L-PDU.                                                  \n
    \Range         CANIF_NO_NOTIFICATION, CANIF_TX_RX_NOTIFICATION            \n
*******************************************************************************/
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON||CanIf_bDEV_ERR_DETECT==STD_ON)
extern FUNC(CanIf_NotifStatusType, CANIF_CODE)CanIf_ReadTxNotifStatus(
    VAR(PduIdType ,AUTOMATIC)CanTxPduId);
#endif
/******************************************************************************/
/* !\Function    : CanIf_GetTxConfirmationState                               \n
   !\Description : This service reports, if any TX confirmation has been done   
                   for the whole CAN controller since the last CAN controller   
                   start.                                                     \n
    \param[in]     ControllerId: Abstracted CanIf ControllerId which is         
                   assigned to a CAN controller                               \n
    \Range         0.. CanIf_ku8eNumOfControllers-1                           \n
    \return        Combined TX confirmation status for all TX PDUs of the       
                   CAN controller                                             \n
    \Range         CANIF_NO_NOTIFICATION, CANIF_TX_RX_NOTIFICATION            \n
*******************************************************************************/
#if(CanIf_bTXCONF_POLL_SUPPORT==STD_ON||CanIf_bDEV_ERR_DETECT==STD_ON)
extern FUNC(CanIf_NotifStatusType, CANIF_CODE)CanIf_GetTxConfirmationState(
    VAR(uint8 ,AUTOMATIC)ControllerId);
#endif
/******************************************************************************/
/* !\Function    : CanIf_CancelTransmit                                       \n
   !\Description : This is a dummy API introduced for interface compatibility.\n
    \param[in]     CanTxPduId: L-PDU handle of CAN L-PDU to be transmitted.     
                   This handle specifies the corresponding CAN L-PDU ID and     
                   implicitly the CAN Driver instance as well as the            
                   corresponding CAN controller device.                       \n
    \Range         0.. PbCfg.CanIf_udtNumofTxPdus-1                           \n
    \return        Always return E_OK except if input parameters is invalid     
                   or CanIf isn't initialized                                 \n
    \Range         E_OK, E_NOT_OK                                             \n
*******************************************************************************/
#if(CanIf_bCANCEL_TRANSMIT==STD_ON||CanIf_bDEV_ERR_DETECT==STD_ON)
FUNC(Std_ReturnType, CANIF_CODE)CanIf_CancelTransmit(
    VAR(PduIdType ,AUTOMATIC)CanTxPduId);
#endif
/******************************************************************************/
/* !\Function    : CanIf_SetDynamicTxId                                       \n
   !\Description : This service reconfigures the corresponding CAN identifier
                   of the requested CAN L-PDU.                                \n
    \param[in]     CanTxPduId: L-PDU handle of CAN L-PDU for transmission.      
                   This ID specifies the corresponding CAN L-PDU ID and         
                   implicitly the CAN Driver instance as well as the            
                   corresponding CAN controller device.                       \n
    \Range         0..PbCfg.CanIf_udtNumofTxPdus-1                            \n
    \param[in]     Standard/Extended CAN ID of CAN L-PDU that                   
                   shall be transmitted.                                      \n
    \Range         0..0x7FF Standard    0..536870911 Extended                   
                   BIF: 0 Standard , 1 Extended                               \n
    \return        void                                                       \n
    \Range         N/A                                                        \n
*******************************************************************************/
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON||CanIf_bDEV_ERR_DETECT == STD_ON)
FUNC(void, CANIF_CODE)CanIf_SetDynamicTxId(
    VAR(PduIdType, AUTOMATIC) CanTxPduId,
    VAR(Can_IdType, AUTOMATIC) CanId);
#endif
/******************************************************************************/
/*                                CANIF RECEPTION                             */
/******************************************************************************/
/******************************************************************************/
/* !\Function    : CanIf_ReadRxNotifStatus                                    \n
   !\Description : This service returns the indication status                   
                   (indication occurred or not) of a specific CAN Rx L-PDU,     
                   requested by the CanRxPduId.                               \n
    \param[in]     CanRxPduId: L-PDU handle of CAN L-PDU to be received.        
                   This handle specifies the corresponding CAN L-PDU ID and     
                   implicitly the CAN Driver instance as well as the            
                   corresponding CAN controller device.                       \n
    \Range         0..(PbCfg.CanIf_udtNumofRxPdus-1)                          \n
    \return        Current indication status of the corresponding CAN Rx        
                   L-PDU.                                                     \n
    \Range         CANIF_NO_NOTIFICATION,CANIF_TX_RX_NOTIFICATION             \n
*******************************************************************************/
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON||CanIf_bDEV_ERR_DETECT==STD_ON)
extern FUNC(CanIf_NotifStatusType, CANIF_CODE)CanIf_ReadRxNotifStatus(
    VAR(PduIdType ,AUTOMATIC)CanRxPduId);
#endif
/******************************************************************************/
/* !\Function    : CanIf_ReadRxPduData                                        \n
   !\Description : This service provides the CAN DLC and the received data      
                  of the requested CanRxPduId to the calling upper layer.     \n
    \param[in]     CanRxPduId: Receive L-PDU handle of CAN L-PDU. This handle 
                   specifies the corresponding CAN L-PDU ID and implicitly      
                   the CAN Driver instance as well as the corresponding         
                   CAN controller device.                                     \n
    \Range         0..(PbCfg.CanIf_udtNumofRxPdus-1)                          \n
    \param[out]     PduInfoPtr: Pointer to a structure with CAN L-PDU related   
                   data: DLC and pointer to CAN L-SDU buffer                  \n
    \Range         not NULL                                                   \n
    \return        Request for L-PDU data has been accepted or not            \n
    \Range         E_OK, E_NOT_OK                                             \n
*******************************************************************************/
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON||CanIf_bDEV_ERR_DETECT==STD_ON)
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_ReadRxPduData(
    VAR(PduIdType ,AUTOMATIC)CanRxPduId,
    P2VAR(PduInfoType,AUTOMATIC,CANIF_APPL_DATA)PduInfoPtr);
#endif
/******************************************************************************/
/*                             CANIF MODE HANDLER                             */
/******************************************************************************/

/******************************************************************************/
/* !\Description : This service calls the corresponding CAN Driver service for 
                   changing of the CAN controller mode.                       \n
    \param[in]     ControllerId:  Abstracted CanIf ControllerId which is        
                   assigned to a CAN controller, which is requested             
                   for mode transition.                                       \n
    \Range         0..CanIf_ku8eNumOfControllers-1                            \n
    \param[in]     ControllerMode:  Requested mode transition                 \n
    \Range         CANIF_CS_SLEEP,CANIF_CS_STARTED,CANIF_CS_STOPPED           \n
    \return        Controller mode request has been accepted or not           \n
    \Range         E_OK, E_NOT_OK                                             \n
*******************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_SetControllerMode(
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(CanIf_ControllerModeType, AUTOMATIC) ControllerMode);
/******************************************************************************/
/*!\Function    : CanIf_GetControllerMode                                    \n
   !\Description : This service reports about the current status of the         
                   requested CAN controller.                                  \n
    \param[in]     ControllerId:  Abstracted CanIf ControllerId which is        
                   assigned to a CAN controller, which is requested             
                   for mode transition.                                       \n
    \Range         0..CanIf_ku8eNumOfControllers-1                            \n
    \param[out]     ControllerModePtr:  Pointer to a memory location, where     
                   the current mode of the CAN controller will be stored.     \n
    \Range         Not NULL                                                   \n
    \return        Controller mode request has been accepted or not           \n
    \Range         E_OK, E_NOT_OK                                             \n
*******************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_GetControllerMode(
    VAR(uint8, AUTOMATIC) ControllerId,
    P2VAR(CanIf_ControllerModeType,AUTOMATIC,CANIF_APPL_DATA)
        ControllerModePtr);
/******************************************************************************/
/* !\Function    : CanIf_SetTrcvMode                                          \n
   !\Description : This service changes the operation mode of the tansceiver    
                  TransceiverId, via calling the corresponding CAN Transceiver  
                  Driver service.                                             \n
    \param[in]     TransceiverId: Abstracted CanIf TransceiverId,               
                   which is assigned to a CAN transceiver, which is requested   
                   for mode transition                                        \n
    \Range         0..CanIf_u8NUM_OF_TRCVS-1                                  \n
    \param[in]     Requested mode transition                                  \n
    \Range         Maximum Number of Controlers assigned to that CanDrvId     \n
    \return        transceiver changed to requestd to rquested mode or not    \n
    \Range         E_OK: Will be returned, if the transceiver state has been    
                   changed to the requested mode.                               
                   E_NOT_OK: Will be returned, if the transceiver state         
                   change has failed or the parameter is out of the allowed     
                   range.The previous state has not been changed.             \n
*******************************************************************************/
#if(CanIf_u8NUM_OF_TRCVS!=0||CanIf_bDEV_ERR_DETECT==STD_ON)
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_SetTrcvMode(
    VAR(uint8, AUTOMATIC) TransceiverId,
    VAR(CanTrcv_TrcvModeType, AUTOMATIC) TransceiverMode);
#endif
/******************************************************************************/
/* !\Function    : CanIf_GetTrcvMode                                          \n
   !\Description : his function invokes CanTrcv_GetOpMode and updates           
                   the parameter TransceiverModePtr with the value              
                   OpMode provided by CanTrcv.                                \n
    \param[in]     TransceiverId: Abstracted CanIf TransceiverId, which is      
                   assigned to a CAN transceiver, which is requested for        
                   current operation mode.                                    \n
    \Range         0..CanIf_u8NUM_OF_TRCVS-1                                  \n
    \param[out]     TransceiverModePtr Requested mode of requested network      
                   the Transceiver is connected to.                           \n
    \Range         not Null                                                   \n
    \return        Transceiver mode request has been accepted or not          \n
    \Range         E_OK,E_NOT_OK                                              \n
*******************************************************************************/
#if(CanIf_u8NUM_OF_TRCVS!=0||CanIf_bDEV_ERR_DETECT==STD_ON)
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_GetTrcvMode(
    P2VAR(CanTrcv_TrcvModeType,AUTOMATIC,CANIF_APPL_DATA)TransceiverModePtr,
    VAR(uint8, AUTOMATIC) TransceiverId);
#endif
/******************************************************************************/
/* !\Function    : CanIf_SetPduMode                                           \n
   !\Description : This service sets the requested mode at the                  
                   L-PDUs of a predefined logical PDU channel.                \n
    \param[in]     ControllerId: All PDUs of the own ECU connected to the       
                   corresponding CanIf ControllerId, which is assigned to       
                   a physical CAN controller are addressed.                   \n
    \Range         0..CanIf_ku8eNumOfControllers                              \n
    \param[in]     PduModeRequest: Requested PDU mode change                  \n
    \Range         (see CanIf_PduSetModeType)                                 \n
    \return        Request for mode transition has been accepted or not       \n
    \Range         E_OK, E_NOT_OK                                             \n
*******************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_SetPduMode(
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(CanIf_PduSetModeType, AUTOMATIC) PduModeRequest);
/******************************************************************************/
/* !\Function    : CanIf_GetPduMode                                           \n
   !\Description : This service reports the current mode of                     
                   a requested PDU channel.                                   \n
    \param[in]     ControllerId: All PDUs of the own ECU connected to the       
                   corresponding CanIf ControllerId, which is assigned to       
                   a physical CAN controller are addressed.                   \n
    \Range         0..CanIf_ku8eNumOfControllers                              \n
    \param[out]     PduModePtr:Pointer to a memory location, where the current 
                   mode of the logical PDU channel will be stored.            \n
    \Range         Not NULL                                                   \n
    \return        mode request has been accepted or not                      \n
    \Range         E_OK, E_NOT_OK                                             \n
*******************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_GetPduMode(
    VAR(uint8, AUTOMATIC) ControllerId,
    P2VAR(CanIf_PduGetModeType,AUTOMATIC,CANIF_APPL_DATA) PduModePtr);
/******************************************************************************/
/* !\Function    : CanIf_SetTrcvWakeupMode                                    \n
   !\Description : This function shall call CanTrcv_SetTrcvWakeupMode.        \n
    \param[in]     TransceiverId: Abstracted CanIf TransceiverId, which is      
                   assigned to a CAN transceiver, which is requested            
                   for wake up reason.                                        \n
    \Range         0..CanIf_u8NUM_OF_TRCVS                                    \n
    \param[in]     TrcvWakeupMode:provided pointer to where the requested       
                   transceiver wake up reason shall be returned               \n
    \Range         Not NULL                                                   \n
    \return        Transceiver wake up reason request has been accepted.        
                   or not                                                     \n
    \Range         E_OK, E_NOT_OK                                             \n
*******************************************************************************/
#if((CanIf_u8NUM_OF_TRCVS!=0||CanIf_bDEV_ERR_DETECT==STD_ON)&&(CanIf_bWAKUP_SUPPORT == STD_ON))
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_SetTrcvWakeupMode(
    VAR(uint8, AUTOMATIC) TransceiverId,
    VAR(CanTrcv_TrcvWakeupModeType, AUTOMATIC) TrcvWakeupMode);
#endif
/******************************************************************************/
/* !\Function    : CanIf_GetTrcvWakeupReason                                  \n
   !\Description : This service calls the corresponding CAN Driver service for 
                   changing of the CAN controller mode.                       \n
    \param[in]     TransceiverId: Abstracted CanIf TransceiverId, which is      
                   assigned to a CAN transceiver, which is requested            
                   for wake up reason.                                        \n
    \Range         0..CanIf_u8NUM_OF_TRCVS                                    \n
    \param[out]     TrcvWuReasonPtr:provided pointer to where the requested 
                   transceiver wake up reason shall be returned               \n
    \Range         Not NULL                                                   \n
    \return        Transceiver wake up reason request has been accepted.        
                   or not                                                     \n
    \Range         E_OK, E_NOT_OK                                             \n
*******************************************************************************/
#if((CanIf_u8NUM_OF_TRCVS!=0||CanIf_bDEV_ERR_DETECT==STD_ON)&&(CanIf_bWAKUP_SUPPORT == STD_ON))
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_GetTrcvWakeupReason(
    VAR(uint8, AUTOMATIC) TransceiverId,
    P2VAR(CanTrcv_TrcvWakeupReasonType,AUTOMATIC,CANIF_APPL_DATA)
    TrcvWuReasonPtr);
#endif
/******************************************************************************/
/* !\Function    : CanIf_CheckWakeup                                          \n
   !\Description : This service checks, whether an underlying CAN               
                   driver or a CAN transceiver driver already signals       
                   a wakeup event.                                            \n
    \param[in]     WakeupSource: Source device, which initiated the wake        
                   up event: CAN controller or CAN transceiver                \n
    \Range         0..31                                                      \n
    \return        Will be returned, if the check wake up request has           
                   been accepted or not                                       \n
    \Range         E_OK, E_NOT_OK                                             \n
*******************************************************************************/
#if(CanIf_bWAKUP_SUPPORT == STD_ON)
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_CheckWakeup(
    VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource);
#endif
/******************************************************************************/
/* !\Function    : CanIf_CheckValidation                                      \n
   !\Description : Service is performed to validate a previous wakeup event   \n
    \param[in]     WakeupSource: Source device which initiated the wake-up      
                   event and which has to be validated: CAN controller          
                   or CAN transceiver                                         \n
    \Range         0..31                                                      \n
    \return        Will be returned, if the check validation request has        
                   been accepted or not                                       \n
    \Range         E_OK, E_NOT_OK                                             \n
*******************************************************************************/
#if((CanIf_bWAKUP_CHK_VALID_API==STD_ON||CanIf_bDEV_ERR_DETECT==STD_ON)&&(CanIf_bWAKUP_SUPPORT == STD_ON))
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_CheckValidation(
    VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource);
#endif

#if((CanIf_bPUBLIC_PN_SUPPORT == STD_ON)&&(CanIf_bWAKUP_SUPPORT == STD_ON))
/******************************************************************************/
/*!\Description :  Requests the CanIf module to check the Wake flag of the 
												designated CAN transceiver    \n
    \param[in]     TransceiverId: Abstracted CanIf TransceiverId,               
                   which is assigned to a CAN transceiver, which is requested   
                   for mode transition                                        \n
    \Range         0..CanIf_u8NUM_OF_TRCVS-1                                  \n
    \return        Controller mode request has been accepted or not           \n
    \Range         E_OK, E_NOT_OK											  \n
*******************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckTrcvWakeFlag (
	VAR(uint8, AUTOMATIC)  TransceiverId);
/******************************************************************************/
/*!\Description :  Requests the CanIf module to clear the Wake flag of the 
												designated CAN transceiver    \n
    \param[in]     TransceiverId: Abstracted CanIf TransceiverId,               
                   which is assigned to a CAN transceiver, which is requested   
                   for mode transition                                        \n
    \Range         0..CanIf_u8NUM_OF_TRCVS-1                                  \n
    \return        Controller mode request has been accepted or not           \n
    \Range         E_OK, E_NOT_OK											  \n
*******************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearTrcvWufFlag (
	VAR(uint8, AUTOMATIC)  TransceiverId);
#endif
/******************************************************************************/
/*!\Description : This service returns the version information of the called 
                   CAN Interface module.                                      \n
    \param[out]    VersionInfo: Pointer to where to store the                   
                   version information of this module.                        \n
    \Range         Not Null                                                   \n
    \Trace_To CANIF-CDD-0252(0)                                                 
*******************************************************************************/
/* PRQA S 3412 L1                                                             */
#if (CanIf_bVERSIONINFO_API == STD_ON)
  #if (CanIf_bDEV_ERR_DETECT == STD_ON)
    #define CanIf_GetVersionInfo(Versioninfo) do {                              \
	    /* \Trace_To CANIF-CDD-0254(0)                                        */\
		/*!If parameter VersionInfo has an invalid value                      */\
      if ((Versioninfo) != NULL_PTR)											\
      {                                                                         \
      ((Std_VersionInfoType *)(Versioninfo))->vendorID =							\
								CANIF_VENDOR_ID;                                \
      ((Std_VersionInfoType *)(Versioninfo))->moduleID =							\
								CANIF_MODULE_ID;                                \
      ((Std_VersionInfoType *)(Versioninfo))->sw_major_version =					\
										CANIF_SW_MAJOR_VERSION;                 \
      ((Std_VersionInfoType *)(Versioninfo))->sw_minor_version =					\
										CANIF_SW_MINOR_VERSION;                 \
      ((Std_VersionInfoType *)(Versioninfo))->sw_patch_version =					\
										CANIF_SW_PATCH_VERSION;                 \
      }                                                                         \
      else                                                                      \
      {                                                                         \
        CanIf_vidDET_REPORT_ERROR(CanIf_u8GETVERSIONINFO_API,					\
            CANIF_E_PARAM_POINTER);												\
      }                                                                         \
    }while(1==0)
  #else
        /* \Trace_To CANIF-CDD-0253(0)                                        */\
    #define Com_GetVersionInfo(Versioninfo) do {                                \
      ((Std_VersionInfoType *)(Versioninfo))->vendorID = CANIF_VENDOR_ID;         \
      ((Std_VersionInfoType *)(Versioninfo))->moduleID = CANIF_MODULE_ID;         \
      ((Std_VersionInfoType *)(Versioninfo))->sw_major_version =					\
									CANIF_SW_MAJOR_VERSION;		                \
      ((Std_VersionInfoType *)(Versioninfo))->sw_minor_version =					\
									CANIF_SW_MINOR_VERSION;						\
      ((Std_VersionInfoType *)(Versioninfo))->sw_patch_version =					\
									CANIF_SW_PATCH_VERSION;			            \
      } while (1==0)
  #endif
#else
  #if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*! Report to the DET (using ANIF_E_NOK_NOSUPPORT)                        */\
    /* \Trace_To CANIF-CDD-5243(0)                                            */\
    #define CanIf_GetVersionInfo(Versioninfo) do {								\
			CanIf_vidDET_REPORT_ERROR(CanIf_u8GETVERSIONINFO_API,				\
											CANIF_E_NOK_NOSUPPORT);				\
    }while (1==0)
	#endif
#endif
/* PRQA L:L1                                                                  */
#define CANIF_STOP_SEC_CODE
/* PRQA S 0857 --                                                             */
#include "MemMap.h"
/* Check this component version information toward configured one             */
#ifdef CANIF_CFG_MAJOR_VERSION 
  #ifdef CANIF_CFG_MINOR_VERSION
     /* Major version of the vendor specific implementation of CANIF module   */
    #if (CANIF_SW_MAJOR_VERSION != CANIF_CFG_MAJOR_VERSION)
      #error "Configuration Major Version incompatible with vendor C & H files"
    #endif
     /* Minor version of the vendor specific implementation of CANIF module   */
    #if (CANIF_SW_MINOR_VERSION != CANIF_CFG_MINOR_VERSION)
      #error "Configuration Minor Version incompatible with vendor C & H files"
    #endif 
  #else
    #error "Configuration Minor Version for C and H files not defined"
  #endif /* CANIF_CFG_MINOR_VERSION */
#else
  #error "Configuration Major Version for C and H files not defined"
#endif  /* CANIF_CFG_MAJOR_VERSION */

/*-------------------------------- end of file -------------------------------*/
#endif /*CANIF_H*/
/* PRQA S 0857 --                                                             */