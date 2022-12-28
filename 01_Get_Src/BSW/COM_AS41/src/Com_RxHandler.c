/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : Com                                                     */
/* !Description     : AUTOSAR Communication Module                            */
/*                                                                            */
/* !Module          : Com_RxHandler                                           */
/* !Description     : Module responsible for the receiption part of the COM   */
/*                                                                            */
/* !File            : Com_RxHandler.c                                         */
/*                                                                            */
/* !Scope           : Public                                                  */
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
/* $Archive::   Y:/B791130I0\02_Modules\03_Com\02_Development\02_Source_Code  */
/*              \02_Source_Files\                                            $*/
/* $Revision::   1.133     $$Author::   ametwelly      $$Date::   Aug 24 2014$*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/*******************************************************************/


/*****************************************************************************/
/*! \file
*
* \par
*   Internals of the module Com. \n
*   This file contains the internals of the module Com.  */
/*****************************************************************************/

/******************************************************************************/
/*! \defgroup module Com
* This is the grouping of the Com module members.
* \{
*/
/******************************************************************************/
#include "Com.h"
#include "Com_Internal.h"
#include "Com_Cfg.h"
#include "Com_LCfg.h"
#include "SchM_Com.h"

#if (COM_DEV_ERROR_DETECT == STD_ON)
  #include "Det.h"
#endif

/******************************************************************************/

/* Intermodule Version Checking                                              */

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
#if (DET_AR_RELEASE_MINOR_VERSION != COM_AR_RELEASE_MINOR_VERSION)
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

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/******************************************************************************/
/*                       Macro Definitions                                    */
/******************************************************************************/

/* !Deviation: [3453]  the following functions like macros , helps to increase 
the readability of the code ,by accessing the required configuration parameter 
, through a macro . Macros were used instead of functions in order to increase
 the code performance  by reducing the time required by the context switching*/
/* PRQA S 3453 ++ */

/*Macro to get a pointer of a specific RX Ipdu Identified by a certain Ipdu ID*/
#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_RX_IPDU_PTR(u16PduId) \
(&(Com_pkstreMainConfig->pkstrRxIPdu[(Com_pkstreMainConfig->pkstrIPduLookUp[\
(u16PduId)].u16Index)]))
#else

#define pkstrGET_RX_IPDU_PTR(u16PduId) \
(&(akstrRxIPdu[(akstrIPduLookUp[(u16PduId)].u16Index)]))
#endif


#if (Com_u16NO_OF_IPDU_REPLIC > 0u)
#define pu8GET_RX_IPDU_1ST_REP(u16IpduReplicasBuffIx) \
(&Com_au8eReplicasBuffer[(u16IpduReplicasBuffIx)])
#else
#define pu8GET_RX_IPDU_1ST_REP(u16IpduReplicasBuffIx) \
	(P2VAR(uint8,AUTOMATIC,TYPEDEF))NULL_PTR
#endif


#if Com_u16NO_OF_RXIPDU_CALLOUT > 0u
#define pfGET_RXIPDU_CALOUTPTR(u16IpduCalloutsIx) \
Com_akpfbeRxIPduCalloutPtrs[u16IpduCalloutsIx]
#else
#define pfGET_RXIPDU_CALOUTPTR(u16IpduCalloutsIx) NULL_PTR
#endif


#if Com_u16NO_OF_SIGNAL > 0u
#define pfSIG_INVALID_CBK(u16SigIx) \
(Com_akstreSignalLT[(u16SigIx)].pfvidInvalidNotification)
#else
#define pfSIG_INVALID_CBK(u16SigIx) FALSE
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define u8GET_IPDU_DIR(u16IpduId) \
(Com_pkstreMainConfig->pkstrIPduLookUp[(u16IpduId)].u8Direction)
#else
#define u8GET_IPDU_DIR(u16IpduId) \
(akstrIPduLookUp[(u16IpduId)].u8Direction)
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define u8GET_SIG_STRUCT_TYPE(u16SigId) \
(Com_pkstreMainConfig->pkstrSignalLookUp[(u16SigId)].u8StructureType)
#else
#define u8GET_SIG_STRUCT_TYPE(u16SigId) \
(akstrSignalLookUp[(u16SigId)].u8StructureType)
#endif


#define u8GET_SIG_DIR(u16SigId) \
((Com_pkstreMainConfig->pkstrSignalPB[Com_pkstreMainConfig->pkstrSignalLookUp[\
(u16SigId)].u16Index].udteSignalFlags & Com_u8SIGNAL_DIRECTION) != FALSE)

/*! Macro to define if an RX IPDU has a configured TimeOut*/

#if Com_u16NO_OF_SIGNAL > 0u
#define u16GET_SIG_ID_FROM_IX(u16SigIx)  \
Com_akstreSignalLT[(u16SigIx)].u16SignalId
#else
#define u16GET_SIG_ID_FROM_IX(u16SigIx) 0u
#endif

#define pkstrGET_PB_GRP_SIG_PTR(u16SigId) \
(&( Com_pkstreMainConfig->pkstrGroupSignalPB[Com_pkstreMainConfig->\
pkstrSignalLookUp[(u16SigId)].u16Index]))

/*Macro to get the number of group signal inside a signal group identified by
Signal Group ID*/
#if (Com_bPB_VARIANT == STD_ON)
#define u16GET_NB_OF_GRPSIG(u16SigGrpId) \
Com_pkstreMainConfig->pkstrSignalGroupPB[(u16SigGrpId)].u16NoOfGroupSignals
#else
#define u16GET_NB_OF_GRPSIG(u16SigGrpId) \
akstrSignalGroupPB[(u16SigGrpId)].u16NoOfGroupSignals
#endif

/*!  \Description  MACRO used to get u16GroupSignalIndex member of
SignalGroup */
#if (Com_bPB_VARIANT == STD_ON)
#define u16GET_GRP_SIG_IX(u16SigGrpId) \
Com_pkstreMainConfig->pkstrSignalGroupPB[(u16SigGrpId)].u16GroupSignalIndex
#else
#define u16GET_GRP_SIG_IX(u16SigGrpId) \
akstrSignalGroupPB[(u16SigGrpId)].u16GroupSignalIndex
#endif
/*Macro to get a pointer of a specific Signal Group Identified by a certain ID*/
#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PB_SIGGRP_PTR(u16SigGrpId) \
(&( Com_pkstreMainConfig->pkstrSignalGroupPB[(u16SigGrpId)]))
#else
#define pkstrGET_PB_SIGGRP_PTR(u16SigGrpId) \
(&( akstrSignalGroupPB[(u16SigGrpId)]))
#endif


/*Macro to define the type of the IPDU */
#if (Com_bPB_VARIANT == STD_ON)
#define u8GET_RX_IPDU_TYPE(u16IpduId) \
((uint8)(Com_pkstreMainConfig->pkstrRxIPdu[(Com_pkstreMainConfig->\
pkstrIPduLookUp[(u16IpduId) ].u16Index)].udteRxIPduFlags & Com_u8RX_IPDUTYPE_MASK) != FALSE)
#else

#define u8GET_RX_IPDU_TYPE(u16IpduId) \
((uint8)(akstrRxIPdu[(akstrIPduLookUp[(u16IpduId)].u16Index)].udteRxIPduFlags & Com_u8RX_IPDUTYPE_MASK) != FALSE)
#endif

#if Com_u16NO_OF_GROUP_SIGSLT > 0u
#define u16GET_U8N_GRPSIG_LEN(u16SigIx)\
Com_akstreGroupSignalLT[(u16SigIx)].u16SignalLength
#else
#define u16GET_U8N_GRPSIG_LEN(u16SigIx) 0u
#endif

#if Com_u16NO_OF_SIGNAL_GROUPSLT > 0u
#define pfSIGGRP_INVALID_CBK(u16SigGroupId) \
(Com_akstreSignalGroupLT[(u16SigGroupId)].pfvidInvalidNotification)
#else
#define pfSIGGRP_INVALID_CBK(u16SigId) FALSE
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define u8GET_GRPSIG_DIR(u16SigId) \
((Com_pkstreMainConfig->pkstrGroupSignalPB[Com_pkstreMainConfig->\
pkstrSignalLookUp[(u16SigId)].u16Index].udteGroupSignalFlags & Com_u8GRPSIGNAL_DIRECTION) != FALSE)
#else
#define u8GET_GRPSIG_DIR(u16SigId) \
((akstrGroupSignalPB[akstrSignalLookUp[(u16SigId)].u16Index].udteGroupSignalFlags & Com_u8GRPSIGNAL_DIRECTION) != FALSE)
#endif


/*Macro to get a pointer of a specific RX Ipdu Identified by a certain Ipdu ID*/
#if (Com_bPB_VARIANT == STD_ON)
#define u16GET_RX_IPDU_ID(u16PduIx) \
(Com_pkstreMainConfig->pkstrRxIPdu[u16PduIx].u16IPduId)

#else
#define u16GET_RX_IPDU_ID(u16PduIx) \
		(akstrRxIPdu[u16PduIx].u16IPduId)
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



