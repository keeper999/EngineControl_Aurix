/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                 */
/*                                                                            */
/* !Component       : Com                                                     */
/* !Description     : AUTOSAR Communication Module                            */
/*                                                                            */
/* !Module          : Com                                                     */
/*                                                                            */
/* !File            : Com_IPduGroupServices                                   */
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
/* $Revision::   1.84     $$Author::   ametwelly      $$Date::   Aug 24 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file Com_IPduGroupServices.c
*
* \par
*   Internals of Com_IPduGroupServices Sub-Component.
*   This file contains the internals of Com_IPduGroupServices Sub-Component. */
/******************************************************************************/

/******************************************************************************/
/*! \defgroup module Com
* This is the grouping of the Com module members.
* \{
*/
/******************************************************************************/

#include"Com.h"
#include"Com_Internal.h"
#include "Com_Cfg.h"
#include "Com_LCfg.h"
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

#define u8MASK 0x01U

/* !Deviation: [3453]  the following functions like macros , helps to increase
the readability of the code , by accessing the required configuration parameter
, through a macro . Macros were used instead of functions in order to increase
the code performance by reducing the time required by the context switching*/
/* PRQA S 3453 ++ */

/* !Deviation: [3456]  a macro argument will be reevaluated each time it
is used in the macro expansion. it is dangerous only if the macro argument is
passed as expression which is not the case here. */
/* PRQA S 3456 ++ */

/*!	\Description  MACRO used in comparison between old and new bit values of \n
                  the ipduGroupVector's */
#define bBYTE_MASK(byte, bit_number) \
          ((boolean)(((u8MASK << ((bit_number))) & (byte)) >> ((bit_number))))

/*!	\Description  MACRO used to reload timeout timer for RX I-PDU by first
timeout */

#if (Com_bPB_VARIANT == STD_ON)
#define u32RXIPDU_RLD_FTIMEOUT(u16IPduFiTOIx, u16IPTOIx) \
            (Com_pkstreMainConfig->pu32TimeOutTimer[u16IPTOIx]\
                          = Com_pkstreMainConfig->pku32IpduFirstTO[u16IPduFiTOIx])
#else
#if (Com_u16IPDU_FIRST_TO_SIZE > 0U)
#define u32RXIPDU_RLD_FTIMEOUT(u16IPduFiTOIx, u16IPTOIx) \
            (Com_au32TimeOutTimer[u16IPTOIx]\
                          = Com_aku32eIpduFirstTO[u16IPduFiTOIx])	
#else
#define u32RXIPDU_RLD_FTIMEOUT(u16IPduFiTOIx, u16IPTOIx) \
	(P2CONST(uint32,AUTOMATIC,TYPEDEF))NULL_PTR
#endif						  
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_IPDUGRPCTRL_PTR(u16Index) \
		(&(Com_pkstreMainConfig->pkstrIPduGroup[u16Index]))
