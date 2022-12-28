/******************************************************************************/
/*                                                                            */
/* !Layer           : HAL                                                    */
/*                                                                            */
/* !Component       : CanIf                                                   */
/* !Description     : It represents the interface to the services of            
                      the CAN Driver for the upper communication layers.      */
/*                                                                            */
/*!\Module          : CanIf_Types                                             */
/*!\file            : CanIf_Types.h                                           \n
    \Description    : defines CanIf Types                                     */
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
/* $Revision::   1.27      $$Author::   mamroussy     $$Date::   Aug 04 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef CANIF_TYPES_H
#define CANIF_TYPES_H

#include"ComStack_Types.h"
#include "Can_GeneralTypes.h"
#include "CanIf_Cfg.h"
#include "CanIf_LocalCfg.h"
#if (CanIf_bWAKUP_SUPPORT == STD_ON)
#include "EcuM_Types.h"
#endif
#include "CanIf_LocalLCfg.h"
/******************************************************************************/
/*                              EXPORTED TYPES                                */
/******************************************************************************/

/******************************************************************************/
/*!  \Description Request for PDU channel group. The request type of the        
                  channel defines it's transmit or receive activity.            
                  Communication direction (transmission and/or reception)       
                  of the channel can be controlled separately or together       
                  by upper layers.
				  (AR4.0.2 Specific Type)
*******************************************************************************/
typedef enum
{
    CANIF_SET_OFFLINE = 0,
    CANIF_SET_ONLINE=1,
    CANIF_SET_RX_OFFLINE=2,
    CANIF_SET_RX_ONLINE=3,
    CANIF_SET_TX_OFFLINE=4,
    CANIF_SET_TX_OFFLINE_ACTIVE=5,
    CANIF_SET_TX_ONLINE=6
}CanIf_PduSetModeType;
/******************************************************************************/
/*!  \Description Status of the PDU channel group. Current mode of the channel  
                  defines its transmit or receive activity. Communication       
                  direction (transmission and/or reception) of the channel      
                  can be controlled separately or together by upper layers.
				  (AR4.0.2 Specific Type)
*******************************************************************************/
typedef enum
{
    CANIF_GET_OFFLINE = 0,
    CANIF_GET_OFFLINE_ACTIVE=1,
    CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE=2,
    CANIF_GET_ONLINE=3,
    CANIF_GET_RX_ONLINE=4,
    CANIF_GET_TX_ONLINE=5
}CanIf_PduGetModeType;

/******************************************************************************/
/*!  \Description The PduMode of a channel defines its transmit or receive 
				  activity. Communication direction (transmission and/or 
				  reception) of the channel can be controlled separately or 
				  together by upper layers.    
*******************************************************************************/
typedef enum
{
    CANIF_OFFLINE = 0,
    CANIF_TX_OFFLINE=1,
    CANIF_TX_OFFLINE_ACTIVE=2,
    CANIF_ONLINE=3
}CanIf_PduModeType;

/******************************************************************************/
/*                              POST-BUILD TYPES                              */
/******************************************************************************/

/******************************************************************************/
/*!  \Description Type of CAN Identifier of the transmit CAN L-PDU used by      
                  the CAN Driver module for CAN L-PDU transmission.             
*******************************************************************************/
typedef enum
{
    CanIf_EXTENDED = 0,
    CanIf_STANDARD=1
}CanIf_tenuCanIdType;
/******************************************************************************/
/*!  \Description Defines the type of each transmit CAN L-PDU                   
*******************************************************************************/
typedef enum
{
    CanIf_STATIC = 0,
    CanIf_DYNAMIC=1
}CanIf_tenuTXPduType;
/******************************************************************************/
/*!  \Description Defines a local type of Can_PduType                  
*******************************************************************************/
typedef struct
{
	PduIdType swPduHandle;
    PduLengthType length;
    Can_IdType id;
	P2VAR(uint8,AUTOMATIC,AUTOSAR_COMSTACKDATA) sdu;
} CanIf_tstrLocalPduType;
/******************************************************************************/
/*!  \Description Structure of Tx Buffering(RAM ARRAY)                          
*******************************************************************************/
typedef struct
{
    /*CanIf_u8EMPTY_BUFFER :empty bufer CanIf_u8ABORTED_TXPDU :cancelled from   
    CanDrv CanIf_u8NEW_TXPDU     :sent from Upper Layer                       */
    VAR(uint8, AUTOMATIC)                       u8TxbufferStatus;
    /*the buffered message                                                    */
    VAR(CanIf_tstrLocalPduType, AUTOMATIC)                 udtBufferedMessage;
}CanIf_tstrTxPduBuffer;


