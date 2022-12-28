
/******************************************************************************/
/*                                                                            */
/* !Layer           : HAL                                                    */
/*                                                                            */
/* !Component       : CanIf                                                   */
/* !Description     : It represents the interface to the services of 
                      the CAN Driver for the upper communication layers.      */
/*                                                                            */
/*!\Module          : CanIf_Cfg                                               */
/*!\file            : CanIf_LocalCfg.h                                        \n
    \Description    :It contain Pre-Compile Configurationtypes and externs    \n
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
/* $Revision::   1.12     $$Author::   mamroussy      $$Date::   Dec 06 2012 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
#ifndef CANIF_LOCALCFG_H
#define CANIF_LOCALCFG_H

/******************************************************************************/
/*                              DEFINES                                       */
/******************************************************************************/
/******************************************************************************/
/*!  \Description  Invalid TxPduId
*******************************************************************************/
#define CanIf_u8INVALID_TXPDU                 (PduIdType) (0xFFFFFFFFUL)
/******************************************************************************/
/*!  \Description  Invalid RxPduId
*******************************************************************************/
#define CanIf_u8INVALID_RXPDU                 (PduIdType) (0xFFFFFFFFUL)
/******************************************************************************/
/*!  \Description  Tx buffer is empty
*******************************************************************************/
#define CanIf_u8EMPTY_BUFFER                  (uint8)     (0x00)
/******************************************************************************/
/*!  \Description  Tx buffer contains Tx message cancelled from CanDrv
*******************************************************************************/
#define CanIf_u8ABORTED_TXPDU                 (uint8)     (0x01)
/******************************************************************************/
/*!  \Description  Tx buffer contains new Tx message from Upper layer
*******************************************************************************/
#define CanIf_u8NEW_TXPDU                     (uint8)     (0x02)
/******************************************************************************/
/*!  \Description  Dlc check passed
*******************************************************************************/
#define CanIf_u8DLC_CHECK_PASSED                    (uint8)     0x01
/******************************************************************************/
/*!  \Description  Dlc check failed
*******************************************************************************/
#define CanIf_u8DLC_CHECK_FAILED                    (uint8)     0x00
/******************************************************************************/
/*!  \Description  Invalid Hrh index
*******************************************************************************/
#define CanIf_u16INVALID_HRH                        (uint16)    0xFFFFUL
/******************************************************************************/
/*!  \Description  Hrh sw filter passed
*******************************************************************************/
#define CanIf_u8HRH_SW_FIL_PASSED                   (uint8)     0x01
/******************************************************************************/
/*!  \Description  Hrh sw filter failed
*******************************************************************************/
#define CanIf_u8HRH_SW_FIL_FAILED                   (uint8)     0x00
/******************************************************************************/
/*!  \Description  Rx indication failed in some point (can't resume)
*******************************************************************************/
#define CanIf_u8ABORT_RX_INDICATION                 (uint8)     0x00
/******************************************************************************/
/*!  \Description  Rx indication passed in some point (resume)
*******************************************************************************/
#define CanIf_u8RESUME_RX_INDICATION                (uint8)     0x01



/******************************************************************************/
/*!  \Description use AUTOSAR normal implementation of CanIf_RxIndication 
*******************************************************************************/
#define CanIf_coMIXTE                               0x02

/******************************************************************************/
/*!  \Description  using same critical section for all pdu in Rx Configuration 
*******************************************************************************/
#define CanIf_coSAME_CRITIC_SEC_RX                STD_ON
/******************************************************************************/
/*!  \Description using same critical section for all pdu in Tx Configuration 
*******************************************************************************/
#define CanIf_coSAME_CRITIC_SEC_TX                STD_ON

/******************************************************************************/
/*!  \Description using no Can ID range for all configured HrH 
*******************************************************************************/
#define CanIf_bNO_CANID_RANGE     STD_ON

/******************************************************************************/
/*!  \Description no BASIC CAN pdu is configured 
*******************************************************************************/
#define CanIf_noBASIC_CAN_PDU                        STD_ON
/******************************************************************************/
/*!  \Description used to choose AUTOSAR normal implementation of 
CanIf_RxIndication or the optimized implementation of CanIf_RxIndication
*******************************************************************************/
#define CanIf_coRX_INDICATION                 STD_ON
/******************************************************************************/
/*!  \Description Wake Up supported in ECU
 \Range STD_ON if at least on Controller or Transceiver has Wakeup 
   support enabled.
STD_OFF no Controller or Transceiver has Wakeup support enabled.   
*******************************************************************************/

