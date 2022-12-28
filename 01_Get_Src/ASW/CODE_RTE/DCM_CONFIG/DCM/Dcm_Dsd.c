/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : Dsd                                                     */
/* !Description     : Dsd                                                     */
/*                                                                            */
/* !Module          : Dsd                                                     */
/* !File            : Dcm_Dsd.c                                               */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VALEO                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2010 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   Y:/Prod_01/B791031T0/archives/B791031T0/04_Software_Component$*/
/* $Revision::   1.34.1.1 $$Author::   ahmedz         $$Date::   Oct 05 2011 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file
*
* \par
*   Internals of the module DSD. \n
*   This file contains the internals of the module DSD.  */
/******************************************************************************/

/******************************************************************************/
/*! \defgroup  Dsd_Comp_Id Dsd Component
* DSD Component.
* \{
*/

/*! \defgroup Dsd_Module_Id Dsd Module
* This is the grouping of DSD module members.
* \{
*/
/******************************************************************************/


/******************************************************************************/
/* Includes                                                                   */
/******************************************************************************/

/* !Deviation : Re-Including autosar MemMap.h   */
/* PRQA S 0838 L1                                                             */
#include "Dcm.h"
#include "Dcm_Internal.h"
/* PRQA L:L1                                                                  */
#include "Rte_Dcm.h"
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
#include "SchM_Dcm.h"
#endif
/* !Deviation : Re-Including autosar MemMap.h   */
/* PRQA S 0838 L1                                                             */
#if(DCM_bDIAG_SERV_IS_CALLOUT == STD_ON)
#include "Dcm_Callouts.h"
#endif
/* PRQA L:L1                                                                  */
 
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/*! \Description Indicates that the request is received using functional
                  addressing.  \n
  \Range         1 \n
*******************************************************************************/
#define bFUNC_REQ 1

/******************************************************************************/
/*! \Description Indicates that the request is received using Physical
                  addressing.  \n
  \Range         0 \n
*******************************************************************************/
#define bPHYS_REQ 0

/******************************************************************************/
/*! \Description Indicates that positive response should be suppressed. \n
  \Range         TRUE \n
*******************************************************************************/
#define bSUPPRESS_RESP TRUE

/******************************************************************************/
/*! \Description Indicates that positive response should not be suppressed. \n
  \Range         FALSE \n
*******************************************************************************/
#define bDONOT_SUPPRESS_RESP FALSE

/******************************************************************************/
/*! \Description Used to Mask the suppressPosRspMsgIndicationBit.   \n
  \Range         0x80 \n
*******************************************************************************/
#define u8CHK_POS_RESP_BIT (uint8)0x80

/******************************************************************************/
/*! \Description Used as a Mask to clear the suppressPosRspMsgIndicationBit.  \n
  \Range         0x7F \n
*******************************************************************************/
#define u8CLR_POS_RESP_BIT (uint8)0x7F

/******************************************************************************/
/*! \Description Used as a Mask to get the positive response service ID from\n
                 the request service Id.
  \Range         0x40 \n
*******************************************************************************/
#define u8POS_SID_MASK (uint8)0x40



/******************************************************************************/
/*! \Description The Low invalid Request Service Id in First range.  \n
  \Range         0x40 \n
*******************************************************************************/
#define u8INV_SID_LOW_RANGE_1 (uint8)0x40

/******************************************************************************/
/*! \Description The High invalid Request Service Id in First range.  \n
  \Range         0x7F \n
*******************************************************************************/
#define u8INV_SID_HIGH_RANGE_1 (uint8)0x7F

/******************************************************************************/
/*! \Description The Low invalid Request Service Id in Second range. \n
  \Range         0xC0 \n
*******************************************************************************/
#define u8INV_SID_LOW_RANGE_2 (uint8)0xC0

/******************************************************************************/
/*! \Description The High invalid Request Service Id in Second range. \n
  \Range         0xFF \n
*******************************************************************************/
#define u8INV_SID_HIGH_RANGE_2 (uint8)0xFF


/******************************************************************************/
/*! \Description SecurityAccess Service ID. \n
  \Range         0x27 \n
*******************************************************************************/
#define u8SEC_ACCESS_SID (uint8)0x27

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/


/* !Deviation : Inhibit MISRA rule: Implemented as a macro for optimization   */
/* PRQA S 3453 ++                                                             */

/******************************************************************************/
/*!   \Description Used to return the Number of Services in a service Table. \n

   \return      Number of Services.
*******************************************************************************/
#define u8NUM_SERVS(u8ProtocolSIDTable) Dcm_kstreDsdConfig.\
                               astrDcmDsdServiceTable[u8ProtocolSIDTable].\
                               u8NumOfServ

/******************************************************************************/
/*!   \Description Used to return the Number of SubFunctions configured in \n
                   a Service.\n

   \return      Number of SubFunctions.
*******************************************************************************/
#define u8NUM_SUBFUNC(u8ProtocolSIDTable,u8ServiceCount)\
    Dcm_kstreDsdConfig.astrDcmDsdServiceTable[u8ProtocolSIDTable].\
    ppkstrDcmDsdService[u8ServiceCount]->u8NumOfSubServices

/******************************************************************************/
/*!   \Description Used to return the Number of configured sessions per Service.

   \return      Number of Sessions.
*******************************************************************************/
#define u8NUM_SERV_SESS(u8ProtocolSIDTable,u8ServiceCount)\
    Dcm_kstreDsdConfig.astrDcmDsdServiceTable[u8ProtocolSIDTable].\
    ppkstrDcmDsdService[u8ServiceCount]->u8NumOfSessionRef

/******************************************************************************/
/*!   \Description Used to return the Number of configured session references
                 per SubFunction.

   \return      Number of Session references.
*******************************************************************************/
#define u8NUM_SUBFUNC_SESS(u8ProtocolSIDTable,u8ServiceCount,u8SubServiceCount)\
    Dcm_kstreDsdConfig.astrDcmDsdServiceTable[u8ProtocolSIDTable].\
    ppkstrDcmDsdService[u8ServiceCount]->\
    pkstrDcmDsdSubService[u8SubServiceCount].\
    u8NumOfSessionRef

/******************************************************************************/
/*!   \Description Used to return the Number of configured Security references
                 per Service. \n

   \return      Number of Security references .
*******************************************************************************/
#define u8NUM_SERV_SEC(u8ProtocolSIDTable,u8ServiceCount)\
    Dcm_kstreDsdConfig.astrDcmDsdServiceTable[u8ProtocolSIDTable].\
    ppkstrDcmDsdService[u8ServiceCount]->\
    u8NumOfSecurityRef


/******************************************************************************/
/*!   \Description Used to return the Number of configured Security references
                 per SubFunction. \n

   \return      Number of Security references .
*******************************************************************************/
#define u8NUM_SUBFUNC_SEC(u8ProtocolSIDTable,u8ServiceCount,u8SubServiceCount)\
    Dcm_kstreDsdConfig.astrDcmDsdServiceTable[u8ProtocolSIDTable].\
    ppkstrDcmDsdService[u8ServiceCount]->\
    pkstrDcmDsdSubService[u8SubServiceCount].\
    u8NumOfSecurityRef

/******************************************************************************/
/*!   \Description Used to return the Service ID \n

   \return      Service ID.
*******************************************************************************/
#define u8SERV_ID(u8ProtocolSIDTable,u8ServiceCount)\
    Dcm_kstreDsdConfig.astrDcmDsdServiceTable[u8ProtocolSIDTable].\
    ppkstrDcmDsdService[u8ServiceCount]->u8DcmDsdSidTabServiceId

/******************************************************************************/
/*!   \Description Used to return the SubFunction ID \n

   \return      SubFunction ID.
*******************************************************************************/
#define u8SUBFUNC_ID(u8ProtocolSIDTable,u8ServiceCount,u8SubServiceCount)\
    Dcm_kstreDsdConfig.astrDcmDsdServiceTable[u8ProtocolSIDTable].\
    ppkstrDcmDsdService[u8ServiceCount]->\
    pkstrDcmDsdSubService[u8SubServiceCount].\
    u8DcmDsdSubServiceId

/******************************************************************************/
/*!   \Description Used to return the allowed addressing mode of the Service.\n

   \return      allowed addressing mode of the Service.
*******************************************************************************/
#define u8SERV_ADDR_MODE(u8ProtocolSIDTable,u8ServiceCount)\
    Dcm_kstreDsdConfig.astrDcmDsdServiceTable[u8ProtocolSIDTable].\
    ppkstrDcmDsdService[u8ServiceCount]->\
    u8DcmDsdServAddrMode

/******************************************************************************/
/*!   \Description Used to return Pointer to the first session reference of the
                 Service.\n

   \return     Pointer to the first session reference of the Service.
*******************************************************************************/
#define ppkstrSERV_SESS_REF(u8ProtocolSIDTable,u8ServiceCount)\
    Dcm_kstreDsdConfig.astrDcmDsdServiceTable[u8ProtocolSIDTable].\
    ppkstrDcmDsdService[u8ServiceCount]->\
    ppkstrDcmDsdSidTabSessionLevelRef

/******************************************************************************/
/*!   \Description Used to return Pointer to the first Security reference of the
                 Service.\n

   \return     Pointer to the first session reference of the Service.
*******************************************************************************/
#define ppkstrSERV_SEC_REF(u8ProtocolSIDTable,u8ServiceCount)\
    Dcm_kstreDsdConfig.astrDcmDsdServiceTable[u8ProtocolSIDTable].\
    ppkstrDcmDsdService[u8ServiceCount]->\
    ppkstrDcmDsdSidTabSecurityLevelRef


/******************************************************************************/
/*!  \Description Used to return the SubFunction availability for the service\n

   \return     SubFunction availability for the service.
*******************************************************************************/
#define bSERV_SUBFUNC_AVAIL(u8ProtocolSIDTable,u8ServiceCount)\
    Dcm_kstreDsdConfig.astrDcmDsdServiceTable[u8ProtocolSIDTable].\
    ppkstrDcmDsdService[u8ServiceCount]->\
    bDcmDsdSidTabSubfuncAvail

/******************************************************************************/
/*!   \Description Used to return whether the service is implemented as callout
                 or not.\n

   \return     The Service is Callout or not.
*******************************************************************************/
#define bSERV_IS_CALLOUT(u8ProtocolSIDTable,u8ServiceCount)\
    Dcm_kstreDsdConfig.astrDcmDsdServiceTable[u8ProtocolSIDTable].\
    ppkstrDcmDsdService[u8ServiceCount]->\
    bDcmDsdIsCallout


/******************************************************************************/
/*!   \Description Used to return the session level in certain session reference
                 of a service.

   \return     Session Level.
*******************************************************************************/
#define u8SERV_SESS_LEV(u8ProtocolSIDTable,u8ServiceCount,u8SessionCount)\
    Dcm_kstreDsdConfig.astrDcmDsdServiceTable[u8ProtocolSIDTable].\
    ppkstrDcmDsdService[u8ServiceCount]->\
    ppkstrDcmDsdSidTabSessionLevelRef[u8SessionCount]->\
    u8DcmDspSessionLevel

/******************************************************************************/
/*!   \Description Used to return the security level in certain security
                   reference of a service.

   \return     Security Level.
*******************************************************************************/
#define u8SERV_SEC_LEVEL(u8ProtocolSIDTable,u8ServiceCount,u8SecurityCount)\
    Dcm_kstreDsdConfig.astrDcmDsdServiceTable[u8ProtocolSIDTable].\
    ppkstrDcmDsdService[u8ServiceCount]->\
    ppkstrDcmDsdSidTabSecurityLevelRef[u8SecurityCount]->\
    u8DcmDspSecurityLevel

