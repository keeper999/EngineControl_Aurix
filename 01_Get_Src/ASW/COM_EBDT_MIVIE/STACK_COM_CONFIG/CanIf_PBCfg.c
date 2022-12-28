
/******************************************************************************/
/*                                                                            */
/* !Layer           : HAL                                                    */
/*                                                                            */
/* !Component       : CanIf                                                   */
/* !Description     : It represents the interface to the services of 
                      the CAN Driver for the upper communication layers.      */
/*                                                                            */
/*!\Module          : CanIf_PbCfg                                             */
/*!\file            : CanIf_PbCfg.c                                           \n
    \Description    :Responsible for PostBuild Configurations                 */
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
/* $Revision::   1.14     $$Author::   ametwelly      $$Date::   Jun 21 2012 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/* PRQA S 0838 EOF */
/*MISRA Msg justification:   MemMap mechanism is to be included after segment
                             definition*/
/* PRQA S 0862 EOF */
/*MISRA Msg justification:   Constants in header files are referenced
                             as  they are still subs*/

#include"CanIf.h"
#include "CanIf_PBCfg.h"
#include "CanIf_LocalCfg.h"
#if(CanIf_bDEM_ERR_DETECT == STD_ON)
#include"Dem.h"
#endif

#include "Can_17_MCanP_Cfg.h" 

#include "PduR_Cfg.h" 
    
#include "CCPUSR_CanIf_Cfg.h" 
    
#include "Dcm_stub.h" 
    


#define CANIF_START_SEC_CALIB_DATA_8
#include "MemMap.h"
#if(CanIf_bTX_BUFFERING==STD_ON)
/******************************************************************************/
/*!  \Description arrays of Tx Data buffering ,one Buffer for Each TxLPdu
*******************************************************************************/
/*CanIf_CanIf_au8TxPdubufferX is created for each CanIfTxPduCfg instance that   
  its CanIfTxPduHthIdRef points to CanIfHthCfg instance that has                
  CanIfHthCanHandleTypeRef is basic                                           */
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number         
                            used as it cant be Definition because it is         
                            Link-Time or post-Build Configuration             */
/* PRQA S 3233 ++ */
/*MISRA Msg justification:  Tx buffers shouldn't be init and usage is
                            handled in code*/

/* PRQA S 3132 -- */
/* PRQA S 3233 -- */
#endif
/******************************************************************************/
/*!  \Description arrays of Rx Data buffering ,one Buffer for Each RxLPdu       
                  that has bRxPduReadData enabled.                              
*******************************************************************************/
/*CanIf_au8RxPdubufferX is created for each element in CanIfRxPduCfg  that has 
  CanIfRxPduReadData = true                                                   */
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number used as 
                            it cant be Definition because it is Link-Time or    
                            post-Build Configuration                          */
/* PRQA S 3233 ++ */
/*MISRA Msg justification:  Rx buffers shouldn't be init and usage is handled   
                            in code                                           */

/* PRQA S 3132 -- */
/* PRQA S 3233 -- */
#endif
/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */ 
#define CANIF_STOP_SEC_CALIB_DATA_8
#include "MemMap.h"


#define CANIF_START_SEC_CALIB_DATA_UNSPECIFIED
#include "MemMap.h"
/* PRQA L:L1 */ 
#if(CanIf_bTX_BUFFERING==STD_ON)
/******************************************************************************/
/*!  \Description array of Txbuffering that contain the whole messaage buffer   
                  and the State of the buffer Queued /NotQueued and New/Aborted 
*******************************************************************************/
/*one CanIf_astrTxPduBuffer cell is created for each CanIfTxPduCfg instance that
  its CanIfTxPduHthIdRef points to CanIfHthCfg instance that has                
  CanIfHthCanHandleTypeRef is basic and its reference is filled in                  
  akstrTxPduPbCfg.CanIf_pudteTxBufferRefer                                            */
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number used as 
                            it cant be Definition because it is Link-Time or    
                            post-Build Configuration                          */
static VAR (CanIf_tstrTxPduBuffer, CANIF_CALIB_DATA) CanIf_astrTxPduBuffer[0]=
{
};

