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
/* !File            : Dcm_Dsp_Obd.c                                           */
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
/* $Revision::   1.37.1.4 $$Author::   manwar         $$Date::   Jul 19 2012 $*/
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
/* PRQA L:L1                                                                  */
#include "Rte_Dcm.h"
#if (DCM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#if((DCM_bOBD_SERVICES_ENABLED == STD_ON)||(DCM_bRDBI_EN == STD_ON))

/*! \Desription  Increment value for the next data in the response message */
/* \Range  9 */
#define u8OBD_SVC_06_INCREMENT 0x09
/*! \Desription  Max length of PID Data in bytes */
/* \Range  4 */
#define u8SVC01_MAX_DATA_LEN (uint8)4
/*! \Desription  Max length of OBD requests in bytes    */
/* \Range  6 */
#define u8OBD_SVC_MAX_REQ_LEN (uint8)6
/*! \Desription  Position of last bit of each availability response */
/* \Range  5 */
#define u8LAST_BIT_POSITION 32 
/*! \Desription  The increment value for the availability response message */
/* \Range  5 */
#define u16AVAILABLE_INCREMENT (uint16)5 


/* !Deviation : Macros are needed for code readability and maintenance       */ 
/* PRQA S 3459,3453 ++ */ 
/******************************************************************************/
/*! \Description  Checks if the given ID is an availability ID */
#define u8IS_AVAILABILITY_ID(u8ID) \
    ((((u8ID) % 0x20) == 0)? (u8AVAILABILTY_MSG): (u8REQUEST_VALUE_MSG)) 
/******************************************************************************/
/* !Deviation : Paramter is needed to be evaluated more than once       */ 
/* PRQA S 3456 ++ */
/******************************************************************************/
/*! \Description  Checks if a given ID belongs to certain availability range */
#define bIS_BELONGTO_AVID(u8AvID, u8CurrentID) \
    (((((u8CurrentID) - (u8AvID)) < 32) && (((u8CurrentID) - (u8AvID)) > 0))\
    ? (TRUE) : (FALSE))
/******************************************************************************/
/*! \Description  Sets the ID Bit in the availability response */
#define vidSET_AVAILABILITY_BIT(u8Index, u8Def) \
    ((pu8OutBuffer[((u8Index)+1) + (((u8Def)-1) /0x08)])\
    |= (uint8)(0x80 >> (((u8Def)-1) % 0x08)))
/******************************************************************************/
/*! \Description  Set Error ID or Number of IDs  */
#define u8GET_ERROR_OR_NUM(bChoice, u8Num, u8ErrorID)\
  (((bChoice) == TRUE) ? (u8Num) : (u8ErrorID))

/* PRQA S 3456 -- */
/******************************************************************************/
/*! \Description  Gets Test ID of a certain Monitor Test */
#define vidGET_TESTID(u8MIDIndex, u8TIDIndex)\
    Dcm_kstreDspConfig.astrDcmDspTestResultObdmidTid[u8MIDIndex].\
    pku8DcmDspTestResultObdmidTids[u8TIDIndex].u8DcmDspTestResultTestId
/******************************************************************************/
/*! \Description  Gets unit and scale of a certain Monitor Test */
#define vidGET_SCALE_UNIT(u8MIDIndex, u8Index)\
    Dcm_kstreDspConfig.astrDcmDspTestResultObdmidTid[u8MIDIndex].\
    pku8DcmDspTestResultObdmidTids[u8Index].u8DcmDspTestResultObdmidTidUaSid
/******************************************************************************/
/*! \Description  Gets the function pointer of a certain Monitor Test */
#define vidGET_READ_FUNC(u8MIDIndex, u8Index)\
    Dcm_kstreDspConfig.astrDcmDspTestResultObdmidTid[u8MIDIndex].\
    pku8DcmDspTestResultObdmidTids[u8Index].pfGetDTRValue
/*! \Description  Gets the high byte of a certain value */
#define vidSET_HIGH_BYTE(u16value)\
    (uint8)(((u16value) >> 8) & 0x00FF)
/******************************************************************************/
/*! \Description  Gets the low byte of a certain value */
#define vidSET_LOW_BYTE(u16value)\
    (uint8)((u16value) & 0x00FF)
/******************************************************************************/
/*! \Description  Gets service type of PID data */
#define u8GET_SERV_OF_PIDDATA(u8PIDIdx, u8DataIdx) \
    Dcm_kstreDspConfig.astrDcmDspPid[u8PIDIdx].pkstrDcmDspPidData[u8DataIdx].\
    pkstrDcmDspPidService01->u8DcmDspPidDataUsePort
/******************************************************************************/
/*! \Description  Gets supported information byte position of a certain \n
                 PID data */
#define u8GET_SUPPINFO_BYTE(u8PIDIndex, u8Index) \
  ((Dcm_kstreDspConfig.astrDcmDspPid[u8PIDIndex].\
  pkstrDcmDspPidSupportInfo[u8Index].u8DcmDspPidSupportInfoPos)/8)
/******************************************************************************/
/*! \Description  Gets supported information bit position within byte of \n
                 a certain PID data */
#define u8GET_SUPPINFO_BIT(u8PIDIndex, u8InfoIndex) \
(0x80 >> ((Dcm_kstreDspConfig.astrDcmDspPid[u8PIDIndex].\
pkstrDcmDspPidSupportInfo[u8InfoIndex].u8DcmDspPidSupportInfoPos)%8))
/******************************************************************************/
/*! \Description  Gets byte position of a certain PID data */
#define u8GET_PID_DATA_BYTE(u8PIDIndex, u8DataIndex) \
    (Dcm_kstreDspConfig.astrDcmDspPid[u8PIDIndex].\
            pkstrDcmDspPidData[u8DataIndex].u16DcmDspPidDataPos / 8)
/******************************************************************************/
/*! \Description  Gets bit position of a certain PID data */
#define u8GET_PID_DATA_BIT(u8PIDIndex, u8DataIndex) \
((Dcm_kstreDspConfig.astrDcmDspPid[u8PIDIndex].\
            pkstrDcmDspPidData[u8DataIndex].u16DcmDspPidDataPos)%8)
/******************************************************************************/
/*! \Description  Gets size of a certain vehicle Info. Data */
#define u8GET_VEHINFO_DATASIZE(u8InfoIndex,u8Index) \
    Dcm_kstreDspConfig.astrDcmDspVehInfo[u8InfoIndex].\
    pkstrDcmDspVehInfoData[u8Index].u8DcmDspVehInfoDataSize
/******************************************************************************/
/* PRQA S 3459,3453 -- */ 
/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*              for memory allocation and should be included several times.  */ 
/* PRQA S 5087,0838 L1 */ 
#define DCM_START_SEC_VAR_16BIT
#include "MemMap.h"
/* \Description  Variable to indicate the current index in the response \n
                 message        */
static VAR(uint16, DCM_VAR) Dsp_u16ResMsgIndex = 0;
#define DCM_STOP_SEC_VAR_16BIT
#include "MemMap.h"

#define DCM_START_SEC_VAR_8BIT
#include "MemMap.h"
/*! \Description  Variable to indicate the number of valid PIDs        */
static VAR(uint8, DCM_VAR) Dsp_u8NumValidIds = 0;
#define DCM_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/*! Variables */
/* !Deviation : Variables are defined in C files not header files   */
/* PRQA S 3406 L2                                                            */
#if( DCM_u8NUM_OF_PIDS > 0U )
static VAR(uint8, DCM_VAR) Dsp_au8ValidIDs[DCM_u8NUM_OF_PIDS];
#endif
/* PRQA L:L2                                                            */
#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/* PRQA L:L1                                                                */

/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*              for memory allocation and should be included several times.  */ 
/* PRQA S 5087,0838 L1 */ 
#define DCM_START_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */ 
static FUNC(void, DCM_CODE) vidClrResBytes(
  uint32 u32Start, uint32 u32Length, 
  P2VAR(uint8, AUTOMATIC, DCM_APPL_CODE) pu8Buffer);

static FUNC(void, DCM_CODE) vidSetSupportedInfo (
    VAR(uint8,DCM_VAR) u8PIDIndex, 
    P2VAR(uint8, AUTOMATIC, DCM_VAR) pu8Buffer);

static FUNC(void, DCM_CODE) vidReadTid(
  uint8 u8MidIndex, 
  uint8 u8TidIndex,
  P2VAR(uint8, AUTOMATIC, DCM_VAR) pu8Buffer,
  P2VAR(uint16, AUTOMATIC, DCM_VAR) pu16Index);

static FUNC(void, DCM_CODE) vidInsertAvIDs(
    sint8 s8PrevIdx, uint8 u8CurrentIdx, uint8 u8ServiceID,
    P2CONST(uint8,AUTOMATIC,DCM_VAR) pku8InBuffer,
    P2VAR(uint8,AUTOMATIC,DCM_VAR) pu8OutBuffer);

static FUNC(uint8, DCM_CODE) u8GetErrorORNumID(uint8 u8ServiceID, boolean bChoice);

static FUNC(uint8, DCM_CODE) u8SetIDValue(uint8 u8ServiceID,uint8 u8SupID);

static FUNC (uint16, DCM_CODE) u16CalcTotalLength (uint16 u16PidDataLen);
/******************************************************************************/
/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*              for memory allocation and should be included several times.  */ 
/* PRQA S 5087,0838 L1 */ 
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */
#endif


#if (DCM_bOBD_SERVICES_ENABLED == STD_ON)

/*! Type Definations */
typedef uint8 tu8MsgType;
#define u8AVAILABILTY_MSG 0x01
#define u8REQUEST_VALUE_MSG 0x02


/******************************************************************************/
/**************************MACROS**********************************************/
/******************************************************************************/
/* !Deviation : Macros are needed for code readability and maintenance       */ 
/* PRQA S 3459,3453 ++ */ 
#if ((DCM_bOBD_SVC03_ENABLED == STD_ON)\
    ||(DCM_bOBD_SVC07_ENABLED == STD_ON)\
    ||(DCM_bOBD_SVC0A_ENABLED == STD_ON)\
    ||(DCM_bOBD_SVC02_ENABLED == STD_ON))
/******************************************************************************/
/*! \Description  Gets DTC High Byte */
#define vidGET_DTC_HIGH_BYTE(u32DTC)\
    (((u32DTC) >> 16) & 0x000000FF)
/*! \Description  Gets DTC Low Byte */
#define vidGET_DTC_LOW_BYTE(u32DTC)\
    (((u32DTC) >> 8) & 0x000000FF)
#endif
/******************************************************************************/

#if (DCM_bOBD_SVC06_ENABLED == STD_ON)
/*! \Description  Calculates Response length of service 0x06 */
#define u16CALC_SVC06_RES_LEN(u8Index)\
  (uint16)(Dcm_kstreDspConfig.astrDcmDspTestResultObdmidTid[(u8Index)].u8NumOfTids\
    *(u8OBD_SVC_06_INCREMENT))
#endif
/* PRQA S 3459,3453 -- */ 
/******************************************************************************/
/*********************************DEFINES**************************************/
/******************************************************************************/
/******************************************************************************/
#if (DCM_bOBD_SVC01_ENABLED == STD_ON)
/*! \Desription  State when Service 01 is pending */
/*! \Range  1 */
#define u8OBD_SVC_01_PENDING 0x01

#endif
/******************************************************************************/
#if (DCM_bOBD_SVC02_ENABLED == STD_ON)
/*! \Desription  Default value for the OBD Freeze Frame */
/*! \Range  0 */
#define u8DEFAULT_FREEZE_FRAME (uint8)0
/*! \Desription  Value to indicate ignoring a PID in response */
/*! \Range  0xFE */
#define u8IGNORE_PID (uint8)0xFE
#endif
/******************************************************************************/
#if ((DCM_bOBD_SVC03_ENABLED == STD_ON)\
    ||(DCM_bOBD_SVC07_ENABLED == STD_ON)\
    ||(DCM_bOBD_SVC0A_ENABLED == STD_ON))
/*! \Desription  State when Services 03, 07 or 0A is pending */
/*! \Range  3 */
#define u8OBD_SVC_DTC_PENDING 0x03
#if (DCM_PAGED_BUFFER_ENABLED == STD_ON)
/*! \Desription  State when page processing is started for Services \n
                03, 07 or 0A              */
/*! \Range  7 */
#define u8SVC_DTC_PAGE_PENDING 0x07
#endif
#endif
/******************************************************************************/
#if (DCM_bOBD_SVC04_ENABLED == STD_ON)
/*! \Desription  DTC value that coresponds to all DTCs */
/*! \Range  0 */
#define u32DEFAULT_DTC (uint32)0x0000
/*! \Desription  State when Service 04 is pending */
/*! \Range  4 */
#define u8OBD_SVC_04_PENDING (uint8)0x04
/*! \Desription  Response length of Service 04 */
/*! \Range  0 */
#define u32OBD_SVC04_RES_LENGTH (Dcm_MsgLenType)0
#endif

#if ((DCM_bOBD_SVC06_ENABLED == STD_ON) && (DCM_PAGED_BUFFER_ENABLED == STD_ON))
/*! \Desription  State when Service 06 is pending */
/*! \Range  6 */
#define u8SVC06_PAGE_PENDING (uint8)0x06
#endif
/******************************************************************************/
#if(DCM_bOBD_SVC08_ENABLED == STD_ON)
/*! \Desription  State when Service 09 is pending */
/*! \Range  1 */
#define u8DEFAULT_RC_TID 0x01
#endif 
/******************************************************************************/
#if(DCM_bOBD_SVC09_ENABLED == STD_ON)
/*! \Desription  State when Service 09 is pending */
/*! \Range  9 */
#define u8OBD_SVC_09_PENDING 0x09
/*! \Desription  State when Service 09 is paused due to Paged-Buffer */
/*! \Range  0x0A */
#define u8SVC09_PAGE_PENDING 0x0A
#endif

/******************************************************************************/
/**************************STATIC VARIABLES************************************/
/******************************************************************************/


/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*              for memory allocation and should be included several times.  */ 
/* PRQA S 5087,0838 L1 */ 
#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
#if(DCM_bOBD_SVC01_ENABLED == STD_ON)
/*! \Description  Variable to indicate if the PID processed before */
static VAR(boolean, DCM_VAR) Dsp_abPIDFirstProcessed[u8OBD_SVC_MAX_REQ_LEN] = 
{
  FALSE, FALSE, FALSE, FALSE, FALSE, FALSE
};
#endif
#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_VAR_8BIT
#include "MemMap.h"

#if(DCM_bOBD_SVC01_ENABLED == STD_ON)
/*! \Description  Variable to indicate the current request index for service 01*/
static VAR(uint8, DCM_VAR) Dsp_u8CurReqIndex = 0;
#endif

/*! \Description  Variable to indicate the current ID           */
static VAR(uint8, DCM_VAR) Dsp_u8CurIdIndex = 0;
/*! \Description  Variable to indicate the current data        */
static VAR(uint8, DCM_VAR) Dsp_u8CurDataIndex = 0;

#define DCM_STOP_SEC_VAR_8BIT
#include "MemMap.h"
/* PRQA L:L1                                                                 */

/******************************************************************************/
/**************************STATIC FUNCTIONS************************************/
/******************************************************************************/
/******************************************************************************/
/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*              for memory allocation and should be included several times.  */ 
/* PRQA S 5087,0838 L1 */ 
#define DCM_START_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */
#if ((DCM_bOBD_SVC01_ENABLED == STD_ON)\
    || (DCM_bOBD_SVC02_ENABLED == STD_ON)\
    || (DCM_bOBD_SVC06_ENABLED == STD_ON)\
    || (DCM_bOBD_SVC08_ENABLED == STD_ON)\
    || (DCM_bOBD_SVC09_ENABLED == STD_ON))

static FUNC(boolean, DCM_CODE) bIsValidFormat(
  P2CONST(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext);

static FUNC(boolean, DCM_CODE) bCheckValidReqMsg(
    P2CONST(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext,
    P2VAR(tu8MsgType, AUTOMATIC, DCM_VAR) pudtMsgType,
    uint8 u8ServiceID);

static FUNC(void, DCM_CODE) vidSetResponse(
  uint16 u16CheckValue,
  P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext);

static FUNC(void, DCM_CODE) vidClrGlobalVars(void);

#endif

#if((DCM_bOBD_SVC01_ENABLED == STD_ON)\
    || (DCM_bOBD_SVC02_ENABLED == STD_ON))

static FUNC(void, DCM_CODE) vidGetValidIDs(
    uint8 u8ServiceID);

static FUNC(void, DCM_CODE) vidClearValidPIDs(void);
#endif

#if(DCM_bOBD_SVC01_ENABLED == STD_ON)
static FUNC(uint8, DCM_CODE) u8FillResponse(
  uint8 u8CurrentIdx,
  uint8 u8Context,
  P2VAR(Std_ReturnType,AUTOMATIC,DCM_VAR) pudtReadDataReturn);

static FUNC(void, DCM_CODE) vidClrServ01Data(void);

static FUNC(void,DCM_CODE) vidMainOBDService01 (uint8 u8Context);
#endif
/******************************************************************************/
#if(DCM_bOBD_SVC09_ENABLED == STD_ON)
static FUNC(void,DCM_CODE) vidMainOBDService09 (uint8 u8Context);
static FUNC(uint16, DCM_CODE) u16CalcResLength09 (void);
#endif
/******************************************************************************/
#if ((DCM_bOBD_SVC03_ENABLED == STD_ON)\
    ||(DCM_bOBD_SVC07_ENABLED == STD_ON)\
    ||(DCM_bOBD_SVC0A_ENABLED == STD_ON))