/******************************************************************************/
/*!   \Description Used to return Pointer to the first Security reference of the
                 SubFunction.\n

   \return     Pointer to the first Security reference of the SubFunction.
*******************************************************************************/
#define ppkstrSUBFUNC_SEC_REF(u8ProtocolSIDTable,u8ServiceCount,\
                              u8SubServiceCount)\
  Dcm_kstreDsdConfig.astrDcmDsdServiceTable[u8ProtocolSIDTable].\
  ppkstrDcmDsdService[u8ServiceCount]->\
  pkstrDcmDsdSubService[u8SubServiceCount].\
  ppkstrDcmDsdSubServiceSecurityLevelRef

/******************************************************************************/
/*!   \Description Used to return Pointer to the first Session reference of the
                 SubFunction\n

   \return     Pointer to the first session reference of the SubFunction.
*******************************************************************************/
#define ppkstrSUBFUNC_SES_REF(u8ProtocolSIDTable,u8ServiceCount,\
                              u8SubServiceCount)\
  Dcm_kstreDsdConfig.astrDcmDsdServiceTable[u8ProtocolSIDTable].\
  ppkstrDcmDsdService[u8ServiceCount]->\
  pkstrDcmDsdSubService[u8SubServiceCount].\
  ppkstrDcmDsdSubServiceSessionLevelRef


/******************************************************************************/
/*!   \Description Used to return the session level in certain session reference
                 of a SubFunction.

   \return     Session Level
*******************************************************************************/
#define u8SUBFUNC_SES_LEV(u8ProtocolSIDTable,u8ServiceCount,u8SubServiceCount,\
                          u8SessionCount)\
    Dcm_kstreDsdConfig.astrDcmDsdServiceTable[u8ProtocolSIDTable].\
    ppkstrDcmDsdService[u8ServiceCount]->\
    pkstrDcmDsdSubService[u8SubServiceCount].\
    ppkstrDcmDsdSubServiceSessionLevelRef[u8SessionCount]->\
    u8DcmDspSessionLevel

/******************************************************************************/
/*!   \Description Used to return the Security level in certain Security
                   reference of a SubFunction.

   \return     Security Level
*******************************************************************************/
#define u8SUBFUNC_SEC_LEV(u8ProtocolSIDTable,u8ServiceCount,u8SubServiceCount,\
                          u8SecurityCount)\
    Dcm_kstreDsdConfig.astrDcmDsdServiceTable[u8ProtocolSIDTable].\
    ppkstrDcmDsdService[u8ServiceCount]->\
    pkstrDcmDsdSubService[u8SubServiceCount].\
    ppkstrDcmDsdSubServiceSecurityLevelRef[u8SecurityCount]->\
    u8DcmDspSecurityLevel
/* PRQA S 3453 --                                                             */



/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/*! \Description Message Response Type. \n\n
  \Range       u8POS_RESP,u8NEG_RESP \n\n
*******************************************************************************/
typedef uint8 tu8ResponseType;
/******************************************************************************/
/*! \Description Indicates positive response. \n\n
    \Range       0x00 \n\n
*******************************************************************************/
#define u8POS_RESP (uint8)0x00
/******************************************************************************/
/*! \Description Indicates Negative response. \n\n
    \Range       0x01 \n\n
*******************************************************************************/
#define u8NEG_RESP (uint8)0x01

/******************************************************************************/
/*! \Description Message Information Structure Type. \n\n
*******************************************************************************/
typedef struct{
  /*! \Description Indicates the Type of the response message. \n\n
      \Range       u8POS_RESP,u8NEG_RESP \n\n  */
  tu8ResponseType   u8ResponseType;
#if(DCM_bDIAG_SERV_IS_CALLOUT == STD_ON)
  /*! \Description Indicates whether the requested service is
                   callout or not.\n
      \Range       TRUE,FALSE \n\n  */
  boolean bIsCallout;
#endif
  /*! \Description Pointer to TX Buffer. \n\n */
  Dcm_MsgType pu8TxBuffer;
  /*! \Description Pointer to RX Buffer. \n\n */
  Dcm_MsgType pu8RxBuffer;
  /*! \Description Indicates that the response is originated from the DSD. \n
      \Range       TRUE,FALSE \n\n  */
  boolean bInternalResp;
} tstrMsgInfoType;


/* !Deviation : Re-Including autosar MemMap.h   */
/* PRQA S 0838 L1                                                             */

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)


#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"


/******************************************************************************/
/*!   \Description Pointer to Paged Buffer Message Context Structure. \n\n
      \Range       NOT NULL \n\
*******************************************************************************/
#if(DCM_bROE_ENABLED == STD_ON)
static P2VAR(Dcm_MsgContextType,DCM_VAR,DCM_VAR) Dsd_apstrPbMsgContext[2];
#else
static P2VAR(Dcm_MsgContextType,DCM_VAR,DCM_VAR) Dsd_apstrPbMsgContext[1];
#endif

#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"


#define DCM_START_SEC_VAR_16BIT
#include "MemMap.h"
/******************************************************************************/
/*!   \Description Paged Buffer Timeout Counter. \n\n
       \Range  0..65535
*******************************************************************************/
#if(DCM_bROE_ENABLED == STD_ON)
static VAR(uint16,DCM_VAR)  Dsd_au16PbCount[2];
#else
static VAR(uint16,DCM_VAR)  Dsd_au16PbCount[1];
#endif
#define DCM_STOP_SEC_VAR_16BIT
#include "MemMap.h"



#define DCM_START_SEC_VAR_BOOLEAN
#include "MemMap.h"

/******************************************************************************/
/*!   \Description Used to Indicate that the First Page is requested. \n\n
      \Range  TRUE,FALSE
*******************************************************************************/
#if(DCM_bROE_ENABLED == STD_ON)
static VAR(boolean,DCM_VAR) Dsd_abFirstPage[2];
#else
static VAR(boolean,DCM_VAR) Dsd_abFirstPage[1];
#endif


/******************************************************************************/
/*!   \Description Used to Indicate whether the Paged Buffer Timer is On. \n\n
      \Range  TRUE,FALSE
*******************************************************************************/
#if(DCM_bROE_ENABLED == STD_ON)
static VAR(boolean,DCM_VAR) Dsd_abPbTimerOn[2];
#else
static VAR(boolean,DCM_VAR) Dsd_abPbTimerOn[1];
#endif

#define DCM_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#endif /*DCM_PAGED_BUFFER_ENABLED == STD_ON*/

#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/******************************************************************************/
/*!   \Description Holds Information about the request message. \n\n
*******************************************************************************/
static VAR(tstrMsgInfoType,DCM_VAR)
    Dsd_strMsgInfo[DspInternal_u8MAX_NUM_INTERNAL_REQ];
#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"


/******************************************************************************/
/* LOCAL FUNCTION Declaration                                                 */
/******************************************************************************/



#define DCM_START_SEC_CODE
#include "MemMap.h"

static FUNC(void,DCM_CODE) vidSetNegResponse(
    CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) kpstrMsgContext ,
    uint8 u8NegRespCode);

#if(DCM_REQUEST_MANUF_SUPPL_INDIC_EN == STD_ON)
static FUNC(boolean,DCM_CODE) bManufSupplIndicCheck(
    uint8 u8CurrentSid,
    CONSTP2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) kpkstrMsgContext,
    CONSTP2VAR(uint8, AUTOMATIC,AUTOMATIC) kpu8NegCode);

#endif
    
#if(DCM_REQUEST_SUPPLIER_INDICATION_ENABLED == STD_ON)
static FUNC(boolean,DCM_CODE) bDsdSupplIndicCheck(
       uint8 u8CurrentSid,
       CONSTP2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) kpkstrMsgContext,
       CONSTP2VAR(uint8, AUTOMATIC,AUTOMATIC) kpu8NegCode);
#endif

#if(DCM_REQUEST_MANUFACTURER_INDICATION_ENABLED == STD_ON)
static FUNC(boolean,DCM_CODE) bManufIndicCheck(
    uint8 u8CurrentSid,    
    CONSTP2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) kpkstrMsgContext,
    CONSTP2VAR(uint8, AUTOMATIC,AUTOMATIC) kpu8NegCode);
#endif

static FUNC(boolean,DCM_CODE) bCheckServSupported(
    uint8 u8CurrentSid,
    uint8 u8ProtocolSIDTable,
    CONSTP2CONST(Dcm_MsgContextType, AUTOMATIC,AUTOMATIC) kpkstrMsgContext,
    CONSTP2VAR(uint8, AUTOMATIC,AUTOMATIC) kpu8ServiceIndex);


static FUNC(boolean,DCM_CODE) bCheckSubFuncSupp(
    uint8 u8ServiceIndex,
    uint8 u8ProtocolSIDTable,
    CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC,AUTOMATIC) kpstrMsgContext,
    CONSTP2VAR(uint8, AUTOMATIC,AUTOMATIC) kpu8SubFuncIndex);


static FUNC(boolean,DCM_CODE) bCheckServSecurity(
    uint8 u8ProtocolSIDTable,
    uint8 u8ServiceIndex);


static FUNC(boolean,DCM_CODE) bCheckServSession(
    uint8 u8ProtocolSIDTable,
    uint8 u8ServiceIndex);

static FUNC(boolean,DCM_CODE) bCheckSubFuncSecurity(
    uint8 u8ProtocolSIDTable,
    uint8 u8ServiceIndex,
    uint8 u8SubFuncIndex);

static FUNC(boolean,DCM_CODE) bCheckSubFuncSession(
    uint8 u8ProtocolSIDTable,
    uint8 u8ServiceIndex,
    uint8 u8SubFuncIndex);


/* PRQA L:L1                                                                  */

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/



/******************************************************************************/
/*! \Description Internal function used by the DSD to send negative responses.\n

  \param[in] pMsgContext   Pointer to the MsgContext struct.
             \Range   NOT NULL  \n
  \param[in] u8NegRespCode   Negative response error code. \n
             \Range   0x00..0XFF  \n
  \return      void.  
  \Trace_To : CDD-0932(0),CDD-0933(0),CDD-0935(0),CDD-0936(0),CDD-0937(0),
              CDD-0938(0),CDD-0943(0)
*******************************************************************************/
static FUNC(void,DCM_CODE) vidSetNegResponse(
    CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) kpstrMsgContext ,
    uint8 u8NegRespCode)
{
  /*! Set resData to point to the first byte in Tx Buffer */
  kpstrMsgContext->resData =
      Dsd_strMsgInfo[kpstrMsgContext->idContext].pu8TxBuffer;

  /*! IF the [request is functional and the error code  equal to
      DCM_E_SERVICENOTSUPPORTED or
      DCM_E_SUBFUNCTIONNOTSUPPORTED or DCM_E_REQUESTOUTOFRANGE] OR the
      error code equal to DCM_u8E_SUPPRESS_RESPONSE THEN  */
  if (((kpstrMsgContext->msgAddInfo.reqType == bFUNC_REQ)
      && ((u8NegRespCode == DCM_E_SERVICENOTSUPPORTED) ||
          (u8NegRespCode == DCM_E_SUBFUNCTIONNOTSUPPORTED) ||
          (u8NegRespCode == DCM_E_REQUESTOUTOFRANGE)))
          || (u8NegRespCode == DCM_u8E_SUPPRESS_RESPONSE))

  {
    /*! DO NOTHING */

  }
  /*! ELSE  */
  else
  {
    /*!Set bInternalResp to TRUE */
    Dsd_strMsgInfo[kpstrMsgContext->idContext].bInternalResp = TRUE;

    /*! set First Byte in TX buffer with DspInternal_u8SID_NEG_RESP  */
    Dsd_strMsgInfo[kpstrMsgContext->idContext].pu8TxBuffer[0] =
        DspInternal_u8SID_NEG_RESP;

    /*! set Second Byte in TX buffer with request service ID  */
    Dsd_strMsgInfo[kpstrMsgContext->idContext].pu8TxBuffer[1] =
        Dsd_strMsgInfo[kpstrMsgContext->idContext].pu8RxBuffer[0];

    /*! set Third Byte in TX buffer with u8NegRespCode  */
    Dsd_strMsgInfo[kpstrMsgContext->idContext].pu8TxBuffer[2] =
        u8NegRespCode;

    /*! set resDataLen with DspInternal_u8NEG_RESPONSE_LENGTH  */
    kpstrMsgContext->resDataLen = (Dcm_MsgLenType)DspInternal_u8NEG_RESPONSE_LENGTH;

  }
  /*! END IF  */

}


