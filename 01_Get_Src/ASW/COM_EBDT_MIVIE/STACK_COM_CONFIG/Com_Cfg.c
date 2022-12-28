
/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : Com                                                     */
/* !Description     : Autosar Com module                                      */
/*                                                                            */
/* !Module          : Com                                                     */
/* !Description     : Autosar Com module                                      */
/*                                                                            */
/* !File            : Com_Cfg.c                                               */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/03-Com/02_$*/
/* $Revision::   1.3      $$Author::   ngalal         $$Date::   Dec 04 2011 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
#include "Com_Cfg.h"
#include "Com_Cbk.h"

#define COM_START_CONFIG_DATA_UNSPECIFIED
/* !Deviation: [0838]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 0838 ++ */
#include "Memmap.h"
/* PRQA S 0838 -- */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

#if Com_u16NO_OF_RXIPDU_CALLOUT > 0u
/******************************************************************************/
/*! \Description Com_akpfbeRxIPduCalloutPtrs Array \n
         calculation method: \n
          each entry of this array equals ComIPduCallout of one \n
          of the I-PDU's
          the index of the callout is copied to \n
          ku16IPduCalloutIndex into the corresponding I-PDU \n
          structure in Com_akstrRxIPdu or Com_akstrTxIPdu array \n */
/******************************************************************************/
CONST(Com_tpfbRxIpduCallout, COM_CFG_CONST) Com_akpfbeRxIPduCalloutPtrs[Com_u16NO_OF_RXIPDU_CALLOUT] =
{
    FHCAN_EveRxF572_Callout,
    FHCAN_EveRxF50E_Callout,
    FHCAN_EveRxF552_Callout,
    FHCAN_EveRxF495_Callout,
    FHCAN_EveRxF4F2_Callout,
    FHCAN_EveRxF3C9_Callout,
    FHCAN_EveRxF7F2_Callout,
    FHCAN_EveRxF532_Callout,
    FHCAN_EveRxF492_Callout,
    FHCAN_EveRxF489_Callout,
    FHCAN_EveRxF50D_Callout,
    FHCAN_EveRxF5B2_Callout,
    FHCAN_EveRxF592_Callout,
    FHCAN_EveRxF34D_Callout,
    FHCAN_EveRxF792_Callout,
    FHCAN_EveRxF30D_Callout,
    FHCAN_EveRxF44D_Callout,
    FHCAN_EveRxF305_Callout,
    FHCAN_EveRxF329_Callout,
    FHCAN_EveRxF3CD_Callout,
    FHCAN_EveRxF349_Callout,
    FHCAN_EveRxF3AD_Callout,
    FHCAN_EveRxF4D2_Callout,
    FHCAN_EveRxF57C_Callout,
    FHCAN_EveRxF612_Callout,
    FHCAN_EveRxF4B2_Callout,
    FHCAN_EveRxF38D_Callout,
    FHCAN_EveRxF412_Callout,
    FHCAN_EveRxF432_Callout,
    
};
#endif

#if Com_u16NO_OF_TXIPDU_CALLOUT > 0u
/******************************************************************************/
/*! \Description Com_akpfbeTxIPduCalloutPtrs Array \n
         calculation method: \n
          each entry of this array equals ComIPduCallout of one \n
          of the I-PDU's
          the index of the callout is copied to \n
          ku16IPduCalloutIndex into the corresponding I-PDU \n
          structure in Com_akstrRxIPdu or Com_akstrTxIPdu array \n */
/******************************************************************************/
CONST(Com_tpfbTxIpduCallout, COM_CFG_CONST) Com_akpfbeTxIPduCalloutPtrs[Com_u16NO_OF_TXIPDU_CALLOUT] =
{
    ISCAN_EveTxF228_Callout,
    ISCAN_EveTxF388_Callout,
    
};
#endif


#if Com_u16NO_OF_IPDU_COUNTER > 0u
/******************************************************************************/
/*! \Description Com_akstreIPduCounters\n
         calculation method: \n
          each entry of this array holds the IPduCounterRam of one \n
          of the I-PDU's
          the index of the callout is copied to \n
          ku16IPduCounterIndex into the corresponding I-PDU \n
          structure in Com_akstrRxIPdu or Com_akstrTxIPdu array \n */