/* PRQA S 3132 -- */
#endif
/* PRQA S 5087 L1 */ 
#define CANIF_STOP_SEC_CALIB_DATA_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_SEC_CALIB_CONST_UNSPECIFIED
#include "MemMap.h"
/* PRQA L:L1 */ 
/******************************************************************************/
/*!  \Description array that contain Configuration for each TxLPduId            
*******************************************************************************/
/*index of this array is CanIfTxPduCfg-->CanIfTxPduId                         */
/*arranged according to CanIfHthCfg                                           */
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number         
                            used as it cant be Definition because it is         
                            Link-Time or post-Build Configuration             */
/*in case bReadNotifyStatus is configured with STD_OFF udtNotifyStatusIndex 
  will be 0                                                                   */
/*in case enuTXPduType is configured with CanIf_STATIC udtDyCanIdIndex will     
  be 0                                                                        */
/*in case akstrTxPduPbCfg.u16Hth  configured in  CanIf_akstreHthLCfg with       
enuHandleType equal CanIf_FULL akstrTxPduPbCfg.CanIf_pudteTxBufferRefer will be NULL     */

#define u16NO_OF_TX_IPDUS  35  
#if  u16NO_OF_TX_IPDUS > 0u       
static CONST(CanIf_tstrTxPduPbCfg, CANIF_CALIB_CONST) akstrTxPduPbCfg[35]=
/* PRQA S 3132 -- */
{

/******************************************************************************/
/******************************* TxPdu: CMM_108 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  0,  
        /*udtCanId                          */  0x108,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  6,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CMM_388 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  1,  
        /*udtCanId                          */  0x388,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  18,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CMM_3B8 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  2,  
        /*udtCanId                          */  0x3B8,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  3,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CMM_348 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  3,  
        /*udtCanId                          */  0x348,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  7,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CMM_208 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  4,  
        /*udtCanId                          */  0x208,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  21,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CMM_488 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  5,  
        /*udtCanId                          */  0x488,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  9,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: STT_CMM_3C8 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  6,  
        /*udtCanId                          */  0x3C8,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  4,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CMM_468 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  7,  
        /*udtCanId                          */  0x468,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  19,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CMM_588 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  8,  
        /*udtCanId                          */  0x588,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  1,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: EAC_CMM_UCC_0E8 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  9,  
        /*udtCanId                          */  0xE8,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  13,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: RQD_CMM_UCC_0E8 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  10,  
        /*udtCanId                          */  0xE8,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  11,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: EAC_CMM_BSI_072 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  11,  
        /*udtCanId                          */  0x72,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  10,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CMM_608 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  12,  
        /*udtCanId                          */  0x608,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  2,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: RQD_CMM_BSI_072 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  13,  
        /*udtCanId                          */  0x72,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  22,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: JDD_CAN_CMM_768 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  14,  
        /*udtCanId                          */  0x768,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  14,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: NEW_JDD_CMM_768 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  15,  
        /*udtCanId                          */  0x768,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  20,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CanTpTxNPdu_7E8 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  16,  
        /*udtCanId                          */  0x7E8,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[12], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  2,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CMM_228 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  17,  
        /*udtCanId                          */  0x228,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  16,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CanTpTxNPdu_688 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  18,  
        /*udtCanId                          */  0x688,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[11], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  
            CDD_CanTpTxNPdu_688,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CMM_7A8 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  19,  
        /*udtCanId                          */  0x7A8,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  8,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CCP_PMH ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  20,  
        /*udtCanId                          */  0x7CC,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[10], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  
            CDD_CCP_PMH,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CCP_10MS ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  21,  
        /*udtCanId                          */  0x7CD,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[3], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  
            CDD_CCP_10MS,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CCP_100MS ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  22,  
        /*udtCanId                          */  0x7CE,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[2], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  
            CDD_CCP_100MS,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CCP_1000MS ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  23,  
        /*udtCanId                          */  0x7CF,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[1], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  
            CDD_CCP_1000MS,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CCP_DEVAID_DTO ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  24,  
        /*udtCanId                          */  0x101,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[7], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  
            CDD_CCP_DEVAID_DTO,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CCP_DEVAID_10MS ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  25,  
        /*udtCanId                          */  0x102,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[6], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  
            CDD_CCP_DEVAID_10MS,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CCP_DEVAID_PMH ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  26,  
        /*udtCanId                          */  0x103,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[8], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  
            CDD_CCP_DEVAID_PMH,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CCP_DEVAID_100MS ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  27,  
        /*udtCanId                          */  0x104,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[5], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  
            CDD_CCP_DEVAID_100MS,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CCP_DTO ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  28,  
        /*udtCanId                          */  0x728,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[9], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  
            CDD_CCP_DTO,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CCP_DEVAID_1000MS ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  29,  
        /*udtCanId                          */  0x105,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[4], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  
            CDD_CCP_DEVAID_1000MS,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CMM_788 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  30,  
        /*udtCanId                          */  0x788,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  5,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CMM_1E8 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  31,  
        /*udtCanId                          */  0x1E8,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  17,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CMM_5F8 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  32,  
        /*udtCanId                          */  0x5F8,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  15,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CMM_438 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  33,  
        /*udtCanId                          */  0x438,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  12,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
/******************************************************************************/
/******************************* TxPdu: CMM_BV_2E8 ***********************************/
/******************************************************************************/
    {
        /*u16Hth                            */  34,  
        /*udtCanId                          */  0x2E8,     
        /*enuCanIdType                      */  CanIf_STANDARD,  
        /*CanIf_pudteUlId                   */  &CanIf_akpfvideUlTxConfrimLTCfg[13], 
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,  
        /*udtNotifyStatusIndex              */  0,
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        /*enuTXPduType                      */  CanIf_STATIC,
        /*udtDyCanIdIndex                   */  0,
#endif
        /*u16DemESStopped                   */  (uint16)0xFFFF,
        /*udtTxPduRef                       */  0,
#if(CanIf_coSAME_CRITIC_SEC_TX ==STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreTxBuffCriticalSec[0],
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*CanIf_pudteTxBufferRefer          */  NULL_PTR,
#endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
/*bCanIfTxPduPnFilter*/FALSE
#endif
    },
            
};

