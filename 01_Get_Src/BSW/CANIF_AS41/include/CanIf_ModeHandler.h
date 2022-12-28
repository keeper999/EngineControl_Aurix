/******************************************************************************/
/*                                                                            */
/* !Layer           : HAL                                                     */
/*                                                                            */
/* !Component       : CanIf                                                   */
/*                                                                            */
/*!\Module          : CanIf_ModeHandler                                       */
/*!\file                : CanIf_ModeHandler.h                                 \n
    \Description        : This subcomponent is responsible for mode handling    
                          related functionalities                             */
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
/* $Revision::   1.10     $$Author::   MTAYMOUR       $$Date::   Mar 31 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
#ifndef CANIF_MODEHANDLER_H
#define CANIF_MODEHANDLER_H
/* PRQA S 3453 ++ */
/*MISRA Msg justification:  Function Like Macro is used here to 
                            simplify Det Error Calling */
#define CanIf_u32GET_WKS_BIT(WakeupSourceIn)      \
                                        (uint32)((0x00000001)<<(WakeupSourceIn))
/* PRQA S 3453 -- */
#define CANIF_START_SEC_CODE
#include "MemMap.h"
/******************************************************************************/
/* !\Function    : CanIf_vidLocalCntrlBusOff                                  \n
   !\Description : This service indicates a Controller BusOff event 
                  referring to the corresponding CAN Controller.              \n
    \param[in]     CanDrvId: the driver Id that this  Controller 
                   mode indication requested from                             \n
    \Range         0..CanIf_u8NUM_OF_CAN_DRVS-1                               \n
    \param[in]     Controller:  CAN controllerId, which state has been 
                   transitioned.                                              \n
    \Range         Maximum Number of Controlers assigned to that CanDrvId     \n
    \return        void                                                       \n
    \Range         N/A                                                        \n
*******************************************************************************/
extern FUNC(void, CANIF_CODE)CanIf_vidLocalCntrlBusOff(
     VAR(uint8, AUTOMATIC) Controller,
	 VAR(uint8, AUTOMATIC) CanDrvId);
/******************************************************************************/
/* !\Function    : CanIf_vidCntrlModeIndic                                    \n
   !\Description : This service indicates a controller state transition 
                   referring to the corresponding CAN controller.             \n
    \param[in]     CanDrvId: the driver Id that this  Controller 
                   mode indication requested from                             \n
    \Range         0..CanIf_u8NUM_OF_CAN_DRVS-1                               \n
    \param[in]     Controller:  CAN controller, which state has been 
                   transitioned.                                              \n
    \Range         Maximum Number of Controlers assigned to that CanDrvId     \n
    \param[in]     ControllerMode:  Mode to which the CAN controller 
                   transitioned                                               \n
    \Range         CANIF_CS_SLEEP,CANIF_CS_STARTED,CANIF_CS_STOPPED           \n
    \return        void                                                       \n
    \Range         N/A                                                        \n
*******************************************************************************/
extern FUNC(void, CANIF_CODE)CanIf_vidCntrlModeIndic(
    VAR(uint8, AUTOMATIC) Controller,
    VAR(CanIf_ControllerModeType, AUTOMATIC) ControllerMode,
	VAR(uint8, AUTOMATIC) CanDrvId);

#if(CanIf_bPUBLIC_PN_SUPPORT == STD_ON)
/******************************************************************************/
/*!\Description :  A call back service that indicates if the transceiver is 
					running in PN communication mode.						  \n
    \param[in]     TransceiverId: Abstracted CanIf TransceiverId,               
                   which is assigned to a CAN transceiver, which is requested   
                   for mode transition                                        \n
    \Range         0..CanIf_u8NUM_OF_TRCVS-1                                  \n
    \param[in]     TransceiverId: CAN transceiver, which state has been           
                   transitioned.                                              \n
    \Range         0.. number oftransceivers assigned to that CanTrcvDrvId    \n
    \return        void														  \n
*******************************************************************************/
#if(CanIf_u8NUM_OF_TRCV_DRVS !=0||CanIf_bDEV_ERR_DETECT==STD_ON)
extern FUNC(void, CANIF_CODE) CanIf_vidLocConfPnAvilable (
	VAR(uint8, AUTOMATIC)  TransceiverId,
	VAR(uint8, AUTOMATIC) CanTrcvDrvId);
#endif
#endif

#if (CanIf_bPUBLIC_PN_SUPPORT == STD_ON)
/******************************************************************************/
/*!\Description :  This service indicates that the transceiver has cleared 
															the WufFlag.	  \n
    \param[in]     CanTrcvDrvId: transceiver driver that this Transceiver is 
                   assignedt to                                               \n
    \Range         0..CanIf_u8NUM_OF_TRCV_DRVS-1                              \n
    \param[in]     TransceiverId: CAN transceiver, which state has been           
                   transitioned.                                              \n
    \Range         0.. number oftransceivers assigned to that CanTrcvDrvId    \n
    \return        void                                                       \n
*******************************************************************************/
#if(CanIf_u8NUM_OF_TRCVS!=0||CanIf_bDEV_ERR_DETECT==STD_ON)
extern FUNC(void, CANIF_CODE)CanIf_vidLocClrWuFlagIndic(
    VAR(uint8, AUTOMATIC) TransceiverId,
	VAR(uint8, AUTOMATIC) CanTrcvDrvId);
