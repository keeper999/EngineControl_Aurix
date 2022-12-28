/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : Com                                                     */
/* !Description     : AUTOSAR Communication Module                            */
/*                                                                            */
/* !Module          : Com_SignalIpduServices                                  */
/* !Description     : Module providing some services for the COM , e.g packing*/
/*                    and unpacking the signal into the ipdu buffer , sign    */
/*                    extension and filtering algorithms                      */
/*                                                                            */
/* !File            : Com_SignalIpduServices.c                                */
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
/* $Revision::   1.150     $$Author::   ametwelly      $$Date::   Aug 24 2014$*/
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
/* !Deviation : This translation unit makes use of floating types. */
/*Support of floating point variable is mandated by AUTOSAR */
/*PRQA S 0790 ++ */
#include "Com.h"
#include "Com_Internal.h"
#include "Com_Cfg.h"
#include "Com_LCfg.h"
#include "SchM_Com.h"
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

#endif /* #if (COM_bINTER_MOD_VER_CHECK == STD_ON) */

/******************************************************************************/

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/* !Comment : Maximum Temp Buffer size to be used in the pack and unpack      */
/*            function                                                        */
#define u8MAX_TEMP_BUFF_SIZE              8u


/******************************************************************************/
/*                       Macro Definitions                                    */
/******************************************************************************/

/* !Deviation: [3453]  the following functions like macros , helps to increase
the readability of the code ,by accessing the required configuration parameter ,
 through a macro . Macros were used instead of functions in order to increase
  the code performance  by reducing the time required by the context switching*/
/* PRQA S 3453 ++ */
/*Macro to get a pointer of a specific TX Ipdu Identified by a certain Ipdu ID*/
#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_TX_IPDU_PTR(u16PduId) \
(&(Com_pkstreMainConfig->pkstrTxIPdu[(Com_pkstreMainConfig->pkstrIPduLookUp[\
(u16PduId)].u16Index)]))
#else

#define pkstrGET_TX_IPDU_PTR(u16PduId) \
(&(akstrTxIPdu[(akstrIPduLookUp[\
(u16PduId)].u16Index)]))
#endif

/*Macro to get a pointer of a specific RX Ipdu Identified by a certain Ipdu ID*/
#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_RX_IPDU_PTR(u16PduId) \
(&(Com_pkstreMainConfig->pkstrRxIPdu[(Com_pkstreMainConfig->pkstrIPduLookUp[\
(u16PduId)].u16Index)]))
#else
#define pkstrGET_RX_IPDU_PTR(u16PduId) \
(&(akstrRxIPdu[(akstrIPduLookUp[\
(u16PduId)].u16Index)]))
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_RX_IPDU_PTR_IX(u16Index) \
		(&(Com_pkstreMainConfig->pkstrRxIPdu[u16Index]))
#else
#define pkstrGET_RX_IPDU_PTR_IX(u16Index) \
	     (&(akstrRxIPdu[u16Index]))
#endif




/*Macro to get a pointer of a specific Signal Identified by a certain signal ID*/
#define pkstrGET_PB_SIGNAL_PTR(u16SigId) \
(&( Com_pkstreMainConfig->pkstrSignalPB[Com_pkstreMainConfig->pkstrSignalLookUp[\
(u16SigId)].u16Index]))

/*Macro to get a specific filter algorithm assigned to a signal specified by a
signal ID*/
#if ((Com_u16NO_OF_SIGNAL > 0u) && (Com_u16NO_OF_FILTER > 0u))
#define u8GET_FILTER_ALGORITHM(u16SigId) \
(Com_akstreFilter[(Com_akstreSignalLT[Com_pkstreMainConfig->pkstrSignalLookUp[(u16SigId)].u16Index].u16FilterIndex)].\
u8FilterAlgorithm)
#else
#define u8GET_FILTER_ALGORITHM(u16SigId)  Com_u8F_NEVER
#endif

/*Macro to get a specific filter index assigned to a signal specified by a
signal ID*/
#if ((Com_u16NO_OF_SIGNAL > 0u) && (Com_u16NO_OF_FILTER > 0u))
#define u16GET_SPECIFIC_FLTR_IX(u16SigFilterIx) \
(Com_akstreFilter[u16SigFilterIx].u16Index)
#else
#define u16GET_SPECIFIC_FLTR_IX(u16SigId) 0x00u
#endif

/*Macro to get the TX Ipdu Ram  buffer index*/
#define u32GET_TX_IPDU_BUFF_IX(u16IpduId) \
(Com_pkstreMainConfig->pkstrTxIPdu[(Com_pkstreMainConfig->pkstrIPduLookUp[\
(u16IpduId)].u16Index)].u32IPduBufferIndex)

/*Macro to get the RX Ipdu Ram  buffer index*/
#define u32GET_RX_IPDU_BUFF_IX(u16IpduId) \
(Com_pkstreMainConfig->pkstrRxIPdu[(Com_pkstreMainConfig->pkstrIPduLookUp[\
(u16IpduId)].u16Index)].u32IPduBufferIndex)

/*Macro to get the RX Ipdu counter size */
#if Com_u16NO_OF_IPDU_COUNTER > 0u
#define u8GET_RX_IPDU_CTR_SIZE(u16IpduId)  \
(Com_akstreIPduCounters[(Com_pkstreMainConfig->pkstrRxIPdu[\
(Com_pkstreMainConfig->pkstrIPduLookUp[(u16IpduId)].u16Index)].\
u16IPduCounterIndex)].u8IPduCounterSize)
#else
#define u8GET_RX_IPDU_CTR_SIZE(u16IpduId) 0x00u
#endif

/*Macro to get the RX Ipdu counter bit position inside the Ipdu */
#if Com_u16NO_OF_IPDU_COUNTER > 0u
#define u16GET_RX_IPDU_CTR_POS(u16IpduId) \
(Com_akstreIPduCounters[(Com_pkstreMainConfig->pkstrRxIPdu[\
(Com_pkstreMainConfig->pkstrIPduLookUp[(u16IpduId)].u16Index)].\
u16IPduCounterIndex )].u16IPduCounterStartPos)
#else
#define u16GET_RX_IPDU_CTR_POS(u16IpduId) 0x00u
#endif

/*Macro to get the RX Ipdu counter threshold value */
#if Com_u16NO_OF_IPDU_COUNTER > 0u
#define u8GET_RX_IPDU_CTR_THR(u16IpduId) \
(Com_akstreIPduCounters[(Com_pkstreMainConfig->pkstrRxIPdu[\
(Com_pkstreMainConfig->pkstrIPduLookUp[(u16IpduId)].u16Index)].\
u16IPduCounterIndex )].u8IPduCounterThreshold)
#else
#define u8GET_RX_IPDU_CTR_THR(u16IpduId) 0x00u
#endif

/*Macro to get the RX Ipdu counter Ram value */
#if Com_u16NO_OF_IPDU_COUNTER > 0u
#define u8EXPECTED_RX_IPDU_CTR(u16IpduId) \
(Com_au8eIPduCounterRam[(Com_pkstreMainConfig->pkstrRxIPdu[\
(Com_pkstreMainConfig->pkstrIPduLookUp[(u16IpduId)].u16Index)].\
u16IPduCounterIndex )])
#else
#define u8EXPECTED_RX_IPDU_CTR(u16IpduId) 0x00u
#endif

/*Macro to get the TX Ipdu counter bit position inside the Ipdu */
#if Com_u16NO_OF_IPDU_COUNTER > 0u
#define u16GET_TX_IPDU_CTR_POS(u16IpduId) \
(Com_akstreIPduCounters[(Com_pkstreMainConfig->pkstrTxIPdu[\
(Com_pkstreMainConfig->pkstrIPduLookUp[(u16IpduId)].u16Index)].\
u16IPduCounterIndex )].u16IPduCounterStartPos)
#else
#define u16GET_TX_IPDU_CTR_POS(u16IpduId) 0x00u
#endif

/*Macro to get the TX Ipdu counter Ram value */
#if Com_u16NO_OF_IPDU_COUNTER > 0u
#define u8EXPECTED_TX_IPDU_CTR(u16IpduId) \
(Com_au8eIPduCounterRam[(Com_pkstreMainConfig->pkstrTxIPdu[\
(Com_pkstreMainConfig->pkstrIPduLookUp[(u16IpduId)].u16Index)].\
u16IPduCounterIndex )])
#else
#define u8EXPECTED_TX_IPDU_CTR(u16IpduId) 0x00u
#endif

/*Macro to get the TX Ipdu counter size */
#if Com_u16NO_OF_IPDU_COUNTER > 0u
#define u8GET_TX_IPDU_CTR_SIZE(u16IpduId) \
(Com_akstreIPduCounters[(Com_pkstreMainConfig->pkstrTxIPdu[\
(Com_pkstreMainConfig->pkstrIPduLookUp[(u16IpduId)].u16Index)].\
u16IPduCounterIndex )].u8IPduCounterSize)
#else
#define u8GET_TX_IPDU_CTR_SIZE(u16IpduId) 0x00u
#endif

/*Macro to get a suitable bit u16Mask according to the bit order*/
#define u8GET_BIT_MASK(u8BitOrder) (0x01u <<(u8BitOrder))

/*Macro to identify if a bit is SET or not*/
#define bIS_BIT_SET(u8Var, u8mask)    (((u8Var) & (u8mask)) != 0)

/*Macro to set a bit in a specific Byte*/
#define vidSET_BIT_MASK(u8Var, u8mask)  ((u8Var) |= (u8mask))

/*Macro to clear a bit in a specific byte*/
#define vidCLR_BIT_MASK(u8Var, u8mask) ((u8Var) &= ((u8mask) ^ (uint8)0xFF))

/*Macro to u16Mask some bit from a specific position and having a certain size*/
#define u8MASK_CERTAIN_BITS(u8StartPos,u8BitNumbers) \
((uint8)(((uint8)0xFFu >> ((uint8)((uint8)8u -(u8BitNumbers))))<<(u8StartPos)))

#if Com_u16NO_OF_IPDU_REPLIC > 0u
#define pu8GET_RX_IPDU_1ST_REP(u16IpduId) \
(&Com_au8eReplicasBuffer[(Com_akstreIPduReplication[(Com_pkstreMainConfig->\
pkstrRxIPdu[(Com_pkstreMainConfig->pkstrIPduLookUp[(u16IpduId)].u16Index)].\
u16IPduReplicationIndex)].u16ReplicasBufferIndex)])
#else
#define pu8GET_RX_IPDU_1ST_REP(u16IpduId) \
	(P2VAR(uint8,AUTOMATIC,TYPEDEF))NULL_PTR
#endif

#if Com_u16NO_OF_IPDU_REPLIC > 0u
#define u8GET_RX_IPDU_NB_REP(u16IpduId) \
(Com_akstreIPduReplication[(Com_pkstreMainConfig->pkstrRxIPdu[\
(Com_pkstreMainConfig->pkstrIPduLookUp[(u16IpduId)].u16Index)].\
u16IPduReplicationIndex)].u8NoOfReplicas)
#else
#define u8GET_RX_IPDU_NB_REP(u16IpduId) 0x00u
#endif

#if Com_u16NO_OF_RXIPDU_CALLOUT > 0u
#define pfGET_RXIPDU_CALOUTPTR(u16IpduId) Com_akpfbeRxIPduCalloutPtrs[\
Com_pkstreMainConfig->pkstrRxIPdu[(Com_pkstreMainConfig->pkstrIPduLookUp[\
(u16IpduId)].u16Index)].u16IPduCalloutIndex]
#else
#define pfGET_RXIPDU_CALOUTPTR(u16IpduId) \
	(P2CONST(Com_tpfbRxIpduCallout,AUTOMATIC,TYPEDEF))NULL_PTR
#endif

#if Com_u16NO_OF_SIGNAL > 0u
#define u16GET_SIG_INVALID_IX(u16SigIx) \
(Com_akstreSignalLT[u16SigIx].u16SigInvalidValIndex)
#else
#define u16GET_SIG_INVALID_IX(u16SigIx) 0x00u
#endif

#if Com_u16NO_OF_SIGNAL > 0u
#define pfSIG_INVALID_CBK(u16SigId) \
(Com_akstreSignalLT[Com_pkstreMainConfig->pkstrSignalLookUp[(u16SigId)].\
u16Index].pfvidInvalidNotification)
#else
#define pfSIG_INVALID_CBK(u16SigId) FALSE
#endif

#if Com_u16NO_OF_SIGNAL > 0u
#define bGET_SIG_INVALID_ACT(u16SigIx) \
((Com_akstreSignalLT[u16SigIx].udteSignalLTFlags & Com_u8SIGLT_DATINVAL_ACT) != FALSE)
#else
#define bGET_SIG_INVALID_ACT(u16SigIx)  Com_u8INVALID_ACT_NOTIFY
#endif

#if Com_u16NO_OF_GROUP_SIGSLT > 0u
#define u16GRPSIG_INVALID_IX(u16SigIx) \
(Com_akstreGroupSignalLT[u16SigIx].u16SigInvalidValIndex)
#else
#define u16GRPSIG_INVALID_IX(u16SigIx) 0x00u
#endif


/*Macro to get a specific filter index assigned to a signal specified by a signal ID*/
#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_FILTER > 0u))
#define u16GRPSIG_SPCFC_FLTR_IX(u16SigFilterIx) \
(Com_akstreFilter[u16SigFilterIx].u16Index)
#else
#define u16GRPSIG_SPCFC_FLTR_IX(u16SigFilterIx) 0x00u
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define u8SIG_STRUCTURE_TYPE(u16SigId) \
Com_pkstreMainConfig->pkstrSignalLookUp[(u16SigId)].u8StructureType
#else
#define u8SIG_STRUCTURE_TYPE(u16SigId) \
			akstrSignalLookUp[(u16SigId)].u8StructureType
#endif


#if Com_u16NO_OF_GROUP_SIGSLT > 0u
#define bSIGGRP_INVALID_ACT(u16SigGroupId) \
((Com_akstreSignalGroupLT[(u16SigGroupId)].udteSignalGroupLTFlags & Com_u8SIGPLT_DATAINVL_ACT) != FALSE)
#else
#define bSIGGRP_INVALID_ACT(u16SigGroupId)  Com_u8INVALID_ACT_NOTIFY
#endif



#if Com_u16NO_OF_GROUP_SIGSLT > 0u
#define pfSIGGRP_INVALID_CBK(u16SigGroupId) \
(Com_akstreSignalGroupLT[(u16SigGroupId)].pfvidInvalidNotification)
#else
#define pfSIGGRP_INVALID_CBK(u16SigId) FALSE
#endif

#if Com_u16NO_OF_GROUP_SIGSLT > 0u
#define u16SIGGRP_ID_FROM_SIGID(u16GrpSigIx) \
(Com_akstreGroupSignalLT[(u16GrpSigIx)].u16SignalGroupId)
#else
#define u16SIGGRP_ID_FROM_SIGID(u16GrpSigIx)  0
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define u16GWSRCIX_OF_IPDUMAP(u16GWSigIndex)  \
Com_pkstreMainConfig->pkstrGWSignalMapping[(u16GWSigIndex)].u16SrcIndex
#else
#if u16NO_OF_GW_PATHS > 0u
#define u16GWSRCIX_OF_IPDUMAP(u16GWSigIndex)  \
akstrGWSignalMapping[(u16GWSigIndex)].u16SrcIndex
#else
#define u16GWSRCIX_OF_IPDUMAP(u16GWSigIndex)  0u
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define u16GWSRCSTYP_OF_IPDUMAP(u16GWSigIndex)  \
Com_pkstreMainConfig->pkstrGWSignalMapping[(u16GWSigIndex)].u8SrcStructType
#else
#if u16NO_OF_GW_PATHS > 0u
#define u16GWSRCSTYP_OF_IPDUMAP(u16GWSigIndex)  \
akstrGWSignalMapping[(u16GWSigIndex)].u8SrcStructType
#else
#define u16GWSRCSTYP_OF_IPDUMAP(u16GWSigIndex)  0u
#endif
#endif


#if ((Com_u16NO_OF_SIGNAL > 0u) && (Com_u16NO_OF_FILTER > 0u))
#define u16DST_SPECIFIC_FLTR_IX(u16SigFilterIx) \
Com_akstreFilter[(u16SigFilterIx)].u16Index
#else
#define u16DST_SPECIFIC_FLTR_IX(u16SigFilterIx) 0u
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_LOOKUP_SIG_PTR(u16SigId) \
		(&(Com_pkstreMainConfig->pkstrSignalLookUp[u16SigId]))
