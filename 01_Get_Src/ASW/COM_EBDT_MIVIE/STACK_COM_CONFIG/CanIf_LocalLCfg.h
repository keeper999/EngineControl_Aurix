
/******************************************************************************/
/*                                                                            */
/* !Layer           : HAL                                                    */
/*                                                                            */
/* !Component       : CanIf                                                   */
/* !Description     : It represents the interface to the services of 
                      the CAN Driver for the upper communication layers.      */
/*                                                                            */
/*!\Module          : CanIf_LCfg                                               */
/*!\file            : CanIf_LocalLCfg.h                                       \n
    \Description    :It contain Link-Time Configuration Types and extern      \n
                     for the CanIf                                            */
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
/* $Revision::   1.6      $$Author::   ametwelly      $$Date::   Jun 21 2012 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*!  \Description contains the configuration (parameters) of an addressed CAN
                  controller 
*******************************************************************************/
#ifndef CANIF_LOCALLCFG_H
#define CANIF_LOCALLCFG_H


/*                                    DEFINES                            */
/******************************************************************************/
/*!  \Description no upper layer configured for Rx Indication for the     \n
      corresponding RxPdu 
*******************************************************************************/
#define u8NO_UL_CONFIGURED  10
/******************************************************************************/
/*!  \Description Can NM is the upper layer configured for Rx Indication for  \n
      the corresponding RxPdu 
*******************************************************************************/
#define u8CAN_NM            20
/******************************************************************************/
/*!  \Description Can TP is the upper layer configured for Rx Indication for  \n
      the corresponding RxPdu 
*******************************************************************************/
#define u8CAN_TP            30
/******************************************************************************/
/*!  \Description CDD is the upper layer configured for Rx Indication for     \n
      the corresponding RxPdu 
*******************************************************************************/
#define u8CDD               40
/******************************************************************************/
/*!  \Description J1939TP is the upper layer configured for Rx Indication for \n
      the corresponding RxPdu 
*******************************************************************************/
#define u8J1939TP           50
/******************************************************************************/
/*!  \Description PDUR is the upper layer configured for Rx Indication for    \n
      the corresponding RxPdu 
*******************************************************************************/
#define u8PDUR              60
/******************************************************************************/
/*!  \Description XCP is the upper layer configured for Rx Indication for     \n
      the corresponding RxPdu 
*******************************************************************************/
#define u8XCP               70


/******************************************************************************/
/*                              EXPORTED TYPES                                */
/******************************************************************************/
/******************************************************************************/
/*!  \Description Operating modes of the CAN Controller and CAN Driver          
*******************************************************************************/
typedef enum
{
    CANIF_CS_UNINIT = 0,
    CANIF_CS_SLEEP=1,
    CANIF_CS_STARTED=2,
    CANIF_CS_STOPPED=3
}CanIf_ControllerModeType;

/******************************************************************************/
/*!  \Description Return value of CAN L-PDU notification status.                
*******************************************************************************/
typedef enum
{
    CANIF_NO_NOTIFICATION= 0,
    CANIF_TX_RX_NOTIFICATION=1
}CanIf_NotifStatusType;