#define CanIf_bWAKUP_SUPPORT                STD_OFF
/******************************************************************************/
/*!  \Description contains the PC configuration (parameters) of an addressed
                  CAN Transceiver 
*******************************************************************************/
/*CanIfTrcvCfg->CanIfTrcvId is index of composing array*/
typedef struct
{
            /*CanIfTrcvDrvCfg-->CanIfTrcvCfg*/
    VAR(uint8, AUTOMATIC) u8TrcvDrvId;
#if (CanIf_bWAKUP_SUPPORT == STD_ON)
            /*CanIfTrcvCfg-->CanIfTrcvWakeupSourceInRef*/
    VAR(uint8, AUTOMATIC) u8WakupSourceIn;
            /*CanIfTrcvCfg-->CanIfTrcvWakeupSourceOutRef*/
    VAR(uint8, AUTOMATIC) u8WakupSourceOut;
#endif
}CanIf_tstrTrcvPCCfg;
/******************************************************************************/
/*!  \Description Pointer to service  Can_ReturnType,
                        Can_SetControllerMode ( uint8 Controller,
                        Can_StateTransitionType Transition );
                        offred by Can Drvs
*******************************************************************************/
typedef P2FUNC(Can_ReturnType, CANIF_APPL_CODE, CanIf_tpfenuSetControllerMode)
                        ( uint8 Controller,
                        Can_StateTransitionType Transition);
/******************************************************************************/
/*!  \Description Pointer to service Can_ReturnType, CANIF_CODE, Can_Write) 
                        ( Can_HwHandleType Hth, const Can_PduType* PduInfo );
                        offred by Can Drvs
*******************************************************************************/
typedef P2FUNC(Can_ReturnType, CANIF_APPL_CODE, CanIf_tpfenuWrite)
                        ( Can_HwHandleType Hth,
                        const Can_PduType* PduInfo);
/******************************************************************************/
/*!  \Description Pointer to service Can_ReturnType, 
                        Can_CheckWakeup ( uint8 Controller );
                        offred by Can Drvs
*******************************************************************************/
typedef P2FUNC(Can_ReturnType, CANIF_APPL_CODE, CanIf_tpfenuCtrlCheckWakeup)
                        ( uint8 Controller);
/******************************************************************************/
/*!  \Description The lower layer CanDrv pointers to its services.
*******************************************************************************/
typedef struct
{
    VAR(CanIf_tpfenuSetControllerMode, AUTOMATIC) pfenuSetControllerMode;
                /*CanIfCtrlDrvCfg ->CanSetControllerModeName*/
    VAR(CanIf_tpfenuWrite, AUTOMATIC) pfenuWrite;
                /*CanIfCtrlDrvCfg->CanWriteName*/
#if (CanIf_bWAKUP_SUPPORT == STD_ON)
    VAR(CanIf_tpfenuCtrlCheckWakeup, AUTOMATIC) pfenuCheckWakeup;
                /*CanIfCtrlDrvCfg->CanCheckWakeupName*/
#endif
}CanIf_tstrCanDrvServicesPCCfg;
/******************************************************************************/
/*!  \Description Pointer to service Std_ReturnType CanTrcv_SetOpMode
                        ( uint8 Transceiver, CanTrcv_TrcvModeType OpMode )
                        offred by CanTrcv Drvs
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, CANIF_APPL_CODE, CanIf_tpfudtSetOpMode)
                        ( uint8 Transceiver,CanTrcv_TrcvModeType OpMode);
/******************************************************************************/
/*!  \Description Pointer to service Std_ReturnType CanTrcv_GetOpMode
                        ( uint8 Transceiver, CanTrcv_TrcvModeType* OpMode )
                        offred by CanTrcv Drvs
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, CANIF_APPL_CODE, CanIf_tpfudtGetOpMode)
                        ( uint8 Transceiver,CanTrcv_TrcvModeType* OpMode);
/******************************************************************************/
/*!  \Description Pointer to service Std_ReturnType CanTrcv_SetWakeupMode
                        (uint8 Transceiver,
                        CanTrcv_TrcvWakeupModeType TrcvWakeupMode)
                        offred by CanTrcv Drvs
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, CANIF_APPL_CODE, CanIf_tpfudtSetWakeupMode)
                 ( uint8 Transceiver,CanTrcv_TrcvWakeupModeType TrcvWakeupMode);
/******************************************************************************/
/*!  \Description Pointer to service Std_ReturnType CanTrcv_GetBusWuReason
                        ( uint8 Transceiver, 
                        CanTrcv_TrcvWakeupReasonType* reason )
                        offred by CanTrcv Drvs
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, CANIF_APPL_CODE, CanIf_tpfudtGetBusWuReason)
                      ( uint8 Transceiver,CanTrcv_TrcvWakeupReasonType* reason);
/******************************************************************************/
/*!  \Description Pointer to service typedef P2FUNC(Can_ReturnType, 
                        CANIF_CODE, CanTrcv_CheckWakeup) ( uint8 Transceiver )
                        offred by CanTrcv Drvs
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, CANIF_APPL_CODE, CanIf_tpfudtTransCheckWakeup)
                        ( uint8 Transceiver);
/******************************************************************************/
/*!  \Description Pointer to service typedef P2FUNC(Can_ReturnType, 
                        CANIF_CODE, CanTrcvClearWuFlag) ( uint8 Transceiver )
                        offred by CanTrcv Drvs
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, CANIF_APPL_CODE, CanIf_tpfudtClearTrcvWufFlag)
                        ( uint8 Transceiver);
/******************************************************************************/
/*!  \Description Pointer to service typedef P2FUNC(Can_ReturnType, 
                        CANIF_CODE, CanTrcvCheckWuFlag) ( uint8 Transceiver )
                        offred by CanTrcv Drvs
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, CANIF_APPL_CODE, CanIf_tpfudtCheckTrcvWufFlag)
                        ( uint8 Transceiver);
/******************************************************************************/
/*!  \Description The lower layer Can transceiver Driver pointer to its 
                  services.
*******************************************************************************/
typedef struct
{
    /*CanIfTrcvDrvCfg ->CanTrcvSetOpModeName*/
    VAR(CanIf_tpfudtSetOpMode, AUTOMATIC) pfu8SetOpMode;
    /*CanIfTrcvDrvCfg ->CanTrcvGetOpModeName*/
    VAR(CanIf_tpfudtGetOpMode, AUTOMATIC) pfu8GetOpMode;
#if (CanIf_bWAKUP_SUPPORT == STD_ON)
    /*CanIfTrcvDrvCfg ->CanTrcvSetWakeupModeName*/
    VAR(CanIf_tpfudtSetWakeupMode, AUTOMATIC) pfu8SetWakeupMode;
    /*CanIfTrcvDrvCfg ->CanTrcvGetBusWuReasonName*/
    VAR(CanIf_tpfudtGetBusWuReason, AUTOMATIC) pfu8GetBusWuReason;
    /*CanIfTrcvDrvCfg ->CanTrcvCheckWakeupName*/
    VAR(CanIf_tpfudtTransCheckWakeup, AUTOMATIC) pfu8CheckWakeup;
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
    /*CanIfTrcvDrvCfg ->CanTrcvClearWuFlagName*/
    VAR(CanIf_tpfudtClearTrcvWufFlag, AUTOMATIC) pfu8ClearTrcvWufFlag;
/*CanIfTrcvDrvCfg ->CanTrcvCheckWuFlagName*/
    VAR(CanIf_tpfudtCheckTrcvWufFlag, AUTOMATIC) pfu8CheckTrcvWufFlag;
#endif
#endif    
}CanIf_tstrTrcvDrvServicesPCCfg;

