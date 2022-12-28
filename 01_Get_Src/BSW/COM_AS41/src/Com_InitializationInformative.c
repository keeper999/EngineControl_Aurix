/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : Com                                                     */
/* !Description     : AUTOSAR Communication Module                            */
/*                                                                            */
/* !Module          : Com_InitializationInformative                           */
/* !Description     : Module responsible for the componenet Initialization    */
/*                    and providing Information about the componenet          */
/*                                                                            */
/* !File            : Com_InitializationInformative.c                         */
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
/* $Revision::   1.140     $$Author::   ametwelly      $$Date::   Aug 24 2014$*/
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
/* !Deviation: [0790](This translation unit makes use of floating types.) */
/*AUTOSAR support float signal values , float 32 and float64 */
/*PRQA S 0790 ++ */

#include "Com.h"
#include "Com_Internal.h"
#include "Com_Cfg.h"
#include "Com_LCfg.h"
#include "SchM_Com.h"
#include "Com_PackSig.h"

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

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/* !Comment : Inavalid value for the Configuration Id to be returned in case  */
/*            uninitialezed module and no Det protection                      */
#define u32COM_CONF_INVALID_ID  0xFFFFFFFFUL
/* !Comment :  Received Ipdu unused area default value                        */
/*Althoug there is NO default area configured for the RX Ipdu , but due to    */
/*the design , Deferred RX IPDUs will have an entry in the RAM buffer ,and    */
/* since there is an AutoSAR requirement to initialize all RAM variables ,    */
/*the unused area of the RX Ipdu shall be initialized                         */
#define u8RX_IPDU_UNUSED_AREA 0x00u

/******************************************************************************/
/*                       Macro Definitions                                    */
/******************************************************************************/

/* !Deviation: [3453]  the following functions like macros , helps to increase
the readability of the code , by accessing the required configuration parameter
, through a macro . Macros were used instead of functions in order to increase
the code performance  by reducing the time required by the context switching*/
/* PRQA S 3453 ++ */

/*Macro to get a specific filter algorithm assigned to a signal specified by a
signal ID*/
#if ((Com_u16NO_OF_SIGNAL > 0u) && (Com_u16NO_OF_FILTER > 0u))
#define pkstrGET_FILTER_SPEC_PTR(u16SigFilterIx) \
(&(Com_akstreFilter[(u16SigFilterIx)]))
#else
#define pkstrGET_FILTER_SPEC_PTR(u16SigFilterIx) \
		(P2CONST(Com_tstrFilter,AUTOMATIC,TYPEDEF)) NULL_PTR
#endif




/*Macro to get a specific filter index assigned to a signal specified by a signal ID*/
#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_FILTER > 0u))
#define u16GRPSIG_SPCFC_FLTR_IX(u16SigFilterIx) \
(Com_akstreFilter[u16SigFilterIx].u16Index)
#else
#define u16GRPSIG_SPCFC_FLTR_IX(u16SigFilterIx) 0x00u
#endif


/*Macro to get the TX Ipdu counter bit position inside the Ipdu */
#if Com_u16NO_OF_IPDU_COUNTER > 0u
#define u16GET_TX_IPDU_CTR_POS(u16IpduCtrIx) \
(Com_akstreIPduCounters[(u16IpduCtrIx)].u16IPduCounterStartPos)
#else
#define u16GET_TX_IPDU_CTR_POS(u16IpduCtrIx) 0x00u
#endif


/*Macro to get the TX Ipdu counter size */
#if Com_u16NO_OF_IPDU_COUNTER > 0u
#define u8GET_TX_IPDU_CTR_SIZE(u16IpduCtrIx) \
(Com_akstreIPduCounters[(u16IpduCtrIx)].u8IPduCounterSize)
#else
#define u8GET_TX_IPDU_CTR_SIZE(u16IpduCtrIx) 0x00u
#endif

/*Macro to get a suitable bit mask according to the bit order*/
#define u8GET_BIT_MASK(u8BitOrder) (0x01u <<(u8BitOrder))

/*Macro to identify if a bit is SET or not*/
#define bIS_BIT_SET(u8Var, u8mask)    (((u8Var) & (u8mask)) != 0)

/*Macro to set a bit in a specific Byte*/
#define vidSET_BIT_MASK(u8Var, u8mask)  ((u8Var) |= (u8mask))

/*Macro to clear a bit in a specific byte*/
#define vidCLR_BIT_MASK(u8Var, u8mask) ((u8Var) &= ((u8mask) ^ (uint8)0xFF))

/*Macro to mask some bit from a specific position and having a certain size*/
#define u8MASK_CERTAIN_BITS(u8StartPos,u8BitNumbers) \
(uint8)(((uint8)0xFFu >> ((uint8)8u -(u8BitNumbers)))<<(u8StartPos))

#if Com_u16NO_OF_SIGNAL > 0u
#define u16GET_SIG_ID_FROM_IX(u16SigIx)  \
Com_akstreSignalLT[(u16SigIx)].u16SignalId
#else
#define u16GET_SIG_ID_FROM_IX(u16SigIx) 0
#endif


#if Com_u16NO_OF_GROUP_SIGSLT > 0u
#define u16GET_U8N_GRPSIG_LEN(u16SigIx)\
Com_akstreGroupSignalLT[(u16SigIx)].u16SignalLength
#else
#define u16GET_U8N_GRPSIG_LEN(u16SigIx) 0u
#endif

#if Com_u16NO_OF_SIGNAL > 0u
#define u16GET_U8N_SIG_LEN_IX(u16SigIx)\
Com_akstreSignalLT[(u16SigIx)].u16SignalLength

#else
#define u16GET_U8N_SIG_LEN_IX(u16SigIx) 0u
#endif 


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_IPDU_LOOKUP_PTR(u16IPduId) \
		(&(Com_pkstreMainConfig->pkstrIPduLookUp[(u16IPduId)]))
