/* !Deviation: [0790]  usage of floating point is not avoidable because it is
    mandated by AUTOSAR */
/* PRQA S 0790 ++ */
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                 */
/*                                                                            */
/* !Component       : Com                                                     */
/* !Description     : AUTOSAR Communication Module                            */
/*                                                                            */
/* !Module          : Com                                                     */
/*                                                                            */
/* !File            : Com_GWHandler.c                                         */
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
/* $Revision::   1.61     $$Author::   ametwelly      $$Date::   Jun 26 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file Com_GWHandler.c
*
* \par
*   Internals of GWHandler Sub-Component.
*   This file contains the internals of GWHandler Sub-Component. */
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


#if (COM_DEV_ERROR_DETECT == STD_ON)
  #include "Det.h"
#endif /* COM_DEV_ERROR_DETECT */
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

/* !Deviation: [3453]  the following functions like macros , helps to increase
the readability of the code , by accessing the required configuration parameter
, through a macro . Macros were used instead of functions in order to increase
the code performance by reducing the time required by the context switching*/
/* PRQA S 3453 ++ */

/* !Deviation: [3456]  a macro argument will be reevaluated each time it
is used in the macro expansion. it is dangerous only if the macro argument is
passed as expression which is not the case here. */
/* PRQA S 3456 ++ */

/*!	\Description  MACRO used to Get Signal index fron look up array */
#if (Com_bPB_VARIANT == STD_ON)
#define u16SIG_GET_LKUP_IX(sig_id) \
          Com_pkstreMainConfig->pkstrSignalLookUp[(sig_id)].u16Index