#endif
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT == STD_ON)
/******************************************************************************/
/*!\Description :  Requests the CanIf module to check the Wake flag of the 
												designated CAN transceiver.	  \n
    \param[in]     CanTrcvDrvId: transceiver driver that this Transceiver is 
                   assignedt to                                               \n
    \Range         0..CanIf_u8NUM_OF_TRCV_DRVS-1                              \n
    \param[in]     TransceiverId: CAN transceiver, which state has been           
                   transitioned.                                              \n
    \Range         0.. number oftransceivers assigned to that CanTrcvDrvId    \n
    \return        void                                                       \n
*******************************************************************************/
#if(CanIf_u8NUM_OF_TRCVS!=0||CanIf_bDEV_ERR_DETECT==STD_ON)
extern FUNC(void, CANIF_CODE)CanIf_vidLocChkTrcvWFIndic(
    VAR(uint8, AUTOMATIC) TransceiverId,
    VAR(uint8, AUTOMATIC) CanTrcvDrvId);
#endif
#endif
/******************************************************************************/
/* !\Function    : CanIf_TrcvModeIndication                                   \n
   !\Description : This service indicates a transceiver state transition
                   referring to the corresponding CAN transceiver.            \n
    \param[in]     TransceiverId: TransceiverId driver that this Transceiver is 
                   assignedt to                                               \n
    \Range         0..CanIf_u8NUM_OF_TRCV_DRVS-1                              \n
    \param[in]     Transceiver: CAN transceiver, which state has been 
                   transitioned.                                              \n
    \Range         0.. number oftransceivers assigned to that CanTrcvDrvId    \n
    \param[in]     TransceiverMode Mode to which the CAN transceiver 
                   transitioned                                               \n
    \Range         CANTRCV_TRCVMODE_NORMAL,CANTRCV_TRCVMODE_SLEEP,
                   CANTRCV_TRCVMODE_STANDBY                                   \n
    \return        void                                                       \n
    \Range         N/A                                                        \n
*******************************************************************************/
#if(CanIf_u8NUM_OF_TRCVS!=0||CanIf_bDEV_ERR_DETECT==STD_ON)
extern FUNC(void, CANIF_CODE)CanIf_vidLocalTrcvModeIndic(
    VAR(uint8, AUTOMATIC) TransceiverId,
    VAR(CanTrcv_TrcvModeType, AUTOMATIC) TransceiverMode,
	VAR(uint8, AUTOMATIC) CanTrcvDrvId);
#endif

/******************************************************************************/
/*! \Description : This service shall check, if a certain CAN controller 
					supports a requested
					baudrate Please note that this API is deprecated and is 
					kept only for backward compatibility reasons. In the 
					next major release this API will be deleted.              \n
    \param[in]     ControllerId:  CAN Controller to check for the support 
								  of a certain baudrate                       \n
    \Range         0..CanIf_ku8eNumOfControllers-1                            \n
    \param[in]     Baudrate:  Baudrate to check in kbps		                  \n
    \Range														              \n
    \return														              \n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To XYZ_Req                                              
*******************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_CheckBaudrate(
    VAR(uint8, AUTOMATIC) ControllerId,
    CONST(uint16 ,AUTOMATIC)Baudrate);
    
/******************************************************************************/
/*! \Description : This service shall change the baudrate of the CAN controller.
					Please note that this API is deprecated and is 
					kept only for backward compatibility reasons. In the 
					next major release this API will be deleted.              \n
    \param[in]     ControllerId:  CAN Controller to check for the support 
								  of a certain baudrate                       \n
    \Range         0..CanIf_ku8eNumOfControllers-1                            \n
    \param[in]     Baudrate:  Baudrate to check in kbps		                  \n
    \Range														              \n
    \return														              \n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To CANIF-CDD-0672(0)         
*******************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_ChangeBaudrate(
    VAR(uint8, AUTOMATIC) ControllerId,
    CONST(uint16 ,AUTOMATIC)Baudrate);
    
/******************************************************************************/
/*! \Description : This service shall set the baudrate of the CAN controller 
					Please note that this API is deprecated and is 
					kept only for backward compatibility reasons. In the 
					next major release this API will be deleted.              \n
    \param[in]     ControllerId:  CAN Controller to set the baudrate          \n
    \Range         0..CanIf_ku8eNumOfControllers-1                            \n
    \param[in]     Baudrate:  Baudrate to check in kbps		                  \n
    \Range														              \n
    \return														              \n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To XYZ_Req                                              
*******************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_SetBaudrate(
    VAR(uint8, AUTOMATIC) ControllerId,
    CONST(uint16 ,AUTOMATIC)Baudrate);

/******************************************************************************/
/*! \Description : This service shall change the Icom Configuration of a 
				   CAN controller to the requested one.				          \n
    \param[in]     ControllerId:  CAN Controller to set the baudrate for      \n
    \Range         0..CanIf_ku8eNumOfControllers-1                            \n
    \param[in]     ConfigurationId:  Requested Configuration                  \n
    \Range														              \n
    \return														              \n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To XYZ_Req                                              
*******************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_SetIcomConfiguration(
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(IcomConfigIdType ,AUTOMATIC)ConfigurationId);
/******************************************************************************/
/*! \Description : This service shall inform about the change of the 
					Icom Configuration of a CAN controller.			          \n
    \param[in]     ControllerId:  CAN Controller to set the baudrate for      \n
    \Range         0..CanIf_ku8eNumOfControllers-1                            \n
    \param[in]     ConfigurationId:  Requested Configuration                  \n
    \Range		   0..255										              \n
	\param[in]     Error:  Requested Configuration                            \n
    \Range		   ICOM_SWITCH_E_OK, ICOM_SWITCH_E_FAILED		              \n
    \return														              \n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To XYZ_Req                                              
*******************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_CurrentIcomConfiguration(
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(IcomConfigIdType ,AUTOMATIC)ConfigurationId,
	VAR(IcomSwitch_ErrorType ,AUTOMATIC)Error);

#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
/*----------------------------------End Of File ------------------------------*/
#endif
