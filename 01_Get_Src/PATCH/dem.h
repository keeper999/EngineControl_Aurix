/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* !File            : Dem.h                                                   */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : Service Layer                                           */
/*                                                                            */
/* !Component       : Dcm                                                     */
/* !Description     : Dcm                                                     */
/*                                                                            */
/* !Module          : Dcm                                                     */
/* !Description     : Dcm                                                     */
/*                                                                            */
/* !File            : Dem.h                                                   */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/*                                                                            */
/* COPYRIGHT 2010 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/

#ifndef DEM_H_
#define DEM_H_

#include "STD_TYPES.h"
#include "DCM_MANU.h"
#include "DCM_MANU_L.h"
#include "DCM_MANU_IM.h"

#define Rte_Call_DcmIf_ClearDTC Dem_ClearDTC

typedef uint8 Dem_ReturnSetFilterType;
typedef enum 
{
/* Mandatory For NvM : these define must exist */
   NVM_E_REQ_FAILED,
   NVM_E_WRONG_BLOCK_ID,
   NVM_E_INTEGRITY_FAILED,
   NVM_E_VERIFY_FAILED,
/* End of Mandatory For NvM */

/* Must exist if Dem_ReportErrorStatus is a function */
/* For NvM */
   NVM_udtE_BLK_PENDING_PROD,
   NVM_E_QUEUE_OVERFLOW,
   NVM_udtE_BGND_OVERFLOW_PROD,
   NVM_udtE_INVALID_STATE_PROD,
   NVM_E_LOSS_OF_REDUNDANCY,
   NVM_E_WRITE_PROTECTED,
   NVM_udtE_NV_BLK_ACCESS_PROD
/* End NvM */
} Dem_EventIdType;
/*typedef uint8 Dem_ReturnSetDTCFilterType;*/
/*#define DEM_FILTER_ACCEPTED                        0x00*/
/*#define DEM_WRONG_FILTER                           0x01*/

/*typedef uint8 Dem_FilterWithSeverityType;*/
#define DEM_FILTER_WITH_SEVERITY_YES               0x00
/*#define DEM_FILTER_WITH_SEVERITY_NO                0x01*/

/*typedef uint8 Dem_DTCSeverityType;*/
/*#define DEM_SEVERITY_NO_SEVERITY                   0x00*/
#define DEM_SEVERITY_MAINTENANCE_ONLY              0x20
#define DEM_SEVERITY_CHECK_AT_NEXT_HALT            0x40
#define DEM_SEVERITY_CHECK_IMMEDIATELY             0x80

/*typedef uint8 Dem_FilterForFDCType;*/
#define DEM_FILTER_FOR_FDC_YES                     0x00
/*#define DEM_FILTER_FOR_FDC_NO                      0x01*/

/*typedef uint8 Dem_ReturnGetNumberOfFilteredDTCType;*/
/*#define DEM_NUMBER_OK                              0x00*/
/*#define DEM_NUMBER_FAILED                          0x01*/
#define DEM_NUMBER_PENDING                         0x02

/*typedef uint8 Dem_ReturnGetNextFilteredDTCType;*/
/*#define DEM_FILTERED_OK                            0x00*/
/*#define DEM_FILTERED_NO_MATCHING_DTC               0x01*/
#define DEM_FILTERED_WRONG_DTCKIND                 0x02
#define DEM_FILTERED_PENDING                       0x03

/*typedef uint8 Dem_ReturnGetSizeOfFreezeFrameByDTCType;*/
/*#define DEM_GET_SIZEOFFF_OK                        0x00*/
/*#define DEM_GET_SIZEOFFF_WRONG_DTC                 0x01*/
/*#define DEM_GET_SIZEOFFF_WRONG_DTCOR               0x02*/
/*#define DEM_GET_SIZEOFFF_WRONG_DTCKIND             0x03*/
/*#define DEM_GET_SIZEOFFF_WRONG_RNUM                0x04*/
/*#define DEM_GET_SIZEOFFF_PENDING                   0x05*/