#else
#define pkstrGET_IPDUGRPCTRL_PTR(u16Index) \
	     (&(akstrIPduGroup[u16Index]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_IPDU_GRP_MAP(u16Index) \
		(Com_pkstreMainConfig->pku16IPduGroupToIPduMap)
#else
#define pkstrGET_IPDU_GRP_MAP(u16Index) \
	     (&(aku16IPduGroupToIPduMap[u16Index]))
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_IPDU_LOOK_UP_PTR(u16Index) \
		(&(Com_pkstreMainConfig->pkstrIPduLookUp[u16Index]))
#else
#define pkstrGET_IPDU_LOOK_UP_PTR(u16Index) \
	     (&(akstrIPduLookUp[u16Index]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_TX_MODE_PTR(u16Index) \
		(&(Com_pkstreMainConfig->pkstrTxMode[u16Index]))
#else
#define pkstrGET_TX_MODE_PTR(u16Index) \
	     (&(akstrTxMode[u16Index]))
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_RX_IPDU_PTR(u16Index) \
		(&(Com_pkstreMainConfig->pkstrRxIPdu[u16Index]))
#else
#define pkstrGET_RX_IPDU_PTR(u16Index) \
	     (&(akstrRxIPdu[u16Index]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_TX_IPDU_PTR(u16Index) \
		(&(Com_pkstreMainConfig->pkstrTxIPdu[u16Index]))
#else
#define pkstrGET_TX_IPDU_PTR(u16Index) \
	     (&(akstrTxIPdu[u16Index]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PB_TIMEOUT_TIMER(u16Index) \
	(&(Com_pkstreMainConfig->pu32TimeOutTimer[u16Index]))
#else
#if u16NO_OF_TIMEOUT > 0u
#define pkstrGET_PB_TIMEOUT_TIMER(u16Index) \
	(&(Com_au32TimeOutTimer[u16Index]))
#else
#define pkstrGET_PB_TIMEOUT_TIMER(u16Index) \
	(P2VAR(uint32,AUTOMATIC,TYPEDEF))NULL_PTR
#endif
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_IPDU_SGL_MAP_PTR(u16Index) \
		(&(Com_pkstreMainConfig->pkstrIPduToSignalMapping[u16Index]))
#else
#define pkstrGET_IPDU_SGL_MAP_PTR(u16Index) \
	     (&(akstrIPduToSignalMapping[u16Index]))
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_RX_IPDU_PTR_IX(u16IPduIx) \
(&(Com_pkstreMainConfig->pkstrRxIPdu[u16IPduIx]))
#else
#define pkstrGET_RX_IPDU_PTR_IX(u16IPduIx) \
(&(akstrRxIPdu[u16IPduIx]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PB_SIGNAL_PTR(u16SignalIx) \
(&(Com_pkstreMainConfig->pkstrSignalPB[(u16SignalIx)]))
#else
#define pkstrGET_PB_SIGNAL_PTR(u16SignalIx) \
(&(akstrSignalPB[(u16SignalIx)]))
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define pkstrGET_PB_SIG_GRP_PTR(u16SignalGroupIx) \
(&(Com_pkstreMainConfig->pkstrSignalGroupPB[(u16SignalGroupIx)]))
#else
#define pkstrGET_PB_SIG_GRP_PTR(u16SignalGroupIx) \
(&(akstrSignalGroupPB[(u16SignalGroupIx)]))
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define u8IPDU_GET_TXMODE_PTR(TxModeIx) \
          (&(Com_pkstreMainConfig->pkstrTxMode[(TxModeIx)]))
#else
#define u8IPDU_GET_TXMODE_PTR(TxModeIx) \
          (&(akstrTxMode[(TxModeIx)]))
#endif			


#if (Com_bPB_VARIANT == STD_ON)
#define u16GET_IPDU_GROUP_MAP(u16Index) \
		Com_pkstreMainConfig->pku16IPduToIPduGroupMap[u16Index]
#else
#define u16GET_IPDU_GROUP_MAP(u16Index) \
	     aku16IPduToIPduGroupMap[u16Index]
#endif


/*!	\Description  MACRO used to check if I-PDU based Timeout is supported
 for TX I-PDU */
/*#define bTXIPDU_IPDU_TO_SPRT(cfg_ptr, pdu_index) \
          (((cfg_ptr)->pkstrTxIPdu[(pdu_index)].udteTxIPduFlags & Com_u8TX_IPDUTIMEOUT_MASK) != FALSE)*/

/* PRQA S 3456 -- */
/* PRQA S 3453 -- */


/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/******************************************************************************/
/*!	\Description Mask array used to set/get bit in/from bit vector
*******************************************************************************/
CONST(uint8, COM_CONST) Com_aku8eBitMaskArray [COM_u8BIT_MASK_ARRAY_SIZE] =
{
  0x01,
  0x02,
  0x04,
  0x08,
  0x10,
  0x20,
  0x40,
  0x80
};

/* PRQA S 0850 --                                                             */

/* !Deviation: [8019] COM_START_SEC_CODE is required by AUTOSAR */
/* PRQA S 8019 ++ */

/* !Deviation: [8519] COM_START_SEC_CODE is required by AUTOSAR */
/* PRQA S 8519 ++ */

/* !Deviation: [0838] Multiple Memmap.h inclusion is implied by AUTOSAR */
/* PRQA S 0838, 5087 L1 */
/* PRQA S 5087 L1 */
#define COM_START_SEC_CODE
#include "Memmap.h"
/* PRQA L:L1 */
/* PRQA L:L1 */

/* PRQA S 8019 -- */
/* PRQA S 8519 -- */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/******************************************************************************/
/*! \Description This function extracts bit from bit vector according to its \n
                 position
  \param[in]   pku8Vector  Pointer to bit vector
  \param[in]   u16BitPosition  position in the bit vector
  \return      TRUE if bit == 1, FALSE otherwise
*******************************************************************************/
FUNC(boolean,COM_CODE) Com_bExtractBitVector(
                      P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)
                                            pku8Vector,
                      VAR(uint16,AUTOMATIC) u16BitPosition)
{
  VAR(uint16, AUTOMATIC)    u16BytePos;
  VAR(boolean, AUTOMATIC)   bRetunValue;
  VAR(uint8, AUTOMATIC)     u8MaskIndex;

/* PRQA S 0850 --                                                             */

  u16BytePos = u16BitPosition >> 3;
  u8MaskIndex = (uint8)(u16BitPosition & 0x0007);
  if((pku8Vector[u16BytePos] & Com_aku8eBitMaskArray[u8MaskIndex]) ==
                               Com_aku8eBitMaskArray[u8MaskIndex])
  {
    bRetunValue = TRUE;
  }
  else
  {
    bRetunValue = FALSE;
  }

  return bRetunValue;
}

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/******************************************************************************/
/*! \Description This function sets bit in a bit vector according to its \n
                 position
  \param[in]   pku8Vector  Pointer to bit vector
  \param[in]   u16BitPosition  position in the bit vector
  \return      void
*******************************************************************************/
FUNC(void,COM_CODE) Com_vidSetBitVector(
                P2VAR(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pu8Vector,
                VAR(uint16,AUTOMATIC) u16BitPosition,
                VAR(boolean,AUTOMATIC) bBitValue)
{
  VAR(uint16, AUTOMATIC) u16BytePos;
  VAR(uint8, AUTOMATIC)  u8MaskIndex;
/* PRQA S 0850 --                                                             */

  u16BytePos = u16BitPosition >> 3;
  u8MaskIndex = (uint8)(u16BitPosition & 0x0007);
  if(bBitValue == FALSE)
  {
    pu8Vector[u16BytePos] =
        (pu8Vector[u16BytePos] & (uint8)(~Com_aku8eBitMaskArray[u8MaskIndex]));
  }
  else
  {
    pu8Vector[u16BytePos] =
             (pu8Vector[u16BytePos] | (Com_aku8eBitMaskArray[u8MaskIndex]));
  }
} /* Com_vidSetBitVector */

/* !Deviation: [4700, 0715] Metric thresholds Metric value out of threshold
range.
This function is readable and easily debuggable because it consists of 2 main
blocks "I-PDU group changing from STOP to START" and "I-PDU group changing
from  START to STOP".*/
/* PRQA S 4700 ++ */
/* PRQA S 0715 ++ */

/* !Deviation: [3673]  The object addressed by the pointer parameter
ipduGroupVector is not modified and so the pointer could be of type
pointer to const. MISRA Rule 81.
The API prototype is required by Autosar */
/* PRQA S 3673 ++ */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/******************************************************************************/
/*! \Description Function to start/stop I-PDU groups.
    \param[in]  ipduGroupVector I-PDU group vector containing the activation \n
                state (stopped = 0/ started = 1) for all I-PDU groups.
    \param[in]  initialize flag to request initialization of the I-PDUs which \n
                are newly started \n
                \Range TRUE,FALSE \n
                \Unit boolean
    \param[in,out]  None
*******************************************************************************/
/*! \Trace_To Com-CDD-IpduGroupServices-0449(0),
              Com-CDD-IpduGroupServices-0451(0),
              Com-CDD-IpduGroupServices-0452(0),
              Com-CDD-IpduGroupServices-0019(0),
              Com-CDD-IpduGroupServices-0026(0),
              Com-CDD-IpduGroupServices-0046(0),
              Com-CDD-IpduGroupServices-0222(0),
              Com-CDD-0179(0),
              Com-CDD-0180(0),
              Com-CDD-0181(0),
              Com-CDD-0182(0),
              Com-CDD-0183(0),
			  Com-CDD-5746(0),
			  Com-CDD-5752(0),
			  Com-CDD-5371(1),
              Com-CDD-IpduGroupServices-0220(0),
              Com-CDD-IpduGroupServices-0223(0),
              Com-CDD-IpduGroupServices-0221(0),
              Com-CDD-IpduGroupServices-5691(0),
              Com-CDD-IpduGroupServices-0047(0) */
FUNC(void, COM_CODE) Com_IpduGroupControl(
                         VAR(Com_IpduGroupVector, AUTOMATIC)  ipduGroupVector,
                         VAR(boolean, AUTOMATIC)              initialize )
{
/* PRQA S 0850 --                                                             */
/* PRQA S 3673 -- */
  /*! DET check and reporting */
#if (COM_DEV_ERROR_DETECT == STD_ON)
/*Com-CDD-IpduGroupServices-0449(0)*/
  if ( Com_enueStatus == COM_UNINIT)
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_IpduGroupControl , COM_E_UNINIT);
/* PRQA S 3212 -- */
  }
  /*Com-CDD-IpduGroupServices-0451(0)*/
  else if ( ipduGroupVector == NULL_PTR )
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_IpduGroupControl , COM_E_PARAM_POINTER);
/* PRQA S 3212 -- */
  }
  else
#endif /*COM_DEV_ERROR_DETECT*/
  {
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

    /*! Local variables */
    VAR(boolean, AUTOMATIC)     bConfWaitStatus;
    VAR(boolean, AUTOMATIC)     bOldBitVal;
    VAR(boolean, AUTOMATIC)     bNewBitVal;
#if (Com_bTO_SUPPORT == STD_ON)
    VAR(boolean, AUTOMATIC)     bRxDMActive;
    VAR(uint8, AUTOMATIC)       u8CurrTxModeTrueType;
#endif

    VAR(uint8, AUTOMATIC)       u8CurrentIPduDir;

    VAR(uint16_least, AUTOMATIC)      u16ByteLoopIndex;
	VAR(uint16_least, AUTOMATIC)      u16IPduGrpLoopIndex;
    VAR(uint16, AUTOMATIC)      	  u16CurrentIPduIndex;
    VAR(PduIdType, AUTOMATIC)   u16CurrentIPduId;
    VAR(Com_IpduGroupIdType, AUTOMATIC)
                                u16IPduGroupId;
							

/* !Deviation: [8018, 8318, 8518]  VNR is repected for pointer to constant */
/* PRQA S 8018 ++ */
/* PRQA S 8318 ++ */
/* PRQA S 8518 ++ */
    /*! Local main Post-build configuration pointer */
	P2CONST(Com_tstrIPduLookUp,AUTOMATIC,TYPEDEF) pkstrIPduLookUpPtr;
#if (Com_bTO_SUPPORT == STD_ON) 
	P2CONST(Com_tstrTxMode,AUTOMATIC,TYPEDEF) pkstrTxModePtr;
	VAR(uint32,AUTOMATIC)  			u32IPduTxTO;
#endif

	P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF) pkstrTxIPduPtr;
	P2CONST(Com_tstrRxIPdu,AUTOMATIC,TYPEDEF) pkstrRxIPduPtr;
	P2VAR(uint32,AUTOMATIC,AUTOMATIC) pu32TOTPtr;
	VAR(boolean,AUTOMATIC) bIpduStatusChanged;
	VAR(uint16,AUTOMATIC)  u16NumberOfIPduGroup;
/* PRQA S 8518 -- */
/* PRQA S 8318 -- */
/* PRQA S 8018 -- */
/* PRQA S 0850 --                                                             */

	
	pu32TOTPtr = pkstrGET_PB_TIMEOUT_TIMER(0);
	 /*! For each I-PDU belongs to this I-PDU group */
     for(u16CurrentIPduId = 0u;
                  u16CurrentIPduId < u16NO_OF_IPDUS_STATUS;
                  u16CurrentIPduId++)
     {	
		pkstrIPduLookUpPtr = pkstrGET_IPDU_LOOK_UP_PTR(u16CurrentIPduId);
        u8CurrentIPduDir = pkstrIPduLookUpPtr->u8Direction;
        u16CurrentIPduIndex = pkstrIPduLookUpPtr->u16Index;
		bIpduStatusChanged = FALSE;
                  /*! call COM_vidInitTxIpdu or COM_vidInitRxIpdu */
                  /* Com-CDD-IpduGroupServices-0019(0),
                     Com-CDD-IpduGroupServices-0046(0),
                     Com-CDD-0182(0) */
                  if(u8CurrentIPduDir == Com_u8DIRECTION_TX)
                  {
					
				    pkstrTxIPduPtr = pkstrGET_TX_IPDU_PTR(u16CurrentIPduIndex);
					u16NumberOfIPduGroup = pkstrTxIPduPtr->u16NumberOfIPduGroups;
					for(u16IPduGrpLoopIndex =0;
					((u16IPduGrpLoopIndex < u16NumberOfIPduGroup)&&(bIpduStatusChanged == FALSE));
									u16IPduGrpLoopIndex++)
					{
						u16IPduGroupId = u16GET_IPDU_GROUP_MAP(pkstrTxIPduPtr->u16IPduGroupMapIndex+u16IPduGrpLoopIndex);
						bOldBitVal = Com_bGETBITOPT(&(Com_au8eIPduGroupVector[0]),u16IPduGroupId);
						bNewBitVal = Com_bGETBITOPT(&(ipduGroupVector[0]),u16IPduGroupId);

					if(bOldBitVal != bNewBitVal)
					{
						if((bOldBitVal == FALSE) && (bNewBitVal != FALSE))
						{
#if Com_u16NO_OF_TX_IPDU > 0u
							if(initialize == TRUE)
							{
								Com_vidInitTxIpdu (u16CurrentIPduId , FALSE);
							}
#endif /*Com_u16NO_OF_TX_IPDU*/
						#if (Com_bTO_SUPPORT == STD_ON) 
							pkstrTxModePtr = u8IPDU_GET_TXMODE_PTR(pkstrTxIPduPtr->u16TxModeTrueIndex);
							u8CurrTxModeTrueType = pkstrTxModePtr->u8TxMode;							
							
							u32IPduTxTO = pkstrTxIPduPtr->u32Timeout;
							if(((pkstrTxIPduPtr->udteTxIPduFlags & Com_u8TX_IPDUTMS_MASK ) == FALSE)    &&
									(u8CurrTxModeTrueType == (uint8)Com_u8TX_MODE_NONE)   &&
											(u32IPduTxTO != 0xFFFFFFFFUL))
							{
								SchM_Enter_Com_TimeoutTimer_03();
								/* Com-CDD-IpduGroupServices-5691(0) */
								pu32TOTPtr[pkstrTxIPduPtr->u16TOTimerIndex] = u32IPduTxTO;
								SchM_Exit_Com_TimeoutTimer_03();
								#if u16NO_OF_IPDUS_STATUS > 0u
								SchM_Enter_Com_IPduStatus_03();
								Com_audteIPduStatus[u16CurrentIPduId] |= Com_u8WAIT_CONF;
								SchM_Exit_Com_IPduStatus_03();
								#endif
							}
						 #endif
							
							/*! Update I-PDU state flag */
							#if u16NO_OF_IPDUS_STATUS > 0u
							SchM_Enter_Com_IPduStatus_03();
							Com_audteIPduStatus[u16CurrentIPduId] |= Com_u8ACTIVE_MASK;
							SchM_Exit_Com_IPduStatus_03();
							#endif
							
							bIpduStatusChanged = TRUE;
						}
						else if((bOldBitVal != FALSE) && (bNewBitVal == FALSE))
						{ 
							/*! I-PDU group changing from  START to STOP */
							/*! check if this I-PDU waits confirmation*/

							/* !Deviation: [3361]  This 'do - while' control expression has a constant,
							'false' value. This is intended. (multi-line function like MACRO) */
							/* PRQA S 3361 ++ */
							  #if u16NO_OF_IPDUS_STATUS > 0u
							  SchM_Enter_Com_IPduStatus_03();
							  bConfWaitStatus = Com_audteIPduStatus[u16CurrentIPduId] & (Com_u8WAIT_CONF);
							  SchM_Exit_Com_IPduStatus_03();
							  #endif
							
							  
							#if (Com_bTX_INACTIVE_ERROR == STD_ON)  
							/*! Add IPDU Error Notification for optimization to avoid access Signal/Signal group structure
								and get pointer to every Error notifications*/
								if(bConfWaitStatus != FALSE)
								{
									if(pkstrTxIPduPtr->pfvidIPduErrorNotifPtr != NULL_PTR)
									{
										(*pkstrTxIPduPtr->pfvidIPduErrorNotifPtr)();
									}
								}
							#endif
												  
							#if (Com_bTO_SUPPORT == STD_ON) 
							  /*! Deadline Monitoring Handling */
							  /*! If I-PDU direction == TX clear Timeout timer.*/
								if((pkstrTxIPduPtr->u32Timeout)
											   != 0xFFFFFFFFUL)
								{
									/*! Function call to clear Tx I-PDU timeout timer */
									/* Com-CDD-IpduGroupServices-0223(0) */
									Com_vidClearTOTxIpdu(u16CurrentIPduIndex);
								}
							  else
								{
								}
							#endif
							
							/*Fix Bug# 46015
							Clear Deferred Proccessing flag when I-PDU state change
								from  START to STOP */
							#if u16NO_OF_IPDUS_STATUS > 0u
							SchM_Enter_Com_IPduStatus_03();
							Com_audteIPduStatus[u16CurrentIPduId] &= (Com_udtIPduStatus)(~(Com_u8DEF_PROC_MASK| Com_u8WAIT_CONF | Com_u8ACTIVE_MASK)); 
							SchM_Exit_Com_IPduStatus_03();
							#endif
							 /*! clear th I-PDU Confirmation Wait flag */
							/* Com-CDD-IpduGroupServices-0026(0) */
						}
						else
						{
						
						}
					}
					else
					{
					    /* Com-CDD-0183(0) */
						/*! If the status of the the I-PDU group was not changed,
						do nothing */
					 }
				     }
				  }
                  else /* u16CurrentIPduDir == Com_u8DIRECTION_RX */
                  {
					pkstrRxIPduPtr = pkstrGET_RX_IPDU_PTR_IX(u16CurrentIPduIndex);
					u16NumberOfIPduGroup = pkstrRxIPduPtr->u16NumberOfIPduGroups;
					for(u16IPduGrpLoopIndex =0;
					((u16IPduGrpLoopIndex < u16NumberOfIPduGroup)&&(bIpduStatusChanged == FALSE));
									u16IPduGrpLoopIndex++)
					{
						u16IPduGroupId = u16GET_IPDU_GROUP_MAP(pkstrRxIPduPtr->u16IPduGroupMapIndex+u16IPduGrpLoopIndex);
						bOldBitVal = Com_bGETBITOPT(&(Com_au8eIPduGroupVector[0]),u16IPduGroupId);
						bNewBitVal = Com_bGETBITOPT(&(ipduGroupVector[0]),u16IPduGroupId);
						if(bOldBitVal != bNewBitVal)
						{
						 if((bOldBitVal == FALSE) && (bNewBitVal != FALSE))
						 {
							if(initialize == TRUE)
							{
								Com_vidInitRxIpdu (u16CurrentIPduId , FALSE);
							}
					        /*! Deadline Monitoring Handling */
							/*! If I-PDU direction == RX initialize Timeout timers.*/
						  
						  #if (Com_bTO_SUPPORT == STD_ON)
							bRxDMActive = Com_bIpduCheckRxDMActive(u16CurrentIPduId);
							if (
								(bRxDMActive == TRUE) &&
								(
									((pkstrRxIPduPtr->u16TOTimerIndex) != (uint16)0xFFFFu) ||
									((pkstrRxIPduPtr->udteRxIPduFlags & Com_u8RX_IPDUSIGTIMEOUT) != FALSE)
								)
							   )
							{
								/*! Function call to init I-PDU based timeout timer and/or
								signal based timeout timers with FirstTimeout or Timeout */
								/* Com-CDD-IpduGroupServices-0220(0) */
								Com_vidInitTORxIpdu(u16CurrentIPduIndex);
							}
							else
							{
							
							}
							#endif
							/*! Update I-PDU state flag */
							#if u16NO_OF_IPDUS_STATUS > 0u
							SchM_Enter_Com_IPduStatus_03();
							Com_audteIPduStatus[u16CurrentIPduId] |= Com_u8ACTIVE_MASK;
							SchM_Exit_Com_IPduStatus_03();
							#endif
							
							bIpduStatusChanged = TRUE;
						}
						else if((bOldBitVal != FALSE) && (bNewBitVal == FALSE))
						{
						/*Fix Bug# 46015
							Clear Deferred Proccessing flag when I-PDU state change
								from  START to STOP */
							#if u16NO_OF_IPDUS_STATUS > 0u
							SchM_Enter_Com_IPduStatus_03();
							Com_audteIPduStatus[u16CurrentIPduId] &= (Com_udtIPduStatus)(~(Com_u8DEF_PROC_MASK | Com_u8ACTIVE_MASK));
							SchM_Exit_Com_IPduStatus_03();
							#endif
						}
						else
						{
						}
						}
						else
						{
						}
					}
                  }  
			}
				
		
    /* Com-CDD-0180(0) */
    /*! copy the new ipduGroupVector to the local vector */
    for(u16ByteLoopIndex = 0; u16ByteLoopIndex <= Com_u16IPDUGROUPVCTRMAXIX;
        u16ByteLoopIndex++)
    {
      Com_au8eIPduGroupVector[u16ByteLoopIndex] =
                                              ipduGroupVector[u16ByteLoopIndex];
    }
  }
} /* Com_IpduGroupControl() */
/* PRQA S 4700 -- */
/* PRQA S 0715 -- */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/******************************************************************************/
/*! \Description This service checks the status of the I-PDU group containing \n
                 the I-PDU identified by PduId. This function is used at both \n
                 sender and receiver sides. This is an optimized version of \n
                 Com_bIpduCheckState
    \param[in]  PduId ID of the I-PDU to be checked
*******************************************************************************/
/*! \Trace_To Com-CDD-5746(0),
			  Com-CDD-5752(0) */
FUNC(boolean, COM_CODE)
              Com_bIpduCheckActive(CONST(PduIdType, AUTOMATIC) PduId)
{
  /*! Local variables */
  VAR(boolean, AUTOMATIC)     bRetunValue;

/* !Deviation: [3361]  This 'do - while' control expression has a constant,
'false' value. This is intended. (multi-line function like MACRO) */
/* PRQA S 3361 ++ */
	#if u16NO_OF_IPDUS_STATUS > 0u
	bRetunValue = ((Com_audteIPduStatus[PduId] & (Com_u8ACTIVE_MASK)) != FALSE);
	#endif
/* PRQA S 3361 -- */

  return bRetunValue;
}/* Com_bIpduCheckActive() */

/******************************************************************************/
/*! \Description This service sets all bits of the given \n
                 ipduGroupVector to 0. \n
                 This service is used by BSWM to clear the IPduGroup vector \n
                 allocated and managed by BSWM not the IPduGroupVector \n
                 allocated by COM.
    \param[in]  ipduGroupVector I-PDU group vector to be cleared
*******************************************************************************/
/*! \Trace_To Com-CDD-IpduGroupServices-0453(0),
              Com-CDD-IpduGroupServices-0454(0),
              Com-CDD-IpduGroupServices-0455(0),
              Com-CDD-0194(0) */
FUNC(void, COM_CODE) Com_ClearIpduGroupVector(
                          VAR(Com_IpduGroupVector, AUTOMATIC) ipduGroupVector)
{
/* PRQA S 0850 --                                                             */

  /*! DET check and reporting */
#if (COM_DEV_ERROR_DETECT == STD_ON)
  /* Com-CDD-IpduGroupServices-0454(0) */
if ( ipduGroupVector == NULL_PTR )
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_ClearIpduGroupVector , COM_E_PARAM_POINTER);
/* PRQA S 3212 -- */
  }
  else
#endif /*COM_DEV_ERROR_DETECT*/
  {
/* PRQA S 0850 ++                                                             */
    VAR(uint16_least, AUTOMATIC) u16ByteLoopIndex;
/* PRQA S 0850 --                                                             */

    for(u16ByteLoopIndex = 0; u16ByteLoopIndex <= Com_u16IPDUGROUPVCTRMAXIX;
         u16ByteLoopIndex++)
    {
      ipduGroupVector[u16ByteLoopIndex] = (uint8) 0;
    }
  }
} /* Com_ClearIpduGroupVector() */

/* !Deviation: [3673, 3206]  the prototype of this API is required by AUTOSAR */
/* PRQA S 3673 ++ */
/* PRQA S 3206 ++ */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/******************************************************************************/
/*! \Description This service sets the value of a bit in an I-PDU \n
                 group vector.  \n
                 This service is used by BSWM to modify the IPduGroup vector \n
                 allocated and managed by BSWM not the IPduGroupVector \n
                 allocated by COM.
    \param[in]  ipduGroupVector I-PDU group vector to be modified
    \param[in]  ipduGroupId ipduGroup ID used to identify the corresponding \n
                bit in the I-PDU group vector
    \param[in]  bitval New value of the corresponding bit
*******************************************************************************/
/*! \Trace_To Com-CDD-IpduGroupServices-0456(0),
              Com-CDD-IpduGroupServices-0457(0),
              Com-CDD-IpduGroupServices-0458(0),
              Com-CDD-IpduGroupServices-0459(0),
              Com-CDD-0195(0),
              Com-CDD-0196(0) */
FUNC(void, COM_CODE) Com_SetIpduGroup(
                          VAR(Com_IpduGroupVector, AUTOMATIC) ipduGroupVector,
                          VAR(Com_IpduGroupIdType, AUTOMATIC) ipduGroupId,
                          VAR(boolean, AUTOMATIC)             bitval)
{
/* PRQA S 0850 --                                                             */
/* PRQA S 3673 -- */
/* PRQA S 3206 -- */
  /*! DET check and reporting */
#if (COM_DEV_ERROR_DETECT == STD_ON)
  /* Com-CDD-IpduGroupServices-0458(0) */
  if ( ipduGroupVector == NULL_PTR )
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_SetIpduGroup , COM_E_PARAM_POINTER);
/* PRQA S 3212 -- */
  }
#if (COM_SUPPORTED_IPDU_GROUPS > 0U)
  /* Com-CDD-IpduGroupServices-0457(0) */
  else if ( ipduGroupId > ((uint16)COM_SUPPORTED_IPDU_GROUPS - (uint16)1))
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_SetIpduGroup , COM_E_PARAM);
/* PRQA S 3212 -- */
  }