#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PB_SIGNAL_PTR(u16SigId) \
(&(Com_pkstreMainConfig->pkstrSignalPB[Com_pkstreMainConfig->\
pkstrSignalLookUp[(u16SigId)].u16Index]))
#else
#define pkstrGET_PB_SIGNAL_PTR(u16SigId) \
(&(akstrSignalPB[akstrSignalLookUp[(u16SigId)].u16Index]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PBSIGPTR_IX(u16SigIx) \
(&(Com_pkstreMainConfig->pkstrSignalPB[u16SigIx]))
#else
#define pkstrGET_PBSIGPTR_IX(u16SigIx) \
(&(akstrSignalPB[u16SigIx]))
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define u16GET_SIGAL_INDEX(u16SigId) \
		(Com_pkstreMainConfig->pkstrSignalLookUp[u16SigId].u16Index)
#else
#define u16GET_SIGAL_INDEX(u16SigId) \
	     (akstrSignalLookUp[(u16SigId)].u16Index)
#endif


#define u16GET_U8N_SIGNAL_LEN(u16SigIx) \
		(Com_akstreSignalLT[u16SigIx].u16SignalLength)
		
		
#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_RX_IPDU_PTR_IX(u16Index) \
		(&(Com_pkstreMainConfig->pkstrRxIPdu[u16Index]))
#else
#define pkstrGET_RX_IPDU_PTR_IX(u16Index) \
	     (&(akstrRxIPdu[u16Index]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_IPDU_LOOK_UP_PTR(u16Index) \
		(&(Com_pkstreMainConfig->pkstrIPduLookUp[u16Index]))
#else
#define pkstrGET_IPDU_LOOK_UP_PTR(u16Index) \
	     (&(akstrIPduLookUp[u16Index]))
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_IPDU_SGL_MAP_PTR(u16Index) \
		(&(Com_pkstreMainConfig->pkstrIPduToSignalMapping[u16Index]))
#else
#define pkstrGET_IPDU_SGL_MAP_PTR(u16Index) \
	     (&(akstrIPduToSignalMapping[u16Index]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_GW_SIG_MAPP_PTR(u16GWSigMap) \
		(&(Com_pkstreMainConfig->pkstrGWSignalMapping[u16GWSigMap]))
#else
#if u16NO_OF_GW_PATHS > 0u
#define pkstrGET_GW_SIG_MAPP_PTR(u16GWSigMap) \
	     (&(akstrGWSignalMapping[u16GWSigMap]))
#else
#define pkstrGET_GW_SIG_MAPP_PTR(u16GWSigMap) \
		(P2CONST(Com_tstrGWSignalMapping,AUTOMATIC,TYPEDEF))NULL_PTR	
#endif
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_IPDU_BUFF_PTR(u16IPduBufferIx) \
(&(Com_pkstreMainConfig->pu8IPduBuffer[(u16IPduBufferIx)]))
#else
#define pkstrGET_IPDU_BUFF_PTR(u16IPduBufferIx) \
(&(Com_au8IPduBuffer[(u16IPduBufferIx)]))
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define u16GET_IPDU_INDEX(u16IPduIx) \
		(Com_pkstreMainConfig->pkstrIPduLookUp[(u16IPduIx)].u16Index)
#else
#define u16GET_IPDU_INDEX(u16IPduIx) \
	     (akstrIPduLookUp[(u16IPduIx)].u16Index)
#endif

#define pkstrGET_RX_IPDU_REP_PTR(u16IPduReplicasIx) \
		(&(Com_akstreIPduReplication[(u16IPduReplicasIx)]))


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
#define pkstrGET_PBSRC_DESCPTR_IX(u16SigIx) \
(&( Com_pkstreMainConfig->pkstrGWSrcDesc[(u16SigIx)]))
#else
#if u16NO_OF_GW_SRC_DESC > 0u  
#define pkstrGET_PBSRC_DESCPTR_IX(u16SigIx) \
(&(akstrGWSrcDesc[(u16SigIx)]))
#else
#define pkstrGET_PBSRC_DESCPTR_IX(u16SigIx) \
	(P2CONST(Com_tstrGWSrcDesc,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_TP_IPDU_CTR_PTR(u16TpIpduCtrIx) \
(&(Com_pkstreMainConfig->pu16TpByteCounter[(u16TpIpduCtrIx)]))
#else
#if u16NO_OF_TP_IPDU > 0u
#define pkstrGET_TP_IPDU_CTR_PTR(u16TpIpduCtrIx) \
(&(Com_au16TpByteCounter[(u16TpIpduCtrIx)]))
#else
#define  pkstrGET_TP_IPDU_CTR_PTR(u16TpIpduCtrIx) \
	(P2VAR(uint16,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PBGRPSIGPTR_IX(u16SigIx) \
(&( Com_pkstreMainConfig->pkstrGroupSignalPB[(u16SigIx)]))
#else
#define pkstrGET_PBGRPSIGPTR_IX(u16SigIx) \
(&(akstrGroupSignalPB[(u16SigIx)]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define u8GET_PB_GRP_SIG_TYPE(u16SigIx) \
(Com_pkstreMainConfig->pkstrGroupSignalPB[(u16SigIx)].u8SignalType)
#else
#define u8GET_PB_GRP_SIG_TYPE(u16SigIx) \
(akstrGroupSignalPB[(u16SigIx)].u8SignalType)
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkbGET_SIGINIT_VALUEB(u16SigInitValIx) \
	(&(Com_pkstreMainConfig->pkbSignalInitValueB[(u16SigInitValIx)]))
#else
#if u16NO_OF_SIG_B > 0u
#define pkbGET_SIGINIT_VALUEB(u16SigInitValIx) \
		(&(aku8SignalInitValueB[(u16SigInitValIx)]))
#else
#define pkbGET_SIGINIT_VALUEB(u16SigInitValIx) \
		(P2CONST(boolean,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pku8GET_SIGINIT_VALU8U8N(u16SigInitValIx) \
	(&(Com_pkstreMainConfig->pku8SignalInitValueU8U8N[(u16SigInitValIx)]))
#else
#if u16NO_OF_SIG_U8U8N > 0u
#define pku8GET_SIGINIT_VALU8U8N(u16SigInitValIx) \
		(&(aku8SignalInitValueU8U8N[(u16SigInitValIx)]))
#else
#define pku8GET_SIGINIT_VALU8U8N(u16SigInitValIx) \
		(P2CONST(uint8,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define pks8GET_SIGINIT_VALUES8(u16SigInitValIx) \
	(&(Com_pkstreMainConfig->pks8SignalInitValueS8[(u16SigInitValIx)]))
#else
#if u16NO_OF_SIG_S8 > 0u
#define pks8GET_SIGINIT_VALUES8(u16SigInitValIx) \
		(&(aks8SignalInitValueS8[(u16SigInitValIx)]))
#else
#define pks8GET_SIGINIT_VALUES8(u16SigInitValIx) \
		(P2CONST(sint8,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define pku16GET_SIGINIT_VALUEU16(u16SigInitValIx) \
	(&(Com_pkstreMainConfig->pku16SignalInitValueU16[(u16SigInitValIx)]))
#else
#if u16NO_OF_SIG_U16 > 0u
#define pku16GET_SIGINIT_VALUEU16(u16SigInitValIx) \
		(&(aku16SignalInitValueU16[(u16SigInitValIx)]))

#else
#define pku16GET_SIGINIT_VALUEU16(u16SigInitValIx) \
		(P2CONST(uint16,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define pks16GET_SIGINIT_VALUES16(u16SigInitValIx) \
	(&(Com_pkstreMainConfig->pks16SignalInitValueS16[(u16SigInitValIx)]))
#else
#if u16NO_OF_SIG_S16 > 0u
#define pks16GET_SIGINIT_VALUES16(u16SigInitValIx) \
		(&(aks16SignalInitValueS16[(u16SigInitValIx)]))
#else
#define pks16GET_SIGINIT_VALUES16(u16SigInitValIx) \
		(P2CONST(sint16,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pku32GET_SIGINIT_VALUEU32(u16SigInitValIx) \
	(&(Com_pkstreMainConfig->pku32SignalInitValueU32[(u16SigInitValIx)]))
#else
#if u16NO_OF_SIG_U32 > 0u
#define pku32GET_SIGINIT_VALUEU32(u16SigInitValIx) \
		(&(aku32SignalInitValueU32[(u16SigInitValIx)]))
#else
#define pku32GET_SIGINIT_VALUEU32(u16SigInitValIx) \
		(P2CONST(uint32,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pks32GET_SIGINIT_VALUES32(u16SigInitValIx) \
	(&(Com_pkstreMainConfig->pks32SignalInitValueS32[(u16SigInitValIx)]))
#else
#if u16NO_OF_SIG_S32 > 0u
#define pks32GET_SIGINIT_VALUES32(u16SigInitValIx) \
		(&(aks32SignalInitValueS32[(u16SigInitValIx)]))
#else
#define pks32GET_SIGINIT_VALUES32(u16SigInitValIx) \
		(P2CONST(sint32,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define pkf32GET_SIGINIT_VALUEF32(u16SigInitValIx) \
	(&(Com_pkstreMainConfig->pkf32SignalInitValueF32[(u16SigInitValIx)]))
#else
#if u16NO_OF_SIG_F32 > 0u
#define pkf32GET_SIGINIT_VALUEF32(u16SigInitValIx) \
		(&(akf32SignalInitValueF32[(u16SigInitValIx)]))
#else
#define pkf32GET_SIGINIT_VALUEF32(u16SigInitValIx) \
		(P2CONST(float32,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkf64GET_SIGINIT_VALUEF64(u16SigInitValIx) \
	(&(Com_pkstreMainConfig->pkf64SignalInitValueF64[(u16SigInitValIx)]))
#else
#if u16NO_OF_SIG_F64 > 0u
#define pkf64GET_SIGINIT_VALUEF64(u16SigInitValIx) \
		(&(akf64SignalInitValueF64[(u16SigInitValIx)]))
#else
#define pkf64GET_SIGINIT_VALUEF64(u16SigInitValIx) \
		(P2CONST(float64,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif



/* PRQA S 3453 -- */
typedef struct 
{
  VAR(uint16,AUTOMATIC)   u16SignlID ;
  VAR(uint16,AUTOMATIC)   u16SignlIx ;            
  VAR(uint8 , AUTOMATIC)  u8SigStructType;
  VAR(uint16,AUTOMATIC)   u16SigUBIx;                            
  /* !Deviation:[3672]  (Using non-const pointer to function.)
  the pointer to function can not be declared as constant , as it will
  be assigned a value calculated by the code depending on the PduId*/
  /*PRQA S 3672 ++ */
  VAR(Com_tpfvidSigInvalidNotif,AUTOMATIC)  pfvidInValidNot;  
  /*PRQA S 3672 -- */
}tstrProcessSig ; 

/******************************************************************************/
/* !Deviation: [8019]  ( The name of " symbolic constants " (#define) 
Identifiers does not  respect the naming conventions.) */
/*[8519](The Type of " symbolic constants " (#define) Identifiers does not  
respect the naming conventions.)*/
/*this #define is imposed by the AUTOSAR MemMap file , required for memory 
abstraction*/
/*PRQA S 8019 ,8519 ++ */
/* PRQA S  5087 L1 */
#define COM_START_SEC_CODE
/*PRQA S 8019 ,8519 -- */
#include "MemMap.h"
/* PRQA L:L1 */

#if (Com_bRX_REPLICAS_SUPPORT == STD_ON)
static FUNC(Com_tpku8MaxCalibDataConstPtr ,COM_CODE) pku8VoteIpdu (
P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)       pku8IpduOneFirstByte ,
P2CONST(uint8,AUTOMATIC,COM_CALIB_DATA)       pku8IpduTwoFirstByte ,
P2CONST(uint8,AUTOMATIC,COM_CALIB_DATA)       pku8IpduThreeFirstByte ,
VAR(uint16 ,AUTOMATIC)                       u16IpduLength,
VAR(uint8, AUTOMATIC)                        u8Quorum);
#endif

#if (Com_bRX_REPLICAS_SUPPORT == STD_ON)
static FUNC(boolean,COM_CODE) bCompare2u8Arrays (
P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)       pku8FirstArray ,
P2CONST(uint8,AUTOMATIC,COM_APPL_DATA)       pku8SecondArray ,
VAR(uint16 ,AUTOMATIC)                       u16CmpLength) ;
#endif


static FUNC(void,COM_CODE) vidProcessRxIpdu (
VAR(uint16,AUTOMATIC)                             u16IpduIx ,
P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)            pku8OrgIpduFirstByte );

static FUNC(void,COM_CODE) vidIpduProcessDM (
VAR(uint16,AUTOMATIC)                   u16RxPduIx) ;

#if((Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
static FUNC(void , COM_CODE) vidInitSigGroupObj (
                  VAR(Com_SignalGroupIdType,AUTOMATIC)       u16SignalGroupId);
#endif                  
                    
#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
static FUNC(void,COM_CODE) vidCopySigShadow2Obj(
                  VAR(Com_SignalGroupIdType,AUTOMATIC)       u16SignalGroupId);
#endif

#if ((Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))                
static FUNC(uint8,COM_CODE) u8ProcessRxSigGrp(
        VAR(uint16,AUTOMATIC) u16SigGrpID ,
        P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) PduInfoPtr);
#endif
        
static FUNC(uint8,COM_CODE) u8ProcessRxSig(
        P2CONST(tstrProcessSig,AUTOMATIC,COM_APPL_DATA)  pkstrProcessSigData,
        P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)   PduInfoPtr);                                             

#if((Com_u16NO_OF_IPDU_REPLIC > 0u) && (Com_bRX_REPLICAS_SUPPORT == STD_ON))
static FUNC(void,COM_CODE) vidHandleIpduReplicas(
VAR(PduIdType,AUTOMATIC)                     u16RxPduId ,
P2CONST(PduInfoType,AUTOMATIC,COM_APPL_DATA) pkstrPduInfoPtr ) ;
#endif 
/******************************************************************************/
/* !Deviation: [4700]  ( here has been an infringement of a threshold on the
     specified metric)
 Further decomposition of this function will affect its overall performance 
 so no other meaningfull division is required*/
 /*  PRQA S 4700 ++ */   

/* !Deviation: [8023]  (The name of the function does not  respect the naming 
conventions.) */
/*function names are mandated by AUTOSAR*/
/*PRQA S 8023 ++ */
/* !Deviation: [3205]  ( Some of the local varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S 3205,3203 ++ */
/*************************************************************************/
/*! \Description:                \n

**************************************************************************/
/*! \Trace_To : Com-CDD-0205(0) , Com-CDD-RxHandler-0004(0), Com-CDD-RxHandler-0478(0) , 
Com-CDD-RxHandler-0491(0) ,Com-CDD-RxHandler-0490(0), 
Com-CDD-RxHandler-0479(0) , Com-CDD-RxHandler-0500(0) , Com-CDD-0204(0)*/
/* !Deviation: [3673]  (The pointer is Modified in the normal case  but in some special
 Configurations it will not be modified but it's not a pointer to const .) */
 /*PRQA S 3673 ++ */
FUNC(uint8,COM_CODE) Com_ReceiveSignal (
     VAR(Com_SignalIdType, AUTOMATIC)    SignalId,
     P2VAR(void,AUTOMATIC,COM_APPL_DATA) SignalDataPtr )
/*PRQA S 8023 -- */
{
  VAR(uint8, AUTOMATIC)                                 u8RxSignalReturn ;
/* !Deviation: [8018]  (The name of the constant (const) does not  respect the 
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) does not  respect the 
naming conventions.)*/
/*[8518] (The Separator of the constant (const) does not  respect the naming
 conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318 , 8518 ++ */
  P2CONST(Com_tstrSignalPB,AUTOMATIC,COM_CALIB_CONST)   pkstrLocSigPB;
  VAR(uint16,AUTOMATIC)                                 u16SigByteLen;
  VAR(uint16_least,AUTOMATIC)                           u16SigLoopIx;  
  VAR(uint16,AUTOMATIC)                                 u16SigIx;
/*PRQA S 8018 , 8318 , 8518 -- */
  

#if (Com_u16NO_OF_SIGNAL> 0u )  
  P2VAR(uint8,AUTOMATIC,TYPEDEF)pu8SigObjU8U8N;
  P2CONST(uint16, AUTOMATIC, AUTOMATIC) pku16SigObjIdx;
  P2VAR(boolean,AUTOMATIC,TYPEDEF)pbSigObjB;
  P2VAR(sint8,AUTOMATIC,TYPEDEF)ps8SigObjS8;
  P2VAR(uint16,AUTOMATIC,TYPEDEF)pu16SigObjU16;
  P2VAR(sint16,AUTOMATIC,TYPEDEF)ps16SigObjS16;
  P2VAR(uint32,AUTOMATIC,TYPEDEF)pu32SigObjU32;
  P2VAR(sint32,AUTOMATIC,TYPEDEF)ps32SigObjS32;
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON)
  P2VAR(float32,AUTOMATIC,TYPEDEF)pf32SigObjF32;
  P2VAR(float64,AUTOMATIC,TYPEDEF)pf64SigObjF64;
#endif
#endif

  u8RxSignalReturn = COM_SERVICE_NOT_AVAILABLE ;

  if ( SignalDataPtr ==  NULL_PTR )
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
    #endif
  }
  else if (Com_enueStatus == COM_UNINIT)
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
    #endif
  }
  else if ((SignalId > Com_u16SIGNALIDMAX)||
          (u8GET_SIG_STRUCT_TYPE(SignalId) != (uint8)Com_u8SIG_STRUCT_SIG)
          /*IE Requirement to read the TX signal Objects*/
          /*
          ||
          (u8GET_SIG_DIR(SignalId)!= Com_u8SIG_DIR_RECEIVE) */
         )
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM);
    #endif
  }
  else
  {
  #if (Com_u16NO_OF_SIGNAL> 0u )   
  /*No Development Error occured , i.e Normal operation*/
    u16SigIx    = u16GET_SIGAL_INDEX(SignalId);
    pkstrLocSigPB = pkstrGET_PBSIGPTR_IX(u16SigIx);

	pku16SigObjIdx = &(pkstrLocSigPB->u16SignalObjectIndex); 
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
    /*fill the content of the SignalDataPtr with the corresponding signal object data */
    /*last known value will be returned , or its init value , even for a stopped Ipdu */
    switch (pkstrLocSigPB->u8SignalType)
    {
      case Com_u8SIGNAL_TYPE_BOOLEAN:
      *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =
      pbSigObjB[*pku16SigObjIdx];
      break;

      case Com_u8SIGNAL_TYPE_UINT8:
      *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =
      pu8SigObjU8U8N[*pku16SigObjIdx];
      break;

      case Com_u8SIGNAL_TYPE_SINT8:
      *(P2VAR(sint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =
      ps8SigObjS8[*pku16SigObjIdx];
      break;

      case Com_u8SIGNAL_TYPE_UINT16:
      SchM_Enter_Com_SigObjU16_0b();
      *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =
      pu16SigObjU16[*pku16SigObjIdx];
      SchM_Exit_Com_SigObjU16_0b();
      break;

      case Com_u8SIGNAL_TYPE_SINT16:
      SchM_Enter_Com_SigObjS16_0b();
      *(P2VAR(sint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =
      ps16SigObjS16[*pku16SigObjIdx];
      SchM_Exit_Com_SigObjS16_0b();
      break;

      case Com_u8SIGNAL_TYPE_UINT32:
      SchM_Enter_Com_SigObjU32_0b();
      *(P2VAR(uint32,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =
      pu32SigObjU32[*pku16SigObjIdx];
      SchM_Exit_Com_SigObjU32_0b();
      break;
      case Com_u8SIGNAL_TYPE_SINT32:
      SchM_Enter_Com_SigObjS32_0b();
      *(P2VAR(sint32,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =
      ps32SigObjS32[*pku16SigObjIdx];
      SchM_Exit_Com_SigObjS32_0b();
      break;
	  
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON)
      case Com_u8SIGNAL_TYPE_FLOAT32:
      SchM_Enter_Com_SigObjF32_0b();
      *(P2VAR(float32,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =
      pf32SigObjF32[*pku16SigObjIdx];
      SchM_Exit_Com_SigObjF32_0b();
      break;

      case Com_u8SIGNAL_TYPE_FLOAT64:
      SchM_Enter_Com_SigObjF64_0b();
      *(P2VAR(float64,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =
      pf64SigObjF64[*pku16SigObjIdx];
      SchM_Exit_Com_SigObjF64_0b();
      break;
#endif

      case Com_u8SIGNAL_TYPE_UINT8N:
      SchM_Enter_Com_SigObjU8U8N_0b();
	  u16SigByteLen =  u16GET_U8N_SIGNAL_LEN(u16SigIx);
	  for (u16SigLoopIx = 0 ; u16SigLoopIx < u16SigByteLen ; u16SigLoopIx++)
      {          
        ((P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr)[u16SigLoopIx] =
        pu8SigObjU8U8N[(*pku16SigObjIdx) + u16SigLoopIx];
      }
      SchM_Exit_Com_SigObjU8U8N_0b();
      break;         

      default:
      u8RxSignalReturn = E_NOT_OK ;
      break;
    }
    /*check if the signal belong to a stopped Ipdu*/
	#if u16NO_OF_IPDUS_STATUS > 0u
	SchM_Enter_Com_IPduStatus_0B();
    if (Com_vidIPDUCHECKACTIVE(pkstrLocSigPB->u16IPduIndex) != 0)
    {
      u8RxSignalReturn = E_OK ;
    }
	SchM_Exit_Com_IPduStatus_0B();
	#endif

  #endif
  }
   
  return  u8RxSignalReturn ;
}
/*PRQA S 3673 -- */
/*PRQA S 3205,3203 -- */
 /*  PRQA S 4700 -- */
/******************************************************************************/
/* !Deviation: [4700]  ( here has been an infringement of a threshold on the
     specified metric)
 Further decomposition of this function will affect its overall performance 
 so no other meaningfull division is required*/
 /*  PRQA S 4700 ++ */  

/* !Deviation: [8023]  (The name of the function does not  respect the naming conventions.) */
/*function names are mandated by AUTOSAR*/
/*PRQA S 8023 ++ */
/*************************************************************************/
/*! \Description:                \n

**************************************************************************/
 /*! \Trace_To : Com-CDD-RxHandler-0068(0) , 
Com-CDD-RxHandler-0482(0) , Com-CDD-RxHandler-0498(0) ,
Com-CDD-RxHandler-0499(0) , Com-CDD-RxHandler-0483(0) ,
Com-CDD-RxHandler-0467(0) , Com-CDD-RxHandler-0469(0) ,
Com-CDD-RxHandler-0474(0) , Com-CDD-RxHandler-0476(0) ,
Com-CDD-RxHandler-0518(0) , Com-CDD-RxHandler-0464(0) ,
Com-CDD-0258(0) , Com-CDD-0259(0) , Com-CDD-0273(0) , 
Com-CDD-0273(0) , Com-CDD-0274(0) , Com-CDD-0275(0) , 
Com-CDD-0276(0) , Com-CDD-5746(0) , Com-CDD-5517(0), 
Com-CDD-RxHandler-0069(0) , Com-CDD-RxHandler-5602(0) , Com-CDD-RxHandler-5603(0) ,
Com-CDD-RxHandler-5604(0) , Com-CDD-RxHandler-5616(0) , Com-CDD-RxHandler-5619(0) ,
Com-CDD-RxHandler-5622(0) , Com-CDD-RxHandler-5625(0) , Com-CDD-RxHandler-5637(0) ,
Com-CDD-RxHandler-5638(0) , Com-CDD-RxHandler-5655(0) , Com-CDD-RxHandler-5684(0) */
FUNC(void,COM_CODE) Com_MainFunctionRx (void)
/*PRQA S 8023 -- */
{
/*local variables declaration*/
  VAR(PduIdType ,AUTOMATIC)                         u16IpduId;
   VAR(PduIdType ,AUTOMATIC)                        u16IpduIx;
   
#if (Com_bTO_SUPPORT == STD_ON)
  VAR(boolean , AUTOMATIC)                          bIpduTimeOutPassed;
#endif

/* !Deviation: [8018]  (The name of the constant (const) does not  respect the naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) does not  respect the naming conventions.)*/
/*[8518] (The Separator of the constant (const) does not  respect the naming conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318 , 8518 ++ */
  P2CONST(Com_tstrRxIPdu,AUTOMATIC,COM_CALIB_CONST) pkstrLocRXIpduPB;
  P2CONST(Com_tstrRxIPdu,AUTOMATIC,COM_CALIB_CONST) pkstrRXIpduPBTemp;
  P2CONST(uint8,AUTOMATIC,COM_APPL_DATA)            pku8OrgIpduFirstByte;

#if (Com_bTO_SUPPORT == STD_ON)
  VAR(uint16,AUTOMATIC)                             u16IpduSigMapIndx;
  VAR(uint16,AUTOMATIC)                             u16MaxSigNo;
#endif

#if (Com_bTO_SUPPORT == STD_ON)
  VAR(uint16,AUTOMATIC)                             u16LoopIndex;
  VAR(boolean,AUTOMATIC)                            bIpduDmActive;
  P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF)pkstrIPduToSigMap;
#endif    
  VAR(boolean,AUTOMATIC)                            bIpduActive;
  P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF)pkstrIPduToSigMapTemp;
  P2VAR(uint8,AUTOMATIC,TYPEDEF) 					pu8IPduBuf;
  
  VAR(uint8, AUTOMATIC)                     audteIPduStatus[Com_u16RXIPDUMAXIX+1];
  VAR(uint8, AUTOMATIC)                     u8IpduStatus;

  /*PRQA S 8018 , 8318 , 8518 -- */
  if (Com_enueStatus == COM_UNINIT)
  {
	/* Do Nothing */
  }
  else
  {

/*the part of DM */
/*shall check the Com_au8eRxDMIPduGroupVector to know which Ipdu,corresponding
 to a certain Ipdu group , need to have a deadline monitoring  check  .*/
 
  pkstrIPduToSigMapTemp = pkstrGET_IPDU_SGL_MAP_PTR(0);
  pu8IPduBuf = pkstrGET_IPDU_BUFF_PTR(0);

   /*loop on all Rx Ipdu only */
   pkstrRXIpduPBTemp = pkstrGET_RX_IPDU_PTR_IX(0);
   SchM_Enter_Com_IPduStatus_18();
   for(u16IpduIx = 0u;
        u16IpduIx <= Com_u16RXIPDUMAXIX;
         u16IpduIx++)
	{
		u16IpduId = pkstrRXIpduPBTemp[u16IpduIx].u16IPduId;
		audteIPduStatus[u16IpduIx] = Com_audteIPduStatus[u16IpduId];
	}
	SchM_Exit_Com_IPduStatus_18();
	
	
    for (u16IpduIx = 0 ; u16IpduIx <= Com_u16RXIPDUMAXIX; u16IpduIx++ )
    {
		u8IpduStatus = audteIPduStatus[u16IpduIx];
#if (Com_bTO_SUPPORT == STD_ON)
		/*! Check IPDU Deadline monitroing activited or not*/
		bIpduDmActive = ((u8IpduStatus & (Com_u8RX_DM_EN_TX_STOP)) != FALSE);
#endif
		/*! Check IPDU  activited or not*/
        bIpduActive   	 = ((u8IpduStatus & (Com_u8ACTIVE_MASK)) != FALSE); 
		pkstrLocRXIpduPB = &pkstrRXIpduPBTemp[u16IpduIx];

		if( bIpduActive != (boolean)FALSE )
		{
#if (Com_bTO_SUPPORT == STD_ON)
			if( bIpduDmActive != (boolean)FALSE)
			{                
			  /*check if the ipdu has a configured time out */
			  /*! check IPDU timeout Configured */
			  if(pkstrLocRXIpduPB->u32Timeout != 0xFFFFFFFFUL)
			  {
				/*Com-SRS-0099(0)*/
				bIpduTimeOutPassed = Com_bRxIpduCheckDM(u16IpduIx);
				 /*! check IPDU timeout passed  */
				if (bIpduTimeOutPassed == (boolean)TRUE)
				{
				  /*! call the corresponding notification if configured*/
				  vidIpduProcessDM(u16IpduIx);

				  /*! reset the deadline monitoring timer */
				  Com_vidRxIpduResetDM(u16IpduIx);
				}
			  }              
				/*! check IPDU's Signals timeout Configured */			  
			  if ((boolean)(pkstrLocRXIpduPB->udteRxIPduFlags & Com_u8RX_IPDUSIGTIMEOUT) != (boolean)FALSE)
			  {
				u16IpduSigMapIndx = pkstrLocRXIpduPB->u16IPduSigMappingIndex;
				u16MaxSigNo = pkstrLocRXIpduPB->u16IPduNoOfSignals;

				for (u16LoopIndex = u16IpduSigMapIndx ;
				   u16LoopIndex < (u16IpduSigMapIndx+u16MaxSigNo) ;
				   u16LoopIndex++ )
				{
				   pkstrIPduToSigMap = &pkstrIPduToSigMapTemp[u16LoopIndex];
				   
				    /*! check IPDU's Signals timeout Passed and calling notifications */
				  Com_vidSignalHandleDM((pkstrIPduToSigMap->u8Type),
											(pkstrIPduToSigMap->u16Index));
				}
			  }
			}
			else
			{
		  /*do nothing this Ipdu shall not be monitored */
			}
		
#endif
		  /*! Check the Com_u8DEF_PROC_MASK flag previously set in Com_RxIndication, 
							to know which Ipdu need to be processed */
			if((u8IpduStatus & (Com_u8DEF_PROC_MASK))!= (boolean)FALSE)
			  {  
				  pku8OrgIpduFirstByte =  &pu8IPduBuf[pkstrLocRXIpduPB->u32IPduBufferIndex] ;
				  /*! Processs Deferred IPDUs only*/
				  vidProcessRxIpdu (u16IpduIx , pku8OrgIpduFirstByte);
			  }
			  else
			  {
							/*Immediate Ipdu*/
			  }
	    }  
    }
	
	
	SchM_Enter_Com_IPduStatus_18();
    for(u16IpduIx = 0u;
        u16IpduIx <= Com_u16RXIPDUMAXIX;
         u16IpduIx++)
	{
	     u16IpduId = pkstrRXIpduPBTemp[u16IpduIx].u16IPduId;
		#if u16NO_OF_IPDUS_STATUS > 0u	
			if ((audteIPduStatus[u16IpduIx] & Com_u8DEF_PROC_MASK)!= FALSE)
			{
				Com_audteIPduStatus[u16IpduId] &= (Com_udtIPduStatus) ~Com_u8DEF_PROC_MASK;
			}
		#endif
	}
	SchM_Exit_Com_IPduStatus_18();
	
  }
}
 /*  PRQA S 4700 -- */

#if (Com_bRX_REPLICAS_SUPPORT == STD_ON)
/*************************************************************************/
/*! \Description: This function takes a pointer to the first byte in the IPDU \n
and possible up to 2 replica's pointer to their first byte ,  \n
it will compare them , if a Quorum number of these inputs \n
was identical ,  \n
it will return a pointer to this valid IPDU ,  \n
else it will return a NULL pointer.                \n

**************************************************************************/
#if Com_u16NO_OF_IPDU_REPLIC > 0u
static FUNC(Com_tpku8MaxCalibDataConstPtr,COM_CODE) pku8VoteIpdu (
/* !Deviation: [8018]  (The name of the constant (const) does not  respect the naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) does not  respect the naming conventions.)*/
/*[8518] (The Separator of the constant (const) does not  respect the naming conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318 , 8518 ++ */
P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)       pku8IpduOneFirstByte ,
P2CONST(uint8,AUTOMATIC,COM_CALIB_DATA)       			   pku8IpduTwoFirstByte ,
P2CONST(uint8,AUTOMATIC,COM_CALIB_DATA)       			   pku8IpduThreeFirstByte ,
/*PRQA S 8018 , 8318 , 8518 -- */
VAR(uint16 ,AUTOMATIC)                       u16IpduLength,
VAR(uint8, AUTOMATIC)                        u8Quorum)
{
/*local varaibles declarations*/
/* !Deviation: [8018]  (The name of the constant (const) does not  respect the naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) does not  respect the naming conventions.)*/
/*[8518] (The Separator of the constant (const) does not  respect the naming conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318 , 8518 ++ */
  P2CONST(uint8 , AUTOMATIC , COM_MAX_CALIB_APPL_CFGCONST)  pku8VoteResult ;
/*PRQA S 8018 , 8318 , 8518 -- */
  VAR(boolean,AUTOMATIC)                                    bIpdu1Ipdu2Equals ;
  VAR(boolean,AUTOMATIC)                                    bIpdu2Ipdu3Equals ;
  VAR(boolean,AUTOMATIC)                                    bIpdu1Ipdu3Equals ;
  VAR(uint8 , AUTOMATIC)                                    u8Counter;


  bIpdu1Ipdu2Equals = 
  bCompare2u8Arrays(pku8IpduOneFirstByte,pku8IpduTwoFirstByte,u16IpduLength);
  bIpdu2Ipdu3Equals = 
  bCompare2u8Arrays(pku8IpduTwoFirstByte,pku8IpduThreeFirstByte,u16IpduLength);
  bIpdu1Ipdu3Equals = 
  bCompare2u8Arrays(pku8IpduOneFirstByte,pku8IpduThreeFirstByte,u16IpduLength);

  if (bIpdu1Ipdu2Equals && bIpdu2Ipdu3Equals)
  {
    u8Counter     = (uint8)3u;
    pku8VoteResult = pku8IpduOneFirstByte ;
  }

  else if ( bIpdu1Ipdu2Equals|| bIpdu1Ipdu3Equals )
  {
    u8Counter     = (uint8)2u;
    pku8VoteResult = pku8IpduOneFirstByte ;
  }
  else if (bIpdu2Ipdu3Equals == TRUE)
  {
    u8Counter     = (uint8)2u;
    pku8VoteResult = pku8IpduTwoFirstByte ;
  }
  else
  {
    u8Counter     = (uint8)1u;
    pku8VoteResult = pku8IpduOneFirstByte ;
  }
  if (u8Counter < u8Quorum)
  {
    pku8VoteResult =(P2CONST(uint8,AUTOMATIC,COM_APPL_DATA)) NULL_PTR ;
  }
  return  pku8VoteResult;
}
#endif 
#endif


/******************************************************************************/
/*************************************************************************/
/*! \Description: \n

**************************************************************************/
#if (Com_bRX_REPLICAS_SUPPORT == STD_ON)
static FUNC(boolean,COM_CODE) bCompare2u8Arrays (
P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)       pku8FirstArray ,
P2CONST(uint8,AUTOMATIC,COM_APPL_DATA)       pku8SecondArray ,
VAR(uint16 ,AUTOMATIC)                       u16CmpLength)
{
  VAR(uint16_least,AUTOMATIC)    u16LoopIndex;
  VAR(boolean , AUTOMATIC) bCmpResult;
  bCmpResult = TRUE ;


  if ((pku8FirstArray == (P2CONST(uint8,AUTOMATIC,COM_APPL_DATA))NULL_PTR) || 
      (pku8SecondArray == (P2CONST(uint8,AUTOMATIC,COM_APPL_DATA))NULL_PTR))
  {
    bCmpResult = FALSE;
  }

  for ( u16LoopIndex = 0 ; ((u16LoopIndex < u16CmpLength)&& (bCmpResult != FALSE) ) ;u16LoopIndex ++)
  {
/* !Deviation: [0505] (Dereferencing pointer value that is apparently NULL.)
   yes , pku8FirstArray or pku8SecondArray can be NULL but if this occured
   they will not be accessed as the exit condition of the for loop will
   evaluate to TRUE*/
/* PRQA S 0505 ++ */
    SchM_Enter_Com_IPduBuff();
    if (pku8FirstArray[u16LoopIndex] !=  pku8SecondArray[u16LoopIndex])
    /* PRQA S 0505 -- */
    {
      bCmpResult = FALSE;
    }
    SchM_Exit_Com_IPduBuff();
  }
  return bCmpResult;

}
#endif
/******************************************************************************/
/* !Deviation: [4700]  ( here has been an infringement of a threshold on the
     specified metric)
 Further decomposition of this function will affect its overall performance 
 so no other meaningfull division is required*/
 /*  PRQA S 4700 ++ */  
 
 /* !Deviation: [3205]  ( Some of the local varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S 3205,3203 ++ */
/*************************************************************************/
/*! \Description: \n

**************************************************************************/ 
static FUNC(void,COM_CODE) vidProcessRxIpdu (
VAR(uint16,AUTOMATIC)                             u16IpduIx ,
P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)            pku8OrgIpduFirstByte )
{

/* !Deviation: [8018]  (The name of the constant (const) does not  respect the naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) does not  respect the naming conventions.)*/
/*[8518] (The Separator of the constant ("const") does not  respect the naming conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318 , 8518 ++ */
  P2CONST(Com_tstrRxIPdu,AUTOMATIC,COM_CALIB_CONST)                          pkstrLocRXIpduPB;
  P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)                       pku8IpduFirstByte;
#if (Com_bRX_REPLICAS_SUPPORT == STD_ON)
  P2CONST(uint8,AUTOMATIC,COM_APPL_DATA)                                     pku8FirstReplica;
  P2CONST(uint8,AUTOMATIC,COM_APPL_DATA)                                     pku8SecondReplica;
#endif
  /*PRQA S 8018 , 8318 , 8518 -- */
  P2VAR(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)                   PduInfoPtr;
  VAR(uint16_least , AUTOMATIC)                                              u16SigLoopIndex;
  VAR(PduInfoType , AUTOMATIC)                                               strIpduInfo;
#if (Com_bIPDU_COUNTER_SUPPORT == STD_ON)
  VAR(Std_ReturnType , AUTOMATIC)                                            u8DataSequenceRes;
#endif
  
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
  VAR(uint16,AUTOMATIC)                                                      u16SigGrpID ;
  VAR(uint16,AUTOMATIC)														 u16GroupSigIdx;
  VAR(uint16,AUTOMATIC)                                 					 u16SigID ; 
#endif

  VAR(tstrProcessSig,AUTOMATIC)                                              strProcessSigData;
  VAR(uint8,AUTOMATIC)                                                       u8ProcessRxSigRes; 

#if (Com_bRX_REPLICAS_SUPPORT == STD_ON)
  VAR(uint16,AUTOMATIC)                                 					 u16IPduReplicaIx;
  P2CONST(Com_tstrIPduReplication,AUTOMATIC,TYPEDEF) 						 pkstreIPduReplica;
#endif
#if (Com_bIPDU_COUNTER_SUPPORT == STD_ON)
  VAR(uint16,AUTOMATIC)                                 				      u16IPduCtrIx; 
#endif
  P2CONST(uint16, AUTOMATIC, AUTOMATIC)  pku16IPduSigMapIdx;
  P2CONST(uint16, AUTOMATIC, AUTOMATIC)  pku16IPduNoOfSig;
  P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF)  pkstrIPduToSigMap;
  P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF)  pkstrIPduToSigMapTemp;
  P2CONST(Com_tstrGWSignalMapping,AUTOMATIC,TYPEDEF)	pkstrGWSigMap;
  P2CONST(Com_tstrGWSignalMapping,AUTOMATIC,TYPEDEF)	pkstrGWSigMapTemp;
  P2CONST(Com_tstrSignalPB,AUTOMATIC,TYPEDEF)  		pkstrSigPB;
#if (Com_bGW_DESC_SUPPORT == STD_ON)
  P2CONST(Com_tstrGWSrcDesc,AUTOMATIC,TYPEDEF)	  pkstrGWSrcDscPtr;
  P2CONST(Com_tstrGWSrcDesc,AUTOMATIC,TYPEDEF)	  pkstrGWSrcDscPtrTemp;
#endif

  P2VAR(uint16,AUTOMATIC,AUTOMATIC)pu16SignlIxPtr;
  P2VAR(uint16,AUTOMATIC,AUTOMATIC)pu16SignlIDPtr;
#if (Com_bUBIT_SUPPORT == STD_ON)
  P2VAR(uint16,AUTOMATIC,AUTOMATIC) pu16SigUBIx;
#endif
  VAR(uint16,AUTOMATIC)                            u16IpduLength ;
  VAR(uint16,AUTOMATIC)                            u16DataBufferIx ;
  VAR(uint8,AUTOMATIC)                             au8DataBuffer[Com_u16MAX_RX_IPDU_LENGTH] ;

  P2VAR(uint8,AUTOMATIC,AUTOMATIC)pu8SigStructTypePtr;

  PduInfoPtr = &strIpduInfo;

  pkstrLocRXIpduPB =  pkstrGET_RX_IPDU_PTR_IX(u16IpduIx);
  u16IpduLength = pkstrLocRXIpduPB->u16IPduLength;
  /*If the Ipdu has a configured replica start the voting , and clear the replica counter*/
#if ((Com_bRX_REPLICAS_SUPPORT == STD_ON) && (Com_u16NO_OF_IPDU_REPLIC > 0u))

  u16IPduReplicaIx = pkstrLocRXIpduPB->u16IPduReplicationIndex;
  pkstreIPduReplica= pkstrGET_RX_IPDU_REP_PTR(u16IPduReplicaIx);
  
  /*! check IPDU has replicas */
  if (u16IPduReplicaIx != (uint16)0xFFFFu)
  {
   /*! get pointer to first replicas buffer*/
    pku8FirstReplica = (P2CONST(uint8,AUTOMATIC,COM_APPL_DATA))(pu8GET_RX_IPDU_1ST_REP(pkstreIPduReplica->u16ReplicasBufferIndex)) ;
    if (pkstreIPduReplica->u8NoOfReplicas == (uint8)2u)
    {
      pku8SecondReplica = &(pku8FirstReplica[u16IpduLength]);
    }
    else
    {
      pku8SecondReplica =(P2CONST(uint8,AUTOMATIC,COM_APPL_DATA))NULL_PTR;
    }
	/*! do voting between different replicas*/
    pku8IpduFirstByte = pku8VoteIpdu ( pku8OrgIpduFirstByte,
                                    pku8FirstReplica,
                                    pku8SecondReplica,
                                    u16IpduLength,
                                    pkstreIPduReplica->u8IPduReplicaQuorum);
  }

  else
  {
#endif /* Com_u16NO_OF_IPDU_REPLIC > 0*/
     /*Ipdu has no replica*/
    pku8IpduFirstByte = pku8OrgIpduFirstByte ;
	
#if ((Com_bRX_REPLICAS_SUPPORT == STD_ON)&& (Com_u16NO_OF_IPDU_REPLIC > 0u))
  }
#endif /* Com_u16NO_OF_IPDU_REPLIC > 0*/

  if(pku8IpduFirstByte!=(P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))NULL_PTR)
  {
    /* !Deviation: [0311] (Dangerous pointer cast results in loss of const
                   qualification.)
    PduInfoPtr can not be a const structure as it is required to fill its
    content before passing it , so the const pointer pku8IpduFirstByte shall be
    casted to (uint8*) before copying its content to PduInfoPtr->SduDataPtr*/
    /*if the ipdu has a configured counter check the counter before processing it */
	
#if (Com_bIPDU_COUNTER_SUPPORT == STD_ON)
    /*! check IPDu have counter is configured*/
	u16IPduCtrIx = pkstrLocRXIpduPB->u16IPduCounterIndex;
	if(u16IPduCtrIx != (uint16)0xFFFFu)
    {
    /*! check the data sequence*/
      u8DataSequenceRes = Com_u8IpduCheckDataSeq(u16IpduIx ,pku8IpduFirstByte) ;
    }
    else
    {
    /*no counter is configured so the next check shall be true*/
      u8DataSequenceRes = E_OK;
    }
    if(u8DataSequenceRes == E_OK)
    {
#endif
      /* PRQA S 0311 ++ */
	  
	  /*! Copy Received Data to be processed*/
	  SchM_Enter_Com_IPduBuff();
		  for (u16DataBufferIx = 0 ;u16DataBufferIx < u16IpduLength;u16DataBufferIx++)
		  {
			au8DataBuffer[u16DataBufferIx] = pku8IpduFirstByte[u16DataBufferIx]; 
		  }
	  SchM_Exit_Com_IPduBuff();
	  
	  PduInfoPtr->SduDataPtr = &au8DataBuffer[0];
      PduInfoPtr->SduLength  = u16IpduLength ;

	  pku16IPduSigMapIdx = &(pkstrLocRXIpduPB->u16IPduSigMappingIndex);
	  pku16IPduNoOfSig = &(pkstrLocRXIpduPB->u16IPduNoOfSignals);
	  
	  pkstrIPduToSigMapTemp = pkstrGET_IPDU_SGL_MAP_PTR(0);
	  pkstrGWSigMapTemp = pkstrGET_GW_SIG_MAPP_PTR(0);
	  pkstrSigPB = pkstrGET_PBSIGPTR_IX(0);
#if (Com_bGW_DESC_SUPPORT == STD_ON)
	  pkstrGWSrcDscPtrTemp = pkstrGET_PBSRC_DESCPTR_IX(0);
#endif

	  pu16SignlIxPtr = &(strProcessSigData.u16SignlIx);
	  pu16SignlIDPtr =  &(strProcessSigData.u16SignlID);
#if (Com_bUBIT_SUPPORT == STD_ON)
	  pu16SigUBIx	= &(strProcessSigData.u16SigUBIx);
#endif

	  pu8SigStructTypePtr = &(strProcessSigData.u8SigStructType);


    /* PRQA S 0311 -- */
	/*! Loop on all signals/ signals groups/ GW signals, GW signals groups to process 
			Rx values and calling notifications*/
      for (u16SigLoopIndex = *pku16IPduSigMapIdx ; u16SigLoopIndex < ((*pku16IPduSigMapIdx)+(*pku16IPduNoOfSig)) ; u16SigLoopIndex++ )
      {
        /*switch on the type of the content of IPdu to Signal mapping */
		
		pkstrIPduToSigMap = &pkstrIPduToSigMapTemp[u16SigLoopIndex];
        /*! get Signals/ Signals group properties and processs its RX values depend on the type*/
		switch (pkstrIPduToSigMap->u8Type)
        {
          case Com_u8SIGNAL :
        /*Get the Signal ID*/
          *pu16SignlIxPtr = 
          pkstrIPduToSigMap->u16Index;            
          *pu16SignlIDPtr = 
          u16GET_SIG_ID_FROM_IX(*pu16SignlIxPtr);
#if (Com_bUBIT_SUPPORT == STD_ON)
		  *pu16SigUBIx = pkstrSigPB[*pu16SignlIxPtr].u16UpdateBitPosition;
#endif

#if (Com_bDATA_INVALID_SUPPORT == STD_ON)
          strProcessSigData.pfvidInValidNot = pfSIG_INVALID_CBK(*pu16SignlIxPtr); 
#endif

          *pu8SigStructTypePtr = (uint8)Com_u8SIGNAL ;    
		   /*! Unpack, check invalidation, Call notifcations in this function*/
          (void)u8ProcessRxSig(
          (P2CONST(tstrProcessSig,AUTOMATIC,COM_APPL_DATA))&strProcessSigData ,
           PduInfoPtr);
          break;
#if (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
          case Com_u8SIGNALGROUP:
           /*not supported in this phase*/
          /*Get the Signal ID*/
          u16SigGrpID = pkstrIPduToSigMap->u16Index;
		  /*! Unpack, check invalidation, Call notifcations in this function*/
          (void) u8ProcessRxSigGrp( u16SigGrpID , PduInfoPtr);
          break;
#endif             
          case Com_u8GWSIGNAL:
      /*Get the Signal ID*/
		  pkstrGWSigMap = &pkstrGWSigMapTemp[pkstrIPduToSigMap->u16Index];
          *pu16SignlIxPtr =
          pkstrGWSigMap->u16SrcIndex;
          *pu8SigStructTypePtr =
          pkstrGWSigMap->u8SrcStructType;

          switch (*pu8SigStructTypePtr)
          {
            case Com_u8SIG_STRUCT_SIG:
            *pu16SignlIDPtr = u16GET_SIG_ID_FROM_IX(*pu16SignlIxPtr);
#if (Com_bUBIT_SUPPORT == STD_ON)
			*pu16SigUBIx = pkstrSigPB[*pu16SignlIxPtr].u16UpdateBitPosition;
#endif

#if (Com_bDATA_INVALID_SUPPORT == STD_ON)
            strProcessSigData.pfvidInValidNot = pfSIG_INVALID_CBK(*pu16SignlIxPtr); 
#endif
            break;
            
#if (Com_bGW_DESC_SUPPORT == STD_ON)			
            case Com_u8GW_STRUCT_SRC_DESC:
			pkstrGWSrcDscPtr = &pkstrGWSrcDscPtrTemp[*pu16SignlIxPtr];
            *pu16SignlIDPtr = pkstrGWSrcDscPtr->u16SignalId;
		#if (Com_bUBIT_SUPPORT == STD_ON)
			*pu16SigUBIx = pkstrGWSrcDscPtr->u16UpdateBitPosition;
		#endif
            /*! Com_u8GW_STRUCT_SRC_DESC has no configured Notification*/
		#if (Com_bDATA_INVALID_SUPPORT == STD_ON)
            strProcessSigData.pfvidInValidNot = 
            (VAR(Com_tpfvidSigInvalidNotif,AUTOMATIC) )NULL_PTR;  
		#endif			
            break;
#endif
            default:
             /*Com_u8GW_STRUCT_SIGGROUP will be gatewayed through COM_u8GW_STRUCT_GROUPSIG
             or Com_u8GW_STRUCT_DST_DESC can not be gatewayed */
            break;
          }
			/*! Unpack, check invalidation, Call notifcations for this GW signal 
			in this function*/
          u8ProcessRxSigRes = u8ProcessRxSig(
          (P2CONST(tstrProcessSig,AUTOMATIC,COM_APPL_DATA))&strProcessSigData ,
           PduInfoPtr );

          /* If GW Sig Set the corresponding bit in GWFlags*/
          if (u8ProcessRxSigRes == (uint8)E_OK)
          {
			#if Com_u16NO_OF_SIGNAL_STATUS > 0u
			SchM_Enter_Com_SignalStatus_18();
			SchM_Enter_Com_SignalStatus_42();
			SchM_Enter_Com_SignalStatus_1E();
			/*! mark this Signal In the Signal Byte status To be GW in the GW mainFunction Route*/
			Com_audteSignalStatus[*pu16SignlIDPtr] |= Com_u8GWS_RX;
			
			SchM_Exit_Com_SignalStatus_1E();
			SchM_Exit_Com_SignalStatus_42();
			SchM_Exit_Com_SignalStatus_18();
			#endif
          }
          else
          {
         /*do not set the GW flag*/
          }             
          break;
#if ((Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
          case Com_u8GWSIGNALGROUP :
         /*not supported in this phase*/
        /*Get the Signal ID*/
		  pkstrGWSigMap = &pkstrGWSigMapTemp[pkstrIPduToSigMap->u16Index];
          u16SigGrpID = pkstrGWSigMap->u16SrcIndex;
		  /*! Unpack, check invalidation, Call notifcations for this GW signal group 
		  in this function*/
          u8ProcessRxSigRes = u8ProcessRxSigGrp( u16SigGrpID , PduInfoPtr);
          if (u8ProcessRxSigRes == (uint8)E_OK)
          {
         /*set the GW flag*/
			
			/*Set the first group Signal GW maaping to indicate this Signal group contain this Group signal shall be Gatewayed*/
			u16GroupSigIdx = u16GET_GRP_SIG_IX(u16SigGrpID);
			u16SigID = Com_akstreGroupSignalLT[u16GroupSigIdx].u16SignalId;
			
			#if Com_u16NO_OF_SIGNAL_STATUS > 0u
			SchM_Enter_Com_SignalStatus_18();
			SchM_Enter_Com_SignalStatus_42();
			SchM_Enter_Com_SignalStatus_1E();
			/*! mark this Signal Group In the First Group Signal Location Byte status To be GW in the GW mainFunction Route*/
			Com_audteSignalStatus[u16SigID] |= (Com_u8GWS_RX);
			
			SchM_Exit_Com_SignalStatus_1E();
			SchM_Exit_Com_SignalStatus_42();
			SchM_Exit_Com_SignalStatus_18();
			#endif

          }
          else
          {
         /*do not set the GW flag*/
          }
          break;
#endif             
          default:
          break;
        }
      }
#if (Com_bIPDU_COUNTER_SUPPORT == STD_ON)
    }/*no counter configured or correct Ipdu Counter*/
    else
    {
    /*wrong Ipdu Counter*/
    }
#endif
  }
  else
  {
   /*voting failed*/
  }
}
/*PRQA S 3205,3203 -- */
 /*  PRQA S 4700 -- */
/*****************************************************************************/
/* !Deviation: [4700]  ( here has been an infringement of a threshold on the
     specified metric)
 Further decomposition of this function will affect its overall performance 
 so no other meaningfull division is required*/
 /*  PRQA S 4700 ++ */   
/* !Deviation:[3673] (The object addressed by the pointer parameter 'PduInfoPtr'
   is not modified and so the pointer could be of type 'pointer to const')
   This prototype is maindated by the AUTOSAR*/
/* PRQA S 3673 ++ */
/*************************************************************************/
/*! \Description: \n

**************************************************************************/
/* !Deviation: [8023]  (The name of the function does not  respect the naming conventions.) */
/*function names are mandated by AUTOSAR*/
/*PRQA S 8023 ++ */
 /*! \Trace_To : Com-CDD-RxHandler-0002(0) , Com-CDD-RxHandler-0052(0) ,Com-CDD-RxHandler-0054(0) ,
Com-CDD-RxHandler-0493(0) ,Com-CDD-RxHandler-0494(0) ,Com-CDD-RxHandler-0495(0) ,
Com-CDD-RxHandler-0478(0) ,Com-CDD-RxHandler-0485(0) ,Com-CDD-RxHandler-0486(0) ,
Com-CDD-RxHandler-0480(0) ,Com-CDD-RxHandler-0481(0) ,Com-CDD-RxHandler-0497(0) ,
Com-CDD-RxHandler-0463(0) , Com-CDD-RxHandler-0515(0) ,  
 Com-CDD-RxHandler-0035(0) ,Com-CDD-RxHandler-0036(0)  ,Com-CDD-RxHandler-0041(0) ,
 Com-CDD-RxHandler-0063(0) , Com-CDD-RxHandler-0064(0) , Com-CDD-RxHandler-0065(0) ,
 Com-CDD-RxHandler-0468(0) , Com-CDD-RxHandler-0470(0) , Com-CDD-RxHandler-0471(0) ,
 Com-CDD-RxHandler-0477(0) , Com-CDD-RxHandler-0484(0) , Com-CDD-RxHandler-0496(0) , 
 Com-CDD-RxHandler-5613(0) , Com-CDD-RxHandler-5614(0) , Com-CDD-RxHandler-5617(0) ,
 Com-CDD-RxHandler-5620(0) ,Com-CDD-RxHandler-5623(0) , Com-CDD-RxHandler-5626(0)  , 
 Com-CDD-RxHandler-5639(0) , Com-CDD-RxHandler-5728(0) , Com-CDD-RxHandler-5682(0) , 
 Com-CDD-RxHandler-5685(0) ,Com-CDD-5746(0) , Com-CDD-5517(0), Com-CDD-5748(1), Com-CDD-5514(1)*/
FUNC(void,COM_CODE) Com_RxIndication (
     VAR(PduIdType,AUTOMATIC)                   RxPduId,
     P2VAR(PduInfoType,AUTOMATIC,COM_APPL_DATA) PduInfoPtr)
/*PRQA S 8023 -- */
/* PRQA S 3673 -- */
{
/*local variable declaration*/
/* !Deviation: [8018]  (The name of the constant (const) does not  respect the naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) does not  respect the naming conventions.)*/
/*[8518] (The Separator of the constant (const) does not  respect the naming conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518 ++ */
  P2CONST(Com_tstrRxIPdu,AUTOMATIC,COM_CALIB_CONST) pkstrLocRXIpduPB;
/*PRQA S 8018 , 8318 , 8518 -- */
#if (Com_bRX_CALLOUT_SUPPORT == STD_ON)
  VAR(boolean, AUTOMATIC)                           bCalloutReturn;
#endif
  VAR(uint16_least , AUTOMATIC)                     u16ByteLoopIndex;
  VAR(uint16 , AUTOMATIC)                     		u16RxPduIx;
  
  VAR(uint32, AUTOMATIC)                            u32IpduBufferIx;
#if (Com_bRX_REPLICAS_SUPPORT == STD_ON)
  VAR(uint16,AUTOMATIC)                             u16IPduReplicaIx;
#endif
  /* !Deviation:[3672]  (Using non-const pointer to function.)
  the pointer to function can not be declared as constant , as it will
  be assigned a value calculated by the code depending on the PduId*/
  /*PRQA S 3672 ++ */
/*[ 8318]  ( the Component ID of the constant (const) does not  respect the naming conventions.)*/
/*[8518] (The Separator of the constant (const) does not  respect the naming conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518 ++ */
#if (Com_bRX_CALLOUT_SUPPORT == STD_ON)
  VAR(Com_tpfbRxIpduCallout, AUTOMATIC)             pfbRxCallout;
#endif
  /*PRQA S 8018 , 8318, 8518 ++ */
  /*PRQA S 3672 -- */
  VAR(boolean, AUTOMATIC)                           bIpduIsActive;
#if (Com_bTO_SUPPORT == STD_ON)
  VAR(uint16,AUTOMATIC)                             u16IpduSigMapIndx;
  VAR(uint16_least,AUTOMATIC)                       u16LoopIndex;
  P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF) pkstrIPduToSigMap;
  P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF) pkstrIPduToSigMapTemp;
  VAR(uint16,AUTOMATIC)                             u16MaxSigNo;
#endif

#if (Com_bRX_CALLOUT_SUPPORT == STD_ON)
  VAR(uint16,AUTOMATIC)                             u16IPduCalloutIx;
#endif

	P2VAR(uint8,AUTOMATIC,TYPEDEF) 					pu8IPduBuf;		
	P2VAR(PduLengthType, AUTOMATIC, AUTOMATIC) pkudtSduLengthPtr;
	P2VAR(uint8, AUTOMATIC, AUTOSAR_COMSTACKDATA) pudtSduDataPtr;

  
  if ( PduInfoPtr ==  NULL_PTR )
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_RxIndication, COM_E_PARAM_POINTER);
    #endif /*COM_DEV_ERROR_DETECT*/
  }
  else if (Com_enueStatus == COM_UNINIT)
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_RxIndication, COM_E_UNINIT);
    #endif /*COM_DEV_ERROR_DETECT*/
  }
  else if ((RxPduId > Com_u16RXIPDUIDMAX) ||
          (u8GET_IPDU_DIR(RxPduId) != (uint8) Com_u8DIRECTION_RX)||
          (u8GET_RX_IPDU_TYPE(RxPduId) != (uint8) Com_u8IPDU_TYPE_NORMAL))
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_RxIndication, COM_E_PARAM);
    #endif /*COM_DEV_ERROR_DETECT*/
  }
  else
  {

	u16RxPduIx = u16GET_IPDU_INDEX(RxPduId);
    pkstrLocRXIpduPB = pkstrGET_RX_IPDU_PTR_IX(u16RxPduIx);
    /*check if the ipdu is active , process it , else discard it */
	SchM_Enter_Com_IPduStatus_1E();
    #if u16NO_OF_IPDUS_STATUS > 0u
	bIpduIsActive = ((Com_audteIPduStatus[RxPduId] & (Com_u8ACTIVE_MASK)) != FALSE);
	#endif
	SchM_Exit_Com_IPduStatus_1E();
	
    if (bIpduIsActive == (boolean)TRUE )
    {
	
#if (Com_bRX_CALLOUT_SUPPORT == STD_ON)
    /*Call the corresponding Com_RxIpduCallout if configured*/
	  u16IPduCalloutIx = pkstrLocRXIpduPB->u16IPduCalloutIndex;
	  if(u16IPduCalloutIx != (uint16)0xFFFFu)
      {
        pfbRxCallout = pfGET_RXIPDU_CALOUTPTR(u16IPduCalloutIx);
         /* !Deviation: [504]  ( Access of this pointer is protected by 
         the previous if condition) */
         /*PRQA S 504 ++ */
        bCalloutReturn  = (*pfbRxCallout)(RxPduId,PduInfoPtr);
		 /*PRQA S 504 --  */
      }
      else
      {
         /*No Callout is configured*/
        bCalloutReturn = TRUE;
      }
      if (bCalloutReturn == TRUE)
      {
#endif
      /*continue processing the IPDU*/
        /*first check if defferred IPDU copy it to the RAM */
         /* if the IPdu was deferred and has no replica , or it was deferred that has a replica but this is the first time of ipdu receiption*/
#if ((Com_u16NO_OF_IPDU_REPLIC > 0u) && (Com_bRX_REPLICAS_SUPPORT == STD_ON))
          u16IPduReplicaIx = pkstrLocRXIpduPB->u16IPduReplicationIndex;
 		 
		if (u16IPduReplicaIx != (uint16)0xFFFFu)
        {
          vidHandleIpduReplicas(RxPduId ,PduInfoPtr);
        }
        else
        {
#endif /*Com_u16NO_OF_IPDU_REPLIC > 0 */
          /*Ipdu has no replica*/
          if ((pkstrLocRXIpduPB->udteRxIPduFlags & Com_u8RX_IPDUSIGPROCESSING) != Com_u8SIG_PROC_IMMEDIATE)
          {
          /*copy then set the flag*/
            u32IpduBufferIx = pkstrLocRXIpduPB->u32IPduBufferIndex;

			pu8IPduBuf		= pkstrGET_IPDU_BUFF_PTR(0);
			pkudtSduLengthPtr	= &(PduInfoPtr->SduLength);
			pudtSduDataPtr		= PduInfoPtr->SduDataPtr;
            
			for (u16ByteLoopIndex = 0 ; u16ByteLoopIndex < *pkudtSduLengthPtr ; u16ByteLoopIndex++)
            {
              SchM_Enter_Com_IPduBuff_42();
              pu8IPduBuf[(u32IpduBufferIx+u16ByteLoopIndex)]  = pudtSduDataPtr[u16ByteLoopIndex];
              SchM_Exit_Com_IPduBuff_42();
            }
			
			#if u16NO_OF_IPDUS_STATUS > 0u
			SchM_Enter_Com_IPduStatus_42();
			Com_audteIPduStatus[RxPduId] |= Com_u8DEF_PROC_MASK; 
			SchM_Exit_Com_IPduStatus_42();
			#endif
          }
          else
         /*immediate ipdu*/
          {
             /*continue processing*/
            vidProcessRxIpdu(u16RxPduIx , (P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))(PduInfoPtr->SduDataPtr) );
          }
        #if ((Com_u16NO_OF_IPDU_REPLIC > 0u) && (Com_bRX_REPLICAS_SUPPORT == STD_ON))
        }
        #endif /*Com_u16NO_OF_IPDU_REPLIC > 0*/
#if (Com_bRX_CALLOUT_SUPPORT == STD_ON)
      }
      else
      {
    /*discard the IPDU due to callout return false*/
      }
#endif

#if (Com_bTO_SUPPORT == STD_ON)
    /*Reset the deadline "IPDU based" monotoring of the recived Ipdu*/
      Com_vidRxIpduResetDM(u16RxPduIx);

      u16IpduSigMapIndx = pkstrLocRXIpduPB->u16IPduSigMappingIndex;
      u16MaxSigNo = pkstrLocRXIpduPB->u16IPduNoOfSignals;
    /*Reset the deadline "Signal based" monotoring of the recived Ipdu*/
	  pkstrIPduToSigMapTemp = pkstrGET_IPDU_SGL_MAP_PTR(0);
      for (u16LoopIndex = u16IpduSigMapIndx ;
         u16LoopIndex < (u16IpduSigMapIndx+u16MaxSigNo) ;
         u16LoopIndex++ )
      {
		pkstrIPduToSigMap = &pkstrIPduToSigMapTemp[u16LoopIndex];
        Com_vidSignalResetDM(pkstrIPduToSigMap->u8Type,
                     pkstrIPduToSigMap->u16Index);
      }
#endif

   }

  }

}
/* PRQA S 4700 -- */

#if (Com_bTO_SUPPORT == STD_ON)
/* !Deviation: [4700]  ( here has been an infringement of a threshold on the
     specified metric)
 Further decomposition of this function will affect its overall performance 
 so no other meaningfull division is required*/
 /*  PRQA S 4700 ++ */ 
 /* !Deviation: [3205]  ( Some of the local varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S 3205,3199, 3203  ++ */ 
 /*************************************************************************/
/*! \Description: \n

**************************************************************************/
static FUNC(void,COM_CODE) vidIpduProcessDM (
VAR(uint16,AUTOMATIC)                   u16RxPduIx)
{

/* !Deviation: [8018]  (The name of the constant (const) does not respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */  
  P2CONST(Com_tstrRxIPdu,AUTOMATIC,COM_CALIB_CONST)            pkstrLocRXIpduPB;

/*PRQA S 8018 , 8318, 8518  -- */          
  /* !Deviation:[3672]  (Using non-const pointer to function.)
  the pointer to function can not be declared as constant , as it will
  be assigned a value calculated by the code depending on the PduId*/
  /*PRQA S 3672 ++ */
  VAR(Com_tpfvidTimeoutNotification, AUTOMATIC)                pfvidTimeOutNotify;
/*PRQA S 3672 -- */
  VAR(uint16,AUTOMATIC)                                        u16IpduSigMapIndx;
  VAR(uint16,AUTOMATIC)                                        u16MaxSigNo;
  VAR(uint16_least,AUTOMATIC)                                  u16LoopIndex;
  /*VAR(uint16,AUTOMATIC)                                        u16SigId;*/
  VAR(uint8,AUTOMATIC)                                         u8SigContainer;
  VAR(uint16,AUTOMATIC)                                        u16SigIx;
  VAR(uint16,AUTOMATIC)                                        u16SigGroupId; 
  VAR(uint16_least,AUTOMATIC)                                  u16SigLoopIx;
  VAR(uint8,AUTOMATIC)                                         u8StructType ;    

  VAR(boolean,AUTOMATIC)                                       bTimeOutconf;
  VAR(boolean,AUTOMATIC)                                       bUpdateBitconf;
  VAR(uint8,AUTOMATIC)                                         u8TimeOutAction;
  
#if (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
  VAR(uint16,AUTOMATIC)                                        u16GroupSigNb;
  VAR(uint16,AUTOMATIC)                                        u16GroupSigIx;
#endif

  P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF) 		pkstrIPduToSigMap;
  P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF) 		pkstrIPduToSigMapTemp;
  #if(Com_u16NO_OF_SIGNAL > 0u)
  P2CONST(Com_tstrSignalPB,AUTOMATIC,TYPEDEF) 					pkstrSigPB;
  P2CONST(Com_tstrSignalPB,AUTOMATIC,TYPEDEF) 					pkstrSigPBTemp;
  P2CONST(Com_tstrSignalLT,AUTOMATIC,TYPEDEF) 					pkstreSignalLT;
#endif

#if (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
  P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,TYPEDEF) 				pkstrSigGrpPB;
  P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,TYPEDEF) 				pkstrSigGrpPBTemp;
  P2CONST(Com_tstrSignalGroupLT,AUTOMATIC,TYPEDEF) 				pkstreSignalGroupLT;
#endif
  P2CONST(Com_tstrGWSignalMapping,AUTOMATIC,TYPEDEF) 			pkstrGWSigMap;
  P2CONST(Com_tstrGWSignalMapping,AUTOMATIC,TYPEDEF) 			pkstrGWSigMapTemp;
  


  pkstrLocRXIpduPB = pkstrGET_RX_IPDU_PTR_IX(u16RxPduIx);
  u8StructType = (uint8)0xFFu;
  pfvidTimeOutNotify = (VAR(Com_tpfvidTimeoutNotification, AUTOMATIC))NULL_PTR;
  
  u16IpduSigMapIndx = pkstrLocRXIpduPB->u16IPduSigMappingIndex;
  u16MaxSigNo = pkstrLocRXIpduPB->u16IPduNoOfSignals;

  pkstrIPduToSigMapTemp = pkstrGET_IPDU_SGL_MAP_PTR(0);
#if(Com_u16NO_OF_SIGNAL > 0u)  
  pkstrSigPBTemp = pkstrGET_PBSIGPTR_IX(0);
#endif
#if (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
  pkstrSigGrpPBTemp = pkstrGET_PB_SIGGRP_PTR(0);
#endif
  pkstrGWSigMapTemp = pkstrGET_GW_MAP_SIG_PTR(0);
  u16SigIx = 0u;

    /*! loop on each signal , signal group inside the ipdu 
	if the signal has a configured DM , perform the timeout action */
  for (u16LoopIndex = u16IpduSigMapIndx ;
       u16LoopIndex < (u16IpduSigMapIndx+u16MaxSigNo) ;
       u16LoopIndex++ )
  {
    /*switch on the type of the content of IPdu to Signal mapping */
	
	pkstrIPduToSigMap = &pkstrIPduToSigMapTemp[u16LoopIndex];
    u8SigContainer = pkstrIPduToSigMap->u8Type;
	bTimeOutconf   = (boolean)FALSE ;
	bUpdateBitconf = (boolean)FALSE ;
	u8TimeOutAction = (uint8)0xFFu;  

 /* !Deviation: [3352]  ( The Switch case has more than 2 paths in the normal case but
in some special configuration it will have only two paths.) */
/*PRQA S 3352 ++ */
    switch (u8SigContainer)
    {
#if(Com_u16NO_OF_SIGNAL > 0u)     
      case Com_u8SIGNAL:
      u16SigIx = pkstrIPduToSigMap->u16Index ;
	  pkstreSignalLT = &Com_akstreSignalLT[u16SigIx];
	  pkstrSigPB = &pkstrSigPBTemp[u16SigIx];
	  u8StructType = Com_u8SIG_STRUCT_SIG;
      bUpdateBitconf   = (boolean)((pkstrSigPB->u16UpdateBitPosition) != (uint16)0xFFFFU);
/* !Deviation: [3212]  (Casting (boolean) is required in case 
                       u16LoopIndex is defined with different type than boolean) */
/*PRQA S 3212 ++ */
	  bTimeOutconf     = (boolean)((pkstrSigPB->u32Timeout) != (uint32)0xFFFFFFFFUL);
/*PRQA S 3212 -- */
      u8TimeOutAction  = (uint8) ((pkstreSignalLT->udteSignalLTFlags & Com_u8SIGLT_TIMEOUT_ACT) != FALSE);
      pfvidTimeOutNotify =
      pkstreSignalLT->pfvidTimeoutNotification;

      break;
#endif /*(Com_u16NO_OF_SIGNAL > 0)  */ 

#if((Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))   
      case Com_u8SIGNAL_GROUP:
      u16SigGroupId =  pkstrIPduToSigMap->u16Index ;
	  pkstrSigGrpPB = &pkstrSigGrpPBTemp[u16SigGroupId];
	  pkstreSignalGroupLT = &Com_akstreSignalGroupLT[u16SigGroupId];
	  bUpdateBitconf   = (boolean)((pkstrSigGrpPB->u16UpdateBitPosition) != (uint16)0xFFFFU);   
      u8TimeOutAction  = (uint8) ((pkstreSignalGroupLT->udteSignalGroupLTFlags & Com_u8SIGPLT_TIMOUT_ACT) != FALSE);
      pfvidTimeOutNotify =
      pkstreSignalGroupLT->pfvidTimeoutNotification;
/* !Deviation: [3212]  (Casting (boolean) is required in case 
                       u16LoopIndex is defined with different type than boolean) */
/*PRQA S 3212 ++ */
	  bTimeOutconf     = (boolean)((pkstrSigGrpPB->u32Timeout) != (uint32)0xFFFFFFFFUL);
/*PRQA S 3212 -- */
      u16GroupSigNb = pkstrSigGrpPB->u16NoOfGroupSignals ;
      u16GroupSigIx = pkstrSigGrpPB->u16GroupSignalIndex;

      break;
#endif /*(Com_u16NO_OF_SIGNAL_GROUPSLT > 0) */     
      case Com_u8GWSIGNAL :
	   /* !Deviation: [3198]  ( The value assigned to 'u16SigIx' is always modified 
	   before being used due to some special configuration but in the normal case
	   this part is normally reachable) */
        /*PRQA S 3198 ++ */
	  pkstrGWSigMap = &pkstrGWSigMapTemp[pkstrIPduToSigMap->u16Index];
      u16SigIx = pkstrGWSigMap->u16SrcIndex;
      /*PRQA S 3198 -- */
      u8StructType = pkstrGWSigMap->u8SrcStructType;
  
      if (u8StructType == (uint8)Com_u8SIG_STRUCT_SIG) 
      {
#if(Com_u16NO_OF_SIGNAL > 0u)                 
	    pkstreSignalLT = &Com_akstreSignalLT[u16SigIx];
	    pkstrSigPB = &pkstrSigPBTemp[u16SigIx];
		bUpdateBitconf   = (boolean)((pkstrSigPB->u16UpdateBitPosition) != (uint16)0xFFFFU);
/* !Deviation: [3212]  (Casting (boolean) is required in case 
                       u16LoopIndex is defined with different type than boolean) */
/*PRQA S 3212 ++ */

		bTimeOutconf     = (boolean)((pkstrSigPB->u32Timeout) != (uint32)0xFFFFFFFFUL);
/*PRQA S 3212 -- */
        u8TimeOutAction  = (uint8) ((pkstreSignalLT->udteSignalLTFlags & Com_u8SIGLT_TIMEOUT_ACT) != FALSE);
        pfvidTimeOutNotify =
        pkstreSignalLT->pfvidTimeoutNotification;
#endif       
      }
      else
      {
    
    /*Com_u8SIG_STRUCT_SRCDESC*/
    /*shall not monitor the DM*/
        bUpdateBitconf = (boolean)FALSE ;
        bTimeOutconf   = (boolean)FALSE ;
        u8TimeOutAction = (uint8)0xFFu;   
		u8StructType = Com_u8SIG_STRUCT_SRCDESC;
		/*u16SigId = (uint16)0;	*/	
      }
      break;
#if((Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
      case Com_u8GWSIGNALGROUP :
   /*note the signal group ID is the same as the signal Index*/
      pkstrGWSigMap = &pkstrGWSigMapTemp[pkstrIPduToSigMap->u16Index];
	  u16SigGroupId = pkstrGWSigMap->u16SrcIndex;
   	  pkstrSigGrpPB = &pkstrSigGrpPBTemp[u16SigGroupId];
	  pkstreSignalGroupLT = &Com_akstreSignalGroupLT[u16SigGroupId];
	  bUpdateBitconf   = (boolean)((pkstrSigGrpPB->u16UpdateBitPosition) != (uint16)0xFFFFu);
      
      u8TimeOutAction  = (uint8) ((pkstreSignalGroupLT->udteSignalGroupLTFlags & Com_u8SIGPLT_TIMOUT_ACT) != FALSE);
      pfvidTimeOutNotify = pkstreSignalGroupLT->pfvidTimeoutNotification;
	  bTimeOutconf     = (boolean)((pkstrSigGrpPB->u32Timeout) != (uint16)0xFFFFu);
      u16GroupSigNb = pkstrSigGrpPB->u16NoOfGroupSignals;
      u16GroupSigIx = pkstrSigGrpPB->u16GroupSignalIndex;
         
      break;
#endif        
      default:   
      break;
    }
/*PRQA S 3352 -- */
 /* !Deviation: [3356]  ( The value of this control expression is always 'false' due to 
 some special configuration but in the normal case this part is normally reachable.) */
/*PRQA S 3356, 3359,3201  ++ */
    /*! IPDU timeout actions and notification will be processed for The signals 
	that doesn't have update bits only and it's configured timeout*/
	if ( (bTimeOutconf == (boolean)TRUE) && (bUpdateBitconf == (boolean)FALSE) )
          /*siganls with UB with be monitored separately*/
    {    
/*PRQA S 3356, 3359,3201  -- */
      if(u8TimeOutAction == (uint8)Com_u8TIMEOUT_ACT_REPLACE)
      {
        if((u8SigContainer ==(uint8) Com_u8SIGNAL) ||(u8StructType == (uint8)Com_u8SIG_STRUCT_SIG) )
       /*! replace the signal value with the init one*/
        {          
          (void)Com_pkvidInitSigObjnOldVal(u8StructType,u16SigIx,FALSE);
        }
       #if ((Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))     
		else if ((u8SigContainer == (uint8)Com_u8SIGNALGROUP) || (u8SigContainer==(uint8)Com_u8GWSIGNALGROUP) )
        {
          /* !Deviation: [3353]  (The variable 'u16GroupSigIx' is 
         possibly unset at this point..) */
         /*[3353](The variable 'u16GroupSigIx' is possibly unset at this point..)*/
         /*[3347](The variable is apparently unset at this point.)*/
           /*variable will always be initialized before being used as it
            is protected by the above condition */
       /*PRQA S 3353 , 3347 ++*/
          /*! loop on all group signals and Replcae its Objects by Init values*/
		  for (u16SigLoopIx = u16GroupSigIx;
          u16SigLoopIx < (u16GroupSigIx  + u16GroupSigNb );
          u16SigLoopIx++)
         /*PRQA S 3353 , 3347 --*/
          {
            (void)Com_pkvidInitSigObjnOldVal(Com_u8SIG_STRUCT_GROUPSIG ,u16SigLoopIx,FALSE);
          }
        
        }
        #endif /*Com_u16NO_OF_GROUP_SIGSLT*/
        else
        {
       /*no time out action is configured for description types*/
        }
 
      }
      else
      {
    /*timeout action = Com_u8TIMEOUT_ACT_NONE*/
    /*do nothing*/
      }
	  /*! Check timeout notifications and call it*/
      if(pfvidTimeOutNotify != (VAR(Com_tpfvidTimeoutNotification,AUTOMATIC))NULL_PTR)
      {
        (*pfvidTimeOutNotify)();
      }
      else
      {
    /*no notification is configured*/
    /*do nothing , do not call the timeout notification*/
      }
    }
    else
    {
 /*no timeout is configured*/
 /*do nothing*/
    } 

    u8StructType = (uint8)0xFFu;

  }
}

#endif
/*PRQA S 3205,3199, 3203  -- */
 /*  PRQA S 4700 -- */
 
 /*************************************************************************/
/*! \Description: The service Com_ReceiveSignalGroup copies the received\n
 signal group objects extracted from the I-PDU to the shadow buffer.\n

**************************************************************************/
/* !Deviation: [8023]  (The name of the function does not  respect the naming
conventions.) */
/*[8523](The Type field of the function does notrespect the naming conventions.)*/
/*function names are mandated by AUTOSAR*/
/*PRQA S 8523 , 8023 ++ */
 /*! \Trace_To : Com-CDD-RxHandler-0006(0) ,Com-CDD-RxHandler-5628(0)
Com-CDD-RxHandler-5636(0) ,Com-CDD-RxHandler-5641(0) , Com-CDD-RxHandler-5687(0) , 
Com-CDD-0219(0) , Com-CDD-0218(0)*/
 /* !Deviation: [3205]  ( Some of the local varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S 3205  ++ */
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
FUNC(uint8,COM_CODE) Com_ReceiveSignalGroup (
                    VAR(Com_SignalGroupIdType,AUTOMATIC)         SignalGroupId)
/*PRQA S 8523 , 8023 -- */
{
  /*local variables definition*/
  VAR(uint8,AUTOMATIC)                                       u8RxSigGrpRet ;
  VAR(boolean,AUTOMATIC)                                     bIsIpduGrpActive;
 /*PRQA S 8018 , 8318, 8518  ++ */
  P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,COM_CALIB_CONST)   pkstrLocSigGrpPB;  
/*PRQA S 8018 , 8318, 8518  -- */

  u8RxSigGrpRet = COM_SERVICE_NOT_AVAILABLE;
  if (Com_enueStatus == COM_UNINIT)
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignalGroup, COM_E_UNINIT);
    #endif /*COM_DEV_ERROR_DETECT*/
  }
  else if (SignalGroupId > Com_u16SIGNALGROUPIDMAX)
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignalGroup, COM_E_PARAM);
    #endif /*COM_DEV_ERROR_DETECT*/
  }
  else
  {
    #if (Com_u16NO_OF_GROUP_SIGSLT > 0u)
    Com_vidCopySigObj2Shadow(SignalGroupId);
    /*check if the ipdu is active or not*/
	/*PRQA S 8018 , 8318, 8518  ++ */
    pkstrLocSigGrpPB = pkstrGET_PB_SIGGRP_PTR(SignalGroupId);
	/*PRQA S 8018 , 8318, 8518  ++ */
	
	SchM_Enter_Com_IPduStatus_0E();
    bIsIpduGrpActive = Com_bIpduCheckActive(pkstrLocSigGrpPB->u16IPduIndex);  
	SchM_Exit_Com_IPduStatus_0E();
	
    if(bIsIpduGrpActive == TRUE)
    {
      u8RxSigGrpRet = E_OK;
    }
    else
    {
  /*Stopped Ipdu Group*/
  /* in this case  u8RxSigGrpRet = COM_SERVICE_NOT_AVAILABLE*/
    }
    #endif /* Com_u16NO_OF_GROUP_SIGSLT > 0u */
  }
  return u8RxSigGrpRet;
}
#endif /*Com_bSIGNAL_GROUP_SUPPORT*/
/*PRQA S 3205  -- */
/* !Deviation: [4700]  ( here has been an infringement of a threshold on the
     specified metric)
 Further decomposition of this function will affect its overall performance 
 so no other meaningfull division is required*/
 /*  PRQA S 4700 ++ */   


 /*************************************************************************/
/*! \Description: Com_ReceiveShadowSignal shall update the group signal that\n
  is referenced by SignalDataPtr with the data in the shadow buffer.\n

**************************************************************************/
/*[8523](The Type field of the function does notrespect the naming conventions.)*/
 /* !Deviation: [8023]  (The name of the function does not  respect the naming
conventions.) */
/*function names are mandated by AUTOSAR*/
/*PRQA S 8023 , 8523 ++ */
 /* !Deviation: [3205]  ( Some of the local varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S 3205  ++ */
 /*! \Trace_To :Com-CDD-RxHandler-0007(0) , Com-CDD-RxHandler-5629(0) , 
 Com-CDD-0222(0) , Com-CDD-0223(0) , */
 /* !Deviation: [3673]  (The pointer is Modified in the normal case  but in some special
 Configurations it will not be modified but it's not a pointer to const .) */
 /*PRQA S 3673 ++ */
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
FUNC(void,COM_CODE) Com_ReceiveShadowSignal (
                    VAR(Com_SignalIdType,AUTOMATIC)     SignalId ,
                    P2VAR(void,AUTOMATIC,COM_APPL_DATA) SignalDataPtr)
/*PRQA S 8023 , 8523 -- */                    
{
  /*local variable declaration*/
  P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,COM_CALIB_CONST)   pkstrLocGrpSigPB;
  VAR(uint16_least,AUTOMATIC)                                u16LoopIx;
  VAR(uint16,AUTOMATIC)                                      u16SigByteLen;
  VAR(uint16,AUTOMATIC)                                      u16SigIx;
  
#if(Com_u16NO_OF_GROUP_SIGSLT > 0u)
  P2VAR(uint8,AUTOMATIC,TYPEDEF) pu8SigObjU8U8N;
  P2CONST(uint16, AUTOMATIC,AUTOMATIC) pku16ShadowBufIdx;
  P2VAR(boolean,AUTOMATIC,TYPEDEF) pbSigObjB;
  P2VAR(sint8,AUTOMATIC,TYPEDEF)ps8SigObjS8;
  P2VAR(uint16,AUTOMATIC,TYPEDEF)pu16SigObjU16;
  P2VAR(sint16,AUTOMATIC,TYPEDEF)ps16SigObjS16;
  P2VAR(uint32,AUTOMATIC,TYPEDEF)pu32SigObjU32;
  P2VAR(sint32,AUTOMATIC,TYPEDEF)ps32SigObjS32;
  
#if(Com_bFLOAT_SIGNAL_SUPPORT == STD_ON) 
  P2VAR(float32,AUTOMATIC,TYPEDEF)pf32SigObjF32;
  P2VAR(float64,AUTOMATIC,TYPEDEF)pf64SigObjF64;
#endif
#endif
  if ( SignalDataPtr ==  NULL_PTR )
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveShadowSignal, COM_E_PARAM_POINTER);
    #endif
  }
  else if (Com_enueStatus == COM_UNINIT)
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveShadowSignal, COM_E_UNINIT);
    #endif
  }
  else if ((SignalId > Com_u16SIGNALIDMAX)||
          (u8GET_SIG_STRUCT_TYPE(SignalId) != (uint8)Com_u8SIG_STRUCT_GROUPSIG)||
          (u8GET_GRPSIG_DIR(SignalId)!= Com_u8SIG_DIR_RECEIVE)
         )
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveShadowSignal, COM_E_PARAM);
    #endif
  }
  else
  {

 #if (Com_u16NO_OF_GROUP_SIGSLT > 0u) 
  /*No Development Error occured , i.e Normal operation*/
    u16SigIx = u16GET_SIGAL_INDEX(SignalId);
	pkstrLocGrpSigPB = pkstrGET_PBGRPSIGPTR_IX(u16SigIx);
    u16SigByteLen    = u16GET_U8N_GRPSIG_LEN(u16SigIx);

	pku16ShadowBufIdx = &(pkstrLocGrpSigPB->u16ShadowBufferIndex);
	
	pbSigObjB =     pkB_GET_SIG_OBJ_VALUEB(0);
	pu8SigObjU8U8N =   pku8GET_SIG_OBJ_VALUEU8(0);
	ps8SigObjS8 =   pks8GET_SIG_OBJ_VALUES8(0);
	pu16SigObjU16 = pku16GET_SIG_OBJ_VALUEU16(0);
	ps16SigObjS16 = pks16GET_SIG_OBJ_VALUES16(0);
	pu32SigObjU32 = pku32GET_SIG_OBJ_VALUEU32(0);
	ps32SigObjS32 = pks32GET_SIG_OBJ_VALUES32(0);
	
#if(Com_bFLOAT_SIGNAL_SUPPORT == STD_ON) 
	pf32SigObjF32 = pkf32GET_SIG_OBJ_VALUEF32(0);
	pf64SigObjF64 = pkf64GET_SIG_OBJ_VALUEF64(0);
#endif

    /*fill the content of the SignalDataPtr with the corresponding signal object data */
    /*last known value will be returned , or its init value , even for a stopped Ipdu */
    switch (pkstrLocGrpSigPB->u8SignalType)
    {
      case Com_u8SIGNAL_TYPE_BOOLEAN:
      *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =
      pbSigObjB[*pku16ShadowBufIdx];
      break;

      case Com_u8SIGNAL_TYPE_UINT8:
      *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =
      pu8SigObjU8U8N[*pku16ShadowBufIdx];
      break;

      case Com_u8SIGNAL_TYPE_SINT8:
      *(P2VAR(sint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =
      ps8SigObjS8[*pku16ShadowBufIdx];
      break;

      case Com_u8SIGNAL_TYPE_UINT16:
      SchM_Enter_Com_SigObjU16_0f();
      *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =
      pu16SigObjU16[*pku16ShadowBufIdx];
      SchM_Exit_Com_SigObjU16_0f();
      break;

      case Com_u8SIGNAL_TYPE_SINT16:
      SchM_Enter_Com_SigObjS16_0f();
      *(P2VAR(sint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =
      ps16SigObjS16[*pku16ShadowBufIdx];
      SchM_Exit_Com_SigObjS16_0f();
      break;

      case Com_u8SIGNAL_TYPE_UINT32:
      SchM_Enter_Com_SigObjU32_0f();
      *(P2VAR(uint32,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =
      pu32SigObjU32[*pku16ShadowBufIdx];
      SchM_Exit_Com_SigObjU32_0f();
      break;

      case Com_u8SIGNAL_TYPE_SINT32:
      SchM_Enter_Com_SigObjS32_0f();
      *(P2VAR(sint32,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =
      ps32SigObjS32[*pku16ShadowBufIdx];
      SchM_Exit_Com_SigObjS32_0f();
      break;
#if(Com_bFLOAT_SIGNAL_SUPPORT == STD_ON) 
      case Com_u8SIGNAL_TYPE_FLOAT32:
      SchM_Enter_Com_SigObjF32_0f();
      *(P2VAR(float32,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =
      pf32SigObjF32[*pku16ShadowBufIdx];
      SchM_Exit_Com_SigObjF32_0f();
      break;

      case Com_u8SIGNAL_TYPE_FLOAT64:
      SchM_Enter_Com_SigObjF64_0f();
      *(P2VAR(float64,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =
      pf64SigObjF64[*pku16ShadowBufIdx];
      SchM_Exit_Com_SigObjF64_0f();
      break;
#endif
      case Com_u8SIGNAL_TYPE_UINT8N :
      SchM_Enter_Com_SigObjU8U8N_0f();
      for (u16LoopIx = 0 ; u16LoopIx < u16SigByteLen ; u16LoopIx++)
      {
        ((P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr)[u16LoopIx] =
        pu8SigObjU8U8N[(*pku16ShadowBufIdx) + u16LoopIx];
      }
      SchM_Exit_Com_SigObjU8U8N_0f();
      break;
      default:
      break;
    }

  #endif /*(Com_u16NO_OF_GROUP_SIGSLT > 0) */
  }
}
#endif /*Com_bSIGNAL_GROUP_SUPPORT*/
 /*PRQA S 3673 -- */
 /*PRQA S 3205  --*/
 /*  PRQA S 4700 -- */
 


  /*************************************************************************/
/*! \Description: The service Com_ReceiveDynSignal returns in Length the\n
 length of the dynamical length signal and in SignalDataPtr a pointer to\n

 the data of the signal identified by SignalId\n

**************************************************************************/
/* !Deviation: [8023]  (The name of the function does not  respect the naming
conventions.) */
/*[8523](The Type field of the function does notrespect the naming conventions.)*/
/*PRQA S 8523 , 8523 ++ */
/*function names are mandated by AUTOSAR*/
/*PRQA S 8523 , 8023 ++ */
 /* !Deviation: [3205]  ( Some of the local varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S 3205 ++ */
 /*! \Trace_To : Com-CDD-RxHandler-0005(0) , Com-CDD-0207(0) , Com-CDD-0208(0) ,
 Com-CDD-0209(0) , Com-SRS-0206(0) ,  */
  /* !Deviation: [3673]  (The pointer "SignalDataPtr" and "Length" is Modified 
  in the normal case  but in some special Configurations it will not be modified
  but it's not a pointer to const .) */
 /*PRQA S 3673 ++ */
#if (Com_bDATA_TP_SUPPORT == STD_ON)
FUNC(uint8,COM_CODE) Com_ReceiveDynSignal(
                      VAR(Com_SignalIdType,AUTOMATIC)SignalId,
                      P2VAR(void,AUTOMATIC,COM_APPL_DATA) SignalDataPtr ,
                      P2VAR(uint16,AUTOMATIC,COM_APPL_DATA) Length )
/*PRQA S 8023 -- */
{
  /*local variable definition*/

  VAR(uint16,AUTOMATIC)                                u16SigObjIx;
  VAR(uint16,AUTOMATIC)                                u16DynSigMaxLen;
  VAR(uint16,AUTOMATIC)                                u16DynSigLen;
  VAR(uint16,AUTOMATIC)                                u16DynSigStartIx;
  VAR(uint16_least,AUTOMATIC)                          u16LoopIx;
  VAR(uint16,AUTOMATIC)                                u16IpduId;
  VAR(boolean,AUTOMATIC)                               bIsIpduActive;
  VAR(uint16,AUTOMATIC)                                u16SigIx;
  P2CONST(Com_tstrSignalPB,AUTOMATIC,COM_CALIB_CONST)  pkstrLocSigPB;

#if(Com_u16NO_OF_SIGNAL > 0u)
  P2VAR(uint8,AUTOMATIC,TYPEDEF)						pu8SigObjU8U8N;
#endif
  VAR(uint8,AUTOMATIC)                                 u8RxDynSigRet;
   /*in case a det error occured this shall be the return value*/
  u8RxDynSigRet = COM_SERVICE_NOT_AVAILABLE;

  if (( SignalDataPtr ==  NULL_PTR ) ||
       (Length == (P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))NULL_PTR))
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveDynSignal, COM_E_PARAM_POINTER);
    #endif
  }
  else if (Com_enueStatus == COM_UNINIT)
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveDynSignal, COM_E_UNINIT);
    #endif
  }
  else if ((SignalId > Com_u16SIGNALIDMAX)||
          ((u8GET_SIG_STRUCT_TYPE(SignalId) != (uint8)Com_u8SIG_STRUCT_SIG) ))
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveDynSignal, COM_E_PARAM);
    #endif
  }
  else
  {

 #if(Com_u16NO_OF_SIGNAL > 0u) 
     
	u16SigIx    = u16GET_SIGAL_INDEX(SignalId);
    pkstrLocSigPB = pkstrGET_PBSIGPTR_IX(u16SigIx);
    u16SigObjIx   =   pkstrLocSigPB->u16SignalObjectIndex ;
    u16DynSigMaxLen =  u16GET_U8N_SIGNAL_LEN(u16SigIx);
    u16IpduId       = pkstrLocSigPB->u16IPduIndex ;
	pu8SigObjU8U8N = pku8GET_SIG_OBJ_VALUEU8(0);
	SchM_Enter_Com_IPduStatus_22();
    bIsIpduActive =Com_bIpduCheckActive(u16IpduId);
	SchM_Exit_Com_IPduStatus_22();
	
	
    if (bIsIpduActive== (boolean)TRUE)
    {

    /*read the previously calculated dynamic syganl length*/
      SchM_Enter_Com_SigObjU8U8N_22();
      u16DynSigLen = (uint16)(((uint16)( ( (uint16)pu8SigObjU8U8N[u16SigObjIx ] ) << (uint16)8 ) )|
                        ((uint16)pu8SigObjU8U8N[u16SigObjIx + (uint16)1]));
      SchM_Exit_Com_SigObjU8U8N_22();
                                              
      if (*Length < u16DynSigLen )
      {
      /*the receiver buffer size is less than the received signal */
        u8RxDynSigRet = E_NOT_OK ;
      }
      else
      {
      /*fill the length out variable with the calculated dynamic signal length*/
        *Length = u16DynSigLen ;
      /*copy the dynamic signal data to the loacation specified by SignalDataPtr*/
      /*the construction of the signal object in case of dynamic signal is as follow :

       |High Byte of the calculate length| | ->Obj Index
       |Low Byte of the calculate Length | | Max conf size
       |maybe unused bytes               | |
       |maybe unused bytes               | |
       |.................................| |
       |First Used Byte                  | |->Start Ix     |
       |.................................| |               |Dyn Signal Length
       |Last Used Byte                   | |               |

       */
       /*u16DynSigStartIx = Signal Object Index + 2 +Max conf size - 1
                         - (Dyn Signla Length - 1)  */
        u16DynSigStartIx = ( u16SigObjIx + (uint16)2 + u16DynSigMaxLen ) - u16DynSigLen  ;
        SchM_Enter_Com_SigObjU8U8N_22();      
        for(u16LoopIx = 0 ; u16LoopIx <u16DynSigLen ; u16LoopIx++ )
        {

          ((P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr)[u16LoopIx] =
          pu8SigObjU8U8N[(u16DynSigStartIx+ u16LoopIx)];
        }
        SchM_Exit_Com_SigObjU8U8N_22();      
        u8RxDynSigRet = E_OK ;
      }
    }
    else
    {
    /*IPDU group was stopped*/
    }
#endif /*(Com_u16NO_OF_SIGNAL > 0)*/  
  }

  return u8RxDynSigRet;
}
 /*PRQA S 3673 -- */
 
/*PRQA S 3205   -- */
#endif /*Com_bDATA_TP_SUPPORT*/

/*************************************************************************/
/*! \Description: Com_StartOfReception returns the pointer to the size of the \n
  AUTOSAR COM module's internal receive buffer for the I-PDU with ID ComRxPduId.\n
  The parameter 'TpSduInfoPtr' is currently not used by COM (NOT SUPPORTED)
**************************************************************************/
/* !Deviation: [8023]  (The name of the function does not  respect the naming
conventions.) */
/*[8523](The Type field of the function does notrespect the naming conventions.)*/
 /* !Deviation: [8023]  (The name of the function does not  respect the naming
conventions.) */
/*PRQA S 8023 , 8523 , 8523 ++ */
/*function names are mandated by AUTOSAR*/
/* !Deviation: [3205]  ( Some of the local varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S 3205,3203,3199 ++ */
 /*! \Trace_To :Com-CDD-RxHandler-0031(0) , Com-CDD-RxHandler-0033(0) ,
Com-CDD-RxHandler-5647(0) , Com-CDD-RxHandler-5648(0) , Com-CDD-0250(0) ,
Com-CDD-0249(0) , Com-CDD-0252(0) , Com-CDD-0253(0) ,  
Com-CDD-0248(0) , */
#if (Com_bDATA_TP_SUPPORT == STD_ON)
FUNC(BufReq_ReturnType ,COM_CODE) Com_StartOfReception (
              VAR(PduIdType,AUTOMATIC)                        ComRxPduId,
/* !Deviation: [2495]  TpSduInfoPtr is added for AR4.1.2 compatability */
/*PRQA S 3206 ++ */
			  P2VAR( PduInfoType ,AUTOMATIC ,COM_APPL_DATA) TpSduInfoPtr,
/*PRQA S 3206 -- */
			  VAR(PduLengthType ,AUTOMATIC)                   TpSduLength,
              P2VAR( PduLengthType ,AUTOMATIC ,COM_APPL_DATA) RxBufferSizePtr )
/*PRQA S 8023 , 8523 , 8023 -- */
{
/*local varaibles definitions*/
  VAR(BufReq_ReturnType,AUTOMATIC)                    enuBufferStatus ;

  VAR(boolean,AUTOMATIC)                              bIsIpduActive;
  P2CONST(Com_tstrRxIPdu,AUTOMATIC,COM_CALIB_CONST)   pkstrLocRXIpduPB;
  VAR(uint16, AUTOMATIC)                              u16LastSigIxInIpduMap;
  P2CONST(Com_tstrSignalPB,AUTOMATIC,COM_CALIB_CONST) pkstrLocSigPB;
  VAR(uint16,AUTOMATIC)                               u16SigIx;
  VAR(uint16,AUTOMATIC)                               u16SigId;
  VAR(uint16,AUTOMATIC)                               u16DynSigBytePos;
  VAR(uint16,AUTOMATIC)                               u16DynSigMaxLen;  
  VAR(uint32,AUTOMATIC)                               u32IpduLastByteIx;
#if(Com_u16NO_OF_SIGNAL > 0u)      
	P2VAR(uint8,AUTOMATIC,TYPEDEF) pu8IPduBuf;  
#endif
  P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,COM_CALIB_CONST)   pkstrIPduToSignalMapp;
  P2VAR(uint16,AUTOMATIC,COM_CALIB_CONST)   			pu16TpByteCtr;

  enuBufferStatus  = BUFREQ_E_NOT_OK;

  if ( RxBufferSizePtr ==
      (P2VAR( PduLengthType ,AUTOMATIC ,COM_APPL_DATA))NULL_PTR )
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                          COMServiceId_StartOfReception,COM_E_PARAM_POINTER);
    #endif
  }
  else if (Com_enueStatus == COM_UNINIT)
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                          COMServiceId_StartOfReception, COM_E_UNINIT);
    #endif
  }
  else if ((ComRxPduId > Com_u16RXIPDUIDMAX) ||
          (u8GET_IPDU_DIR(ComRxPduId) != (uint8) Com_u8DIRECTION_RX) ||
          (u8GET_RX_IPDU_TYPE(ComRxPduId) != (uint8) Com_u8IPDU_TYPE_TP))
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                          COMServiceId_StartOfReception, COM_E_PARAM);
    #endif
  }
  else
  {
	SchM_Enter_Com_IPduStatus_25();
    bIsIpduActive =Com_bIpduCheckActive(ComRxPduId);
    SchM_Exit_Com_IPduStatus_25();
	
	if (bIsIpduActive== (boolean)TRUE)
    {
      pkstrLocRXIpduPB = pkstrGET_RX_IPDU_PTR(ComRxPduId);
     /*check on the given length of the TP buffer*/
      if (TpSduLength > pkstrLocRXIpduPB->u16IPduLength )
      {
        enuBufferStatus = BUFREQ_E_OVFL;
      }
      else
      {
      /*TP length can be placed in the TP buffer */
      /*1.Update the buffer length with the available buffer size*/
      /*based on the current design which allocate a buffer for each TP IPDU
      , with a size = maximum size of the TP Ipdu */
        * RxBufferSizePtr = pkstrLocRXIpduPB->u16IPduLength ;
      /*2.Calculate Dynamic signal size , and write it to the first 2 bytes
      of the signal object , if applicable */
        u16LastSigIxInIpduMap = (uint16)(((uint16)((pkstrLocRXIpduPB->u16IPduSigMappingIndex) +
                                 (pkstrLocRXIpduPB->u16IPduNoOfSignals) ))    -
                                 (uint16)1u);
  #if(Com_u16NO_OF_SIGNAL > 0u) 
     pkstrIPduToSignalMapp = pkstrGET_IPDU_SGL_MAP_PTR(0);
        if (pkstrIPduToSignalMapp[u16LastSigIxInIpduMap].u8Type ==(uint8)Com_u8SIGNAL )
        {
          
          u16SigIx = pkstrIPduToSignalMapp[u16LastSigIxInIpduMap].u16Index;
          u16SigId = u16GET_SIG_ID_FROM_IX(u16SigIx);
          pkstrLocSigPB = pkstrGET_PBSIGPTR_IX(u16SigIx);
          if (pkstrLocSigPB->u8SignalType == Com_u8SIGNAL_TYPE_UINT8DYN)
          {
             /*<dynamic signal length in bytes> =
             <received I PDU length in bytes> - <ComBitPosition of dynamic
             length signal> / 8*/
            u16DynSigMaxLen = Com_akstreSignalLT[u16SigIx].u16SignalLength;
            u16DynSigBytePos =  (pkstrLocSigPB->u16BitPosition) >> (uint16)3 ;
            u32IpduLastByteIx = pkstrLocRXIpduPB->u32IPduBufferIndex +
                                 (uint32)u16DynSigBytePos +
                                 (uint32)u16DynSigMaxLen  + (uint32)1;

			pu8IPduBuf		= pkstrGET_IPDU_BUFF_PTR(0);
             /*write the Ipdu length in the last 2 byte of Ipdu*/
            SchM_Enter_Com_IPduBuff_25();
            pu8IPduBuf[u32IpduLastByteIx - (uint32)1 ] = 
            (uint8)((uint16)(TpSduLength & (uint16)0xFF00u) >> (uint16)8u) ;
            pu8IPduBuf[u32IpduLastByteIx] = (uint8)(TpSduLength & (uint16)0x00FFu);
            SchM_Exit_Com_IPduBuff_25();

          }
          else
          {
           /*signal is not dynamic , do nothing*/
          }


        }
        else
        {
         /*do nothing , DYN signal can not be placed in a container other than
          the Com_u8TSIGNAL one */
        }
  #endif/*(Com_u16NO_OF_SIGNAL > 0u)*/
      /*3.reset the counter of the received bytes numbers */ 
	  pu16TpByteCtr = pkstrGET_TP_IPDU_CTR_PTR(0);
	  pu16TpByteCtr[pkstrLocRXIpduPB->
        u16TpIPduByteCtrIndex] = (uint16)0;
      /*4.Update the enuBufferStatus */
        enuBufferStatus = BUFREQ_OK;

      }/*length is correct*/
    }
    else
    {
    /*stopped Ipdu , do not update the buffer size*/
    }
  }/*no det occured */
  return enuBufferStatus ;
}
/*PRQA S 3205,3203, 3199 --*/
#endif /*Com_bDATA_TP_SUPPORT*/
/*************************************************************************/
/*! \Description :Called once upon reception of each segment. Within this\n
 call, the received data is copied to the receive TP buffer. The API might\n
  only be called with an SduLength greater 0 if the RxBufferSizePtr returned\n
   by the previous API call indicates sufficient receive buffer\n
   (SduLength = RxBufferSizePtr). The function must only be called if the\n
   connection has been accepted by an initial call to Com_StartOfReception.\n

**************************************************************************/
   /* !Deviation: [8023]  (The name of the function does not  respect the naming
conventions.) */
/*[8523](The Type field of the function does notrespect the naming conventions.)*/
/*PRQA S 8023 , 8523 , 8523 ++ */
/*function names are mandated by AUTOSAR*/
/* !Deviation:[3673] (The object addressed by the pointer parameter 'PduInfoPtr'
   is not modified and so the pointer could be of type 'pointer to const')
   This prototype is maindated by the AUTOSAR*/
