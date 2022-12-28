/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : Dsp                                                     */
/* !Description     : Diagnostic Communication Manager                        */
/*                                                                            */
/* !Module          : Dsp                                                     */
/* !Description     : Diagnostic Service Processing                           */
/*                                                                            */
/* !File            : Dcm_Dsp_Rdtci.c                                         */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2010 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   Y:/Prod_01/B791031T0/archives/B791031T0/04_Software_Component$*/
/* $Revision::   1.10.1.2 $$Author::   ahmedz         $$Date::   Oct 04 2011 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file
*
* \par
*   Internals of the module DSP. \n
*   This file contains the internals of the module DSP.  */
/******************************************************************************/

/******************************************************************************/
/*! \defgroup  Dsp_Comp_Id Dsp Component
* Diagnostic Service Processing
* \{
*/
/*! \defgroup DSP_Module_Id Dsp Module
* This is the grouping of Dsp module members.
* \{
*/
/******************************************************************************/


/******************************************************************************/
/* Includes                                                                   */
/******************************************************************************/

/* !Deviation : Re-Including autosar MemMap.h   */
/* PRQA S 0838 L1                                                             */
#include "Dcm.h"
#include "Dcm_Cfg.h"
#include "Dcm_Internal.h"
#include "Dem.h"
#include "Rte_Dcm.h"
#include "SchM_Dcm.h"
#include "BswM_Dcm.h"




#if (DCM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif


/* PRQA L:L1                                                                  */
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/



/*! \Description  ReadDTCInformation sub-functions                        /n */ 
#define u8SUB_FUNCTION        0U

/*! Decription  ReadDTCInformation/GetDTC/DTCStatusMask byte index        /n */ 
#define u8INDEX_STATUS_MASK       1U
/*! Decription  ReadDTCInformation/GetDTC/DTCAndStatusRecord offset       /n */ 
#define u8OFFSET_GET_DTC_REC      2
/*! Decription  ReadDTCInformation/GetDTC/DTCAndStatusRecord length/DTC   /n */ 
#define u8LENGTH_GET_DTC_REC      4
/*! Decription  ReadDTCInformation/GetNumberDTC/DTCFormatId byte index    /n */ 
#define u8INDEX_DTC_FORMAT_ID     2U
/*! Decription  ReadDTCInformation/GetNumberDTC/DTCCount byte index       /n */ 
#define u8INDEX_DTC_COUNT         3U
/*! Decription  ReadDTCInformation/GetNumberDTC response length           /n */ 
#define u8RDI_RNBSM_RESP_LEN      5
/*! Decription  DTCStatusMask to all status bits                          /n */ 
#define u8ALL_STATUS_BITS         ((uint8)0xFF)
/*! Decription  ReadDTCInformation/SnapshotRecord/DTCMaskRecord HIGH      /n */ 
#define u8RDI_DTC_MASK_HIGH       1U
/*! Decription  ReadDTCInformation/SnapshotRecord/DTCMaskRecord MIDDLE    /n */ 
#define u8RDI_DTC_MASK_MED        2U
/*! Decription  ReadDTCInformation/SnapshotRecord/DTCMaskRecord LOW       /n */ 
#define u8RDI_DTC_MASK_LOW        3U
/*! Decription  ReadDTCInformation/SnapshotRecord/SnapshotRecordNumber    /n */ 
#define u8RDI_SNAPSHOT_REC_NUM    4U
/*! Decription  ReadDTCInformation/SnapshotRecord/header size             /n */ 
#define u8RDI_SSREC_HEAD_SIZE     5
/*! Decription  ReadDTCInformation/SnapshotRecord/DTCStatus in response   /n */ 
#define u8RDI_SSREC_DTC_STATUS    4U
/*! ReadDTCInformation sub-functions                                      /n */ 
/*! Description  reportNumberOfDTCByStatusMask                            /n */ 
#define u8R1_NUM_DTC_BY_STM       0x01U
/*! Description  reportDTCByStatusMask                                    /n */ 
#define u8R1_DTC_BY_STM           0x02U
/*! Description  reportMirrorMemoryDTCByStatusMask                        /n */ 
#define u8R1_M_DTC_BY_STM         0x0FU
/*! Description  reportNumberOfMirrorMemoryDTCByStatusMask                /n */ 
#define u8R1_NUM_M_DTC_BY_STM     0x11U
/*! Description  reportNumberOfEmissionsRelatedOBDDTCByStatusMask         /n */ 
#define u8R1_NUM_OBDDTC_BY_STM    0x12U
/*! Description  reportEmissionsRelatedOBDDTCByStatusMask                 /n */ 
#define u8R1_OBD_DTC_BY_STM       0x13U
/*! Description  reportDTCSnapshotIdentification                          /n */ 
#define u8R2_SNAPSHOT_ID          0x03U


/*! Description  reportNumberOfDTCBySeverityMaskRecord                    /n */ 
#define u8R5_NUM_DTC_BY_SEVMSK    0x07U
/*! Description  reportDTCBySeverityMaskRecord                            /n */ 
#define u8R5_DTC_BY_SEVMASK       0x08U
/*! Description  reportSeverityInformationOfDTC                           /n */ 
#define u8R6_SEV_INFO_OF_DTC      0x09U
/*! Description  reportSupportedDTC                                       /n */ 
#define u8R7_SUPPORTED_DTC        0x0AU
/*! Description  reportFirstTestFailedDTC                                 /n */ 
#define u8R7_FIRST_FAIL_DTC       0x0BU
/*! Description  reportFirstConfirmedDTC                                  /n */ 
#define u8R7_FIRST_CONF_DTC       0x0CU
/*! Description  reportMostRecentTestFailedDTC                            /n */ 
#define u8R7_RECENT_FAIL_DTC      0x0DU
/*! Description  reportMostRecentConfirmedDTC                             /n */ 
#define u8R7_RECENT_CONF_DTC      0x0EU
/*! Description  reportDTCFaultDetectionCounter                           /n */ 
#define u8R7_FAULT_DET_COUNTER    0x14U
/*! Description  reportDTCWithPermanentStatus                             /n */ 
#define u8R7_DTC_WITH_PERM_ST     0x15U




/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [3456]: Macros are used for performance.   */
/* PRQA S 3453 ++                                                             */

/* !Deviation : Macros are needed for code readability and maintenance       */ 
/* PRQA S 3459 ++ */
#define vidRESPOND_NRC(u8NegRespCode) \
 do { \
    DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE; \
    DsdInternal_SetNegResponse(DspInternal_apstreMsgContext[u8Context],u8NegRespCode);\
    DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]); \
 } while(0)

#define vidRESPOND_OK() \
 do { \
    DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE; \
    DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]); \
 } while(0)

/*! \Description  Shift lefts a data by given no. of bits */
#define u32SHIFT_LEFT(u8Data, u8ShiftBits) \
   ((((uint32)(u8Data)) & 0x000000FFUL) << (u8ShiftBits))

/* PRQA S 3456 --                                                             */
/* PRQA S 3453 --                                                             */

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/



/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/


#if(DCM_bREAD_DTC_INFO_ENABLED == STD_ON)
#define DCM_START_SEC_VAR_BOOLEAN
#include "MemMap.h"

#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
static VAR(boolean,DCM_VAR) Dsp_bDtcPadding;
#endif
static VAR(boolean,DCM_VAR) Dsp_bRdtciFirstCall;

/* !Deviation : Re-Including autosar MemMap.h   */
/* PRQA S 0838 L1                                                             */
#define DCM_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"
#endif


#if(DCM_bREAD_DTC_INFO_ENABLED == STD_ON)
#define DCM_START_SEC_VAR_8BIT
#include "MemMap.h"


/*! \Description  current record number        /n */
/*! /Range        0..0xFE                                       /n */
static VAR(uint8, DCM_VAR) Dsp_u8CurrentRecord;

/*! \Description  last record number)           /n */
/*! /Range        0..0xFE                                              /n */
static VAR(uint8, DCM_VAR) Dsp_u8LastRecord;


#define DCM_STOP_SEC_VAR_8BIT
#include "MemMap.h"


#define DCM_START_SEC_VAR_32BIT
#include "MemMap.h"


/*! \Description  ReadDTCInformation remaining Data. Used for:              \n
                  Remaining DTCs, Remaining buffer for snapshot data        \n
    \Range        0..0xFFFF                                                 */
static VAR(uint32, DCM_VAR) Dsp_u32RemainingData;


static VAR(uint32, DCM_VAR) Dsp_u32ResDataIndex;


#define DCM_STOP_SEC_VAR_32BIT
#include "MemMap.h"

#endif




/* PRQA L:L1 */ 


/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/

/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*              for memory allocation and should be included several times.  */ 
/* PRQA S 5087,0838 L1 */ 
#define DCM_START_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */ 


#if(DCM_bREAD_DTC_INFO_ENABLED == STD_ON)
static FUNC(Std_ReturnType,DCM_CODE) u8SetStatusAvailMask(
   VAR(Dcm_IdContextType,AUTOMATIC) u8Context);
static FUNC(void,DCM_CODE) vidMainNumberOfDTCs(
   VAR(Dcm_IdContextType,AUTOMATIC) u8Context,
   VAR(Dem_ReturnSetFilterType,AUTOMATIC) udtSetFilterStatus);
static FUNC(void,DCM_CODE) vidMainReportDtc(
   VAR(Dcm_IdContextType,AUTOMATIC) u8Context,
   VAR(Dem_ReturnSetFilterType,AUTOMATIC) udtSetFilterStatus);
static FUNC(void,DCM_CODE) vidMainSnapshotRecordByDTC(
   VAR(Dcm_IdContextType,AUTOMATIC) u8Context);
static FUNC(void,DCM_CODE) vidSubExtendDataRecordByDTCNum(
   VAR(Dcm_IdContextType,AUTOMATIC) u8Context);
static FUNC(void,DCM_CODE) vidSubSnapshotRecByIndent(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context);

static FUNC(void,DCM_CODE) vidSubSnapshotRecByRecNum(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context);

static FUNC(void,DCM_CODE) vidMainExtendDataRecByDtc(
    VAR(Dcm_IdContextType,AUTOMATIC) u8Context);

static FUNC(void,DCM_CODE) vidGetFreezeFrameByDTC(
   VAR(Dcm_IdContextType,AUTOMATIC) u8Context);

static FUNC(void,DCM_CODE) vidGetDataRecordByDTC(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context);

static FUNC(void,DCM_CODE) vidSubNumOfDtcByStMask(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context);
static FUNC(void,DCM_CODE) vidSubNumOfDtcBySevMask(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context);
static FUNC(void,DCM_CODE) vidSubDtcByStMask(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context);
static FUNC(void,DCM_CODE) vidSubMirrorDtcByStMask(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context);
static FUNC(void,DCM_CODE) vidSubNumOfMirrorDtcByStMask(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context);
static FUNC(void,DCM_CODE) vidSubNumOfObdDtcByStMask(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context);
static FUNC(void,DCM_CODE) vidSubObdDtcByStMask(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context);
static FUNC(void,DCM_CODE) vidSubSnapshotRecByDtc(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context);
static FUNC(void,DCM_CODE) vidSubSupportedDtc(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context);
static FUNC(void,DCM_CODE) vidSubDtcWithPermSt(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context);

static FUNC(void,DCM_CODE) vidSubDtcOccurrenceTime(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context);

static FUNC(void,DCM_CODE) vidSubReportDtcFaultDetCount(
    VAR(Dcm_IdContextType,AUTOMATIC) u8Context);

static FUNC(void,DCM_CODE) vidSubReportSeverityInfo(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context);

static FUNC(void,DCM_CODE) vidSubReportDtcBySevMaskRecord(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context);

static FUNC(void,DCM_CODE) vidMainDtcFaultDetCount(
    VAR(Dcm_IdContextType,AUTOMATIC) u8Context);


/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/