/******************************************************************************/
/*!  \Description Contains the configuration (parameters) of a transmit         
                  CAN L-PDU.                                                    
*******************************************************************************/
typedef struct
{
/* PRQA S 0783 ++ */
/*MISRA Msg justification:  names in Struct may be Repeated in Local Variables*/
    /*CanIfTxPduCfg-->CanIfTxPduHthIdRef index in CanIf_akstreHthLCfg and       
    CanIf_akstrHthTxPduCfg                                                    */
    /*index in  CanIf_akstreHthLCfg array                                     */
    VAR(uint16, AUTOMATIC)                      u16Hth;
    /*CanIfTxPduCfg-->CanIfTxPduCanId                                         */
    VAR(Can_IdType, AUTOMATIC)                  udtCanId;
    /*CanIfTxPduCfg-->CanIfTxPduCanIdType                                     */
    /*EXTENDED_CAN-->CanIf_EXTENDED
    STANDARD_CAN-->CanIf_STANDARD                                             */
    VAR(CanIf_tenuCanIdType, AUTOMATIC)         enuCanIdType;
                    
/* PRQA S 0783 -- */
    /*CanIfTxPduCfg-->CanIfTxPduUserTxConfirmationUL                          */
    /*Link to CanIf_kaudteUlServicesLTCfg pf array                            */
	P2CONST(CanIf_tpfudtTxConfirmation, AUTOMATIC,CANIF_APPL_CONST)
												CanIf_pudteUlId;
	
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
    /*CanIfTxPduCfg-->CanIfTxPduReadNotifyStatus                              */
    /*false-->STD_OFF   true-->STD_ON                                         */
    VAR(boolean, AUTOMATIC)                     bReadNotifyStatus;
    /*If CanIfTxPduCfg-->CanIfTxPduReadNotifyStatus = true a new cell will be   
    added to CanIf_astreDynamicTxPduCanId array and udtNotifyStatusIndex will   
    take a value which is index in CanIf_astreDynamicTxPduCanId array and If    
    CanIfTxPduCfg-->CanIfTxPduReadNotifyStatus = flase value will be 0        */
    VAR(PduIdType, AUTOMATIC)                   udtNotifyStatusIndex;   
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
    /*CanIfTxPduCfg-->CanIfTxPduType                                          */
    /*STATIC-->CanIf_STATIC   DYNAMIC-->CanIf_DYNAMIC                         */
    VAR(CanIf_tenuTXPduType, AUTOMATIC)         enuTXPduType;
    /*If CanIfTxPduCfg-->CanIfTxPduType = true a new cell will be added to      
    CanIf_aenueTxNotifStatus array and udtDyCanIdIndex will take a value which  
    is index in CanIf_aenueTxNotifStatus array and If                           
    CanIfTxPduCfg-->CanIfTxPduType = flase value will be 0                    */
    VAR(PduIdType, AUTOMATIC)                   udtDyCanIdIndex;
#endif
    /*CanIfTxPduCfg-->CanIfTxPduDemEventParameterRefs                         */
    /*if multiplicity 0 configure it with 0xFFFF                              */
    VAR(uint16, AUTOMATIC)                      u16DemESStopped;
    /*CanIfTxPduDemEventParameterRefs-->CanIfTxPduRef-->CANIF_E_STOPPED       */
    /* Pdu Name from PduR_Cfg,CanNm_Cfg,CanTp_Cfg or etc                      */
    VAR(PduIdType, AUTOMATIC)                   udtTxPduRef;
    /*CanIfTxPduCfg-->CanIfTxPduBswSchExclAreaIdRef Exclusive area Id from      
    SchM_CanIf.h                                                              */
	/* Address of Element of Structure CanIf_tstrCriticalSection which contains */
	/* enter and exit function address exculsive areas						   */
#if(CanIf_coSAME_CRITIC_SEC_TX == STD_OFF)
    P2CONST(CanIf_tstrCriticalSection, AUTOMATIC,CANIF_APPL_CONST) 
												CanIf_pudteSchMExclArea;
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
    /*refere to CanIf_astreTxPduBuffer description                            */
	P2VAR(CanIf_tstrTxPduBuffer, AUTOMATIC,CANIF_VAR) 
												CanIf_pudteTxBufferRefer;
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
    /*CanIfTxPduCfg-->CanIfTxPduPnFilterPdu                                         */
	VAR(boolean, AUTOMATIC)						bCanIfTxPduPnFilter;
#endif
}CanIf_tstrTxPduPbCfg;/*CanIfTxPduCfg-->CanIfTxPduId                          */