/* PRQA S 3673 ++ */
 /*! \Trace_To :Com-CDD-RxHandler-5661(0) , Com-CDD-RxHandler-0030(0) ,
Com-CDD-RxHandler-0029(0) , Com-CDD-RxHandler-5746(0) , Com-CDD-0254(0),
Com-CDD-RxHandler-5747(0)
*/
#if (Com_bDATA_TP_SUPPORT == STD_ON)
FUNC(BufReq_ReturnType, COM_CODE) Com_CopyRxData (
              VAR(PduIdType,AUTOMATIC)                          PduId,
/* Removed const from following parameter as per PDUR and DCM specs */
              P2VAR(PduInfoType,AUTOMATIC,COM_APPL_DATA)      PduInfoPointer ,
              P2VAR( PduLengthType , AUTOMATIC , COM_APPL_DATA) RxBufferSizePtr)
/*PRQA S 8023, 8523 , 8523 -- */
/* PRQA S 3673 -- */
{
  VAR(BufReq_ReturnType,AUTOMATIC)                    enuBufferStatus ;

  P2CONST(Com_tstrRxIPdu,AUTOMATIC,COM_CALIB_CONST)   pkstrLocRXIpduPB;
  VAR(boolean,AUTOMATIC)                              bIsIpduActive;
  VAR(uint16_least,AUTOMATIC)                         u16LoopIx;
  VAR(uint16,AUTOMATIC)                               u16PreviousTpByteCnt;

  P2VAR(uint8,AUTOMATIC,TYPEDEF) pu8IPduBuf;
  P2CONST(uint32, AUTOMATIC,AUTOMATIC) pku32IPduBufIdx;
  P2VAR(uint8, AUTOMATIC, AUTOSAR_COMSTACKDATA) pudtSduDataPtr;
  P2CONST(PduLengthType, AUTOMATIC,AUTOMATIC) pkudtSduLengthPtr;
  P2VAR(uint16,AUTOMATIC,COM_CALIB_CONST)      pu16TpByteCtr;

  enuBufferStatus = BUFREQ_E_NOT_OK;
  if ( (PduInfoPointer ==
       (P2CONST(PduInfoType,AUTOMATIC,COM_APPL_DATA))NULL_PTR )||
      (RxBufferSizePtr ==
       (P2VAR( PduLengthType , AUTOMATIC , COM_APPL_DATA))NULL_PTR)
    )

  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                          COMServiceId_CopyRxData,COM_E_PARAM_POINTER);
    #endif
  }
  else if (Com_enueStatus == COM_UNINIT)
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                          COMServiceId_CopyRxData, COM_E_UNINIT);
    #endif
  }
  else if ((PduId > Com_u16RXIPDUIDMAX) ||
          (u8GET_IPDU_DIR(PduId) != (uint8) Com_u8DIRECTION_RX)||
          (u8GET_RX_IPDU_TYPE(PduId) != (uint8) Com_u8IPDU_TYPE_TP))
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                          COMServiceId_CopyRxData, COM_E_PARAM);
    #endif
  }
  else
  {
  /*no DET error occured*/
  /*check if the ipdu is still active */
	
	SchM_Enter_Com_IPduStatus_23();
    bIsIpduActive =Com_bIpduCheckActive(PduId);
	SchM_Exit_Com_IPduStatus_23();
	
    pkstrLocRXIpduPB = pkstrGET_RX_IPDU_PTR(PduId);
    pu16TpByteCtr = pkstrGET_TP_IPDU_CTR_PTR(0);
	if (bIsIpduActive== (boolean)TRUE)
    {
      u16PreviousTpByteCnt =
      pu16TpByteCtr[pkstrLocRXIpduPB->u16TpIPduByteCtrIndex];

	  pu8IPduBuf = pkstrGET_IPDU_BUFF_PTR(0);
	  pku32IPduBufIdx = &(pkstrLocRXIpduPB->u32IPduBufferIndex);
	  pudtSduDataPtr = PduInfoPointer->SduDataPtr;
	  pkudtSduLengthPtr = &(PduInfoPointer->SduLength);
    /*copy the rx data to the corresponding buffer place */
      SchM_Enter_Com_IPduBuff_23();      
      for (u16LoopIx = 0 ; u16LoopIx < *pkudtSduLengthPtr ;
            u16LoopIx ++)
      {
        pu8IPduBuf[((*pku32IPduBufIdx) + u16PreviousTpByteCnt + u16LoopIx )] =
            pudtSduDataPtr[u16LoopIx];             
      }
      SchM_Exit_Com_IPduBuff_23();
    /*update the number of the received byte by adding */
      pu16TpByteCtr[pkstrLocRXIpduPB->u16TpIPduByteCtrIndex] +=  PduInfoPointer->SduLength;
    /*calculate the size of the rest free buffer bytes */
      *RxBufferSizePtr  =  pkstrLocRXIpduPB->u16IPduLength -
                           pu16TpByteCtr[pkstrLocRXIpduPB->u16TpIPduByteCtrIndex] ;
      enuBufferStatus = BUFREQ_OK;
    }
    else
    {
    /*Ipdu is stopped*/
      /*reset the counter of the received bytes numbers */
      pu16TpByteCtr[pkstrLocRXIpduPB->
      u16TpIPduByteCtrIndex] = (uint16)0;
    }
  }
  return enuBufferStatus ;
}
#endif	/*Com_bDATA_TP_SUPPORT*/


 /*************************************************************************/