#endif
  else
#endif /*COM_DEV_ERROR_DETECT*/
  {
#if (COM_SUPPORTED_IPDU_GROUPS > 0U)
    /* Com-CDD-0196(0) */
    Com_vidSETBIT(ipduGroupVector, ipduGroupId, bitval);
#endif
  }
} /* Com_SetIpduGroup() */


#if (Com_bTO_SUPPORT == STD_ON)
/* !Deviation: [4700] Metric thresholds Metric value out of threshold range.
Partitioning this function shall not pay for the negative effect of context
switching. */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description  This service initializes timeout for Rx I-PDU
    \param[in]  RxPduId I-PDU ID which timeout shall be reset
*******************************************************************************/
/*! \Trace_To   */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

FUNC(void, COM_CODE) Com_vidInitTORxIpdu(CONST(uint16, AUTOMATIC) ku16IPduIndex)
{
  VAR(uint8, AUTOMATIC)             u8CurrentSigType;
  VAR(uint16, AUTOMATIC)            u16CurrentNoOfSig;
  VAR(uint16, AUTOMATIC)            u16CurrentSigMapIndex;
  VAR(uint16, AUTOMATIC)            u16IPduTOIx;
  VAR(uint16, AUTOMATIC)            u16IPduFirstIx;
  VAR(uint16_least, AUTOMATIC)      u16SigLoopIndex;
  VAR(uint32, AUTOMATIC)            u32FirstTO;
  VAR(uint32, AUTOMATIC)            u32SGTO;
  VAR(uint32, AUTOMATIC)            u32SGFirstTO;
  VAR(uint16, AUTOMATIC)            u16SigTOTimerIx;
#if (((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)) \
     || (Com_u16NO_OF_SIGNAL > 0u))
  VAR(uint16, AUTOMATIC)            u16CurrentSigIx;
  P2CONST(Com_tstrSignalPB,AUTOMATIC,TYPEDEF) pkstrSignalPBPtr;
  P2VAR(uint32,AUTOMATIC,AUTOMATIC)pu32TOTPtr;
  P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,TYPEDEF) pkstrSigGroupPB;