/******************************************************************************/
/*!  \Description Contains the configuration (parameters) of a Receive          
                  CAN L-PDU.                                                    
*******************************************************************************/
/*CanIfRxPduCfg->CanIfRxPduId*/
typedef struct
{
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
    /*CanIfRxPduCfg-->CanIfRxPduReadData                                      */
    /*false-->STD_OFF   true-->STD_ON                                         */
    VAR(boolean, AUTOMATIC)                     bRxPduReadData;
    /*If CanIfRxPduCfg-->CanIfRxPduReadData = true a new cell will be added to  
    CanIf_astreTxPduBuffer array and udtRxBufferIndex will take a value which is
    index in CanIf_astreTxPduBuffer array and If                                
    CanIfRxPduCfg-->CanIfRxPduReadData = flase value will be 0                */
	P2VAR(PduInfoType, AUTOMATIC,CANIF_VAR) 
												CanIf_pudteRxBufferRefer;
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
    /*CanIfRxPduCfg-->CanIfRxPduReadNotifyStatus                              */
    /*false-->STD_OFF   true-->STD_ON                                         */
    VAR(boolean, AUTOMATIC)                     bReadNotifyStatus;
    /*If CanIfRxPduCfg-->CanIfRxPduReadNotifyStatus = true a new cell will be   
    added to CanIf_aenueRxNotifStatus array and udtNotifyStatusIndex will take  
    a value which is index in CanIf_aenueRxNotifStatus array and                
    If CanIfRxPduCfg-->CanIfRxPduReadNotifyStatus = flase value will be 0     */
    VAR(PduIdType, AUTOMATIC)                   udtNotifyStatusIndex;
#endif
    /*CanIfRxPduCfg-->CanIfRxPduUserRxIndicationUL                            */
    /*Link to CanIf_kaudteUlServicesLTCfg pf array                            */
	P2CONST(CanIf_tstrRxULCfg, AUTOMATIC,CANIF_APPL_CONST) 		CanIf_pudteUlId;
    /*CanIfRxPduCfg-->CanIfRxPduDlc                                           */
    VAR(uint8, AUTOMATIC)                       u8DLC;
    /*CanIfRxPduCfg-->CanIfRxPduDemEventParameterRefs                         */
    /*if multiplicity 0 configure it with 0xFFFF                              */
    VAR(uint16, AUTOMATIC)                      u16DemInvalidDlc;
    /*CanIfRxPduCfg-->CanIfRxPduRef                                           */
    VAR(PduIdType, AUTOMATIC)                   udtRxPduRef;
    /*CanIfRxPduCfg-->CanIfRxPduBswSchExclAreaIdRef Exclusive area Id from      
    SchM_CanIf.h                                                              */
	/* Address of Element of Structure CanIf_tstrCriticalSection which contains */
	/* enter and exit function address exculsive areas						   */
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
    P2CONST(CanIf_tstrCriticalSection, AUTOMATIC,CANIF_APPL_CONST) CanIf_pudteSchMExclArea;
#endif

    /*from CanIfRxPduCfg-->CanIfRxPduHrhIdRef and from                          
    CanIfCtrlCfg-->CanIfCtrlId                                                */
    /*index in CanIf_akstreCtrlLCfg array                                     */
    VAR(uint8, AUTOMATIC)                       u8ControllerId;
}CanIf_tstrRxPduPbCfg;

/******************************************************************************/
/*!  \Description Contains for each Hth The start index of TxPdus               
                  assigned to this Hth in the CanIfTxPduCfg array               
                  and bollean that indicates that at least 1 TxPdu is assigned  
                  to this Hth or not                                            
*******************************************************************************/
typedef struct
{
    /*The start index of TxPdus assigned to this Hth                          */
    /*the start index of this struct in CanIf_akstreRxPduPbCfg array          */
    VAR(PduIdType, AUTOMATIC)                   udtTxpduStartIndex;
    /*At least one TxPdu is assigned to this Hth                              */
    /*if at least one CanIfRxPduCfg->CanIfRxPduId is configured for this        
    CanIfHrhCfg this element= STD_ON else = STD_OFF                           */
    VAR(boolean, AUTOMATIC)                     bHthUsed;
}CanIf_tstrHthTxPduCfg;