/******************************************************************************/
/*!  \Description array that contain mapping between TxPduId and index of the
  array akstrTxPduPbCfg. 
*******************************************************************************/
static CONST(uint16, CANIF_CALIB_CONST) aku16TxPduMapping[35] =
{
  5,
         34,
         8,
         23,
         12,
         2,
         6,
         30,
         0,
         3,
         19,
         33,
         11,
         16,
         20,
         9,
         14,
         32,
         17,
         31,
         22,
         1,
         7,
         18,
         4,
         15,
         28,
         29,
         27,
         26,
         10,
         13,
         21,
         24,
         25,
         
};
#endif

/******************************************************************************/
/*!  \Description array that contain Configuration for each Hth                 
                  Contain the start Index of TxPdus assigned to that Hth        
*******************************************************************************/
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number
                            used as it cant be Definition because it is
                            Link-Time or post-Build Configuration             */
/*in case bHthUsed is configured with STD_OFF udtTxpduStartIndex will be 0    */

#define u16NO_OF_HTHS 35
#if u16NO_OF_HTHS > 0u        
static CONST(CanIf_tstrHthTxPduCfg, CANIF_CALIB_CONST) akstrHthTxPduCfg[35]=
/* PRQA S 3132 -- */
{
    
/******************************************************************************/
/********************************* HTH  ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  0,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 1 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  1,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 2 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  2,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 3 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  3,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 4 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  4,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 5 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  5,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 6 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  6,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 7 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  7,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 8 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  8,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 9 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  9,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 10 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  10,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 11 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  11,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 12 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  12,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 13 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  13,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 14 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  14,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 15 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  15,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 16 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  16,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 17 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  17,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 18 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  18,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 19 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  19,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 20 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  20,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 21 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  21,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 22 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  22,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 23 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  23,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 24 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  24,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 25 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  25,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 26 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  26,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 27 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  27,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 28 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  28,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 29 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  29,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 30 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  30,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 31 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  31,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 32 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  32,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 33 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  33,          
        /*bHthUsed                          */  STD_ON
    },

/******************************************************************************/
/********************************* HTH 34 ***********************************/
/******************************************************************************/
    {
        /*udtTxpduStartIndex                */  34,          
        /*bHthUsed                          */  STD_ON
    },

};
#endif

#define CANIF_STOP_SEC_CALIB_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_SEC_CALIB_CONST_16 
#include "MemMap.h"
/******************************************************************************/
/*!  \Description array that contain Configuration for each Hrh                 
*******************************************************************************/
/*CanIfHrhCfg this array is sorted according to CanDrv                        */
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number         
                            used as it cant be Definition because it is         
                            Link-Time or post-Build Configuration             */