static FUNC(void, DCM_CODE) vidObtainDTCSVCs(
    uint8 u8ServiceID,
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext);

static FUNC(void, DCM_CODE) vidFillDTCs(
    uint8 u8Context, uint16 u16NoOfDTCs);

static FUNC(void,DCM_CODE) vidMainOBDSVCObtainDTC (uint8 u8Context);

#endif


#if (DCM_PAGED_BUFFER_ENABLED == STD_ON)
static FUNC(void, DCM_CODE) vidInitPageProcess(
  uint8 u8Context, uint16 u16ResLength, uint8 u8ServiceId);

#if ((DCM_bOBD_SVC03_ENABLED == STD_ON)\
    ||(DCM_bOBD_SVC07_ENABLED == STD_ON)\
    ||(DCM_bOBD_SVC0A_ENABLED == STD_ON))
static FUNC(void, DCM_CODE) vidProcessPageDTCs(uint8 u8Context);
static FUNC(void, DCM_CODE) vidSetLoopLimits(
  uint32 u32Index, uint8 u8Context,
  P2VAR(uint32, AUTOMATIC, DCM_VAR) pu32StartIdx,
  P2VAR(uint32, AUTOMATIC, DCM_VAR) pu32EndIdx);
#endif

#if (DCM_bOBD_SVC06_ENABLED == STD_ON)
static FUNC(void,DCM_CODE) vidMainOBDService06 (uint8 u8Context);
#endif

#if (DCM_bOBD_SVC09_ENABLED == STD_ON)
static FUNC(void,DCM_CODE) vidProcessPage09 (uint8 u8Context);
#endif

#endif
/******************************************************************************/
#if (DCM_bOBD_SVC02_ENABLED == STD_ON)
static FUNC(uint8, DCM_CODE) u8SetResSVC02(
    uint8 u8PIDIndex,
    uint8 u8CurrentReqIdx,
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext);

static FUNC(uint8, DCM_CODE) u8ReadDataOfFF(
    uint8 u8PIDIndex,
    P2CONST(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext);
#endif
/*******************************************************************************/

#if (DCM_bOBD_SVC04_ENABLED == STD_ON)
static FUNC(void,DCM_CODE) vidMainOBDService04 (uint8 u8Context);
#endif
/*******************************************************************************/
/************************FUNCTION DEFINATIONS***********************************/
/*******************************************************************************/

#if (DCM_PAGED_BUFFER_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Initializes the Paged-Buffer Process \n
    \param[in]   u8Context   Current Context
    \Range       0..(DspInternal_u8MAX_NUM_INTERNAL_REQ-1)
    \param[in]   u16ResLength   Length of the response message
    \Range       0..65535
    \param[in]   u8ServiceId   Service ID
    \Range       0x01..0x0A
    \return      void.
*******************************************************************************/
static FUNC(void, DCM_CODE) vidInitPageProcess(
  uint8 u8Context, uint16 u16ResLength, uint8 u8ServiceId)
{
  /*! Switch (Service ID) */
  switch (u8ServiceId)
  {
#if ((DCM_bOBD_SVC03_ENABLED == STD_ON)\
    ||(DCM_bOBD_SVC07_ENABLED == STD_ON)\
    ||(DCM_bOBD_SVC0A_ENABLED == STD_ON))
  /*! Case 0x03 (For services 0x03, 0x07 and 0x0A) */
  case 0x03:
    /*! Set response length to 2*u16ResLength + 1 */
    DspInternal_apstreMsgContext[u8Context]->resDataLen = (2*u16ResLength) + 1;
    /*! Set the first byte in response to no. of DTCs */
    DspInternal_apstreMsgContext[u8Context]->resData[0] = (uint8)u16ResLength;
    /*! Set Status to u8SVC_DTC_PAGE_PENDING  */
    DspInternal_au8eStatus[u8Context] = u8SVC_DTC_PAGE_PENDING;
    break;
#endif
  /*! Case 0x06 (Service 0x06) */
#if(DCM_bOBD_SVC06_ENABLED == STD_ON)
  case 0x06:
    /*! Set response length to u16ResLength */
    DspInternal_apstreMsgContext[u8Context]->resDataLen = u16ResLength;
    /*! Set Status to u8SVC06_PAGE_PENDING  */
    DspInternal_au8eStatus[u8Context] = u8SVC06_PAGE_PENDING;
    break;
#endif  
#if(DCM_bOBD_SVC09_ENABLED == STD_ON)
  case 0x09:
    /*! Set response length to u16ResLength */
    DspInternal_apstreMsgContext[u8Context]->resDataLen = u16ResLength;
    /*! Set Status to u8SVC09_PAGE_PENDING  */
    DspInternal_au8eStatus[u8Context] = u8SVC09_PAGE_PENDING;
    break;
#endif
  default:
    break;
  }
  /*! Call DsdInternal_StartPagedProcessing    */
  DsdInternal_StartPagedProcessing
      (DspInternal_apstreMsgContext[u8Context]);
}
#endif
/******************************************************************************/
/*! \Description Main Function for OBD services. \n
    \param[in]   u8IdContext
    \Range       0..(DspInternal_u8MAX_NUM_INTERNAL_REQ-1)
    \return      void. \n
    \Trace_To    CDD-DSP-0051(0), CDD-DSP-0055(0)}
*******************************************************************************/
FUNC(void, DCM_CODE) DspInternal_OBDMain(uint8 u8IdContext)
{
  /*! Switch on the current status */
  switch(DspInternal_au8eStatus[u8IdContext])
  {
#if (DCM_bOBD_SVC01_ENABLED == STD_ON)
    /*! Case u8OBD_SVC_01_PENDING, call vidMainOBDService01 */
  case u8OBD_SVC_01_PENDING:
    vidMainOBDService01(u8IdContext);
    break;
#endif
#if ((DCM_bOBD_SVC03_ENABLED == STD_ON)\
 || (DCM_bOBD_SVC07_ENABLED == STD_ON)\
 || (DCM_bOBD_SVC0A_ENABLED == STD_ON))
    /*! Case u8OBD_SVC_DTC_PENDING, call vidMainOBDSVCObtainDTC */
  case u8OBD_SVC_DTC_PENDING:
    vidMainOBDSVCObtainDTC(u8IdContext);
    break;
#endif

#if (DCM_PAGED_BUFFER_ENABLED == STD_ON)
#if ((DCM_bOBD_SVC03_ENABLED == STD_ON)\
 || (DCM_bOBD_SVC07_ENABLED == STD_ON)\
 || (DCM_bOBD_SVC0A_ENABLED == STD_ON))
  case u8SVC_DTC_PAGE_PENDING:
    /*! Call vidProcessPageDTCs */
    vidProcessPageDTCs(u8IdContext);
    break;
#endif
#if (DCM_bOBD_SVC06_ENABLED == STD_ON)
  case u8SVC06_PAGE_PENDING:
    vidMainOBDService06(u8IdContext);
    break;
#endif
#if (DCM_bOBD_SVC09_ENABLED == STD_ON)
  case u8SVC09_PAGE_PENDING:
    vidProcessPage09(u8IdContext);
    break;
#endif
#endif
#if (DCM_bOBD_SVC04_ENABLED == STD_ON)
    /*! Case u8OBD_SVC_04_PENDING, call vidMainOBDService04 */
  case u8OBD_SVC_04_PENDING:
    vidMainOBDService04(u8IdContext);
    break;
#endif
#if (DCM_bOBD_SVC09_ENABLED == STD_ON)
    /*! Case u8OBD_SVC_09_PENDING, call vidMainOBDService09 */
  case u8OBD_SVC_09_PENDING:
    vidMainOBDService09(u8IdContext);
    break;
#endif
  default:
    break;
  }
}

#if ((DCM_bOBD_SVC01_ENABLED == STD_ON)\
    || (DCM_bOBD_SVC02_ENABLED == STD_ON)\
    || (DCM_bOBD_SVC06_ENABLED == STD_ON)\
    || (DCM_bOBD_SVC08_ENABLED == STD_ON)\
    || (DCM_bOBD_SVC09_ENABLED == STD_ON))
/*******************************************************************************/
/*! \Description Checks the validity of the request message.\n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \param[in] u8ServiceID   Service ID. \n
    \Range       0x01, 0x02, 0x06, 0x09  \n
    \param[out] pudtMsgType  indicates the type of the request message \n
    \Range u8AVAILABILTY_MSG, u8REQUEST_VALUE_MSG \n
    \return      boolean. 
    \Trace_To    CDD-0301(0), CDD-0305(0), CDD-0306(0), CDD-0313(0),
                 CDD-0316(0), CDD-0321(0), CDD-DSP-0111(0), CDD-DSP-0148(0),
                 CDD-DSP-0147(0)
******************************************************************************/
static FUNC(boolean, DCM_CODE) bCheckValidReqMsg(
    P2CONST(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext,
    P2VAR(tu8MsgType, AUTOMATIC, DCM_VAR) pudtMsgType,
    uint8 u8ServiceID)
{
  uint8   u8Index;
  uint8   u8LoopInc;
  boolean bReturn = TRUE;
  #if(DCM_DEV_ERROR_DETECT == STD_ON)
  uint8   u8ServiceIDError;
  u8ServiceIDError = u8GetErrorORNumID(u8ServiceID, FALSE);
  #endif

  if (u8ServiceID == 0x02)
  {
    u8LoopInc = 2;
  }
  else
  {
    u8LoopInc = 1;
  }
  *pudtMsgType = u8IS_AVAILABILITY_ID(pMsgContext->reqData[0]);
  /*! Loop for all IDs in the requested message */
  /*! If all IDs are Availability IDs or all IDs are Request value /n
      IDs, then Return TRUE \n
      else Return FALSE */
  for (u8Index = u8LoopInc; (u8Index < pMsgContext->reqDataLen)
      && (bReturn != FALSE); u8Index += u8LoopInc)
  {
    if (u8IS_AVAILABILITY_ID(pMsgContext->reqData[u8Index]) == *pudtMsgType)
    {
      *pudtMsgType = u8IS_AVAILABILITY_ID(pMsgContext->reqData[u8Index]);
    }
    else
    {
      bReturn = FALSE;
    }
  }
  /*! If still no errors    */
  if (bReturn == TRUE)
  {
    /*! If it is a u8REQUEST_VALUE_MSG message, check the length of 
        the message */
    /*! Switch (Service ID)*/
    if ((u8ServiceID == 0x06) || (u8ServiceID == 0x08) || 
        (u8ServiceID == 0x09))
    {
      /*! If it is a u8REQUEST_VALUE_MSG message and the length of 
        the message isn't equal 1, return FALSE */
      if ((*pudtMsgType == u8REQUEST_VALUE_MSG) && 
        (pMsgContext->reqDataLen != 1))
      {
        bReturn = FALSE;
      }
    }
    /*! if the service is 0x02, check the validity of the message */
    else if (u8ServiceID == 0x02)
    {
      bReturn = bIsValidFormat(pMsgContext);
    }
    else
    {
    }
  }
  #if(DCM_DEV_ERROR_DETECT == STD_ON)
  if (bReturn == FALSE)
  {
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID, u8ServiceIDError, 
        DCM_u8E_OBD_INVALID_REQUEST);
  }
  #endif
  return bReturn;
}
/*******************************************************************************/
/*! \Description Checks that the format of service 02 request is valid.\n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      Validity of request message. 
    \Range       TRUE, FALSE     
    \Trace_To    CDD-0344(0), CDD-1113(0)*/
/******************************************************************************/
static FUNC(boolean, DCM_CODE) bIsValidFormat(
  P2CONST(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{
  boolean bReturn = TRUE;
  /*! If the message length is not multiple of 2, return FALSE */
  if ((pMsgContext->reqDataLen % 2) != 0)
  {
    bReturn = FALSE;
  }
  return bReturn;
}
/*******************************************************************************/
/*! \Description Sets the response according to the length calculated.\n
    \param[in] u16CheckValue   Length calculated. \n
    \Range       0..65535  \n
    param[in] pMsgContext   Current message context \n
    \Range       Not Null  \n
    \return      void \n
*******************************************************************************/
static FUNC(void, DCM_CODE) vidSetResponse(
  uint16 u16CheckValue,
  P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{
  /*! If no PIDs supported */
  if (u16CheckValue == 0)
  {
    /*! Send NRC 0 */
    DsdInternal_SetNegResponse(pMsgContext, DCM_u8E_SUPPRESS_RESPONSE);
  }
  /*! else */
  else
  {
    /*! Set the response length */
    pMsgContext->resDataLen = u16CheckValue;
  }
  /*!Call DsdInternal_ProcessingDone */
  DsdInternal_ProcessingDone(pMsgContext);
}
/*******************************************************************************/
/*! \Description Clears global variables.\n
    \param[in] void \n
    \return      void. */
/******************************************************************************/
static FUNC(void, DCM_CODE) vidClrGlobalVars(void)
{
  Dsp_u8CurIdIndex = 0;
  Dsp_u8CurDataIndex = 0;
  Dsp_u16ResMsgIndex = 0;
}
#endif /* #if ((DCM_bOBD_SVC01_ENABLED == STD_ON)\
    || (DCM_bOBD_SVC02_ENABLED == STD_ON)\
    || (DCM_bOBD_SVC06_ENABLED == STD_ON)\
    || (DCM_bOBD_SVC08_ENABLED == STD_ON)\
    || (DCM_bOBD_SVC09_ENABLED == STD_ON)) */

#if ((DCM_bOBD_SVC01_ENABLED == STD_ON) ||\
     (DCM_bOBD_SVC02_ENABLED == STD_ON))
/*******************************************************************************/
/*! \Description Gets the valid (configured) IDs.
    \param[in] u8ServiceID   request service ID \n
    \Range       0x01..0x0A  \n
    \param[out] pu8AvaialbleIDs   Pointer to array to be filled \n
    \Range       NOT NULL  \n
    \param[out] pu8Length  pointer to the array length to be filled \n
    \Range        NOT NULL \n
    \return      void. */
/******************************************************************************/
static FUNC(void, DCM_CODE) vidGetValidIDs(uint8 u8ServiceID)
{
  uint8                          u8Index;
  Dcm_DspPidSupportedServiceType u8SuppotredSvcType;
  /*! Loop for all configured PIDs */
  /* !Deviation : For Loop Only executed once because it is dependent on
                the configuration */
  /* PRQA S 2465 L1                                                        */
  for(u8Index = 0; u8Index < (uint8)DCM_u8NUM_OF_PIDS; u8Index++)
  {
  /* PRQA L:L1                                                             */
    u8SuppotredSvcType = 
        Dcm_kstreDspConfig.astrDcmDspPid[u8Index].u8DcmDspPidService;
    /*! If this PID is used and it belongs to the given Serivce*/
    if(((u8SuppotredSvcType == u8ServiceID)
        || (u8SuppotredSvcType == DCM_SERVICE_01_02) )
        && (Dcm_pkstrePbConfig->strPbDcmDspConfig.
        pkstrDcmDspPid[u8Index].bDcmDspPidUsed == (boolean)TRUE))
    {
      /*! Save this PID to be returned */
      Dsp_au8ValidIDs[Dsp_u8NumValidIds] = u8Index;
      Dsp_u8NumValidIds++;
    }
  }
}
/*******************************************************************************/
/*! \Description Clears the Valid PIDs global array.\n
    \param[in] void \n
    \return      void. */
/******************************************************************************/
static FUNC(void, DCM_CODE) vidClearValidPIDs(void)
{
  uint8 u8Index;
  for(u8Index = 0; u8Index < Dsp_u8NumValidIds; u8Index++)
  {
    Dsp_au8ValidIDs[u8Index] = (uint8)0;
  }
  Dsp_u8NumValidIds = 0;
}

#endif /* #if ((DCM_bOBD_SVC01_ENABLED == STD_ON) ||
               (DCM_bOBD_SVC02_ENABLED == STD_ON))*/

#if(DCM_bOBD_SVC01_ENABLED == STD_ON)
/*******************************************************************************/
/*! \Description Clears OBD Service 01 global data.\n
    \param[in] void \n
    \return      void. */
/******************************************************************************/
static FUNC(void, DCM_CODE) vidClrServ01Data(void)
{
  uint8 u8Index;
  /*! Reset Dsp_abPIDFirstProcessed array to FALSE*/
  for(u8Index = 0; u8Index < u8OBD_SVC_MAX_REQ_LEN; u8Index++)
  {
    Dsp_abPIDFirstProcessed[u8Index] = FALSE;
  }
  /*! Clear Dsp_u8CurReqIndex */
  Dsp_u8CurReqIndex = 0;
  /*! Clear valid PIDs array */
  vidClearValidPIDs();
  /*! Clear other global variables */
  vidClrGlobalVars();
}