/*! \Description :By a call to Com_TpRxIndication the AUTOSAR COM module\n
 starts the processing of the received large or dynamic length IPDU.\n

**************************************************************************/
/* !Deviation: [8023]  (The name of the function does not  respect the naming
conventions.) */
/*[8523](The Type field of the function does notrespect the naming conventions.)*/
/*PRQA S 8023 , 8523 ++ */
/*function names are mandated by AUTOSAR*/
 /*! \Trace_To : Com-CDD-RxHandler-5660(0) ,Com-CDD-RxHandler-0003(0) ,
Com-CDD-RxHandler-0037(0) ,Com-CDD-RxHandler-0038(0) ,
Com-CDD-RxHandler-0042(0) ,Com-CDD-RxHandler-0055(0) ,
Com-CDD-RxHandler-0066(0) ,Com-CDD-RxHandler-0067(0) ,
Com-CDD-RxHandler-5615(0) ,Com-CDD-RxHandler-5618(0) ,
Com-CDD-RxHandler-5621(0) ,Com-CDD-RxHandler-5624(0) ,
Com-CDD-RxHandler-5627(0) ,Com-CDD-RxHandler-5630(0) ,
Com-CDD-RxHandler-5631(0) ,Com-CDD-RxHandler-5683(0) ,
Com-CDD-RxHandler-5686(0) , Com-CDD-0241(0) , Com-CDD-0278(0) ,
Com-CDD-0283(0) , Com-CDD-0243(0) , Com-CDD-5748(1), Com-CDD-5514(1)*/
#if (Com_bDATA_TP_SUPPORT == STD_ON)
FUNC(void,COM_CODE) Com_TpRxIndication (
                    VAR(PduIdType, AUTOMATIC)      PduId,
                    VAR(Std_ReturnType, AUTOMATIC) Result)