/*typedef uint8 Dem_ReturnGetFreezeFrameDataByDTCType;*/
/*#define DEM_GET_FFDATABYDTC_OK                     0x00*/
/*#define DEM_GET_FFDATABYDTC_WRONG_DTC              0x01*/
/*#define DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN        0x02*/
/*#define DEM_GET_FFDATABYDTC_WRONG_DTCKIND          0x03*/
/*#define DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER     0x04*/
/*#define DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE       0x05*/
#define DEM_GET_FFDATABYDTC_PENDING                0x06

/*typedef uint8 Dem_ReturnGetStatusOfDTCType;*/
/*#define DEM_STATUS_OK                              0x00*/
/*#define DEM_STATUS_WRONG_DTC                       0x01*/
/*#define DEM_STATUS_WRONG_DTCORIGIN                 0x02*/
/*#define DEM_STATUS_WRONG_DTCKIND                   0x03*/
#define DEM_STATUS_FAILED                          0x04

/*typedef uint8 Dem_ReturnClearDTCType;*/
/*#define DEM_CLEAR_OK                               0x00*/
/*#define DEM_CLEAR_WRONG_DTC                        0x01*/
/*#define DEM_CLEAR_WRONG_DTCORIGIN                  0x02*/
/*#define DEM_CLEAR_WRONG_DTCKIND                    0x03*/
/*#define DEM_CLEAR_FAILED                           0x04*/
#define DEM_CLEAR_PENDING                          0x05

/*typedef uint8 Dem_DTCKindType;*/
/*#define DEM_DTC_KIND_ALL_DTCS                      0x01*/
#define DEM_DTC_KIND_EMISSION_REL_DTCS             0x02

/*typedef uint8 Dem_DTCOriginType;*/
/*#define DEM_DTC_ORIGIN_PRIMARY_MEMORY              0x01*/
#define DEM_DTC_ORIGIN_MIRROR_MEMORY               0x02
#define DEM_DTC_ORIGIN_PERMANENT_MEMORY            0x03
#define DEM_DTC_ORIGIN_SECONDARY_MEMORY            0x04

typedef uint8 Dem_ReturnGetDTCByOccurrenceTimeType;
#define DEM_OCCURR_OK                              0x00
#define DEM_OCCURR_WRONG_DTCKIND                   0x01
#define DEM_OCCURR_FAILED                          0x02

typedef uint8 Dem_DTCRequestType;
#define DEM_FIRST_FAILED_DTC                       0x01
#define DEM_MOST_RECENT_FAILED_DTC                 0x02
#define DEM_FIRST_DET_CONFIRMED_DTC                0x03
#define DEM_MOST_REC_DET_CONFIRMED_DTC             0x04

typedef uint8 Dem_ReturnGetFreezeFrameDataByRecordType;
#define DEM_GET_FFBYRECORD_OK                      0x00
#define DEM_GET_FFBYRECORD_WRONG_RECORD            0x01
#define DEM_GET_FFBYRECORD_NO_DTC_FOR_RECORD       0x02
#define DEM_GET_FFBYRECORD_WRONG_DTCKIND           0x03

typedef uint8 Dem_ReturnGetSeverityOfDTCType;
#define DEM_GET_SEVERITYOFDTC_OK                   0x00
#define DEM_GET_SEVERITYOFDTC_WRONG_DTC            0x01
#define DEM_GET_SEVERITYOFDTC_WRONG_DTCORIGIN      0x02
#define DEM_GET_SEVERITYOFDTC_NOSEVERITY           0x03

typedef uint8 Dem_ReturnGetFunctionalUnitOfDTCType;
/*#define DEM_GET_SEVERITYOFDTC_OK                   0x00*/
#define DEM_GET_SEVERITYOFDTC_WRONG_DTC            0x01

typedef uint8 Dem_ReturnGetSizeOfExtendedDataRecordByDTCType;
#define DEM_GET_SIZEOFEDRBYDTC_OK                  0x00
#define DEM_GET_SIZEOFEDRBYDTC_W_DTC               0x01
#define DEM_GET_SIZEOFEDRBYDTC_W_DTCOR             0x02
#define DEM_GET_SIZEOFEDRBYDTC_W_DTCKI             0x03
#define DEM_GET_SIZEOFEDRBYDTC_W_RNUM              0x04
#define DEM_GET_SIZEOFEDRBYDTC_PENDING             0x05