#else
#define pkstrGET_IPDU_LOOKUP_PTR(u16IPduId) \
				(&(akstrIPduLookUp[(u16IPduId)]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define u32GET_CONFIG_ID() \
		Com_pkstreMainConfig->u32ConfigurationId
#else
#define u32GET_CONFIG_ID() \
	    Com_u32ConfigurationId
#endif
		

#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_IPDU_SIG_MAP_PTR() \
		Com_pkstreMainConfig->pkstrIPduToSignalMapping
#else
#define pkstrGET_IPDU_SIG_MAP_PTR() \
	     &akstrIPduToSignalMapping[0]
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_GW_SIG_MAPP_PTR() \
		Com_pkstreMainConfig->pkstrGWSignalMapping
#else
#if u16NO_OF_GW_PATHS > 0u
#define pkstrGET_GW_SIG_MAPP_PTR() \
	     &akstrGWSignalMapping[0]
#else
#define pkstrGET_GW_SIG_MAPP_PTR() \
		(P2CONST(Com_tstrGWSignalMapping,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_GW_SRC_DESC_PTR() \
		Com_pkstreMainConfig->pkstrGWSrcDesc
#else
#if u16NO_OF_GW_SRC_DESC > 0u
#define pkstrGET_GW_SRC_DESC_PTR() \
	     &akstrGWSrcDesc[0]
		 
#else
#define pkstrGET_GW_SRC_DESC_PTR() \
		(P2CONST(Com_tstrGWSrcDesc,AUTOMATIC,TYPEDEF))NULL_PTR
#endif	 
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_GW_DES_DESC_PTR() \
		Com_pkstreMainConfig->pkstrGWDstDesc
#else
#if u16NO_OF_GW_DST_DESC > 0u
#define pkstrGET_GW_DES_DESC_PTR() \
	     &akstrGWDstDesc[0]
#else

#define pkstrGET_GW_DES_DESC_PTR() \
		(P2CONST(Com_tstrGWDstDesc,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define u16GET_GRP_SIG_IX(u16SigGrpId) \
Com_pkstreMainConfig->pkstrSignalGroupPB[(u16SigGrpId)].u16GroupSignalIndex
#else
#define u16GET_GRP_SIG_IX(u16SigGrpId) \
	     &akstrSignalGroupPB[(u16SigGrpId)].u16GroupSignalIndex
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_LOOKUP_SIG_PTR(u16SigId) \
		(&(Com_pkstreMainConfig->pkstrSignalLookUp[u16SigId]))
#else
#define pkstrGET_LOOKUP_SIG_PTR(u16SigId) \
	     (&(akstrSignalLookUp[(u16SigId)]))
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PB_SIGNAL_PTR(u16SigIx) \
(&(Com_pkstreMainConfig->pkstrSignalPB[u16SigIx]))
#else
#define pkstrGET_PB_SIGNAL_PTR(u16SigIx) \
(&(akstrSignalPB[u16SigIx]))
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PB_GRP_SIG_PTR(u16SigIx) \
(&( Com_pkstreMainConfig->pkstrGroupSignalPB[(u16SigIx)]))
#else
#define pkstrGET_PB_GRP_SIG_PTR(u16SigIx) \
(&(akstrGroupSignalPB[(u16SigIx)]))
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PB_SRC_DESC_PTR(u16SigIx) \
(&( Com_pkstreMainConfig->pkstrGWSrcDesc[(u16SigIx)]))
#else
#define pkstrGET_PB_SRC_DESC_PTR(u16SigIx) \
(&(akstrGWSrcDesc[(u16SigIx)]))
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PB_DST_DESC_PTR(u16SigIx) \
(&(Com_pkstreMainConfig->pkstrGWDstDesc[(u16SigIx)]))
#else
#define pkstrGET_PB_DST_DESC_PTR(u16SigIx) \
(&(akstrGWDstDesc[(u16SigIx)]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PB_TIMEOUT_TIMER() \
(Com_pkstreMainConfig->pu32TimeOutTimer)
#else
#define pkstrGET_PB_TIMEOUT_TIMER() \
(&(Com_au32TimeOutTimer[0]))
#endif


#if ((Com_u16NO_OF_SIGNAL > 0u) && (Com_u16NO_OF_FILTER > 0u))
#if (Com_bPB_VARIANT == STD_ON)
#define u16GET_SPECIFIC_FLTR_IX(u16SigId) \
(Com_akstreFilter[(Com_akstreSignalLT[Com_pkstreMainConfig->pkstrSignalLookUp[\
(u16SigId)].u16Index].u16FilterIndex)].u16Index)
#else
#define u16GET_SPECIFIC_FLTR_IX(u16SigId) 0x00u
#endif
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_TX_IPDU_PTR(u16IPduId) \
(&(Com_pkstreMainConfig->pkstrTxIPdu[Com_pkstreMainConfig->pkstrIPduLookUp[(u16IPduId)].u16Index]))
#else
#define pkstrGET_TX_IPDU_PTR(u16IPduId) \
(&(akstrTxIPdu[akstrIPduLookUp[(u16IPduId)].u16Index]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_RX_IPDU_PTR(u16IPduId) \
(&(Com_pkstreMainConfig->pkstrRxIPdu[Com_pkstreMainConfig->pkstrIPduLookUp[(u16IPduId)].u16Index]))
#else
#define pkstrGET_RX_IPDU_PTR(u16IPduId) \
(&(akstrRxIPdu[akstrIPduLookUp[(u16IPduId)].u16Index]))
#endif




#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_IPDU_BUFF_PTR(u16IPduBufferIx) \
(&(Com_pkstreMainConfig->pu8IPduBuffer[(u16IPduBufferIx)]))
#else
#define pkstrGET_IPDU_BUFF_PTR(u16IPduBufferIx) \
(&(Com_au8IPduBuffer[(u16IPduBufferIx)]))
#endif

#if Com_u16NO_OF_IPDU_COUNTER > 0u
#define pkstrGET_IPDU_CTR_PTR(u16IpduCtrIx) \
	(&(Com_akstreIPduCounters[(u16IpduCtrIx)]))
#else
#define pkstrGET_IPDU_CTR_PTR(u16IpduCtrIx) \
	(P2CONST(Com_tstrIPduCounter,AUTOMATIC,TYPEDEF))NULL_PTR
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_TP_IPDU_CTR_PTR(u16TpIpduCtrIx) \
(&(Com_pkstreMainConfig->pu16TpByteCounter[(u16TpIpduCtrIx)]))
#else
#if u16NO_OF_TP_IPDU > 0u
#define pkstrGET_TP_IPDU_CTR_PTR(u16TpIpduCtrIx) \
(&(Com_au16TpByteCounter[(u16TpIpduCtrIx)]))
#else
#define pkstrGET_TP_IPDU_CTR_PTR(u16TpIpduCtrIx) \
	(P2VAR(uint16,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PB_SIGGRP_PTR(u16SigGrpId) \
	(&( Com_pkstreMainConfig->pkstrSignalGroupPB[(u16SigGrpId)]))
#else
#define pkstrGET_PB_SIGGRP_PTR(u16SigGrpId) \
		(&(akstrSignalGroupPB[(u16SigGrpId)]))
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
#define udtGET_PB_INIT_IPDUSTATUS(u16IpduId) \
(Com_pkstreMainConfig->pkudteInitIPduStatus[u16IpduId])
#else
#define udtGET_PB_INIT_IPDUSTATUS(u16IpduId) \
(Com_audteInitIPduStatus[u16IpduId])
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
#define pku8GET_SIG_INT_FLTR_VAL(u16SigIx) \
	(&(Com_pkstreMainConfig->pku8SigInitFilterResult[(u16SigIx)]))
#else
#define pku8GET_SIG_INT_FLTR_VAL(u16SigIx) \
		(&(aku8SigInitFilterResult[(u16SigIx)]))
#endif




#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_TX_MODE(u16IPduTxModeIx) \
	(&(Com_pkstreMainConfig->pkstrTxMode[(u16IPduTxModeIx)]))
#else
#define pkstrGET_TX_MODE(u16IPduTxModeIx) \
		(&(akstrTxMode[(u16IPduTxModeIx)]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pku32GET_TX_MODE_TIMR(u16IPduTxMoTimerIx) \
	(&(Com_pkstreMainConfig->pu32TxModeTimer[(u16IPduTxMoTimerIx)]))
#else
#define pku32GET_TX_MODE_TIMR(u16IPduTxMoTimerIx) \
		(&(Com_au32TxModeTimer[(u16IPduTxMoTimerIx)]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_TX_MODE_DIR(u16IPduTxMoDIRIx) \
	(&(Com_pkstreMainConfig->pkstrTxModeDirect[(u16IPduTxMoDIRIx)]))
#else
#define pkstrGET_TX_MODE_DIR(u16IPduTxMoDIRIx) \
		(&(akstrTxModeDirect[(u16IPduTxMoDIRIx)]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_TX_MODE_MIXED(u16IPduTxMoMIXIx) \
	(&(Com_pkstreMainConfig->pkstrTxModeMixed[(u16IPduTxMoMIXIx)]))
#else
#define pkstrGET_TX_MODE_MIXED(u16IPduTxMoMIXIx) \
		(&(akstrTxModeMixed[(u16IPduTxMoMIXIx)]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_TX_MODE_PERIODIC(u16IPduTxMoPERIx) \
	(&(Com_pkstreMainConfig->pkstrTxModePeriodic[(u16IPduTxMoPERIx)]))
#else
#define pkstrGET_TX_MODE_PERIODIC(u16IPduTxMoPERIx) \
		(&(akstrTxModePeriodic[(u16IPduTxMoPERIx)]))
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define pku32GET_MD_TIMER(u16MDTimerIx) \
	(&(Com_pkstreMainConfig->pu32MDTimer[(u16MDTimerIx)]))
#else
#define pku32GET_MD_TIMER(u16MDTimerIx) \
		(&(Com_au32MDTimer[(u16MDTimerIx)]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pku8GET_REPEATATION_CTR(u16RepeatationCtr) \
	(&(Com_pkstreMainConfig->pu8TxModeRepetitionsCtr[(u16RepeatationCtr)]))
#else
#define pku8GET_REPEATATION_CTR(u16RepeatationCtr) \
		(&(Com_au8TxModeRepetitionsCtr[(u16RepeatationCtr)]))
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define pu16GET_TP_BYTECNTR_MXIX() \
	(Com_pkstreMainConfig->u16TpByteCounterMaxIx)
#else


#if (u16NO_OF_TP_IPDU > 0)
#define pu16GET_TP_BYTECNTR_MXIX() \
				(u16NO_OF_TP_IPDU - 1)
#else
#define pu16GET_TP_BYTECNTR_MXIX() \
				(u16NO_OF_TP_IPDU)				
#endif
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define u32IPDU_GET_FIRST_FTIMEOUT(u16IPduFiTOIx) \
            (Com_pkstreMainConfig->pku32IpduFirstTO[u16IPduFiTOIx])                    
#else
#if Com_u16IPDU_FIRST_TO_SIZE > 0u
#define u32IPDU_GET_FIRST_FTIMEOUT(u16IPduFiTOIx) \
            (Com_aku32eIpduFirstTO[u16IPduFiTOIx])	
#else

#define u32IPDU_GET_FIRST_FTIMEOUT(u16IPduFiTOIx) \
	       (P2CONST(uint32,AUTOMATIC,TYPEDEF))NULL_PTR			
#endif
#endif



/* PRQA S 3453 -- */
/******************************************************************************/


/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
   /* !Deviation: [0838]  ( File has already been included directly from this
   file.  ) */
   /*multiple inclusion of MemMap.h is necessary to adjust the memory mapping of
        the functions and variables*/
/* PRQA S 0838, 5087 L1 */

/* !Comment : Pointer to the main configuration structure                     */
/* !Range   : No Null                                                         */

/* !Deviation: [8019]  ( The name of " symbolic constants " (#define)
Identifiers does notrespect the naming conventions.) */
/*[8519](The Type of " symbolic constants " (#define) Identifiers does not 
respect the naming conventions.)*/
/*[8619](The Descriptive body of " symbolic constants " (#define) Identifiers
does notrespect the naming conventions.)*/
/*this #define is imposed by the AUTOSAR MemMap file , required for memory
abstraction*/
/*PRQA S 8019 , 8519 , 8619++ */
#define COM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/* !Deviation: [8018]  (The name of the constant (const) does notrespect the
naming conventions.) */
/*Limitation in the current QAC check with pointer to constant structure ,the
 name is correct*/
/*PRQA S 8018 ++ */
P2CONST(Com_ConfigType,COM_VAR,COM_CALIB_CONST)Com_pkstreMainConfig =
(P2CONST(Com_ConfigType,COM_VAR,COM_CALIB_CONST))NULL_PTR;
/*PRQA S 8018  -- */
/* PRQA S 5087 L1 */
#define COM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/* PRQA L:L1 */
/*PRQA S 8019 , 8519 , 8619--  */

/* !Comment : status of the com module                                        */
/* !Range   : COM_UNINIT , COM_INIT                                           */
/* !Deviation: [8019]  ( The name of " symbolic constants " (#define)
Identifiers does notrespect the naming conventions.) */
/*[8519](The Type of " symbolic constants " (#define) Identifiers does not 
respect the naming conventions.)*/
/*this #define is imposed by the AUTOSAR MemMap file , required for memory
abstraction*/
/*PRQA S 8019 , 8519++ */
/* PRQA S 5087 L1 */
#define COM_START_SEC_VAR_8
#include "MemMap.h"
/* PRQA L:L1 */
VAR(Com_StatusType,COM_VAR) Com_enueStatus = COM_UNINIT ;
/* PRQA S 5087 L1 */
#define COM_STOP_SEC_VAR_8
#include "MemMap.h"
/* PRQA L:L1 */
/*PRQA S 8019 , 8519 -- */
/******************************************************************************/
/*                       Static functions Declration                        */
/******************************************************************************/
/* !Deviation: [8019]  ( The name of " symbolic constants " (#define) Identifiers
does notrespect the naming conventions.) */
/*[8519](The Type of " symbolic constants " (#define) Identifiers does not 
respect the naming conventions.)*/
/*this #define is imposed by the AUTOSAR MemMap file , required for memory
abstraction*/
/*PRQA S 8019 , 8519++ */
/* PRQA S 5087 L1 */
#define COM_START_SEC_CODE
/*PRQA S 8019 , 8519 -- */
#include "MemMap.h"
/* PRQA L:L1 */
#if Com_u16NO_OF_SIGNAL > 0u
static FUNC(void,COM_CODE) vidInitSigParam(
                       VAR(Com_SignalIdType,AUTOMATIC) u16SigIx,
#if Com_u16NO_OF_ONE_EVERY_N_F > 0u
                       VAR(boolean,AUTOMATIC)          bBulkInitMode,
#endif
                       VAR(boolean,AUTOMATIC)          bPackSignal,
					   VAR(uint8, AUTOMATIC)           u8SigStructType,
					   VAR(uint8, AUTOMATIC)           u8IpduDirection);
#endif
static FUNC(void,COM_CODE) vidInitIpduSignals (
                         VAR(uint8,AUTOMATIC)   u8IpduDirection   ,
                         VAR(boolean,AUTOMATIC) bBulkInit         ,
                         VAR(boolean,AUTOMATIC) bPackSig,
						 VAR(uint16,AUTOMATIC)  u16IpduSigMapIndx ,
                         VAR(uint16,AUTOMATIC)  u16MaxSigNo);

#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
static FUNC(void,COM_CODE) vidInitSigGrpParam (
                           VAR(uint16,AUTOMATIC)  u16SigGrpID ,
                           VAR(boolean,AUTOMATIC) bBulkInit   ,
                           VAR(boolean,AUTOMATIC) bPackSig,
						   VAR(uint8,AUTOMATIC)   u8IpduDirection) ;
#endif                           
    
#if (Com_bDATA_TP_SUPPORT == STD_ON)
static FUNC( Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjU8Dyn(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx ,
                             VAR(uint16,AUTOMATIC)  u16SigByteLen ) ;
#endif
static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjU8N(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx ,
                             VAR(uint16,AUTOMATIC)  u16SigByteLen ) ;
							 
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON)
static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjF64(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx) ; 
							 
static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjF32(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx) ;
#endif
static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjnOldValS32(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx
#if Com_u16NO_OF_MASK_OLD_F_S32 > 0u
                             ,VAR(uint16,AUTOMATIC)  u16SpecificFilterIndex,
                             VAR(boolean,AUTOMATIC) bInitOldValFilter
#endif							 
							 ) ;
static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjnOldValU32(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx
#if Com_u16NO_OF_MASK_OLD_F_U32 > 0u
                             ,VAR(uint16,AUTOMATIC)  u16SpecificFilterIndex,
                             VAR(boolean,AUTOMATIC) bInitOldValFilter
#endif
							 ) ;
static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjnOldValS16(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx
#if Com_u16NO_OF_MASK_OLD_F_S16 > 0u
                             ,VAR(uint16,AUTOMATIC)  u16SpecificFilterIndex,
                             VAR(boolean,AUTOMATIC) bInitOldValFilter
#endif							 
							 ) ;
static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjnOldValU16(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx
#if Com_u16NO_OF_MASK_OLD_F_U16 > 0u
                             ,VAR(uint16,AUTOMATIC)  u16SpecificFilterIndex,
                             VAR(boolean,AUTOMATIC) bInitOldValFilter
#endif
							 );
static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjnOldValS8(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx
#if Com_u16NO_OF_MASK_OLD_F_S8 > 0u
                             ,VAR(uint16,AUTOMATIC)  u16SpecificFilterIndex,
                             VAR(boolean,AUTOMATIC) bInitOldValFilter
#endif
							 ) ;

static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjnOldValU8(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx
#if Com_u16NO_OF_MASK_OLD_F_U8> 0u
                             ,VAR(uint16,AUTOMATIC)  u16SpecificFilterIndex,
                             VAR(boolean,AUTOMATIC) bInitOldValFilter
#endif							 
							 ) ;
static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjnOldValB(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx
#if  Com_u16NO_OF_MASK_OLD_F_B > 0u
                             ,VAR(uint16,AUTOMATIC)  u16SpecificFilterIndex,
                             VAR(boolean,AUTOMATIC) bInitOldValFilter
#endif
																		);            
static FUNC(void,COM_CODE) vidInitConfRamArrays (void) ;
#if Com_u16NO_OF_TX_IPDU > 0
static FUNC(void,COM_CODE) vidInitTxModeParam(
                           VAR(uint16,AUTOMATIC) u16PduId );
#endif
/******************************************************************************/
/*! \Trace_To : Com-CDD-InitializationInformative-0237(0) ,
Com-CDD-InitializationInformative-0519(0) , Com-CDD-InitializationInformative-0522(0) ,
Com-CDD-InitializationInformative-0242(0) , Com-CDD-InitializationInformative-0523(0) ,
Com-CDD-InitializationInformative-0524(0) , Com-CDD-InitializationInformative-0525(0) ,
Com-CDD-0176(0) , Com-CDD-0175(0) , Com-CDD-InitializationInformative-5656(0) , 
Com-CDD-InitializationInformative-5635(0) , Com-CDD-5752(0), Com-CDD-5517(0), Com-CDD-5368(1),
Com-CDD-5745(1), Com-CDD-5216(1), Com-CDD-5371(1), Com-CDD-5370(1), Com-CDD-5747(1), Com-CDD-5544(0) */
/* !Deviation: [8023]  (The name of the function does notrespect the naming conventions.) */
/*[8523](The Type field of the function does notrespect the naming conventions.)*/
/*function names are mandated by AUTOSAR*/
/*PRQA S 8023 , 8523 ++ */
/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
FUNC(void ,COM_CODE) Com_Init(
                     P2CONST(Com_ConfigType,AUTOMATIC,COM_CALIB_CONST) config)
/*PRQA S 8023 , 8523 -- */
{
  /*Local Variables declarations*/
  VAR(uint16_least,AUTOMATIC)    u16LoopIndex;
  P2CONST(Com_tstrIPduLookUp,AUTOMATIC,TYPEDEF) pkstrIPduLookUpPtr;
#if (Com_bPB_VARIANT == STD_ON)
  if ( config == (P2CONST(Com_ConfigType,AUTOMATIC,COM_APPL_DATA))NULL_PTR )
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_Init,
                                                           COM_E_PARAM_POINTER);
    #endif /*COM_DEV_ERROR_DETECT*/
  }
  else
  {

  /*copy the main configuration pointer to a global variable*/
    Com_pkstreMainConfig = config;
#endif

    vidInitConfRamArrays();
  
  /*Secondly each Ipdu with its configured parameter*/
  /*Com_init shall call COM_InitIpdu function to initialize the Ipdus with
  bBulkInitMode = true*/
    
	pkstrIPduLookUpPtr = pkstrGET_IPDU_LOOKUP_PTR(0);
    for (u16LoopIndex = 0 ; u16LoopIndex <= Com_u16IPDUIDMAX; u16LoopIndex++ )
    {
  /*void Com_InitIPdu(PduIdType PduId, Boolean bBulkInitMode)*/
      switch (pkstrIPduLookUpPtr[u16LoopIndex].u8Direction)
      {
      /* !Deviation: [3212]  (Casting (PduIdType) is required in case 
                 u16LoopIndex is defined with differenet type than PduIdType) */
/*PRQA S 3212 ++ */
        case Com_u8DIRECTION_TX:
        #if Com_u16NO_OF_TX_IPDU > 0u
        Com_vidInitTxIpdu ((PduIdType)u16LoopIndex ,TRUE) ;
        #endif
        break;

        case Com_u8DIRECTION_RX:
        Com_vidInitRxIpdu ((PduIdType)u16LoopIndex ,TRUE) ;
        break;
/*PRQA S 3212 -- */
        default:
      /*it shall not enter here !*/
        break;
      }
    }

  /*Set the Com_enueStatus to COM_INIT*/
    Com_enueStatus = COM_INIT;
#if (Com_bPB_VARIANT == STD_ON)
  }
#endif
}

/******************************************************************************/
/*! \Trace_To : Com-CDD-0177(0), Com-CDD-0178(0) ,
Com-CDD-InitializationInformative-0526(0),
Com-CDD-InitializationInformative-0520(0) ,
Com-CDD-InitializationInformative-0527(0) , 
Com-CDD-InitializationInformative-5657(0) , 
*/
/* !Deviation: [8023]  (The name of the function does notrespect the naming
conventions.)
[8523](The Type field of the function does notrespect the naming conventions.)*/
/*function names are mandated by AUTOSAR*/
/*PRQA S 8023 , 8523 ++ */
 /* !Deviation: [3205]  ( Some of the local varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S 3205 ++ */
/*************************************************************************/
/*! \Description: Global function to de-initialize the Com               \n

**************************************************************************/
FUNC(void,COM_CODE) Com_DeInit( void )
/*PRQA S 8023 , 8523 -- */
{
/*local variables declaration*/
  VAR(uint16_least,AUTOMATIC) u16LoopIndex ;


  if ( Com_enueStatus == COM_UNINIT )
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID,COM_INSTANCE_ID,COMServiceId_DeInit,
                                                                  COM_E_UNINIT);
    #endif /*COM_DEV_ERROR_DETECT*/
  }
  else
  {


  /* !Deviation: [2465]  the loop could only be executed once ,leading to a QAC
  error , only if the configured   COM_SUPPORTED_IPDU_GROUPS was less than 9  */
/* PRQA S 2465 ++ */

  /*Stopping all IPDU Groups by clearing the Com_au8eIPduGroupVector bits ,
  which will leads to stop inter ECU   Communications*/
#if (COM_SUPPORTED_IPDU_GROUPS > 0U) 
    for (u16LoopIndex = 0 ;
       u16LoopIndex <= (uint16)((COM_SUPPORTED_IPDU_GROUPS - 1u) >> 3) ;
       u16LoopIndex ++ )
    {
      Com_au8eIPduGroupVector[u16LoopIndex] = (uint8)0x00u;
	 #if (Com_bTO_SUPPORT == STD_ON) 
	  Com_au8eRxDMIPduGroupVector[u16LoopIndex] = (uint8)0x00u;
     #endif
	}
#endif
	
	
#if (u16NO_OF_IPDUS_STATUS > 0U)
    /*Initialize Com_u8D_MDT_MASK, Com_u8WAIT_CONF, Com_u8ACTIVE_MASK to FALSE*/
	for (u16LoopIndex = 0 ;
       u16LoopIndex <= (uint16)(u16NO_OF_IPDUS_STATUS - 1u) ;
       u16LoopIndex ++ )
    {
      Com_audteIPduStatus[u16LoopIndex] = (Com_udtIPduStatus)0x00u ;
    }
#endif

  
/* PRQA S 2465 -- */
  /*set the Com_enueStatus to COM_UNINIT*/
    Com_enueStatus = COM_UNINIT;


  }
}
/*PRQA S 3205 -- */
/******************************************************************************/
/*! \Trace_To : Com-CDD-0188(0) */
/* !Deviation: [8023]  (The name of the function does notrespect the naming
conventions.) */
/*[8523](The Type field of the function does notrespect the naming conventions.)
*/
/*function names are mandated by AUTOSAR*/
/*PRQA S 8023 , 8523 ++ */
/*************************************************************************/
/*! \Description: Global function to get the Com  status             \n

**************************************************************************/
FUNC(Com_StatusType,COM_CODE) Com_GetStatus(void)
/*PRQA S 8023  , 8523-- */
{
  return Com_enueStatus ;
}

/******************************************************************************/

/*! \Trace_To : Com-CDD-InitializationInformative-0528(0), Com-CDD-0189(0) ,
Com-CDD-0190(0) , Com-CDD-InitializationInformative-5658(0)*/
/* !Deviation: [8023]  (The name of the function does notrespect the naming
conventions.) */
/*[8523](The Type field of the function does notrespect the naming conventions.)
*/
/*function names are mandated by AUTOSAR*/
/*PRQA S 8023 , 8523 ++ */
/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
FUNC(uint32,COM_CODE) Com_GetConfigurationId( void )
/*PRQA S 8023, 8523 -- */
{
/*local variables declarations*/
  VAR(uint32,AUTOMATIC)u32ConfigId = u32COM_CONF_INVALID_ID ;


  if ( Com_enueStatus == COM_UNINIT )
  {
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(COM_MODULE_ID,COM_INSTANCE_ID,
                          COMServiceId_GetConfigurationId, COM_E_UNINIT);
      #endif /*COM_DEV_ERROR_DETECT */
  }
  else
  {
#if (Com_bPB_VARIANT == STD_ON)
    if(Com_pkstreMainConfig !=
    (P2VAR(Com_ConfigType,AUTOMATIC,COM_APPL_DATA))NULL_PTR)
    {
#endif

      u32ConfigId = u32GET_CONFIG_ID() ;

#if (Com_bPB_VARIANT == STD_ON)
    }
    else
    {
    /*the module was not initialzed , do not try to access the main config
          pointer */
    }
#endif

  }

  return u32ConfigId;
}


/******************************************************************************/

/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
/* !Deviation: [4700]  ( here has been an infringement of a threshold on the
specified metric)
The vidInitIpduSignals function deviate the Cyclomatic complexity , as it
requires a lot of checks , these checks are plan enough ,
so no other meaningfull division is required*/
/* PRQA S 4700 ++ */

 /* !Deviation: [3205]  ( Some of the local varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S 3205 ++ */
#if Com_u16NO_OF_SIGNAL > 0u
static FUNC(void,COM_CODE) vidInitIpduSignals (
                         VAR(uint8,AUTOMATIC)   u8IpduDirection   ,
                         VAR(boolean,AUTOMATIC) bBulkInit ,
                         VAR(boolean,AUTOMATIC) bPackSig,
                         VAR(uint16,AUTOMATIC)  u16IpduSigMapIndx ,
                         VAR(uint16,AUTOMATIC)  u16MaxSigNo)
{
/*local variables declarations*/
  VAR(uint16_least,AUTOMATIC)          u16LoopIndex;
  VAR(Com_SignalIdType,AUTOMATIC)      u16SigID;
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
  VAR(Com_SignalGroupIdType,AUTOMATIC) u16SigGrpID;
  VAR(uint16,AUTOMATIC)				   u16GroupSigIdx; 
#endif
  VAR(uint16 , AUTOMATIC)              u16SigIx;
  VAR(uint8, AUTOMATIC)                u8SigStructType;

  P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF) pkstrIPduToSigMap;
  P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF) pkstrIPduToSigMapLoc;
  P2CONST(Com_tstrGWSignalMapping,AUTOMATIC,TYPEDEF) pkstrGWSigMap;
  P2CONST(Com_tstrGWSignalMapping,AUTOMATIC,TYPEDEF) pkstrGWSigMapLoc;
  P2CONST(Com_tstrGWSrcDesc,AUTOMATIC,TYPEDEF) pkstrGWSrcDescPtr;
  P2CONST(Com_tstrGWDstDesc,AUTOMATIC,TYPEDEF) pkstrGWDstDescPtr;

  pkstrIPduToSigMap = pkstrGET_IPDU_SIG_MAP_PTR();
  pkstrGWSigMap     = pkstrGET_GW_SIG_MAPP_PTR();
  pkstrGWSrcDescPtr = pkstrGET_GW_SRC_DESC_PTR();
  pkstrGWDstDescPtr = pkstrGET_GW_DES_DESC_PTR();


  for (u16LoopIndex = u16IpduSigMapIndx ;
         u16LoopIndex < (u16IpduSigMapIndx+u16MaxSigNo) ;
         u16LoopIndex++ )
  {
	pkstrIPduToSigMapLoc = &pkstrIPduToSigMap[u16LoopIndex];
      /*switch on the type of the content of IPdu to Signal mapping */
    switch (pkstrIPduToSigMapLoc->u8Type)
    {        
      case Com_u8SIGNAL :
        /*Get the Signal ID*/
      #if Com_u16NO_OF_SIGNAL > 0u
        /*Get a pointer to the signal structure identified by the signal ID*/
		vidInitSigParam(pkstrIPduToSigMapLoc->u16Index,
#if Com_u16NO_OF_ONE_EVERY_N_F > 0u
		  bBulkInit,
#endif
		  bPackSig,
		  Com_u8SIGNAL,
		  u8IpduDirection);
      #endif
      break;

      case Com_u8SIGNALGROUP:
      #if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
      u16SigGrpID =
      pkstrIPduToSigMapLoc->u16Index ;
      vidInitSigGrpParam(u16SigGrpID ,bBulkInit, bPackSig,u8IpduDirection) ;
      #endif
      break;

      case Com_u8GWSIGNAL :
      /*get the signal Index*/
      pkstrGWSigMapLoc = &pkstrGWSigMap[pkstrIPduToSigMapLoc->u16Index];
	  if (u8IpduDirection == Com_u8DIRECTION_TX)
      {
		u16SigIx =
        pkstrGWSigMapLoc->u16DstIndex;
        u8SigStructType =
        pkstrGWSigMapLoc->u8DstStructType;
      }
      else
      {
        /*u8IpduDirection == Com_u8DIRECTION_RX */
        u16SigIx =
        pkstrGWSigMapLoc->u16SrcIndex;
        u8SigStructType =
        pkstrGWSigMapLoc->u8SrcStructType;
      }
        /*get the signal ID */
      if(u8SigStructType == (uint8) Com_u8GW_STRUCT_SIG)
      {
        u16SigID = u16GET_SIG_ID_FROM_IX(u16SigIx);
      }
#if (Com_bGW_DESC_SUPPORT == STD_ON) 
      else if (u8SigStructType == (uint8) Com_u8GW_STRUCT_SRC_DESC)
      {
        u16SigID = pkstrGWSrcDescPtr[u16SigIx].u16SignalId;
      }
      else if(u8SigStructType == (uint8) Com_u8GW_STRUCT_DST_DESC)
      {
        u16SigID = pkstrGWDstDescPtr[u16SigIx].u16SignalId;
      }
#endif
      else
      {
      /*shall not enter here*/
        u16SigID = (uint16)0;
      }
      vidInitSigParam(u16SigIx,
#if Com_u16NO_OF_ONE_EVERY_N_F > 0u
		  bBulkInit,
#endif
		  bPackSig,
		  u8SigStructType,
		  u8IpduDirection) ;
        /*clear GW signal flag*/
	  #if Com_u16NO_OF_SIGNAL_STATUS > 0u
	  SchM_Enter_Com_SignalStatus_03();
	  Com_audteSignalStatus[u16SigID] &= (uint8)(~Com_u8GWS_RX);
	  SchM_Exit_Com_SignalStatus_03();
	  #endif
	  
      break;

      case Com_u8GWSIGNALGROUP :            
      #if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
	  if (u8IpduDirection == Com_u8DIRECTION_TX )
      {
        u16SigGrpID =
        pkstrGWSigMap[pkstrIPduToSigMapLoc->u16Index].u16DstIndex;
      }
      else
      {
        /*u8IpduDirection == Com_u8DIRECTION_RX */
        u16SigGrpID =
        pkstrGWSigMap[pkstrIPduToSigMapLoc->u16Index].u16SrcIndex;
      }     
      vidInitSigGrpParam(u16SigGrpID , bBulkInit, bPackSig,u8IpduDirection) ;
        /*clear GW signal flag*/

	  /*clear the GW flag for Signal group by set the flag in the first Its Group Signal*/
	  u16GroupSigIdx = u16GET_GRP_SIG_IX(u16SigGrpID);
      u16SigID = Com_akstreGroupSignalLT[u16GroupSigIdx].u16SignalId;
	  
	  #if Com_u16NO_OF_SIGNAL_STATUS > 0u
	  SchM_Enter_Com_SignalStatus_03();
	  Com_audteSignalStatus[u16SigID] &= (uint8)(~Com_u8GWS_RX);
	  SchM_Exit_Com_SignalStatus_03();
	  #endif
	  
	  #endif
      break;
	  
      default:
      break;
    }
  }
}
#endif 
/*PRQA S 3205 --*/
/* PRQA S 4700 -- */
/******************************************************************************/
   /* !Deviation: [4700]  ( here has been an infringement of a threshold on the
         specified metric)
        The vidInitSigParam function deviate the Cyclomatic complexity , as it
        shall initialize all the ram variables  related to the Signal ,
        requireing a lot of checks , these checks are plan enough ,
     so no other meaningfull division is required*/
/* PRQA S 4700 ++ */
/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
/* !Deviation: [3206]  ( Some of the input parameters are not used 
in this function depending on the configuration.) */
/*PRQA S 3206 ++ */
 /* !Deviation: [3205]  ( Some of the local varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S 3205,3203,3199 ++ */
#if Com_u16NO_OF_SIGNAL > 0u
static FUNC(void,COM_CODE) vidInitSigParam(
                       VAR(Com_SignalIdType,AUTOMATIC) u16SigIx,
#if Com_u16NO_OF_ONE_EVERY_N_F > 0u
                       VAR(boolean,AUTOMATIC)          bBulkInitMode,
#endif                       
					   VAR(boolean,AUTOMATIC)          bPackSignal,
                       VAR(uint8, AUTOMATIC)           u8SigStructType,
					   VAR(uint8, AUTOMATIC)           u8IpduDirection)
/*PRQA S 3206 -- */
{

 /* !Deviation: [8018]  (The name of the constant (const) does notrespect the
 naming conventions.) */
/*[8318]The Component ID of the constant (const) does notrespect the naming
 conventions.*/
/*[8518]The Separator of the constant (const) does notrespect the naming
conventions.*/
/*Limitation in the current QAC check with pointer to constant structure , the
name is correct*/
/*PRQA S 8018 , 8318 ,8518 ++ */
  /*hold a pointer to a const structure that can be either Description or Signal
  */

  P2CONST(Com_tstrSignalPB,AUTOMATIC,COM_CALIB_CONST)       pkstrLocSigPB;
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
  P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,COM_CALIB_CONST)  pkstrLocGrpSigPB;
#endif

#if (Com_bGW_DESC_SUPPORT == STD_ON) 
  P2CONST(Com_tstrGWSrcDesc,AUTOMATIC,COM_CALIB_CONST)      pkstrLocSrcDscPB;
  P2CONST(Com_tstrGWDstDesc,AUTOMATIC,COM_CALIB_CONST)      pkstrLocDstDscPB;
#endif

  P2CONST(void,AUTOMATIC,COM_CALIB_CONST)                   pkvidData;
  P2CONST(Com_tstrSignalLT,AUTOMATIC,COM_CALIB_CONST)       pkstreSignalLT;
/*PRQA S 8018 , 8318 ,8518 -- */
  VAR(uint16,AUTOMATIC)                                     u16SigFilterIndex;
  
#if Com_u16NO_OF_ONE_EVERY_N_F > 0u
  VAR(uint16,AUTOMATIC)                                     u16SpecificFilterIndex;
#endif
#if (Com_bUBIT_SUPPORT== STD_ON) 
  /*VAR(boolean,AUTOMATIC)                                   bIsUBConfigured;*/
  VAR(uint16, AUTOMATIC)									 u16UpdBitPos;
#endif

  VAR(uint16, AUTOMATIC)                                    u16MaxDynLength; 
#if	(Com_bFLOAT_SIGNAL_SUPPORT == STD_OFF)
  VAR(uint8, AUTOMATIC)           							u8CurrSigType;
#endif
  
#if (Com_bTO_SUPPORT == STD_ON) 
  P2VAR(uint32,AUTOMATIC,AUTOMATIC)	 pu32TOT;
  VAR(uint16, AUTOMATIC) u16TOTimerIdx;
  P2CONST(uint32,AUTOMATIC,AUTOMATIC) pku32To;
  VAR(uint32, AUTOMATIC) u32FrstTmeout;
#endif

  u16MaxDynLength = (uint16)0;
  u16SigFilterIndex = 0xFFFFu;
  switch (u8SigStructType)
  {  
    case Com_u8SIG_STRUCT_SIG:
#if (Com_u16NO_OF_SIGNAL > 0u)     
    pkstrLocSigPB =   pkstrGET_PB_SIGNAL_PTR(u16SigIx);	
#if (Com_bUBIT_SUPPORT == STD_ON) 
	u16UpdBitPos = pkstrLocSigPB->u16UpdateBitPosition;
#endif
    pkstreSignalLT = &Com_akstreSignalLT[u16SigIx];
	u16MaxDynLength = pkstreSignalLT->u16SignalLength; 
	u16SigFilterIndex = pkstreSignalLT->u16FilterIndex;

#if	(Com_bFLOAT_SIGNAL_SUPPORT == STD_OFF)
	u8CurrSigType = pkstrLocSigPB->u8SignalType;
#endif	

#if ((Com_bUBIT_SUPPORT == STD_ON) && (Com_bTO_SUPPORT == STD_ON))
	  u16TOTimerIdx = pkstrLocSigPB->u16TOTimerIndex;
	  pku32To = &(pkstrLocSigPB->u32Timeout);
	  u32FrstTmeout = pkstrLocSigPB->u32FirstTimeout;
#endif
	  
#endif
    break;

    case Com_u8SIG_STRUCT_GROUPSIG :
#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
    pkstrLocGrpSigPB =  pkstrGET_PB_GRP_SIG_PTR(u16SigIx);
#if (Com_bUBIT_SUPPORT== STD_ON) 
	u16UpdBitPos = 0xFFFFu;
#endif
    /*group signal does not support the dynamic signals , for U8N arrays ,length
    will be calculated separately */ 
    u16MaxDynLength = (uint16)0;
	
#if	(Com_bFLOAT_SIGNAL_SUPPORT == STD_OFF)
	u8CurrSigType = pkstrLocGrpSigPB->u8SignalType;
#endif
	
#endif   
    break;

 
    case Com_u8GW_STRUCT_SRC_DESC:
#if (Com_bGW_DESC_SUPPORT == STD_ON) 
    pkstrLocSrcDscPB = pkstrGET_PB_SRC_DESC_PTR(u16SigIx);
#if (Com_bUBIT_SUPPORT== STD_ON) 
	u16UpdBitPos = pkstrLocSrcDscPB->u16UpdateBitPosition;
#endif

#if (Com_u16GW_SIG_LENGTH_SIZE  > 0u)     
    u16MaxDynLength = Com_aku16eGWSignalLength[pkstrLocSrcDscPB->u16LengthIndex];
#endif

#if	(Com_bFLOAT_SIGNAL_SUPPORT == STD_OFF)
	u8CurrSigType = pkstrLocSrcDscPB->u8SignalType;
#endif
    
#endif
    break;


    case Com_u8GW_STRUCT_DST_DESC:
#if (Com_bGW_DESC_SUPPORT == STD_ON) 
    pkstrLocDstDscPB = pkstrGET_PB_DST_DESC_PTR(u16SigIx);
	
    #if (Com_bUBIT_SUPPORT== STD_ON) 
	u16UpdBitPos = pkstrLocDstDscPB->u16UpdateBitPosition;
	#endif

	#if (Com_u16GW_SIG_LENGTH_SIZE  > 0u)     
    u16MaxDynLength = Com_aku16eGWSignalLength[pkstrLocDstDscPB->u16LengthIndex]; 
	#endif          
	u16SigFilterIndex = pkstrLocDstDscPB->u16FilterIndex;

#if	(Com_bFLOAT_SIGNAL_SUPPORT == STD_OFF)
	u8CurrSigType = pkstrLocDstDscPB->u8SignalType;
#endif
#endif
    break;


    default:
#if (Com_bUBIT_SUPPORT== STD_ON) 
	u16UpdBitPos = 0xFFFFu;
#endif
    pkstrLocSigPB = (P2CONST(Com_tstrSignalPB,AUTOMATIC,COM_CALIB_CONST))NULL_PTR;
  
    u8IpduDirection = (uint8)0xFFu;        
    /*shall not enter here*/
    break;
  }



  pkvidData = Com_pkvidInitSigObjnOldVal(u8SigStructType ,u16SigIx, TRUE);
  /*Set the Signal timeOut ,if configured, to its corresponding value*/
  /*update bit option will be tightly coupled with stand alone timeout of signals
            so it should be closed if update bit is OFF		*/
#if (Com_u16NO_OF_SIGNAL > 0u)  
 #if ((Com_bUBIT_SUPPORT == STD_ON) && (Com_bTO_SUPPORT == STD_ON))  
  if (u8SigStructType == (uint8) Com_u8SIG_STRUCT_SIG)
  {
	/*!Deviation: [3353] (The variable 'pkstrLocSigPB' is possibly unset
	 at this point.)*/
	 /*!Deviation: [0505](Dereferencing pointer value that is apparently 
	 NULL)*/
	 /*this variable access is protected by the above if condition*/
	 /* PRQA S 3353 , 0505 ++ */
	/*only signal with UB will have a separate TO monitoring*/ 
	   if (( (*pku32To) != 0xFFFFFFFFUL) &&
	   (u16UpdBitPos != (uint16)0xFFFFu))
    {
		pu32TOT = pkstrGET_PB_TIMEOUT_TIMER();
	  
	  if (u32FrstTmeout != 0xFFFFFFFFUL)
      {
        /*N.B Fisrt Timeout is a LT parameter while the Timeout is a PB one*/
        SchM_Enter_Com_TimeoutTimer();
        pu32TOT[u16TOTimerIdx] = u32FrstTmeout;
        SchM_Exit_Com_TimeoutTimer();
      }
      else
      {
        SchM_Enter_Com_TimeoutTimer();
        pu32TOT[u16TOTimerIdx] = *pku32To;
        SchM_Exit_Com_TimeoutTimer();
      }
        /* PRQA S 3353 , 0505 -- */
    }
  }
  else
  {
  /*do nothing , time out is not configurable for description and initialized 
  separately in another function for signal group*/
  }
  #endif /* COM_UBIT_SUPPORT*/ 
#endif /* (Com_u16NO_OF_SIGNAL > 0u)  */
 
    /*pack signals and clear update bits only for TX Ipdu or deferred RX Ipdu
         since immediate RX idpu does not have an IpduRam buffer*/
  if (bPackSignal == (boolean)TRUE)
  {
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
	/*[3382]  ( Unsigned arithmetic apparently results in wraparound past zero. ) */
	/*[3762]  ( Implicit conversion: int to unsigned long. ) */
	/*PRQA S 0291, 0715, 0769, 2018, 3201, 3212, 3297, 3325, 3334, 3353, 3382, 3762 ++ */
    /*fill the signal in the IPDU buffer with the INIT value*/
	
	
	   /* Com-CDD-InitializationInformative-0262(0),
		Com-CDD-0437(0) , Com-CDD-0438(0) ,
		Com-CDD-0439(0) , Com-CDD-0441(0) ,
		Com-CDD-0440(0) , Com-CDD-0442(0) ,
		Com-CDD-0443(0) , Com-CDD-InitializationInformative-5721(0) , 
		Com-CDD-InitializationInformative-0269(0) */
#if (Com_bGW_DESC_SUPPORT == STD_OFF)
	  if (u8SigStructType != Com_u8GW_STRUCT_DST_DESC && u8SigStructType != Com_u8GW_STRUCT_SRC_DESC)
	  {
#endif
#if	(Com_bFLOAT_SIGNAL_SUPPORT == STD_OFF)
		if(u8CurrSigType !=Com_u8SIGNAL_TYPE_FLOAT32 && u8CurrSigType !=Com_u8SIGNAL_TYPE_FLOAT64)
		{
#endif
			Com_vidSignalPackSignal(u16SigIx ,pkvidData, u8SigStructType,u16MaxDynLength);
#if	(Com_bFLOAT_SIGNAL_SUPPORT == STD_OFF)
		}
#endif
#if (Com_bGW_DESC_SUPPORT == STD_OFF)
	 }
#endif
	/*PRQA S 0291, 0715, 0769, 2018, 3201, 3212, 3297, 3325, 3334, 3353, 3382, 3762 -- */
    /*clear the update bit*/
/*clearing update bits for Tx ipdu only since for Rx Ipdu the unused area are
set to 0's and only the deferred Rx ipdu has entries in the Ram buffer*/
#if (Com_bUBIT_SUPPORT== STD_ON)    
   if (u8IpduDirection == Com_u8DIRECTION_TX )
    {
      if (u16UpdBitPos != (uint16)0xFFFFu)
      {
        Com_vidSignalEditUpdateBit(u8SigStructType,u16SigIx,u16UpdBitPos,FALSE);
      }
    }
#endif

  }
    /*if the signal had a configured OneEveryN filter clear the occurance */
#if Com_u16NO_OF_ONE_EVERY_N_F > 0u
  if ((u8SigStructType == (uint8) Com_u8SIGNAL) 
#if (Com_bGW_DESC_SUPPORT == STD_ON) 
  || (u8SigStructType == (uint8) Com_u8GW_STRUCT_DST_DESC)
#endif  
  )
  {
	
	
    if ((bBulkInitMode == (boolean)FALSE)
	&& (u16SigFilterIndex != (uint16)0xFFFFu)
	&& ((Com_akstreFilter[u16SigFilterIndex].u8FilterAlgorithm) == (uint8)Com_u8F_ONE_EVERY_N))
    {
	  #if Com_u16NO_OF_ONE_EVERY_N_F > 0u
      u16SpecificFilterIndex = Com_akstreFilter[u16SigFilterIndex].u16Index;
      Com_au32eOneEveryNFilterCtr[Com_akstreOneEveryNFilter[
      u16SpecificFilterIndex].u16CounterIndex] = (uint32)0;
	  #endif
	  
    }

  }
  else
  {
    /*do nothing , filter is not configured for Com_u8GW_STRUCT_SRC_DESC */
  }
#endif
}
#endif
/*PRQA S 3205,3203, 3199-- */
/* PRQA S 4700 -- */



/******************************************************************************/
/* !Deviation: [4700]  ( here has been an infringement of a threshold on the
specified metric)
The COM_vidInitTxIpdu function deviate the Cyclomatic complexity , as it
shall initialize all the ram variables related to the TX Ipdus ,
requireing a lot of checks , these checks are plan enough ,
so no other meaningfull division is required*/
/* PRQA S 4700 ++ */

/*! \Trace_To : Com-CDD-InitializationInformative-0238(0),
Com-CDD-InitializationInformative-0531(0) ,
Com-CDD-InitializationInformative-0018(0) , Com-CDD-InitializationInformative-0240(0)
Com-CDD-InitializationInformative-0241(0) , Com-CDD-5746(0), Com-CDD-5368(1), Com-CDD-5371(1)*/
/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
/* !Deviation: [3206]  ( Some of the input parameters are not used 
in this function depending on the configuration.) */
/*PRQA S 3206 ++ */
#if(Com_u16NO_OF_TX_IPDU > 0U)
FUNC(void,COM_CODE)  Com_vidInitTxIpdu (
                    VAR(PduIdType,AUTOMATIC) u16PduId ,
                    VAR(boolean,AUTOMATIC)   bBulkInitMode)
/*PRQA S 3206 -- */
{
  VAR(uint32_least,AUTOMATIC)                       u32IpduRamBufferIndex;
  
/* !Deviation: [8018]  (The name of the constant (const) does notrespect the
 naming conventions.) */
/*[8318]The Component ID of the constant (const) does notrespect the naming
 conventions.*/
/*[8518]The Separator of the constant (const) does notrespect the naming
 conventions.*/
/*Limitation in the current QAC check with pointer to constant structure , the
 name is correct*/
/*PRQA S 8018 , 8318 ,8518 ++ */
  P2CONST(Com_tstrTxIPdu,AUTOMATIC,COM_CALIB_CONST) pkstrLocTXIpduPB;
/*PRQA S 8018 , 8318 ,8518 -- */

#if (Com_bIPDU_COUNTER_SUPPORT == STD_ON)	
  VAR(uint8,AUTOMATIC)                              u8TxIpduCtrBitPos;
  VAR(uint16,AUTOMATIC)                             u16TxIpduCtrBytePos;
  VAR(uint8,AUTOMATIC)                              u8TxIpduCtrSize;
  VAR(uint16,AUTOMATIC)                             u16IPduCtrIx;
  P2CONST(Com_tstrIPduCounter, AUTOMATIC,AUTOMATIC) pkstrIPduCtr;
#endif
  
#if (Com_bDATA_TP_SUPPORT == STD_ON)
  VAR(uint16,AUTOMATIC)                             u16TpIPduCtrIndex;
  P2VAR(uint16, AUTOMATIC,AUTOMATIC) 				pu16TpIPduCtr;
#endif
  
  P2VAR(uint8,AUTOMATIC,TYPEDEF)	   pu8IPduBuf;
  P2CONST(uint32, AUTOMATIC,AUTOMATIC) pku32IPduBufIdx;
  P2CONST(uint16, AUTOMATIC,AUTOMATIC) pku16IPduLength_ptr;
  P2CONST(uint16, AUTOMATIC,AUTOMATIC) pku16TxUnusdAreasDfltIdx;
  

#if (Com_bTO_SUPPORT == STD_ON) 
  P2VAR(uint32,AUTOMATIC,AUTOMATIC)  pu32TOT;
  
  VAR(uint16,AUTOMATIC)              u16TOTimerIdx;
#endif
  
  pkstrLocTXIpduPB = pkstrGET_TX_IPDU_PTR(u16PduId);
  /*filling the IPDU RAM buffer with the unused area default value */
  /*get the ram buffer index*/
  /*u16Index will hold the ram buffer index*/
  pu8IPduBuf = pkstrGET_IPDU_BUFF_PTR(0);
  pku32IPduBufIdx = &(pkstrLocTXIpduPB->u32IPduBufferIndex);
  pku16IPduLength_ptr = &(pkstrLocTXIpduPB->u16IPduLength);
  pku16TxUnusdAreasDfltIdx = &(pkstrLocTXIpduPB->u16TxUnusedAreasDefltIx);

  for (u32IpduRamBufferIndex = *pku32IPduBufIdx; u32IpduRamBufferIndex < ((*pku32IPduBufIdx) +
  (*pku16IPduLength_ptr)) ; u32IpduRamBufferIndex ++ )
  {
    SchM_Enter_Com_IPduBuff();
    pu8IPduBuf[u32IpduRamBufferIndex] =
    Com_aku8eTxUnusedAreaDefault[*pku16TxUnusdAreasDfltIdx];
    SchM_Exit_Com_IPduBuff();
  }
  /*filling each signal within the Ipdu with the INIT value , i.e packing the
  corresponding signal in the  Ipdu Ram buffer and in the corresponding data
  object*/
  /*u16Index hold the index of the signal in the ipdutosignalmapping array*/
  /*u16Index = pkstrLocTXIpduPB->ku16IPduSigMapIndx*/

  /*Call the vidInitSigObjFltrBfr which will initialize all signals objects ,
  Old_value filter and the ram buffer  with the signal init value ,
  OneEveryN filter with 0s and clear update bits */
  /*void vidInitSigObjFltrBfr (uint16 IpduSigMapIndx , uint16 u16MaxSigNo ,
   bool bBulkInitMode , bool bPackSig)*/

  vidInitIpduSignals (Com_u8DIRECTION_TX ,
   bBulkInitMode , TRUE,
   (pkstrLocTXIpduPB->u16IPduSigMappingIndex) ,
  (pkstrLocTXIpduPB->u16IPduNoOfSignals));

  /*protection againest accessing of empty arrays*/

  /*if the Ipdu has a configured counter , pack the Ipdu counter into its
      correct place of the Ipdu Ram Buffer*/
	
#if (Com_bIPDU_COUNTER_SUPPORT == STD_ON)	
  
  u16IPduCtrIx = pkstrLocTXIpduPB->u16IPduCounterIndex;
  if(u16IPduCtrIx != (uint16)0xFFFFu)
  {

     /*get the CTR byte position and corresponding bit position*/
    pkstrIPduCtr = pkstrGET_IPDU_CTR_PTR(u16IPduCtrIx);
	u16TxIpduCtrBytePos = (uint16)(pkstrIPduCtr->u16IPduCounterStartPos >>(uint16)3u);
    u8TxIpduCtrBitPos   =
    (uint8) (pkstrIPduCtr->u16IPduCounterStartPos -
    ((uint16)(u16TxIpduCtrBytePos <<(uint16)3)));
    u32IpduRamBufferIndex =
    (pkstrLocTXIpduPB->u32IPduBufferIndex + (uint32)u16TxIpduCtrBytePos);
     /*get the couter size */
    u8TxIpduCtrSize = pkstrIPduCtr->u8IPduCounterSize;
     /*clear the place of the counter inside the ipdu ram buffer , i.e set the
            initial value of the couter to zero*/
    SchM_Enter_Com_IPduBuff();
    pu8IPduBuf[u32IpduRamBufferIndex] &=
    (uint8)(u8MASK_CERTAIN_BITS(u8TxIpduCtrBitPos,u8TxIpduCtrSize) ^0xFF);
    SchM_Exit_Com_IPduBuff();
  }
  
#endif

  /*fill the TimeOut timer with the correct configured value
  due to an ICR this requirement changed to be: fill it with zeros*/
  
#if (Com_bTO_SUPPORT == STD_ON)
  u16TOTimerIdx = pkstrLocTXIpduPB->u16TOTimerIndex;
  if (u16TOTimerIdx != (uint16)0xFFFFu)
  {
	pu32TOT = pkstrGET_PB_TIMEOUT_TIMER();
    SchM_Enter_Com_TimeoutTimer();
    pu32TOT[u16TOTimerIdx] = (uint32)0 ;
    SchM_Exit_Com_TimeoutTimer();
  }
#endif 
  
  vidInitTxModeParam(u16PduId);
  
  if(bBulkInitMode == FALSE)
  {
  
  #if (Com_bIPDU_COUNTER_SUPPORT == STD_ON)
    #if Com_u16NO_OF_IPDU_COUNTER > 0u
    /*  ComIPduCounterRamArray with zero*/
	if (u16IPduCtrIx != (uint16)0xFFFFu)
    {
      Com_au8eIPduCounterRam[u16IPduCtrIx] = 0x00u ;
    }
    #endif
  #endif

    /*clear the Com_u8WAIT_CONF, Com_u8DEF_PROC_MASK */
	/* !Deviation: [0277]  ( An Integer Constant experssion with negative value is being converted to 
		an unsigned type)  */
	/*PRQA S 0277 ++ */
#if u16NO_OF_IPDUS_STATUS > 0u
	SchM_Enter_Com_IPduStatus_03();
	Com_audteIPduStatus[u16PduId] &= (((Com_udtIPduStatus)(~Com_u8WAIT_CONF)) | ((Com_udtIPduStatus)(~Com_u8DEF_PROC_MASK))); 
	SchM_Exit_Com_IPduStatus_03();
#endif
	/*PRQA S 0277 -- */
	
  #if (Com_bDATA_TP_SUPPORT == STD_ON)
	u16TpIPduCtrIndex = pkstrLocTXIpduPB->u16TpIPduByteCtrIndex;
	
	pu16TpIPduCtr = pkstrGET_TP_IPDU_CTR_PTR(0);
	if(u16TpIPduCtrIndex != (uint16)0xFFFFu)
    {      
      pu16TpIPduCtr[u16TpIPduCtrIndex] = (uint16)0;
    }
  #endif
  }
}
#endif
/* PRQA S 4700 -- */

/* !Deviation: [4700]  ( here has been an infringement of a threshold on the
specified metric)
The COM_vidInitRxIpdu function deviate the STPTH , as it
shall initialize all the ram variables related to the RX Ipdus ,
requireing a lot of checks , these checks are plan enough ,
so no other meaningfull division is required*/
/* PRQA S 4700 ++ */
 /* !Deviation: [3205]  ( Some of the local varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S 3205,3199, 3203  ++ */
/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
/*! \Trace_To :Com-CDD-InitializationInformative-0238(0),
Com-CDD-InitializationInformative-0018(0) , Com-CDD-InitializationInformative-5649(0) , 
Com-CDD-InitializationInformative-5650(0) , Com-CDD-InitializationInformative-5651(0) , 
Com-CDD-InitializationInformative-5653(0) , Com-CDD-InitializationInformative-5654(0) , 
Com-CDD-5746(0), Com-CDD-5745(1)*/
FUNC(void,COM_CODE) Com_vidInitRxIpdu (
                     VAR(PduIdType,AUTOMATIC) u16PduId ,
                     VAR(boolean,AUTOMATIC)   bBulkInitMode)
{

  VAR(boolean,AUTOMATIC)                            bPackSignal;
  
 #if (Com_bRX_REPLICAS_SUPPORT == STD_ON)
  VAR(uint16,AUTOMATIC)                             u16IPduReplicaIx;
 #endif
  VAR(uint32_least,AUTOMATIC)                       u32IpduRamBufferIndex;
#if (Com_bIPDU_COUNTER_SUPPORT == STD_ON)
  VAR(uint16,AUTOMATIC)                             u16IPduCtrIx;
#endif
#if (Com_bDATA_TP_SUPPORT == STD_ON) 
	VAR(uint16,AUTOMATIC)                           u16TpIPduCtrIx;
	P2VAR(uint16, AUTOMATIC,AUTOMATIC) 				pu16TpIPduCtr;
#endif
  P2CONST(uint32, AUTOMATIC,AUTOMATIC) pku32IPduBufIdx;
  P2CONST(uint16, AUTOMATIC,AUTOMATIC) pu16IPduLength;
  P2VAR(uint8,AUTOMATIC,TYPEDEF) pu8IPduBuf;

#if (Com_bTO_SUPPORT == STD_ON)
  P2VAR(uint32,AUTOMATIC,AUTOMATIC)	   pu32TOT;
  P2CONST(uint16, AUTOMATIC,AUTOMATIC) pku16TOTimerIdx;
  P2CONST(uint16, AUTOMATIC,AUTOMATIC) pu16FirstTimeoutIdx;
  P2CONST(uint32, AUTOMATIC,AUTOMATIC) pku32To;
#endif
/* !Deviation: [8018]  (The name of the constant (const) does notrespect the
naming conventions.) */
/*[8318]The Component ID of the constant (const) does notrespect the naming
 conventions.*/
/*[8518]The Separator of the constant (const) does notrespect the naming
 conventions.*/
/*Limitation in the current QAC check with pointer to constant structure , the
name is correct*/
/*PRQA S 8018 , 8318 , 8518++ */
  P2CONST(Com_tstrRxIPdu,AUTOMATIC,COM_CALIB_CONST) pkstrLocRXIpduPB;
/*PRQA S 8018 , 8318 ,8518 -- */

  /*shall initialize the following :
  *Signal Object
  *Old_Value of the filter
  *Ipdubuffer and clear the updatebits for defrered processing IPDUs
  */
  pkstrLocRXIpduPB = pkstrGET_RX_IPDU_PTR(u16PduId);

/*Rx Ipdu will be saved in the  Ipdu Ram buffer in the following cases :
1.Deferred Ipdu 
2.Immediate Ipdu with configured Replica 
3.Tp Ipdu */
  pku32IPduBufIdx = &(pkstrLocRXIpduPB->u32IPduBufferIndex);
  if((*pku32IPduBufIdx) != 0xFFFFFFFFUL)
  {
    /*filling the IPDU RAM buffer with the unused area default value , althoug
    there is default area configured
    for the RX Ipdu , but due to the design , Deferred RX IPDUs will have an
    entry in the RAM buffer , and since there is an AutoSAR requirement to
    initialize all RAM variables , the unused area of the RX Ipdu shall be
    initialized
    */
    /*get the ram buffer index*/
    /*u16Index will hold the ram buffer index*/
	pu16IPduLength = &(pkstrLocRXIpduPB->u16IPduLength);
	pu8IPduBuf = pkstrGET_IPDU_BUFF_PTR(0);
    for (u32IpduRamBufferIndex = (*pku32IPduBufIdx) ; u32IpduRamBufferIndex < ((*pku32IPduBufIdx) +
    (*pu16IPduLength)) ; u32IpduRamBufferIndex ++ )
    {
      SchM_Enter_Com_IPduBuff();
      pu8IPduBuf[u32IpduRamBufferIndex] = u8RX_IPDU_UNUSED_AREA;
      SchM_Exit_Com_IPduBuff();
    }

    bPackSignal = TRUE ;
  }
  else
  {
    bPackSignal = FALSE ;
  }
  #if Com_u16NO_OF_SIGNAL > 0u
  vidInitIpduSignals (Com_u8DIRECTION_RX ,
  bBulkInitMode , bPackSignal,
  (pkstrLocRXIpduPB->u16IPduSigMappingIndex) ,
  (pkstrLocRXIpduPB->u16IPduNoOfSignals));
  #endif
  /*Reset the Replica counter , if configured , to its corresponding value*/
  
  #if ((Com_u16NO_OF_IPDU_REPLIC > 0u) && (Com_bRX_REPLICAS_SUPPORT == STD_ON))
  u16IPduReplicaIx = pkstrLocRXIpduPB->u16IPduReplicationIndex;
  if(u16IPduReplicaIx != (uint16)0xFFFFu)
  {
    Com_au8eReplicasCounter [u16IPduReplicaIx] =
    Com_akstreIPduReplication[u16IPduReplicaIx].
    u8NoOfReplicas ;
  }
  #endif
  /*fill the TimeOut timer with the correct configured value*/
  
#if (Com_bTO_SUPPORT == STD_ON)
  pku32To = &(pkstrLocRXIpduPB->u32Timeout);
  if ((*pku32To) != 0xFFFFFFFFUL)
  {
	  pu32TOT = pkstrGET_PB_TIMEOUT_TIMER();
	  pku16TOTimerIdx = &(pkstrLocRXIpduPB->u16TOTimerIndex);
	  pu16FirstTimeoutIdx = &(pkstrLocRXIpduPB->u16FirstTimeoutIndex);
	if((*pu16FirstTimeoutIdx) != (uint16)0xFFFFu)
    {
      SchM_Enter_Com_TimeoutTimer();
      pu32TOT[*pku16TOTimerIdx] = u32IPDU_GET_FIRST_FTIMEOUT(*pu16FirstTimeoutIdx);
      SchM_Exit_Com_TimeoutTimer();
    }
    else
    {
      SchM_Enter_Com_TimeoutTimer();
      pu32TOT[*pku16TOTimerIdx] = *pku32To;
      SchM_Exit_Com_TimeoutTimer();
    }
  }
#endif

  if(bBulkInitMode == FALSE)
  {
  /*  ComIPduCounterRamArray with zero*/

#if (Com_bIPDU_COUNTER_SUPPORT == STD_ON)
	u16IPduCtrIx = pkstrLocRXIpduPB->u16IPduCounterIndex;
	if(u16IPduCtrIx != (uint16)0xFFFFu)
    {
      /*SET Com_u8CTR_ACC_ANY flag for each Rx Ipdu with 1s*/
		SchM_Enter_Com_IPduStatus_03();
		Com_audteIPduStatus[u16PduId] |= Com_u8CTR_ACC_ANY; 
		SchM_Exit_Com_IPduStatus_03();
    }
#endif
    /*clear IPDU's Com_u8DEF_PROC_MASK flag*/
    if ((pkstrLocRXIpduPB->udteRxIPduFlags & Com_u8RX_IPDUSIGPROCESSING) != Com_u8SIG_PROC_IMMEDIATE)
    {
		#if u16NO_OF_IPDUS_STATUS > 0u
		SchM_Enter_Com_IPduStatus_03();
		Com_audteIPduStatus[u16PduId] &=  (Com_udtIPduStatus)(~Com_u8DEF_PROC_MASK); 
		SchM_Exit_Com_IPduStatus_03();
		#endif
    }

#if (Com_bDATA_TP_SUPPORT == STD_ON)    
	u16TpIPduCtrIx = pkstrLocRXIpduPB->u16TpIPduByteCtrIndex;
	
	pu16TpIPduCtr = pkstrGET_TP_IPDU_CTR_PTR(0);
	if (u16TpIPduCtrIx != (uint16)0xFFFFu)
    {      
       pu16TpIPduCtr[u16TpIPduCtrIx] = (uint16)0;
    }
#endif

  }

}
/*PRQA S 3205, 3199, 3203 -- */
/* PRQA S 4700 -- */
/* !Deviation: [4700]  ( here has been an infringement of a threshold on the
specified metric)
The Com_pkvidInitSigObjnOldVal function deviate the Cyclomatic complexity and the
Estimated Static Program Paths , although it is composed of 2 switch cases only
, one to get the required parameter values and another to call a specific 
initialization function based on the signal type so no other meaningfull 
division is required*/
/* PRQA S 4700 ++ */
/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
/* !Deviation: [3206]  ( Some of the input parameters are not used 
in this function depending on the configuration.) */
/*PRQA S 3206 ++ */
/* !Deviation: [3205]  ( Some of the local varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S 3205 ++ */
FUNC(Com_tpkvidConstCalibPtr,COM_CODE)
      Com_pkvidInitSigObjnOldVal(
                    VAR(uint8,AUTOMATIC)   						u8SigStructType,
                    VAR(uint16,AUTOMATIC)                       u16SigIx,
                    VAR(boolean,AUTOMATIC)                      bInitOldVal)
/*PRQA S 3206 -- */
{
 /* !Deviation: [8018]  (The name of the constant (const) does not respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */
  P2CONST(void,AUTOMATIC,COM_CALIB_CONST)                   pkvidData;
  P2CONST(Com_tstrSignalPB,AUTOMATIC,COM_CALIB_CONST)       pkstrLocSigPB;
  
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
  P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,COM_CALIB_CONST)  pkstrLocGrpSigPB;
  P2CONST(Com_tstrGroupSignalLT,AUTOMATIC,COM_CALIB_CONST)  pstrGroupSignalLT;
#endif
  P2CONST(Com_tstrSignalLT,AUTOMATIC,COM_CALIB_CONST)  		pkstreSignalLT;

#if (Com_bGW_DESC_SUPPORT == STD_ON) 
  P2CONST(Com_tstrGWSrcDesc,AUTOMATIC,COM_CALIB_CONST)      pkstrLocSrcDscPB;
  P2CONST(Com_tstrGWDstDesc,AUTOMATIC,COM_CALIB_CONST)      pkstrLocDstDscPB;
#endif
/*PRQA S 8018 , 8318, 8518  -- */

  VAR(uint8, AUTOMATIC)                                     u8SigType;
  VAR(uint16,AUTOMATIC)                                     u16SigInitValIx;
  VAR(uint16,AUTOMATIC)                                     u16SigObjIx;
  VAR(uint16, AUTOMATIC)                                    u16SigByteLen;
  VAR(uint16,AUTOMATIC)                                     u16SpecificFilterIndex;
  VAR(boolean,AUTOMATIC)                                    bInitOldValFilter;  
  VAR(uint16,AUTOMATIC)                                     u16FilterIx;
  P2CONST(Com_tstrFilter,AUTOMATIC,COM_CALIB_CONST)      	pkstrSigFilter;
  

#if ((Com_u16NO_OF_MASK_OLD_F_B   > 0u) || \
(Com_u16NO_OF_MASK_OLD_F_U8  > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S8  > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_U16 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S16 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_U32 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S32 > 0u) )
  VAR(uint8,AUTOMATIC) u8FilterAlg;
  #endif


  pkvidData = (P2CONST(void,AUTOMATIC,COM_CALIB_CONST)) NULL_PTR;
  u16SigInitValIx = (uint16)0;
  u16SpecificFilterIndex = (uint16)0;
  
#if ((Com_u16NO_OF_MASK_OLD_F_B   > 0u) || \
(Com_u16NO_OF_MASK_OLD_F_U8  > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S8  > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_U16 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S16 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_U32 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S32 > 0u) )

  u8FilterAlg =(uint8)0xFFu;
#endif

  switch (u8SigStructType)
  {
#if(Com_u16NO_OF_SIGNAL > 0u)
    case Com_u8SIG_STRUCT_SIG:
    pkstrLocSigPB =   pkstrGET_PB_SIGNAL_PTR(u16SigIx);
    u8SigType	  =  pkstrLocSigPB->u8SignalType;
    u16SigInitValIx = pkstrLocSigPB->u16SignalInitValueIndex;
    u16SigObjIx = pkstrLocSigPB->u16SignalObjectIndex ;
    pkstreSignalLT = &Com_akstreSignalLT[u16SigIx];
	u16SigByteLen = pkstreSignalLT->u16SignalLength;
	u16FilterIx = pkstreSignalLT->u16FilterIndex;
   #if ((Com_u16NO_OF_MASK_OLD_F_B   > 0u) || \
(Com_u16NO_OF_MASK_OLD_F_U8  > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S8  > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_U16 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S16 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_U32 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S32 > 0u) )

	if(u16FilterIx != (uint16)0xFFFFu)
	{
	 pkstrSigFilter = pkstrGET_FILTER_SPEC_PTR(pkstreSignalLT->u16FilterIndex);
	 u8FilterAlg = pkstrSigFilter->u8FilterAlgorithm;
     u16SpecificFilterIndex = pkstrSigFilter->u16Index;
	}
#endif
    break;
#endif

#if((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))     
    case Com_u8SIG_STRUCT_GROUPSIG:
    pkstrLocGrpSigPB =   pkstrGET_PB_GRP_SIG_PTR(u16SigIx);
    u8SigType =  pkstrLocGrpSigPB->u8SignalType;
    u16SigInitValIx = pkstrLocGrpSigPB->u16SignalInitValueIndex;
    u16SigObjIx = pkstrLocGrpSigPB->u16SignalObjectIndex ;
	pstrGroupSignalLT = &Com_akstreGroupSignalLT[u16SigIx];   
    u16SigByteLen =  pstrGroupSignalLT->u16SignalLength;
	u16FilterIx = pstrGroupSignalLT->u16FilterIndex;
#if ((Com_u16NO_OF_MASK_OLD_F_B   > 0u) || \
(Com_u16NO_OF_MASK_OLD_F_U8  > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S8  > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_U16 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S16 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_U32 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S32 > 0u) )

	if(u16FilterIx!= (uint16)0xFFFFu)
	{
     pkstrSigFilter = pkstrGET_FILTER_SPEC_PTR(pstrGroupSignalLT->u16FilterIndex);
	 u8FilterAlg 	= pkstrSigFilter->u8FilterAlgorithm;
     u16SpecificFilterIndex = pkstrSigFilter->u16Index;
	}
#endif
    break;
#endif/*#if(Com_u16NO_OF_GROUP_SIGSLT > 0u) */
    
#if (Com_bGW_DESC_SUPPORT == STD_ON)
    case Com_u8GW_STRUCT_SRC_DESC:
    pkstrLocSrcDscPB = pkstrGET_PB_SRC_DESC_PTR(u16SigIx);
    u8SigType =  pkstrLocSrcDscPB->u8SignalType;
    u16SigObjIx = pkstrLocSrcDscPB->u16SignalObjectIndex ;
    u16SigByteLen =  pkstrLocSrcDscPB->u16LengthIndex;
#if ((Com_u16NO_OF_MASK_OLD_F_B   > 0u) || \
(Com_u16NO_OF_MASK_OLD_F_U8  > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S8  > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_U16 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S16 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_U32 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S32 > 0u) )
    /* Com_u8GW_STRUCT_SRC_DESC shall not have a configured filter*/
    /* dummy values since it shall not be used*/    
    u8FilterAlg =   (uint8)0xFFu;
    u16SpecificFilterIndex = (uint16)0u;
	u16FilterIx =  (uint16)0xFFFFu;
    u16SigInitValIx = (uint16)0;
#endif
    break;

    case Com_u8GW_STRUCT_DST_DESC:
    pkstrLocDstDscPB = pkstrGET_PB_DST_DESC_PTR(u16SigIx);
    u8SigType =  pkstrLocDstDscPB->u8SignalType;
    u16SigInitValIx = pkstrLocDstDscPB->u16SignalInitValueIndex;
    u16SigObjIx = pkstrLocDstDscPB->u16SignalObjectIndex ;
    u16SigByteLen =  pkstrLocDstDscPB->u16LengthIndex;
	u16FilterIx = pkstrLocDstDscPB->u16FilterIndex;
#if ((Com_u16NO_OF_MASK_OLD_F_B   > 0u) || \
(Com_u16NO_OF_MASK_OLD_F_U8  > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S8  > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_U16 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S16 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_U32 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S32 > 0u) )
   if(u16FilterIx != (uint16)0xFFFFu)
   {
	 pkstrSigFilter = pkstrGET_FILTER_SPEC_PTR(pkstrLocDstDscPB->u16FilterIndex);
	 u8FilterAlg = pkstrSigFilter->u8FilterAlgorithm;
     u16SpecificFilterIndex = pkstrSigFilter->u16Index;
    }
#endif
    break;
#endif /*Com_bGW_DESC_SUPPORT*/

    default:
    /* condition exit and dummy values since they shall not be used*/    
    u8SigType = (uint8)0xFF ;

#if ((Com_u16NO_OF_MASK_OLD_F_B   > 0u) || \
(Com_u16NO_OF_MASK_OLD_F_U8  > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S8  > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_U16 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S16 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_U32 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S32 > 0u) )    
    u8FilterAlg =(uint8)0xFFu;
	u16SpecificFilterIndex = (uint16)0u;
	u16FilterIx =  (uint16)0xFFFFu;
#endif 
    
    u16SigObjIx = (uint16)0; 
    u16SigByteLen =  (uint16)0;   
    break;
  }
 
   /* PRQA S 3757 ++ */
  bInitOldValFilter = bInitOldVal 
#if ((Com_u16NO_OF_MASK_OLD_F_B   > 0u) || \
(Com_u16NO_OF_MASK_OLD_F_U8  > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S8  > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_U16 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S16 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_U32 > 0u) ||  \
(Com_u16NO_OF_MASK_OLD_F_S32 > 0u) )    
						&& (u16FilterIx != (uint16)0xFFFFu)
                        && (u8FilterAlg == (uint8)Com_u8F_M_NEW_DIFF_M_OLD)
#endif                        
                        ;
   /* PRQA S 3757 -- */
  /* init values are multiple arrays based on the signal type the correct array
  shall be chosen first*/

  switch (u8SigType)
  {
    case Com_u8SIGNAL_TYPE_BOOLEAN:                              
    pkvidData = pkvidInitSigObjnOldValB(
                             u8SigStructType,
                             u16SigInitValIx,
                             u16SigObjIx
#if  Com_u16NO_OF_MASK_OLD_F_B > 0u
                             ,u16SpecificFilterIndex,
                             bInitOldValFilter
#endif
							 );        
    break;

    case Com_u8SIGNAL_TYPE_UINT8:
    pkvidData = pkvidInitSigObjnOldValU8(
                             u8SigStructType,
                             u16SigInitValIx,
                             u16SigObjIx
#if Com_u16NO_OF_MASK_OLD_F_U8> 0u
                             ,u16SpecificFilterIndex,
                             bInitOldValFilter
#endif							 
							 ) ;        
    
    break;

    case Com_u8SIGNAL_TYPE_SINT8:
    pkvidData = pkvidInitSigObjnOldValS8(
                             u8SigStructType,
                             u16SigInitValIx,
                             u16SigObjIx
#if Com_u16NO_OF_MASK_OLD_F_S8 > 0u
                             ,u16SpecificFilterIndex,
                             bInitOldValFilter
#endif
							 ) ;        
    
    break;

    case Com_u8SIGNAL_TYPE_UINT16:
    pkvidData = pkvidInitSigObjnOldValU16(
                             u8SigStructType,
                             u16SigInitValIx,
                             u16SigObjIx
#if Com_u16NO_OF_MASK_OLD_F_U16 > 0u
                             ,u16SpecificFilterIndex,
                             bInitOldValFilter
#endif
							 ) ;        
    
    break;

    case Com_u8SIGNAL_TYPE_SINT16:
    pkvidData = pkvidInitSigObjnOldValS16(
                             u8SigStructType,
                             u16SigInitValIx,
                             u16SigObjIx
#if Com_u16NO_OF_MASK_OLD_F_S16 > 0u
                             ,u16SpecificFilterIndex,
                             bInitOldValFilter
#endif
							 ) ;        
    
    break;

    case Com_u8SIGNAL_TYPE_UINT32:
    pkvidData = pkvidInitSigObjnOldValU32(
                             u8SigStructType,
                             u16SigInitValIx,
                             u16SigObjIx
#if Com_u16NO_OF_MASK_OLD_F_U32 > 0u
                             ,u16SpecificFilterIndex,
                             bInitOldValFilter
#endif				 
							 ) ;        
    
    break;

    case Com_u8SIGNAL_TYPE_SINT32:
    pkvidData = pkvidInitSigObjnOldValS32(
                             u8SigStructType,
                             u16SigInitValIx,
                             u16SigObjIx
#if Com_u16NO_OF_MASK_OLD_F_S32 > 0u
                             ,u16SpecificFilterIndex,
                             bInitOldValFilter
#endif
							 ) ;        
    
    break;
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON)
    case Com_u8SIGNAL_TYPE_FLOAT32:
    pkvidData = pkvidInitSigObjF32(
                             u8SigStructType,
                             u16SigInitValIx,
                             u16SigObjIx) ;        
    
    break;

    case Com_u8SIGNAL_TYPE_FLOAT64:
    pkvidData = pkvidInitSigObjF64(
                             u8SigStructType,
                             u16SigInitValIx,
                             u16SigObjIx) ;        
    
    break;
#endif

    case Com_u8SIGNAL_TYPE_UINT8N:
    pkvidData = pkvidInitSigObjU8N(
                             u8SigStructType,
                             u16SigInitValIx,
                             u16SigObjIx,
                             u16SigByteLen) ;        
    
    break;
#if (Com_bDATA_TP_SUPPORT == STD_ON)
    case Com_u8SIGNAL_TYPE_UINT8DYN:
    pkvidData = pkvidInitSigObjU8Dyn(
                             u8SigStructType,
                             u16SigInitValIx,
                             u16SigObjIx,
                             u16SigByteLen) ;        
    
    break;
#endif

    default:
    break;

  }
  return pkvidData;
}
/*PRQA S 3205 -- */
/* PRQA S 4700 -- */
#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
static FUNC(void,COM_CODE) vidInitSigGrpParam (
                           VAR(uint16,AUTOMATIC)  u16SigGrpID ,
                           VAR(boolean,AUTOMATIC) bBulkInit   ,
                           VAR(boolean,AUTOMATIC) bPackSig,
						   VAR(uint8,AUTOMATIC)   u8IpduDirection) 
{     
  VAR(uint16_least,AUTOMATIC)                       u16SigLoopIx;
  VAR(uint16, AUTOMATIC)							u16GroupSigIdx;
  VAR(uint16, AUTOMATIC)							u16NoOfGroupSig;
#if (Com_bUBIT_SUPPORT== STD_ON)
  VAR(uint16, AUTOMATIC)							u16UpdBitPos;
#endif
    
#if (Com_bTO_SUPPORT == STD_ON)
  P2VAR(uint32,AUTOMATIC,AUTOMATIC)    pu32TOT;
  P2CONST(uint16, AUTOMATIC,AUTOMATIC) pku16TOTimerIdx;
  VAR(uint32, AUTOMATIC) 			   u32FrstTmeout;
  VAR(uint32, AUTOMATIC) 			   u32To;
 #endif
  /* !Deviation: [8018]  (The name of the constant (const) does not respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */
  P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,COM_CALIB_CONST) pkstrLocSigGrpPB;
/*PRQA S 8018 , 8318, 8518  -- */    
    
  pkstrLocSigGrpPB = pkstrGET_PB_SIGGRP_PTR(u16SigGrpID);

  u16GroupSigIdx = pkstrLocSigGrpPB->u16GroupSignalIndex;
  u16NoOfGroupSig = pkstrLocSigGrpPB->u16NoOfGroupSignals;
  u32FrstTmeout = pkstrLocSigGrpPB->u32FirstTimeout;

  for(u16SigLoopIx = u16GroupSigIdx ;  u16SigLoopIx < ( u16NoOfGroupSig +
                   u16GroupSigIdx ) ;  u16SigLoopIx ++ )
  {
    vidInitSigParam(u16SigLoopIx,
#if Com_u16NO_OF_ONE_EVERY_N_F > 0u		
		bBulkInit,
#endif
		bPackSig,
		Com_u8SIG_STRUCT_GROUPSIG,
		u8IpduDirection);
  }
  /*initialize the shadow buffer by copying the object data containing 
  the init values to the shadow buffer*/
  Com_vidCopySigObj2Shadow(u16SigGrpID);

  #if (Com_bUBIT_SUPPORT== STD_ON)
	u16UpdBitPos =pkstrLocSigGrpPB->u16UpdateBitPosition;
  #endif
  /*Initialize time out of signal group*/
#if ((Com_bTO_SUPPORT == STD_ON) && (Com_bUBIT_SUPPORT== STD_ON))
  u32To = pkstrLocSigGrpPB->u32Timeout;
  if ((u32To != 0xFFFFFFFFUL) 
	#if (Com_bUBIT_SUPPORT== STD_ON)
		&& (u16UpdBitPos != (uint16)0xFFFFu)
	#endif 
	  )
  {
	pu32TOT = pkstrGET_PB_TIMEOUT_TIMER();
	pku16TOTimerIdx = &(pkstrLocSigGrpPB->u16TOTimerIndex);
	
	if (u32FrstTmeout != 0xFFFFFFFFUL)
    {
      /*N.B Fisrt Timeout is a LT parameter while the Timeout is a PB one*/
      SchM_Enter_Com_TimeoutTimer();
      pu32TOT[*pku16TOTimerIdx] = u32FrstTmeout;
      SchM_Exit_Com_TimeoutTimer();
    }
    else
    {
      SchM_Enter_Com_TimeoutTimer();
      pu32TOT[*pku16TOTimerIdx] = u32To;
      SchM_Exit_Com_TimeoutTimer();
    }
  }
#endif
  
#if (Com_bUBIT_SUPPORT== STD_ON)
  /* clear update bit of signal group */
	if (u8IpduDirection == Com_u8DIRECTION_TX )
    {
	  if (u16UpdBitPos != (uint16)0xFFFFu)
	  {
		Com_vidSignalEditUpdateBit(Com_u8SIGNALGROUP,u16SigGrpID,u16UpdBitPos,FALSE);          
	  }
	  else
	  {
	  /*no UB configured , do nothing */
	  }  
	}
#endif

}
#endif
/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
/* !Deviation: [3206]  ( Some of the input parameters are not used 
in this function depending on the configuration.) */
/*PRQA S 3206 ++ */
static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjnOldValB(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx
#if  Com_u16NO_OF_MASK_OLD_F_B > 0u
                             ,VAR(uint16,AUTOMATIC)  u16SpecificFilterIndex,
                             VAR(boolean,AUTOMATIC) bInitOldValFilter
#endif
							 ) 
/*PRQA S 3206 -- */
{
/* !Deviation: [8018]  (The name of the constant (const) does not respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */
  P2CONST(void,AUTOMATIC,COM_CALIB_CONST)     pkvidData;
/*PRQA S 8018 , 8318, 8518  -- */  
  pkvidData = (P2CONST(void,AUTOMATIC,COM_CALIB_CONST) ) NULL_PTR;
  if((u8SigStructType == (uint8) Com_u8SIGNAL)||(u8SigStructType == (uint8) Com_u8SIG_STRUCT_GROUPSIG) 
#if (Com_bGW_DESC_SUPPORT == STD_ON)  
   || (u8SigStructType == (uint8) Com_u8GW_STRUCT_DST_DESC)
#endif  
   )
  {

  /*fill a local vid pointer with the address of the corresponding init value
  , this pointer will be sent to pack signal function later*/
    pkvidData =(P2CONST(void,AUTOMATIC,COM_CALIB_CONST)) pkbGET_SIGINIT_VALUEB(u16SigInitValIx);
    
  /*fill the signal object with the corresponding Init value*/
  /*no need to protect the shared variable since it is a boolean type*/
    
	(*(pkB_GET_SIG_OBJ_VALUEB(u16SigObjIx))) =
    * (P2CONST(boolean,AUTOMATIC,COM_CALIB_CONST)) pkvidData ;
  /*fill the old_value if this signal contribute to a filter*/
  /*Indexed by ComMaskOldValFilterU8Array.OldValueIndex*/

  #if  Com_u16NO_OF_MASK_OLD_F_B > 0u
    if(bInitOldValFilter == TRUE)
    {
      Com_abeFilterOldValueB[Com_akstreMaskOldFilterB[
      u16SpecificFilterIndex].u16OldValueIndex] =
      *(P2CONST(boolean,AUTOMATIC,COM_CALIB_CONST)) pkvidData ;
    }
  #endif
  }
#if (Com_bGW_DESC_SUPPORT == STD_ON) 
  else if(u8SigStructType == (uint8) Com_u8GW_STRUCT_SRC_DESC)
  {
    (*pkB_GET_SIG_OBJ_VALUEB(u16SigObjIx)) = (boolean)FALSE ;
    pkvidData = pkB_GET_SIG_OBJ_VALUEB(u16SigObjIx);
  }
#endif
  else
  {
  /*shall not enter here*/
  }
  return pkvidData ;
}
/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
/* !Deviation: [3206]  ( Some of the input parameters are not used 
in this function depending on the configuration.) */
/*PRQA S 3206 ++ */
static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjnOldValU8(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx
#if Com_u16NO_OF_MASK_OLD_F_U8> 0u
							 ,VAR(uint16,AUTOMATIC) u16SpecificFilterIndex,
                             VAR(boolean,AUTOMATIC) bInitOldValFilter
#endif
							 )
/*PRQA S 3206 -- */
{
/* !Deviation: [8018]  (The name of the constant (const) does not respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */
  P2CONST(void,AUTOMATIC,COM_CALIB_CONST)     pkvidData;
/*PRQA S 8018 , 8318, 8518  -- */
  pkvidData = (P2CONST(void,AUTOMATIC,COM_CALIB_CONST) ) NULL_PTR;    
  if((u8SigStructType == (uint8) Com_u8SIG_STRUCT_SIG)||(u8SigStructType == (uint8)Com_u8SIG_STRUCT_GROUPSIG) 
#if (Com_bGW_DESC_SUPPORT == STD_ON)   
  ||(u8SigStructType == (uint8)Com_u8GW_STRUCT_DST_DESC)
#endif
   )
  {

    pkvidData =
      (P2CONST(void,AUTOMATIC,COM_CALIB_CONST)) pku8GET_SIGINIT_VALU8U8N(u16SigInitValIx);
    (*(pku8GET_SIG_OBJ_VALUEU8(u16SigObjIx))) =
    (*(P2CONST(uint8,AUTOMATIC,COM_CALIB_CONST))(pkvidData));
    /*fill the old_value if this signal contribute to a filter*/
    /*Indexed by ComMaskOldValFilterU8Array.OldValueIndex*/
    #if Com_u16NO_OF_MASK_OLD_F_U8> 0u
    if(bInitOldValFilter == TRUE)
    {
      Com_au8eFilterOldValueU8[Com_akstreMaskOldFilterU8[
      u16SpecificFilterIndex].u16OldValueIndex] =
      * (P2CONST(uint8,AUTOMATIC,COM_CALIB_CONST)) pkvidData ;
    }
    #endif
  }
 
#if (Com_bGW_DESC_SUPPORT == STD_ON) 
  else if(u8SigStructType == (uint8)Com_u8GW_STRUCT_SRC_DESC)
  {
    (*pku8GET_SIG_OBJ_VALUEU8(u16SigObjIx)) = (uint8)0;
    pkvidData = pku8GET_SIG_OBJ_VALUEU8(u16SigObjIx);
  }
#endif
  else
  {
    /*shall not enter here*/
  }
  return pkvidData ;
}
/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
/* !Deviation: [3206]  ( Some of the input parameters are not used 
in this function depending on the configuration.) */
/*PRQA S 3206 ++ */
static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjnOldValS8(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx
#if Com_u16NO_OF_MASK_OLD_F_S8 > 0u
                             ,VAR(uint16,AUTOMATIC)  u16SpecificFilterIndex,
                             VAR(boolean,AUTOMATIC) bInitOldValFilter
#endif
							 ) 
/*PRQA S 3206 -- */							 
{
/* !Deviation: [8018]  (The name of the constant (const) does not respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */    
  P2CONST(void,AUTOMATIC,COM_CALIB_CONST)     pkvidData;
/*PRQA S 8018 , 8318, 8518  -- */      
  pkvidData = (P2CONST(void,AUTOMATIC,COM_CALIB_CONST) ) NULL_PTR;    
  if((u8SigStructType == (uint8)Com_u8SIG_STRUCT_SIG)||(u8SigStructType == (uint8)Com_u8SIG_STRUCT_GROUPSIG) 
#if (Com_bGW_DESC_SUPPORT == STD_ON)   
  || (u8SigStructType == (uint8)Com_u8GW_STRUCT_DST_DESC)
#endif 
  )
  {

    pkvidData =
    (P2CONST(void,AUTOMATIC,COM_CALIB_CONST)) pks8GET_SIGINIT_VALUES8(u16SigInitValIx);
    (*(pks8GET_SIG_OBJ_VALUES8(u16SigObjIx))) =
    * (P2CONST(sint8,AUTOMATIC,COM_CALIB_CONST)) pkvidData ;
    /*fill the old_value if this signal contribute to a filter*/
    /*Indexed by ComMaskOldValFilterU8Array.OldValueIndex*/
    #if Com_u16NO_OF_MASK_OLD_F_S8 > 0u
    if(bInitOldValFilter == TRUE)
    {

      Com_as8eFilterOldValueS8[Com_akstreMaskOldFilterS8[
      u16SpecificFilterIndex].u16OldValueIndex] =
      * (P2CONST(sint8,AUTOMATIC,COM_CALIB_CONST)) pkvidData ;
    }
    #endif
  }
#if (Com_bGW_DESC_SUPPORT == STD_ON) 
  else if(u8SigStructType == (uint8)Com_u8GW_STRUCT_SRC_DESC)
  {
    (*pks8GET_SIG_OBJ_VALUES8(u16SigObjIx))  = (sint8)0;
    pkvidData = pks8GET_SIG_OBJ_VALUES8(u16SigObjIx);
  }
#endif
  else
  {
    /*shall not enter here*/
  }
  return pkvidData ;
}
/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
/* !Deviation: [3206]  ( Some of the input parameters are not used 
in this function depending on the configuration.) */
/*PRQA S 3206 ++ */
static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjnOldValU16(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx
#if Com_u16NO_OF_MASK_OLD_F_U16 > 0u
                             ,VAR(uint16,AUTOMATIC)  u16SpecificFilterIndex,
                             VAR(boolean,AUTOMATIC) bInitOldValFilter 
#endif
																		)
/*PRQA S 3206 -- */							 
{
/* !Deviation: [8018]  (The name of the constant (const) does not respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */     
  P2CONST(void,AUTOMATIC,COM_CALIB_CONST)     pkvidData;
  
  P2VAR(uint16,AUTOMATIC,TYPEDEF) pu16SigObjU16;
/*PRQA S 8018 , 8318, 8518  -- */    
  pkvidData = (P2CONST(void,AUTOMATIC,COM_CALIB_CONST) ) NULL_PTR; 
  pu16SigObjU16 = (pku16GET_SIG_OBJ_VALUEU16(u16SigObjIx));
  if((u8SigStructType == (uint8) Com_u8SIG_STRUCT_SIG)||(u8SigStructType == (uint8)Com_u8SIG_STRUCT_GROUPSIG) 
 #if (Com_bGW_DESC_SUPPORT == STD_ON)  
  || (u8SigStructType == (uint8)Com_u8GW_STRUCT_DST_DESC)
 #endif 
  )
  {

    pkvidData =
    (P2CONST(void,AUTOMATIC,COM_CALIB_CONST)) pku16GET_SIGINIT_VALUEU16(u16SigInitValIx);
    SchM_Enter_Com_SigObjU16();
    (*pu16SigObjU16) = * (P2CONST(uint16,AUTOMATIC,COM_CALIB_CONST)) pkvidData ;
    SchM_Exit_Com_SigObjU16();
    /*fill the old_value if this signal contribute to a filter*/
    /*Indexed by ComMaskOldValFilterU8Array.OldValueIndex*/
    #if Com_u16NO_OF_MASK_OLD_F_U16 > 0u
    if (bInitOldValFilter == TRUE)
    {

      Com_au16eFilterOldValueU16[Com_akstreMaskOldFilterU16[
      u16SpecificFilterIndex].u16OldValueIndex] =
      * (P2CONST(uint16,AUTOMATIC,COM_CALIB_CONST))pkvidData ;
    }
    #endif
  }
 #if (Com_bGW_DESC_SUPPORT == STD_ON) 
  else if(u8SigStructType == (uint8) Com_u8GW_STRUCT_SRC_DESC)
  {
    SchM_Enter_Com_SigObjU16();
    (*pu16SigObjU16) = (uint16)0;
    SchM_Exit_Com_SigObjU16();    
    pkvidData = pu16SigObjU16;
  }
 #endif
  else
  {
    /*shall not enter here*/
  }
  return pkvidData ;    
}
/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
/* !Deviation: [3206]  ( Some of the input parameters are not used 
in this function depending on the configuration.) */
/*PRQA S 3206 ++ */
static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjnOldValS16(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx
#if Com_u16NO_OF_MASK_OLD_F_S16 > 0u
                             ,VAR(uint16,AUTOMATIC)  u16SpecificFilterIndex,
                             VAR(boolean,AUTOMATIC) bInitOldValFilter
#endif							 
							 ) 
/*PRQA S 3206 -- */
{
/* !Deviation: [8018]  (The name of the constant (const) does not respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */   
  P2CONST(void,AUTOMATIC,COM_CALIB_CONST)     pkvidData;
  
  P2VAR(sint16,AUTOMATIC,TYPEDEF)ps16SigObjS16;
  ps16SigObjS16 = pks16GET_SIG_OBJ_VALUES16(u16SigObjIx);
/*PRQA S 8018 , 8318, 8518  -- */     
  pkvidData = (P2CONST(void,AUTOMATIC,COM_CALIB_CONST) ) NULL_PTR;        
  if((u8SigStructType == (uint8) Com_u8SIG_STRUCT_SIG)||(u8SigStructType == (uint8) Com_u8SIG_STRUCT_GROUPSIG) 
#if (Com_bGW_DESC_SUPPORT == STD_ON)   
  ||(u8SigStructType == (uint8) Com_u8GW_STRUCT_DST_DESC)
#endif 
  )
  {
    pkvidData =
    (P2CONST(void,AUTOMATIC,COM_CALIB_CONST)) pks16GET_SIGINIT_VALUES16(u16SigInitValIx);

    SchM_Enter_Com_SigObjS16();
    (*ps16SigObjS16) = *(P2CONST(sint16,AUTOMATIC,COM_CALIB_CONST)) pkvidData ;
    SchM_Exit_Com_SigObjS16();
    /*fill the old_value if this signal contribute to a filter*/
    /*Indexed by ComMaskOldValFilterU8Array.OldValueIndex*/
    #if Com_u16NO_OF_MASK_OLD_F_S16 > 0u
    if (bInitOldValFilter == TRUE)
    {

      Com_as16eFilterOldValueS16[Com_akstreMaskOldFilterS16[
      u16SpecificFilterIndex].u16OldValueIndex] =
      * (P2CONST(sint16,AUTOMATIC,COM_CALIB_CONST)) pkvidData ;
    }
    #endif
  }
#if (Com_bGW_DESC_SUPPORT == STD_ON) 
  else if(u8SigStructType == (uint8) Com_u8GW_STRUCT_SRC_DESC)
  {
    SchM_Enter_Com_SigObjS16();    
    (*ps16SigObjS16) = (sint16)0;
    SchM_Exit_Com_SigObjS16();    
    pkvidData = ps16SigObjS16;
  }
#endif
  else
  {
    /*shall not enter here*/
  }
  return pkvidData ;    
}
/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
/* !Deviation: [3206]  ( Some of the input parameters are not used 
in this function depending on the configuration.) */
/*PRQA S 3206 ++ */
static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjnOldValU32(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx
#if Com_u16NO_OF_MASK_OLD_F_U32 > 0u
                             ,VAR(uint16,AUTOMATIC)  u16SpecificFilterIndex,
                             VAR(boolean,AUTOMATIC) bInitOldValFilter
#endif							 
							 ) 
/*PRQA S 3206 --*/							 
{
/* !Deviation: [8018]  (The name of the constant (const) does not respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */     
  P2CONST(void,AUTOMATIC,COM_CALIB_CONST)     pkvidData;
  P2VAR(uint32,AUTOMATIC,TYPEDEF)pu32SigObjU32;
  pu32SigObjU32 = pku32GET_SIG_OBJ_VALUEU32(u16SigObjIx);
/*PRQA S 8018 , 8318, 8518  -- */     
  pkvidData = (P2CONST(void,AUTOMATIC,COM_CALIB_CONST) ) NULL_PTR;        
  if((u8SigStructType == (uint8) Com_u8SIG_STRUCT_SIG)|| 
  (u8SigStructType == (uint8)Com_u8SIG_STRUCT_GROUPSIG) 
 #if (Com_bGW_DESC_SUPPORT == STD_ON)  
  ||(u8SigStructType == (uint8) Com_u8GW_STRUCT_DST_DESC)
 #endif 
  )
  {

    pkvidData =
    (P2CONST(void,AUTOMATIC,COM_CALIB_CONST)) pku32GET_SIGINIT_VALUEU32(u16SigInitValIx);
    SchM_Enter_Com_SigObjU32();
    (*pu32SigObjU32) = * (P2CONST(uint32,AUTOMATIC,COM_CALIB_CONST)) pkvidData ;
    SchM_Exit_Com_SigObjU32();
    /*fill the old_value if this signal contribute to a filter*/
    /*Indexed by ComMaskOldValFilterU8Array.OldValueIndex*/
    #if Com_u16NO_OF_MASK_OLD_F_U32 > 0u
    if (bInitOldValFilter == TRUE)
    {

      Com_au32eFilterOldValueU32[Com_akstreMaskOldFilterU32[
      u16SpecificFilterIndex].u16OldValueIndex] =
      * (P2CONST(uint32,AUTOMATIC,COM_CALIB_CONST)) pkvidData ;
    }
    #endif
  }
#if (Com_bGW_DESC_SUPPORT == STD_ON) 
  else if(u8SigStructType == (uint8) Com_u8GW_STRUCT_SRC_DESC)
  {
    SchM_Enter_Com_SigObjU32();    
    (*pu32SigObjU32) = (uint32)0;
    SchM_Exit_Com_SigObjU32();    
    pkvidData = pu32SigObjU32;
  }
#endif
  else
  {
    /*shall not enter here*/
  }
  return pkvidData ;    
}
/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
/* !Deviation: [3206]  ( Some of the input parameters are not used 
in this function depending on the configuration.) */
/*PRQA S 3206 ++ */
static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjnOldValS32(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx
#if Com_u16NO_OF_MASK_OLD_F_S32 > 0u
                             ,VAR(uint16,AUTOMATIC)  u16SpecificFilterIndex,
                             VAR(boolean,AUTOMATIC) bInitOldValFilter
#endif
							 ) 
/*PRQA S 3206 -- */
{
/* !Deviation: [8018]  (The name of the constant (const) does not respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */    
  P2CONST(void,AUTOMATIC,COM_CALIB_CONST)     pkvidData;
  P2VAR(sint32,AUTOMATIC,TYPEDEF)ps32SigObjS32;
  ps32SigObjS32 = pks32GET_SIG_OBJ_VALUES32(u16SigObjIx);
/*PRQA S 8018 , 8318, 8518  -- */     
  pkvidData = (P2CONST(void,AUTOMATIC,COM_CALIB_CONST) ) NULL_PTR;        
  if((u8SigStructType == (uint8)Com_u8SIG_STRUCT_SIG)||
  (u8SigStructType == (uint8)Com_u8SIG_STRUCT_GROUPSIG) 
 #if (Com_bGW_DESC_SUPPORT == STD_ON)  
  ||(u8SigStructType == (uint8)Com_u8GW_STRUCT_DST_DESC)
 #endif 
  )
  {

    pkvidData =
    (P2CONST(void,AUTOMATIC,COM_CALIB_CONST)) pks32GET_SIGINIT_VALUES32(u16SigInitValIx);
    SchM_Enter_Com_SigObjS32();
    (*ps32SigObjS32) = *(P2CONST(sint32,AUTOMATIC,COM_CALIB_CONST))pkvidData ;
    SchM_Exit_Com_SigObjS32();
    /*fill the old_value if this signal contribute to a filter*/
    /*Indexed by ComMaskOldValFilterU8Array.OldValueIndex*/
    #if Com_u16NO_OF_MASK_OLD_F_S32 > 0u
    if (bInitOldValFilter == TRUE)
    {

      Com_as32eFilterOldValueS32[Com_akstreMaskOldFilterS32[
      u16SpecificFilterIndex].u16OldValueIndex] =
      * (P2CONST(sint32,AUTOMATIC,COM_CALIB_CONST)) pkvidData ;
    }
    #endif
  }
#if (Com_bGW_DESC_SUPPORT == STD_ON) 
  else if(u8SigStructType == (uint8) Com_u8GW_STRUCT_SRC_DESC)
  {
    SchM_Enter_Com_SigObjS32();    
    (*ps32SigObjS32) = (sint32)0;
    SchM_Exit_Com_SigObjS32();    
    pkvidData = ps32SigObjS32;
  }
#endif

  else
  {
    /*shall not enter here*/
  }
  return pkvidData ;    
}



#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON) 
/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjF32(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx) 
{
/* !Deviation: [8018]  (The name of the constant (const) does not respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */     
  P2CONST(void,AUTOMATIC,COM_CALIB_CONST)     pkvidData;

  P2VAR(float32,AUTOMATIC,TYPEDEF)pf32SigObjF32;
  pf32SigObjF32 = pkf32GET_SIG_OBJ_VALUEF32(u16SigObjIx);
/*PRQA S 8018 , 8318, 8518  -- */     
  pkvidData = (P2CONST(void,AUTOMATIC,COM_CALIB_CONST) ) NULL_PTR;        
  if((u8SigStructType == (uint8)Com_u8SIG_STRUCT_SIG)||
  (u8SigStructType == (uint8)Com_u8SIG_STRUCT_GROUPSIG) 
#if (Com_bGW_DESC_SUPPORT == STD_ON) 
  ||(u8SigStructType == (uint8)Com_u8GW_STRUCT_DST_DESC)
#endif
 )
  {

    pkvidData =
    (P2CONST(void,AUTOMATIC,COM_CALIB_CONST)) pkf32GET_SIGINIT_VALUEF32(u16SigInitValIx);
    SchM_Enter_Com_SigObjF32();
    (*pf32SigObjF32) = * (P2CONST(float32,AUTOMATIC,COM_CALIB_CONST)) pkvidData ;
    SchM_Exit_Com_SigObjF32();
  }
#if (Com_bGW_DESC_SUPPORT == STD_ON) 
  else if(u8SigStructType == (uint8)Com_u8GW_STRUCT_SRC_DESC)
  {
    SchM_Enter_Com_SigObjF32();    
    (*pf32SigObjF32) = (float32)0;
    SchM_Exit_Com_SigObjF32();    
    pkvidData = pf32SigObjF32;
  }
#endif
  else
  {
    /*shall not enter here*/
  }
  return pkvidData ;    
}
/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjF64(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx) 
{
/* !Deviation: [8018]  (The name of the constant (const) does not respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */    
  P2CONST(void,AUTOMATIC,COM_CALIB_CONST)     pkvidData;
  
  P2VAR(float64,AUTOMATIC,TYPEDEF)pf64SigObjF64;
  pf64SigObjF64 = pkf64GET_SIG_OBJ_VALUEF64(u16SigObjIx);
/*PRQA S 8018 , 8318, 8518  -- */     
  pkvidData = (P2CONST(void,AUTOMATIC,COM_CALIB_CONST) ) NULL_PTR;        
  if((u8SigStructType == (uint8)Com_u8SIG_STRUCT_SIG)||
  (u8SigStructType == (uint8)Com_u8SIG_STRUCT_GROUPSIG) 
#if (Com_bGW_DESC_SUPPORT == STD_ON)  
  || (u8SigStructType == (uint8)Com_u8GW_STRUCT_DST_DESC)
#endif  
 )
  {
    pkvidData =
    (P2CONST(void,AUTOMATIC,COM_CALIB_CONST)) pkf64GET_SIGINIT_VALUEF64(u16SigInitValIx);
    SchM_Enter_Com_SigObjF64();
    (*pf64SigObjF64) = *(P2CONST(float64,AUTOMATIC,COM_CALIB_CONST))pkvidData ;
    SchM_Exit_Com_SigObjF64();
  }
#if (Com_bGW_DESC_SUPPORT == STD_ON)
  else if(u8SigStructType == (uint8) Com_u8GW_STRUCT_SRC_DESC)
  {
    SchM_Enter_Com_SigObjF64();    
    (*pf64SigObjF64) = (float64)0;
    SchM_Exit_Com_SigObjF64();    
    pkvidData = pf64SigObjF64;
  }
#endif
  else
  {
    /*shall not enter here*/
  }
  return pkvidData ;    
}
#endif

/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjU8N(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx ,
                             VAR(uint16,AUTOMATIC)  u16SigByteLen ) 
{
  VAR(uint16_least,AUTOMATIC)                       u16LoopIx;
/* !Deviation: [8018]  (The name of the constant (const) does not respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */    
  P2CONST(void,AUTOMATIC,COM_CALIB_CONST)     pkvidData;
  P2VAR(uint8,AUTOMATIC,TYPEDEF) pu8SigObjU8U8N;
/*PRQA S 8018 , 8318, 8518 -- */ 
  pkvidData = (P2CONST(void,AUTOMATIC,COM_CALIB_CONST) )NULL_PTR;  
  pu8SigObjU8U8N = pku8GET_SIG_OBJ_VALUEU8(0);
  if((u8SigStructType == (uint8)Com_u8SIG_STRUCT_SIG)||(u8SigStructType == (uint8)Com_u8SIG_STRUCT_GROUPSIG) 
#if (Com_bGW_DESC_SUPPORT == STD_ON)   
  ||(u8SigStructType == (uint8)Com_u8GW_STRUCT_DST_DESC)
#endif  
  )
  {

    pkvidData =
      (P2CONST(void,AUTOMATIC,COM_CALIB_CONST)) pku8GET_SIGINIT_VALU8U8N(u16SigInitValIx);
    SchM_Enter_Com_SigObjU8U8N();      
    for (u16LoopIx = 0 ; u16LoopIx < u16SigByteLen ; u16LoopIx++)
    {
      pu8SigObjU8U8N[(u16SigObjIx + u16LoopIx)] =
      ( (P2CONST(uint8,AUTOMATIC,COM_CALIB_CONST)) pkvidData )[u16LoopIx];
    }
    SchM_Exit_Com_SigObjU8U8N();
            /*Signals with type UINT8N only support filter of always or never */
  }
  
#if (Com_bGW_DESC_SUPPORT == STD_ON) 
  else if(u8SigStructType == (uint8)Com_u8GW_STRUCT_SRC_DESC)
  {
    SchM_Enter_Com_SigObjU8U8N();
    for (u16LoopIx = 0 ; u16LoopIx < u16SigByteLen ; u16LoopIx++)
    {
      pu8SigObjU8U8N[(u16SigObjIx + u16LoopIx )] = (uint8)0;
    }
    SchM_Exit_Com_SigObjU8U8N();
    pkvidData = &(pu8SigObjU8U8N[u16SigObjIx ]);      

  }
#endif
  else
  {
    /*shall not enter here*/
  }
  return pkvidData ;    
}


#if (Com_bDATA_TP_SUPPORT == STD_ON) 
/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
static FUNC(Com_tpkvidConstCalibPtr,COM_CODE) pkvidInitSigObjU8Dyn(
                             VAR(uint8,AUTOMATIC)   u8SigStructType,
                             VAR(uint16,AUTOMATIC)  u16SigInitValIx,
                             VAR(uint16,AUTOMATIC)  u16SigObjIx ,
                             VAR(uint16,AUTOMATIC)  u16SigByteLen ) 
{
  VAR(uint16_least,AUTOMATIC)                       u16LoopIx;
/* !Deviation: [8018]  (The name of the constant (const) does not respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */
  P2CONST(void,AUTOMATIC,COM_CALIB_CONST)     pkvidData;
  P2VAR(uint8,AUTOMATIC,TYPEDEF) pu8SigObjU8U8N;

/*PRQA S 8018 , 8318, 8518  -- */
  pkvidData = (P2CONST(void,AUTOMATIC,COM_CALIB_CONST) )NULL_PTR;

    pu8SigObjU8U8N = pku8GET_SIG_OBJ_VALUEU8(0);
    /*writing the max dynamic length of the signal, it is saved on the first 2 bytes
    of the corresponding signal object */
    /*loading the high byte into the first array byte at the correspending
    index*/
  SchM_Enter_Com_SigObjU8U8N();    
  pu8SigObjU8U8N[u16SigObjIx ] =
  (uint8)(((uint16)(u16SigByteLen & (uint16)0xFF00u)) >> (uint16)8u);
  pu8SigObjU8U8N[u16SigObjIx +(uint16)1] = (uint8)(u16SigByteLen & (uint16)0x00FF);
  SchM_Exit_Com_SigObjU8U8N();

  if(u8SigStructType == (uint8)Com_u8SIG_STRUCT_SIG)
  {

    pkvidData =
    (P2CONST(void,AUTOMATIC,COM_CALIB_CONST)) pku8GET_SIGINIT_VALU8U8N(u16SigInitValIx);

    SchM_Enter_Com_SigObjU8U8N();
    for (u16LoopIx = 0 ; u16LoopIx < u16SigByteLen ; u16LoopIx++)
    {
      pu8SigObjU8U8N[(u16SigObjIx + Com_u8U8DYN_OBJ_IX_OFFSET +u16LoopIx)] =
      ( (P2CONST(uint8,AUTOMATIC,COM_CALIB_CONST)) pkvidData)[u16LoopIx];
    }
    SchM_Exit_Com_SigObjU8U8N();      
  }
  else
  {
  /*shall not enter here*/
  }
  return pkvidData ;
}

#endif

/* !Deviation: [4700]  ( here has been an infringement of a threshold on the
specified metric)
The vidInitConfRamArrays function deviate the Cyclomatic complexity and the Estimated Static
Program Paths  due the requirement of initializing all RAM variables , so a
large number of checks is required , these checks  are plan enough  also grouping
the initialization of RX Ipdu and TX Ipdu in COM_vidInitRxIpdu , and
COM_vidInitTxIpdu   respectively so no other meaningfull division is required*/
/* PRQA S 4700 ++ */
/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
static FUNC(void,COM_CODE) vidInitConfRamArrays (void)
{
  VAR(uint16_least,AUTOMATIC)    u16LoopIndex;
  P2CONST(uint8,AUTOMATIC,TYPEDEF) pku8SigInitFltrRslt;
#if (Com_bDATA_TP_SUPPORT == STD_ON)
  P2VAR(uint16,AUTOMATIC,AUTOMATIC) pu16TpBCntr;
#endif
  VAR(boolean,AUTOMATIC)    bInitFilterReslt;
  /*clearing the Com_IpduGroupVector bits , which will leads to stop inter ECU
  Communications*/
    /*Calculate the size of the Com_IpduGroupVector in bytes
  * Each IPDU Group is represented by one bit in ComSupportedIPduGroups ,
  * to convert to Byte , divide by 8.
  * to ensure the ceiling add 1.
  * a problem could arise with ceiling if the ComSupportedIPduGroups was divisible by 8 ,
  * so substract 1 from the ComSupportedIPduGroups before converting it to bytes
  * size = [(ComSupportedIPduGroups-1)/8+1] ,
  */

  /* !Deviation: [2465]  the loop could only be executed once ,leading to a QAC error , only if
      if the configured   COM_SUPPORTED_IPDU_GROUPS was less than 9  */
/* PRQA S 2465 ++ */
  #if (COM_SUPPORTED_IPDU_GROUPS > 0U)
  for (u16LoopIndex = 0 ;
       u16LoopIndex <= (uint16)((COM_SUPPORTED_IPDU_GROUPS - 1u) >> 3) ;
       u16LoopIndex ++ )
  {
    Com_au8eIPduGroupVector[u16LoopIndex] = (uint8)0x00u ;
	#if (Com_bTO_SUPPORT == STD_ON) 
	Com_au8eRxDMIPduGroupVector[u16LoopIndex] = (uint8)0x00u;
	#endif
  }
  #endif
	
	
  #if (u16NO_OF_IPDUS_STATUS > 0U)
  /*Initialize Com_u8D_MDT_MASK, Com_u8WAIT_CONF, Com_u8ACTIVE_MASK, Com_u8DEF_PROC_MASK to FALSE
	and set Com_u8CTR_ACC_ANY to TRUE*/
	for (u16LoopIndex = 0 ;
       u16LoopIndex <= (uint16)(u16NO_OF_IPDUS_STATUS - 1u) ;
       u16LoopIndex ++ )
    {
      Com_audteIPduStatus[u16LoopIndex] = (Com_udtIPduStatus) (((Com_udtIPduStatus)0x00u) | Com_u8CTR_ACC_ANY)
								#if (Com_bTMS_SUPPORT == STD_ON)
										|((udtGET_PB_INIT_IPDUSTATUS(u16LoopIndex) & Com_u8INIT_TX_MO_FLG))
								#endif		
										;
    }
  #endif
  
/* PRQA S 2465 -- */

  /*COM_Init shall initialize All RAM variables (internal data) with suitable values as following : */
  /*first bulk mode initialization , i.e filling the whole arrays with the same value*/
  /*  ComIPduCounterRamArray with zeros*/
 #if Com_u16NO_OF_IPDU_COUNTER > 0u
  for (u16LoopIndex = 0 ;
      u16LoopIndex < (uint16)Com_u16NO_OF_IPDU_COUNTER;
      u16LoopIndex++)
  {
    Com_au8eIPduCounterRam[u16LoopIndex] = 0x00u ;
  }
 #endif
  /*ComOneEveryNFilterCountersArray set the occurance to zeros*/
  #if Com_u16NO_OF_ONE_EVERY_N_F > 0u
  for (u16LoopIndex = 0 ;
       u16LoopIndex <= Com_u16ONEEVERYNFCTRMAXIX ;
       u16LoopIndex++)
  {
    Com_au32eOneEveryNFilterCtr[u16LoopIndex] = 0;
  }
  #endif

  /*ComCurrentTxModeFalgsArray with ComInitialTxModeFalgsArray (value calculated
  statically by   the configuration tool based on the signal initial values)*/

  
  /*Com_init shall copy the ComSignalInitFilterResultArray to
  ComSignalLastFilterResultArray
  (value calculated statically by the configuration tool based on the signal
  initial values)*/
    /*reset the Ipdu byte counter index for Tp Idpus*/
#if (Com_bDATA_TP_SUPPORT == STD_ON)
   #if ((Com_bPTR_NULL_CHECK == STD_ON) && (Com_bPB_VARIANT == STD_ON))   
  if (Com_pkstreMainConfig->pu16TpByteCounter !=
                             (P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))NULL_PTR)
  { 
  #endif
	pu16TpBCntr = pkstrGET_TP_IPDU_CTR_PTR(0);
    for(u16LoopIndex = 0 ; u16LoopIndex <= pu16GET_TP_BYTECNTR_MXIX();
    u16LoopIndex++)
    {    
      pu16TpBCntr[u16LoopIndex] = (uint16)0;
    }
   #if (Com_bPTR_NULL_CHECK == STD_ON && Com_bPB_VARIANT == STD_ON)
  }
  #endif
#endif
  
  
  /*Com_init shall copy the ComSignalInitFilterResultArray to
  ComSignalLastFilterResultArray
  (value calculated statically by the configuration tool based on the signal
  initial values)*/
  /*initialize all Com_audteSignalStatus array flags including GW falgs, Copy Init_Filter Result into Last Filter Result*/
  
#if (Com_bTMS_SUPPORT == STD_ON)  

  #if ((Com_bPTR_NULL_CHECK == STD_ON) && (Com_bPB_VARIANT == STD_ON))  
	if (Com_pkstreMainConfig->pku8SigInitFilterResult !=
                                 (P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))NULL_PTR)
	{
  #endif
	 pku8SigInitFltrRslt = pku8GET_SIG_INT_FLTR_VAL(0);
#endif
     for (u16LoopIndex = 0 ; u16LoopIndex < Com_u16NO_OF_SIGNAL_STATUS; u16LoopIndex++)
	 {
#if (Com_bTMS_SUPPORT == STD_ON)  
	  bInitFilterReslt = Com_bGETBITOPT(pku8SigInitFltrRslt, u16LoopIndex);
#endif
	  
	  #if Com_u16NO_OF_SIGNAL_STATUS > 0u
      Com_audteSignalStatus[u16LoopIndex] = (uint8)0x00u 
	  #endif
	  #if (Com_bTMS_SUPPORT == STD_ON) 
	  | ((bInitFilterReslt) << 1)| ((bInitFilterReslt) << 3) /*added this part for TMS optimization processing*/
	  #endif
	  ;
     }
#if (Com_bTMS_SUPPORT == STD_ON)  	
    #if (Com_bPTR_NULL_CHECK == STD_ON && Com_bPB_VARIANT == STD_ON) 
	}
	#endif
#endif

}
/* PRQA S 4700 -- */
/* !Deviation: [4700]  ( here has been an infringement of a threshold on the
specified metric)
The vidInitTxModeParam function deviate the Cyclomatic complexity and the Estimated Static
Program Paths , no other meaningfull division is required*/
/* PRQA S 4700 ++ */
/*************************************************************************/
/*! \Description: Global function to initialize the Com               \n

**************************************************************************/
#if Com_u16NO_OF_TX_IPDU > 0
static FUNC(void,COM_CODE) vidInitTxModeParam(
                           VAR(uint16,AUTOMATIC) u16PduId )
{
  VAR(uint16,AUTOMATIC)                             u16LocIndex;   
/* !Deviation: [8018]  (The name of the constant (const) does not respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */  
  P2CONST(Com_tstrTxMode,AUTOMATIC,COM_CALIB_CONST) pkstrLocTxMode;
  P2CONST(Com_tstrTxIPdu,AUTOMATIC,COM_CALIB_CONST) pkstrLocTXIpduPB; 

  P2VAR(Com_tu32TxModeTimer,AUTOMATIC,TYPEDEF) pu32TxModeTimerPtr;
#if (Com_bNTIMES_SUPPORT == STD_ON)
  P2CONST(Com_tstrTxModeDirect,AUTOMATIC,TYPEDEF) pkstrTxModeDirectPtr;
#endif
  
 #if (Com_bMDT_SUPPORT == STD_ON) 
  P2VAR(Com_tu32MDTimer,AUTOMATIC,TYPEDEF) pu32MDTimerPtr;
  P2CONST(uint16, AUTOMATIC,AUTOMATIC) pku16MDTimerIdx;
 #endif
  P2CONST(Com_tstrTxModeMixed,AUTOMATIC,TYPEDEF)    pkstrTxModeMixedPtr;
  P2CONST(Com_tstrTxModePeriodic,AUTOMATIC,TYPEDEF) pkstrTxModePeriodicPtr;
  P2VAR(uint8,AUTOMATIC,TYPEDEF) 					pu8TxModeReceptionCtr;
/*PRQA S 8018 , 8318, 8518  -- */ 
  /*
  - reset ComTxModeRepetitionsCounter , with the corresponding configured value
  get the current tx mode for the ipdu from the ComCurrentTxModeFalgsArray to
  know if tx mode = true or false  then according to the above value select the
  COMTxModeTrueIndex or the COMTxModeTrue from the TXIPDU to index the
  COMTxModeArray , to know the TX ModeMode if = Direct or mixed , and get the
  related index  use the above index to select the suitable COMTXDiectArray or
  COMTxMixedArray. get the number or repition and the repition index
  index the comTxmode repition array
  also:
  - ComTxModeTimer of I-PDUs in Periodic or MIXED transmission mode with the
  corresponding IPDU configured   TIME OFFSET value, if configured, else with
  the normal periodic timer value
  */
  /*could be removed in optimization according to their placement */
  pkstrLocTXIpduPB = pkstrGET_TX_IPDU_PTR(u16PduId);  
#if((Com_bTMS_SUPPORT == STD_ON) && (Com_u16NO_OF_SIGNAL_STATUS > 0u)) 
    SchM_Enter_Com_IPduStatus_03();
  if(((Com_audteIPduStatus[u16PduId] & Com_u8CURR_TX_MO_FLG) != FALSE))
  /* current TXMode = TRUE*/
  {
    SchM_Exit_Com_IPduStatus_03();
#endif
	pkstrLocTxMode = pkstrGET_TX_MODE(pkstrLocTXIpduPB->u16TxModeTrueIndex);
#if((Com_bTMS_SUPPORT == STD_ON) && (Com_u16NO_OF_SIGNAL_STATUS > 0u)) 
  }
  else
  {
  /*current mode = False*/
    SchM_Exit_Com_IPduStatus_03();
    pkstrLocTxMode = pkstrGET_TX_MODE(pkstrLocTXIpduPB->u16TxModeFalseIndex);
  }
#endif 
  /*Now u16Index hold the index of a specific the TX mode (direct, mixed or
  periodic) */
  u16LocIndex = pkstrLocTxMode->u16Index;

  pu32TxModeTimerPtr = pku32GET_TX_MODE_TIMR(0);
  pu8TxModeReceptionCtr = pku8GET_REPEATATION_CTR(0);
  
#if (Com_bMDT_SUPPORT == STD_ON) 
  pu32MDTimerPtr = pku32GET_MD_TIMER(0);
  pku16MDTimerIdx = &(pkstrLocTXIpduPB->u16MDTimerIndex);
#endif
  switch (pkstrLocTxMode->u8TxMode)
  {
    /*TX Mode = Direct*/
    case Com_u8TX_MODE_DIRECT:
#if (Com_bNTIMES_SUPPORT == STD_ON)
    pkstrTxModeDirectPtr = pkstrGET_TX_MODE_DIR(u16LocIndex);
	#if ((Com_bPTR_NULL_CHECK == STD_ON) && (Com_bPB_VARIANT == STD_ON))	
    if (Com_pkstreMainConfig->pu8TxModeRepetitionsCtr !=
    (P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))NULL_PTR)
    {
	#endif
      pu8TxModeReceptionCtr[pkstrTxModeDirectPtr->u16RepetitionsCtrIndex] =(uint8)0u;
      /*initialize the corresponding Com_au32TxModeTimer with the configured
      value*/
      SchM_Enter_Com_TxModeTimer();
      pu32TxModeTimerPtr[pkstrTxModeDirectPtr->u16RepetitionPrdTmrIx]  = (uint32)0;
      SchM_Exit_Com_TxModeTimer();
   #if ((Com_bPTR_NULL_CHECK == STD_ON) && (Com_bPB_VARIANT == STD_ON))  
    }
	#endif
#endif
    /*- ComMinimumDelayTime of I-PDUs in transmission mode DIRECT or MIXED ,
    for the TX IPDUs ,
    with the corresponding configured value*/
#if(Com_bMDT_SUPPORT == STD_ON)
	if ((*pku16MDTimerIdx) != (uint16)0xFFFFu)
    {
      SchM_Enter_Com_MDT();
      pu32MDTimerPtr[*pku16MDTimerIdx] = (uint32)0;
      SchM_Exit_Com_MDT();
    }
#endif
    break;
    /*TX Mode = Mixed*/
    case Com_u8TX_MODE_MIXED:
    pkstrTxModeMixedPtr = pkstrGET_TX_MODE_MIXED(u16LocIndex);
#if (Com_bNTIMES_SUPPORT == STD_ON)
	#if ((Com_bPTR_NULL_CHECK == STD_ON) && (Com_bPB_VARIANT == STD_ON))  
    if (Com_pkstreMainConfig->pu8TxModeRepetitionsCtr !=
    (P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))NULL_PTR)
    {
	#endif
      pu8TxModeReceptionCtr[pkstrTxModeMixedPtr->u16RepetitionsCtrIndex] = (uint8)0u;
      SchM_Enter_Com_TxModeTimer();
      /*initialize the corresponding Com_au32TxModeTimer with the configured
             value*/
      pu32TxModeTimerPtr[pkstrTxModeMixedPtr->u16RepetitionPrdTmrIx]  =(uint32) 0 ;
      SchM_Exit_Com_TxModeTimer();
	#if ((Com_bPTR_NULL_CHECK == STD_ON) && (Com_bPB_VARIANT == STD_ON))  
    }
	#endif
#endif
    if (pkstrTxModeMixedPtr->u32TimeOffset != 0)
    {
      SchM_Enter_Com_TxModeTimer();      
      pu32TxModeTimerPtr[pkstrTxModeMixedPtr->u16TimerIndex]=
      pkstrTxModeMixedPtr->u32TimeOffset - (uint32)1;
      SchM_Exit_Com_TxModeTimer();      
    }
    else
    /*No offset is configured*/
    {
      SchM_Enter_Com_TxModeTimer();       
      pu32TxModeTimerPtr[pkstrTxModeMixedPtr->u16TimerIndex]=
      pkstrTxModeMixedPtr->u32TimePeriod - (uint32)1;
      SchM_Exit_Com_TxModeTimer();
    }

    /*- ComMinimumDelayTime of I-PDUs in transmission mode DIRECT or MIXED ,for
         the TX IPDUs , with the corresponding configured value*/
#if(Com_bMDT_SUPPORT == STD_ON)
	if ((*pku16MDTimerIdx) != (uint16)0xFFFFu)
    {
      SchM_Enter_Com_MDT();
      pu32MDTimerPtr[*pku16MDTimerIdx] =
      (uint32)0;
      SchM_Exit_Com_MDT();
    }
#endif
    break;
    /*TX Mode = Periodic*/
    case Com_u8TX_MODE_PERIODIC:
    pkstrTxModePeriodicPtr = pkstrGET_TX_MODE_PERIODIC(u16LocIndex);
    if (pkstrTxModePeriodicPtr->u32TimeOffset != 0)
    {
      SchM_Enter_Com_TxModeTimer();      
      pu32TxModeTimerPtr[pkstrTxModePeriodicPtr->u16TimerIndex]=
      pkstrTxModePeriodicPtr->u32TimeOffset -
      (uint32)1;
      SchM_Exit_Com_TxModeTimer();      
    }
    else
    /*No offset is configured*/
    {
      SchM_Enter_Com_TxModeTimer();    
     pu32TxModeTimerPtr[pkstrTxModePeriodicPtr->u16TimerIndex]=
      pkstrTxModePeriodicPtr->u32TimePeriod - (uint32)1;
      SchM_Exit_Com_TxModeTimer();
    }
#if(Com_bMDT_SUPPORT == STD_ON)
	if ((*pku16MDTimerIdx) != (uint16)0xFFFFu)
    {
      SchM_Enter_Com_MDT();
      pu32MDTimerPtr[*pku16MDTimerIdx] =
      (uint32)0;
      SchM_Exit_Com_MDT();
    }
#endif
    break;
    default:
    /*TX mode = NONE*/
    break;
  }

}
#endif
/* PRQA S 4700 -- */
/*PRQA S 0790 -- */
/* !Deviation: [8019]  ( The name of " symbolic constants " (#define)
Identifiers does not respect the naming conventions.) */
/*[8519](The Type of " symbolic constants " (#define) Identifiers does not 
respect the naming conventions.)*/
/*this #define is imposed by the AUTOSAR MemMap file , required for memory
 abstraction*/
/*PRQA S 8019 , 8519 ++ */
/* PRQA S 5087 L1 */
#define COM_STOP_SEC_CODE
/*PRQA S 8019 , 8519-- */
#include "MemMap.h"
/* PRQA L:L1 */
/** \} */ /* end of Com module group */

/* PRQA S 0850 --                                                             */
