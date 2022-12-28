/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DCM_MANU                                                */
/* !Description     : DCM_MANU Component                                      */
/*                                                                            */
/* !Module          : DCM_MANU                                                */
/* !Description     : Code Manuel du DCM                                      */
/*                                                                            */
/* !File            : Dem_Stub.c                                              */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / Dem_DcmCancelOperation                                               */
/*   2 / Dem_ClearDTC                                                         */
/*   3 / Rte_Call_DcmIf_ClearDTC                                              */
/*   4 / Dem_SetDTCFilter                                                     */
/*   5 / Dem_GetDTCByOccurrenceTime                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_5074345 / 4                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/Dem$*/
/* $Revision::   1.2      $$Author::   pbakabad       $$Date::   22 May 2014 $*/
/* $Author::   pbakabad                               $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "DCM_MANU.h"
#include "DCM_MANU_L.h"
#include "DCM_MANU_IM.h"
#include "DEM.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_GetDTCByOccurrenceTime                                 */
/* !Description :  Fonction d'effacement des défauts                          */
/* !Number      :  Dem_Stub.5                                                 */
/* !Author      :  VGAR                                                       */
/* !Trace_To    :  VEMS_R_11_02667_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
Dem_ReturnGetDTCByOccurrenceTimeType Dem_GetDTCByOccurrenceTime
(
   Dem_DTCRequestType DTCRequest,
   Dem_DTCKindType DTCKind,
   uint32* DTC
)
{
   return DEM_OCCURR_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_GetFreezeFrameDataByRecord                             */
/* !Description :  Fonction d'effacement des défauts                          */
/* !Number      :  Dem_Stub.6                                                 */
/* !Author      :  VGAR                                                       */
/* !Trace_To    :  VEMS_R_11_02667_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
Dem_ReturnGetFreezeFrameDataByRecordType Dem_GetFreezeFrameDataByRecord
(
   uint8 RecordNumber,
   Dem_DTCOriginType DTCOrigin,
   Dem_DTCKindType DTCKind,
   uint32* DTC,
   uint8* DestBuffer,
   uint16* BufSize
)
{
   return DEM_GET_FFBYRECORD_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_GetSeverityOfDTC                                       */
/* !Description :  Fonction d'effacement des défauts                          */
/* !Number      :  Dem_Stub.6                                                 */
/* !Author      :  VGAR                                                       */
/* !Trace_To    :  VEMS_R_11_02667_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
Dem_ReturnGetSeverityOfDTCType Dem_GetSeverityOfDTC
(
   uint32 DTC,
   Dem_DTCSeverityType* DTCSeverity
)
{
   return DEM_GET_SEVERITYOFDTC_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_GetFunctionalUnitOfDTC                                 */
/* !Description :  Fonction d'effacement des défauts                          */
/* !Number      :  Dem_Stub.6                                                 */
/* !Author      :  VGAR                                                       */
/* !Trace_To    :  VEMS_R_11_02667_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
Dem_ReturnGetFunctionalUnitOfDTCType Dem_GetFunctionalUnitOfDTC
(
   uint32 DTC,
   uint8* DTCFunctionalUnit
)
{
   return DEM_GET_SEVERITYOFDTC_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_GetSizeOfExtendedDataRecordByDTC                       */
/* !Description :  Fonction d'effacement des défauts                          */
/* !Number      :  Dem_Stub.6                                                 */
/* !Author      :  VGAR                                                       */
/* !Trace_To    :  VEMS_R_11_02667_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
Dem_ReturnGetSizeOfExtendedDataRecordByDTCType
   Dem_GetSizeOfExtendedDataRecordByDTC
(
   uint32 DTC,
   Dem_DTCKindType DTCKind,
   Dem_DTCOriginType DTCOrigin,
   uint8 ExtendedDataNumber,
   uint16* SizeOfExtendedDataRecord
)
{
   return DEM_GET_SIZEOFEDRBYDTC_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_SetFreezeFrameRecordFilter                             */
/* !Description :  Fonction d'effacement des défauts                          */
/* !Number      :  Dem_Stub.6                                                 */
/* !Author      :  VGAR                                                       */
/* !Trace_To    :  VEMS_R_11_02667_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
Dem_ReturnSetFilterType Dem_SetFreezeFrameRecordFilter
(
   uint16* NumberOfFilteredRecords
)
{
   return DEM_FILTER_ACCEPTED;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_GetNextFilteredDTCAndSeverity                          */
/* !Description :  Fonction d'effacement des défauts                          */
/* !Number      :  Dem_Stub.6                                                 */
/* !Author      :  VGAR                                                       */
/* !Trace_To    :  VEMS_R_11_02667_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
Dem_ReturnGetNextFilteredDTCType Dem_GetNextFilteredDTCAndSeverity
(
   uint32* DTC,
   uint8* DTCStatus,
   Dem_DTCSeverityType* DTCSeverity,
   uint8* DTCFunctionalUnit
)
{
   return DEM_FILTERED_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_GetNextFilteredRecord                                  */
/* !Description :  Fonction d'effacement des défauts                          */
/* !Number      :  Dem_Stub.6                                                 */
/* !Author      :  VGAR                                                       */
/* !Trace_To    :  VEMS_R_11_02667_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
Dem_ReturnGetNextFilteredDTCType Dem_GetNextFilteredRecord
(
   uint32* DTC,
   uint8* RecordNumber
)
{
   return DEM_FILTERED_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_GetNextFilteredDTCAndFDC                               */
/* !Description :  Fonction d'effacement des défauts                          */
/* !Number      :  Dem_Stub.6                                                 */
/* !Author      :  VGAR                                                       */
/* !Trace_To    :  VEMS_R_11_02667_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
Dem_ReturnGetNextFilteredDTCType Dem_GetNextFilteredDTCAndFDC
(
   uint32* DTC,
   sint8* DTCFaultDetectionCounter
)
{
   return DEM_FILTERED_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_GetExtendedDataRecordByDTC                             */
/* !Description :  Fonction d'effacement des défauts                          */
/* !Number      :  Dem_Stub.6                                                 */
/* !Author      :  VGAR                                                       */
/* !Trace_To    :  VEMS_R_11_02667_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
Dem_ReturnGetExtendedDataRecordByDTCType Dem_GetExtendedDataRecordByDTC
(
   uint32 DTC,
   Dem_DTCKindType DTCKind,
   Dem_DTCOriginType DTCOrigin,
   uint8 ExtendedDataNumber,
   uint8* DestBuffer,
   uint16* BufSize
)
{
   return DEM_RECORD_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_DCM_MANU_StubServiceAftS                                */
/* !Description :  Fonction mappant les APIs pour les services UDS type       */
/*                 Client-Serveur                                             */
/* !Number      :  Dem_Stub.7                                                 */
/* !Author      :  PBAK                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
void RE_DCM_MANU_StubServiceAftS(void)
{

}