/*----------------------------------------------------------------------------*/
/*                              MODE HANDLER TYPES                            */
/*----------------------------------------------------------------------------*/
/******************************************************************************/
/*!  \Description contains the configuration (parameters) of an adressed CAN
                  controller by an underlying CAN Driver module
*******************************************************************************/
/*CanIfCtrlCfg-->CanIfCtrlId is index of composed array*/
typedef struct
{
    VAR(uint8, AUTOMATIC) u8CtrlIdRef;         
                                /*Controller Id under the CanDriver  */
                                /*CanIfCtrlCfg-->CanIfCtrlCanCtrlRef*/
    VAR(uint8, AUTOMATIC) u8CanDrvId;          
                                /*Driver Id */
                                /*CanIfCtrlDrvCfg-->CanIfCtrlCfg*/
    VAR(uint8, AUTOMATIC) u8HthStartIndex;     
                                /*Startindex of normal Tx 
                                  handles in CanIfHthCfg table   */
                                /*start index for all CanIfHthCfg assingned
                                  to that CanIfCtrlId*/
                                /*if a controller has no HTHs used, then 
                                  u8HthStartIndex shall be configured with 0.*/
    VAR(uint8, AUTOMATIC) u8NumOfHth;          
                                /*Num Of Hths assigned to that Hth*/ 
                                /*size of summition of CanIfHthCfg 
                                  assingned to that CanIfCtrlId(this CanIfHthCfg
                                  should be used)*/
#if(CanIf_bWAKUP_SUPPORT == STD_ON)  
    VAR(boolean, AUTOMATIC) bWakeupSupport;    
                                /*Wakeup Support ON/OFF */
                                /*CanIfCtrlCfg-->CanIfCtrlWakeupSupport*/
                                /*false=STD_OFF and true=STD_ON*/
#if (CanIf_bWAKUP_CHK_VALID_API == STD_ON)
    VAR(uint8, AUTOMATIC) u8WkupEventIndex;    
                                /*if Wakeup Support ON: index of 
                                  this controller in CanIf_astreCtrlWakeup  */
                                /*if CanIfCtrlCfg-->CanIfCtrlWakeupSupport=true
                                  this is index of this element in
                                  CanIf_astreCtrlWakeup array*/
#endif
    VAR(uint8, AUTOMATIC) u8WakupSourceIn;     
                                /*Wakeup Source In for that Controller*/
                                /*CanIfCtrlCfg-->CanIfCtrlWakeupSourceInRef*/
    VAR(uint8, AUTOMATIC) u8WakupSourceOut;    
                                /*Wakeup Source Out for that Controller*/
                                /*CanIfCtrlCfg-->CanIfCtrlWakeupSourceOutRef*/
#endif
}CanIf_tstrCtrlCfg;
/******************************************************************************/
/*!  \Description pointer to void <User_ControllerBusOff>( uint8 ControllerId )
*******************************************************************************/
typedef P2FUNC(void, CANIF_APPL_CODE, CanIf_tpfvidControllerBusOff)
                        ( uint8 ControllerId);
#if(CanIf_bWAKUP_SUPPORT == STD_ON)
/******************************************************************************/
/*!  \Description pointer to void <User_SetWakeupEvent>
                    ( EcuM_WakeupSourceType sources )
*******************************************************************************/
typedef P2FUNC(void, CANIF_APPL_CODE, CanIf_tpfvidSetWakeupEvent)
                        ( EcuM_WakeupSourceType sources);
/******************************************************************************/
/*!  \Description pointer to void <User_ValidateWakeupEvent>
                  ( EcuM_WakeupSourceType sources )
*******************************************************************************/
typedef P2FUNC(void, CANIF_APPL_CODE, CanIf_tpfvidValidWakeupEvent)
                        ( EcuM_WakeupSourceType sources);
#endif
/******************************************************************************/
/*!  \Description pointer to void <User_ControllerModeIndication>
                  ( uint8 ControllerId,
                  CanIf_ControllerModeType ControllerMode )
*******************************************************************************/
typedef P2FUNC(void, CANIF_APPL_CODE, CanIf_tpfvidControllerModeIndic)
                        (   uint8 ControllerId,
                            CanIf_ControllerModeType ControllerMode);
/******************************************************************************/
/*!  \Description pointer to void <User_TrcvModeIndication>
                  ( uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode )
*******************************************************************************/
typedef P2FUNC(void, CANIF_APPL_CODE, CanIf_tpfvidTrcvModeIndic)
                        (   uint8 TransceiverId,
                            CanTrcv_TrcvModeType TransceiverMode);
/******************************************************************************/
/*!  \Description pointer to void <User_ConfirmPnAvailability>
(uint8 TransceiverId)
*******************************************************************************/
typedef P2FUNC(void, CANIF_APPL_CODE, CanIf_tpfvidConfPnAvailability)
                        (uint8 TransceiverId);
/******************************************************************************/
/*!  \Description pointer to void <User_ClearTrcvWuFlagIndication>
( uint8 TransceiverId)
*******************************************************************************/
typedef P2FUNC(void, CANIF_APPL_CODE, CanIf_tpfvidClearTrcvWuFIndic)
                        (uint8 TransceiverId);
/******************************************************************************/
/*!  \Description pointer to void <User_CheckTrcvWuFlagIndication>
( uint8 TransceiverId)
*******************************************************************************/
typedef P2FUNC(void, CANIF_APPL_CODE, CanIf_tpfvidCheckTrcvWuFIndic)
                        (uint8 TransceiverId);