#endif

  	P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF) pkstrIPduToSigMap;
	P2VAR(uint32,AUTOMATIC,AUTOMATIC)pu32TOT;
	P2CONST(Com_tstrRxIPdu,AUTOMATIC,TYPEDEF) pkstrRxIPduPtr ;

/* PRQA S 0850 --                                                             */

  pkstrRxIPduPtr  = pkstrGET_RX_IPDU_PTR_IX(ku16IPduIndex);
  u16IPduTOIx = pkstrRxIPduPtr->u16TOTimerIndex;
  if(u16IPduTOIx != 0xFFFFUL)
  {
	u16IPduFirstIx = pkstrRxIPduPtr->u16FirstTimeoutIndex;
	if(u16IPduFirstIx != (uint16)0xFFFFu)
    {
      /*! Reload I-PDU timeout timer by first timeout */
      SchM_Enter_Com_TimeoutTimer();
      u32RXIPDU_RLD_FTIMEOUT(u16IPduFirstIx, u16IPduTOIx);
      SchM_Exit_Com_TimeoutTimer();
    }
    else
    {
	  pu32TOT = pkstrGET_PB_TIMEOUT_TIMER(0);
      SchM_Enter_Com_TimeoutTimer();
      /*! Reload I-PDU timeout timer by timeout */
      pu32TOT[u16IPduTOIx] = pkstrRxIPduPtr->u32Timeout;
      SchM_Exit_Com_TimeoutTimer();
    }
  }
  else
  {

  }

  if((pkstrRxIPduPtr->udteRxIPduFlags & Com_u8RX_IPDUSIGTIMEOUT) != FALSE)
  {
    u16CurrentNoOfSig = pkstrRxIPduPtr->u16IPduNoOfSignals;
    u16CurrentSigMapIndex = pkstrRxIPduPtr->u16IPduSigMappingIndex;
#if (((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)) \
     || (Com_u16NO_OF_SIGNAL > 0u))
	pu32TOTPtr = pkstrGET_PB_TIMEOUT_TIMER(0);