/*in case bHrhSwFilter in CanIf_akstreHrhLCfg is configured with STD_OFF        
u16CanIdRangeSI will be 0                                                     */

        
#define u16_NO_HRHS  42
#if u16_NO_HRHS > 0u
static CONST(CanIf_tstrHrhPbCfg, CANIF_CALIB_CONST) akstrHrhPbCfg[42]=
/* PRQA S 3132 -- */
{
    
/******************************************************************************/
/********************************* HRH 0 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  0,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  36
    },

/******************************************************************************/
/********************************* HRH 1 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  1,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  21
    },

/******************************************************************************/
/********************************* HRH 2 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  2,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  11
    },

/******************************************************************************/
/********************************* HRH 3 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  3,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  38
    },

/******************************************************************************/
/********************************* HRH 4 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  4,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  39
    },

/******************************************************************************/
/********************************* HRH 5 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  5,    
        /*bHrhUsed                          */  STD_OFF, 
        /*udtCanHrhRef                      */  24
    },

/******************************************************************************/
/********************************* HRH 6 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  5,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  3
    },

/******************************************************************************/
/********************************* HRH 7 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  6,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  0
    },

/******************************************************************************/
/********************************* HRH 8 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  7,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  13
    },

/******************************************************************************/
/********************************* HRH 9 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  8,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  34
    },

/******************************************************************************/
/********************************* HRH 10 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  9,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  16
    },

/******************************************************************************/
/********************************* HRH 11 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  10,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  25
    },

/******************************************************************************/
/********************************* HRH 12 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  11,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  44
    },

/******************************************************************************/
/********************************* HRH 13 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  12,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  15
    },

/******************************************************************************/
/********************************* HRH 14 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  13,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  43
    },

/******************************************************************************/
/********************************* HRH 15 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  14,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  12
    },

/******************************************************************************/
/********************************* HRH 16 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  15,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  5
    },

/******************************************************************************/
/********************************* HRH 17 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  16,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  6
    },

/******************************************************************************/
/********************************* HRH 18 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  17,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  45
    },

/******************************************************************************/
/********************************* HRH 19 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  18,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  7
    },

/******************************************************************************/
/********************************* HRH 20 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  19,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  23
    },

/******************************************************************************/
/********************************* HRH 21 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  20,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  2
    },

/******************************************************************************/
/********************************* HRH 22 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  21,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  33
    },

/******************************************************************************/
/********************************* HRH 23 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  22,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  31
    },

/******************************************************************************/
/********************************* HRH 24 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  23,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  18
    },

/******************************************************************************/
/********************************* HRH 25 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  24,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  19
    },

/******************************************************************************/
/********************************* HRH 26 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  25,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  37
    },

/******************************************************************************/
/********************************* HRH 27 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  26,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  17
    },

/******************************************************************************/
/********************************* HRH 28 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  27,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  28
    },

/******************************************************************************/
/********************************* HRH 29 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  28,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  29
    },

/******************************************************************************/
/********************************* HRH 30 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  29,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  8
    },

/******************************************************************************/
/********************************* HRH 31 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  30,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  27
    },

/******************************************************************************/
/********************************* HRH 32 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  31,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  26
    },

/******************************************************************************/
/********************************* HRH 33 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  32,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  20
    },

/******************************************************************************/
/********************************* HRH 34 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  33,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  1
    },

/******************************************************************************/
/********************************* HRH 35 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  34,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  30
    },

/******************************************************************************/
/********************************* HRH 36 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  35,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  4
    },

/******************************************************************************/
/********************************* HRH 37 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  36,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  10
    },

/******************************************************************************/
/********************************* HRH 38 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  37,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  9
    },

/******************************************************************************/
/********************************* HRH 39 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  38,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  35
    },

/******************************************************************************/
/********************************* HRH 40 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  39,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  22
    },

/******************************************************************************/
/********************************* HRH 41 ***********************************/
/******************************************************************************/
    {
        /*u16CanIdRangeSI                   */  0,    
        /*u16CanIdRxPduMapSI                */  40,    
        /*bHrhUsed                          */  STD_ON, 
        /*udtCanHrhRef                      */  32
    },

};
#endif

#define CANIF_STOP_SEC_CALIB_CONST_16 
#include "MemMap.h"


