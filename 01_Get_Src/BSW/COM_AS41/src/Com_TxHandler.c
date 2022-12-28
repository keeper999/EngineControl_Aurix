/* !Deviation: [0790]  usage of floating point is not avoidable because it is
    mandated by AUTOSAR */
/* PRQA S 0790 ++ */
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : Com                                                     */
/* !Description     : AUTOSAR Communication Module                            */
/*                                                                            */
/* !Module          : Com                                                     */
/*                                                                            */
/* !File            : Com_TxHandler.c                                         */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : ALL                                                     */
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
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/03-Com/02$ */
/* $Revision::   1.229    $$Author::   ametwelly      $$Date::   Aug 24 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file Com_TxHandler.c
*
* \par
*   Internals of TxHandler Sub-Component.
*   This file contains the internals of TxHandler Sub-Component. */
/******************************************************************************/

/******************************************************************************/
/*! \defgroup module Com
* This is the grouping of the Com module members.
* \{
*/
/******************************************************************************/

#include"Com.h"
#include"Com_Cbk.h"
#include"Com_Internal.h"
#include "Com_Cfg.h"
#include "Com_LCfg.h"
#include "PduR_Com.h"
#include "SchM_Com.h"

#include "Com_PackSig.h"

#if (COM_DEV_ERROR_DETECT == STD_ON)
  #include "Det.h"
#endif /* COM_DEV_ERROR_DETECT */
/******************************************************************************/
/* Intermodule Version Checking */

#if (COM_bINTER_MOD_VER_CHECK == STD_ON)

/* Check versus MemMap */
#ifdef MEM_AR_RELEASE_MAJOR_VERSION
#ifdef MEM_AR_RELEASE_MINOR_VERSION
/* Major version check */
#if (MEM_AR_RELEASE_MAJOR_VERSION != COM_AR_RELEASE_MAJOR_VERSION)
#error "MEMMAP AR RELEASE MAJOR VERSION is not compatible with \
COM AR RELEASE MAJOR VERSION"
#endif
/* Minor version check */
#if (MEM_AR_RELEASE_MINOR_VERSION > COM_AR_RELEASE_MINOR_VERSION)
#error "MEMMAP AR RELEASE MINOR VERSION is not compatible with \
COM AR RELEASE MINOR VERSION"
#endif
#else
#error "MEMMAP AR RELEASE MINOR VERSION not defined"
#endif
#else
#error "MEMMAP AR RELEASE MAJOR VERSION not defined"
#endif
/******************************************************************************/
/* Check versus SchM */
#ifdef SCHM_AR_RELEASE_MAJOR_VERSION
#ifdef SCHM_AR_RELEASE_MINOR_VERSION
/* Major version check */
#if (SCHM_AR_RELEASE_MAJOR_VERSION != COM_AR_RELEASE_MAJOR_VERSION)
#error "SCHM AR RELEASE MAJOR VERSION is not compatible with \
COM AR RELEASE MAJOR VERSION"
#endif
/* Minor version check */
#if (SCHM_AR_RELEASE_MINOR_VERSION > COM_AR_RELEASE_MINOR_VERSION)
#error "SCHM AR RELEASE MINOR VERSION is not compatible with \
COM AR RELEASE MINOR VERSION"
#endif
#else
#error "SCHM AR RELEASE MINOR VERSION not defined"
#endif
#else
#error "SCHM AR RELEASE MAJOR VERSION not defined"
#endif
/******************************************************************************/
/* Check versus Det */
#if (COM_DEV_ERROR_DETECT == STD_ON)
#ifdef DET_AR_RELEASE_MAJOR_VERSION
#ifdef DET_AR_RELEASE_MINOR_VERSION
/* Major version check */
#if (DET_AR_RELEASE_MAJOR_VERSION != COM_AR_RELEASE_MAJOR_VERSION)
#error "DET AR RELEASE MAJOR VERSION is not compatible with \
COM AR RELEASE MAJOR VERSION"
#endif
/* Minor version check */
#if (DET_AR_RELEASE_MINOR_VERSION > COM_AR_RELEASE_MINOR_VERSION)
#error "DET AR RELEASE MINOR VERSION is not compatible with \
COM AR RELEASE MINOR VERSION"
#endif
#else
#error "DET AR RELEASE MINOR VERSION not defined"
#endif
#else
#error "DET AR RELEASE MAJOR VERSION not defined"
#endif
#endif /*(COM_DEV_ERROR_DETECT == STD_ON)*/

#endif /* #if (COM_bINTER_MOD_VER_CHECK == STD_ON) */

/******************************************************************************/

/* !Deviation: [3453]  the following functions like macros , helps to increase
the readability of the code , by accessing the required configuration parameter
, through a macro . Macros were used instead of functions in order to increase
the code performance  by reducing the time required by the context switching*/
/* PRQA S 3453 ++ */


/* !Deviation: [3456]  cfg_ptr macro argument will be reevaluated each time it
is used in the macro expansion. it is dangerous only if cfg_ptr is passed as
expression whish is not the case here. */
/* PRQA S 3456 ++ */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */


/*! \Description  MACRO used to Get I-PDU index */
#if (Com_bPB_VARIANT == STD_ON)
#define u16IPDU_GET_IX(pdu_id) \
                Com_pkstreMainConfig->pkstrIPduLookUp[pdu_id].u16Index
#else
#define u16IPDU_GET_IX(pdu_id) \
                akstrIPduLookUp[pdu_id].u16Index
#endif

/*! \Description  MACRO used to check if TxMode switch is applicable \n
                  for TX I-PDU */
#define bTX_IPDU_GET_TMS_FLAG(TxIPdu_Ptr) \
          (((TxIPdu_Ptr)->udteTxIPduFlags & Com_u8TX_IPDUTMS_MASK) != FALSE)

#if (Com_bPB_VARIANT == STD_ON)		  
#define bTXIPDU_GET_TMS_FLAG(pdu_index) \
          ((Com_pkstreMainConfig->pkstrTxIPdu[(pdu_index)].udteTxIPduFlags & Com_u8TX_IPDUTMS_MASK) != FALSE)
#else
#define bTXIPDU_GET_TMS_FLAG(pdu_index) \
          ((akstrTxIPdu[(pdu_index)].udteTxIPduFlags & Com_u8TX_IPDUTMS_MASK) != FALSE)
#endif
		  

/*! \Description  MACRO used to check if the structure type from Signal ID \n
                  returns one of the following \n
                      COM_u8SIG_STRUCTURE_TYPE_SIGNAL          \n
                      COM_u8SIG_STRUCTURE_TYPE_GROUPSIGNAL     \n
                      COM_u8SIG_STRUCT_SRCDESC                 \n
                      Com_u8SIG_STRUCT_DSTDESC */

/*! \Description  MACRO used to Get Signal index fron look up array */
#if (Com_bPB_VARIANT == STD_ON)
#define u16SIG_GET_LKUP_IX(sig_id) \
          Com_pkstreMainConfig->pkstrSignalLookUp[(sig_id)].u16Index
#else
#define u16SIG_GET_LKUP_IX( sig_id) \
          akstrSignalLookUp[(sig_id)].u16Index
#endif

/*! \Description  MACRO used to get callout pointer for TX I-PDU */
#if Com_u16NO_OF_TXIPDU_CALLOUT > 0u
#define pfTXIPDU_GET_CALOUTPTR(Callout_index) \
        Com_akpfbeTxIPduCalloutPtrs[Callout_index]
#else
#define pfTXIPDU_GET_CALOUTPTR(Callout_index) \
                                    (Com_tpfbTxIpduCallout) NULL_PTR
#endif



/*! \Description  MACRO used to get type of TX I-PDU */
#define bTXIPDU_GET_TYPE(TxIPduPtr) \
          (((TxIPduPtr)->udteTxIPduFlags & Com_u8TX_IPDUTYPE_MASK) != FALSE)
		  

/*! \Description  MACRO used to get u16SignalId member of
GroupSignal */
#if Com_u16NO_OF_GROUP_SIGSLT > 0u
  #define u16GET_G_SIG_ID(group_sig_ix) \
              Com_akstreGroupSignalLT[(group_sig_ix)].u16SignalId
#else
#define u16GET_G_SIG_ID(group_sig_ix) (uint16)0
#endif

	  
	  

#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PB_SIGGRP_PTR(u16SigGrpId) \
	(&( Com_pkstreMainConfig->pkstrSignalGroupPB[(u16SigGrpId)]))
#else
#if u16NO_OF_SIGNAL_GROUPS > 0u
#define pkstrGET_PB_SIGGRP_PTR(u16IPduId) \
		(&(akstrSignalGroupPB[(u16SigGrpId)]))
#else
#define pkstrGET_PB_SIGGRP_PTR(u16IPduId) \
		(P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif




#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_GW_MAP_SIG_PTR(u16SignalMappIndex) \
(&(Com_pkstreMainConfig->pkstrGWSignalMapping[u16SignalMappIndex]))
#else
#if u16NO_OF_GW_PATHS > 0u
#define pkstrGET_GW_MAP_SIG_PTR(u16SignalMappIndex) \
(&(akstrGWSignalMapping[u16SignalMappIndex]))

#else
#define pkstrGET_GW_MAP_SIG_PTR(u16SignalMappIndex) \
	(P2CONST(Com_tstrGWSignalMapping,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_IPDU_SIG_MAP_PTR(u16Index) \
		(&(Com_pkstreMainConfig->pkstrIPduToSignalMapping[u16Index]))
#else
#if u16NO_OF_SIG_ALL_TYPES > 0u
#define pkstrGET_IPDU_SIG_MAP_PTR(u16Index) \
	     (&(akstrIPduToSignalMapping[u16Index]))
#else
#define pkstrGET_IPDU_SIG_MAP_PTR(u16Index) \
		(P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PB_SIGNAL_PTR(u16SigIx) \
(&(Com_pkstreMainConfig->pkstrSignalPB[u16SigIx]))
#else
#define pkstrGET_PB_SIGNAL_PTR(u16SigIx) \
(&(akstrSignalPB[u16SigIx]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define udtGET_PB_INIT_IPDUSTATUS(u16IpduId) \
(Com_pkstreMainConfig->pkudteInitIPduStatus[u16IpduId])
#else
#define udtGET_PB_INIT_IPDUSTATUS(u16IpduId) \
(Com_audteInitIPduStatus[u16IpduId])
#endif




#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PB_DST_DESC_PTR(u16SigIx) \
	(&(Com_pkstreMainConfig->pkstrGWDstDesc[(u16SigIx)]))
#else
#if u16NO_OF_GW_DST_DESC > 0u
#define pkstrGET_PB_DST_DESC_PTR(u16SigIx) \
(&(akstrGWDstDesc[(u16SigIx)]))
#else
#define pkstrGET_PB_DST_DESC_PTR(u16SigIx) \
	(P2CONST(Com_tstrGWDstDesc,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_TX_IPDUPTR_BYID(u16IPduId) \
(&(Com_pkstreMainConfig->pkstrTxIPdu[Com_pkstreMainConfig->pkstrIPduLookUp[(u16IPduId)].u16Index]))
#else
#define pkstrGET_TX_IPDUPTR_BYID(u16IPduId) \
(&(akstrTxIPdu[akstrIPduLookUp[(u16IPduId)].u16Index]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pu8TXIPDU_GET_BUFF_PTR(IPdu_Buff_ix) \
          (&(Com_pkstreMainConfig->pu8IPduBuffer[(IPdu_Buff_ix)]))
#else
#if u16IPDUS_BYTE_LENGTH > 0u
#define pu8TXIPDU_GET_BUFF_PTR(IPdu_Buff_ix) \
          (&(Com_au8IPduBuffer[(IPdu_Buff_ix)]))

#else
#define pu8TXIPDU_GET_BUFF_PTR(IPdu_Buff_ix) \
		(P2VAR(uint8,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define u16TXIPDU_SET_TPBYTECNT(IpduTpCtr_Ix, value) \
          (Com_pkstreMainConfig->pu16TpByteCounter[(IpduTpCtr_Ix)] = (value))
#else
#if u16NO_OF_TP_IPDU > 0u
#define u16TXIPDU_SET_TPBYTECNT(IpduTpCtr_Ix, value) \
          (Com_au16TpByteCounter[(IpduTpCtr_Ix)] = (value))
#else
#define u16TXIPDU_SET_TPBYTECNT(IpduTpCtr_Ix, value) 0u
#endif
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define pku32GET_MD_TIMER(u16MDTimerIx) \
	(&(Com_pkstreMainConfig->pu32MDTimer[(u16MDTimerIx)]))
#else
#if u16NO_OF_MDT > 0u
#define pku32GET_MD_TIMER(u16MDTimerIx) \
		(&(Com_au32MDTimer[(u16MDTimerIx)]))
#else
#define pku32GET_MD_TIMER(u16MDTimerIx) \
		(P2VAR(Com_tu32MDTimer,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif




#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PB_GRP_SIG_PTR(u16SigIx) \
(&( Com_pkstreMainConfig->pkstrGroupSignalPB[(u16SigIx)]))
#else
#if u16NO_OF_GROUP_SIGNALS > 0u
#define pkstrGET_PB_GRP_SIG_PTR(u16SigIx) \
(&(akstrGroupSignalPB[(u16SigIx)]))
#else
#define pkstrGET_PB_GRP_SIG_PTR(u16SigIx)  \
	(P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define u8MIXTXMODE_GET_PTR(mode_index) \
		(&(Com_pkstreMainConfig->pkstrTxModeMixed[mode_index]))
#else
#if u16NO_OF_TX_M_MIXED > 0u
#define u8MIXTXMODE_GET_PTR(mode_index) \
		(&(akstrTxModeMixed[mode_index]))
#else
#define u8MIXTXMODE_GET_PTR(mode_index) \
		(P2CONST(Com_tstrTxModeMixed,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif	   
	   


#if (Com_bPB_VARIANT == STD_ON)
#define u8DIRTXMODE_GET_PTR(mode_index) \
		(&(Com_pkstreMainConfig->pkstrTxModeDirect[mode_index]))
#else
#if u16NO_OF_TX_M_DIRECT > 0u 
#define u8DIRTXMODE_GET_PTR(mode_index) \
		(&(akstrTxModeDirect[mode_index]))
#else
#define u8DIRTXMODE_GET_PTR(mode_index) \
	(P2CONST(Com_tstrTxModeDirect,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif
	   
	   

#if (Com_bPB_VARIANT == STD_ON)
#define u8TXMODE_GET_REPCTR(RepCtrIx) \
       Com_pkstreMainConfig->pu8TxModeRepetitionsCtr[RepCtrIx]
#else
#if u16NO_OF_TX_M_COUNTERS > 0u
#define u8TXMODE_GET_REPCTR(RepCtrIx) \
       Com_au8TxModeRepetitionsCtr[RepCtrIx]
#else
#define u8TXMODE_GET_REPCTR(RepCtrIx) 0u
#endif
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define u8TXMODE_DEC_REPCTR(RepCtrIx) \
        ((Com_pkstreMainConfig->pu8TxModeRepetitionsCtr[RepCtrIx]) \
          = ( ((Com_pkstreMainConfig->pu8TxModeRepetitionsCtr[RepCtrIx]) - ((uint8)1) )))
#else
#if u16NO_OF_TX_M_COUNTERS > 0u 
#define u8TXMODE_DEC_REPCTR(RepCtrIx) \
        ((Com_au8TxModeRepetitionsCtr[RepCtrIx]) \
          = ( ((Com_au8TxModeRepetitionsCtr[RepCtrIx]) - ((uint8)1) )))
#else
#define u8TXMODE_DEC_REPCTR(RepCtrIx)
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_TX_IPDU_PTR(u16IPduIx) \
(&(Com_pkstreMainConfig->pkstrTxIPdu[(u16IPduIx)]))
#else
#define pkstrGET_TX_IPDU_PTR(u16IPduIx) \
(&(akstrTxIPdu[(u16IPduIx)]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define u8IPDU_GET_TXMODE_PTR(TxModeIx) \
          (&(Com_pkstreMainConfig->pkstrTxMode[(TxModeIx)]))
#else
#if u16NO_OF_TX_MODES > 0u
#define u8IPDU_GET_TXMODE_PTR(TxModeIx) \
          (&(akstrTxMode[(TxModeIx)]))
#else
#define u8IPDU_GET_TXMODE_PTR(TxModeIx) \
		(P2CONST(Com_tstrTxMode,AUTOMATIC,TYPEDEF))NULL_PTR
#endif	
#endif		



#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PB_TIMEOUT_TIMER(TimeoutIx) \
(&(Com_pkstreMainConfig->pu32TimeOutTimer[(TimeoutIx)]))
#else
#if u16NO_OF_TIMEOUT > 0u
#define pkstrGET_PB_TIMEOUT_TIMER(TimeoutIx) \
(&(Com_au32TimeOutTimer[(TimeoutIx)]))
#else
#define pkstrGET_PB_TIMEOUT_TIMER(TimeoutIx) \
	(P2VAR(uint32,AUTOMATIC,TYPEDEF))NULL_PTR
#endif	
#endif

			
#if (Com_bPB_VARIANT == STD_ON)
#define u8IPDU_GET_DIR(pdu_id) \
             Com_pkstreMainConfig->pkstrIPduLookUp[(pdu_id)].u8Direction
#else
#define u8IPDU_GET_DIR(pdu_id) \
             akstrIPduLookUp[(pdu_id)].u8Direction
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define u8TXIPDU_GET_TYPE(u16IPduIx) \
          ((Com_pkstreMainConfig->pkstrTxIPdu[(u16IPduIx)].udteTxIPduFlags & Com_u8TX_IPDUTYPE_MASK) != FALSE)
#else
#define u8TXIPDU_GET_TYPE(u16IPduIx) \
          ((akstrTxIPdu[(u16IPduIx)].udteTxIPduFlags & Com_u8TX_IPDUTYPE_MASK) != FALSE)
#endif

		  

#if (Com_bPB_VARIANT == STD_ON)		  
#define u16TXIPDU_CLR_TP_BYTCTR(pdu_index) \
          (Com_pkstreMainConfig->pu16TpByteCounter[Com_pkstreMainConfig->\
					pkstrTxIPdu[(pdu_index)].u16TpIPduByteCtrIndex]\
											= (uint16)0)
#else
#if u16NO_OF_TP_IPDU > 0u
#define u16TXIPDU_CLR_TP_BYTCTR(pdu_index) \
          (Com_au16TpByteCounter[akstrTxIPdu[(pdu_index)].u16TpIPduByteCtrIndex]\
											= (uint16)0)

#else
#define u16TXIPDU_CLR_TP_BYTCTR(pdu_index)
#endif
#endif
			
			
#if (Com_bPB_VARIANT == STD_ON)	
#define u16IPDU_GET_MAP_SIGIX(map_index) \
          Com_pkstreMainConfig->pkstrIPduToSignalMapping[map_index].u16Index
#else
#define u16IPDU_GET_MAP_SIGIX(map_index) \
          akstrIPduToSignalMapping[map_index].u16Index
#endif

#if (Com_bPB_VARIANT == STD_ON)	
#define u8SIG_GET_TYPE(sig_index) \
          Com_pkstreMainConfig->pkstrSignalPB[sig_index].u8SignalType
#else
#define u8SIG_GET_TYPE(sig_index) \
          akstrSignalPB[sig_index].u8SignalType
#endif


#if (Com_bPB_VARIANT == STD_ON)	
#define u16TXIPDU_GET_TPBYTECNT(u16TpCtrIx) \
          Com_pkstreMainConfig->pu16TpByteCounter[(u16TpCtrIx)]
		  
#else
#if u16NO_OF_TP_IPDU > 0u
#define u16TXIPDU_GET_TPBYTECNT(u16TpCtrIx) \
          Com_au16TpByteCounter[(u16TpCtrIx)]
#else
#define u16TXIPDU_GET_TPBYTECNT(u16TpCtrIx) 0
#endif
#endif



#if (Com_bPB_VARIANT == STD_ON)	
#define u16TXIPDU_CLR_TPBYTECNT(u16TpCtrIx) \
          (Com_pkstreMainConfig->pu16TpByteCounter[(u16TpCtrIx)] = (uint16)0)
#else
#if u16NO_OF_TP_IPDU > 0u
#define u16TXIPDU_CLR_TPBYTECNT(u16TpCtrIx) \
          (Com_au16TpByteCounter[(u16TpCtrIx)] = (uint16)0)
#else
#define u16TXIPDU_CLR_TPBYTECNT(u16TpCtrIx) (u16TpCtrIx = 0)
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)					
#define u8SIG_GET_STRUCT_TYPE(sig_id) \
        Com_pkstreMainConfig->pkstrSignalLookUp[(sig_id)].u8StructureType
#else
#define u8SIG_GET_STRUCT_TYPE(sig_id) \
        akstrSignalLookUp[(sig_id)].u8StructureType
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define u8GSIG_GET_DIR(sig_index) \
      ((Com_pkstreMainConfig->pkstrGroupSignalPB[(sig_index)].udteGroupSignalFlags & Com_u8GRPSIGNAL_DIRECTION) != FALSE)
	  
#else
#if u16NO_OF_GROUP_SIGNALS > 0u
#define u8GSIG_GET_DIR(sig_index) \
      ((akstrGroupSignalPB[(sig_index)].udteGroupSignalFlags & Com_u8GRPSIGNAL_DIRECTION) != FALSE)
#else
#define u8GSIG_GET_DIR(sig_index) 0u
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define u8SIG_GET_DIR(sig_index) \
          ((Com_pkstreMainConfig->pkstrSignalPB[(sig_index)].udteSignalFlags & Com_u8SIGNAL_DIRECTION) != FALSE)
#else
#define u8SIG_GET_DIR(sig_index) \
          ((akstrSignalPB[(sig_index)].udteSignalFlags & Com_u8SIGNAL_DIRECTION) != FALSE)
#endif		  


#if (Com_bPB_VARIANT == STD_ON)
#define pku32GET_TX_MODE_TIMER(TxModeTimerIx) \
(&(Com_pkstreMainConfig->pu32TxModeTimer[(TxModeTimerIx)]))
#else
#if u16NO_OF_TX_MODE_TIMERS > 0u
#define pku32GET_TX_MODE_TIMER(TxModeTimerIx) \
(&(Com_au32TxModeTimer[(TxModeTimerIx)]))
#else
#define pku32GET_TX_MODE_TIMER(TxModeTimerIx)	\
	(P2VAR(Com_tu32TxModeTimer,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif	
  



#if (Com_bPB_VARIANT == STD_ON)
#define u8PERTXMODE_GET_PTR(mode_index) \
		(&(Com_pkstreMainConfig->pkstrTxModePeriodic[(mode_index)]))
#else
#if u16NO_OF_TX_M_PERIODIC > 0u
#define u8PERTXMODE_GET_PTR(mode_index) \
		(&(akstrTxModePeriodic[(mode_index)]))
#else
#define u8PERTXMODE_GET_PTR(mode_index)	\
	(P2CONST(Com_tstrTxModePeriodic,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif	



#if (Com_bPB_VARIANT == STD_ON)
#define u8TXMODE_RLD_REPCTR(TxModePtr) \
        ((Com_pkstreMainConfig->pu8TxModeRepetitionsCtr[((TxModePtr)->u16RepetitionsCtrIndex)]) \
          = ((TxModePtr)->u8NumberOfRepetitions))
#else
#if u16NO_OF_TX_M_COUNTERS > 0u
#define u8TXMODE_RLD_REPCTR(TxModePtr) \
        ((Com_au8TxModeRepetitionsCtr[((TxModePtr)->u16RepetitionsCtrIndex)]) \
          = ((TxModePtr)->u8NumberOfRepetitions))
#else
#define u8TXMODE_RLD_REPCTR(TxModePtr)
#endif
#endif




#if (Com_bPB_VARIANT == STD_ON)
#define pku32RLD_PERIODIC_MOD_TMR(TxModePtr) \
      ((Com_pkstreMainConfig->pu32TxModeTimer[(TxModePtr)->u16RepetitionPrdTmrIx]) = \
          ((TxModePtr)->u32RepetitionPeriod)-((uint32)1))
			
#else
#if u16NO_OF_TX_MODE_TIMERS > 0u
#define pku32RLD_PERIODIC_MOD_TMR(TxModePtr) \
      ((Com_au32TxModeTimer[(TxModePtr)->u16RepetitionPrdTmrIx]) = \
          ((TxModePtr)->u32RepetitionPeriod)-((uint32)1))	
#else
#define pku32RLD_PERIODIC_MOD_TMR(TxModePtr)
#endif
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define u8SIG_GET_TX_PROP(sig_index) \
          ((uint8)((Com_pkstreMainConfig->pkstrSignalPB[(sig_index)].udteSignalFlags & Com_u8SIGNAL_TXPROPERTY) >> 2))
		  
#else
#define u8SIG_GET_TX_PROP(sig_index) \
          ((uint8)((akstrSignalPB[(sig_index)].udteSignalFlags & Com_u8SIGNAL_TXPROPERTY) >> 2))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define u16DSTDESC_GET_SIG_ID(sig_index) \
          Com_pkstreMainConfig->pkstrGWDstDesc[(sig_index)].u16SignalId		
#else
#if u16NO_OF_GW_DST_DESC > 0u
#define u16DSTDESC_GET_SIG_ID(sig_index) \
          akstrGWDstDesc[(sig_index)].u16SignalId			
#else
#define u16DSTDESC_GET_SIG_ID(sig_index) 0
#endif	  
#endif


/*! \Description  MACRO used to get transfer property of  DstDesc */

#if (Com_bPB_VARIANT == STD_ON)
#define u8DSTDESC_GET_TX_PROP(sig_index) \
              ((uint8)((Com_pkstreMainConfig->pkstrGWDstDesc[sig_index].udteSignalFlags & Com_u8SIGNAL_TXPROPERTY) >> 2))
#else
#if u16NO_OF_GW_DST_DESC > 0u
#define u8DSTDESC_GET_TX_PROP(sig_index) \
              ((uint8)((akstrGWDstDesc[sig_index].udteSignalFlags & Com_u8SIGNAL_TXPROPERTY) >> 2))
#else
#define u8DSTDESC_GET_TX_PROP(sig_index) 0
#endif	
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define u16SIG_GET_IPDU_ID(sig_index) \
              (Com_pkstreMainConfig->pkstrSignalPB[(sig_index)].u16IPduIndex)
#else
#define u16SIG_GET_IPDU_ID(sig_index) \
              (akstrSignalPB[(sig_index)].u16IPduIndex)
#endif

/*! \Description  MACRO used to get type of signal */
#if (Com_bPB_VARIANT == STD_ON)
#define u8GSIG_GET_TYPE(sig_index) \
         Com_pkstreMainConfig->pkstrGroupSignalPB[sig_index].u8SignalType
#else
#if u16NO_OF_GROUP_SIGNALS > 0u
#define u8GSIG_GET_TYPE(sig_index) \
          akstrGroupSignalPB[sig_index].u8SignalType
#else
#define u8GSIG_GET_TYPE(sig_index) 0u
#endif
#endif
		  
		
/*! \Description  MACRO used to Get Signal group direction */
#if (Com_bPB_VARIANT == STD_ON)
#define u8SIGG_GET_DIR(sig_index) \
          ((Com_pkstreMainConfig-> \
              pkstrSignalGroupPB[(sig_index)].udteSignalGroupFlags & Com_u8SIGNALGRP_DIRECTION) != FALSE)
#else
#if u16NO_OF_SIGNAL_GROUPS > 0u
#define u8SIGG_GET_DIR(sig_index) \
          ((akstrSignalGroupPB[(sig_index)].udteSignalGroupFlags & Com_u8SIGNALGRP_DIRECTION) != FALSE)			  
#else
#define u8SIGG_GET_DIR(sig_index) 0u
#endif	  
#endif		



#if (Com_bPB_VARIANT == STD_ON)
#define u16GET_SIG_GRP_UPDAT_BT(sig_Gro_index) \
          Com_pkstreMainConfig->pkstrSignalGroupPB[(sig_Gro_index)].u16UpdateBitPosition
#else
#if u16NO_OF_SIGNAL_GROUPS > 0u
#define u16GET_SIG_GRP_UPDAT_BT(sig_Gro_index) \
          akstrSignalGroupPB[(sig_Gro_index)].u16UpdateBitPosition;
#else
#define u16GET_SIG_GRP_UPDAT_BT(sig_Gro_index) 0u
#endif
#endif




/*! \Description  MACRO used to get transfer property of signal */
#if (Com_bPB_VARIANT == STD_ON)
#define u8SIGG_GET_TX_PROP(sig_index) \
		  ((uint8)(Com_pkstreMainConfig->pkstrSignalGroupPB[(sig_index)].udteSignalGroupFlags & Com_u8SIGNALGRP_TXPROPERTY))
#else
#if u16NO_OF_SIGNAL_GROUPS > 0u
#define u8SIGG_GET_TX_PROP(sig_index) \
		  ((uint8)(akstrSignalGroupPB[(sig_index)].udteSignalGroupFlags & Com_u8SIGNALGRP_TXPROPERTY))
#else
#define u8SIGG_GET_TX_PROP(sig_index) 0u
#endif
#endif



/*! \Description  MACRO used to Clear Repetition Counter */

#if (Com_bPB_VARIANT == STD_ON)
#define u8TXMODE_CLR_REPCTR(TxMode) \
      ((Com_pkstreMainConfig->pu8TxModeRepetitionsCtr \
        [(TxMode)->u16RepetitionsCtrIndex ]) = \
          (uint8)0)
#else
#if u16NO_OF_TX_M_COUNTERS > 0u
#define u8TXMODE_CLR_REPCTR(TxMode) \
      ((Com_au8TxModeRepetitionsCtr \
        [(TxMode)->u16RepetitionsCtrIndex ]) = \
          (uint8)0)
#else

#define  u8TXMODE_CLR_REPCTR(TxMode) 
#endif
#endif		  
/*! \Description  MACRO used to Clear Repetition Counter */


#if (Com_bPB_VARIANT == STD_ON)
#define u8MIXTXMODE_CLR_REPCTR(mode_index) \
      ((Com_pkstreMainConfig->pu8TxModeRepetitionsCtr \
        [Com_pkstreMainConfig->pkstrTxModeMixed[(mode_index)].u16RepetitionsCtrIndex ]) = \
          (uint8)0)
#else
#if ((u16NO_OF_TX_M_COUNTERS > 0u) && (u16NO_OF_TX_M_MIXED > 0u))
#define u8MIXTXMODE_CLR_REPCTR(mode_index) \
      ((Com_au8TxModeRepetitionsCtr \
        [akstrTxModeMixed[(mode_index)].u16RepetitionsCtrIndex]) = \
          (uint8)0)
#else
#define u8MIXTXMODE_CLR_REPCTR(mode_index)
#endif	  
#endif
		  
		  
#if (Com_bPB_VARIANT == STD_ON)
#define u8DIRTXMODE_CLR_REPCTR(mode_index) \
      ((Com_pkstreMainConfig->pu8TxModeRepetitionsCtr \
        [Com_pkstreMainConfig->pkstrTxModeDirect[(mode_index)].u16RepetitionsCtrIndex ]) = \
          (uint8)0)
#else
#if ((u16NO_OF_TX_M_COUNTERS > 0u) && (u16NO_OF_TX_M_MIXED > 0u))
#define u8DIRTXMODE_CLR_REPCTR(mode_index) \
      ((Com_au8TxModeRepetitionsCtr \
        [akstrTxModeDirect[(mode_index)].u16RepetitionsCtrIndex]) = \
          (uint8)0)


#else
#define u8DIRTXMODE_CLR_REPCTR(mode_index)
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define u16TXIPDU_GET_LENGTH(pdu_index) \
          Com_pkstreMainConfig->pkstrTxIPdu[(pdu_index)].u16IPduLength
#else
#define u16TXIPDU_GET_LENGTH(pdu_index) \
          akstrTxIPdu[(pdu_index)].u16IPduLength
		  
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define pkB_GET_SIG_OBJ_VALUEB(u16SigObjIx) \
	(&(Com_pkstreMainConfig->pbSignalObjectB[(u16SigObjIx)]))
#else
#if u16NO_OF_SIG_B_OBJ > 0u
#define pkB_GET_SIG_OBJ_VALUEB(u16SigObjIx) \
		(&(Com_au8SignalObjectB[(u16SigObjIx)]))
#else
#define pkB_GET_SIG_OBJ_VALUEB(u16SigObjIx) \
		(P2VAR(boolean,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pku8GET_SIG_OBJ_VALUEU8(u16SigObjIx) \
	(&(Com_pkstreMainConfig->pu8SignalObjectU8U8N[(u16SigObjIx)]))
#else
#if u16NO_OF_SIG_U8U8N_OBJ > 0u
#define pku8GET_SIG_OBJ_VALUEU8(u16SigObjIx) \
		(&(Com_au8SignalObjectU8U8N[(u16SigObjIx)]))
#else
#define pku8GET_SIG_OBJ_VALUEU8(u16SigObjIx) \
		(P2VAR(uint8,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define pks8GET_SIG_OBJ_VALUES8(u16SigObjIx) \
	(&(Com_pkstreMainConfig->ps8SignalObjectS8[(u16SigObjIx)]))
#else
#if u16NO_OF_SIG_S8_OBJ > 0u
#define pks8GET_SIG_OBJ_VALUES8(u16SigObjIx) \
		(&(Com_as8SignalObjectS8[(u16SigObjIx)]))
#else
#define pks8GET_SIG_OBJ_VALUES8(u16SigObjIx)  \
		(P2VAR(sint8,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pku16GET_SIG_OBJ_VALUEU16(u16SigObjIx) \
	(&(Com_pkstreMainConfig->pu16SignalObjectU16[(u16SigObjIx)]))
#else
#if u16NO_OF_SIG_U16_OBJ > 0u
#define pku16GET_SIG_OBJ_VALUEU16(u16SigObjIx) \
		(&(Com_au16SignalObjectU16[(u16SigObjIx)]))
#else
#define pku16GET_SIG_OBJ_VALUEU16(u16SigObjIx) \
		(P2VAR(uint16,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define pks16GET_SIG_OBJ_VALUES16(u16SigObjIx) \
	(&(Com_pkstreMainConfig->ps16SignalObjectS16[(u16SigObjIx)]))
#else
#if u16NO_OF_SIG_S16_OBJ > 0u
#define pks16GET_SIG_OBJ_VALUES16(u16SigObjIx) \
		(&(Com_as16SignalObjectS16[(u16SigObjIx)]))
#else
#define pks16GET_SIG_OBJ_VALUES16(u16SigObjIx) \
		(P2VAR(sint16,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define pku32GET_SIG_OBJ_VALUEU32(u16SigObjIx) \
	(&(Com_pkstreMainConfig->pu32SignalObjectU32[(u16SigObjIx)]))
#else
#if u16NO_OF_SIG_U32_OBJ > 0u
#define pku32GET_SIG_OBJ_VALUEU32(u16SigObjIx) \
		(&(Com_au32SignalObjectU32[(u16SigObjIx)]))
#else
#define pku32GET_SIG_OBJ_VALUEU32(u16SigObjIx) \
		(P2VAR(uint32,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define pks32GET_SIG_OBJ_VALUES32(u16SigObjIx) \
	(&(Com_pkstreMainConfig->ps32SignalObjectS32[(u16SigObjIx)]))
#else
#if u16NO_OF_SIG_S32_OBJ > 0u
#define pks32GET_SIG_OBJ_VALUES32(u16SigObjIx) \
		(&(Com_as32SignalObjectS32[(u16SigObjIx)]))
#else 
#define pks32GET_SIG_OBJ_VALUES32(u16SigObjIx) \
		(P2VAR(sint32,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define pkf32GET_SIG_OBJ_VALUEF32(u16SigObjIx) \
	(&(Com_pkstreMainConfig->pf32SignalObjectF32[(u16SigObjIx)]))
#else
#if u16NO_OF_SIG_F32_OBJ > 0u
#define pkf32GET_SIG_OBJ_VALUEF32(u16SigObjIx) \
		(&(Com_af32SignalObjectF32[(u16SigObjIx)]))
#else
#define pkf32GET_SIG_OBJ_VALUEF32(u16SigObjIx) \
		(P2VAR(float32,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkf64GET_SIG_OBJ_VALUEF64(u16SigObjIx) \
	(&(Com_pkstreMainConfig->pf64SignalObjectF64[(u16SigObjIx)]))

#else
#if u16NO_OF_SIG_F64_OBJ > 0u
#define pkf64GET_SIG_OBJ_VALUEF64(u16SigObjIx) \
		(&(Com_af64SignalObjectF64[(u16SigObjIx)]))
#else
#define pkf64GET_SIG_OBJ_VALUEF64(u16SigObjIx) \
		(P2VAR(float64,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif



/* !Deviation: [8019] and [8519]  the following MACRO is implied by AUTOSAR */
/* PRQA S 8019 ++ */
/* PRQA S 8519 ++ */

/* !Deviation: [0838] Multiple Memmap.h inclusion is implied by AUTOSAR */
/* PRQA S 838 ++ */

#define COM_START_SEC_CODE
#include "Memmap.h"

/* PRQA S 838 -- */

/* PRQA S 8019 -- */
/* PRQA S 8519 -- */

/******************************************************************************/
/*! \Description Com_TxConfirmation internal variables structure
*******************************************************************************/
typedef struct
{
  VAR(boolean, AUTOMATIC)     bTCLCurrentTxMode;
  VAR(boolean, AUTOMATIC)     bTCLConfirmSignals;
  VAR(boolean, AUTOMATIC)     bTCLIPduIsActive;
  VAR(boolean, AUTOMATIC)     bTCLReloadTimeout;

  VAR(uint8, AUTOMATIC)       u8TCLCurrentTxModeType;
  VAR(uint8, AUTOMATIC)       u8TCLCurrentSigType;
  VAR(uint8, AUTOMATIC)       u8TCLCurrentNoOfRep;
  VAR(uint8, AUTOMATIC)       u8TCLCurrentRptCtr;
  VAR(uint16, AUTOMATIC)      u16TCLCurrentNoOfSig;
  VAR(uint16, AUTOMATIC)      u16TCLCurrentSigMapIx;
  VAR(uint16_least, AUTOMATIC)      u16TCLSigLoopIndex;
  VAR(uint16, AUTOMATIC)      u16TCLCurrentIPduIndex;
  VAR(uint16, AUTOMATIC)      u16TCLCurrentSigIx;
  VAR(uint16, AUTOMATIC)      u16TCLCurrentTxModeIx;
} tstrTxConfirmationData;

/******************************************************************************/
/*! \Description Com_SendSignal internal variables structure
*******************************************************************************/
typedef struct
{
  VAR(boolean, AUTOMATIC)     bSSLNewTxMode;
  VAR(boolean, AUTOMATIC)     bSSLCurrentTxMode;
  VAR(boolean, AUTOMATIC)     bSSLNewFilterRslt;
  VAR(boolean, AUTOMATIC)     bSSLOldFilterRslt;
  VAR(boolean, AUTOMATIC)     bSSLTMSwitchHappened;
  VAR(boolean, AUTOMATIC)     bSSLElapsedMDT;
  VAR(boolean, AUTOMATIC)     bSSLSignalIsChanged;
  VAR(boolean, AUTOMATIC)     bSSLIPduState;
  VAR(boolean, AUTOMATIC)     bSSLSendIPdu;
  VAR(boolean, AUTOMATIC)     bSSLCalloutReturn;
  VAR(boolean, AUTOMATIC)     bSSLCancelTxSupported;
  VAR(boolean, AUTOMATIC)     bSSLUpdateBitSupport;
  VAR(boolean, AUTOMATIC)     bSSLFilterSupport;
  VAR(boolean, AUTOMATIC)     bSupressCancelTx;

  VAR(uint8, AUTOMATIC)       u8SSLReturnValue;
  VAR(uint8, AUTOMATIC)       u8SSLCurrentSigDir;
  VAR(uint8, AUTOMATIC)       u8SSLCurrentTxModeType;
  VAR(uint8, AUTOMATIC)       u8SSLNewTxModeType;
  VAR(uint8, AUTOMATIC)       u8SSLCurrentTxProperty;
  VAR(uint8, AUTOMATIC)       u8SSLPdurRetVal;
  VAR(uint8, AUTOMATIC)       u8SSLSigStructType;


  VAR(uint16, AUTOMATIC)      u16SSLCurrentSigIx;
  VAR(uint16, AUTOMATIC)      u16SSLCurrentSigId;
  VAR(uint16, AUTOMATIC)      u16SSLCurrentIPduIx;
  VAR(uint16, AUTOMATIC)      u16SSLCurrentTxModeIx;
  VAR(uint16, AUTOMATIC)      u16SSLNewTxModeIndex;
  VAR(uint16, AUTOMATIC)      u16SSLDynLength;

  VAR(PduIdType, AUTOMATIC)   u16SSLCurrentIPduId;

  VAR(Com_tpfbTxIpduCallout, COM_CFG_CONST)
                              pfbSSLCalloutPtr;

  P2VAR(uint8, AUTOMATIC, COM_CALIB_DATA)
                              pu8SSLIPduBuffPtr;
  VAR(boolean, AUTOMATIC)     bIPduSignalMDTMask;
} tstrSendSignalData;

/******************************************************************************/
/*! \Description Com_MainFunction internal variables structure
*******************************************************************************/
typedef struct
{
  VAR(boolean, AUTOMATIC)     bMTLCurrentTxMode;
  VAR(boolean, AUTOMATIC)     bMTLElapsedMDT;
  VAR(boolean, AUTOMATIC)     bMTLIPduState;
  VAR(boolean, AUTOMATIC)     bMTLSendIPdu;
  VAR(boolean, AUTOMATIC)     bMTLDelayedMDT;
  VAR(boolean, AUTOMATIC)     bMTLCalloutReturn;
  VAR(boolean, AUTOMATIC)     bMTLIPduIsDeferred;

  VAR(uint8, AUTOMATIC)       u8MTLCurrentNoOfRep;
  VAR(uint8, AUTOMATIC)       u8MTLCurrentRepCtr;
  VAR(uint8, AUTOMATIC)       u8MTLCurrentTxModeType;
  VAR(uint8, AUTOMATIC)       u8MTLPdurRetVal;
  VAR(uint8, AUTOMATIC)       u8MTLCurrentSigType;

  VAR(uint16, AUTOMATIC)      u16MTLCurrentSigIx;
  VAR(uint16, AUTOMATIC)      u16MTLCurrentIPduIndex;
  VAR(uint16, AUTOMATIC)      u16MTLCurrentTxModeIx;
  VAR(uint16_least, AUTOMATIC)      u16MTLSigLoopIndex;
  VAR(uint16, AUTOMATIC)      u16MTLCurrentNoOfSig;
  VAR(uint16, AUTOMATIC)      u16MTLCurrentSigMapIx;
  VAR(uint16_least, AUTOMATIC)      u16MTLIPduLoopIndex;

  VAR(uint32, AUTOMATIC)      u32MTLCurrentRepPrdTmr;
  VAR(uint32, AUTOMATIC)      u32MTLCurrentPrdTmr;
  VAR(PduIdType, AUTOMATIC)   u16MTLCurrentIPduId;

  VAR(Com_tpfbTxIpduCallout, COM_CFG_CONST)
                              pfbMTLCalloutPtr;
  P2VAR(uint8, AUTOMATIC, COM_CALIB_DATA)
                              pu8MTLIPduBuffPtr;
  VAR(boolean, AUTOMATIC)     bIPduMDTMask;
} tstrMainFunctionTxData;

#if (Com_bDATA_TP_SUPPORT == STD_ON) 
/******************************************************************************/
/*! \Description  Function to estimate the dynamic IPDU length.
    \param[in]  u16DynPduId ID of the I-PDU which length to be estimated.
*******************************************************************************/
static FUNC(uint16, COM_CODE) u16GetDynIPduLength(VAR(PduIdType, AUTOMATIC)
                                                                  u16DynPduId);

/******************************************************************************/
/*! \Description  This function returns TRUE if the I-PDU identefied by \n
u16PduId contains signal which has  dynamic length.
    \param[in]  u16PduId ID of the I-PDU to be checked.
*******************************************************************************/
static FUNC(boolean, COM_CODE) bTPIPduIsDynamic(VAR(PduIdType, AUTOMATIC)
                                                                  u16PduId);
#endif
/******************************************************************************/
/*! \Description  For signals of type UINT8N and UINT8DYN this service \n
                  retuns TRUE if signal new value is diffrent than old \n
                  one \n
    \param[in]  SignalId ID of the signal
    \param[in]  SignalNewDataPtr New Signal value
    \param[in]  u16DynLength Length of the dynamic signal
*******************************************************************************/
static FUNC(boolean, COM_CODE) bSignalIsChangedU8N(
#if Com_u16NO_OF_SIGNAL > 0u
                            VAR(Com_SignalIdType, AUTOMATIC)
                                                      u16SignalId,
#endif
                            P2CONST(void,AUTOMATIC, COM_MAX_CALIB_APPL_CFGCONST)
                                                      pkvidSignalNewDataPtr,
                            VAR(uint16, AUTOMATIC)    u16DynLength);

#if (Com_bGW_DESC_SUPPORT == STD_ON) 
/******************************************************************************/
/*! \Description  This service TRUE if signal new value is diffrent than old \n
                  one of DstDesc \n
    \param[in]  SignalId ID of the signal
    \param[in]  SignalNewDataPtr New Signal value
*******************************************************************************/
/*! \Trace_To   */
static FUNC(boolean, COM_CODE) bDstDescIsChanged(
                            VAR(Com_SignalIdType, AUTOMATIC)
                                                      u16SignalId,
                            P2CONST(void,AUTOMATIC, COM_MAX_CALIB_APPL_CFGCONST)
                                                      pkvidSignalNewDataPtr);
#endif
													  
#if (Com_bGW_DESC_SUPPORT == STD_ON) 													  
/******************************************************************************/
/*! \Description  For DstDesc of type UINT8N this service \n
                  retuns TRUE if signal new value is diffrent than old \n
                  one \n
    \param[in]  SignalId ID of the signal
    \param[in]  SignalNewDataPtr New Signal value
*******************************************************************************/
static FUNC(boolean, COM_CODE) bDstDescIsChangedU8N(
                            VAR(Com_SignalIdType, AUTOMATIC)
                                                      u16SignalId
#if (Com_u16GW_SIG_LENGTH_SIZE > 0U)													  
													  ,
                            P2CONST(void,AUTOMATIC, COM_MAX_CALIB_APPL_CFGCONST)
                                                      pkvidSignalNewDataPtr
#endif
													  );
#endif

#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
/******************************************************************************/
/*! \Description This function calls Com_vidSignalPackSignal for each group \n
                  signal in the signal group
  \param[in]   u16SignalGroupId  signal group ID
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE)
    vidPackSignalGroup(VAR(Com_SignalGroupIdType,AUTOMATIC)   u16SignalGroupId);
#endif

#if (Com_bTMS_SUPPORT == STD_ON) 
/******************************************************************************/
/*! \Description This function handles Com_SendSignal processing in case: \n
                  TxMode Switch Happened && \n
                  IPDU state = Active && \n
                  MDT Elapsed \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidHandleSendSignalTTT(
                                P2VAR(tstrSendSignalData,
                                      AUTOMATIC, COM_VAR)
                                                            pkudtSendSignalData);

/******************************************************************************/
/*! \Description This function handles Com_SendSignal processing in case: \n
                  TxMode Switch Happened && \n
                  IPDU state = Active && \n
                  MDT Not Elapsed \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidHandleSendSignalTTF(
                              P2VAR(tstrSendSignalData,
                                    AUTOMATIC, COM_VAR)
                                                            pkudtSendSignalData);

/******************************************************************************/
/*! \Description This function handles Com_SendSignal processing in case: \n
                  TxMode Switch Happened && \n
                  IPDU state = Not Active && \n
                  MDT Elapsed or MDT is not Elapsed\n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidHandleSendSignalTFT(
                              P2VAR(tstrSendSignalData,
                                    AUTOMATIC, COM_VAR)
                                                            pkudtSendSignalData);

/******************************************************************************/
/*! \Description This function handles Com_SendSignal processing in case: \n
                  No TxMode Switch Happened && \n
                  IPDU state = Active && \n
                  MDT Elapsed \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidHandleSendSignalFTT(
                              P2VAR(tstrSendSignalData,
                                    AUTOMATIC, COM_VAR)
                                                            pkudtSendSignalData);

/******************************************************************************/
/*! \Description This function handles Com_SendSignal processing in case: \n
                  No TxMode Switch Happened && \n
                  IPDU state = Active && \n
                  MDT Not Elapsed \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidHandleSendSignalFTF(
                              P2VAR(tstrSendSignalData,
                                    AUTOMATIC, COM_VAR)
                                                            pkudtSendSignalData);
#endif
/******************************************************************************/
/*! \Description This function handles Com_SendSignal processing in case: \n
                  No TxMode Switch Happened && \n
                  IPDU state = Active && \n
                  MDT Elapsed \n
                  Current TxMode = MIXED \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidHandleSendSignalFTTM(
                              P2VAR(tstrSendSignalData,
                                    AUTOMATIC, COM_VAR)
                                                            pkudtSendSignalData);

/******************************************************************************/
/*! \Description This function handles Com_SendSignal processing in case: \n
                  No TxMode Switch Happened && \n
                  IPDU state = Active && \n
                  MDT Elapsed \n
                  Current TxMode = DIRECT \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidHandleSendSignalFTTD(
                              P2VAR(tstrSendSignalData,
                                    AUTOMATIC, COM_VAR)
                                                            pkudtSendSignalData);

/******************************************************************************/
/*! \Description This function handles Com_SendSignal processing in case: \n
                  No TxMode Switch Happened && \n
                  IPDU state = Active && \n
                  MDT Not Elapsed \n
                  Current TxMode = MIXED \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidHandleSendSignalFTFM(
                              P2VAR(tstrSendSignalData,
                                    AUTOMATIC, COM_VAR)
                                                            pkudtSendSignalData);

/******************************************************************************/
/*! \Description This function handles Com_SendSignal processing in case: \n
                  No TxMode Switch Happened && \n
                  IPDU state = Active && \n
                  MDT Not Elapsed \n
                  Current TxMode = DIRECT \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidHandleSendSignalFTFD(
                              P2VAR(tstrSendSignalData,
                                    AUTOMATIC, COM_VAR)
                                                            pkudtSendSignalData);

#if (Com_bTMS_SUPPORT == STD_ON) 
/******************************************************************************/
/*! \Description This function handles Com_SendSignal processing. \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidHandleSendSignal(
                              P2VAR(tstrSendSignalData,
                                    AUTOMATIC, COM_VAR)
                                                            pkudtSendSignalData);
#endif
/******************************************************************************/
/*! \Description This function handles Com_SendSignal part of update bit \n
                 and trigger on change
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignalGroup internal \n
               variables structure
  \param[in]   SignalGroupId  signal Group Handle ID passed to Com_SendSignal
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidHandleUbitTrigOnCh(
            VAR(Com_SignalIdType, AUTOMATIC)  SignalId,
            P2CONST(void,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) SignalDataPtr,
		    P2VAR(tstrSendSignalData,AUTOMATIC, COM_VAR) pkudtSendSignalData);

/******************************************************************************/
/*! \Description This function handles Com_SendSignal Preparation - TMS part. \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \param[in]   SignalId  signal Handle ID passed to Com_SendSignal
  \param[in]   SignalDataPtr  Pointer to signal data passed to Com_SendSignal
  \return      void
*******************************************************************************/
/*! \Trace_To   Com-CDD-TxHandler-0020(0),
                Com-CDD-TxHandler-0286(0),
                Com-CDD-TxHandler-0024(0) */
static FUNC(void, COM_CODE) vidPrepSendSignalTMS(
            P2VAR(tstrSendSignalData,
                  AUTOMATIC, COM_VAR) pkudtSendSignalData,
            VAR(Com_SignalIdType, AUTOMATIC)  SignalId);

#if (Com_bTMS_SUPPORT == STD_ON)
/******************************************************************************/
/*! \Description This function handles Com_SendSignal Preparation. \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \param[in]   SignalId  signal Handle ID passed to Com_SendSignal
  \param[in]   SignalDataPtr  Pointer to signal data passed to Com_SendSignal
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidPrepSendSignal(
                            P2VAR(tstrSendSignalData, AUTOMATIC, COM_VAR)
                                                          pkudtSendSignalData,
                            VAR(Com_SignalIdType, AUTOMATIC)
                                                          SignalId);

/******************************************************************************/
/*! \Description This function handles Com_SendSignalGroup TMS Preparation. \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignalGroup internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To   Com-CDD-TxHandler-0022(0),
                Com-CDD-TxHandler-0322(0),
                Com-CDD-TxHandler-0025(0),
                Com-CDD-TxHandler-0509(0) */
static FUNC(void, COM_CODE) vidPrepSendSigGrpTMS(
             P2CONST(tstrSendSignalData,
                  AUTOMATIC, TYPEDEF) pkudtSendSignalData);
/******************************************************************************/
/*! \Description This function handles Com_SendSignalGroup Preparation. \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignalGroup internal \n
               variables structure
  \param[in]   SignalId  signal Handle ID passed to Com_SendSignal
  \param[in]   SignalDataPtr  Pointer to signal data passed to Com_SendSignal
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidPrepSendSignalGroup(
            VAR(Com_SignalGroupIdType, AUTOMATIC)  u16SignalGroupId,
            P2VAR(tstrSendSignalData,AUTOMATIC, COM_VAR) pkudtSendSignalData);

/******************************************************************************/
/*! \Description This function handles I-PDU processing of SendSignal calls \n
                 of the period between MainFunctionTx calls \n
                 This function is added to enhance code performance.
  \param[in]   pstrMainFunctionTxData  Pointer to Com_MainFunctionTx internal \n
               variables structure
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidHandleSendSigReqs(
    P2VAR(tstrMainFunctionTxData, AUTOMATIC, COM_VAR)
                                                pstrMainFunctionTxData);
#endif
/******************************************************************************/
/*! \Description This function handles Com_MainFunctionTx processing in case: \n
                  IPDU state = Active \n
                  TxMode = MIXED \n
                 This function is added to reduce code complexity.
  \param[in]   pstrMainFunctionTxData  Pointer to Com_MainFunctionTx internal \n
               variables structure
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidActiveIPduHandleM(
                              P2VAR(tstrMainFunctionTxData,
                                    AUTOMATIC, COM_VAR)
                                                        pstrMainFunctionTxData);

/******************************************************************************/
/*! \Description This function handles Com_MainFunctionTx processing in case: \n
                  IPDU state = Active && \n
                  TxMode = PERIODIC \n
                 This function is added to reduce code complexity.
  \param[in]   pstrMainFunctionTxData  Pointer to Com_MainFunctionTx internal \n
               variables structure
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidActiveIPduHandleP(
                              P2VAR(tstrMainFunctionTxData,
                                    AUTOMATIC, COM_VAR)
                                                        pstrMainFunctionTxData);

/******************************************************************************/
/*! \Description This function handles Com_MainFunctionTx processing in case: \n
                  IPDU state = Active && \n
                  TxMode = DIRECT \n
                 This function is added to reduce code complexity.
  \param[in]   pstrMainFunctionTxData  Pointer to Com_MainFunctionTx internal \n
               variables structure
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidActiveIPduHandleD(
                              P2VAR(tstrMainFunctionTxData,
                                    AUTOMATIC, COM_VAR)
                                                        pstrMainFunctionTxData);

/******************************************************************************/
/*! \Description This function handles Com_MainFunctionTx processing for \n
                  IPDUs delayed due to MDT \n
                 This function is added to reduce code complexity.
  \param[in]   pstrMainFunctionTxData  Pointer to Com_MainFunctionTx internal \n
               variables structure
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidActiveIPduHandleMDT(
                              P2VAR(tstrMainFunctionTxData,
                                    AUTOMATIC, COM_VAR)
                                                        pstrMainFunctionTxData);

/******************************************************************************/
/*! \Description This function handles Com_MainFunctionTx processing in case: \n
                  IPDU Shall be sent \n
                 This function is added to reduce code complexity.
  \param[in]   pstrMainFunctionTxData  Pointer to Com_MainFunctionTx internal \n
               variables structure
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidActiveIPduHandleSend(
    P2VAR(tstrMainFunctionTxData, AUTOMATIC, COM_VAR)
                                                    pstrMainFunctionTxData);

/******************************************************************************/
/*! \Description This function handles Com_MainFunctionTx processing in case: \n
                  IPDU state = Active \n
                 This function is added to reduce code complexity.
  \param[in]   pstrMainFunctionTxData  Pointer to Com_MainFunctionTx internal \n
               variables structure
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidActiveIPduHandle(
                              P2VAR(tstrMainFunctionTxData,
                                    AUTOMATIC, COM_VAR)
                                                        pstrMainFunctionTxData);

/******************************************************************************/
/*! \Description This function handles Com_TxConfirmation processing \n
                 This function is added to reduce code complexity.
  \param[in]   pstrTxConfirmationData  Pointer to Com_TxConfirmation internal \n
               variables structure
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidHandleTxConf(
                              P2VAR(tstrTxConfirmationData,
                                    AUTOMATIC, COM_VAR)
                                                        pstrTxConfirmationData);

#if (Com_bUBIT_SUPPORT == STD_ON) 
/******************************************************************************/
/*! \Description This service clears all update-bits of signals contained \n
                 in an I-PDU to PduR
    \param[in]  PduId ID of the I-PDU which signals update-bits to be \n
                cleared
*******************************************************************************/
static FUNC(void, COM_CODE) vidIPduClearUBits( VAR(PduIdType, AUTOMATIC)
                                                                      u16PduId);

#endif

#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON) 
/******************************************************************************/
/*! \Description This service copy data to shadow buffer
    \param[in]  u16SignalId ID of the group signal
    \param[in]  pkvidSignalDataPtr pointer to data
*******************************************************************************/
static FUNC(void, COM_CODE) vidWriteShadowBuff (
                    VAR(Com_SignalIdType, AUTOMATIC) u16SignalId,
                    P2CONST(void, AUTOMATIC, COM_MAX_CALIB_APPL_CFGCONST)
                                                            pkvidSignalDataPtr);
#endif
/******************************************************************************/
/*! \Description this function handles processing of Com_TxConfirmation and \n
                 Com_TpTxConfirmation
    \param[in]  u16TxPduId The lower layer communication module confirms the \n
                transmission of an I-PDU.
    \param[in]  u8Result  Result of the transmission of the I-PDU
    \param[in]  ku8IPduType IPDU Type Com_u8IPDU_TYPE_NORMAL or
                Com_u8IPDU_TYPE_TP
    \param[in]  pstrTxConfirmationData Pointer to Com_TxConfirmation internal \n
                variables structure
    \param[in,out]  None
*******************************************************************************/
static FUNC(void, COM_CODE) vidTxConfirmation(VAR(PduIdType, AUTOMATIC)
                                                    u16TxPduId,
                    VAR(NotifResultType, AUTOMATIC) u8Result,
                    CONST(uint8, AUTOMATIC)         ku8IPduType,
                    P2VAR(tstrTxConfirmationData, AUTOMATIC, COM_VAR)
                                                    pstrTxConfirmationData );

/******************************************************************************/
/*! \Description This function handles Com_MainFunctionTx processing for \n
                  deadline monitoring \n
                 This function is added to reduce code complexity.
  \param[in]   pstrMainFunctionTxData  Pointer to Com_MainFunctionTx internal \n
               variables structure
  \return      void
*******************************************************************************/
static FUNC(void, COM_CODE) vidActiveIPduHandleTO(
    P2VAR(tstrMainFunctionTxData, AUTOMATIC, COM_VAR)
                                                  pstrMainFunctionTxData);
	
	
/******************************************************************************/
/*! \Description This function handles Com_MainFunctionTx processing for \n
                  TMS evaluation \n
                 This function is added to Optimize code execution time.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/

static FUNC(void, COM_CODE) vidIPduHandleTMS(P2VAR(tstrSendSignalData,	
									AUTOMATIC, COM_VAR) pkudtSendSignalData);												  
												  
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
This function deviates in STSUB = 20. This deviation occured nbecause of the
mandatory RAM object protection. */
/* PRQA S 4700 ++ */
/* !Deviation: [3206]  Due to differnt combinations of Pre-compile options some
parameters shall not be used */
/* PRQA S 3206 ++ */
/******************************************************************************/
/*! \Description This function calls Com_vidSignalPackSignal for each group \n
                  signal in the signal group
  \param[in]   u16SignalGroupId  signal group ID
  \return      void
*******************************************************************************/
/*! \Trace_To       Com-CDD-TxHandler-5720(0),
					Com-CDD-0437(0) , Com-CDD-0438(0) ,
					Com-CDD-0439(0) , Com-CDD-0441(0) ,
					Com-CDD-0440(0) , Com-CDD-0442(0) ,
					Com-CDD-0443(0) , Com-CDD-SignalIpduServices-0261(0), 
					Com-CDD-TxHandler-0269(0)*/
static FUNC(void, COM_CODE) vidPackSignalGroup(
                      VAR(Com_SignalGroupIdType,AUTOMATIC)   u16SignalGroupId)
{
/* PRQA S 3206 -- */
#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
  VAR(uint16, AUTOMATIC)            u16NoOfGroupSig;
  VAR(uint16, AUTOMATIC)            u16CurrFirstGSigIx;
  VAR(uint16_least, AUTOMATIC)      u16GroupSigLoopIndex;
  P2CONST(void, AUTOMATIC,
      COM_MAX_CALIB_APPL_CFGCONST)  pkvidGroupSigShadowPtr;
  P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,COM_CALIB_CONST)	
									pkstrSigGrPB;


  /*! get the number of group signals in the signal group*/
  
  pkstrSigGrPB = pkstrGET_PB_SIGGRP_PTR(u16SignalGroupId);
  u16NoOfGroupSig = pkstrSigGrPB->u16NoOfGroupSignals;
  
  /*! get the index of the first group signal in the signal group*/
  u16CurrFirstGSigIx = pkstrSigGrPB->u16GroupSignalIndex;
  /* Com-CDD-TxHandler-5720(0) */
 SchM_Enter_Com_SigObjB();
 SchM_Enter_Com_SigObjF32();
 SchM_Enter_Com_SigObjF64();
 SchM_Enter_Com_SigObjS16();
 SchM_Enter_Com_SigObjS32();
 SchM_Enter_Com_SigObjS8();
 SchM_Enter_Com_SigObjU16();
 SchM_Enter_Com_SigObjU32();
 SchM_Enter_Com_SigObjU8();
  /*! For each group signal in the signal group */
  for(u16GroupSigLoopIndex = 0;
      u16GroupSigLoopIndex < u16NoOfGroupSig;
      u16GroupSigLoopIndex++)
  {
    /*! Get source group signals shadow buffer pointer  */
    pkvidGroupSigShadowPtr =  Com_pvidGetGSigShadowPtr((u16CurrFirstGSigIx +
                                        u16GroupSigLoopIndex));

	
	/* !Deviation: [0291]  ( An integer expression with a value that is apparently 
	negative is being converted to an unsigned type. ) */
	/*[0715]  ( Nesting of control structures (statements) exceeds 15 - program is 
	non-conforming.) */
	/*[0769]  ( This break statement terminates an iteration statement. ) */
	/*[2018]  ( This switch default label is unreachable. ) */
	/*[3201]  ( This statement is unreachable. ) */
	/*[3212]  ( This explicit cast is redundant and could be removed. ) */
	/*[3297]  ( Implicit unsigned conversion on positive integer expression 
	will apparently not preserve value. ) */
	/*[3325]  ( This control expression has a constant 'false' value. ) */
	/*[3334]  ( This declaration of 'pkstrLocDstDscPB' hides a more global
	declaration. ) */
	/*[3353]  ( The variable 'u8RemSigBits' is possibly unset at this point. ) */
	/*[3356]  ( The result of this logical operation is always 'false'. ) */
	/*[3359]  ( The value of this control expression is always 'false'. ) */
	/*[3382]  ( Unsigned arithmetic apparently results in wraparound past zero. ) */
	/*[3762]  ( Implicit conversion: int to unsigned long. ) */
	/*PRQA S 0291, 0715, 0769, 2018, 3201, 3212, 3297, 3325, 3334, 3353, 3356, 3359, 3382, 3762 ++ */
    /*! Call Com_vidSignalPackSignal */
	 /* Com-CDD-TxHandler-0262(0),
		Com-CDD-0437(0) , Com-CDD-0438(0) ,
		Com-CDD-0439(0) , Com-CDD-0441(0) ,
		Com-CDD-0440(0) , Com-CDD-0442(0) ,
		Com-CDD-0443(0) , Com-CDD-TxHandler-5721(0) , 
		Com-CDD-TxHandler-0269(0) */
    Com_vidSignalPackSignal((u16CurrFirstGSigIx +u16GroupSigLoopIndex),
                            pkvidGroupSigShadowPtr,
                            Com_u8SIG_STRUCT_GROUPSIG,
                            (uint16)0);
	/*PRQA S 0291, 0715, 0769, 2018, 3201, 3212, 3297, 3325, 3334, 3353, 3356, 3359, 3382, 3762 -- */
  }
 SchM_Exit_Com_SigObjU8();
 SchM_Exit_Com_SigObjU32();
 SchM_Exit_Com_SigObjU16();
 SchM_Exit_Com_SigObjS8();
 SchM_Exit_Com_SigObjS32();
 SchM_Exit_Com_SigObjS16();
 SchM_Exit_Com_SigObjF64();
 SchM_Exit_Com_SigObjF32();
 SchM_Exit_Com_SigObjB();
#endif
} /* vidPackSignalGroup */
/* PRQA S 4700 -- */
#endif


#if (Com_bUBIT_SUPPORT == STD_ON) 
/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
This function deviates in STCYC = 13. Partitioning this function shall not
pay for the negative effect of context switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description This service clears all update-bits of signals contained \n
                 in an I-PDU to PduR
    \param[in]  PduId ID of the I-PDU which signals update-bits to be \n
                cleared
*******************************************************************************/
/*! \Trace_To  */
static FUNC(void, COM_CODE) vidIPduClearUBits(VAR(PduIdType, AUTOMATIC)
                                                                      u16PduId)
{
  /*! Local variables */

  VAR(uint8, AUTOMATIC)             u8CurrentSigType;
  VAR(uint8, AUTOMATIC)             u8GWSigType;
  VAR(uint16, AUTOMATIC)            u16CurrentNoOfSig;
  VAR(uint16, AUTOMATIC)            u16CurrentSigMapIndex;
  VAR(uint16_least, AUTOMATIC)      u16SigLoopIndex;
  VAR(uint16, AUTOMATIC)            u16CurrentSigIx;
  VAR(uint16, AUTOMATIC)            u16GWSigIx;  
  VAR(uint16, AUTOMATIC)			u16UpdBitPos;
  
  P2CONST(Com_tstrSignalPB,AUTOMATIC,TYPEDEF)pkstrSigPB;
  P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF)pkstrIPduToSigMap;
  P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF)pkstrIPduToSigMapLoc;
  
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON) 
  P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,TYPEDEF)pkstrSigGrpPB;
#endif

  P2CONST(Com_tstrGWSignalMapping,AUTOMATIC,TYPEDEF)pkstrGWSigMap;
  P2CONST(Com_tstrGWSignalMapping,AUTOMATIC,TYPEDEF)pkstrGWSigMapLoc;
#if (Com_bGW_DESC_SUPPORT == STD_ON) 
  P2CONST(Com_tstrGWDstDesc,AUTOMATIC,TYPEDEF)pkstrDDsc;
#endif

  P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF)	  pkstrTxIPduPtr;
  
  
  pkstrTxIPduPtr = pkstrGET_TX_IPDUPTR_BYID(u16PduId);
  u16CurrentNoOfSig     = pkstrTxIPduPtr->u16IPduNoOfSignals;
  u16CurrentSigMapIndex = pkstrTxIPduPtr->u16IPduSigMappingIndex;

  pkstrIPduToSigMapLoc = pkstrGET_IPDU_SIG_MAP_PTR(0);
  pkstrSigPB = pkstrGET_PB_SIGNAL_PTR(0);
  
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
  pkstrSigGrpPB = pkstrGET_PB_SIGGRP_PTR(0);
#endif

  pkstrGWSigMapLoc = pkstrGET_GW_MAP_SIG_PTR(0);
  
#if (Com_bGW_DESC_SUPPORT == STD_ON) 
  pkstrDDsc=pkstrGET_PB_DST_DESC_PTR(0);
#endif


  /*! for each signal/signal group in the I-PDU */
  for(u16SigLoopIndex = 0u;
      u16SigLoopIndex < u16CurrentNoOfSig;
      u16SigLoopIndex++)
  {
    
	pkstrIPduToSigMap = &pkstrIPduToSigMapLoc[u16CurrentSigMapIndex + u16SigLoopIndex];
	u16CurrentSigIx = pkstrIPduToSigMap->u16Index;
    u8CurrentSigType = pkstrIPduToSigMap->u8Type;
    switch(u8CurrentSigType)
    {
      case Com_u8SIGNAL:
      /*! check if the signal has ubdate-bit configured*/
	  u16UpdBitPos = pkstrSigPB[u16CurrentSigIx].u16UpdateBitPosition;
	  if(u16UpdBitPos != (uint16)0xFFFFu)
      {
        Com_vidSignalEditUpdateBit(Com_u8SIGNAL, u16CurrentSigIx, u16UpdBitPos, FALSE);
      }
      else
      {

      }
      break;
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON) 
      case Com_u8SIGNALGROUP:
      /*! check if the signal group has ubdate-bit configured*/
      /*! clear ubdate-bit */
	  u16UpdBitPos = pkstrSigGrpPB[u16CurrentSigIx].u16UpdateBitPosition;
	  
	  if(u16UpdBitPos != (uint16)0xFFFFu)
      {
        Com_vidSignalEditUpdateBit(Com_u8SIGNALGROUP, u16CurrentSigIx, u16UpdBitPos,FALSE);
      }
      else
      {

      }
      break;
#endif
      case Com_u8GWSIGNAL:
      case Com_u8GWSIGNALGROUP:
	  pkstrGWSigMap = &pkstrGWSigMapLoc[u16CurrentSigIx];
      u16GWSigIx   = pkstrGWSigMap->u16DstIndex;
      u8GWSigType = pkstrGWSigMap->u8DstStructType;
      switch(u8GWSigType)
      {
        case Com_u8GW_STRUCT_SIG:
        /*! check if the signal has ubdate-bit configured*/
		u16UpdBitPos = pkstrSigPB[u16GWSigIx].u16UpdateBitPosition;
		if(u16UpdBitPos != (uint16)0xFFFFu)
       	 {
         		 Com_vidSignalEditUpdateBit(Com_u8SIGNAL, u16GWSigIx, u16UpdBitPos, FALSE);
        	}
        	else
       	 {
         }
        break;
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
        case Com_u8GW_STRUCT_SIGGROUP:
        /*! check if the signal group has ubdate-bit configured*/
        /*! clear ubdate-bit */
		u16UpdBitPos = pkstrSigGrpPB[u16GWSigIx].u16UpdateBitPosition;
		if(u16UpdBitPos != (uint16)0xFFFFu)
        {
          Com_vidSignalEditUpdateBit(Com_u8SIGNALGROUP,
                                     u16GWSigIx, u16UpdBitPos,
                                     FALSE);
        }
        else
        {

        }
        break;
#endif
#if (Com_bGW_DESC_SUPPORT == STD_ON) 
        case Com_u8GW_STRUCT_DST_DESC:
        /*! check if the dst. desc. has ubdate-bit configured*/
        /*! clear ubdate-bit */
		u16UpdBitPos = pkstrDDsc[u16GWSigIx].u16UpdateBitPosition;
		if(u16UpdBitPos != (uint16)0xFFFFu)
        {
          Com_vidSignalEditUpdateBit(Com_u8GW_STRUCT_DST_DESC,
                                     u16GWSigIx,
									 u16UpdBitPos,
                                     FALSE);
        }
        else
        {

        }
        break;
#endif
        default:

        break;
      }
      break;

      default:

      break;
    }
  }
} /* vidIPduClearUBits */
/* PRQA S 4700 -- */
#endif


/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
This function deviates in STSUB = 12. This is because of SchM protection
function calls */
/* PRQA S 4700 ++ */
/* !Deviation: [0627] No other declararation with the same name exists */
/* PRQA S 0627 ++ */
/******************************************************************************/
/*! \Description This service sends an I-PDU to PduR and reset MDT timer \n
    \param[in]  u16PduId ID of the I-PDU to be sent
    \param[in]  bDecMDT TRUE: decrement MDT after reload,
                        FALSE: No MDT decermentation
*******************************************************************************/
/*! \Trace_To   Com-CDD-TxHandler-0283(0),Com-CDD-5746(0), Com-CDD-5370(1) */
FUNC(PduR_ReturnType, COM_CODE) Com_u8SendIPdu(
                                          VAR(PduIdType, AUTOMATIC) u16PduId,
                                          VAR(boolean, AUTOMATIC) bDecMDT)
{
  /*! Local variables */
#if (Com_bDATA_TP_SUPPORT == STD_ON) 
  VAR(boolean, AUTOMATIC)           bDynamicIPdu;
#endif

  VAR(uint8, AUTOMATIC)             u8PdurRetVal;

  VAR(PduInfoType, AUTOMATIC)       strPduInfo;
  VAR(uint16, AUTOMATIC)            u16TpIPduCtrIx;

  P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF)pkTxIPdu;

#if (Com_bMDT_SUPPORT == STD_ON)
  P2VAR(Com_tu32MDTimer,AUTOMATIC,TYPEDEF)pu32MDTimerPtr;
  VAR(uint16, AUTOMATIC)            	  u16MDTimerIx;
#endif
  
  pkTxIPdu = pkstrGET_TX_IPDUPTR_BYID(u16PduId);
  strPduInfo.SduDataPtr  = pu8TXIPDU_GET_BUFF_PTR(pkTxIPdu->u32IPduBufferIndex);

  if(bTXIPDU_GET_TYPE(pkTxIPdu) == Com_u8IPDU_TYPE_NORMAL)
  {
    strPduInfo.SduLength = pkTxIPdu->u16IPduLength;
  }
  else /* IPdu Type == Com_u8IPDU_TYPE_TP  */
  {
  
#if (Com_bDATA_TP_SUPPORT == STD_ON) 
    bDynamicIPdu = bTPIPduIsDynamic(u16PduId);
    if(bDynamicIPdu == FALSE)
    {
#endif
      strPduInfo.SduLength =  pkTxIPdu->u16IPduLength;
	  
#if (Com_bDATA_TP_SUPPORT == STD_ON) 
    }
    else /* bDynamicIPdu == TRUE */
    {
      strPduInfo.SduLength = u16GetDynIPduLength(u16PduId);
    }
#endif
  }
 SchM_Enter_Com_IPduBuff();
  u8PdurRetVal = PduR_ComTransmit(
                    pkTxIPdu->u16PduRIPduId,
                    &strPduInfo );
 SchM_Exit_Com_IPduBuff();

#if (Com_bDATA_TP_SUPPORT == STD_ON) 
  u16TpIPduCtrIx = pkTxIPdu->u16TpIPduByteCtrIndex;
  
  if(((u8PdurRetVal == E_OK) &&
	 (u16TpIPduCtrIx != (uint16)0xFFFFu)))
  {
    /*! Set TP Byte counter */
    u16TXIPDU_SET_TPBYTECNT(u16TpIPduCtrIx,
                            strPduInfo.SduLength);
  }
  else
  {

  }
#endif

#if (Com_bMDT_SUPPORT == STD_ON)
  u16MDTimerIx = pkTxIPdu->u16MDTimerIndex;
  if(u16MDTimerIx != (uint16)0xFFFFu)
  {
    /*! Reload I-PDUs ComMDTimer by the value of ComMinimumDelayTime \n
    after calling PduR_ComTransmit */
    pu32MDTimerPtr = pku32GET_MD_TIMER(u16MDTimerIx);
    /* Com-CDD-TxHandler-0283(0) */
    if(bDecMDT == TRUE)
    {
     SchM_Enter_Com_MDT();
      (*pu32MDTimerPtr) =
      (pkTxIPdu->u32MinimumDelayTime) - (uint32)1;
     SchM_Exit_Com_MDT();
    }
    else
    {
     SchM_Enter_Com_MDT();
      (*pu32MDTimerPtr) =
      (pkTxIPdu->u32MinimumDelayTime);
     SchM_Exit_Com_MDT();
    }

  } 
#endif  

  return u8PdurRetVal;
} /* Com_u8SendIPdu */
/* PRQA S 4700 -- */
/* PRQA S 0627 -- */


/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
This function deviates in STCYC = 11. Partitioning this function shall not
pay for the negative effect of context switching. */
/* PRQA S 4700 ++ */
/* !Deviation: [3206]  Due to differnt combinations of Pre-compile options some
parameters shall not be used */
/* PRQA S 3206 ++ */
/******************************************************************************/
/*! \Description  For signals of type UINT8N and UINT8DYN this service \n
                  retuns TRUE if signal new value is diffrent than old \n
                  one \n
    \param[in]  SignalId ID of the signal
    \param[in]  SignalNewDataPtr New Signal value
    \param[in]  u16DynLength Length of the dynamic signal
*******************************************************************************/
/*! \Trace_To  Com-CDD-5746(0) */
static FUNC(boolean, COM_CODE) bSignalIsChangedU8N(
#if Com_u16NO_OF_SIGNAL > 0u
                            VAR(Com_SignalIdType, AUTOMATIC)
                                                      u16SignalId,
#endif
                            P2CONST(void,AUTOMATIC, COM_MAX_CALIB_APPL_CFGCONST)
                                                      pkvidSignalNewDataPtr,
                            VAR(uint16, AUTOMATIC)    u16DynLength)
{
  /* PRQA S 3206 -- */
  /*! Local variables */
/* !Deviation: [3204]  Due to differnt combinations of Pre-compile options
this variable cannot be declared as const */
/* PRQA S 3204 ++ */
  VAR(boolean, AUTOMATIC)     bChangeHappened;
/* PRQA S 3204 -- */
#if Com_u16NO_OF_SIGNAL > 0u
  VAR(uint8, AUTOMATIC)       u8CurrentSigType;
  VAR(uint8, AUTOMATIC)       u8OldByteVal;
  VAR(uint8, AUTOMATIC)       u8NewByteVal;
  VAR(uint16, AUTOMATIC)      u16CurrentSigIx;
  VAR(uint16, AUTOMATIC)      u16CurrentSignalLength;
  VAR(uint16_least, AUTOMATIC)      u16ByteLoopIndex;
  P2VAR(uint8, AUTOMATIC,COM_CALIB_DATA)
                              pu8CurrentSignalObjPtr;
  P2CONST(Com_tstrSignalPB,AUTOMATIC,TYPEDEF)
							  pkstrSigPB;
#endif
  bChangeHappened  = FALSE;
#if Com_u16NO_OF_SIGNAL > 0u
  u16CurrentSigIx   = u16SIG_GET_LKUP_IX(u16SignalId);
  pkstrSigPB = pkstrGET_PB_SIGNAL_PTR(u16CurrentSigIx);
  u8CurrentSigType  = pkstrSigPB->u8SignalType;
  switch(u8CurrentSigType)
  {
    case Com_u8SIGNAL_TYPE_UINT8N:
    u16CurrentSignalLength =
      Com_akstreSignalLT[u16CurrentSigIx].u16SignalLength;
    pu8CurrentSignalObjPtr =
      pku8GET_SIG_OBJ_VALUEU8(pkstrSigPB->u16SignalObjectIndex);
   SchM_Enter_Com_SigObjU8();
    for(u16ByteLoopIndex = 0; u16ByteLoopIndex < u16CurrentSignalLength;
        u16ByteLoopIndex++)
    {
      if(bChangeHappened == FALSE)
      {
        u8OldByteVal = pu8CurrentSignalObjPtr[u16ByteLoopIndex];
        u8NewByteVal =
          ((P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
            pkvidSignalNewDataPtr)[u16ByteLoopIndex];
        if(u8OldByteVal != u8NewByteVal)
        {
          bChangeHappened = TRUE;
        }
        else
        {

        }
      }
    }
   SchM_Exit_Com_SigObjU8();
    break;
#if (Com_bDATA_TP_SUPPORT == STD_ON) 
    case Com_u8SIGNAL_TYPE_UINT8DYN:
    u16CurrentSignalLength = u16DynLength;
    /* According to design, the first 2 bytes of the dynamic signal object
    are used to store the dynamic length. Hence the actual object data
    pointer shall be = signal_object_ptr + 2 */
    pu8CurrentSignalObjPtr =
      ((pku8GET_SIG_OBJ_VALUEU8(pkstrSigPB->u16SignalObjectIndex+2)));
   SchM_Enter_Com_SigObjU8();
    for(u16ByteLoopIndex = 0; u16ByteLoopIndex < u16CurrentSignalLength;
        u16ByteLoopIndex++)
    {
      if(bChangeHappened == FALSE)
      {
        u8OldByteVal = pu8CurrentSignalObjPtr[u16ByteLoopIndex];
        u8NewByteVal =
          ((P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
            pkvidSignalNewDataPtr)[u16ByteLoopIndex];
        if(u8OldByteVal != u8NewByteVal)
        {
          bChangeHappened = TRUE;
        }
        else
        {

        }
      }
    }
   SchM_Exit_Com_SigObjU8();
    break;
#endif

    default:

    break;
  }
#endif /* Com_u16NO_OF_SIGNAL > 0u */
  return bChangeHappened;
} /* bSignalIsChangedU8N */
/* PRQA S 4700 -- */

/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
This function deviates in STCYC = 20, STSUB = 19. Partitioning this function
shall not pay for the negative effect of context switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description  This service TRUE if signal new value is diffrent than old \n
                  one \n
    \param[in]  SignalId ID of the signal
    \param[in]  SignalNewDataPtr New Signal value
    \param[in]  u16DynLength Length of the dynamic signal
*******************************************************************************/
/*! \Trace_To   */
FUNC(boolean, COM_CODE) Com_bSignalIsChanged(
                            VAR(Com_SignalIdType, AUTOMATIC)
                                                      u16SignalId,
                            P2CONST(void,AUTOMATIC, COM_MAX_CALIB_APPL_CFGCONST)
                                                      pkvidSignalNewDataPtr,
                            VAR(uint16, AUTOMATIC)    u16DynLength)
{
  /*! Local variables */

  VAR(boolean, AUTOMATIC)     bReturnValue;
  VAR(uint8, AUTOMATIC)       u8CurrentSigType;
  VAR(uint16, AUTOMATIC)      u16CurrentSigIx;

  P2VAR(boolean,AUTOMATIC,TYPEDEF)pbSigObjB;
 #if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON) 
  P2VAR(float32,AUTOMATIC,TYPEDEF)pf32SigObjF32;
  P2VAR(float64,AUTOMATIC,TYPEDEF)pf64SigObjF64;
 #endif
 
  P2VAR(uint8,AUTOMATIC,TYPEDEF)pu8SigObjU8U8N;
  P2VAR(sint8,AUTOMATIC,TYPEDEF)ps8SigObjS8;
  P2VAR(uint16,AUTOMATIC,TYPEDEF)pu16SigObjU16;
  P2VAR(sint16,AUTOMATIC,TYPEDEF)ps16SigObjS16;
  P2VAR(uint32,AUTOMATIC,TYPEDEF)pu32SigObjU32;
  P2VAR(sint32,AUTOMATIC,TYPEDEF)ps32SigObjS32;
  P2CONST(Com_tstrSignalPB,AUTOMATIC,TYPEDEF)pkstrSigPB;

  u16CurrentSigIx   = u16SIG_GET_LKUP_IX(u16SignalId);
  pkstrSigPB = pkstrGET_PB_SIGNAL_PTR(u16CurrentSigIx);
  u8CurrentSigType  = pkstrSigPB->u8SignalType;

  bReturnValue          = FALSE;
  
    pbSigObjB =     pkB_GET_SIG_OBJ_VALUEB(0);
	pu8SigObjU8U8N =   pku8GET_SIG_OBJ_VALUEU8(0);
	ps8SigObjS8 =   pks8GET_SIG_OBJ_VALUES8(0);
	pu16SigObjU16 = pku16GET_SIG_OBJ_VALUEU16(0);
	ps16SigObjS16 = pks16GET_SIG_OBJ_VALUES16(0);
	pu32SigObjU32 = pku32GET_SIG_OBJ_VALUEU32(0);
	ps32SigObjS32 = pks32GET_SIG_OBJ_VALUES32(0);
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON)
	pf32SigObjF32 = pkf32GET_SIG_OBJ_VALUEF32(0);
	pf64SigObjF64 = pkf64GET_SIG_OBJ_VALUEF64(0);
#endif


  switch(u8CurrentSigType)
  {
    /* Com-CDD-TxHandler-0227(0) */
    case Com_u8SIGNAL_TYPE_BOOLEAN:
 SchM_Enter_Com_SigObjB();
    if(*(P2CONST(boolean,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
       pkvidSignalNewDataPtr !=
          pbSigObjB[pkstrSigPB->u16SignalObjectIndex])
    {
      bReturnValue = TRUE;
    }
    else
    {
      bReturnValue = FALSE;
    }
 SchM_Exit_Com_SigObjB();
    break;

#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON) 
    case Com_u8SIGNAL_TYPE_FLOAT32:
   SchM_Enter_Com_SigObjF32();
    if((*(P2CONST(float32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
    pkvidSignalNewDataPtr > (pf32SigObjF32[(pkstrSigPB->u16SignalObjectIndex)] + Com_f32FLOAT32_TOLERANCE))
       ||
       (*(P2CONST(float32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
        pkvidSignalNewDataPtr < (pf32SigObjF32[(pkstrSigPB[
      u16CurrentSigIx].u16SignalObjectIndex)] - Com_f32FLOAT32_TOLERANCE))
       )
    {
      bReturnValue = TRUE;
    }
    else
    {
      bReturnValue = FALSE;
    }
   SchM_Exit_Com_SigObjF32();
    break;
    case Com_u8SIGNAL_TYPE_FLOAT64:
   SchM_Enter_Com_SigObjF64();
/* !Deviation: [1267] A suffixed floating constant is being explicitly cast to
another floating type. This may be intended but could indicate that the
suffix is inappropriate. This is an intended casting */
/* PRQA S 1267 ++ */
    if((*(P2CONST(float64,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
        pkvidSignalNewDataPtr > (pf64SigObjF64[(pkstrSigPB->u16SignalObjectIndex)] + Com_f64FLOAT64_TOLERANCE))
       ||
       (*(P2CONST(float64,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
        pkvidSignalNewDataPtr < (pf64SigObjF64[(pkstrSigPB->u16SignalObjectIndex)] - Com_f64FLOAT64_TOLERANCE))
       )
/* PRQA S 1267 -- */
    {
      bReturnValue = TRUE;
    }
    else
    {
      bReturnValue = FALSE;
    }
   SchM_Exit_Com_SigObjF64();
    break;
#endif

    case Com_u8SIGNAL_TYPE_SINT16:
   SchM_Enter_Com_SigObjS16();
    if(*(P2CONST(sint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
       pkvidSignalNewDataPtr !=
        ps16SigObjS16[pkstrSigPB->u16SignalObjectIndex])
    {
      bReturnValue = TRUE;
    }
    else
    {
      bReturnValue = FALSE;
    }
   SchM_Exit_Com_SigObjS16();
    break;
    case Com_u8SIGNAL_TYPE_SINT32:
   SchM_Enter_Com_SigObjS32();
    if(*(P2CONST(sint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
       pkvidSignalNewDataPtr !=
       ps32SigObjS32[pkstrSigPB->u16SignalObjectIndex])
    {
      bReturnValue = TRUE;
    }
    else
    {
      bReturnValue = FALSE;
    }
   SchM_Exit_Com_SigObjS32();
    break;
    case Com_u8SIGNAL_TYPE_SINT8:
 SchM_Enter_Com_SigObjS8();
    if(*(P2CONST(sint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
       pkvidSignalNewDataPtr !=
         ps8SigObjS8[pkstrSigPB->u16SignalObjectIndex])
    {
      bReturnValue = TRUE;
    }
    else
    {
      bReturnValue = FALSE;
    }
 SchM_Exit_Com_SigObjS8();
    break;
    case Com_u8SIGNAL_TYPE_UINT16:
   SchM_Enter_Com_SigObjU16();
    if(*(P2CONST(uint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
       pkvidSignalNewDataPtr !=
        pu16SigObjU16[pkstrSigPB->u16SignalObjectIndex])
    {
      bReturnValue = TRUE;
    }
    else
    {
      bReturnValue = FALSE;
    }
   SchM_Exit_Com_SigObjU16();
    break;
    case Com_u8SIGNAL_TYPE_UINT32:
   SchM_Enter_Com_SigObjU32();
    if(*(P2CONST(uint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
       pkvidSignalNewDataPtr !=
        pu32SigObjU32[pkstrSigPB->u16SignalObjectIndex])
    {
      bReturnValue = TRUE;
    }
    else
    {
      bReturnValue = FALSE;
    }
   SchM_Exit_Com_SigObjU32();
    break;
    case Com_u8SIGNAL_TYPE_UINT8:
 SchM_Enter_Com_SigObjU8();
    if(*(P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
       pkvidSignalNewDataPtr !=
        pu8SigObjU8U8N[pkstrSigPB->u16SignalObjectIndex ])
    {
      bReturnValue = TRUE;
    }
    else
    {
      bReturnValue = FALSE;
    }
 SchM_Exit_Com_SigObjU8();
    break;
    case Com_u8SIGNAL_TYPE_UINT8N:
#if (Com_bDATA_TP_SUPPORT == STD_ON) 
    case Com_u8SIGNAL_TYPE_UINT8DYN:
#endif
    bReturnValue = bSignalIsChangedU8N(
#if Com_u16NO_OF_SIGNAL > 0u		
		u16SignalId,
#endif
                                       pkvidSignalNewDataPtr,
                                       u16DynLength);
    break;

    default:

    break;
  }

  return bReturnValue;

} /* Com_bSignalIsChanged */
/* PRQA S 4700 -- */


#if (Com_bGW_DESC_SUPPORT == STD_ON) 
/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
This function deviates in STCYC = 11. Partitioning this function shall not
pay for the negative effect of context switching. */
/* PRQA S 4700 ++ */
/* !Deviation: [3206]  Due to differnt combinations of Pre-compile options some
parameters shall not be used */
/* PRQA S 3206 ++ */
/******************************************************************************/
/*! \Description  For DstDesc of type UINT8N this service \n
                  retuns TRUE if signal new value is diffrent than old \n
                  one \n
    \param[in]  SignalId ID of the signal
    \param[in]  SignalNewDataPtr New Signal value
*******************************************************************************/
static FUNC(boolean, COM_CODE) bDstDescIsChangedU8N(
                            VAR(Com_SignalIdType, AUTOMATIC)
                                                      u16SignalId
#if (Com_u16GW_SIG_LENGTH_SIZE > 0U)													  
													  ,
                            P2CONST(void,AUTOMATIC, COM_MAX_CALIB_APPL_CFGCONST)
                                                      pkvidSignalNewDataPtr
#endif													  
													  )
{
/* PRQA S 3206 -- */
  /*! Local variables */
/* !Deviation: [3204]  Due to differnt combinations of Pre-compile options
this variable cannot be declared as const */
/* PRQA S 3204 ++ */
  VAR(boolean, AUTOMATIC)     bReturnValue;
/* PRQA S 3204 -- */
#if (Com_u16GW_SIG_LENGTH_SIZE > 0U)
  VAR(boolean, AUTOMATIC)     bAllBytesAreMatching;
  VAR(uint8, AUTOMATIC)       u8CurrentSigType;
  VAR(uint8, AUTOMATIC)       u8OldByteVal;
  VAR(uint8, AUTOMATIC)       u8NewByteVal;
  VAR(uint16, AUTOMATIC)      u16CurrentSigIx;
  VAR(uint16, AUTOMATIC)      u16CurrentSignalLength;
  VAR(uint16_least, AUTOMATIC)      u16ByteLoopIndex;
  P2VAR(uint8, AUTOMATIC,COM_CALIB_DATA)
                              pu8CurrentSignalObjPtr;
  P2CONST(Com_tstrGWDstDesc,AUTOMATIC,TYPEDEF)			
							  pkstrDSTDesSigPB;

  bAllBytesAreMatching  = TRUE;
#endif
  bReturnValue          = FALSE;
#if (Com_u16GW_SIG_LENGTH_SIZE > 0U)
  u16CurrentSigIx   = u16SIG_GET_LKUP_IX(u16SignalId);
  pkstrDSTDesSigPB = pkstrGET_PB_DST_DESC_PTR(u16CurrentSigIx);
  u8CurrentSigType  = pkstrDSTDesSigPB->u8SignalType;
  
    if (u8CurrentSigType == Com_u8SIGNAL_TYPE_UINT8N)
	{
		u16CurrentSignalLength = pkstrDSTDesSigPB->u16LengthIndex;
		pu8CurrentSignalObjPtr = pku8GET_SIG_OBJ_VALUEU8(pkstrDSTDesSigPB->
											u16SignalObjectIndex);

		SchM_Enter_Com_SigObjU8();
		for(u16ByteLoopIndex = 0; u16ByteLoopIndex < u16CurrentSignalLength;
			u16ByteLoopIndex++)
		{
		  if(bAllBytesAreMatching == TRUE)
		  {
			u8OldByteVal = pu8CurrentSignalObjPtr[u16ByteLoopIndex];
			u8NewByteVal =
			  ((P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
				pkvidSignalNewDataPtr)[u16ByteLoopIndex];
			if(u8OldByteVal != u8NewByteVal)
			{
			  bAllBytesAreMatching = FALSE;
			}
			else
			{

			}
		  }
		}
		SchM_Exit_Com_SigObjU8();
		if(bAllBytesAreMatching == TRUE)
		{
		  bReturnValue = FALSE;
		}
		else
		{
		  bReturnValue = TRUE;
		}
	}
	else
	{
	
	}
#endif
  return bReturnValue;
} /* bSignalIsChangedU8N */
/* PRQA S 4700 -- */
#endif

#if (Com_bGW_DESC_SUPPORT == STD_ON)
/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
Partitioning this function shall not pay for the negative effect of context
switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description  This service TRUE if signal new value is diffrent than old \n
                  one of DstDesc \n
    \param[in]  SignalId ID of the signal
    \param[in]  SignalNewDataPtr New Signal value
*******************************************************************************/
/*! \Trace_To   */
static FUNC(boolean, COM_CODE) bDstDescIsChanged(
                            VAR(Com_SignalIdType, AUTOMATIC)
                                                      u16SignalId,
                            P2CONST(void,AUTOMATIC, COM_MAX_CALIB_APPL_CFGCONST)
                                                      pkvidSignalNewDataPtr)
{
  /*! Local variables */

  VAR(boolean, AUTOMATIC)     bReturnValue;
  VAR(uint8, AUTOMATIC)       u8CurrentSigType;
  VAR(uint16, AUTOMATIC)      u16CurrentSigIx;

  P2VAR(boolean,AUTOMATIC,TYPEDEF)pbSigObjB;

#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON) 
  P2VAR(float32,AUTOMATIC,TYPEDEF)pf32SigObjF32;
  P2VAR(float64,AUTOMATIC,TYPEDEF)pf64SigObjF64;
#endif
 
  P2VAR(uint8,AUTOMATIC,TYPEDEF)pu8SigObjU8U8N;
  P2VAR(sint8,AUTOMATIC,TYPEDEF)ps8SigObjS8;
  P2VAR(uint16,AUTOMATIC,TYPEDEF)pu16SigObjU16;
  P2VAR(sint16,AUTOMATIC,TYPEDEF)ps16SigObjS16;
  P2VAR(uint32,AUTOMATIC,TYPEDEF)pu32SigObjU32;
  P2VAR(sint32,AUTOMATIC,TYPEDEF)ps32SigObjS32;
  P2CONST(Com_tstrSignalPB,AUTOMATIC,TYPEDEF)pkstrSigPB;

  u16CurrentSigIx   = u16SIG_GET_LKUP_IX(u16SignalId);
  pkstrSigPB = pkstrGET_PB_SIGNAL_PTR(u16CurrentSigIx);
  u8CurrentSigType  = pkstrSigPB->u8SignalType;
  
    pbSigObjB =     pkB_GET_SIG_OBJ_VALUEB(0);
	pu8SigObjU8U8N =   pku8GET_SIG_OBJ_VALUEU8(0);
	ps8SigObjS8 =   pks8GET_SIG_OBJ_VALUES8(0);
	pu16SigObjU16 = pku16GET_SIG_OBJ_VALUEU16(0);
	ps16SigObjS16 = pks16GET_SIG_OBJ_VALUES16(0);
	pu32SigObjU32 = pku32GET_SIG_OBJ_VALUEU32(0);
	ps32SigObjS32 = pks32GET_SIG_OBJ_VALUES32(0);
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON)
	pf32SigObjF32 = pkf32GET_SIG_OBJ_VALUEF32(0);
	pf64SigObjF64 = pkf64GET_SIG_OBJ_VALUEF64(0);
#endif

  bReturnValue          = FALSE;

  switch(u8CurrentSigType)
  {
    /* Com-CDD-TxHandler-0227(0) */
    case Com_u8SIGNAL_TYPE_BOOLEAN:
   SchM_Enter_Com_SigObjB();
    if(*(P2CONST(boolean,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
       pkvidSignalNewDataPtr != pbSigObjB[pkstrSigPB->u16SignalObjectIndex])
    {
      bReturnValue = TRUE;
    }
    else
    {
      bReturnValue = FALSE;
    }
   SchM_Exit_Com_SigObjB();
    break;
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON)
    case Com_u8SIGNAL_TYPE_FLOAT32:
   SchM_Enter_Com_SigObjF32();
    if((*(P2CONST(float32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
        pkvidSignalNewDataPtr > 
    (pf32SigObjF32[(pkstrSigPB->u16SignalObjectIndex)] + 
                    Com_f32FLOAT32_TOLERANCE))
       ||
       (*(P2CONST(float32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
        pkvidSignalNewDataPtr <
        (pf32SigObjF32[(pkstrSigPB->u16SignalObjectIndex)] -
                                         Com_f32FLOAT32_TOLERANCE))
       )
    {
      bReturnValue = TRUE;
    }
    else
    {
      bReturnValue = FALSE;
    }
   SchM_Exit_Com_SigObjF32();
    break;
    case Com_u8SIGNAL_TYPE_FLOAT64:
   SchM_Enter_Com_SigObjF64();
/* !Deviation: [1267] A suffixed floating constant is being explicitly cast to
another floating type. This may be intended but could indicate that the
suffix is inappropriate. This is an intended casting */
/* PRQA S 1267 ++ */
    if((*(P2CONST(float64,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
        pkvidSignalNewDataPtr >
        (pf64SigObjF64[(pkstrSigPB->u16SignalObjectIndex)] +
                                                Com_f64FLOAT64_TOLERANCE))
       ||
       (*(P2CONST(float64,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
        pkvidSignalNewDataPtr <
        (pf64SigObjF64[(pkstrSigPB->u16SignalObjectIndex)] -
                                                Com_f64FLOAT64_TOLERANCE))
       )
/* PRQA S 1267 -- */
    {
      bReturnValue = TRUE;
    }
    else
    {
      bReturnValue = FALSE;
    }
   SchM_Exit_Com_SigObjF64();
    break;
#endif

    case Com_u8SIGNAL_TYPE_SINT16:
   SchM_Enter_Com_SigObjS16();
    if(*(P2CONST(sint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
       pkvidSignalNewDataPtr !=
        ps16SigObjS16[pkstrSigPB->u16SignalObjectIndex])
    {
      bReturnValue = TRUE;
    }
    else
    {
      bReturnValue = FALSE;
    }
   SchM_Exit_Com_SigObjS16();
    break;
    case Com_u8SIGNAL_TYPE_SINT32:
   SchM_Enter_Com_SigObjS32();
    if(*(P2CONST(sint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
       pkvidSignalNewDataPtr !=
        ps32SigObjS32[pkstrSigPB->u16SignalObjectIndex])
    {
      bReturnValue = TRUE;
    }
    else
    {
      bReturnValue = FALSE;
    }
   SchM_Exit_Com_SigObjS32();
    break;
    case Com_u8SIGNAL_TYPE_SINT8:
   SchM_Enter_Com_SigObjS8();
    if(*(P2CONST(sint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
       pkvidSignalNewDataPtr !=
        ps8SigObjS8[pkstrSigPB->u16SignalObjectIndex])
    {
      bReturnValue = TRUE;
    }
    else
    {
      bReturnValue = FALSE;
    }
   SchM_Exit_Com_SigObjS8();
    break;
    case Com_u8SIGNAL_TYPE_UINT16:
   SchM_Enter_Com_SigObjU16();
    if(*(P2CONST(uint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
       pkvidSignalNewDataPtr !=
        pu16SigObjU16[pkstrSigPB->u16SignalObjectIndex])
    {
      bReturnValue = TRUE;
    }
    else
    {
      bReturnValue = FALSE;
    }
   SchM_Exit_Com_SigObjU16();
    break;
    case Com_u8SIGNAL_TYPE_UINT32:
   SchM_Enter_Com_SigObjU32();
    if(*(P2CONST(uint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
       pkvidSignalNewDataPtr !=
        pu32SigObjU32[pkstrSigPB->u16SignalObjectIndex])
    {
      bReturnValue = TRUE;
    }
    else
    {
      bReturnValue = FALSE;
    }
   SchM_Exit_Com_SigObjU32();
    break;
    case Com_u8SIGNAL_TYPE_UINT8:
   SchM_Enter_Com_SigObjU8();
    if(*(P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
       pkvidSignalNewDataPtr !=
        pu8SigObjU8U8N[pkstrSigPB->u16SignalObjectIndex ])
    {
      bReturnValue = TRUE;
    }
    else
    {
      bReturnValue = FALSE;
    }
   SchM_Exit_Com_SigObjU8();
    break;
    case Com_u8SIGNAL_TYPE_UINT8N:
    case Com_u8SIGNAL_TYPE_UINT8DYN:
    bReturnValue = bDstDescIsChangedU8N(u16SignalId
#if (Com_u16GW_SIG_LENGTH_SIZE > 0U)		
										,
                                        pkvidSignalNewDataPtr
#endif
										);
    break;

    default:

    break;
  }

  return bReturnValue;

} /* Com_bDstDescIsChanged */
/* PRQA S 4700 -- */
#endif

/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
This function deviates in STCYC = 26, STSUB = 20. Partitioning this function
shall not pay for the negative effect of context switching. */
/* PRQA S 4700 ++ */
/* !Deviation: [3206]  Due to differnt combinations of Pre-compile options some
parameters shall not be used */
/* PRQA S 3206 ++ */
/******************************************************************************/
/*! \Description  This service TRUE if signal group shadow buffer is diffrent \n
                   than the object \n
    \param[in]  u16SignalGroupId ID of the signal group
*******************************************************************************/
/*! \Trace_To  */
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
FUNC(boolean, COM_CODE) Com_bSignalGroupIsChanged(
                      VAR(Com_SignalGroupIdType, AUTOMATIC) u16SignalGroupId)
{
/* PRQA S 3206 -- */
   /*! Local variables */
/* !Deviation: [3204]  Due to differnt combinations of Pre-compile options
this variable cannot be declared as const */
/* PRQA S 3204 ++ */
  VAR(boolean, AUTOMATIC)     bReturnValue;
/* PRQA S 3204 -- */
#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
  VAR(boolean, AUTOMATIC)     bAllBytesAreMatching;

  VAR(uint8, AUTOMATIC)       u8CurrGroupSigType;
  VAR(uint8, AUTOMATIC)       u8OldByteVal;
  VAR(uint8, AUTOMATIC)       u8NewByteVal;

  VAR(uint16_least, AUTOMATIC)      u16CurrGroupSigIx;
  VAR(uint16_least, AUTOMATIC)      u16ByteLoopIndex;
  VAR(uint16, AUTOMATIC)      u16NoOfGroupSig;
  VAR(uint16, AUTOMATIC)      u16CurrFirstGSigIx;
  VAR(uint16_least, AUTOMATIC)      u16GroupSigLoopIndex;
  VAR(uint16, AUTOMATIC)      u16CurrGroupSigLength;


  P2VAR(uint8, AUTOMATIC,COM_CALIB_DATA)
                              pu8CurrGSignalObjPtr;

  P2VAR(uint8, AUTOMATIC,COM_CALIB_DATA)
                              pu8CurrGSignalShadPtr;


  P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,TYPEDEF) pkstrGrpSigPBLoc;
  P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,TYPEDEF) pkstrGrpSigPB;
  P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,TYPEDEF) pkstrSigGroPB;
  P2VAR(boolean,AUTOMATIC,TYPEDEF)pbSigObjB;
  
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON) 
  P2VAR(float32,AUTOMATIC,TYPEDEF)pf32SigObjF32;
  P2VAR(float64,AUTOMATIC,TYPEDEF)pf64SigObjF64;
#endif

  P2VAR(sint16,AUTOMATIC,TYPEDEF)ps16SigObjS16;
  P2VAR(sint32,AUTOMATIC,TYPEDEF)ps32SigObjS32;
  P2VAR(sint8,AUTOMATIC,TYPEDEF)ps8SigObjS8;
  P2VAR(uint16,AUTOMATIC,TYPEDEF)pu16SigObju16;
  P2VAR(uint32,AUTOMATIC,TYPEDEF)pu32SigObju32;
  P2VAR(uint8,AUTOMATIC,TYPEDEF)pu8SigObju8u8n;
#endif
  bReturnValue       = FALSE;
#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))

  pkstrGrpSigPBLoc = pkstrGET_PB_GRP_SIG_PTR(0);
  

  /*! get the number of group signals in the signal group*/
  
  pkstrSigGroPB = pkstrGET_PB_SIGGRP_PTR(u16SignalGroupId);
  u16NoOfGroupSig = pkstrSigGroPB->u16NoOfGroupSignals;
  /*! get the index of the first group signal in the signal group*/
  u16CurrFirstGSigIx = pkstrSigGroPB->u16GroupSignalIndex;

    pbSigObjB =     pkB_GET_SIG_OBJ_VALUEB(0);
	pu8SigObju8u8n =   pku8GET_SIG_OBJ_VALUEU8(0);
	ps8SigObjS8 =   pks8GET_SIG_OBJ_VALUES8(0);
	pu16SigObju16 = pku16GET_SIG_OBJ_VALUEU16(0);
	ps16SigObjS16 = pks16GET_SIG_OBJ_VALUES16(0);
	pu32SigObju32 = pku32GET_SIG_OBJ_VALUEU32(0);
	ps32SigObjS32 = pks32GET_SIG_OBJ_VALUES32(0);
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON)
	pf32SigObjF32 = pkf32GET_SIG_OBJ_VALUEF32(0);
	pf64SigObjF64 = pkf64GET_SIG_OBJ_VALUEF64(0);
#endif

  /*! For each group signal in the signal group check if changed */
  for(u16GroupSigLoopIndex = 0;
      u16GroupSigLoopIndex < u16NoOfGroupSig;
      u16GroupSigLoopIndex++)
  {
    u16CurrGroupSigIx   = (uint16_least)(u16CurrFirstGSigIx + u16GroupSigLoopIndex);
	pkstrGrpSigPB = &pkstrGrpSigPBLoc[u16CurrGroupSigIx];
    u8CurrGroupSigType  = pkstrGrpSigPB->u8SignalType;
    bAllBytesAreMatching  = TRUE;

    switch(u8CurrGroupSigType)
    {
      /* Com-CDD-TxHandler-0227(0) */
      case Com_u8SIGNAL_TYPE_BOOLEAN:
     SchM_Enter_Com_SigObjB();
      if( pbSigObjB[pkstrGrpSigPB->u16ShadowBufferIndex ]  !=
          pbSigObjB[pkstrGrpSigPB->u16SignalObjectIndex ])
      {
        bReturnValue = bReturnValue | TRUE;
      }
      else
      {

      }
     SchM_Exit_Com_SigObjB();
      break;
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON) 
      case Com_u8SIGNAL_TYPE_FLOAT32:
     SchM_Enter_Com_SigObjF32();
      if((pf32SigObjF32[pkstrGrpSigPB->u16ShadowBufferIndex]  >
          ((pf32SigObjF32[pkstrGrpSigPB->u16SignalObjectIndex] )
           + Com_f32FLOAT32_TOLERANCE) )
         ||
         ((pf32SigObjF32[pkstrGrpSigPB->u16ShadowBufferIndex]) <
          ((pf32SigObjF32[pkstrGrpSigPB->u16SignalObjectIndex])
           - Com_f32FLOAT32_TOLERANCE))
         )
      {
        bReturnValue = bReturnValue | TRUE;
      }
      else
      {

      }
     SchM_Exit_Com_SigObjF32();
      break;
      case Com_u8SIGNAL_TYPE_FLOAT64:
     SchM_Enter_Com_SigObjF64();
/* !Deviation: [1267] A suffixed floating constant is being explicitly cast to
another floating type. This may be intended but could indicate that the
suffix is inappropriate. This is an intended casting */
/* PRQA S 1267 ++ */
      if((pf64SigObjF64[pkstrGrpSigPB->u16ShadowBufferIndex] >
          ((pf64SigObjF64[pkstrGrpSigPB->u16SignalObjectIndex])
         + Com_f64FLOAT64_TOLERANCE))
         ||
         (pf64SigObjF64[pkstrGrpSigPB->u16ShadowBufferIndex] <
          ((pf64SigObjF64[pkstrGrpSigPB->u16SignalObjectIndex])
         - Com_f64FLOAT64_TOLERANCE))
         )
/* PRQA S 1267 -- */
      {
        bReturnValue = bReturnValue | TRUE;
      }
      else
      {

      }
     SchM_Exit_Com_SigObjF64();
      break;
#endif
      case Com_u8SIGNAL_TYPE_SINT16:
     SchM_Enter_Com_SigObjS16();
      if( ps16SigObjS16[pkstrGrpSigPB->u16ShadowBufferIndex ] !=
          ps16SigObjS16[pkstrGrpSigPB->u16SignalObjectIndex])
      {
        bReturnValue = bReturnValue | TRUE;
      }
      else
      {

      }
     SchM_Exit_Com_SigObjS16();
      break;
      case Com_u8SIGNAL_TYPE_SINT32:
     SchM_Enter_Com_SigObjS32();
      if( ps32SigObjS32[pkstrGrpSigPB->u16ShadowBufferIndex ] !=
          ps32SigObjS32[pkstrGrpSigPB->u16SignalObjectIndex])
      {
        bReturnValue = bReturnValue | TRUE;
      }
      else
      {

      }
     SchM_Exit_Com_SigObjS32();
      break;
      case Com_u8SIGNAL_TYPE_SINT8:
     SchM_Enter_Com_SigObjS8();
      if( ps8SigObjS8[pkstrGrpSigPB->u16ShadowBufferIndex ] !=
          ps8SigObjS8[pkstrGrpSigPB->u16SignalObjectIndex])
      {
        bReturnValue = bReturnValue | TRUE;
      }
      else
      {

      }
     SchM_Exit_Com_SigObjS8();
      break;
      case Com_u8SIGNAL_TYPE_UINT16:
     SchM_Enter_Com_SigObjU16();
      if( pu16SigObju16[pkstrGrpSigPB->u16ShadowBufferIndex ] !=
          pu16SigObju16[pkstrGrpSigPB->u16SignalObjectIndex])
      {
        bReturnValue = bReturnValue | TRUE;
      }
      else
      {

      }
     SchM_Exit_Com_SigObjU16();
      break;
      case Com_u8SIGNAL_TYPE_UINT32:
     SchM_Enter_Com_SigObjU32();
      if( pu32SigObju32[pkstrGrpSigPB->u16ShadowBufferIndex ] !=
          pu32SigObju32[pkstrGrpSigPB->u16SignalObjectIndex])
      {
        bReturnValue = bReturnValue | TRUE;
      }
      else
      {

      }
     SchM_Exit_Com_SigObjU32();
      break;
      case Com_u8SIGNAL_TYPE_UINT8:
     SchM_Enter_Com_SigObjU8();
      if( pu8SigObju8u8n[pkstrGrpSigPB->u16ShadowBufferIndex ] !=
          pu8SigObju8u8n[pkstrGrpSigPB->u16SignalObjectIndex])
      {
        bReturnValue = bReturnValue | TRUE;
      }
      else
      {

      }
     SchM_Exit_Com_SigObjU8();
      break;
      case Com_u8SIGNAL_TYPE_UINT8N:
      u16CurrGroupSigLength =
        Com_akstreGroupSignalLT[u16CurrGroupSigIx].u16SignalLength;
      pu8CurrGSignalObjPtr =
        &(pu8SigObju8u8n[pkstrGrpSigPB->u16SignalObjectIndex]);
      pu8CurrGSignalShadPtr =
        &(pu8SigObju8u8n[pkstrGrpSigPB->u16ShadowBufferIndex ]);
     SchM_Enter_Com_SigObjU8();
      for(u16ByteLoopIndex = 0; u16ByteLoopIndex < u16CurrGroupSigLength;
          u16ByteLoopIndex++)
      {
        if(bAllBytesAreMatching == TRUE)
        {
          u8OldByteVal = pu8CurrGSignalObjPtr[u16ByteLoopIndex];
          u8NewByteVal = pu8CurrGSignalShadPtr[u16ByteLoopIndex];
          if(u8OldByteVal != u8NewByteVal)
          {
            bAllBytesAreMatching = FALSE;
          }
          else
          {

          }
        }
      }
     SchM_Exit_Com_SigObjU8();
      if(bAllBytesAreMatching == TRUE)
      {

      }
      else
      {
        bReturnValue = bReturnValue | TRUE;
      }
      break;

      default:

      break;
    } /* switch(u8CurrGroupSigType) */
  }   /* For each group signal in the signal group check if changed */
#endif /* Com_u16NO_OF_GROUP_SIGSLT > 0u */

  return bReturnValue;
} /* Com_bSignalGroupIsChanged */
/* PRQA S 4700 -- */
#endif


#if (Com_bTMS_SUPPORT == STD_ON) 
/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
This function deviates in STCYC = 13. Partitioning this function shall not
pay for the negative effect of context switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description This service returns the TxMode evaluated according to \n
                 signal/ group signal values \n
    \param[in]  ID of the I-PDU which TxMode needed to be evaluated
*******************************************************************************/
/*! \Trace_To Com-CDD-TxHandler-5593(0),
              Com-CDD-TxHandler-0356(0),
              Com-CDD-TxHandler-0359(0),
              Com-CDD-TxHandler-0358(0),
              Com-CDD-TxHandler-0357(0),
              Com-CDD-TxHandler-0355(0),
			  Com-CDD-5748(1), Com-CDD-5545(1), Com-CDD-5547(1)  */
FUNC(boolean, COM_CODE) Com_bEvaluateTxMode(VAR(PduIdType, AUTOMATIC) PduId)
{
  /*! Local variables */

  VAR(boolean, AUTOMATIC)           bCurrentFilterResult;
  VAR(uint8, AUTOMATIC)             u8CurrentSigType;
  VAR(uint16, AUTOMATIC)            u16CurrentNoOfSig;
  VAR(uint16, AUTOMATIC)            u16CurrentSigMapIndex;
  VAR(uint16_least, AUTOMATIC)      u16SigLoopIndex;
  VAR(uint16, AUTOMATIC)            u16CurrentSigIx;
  VAR(uint16, AUTOMATIC)            u16CrntSigId;

  P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF)pkstrIPdu2SigMap;
  P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF)pkstrIPdu2SigMapLoc;
  P2CONST(Com_tstrGWSignalMapping,AUTOMATIC,TYPEDEF)pkstrGWSiglMap;
  P2CONST(Com_tstrGWSignalMapping,AUTOMATIC,TYPEDEF)pkstrGWSiglMapLoc;
  P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF)			pkTxIPdu;
#if (Com_bGW_DESC_SUPPORT == STD_ON) 
  P2CONST(Com_tstrGWDstDesc,AUTOMATIC,TYPEDEF)pkstrDstDsc;
  P2CONST(Com_tstrGWDstDesc,AUTOMATIC,TYPEDEF)pkstrDstDscLoc;
#endif
 
   VAR(boolean, AUTOMATIC)           bNewFilterRslt;
   VAR(boolean, AUTOMATIC)           bOldFilterRslt;
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON) 
#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
  VAR(uint16, AUTOMATIC)            u16CurrFirstGSigIx;
  VAR(uint16, AUTOMATIC)            u16CurrSignalGroupId;
  VAR(Com_SignalIdType, AUTOMATIC)  u16CurrGSigId;
  P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,TYPEDEF)pkstrSigGrpPB;
  P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,TYPEDEF)pkstrSigGrpPBLoc;
  
#endif
#endif

  pkstrIPdu2SigMapLoc = pkstrGET_IPDU_SIG_MAP_PTR(0);
  pkstrGWSiglMapLoc = pkstrGET_GW_MAP_SIG_PTR(0);

#if (Com_bGW_DESC_SUPPORT == STD_ON) 
  pkstrDstDscLoc = pkstrGET_PB_DST_DESC_PTR(0);
#endif

#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
  pkstrSigGrpPBLoc = pkstrGET_PB_SIGGRP_PTR(0);
#endif
  pkTxIPdu = pkstrGET_TX_IPDUPTR_BYID(PduId);

  if(bTX_IPDU_GET_TMS_FLAG(pkTxIPdu) == TRUE)
  {
    bCurrentFilterResult = FALSE;


    u16CurrentNoOfSig = pkTxIPdu->u16IPduNoOfSignals;
    u16CurrentSigMapIndex = pkTxIPdu->u16IPduSigMappingIndex;

    /*! for each signal/signal group in the I-PDU */
	
    for(u16SigLoopIndex = 0u;
        u16SigLoopIndex < u16CurrentNoOfSig;
        u16SigLoopIndex++)
    {
	
	  pkstrIPdu2SigMap = &pkstrIPdu2SigMapLoc[u16CurrentSigMapIndex + u16SigLoopIndex];
      u16CurrentSigIx = pkstrIPdu2SigMap->u16Index;
      u8CurrentSigType = pkstrIPdu2SigMap->u8Type;
      if((u8CurrentSigType == (uint8) Com_u8GWSIGNAL) ||
         (u8CurrentSigType == (uint8) Com_u8GWSIGNALGROUP))
      {
        pkstrGWSiglMap = &pkstrGWSiglMapLoc[u16CurrentSigIx];
		u8CurrentSigType = pkstrGWSiglMap->u8DstStructType;
        u16CurrentSigIx = pkstrGWSiglMap->u16DstIndex;
      }
      else
      {
      }
		
		  if(bCurrentFilterResult == FALSE)
		  {

			switch(u8CurrentSigType)
			{
			  case Com_u8SIGNAL:
			  /* in case of Com_u8GW_STRUCT_SIG processing shall also go here */
	#if Com_u16NO_OF_SIGNAL > 0u
			  /* Com-CDD-TxHandler-0356(0) */
				u16CrntSigId	=	Com_akstreSignalLT[u16CurrentSigIx].u16SignalId;
				#if Com_u16NO_OF_SIGNAL_STATUS > 0u
				SchM_Enter_Com_SignalStatus_19();
				bNewFilterRslt = (boolean)((Com_audteSignalStatus[u16CrntSigId] & Com_u8NEW_FILTER_RESULT) != (boolean)FALSE);
				bOldFilterRslt = (boolean)((Com_audteSignalStatus[u16CrntSigId] & Com_u8LASTFILTER_RES) != (boolean)FALSE);
				SchM_Exit_Com_SignalStatus_19();
		
				if(bNewFilterRslt != bOldFilterRslt)
				{
					Com_audteSignalStatus[u16CrntSigId] ^= Com_u8LASTFILTER_RES;
				}
				#endif
			
			  if(Com_akstreSignalLT[u16CurrentSigIx].u16FilterIndex != (uint16)0xFFFFu)
			  {
				/* Com-CDD-TxHandler-0359(0) */
				/* Com-CDD-TxHandler-0358(0) */
				#if Com_u16NO_OF_SIGNAL_STATUS > 0u
				SchM_Enter_Com_SignalStatus_0D();
				SchM_Enter_Com_SignalStatus_19();
				bCurrentFilterResult = bCurrentFilterResult | (boolean)((Com_audteSignalStatus[u16CrntSigId] & Com_u8LASTFILTER_RES) > 0);
				SchM_Exit_Com_SignalStatus_19();
				SchM_Exit_Com_SignalStatus_0D();
				#endif
			  }
			  else
			  {

			  }
	#endif
			  break;
	#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON) 
			  case Com_u8SIGNALGROUP:
			  /* case Com_u8GW_STRUCT_SIGGROUP: */
	#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u)&& (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
			  /* Com-CDD-TxHandler-0355(0) */
			  /*! Do the same in Com_u8SIGNAL case for each group signal in \n
			   this signal group*/
			  u16CurrSignalGroupId = u16CurrentSigIx;
			  /*! get the number of group signals in the signal group*/
			  pkstrSigGrpPB = &pkstrSigGrpPBLoc[u16CurrSignalGroupId];
			  /*! get the index of the first group signal in the signal group*/
			  u16CurrFirstGSigIx = pkstrSigGrpPB->u16GroupSignalIndex;
			  
			    /*indicate the first Group signal location in that the signal group filter is changed*/
			    u16CrntSigId	=	Com_akstreGroupSignalLT[u16CurrFirstGSigIx].u16SignalId;
				#if Com_u16NO_OF_SIGNAL_STATUS > 0u
				SchM_Enter_Com_SignalStatus_19();
				bNewFilterRslt = (boolean)((Com_audteSignalStatus[u16CrntSigId] & Com_u8NEW_FILTER_RESULT) != (boolean)FALSE);
				bOldFilterRslt = (boolean)((Com_audteSignalStatus[u16CrntSigId] & Com_u8LASTFILTER_RES) != (boolean)FALSE);
				SchM_Exit_Com_SignalStatus_19();
		
				if(bNewFilterRslt != bOldFilterRslt)
				{
					Com_audteSignalStatus[u16CrntSigId] ^= Com_u8LASTFILTER_RES;
				}
				#endif
				

			  /*! For each group signal in the signal group */
				/*! Get group signals ID */
				u16CurrGSigId = u16GET_G_SIG_ID(u16CurrFirstGSigIx);
				
				/* Com-CDD-TxHandler-0356(0) */
				  /* Com-CDD-TxHandler-0359(0) */
				  /* Com-CDD-TxHandler-0358(0) */
				
				#if Com_u16NO_OF_SIGNAL_STATUS > 0u
				SchM_Enter_Com_SignalStatus_0D();
				SchM_Enter_Com_SignalStatus_19();
				bCurrentFilterResult = bCurrentFilterResult | (boolean)((Com_audteSignalStatus[u16CurrGSigId] & Com_u8LASTFILTER_RES) > 0);
				SchM_Exit_Com_SignalStatus_19();
				SchM_Exit_Com_SignalStatus_0D();
				#endif
				/*}
				else
				{

				}
				}*/
	#endif
			  break;
	#endif

	#if (Com_bGW_DESC_SUPPORT == STD_ON) 
			  case Com_u8GW_STRUCT_DST_DESC:
			  /* Com-CDD-TxHandler-0356(0) */
				pkstrDstDsc = &pkstrDstDscLoc[u16CurrentSigIx];
			  	u16CrntSigId	=	pkstrDstDsc->u16SignalId;
				SchM_Enter_Com_SignalStatus_19();
				#if Com_u16NO_OF_SIGNAL_STATUS > 0u
				bNewFilterRslt = (boolean)((Com_audteSignalStatus[u16CrntSigId] & Com_u8NEW_FILTER_RESULT) != (boolean)FALSE);
				bOldFilterRslt = (boolean)((Com_audteSignalStatus[u16CrntSigId] & Com_u8LASTFILTER_RES) != (boolean)FALSE);
				#endif
				SchM_Exit_Com_SignalStatus_19();
		
				if(bNewFilterRslt != bOldFilterRslt)
				{
					#if Com_u16NO_OF_SIGNAL_STATUS > 0u
					Com_audteSignalStatus[u16CrntSigId] ^= Com_u8LASTFILTER_RES;
					#endif
				}
				
			  if(pkstrDstDsc->u16FilterIndex != (uint16)0xFFFFu)
			  {
				/* Com-CDD-TxHandler-0359(0) */
				/* Com-CDD-TxHandler-0358(0) */		
				#if Com_u16NO_OF_SIGNAL_STATUS > 0u				
				SchM_Enter_Com_SignalStatus_0D();
				SchM_Enter_Com_SignalStatus_19();
				bCurrentFilterResult = bCurrentFilterResult | (boolean)((Com_audteSignalStatus[u16CrntSigId] & Com_u8LASTFILTER_RES) > 0);
				SchM_Exit_Com_SignalStatus_19();
				SchM_Exit_Com_SignalStatus_0D();
				#endif
				
			  }
			  else
			  {

			  }
			  break;
	#endif
			  default:

			  break;
			}
		  }
	}
	}
	else
	{ /* Com-CDD-TxHandler-0357(0) */
		bCurrentFilterResult = TRUE;
	}

  return bCurrentFilterResult;
}
/* PRQA S 4700 -- */
#endif


/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
This function deviates in STCYC = 12. Partitioning this function shall not
pay for the negative effect of context switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description This function handles Com_TxConfirmation processing \n
                 This function is added to reduce code complexity.
  \param[in]   pstrTxConfirmationData  Pointer to Com_TxConfirmation internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To Com-CDD-TxHandler-5708(0) */
static FUNC(void, COM_CODE) vidHandleTxConf(
                              P2VAR(tstrTxConfirmationData,
                                    AUTOMATIC, COM_VAR)
                                                        pstrTxConfirmationData)
{

  P2CONST(Com_tstrTxModeMixed,AUTOMATIC,TYPEDEF) pkstrTxModeMixedPtr;
#if (Com_bNTIMES_SUPPORT == STD_ON)
  P2CONST(Com_tstrTxModeDirect,AUTOMATIC,TYPEDEF) pkstrTxModeDirectPtr;
#endif
  switch(pstrTxConfirmationData->u8TCLCurrentTxModeType)
  {
    case Com_u8TX_MODE_MIXED:
	pkstrTxModeMixedPtr = 
	u8MIXTXMODE_GET_PTR(pstrTxConfirmationData->u16TCLCurrentTxModeIx);   
   
   pstrTxConfirmationData->u8TCLCurrentRptCtr =
      u8TXMODE_GET_REPCTR(pkstrTxModeMixedPtr->u16RepetitionsCtrIndex);
    pstrTxConfirmationData->u8TCLCurrentNoOfRep = 
						pkstrTxModeMixedPtr->u8NumberOfRepetitions;
    if(pstrTxConfirmationData->u8TCLCurrentNoOfRep > (uint8)0)
    {
      if(pstrTxConfirmationData->u8TCLCurrentRptCtr > (uint8)0)
      {
        u8TXMODE_DEC_REPCTR(pkstrTxModeMixedPtr->u16RepetitionsCtrIndex);
        pstrTxConfirmationData->u8TCLCurrentRptCtr =
          u8TXMODE_GET_REPCTR(pkstrTxModeMixedPtr->u16RepetitionsCtrIndex);
        if(pstrTxConfirmationData->u8TCLCurrentRptCtr == (uint8)0)
        {
          pstrTxConfirmationData->bTCLConfirmSignals = TRUE;
        }
        else
        {

        }
      }
      else /* u8CurrentRptCtr == (uint8) 0  then confirm for the periodic
              part*/
      {
        pstrTxConfirmationData->bTCLConfirmSignals = TRUE;
      }
    }
    /* u8CurrentNoOfRep == (uint8) 0, Confirm Signals see COM467*/
    /* Fix bug# 47188*/
    else
    {
      pstrTxConfirmationData->bTCLConfirmSignals = TRUE;
    }
    break;

    case Com_u8TX_MODE_DIRECT:
#if (Com_bNTIMES_SUPPORT == STD_ON)
   pkstrTxModeDirectPtr = 
	u8DIRTXMODE_GET_PTR(pstrTxConfirmationData->u16TCLCurrentTxModeIx);  
    pstrTxConfirmationData->u8TCLCurrentRptCtr =
      u8TXMODE_GET_REPCTR(pkstrTxModeDirectPtr->u16RepetitionsCtrIndex);
    pstrTxConfirmationData->u8TCLCurrentNoOfRep =
				pkstrTxModeDirectPtr->u8NumberOfRepetitions;
    if(pstrTxConfirmationData->u8TCLCurrentNoOfRep > (uint8) 0)
    {
      if(pstrTxConfirmationData->u8TCLCurrentRptCtr > (uint8) 0)
      {
        u8TXMODE_DEC_REPCTR(pkstrTxModeDirectPtr->u16RepetitionsCtrIndex);

        pstrTxConfirmationData->u8TCLCurrentRptCtr =
          u8TXMODE_GET_REPCTR(pkstrTxModeDirectPtr->u16RepetitionsCtrIndex);
        if(pstrTxConfirmationData->u8TCLCurrentRptCtr == (uint8) 0)
        {
          pstrTxConfirmationData->bTCLConfirmSignals = TRUE;
        }
        else
        {

        }
      }
      else /* u8CurrentRptCtr == (uint8) 0 */
      {
        pstrTxConfirmationData->bTCLConfirmSignals = TRUE;
      }
    }
    /* u8CurrentNoOfRep == (uint8) 0, Confirm Signals see COM467*/
    /* Fix bug# 47188*/
    else
    {
#endif

      pstrTxConfirmationData->bTCLConfirmSignals = TRUE;
	  
#if (Com_bNTIMES_SUPPORT == STD_ON)    
	}
#endif	
    break;
    case Com_u8TX_MODE_PERIODIC:
    pstrTxConfirmationData->bTCLConfirmSignals = TRUE;
    break;

    case Com_u8TX_MODE_NONE:
    pstrTxConfirmationData->bTCLConfirmSignals = TRUE;
	
#if (Com_bTMS_SUPPORT == STD_ON) 
    if(bTXIPDU_GET_TMS_FLAG(pstrTxConfirmationData->u16TCLCurrentIPduIndex)
                                                                    == FALSE)
#endif
    {
#if (Com_bTO_SUPPORT == STD_ON) 
      pstrTxConfirmationData->bTCLReloadTimeout = TRUE;
#endif
    }
    break;

    default:

    break;
  }
}
/* PRQA S 4700 -- */

/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
Partitioning this function shall not pay for the negative effect of context
switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description this function handles processing of Com_TxConfirmation and \n
                 Com_TpTxConfirmation
    \param[in]  u16TxPduId The lower layer communication module confirms the \n
                transmission of an I-PDU.
    \param[in]  u8Result  Result of the transmission of the I-PDU
    \param[in]  ku8IPduType IPDU Type Com_u8IPDU_TYPE_NORMAL or
                Com_u8IPDU_TYPE_TP
    \param[in]  pstrTxConfirmationData Pointer to Com_TxConfirmation internal \n
                variables structure
    \param[in,out]  None
*******************************************************************************/
/*! \Trace_To         Com-CDD-TxHandler-0039(0),
                      Com-CDD-TxHandler-0040(0),
                      Com-CDD-TxHandler-0043(0),
                      Com-CDD-TxHandler-0044(0),
                      Com-CDD-TxHandler-0348(0),
                      Com-CDD-TxHandler-0349(0),
                      Com-CDD-TxHandler-0350(0),
                      Com-CDD-TxHandler-0440(0),
                      Com-CDD-TxHandler-5591(0),
                      Com-CDD-TxHandler-0015(0),
                      Com-CDD-TxHandler-5694(0),
                      Com-CDD-TxHandler-5699(0),
                      Com-CDD-TxHandler-5695(0),
                      Com-CDD-TxHandler-0016(0),
                      Com-CDD-TxHandler-0027(0),
                      Com-CDD-TxHandler-0028(0),
                      Com-CDD-TxHandler-0511(0),
                      Com-CDD-TxHandler-5708(0),
                      Com-CDD-TxHandler-5709(0),
                      Com-CDD-TxHandler-5722(0),
                      Com-CDD-TxHandler-5723(0),
                      Com-CDD-TxHandler-5724(0),
                      Com-CDD-TxHandler-5693(0),
                      Com-CDD-TxHandler-5696(0),
                      Com-CDD-TxHandler-5700(0),
                      Com-CDD-TxHandler-5718(0),
                      Com-CDD-0270(0), Com-CDD-5746(0), Com-CDD-5371(1) */
static FUNC(void, COM_CODE) vidTxConfirmation(
                    VAR(PduIdType, AUTOMATIC)       u16TxPduId,
                    VAR(NotifResultType, AUTOMATIC) u8Result,
                    CONST(uint8, AUTOMATIC)         ku8IPduType,
                    P2VAR(tstrTxConfirmationData, AUTOMATIC, COM_VAR)
                                                    pstrTxConfirmationData )
{

    P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF) 	pkstrTxIPduPtr;
    P2CONST(Com_tstrTxMode,AUTOMATIC,TYPEDEF) 	pkstrTxModePtr;
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) 		pu16TCLCrntIPduIdx;
    P2VAR(boolean, AUTOMATIC, AUTOMATIC)		pbTCLCrntTxMod;
   
#if (Com_bTO_SUPPORT == STD_ON) 
    P2VAR(uint32,AUTOMATIC,AUTOMATIC)pu32TOT;
	VAR(uint16, AUTOMATIC)	u16TxIPduTOIx;
#endif


#if (Com_bMDT_SUPPORT == STD_ON) 
    P2VAR(Com_tu32MDTimer,AUTOMATIC,TYPEDEF)	pu32MDTimerPtr;
	VAR(uint16, AUTOMATIC) 						u16MDTimerIx;
#endif

    pu16TCLCrntIPduIdx = &(pstrTxConfirmationData->u16TCLCurrentIPduIndex);
	pstrTxConfirmationData->u16TCLCurrentIPduIndex =
						u16IPDU_GET_IX(u16TxPduId);
    pkstrTxIPduPtr = pkstrGET_TX_IPDU_PTR(*pu16TCLCrntIPduIdx);
  /*! Check if the I-PDU is active */
  /* Com-CDD-TxHandler-0015(0) */
  /* Com-CDD-TxHandler-0016(0) */
   SchM_Enter_Com_IPduStatus_40();
   SchM_Enter_Com_IPduStatus_26();
    pstrTxConfirmationData->bTCLIPduIsActive = Com_bIpduCheckActive(u16TxPduId);
   SchM_Exit_Com_IPduStatus_26();
	SchM_Exit_Com_IPduStatus_40();
  
  if(pstrTxConfirmationData->bTCLIPduIsActive == TRUE)
  {
    pbTCLCrntTxMod = &(pstrTxConfirmationData->bTCLCurrentTxMode);
	#if u16NO_OF_IPDUS_STATUS > 0u
   SchM_Enter_Com_IPduStatus_40();
   SchM_Enter_Com_IPduStatus_26();
	*pbTCLCrntTxMod = (boolean)((Com_audteIPduStatus[u16TxPduId] & Com_u8CURR_TX_MO_FLG) != FALSE);
	SchM_Exit_Com_IPduStatus_26();
   SchM_Exit_Com_IPduStatus_40();
	#endif
	
	 
	  
#if (Com_bTMS_SUPPORT == STD_ON) 
    if(pstrTxConfirmationData->bTCLCurrentTxMode == TRUE)
    {
#endif

      pkstrTxModePtr = u8IPDU_GET_TXMODE_PTR(pkstrTxIPduPtr->u16TxModeTrueIndex);
      pstrTxConfirmationData->u8TCLCurrentTxModeType = pkstrTxModePtr->u8TxMode;
      pstrTxConfirmationData->u16TCLCurrentTxModeIx = pkstrTxModePtr->u16Index;
#if (Com_bTMS_SUPPORT == STD_ON) 
    }
    else
    /*bCurrentTxMode == FALSE*/
    {
	  pkstrTxModePtr = u8IPDU_GET_TXMODE_PTR(pkstrTxIPduPtr->u16TxModeFalseIndex);
      pstrTxConfirmationData->u8TCLCurrentTxModeType = pkstrTxModePtr->u8TxMode;
      pstrTxConfirmationData->u16TCLCurrentTxModeIx = pkstrTxModePtr->u16Index;
    }
#endif

    /*! Handle this confirmation only in case it has no errors*/
    /* only TP confirmation which can have error code */
    if((ku8IPduType   == Com_u8IPDU_TYPE_NORMAL) || ((u8Result     == NTFRSLT_OK)  
#if (Com_bDATA_TP_SUPPORT == STD_ON)
		&& (ku8IPduType  == Com_u8IPDU_TYPE_TP)
#endif
		))
    {
      vidHandleTxConf(pstrTxConfirmationData);
    }
    /*! If Result != NTFRSLT_OK, Ignore the confirmation */
    if(u8Result != NTFRSLT_OK)
    {
      /*! If transmission error in case of TP, unlock I-PDU buffer */
      pstrTxConfirmationData->bTCLConfirmSignals = FALSE;
	  
	  /* !Deviation: [0277]  ( An Integer Constant experssion with negative value is being converted to an unsigned type)  */
	  /*PRQA S 0277 ++ */
	  #if u16NO_OF_IPDUS_STATUS > 0u
	 SchM_Enter_Com_IPduStatus_40();
	 SchM_Enter_Com_IPduStatus_26();
	  Com_audteIPduStatus[u16TxPduId] &= (Com_udtIPduStatus)(~Com_u8WAIT_CONF);
	 SchM_Exit_Com_IPduStatus_26();
	 SchM_Exit_Com_IPduStatus_40();
	  #endif
	  
	  /*PRQA S 0277 -- */
    }
    else
    {

    }

    if(pstrTxConfirmationData->bTCLConfirmSignals == TRUE)
    {
	
#if ((Com_bDATA_TP_SUPPORT == STD_ON) && (Com_bUBIT_SUPPORT == STD_ON)) 
      if(ku8IPduType  == Com_u8IPDU_TYPE_TP)
      {
        /*! If I-PDU type = TP, clear all update-bits of all signals \n
        and signal groups belonging to the I-PDU */
        /* Com-CDD-TxHandler-0511(0) */
 
        vidIPduClearUBits(u16TxPduId);
      }
      else
      {

      }
#endif


#if (Com_bTO_SUPPORT == STD_ON) 
	  u16TxIPduTOIx = pkstrTxIPduPtr->u16TOTimerIndex;															
      
	  if(u16TxIPduTOIx != (uint16)0xFFFFu)
	  {
		pu32TOT = pkstrGET_PB_TIMEOUT_TIMER(0);
        if(pstrTxConfirmationData->bTCLReloadTimeout == TRUE)
        {
          /*! If this I-PDU has only one TxMode equals NONE, reload timeout \n
          timer */
          /* Com-CDD-TxHandler-5695(0) */
         SchM_Enter_Com_TimeoutTimer();
          pu32TOT[u16TxIPduTOIx] = 
							pkstrTxIPduPtr->u32Timeout;
         SchM_Exit_Com_TimeoutTimer();
        }
        else
        {
          /*! Else clear I-PDU timeout timer */
         SchM_Enter_Com_TimeoutTimer();
          /* Com-CDD-TxHandler-5694(0) */
          pu32TOT[u16TxIPduTOIx] = (uint32)0;
         SchM_Exit_Com_TimeoutTimer();
          /* Com-CDD-TxHandler-0349(0) */
          /* Com-CDD-TxHandler-5709(0) */
          /* Fixed Bug# 46522 and Bug# 46391
          clear ComTxConfWaitFlag for TxPduId I-PDU
          For Direct TxMode and Direct part of Mixed TxMode clear after all
          repetitions are confirmed */
			
		  /* !Deviation: [0277]  ( An Integer Constant experssion with negative value is being converted to an unsigned type)  */
		  /*PRQA S 0277 ++ */
		  #if u16NO_OF_IPDUS_STATUS > 0u
		 SchM_Enter_Com_IPduStatus_40();
		 SchM_Enter_Com_IPduStatus_26();
		  Com_audteIPduStatus[u16TxPduId] &= (Com_udtIPduStatus)(~Com_u8WAIT_CONF); 
		 SchM_Exit_Com_IPduStatus_26();
	     SchM_Exit_Com_IPduStatus_40();
		  #endif
		  
		  /*PRQA S 0277 -- */
        }
      }
      else
      {
#endif
        /* Com-CDD-TxHandler-0349(0) */
        /* Com-CDD-TxHandler-5709(0) */
        /* Fixed Bug# 46522 and Bug# 46391
        clear ComTxConfWaitFlag for TxPduId I-PDU
        For Direct TxMode and Direct part of Mixed TxMode clear after all
        repetitions are confirmed */

	    /* !Deviation: [0277]  ( An Integer Constant experssion with negative value is being converted to an unsigned type)  */
		/*PRQA S 0277 ++ */
		#if u16NO_OF_IPDUS_STATUS > 0u
	   SchM_Enter_Com_IPduStatus_40();
	   SchM_Enter_Com_IPduStatus_26();
		Com_audteIPduStatus[u16TxPduId] &= (Com_udtIPduStatus)(~Com_u8WAIT_CONF); 
		SchM_Exit_Com_IPduStatus_26();
	   SchM_Exit_Com_IPduStatus_40();
		#endif
		
		/*PRQA S 0277 -- */
#if (Com_bTO_SUPPORT == STD_ON) 
      }
#endif
    
    if((pkstrTxIPduPtr->pfvidIPduNotifPtr != NULL_PTR) &&
       ((pkstrTxIPduPtr->udteTxIPduFlags & Com_u8TX_IPDUSIGPROCESSING)
        == Com_u8SIG_PROC_IMMEDIATE))
      {
        /* Com-CDD-TxHandler-0440(0) */
        /* Com-CDD-TxHandler-5724(0) */
        
        /*! Call ComNotification */
        (*pkstrTxIPduPtr->pfvidIPduNotifPtr)();
      }
    else if(pkstrTxIPduPtr->pfvidIPduNotifPtr != NULL_PTR) /* signal proccessing = DEFERRED*/
      {
		#if u16NO_OF_IPDUS_STATUS > 0u
	   SchM_Enter_Com_IPduStatus_40();
	   SchM_Enter_Com_IPduStatus_26();
        Com_audteIPduStatus[u16TxPduId] |= Com_u8DEF_PROC_MASK;  
		SchM_Exit_Com_IPduStatus_26();
	   SchM_Exit_Com_IPduStatus_40();
		#endif
      }
	 else
	  {
		
	  }
     }
	 
#if (Com_bMDT_SUPPORT == STD_ON) 
    /*! if I-PDU has configured MDT */
	u16MDTimerIx = pkstrTxIPduPtr->u16MDTimerIndex ;
	if(u16MDTimerIx != (uint16)0xFFFFu)
    {
      /* Com-CDD-TxHandler-0350(0) */
      /* Com-CDD-TxHandler-5722(0) */
      /*! Reload MDT timer only if not equal zero */
      if(*(pku32GET_MD_TIMER(u16MDTimerIx)) !=   (uint32) 0)
      {
        pu32MDTimerPtr = pku32GET_MD_TIMER(0);
       SchM_Enter_Com_MDT();
        (pu32MDTimerPtr[u16MDTimerIx]) =(pkstrTxIPduPtr->u32MinimumDelayTime);
       SchM_Exit_Com_MDT();
      }
      else
      {

      }
    }
#endif

  } /* Com_bIpduCheckActive(TxPduId) == TRUE */
  else
  {
    /* Com-CDD-TxHandler-0027(0) */
    /* I-PDU is not active*/
  }
} /* vidTxConfirmation */
/* PRQA S 4700 -- */

/******************************************************************************/
/*! \Description The lower layer communication module confirms the \n
                 transmission of an I-PDU.
    \param[in]  TxPduId The lower layer communication module confirms the \n
                transmission of an I-PDU.
    \param[in,out]  None
*******************************************************************************/
/*! \Trace_To Com-CDD-TxHandler-0437(0),
              Com-CDD-TxHandler-0438(0),
              Com-CDD-TxHandler-0439(0),
              Com-CDD-TxHandler-0443(0),
              Com-CDD-0245(0), Com-CDD-0246(0), 
			  Com-CDD-5746(0), Com-CDD-5371(1) */
FUNC(void, COM_CODE) Com_TxConfirmation(VAR(PduIdType, AUTOMATIC) TxPduId)
{
  /*! Local variables */
  VAR(boolean, AUTOMATIC)                bIPduWaitForConf;
  VAR(tstrTxConfirmationData, AUTOMATIC) strTxConfirmationData;
  strTxConfirmationData.bTCLConfirmSignals = FALSE;

  /*! DET check and reporting */
#if (COM_DEV_ERROR_DETECT == STD_ON)
  /* Com-CDD-TxHandler-0437(0) */
  if (Com_enueStatus == COM_UNINIT)
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_TxConfirmation , COM_E_UNINIT);
/* PRQA S 3212 -- */
  }
  /* Com-CDD-TxHandler-0438(0) */
  else if (TxPduId > Com_u16TXIPDUIDMAX)
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_TxConfirmation , COM_E_PARAM);
/* PRQA S 3212 -- */
  }
  else if ((u8IPDU_GET_DIR(TxPduId) != (uint8) Com_u8DIRECTION_TX) ||
           (u8TXIPDU_GET_TYPE(u16IPDU_GET_IX(TxPduId)) !=
                                                        Com_u8IPDU_TYPE_NORMAL))
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_TxConfirmation , COM_E_PARAM);
/* PRQA S 3212 -- */
  }
  else /*! no DET error */
#endif /*COM_DEV_ERROR_DETECT*/
  {
	#if u16NO_OF_IPDUS_STATUS > 0u
	SchM_Enter_Com_IPduStatus_40();
	bIPduWaitForConf = (boolean)(Com_audteIPduStatus[TxPduId] & Com_u8WAIT_CONF);
	SchM_Exit_Com_IPduStatus_40();
	#endif
	
    /*! Process confirmation only if TxConfWaitFlag is set */
    if(bIPduWaitForConf != FALSE)
    {
      vidTxConfirmation(TxPduId,
                        NTFRSLT_OK,
                        Com_u8IPDU_TYPE_NORMAL,
                        &strTxConfirmationData);
    }
    else
    {

    }
  }
} /* Com_TxConfirmation() */

/******************************************************************************/
/*! \Description  This function is called by the PduR after a large I-PDU has \n
                  been transmitted via the transport protocol on its network.
    \param[in]  PduId ID of the I-PDU that has been transmitted.
    \param[in]  Result Result of the transmission of the I-PDU
    \param[in,out]  None
*******************************************************************************/
/*! \Trace_To   Com-CDD-TxHandler-0441(0),
                Com-CDD-TxHandler-0442(0),
                Com-CDD-TxHandler-0443(0),
                Com-CDD-0247(0), Com-CDD-5746(0), Com-CDD-5371(1) */
#if (Com_bDATA_TP_SUPPORT == STD_ON) 
FUNC(void, COM_CODE) Com_TpTxConfirmation(VAR(PduIdType, AUTOMATIC) PduId,
                                          VAR(Std_ReturnType, AUTOMATIC)
                                                                    Result)
{
  /*! Local variables */
  VAR(boolean, AUTOMATIC)                bIPduWaitForConf;

  VAR(tstrTxConfirmationData, AUTOMATIC) strTxConfirmationData;

  /*! Main Post-build configuration pointer cashing */
  /*strTxConfirmationData.pkstrTCLMainPBConf = Com_pkstreMainConfig;*/

  strTxConfirmationData.bTCLConfirmSignals = FALSE;

  /*! DET check and reporting */
#if (COM_DEV_ERROR_DETECT == STD_ON)
  /* Com-CDD-TxHandler-0441(0) */
  if (Com_enueStatus == COM_UNINIT)
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                          COMServiceId_TpTxConfirmation , COM_E_UNINIT);
/* PRQA S 3212 -- */
  }
  /* Com-CDD-TxHandler-0442(0) */
  else if (PduId > Com_u16TXIPDUIDMAX)
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                          COMServiceId_TpTxConfirmation , COM_E_PARAM);
/* PRQA S 3212 -- */
  }
  /* Com-CDD-TxHandler-0442(0) */
  else if ((u8IPDU_GET_DIR(PduId) != (uint8) Com_u8DIRECTION_TX) ||
           (u8TXIPDU_GET_TYPE(u16IPDU_GET_IX(PduId))
                                                    != Com_u8IPDU_TYPE_TP))
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                          COMServiceId_TpTxConfirmation , COM_E_PARAM);
/* PRQA S 3212 -- */
  }
  else /*! no DET error */
#endif /*COM_DEV_ERROR_DETECT*/
  {
	#if u16NO_OF_IPDUS_STATUS > 0u
	SchM_Enter_Com_IPduStatus_26();
	bIPduWaitForConf = Com_audteIPduStatus[PduId] & Com_u8WAIT_CONF;
	SchM_Exit_Com_IPduStatus_26();
	#endif
	
    /*! Process confirmation only if TxConfWaitFlag is set */
    if(bIPduWaitForConf != FALSE)
    {
      vidTxConfirmation(PduId,
                        Result,
                        Com_u8IPDU_TYPE_TP,
                        &strTxConfirmationData);
    }
    else
    {

    }
    strTxConfirmationData.u16TCLCurrentIPduIndex
                    = u16IPDU_GET_IX(PduId);
    /*! Clear TP byte counter for this I-PDU */
    u16TXIPDU_CLR_TP_BYTCTR(strTxConfirmationData.u16TCLCurrentIPduIndex);
  }
} /* Com_TpTxConfirmation() */

/******************************************************************************/
/*! \Description  This function returns TRUE if the I-PDU identefied by \n
u16PduId contains signal which has  dynamic length.
    \param[in]  u16PduId ID of the I-PDU to be checked.
*******************************************************************************/
static FUNC(boolean, COM_CODE) bTPIPduIsDynamic(VAR(PduIdType, AUTOMATIC)
                                                                    u16PduId)
{
  /*! Local variables */
  VAR(boolean, AUTOMATIC)               bReturnValue;
  VAR(uint8, AUTOMATIC)                 u8CurrLastSigStrType;
  VAR(uint16, AUTOMATIC)                u16CurrentIPduIndex;
  VAR(uint16, AUTOMATIC)                u16CurrentNoOfSig;
  VAR(uint16, AUTOMATIC)                u16CurrentSigMapIndex;
  VAR(uint16, AUTOMATIC)                u16CurrentLastSigIx;
  P2CONST(Com_tstrTxIPdu,AUTOMATIC,COM_CALIB_CONST) pkstrLocTXIpduPB;
  P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF) pkstrIPduToSigMap;

  bReturnValue = FALSE;

  u16CurrentIPduIndex   = u16IPDU_GET_IX(u16PduId);
  pkstrLocTXIpduPB = pkstrGET_TX_IPDU_PTR(u16CurrentIPduIndex);
  u16CurrentNoOfSig     = pkstrLocTXIpduPB->u16IPduNoOfSignals;
  u16CurrentSigMapIndex = pkstrLocTXIpduPB->u16IPduSigMappingIndex;

   pkstrIPduToSigMap = pkstrGET_IPDU_SIG_MAP_PTR(
			((u16CurrentSigMapIndex + u16CurrentNoOfSig) - 1));
  u16CurrentLastSigIx = pkstrIPduToSigMap->u16Index;
  u8CurrLastSigStrType = pkstrIPduToSigMap->u8Type;
  
  if(u8CurrLastSigStrType == (uint8)Com_u8SIGNAL)
  {
    if(u8SIG_GET_TYPE(u16CurrentLastSigIx) == Com_u8SIGNAL_TYPE_UINT8DYN)
    {
      bReturnValue = TRUE;
    }
    else
    {

    }
  }
  else
  {

  }
  return bReturnValue;
}

/******************************************************************************/
/*! \Description  Function The service Com_SwitchIpduTxMode sets the 
     transmission mode of the I-PDU referenced by PduId to Mode.
     In case the transmission mode changes, the new mode shall immediately be 
	 effective (see COM239).
     In case the requested transmission mode was already active for this I-PDU,
	 the call will have no effect.
*******************************************************************************/
/*! \Trace_To     Com-CDD-0501(0) */
/* !Deviation: [3673]  This Api is empty (4.1.2 specific) */
/* PRQA S 3206 ++ */
FUNC(void, COM_CODE) Com_SwitchIpduTxMode(VAR(PduIdType, AUTOMATIC)
                                                                  PduId,
												 VAR(boolean, AUTOMATIC) 
												                  Mode)
/* PRQA S 3206 -- */
{
	/* NOT SUPPORTED : 4.1.2 specific */
}

/******************************************************************************/
/*! \Description  Function to estimate the dynamic IPDU length.
    \param[in]  u16DynPduId ID of the I-PDU which length to be estimated.
*******************************************************************************/
/*! \Trace_To     Com-CDD-TxHandler-5714(0) */
static FUNC(uint16, COM_CODE) u16GetDynIPduLength(VAR(PduIdType, AUTOMATIC)
                                                                    u16DynPduId)
{
  /*! Local variables */
  VAR(uint16, AUTOMATIC)                u16DynLength;
  VAR(uint16, AUTOMATIC)                u16CurrIPduMaxLength;

  P2VAR(uint8, AUTOMATIC,COM_CALIB_DATA)
                                        pu8CurrentIPduBuff;
  P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF) pkTxIPdu;

  u16DynLength = 0x0000;
  pkTxIPdu = pkstrGET_TX_IPDUPTR_BYID(u16DynPduId);
  pu8CurrentIPduBuff    = pu8TXIPDU_GET_BUFF_PTR(pkTxIPdu->u32IPduBufferIndex);
  u16CurrIPduMaxLength = pkTxIPdu->u16IPduLength;

  u16DynLength = u16DynLength | (uint16) pu8CurrentIPduBuff[u16CurrIPduMaxLength];
  u16DynLength = u16DynLength << 8;
  u16DynLength = u16DynLength | (uint16) pu8CurrentIPduBuff[u16CurrIPduMaxLength + 1];

  return u16DynLength;
}
#endif /*Com_bDATA_TP_SUPPORT*/

/******************************************************************************/
/*! \Description  At invocation of Com_CopyTxData the AUTOSAR COM module \n
                  copy the requested transmit data of the large IPDU with ID \n
                  PduId from its internal transmit buffer to the location \n
                   specified by the PduInfoPtr. The function Com_CopyTxData \n
                   also calculates and sets the TxDataCntPtr to the amount \n
                   of remaining bytes for the transmission of this large I-PDU.
    \param[in]  PduId ID of Tp I-PDU to be transmitted
    \param[in]  PduInfoPtr  Pointer to a PduInfoType, which indicates \n
                            the number of bytes to be copied (SduLength) \n
                            and the location where the data have to be \n
                            copied to (SduDataPtr). An SduLength of 0 is \n
                            possible in order to poll the available transmit \n
                            data count. In this case no data are to be \n
                            copied and SduDataPtr might be invalid.
    \param[in]  RetryInfoPtr If the transmitted TP I-PDU does not support \n
                the retry feature a NULL_PTR can be provided. \n
                Alternatively, TpDataState can indicate TP_NORETRY. \n
                Both indicate that the copied trans-mit data can be removed \n
                from the buffer after it has been copied.
    \param[out]  TxDataCntPtr Remaining Tx data after completion of this call.

*******************************************************************************/
/*! \Trace_To     Com-CDD-TxHandler-0121(0),
                  Com-CDD-TxHandler-0444(0),
                  Com-CDD-TxHandler-0445(0),
                  Com-CDD-TxHandler-0446(0),
                  Com-CDD-TxHandler-0447(0),
                  Com-CDD-TxHandler-0032(0),
                  Com-CDD-TxHandler-0034(0),
                  Com-CDD-TxHandler-5717(0),
				  Com-CDD-5746(0), Com-CDD-5371(1) */
/* !Deviation: [3673]  the following prototype is required by AUTOSAR */
/* PRQA S 3673 ++ */
#if (Com_bDATA_TP_SUPPORT == STD_ON) 
FUNC(BufReq_ReturnType, COM_CODE) Com_CopyTxData(
                    VAR(PduIdType, AUTOMATIC)                     PduId,
                    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA)  PduInfoPtr,
                    P2VAR(RetryInfoType, AUTOMATIC, COM_APPL_DATA)RetryInfoPtr,
                    P2VAR(PduLengthType, AUTOMATIC,COM_APPL_DATA)
                                                                  TxDataCntPtr )
/* PRQA S 3673 -- */
{
  /*! Local variables */
  VAR(boolean, AUTOMATIC)               bIPduWaitForConf;
  VAR(boolean, AUTOMATIC)               bIPduState;
  VAR(boolean, AUTOMATIC)               bDynamicIPdu;
  VAR(uint16, AUTOMATIC)                u16CurrIPduLength;
  VAR(uint16, AUTOMATIC)                u16CurrIPduIndex;
  VAR(uint16_least, AUTOMATIC)          u16ByteLoopIndex;

  VAR(uint16, AUTOMATIC)                u16CurrRemainDataCnt;
  VAR(uint16, AUTOMATIC)                u16CurrStartIndex;
  VAR(uint16, AUTOMATIC)                u16TpIPduCtrIx;

  VAR(TpDataStateType, AUTOMATIC)       enuRetryState;

  P2VAR(uint8, AUTOMATIC,COM_CALIB_DATA)
                                        pu8CurrentIPduBuff;
  P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF) pkTxIPdu; 

  P2VAR(uint8, AUTOMATIC, AUTOSAR_COMSTACKDATA)  pu8DataPtr;
    P2VAR(PduLengthType, AUTOMATIC, AUTOSAR_COMSTACKDATA)  pudtLengthPtr;
  /*! Main Post-build configuration pointer cashing */
  VAR(BufReq_ReturnType, AUTOMATIC)     enuReturnValue;  
  enuReturnValue = BUFREQ_E_NOT_OK;
  /*! DET check and reporting */
#if (COM_DEV_ERROR_DETECT == STD_ON)
  /*  */
  if (Com_enueStatus == COM_UNINIT)
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    /* Com-CDD-TxHandler-0444(0) */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                          COMServiceId_CopyTxData , COM_E_UNINIT);
/* PRQA S 3212 -- */
  }
  else if ((PduId > Com_u16TXIPDUIDMAX)  ||
           (u8IPDU_GET_DIR(PduId) != (uint8) Com_u8DIRECTION_TX) ||
           (u8TXIPDU_GET_TYPE(u16IPDU_GET_IX(PduId)) != Com_u8IPDU_TYPE_TP))
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    /* Com-CDD-TxHandler-0445(0) */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                          COMServiceId_CopyTxData , COM_E_PARAM);
/* PRQA S 3212 -- */
  }
  else if ((PduInfoPtr   == NULL_PTR) ||
           (TxDataCntPtr == NULL_PTR))
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    /* Com-CDD-TxHandler-0446(0) */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                          COMServiceId_CopyTxData , COM_E_PARAM_POINTER);
/* PRQA S 3212 -- */
  }
  else /*! no DET error */
#endif /*COM_DEV_ERROR_DETECT*/
  {
    pu8DataPtr = PduInfoPtr->SduDataPtr;
    pudtLengthPtr = &(PduInfoPtr->SduLength);
	
	#if u16NO_OF_IPDUS_STATUS > 0u
	SchM_Enter_Com_IPduStatus_24();
	bIPduWaitForConf = Com_audteIPduStatus[PduId] & Com_u8WAIT_CONF;
    bIPduState = Com_bIpduCheckActive(PduId);
	SchM_Exit_Com_IPduStatus_24();
	#endif
	
    u16CurrIPduIndex = u16IPDU_GET_IX(PduId);
	pkTxIPdu = pkstrGET_TX_IPDU_PTR(u16CurrIPduIndex);
    /* Com-CDD-TxHandler-0032(0) */
	u16TpIPduCtrIx = pkTxIPdu->u16TpIPduByteCtrIndex;
    if((bIPduWaitForConf != FALSE) &&
       (bIPduState == TRUE))
    {
      if(RetryInfoPtr != NULL_PTR)
      {
        enuRetryState = RetryInfoPtr->TpDataState;
      }
      else /* RetryInfoPtr == NULL_PTR */
      {
        enuRetryState = TP_NORETRY;
      }

      bDynamicIPdu = bTPIPduIsDynamic(PduId);

      if(bDynamicIPdu == FALSE)
      {
        u16CurrIPduLength = pkTxIPdu->u16IPduLength;
      }
      else /* bDynamicIPdu == TRUE */
      {
        u16CurrIPduLength = u16GetDynIPduLength(PduId);
      }

      if((enuRetryState == TP_DATARETRY) &&
         (RetryInfoPtr != NULL_PTR)      &&
         (RetryInfoPtr->TxTpDataCnt < u16CurrIPduLength))
      {
        u16TXIPDU_SET_TPBYTECNT(u16TpIPduCtrIx,
                                ((u16CurrIPduLength -
                                  RetryInfoPtr->TxTpDataCnt) - 1));
      }
      else
      {

      }

      u16CurrRemainDataCnt = u16TXIPDU_GET_TPBYTECNT(u16TpIPduCtrIx);
      /*! If SduLength > no. of bytes remaining in buffer, stop procrssing and
      return error*/
      if(PduInfoPtr->SduLength <= u16CurrRemainDataCnt)
      {
        u16CurrStartIndex = (u16CurrIPduLength - u16CurrRemainDataCnt);
        pu8CurrentIPduBuff      = pu8TXIPDU_GET_BUFF_PTR(pkTxIPdu->u32IPduBufferIndex);
        for(u16ByteLoopIndex = (uint16)0;
        u16ByteLoopIndex < (*pudtLengthPtr);
        u16ByteLoopIndex++)
        {
          pu8DataPtr[u16ByteLoopIndex] =
                      pu8CurrentIPduBuff[u16ByteLoopIndex + u16CurrStartIndex];
          u16CurrRemainDataCnt = u16CurrRemainDataCnt - (uint16)1;
        }
		
        u16TXIPDU_SET_TPBYTECNT(u16TpIPduCtrIx,
                                u16CurrRemainDataCnt);
        *TxDataCntPtr = u16CurrRemainDataCnt;
        enuReturnValue = BUFREQ_OK;
      }
      else
      {
        *TxDataCntPtr = u16CurrRemainDataCnt;
        enuReturnValue = BUFREQ_E_NOT_OK;
      }
    }
    else
    {
      /* Com-CDD-TxHandler-0034(0) */
      /* Com-CDD-TxHandler-5717(0) */
      u16TXIPDU_CLR_TPBYTECNT(u16TpIPduCtrIx);
      *TxDataCntPtr = (PduLengthType)0;
      enuReturnValue = BUFREQ_E_NOT_OK;
    }
  }
  return enuReturnValue;
} /* Com_CopyTxData */
#endif	/* Com_bDATA_TP_SUPPORT */
/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
Partitioning this function shall not pay for the negative effect of context
switching. */
/* PRQA S 4700 ++ */
/* !Deviation: [3206, 3204]  Due to differnt combinations of Pre-compile options
 some parameters shall not be used */
/* PRQA S 3206 ++ */
/* PRQA S 3204 ++ */
/******************************************************************************/
/*! \Description The service Com_InvalidateSignal invalidates the signal \n
                 with the given SignalId by setting its value to its \n
                 configured ComSignalDataInvalidValue.
    \param[in]  SignalId Id of signal to be invalidated.
*******************************************************************************/
/*! \Trace_To Com-CDD-TxHandler-0117(0),
              Com-CDD-TxHandler-0423(0),
              Com-CDD-TxHandler-0421(0),
              Com-CDD-TxHandler-0422(0),
              Com-CDD-TxHandler-0231(0),
              Com-CDD-TxHandler-0229(0),
              Com-CDD-TxHandler-0008(0),
              Com-CDD-TxHandler-0227(0),
              Com-CDD-0227(0),
              Com-CDD-TxHandler-0232(0) */
#if (Com_bDATA_INVALID_SUPPORT == STD_ON)
FUNC(uint8, COM_CODE) Com_InvalidateSignal( VAR(Com_SignalIdType, AUTOMATIC)
                                                                      SignalId )
{
/* PRQA S 3206 -- */
  /*! Local variables */
  VAR(boolean, AUTOMATIC)       bIPduIsActive;
/* PRQA S 3204 -- */
  VAR(PduIdType, AUTOMATIC)     u16CurrentIPduId;
  VAR(uint16, AUTOMATIC)        u16SigInvalidValIx;
  P2CONST(Com_tstrSignalPB,AUTOMATIC,COM_CALIB_CONST)       pkstrLocSigPB;
  
  VAR(uint16, AUTOMATIC)        u16CurrentSigIx;
  VAR(uint8, AUTOMATIC)         u8ReturnValue;
  VAR(uint8, AUTOMATIC)         u8SigType;
/* !Deviation: [3198] Redundant assignment is intended to keep variable valid
in case Com_u16NO_OF_SIGNAL == 0 */
/* PRQA S 3198 ++ */
  u8ReturnValue = COM_SERVICE_NOT_AVAILABLE;
/* PRQA S 3198 -- */

  /*! DET check and reporting */
#if (COM_DEV_ERROR_DETECT == STD_ON)
  /* Com-CDD-TxHandler-0421(0) */
  if (Com_enueStatus == COM_UNINIT)
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_InvalidateSignal , COM_E_UNINIT);
    u8ReturnValue = COM_SERVICE_NOT_AVAILABLE;

/* PRQA S 3212 -- */
  }
#if Com_u16NO_OF_SIGNAL > 0u
  /* Com-CDD-TxHandler-0422(0) */
  else if (SignalId > Com_u16SIGNALIDMAX)
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_InvalidateSignal , COM_E_PARAM);
    u8ReturnValue = COM_SERVICE_NOT_AVAILABLE;
/* PRQA S 3212 -- */
  }
  else if ((u8SIG_GET_STRUCT_TYPE(SignalId) !=
                                                (uint8) Com_u8SIG_STRUCT_SIG) ||
           (u8SIG_GET_DIR(u16SIG_GET_LKUP_IX(SignalId)) != Com_u8SIG_DIR_SEND) ||
           (u8SIG_GET_TYPE(u16SIG_GET_LKUP_IX(SignalId)) == Com_u8SIGNAL_TYPE_UINT8N) ||
           (u8SIG_GET_TYPE(u16SIG_GET_LKUP_IX(SignalId)) == Com_u8SIGNAL_TYPE_UINT8DYN))
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_InvalidateSignal , COM_E_PARAM);
    u8ReturnValue = COM_SERVICE_NOT_AVAILABLE;
/* PRQA S 3212 -- */
  }
#endif
  else
#endif /*COM_DEV_ERROR_DETECT*/
  {
#if Com_u16NO_OF_SIGNAL > 0u
	u16CurrentSigIx = u16SIG_GET_LKUP_IX(SignalId); 
	u8SigType = u8SIG_GET_TYPE(u16CurrentSigIx);
    pkstrLocSigPB = pkstrGET_PB_SIGNAL_PTR(u16CurrentSigIx);
	u16CurrentIPduId  = pkstrLocSigPB->u16IPduIndex;
    /* Com-CDD-0227(0) */
    /* Com-CDD-TxHandler-0231(0) */
	
	u16SigInvalidValIx = Com_akstreSignalLT[u16CurrentSigIx].u16SigInvalidValIndex;
    if(u16SigInvalidValIx == (uint16)0xFFFFu)
    {
      u8ReturnValue = COM_SERVICE_NOT_AVAILABLE;
    }
    else
    {
      /* Com-CDD-TxHandler-0229(0) */
	  SchM_Enter_Com_IPduStatus_10();
      bIPduIsActive = Com_bIpduCheckActive(u16CurrentIPduId);
	  SchM_Exit_Com_IPduStatus_10();
	   
      if(bIPduIsActive == FALSE)
      {
        u8ReturnValue = COM_SERVICE_NOT_AVAILABLE;
      }
      /* Com-CDD-TxHandler-0008(0) */
      else
      {
        u8ReturnValue = E_OK;
      }
	  
      switch(u8SigType)
      {
      /* Com-CDD-TxHandler-0227(0) */
        case Com_u8SIGNAL_TYPE_BOOLEAN:
#if Com_u16SIG_INV_V_B_SIZE > 0u
        /* Com-CDD-TxHandler-0232(0) */
        u8ReturnValue =
          Com_SendSignal( SignalId,
                          &Com_akbeSigInvalidValB[u16SigInvalidValIx]
                        );
#endif
        break;
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON)
        case Com_u8SIGNAL_TYPE_FLOAT32:
#if Com_u16SIG_INV_V_F32_SIZE > 0u
        /* Com-CDD-TxHandler-0232(0) */
        u8ReturnValue =
          Com_SendSignal( SignalId,
                          &Com_akf32eSigInvalidValF32[u16SigInvalidValIx]
                        );
#endif
        break;
        case Com_u8SIGNAL_TYPE_FLOAT64:
#if Com_u16SIG_INV_V_F64_SIZE > 0u
        /* Com-CDD-TxHandler-0232(0) */
        u8ReturnValue =
          Com_SendSignal( SignalId,
                          &Com_akf64eSigInvalidValF64[u16SigInvalidValIx]
                        );
#endif
        break;
#endif
        case Com_u8SIGNAL_TYPE_SINT16:
#if Com_u16SIG_INV_V_S16_SIZE > 0u
        /* Com-CDD-TxHandler-0232(0) */
        u8ReturnValue =
          Com_SendSignal( SignalId,
                          &Com_aks16eSigInvalidValS16[u16SigInvalidValIx]
                        );
#endif
        break;
        case Com_u8SIGNAL_TYPE_SINT32:
#if Com_u16SIG_INV_V_S32_SIZE > 0u
        /* Com-CDD-TxHandler-0232(0) */
        u8ReturnValue =
          Com_SendSignal( SignalId,
                          &Com_aks32eSigInvalidValS32[u16SigInvalidValIx]
                        );
#endif
        break;
        case Com_u8SIGNAL_TYPE_SINT8:
#if Com_u16SIG_INV_V_S8_SIZE > 0u
        /* Com-CDD-TxHandler-0232(0) */
        u8ReturnValue =
          Com_SendSignal( SignalId,
                          &Com_aks8eSigInvalidValS8[u16SigInvalidValIx]
                        );
#endif
        break;
        case Com_u8SIGNAL_TYPE_UINT16:
#if Com_u16SIG_INV_V_U16_SIZE > 0u
        /* Com-CDD-TxHandler-0232(0) */
        u8ReturnValue =
          Com_SendSignal( SignalId,
                          &Com_aku16eSigInvalidValU16[u16SigInvalidValIx]
                        );
#endif
        break;
        case Com_u8SIGNAL_TYPE_UINT32:
#if Com_u16SIG_INV_V_U32_SIZE > 0u
        /* Com-CDD-TxHandler-0232(0) */
        u8ReturnValue =
          Com_SendSignal( SignalId,
                          &Com_aku32eSigInvalidValU32[u16SigInvalidValIx]
                        );
#endif
        break;
        case Com_u8SIGNAL_TYPE_UINT8:
#if Com_u16SIG_INV_V_U8U8N_SIZE > 0u
        /* Com-CDD-TxHandler-0232(0) */
        u8ReturnValue =
          Com_SendSignal( SignalId,
                          &Com_aku8eSigInvalidValU8U8N[u16SigInvalidValIx]
                        );
#endif
        break;
        case Com_u8SIGNAL_TYPE_UINT8N:
        case Com_u8SIGNAL_TYPE_UINT8DYN:
          /* Not apllicable */
        break;
        default:

        break;
      }
    }
#endif /* Com_u16NO_OF_SIGNAL > 0u */
  }
  return u8ReturnValue;
} /* Com_InvalidateSignal() */
/* PRQA S 4700 -- */
#endif /*Com_bDATA_INVALID_SUPPORT*/

#if (Com_bTMS_SUPPORT == STD_ON) 
/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
Partitioning this function shall not pay for the negative effect of context
switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description This function handles Com_SendSignal processing in case: \n
                  TxMode Switch Happened && \n
                  IPDU state = Active && \n
                  MDT Elapsed \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To       Com-CDD-TxHandler-0011(0),
                    Com-CDD-TxHandler-0012(0),
                    Com-CDD-TxHandler-0287(0),
                    Com-CDD-TxHandler-0323(0),
                    Com-CDD-TxHandler-0288(0),
                    Com-CDD-TxHandler-0324(0),
                    Com-CDD-TxHandler-0289(0),
                    Com-CDD-TxHandler-0325(0),
                    Com-CDD-TxHandler-0290(0),
                    Com-CDD-TxHandler-0326(0),
                    Com-CDD-TxHandler-0291(0),
                    Com-CDD-TxHandler-0327(0),
                    Com-CDD-TxHandler-0308(0),
                    Com-CDD-TxHandler-0343(0),
                    Com-CDD-TxHandler-0313(0),
					Com-CDD-5746(0), Com-CDD-5371(1) */
static FUNC(void, COM_CODE) vidHandleSendSignalTTT(
            P2VAR(tstrSendSignalData,
                  AUTOMATIC, COM_VAR) pkudtSendSignalData)
{
  P2VAR(Com_tu32TxModeTimer,AUTOMATIC,TYPEDEF)pu32TxModTimr;
  P2CONST(Com_tstrTxModePeriodic,AUTOMATIC,TYPEDEF)pkstrTxModPrdic;
  P2CONST(Com_tstrTxModePeriodic,AUTOMATIC,TYPEDEF)pkstrTxModPrdicLoc;
  P2VAR(uint16, AUTOMATIC,AUTOMATIC)pu16SSLNewTxModeIdx;
  P2VAR(PduIdType, AUTOMATIC,AUTOMATIC)pu16SSLCrntIPduId;
  P2CONST(Com_tstrTxModeMixed,AUTOMATIC,TYPEDEF) pkstrTxModeMixedPtr;
  P2CONST(Com_tstrTxModeDirect,AUTOMATIC,TYPEDEF) pkstrTxModeDirectPtr;

  pu32TxModTimr = pku32GET_TX_MODE_TIMER(0);
  pkstrTxModPrdicLoc = u8PERTXMODE_GET_PTR(0);
  pu16SSLNewTxModeIdx = &(pkudtSendSignalData->u16SSLNewTxModeIndex);
  pu16SSLCrntIPduId = &(pkudtSendSignalData->u16SSLCurrentIPduId);
  switch (pkudtSendSignalData->u8SSLNewTxModeType)
  {
    case Com_u8TX_MODE_MIXED:
    /*! In case of Mixed TxMode, Mark I-PDU for send */
    /* Com-CDD-TxHandler-0288(0) */
	pkstrTxModeMixedPtr = 
	u8MIXTXMODE_GET_PTR(*pu16SSLNewTxModeIdx); 
    pkudtSendSignalData->bSSLSendIPdu = TRUE;
   
    /*! If TMS switch change occurs to PERIODIC or MIXED, reload the \n
    ComTxModeTimePeriodTimer with ComTxModeTimePeriod value. */
    /* Com-CDD-TxHandler-0287(0) */
    (pu32TxModTimr[pkstrTxModeMixedPtr->u16TimerIndex]) =
              (pkstrTxModeMixedPtr->u32TimePeriod);
   
#if (Com_bNTIMES_SUPPORT == STD_ON)
    if((pkudtSendSignalData->u8SSLCurrentTxProperty == Com_u8TXPROP_TRIGGERED) ||
	((pkudtSendSignalData->u8SSLCurrentTxProperty == Com_u8TXPROP_TRIG_CHANGE) && 
		(pkudtSendSignalData->bSSLSignalIsChanged == TRUE)))
    {
      if((pkstrTxModeMixedPtr->u8NumberOfRepetitions) > 0)
      {
	    /*! Load Repetitions counter & period*/
        /* Com-CDD-TxHandler-0288(0) */
        u8TXMODE_RLD_REPCTR(pkstrTxModeMixedPtr);
		pku32RLD_PERIODIC_MOD_TMR(pkstrTxModeMixedPtr);
      }
    }
    else /* u8CurrentTxProperty == Com_u8TXPROP_PENDING */
    {

    }
#endif
    break;
    case Com_u8TX_MODE_PERIODIC:
    /*! In case of Mixed TxMode, Mark I-PDU for send */
    /* Com-CDD-TxHandler-0288(0) */
	pkstrTxModPrdic = &pkstrTxModPrdicLoc[*pu16SSLNewTxModeIdx]; 
    pkudtSendSignalData->bSSLSendIPdu = TRUE;
   
    /*! If TMS switch change occurs to PERIODIC or MIXED, reload the \n
    ComTxModeTimePeriodTimer with ComTxModeTimePeriod value. */
    /* Com-CDD-TxHandler-0287(0) */
    (pu32TxModTimr[pkstrTxModPrdic->u16TimerIndex]) =
            (pkstrTxModPrdic->u32TimePeriod);
   
    break;
    case Com_u8TX_MODE_DIRECT:
    /* Com-CDD-TxHandler-0289(0) */
	pkstrTxModeDirectPtr = 
	u8DIRTXMODE_GET_PTR(*pu16SSLNewTxModeIdx); 
    pkudtSendSignalData->bSSLSendIPdu = TRUE;
	
	#if u16NO_OF_IPDUS_STATUS > 0u
	SchM_Enter_Com_IPduStatus_19();
	Com_audteIPduStatus[(*pu16SSLCrntIPduId)] |= Com_u8WAIT_CONF;
	SchM_Exit_Com_IPduStatus_19();
	#endif
	
	
    /* Com-CDD-TxHandler-0291(0) */
#if (Com_bNTIMES_SUPPORT == STD_ON)
    if(pkstrTxModeDirectPtr->u8NumberOfRepetitions > 0)
    {
      /* Com-CDD-TxHandler-0290(0) */
      /*! Load Repetitions counter & period*/
	  u8TXMODE_RLD_REPCTR(pkstrTxModeDirectPtr);
	  pku32RLD_PERIODIC_MOD_TMR(pkstrTxModeDirectPtr);
    }
    else
    {
    }
#endif
    break;

    case Com_u8TX_MODE_NONE:
      /* Com-CDD-TxHandler-0308(0) */
    break;

    default:

    break;
  }
}
/* PRQA S 4700 -- */

/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
Partitioning this function shall not pay for the negative effect of context
switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description This function handles Com_SendSignal processing in case: \n
                  TxMode Switch Happened && \n
                  IPDU state = Active && \n
                  MDT Not Elapsed \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To       Com-CDD-TxHandler-0011(0), \n
                    Com-CDD-TxHandler-0012(0),
                    Com-CDD-TxHandler-0287(0),
                    Com-CDD-TxHandler-0323(0),
                    Com-CDD-TxHandler-0288(0),
                    Com-CDD-TxHandler-0324(0),
                    Com-CDD-TxHandler-0289(0),
                    Com-CDD-TxHandler-0325(0),
                    Com-CDD-TxHandler-0290(0)
                    Com-CDD-TxHandler-0326(0),
                    Com-CDD-TxHandler-0291(0),
                    Com-CDD-TxHandler-0327(0),
                    Com-CDD-TxHandler-0308(0),
                    Com-CDD-TxHandler-0343(0),
                    Com-CDD-TxHandler-0313(0),
					Com-CDD-5746(0), Com-CDD-5371(1), Com-CDD-5370(1)*/
static FUNC(void, COM_CODE) vidHandleSendSignalTTF(
            P2VAR(tstrSendSignalData,
                  AUTOMATIC, COM_VAR) pkudtSendSignalData)
{
  P2VAR(PduIdType, AUTOMATIC, AUTOMATIC)pu16SSLCrntIPduId;
  P2VAR(Com_tu32TxModeTimer,AUTOMATIC,TYPEDEF)pudtTxModTimer;
  P2VAR(uint16, AUTOMATIC, AUTOMATIC)pu16SSLNewTxModIdx;
  P2CONST(Com_tstrTxModePeriodic,AUTOMATIC,TYPEDEF)pkstrTxModPrdic;
  P2CONST(Com_tstrTxModeMixed,AUTOMATIC,TYPEDEF) pkstrTxModeMixedPtr;
  P2CONST(Com_tstrTxModeDirect,AUTOMATIC,TYPEDEF) pkstrTxModeDirectPtr;

  pudtTxModTimer = pku32GET_TX_MODE_TIMER(0);
  
  pu16SSLCrntIPduId = &(pkudtSendSignalData->u16SSLCurrentIPduId);
  pu16SSLNewTxModIdx = &(pkudtSendSignalData->u16SSLNewTxModeIndex);
  
  switch (pkudtSendSignalData->u8SSLNewTxModeType)
  {
    case Com_u8TX_MODE_MIXED:
	 pkstrTxModeMixedPtr = u8MIXTXMODE_GET_PTR((*pu16SSLNewTxModIdx));
    /* Com-CDD-TxHandler-0288(0) */
	
	/*! Set IPDU needs to be send after MDT elapsed*/
	/*#if u16NO_OF_IPDUS_STATUS > 0u
	SchM_Enter_Com_IPduStatus_0D();
	Com_audteIPduStatus[*pu16SSLCrntIPduId] |= (Com_udtIPduStatus)Com_u8D_MDT_MASK; 
	SchM_Exit_Com_IPduStatus_0D();
	#endif*/
	
	pkudtSendSignalData->bIPduSignalMDTMask = TRUE;
	
	
    /*! If TMS switch change occurs to PERIODIC or MIXED, reload the \n
    ComTxModeTimePeriodTimer with ComTxModeTimePeriod value. */
    /* Com-CDD-TxHandler-0287(0) */
    (pudtTxModTimer[pkstrTxModeMixedPtr->u16TimerIndex]) =
              (pkstrTxModeMixedPtr->u32TimePeriod);
   
#if (Com_bNTIMES_SUPPORT == STD_ON)
    if((pkudtSendSignalData->u8SSLCurrentTxProperty == Com_u8TXPROP_TRIGGERED) ||
	((pkudtSendSignalData->u8SSLCurrentTxProperty == Com_u8TXPROP_TRIG_CHANGE) &&
	(pkudtSendSignalData->bSSLSignalIsChanged == TRUE)))
    {
      if((pkstrTxModeMixedPtr->u8NumberOfRepetitions) > 0)
      {
        /* Com-CDD-TxHandler-0288(0) */
        /*! Load Repetitions counter & period*/
		u8TXMODE_RLD_REPCTR(pkstrTxModeMixedPtr);
		pku32RLD_PERIODIC_MOD_TMR(pkstrTxModeMixedPtr);
      }
    }
    else /* u8CurrentTxProperty == Com_u8TXPROP_PENDING */
    {

    }
#endif
    break;
    case Com_u8TX_MODE_PERIODIC:
	pkstrTxModPrdic = u8PERTXMODE_GET_PTR(*pu16SSLNewTxModIdx);
    /* Com-CDD-TxHandler-0288(0) */

	/*! Set IPDU needs to be send after MDT elapsed*/
	/*#if u16NO_OF_IPDUS_STATUS > 0u
	SchM_Enter_Com_IPduStatus_0D();
	Com_audteIPduStatus[*pu16SSLCrntIPduId] |= (Com_udtIPduStatus)Com_u8D_MDT_MASK;
	SchM_Exit_Com_IPduStatus_0D();
	#endif*/
	
	pkudtSendSignalData->bIPduSignalMDTMask = TRUE;
   
	
    /*! If TMS switch change occurs to PERIODIC or MIXED, reload the \n
    ComTxModeTimePeriodTimer with ComTxModeTimePeriod value. */
    /* Com-CDD-TxHandler-0287(0) */
    (pudtTxModTimer[pkstrTxModPrdic->u16TimerIndex]) = (pkstrTxModPrdic->u32TimePeriod);
   
    break;
    case Com_u8TX_MODE_DIRECT:
    /* Com-CDD-TxHandler-0289(0) */
   	pkstrTxModeDirectPtr = 
	u8DIRTXMODE_GET_PTR(*pu16SSLNewTxModIdx);
	
	/*! Set IPDU needs to be send after MDT elapsed*/	
	#if u16NO_OF_IPDUS_STATUS > 0u
	SchM_Enter_Com_IPduStatus_19();
	Com_audteIPduStatus[*pu16SSLCrntIPduId] |= (Com_udtIPduStatus) (Com_u8WAIT_CONF); 
	SchM_Exit_Com_IPduStatus_19();
	#endif
	
	/*! check normal protection for function ID 0x0D*/
	/*Com_audteIPduStatus[*pu16SSLCrntIPduId] |= (Com_udtIPduStatus) (Com_u8D_MDT_MASK); */

	pkudtSendSignalData->bIPduSignalMDTMask = TRUE;
	
    /* Com-CDD-TxHandler-0291(0) */
#if (Com_bNTIMES_SUPPORT == STD_ON)
    if((pkstrTxModeDirectPtr->u8NumberOfRepetitions) > 0)
    {
      /* Com-CDD-TxHandler-0290(0) */  
	  /*! Load Repetitions counter & period*/
	  u8TXMODE_RLD_REPCTR(pkstrTxModeDirectPtr);
	  pku32RLD_PERIODIC_MOD_TMR(pkstrTxModeDirectPtr);
    }
    else
    {
    }
#endif
    break;
    case Com_u8TX_MODE_NONE:
      /* Com-CDD-TxHandler-0308(0) */
    break;

    default:

    break;
  }
}
/* PRQA S 4700 -- */
/******************************************************************************/
/*! \Description This function handles Com_SendSignal processing in case: \n
                  TxMode Switch Happened && \n
                  IPDU state = Not Active && \n
                  MDT Elapsed ot MDT is not Elapsed \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To       Com-CDD-TxHandler-0287(0),
                    Com-CDD-TxHandler-0323(0),
                    Com-CDD-TxHandler-0297(0),
                    Com-CDD-TxHandler-0308(0),
                    Com-CDD-TxHandler-0343(0),
                    Com-CDD-TxHandler-0313(0) */
static FUNC(void, COM_CODE) vidHandleSendSignalTFT(
            P2VAR(tstrSendSignalData,
                  AUTOMATIC, COM_VAR) pkudtSendSignalData)
{
  P2VAR(Com_tu32TxModeTimer,AUTOMATIC,TYPEDEF)pudtTxModTimer;
  P2CONST(Com_tstrTxModeMixed,AUTOMATIC,TYPEDEF)pkstrTxModMxd;
  P2VAR(uint16, AUTOMATIC, AUTOMATIC)pu16SSLNewTxModIdx;
  P2CONST(Com_tstrTxModePeriodic,AUTOMATIC,TYPEDEF)pkstrTxModPrdic;


  pudtTxModTimer = pku32GET_TX_MODE_TIMER(0);
  pu16SSLNewTxModIdx = &(pkudtSendSignalData->u16SSLNewTxModeIndex);
  pkudtSendSignalData->u8SSLReturnValue = COM_SERVICE_NOT_AVAILABLE;
  
  switch (pkudtSendSignalData->u8SSLNewTxModeType)
  {
    case Com_u8TX_MODE_MIXED:
	 pkstrTxModMxd = u8MIXTXMODE_GET_PTR((*pu16SSLNewTxModIdx));
   
    /*! If TMS switch change occurs to PERIODIC or MIXED, reload the \n
    ComTxModeTimePeriodTimer with ComTxModeTimePeriod value. */
    /* Com-CDD-TxHandler-0287(0) */
    (pudtTxModTimer[pkstrTxModMxd->u16TimerIndex ]) = (pkstrTxModMxd->u32TimePeriod);
   
    break;
    case Com_u8TX_MODE_PERIODIC:
	pkstrTxModPrdic = u8PERTXMODE_GET_PTR(*pu16SSLNewTxModIdx);
   
    /*! If TMS switch change occurs to PERIODIC or MIXED, reload the \n
    ComTxModeTimePeriodTimer with ComTxModeTimePeriod value. */
    /* Com-CDD-TxHandler-0287(0) */
    (pudtTxModTimer[pkstrTxModPrdic->u16TimerIndex ]) = (pkstrTxModPrdic->u32TimePeriod);
   
    break;
    case Com_u8TX_MODE_DIRECT:
      /* Com-CDD-TxHandler-0297(0) */
    break;
    case Com_u8TX_MODE_NONE:
      /* Com-CDD-TxHandler-0308(0) */
    break;

    default:

    break;
  }
}
#endif
/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
Partitioning this function shall not pay for the negative effect of context
switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description This function handles Com_SendSignal processing in case: \n
                  No TxMode Switch Happened && \n
                  IPDU state = Active && \n
                  MDT Elapsed \n
                  Current TxMode = MIXED \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To       Com-CDD-TxHandler-0011(0), \n
                    Com-CDD-TxHandler-0012(0),
                    Com-CDD-TxHandler-0294(0),
                    Com-CDD-TxHandler-0330(0),
                    Com-CDD-TxHandler-5706(0),
                    Com-CDD-TxHandler-0296(0),
                    Com-CDD-TxHandler-0332(0),
                    Com-CDD-TxHandler-5705(0),
                    Com-CDD-TxHandler-0299(0),
                    Com-CDD-TxHandler-0334(0),
                    Com-CDD-TxHandler-0315(0),
                    Com-CDD-TxHandler-0301(0),
                    Com-CDD-TxHandler-0336(0),
                    Com-CDD-TxHandler-0317(0),
                    Com-CDD-TxHandler-0306(0),
                    Com-CDD-TxHandler-0341(0),
                    Com-CDD-TxHandler-0311(0),
                    Com-CDD-TxHandler-0307(0),
                    Com-CDD-TxHandler-0342(0),
                    Com-CDD-TxHandler-0312(0),
                    Com-CDD-0497(0),
					Com-CDD-5746(0), Com-CDD-5371(1),
					Com-CDD-5747(1), Com-CDD-5545(0)*/
static FUNC(void, COM_CODE) vidHandleSendSignalFTTM(
            P2VAR(tstrSendSignalData,
                  AUTOMATIC, COM_VAR) pkudtSendSignalData)
{
  P2VAR(PduIdType, AUTOMATIC, AUTOMATIC)pu16SSLCrntIPduId;
#if (Com_bTO_SUPPORT == STD_ON) 
  P2VAR(uint32,AUTOMATIC,AUTOMATIC)pu32TOTimer;
  VAR(uint16,AUTOMATIC) u16TxIPduTOIx;
#endif

  P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF)pkstrTxIPduPtr;
  P2VAR(uint16, AUTOMATIC,AUTOMATIC)pu16SSLCrntIPduIx;
  P2CONST(Com_tstrTxModeMixed,AUTOMATIC,TYPEDEF)pkstrTxModMxd;

  pu16SSLCrntIPduId = &(pkudtSendSignalData->u16SSLCurrentIPduId);
  pu16SSLCrntIPduIx = &(pkudtSendSignalData->u16SSLCurrentIPduIx);
#if (Com_bTO_SUPPORT == STD_ON) 
  pu32TOTimer = pkstrGET_PB_TIMEOUT_TIMER(0);
#endif

  pkstrTxIPduPtr = pkstrGET_TX_IPDU_PTR((*pu16SSLCrntIPduIx));
  pkstrTxModMxd = u8MIXTXMODE_GET_PTR(pkudtSendSignalData->u16SSLNewTxModeIndex);
  if((pkudtSendSignalData->u8SSLCurrentTxProperty == Com_u8TXPROP_TRIGGERED) ||
  ((pkudtSendSignalData->u8SSLCurrentTxProperty == Com_u8TXPROP_TRIG_CHANGE) && (pkudtSendSignalData->bSSLSignalIsChanged == TRUE)))
  {
    /* Com-CDD-TxHandler-0299(0) */
    /* Com-CDD-TxHandler-0306(0) */
    pkudtSendSignalData->bSSLSendIPdu = TRUE;

	#if u16NO_OF_IPDUS_STATUS > 0u
	SchM_Enter_Com_IPduStatus_19();
	Com_audteIPduStatus[*pu16SSLCrntIPduId] |= Com_u8WAIT_CONF;
	SchM_Exit_Com_IPduStatus_19();
	#endif
	
	
#if (Com_bNTIMES_SUPPORT == STD_ON) 
    /* Com-CDD-TxHandler-0294(0) */
    if((pkstrTxModMxd->u8NumberOfRepetitions) > 0)
    {
      /* Com-CDD-TxHandler-0296(0) */
	  #if u16NO_OF_IPDUS_STATUS > 0u
	  pkudtSendSignalData->bSSLCancelTxSupported = udtGET_PB_INIT_IPDUSTATUS(pkudtSendSignalData->u16SSLCurrentIPduId) & (Com_u8CNCL_TXSPP_FLG);
	  #endif
	  
      if((u8TXMODE_GET_REPCTR(pkstrTxModMxd->u16RepetitionsCtrIndex)) != 0)
      {
		#if (Com_bTO_SUPPORT == STD_ON) 
			u16TxIPduTOIx =	pkstrTxIPduPtr->u16TOTimerIndex;
			if(u16TxIPduTOIx != (uint16)0xFFFFu)
			{
			 SchM_Enter_Com_TimeoutTimer();
			  pu32TOTimer[u16TxIPduTOIx] = (uint32)0;
			 SchM_Exit_Com_TimeoutTimer();
			}
		#endif

#if (Com_bPDUR_CANCEL_TRANSMIT_SUPPORT == STD_ON)
        if((pkudtSendSignalData->bSSLCancelTxSupported == TRUE) &&
           (pkudtSendSignalData->bSupressCancelTx == FALSE))
        {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
          (void) PduR_ComCancelTransmit(
                                      pkudtSendSignalData->u16SSLCurrentIPduId);
/* PRQA S 3212 -- */
        }
#endif /*Com_bPDUR_CANCEL_TRANSMIT_SUPPORT*/
      }
      /* Com-CDD-TxHandler-0296(0) */
      /* Com-CDD-TxHandler-0295(0) */
      /* Com-CDD-TxHandler-0299(0) */
		u8TXMODE_RLD_REPCTR(pkstrTxModMxd);
		pku32RLD_PERIODIC_MOD_TMR(pkstrTxModMxd);
    }
    else
    {
    }
#endif
  }
  else /* u8CurrentTxProperty == Com_u8TXPROP_PENDING */
  {
    /* Com-CDD-TxHandler-0301(0) */
  }
}
/* PRQA S 4700 -- */


/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
Partitioning this function shall not pay for the negative effect of context
switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description This function handles Com_SendSignal processing in case: \n
                  No TxMode Switch Happened && \n
                  IPDU state = Active && \n
                  MDT Elapsed \n
                  Current TxMode = DIRECT \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To       Com-CDD-TxHandler-0011(0), \n
                    Com-CDD-TxHandler-0012(0),
                    Com-CDD-TxHandler-0294(0),
                    Com-CDD-TxHandler-0330(0),
                    Com-CDD-TxHandler-5706(0),
                    Com-CDD-TxHandler-0295(0),
                    Com-CDD-TxHandler-0331(0),
                    Com-CDD-TxHandler-5707(0),
                    Com-CDD-TxHandler-0296(0),
                    Com-CDD-TxHandler-0332(0),
                    Com-CDD-TxHandler-5705(0),
                    Com-CDD-TxHandler-0299(0),
                    Com-CDD-TxHandler-0334(0),
                    Com-CDD-TxHandler-0315(0),
                    Com-CDD-TxHandler-0301(0),
                    Com-CDD-TxHandler-0336(0),
                    Com-CDD-TxHandler-0317(0),
                    Com-CDD-TxHandler-0306(0),
                    Com-CDD-TxHandler-0341(0),
                    Com-CDD-TxHandler-0311(0),
                    Com-CDD-TxHandler-0307(0),
                    Com-CDD-TxHandler-0342(0),
                    Com-CDD-TxHandler-0311(0),
                    Com-CDD-0497(0),
					Com-CDD-5746(0), Com-CDD-5371(1),
					Com-CDD-5747(1), Com-CDD-5545(0)*/
static FUNC(void, COM_CODE) vidHandleSendSignalFTTD(
            P2VAR(tstrSendSignalData,
                  AUTOMATIC, COM_VAR) pkudtSendSignalData)
{
  P2VAR(PduIdType, AUTOMATIC, AUTOMATIC)pu16SSLCrntIPduId;
#if (Com_bTO_SUPPORT == STD_ON) 
  P2VAR(uint32,AUTOMATIC,AUTOMATIC)pu32TOTimer;
#endif
  P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF)pkstrTxIPduPtr;
  P2VAR(uint16, AUTOMATIC,AUTOMATIC)pu16SSLCrntIPduIx;
  VAR(uint16, AUTOMATIC) u16TxTOTimerIx;
  P2CONST(Com_tstrTxModeDirect,AUTOMATIC,TYPEDEF) pkstrTxModeDirectPtr;


  pu16SSLCrntIPduId = &(pkudtSendSignalData->u16SSLCurrentIPduId);
#if (Com_bTO_SUPPORT == STD_ON) 
  pu32TOTimer = pkstrGET_PB_TIMEOUT_TIMER(0);
#endif
  pu16SSLCrntIPduIx = &(pkudtSendSignalData->u16SSLCurrentIPduIx);
  pkstrTxIPduPtr = pkstrGET_TX_IPDU_PTR((*pu16SSLCrntIPduIx));
  pkstrTxModeDirectPtr = 
	u8DIRTXMODE_GET_PTR(pkudtSendSignalData->u16SSLNewTxModeIndex); 
  if((pkudtSendSignalData->u8SSLCurrentTxProperty == Com_u8TXPROP_TRIGGERED) ||
  ((pkudtSendSignalData->u8SSLCurrentTxProperty == Com_u8TXPROP_TRIG_CHANGE) && (pkudtSendSignalData->bSSLSignalIsChanged == TRUE)))
  {
    /* Com-CDD-TxHandler-0299(0) */
    /* Com-CDD-TxHandler-0306(0) */
    pkudtSendSignalData->bSSLSendIPdu = TRUE;

	#if u16NO_OF_IPDUS_STATUS > 0u
	SchM_Enter_Com_IPduStatus_19();
	Com_audteIPduStatus[*pu16SSLCrntIPduId] |= Com_u8WAIT_CONF;
	SchM_Exit_Com_IPduStatus_19();
	#endif
    /* Com-CDD-TxHandler-0294(0) */
#if (Com_bNTIMES_SUPPORT == STD_ON)    
   if((pkstrTxModeDirectPtr->u8NumberOfRepetitions) > 0)
    {
      /* Com-CDD-TxHandler-0296(0) */
	  #if u16NO_OF_IPDUS_STATUS > 0u
	  pkudtSendSignalData->bSSLCancelTxSupported = udtGET_PB_INIT_IPDUSTATUS(pkudtSendSignalData->u16SSLCurrentIPduId) & (Com_u8CNCL_TXSPP_FLG);
	  #endif
	  
      if((u8TXMODE_GET_REPCTR(pkstrTxModeDirectPtr->u16RepetitionsCtrIndex)) != 0)
      {
		/*! Reset IPDU Timeout */
		#if (Com_bTO_SUPPORT == STD_ON) 
			u16TxTOTimerIx = pkstrTxIPduPtr->u16TOTimerIndex;
			 if(u16TxTOTimerIx != (uint16)0xFFFFu)
			{
			 SchM_Enter_Com_TimeoutTimer();
			  pu32TOTimer[u16TxTOTimerIx] = (uint32)0;
			 SchM_Exit_Com_TimeoutTimer();
			}
		#endif

#if (Com_bPDUR_CANCEL_TRANSMIT_SUPPORT == STD_ON)
		/*! Check if this IPDU has Configured Cancel Tx Support */
        if((pkudtSendSignalData->bSSLCancelTxSupported == TRUE) &&
           (pkudtSendSignalData->bSupressCancelTx == FALSE))
        {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
          (void) PduR_ComCancelTransmit(
                                      pkudtSendSignalData->u16SSLCurrentIPduId);
/* PRQA S 3212 -- */
        }
#endif /*Com_bPDUR_CANCEL_TRANSMIT_SUPPORT*/
      }
      /* Com-CDD-TxHandler-0296(0) */
      /* Com-CDD-TxHandler-0295(0) */
      /* Com-CDD-TxHandler-0299(0) */
	  /*! Load Repetitions counter & period*/
	  u8TXMODE_RLD_REPCTR(pkstrTxModeDirectPtr);
	  pku32RLD_PERIODIC_MOD_TMR(pkstrTxModeDirectPtr);
    }
    else
    {
    }
#endif
 
  }
  else /* u8CurrentTxProperty == Com_u8TXPROP_PENDING */
  {
    /* Com-CDD-TxHandler-0301(0) */
  }
}
/* PRQA S 4700 -- */

#if (Com_bTMS_SUPPORT == STD_ON)
/******************************************************************************/
/*! \Description This function handles Com_SendSignal processing in case: \n
                  No TxMode Switch Happened && \n
                  IPDU state = Active && \n
                  MDT Elapsed \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To       Com-CDD-TxHandler-0011(0), \n
                    Com-CDD-TxHandler-0012(0),
                    Com-CDD-TxHandler-0300(0),
                    Com-CDD-TxHandler-0335(0),
                    Com-CDD-TxHandler-0316(0),
                    Com-CDD-TxHandler-0308(0),
                    Com-CDD-TxHandler-0343(0),
                    Com-CDD-TxHandler-0313(0) */
static FUNC(void, COM_CODE) vidHandleSendSignalFTT(
            P2VAR(tstrSendSignalData,
                  AUTOMATIC, COM_VAR) pkudtSendSignalData)
{
  switch (pkudtSendSignalData->u8SSLNewTxModeType)
  {
    case Com_u8TX_MODE_MIXED:
    vidHandleSendSignalFTTM(pkudtSendSignalData);
    break;
    case Com_u8TX_MODE_PERIODIC:
      /* Com-CDD-TxHandler-0300(0) */
    break;
    case Com_u8TX_MODE_DIRECT:
    vidHandleSendSignalFTTD(pkudtSendSignalData);
    break;
    case Com_u8TX_MODE_NONE:
      /* Com-CDD-TxHandler-0308(0) */
    break;

    default:

    break;
  }
}
#endif
/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
Partitioning this function shall not pay for the negative effect of context
switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description This function handles Com_SendSignal processing in case: \n
                  No TxMode Switch Happened && \n
                  IPDU state = Active && \n
                  MDT Not Elapsed \n
                  Current TxMode = MIXED \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To       Com-CDD-TxHandler-0011(0),
                    Com-CDD-TxHandler-0012(0),
                    Com-CDD-TxHandler-0294(0),
                    Com-CDD-TxHandler-0330(0),
                    Com-CDD-TxHandler-5706(0),
                    Com-CDD-TxHandler-0295(0),
                    Com-CDD-TxHandler-0331(0),
                    Com-CDD-TxHandler-5707(0),
                    Com-CDD-TxHandler-0296(0),
                    Com-CDD-TxHandler-0332(0),
                    Com-CDD-TxHandler-5705(0),
                    Com-CDD-TxHandler-0301(0),
                    Com-CDD-TxHandler-0336(0),
                    Com-CDD-TxHandler-0317(0),
                    Com-CDD-TxHandler-0302(0),
                    Com-CDD-TxHandler-0337(0),
                    Com-CDD-TxHandler-0318(0),
					Com-CDD-5746(0), Com-CDD-5370(1),
					Com-CDD-5747(1), Com-CDD-5545(0)*/
static FUNC(void, COM_CODE) vidHandleSendSignalFTFM(
            P2VAR(tstrSendSignalData,
                  AUTOMATIC, COM_VAR) pkudtSendSignalData)
{

  P2VAR(PduIdType, AUTOMATIC, AUTOMATIC)pu16SSLCrntIPduId;
#if (Com_bTO_SUPPORT == STD_ON) 
  P2VAR(uint32,AUTOMATIC,AUTOMATIC)pu32TOTimer;  
#endif

  P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF)pkstrTxIPduPtr;
  P2VAR(uint16, AUTOMATIC,AUTOMATIC)pu16SSLCrntIPduIx;
  VAR(uint16, AUTOMATIC) u16TxTOTimerIx;
  P2CONST(Com_tstrTxModeMixed,AUTOMATIC,TYPEDEF)pkstrTxModMxd;

  pu16SSLCrntIPduId = &(pkudtSendSignalData->u16SSLCurrentIPduId);
#if (Com_bTO_SUPPORT == STD_ON) 
  pu32TOTimer = pkstrGET_PB_TIMEOUT_TIMER(0);
#endif

  pu16SSLCrntIPduIx = &(pkudtSendSignalData->u16SSLCurrentIPduIx);
  pkstrTxIPduPtr =pkstrGET_TX_IPDU_PTR((*pu16SSLCrntIPduIx));
  pkstrTxModMxd = u8MIXTXMODE_GET_PTR(pkudtSendSignalData->u16SSLNewTxModeIndex);
  
  if((pkudtSendSignalData->u8SSLCurrentTxProperty == Com_u8TXPROP_TRIGGERED) || 
  ((pkudtSendSignalData->u8SSLCurrentTxProperty == Com_u8TXPROP_TRIG_CHANGE) && (pkudtSendSignalData->bSSLSignalIsChanged == TRUE)))
  {
    /* Com-CDD-TxHandler-0302(0) */
	/*#if u16NO_OF_IPDUS_STATUS > 0u
	Com_audteIPduStatus[*pu16SSLCrntIPduId] |= (Com_udtIPduStatus)Com_u8D_MDT_MASK; 
	#endif*/
	
	pkudtSendSignalData->bIPduSignalMDTMask = TRUE;
	
    /* Com-CDD-TxHandler-0294(0) */
    #if (Com_bNTIMES_SUPPORT == STD_ON) 
	if((pkstrTxModMxd->u8NumberOfRepetitions) > 0)
    {
	  #if u16NO_OF_IPDUS_STATUS > 0u
	 SchM_Enter_Com_IPduStatus_19();
	  Com_audteIPduStatus[*pu16SSLCrntIPduId] |= Com_u8WAIT_CONF;
	 SchM_Exit_Com_IPduStatus_19();
	  #endif
	  
      /* Com-CDD-TxHandler-0296(0) */
	  #if u16NO_OF_IPDUS_STATUS > 0u
	  pkudtSendSignalData->bSSLCancelTxSupported = udtGET_PB_INIT_IPDUSTATUS(pkudtSendSignalData->u16SSLCurrentIPduId) & (Com_u8CNCL_TXSPP_FLG);
	  #endif
	  
      if(u8TXMODE_GET_REPCTR(pkstrTxModMxd->u16RepetitionsCtrIndex) != 0)
      {
		#if (Com_bTO_SUPPORT == STD_ON) 
		/*! Reset IPDU Timeout*/
		u16TxTOTimerIx = pkstrTxIPduPtr->u16TOTimerIndex;
		if(u16TxTOTimerIx != (uint16)0xFFFFu)
        {
         SchM_Enter_Com_TimeoutTimer();
          pu32TOTimer[u16TxTOTimerIx] = (uint32)0;
         SchM_Exit_Com_TimeoutTimer();
        }
		#endif
		
#if (Com_bPDUR_CANCEL_TRANSMIT_SUPPORT == STD_ON)
        if((pkudtSendSignalData->bSSLCancelTxSupported == TRUE) &&
           (pkudtSendSignalData->bSupressCancelTx == FALSE))
        {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
          (void) PduR_ComCancelTransmit(
                                      pkudtSendSignalData->u16SSLCurrentIPduId);
/* PRQA S 3212 -- */
        }
#endif /*Com_bPDUR_CANCEL_TRANSMIT_SUPPORT*/
      }
      /* Com-CDD-TxHandler-0296(0) */
      /* Com-CDD-TxHandler-0295(0) */
	  /*! Reload Repitition period and Counter*/
			u8TXMODE_RLD_REPCTR(pkstrTxModMxd);
			pku32RLD_PERIODIC_MOD_TMR(pkstrTxModMxd);
    }
    else
	#endif
    {
    }
  }
  else /* u8CurrentTxProperty == Com_u8TXPROP_PENDING */
  {
    /* Com-CDD-TxHandler-0301(0) */
  }
}
/* PRQA S 4700 -- */

/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
Partitioning this function shall not pay for the negative effect of context
switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description This function handles Com_SendSignal processing in case: \n
                  No TxMode Switch Happened && \n
                  IPDU state = Active && \n
                  MDT Not Elapsed \n
                  Current TxMode = DIRECT \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To       Com-CDD-TxHandler-0011(0), \n
                    Com-CDD-TxHandler-0012(0),
                    Com-CDD-TxHandler-0295(0),
                    Com-CDD-TxHandler-0331(0),
                    Com-CDD-TxHandler-5707(0),
                    Com-CDD-TxHandler-0296(0),
                    Com-CDD-TxHandler-0332(0),
                    Com-CDD-TxHandler-5705(0),
                    Com-CDD-TxHandler-0301(0),
                    Com-CDD-TxHandler-0336(0),
                    Com-CDD-TxHandler-0317(0),
                    Com-CDD-TxHandler-0302(0),
                    Com-CDD-TxHandler-0337(0),
                    Com-CDD-TxHandler-0317(0),
					Com-CDD-5746(0), Com-CDD-5370(1),
					Com-CDD-5747(1), Com-CDD-5545(0)*/
static FUNC(void, COM_CODE) vidHandleSendSignalFTFD(
            P2VAR(tstrSendSignalData,
                  AUTOMATIC, COM_VAR) pkudtSendSignalData)
{

  P2VAR(PduIdType, AUTOMATIC, AUTOMATIC)pu16SSLCrntIPduId;
#if (Com_bTO_SUPPORT == STD_ON) 
  P2VAR(uint32,AUTOMATIC,AUTOMATIC)pu32TOTimer;  
#endif

  P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF)pkstrTxIPduPtr;
  P2VAR(uint16, AUTOMATIC,AUTOMATIC)pu16SSLCrntIPduIx;
  VAR(uint16, AUTOMATIC)u16TxTOTimerIx;
  P2CONST(Com_tstrTxModeDirect,AUTOMATIC,TYPEDEF) pkstrTxModeDirectPtr;


  pu16SSLCrntIPduId = &(pkudtSendSignalData->u16SSLCurrentIPduId);
#if (Com_bTO_SUPPORT == STD_ON) 
  pu32TOTimer = pkstrGET_PB_TIMEOUT_TIMER(0);
#endif

  pu16SSLCrntIPduIx = &(pkudtSendSignalData->u16SSLCurrentIPduIx);
  pkstrTxIPduPtr = pkstrGET_TX_IPDU_PTR((*pu16SSLCrntIPduIx));
  pkstrTxModeDirectPtr = 
	u8DIRTXMODE_GET_PTR(pkudtSendSignalData->u16SSLNewTxModeIndex); 
	
 

  if((pkudtSendSignalData->u8SSLCurrentTxProperty == Com_u8TXPROP_TRIGGERED) ||
  ((pkudtSendSignalData->u8SSLCurrentTxProperty == Com_u8TXPROP_TRIG_CHANGE) && (pkudtSendSignalData->bSSLSignalIsChanged == TRUE)))
  {
    /* Com-CDD-TxHandler-0302(0) */
	/*#if u16NO_OF_IPDUS_STATUS > 0u
	Com_audteIPduStatus[*pu16SSLCrntIPduId] |= (Com_udtIPduStatus)Com_u8D_MDT_MASK;
	#endif*/
	
	pkudtSendSignalData->bIPduSignalMDTMask = TRUE;
	
#if (Com_bNTIMES_SUPPORT == STD_ON)  
    if((pkstrTxModeDirectPtr->u8NumberOfRepetitions) > 0)
    {
	  #if u16NO_OF_IPDUS_STATUS > 0u
	 SchM_Enter_Com_IPduStatus_19();
	  Com_audteIPduStatus[*pu16SSLCrntIPduId] |= Com_u8WAIT_CONF;
	 SchM_Exit_Com_IPduStatus_19();
	  #endif
	  
      /* Com-CDD-TxHandler-0296(0) */
	   pkudtSendSignalData->bSSLCancelTxSupported = udtGET_PB_INIT_IPDUSTATUS(pkudtSendSignalData->u16SSLCurrentIPduId) & (Com_u8CNCL_TXSPP_FLG);
      if(u8TXMODE_GET_REPCTR(pkstrTxModeDirectPtr->u16RepetitionsCtrIndex) != 0)
      {
		#if (Com_bTO_SUPPORT == STD_ON) 
		u16TxTOTimerIx = pkstrTxIPduPtr->u16TOTimerIndex;
		if(u16TxTOTimerIx != (uint16)0xFFFFu)
        {
         SchM_Enter_Com_TimeoutTimer();
          pu32TOTimer[u16TxTOTimerIx] = (uint32)0;
         SchM_Exit_Com_TimeoutTimer();
        }
		#endif

#if (Com_bPDUR_CANCEL_TRANSMIT_SUPPORT == STD_ON)		
        if((pkudtSendSignalData->bSSLCancelTxSupported == TRUE) &&
           (pkudtSendSignalData->bSupressCancelTx == FALSE))
        {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
          (void) PduR_ComCancelTransmit(
                                      pkudtSendSignalData->u16SSLCurrentIPduId);
/* PRQA S 3212 -- */
        }
#endif /*Com_bPDUR_CANCEL_TRANSMIT_SUPPORT*/
      }
      /* Com-CDD-TxHandler-0296(0) */
      /* Com-CDD-TxHandler-0295(0) */
	  /*! Reload Repitition period and Counter*/
			u8TXMODE_RLD_REPCTR(pkstrTxModeDirectPtr);
			pku32RLD_PERIODIC_MOD_TMR(pkstrTxModeDirectPtr);
    }
	else
#endif
	{
	}

  }
  else /* u8CurrentTxProperty == Com_u8TXPROP_PENDING */
  {
    /* Com-CDD-TxHandler-0301(0) */
  }
}
/* PRQA S 4700 -- */
#if (Com_bTMS_SUPPORT == STD_ON)
/******************************************************************************/
/*! \Description This function handles Com_SendSignal processing in case: \n
                  No TxMode Switch Happened && \n
                  IPDU state = Active && \n
                  MDT Not Elapsed \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To       Com-CDD-TxHandler-0011(0), \n
                    Com-CDD-TxHandler-0012(0),
                    Com-CDD-TxHandler-0300(0),
                    Com-CDD-TxHandler-0335(0),
                    Com-CDD-TxHandler-0316(0),
                    Com-CDD-TxHandler-0308(0),
                    Com-CDD-TxHandler-0343(0),
                    Com-CDD-TxHandler-0313(0) */					
static FUNC(void, COM_CODE) vidHandleSendSignalFTF(
            P2VAR(tstrSendSignalData,
                  AUTOMATIC, COM_VAR) pkudtSendSignalData)
{
  switch (pkudtSendSignalData->u8SSLNewTxModeType)
  {
    case Com_u8TX_MODE_MIXED:
    vidHandleSendSignalFTFM(pkudtSendSignalData);
    break;
    case Com_u8TX_MODE_PERIODIC:
      /* Com-CDD-TxHandler-0300(0) */
    break;
	case Com_u8TX_MODE_DIRECT:
    vidHandleSendSignalFTFD(pkudtSendSignalData);
    break;
    case Com_u8TX_MODE_NONE:
      /* Com-CDD-TxHandler-0308(0) */
    break;

    default:

    break;
  }
}
#endif

#if (Com_bTMS_SUPPORT == STD_ON)
/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
Partitioning this function shall not pay for the negative effect of context
switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description This function handles Com_SendSignal processing. \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To  */
static FUNC(void, COM_CODE) vidHandleSendSignal(
            P2VAR(tstrSendSignalData,
                  AUTOMATIC, COM_VAR) pkudtSendSignalData)
{
  /* Com-CDD-TxHandler-0011(0) */
  /* Com-CDD-TxHandler-0014(0) */
  if((pkudtSendSignalData->bSSLTMSwitchHappened == TRUE) &&
     (pkudtSendSignalData->bSSLIPduState        == TRUE) &&
     (pkudtSendSignalData->bSSLElapsedMDT       == TRUE))
  {
    vidHandleSendSignalTTT(pkudtSendSignalData);
  }
  /* Com-CDD-TxHandler-0011(0) */
  /* Com-CDD-TxHandler-0014(0) */
  else if((pkudtSendSignalData->bSSLTMSwitchHappened == TRUE) &&
          (pkudtSendSignalData->bSSLIPduState        == TRUE) &&
          (pkudtSendSignalData->bSSLElapsedMDT       == FALSE))
  {
    vidHandleSendSignalTTF(pkudtSendSignalData);
  }

  else if((pkudtSendSignalData->bSSLTMSwitchHappened == TRUE) &&
          (pkudtSendSignalData->bSSLIPduState        == FALSE) &&
          (pkudtSendSignalData->bSSLElapsedMDT       == TRUE))
  {
    vidHandleSendSignalTFT(pkudtSendSignalData);
  }

  else if((pkudtSendSignalData->bSSLTMSwitchHappened == TRUE) &&
          (pkudtSendSignalData->bSSLIPduState        == FALSE) &&
          (pkudtSendSignalData->bSSLElapsedMDT       == FALSE))
  {
	/*! the same functionality of vidHandleSendSignalTFT as IPDU is not active*/
	vidHandleSendSignalTFT(pkudtSendSignalData);
  }
  /* Com-CDD-TxHandler-0011(0) */
  /* Com-CDD-TxHandler-0014(0) */
  else if((pkudtSendSignalData->bSSLTMSwitchHappened == FALSE) &&
          (pkudtSendSignalData->bSSLIPduState        == TRUE) &&
          (pkudtSendSignalData->bSSLElapsedMDT       == TRUE))
  {
    vidHandleSendSignalFTT(pkudtSendSignalData);
  }
  /* Com-CDD-TxHandler-0011(0) */
  /* Com-CDD-TxHandler-0014(0) */
  else if((pkudtSendSignalData->bSSLTMSwitchHappened == FALSE) &&
          (pkudtSendSignalData->bSSLIPduState        == TRUE) &&
          (pkudtSendSignalData->bSSLElapsedMDT       == FALSE))
  {
    vidHandleSendSignalFTF(pkudtSendSignalData);
  }
  else
  {

  }
}
/* PRQA S 4700 -- */


/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
Partitioning this function shall not pay for the negative effect of context
switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description This function handles Com_SendSignal Preparation - TMS part. \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \param[in]   SignalId  signal Handle ID passed to Com_SendSignal
  \param[in]   SignalDataPtr  Pointer to signal data passed to Com_SendSignal
  \return      void
*******************************************************************************/
/*! \Trace_To   Com-CDD-TxHandler-0020(0),
                Com-CDD-TxHandler-0286(0),
                Com-CDD-TxHandler-0024(0),
                Com-CDD-TxHandler-5729(0),
                Com-CDD-TxHandler-5726(0) */
static FUNC(void, COM_CODE) vidPrepSendSignalTMS(
            P2VAR(tstrSendSignalData,
                  AUTOMATIC, COM_VAR) pkudtSendSignalData,
            VAR(Com_SignalIdType, AUTOMATIC)  SignalId)
{

  P2VAR(uint16, AUTOMATIC,AUTOMATIC)pu16SSLCrntSigId;
 /*PRQA S 8018 , 8318 ,8518 ++ */
  Com_tpkvidMaxCalibDataConstPtr pkvidCurrSigObjPtr;
 /*PRQA S 8018 , 8318 ,8518 -- */
  pu16SSLCrntSigId = &(pkudtSendSignalData->u16SSLCurrentSigId);


  /*! handle TM switch if happened */
  if( pkudtSendSignalData->bSSLFilterSupport == TRUE)
  {

    pkvidCurrSigObjPtr = Com_pkvidGetSigObjPtr(SignalId);

	/*! Apply filter on signal and save result*/
    pkudtSendSignalData->bSSLNewFilterRslt =
                Com_bSignalApplyFilter(pkudtSendSignalData->u16SSLCurrentSigIx, pkvidCurrSigObjPtr,
				pkudtSendSignalData->u8SSLSigStructType);
	
	#if Com_u16NO_OF_SIGNAL_STATUS > 0u
	SchM_Enter_Com_SignalStatus_19();
	/*! Check if New filter result differ Old Value shall New value evalute TMS*/
	pkudtSendSignalData->bSSLOldFilterRslt = (boolean)((Com_audteSignalStatus[*pu16SSLCrntSigId] & Com_u8LASTFILTER_RES) != (boolean)FALSE);
	if(pkudtSendSignalData->bSSLNewFilterRslt != pkudtSendSignalData->bSSLOldFilterRslt)
	{
	    /*! save Signal Filter result in the global signal Status to be used during TMS evalution*/
		Com_audteSignalStatus[*pu16SSLCrntSigId] ^= (uint8)Com_u8NEW_FILTER_RESULT;
	}
	SchM_Exit_Com_SignalStatus_19();
	#endif
	

    /* Com-CDD-TxHandler-5729(0) */
#if Com_u8FILTERING_DIR  == Com_u8DIRECTION_TX
    if(pkudtSendSignalData->bSSLNewFilterRslt == FALSE)
    {
      pkudtSendSignalData->u8SSLCurrentTxProperty = Com_u8TXPROP_PENDING;
    }
    else
    {
	
    }
#endif
	}
}
/* PRQA S 4700 -- */
/******************************************************************************/
/*! \Description This function handles Com_SendSignal Preparation. \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignal internal \n
               variables structure
  \param[in]   SignalId  signal Handle ID passed to Com_SendSignal
  \param[in]   SignalDataPtr  Pointer to signal data passed to Com_SendSignal
  \return      void
*******************************************************************************/
/*! \Trace_To   Com-CDD-TxHandler-0303(0),
                Com-CDD-TxHandler-0338(0),
                Com-CDD-TxHandler-0319(0),
                Com-CDD-TxHandler-0502(0),
                Com-CDD-TxHandler-0505(0),
                Com-CDD-TxHandler-5725(0) */
static FUNC(void, COM_CODE) vidPrepSendSignal(
            P2VAR(tstrSendSignalData,
                  AUTOMATIC, COM_VAR) pkudtSendSignalData,
            VAR(Com_SignalIdType, AUTOMATIC)  SignalId)
{
  P2CONST(Com_tstrSignalLT,AUTOMATIC,TYPEDEF)pkstreSignalLT;
  P2CONST(Com_tstrGWDstDesc,AUTOMATIC,TYPEDEF)pkstrGWDstDescPtr;
  VAR(uint8,AUTOMATIC) 				u8CurrentTxProperty;

  pkstreSignalLT = &Com_akstreSignalLT[pkudtSendSignalData->
                                            u16SSLCurrentSigIx];

  /*! Get the Signal Properites Filtering, Tx property*/
  if(pkudtSendSignalData->u8SSLSigStructType == (uint8) Com_u8SIG_STRUCT_SIG)
  {
#if Com_u16NO_OF_SIGNAL > 0u
	pkudtSendSignalData->bSSLFilterSupport = (boolean)(pkstreSignalLT->u16FilterIndex != (uint16)0xFFFFu);
    pkudtSendSignalData->u16SSLCurrentSigId =
          pkstreSignalLT->u16SignalId;
	u8CurrentTxProperty = u8SIG_GET_TX_PROP(pkudtSendSignalData->u16SSLCurrentSigIx);
	if(u8CurrentTxProperty == Com_u8TXPROP_TRIGGERED)
	{
		pkudtSendSignalData->u8SSLCurrentTxProperty = Com_u8TXPROP_TRIGGERED;
	}
	else if((u8CurrentTxProperty == Com_u8TXPROP_TRIG_CHANGE) && (pkudtSendSignalData->u8SSLCurrentTxProperty != Com_u8TXPROP_TRIGGERED))
	{
		pkudtSendSignalData->u8SSLCurrentTxProperty = Com_u8TXPROP_TRIG_CHANGE;
		pkudtSendSignalData->bSSLSignalIsChanged = TRUE;
	}
	else
	{
	}
	
#endif
  }
#if (Com_bGW_DESC_SUPPORT == STD_ON)
  else /* pkudtSendSignalData->u8SSLSigStructType == Com_u8SIG_STRUCT_DSTDESC */
  {
    /*! Get the Signal description Properites Filtering, Tx property*/
								   
	pkudtSendSignalData->bSSLFilterSupport  =  (boolean)((pkstreSignalLT->u16FilterIndex) != (uint16)0xFFFFu);
    
	pkstrGWDstDescPtr = pkstrGET_PB_DST_DESC_PTR(pkudtSendSignalData->u16SSLCurrentSigIx);
	pkudtSendSignalData->u16SSLCurrentSigId = pkstrGWDstDescPtr->u16SignalId;
	
	u8CurrentTxProperty = (uint8)((pkstrGWDstDescPtr->udteSignalFlags & Com_u8SIGNAL_TXPROPERTY) >> 2);
    if(u8CurrentTxProperty == Com_u8TXPROP_TRIGGERED)
	{
		pkudtSendSignalData->u8SSLCurrentTxProperty = Com_u8TXPROP_TRIGGERED;
	}
	else if((u8CurrentTxProperty == Com_u8TXPROP_TRIG_CHANGE) && (pkudtSendSignalData->u8SSLCurrentTxProperty != Com_u8TXPROP_TRIGGERED))
	{
		pkudtSendSignalData->u8SSLCurrentTxProperty = Com_u8TXPROP_TRIGGERED;
		pkudtSendSignalData->bSSLSignalIsChanged = TRUE;
	}
	else
	{
	}
  }
#endif
  
  vidPrepSendSignalTMS(pkudtSendSignalData, SignalId);

} /* vidPrepSendSignal */
#endif

/******************************************************************************/
/*! \Description This function handles Com_SendSignal part of update bit \n
                 and trigger on change
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignalGroup internal \n
               variables structure
  \param[in]   SignalGroupId  signal Group Handle ID passed to Com_SendSignal
  \return      void
*******************************************************************************/
/*! \Trace_To    */
static FUNC(void, COM_CODE) vidHandleUbitTrigOnCh(
            VAR(Com_SignalIdType, AUTOMATIC)  SignalId,
            P2CONST(void,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) SignalDataPtr,
			P2VAR(tstrSendSignalData,AUTOMATIC, COM_VAR) pkudtSendSignalData)
{

  P2CONST(Com_tstrSignalPB,AUTOMATIC,TYPEDEF)	pkstrLocSigPB;
  P2CONST(Com_tstrSignalLT,AUTOMATIC,TYPEDEF)	pkstreSignalLT;
  P2CONST(Com_tstrGWDstDesc,AUTOMATIC,TYPEDEF)	pkstrGWDstDescPtr;
  
 
  
  if(pkudtSendSignalData->u8SSLSigStructType == (uint8) Com_u8SIG_STRUCT_SIG)
  {
#if Com_u16NO_OF_SIGNAL > 0u
  pkstrLocSigPB = pkstrGET_PB_SIGNAL_PTR(pkudtSendSignalData->u16SSLCurrentSigIx);
  pkstreSignalLT = &Com_akstreSignalLT[pkudtSendSignalData->u16SSLCurrentSigIx];
#if (Com_bUBIT_SUPPORT == STD_ON) 
	pkudtSendSignalData->bSSLUpdateBitSupport  =
              (boolean)((pkstrLocSigPB->u16UpdateBitPosition) != (uint16)0xFFFFu);
									
#endif

#if Com_u8FILTERING_DIR  == Com_u8DIRECTION_TX
	pkudtSendSignalData->bSSLFilterSupport = (boolean)((pkstreSignalLT->u16FilterIndex) != (uint16)0xFFFFu);
#endif
    pkudtSendSignalData->u16SSLCurrentSigId = pkstreSignalLT->u16SignalId;
    pkudtSendSignalData->u8SSLCurrentTxProperty = (uint8)((pkstrLocSigPB->udteSignalFlags & Com_u8SIGNAL_TXPROPERTY) >> 2);

#if (Com_bTMS_SUPPORT == STD_ON)
    if(pkudtSendSignalData->u8SSLCurrentTxProperty == Com_u8TXPROP_TRIG_CHANGE)
    {
      pkudtSendSignalData->bSSLSignalIsChanged =
                        Com_bSignalIsChanged(
                                          SignalId,
                                          SignalDataPtr,
                                          pkudtSendSignalData->u16SSLDynLength);
    }
    else
    {
      pkudtSendSignalData->bSSLSignalIsChanged = TRUE;
    }
#else
	if(pkudtSendSignalData->u8SSLCurrentTxProperty == Com_u8TXPROP_TRIGGERED )
	{
		pkudtSendSignalData->bSSLSignalIsChanged = TRUE;
	}
	else if(pkudtSendSignalData->u8SSLCurrentTxProperty == Com_u8TXPROP_TRIG_CHANGE)
    {
       pkudtSendSignalData->bSSLSignalIsChanged =
                         Com_bSignalIsChanged(
                                          SignalId,
                                          SignalDataPtr,
                                          pkudtSendSignalData->u16SSLDynLength);
    }
    else
    {
       pkudtSendSignalData->bSSLSignalIsChanged = FALSE;
    }
#endif

#endif
  }
 
#if (Com_bGW_DESC_SUPPORT == STD_ON) 
  else /* pkudtSendSignalData->u8SSLSigStructType == Com_u8SIG_STRUCT_DSTDESC */
  {
  
  pkstrGWDstDescPtr = pkstrGET_PB_DST_DESC_PTR(pkudtSendSignalData->u16SSLCurrentSigIx);
 
 #if (Com_bUBIT_SUPPORT == STD_ON) 
	  pkudtSendSignalData->bSSLUpdateBitSupport  =  (boolean)((pkstrGWDstDescPtr->
							u16UpdateBitPosition) != (uint16)0xFFFFu);
#endif

#if Com_u8FILTERING_DIR  == Com_u8DIRECTION_TX
	pkudtSendSignalData->bSSLFilterSupport  =  (boolean)((pkstrGWDstDescPtr->u16FilterIndex) != (uint16)0xFFFFu);
#endif
    pkudtSendSignalData->u16SSLCurrentSigId = pkstrGWDstDescPtr->u16SignalId;
    pkudtSendSignalData->u8SSLCurrentTxProperty = (uint8)((pkstrGWDstDescPtr->udteSignalFlags & Com_u8SIGNAL_TXPROPERTY) >> 2);

#if (Com_bTMS_SUPPORT == STD_ON)
    if(pkudtSendSignalData->u8SSLCurrentTxProperty == Com_u8TXPROP_TRIG_CHANGE)
    {
      pkudtSendSignalData->bSSLSignalIsChanged =
                        bDstDescIsChanged(
                                          SignalId,
                                          SignalDataPtr);
    }
    else
    {
      pkudtSendSignalData->bSSLSignalIsChanged = TRUE;
    }
#else
	
	if(pkudtSendSignalData->u8SSLCurrentTxProperty == Com_u8TXPROP_TRIGGERED)
	{
		pkudtSendSignalData->bSSLSignalIsChanged = TRUE;
	}
	else if(pkudtSendSignalData->u8SSLCurrentTxProperty == Com_u8TXPROP_TRIG_CHANGE)
    {
       pkudtSendSignalData->bSSLSignalIsChanged =
                         Com_bSignalIsChanged(
                                          SignalId,
                                          SignalDataPtr,
                                          pkudtSendSignalData->u16SSLDynLength);
    }
    else
    {
       pkudtSendSignalData->bSSLSignalIsChanged = FALSE;
    }
#endif
  }
#endif

}



/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
Partitioning this function shall not pay for the negative effect of context
switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description The service Com_SendSignal updates the signal object \n
                 identified by SignalId with the signal referenced by \n
                 the SignalDataPtr parameter \n
    \param[in]  SignalId Id of signal to be sent.
                SignalDataPtr Reference to the signal data to be transmitted
*******************************************************************************/
/*! \Trace_To Com-CDD-TxHandler-0114(0),
              Com-CDD-TxHandler-0405(0),
              Com-CDD-TxHandler-0406(0),
              Com-CDD-TxHandler-0407(0),
              Com-CDD-TxHandler-0408(0),
              Com-CDD-TxHandler-0284(0),
              Com-CDD-TxHandler-0285(0),
              Com-CDD-TxHandler-0298(0),
              Com-CDD-TxHandler-0333(0),
              Com-CDD-TxHandler-0061(0),
              Com-CDD-TxHandler-0305(0),
              Com-CDD-TxHandler-5729(0),
              Com-CDD-TxHandler-5710(0),
              Com-CDD-TxHandler-5736(0),
              Com-CDD-0497(0),
			   Com-CDD-TxHandler-0262(0),
		Com-CDD-0437(0) , Com-CDD-0438(0) ,
		Com-CDD-0439(0) , Com-CDD-0441(0) ,
		Com-CDD-0440(0) , Com-CDD-0442(0) ,
		Com-CDD-0443(0) , Com-CDD-TxHandler-5721(0) , 
		Com-CDD-5746(0), Com-CDD-5744(1),
		Com-CDD-5216(1), Com-CDD-0443(0) ,
		Com-CDD-5748(1), Com-CDD-5546(1), 		
		Com-CDD-TxHandler-0269(0) */
FUNC(uint8, COM_CODE) Com_SendSignal(
                          VAR(Com_SignalIdType, AUTOMATIC)  SignalId,
                          P2CONST(void,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)
                                                            SignalDataPtr )
{

  /*! Local variables */
  VAR(boolean, AUTOMATIC)               bIPduWaitForConf;
  VAR(boolean, AUTOMATIC)               bIPduIsActive;
  P2VAR(PduIdType, AUTOMATIC,AUTOMATIC) pu16SSLCrntIPduId;
  VAR(uint8, AUTOMATIC)                 u8CurrentSigType;

  VAR(tstrSendSignalData, AUTOMATIC) 	strSendSignalData;
  P2CONST(Com_tstrSignalPB,AUTOMATIC,TYPEDEF)	pkstrLocSigPB;
  P2CONST(Com_tstrGWDstDesc,AUTOMATIC,TYPEDEF)	pkstrGWDstDescPtr;
#if (Com_bUBIT_SUPPORT== STD_ON)    
  VAR(uint16, AUTOMATIC) u16UpdBitPos;
#endif
#if (Com_bTX_INACTIVE_ERROR == STD_ON) 
 Com_tpfvidSigTxErrorNotif pudtSigTxErrorNotif; 
#endif
  strSendSignalData.u8SSLReturnValue     = E_OK;

  strSendSignalData.bSSLSendIPdu = FALSE;
  /*! clear u16SSLDynLength because it is used in case of dynamic signals \n
   only */
  strSendSignalData.u16SSLDynLength = (uint16)0;
#if (Com_bUBIT_SUPPORT== STD_ON)   
  u16UpdBitPos = (uint16)0xFFFFu;
#endif
#if (COM_DEV_ERROR_DETECT == STD_ON)
  /*! DET check and reporting */
  if (Com_enueStatus == COM_UNINIT)
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    /*! DET report if module was not initialized */
    /* Com-CDD-TxHandler-0405(0) */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_SendSignal , COM_E_UNINIT);
/* PRQA S 3212 -- */
    strSendSignalData.u8SSLReturnValue = COM_SERVICE_NOT_AVAILABLE;
  }
  else
  {
    if (SignalId > Com_u16SIGNALIDMAX)
    {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
      /*! DET report if SignalId is out of range */
      (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                      COMServiceId_SendSignal , COM_E_PARAM);
/* PRQA S 3212 -- */
      strSendSignalData.u8SSLReturnValue = COM_SERVICE_NOT_AVAILABLE;
    }
    else
    {
#endif /*COM_DEV_ERROR_DETECT*/

     
      strSendSignalData.u8SSLSigStructType =
              u8SIG_GET_STRUCT_TYPE(SignalId);
      strSendSignalData.u16SSLCurrentSigIx =
                        u16SIG_GET_LKUP_IX(SignalId);
	  if(strSendSignalData.u8SSLSigStructType == (uint8) Com_u8SIG_STRUCT_SIG)
      {
#if (Com_u16NO_OF_SIGNAL > 0u)
		pkstrLocSigPB = pkstrGET_PB_SIGNAL_PTR(strSendSignalData.u16SSLCurrentSigIx);
        strSendSignalData.u8SSLCurrentSigDir = (boolean)((pkstrLocSigPB->udteSignalFlags & Com_u8SIGNAL_DIRECTION) != FALSE);
        u8CurrentSigType = pkstrLocSigPB->u8SignalType;
		strSendSignalData.u16SSLCurrentIPduId  = pkstrLocSigPB->u16IPduIndex;
#if (Com_bUBIT_SUPPORT== STD_ON)   		
		u16UpdBitPos = pkstrLocSigPB->u16UpdateBitPosition;
#endif

#else
        u8CurrentSigType = Com_u8SIGNAL_TYPE_UINT8;
#endif
      }
      else if(strSendSignalData.u8SSLSigStructType ==
                                              (uint8) Com_u8SIG_STRUCT_DSTDESC)
      {
#if (Com_bGW_DESC_SUPPORT == STD_ON)
	    pkstrGWDstDescPtr = pkstrGET_PB_DST_DESC_PTR(strSendSignalData.u16SSLCurrentSigIx);
        strSendSignalData.u8SSLCurrentSigDir = (boolean)((pkstrGWDstDescPtr->udteSignalFlags & Com_u8SIGNAL_DIRECTION) != FALSE);
        u8CurrentSigType = pkstrGWDstDescPtr->u8SignalType;
		strSendSignalData.u16SSLCurrentIPduId  = pkstrGWDstDescPtr->u16IPduIndex;
	#if (Com_bUBIT_SUPPORT== STD_ON)   
			u16UpdBitPos = pkstrGWDstDescPtr->u16UpdateBitPosition;
	#endif      
#else
	strSendSignalData.u8SSLReturnValue = COM_SERVICE_NOT_AVAILABLE;
#endif
	  }
      else
      {
        u8CurrentSigType = Com_u8SIGNAL_TYPE_UINT8;
      }
      /* Com-CDD-TxHandler-0406(0) */
      if (
          (
           (strSendSignalData.u8SSLSigStructType !=
                                              (uint8) Com_u8SIG_STRUCT_SIG) &&
           (strSendSignalData.u8SSLSigStructType !=
                                              (uint8) Com_u8SIG_STRUCT_DSTDESC)
           ) ||
           (strSendSignalData.u8SSLCurrentSigDir != Com_u8SIG_DIR_SEND)||
           (u8CurrentSigType == Com_u8SIGNAL_TYPE_UINT8DYN))
      {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
        /*! DET report if direction is not send or if signal is dynamic or \n
        called for group signals */
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                        COMServiceId_SendSignal , COM_E_PARAM);
/* PRQA S 3212 -- */
        strSendSignalData.u8SSLReturnValue = COM_SERVICE_NOT_AVAILABLE;
      }
      /* Com-CDD-TxHandler-0407(0) */
      else if ( SignalDataPtr == NULL_PTR )
      {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
        /*! DET report SignalDataPtr == NULL_PTR */
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                        COMServiceId_SendSignal , COM_E_PARAM_POINTER);
/* PRQA S 3212 -- */
        strSendSignalData.u8SSLReturnValue = COM_SERVICE_NOT_AVAILABLE;
      }
      else
      {

      }

  /* If no error */
#if ((COM_DEV_ERROR_DETECT == STD_ON) || Com_bGW_DESC_SUPPORT == STD_OFF)
  if(strSendSignalData.u8SSLReturnValue == E_OK)
#endif /*COM_DEV_ERROR_DETECT*/
  {


  pu16SSLCrntIPduId = &(strSendSignalData.u16SSLCurrentIPduId);
  strSendSignalData.u16SSLCurrentIPduIx = u16IPDU_GET_IX((*pu16SSLCrntIPduId));
	
	#if u16NO_OF_IPDUS_STATUS > 0u
	SchM_Enter_Com_IPduStatus_0A();
	bIPduWaitForConf = Com_audteIPduStatus[*pu16SSLCrntIPduId] & Com_u8WAIT_CONF;
	SchM_Exit_Com_IPduStatus_0A();
	#endif
	
    /*! If IPdu buffer is not locked, handle request normally */
    /* Com-CDD-TxHandler-5710(0) */
    if(!((u8TXIPDU_GET_TYPE(strSendSignalData.u16SSLCurrentIPduIx) ==
                                                      Com_u8IPDU_TYPE_TP) &&
       (bIPduWaitForConf != FALSE)))
    {
      strSendSignalData.u8SSLNewTxModeType   = (uint8)0;
      strSendSignalData.u16SSLNewTxModeIndex = (uint16)0;
      strSendSignalData.bSSLSignalIsChanged  = FALSE;

      vidHandleUbitTrigOnCh(SignalId, SignalDataPtr,&strSendSignalData);
      /*! if bSSLSignalIsChanged == TRUE, this means whether this signal:
            - is changed with TxProperty Tigger on change,
            - has TxProperty Tigger or
            - has TxProperty pending.
          in all 3 cases this signal might change TMS, and extra processing is
          needed in Com_MainFunctionTx.*/

      if(strSendSignalData.bSSLSignalIsChanged == TRUE)
      {
/* !Deviation: [3201, 3325]  This statement is unreachable. This is reachable
throught assignment of bSSLSignalIsChanged in vidHandleUbitTrigOnCh */
/* PRQA S 3201 ++ */
/* PRQA S 3325 ++ */
/* !Deviation: [3361]  This 'do - while' control expression has a constant,
'false' value. This is intended. (multi-line function like MACRO) */
/* PRQA S 3361 ++ */
#if (Com_bTMS_SUPPORT == STD_ON)
		#if Com_u16NO_OF_SIGNAL_STATUS > 0u
		 SchM_Enter_Com_SignalStatus_0A();
		  Com_audteSignalStatus[SignalId] |= Com_u8SS_TMS_REQ;
		 SchM_Exit_Com_SignalStatus_0A(); 
		#endif
		
#endif

	/*Add for optimization, in case we need to close features that will enable and disable sending the IPDU contains
	this signal we need flag to check sending that ipdu or not also we will use this flag in Com_MainFunctionTx to 
	avoid processing of all IPDU */
	#if u16NO_OF_IPDUS_STATUS > 0u
	SchM_Enter_Com_IPduStatus_0A();
	Com_audteIPduStatus[*pu16SSLCrntIPduId] |= Com_u8SENDSIGNAL_RQ;
	SchM_Exit_Com_IPduStatus_0A();    
	#endif	
/* PRQA S 3361 -- */
/* PRQA S 3325 -- */
/* PRQA S 3201 -- */
      }
      else
      {

      }

      /* Com-CDD-TxHandler-0061(0) */
      /* Com-CDD-TxHandler-0305(0) */
      /* Com-CDD-TxHandler-0298(0) */
      /* Com-CDD-TxHandler-5729(0) */
#if Com_u8FILTERING_DIR  == Com_u8DIRECTION_TX
      /*! handle Transmission Filtering */
      if( strSendSignalData.bSSLFilterSupport == TRUE)
      {
        strSendSignalData.bSSLNewFilterRslt =
                  Com_bSignalApplyFilter(strSendSignalData.u16SSLCurrentSigIx, SignalDataPtr,
				  strSendSignalData.u8SSLSigStructType);
      }
      else
      {
        strSendSignalData.bSSLNewFilterRslt = TRUE;
      }

      if(strSendSignalData.bSSLNewFilterRslt == TRUE)
#endif
      {
/* !Deviation: [2215] Indentation is correct in case
COM_FILTER_SIDE == Com_u8FILTER_SIDE_TX */
/* PRQA S 2215 ++ */
        /*! Pack the signal in the I-PDU buffer */
        if(strSendSignalData.u8SSLSigStructType == (uint8) Com_u8SIG_STRUCT_SIG)
        {
			/* !Deviation: [0291]  ( An integer expression with a value that is apparently 
			negative is being converted to an unsigned type. ) */
			/*[0505]  ( Dereferencing pointer value that is apparently NULL. ) */
			/*[0715]  ( Nesting of control structures (statements) exceeds 15 - program is 
			non-conforming.) */
			/*[0769]  ( This break statement terminates an iteration statement. ) */
			/*[2018]  ( This switch default label is unreachable. ) */
			/*[3201]  ( This statement is unreachable. ) */
			/*[3212]  ( This explicit cast is redundant and could be removed. ) */
			/*[3297]  ( Implicit unsigned conversion on positive integer expression 
			will apparently not preserve value. ) */
			/*[3325]  ( This control expression has a constant 'false' value. ) */
			/*[3334]  ( This declaration of 'pkstrLocDstDscPB' hides a more global
			declaration. ) */
			/*[3353]  ( The variable 'u8RemSigBits' is possibly unset at this point. ) */
			/*[3356]  ( The result of this logical operation is always 'false'. ) */
			/*[3359]  ( The value of this control expression is always 'false'. ) */
			/*[3382]  ( Unsigned arithmetic apparently results in wraparound past zero. ) */
			/*[3762]  ( Implicit conversion: int to unsigned long. ) */
			/*PRQA S 0291, 0505, 0715, 0769, 2018, 3201, 3212, 3297, 3325, 3334, 3353, 3356, 3359, 3382, 3762 ++ */
			 /* Com-CDD-TxHandler-0262(0),
		Com-CDD-0437(0) , Com-CDD-0438(0) ,
		Com-CDD-0439(0) , Com-CDD-0441(0) ,
		Com-CDD-0440(0) , Com-CDD-0442(0) ,
		Com-CDD-0443(0) , Com-CDD-TxHandler-5721(0) , 
		Com-CDD-TxHandler-0269(0) */
		#if	(Com_bFLOAT_SIGNAL_SUPPORT == STD_OFF)
		if(u8CurrentSigType !=Com_u8SIGNAL_TYPE_FLOAT32 && u8CurrentSigType !=Com_u8SIGNAL_TYPE_FLOAT64)
		#endif
		{
          Com_vidSignalPackSignal(strSendSignalData.u16SSLCurrentSigIx, SignalDataPtr,
                                  Com_u8SIG_STRUCT_SIG, (uint16)0);
		}
	      /*PRQA S 0291, 0505, 0715, 0769, 2018, 3201, 3212, 3297, 3325, 3334, 3353, 3356, 3359, 3382, 3762 -- */
        }
		
#if (Com_bGW_DESC_SUPPORT == STD_ON) 
        else /* u8SSLSigStructType == Com_u8SIG_STRUCT_DSTDESC */
        {
          /*! Call Com_SignalPackSignal to write signal data referenced by \n
          SignalDataPtr into the I-PDU RAM buffer. */
			/* Com-CDD-TxHandler-0284(0) */
			/* !Deviation: [0291]  ( An integer expression with a value that is apparently 
			negative is being converted to an unsigned type. ) */
			/*[0505]  ( Dereferencing pointer value that is apparently NULL. ) */
			/*[0715]  ( Nesting of control structures (statements) exceeds 15 - program is 
			non-conforming.) */
			/*[0769]  ( This break statement terminates an iteration statement. ) */
			/*[2018]  ( This switch default label is unreachable. ) */
			/*[3201]  ( This statement is unreachable. ) */
			/*[3212]  ( This explicit cast is redundant and could be removed. ) */
			/*[3297]  ( Implicit unsigned conversion on positive integer expression 
			will apparently not preserve value. ) */
			/*[3325]  ( This control expression has a constant 'false' value. ) */
			/*[3334]  ( This declaration of 'pkstrLocDstDscPB' hides a more global
			declaration. ) */
			/*[3353]  ( The variable 'u8RemSigBits' is possibly unset at this point. ) */
			/*[3356]  ( The result of this logical operation is always 'false'. ) */
			/*[3359]  ( The value of this control expression is always 'false'. ) */
			/*[3382]  ( Unsigned arithmetic apparently results in wraparound past zero. ) */
			/*[3762]  ( Implicit conversion: int to unsigned long. ) */
			/*PRQA S 0291, 0505, 0715, 0769, 2018, 3201, 3212, 3297, 3325, 3334, 3353, 3356, 3359, 3382, 3762 ++ */
			
			  /* Com-CDD-TxHandler-0262(0),
		Com-CDD-0437(0) , Com-CDD-0438(0) ,
		Com-CDD-0439(0) , Com-CDD-0441(0) ,
		Com-CDD-0440(0) , Com-CDD-0442(0) ,
		Com-CDD-0443(0) , Com-CDD-TxHandler-5721(0) , 
		Com-CDD-TxHandler-0269(0) */
		#if	(Com_bFLOAT_SIGNAL_SUPPORT == STD_OFF)
		if(u8CurrentSigType !=Com_u8SIGNAL_TYPE_FLOAT32 && u8CurrentSigType !=Com_u8SIGNAL_TYPE_FLOAT64)
		#endif
		{
          Com_vidSignalPackSignal(strSendSignalData.u16SSLCurrentSigIx, SignalDataPtr,
                                  Com_u8SIG_STRUCT_DSTDESC, (uint16)0);
		}
		   /*PRQA S 0291, 0505, 0715, 0769, 2018, 3201, 3212, 3297, 3325, 3334, 3353, 3356, 3359, 3382, 3762 -- */
        }
#endif

#if (Com_bUBIT_SUPPORT== STD_ON)    
        /*! check if the signal has ubdate-bit configured*/
		
		if(u16UpdBitPos != (uint16)0xFFFFu)
        {
          /*! Set update bit */
          /* Com-CDD-TxHandler-0502(0) */
          Com_vidSignalEditUpdateBit(strSendSignalData.u8SSLSigStructType,
                                     strSendSignalData.u16SSLCurrentSigIx,
									 u16UpdBitPos,
                                     TRUE);
        }
        else
        {

        }
#endif
     
	 }
/* PRQA S 2215 -- */
#if Com_u8FILTERING_DIR  == Com_u8DIRECTION_TX
      else /* strSendSignalData.bSSLNewFilterRslt == FALSE */
      {

      }
#endif
    }
    else
    {
      strSendSignalData.u8SSLReturnValue = COM_BUSY;
    }

  
 SchM_Enter_Com_IPduStatus_0A();
  bIPduIsActive = Com_bIpduCheckActive(strSendSignalData.u16SSLCurrentIPduId);
 SchM_Exit_Com_IPduStatus_0A();
  
  
  if(bIPduIsActive == FALSE)
  {
    strSendSignalData.u8SSLReturnValue = COM_SERVICE_NOT_AVAILABLE;
	#if u16NO_OF_IPDUS_STATUS > 0u
	SchM_Enter_Com_IPduStatus_0A();
	Com_audteIPduStatus[*pu16SSLCrntIPduId] |= Com_u8RX_DM_EN_TX_STOP;
	SchM_Exit_Com_IPduStatus_0A();  
	#endif
  }
  else
  {
	#if u16NO_OF_IPDUS_STATUS > 0u
  	SchM_Enter_Com_IPduStatus_0A();
	Com_audteIPduStatus[*pu16SSLCrntIPduId] &= (Com_udtIPduStatus)~Com_u8RX_DM_EN_TX_STOP;
	SchM_Exit_Com_IPduStatus_0A();  
	#endif
  }
  
  
#if (Com_bTX_INACTIVE_ERROR == STD_ON) 
  if((bIPduIsActive == FALSE) &&
     (strSendSignalData.u8SSLSigStructType == (uint8) Com_u8SIG_STRUCT_SIG))
  {
#if Com_u16NO_OF_SIGNAL > 0u
    /*! Check if the signal has Error Notification configured*/
	   
	 pudtSigTxErrorNotif = 
	 Com_akstreSignalLT[strSendSignalData.u16SSLCurrentSigIx].
        pfvidComErrorNotification;
	if(pudtSigTxErrorNotif != NULL_PTR)
    {
      /*! Call signal Error Notification */
      /* Com-CDD-TxHandler-5725(0) */
      (*pudtSigTxErrorNotif)();
    }
    else
    {

    }
#endif
  }
#endif
 }
#if (COM_DEV_ERROR_DETECT == STD_ON)
  }
}
#endif
  return strSendSignalData.u8SSLReturnValue;
} /* Com_SendSignal() */
/* PRQA S 4700 -- */

/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
Partitioning this function shall not pay for the negative effect of context
switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description The service Com_SendDynSignal updates the signal object \n
                 identified by SignalId with the signal referenced by \n
                 the SignalDataPtr parameter \n
    \param[in]  SignalId Id of signal to be sent.
                SignalDataPtr Reference to the signal data to be transmitted
                Length Length of the dynamic length signal
*******************************************************************************/
/*! \Trace_To     Com-CDD-TxHandler-0115(0),
                  Com-CDD-TxHandler-0410(0),
                  Com-CDD-TxHandler-0411(0),
                  Com-CDD-TxHandler-0412(0),
                  Com-CDD-TxHandler-0413(0),
                  Com-CDD-TxHandler-5715(0),
                  Com-CDD-TxHandler-0309(0),
                  Com-CDD-TxHandler-0310(0),
                  Com-CDD-TxHandler-0314(0),
                  Com-CDD-TxHandler-5713(0),
                  Com-CDD-TxHandler-5711(0),
                  Com-CDD-TxHandler-5737(0),
				  Com-CDD-5746(0), Com-CDD-5744(1),
                  Com-CDD-0497(0),Com-CDD-5748(1), Com-CDD-5546(1) */
#if (Com_bDATA_TP_SUPPORT == STD_ON)
FUNC(uint8, COM_CODE) Com_SendDynSignal(
                          VAR(Com_SignalIdType, AUTOMATIC)  SignalId,
                          P2CONST(void, AUTOMATIC, COM_MAX_CALIB_APPL_CFGCONST)
                                                            SignalDataPtr,
                          VAR(uint16, AUTOMATIC) Length )
{
  /*! Local variables */
  VAR(boolean, AUTOMATIC)            bIPduWaitForConf;
  VAR(boolean, AUTOMATIC)            bIPduIsActive;

#if (COM_DEV_ERROR_DETECT == STD_ON)
  VAR(uint8, AUTOMATIC)              u8CurrentSigType;
#endif /*COM_DEV_ERROR_DETECT*/

  VAR(tstrSendSignalData, AUTOMATIC) strSendSignalData;

  P2VAR(PduIdType, AUTOMATIC,AUTOMATIC)			pu16SSLCrntIPduId;
  P2CONST(Com_tstrSignalPB,AUTOMATIC,TYPEDEF)	pkstrLocSigPB;

#if (Com_bUBIT_SUPPORT == STD_ON)
  VAR(uint16, AUTOMATIC)					u16UpdBitPos;
#endif

#if (Com_bTX_INACTIVE_ERROR == STD_ON) 
 Com_tpfvidSigTxErrorNotif 					pudtSigTxErrorNotif; 
#endif



  strSendSignalData.u8SSLReturnValue  = E_OK;

  strSendSignalData.bSSLSendIPdu = FALSE;

  strSendSignalData.u16SSLDynLength = Length;

#if (COM_DEV_ERROR_DETECT == STD_ON)
  /*! DET check and reporting */
  /* Com-CDD-TxHandler-0405(0) */
  if (Com_enueStatus == COM_UNINIT)
  {

/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    /* Com-CDD-TxHandler-0410(0) */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_SendDynSignal , COM_E_UNINIT);
/* PRQA S 3212 -- */

    strSendSignalData.u8SSLReturnValue = COM_SERVICE_NOT_AVAILABLE;
  }
  else
  { 

    if ((SignalId > Com_u16SIGNALIDMAX) ||
        (u8SIG_GET_STRUCT_TYPE(SignalId) != (uint8) Com_u8SIG_STRUCT_SIG))
    {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
      (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                      COMServiceId_SendDynSignal , COM_E_PARAM);
/* PRQA S 3212 -- */

      strSendSignalData.u8SSLReturnValue = COM_SERVICE_NOT_AVAILABLE;
    }
    else
    {
	
	
	  strSendSignalData.u16SSLCurrentSigIx = 
                        u16SIG_GET_LKUP_IX(SignalId);
      pkstrLocSigPB = pkstrGET_PB_SIGNAL_PTR(strSendSignalData.u16SSLCurrentSigIx);
      strSendSignalData.u8SSLCurrentSigDir =
                            u8SIG_GET_DIR(strSendSignalData.u16SSLCurrentSigIx);
							
	  u8CurrentSigType = pkstrLocSigPB->u8SignalType;
      /* Com-CDD-TxHandler-0406(0) */
      if ((strSendSignalData.u8SSLCurrentSigDir != Com_u8SIG_DIR_SEND)        ||
          (u8CurrentSigType                     != Com_u8SIGNAL_TYPE_UINT8DYN)
#if Com_u16NO_OF_SIGNAL > 0u
          ||
          (Length >
                Com_akstreSignalLT[strSendSignalData.u16SSLCurrentSigIx].
                                                               u16SignalLength)
#endif
          )
      {

/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                        COMServiceId_SendDynSignal , COM_E_PARAM);
/* PRQA S 3212 -- */

        strSendSignalData.u8SSLReturnValue = COM_SERVICE_NOT_AVAILABLE;
      }
      /* Com-CDD-TxHandler-0407(0) */
      else if ( SignalDataPtr == NULL_PTR )
      {

/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                        COMServiceId_SendDynSignal , COM_E_PARAM_POINTER);
/* PRQA S 3212 -- */

        strSendSignalData.u8SSLReturnValue = COM_SERVICE_NOT_AVAILABLE;
      }
      else
      {

      }
	 }
    }
										 						 

  if(strSendSignalData.u8SSLReturnValue == E_OK)
#endif /*COM_DEV_ERROR_DETECT*/ 
  {    
	strSendSignalData.u16SSLCurrentSigIx   = u16SIG_GET_LKUP_IX(SignalId);
    pkstrLocSigPB = pkstrGET_PB_SIGNAL_PTR(strSendSignalData.u16SSLCurrentSigIx);
    strSendSignalData.u16SSLCurrentIPduId  = pkstrLocSigPB->u16IPduIndex;
	 #if (Com_bUBIT_SUPPORT== STD_ON)  
      u16UpdBitPos = pkstrLocSigPB->u16UpdateBitPosition;
	 #endif									 
    strSendSignalData.u16SSLCurrentIPduIx  =
                        u16IPDU_GET_IX(strSendSignalData.u16SSLCurrentIPduId);

	pu16SSLCrntIPduId = &(strSendSignalData.u16SSLCurrentIPduId);
	
	#if u16NO_OF_IPDUS_STATUS > 0u
   SchM_Enter_Com_IPduStatus_21();
	bIPduWaitForConf = Com_audteIPduStatus[*pu16SSLCrntIPduId] & Com_u8WAIT_CONF;
   SchM_Exit_Com_IPduStatus_21();
	#endif
	
  strSendSignalData.u8SSLSigStructType   = (uint8) Com_u8SIG_STRUCT_SIG;

    /*! If IPdu buffer is not locked, handle request normally */
    /* Com-CDD-TxHandler-5711(0) */
    if(bIPduWaitForConf == FALSE)
    {
      strSendSignalData.u8SSLNewTxModeType   = (uint8)0;
      strSendSignalData.u16SSLNewTxModeIndex = (uint16)0;
      strSendSignalData.bSSLSignalIsChanged  = FALSE;

      vidHandleUbitTrigOnCh(SignalId, SignalDataPtr,&strSendSignalData);
      /*! if bSSLSignalIsChanged == TRUE, this means whether this signal:
            - is changed wit TxProperty Tigger on change,
            - has TxProperty Tigger or
            - has TxProperty pending.
          in all 3 cases this signal might change TMS, and extra processing is
          needed in Com_MainFunctionTx.*/

      if(strSendSignalData.bSSLSignalIsChanged == TRUE)
      {
/* !Deviation: [3201, 3325]  This statement is unreachable. This is reachable
throught assignment of bSSLSignalIsChanged in vidHandleUbitTrigOnCh */
/* PRQA S 3201 ++ */
/* PRQA S 3325 ++ */
/* !Deviation: [3361]  This 'do - while' control expression has a constant,
'false' value. This is intended. (multi-line function like MACRO) */
/* PRQA S 3361 ++ */
#if (Com_bTMS_SUPPORT == STD_ON)
			
		  #if Com_u16NO_OF_SIGNAL_STATUS > 0u
		 SchM_Enter_Com_SignalStatus_21();
		  Com_audteSignalStatus[SignalId] |= Com_u8SS_TMS_REQ;
		 SchM_Exit_Com_SignalStatus_21(); 
		  #endif
		  
#endif  /*Com_bTMS_SUPPORT*/
/* PRQA S 3361 -- */
/* PRQA S 3325 -- */
/* PRQA S 3201 -- */
		#if u16NO_OF_IPDUS_STATUS > 0u
	  	SchM_Enter_Com_IPduStatus_21();
		Com_audteIPduStatus[*pu16SSLCrntIPduId] |= Com_u8SENDSIGNAL_RQ;
		SchM_Exit_Com_IPduStatus_21();
		#endif
		

      }
      else
      {

      }

      /* Com-CDD-TxHandler-0284(0) */
      /* Com-CDD-TxHandler-0061(0) */
      /* Com-CDD-TxHandler-0305(0) */
      /* Com-CDD-TxHandler-0298(0) */
      /*! Pack the signal in the I-PDU buffer */
      /* Com-CDD-TxHandler-5715(0) */
      /* Com-CDD-TxHandler-0310(0) */
      /* Com-CDD-TxHandler-5713(0) */
		/* !Deviation: [0291]  ( An integer expression with a value that is apparently 
		negative is being converted to an unsigned type. ) */
		/*[0505]  ( Dereferencing pointer value that is apparently NULL. ) */
		/*[0715]  ( Nesting of control structures (statements) exceeds 15 - program is 
		non-conforming.) */
		/*[0769]  ( This break statement terminates an iteration statement. ) */
		/*[2018]  ( This switch default label is unreachable. ) */
		/*[3201]  ( This statement is unreachable. ) */
		/*[3212]  ( This explicit cast is redundant and could be removed. ) */
		/*[3297]  ( Implicit unsigned conversion on positive integer expression 
		will apparently not preserve value. ) */
		/*[3325]  ( This control expression has a constant 'false' value. ) */
		/*[3334]  ( This declaration of 'pkstrLocDstDscPB' hides a more global
		declaration. ) */
		/*[3353]  ( The variable 'u8RemSigBits' is possibly unset at this point. ) */
		/*[3356]  ( The result of this logical operation is always 'false'. ) */
		/*[3359]  ( The value of this control expression is always 'false'. ) */
		/*[3382]  ( Unsigned arithmetic apparently results in wraparound past zero. ) */
		/*[3762]  ( Implicit conversion: int to unsigned long. ) */
		/*PRQA S 0505, 0291, 0715, 0769, 2018, 3201, 3212, 3297, 3325, 3334, 3353, 3356, 3359, 3382, 3762 ++ */
        Com_vidSignalPackSignal(strSendSignalData.u16SSLCurrentSigIx, SignalDataPtr,
                              Com_u8SIG_STRUCT_SIG, Length);
	    /*PRQA S 0505, 0291, 0715, 0769, 2018, 3201, 3212, 3297, 3325, 3334, 3353, 3356, 3359, 3382, 3762 -- */

#if (Com_bUBIT_SUPPORT== STD_ON)  
      /*! check if the signal has update-bit configured*/
	  if(u16UpdBitPos != (uint16)0xFFFFu)
      {
        /*! Set update bit */
        /* Com-CDD-TxHandler-0502(0) */
        Com_vidSignalEditUpdateBit(strSendSignalData.u8SSLSigStructType,
                                   strSendSignalData.u16SSLCurrentSigIx,
								   u16UpdBitPos,
                                   TRUE);
      }
      else
      {

      }
#endif
    }
    else
    {
      strSendSignalData.u8SSLReturnValue = COM_BUSY;
    }

 SchM_Enter_Com_IPduStatus_21();
  bIPduIsActive = Com_bIpduCheckActive(strSendSignalData.u16SSLCurrentIPduId);
 SchM_Exit_Com_IPduStatus_21();
  
  
  if(bIPduIsActive == FALSE)
  {
    strSendSignalData.u8SSLReturnValue = COM_SERVICE_NOT_AVAILABLE;
  }
  else
  {

  }

#if (Com_bTX_INACTIVE_ERROR == STD_ON) 
  if((bIPduIsActive == FALSE) &&
     (strSendSignalData.u8SSLSigStructType == (uint8) Com_u8SIG_STRUCT_SIG))
  {
#if Com_u16NO_OF_SIGNAL > 0u
    /*! Check if the signal has Error Notification configured*/
	
	pudtSigTxErrorNotif = 
	 Com_akstreSignalLT[strSendSignalData.u16SSLCurrentSigIx].
        pfvidComErrorNotification;
	if(pudtSigTxErrorNotif != NULL_PTR)
    {
      /*! Call signal Error Notification */
      /* Com-CDD-TxHandler-5725(0) */
      (*pudtSigTxErrorNotif)();
    }
    else
    {

    }
#endif /*Com_u16NO_OF_SIGNAL*/
  }
#endif /*Com_bTX_INACTIVE_ERROR*/
  } 
  return strSendSignalData.u8SSLReturnValue;
} /* Com_SendDynSignal() */
/* PRQA S 4700 -- */
#endif /*Com_bDATA_TP_SUPPORT*/ 

/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
This function deviates in STCYC = 13 and STSUB = 21. Partitioning this
function shall not pay for the negative effect of context switching. */
/* PRQA S 4700 ++ */
/* !Deviation: [3206]  Due to differnt combinations of Pre-compile options some
parameters shall not be used */
/* PRQA S 3206 ++ */
/******************************************************************************/
/*! \Description This service copy data to shadow buffer
    \param[in]  u16SignalId ID of the group signal
    \param[in]  pkvidSignalDataPtr pointer to data
*******************************************************************************/
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON) 
static FUNC(void, COM_CODE) vidWriteShadowBuff (
    VAR(Com_SignalIdType, AUTOMATIC) u16SignalId,
    P2CONST(void, AUTOMATIC, COM_MAX_CALIB_APPL_CFGCONST) pkvidSignalDataPtr)
{
/* PRQA S 3206 -- */
#if Com_u16NO_OF_GROUP_SIGSLT > 0u
  /*! Local variables */

  VAR(uint8, AUTOMATIC)       u8CurrentSigType;

  VAR(uint16, AUTOMATIC)      u16CurrentSigIx;

  VAR(uint16, AUTOMATIC)      u16CurrentSignalLength;
  VAR(uint16_least, AUTOMATIC)      u16ByteLoopIndex;

  P2VAR(void, AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)
                              pvidCurrGSigShadowPtr;

  u16CurrentSigIx   = u16SIG_GET_LKUP_IX(u16SignalId);
  u8CurrentSigType  = u8GSIG_GET_TYPE(u16CurrentSigIx);

  pvidCurrGSigShadowPtr = Com_pvidGetGSigShadowPtr(u16CurrentSigIx);

  switch(u8CurrentSigType)
  {
    case Com_u8SIGNAL_TYPE_BOOLEAN:
   SchM_Enter_Com_SigObjB();
    *(P2VAR(boolean,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
    pvidCurrGSigShadowPtr =
              *(P2CONST(boolean,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
              pkvidSignalDataPtr;
   SchM_Exit_Com_SigObjB();
    break;
	
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON) 
    case Com_u8SIGNAL_TYPE_FLOAT32:
   SchM_Enter_Com_SigObjF32();
    *(P2VAR(float32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
    pvidCurrGSigShadowPtr =
              *(P2CONST(float32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
              pkvidSignalDataPtr;
   SchM_Exit_Com_SigObjF32();
    break;
    case Com_u8SIGNAL_TYPE_FLOAT64:
   SchM_Enter_Com_SigObjF64();
    *(P2VAR(float64,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
    pvidCurrGSigShadowPtr =
              *(P2CONST(float64,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
              pkvidSignalDataPtr;
   SchM_Exit_Com_SigObjF64();
    break;
#endif

    case Com_u8SIGNAL_TYPE_SINT16:
   SchM_Enter_Com_SigObjS16();
    *(P2VAR(sint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pvidCurrGSigShadowPtr =
              *(P2CONST(sint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)) pkvidSignalDataPtr;
   SchM_Exit_Com_SigObjS16();
    break;
    case Com_u8SIGNAL_TYPE_SINT32:
   SchM_Enter_Com_SigObjS32();
    *(P2VAR(sint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
    pvidCurrGSigShadowPtr =
              *(P2CONST(sint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
              pkvidSignalDataPtr;
   SchM_Exit_Com_SigObjS32();
    break;
    case Com_u8SIGNAL_TYPE_SINT8:
   SchM_Enter_Com_SigObjS8();
    *(P2VAR(sint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pvidCurrGSigShadowPtr =
              *(P2CONST(sint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)) pkvidSignalDataPtr;
   SchM_Exit_Com_SigObjS8();
    break;
    case Com_u8SIGNAL_TYPE_UINT16:
   SchM_Enter_Com_SigObjU16();
    *(P2VAR(uint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
    pvidCurrGSigShadowPtr =
              *(P2CONST(uint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
              pkvidSignalDataPtr;
   SchM_Exit_Com_SigObjU16();
    break;
    case Com_u8SIGNAL_TYPE_UINT32:
   SchM_Enter_Com_SigObjU32();
    *(P2VAR(uint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
    pvidCurrGSigShadowPtr =
              *(P2CONST(uint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
              pkvidSignalDataPtr;
   SchM_Exit_Com_SigObjU32();
    break;
    case Com_u8SIGNAL_TYPE_UINT8:
   SchM_Enter_Com_SigObjU8();
    *(P2VAR(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
    pvidCurrGSigShadowPtr =
              *(P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
              pkvidSignalDataPtr;
   SchM_Exit_Com_SigObjU8();
    break;
    case Com_u8SIGNAL_TYPE_UINT8N:
    u16CurrentSignalLength =
      Com_akstreGroupSignalLT[u16CurrentSigIx].u16SignalLength;
   SchM_Enter_Com_SigObjU8();
    for(u16ByteLoopIndex = 0; u16ByteLoopIndex < u16CurrentSignalLength;
        u16ByteLoopIndex++)
    {
      ((P2VAR(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
       pvidCurrGSigShadowPtr)[u16ByteLoopIndex] =
      ((P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))
       pkvidSignalDataPtr)[u16ByteLoopIndex];
    }
   SchM_Exit_Com_SigObjU8();
    break;
    default:

    break;
  }
#endif
} /* vidWriteShadowBuff */
/* PRQA S 4700 -- */

/******************************************************************************/
/*! \Description  The service Com_UpdateShadowSignal updates a group signal \n
                  with the data, referenced by SignalDataPtr.
    \param[in]  SignalId Id of group signal to be updated
                SignalDataPtr Reference to the group signal data to be updated
*******************************************************************************/
/*! \Trace_To     Com-CDD-TxHandler-0414(0),
                  Com-CDD-TxHandler-0415(0),
                  Com-CDD-TxHandler-0416(0),
                  Com-CDD-TxHandler-0417(0),
                  Com-CDD-TxHandler-0013(0),
                  Com-CDD-TxHandler-0226(0),
                  Com-CDD-0210(0),
                  Com-CDD-0211(0) */

FUNC(void, COM_CODE) Com_UpdateShadowSignal (
    VAR(Com_SignalIdType, AUTOMATIC) SignalId,
    P2CONST(void, AUTOMATIC, COM_MAX_CALIB_APPL_CFGCONST) SignalDataPtr)
{
  /*! Local variables */
  VAR(uint8, AUTOMATIC)                 u8DetErrorStatus;
  VAR(uint8, AUTOMATIC)                 u8CurrentSigDir;
  VAR(uint16, AUTOMATIC)                u16CurrentSigIx;


  u8DetErrorStatus = E_OK;

  /*! DET check and reporting */

  if (Com_enueStatus == COM_UNINIT)
  {
    u8DetErrorStatus = E_NOT_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_UpdateShadowSignal , COM_E_UNINIT);
/* PRQA S 3212 -- */
#endif /*COM_DEV_ERROR_DETECT*/
  }
  else
  {
    if (SignalId > Com_u16SIGNALIDMAX)
    {
      u8DetErrorStatus = E_NOT_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
      (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                      COMServiceId_UpdateShadowSignal , COM_E_PARAM);
/* PRQA S 3212 -- */
#endif /*COM_DEV_ERROR_DETECT*/
    }
    else
    {
      u16CurrentSigIx = u16SIG_GET_LKUP_IX(SignalId);
      u8CurrentSigDir =     u8GSIG_GET_DIR(u16CurrentSigIx);
      if ((u8SIG_GET_STRUCT_TYPE(SignalId) != (uint8) Com_u8SIG_STRUCT_GROUPSIG) ||
                  (u8CurrentSigDir != Com_u8SIG_DIR_SEND))
      {
        u8DetErrorStatus = E_NOT_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                        COMServiceId_UpdateShadowSignal , COM_E_PARAM);
/* PRQA S 3212 -- */
#endif /*COM_DEV_ERROR_DETECT*/
      }
      else if ( SignalDataPtr == NULL_PTR )
      {
        u8DetErrorStatus = E_NOT_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                        COMServiceId_UpdateShadowSignal , COM_E_PARAM_POINTER);
/* PRQA S 3212 -- */
#endif /*COM_DEV_ERROR_DETECT*/
      }
      else
      {

      }
    }
  }
  /* if no error */
  if(u8DetErrorStatus == E_OK)
  {
    vidWriteShadowBuff(SignalId, SignalDataPtr);
  } 
} /* Com_UpdateShadowSignal */
#endif /*Com_bSIGNAL_GROUP_SUPPORT*/
/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
This function deviates in STCYC = 15 and STSUB = 12. Partitioning this
function shall not pay for the negative effect of context switching. */
/* PRQA S 4700 ++ */
/* !Deviation: [3206]  Due to differnt combinations of Pre-compile options some
parameters shall not be used */
/* PRQA S 3206 ++ */
/******************************************************************************/
/*! \Description The service Com_InvalidateShadowSignal invalidates the group \n
                 signal with the given SignalId by setting its value to its \n
                 configured ComSignalDataInvalidValue.
    \param[in]  SignalId Id of group signal to be invalidated.
*******************************************************************************/
/*! \Trace_To     Com-CDD-TxHandler-0118(0),
                  Com-CDD-TxHandler-0424(0),
                  Com-CDD-TxHandler-0425(0),
                  Com-CDD-TxHandler-0426(0),
                  Com-CDD-TxHandler-0009(0),
                  Com-CDD-TxHandler-5719(0),
                  Com-CDD-0229(0) */
#if ((Com_bSIGNAL_GROUP_SUPPORT == STD_ON) && (Com_bDATA_INVALID_SUPPORT == STD_ON))
FUNC(void, COM_CODE) Com_InvalidateShadowSignal(
                                  VAR(Com_SignalIdType, AUTOMATIC)  SignalId )
{
/* PRQA S 3206 -- */
#if Com_u16NO_OF_GROUP_SIGSLT > 0u
  /*! Local variables */

  VAR(uint8, AUTOMATIC)         u8CurrentSigType;

  VAR(uint16, AUTOMATIC)        u16CurrentSigIx;
  VAR(uint16, AUTOMATIC)        u16InvalidValIndex;
  /*! DET check and reporting */
#if (COM_DEV_ERROR_DETECT == STD_ON)
  if (Com_enueStatus == COM_UNINIT)
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_InvalidateShadowSignal , COM_E_UNINIT);
/* PRQA S 3212 -- */
  }
  else if (SignalId > Com_u16SIGNALIDMAX)
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_InvalidateShadowSignal , COM_E_PARAM);
/* PRQA S 3212 -- */
  }
  else if ((u8SIG_GET_STRUCT_TYPE(SignalId) !=
                                          (uint8) Com_u8SIG_STRUCT_GROUPSIG) ||
           (u8GSIG_GET_DIR(u16SIG_GET_LKUP_IX(SignalId)) !=
                                                          Com_u8SIG_DIR_SEND) ||
           (u8GSIG_GET_TYPE(u16SIG_GET_LKUP_IX(SignalId)) == Com_u8SIGNAL_TYPE_UINT8N) ||
           (u8GSIG_GET_TYPE(u16SIG_GET_LKUP_IX(SignalId)) == Com_u8SIGNAL_TYPE_UINT8DYN))
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_InvalidateShadowSignal , COM_E_PARAM);
/* PRQA S 3212 -- */
  }
  else
#endif /*COM_DEV_ERROR_DETECT*/
  {
  
#if ((Com_bDATA_INVALID_SUPPORT == STD_ON) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))

	u16CurrentSigIx = u16SIG_GET_LKUP_IX(SignalId);
	u8CurrentSigType = u8GSIG_GET_TYPE(u16CurrentSigIx);
	u16InvalidValIndex = Com_akstreGroupSignalLT[u16CurrentSigIx].
                            u16SigInvalidValIndex;
	if(u16InvalidValIndex != (uint16)0xFFFFu)
    {
      switch(u8CurrentSigType)
      {
      /* Com-CDD-TxHandler-0227(0) */
        case Com_u8SIGNAL_TYPE_BOOLEAN:
#if Com_u16SIG_INV_V_B_SIZE > 0u
        vidWriteShadowBuff(SignalId,
                           &Com_akbeSigInvalidValB[u16InvalidValIndex]);
#endif
        break;

        case Com_u8SIGNAL_TYPE_FLOAT32:
#if Com_u16SIG_INV_V_F32_SIZE > 0u
        vidWriteShadowBuff(SignalId,
                           &Com_akf32eSigInvalidValF32[u16InvalidValIndex]);
#endif
        break;

        case Com_u8SIGNAL_TYPE_FLOAT64:
#if Com_u16SIG_INV_V_F64_SIZE > 0u
        vidWriteShadowBuff(SignalId,
                           &Com_akf64eSigInvalidValF64[u16InvalidValIndex]);
#endif
        break;

        case Com_u8SIGNAL_TYPE_SINT16:
#if Com_u16SIG_INV_V_S16_SIZE > 0u
        vidWriteShadowBuff(SignalId,
                           &Com_aks16eSigInvalidValS16[u16InvalidValIndex]);
#endif
        break;

        case Com_u8SIGNAL_TYPE_SINT32:
#if Com_u16SIG_INV_V_S32_SIZE > 0u
        vidWriteShadowBuff(SignalId,
                           &Com_aks32eSigInvalidValS32[u16InvalidValIndex]);
#endif
        break;

        case Com_u8SIGNAL_TYPE_SINT8:
#if Com_u16SIG_INV_V_S8_SIZE > 0u
        vidWriteShadowBuff(SignalId,
                           &Com_aks8eSigInvalidValS8[u16InvalidValIndex]);
#endif
        break;

        case Com_u8SIGNAL_TYPE_UINT16:
#if Com_u16SIG_INV_V_U16_SIZE > 0u
        vidWriteShadowBuff(SignalId,
                           &Com_aku16eSigInvalidValU16[u16InvalidValIndex]);
#endif
        break;

        case Com_u8SIGNAL_TYPE_UINT32:

#if Com_u16SIG_INV_V_U32_SIZE > 0u
        vidWriteShadowBuff(SignalId,
                           &Com_aku32eSigInvalidValU32[u16InvalidValIndex]);
#endif

        break;

        case Com_u8SIGNAL_TYPE_UINT8:
#if Com_u16SIG_INV_V_U8U8N_SIZE > 0u
        vidWriteShadowBuff(SignalId,
                           &Com_aku8eSigInvalidValU8U8N[u16InvalidValIndex]);
#endif
        break;

        case Com_u8SIGNAL_TYPE_UINT8N:
        case Com_u8SIGNAL_TYPE_UINT8DYN:
          /* Not supported */
        break;

        default:

        break;
      }
    }
    else /* No configured InvalidValue */
    {
    }
#endif  
  }

#endif /* Com_u16NO_OF_GROUP_SIGSLT > 0u */
} /* Com_InvalidateShadowSignal() */

/* PRQA S 4700 -- */

/* !Deviation: [3206]  Due to differnt combinations of Pre-compile options some
parameters shall not be used   */
/* PRQA S 3206 ++ */
/******************************************************************************/
/*! \Description The service Com_InvalidateSignalGroup invalidates all group \n
                 signals of the signal group with the given SignalGroupId by \n
                 setting their values to their configured \n
                 ComSignalDataInvalidValues.
    \param[in]  SignalGroupId Id of signal group to be invalidated.
*******************************************************************************/
/*! \Trace_To       Com-CDD-TxHandler-0119(0),
                    Com-CDD-TxHandler-0427(0),
                    Com-CDD-TxHandler-0428(0),
                    Com-CDD-TxHandler-0429(0),
                    Com-CDD-TxHandler-0010(0),
                    Com-CDD-0231(0) */
FUNC(uint8, COM_CODE) Com_InvalidateSignalGroup(
                                        Com_SignalGroupIdType SignalGroupId )
{
  /*! Local variables */
  VAR(uint8, AUTOMATIC)             u8ReturnValue;
#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
  VAR(uint8, AUTOMATIC)             u8CurrGSigType;
  VAR(boolean, AUTOMATIC)           bIPduIsActive;
  VAR(PduIdType, AUTOMATIC)         u16CurrentIPduId;
  VAR(uint16, AUTOMATIC)            u16NoOfGroupSig;
  VAR(uint16, AUTOMATIC)            u16CurrFirstGSigIx;
  VAR(uint16_least, AUTOMATIC)            u16GroupSigLoopIndex;
  VAR(Com_SignalIdType, AUTOMATIC)  u16CurrGSigId;
  P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,TYPEDEF)pkstrSigGrpB;
  P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,TYPEDEF)pkstrGrpSigPB;
#endif

  /*! DET check and reporting */
#if (COM_DEV_ERROR_DETECT == STD_ON)
  /* Com-CDD-TxHandler-0421(0) */
  if (Com_enueStatus == COM_UNINIT)
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_InvalidateSignalGroup , COM_E_UNINIT);
    u8ReturnValue = COM_SERVICE_NOT_AVAILABLE;

/* PRQA S 3212 -- */
  }
  /* Com-CDD-TxHandler-0422(0) */
  else if (SignalGroupId > Com_u16SIGNALGROUPIDMAX)
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_InvalidateSignalGroup , COM_E_PARAM);
    u8ReturnValue = COM_SERVICE_NOT_AVAILABLE;
/* PRQA S 3212 -- */
  }
  else if ((u8SIGG_GET_DIR(SignalGroupId) != Com_u8SIG_DIR_SEND))
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_InvalidateSignalGroup , COM_E_PARAM);
    u8ReturnValue = COM_SERVICE_NOT_AVAILABLE;
/* PRQA S 3212 -- */
  }
  else
#endif /*COM_DEV_ERROR_DETECT*/
  {
#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u))
#if ((Com_bDATA_INVALID_SUPPORT == STD_ON) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
	pkstrSigGrpB = pkstrGET_PB_SIGGRP_PTR(SignalGroupId);
	pkstrGrpSigPB = pkstrGET_PB_GRP_SIG_PTR(0);
    u16CurrentIPduId        = pkstrSigGrpB->u16IPduIndex;

    /*! get the number of group signals in the signal group*/
    u16NoOfGroupSig = pkstrSigGrpB->u16NoOfGroupSignals;
	
    /*! get the index of the first group signal in the signal group*/
    u16CurrFirstGSigIx = pkstrSigGrpB->u16GroupSignalIndex;


    /*! For each group signal in the signal group */
    for(u16GroupSigLoopIndex = 0;
        u16GroupSigLoopIndex < u16NoOfGroupSig;
        u16GroupSigLoopIndex++)
    {
      /*! Get group signals ID */
      u16CurrGSigId = u16GET_G_SIG_ID(u16CurrFirstGSigIx +
                                      u16GroupSigLoopIndex);
      u8CurrGSigType = pkstrGrpSigPB[u16CurrFirstGSigIx + u16GroupSigLoopIndex].u8SignalType;

      if((u8CurrGSigType != Com_u8SIGNAL_TYPE_UINT8N) &&
         (u8CurrGSigType != Com_u8SIGNAL_TYPE_UINT8DYN))
      {
        /*! Call Com_InvalidateShadowSignal */
        Com_InvalidateShadowSignal(u16CurrGSigId);

      }
      else
      {

      }

    }
	SchM_Enter_Com_IPduStatus_1B();
    bIPduIsActive = Com_bIpduCheckActive(u16CurrentIPduId);
	SchM_Exit_Com_IPduStatus_1B();
	
    if(bIPduIsActive == FALSE)
    {
      u8ReturnValue = COM_SERVICE_NOT_AVAILABLE;
    }
    /* Com-CDD-TxHandler-0008(0) */
    else
    {
      /*! Call Com_SendSignalGroup */
      u8ReturnValue = Com_SendSignalGroup( SignalGroupId );
    }
#else
    u8ReturnValue = COM_SERVICE_NOT_AVAILABLE;
#endif
#endif
  }


  return u8ReturnValue;
} /* Com_InvalidateSignalGroup() */
#endif /*Com_bSIGNAL_GROUP_SUPPORT*/
/* PRQA S 3206 -- */
/* !Deviation: [3206]  Due to differnt combinations of Pre-compile options some
parameters shall not be used */
/* PRQA S 3206 ++ */
#if ((Com_bTMS_SUPPORT == STD_ON) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
/******************************************************************************/
/*! \Description This function handles Com_SendSignalGroup TMS Preparation. \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignalGroup internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To   Com-CDD-TxHandler-0022(0),
                Com-CDD-TxHandler-0322(0),
                Com-CDD-TxHandler-0025(0),
                Com-CDD-TxHandler-0509(0),
				Com-CDD-5748(1), Com-CDD-5545(1), Com-CDD-5547(1) */
static FUNC(void, COM_CODE) vidPrepSendSigGrpTMS(
            P2CONST(tstrSendSignalData,
                  AUTOMATIC, TYPEDEF) pkudtSendSignalData)
{
/* PRQA S 3206 -- */
#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
  P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,TYPEDEF)pkstrSigGrpB;
  
  VAR(boolean, AUTOMATIC)       bFilterResult;
  VAR(boolean, AUTOMATIC)       bNewFilterResult;
  VAR(boolean, AUTOMATIC)       bOldFilterResult;
  
  VAR(uint16, AUTOMATIC)        u16NoOfGroupSig;
  VAR(uint16, AUTOMATIC)        u16CurrFirstGSigIx;
  VAR(uint16, AUTOMATIC)        u16CurrGrSigIx;
  
  VAR(uint16_least, AUTOMATIC)        u16GroupSigLoopIndex;
  VAR(Com_SignalIdType, AUTOMATIC)
                                u16CurrGSigId;
  P2CONST(void, AUTOMATIC, COM_MAX_CALIB_APPL_CFGCONST)
                                pkvidGroupSigShadowPtr;
  pkstrSigGrpB = pkstrGET_PB_SIGGRP_PTR(pkudtSendSignalData->u16SSLCurrentSigIx);
  /*! get the number of group signals in the signal group*/
  u16NoOfGroupSig = pkstrSigGrpB->u16NoOfGroupSignals;


  /*! get the index of the first group signal in the signal group*/
	u16CurrFirstGSigIx = pkstrSigGrpB->u16GroupSignalIndex;
	u16CurrGSigId = Com_akstreGroupSignalLT[u16CurrFirstGSigIx].u16SignalId;
	
	#if Com_u16NO_OF_SIGNAL_STATUS > 0u
    bOldFilterResult = (boolean)((Com_audteSignalStatus[u16CurrGSigId] & Com_u8LASTFILTER_RES) != (boolean)FALSE);
	#endif
	
  /*! handle TM switch if happened */
    bNewFilterResult = FALSE;
	
	/*! Loop on all group signals inside this signal group and apply filter on every 
		one then saving the new fiter result in the first group signal status byte*/
  for(u16GroupSigLoopIndex = 0;
      u16GroupSigLoopIndex < u16NoOfGroupSig;
      u16GroupSigLoopIndex++)
  {
    /*! check if this group signal has configured filter */
	if((Com_akstreGroupSignalLT[u16CurrFirstGSigIx + u16GroupSigLoopIndex].
                               u16FilterIndex) != (uint16)0xFFFFu)
    {
      /*! Get group signals ID */
      /*u16CurrGSigId = u16GET_G_SIG_ID(u16CurrFirstGSigIx +
                                      u16GroupSigLoopIndex);*/
      
	  u16CurrGrSigIx = u16CurrFirstGSigIx + u16GroupSigLoopIndex;
	  /*! Get source group signals shadow buffer pointer  */
      pkvidGroupSigShadowPtr = Com_pvidGetGSigShadowPtr(u16CurrGrSigIx);
      bFilterResult =
              Com_bSignalApplyFilter(u16CurrGrSigIx, pkvidGroupSigShadowPtr,
			  Com_u8SIG_STRUCT_GROUPSIG);
	  
	  /*! ORing all Group Signals Results and store last value in NewFilterResult*/
	  
	  bNewFilterResult |= bFilterResult;
	 
    }
  }
  
    /*! Save the Signal group Filter result in the first group signal status Byte*/
	if (bOldFilterResult != bNewFilterResult)
	{
		u16CurrGSigId = u16GET_G_SIG_ID(u16CurrFirstGSigIx);
		#if Com_u16NO_OF_SIGNAL_STATUS > 0u
		Com_audteSignalStatus[u16CurrGSigId] ^= Com_u8NEW_FILTER_RESULT;
		#endif
		
	}
#endif
}
#endif

#if ((Com_bTMS_SUPPORT == STD_ON) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
/******************************************************************************/
/*! \Description This function handles Com_SendSignalGroup Preparation. \n
                 This function is added to reduce code complexity.
  \param[in]   pkudtSendSignalData  Pointer to Com_SendSignalGroup internal \n
               variables structure
  \param[in]   SignalGroupId  signal Group Handle ID passed to Com_SendSignal
  \return      void
*******************************************************************************/
/*! \Trace_To   Com-CDD-TxHandler-0025(0),
                Com-CDD-TxHandler-0509(0),
                Com-CDD-TxHandler-5727(0) */
static FUNC(void, COM_CODE) vidPrepSendSignalGroup(
            VAR(Com_SignalGroupIdType, AUTOMATIC)  u16SignalGroupId,
            P2VAR(tstrSendSignalData, AUTOMATIC, COM_VAR) pkudtSendSignalData)
{

  VAR(uint8,AUTOMATIC) 				u8CurrentTxProperty;
  pkudtSendSignalData->bSupressCancelTx = FALSE;

  /*! Get the current TxMode TRUE or FALSE*/
   u8CurrentTxProperty = u8SIGG_GET_TX_PROP(pkudtSendSignalData->u16SSLCurrentSigIx);
   
   if(u8CurrentTxProperty == Com_u8TXPROP_TRIGGERED)
	{
		pkudtSendSignalData->u8SSLCurrentTxProperty = Com_u8TXPROP_TRIGGERED;
	}
	else if((u8CurrentTxProperty == Com_u8TXPROP_TRIG_CHANGE) && (pkudtSendSignalData->u8SSLCurrentTxProperty != Com_u8TXPROP_TRIGGERED))
	{
		pkudtSendSignalData->u8SSLCurrentTxProperty = Com_u8TXPROP_TRIG_CHANGE;
		if(pkudtSendSignalData->bSSLSignalIsChanged == FALSE)
		{
			pkudtSendSignalData->bSSLSignalIsChanged = Com_bSignalGroupIsChanged(u16SignalGroupId);
		}
	}
	else
	{
	}
   vidPrepSendSigGrpTMS(pkudtSendSignalData);

} /* vidPrepSendSignalGroup */

#endif
/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
Partitioning this function shall not pay for the negative effect of context
switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description The service Com_SendSignalGroup copies the content of the \n
                 associated shadow buffer to the associated I-PDU.
    \param[in]  SignalGroupId Id of signal group to be sent.
*******************************************************************************/
/*! \Trace_To Com-CDD-TxHandler-0116(0),
              Com-CDD-TxHandler-0418(0),
              Com-CDD-TxHandler-0419(0),
              Com-CDD-TxHandler-0420(0),
              Com-CDD-TxHandler-0014(0),
              Com-CDD-TxHandler-0321(0),
              Com-CDD-TxHandler-0062(0),
              Com-CDD-TxHandler-0340(0),
              Com-CDD-0215(0),
              Com-CDD-TxHandler-5712(0),
              Com-CDD-TxHandler-5738(0),			 
			  Com-CDD-5746(0), Com-CDD-5744(1),
              Com-CDD-0497(0),
			  Com-CDD-5748(1), Com-CDD-5546(1) */
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
FUNC(uint8, COM_CODE) Com_SendSignalGroup(
                          VAR(Com_SignalGroupIdType, AUTOMATIC) SignalGroupId )

{
  /*! Local variables */
  VAR(boolean, AUTOMATIC)            bIPduWaitForConf;

  VAR(tstrSendSignalData, AUTOMATIC) strSendSignalData;
  P2VAR(PduIdType, AUTOMATIC,AUTOMATIC)pu16SSLCrntIPduId;
  P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,TYPEDEF) pkstrLocSigGroPB;
  VAR(uint16, AUTOMATIC)   u16GroupSignalId;
#if (Com_bUBIT_SUPPORT == STD_ON)
  VAR(uint16, AUTOMATIC)				u16UpdBitPos;
#endif

#if (Com_bTX_INACTIVE_ERROR == STD_ON)
 VAR(Com_tpfvidSigTxErrorNotif, AUTOMATIC)	pudtSigGroupTxErrorNotif;
#endif


  strSendSignalData.u8SSLReturnValue     = E_OK;

  /*strSendSignalData.bSSLSendIPdu = FALSE;*/



  /*! DET check and reporting */
  /* Com-CDD-TxHandler-0418(0) */
  if (Com_enueStatus == COM_UNINIT)
  {
#if (COM_DEV_ERROR_DETECT == STD_ON)
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_SendSignalGroup , COM_E_UNINIT);
/* PRQA S 3212 -- */
#endif /*COM_DEV_ERROR_DETECT*/
    strSendSignalData.u8SSLReturnValue = COM_SERVICE_NOT_AVAILABLE;
  }
  else
  {

    /* Com-CDD-TxHandler-0419(0) */
    if (SignalGroupId > Com_u16SIGNALGROUPIDMAX)
    {
#if (COM_DEV_ERROR_DETECT == STD_ON)
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
      (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                      COMServiceId_SendSignalGroup , COM_E_PARAM);
/* PRQA S 3212 -- */
#endif /*COM_DEV_ERROR_DETECT*/
      strSendSignalData.u8SSLReturnValue = COM_SERVICE_NOT_AVAILABLE;
    }
    else
    {
      /*! signal group index = SignalGroupId because no config containers \n
      share the same ID space with it */
      strSendSignalData.u16SSLCurrentSigIx = SignalGroupId;
      /*! get signal group direction */
      strSendSignalData.u8SSLCurrentSigDir =
                            u8SIGG_GET_DIR(strSendSignalData.u16SSLCurrentSigIx);
      /* Com-CDD-TxHandler-0419(0) */
      if (strSendSignalData.u8SSLCurrentSigDir != Com_u8SIG_DIR_SEND)
      {
#if (COM_DEV_ERROR_DETECT == STD_ON)
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                        COMServiceId_SendSignalGroup , COM_E_PARAM);
/* PRQA S 3212 -- */
#endif /*COM_DEV_ERROR_DETECT*/
        strSendSignalData.u8SSLReturnValue = COM_SERVICE_NOT_AVAILABLE;
      }
      /* Com-CDD-TxHandler-0407(0) */
      else
      {

      }
    }
  }
 #if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
  /* if no error */
  if(strSendSignalData.u8SSLReturnValue == E_OK)
  {
    /*! signal group index = SignalGroupId because no config containers \n
    share the same ID space with it */
    strSendSignalData.u16SSLCurrentSigIx = SignalGroupId;
	pkstrLocSigGroPB = pkstrGET_PB_SIGGRP_PTR(SignalGroupId);
    strSendSignalData.u16SSLCurrentIPduId  = pkstrLocSigGroPB->u16IPduIndex;
    strSendSignalData.u16SSLCurrentIPduIx  =
                        u16IPDU_GET_IX(strSendSignalData.u16SSLCurrentIPduId);
  
	pu16SSLCrntIPduId = &(strSendSignalData.u16SSLCurrentIPduId);

	#if u16NO_OF_IPDUS_STATUS > 0u
   SchM_Enter_Com_IPduStatus_0D();
	bIPduWaitForConf = Com_audteIPduStatus[*pu16SSLCrntIPduId] & Com_u8WAIT_CONF;
   SchM_Exit_Com_IPduStatus_0D();
	#endif
	
	
    /*! If IPdu buffer is not locked, handle request normally */
    /* Com-CDD-TxHandler-5712(0) */
    if(!((u8TXIPDU_GET_TYPE(strSendSignalData.u16SSLCurrentIPduIx) ==
                                                      Com_u8IPDU_TYPE_TP) &&
       (bIPduWaitForConf != FALSE)))
    {
	  
   strSendSignalData.u8SSLCurrentTxProperty =
                    u8SIGG_GET_TX_PROP(strSendSignalData.u16SSLCurrentSigIx);

#if (Com_bTMS_SUPPORT == STD_ON)
  if(strSendSignalData.u8SSLCurrentTxProperty == Com_u8TXPROP_TRIG_CHANGE)
  {
    strSendSignalData.bSSLSignalIsChanged =
                            Com_bSignalGroupIsChanged(SignalGroupId);
  }
  else
  {
    strSendSignalData.bSSLSignalIsChanged  = TRUE;
  }
#else

	if(strSendSignalData.u8SSLCurrentTxProperty == Com_u8TXPROP_TRIGGERED )
	{
		strSendSignalData.bSSLSignalIsChanged = TRUE;
	}
	else if(strSendSignalData.u8SSLCurrentTxProperty == Com_u8TXPROP_TRIG_CHANGE)
    {
		strSendSignalData.bSSLSignalIsChanged =
                            Com_bSignalGroupIsChanged(SignalGroupId);
    }
    else
    {
       strSendSignalData.bSSLSignalIsChanged  = FALSE;
    }
#endif

 
	  
	 if(strSendSignalData.bSSLSignalIsChanged == TRUE)
	 {
	 
#if (Com_bTMS_SUPPORT == STD_ON)
	  /*! use first Group signal Byte flags to indicate Signal Group will used to evaluate TMS */
	  pkstrLocSigGroPB = pkstrGET_PB_SIGGRP_PTR(SignalGroupId);
	  u16GroupSignalId = Com_akstreGroupSignalLT[pkstrLocSigGroPB->u16GroupSignalIndex].u16SignalId;
	  
	  #if Com_u16NO_OF_SIGNAL_STATUS > 0u
	 SchM_Enter_Com_SignalStatus_0A();
	  Com_audteSignalStatus[u16GroupSignalId] |= Com_u8SS_TMS_REQ;
	 SchM_Exit_Com_SignalStatus_0A(); 	 
	  #endif
	  
#endif

	/*! Add for optimization, in case we need to close features that will enable and disable sending the IPDU contains
	this signal we need flag to check sending that ipdu or not also we will use this flag in Com_MainFunctionTx to 
	avoid processing of all IPDU */
	 #if u16NO_OF_IPDUS_STATUS > 0u
	SchM_Enter_Com_IPduStatus_0D();
	 Com_audteIPduStatus[*pu16SSLCrntIPduId] |= Com_u8SENDSIGNAL_RQ;
	SchM_Exit_Com_IPduStatus_0D();
	 #endif
	 
	}
	else
	{
	
	}

      /* Com-CDD-TxHandler-5720(0) */
      /*! Pack the signal group in the I-PDU buffer */
      vidPackSignalGroup(strSendSignalData.u16SSLCurrentSigIx);

	/*Moved from vidPrepSendSignalGroup*/	  
#if (Com_bUBIT_SUPPORT == STD_ON)
  /*! check if the signal has ubdate-bit configured*/

  u16UpdBitPos = u16GET_SIG_GRP_UPDAT_BT(SignalGroupId);
  if(u16UpdBitPos != (uint16)0xFFFFu)
  {
    /*! Set update bit */
    Com_vidSignalEditUpdateBit(Com_u8SIGNALGROUP,
                               strSendSignalData.u16SSLCurrentSigIx, u16UpdBitPos,TRUE);
  }
  else
  {

  }
#endif
    }
    else
    {
      strSendSignalData.u8SSLReturnValue = COM_BUSY;
    }
	
 /*This Part Moved from vidPrepSendSignalGroup to here*/
	SchM_Enter_Com_IPduStatus_0D();
  strSendSignalData.bSSLIPduState =
                  Com_bIpduCheckActive(strSendSignalData.u16SSLCurrentIPduId);
	SchM_Exit_Com_IPduStatus_0D();

#if (Com_bTX_INACTIVE_ERROR == STD_ON)
  if(strSendSignalData.bSSLIPduState == FALSE)
  {
#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
    /*! check if the signal group has ComErrorNotification
    configured*/
	pudtSigGroupTxErrorNotif = Com_akstreSignalGroupLT[strSendSignalData.u16SSLCurrentSigIx].
									pfvidComErrorNotification;
    if(pudtSigGroupTxErrorNotif != NULL_PTR)
    {
      /* Com-CDD-TxHandler-5727(0) */
      /*! call ComErrorNotification*/
      (*pudtSigGroupTxErrorNotif)();
    }
#endif
  }
#endif
  }
 #endif
  return strSendSignalData.u8SSLReturnValue;
} /* Com_SendSignalGroup() */
#endif /*Com_bSIGNAL_GROUP_SUPPORT*/
/* PRQA S 4700 -- */

/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
This function deviates in STSUB = 14. Partitioning this function shall not
pay for the negative effect of context switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description This function handles Com_MainFunctionTx processing in case: \n
                  IPDU state = Active \n
                  TxMode = MIXED \n
                 This function is added to reduce code complexity.
  \param[in]   pstrMainFunctionTxData  Pointer to Com_MainFunctionTx internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To   Com-CDD-TxHandler-0276(0), \n
                Com-CDD-TxHandler-0279(0),
                Com-CDD-TxHandler-0280(0),
                Com-CDD-TxHandler-0281(0),
				Com-CDD-5746(0), Com-CDD-5370(1)*/
static FUNC(void, COM_CODE) vidActiveIPduHandleM(
                          P2VAR(tstrMainFunctionTxData,
                                AUTOMATIC, COM_VAR)
                                                        pstrMainFunctionTxData)
{
  P2VAR(Com_tu32TxModeTimer,AUTOMATIC,TYPEDEF)pu32TxModeTimerPtr;
  P2CONST(Com_tstrTxModeMixed,AUTOMATIC,TYPEDEF)pkstrTxModeMixedPtr;
  P2VAR(uint16, AUTOMATIC,AUTOMATIC)pu16MTLCrntTxModeIx;
  P2VAR(PduIdType, AUTOMATIC,AUTOMATIC)pu16MTLCrntIPduId;
  VAR(boolean, AUTOMATIC)  			   bRepetitionMixedMode = FALSE;

  pu32TxModeTimerPtr = pku32GET_TX_MODE_TIMER(0);
  pu16MTLCrntTxModeIx = &(pstrMainFunctionTxData->u16MTLCurrentTxModeIx);
  pu16MTLCrntIPduId = &(pstrMainFunctionTxData->u16MTLCurrentIPduId);
  pkstrTxModeMixedPtr = u8MIXTXMODE_GET_PTR(*pu16MTLCrntTxModeIx);
  
#if (Com_bNTIMES_SUPPORT == STD_ON) 
  /* Direct part handling */
  pstrMainFunctionTxData->u8MTLCurrentNoOfRep = pkstrTxModeMixedPtr->u8NumberOfRepetitions;
  pstrMainFunctionTxData->u8MTLCurrentRepCtr = u8TXMODE_GET_REPCTR(pkstrTxModeMixedPtr->u16RepetitionsCtrIndex);

 
  pstrMainFunctionTxData->u32MTLCurrentRepPrdTmr =
        pu32TxModeTimerPtr[pkstrTxModeMixedPtr->u16RepetitionPrdTmrIx];
 

  /* Com-CDD-TxHandler-0276(0) */
  if(pstrMainFunctionTxData->u8MTLCurrentNoOfRep > (uint8) 0)
  {
    if(pstrMainFunctionTxData->u8MTLCurrentRepCtr > (uint8) 0)
    {
	  bRepetitionMixedMode = TRUE;
      if(pstrMainFunctionTxData->u32MTLCurrentRepPrdTmr == (uint32) 0)
      {
	    bRepetitionMixedMode = FALSE;
	    /*!Reload periodic mode period timer*/
		pku32RLD_PERIODIC_MOD_TMR(pkstrTxModeMixedPtr);
		if(pstrMainFunctionTxData->bMTLElapsedMDT == TRUE)
		{
			/*! mark Ipdu to be sent*/
          pstrMainFunctionTxData->bMTLSendIPdu = TRUE;
		  #if u16NO_OF_IPDUS_STATUS > 0u
		 SchM_Enter_Com_IPduStatus_19();
		  Com_audteIPduStatus[*pu16MTLCrntIPduId] |= Com_u8WAIT_CONF; 
		 SchM_Exit_Com_IPduStatus_19();
		  #endif
		  
		 
/*Add this two brackets for reqtify issu as it cover code as static*/		
		}
        else /* pstrMainFunctionTxData->bMTLElapsedMDT == FALSE */
        {
          /* Do nothing */
        }    
	  }
      else /* pstrMainFunctionTxData->u32MTLCurrentRepPrdTmr > (uint32) 0 */
      {
        /* Decrement Repetition period timer only if this I-PDU is not
        delayed because of MDT. This enables Direct Mode/Direct Part to start
        sending with correct timing after MDT has elapsed */
        if(pstrMainFunctionTxData->bMTLDelayedMDT == FALSE)
        {
         
          (pu32TxModeTimerPtr[pkstrTxModeMixedPtr->u16RepetitionPrdTmrIx ]) = 
          (pu32TxModeTimerPtr[pkstrTxModeMixedPtr->u16RepetitionPrdTmrIx ]) - (uint32)1;
         
        }
        else
        {

        }
      }


    }
    else /* pstrMainFunctionTxData->u8MTLCurrentRepCtr == (uint8) 0 */
    {
      /* Do nothing */
    }
		
  }
  else /* pstrMainFunctionTxData->u8MTLCurrentNoOfRep == (uint8) 0 */
  {
    /* Do nothing */
  }
#endif

 
  /* Periodic part handling */
  pstrMainFunctionTxData->u32MTLCurrentPrdTmr =
        pu32TxModeTimerPtr[pkstrTxModeMixedPtr->u16TimerIndex];
 

  if(pstrMainFunctionTxData->u32MTLCurrentPrdTmr == (uint32)0)
  {
   
    /*! If TX I-PDU has current TxMode PERIODIC or MIXED and Time Period \n
     Timer equals zero, reload Time Period Timer by the value of \n
     ComTxModeTimePeriod */
    /* Com-CDD-TxHandler-0279(0) */
    pu32TxModeTimerPtr[pkstrTxModeMixedPtr->u16TimerIndex ] = 
    pkstrTxModeMixedPtr->u32TimePeriod - (uint32)1;
   
#if (Com_bMDT_SUPPORT == STD_ON)
    if(pstrMainFunctionTxData->bMTLElapsedMDT == TRUE)
    {
#endif
      /*! If TX I-PDU has current TxMode PERIODIC or MIXED and Time Period \n
      Timer equals zero and MDT time has elapsed, mark it for transmission */
      /* Com-CDD-TxHandler-0280(0) */
      pstrMainFunctionTxData->bMTLSendIPdu = TRUE;  
	  
	  /*! Fixing bug #06036 for Decrement N times transmission when transmit the periodic one*/
		if(bRepetitionMixedMode != FALSE)
		{
			/*! reload repetition timer again to drop the next N-Times transmission and consider the current one is one of N-times */
			pku32RLD_PERIODIC_MOD_TMR(pkstrTxModeMixedPtr);
		}
	  
#if (Com_bMDT_SUPPORT == STD_ON)      
	}
    else /* pstrMainFunctionTxData->bMTLElapsedMDT == FALSE */
    {
      /*! if and MDTimer doesnt equal zero. Instead it shall set the I-PDU \n
       ComTxDelayedMDT flag. */
      /* Com-CDD-TxHandler-0281(0) */
      pstrMainFunctionTxData->bMTLSendIPdu = FALSE;
	  /*#if u16NO_OF_IPDUS_STATUS > 0u
	  Com_audteIPduStatus[*pu16MTLCrntIPduId] |= (Com_udtIPduStatus)Com_u8D_MDT_MASK; 
	  #endif*/
	  pstrMainFunctionTxData->bIPduMDTMask = TRUE;
	  
    }
#endif
  }
  else /* pstrMainFunctionTxData->u32MTLCurrentPrdTmr > (uint32)0 */
  {
   
    pu32TxModeTimerPtr[pkstrTxModeMixedPtr->u16TimerIndex] =
    pu32TxModeTimerPtr[pkstrTxModeMixedPtr->u16TimerIndex] - (uint32)1;
   
  }
}
/* PRQA S 4700 -- */

/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
Partitioning this function shall not pay for the negative effect of context
switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description This function handles Com_MainFunctionTx processing in case: \n
                  IPDU state = Active && \n
                  TxMode = PERIODIC \n
                 This function is added to reduce code complexity.
  \param[in]   pstrMainFunctionTxData  Pointer to Com_MainFunctionTx internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To   Com-CDD-TxHandler-0279(0), \n
                Com-CDD-TxHandler-0280(0),
                Com-CDD-TxHandler-0281(0) */
static FUNC(void, COM_CODE) vidActiveIPduHandleP(
    P2VAR(tstrMainFunctionTxData, AUTOMATIC, COM_VAR)
                                                 pstrMainFunctionTxData)
{
  P2VAR(Com_tu32TxModeTimer,AUTOMATIC,TYPEDEF)pu32TxModeTimerPtr;
  P2CONST(Com_tstrTxModePeriodic,AUTOMATIC,TYPEDEF)pkstrTxModPridc;
  P2VAR(uint16, AUTOMATIC,AUTOMATIC) pu16MTLCrntTxModeIx;
  P2VAR(PduIdType, AUTOMATIC,AUTOMATIC)pu16MTLCrntIPduId;

  pu16MTLCrntTxModeIx = &(pstrMainFunctionTxData->u16MTLCurrentTxModeIx);
  pu16MTLCrntIPduId = &(pstrMainFunctionTxData->u16MTLCurrentIPduId);
		  
  pkstrTxModPridc = u8PERTXMODE_GET_PTR(*pu16MTLCrntTxModeIx); 
  pu32TxModeTimerPtr = pku32GET_TX_MODE_TIMER(pkstrTxModPridc->u16TimerIndex);
  
 
  pstrMainFunctionTxData->u32MTLCurrentPrdTmr = *pu32TxModeTimerPtr;
 

  if(pstrMainFunctionTxData->u32MTLCurrentPrdTmr == (uint32)0)
  {
   
    /*! If TX I-PDU has current TxMode PERIODIC or MIXED and Time Period \n
     Timer equals zero, reload Time Period Timer by the value of \n
     ComTxModeTimePeriod */
    /* Com-CDD-TxHandler-0279(0) */
    *pu32TxModeTimerPtr = pkstrTxModPridc->u32TimePeriod- (uint32)1;
   
#if (Com_bMDT_SUPPORT == STD_ON)
    if(pstrMainFunctionTxData->bMTLElapsedMDT == TRUE)
    {
      /*! If TX I-PDU has current TxMode PERIODIC or MIXED and Time Period \n
      Timer equals zero and MDT time has elapsed, mark it for transmission */
      /* Com-CDD-TxHandler-0280(0) */
      pstrMainFunctionTxData->bMTLSendIPdu = TRUE;
	  #if u16NO_OF_IPDUS_STATUS > 0u
	 SchM_Enter_Com_IPduStatus_19();
	  Com_audteIPduStatus[*pu16MTLCrntIPduId] |= Com_u8WAIT_CONF; 
	 SchM_Exit_Com_IPduStatus_19();
	  #endif
	  
    }
    else /* pstrMainFunctionTxData->bMTLElapsedMDT == FALSE */
    {
    /* Do nothing */
    }
#else
  pstrMainFunctionTxData->bMTLSendIPdu = TRUE;
#endif
  }
  else /* pstrMainFunctionTxData->u32MTLCurrentPrdTmr > (uint32)0 */
  {
   
    *pu32TxModeTimerPtr =
          *pu32TxModeTimerPtr - (uint32) 1;
   
  }
}
/* PRQA S 4700 -- */
/******************************************************************************/
/*! \Description This function handles Com_MainFunctionTx processing in case: \n
                  IPDU state = Active && \n
                  TxMode = DIRECT \n
                 This function is added to reduce code complexity.
  \param[in]   pstrMainFunctionTxData  Pointer to Com_MainFunctionTx internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To   Com-CDD-TxHandler-0276(0),
                Com-CDD-TxHandler-0281(0) */
static FUNC(void, COM_CODE) vidActiveIPduHandleD(
    P2VAR(tstrMainFunctionTxData, AUTOMATIC, COM_VAR)
                                                 pstrMainFunctionTxData)
{
  P2VAR(Com_tu32TxModeTimer,AUTOMATIC,TYPEDEF)pu32TxModeTimerPtr;
  P2CONST(Com_tstrTxModeDirect,AUTOMATIC,TYPEDEF)pkstrTxModDrct;
  P2VAR(uint16, AUTOMATIC,AUTOMATIC) pu16MTLCrntTxModeIx;

  pu16MTLCrntTxModeIx = &(pstrMainFunctionTxData->u16MTLCurrentTxModeIx);
  pkstrTxModDrct = u8DIRTXMODE_GET_PTR(*pu16MTLCrntTxModeIx);
  pu32TxModeTimerPtr = pku32GET_TX_MODE_TIMER(0);

#if (Com_bNTIMES_SUPPORT == STD_ON)
  /*! Getting Repititation Counter proerites*/
  pstrMainFunctionTxData->u8MTLCurrentNoOfRep = pkstrTxModDrct->u8NumberOfRepetitions;
  pstrMainFunctionTxData->u8MTLCurrentRepCtr = u8TXMODE_GET_REPCTR(pkstrTxModDrct->u16RepetitionsCtrIndex);

 
  pstrMainFunctionTxData->u32MTLCurrentRepPrdTmr =
        pu32TxModeTimerPtr[pkstrTxModDrct->u16RepetitionPrdTmrIx];
 
  /* Com-CDD-TxHandler-0276(0) */
  if(pstrMainFunctionTxData->u8MTLCurrentNoOfRep > (uint8) 0)
  {
    if(pstrMainFunctionTxData->u8MTLCurrentRepCtr > (uint8) 0)
    {
      if(pstrMainFunctionTxData->u32MTLCurrentRepPrdTmr == (uint32) 0)
      { /*! Reload repetition period if it reached zero and repetition \n
        counter is not zero */
        pku32RLD_PERIODIC_MOD_TMR(pkstrTxModDrct);
       
		/*! in case of TMS is OFF will chech MDT is elapsed only*/
		if(pstrMainFunctionTxData->bMTLElapsedMDT == TRUE)
        {		
			/*! Mark IPDu to send*/
			pstrMainFunctionTxData->bMTLSendIPdu = TRUE;
		}
        else /* pstrMainFunctionTxData->bMTLElapsedMDT == FALSE */
        {
          /* Do nothing */
        }    
	  }
      else /* pstrMainFunctionTxData->u32MTLCurrentRepPrdTmr > (uint32) 0 */
      {
        /* Decrement Repitition period timer only if this I-PDU is not
        delayed because of MDT. This enables Direct Mode/Direct Part to start
        sending with correct timing after MDT has elapsed */
        if(pstrMainFunctionTxData->bMTLDelayedMDT == FALSE)
        {
         
          pu32TxModeTimerPtr[pkstrTxModDrct->u16RepetitionPrdTmrIx] =
			pu32TxModeTimerPtr[pkstrTxModDrct->u16RepetitionPrdTmrIx] - (uint32)1;
         
        }
        else
        {

        }
      }
    }
    else /* pstrMainFunctionTxData->u8MTLCurrentRepCtr == (uint8) 0 */
    {
      /* Do nothing */
    }
  }
  else /* pstrMainFunctionTxData->u8MTLCurrentNoOfRep == (uint8) 0 */
  {
    /* Do nothing */
  }
#endif
}

/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
This function deviates in STCYC = 14. Partitioning this function shall not
pay for the negative effect of context switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description This function handles Com_MainFunctionTx processing for \n
                  deadline monitoring \n
                 This function is added to reduce code complexity.
  \param[in]   pstrMainFunctionTxData  Pointer to Com_MainFunctionTx internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To     Com-CDD-TxHandler-5698(0),
                  Com-CDD-TxHandler-5703(0),
                  Com-CDD-TxHandler-5697(0),
                  Com-CDD-TxHandler-5701(0),
                  Com-CDD-TxHandler-5688(0),
                  Com-CDD-TxHandler-5689(0),
                  Com-CDD-TxHandler-5690(0),
                  Com-CDD-TxHandler-5692(0),
                  Com-CDD-0272(0),
				  Com-CDD-5747(1), Com-CDD-5545(0) */
static FUNC(void, COM_CODE) vidActiveIPduHandleTO(
    P2VAR(tstrMainFunctionTxData, AUTOMATIC, COM_VAR)
                                                  pstrMainFunctionTxData)
{

  VAR(uint8, AUTOMATIC)        bCancelTxSupported;
  VAR(uint8, AUTOMATIC)        u8CurrTxModeTrueType;
  P2VAR(uint32,AUTOMATIC,AUTOMATIC) pu32TOutT;
  P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF)pkstrTxIPduPtr;
  P2VAR(uint16, AUTOMATIC,AUTOMATIC) pu16MTLCrntIPduIdx;
  P2VAR(PduIdType, AUTOMATIC,AUTOMATIC)pu16MTLCrntIPduId;
  VAR(uint16, AUTOMATIC)	  u16TxTOTimerIx;
  P2CONST(Com_tstrTxMode,AUTOMATIC,TYPEDEF) pkstrTxModePtr;
	
	
  pu16MTLCrntIPduIdx = &(pstrMainFunctionTxData->u16MTLCurrentIPduIndex);
  pu16MTLCrntIPduId = &(pstrMainFunctionTxData->u16MTLCurrentIPduId);
  
  pu32TOutT = pkstrGET_PB_TIMEOUT_TIMER(0);
  pkstrTxIPduPtr = pkstrGET_TX_IPDU_PTR(*pu16MTLCrntIPduIdx);
  /* Com-CDD-TxHandler-5692(0) */
	u16TxTOTimerIx = pkstrTxIPduPtr->u16TOTimerIndex;
	if((u16TxTOTimerIx != (uint16)0xFFFFu)
	 && (!((bTX_IPDU_GET_TMS_FLAG(pkstrTxIPduPtr) == TRUE) &&
         (pstrMainFunctionTxData->u8MTLCurrentTxModeType == (uint8) Com_u8TX_MODE_NONE))))
  {
   SchM_Enter_Com_TimeoutTimer();
    if(pu32TOutT[u16TxTOTimerIx] > (uint32)0)
    {
      
      /*! Decrement timeout timer for sent I-PDU*/
      
      /* Com-CDD-TxHandler-5698(0) */
      pu32TOutT[u16TxTOTimerIx] =
    pu32TOutT[u16TxTOTimerIx] - (uint32) 1;
      
      /*! If timeout occurs */
    
      if(pu32TOutT[u16TxTOTimerIx] == (uint32)0)
      {
       SchM_Exit_Com_TimeoutTimer();
	    pkstrTxModePtr = u8IPDU_GET_TXMODE_PTR(pkstrTxIPduPtr->u16TxModeTrueIndex);
        u8CurrTxModeTrueType = pkstrTxModePtr->u8TxMode;
        /* In case transmission deadline monitoring is configured for an
        I-PDU with transmission mode NONE only, Reload timeout timer */
        if((bTX_IPDU_GET_TMS_FLAG(pkstrTxIPduPtr) == FALSE)    &&
           (u8CurrTxModeTrueType == (uint8) Com_u8TX_MODE_NONE))
        {
         SchM_Enter_Com_TimeoutTimer();
          pu32TOutT[u16TxTOTimerIx] = pkstrTxIPduPtr->u32Timeout;
         SchM_Exit_Com_TimeoutTimer();
		  
		 #if u16NO_OF_IPDUS_STATUS > 0u
		SchM_Enter_Com_IPduStatus_19();
		 Com_audteIPduStatus[(*pu16MTLCrntIPduId)] |= Com_u8WAIT_CONF; 	/*Set WaitFlags to TRUE*/
		SchM_Exit_Com_IPduStatus_19();
		 #endif
        }
        else
        {
	    /* !Deviation: [0277]  ( An Integer Constant experssion with negative value is being converted to an unsigned type)  */
	    /*PRQA S 0277 ++ */
		  #if u16NO_OF_IPDUS_STATUS > 0u
		 SchM_Enter_Com_IPduStatus_19();
		  Com_audteIPduStatus[(*pu16MTLCrntIPduId)] &= (Com_udtIPduStatus)(~Com_u8WAIT_CONF); 	/*Set WaitFlags to FALSE*/
		 SchM_Exit_Com_IPduStatus_19();
		  #endif
		  
	    /*PRQA S 0277 -- */
        }
		#if u16NO_OF_IPDUS_STATUS > 0u
		bCancelTxSupported = udtGET_PB_INIT_IPDUSTATUS(pstrMainFunctionTxData->u16MTLCurrentIPduId) & (Com_u8CNCL_TXSPP_FLG);
		#endif
	
#if (Com_bPDUR_CANCEL_TRANSMIT_SUPPORT == STD_ON)
        if((bCancelTxSupported == TRUE) &&
           (u8TXIPDU_GET_TYPE(pstrMainFunctionTxData->u16MTLCurrentIPduIndex) ==
                                                        Com_u8IPDU_TYPE_NORMAL))
        {
  /* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
  function return value ignoring */
  /* PRQA S 3212 ++ */
          /*! If Com_aku8eCancelTxSupportFlg == TRUE and \n
          bfType == Com_u8IPDU_TYPE_NORMAL, call PduR_ComCancelTransmit for \n
          that I-PDU and ignore the return of it */
          /* Com-CDD-TxHandler-5697(0) */
          (void) PduR_ComCancelTransmit(
                                  pstrMainFunctionTxData->u16MTLCurrentIPduId);
  /* PRQA S 3212 -- */
        }
        else
        {

        }
#endif /*Com_bPDUR_CANCEL_TRANSMIT_SUPPORT*/

        /*! For DIRECT and MIXED TxMode if a transmission deadline monitoring \n
         timeout occurs before the N-Times transmission is complete, reset \n
         au8TxModeRepetitionsCtr for the I-PDU. This shall stop sending \n
         N-Times. */
        /* Com-CDD-TxHandler-5701(0) */
        if((pstrMainFunctionTxData->u8MTLCurrentTxModeType ==
                                                      (uint8) Com_u8TX_MODE_MIXED)
           ||
           (pstrMainFunctionTxData->u8MTLCurrentTxModeType ==
                                                    (uint8) Com_u8TX_MODE_DIRECT))
        {
          if(pstrMainFunctionTxData->u8MTLCurrentNoOfRep > (uint8) 0)
          {
            if(pstrMainFunctionTxData->u8MTLCurrentRepCtr > (uint8) 0)
            {
              switch(pstrMainFunctionTxData->u8MTLCurrentTxModeType)
              {
                case Com_u8TX_MODE_MIXED:
                u8MIXTXMODE_CLR_REPCTR(pstrMainFunctionTxData->u16MTLCurrentTxModeIx);
                break;
                case Com_u8TX_MODE_DIRECT:
                u8DIRTXMODE_CLR_REPCTR(pstrMainFunctionTxData->u16MTLCurrentTxModeIx);
                break;
                default:
                break;
              }

            }
          }
        }

		 /*! Add IPDU timeout Notification for optimization to avoid access Signal/Signal group structure
		   and get pointer to every timeout notifications*/
		if(pkstrTxIPduPtr->pfvidIPduTimeOutNotifPtr != NULL_PTR)
		{
			(*pkstrTxIPduPtr->pfvidIPduTimeOutNotifPtr)();
		}
      
	  }
      else
      {
			SchM_Exit_Com_TimeoutTimer();
      }
    }
  }
  else
  {

  }
}
/* PRQA S 4700 -- */

/******************************************************************************/
/*! \Description This function handles Com_MainFunctionTx processing for \n
                  IPDUs delayed due to MDT \n
                 This function is added to reduce code complexity.
  \param[in]   pstrMainFunctionTxData  Pointer to Com_MainFunctionTx internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To  Com-CDD-TxHandler-0277(0),
               Com-CDD-TxHandler-0278(0),
			   Com-CDD-5746(0), Com-CDD-5370(1)*/
static FUNC(void, COM_CODE) vidActiveIPduHandleMDT(
    P2VAR(tstrMainFunctionTxData, AUTOMATIC, COM_VAR)
                                                   pstrMainFunctionTxData)
{
  P2VAR(Com_tu32MDTimer,AUTOMATIC,TYPEDEF)pu32MDTimerPtr;
  P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF)pkstrTxIPduPtr;
  P2VAR(uint16, AUTOMATIC,AUTOMATIC)pu16MTLCrntIPduIdx;
  VAR(uint16, AUTOMATIC)  u16MDTimerIx;

  pu32MDTimerPtr = pku32GET_MD_TIMER(0);
  pu16MTLCrntIPduIdx = &(pstrMainFunctionTxData->u16MTLCurrentIPduIndex);
  pkstrTxIPduPtr = pkstrGET_TX_IPDU_PTR(*pu16MTLCrntIPduIdx);
  /* Handling I-PDUs Delayed due to MDT or previous Com_SendSignal call. */
  
  pstrMainFunctionTxData->bMTLDelayedMDT = pstrMainFunctionTxData->bIPduMDTMask;
  
  if(pstrMainFunctionTxData->bMTLDelayedMDT != FALSE)
  {
    if(pstrMainFunctionTxData->bMTLElapsedMDT == TRUE)
    {
      /*! If this I-PDU is delayed for transmission and MDT time elapsed mark \n
       it for transmission */
      /* Com-CDD-TxHandler-0278(0) */
      pstrMainFunctionTxData->bMTLSendIPdu = TRUE;
    }
    else /* pstrMainFunctionTxData->bMTLElapsedMDT == FALSE */
    {

    }
  }
  else /* pstrMainFunctionTxData->bMTLDelayedMDT == FALSE */
  {

  }
  u16MDTimerIx = pkstrTxIPduPtr->u16MDTimerIndex;
  if(u16MDTimerIx != (uint16)0xFFFFu)
  {
    if(pstrMainFunctionTxData->bMTLElapsedMDT == FALSE)
    {
      /* Com-CDD-TxHandler-0277(0) */
     SchM_Enter_Com_MDT();
      /* Fixed bug# 46570*/
      /*! Decrement MDT timer if configured */
      pu32MDTimerPtr[u16MDTimerIx] =
    pu32MDTimerPtr[u16MDTimerIx] - (uint32) 1;
     SchM_Exit_Com_MDT();
    }
    else /* pstrMainFunctionTxData->bMTLElapsedMDT == TRUE */
    {

    }
  }
  else
  {

  }
}

/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
Partitioning this function shall not pay for the negative effect of context
switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description This function handles Com_MainFunctionTx processing in case: \n
                  IPDU Shall be sent \n
                 This function is added to reduce code complexity.
  \param[in]   pstrMainFunctionTxData  Pointer to Com_MainFunctionTx internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To   Com-CDD-TxHandler-0404(0),
                Com-CDD-TxHandler-0059(0),
                Com-CDD-TxHandler-0275(0),
                Com-CDD-TxHandler-0501(0),
                Com-CDD-TxHandler-5702(0),
                Com-CDD-0282(0),
                Com-CDD-0282(0),
                Com-CDD-TxHandler-5735(0),
                Com-CDD-0279(0),
				Com-CDD-5746(0), Com-CDD-5370(1)*/
static FUNC(void, COM_CODE) vidActiveIPduHandleSend(
    P2VAR(tstrMainFunctionTxData, AUTOMATIC, COM_VAR)
                                                    pstrMainFunctionTxData)
{
  P2VAR(PduIdType, AUTOMATIC,AUTOMATIC)pu16MTLCrntIPduId;
  P2VAR(PduInfoType,AUTOMATIC,COM_CALIB_DATA)pstrPduInfoPtr;
  VAR(PduInfoType,AUTOMATIC)   strPduInfo;   
  VAR(uint16,AUTOMATIC)	  u16DynLength;
  VAR(boolean,AUTOMATIC)  bDynamicIPdu;

  VAR(Com_tpfbTxIpduCallout, COM_CFG_CONST)pfbMTLCallout;
  VAR(uint16, AUTOMATIC)     u16IPduCalloutIx;
  VAR(uint16, AUTOMATIC)     u16TxTOTimerIx;

  P2VAR(uint32,AUTOMATIC,AUTOMATIC)pu32TOutT;
  P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF)pkstrTxIPduPtr;
  P2VAR(uint16, AUTOMATIC,AUTOMATIC) pu16MTLCrntIPduIdx;
  P2CONST(Com_tstrTxModeMixed,AUTOMATIC,TYPEDEF) pkstrTxModeMixedPtr;
  P2CONST(Com_tstrTxModeDirect,AUTOMATIC,TYPEDEF)pkstrTxModDrct;

  pu32TOutT = pkstrGET_PB_TIMEOUT_TIMER(0);
  pu16MTLCrntIPduIdx = &(pstrMainFunctionTxData->u16MTLCurrentIPduIndex);
  pu16MTLCrntIPduId = &(pstrMainFunctionTxData->u16MTLCurrentIPduId);
  pkstrTxIPduPtr = pkstrGET_TX_IPDU_PTR(*pu16MTLCrntIPduIdx);

#if (Com_bNTIMES_SUPPORT == STD_ON)
  /*! In case of Direct or Mixed modes reload the repitition period to
  garantee equal time between transmission in case of MDT delay
  Fix Bug 45341*/
  if((pstrMainFunctionTxData->u8MTLCurrentTxModeType ==
                                              (uint8) Com_u8TX_MODE_MIXED)
     &&
     (pstrMainFunctionTxData->u8MTLCurrentRepCtr > (uint8) 1))
  {
    pkstrTxModeMixedPtr =u8MIXTXMODE_GET_PTR(pstrMainFunctionTxData->u16MTLCurrentTxModeIx);
    pku32RLD_PERIODIC_MOD_TMR(pkstrTxModeMixedPtr);
  }
  else if((pstrMainFunctionTxData->u8MTLCurrentTxModeType ==
                                            (uint8) Com_u8TX_MODE_DIRECT)
          &&
          (pstrMainFunctionTxData->u8MTLCurrentRepCtr > (uint8)1))
  {
    pkstrTxModDrct =u8DIRTXMODE_GET_PTR(pstrMainFunctionTxData->u16MTLCurrentTxModeIx);
    pku32RLD_PERIODIC_MOD_TMR(pkstrTxModDrct);
  }
  else
  {

  }
#endif

#if (Com_bTX_CALLOUT_SUPPORT == STD_ON)
																	   
  u16IPduCalloutIx = pkstrTxIPduPtr->u16IPduCalloutIndex;																	   
  if(u16IPduCalloutIx != (uint16)0xFFFFu)
  {
    pstrMainFunctionTxData->pfbMTLCalloutPtr =
    pfTXIPDU_GET_CALOUTPTR(u16IPduCalloutIx);
    pstrMainFunctionTxData->pu8MTLIPduBuffPtr =
     pu8TXIPDU_GET_BUFF_PTR(pkstrTxIPduPtr->u32IPduBufferIndex);
  pstrPduInfoPtr = &strPduInfo; 
  pstrPduInfoPtr->SduDataPtr = pstrMainFunctionTxData->pu8MTLIPduBuffPtr;
#if (Com_bDATA_TP_SUPPORT == STD_ON) 
	bDynamicIPdu = bTPIPduIsDynamic(pstrMainFunctionTxData->u16MTLCurrentIPduId);

	  if (bDynamicIPdu == TRUE)
      {
        u16DynLength = u16GetDynIPduLength(pstrMainFunctionTxData->u16MTLCurrentIPduId);
      }
	  else /*(bDynamicIPdu == FALSE)*/
#endif
      {
        u16DynLength = pkstrTxIPduPtr->u16IPduLength;
      }


  pstrPduInfoPtr->SduLength =  u16DynLength;

  pfbMTLCallout = pstrMainFunctionTxData->pfbMTLCalloutPtr;

   SchM_Enter_Com_IPduBuff();
    /*! Call the I-PDU callout before PduR_ComTransmit */
    /* Com-CDD-TxHandler-0404(0) */
    pstrMainFunctionTxData->bMTLCalloutReturn =
        (*pfbMTLCallout)(*pu16MTLCrntIPduId,pstrPduInfoPtr);
   SchM_Exit_Com_IPduBuff();
  }
  else
  {
    pstrMainFunctionTxData->bMTLCalloutReturn = TRUE;
  }

  if(pstrMainFunctionTxData->bMTLCalloutReturn == TRUE)
  {
#endif 
  
#if (Com_bIPDU_COUNTER_SUPPORT == STD_ON)    
	if((pkstrTxIPduPtr->u16IPduCounterIndex) != (uint16)0xFFFFu)
    {
      /*! If I-PDU counter is configured for the I-PDU to be sent, \n
       call Com_IpduPackDataSeq service before sending I-PDU via \n
       PduR_ComTransmit. */
      /* Com-CDD-TxHandler-0501(0) */
      Com_vidIpduPackDataSeq(pstrMainFunctionTxData->u16MTLCurrentIPduId);
    }
  
#endif
    /*! Send I-PDU */

    /* Com-CDD-TxHandler-0275(0) */
    pstrMainFunctionTxData->u8MTLPdurRetVal =
                Com_u8SendIPdu(pstrMainFunctionTxData->u16MTLCurrentIPduId,
                               TRUE);
	
	/*! add this line here to Clear MDT flag after send as it's moved from Com_u8SendIPdu to its function calling*/
	pstrMainFunctionTxData->bIPduMDTMask = FALSE;
	
	#if u16NO_OF_IPDUS_STATUS > 0u
   SchM_Enter_Com_IPduStatus_19();
	Com_audteIPduStatus[pstrMainFunctionTxData->u16MTLCurrentIPduId] |= Com_u8WAIT_CONF; 
   SchM_Exit_Com_IPduStatus_19();
	#endif
	
#if (Com_bTO_SUPPORT == STD_ON) 
   SchM_Enter_Com_TimeoutTimer();

	 u16TxTOTimerIx = pkstrTxIPduPtr->u16TOTimerIndex;
		 if((u16TxTOTimerIx != (uint16)0xFFFFu)
      && (pu32TOutT[u16TxTOTimerIx] == (uint32)0))
    {
      /*! Reload I-PDU Timeout timer if not running calling \n
      PduR_ComTransmit if bfIPduTimeout == TRUE.*/

      /* Com-CDD-TxHandler-5702(0) */
      pu32TOutT[u16TxTOTimerIx] = 
		pkstrTxIPduPtr->u32Timeout;
     SchM_Exit_Com_TimeoutTimer();
    }
    else
    {
     SchM_Exit_Com_TimeoutTimer();
    }
#endif
  
#if (Com_bUBIT_SUPPORT== STD_ON)    
    if((pstrMainFunctionTxData->u8MTLPdurRetVal == E_OK) &&
       (u8TXIPDU_GET_TYPE(pstrMainFunctionTxData->u16MTLCurrentIPduIndex) ==
                                                    Com_u8IPDU_TYPE_NORMAL))
    {
      /* Com-CDD-TxHandler-5735(0) */
      vidIPduClearUBits(pstrMainFunctionTxData->u16MTLCurrentIPduId);
    }
#endif

#if (Com_bTX_CALLOUT_SUPPORT == STD_ON)  
  }
  else
  {
    /* Com-CDD-TxHandler-0059(0) */
    /*! If the I-PDU callout returns false stop processing the I-PDU */
    /* Fix Bug# 50864: Clear TxConfWaitFlags*/

	/* !Deviation: [0277]  ( An Integer Constant experssion with negative value is being converted to 
	an unsigned type)  */
	/*PRQA S 0277 ++ */
   SchM_Enter_Com_IPduStatus_19();
	Com_audteIPduStatus[*pu16MTLCrntIPduId] &= (Com_udtIPduStatus)(~(Com_u8WAIT_CONF));
   SchM_Exit_Com_IPduStatus_19();
	
	/*Com_audteIPduStatus[*pu16MTLCrntIPduId] &= (Com_udtIPduStatus)(~(Com_u8D_MDT_MASK));*/
	pstrMainFunctionTxData->bIPduMDTMask = FALSE;
	/*PRQA S 0277 -- */
  }
#endif
}/* vidActiveIPduHandleSend */
/* PRQA S 4700 -- */

/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
This function deviates in STCYC = 15 and STSUB = 15. Partitioning this
function shall not pay for the negative effect of context switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description This function handles Com_MainFunctionTx processing in case: \n
                  IPDU state = Active \n
                 This function is added to reduce code complexity.
  \param[in]   pstrMainFunctionTxData  Pointer to Com_MainFunctionTx internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To   Com-CDD-TxHandler-0274(0),
                Com-CDD-TxHandler-0275(0),
                Com-CDD-TxHandler-0277(0),
                Com-CDD-TxHandler-5592(0),
                Com-CDD-0270(0),
				Com-CDD-5746(0), Com-CDD-5370(1)*/
static FUNC(void, COM_CODE) vidActiveIPduHandle(
    P2VAR(tstrMainFunctionTxData, AUTOMATIC, COM_VAR)
                                                pstrMainFunctionTxData)
{
    P2VAR(PduIdType, AUTOMATIC, AUTOMATIC) pu16MTLCrntIPduId;
    P2VAR(Com_tu32MDTimer,AUTOMATIC,TYPEDEF)pu32MDTimerPtr;
    P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF)pkstrTxIPduPtr;
    P2VAR(uint16, AUTOMATIC,AUTOMATIC) pu16MTLCrntIPduIdx;
    VAR(uint16, AUTOMATIC) u16MDTimerIx;
	pu16MTLCrntIPduId = &(pstrMainFunctionTxData->u16MTLCurrentIPduId);
	pu32MDTimerPtr = pku32GET_MD_TIMER(0);
	pu16MTLCrntIPduIdx = &(pstrMainFunctionTxData->u16MTLCurrentIPduIndex);
	pkstrTxIPduPtr = pkstrGET_TX_IPDU_PTR(*pu16MTLCrntIPduIdx);
	
#if (Com_bTO_SUPPORT == STD_ON) 
  /* Handling timeout */
  vidActiveIPduHandleTO(pstrMainFunctionTxData);
#endif

  /*! This flag indicated the first transmission as it's TMS result or send request with TMS off*/
  /*#if u16NO_OF_IPDUS_STATUS > 0u
  pstrMainFunctionTxData->bMTLDelayedMDT = Com_audteIPduStatus[*pu16MTLCrntIPduId] & (Com_udtIPduStatus)Com_u8D_MDT_MASK;
  #endif*/
  pstrMainFunctionTxData->bMTLDelayedMDT = pstrMainFunctionTxData->bIPduMDTMask;
  
/* Check if I-PDU is active */

  if(pstrMainFunctionTxData->bMTLIPduState != FALSE)
  {
    switch(pstrMainFunctionTxData->u8MTLCurrentTxModeType)
    {
      case Com_u8TX_MODE_MIXED:
      vidActiveIPduHandleM(pstrMainFunctionTxData);
      break;

      case Com_u8TX_MODE_PERIODIC:
      vidActiveIPduHandleP(pstrMainFunctionTxData);
      break;

      case Com_u8TX_MODE_DIRECT:
	  #if (Com_bNTIMES_SUPPORT == STD_ON)  
      vidActiveIPduHandleD(pstrMainFunctionTxData);
	  #endif
      break;


      case Com_u8TX_MODE_NONE:
      /* Com-CDD-TxHandler-0274(0) */
      break;

      default:

      break;
    }
	
#if (Com_bMDT_SUPPORT == STD_ON)
    /* Handling I-PDUs Delayed due to MDT. Decrement MDT*/
    vidActiveIPduHandleMDT(pstrMainFunctionTxData);
#endif
    /* (pstrMainFunctionTxData->bMTLDelayedMDT != FALSE) add for optimization 
    prototype only.
    this part of code generates faulty send for I-PDU regardless 
    of their TxMode. This should be handled in a correct way */   
    if(((pstrMainFunctionTxData->bMTLSendIPdu == TRUE)
			|| (pstrMainFunctionTxData->bMTLDelayedMDT != FALSE))
#if (Com_bMDT_SUPPORT == STD_ON)
				&&(pstrMainFunctionTxData->bMTLElapsedMDT != FALSE)
#endif
	)
    {
		vidActiveIPduHandleSend(pstrMainFunctionTxData);
		
		#if (Com_bNTIMES_SUPPORT == STD_OFF)
			/*#if u16NO_OF_IPDUS_STATUS > 0u
			Com_audteIPduStatus[*pu16MTLCrntIPduId] &= (Com_udtIPduStatus) ~Com_u8D_MDT_MASK;
			#endif*/
			pstrMainFunctionTxData->bIPduMDTMask = FALSE;
		#endif
    }
    else
    {

    }
    /*! If I-PDU flag in Com_u8DEF_PROC_MASK is set then \n
     for each signal in the I-PDU, call the configured signal notification \n
      function */
    /* Com-CDD-TxHandler-5592(0) */

  if(pkstrTxIPduPtr->pfvidIPduNotifPtr != NULL_PTR)
  {
	
	#if u16NO_OF_IPDUS_STATUS > 0u
   SchM_Enter_Com_IPduStatus_19();
    pstrMainFunctionTxData->bMTLIPduIsDeferred =
      Com_audteIPduStatus[*pu16MTLCrntIPduId] & Com_u8DEF_PROC_MASK;  
	  Com_audteIPduStatus[*pu16MTLCrntIPduId] &= (Com_udtIPduStatus)(~Com_u8DEF_PROC_MASK);
   SchM_Exit_Com_IPduStatus_19();   
	#endif
	
	
    if(pstrMainFunctionTxData->bMTLIPduIsDeferred != FALSE)
    {
      (*pkstrTxIPduPtr->pfvidIPduNotifPtr)();
    }
   }  
   
 
  }
  else /* pstrMainFunctionTxData->bMTLIPduState == FALSE I-PDU Stopped */
  {
#if (Com_bMDT_SUPPORT == STD_ON)     
    /*! Decrement MDT if applicable in case of stopped I-PDU also */
    /*! Com-CDD-TxHandler-0277(0) */

	u16MDTimerIx = pkstrTxIPduPtr->u16MDTimerIndex;
	if(u16MDTimerIx != (uint16)0xFFFFu)
    {
      if(pstrMainFunctionTxData->bMTLElapsedMDT == FALSE)
      {
       SchM_Enter_Com_MDT();
        (pu32MDTimerPtr[u16MDTimerIx]) = 
        (pu32MDTimerPtr[u16MDTimerIx])- (uint32) 1;
       SchM_Exit_Com_MDT();
      }
    }
#endif  
  }
}
/* PRQA S 4700 -- */

#if (Com_bTMS_SUPPORT == STD_ON)
/******************************************************************************/
/*! \Description This function handles I-PDU processing of SendSignal calls \n
                 of the period between MainFunctionTx calls \n
                 This function is added to enhance code performance.
  \param[in]   pstrMainFunctionTxData  Pointer to Com_MainFunctionTx internal \n
               variables structure
  \return      void
*******************************************************************************/
/*! \Trace_To    */
static FUNC(void, COM_CODE) vidHandleSendSigReqs(
    P2VAR(tstrMainFunctionTxData, AUTOMATIC, COM_VAR)
                                                pstrMainFunctionTxData)
{

  VAR(boolean, AUTOMATIC)             bSigWaitProcessing;
  VAR(Com_SignalIdType, AUTOMATIC)    u16SigId;
  VAR(tstrSendSignalData, AUTOMATIC)  strSendSignalData;

  P2VAR(uint8, AUTOMATIC,AUTOMATIC)       pu8MTLCrntSigType;
  P2VAR(uint16, AUTOMATIC,AUTOMATIC)      pu16MTLCrntSigIx;
  P2VAR(uint16_least, AUTOMATIC,AUTOMATIC)      pu16MTLSigLoopIx;
  P2VAR(uint16, AUTOMATIC,AUTOMATIC)      pu16MTLCrntNoOfSig;
  P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF)pkstrIPduToSigMap;
  P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF)pkstrIPduToSigMapLoc;
  P2CONST(Com_tstrGWSignalMapping,AUTOMATIC,TYPEDEF)pkstrGWSigMap;
  P2CONST(Com_tstrGWSignalMapping,AUTOMATIC,TYPEDEF)pkstrGWSigMapLoc;
  P2CONST(Com_tstrGWDstDesc,AUTOMATIC,TYPEDEF) pkGWDstDsc;
  P2VAR(uint16, AUTOMATIC,AUTOMATIC)      pu16MTLCrntSigMapIx;

  P2VAR(PduIdType, AUTOMATIC, AUTOMATIC)   pu16MTLCrntIPduId;
  P2VAR(uint16, AUTOMATIC, AUTOMATIC)      pu16MTLCrntIPduIdx;

  P2VAR(uint8, AUTOMATIC,AUTOMATIC)     pu8SigDataNewTxModTyp;
  P2VAR(uint16, AUTOMATIC,AUTOMATIC)    pu16SigDataNewTxModIdx;
  P2VAR(boolean, AUTOMATIC,AUTOMATIC)   pbSigDataSigIsChngd;
  P2VAR(boolean, AUTOMATIC,AUTOMATIC)   pbSigDataSendIPdu;
  P2VAR(uint8, AUTOMATIC,AUTOMATIC)     pu8SigDataSigStrctTyp;
  P2VAR(PduIdType, AUTOMATIC,AUTOMATIC)   pudtSigDataCrntIPduId;
  P2VAR(uint16, AUTOMATIC,AUTOMATIC)    pu16SigDataCrntIPduIx;  
  P2VAR(uint16, AUTOMATIC,AUTOMATIC)    pu16SigDataDynLnth;
  P2VAR(uint16, AUTOMATIC,AUTOMATIC)    pu16SigDataCrntSigIx;
  P2VAR(boolean, AUTOMATIC,AUTOMATIC)   pbSigDataSupressCnclTx;
  P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF) pkstrTxIPduPtr;
  P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,TYPEDEF) pkstrLocSigGroPB;
	
  pkstrTxIPduPtr = pkstrGET_TX_IPDU_PTR(pstrMainFunctionTxData->u16MTLCurrentIPduIndex);
  pstrMainFunctionTxData->u16MTLCurrentNoOfSig = pkstrTxIPduPtr->u16IPduNoOfSignals;
  pstrMainFunctionTxData->u16MTLCurrentSigMapIx = pkstrTxIPduPtr->u16IPduSigMappingIndex;
  strSendSignalData.bSupressCancelTx = FALSE;
  
  pu16MTLSigLoopIx = &(pstrMainFunctionTxData->u16MTLSigLoopIndex);
  pu16MTLCrntNoOfSig = &(pstrMainFunctionTxData->u16MTLCurrentNoOfSig);
  pu16MTLCrntSigIx= &(pstrMainFunctionTxData->u16MTLCurrentSigIx);
  pkstrGWSigMapLoc = pkstrGET_GW_MAP_SIG_PTR(0);
  pkstrIPduToSigMapLoc = pkstrGET_IPDU_SIG_MAP_PTR(0);
  pu16MTLCrntSigMapIx = &(pstrMainFunctionTxData->u16MTLCurrentSigMapIx);
  pu8MTLCrntSigType = &(pstrMainFunctionTxData->u8MTLCurrentSigType);
  pkGWDstDsc = pkstrGET_PB_DST_DESC_PTR(0);
  pu16MTLCrntIPduId = &(pstrMainFunctionTxData->u16MTLCurrentIPduId);
  pu16MTLCrntIPduIdx = &(pstrMainFunctionTxData->u16MTLCurrentIPduIndex);

  pu8SigDataNewTxModTyp   = &(strSendSignalData.u8SSLNewTxModeType);
  pu16SigDataNewTxModIdx  = &(strSendSignalData.u16SSLNewTxModeIndex);
  pbSigDataSigIsChngd   = &(strSendSignalData.bSSLSignalIsChanged);
  pbSigDataSendIPdu     = &(strSendSignalData.bSSLSendIPdu);
  pu8SigDataSigStrctTyp   = &(strSendSignalData.u8SSLSigStructType);
  pudtSigDataCrntIPduId   = &(strSendSignalData.u16SSLCurrentIPduId);
  pu16SigDataCrntIPduIx   = &(strSendSignalData.u16SSLCurrentIPduIx);
  pu16SigDataDynLnth    = &(strSendSignalData.u16SSLDynLength);
  pu16SigDataCrntSigIx    = &(strSendSignalData.u16SSLCurrentSigIx);
  pbSigDataSupressCnclTx  = &(strSendSignalData.bSupressCancelTx);

   
  *pudtSigDataCrntIPduId  = *pu16MTLCrntIPduId;
  *pu16SigDataCrntIPduIx  = *pu16MTLCrntIPduIdx;
  strSendSignalData.u8SSLCurrentTxProperty = Com_u8TXPROP_PENDING;
  strSendSignalData.bSSLSignalIsChanged = FALSE;
  /*! for each signal/dst/Signal Groups description in the I-PDU to apply filtering 
	algorithum and save its results if its filter configured and Send request is occured*/
  for(*pu16MTLSigLoopIx = 0u; *pu16MTLSigLoopIx < *pu16MTLCrntNoOfSig;
      (*pu16MTLSigLoopIx)++)
  {
    pkstrIPduToSigMap = &pkstrIPduToSigMapLoc[(*pu16MTLCrntSigMapIx + *pu16MTLSigLoopIx)];
    *pu16MTLCrntSigIx =
      pkstrIPduToSigMap->u16Index;
    *pu8MTLCrntSigType =
      pkstrIPduToSigMap->u8Type;

	 /*! If GW signal/Signal group get its index, type from GW Mapping */ 
    if(*pu8MTLCrntSigType == (uint8) Com_u8GWSIGNAL)
    {
	   pkstrGWSigMap = &pkstrGWSigMapLoc[*pu16MTLCrntSigIx];
      *pu8MTLCrntSigType = pkstrGWSigMap->u8DstStructType;
      *pu16MTLCrntSigIx =  pkstrGWSigMap->u16DstIndex;
    }

    if(*pu8MTLCrntSigType == (uint8) Com_u8SIGNAL)
    {
#if Com_u16NO_OF_SIGNAL > 0u
      u16SigId = Com_akstreSignalLT[*pu16MTLCrntSigIx].u16SignalId;
#else
      u16SigId = (Com_SignalIdType) 0;
#endif
    }
	#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
    else if(*pu8MTLCrntSigType == (uint8) Com_u8SIGNALGROUP)
    {
	  /*!Signal Group ID is the pu16MTLCrntSigIx the index is used to get its First group signal ID */
	  /*! we will use the first group signal ID to store and get signal group status as 
	     Com_audteSignalStatus is indexed by signals ID*/
	  pkstrLocSigGroPB = pkstrGET_PB_SIGGRP_PTR(*pu16MTLCrntSigIx);
	  u16SigId = Com_akstreGroupSignalLT[pkstrLocSigGroPB->u16GroupSignalIndex].u16SignalId;		
	}
	#endif
    else if(*pu8MTLCrntSigType == (uint8) Com_u8GW_STRUCT_DST_DESC)
    {
      u16SigId =
            pkGWDstDsc[*pu16MTLCrntSigIx].u16SignalId;
    }
	else
	{
      u16SigId = (Com_SignalIdType) 0;
    }


    if((*pu8MTLCrntSigType == (uint8) Com_u8SIGNAL) ||
       (*pu8MTLCrntSigType == (uint8) Com_u8GW_STRUCT_DST_DESC) || (*pu8MTLCrntSigType == (uint8) Com_u8SIGNALGROUP))
    {
	  
	  /*! Getting the Signal/Signal group Send Signal request Occured and need 
			to apply TMS ot not */
	  #if Com_u16NO_OF_SIGNAL_STATUS > 0u
	 SchM_Enter_Com_SignalStatus_19();
	  bSigWaitProcessing = Com_audteSignalStatus[u16SigId] & Com_u8SS_TMS_REQ;
	 SchM_Exit_Com_SignalStatus_19(); 
	  #endif
	  
	  
      if(bSigWaitProcessing != FALSE)
      {
        *pu8SigDataNewTxModTyp  = (uint8)0;
        *pu16SigDataNewTxModIdx = (uint16)0;
        *pbSigDataSigIsChngd  = FALSE;
        *pbSigDataSendIPdu    = FALSE;
        *pu8SigDataSigStrctTyp  = *pu8MTLCrntSigType;

        /*! clear u16SSLDynLength because it is used in case of dynamic \n
        signals only */
        *pu16SigDataDynLnth = (uint16)0;

        *pu16SigDataCrntSigIx = *pu16MTLCrntSigIx;
		
		
		switch(*pu8MTLCrntSigType)
		{
		case Com_u8SIGNAL:
		case Com_u8GW_STRUCT_DST_DESC:
			/*! Apply filtering Of signal/Signal desciption and save results*/
			vidPrepSendSignal(&strSendSignalData, u16SigId);
		break;
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
		case Com_u8SIGNALGROUP:
		   /*! Apply filtering Of signalGroup and save results*/
			vidPrepSendSignalGroup(*pu16MTLCrntSigIx,&strSendSignalData);
		break;
#endif
		default:
		break;
		}

		/*! Clear send signal requests status after its filtering processing*/
		#if Com_u16NO_OF_SIGNAL_STATUS > 0u
		SchM_Enter_Com_SignalStatus_19();
		Com_audteSignalStatus[u16SigId] &= (Com_udtIPduStatus)(~Com_u8SS_TMS_REQ);
		SchM_Exit_Com_SignalStatus_19(); 
		#endif
		
      }
    }
  }
  
  /*! This part add new function vidIPduHandleTMS() to apply TMS on all signals/Signal groups 
			one time after apply filtering above*/
	vidIPduHandleTMS(&strSendSignalData);
  
  /*! Comment this part because checking MDT do it In Com_MainFunctionTx*/

    /* Com-CDD-TxHandler-0303(0) */

	/*! add this line to avoid redundancy check MDT in the MainFunction Again to be used there vidActiveIPduHandle*/
	strSendSignalData.bSSLElapsedMDT = pstrMainFunctionTxData->bMTLElapsedMDT;
	
  /* Com-CDD-TxHandler-0011(0) */
	strSendSignalData.bSSLIPduState = pstrMainFunctionTxData->bMTLIPduState;
	strSendSignalData.bIPduSignalMDTMask = pstrMainFunctionTxData->bIPduMDTMask;
  /*! Handle IPDU Tx Modes (Mark IPDU is Send, Load repetition counter, repetition period, Period for periodic...)*/
	vidHandleSendSignal(&strSendSignalData);
  
  pstrMainFunctionTxData->bIPduMDTMask = strSendSignalData.bIPduSignalMDTMask;
  *pbSigDataSupressCnclTx = TRUE;
   /*! this part added for mapping Marking IPDu to send to the Actual sending In function */
   #if u16NO_OF_IPDUS_STATUS > 0u
    if((*pbSigDataSendIPdu == TRUE) && ((Com_audteIPduStatus[*pudtSigDataCrntIPduId] & Com_u8RX_DM_EN_TX_STOP) == FALSE))
   {
	  /* Com-CDD-TxHandler-5736(0) */
	  /*Com_audteIPduStatus[*pudtSigDataCrntIPduId] |= (Com_udtIPduStatus)Com_u8D_MDT_MASK; */
	  pstrMainFunctionTxData->bIPduMDTMask = TRUE;
   }
   else
   {
   }
   #endif
   
}

#endif
/******************************************************************************/
/*! \Description This function performs the processing of the AUTOSAR COM \n
                 modules transmission activities that are not directly \n
                 handled within the COMs function invoked by the RTE, \n
                 for example Com_SendSignal.
    \param[in]  None
*******************************************************************************/
/*! \Trace_To Com-CDD-TxHandler-0113(0),
              Com-CDD-TxHandler-0282(0), Com-CDD-5746(0), Com-CDD-5368(1),
			  Com-CDD-5746(0), Com-CDD-5744(1), Com-CDD-5216(1), Com-CDD-5370(1),
			  Com-CDD-5748(1), Com-CDD-5546(1) */
FUNC(void, COM_CODE) Com_MainFunctionTx( void )
{
  /*! Local variables */

  VAR(tstrMainFunctionTxData, AUTOMATIC) strMainFunctionTxData;

  P2VAR(boolean, AUTOMATIC, AUTOMATIC)     pbSendIPdu;
  P2VAR(boolean, AUTOMATIC, AUTOMATIC)     pbMTLCrntTxMode;
  P2VAR(boolean, AUTOMATIC, AUTOMATIC)     pbMTLIPduStatePtr;
  P2VAR(PduIdType, AUTOMATIC, AUTOMATIC)   pu16MTLCrntIPduId;
  P2VAR(uint16, AUTOMATIC, AUTOMATIC)      pu16MTLCrntIPduIdx;
  P2VAR(uint8, AUTOMATIC, AUTOMATIC)       pu8MTLCrntTxModeType;
  P2VAR(uint16, AUTOMATIC, AUTOMATIC)      pu16MTLCrntTxModeIx;
#if (Com_bMDT_SUPPORT == STD_ON)  
  VAR(uint16, AUTOMATIC)                   u16MDIPduTimerIx;
  P2VAR(Com_tu32MDTimer,AUTOMATIC,TYPEDEF) pu32MDTimerPtr;
#endif
  P2CONST(Com_tstrTxMode,AUTOMATIC,TYPEDEF)pkstrTxMode_ptr;
  P2CONST(Com_tstrTxMode,AUTOMATIC,TYPEDEF)pkstrLocTxMode_ptr;
  P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF)pkstrTxIPduPtr;
  P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF)pkstrTxIPduLocPtr;
  P2VAR(boolean, AUTOMATIC, AUTOMATIC)     pbMTLElpsdMDT;
  
#if (Com_bTMS_SUPPORT == STD_OFF)
  VAR(tstrSendSignalData,AUTOMATIC) strSendSignalData;
#endif
  VAR(boolean, AUTOMATIC)                   bSendSignalRq;
  VAR(uint8, AUTOMATIC)                     u8IpduStatus;
  VAR(uint16_least, AUTOMATIC)              u16LoopIndex;
  VAR(uint16, AUTOMATIC)              		u16LocalIPduId;  
  VAR(uint8, AUTOMATIC)                     audteIPduStatus[Com_u16TXIPDUMAXIX+1];

  /* Com-CDD-0261(0) */
  if (Com_enueStatus == COM_UNINIT)
  {
  /*! Do Nothing */
  }
  else
  {
	/*Starting Get all IPDU's data in Structure that can be passed to all local Functions*/
  pbSendIPdu = &(strMainFunctionTxData.bMTLSendIPdu);
  pu16MTLCrntIPduId = &(strMainFunctionTxData.u16MTLCurrentIPduId);
  pu16MTLCrntIPduIdx = &(strMainFunctionTxData.u16MTLCurrentIPduIndex);
  pbMTLCrntTxMode = &(strMainFunctionTxData.bMTLCurrentTxMode);
  pu8MTLCrntTxModeType = &(strMainFunctionTxData.u8MTLCurrentTxModeType);
  pu16MTLCrntTxModeIx = &(strMainFunctionTxData.u16MTLCurrentTxModeIx);
  pkstrLocTxMode_ptr = u8IPDU_GET_TXMODE_PTR(0);
  pkstrTxIPduLocPtr = pkstrGET_TX_IPDU_PTR(0);
#if (Com_bMDT_SUPPORT == STD_ON) 
  pu32MDTimerPtr = pku32GET_MD_TIMER(0);
#endif
  pbMTLElpsdMDT = &(strMainFunctionTxData.bMTLElapsedMDT);
  pbMTLIPduStatePtr = &(strMainFunctionTxData.bMTLIPduState);
#if u16NO_OF_IPDUS_STATUS > 0u
  SchM_Enter_Com_IPduStatus_19();
   for(u16LoopIndex = 0u;
        u16LoopIndex <= Com_u16TXIPDUMAXIX;
         u16LoopIndex++)
	{
		u16LocalIPduId = pkstrTxIPduLocPtr[u16LoopIndex].u16IPduId;
		audteIPduStatus[u16LoopIndex] = Com_audteIPduStatus[u16LocalIPduId];
	}
	SchM_Exit_Com_IPduStatus_19();
#endif
    /* for each Tx I-PDU processs TMS, Sending IPDU requests, MDT handling*/
    for(u16LoopIndex = 0u;
         u16LoopIndex <= Com_u16TXIPDUMAXIX;
         u16LoopIndex++)
    {
      *pbSendIPdu = FALSE;
      *pu16MTLCrntIPduIdx = u16LoopIndex;
	  pkstrTxIPduPtr = &pkstrTxIPduLocPtr[u16LoopIndex];
      *pu16MTLCrntIPduId = pkstrTxIPduPtr->u16IPduId;
	  u16LocalIPduId =  *pu16MTLCrntIPduId;
     /* Com-CDD-TxHandler-0011(0) */
	
	 /*SchM_Enter_Com_IPduStatus_19();*/
	 u8IpduStatus = audteIPduStatus[u16LoopIndex];
	 /*SchM_Exit_Com_IPduStatus_19();*/
				  
	 strMainFunctionTxData.bIPduMDTMask = ((u8IpduStatus & Com_u8D_MDT_MASK) != FALSE);
	 bSendSignalRq = ((u8IpduStatus & Com_u8SENDSIGNAL_RQ) != FALSE);
	 strMainFunctionTxData.bMTLIPduState = ((u8IpduStatus & (Com_u8ACTIVE_MASK)) != FALSE);
	 
#if (Com_bMDT_SUPPORT == STD_ON)  
		/*! Checking MDT Timer is expired*/
		/*! if MDTIpduTimer Ix is 0xFFFF that means IPDU doesn't configured MDT*/
		u16MDIPduTimerIx = pkstrTxIPduPtr->u16MDTimerIndex;
		if(u16MDIPduTimerIx != (uint16)0xFFFFu)
        {
         /*SchM_Enter_Com_MDT();*/
		  /*! Check Timer expires or Not*/
          if(pu32MDTimerPtr[u16MDIPduTimerIx] != (Com_tu32MDTimer)0)
          {
            *pbMTLElpsdMDT = FALSE;
          }
          else
          {
			/*! Mark IPDU's MDT is expired and this IPDU can be sent now */
            *pbMTLElpsdMDT = TRUE;
          }
         /*SchM_Exit_Com_MDT();*/
        }
        else
        {
#endif
          /*! No minimum delay time monitoring shall take place, if I-PDU \n
           MDT support flag equals FALSE */
          /* Com-CDD-TxHandler-0282(0) */
          *pbMTLElpsdMDT = TRUE;
		  
#if (Com_bMDT_SUPPORT == STD_ON)         
		}
#endif

				  
				  
#if (Com_bTMS_SUPPORT == STD_ON)
      /* handles previous SendSignal calls */
	  /*! This Part is used to chech if IPDU has send signal request then apply TMS algorithum 
			on this IPDU */ 
		#if u16NO_OF_IPDUS_STATUS > 0u
		if(bSendSignalRq != FALSE)
		{
			vidHandleSendSigReqs(&strMainFunctionTxData);	
		}
		else
		{	  
		}
		#endif
		
		
		/*! Get the Current IPDU Tx Mode */
		#if u16NO_OF_IPDUS_STATUS > 0u
		*pbMTLCrntTxMode = ((Com_audteIPduStatus[u16LocalIPduId] & Com_u8CURR_TX_MO_FLG) != FALSE);
		#endif
#else
		/*! This part added to handle Send signal requests if TMS Feature is
		  closed in configuration*/
		 if(strMainFunctionTxData.bMTLIPduState == TRUE)
		{
			
			if(bSendSignalRq != FALSE)
			{
				 /*! setting Current Tx Property for the signal requested the transimsstion from this flag, 
				 it mean this signal is triggered or triggered on change and it's changed*/
				strSendSignalData.u8SSLCurrentTxProperty = bSendSignalRq;
			  
				/*! this part handling Send signals request betweeen different modes with NO TM switch*/
				pkstrTxMode_ptr = &pkstrLocTxMode_ptr[(pkstrTxIPduPtr->u16TxModeTrueIndex)];
				strSendSignalData.u8SSLNewTxModeType = pkstrTxMode_ptr->u8TxMode;
				strSendSignalData.u16SSLNewTxModeIndex = pkstrTxMode_ptr->u16Index;  
				strSendSignalData.u16SSLCurrentIPduIx = strMainFunctionTxData.u16MTLCurrentIPduIndex;
				strSendSignalData.u16SSLCurrentIPduId = strMainFunctionTxData.u16MTLCurrentIPduId;
				strSendSignalData.bSSLElapsedMDT	= *pbMTLElpsdMDT;
				strSendSignalData.bSupressCancelTx = FALSE;
				strSendSignalData.bSSLSendIPdu = FALSE;
				strSendSignalData.bIPduSignalMDTMask = strMainFunctionTxData.bIPduMDTMask;
			   /*The next line is added to make Send IPDU if it's signals is requested to send and TMS feature is OFF*/
			   
			  switch(strSendSignalData.u8SSLNewTxModeType)
			  {
			  case Com_u8TX_MODE_MIXED:
					if(strSendSignalData.bSSLElapsedMDT == TRUE)
					{
						vidHandleSendSignalFTTM(&strSendSignalData);
					}
					else
					{
						vidHandleSendSignalFTFM(&strSendSignalData);
					}
			  break;
			  case Com_u8TX_MODE_DIRECT:
					if(strSendSignalData.bSSLElapsedMDT == TRUE)
					{
						vidHandleSendSignalFTTD(&strSendSignalData);
					}
					else
					{
						vidHandleSendSignalFTFD(&strSendSignalData);
					}
			  break;
			  
			  default:
			  break;
			  }
			  
			  strMainFunctionTxData.bIPduMDTMask = strSendSignalData.bIPduSignalMDTMask;
				 /*! this part added for mapping Marking IPDu to send to the Actual sending In function */
				if(strSendSignalData.bSSLSendIPdu == TRUE)
			   {
				  /* Com-CDD-TxHandler-5736(0) */
				  strMainFunctionTxData.bIPduMDTMask = TRUE;
			   }

			}
			else
			{
			}
		}
		
#endif

#if (Com_bTMS_SUPPORT == STD_ON)
        if(*pbMTLCrntTxMode != FALSE)
        { 
		 /*! The TRUE Tx mode is used in case of TMS is ON and Current Tx mode falg is TRUE
		 or TMS is OFF */
#endif
		  pkstrTxMode_ptr = &pkstrLocTxMode_ptr[(pkstrTxIPduPtr->u16TxModeTrueIndex)];
          *pu8MTLCrntTxModeType = pkstrTxMode_ptr->u8TxMode;
          *pu16MTLCrntTxModeIx = pkstrTxMode_ptr->u16Index;         

#if (Com_bTMS_SUPPORT == STD_ON)
		}    
        else
        /*strMainFunctionTxData.bMTLCurrentTxMode == FALSE*/
        {
		  pkstrTxMode_ptr = &pkstrLocTxMode_ptr[(pkstrTxIPduPtr->u16TxModeFalseIndex)];
          *pu8MTLCrntTxModeType = pkstrTxMode_ptr->u8TxMode;
          *pu16MTLCrntTxModeIx = pkstrTxMode_ptr->u16Index;
        }
#endif 
		
		*pbMTLIPduStatePtr = strMainFunctionTxData.bMTLIPduState;
         vidActiveIPduHandle(&strMainFunctionTxData);
		 
		 if (strMainFunctionTxData.bIPduMDTMask != FALSE)
			{
				audteIPduStatus[u16LoopIndex] |= (Com_udtIPduStatus) Com_u8D_MDT_MASK;
			}
			else
			{
				audteIPduStatus[u16LoopIndex] &= (Com_udtIPduStatus) ~Com_u8D_MDT_MASK;
			}
    }
 	
   SchM_Enter_Com_IPduStatus_19();
    for(u16LoopIndex = 0u;
        u16LoopIndex <= Com_u16TXIPDUMAXIX;
         u16LoopIndex++)
	{
	     u16LocalIPduId = pkstrTxIPduLocPtr[u16LoopIndex].u16IPduId;
		if ((audteIPduStatus[u16LoopIndex] & Com_u8SENDSIGNAL_RQ)!= FALSE)
		{
			Com_audteIPduStatus[u16LocalIPduId] &= (Com_udtIPduStatus) ~Com_u8SENDSIGNAL_RQ;
		}
		/*! add this part for set the MDT flag for the new value*/
		#if u16NO_OF_IPDUS_STATUS > 0u		
			if ((audteIPduStatus[u16LoopIndex] & Com_u8D_MDT_MASK) != FALSE)
			{
				Com_audteIPduStatus[u16LocalIPduId] |= (Com_udtIPduStatus) Com_u8D_MDT_MASK;
			}
			else
			{
				Com_audteIPduStatus[u16LocalIPduId] &= (Com_udtIPduStatus) ~Com_u8D_MDT_MASK;
			}
		#endif
	}
	SchM_Exit_Com_IPduStatus_19();
	
	
  } /* Com_enueStatus != COM_UNINIT */
  return;
} /* Com_MainFunctionTx() */

/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
Partitioning this function shall not pay for the negative effect of context
switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description  By a call to Com_TriggerIPDUSend the I-PDU with the given \n
                  ID is triggered for transmission. \n
    \param[in]  PduId IThe I-PDU-ID of the I-PDU that shall be triggered for \n
                sending \n
                \Range n/a                          \n
                \Unit n/a
    \param[in,out]  None
*******************************************************************************/
/*! \Trace_To Com-CDD-TxHandler-0430(0),
              Com-CDD-TxHandler-0431(0),
              Com-CDD-TxHandler-0432(0),
              Com-CDD-TxHandler-5748(0),
              Com-CDD-0234(0),
              Com-CDD-0232(0),
              Com-CDD-0279(0) */
FUNC(void, COM_CODE) Com_TriggerIPDUSend(VAR(PduIdType, AUTOMATIC) PduId)
{
  /*! Local variables */
  VAR(boolean, AUTOMATIC)                 bCalloutReturn;
  VAR(boolean, AUTOMATIC)                 bElapsedMDT;

  VAR(uint8, AUTOMATIC)                   u8PdurRetVal;

  VAR(uint16, AUTOMATIC)                  u16CurrentIPduIx;
#if (Com_bTX_CALLOUT_SUPPORT == STD_ON)
  VAR(uint16, AUTOMATIC)                  u16IPduCalloutIx;
#endif

#if Com_u16NO_OF_TXIPDU_CALLOUT > 0u
  P2VAR(PduInfoType,AUTOMATIC,COM_CALIB_DATA)pstrPduInfoPtr;
  VAR(PduInfoType,AUTOMATIC)   strPduInfo;   
  VAR(uint16,AUTOMATIC)	  u16DynLength;
  VAR(boolean,AUTOMATIC)	  bDynamicIPdu;
#endif
  P2VAR(Com_tu32MDTimer,AUTOMATIC,TYPEDEF)pu32MDTimerPtr;
  P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF)pkstrTxIPduPtr;
  P2VAR(uint32,AUTOMATIC,AUTOMATIC)pu32TOT;
  VAR(uint16, AUTOMATIC)                  u16TxTOTimerIx;
  VAR(uint16, AUTOMATIC)                  u16MDTimerIx;

  /*! DET check and reporting */

  /* Com-CDD-TxHandler-0430(0) */
  if (Com_enueStatus == COM_UNINIT)
  {
#if (COM_DEV_ERROR_DETECT == STD_ON)
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_TriggerIPDUSend , COM_E_UNINIT);
/* PRQA S 3212 -- */
#endif /*COM_DEV_ERROR_DETECT*/
  }
  /* Com-CDD-TxHandler-0431(0) */
  else if (PduId > Com_u16IPDUIDMAX)
  {
#if (COM_DEV_ERROR_DETECT == STD_ON)
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_TriggerIPDUSend , COM_E_PARAM);
/* PRQA S 3212 -- */
#endif /*COM_DEV_ERROR_DETECT*/
  }
  else if (u8IPDU_GET_DIR(PduId) != (uint8) Com_u8DIRECTION_TX)
  {
#if (COM_DEV_ERROR_DETECT == STD_ON)
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_TriggerIPDUSend , COM_E_PARAM);
/* PRQA S 3212 -- */
#endif /*COM_DEV_ERROR_DETECT*/
  }
  else
  {
    u16CurrentIPduIx    = u16IPDU_GET_IX(PduId);
    pkstrTxIPduPtr = pkstrGET_TX_IPDU_PTR(u16CurrentIPduIx);
#if (Com_bMDT_SUPPORT == STD_ON)
	u16MDTimerIx = pkstrTxIPduPtr->u16MDTimerIndex;
	if(u16MDTimerIx != (uint16)0xFFFFu)
    {
    pu32MDTimerPtr = pku32GET_MD_TIMER(0);
     /*SchM_Enter_Com_MDT();*/
      if(pu32MDTimerPtr[u16MDTimerIx] != (Com_tu32MDTimer)0)
      {
        bElapsedMDT = FALSE;
      }
      else
      {

        bElapsedMDT = TRUE;
      }
    /* SchM_Exit_Com_MDT();*/
    }
    else
    {
#endif
      bElapsedMDT = TRUE;
#if (Com_bMDT_SUPPORT == STD_ON)
    }
#endif
    if(bElapsedMDT == TRUE)
    {
      /* Com-CDD-0234(0) */
#if (Com_u16NO_OF_TXIPDU_CALLOUT > 0u && (Com_bTX_CALLOUT_SUPPORT == STD_ON))
	 u16IPduCalloutIx = pkstrTxIPduPtr->u16IPduCalloutIndex;
      if(u16IPduCalloutIx != (uint16)0xFFFFu)
      {
		pstrPduInfoPtr = &strPduInfo; 
		pstrPduInfoPtr->SduDataPtr = pu8TXIPDU_GET_BUFF_PTR(pkstrTxIPduPtr->u32IPduBufferIndex);

#if (Com_bDATA_TP_SUPPORT == STD_ON) 
		 bDynamicIPdu = bTPIPduIsDynamic(PduId);

		 if (bDynamicIPdu == TRUE)
	     {
	       u16DynLength = u16GetDynIPduLength(PduId);
	     }
	     else /*bDynamicIPdu == FALSE*/
#endif
	     {
	       u16DynLength = pkstrTxIPduPtr->u16IPduLength;
	     }

		pstrPduInfoPtr->SduLength =  u16DynLength;

       SchM_Enter_Com_IPduBuff();
        /* Call the callout function */
        bCalloutReturn =
            (*(pfTXIPDU_GET_CALOUTPTR(u16IPduCalloutIx)))
                                                           (PduId,
                                                            pstrPduInfoPtr);
       SchM_Exit_Com_IPduBuff();
      }
      else
      {
        bCalloutReturn = TRUE;
      }

      if(bCalloutReturn == TRUE)
      {
#endif

#if (Com_bIPDU_COUNTER_SUPPORT == STD_ON)  	
        if((pkstrTxIPduPtr->u16IPduCounterIndex) != (uint16)0xFFFFu)
		{
          /*! If I-PDU counter is configured for the I-PDU to be sent, \n
           call Com_IpduPackDataSeq service before sending I-PDU via \n
           PduR_ComTransmit. */
          /* Com-CDD-TxHandler-0501(0) */
          Com_vidIpduPackDataSeq(PduId);
        }
#endif
        /*! Send I-PDU */

        /* Com-CDD-TxHandler-0275(0) */
        u8PdurRetVal = Com_u8SendIPdu(PduId, FALSE);
		
		/*! Moved from Com_u8SendIPdu to here to avoid write MDT flag in the middle of MainFunctionTx
		as Com_u8SendIPdu called in Com_MainFunctionTx() */
		#if u16NO_OF_IPDUS_STATUS > 0u
		SchM_Enter_Com_IPduStatus_17();
		Com_audteIPduStatus[PduId] &= (Com_udtIPduStatus)(~Com_u8D_MDT_MASK);
		SchM_Exit_Com_IPduStatus_17();
		#endif
       
#if (Com_bTO_SUPPORT== STD_ON) 

		SchM_Enter_Com_TimeoutTimer();
           pu32TOT = pkstrGET_PB_TIMEOUT_TIMER(0);
           u16TxTOTimerIx = pkstrTxIPduPtr->u16TOTimerIndex;
		 if((u16TxTOTimerIx != (uint16)0xFFFFu)
		   && (pu32TOT[u16TxTOTimerIx] == (uint32)0))
        {
          /*! Reload I-PDU Timeout timer if not running calling \n
          PduR_ComTransmit if bfIPduTimeout == TRUE.*/

          /* Com-CDD-TxHandler-5702(0) */
          pu32TOT[u16TxTOTimerIx] =
		  pkstrTxIPduPtr->u32Timeout;
         SchM_Exit_Com_TimeoutTimer();
        }
        else
        {
         SchM_Exit_Com_TimeoutTimer();
        }
#endif

#if (Com_bUBIT_SUPPORT== STD_ON)   
        if(((u8PdurRetVal == E_OK) &&
           (u8TXIPDU_GET_TYPE(u16CurrentIPduIx) == Com_u8IPDU_TYPE_NORMAL)))
        {
          /* Com-CDD-TxHandler-5735(0) */
          vidIPduClearUBits(PduId);

        }
#endif

		#if u16NO_OF_IPDUS_STATUS > 0u
	   SchM_Enter_Com_IPduStatus_17();
		Com_audteIPduStatus[PduId] |= Com_u8WAIT_CONF;
	   SchM_Exit_Com_IPduStatus_17();
		#endif
		
#if (Com_u16NO_OF_TXIPDU_CALLOUT > 0u && (Com_bTX_CALLOUT_SUPPORT == STD_ON))
      }
      else /* bCalloutReturn == FALSE */
      {
        /* Com-CDD-TxHandler-0059(0) */
        /*! If the I-PDU callout returns false stop processing the I-PDU */
        /* Fix Bug# 50864: Clear TxConfWaitFlags */

	   /* !Deviation: [0277]  ( An Integer Constant experssion with negative value is being converted to an unsigned type)  */
	   /*PRQA S 0277 ++ */
	    
		#if u16NO_OF_IPDUS_STATUS > 0u
	   SchM_Enter_Com_IPduStatus_17();
		Com_audteIPduStatus[PduId] &= (Com_udtIPduStatus)(~(Com_u8WAIT_CONF | Com_u8D_MDT_MASK)); 
	   SchM_Exit_Com_IPduStatus_17();
		#endif
	   /*PRQA S 0277 -- */
      }
#endif

    }
    else /* bElapsedMDT == FALSE */
    {
	  #if u16NO_OF_IPDUS_STATUS > 0u
	 SchM_Enter_Com_IPduStatus_1A();
	  Com_audteIPduStatus[PduId] |= (Com_udtIPduStatus) Com_u8D_MDT_MASK;
	 SchM_Exit_Com_IPduStatus_1A();
	  #endif
    }
  }
} /* Com_TriggerIPDUSend() */
/* PRQA S 4700 -- */
/******************************************************************************/
/*! \Description  By a call to Com_TriggerTransmit The lower layer \n
                  communication module requests the buffer of the SDU for \n
                  transmission from the upper layer module. \n
    \param[in]  TxPduId ID of the SDU that is requested to be transmitted
    \param[in]  PduInfoPtr Contains a pointer to a buffer (SduDataPtr) to  \n
                  where the SDU shall be copied to. On return, the service  \n
                  will indicate the length of the copied SDU data in \n
                  SduLength.
    \return     E_OK: SDU has been copied and SduLength indicates the number \n
                      of copied bytes.
                E_NOT_OK: No SDU has been copied. PduInfoPtr must not be used \n
                          since it may contain a NULL pointer or point to \n
                          invalid data. \n
*******************************************************************************/
/*! \Trace_To   Com-CDD-TxHandler-0120(0),
                Com-CDD-TxHandler-0344(0),
                Com-CDD-TxHandler-0017(0),
                Com-CDD-TxHandler-0436(0),
                Com-CDD-TxHandler-0345(0),
                Com-CDD-TxHandler-0510(0),
                Com-CDD-TxHandler-0347(0),
                Com-CDD-TxHandler-0435(0),
                Com-CDD-TxHandler-0434(0),
                Com-CDD-TxHandler-0433(0),
                Com-CDD-0236(0),
                Com-CDD-0281(0),
                Com-SRS-0240(0),
				Com-CDD-5746(0),
				Com-CDD-5368(1) */
FUNC(Std_ReturnType, COM_CODE) Com_TriggerTransmit(
                        VAR(PduIdType, AUTOMATIC) TxPduId,
                        P2VAR(PduInfoType, AUTOMATIC,COM_APPL_DATA) PduInfoPtr )
{
  /*! Local variables */
  VAR(boolean, AUTOMATIC)     bIPduIsActive;

  VAR(uint8, AUTOMATIC)       u8ReturnValue;

  VAR(uint16, AUTOMATIC)      u16CurrentIPduIx;
  VAR(uint16, AUTOMATIC)      u16CurrentIPduLength;
  VAR(uint16_least, AUTOMATIC)      u16ByteLoopIndex;

  P2VAR(uint8, AUTOMATIC,COM_CALIB_DATA)
                              pu8CurrentIPduBuff;

  P2VAR(uint8, AUTOMATIC, AUTOSAR_COMSTACKDATA)  pu8DataPtr;
  P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF)		 pkTxIPdu;

  /*! DET check and reporting */
#if (COM_DEV_ERROR_DETECT == STD_ON)
  /* Com-CDD-TxHandler-0433(0) */
  if (Com_enueStatus == COM_UNINIT)
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_TriggerTransmit , COM_E_UNINIT);
/* PRQA S 3212 -- */
    u8ReturnValue = E_NOT_OK;
  }
  /* Com-CDD-TxHandler-0434(0) */
  else if (TxPduId > Com_u16IPDUIDMAX)
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_TriggerTransmit , COM_E_PARAM);
/* PRQA S 3212 -- */
    u8ReturnValue = E_NOT_OK;
  }
  else if ((u8IPDU_GET_DIR(TxPduId) != Com_u8DIRECTION_TX) ||
           (u8TXIPDU_GET_TYPE(u16IPDU_GET_IX(TxPduId)) != Com_u8IPDU_TYPE_NORMAL))
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_TriggerTransmit , COM_E_PARAM);
/* PRQA S 3212 -- */
    u8ReturnValue = E_NOT_OK;
  }
  /* Com-CDD-TxHandler-0435(0) */
  else if ((PduInfoPtr == NULL_PTR) || (PduInfoPtr->SduDataPtr == NULL_PTR))
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_TriggerTransmit , COM_E_PARAM_POINTER);
/* PRQA S 3212 -- */
    u8ReturnValue = E_NOT_OK;
  }
  else
#endif /*COM_DEV_ERROR_DETECT*/
  {
    u16CurrentIPduIx        = u16IPDU_GET_IX(TxPduId);
	pkTxIPdu = pkstrGET_TX_IPDU_PTR(u16CurrentIPduIx);
    pu8CurrentIPduBuff      = pu8TXIPDU_GET_BUFF_PTR(pkTxIPdu->u32IPduBufferIndex);
    u16CurrentIPduLength    = u16TXIPDU_GET_LENGTH(u16CurrentIPduIx);
    PduInfoPtr->SduLength   = u16CurrentIPduLength;
  pu8DataPtr = PduInfoPtr->SduDataPtr;
   SchM_Enter_Com_IPduBuff();
    /* Com-CDD-TxHandler-0347(0) */
    /* Com-CDD-0236(0) */
    for(u16ByteLoopIndex = (uint16)0;
        u16ByteLoopIndex < u16CurrentIPduLength;
        u16ByteLoopIndex++)
    {
      pu8DataPtr[u16ByteLoopIndex] = pu8CurrentIPduBuff[u16ByteLoopIndex];
    }
   SchM_Exit_Com_IPduBuff();

#if (Com_bUBIT_SUPPORT== STD_ON)   
    /* Com-CDD-TxHandler-0510(0) */
    vidIPduClearUBits(TxPduId);
#endif
    /* Com-CDD-TxHandler-0345(0) */
	SchM_Enter_Com_IPduStatus_41();
    bIPduIsActive = Com_bIpduCheckActive(TxPduId);
	SchM_Exit_Com_IPduStatus_41();
	
    if(bIPduIsActive == TRUE)
    {
      u8ReturnValue = E_OK;
    }
    else
    {
      u8ReturnValue = E_NOT_OK;
    }
  }

  return u8ReturnValue;
} /* Com_TriggerTransmit() */




static FUNC(void, COM_CODE) vidIPduHandleTMS(P2VAR(tstrSendSignalData,	
									AUTOMATIC, COM_VAR) pkudtSendSignalData)
{
     
  P2VAR(PduIdType, AUTOMATIC,AUTOMATIC)   	pu16SSLCrntIPduId;
  P2CONST(Com_tstrTxMode,AUTOMATIC,TYPEDEF) pkstrTxModePtr;
  P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF) pkstrTxIPduPtr;
  VAR(uint8,AUTOMATIC)						u8CurrentTxProperty;
	/*! Get the current TxMode TRUE or FALSE*/
  pu16SSLCrntIPduId = &pkudtSendSignalData->u16SSLCurrentIPduId;
  pkstrTxIPduPtr = pkstrGET_TX_IPDU_PTR(pkudtSendSignalData->u16SSLCurrentIPduIx);
  
  #if u16NO_OF_IPDUS_STATUS > 0u
  pkudtSendSignalData->bSSLCurrentTxMode = ((Com_audteIPduStatus[*pu16SSLCrntIPduId] & Com_u8CURR_TX_MO_FLG) != FALSE);
  #endif
  
  
  /*! Get the current TxMode Type and Index*/
  if(pkudtSendSignalData->bSSLCurrentTxMode == TRUE)
  {
    
	pkstrTxModePtr = u8IPDU_GET_TXMODE_PTR(pkstrTxIPduPtr->u16TxModeTrueIndex);
	pkudtSendSignalData->u8SSLCurrentTxModeType  = pkstrTxModePtr->u8TxMode;
    pkudtSendSignalData->u16SSLCurrentTxModeIx = pkstrTxModePtr->u16Index;
  }
  else
  /*bCurrentTxMode == FALSE*/
  {
    pkstrTxModePtr = u8IPDU_GET_TXMODE_PTR(pkstrTxIPduPtr->u16TxModeFalseIndex);
	pkudtSendSignalData->u8SSLCurrentTxModeType  = pkstrTxModePtr->u8TxMode;
    pkudtSendSignalData->u16SSLCurrentTxModeIx = pkstrTxModePtr->u16Index;
  }
  
	/*Com-CDD-TxHandler-0022(0)*/
	/*! this Function is used to get Evalute New Tx Mode depeneding on the Signal/Signal groups 
		filtering results that calcauted above*/
	pkudtSendSignalData->bSSLNewTxMode =
                  Com_bEvaluateTxMode(pkudtSendSignalData->u16SSLCurrentIPduId);

	 /*! get New Tx Mode Index and type*/
	 /*! this If  may be commented we don't need this step we wait to be tested*/
	 if(pkudtSendSignalData->bSSLNewTxMode == TRUE)
	  {
		pkstrTxModePtr = u8IPDU_GET_TXMODE_PTR(pkstrTxIPduPtr->u16TxModeTrueIndex);
		pkudtSendSignalData->u8SSLNewTxModeType  = pkstrTxModePtr->u8TxMode;
		pkudtSendSignalData->u16SSLNewTxModeIndex = pkstrTxModePtr->u16Index;
      }
      else
      /*bNewTxMode == FALSE*/
      {
		pkstrTxModePtr = u8IPDU_GET_TXMODE_PTR(pkstrTxIPduPtr->u16TxModeFalseIndex);
		pkudtSendSignalData->u8SSLNewTxModeType  = pkstrTxModePtr->u8TxMode;
		pkudtSendSignalData->u16SSLNewTxModeIndex = pkstrTxModePtr->u16Index;
      }
	  
      /* TM switch happened*/
      if(pkudtSendSignalData->bSSLNewTxMode !=
                                          pkudtSendSignalData->bSSLCurrentTxMode)
      {
        pkudtSendSignalData->bSSLTMSwitchHappened = TRUE;
        /*! If the call of Com_EvaluateTxMode returned TRUE, set the current \n
        TxMode flag for the I-PDU to TRUE. If on the other hand the \n
        call of Com_EvaluateTxMode returned FALSE, set the current TxMode \n
        flag for the I-PDU to FALSE.  */
        /* Com-CDD-TxHandler-0286(0) */
        /* Com-CDD-TxHandler-0024(0) */
		/*Com-CDD-TxHandler-0322(0)*/
		#if u16NO_OF_IPDUS_STATUS > 0u
		SchM_Enter_Com_IPduStatus_19();
		Com_audteIPduStatus[*pu16SSLCrntIPduId] ^= Com_u8CURR_TX_MO_FLG;
		SchM_Exit_Com_IPduStatus_19();
		#endif
      }
      else
      {
        pkudtSendSignalData->bSSLTMSwitchHappened = FALSE;
      }
	  
 if(pkudtSendSignalData->bSSLTMSwitchHappened == FALSE)
  {
    pkudtSendSignalData->u8SSLNewTxModeType   =
                                    pkudtSendSignalData->u8SSLCurrentTxModeType;
    pkudtSendSignalData->u16SSLNewTxModeIndex =
                                      pkudtSendSignalData->u16SSLCurrentTxModeIx;
  }
  
  /*! add this part to fix Bug of TM is switched to Mixed mode by Pending signal 
	and anither request by trigger signal*/
  if((pkudtSendSignalData->bSSLTMSwitchHappened == TRUE) && 
		(pkudtSendSignalData->u8SSLNewTxModeType == Com_u8TX_MODE_MIXED))
	{	
		if(pkudtSendSignalData->u8SSLSigStructType == (uint8) Com_u8SIG_STRUCT_SIG)
		{
			u8CurrentTxProperty = u8SIG_GET_TX_PROP(pkudtSendSignalData->u16SSLCurrentSigIx);
		}
		else /*! Desc signal*/
		{
			u8CurrentTxProperty = u8DSTDESC_GET_TX_PROP(pkudtSendSignalData->u16SSLCurrentSigIx);
		}
		
		if(u8CurrentTxProperty == Com_u8TXPROP_PENDING)
		{	
			pkudtSendSignalData->u8SSLCurrentTxProperty = Com_u8TXPROP_PENDING;
		}
	}
}
/* !Deviation: [8019] and [8519]  the following MACRO is required by AUTOSAR */
/* PRQA S 8019 ++ */
/* PRQA S 8519 ++ */

/* !Deviation: [0838] Multiple Memmap.h inclusion is implied by AUTOSAR */
/* PRQA S 838 ++ */
/* PRQA S  5087 L1 */
#define COM_STOP_SEC_CODE
#include "Memmap.h"
/* PRQA L:L1 */
/* PRQA S 838 -- */
/* PRQA S 8019 -- */
/* PRQA S 8519 -- */
/* PRQA S 0790 -- */
/* PRQA S 0850 -- */

/** \} */ /* end of Com module group */