/******************************************************************************/
/*!  \Description Callback functions provided by upper layer modules of the 
                  CanIf. The callback functions defined in this Configuration
                  are common to all configured CAN Drivers / CAN Transceiver
                  Drivers modules. 
*******************************************************************************/
typedef struct
{
    VAR(CanIf_tpfvidControllerBusOff, AUTOMATIC)
        pfvidControllerBusOff;                          
                 /*CanIfDispatchCfg-->CanIfDispatchUserCtrlBusOffName*/
#if(CanIf_bWAKUP_SUPPORT == STD_ON) 
    VAR(CanIf_tpfvidSetWakeupEvent, AUTOMATIC) 
        pfvidSetWakeupEvent;                            
                 /*CanIfDispatchCfg-->CanIfDispatchUserSetWakeupEventName*/
#if (CanIf_bWAKUP_CHK_VALID_API == STD_ON)
    VAR(CanIf_tpfvidValidWakeupEvent, AUTOMATIC) 
        pfvidValidWakeupEvent;                          
                 /*CanIfDispatchCfg-->CanIfDispatchUserValidateWakeupEventName*/
#endif
#endif
    VAR(CanIf_tpfvidControllerModeIndic, AUTOMATIC) 
        pfvidControllerModeIndic;                       
                 /*CanIfDispatchCfg-->CanIfDispatchUserCtrlModeIndicationName*/
#if(CanIf_u8NUM_OF_TRCV_DRVS!=0)
    VAR(CanIf_tpfvidTrcvModeIndic, AUTOMATIC) 
        pfvidTrcvModeIndic;                             
                /*CanIfDispatchCfg-->CanIfDispatchUserTrcvModeIndicationName*/
#endif
#if ((CanIf_bPUBLIC_PN_SUPPORT==STD_ON)&&(CanIf_bWAKUP_SUPPORT == STD_ON))
    VAR(CanIf_tpfvidConfPnAvailability, AUTOMATIC)
pfvidConfPnAvailability;
/*CanIfDispatchCfg-->CanIfDispatchUserConfirmPnAvailabilityName*/
VAR(CanIf_tpfvidClearTrcvWuFIndic, AUTOMATIC)
pfvidClearTrcvWuFlagIndic;
/*CanIfDispatchCfg-->CanIfDispatchUserClearTrcvWufFlagIndicationName*/
VAR(CanIf_tpfvidCheckTrcvWuFIndic, AUTOMATIC)
pfvidCheckTrcvWuFlagIndic;
/*CanIfDispatchCfg-->CanIfDispatchUserCheckTrcvWufFlagIndicationName*/
#endif
}CanIf_tstrDispatchLCfg;
/******************************************************************************/
/*!  \Description Contains the configuration (parameters) of an addressed CAN
                  Transceiver 
*******************************************************************************/
/*CanIfTrcvCfg->CanIfTrcvId is index of composing array*/
typedef struct
{
    VAR(uint8, AUTOMATIC)       u8TrcvIdRef;        
                /* Transeiver Id under the Can Transeiver Driver  */
                /*CanIfTrcvCfg-->CanIfTrcvCanTrcvIdRef*/
#if(CanIf_bWAKUP_SUPPORT == STD_ON)
    VAR(boolean, AUTOMATIC)     bWakeupSupport;     
                /* Wakeup Support ON/OFF */
                /*CanIfTrcvCfg-->CanIfTrcvWakeupSupport*/
                /*false=STD_OFF and true=STD_ON*/
#endif
}CanIf_tstrCanIfTransLCfg;
/******************************************************************************/
/*!  \Description structure that carry wakeup events and wakeup events
                  validation for each controller 
*******************************************************************************/
#if ((CanIf_bWAKUP_CHK_VALID_API == STD_ON)&&(CanIf_bWAKUP_SUPPORT == STD_ON))
typedef struct
{
    VAR(boolean, AUTOMATIC)    bWakeupEvent;
    VAR(boolean, AUTOMATIC)    bWakeupValidation;
}CanIf_tstrCtrlWakeup;
#endif
/******************************************************************************/
/*!  \Description type definition for Pdu Channel Rx Path Status 
*******************************************************************************/
typedef enum
{
    CanIf_RX_PATH_ONLINE = 0,
    CanIf_RX_PATH_OFFLINE=1
}CanIf_tenuRxPathMode;
/******************************************************************************/
/*!  \Description type definition for Pdu Channel Tx Path Status 
*******************************************************************************/
typedef enum
{
    CanIf_TX_PATH_ONLINE = 0,
    CanIf_TX_PATH_OFFLINE=1,
    CanIf_TX_PATH_OFF_ACTIVE=2
}CanIf_tenuTxPathMode;