/*******************************************************************************/
/*! \Description Sets the response if PID is supported.\n
    \param[in] u8CurrentIdx  Current index of the request message \n
    \Range      0..5 \n
    \param[in] u8Context  Current context \n
    \Range     0..255   \n
    \return      NRC.  \n
    \Range       0..255 */
/******************************************************************************/
static FUNC(uint8, DCM_CODE) u8FillResponse(
  uint8 u8CurrentIdx,
  uint8 u8Context,
  P2VAR(Std_ReturnType,AUTOMATIC,DCM_VAR) pudtReadDataReturn)
{
  boolean        bReturn;
  uint8          u8NegRes = 0xFF;

  *pudtReadDataReturn = E_PAUSE;
  /*! If it is the first time to process this PID */
  if (Dsp_abPIDFirstProcessed[u8CurrentIdx] == FALSE)
  {
    Dsp_abPIDFirstProcessed[u8CurrentIdx] = TRUE;
    /*! Check if it is supported by Configuration */
    bReturn = DspInternal_bIsPIDSupported(
      DspInternal_apstreMsgContext[u8Context]->reqData[u8CurrentIdx], 
      &Dsp_u8CurIdIndex);	  
    /*! If supported */
    if (bReturn == (boolean)TRUE)
    {
      /*! Initialy, Clear the response message  */
      /* !Deviation : Macros are needed for code readability and 
                      maintenance       */
      /* PRQA S 3361,2214 ++ */ 
      vidClrResBytes((uint32)Dsp_u16ResMsgIndex, 
          (uint32)Dcm_kstreDspConfig.astrDcmDspPid[Dsp_u8CurIdIndex].
          u8DcmDspPidSize, DspInternal_apstreMsgContext[u8Context]->resData);
      /* PRQA S 3361,2214 -- */ 
      
      /*! In all cases, read the current PID data with DCM_INITIAL */
      *pudtReadDataReturn = DspInternal_udtReadPIDData(Dsp_u8CurIdIndex, DCM_INITIAL, 
        DspInternal_apstreMsgContext[u8Context]->resData, 
        &Dsp_u16ResMsgIndex, &Dsp_u8CurDataIndex, u8Context);
    }
  }
  /*! else (it is not the first time) */
  else
  {
    /*! Read the current PID data with DCM_PENDING */
    *pudtReadDataReturn = DspInternal_udtReadPIDData(Dsp_u8CurIdIndex, DCM_PENDING, 
     DspInternal_apstreMsgContext[u8Context]->resData, 
     &Dsp_u16ResMsgIndex, &Dsp_u8CurDataIndex, u8Context);
  }
   /*! If it returned E_OK, reset Current Data Index */
  if(*pudtReadDataReturn == E_OK)
  {
    Dsp_u8CurDataIndex = 0;
    /*! set the response length to the size of this PID + 1*/
    DspInternal_apstreMsgContext[u8Context]->resDataLen += 
      (Dcm_kstreDspConfig.astrDcmDspPid[Dsp_u8CurIdIndex].
        u8DcmDspPidSize + 1);   
  }
  /*! Else if it returned E_PENDING, set status to 
      u8OBD_SVC_01_PENDING  */
  else if (*pudtReadDataReturn == E_PENDING)
  {
    Dsp_u8CurReqIndex = u8CurrentIdx;
    DspInternal_au8eStatus[u8Context] = u8OBD_SVC_01_PENDING;
  }
  /*! Else (E_NOT_OK), NRC 0 */
  else if (*pudtReadDataReturn == E_NOT_OK)
  {
    u8NegRes = DCM_u8E_SUPPRESS_RESPONSE;
  }
  /*! Else (E_PAUSE) (This PID is not supported), Do Nothing */
  else
  {
  }
  return u8NegRes;
}
/******************************************************************************/
/*! \Description Implements the OBD service 0x01.\n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \param[out] pMsgContext   Pointer to the filled MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To : CDD-0302(0), CDD-0303(0), CDD-0304(0), CDD-1108(0), CDD-1109(0),
                CDD-1110(0), CDD-DSP-0042(0), CDD-0300(0),
                CDD-DSP-0069(0)
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_OBDService01(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{
  tu8MsgType     u8MsgType;  
  uint8          u8NegRes = 0xFF;
  uint8          u8FIndex;
  boolean        bCheckFailed = FALSE;
  boolean        bReturn;
  uint8          u8Context;
  Std_ReturnType udtReadDataReturn = E_OK;

  u8Context = pMsgContext->idContext;
  DspInternal_apstreMsgContext[u8Context] = pMsgContext;

  /*! Clear service 01 global variables */
  vidClrServ01Data();
  
  /*! if the message is valid (contains only availabilty PIDs  \n
      or it contains only request PID values PIDs) then */
  bReturn = bCheckValidReqMsg(pMsgContext, &u8MsgType, 0x01);
  if (bReturn != (boolean)TRUE)
  {
    bCheckFailed = (boolean)TRUE;
  }
  if (bCheckFailed != TRUE)
  {
    /*! get the valid (configured) IDs */
    vidGetValidIDs(DCM_SERVICE_01);
    /*! initialize reponse length to zero */
    DspInternal_apstreMsgContext[u8Context]->resDataLen = 0;

    switch(u8MsgType)
    {
    /*! if the message is availability message */
    case u8AVAILABILTY_MSG:
      /*! Set the availability response */
      DspInternal_vidSetAvailablRes(pMsgContext->reqData, 
        (uint8)pMsgContext->reqDataLen,
        pMsgContext->resData, &Dsp_u16ResMsgIndex, 0x01);
      /*! Set the response according to the calculated length */
      vidSetResponse(Dsp_u16ResMsgIndex, pMsgContext);
      break;

    /*! if it is u8REQUEST_VALUE_MSG message */
    case u8REQUEST_VALUE_MSG:
      /*! Set global index to 0 */
      Dsp_u16ResMsgIndex = 0;
      /*! Loop for PIDs in the request message \n
          if the PID is one of the configured PIDs then */
      for(u8FIndex = 0; (u8FIndex < DspInternal_apstreMsgContext[u8Context]->reqDataLen)
          && ((udtReadDataReturn == E_OK) || (udtReadDataReturn == E_PAUSE)); 
          u8FIndex++)
      {
        /*! Fill the response message */
        u8NegRes = u8FillResponse(u8FIndex, u8Context, 
          &udtReadDataReturn);
      }
      if ((udtReadDataReturn == E_OK) || (udtReadDataReturn == E_PAUSE))
      {
        /*! If all PIDs were not supported */
        if (DspInternal_apstreMsgContext[u8Context]->resDataLen == 0)
        {
          u8NegRes = DCM_u8E_SUPPRESS_RESPONSE;
        }
        /*! else if all data interfaces returned E_OK */
        else if (u8FIndex == DspInternal_apstreMsgContext[u8Context]->reqDataLen)
        {
          DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
          DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
        }
        /*! else, Do nothing */
        else
        {
        }
      }
      break;
    default:
      break;
    }
  }
  /*! else if the request message is not valid then \n
      Set negative response with value 0 */
  else
  {
    u8NegRes = DCM_u8E_SUPPRESS_RESPONSE;
  }
  /*! If negative reponse is set*/
  if (u8NegRes != 0xFF)
  {
    /*! send the NRC to Dsd */
    DsdInternal_SetNegResponse(DspInternal_apstreMsgContext[u8Context], u8NegRes);
    /*! Call DsdInternal_ProcessingDone */
    DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
  }
}

/******************************************************************************/
/*! \Description Main Function for OBD service (0x01). \n
    \param[in]   u8Context
    \Range       0..(DspInternal_u8MAX_NUM_INTERNAL_REQ-1)
    \return      void.
*******************************************************************************/
static FUNC(void,DCM_CODE) vidMainOBDService01 (uint8 u8Context)
{
  Std_ReturnType udtReadPIDReturn = E_OK;
  uint8          u8Index;
  uint8          u8NegRes = 0xFF;

  /*! if there is cancel request, call the application function with \n
      op. status DCM_CANCEL */
  if (DspInternal_apstreMsgContext[u8Context]->msgAddInfo.cancelOperation == 1)
  {
    udtReadPIDReturn = DspInternal_udtReadPIDData(Dsp_u8CurIdIndex, DCM_CANCEL, 
      DspInternal_apstreMsgContext[u8Context]->resData,
      &Dsp_u16ResMsgIndex, &Dsp_u8CurDataIndex, u8Context);
    /*! if it returns E_OK, set status to idle and call 
        DsdInternal_ProcessingDone */
    if (udtReadPIDReturn == E_OK)
    {
      DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
      DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
      
    }
    /*! Else if it returns E_PENDING , Do nothing */
    else if (udtReadPIDReturn == E_PENDING)
    {
      
    }
    /*! Else (E_NOT_OK), NRC 0 */
    else
    {
      u8NegRes = DCM_u8E_SUPPRESS_RESPONSE;
    }
      
  }
  /*! else (no cancel request) */
  else
  {
    for(u8Index = Dsp_u8CurReqIndex; (u8Index < 
      DspInternal_apstreMsgContext[u8Context]->reqDataLen)
          && ((udtReadPIDReturn == E_OK) || (udtReadPIDReturn == E_PAUSE))
          ;u8Index++)
    {
      u8NegRes = u8FillResponse(u8Index, u8Context, &udtReadPIDReturn);
    }
    if ((udtReadPIDReturn == E_OK) || (udtReadPIDReturn == E_PAUSE))
    {
      /*! Set positive response and send to Dsd */
      DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
      DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
    }
  }
 /*! If negative response was set, send it to Dsd */
  if(u8NegRes != 0xFF)
  {
    /*! send the NRC to Dsd */
    DsdInternal_SetNegResponse(DspInternal_apstreMsgContext[u8Context], u8NegRes);
    /*! Call DsdInternal_ProcessingDone */
    DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
  }
}
#endif /*! (#if(DCM_bOBD_SVC01_ENABLED == STD_ON)) */