/*PRQA S 8523 , 8023 -- */
{
/*local variable declaration*/
/* !Deviation: [8018]  (The name of the constant (const) does not  respect the naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) does not  respect the naming conventions.)*/
/*[8518] (The Separator of the constant (const) does not  respect the naming conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518 ++ */

  P2CONST(Com_tstrRxIPdu,AUTOMATIC,COM_CALIB_CONST) pkstrLocRXIpduPB;
/*PRQA S 8018 , 8318 , 8518 -- */
  VAR(boolean, AUTOMATIC)                           bCalloutReturn;
  /* !Deviation:[3672]  (Using non-const pointer to function.)
  the pointer to function can not be declared as constant , as it will
  be assigned a value calculated by the code depending on the PduId*/
  /*PRQA S 3672 ++ */
/*[ 8318]  ( the Component ID of the constant (const) does not  respect the naming conventions.)*/
/*[8518] (The Separator of the constant (const) does not  respect the naming conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518 ++ */
  VAR(Com_tpfbRxIpduCallout, AUTOMATIC)             pfbRxCallout;
  /*PRQA S 8018 , 8318, 8518 ++ */
  /*PRQA S 3672 -- */
  VAR(boolean, AUTOMATIC)                           bIpduIsActive;

  VAR(uint16,AUTOMATIC)                             u16IpduSigMapIndx;
  VAR(uint16,AUTOMATIC)                             u16MaxSigNo;
  VAR(uint16_least,AUTOMATIC)                       u16LoopIndex;
  VAR(uint16,AUTOMATIC)                      		u16RxPduIx;
  
#if (Com_bRX_CALLOUT_SUPPORT == STD_ON)
  VAR(uint16,AUTOMATIC)                             u16IPduCalloutIx;
#endif
  
  P2VAR(uint8,AUTOMATIC,COM_APPL_DATA)            pku8IpduFirstByte;
  VAR(PduInfoType,AUTOMATIC)   strPduInfo;                             
  P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF)pkstrIPduToSigMap;
  P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF)pkstrIPduToSigMapTemp;
  P2VAR(uint8,AUTOMATIC,TYPEDEF)					pu8IPduBuf;
  P2VAR(uint16,AUTOMATIC,TYPEDEF)					pu16TpByteCtr;
  VAR(uint16,AUTOMATIC)                       		u16DynLength = 0;

  if (Com_enueStatus == COM_UNINIT)
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_TpRxIndication, COM_E_UNINIT);
    #endif /*COM_DEV_ERROR_DETECT*/
  }
  else if ((PduId > Com_u16RXIPDUIDMAX) ||
          (u8GET_IPDU_DIR(PduId) != (uint8) Com_u8DIRECTION_RX) ||
          (u8GET_RX_IPDU_TYPE(PduId) != (uint8) Com_u8IPDU_TYPE_TP))
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_TpRxIndication, COM_E_PARAM);
    #endif /*COM_DEV_ERROR_DETECT*/
  }
  else
  {
	u16RxPduIx = u16GET_IPDU_INDEX(PduId);
    pkstrLocRXIpduPB    = pkstrGET_RX_IPDU_PTR_IX(u16RxPduIx);
    /*check if the ipdu is active , process it , else discard it */
    pu16TpByteCtr = pkstrGET_TP_IPDU_CTR_PTR(0);
    if (Result == NTFRSLT_OK)
    {
	  #if u16NO_OF_IPDUS_STATUS > 0u
	  SchM_Enter_Com_IPduStatus_1E();
	  bIpduIsActive = ((Com_audteIPduStatus[PduId] & (Com_u8ACTIVE_MASK)) != FALSE);
	  SchM_Exit_Com_IPduStatus_1E();
	  #endif
	  
      if (bIpduIsActive == (boolean)TRUE )
      {
	    pu8IPduBuf = pkstrGET_IPDU_BUFF_PTR(0);
        pku8IpduFirstByte = &pu8IPduBuf[pkstrLocRXIpduPB->u32IPduBufferIndex] ;
		strPduInfo.SduDataPtr = pku8IpduFirstByte;
		
		u16DynLength = u16DynLength | (uint16) pku8IpduFirstByte[pkstrLocRXIpduPB->u16IPduLength];
		u16DynLength = u16DynLength << 8;
		u16DynLength = u16DynLength | (uint16) pku8IpduFirstByte[pkstrLocRXIpduPB->u16IPduLength + 1];
		
		strPduInfo.SduLength =  u16DynLength;
	#if (Com_bRX_CALLOUT_SUPPORT == STD_ON)
	   u16IPduCalloutIx = pkstrLocRXIpduPB->u16IPduCalloutIndex;
      /*Call the corresponding Com_RxIpduCallout if configured*/
		if(u16IPduCalloutIx != (uint16)0xFFFFu)
		{	
		 pfbRxCallout = pfGET_RXIPDU_CALOUTPTR(u16IPduCalloutIx);
		  /* !Deviation: [504]  ( Access of this pointer is protected by 
         the previous if condition) */
         /*PRQA S 504 ++ */
          bCalloutReturn  = (*pfbRxCallout)(PduId,&strPduInfo);
		 /*PRQA S 504 -- */ 
        }
        else
        {
          /*No Callout is configured*/
          bCalloutReturn = TRUE;
        }
        if (bCalloutReturn == TRUE)
        {
	#endif
        /*continue processing the IPDU*/
          /*Ipdu has is deferered , set a flag to process it during the main function rx*/
          if ((pkstrLocRXIpduPB->udteRxIPduFlags & Com_u8RX_IPDUSIGPROCESSING) != Com_u8SIG_PROC_IMMEDIATE)
          {
            /*#if (Com_u16IPDU_DEF_PROC_SIZE > 0U)*/
            /*copy was done during the Com_CopyRxData then set the flag*/
			#if u16NO_OF_IPDUS_STATUS > 0u
			SchM_Enter_Com_IPduStatus_1E();
			Com_audteIPduStatus[PduId] |= Com_u8DEF_PROC_MASK; 
			SchM_Exit_Com_IPduStatus_1E();
			#endif
          }
          else
           /*immediate ipdu*/
          {
               /*continue processing*/
            vidProcessRxIpdu(u16RxPduIx ,pku8IpduFirstByte);
              /*reset the Ipdu byte counter index for Tp Idpus*/
            pu16TpByteCtr[pkstrLocRXIpduPB->u16TpIPduByteCtrIndex] = (uint16)0;

          }
#if (Com_bRX_CALLOUT_SUPPORT == STD_ON)
        }
        else
        {
        /*discard the IPDU due to callout return false*/
        }
#endif

#if (Com_bTO_SUPPORT == STD_ON)
        /*Reset the deadline "IPDU based" monotoring of the recived Ipdu*/
        Com_vidRxIpduResetDM(u16RxPduIx);

        u16IpduSigMapIndx = pkstrLocRXIpduPB->u16IPduSigMappingIndex;
        u16MaxSigNo = pkstrLocRXIpduPB->u16IPduNoOfSignals;
		pkstrIPduToSigMapTemp = pkstrGET_IPDU_SGL_MAP_PTR(0);
        /*Reset the deadline "Signal based" monotoring of the recived Ipdu*/
        for (u16LoopIndex = u16IpduSigMapIndx ;
             u16LoopIndex < (u16IpduSigMapIndx+u16MaxSigNo) ;
             u16LoopIndex++ )
        {
		  pkstrIPduToSigMap = &pkstrIPduToSigMapTemp[u16LoopIndex];
          Com_vidSignalResetDM((pkstrIPduToSigMap->u8Type),
                            (pkstrIPduToSigMap->u16Index));
        }
#endif

      }
    }
    else
    {
    /*Result != NTFRSLT_OK */
    /*reset the Ipdu byte counter index for Tp Idpus*/
      pu16TpByteCtr[pkstrLocRXIpduPB->u16TpIPduByteCtrIndex] = (uint16)0;

    }
  }
}
#endif/*Com_bDATA_TP_SUPPORT*/

