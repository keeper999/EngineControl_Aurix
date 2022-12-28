/***************************************************************************
;**
;** FILE NAME      : GDEXTINT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef GDEXTINT_H
#define GDEXTINT_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define DEM_CLEAR_FAILED                  4
#define DEM_CLEAR_OK                      0
#define DEM_CLEAR_WRONG_DTC               1
#define DEM_CLEAR_WRONG_DTCKIND           3
#define DEM_CLEAR_WRONG_DTCORIGIN         2
#define DEM_CONTROL_DTC_SETTING_OK        0
#define DEM_CONTROL_DTC_WRONG_DTCGROUP    2
#define DEM_DTC_GROUP_ALL_DTCS            16777215
#define DEM_DTC_KIND_ALL_DTCS             1
#define DEM_DTC_ORIGIN_PRIMARY_MEMORY     1
#define DEM_FILTER_ACCEPTED               0
#define DEM_FILTER_FOR_FDC_NO             1
#define DEM_FILTER_WITH_SEVERITY_NO       1
#define DEM_FILTERED_NO_MATCHING_DTC      1
#define DEM_FILTERED_OK                   0
#define DEM_GET_FFDATABYDTC_OK            0
#define DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE  5
#define DEM_GET_FFDATABYDTC_WRONG_DTC     1
#define DEM_GET_FFDATABYDTC_WRONG_DTCKIND  3
#define DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN  2
#define DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER  4
#define DEM_GET_SIZEOFFF_OK               0
#define DEM_GET_SIZEOFFF_PENDING          5
#define DEM_GET_SIZEOFFF_WRONG_DTC        1
#define DEM_GET_SIZEOFFF_WRONG_DTCKIND    3
#define DEM_GET_SIZEOFFF_WRONG_DTCOR      2
#define DEM_GET_SIZEOFFF_WRONG_RNUM       4
#define DEM_NUMBER_FAILED                 1
#define DEM_NUMBER_OK                     0
#define DEM_SEVERITY_NO_SEVERITY          0
#define DEM_STATUS_OK                     0
#define DEM_STATUS_WRONG_DTC              1
#define DEM_STATUS_WRONG_DTCKIND          3
#define DEM_STATUS_WRONG_DTCORIGIN        2
#define DEM_TYPE_OF_DTC_SUPPORTED         0
#define DEM_WRONG_FILTER                  1
#define GD_FAILED                         1
#define GD_INIT                           32
#define GD_PASSED                         0
#define GD_PRE_FAILED                     3
#define GD_PRE_PASSED                     2
#define GD_STEVENTSTATUS_LNS                  ( 972 )
#define U8STATUSOLD_LNS                       ( 972 )

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

typedef uint32 Dem_DTCGroupType;
typedef uint8 Dem_DTCKindType;
typedef uint8 Dem_DTCOriginType;
typedef uint8 Dem_DTCSeverityType;
typedef uint8 Dem_FilterForFDCType;
typedef uint8 Dem_FilterWithSeverityType;
typedef uint8 Dem_ReturnClearDTCType;
typedef uint8 Dem_ReturnControlDTCSettingType;
typedef uint8 Dem_ReturnGetFreezeFrameDataByDTCType;
typedef uint8 Dem_ReturnGetNextFilteredDTCType;
typedef uint8 Dem_ReturnGetNumberOfFilteredDTCType;
typedef uint8 Dem_ReturnGetSizeOfFreezeFrameByDTCType;
typedef uint8 Dem_ReturnGetStatusOfDTCType;
typedef uint8 Dem_ReturnSetDTCFilterType;
/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  GD_bEnaRstProtOutObd_C;
extern const uint8  GD_bfAvlRdy_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean GD_bInhFrfRec;
extern uint8 GD_stEventStatus[GD_STEVENTSTATUS_LNS];
extern uint8 u8StatusOld[U8STATUSOLD_LNS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

Std_ReturnType Dem_DcmReadDataOfPID01(uint8* u8PID01value);
void Dem_Init(void);
Std_ReturnType Dem_ReadDataOfOBDFreezeFrame(uint8 u8PID,uint8 u8DataElementIndexOfPID,uint8* u8DestBuffer, uint8* u8BufSize);
void GD_RstEventSt(void);
void GD_SetEventSt(uint16 u16IdxDft);
void GD_SetEventSt_reinit(uint16 u16IdxDft);
Std_ReturnType Dem_DisableDTCRecordUpdate(void);
Std_ReturnType Dem_EnableDTCRecordUpdate(void);
uint8 Dem_GetTranslationType(void);
Dem_ReturnClearDTCType Dem_ClearDTC(uint32 u32DTC, Dem_DTCKindType u8DTCKind, Dem_DTCOriginType u8DTCOrigin);
Dem_ReturnControlDTCSettingType Dem_DisableDTCSetting(Dem_DTCGroupType u32DTCGroup, Dem_DTCKindType u8DTCKind);
Dem_ReturnControlDTCSettingType Dem_EnableDTCSetting(Dem_DTCGroupType u32DTCGroup, Dem_DTCKindType u8DTCKind);
Std_ReturnType Dem_GetDTCStatusAvailabilityMask(uint8  *u8DTCStatusMask);
Std_ReturnType Dem_GetEventStatus(uint16 u16DftIdx, uint8  *u8EventStatusExtended);
Dem_ReturnGetNextFilteredDTCType Dem_GetNextFilteredDTC(uint32  *u32DTC, uint8  *u8DTCStatus);
Dem_ReturnGetNumberOfFilteredDTCType Dem_GetNumberOfFilteredDTC(uint16  *u16NumberOfFilteredDTC);
Dem_ReturnGetStatusOfDTCType Dem_GetStatusOfDTC(uint32 u32DTC, Dem_DTCKindType u8DTCKind, Dem_DTCOriginType u8DTCOrigin, uint8  *u8DTCStatus);
Dem_ReturnSetDTCFilterType Dem_SetDTCFilter(uint8 u8DTCStatusMask, Dem_DTCKindType u8DTCKind, Dem_DTCOriginType u8DTCOrigin, Dem_FilterWithSeverityType u8FilterWithSeverity, Dem_DTCSeverityType u8DTCSeverityMask, Dem_FilterForFDCType u8FilterForFaultDetectionCounter);
Std_ReturnType Dem_SetEventStatus(uint16 u16DftIdx, uint8 u8EventStatus);
Dem_ReturnGetFreezeFrameDataByDTCType Dem_GetFreezeFrameDataByDTC(uint32 u32DTC, Dem_DTCKindType u8DTCKind, Dem_DTCOriginType u8DTCOrigin, uint8 u8RecordNumber, uint8  *u8DestBuffer, uint16  *u16BufSize);
Dem_ReturnGetSizeOfFreezeFrameByDTCType Dem_GetSizeOfFreezeFrameByDTC(uint32 u32DTC, Dem_DTCKindType u8DTCKind, Dem_DTCOriginType u8DTCOrigin, uint8 u8RecordNumber, uint16  *u16SizeOfFreezeFrame);


#endif /* GDEXTINT_H */

/*-------------------------------- end of file -------------------------------*/