/******************************************************************************/
CONST(Com_tstrIPduCounter, COM_CFG_CONST) Com_akstreIPduCounters[Com_u16NO_OF_IPDU_COUNTER] =
{

  /*  V2_BV_3C9 Counter */
  {
    /**********************************************************************/
    /*! \Description ku8IPduCounterSize \n
             Size of PDU Counter expressed in \n
             bits \n
             calculation method: equals ComIPduCounterSize \n
      \Range 1..8  \n */
    /**********************************************************************/
    (uint8) 4,
    
    /**********************************************************************/
    /*! \Description ku16IPduCounterStartPosition \n
             Position of PDU counter expressed in bits from \n
             start position of data content of I-PDU . \n
             calculation method: equals \n
             ComIPduCounterStartPosition \n
      \Range 0..2031  \n */
    /**********************************************************************/
    (uint16) 24,
    
    /**********************************************************************/
    /*! \Description ku8IPduCounterThreshold \n
             Threshold value of I-PDU counter algorithm  \n
             calculation method: equals ComIPduCounterThreshold \n
      \Range 0..255  \n */
    /**********************************************************************/
    (uint8) 1,
  },
  /*  STT_BV_329 Counter */
  {
    /**********************************************************************/
    /*! \Description ku8IPduCounterSize \n
             Size of PDU Counter expressed in \n
             bits \n
             calculation method: equals ComIPduCounterSize \n
      \Range 1..8  \n */
    /**********************************************************************/
    (uint8) 4,
    
    /**********************************************************************/
    /*! \Description ku16IPduCounterStartPosition \n
             Position of PDU counter expressed in bits from \n
             start position of data content of I-PDU . \n
             calculation method: equals \n
             ComIPduCounterStartPosition \n
      \Range 0..2031  \n */
    /**********************************************************************/
    (uint16) 0,
    
    /**********************************************************************/
    /*! \Description ku8IPduCounterThreshold \n
             Threshold value of I-PDU counter algorithm  \n
             calculation method: equals ComIPduCounterThreshold \n
      \Range 0..255  \n */
    /**********************************************************************/
    (uint8) 1,
  },
  /*  V2_BVA_349 Counter */
  {
    /**********************************************************************/
    /*! \Description ku8IPduCounterSize \n
             Size of PDU Counter expressed in \n
             bits \n
             calculation method: equals ComIPduCounterSize \n
      \Range 1..8  \n */
    /**********************************************************************/
    (uint8) 4,
    
    /**********************************************************************/
    /*! \Description ku16IPduCounterStartPosition \n
             Position of PDU counter expressed in bits from \n
             start position of data content of I-PDU . \n
             calculation method: equals \n
             ComIPduCounterStartPosition \n
      \Range 0..2031  \n */
    /**********************************************************************/
    (uint16) 48,
    
    /**********************************************************************/
    /*! \Description ku8IPduCounterThreshold \n
             Threshold value of I-PDU counter algorithm  \n
             calculation method: equals ComIPduCounterThreshold \n
      \Range 0..255  \n */
    /**********************************************************************/
    (uint8) 1,
  },
  /*  CMM_3B8 Counter */
  {
    /**********************************************************************/
    /*! \Description ku8IPduCounterSize \n
             Size of PDU Counter expressed in \n
             bits \n
             calculation method: equals ComIPduCounterSize \n
      \Range 1..8  \n */
    /**********************************************************************/
    (uint8) 4,
    
    /**********************************************************************/
    /*! \Description ku16IPduCounterStartPosition \n
             Position of PDU counter expressed in bits from \n
             start position of data content of I-PDU . \n
             calculation method: equals \n
             ComIPduCounterStartPosition \n
      \Range 0..2031  \n */
    /**********************************************************************/
    (uint16) 52,
    
    /**********************************************************************/
    /*! \Description ku8IPduCounterThreshold \n
             Threshold value of I-PDU counter algorithm  \n
             calculation method: equals ComIPduCounterThreshold \n
      \Range 0..255  \n */
    /**********************************************************************/
    (uint8) 0,
  },
  /*  CMM_228 Counter */
  {
    /**********************************************************************/
    /*! \Description ku8IPduCounterSize \n
             Size of PDU Counter expressed in \n
             bits \n
             calculation method: equals ComIPduCounterSize \n
      \Range 1..8  \n */
    /**********************************************************************/
    (uint8) 4,
    
    /**********************************************************************/
    /*! \Description ku16IPduCounterStartPosition \n
             Position of PDU counter expressed in bits from \n
             start position of data content of I-PDU . \n
             calculation method: equals \n
             ComIPduCounterStartPosition \n
      \Range 0..2031  \n */
    /**********************************************************************/
    (uint16) 28,
    
    /**********************************************************************/
    /*! \Description ku8IPduCounterThreshold \n
             Threshold value of I-PDU counter algorithm  \n
             calculation method: equals ComIPduCounterThreshold \n
      \Range 0..255  \n */
    /**********************************************************************/
    (uint8) 0,
  },
};
#endif

/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */

#define COM_STOP_CONFIG_DATA_UNSPECIFIED
/* !Deviation: [0838]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 0838 ++ */
#include "Memmap.h"
/* PRQA S 0838 -- */

#define COM_START_SEC_VAR_8
/* !Deviation: [0838]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 0838 ++ */
#include "Memmap.h"
/* PRQA S 0838 -- */
/* PRQA L:L1 */

#if Com_u16NO_OF_IPDU_COUNTER > 0u
/******************************************************************************/
/*! \Description Com_au8eIPduCounterRam RAM Array \n
         calculation method: \n
          Memory allocation of number of bytes equal to the number \n
          of configured I-PDU counters \n */