/******************************************************************************/
/*!  \Description array of Rxbuffering that contain the whole messaage buffer   
                  Data Array Buffer and Data Length                             
*******************************************************************************/
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
/*One Cell is created in this array for each CanIfRxPduCfg-->CanIfRxPduReadData 
=true and this cell's reference will be filled in CanIfRxPduCfg-->CanIf_pudteRxBufferRefer*/
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number used as 
it cant be Definition because it is Link-Time or post-Build Configuration     */
static VAR (PduInfoType, CANIF_CALIB_DATA) CanIf_astrRxPduBuffer[0]=
{

};
        
/* PRQA S 3132 -- */
#endif


#define CANIF_START_SEC_CALIB_DATA_UNSPECIFIED
#include "MemMap.h"

/******************************************************************************/
/*!  \Description array that contain Configuration for each RxLPduId
*******************************************************************************/
/*CanIfRxPduCfg                                                               */
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number
                            used as it cant be Definition because it is
                            Link-Time or post-Build Configuration             */
/*in case bRxPduReadData is configured with STD_OFF CanIf_pudteRxBufferRefer will be NULL */
/*in case bReadNotifyStatus is configured with STD_OFF udtNotifyStatusIndex will
  be 0                                                                        */

#define u16_NO_RX_PDUS  41
#if u16_NO_RX_PDUS > 0u       
static CONST(CanIf_tstrRxPduPbCfg, CANIF_CALIB_CONST) akstrRxPduPbCfg[41]=
/* PRQA S 3132 -- */

{
       


         
/******************************************************************************/
/******************************* ABR_38D ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  22,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* ABR_44D ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  23,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* ABR_50D ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  13,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* BSI_412 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  8,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* BSI_432 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  21,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* BSI_4F2 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  4,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* BSI_572 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  0,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* BSI_592 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  15,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* BSI_612 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  25,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* BSI_792 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  17,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* BSI_CMM_0A8 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  5,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  26,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* CCP_CRO ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[1],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  
            CDD_CCP_CRO,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* CCP_DEVAID_CRO ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[2],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  
            CDD_CCP_DEVAID_CRO,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  1
    },
     


         
/******************************************************************************/
/******************************* CDS_34D ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  16,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* CLIM_50E ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  1,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* CONTEXTE_1_5B2 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  14,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* CONTEXTE_1_7F2 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  6,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* CRASH_4C8 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  3,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  7,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* CanTpRxNPdu_7DF ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[4],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  2,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* CanTpRxNPdu_7E0 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[4],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  3,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* CanTpRxNPdu_7FF ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[4],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  1,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* DAT_BSI_532 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  3,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  9,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* DIRA_495 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  4,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  3,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* DMTR_57C ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  6,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  32,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* EASY_MOVE_3AD ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  33,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* ELECTRON_BSI_092 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  1,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  19,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* FRE_30D ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  18,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* FRE_3CD ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  29,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* JDD_CAN_BSI_772 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  1,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  30,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* NEW_JDD_55F ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  1,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  10,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* RXCanTpRxNPdu_6A8 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[3],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  
            CDD_RXCanTpRxNPdu_6A8,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* STT_BV_329 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  4,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  28,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* UCC_CMM_0E0 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  5,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  27,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* V2_BSI_552 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  5,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  2,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* V2_BVA_349 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  31,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* V2_BV_3C9 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  5,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* V2_BV_489 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  12,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* VDS_BSI_492 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  6,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  11,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* VIS_BSI_4B2 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  8,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  20,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* VOL_305 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  7,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  24,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     


         
/******************************************************************************/
/******************************* WMI_BSI_4D2 ***********************************/
/******************************************************************************/
    {
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
        /*bRxPduReadData                    */  STD_OFF,    
        /*CanIf_pudteRxBufferRefer          */  NULL_PTR,
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
        /*bReadNotifyStatus                 */  STD_OFF,    
        /*udtNotifyStatusIndex              */  0,
#endif
       /*CanIf_pudteUlId                    */  &CanIf_akstreUlRxLTCfg[5],    
        /*u8DLC                             */  3,    
        /*u16DemInvalidDlc                  */  0xFFFF,       
    
        /*udtRxPduRef                       */  34,
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        /*CanIf_pudteSchMExclArea           */  &CanIf_akstreRxBuffCriticalSec[0],
#endif
        /*u8ControllerId                    */  0
    },
     
};
#endif

        
/******************************************************************************/
/*!  \Description Contains Range/Ranges for each Hrh
*******************************************************************************/
/*CanIfHrhRangeCfg this array is sorted according to CanIfHrhCfg              */
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number         
                            used as it cant be Definition because it is         
                            Link-Time or post-Build Configuration             */