#else
#define pkstrGET_LOOKUP_SIG_PTR(u16SigId) \
	     (&(akstrSignalLookUp[(u16SigId)]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define u16GET_SIG_IX(u16SigId) \
		(Com_pkstreMainConfig->pkstrSignalLookUp[u16SigId].u16Index)
#else
#define u16GET_SIG_IX(u16SigId) \
	     (akstrSignalLookUp[(u16SigId)].u16Index)
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PBSIGPTR_IX(u16SigIx) \
(&(Com_pkstreMainConfig->pkstrSignalPB[u16SigIx]))
#else
#define pkstrGET_PBSIGPTR_IX(u16SigIx) \
(&(akstrSignalPB[u16SigIx]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PBGRPSIGPTR_IX(u16SigIx) \
(&( Com_pkstreMainConfig->pkstrGroupSignalPB[(u16SigIx)]))
#else
#if u16NO_OF_GROUP_SIGNALS > 0u
#define pkstrGET_PBGRPSIGPTR_IX(u16SigIx) \
(&( akstrGroupSignalPB[(u16SigIx)]))
#else
#define pkstrGET_PBGRPSIGPTR_IX(u16SigIx) \
	(P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PBSRC_DESCPTR_IX(u16SigIx) \
(&(Com_pkstreMainConfig->pkstrGWSrcDesc[(u16SigIx)]))
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
#define pkstrGET_IPDU_BUFF_PTR(u16IPduBufferIx) \
(&(Com_pkstreMainConfig->pu8IPduBuffer[(u16IPduBufferIx)]))
#else
#define pkstrGET_IPDU_BUFF_PTR(u16IPduBufferIx) \
(&(Com_au8IPduBuffer[(u16IPduBufferIx)]))
#endif



#if ((Com_u16NO_OF_SIGNAL > 0u) && (Com_u16NO_OF_FILTER > 0u))
#define pkstrGET_FILTER_SPEC_PTR(u16SigFilterIx) \
(&(Com_akstreFilter[(u16SigFilterIx)]))
#else
#define pkstrGET_FILTER_SPEC_PTR(u16SigFilterIx)  \
	(P2CONST(Com_tstrFilter,AUTOMATIC,TYPEDEF)) NULL_PTR
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PBDSTDESCPTR_IX(u16SigIx) \
(&(Com_pkstreMainConfig->pkstrGWDstDesc[(u16SigIx)]))
#else
#if u16NO_OF_GW_DST_DESC > 0u
#define pkstrGET_PBDSTDESCPTR_IX(u16SigId) \
(&(akstrGWDstDesc[(u16SigIx)]))
#else
#define pkstrGET_PBDSTDESCPTR_IX(u16SigId) \
	(P2CONST(Com_tstrGWDstDesc,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define pku32GETONE_EVERY_NPERIOD(u32FilterPeriod) \
(&(Com_pkstreMainConfig->pku32OneEveryNFPeriod[(u32FilterPeriod)]))
#else
#if u16NO_OF_ONE_EVERY_N > 0u
#define pku32GETONE_EVERY_NPERIOD(u32FilterPeriod) \
(&(aku32OneEveryNPeriod[(u32FilterPeriod)]))
#else
#define pku32GETONE_EVERY_NPERIOD(u32FilterPeriod) \
	(P2CONST(uint32,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define bGET_IPDU_DIRECTION(u16IPduId) \
(Com_pkstreMainConfig->pkstrIPduLookUp[(u16IPduId)].u8Direction)
#else
#define bGET_IPDU_DIRECTION(u16IPduId) \
(akstrIPduLookUp[(u16IPduId)].u8Direction)
#endif


#if Com_u16NO_OF_IPDU_COUNTER > 0u
#define pkstrGET_IPDU_CTR_PTR(u16IpduCtrIx) \
(&(Com_akstreIPduCounters[(u16IpduCtrIx)]))
#else
#define pkstrGET_IPDU_CTR_PTR(u16IpduCtrIx) \
	(P2CONST(Com_tpfbRxIpduCallout,AUTOMATIC,TYPEDEF))NULL_PTR
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


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PB_TIMEOUT_TIMER() \
(Com_pkstreMainConfig->pu32TimeOutTimer)
#else
#if u16NO_OF_TIMEOUT > 0u
#define pkstrGET_PB_TIMEOUT_TIMER() \
(&(Com_au32TimeOutTimer[0]))
#else
#define pkstrGET_PB_TIMEOUT_TIMER() \
	(P2VAR(uint32,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PB_SIGNAL_GROUP(u16SigGroIx) \
(&(Com_pkstreMainConfig->pkstrSignalGroupPB[u16SigGroIx]))
#else
#if u16NO_OF_SIGNAL_GROUPS > 0u
#define pkstrGET_PB_SIGNAL_GROUP(u16SigGroIx) \
(&(akstrSignalGroupPB[u16SigGroIx]))
#else
#define pkstrGET_PB_SIGNAL_GROUP(u16SigGroIx) \
		(P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif


/* PRQA S 3453 -- */


/******************************************************************************/


typedef struct 
{
   VAR(uint8,AUTOMATIC)                                  u8SignalBufferLen;
   /*hold the Byte Number of the signal inside the IPDU buffer */
   VAR(uint16,AUTOMATIC)                                 u16StartByteNum;
   /*hold the starting bit position of the signal in a specific Ipdu Buffer
   Byte*/
   VAR(uint8,AUTOMATIC)                                  u8StartBitPos; 
   /*hold the remaining signal length */
   /*range 0..64 for normal data types , not for dynmaic nor uint8N types*/
   VAR(uint8,AUTOMATIC)                                  u8RemSigBits;
   /*hold the sign extension value for signals , 0s for unsigned , 1s for
   signed*/
   VAR(uint8,AUTOMATIC)                                  u8SignBitFiller; 
   VAR(uint8 , AUTOMATIC)                                u8SigEndianess;
   VAR(uint8, AUTOMATIC)                                 u8CurrBitSize;   
   VAR(uint16, AUTOMATIC)                                u16CurrBitPosition;
   VAR(uint16, AUTOMATIC)                                u16SigObjIndex;
   VAR(uint16, AUTOMATIC)                                u16SigIx;
   VAR(uint16, AUTOMATIC)                                u16SigInvalidIx;
   VAR(uint8, AUTOMATIC)                                 u8SigContainer;
   VAR(uint8, AUTOMATIC)                                 u8SigType;
   P2VAR(void,AUTOMATIC,COM_APPL_DATA)                   pvidSigObj;
} tstrUnpackSigProp ; 

/******************************************************************************/
/*                       Static functions Declration                        */
/******************************************************************************/
/* !Deviation: [8019]  ( The name of " symbolic constants " (#define)
Identifiers doesn't respect the naming conventions.) */
/*[8519](The Type of " symbolic constants " (#define) Identifiers doesn't
 respect the naming conventions.)*/
/*this #define is imposed by the AUTOSAR MemMap file , required for memory
 abstraction*/
/*PRQA S 8019 , 8519 ++ */
/* PRQA S  5087 L1 */
#define COM_START_SEC_CODE
/*PRQA S 8019 , 8519 -- */
#include "MemMap.h"
/* PRQA L:L1 */
static FUNC(boolean,COM_CODE) bEvalWithinFilterAlg (
                       VAR(Com_SignalIdType,AUTOMATIC) u16SigIx,
#if (Com_u16NO_OF_LIMITS_F_U8 | Com_u16NO_OF_LIMITS_F_S8 | Com_u16NO_OF_LIMITS_F_U16 | Com_u16NO_OF_LIMITS_F_S16 | Com_u16NO_OF_LIMITS_F_U32 | Com_u16NO_OF_LIMITS_F_S32) > 0u
                       P2CONST(void,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pkvidSigDataPtr,
#endif					 
					   VAR(uint8,AUTOMATIC)            u8SigStrcture
					   );


static FUNC(boolean,COM_CODE) bEvalMaskNewEqFltrAlg (
                       VAR(Com_SignalIdType,AUTOMATIC) u16SigIx,
#if (Com_u16NO_OF_MASK_F_B | Com_u16NO_OF_LIMITS_F_U8 | Com_u16NO_OF_LIMITS_F_S8 | Com_u16NO_OF_LIMITS_F_U16 | Com_u16NO_OF_LIMITS_F_S16 | Com_u16NO_OF_LIMITS_F_U32 | Com_u16NO_OF_LIMITS_F_S32) > 0
                       P2CONST(void,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pkvidSigDataPtr,
#endif
                       VAR(uint8,AUTOMATIC)            u8SigStrcture
					   );


static FUNC(boolean,COM_CODE) bEvalMskNewOldFltrAlg (
                       VAR(Com_SignalIdType,AUTOMATIC) u16SigIx,
#if Com_u16NO_OF_MASK_OLD_F_B || Com_u16NO_OF_MASK_OLD_F_U8 || Com_u16NO_OF_MASK_OLD_F_S8 || Com_u16NO_OF_MASK_OLD_F_U16 || Com_u16NO_OF_MASK_OLD_F_S16 || Com_u16NO_OF_MASK_OLD_F_U32 || Com_u16NO_OF_MASK_OLD_F_S32 > 0u
                       P2CONST(void,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pkvidSigDataPtr,
#endif
                       VAR(uint8,AUTOMATIC)            u8SigStrcture
					   ) ;
#if (Com_bDATA_INVALID_SUPPORT == STD_ON)  
static FUNC(boolean,COM_CODE) bCheckSigIsValid (
                       VAR(uint16,AUTOMATIC)       u16SigInvalidIx,
#if Com_u16SIG_INV_V_B_SIZE || Com_u16SIG_INV_V_U8U8N_SIZE || Com_u16SIG_INV_V_S8_SIZE || Com_u16SIG_INV_V_U16_SIZE || Com_u16SIG_INV_V_S16_SIZE || Com_u8SIGNAL_TYPE_UINT32 || Com_u8SIGNAL_TYPE_SINT32 || Com_u16SIG_INV_V_F32_SIZE || Com_u16SIG_INV_V_F64_SIZE > 0u
                       P2CONST(void,AUTOMATIC,COM_APPL_DATA) pkvidSigTempVal,
#endif
                       VAR(uint8,AUTOMATIC)    u8SigType
					   );
#endif
#if (Com_bDATA_INVALID_SUPPORT == STD_ON)
static FUNC(uint8,COM_CODE) u8ProcessInvalidSig(
                         Com_SignalIdType u16SigIx,
						 VAR(Com_tu8SignalContainerType,AUTOMATIC)  u8SigContainer) ;

#endif

static FUNC(uint8 , COM_CODE) bIsSignalNegative (
           VAR(uint8,AUTOMATIC)                         u8Endianess,
           VAR(uint8,AUTOMATIC)                         u8SigLength ,
           VAR(uint16,AUTOMATIC)                        u16SigBitPos,
           P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)       pku8IpduData);
           
static FUNC(uint8,COM_CODE) u8UnPackArraySignal(
            VAR(uint8,AUTOMATIC)  u8SigType,
            VAR(uint16,AUTOMATIC) u16SigObjIx,            
            VAR(uint16,AUTOMATIC) u16SigLen,
            VAR(uint16,AUTOMATIC) u16StartBytePos, 
            VAR(uint16,AUTOMATIC) u16DynSigMaxLen,            
            P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)pku8IpduFirstByte ); 	   
			
static FUNC(uint8,COM_CODE) u8ExtSigAppFilter8Bit(
			P2CONST(tstrUnpackSigProp , AUTOMATIC , COM_APPL_DATA) pkstrLocUnpackSigProp,
			P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pkstrPduInfoPtr,
			P2VAR(uint8,AUTOMATIC,TYPEDEF)						 pu8SigExtBuff);

static FUNC(void,COM_CODE) vidExtSig2TempBuff8bit(
            P2CONST(tstrUnpackSigProp , AUTOMATIC , COM_APPL_DATA) pkstrLocUnpackSigProp,
            P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pkstrPduInfoPtr,
			P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) pu8TempBigEndianBuff);

#if ((Com_bDATA_INVALID_SUPPORT == STD_ON) || (Com_u8FILTERING_DIR == Com_u8DIRECTION_RX ))
static FUNC(uint8,COM_CODE) u8ChkSigInvApplyFilter(			
			P2CONST(tstrUnpackSigProp , AUTOMATIC , COM_APPL_DATA)	   pkstrLocUnpackSigProp,
			P2CONST(void,AUTOMATIC,COM_APPL_DATA) pkvidTempBuff);
#endif
			
static FUNC(uint8,COM_CODE) u8ExtSigAppFilter16Bit(
			P2CONST(tstrUnpackSigProp , AUTOMATIC , COM_APPL_DATA) pkstrLocUnpackSigProp,
			P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pkstrPduInfoPtr,
			P2VAR(uint16,AUTOMATIC,COM_APPL_DATA) 		pu16BigEndianBuff);

static FUNC(void,COM_CODE) vidExtSig2TempBuff16bit(
            P2CONST(tstrUnpackSigProp , AUTOMATIC , COM_APPL_DATA) pkstrLocUnpackSigProp,
            P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pkstrPduInfoPtr,
			P2VAR(uint16,AUTOMATIC,COM_APPL_DATA) pu16TempBigEndianBuff);
			
static FUNC(void,COM_CODE) vidExtSigAppFilter32Bit(
			P2CONST(tstrUnpackSigProp , AUTOMATIC , COM_APPL_DATA) pkstrLocUnpackSigProp,
			P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pkstrPduInfoPtr,
			P2VAR(uint32,AUTOMATIC,COM_APPL_DATA) 		pu32BigEndianBuff);

static FUNC(void,COM_CODE) vidExtSig2TempBuff32bit(
            P2CONST(tstrUnpackSigProp , AUTOMATIC , COM_APPL_DATA) pkstrLocUnpackSigProp,
            P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pkstrPduInfoPtr,
			P2VAR(uint32,AUTOMATIC,COM_APPL_DATA) pu32TempBigEndianBuff);
			
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON)
static FUNC(Std_ReturnType,COM_CODE) udtFilterInvChkCpu64Bit(
				P2CONST(tstrUnpackSigProp , AUTOMATIC , COM_APPL_DATA) 	 pkstrLocUnpackSigProp,
				P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pkstrPduInfoPtr,
				P2CONST(float64,AUTOMATIC,TYPEDEF)						 pkf64DataBuff);
 
#endif

static FUNC(Std_ReturnType,COM_CODE) udtFilterInvChkCpu32Bit(
			 P2CONST(tstrUnpackSigProp , AUTOMATIC , COM_APPL_DATA) 	 pkstrLocUnpackSigProp,
			 P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)pkstrPduInfoPtr,
			 P2CONST(uint32,AUTOMATIC,TYPEDEF)						 pku32DataBuff);
 
			
/* !Deviation: [4700]  ( here has been an infringement of a threshold on the
specified metric)
The Com_SignalUnPackSignal function deviate the complexity threshold, but no
more division/simplification can be done
for performance issues*/
/* PRQA S 4700 ++ */
/*
This service unpacks signal/group signal identified by u16SignalId from the
Ipdu data,performs endianess conversion and sign extension ,if exist, then
pack it into signal/group signal object.
This service is used at the receiver side only.
*/
 /*! \Trace_To : Com-CDD-SignalIpduServices-0263(0) ,
 Com-CDD-SignalIpduServices-0264(0) , Com-CDD-SignalIpduServices-0265(0) ,
  Com-CDD-SignalIpduServices-0266(0) , Com-CDD-SignalIpduServices-0267(0) , 
  Com-CDD-0437(0) , Com-CDD-SignalIpduServices-5741(0),
 Com-CDD-0438(0) , Com-CDD-0439(0) , 
 Com-CDD-0441(0) ,Com-CDD-0440(0) ,
Com-CDD-0442(0) , Com-CDD-0443(0),
Com-CDD-SignalIpduServices-0261(0) */
/* !Deviation: [3205]  ( Some of the varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S 3205, 3202, 3199, 3203 ++ */
FUNC(uint8,COM_CODE)Com_u8SignalUnPackSignal(
  VAR(Com_SignalIdType,AUTOMATIC)u16SignalId,
  P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)pkstrPduInfoPtr)
{
   /*local variables declaration */
/* !Deviation: [8018]  (The name of the constant (const) doesn't respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */
   P2CONST(Com_tstrSignalPB,AUTOMATIC,COM_CALIB_CONST)   pkstrLocSigPB;
/*PRQA S 8018 , 8318, 8518  -- */

   /*a temporary buffer that will hold the signal value in a pre-defined
   format (BIG ENDIAN) where the Most Significant Byte will occupy the Highest
   byte (lowest address) of the array and the Least Significant Byte will occupy
   the higger byte address as the following example but having 8 byte instead of
    4:
   arr[0]|Most  Most |
   arr[1]|Most  Least|
   arr[2]|Least Most |
   arr[3]|Least Least|
    */
   /*local pointer to uint8 will hold the address of the byte to be filled
   inside the signal object array*/
   P2VAR(void,AUTOMATIC,COM_APPL_DATA)                  pvidSignalObject;
   /*return of the function , E_OK in case the signal updated the signla object
    , else E_NOT_OK*/
   VAR(Std_ReturnType,AUTOMATIC)                         u8UnpackReturn;

   /*different temp signals , which will contains the unpacked received signal
   value used for  checking against invalidity and filtering before updating the
    signal object */
   VAR(uint8,AUTOMATIC)                                  u8SigU8TempUnpacked;
   VAR(uint16,AUTOMATIC)                                 u16SigU16TempUnpacked;
   VAR(uint32,AUTOMATIC)                                 au32SigU32TempUnpacked[2];
   P2VAR(uint8,AUTOMATIC,TYPEDEF)						 pu8BigEndianBuff;
   P2VAR(uint16,AUTOMATIC,TYPEDEF)						 pu16BigEndianBuff;
   P2VAR(uint32,AUTOMATIC,TYPEDEF)						 pu32BigEndianBuff;
   P2VAR(uint32,AUTOMATIC,TYPEDEF)						 pu32BigEndianBuffTemp;
   P2VAR(float64,AUTOMATIC,TYPEDEF)						 pf64BigEndianBuffTemp;
   

   VAR(uint16 , AUTOMATIC)                               u16SigObjIx;

   VAR(uint8, AUTOMATIC)             u8SigStructType;
   
   VAR(uint16,AUTOMATIC)             u16ArrSigByteLength;
   VAR(uint16,AUTOMATIC)             u16SigIxLoc;
#if (Com_bDATA_TP_SUPPORT == STD_ON)    
   VAR(uint16,AUTOMATIC)             u16DynSigLen;
   VAR(uint16,AUTOMATIC)             u16TpIpduLen;
   VAR(uint32,AUTOMATIC)             u32IpduLastByteIx;
#if(Com_u16NO_OF_SIGNAL > 0u)
   P2VAR(uint8,AUTOMATIC,TYPEDEF)	 pu8IPduBuf;
#endif
/*PRQA S 8018 , 8318, 8518  ++ */
   P2CONST(Com_tstrRxIPdu,AUTOMATIC,COM_CALIB_CONST) 	   pkstrLocRXIpduPB; 
 /*PRQA S 8018 , 8318, 8518  -- */
#endif
   VAR(tstrUnpackSigProp,AUTOMATIC ) strLocUnpackSigProp ;

#if (Com_bDATA_TP_SUPPORT == STD_ON)	
   VAR(uint16,AUTOMATIC)             u16PduId;
#endif 
/*PRQA S 8018 , 8318, 8518  ++ */
   P2CONST(Com_tstrSignalLookUp,AUTOMATIC,COM_CALIB_CONST)   pkstrSigLookUp;
/*PRQA S 8018 , 8318, 8518  -- */

/* !Deviation: [8018]  (The name of the constant (const) doesn't respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON) 
/*PRQA S 8018 , 8318, 8518  ++ */
  P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,COM_CALIB_CONST) pkstrLocGrpSigPB;
/*PRQA S 8018 , 8318, 8518  -- */
#endif

#if (Com_bGW_DESC_SUPPORT == STD_ON) 
/*PRQA S 8018 , 8318, 8518  ++ */
  P2CONST(Com_tstrGWSrcDesc,AUTOMATIC,COM_CALIB_CONST) 		pkstrLocSrcDscPB;    
/*PRQA S 8018 , 8318, 8518  -- */  
#endif
/*PRQA S 8018 , 8318, 8518  -- */        
  u8SigStructType = u8SIG_STRUCTURE_TYPE(u16SignalId);
  u16ArrSigByteLength = (uint16)0;  
 /* !Deviation: [3352]  ( The Switch case has more than 2 paths in the normal case but
in some special configuration it will have only two paths.) */
/*PRQA S 3352 ++ */
   switch (u8SigStructType)
  {
#if(Com_u16NO_OF_SIGNAL > 0u)    
    case Com_u8SIG_STRUCT_SIG:
    pkstrSigLookUp = pkstrGET_LOOKUP_SIG_PTR(u16SignalId);
    u16SigIxLoc = pkstrSigLookUp->u16Index;
    strLocUnpackSigProp.u8SigContainer = pkstrSigLookUp->u8StructureType;
    pkstrLocSigPB =  pkstrGET_PBSIGPTR_IX(u16SigIxLoc);
    strLocUnpackSigProp.u8SigType =  pkstrLocSigPB->u8SignalType;
   /*Set the strLocUnpackSigProp.u8CurrBitSize to the signal size*/
    strLocUnpackSigProp.u8CurrBitSize = pkstrLocSigPB->u8BitSize;
    strLocUnpackSigProp.u16CurrBitPosition = pkstrLocSigPB->u16BitPosition;
   /*Calculate the starting byte number inside the IPDU of this signal
   StartingByteNumer = BitPosition / 8 */
   strLocUnpackSigProp.u16StartByteNum =  (strLocUnpackSigProp.u16CurrBitPosition)>>3;
   /*Calculate the StartBitPosition Inside the NewByte
    Start Bit Position Inside The New Byte = BitPosition % 8 */
    /*range = 0..7 */
    strLocUnpackSigProp.u8StartBitPos =
    (uint8)((strLocUnpackSigProp.u16CurrBitPosition) - (strLocUnpackSigProp.u16StartByteNum << 3));
    /*Get the signal endianess*/
    
    u16SigObjIx = pkstrLocSigPB->u16SignalObjectIndex;
    strLocUnpackSigProp.u8SigEndianess = (uint8)(pkstrLocSigPB->udteSignalFlags & Com_u8SIGNAL_ENDIANESS);
    u16ArrSigByteLength = Com_akstreSignalLT[u16SigIxLoc].u16SignalLength;

#if Com_u16SIG_INV_V_B_SIZE || Com_u16SIG_INV_V_U8U8N_SIZE || Com_u16SIG_INV_V_S8_SIZE || Com_u16SIG_INV_V_U16_SIZE || Com_u16SIG_INV_V_S16_SIZE || Com_u8SIGNAL_TYPE_UINT32 || Com_u8SIGNAL_TYPE_SINT32 || Com_u16SIG_INV_V_F32_SIZE || Com_u16SIG_INV_V_F64_SIZE > 0u
    strLocUnpackSigProp.u16SigInvalidIx = Com_akstreSignalLT[u16SigIxLoc].u16SigInvalidValIndex;
#endif
    strLocUnpackSigProp.u16SigIx = u16SigIxLoc;
    
#if (Com_bDATA_TP_SUPPORT == STD_ON)    
    u16PduId = pkstrLocSigPB->u16IPduIndex;
#endif

    break;
#endif /*(Com_u16NO_OF_SIGNAL > 0u)*/

#if((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON) )
    case Com_u8SIG_STRUCT_GROUPSIG:
    pkstrSigLookUp = pkstrGET_LOOKUP_SIG_PTR(u16SignalId);
    strLocUnpackSigProp.u8SigContainer = pkstrSigLookUp->u8StructureType;
    u16SigIxLoc = pkstrSigLookUp->u16Index;
    pkstrLocGrpSigPB = pkstrGET_PBGRPSIGPTR_IX(u16SigIxLoc);
    strLocUnpackSigProp.u8SigType =  pkstrLocGrpSigPB->u8SignalType;
   /*Set the strLocUnpackSigProp.u8CurrBitSize to the signal size*/
    strLocUnpackSigProp.u8CurrBitSize = pkstrLocGrpSigPB->u8BitSize;
    strLocUnpackSigProp.u16CurrBitPosition = pkstrLocGrpSigPB->u16BitPosition;
   /*Calculate the starting byte number inside the IPDU of this signal
   StartingByteNumer = BitPosition / 8 */
   strLocUnpackSigProp.u16StartByteNum =  (strLocUnpackSigProp.u16CurrBitPosition)>>3;
   /*Calculate the StartBitPosition Inside the NewByte
    Start Bit Position Inside The New Byte = BitPosition % 8 */
    /*range = 0..7 */
    strLocUnpackSigProp.u8StartBitPos=
    (uint8)((strLocUnpackSigProp.u16CurrBitPosition) - (strLocUnpackSigProp.u16StartByteNum << 3));
    /*Get the signal endianess*/
    strLocUnpackSigProp.u8SigEndianess = (uint8)(pkstrLocGrpSigPB->udteGroupSignalFlags & Com_u8GRPSIGNAL_ENDIANESS);
    u16SigObjIx = pkstrLocGrpSigPB->u16SignalObjectIndex;
    strLocUnpackSigProp.u16SigIx = u16SigIxLoc;
    u16ArrSigByteLength = Com_akstreGroupSignalLT[u16SigIxLoc].u16SignalLength;

#if (Com_bDATA_TP_SUPPORT == STD_ON)    
    u16PduId = pkstrLocGrpSigPB->u16IPduIndex;      
#endif
    
#if Com_u16SIG_INV_V_B_SIZE || Com_u16SIG_INV_V_U8U8N_SIZE || Com_u16SIG_INV_V_S8_SIZE || Com_u16SIG_INV_V_U16_SIZE || Com_u16SIG_INV_V_S16_SIZE || Com_u8SIGNAL_TYPE_UINT32 || Com_u8SIGNAL_TYPE_SINT32 || Com_u16SIG_INV_V_F32_SIZE || Com_u16SIG_INV_V_F64_SIZE > 0u
    strLocUnpackSigProp.u16SigInvalidIx = u16GRPSIG_INVALID_IX(u16SigIxLoc);
#endif
    break;
#endif /*(Com_u16NO_OF_GROUP_SIGSLT > 0u)*/    


#if (Com_bGW_DESC_SUPPORT == STD_ON)
    case Com_u8GW_STRUCT_SRC_DESC:
    pkstrSigLookUp = pkstrGET_LOOKUP_SIG_PTR(u16SignalId);
    u16SigIxLoc = pkstrSigLookUp->u16Index;
    pkstrLocSrcDscPB = pkstrGET_PBSRC_DESCPTR_IX(u16SigIxLoc);
    strLocUnpackSigProp.u8SigType =  pkstrLocSrcDscPB->u8SignalType;
    strLocUnpackSigProp.u8CurrBitSize = pkstrLocSrcDscPB->u8BitSize;
    strLocUnpackSigProp.u16CurrBitPosition = pkstrLocSrcDscPB->u16BitPosition;
   /*Calculate the starting byte number inside the IPDU of this signal
   StartingByteNumer = BitPosition / 8 */
   strLocUnpackSigProp.u16StartByteNum =  (strLocUnpackSigProp.u16CurrBitPosition)>>3;
   /*Calculate the StartBitPosition Inside the NewByte
    Start Bit Position Inside The New Byte = BitPosition % 8 */
    /*range = 0..7 */
    strLocUnpackSigProp.u8StartBitPos=
    (uint8)((strLocUnpackSigProp.u16CurrBitPosition) - (strLocUnpackSigProp.u16StartByteNum << 3));
    /*Get the signal endianess*/
    strLocUnpackSigProp.u8SigEndianess = (uint8)(pkstrLocSrcDscPB->udteSignalFlags & Com_u8SIGNAL_ENDIANESS);
    u16SigObjIx = pkstrLocSrcDscPB->u16SignalObjectIndex; 
#if(Com_u16GW_SIG_LENGTH_SIZE > 0u)       
    u16ArrSigByteLength = Com_aku16eGWSignalLength[pkstrLocSrcDscPB->u16LengthIndex];
#endif /*(Com_u16GW_SIG_LENGTH_SIZE > 0u)*/   

#if Com_u16SIG_INV_V_B_SIZE || Com_u16SIG_INV_V_U8U8N_SIZE || Com_u16SIG_INV_V_S8_SIZE || Com_u16SIG_INV_V_U16_SIZE || Com_u16SIG_INV_V_S16_SIZE || Com_u8SIGNAL_TYPE_UINT32 || Com_u8SIGNAL_TYPE_SINT32 || Com_u16SIG_INV_V_F32_SIZE || Com_u16SIG_INV_V_F64_SIZE > 0u
     strLocUnpackSigProp.u16SigInvalidIx = (uint16)0xFFFFu;  
#endif

#if (Com_bDATA_TP_SUPPORT == STD_ON)	 
    u16PduId = pkstrLocSrcDscPB->u16IPduIndex; 
#endif

    break;
#endif
    default:
    /*shall not enter here*/
    /*Com_u8GW_STRUCT_DST_DESC is not supported*/    
    strLocUnpackSigProp.u8SigType = (uint8)0xFF ;
    strLocUnpackSigProp.u8CurrBitSize = (uint8)0;
    strLocUnpackSigProp.u16CurrBitPosition = (uint16)0xFFu;
    strLocUnpackSigProp.u16StartByteNum =  (uint16)0;
    /*range = 0..7 */
    strLocUnpackSigProp.u8StartBitPos = (uint8)0xFFu;
    /*Get the signal endianess*/
    strLocUnpackSigProp.u8SigEndianess = (uint8)0xFFu;
    u16SigObjIx = (uint16)0;    
    
#if (Com_bDATA_TP_SUPPORT == STD_ON)	
    u16PduId = (uint16)0xFFFFu;
#endif

    u16SigIxLoc = (uint16)0;
    
#if Com_u16SIG_INV_V_B_SIZE || Com_u16SIG_INV_V_U8U8N_SIZE || Com_u16SIG_INV_V_S8_SIZE || Com_u16SIG_INV_V_U16_SIZE || Com_u16SIG_INV_V_S16_SIZE || Com_u8SIGNAL_TYPE_UINT32 || Com_u8SIGNAL_TYPE_SINT32 || Com_u16SIG_INV_V_F32_SIZE || Com_u16SIG_INV_V_F64_SIZE > 0u
    strLocUnpackSigProp.u16SigInvalidIx = (uint16)0xFFFFu;
#endif
    break;
  }
/*PRQA S 3352 -- */

	u8UnpackReturn = (uint8)Com_u8UNPACK_NOT_OK;

  #if (Com_bPTR_NULL_CHECK == STD_ON) 
   if (pkstrPduInfoPtr !=(P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))NULL_PTR)
   {
  #endif
     switch (strLocUnpackSigProp.u8SigType)
     {
  /* !Deviation: [0310]  ( Casting to different object pointer type.)
   Casting of a pointer to another pointer with the same or less strict alignment is safe ,
   in the bellow code , casting is always done to the (char *) which has the least alignment ( 1Byte ) .
   */

  /* PRQA S 310 ++ */       
  /* PRQA S 3382 ++ */
       case Com_u8SIGNAL_TYPE_BOOLEAN:
           strLocUnpackSigProp.u8SignBitFiller      = (uint8)0x00u;
           pu8BigEndianBuff =  &u8SigU8TempUnpacked;
           pvidSignalObject  = pkB_GET_SIG_OBJ_VALUEB(u16SigObjIx);
           u8UnpackReturn = u8ExtSigAppFilter8Bit(&strLocUnpackSigProp,pkstrPduInfoPtr,pu8BigEndianBuff);
           if ((pvidSignalObject != (P2VAR(boolean,AUTOMATIC,COM_APPL_DATA)) NULL_PTR) && 
                (u8UnpackReturn == Com_u8UNPACK_OK))
           {
                /*update the signal object and set the return with OK */
                  /* !Deviation: [3212]  ( Casting may be important here because boolean 
                  may be different in another compiler. */
                  /* PRQA S 3212 ++ */  
                   (*(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA)) pvidSignalObject) = *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA)) pu8BigEndianBuff;
                 /* PRQA S 3212 -- */
           }
       break;
       case Com_u8SIGNAL_TYPE_UINT8:
            strLocUnpackSigProp.u8SignBitFiller      = (uint8)0x00u;
            pu8BigEndianBuff =  &u8SigU8TempUnpacked;
            pvidSignalObject  = pku8GET_SIG_OBJ_VALUEU8(u16SigObjIx);
            u8UnpackReturn = u8ExtSigAppFilter8Bit(&strLocUnpackSigProp,pkstrPduInfoPtr,pu8BigEndianBuff);
            if ((pvidSignalObject != (P2VAR(uint8,AUTOMATIC,COM_APPL_DATA)) NULL_PTR) && 
                (u8UnpackReturn == Com_u8UNPACK_OK))
           {
                /*update the signal object and set the return with OK */
                (*(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA)) pvidSignalObject) = *pu8BigEndianBuff;
           }
       break;

       case Com_u8SIGNAL_TYPE_SINT8:
              pvidSignalObject = pks8GET_SIG_OBJ_VALUES8(u16SigObjIx);
              pu8BigEndianBuff =  &u8SigU8TempUnpacked;
              strLocUnpackSigProp.u8SignBitFiller =
                bIsSignalNegative (
                (strLocUnpackSigProp.u8SigEndianess),
                 strLocUnpackSigProp.u8CurrBitSize,
                 strLocUnpackSigProp.u16CurrBitPosition,
                 (P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))(pkstrPduInfoPtr->SduDataPtr));
             u8UnpackReturn = u8ExtSigAppFilter8Bit(&strLocUnpackSigProp,pkstrPduInfoPtr,pu8BigEndianBuff);
            if ((pvidSignalObject != (P2VAR(sint8,AUTOMATIC,COM_APPL_DATA)) NULL_PTR) && 
                (u8UnpackReturn == Com_u8UNPACK_OK))
            {
                /*update the signal object and set the return with OK */
                (*(P2VAR(sint8,AUTOMATIC,COM_APPL_DATA)) pvidSignalObject) = *(P2VAR(sint8,AUTOMATIC,COM_APPL_DATA)) pu8BigEndianBuff;
            }
       break;

       case Com_u8SIGNAL_TYPE_UINT16:
        strLocUnpackSigProp.u8SignBitFiller      = (uint8)0x00u;
        pu16BigEndianBuff = &u16SigU16TempUnpacked;
        pvidSignalObject  = pku16GET_SIG_OBJ_VALUEU16(u16SigObjIx);
        u8UnpackReturn = u8ExtSigAppFilter16Bit(&strLocUnpackSigProp,pkstrPduInfoPtr,pu16BigEndianBuff);
        if ((pvidSignalObject != (P2VAR(uint16,AUTOMATIC,COM_APPL_DATA)) NULL_PTR) && 
                (u8UnpackReturn == Com_u8UNPACK_OK))
        {
                /*update the signal object and set the return with OK */
            SchM_Enter_Com_SigObjU16();
            *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA)) pvidSignalObject =  *pu16BigEndianBuff;
            SchM_Exit_Com_SigObjU16();
        }     
       break;

       case Com_u8SIGNAL_TYPE_SINT16:
            pu16BigEndianBuff = &u16SigU16TempUnpacked;
            strLocUnpackSigProp.u8SignBitFiller =
                bIsSignalNegative (
                (strLocUnpackSigProp.u8SigEndianess),
                 strLocUnpackSigProp.u8CurrBitSize,
                 strLocUnpackSigProp.u16CurrBitPosition,
                 (P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))(pkstrPduInfoPtr->SduDataPtr));
            pvidSignalObject  =  pks16GET_SIG_OBJ_VALUES16(u16SigObjIx);
            u8UnpackReturn = u8ExtSigAppFilter16Bit(&strLocUnpackSigProp,pkstrPduInfoPtr,pu16BigEndianBuff);
            if ((pvidSignalObject != (P2VAR(sint16,AUTOMATIC,COM_APPL_DATA)) NULL_PTR) && 
                (u8UnpackReturn == Com_u8UNPACK_OK))
            {
                    /*update the signal object and set the return with OK */
                SchM_Enter_Com_SigObjS16();
                *(P2VAR(sint16,AUTOMATIC,COM_APPL_DATA)) pvidSignalObject = *(P2VAR(sint16,AUTOMATIC,COM_APPL_DATA)) pu16BigEndianBuff;
                SchM_Exit_Com_SigObjS16();
            }   
       break;

       case Com_u8SIGNAL_TYPE_UINT32:
         strLocUnpackSigProp.u8SignBitFiller      = (uint8)0x00u;
         pvidSignalObject    = pku32GET_SIG_OBJ_VALUEU32(u16SigObjIx);
         pu32BigEndianBuffTemp =  &au32SigU32TempUnpacked[0];
         vidExtSigAppFilter32Bit(&strLocUnpackSigProp,pkstrPduInfoPtr,pu32BigEndianBuffTemp);
         u8UnpackReturn = udtFilterInvChkCpu32Bit(&strLocUnpackSigProp,pkstrPduInfoPtr,pu32BigEndianBuffTemp);
        
        if ((pvidSignalObject != (P2VAR(uint32,AUTOMATIC,COM_APPL_DATA)) NULL_PTR) && 
                (u8UnpackReturn == Com_u8UNPACK_OK))
        {
                /*update the signal object and set the return with OK */
            SchM_Enter_Com_SigObjU32();
            *(P2VAR(uint32,AUTOMATIC,COM_APPL_DATA)) pvidSignalObject = *pu32BigEndianBuffTemp;
            SchM_Exit_Com_SigObjU32();
        }    
         
       break;

       case Com_u8SIGNAL_TYPE_SINT32:
         strLocUnpackSigProp.u8SignBitFiller =
                bIsSignalNegative (
                (strLocUnpackSigProp.u8SigEndianess),
                 strLocUnpackSigProp.u8CurrBitSize,
                 strLocUnpackSigProp.u16CurrBitPosition,
                 (P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))(pkstrPduInfoPtr->SduDataPtr));
         pvidSignalObject  = pks32GET_SIG_OBJ_VALUES32(u16SigObjIx);
         pu32BigEndianBuffTemp =  &au32SigU32TempUnpacked[0];
         vidExtSigAppFilter32Bit(&strLocUnpackSigProp,pkstrPduInfoPtr,pu32BigEndianBuffTemp);
         u8UnpackReturn = udtFilterInvChkCpu32Bit(&strLocUnpackSigProp,pkstrPduInfoPtr,pu32BigEndianBuffTemp);          
        
         if ((pvidSignalObject != (P2VAR(sint32,AUTOMATIC,COM_APPL_DATA)) NULL_PTR) && 
                (u8UnpackReturn == Com_u8UNPACK_OK))
        {
                /*update the signal object and set the return with OK */
            SchM_Enter_Com_SigObjS32();
            *(P2VAR(sint32,AUTOMATIC,COM_APPL_DATA)) pvidSignalObject = *(P2VAR(sint32,AUTOMATIC,COM_APPL_DATA)) pu32BigEndianBuffTemp;
            SchM_Exit_Com_SigObjS32();
        }     
       break;
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON)
       case Com_u8SIGNAL_TYPE_FLOAT32:
         strLocUnpackSigProp.u8SignBitFiller      = (uint8)0x00u;
         pvidSignalObject  = pkf32GET_SIG_OBJ_VALUEF32(u16SigObjIx);
         pu32BigEndianBuffTemp = &au32SigU32TempUnpacked[0];
         vidExtSigAppFilter32Bit(&strLocUnpackSigProp,pkstrPduInfoPtr,pu32BigEndianBuffTemp);
         u8UnpackReturn = udtFilterInvChkCpu32Bit(&strLocUnpackSigProp,pkstrPduInfoPtr,pu32BigEndianBuffTemp);
            
        if ((pvidSignalObject != (P2VAR(float32,AUTOMATIC,COM_APPL_DATA)) NULL_PTR) && 
                (u8UnpackReturn == Com_u8UNPACK_OK))
        {
                /*update the signal object and set the return with OK */
            SchM_Enter_Com_SigObjF32();
            *(P2VAR(float32,AUTOMATIC,COM_APPL_DATA)) pvidSignalObject = *(P2VAR(float32,AUTOMATIC,COM_APPL_DATA)) pu32BigEndianBuffTemp;
            SchM_Exit_Com_SigObjF32();
        }     
         
       break;

       case Com_u8SIGNAL_TYPE_FLOAT64:
           strLocUnpackSigProp.u8SignBitFiller      = (uint8)0x00u;
           pvidSignalObject  =  pkf64GET_SIG_OBJ_VALUEF64(u16SigObjIx);
           
           #if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
           pu32BigEndianBuff = &au32SigU32TempUnpacked[1];
           #else
           pu32BigEndianBuff = &au32SigU32TempUnpacked[0];
           #endif
           
           strLocUnpackSigProp.u8CurrBitSize = 32;
           vidExtSigAppFilter32Bit(&strLocUnpackSigProp,pkstrPduInfoPtr,pu32BigEndianBuff);
           
           #if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
           pu32BigEndianBuff = &au32SigU32TempUnpacked[0];
           #else
           pu32BigEndianBuff = &au32SigU32TempUnpacked[1];
           #endif
           
           if (strLocUnpackSigProp.u8SigEndianess == Com_u8ENDIANESS_BIG)
           {
                strLocUnpackSigProp.u16StartByteNum -= 4;
                strLocUnpackSigProp.u16CurrBitPosition -= 32; 
           }
           else
           {
                strLocUnpackSigProp.u16StartByteNum += 4;
                strLocUnpackSigProp.u16CurrBitPosition += 32;               
           }
           
            vidExtSigAppFilter32Bit(&strLocUnpackSigProp,pkstrPduInfoPtr,pu32BigEndianBuff);
            /* !Deviation : Inhibit MISRA rule [3305]: Casting is important here and not  */
            /*          impacted becase it's casting to array of two element              */
            /*              memory classes                                                */
            /* PRQA S 3305 ++                                                             */

            pf64BigEndianBuffTemp = (P2VAR(float64,AUTOMATIC,COM_APPL_DATA)) &au32SigU32TempUnpacked[0];
            /* PRQA S 3305 -- */
            
            u8UnpackReturn = udtFilterInvChkCpu64Bit(&strLocUnpackSigProp, pkstrPduInfoPtr, pf64BigEndianBuffTemp);
            
            if ((pvidSignalObject != (P2VAR(float64,AUTOMATIC,COM_APPL_DATA)) NULL_PTR) && 
                    (u8UnpackReturn == Com_u8UNPACK_OK))
            {
                    /*update the signal object and set the return with OK */
                SchM_Enter_Com_SigObjF64();
                *(P2VAR(float64,AUTOMATIC,COM_APPL_DATA)) pvidSignalObject = *pf64BigEndianBuffTemp;
                SchM_Exit_Com_SigObjF64();
            }   
       break;