/******************************************************************************/
VAR(Com_tu8IPduCounterRam, COM_VAR) Com_au8eIPduCounterRam[Com_u16NO_OF_IPDU_COUNTER];
#endif

#if Com_u16CTR_ACC_ANY_VAL_SIZE > 0u
/******************************************************************************/
/*! \Description Com_au8eIPduCtrAccAnyValFlg RAM Array \n
         calculation method: \n
          Memory allocation of the number of bytes which can hold \n
          number of bits equal to the number \n
          of configured I-PDU counters \n */
/******************************************************************************/
VAR(uint8, COM_VAR) Com_au8eIPduCtrAccAnyValFlg[Com_u16CTR_ACC_ANY_VAL_SIZE];
#endif

/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */

#define COM_STOP_SEC_VAR_8
/* !Deviation: [0838]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 0838 ++ */
#include "Memmap.h"
/* PRQA S 0838 -- */


#define COM_START_CONFIG_DATA_UNSPECIFIED
/* !Deviation: [0838]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 0838 ++ */
#include "Memmap.h"
/* PRQA S 0838 -- */
/* PRQA L:L1 */

#if Com_u16NO_OF_IPDU_REPLIC > 0u
/******************************************************************************/
/*! \Description Com_akstreIPduReplication Array \n
         calculation method: \n
          each entry of this array holds the IPduReplication of one \n
          of the I-PDU's
          the index of the callout is copied to \n
          ku16IPduReplicationIndex into the corresponding I-PDU \n
          structure in Com_akstrRxIPdu array \n */
/******************************************************************************/
CONST(Com_tstrIPduReplication, COM_CFG_CONST) Com_akstreIPduReplication[Com_u16NO_OF_IPDU_REPLIC] =
{
};
#endif

/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */

#define COM_STOP_CONFIG_DATA_UNSPECIFIED
/* !Deviation: [0838]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 0838 ++ */
#include "Memmap.h"
/* PRQA S 0838 -- */



#define COM_START_SEC_VAR_8
/* !Deviation: [0838]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 0838 ++ */
#include "Memmap.h"
/* PRQA S 0838 -- */
/* PRQA L:L1 */

#if Com_u16NO_OF_IPDU_REPLIC > 0u
/******************************************************************************/
/*! \Description Com_au8eReplicasCounter RAM Array \n
         calculation method: \n
          Memory allocation of number of bytes equal to the number \n
          of I-PDU's which have configured Replicas \n */
/******************************************************************************/
VAR(Com_tu8ReplicasCounter, COM_VAR) Com_au8eReplicasCounter[Com_u16NO_OF_IPDU_REPLIC];
#endif 

/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */

#define COM_STOP_SEC_VAR_8
/* !Deviation: [0838]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 0838 ++ */
#include "Memmap.h"
/* PRQA S 0838 -- */


#define COM_START_CONFIG_DATA_8
/* !Deviation: [0838]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 0838 ++ */
#include "Memmap.h"
/* PRQA S 0838 -- */
/* PRQA L:L1 */

#if Com_u16CANCEL_TX_SPRT_SIZE > 0u
/******************************************************************************/
/*! \Description Com_aku8eCancelTxSupportFlg \n
         calculation method: \n
          each Tx I-PDU's has a bit located at location = its PduId \n
          this bit equals: \n
          TRUE   if ComTxIPduCancelTransmitSupport = TRUE \n
          FALSE  if ComTxIPduCancelTransmitSupport = FALSE \n */
/******************************************************************************/
CONST(uint8, COM_CFG_CONST) Com_aku8eCancelTxSupportFlg[Com_u16CANCEL_TX_SPRT_SIZE] =
{
  (uint8)255,
  (uint8)255,
  (uint8)63,
  (uint8)0,
  (uint8)4,
  (uint8)8,
  (uint8)128,
  (uint8)0,
  (uint8)0
  
};
#endif

/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */
        
#define COM_STOP_CONFIG_DATA_8
/* !Deviation: [0838]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 0838 ++ */
#include "Memmap.h"
/* PRQA S 0838 -- */


#define COM_START_SEC_VAR_8
/* !Deviation: [0838]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 0838 ++ */
#include "Memmap.h"
/* PRQA S 0838 -- */
/* PRQA L:L1 */

#if Com_u16REPLIC_BUFF_SIZE > 0u
/******************************************************************************/
/*! \Description Com_au8eReplicasBuffer \n
         calculation method: \n
          RAM allocation of the sum of all \n
          IPduLength * (ku8NoOfReplicas)   \n */
/******************************************************************************/

VAR(uint8, COM_VAR) Com_au8eReplicasBuffer[Com_u16REPLIC_BUFF_SIZE];
#endif

#define COM_STOP_SEC_VAR_8
/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */
/* !Deviation: [0838]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 0838 ++ */
#include "Memmap.h"
/* PRQA S 0838 -- */
/* PRQA L:L1 */
/* PRQA S 0850 --                                                             */

      