typedef uint8 Dem_DTCTranslationFormatType;
#define DEM_DTC_TRANSLATION_ISO15031_6             0x00
#define DEM_DTC_TRANSLATION_ISO14229_1             0x01
#define DEM_DTC_TRANSLATION_SAEJ1939_73            0x02
#define DEM_DTC_TRANSLATION_ISO11992_4             0x03

typedef uint8 Dem_ReturnGetExtendedDataRecordByDTCType;
#define DEM_RECORD_OK                              0x00
#define DEM_RECORD_WRONG_DTC                       0x01
#define DEM_RECORD_WRONG_DTCORIGIN                 0x02
#define DEM_RECORD_WRONG_DTCKIND                   0x03
#define DEM_RECORD_WRONG_NUMBER                    0x04
#define DEM_RECORD_WRONG_BUFFERSIZE                0x05
#define DEM_RECORD_PENDING                         0x06

/*typedef uint8 Dem_ReturnControlDTCSettingType;*/
/*#define DEM_CONTROL_DTC_SETTING_OK                 0x00*/
#define DEM_CONTROL_DTC_SETTING_N_OK               0x01
/*#define DEM_CONTROL_DTC_WRONG_DTCGROUP             0x02*/

/*typedef uint32 Dem_DTCGroupType;*/
#define DEM_DTC_GROUP_EMISSION_REL_DTCS            0x000000
#define DEM_DTC_GROUP_BODY_DTCS
#define DEM_DTC_GROUP_CHASSIS_DTCS
#define DEM_DTC_GROUP_NETWORK_COM_DTCS
#define DEM_DTC_GROUP_POWERTRAIN_DTCS
/*#define DEM_DTC_GROUP_ALL_DTCS                     0xFFFFFF*/


#ifndef DEM_EVENT_STATUS_FAILED
/** \brief Monitor reports qualified test result failed */
#define DEM_EVENT_STATUS_FAILED      0x01U
#endif

#ifndef DEM_EVENT_STATUS_PASSED
/** \brief Monitor reports qualified test result passed */
#define DEM_EVENT_STATUS_PASSED      0x00U
#endif

#define PDUR_E_INIT_FAILED 0x28U
#define CANIF_E_NOT_SLEEP 19U
#define DEM_EVENT_STATUS_PREFAILED   0x03U
extern void Dem_DcmCancelOperation(void);

extern Dem_ReturnClearDTCType Dem_ClearDTC
(
   uint32 DTC,
   Dem_DTCKindType DTCKind,
   Dem_DTCOriginType DTCOrigin
);

extern Dem_ReturnSetFilterType Dem_SetDTCFilter
(
   uint8 DTCStatusMask,
   Dem_DTCKindType DTCKind,
   Dem_DTCOriginType DTCOrigin,
   Dem_FilterWithSeverityType FilterWithSeverity,
   Dem_DTCSeverityType DTCSeverityMask,
   Dem_FilterForFDCType FilterForFaultDetectionCounter
);

extern Dem_ReturnGetDTCByOccurrenceTimeType Dem_GetDTCByOccurrenceTime
(
   Dem_DTCRequestType DTCRequest,
   Dem_DTCKindType DTCKind,
   uint32* DTC
);

extern Dem_ReturnGetStatusOfDTCType Dem_GetStatusOfDTC
(
   uint32 DTC,
   Dem_DTCKindType DTCKind,
   Dem_DTCOriginType DTCOrigin,
   uint8* DTCStatus
);

extern Std_ReturnType Dem_DisableDTCRecordUpdate(void);

extern Dem_ReturnGetFreezeFrameDataByRecordType Dem_GetFreezeFrameDataByRecord
(
   uint8 RecordNumber,
   Dem_DTCOriginType DTCOrigin,
   Dem_DTCKindType DTCKind,
   uint32* DTC,
   uint8* DestBuffer,
   uint16* BufSize
);