#if(DCM_REQUEST_MANUFACTURER_INDICATION_ENABLED == STD_ON)

/******************************************************************************/
/*! \Description Performs the Manufacturer Check for the requested service.\n
    \param[in]  u8CurrentSid   Service ID. \n
    \Range       0..255  \n
    \param[in] kpkstrMsgContext   Pointer to the MsgContext struct.
    \Range     NOT NULL  \n
    \param[out] kpu8NegCode   Pointer to Negative response error code which
                              is returned if check failed. \n
    \Range        NOT NULL  \n
    \return      TRUE is return if check failed, otherwise FALSE is returned.
*******************************************************************************/
static FUNC(boolean,DCM_CODE) bManufIndicCheck(
    uint8 u8CurrentSid,    
    CONSTP2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) kpkstrMsgContext,
    CONSTP2VAR(uint8, AUTOMATIC,AUTOMATIC) kpu8NegCode)
{

#if(DCM_u8NUM_OF_MANUF_INDIC != 1U)
  uint8                        u8LoopIndex;
  boolean                      bNotOkReturned = FALSE;
  Dcm_NegativeResponseCodeType u8NotOkErrorCode = 0;
#endif

  Std_ReturnType               u8ManufReturn;
  boolean                      bCheckFailed      = FALSE;
#if(DCM_u8NUM_OF_MANUF_INDIC != 1U)
  boolean                      bLoopEnd;
#endif

#if(DCM_u8NUM_OF_MANUF_INDIC != 1U)
  bLoopEnd = FALSE;
  /*! Loop through all configured Manufacture Indication Functions */
  for(u8LoopIndex = 0;(u8LoopIndex < (uint8)DCM_u8NUM_OF_MANUF_INDIC) &&
  (bLoopEnd == FALSE);u8LoopIndex++)
  {
#endif

    /*! Call the current Xxx_ManufacturerIndication with the following params:
     * 1) Service Identifier
     * 2) reqData
     * 3) reqDataLen
     * 4) The Address of the local variable used to get the ErrorCode*/
  #if(DCM_u8NUM_OF_MANUF_INDIC == 1U)
/* !Deviation : Indentation deviation because it is dependent on the
                configuration.   */
/* PRQA S 2215 L1                                                         */ 

    u8ManufReturn = (*Dcm_kstreDslConfig.apfu8ManufIndication[0])
                     (u8CurrentSid,
                         kpkstrMsgContext->reqData,
                         (uint16)kpkstrMsgContext->reqDataLen,
                         kpkstrMsgContext->msgAddInfo.reqType,
                         (uint8)kpkstrMsgContext->dcmRxPduId,
                         kpu8NegCode);
/* PRQA L:L1                                                                  */

  #endif
#if(DCM_u8NUM_OF_MANUF_INDIC != 1U)
    u8ManufReturn =
        (*Dcm_kstreDslConfig.apfu8ManufIndication[u8LoopIndex])
                         (u8CurrentSid,
                          kpkstrMsgContext->reqData,
                          (uint16)kpkstrMsgContext->reqDataLen,
                          kpkstrMsgContext->msgAddInfo.reqType,
                          (uint8)kpkstrMsgContext->dcmRxPduId,
                          kpu8NegCode);
#endif

    /*! IF the function return value is E_REQUEST_NOT_ACCEPTED THEN */
    if(u8ManufReturn == E_REQUEST_NOT_ACCEPTED)
    {
#if(DCM_u8NUM_OF_MANUF_INDIC != 1U)
      /*! Set the For Loop End Flag to TRUE */
      bLoopEnd = TRUE;
#endif

      /*! Set the Check Failed Flag to TRUE */
      bCheckFailed = TRUE;

      /*! Set the returned negative response code to zero. */
      *kpu8NegCode = 0;

    }
    /*! ELSE IF the return value is E_NOT_OK THEN */
    else if (u8ManufReturn == E_NOT_OK)
    {
#if(DCM_u8NUM_OF_MANUF_INDIC != 1U)
      /*! Set bNotOkReturned to TRUE */
      bNotOkReturned = TRUE;
      /*! Set u8NotOkErrorCode to code returned by
       *  Xxx_ManufacturerIndication.*/
      u8NotOkErrorCode = *kpu8NegCode;
#endif
#if(DCM_u8NUM_OF_MANUF_INDIC == 1U)
      /*! Set the Check Failed Flag to TRUE */
      bCheckFailed = TRUE;

#endif

    }
    /*! ELSE */
    else
    {
      /*! DO NOTHING */

    }
    /*! END IF */
#if(DCM_u8NUM_OF_MANUF_INDIC != 1U)
  }
  /*! END LOOP */
#endif

#if(DCM_u8NUM_OF_MANUF_INDIC != 1U)

  /*! IF the Check Failed Flag is  TRUE and bNotOkReturned is TRUE Then */
  if((bCheckFailed == FALSE) && (bNotOkReturned == TRUE))
  {

    /*! Set the Check Failed Flag to TRUE */
    bCheckFailed = TRUE;

    /*! Set the returned negative response code to u8NotOkErrorCode. */
    *kpu8NegCode = u8NotOkErrorCode;

  }
#endif

  /*! Return bCheckFailed*/
  return(bCheckFailed);

}
#endif

#if(DCM_REQUEST_SUPPLIER_INDICATION_ENABLED == STD_ON)

/******************************************************************************/
/*! \Description Performs the Supplier Check for the requested service.\n
    \param[in]  u8CurrentSid   Service ID. \n
    \Range       0..255  \n
    \param[in] kpkstrMsgContext   Pointer to the MsgContext struct.
    \Range     NOT NULL  \n
    \param[out] kpu8NegCode   Pointer to Negative response error code which
                              is returned if check failed. \n
    \Range        NOT NULL  \n
    \return      TRUE is return if check failed, otherwise FALSE is returned.
*******************************************************************************/
static FUNC(boolean,DCM_CODE) bDsdSupplIndicCheck(
       uint8 u8CurrentSid,    
       CONSTP2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) kpkstrMsgContext,
       CONSTP2VAR(uint8, AUTOMATIC,AUTOMATIC) kpu8NegCode)
{

#if(DCM_u8NUM_OF_SUPPL_INDIC != 1U)
  uint8                        u8LoopIndex;
  boolean                      bNotOkReturned = FALSE;
  Dcm_NegativeResponseCodeType u8NotOkErrorCode = 0;
#endif
  Std_ReturnType               u8SupplReturn;
  boolean                      bCheckFailed      = FALSE;
#if(DCM_u8NUM_OF_SUPPL_INDIC != 1U)
  boolean                      bLoopEnd;
#endif

#if(DCM_u8NUM_OF_SUPPL_INDIC != 1U)
  /*! Set the Loop End Flag to FALSE */
  bLoopEnd = FALSE;

  /*! Loop through all configured Supplier Indication Functions */
  for(u8LoopIndex = 0;(u8LoopIndex < (uint8)DCM_u8NUM_OF_SUPPL_INDIC) &&
  (bLoopEnd == FALSE);u8LoopIndex++)
  {
#endif

    /*! Call the current Xxx_SupplierIndication with the following params:
     * 1) Service Identifier
     * 2) reqData
     * 3) reqDataLen
     * 4) The Address of the local variable used to get the ErrorCode*/
#if(DCM_u8NUM_OF_SUPPL_INDIC != 1U)
    u8SupplReturn = (*Dcm_kstreDslConfig.apfu8SupplierIndication[u8LoopIndex])
                           (u8CurrentSid,
                            kpkstrMsgContext->reqData,
                            (uint16)kpkstrMsgContext->reqDataLen,
                            kpkstrMsgContext->msgAddInfo.reqType,
                            (uint8)kpkstrMsgContext->dcmRxPduId,
                            kpu8NegCode);
#endif

#if(DCM_u8NUM_OF_SUPPL_INDIC == 1U)
/* !Deviation : Indentation deviation because it is dependent on the
                configuration.   */
/* PRQA S 2215 L1                                                         */
    u8SupplReturn = (*Dcm_kstreDslConfig.apfu8SupplierIndication[0])(
        u8CurrentSid,
        kpkstrMsgContext->reqData,
        (uint16)kpkstrMsgContext->reqDataLen,
        kpkstrMsgContext->msgAddInfo.reqType,
        (uint8)kpkstrMsgContext->dcmRxPduId,
        kpu8NegCode);
/* PRQA L:L1                                                                  */
#endif

/*! IF the function return value is E_REQUEST_NOT_ACCEPTED THEN */
    if(u8SupplReturn == E_REQUEST_NOT_ACCEPTED)
    {
#if(DCM_u8NUM_OF_SUPPL_INDIC != 1U)
      /*! Set the For Loop End Flag to TRUE */
      bLoopEnd = TRUE;
#endif

      /*! Set the Check Failed Flag to TRUE */
      bCheckFailed = TRUE;

      /*! Set the returned negative response code to 0. */
      *kpu8NegCode = 0;


    }
    /*! ELSE IF the return value is E_NOT_OK THEN */
    else if (u8SupplReturn == E_NOT_OK)
    {
#if(DCM_u8NUM_OF_SUPPL_INDIC != 1U)

      /*! Set bNotOkReturned to TRUE. */
      bNotOkReturned = TRUE;
      /*! Set u8NotOkErrorCode with error code returned by
       *  Xxx_SupplierIndication.
       */
      u8NotOkErrorCode = *kpu8NegCode;
#endif
#if(DCM_u8NUM_OF_SUPPL_INDIC == 1U)
      /*! Set the Check Failed Flag to TRUE */
      bCheckFailed = TRUE;

#endif

    }
    /*! ELSE */
    else
    {
      /*! DO NOTHING */
    }
    /*! ENDIF */
#if(DCM_u8NUM_OF_SUPPL_INDIC != 1U)

  }
  /*! END LOOP */
#endif

#if(DCM_u8NUM_OF_SUPPL_INDIC != 1U)

  /*! IF the Check Failed Flag is  TRUE and bNotOkReturned is TRUE Then */
  if((bCheckFailed == FALSE) && (bNotOkReturned == TRUE))
  {

    /*! Set the Check Failed Flag to TRUE */
    bCheckFailed = TRUE;

    /*! Set the returned negative response code to u8NotOkErrorCode. */
    *kpu8NegCode = u8NotOkErrorCode;

  }
#endif

  /*! Return bCheckFailed */
  return(bCheckFailed);
}

#endif

#if(DCM_REQUEST_MANUF_SUPPL_INDIC_EN == STD_ON)