#if((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
/* !Deviation: [4700]  ( here has been an infringement of a threshold on the
     specified metric)
 Further decomposition of this function will affect its overall performance 
 so no other meaningfull division is required*/
 /*  PRQA S 4700 ++ */
 /*************************************************************************/
/*! \Description :.\n
**************************************************************************/ 
FUNC(void,COM_CODE) Com_vidCopySigObj2Shadow(
                    VAR(Com_SignalGroupIdType,AUTOMATIC)         u16SignalGroupId)
{
/*Stopped here*/
  VAR(uint16_least,AUTOMATIC)                                u16LoopIndex;
  P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,COM_CALIB_CONST)   pkstrLocGrpSigPB;
  VAR(uint16_least,AUTOMATIC)                                      u16SigLoopIx;
  VAR(uint16,AUTOMATIC)										 u16GroupSigIdx;
  VAR(uint16,AUTOMATIC)										 u16NoOfGroupSig;

  P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,TYPEDEF) pkstrGroupSigPB;
  P2VAR(boolean,AUTOMATIC,TYPEDEF) pbSigObjB;
  P2VAR(uint8,AUTOMATIC,TYPEDEF) pu8SigObjU8U8N;
  P2VAR(sint8,AUTOMATIC,TYPEDEF) ps8SigObjS8;
  P2VAR(uint16,AUTOMATIC,TYPEDEF) pu16SigObjU16;
  P2VAR(sint16,AUTOMATIC,TYPEDEF) ps16SigObjS16;
  P2VAR(uint32,AUTOMATIC,TYPEDEF) pu32SigObjU32;
  P2VAR(sint32,AUTOMATIC,TYPEDEF) ps32SigObjS32;
  
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON)
  P2VAR(float32,AUTOMATIC,TYPEDEF) pf32SigObjF32;
  P2VAR(float64,AUTOMATIC,TYPEDEF) pf64SigObjF64;