#endif
    /*! for each signal/signal group in the I-PDU */
    for(u16SigLoopIndex = 0u; u16SigLoopIndex < u16CurrentNoOfSig;
        u16SigLoopIndex++)
	{
#if (((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON)) \
     || (Com_u16NO_OF_SIGNAL > 0u))
      pkstrIPduToSigMap = pkstrGET_IPDU_SGL_MAP_PTR((u16CurrentSigMapIndex + u16SigLoopIndex));
	  u16CurrentSigIx =
              pkstrIPduToSigMap->u16Index;
#endif
      u8CurrentSigType =
              pkstrIPduToSigMap->u8Type;
      switch(u8CurrentSigType)
      {
        case Com_u8SIGNAL:
#if Com_u16NO_OF_SIGNAL > 0u
        /*! If the signal has timeout configured*/
		pkstrSignalPBPtr = pkstrGET_PB_SIGNAL_PTR(u16CurrentSigIx);
		u16SigTOTimerIx =  pkstrSignalPBPtr->u16TOTimerIndex;
	if(u16SigTOTimerIx!= (uint16)0xFFFFu)
        {
          /*! Reload First timeout or timetout */
          u32FirstTO = pkstrSignalPBPtr->u32FirstTimeout;
		  if(u32FirstTO != 0xFFFFFFFFUL)
          {
            SchM_Enter_Com_TimeoutTimer();
            pu32TOTPtr[u16SigTOTimerIx] = u32FirstTO;
            SchM_Exit_Com_TimeoutTimer();
          }
          else
          {
            SchM_Enter_Com_TimeoutTimer();
            pu32TOTPtr[u16SigTOTimerIx] = pkstrSignalPBPtr->u32Timeout;
            SchM_Exit_Com_TimeoutTimer();
          }
        }
#endif
        break;
        case Com_u8SIGNALGROUP:
#if ((Com_u16NO_OF_GROUP_SIGSLT > 0u) && (Com_u16NO_OF_SIGNAL_GROUPSLT > 0u) && (Com_bSIGNAL_GROUP_SUPPORT == STD_ON))
        /*! If the signal group has timeout configured*/
        pkstrSigGroupPB = pkstrGET_PB_SIG_GRP_PTR(u16CurrentSigIx);
		u32SGTO = pkstrSigGroupPB->u32Timeout;
		u16SigTOTimerIx = pkstrSigGroupPB->u16TOTimerIndex;
		if(u16SigTOTimerIx != 0xFFFFu)
        {
          /*! Reload First timeout or timetout */
          
		  u32SGFirstTO = pkstrSigGroupPB->u32FirstTimeout;
		  if(u32SGFirstTO != 0xFFFFFFFFUL)
          {
            SchM_Enter_Com_TimeoutTimer();
            pu32TOTPtr[u16SigTOTimerIx] = u32SGFirstTO;
            SchM_Exit_Com_TimeoutTimer();
          }
          else
          {
            SchM_Enter_Com_TimeoutTimer();
            pu32TOTPtr[u16SigTOTimerIx] = u32SGTO;
            SchM_Exit_Com_TimeoutTimer();
          }
        }
#endif
        break;
        default:
        break;
      }
	}
  }
} /* Com_vidInitTORxIpdu */
/* PRQA S 4700 -- */
#endif