/******************************************************************************/
/*! \Description Performs the Manuf/Supplier Check for the requested SubFunction
                 of the requested service service.\n
    \param[in]  u8CurrentSid   Service ID. \n
    \Range       0..255  \n
    \param[in] kpkstrMsgContext   Pointer to the MsgContext struct.
    \Range     NOT NULL  \n
    \param[out] kpu8NegCode   Pointer to Negative response error code which
                              is returned if check failed. \n
    \Range        NOT NULL  \n
    \return      TRUE is return if check failed, otherwise FALSE is returned.
*******************************************************************************/
static FUNC(boolean,DCM_CODE) bManufSupplIndicCheck(
    uint8 u8CurrentSid,    
    CONSTP2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) kpkstrMsgContext,
    CONSTP2VAR(uint8, AUTOMATIC,AUTOMATIC) kpu8NegCode)
{

#if(DCM_u8NUM_OF_MANUF_SUPPL_INDIC != 1U)
  uint8                        u8LoopIndex;
  boolean                      bNotOkReturned = FALSE;
  Dcm_NegativeResponseCodeType u8NotOkErrorCode = 0;
#endif
  Std_ReturnType               u8Return;
  boolean                      bCheckFailed      = FALSE;

#if(DCM_u8NUM_OF_MANUF_SUPPL_INDIC != 1U)
  boolean                      bLoopEnd;
#endif

#if(DCM_u8NUM_OF_MANUF_SUPPL_INDIC != 1U)

  /*! Set the Loop End Flag to FALSE */
  bLoopEnd = FALSE;
  /*! Loop through all configured Xxx_ManufSupplIndication Functions */
  for(u8LoopIndex = 0;(u8LoopIndex < (uint8)DCM_u8NUM_OF_MANUF_SUPPL_INDIC) &&
  (bLoopEnd == FALSE);u8LoopIndex++)
  {
#endif
    /*! Call the current Xxx_ManufSupplIndication with the following
     * params:
     * 1) Service Identifier
     * 2) Pointer to the reqData
     * 3) reqDataLen
     * 4) The Address of the local variable used to get the ErrorCode*/
#if(DCM_u8NUM_OF_MANUF_SUPPL_INDIC != 1U)
    u8Return = (*Dcm_kstreDslConfig.apfu8ManufSupplIndic[u8LoopIndex])
                          (u8CurrentSid,
                              kpkstrMsgContext->reqData,
                              (uint16)kpkstrMsgContext->reqDataLen,
                              kpkstrMsgContext->msgAddInfo.reqType,
                              (uint8)kpkstrMsgContext->dcmRxPduId,
                              kpu8NegCode);
#endif
#if(DCM_u8NUM_OF_MANUF_SUPPL_INDIC == 1U)
/* !Deviation : Indentation deviation because it is dependent on the
                configuration.   */
/* PRQA S 2215 L1                                                         */
    u8Return = (*Dcm_kstreDslConfig.apfu8ManufSupplIndic[0])(u8CurrentSid,
        kpkstrMsgContext->reqData,(uint16)kpkstrMsgContext->reqDataLen,
        kpkstrMsgContext->msgAddInfo.reqType,
        (uint8)kpkstrMsgContext->dcmRxPduId,
        kpu8NegCode);
/* PRQA L:L1                                                                  */
#endif
/*! IF the function return value is E_REQUEST_NOT_ACCEPTED THEN */
    if(u8Return == E_REQUEST_NOT_ACCEPTED)
    {
#if(DCM_u8NUM_OF_MANUF_SUPPL_INDIC != 1U)
      /*! Set the For Loop End Flag to TRUE */
      bLoopEnd = TRUE;
#endif

      /*! Set the Check Failed Flag to TRUE */
      bCheckFailed = TRUE;

      /*! Set the returned negative response code to 0. */
      *kpu8NegCode = 0;


    }
    /*! ELSE IF the return value is E_NOT_OK THEN */
    else if (u8Return == E_NOT_OK)
    {
#if(DCM_u8NUM_OF_MANUF_SUPPL_INDIC != 1U)
      /*! Set bNotOkReturned to TRUE. */
      bNotOkReturned = TRUE;
      /*! Set u8NotOkErrorCode to Error Code returned by
                Xxx_ManufSupplIndication. */
      u8NotOkErrorCode = *kpu8NegCode;
#endif
#if(DCM_u8NUM_OF_MANUF_SUPPL_INDIC == 1U)
      /*! Set the Check Failed Flag to TRUE */
      bCheckFailed = TRUE;

#endif
    }
    /*! ELSE */
    else
    {
      /*! DO NOTHING */
    }
    /*! ENDIF */
#if(DCM_u8NUM_OF_MANUF_SUPPL_INDIC != 1U)
  }
  /*! END LOOP */
#endif
#if(DCM_u8NUM_OF_MANUF_SUPPL_INDIC != 1U)
  /*! IF the Check Failed Flag is  TRUE and bNotOkReturned is TRUE Then */
  if((bCheckFailed == FALSE) && (bNotOkReturned == TRUE))
  {

    /*! Set the Check Failed Flag to TRUE */
    bCheckFailed = TRUE;

    /*! Set the returned negative response code to u8NotOkErrorCode. */
    *kpu8NegCode = u8NotOkErrorCode;

  }
#endif

  /*! Return bCheckFailed*/
  return(bCheckFailed);
}

#endif


/******************************************************************************/
/*! \Description Check if the requested service is supported by the DCM. \n

    \param[in]  u8CurrentSid   Service ID. \n
    \Range       0..255  \n
    \param[in]  u8ProtocolSIDTable   Service Table Index. \n
    \Range       0..(DCM_u8NUM_OF_SESS_TABLE-1)  \n
    \param[in]  kpkstrMsgContext   Pointer to the MsgContext struct.
    \Range      NOT NULL  \n
    \param[out] kpu8ServiceIndex   Pointer to the service index in the
                                   configuration if the service is found.\n
    \Range      NOT NULL  \n
    \return     TRUE is return if check failed, otherwise FALSE is returned.
*******************************************************************************/
static FUNC(boolean,DCM_CODE) bCheckServSupported(
    uint8 u8CurrentSid,
    uint8 u8ProtocolSIDTable,
    CONSTP2CONST(Dcm_MsgContextType, AUTOMATIC,AUTOMATIC) kpkstrMsgContext,
    CONSTP2VAR(uint8, AUTOMATIC,AUTOMATIC) kpu8ServiceIndex)
{
  boolean bCheckFailed = FALSE;
  boolean bLoopEnd = FALSE;
  uint8   u8ServiceCount = 0;


  /*! Loop through all Services in the Service Table till the
   *  requested service is found */
  while(bLoopEnd == FALSE)
  {

    /*! IF the requested SID equals the SID of the current DcmDsdService
     *  structure THEN                  */
    if(u8SERV_ID(u8ProtocolSIDTable,u8ServiceCount) == u8CurrentSid)
    {
      /*! Set the Loop End Flag to TRUE */
      bLoopEnd = TRUE;

      /*! Set the Service Index returned with the current service Index*/
      *kpu8ServiceIndex = u8ServiceCount;

      /*! IF the service is allowed in both func. and phys. addressing
               Modes Then */
      if(u8SERV_ADDR_MODE(u8ProtocolSIDTable,u8ServiceCount) ==
          DCM_FUNC_AND_PHYS)
      {
        /*! Do Nothing */
      }
      /*! ELSE IF the service is allowed in phys. addressing
               Mode only Then */
      else if(u8SERV_ADDR_MODE(u8ProtocolSIDTable,u8ServiceCount) ==
          DCM_PHYS_ONLY)
      {
        /*! IF the requested message is received on
         *  functional address then*/
        if(kpkstrMsgContext->msgAddInfo.reqType == bFUNC_REQ)
        {
          /*! Set the Check Failed Flag to TRUE */
          bCheckFailed = TRUE;
        }
        /*! End IF*/
      }
      /*! ELSE */
      else
      {
        /*! IF the requested message is received on
         *  Physical address then*/
        if(kpkstrMsgContext->msgAddInfo.reqType == bPHYS_REQ)
        {
          /*! Set the Check Failed Flag to TRUE */
          bCheckFailed = TRUE;
        }
        /*! End IF*/

      }
      /*! End IF*/

    }
    /*! ELSE IF All Services in the Service Table have been checked */
    else if (u8ServiceCount == (u8NUM_SERVS(u8ProtocolSIDTable)-(uint8)1))
    {
      /*! Set the Loop End Flag to TRUE */
      bLoopEnd = TRUE;

      /*! Set the Check Failed Flag to TRUE */
      bCheckFailed = TRUE;
    }
    /*! ELSE */
    else
    {
      /*! Select the Next Service */
      u8ServiceCount++;
    }
    /*! END IF */
  }
  /*! END LOOP */

  /*! Return bCheckFailed*/
  return(bCheckFailed);

}


/******************************************************************************/
/*! \Description Check if the requested SubFunction is supported by the DCM. \n

    \param[in]  u8ServiceIndex   Service Index in configuration. \n
    \Range       0..255  \n
    \param[in]  u8ProtocolSIDTable   Service Table Index. \n
    \Range       0..(DCM_u8NUM_OF_SESS_TABLE-1)  \n
    \param[in]  kpkstrMsgContext   Pointer to the MsgContext struct.
    \Range      NOT NULL  \n
    \param[out] kpu8SubFunctionIndex   Pointer to the SubFunction index in the
                                    configuration if the Subfunction is found.\n
    \Range      NOT NULL  \n
    \return     TRUE is return if check failed, otherwise FALSE is returned.
*******************************************************************************/
static FUNC(boolean,DCM_CODE) bCheckSubFuncSupp(
    uint8 u8ServiceIndex,
    uint8 u8ProtocolSIDTable,
    CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC,AUTOMATIC) kpstrMsgContext,
    CONSTP2VAR(uint8, AUTOMATIC,AUTOMATIC) kpu8SubFuncIndex)
{
  boolean bCheckFailed = FALSE;
  boolean bLoopEnd;
  uint8   u8SubFuncCount = 0;


  /*! IF the "suppressPosRspMsgIndicationBit" is TRUE THEN  */
  if((kpstrMsgContext->reqData[0] & u8CHK_POS_RESP_BIT) !=0)
  {
    /*! Set the suppressPosRspMsgIndicationBit to FALSE */
    kpstrMsgContext->reqData[0] = (uint8)(kpstrMsgContext->reqData[0] &
                                          u8CLR_POS_RESP_BIT);

    /*! Set the suppressPosRespone member variable of msgAddInfo High */
    kpstrMsgContext->msgAddInfo.suppressPosResponse = bSUPPRESS_RESP;
  }
  /*! END IF */


  /*! Set the  Loop End Flag to FALSE */
  bLoopEnd = FALSE;

  /*! Loop through all supported Sub-Functions for the requested service*/
  while(bLoopEnd == FALSE)
  {
    /*! IF the requested Sub-Function equals the u8DcmDsdSubServiceId
     *  in the Sub-Function structure THEN                  */
    if(u8SUBFUNC_ID(u8ProtocolSIDTable,u8ServiceIndex,u8SubFuncCount)==
        kpstrMsgContext->reqData[0])
    {
      /*! Set the Sub-Func Index returned with the current Sub-Func Index*/
      *kpu8SubFuncIndex = u8SubFuncCount;
      /*! Set the For Loop End Flag to TRUE */
      bLoopEnd = TRUE;
    }
    /*! ELSE IF All Sub-Functions have been checked THEN*/
    else if(u8SubFuncCount == (u8NUM_SUBFUNC(u8ProtocolSIDTable,
        u8ServiceIndex)-(uint8)1))
    {
      /*! Set the Check Failed Flag to TRUE */
      bCheckFailed = TRUE;

      /*! Set the For Loop End Flag to TRUE */
      bLoopEnd = TRUE;


    }
    /*! ELSE */
    else
    {
      /*! Select the Next Sub-Function  */
      u8SubFuncCount++ ;
    }
    /*! ENDIF */
  }

  /*! Return bCheckFailed*/
  return(bCheckFailed);

}