#if(DCM_bOBD_SVC02_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Implements the OBD service (0x02).\n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \param[out] pMsgContext   Pointer to the filled MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To : CDD-0308(0), CDD-0309(0), CDD-DSP-0043(0)
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This Service performs a lot of checks,   */
/*              so metrics for this service is not met.                       */
/* PRQA S 4700 ++                                                             */
FUNC(void,DCM_CODE) DspInternal_OBDService02(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{
  VAR(tu8MsgType, DCM_VAR) u8MsgType;
  uint8                    u8Index;
  uint8                    u8NegRes = 0xFF;
  boolean                  bReturn;

  /*! Clear global data */
  vidClearValidPIDs();
  vidClrGlobalVars();
  /*! if the message is valid (contains only availabilty PIDs  \n
      or it contains only request PID values PIDs) then */
  bReturn = bCheckValidReqMsg(pMsgContext, &u8MsgType, 0x02);
  if (bReturn == TRUE)
  {
    /*! get the valid (configured) IDs */
    vidGetValidIDs(DCM_SERVICE_02);
    /*! initialize reponse length to zero */
    pMsgContext->resDataLen = 0;

    switch(u8MsgType)
    {
    /*! if the message is availability message */
    case u8AVAILABILTY_MSG:
      /*! Set the availability response */
      DspInternal_vidSetAvailablRes(pMsgContext->reqData, 
        (uint8)pMsgContext->reqDataLen,
        pMsgContext->resData, &Dsp_u16ResMsgIndex, 0x02);
      /*! Set the response according to the calculated length */
      vidSetResponse(Dsp_u16ResMsgIndex, pMsgContext);
      break;

    /*! if it is u8REQUEST_VALUE_MSG message */
    case u8REQUEST_VALUE_MSG:
      /*! Loop for the request message length */
      for(u8Index = 0; (u8Index < pMsgContext->reqDataLen)
          && (u8NegRes == 0xFF); u8Index+=2)
      {
        /*! If this PID is supported */
        bReturn = DspInternal_bIsPIDSupported(pMsgContext->reqData[u8Index], 
          &Dsp_u8CurIdIndex);
        if (bReturn == (boolean)TRUE)
        {
          /*! If the PID is followed by freeze no. 0x00 */
          if (pMsgContext->reqData[u8Index+1] == u8DEFAULT_FREEZE_FRAME)
          {
            /*! Fill the response message */
            u8NegRes = u8SetResSVC02(Dsp_u8CurIdIndex, u8Index, pMsgContext);
          }
          /*! Else, Ignore this PID */
          else
          {
          }
        }
        /*! else (if PID is not supported) then ignore this PID */
        else
        {

        }
      }
      /*! If all PIDs are not supported, call DsdInternal_SetNegResponse */
      if (Dsp_u16ResMsgIndex == 0)
      {
        u8NegRes = DCM_u8E_SUPPRESS_RESPONSE;
      }
      /*! else, set the length of the response message and set positive 
          response */
      else
      {
        pMsgContext->resDataLen = Dsp_u16ResMsgIndex;
        DsdInternal_ProcessingDone(pMsgContext);
      }
      break;
    default:
      break;
    }
  }
  /*! Else if request message is not valid, send NRC 0 */
  else
  {
    u8NegRes = DCM_u8E_SUPPRESS_RESPONSE;  
  }
  if (u8NegRes != 0xFF)
  {
    DsdInternal_SetNegResponse(pMsgContext, u8NegRes);
    DsdInternal_ProcessingDone(pMsgContext);
  }
}
/* PRQA S 4700 --                                                             */
/******************************************************************************/
/*! \Description Reads the freeze frame data from Dem Module.\n
    \param[in] u8PIDIndex   Current PID to process. \n
    \Range       0..255 \n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      NRC value.
    \Range       0..255
    \Trace_To : CDD-1117(0), CDD-DSP-0053(0)
*******************************************************************************/
static FUNC(uint8, DCM_CODE) u8ReadDataOfFF(
    uint8 u8PIDIndex,
    P2CONST(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{
  uint8           u8Index;
  uint8           u8PID;
  uint8           u8BufSize;
  Std_ReturnType  u8RetOBDData;
  uint8           u8NegRes = 0xFF;
  uint16          u16StartIndex;

  /*! loop for all data coreesponding to this PID */
  for(u8Index = 0; (u8Index < Dcm_kstreDspConfig.
      astrDcmDspPid[u8PIDIndex].u8NumOfPidData)
      && (u8NegRes == 0xFF); u8Index++)
  {
    u8PID = Dcm_kstreDspConfig.astrDcmDspPid[u8PIDIndex].
        u8DcmDspPidIdentifier;
    u8BufSize = (uint8)(Dcm_kstreDspConfig.astrDcmDspPid[u8PIDIndex].
        pkstrDcmDspPidData[u8Index].u16DcmDspPidDataSize / 8);

    if (u8Index == 0)
    {
      u16StartIndex = (uint16)(Dsp_u16ResMsgIndex + 2);
    }
    else
    {
      u16StartIndex = Dsp_u16ResMsgIndex;
    }
    /*! Call Dem_ReadDataOfOBDFreezeFrame */
    u8RetOBDData = Dem_ReadDataOfOBDFreezeFrame(u8PID, u8Index,
        &pMsgContext->resData[u16StartIndex], &u8BufSize);
    /*! If the return of the Dem API equals E_OK */
    if (u8RetOBDData == E_OK)
    {
      /*! Check if FF data is stored. If yes, increment the global \n
          response index    */
      if (u8BufSize != 0)
      {
        /*! If first Data, then */
        if (u8Index == 0)
        {
          /*! set first byte in the response to PID value */
          pMsgContext->resData[Dsp_u16ResMsgIndex] = u8PID;
          /*! Set next byte to 0x00 (Freeze Frame 0) */
          pMsgContext->resData[Dsp_u16ResMsgIndex + 1] = u8DEFAULT_FREEZE_FRAME;
          Dsp_u16ResMsgIndex += 2;
        }
        /*! update response index by buffer size */
        Dsp_u16ResMsgIndex += u8BufSize;
      }
      /*! else, do nothing (ignore this PID) */
      else
      {
        u8NegRes = u8IGNORE_PID;
      }
    }
    /*! else if the return of the Dem API equals E_NOT_OK */
    else
    {
      /*! Send negative reponse 0 */
      u8NegRes = DCM_u8E_SUPPRESS_RESPONSE;
    }
  }
  return u8NegRes;
}
/******************************************************************************/
/*! \Description Sets the response message of service 02.\n
    \param[in] u8PIDIndex   Current PID to process. \n
    \Range       0..255 \n
    \param[in] u8CurrentReqIdx   Current processed byte in the request \n
               message. \n
    \Range       0..255 \n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      uint8.
    \Trace_To : CDD-1114(0), CDD-1118(0), CDD-DSP-0052(0)
*******************************************************************************/
static FUNC(uint8, DCM_CODE) u8SetResSVC02(
    uint8 u8PIDIndex,
    uint8 u8CurrentReqIdx,
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{
  uint32         u32DTC;
  uint8          u8NegRes = 0xFF;
  Std_ReturnType udtReturn;

  /*! If the PID value = 0x02 */
  if(pMsgContext->reqData[u8CurrentReqIdx] == 0x02)
  {
    /*! set first byte in the response to PID value */
    pMsgContext->resData[Dsp_u16ResMsgIndex] = 
        pMsgContext->reqData[u8CurrentReqIdx];
    /*! Set next byte to 0x00 (Freeze Frame 0) */
    pMsgContext->resData[Dsp_u16ResMsgIndex + 1] = u8DEFAULT_FREEZE_FRAME;
    /*! If the call to Dem_GetDTCOfOBDFreezeFrame returns E_OK */
    udtReturn = 
      Dem_GetDTCOfOBDFreezeFrame(u8DEFAULT_FREEZE_FRAME, &u32DTC);
    if (udtReturn == E_OK)
    {
      /*! concatenate the DTC value to the response message */
      pMsgContext->resData[Dsp_u16ResMsgIndex + 2] = 
          (uint8)vidGET_DTC_HIGH_BYTE(u32DTC);
      pMsgContext->resData[Dsp_u16ResMsgIndex + 3] = 
          (uint8)vidGET_DTC_LOW_BYTE(u32DTC);
    }
    /*! else if Dem_GetDTCOfOBDFreezeFrame returns E_NOT_OK \n
    (this means that DTC is not available, i.e. no FF data stored) */
    else
    {
      /*! concatenate value 0 to the response message */
      pMsgContext->resData[Dsp_u16ResMsgIndex + 2] = 0;
      pMsgContext->resData[Dsp_u16ResMsgIndex + 3] = 0;
    }
    Dsp_u16ResMsgIndex += 4;
  }
  /*! any PID other than PID 0x02 */
  else
  {
    /*! Read data of the OBD freeze frame */
    u8NegRes = u8ReadDataOfFF(u8PIDIndex, pMsgContext);
    /*! If no FF data stored, ignore this PID */
    if (u8NegRes == u8IGNORE_PID)
    {
      u8NegRes = 0xFF;
    }
  }
  return u8NegRes;
}
#endif /*! #if(DCM_bOBD_SVC02_ENABLED == STD_ON) */
#if (DCM_bOBD_SVC03_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Implements the OBD Service (0x03).\n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \param[out] pMsgContext   Pointer to the filled MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To : CDD-DSP-0044(0), 
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_OBDService03(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{
  vidObtainDTCSVCs(0x03, pMsgContext);    
}
#endif /* #if (DCM_bOBD_SVC03_ENABLED == STD_ON) */
#if(DCM_bOBD_SVC04_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Implements the OBD ClearDiagnosticInformation (0x04) service.\n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \param[out] pMsgContext   Pointer to the filled MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To : CDD-0312(0), CDD-0328(0), CDD-1126(0), CDD-1127(0), \n
                CDD-DSP-0045(0), CDD-DSP-0056(0)
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_OBDService04(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{
  uint8                        u8Context;
  Dem_ReturnClearDTCType       udtClearResult;

  u8Context = pMsgContext->idContext;
  DspInternal_apstreMsgContext[u8Context] = pMsgContext;
  /*! Call Rte_Call_DcmIf_ClearDTC with the following parameters:
      DTC VALUE = 0,
      DTC KIND = DEM_DTC_KIND_EMISSION_REL_DTCS,
      DTC ORIGIN = DEM_DTC_ORIGIN_PRIMARY_MEMORY */
  udtClearResult = Rte_Call_DcmIf_ClearDTC(u32DEFAULT_DTC,
                                           DEM_DTC_KIND_EMISSION_REL_DTCS,
                                           DEM_DTC_ORIGIN_PRIMARY_MEMORY);
  /*! If it returns DEM_CLEAR_OK */
  if (udtClearResult == DEM_CLEAR_OK)
  {
    /*! Set the response length to 0 and call DsdInternal_ProcessingDone */
    pMsgContext->resDataLen = u32OBD_SVC04_RES_LENGTH;
    DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
  }
  /*! Else if it returns DEM_CLEAR_PENDING, set status to PENDING */
  else if (udtClearResult == DEM_CLEAR_PENDING)
  {
    DspInternal_au8eStatus[u8Context] = u8OBD_SVC_04_PENDING;
  }
  /*! else (any other return), set negative response DCM_E_CONDITIONSNOTCORRECT
      and call DsdInternal_ProcessingDone */
  else
  {
    DsdInternal_SetNegResponse(pMsgContext, DCM_E_CONDITIONSNOTCORRECT);
    DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
  }
}
/******************************************************************************/
/*! \Description Main Function for OBD service (0x04). \n
    \param[in]   u8Context
    \Range       0..(DspInternal_u8MAX_NUM_INTERNAL_REQ-1)
    \return      void. \n
    \Trace_To    CDD-DSP-0108(0)
*******************************************************************************/
static FUNC(void,DCM_CODE) vidMainOBDService04 (uint8 u8Context)
{
  Dem_ReturnClearDTCType       udtClearResult;
  /*! If a cancel request is set, set status to IDLE and call  
      DsdInternal_ProcessingDone        */
  if (DspInternal_apstreMsgContext[u8Context]->msgAddInfo.cancelOperation == 1)
  {
    /*! Call Dem_DcmCancelOperation */
    Dem_DcmCancelOperation();
    DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
    DspInternal_apstreMsgContext[u8Context]->resDataLen = u32OBD_SVC04_RES_LENGTH;
    DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
  }
  /*! Else (No cancel request) */
  else
  {
    /*! Call Rte_Call_DcmIf_ClearDTC with the following parameters:
    DTC VALUE = 0,
    DTC KIND = DEM_DTC_KIND_EMISSION_REL_DTCS,
    DTC ORIGIN = DEM_DTC_ORIGIN_PRIMARY_MEMORY */
    udtClearResult = Rte_Call_DcmIf_ClearDTC(u32DEFAULT_DTC,
                                      DEM_DTC_KIND_EMISSION_REL_DTCS,
                                      DEM_DTC_ORIGIN_PRIMARY_MEMORY);
    /*! If it returns DEM_CLEAR_OK */
    if (udtClearResult == DEM_CLEAR_OK)
    {
      /*! Set status to IDLE */
      /*! Set the response length to 0 and call DsdInternal_ProcessingDone */
      DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
      DspInternal_apstreMsgContext[u8Context]->resDataLen = u32OBD_SVC04_RES_LENGTH;
      DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
    }
    /*! else if it returns DEM_CLEAR_PENDING, wait for the next Main */
    else if (udtClearResult == DEM_CLEAR_PENDING)
    {
    
    }
    /*! else (any other return), set negative response DCM_E_CONDITIONSNOTCORRECT
    and call DsdInternal_ProcessingDone */
    else
    {
      DsdInternal_SetNegResponse(DspInternal_apstreMsgContext[u8Context], 
                                              DCM_E_CONDITIONSNOTCORRECT);
      DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
    }
  }

}
#endif /*! #if(DCM_bOBD_SVC04_ENABLED == STD_ON) */
#if (DCM_bOBD_SVC06_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Implements the OBD Service (0x06).\n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \param[out] pMsgContext   Pointer to the filled MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To : CDD-0347(0), CDD-0351(0), CDD-DSP-0046(0), \n
                CDD-DSP-0110(0)
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_OBDService06(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{
  uint8   u8MsgType;
  boolean bCheckFailed = FALSE;
  uint8   u8NegRes = 0xFF;
  boolean bReturn;
  uint16  u16CalcResLength;
  uint8   u8Context;

  u8Context = pMsgContext->idContext;
  DspInternal_apstreMsgContext[u8Context] = pMsgContext;

  /*! Clear global variables */
  vidClrGlobalVars();

  bReturn = bCheckValidReqMsg(pMsgContext, &u8MsgType, 0x06);
  if (bReturn != (boolean)TRUE)
  {
    bCheckFailed = (boolean)TRUE;
  }
  if (bCheckFailed != TRUE)
  {
    /*! initialize reponse length to zero */
    pMsgContext->resDataLen = 0;

    switch(u8MsgType)
    {
    /*! if the message is availability message */
    case u8AVAILABILTY_MSG:
      /*! Set the availability response */
      DspInternal_vidSetAvailablRes(pMsgContext->reqData, 
        (uint8)pMsgContext->reqDataLen,
        pMsgContext->resData, &Dsp_u16ResMsgIndex, 0x06);
      /*! Set the response according to the calculated length */
      vidSetResponse(Dsp_u16ResMsgIndex, pMsgContext);
      break;

    /*! if it is u8REQUEST_VALUE_MSG message */
    case u8REQUEST_VALUE_MSG:
      bReturn = DspInternal_bIsSupportedOBDMID(
        DspInternal_apstreMsgContext[u8Context]->reqData[0], 
        &Dsp_u8CurIdIndex);
      /*! Make sure that the given OBDMID is supported in cfg. */
      if (bReturn == (boolean)TRUE)
      {
        u16CalcResLength = u16CALC_SVC06_RES_LEN(Dsp_u8CurIdIndex);
        if (u16CalcResLength > pMsgContext->resMaxDataLen)
        {
        #if (DCM_PAGED_BUFFER_ENABLED == STD_ON)
          vidInitPageProcess(u8Context, u16CalcResLength, 0x06);
        #else
          u8NegRes = DCM_u8E_SUPPRESS_RESPONSE;
       #endif
        }
        else
        {
          /*! read data of this MID and fill response*/
          (void)DspInternal_udtReadMIDData(Dsp_u8CurIdIndex, &Dsp_u16ResMsgIndex, 
            &Dsp_u8CurDataIndex, pMsgContext->resData, 
            (uint16)DspInternal_apstreMsgContext[u8Context]->resMaxDataLen);
          /*! If All DTRs returned DCM_DTRSTATUS_INVISIBLE, set NRC 0, else */
          if (Dsp_u16ResMsgIndex != 0)
          {
            /*! Set the length of the response to the returned filled length */
            pMsgContext->resDataLen = Dsp_u16ResMsgIndex;
            /*! send processing done to Dsd */
            DsdInternal_ProcessingDone(pMsgContext);
          }
          else
          {
            u8NegRes = DCM_u8E_SUPPRESS_RESPONSE;
          }
        }
      }
      /*! Else if the OBDMID is not supported, set negative response 0*/
      else
      {
        u8NegRes = DCM_u8E_SUPPRESS_RESPONSE;
      }

      break;
    default:
      break;
    }
  }
  /*! else if the request message is not valid, set negative response 0 */
  else
  {
    u8NegRes = DCM_u8E_SUPPRESS_RESPONSE;
  }
  if(u8NegRes != 0xFF)
  {
    /*! NRC 0 */
    DsdInternal_SetNegResponse(pMsgContext, u8NegRes); 
    /*! send processing done to Dsd */
    DsdInternal_ProcessingDone(pMsgContext);
  }
}
#if (DCM_PAGED_BUFFER_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Main Function for OBD service (0x06). \n
    \param[in]   u8Context
    \Range       0..(DspInternal_u8MAX_NUM_INTERNAL_REQ-1)
    \return      void. \n 
*******************************************************************************/
static FUNC(void,DCM_CODE) vidMainOBDService06 (uint8 u8Context)
{
  Std_ReturnType udtReadMidReturn;
  /*! If there is cancel request */
  if (DspInternal_apstreMsgContext[u8Context]->msgAddInfo.cancelOperation == 1)
  {
    /*! Set status to IDLE */
    DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
    /*! Send DsdInternal_ProcessingDone */
    DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
  }
  /*! Else (No CANCEL request) */
  else
  {
    /*! If There is Update Page request */
    if (DspInternal_abePageUpdate[u8Context] == TRUE)
    {
      /*! Reset Page Update Flag */
      DspInternal_abePageUpdate[u8Context] = FALSE;
      /*! Read Mid Data */
      udtReadMidReturn = DspInternal_udtReadMIDData(Dsp_u8CurIdIndex, 
        &Dsp_u16ResMsgIndex, 
        &Dsp_u8CurDataIndex, &DspInternal_apstreMsgContext[u8Context]->resData[0], 
        (uint16)DspInternal_apstreMsgContext[u8Context]->resMaxDataLen);
      /*! Process current page */
      DsdInternal_ProcessPage(u8Context, (uint32)Dsp_u16ResMsgIndex);
      /*! Reset current Index */
      Dsp_u16ResMsgIndex = 0;
      /*! If returned E_OK (Paged-Buffer ended), Set status to IDLE */
      if (udtReadMidReturn == E_OK)
      {
        DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
      }
    }
  }
}
#endif /*! #if (DCM_PAGED_BUFFER_ENABLED == STD_ON)*/
#endif /*! #if (DCM_bOBD_SVC06_ENABLED == STD_ON)*/
#if (DCM_bOBD_SVC07_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Implements the OBD Service (0x07).\n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \param[out] pMsgContext   Pointer to the filled MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To : CDD-DSP-0047(0)
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_OBDService07(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{
  vidObtainDTCSVCs(0x07, pMsgContext);    
}
#endif /* (DCM_bOBD_SVC07_ENABLED == STD_ON) */
#if(DCM_bOBD_SVC08_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Implements the OBD Service (0x08).\n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \param[out] pMsgContext   Pointer to the filled MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To   CDD-0319(0), CDD-0332(0),CDD-0349(0), CDD-0352(0), CDD-1133(0) \n
                CDD-DSP-0048(0), CDD-DSP-0057(0), CDD-3024(0)
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_OBDService08(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{
  boolean        bCheckFailed = FALSE;
  uint8          u8InBuf;
  uint8          u8OutBuf;
  uint8          u8NegRes = 0xFF;
  Std_ReturnType u8Return;
  tu8MsgType     u8MsgType;
  boolean        bReturn;

  vidClrGlobalVars();
  /*! if the message is valid (contains only availabilty PIDs  \n
      or it contains only request PID values PIDs) then */
  bReturn = bCheckValidReqMsg(pMsgContext, &u8MsgType, 0x08);
  if (bReturn != (boolean)TRUE)
  {
    bCheckFailed = (boolean)TRUE;
  }
  if (bCheckFailed != TRUE)
  {
    /*! initialize response length to zero */
    pMsgContext->resDataLen = 0;

    switch(u8MsgType)
    {
    /*! if the message is availability message */
    case u8AVAILABILTY_MSG:
      /*! Set the availability response */
      DspInternal_vidSetAvailablRes(pMsgContext->reqData, 
        (uint8)pMsgContext->reqDataLen,
        pMsgContext->resData, &Dsp_u16ResMsgIndex, 0x08);
      /*! Set the response according to the calculated length */
      vidSetResponse(Dsp_u16ResMsgIndex, pMsgContext);
      break;

    /*! if it is u8REQUEST_VALUE_MSG message */
    case u8REQUEST_VALUE_MSG:
      /*! if the requested TID is 0x01 (which is the only available TID \n
          as specified by ISO)    */
      if (pMsgContext->reqData[0] == u8DEFAULT_RC_TID)
      {
        /*! Call the RTE interface */
        u8Return = Dcm_kstreDspConfig.astrDcmDspRequestControl[0].
            pfu8RequestControl(&u8OutBuf, &u8InBuf);
        /*! If the interface returned E_OK */
        if (u8Return == E_OK)
        {
          /*! Fill the response with TID */
          pMsgContext->resData[0] = pMsgContext->reqData[0];
          /*! increment the response length */
          pMsgContext->resDataLen++;
          /*! call DsdInternal_ProcessingDone */
          DsdInternal_ProcessingDone(pMsgContext);
        }
        /*! Else (the interface returned E_NOT_OK ) */
        else
        {
          /*! Set negative response DCM_E_CONDITIONSNOTCORRECT */
          u8NegRes = DCM_E_CONDITIONSNOTCORRECT;
        }
      }
      /*! else (if TID is not 0x01) */
      else
      {
        /*! Set negative response DCM_u8E_SUPPRESS_RESPONSE */
        u8NegRes = DCM_u8E_SUPPRESS_RESPONSE;
      }
      break;
    default:
      break;
    }
  }
  /*! else (if the request message is not valid) */
  else
  {
    u8NegRes = DCM_u8E_SUPPRESS_RESPONSE;
  }
  /*! If there is any negative response set */
  if (u8NegRes != 0xFF)
  {
    /*! Call DsdInternal_SetNegResponse with the set negative response */
    DsdInternal_SetNegResponse(pMsgContext, u8NegRes);
    /*! call DsdInternal_ProcessingDone */
    DsdInternal_ProcessingDone(pMsgContext);
  }
}
#endif /*! #if(DCM_bOBD_SVC08_ENABLED == STD_ON) */
#if (DCM_bOBD_SVC09_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Implements the OBD Service (0x09).\n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \param[out] pMsgContext   Pointer to the filled MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void. \n
    \Trace_To : CDD-0324(0), CDD-0353(0), CDD-1137(0),CDD-1545(0), \n
                CDD-DSP-0049(0), CDD-0320(0), CDD-DSP-0065(0), CDD-DSP-0066(0)\n
                , CDD-DSP-0068(0), CDD-DSP-0109(0)
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This Service performs a lot of checks,   */
/*              so metrics for this service is not met.                       */
/* PRQA S 4700 ++                                                             */
FUNC(void,DCM_CODE) DspInternal_OBDService09(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{
  uint8          u8Context;
  Std_ReturnType udtReadInfoReturn;
  tu8MsgType     u8MsgType;
  boolean        bReturn;
  uint8          u8NegRes = 0xFF;
  uint16         u16ResLength;

  u8Context = pMsgContext->idContext;
  DspInternal_apstreMsgContext[u8Context] = pMsgContext;

  /*! Clear global data */
  vidClrGlobalVars();

  /*! if the message is valid (contains only availabilty PIDs  \n
      or it contains only request PID values PIDs) then */
  bReturn = bCheckValidReqMsg(pMsgContext, &u8MsgType, 0x09);
  if (bReturn == TRUE)
  {
    /*! initialize response length to zero */
    DspInternal_apstreMsgContext[u8Context]->resDataLen = 0;

    switch(u8MsgType)
    {
    /*! if the message is availability message */
    case u8AVAILABILTY_MSG:
      /*! Set the availability response */
      DspInternal_vidSetAvailablRes(pMsgContext->reqData, 
        (uint8)pMsgContext->reqDataLen,
        pMsgContext->resData, &Dsp_u16ResMsgIndex, 0x09);
      /*! Set the response according to the calculated length */
      vidSetResponse(Dsp_u16ResMsgIndex, pMsgContext);
      break;

    /*! if it is u8REQUEST_VALUE_MSG message */
    case u8REQUEST_VALUE_MSG:
      /*! if the requested info. type is supported */
      bReturn = DspInternal_bIsSupportedVehInfo(
        DspInternal_apstreMsgContext[u8Context]->reqData[0], &Dsp_u8CurIdIndex);
      if (bReturn == (boolean)TRUE)
      {
        /*! Calculate response length */
        u16ResLength = u16CalcResLength09();
        /*! if Calculated response length > Configured max. length */
        if (u16ResLength > DspInternal_apstreMsgContext[u8Context]->resMaxDataLen)
        {
        #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
          /*!  #if(DCM_PAGED_BUFFER_ENABLED == STD_ON) */
          /*! Call vidInitPageProcess */
          vidInitPageProcess(u8Context, u16ResLength, 0x09);
        #else
          /*! #else, NRC 0x22 */
          u8NegRes = DCM_E_CONDITIONSNOTCORRECT;
        #endif
        }
        /*! else (Calculated response length <= Configured max. length) */
        else
        {
          /*! Read data of vehicle info.  */
          udtReadInfoReturn = DspInternal_udtReadVehInfoData(Dsp_u8CurIdIndex,
            DCM_INITIAL, DspInternal_apstreMsgContext[u8Context]->resData, 
            &Dsp_u16ResMsgIndex, &Dsp_u8CurDataIndex,
            DspInternal_apstreMsgContext[u8Context]->resMaxDataLen);
          /*! If return is E_OK, set response length and 
              set positive response */
          if (udtReadInfoReturn == E_OK)
          {
            DspInternal_apstreMsgContext[u8Context]->resDataLen = Dsp_u16ResMsgIndex;
            DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
            DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
          }
          /*! Else if E_PENDING, set status u8OBD_SVC_09_PENDING */
          else if (udtReadInfoReturn == E_PENDING)
          {
            DspInternal_au8eStatus[u8Context] = u8OBD_SVC_09_PENDING;
          }
          /*! Else (E_NOT_OK), set NRC 0x22 */
          else
          {
            u8NegRes = DCM_E_CONDITIONSNOTCORRECT;
          }
        }

      }
      /*! else (Info. is not supported) */
      else
      {
        u8NegRes = DCM_u8E_SUPPRESS_RESPONSE;
      }
      break;
    default:
      break;
    }
  }
  /* else (message is not valid), set negative response 
     DCM_u8E_SUPPRESS_RESPONSE    */
  else
  {
    u8NegRes = DCM_u8E_SUPPRESS_RESPONSE;
  }
  /*! if a negative response is set, call DsdInternal_SetNegResponse*/
  if (u8NegRes != 0xFF)
  {
    DsdInternal_SetNegResponse(pMsgContext, u8NegRes);
    DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
  }
}
/* PRQA S 4700 --                                                             */
/******************************************************************************/
/*! \Description Main Function for OBD service (0x09). \n
    \param[in]   u8Context
    \Range       0..(DspInternal_u8MAX_NUM_INTERNAL_REQ-1)
    \return      void. \n
    \Trace_To   CDD-DSP-0067(0)
*******************************************************************************/
static FUNC(void,DCM_CODE) vidMainOBDService09 (uint8 u8Context)
{
  Std_ReturnType u8ReadInfoReturn;
  uint8          u8NegRes = 0XFF;

  /*! if there is cancel request, call the application function with \n
      op. status DCM_CANCEL */
  if (DspInternal_apstreMsgContext[u8Context]->msgAddInfo.cancelOperation == 1)
  {
    u8ReadInfoReturn = DspInternal_udtReadVehInfoData(Dsp_u8CurIdIndex,
      DCM_CANCEL, &DspInternal_apstreMsgContext[u8Context]->resData[Dsp_u16ResMsgIndex],
      &Dsp_u16ResMsgIndex, &Dsp_u8CurDataIndex,
      DspInternal_apstreMsgContext[u8Context]->resMaxDataLen);
    /*! if readInfo returns E_PENDING */
    if (u8ReadInfoReturn == E_PENDING)
    {
      /*! Do nothing */
    }
    /*! Else: set status to idle and send positive response */
    else if (u8ReadInfoReturn == E_OK)
    {
      DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
      DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
    }
    /*! Else, E_NOT_OK */
    else
    {
      u8NegRes = DCM_u8E_SUPPRESS_RESPONSE;
    }
      
  }
  /*! else (no cancel request) */
  else
  {
    u8ReadInfoReturn = DspInternal_udtReadVehInfoData(Dsp_u8CurIdIndex,
      DCM_PENDING, DspInternal_apstreMsgContext[u8Context]->resData,
      &Dsp_u16ResMsgIndex, &Dsp_u8CurDataIndex, 
      DspInternal_apstreMsgContext[u8Context]->resMaxDataLen);
    /*! if return E_OK, Set positive response  */
    if (u8ReadInfoReturn == E_OK)
    {
      DspInternal_apstreMsgContext[u8Context]->resDataLen = Dsp_u16ResMsgIndex;
      DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
      DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
    }
    /*! else if Return E_PENDING, Do Nothing */
    else if (u8ReadInfoReturn == E_PENDING)
    {  
    }
    /*! Else (Return E_NOT_OK) */
    else
    {
      u8NegRes = DCM_E_CONDITIONSNOTCORRECT;
    }
  }
  if (u8NegRes != 0xFF)
  {
    DsdInternal_SetNegResponse(DspInternal_apstreMsgContext[u8Context], u8NegRes);
    DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
    DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
  }

}
/******************************************************************************/
/*! \Description Calculates length of OBD service (0x09) response. \n
    \param[in]   void
    \return      Length of Service 09 response message \n
    \Range       0..65535
*******************************************************************************/
static FUNC(uint16, DCM_CODE) u16CalcResLength09 (void)
{
  uint16 u16ResLength = 2;
  uint8  u8Index;
  for (u8Index = 0; u8Index < Dcm_kstreDspConfig.
    astrDcmDspVehInfo[Dsp_u8CurIdIndex].u8NumVehInfoData; u8Index++)
  {
    u16ResLength += u8GET_VEHINFO_DATASIZE(Dsp_u8CurIdIndex, u8Index);
  }
  return u16ResLength;
}

#if (DCM_PAGED_BUFFER_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Main Function for page processing of OBD service (0x09). \n
    \param[in]   u8Context
    \Range       0..(DspInternal_u8MAX_NUM_INTERNAL_REQ-1)
    \return      void. \n
*******************************************************************************/
static FUNC(void, DCM_CODE) vidProcessPage09(uint8 u8Context)
{
  Std_ReturnType          u8ReadInfoReturn;
  /* !Deviation : Static is used because the variable is not used anywhere 
                    else and its value should be maintained                  */
  /* PRQA S 3223 ++                                                          */
  static Dcm_OpStatusType LOC_udtOpStatus = DCM_INITIAL;
  /* PRQA S 3223 --                                                          */

  /*! if there is cancel request, call the application function with \n
      op. status DCM_CANCEL */
  if (DspInternal_apstreMsgContext[u8Context]->msgAddInfo.cancelOperation == 1)
  {
    u8ReadInfoReturn = DspInternal_udtReadVehInfoData(Dsp_u8CurIdIndex,
      DCM_CANCEL, &DspInternal_apstreMsgContext[u8Context]->resData[Dsp_u16ResMsgIndex],
      &Dsp_u16ResMsgIndex, &Dsp_u8CurDataIndex, 
      DspInternal_apstreMsgContext[u8Context]->resMaxDataLen);
    /*! if readInfo returns E_PENDING */
    if (u8ReadInfoReturn == E_PENDING)
    {
      /*! Do nothing */
    }
    /*! Else: */
    else
    {
      DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
      DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
    }   
  }
  /*! Else (No cancel request) */
  else
  {
    /*! If Update Page request is received */
    if (DspInternal_abePageUpdate[u8Context] == TRUE)
    {
      /*! Call DspInternal_udtReadVehInfoData */
      u8ReadInfoReturn = DspInternal_udtReadVehInfoData(Dsp_u8CurIdIndex,
        LOC_udtOpStatus, 
        &DspInternal_apstreMsgContext[u8Context]->resData[0],
        &Dsp_u16ResMsgIndex, &Dsp_u8CurDataIndex,
        DspInternal_apstreMsgContext[u8Context]->resMaxDataLen);
      /*! If it returned E_OK */
      if (u8ReadInfoReturn == E_OK)
      {
        LOC_udtOpStatus = DCM_INITIAL;
        /*! Reset Page Update Flag */
        DspInternal_abePageUpdate[u8Context] = FALSE;
        /*! Process Final Page and set status to IDLE */
        DsdInternal_ProcessPage(u8Context, (uint32)Dsp_u16ResMsgIndex);
        DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
      }
      /*! Else if it returned E_PAUSE */
      else if (u8ReadInfoReturn == E_PAUSE)
      {
        /*! Reset Page Update Flag */
        DspInternal_abePageUpdate[u8Context] = FALSE;
        /*! Process page, set OpStatus to DCM_INITIAL 
            and reset response index */
        DsdInternal_ProcessPage(u8Context, (uint32)Dsp_u16ResMsgIndex);
        LOC_udtOpStatus = DCM_INITIAL;
        Dsp_u16ResMsgIndex = 0;
      }
      /*! else if it returned E_PENDING, set OpStatus to DCM_PENDING */
      else
      {
        LOC_udtOpStatus = DCM_PENDING;
      }
    }
  }
  
}
#endif /* #if (DCM_PAGED_BUFFER_ENABLED == STD_ON)*/
#endif /* #if (DCM_bOBD_SVC09_ENABLED == STD_ON) */

#if (DCM_bOBD_SVC0A_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Implements the OBD Service (0x0A).\n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \param[out] pMsgContext   Pointer to the filled MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void. \n
    \Trace_To : CDD-DSP-0050(0), CDD-0400(0)
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_OBDService0A(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{
  vidObtainDTCSVCs(0x0A, pMsgContext);    
}
#endif /* #if (DCM_bOBD_SVC0A_ENABLED == STD_ON) */

#if ((DCM_bOBD_SVC03_ENABLED == STD_ON)\
    ||(DCM_bOBD_SVC07_ENABLED == STD_ON)\
    ||(DCM_bOBD_SVC0A_ENABLED == STD_ON))
/******************************************************************************/
/*! \Description Implements the common part of the services 0x03, 0x07 \n
                 and 0x0A.\n
    \param[in] u8ServiceID   the service ID. \n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \param[out] pMsgContext   Pointer to the filled MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To : CDD-1122(0), CDD-1123(0), CDD-1124(0), CDD-1468(0), \n
                CDD-DSP-0054(0), CDD-DSP-0106(0)
*******************************************************************************/
static FUNC(void, DCM_CODE) vidObtainDTCSVCs(
    uint8 u8ServiceID,
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{
  uint8                                u8DTCStatusMask = 0;
  uint8                                u8Context;
  uint8                                u8NegRes = 0xFF;
  Dem_DTCOriginType                    u8DTCOrigin = 0;
  Dem_ReturnSetFilterType              u8Return;
  Dem_ReturnGetNumberOfFilteredDTCType u8ReturnNoOfDTC;
  uint16                               u16NoOfDTCs = 0;

  u8Context = pMsgContext->idContext;
  DspInternal_apstreMsgContext[u8Context] = pMsgContext;

  /*! switch for service ID */
  switch(u8ServiceID)
  {
  case 0x03: /*! Case service 0x03*/
    /*! Set status mask to 0x08 */
    u8DTCStatusMask = (uint8)0x08;
    /*! Set DTC orgin to primary memory */
    u8DTCOrigin = DEM_DTC_ORIGIN_PRIMARY_MEMORY;
    break;
  case 0x07: /*! Case service 0x07*/
    /*! Set status mask to 0x04 */
    u8DTCStatusMask = (uint8)0x04;
    /*! Set DTC orgin to primary memory */
    u8DTCOrigin = DEM_DTC_ORIGIN_PRIMARY_MEMORY;
    break;
  case 0x0A: /*! Case service 0x0A*/
    /*! Set status mask to 0 */
    u8DTCStatusMask = (uint8)0;
    /*! Set DTC orgin to permanent memory */
    u8DTCOrigin = DEM_DTC_ORIGIN_PERMANENT_MEMORY;
    break;
  default:
    break;
  }
  /*! initialize response length to 0 */
  pMsgContext->resDataLen = (uint32)0;
  /*! Set the DTC Filter with the following parameters \n
      STATUS MASK: the calculated status mask \n
      DTC_KIND: DEM_DTC_KIND_EMISSION_REL_DTCS \n
      DTC_ORIGIN: the calculated DTC origin \n
      DTC_FILTER_WITH_SEVERITY: DEM_FILTER_WITH_SEVERITY_NO \n
      DTC_SEVERITY: DEM_SEVERITY_NO_SEVERITY \n
      FILTER_FOR_FDC: DEM_FILTER_FOR_FDC_NO */
  u8Return = Dem_SetDTCFilter(u8DTCStatusMask, DEM_DTC_KIND_EMISSION_REL_DTCS, 
      u8DTCOrigin, DEM_FILTER_WITH_SEVERITY_NO, 
      DEM_SEVERITY_NO_SEVERITY, DEM_FILTER_FOR_FDC_NO);

  /*! if the return type of SetDTCFilter equals DEM_FILTER_ACCEPTED */
  if (u8Return == DEM_FILTER_ACCEPTED)
  {
    /*! get the number of filtered DTCs by calling \n
        Dem_GetNumberOfFilteredDTC */
    u8ReturnNoOfDTC = Dem_GetNumberOfFilteredDTC(&u16NoOfDTCs);
    /*! if it returns OK, fill response message */
    if (u8ReturnNoOfDTC == DEM_NUMBER_OK)
    {
      /*! If Max. response length is less than 2*u16NoOfDTCs + 1 */
      if (DspInternal_apstreMsgContext[u8Context]->resMaxDataLen < 
        (uint32)((2*u16NoOfDTCs) + 1))
      {
        /*!  #if(DCM_PAGED_BUFFER_ENABLED == STD_ON) */
      #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
        /*! Initialize paged-buffer process */
        vidInitPageProcess(u8Context, u16NoOfDTCs, 0x03);
      #else
        /*! #Else, set negative response 0 */
        u8NegRes = DCM_u8E_SUPPRESS_RESPONSE;
      #endif
      }
      /*! Else (Max. response length >= than 2*u16NoOfDTCs + 1) */
      else
      {
        /*! Call vidFillDTCs */
        vidFillDTCs(u8Context, u16NoOfDTCs);
        /* !Deviation : Inhibit rule [2215]: Indentation level depends on
                        configuration                                       */
        /*! send processing done to Dsd */
        DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
        /* PRQA S 2215 --                                                   */
      }
    }
    /*! else if it returns PENDING */
    else if (u8ReturnNoOfDTC == DEM_NUMBER_PENDING)
    {
      /*! Set status to pending */
      DspInternal_au8eStatus[u8Context] = u8OBD_SVC_DTC_PENDING;
    }
    /*! else (returns DEM_NUMBER_FAILED), then set negative response 0 */
    else
    {
      u8NegRes = DCM_u8E_SUPPRESS_RESPONSE;
    }

  }
  /*! else (return type of SetDTCFilter equals DEM_WRONG_FILTER) */
  else
  {
    /*! Set negative reponse 0 */
    u8NegRes = DCM_u8E_SUPPRESS_RESPONSE;
  }
  if (u8NegRes != 0xFF)
  {
    /*! Set negative reponse 0 */
    DsdInternal_SetNegResponse(pMsgContext, u8NegRes);
    /*! send processing done to Dsd */
    DsdInternal_ProcessingDone(pMsgContext);
  }
}
/******************************************************************************/
/*! \Description Fills the reponse message with the DTCs' values \n
    \param[in]   u8Context
    \Range       0..(DspInternal_u8MAX_NUM_INTERNAL_REQ-1)
    \param[in]   No. of DTCs
    \Range       0..255
    \return      void.
    \Trace_To   CDD-0310(0), CDD-0311(0), CDD-0315(0)
*******************************************************************************/
static FUNC(void, DCM_CODE) vidFillDTCs(
    uint8 u8Context, uint16 u16NoOfDTCs)
{
  boolean                          bExit = FALSE;
  uint8                            u8Index;
  uint32                           u32DTC;
  uint8                            u8DTCStatus;
  Dem_ReturnGetNextFilteredDTCType udtReturn;

  /*! Set the length of the reponse message to 1 */
  DspInternal_apstreMsgContext[u8Context]->resDataLen = (uint32)1;
  /*! Loop for No. of filtered DTCs */
  for(u8Index = 0; (u8Index < u16NoOfDTCs) && (bExit == FALSE); u8Index++)
  {
    /*! Get next filtered DTC */
    udtReturn = Dem_GetNextFilteredDTC(&u32DTC, &u8DTCStatus);
    /*! If Dem_GetNextFilteredDTC returns DEM_FILTERED_OK */
    if (udtReturn == DEM_FILTERED_OK)
    {
      /*! fill the DTC high byte in the response */
      DspInternal_apstreMsgContext[u8Context]->
        resData[DspInternal_apstreMsgContext[u8Context]->resDataLen] = 
        (uint8)vidGET_DTC_HIGH_BYTE(u32DTC);
      /*! fill the DTC low byte in the response */
      DspInternal_apstreMsgContext[u8Context]->
        resData[DspInternal_apstreMsgContext[u8Context]->resDataLen + 1] = 
        (uint8)vidGET_DTC_LOW_BYTE(u32DTC);
      /*! increment the response length by 2 */
      DspInternal_apstreMsgContext[u8Context]->resDataLen += 2;
    }
    /* Else if Dem_GetNextFilteredDTC returns DEM_FILTERED_NO_MATCHING_DTC*/
    else if (udtReturn == DEM_FILTERED_NO_MATCHING_DTC)
    {
      /*! Set the first byte of the reponse by No. of DTCs */
      DspInternal_apstreMsgContext[u8Context]->resData[0] = u8Index;
      /*! Exit loop */
      bExit = TRUE;
    }
    /*! else (return value is DEM_FILTERED_WRONG_DTCKIND or 
        DEM_FILTERED_PENDING)*/
    else
    {
      /*! Send negative response DCM_u8E_SUPPRESS_RESPONSE to Dsd */
      DsdInternal_SetNegResponse(DspInternal_apstreMsgContext[u8Context], 
        DCM_u8E_SUPPRESS_RESPONSE);
      /*! and exit loop */
      bExit = TRUE;
    }
  }
  /*! Set the first byte to NoOfDTCs in case no exit condition happened */
  if (bExit == FALSE)
  {
    DspInternal_apstreMsgContext[u8Context]->resData[0] = (uint8)u16NoOfDTCs;
  }  
}
/******************************************************************************/
/*! \Description Main Function for OBD services (0x03, 0x07 and 0x0A). \n
    \param[in]   u8Context
    \Range       0..(DspInternal_u8MAX_NUM_INTERNAL_REQ-1)
    \return      void.
    \Trace_To    CDD-DSP-0107(0)
*******************************************************************************/
static FUNC(void,DCM_CODE) vidMainOBDSVCObtainDTC (uint8 u8Context)
{
  Dem_ReturnGetNumberOfFilteredDTCType u8ReturnNoOfDTC;
  uint16                               u16NoOfDTCs;
  uint8                                u8NegRes = 0xFF;
 
  /*! if there is cancel request */
  if (DspInternal_apstreMsgContext[u8Context]->msgAddInfo.cancelOperation == 1)
  {
    /*! Call Dem_DcmCancelOperation */
    Dem_DcmCancelOperation();
    /*! Set response length to 0 */
    DspInternal_apstreMsgContext[u8Context]->resDataLen = 0;
    /*! Set status to Idle */
    DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
    /*! Send processing done */
    DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
  }
  /*! Else: no Cancel request */
  else
  {
    /*! get the number of filtered DTCs by calling \n
        Dem_GetNumberOfFilteredDTC */
    u8ReturnNoOfDTC = Dem_GetNumberOfFilteredDTC(&u16NoOfDTCs);
    /*! if it returns OK */
    if (u8ReturnNoOfDTC == DEM_NUMBER_OK)
    {
      /*! If Max. response length is less than 2*u16NoOfDTCs + 1 */
      if (DspInternal_apstreMsgContext[u8Context]->resMaxDataLen < 
        (uint32)((2*u16NoOfDTCs) + 1))
      {
        /*!  #if(DCM_PAGED_BUFFER_ENABLED == STD_ON) */
      #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
        vidInitPageProcess(u8Context, u16NoOfDTCs, 0x03);
      #else
        /*! #Else, set negative response 0 */
        u8NegRes = DCM_u8E_SUPPRESS_RESPONSE;
      #endif
      }
      /*! Else (Max. response length >= than 2*u16NoOfDTCs + 1) */
      else
      {
        /*! Call vidFillDTCs */
        vidFillDTCs(u8Context, u16NoOfDTCs);
        /* !Deviation : Inhibit rule [2215]: Indentation level depends on
                        configuration                                       */
        /* PRQA S 2215 ++                                                   */
        /*! Set status to IDLE */
        DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
        /*! send processing done to Dsd */
        DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
        /* PRQA S 2215 --                                                   */
      }
    }
    /*! else if it returns PENDING, Do nothing */
    else if (u8ReturnNoOfDTC == DEM_NUMBER_PENDING)
    {

    }
    /*! else (NOT_OK), set negative response 0 */
    else
    {
      /*! Set negative reponse DCM_u8E_SUPPRESS_RESPONSE */
      u8NegRes = DCM_u8E_SUPPRESS_RESPONSE; 
    }
    if (u8NegRes != 0xFF)
    {
      DsdInternal_SetNegResponse(DspInternal_apstreMsgContext[u8Context], 
        DCM_u8E_SUPPRESS_RESPONSE);
      /*! Set status to Idle */
      DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
      /*! send processing done to Dsd */
      DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
    }
  }

}
#if (DCM_PAGED_BUFFER_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Processes the page buffer request for services 0x03, 0x07 and
                 0x0A \n
    \param[in]   u8Context
    \Range       0..(DspInternal_u8MAX_NUM_INTERNAL_REQ-1)
    \return      void.
    \Trace_To    CDD-DSP-0149(0), CDD-DSP-0150(0)
*******************************************************************************/
static FUNC(void, DCM_CODE) vidProcessPageDTCs(uint8 u8Context)
{
  /* !Deviation : Static is used because the variable is not used anywhere 
                  else and its value should be maintained                  */
  /* PRQA S 3223 ++                                                        */
  static uint32  LOC_u32CurrentResIdx = 1;
  static boolean LOC_bNoDtcs = FALSE;
  /* PRQA S 3223 --                                                        */
  uint32         u32Idx;
  uint32         u32DTC;
  uint8          u8DTCStatus;
  boolean        bExit = FALSE;
  uint32         u32StartIdx;
  uint32         u32EndIdx;
  Dem_ReturnGetNextFilteredDTCType 
                 udtReturnNext;

  /*! if there is cancel request */
  if (DspInternal_apstreMsgContext[u8Context]->msgAddInfo.cancelOperation == 1)
  {
    /*! Call Dem_DcmCancelOperation */
    Dem_DcmCancelOperation();
    /*! Reset global index */
    LOC_u32CurrentResIdx = 1;
    LOC_bNoDtcs = FALSE;
    /*! Set status to IDLE */
    DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
  }
  /*! Else (If no cancel request) */
  else
  {
    vidSetLoopLimits(LOC_u32CurrentResIdx, u8Context, &u32StartIdx, 
      &u32EndIdx);
    /*! if update page is called and no cancel page request is done */
    if(DspInternal_abePageUpdate[u8Context] == TRUE)
    {
      /*! reset update page flag */
      DspInternal_abePageUpdate[u8Context] = FALSE;
      /*! clear response bytes starting from current index 
        and with max. length*/
      /* !Deviation : Macros are needed for code readability 
                    and maintenance  */
      /* PRQA S 3361,2214 ++ */ 
      vidClrResBytes(u32StartIdx, 
        DspInternal_apstreMsgContext[u8Context]->resMaxDataLen, 
        DspInternal_apstreMsgContext[u8Context]->resData);
      /* PRQA S 3361,2214 -- */
      /*! loop for the max. length of the response message until we reach \n
          the total response length    */
      for(u32Idx = u32StartIdx; (u32Idx < u32EndIdx) && (bExit != TRUE); 
        u32Idx += 2)
      {
        if (LOC_u32CurrentResIdx < (DspInternal_apstreMsgContext[u8Context]->
            resDataLen - 1))
        {
          /*! If last call of Dem_GetNextFilteredDTC returns
              DEM_FILTERED_NO_MATCHING_DTC, do nothing */
          if (LOC_bNoDtcs != TRUE)
          {
            /*! Get next filtered DTC */
            udtReturnNext = Dem_GetNextFilteredDTC(&u32DTC, &u8DTCStatus);
            /*! If return = DEM_FILTERED_OK */
            if (udtReturnNext == DEM_FILTERED_OK)
            {
              /*! fill the DTC high byte in the response */
              DspInternal_apstreMsgContext[u8Context]->resData[u32Idx] = 
                  (uint8)vidGET_DTC_HIGH_BYTE(u32DTC);
              /*! fill the DTC low byte in the response */
              DspInternal_apstreMsgContext[u8Context]->resData[u32Idx+1] = 
                  (uint8)vidGET_DTC_LOW_BYTE(u32DTC);
              /*! incrment the response length by 2 */
              LOC_u32CurrentResIdx += 2;
            }
            /*! ElseIf return = DEM_FILTERED_NO_MATCHING_DTC, Exit loop and 
                process page with the max buffer length */
            else if (udtReturnNext == DEM_FILTERED_NO_MATCHING_DTC)
            {
              LOC_bNoDtcs = TRUE;
            }
            /*! Else return = DCM_FILTERED_WRONG_DTC, ignore this DTC */
            else
            {
              LOC_u32CurrentResIdx += 2;
            }
          }
          else
          {
            /*! incrment the response length by 2 */
            LOC_u32CurrentResIdx += 2;
          }
        }
        /*! if total response length is reached, exit loop */
        else
        {
          bExit = TRUE;
          LOC_u32CurrentResIdx = 1;
          LOC_bNoDtcs = FALSE;
          /*! call DsdInternal_ProcessPage with the current context and the \n
              length filled */
          DsdInternal_ProcessPage(u8Context, u32Idx);
          DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
        }
      }
      if ((bExit != TRUE) || (LOC_bNoDtcs == TRUE))
      {
        /*! call DsdInternal_ProcessPage with the current context and the \n
            length filled */
        DsdInternal_ProcessPage(u8Context, u32Idx);
      }
    }
  }
}
/******************************************************************************/
/*! \Description sets the loop start and end indexes
    \param[in]   u32Index
    \Range       0..4294967295
    \param[in]   u8Context
    \Range       0..(DspInternal_u8MAX_NUM_INTERNAL_REQ-1)
    \param[out]  p32StartIdx returned value of the starting index 
    \Range       0..4294967295
    \param[out]  p32EndIdx returned value of the end index
    \Range       0..4294967295
    \return      indicate whether the last result of Dem_GetNextFilteredDTC
                 returned DEM_FILTERED_NO_MATCHING_DTC or not.
    \Range       TRUE..FALSE 
*******************************************************************************/
static FUNC(void, DCM_CODE) vidSetLoopLimits(
  uint32 u32Index, uint8 u8Context,
  P2VAR(uint32, AUTOMATIC, DCM_VAR) pu32StartIdx,
  P2VAR(uint32, AUTOMATIC, DCM_VAR) pu32EndIdx)
{
 /*! Check if it is the first Page */
  if (u32Index == 1)
  {
    /*! Start the loop at 1 and end at 
        DspInternal_apstreMsgContext[u8Context]->resMaxDataLen - 1 */
    *pu32StartIdx = 1;
    *pu32EndIdx = DspInternal_apstreMsgContext[u8Context]->resMaxDataLen - 1;
  }
  /*! Else */
  else
  {
    /*! Start the loop at 1 and end at 
        DspInternal_apstreMsgContext[u8Context]->resMaxDataLen - 
      (DspInternal_apstreMsgContext[u8Context]->resMaxDataLen % 2  */
    *pu32StartIdx = 0;
    *pu32EndIdx = DspInternal_apstreMsgContext[u8Context]->resMaxDataLen - 
      (DspInternal_apstreMsgContext[u8Context]->resMaxDataLen % 2);
  }
}
/*******************************************************************************/
#endif /*! #if (DCM_PAGED_BUFFER_ENABLED == STD_ON) */

#endif /*! #if ((DCM_bOBD_SVC03_ENABLED == STD_ON)\
    ||(DCM_bOBD_SVC07_ENABLED == STD_ON)\
    ||(DCM_bOBD_SVC0A_ENABLED == STD_ON))*/


/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*              for memory allocation and should be included several times.  */ 
/* PRQA S 5087,0838 L1 */ 
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */
#endif /*! #if (DCM_bOBD_SERVICES_ENABLED == STD_ON)*/

/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*              for memory allocation and should be included several times.  */ 
/* PRQA S 5087,0838 L1 */ 
#define DCM_START_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */
#if (DCM_u8NUM_OBDMID > 0U)
/******************************************************************************/
/*! \Description Read Tid values of certain Mid \n
    \param[in]   u8MidIndex Current MID Index
    \Range       0..255
    \param[in]   u8TidIndex Current TID Index
    \Range       0..255
    \param[out]   pu8Buffer Current TID Index
    \Range       Not NULL
    \param[out]   pu16Index the last index filled in the buffer
    \Range       Not NULL
    \return      void.
*******************************************************************************/
static FUNC(void, DCM_CODE) vidReadTid(
  uint8 u8MidIndex, 
  uint8 u8TidIndex,
  P2VAR(uint8, AUTOMATIC, DCM_VAR) pu8Buffer,
  P2VAR(uint16, AUTOMATIC, DCM_VAR) pu16Index)
{
  uint16         u16TestValue;
  uint16         u16MinLimit;
  uint16         u16MaxLimit;
  uint8          u8Status;

  /*! Call the DTRRead function for this Test ID */
  (void)vidGET_READ_FUNC(u8MidIndex, u8TidIndex)(DCM_INITIAL, 
      &u16TestValue, &u16MinLimit, &u16MaxLimit, &u8Status);
  /*! If the return status is DCM_DTRSTATUS_VISIBLE, fill the response as \n
      follows: */
  if(u8Status == DCM_DTRSTATUS_VISIBLE)
  {
    /*! 1st Byte = OBDMID */
    pu8Buffer[*pu16Index] = Dcm_kstreDspConfig.
      astrDcmDspTestResultObdmidTid[u8MidIndex].u8DcmDspTestResultObdmid;
    /*! 2nd Byte = TID    */
    pu8Buffer[*pu16Index + 1] = 
        vidGET_TESTID(u8MidIndex, u8TidIndex);
    /*! 3rd Byte = Unit and Scaling ID */
    pu8Buffer[*pu16Index + 2] = 
        vidGET_SCALE_UNIT(u8MidIndex, u8TidIndex);
    /*! 4th Byte = High Byte of Test Value */
    pu8Buffer[*pu16Index + 3] = 
        vidSET_HIGH_BYTE(u16TestValue);
    /*! 5th Byte = Low Byte of Test Value */
    pu8Buffer[*pu16Index + 4] = 
        vidSET_LOW_BYTE(u16TestValue);
    /*! 6th Byte = High Byte of Min. Limit */
    pu8Buffer[*pu16Index + 5] = 
        vidSET_HIGH_BYTE(u16MinLimit);
    /*! 7th Byte = Low Byte of Min. Limit */
    pu8Buffer[*pu16Index + 6] = 
        vidSET_LOW_BYTE(u16MinLimit);
    /*! 8th Byte = High Byte of Max. Limit */
    pu8Buffer[*pu16Index + 7] = 
        vidSET_HIGH_BYTE(u16MaxLimit);
    /*! 9th Byte = Low Byte of Max. Limit */
    pu8Buffer[*pu16Index + 8] = 
        vidSET_LOW_BYTE(u16MaxLimit);
    /*! Increment the response length by 9 */
    *pu16Index += (uint16)u8OBD_SVC_06_INCREMENT;
  }
  /*! else (return Status equals DCM_DTRSTATUS_INVISIBLE), Do nothing */
  else
  {

  }
}
/*******************************************************************************/
/*! \Description Checks if the OBDMID is supported in Cfg.\n
    \param[in] u8OBDMID   Vehicle info. type \n
    \Range       0..255 \n
    \param[out] pu8Index  index of the OBDMID if found. \n
    \Range        0..255 \n
    \return      boolean. \n
    \Trace_To    CDD-DSP-0098(0)  */
/******************************************************************************/
FUNC(boolean, DCM_CODE) DspInternal_bIsSupportedOBDMID (
    uint8 u8OBDMID,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) pu8Index)
{
  uint8   u8Index;
  boolean bReturn = FALSE;
  /*! Loop for all MIDs */
  for (u8Index = 0; (u8Index < (uint8)DCM_u8NUM_OBDMID) && 
      (bReturn != TRUE); u8Index++)
  {
    /*! If the MID is found, save index and return */
    if(u8OBDMID == Dcm_kstreDspConfig.astrDcmDspTestResultObdmidTid[u8Index].
        u8DcmDspTestResultObdmid)
    {
      *pu8Index = u8Index;
      bReturn = TRUE;
    }
  }

  return bReturn;
}
/*******************************************************************************/
/*! \Description Fills the response of OBD service (0x06).\n
    \param[in] u8MID   OBDMID index \n
    \Range       0..255 \n
    \param[in] pu16BufferIndex   Index of buffer to start filling from \n
    \Range       0..65535 \n
    \param[out] pu16BufferIndex   last index of buffer filled \n
    \Range       0..65535 \n
    \param[in] pu8DataIndex   Index of data to start filling from \n
    \Range       0..65535 \n
    \param[out] pu8DataIndex   last index of data filled \n
    \Range       0..65535 \n
    \param[out] pu8Buffer  pointer to buffer to be filled. \n
    \Range        NOT NULL \n
    \param[in] u16MaxLength  Max. length to be filled  \n
    \Range        0..65535 \n
    \return      Std_ReturnType. \n
    \Range       E_OK, E_PAUSE \n
    \Trace_To    CDD-1130(0), CDD-DSP-0073(0), CDD-DSP-0063(0)    */
/******************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_udtReadMIDData(
    uint8 u8MID,
    P2VAR(uint16,AUTOMATIC,DCM_VAR) pu16BufferIndex, 
    P2VAR(uint8,AUTOMATIC,DCM_VAR) pu8DataIndex,
    P2VAR(uint8,AUTOMATIC,DCM_VAR) pu8Buffer,
    /* !Deviation : Inhibit rule [3206]: Usage of variable depends on 
                    configuration */
    /* PRQA S 3206 ++                                                   */
    uint16 u16MaxLength)
    /* PRQA S 3206 --                                                   */
{
  
  uint8          u8Index;
  /* !Deviation : Inhibit rule [3206]: Usage of variable depends on 
                  configuration */
  /* PRQA S 3204 ++                                                   */
  Std_ReturnType udtReadMidReturn = E_NOT_OK;
  /* PRQA S 3204 --                                                   */
  #if (DCM_PAGED_BUFFER_ENABLED == STD_ON)
  boolean        bExit = FALSE;
  #endif

  /*! Loop for all Tids corresponding to this MID */
  for(u8Index = *pu8DataIndex; (u8Index < Dcm_kstreDspConfig.
    astrDcmDspTestResultObdmidTid[u8MID].u8NumOfTids)
    #if (DCM_PAGED_BUFFER_ENABLED == STD_ON)
    && (bExit != TRUE)
    #endif
    ;u8Index++)
  {
#if (DCM_PAGED_BUFFER_ENABLED == STD_ON)
    /*! #if (DCM_PAGED_BUFFER_ENABLED == STD_ON) */
    /*! If (Current length + 9) <= Max Length */
    if ((uint16)(*pu16BufferIndex + u8OBD_SVC_06_INCREMENT) <= u16MaxLength)
    {
      /*! Incrment static data index */
      (*pu8DataIndex)++;
      /*! Read Tid Data */
      vidReadTid(u8MID, u8Index, pu8Buffer, pu16BufferIndex);
    }
    /*! Else */
    else
    {
      /*! Exit loop */
      bExit = TRUE;
      /*! Return E_PAUSE */
      udtReadMidReturn = E_PAUSE;
    }
#else
    vidReadTid(u8MID, u8Index, pu8Buffer, pu16BufferIndex);
    *pu8DataIndex = u8Index;
#endif
  }
#if (DCM_PAGED_BUFFER_ENABLED == STD_ON)
  if (bExit != TRUE)
  {
    udtReadMidReturn = E_OK;
  }
#endif
  return udtReadMidReturn;
}
#endif
#if(DCM_u8NUM_OF_PIDS > 0U)
/*******************************************************************************/
/*! \Description Calculates the total length of PID data\n
    \param[in] u8PidDataLen   PID data length \n
    \Range       0..255 \n
    \return      total length of PID \n
    \Range       0..65535 \n */
/******************************************************************************/
static FUNC (uint16, DCM_CODE) u16CalcTotalLength (uint16 u16PidDataLen)
{
  uint16 u16TotalLength;
  if (u16PidDataLen <= 8)
  {
    u16TotalLength = 8;
  }
  else if (u16PidDataLen <= 16)
  {
    u16TotalLength = 16;
  }
  else
  {
    u16TotalLength = 32;
  }
  return u16TotalLength;
}
/*******************************************************************************/
/*! \Description Reads PID data.\n
    \param[in] u8PIDIndex   Current PID index\n
    \Range       0..255 \n
    \param[in] udtOpStatus   Current Op. Status \n
    \Range       DCM_INITIAL, DCM_PENDING, DCM_CANCEL \n
    \param[in] pu16BufferIndex   Index of buffer to start filling from \n
    \Range       0..65535 \n
    \param[out] pu16BufferIndex   last index of buffer filled \n
    \Range       0..65535 \n
    \param[in] pu8DataIndex   Index of data to start filling from \n
    \Range       0..65535 \n
    \param[out] pu8DataIndex   last index of data filled \n
    \Range       0..65535 \n
    \param[out] pu8Buffer  pointer to buffer to be filled. \n
    \Range        NOT NULL \n
    \param[in] u16MaxLength  Max. length to be filled  \n
    \Range        0..65535 \n
    \return      Std_ReturnType. 
    \Range       E_OK, E_NOT_OK, E_PENDING. \n  
    \Trace_To     CDD-DSP-0070(0)   */
/******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This Service performs a lot of checks,   */
/*              so metrics for this service is not met.                       */
/* PRQA S 4700 ++                                                             */
FUNC(Std_ReturnType, DCM_CODE) DspInternal_udtReadPIDData (
  uint8 u8PIDIndex,
  Dcm_OpStatusType udtOpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_VAR) pu8Buffer,
  P2VAR(uint16,AUTOMATIC,DCM_VAR) pu16BufferIndex,
  P2VAR(uint8,AUTOMATIC,DCM_VAR) pu8DataIndex,
  uint8 u8Context)

{
  Std_ReturnType udtReadPIDReturn = E_OK;
  uint8          u8Index;
  uint8          u8BytePos;
  uint8          u8BitPos;
  uint8          au8DataContent[u8SVC01_MAX_DATA_LEN];
  boolean        bExitLoop = FALSE;
  uint16         u16DataSize;
  uint16         u16TotalLength;
  boolean        bEndian = FALSE;
  uint8          u8ProtocolIndex;

  u8ProtocolIndex = Dcm_pkstrePbConfig->strPbDcmDslConfig.
    pkstrDcmDslProtocolRx[DspInternal_apstreMsgContext[u8Context]->dcmRxPduId].
            u8DcmDslProtocolIndex;

  if (udtOpStatus == DCM_INITIAL)
  {
    /*! Fill the first byte by PID */
    pu8Buffer[*pu16BufferIndex] = 
      Dcm_kstreDspConfig.astrDcmDspPid[u8PIDIndex].u8DcmDspPidIdentifier;
    /*! Increment global response index */
    (*pu16BufferIndex)++;
    /*! If there are supported Info, set it in the buffer */
    if (Dcm_kstreDspConfig.astrDcmDspPid[u8PIDIndex].u8NumOfPidSupportInfo != 0)
    {
      vidSetSupportedInfo(u8PIDIndex, &pu8Buffer[*pu16BufferIndex]);
    }
  }
  
  /*! If Rte port is used for calling the application then, \n
       call the Rte interface, else call the configured function */
  for(u8Index = *pu8DataIndex; (u8Index < Dcm_kstreDspConfig.
    astrDcmDspPid[u8PIDIndex].u8NumOfPidData) 
    && (udtReadPIDReturn == E_OK) && (bExitLoop == FALSE); u8Index++)
  {
    switch(u8GET_SERV_OF_PIDDATA(u8PIDIndex, u8Index))
    {
    case USE_FNC:
      udtReadPIDReturn = Dcm_kstreDspConfig.astrDcmDspPid[u8PIDIndex].
        pkstrDcmDspPidData[u8Index].pkstrDcmDspPidService01->
        pfDcmDspDataReadFnc(au8DataContent);
      bEndian = FALSE;
      break;
    case USE_DATA_SYNCH_CLIENT_SERVER:
      udtReadPIDReturn = Dcm_kstreDspConfig.astrDcmDspPid[u8PIDIndex].
        pkstrDcmDspPidData[u8Index].pkstrDcmDspPidService01->
        pfDcmDspDataReadSync(au8DataContent);
      bEndian = FALSE;
      break;
    case USE_DATA_ASYNCH_CLIENT_SERVER:
      udtReadPIDReturn = Dcm_kstreDspConfig.astrDcmDspPid[u8PIDIndex].
        pkstrDcmDspPidData[u8Index].pkstrDcmDspPidService01->
        pfDcmDspDataReadAsync(udtOpStatus, au8DataContent);
      bEndian = FALSE;
      break;
    case USE_DATA_SENDER_RECEIVER:
      udtReadPIDReturn = Dcm_kstreDspConfig.astrDcmDspPid[u8PIDIndex].
        pkstrDcmDspPidData[u8Index].pkstrDcmDspPidService01->
        pfDcmDspDataReadSr(au8DataContent);
      bEndian = Dcm_kstreDslConfig.astrDcmDslProtocolRow[u8ProtocolIndex].
        bDcmDslProtocolEndiannessConvEnabled;
      break;
    default:
      break;
    }
    /*! if return E_PENDING */
    if (udtReadPIDReturn == E_PENDING)
    {
      /*! save current data index */
      *pu8DataIndex = u8Index;
    }
    /*! else if(Return E_OK) */
    else if (udtReadPIDReturn == E_OK)
    {
      
      u8BytePos = (uint8)u8GET_PID_DATA_BYTE(u8PIDIndex, u8Index);
      u8BitPos = (uint8)u8GET_PID_DATA_BIT(u8PIDIndex, u8Index);
      u16DataSize = Dcm_kstreDspConfig.astrDcmDspPid[u8PIDIndex].
        pkstrDcmDspPidData[u8Index].u16DcmDspPidDataSize;
      u16TotalLength = u16CalcTotalLength(u16DataSize);
      /*! Fill the buffer with the returned data */
      /* !Deviation : The value of "au8DataContent" is always set becuase the
                      default case is never entered */
      /* PRQA S 3354 ++                                                   */
      DspInternal_vidInjectSignalIntoBuff(au8DataContent, 
        &pu8Buffer[*pu16BufferIndex], (uint16)u8BytePos, u8BitPos, 
        u16DataSize, u16TotalLength, bEndian);
      /* PRQA S 3354 --                                                   */
    }
    /*! Else (Return E_NOT_OK), Do Nothing*/
    else
    {
    }
    /*! If OpStatus = DCM_CANCEL, Exit loop. */
    if (udtOpStatus == DCM_CANCEL)
    {
      bExitLoop = TRUE;
    }
  }
  /*! If all data are read, increment response buffer index for the next PID */
  if ((u8Index == Dcm_kstreDspConfig.astrDcmDspPid[u8PIDIndex].u8NumOfPidData)
      && (udtReadPIDReturn == E_OK))
  {
    *pu16BufferIndex += Dcm_kstreDspConfig.astrDcmDspPid[u8PIDIndex].
      u8DcmDspPidSize;
  }
  return udtReadPIDReturn;
}
/* PRQA S 4700 --                                                              */
/*******************************************************************************/
/*! \Description Checks if the given ID is supported in Cfg.\n
    \param[in] u8PID  the given ID \n
    \Range        0..255 \n
    \param[out] pu8PIDIndex  the index of PID if found \n
    \Range        0..255 \n
    \return      boolean. \n
    \Range       TRUE, FALSE  \n
    \Trace_To    CDD-DSP-0099(0)  */
/******************************************************************************/
FUNC(boolean, DCM_CODE) DspInternal_bIsPIDSupported (
    VAR(uint8, DCM_VAR) u8PID, 
    P2VAR(uint8, AUTOMATIC, DCM_VAR) pu8PIDIndex)
{
  uint8   u8Index;
  boolean bReturn = FALSE;
  /*! search for the given Id in the available PIDs */
  /* !Deviation : For Loop Only executed once because it is dependent on
                the configuration */
  /* PRQA S 2465 L1                                                        */
  for (u8Index = 0; (u8Index < Dsp_u8NumValidIds) && (bReturn != TRUE); 
      u8Index++)
  /* PRQA L:L1                                                             */
  {
    if (u8PID == Dcm_kstreDspConfig.astrDcmDspPid[Dsp_au8ValidIDs[u8Index]].
        u8DcmDspPidIdentifier)
    {
      *pu8PIDIndex = Dsp_au8ValidIDs[u8Index];
      bReturn = TRUE;
    }
  }
  return bReturn;
}

/*******************************************************************************/
/*! \Description Sets the supported info. in the response message.\n
    \param[in] u8PIDIndex   PID Index \n
    \Range       0..255  \n
    \param[in] pu8Buffer  Buffer to fill in the supported info. \n
    \Range        NOT NULL \n
    \return      void. */
/******************************************************************************/
static FUNC(void, DCM_CODE) vidSetSupportedInfo (
    VAR(uint8,DCM_VAR) u8PIDIndex, 
    P2VAR(uint8, AUTOMATIC, DCM_VAR) pu8Buffer)
{
  uint8 u8Index;
  for (u8Index = 0; u8Index < Dcm_kstreDspConfig.astrDcmDspPid[u8PIDIndex].
      u8NumOfPidSupportInfo; u8Index++)
  {
    pu8Buffer[u8GET_SUPPINFO_BYTE(u8PIDIndex, u8Index)] |= 
        (uint8)(u8GET_SUPPINFO_BIT(u8PIDIndex, u8Index));
  }
    
}
#endif
#if (DCM_u8NUM_OF_VEHICLE_INFO > 0U)
/*******************************************************************************/
/*! \Description Reads Vehicle Information data.\n
    \param[in] u8VehInfoIdx   Current vehicle info type index \n
    \Range       0..255 \n
    \param[in] udtOpStatus   Current Op. Status \n
    \Range       DCM_INITIAL, DCM_PENDING, DCM_CANCEL \n
    \param[in] pu16BufferIndex   Index of buffer to start filling from \n
    \Range       0..65535 \n
    \param[out] pu16BufferIndex   last index of buffer filled \n
    \Range       0..65535 \n
    \param[in] pu8DataIndex   Index of data to start filling from \n
    \Range       0..65535 \n
    \param[out] pu8DataIndex   last index of data filled \n
    \Range       0..65535 \n
    \param[out] pu8Buffer  pointer to buffer to be filled. \n
    \Range        NOT NULL \n
    \param[in] u32MaxResLen  Max. length to be filled  \n
    \Range        0..65535 \n
    \return      Std_ReturnType. 
    \Range       E_OK, E_NOT_OK, E_PENDING, E_PAUSE. \n  
    \Trace_To     CDD-DSP-0071(0)   */
/******************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_udtReadVehInfoData (
  uint8 u8VehInfoIdx,
  Dcm_OpStatusType udtOpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_VAR) pu8Buffer,
  P2VAR(uint16,AUTOMATIC,DCM_VAR) pu16BufferIndex,
  P2VAR(uint8,AUTOMATIC,DCM_VAR) pu8DataIndex,
  /* !Deviation : Inhibit rule [3206]: Usage of variable depends on 
                    configuration */
  /* PRQA S 3206 ++                                                   */
  uint32 u32MaxResLen)
  /* PRQA S 3206 --                                                   */
{
  Std_ReturnType udtReadInfoReturn = E_OK;
  uint8          u8Index;
  boolean        bExitLoop = FALSE;
  /*! If it is the first call */
  if ((udtOpStatus == DCM_INITIAL) && (*pu8DataIndex == 0))
  {
    /*! set the first byte of the response to Id of the Info. */
    pu8Buffer[0] = Dcm_kstreDspConfig.
     astrDcmDspVehInfo[u8VehInfoIdx].u8DcmDspVehInfoInfoType;
    /*! Set the second byte of response to number of info. Data */
    pu8Buffer[1] = Dcm_kstreDspConfig.
        astrDcmDspVehInfo[u8VehInfoIdx].u8NumVehInfoData;
    /*! increase response length by 2*/
    (*pu16BufferIndex) += 2;
  }
  /*! Loop for all data of this VehInfo */
  for(u8Index = *pu8DataIndex; (u8Index < Dcm_kstreDspConfig.
      astrDcmDspVehInfo[u8VehInfoIdx].u8NumVehInfoData) 
    && (udtReadInfoReturn == E_OK) && (bExitLoop == FALSE); u8Index++)
  {
#if (DCM_PAGED_BUFFER_ENABLED == STD_ON)
    /*! #if (DCM_PAGED_BUFFER_ENABLED == STD_ON) */
    /*! If the current data can fit in this page */
    if (((uint32)(*pu16BufferIndex
      + u8GET_VEHINFO_DATASIZE(u8VehInfoIdx, u8Index))
      <= u32MaxResLen) || (udtOpStatus == DCM_CANCEL))
    {
#endif
      /*! If Rte port is used for calling the application then, \n
       call the Rte interface, else call the configured function */
      /* !Deviation : Indentation depends on configuration */
      /* PRQA S 2215 ++                                         */
      if(Dcm_kstreDspConfig.astrDcmDspVehInfo[u8VehInfoIdx].
          pkstrDcmDspVehInfoData[u8Index].bDcmDspVehInfoDataUsePort
          == TRUE)
      {
        udtReadInfoReturn = 
            Dcm_kstreDspConfig.astrDcmDspVehInfo[u8VehInfoIdx].
            pkstrDcmDspVehInfoData[u8Index].
            pfDcmDspVehInfoDataReadPort(udtOpStatus, 
            &pu8Buffer[*pu16BufferIndex]);
      }
      else
      {
        udtReadInfoReturn = 
        Dcm_kstreDspConfig.astrDcmDspVehInfo[u8VehInfoIdx].
            pkstrDcmDspVehInfoData[u8Index].
            pfDcmDspVehInfoDataReadFnc(udtOpStatus, 
            &pu8Buffer[*pu16BufferIndex]);
      }
      /*! if return E_PENDING */
      if (udtReadInfoReturn == E_PENDING)
      {
        /*! save current data index */
        *pu8DataIndex = u8Index;
      }
      /*! else if(Return E_OK), increment response index by \n
          size of current info data, and set opStatus to INITIAL    */
      else if (udtReadInfoReturn == E_OK)
      {
        *pu16BufferIndex += 
            u8GET_VEHINFO_DATASIZE(u8VehInfoIdx, u8Index);
        udtOpStatus = DCM_INITIAL;
      }
      /*! Else (Return E_NOT_OK)*/
      else
      {
      #if(DCM_DEV_ERROR_DETECT == STD_ON)
        /*! Report DET with DCM_E_INTERFACE_VALUE_OUT_OF_RANGE */
        Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID, 
          Dcm_u8OBD_SERVICE_09_ID, DCM_E_INTERFACE_VALUE_OUT_OF_RANGE);
      #endif
      }
      /* PRQA S 2215 --                                         */
#if (DCM_PAGED_BUFFER_ENABLED == STD_ON)
    }
    else
    {
      udtReadInfoReturn = E_PAUSE;
      *pu8DataIndex = u8Index;
      bExitLoop = TRUE;
    }
#endif
    if (udtOpStatus == DCM_CANCEL)
    {
      bExitLoop = TRUE;
    }
  }
  return udtReadInfoReturn;
}
/*******************************************************************************/
/*! \Description Checks if the given vehicle info. is supported in Cfg.\n
    \param[in] u8VehInfoType   Vehicle info. type \n
    \Range       0..255 \n
    \return      boolean. \n
    \Range       TRUE, FALSE  \n
    \Trace_To    CDD-DSP-0100(0)  */
/******************************************************************************/
FUNC(boolean, DCM_CODE) DspInternal_bIsSupportedVehInfo (
    uint8 u8VehInfoType,
    P2VAR(uint8,AUTOMATIC,DCM_VAR) pu8VehInfoIdx)
{
  uint8   u8Index;
  boolean bReturn = FALSE;
  /* !Deviation : For Loop Only executed once because it is dependent on
                the configuration */
  /* PRQA S 2465 L1                                                        */
  for (u8Index = 0; (u8Index < (uint8)DCM_u8NUM_OF_VEHICLE_INFO) && 
      (bReturn != TRUE); u8Index++)
  /* PRQA L:L1                                                             */
  {
    if(u8VehInfoType == Dcm_kstreDspConfig.astrDcmDspVehInfo[u8Index].
        u8DcmDspVehInfoInfoType)
    {
      *pu8VehInfoIdx = u8Index;
      bReturn = TRUE;
    }
  }

  return bReturn;
}
#endif
#if ((DCM_bOBD_SERVICES_ENABLED == STD_ON) || (DCM_bRDBI_EN == STD_ON))
/*******************************************************************************/
/*! \Description Sets the availablity response message.\n
    \param[in] pku8InBuffer   Input buffer. \n
    \Range       NOT NULL  \n
    \param[in] u8BufInLength   Input buffer length. \n
    \Range       1..6  \n
    \param[out] pu8OutBuffer   Output buffer. \n
    \Range       NOT NULL  \n
    \param[out] pu16BufOutLength   output buffer length to be filled. \n
    \Range       0..65535 \n
    \param[in] u8ServiceID  current service ID \n
    \Range      0x01..0x0A \n
    \return      void   \n
    \Trace_To   CDD-0314(0), CDD-0317(0), CDD-0318(0), CDD-0322(0), CDD-0323(0),
                CDD-0343(0), CDD-0345(0), CDD-0346(0), CDD-0348(0),CDD-0350(0),
                CDD-0354(0), CDD-1107(0), CDD-1116(0), CDD-1129(0), CDD-1132(0),
                CDD-1136(0), CDD-3023(0), CDD-DSP-0169(0), CDD-DSP-0172(0) 
******************************************************************************/
FUNC(void, DCM_CODE) DspInternal_vidSetAvailablRes(
    P2CONST(uint8,AUTOMATIC,DCM_VAR) pku8InBuffer,
    uint8 u8BufInLength,
    P2VAR(uint8,AUTOMATIC,DCM_VAR) pu8OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR) pu16BufOutLength,
    uint8 u8ServiceID)
{
  uint8   u8NumIDs;
  uint8   u8AvID;
  uint8   u8SupID;
  uint8   u8CurrentID;
  sint8   s8PrevIndex;
  uint8   u8LoopInc;
  uint8   u8LastBitSet;
  /* !Deviation : Local initilization is used instead of for loop for 
                  optimization  */
  /* PRQA S 3604++ */
  boolean abFirstDetected[u8OBD_SVC_MAX_REQ_LEN] = 
  {
    TRUE, TRUE, TRUE,TRUE, TRUE, TRUE
  };
  /* PRQA S 3604-- */
  /*! If it is service 0x02 */
  if(u8ServiceID == 0x02)
  {
    s8PrevIndex = -2;
    /*! Increment outer loop by 2 */
    u8LoopInc = 2;
    /*! Clear bytes in the reponse message */
    vidClrResBytes(0, (uint32)((u8BufInLength / 2) * 6), pu8OutBuffer);
  }
  /*! Else (Any other service) */
  else
  {
    s8PrevIndex = -1;
    /*! Increment outer loop by 1 */
    u8LoopInc = 1;
    /*! Clear bytes in the reponse message */
    vidClrResBytes(0, (uint32)(u8BufInLength * 5), pu8OutBuffer);
  }
  /*! Set the number of IDs according to the current service */
  u8NumIDs = u8GetErrorORNumID(u8ServiceID, TRUE);
  /*! for all availability IDs in the request message */
  for(u8AvID = 0; u8AvID < u8BufInLength; u8AvID += u8LoopInc)
  {
    /*Clear u8LastBitSet for this availability ID*/
    u8LastBitSet = FALSE; 
#if(DCM_bOBD_SVC02_ENABLED == STD_ON)
    /*! If this is service 0x02 and second byte doesn't equal 0, 
        ignore this PID */
    if ((u8ServiceID == 0x02) && 
      (pku8InBuffer[u8AvID + 1] != u8DEFAULT_FREEZE_FRAME))
    {
    }
    else
    {
#endif
      /*! For all configured IDs */
      for(u8SupID = 0; u8SupID < u8NumIDs; u8SupID++)
      {
        u8CurrentID = u8SetIDValue(u8ServiceID, u8SupID);        
        /*! If the current ID belongs to an availabilty ID 
            or belongs to another availability ID and greater  
            than the current one*/
        if ((bIS_BELONGTO_AVID(pku8InBuffer[u8AvID], u8CurrentID) ==
            TRUE) || ((u8LastBitSet == FALSE) &&
            (u8CurrentID > pku8InBuffer[u8AvID])))
        {
          /*! respond to unsupported PIDs if subsequent ranges have \n
              a supported PID(s). */
          if ((u8AvID - s8PrevIndex) > u8LoopInc)
          {
            vidInsertAvIDs(s8PrevIndex, u8AvID, u8ServiceID, pku8InBuffer, 
              pu8OutBuffer);
          }
          /*! If ID detected for the first time */
          if (abFirstDetected[u8AvID] == TRUE)
          {
            /*! Set the availability ID in the response message */
            pu8OutBuffer[*pu16BufOutLength] = pku8InBuffer[u8AvID];
            /*! set the global response index for the next \n
                availabiulity ID */
            #if(DCM_bOBD_SVC02_ENABLED == STD_ON)
            /*! If it is service 0x02, inject FF 0x00 into the response */
            if (u8ServiceID == 0x02)
            {
              pu8OutBuffer[*pu16BufOutLength + 1] = 
                u8DEFAULT_FREEZE_FRAME;
              (*pu16BufOutLength)++;
            }
            #endif
            *pu16BufOutLength += u16AVAILABLE_INCREMENT;
            /*! save the last detected ID */
            s8PrevIndex = (sint8)u8AvID;
            abFirstDetected[u8AvID] = FALSE;            
          }
          if (bIS_BELONGTO_AVID(pku8InBuffer[u8AvID], u8CurrentID) ==
            TRUE)
          {
            /*! set the bit corresponding to the current ID in the \n
                 response message */
            vidSET_AVAILABILITY_BIT(*pu16BufOutLength - u16AVAILABLE_INCREMENT,
                     (u8CurrentID - pku8InBuffer[u8AvID]));
          }
          else
          {
            /*! set the last bit  in the response message */
            vidSET_AVAILABILITY_BIT(*pu16BufOutLength - u16AVAILABLE_INCREMENT,
               u8LAST_BIT_POSITION);
            u8LastBitSet = TRUE;
          }
        }        
      } 
    #if(DCM_bOBD_SVC02_ENABLED == STD_ON)
    }
    #endif
  }
}
/*******************************************************************************/
/*! \Description Inserts availability IDs in the response message .\n
    \param[in] u8PrevIdx  lower limit index of IDs to be inserted. \n
    \Range        0..255 \n
    \param[in] u8CurrentIdx  upper limit index of IDs to be inserted. \n
    \Range        0..255 \n
    \param[in] u8ServiceID  current service ID \n
    \Range      0x01..0x0A \n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void. */
/******************************************************************************/
static FUNC(void, DCM_CODE) vidInsertAvIDs(
    sint8 s8PrevIdx, uint8 u8CurrentIdx, uint8 u8ServiceID,
    P2CONST(uint8,AUTOMATIC,DCM_VAR) pku8InBuffer,
    P2VAR(uint8,AUTOMATIC,DCM_VAR) pu8OutBuffer)
{
  uint8 u8Index;
  uint8 u8LoopInc;
  /*! If current service = 0x02, increment loop by 2. 
      Else, increment loop by 1 */
  if (u8ServiceID == 0x02)
  {
    u8LoopInc = 2;
  }
  else
  {
    u8LoopInc = 1;
  }

  for (u8Index = (uint8)(s8PrevIdx+u8LoopInc); u8Index < u8CurrentIdx;
       u8Index += u8LoopInc)
  {
    #if(DCM_bOBD_SVC02_ENABLED == STD_ON)
    if (u8ServiceID == 0x02 && pku8InBuffer[u8Index+1] != u8DEFAULT_FREEZE_FRAME)
    {
      /*Do nothing*/
    }
    else
    {
    #endif
      pu8OutBuffer[Dsp_u16ResMsgIndex] = pku8InBuffer[u8Index];
    /*! If it is service 0x02, inject FF 0x00 into the response */
#if(DCM_bOBD_SVC02_ENABLED == STD_ON)
    if (u8ServiceID == 0x02)
    {
      pu8OutBuffer[Dsp_u16ResMsgIndex + 1] = u8DEFAULT_FREEZE_FRAME;
      Dsp_u16ResMsgIndex++;
    }
#endif
    Dsp_u16ResMsgIndex += u16AVAILABLE_INCREMENT;
  }
    #if(DCM_bOBD_SVC02_ENABLED == STD_ON)
    }
    #endif
}
/*******************************************************************************/
/*! \Description Sets the error ID according to the current service.\n
    \param[in] u8ServiceID   Pointer to the MsgContext structure. \n
    \Range       0x01, 0x02, 0x06, 0x08, 0x09  \n
    param[in] bChoice   Flag to indicate ErrorID (FALSE) or NUM (TRUE). \n
    \Range       TRUE, FALSE  \n
    \return      Error or NUM ID. 
    \Range       0..255     */
/******************************************************************************/
static FUNC(uint8, DCM_CODE) u8GetErrorORNumID(uint8 u8ServiceID, boolean bChoice)
{
  uint8   u8ID = 0;
  switch (u8ServiceID)
  {
#if (DCM_u8NUM_OF_PIDS > 0U)
  case 0x01:
    u8ID = (uint8)u8GET_ERROR_OR_NUM(bChoice, Dsp_u8NumValidIds, Dcm_u8OBD_SERVICE_01_ID);
    break;
  case 0x02:
    u8ID = (uint8)u8GET_ERROR_OR_NUM(bChoice, Dsp_u8NumValidIds, Dcm_u8OBD_SERVICE_02_ID);
    break;
#endif
#if(DCM_u8NUM_OBDMID > 0U)
  case 0x06:
    u8ID = u8GET_ERROR_OR_NUM(bChoice, (uint8)DCM_u8NUM_OBDMID, Dcm_u8OBD_SERVICE_06_ID);
    break;
#endif
#if(DCM_u8NUM_RC_TIDS > 0U)
  case 0x08:
    u8ID = u8GET_ERROR_OR_NUM(bChoice, (uint8)DCM_u8NUM_RC_TIDS, Dcm_u8OBD_SERVICE_08_ID);
    break;
#endif
#if(DCM_u8NUM_OF_VEHICLE_INFO > 0U)
  case 0x09:
    u8ID = u8GET_ERROR_OR_NUM(bChoice, (uint8)DCM_u8NUM_OF_VEHICLE_INFO, 
      Dcm_u8OBD_SERVICE_09_ID);
    break;
#endif

  default:
    break;
  }
  return u8ID;
}
/******************************************************************************/
/*! \Description Clears response bytes \n
    \param[in]   u32Start   Start index to start clear from
    \Range       0..
    \param[in]   u32Length   Length To clear
    \Range       0..65535
    \param[in]   pMsgContext   Message context
    \Range       Not Null
    \return      void.
*******************************************************************************/
static FUNC(void, DCM_CODE) vidClrResBytes(
  uint32 u32Start, uint32 u32Length, 
  P2VAR(uint8, AUTOMATIC, DCM_APPL_CODE) pu8Buffer)
{
  uint32 u32Index; 
  for(u32Index = u32Start; u32Index < u32Length; u32Index++)
  {
    pu8Buffer[u32Index] = (uint8)0; 
  }
}
/*******************************************************************************/
/*! \Description Sets the Service ID according to the passed service.\n
    \param[in] u8ServiceID   ID of current service \n
    \Range       0..255  \n
    \param[out] u8SupID  index of current requested ID \n
    \Range        0..255 \n
    \return      uint8. */
/******************************************************************************/
static FUNC(uint8, DCM_CODE) u8SetIDValue(uint8 u8ServiceID, uint8 u8SupID)
{
  uint8 u8CurrentID = 0;
  switch(u8ServiceID)
  {
#if (DCM_u8NUM_OF_PIDS > 0U)
  case 0x01:
  case 0x02:
    u8CurrentID = Dcm_kstreDspConfig.
            astrDcmDspPid[Dsp_au8ValidIDs[u8SupID]].u8DcmDspPidIdentifier;
    break;
#endif
#if(DCM_u8NUM_OBDMID > 0U)
  case 0x06:
    u8CurrentID = Dcm_kstreDspConfig.astrDcmDspTestResultObdmidTid[u8SupID].
        u8DcmDspTestResultObdmid;
    break;
#endif
#if(DCM_u8NUM_RC_TIDS > 0U)
  case 0x08:
    u8CurrentID = Dcm_kstreDspConfig.astrDcmDspRequestControl[u8SupID].
        u8DcmDspRequestControlTestId;
    break;
#endif
#if(DCM_u8NUM_OF_VEHICLE_INFO > 0U)
  case 0x09:
    u8CurrentID = Dcm_kstreDspConfig.astrDcmDspVehInfo[u8SupID].
        u8DcmDspVehInfoInfoType;
    break;
#endif
  default:
    break;
  }
  return u8CurrentID;
}
#endif
/******************************************************************************/
/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*              for memory allocation and should be included several times.  */ 
/* PRQA S 5087,0838 L1 */ 
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */
/** \} */ /* end of DSP module group */
/** \} */ /* end of DSP Component group */
/*-------------------------------- end of file -------------------------------*/