#if (Com_bTO_SUPPORT == STD_ON)
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/******************************************************************************/
/*! \Description  This service clears timeout for Tx I-PDU
    \param[in]  TxPduId I-PDU ID which timeout shall be cleared
*******************************************************************************/
/*! \Trace_To   */
FUNC(void, COM_CODE) Com_vidClearTOTxIpdu(CONST(uint16, AUTOMATIC) ku16TxPduIx)
{
  P2VAR(uint32,AUTOMATIC,AUTOMATIC) pu32TOT;
  P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF) pkstrTxIPduPtr;
/* PRQA S 0850 --                                                             */

  pu32TOT = pkstrGET_PB_TIMEOUT_TIMER(0);
  pkstrTxIPduPtr = pkstrGET_TX_IPDU_PTR(ku16TxPduIx);
  /*! Clear I-PDU timeout timer */
  SchM_Enter_Com_TimeoutTimer_03();
  pu32TOT[pkstrTxIPduPtr->u16TOTimerIndex] = (uint32)0;
  SchM_Exit_Com_TimeoutTimer_03();

} /* Com_vidClearTOTxIpdu */

#endif
/* !Deviation: [4700, 0715] Metric thresholds Metric value out of threshold
range.
This function is readable and easily debuggable because it consists of 2 main
blocks "I-PDU group changing from STOP to START" and "I-PDU group changing
from  START to STOP".*/
/* PRQA S 4700 ++ */
/* PRQA S 0715 ++ */