/******************************************************************************/
/*! \Description Check if the requested service is allowed in the current
                 session. \n
    \param[in]  u8ProtocolSIDTable   Service Table Index. \n
    \Range       0..(DCM_u8NUM_OF_SESS_TABLE-1)  \n

    \param[in]  u8ServiceIndex   Service Index in the configuration.\n
    \Range      0..[Number of services per service table - 1]  \n
    \return     TRUE is return if check failed, otherwise FALSE is returned.
*******************************************************************************/
static FUNC(boolean,DCM_CODE) bCheckServSession(
    uint8 u8ProtocolSIDTable,
    uint8 u8ServiceIndex)
{
  boolean         bLoopEnd =     FALSE;
  boolean         bCheckFailed = FALSE;
  Dcm_SesCtrlType u8CurrentSession;
  uint8           u8SessionCount = 0;

  /*! Get the current session level by calling Dcm_GetSesCtrlType  */
  (void)Dcm_GetSesCtrlType(&u8CurrentSession);

  if(ppkstrSERV_SESS_REF(u8ProtocolSIDTable,u8ServiceIndex)
      != (P2CONST(Dcm_tpkstrDspSessionRowType,TYPEDEF,DCM_CFG_CONST))NULL_PTR)
  {
    /*! Loop through all Session References of the requested service */
    while(bLoopEnd == FALSE)
    {
      /*! IF DCM Current Session equals the Session level in the
       *  reference Session Structure THEN */
      if((u8SERV_SESS_LEV(u8ProtocolSIDTable,u8ServiceIndex,u8SessionCount)
          == u8CurrentSession) ||
          (u8SERV_SESS_LEV(u8ProtocolSIDTable,u8ServiceIndex,u8SessionCount)
              == DCM_ALL_SESSION_LEVEL))
      {
        /*! Set the Loop End Flag to TRUE */
        bLoopEnd = TRUE;
      }
      /*! ELSE IF All Session References have been checked */
      else if(u8SessionCount == (u8NUM_SERV_SESS(u8ProtocolSIDTable,
          u8ServiceIndex)-(uint8)1))
      {
        /*! Set the Check Failed Flag to TRUE */
        bCheckFailed = TRUE;

        /*! Set the Loop End Flag to TRUE */
        bLoopEnd = TRUE;

      }
      /*! ELSE */
      else
      {
        /*! Select the Next Session reference  */
        u8SessionCount++;
      }
      /*! ENDIF */
    }
    /*! END LOOP */

  }

  /*! Return bCheckFailed*/
  return(bCheckFailed);

}


/******************************************************************************/
/*! \Description Check if the requested service is allowed in the current
                 security level. \n
    \param[in]  u8ProtocolSIDTable   Service Table Index. \n
    \Range       0..(DCM_u8NUM_OF_SESS_TABLE-1)  \n
    \param[in]  u8ServiceIndex   Service Index in the configuration.\n
    \Range      0..[Number of services per service table - 1]  \n
    \return     TRUE is return if check failed, otherwise FALSE is returned.
*******************************************************************************/
static FUNC(boolean,DCM_CODE) bCheckServSecurity(
    uint8 u8ProtocolSIDTable,
    uint8 u8ServiceIndex)

{
  boolean         bLoopEnd;
  boolean         bCheckFailed = FALSE;
  Dcm_SesCtrlType u8CurrentSecurity;
  uint8           u8SecurityCount = 0;

  /*! Get the current Security level by calling Dcm_GetSecurityLevel  */
  (void)Dcm_GetSecurityLevel(&u8CurrentSecurity);

  /*! Set the Loop End flag to FALSE */
  bLoopEnd = FALSE;

  if(ppkstrSERV_SEC_REF(u8ProtocolSIDTable,u8ServiceIndex)!=
      (P2CONST(Dcm_tpkstrDspSecurityRowType,TYPEDEF,DCM_CFG_CONST))NULL_PTR)
  {
    /*! Loop through all  Security References of the requested service */
    while(bLoopEnd == FALSE)
    {
      /*! IF DCM Current Security level equals the Security level in the
       *  reference Security Structure THEN */
      if((u8SERV_SEC_LEVEL(u8ProtocolSIDTable,u8ServiceIndex,u8SecurityCount)
          == u8CurrentSecurity) ||
          (u8SERV_SEC_LEVEL(u8ProtocolSIDTable,u8ServiceIndex,u8SecurityCount)
              == DCM_SEC_LEV_ALL))

      {
        /*! Set the Loop End Flag to TRUE */
        bLoopEnd = TRUE;
      }
      /*! ELSE IF All Security References have been checked */
      else if(u8SecurityCount == (u8NUM_SERV_SEC(u8ProtocolSIDTable,
          u8ServiceIndex)-(uint8)1))
      {
        /*! Set the Check Failed Flag to TRUE */
        bCheckFailed = TRUE;

        /*! Set the Loop End Flag to TRUE */
        bLoopEnd = TRUE;

      }
      /*! ELSE */
      else
      {
        /*! Select the Next Security reference  */
        u8SecurityCount++;
      }
      /*! ENDIF */
    }
    /*! END LOOP */
  }

  /*! Return bCheckFailed*/
  return(bCheckFailed);

}

/******************************************************************************/
/*! \Description Check if the requested Subfunction is allowed in the current
                 security level. \n
    \param[in]  u8ProtocolSIDTable   Service Table Index. \n
    \Range       0..(DCM_u8NUM_OF_SESS_TABLE-1)  \n

    \param[in]  u8ServiceIndex   Service Index in the configuration.\n
    \Range      0..[Number of services per service table - 1]  \n

    \param[in]  u8SubFuncIndex   SubFunction Index in the configuration.\n
    \Range      0..[Number of SubFuncation per service - 1]  \n

    \return     TRUE is return if check failed, otherwise FALSE is returned.
*******************************************************************************/
static FUNC(boolean,DCM_CODE) bCheckSubFuncSecurity(
    uint8 u8ProtocolSIDTable,
    uint8 u8ServiceIndex,
    uint8 u8SubFuncIndex)

{
  boolean         bLoopEnd;
  boolean         bCheckFailed = FALSE;
  Dcm_SesCtrlType u8CurrentSecurity;
  uint8           u8SecurityCount = 0;

  /*! Get the current Security level by calling Dcm_GetSecurityLevel  */
  (void)Dcm_GetSecurityLevel(&u8CurrentSecurity);


  if((ppkstrSUBFUNC_SEC_REF(u8ProtocolSIDTable,u8ServiceIndex,u8SubFuncIndex)
      !=(P2CONST(Dcm_tpkstrDspSecurityRowType,TYPEDEF,DCM_CFG_CONST))NULL_PTR))
  {
    /*! Set the  Loop End Flag to FALSE */
    bLoopEnd = FALSE;

    /*! Loop through all Sub-Function Security References*/
    while(bLoopEnd == FALSE)
    {
      /*! IF DCM Current Security level equals the Security level in the
       *  Sub-Function reference Security THEN */
      if((u8SUBFUNC_SEC_LEV(u8ProtocolSIDTable,u8ServiceIndex,
          u8SubFuncIndex,u8SecurityCount) == u8CurrentSecurity)
        || (u8SUBFUNC_SEC_LEV(u8ProtocolSIDTable,u8ServiceIndex,
            u8SubFuncIndex,u8SecurityCount) == DCM_SEC_LEV_ALL))
      {
        /*! Set the For Loop End Flag to TRUE */
        bLoopEnd = TRUE;
      }
      /*! ELSE IF All Sub-Functions Security references have been checked */
      else if(u8SecurityCount ==
          (u8NUM_SUBFUNC_SEC(u8ProtocolSIDTable,u8ServiceIndex,
              u8SubFuncIndex)-(uint8)1))
      {
        /*! Set the Check Failed Flag to TRUE */
        bCheckFailed = TRUE;

        /*! Set the For Loop End Flag to TRUE */
        bLoopEnd = TRUE;

      }
      /*! ELSE */
      else
      {
        /*! Select the Next Sub-Function Security reference  */
        u8SecurityCount++;
      }
      /*! ENDIF */
    }
    /*! END LOOP */
  }
  /*! ENDIF */

  /*! Return bCheckFailed*/
  return(bCheckFailed);

}


/******************************************************************************/
/*! \Description Check if the requested Subfunction is allowed in the current
                 session level. \n
    \param[in]  u8ProtocolSIDTable   Service Table Index. \n
    \Range       0..(DCM_u8NUM_OF_SESS_TABLE-1)  \n

    \param[in]  u8ServiceIndex   Service Index in the configuration.\n
    \Range      0..[Number of services per service table - 1]  \n

    \param[in]  u8SubFuncIndex   SubFunction Index in the configuration.\n
    \Range      0..[Number of SubFuncation per service - 1]  \n

    \return     TRUE is return if check failed, otherwise FALSE is returned.
*******************************************************************************/

static FUNC(boolean,DCM_CODE) bCheckSubFuncSession(
    uint8 u8ProtocolSIDTable,
    uint8 u8ServiceIndex,
    uint8 u8SubFuncIndex)
{

  boolean         bLoopEnd;
  boolean         bCheckFailed = FALSE;
  Dcm_SesCtrlType u8CurrentSession;
  uint8           u8SessionCount = 0;

  /*! Get the current session level by calling Dcm_GetSesCtrlType  */
  (void)Dcm_GetSesCtrlType(&u8CurrentSession);

  /*! IF Session reference of the Sub-Function not equal to NULL THEN */

  if((ppkstrSUBFUNC_SES_REF(u8ProtocolSIDTable,u8ServiceIndex,u8SubFuncIndex) !=
     (P2CONST(Dcm_tpkstrDspSessionRowType,TYPEDEF,DCM_CFG_CONST))NULL_PTR))
  {
    /*! Set the  Loop End Flag to FALSE */
    bLoopEnd = FALSE;

    /*! Loop through all Sub-Function Session References*/
    while(bLoopEnd == FALSE)
    {
      /*! IF DCM Current Session level equals the Session level in the
       *  Sub-Function  Session reference THEN */
      if((u8SUBFUNC_SES_LEV(u8ProtocolSIDTable,u8ServiceIndex,
                            u8SubFuncIndex,u8SessionCount)
                            == u8CurrentSession) ||
          (u8SUBFUNC_SES_LEV(u8ProtocolSIDTable,u8ServiceIndex,
                             u8SubFuncIndex,u8SessionCount)
                            == DCM_ALL_SESSION_LEVEL))
      {
        /*! Set the  Loop End Flag to TRUE */
        bLoopEnd = TRUE;
      }
      /*! ELSE IF All Sub-Functions Session references have been checked */
      else if(u8SessionCount ==
          (u8NUM_SUBFUNC_SESS(u8ProtocolSIDTable,u8ServiceIndex,
                              u8SubFuncIndex)-(uint8)1))
      {
        /*! Set the Check Failed Flag to TRUE */
        bCheckFailed = TRUE;

        /*! Set the  Loop End Flag to TRUE */
        bLoopEnd = TRUE;

      }
      /*! ELSE */
      else
      {
        /*! Select the Next Sub-Function session reference  */
        u8SessionCount++;
      }
      /*! ENDIF */
    }
    /*! END LOOP */
  }
  /*! ENDIF */


  return(bCheckFailed);

}


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/




#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description  DSD main function. Handles the Paged buffer timer. \n

  \return      void.
  \Trace_To : CDD-DSD-0003(0),CDD-DSD-0011(1)