/******************************************************************************/
/*! \Description subfunction:0x01   Report Number of Dtc by status mask     \n*/
/******************************************************************************/
static FUNC(void,DCM_CODE) vidSubNumOfDtcByStMask(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  VAR(Dem_ReturnSetFilterType,AUTOMATIC) udtSetFilterStatus;


  /*! If request message length equals 2 */
  if (DspInternal_apstreMsgContext[u8Context]->reqDataLen == 2)
  {
    /*! Set the DTC Dem filter                                               */ 
    udtSetFilterStatus = Dem_SetDTCFilter(
       DspInternal_apstreMsgContext[u8Context]->reqData[u8INDEX_STATUS_MASK],
       DEM_DTC_KIND_ALL_DTCS,
       DEM_DTC_ORIGIN_PRIMARY_MEMORY,
       DEM_FILTER_WITH_SEVERITY_NO,
       DEM_SEVERITY_NO_SEVERITY,
       DEM_FILTER_FOR_FDC_NO);
    /*! Set current status                                                   */ 
    DspInternal_au8eStatus[u8Context] = DspInternal_u8BLOCKED;
    /*! Process request and respond (if applicable in current cycle)         */ 
    vidMainNumberOfDTCs(u8Context, udtSetFilterStatus);
    /*! Set current status                                                   */ 
    if (DspInternal_au8eStatus[u8Context] == DspInternal_u8BLOCKED)
    {
      DspInternal_au8eStatus[u8Context] = DspInternal_u8READ_DTC_INFO;
    }
  }
  else
  {
    /*! Send 0x13 Negative Response.*/
    /* PRQA S 3361 ++ */ 
    vidRESPOND_NRC(DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    /* PRQA S 3361 -- */ 
  }
}


/******************************************************************************/
/*! \Description subfunction:0x07   Report Number of Dtc by Severity mask   \n*/
/******************************************************************************/
static FUNC(void,DCM_CODE) vidSubNumOfDtcBySevMask(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  VAR(Dem_ReturnSetFilterType,AUTOMATIC) udtSetFilterStatus;


  /*! If request message length equals 3 */
  if (DspInternal_apstreMsgContext[u8Context]->reqDataLen == 3)
  {
    /*! Set the DTC Dem filter                                               */ 
    udtSetFilterStatus = Dem_SetDTCFilter(
       DspInternal_apstreMsgContext[u8Context]->reqData[2],
       DEM_DTC_KIND_ALL_DTCS,
       DEM_DTC_ORIGIN_PRIMARY_MEMORY,
       DEM_FILTER_WITH_SEVERITY_YES,
       DspInternal_apstreMsgContext[u8Context]->reqData[1],
       DEM_FILTER_FOR_FDC_NO);
    /*! Set current status                                                   */ 
    DspInternal_au8eStatus[u8Context] = DspInternal_u8BLOCKED;
    /*! Process request and respond (if applicable in current cycle)         */ 
    vidMainNumberOfDTCs(u8Context, udtSetFilterStatus);
    /*! Set current status                                                   */ 
    if (DspInternal_au8eStatus[u8Context] == DspInternal_u8BLOCKED)
    {
      DspInternal_au8eStatus[u8Context] = DspInternal_u8READ_DTC_INFO;
    }
  }
  else
  {
    /* PRQA S 3361 ++ */ 
    vidRESPOND_NRC(DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    /* PRQA S 3361 -- */ 
  }
}

/******************************************************************************/
/*! \Description subfunction:0x12   Report Number of Emission Related Obd Dtc
 *                                  by status mask     \n*/
/******************************************************************************/
static FUNC(void,DCM_CODE) vidSubNumOfObdDtcByStMask(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  VAR(Dem_ReturnSetFilterType,AUTOMATIC) udtSetFilterStatus;


  /*! If request message length equals 2 */
  if (DspInternal_apstreMsgContext[u8Context]->reqDataLen == 2)
  {
    /*! Set the DTC Dem filter                                               */ 
    udtSetFilterStatus = Dem_SetDTCFilter(
       DspInternal_apstreMsgContext[u8Context]->reqData[u8INDEX_STATUS_MASK],
       DEM_DTC_KIND_EMISSION_REL_DTCS,
       DEM_DTC_ORIGIN_PRIMARY_MEMORY,
       DEM_FILTER_WITH_SEVERITY_NO,
       DEM_SEVERITY_NO_SEVERITY,
       DEM_FILTER_FOR_FDC_NO);
    /*! Set current status                                                   */ 
    DspInternal_au8eStatus[u8Context] = DspInternal_u8BLOCKED;
    /*! Process request and respond (if applicable in current cycle)         */ 
    vidMainNumberOfDTCs(u8Context, udtSetFilterStatus);
    /*! Set current status                                                   */ 
    if (DspInternal_au8eStatus[u8Context] == DspInternal_u8BLOCKED)
    {
      DspInternal_au8eStatus[u8Context] = DspInternal_u8READ_DTC_INFO;
    }
  }
  else
  {
    /* PRQA S 3361 ++ */ 
    vidRESPOND_NRC(DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    /* PRQA S 3361 -- */ 
  }
}


/******************************************************************************/
/*! \Description subfunction:0x11   Report Number of mirror memorry Dtc
 *                                  by status mask     \n*/
/******************************************************************************/
static FUNC(void,DCM_CODE) vidSubNumOfMirrorDtcByStMask(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  VAR(Dem_ReturnSetFilterType,AUTOMATIC) udtSetFilterStatus;

  /*! If request message length equals 2 */
  if (DspInternal_apstreMsgContext[u8Context]->reqDataLen == 2)
  {
    /*! Set the DTC Dem filter                                               */ 
    udtSetFilterStatus = Dem_SetDTCFilter(
       DspInternal_apstreMsgContext[u8Context]->reqData[u8INDEX_STATUS_MASK],
       DEM_DTC_KIND_ALL_DTCS,
       DEM_DTC_ORIGIN_MIRROR_MEMORY,
       DEM_FILTER_WITH_SEVERITY_NO,
       DEM_SEVERITY_NO_SEVERITY,
       DEM_FILTER_FOR_FDC_NO);
    /*! Set current status                                                   */ 
    DspInternal_au8eStatus[u8Context] = DspInternal_u8BLOCKED;
    /*! Process request and respond (if applicable in current cycle)         */ 
    vidMainNumberOfDTCs(u8Context, udtSetFilterStatus);
    /*! Set current status                                                   */ 
    if (DspInternal_au8eStatus[u8Context] == DspInternal_u8BLOCKED)
    {
      DspInternal_au8eStatus[u8Context] = DspInternal_u8READ_DTC_INFO;
    }
  }
  else
  {
    /* PRQA S 3361 ++ */ 
    vidRESPOND_NRC(DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    /* PRQA S 3361 -- */ 
  }
}

/* Deviation: the function has high cyclomatic complexity as it depends   \n
              on several parameters, and it will not be readable in case  \n
              we splitted into several functions                          \n */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Description Handles Sub-Functions: 0x0B,0x0C,0x0D,0x0E
 *               ReportFirstTestFailedDTC,ReportFirstConfirmedDTC,
 *               ReportMostRecentTestFailedDTC,ReportMostRecentConfirmedDTC \n
 *   \Trace_To   CDD-1008(0),CDD-1009(0),CDD-1010(0)
******************************************************************************/
static FUNC(void,DCM_CODE) vidSubDtcOccurrenceTime(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  Dem_ReturnGetDTCByOccurrenceTimeType u8GetDtcReturn;
  uint32                               u32Dtc;
  Dem_DTCRequestType                   u8DtcRequestType;
  Dem_ReturnGetStatusOfDTCType         u8DtcStatusReturn;
  uint8                                u8DtcStatus;
  uint8                                u8NegRespCode = 0;
  Std_ReturnType                       u8ReturnStd;

  /*! If request message length equals 1 */
  if (DspInternal_apstreMsgContext[u8Context]->reqDataLen == 1)
  {
    /*! Set status availability mask */
    u8ReturnStd = u8SetStatusAvailMask(u8Context);
    if(u8ReturnStd == E_OK)
    {
      /*! If status availability mask not equal to zero */
      if(DspInternal_apstreMsgContext[u8Context]->resData[u8INDEX_STATUS_MASK] != 0)
      {
        /*! Set the request type */
        switch(DspInternal_apstreMsgContext[u8Context]->reqData[0])
        {
        case u8R7_FIRST_FAIL_DTC:
          u8DtcRequestType = DEM_FIRST_FAILED_DTC;
          break;
        case u8R7_FIRST_CONF_DTC:
          u8DtcRequestType = DEM_MOST_RECENT_FAILED_DTC;
          break;
        case u8R7_RECENT_FAIL_DTC:
          u8DtcRequestType = DEM_FIRST_DET_CONFIRMED_DTC;
          break;
        default:
          u8DtcRequestType = DEM_MOST_REC_DET_CONFIRMED_DTC;
          break;

        }
        /*! Get DTC by occurrence time */
        u8GetDtcReturn = Dem_GetDTCByOccurrenceTime(u8DtcRequestType,
          DEM_DTC_KIND_ALL_DTCS,
          &u32Dtc);
        /*! If Get DTC by occurrence time returned OK */
        if(u8GetDtcReturn == DEM_OCCURR_OK)
        {
          /*! If Dtc not equal zero Then */
          if(u32Dtc != 0)
          {
            /*! get DTC status                                                  */
            u8DtcStatusReturn =Dem_GetStatusOfDTC(u32Dtc,
              DEM_DTC_KIND_ALL_DTCS,
              DEM_DTC_ORIGIN_PRIMARY_MEMORY,
              &u8DtcStatus);
            /*! IF get DTC status returned OK                                   */
            if (u8DtcStatusReturn == DEM_STATUS_OK)
            {

              /*! Save DTC in response buffer                                   */
              DspInternal_apstreMsgContext[u8Context]->resData[2] =
                (uint8)((u32Dtc & 0x00FF0000UL) >> 16U);
              DspInternal_apstreMsgContext[u8Context]->resData[3] =
                (uint8)((u32Dtc & 0x0000FF00UL) >> 8U);
              DspInternal_apstreMsgContext[u8Context]->resData[4] =
                (uint8)(u32Dtc & 0x000000FFUL);
              /*! Set statusOfDTC parameter in the response buffer */
              DspInternal_apstreMsgContext[u8Context]->resData[5] = u8DtcStatus;
              /*! Set the response length */
              DspInternal_apstreMsgContext[u8Context]->resDataLen = 6;

            }  
            /*! Else */
            else
            {
              /*! set the negative response code to 0x31 */
              u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;
            }
          }
          /*! Else */
          else
          {
            /*! Set the response length */
            DspInternal_apstreMsgContext[u8Context]->resDataLen = 2;

          }
        }
        /*! Else [Get DTC by occurrence time] */
        else
        {
          /*! set the negative response code to 0x31 */
          u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;
        }
      }
    }
    /*! ELSE : Set status availability mask returned error*/
    else
    {
      /*! set the negative response code to 0x31 */
      u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;
    }


  }
  /*! Else : Request Length Not Correct */
  else
  {
    /*! set the negative response code to 0x13 */
    u8NegRespCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

  }

  /*! If Negative response to be sent */
  if(u8NegRespCode != 0)
  {
    /*! Send the Negative Response */
    /* PRQA S 3361 ++ */
    vidRESPOND_NRC(u8NegRespCode);
    /* PRQA S 3361 -- */
  }
  /*! Else */
  else
  {
    /*! Send positive response */
    /* PRQA S 3361 ++ */
    vidRESPOND_OK();
    /* PRQA S 3361 -- */

  }
}
/* PRQA S 4700 -- */

/******************************************************************************/
/*! \Description Sub-Function 0x02: reportDTCByStatusMask                   \n*/
/******************************************************************************/
static FUNC(void,DCM_CODE) vidSubDtcByStMask(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  Dem_ReturnSetFilterType udtSetFilterStatus;
  Std_ReturnType          u8ReturnSetStatusAvail;


  /*! IF the request length equals 2 */
  if (DspInternal_apstreMsgContext[u8Context]->reqDataLen == 2)
  {
    /*! Set the DTC Dem filter                                               */
    udtSetFilterStatus = Dem_SetDTCFilter(
      DspInternal_apstreMsgContext[u8Context]->reqData[u8INDEX_STATUS_MASK],
      DEM_DTC_KIND_ALL_DTCS,
      DEM_DTC_ORIGIN_PRIMARY_MEMORY,
      DEM_FILTER_WITH_SEVERITY_NO,
      DEM_SEVERITY_NO_SEVERITY,
      DEM_FILTER_FOR_FDC_NO);
    Dsp_u32RemainingData = 0;
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    Dsp_bDtcPadding = FALSE;
#endif
    /*! Set current status                                                   */
    DspInternal_au8eStatus[u8Context] = DspInternal_u8BLOCKED;
    /*! Set Status Availabilty Mask */
    u8ReturnSetStatusAvail = u8SetStatusAvailMask(u8Context);

    /*! IF set status availability Mask successful */
    if(u8ReturnSetStatusAvail == E_OK)
    {
      /*! If status availability mask not equal to zero */
      if(DspInternal_apstreMsgContext[u8Context]->
          resData[u8INDEX_STATUS_MASK] != 0)
      {
        /*! Process request and respond (if applicable in current cycle)      */
        vidMainReportDtc(u8Context, udtSetFilterStatus);
        /*! Set current status                                                */
        if (DspInternal_au8eStatus[u8Context] == DspInternal_u8BLOCKED)
        {
          DspInternal_au8eStatus[u8Context] = DspInternal_u8READ_DTC_INFO;
        }
      }
      /*! Else : Dtc status avail. mask equals zero */
      else
      {
        /*! Send the response */
        /* PRQA S 3361 ++ */
        vidRESPOND_OK();
        /* PRQA S 3361 -- */
      }
    }
    /*! ELSE : Set status availability mask failed */
    else
    {
      /*! Send NRC 0x31 */
      /* PRQA S 3361 ++ */
      vidRESPOND_NRC(DCM_E_REQUESTOUTOFRANGE);
      /* PRQA S 3361 -- */
    }
  }
  /*! Else : Request length is incorrect */
  else
  {
    /*! Send NRC 0x13 */
    /* PRQA S 3361 ++ */
    vidRESPOND_NRC(DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    /* PRQA S 3361 -- */
  }
}

/******************************************************************************/
/*! \Description Sub-Function 0x0F: reportMirrorMemoryDTCByStatusMask       \n*/
/******************************************************************************/
static FUNC(void,DCM_CODE) vidSubMirrorDtcByStMask(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  Dem_ReturnSetFilterType udtSetFilterStatus;
  Std_ReturnType          u8ReturnSetStatusAvail;


  /*! IF the request length equals 2 */
  if (DspInternal_apstreMsgContext[u8Context]->reqDataLen == 2)
  {
    /*! Set the DTC Dem filter                                               */
    udtSetFilterStatus = Dem_SetDTCFilter(
       DspInternal_apstreMsgContext[u8Context]->reqData[u8INDEX_STATUS_MASK],
       DEM_DTC_KIND_ALL_DTCS,
       DEM_DTC_ORIGIN_MIRROR_MEMORY,
       DEM_FILTER_WITH_SEVERITY_NO,
       DEM_SEVERITY_NO_SEVERITY,
       DEM_FILTER_FOR_FDC_NO);
    Dsp_u32RemainingData = 0;
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    Dsp_bDtcPadding = FALSE;
#endif
    /*! Set current status                                                   */
    DspInternal_au8eStatus[u8Context] = DspInternal_u8BLOCKED;

    /*! Set Status Availabilty Mask */
    u8ReturnSetStatusAvail = u8SetStatusAvailMask(u8Context);

    /*! IF set status availability Mask successful */
    if(u8ReturnSetStatusAvail == E_OK)
    {
      /*! If status availability mask not equal to zero */
      if(DspInternal_apstreMsgContext[u8Context]->
          resData[u8INDEX_STATUS_MASK] != 0)
      {
        /*! Process request and respond (if applicable in current cycle)      */
        vidMainReportDtc(u8Context, udtSetFilterStatus);
        /*! Set current status                                                */
        if (DspInternal_au8eStatus[u8Context] == DspInternal_u8BLOCKED)
        {
          DspInternal_au8eStatus[u8Context] = DspInternal_u8READ_DTC_INFO;
        }
      }
      /*! Else : Dtc status avail. mask equals zero */
      else
      {
        /*! Send the response */
        /* PRQA S 3361 ++ */
        vidRESPOND_OK();
        /* PRQA S 3361 -- */
      }
    }
    /*! ELSE : Set status availability mask failed */
    else
    {
      /*! Send NRC 0x31 */
      /* PRQA S 3361 ++ */
      vidRESPOND_NRC(DCM_E_REQUESTOUTOFRANGE);
      /* PRQA S 3361 -- */
    }
  }
  /*! Else : Request length is incorrect */
  else
  {
    /*! Send NRC 0x13 */
    /* PRQA S 3361 ++ */
    vidRESPOND_NRC(DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    /* PRQA S 3361 -- */
  }
}


/******************************************************************************/
/*! \Description Sub-Function 0x13: reportEmissionsRelatedOBDDTCByStatusMask\n*/
/******************************************************************************/
static FUNC(void,DCM_CODE) vidSubObdDtcByStMask(

  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  Dem_ReturnSetFilterType udtSetFilterStatus;
  Std_ReturnType          u8ReturnSetStatusAvail;


  /*! IF the request length equals 2 */
  if (DspInternal_apstreMsgContext[u8Context]->reqDataLen == 2)
  {
    /*! Set the DTC Dem filter                                               */ 
    udtSetFilterStatus = Dem_SetDTCFilter(
        DspInternal_apstreMsgContext[u8Context]->reqData[u8INDEX_STATUS_MASK],
        DEM_DTC_KIND_EMISSION_REL_DTCS,
        DEM_DTC_ORIGIN_PRIMARY_MEMORY,
        DEM_FILTER_WITH_SEVERITY_NO,
        DEM_SEVERITY_NO_SEVERITY,
        DEM_FILTER_FOR_FDC_NO);
    Dsp_u32RemainingData = 0;
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    Dsp_bDtcPadding = FALSE;
#endif
    /*! Set current status                                                   */ 
    DspInternal_au8eStatus[u8Context] = DspInternal_u8BLOCKED;

    /*! Set Status Availabilty Mask */
    u8ReturnSetStatusAvail = u8SetStatusAvailMask(u8Context);

    /*! IF set status availability Mask successful */
    if(u8ReturnSetStatusAvail == E_OK)
    {
      /*! If status availability mask not equal to zero */
      if(DspInternal_apstreMsgContext[u8Context]->
          resData[u8INDEX_STATUS_MASK] != 0)
      {
        /*! Process request and respond (if applicable in current cycle)      */
        vidMainReportDtc(u8Context, udtSetFilterStatus);
        /*! Set current status                                                */
        if (DspInternal_au8eStatus[u8Context] == DspInternal_u8BLOCKED)
        {
          DspInternal_au8eStatus[u8Context] = DspInternal_u8READ_DTC_INFO;
        }
      }
      /*! Else : Dtc status avail. mask equals zero */
      else
      {
        /*! Send the response */
        /* PRQA S 3361 ++ */
        vidRESPOND_OK();
        /* PRQA S 3361 -- */
      }
    }
    /*! ELSE : Set status availability mask failed */
    else
    {
      /*! Send NRC 0x31 */
      /* PRQA S 3361 ++ */
      vidRESPOND_NRC(DCM_E_REQUESTOUTOFRANGE);
      /* PRQA S 3361 -- */
    }
  }
  /*! Else : Request length is incorrect */
  else
  {
    /*! Send NRC 0x13 */
    /* PRQA S 3361 ++ */
    vidRESPOND_NRC(DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    /* PRQA S 3361 -- */
  }
}


/******************************************************************************/
/*! \Description Sub-Function 0x0A: reportSupportedDTCs                     \n*/
/******************************************************************************/
static FUNC(void,DCM_CODE) vidSubSupportedDtc(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{

  Dem_ReturnSetFilterType udtSetFilterStatus;
  Std_ReturnType          u8ReturnSetStatusAvail;


  /*! IF the request length equals 1 */
  if (DspInternal_apstreMsgContext[u8Context]->reqDataLen == 1)
  {
    /*! Set the DTC Dem filter                                               */ 
    udtSetFilterStatus = Dem_SetDTCFilter(
        u8ALL_STATUS_BITS,
        DEM_DTC_KIND_ALL_DTCS,
        DEM_DTC_ORIGIN_PRIMARY_MEMORY,
        DEM_FILTER_WITH_SEVERITY_NO,
        DEM_SEVERITY_NO_SEVERITY,
        DEM_FILTER_FOR_FDC_NO);
    Dsp_u32RemainingData = 0;
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    Dsp_bDtcPadding = FALSE;
#endif
    /*! Set current status                                                   */ 
    DspInternal_au8eStatus[u8Context] = DspInternal_u8BLOCKED;

    /*! Set Status Availabilty Mask */
    u8ReturnSetStatusAvail = u8SetStatusAvailMask(u8Context);

    /*! IF set status availability Mask successful */
    if(u8ReturnSetStatusAvail == E_OK)
    {
      /*! If status availability mask not equal to zero */
      if(DspInternal_apstreMsgContext[u8Context]->
          resData[u8INDEX_STATUS_MASK] != 0)
      {
        /*! Process request and respond (if applicable in current cycle)      */
        vidMainReportDtc(u8Context, udtSetFilterStatus);
        /*! Set current status                                                */
        if (DspInternal_au8eStatus[u8Context] == DspInternal_u8BLOCKED)
        {
          DspInternal_au8eStatus[u8Context] = DspInternal_u8READ_DTC_INFO;
        }
      }
      /*! Else : Dtc status avail. mask equals zero */
      else
      {
        /*! Send the response */
        /* PRQA S 3361 ++ */
        vidRESPOND_OK();
        /* PRQA S 3361 -- */
      }
    }
    /*! ELSE : Set status availability mask failed */
    else
    {
      /*! Send NRC 0x31 */
      /* PRQA S 3361 ++ */
      vidRESPOND_NRC(DCM_E_REQUESTOUTOFRANGE);
      /* PRQA S 3361 -- */
    }
  }
  /*! Else : Request length is incorrect */
  else
  {
    /*! Send NRC 0x13 */
    /* PRQA S 3361 ++ */
    vidRESPOND_NRC(DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    /* PRQA S 3361 -- */
  }
}


/******************************************************************************/
/*! \Description Sub-Function 0x15: reportDTCWithPermantStatus              \n*/
/******************************************************************************/
static FUNC(void,DCM_CODE) vidSubDtcWithPermSt(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  VAR(Dem_ReturnSetFilterType,AUTOMATIC) udtSetFilterStatus;
  Std_ReturnType                         u8ReturnSetStatusAvail;


  /*! IF the request length equals 1 */
  if (DspInternal_apstreMsgContext[u8Context]->reqDataLen == 1)
  {
    /*! Set the DTC Dem filter                                               */ 
    udtSetFilterStatus = Dem_SetDTCFilter(
        u8ALL_STATUS_BITS,
        DEM_DTC_KIND_ALL_DTCS,
        DEM_DTC_ORIGIN_PERMANENT_MEMORY,
        DEM_FILTER_WITH_SEVERITY_NO,
        DEM_SEVERITY_NO_SEVERITY,
        DEM_FILTER_FOR_FDC_NO);
    Dsp_u32RemainingData = 0;
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    Dsp_bDtcPadding = FALSE;
#endif
    /*! Set current status                                                   */ 
    DspInternal_au8eStatus[u8Context] = DspInternal_u8BLOCKED;

    /*! Set Status Availabilty Mask */
    u8ReturnSetStatusAvail = u8SetStatusAvailMask(u8Context);

    /*! IF set status availability Mask successful */
    if(u8ReturnSetStatusAvail == E_OK)
    {
      /*! If status availability mask not equal to zero */
      if(DspInternal_apstreMsgContext[u8Context]->
          resData[u8INDEX_STATUS_MASK] != 0)
      {
        /*! Process request and respond (if applicable in current cycle)      */
        vidMainReportDtc(u8Context, udtSetFilterStatus);
        /*! Set current status                                                */
        if (DspInternal_au8eStatus[u8Context] == DspInternal_u8BLOCKED)
        {
          DspInternal_au8eStatus[u8Context] = DspInternal_u8READ_DTC_INFO;
        }
      }
      /*! Else : Dtc status avail. mask equals zero */
      else
      {
        /*! Send the response */
        /* PRQA S 3361 ++ */
        vidRESPOND_OK();
        /* PRQA S 3361 -- */
      }
    }
    /*! ELSE : Set status availability mask failed */
    else
    {
      /*! Send NRC 0x31 */
      /* PRQA S 3361 ++ */
      vidRESPOND_NRC(DCM_E_REQUESTOUTOFRANGE);
      /* PRQA S 3361 -- */
    }
  }
  /*! Else : Request length is incorrect */
  else
  {
    /*! Send NRC 0x13 */
    /* PRQA S 3361 ++ */
    vidRESPOND_NRC(DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    /* PRQA S 3361 -- */
  }
}


/******************************************************************************/
/*! \Description Sub-Function 0x14: reportDTCFaultDetectionCounnter         \n*/
/******************************************************************************/
static FUNC(void,DCM_CODE) vidSubReportDtcFaultDetCount(
    VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{

  /*! IF the request length equals 1 */
  if (DspInternal_apstreMsgContext[u8Context]->reqDataLen == 1)
  {

    Dsp_u32RemainingData = 0;
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    Dsp_bDtcPadding = FALSE;
#endif
    /*! Set current status  */
    DspInternal_au8eStatus[u8Context] = DspInternal_u8READ_DTC_INFO;
    Dsp_bRdtciFirstCall = FALSE;
  }
  /*! Else : Request length is incorrect */
  else
  {
    /*! Send NRC 0x13 */
    /* PRQA S 3361 ++ */
    vidRESPOND_NRC(DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    /* PRQA S 3361 -- */
  }


}


/******************************************************************************/
/*! \Description Sub-Function 0x08: reportDTCBySeverityMaskRecord         \n
    \Trace_To CDD-0015(0)    */
/******************************************************************************/
static FUNC(void,DCM_CODE) vidSubReportDtcBySevMaskRecord(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  VAR(Dem_ReturnSetFilterType,AUTOMATIC) udtSetFilterStatus;
  Std_ReturnType                         u8ReturnStd;


  /*! IF the request length equals 3 */
  if (DspInternal_apstreMsgContext[u8Context]->reqDataLen == 3)
  {
    /*! Set the DTC Dem filter                                               */
    udtSetFilterStatus = Dem_SetDTCFilter(
      DspInternal_apstreMsgContext[u8Context]->reqData[2],
      DEM_DTC_KIND_ALL_DTCS,
      DEM_DTC_ORIGIN_PRIMARY_MEMORY,
      DEM_FILTER_WITH_SEVERITY_YES,
      DspInternal_apstreMsgContext[u8Context]->reqData[1],
      DEM_FILTER_FOR_FDC_NO
      );


    Dsp_u32RemainingData = 0;
    /*! Set current status                                                   */
    DspInternal_au8eStatus[u8Context] = DspInternal_u8BLOCKED;
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    Dsp_bDtcPadding = 0;
#endif
    u8ReturnStd = u8SetStatusAvailMask(u8Context);

    if(u8ReturnStd == E_OK)
    {
      /*! Process request and respond (if applicable in current cycle)      */
      vidMainReportDtc(u8Context, udtSetFilterStatus);
      /*! Set current status                                                */
      if (DspInternal_au8eStatus[u8Context] == DspInternal_u8BLOCKED)
      {
        DspInternal_au8eStatus[u8Context] = DspInternal_u8READ_DTC_INFO;
      }
    }
    else
    {
      /* PRQA S 3361 ++ */
      vidRESPOND_NRC(DCM_E_REQUESTOUTOFRANGE);
      /* PRQA S 3361 -- */
    }
  }
  else
  {
    /* PRQA S 3361 ++ */
    vidRESPOND_NRC(DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    /* PRQA S 3361 -- */
  }
}


/******************************************************************************/
/*! \Description Sub-Function 0x04: reportDTCSnapshotRecordByDTCNumber      \n*/
/******************************************************************************/
static FUNC(void,DCM_CODE) vidSubSnapshotRecByDtc(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  Std_ReturnType u8StdReturn;
  /*! If request message length equals 5 */
  if (DspInternal_apstreMsgContext[u8Context]->reqDataLen == 5)
  {
    Dsp_u32RemainingData = 0;

    /*! Set current status                                                   */
    DspInternal_au8eStatus[u8Context] = DspInternal_u8BLOCKED;


    /*! Disable DTC record Update */
    u8StdReturn = Dem_DisableDTCRecordUpdate();
    if(u8StdReturn == E_OK)
    {
      vidMainSnapshotRecordByDTC(u8Context);
      /*! Set current status                                                   */
      if (DspInternal_au8eStatus[u8Context] == DspInternal_u8BLOCKED)
      {
        DspInternal_au8eStatus[u8Context] = DspInternal_u8READ_DTC_INFO;
      }
    }
    else
    {

      /*! Send NRC 0x31 */
      /* PRQA S 3361 ++ */
      vidRESPOND_NRC(DCM_E_REQUESTOUTOFRANGE);
      /* PRQA S 3361 -- */
    }

  }
  /*! ELSE: Request length is Incorrect */
  else
  {
    /*! Send 0x13 negative response */
    /* PRQA S 3361 ++ */
    vidRESPOND_NRC(DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    /* PRQA S 3361 -- */
  }
}


/******************************************************************************
    \Description Sub-Function 0x06,0x10:
                 reportDTCExtendedDataRecordByDTCNumber
                 reportMirrorMemoryDTCExtendedDataRecordByDTCNumber   \n
    \Trace_To    CDD-0013(0),CDD-0014(0)
******************************************************************************/
static FUNC(void,DCM_CODE) vidSubExtendDataRecordByDTCNum(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  Std_ReturnType u8StdReturn;
  /*! If request message length equals 5 */
  if (DspInternal_apstreMsgContext[u8Context]->reqDataLen == 5)
  {
    Dsp_u32RemainingData = 0;

    /*! Set current status                                                   */
    DspInternal_au8eStatus[u8Context] = DspInternal_u8BLOCKED;


    /*! Disable DTC record Update */
    u8StdReturn = Dem_DisableDTCRecordUpdate();
    if(u8StdReturn == E_OK)
    {
      vidMainExtendDataRecByDtc(u8Context);
      /*! Set current status                                                 */
      if (DspInternal_au8eStatus[u8Context] == DspInternal_u8BLOCKED)
      {
        DspInternal_au8eStatus[u8Context] = DspInternal_u8READ_DTC_INFO;
      }
    }
    else
    {
      /*! Send NRC 0x31 */
      /* PRQA S 3361 ++ */
      vidRESPOND_NRC(DCM_E_REQUESTOUTOFRANGE);
      /* PRQA S 3361 -- */
    }

  }
  /*! ELSE: Request length is Incorrect */
  else
  {
    /*! Send 0x13 negative response */
    /* PRQA S 3361 ++ */
    vidRESPOND_NRC(DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    /* PRQA S 3361 -- */
  }
}

/* Deviation: the function has high cyclomatic complexity as it depends   \n
              on several parameters, and it will not be readable in case  \n
              we splitted into several functions                          \n */
/* PRQA S 4700 ++ */
/******************************************************************************
    \Description Sub-Function 0x05: reportDTCSnapshotRecordByRecordNumber   \n
    \Trace_To CDD-1001(0),CDD-1002(0),CDD-1003(0),CDD-1004(0),CDD-1006(0),
              CDD-1007(0),CDD-0012(0)
******************************************************************************/
static FUNC(void,DCM_CODE) vidSubSnapshotRecByRecNum(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  Std_ReturnType                            u8StdReturn;
  Dem_ReturnGetFreezeFrameDataByRecordType  u8RetGetFreezeFrame;
  uint32                                    u32Dtc;
  uint16                                    u16BufSize;
  uint8                                     u8NegRespCode = 0;
  Dem_ReturnGetStatusOfDTCType              u8DtcStatusReturn;
  uint8                                     u8DtcStatus;


  /*! If request message length equals 2 */
  if (DspInternal_apstreMsgContext[u8Context]->reqDataLen == 2)
  {
    /*! Check that the requested record number equals zero */
    if(DspInternal_apstreMsgContext[u8Context]->reqData[1] == 0)
    {
      /*! Disable DTC record Update */
      u8StdReturn = Dem_DisableDTCRecordUpdate();
      if(u8StdReturn == E_OK)
      {
        u8RetGetFreezeFrame = Dem_GetFreezeFrameDataByRecord(
            0,
            DEM_DTC_ORIGIN_PRIMARY_MEMORY,
            DEM_DTC_KIND_ALL_DTCS,
            &u32Dtc,
            &DspInternal_apstreMsgContext[u8Context]->resData[6],
            &u16BufSize);
        if(u8RetGetFreezeFrame == DEM_GET_FFBYRECORD_OK)
        {
          /*! get DTC status                                                  */
          u8DtcStatusReturn =Dem_GetStatusOfDTC(u32Dtc,
              DEM_DTC_KIND_ALL_DTCS,
              DEM_DTC_ORIGIN_PRIMARY_MEMORY,
              &u8DtcStatus);
          /*! IF get DTC status returned OK                                   */
          if (u8DtcStatusReturn == DEM_STATUS_OK)
          {
            /*! Save DTC in response buffer                                   */
            DspInternal_apstreMsgContext[u8Context]->resData[1] = 0;
            DspInternal_apstreMsgContext[u8Context]->resData[2] =
                (uint8)((u32Dtc & 0x00FF0000UL) >> 16U);
            DspInternal_apstreMsgContext[u8Context]->resData[3] =
                (uint8)((u32Dtc & 0x0000FF00UL) >> 8U);
            DspInternal_apstreMsgContext[u8Context]->resData[4] =
                (uint8)(u32Dtc & 0x000000FFUL);
            /*! Set statusOfDTC parameter in the response buffer */
            DspInternal_apstreMsgContext[u8Context]->resData[5] = u8DtcStatus;
            /*! Set the response length */
            DspInternal_apstreMsgContext[u8Context]->resDataLen = (uint32)6 +
                (uint32)u16BufSize;


          }  
          /*! Else */
          else
          {
            /*! set the negative response code to 0x31 */
            u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;
          }

        }
        else if(u8RetGetFreezeFrame == DEM_GET_FFBYRECORD_NO_DTC_FOR_RECORD)
        {
          DspInternal_apstreMsgContext[u8Context]->resData[1] = 0;
          DspInternal_apstreMsgContext[u8Context]->resDataLen = 2;
        }
        else
        {
          u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;
        }
      }
      else
      {
        /*! Send 0x31 negative response */
        u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;

      }
    }
    else
    {
      /*! Send 0x31 negative response */
      u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;
    }

  }
  /*! ELSE: Request length is Incorrect */
  else
  {
    /*! Send 0x13 negative response */
    u8NegRespCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

  }

  if(u8NegRespCode != 0)
  {
    /*! Send 0x13 negative response */
    /* PRQA S 3361 ++ */
    vidRESPOND_NRC(u8NegRespCode);
    /* PRQA S 3361 -- */
  }
  else
  {
    /* PRQA S 3361 ++ */
    vidRESPOND_OK();
    /* PRQA S 3361 -- */

  }
}

/* PRQA S 4700 -- */

/******************************************************************************/
/*! \Description Sub-Function 0x03: reportDTCSnapshotRecordByIdentification \n*/
/******************************************************************************/
static FUNC(void,DCM_CODE) vidSubSnapshotRecByIndent(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{

  /*! If request message length equals 1 */
  if (DspInternal_apstreMsgContext[u8Context]->reqDataLen == 1)
  {
    Dsp_u32RemainingData = 0;
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    Dsp_bDtcPadding = FALSE;
#endif
    /*! Set current status                                                */
    DspInternal_au8eStatus[u8Context] = DspInternal_u8BLOCKED;
    /*! Process request and respond (if applicable in current cycle)      */
    vidMainReportDtc(u8Context,DEM_FILTER_ACCEPTED);
    /*! Set current status                                                */
    if (DspInternal_au8eStatus[u8Context] == DspInternal_u8BLOCKED)
    {
      DspInternal_au8eStatus[u8Context] = DspInternal_u8READ_DTC_INFO;
    }

  }
  /*! ELSE: Request length is Incorrect */
  else
  {
    /*! Send conditions not correct negative response */
    /* PRQA S 3361 ++ */
    vidRESPOND_NRC(DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    /* PRQA S 3361 -- */
  }
}


/* Deviation: the function has high cyclomatic complexity as it depends   \n
              on several parameters, and it will not be readable in case  \n
              we splitted into several functions                          \n */
/* PRQA S 4700 ++ */
/******************************************************************************
    \Description Sub-Function 0x09: reportSeverityInformationOfDTC         \n
    \Trace_To CDD-0982(0),CDD-0016(0)
******************************************************************************/
static FUNC(void,DCM_CODE) vidSubReportSeverityInfo(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  Dem_ReturnGetSeverityOfDTCType       u8GetSeverityReturn;
  Dem_DTCSeverityType                  u8DtcSeverity;
  uint32                               u32Dtc;
  Dem_ReturnGetFunctionalUnitOfDTCType u8GetFuncUnitReturn;
  uint8                                u8DtcFuncUnit;
  uint8                                u8NegResponse = 0;
  Dem_ReturnGetStatusOfDTCType         u8ReturnGetStatus;
  uint8                                u8DTCStatus;
  Std_ReturnType                       u8ReturnStd;

  /*! Check the request length */
  if(DspInternal_apstreMsgContext[u8Context]->reqDataLen == 4)
  {
    /*! Set the status availability mask */
    u8ReturnStd = u8SetStatusAvailMask(u8Context);
    if(u8ReturnStd == E_OK)
    {
      /*! If status availability mask not equal to zero */
      if(DspInternal_apstreMsgContext[u8Context]->resData[u8INDEX_STATUS_MASK] != 0 )
      {
        u32Dtc =
        u32SHIFT_LEFT(
            DspInternal_apstreMsgContext[u8Context]->reqData[u8RDI_DTC_MASK_HIGH], 16) |
        u32SHIFT_LEFT(
            DspInternal_apstreMsgContext[u8Context]->reqData[u8RDI_DTC_MASK_MED], 8) |
            (uint32)DspInternal_apstreMsgContext[u8Context]->reqData[u8RDI_DTC_MASK_LOW];

        /*! Get Severity of the DTC */
        u8GetSeverityReturn = Dem_GetSeverityOfDTC(u32Dtc,&u8DtcSeverity);

        if(u8GetSeverityReturn == DEM_GET_SEVERITYOFDTC_NOSEVERITY)
        {
          u8GetSeverityReturn = DEM_GET_SEVERITYOFDTC_OK;
          u8DtcSeverity = 0;
        }

        if(u8GetSeverityReturn == DEM_GET_SEVERITYOFDTC_OK)
        {

          /*! Get Functional Unit of DTC */
          u8GetFuncUnitReturn =  Dem_GetFunctionalUnitOfDTC(u32Dtc,
              &u8DtcFuncUnit);

          /*! If get functional unit returns OK */
          if(u8GetFuncUnitReturn == DEM_GET_SEVERITYOFDTC_OK)
          {
            /*! get DTC status                                                */
            u8ReturnGetStatus = Dem_GetStatusOfDTC(u32Dtc,
                                                   DEM_DTC_KIND_ALL_DTCS,
                                                   DEM_DTC_ORIGIN_PRIMARY_MEMORY,
                                                   &u8DTCStatus);
            /*! IF get DTC status returned OK                                 */
            if (u8ReturnGetStatus == DEM_STATUS_OK)
            {
              DspInternal_apstreMsgContext[u8Context]->resData[2] =
                  u8DtcSeverity;
              DspInternal_apstreMsgContext[u8Context]->resData[3] =
                  u8DtcFuncUnit;
              DspInternal_apstreMsgContext[u8Context]->resData[4] =
                  DspInternal_apstreMsgContext[u8Context]->reqData[1];
              DspInternal_apstreMsgContext[u8Context]->resData[5] =
                  DspInternal_apstreMsgContext[u8Context]->reqData[2];
              DspInternal_apstreMsgContext[u8Context]->resData[6] =
                  DspInternal_apstreMsgContext[u8Context]->reqData[3];
              DspInternal_apstreMsgContext[u8Context]->resData[7] = u8DTCStatus;

              DspInternal_apstreMsgContext[u8Context]->resDataLen = 8;

            }  
            /*! ELSE */
            else
            {
              /*! Set Negative response to DCM_E_REQUESTOUTOFRANGE*/
              u8NegResponse = DCM_E_REQUESTOUTOFRANGE;
            }
          }
          /*! Else: Get functional units fails : wrong Dtc kind */
          else
          {
            /*! Set Negative response to DCM_E_REQUESTOUTOFRANGE*/
            u8NegResponse = DCM_E_REQUESTOUTOFRANGE;
          }
        }
        /*! Else : Get Severity Of DTC returns wrong Dtc or wrong Dtc origin*/
        else
        {
          /*! Set Negative response to DCM_E_REQUESTOUTOFRANGE*/
          u8NegResponse = DCM_E_REQUESTOUTOFRANGE;

        }
      }

    }
    else
    {
      /*! Set Negative response to 0x31*/
      u8NegResponse = DCM_E_REQUESTOUTOFRANGE;
    }
  }
  /*! ELSE: Request Length not correct */
  else
  {
    /*! Set Negative response to DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT */
    u8NegResponse = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }

  /*! Negative response code equals zero */
  if(u8NegResponse == 0)
  {
    /* PRQA S 3361 ++ */
    /*! Send positive response */
    vidRESPOND_OK();
    /* PRQA S 3361 -- */
  }
  /*! ELSE */
  else
  {
    /* PRQA S 3361 ++ */
    /*! Send negative response */
    vidRESPOND_NRC(u8NegResponse);
    /* PRQA S 3361 -- */
  }

}



/* Deviation: the function has high cyclomatic complexity as it depends   \n
              on several parameters, and it will not be readable in case  \n
              we splitted into several functions                          \n */
/* PRQA S 4700 ++ */
/******************************************************************************
    \Description Sub-Function 0x06,0x10                                       \n
    \Trace_To CDD-0983(0),CDD-0984(0),CDD-0985(0),CDD-0986(0),CDD-0987(0),
              CDD-0988(0),CDD-0989(0),CDD-0990(0),CDD-0991(0),CDD-0992(0),
              CDD-0993(0)
******************************************************************************/
static FUNC(void,DCM_CODE) vidMainExtendDataRecByDtc(
    VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  /*! \Description  Return value of Dem_GetSizeOfExtendedDataRecordByDTC  */
  Dem_ReturnGetSizeOfExtendedDataRecordByDTCType  udtGetSizeReturn;
  /*! \Description  The DTC mask record                                      */
  uint32                                          u32DTC;
  /*! \Description  Freeze frame data size                                   */
  uint16                                          u16DataRecordsSize;
 
  /*! \Description  DTC Status returned from Dem_GetStatusOfDTC              */
  uint8                                           u8DTCStatus;
  /*! \Description  Return value from Dem_GetStatusOfDTC                     */
  Dem_ReturnGetStatusOfDTCType                    u8ReturnGetStatus;
  uint8                                           u8NegRespcode = 0;

  /*! IF size has not been get yet  */
  if (Dsp_u32RemainingData == 0)
  {
    u32DTC =
        u32SHIFT_LEFT(
            DspInternal_apstreMsgContext[u8Context]->
            reqData[u8RDI_DTC_MASK_HIGH], 16) |
        u32SHIFT_LEFT(
            DspInternal_apstreMsgContext[u8Context]->
            reqData[u8RDI_DTC_MASK_MED], 8) |
       (uint32)DspInternal_apstreMsgContext[u8Context]->
       reqData[u8RDI_DTC_MASK_LOW];
    /*! Get size of extended data record */                                            
    udtGetSizeReturn = Dem_GetSizeOfExtendedDataRecordByDTC(u32DTC,
        DEM_DTC_KIND_ALL_DTCS,
        DEM_DTC_ORIGIN_PRIMARY_MEMORY,
        DspInternal_apstreMsgContext[u8Context]->
        reqData[u8RDI_SNAPSHOT_REC_NUM],
        &u16DataRecordsSize);
    /*! IF returned OK                                                       */
    if (udtGetSizeReturn == DEM_GET_SIZEOFEDRBYDTC_OK)
    {
      /*! Set remaining buffer to maximum                                  */
      Dsp_u32RemainingData = u16DataRecordsSize;
      Dsp_u32ResDataIndex = u8RDI_SSREC_HEAD_SIZE;

      /*! IF All records to be retrieved                                   */
      if (DspInternal_apstreMsgContext[u8Context]->
          reqData[u8RDI_SNAPSHOT_REC_NUM] == 0xFF)
      {

        Dsp_u8CurrentRecord = (uint8)0x01;
        Dsp_u8LastRecord = (uint8)0xEF;
      }
      else if(DspInternal_apstreMsgContext[u8Context]->
          reqData[u8RDI_SNAPSHOT_REC_NUM] == 0xFE)
      {
        Dsp_u8CurrentRecord = (uint8)0x09;
        Dsp_u8LastRecord = (uint8)0xEF;
      }
      /*! ELSE (specific record to be retrieved)                           */
      else
      {
        /*! Set current record and last record to specific record          */
        Dsp_u8CurrentRecord =
            DspInternal_apstreMsgContext[u8Context]->
            reqData[u8RDI_SNAPSHOT_REC_NUM];
        Dsp_u8LastRecord =
            DspInternal_apstreMsgContext[u8Context]->
            reqData[u8RDI_SNAPSHOT_REC_NUM];
      }

      /*! Set DTC parameters in the response*/

      DspInternal_apstreMsgContext[u8Context]->resData[u8RDI_DTC_MASK_HIGH] =
          DspInternal_apstreMsgContext[u8Context]->reqData[u8RDI_DTC_MASK_HIGH];
      DspInternal_apstreMsgContext[u8Context]->resData[u8RDI_DTC_MASK_MED] =
          DspInternal_apstreMsgContext[u8Context]->reqData[u8RDI_DTC_MASK_MED];
      DspInternal_apstreMsgContext[u8Context]->resData[u8RDI_DTC_MASK_LOW] =
          DspInternal_apstreMsgContext[u8Context]->reqData[u8RDI_DTC_MASK_LOW];
      /*! get DTC status                                                   */

      if(DspInternal_au8eSubStatus[u8Context] == (uint8)DspInternal_u8R4_EXT_DATA_BY_DTC)
      {
        u8ReturnGetStatus = Dem_GetStatusOfDTC(u32DTC,
            DEM_DTC_KIND_ALL_DTCS,
            DEM_DTC_ORIGIN_PRIMARY_MEMORY,
            &u8DTCStatus);
      }
      else
      {
        u8ReturnGetStatus = Dem_GetStatusOfDTC(u32DTC,
            DEM_DTC_KIND_ALL_DTCS,
            DEM_DTC_ORIGIN_MIRROR_MEMORY,
            &u8DTCStatus);
      }
      /*! IF get DTC status returned OK                                    */
      if (u8ReturnGetStatus == DEM_STATUS_OK)
      {
        /*! Store DTC status in the response                               */
        DspInternal_apstreMsgContext[u8Context]->
        resData[u8RDI_SSREC_DTC_STATUS] = u8DTCStatus;


        DspInternal_apstreMsgContext[u8Context]->resDataLen =
            u8RDI_SSREC_HEAD_SIZE + u16DataRecordsSize;


        /*! IF size > available buffer                                      */
        if ( DspInternal_apstreMsgContext[u8Context]->resDataLen >
             DspInternal_apstreMsgContext[u8Context]->resMaxDataLen)
        {
#if(DCM_PAGED_BUFFER_ENABLED == STD_OFF)
          /*! NRC14                                                         */

          u8NegRespcode = DCM_E_RESPONSETOOLONG;

#else
          /*! Set PagedMode to TRUE*/
          DspInternal_abePagedMode[u8Context] = TRUE;
          /*! Start paged processing */
          DsdInternal_StartPagedProcessing(
              DspInternal_apstreMsgContext[u8Context]);

#endif
        }
#if(DCM_PAGED_BUFFER_ENABLED == STD_OFF)
        if(u8NegRespcode == 0)
        {
#endif
          /* !Deviation: Alignment not correct due to configurable code */
          /* PRQA S 2215 ++                                             */
          /*! Get freeze frame data                                     */
          vidGetDataRecordByDTC(u8Context);
          /* PRQA S 2215 --                                             */
#if(DCM_PAGED_BUFFER_ENABLED == STD_OFF)
        }
#endif

      }
      /*! ELSE */
      else
      {
        /*! Send NRC 0x31 */
        u8NegRespcode = DCM_E_REQUESTOUTOFRANGE;
      }

    }
    /*! ELSE IF getting size returned PENDING                                */
    else if (udtGetSizeReturn == DEM_GET_SIZEOFEDRBYDTC_PENDING)
    {
      /*! RETURN from function                                               */
    }
    /*! ELSE (getting size returned error)                                   */
    else
    {
      /*! Send NRC 0x31 */
      u8NegRespcode = DCM_E_REQUESTOUTOFRANGE;
    }
  }
  /*! ELSE (size already get)                                                */
  else
  {
    /*! Get Data Record By DTC */
    vidGetDataRecordByDTC(u8Context);
  }

  /*!If negative respond code not equal to zero   */
  if(u8NegRespcode != 0)
  {
    (void)Dem_EnableDTCRecordUpdate();
    /*! Send the negative response */
    /* PRQA S 3361 ++ */
    vidRESPOND_NRC(u8NegRespcode);
    /* PRQA S 3361 -- */
  }

}
/* PRQA S 4700 -- */


/******************************************************************************/
/*! \Description Main function of reportDTCFaultDetectionCounnter(0x14)
    \param[in]    Context number                                              \n
    \Trace_To CDD-1011(0),CDD-1012(0)     \n*/
/******************************************************************************/
static FUNC(void,DCM_CODE) vidMainDtcFaultDetCount(
    VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{

  Dem_ReturnSetFilterType udtSetFilterStatus = DEM_FILTER_ACCEPTED;

  /*! If set DTC filter not called before */
  if(Dsp_bRdtciFirstCall == FALSE)
  {
    Dsp_bRdtciFirstCall = TRUE;

    /*! Set the DTC Dem filter */
    udtSetFilterStatus = Dem_SetDTCFilter(
        0x00,
        DEM_DTC_KIND_ALL_DTCS,
        DEM_DTC_ORIGIN_PRIMARY_MEMORY,
        DEM_FILTER_WITH_SEVERITY_NO,
        DEM_SEVERITY_NO_SEVERITY,
        DEM_FILTER_FOR_FDC_YES);
  }

  vidMainReportDtc(u8Context,udtSetFilterStatus);

}



/* Deviation: the function has high cyclomatic complexity as it depends   \n
              on several parameters, and it will not be readable in case  \n
              we splitted into several functions                          \n */
/* PRQA S 4700 ++ */
/*******************************************************************************
    \Description  Process the report DTC subfunctions of ReadDTCInformation   \n
                  whether from the request or the main function               \n
    \param[in]    Context number                                              \n
    \param[in]    Return value of a call to Dem_SetDTCFilter()                \n
    \Range        DEM_FILTER_ACCEPTED, DEM_WRONG_FILTER                       \n
    \Trace_To     CDD-0974(0), CDD-0977(0), CDD-0018(0),CDD-0980(0),CDD-0981(0),
                  CDD-0994(0) \n\n
 *******************************************************************************/
static FUNC(void,DCM_CODE) vidMainReportDtc(
  VAR(Dcm_IdContextType,AUTOMATIC)       u8Context,
  VAR(Dem_ReturnSetFilterType,AUTOMATIC) udtSetFilterStatus)
{
  /*! \Description  Return value of Dem_GetNumberOfFilteredDTC()              */
  VAR(Dem_ReturnGetNumberOfFilteredDTCType,AUTOMATIC) udtGetNumReturn;
  /*! \Description  Returned number of DTCs to store                          */
  VAR(uint16,AUTOMATIC)                               u16NumberOfDTCs;
  /*! \Description  Remaining DTCs to save in the current call cycle         */
  VAR(uint16,AUTOMATIC)                               u16DtcCount = 0;
  /*! \Description  Return value of Dem_GetNextFilteredDTC                   */
  VAR(Dem_ReturnGetNextFilteredDTCType,AUTOMATIC)     udtNextDtcReturn;
  /*! \Description  DTC returned by Dem_GetNextFilteredDTC                   */
  VAR(uint32,AUTOMATIC)                               u32DTC;
  /*! \Description  DTC Status returned by Dem_GetNextFilteredDTC            */
  VAR(uint8,AUTOMATIC)                                u8DtcStatusOrRec = 0;
  uint8                                               u8NegRespCode = 0;
  Dem_DTCSeverityType                                 u8DtcSeverity = 0;
  uint8                                               u8DtcFuncUnit = 0;
  uint8                                               u8DtcRecLen = (uint8)4;
  Dem_ReturnSetFilterType                             u8RetSetFilter;
  uint16                                              u16Offset = 2;
  sint8                                               s8FaultCount = 0;

  if((DspInternal_au8eSubStatus[u8Context] == (uint8)u8R2_SNAPSHOT_ID) ||
     (DspInternal_au8eSubStatus[u8Context] == (uint8)u8R7_FAULT_DET_COUNTER))
  {
    u16Offset = 1;
  }

  if(DspInternal_au8eSubStatus[u8Context] == (uint8)u8R5_DTC_BY_SEVMASK)
  {
    u8DtcRecLen = (uint8)6;

  }
  /*! IF the filter mask is accepted                                         */
  if (udtSetFilterStatus == DEM_FILTER_ACCEPTED)
  {
    /*! IF Dem_GetNumberOfFilteredDTC is not called yet                      */
    if (Dsp_u32RemainingData == 0)

    {
      if(DspInternal_au8eSubStatus[u8Context] == (uint8)u8R2_SNAPSHOT_ID)
      {
        u8RetSetFilter =  Dem_SetFreezeFrameRecordFilter(&u16NumberOfDTCs);
        if(u8RetSetFilter != DEM_FILTER_ACCEPTED)
        {
          u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;
        }
      }
      else
      {
        udtGetNumReturn = Dem_GetNumberOfFilteredDTC(&u16NumberOfDTCs);
        if(udtGetNumReturn == DEM_NUMBER_OK)
        {
        }
        else if (udtGetNumReturn == DEM_NUMBER_PENDING)
        {
          u16DtcCount = (uint16)1;
          /*! RETURN from function */
        }
        /*! ELSE (including FAILED)*/
        else
        {
          u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;

        }

      }

      /*! IF Get Number of DTC returns OK */
      if ((u16DtcCount == 0) && (u8NegRespCode == 0))
      {
        /*! Set response data Index to 2 */
        Dsp_u32ResDataIndex = u16Offset;

        /*! Set the reponse length                                        */
        DspInternal_apstreMsgContext[u8Context]->resDataLen =
            (uint32)u16Offset +
            ((uint32)u16NumberOfDTCs * (uint32)u8DtcRecLen);



        /*! IF response buffer is not sufficient                             */
        if (DspInternal_apstreMsgContext[u8Context]->resMaxDataLen <
            DspInternal_apstreMsgContext[u8Context]->resDataLen)
        {
          /*! IF paged buffering is used                                     */
          #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)

          DspInternal_abePagedMode[u8Context] = TRUE;
          Dsp_u32RemainingData = u16NumberOfDTCs;

          DsdInternal_StartPagedProcessing(
              DspInternal_apstreMsgContext[u8Context]);
          /*! ELSE (No paged buffering)                                      */
          #else
          #if (DCM_DEV_ERROR_DETECT == STD_ON)
          /*! Report to Det                                                  */
          Det_ReportError (DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
              Dcm_u8UDS_READ_DTC_INFO_ID,
              DCM_E_INTERFACE_BUFFER_OVERFLOW);
          #endif
          /*! NRC14                                                          */
          /* PRQA S 3361 ++ */
          vidRESPOND_NRC(DCM_E_RESPONSETOOLONG);
          /* PRQA S 3361 -- */
          #endif
        }
        /*! else (buffer is enough)                                          */
        else
        {
          Dsp_u32RemainingData = u16NumberOfDTCs;
          /*! IF the number of filtered DTCs equals zero then send the response
           *   without DTCs */

          if(u16NumberOfDTCs == 0)
          {
            /* PRQA S 3361 ++ */
            vidRESPOND_OK();
            /* PRQA S 3361 -- */
          }
        }
      }

    }

    /*! If Dem_GetNumberOfFilteredDTC is called Then */
    if (Dsp_u32RemainingData > 0)
    {
      /*! Load counts per cycle                                              */
      #if (DCM_u16RDTC_DTC_PER_CYC > 0U)
      if (Dsp_u32RemainingData > (uint32)DCM_u16RDTC_DTC_PER_CYC)
      {
        u16DtcCount = DCM_u16RDTC_DTC_PER_CYC;
        Dsp_u32RemainingData -= (uint32)DCM_u16RDTC_DTC_PER_CYC;
      }
      else
      {
        u16DtcCount = (uint16)Dsp_u32RemainingData;
        Dsp_u32RemainingData = 0;
      }
      #else
      u16DtcCount = (uint16)Dsp_u32RemainingData;
      Dsp_u32RemainingData = 0;
      #endif

      /*! Get next DTC (if applicable)                                       */
      while (u16DtcCount > 0)
      {
        /* !Deviation : It is needed when DCM_PAGED_BUFFER_ENABLED is ON */
        /* PRQA S 3198 ++ */
        udtNextDtcReturn = DEM_FILTERED_OK;
        /* PRQA S 3198 -- */

        /* !Deviation : Indentation not correct as it is dependent on the 
                        configuration*/
        /* PRQA S 2215 ++ */
 #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
        /*! IF Dtc Zero Padding is enabled */
        if(Dsp_bDtcPadding == FALSE)
        {
#endif
          if(DspInternal_au8eSubStatus[u8Context] == (uint8)u8R5_DTC_BY_SEVMASK)
          {
            /*! Get Next Filtered DTC. */
            udtNextDtcReturn = Dem_GetNextFilteredDTCAndSeverity(
                &u32DTC,
                &u8DtcStatusOrRec,
                &u8DtcSeverity,
                &u8DtcFuncUnit);
          }
          else if(DspInternal_au8eSubStatus[u8Context] ==
              (uint8)u8R2_SNAPSHOT_ID)
          {
            udtNextDtcReturn = Dem_GetNextFilteredRecord(&u32DTC,
                &u8DtcStatusOrRec);
          }
          else if(DspInternal_au8eSubStatus[u8Context] ==
              (uint8)u8R7_FAULT_DET_COUNTER)
          {
            udtNextDtcReturn = Dem_GetNextFilteredDTCAndFDC(&u32DTC,
                                                            &s8FaultCount);
          }
          else
          {
            /*! Get Next Filtered DTC. */
            udtNextDtcReturn = Dem_GetNextFilteredDTC(&u32DTC,
                &u8DtcStatusOrRec);

          }
          /*! IF Dem_GetNextFilteredDTC returned OK                           */
          if (udtNextDtcReturn == DEM_FILTERED_OK)

          {

            /*! Decrement remainig DTC counter   */
            u16DtcCount--;
          }
          /*! ELSE IF Dem_GetNextFilteredDTC returned PENDING                 */
          else if (udtNextDtcReturn == DEM_FILTERED_PENDING)

          {
            /*! Set the remaining Dtcs to read. */
            Dsp_u32RemainingData += u16DtcCount;
            /*! RETURN from function                                          */
            u16DtcCount = 0;
          }
          /*! ELSE IF Dem_GetNextFilteredDTC returned NO MATCHING DTC         */
          else if (udtNextDtcReturn == DEM_FILTERED_NO_MATCHING_DTC)

          {
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
            /*! If paged mode is active */
            if(DspInternal_abePagedMode[u8Context] == TRUE)
            {
              /*! Set Dtc Padding global variable to TRUE */
              Dsp_bDtcPadding = TRUE;

              /*! Set the DTC and DTCStatus to 0 */
              u32DTC = 0;
              u8DtcStatusOrRec = 0;
              s8FaultCount = 0;
              /* !Deviation: Nesting is needed due to complexity of the function */
              /* PRQA S 0715 ++                                                             */
              if(DspInternal_au8eSubStatus[u8Context] ==
                  (uint8)u8R5_DTC_BY_SEVMASK)
              {
                u8DtcSeverity = 0;
                u8DtcFuncUnit = 0;
              }
              /* PRQA S 0715 --                                                             */
              u16DtcCount--;
            }
            /*! Else : Paged Mode not active */
            else
            {
              /*! Set response data length */
              DspInternal_apstreMsgContext[u8Context]->resDataLen =
                  Dsp_u32ResDataIndex;
              DspInternal_au8eStatus[u8Context] = 0x00;
              DsdInternal_ProcessingDone(
                  DspInternal_apstreMsgContext[u8Context]);

              u16DtcCount = 0;

            }
#else
            /*! Set response data length */
            DspInternal_apstreMsgContext[u8Context]->resDataLen =
                Dsp_u32ResDataIndex;

            /*! Send the response. */
            /* PRQA S 3361 ++ */
            vidRESPOND_OK();
            /* PRQA S 3361 -- */
            /*! RETURN from function                                          */
            u16DtcCount = 0;
#endif
          }
          /*! ELSE (including WRONG DTC Kind)                                 */
          else
          {

#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
            if(DspInternal_abePagedMode[u8Context] == TRUE)
            {

              u32DTC = 0;
              u8DtcStatusOrRec = 0;
              s8FaultCount = 0;
              /* !Deviation: Nesting is needed due to complexity of the function */
              /* PRQA S 0715 ++                                                             */
              if(DspInternal_au8eSubStatus[u8Context] ==
                  (uint8)u8R5_DTC_BY_SEVMASK)
              {
                u8DtcSeverity = 0;
                u8DtcFuncUnit = 0;
              }
              /* PRQA S 0715 --                                                             */

              /*! Decrement remainig counter   */
              u16DtcCount--;
            }
            else
            {
              /*! Report NRC31                                               */
              u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;

              /*! RETURN from function                                       */
              u16DtcCount = 0;
            }
#else
            /*! Report NRC31                                                 */
            u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;
            /*! RETURN from function                                         */
            u16DtcCount = 0;
#endif
          }
 #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
        }
        /* PRQA S 2215 -- */
        /*! DTC Zero Padding enabled */
        else
        {

          /*! Set DTC and DTCStatus to Zero */

          u32DTC = 0;
          u8DtcStatusOrRec = 0;
          s8FaultCount = 0;
          if(DspInternal_au8eSubStatus[u8Context] == (uint8)u8R5_DTC_BY_SEVMASK)
          {
            u8DtcSeverity = 0;
            u8DtcFuncUnit = 0;
          }
          /*! Decrement remainig counter   */
          u16DtcCount--;
        }
#endif

        /*! If Get Next filtered Dtc didn't return DEM_FILTERED_PENDING
         *  and no negative response is sent.
         */
        if((udtNextDtcReturn != DEM_FILTERED_PENDING) &&
           (DspInternal_au8eStatus[u8Context] != DspInternal_u8IDLE) &&
            (u8NegRespCode == 0))
        {
          if(DspInternal_au8eSubStatus[u8Context] == (uint8)u8R5_DTC_BY_SEVMASK)

          {
            /*! Save DTC in response buffer */
            DspInternal_apstreMsgContext[u8Context]->
            resData[Dsp_u32ResDataIndex] = u8DtcSeverity;
            Dsp_u32ResDataIndex++;

            DspInternal_apstreMsgContext[u8Context]->
            resData[Dsp_u32ResDataIndex] = u8DtcFuncUnit;
            Dsp_u32ResDataIndex++;
          }

          DspInternal_apstreMsgContext[u8Context]->
          resData[Dsp_u32ResDataIndex] =
              (uint8)((u32DTC & 0x00FF0000UL) >> 16U);
          Dsp_u32ResDataIndex++;

          DspInternal_apstreMsgContext[u8Context]->
          resData[Dsp_u32ResDataIndex] =
              (uint8)((u32DTC & 0x0000FF00UL) >> 8U);
          Dsp_u32ResDataIndex++;


          DspInternal_apstreMsgContext[u8Context]->
          resData[Dsp_u32ResDataIndex] =
              (uint8)(u32DTC & 0x000000FFUL);
          Dsp_u32ResDataIndex++;
          if(DspInternal_au8eSubStatus[u8Context] ==
              (uint8)u8R7_FAULT_DET_COUNTER)
          {
            DspInternal_apstreMsgContext[u8Context]->
              resData[Dsp_u32ResDataIndex] = (uint8)s8FaultCount;
          }
          else
          {
            DspInternal_apstreMsgContext[u8Context]->
              resData[Dsp_u32ResDataIndex] = u8DtcStatusOrRec;
          }
          Dsp_u32ResDataIndex++;



          #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
          /*! IF Paged Buffer Mode is On */
          if(DspInternal_abePagedMode[u8Context] == TRUE)
          {
            /*! If the buffer is full or no remaining DTCs to Send */
            if(((Dsp_u32ResDataIndex + (uint32)u8DtcRecLen) >
            DspInternal_apstreMsgContext[u8Context]->resMaxDataLen) ||
            ((Dsp_u32RemainingData == 0) && (u16DtcCount == 0)) )
            {
              /*! Set Page update flag to flase */
              DspInternal_abePageUpdate[u8Context] = FALSE;

              /*! Set the remaining Dtcs to read */
              Dsp_u32RemainingData += u16DtcCount;

              /*! Exit from the loop */
              u16DtcCount = 0;

              /*! Process Page */
              DsdInternal_ProcessPage(u8Context,
                  Dsp_u32ResDataIndex);

              /*! set response data index to zero */
              Dsp_u32ResDataIndex = 0;

              /*! If Remaining Dtcs to read equals zero */
              if(Dsp_u32RemainingData == 0)
              {
                /*! Set Dsp status to Idle */
                DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;

                /*! Set Paged Mode and Page Update to FALSE */
                DspInternal_abePagedMode[u8Context] = FALSE;
                DspInternal_abePageUpdate[u8Context] = FALSE;

              }
            }
          }
          /*! ELSE : Paged Buffer not active. */
          else
          {
            /*! If no remaining DTCs to Send */
            if((Dsp_u32RemainingData == 0) && (u16DtcCount == 0))
            {
              /*! Send response  */
              /* PRQA S 3361 ++ */
              vidRESPOND_OK();
              /* PRQA S 3361 -- */

            }
          }
          #else
          /*! If no remaining DTCs to Send */
          if((Dsp_u32RemainingData == 0) && (u16DtcCount == 0))
          {
            /*! Send response  */
            /* PRQA S 3361 ++ */
            vidRESPOND_OK();
            /* PRQA S 3361 -- */

          }
          #endif
        }
      }
    }
  }
  /*! filter mask is not accepted                                          */
  else
  {
    /*! Report NRC31                                                       */
    u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;
  }

  /*! If Negative response code not equal to zero */
  if(u8NegRespCode != 0)
  {
    /* PRQA S 3361 ++ */
    /*! Send the negative response. */
    vidRESPOND_NRC(u8NegRespCode);
    /* PRQA S 3361 -- */
  }
}
/* PRQA S 4700 -- */


/*******************************************************************************
    \Trace_To     CDD-0973(0), CDD-0974(0), CDD-0009(0), CDD-0018(0),       \n\n
                  CDD-0946(0), CDD-0948(0)                                    \n
    \Description  Report Number of DTC subfunctions of ReadDTCInformation     \n
                  whether from the request or the main function               \n
    \param[in]    Context number                                              \n
    \param[in]    Return value of a call to Dem_SetDTCFilter()                \n
    \Range        DEM_FILTER_ACCEPTED, DEM_WRONG_FILTER                       \n
*******************************************************************************/
static FUNC(void,DCM_CODE) vidMainNumberOfDTCs(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context,
  VAR(Dem_ReturnSetFilterType,AUTOMATIC) udtSetFilterStatus)
{
  /*! \Description  Return value of Dem_GetNumberOfFilteredDTC()             */
  VAR(Dem_ReturnGetNumberOfFilteredDTCType,AUTOMATIC) udtGetNumReturn;
  /*! \Description  Returned number of DTCs to store                         */
  VAR(uint16,AUTOMATIC)                               u16NumberOfDTCs;
  /*! \Description  Output of Dem_GetDTCStatusAvailabilityMask()             */
  VAR(uint8,AUTOMATIC)                                u8StatusAvMask;
  VAR(uint8,AUTOMATIC)                                u8DtcFormatId;
  /*! \Description  Return value of Dem_GetDTCStatusAvailabilityMask()       */
  VAR(Std_ReturnType,AUTOMATIC)                       udtReturnValue;

  /*! IF the filter mask is accepted                                         */
  if (udtSetFilterStatus == DEM_FILTER_ACCEPTED)
  {
    udtGetNumReturn = Dem_GetNumberOfFilteredDTC(&u16NumberOfDTCs);
    /*! IF return value of Dem_GetNumberOfFilteredDTC is OK                  */
    if (udtGetNumReturn == DEM_NUMBER_OK)
    {

      /*! Get status availability mask                                       */
      udtReturnValue = Dem_GetDTCStatusAvailabilityMask(&u8StatusAvMask);
      if (udtReturnValue == E_OK)
      {
        DspInternal_apstreMsgContext[u8Context]->resData[u8INDEX_STATUS_MASK] =
                                                                 u8StatusAvMask;
        /*! Get DTC Format Identifer                                         */
        u8DtcFormatId = Dem_GetTranslationType();
        DspInternal_apstreMsgContext[u8Context]->resData[u8INDEX_DTC_FORMAT_ID] =
                                                                 u8DtcFormatId;
        DspInternal_apstreMsgContext[u8Context]->resData[u8INDEX_DTC_COUNT] =
                           (uint8)((u16NumberOfDTCs & ((uint16)0xFF00)) >> 8U);
        DspInternal_apstreMsgContext[u8Context]->resData[u8INDEX_DTC_COUNT + 1U] =
                                   (uint8)(u16NumberOfDTCs & ((uint16)0x00FF));
        DspInternal_apstreMsgContext[u8Context]->resDataLen =
                                                  (uint32)u8RDI_RNBSM_RESP_LEN;
        /*! Send response                                                    */
        /* PRQA S 3361 ++ */
        vidRESPOND_OK();
        /* PRQA S 3361 -- */
      }
      else
      {

        /*! Report NRC31                                                   */
        /* PRQA S 3361 ++ */
        vidRESPOND_NRC(DCM_E_REQUESTOUTOFRANGE);
        /* PRQA S 3361 -- */
      }
    }
    /*! ELSE IF return value of Dem_GetNumberOfFilteredDTC is PENDING        */
    else if (udtGetNumReturn == DEM_NUMBER_PENDING)
    {
      /*! RETURN from function                                               */
    }
    /*! ELSE (including FAILED)                                              */
    else
    {
      /*! Report NRC22                                                     */
      /* PRQA S 3361 ++ */
      vidRESPOND_NRC(DCM_E_REQUESTOUTOFRANGE);
      /* PRQA S 3361 -- */
    }
  }
  /*! filter mask is not accepted                                            */
  else
  {
    /*! Report NRC31                                                         */
    /* PRQA S 3361 ++ */
    vidRESPOND_NRC(DCM_E_REQUESTOUTOFRANGE);
    /* PRQA S 3361 -- */
  }
}



/* Deviation: the function has high cyclomatic complexity as it depends   \n
              on several parameters, and it will not be readable in case  \n
              we splitted into several functions                          \n */ 
/* PRQA S 4700 ++ */ 
/*******************************************************************************
    \Trace_To     CDD-0995(0), CDD-0996(0), CDD-0997(0), CDD-1000(0),       \n\n
                  CDD-0011(0)                                                 \n
    \Description  Report Snapshot record by DTC subfunction of                \n
                  ReadDTCInformation whether from the request or the main     \n
                  function                                                    \n
    \param[in]    Context number                                              \n
 *******************************************************************************/
static FUNC(void,DCM_CODE) vidMainSnapshotRecordByDTC(
    VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  /*! \Description  Return value of Dem_GetSizeOfFreezeFrameByDTC            */ 
  Dem_ReturnGetSizeOfFreezeFrameByDTCType udtGetSizeReturn;
  /*! \Description  The DTC mask record                                      */ 
  uint32                                  u32DTC;
  /*! \Description  Freeze frame data size                                   */ 
  uint16                                  u16FreezeFrameSize;

  /*! \Description  DTC Status returned from Dem_GetStatusOfDTC              */
  uint8                                   u8DTCStatus;
  /*! \Description  Return value from Dem_GetStatusOfDTC                     */
  Dem_ReturnGetStatusOfDTCType            u8ReturnGetStatus;
  uint8                                   u8NegRespcode = 0;

  /*! IF size has not been get yet  */
  if (Dsp_u32RemainingData == 0)
  {
    u32DTC =
        u32SHIFT_LEFT(
            DspInternal_apstreMsgContext[u8Context]->
            reqData[u8RDI_DTC_MASK_HIGH], 16) |
        u32SHIFT_LEFT(
            DspInternal_apstreMsgContext[u8Context]->
            reqData[u8RDI_DTC_MASK_MED], 8) |
       (uint32)DspInternal_apstreMsgContext[u8Context]->
       reqData[u8RDI_DTC_MASK_LOW];
    /*! Get size for freeze frame                                            */ 
    udtGetSizeReturn = Dem_GetSizeOfFreezeFrameByDTC(u32DTC,
        DEM_DTC_KIND_ALL_DTCS,
        DEM_DTC_ORIGIN_PRIMARY_MEMORY,
        DspInternal_apstreMsgContext[u8Context]->
        reqData[u8RDI_SNAPSHOT_REC_NUM],
        &u16FreezeFrameSize);
    /*! IF returned OK                                                       */ 
    if (udtGetSizeReturn == DEM_GET_SIZEOFFF_OK)
    {
      /*! Set remaining buffer to maximum                                  */
      Dsp_u32RemainingData = u16FreezeFrameSize;
      Dsp_u32ResDataIndex = u8RDI_SSREC_HEAD_SIZE;

      /*! IF All records to be retrieved                                   */
      if (DspInternal_apstreMsgContext[u8Context]->
          reqData[u8RDI_SNAPSHOT_REC_NUM] == 0xFF)
      {
        /*! Set current record to 0 and last record to 0xFE                */
        Dsp_u8CurrentRecord = 0u;
        Dsp_u8LastRecord = 0xFE;
      }
      /*! ELSE (specific record to be retrieved)                           */
      else
      {
        /*! Set current record and last record to specific record          */
        Dsp_u8CurrentRecord =
            DspInternal_apstreMsgContext[u8Context]->
            reqData[u8RDI_SNAPSHOT_REC_NUM];
        Dsp_u8LastRecord =
            DspInternal_apstreMsgContext[u8Context]->
            reqData[u8RDI_SNAPSHOT_REC_NUM];
      }

      /*! Set DTC parameters in the response*/

      DspInternal_apstreMsgContext[u8Context]->resData[u8RDI_DTC_MASK_HIGH] =
          DspInternal_apstreMsgContext[u8Context]->reqData[u8RDI_DTC_MASK_HIGH];
      DspInternal_apstreMsgContext[u8Context]->resData[u8RDI_DTC_MASK_MED] =
          DspInternal_apstreMsgContext[u8Context]->reqData[u8RDI_DTC_MASK_MED];
      DspInternal_apstreMsgContext[u8Context]->resData[u8RDI_DTC_MASK_LOW] =
          DspInternal_apstreMsgContext[u8Context]->reqData[u8RDI_DTC_MASK_LOW];
      /*! get DTC status                                                   */
      u8ReturnGetStatus = Dem_GetStatusOfDTC(u32DTC,
          DEM_DTC_KIND_ALL_DTCS,
          DEM_DTC_ORIGIN_PRIMARY_MEMORY,
          &u8DTCStatus);
      /*! IF get DTC status returned OK                                    */
      if (u8ReturnGetStatus == DEM_STATUS_OK)
      {
        /*! Store DTC status in the response                               */
        DspInternal_apstreMsgContext[u8Context]->resData[u8RDI_SSREC_DTC_STATUS]
                                                        = u8DTCStatus;


        DspInternal_apstreMsgContext[u8Context]->resDataLen =
            u8RDI_SSREC_HEAD_SIZE + u16FreezeFrameSize;


        /*! IF size > available buffer                                      */
        if ( DspInternal_apstreMsgContext[u8Context]->resDataLen >
             DspInternal_apstreMsgContext[u8Context]->resMaxDataLen)
        {
#if(DCM_PAGED_BUFFER_ENABLED == STD_OFF)
          /*! NRC14                                                         */

          u8NegRespcode = DCM_E_RESPONSETOOLONG;

#else
          /*! Set PagedMode to TRUE*/
          DspInternal_abePagedMode[u8Context] = TRUE;
          /*! Start paged processing */
          DsdInternal_StartPagedProcessing(
              DspInternal_apstreMsgContext[u8Context]);

#endif
        }
#if(DCM_PAGED_BUFFER_ENABLED == STD_OFF)
        if(u8NegRespcode == 0)
        {
#endif
          /*! Get freeze frame data                                         */
          vidGetFreezeFrameByDTC(u8Context);
#if(DCM_PAGED_BUFFER_ENABLED == STD_OFF)
        }
#endif

      }
      else
      {
        /*! Send NRC 0x31 */
        u8NegRespcode = DCM_E_REQUESTOUTOFRANGE;
      }

    }
    /*! ELSE IF getting size returned PENDING                                */
    else if (udtGetSizeReturn == DEM_GET_SIZEOFFF_PENDING)
    {
      /*! RETURN from function                                               */
    }
    /*! ELSE (getting size returned error)                                   */
    else
    {
      /*! Send NRC 0x31 */
      u8NegRespcode = DCM_E_REQUESTOUTOFRANGE;
    }
  }
  /*! ELSE (size already get)                                                */
  else
  {
    /*! Get freeze frame data */
    vidGetFreezeFrameByDTC(u8Context);
  }

  /*!If negative respond code not equal to zero   */
  if(u8NegRespcode != 0)
  {
    (void)Dem_EnableDTCRecordUpdate();
    /*! Send the negative response */
    /* PRQA S 3361 ++ */
    vidRESPOND_NRC(u8NegRespcode);
    /* PRQA S 3361 -- */
  }

}
/* PRQA S 4700 -- */

/* Deviation: the function has high cyclomatic complexity as it depends   \n
              on several parameters, and it will not be readable in case  \n
              we splitted into several functions                          \n */ 
/* PRQA S 4700 ++ */ 
/*******************************************************************************
    \Trace_To     CDD-0996(0), CDD-0998(0), CDD-0999(0), CDD-0010(0),       \n\n
                  CDD-0018(0), CDD-0946(0), CDD-0948(0), CDD-0954(0),         \n
                  CDD-0953(0)                                                 \n
    \Description  Get snapshot records by DTC number                          \n
    \param[in]    Context number                                              \n
*******************************************************************************/
static FUNC(void,DCM_CODE) vidGetFreezeFrameByDTC(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  /*! \Description  Return value of Dem_GetFreezeFrameDataByDTC              */ 
  Dem_ReturnGetFreezeFrameDataByDTCType   udtGetFFReturn;
  
  /*! \Description  The DTC mask record                                      */ 
  uint32                                  u32DTC;
  /*! \Description  Freeze frame data size                                   */ 
  uint16                                  u16FreezeFrameSize;
  /*! \Description  Last snapshot records to be read                         */ 
  uint8                                   u8MaxPerCycle;
  /*! \Description  Number of snapshot records to be read                    */ 
  uint8                                   u8Count;
  /*! \Description  Flag to exit the loop                                    */ 
  boolean                                 bExitLoop = FALSE;
  uint8                                   u8NegRespCode = 0;
  Std_ReturnType                          u8ReturnStd;



  u32DTC =
    u32SHIFT_LEFT(
       DspInternal_apstreMsgContext[u8Context]->
       reqData[u8RDI_DTC_MASK_HIGH], 16u) |
    u32SHIFT_LEFT(
       DspInternal_apstreMsgContext[u8Context]->
       reqData[u8RDI_DTC_MASK_MED], 8u) |
    (uint32)DspInternal_apstreMsgContext[u8Context]->
    reqData[u8RDI_DTC_MASK_LOW];


  #if (DCM_u8RDTC_SNAPSHOTS_PER_CYC > 0U)
  if ((uint8)((uint8)(Dsp_u8LastRecord -
       Dsp_u8CurrentRecord) + 1) >
       ((uint8)DCM_u8RDTC_SNAPSHOTS_PER_CYC))
  {
    u8MaxPerCycle = (Dsp_u8CurrentRecord +
       ((uint8)DCM_u8RDTC_SNAPSHOTS_PER_CYC));
  }
  else
  {
    u8MaxPerCycle = (uint8)(Dsp_u8LastRecord + (uint8)1);
  }
  #else
  u8MaxPerCycle = (uint8)(Dsp_u8LastRecord + (uint8)1);
  #endif
  /*! loop on all records to be retrieved    */ 
  for (u8Count = Dsp_u8CurrentRecord;
       ((u8Count < u8MaxPerCycle) && (bExitLoop == FALSE));
       u8Count++)
  {    
    if((DspInternal_apstreMsgContext[u8Context]->resMaxDataLen -
        Dsp_u32ResDataIndex) > (uint32)65535)
    {
      u16FreezeFrameSize = (uint16)65535;
    }
    else
    {
      u16FreezeFrameSize =
        (uint16)(DspInternal_apstreMsgContext[u8Context]->resMaxDataLen -
        Dsp_u32ResDataIndex);
    }

    Dsp_u8CurrentRecord = u8Count;

    
    /*! Get Freeze frame data by Dtc */
    udtGetFFReturn = Dem_GetFreezeFrameDataByDTC(u32DTC,
      DEM_DTC_KIND_ALL_DTCS,
      DEM_DTC_ORIGIN_PRIMARY_MEMORY,
      u8Count,
      &DspInternal_apstreMsgContext[u8Context]->
      resData[Dsp_u32ResDataIndex],
      &u16FreezeFrameSize);

    /*! IF getting freeze frame returned OK                                */
    if (udtGetFFReturn == DEM_GET_FFDATABYDTC_OK)
    {
      Dsp_u32ResDataIndex += u16FreezeFrameSize;
      /*! IF remaining buffer > 0                                        */
      if(Dsp_u32RemainingData >= u16FreezeFrameSize)
      {
        /*! Decrement Remaining buffer by acutal written size             */
        Dsp_u32RemainingData -= u16FreezeFrameSize;

        /*! IF current record equals last record                             */
        if ((u8Count >= Dsp_u8LastRecord) || (Dsp_u32RemainingData == 0))
        {
          bExitLoop = TRUE;
          u8ReturnStd = Dem_EnableDTCRecordUpdate();

          if((u8ReturnStd == E_OK) && (Dsp_u32RemainingData == 0))
          {

            /* PRQA S 3361 ++ */
            vidRESPOND_OK();
            /* PRQA S 3361 -- */
          }
          else
          {
            /* PRQA S 3361 ++ */
            vidRESPOND_NRC(DCM_E_REQUESTOUTOFRANGE);
            /* PRQA S 3361 -- */

          }

        }
        /*! ELSE (more records to read)                                      */
        else
        {
          /*! Do nothing */

        }


      }
      /*! ELSE (remaining buffer is not enough)                          */
      else
      {
        Dsp_u32RemainingData = 0;
        /*! NRC14                                                         */
        u8NegRespCode = DCM_E_RESPONSETOOLONG;

        bExitLoop = TRUE;
      }
     
    }
    /*! ELSE IF getting freeze frame returned PENDING                       */
    else if (udtGetFFReturn == DEM_GET_FFDATABYDTC_PENDING)
    {
      /*! RETURN from function                                              */
      bExitLoop = TRUE;
    }
    /*! ELSE IF getting freeze frame returned WRONG BUFFER SIZE             */
    else if (udtGetFFReturn == DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE)
    {
      bExitLoop = TRUE;
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
      if(DspInternal_abePagedMode[u8Context] == TRUE)
      {
        DspInternal_abePageUpdate[u8Context] = FALSE;
        if(Dsp_u32ResDataIndex != 0)
        {
          DspInternal_abePageUpdate[u8Context] = FALSE;
          DsdInternal_ProcessPage(u8Context,Dsp_u32ResDataIndex);
          Dsp_u32ResDataIndex = 0;
        }
        else
        {
          /*! Set Negative response to 0x14*/
          u8NegRespCode = DCM_E_RESPONSETOOLONG;

        }
      }
      else
      {
        /*! Set Negative response to 0x14*/
        u8NegRespCode = DCM_E_RESPONSETOOLONG;

      }
#else
      /*! Set Negative response to 0x14*/
      u8NegRespCode = DCM_E_RESPONSETOOLONG;

#endif
    }
    /*! ELSE (getting freeze frame returned error)                         */
    else 
    {
      u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;

      /*! RETURN from function                                             */
      bExitLoop = TRUE;
    }

  }
  if (bExitLoop == FALSE)
  {
    Dsp_u8CurrentRecord = u8Count;
  }

  if(u8NegRespCode != 0)
  {
    (void)Dem_EnableDTCRecordUpdate();

    #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    if(DspInternal_abePagedMode[u8Context] == FALSE)
    {
      /* PRQA S 3361 ++ */
      vidRESPOND_NRC(u8NegRespCode);
      /* PRQA S 3361 -- */
    }
    else
    {
      DspInternal_abePagedMode[u8Context] = FALSE;
      DspInternal_abePageUpdate[u8Context] = FALSE;
      DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;

    }
    #else
    /* PRQA S 3361 ++ */
    vidRESPOND_NRC(u8NegRespCode);
    /* PRQA S 3361 -- */
    #endif

  }
}


/* Deviation: the function has high cyclomatic complexity as it depends   \n
              on several parameters, and it will not be readable in case  \n
              we splitted into several functions                          \n */ 
/* PRQA S 4700 ++ */ 
static FUNC(void,DCM_CODE) vidGetDataRecordByDTC(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{

  Dem_ReturnGetExtendedDataRecordByDTCType       udtGetFFReturn;

  /*! \Description  The DTC mask record                                  */
  uint32                                         u32DTC;
  /*! \Description  Data Record size                                     */
  uint16                                         u16DataRecordSize;
  /*! \Description  Last data records to be read                         */
  uint8                                          u8MaxPerCycle;
  /*! \Description  Number of data records to be read                    */
  uint8                                          u8Count;
  /*! \Description  Flag to exit the loop                                */
  boolean                                        bExitLoop = FALSE;
  uint8                                          u8NegRespCode = 0;
  uint8                                          u8StdReturn;



  u32DTC =
    u32SHIFT_LEFT(
       DspInternal_apstreMsgContext[u8Context]->
       reqData[u8RDI_DTC_MASK_HIGH], 16u) |
    u32SHIFT_LEFT(
       DspInternal_apstreMsgContext[u8Context]->
       reqData[u8RDI_DTC_MASK_MED], 8u) |
    (uint32)DspInternal_apstreMsgContext[u8Context]->
    reqData[u8RDI_DTC_MASK_LOW];


  #if (DCM_u8RDTC_SNAPSHOTS_PER_CYC > 0U)
  if ((uint8)((uint8)(Dsp_u8LastRecord -
       Dsp_u8CurrentRecord) + 1) >
       ((uint8)DCM_u8RDTC_SNAPSHOTS_PER_CYC))
  {
    u8MaxPerCycle = (Dsp_u8CurrentRecord +
       ((uint8)DCM_u8RDTC_SNAPSHOTS_PER_CYC));
  }
  else
  {
    u8MaxPerCycle = (uint8)(Dsp_u8LastRecord + (uint8)1);
  }
  #else
  u8MaxPerCycle = (uint8)(Dsp_u8LastRecord + (uint8)1);
  #endif
  /*! loop on all records to be retrieved */
  for (u8Count = Dsp_u8CurrentRecord;
       ((u8Count < u8MaxPerCycle) && (bExitLoop == FALSE));
       u8Count++)
  {

    if((DspInternal_apstreMsgContext[u8Context]->resMaxDataLen -
      Dsp_u32ResDataIndex) > (uint32)65535)
    {
      u16DataRecordSize = (uint16)65535;
    }
    else
    {
      u16DataRecordSize =
        (uint16)(DspInternal_apstreMsgContext[u8Context]->resMaxDataLen -
        Dsp_u32ResDataIndex);
    }


    Dsp_u8CurrentRecord = u8Count;


    if(DspInternal_au8eSubStatus[u8Context] == (uint8)DspInternal_u8R4_EXT_DATA_BY_DTC)
    {
      udtGetFFReturn = Dem_GetExtendedDataRecordByDTC(u32DTC,
        DEM_DTC_KIND_ALL_DTCS,
        DEM_DTC_ORIGIN_PRIMARY_MEMORY,
        u8Count,
        &DspInternal_apstreMsgContext[u8Context]->
        resData[Dsp_u32ResDataIndex],
        &u16DataRecordSize);
    }
    else
    {
      udtGetFFReturn = Dem_GetExtendedDataRecordByDTC(u32DTC,
        DEM_DTC_KIND_ALL_DTCS,
        DEM_DTC_ORIGIN_MIRROR_MEMORY,
        u8Count,
        &DspInternal_apstreMsgContext[u8Context]->
        resData[Dsp_u32ResDataIndex],
        &u16DataRecordSize);

    }

    /*! IF getting freeze frame returned OK                                */
    if (udtGetFFReturn == DEM_RECORD_OK)
    {
      Dsp_u32ResDataIndex += u16DataRecordSize;
      /*! IF remaining buffer > 0                                        */
      if(Dsp_u32RemainingData >= u16DataRecordSize)
      {
        /*! Decrement Remaining buffer by acutal written size             */
        Dsp_u32RemainingData -= u16DataRecordSize;
        /*! IF current record equals last record                             */
        if ((u8Count >= Dsp_u8LastRecord) || (Dsp_u32RemainingData == 0))
        {
          bExitLoop = TRUE;
          u8StdReturn = Dem_EnableDTCRecordUpdate();

          if((u8StdReturn == E_OK) && (Dsp_u32RemainingData == 0))
          {

            /* PRQA S 3361 ++ */
            vidRESPOND_OK();
            /* PRQA S 3361 -- */
          }
          else
          {
            /* PRQA S 3361 ++ */
            vidRESPOND_NRC(DCM_E_REQUESTOUTOFRANGE);
            /* PRQA S 3361 -- */
          }

        }
        /*! ELSE (more records to read)                                      */
        else
        {
          /*! Do Nothing */

        }
      }
      /*! ELSE (remaining buffer is not enough)                          */
      else
      {
        Dsp_u32RemainingData = 0;
        /*! NRC14                                                         */
        u8NegRespCode = DCM_E_RESPONSETOOLONG;

        bExitLoop = TRUE;
      }

    }
    /*! ELSE IF getting data record returned PENDING                       */
    else if (udtGetFFReturn == DEM_RECORD_PENDING)
    {
      /*! RETURN from function                                              */
      bExitLoop = TRUE;
    }
    /*! ELSE IF getting data record returned WRONG BUFFER SIZE             */
    else if (udtGetFFReturn == DEM_RECORD_WRONG_BUFFERSIZE)
    {
      bExitLoop = TRUE;
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
      if(DspInternal_abePagedMode[u8Context] == TRUE)
      {
        DspInternal_abePageUpdate[u8Context] = FALSE;
        if(Dsp_u32ResDataIndex != 0)
        {
          DspInternal_abePageUpdate[u8Context] = FALSE;
          DsdInternal_ProcessPage(u8Context,Dsp_u32ResDataIndex);
          Dsp_u32ResDataIndex = 0;
        }
        else
        {
          u8NegRespCode = DCM_E_RESPONSETOOLONG;

        }
      }
      else
      {
        u8NegRespCode = DCM_E_RESPONSETOOLONG;

      }
#else
      u8NegRespCode = DCM_E_RESPONSETOOLONG;

#endif
    }
    /*! ELSE (getting data record returned error)                         */
    else
    {
      u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;

      /*! RETURN from function                                             */
      bExitLoop = TRUE;
    }

  }
  if (bExitLoop == FALSE)
  {
    Dsp_u8CurrentRecord = u8Count;
  }

  if(u8NegRespCode != 0)
  {
    /*! Enable record update */
    (void)Dem_EnableDTCRecordUpdate();

    #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    /*! If Paged mode if Off */
    if(DspInternal_abePagedMode[u8Context] == FALSE)
    {
      /*! Send the Negative response */
      /* PRQA S 3361 ++ */
      vidRESPOND_NRC(u8NegRespCode);
      /* PRQA S 3361 -- */
    }
    /*! Esle */
    else
    {
      /*! Reset Paged buffer variables and Dsp status */
      DspInternal_abePagedMode[u8Context] = FALSE;
      DspInternal_abePageUpdate[u8Context] = FALSE;
      DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;

    }
    #else
    /*! Send the negative response */
    /* PRQA S 3361 ++ */
    vidRESPOND_NRC(u8NegRespCode);
    /* PRQA S 3361 -- */
    #endif

  }
}
/* PRQA S 4700 -- */ 



/* Deviation: the function has high cyclomatic complexity as it depends   \n
              on several parameters, and it will not be readable in case  \n
              we splitted into several functions                          \n */ 
/* PRQA S 4700 ++ */ 
/******************************************************************************/
/*! \Trace_To     CDD-0972(0), CDD-0974(0), CDD-0977(0)                     \n\n
    \Description  Read Dtc Information Main Function                         \n
    \param[in]    Context number                                              \n
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_vidMainReadDTCInfo(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  /*! If cancel flag is high */
  if(DspInternal_apstreMsgContext[u8Context]->msgAddInfo.cancelOperation == 1)
  {
    /*! Call the Dem cancel operation */
    Dem_DcmCancelOperation();

    if((DspInternal_au8eSubStatus[u8Context] == (uint8)DspInternal_u8R2_SNAPSHOTREC_BYDTC)||
       (DspInternal_au8eSubStatus[u8Context] == (uint8)DspInternal_u8R3_SNAPSHOTREC_BYNUM)||
       (DspInternal_au8eSubStatus[u8Context] == (uint8)DspInternal_u8R4_EXT_DATA_BY_DTC)||
       (DspInternal_au8eSubStatus[u8Context] == (uint8)DspInternal_u8R4_M_EXT_DATA_BY_DTC))
    {
      /*! Enable Dtc record Update */
      (void)Dem_EnableDTCRecordUpdate();
    }

    /*! Set the dsp status to Idle */
    DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    DspInternal_abePageUpdate[u8Context] = FALSE;
    DspInternal_abePagedMode[u8Context] = FALSE;
#endif
    /*! Call processing done */
    DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
  }
  /*! ELSE : Cancel bit low */
  else
  {
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    /*! If Paged buffer mode is OFF OR Paged buffer mode is ON and Paged
     *  Update is requested.
     */
    if((DspInternal_abePagedMode[u8Context] == FALSE) ||
        ((DspInternal_abePagedMode[u8Context] == TRUE) &&
         (DspInternal_abePageUpdate[u8Context] == TRUE)))
    {
#endif
      /*! switch on the subfunction ID  */
      switch (DspInternal_au8eSubStatus[u8Context])
      {
        case u8R1_NUM_DTC_BY_STM:
        case u8R1_NUM_M_DTC_BY_STM:
        case u8R5_NUM_DTC_BY_SEVMSK:
        case u8R1_NUM_OBDDTC_BY_STM:
          /*! Process request and respond (if applicable in current cycle)    */
          vidMainNumberOfDTCs(u8Context, DEM_FILTER_ACCEPTED);
          break;
        case u8R1_DTC_BY_STM:
        case u8R1_M_DTC_BY_STM:
        case u8R1_OBD_DTC_BY_STM:
        case u8R7_SUPPORTED_DTC:
        case u8R7_DTC_WITH_PERM_ST:
        case u8R5_DTC_BY_SEVMASK:
        case u8R2_SNAPSHOT_ID:
          /*! Process request and respond (if applicable in current cycle)    */
          vidMainReportDtc(u8Context, DEM_FILTER_ACCEPTED);
          break;


        case DspInternal_u8R2_SNAPSHOTREC_BYDTC:
          vidMainSnapshotRecordByDTC(u8Context);
          break;
        case DspInternal_u8R4_EXT_DATA_BY_DTC:
          vidMainExtendDataRecByDtc(u8Context);
          break;
        case DspInternal_u8R4_M_EXT_DATA_BY_DTC:
          vidMainExtendDataRecByDtc(u8Context);
          break;

        case u8R6_SEV_INFO_OF_DTC:
          vidSubReportSeverityInfo(u8Context);

          break;
        case u8R7_FAULT_DET_COUNTER:
          vidMainDtcFaultDetCount(u8Context);

          break;
        default:
          break;
      }

#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    }
#endif


  }
}
/* PRQA S 4700 -- */ 


/******************************************************************************/
/*! \Trace_To     CDD-0975(0), CDD-0976(0), CDD-0946(0), CDD-0948(0)        \n\n
    \Description  Respond to ReadDTCInformation with DTCs                     \n
    \param[in]    Context number                                              \n
*******************************************************************************/
static FUNC(Std_ReturnType,DCM_CODE) u8SetStatusAvailMask(
   VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  /*! \Description  Output of Dem_GetDTCStatusAvailabilityMask()             */
  VAR(uint8,AUTOMATIC)           u8StatusAvMask = 0;

  /*! \Description  Return value of Dem_GetDTCStatusAvailabilityMask()       */
  VAR(Std_ReturnType,AUTOMATIC)  udtReturnValue;




  /*! Get status availability mask                                          */
  udtReturnValue = Dem_GetDTCStatusAvailabilityMask(&u8StatusAvMask);
  if (udtReturnValue == E_OK)
  {
    DspInternal_apstreMsgContext[u8Context]->resData[u8INDEX_STATUS_MASK] =
                                                                u8StatusAvMask;
  }

  /*! If status availability mask equals zero */
  if (u8StatusAvMask == 0)
  {
    /*! Set the response data length to 2 */
    DspInternal_apstreMsgContext[u8Context]->resDataLen = 2;
  }

return udtReturnValue;

}



/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/


/* Deviation: the function has high cyclomatic complexity as it depends   \n
              on several parameters, and it will not be readable in case  \n
              we splitted into several functions                          \n */
/* PRQA S 4700 ++ */
/******************************************************************************/
/*! \Trace_To     CDD-0972(0), CDD-0974(0), CDD-0977(0), CDD-0008(0),       \n\n
                  CDD-0017(0)                                                 \n
    \Description  Uds Service ReadDTCInformation                              \n
    \param[in]    Pointer to message context                                  \n
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_ReadDTCInformation(
  P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{
  /*! \Description  Context number                                          */
  VAR(Dcm_IdContextType,AUTOMATIC)       u8Context;


  /*! Save message context                                                  */
  u8Context = pMsgContext->idContext;
  DspInternal_apstreMsgContext[u8Context] = pMsgContext;
  /*! Set current Sub status                                                    */
  DspInternal_au8eSubStatus[u8Context] =
      DspInternal_apstreMsgContext[u8Context]->reqData[u8SUB_FUNCTION];
  DspInternal_apstreMsgContext[u8Context]->resData[u8SUB_FUNCTION] =
      DspInternal_apstreMsgContext[u8Context]->reqData[u8SUB_FUNCTION];
  /*! switch on the subfunction ID  */
  switch (DspInternal_au8eSubStatus[u8Context])
  {
    case u8R1_NUM_DTC_BY_STM:
      vidSubNumOfDtcByStMask(u8Context);
      break;
    case u8R1_DTC_BY_STM:
      vidSubDtcByStMask(u8Context);
      break;
    case u8R1_M_DTC_BY_STM:
      vidSubMirrorDtcByStMask(u8Context);
      break;
    case u8R1_NUM_M_DTC_BY_STM:
      vidSubNumOfMirrorDtcByStMask(u8Context);
      break;
    case u8R1_NUM_OBDDTC_BY_STM:
      vidSubNumOfObdDtcByStMask(u8Context);
      break;
    case u8R1_OBD_DTC_BY_STM:
      vidSubObdDtcByStMask(u8Context);
      break;

    case u8R2_SNAPSHOT_ID:
      vidSubSnapshotRecByIndent(u8Context);
      break;

    case DspInternal_u8R2_SNAPSHOTREC_BYDTC:
      vidSubSnapshotRecByDtc(u8Context);
      break;

    case DspInternal_u8R3_SNAPSHOTREC_BYNUM:
      vidSubSnapshotRecByRecNum(u8Context);
      break;
    case DspInternal_u8R4_EXT_DATA_BY_DTC:
      vidSubExtendDataRecordByDTCNum(u8Context);
      break;
    case DspInternal_u8R4_M_EXT_DATA_BY_DTC:
      vidSubExtendDataRecordByDTCNum(u8Context);
      break;

    case u8R5_NUM_DTC_BY_SEVMSK:
      vidSubNumOfDtcBySevMask(u8Context);
      break;

    case u8R5_DTC_BY_SEVMASK:
      vidSubReportDtcBySevMaskRecord(u8Context);
      break;
    case u8R6_SEV_INFO_OF_DTC:
      vidSubReportSeverityInfo(u8Context);
      break;

    case u8R7_SUPPORTED_DTC:
      vidSubSupportedDtc(u8Context);
      break;

    case u8R7_FIRST_FAIL_DTC:
    case u8R7_FIRST_CONF_DTC:
    case u8R7_RECENT_FAIL_DTC:
    case u8R7_RECENT_CONF_DTC:
      vidSubDtcOccurrenceTime(u8Context);
      break;

    case u8R7_FAULT_DET_COUNTER:
      vidSubReportDtcFaultDetCount(u8Context);
      break;

    case u8R7_DTC_WITH_PERM_ST:
      vidSubDtcWithPermSt(u8Context);
      break;
    default:
      /* PRQA S 3361 ++ */
      vidRESPOND_NRC(DCM_E_SUBFUNCTIONNOTSUPPORTED);
      /* PRQA S 3361 -- */
      break;
  }
}
/* PRQA S 4700 -- */


#endif


/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*              for memory allocation and should be included several times.  */ 
/* PRQA S 5087,0838 L1 */ 
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */ 


/** \} */ /* end of DSP module group */
/** \} */ /* end of DSP Component group */
/*-------------------------------- end of file -------------------------------*/

/* !Deviation : Inhibit MISRA rule [0862]: This is the way MemMap is used     */
/* PRQA S 0862 L1 */

/* PRQA L:L1 */