#endif
  P2CONST(uint16, AUTOMATIC,AUTOMATIC) pku16ShadowBufIdx;
  P2CONST(uint16, AUTOMATIC,AUTOMATIC) pku16SigObjIdx;

   u16GroupSigIdx = u16GET_GRP_SIG_IX(u16SignalGroupId);
   u16NoOfGroupSig = u16GET_NB_OF_GRPSIG(u16SignalGroupId);

    pkstrGroupSigPB = pkstrGET_PBGRPSIGPTR_IX(0);
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

  for (u16LoopIndex = u16GroupSigIdx; u16LoopIndex < (u16GroupSigIdx +
                        u16NoOfGroupSig); u16LoopIndex++)
  {
    /*u16SigId         = Com_akstreGroupSignalLT[u16LoopIndex].u16SignalId;*/
    pkstrLocGrpSigPB = &(pkstrGroupSigPB[u16LoopIndex]);
	pku16ShadowBufIdx = &(pkstrLocGrpSigPB->u16ShadowBufferIndex);
	pku16SigObjIdx = &(pkstrLocGrpSigPB->u16SignalObjectIndex);
    switch(pkstrLocGrpSigPB->u8SignalType)
    {
      case Com_u8SIGNAL_TYPE_BOOLEAN:
      pbSigObjB[*pku16ShadowBufIdx] =
      pbSigObjB[*pku16SigObjIdx];
      break;
      case Com_u8SIGNAL_TYPE_UINT8:
      pu8SigObjU8U8N[*pku16ShadowBufIdx] =
      pu8SigObjU8U8N[*pku16SigObjIdx];
      break;
      case Com_u8SIGNAL_TYPE_SINT8:
      ps8SigObjS8[*pku16ShadowBufIdx] =
      ps8SigObjS8[*pku16SigObjIdx];
      break;
      case Com_u8SIGNAL_TYPE_UINT16:
      SchM_Enter_Com_SigObjU16();
      pu16SigObjU16[*pku16ShadowBufIdx] =
      pu16SigObjU16[*pku16SigObjIdx];
      SchM_Exit_Com_SigObjU16();
      break;
      case Com_u8SIGNAL_TYPE_SINT16:
      SchM_Enter_Com_SigObjS16();
      ps16SigObjS16[*pku16ShadowBufIdx] =
      ps16SigObjS16[*pku16SigObjIdx];
      SchM_Exit_Com_SigObjS16();
      break;
      case Com_u8SIGNAL_TYPE_UINT32:
      SchM_Enter_Com_SigObjU32();
      pu32SigObjU32[*pku16ShadowBufIdx] =
      pu32SigObjU32[*pku16SigObjIdx];
      SchM_Exit_Com_SigObjU32();
      break;
      case Com_u8SIGNAL_TYPE_SINT32:
      SchM_Enter_Com_SigObjS32();
      ps32SigObjS32[*pku16ShadowBufIdx] =
      ps32SigObjS32[*pku16SigObjIdx];
      SchM_Exit_Com_SigObjS32();
      break;
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON)
      case Com_u8SIGNAL_TYPE_FLOAT32:
      SchM_Enter_Com_SigObjF32();
      pf32SigObjF32[*pku16ShadowBufIdx] =
      pf32SigObjF32[*pku16SigObjIdx];
      SchM_Exit_Com_SigObjF32();
      break;
      case Com_u8SIGNAL_TYPE_FLOAT64:
      SchM_Enter_Com_SigObjF64();
      pf64SigObjF64[*pku16ShadowBufIdx] =
      pf64SigObjF64[*pku16SigObjIdx];
      SchM_Exit_Com_SigObjF64();
      break;
#endif
      case Com_u8SIGNAL_TYPE_UINT8N:
      SchM_Enter_Com_SigObjU8U8N();
      for(u16SigLoopIx = 0 ; u16SigLoopIx < u16GET_U8N_GRPSIG_LEN(u16LoopIndex); u16SigLoopIx++ )
      {
        pu8SigObjU8U8N[
               (*pku16ShadowBufIdx + u16SigLoopIx)] =
        pu8SigObjU8U8N[
               (*pku16SigObjIdx + u16SigLoopIx)];
      }
      SchM_Exit_Com_SigObjU8U8N();
      break;
      default :
      /*either dynamic signal => Dynamic length signals cannot be part of a signal
       group, since there is no API defined to update the shadow buffer of a
       dynamic length signal.
       Or a wrong configuration value*/
       /*do nothing*/
      break;

    }

  }

}
 /*  PRQA S 4700 -- */
#endif /*(Com_u16NO_OF_GROUP_SIGSLT > 0u)*/


#if((Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
/* !Deviation: [4700]  ( here has been an infringement of a threshold on the
     specified metric)
 Further decomposition of this function will affect its overall performance 
 so no other meaningfull division is required*/
 /*  PRQA S 4700 ++ */
 /*************************************************************************/
/*! \Description :.\n

**************************************************************************/  
static FUNC(void , COM_CODE) vidInitSigGroupObj (
                    VAR(Com_SignalGroupIdType,AUTOMATIC)         u16SignalGroupId)
{
  VAR(uint16_least,AUTOMATIC)                                u16LoopIndex; 
  P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,COM_CALIB_CONST)   pkstrLocGrpSigPB;
  VAR(uint16_least,AUTOMATIC)                                u16LoopIx;
  VAR(uint16,AUTOMATIC)										 u16GroupSigIdx;
  VAR(uint16,AUTOMATIC)										 u16NoOfGroupSig;

  P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,TYPEDEF) pkstrGroupSigPB;
  P2VAR(boolean,AUTOMATIC,TYPEDEF) pbSigObjB;
  P2VAR(uint8,AUTOMATIC,TYPEDEF) pu8SigObjU8U8N;
  P2VAR(sint8,AUTOMATIC,TYPEDEF) ps8SigObjS8;
  P2VAR(uint16,AUTOMATIC,TYPEDEF) pu16SigObjU16;
  P2VAR(sint16,AUTOMATIC,TYPEDEF) ps16SigObjS16;
  P2VAR(uint32,AUTOMATIC,TYPEDEF) pu32SigObjU32;
  P2VAR(sint32,AUTOMATIC,TYPEDEF) ps32SigObjS32;
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON)
  P2VAR(float32,AUTOMATIC,TYPEDEF) pf32SigObjF32;
  P2VAR(float64,AUTOMATIC,TYPEDEF) pf64SigObjF64;
#endif

  P2CONST(boolean,AUTOMATIC,TYPEDEF) pkbSigInitValueB;
  P2CONST(uint8,AUTOMATIC,TYPEDEF) pku8SigInitValueU8U8N;
  P2CONST(sint8,AUTOMATIC,TYPEDEF) pks8SigInitValueS8;
  P2CONST(uint16,AUTOMATIC,TYPEDEF) pku16SigInitValueU16;
  P2CONST(sint16,AUTOMATIC,TYPEDEF) pks16SigInitValueS16;
  P2CONST(uint32,AUTOMATIC,TYPEDEF) pku32SigInitValueU32;
  P2CONST(sint32,AUTOMATIC,TYPEDEF) pks32SigInitValueS32;
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON)
  P2CONST(float32,AUTOMATIC,TYPEDEF) pkf32SigInitValueF32;
  P2CONST(float64,AUTOMATIC,TYPEDEF) pkf64SigInitValueF64;
#endif

  P2CONST(uint16, AUTOMATIC,AUTOMATIC) pku16SigObjIdx;
  P2CONST(uint16, AUTOMATIC,AUTOMATIC) pku16SigInitValueIdx;

  u16GroupSigIdx = u16GET_GRP_SIG_IX(u16SignalGroupId);
  u16NoOfGroupSig = u16GET_NB_OF_GRPSIG(u16SignalGroupId);

  
   pkstrGroupSigPB = pkstrGET_PBGRPSIGPTR_IX(0);
  	pbSigObjB =     pkB_GET_SIG_OBJ_VALUEB(0);
	pu8SigObjU8U8N =   pku8GET_SIG_OBJ_VALUEU8(0);
	ps8SigObjS8 =   pks8GET_SIG_OBJ_VALUES8(0);
	pu16SigObjU16 = pku16GET_SIG_OBJ_VALUEU16(0);
	ps16SigObjS16 = pks16GET_SIG_OBJ_VALUES16(0);
	pu32SigObjU32 = pku32GET_SIG_OBJ_VALUEU32(0);
	ps32SigObjS32 = pks32GET_SIG_OBJ_VALUES32(0);
	
    pkbSigInitValueB 	  = pkbGET_SIGINIT_VALUEB(0);
	pku8SigInitValueU8U8N = pku8GET_SIGINIT_VALU8U8N(0);
	pks8SigInitValueS8    = pks8GET_SIGINIT_VALUES8(0);
	pku16SigInitValueU16 = pku16GET_SIGINIT_VALUEU16(0);
    pks16SigInitValueS16 = pks16GET_SIGINIT_VALUES16(0);
    pku32SigInitValueU32 = pku32GET_SIGINIT_VALUEU32(0);
    pks32SigInitValueS32 = pks32GET_SIGINIT_VALUES32(0);
  
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON)
  pf32SigObjF32 = pkf32GET_SIG_OBJ_VALUEF32(0);
  pkf32SigInitValueF32 = pkf32GET_SIGINIT_VALUEF32(0);
  pf64SigObjF64 = pkf64GET_SIG_OBJ_VALUEF64(0);
  pkf64SigInitValueF64 = pkf64GET_SIGINIT_VALUEF64(0);
#endif




  for (u16LoopIndex = u16GroupSigIdx; u16LoopIndex < (u16GroupSigIdx + u16NoOfGroupSig);
       u16LoopIndex++)
  {
    /*u16SigId         = Com_akstreGroupSignalLT[u16LoopIndex].u16SignalId ;*/
    pkstrLocGrpSigPB = &(pkstrGroupSigPB[u16LoopIndex]);

    pku16SigObjIdx = &(pkstrLocGrpSigPB->u16SignalObjectIndex);
	pku16SigInitValueIdx = &(pkstrLocGrpSigPB->u16SignalInitValueIndex);

    switch(pkstrLocGrpSigPB->u8SignalType)
    {
      case Com_u8SIGNAL_TYPE_BOOLEAN:
      pbSigObjB[*pku16SigObjIdx] =
      pkbSigInitValueB[*pku16SigInitValueIdx];
      break;
      case Com_u8SIGNAL_TYPE_UINT8:
      pu8SigObjU8U8N[*pku16SigObjIdx] =
      pku8SigInitValueU8U8N[*pku16SigInitValueIdx];   
      break;
      case Com_u8SIGNAL_TYPE_SINT8:
      ps8SigObjS8[*pku16SigObjIdx] =
      pks8SigInitValueS8[*pku16SigInitValueIdx];
      break;
      case Com_u8SIGNAL_TYPE_UINT16:
      SchM_Enter_Com_SigObjU16();
      pu16SigObjU16[*pku16SigObjIdx] =
      pku16SigInitValueU16[*pku16SigInitValueIdx];
      SchM_Exit_Com_SigObjU16();
      break;
      case Com_u8SIGNAL_TYPE_SINT16:
      SchM_Enter_Com_SigObjS16();
      ps16SigObjS16[*pku16SigObjIdx] =
      pks16SigInitValueS16[*pku16SigInitValueIdx];
      SchM_Exit_Com_SigObjS16();
      break;
      case Com_u8SIGNAL_TYPE_UINT32:
      SchM_Enter_Com_SigObjU32();
      pu32SigObjU32[*pku16SigObjIdx] =
      pku32SigInitValueU32[*pku16SigInitValueIdx];
      SchM_Exit_Com_SigObjU32();
      break;
      case Com_u8SIGNAL_TYPE_SINT32:
      SchM_Enter_Com_SigObjS32();
      ps32SigObjS32[*pku16SigObjIdx] =
      pks32SigInitValueS32[*pku16SigInitValueIdx];
      SchM_Exit_Com_SigObjS32();
      break;
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON)
      case Com_u8SIGNAL_TYPE_FLOAT32:
      SchM_Enter_Com_SigObjF32();
      pf32SigObjF32[*pku16SigObjIdx] =
      pkf32SigInitValueF32[*pku16SigInitValueIdx];
      SchM_Exit_Com_SigObjF32();
      break;
      case Com_u8SIGNAL_TYPE_FLOAT64:
      SchM_Enter_Com_SigObjF64();
      pf64SigObjF64[*pku16SigObjIdx] =
      pkf64SigInitValueF64[*pku16SigInitValueIdx];
      SchM_Exit_Com_SigObjF64();
      break;
#endif
      case Com_u8SIGNAL_TYPE_UINT8N:
      SchM_Enter_Com_SigObjU8U8N();
      for(u16LoopIx = 0 ; u16LoopIx < u16GET_U8N_GRPSIG_LEN(u16LoopIndex); u16LoopIx++ )
      {
        pu8SigObjU8U8N[(*pku16SigObjIdx + u16LoopIx)] =
        pku8SigInitValueU8U8N[(*pku16SigInitValueIdx + u16LoopIx)];
      }
      SchM_Exit_Com_SigObjU8U8N();
      break;
      default :
      /*either dynamic signal => Dynamic length signals cannot be part of a signal
       group, since there is no API defined to update the shadow buffer of a
       dynamic length signal.
       Or a wrong configuration value*/
       /*do nothing*/
      break;

    }

  }

}
 /*  PRQA S 4700 -- */
#endif /*(Com_u16NO_OF_SIGNAL_GROUPSLT > 0u)*/

#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
/* !Deviation: [4700]  ( here has been an infringement of a threshold on the
     specified metric)
 Further decomposition of this function will affect its overall performance 
 so no other meaningfull division is required*/
 /*  PRQA S 4700 ++ */  
  /*************************************************************************/
/*! \Description :.\n

**************************************************************************/ 
static FUNC(void,COM_CODE) vidCopySigShadow2Obj(
                    VAR(Com_SignalGroupIdType,AUTOMATIC)         u16SignalGroupId)
{

  VAR(uint16_least,AUTOMATIC)                                u16LoopIndex; 
  P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,COM_CALIB_CONST)   pkstrLocGrpSigPB;
  VAR(uint16_least,AUTOMATIC)                                u16SigLoopIx;
  VAR(uint16,AUTOMATIC)										 u16GroupSigIdx;
  VAR(uint16,AUTOMATIC)										 u16NoOfGroupSig;

  P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,TYPEDEF) pkstrGroupSigPB;
  P2VAR(boolean,AUTOMATIC,TYPEDEF) pbSigObjB;
  P2VAR(uint8,AUTOMATIC,TYPEDEF) pu8SigObjU8U8N;
  P2VAR(sint8,AUTOMATIC,TYPEDEF) ps8SigObjS8;
  P2VAR(uint16,AUTOMATIC,TYPEDEF) pu16SigObjU16;
  P2VAR(sint16,AUTOMATIC,TYPEDEF) ps16SigObjS16;
  P2VAR(uint32,AUTOMATIC,TYPEDEF) pu32SigObjU32;
  P2VAR(sint32,AUTOMATIC,TYPEDEF) ps32SigObjS32;
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON)
  P2VAR(float32,AUTOMATIC,TYPEDEF) pf32SigObjF32;
  P2VAR(float64,AUTOMATIC,TYPEDEF) pf64SigObjF64;