#endif
       case  Com_u8SIGNAL_TYPE_UINT8N :
          u8UnpackReturn = u8UnPackArraySignal(
                      Com_u8SIGNAL_TYPE_UINT8N,
                      u16SigObjIx,            
                      u16ArrSigByteLength,
                      strLocUnpackSigProp.u16StartByteNum, 
                      0,            
                      (P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))(pkstrPduInfoPtr->SduDataPtr) );                            
       break;
#if (Com_bDATA_TP_SUPPORT == STD_ON)	   
#if(Com_u16NO_OF_SIGNAL > 0u)    
       case Com_u8SIGNAL_TYPE_UINT8DYN:
		  pu8IPduBuf = pkstrGET_IPDU_BUFF_PTR(0);
          pkstrLocRXIpduPB = pkstrGET_RX_IPDU_PTR(u16PduId);                 
          u32IpduLastByteIx = pkstrLocRXIpduPB->u32IPduBufferIndex +
                              (uint32)strLocUnpackSigProp.u16StartByteNum +
                              (uint32)Com_akstreSignalLT[u16SigIxLoc].u16SignalLength  
                              + (uint32)1;
          SchM_Enter_Com_IPduBuff();                          
          u16TpIpduLen = ( (uint16)(((uint16)(pu8IPduBuf[u32IpduLastByteIx - (uint32)1 ] )) <<(uint16)8u ) )| 
               ((uint16)pu8IPduBuf[u32IpduLastByteIx] ); 
           SchM_Exit_Com_IPduBuff();

          u16DynSigLen = u16TpIpduLen - strLocUnpackSigProp.u16StartByteNum;
          u8UnpackReturn = u8UnPackArraySignal(
                      Com_u8SIGNAL_TYPE_UINT8DYN,
                      u16SigObjIx,            
                      u16DynSigLen,
                      strLocUnpackSigProp.u16StartByteNum, 
                      u16ArrSigByteLength,            
                      (P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))(pkstrPduInfoPtr->SduDataPtr));                             
       break;
#endif /*(Com_u16NO_OF_SIGNAL > 0u) */
#endif
       
       default:
       strLocUnpackSigProp.u8SignalBufferLen = (uint8)8u;
       strLocUnpackSigProp.u8SignBitFiller      = (uint8)0x00u ; 
       break;

	}
#if (Com_bPTR_NULL_CHECK == STD_ON) 
   }
   else
   {
   /*Null pointer (pkstrPduInfoPtr) was passed to the unpack function , shall not process the signal*/
   }
#endif

   return u8UnpackReturn;
}
/*PRQA S 3205,3202, 3199, 3203 -- */
 /* PRQA S 3382 -- */
/* PRQA S 4700 -- */
/******************************************************************************/
/* !Deviation: [4700]  ( here has been an infringement of a threshold on the specified metric)
The Com_SignalApplyFilter function deviate the complexity threshold, but no more division/simplification can be done
for performance issues*/
/* PRQA S 4700 ++ */
/* !Deviation: [3205]  ( Some of the varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S 3205, 3199, 3203 ++ */
/* PRQA S 0781 ++                                                             */
/* !Deviation : Inhibit MISRA rule [3673]: There is no need to change pointer to variable   */
/*to pointer to constant because the function used is an internal function                    */