/* !Deviation: [3673]  The object addressed by the pointer parameter
ipduGroupVector is not modified and so the pointer could be of type
pointer to const. MISRA Rule 81.
The API prototype is required by Autosar */
/* PRQA S 3673 ++ */

/******************************************************************************/
/*! \Description  This service enables or disables I-PDU group Deadline \n
                  Monitoring.
    \param[in]  I-PDU group vector containing the requested deadline \n
                monitoring state (disabled = 0/ enabled = 1) for all I-PDU \n
                groups.
    \param[in,out]  None
*******************************************************************************/
/*! \Trace_To         Com-CDD-IpduGroupServices-0460(0),
                      Com-CDD-IpduGroupServices-0461(0),
                      Com-CDD-IpduGroupServices-0462(0),
                      Com-CDD-IpduGroupServices-0218(0),
                      Com-CDD-0184(0),
                      Com-CDD-0185(0),
                      Com-CDD-0187(0),
                      Com-CDD-0108(0),
                      Com-CDD-0109(0) 
					  Com-CDD-5746(0),
					  Com-CDD-5216(1),*/
#if (Com_bTO_SUPPORT == STD_ON)
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

FUNC(void, COM_CODE) Com_ReceptionDMControl(
                          VAR(Com_IpduGroupVector, AUTOMATIC)  ipduGroupVector)
/* PRQA S 0850 --                                                             */

/* PRQA S 3673 -- */
{
  /*! DET check and reporting */
#if (COM_DEV_ERROR_DETECT == STD_ON)
/*Com-CDD-IpduGroupServices-0449(0)*/
  if ( Com_enueStatus == COM_UNINIT)
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    /* Com-CDD-IpduGroupServices-0460(0) */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_ReceptionDMControl , COM_E_UNINIT);
/* PRQA S 3212 -- */
  }
  /*Com-CDD-IpduGroupServices-0451(0)*/
  else if ( ipduGroupVector == NULL_PTR )
  {
/* !Deviation: [3212] Redundant explicit type casting is mandatory to avoid
function return value ignoring */
/* PRQA S 3212 ++ */
    /* Com-CDD-IpduGroupServices-0461(0) */
    (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,
                    COMServiceId_ReceptionDMControl , COM_E_PARAM_POINTER);
/* PRQA S 3212 -- */
  }
  else