#define u16NO_OF_HRH_RANGES 0
#if u16NO_OF_HRH_RANGES > 0u        
static CONST(CanIf_tstrHrhRangePbCfg, CANIF_CALIB_CONST) akstrHrhRangePbCfg[0]=
/* PRQA S 3132 -- */
{

/******************************************************************************/
/**************************** Ranges for HRH 0 ********************************/
/******************************************************************************/      
  
};
#endif

/******************************************************************************/
/*!  \Description Contains Range of CanIds and corresponding RxPdus for each Hrh
*******************************************************************************/
/*CanIfRxPduCanIdRange*/
/*should be arranged according to CanIfHrhCfg and for each CanIfHrhCfg
  it should be arranged according to 
  CanIfRxPduCanIdRangeLowerCanId and CanIfRxPduCanIdRangeUpperCanId*/
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number
                            used as it cant be Definition because it is
                            Link-Time or post-Build Configuration */


#define u16CAN_ID_RX_PDU_MAP 41   
#if u16CAN_ID_RX_PDU_MAP > 0u
static CONST(CanIf_tstrCanIdRxpduMap, CANIF_CALIB_CONST) akstrCanIdRxpduMap[41]=
/* PRQA S 3132 -- */
{

/******************************************************************************/
/************************ RxPdus Assigned to HRH 0 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  0,
        /*udtUpperCanId                     */  909,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  909,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 1 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  1,
        /*udtUpperCanId                     */  1101,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1101,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 2 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  2,
        /*udtUpperCanId                     */  1293,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1293,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 3 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  3,
        /*udtUpperCanId                     */  1042,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1042,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 4 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  4,
        /*udtUpperCanId                     */  1074,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1074,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 6 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  5,
        /*udtUpperCanId                     */  1266,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1266,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 7 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  6,
        /*udtUpperCanId                     */  1394,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1394,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 8 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  7,
        /*udtUpperCanId                     */  1426,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1426,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 9 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  8,
        /*udtUpperCanId                     */  1554,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1554,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 10 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  9,
        /*udtUpperCanId                     */  1938,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1938,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 11 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  10,
        /*udtUpperCanId                     */  168,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  168,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 12 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  11,
        /*udtUpperCanId                     */  1800,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1800,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 13 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  13,
        /*udtUpperCanId                     */  845,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  845,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 14 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  14,
        /*udtUpperCanId                     */  1294,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1294,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 15 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  15,
        /*udtUpperCanId                     */  1458,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1458,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 16 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  16,
        /*udtUpperCanId                     */  2034,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  2034,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 17 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  17,
        /*udtUpperCanId                     */  1224,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1224,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 18 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  12,
        /*udtUpperCanId                     */  256,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  256,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 19 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  21,
        /*udtUpperCanId                     */  1330,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1330,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 20 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  30,
        /*udtUpperCanId                     */  1704,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1704,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 21 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  22,
        /*udtUpperCanId                     */  1173,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1173,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 22 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  23,
        /*udtUpperCanId                     */  1404,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1404,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 23 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  24,
        /*udtUpperCanId                     */  941,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  941,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 24 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  25,
        /*udtUpperCanId                     */  146,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  146,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 25 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  18,
        /*udtUpperCanId                     */  2015,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  2015,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 26 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  19,
        /*udtUpperCanId                     */  2016,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  2016,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 27 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  26,
        /*udtUpperCanId                     */  781,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  781,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 28 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  27,
        /*udtUpperCanId                     */  973,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  973,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 29 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  28,
        /*udtUpperCanId                     */  1906,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1906,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 30 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  29,
        /*udtUpperCanId                     */  1375,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1375,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 31 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  31,
        /*udtUpperCanId                     */  809,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  809,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 32 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  32,
        /*udtUpperCanId                     */  224,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  224,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 33 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  20,
        /*udtUpperCanId                     */  2047,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  2047,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 34 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  33,
        /*udtUpperCanId                     */  1362,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1362,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 35 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  34,
        /*udtUpperCanId                     */  841,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  841,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 36 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  35,
        /*udtUpperCanId                     */  969,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  969,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 37 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  36,
        /*udtUpperCanId                     */  1161,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1161,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 38 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  37,
        /*udtUpperCanId                     */  1170,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1170,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 39 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  38,
        /*udtUpperCanId                     */  1202,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1202,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 40 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  39,
        /*udtUpperCanId                     */  773,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  773,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
/******************************************************************************/
/************************ RxPdus Assigned to HRH 41 ****************************/
/******************************************************************************/
          
    {
        /*udtRxPduId                        */  40,
        /*udtUpperCanId                     */  1234,
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
        /*udtLowerCanId                     */  1234,
#endif
        /*udtRxPduCanIdType                 */  CanIf_STANDARD
    },
          
};
#endif