/*! \Trace_To :  Com-CDD-SignalIpduServices-0534(0) , Com-CDD-SignalIpduServices-0255(0),
Com-CDD-SignalIpduServices-0256(0) , Com-CDD-SignalIpduServices-0257(0),
Com-CDD-SignalIpduServices-0258(0) , Com-CDD-SignalIpduServices-0270(0),
Com-CDD-SignalIpduServices-0401(0) , Com-CDD-SignalIpduServices-0402(0),
Com-CDD-SignalIpduServices-0252(0) , Com-CDD-SignalIpduServices-0253(0) , 
Com-CDD-SignalIpduServices-0254(0) , Com-CDD-SignalIpduServices-0255(0) , 
Com-CDD-SignalIpduServices-0532(0) , Com-CDD-SignalIpduServices-0533(0) , 
Com-CDD-SignalIpduServices-0534(0) , Com-CDD-SignalIpduServices-5742(0) , */
FUNC(boolean,COM_CODE) Com_bSignalApplyFilter (
                       VAR(Com_SignalIdType,AUTOMATIC) u16SigIx,
                       P2CONST(void,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pkvidSignalDataPtr,
					   VAR(uint8,AUTOMATIC)            u8SigStrcture)
{
   /*local variables declaration */
   VAR(boolean,AUTOMATIC)                                bFilterResult;
   VAR(uint8,AUTOMATIC)                                  u8FilterAlg;
   VAR(uint16,AUTOMATIC)                                 u16FilterIx;
   /*PRQA S 8018 , 8318, 8518  ++ */
   P2CONST(Com_tstrFilter,AUTOMATIC,COM_CALIB_CONST)     pkstrSigFilter;

#if (Com_bGW_DESC_SUPPORT == STD_ON)
   P2CONST(Com_tstrGWDstDesc,AUTOMATIC,COM_CALIB_CONST)  pkstrLocDstDscPB;
#endif

 
#if (Com_u16NO_OF_ONE_EVERY_N_F > 0u)
   P2CONST(uint32,AUTOMATIC,COM_CALIB_CONST)  			 pku32OneEveryNPeriod;
   VAR(uint16,AUTOMATIC)                                 u16SpecificFilterIndex = 0;
#endif
  /*PRQA S 8018 , 8318, 8518  -- */
   u8FilterAlg = 0xFFu;
 
#if (Com_u16NO_OF_ONE_EVERY_N_F > 0u)
   pku32OneEveryNPeriod = pku32GETONE_EVERY_NPERIOD(0);
#endif

   switch(u8SigStrcture)
   {
    case Com_u8SIG_STRUCT_SIG:
	
	/* PRQA S 3746 ++ */
	u16FilterIx = Com_akstreSignalLT[u16SigIx].u16FilterIndex;
	/* PRQA S 3746 -- */	
	if(u16FilterIx != (uint16)0xFFFFu)
	{
	pkstrSigFilter = pkstrGET_FILTER_SPEC_PTR(u16FilterIx);
	u8FilterAlg = pkstrSigFilter->u8FilterAlgorithm;
	
 #if (Com_u16NO_OF_ONE_EVERY_N_F > 0u)
    u16SpecificFilterIndex =  pkstrSigFilter->u16Index;
#endif

    }
	break;
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
    case Com_u8SIG_STRUCT_GROUPSIG:
	/* PRQA S 3746 ++ */
	u16FilterIx = Com_akstreGroupSignalLT[u16SigIx].u16FilterIndex;
	/* PRQA S 3746 -- */
	if(u16FilterIx != (uint16)0xFFFFu)
	{
	pkstrSigFilter = pkstrGET_FILTER_SPEC_PTR(u16FilterIx);
	u8FilterAlg = pkstrSigFilter->u8FilterAlgorithm;

 #if (Com_u16NO_OF_ONE_EVERY_N_F > 0u)
    u16SpecificFilterIndex =  pkstrSigFilter->u16Index;
#endif
    }
	break;
#endif

#if (Com_bGW_DESC_SUPPORT == STD_ON)
    case Com_u8GW_STRUCT_DST_DESC:
	pkstrLocDstDscPB = pkstrGET_PBDSTDESCPTR_IX(u16SigIx);
	u16FilterIx = pkstrLocDstDscPB->u16FilterIndex;
	if(u16FilterIx != (uint16)0xFFFFu)
	{
	pkstrSigFilter = pkstrGET_FILTER_SPEC_PTR(u16FilterIx);
	u8FilterAlg = pkstrSigFilter->u8FilterAlgorithm;
 #if (Com_u16NO_OF_ONE_EVERY_N_F > 0u)
    u16SpecificFilterIndex =  pkstrSigFilter->u16Index;
#endif

	}
    break;
#endif

    default:
    /*  Com_u8GW_STRUCT_SRC_DESC has no configured filter*/     
    u8FilterAlg =   (uint8)0xFFu;
	u16FilterIx = (uint16)0xFFFFu;
#if (Com_u16NO_OF_ONE_EVERY_N_F > 0u)
    u16SpecificFilterIndex = (uint16)0u;
#endif
    break;

   }
 /* !Deviation: [3356]  ( The value of this control expression is always 'false' due to 
 some special configuration but in the normal case this part is normally reachable.) */
/*PRQA S 3356, 3359,3201  ++ */
   /*if(bIsFilterConf == (boolean)TRUE)*/
   if (u16FilterIx != (uint16)0xFFFFu)
   {
 /*PRQA S 3356, 3359,3201  -- */  
    /*signal had a configured filter*/
     switch(u8FilterAlg)
     {
      case Com_u8F_ALWAYS:
        bFilterResult = TRUE;
      break;
      case Com_u8F_NEVER:
        bFilterResult = FALSE;
      break;
      case Com_u8F_M_NEW_DIFF_M_OLD:
        bFilterResult = bEvalMskNewOldFltrAlg(u16SigIx,
#if Com_u16NO_OF_MASK_OLD_F_B || Com_u16NO_OF_MASK_OLD_F_U8 || Com_u16NO_OF_MASK_OLD_F_S8 || Com_u16NO_OF_MASK_OLD_F_U16 || Com_u16NO_OF_MASK_OLD_F_S16 || Com_u16NO_OF_MASK_OLD_F_U32 || Com_u16NO_OF_MASK_OLD_F_S32 > 0u
			pkvidSignalDataPtr,
#endif
			u8SigStrcture
			);
      break;
      case Com_u8F_MASKED_NEW_DIFF_X:
       /* bFilterResult = negation of the result of the bEvalMaskNewEqFltrAlg function*/
      bFilterResult = (bEvalMaskNewEqFltrAlg(u16SigIx,
#if Com_u16NO_OF_MASK_F_B || Com_u16NO_OF_LIMITS_F_U8 || Com_u16NO_OF_LIMITS_F_S8 || Com_u16NO_OF_LIMITS_F_U16 || Com_u16NO_OF_LIMITS_F_S16 || Com_u16NO_OF_LIMITS_F_U32 || Com_u16NO_OF_LIMITS_F_S32 > 0u		  
		  pkvidSignalDataPtr,
#endif
		u8SigStrcture
		  ))^(uint8)0x01u;
      break;
      case Com_u8F_MASKED_NEW_EQ_X:
        bFilterResult = bEvalMaskNewEqFltrAlg(u16SigIx,
#if Com_u16NO_OF_MASK_F_B || Com_u16NO_OF_LIMITS_F_U8 || Com_u16NO_OF_LIMITS_F_S8 || Com_u16NO_OF_LIMITS_F_U16 || Com_u16NO_OF_LIMITS_F_S16 || Com_u16NO_OF_LIMITS_F_U32 || Com_u16NO_OF_LIMITS_F_S32 > 0u			
			pkvidSignalDataPtr,
#endif
			u8SigStrcture
			);
      break;
      case Com_u8F_NEW_IS_OUTSIDE:
        /*bFilterResult = negation of the result of the bEvalWithinFilterAlg function  */
        bFilterResult = (bEvalWithinFilterAlg(u16SigIx,
#if Com_u16NO_OF_LIMITS_F_U8 || Com_u16NO_OF_LIMITS_F_S8 || Com_u16NO_OF_LIMITS_F_U16 || Com_u16NO_OF_LIMITS_F_S16 || Com_u16NO_OF_LIMITS_F_U32 || Com_u16NO_OF_LIMITS_F_S32 > 0u			
			pkvidSignalDataPtr,
#endif			
			u8SigStrcture
			))^(uint8)0x01u;
      break;
      case Com_u8F_NEW_IS_WITHIN:
        bFilterResult = bEvalWithinFilterAlg(u16SigIx,
#if Com_u16NO_OF_LIMITS_F_U8 || Com_u16NO_OF_LIMITS_F_S8 || Com_u16NO_OF_LIMITS_F_U16 || Com_u16NO_OF_LIMITS_F_S16 || Com_u16NO_OF_LIMITS_F_U32 || Com_u16NO_OF_LIMITS_F_S32 > 0u			
			pkvidSignalDataPtr,
#endif		
			u8SigStrcture	
			);
      break;
      case Com_u8F_ONE_EVERY_N:
      /*(occurrence counter % periode ) equals the offset , return true , else return false
        [since the occurrence will be cleared when it is equal to the period ({Com-CDD-SignalIpduServices-0270(0)}),
        the above check could be simplified to the following : if occurrence was equal the offset ,
        return true else return false */

		/* !Deviation: [3198]  ( The Value assigned to Variable is set before being used   */
		/*PRQA S 3198 ++ */
		bFilterResult = FALSE;
		/*PRQA S 3198 -- */
      #if (Com_u16NO_OF_ONE_EVERY_N_F > 0u)
        if ( Com_au32eOneEveryNFilterCtr[Com_akstreOneEveryNFilter[u16SpecificFilterIndex].u16CounterIndex] ==
             Com_akstreOneEveryNFilter[u16SpecificFilterIndex].u32FilterOffset )
        {
           bFilterResult = TRUE;
        }
        else
        {
           bFilterResult = FALSE;
        }
        /*increment the occurrence*/
        Com_au32eOneEveryNFilterCtr[Com_akstreOneEveryNFilter[u16SpecificFilterIndex].u16CounterIndex] ++;

        /*clear the occurrence if it was equal to the period*/
        if (Com_au32eOneEveryNFilterCtr[Com_akstreOneEveryNFilter[u16SpecificFilterIndex].u16CounterIndex] ==
            pku32OneEveryNPeriod[u16SpecificFilterIndex])
        {
           Com_au32eOneEveryNFilterCtr[Com_akstreOneEveryNFilter[u16SpecificFilterIndex].u16CounterIndex] = 0x00UL;
        }
        else
        {
        /*do nothing*/
        }
      #endif

      break;
      default:
        bFilterResult = TRUE;
      break;
     }
   }
   else
   {
   /*signal has no configured value*/
   /*do nothing but return TRUE , in case the return of the function is used for further checks*/
     bFilterResult = TRUE;
   }
   return bFilterResult;
}
/*PRQA S 3205, 3199, 3203 -- */
/* PRQA S 4700 -- */
/* PRQA S 0781 --                                                             */

/* !Deviation: [4700]  ( here has been an infringement of a threshold on the specified metric)
The bEvalWithinFilterAlg function deviate the complexity threshold, but no more division/simplification can be done
for performance issues*/
/* PRQA S 4700 ++ */
/* !Deviation: [3205]  ( Some of the varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S 3205, 3199, 3203 ++ */
/* !Deviation: [3206]  ( Some of the input parameters are not used 
in this function depending on the configuration.) */
/*PRQA S 3206 ++ */
/* PRQA S 0781 ++                                                             */
/* !Deviation : Inhibit MISRA rule [3673]: There is no need to change pointer to variable   */
/*to pointer to constant because the function used is an internal function                    */

static FUNC(boolean,COM_CODE) bEvalWithinFilterAlg (
                       VAR(Com_SignalIdType,AUTOMATIC) u16SigIx,
#if Com_u16NO_OF_LIMITS_F_U8 || Com_u16NO_OF_LIMITS_F_S8 || Com_u16NO_OF_LIMITS_F_U16 || Com_u16NO_OF_LIMITS_F_S16 || Com_u16NO_OF_LIMITS_F_U32 || Com_u16NO_OF_LIMITS_F_S32 > 0u
                       P2CONST(void,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pkvidSigDataPtr,
#endif
                       VAR(uint8,AUTOMATIC)            u8SigStrcture
					   )
/*PRQA S 3206 -- */
{
 /* !Deviation: [8018]  (The name of the constant (const) doesn't respect the naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */
  P2CONST(Com_tstrSignalPB,AUTOMATIC,COM_CALIB_CONST)       pkstrLocSigPB;
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
  P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,COM_CALIB_CONST)  pkstrLocGrpSigPB;
#endif

#if (Com_bGW_DESC_SUPPORT == STD_ON)
  P2CONST(Com_tstrGWDstDesc,AUTOMATIC,COM_CALIB_CONST) 		pkstrLocDstDscPB;   
#endif  

/*PRQA S 8018 , 8318, 8518  -- */
   VAR(boolean,AUTOMATIC)                                bFiltrRes;
#if (Com_u16NO_OF_LIMITS_F_U8 > 0 || Com_u16NO_OF_LIMITS_F_S8 > 0 || Com_u16NO_OF_LIMITS_F_U16 > 0 || Com_u16NO_OF_LIMITS_F_S16 > 0 || Com_u16NO_OF_LIMITS_F_U32 > 0 ||Com_u16NO_OF_LIMITS_F_S32 > 0)
   VAR(uint16,AUTOMATIC)                                 u16SpecificFilterIndex;
#endif
   VAR(uint8,AUTOMATIC)                                  u8SigType;
   VAR(uint16,AUTOMATIC)                                 u16FilterIx;
  
   switch(u8SigStrcture)
   {
    case Com_u8SIG_STRUCT_SIG:
   /*get the signal type*/
    pkstrLocSigPB = pkstrGET_PBSIGPTR_IX(u16SigIx);
    /* PRQA S 3746 ++ */
    u16FilterIx = Com_akstreSignalLT[u16SigIx].u16FilterIndex;
    /* PRQA S 3746 -- */
    u8SigType     = pkstrLocSigPB->u8SignalType ;
#if (Com_u16NO_OF_LIMITS_F_U8 > 0 || Com_u16NO_OF_LIMITS_F_S8 > 0 || Com_u16NO_OF_LIMITS_F_U16 > 0 || Com_u16NO_OF_LIMITS_F_S16 > 0 || Com_u16NO_OF_LIMITS_F_U32 > 0 ||Com_u16NO_OF_LIMITS_F_S32 > 0)
    u16SpecificFilterIndex = u16GET_SPECIFIC_FLTR_IX(u16FilterIx);
#endif
    break;
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
    case Com_u8SIG_STRUCT_GROUPSIG:
    pkstrLocGrpSigPB = pkstrGET_PBGRPSIGPTR_IX(u16SigIx);
    /* PRQA S 3746 ++ */
    u16FilterIx = Com_akstreGroupSignalLT[u16SigIx].u16FilterIndex;
    /* PRQA S 3746 -- */
    u8SigType     = pkstrLocGrpSigPB->u8SignalType ;
#if (Com_u16NO_OF_LIMITS_F_U8 > 0 || Com_u16NO_OF_LIMITS_F_S8 > 0 || Com_u16NO_OF_LIMITS_F_U16 > 0 || Com_u16NO_OF_LIMITS_F_S16 > 0 || Com_u16NO_OF_LIMITS_F_U32 > 0 ||Com_u16NO_OF_LIMITS_F_S32 > 0)
    u16SpecificFilterIndex = u16GRPSIG_SPCFC_FLTR_IX(u16FilterIx);
#endif
    break;
#endif

#if (Com_bGW_DESC_SUPPORT == STD_ON)
    case Com_u8GW_STRUCT_DST_DESC:
    pkstrLocDstDscPB = pkstrGET_PBDSTDESCPTR_IX(u16SigIx) ;
    u8SigType     = pkstrLocDstDscPB->u8SignalType ;
#if (Com_u16NO_OF_LIMITS_F_U8 > 0 || Com_u16NO_OF_LIMITS_F_S8 > 0 || Com_u16NO_OF_LIMITS_F_U16 > 0 || Com_u16NO_OF_LIMITS_F_S16 > 0 || Com_u16NO_OF_LIMITS_F_U32 > 0 ||Com_u16NO_OF_LIMITS_F_S32 > 0)
    u16SpecificFilterIndex = u16DST_SPECIFIC_FLTR_IX(pkstrLocDstDscPB->u16FilterIndex);
#endif
    break;
#endif

    default:
    /*  Com_u8GW_STRUCT_SRC_DESC has no configured filter*/    
    u8SigType = (uint8)0xFFU ;
#if (Com_u16NO_OF_LIMITS_F_U8 > 0 || Com_u16NO_OF_LIMITS_F_S8 > 0 || Com_u16NO_OF_LIMITS_F_U16 > 0 || Com_u16NO_OF_LIMITS_F_S16 > 0 || Com_u16NO_OF_LIMITS_F_U32 > 0 ||Com_u16NO_OF_LIMITS_F_S32 > 0)
    u16SpecificFilterIndex = (uint16)0;
#endif
    break;

   }
   bFiltrRes = TRUE;
   switch (u8SigType)
   {
      /*signals with type : Com_u8SIGNAL_TYPE_BOOLEAN shall not be configired to have this filter algorithm
        signals with type float32 or float64 shall not have filter at all*/
       case Com_u8SIGNAL_TYPE_UINT8:
       #if Com_u16NO_OF_LIMITS_F_U8 > 0u
         if ((*(P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr >= Com_akstreLimitsFilterU8[u16SpecificFilterIndex].u8FilterMin)
          && (*(P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr <= Com_akstreLimitsFilterU8[u16SpecificFilterIndex].u8FilterMax))
          {
             bFiltrRes = TRUE;
          }
          else
          {
             bFiltrRes = FALSE;
          }
       #endif
       break;

       case Com_u8SIGNAL_TYPE_SINT8:
       #if Com_u16NO_OF_LIMITS_F_S8 > 0u
         if ((*(P2CONST(sint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr >= Com_akstreLimitsFilterS8[u16SpecificFilterIndex].s8FilterMin)
          && (*(P2CONST(sint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr <= Com_akstreLimitsFilterS8[u16SpecificFilterIndex].s8FilterMax))
         {
            bFiltrRes = TRUE;
         }
         else
         {
            bFiltrRes = FALSE;
         }
       #endif
       break;

       case Com_u8SIGNAL_TYPE_UINT16:
       #if Com_u16NO_OF_LIMITS_F_U16 > 0u
         if ((*(P2CONST(uint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr >= Com_akstreLimitsFilterU16[u16SpecificFilterIndex].u16FilterMin)
          && (*(P2CONST(uint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr <= Com_akstreLimitsFilterU16[u16SpecificFilterIndex].u16FilterMax))
          {
             bFiltrRes = TRUE;
          }
          else
          {
             bFiltrRes = FALSE;
          }
       #endif
       break;

       case Com_u8SIGNAL_TYPE_SINT16:
       #if Com_u16NO_OF_LIMITS_F_S16 > 0u
         if ((*(P2CONST(sint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr >= Com_akstreLimitsFilterS16[u16SpecificFilterIndex].s16FilterMin)
          && (*(P2CONST(sint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr <= Com_akstreLimitsFilterS16[u16SpecificFilterIndex].s16FilterMax))
          {
             bFiltrRes = TRUE;
          }
          else
          {
             bFiltrRes = FALSE;
          }
       #endif
       break;

       case Com_u8SIGNAL_TYPE_UINT32:
       #if Com_u16NO_OF_LIMITS_F_U32 > 0u
          if ((*(P2CONST(uint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr >= Com_akstreLimitsFilterU32[u16SpecificFilterIndex].u32FilterMin)
           && (*(P2CONST(uint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr <= Com_akstreLimitsFilterU32[u16SpecificFilterIndex].u32FilterMax))
           {
              bFiltrRes = TRUE;
           }
           else
           {
              bFiltrRes = FALSE;
           }
       #endif
       break;

       case Com_u8SIGNAL_TYPE_SINT32:
       #if Com_u16NO_OF_LIMITS_F_S32 > 0u
          if ((*(P2CONST(sint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr >= Com_akstreLimitsFilterS32[u16SpecificFilterIndex].s32FilterMin)
           && (*(P2CONST(sint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr <= Com_akstreLimitsFilterS32[u16SpecificFilterIndex].s32FilterMax))
          {
             bFiltrRes = TRUE;
          }
          else
          {
             bFiltrRes = FALSE;
          }
       #endif
       break;

        default:

        break;
   }
   return  bFiltrRes;
}
/* PRQA S 0781 --                                                             */

/*PRQA S 3205, 3199, 3203 -- */
/* PRQA S 4700 -- */

/* !Deviation: [4700]  ( here has been an infringement of a threshold on the specified metric)
The bEvalMaskNewEqFltrAlg function deviate the complexity threshold, but no more division/simplification can be done
for performance issues*/
/* PRQA S 4700 ++ */
/* !Deviation: [3205]  ( Some of the varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S 3205, 3199, 3203 ++ */
/* !Deviation: [3206]  ( Some of the input parameters are not used 
in this function depending on the configuration.) */
/*PRQA S 3206 ++ */
/* PRQA S 0781 ++                                                             */
/* !Deviation : Inhibit MISRA rule [3673]: There is no need to change pointer to variable   */
/*to pointer to constant because the function used is an internal function                    */

static FUNC(boolean,COM_CODE) bEvalMaskNewEqFltrAlg (
                       VAR(Com_SignalIdType,AUTOMATIC) u16SigIx,
#if (Com_u16NO_OF_MASK_F_B | Com_u16NO_OF_LIMITS_F_U8 | Com_u16NO_OF_LIMITS_F_S8 | Com_u16NO_OF_LIMITS_F_U16 | Com_u16NO_OF_LIMITS_F_S16 | Com_u16NO_OF_LIMITS_F_U32 | Com_u16NO_OF_LIMITS_F_S32) > 0u
                       P2CONST(void,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pkvidSigDataPtr,
#endif
                       VAR(uint8,AUTOMATIC)            u8SigStrcture
					   )
/*PRQA S 3206 -- */
{
 /* !Deviation: [8018]  (The name of the constant (const) doesn't respect the naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */
   P2CONST(Com_tstrSignalPB,AUTOMATIC,COM_CALIB_CONST)      pkstrLocSigPB;
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
  P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,COM_CALIB_CONST)  pkstrLocGrpSigPB;
#endif

#if (Com_bGW_DESC_SUPPORT == STD_ON)
  P2CONST(Com_tstrGWDstDesc,AUTOMATIC,COM_CALIB_CONST)      pkstrLocDstDscPB;
#endif

/*PRQA S 8018 , 8318, 8518  -- */
   VAR(boolean,AUTOMATIC)                                bFiltrRes;
#if (Com_u16NO_OF_MASK_F_B | Com_u16NO_OF_LIMITS_F_U8 | Com_u16NO_OF_LIMITS_F_S8 | Com_u16NO_OF_LIMITS_F_U16 | Com_u16NO_OF_LIMITS_F_S16 | Com_u16NO_OF_LIMITS_F_U32 | Com_u16NO_OF_LIMITS_F_S32) > 0u
   VAR(uint16,AUTOMATIC)                                 u16SpecificFilterIndex;
   VAR(uint16,AUTOMATIC)                                 u16FilterIx;
#endif
   VAR(uint8,AUTOMATIC)                                  u8SigType;


   switch(u8SigStrcture)
   {
    case Com_u8SIG_STRUCT_SIG:
   /*get the signal type*/
    pkstrLocSigPB = pkstrGET_PBSIGPTR_IX(u16SigIx);
    /* PRQA S 3746 ++ */
    /* PRQA S 3746 -- */
    u8SigType     = pkstrLocSigPB->u8SignalType ;
#if (Com_u16NO_OF_MASK_F_B | Com_u16NO_OF_LIMITS_F_U8 | Com_u16NO_OF_LIMITS_F_S8 | Com_u16NO_OF_LIMITS_F_U16 | Com_u16NO_OF_LIMITS_F_S16 | Com_u16NO_OF_LIMITS_F_U32 | Com_u16NO_OF_LIMITS_F_S32) > 0u
    u16FilterIx = Com_akstreSignalLT[u16SigIx].u16FilterIndex;
	u16SpecificFilterIndex = u16GET_SPECIFIC_FLTR_IX(u16FilterIx);
#endif
    break;
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
    case Com_u8SIG_STRUCT_GROUPSIG:
    pkstrLocGrpSigPB = pkstrGET_PBGRPSIGPTR_IX(u16SigIx) ;
    /* PRQA S 3746 ++ */
    /* PRQA S 3746 -- */
    u8SigType     = pkstrLocGrpSigPB->u8SignalType ;
#if (Com_u16NO_OF_MASK_F_B | Com_u16NO_OF_LIMITS_F_U8 | Com_u16NO_OF_LIMITS_F_S8 | Com_u16NO_OF_LIMITS_F_U16 | Com_u16NO_OF_LIMITS_F_S16 | Com_u16NO_OF_LIMITS_F_U32 | Com_u16NO_OF_LIMITS_F_S32) > 0u
    u16FilterIx = Com_akstreGroupSignalLT[u16SigIx].u16FilterIndex;
	u16SpecificFilterIndex = u16GRPSIG_SPCFC_FLTR_IX(u16FilterIx);
#endif
    break;
#endif

#if (Com_bGW_DESC_SUPPORT == STD_ON)
    case Com_u8GW_STRUCT_DST_DESC:
    pkstrLocDstDscPB = pkstrGET_PBDSTDESCPTR_IX(u16SigIx) ;
    u8SigType     = pkstrLocDstDscPB->u8SignalType ;
#if (Com_u16NO_OF_MASK_F_B | Com_u16NO_OF_LIMITS_F_U8 | Com_u16NO_OF_LIMITS_F_S8 | Com_u16NO_OF_LIMITS_F_U16 | Com_u16NO_OF_LIMITS_F_S16 | Com_u16NO_OF_LIMITS_F_U32 | Com_u16NO_OF_LIMITS_F_S32) > 0u
    u16SpecificFilterIndex = u16DST_SPECIFIC_FLTR_IX(pkstrLocDstDscPB->u16FilterIndex);
#endif
    break;
#endif

    default:
    /*  Com_u8GW_STRUCT_SRC_DESC has no configured filter*/     
    u8SigType = (uint8)0xFFU;
#if (Com_u16NO_OF_MASK_F_B | Com_u16NO_OF_LIMITS_F_U8 | Com_u16NO_OF_LIMITS_F_S8 | Com_u16NO_OF_LIMITS_F_U16 | Com_u16NO_OF_LIMITS_F_S16 | Com_u16NO_OF_LIMITS_F_U32 | Com_u16NO_OF_LIMITS_F_S32) > 0u
    u16SpecificFilterIndex = (uint16)0;    
#endif
    break;

   }
   bFiltrRes = TRUE;
   switch (u8SigType)
   {
      case Com_u8SIGNAL_TYPE_BOOLEAN:
      #if Com_u16NO_OF_MASK_F_B > 0u
        if( (*(P2CONST(boolean,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr &
        (Com_akstreMaskFilterB[u16SpecificFilterIndex].bFilterMask)) ==
        (Com_akstreMaskFilterB[u16SpecificFilterIndex].bFilterX))
           {
              bFiltrRes = TRUE;
           }
           else
           {
              bFiltrRes = FALSE;
           }
      #endif
      break;

      case Com_u8SIGNAL_TYPE_UINT8:
      #if Com_u16NO_OF_MASK_F_U8 > 0u
        if( (*(P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr &
        (Com_akstreMaskFilterU8[u16SpecificFilterIndex].u8FilterMask)) ==
        (Com_akstreMaskFilterU8[u16SpecificFilterIndex].u8FilterX))
        {
           bFiltrRes = TRUE;
        }
        else
        {
           bFiltrRes = FALSE;
        }
      #endif
      break;

      case Com_u8SIGNAL_TYPE_SINT8:
      #if Com_u16NO_OF_MASK_F_S8 > 0u
        if( (uint8)(*(P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr &
        (uint8)(Com_akstreMaskFilterS8[u16SpecificFilterIndex].s8FilterMask)) ==
        (uint8)(Com_akstreMaskFilterS8[u16SpecificFilterIndex].s8FilterX))
        {
           bFiltrRes = TRUE;
        }
        else
        {
           bFiltrRes = FALSE;
        }
      #endif
      break;

      case Com_u8SIGNAL_TYPE_UINT16:
      #if Com_u16NO_OF_MASK_F_U16 > 0u
        if( (*(P2CONST(uint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr &
        (Com_akstreMaskFilterU16[u16SpecificFilterIndex].u16FilterMask)) ==
        (Com_akstreMaskFilterU16[u16SpecificFilterIndex].u16FilterX))
        {
           bFiltrRes = TRUE;
        }
        else
        {
           bFiltrRes = FALSE;
        }
      #endif
      break;

      case Com_u8SIGNAL_TYPE_SINT16:
      #if Com_u16NO_OF_MASK_F_S16 > 0u
        if( (uint16)((*(P2CONST(uint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr) &
        ((uint16)(Com_akstreMaskFilterS16[u16SpecificFilterIndex].s16FilterMask))) ==
        ((uint16)(Com_akstreMaskFilterS16[u16SpecificFilterIndex].s16FilterX)))
        {
           bFiltrRes = TRUE;
        }
        else
        {
           bFiltrRes = FALSE;
        }
      #endif
      break;

      case Com_u8SIGNAL_TYPE_UINT32:
      #if Com_u16NO_OF_MASK_F_U32 > 0u
        if( (*(P2CONST(uint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr &
        (Com_akstreMaskFilterU32[u16SpecificFilterIndex].u32FilterMask)) ==
        (Com_akstreMaskFilterU32[u16SpecificFilterIndex].u32FilterX))
        {
           bFiltrRes = TRUE;
        }
        else
        {
           bFiltrRes = FALSE;
        }
      #endif
      break;

      case Com_u8SIGNAL_TYPE_SINT32:
      #if Com_u16NO_OF_MASK_F_S32 > 0u
        if( (*(P2CONST(uint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr &
        (uint32)(Com_akstreMaskFilterS32[u16SpecificFilterIndex].s32FilterMask)) ==
        (uint32)(Com_akstreMaskFilterS32[u16SpecificFilterIndex].s32FilterX))
        {
           bFiltrRes = TRUE;
        }
        else
        {
           bFiltrRes = FALSE;
        }
      #endif
      break;

      default:
      break;
   }
   return bFiltrRes;
}
/*PRQA S 3205, 3199, 3203 -- */
/* PRQA S 4700 -- */
/* PRQA S 0781 --                                                             */

/* PRQA S 0781 ++                                                             */
/* !Deviation : Inhibit MISRA rule [3673]: There is no need to change pointer to variable   */
/*to pointer to constant because the function used is an internal function                    */

/* !Deviation: [4700]  ( here has been an infringement of a threshold on the specified metric)
The bEvalMskNewOldFltrAlg function deviate the complexity threshold, but no more division/simplification can be done
for performance issues*/
/* PRQA S 4700 ++ */
/* !Deviation: [3205]  ( Some of the varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S 3205, 3199, 3203 ++ */
/* !Deviation: [3206]  ( Some of the input parameters are not used 
in this function depending on the configuration.) */
/*PRQA S 3206 ++ */
static FUNC(boolean,COM_CODE) bEvalMskNewOldFltrAlg (
                       VAR(Com_SignalIdType,AUTOMATIC) u16SigIx,
#if (Com_u16NO_OF_MASK_OLD_F_B | Com_u16NO_OF_MASK_OLD_F_U8 | Com_u16NO_OF_MASK_OLD_F_S8 | Com_u16NO_OF_MASK_OLD_F_U16 | Com_u16NO_OF_MASK_OLD_F_S16 | Com_u16NO_OF_MASK_OLD_F_U32 | Com_u16NO_OF_MASK_OLD_F_S32) > 0u
                       P2CONST(void,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pkvidSigDataPtr,
#endif
                       VAR(uint8,AUTOMATIC)            u8SigStrcture
					   )
/*PRQA S 3206 -- */
{
 /* !Deviation: [8018]  (The name of the constant (const) doesn't respect the naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */
  P2CONST(Com_tstrSignalPB,AUTOMATIC,COM_CALIB_CONST)   	pkstrLocSigPB;
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
  P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,COM_CALIB_CONST)  pkstrLocGrpSigPB;
#endif

#if (Com_bGW_DESC_SUPPORT == STD_ON)
  P2CONST(Com_tstrGWDstDesc,AUTOMATIC,COM_CALIB_CONST) 		pkstrLocDstDscPB;   
#endif

/*PRQA S 8018 , 8318, 8518  -- */
   VAR(boolean,AUTOMATIC)                                	bFiltrRes;
#if Com_u16NO_OF_MASK_OLD_F_B || Com_u16NO_OF_MASK_OLD_F_U8 || Com_u16NO_OF_MASK_OLD_F_S8 || Com_u16NO_OF_MASK_OLD_F_U16 || Com_u16NO_OF_MASK_OLD_F_S16 || Com_u16NO_OF_MASK_OLD_F_U32 || Com_u16NO_OF_MASK_OLD_F_S32 > 0u
   VAR(uint16, AUTOMATIC)                                	u16SpecificFilterIndex;
#endif
   VAR(uint8,AUTOMATIC)                                     u8SigType;
   VAR(uint16,AUTOMATIC)                                    u16FilterIx;
   
   switch(u8SigStrcture)
   {
    case Com_u8SIG_STRUCT_SIG:
   /*get the signal type*/
    pkstrLocSigPB = pkstrGET_PBSIGPTR_IX(u16SigIx);
    /* PRQA S 3746 ++ */
    u16FilterIx = Com_akstreSignalLT[u16SigIx].u16FilterIndex;
    /* PRQA S 3746 -- */
    u8SigType     = pkstrLocSigPB->u8SignalType ;
#if Com_u16NO_OF_MASK_OLD_F_B || Com_u16NO_OF_MASK_OLD_F_U8 || Com_u16NO_OF_MASK_OLD_F_S8 || Com_u16NO_OF_MASK_OLD_F_U16 || Com_u16NO_OF_MASK_OLD_F_S16 || Com_u16NO_OF_MASK_OLD_F_U32 || Com_u16NO_OF_MASK_OLD_F_S32 > 0u
    u16SpecificFilterIndex = u16GET_SPECIFIC_FLTR_IX(u16FilterIx);
#endif
    break;

#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
    case Com_u8SIG_STRUCT_GROUPSIG:
    pkstrLocGrpSigPB = pkstrGET_PBGRPSIGPTR_IX(u16SigIx) ;
    /* PRQA S 3746 ++ */
    u16FilterIx = Com_akstreGroupSignalLT[u16SigIx].u16FilterIndex;
    /* PRQA S 3746 -- */
    u8SigType     = pkstrLocGrpSigPB->u8SignalType ;
#if Com_u16NO_OF_MASK_OLD_F_B || Com_u16NO_OF_MASK_OLD_F_U8 || Com_u16NO_OF_MASK_OLD_F_S8 || Com_u16NO_OF_MASK_OLD_F_U16 || Com_u16NO_OF_MASK_OLD_F_S16 || Com_u16NO_OF_MASK_OLD_F_U32 || Com_u16NO_OF_MASK_OLD_F_S32 > 0u
    u16SpecificFilterIndex = u16GRPSIG_SPCFC_FLTR_IX(u16FilterIx);
#endif
    break;
#endif

#if (Com_bGW_DESC_SUPPORT == STD_ON)
    case Com_u8GW_STRUCT_DST_DESC:
    pkstrLocDstDscPB = pkstrGET_PBDSTDESCPTR_IX(u16SigIx) ;
    u8SigType     = pkstrLocDstDscPB->u8SignalType ;
#if Com_u16NO_OF_MASK_OLD_F_B || Com_u16NO_OF_MASK_OLD_F_U8 || Com_u16NO_OF_MASK_OLD_F_S8 || Com_u16NO_OF_MASK_OLD_F_U16 || Com_u16NO_OF_MASK_OLD_F_S16 || Com_u16NO_OF_MASK_OLD_F_U32 || Com_u16NO_OF_MASK_OLD_F_S32 > 0u
    u16SpecificFilterIndex = u16DST_SPECIFIC_FLTR_IX(pkstrLocDstDscPB->u16FilterIndex);
#endif
    break;
#endif


    default:
    /* Com_u8GW_STRUCT_SRC_DESC has no configured filter*/     
    u8SigType = (uint8)0xFFU ;
#if Com_u16NO_OF_MASK_OLD_F_B || Com_u16NO_OF_MASK_OLD_F_U8 || Com_u16NO_OF_MASK_OLD_F_S8 || Com_u16NO_OF_MASK_OLD_F_U16 || Com_u16NO_OF_MASK_OLD_F_S16 || Com_u16NO_OF_MASK_OLD_F_U32 || Com_u16NO_OF_MASK_OLD_F_S32 > 0u
    u16SpecificFilterIndex = (uint16)0;
#endif
    break;

   }


   bFiltrRes = TRUE;
   switch (u8SigType)
   {
      case Com_u8SIGNAL_TYPE_BOOLEAN:
      #if Com_u16NO_OF_MASK_OLD_F_B > 0u
        if(((*(P2CONST(boolean,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr)&(Com_akstreMaskOldFilterB[u16SpecificFilterIndex].bFilterMask))
               /*masked new value*/
           !=
               /*masked old value*/
           ((Com_abeFilterOldValueB[Com_akstreMaskOldFilterB[u16SpecificFilterIndex].u16OldValueIndex]) &
           (Com_akstreMaskOldFilterB[u16SpecificFilterIndex].bFilterMask)))
        {
           bFiltrRes = TRUE;
       /*update the old value in the corresponding array*/
       Com_abeFilterOldValueB[Com_akstreMaskOldFilterB[u16SpecificFilterIndex].u16OldValueIndex] =
       *(P2CONST(boolean,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr ;

        }
        else
        {
           bFiltrRes = FALSE;
        }
      #endif
      break;

      case Com_u8SIGNAL_TYPE_UINT8:
      #if Com_u16NO_OF_MASK_OLD_F_U8 > 0u
        if(((*(P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr)&(Com_akstreMaskOldFilterU8[u16SpecificFilterIndex].u8FilterMask))
               /*masked new value*/
           !=
               /*masked old value*/
           ((Com_au8eFilterOldValueU8[Com_akstreMaskOldFilterU8[u16SpecificFilterIndex].u16OldValueIndex]) &
           (Com_akstreMaskOldFilterU8[u16SpecificFilterIndex].u8FilterMask)))
         {
           bFiltrRes = TRUE;
       Com_au8eFilterOldValueU8[Com_akstreMaskOldFilterU8[u16SpecificFilterIndex].u16OldValueIndex] =
       *(P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr;
         }
         else
         {
           bFiltrRes = FALSE;
         }
      #endif
      break;

      case Com_u8SIGNAL_TYPE_SINT8:
      #if Com_u16NO_OF_MASK_OLD_F_S8 > 0u
        if(((*(P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr)&(uint8)(Com_akstreMaskOldFilterS8[u16SpecificFilterIndex].s8FilterMask))
               /*masked new value*/
           !=
               /*masked old value*/
          ((uint8)(Com_as8eFilterOldValueS8[Com_akstreMaskOldFilterS8[u16SpecificFilterIndex].u16OldValueIndex]) &
          (uint8)(Com_akstreMaskOldFilterS8[u16SpecificFilterIndex].s8FilterMask)))
        {
           bFiltrRes = TRUE;
       Com_as8eFilterOldValueS8[Com_akstreMaskOldFilterS8[u16SpecificFilterIndex].u16OldValueIndex] =
       *(P2CONST(sint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr ;
        }
        else
        {
           bFiltrRes = FALSE;
        }
      #endif
      break;

      case Com_u8SIGNAL_TYPE_UINT16:
      #if Com_u16NO_OF_MASK_OLD_F_U16 > 0u
        if(((*(P2CONST(uint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr)&(Com_akstreMaskOldFilterU16[u16SpecificFilterIndex].u16FilterMask))
               /*masked new value*/
           !=
               /*masked old value*/
           (Com_au16eFilterOldValueU16[Com_akstreMaskOldFilterU16[u16SpecificFilterIndex].u16OldValueIndex] &
           (Com_akstreMaskOldFilterU16[u16SpecificFilterIndex].u16FilterMask)))
        {
           bFiltrRes = TRUE;
       Com_au16eFilterOldValueU16[Com_akstreMaskOldFilterU16[u16SpecificFilterIndex].u16OldValueIndex] =
       *(P2CONST(uint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr ;
        }
        else
        {
           bFiltrRes = FALSE;
        }
      #endif
      break;

      case Com_u8SIGNAL_TYPE_SINT16:
      #if Com_u16NO_OF_MASK_OLD_F_S16 > 0u
        if(((*(P2CONST(uint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr)&(uint16)(Com_akstreMaskOldFilterS16[u16SpecificFilterIndex].s16FilterMask))
               /*masked new value*/
           !=
               /*masked old value*/
           ((uint16)(Com_as16eFilterOldValueS16[Com_akstreMaskOldFilterS16[u16SpecificFilterIndex].u16OldValueIndex]) &
         (uint16)(Com_akstreMaskOldFilterS16[u16SpecificFilterIndex].s16FilterMask)))
        {
           bFiltrRes = TRUE;
       Com_as16eFilterOldValueS16[Com_akstreMaskOldFilterS16[u16SpecificFilterIndex].u16OldValueIndex] =
       *(P2CONST(sint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr;
        }
        else
        {
           bFiltrRes = FALSE;
        }
      #endif
      break;

      case Com_u8SIGNAL_TYPE_UINT32:
      #if Com_u16NO_OF_MASK_OLD_F_U32 > 0u
        if(((*(P2CONST(uint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr)&(Com_akstreMaskOldFilterU32[u16SpecificFilterIndex].u32FilterMask))
               /*masked new value*/
           !=
               /*masked old value*/
           (Com_au32eFilterOldValueU32[Com_akstreMaskOldFilterU32[u16SpecificFilterIndex].u16OldValueIndex] &
           (Com_akstreMaskOldFilterU32[u16SpecificFilterIndex].u32FilterMask)))
        {
           bFiltrRes = TRUE;
       Com_au32eFilterOldValueU32[Com_akstreMaskOldFilterU32[u16SpecificFilterIndex].u16OldValueIndex] =
       *(P2CONST(uint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr ;
        }
        else
        {
           bFiltrRes = FALSE;
        }
      #endif
      break;

      case Com_u8SIGNAL_TYPE_SINT32:
      #if Com_u16NO_OF_MASK_OLD_F_S32 > 0u
         if(((*(P2CONST(uint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr)&(uint32)(Com_akstreMaskOldFilterS32[u16SpecificFilterIndex].s32FilterMask))
               /*masked new value*/
           !=
               /*masked old value*/
            ((uint32)(Com_as32eFilterOldValueS32[Com_akstreMaskOldFilterS32[u16SpecificFilterIndex].u16OldValueIndex]) &
            (uint32)(Com_akstreMaskOldFilterS32[u16SpecificFilterIndex].s32FilterMask)))
        {
           bFiltrRes = TRUE;
       Com_as32eFilterOldValueS32[Com_akstreMaskOldFilterS32[u16SpecificFilterIndex].u16OldValueIndex] =
       *(P2CONST(sint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSigDataPtr ;
        }
        else
        {
           bFiltrRes = FALSE;
        }
      #endif
      break;

      default:
/*do nothing ,bFiltrRes already initialized to TRUE*/

      break;
    }

    return bFiltrRes;
}
/*PRQA S 3205, 3199, 3203 -- */
/* PRQA S 4700 -- */
/* PRQA S 0781 --                                                             */


#if (Com_bUBIT_SUPPORT == STD_ON)
/*! \Trace_To : Com-CDD-SignalIpduServices-0259(0) , Com-CDD-SignalIpduServices-5540(0) ,
Com-CDD-SignalIpduServices-5542(0) , */
 FUNC(boolean,COM_CODE) Com_bSignalCheckUpdateBit (
                       P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)  pku8IpduFirstByte,
					   VAR(uint16,AUTOMATIC)                        u16UBIx)
 {
    VAR(boolean,AUTOMATIC)  bUpdateBit;
    VAR(uint16,AUTOMATIC)   u16BytePosition;
    VAR(uint8, AUTOMATIC)   u8BitPosition;
	 
	u16BytePosition = (u16UBIx)>> 3;
    u8BitPosition = (uint8)((u16UBIx) -
                        (u16BytePosition << 3)) ;
    bUpdateBit = (boolean)((pku8IpduFirstByte[u16BytePosition] & u8GET_BIT_MASK(u8BitPosition))>>u8BitPosition);

    return bUpdateBit;
 }

#endif 
/*shall only be used for TX Ipdus*/


#if (Com_bUBIT_SUPPORT == STD_ON)
/*! \Trace_To : Com-CDD-SignalIpduServices-0535(0) , Com-CDD-SignalIpduServices-0536(0) , 
Com-CDD-SignalIpduServices-0538(0) ,
		Com-CDD-0437(0) , Com-CDD-0438(0) ,
		Com-CDD-0439(0) , Com-CDD-0441(0) ,
		Com-CDD-0440(0) , Com-CDD-0442(0) ,
		Com-CDD-0443(0) , Com-CDD-SignalIpduServices-0261(0) */
 FUNC(void,COM_CODE) Com_vidSignalEditUpdateBit (
                    VAR(Com_tu8SignalContainerType,AUTOMATIC) u8SigContainer ,
                    VAR(uint16,AUTOMATIC)              u16Index,
					VAR(uint16,AUTOMATIC)              u16UpdateBitPosition,
                    VAR(boolean,AUTOMATIC)             bValue )
 {
    VAR(uint16,AUTOMATIC)                             u16BytePosition;
    VAR(uint8, AUTOMATIC)                             u8BitPosition;
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA)              pu8IpduFirstByte;
    VAR(uint16,AUTOMATIC)                             u16IpduId;
/* !Deviation: [8018]  (The name of the constant (const) doesn't respect the naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518 ++ */
    P2CONST(Com_tstrTxIPdu,AUTOMATIC,COM_CALIB_CONST) pkstrLocTXIpduPB;
    P2CONST(Com_tstrRxIPdu,AUTOMATIC,COM_CALIB_CONST) pkstrLocRXIpduPB;    
	P2CONST(Com_tstrSignalPB,AUTOMATIC,COM_CALIB_CONST) pkstrLocSigPB;
#if (Com_bGW_DESC_SUPPORT == STD_ON)
	P2CONST(Com_tstrGWDstDesc,AUTOMATIC,COM_CALIB_CONST) pkstrLocDesDscPB;
#endif

#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
	P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,TYPEDEF)      pkstrSigGroupPB;
#endif
/*PRQA S 8018 , 8318, 8518 -- */
    switch (u8SigContainer)
    {

      case Com_u8SIGNAL:
		pkstrLocSigPB =   pkstrGET_PBSIGPTR_IX(u16Index);
        u16BytePosition = (u16UpdateBitPosition) >> 3u;
		u8BitPosition = (uint8)(u16UpdateBitPosition & (uint16)7);
        u16IpduId = pkstrLocSigPB->u16IPduIndex;
        
      break;
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)
      case Com_u8SIGNALGROUP:
		pkstrSigGroupPB =  pkstrGET_PB_SIGNAL_GROUP(u16Index);
        u16BytePosition = (u16UpdateBitPosition) >> 3u;
		u8BitPosition = (uint8)(u16UpdateBitPosition & (uint16)7);

        u16IpduId = pkstrSigGroupPB->u16IPduIndex;

      break;
#endif

#if (Com_bGW_DESC_SUPPORT == STD_ON)
      case Com_u8SIG_STRUCT_DSTDESC:
		pkstrLocDesDscPB = pkstrGET_PBDSTDESCPTR_IX(u16Index);
        u16BytePosition = (u16UpdateBitPosition) >> 3u;
		u8BitPosition = (uint8)(u16UpdateBitPosition & (uint16)7);

        u16IpduId = pkstrLocDesDscPB->u16IPduIndex;

      break;
#endif
      default:
      /*no use case to edit the UB of a Com_u8SIG_STRUCT_SRCDESC*/
      /*shall not enter here */
      u16IpduId = (uint16)0 ;
      u8BitPosition = (uint8)0;
      u16BytePosition = (uint16)0;
      break;
    }
    if (bGET_IPDU_DIRECTION(u16IpduId) == Com_u8DIRECTION_TX )
    {      
      pkstrLocTXIpduPB = pkstrGET_TX_IPDU_PTR(u16IpduId);
      pu8IpduFirstByte = pkstrGET_IPDU_BUFF_PTR(pkstrLocTXIpduPB->u32IPduBufferIndex);
    }
    else
    {
      pkstrLocRXIpduPB = pkstrGET_RX_IPDU_PTR(u16IpduId);
      pu8IpduFirstByte = pkstrGET_IPDU_BUFF_PTR(pkstrLocRXIpduPB->u32IPduBufferIndex);    
    }
    if (bValue == (boolean)1u)
    {
       SchM_Enter_Com_IPduBuff();
       vidSET_BIT_MASK(pu8IpduFirstByte[u16BytePosition], u8GET_BIT_MASK(u8BitPosition));
       SchM_Exit_Com_IPduBuff();
    }
    else
    /*bValue == 0*/
    {
       SchM_Enter_Com_IPduBuff();
       vidCLR_BIT_MASK(pu8IpduFirstByte[u16BytePosition], (uint8)u8GET_BIT_MASK(u8BitPosition));
       SchM_Exit_Com_IPduBuff();
    }


 }

 #endif
 

#if (Com_bIPDU_COUNTER_SUPPORT == STD_ON)
 /*! \Trace_To : Com-CDD-SignalIpduServices-0051(0) ,  Com-CDD-SignalIpduServices-0400(0) ,
 Com-CDD-SignalIpduServices-0053(0) , Com-CDD-SignalIpduServices-5668(0) , Com-CDD-5746(0), Com-CDD-5745(1),
   */
/* !Deviation: [3203]  ( Some of the varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S  3199, 3203 ++ */
/* PRQA S 0781 ++                                                             */
/* !Deviation : Inhibit MISRA rule [3673]: There is no need to change pointer to variable   */
/*to pointer to constant because the function used is an internal function                    */

 FUNC(Std_ReturnType,COM_CODE) Com_u8IpduCheckDataSeq (
                              VAR(uint16,AUTOMATIC)                     u16IPduIx,
                              P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)       pku8IpduFirstByte)
 {
    VAR(uint16,AUTOMATIC)                             u16CtrBytePosition;
    VAR(uint8, AUTOMATIC)                             u8CtrBitPosition;
    VAR(uint8, AUTOMATIC)                             u8RxIpduCtrVal;
    VAR(Std_ReturnType , AUTOMATIC)                   u8DataSeq;
    VAR(uint8, AUTOMATIC)                             u8SuitableMask;
    VAR(uint8, AUTOMATIC)                             u8CtrExpectedVal;
    VAR(uint8, AUTOMATIC)                             u8CtrThreshold;
    VAR(uint16,AUTOMATIC)                             u16IPduCtrIx;
    VAR(PduIdType,AUTOMATIC)                             u16IPduId;
    
#if (Com_u16NO_OF_COUNTER_ERR > 0u)  
/* !Deviation: [8018]  (The name of the constant (const) doesn't respect the naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518 ++ */
    P2CONST(Com_tstrRxIPdu,AUTOMATIC,COM_CALIB_CONST) pkstrLocRXIpduPB;
	P2CONST(Com_tstrIPduCounter,AUTOMATIC,COM_CALIB_CONST) pkstrIPduCtr;
/*PRQA S 8018 , 8318, 8518 -- */
    
	pkstrLocRXIpduPB = pkstrGET_RX_IPDU_PTR_IX(u16IPduIx);
	
	u16IPduCtrIx = pkstrLocRXIpduPB->u16IPduCounterIndex;
	pkstrIPduCtr = pkstrGET_IPDU_CTR_PTR(u16IPduCtrIx);
    u16CtrBytePosition = pkstrIPduCtr->u16IPduCounterStartPos >> 3u;
    u8CtrBitPosition = (uint8)(pkstrIPduCtr->u16IPduCounterStartPos -  (u16CtrBytePosition<< 3u));
    u8SuitableMask = u8MASK_CERTAIN_BITS(u8CtrBitPosition,pkstrIPduCtr->u8IPduCounterSize);

    SchM_Enter_Com_IPduBuff();
    u8RxIpduCtrVal =  (uint8)(pku8IpduFirstByte[u16CtrBytePosition] & u8SuitableMask) >>u8CtrBitPosition ;
    SchM_Exit_Com_IPduBuff();
    u8SuitableMask = u8SuitableMask >>u8CtrBitPosition ;

#if Com_u16NO_OF_IPDU_COUNTER > 0u
    u8CtrExpectedVal = Com_au8eIPduCounterRam[u16IPduCtrIx];
#endif

    u8CtrThreshold = pkstrIPduCtr->u8IPduCounterThreshold;

    u16IPduId = pkstrLocRXIpduPB->u16IPduId;
#if u16NO_OF_IPDUS_STATUS > 0u
    SchM_Enter_Com_IPduStatus_18();    
    SchM_Enter_Com_IPduStatus_42();
    SchM_Enter_Com_IPduStatus_1E();
    if((Com_audteIPduStatus[u16IPduId] & Com_u8CTR_ACC_ANY) != (boolean)FALSE)
    {   
        /*accept Com_u8CTR_ACC_ANY flag is set*/
       u8DataSeq = E_OK;
       /*clear Com_u8CTR_ACC_ANY flag */
       Com_audteIPduStatus[u16IPduId] &= (Com_udtIPduStatus)(~Com_u8CTR_ACC_ANY);
       SchM_Exit_Com_IPduStatus_1E();
       SchM_Exit_Com_IPduStatus_42();
       SchM_Exit_Com_IPduStatus_18();      
    }
    else
    {
	   SchM_Exit_Com_IPduStatus_1E();
	   SchM_Exit_Com_IPduStatus_42();
       SchM_Exit_Com_IPduStatus_18();
 /* !Deviation: [3356]  ( The value of this control expression is always 'false' due to 
 some special configuration but in the normal case this part is normally reachable.) */
/*PRQA S 3356, 3359,3201  ++ */
       if (((u8CtrExpectedVal+ u8CtrThreshold) & u8SuitableMask) < u8CtrExpectedVal )
      {
/*PRQA S 3356, 3359,3201  -- */
       /*a wrap arround will occures*/
         if ((u8RxIpduCtrVal<= ((u8CtrExpectedVal+ u8CtrThreshold)& u8SuitableMask) )||
            (u8RxIpduCtrVal>=u8CtrExpectedVal))
         {
            u8DataSeq = E_OK;
         }
         else
         {
            u8DataSeq = E_NOT_OK;
         }
      }
      else
      {
      /*check if the received I-PDU counter  was greater than the expected one or less than the
      expected I-PDU counter + ComIPduCounterThreshold */
        if ((u8RxIpduCtrVal >=u8CtrExpectedVal)
        && (u8RxIpduCtrVal <= (u8CtrExpectedVal+ u8CtrThreshold)))
        {
           u8DataSeq = E_OK;
        }
        else
        {
           u8DataSeq = E_NOT_OK;
        }
      }
      if (u8DataSeq == E_NOT_OK)
      /*counter error has happened*/
      {

        #if Com_u16NO_OF_COUNTER_ERR > 0u
        Com_akpfvideIPduCounterErrNotif[(pkstrLocRXIpduPB->u16IPduCounterIndex)]
                                        (u16IPduId , u8CtrExpectedVal , u8RxIpduCtrVal) ;
        #endif
      }
      else
      {
      /*do nothing */
      }

    }

#endif

    #if Com_u16NO_OF_IPDU_COUNTER > 0u
    Com_au8eIPduCounterRam[u16IPduCtrIx] = (u8RxIpduCtrVal +(uint8)1) & u8SuitableMask ;
    #endif
#endif
    return u8DataSeq;
 }
/*PRQA S  3199, 3203 -- */
/* PRQA S 0781 --                                                             */

#endif


#if (Com_bIPDU_COUNTER_SUPPORT == STD_ON)
/*! \Trace_To : Com-CDD-SignalIpduServices-0136(0) */
 FUNC(void,COM_CODE) Com_vidIpduPackDataSeq (
                    VAR(PduIdType,AUTOMATIC) u16IPduId)
 {
    /*local variable declaration*/
    VAR(uint16,AUTOMATIC)                             u16CtrBytePosition;
    VAR(uint8, AUTOMATIC)                             u8CtrBitPosition;
    VAR(uint32,AUTOMATIC)                             u32IpduRamBufferIndex;
	P2VAR(uint8,AUTOMATIC,TYPEDEF)					  pu8IPduBuf;
/*PRQA S 8018 , 8318, 8518 ++ */
	P2CONST(Com_tstrIPduCounter,AUTOMATIC,COM_CALIB_CONST) pkstrIPduCtr;
	P2CONST(Com_tstrTxIPdu,AUTOMATIC,COM_CALIB_CONST)   pkstrLocTXIpduPB;
/*PRQA S 8018 , 8318, 8518 -- */
	VAR(uint16,AUTOMATIC)                             u16IPduCtrIx;
   
	
	 pkstrLocTXIpduPB = pkstrGET_TX_IPDU_PTR(u16IPduId);
	 u16IPduCtrIx = pkstrLocTXIpduPB->u16IPduCounterIndex;
#if Com_u16NO_OF_IPDU_COUNTER > 0u
	 pkstrIPduCtr = pkstrGET_IPDU_CTR_PTR(u16IPduCtrIx);
#endif    
	 u16CtrBytePosition = pkstrIPduCtr->u16IPduCounterStartPos>> 3u;
     u8CtrBitPosition =  (uint8)(pkstrIPduCtr->u16IPduCounterStartPos -   (u16CtrBytePosition << 3u)) ;

      u32IpduRamBufferIndex = pkstrLocTXIpduPB->u32IPduBufferIndex + (uint32)u16CtrBytePosition;
	  pu8IPduBuf = pkstrGET_IPDU_BUFF_PTR(0);
     /*Clear the place of the corresponding counter part in the IPDU buffer byte */
     SchM_Enter_Com_IPduBuff();
     pu8IPduBuf[u32IpduRamBufferIndex] &=
     (uint8)(u8MASK_CERTAIN_BITS(u8CtrBitPosition,pkstrIPduCtr->u8IPduCounterSize)^(uint8)0xFFu)  ;

     /*pack the counter value*/

#if Com_u16NO_OF_IPDU_COUNTER > 0u
     pu8IPduBuf[u32IpduRamBufferIndex] |=
     (uint8)(((Com_au8eIPduCounterRam[u16IPduCtrIx] )
     &(u8MASK_CERTAIN_BITS(0,pkstrIPduCtr->u8IPduCounterSize))) << u8CtrBitPosition);
/*  PRQA S 4130 -- */ 
#endif

     SchM_Exit_Com_IPduBuff();
     /*set the new value of the counter with respect to wrap arround*/
     #if Com_u16NO_OF_IPDU_COUNTER > 0u
     Com_au8eIPduCounterRam[u16IPduCtrIx] = ((Com_au8eIPduCounterRam[u16IPduCtrIx])+(uint8)1u)
                                          & (u8MASK_CERTAIN_BITS(0,pkstrIPduCtr->u8IPduCounterSize));
     #endif

 }
#endif
 /* !Deviation: [4700]  ( here has been an infringement of a threshold on the
specified metric)
Further decomposition of this function will affect its overall performance 
so no other meaningfull division is required*/
/*  PRQA S 4700 ++ */     
/* !Deviation: [3202]  ( Some of the varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S  3199, 3203 ++ */
/* !Deviation: [3206]  ( Some of the input parameters are not used 
in this function depending on the configuration.) */
/*PRQA S 3206 ++ */
#if (Com_bDATA_INVALID_SUPPORT == STD_ON)  
static FUNC(boolean,COM_CODE) bCheckSigIsValid (
                       VAR(uint16,AUTOMATIC)       u16SigInvalidIx,
#if Com_u16SIG_INV_V_B_SIZE || Com_u16SIG_INV_V_U8U8N_SIZE || Com_u16SIG_INV_V_S8_SIZE || Com_u16SIG_INV_V_U16_SIZE || Com_u16SIG_INV_V_S16_SIZE || Com_u8SIGNAL_TYPE_UINT32 || Com_u8SIGNAL_TYPE_SINT32 || Com_u16SIG_INV_V_F32_SIZE || Com_u16SIG_INV_V_F64_SIZE > 0u
                       P2CONST(void,AUTOMATIC,COM_APPL_DATA) pkvidSigTempVal,
#endif
                       VAR(uint8,AUTOMATIC)    u8SigType
					   )
/*PRQA S 3206 ++ */					   
{
 /*local variable declaration*/
 /* !Deviation: [8018]  (The name of the constant (const) doesn't respect the naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming conventions.)*/
/*Limitation in the current QAC check , the name is correct*/

   VAR(boolean,AUTOMATIC)                                bSigIsValid;

  bSigIsValid = TRUE;
 /* !Deviation: [3356]  ( The value of this control expression is always 'false' due to 
 some special configuration but in the normal case this part is normally reachable.) */
/*PRQA S 3356, 3359,3201  ++ */
   if (u16SigInvalidIx != (uint16)0xFFFFu)
   {
/*PRQA S 3356, 3359,3201  -- */   
     switch (u8SigType)
     {
        case Com_u8SIGNAL_TYPE_BOOLEAN:
        #if Com_u16SIG_INV_V_B_SIZE > 0u
          if (*(P2CONST(boolean,AUTOMATIC,COM_APPL_DATA))pkvidSigTempVal ==
             Com_akbeSigInvalidValB[u16SigInvalidIx])
          {
           /*signal is invalid*/
           bSigIsValid = FALSE;
          }
          else
          {
          /*do nothing , the bSigIsValid is already initialized to TRUE */
          }
        #endif
        break;

        case Com_u8SIGNAL_TYPE_UINT8:
        #if Com_u16SIG_INV_V_U8U8N_SIZE > 0u
          if (*(P2CONST(uint8,AUTOMATIC,COM_APPL_DATA))pkvidSigTempVal ==
             Com_aku8eSigInvalidValU8U8N[u16SigInvalidIx])
          {
           /*signal is invalid*/
           bSigIsValid = FALSE;
          }
          else
          {
          /*do nothing , the bSigIsValid is already initialized to TRUE */
          }
        #endif
        break;

        case Com_u8SIGNAL_TYPE_SINT8:
        #if Com_u16SIG_INV_V_S8_SIZE > 0u
          if (*(P2CONST(sint8,AUTOMATIC,COM_APPL_DATA))pkvidSigTempVal ==
           Com_aks8eSigInvalidValS8[u16SigInvalidIx])
          {
           /*signal is invalid*/
           bSigIsValid = FALSE;
          }
          else
          {
          /*do nothing , the bSigIsValid is already initialized to TRUE */
          }
        #endif
        break;

        case Com_u8SIGNAL_TYPE_UINT16:
        #if Com_u16SIG_INV_V_U16_SIZE > 0u
          if (*(P2CONST(uint16,AUTOMATIC,COM_APPL_DATA))pkvidSigTempVal ==
          Com_aku16eSigInvalidValU16[u16SigInvalidIx])
          {
           /*signal is invalid*/
           bSigIsValid = FALSE;
          }
          else
          {
          /*do nothing , the bSigIsValid is already initialized to TRUE */
          }
        #endif
        break;

        case Com_u8SIGNAL_TYPE_SINT16:
        #if Com_u16SIG_INV_V_S16_SIZE> 0u
          if (*(P2CONST(sint16,AUTOMATIC,COM_APPL_DATA))pkvidSigTempVal ==
          Com_aks16eSigInvalidValS16[u16SigInvalidIx])
          {
           /*signal is invalid*/
           bSigIsValid = FALSE;
          }
          else
          {
          /*do nothing , the bSigIsValid is already initialized to TRUE */
          }
        #endif
        break;

        case Com_u8SIGNAL_TYPE_UINT32:
        #if Com_u16SIG_INV_V_U32_SIZE > 0u
          if (*(P2CONST(uint32,AUTOMATIC,COM_APPL_DATA))pkvidSigTempVal ==
          Com_aku32eSigInvalidValU32[u16SigInvalidIx])
          {
           /*signal is invalid*/
           bSigIsValid = FALSE;
          }
          else
          {
          /*do nothing , the bSigIsValid is already initialized to TRUE */
          }
        #endif
        break;

        case Com_u8SIGNAL_TYPE_SINT32:
        #if Com_u16SIG_INV_V_S32_SIZE > 0u
          if (*(P2CONST(sint32,AUTOMATIC,COM_APPL_DATA))pkvidSigTempVal ==
          Com_aks32eSigInvalidValS32[u16SigInvalidIx])
          {
           /*signal is invalid*/
           bSigIsValid = FALSE;
          }
          else
          {
          /*do nothing , the bSigIsValid is already initialized to TRUE */
          }
        #endif
        break;

        case Com_u8SIGNAL_TYPE_FLOAT32:
        #if Com_u16SIG_INV_V_F32_SIZE > 0u
          if ( 
          !((*(P2CONST(float32,AUTOMATIC,COM_APPL_DATA))pkvidSigTempVal >
          (Com_akf32eSigInvalidValF32[u16SigInvalidIx] + Com_f32FLOAT32_TOLERANCE) )
          ||
          (*(P2CONST(float32,AUTOMATIC,COM_APPL_DATA))pkvidSigTempVal <
          (Com_akf32eSigInvalidValF32[u16SigInvalidIx] - Com_f32FLOAT32_TOLERANCE) )))          
          {
           /*signal is invalid*/
           bSigIsValid = FALSE;
          }
          else
          {
          /*do nothing , the bSigIsValid is already initialized to TRUE */
          }
        #endif
        break;

        case Com_u8SIGNAL_TYPE_FLOAT64:
        #if Com_u16SIG_INV_V_F64_SIZE > 0u
          if ( 
          !((*(P2CONST(float64,AUTOMATIC,COM_APPL_DATA))pkvidSigTempVal >
           (Com_akf64eSigInvalidValF64[u16SigInvalidIx] + Com_f64FLOAT64_TOLERANCE))
           ||
           (*(P2CONST(float64,AUTOMATIC,COM_APPL_DATA))pkvidSigTempVal <
           (Com_akf64eSigInvalidValF64[u16SigInvalidIx] - Com_f64FLOAT64_TOLERANCE))))          
          {
           /*signal is invalid*/
           bSigIsValid = FALSE;
          }
          else
          {
          /*do nothing , the bSigIsValid is already initialized to TRUE */
          }
        #endif
        break;

        default:
           bSigIsValid = TRUE;
        break;
     }
 }
 else
 {
   /*do nothing , Signal has no invalid value and the bSigIsValid is already
   initialized to TRUE to pass any next checks*/
 }

 return bSigIsValid ;
}
#endif
/*PRQA S  3199, 3203 -- */
/*  PRQA S 4700 -- */ 

#if (Com_bDATA_INVALID_SUPPORT == STD_ON)
/******************************************************************************/
/*description: this function will process the Invalid signal as follow :
 If the signal invalid action was "notify" , it will call the configured callback function
 and will NOT update the signal Object.
 If the signal invalidation action was "replace" , it will replace it with INIT value
 */
/* !Deviation: [4700]  ( here has been an infringement of a threshold on the
specified metric)
Further decomposition of this function will affect its overall performance 
so no other meaningfull division is required*/
/*  PRQA S 4700 ++ */     
/* !Deviation: [3202]  ( Some of the varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S  3199, 3203 ++ */
/* !Deviation : Inhibit MISRA rule [0781]: Variable names are used  */
/*              as a local variable and are also members of a used structure on */
/*              purpose                                                       */
/* PRQA S 0781 ++                                                             */
static FUNC(uint8,COM_CODE) u8ProcessInvalidSig(
                         Com_SignalIdType u16SigIx,
						 VAR(Com_tu8SignalContainerType,AUTOMATIC)    u8SigContainer)
{
 /*local variable declaration*/
  Std_ReturnType                                        u8ProcessInvalidret;
 /* !Deviation: [8018]  (The name of the constant (const) doesn't respect the naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */
  P2CONST(Com_tstrSignalPB,AUTOMATIC,COM_CALIB_CONST)   pkstrLocSigPB;
  P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,COM_CALIB_CONST)  pkstrLocGrpSigPB;  
/*PRQA S 8018 , 8318, 8518  -- */
  VAR(uint8,AUTOMATIC)                                 u8SigType;
  VAR(uint8,AUTOMATIC)                                 u8SigInvalidAction;
  VAR(uint16,AUTOMATIC)                                u16SigGroupId ;
  VAR(uint16,AUTOMATIC)                                u16SigObjIx;
  VAR(uint16,AUTOMATIC)                                u16SigInitValIx;

		P2VAR(boolean,AUTOMATIC,TYPEDEF)pbSigObjB;
		
/*PRQA S 8018 , 8318, 8518  ++ */
		P2CONST(boolean,AUTOMATIC,TYPEDEF)pkbSigInitValueB;
		P2VAR(uint8,AUTOMATIC,TYPEDEF)pu8SigObjU8U8N;
		P2CONST(uint8,AUTOMATIC,TYPEDEF)pku8SigInitValueU8U8N;
		P2VAR(sint8,AUTOMATIC,TYPEDEF)ps8SigObjS8;
		P2CONST(sint8,AUTOMATIC,TYPEDEF)pks8SigInitValueS8;
  		P2VAR(uint16,AUTOMATIC,TYPEDEF)pu16SigObjU16;
		P2CONST(uint16,AUTOMATIC,TYPEDEF)pku16SigInitValueU16;
		P2VAR(sint16,AUTOMATIC,TYPEDEF)ps16SigObjS16;
		P2CONST(sint16,AUTOMATIC,TYPEDEF)pks16SigInitValueS16;
		P2VAR(uint32,AUTOMATIC,TYPEDEF)pu32SigObjU32;
		P2CONST(uint32,AUTOMATIC,TYPEDEF)pku32SigInitValueU32;
		P2VAR(sint32,AUTOMATIC,TYPEDEF)ps32SigObjS32;
		P2CONST(sint32,AUTOMATIC,TYPEDEF)pks32SigInitValueS32;
		
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON) 
		P2VAR(float32,AUTOMATIC,TYPEDEF)pf32SigObjF32;
		P2CONST(float32,AUTOMATIC,TYPEDEF)pkf32SigInitValueF32;
		P2VAR(float64,AUTOMATIC,TYPEDEF)pf64SigObjF64;
		P2CONST(float64,AUTOMATIC,TYPEDEF)pkf64SigInitValueF64;
#endif
/*PRQA S 8018 , 8318, 8518  -- */
    switch (u8SigContainer)
  {
    case Com_u8SIG_STRUCT_SIG:
    pkstrLocSigPB =   pkstrGET_PBSIGPTR_IX(u16SigIx);
    u8SigType =  pkstrLocSigPB->u8SignalType;
    u8SigInvalidAction =(uint8) bGET_SIG_INVALID_ACT(u16SigIx);       
    u16SigObjIx = pkstrLocSigPB->u16SignalObjectIndex ;
    u16SigInitValIx = pkstrLocSigPB->u16SignalInitValueIndex;
    break;
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON) 
    case Com_u8SIG_STRUCT_GROUPSIG:
    pkstrLocGrpSigPB =   pkstrGET_PBGRPSIGPTR_IX(u16SigIx);
    u8SigType =  pkstrLocGrpSigPB->u8SignalType;
    u16SigGroupId = u16SIGGRP_ID_FROM_SIGID(u16SigIx);
    u8SigInvalidAction = bSIGGRP_INVALID_ACT(u16SigGroupId); 
    u16SigObjIx = pkstrLocGrpSigPB->u16SignalObjectIndex ;
    u16SigInitValIx = pkstrLocGrpSigPB->u16SignalInitValueIndex;               
    break;
#endif
    default:
    /*Com_u8GW_STRUCT_SRC_DESC and Com_u8GW_STRUCT_DST_DESC */
    /*does not have a configured invalid value*/       
    /*shall not enter here*/
    u8SigType = (uint8)0xFF ;
    u8SigInvalidAction = (uint8)Com_u8INVALID_ACT_REPLACE ;
    u16SigObjIx = (uint16)0;
    u16SigInitValIx = (uint16)0;      
    break;
  }


   if(u8SigInvalidAction == (uint8)Com_u8INVALID_ACT_NOTIFY)
  {
     u8ProcessInvalidret = (uint8)Com_u8UNPACK_NOK_INV_NOT;
  }
  else
  {
/*Com_u8INVALID_ACT_REPLACE*/
/*update the signal object with the signal INIT value then normaly notify the
RTE*/
		pbSigObjB   = pkB_GET_SIG_OBJ_VALUEB(0);
		pkbSigInitValueB = pkbGET_SIGINIT_VALUEB(0);
		pu8SigObjU8U8N   = pku8GET_SIG_OBJ_VALUEU8(0);
		pku8SigInitValueU8U8N = pku8GET_SIGINIT_VALU8U8N(0);
		ps8SigObjS8   = pks8GET_SIG_OBJ_VALUES8(0);
		pks8SigInitValueS8 = pks8GET_SIGINIT_VALUES8(0);
		pu16SigObjU16 = pku16GET_SIG_OBJ_VALUEU16(0);
		pku16SigInitValueU16 = pku16GET_SIGINIT_VALUEU16(0);
		ps16SigObjS16 = pks16GET_SIG_OBJ_VALUES16(0);
		pks16SigInitValueS16 = pks16GET_SIGINIT_VALUES16(0);
		pu32SigObjU32 = pku32GET_SIG_OBJ_VALUEU32(0);
		pku32SigInitValueU32 = pku32GET_SIGINIT_VALUEU32(0);
		ps32SigObjS32 = pks32GET_SIG_OBJ_VALUES32(0);
		pks32SigInitValueS32 = pks32GET_SIGINIT_VALUES32(0);

#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON) 
		pf32SigObjF32 = pkf32GET_SIG_OBJ_VALUEF32(0);
		pkf32SigInitValueF32 = pkf32GET_SIGINIT_VALUEF32(0);
		pf64SigObjF64 = pkf64GET_SIG_OBJ_VALUEF64(0);
		pkf64SigInitValueF64 = pkf64GET_SIGINIT_VALUEF64(0);
#endif

     switch (u8SigType)
     {
        case Com_u8SIGNAL_TYPE_BOOLEAN:
          pbSigObjB[u16SigObjIx] =
          pkbSigInitValueB[u16SigInitValIx];
        break;

        case Com_u8SIGNAL_TYPE_UINT8:
          pu8SigObjU8U8N[u16SigObjIx] =
          pku8SigInitValueU8U8N[u16SigInitValIx];
        break;

        case Com_u8SIGNAL_TYPE_SINT8:
          ps8SigObjS8[u16SigObjIx] =
          pks8SigInitValueS8[u16SigInitValIx];
        break;

        case Com_u8SIGNAL_TYPE_UINT16:
          SchM_Enter_Com_SigObjU16();
          pu16SigObjU16[u16SigObjIx] =
          pku16SigInitValueU16[u16SigInitValIx];
          SchM_Exit_Com_SigObjU16();
        break;

        case Com_u8SIGNAL_TYPE_SINT16:
          SchM_Enter_Com_SigObjS16();
          ps16SigObjS16[u16SigObjIx] =
          pks16SigInitValueS16[u16SigInitValIx];
          SchM_Exit_Com_SigObjS16();
        break;

        case Com_u8SIGNAL_TYPE_UINT32:
          SchM_Enter_Com_SigObjU32();
          pu32SigObjU32[u16SigObjIx] =
          pku32SigInitValueU32[u16SigInitValIx];
          SchM_Exit_Com_SigObjU32();
        break;

        case Com_u8SIGNAL_TYPE_SINT32:
          SchM_Enter_Com_SigObjS32();
          ps32SigObjS32[u16SigObjIx] =
          pks32SigInitValueS32[u16SigInitValIx];
          SchM_Exit_Com_SigObjS32();
        break;
#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON) 
        case Com_u8SIGNAL_TYPE_FLOAT32:
          SchM_Enter_Com_SigObjF32();
          pf32SigObjF32[u16SigObjIx] =
          pkf32SigInitValueF32[u16SigInitValIx];
          SchM_Exit_Com_SigObjF32();
        break;

        case Com_u8SIGNAL_TYPE_FLOAT64:
          SchM_Enter_Com_SigObjF64();
          pf64SigObjF64[u16SigObjIx] =
          pkf64SigInitValueF64[u16SigInitValIx];
          SchM_Exit_Com_SigObjF64();
        break;
#endif
        default:
        break;
     }

   u8ProcessInvalidret = Com_u8UNPACK_NOK_INV_REP;
   }
return u8ProcessInvalidret;
}
/* PRQA S 0781 --                                                             */

#endif

/* PRQA S 0781 --                                                             */

/*PRQA S  3199, 3203 -- */
/*  PRQA S 4700 -- */ 
/*this function is used to detect if the signed signal has a negative value
or not , so it will simply check the Most significant bit of the signal value
if equals 1 so it is a negative value else a positive one */
static FUNC(uint8 , COM_CODE) bIsSignalNegative (
           VAR(uint8,AUTOMATIC)                         u8Endianess,
           VAR(uint8,AUTOMATIC)                         u8SigLength ,
           VAR(uint16,AUTOMATIC)                        u16SigBitPos,
           P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)       pku8IpduData)
{

/*local variable declartion*/
   VAR(uint16,AUTOMATIC)                                 u16MSBytePos=(uint16)0u;
   VAR(uint8,AUTOMATIC)                                  u8MSbitPos=(uint8)0u;
   VAR(uint8,AUTOMATIC)                                  u8StrtBitPos;
   VAR(uint16,AUTOMATIC)                                 u16StrtBytePos;
   VAR(boolean,AUTOMATIC)                                bSigIsNegative;
   VAR(uint8,AUTOMATIC)                                  u8RemainBits;
   VAR(uint8,AUTOMATIC)                                  u8BitsToNextByte;
   VAR(uint8,AUTOMATIC)                                  u8MSbitMask;
   VAR(uint8,AUTOMATIC)                                  u8ReturnValue;

   u8RemainBits = u8SigLength;
   u16StrtBytePos = (uint16)(u16SigBitPos >>(uint16)3u) ;
   u8StrtBitPos   =
   (uint8)(u16SigBitPos - ((uint16)(u16StrtBytePos <<(uint16)3u))) ;
   u8BitsToNextByte = (uint8)8u - u8StrtBitPos ;
   if (u8Endianess == Com_u8ENDIANESS_BIG)
   {
   /*big endian signal*/
   /*find the MSB position and the MS bit position*/
     do
     {
       if (u8RemainBits <= u8BitsToNextByte )
       {
          u16MSBytePos =  u16StrtBytePos;
          u8MSbitPos   =
          (uint8)(((uint8)(u8StrtBitPos + u8RemainBits)) - (uint8)1u);
          u8RemainBits = (uint8)0u;

       }
       else
       {
          u8RemainBits -= u8BitsToNextByte;
          u16StrtBytePos -= (uint16)1u;
          u8StrtBitPos     = (uint8)0u;
          u8BitsToNextByte = (uint8)8u ;
       }

     } while(u8RemainBits != (uint8)0u );


   }
   else
   {
   /*little endian or opaque*/
     /*u16MSBytePos = (start + length -1 ) /8 */
     u16MSBytePos =
     (uint16)((uint16)((u16SigBitPos + (uint16)u8SigLength)  - (uint16)1u)  >>
                       (uint16)3u  ) ;
     /*u8MSbitPos = (start + length -1 ) % 8 */
     u8MSbitPos  =
     (uint8)((uint16)((uint16)(u16SigBitPos + (uint16) u8SigLength) - (uint16)1)
      -
     (uint16)(u16MSBytePos <<(uint16)3u));
   }
  /* !Deviation:[3353] (The variable 'u8MSbitPos' is possibly unset at this
   point.)
   Variables : u8MSbitPos and  u16MSBytePos will always be set before being
   used for the following reason:
   1.do while loop ensure that the loop is excecuted at least once
   2.they are set based on the condition that the remaining bits is less than
   or equal bits till next byte , if this condition
   is not true , this will ensure another loop in the do while till setting the
   2 variables
   */
     /*PRQA S 3353 ++ */
   u8MSbitMask = u8GET_BIT_MASK(u8MSbitPos);
   bSigIsNegative = bIS_BIT_SET(pku8IpduData[u16MSBytePos] , u8MSbitMask );
     /*PRQA S 3353 -- */
	 
	if (bSigIsNegative == TRUE)
	{
		u8ReturnValue = 0xFF;
	}
	else
	{
		u8ReturnValue = 0x00;
	}
   return  u8ReturnValue;

}

#if (Com_bTO_SUPPORT == STD_ON)
/*description: this function check if the TimeOut for a specific Ipdu has
passed or not */
/*! \Trace_To : Com-SRS-0099(0), */
FUNC(boolean , COM_CODE) Com_bRxIpduCheckDM (
                         VAR(PduIdType,AUTOMATIC)  u16IpduIx)
{
   VAR(boolean, AUTOMATIC)  bIpduTimeOutPassed;
   VAR(uint32,  AUTOMATIC)  u32CurrentTimerVal;
   VAR(uint16,  AUTOMATIC)  u16TOTimerIdx;
/* !Deviation: [8018]  (The name of the constant (const) doesn't respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */
   P2CONST(Com_tstrRxIPdu,AUTOMATIC,COM_CALIB_CONST) pkstrLocRXIpduPB;
   P2VAR(uint32,AUTOMATIC,AUTOMATIC)				 pu32TOutT;
   
/*PRQA S 8018 , 8318, 8518  -- */
   u32CurrentTimerVal = 0xFFFFFFFFUL;

   pkstrLocRXIpduPB = pkstrGET_RX_IPDU_PTR_IX(u16IpduIx);
   u16TOTimerIdx = pkstrLocRXIpduPB->u16TOTimerIndex;
   if(u16TOTimerIdx != (uint16)0xFFFFu)
   {
	   pu32TOutT = pkstrGET_PB_TIMEOUT_TIMER();
		
      /*decrement the timeout */
      /*checking against 0 , shall be done before decrementing it becasue
      if we decrement then check then reload , the main function will not
      detect any timeout */

      /*assuming configured timeout = x , after 1st call T = x-1 ,2nd call
       T = x-2 , after x calls T = 0  */
      SchM_Enter_Com_TimeoutTimer_18();          
      pu32TOutT[u16TOTimerIdx]--;

      u32CurrentTimerVal = pu32TOutT[u16TOTimerIdx];
      SchM_Exit_Com_TimeoutTimer_18();          
   }


   if (u32CurrentTimerVal > (uint32)0)
   {
      bIpduTimeOutPassed = FALSE;
   }
   else
   {
       bIpduTimeOutPassed = TRUE;
   }
   return  bIpduTimeOutPassed ;
}


/*Description : Reload the Ipdu Timer with the configured Ipdu Timeout
value*/
/*! \Trace_To : Com-SRS-0098(0), Com-CDD-SignalIpduServices-5669(0) , 
 */
FUNC(void,COM_CODE) Com_vidRxIpduResetDM(
                         VAR(uint16,AUTOMATIC)  u16IpduIx)
{
/* !Deviation: [8018]  (The name of the constant (const) doesn't respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */
   P2CONST(Com_tstrRxIPdu,AUTOMATIC,COM_CALIB_CONST) pkstrLocRXIpduPB;
   
   P2VAR(uint32,AUTOMATIC,AUTOMATIC)				 pu32TOutT;
   VAR(uint16,AUTOMATIC)							 u16TOTimerIdx;
   P2CONST(uint32,AUTOMATIC,AUTOMATIC)				 pku32Tout;
/*PRQA S 8018 , 8318, 8518  -- */
   pkstrLocRXIpduPB = pkstrGET_RX_IPDU_PTR_IX(u16IpduIx);
   u16TOTimerIdx = pkstrLocRXIpduPB->u16TOTimerIndex;
   if (u16TOTimerIdx != (uint16)0xFFFFu)
   {
	  pu32TOutT = pkstrGET_PB_TIMEOUT_TIMER();
	  pku32Tout = &(pkstrLocRXIpduPB->u32Timeout);
      SchM_Enter_Com_TimeoutTimer();
      pu32TOutT[u16TOTimerIdx] = *pku32Tout;
      SchM_Exit_Com_TimeoutTimer();
   }
   else
   {
   /*do nothing*/
   }

}

/*Description : Reload the Signal Timeout Timer with the configured signal
Timeout value*/
/*! \Trace_To : Com-SRS-0098(0), Com-CDD-SignalIpduServices-5670(0) ,
 */
  /* !Deviation: [3205]  ( Some of the varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S  3205, 3199 ++ */
FUNC(void,COM_CODE) Com_vidSignalResetDM(
                       VAR(Com_tu8SignalContainerType,AUTOMATIC)       u8SigContainer,
                       VAR(uint16,AUTOMATIC)                    u16Index )

{
/* !Deviation: [8018]  (The name of the constant (const) doesn't respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */
    P2CONST(Com_tstrSignalPB,AUTOMATIC,COM_CALIB_CONST)   pkstrLocSigPB;
	VAR(uint16,AUTOMATIC)  								  u16SigTOTimerIx;
	P2VAR(uint32,AUTOMATIC,AUTOMATIC)					  pu32TOutT;
	P2CONST(uint16,AUTOMATIC,AUTOMATIC)					  pku16TOTimerIdx;
	P2CONST(uint32,AUTOMATIC,AUTOMATIC)					  pku32Tout;
	P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,TYPEDEF)      pkstrSigGroupPB;
/*PRQA S 8018 , 8318, 8518  -- */  
 /* !Deviation: [3315]  ( The Switch case has more than 2 paths in the normal case but
in some special configuration it will have only two paths.) */
/*PRQA S 3315 ++ */
	pu32TOutT = pkstrGET_PB_TIMEOUT_TIMER();

	 /*! Set signal/Signal Group timeout if configured*/
    switch (u8SigContainer)
    {
#if(Com_u16NO_OF_SIGNAL > 0u)        
      case Com_u8SIGNAL:
		pkstrLocSigPB = pkstrGET_PBSIGPTR_IX(u16Index);
		pku16TOTimerIdx = &(pkstrLocSigPB->u16TOTimerIndex);
		if (((*pku16TOTimerIdx) != (uint16)0xFFFFu) &&
		(pkstrLocSigPB->u16UpdateBitPosition != (uint16)0xFFFFu))
        {
		   pku32Tout = &(pkstrLocSigPB->u32Timeout);
           SchM_Enter_Com_TimeoutTimer();
           pu32TOutT[*pku16TOTimerIdx] = *pku32Tout;
           SchM_Exit_Com_TimeoutTimer();
        }
        else
        {
        /*do nothing*/
        }
      break;
#endif /*(Com_u16NO_OF_SIGNAL > 0u)  */      

#if((Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
      case Com_u8SIGNAL_GROUP:
		pkstrSigGroupPB = pkstrGET_PB_SIGNAL_GROUP(u16Index);
		u16SigTOTimerIx = pkstrSigGroupPB->u16TOTimerIndex;
		if((u16SigTOTimerIx != (uint16)0xFFFFu) &&
		(pkstrSigGroupPB->u16UpdateBitPosition != (uint16)0xFFFFu))
        {
           SchM_Enter_Com_TimeoutTimer();
           pu32TOutT[u16SigTOTimerIx] =
           pkstrSigGroupPB->u32Timeout;
           SchM_Exit_Com_TimeoutTimer();

        }
        else
        {
        /*do nothing */
        }
      break;
#endif /*(Com_u16NO_OF_SIGNAL_GROUPSLT > 0u)*/      
      default:
      /*shall not enter here*/
      break;

    }
/*PRQA S 3315 -- */ 
}
/*PRQA S  3205, 3199 --*/
/*Description:
*/
/* !Deviation: [4700]  ( here has been an infringement of a threshold on the
specified metric)
Further decomposition of this function will affect its overall performance 
so no other meaningfull division is required*/
/*  PRQA S 4700 ++ */ 
/* !Deviation : Inhibit MISRA rule [0781]: Variable names are used  */
/*              as a local variable and are also members of a used structure on */
/*              purpose                                                       */
/* PRQA S 0781 ++                                                             */
    

/*! \Trace_To : Com-SRS-0097(0) , Com-SRS-0098(0) ,  Com-SRS-0496(0) ,
Com-SRS-0101(0) , Com-SRS-0102(0) , Com-SRS-0103(0) , Com-SRS-0104(0) ,
 Com-SRS-0106(0) , Com-SRS-0490(0) , Com-CDD-SignalIpduServices-5632(0) ,
 Com-CDD-SignalIpduServices-5633(0) , Com-CDD-SignalIpduServices-5634(0) ,
 Com-CDD-SignalIpduServices-5662(0) , Com-CDD-SignalIpduServices-5663(0) , 
 Com-CDD-SignalIpduServices-5664(0) , Com-CDD-SignalIpduServices-5665(0) ,
 Com-CDD-SignalIpduServices-5666(0) , Com-CDD-SignalIpduServices-5667(0) ,*/
 /* !Deviation: [3205]  ( Some of the varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S  3205, 3203, 3199 ++ */
FUNC(void,COM_CODE) Com_vidSignalHandleDM(
                    VAR(Com_tu8SignalContainerType,AUTOMATIC) u8SigContainer ,
                    VAR(uint16,AUTOMATIC)              u16Index)
{
/* !Deviation: [8018]  (The name of the constant (const) doesn't respect the
naming conventions.) */
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming
 conventions.)*/
/*[8518] (The Separator of the constant (const) doesn't respect the naming
conventions.)*/
/*Limitation in the current QAC check , the name is correct*/
/*PRQA S 8018 , 8318, 8518  ++ */
   P2CONST(Com_tstrSignalPB,AUTOMATIC,COM_CALIB_CONST)      pkstrLocSigPB;
 #if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON) 
   P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,COM_CALIB_CONST) pkstrLocSigGrpPB;
 #endif
/*PRQA S 8018 , 8318, 8518  -- */
   VAR(uint32,  AUTOMATIC)  								u32CurrentTimerVal;
  /* !Deviation:[3672]  (Using non-const pointer to function.)
  the pointer to function can not be declared as constant , as it will
  be assigned a value calculated by the code depending on the PduId*/
  /*PRQA S 3672 ++ */   
   VAR(Com_tpfvidTimeoutNotification,AUTOMATIC)            pfvidTimeOutNotify;
  /*PRQA S 3672 -- */ 
#if (Com_bUBIT_SUPPORT == STD_ON) 
   VAR(boolean,AUTOMATIC)                                  bUpdateBitconf;
#endif
 
   VAR(uint16,AUTOMATIC)                                   u16TimeOutIx;
   VAR(uint32,AUTOMATIC)                                   u32TimeOutConfVal;
   VAR(uint8,AUTOMATIC)                                    u8TimeOutAction;
 #if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON) 
   VAR(uint16,AUTOMATIC)                                   u16GroupSigNb;
   VAR(uint16,AUTOMATIC)                                   u16GroupSigIx;
   VAR(uint16,AUTOMATIC)                                   u16SigGrpId;
 #endif
   VAR(uint16_least,AUTOMATIC)                             u16LoopIndex;
   VAR(uint16,AUTOMATIC)                                   u16SigIx;
   VAR(uint8,AUTOMATIC)                                    u8StructType;
   P2VAR(uint32,AUTOMATIC,AUTOMATIC)					   pu32TOutT;
 /*PRQA S 8018 , 8318, 8518  ++ */
   P2CONST(Com_tstrSignalLT,AUTOMATIC,COM_CALIB_CONST)	   pkstreSignalLT;
   P2CONST(Com_tstrSignalGroupLT,AUTOMATIC,COM_CALIB_CONST) pkstreSignalGroupLT;
  /*PRQA S 8018 , 8318, 8518  -- */

  pfvidTimeOutNotify = (VAR(Com_tpfvidTimeoutNotification,AUTOMATIC) )NULL_PTR;
 /* !Deviation: [3352]  ( The Switch case has more than 2 paths in the normal case but
in some special configuration it will have only two paths.) */
/*PRQA S 3352 ++ */
   switch (u8SigContainer)
   {
#if(Com_u16NO_OF_SIGNAL > 0u)     
     case Com_u8SIGNAL:
       u16SigIx         = u16Index;
       pkstrLocSigPB    = pkstrGET_PBSIGPTR_IX(u16SigIx);
#if (Com_bUBIT_SUPPORT == STD_ON) 
       bUpdateBitconf   = (boolean)((pkstrLocSigPB->u16UpdateBitPosition) != (uint16)0xFFFFu);
#endif
       u16TimeOutIx     = pkstrLocSigPB->u16TOTimerIndex;
       u32TimeOutConfVal= pkstrLocSigPB->u32Timeout;
       pkstreSignalLT   =  &Com_akstreSignalLT[u16SigIx];
       u8TimeOutAction  = (uint8) ((pkstreSignalLT->udteSignalLTFlags & Com_u8SIGLT_TIMEOUT_ACT) != FALSE);
       pfvidTimeOutNotify = pkstreSignalLT->pfvidTimeoutNotification;

     break;
#endif /*(Com_u16NO_OF_SIGNAL > 0u)*/ 
    
#if ((Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT== STD_ON))     
     case Com_u8SIGNALGROUP:
     /*note the signal group ID is the same as the signal Index*/
	   pkstrLocSigGrpPB = pkstrGET_PB_SIGNAL_GROUP(u16Index);
#if (Com_bUBIT_SUPPORT == STD_ON) 
       bUpdateBitconf   = (boolean)((pkstrLocSigGrpPB->u16UpdateBitPosition) != (uint16)0xFFFFu);
#endif
       u16TimeOutIx     = pkstrLocSigGrpPB->u16TOTimerIndex;
       u32TimeOutConfVal= pkstrLocSigGrpPB->u32Timeout;
	   pkstreSignalGroupLT = &Com_akstreSignalGroupLT[u16Index];
       u8TimeOutAction  = (uint8) ((pkstreSignalGroupLT->udteSignalGroupLTFlags & Com_u8SIGPLT_TIMOUT_ACT) != FALSE);
       pfvidTimeOutNotify = pkstreSignalGroupLT->pfvidTimeoutNotification;
       u16GroupSigNb = pkstrLocSigGrpPB->u16NoOfGroupSignals ;
       u16GroupSigIx = pkstrLocSigGrpPB->u16GroupSignalIndex;

     break;
#endif /*(Com_u16NO_OF_SIGNAL_GROUPSLT > 0u)*/ 
    case Com_u8GWSIGNAL :
      u16SigIx = u16GWSRCIX_OF_IPDUMAP(u16Index);
      u8StructType = u16GWSRCSTYP_OF_IPDUMAP(u16Index);
    
      if (u8StructType == (uint8)Com_u8SIGNAL) 
      {
#if(Com_u16NO_OF_SIGNAL > 0u)                 
       pkstrLocSigPB    = pkstrGET_PBSIGPTR_IX(u16SigIx);
#if (Com_bUBIT_SUPPORT == STD_ON) 
       bUpdateBitconf   = (boolean)((pkstrLocSigPB->u16UpdateBitPosition) != (uint16)0xFFFFu);
#endif
       u16TimeOutIx     = pkstrLocSigPB->u16TOTimerIndex;
       u32TimeOutConfVal= pkstrLocSigPB->u32Timeout;
       pkstreSignalLT   =  &Com_akstreSignalLT[u16SigIx];
       u8TimeOutAction  = (uint8) ((pkstreSignalLT->udteSignalLTFlags & Com_u8SIGLT_TIMEOUT_ACT) != FALSE);
       pfvidTimeOutNotify = pkstreSignalLT->pfvidTimeoutNotification;
#endif       
      }
      else
      {
      
      /*Com_u8SIG_STRUCT_SRCDESC*/
      /*shall not monitor the DM*/
#if (Com_bUBIT_SUPPORT == STD_ON) 
       bUpdateBitconf = (boolean)FALSE ;
#endif
       u32TimeOutConfVal = (uint32)0;
       u16TimeOutIx = (uint16)0xFFFFu;
       u8TimeOutAction = (uint8)0xFFu;     
      }
    break;
#if((Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT ==  STD_ON))    
    case Com_u8GWSIGNALGROUP :
     /*note the signal group ID is the same as the signal Index*/
       u16SigGrpId =    u16GWSRCIX_OF_IPDUMAP(u16Index);
	   pkstrLocSigGrpPB = pkstrGET_PB_SIGNAL_GROUP(u16SigGrpId);
#if (Com_bUBIT_SUPPORT == STD_ON) 
        bUpdateBitconf   = (boolean)((pkstrLocSigGrpPB->u16UpdateBitPosition) != (uint16)0xFFFFu);
#endif
       u16TimeOutIx     = pkstrLocSigGrpPB->u16TOTimerIndex;
       u32TimeOutConfVal= pkstrLocSigGrpPB->u32Timeout;
	   pkstreSignalGroupLT = &Com_akstreSignalGroupLT[u16SigGrpId];
       u8TimeOutAction  = (uint8) ((pkstreSignalGroupLT->udteSignalGroupLTFlags & Com_u8SIGPLT_TIMOUT_ACT) != FALSE);
       pfvidTimeOutNotify = pkstreSignalGroupLT->pfvidTimeoutNotification;
       u16GroupSigNb = pkstrLocSigGrpPB->u16NoOfGroupSignals ;
       u16GroupSigIx = pkstrLocSigGrpPB->u16GroupSignalIndex;
           
    break;
#endif        
     default:
#if (Com_bUBIT_SUPPORT == STD_ON) 
       bUpdateBitconf = (boolean)FALSE ;
#endif
       
       u32TimeOutConfVal = (uint32)0;
       u16TimeOutIx = (uint16)0xFFFFu;
       u8TimeOutAction = (uint8)0xFFu;      
     break;
   }
 /*PRQA S 3352 -- */
 /* !Deviation: [3356]  ( The value of this control expression is always 'false' due to 
 some special configuration but in the normal case this part is normally reachable.) */
/*PRQA S 3356, 3359,3201  ++ */
#if (Com_bUBIT_SUPPORT == STD_ON) 

	   if ((u16TimeOutIx != (uint16)0xFFFFu) && (u32TimeOutConfVal != (uint32)0) && (bUpdateBitconf !=FALSE))
       {
/*PRQA S 3356, 3359,3201  -- */
/*first check on the old value of the timer , if it was 0 , reload the timer*/
		  pu32TOutT = pkstrGET_PB_TIMEOUT_TIMER();
          SchM_Enter_Com_TimeoutTimer_18();
          if (pu32TOutT[u16TimeOutIx] == (uint32)0)
          {
             pu32TOutT[u16TimeOutIx]= u32TimeOutConfVal;
          }
          else
          {
          /*timer old value does not equal 0*/
          /*do nothing*/
          }
          SchM_Exit_Com_TimeoutTimer_18();
/*now it is impossible that the timer contains zero , I want to catch the
transition between timer = 1 and timer = 0, So the timer shall be decremented
then checked againest 0*/
/*decrement the timer*/
           SchM_Enter_Com_TimeoutTimer_18();
           pu32TOutT[u16TimeOutIx]--;

          u32CurrentTimerVal = pu32TOutT[u16TimeOutIx];
          SchM_Exit_Com_TimeoutTimer_18();
          if(u32CurrentTimerVal == (uint32)0)
          {
           /*time out occured*/
           /*check the timeout action */
            if(u8TimeOutAction == (uint8)Com_u8TIMEOUT_ACT_REPLACE)
            {
              
               if (u8SigContainer == (uint8)Com_u8SIG_STRUCT_SIG )
               {
#if(Com_u16NO_OF_SIGNAL > 0u) 
/* !Deviation:[3353] (The variable is possibly unset at this
point.) */
/*u16SigId will be only set for signal structure and it is protected by the 
above if condition*/  
/*  PRQA S 3353 ++ */            
               /*replace the signal value with the init one*/
               (void)Com_pkvidInitSigObjnOldVal(Com_u8SIG_STRUCT_SIG,u16SigIx,FALSE);
/*  PRQA S 3353 -- */                
#endif /*(Com_u16NO_OF_SIGNAL > 0u) */               
               }
#if((Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
               else if( (u8SigContainer == (uint8)Com_u8SIGNALGROUP) || 
                (u8SigContainer == (uint8)Com_u8GWSIGNALGROUP)  )
               {          
               /*for each signal in the signal group initialize it*/
        /*!Deviation: [3347] (The variable 'u16GroupSigIx' and  'u16GroupSigNb'are apparently unset
         at this point.)*/
         /*!Deviation: [3353](The variable 'u16GroupSigIx' is possibly unset at this point.)*/
         /*thes variables access is protected by the above if condition*/
         /* PRQA S 3347 , 3353 ++ */              
                 for(u16LoopIndex = u16GroupSigIx ;
                     u16LoopIndex <(u16GroupSigIx + u16GroupSigNb);
                     u16LoopIndex ++ )
         /* PRQA S 3347 , 3353-- */                                   
                 {
                    (void)Com_pkvidInitSigObjnOldVal(Com_u8SIG_STRUCT_GROUPSIG,u16LoopIndex,FALSE);
                 }                
                 }
#endif /*(Com_u16NO_OF_SIGNAL_GROUPSLT > 0u)*/ 
               else
               {
               /*incorrect type , shall not enter here*/
               }
            }
            else
            {
            /*timeout action = Com_u8TIMEOUT_ACT_NONE*/
            /*do nothing*/
            }
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
          /*time out did not pass yet*/

          }
       }
       else
       {
       /*no timeout is configured*/
       /*do nothing*/
       }
#endif

}
/*PRQA S  3205, 3203, 3199 -- */
/*  PRQA S 4700 -- */ 
/* PRQA S 0781 --                                                             */

#endif


/*this function will be used to unpack the array signal types */
/* i.e Com_u8SIGNAL_TYPE_UINT8N or Com_u8SIGNAL_TYPE_UINT8DYN */
static FUNC(uint8,COM_CODE) u8UnPackArraySignal(
            VAR(uint8,AUTOMATIC)  u8SigType,
            VAR(uint16,AUTOMATIC) u16SigObjIx,            
            VAR(uint16,AUTOMATIC) u16SigLen,
            VAR(uint16,AUTOMATIC) u16StartBytePos, 
            VAR(uint16,AUTOMATIC) u16DynSigMaxLen,            
            P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)pku8IpduFirstByte )
{
/*local variable definition*/
  VAR(uint16_least,AUTOMATIC) 	 u16LoopIx ;
  VAR(uint16,AUTOMATIC) 		 u16ObjStartByteIx ;
  VAR(uint8,AUTOMATIC)  		 u8UnPackArraySigRet;
  P2VAR(uint8,AUTOMATIC,TYPEDEF) pu8SigObjU8U8N;

  pu8SigObjU8U8N = pku8GET_SIG_OBJ_VALUEU8(0);
  switch (u8SigType )
  {
    case Com_u8SIGNAL_TYPE_UINT8N :
      u16ObjStartByteIx =  u16SigObjIx;
    break;
	
#if (Com_bDATA_TP_SUPPORT == STD_ON)
    case Com_u8SIGNAL_TYPE_UINT8DYN :      
      u16ObjStartByteIx = (( u16SigObjIx + (uint16)Com_u8U8DYN_OBJ_IX_OFFSET +u16DynSigMaxLen) - u16SigLen) ;
    /*Write the DYN signal object size in the first 2 byte of signal object 
    array */
      SchM_Enter_Com_SigObjU8U8N();
      pu8SigObjU8U8N[u16SigObjIx] =
      (uint8)((uint16)(u16SigLen & (uint16)0xFF00U) >> (uint16)8);

      pu8SigObjU8U8N[ u16SigObjIx + (uint16)1 ] =
      (uint8)((u16SigLen & (uint16)0x00FF)); 
      SchM_Exit_Com_SigObjU8U8N();       
    break;
#endif
    default:
    u16ObjStartByteIx = (uint16)0;
    break; 
  }
 
#if (Com_bPTR_NULL_CHECK == STD_ON) 
  if ((pu8SigObjU8U8N != (P2VAR(uint8,AUTOMATIC,COM_APPL_DATA)) NULL_PTR) &&
      (pku8IpduFirstByte != (P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)) NULL_PTR))
  { 
#endif
	pu8SigObjU8U8N = pku8GET_SIG_OBJ_VALUEU8(0);
    SchM_Enter_Com_SigObjU8U8N();    
    for(u16LoopIx = 0 ; u16LoopIx < u16SigLen ; u16LoopIx++ )
    {
         pu8SigObjU8U8N[(u16ObjStartByteIx + u16LoopIx)] =
         pku8IpduFirstByte[( u16StartBytePos + u16LoopIx ) ]; 
         
    }
    SchM_Exit_Com_SigObjU8U8N(); 
    u8UnPackArraySigRet = (uint8)Com_u8UNPACK_OK;
#if (Com_bPTR_NULL_CHECK == STD_ON) 
  }
  else
  {
    u8UnPackArraySigRet = (uint8)Com_u8UNPACK_NOT_OK;
  }
#endif

  return u8UnPackArraySigRet;

}

static FUNC(uint8,COM_CODE) u8ExtSigAppFilter8Bit(
			P2CONST(tstrUnpackSigProp , AUTOMATIC , COM_APPL_DATA)	   pkstrLocUnpackSigProp,
			P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)  pkstrPduInfoPtr,
			P2VAR(uint8,AUTOMATIC,TYPEDEF)						 		pu8SigExtBuff)
{
	VAR(uint8,AUTOMATIC) 					u8UnpackReturn;
/* !Deviation: [3198]  (Initialization is needed.)*/
/* PRQA S 3198 ++ */
	u8UnpackReturn = (uint8)Com_u8UNPACK_OK;
/* PRQA S 3198 -- */	
	 /*prepare the temp buffer with the sign extension bit filler */
     if((pkstrLocUnpackSigProp->u8SignBitFiller) == 0xFF)
     {
     /*signed data type*/
     /*check the last bit ,to see if it represent a signed value or not*/
			*pu8SigExtBuff = 0xFF;
     }
     else
     {
     /*unsigned data type , the sign bit filler will remain as initialized =
     0x00*/
		    *pu8SigExtBuff = 0x00u;
     }
	 
	  vidExtSig2TempBuff8bit(pkstrLocUnpackSigProp,pkstrPduInfoPtr,pu8SigExtBuff);
		
	  #if ((Com_bDATA_INVALID_SUPPORT == STD_ON) || (Com_u8FILTERING_DIR == Com_u8DIRECTION_RX ))
		u8UnpackReturn = u8ChkSigInvApplyFilter(pkstrLocUnpackSigProp,
												(P2VAR(void,AUTOMATIC,COM_APPL_DATA)) pu8SigExtBuff);
      #else
      u8UnpackReturn = (uint8)Com_u8UNPACK_OK;
	  #endif
	return u8UnpackReturn;
}

/* !Deviation : Inhibit MISRA rule [0781]: Variables are used  */
/*              as a local variable and are also members of a used structure on */
/*              purpose                                                       */
/* PRQA S 0781 ++                                                             */
/* !Deviation : Inhibit MISRA rule [3673]: There is no need to change pointer to variable   */
/*to pointer to constant because the function used is an internal function                    */
/* PRQA S 3673 ++                                                             */

/* !Deviation : Inhibit MISRA rule [0291]: Negative value is known to us and used */
/* decrement 1 so no need to consider it                                          */
/* PRQA S 0291 ++                                                                 */

/* !Deviation : Inhibit MISRA rule [3760]: conversion is appliacable because we  */
/* consider it to get next byte of previous byte                                 */
/* PRQA S 3760 ++                                                                */
/* !Deviation : Inhibit MISRA rule [3760]: shift operation for uint32 won't exceed   */
/* than 8 bits because conversion for range of the variable uint8 from 0..255 to 0..8 */
/* PRQA S 3382 ++                                                                  */
static FUNC(void,COM_CODE) vidExtSig2TempBuff8bit(
            P2CONST(tstrUnpackSigProp , AUTOMATIC , COM_APPL_DATA)  pkstrLocUnpackSigProp,
            P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pkstrPduInfoPtr,
			P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) pu8TempBigEndianBuff) 
{

        VAR(uint8,AUTOMATIC)                    u8RemSigBits;
        VAR(uint8,AUTOMATIC)                    u8StartBitPos;
		VAR(uint8,AUTOMATIC) 					u8IpduBitsTillNextByte;
		VAR(uint8,AUTOMATIC) 					u8StopBitPos;
		VAR(sint8,AUTOMATIC) 					s8Step;
        VAR(uint16,AUTOMATIC)                   u16StartByteNum;
		P2VAR(uint8,AUTOMATIC,COM_APPL_DATA)    pu8SduDataPtr;
		
		u8StartBitPos = pkstrLocUnpackSigProp->u8StartBitPos;
		u8IpduBitsTillNextByte = (uint8)8u  - u8StartBitPos;
		u8RemSigBits = pkstrLocUnpackSigProp->u8CurrBitSize;
		u16StartByteNum = pkstrLocUnpackSigProp->u16StartByteNum;
		pu8SduDataPtr = pkstrPduInfoPtr->SduDataPtr;
		u8StopBitPos = (u8RemSigBits) - u8IpduBitsTillNextByte;
		
		if (pkstrLocUnpackSigProp->u8SigEndianess == Com_u8ENDIANESS_BIG)
		{          
              if(u16StartByteNum != 0)
              {
                s8Step = -1;
              }
              else
              {
                s8Step = 0;
              }
              
        }
        else
        {
              s8Step = 1;
        }
		
        if (u8RemSigBits <= u8IpduBitsTillNextByte)
        {
        /* signal endianness does not matter in case the signal length was < 8 bits*/
        /*signal does not cross a byte boundary*/
        (*pu8TempBigEndianBuff) =  (uint8)(((pu8SduDataPtr[u16StartByteNum]) &
                              u8MASK_CERTAIN_BITS(u8StartBitPos,u8RemSigBits))
                              >> u8StartBitPos);
       /*loop exit condition*/
        }
        else
        {
            /* PRQA S 3690 ++ */
          (*pu8TempBigEndianBuff) = (uint8)((pu8SduDataPtr[u16StartByteNum] &
                                u8MASK_CERTAIN_BITS(u8StartBitPos,u8IpduBitsTillNextByte))
                               >> u8StartBitPos)
                               |
                               (uint8)((pu8SduDataPtr[(u16StartByteNum) + s8Step] &
                                 u8MASK_CERTAIN_BITS(0u,u8StopBitPos))
                                << ((uint8)8u - (u8StartBitPos)) ) ;
            /* PRQA S 3690 -- */
        }
                    
      if((pkstrLocUnpackSigProp->u8SignBitFiller == 0xFF) && (u8RemSigBits != 8))
      {
        /*last byte of a negative value signed data type that cross a byte boundary*/
         (*pu8TempBigEndianBuff) |= (uint8)((uint8)0xFF << (u8RemSigBits) );
      }
}
/* PRQA S 3382 --                                                             */
/* PRQA S 3760 --                                                             */
/* PRQA S 0291 --                                                             */
/* PRQA S 0781 --                                                             */

/* !Deviation : Inhibit MISRA rule [3197]: Variable u8UnpackReturn is initialized      */
/*              on purpose to make sure it has a value in all branch and compilation  */
/*              conditions                                                            */
/* PRQA S 3197 ++                                                             */
#if ((Com_bDATA_INVALID_SUPPORT == STD_ON) || (Com_u8FILTERING_DIR == Com_u8DIRECTION_RX ))
/* !Deviation : Inhibit MISRA rule [3673]: There is no need to change pointer to variable   */
/*to pointer to constant because the function used is an internal function                    */
/* PRQA S 3673 ++                                                             */
static FUNC(uint8,COM_CODE) u8ChkSigInvApplyFilter(			
			P2CONST(tstrUnpackSigProp , AUTOMATIC , COM_APPL_DATA)	   pkstrLocUnpackSigProp,
			P2CONST(void,AUTOMATIC,COM_APPL_DATA) pkvidTempBuff)
{
/* PRQA S 3673 --                                                            */
    VAR(uint8,AUTOMATIC)                        u8UnpackReturn = Com_u8UNPACK_NOT_OK;
    
    #if (Com_u8FILTERING_DIR == Com_u8DIRECTION_RX)
    VAR(boolean,AUTOMATIC)                  bSigPassedFilter;
    #endif
    
    #if (Com_bDATA_INVALID_SUPPORT == STD_ON)  
    VAR(boolean,AUTOMATIC)                  bSigIsValid;
    #endif
    
    #if (Com_bDATA_INVALID_SUPPORT == STD_ON)  
          /*Now the au8TempBigEndianBuff contains the received data in the proper endianness and sign extension*/
          /*check for invalidity*/
				bSigIsValid = bCheckSigIsValid(pkstrLocUnpackSigProp->u16SigInvalidIx,
		#if Com_u16SIG_INV_V_B_SIZE || Com_u16SIG_INV_V_U8U8N_SIZE || Com_u16SIG_INV_V_S8_SIZE || Com_u16SIG_INV_V_U16_SIZE || Com_u16SIG_INV_V_S16_SIZE || Com_u8SIGNAL_TYPE_UINT32 || Com_u8SIGNAL_TYPE_SINT32 || Com_u16SIG_INV_V_F32_SIZE || Com_u16SIG_INV_V_F64_SIZE > 0u			
					pkvidTempBuff,
		#endif
				pkstrLocUnpackSigProp->u8SigType);
		if (bSigIsValid == (boolean)TRUE)
        {
	  #endif
		
			/*signal has a valid */           
       #if (Com_u8FILTERING_DIR == Com_u8DIRECTION_RX )
           bSigPassedFilter = Com_bSignalApplyFilter (pkstrLocUnpackSigProp->u16SigIx,pkvidTempBuff, pkstrLocUnpackSigProp->u8SigContainer);
			/*  PRQA S 3355 , 3358 ++ */             
           if (bSigPassedFilter == (boolean)TRUE)
			/*  PRQA S 3355 , 3358 ++ */             
           {
		#endif				
				 u8UnpackReturn = (uint8)Com_u8UNPACK_OK;
		  
		#if (Com_u8FILTERING_DIR == Com_u8DIRECTION_RX )
           }
			/* !Deviation: [3201]  (This statement is unreachable.)*/
			/*  PRQA S 3201 ++ */       
           else
           {           
           /*signal filtered out */
           u8UnpackReturn = (uint8)Com_u8UNPACK_NOK_FLTR_OUT;
           }
			/*  PRQA S 3201 -- */  
			#endif
        
		#if (Com_bDATA_INVALID_SUPPORT == STD_ON)  
		}
        else
        {
		#if (Com_bDATA_INVALID_SUPPORT == STD_ON)
           /*u8ProcessInvalidSig will retrun E_OK in case the signal invalidate action was
           REPLACE , and E_NOT_OK in case of NOTIFY*/
           u8UnpackReturn = u8ProcessInvalidSig(pkstrLocUnpackSigProp->u16SigIx,pkstrLocUnpackSigProp->u8SigContainer);
		#endif
        }
		#endif
	return u8UnpackReturn;
}
#endif
/* PRQA S 3197 --                                                             */

static FUNC(uint8,COM_CODE) u8ExtSigAppFilter16Bit(
			P2CONST(tstrUnpackSigProp , AUTOMATIC , COM_APPL_DATA) pkstrLocUnpackSigProp,
			P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pkstrPduInfoPtr,
			P2VAR(uint16,AUTOMATIC,COM_APPL_DATA) 		pu16BigEndianBuff)
{
	VAR(uint8,AUTOMATIC) 					u8UnpackReturn;
	/* !Deviation: [3198]  (Initialization is needed.)*/
	/* PRQA S 3198 ++ */
	u8UnpackReturn = (uint8)Com_u8UNPACK_OK;
	/* PRQA S 3198 -- */	
	/*prepare the temp buffer with the sign extension bit filler */
     if((pkstrLocUnpackSigProp->u8SignBitFiller) == 0xFFu)
     {
     /*signed data type*/
     /*check the last bit ,to see if it represent a signed value or not*/
            *pu16BigEndianBuff = (uint16)0xFFFFu;
     }
     else
     {
     /*unsigned data type , the sign bit filler will remain as initialized =
     0x00*/
            *pu16BigEndianBuff = (uint16)0x0000u;
     }
	 
	 vidExtSig2TempBuff16bit(pkstrLocUnpackSigProp,pkstrPduInfoPtr,pu16BigEndianBuff);
	  
	  #if ((Com_bDATA_INVALID_SUPPORT == STD_ON) || (Com_u8FILTERING_DIR == Com_u8DIRECTION_RX ))
		u8UnpackReturn = u8ChkSigInvApplyFilter(pkstrLocUnpackSigProp,
										(P2VAR(void,AUTOMATIC,COM_APPL_DATA))  pu16BigEndianBuff);
      #else      
      u8UnpackReturn = (uint8)Com_u8UNPACK_OK;      
	  #endif
	return u8UnpackReturn;	
}

/* !Deviation : Inhibit MISRA rule [0781]: Variables are used  */
/*              as a local variable and are also members of a used structure on */
/*              purpose                                                       */
/* PRQA S 0781 ++                                                             */
/* !Deviation : Inhibit MISRA rule [3673]: There is no need to change pointer to variable   */
/*to pointer to constant because the function used is an internal function                    */
/* PRQA S 3673 ++                                                             */

/* !Deviation : Inhibit MISRA rule [0291]: Negative value is known to us and used */
/* decrement 1 so no need to consider it                                          */
/* PRQA S 0291 ++                                                                 */

/* !Deviation : Inhibit MISRA rule [3760]: conversion is appliacable because we  */
/* consider it to get next byte of previous byte                                 */
/* PRQA S 3760 ++                                                                */

/* !Deviation : Inhibit MISRA rule [3760]: shift operation for uint32 won't exceed   */
/* than 8 bits because conversion for range of the variable uint8 from 0..255 to 0..8 */
/* PRQA S 3382 ++                                                                  */

static FUNC(void,COM_CODE) vidExtSig2TempBuff16bit(
            P2CONST(tstrUnpackSigProp , AUTOMATIC , COM_APPL_DATA) pkstrLocUnpackSigProp,
            P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pkstrPduInfoPtr,
			P2VAR(uint16,AUTOMATIC,COM_APPL_DATA) pu16TempBigEndianBuff)
{
/* PRQA S 3673 --                                                             */
        VAR(uint8,AUTOMATIC)                    u8RemSigBits;
        VAR(uint8,AUTOMATIC)                    u8StartBitPos;
        VAR(uint8,AUTOMATIC)                    u8IpduBitsTillNextByte;
        VAR(uint8,AUTOMATIC)                    u8StopBitPos;
        VAR(sint8,AUTOMATIC)                    s8Step;
        VAR(uint16,AUTOMATIC)                   u16StartByteNum;
        P2VAR(uint8,AUTOMATIC,COM_APPL_DATA)    pu8SduDataPtr;
		
		
		u8IpduBitsTillNextByte = (uint8)8u  - pkstrLocUnpackSigProp->u8StartBitPos;
		u8RemSigBits = pkstrLocUnpackSigProp->u8CurrBitSize;
		u16StartByteNum = pkstrLocUnpackSigProp->u16StartByteNum;
		u8StartBitPos = pkstrLocUnpackSigProp->u8StartBitPos;
		pu8SduDataPtr = pkstrPduInfoPtr->SduDataPtr;
		u8StopBitPos = (u8RemSigBits) - u8IpduBitsTillNextByte;
		
		if (pkstrLocUnpackSigProp->u8SigEndianess == Com_u8ENDIANESS_BIG)
		{          
              if(u16StartByteNum != 0)
              {
                s8Step = -1;
              }
              else
              {
                s8Step = 0;
              }
        }
        else
        {
              s8Step = 1;
        }
		
        if (u8RemSigBits <= u8IpduBitsTillNextByte)
		{
		/* signal endianness does not matter in case the signal length was < 8 bits*/
		/*signal does not cross a byte boundary*/
            (*pu16TempBigEndianBuff) =  (uint16)(((pu8SduDataPtr[u16StartByteNum]) &
                                    u8MASK_CERTAIN_BITS(u8StartBitPos,u8RemSigBits))
                                    >> u8StartBitPos);
        }
        else
        {   

            if ((u16StartByteNum % 8) == 0)
            {
                    /* PRQA S 3690 ++ */
                (*pu16TempBigEndianBuff) = (uint16)(pu8SduDataPtr[u16StartByteNum]) |
                                            (uint16)((pu8SduDataPtr[(u16StartByteNum) + s8Step] &
                                         u8MASK_CERTAIN_BITS(0u,u8StopBitPos))
                                        << ((uint8)8u - (u8StartBitPos)) ) ;
                    /* PRQA S 3690 -- */
            }
            else
            {                       
                if (u8StopBitPos > 8)
                {
                    (*pu16TempBigEndianBuff) = (uint16)((pu8SduDataPtr[u16StartByteNum] &
                        u8MASK_CERTAIN_BITS(u8StartBitPos,u8IpduBitsTillNextByte))
                       >> u8StartBitPos)
                       |
                       (uint16)((pu8SduDataPtr[(u16StartByteNum) + s8Step] &
                         u8MASK_CERTAIN_BITS(0u,8))
                        << ((uint8)8u - (u8StartBitPos)))
                        |  (uint16)((uint16)((pu8SduDataPtr[(u16StartByteNum) + (2*s8Step)] &
                         u8MASK_CERTAIN_BITS(0u,(u8StopBitPos - 8u))))
                        << ((uint8)8u + (u8IpduBitsTillNextByte)));     
                }
                else
                {
                    (*pu16TempBigEndianBuff) = (uint16)((pu8SduDataPtr[u16StartByteNum] &
                        u8MASK_CERTAIN_BITS(u8StartBitPos,u8IpduBitsTillNextByte))
                       >> u8StartBitPos)
                       |
                       (uint16)((pu8SduDataPtr[(u16StartByteNum) + s8Step] &
                         u8MASK_CERTAIN_BITS(0u,u8StopBitPos))
                        << ((uint8)8u - (u8StartBitPos)));                  
                }
            }
        }
    
    if((pkstrLocUnpackSigProp->u8SignBitFiller == 0xFF) && (u8RemSigBits != 16))
    {
        /*last byte of a negative value signed data type that cross a byte boundary*/
         (*pu16TempBigEndianBuff) |= (uint16)((uint16)0xFFFFu << (u8RemSigBits));
    }
}
/* PRQA S 3382 --                                                             */
/* PRQA S 3760 --                                                             */
/* PRQA S 0291 --                                                             */
/* PRQA S 0781 --                                                             */

static FUNC(void,COM_CODE) vidExtSigAppFilter32Bit(
			P2CONST(tstrUnpackSigProp , AUTOMATIC , COM_APPL_DATA) pkstrLocUnpackSigProp,
			P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pkstrPduInfoPtr,
			P2VAR(uint32,AUTOMATIC,COM_APPL_DATA) 		pu32BigEndianBuff)
{	
	/*prepare the temp buffer with the sign extension bit filler */
     if((pkstrLocUnpackSigProp->u8SignBitFiller) == 0xFFu)
     {
     /*signed data type*/
     /*check the last bit ,to see if it represent a signed value or not*/
            *pu32BigEndianBuff = 0xFFFFFFFFUL;
     }
     else
     {
     /*unsigned data type , the sign bit filler will remain as initialized =
     0x00*/
            *pu32BigEndianBuff = (uint32)0x00000000;
     }
	 
	 vidExtSig2TempBuff32bit(pkstrLocUnpackSigProp,pkstrPduInfoPtr,pu32BigEndianBuff);
}

/* !Deviation : Inhibit MISRA rule [0781]: Variable names are used  */
/*              as a local variable and are also members of a used structure on */
/*              purpose                                                       */
/* PRQA S 0781 ++                                                             */
/* !Deviation : Inhibit MISRA rule [3673]: There is no need to change pointer to variable   */
/*to pointer to constant because the function used is an internal function         */
/* PRQA S 3673 ++                                                             */

/* !Deviation : Inhibit MISRA rule [0291]: Negative value is known to us and used */
/* decrement 1 so no need to consider it                                          */
/* PRQA S 0291 ++                                                                 */

/* !Deviation : Inhibit MISRA rule [3760]: conversion is appliacable because we  */
/* consider it to get next byte of previous byte                                 */
/* PRQA S 3760 ++                                                                */

/* !Deviation : Inhibit MISRA rule [3760]: shift operation for uint32 won't exceed   */
/* than 8 bits because conversion for range of the variable uint8 from 0..255 to 0..8 */
/* PRQA S 3382 ++                                                                  */

static FUNC(void,COM_CODE) vidExtSig2TempBuff32bit(
            P2CONST(tstrUnpackSigProp , AUTOMATIC , COM_APPL_DATA) pkstrLocUnpackSigProp,
            P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pkstrPduInfoPtr,
			P2VAR(uint32,AUTOMATIC,COM_APPL_DATA) pu32TempBigEndianBuff)
{
/* PRQA S 3673 --                                                             */

        VAR(uint8,AUTOMATIC)                    u8RemSigBits;
        VAR(uint8,AUTOMATIC)                    u8StartBitPos;
        VAR(uint8,AUTOMATIC)                    u8IpduBitsTillNextByte;
        VAR(uint8,AUTOMATIC)                    u8StopBitPos;
        VAR(sint8,AUTOMATIC)                    s8Step;
        VAR(uint16,AUTOMATIC)                   u16StartByteNum;
		P2VAR(uint8,AUTOMATIC,COM_APPL_DATA)    pu8SduDataPtr;
		
		
		u8IpduBitsTillNextByte = (uint8)8u  - pkstrLocUnpackSigProp->u8StartBitPos;
		u8RemSigBits = pkstrLocUnpackSigProp->u8CurrBitSize;
		u16StartByteNum = pkstrLocUnpackSigProp->u16StartByteNum;
		u8StartBitPos = pkstrLocUnpackSigProp->u8StartBitPos;
		pu8SduDataPtr = pkstrPduInfoPtr->SduDataPtr;
		u8StopBitPos = (u8RemSigBits) - u8IpduBitsTillNextByte;
		
		if (pkstrLocUnpackSigProp->u8SigEndianess == Com_u8ENDIANESS_BIG)
		{          
              if(u16StartByteNum != 0)
              {
                s8Step = -1;
              }
              else
              {
                s8Step = 0;
              }
        }
        else
        {
              s8Step = 1;
        }
        
        if (u8RemSigBits <= u8IpduBitsTillNextByte)
        {
        /* signal endianness does not matter in case the signal length was < 8 bits*/
        /*signal does not cross a byte boundary*/
            (*pu32TempBigEndianBuff) =  (uint32)(((pu8SduDataPtr[u16StartByteNum]) &
                                    u8MASK_CERTAIN_BITS(u8StartBitPos,u8RemSigBits))
                                    >> u8StartBitPos);
        }
        else
        {   

/* !Deviation: [3212]  Casting in the following code might be needed if compiler/platform is changed */
/*  PRQA S 3212 ++ */  
            if ((u8StartBitPos % 8u) == 0)
            {
                    
                if(u8RemSigBits <= 16u)
                {
                    /* PRQA S 3690 ++ */
                    (*pu32TempBigEndianBuff) = (uint32)(pu8SduDataPtr[u16StartByteNum]) |
                                                (uint32) ((uint32)(pu8SduDataPtr[(u16StartByteNum) + s8Step] &
                                             u8MASK_CERTAIN_BITS(0u,u8StopBitPos))
                                            << ((uint8)8u)) ;
                    /* PRQA S 3690 -- */
                }
                else if (u8RemSigBits <= 24u)
                {
                    /* PRQA S 3690 ++ */
                    (*pu32TempBigEndianBuff) = (uint32)(pu8SduDataPtr[u16StartByteNum]) | (uint32)(((uint32)(pu8SduDataPtr[u16StartByteNum + s8Step])) << ((uint8)8u))
                                                |(uint32)((uint32)(pu8SduDataPtr[(u16StartByteNum) + (2*s8Step)] &
                                             u8MASK_CERTAIN_BITS(0u,(u8StopBitPos-8))) << ((uint8)16u));
                    /* PRQA S 3690 -- */
                }
                else /*more than 24 bit*/
                {
                    (*pu32TempBigEndianBuff) = (uint32)(pu8SduDataPtr[u16StartByteNum]) | (uint32)((uint32)(pu8SduDataPtr[u16StartByteNum + s8Step]) << ((uint8)8u))
                                               |(uint32)((uint32)(pu8SduDataPtr[u16StartByteNum + (2*s8Step)]) << ((uint8)16u))
                                                |(uint32)((uint32)(pu8SduDataPtr[(u16StartByteNum) + (3*s8Step)] &
                                             u8MASK_CERTAIN_BITS(0u,(u8StopBitPos-16))) << ((uint8)24u));
                }
            }
            else
            {                       
                if (u8StopBitPos <= 8)
                {
                    (*pu32TempBigEndianBuff) = (uint32)((pu8SduDataPtr[u16StartByteNum] &
                        u8MASK_CERTAIN_BITS(u8StartBitPos,u8IpduBitsTillNextByte)) >> u8StartBitPos)
                       | (uint32)((uint32)(pu8SduDataPtr[(u16StartByteNum) + s8Step] & u8MASK_CERTAIN_BITS(0u,u8StopBitPos))
                        << ((uint8)8u - (u8StartBitPos)));  
                    
                }               
                else if (u8StopBitPos <= 16)
                {
                
                (*pu32TempBigEndianBuff) = (uint32)((pu8SduDataPtr[u16StartByteNum] &
                        u8MASK_CERTAIN_BITS(u8StartBitPos,u8IpduBitsTillNextByte)) >> u8StartBitPos)
                       | (uint32)((uint32)(pu8SduDataPtr[(u16StartByteNum) + s8Step]) << ((uint8)8u - (u8StartBitPos)))
                       | (uint32)((uint32)(pu8SduDataPtr[(u16StartByteNum) + (2*s8Step)] &
                         u8MASK_CERTAIN_BITS(0u,u8StopBitPos-8)) << ((uint8)16u - (u8StartBitPos)));    
                }
                else if (u8StopBitPos <= 24)
                {
                
                (*pu32TempBigEndianBuff) = (uint32)((pu8SduDataPtr[u16StartByteNum] &
                        u8MASK_CERTAIN_BITS(u8StartBitPos,u8IpduBitsTillNextByte)) >> u8StartBitPos)
                       | (uint32)((uint32)(pu8SduDataPtr[(u16StartByteNum) + s8Step]) << ((uint8)8u - (u8StartBitPos)))
                       | (uint32)((uint32)(pu8SduDataPtr[(u16StartByteNum) + (2*s8Step)]) << ((uint8)16u - (u8StartBitPos)))
                       | (uint32)((uint32)(pu8SduDataPtr[(u16StartByteNum) + (3*s8Step)] &
                         u8MASK_CERTAIN_BITS(0u,u8StopBitPos-16)) << ((uint8)24u - (u8StartBitPos)));   
                }
                else
                {
                
                (*pu32TempBigEndianBuff) = (uint32)((pu8SduDataPtr[u16StartByteNum] &
                        u8MASK_CERTAIN_BITS(u8StartBitPos,u8IpduBitsTillNextByte)) >> u8StartBitPos)
                       | (uint32)((uint32)(pu8SduDataPtr[(u16StartByteNum) + s8Step]) << ((uint8)8u - (u8StartBitPos)))
                       | (uint32)((uint32)(pu8SduDataPtr[(u16StartByteNum) + (2*s8Step)]) << ((uint8)16u - (u8StartBitPos)))
                       | (uint32)((uint32)(pu8SduDataPtr[(u16StartByteNum) + (3*s8Step)]) << ((uint8)24u - (u8StartBitPos)))
                       | (uint32)((uint32)(pu8SduDataPtr[(u16StartByteNum) + (4*s8Step)] &
                         u8MASK_CERTAIN_BITS(0u,(u8StopBitPos-24))) << (uint8)((uint8)32u - (u8StartBitPos)));   
                }
            }
/*  PRQA S 3212 -- */  
        }
        
/* !Deviation: [3212]  Casting in the following statement might be needed if compiler/platform is changed */
/*  PRQA S 3212 ++ */       
/* !Deviation: [3381]  Left shift is done on purpose to generate a mask, and the truncated bits are not needed */
/*  PRQA S 3381 ++ */ 
/* !Deviation: [1255]  Constant doesn't need to be of type int because it's casted to a known size data type */
/*  PRQA S 1255 ++ */ 
    if((pkstrLocUnpackSigProp->u8SignBitFiller == 0xFF) && (u8RemSigBits != 32))
    {
         (*pu32TempBigEndianBuff) |= (uint32)((uint32)0xFFFFFFFFUL << (uint8)(u8RemSigBits));
    }
     
}
/* PRQA S 3382 --                                                                  */
/*  PRQA S 3760 -- */ 
/*  PRQA S 0291 -- */ 
/* PRQA S 0781 --     */
/*  PRQA S 3212 -- */ 
/*  PRQA S 3381 -- */ 
/*  PRQA S 1255 -- */ 

#if (Com_bFLOAT_SIGNAL_SUPPORT == STD_ON)
static FUNC(Std_ReturnType,COM_CODE) udtFilterInvChkCpu64Bit(
				P2CONST(tstrUnpackSigProp , AUTOMATIC , COM_APPL_DATA) 	 pkstrLocUnpackSigProp,
				P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)pkstrPduInfoPtr,
				P2CONST(float64,AUTOMATIC,TYPEDEF)						 pkf64DataBuff)
{

	 VAR(Std_ReturnType,AUTOMATIC)                         u8UnpackReturn;
/* !Deviation: [3198]  ( u8UnpackReturn needs initialization)*/
/* PRQA S 3198 ++ */
	 u8UnpackReturn = Com_u8UNPACK_OK;
/* PRQA S 3198 -- */		
		#if ((Com_bDATA_INVALID_SUPPORT == STD_ON) || (Com_u8FILTERING_DIR == Com_u8DIRECTION_RX ))
			u8UnpackReturn = u8ChkSigInvApplyFilter(pkstrLocUnpackSigProp, pkf64DataBuff);
		#endif
	
	return u8UnpackReturn;
}

#endif
	
static FUNC(Std_ReturnType,COM_CODE) udtFilterInvChkCpu32Bit(
			 P2CONST(tstrUnpackSigProp , AUTOMATIC , COM_APPL_DATA) 	 pkstrLocUnpackSigProp,
			 P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)pkstrPduInfoPtr,
			 P2CONST(uint32,AUTOMATIC,TYPEDEF)						 pku32DataBuff)
{


	 VAR(Std_ReturnType,AUTOMATIC)                         u8UnpackReturn;
/* !Deviation: [3198]  ( u8UnpackReturn needs initialization)*/
/* PRQA S 3198 ++ */
	 u8UnpackReturn = Com_u8UNPACK_OK;
/* PRQA S 3198 -- */	 
	#if ((Com_bDATA_INVALID_SUPPORT == STD_ON) || (Com_u8FILTERING_DIR == Com_u8DIRECTION_RX ))
		u8UnpackReturn = u8ChkSigInvApplyFilter(pkstrLocUnpackSigProp, pku32DataBuff );
	#endif
	
	return u8UnpackReturn;
}
/*  PRQA S 4700 -- */ 
/* !Deviation: [8019]  ( The name of " symbolic constants " (#define)
Identifiers doesn't respect the naming conventions.) */
/*[8519](The Type of " symbolic constants " (#define) Identifiers
doesn't respect the naming conventions.)*/
/*this #define is imposed by the AUTOSAR MemMap file , required for memory
abstraction*/
/*PRQA S 8019 , 8519 ++ */
/* PRQA S  5087 L1 */
#define COM_STOP_SEC_CODE
/*PRQA S 8019 , 8519 -- */
#include "MemMap.h"
/* PRQA L:L1 */
/*PRQA S 0790 -- */
/** \} */ /* end of Com module group */

/* PRQA S 0850 --                                                             */