extern Dem_ReturnGetSeverityOfDTCType Dem_GetSeverityOfDTC
(
   uint32 DTC,
   Dem_DTCSeverityType* DTCSeverity
);

extern Dem_ReturnGetFunctionalUnitOfDTCType Dem_GetFunctionalUnitOfDTC
(
   uint32 DTC,
   uint8* DTCFunctionalUnit
);

extern Dem_ReturnGetSizeOfExtendedDataRecordByDTCType
   Dem_GetSizeOfExtendedDataRecordByDTC
(
   uint32 DTC,
   Dem_DTCKindType DTCKind,
   Dem_DTCOriginType DTCOrigin,
   uint8 ExtendedDataNumber,
   uint16* SizeOfExtendedDataRecord
);

extern Std_ReturnType Dem_EnableDTCRecordUpdate(void);

extern Dem_ReturnSetFilterType Dem_SetFreezeFrameRecordFilter
(
   uint16* NumberOfFilteredRecords
);

extern Dem_ReturnGetNumberOfFilteredDTCType Dem_GetNumberOfFilteredDTC
(
   uint16* NumberOfFilteredDTC
);

extern Dem_ReturnGetNextFilteredDTCType Dem_GetNextFilteredDTCAndSeverity
(
   uint32* DTC,
   uint8* DTCStatus,
   Dem_DTCSeverityType* DTCSeverity,
   uint8* DTCFunctionalUnit
);

extern Dem_ReturnGetNextFilteredDTCType Dem_GetNextFilteredRecord
(
   uint32* DTC,
   uint8* RecordNumber
);

extern Dem_ReturnGetNextFilteredDTCType Dem_GetNextFilteredDTCAndFDC
(
   uint32* DTC,
   sint8* DTCFaultDetectionCounter
);

extern Dem_ReturnGetNextFilteredDTCType Dem_GetNextFilteredDTC
(
   uint32* DTC,
   uint8* DTCStatus
);

extern Std_ReturnType Dem_GetDTCStatusAvailabilityMask( uint8* DTCStatusMask );

extern Dem_DTCTranslationFormatType Dem_GetTranslationType(void);

extern Dem_ReturnGetSizeOfFreezeFrameByDTCType Dem_GetSizeOfFreezeFrameByDTC
(
   uint32 DTC,
   Dem_DTCKindType DTCKind,
   Dem_DTCOriginType DTCOrigin,
   uint8 RecordNumber,
   uint16* SizeOfFreezeFrame
);

extern Dem_ReturnGetFreezeFrameDataByDTCType Dem_GetFreezeFrameDataByDTC
(
   uint32 DTC,
   Dem_DTCKindType DTCKind,
   Dem_DTCOriginType DTCOrigin,
   uint8 RecordNumber,
   uint8* DestBuffer,
   uint16* BufSize
);

extern Dem_ReturnGetExtendedDataRecordByDTCType Dem_GetExtendedDataRecordByDTC
(
   uint32 DTC,
   Dem_DTCKindType DTCKind,
   Dem_DTCOriginType DTCOrigin,
   uint8 ExtendedDataNumber,
   uint8* DestBuffer,
   uint16* BufSize
);

extern Dem_ReturnControlDTCSettingType Dem_DisableDTCSetting
(
   Dem_DTCGroupType DTCGroup,
   Dem_DTCKindType DTCKind
);

extern Dem_ReturnControlDTCSettingType Dem_EnableDTCSetting
(
   Dem_DTCGroupType DTCGroup,
   Dem_DTCKindType DTCKind
);

extern Std_ReturnType Dem_ReadDataOfOBDFreezeFrame
(
	uint8 PID,
	uint8 DataElementIndexOfPID,
	uint8* DestBuffer,
	uint8* BufSize
);

extern Std_ReturnType Dem_GetDTCOfOBDFreezeFrame(
	uint8 FrameNumber,
	uint32* DTC
);

#endif /* DEM_H_ */
/*-------------------------------- end of file -------------------------------*/