/******************************************************************************/
/*!  \Description array contains the configuration (parameters) of an
                  addressed CAN controller
*******************************************************************************/
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
static CONST(CanIf_tstrCtrlPbCfg, CANIF_CALIB_CONST) akstreCtrlPbCfg[2]=
{
/******************************************************************************/
/******************************* Controller CanIfCtrlDrvCfg/CanIf_Controller_Can_InterSystem *********************************/
/******************************************************************************/
    {
/*bPnTxfilter_is_effective*/FALSE   
    },
/******************************************************************************/
/******************************* Controller CanIfCtrlDrvCfg/CanIf_Controller_Can_devaid *********************************/
/******************************************************************************/
    {
/*bPnTxfilter_is_effective*/FALSE   
    }
};
#endif

#define CANIF_STOP_SEC_CALIB_DATA_UNSPECIFIED
#include "MemMap.h"

/******************************************************************************/
/*!  \Description array of CanIds that is assigned to Dynamic TxLpdus           
*******************************************************************************/
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
/*One Cell is created in this array for each                                    
  CanIfTxPduCfg-->CanIfTxPduCfg-->CanIfTxPduType=true and this cell's index will
  be filled in CanIfTxPduCfg-->udtDyCanIdIndex                                */
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number used as 
                            it cant be Definition because it is Link-Time or    
                            post-Build Configuration                          */
#define u16NO_OF_DYN_TX_CAN_IDS 0
#if u16NO_OF_DYN_TX_CAN_IDS > 0u        
static VAR (CanIf_tstrDynamicTxPduCanId, CANIF_CALIB_DATA) 
                CanIf_astrDynamicTxPduCanId[0];
#endif
#endif
/* PRQA S 3132 -- */
/******************************************************************************/
/*!  \Description array of notification Status for each RxLPdu                  
*******************************************************************************/
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
/*One Cell is created in this array for each                                    
  CanIfTxPduCfg-->CanIfTxPduReadNotifyStatus=true and this cell's index will be 
  filled in CanIfTxPduCfg-->udtNotifyStatusIndex                              */
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number
                            used as it cant be Definition because it is
                            Link-Time or post-Build Configuration */
static VAR (CanIf_NotifStatusType, CANIF_CALIB_DATA) 
                CanIf_aenuTxNotifStatus[0];
/* PRQA S 3132 -- */
#endif
/******************************************************************************/
/*!  \Description array of notification Status for each TxLPdu                  
*******************************************************************************/
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
/*One Cell is created in this array for each                                    
CanIfRxPduCfg-->CanIfRxPduReadNotifyStatus=true and this cell's index will be   
filled in CanIfTxPduCfg-->udtNotifyStatusIndex                                */
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number used as 
                            it cant be Definition because it is Link-Time or    
                            post-Build Configuration                          */
static VAR (CanIf_NotifStatusType, CANIF_CALIB_DATA) 
                CanIf_aenuRxNotifStatus[0];
/* PRQA S 3132 -- */
#endif




#define CANIF_START_SEC_CALIB_CONST_UNSPECIFIED
#include "MemMap.h"