/******************************************************************************/
/*!  \Description structure type definition for Pdu Channel Tx and Rx Path 
                  Status 
*******************************************************************************/
typedef struct
{
    VAR(CanIf_tenuRxPathMode, AUTOMATIC)    enuRxPath;
    VAR(CanIf_tenuTxPathMode, AUTOMATIC)    enuTxPath;
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
VAR(boolean, AUTOMATIC)bPnTxfilter;
#endif
}CanIf_tstrPduMode;

/*----------------------------------------------------------------------------*/
/*-------------------------END OF MODE HANDLER TYPES--------------------------*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*--------------------------------UL Ids Type---------------------------------*/
/*----------------------------------------------------------------------------*/
/******************************************************************************/
/*!  \Description TxConfirmation Pointer to Function Type 
*******************************************************************************/
typedef P2FUNC(void, CANIF_APPL_CODE, CanIf_tpfudtTxConfirmation)
                        ( PduIdType TxPduId);      
                            /*CanIfTxPduCfg-->CanIfTxPduUserTxConfirmationName*/
/******************************************************************************/
/*!  \Description RxIndication Pointer to Function Type 
*******************************************************************************/
typedef P2FUNC(void, CANIF_APPL_CODE, CanIf_tpfudtRxIndication)
                        ( PduIdType RxPduId, PduInfoType* PduInfoPtr);  
                            /*CanIfRxPduCfg-->CanIfRxPduUserRxIndicationName*/

/******************************************************************************/
/*!  \Description RxIndication Pointer to Function Type and the upper layer 
                  component 
*******************************************************************************/
typedef struct
{
    VAR(CanIf_tpfudtRxIndication, AUTOMATIC)    pfudtRxIndication;
#if(CanIf_bWAKEUP_VALID_BY_NM==STD_ON)
    VAR(uint8, AUTOMATIC)    u8UpperComponent;
#endif
}CanIf_tstrRxULCfg;
/*----------------------------------------------------------------------------*/
/*                                HTH CFG TYPES                               */
/*----------------------------------------------------------------------------*/
/******************************************************************************/
/*!  \Description Specifies the type (Full-CAN or Basic-CAN) of a hardware 
                  object.
*******************************************************************************/
typedef enum
{
    CanIf_BASIC=0,
    CanIf_FULL=1
}CanIf_tenuHandleType;
/******************************************************************************/
/*!  \Description This Structure type contains parameters related to each HTH
*******************************************************************************/
/*CanIfHthCfg*/
typedef struct
{
/* PRQA S 0783 ++ */
/*MISRA Msg justification:  no problem from the same name of u8ControllerId*/
    VAR(uint8, AUTOMATIC)             u8ControllerId;          
                                      /*CanIfHthCfg-->CanIfHthCanCtrlIdRef*/
                                      /*index in CanIf_akstreCtrlLCfg array*/
/* PRQA S 0783 -- */
    VAR(Can_HwHandleType, AUTOMATIC)  udtCanHthRef;            
                                      /*CanIfHthCfg-->CanIfHthIdSymRef*/
    VAR(CanIf_tenuHandleType, AUTOMATIC) enuHandleType;        
                                      /*CanIfHthCfg-->CanIfHthCanHandleTypeRef*/
}CanIf_tstrHthLCfg;
/******************************************************************************/
/*!  \Description This Structure type contains parameters related to each HRH
*******************************************************************************/
/*CanIfHrhCfg */
typedef struct
{
/* PRQA S 0783 ++ */
/*MISRA Msg justification:  no problem from the same name of u8ControllerId*/
    VAR(uint8, AUTOMATIC)             u8ControllerId;           
                                      /*CanIfHrhCfg-->CanIfHrhCanCtrlIdRef*/
                                      /*index in CanIf_akstreCtrlLCfg array*/
/* PRQA S 0783 -- */
    VAR(CanIf_tenuHandleType, AUTOMATIC) enuHandleType;         
                                      /*CanIfHrhCfg-->CanIfHrhCanHandleTypeRef*/
#if(CanIf_bHRH_SW_FILTER==STD_ON)
    VAR(boolean, AUTOMATIC)      bHrhSwFilter;                  
                                   /* if CanIfHrhCfg-->CanIfHrhSoftwareFilter */
                                   /*true = STD_ON ,false =STD_OFF*/
#endif
}CanIf_tstrHrhLCfg;