#else
#define u16SIG_GET_LKUP_IX(sig_id) \
		  akstrSignalLookUp[(sig_id)].u16Index
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PBGRPSIGPTR_IX(u16SigIx) \
(&( Com_pkstreMainConfig->pkstrGroupSignalPB[(u16SigIx)]))
#else
#if u16NO_OF_GROUP_SIGNALS > 0u
#define pkstrGET_PBGRPSIGPTR_IX(u16SigIx) \
(&(akstrGroupSignalPB[(u16SigIx)]))
#else
#define pkstrGET_PBGRPSIGPTR_IX(u16SigIx) \
	(P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif

/*!	\Description  MACRO used to check if the structure type from Signal ID \n
                  returns one of the following \n
                      COM_u8SIG_STRUCTURE_TYPE_SIGNAL          \n
                      COM_u8SIG_STRUCTURE_TYPE_GROUPSIGNAL     \n
                      Com_u8SIG_STRUCT_SRCDESC                 \n
                      Com_u8SIG_STRUCT_DSTDESC */

#if (Com_bPB_VARIANT == STD_ON)
#define u8SIG_GET_STRUCT_TYPE(sig_id) \
          Com_pkstreMainConfig->pkstrSignalLookUp[(sig_id)].u8StructureType
#else
#define u8SIG_GET_STRUCT_TYPE(sig_id) \
          akstrSignalLookUp[(sig_id)].u8StructureType
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
#define pkstrGET_PBSIGPTR_IX(u16SigIx) \
(&(Com_pkstreMainConfig->pkstrSignalPB[u16SigIx]))
#else
#define pkstrGET_PBSIGPTR_IX(u16SigIx) \
(&(akstrSignalPB[u16SigIx]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PBSRC_DESCPTR_IX(u16SigIx) \
(&( Com_pkstreMainConfig->pkstrGWSrcDesc[(u16SigIx)]))
#else
#if u16NO_OF_GW_SRC_DESC > 0u 
#define pkstrGET_PBSRC_DESCPTR_IX(u16SigIx) \
(&(akstrGWSrcDesc[(u16SigIx)]))
#else
#define pkstrGET_PBSRC_DESCPTR_IX(u16SrcSigIx) \
	(P2CONST(Com_tstrGWSrcDesc,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PBDSTDESCPTR_IX(u16SigIx) \
(&(Com_pkstreMainConfig->pkstrGWDstDesc[(u16SigIx)]))
#else
#if u16NO_OF_GW_DST_DESC > 0u
#define pkstrGET_PBDSTDESCPTR_IX(u16SigIx) \
(&(akstrGWDstDesc[(u16SigIx)]))
#else
#define pkstrGET_PBDSTDESCPTR_IX(u16SigIx) \
	(P2CONST(Com_tstrGWDstDesc,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif




/* Com-CDD-GWHandler-0351(0) */
#if (Com_bGW_ENABLED == STD_ON)
/*!	\Description  MACRO used to get u16Com_GWSignalMappingMaxIx */
#if (Com_bPB_VARIANT == STD_ON)
#define u16GET_GWSIGMAP_MAXIX() \
                  Com_pkstreMainConfig->u16GWSignalMappingMaxIx
#else
#if (u16NO_OF_GW_PATHS > 0)
#define u16GET_GWSIGMAP_MAXIX() \
                  u16NO_OF_GW_PATHS - 1
#else
#define u16GET_GWSIGMAP_MAXIX() \
				  u16NO_OF_GW_PATHS
#endif
#endif


#define u16GET_G_SIG_ID(group_sig_ix) \
              Com_akstreGroupSignalLT[(group_sig_ix)].u16SignalId


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_GW_MAP_SIG_PTR(u16SignalMappIndex) \
(&(Com_pkstreMainConfig->pkstrGWSignalMapping[u16SignalMappIndex]))
#else
#define pkstrGET_GW_MAP_SIG_PTR(u16SignalMappIndex) \
(&(akstrGWSignalMapping[u16SignalMappIndex]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_GW_DEST_DESC_PTR(u16DestSigIx) \
(&(Com_pkstreMainConfig->pkstrGWDstDesc[u16DestSigIx]))
#else
#if u16NO_OF_GW_DST_DESC > 0u
#define pkstrGET_GW_DEST_DESC_PTR(u16DestSigIx) \
(&(akstrGWDstDesc[u16DestSigIx]))
#else
#define pkstrGET_GW_DEST_DESC_PTR(u16DestSigIx) \
	(P2CONST(Com_tstrGWDstDesc,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_GW_SRC_DESC_PTR(u16SrcSigIx) \
(&(Com_pkstreMainConfig->pkstrGWSrcDesc[u16SrcSigIx]))
#else
#if u16NO_OF_GW_SRC_DESC > 0u 
#define pkstrGET_GW_SRC_DESC_PTR(u16SrcSigIx) \
(&(akstrGWSrcDesc[u16SrcSigIx]))
#else
#define pkstrGET_GW_SRC_DESC_PTR(u16SrcSigIx) \
	(P2CONST(Com_tstrGWSrcDesc,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PB_SIG_GRP_PTR(u16SignalGroupIx) \
(&(Com_pkstreMainConfig->pkstrSignalGroupPB[(u16SignalGroupIx)]))
#else
#define pkstrGET_PB_SIG_GRP_PTR(u16SignalGroupIx) \
(&(akstrSignalGroupPB[(u16SignalGroupIx)]))
#endif
#endif

/* PRQA S 3456 -- */
/* PRQA S 3453 -- */


/* !Deviation: [8019] and [8519]  the following MACRO is implied by AUTOSAR */
/* PRQA S 8019 ++ */
/* PRQA S 8519 ++ */

#define COM_START_SEC_CODE
#include "Memmap.h"

/* PRQA S 8019 -- */
/* PRQA S 8519 -- */

/* !Deviation: [4700, 0715] Metric thresholds Metric value out of threshold
range.
This function is readable and easily debuggable and the deviasion is minor*/
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description This function performs the processing of the AUTOSAR COM \n
                 module's gateway activities
    \param[in]  None
*******************************************************************************/
/*! \Trace_To Com-CDD-GWHandler-0122(0),
              Com-CDD-GWHandler-0448(0),
              Com-CDD-GWHandler-0351(0),
              Com-CDD-GWHandler-0352(0),
              Com-CDD-GWHandler-0353(0),
              Com-CDD-GWHandler-0354(0),
              Com-CDD-GWHandler-0512(0),
              Com-CDD-0153(0),
              Com-CDD-0263(0),
			  Com-CDD-5748(1), Com-CDD-5514(1) */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
FUNC(void, COM_CODE) Com_MainFunctionRouteSignals( void )
/* PRQA S 0850 --                                                             */
{
  /*! Local variables */
#if (Com_bGW_ENABLED == STD_ON)
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

  VAR(boolean, AUTOMATIC)         bGWSignalReceived;
  VAR(uint8, AUTOMATIC)           u8CurrSrcStructType;
  VAR(uint8, AUTOMATIC)           u8NextSrcStructType;
  VAR(uint8, AUTOMATIC)           u8CurrDstStructType;
  VAR(uint16, AUTOMATIC)          u16CurrGWSigMapMaxIx;
  VAR(uint16_least, AUTOMATIC)          u16GWFlagsLoopIndex;
  VAR(uint16_least, AUTOMATIC)          u16MutiGWLoopIndex;
  VAR(uint16, AUTOMATIC)          u16CurrSrcId;
  VAR(uint16, AUTOMATIC)          u16CurrDstId;
  VAR(uint16, AUTOMATIC)          u16CurrSrcIndex;
  VAR(uint16, AUTOMATIC)          u16CurrDstIndex;
#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u))
  VAR(uint16, AUTOMATIC)          u16NoOfGroupSig;
  VAR(uint16, AUTOMATIC)          u16CurrSrcFirstGSigIx;
  VAR(uint16, AUTOMATIC)          u16CurrDstFirstGSigIx;
  VAR(uint16, AUTOMATIC)          u16CurrDstGSigId;
  VAR(uint16_least, AUTOMATIC)          u16GroupSigLoopIndex;
#endif
  VAR(uint16, AUTOMATIC)          u16NextSrcIndex;
  P2CONST(void, AUTOMATIC,
        COM_MAX_CALIB_APPL_CFGCONST)
                                  pkvidCurrSigObjPtr;
#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u))
  P2CONST(void, AUTOMATIC,
        COM_MAX_CALIB_APPL_CFGCONST)
                                  pkvidCurrSrcGSigShadowPtr;
#endif
	P2CONST(Com_tstrGWSignalMapping,AUTOMATIC,TYPEDEF) pkstrGWSigMap;
	P2CONST(Com_tstrGWDstDesc,AUTOMATIC,TYPEDEF) pkstrGWDstDescPtr;
	P2CONST(Com_tstrGWSrcDesc,AUTOMATIC,TYPEDEF) pkstrGWSrcDescPtr;
	P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,TYPEDEF) pkstrSigGroupPB;
/* PRQA S 0850 --                                                             */


  u16CurrDstId  = (uint16)0;

  /*! DET check and reporting */
  /* Com-CDD-0261(0) */
  if (Com_enueStatus == COM_UNINIT)
  {
	/* Do Nothing */
  }
  else
  {

    u16CurrGWSigMapMaxIx = u16GET_GWSIGMAP_MAXIX();
    /*! For each bit in Com_au8GWFlags */
	pkstrGWDstDescPtr = pkstrGET_GW_DEST_DESC_PTR(0);
	pkstrGWSrcDescPtr = pkstrGET_GW_SRC_DESC_PTR(0);
	pkstrSigGroupPB = pkstrGET_PB_SIG_GRP_PTR(0);
#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u))
	u16CurrSrcFirstGSigIx = 0;
#endif

    for(u16GWFlagsLoopIndex = 0;
        u16GWFlagsLoopIndex <= u16CurrGWSigMapMaxIx;
        u16GWFlagsLoopIndex++)
    {
	  
	 pkstrGWSigMap = pkstrGET_GW_MAP_SIG_PTR(u16GWFlagsLoopIndex);
	 u16CurrSrcIndex = pkstrGWSigMap->u16SrcIndex;

     u8CurrSrcStructType = pkstrGWSigMap->u8SrcStructType;
						  
	  switch (u8CurrSrcStructType)
	  {
	  case Com_u8GW_STRUCT_SIG:
	  u16CurrSrcId = Com_akstreSignalLT[u16CurrSrcIndex].u16SignalId;
	  break;
	  
	  case Com_u8GW_STRUCT_SIGGROUP:
#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u))
	  u16CurrSrcFirstGSigIx = pkstrSigGroupPB[u16CurrSrcIndex].u16GroupSignalIndex;
      u16CurrSrcId = u16GET_G_SIG_ID(u16CurrSrcFirstGSigIx);
#endif
	  break;
	  
	  case Com_u8GW_STRUCT_SRC_DESC:
	  u16CurrSrcId = pkstrGWSrcDescPtr[u16CurrSrcIndex].u16SignalId;
	  break;
	  
	  default:
	  u16CurrSrcId =0;
	  break; 
	  }
	  
	  #if Com_u16NO_OF_SIGNAL_STATUS > 0u
	  SchM_Enter_Com_SignalStatus_1A();
	  bGWSignalReceived = Com_audteSignalStatus[u16CurrSrcId] & Com_u8GWS_RX;
	  SchM_Exit_Com_SignalStatus_1A();
	  #endif
	  
      /*! If bit = TRUE */
      if(bGWSignalReceived != FALSE)
      {
        /*! Then access akstrGWSignalMapping[ bit_position ] */

        u16MutiGWLoopIndex = u16GWFlagsLoopIndex;
        /*! For each entry starting from akstrGWSignalMapping[ bit_position ] \n
        and u16SrcIndex equal the u16SrcIndex of \n
        akstrGWSignalMapping[ bit_position ] \n
        do. */
        do
        {
		
		  pkstrGWSigMap = pkstrGET_GW_MAP_SIG_PTR(u16MutiGWLoopIndex);
          u16CurrDstIndex =
                          pkstrGWSigMap->u16DstIndex;
          u8CurrDstStructType =
                          pkstrGWSigMap->u8DstStructType;

          switch (u8CurrSrcStructType)
          {
            case Com_u8GW_STRUCT_SIG:
			case Com_u8GW_STRUCT_SRC_DESC:
#if Com_u16NO_OF_SIGNAL > 0u
            /*! if u8DstStructType == Com_u8GW_STRUCT_SIG */
            /*! call Com_SendSignal for the signal ID of u16DstIndex  \n
            passing the pointer to the source signal object */
            switch(u8CurrDstStructType)
            {
              case Com_u8GW_STRUCT_SIG:
              u16CurrDstId = Com_akstreSignalLT[u16CurrDstIndex].u16SignalId;
              break;

              case Com_u8GW_STRUCT_DST_DESC:
              u16CurrDstId = pkstrGWDstDescPtr[u16CurrDstIndex].u16SignalId;
              break;

              default:
              break;
            }
            pkvidCurrSigObjPtr = Com_pkvidGetSigObjPtr(u16CurrSrcId);
            /* Com-CDD-GWHandler-0352(0) */
            (void) Com_SendSignal( u16CurrDstId, pkvidCurrSigObjPtr );
#endif
            break;
            case Com_u8GW_STRUCT_SIGGROUP:
#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
            /* for signal groups, index = ID because they have different ID
            space than signals and group signals */
            (void) Com_ReceiveSignalGroup(u16CurrSrcIndex);
            /*! if u8DstStructType == Com_u8GW_STRUCT_SIGGROUP */
            /*! get the number of group signals in the signal group*/
            u16NoOfGroupSig = pkstrSigGroupPB[u16CurrSrcIndex].u16NoOfGroupSignals;
            /*! get the index of the first group signal in the signal group*/
            u16CurrDstFirstGSigIx = pkstrSigGroupPB[u16CurrDstIndex].u16GroupSignalIndex;

            /*! for each group signal in signal group of ID of u16DstIndex \n
            call Com_UpdateShadowSignal passing the pointer to the source \n
            group signal object */
            SchM_Enter_Com_SigObjB_1a();
            SchM_Enter_Com_SigObjF32_1a();
            SchM_Enter_Com_SigObjF64_1a();
            SchM_Enter_Com_SigObjS16_1a();
            SchM_Enter_Com_SigObjS32_1a();
            SchM_Enter_Com_SigObjS8_1a();
            SchM_Enter_Com_SigObjU16_1a();
            SchM_Enter_Com_SigObjU32_1a();
            SchM_Enter_Com_SigObjU8_1a();
            for(u16GroupSigLoopIndex = 0;
                u16GroupSigLoopIndex < u16NoOfGroupSig;
                u16GroupSigLoopIndex++)
            {
              /*! Get source and destination group signals ID's */
              u16CurrDstGSigId = u16GET_G_SIG_ID(u16CurrDstFirstGSigIx +
                                                  u16GroupSigLoopIndex);
              /*! Get source group signal's shadow buffer pointer  */
              pkvidCurrSrcGSigShadowPtr =
                                  Com_pvidGetGSigShadowPtr((u16CurrSrcFirstGSigIx +
                                                 u16GroupSigLoopIndex));

              /*! Call Com_UpdateShadowSignal for the current group signal */
              Com_UpdateShadowSignal(u16CurrDstGSigId,
                                     pkvidCurrSrcGSigShadowPtr);

            }
            /* for signal groups, index = ID because they have different ID
            space than signals and group signals */
            /*! Call Com_SendSignalGroup for signal group ID of u16DstIndex */
            (void) Com_SendSignalGroup(u16CurrDstIndex);
			SchM_Exit_Com_SigObjU8_1a();
            SchM_Exit_Com_SigObjU32_1a();
            SchM_Exit_Com_SigObjU16_1a();
            SchM_Exit_Com_SigObjS8_1a();
            SchM_Exit_Com_SigObjS32_1a();
            SchM_Exit_Com_SigObjS16_1a();
            SchM_Exit_Com_SigObjF64_1a();
            SchM_Exit_Com_SigObjF32_1a();
			SchM_Exit_Com_SigObjB_1a();
#endif
            break;
            default:

            break;
          }

          u16MutiGWLoopIndex = u16MutiGWLoopIndex + (uint16)1;


          if(u16MutiGWLoopIndex <= u16CurrGWSigMapMaxIx)
          {
		    pkstrGWSigMap = pkstrGET_GW_MAP_SIG_PTR(u16MutiGWLoopIndex);
            u16NextSrcIndex =
                          pkstrGWSigMap->u16SrcIndex;

            u8NextSrcStructType =
                          pkstrGWSigMap->u8SrcStructType;
          }
          else
          {
            u16NextSrcIndex  = (uint16)0;
            u8NextSrcStructType = (uint8)0;
          }
        } while((u16NextSrcIndex == u16CurrSrcIndex) &&
                (u8NextSrcStructType  == u8CurrSrcStructType) &&
                (u16MutiGWLoopIndex <= u16CurrGWSigMapMaxIx));
        /*! Clear GW Flag after processing */
		#if Com_u16NO_OF_SIGNAL_STATUS > 0u
		SchM_Enter_Com_SignalStatus_1A();
		Com_audteSignalStatus[u16CurrSrcId] &= (Com_udtSigStatus) (~(Com_u8GWS_RX));
		SchM_Exit_Com_SignalStatus_1A();
		#endif
      }
    }
  }
#endif
}
/* PRQA S 4700 -- */

/* !Deviation: [8019] and [8519]  the following MACRO is required by AUTOSAR */
/* PRQA S 8019 ++ */
/* PRQA S 8519 ++ */

/* !Deviation: [0838] Multiple Memmap.h inclusion is implied by AUTOSAR */
/* PRQA S 0838, 5087 L1 */


#define COM_STOP_SEC_CODE
#include "Memmap.h"
/* PRQA L:L1 */

/* PRQA S 8019 -- */
/* PRQA S 8519 -- */
/* PRQA S 0790 -- */

/* !Deviation: [5087]    the following MACRO is implied by AUTOSAR */
/* PRQA S 5087 L1 */
#define COM_START_SEC_CODE
#include "MemMap.h"
 /* PRQA L:L1 */
/******************************************************************************/
/*! \Description This function returns group signal shadow buffer pointer
  \param[in]   u16SignalId  signal Handle ID
  \return      group signal shadow buffer pointer in the form of pointer to void
*******************************************************************************/
/* !Deviation: [4700, 0715] Metric thresholds Metric value out of threshold
range.
This function is readable and easily debuggable because it consists of simple
switch cases.*/
/* PRQA S 4700 ++ */
#if (Com_bSIGNAL_GROUP_SUPPORT == STD_ON) 
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

FUNC(Com_tpvidMaxCalibDataConstPtr, COM_CODE)
        Com_pvidGetGSigShadowPtr(VAR(Com_SignalIdType, AUTOMATIC) u16SignalIx)
{
  /*! Local variables */
  VAR(uint8, AUTOMATIC)           u8CurrSigType;
  VAR(uint16, AUTOMATIC)          u16CurrShdBufIx;

  P2VAR(void, AUTOMATIC, COM_CALIB_DATA)
                                  pvidReturnValue;
  P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,COM_CALIB_CONST)
								  pkstrGroSigPB;
/* PRQA S 0850 --                                                             */

  pvidReturnValue  = NULL_PTR;

  pkstrGroSigPB = pkstrGET_PBGRPSIGPTR_IX(u16SignalIx);
  u8CurrSigType      = pkstrGroSigPB->u8SignalType;

  u16CurrShdBufIx    = pkstrGroSigPB->u16ShadowBufferIndex; 


  switch(u8CurrSigType)
  {
    /* Com-CDD-TxHandler-0227(0) */
    case Com_u8SIGNAL_TYPE_BOOLEAN:
    pvidReturnValue = pkB_GET_SIG_OBJ_VALUEB(u16CurrShdBufIx);
    break;

    case Com_u8SIGNAL_TYPE_FLOAT32:
    pvidReturnValue = pkf32GET_SIG_OBJ_VALUEF32(u16CurrShdBufIx);
    break;

    case Com_u8SIGNAL_TYPE_FLOAT64:
    pvidReturnValue = pkf64GET_SIG_OBJ_VALUEF64(u16CurrShdBufIx);
    break;

    case Com_u8SIGNAL_TYPE_SINT16:
    pvidReturnValue = pks16GET_SIG_OBJ_VALUES16(u16CurrShdBufIx);
    break;

    case Com_u8SIGNAL_TYPE_SINT32:
    pvidReturnValue = pks32GET_SIG_OBJ_VALUES32(u16CurrShdBufIx);
    break;

    case Com_u8SIGNAL_TYPE_SINT8:
    pvidReturnValue = pks8GET_SIG_OBJ_VALUES8(u16CurrShdBufIx);
    break;

    case Com_u8SIGNAL_TYPE_UINT16:
    pvidReturnValue = pku16GET_SIG_OBJ_VALUEU16(u16CurrShdBufIx);
    break;

    case Com_u8SIGNAL_TYPE_UINT32:
    pvidReturnValue = pku32GET_SIG_OBJ_VALUEU32(u16CurrShdBufIx);
    break;

    case Com_u8SIGNAL_TYPE_UINT8:
    pvidReturnValue = pku8GET_SIG_OBJ_VALUEU8(u16CurrShdBufIx);
    break;

    case Com_u8SIGNAL_TYPE_UINT8N:
    pvidReturnValue = pku8GET_SIG_OBJ_VALUEU8(u16CurrShdBufIx);
    break;

    case Com_u8SIGNAL_TYPE_UINT8DYN:
      /* Not supporting GW */
    break;

    default:

    break;
  }

  return pvidReturnValue;
}



#endif
/* PRQA S 4700 -- */

/******************************************************************************/
/*! \Description This function returns signal, group signal or GW \n
                 description object pointer
  \param[in]   u16SignalId  signal Handle ID
  \return      Signal, group signal or GW description object pointer in the \n
               form of pointer to void
*******************************************************************************/
/* !Deviation: [4700, 0715] Metric thresholds Metric value out of threshold
range.
This function is readable and easily debuggable because it consists of simple
switch cases.*/
/* PRQA S 4700 ++ */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

FUNC(Com_tpkvidMaxCalibDataConstPtr, COM_CODE)
            Com_pkvidGetSigObjPtr(VAR(Com_SignalIdType, AUTOMATIC) u16SignalId)
{
  /*! Local variables */
  VAR(uint8, AUTOMATIC)           u8CurrSigStructType;
  VAR(uint8, AUTOMATIC)           u8CurrSigType;
  VAR(uint16, AUTOMATIC)          u16CurrSigIx;
  VAR(uint16, AUTOMATIC)          u16CurrObjIx;

  /*! Local main Post-build configuration pointer */

  Com_tpkvidMaxCalibDataConstPtr  pkvidReturnValue;
   P2CONST(Com_tstrSignalPB,AUTOMATIC,COM_CALIB_CONST)
								  pkstrSigPB;
   P2CONST(Com_tstrGWSrcDesc,AUTOMATIC,COM_CALIB_CONST)
								  pkstrGWSrcDescPtr;
   P2CONST(Com_tstrGWDstDesc,AUTOMATIC,COM_CALIB_CONST)
								  pkstrGWDstDescPtr;
/* PRQA S 0850 --                                                             */

  u8CurrSigType = Com_u8SIGNAL_TYPE_BOOLEAN;
  u16CurrObjIx  = (uint16)0;
  pkvidReturnValue = NULL_PTR;

  u8CurrSigStructType = u8SIG_GET_STRUCT_TYPE(u16SignalId);
  u16CurrSigIx = u16SIG_GET_LKUP_IX(u16SignalId);
  switch(u8CurrSigStructType)
  {
    case Com_u8GW_STRUCT_SIG:
	pkstrSigPB = pkstrGET_PBSIGPTR_IX(u16CurrSigIx);
    u8CurrSigType = pkstrSigPB->u8SignalType;
    u16CurrObjIx  = pkstrSigPB->u16SignalObjectIndex;
    break;

    case Com_u8SIG_STRUCT_GROUPSIG:
      /* Not supported */
    break;

    case Com_u8SIG_STRUCT_SRCDESC:
	pkstrGWSrcDescPtr = pkstrGET_PBSRC_DESCPTR_IX(u16CurrSigIx);
    u8CurrSigType = pkstrGWSrcDescPtr->u8SignalType;
    u16CurrObjIx  = pkstrGWSrcDescPtr->u16SignalObjectIndex;
    break;

    case Com_u8SIG_STRUCT_DSTDESC:
	pkstrGWDstDescPtr = pkstrGET_PBDSTDESCPTR_IX(u16CurrSigIx);
    u8CurrSigType = pkstrGWDstDescPtr->u8SignalType;
    u16CurrObjIx  = pkstrGWDstDescPtr->u16SignalObjectIndex;
    break;

    default:
    break;
  }

  switch(u8CurrSigType)
  {
    /* Com-CDD-TxHandler-0227(0) */
    case Com_u8SIGNAL_TYPE_BOOLEAN:
    pkvidReturnValue = pkB_GET_SIG_OBJ_VALUEB(u16CurrObjIx);
    break;


    case Com_u8SIGNAL_TYPE_FLOAT32:
    pkvidReturnValue = pkf32GET_SIG_OBJ_VALUEF32(u16CurrObjIx);
    break;

    case Com_u8SIGNAL_TYPE_FLOAT64:
    pkvidReturnValue = pkf64GET_SIG_OBJ_VALUEF64(u16CurrObjIx);
    break;

    case Com_u8SIGNAL_TYPE_SINT16:
    pkvidReturnValue = pks16GET_SIG_OBJ_VALUES16(u16CurrObjIx);
    break;

    case Com_u8SIGNAL_TYPE_SINT32:
    pkvidReturnValue = pks32GET_SIG_OBJ_VALUES32(u16CurrObjIx);
    break;

    case Com_u8SIGNAL_TYPE_SINT8:
    pkvidReturnValue = pks8GET_SIG_OBJ_VALUES8(u16CurrObjIx);
    break;

    case Com_u8SIGNAL_TYPE_UINT16:
    pkvidReturnValue = pku16GET_SIG_OBJ_VALUEU16(u16CurrObjIx);
    break;

    case Com_u8SIGNAL_TYPE_UINT32:
    pkvidReturnValue = pku32GET_SIG_OBJ_VALUEU32(u16CurrObjIx);
    break;

    case Com_u8SIGNAL_TYPE_UINT8:
    pkvidReturnValue = pku8GET_SIG_OBJ_VALUEU8(u16CurrObjIx);
    break;

    case Com_u8SIGNAL_TYPE_UINT8N:
    pkvidReturnValue = pku8GET_SIG_OBJ_VALUEU8(u16CurrObjIx);
    break;

    case Com_u8SIGNAL_TYPE_UINT8DYN:
      /* Not supporting GW */
    break;

    default:
    break;
  }
  return pkvidReturnValue;
}
/* PRQA S 4700 -- */
/* !Deviation: [5087]    the following MACRO is implied by AUTOSAR */
/* PRQA S 5087 L1 */
#define COM_STOP_SEC_CODE
#include "Memmap.h"
 /* PRQA L:L1 */
/** \} */ /* end of Com module group */