/******************************************************************************/
/*!  \Description Contains for each Hrh The start index of Range/Ranges         
                  of Canids Configured for this Hrh , Start Index of RxPdu-CanId
                  Map   assigned to this Hrhand also the Hrh ref on the CanDrv  
*******************************************************************************/
/*CanIfHrhCfg*/
typedef struct
{
    /*The start index of Ranges of CanIds assigned to this HRh                */
    /*if CanIfHrhCfg-->CanIfHrhSoftwareFilter=true                            */
    /*it is index in CanIf_akstreHrhRangePbCfg array                          */
    /*the start index of this struct in CanIf_akstreHrhRangePbCfg array       */
    VAR(uint16, AUTOMATIC)                      u16CanIdRangeSI;
    /*The start index of CanId RxPdu Map assigned to this HRh                 */
    /*index of this CanIfHrhCfg in CanIf_akstreCanIdRxpduMap array            */
    /*the start index of this struct in CanIf_akstreCanIdRxpduMap array       */
    VAR(uint16, AUTOMATIC)                      u16CanIdRxPduMapSI;
    /*At least one RxPdu is assigned to this Hrh                              */
    /*if at least one CanIfRxPduCfg->CanIfRxPduId is configured for this        
    CanIfHrhCfg this element = STD_ON else = STD_OFF                          */
    VAR(boolean, AUTOMATIC)                     bHrhUsed;
    /*CanIfHrhCfg->CanIfHrhIdSymRef                                           */
    VAR(Can_HwHandleType, AUTOMATIC)            udtCanHrhRef;
}CanIf_tstrHrhPbCfg;

/******************************************************************************/
/*!  \Description Contains Range/Ranges for each Hrh                            
*******************************************************************************/
/*CanIfHrhRangeCfg*/
typedef struct
{
    /*The Upper Limit of the Range                                            */
    /*CanIfHrhRangeCfg-->CanIfHrhRangeRxPduUpperCanId                         */
    VAR(Can_IdType, AUTOMATIC)                  udtUpperCanId;
    /*The Lower Limit of the Range                                            */
    /*CanIfHrhRangeCfg-->CanIfHrhRangeRxPduLowerCanId                         */
    VAR(Can_IdType, AUTOMATIC)                  udtLowerCanId;
    /*Type of the Range                                                       */
    /*CanIfHrhRangeCfg-->CanIfHrhRangeRxPduRangeCanIdType                     */
    /*EXTENDED_CAN-->CanIf_EXTENDED,STANDARD_CAN-->CanIf_STANDARD             */
    VAR(CanIf_tenuCanIdType, AUTOMATIC)         udtRangeType;
}CanIf_tstrHrhRangePbCfg;

/******************************************************************************/
/*!  \Description Contains Range of CanIds and corresponding RxPdus for each Hrh
*******************************************************************************/
typedef struct
{
/* PRQA S 0783 ++ */
/*MISRA Msg justification:  names in Struct may be Repeated in Local Variables*/
    /*corresponding RxPdus for each Hrh                                       */
    VAR(PduIdType, AUTOMATIC)                   udtRxPduId;
/* PRQA S 0783 -- */
    /*The Upper Limit of the Range or Singe CanId                             */
    /*CanIfRxPduCanIdRange-->CanIfRxPduCanIdRangeUpperCanId                   */
    VAR(Can_IdType, AUTOMATIC)                  udtUpperCanId;
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
    /*The Lower Limit of the Range                                            */
    /*CanIfRxPduCanIdRange-->CanIfRxPduCanIdRangeLowerCanId                   */
    /*CanIfRxPduCanIdRange-->CanIfRxPduCanIdRangeLowerCanId =                   
    CanIfRxPduCanIdRange-->CanIfRxPduCanIdRangeUpperCanId ,                     
    CanIfRxPduCanIdRange isn't configured Loewr and upper                       
    = CanIfRxPduCfg=CanIfRxPduCanId                                           */
    VAR(Can_IdType, AUTOMATIC)                  udtLowerCanId;
#endif
    /*CanIfRxPduCfg-->CanIfRxPduCanIdType                                     */
    /*EXTENDED_CAN-->CanIf_EXTENDED,    STANDARD_CAN-->CanIf_STANDARD         */
    VAR(CanIf_tenuCanIdType, AUTOMATIC)         udtRxPduCanIdType;
}CanIf_tstrCanIdRxpduMap;



/******************************************************************************/
/*!  \Description Structure of Dynamic TxPdus (RAM ARRAY)                       
*******************************************************************************/
typedef struct
{
/* PRQA S 0783 ++ */
/*MISRA Msg justification:  names in Struct may be Repeated in Local Variables*/
    VAR(Can_IdType, AUTOMATIC)          udtCanId;
    VAR(CanIf_tenuCanIdType, AUTOMATIC) udtCanIdType;
/* PRQA S 0783 -- */
}CanIf_tstrDynamicTxPduCanId;