/* PRQA L:L1 */ 
/******************************************************************************/
/*!  \Description configuration set, used for post build parameters 
*******************************************************************************/
CONST (CanIf_ConfigType, CANIF_CALIB_CONST) akstrConfig[CanIf_u8NUM_OF_PB_CFGS] =
{
    {
        #if u16NO_OF_TX_IPDUS > 0u    
            /*TxPdu Config Array                        */  akstrTxPduPbCfg,
        #else 
            (P2CONST(CanIf_tstrTxPduPbCfg, AUTOMATIC, CANIF_APPL_CONST)) NULL_PTR,
        #endif
            /*Size of TxPdu Config Array                */  35,                             
            /*Number Of Instances of CanIfTxPduCfg      
              Container                                 */
        #if u16NO_OF_HTHS > 0u    
            /*Hth TxPdu Cinfig Array                    */  akstrHthTxPduCfg,
        #else
            (P2CONST(CanIf_tstrHthTxPduCfg, AUTOMATIC, CANIF_APPL_CONST)) NULL_PTR,
        #endif    
        #if(CanIf_bTX_BUFFERING==STD_ON)
            /*TxPdu buffers Array                       */  CanIf_astrTxPduBuffer,
        #endif
        #if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
        #if u16NO_OF_DYN_TX_CAN_IDS > 0u    
            /*TxPdus Dynamic CanIds Array               */  CanIf_astrDynamicTxPduCanId,
        #else
            (P2VAR(CanIf_tstrDynamicTxPduCanId, AUTOMATIC, CANIF_VAR)) NULL_PTR,
        #endif    
            /*Size of TxPdus Dynamic CanIds Array       */  0,                         
            /*Number Of Instances of CanIfTxPduCfg that 
              Has CanIfTxPduType is DYNAMIC             */
        #endif
        #if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
            /*TxPdu Notification Status Array           */  CanIf_aenuTxNotifStatus,
            /*Size Of TxPdu Notification Status Array   */  0,                         
            /*Number Of Instances of CanIfTxPduCfg that 
              Has CanIfTxPduReadNotifyStatus is true    */
        #endif
            /*Size of RxPdu Config Array                */  41,                         /*the number of instances of 
                                          CanIfRxPduCfg container*/
            /*Size of HRH Ranges Array                  */  0,                         /*number of instances of 
                                          CanIfHrhRangeCfg container*/
            /*Size Of RxPdu CanId Map Array             */  41,                         /*number of instances of 
                                          CanIfRxPduCanIdRange container*/
        #if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
             /*Size Of RxPdu Notification Status Array  */  0,                         /*number of instances of 
                                          CanIfRxPduCfg that has 
                                          CanIfRxPduReadNotifyStatus 
                                          parameter eual true*/
        #endif
        #if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
            /*Size Of RxPdus Buffers Array              */  0,                         /*number of instances of CanIfRxPduCfg that has 
                                          CanIfRxPduReadData parameter equal true*/
        #endif
        #if u16_NO_HRHS > 0u    
            /*HRH Post-Build Config Array               */  akstrHrhPbCfg,
        #else
            (P2CONST(CanIf_tstrHrhPbCfg, AUTOMATIC, CANIF_APPL_CONST)) NULL_PTR,
        #endif    
        #if u16_NO_RX_PDUS > 0u    
            /*RxPdu Config Array                        */  akstrRxPduPbCfg,
        #else
            (P2CONST(CanIf_tstrRxPduPbCfg, AUTOMATIC, CANIF_APPL_CONST)) NULL_PTR,
        #endif
        #if u16NO_OF_HRH_RANGES > 0u
            /*Hrh Ranges Config Array                   */  akstrHrhRangePbCfg,
        #else 
            (P2CONST(CanIf_tstrHrhRangePbCfg, AUTOMATIC, CANIF_APPL_CONST)) NULL_PTR,
        #endif
        #if u16CAN_ID_RX_PDU_MAP > 0u
            /*RxPdu CanId Map Config Array              */  akstrCanIdRxpduMap,
        #else
            (P2CONST(CanIf_tstrCanIdRxpduMap, AUTOMATIC, CANIF_APPL_CONST)) NULL_PTR,
        #endif
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
        /* Controller configuration array          */  akstreCtrlPbCfg,
#endif
        #if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
            /*RxPdus Buffers Array                      */  CanIf_astrRxPduBuffer,
        #endif
        #if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
            /*RxPdu Notification Status Array           */  CanIf_aenuRxNotifStatus,
        #endif
        #if u16NO_OF_TX_IPDUS > 0u    
            /*TxPdu Mapping Array                       */  aku16TxPduMapping
        #else 
            (P2CONST(uint16, AUTOMATIC, CANIF_APPL_CONST)) NULL_PTR
        #endif
    }
};

#define CANIF_STOP_SEC_CALIB_CONST_UNSPECIFIED
#include "MemMap.h"
/* PRQA L:L1 */ 
          