/******************************************************************************/
/*!  \Description This Structure type contains parameters related to each CanDrv
*******************************************************************************/
/*CanIfCtrlDrvCfg */
typedef struct
{
    VAR(boolean, AUTOMATIC)             bRxIndication;           
                    /*CanIfCtrlDrvCfg-->CanIfCtrlDrvRxIndication*/
                                                                 
                    /*true this Config should be STD_ON else STD_OFF*/
    VAR(boolean, AUTOMATIC)             bTxConfirmation;         
                    /*CanIfCtrlDrvCfg-->CanIfCtrlDrvTxConfirmation*/
                    /*true this Config should be STD_ON else STD_OFF*/
}CanIf_tstrCtrlDrvLCfg;

/******************************************************************************/
/*!  \Description This Structure type contains start index of Hrh for each 
                  driver
*******************************************************************************/
/*start index in CanIf_tstrHrhLCfg array*/
typedef struct
{
    VAR(uint16, AUTOMATIC)             u16HrhListStartindex;    
                    /*CanIfHrhCfg-->CanIfHrhIdSymRef*/

}CanIf_tstrCanDrvHrhMap;
/*----------------------------------------------------------------------------*/
/*---------------------------END OF HTH CFG TYPES-----------------------------*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                                  DECLARATIONS                              */
/*----------------------------------------------------------------------------*/

#define CANIF_START_CONFIG_DATA_8
#include "MemMap.h"

/******************************************************************************/
/*!  \Description constant that defines the overall num. of controllers used 
*******************************************************************************/
extern CONST(uint8, CANIF_CFG_CONST) CanIf_ku8eNumOfControllers;
/******************************************************************************/
/*!  \Description array contains the configuration (parameters) of an 
                  addressed CAN controller 
*******************************************************************************/
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number
                            used as it cant be Definition because it is
                            Link-Time or post-Build Configuration */
extern CONST(CanIf_tstrCtrlCfg, CANIF_CFG_CONST) CanIf_akstreCtrlLCfg[2];
/* PRQA S 3132 -- */
/******************************************************************************/
/*!  \Description Contains the configuration (parameters) of an addressed CAN
                  Transceiver 
*******************************************************************************/
#if(CanIf_u8NUM_OF_TRCVS!=0)
extern CONST(CanIf_tstrCanIfTransLCfg, CANIF_CFG_CONST) 
                        CanIf_akstreTransLCfg[CanIf_u8NUM_OF_TRCVS];
#endif
/******************************************************************************/
/*!  \Description Max number of Upper Layers Max Number.
*******************************************************************************/
extern CONST(CanIf_tstrCtrlDrvLCfg, CANIF_CFG_CONST)
                        CanIf_akstreCtrlDrvLCfg[CanIf_u8NUM_OF_CAN_DRVS];
#define CANIF_STOP_CONFIG_DATA_8
#include "MemMap.h"

#define CANIF_START_CONFIG_DATA_16
#include "MemMap.h"
/******************************************************************************/
/*!  \Description Max number of HW Transmit Handles.
*******************************************************************************/
extern CONST(uint16, CANIF_CFG_CONST) CanIf_ku16eNumOfHth;
/******************************************************************************/
/*!  \Description Max number of HW Receive Handles.
*******************************************************************************/
extern CONST(uint16, CANIF_CFG_CONST) CanIf_ku16eNumOfHrh;
/******************************************************************************/
/*!  \Description Structure to enable mapping from to the start index of 
                  all Hrhs that is assigned tothat CanDrv.}
*******************************************************************************/
extern CONST(CanIf_tstrCanDrvHrhMap, CANIF_CFG_CONST) 
                        CanIf_akstreCanDrvHrhMapLCfg[CanIf_u8NUM_OF_CAN_DRVS];
#define CANIF_STOP_CONFIG_DATA_16
#include "MemMap.h"