/******************************************************************************/
/*!  \Description Pointer to Enter Critical Section service
*******************************************************************************/
typedef P2FUNC(void, CANIF_APPL_CODE, CanIf_tpfvidEnterCriticalSec)(void);
/******************************************************************************/
/*!  \Description Pointer to Exit Critical Section service
*******************************************************************************/
typedef P2FUNC(void, CANIF_APPL_CODE, CanIf_tpfvidExitCriticalSec)(void);
/******************************************************************************/
/*!  \Description structure of pointer to functions to access
                  critical section Enter and Exit
*******************************************************************************/
typedef struct
{
    VAR(CanIf_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterCriticalSec;
    VAR(CanIf_tpfvidExitCriticalSec, AUTOMATIC) pfvidExitCriticalSec;
}CanIf_tstrCriticalSection;



#define CANIF_START_CONFIG_DATA_8
#include "MemMap.h"
/******************************************************************************/
/*!  \Description array contains the PC configuration (parameters) of an 
                 addressed CAN Transceiver 
*******************************************************************************/
#if(CanIf_u8NUM_OF_TRCVS!=0)
extern CONST(CanIf_tstrTrcvPCCfg, CANIF_CFG_CONST)
                       CanIf_akstreCanTrcvPCCfg
                                    [CanIf_u8NUM_OF_TRCVS];
#endif
#define CANIF_STOP_CONFIG_DATA_8
#include "MemMap.h"

#define CANIF_START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/******************************************************************************/
/*!  \Description array contains The lower layer CanDrv pointers to its 
                  services.
*******************************************************************************/
extern CONST(CanIf_tstrCanDrvServicesPCCfg, CANIF_CFG_CONST)
                        CanIf_akstreCanServicesPCCfg
                                    [CanIf_u8NUM_OF_CAN_DRVS];
/******************************************************************************/
/*!  \Description array contains The lower layer Can transceiver Driver pointer
                  to its services.
*******************************************************************************/
#if(CanIf_u8NUM_OF_TRCV_DRVS!=0)
extern CONST(CanIf_tstrTrcvDrvServicesPCCfg, CANIF_CFG_CONST)
                        CanIf_akstreCanTrcvSrvcsPCCfg
                                    [CanIf_u8NUM_OF_TRCV_DRVS];
#endif
#if(CanIf_coSAME_CRITIC_SEC_TX == STD_OFF)
/******************************************************************************/
/*!  \Description array contains The cirtical setction implemented to 
                  protect Tx buffer
*******************************************************************************/

#endif
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
/******************************************************************************/
/*!  \Description array contains The cirtical setction implemented to 
                  protect Rx buffer
*******************************************************************************/
/* PRQA S 3132 ++ */

#endif
/* PRQA S 3132 -- */
#define CANIF_STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


/*-------------------------------- end of file -------------------------------*/
#endif          /*CANIF_LOCALCFG_H*/
          