#endif /*COM_DEV_ERROR_DETECT*/
  {
  
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

    /*! Local variables */
    VAR(boolean, AUTOMATIC)     bOldBitVal;
    VAR(boolean, AUTOMATIC)     bNewBitVal;

    VAR(uint8_least, AUTOMATIC)       u8BitLoopIndex;
    VAR(uint8, AUTOMATIC)       u8OldByteVal;
    VAR(uint8, AUTOMATIC)       u8NewByteVal;

    VAR(uint8, AUTOMATIC)       u8CurrentIPduDir;

    VAR(uint16_least, AUTOMATIC)      u16ByteLoopIndex;
    VAR(uint16_least, AUTOMATIC)      u16IPduLoopIndex;
    VAR(uint16, AUTOMATIC)      u16CurrentNoOfIPdus;
    VAR(uint16, AUTOMATIC)      u16CurrentIPduMapIndex;
    VAR(uint16, AUTOMATIC)      u16CurrentIPduIndex;

    VAR(PduIdType, AUTOMATIC)   u16CurrentIPduId;

    VAR(Com_IpduGroupIdType, AUTOMATIC)
                                u16IPduGroupId;
                                
/* !Deviation: [8018, 8318, 8518]  VNR is repected for pointer to constant */
/* PRQA S 8018 ++ */
/* PRQA S 8318 ++ */
/* PRQA S 8518 ++ */
    /*! Local main Post-build configuration pointer */

	P2CONST(Com_tstrIPduGroup,AUTOMATIC,TYPEDEF) pkstrIPduGroupPtr;
	P2CONST(PduIdType,AUTOMATIC,TYPEDEF) pku16IPduGroupToIPduMapPtr;
	P2CONST(Com_tstrIPduLookUp,AUTOMATIC,TYPEDEF) pkstrIPduLookUpPtr;
	P2CONST(Com_tstrRxIPdu,AUTOMATIC,TYPEDEF) pkstrRxIPduPtr ;
/* PRQA S 8518 -- */
/* PRQA S 8318 -- */
/* PRQA S 8018 -- */
/* PRQA S 0850 --                                                             */

	pku16IPduGroupToIPduMapPtr = pkstrGET_IPDU_GRP_MAP(0);

    /*! loop on each bit in IPdu Group Vector byte*/
    for(u16ByteLoopIndex = 0; u16ByteLoopIndex <= Com_u16IPDUGROUPVCTRMAXIX;
        u16ByteLoopIndex++)
    {
      u8OldByteVal = Com_au8eRxDMIPduGroupVector[u16ByteLoopIndex];
      u8NewByteVal = ipduGroupVector[u16ByteLoopIndex];
      if(u8OldByteVal != u8NewByteVal)
      {
        for(u8BitLoopIndex = 0; u8BitLoopIndex <= (uint8)7;
          u8BitLoopIndex++)
        {
          bOldBitVal = bBYTE_MASK(u8OldByteVal,
                                          u8BitLoopIndex);
          bNewBitVal = bBYTE_MASK(u8NewByteVal,
                                          u8BitLoopIndex);
          if(bOldBitVal != bNewBitVal)
          {
            /*! I-PDU group state changed */
            /*! Calculate the IPduGroupId */
            u16IPduGroupId = (Com_IpduGroupIdType)((8 * u16ByteLoopIndex) +
                                  u8BitLoopIndex);
            
			pkstrIPduGroupPtr = pkstrGET_IPDUGRPCTRL_PTR(u16IPduGroupId);
			u16CurrentNoOfIPdus =
                            pkstrIPduGroupPtr->u16NoOfIPdus;
            u16CurrentIPduMapIndex =
                            pkstrIPduGroupPtr->u16IPduMappingIndex;

            if((bOldBitVal == FALSE) && (bNewBitVal == TRUE))
            {
              /*! I-PDU group changing from STOP to START */

              /*! For each I-PDU belongs to this I-PDU group */
              for(u16IPduLoopIndex = 0u;
                  u16IPduLoopIndex < u16CurrentNoOfIPdus;
                  u16IPduLoopIndex++)
              {
                u16CurrentIPduId =
                      pku16IPduGroupToIPduMapPtr[(u16CurrentIPduMapIndex +
                                             u16IPduLoopIndex)];
                pkstrIPduLookUpPtr = pkstrGET_IPDU_LOOK_UP_PTR(u16CurrentIPduId);
				u8CurrentIPduDir =
                      pkstrIPduLookUpPtr->u8Direction;

                /*! Deadline Monitoring Handling */
                /*! If I-PDU direction == RX initialize Timeout timers.*/
                /* Com-CDD-IpduGroupServices-0220(0) */
                if(u8CurrentIPduDir == Com_u8DIRECTION_RX)
                {
				u16CurrentIPduIndex =
                      pkstrIPduLookUpPtr->u16Index;
				pkstrRxIPduPtr = pkstrGET_RX_IPDU_PTR(u16CurrentIPduIndex);               
				 if(((pkstrRxIPduPtr->u16TOTimerIndex) != (uint16)0xFFFFu) ||
                      ((pkstrRxIPduPtr->udteRxIPduFlags & Com_u8RX_IPDUSIGTIMEOUT) != FALSE))
                  {
                    /*! Function call to init I-PDU based timeout timer and/or
                    signal based timeout timers with FirstTimeout or Timeout */
                    /* Com-CDD-IpduGroupServices-0218(0) */
                    Com_vidInitTORxIpdu(u16CurrentIPduIndex);
                  }
                  else
                  {
                  }
					#if u16NO_OF_IPDUS_STATUS > 0u
				    SchM_Enter_Com_IPduStatus_06();
		    		Com_audteIPduStatus[u16CurrentIPduId] |= Com_u8RX_DM_EN_TX_STOP; 
			    	SchM_Exit_Com_IPduStatus_06();
					#endif
                }
                else
                {
                }
              }
            
			
			}
            else if((bOldBitVal == TRUE) && (bNewBitVal == FALSE))
            {
              /*! I-PDU group changing from  START to STOP */
              /* Timeout timer shall not be reset here because it shall be
              reloaded upon starting monitoring for the same group */
			  for(u16IPduLoopIndex = 0u;
                  u16IPduLoopIndex < u16CurrentNoOfIPdus;
                  u16IPduLoopIndex++)
              {
                u16CurrentIPduId =
                      pku16IPduGroupToIPduMapPtr[(u16CurrentIPduMapIndex +
                                             u16IPduLoopIndex)];
                
				pkstrIPduLookUpPtr = pkstrGET_IPDU_LOOK_UP_PTR(u16CurrentIPduId);
				u8CurrentIPduDir =
                      pkstrIPduLookUpPtr->u8Direction;

                if(u8CurrentIPduDir == Com_u8DIRECTION_RX)
                {  
					#if u16NO_OF_IPDUS_STATUS > 0u
				    SchM_Enter_Com_IPduStatus_06();
		    		Com_audteIPduStatus[u16CurrentIPduId] &= (Com_udtIPduStatus)(~Com_u8RX_DM_EN_TX_STOP); 
			    	SchM_Exit_Com_IPduStatus_06();
					#endif
					
                }
                else
                {
                }
              }
			  
            }
            else
            {
              /* do nothing */
            }
          }
          else
          {
            /* Com-CDD-0183(0) */
            /*! If the status of the the I-PDU group was not changed,
            do nothing */
          }
        } /* ipduGroupVector bit loop */
      } /* if byte change */
      else
      {
        /* Com-CDD-0183(0) */
      }
    }/* ipduGroupVector byte loop */

    /*! copy the new ipduGroupVector to the local vector */
    for(u16ByteLoopIndex = 0; u16ByteLoopIndex <= Com_u16IPDUGROUPVCTRMAXIX;
        u16ByteLoopIndex++)
    {
      Com_au8eRxDMIPduGroupVector[u16ByteLoopIndex] =
                                              ipduGroupVector[u16ByteLoopIndex];
    }
  }
} /* Com_ReceptionDMControl() */
#endif
/* PRQA S 4700 -- */
/* PRQA S 0715 -- */

#if (Com_bTO_SUPPORT == STD_ON)
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/******************************************************************************/
/*! \Description This service checks the Rx deadline monitoring status of \n
                 the I-PDU group containing the I-PDU identified by PduId. \n
                  This function is used at receiver side only.
    \param[in]  PduId ID of the I-PDU to be checked
*******************************************************************************/
/*! \Trace_To  		 Com-CDD-5746(0), Com-CDD-5216(1)*/
FUNC(boolean, COM_CODE) Com_bIpduCheckRxDMActive(
                                        CONST(PduIdType, AUTOMATIC) ku16PduId)
{
  /*! Local variables */
	VAR(boolean, AUTOMATIC)     bRetunValue;

/* PRQA S 0850 --                                                             */
  	
	#if u16NO_OF_IPDUS_STATUS > 0u
	SchM_Enter_Com_IPduStatus_18();
	bRetunValue = ((Com_audteIPduStatus[ku16PduId] & (Com_u8RX_DM_EN_TX_STOP)) != FALSE);
	SchM_Exit_Com_IPduStatus_18();
	#endif
	
  return bRetunValue;
}/* Com_IpduCheckRxDMActive() */
#endif
/* !Deviation: [8019] COM_START_SEC_CODE is required by AUTOSAR */
/* PRQA S 8019 ++ */

/* !Deviation: [8519] COM_START_SEC_CODE is required by AUTOSAR */
/* PRQA S 8519 ++ */

/* !Deviation: [0838] Multiple Memmap.h inclusion is implied by AUTOSAR */
/* PRQA S 0838, 5087 L1 */
/* PRQA S  5087 L1 */
#define COM_STOP_SEC_CODE
#include "Memmap.h"
/* PRQA L:L1 */
/* PRQA L:L1 */

/* PRQA S 8019 -- */
/* PRQA S 8519 -- */

/** \} */ /* end of Com module group */