*******************************************************************************/
FUNC(void,DCM_CODE) DsdInternal_Main(void)
{

#if(DCM_bROE_ENABLED == STD_ON)
  uint8 u8Context = 0;
#endif

  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */
  /* PRQA S 3138 ++                                                           */

  SchM_Enter_Dcm_Access_020();
  SchM_Enter_Dcm_Access_021();
  /* PRQA S 3141 --                                                           */
  /* PRQA S 3138 --                                                           */

#if(DCM_bROE_ENABLED == STD_ON)
  for(u8Context;u8Context < 2;u8Context++)
  {
    /*!  IF page buffer Timer is On i.e. Dsd_abPbTimerOn = TRUE THEN */
    if(Dsd_abPbTimerOn[u8Context] == TRUE )
    {
      /*!  IF page buffer counter Dsd_au16PbCount equal Zero  THEN */
      if(Dsd_au16PbCount[u8Context] == 0)
      {
        /*! Set Dsd_abPbTimerOn to FALSE */
        Dsd_abPbTimerOn[u8Context] = FALSE;

        /*! Call DslInternal_PageBufferFailed */
        DslInternal_PageBufferFailed(u8Context);
      }
      /*! ELSE */
      else
      {
        /*! Decrement Paged Buffer Counter (Dsd_au16PbCount) */
        Dsd_au16PbCount[u8Context]--;
      }
      /*! END IF */
    }
    /*! END IF */
  }
#else
  /*!  IF page buffer Timer is On i.e. Dsd_abPbTimerOn = TRUE THEN */
  if(Dsd_abPbTimerOn[0] == TRUE )
  {
    /*!  IF page buffer counter Dsd_au16PbCount equal Zero  THEN */
    if(Dsd_au16PbCount[0] == 0)
    {
      /*! Set Dsd_abPbTimerOn to FALSE */
      Dsd_abPbTimerOn[0] = FALSE;

      /*! Call DslInternal_PageBufferFailed */
      DslInternal_PageBufferFailed(0);
    }
    /*! ELSE */
    else
    {
      /*! Decrement Paged Buffer Counter (Dsd_au16PbCount) */
      Dsd_au16PbCount[0]--;
    }
    /*! END IF */
  }
  /*! END IF */
#endif

  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */
  /* PRQA S 3138 ++                                                           */

  SchM_Exit_Dcm_Access_020();
  SchM_Exit_Dcm_Access_021();
  /* PRQA S 3141 --                                                           */
  /* PRQA S 3138 --                                                           */


}
#endif



#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description  DSD Initialization function.  \n
    \return      void.
    \Trace_To : CDD-DSD-0006(0),CDD-DSD-0012(0)
*******************************************************************************/
FUNC(void,DCM_CODE) DsdInternal_Init(void)
{

    /*! Set the Dsd_au16PbCount with DCM_PAGED_BUFFER_TIMEOUT */
  Dsd_au16PbCount[0] = DCM_PAGED_BUFFER_TIMEOUT;

  /*! Set the Dsd_abPbTimerOn to FALSE */
  Dsd_abPbTimerOn[0] = FALSE;
#if(DCM_bROE_ENABLED == STD_ON)
    /*! Set the Dsd_au16PbCount with DCM_PAGED_BUFFER_TIMEOUT */
  Dsd_au16PbCount[1] = DCM_PAGED_BUFFER_TIMEOUT;

  /*! Set the Dsd_abPbTimerOn to FALSE */
  Dsd_abPbTimerOn[1] = FALSE;
#endif


}
#endif



#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description With this API, the DSP submodule gives the complete response\n
                 length to the DSD and starts paged-buffer handling. This API\n
                 starts no transmission.
    \param[in] pMsgContext   Pointer to the MsgContext struct.
               \Range   NOT NULL  \n
    \return        void.
    \Trace_To : CDD-DSD-0007(0),CDD-DSD-0015(0),CDD-DSD-0014(0),CDD-DSD-0013(0),
                CDD-DSD-0016(0)
*******************************************************************************/
FUNC(void,DCM_CODE) DsdInternal_StartPagedProcessing(
    P2VAR(Dcm_MsgContextType,AUTOMATIC, DCM_VAR) pMsgContext)
{

  /*! Set Dsd_apstrPbMsgContext to pMsgContext. */
  Dsd_apstrPbMsgContext[pMsgContext->idContext] = pMsgContext;

  /*! Set Dsd_abFirstPage to TRUE. */
  Dsd_abFirstPage[pMsgContext->idContext] = TRUE;

  /*! Increment resDataLen*/
  pMsgContext->resDataLen++;

  /*! Set the First byte in Tx Buffer with the Postive Response Service ID. */
  Dsd_strMsgInfo[pMsgContext->idContext].pu8TxBuffer[0] =
    Dsd_strMsgInfo[pMsgContext->idContext].pu8RxBuffer[0] |
    u8POS_SID_MASK;

  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */
  /* PRQA S 3138 ++                                                           */
  SchM_Enter_Dcm_Access_020();
  /* PRQA S 3141 --                                                           */
  /* PRQA S 3138 --                                                           */
  /*! Set the Dsd_au16PbCount with DCM_PAGED_BUFFER_TIMEOUT */
  Dsd_au16PbCount[pMsgContext->idContext] = DCM_PAGED_BUFFER_TIMEOUT;

  /*! Set the Dsd_abPbTimerOn to TRUE */
  Dsd_abPbTimerOn[pMsgContext->idContext] = TRUE;

  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */
  /* PRQA S 3138 ++                                                           */
  SchM_Exit_Dcm_Access_020();
  /* PRQA S 3141 --                                                           */
  /* PRQA S 3138 --                                                           */

  /*! Call DspInternal_UpdatePage */
  DspInternal_UpdatePage(pMsgContext->idContext);



}


/******************************************************************************/
/*! \Description Using this API, The DSL requests from the DSD to update the
                 page.Accordingly the DSD requests from the DSP to update the
                 page. And the DSD starts the Paged Buffer Timeout timer.
    \param[in] idContext   Context Identifier.
    \Range     0..(DspInternal_u8MAX_NUM_INTERNAL_REQ-1)        \n
    \return        void.
    \Trace_To : CDD-DSD-0008(0),CDD-DSD-0017(0),CDD-DSD-0018(0)
*******************************************************************************/
FUNC(void,DCM_CODE) DsdInternal_UpdatePage(Dcm_IdContextType idContext)

{


  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */
  /* PRQA S 3138 ++                                                           */
  SchM_Enter_Dcm_Access_021();
  /* PRQA S 3141 --                                                           */
  /* PRQA S 3138 --                                                           */
  /*! Set the Dsd_au16PbCount with DCM_PAGED_BUFFER_TIMEOUT */
  Dsd_au16PbCount[idContext] = DCM_PAGED_BUFFER_TIMEOUT;

  /*! Start the Paged Buffer Timer i.e. Dsd_abPbTimerOn = TRUE */
  Dsd_abPbTimerOn[idContext] = TRUE;

  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */
  /* PRQA S 3138 ++                                                           */
  SchM_Exit_Dcm_Access_021();
  /* PRQA S 3141 --                                                           */
  /* PRQA S 3138 --                                                           */


  /*! IF Dsd_abFirstPage is TRUE THEN */
  if(Dsd_abFirstPage[idContext] == TRUE)
  {
    /*! Set Dsd_abFirstPage to FALSE  */
    Dsd_abFirstPage[idContext] = FALSE;

    /*! Set resData to point to the first byte in the TxBuffer. */
    Dsd_apstrPbMsgContext[idContext]->resData = Dsd_strMsgInfo[idContext].pu8TxBuffer;
    /*! Increment resMaxDataLen */
    Dsd_apstrPbMsgContext[idContext]->resMaxDataLen++;
  }
  /*! END*/

  /*! Call the DspInternal_UpdatePage */
  DspInternal_UpdatePage(idContext);

}


/******************************************************************************/
/*! \Description Used by the DSP to inform the DSL that a new page has been\n
                processed.The DSD stops the paged buffer timer and informs \n
                the DSL that a new page is ready to be sent. \n

  \param[in] idContext   Context Identifier.
              \Range     0..(DspInternal_u8MAX_NUM_INTERNAL_REQ-1)        \n

  \param[in]  FilledPageLen   Size of filled page.
              \Range          0..4294967296        \n

  \return      void.
  \Trace_To : CDD-DSD-0009(0),CDD-DSD-0019(0),CDD-DSD-0020(0)
*******************************************************************************/
FUNC(void,DCM_CODE) DsdInternal_ProcessPage(
    Dcm_IdContextType idContext,Dcm_MsgLenType FilledPageLen)
{

  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */
  /* PRQA S 3138 ++                                                           */
  SchM_Enter_Dcm_Access_020();
  /*! Stop the Paged Buffer Timer i.e. Dsd_abPbTimerOn = FALSE */
  Dsd_abPbTimerOn[idContext] = FALSE;
  SchM_Exit_Dcm_Access_020();
  /* PRQA S 3141 --                                                           */
  /* PRQA S 3138 --                                                           */

  /*! IF Dsd_abFirstPage is TRUE THEN */
  if(Dsd_abFirstPage[idContext] == TRUE)
  {
    /*! Increment page length */
    FilledPageLen++;
  }
  /*! Call DslInternal_ProcessPage with parameters idContext, FilledPageLen */
  DslInternal_ProcessPage(idContext,FilledPageLen);

}



#endif





/******************************************************************************/
/*! \Description Used by the DSP to Indicate to the DSD that the final
                 response is negative. \n

  \param[in] pMsgContext   Pointer to the MsgContext struct.
  \Range   NOT NULL  \n

  \param[in] u8NegRespCode   Negative response error code. \n
  \Range   0x00..0XFF  \n
  \return      void.

  \Trace_To: CDD-DSD-0005(0),CDD-0932(0),CDD-0933(0),CDD-0935(0),CDD-0936(0),
             CDD-0937(0),CDD-0938(0)
*******************************************************************************/
FUNC(void,DCM_CODE) DsdInternal_SetNegResponse(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext ,
    uint8 u8NegRespCode)
{
  /*! set u8ResponseType in Dsd_strMsgInfo[idContext] with u8NEG_RESP */
  Dsd_strMsgInfo[pMsgContext->idContext].u8ResponseType = u8NEG_RESP;


  /*! set first byte in Tx Buffer with DspInternal_u8SID_NEG_RESP  */
  Dsd_strMsgInfo[pMsgContext->idContext].pu8TxBuffer[0] =
      DspInternal_u8SID_NEG_RESP;

  /*! set Second byte in Tx Buffer with request service Id  */
  Dsd_strMsgInfo[pMsgContext->idContext].pu8TxBuffer[1] =
      Dsd_strMsgInfo[pMsgContext->idContext].pu8RxBuffer[0];


  /*! set Third byte in Tx Buffer with u8NegRespCode  */
  Dsd_strMsgInfo[pMsgContext->idContext].pu8TxBuffer[2] = u8NegRespCode;

  /*! set resDataLen in pMsgContext with DspInternal_u8NEG_RESPONSE_LENGTH  */
  pMsgContext->resDataLen = (Dcm_MsgLenType)DspInternal_u8NEG_RESPONSE_LENGTH;

}



