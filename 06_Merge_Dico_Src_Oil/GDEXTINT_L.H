/***************************************************************************
;**
;** FILE NAME      : GDEXTINT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef GDEXTINT_L_H
#define GDEXTINT_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define GD_IDXDFTFILT_LNS                     ( 30 )
#define GD_IDXDFTFILT_COLS                     ( 2 )

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean GD_bInhDft;
extern uint8 GD_ctDftFilt;
extern uint8 GD_ctDftNxtFilt;
extern uint8 GD_idxDftFilt[GD_IDXDFTFILT_LNS][GD_IDXDFTFILT_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Dem_DcmCancelOperation(void);
Std_ReturnType GDEXTINT_DcmReadDataOfPID01(uint8* u8PID01value);
Std_ReturnType GDEXTINT_GetDTCOfOBDFreezeFrame(uint8 u8FrameNumber, uint32* u32DTC);
Std_ReturnType GDEXTINT_ReadDataOfOBDFreezeFrame(uint8 u8PID,uint8 u8DataElementIndexOfPID,uint8* u8DestBuffer, uint8* u8BufSize);
void GDEXTINT_vidEveRst_GDExtInt(void);
void GDEXTINT_vidRstEventSt(void);
void GDEXTINT_vidSetEventSt(uint16 u16IdxDft);
void GDEXTINT_vidSetEventSt_reinit(uint16 u16IdxDft);
Std_ReturnType GDEXTINT_DisableDTCRecordUpdate(void);
Std_ReturnType GDEXTINT_EnableDTCRecordUpdate(void);
uint8 GDEXTINT_GetTranslationType(void);
Dem_ReturnClearDTCType GDEXTINT_ClearDTC(uint32 u32DTC, Dem_DTCKindType u8DTCKind, Dem_DTCOriginType u8DTCOrigin);
Dem_ReturnControlDTCSettingType GDEXTINT_DisableDTCSetting(Dem_DTCGroupType u32DTCGroup, Dem_DTCKindType u8DTCKind);
Dem_ReturnControlDTCSettingType GDEXTINT_EnableDTCSetting(Dem_DTCGroupType u32DTCGroup, Dem_DTCKindType u8DTCKind);
Std_ReturnType GDEXTINT_GetDTCStatAvailbltyMask(uint8  *u8DTCStatusMask);
Std_ReturnType GDEXTINT_GetEventStatus(uint16 u16DftIdx, uint8  *u8EventStatusExtended);
Dem_ReturnGetNextFilteredDTCType GDEXTINT_GetNextFilteredDTC(uint32  *u32DTC, uint8  *u8DTCStatus);
Dem_ReturnGetNumberOfFilteredDTCType GDEXTINT_GetNumberOfFilteredDTC(uint16  *u16NumberOfFilteredDTC);
Dem_ReturnGetStatusOfDTCType GDEXTINT_GetStatusOfDTC(uint32 u32DTC, Dem_DTCKindType u8DTCKind, Dem_DTCOriginType u8DTCOrigin, uint8  *u8DTCStatus);
Dem_ReturnSetDTCFilterType GDEXTINT_SetDTCFilter(uint8 u8DTCStatusMask, Dem_DTCKindType u8DTCKind, Dem_DTCOriginType u8DTCOrigin, Dem_FilterWithSeverityType u8FilterWithSeverity, Dem_DTCSeverityType u8DTCSeverityMask, Dem_FilterForFDCType u8FilterForFaultDetectionCounter);
Std_ReturnType GDEXTINT_SetEventStatus(uint16 u16DftIdx, uint8 u8EventStatus);
Dem_ReturnGetFreezeFrameDataByDTCType GDEXTINT_GetFreezeFrameDataByDTC(uint32 u32DTC, Dem_DTCKindType u8DTCKind, Dem_DTCOriginType u8DTCOrigin, uint8 u8RecordNumber, uint8  *u8DestBuffer, uint16  *u16BufSize);
void GDEXTINT_GetFreezeFrameDataByD1(uint8 u8LocalIdx, uint16 u16LocalIndPanne, uint8  *u8DestBuffer);
Dem_ReturnGetSizeOfFreezeFrameByDTCType GDEXTINT_GetSizeOfFrzeFrameByDTC(uint32 u32DTC, Dem_DTCKindType u8DTCKind, Dem_DTCOriginType u8DTCOrigin, uint8 u8RecordNumber, uint16  *u16SizeOfFreezeFrame);


#endif /* GDEXTINT_L_H */

/*-------------------------------- end of file -------------------------------*/