#endif
  
  u16GroupSigIdx = u16GET_GRP_SIG_IX(u16SignalGroupId);
  u16NoOfGroupSig = u16GET_NB_OF_GRPSIG(u16SignalGroupId);


    pkstrGroupSigPB = pkstrGET_PBGRPSIGPTR_IX(0);
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

  for (u16LoopIndex = u16GroupSigIdx; u16LoopIndex < (u16GroupSigIdx + u16NoOfGroupSig);
       u16LoopIndex++)
  {
    pkstrLocGrpSigPB = &(pkstrGroupSigPB[u16LoopIndex]);

    switch(pkstrLocGrpSigPB->u8SignalType)
    {
      case Com_u8SIGNAL_TYPE_BOOLEAN:
      pbSigObjB[pkstrLocGrpSigPB->u16SignalObjectIndex] =
      pbSigObjB[pkstrLocGrpSigPB->u16ShadowBufferIndex];
      break;
      case Com_u8SIGNAL_TYPE_UINT8:
      pu8SigObjU8U8N[pkstrLocGrpSigPB->u16SignalObjectIndex] =
      pu8SigObjU8U8N[pkstrLocGrpSigPB->u16ShadowBufferIndex];
      break;
      case Com_u8SIGNAL_TYPE_SINT8:
      ps8SigObjS8[pkstrLocGrpSigPB->u16SignalObjectIndex] =
      ps8SigObjS8[pkstrLocGrpSigPB->u16ShadowBufferIndex];
      break;
      case Com_u8SIGNAL_TYPE_UINT16:
      SchM_Enter_Com_SigObjU16();
      pu16SigObjU16[pkstrLocGrpSigPB->u16SignalObjectIndex] =
      pu16SigObjU16[pkstrLocGrpSigPB->u16ShadowBufferIndex];
      SchM_Exit_Com_SigObjU16();
      break;
      case Com_u8SIGNAL_TYPE_SINT16:
      SchM_Enter_Com_SigObjS16();
      ps16SigObjS16[pkstrLocGrpSigPB->u16SignalObjectIndex] =
      ps16SigObjS16[pkstrLocGrpSigPB->u16ShadowBufferIndex];
      SchM_Exit_Com_SigObjS16();
      break;
      case Com_u8SIGNAL_TYPE_UINT32:
      SchM_Enter_Com_SigObjU32();
      pu32SigObjU32[pkstrLocGrpSigPB->u16SignalObjectIndex] =
      pu32SigObjU32[pkstrLocGrpSigPB->u16ShadowBufferIndex];
      SchM_Exit_Com_SigObjU32();
      break;
      case Com_u8SIGNAL_TYPE_SINT32:
      SchM_Enter_Com_SigObjS32();
      ps32SigObjS32[pkstrLocGrpSigPB->u16SignalObjectIndex] =
      ps32SigObjS32[pkstrLocGrpSigPB->u16ShadowBufferIndex];
      SchM_Exit_Com_SigObjS32();
      break;
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON)
      case Com_u8SIGNAL_TYPE_FLOAT32:
      SchM_Enter_Com_SigObjF32();
      pf32SigObjF32[pkstrLocGrpSigPB->u16SignalObjectIndex] =
      pf32SigObjF32[pkstrLocGrpSigPB->u16ShadowBufferIndex];
      SchM_Exit_Com_SigObjF32();
      break;
      case Com_u8SIGNAL_TYPE_FLOAT64:
      SchM_Enter_Com_SigObjF64();
      pf64SigObjF64[pkstrLocGrpSigPB->u16SignalObjectIndex] =
      pf64SigObjF64[pkstrLocGrpSigPB->u16ShadowBufferIndex];
      SchM_Exit_Com_SigObjF64();
      break;
#endif
      case Com_u8SIGNAL_TYPE_UINT8N:
      SchM_Enter_Com_SigObjU8U8N();
      for(u16SigLoopIx = 0 ; u16SigLoopIx < u16GET_U8N_GRPSIG_LEN(u16LoopIndex); u16SigLoopIx++ )
      {
        pu8SigObjU8U8N[(pkstrLocGrpSigPB->u16SignalObjectIndex + u16SigLoopIx)] =
        pu8SigObjU8U8N[(pkstrLocGrpSigPB->u16ShadowBufferIndex + u16SigLoopIx)];
      }
      SchM_Exit_Com_SigObjU8U8N(); 
      break;
      default :
      /*either dynamic signal => Dynamic length signals cannot be part of a signal
      group, since there is no API defined to update the shadow buffer of a
      dynamic length signal.
      Or a wrong configuration value*/
      /*do nothing*/
      break;

    }
  }
}
 /*  PRQA S 4700 -- */ 
#endif /*(Com_u16NO_OF_GROUP_SIGSLT > 0u)*/
 /*************************************************************************/
/*! \Description :.\n

**************************************************************************/ 
static FUNC(uint8,COM_CODE) u8ProcessRxSig(
        P2CONST(tstrProcessSig,AUTOMATIC,COM_APPL_DATA)  pkstrProcessSigData,
        P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)   PduInfoPtr)
{                           

#if (Com_bUBIT_SUPPORT == STD_ON)
  VAR(boolean,AUTOMATIC)   bUpdateBitOK ;
#endif

  VAR(uint8,AUTOMATIC)     u8UnpackSignalRes;
  VAR(Com_tpfvidSignalNotification,AUTOMATIC)     pudtSignalNotifPtr;
  u8UnpackSignalRes = (uint8)E_NOT_OK;
  
#if (Com_bUBIT_SUPPORT == STD_ON)
  /*! check if the signal has update bit set to 1 , or no UB is configured*/
  /*if(pkstrProcessSigData->bIsUBConfigured == (boolean)TRUE)*/
  if(pkstrProcessSigData->u16SigUBIx != (uint16)0xFFFFu)
  {
    bUpdateBitOK = Com_bSignalCheckUpdateBit(
                   PduInfoPtr->SduDataPtr,
				   pkstrProcessSigData->u16SigUBIx);
  }
  else
  {
    /*! no update bit is configured , so it shall pass the next condition*/
    bUpdateBitOK = TRUE;
  }


  if(bUpdateBitOK == TRUE)
  {
#endif
  /*! unpack the signal*/
    u8UnpackSignalRes =  Com_u8SignalUnPackSignal(
                                             pkstrProcessSigData->u16SignlID ,
                                             PduInfoPtr);
    if( (u8UnpackSignalRes == (uint8)Com_u8UNPACK_OK) 
#if (Com_bDATA_INVALID_SUPPORT == STD_ON)	
	||(u8UnpackSignalRes == (uint8)Com_u8UNPACK_NOK_INV_REP)
#endif
	)
    {
      if(pkstrProcessSigData->u8SigStructType == (uint8)Com_u8SIG_STRUCT_SIG)
      {
        u8UnpackSignalRes = (uint8)E_OK;
        /*replacement with init value in case of Com_u8UNPACK_NOK_INV_REP is 
        done during process invalid value function */
        /*successfull notification*/
/* !Deviation: [3325]  ( The value of this control expression is always 'false' due to 
 some special configuration but in the normal case this part is normally reachable.) */
/*PRQA S 3325,3201  ++ */
		  /*! check signal notification is configured and call it*/
		  pudtSignalNotifPtr = Com_akstreSignalLT[pkstrProcessSigData->u16SignlIx].pfvidSignalNotifPtr; 
		if(pudtSignalNotifPtr != NULL_PTR)
        {
           #if Com_u16NO_OF_SIGNAL > 0u
          (*pudtSignalNotifPtr)();
           #endif
        }
/*PRQA S 3325,3201  -- */
        else
        {
        /*no notification is configured*/
        }
      }

    }
#if (Com_bDATA_INVALID_SUPPORT == STD_ON)
	/*! check if return of unpacking is invalid value Notifiy , check invalidation 
				Notification is configured and call it*/
    else if (u8UnpackSignalRes == (uint8)Com_u8UNPACK_NOK_INV_NOT)
    {
      if(pkstrProcessSigData->u8SigStructType == (uint8)Com_u8SIG_STRUCT_SIG)
      {
      
     /*Invalid Signal*/
        (*pkstrProcessSigData->pfvidInValidNot)();
      }
    }
#endif
    else
    {
     /*no notification due to discarding the signal (filtered out )*/
    }
#if (Com_bUBIT_SUPPORT == STD_ON)
  }
  else
  {
  /*no notification due to unset update bit*/
  }
#endif
  return u8UnpackSignalRes;

}
 /*************************************************************************/
/*! \Description :.\n

**************************************************************************/ 
#if ((Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))  
static FUNC(uint8,COM_CODE) u8ProcessRxSigGrp(
        VAR(uint16,AUTOMATIC) u16SigGrpID ,
        P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) PduInfoPtr)
{

  /* !Deviation:[3672]  (Using non-const pointer to function.)
  the pointer to function can not be declared as constant , as it will
  be assigned a value calculated by the code depending on the PduId*/
  /*PRQA S 3672 ++ */  
#if (Com_bDATA_INVALID_SUPPORT == STD_ON)
  VAR(Com_tpfvidSigInvalidNotif,AUTOMATIC)              pfvidInValidNotification; 
#endif

  /*PRQA S 3672 -- */     
  VAR(uint16_least,AUTOMATIC)                           u16SigLoopIx;
  VAR(boolean,AUTOMATIC)                                bUpdateBitOK;
  VAR(uint8,AUTOMATIC)                                  u8UnpackSignalRes;
  VAR(uint8,AUTOMATIC)                                  u8ProcessRxSigGrpRes;
#if	(Com_bFLOAT_SIGNAL_SUPPORT == STD_OFF)
  VAR(uint8,AUTOMATIC)                                  u8CurrentGroSigType;
#endif

  VAR(uint16,AUTOMATIC)                                 u16SigID ; 
  VAR(uint16,AUTOMATIC)                                 u16UBIx;
  VAR(uint16,AUTOMATIC)									u16GroupSigIdx;
  VAR(uint16,AUTOMATIC)									u16NoOfGroupSig;
  VAR(Com_tpfvidSignalNotification,AUTOMATIC)			pudtSigNotifPtr;
  P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,TYPEDEF) 		pkstrSigGrpPB;
    
  u8UnpackSignalRes = (uint8)Com_u8UNPACK_OK;
  u8ProcessRxSigGrpRes = (uint8)E_NOT_OK ;
#if (Com_bDATA_INVALID_SUPPORT == STD_ON)
  pfvidInValidNotification = pfSIGGRP_INVALID_CBK(u16SigGrpID);   
#endif
  pkstrSigGrpPB = pkstrGET_PB_SIGGRP_PTR(u16SigGrpID);
#if (Com_bUBIT_SUPPORT == STD_ON)
  /*! check if the signal has update bit set to 1 , or no UB is configured*/
  /*if(bIS_SIGGROUP_UB_CONF(u16SigGrpID) == (boolean)TRUE)*/
  u16UBIx = pkstrSigGrpPB->u16UpdateBitPosition;
  if (u16UBIx != (uint16)0xFFFFu)
  {
    bUpdateBitOK = Com_bSignalCheckUpdateBit(
                   PduInfoPtr->SduDataPtr,
				   u16UBIx);
  }
  else
  {
    /*no update bit is configured , so it shall pass the next condition*/
    bUpdateBitOK = TRUE;
  }

  if(bUpdateBitOK == TRUE)
  {
#endif
	u16GroupSigIdx = pkstrSigGrpPB->u16GroupSignalIndex;
	u16NoOfGroupSig = pkstrSigGrpPB->u16NoOfGroupSignals;

  /*! Loop on all group signals to unpack it*/
    for(u16SigLoopIx = u16GroupSigIdx;
    ((u16SigLoopIx < (u16NoOfGroupSig + u16GroupSigIdx)) &&
	(u8UnpackSignalRes == (uint8)Com_u8UNPACK_OK));u16SigLoopIx ++ )
    {
        u16SigID = Com_akstreGroupSignalLT[u16SigLoopIx].u16SignalId;
		#if	(Com_bFLOAT_SIGNAL_SUPPORT == STD_OFF)
		u8CurrentGroSigType = u8GET_PB_GRP_SIG_TYPE(u16SigLoopIx);
		if(u8CurrentGroSigType != Com_u8SIGNAL_TYPE_FLOAT32 && u8CurrentGroSigType !=Com_u8SIGNAL_TYPE_FLOAT64)
		{
	    #endif
           u8UnpackSignalRes =  Com_u8SignalUnPackSignal(u16SigID ,PduInfoPtr );
		#if(Com_bFLOAT_SIGNAL_SUPPORT == STD_OFF)
		}
		#endif
    }
    if( (u8UnpackSignalRes == (uint8)Com_u8UNPACK_OK) 
#if (Com_bDATA_INVALID_SUPPORT == STD_ON)	
	||(u8UnpackSignalRes == (uint8)Com_u8UNPACK_NOK_INV_REP)
#endif	
	)
    {
      u8ProcessRxSigGrpRes = E_OK;
#if (Com_bDATA_INVALID_SUPPORT == STD_ON)      
	  if(u8UnpackSignalRes == (uint8)Com_u8UNPACK_NOK_INV_REP) 

      {
		/*! initialize All group signal obejcts in invalidation notifcation occured*/
        vidInitSigGroupObj(u16SigGrpID);
      }
      else
      {
          /*do nothing*/
      }        
#endif

	  pudtSigNotifPtr = Com_akstreSignalGroupLT[u16SigGrpID].pfvidSignalNotifPtr;
        /*! successfull notification*/
	  if (pudtSigNotifPtr != NULL_PTR)
      {
            #if Com_u16NO_OF_SIGNAL_GROUPSLT > 0u
        (*pudtSigNotifPtr)();
            #endif
      }
      else
      {
          /*no notification is configured*/
      }

    }
#if (Com_bDATA_INVALID_SUPPORT == STD_ON)
    else if (u8UnpackSignalRes == (uint8)Com_u8UNPACK_NOK_INV_NOT)
    {
     /*Invalid Signal */
     /*! copy the old value signal to the signal object of the whole signal group*/
      vidCopySigShadow2Obj(u16SigGrpID);
      (*pfvidInValidNotification)();
    }
#endif
    else
    {
     /*shall not enter here since no filtering out for signal group*/
     /*no notification due to discarding the signal (filtered out )*/
    }
#if (Com_bUBIT_SUPPORT == STD_ON)
  }
  else
  {
  /*no notification due to unset update bit*/
  }
#endif

  return u8ProcessRxSigGrpRes ;
}
#endif /*(Com_u16NO_OF_SIGNAL_GROUPSLT > 0u)*/

#if((Com_u16NO_OF_IPDU_REPLIC > 0u) && (Com_bRX_REPLICAS_SUPPORT == STD_ON))
 /*************************************************************************/
/*! \Description :.\n

**************************************************************************/ 
static FUNC(void,COM_CODE) vidHandleIpduReplicas(
VAR(PduIdType,AUTOMATIC)                     u16RxPduId ,
P2CONST(PduInfoType,AUTOMATIC,COM_APPL_DATA) pkstrPduInfoPtr ) 
{

  P2CONST(Com_tstrRxIPdu,AUTOMATIC,COM_CALIB_CONST) pkstrLocRXIpduPB;
  VAR(uint32, AUTOMATIC)                            u32IpduBufferIx;
  P2VAR(uint8,AUTOMATIC,COM_APPL_DATA)              pu8FirstReplica;
  P2VAR(uint8,AUTOMATIC,COM_APPL_DATA)              pu8SecondReplica;
  VAR(uint16_least , AUTOMATIC)                     u16ByteLoopIndex;
  P2VAR(uint8,AUTOMATIC,TYPEDEF) 					pu8IPduBuf;  
  P2CONST(PduLengthType,AUTOMATIC,TYPEDEF) 			pkudtSduLengthPtr;
  P2VAR(uint8, AUTOMATIC, AUTOSAR_COMSTACKDATA) 	pudtSduDataPtr;
  P2CONST(Com_tstrIPduReplication,AUTOMATIC,TYPEDEF) pkstreIPduReplica;
  VAR(uint16,AUTOMATIC)                             u16IPduReplicaIx;
  VAR(uint16,AUTOMATIC)                             u16RxPduIx;
  P2VAR(uint8,AUTOMATIC,TYPEDEF) 					pu8ReplicasCounter;  
        
  u16RxPduIx = u16GET_IPDU_INDEX(u16RxPduId);
  pkstrLocRXIpduPB    = pkstrGET_RX_IPDU_PTR_IX(u16RxPduIx);
  u16IPduReplicaIx = pkstrLocRXIpduPB->u16IPduReplicationIndex;
  pkstreIPduReplica= pkstrGET_RX_IPDU_REP_PTR(u16IPduReplicaIx);
  pu8ReplicasCounter = &Com_au8eReplicasCounter[u16IPduReplicaIx];
  
  u32IpduBufferIx = pkstrLocRXIpduPB->u32IPduBufferIndex;
  pu8FirstReplica =  pu8GET_RX_IPDU_1ST_REP(pkstreIPduReplica->u16ReplicasBufferIndex);
  pu8IPduBuf = pkstrGET_IPDU_BUFF_PTR(0);
  pkudtSduLengthPtr = &(pkstrPduInfoPtr->SduLength);
  pudtSduDataPtr = pkstrPduInfoPtr->SduDataPtr;
  if ((*pu8ReplicasCounter) == pkstreIPduReplica->u8NoOfReplicas)
  {/*copy the original Ipdu data*/
    for (u16ByteLoopIndex = 0 ; u16ByteLoopIndex < *pkudtSduLengthPtr ; u16ByteLoopIndex++)
    {
      SchM_Enter_Com_IPduBuff_42();
      pu8IPduBuf[(u32IpduBufferIx+u16ByteLoopIndex)]  = pudtSduDataPtr[u16ByteLoopIndex];
      SchM_Exit_Com_IPduBuff_42();
    }
  }
  /*original Ipdu received from the previous part*/
  else if((*pu8ReplicasCounter)  ==
    ((pkstreIPduReplica->u8NoOfReplicas) -1 ))
  {
    for (u16ByteLoopIndex = 0 ; u16ByteLoopIndex < *pkudtSduLengthPtr; u16ByteLoopIndex++)
    {
      pu8FirstReplica[u16ByteLoopIndex] = pudtSduDataPtr[u16ByteLoopIndex];
    }


  }

  else if(((*pu8ReplicasCounter) == 0) &&
         ((pkstreIPduReplica->u8NoOfReplicas)== (uint8)2u))
  {

  /*Copy the second replica*/

    pu8SecondReplica = &(pu8FirstReplica[pkstrLocRXIpduPB->u16IPduLength]) ;
    for (u16ByteLoopIndex = 0 ; u16ByteLoopIndex < *pkudtSduLengthPtr ; u16ByteLoopIndex++)
    {
      pu8SecondReplica[u16ByteLoopIndex] = pudtSduDataPtr[u16ByteLoopIndex] ;
    }

  }
  else
  {
    /*shall not enter here*/
  }
  if ((*pu8ReplicasCounter)  == (uint8)0)
  {
    /*reset the number of replicas*/
    (*pu8ReplicasCounter)  = pkstreIPduReplica->u8NoOfReplicas;

    if ((pkstrLocRXIpduPB->udteRxIPduFlags & Com_u8RX_IPDUSIGPROCESSING) != Com_u8SIG_PROC_IMMEDIATE)
    {
       /*for deferred Ipdu , only set the deferred flag , processing will be done in the Main Rx function*/
	  #if u16NO_OF_IPDUS_STATUS > 0u
	  SchM_Enter_Com_IPduStatus_42();
	  Com_audteIPduStatus[u16RxPduId] |= Com_u8DEF_PROC_MASK; 
      SchM_Exit_Com_IPduStatus_42();
	  #endif
	  
    }
    else
    {
      /*imediate Ipdu shall be processed right now*/
      vidProcessRxIpdu(u16RxPduIx , &pu8IPduBuf[pkstrLocRXIpduPB->u32IPduBufferIndex]);
    }
  }
  else
  {
    /*replica counter != 0*/
    (*pu8ReplicasCounter)  -=(uint8)1u;
  }
}
#endif /*(Com_u16NO_OF_IPDU_REPLIC > 0u)*/
/* !Deviation: [8019]  ( The name of " symbolic constants " (#define) Identifiers does not  respect the naming conventions.) */
/*[8519](The Type of " symbolic constants " (#define) Identifiers does not  respect the naming conventions.)*/
/*this #define is imposed by the AUTOSAR MemMap file , required for memory abstraction*/
/*PRQA S 8019 , 8519 ++ */
/* PRQA S  5087 L1 */
#define COM_STOP_SEC_CODE
/*PRQA S 8019 ,8519 -- */
#include "MemMap.h"
/* PRQA L:L1 */
/** \} */ /* end of Com module group */

/* PRQA S 0850 --                                                             */