/******************************************************************************/
/*! \Description The DSL uses this API to confirm the transmission of the \n
                 Response\n
  \param[in] idContext   Context Identifier
              \Range     0..(DspInternal_u8MAX_NUM_INTERNAL_REQ-1)        \n

  \param[in] dcmRxPduId  Rx Pdu ID \n
             \Range      dependent on PduIdType      \n

  \param[in] result   Result of Message transmission \n
             \Range   0x00..0x1E, 0x1F..0x3C   \n

  \return        void
  \Trace_To: CDD-DSD-0002(0),CDD-DSD-0026(0),CDD-0941(0),CDD-0943(0),
             CDD-0823(0)
*******************************************************************************/
FUNC(void,DCM_CODE) DsdInternal_Confirmation(
    Dcm_IdContextType idContext,
    PduIdType dcmRxPduId,
    NotifResultType result)
{

  /*! Define Local Confirmation status variable */
  Dcm_ConfirmationStatusType u8Status;


  /*! IF bInternalResp is FALSE */
  if(Dsd_strMsgInfo[idContext].bInternalResp == FALSE)
  {
    /*! IF result equal NTFRSLT_OK THEN */
    if(result == NTFRSLT_OK)
    {
      /*! IF u8ResponseType member of Dsd_strMsgInfo[idContext] is
          u8POS_RESP THEN */
      if(Dsd_strMsgInfo[idContext].u8ResponseType == u8POS_RESP)
      {
        /*! Set the local status variable to DCM_RES_POS_OK */
        u8Status = DCM_RES_POS_OK;
      }
      /*! ELSE */
      else
      {
        /*! Set the local status variable to DCM_RES_NEG_OK */
        u8Status = DCM_RES_NEG_OK;
      }
      /*! END IF  */

    }
    /*! ELSE */
    else
    {
      /*! IF u8ResponseType member of Dsd_strMsgInfo[idContext] is
       *  u8NEG_RESP THEN */
      if(Dsd_strMsgInfo[idContext].u8ResponseType == u8NEG_RESP)
      {
        /*! Set the local status variable to DCM_RES_NEG_NOT_OK */
        u8Status = DCM_RES_NEG_NOT_OK;
      }
      /*! ELSE */
      else
      {
        /*! Set the local status variable to DCM_RES_POS_NOT_OK */
        u8Status = DCM_RES_POS_NOT_OK;
      }
    }


#if(DCM_bDIAG_SERV_IS_CALLOUT == STD_ON)
    /*! IF bIsCallout member of Dsd_strMsgInfo[idContext] is TRUE THEN*/
    if(Dsd_strMsgInfo[idContext].bIsCallout == TRUE)
    {
      /*! Call the Dcm_Confirmation with parameters:
       *  1) idContext
       *  2) dcmRxPduId
       *  3) Local confirmation status Variable  */
      Dcm_Confirmation(idContext,dcmRxPduId,u8Status);
    }
    /*! ELSE */
    else
    {
#endif
      /*! Call the DspInternal_DcmConfirmation with parameters:
       *  1) idContext
       *  2) dcmRxPduId
       *  3) Local confirmation status Variable  */

      DspInternal_DcmConfirmation(idContext,dcmRxPduId,u8Status);
#if(DCM_bDIAG_SERV_IS_CALLOUT == STD_ON)
    }
#endif

  }
  /*! END IF*/
}


/******************************************************************************/
/*! \Description Using this API, The DSP informs the DSD that the DSP has
                 finished processing the request and the DSD can send the
                 positive/negative response.\n

  \param[in] pMsgContext   Pointer to the MsgContext struct.
               \Range   NOT NULL  \n

  \return      void
  \Trace_To: CDD-DSD-0004(0),CDD-DSD-0025(0),CDD-0915(0),CDD-0919(0),
             CDD-0932(0),CDD-0933(0),CDD-0934(0),CDD-0938(0),CDD-0943(0),
             CDD-0820(0)
*******************************************************************************/
FUNC(void,DCM_CODE) DsdInternal_ProcessingDone(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext)
{

  /*! Set resData to point to the first byte in Tx Buffer */
  pMsgContext->resData = Dsd_strMsgInfo[pMsgContext->idContext].pu8TxBuffer;

  /*! IF response is negative  THEN */
  if(Dsd_strMsgInfo[pMsgContext->idContext].
      u8ResponseType == u8NEG_RESP)
  {

    /*! IF the [request is functional and the error code in third byte of the
     *  TX Buffer equal to DCM_E_SERVICENOTSUPPORTED or
     *  DCM_E_SUBFUNCTIONNOTSUPPORTED or DCM_E_REQUESTOUTOFRANGE] OR the
     *  third byte of resData equal to DCM_u8E_SUPPRESS_RESPONSE THEN  */
    if (((pMsgContext->msgAddInfo.reqType == bFUNC_REQ)
        && ((Dsd_strMsgInfo[pMsgContext->idContext].pu8TxBuffer[2] ==
            DCM_E_SERVICENOTSUPPORTED) ||
            (Dsd_strMsgInfo[pMsgContext->idContext].pu8TxBuffer[2] ==
                DCM_E_SUBFUNCTIONNOTSUPPORTED) ||
              (Dsd_strMsgInfo[pMsgContext->idContext].pu8TxBuffer[2] ==
                    DCM_E_REQUESTOUTOFRANGE)))
           || (Dsd_strMsgInfo[pMsgContext->idContext].pu8TxBuffer[2] ==
                        DCM_u8E_SUPPRESS_RESPONSE))
    {
      /*! Set resDataLen to DspInternal_udtSUPPRESS_RESP_LENGTH */
      pMsgContext->resDataLen = DspInternal_udtSUPPRESS_RESP_LENGTH;


#if(DCM_bDIAG_SERV_IS_CALLOUT == STD_ON)
      /*! IF bIsCallout member of Dsd_strMsgInfo[idContext]
          is TRUE THEN */
      if(Dsd_strMsgInfo[pMsgContext->idContext].bIsCallout == TRUE)
      {
        /*! Call the Dcm_Confirmation with parameters:
         *  1) pMsgContext->idContext
         *  2) pMsgContext->dcmRxPduId
         *  3) DCM_RES_NEG_OK                      */
        Dcm_Confirmation(pMsgContext->idContext,
            pMsgContext->dcmRxPduId,
            DCM_RES_NEG_OK);
      }
      /*! ELSE */
      else
      {
#endif
        /*! Call the DspInternal_DcmConfirmation with parameters:
         *  1) pMsgContext->idContext
         *  2) pMsgContext->dcmRxPduId
         *  3) DCM_RES_NEG_OK                      */
        DspInternal_DcmConfirmation(pMsgContext->idContext,
            pMsgContext->dcmRxPduId,
            DCM_RES_NEG_OK);
#if(DCM_bDIAG_SERV_IS_CALLOUT == STD_ON)
      }
#endif
      /*! END IF */

      /*! Call the DslInternal_ProcessingDone with idContext */
      DslInternal_ProcessingDone(pMsgContext->idContext);
    }
    /*! ELSE */
    else
    {
      /*! Call the DslInternal_ProcessingDone with idContext */
      DslInternal_ProcessingDone(pMsgContext->idContext);

    }
    /*! END IF */

  }
  /*! ELSE IF msgAddInfo.suppressPosResponse equal Zero THEN */
  else if (pMsgContext->msgAddInfo.suppressPosResponse == bDONOT_SUPPRESS_RESP)
  {

    /*! Increment resDataLen */
    pMsgContext->resDataLen++;

    /*! Set the First Byte in TX Buffer with the positive response Service Id*/
    Dsd_strMsgInfo[pMsgContext->idContext].pu8TxBuffer[0] =
       (uint8)(Dsd_strMsgInfo[pMsgContext->idContext].pu8RxBuffer[0]|
               u8POS_SID_MASK);

    /*! Call the DslInternal_ProcessingDone with idContext */
    DslInternal_ProcessingDone(pMsgContext->idContext);


  }
  /*! ELSE */
  else
  {
    /*! Set resDataLen to DspInternal_udtSUPPRESS_RESP_LENGTH */
    pMsgContext->resDataLen = DspInternal_udtSUPPRESS_RESP_LENGTH;


#if(DCM_bDIAG_SERV_IS_CALLOUT == STD_ON)
    /*! IF bIsCallout member of Dsd_strMsgInfo[idContext] is TRUE THEN*/
    if(Dsd_strMsgInfo[pMsgContext->idContext].bIsCallout == TRUE)
    {
      /*! Call the Dcm_Confirmation with parameters:
       *  1) pMsgContext->idContext
       *  2) pMsgContext->dcmRxPduId
       *  3) DCM_RES_POS_OK   */
      Dcm_Confirmation(pMsgContext->idContext,
          pMsgContext->dcmRxPduId,
          DCM_RES_POS_OK);
    }
    /*! ELSE */
    else
    {
#endif
      /*! Call the DspInternal_DcmConfirmation with parameters:
       *  1) pMsgContext->idContext
       *  2) pMsgContext->dcmRxPduId
       *  3) DCM_RES_POS_OK   */
      DspInternal_DcmConfirmation(pMsgContext->idContext,
          pMsgContext->dcmRxPduId,
          DCM_RES_POS_OK);
#if(DCM_bDIAG_SERV_IS_CALLOUT == STD_ON)
    }
#endif
    /*! END IF */

    /*! Call the DslInternal_ProcessingDone with idContext */
    DslInternal_ProcessingDone(pMsgContext->idContext);
  }
  /*! END IF */

}




/******************************************************************************/
/*! \Description Using this API, The DSL informs the DSD that a new
                 diagnostic request has been received.The DSD performs
                 different checks on the message then decides whether to
                 forward the message to the DSP or send negative response. \n

    \param[in] pMsgContext   Pointer to the MsgContext struct.
    \Range     NOT NULL  \n
    \param[in] u8ProtocolSIDTable   Service Table Index.
    \Range     0..(DCM_u8NUM_OF_SESS_TABLE-1)   \n
    \return    void.\n
    \Trace_To: CDD-DSD-0001(0),CDD-DSD-0023(0),CDD-DSD-0024(0),CDD-0908(0),
               CDD-0909(0),CDD-0910(0),CDD-0912(0),CDD-0913(0),
               CDD-0914(0),CDD-0916(0),CDD-0917(0),CDD-0919(0),CDD-0920(0),
               CDD-0921(0),CDD-0922(0),CDD-0923(0),CDD-0924(0),CDD-0925(0),
               CDD-0926(0),CDD-0927(0),CDD-0928(0),CDD-0929(0),CDD-0930(0),
               CDD-0935(0),CDD-1557(0),CDD-0944(0),CDD-1915(0),CDD-1914(0)
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This Service performs a lot of checks,   */
/*              so metrics for this service is not met.                      */
/* PRQA S 4700 ++                                                           */
FUNC(void,DCM_CODE) DsdInternal_DataIndication(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    uint8  u8ProtocolSIDTable)
{

  uint8                        u8CurrentSid;
  uint8                        u8ServiceIndex = 0;
  uint8                        u8SubFuncIndex = 0;
  boolean                      bCheckFailed;
  uint8                        u8NegRespCode = 0;

#if((DCM_REQUEST_MANUFACTURER_INDICATION_ENABLED == STD_ON)||\
    (DCM_REQUEST_SUPPLIER_INDICATION_ENABLED == STD_ON)||\
    (DCM_REQUEST_MANUF_SUPPL_INDIC_EN == STD_ON))
  Dcm_NegativeResponseCodeType u8ApplNegCode;
#endif


  /*! Set the u8ResponseType member of Dsd_strMsgInfo[idContext] to
      u8POS_RESP*/
  Dsd_strMsgInfo[pMsgContext->idContext].u8ResponseType = u8POS_RESP;

  /*! Set the bInternalResp of Dsd_strMsgInfo with FALSE */
  Dsd_strMsgInfo[pMsgContext->idContext].bInternalResp  = FALSE;

  /*! Set the suppressPosResponse bit in pMsgContext to bDONOT_SUPPRESS_RESP */
  pMsgContext->msgAddInfo.suppressPosResponse = bDONOT_SUPPRESS_RESP;

  /*! Set the Current SID Local variable with the first byte of reqData */
  u8CurrentSid = pMsgContext->reqData[0];

  /*! Set pu8RxBuffer of Dsd_strMsgInfo to pMsgContext->reqData */
  Dsd_strMsgInfo[pMsgContext->idContext].pu8RxBuffer =
      pMsgContext->reqData;

  /*! Set pu8TxBuffer of Dsd_strMsgInfo to pMsgContext->resData */
  Dsd_strMsgInfo[pMsgContext->idContext].pu8TxBuffer =
      pMsgContext->resData;

  /*! Set the reqData pointer to point to the second byte
   *  in the reqData buffer */
  pMsgContext->reqData = &pMsgContext->reqData[1];

  /*! Set the resData pointer to point to the second byte
   *  in the resData buffer */
  pMsgContext->resData = &pMsgContext->resData[1];

  /*! Decrement the reqDataLen */
  pMsgContext->reqDataLen-- ;

  /*! Decrement the resMaxDataLen */
  pMsgContext->resMaxDataLen-- ;

  /*! Set resDataLen to DspInternal_udtSUPPRESS_RESP_LENGTH */
  pMsgContext->resDataLen = DspInternal_udtSUPPRESS_RESP_LENGTH;