#define CANIF_START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/******************************************************************************/
/*!  \Description Callback functions provided by upper layer modules of the 
                  CanIf. The callback functions defined in this Configuration
                  are common to all configured CAN Drivers / CAN Transceiver
                  Drivers modules. 
*******************************************************************************/
extern CONST(CanIf_tstrDispatchLCfg, CANIF_CFG_CONST) CanIf_kstreDispatchLCfg;
/******************************************************************************/
/*!  \Description array Contains Hths Configurations
*******************************************************************************/
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number
                            used as it cant be Definition because it is
                            Link-Time or post-Build Configuration */

extern CONST(CanIf_tstrHthLCfg, CANIF_CFG_CONST) CanIf_akstreHthLCfg[35];
/* PRQA S 3132 -- */
/******************************************************************************/
/*!  \Description array Contains Hrhs Configurations
*******************************************************************************/
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number
                            used as it cant be Definition because it is
                            Link-Time or post-Build Configuration */

extern CONST(CanIf_tstrHrhLCfg, CANIF_CFG_CONST) CanIf_akstreHrhLCfg[42];
/* PRQA S 3132 -- */
/******************************************************************************/
/*!  \Description array contains the PC configuration for UpperLayer Pointer
                  to Tx Cnfirmation Functions 
*******************************************************************************/

/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number
                            used as it cant be Definition because it is
                            Link-Time or post-Build Configuration */

extern CONST(CanIf_tpfudtTxConfirmation, CANIF_CFG_CONST)
                                CanIf_akpfvideUlTxConfrimLTCfg[14];
/* PRQA S 3132 -- */
/******************************************************************************/
/*!  \Description array contains the PC configuration for UpperLayer Pointer
                  Rx Indication to Functions  and the Upper Layer Component
*******************************************************************************/
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number
                            used as it cant be Definition because it is
                            Link-Time or post-Build Configuration */

extern CONST(CanIf_tstrRxULCfg, CANIF_CFG_CONST)
                        CanIf_akstreUlRxLTCfg[6];
/* PRQA S 3132 -- */

#define CANIF_STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_SEC_VAR_8
#include "MemMap.h"
/******************************************************************************/
/*!  \Description array that carry wakeup events and wakeup events
                  validation for each controller 
*******************************************************************************/
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number
                            used as it cant be Definition because it is
                            Link-Time or post-Build Configuration */
#if ((CanIf_bWAKUP_CHK_VALID_API == STD_ON)&&(CanIf_bWAKUP_SUPPORT == STD_ON))

extern VAR(CanIf_tstrCtrlWakeup, CANIF_VAR ) CanIf_astreCtrlWakeup [0];
#endif
/* PRQA S 3132 -- */
#define CANIF_STOP_SEC_VAR_8
#include "MemMap.h"

#define CANIF_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/******************************************************************************/
/*!  \Description array that contains Status of the PDU channel group.
                  Current mode of the channel defines its transmit or receive
                  activity. Communication direction (transmission and
                  /or reception) of the channel can be controlled separately
                  or together by upper layers.
*******************************************************************************/
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number
                            used as it cant be Definition because it is
                            Link-Time or post-Build Configuration */
extern VAR(CanIf_tstrPduMode, CANIF_VAR ) 
                CanIf_astreCurrPduChannelMode [2];
/* PRQA S 3132 -- */
/******************************************************************************/
/*!  \Description array contain Operating modes of the CAN Controllers
*******************************************************************************/
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number
                            used as it cant be Definition because it is
                            Link-Time or post-Build Configuration */
extern VAR(CanIf_ControllerModeType, CANIF_VAR ) 
                CanIf_aenueCurrControllerMode [2];
/* PRQA S 3132 -- */
/******************************************************************************/
/*!  \Description array contain TX confirmation has been done for the 
                  whole CAN controller since the last CAN controller start.
*******************************************************************************/
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number
                            used as it cant be Definition because it is
                            Link-Time or post-Build Configuration */
#if (CanIf_bTXCONF_POLL_SUPPORT == STD_ON)
extern VAR(CanIf_NotifStatusType, CANIF_VAR ) 
                CanIf_aenueTxConfirmState [2];
#endif
/* PRQA S 3132 -- */
#define CANIF_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/*-------------------------------- end of file -------------------------------*/
#endif /*CANIF_LOCALLCFG_H*/
          