/******************************************************************************/
/*!  \Description contains the post-build configuration (parameters) of an
                  adressed CAN controller by an underlying CAN Driver module
*******************************************************************************/
/*CanIfCtrlCfg-->CanIfCtrlId is index of composed array*/
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
typedef struct
{
	VAR(boolean, AUTOMATIC)	bPnFilterIsEffective;
}CanIf_tstrCtrlPbCfg;
#endif
/******************************************************************************/
/*!  \Description configuration set, used for post build parameters             
*******************************************************************************/
typedef struct
{
    P2CONST(CanIf_tstrTxPduPbCfg, AUTOMATIC, CANIF_APPL_CONST) 
                                                CanIf_pudtTxPduPbCfg;
    /*size of akstrTxPduPbCfg                                                 */
    CONST(PduIdType, AUTOMATIC)                 CanIf_udtNumofTxPdus;
    P2CONST(CanIf_tstrHthTxPduCfg, AUTOMATIC, CANIF_APPL_CONST)
                                                CanIf_pudtHthTxPduCfg;
#if(CanIf_bTX_BUFFERING==STD_ON)
    P2VAR(CanIf_tstrTxPduBuffer, AUTOMATIC, CANIF_VAR)
                                                pudtTxPduBuffer;
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
    /*Size of CanIf_astreDynamicTxPduCanId                                    */
    P2VAR(CanIf_tstrDynamicTxPduCanId, AUTOMATIC, CANIF_VAR)
                                                pudtDynamicTxPduCanId;
    CONST(PduIdType, AUTOMATIC)                 CanIf_udtSizeOfDynamicTxPdus;
#endif
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
    P2VAR(CanIf_NotifStatusType, AUTOMATIC, CANIF_VAR)
                                                penuTxNotifStatus;
    /*Size of CanIf_aenueTxNotifStatus                                        */
    CONST(PduIdType, AUTOMATIC)
                                                CanIf_udtSizeOfTxNotifStatus;
#endif
    /*size of CanIf_akstreRxPduPbCfg                                          */
    CONST(PduIdType, AUTOMATIC)                 CanIf_udtNumofRxPdus;
    /*Size of CanIf_ku16eNumOfHrh                                             */
    CONST(uint16, AUTOMATIC)CanIf_ku16SizeOfHrhRanges;
    /*Size of  CanIf_akstreCanIdRxpduMap                                      */
    CONST(uint16, AUTOMATIC)                    CanIf_ku16SizeOfCanIdRxPduMap;
                    
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
    /*size of CanIf_aenueRxNotifStatus                                        */
    CONST(PduIdType, AUTOMATIC)                 CanIf_pkudtSizeOfRxNotifStatus;
                    
#endif
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
    /*size of CanIf_astreRxPduBuffer                                          */
    CONST(PduIdType, AUTOMATIC)                 CanIf_pkudtSizeOfRxBuffer;
#endif
    P2CONST(CanIf_tstrHrhPbCfg, AUTOMATIC, CANIF_APPL_CONST)
                                                CanIf_pkudtHrhPbCfg;
    P2CONST(CanIf_tstrRxPduPbCfg, AUTOMATIC, CANIF_APPL_CONST)
                                                CanIf_pudteRxPduPbCfg;
    P2CONST(CanIf_tstrHrhRangePbCfg, AUTOMATIC, CANIF_APPL_CONST)
                                                CanIf_pudteHrhRangePbCfg;
    P2CONST(CanIf_tstrCanIdRxpduMap, AUTOMATIC, CANIF_APPL_CONST)
                                                CanIf_pudteCanIdRxpduMap;
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
    P2CONST(CanIf_tstrCtrlPbCfg, AUTOMATIC, CANIF_APPL_CONST)
                                                CanIf_pkudteCtrlPbCfg;
#endif
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
    P2VAR(PduInfoType, AUTOMATIC, CANIF_VAR)    pudtRxbuffer;
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
    P2VAR(CanIf_NotifStatusType, AUTOMATIC, CANIF_VAR)
                                                penuRxNotifStatus;
#endif

    P2CONST(uint16, AUTOMATIC, CANIF_APPL_CONST) 
                                                CanIf_pku16TxPduMappingPbCfg;

    /* PRQA S  8022,8622 ++ */
}CanIf_ConfigType;
/* PRQA S  8022,8622 -- */



/*-------------------------------- end of file -------------------------------*/
#endif /* CANIF_TYPES_H */