#if(DCM_RESPOND_ALL_REQUEST == STD_OFF)
  /*! IF DCM_RESPOND_ALL_REQUEST is configured to STD_OFF AND the requested
   *  Service ID is  in the range from 0xC0 to 0xFF or in the range from
   *  0x40 to 0x7F THEN*/
  if (( (u8CurrentSid >= u8INV_SID_LOW_RANGE_1) &&
      (u8CurrentSid <= u8INV_SID_HIGH_RANGE_1)) ||
      (u8CurrentSid >= u8INV_SID_LOW_RANGE_2))

  {
    /*!Set bInternalResp to TRUE */
    Dsd_strMsgInfo[pMsgContext->idContext].bInternalResp = TRUE;

    /*! Call the DslInternal_ProcessingDone with idContext */
    DslInternal_ProcessingDone(pMsgContext->idContext);
  }
  /*! ELSE */
  else
  {
#endif
    /*! ****************************************************************** */
    /*! Verification of the Manufacturer Application environment/permission*/
    /*! ****************************************************************** */

    /*! IF the config. param DCM_REQUEST_MANUFACTURER_INDICTION_ENABLED = TRUE*/
#if(DCM_REQUEST_MANUFACTURER_INDICATION_ENABLED == STD_ON)

    /*! Call bManufIndicCheck */
    bCheckFailed = bManufIndicCheck(u8CurrentSid,pMsgContext,&u8ApplNegCode);

    /*! If bManufIndicCheck returned TRUE THEN */
    if(bCheckFailed == TRUE)
    {
      /*! Set u8NegRespCode with the error code returned by bManufIndicCheck*/
      u8NegRespCode = u8ApplNegCode;
    }

#endif

    /*! ********************************************* */
    /*! Check that the requested service is supported */
    /*! ********************************************* */

#if(DCM_REQUEST_MANUFACTURER_INDICATION_ENABLED == STD_ON)
    /*! If the Check Failed Flag is FALSE THEN */
    if(bCheckFailed == FALSE)
    {
#endif
      /*! Call bCheckServSupported */
      bCheckFailed = bCheckServSupported(u8CurrentSid,u8ProtocolSIDTable,
                                         pMsgContext,&u8ServiceIndex);

      /*! If bCheckServSupported returned TRUE THEN */
      if(bCheckFailed == TRUE)
      {
        /*! Set u8NegRespCode with DCM_E_SERVICENOTSUPPORTED*/
        u8NegRespCode = DCM_E_SERVICENOTSUPPORTED;
      }
#if(DCM_REQUEST_MANUFACTURER_INDICATION_ENABLED == STD_ON)
    }
#endif
    /*! ENDIF */

    /*! ****************************************************************** */
    /*! Check that the requested service is allowed in the current session */
    /*! ****************************************************************** */

    /*! IF Check Failed equal FALSE */
    if(bCheckFailed == FALSE)

    {
      /*! Call bCheckServSession */
      bCheckFailed = bCheckServSession(u8ProtocolSIDTable,
                                       u8ServiceIndex);
      /*! If bCheckServSession returned TRUE THEN */
      if(bCheckFailed == TRUE)
      {
        /*! Set u8NegRespCode with DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION*/
        u8NegRespCode = DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION;

      }
    }
    /*! ENDIF */

    /*! ****************************************************************** */
    /*! Check that the requested service is allowed in the current Security
     *  Level                                                              */
    /*! ****************************************************************** */

    /*! IF Check Failed equal FALSE THEN */
    if(bCheckFailed == FALSE)
    {
      /*! Call bCheckServSecurity */
      bCheckFailed = bCheckServSecurity(u8ProtocolSIDTable,
                                        u8ServiceIndex);
      /*! If bCheckServSecurity returned TRUE THEN */
      if(bCheckFailed == TRUE)
      {
        /*! Set u8NegRespCode with DCM_E_SECURITYACCESSDENIED*/
        u8NegRespCode = DCM_E_SECURITYACCESSDENIED;

      }

    }
    /*! ENDIF */

      /*! ****************************************************************** */
      /*! Verification of the Manuf/Suppl Application environment/permission */
      /*! ****************************************************************** */

#if(DCM_REQUEST_MANUF_SUPPL_INDIC_EN == STD_ON)
      /*! IF Check Failed Flag equal to FALSE THEN*/
      if(bCheckFailed == FALSE)
      {
        /*! Call bManufSupplIndicCheck */
        bCheckFailed =
          bManufSupplIndicCheck(u8CurrentSid,pMsgContext,&u8ApplNegCode);

        /*! If bManufSupplIndicCheck returned TRUE THEN */
        if(bCheckFailed == TRUE)
        {
          /*! Set u8NegRespCode with the error code returned by
              bManufSupplIndicCheck*/
          u8NegRespCode = u8ApplNegCode;
        }

      }
#endif


    /*! ************************************************** */
    /*! Check that the requested Sub-Function is supported */
    /*! ************************************************** */

    /*! IF Check Failed is False and the requested Service has
     *  Sub-Function available  i.e bDcmDsdSidTabSubfuncAvail = TRUE  THEN */
    if((bCheckFailed == FALSE) &&
        (bSERV_SUBFUNC_AVAIL(u8ProtocolSIDTable,u8ServiceIndex) == TRUE))
    {
      /*! Check that the request length is at least 2 , if not that set the
       *  u8NegRespCode with DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT */
      if(pMsgContext->reqDataLen == 0)
      {

        bCheckFailed = TRUE;
        u8NegRespCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

      }

      /*! IF Check Failed equal FALSE */
      if(bCheckFailed == FALSE)
      {

        /*! Call bCheckSubFuncSupp */
        bCheckFailed = bCheckSubFuncSupp(u8ServiceIndex,u8ProtocolSIDTable,
                                         pMsgContext,&u8SubFuncIndex);

        /*! If bCheckSubFuncSupp returned TRUE THEN */
        if(bCheckFailed == TRUE)
        {
          /*! Set u8NegRespCode with DCM_E_SUBFUNCTIONNOTSUPPORTED*/
          u8NegRespCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;

        }
      }


      /*! ****************************************************************** */
      /*! Check that the requested Sub-Function is allowed in the            */
      /*!                                                   current session  */
      /*! ****************************************************************** */

      /*! IF Check Failed equal FALSE */
      if(bCheckFailed == FALSE)
      {
        /*! Call bCheckSubFuncSession */
        bCheckFailed = bCheckSubFuncSession (u8ProtocolSIDTable,u8ServiceIndex,
                                             u8SubFuncIndex);

        /*! If bCheckSubFuncSession returned TRUE THEN */
        if(bCheckFailed == TRUE)
        {
          /*! Set u8NegRespCode with
           *  DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION*/
          u8NegRespCode = DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION;

        }
      }
      /*! ENDIF */


      /*! ****************************************************************** */
      /*! Check that the requested Sub-Function is allowed in the            */
      /*! current security level.                                            */
      /*! ****************************************************************** */

      /*! IF Check Failed equal FALSE */
      if(bCheckFailed == FALSE)

      {
        /*! Call bCheckSubFuncSecurity */
        bCheckFailed = bCheckSubFuncSecurity(u8ProtocolSIDTable,u8ServiceIndex,
                                             u8SubFuncIndex);

        /*! If bCheckSubFuncSecurity returned TRUE THEN */
        if(bCheckFailed == TRUE)
        {
          /*! Set u8NegRespCode with DCM_E_SECURITYACCESSDENIED*/
          u8NegRespCode = DCM_E_SECURITYACCESSDENIED;

        }

      }
      /*! ENDIF */

#if(DCM_REQUEST_SUPPLIER_INDICATION_ENABLED == STD_ON && \
    DCM_bPSA_SPECIFIC_CONF == STD_ON)
      /*! IF Check Failed Flag equal to FALSE THEN*/
      if(bCheckFailed == FALSE)
      {
        /*! If the service requested is not SecurityAccess Then */
        if(u8CurrentSid != u8SEC_ACCESS_SID)
        {

          /*! Call bDsdSupplIndicCheck */
          bCheckFailed = bDsdSupplIndicCheck(u8CurrentSid,pMsgContext,&u8ApplNegCode);

          /*! If bDsdSupplIndicCheck returned TRUE THEN */
          if(bCheckFailed == TRUE)
          {
            /*! Set u8NegRespCode with the error code returned by bDsdSupplIndicCheck*/
            u8NegRespCode = u8ApplNegCode;
          }
        } 

      }
      /*! ENDIF */
#endif
    }
    /*! ENDIF */

    /*! ****************************************************************** */
    /*! Verification of the Supplier Application environment/permission    */
    /*! ****************************************************************** */

#if(DCM_REQUEST_SUPPLIER_INDICATION_ENABLED == STD_ON && \
    DCM_bPSA_SPECIFIC_CONF == STD_OFF)
    /*! IF Check Failed Flag equal to FALSE THEN*/
    if(bCheckFailed == FALSE)
    {
      /*! Call bDsdSupplIndicCheck */
      bCheckFailed = bDsdSupplIndicCheck(u8CurrentSid,pMsgContext,&u8ApplNegCode);

      /*! If bDsdSupplIndicCheck returned TRUE THEN */
      if(bCheckFailed == TRUE)
      {
        /*! Set u8NegRespCode with the error code returned by bDsdSupplIndicCheck*/
        u8NegRespCode = u8ApplNegCode;
      }


    }
    /*! ENDIF */
#endif

    /*! IF Check Flag equal False THEN */
    if(bCheckFailed == FALSE)
    {

#if(DCM_bDIAG_SERV_IS_CALLOUT == STD_ON)
      /*! Store the bIsCallout which is present in the Service structure in
       *  the Dsd_strMsgInfo[idcontext].bIsCallout */
      Dsd_strMsgInfo[pMsgContext->idContext].bIsCallout =
          bSERV_IS_CALLOUT(u8ProtocolSIDTable,u8ServiceIndex);
#endif

      /*! Call the Configured Diagnostic Service with parameter pMsgContext*/
      (*Dcm_kstreDsdConfig.
      astrDcmDsdServiceTable[u8ProtocolSIDTable].
      ppkstrDcmDsdService[u8ServiceIndex]->pfvidDcmDsdSidTabFnc)(pMsgContext);

    }
    /*! ELSE */
    else
    {
      /*! IF u8NegRespCode not equal to zero THEN */
      if(u8NegRespCode != 0)
      {
        /*! Call vidSetNegResponse*/
        vidSetNegResponse(pMsgContext,u8NegRespCode);
      }
      /*! Call DslInternal_ProcessingDone*/
      DslInternal_ProcessingDone(pMsgContext->idContext);

    }
    /*! ENDIF */
#if(DCM_RESPOND_ALL_REQUEST == STD_OFF)
  }
  /*! END IF */
#endif

}
/* PRQA S 4700 --                                                           */
/* !Deviation : Re-Including autosar MemMap.h   */
/* PRQA S 0838 L1                                                             */
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1                                                                  */


/** \} */ /* end of DSD module group */
/** \} */ /* end of DSD Component group */



/*-------------------------------- end of file -------------------------------*/

