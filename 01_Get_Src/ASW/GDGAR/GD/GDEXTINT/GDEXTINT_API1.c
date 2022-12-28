/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GDEXTINT                                                */
/* !Description     : GDEXTINT Component                                      */
/*                                                                            */
/* !Module          : GDEXTINT                                                */
/* !Description     : GD EXTERNAL INTERFACE                                   */
/*                                                                            */
/* !File            : GDEXTINT_API1.C                                         */
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
/*   1 / Dem_SetEventStatus                                                   */
/*   2 / Dem_GetEventStatus                                                   */
/*   3 / Dem_DisableDTCSetting                                                */
/*   4 / Dem_EnableDTCSetting                                                 */
/*   5 / Dem_DisableDTCRecordUpdate                                           */
/*   6 / Dem_EnableDTCRecordUpdate                                            */
/*   7 / Dem_ClearDTC                                                         */
/*   8 / Dem_SetDTCFilter                                                     */
/*   9 / Dem_GetNumberOfFilteredDTC                                           */
/*   10 / Dem_GetNextFilteredDTC                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5075312 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GDEXTINT/GDEXTINT_API1.C_v   $*/
/* $Revision::   1.12     $$Author::   mbenfrad       $$Date::   27 Aug 2013 $*/
/* $Author::   mbenfrad                               $$Date::   27 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "GDExtInt.h"
#include "GDExtInt_L.h"
#include "GDExtInt_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_SetEventStatus                                         */
/* !Description :  Set the status of an Event                                 */
/* !Number      :  API1.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GDEXTINT_SetEventStatus(argin uint16          */
/*  u16DftIdx, argin uint8 u8EventStatus);                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType Dem_SetEventStatus
(
   uint16 u16DftIdx,
   uint8 u8EventStatus
)
{
   Std_ReturnType udtLocalOut;


   udtLocalOut = GDEXTINT_SetEventStatus(u16DftIdx, u8EventStatus);

   return(udtLocalOut);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_GetEventStatus                                         */
/* !Description :  Gets the current extended event status of an event         */
/* !Number      :  API1.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GDEXTINT_GetEventStatus(argin uint16          */
/*  u16DftIdx, argin uint8 *u8EventStatusExtended);                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType Dem_GetEventStatus
(
   uint16 u16DftIdx,
   uint8* u8EventStatusExtended
)
{
   Std_ReturnType udtLocalOut;


   udtLocalOut = GDEXTINT_GetEventStatus(u16DftIdx, u8EventStatusExtended);

   return(udtLocalOut);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_DisableDTCSetting                                      */
/* !Description :  Disables the DTC setting for a DTC group.                  */
/* !Number      :  API1.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Dem_ReturnControlDTCSettingType                               */
/*  GDEXTINT_DisableDTCSetting(argin Dem_DTCGroupType u32DTCGroup, argin      */
/*  Dem_DTCKindType u8DTCKind);                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dem_ReturnControlDTCSettingType Dem_DisableDTCSetting
(
   Dem_DTCGroupType u32DTCGroup,
   Dem_DTCKindType u8DTCKind
)
{
   Dem_ReturnControlDTCSettingType udtLocalOut;


   udtLocalOut = GDEXTINT_DisableDTCSetting(u32DTCGroup, u8DTCKind);

   return(udtLocalOut);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_EnableDTCSetting                                       */
/* !Description :  Enables the DTC setting for a DTC group.                   */
/* !Number      :  API1.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Dem_ReturnControlDTCSettingType                               */
/*  GDEXTINT_EnableDTCSetting(argin Dem_DTCGroupType u32DTCGroup, argin       */
/*  Dem_DTCKindType u8DTCKind);                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dem_ReturnControlDTCSettingType Dem_EnableDTCSetting
(
   Dem_DTCGroupType u32DTCGroup,
   Dem_DTCKindType u8DTCKind
)
{
   Dem_ReturnControlDTCSettingType udtLocalOut;


   udtLocalOut = GDEXTINT_EnableDTCSetting(u32DTCGroup, u8DTCKind);

   return(udtLocalOut);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_DisableDTCRecordUpdate                                 */
/* !Description :  Disables the DTC record update.                            */
/* !Number      :  API1.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GDEXTINT_DisableDTCRecordUpdate();            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType Dem_DisableDTCRecordUpdate(void)
{
   Std_ReturnType udtLocalOut;


   udtLocalOut = GDEXTINT_DisableDTCRecordUpdate();

   return(udtLocalOut);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_EnableDTCRecordUpdate                                  */
/* !Description :  Enables the DTC record update.                             */
/* !Number      :  API1.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GDEXTINT_EnableDTCRecordUpdate();             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType Dem_EnableDTCRecordUpdate(void)
{
   Std_ReturnType udtLocalOut;


   udtLocalOut = GDEXTINT_EnableDTCRecordUpdate();

   return(udtLocalOut);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_ClearDTC                                               */
/* !Description :  Clears single DTCs as well as groups of DTCs. This API can */
/*                 only be used  through the RTE, and therefore no declaration*/
/*                 is exported via Dem.h.                                     */
/* !Number      :  API1.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Dem_ReturnClearDTCType  GDEXTINT_ClearDTC(argin uint32 u32DTC,*/
/*  argin Dem_DTCKindType u8DTCKind, argin Dem_DTCOriginType u8DTCOrigin);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dem_ReturnClearDTCType Dem_ClearDTC
(
   uint32 u32DTC,
   Dem_DTCKindType u8DTCKind,
   Dem_DTCOriginType u8DTCOrigin
)
{
   Dem_ReturnClearDTCType udtLocalOut;


   udtLocalOut = GDEXTINT_ClearDTC(u32DTC, u8DTCKind, u8DTCOrigin);

   return(udtLocalOut);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_SetDTCFilter                                           */
/* !Description :  The server shall perform a bit-wise logical AND-ing        */
/*                 operation between the mask  specified in the client's      */
/*                 request and the actual status associated with each DTC     */
/*                 supported by the server.                                   */
/* !Number      :  API1.8                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Dem_ReturnSetDTCFilterType  GDEXTINT_SetDTCFilter(argin uint8 */
/*  u8DTCStatusMask, argin Dem_DTCKindType u8DTCKind, argin Dem_DTCOriginType */
/*  u8DTCOrigin, argin Dem_FilterWithSeverityType u8FilterWithSeverity, argin */
/*  Dem_DTCSeverityType u8DTCSeverityMask, argin Dem_FilterForFDCType         */
/*  u8FilterForFaultDetectionCounter);                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dem_ReturnSetDTCFilterType Dem_SetDTCFilter
(
   uint8 u8DTCStatusMask,
   Dem_DTCKindType u8DTCKind,
   Dem_DTCOriginType u8DTCOrigin,
   Dem_FilterWithSeverityType u8FilterWithSeverity,
   Dem_DTCSeverityType u8DTCSeverityMask,
   Dem_FilterForFDCType u8FilterForFaultDetectionCounter
)
{
   Dem_ReturnSetDTCFilterType udtLocalOut;


   udtLocalOut = GDEXTINT_SetDTCFilter(u8DTCStatusMask,
                                       u8DTCKind,
                                       u8DTCOrigin,
                                       u8FilterWithSeverity,
                                       u8DTCSeverityMask,
                                       u8FilterForFaultDetectionCounter);

   return(udtLocalOut);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_GetNumberOfFilteredDTC                                 */
/* !Description :  Gets the number of a filtered DTC.                         */
/* !Number      :  API1.9                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Dem_ReturnGetNumberOfFilteredDTCType                          */
/*  GDEXTINT_GetNumberOfFilteredDTC(argin uint16 *u16NumberOfFilteredDTC);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dem_ReturnGetNumberOfFilteredDTCType Dem_GetNumberOfFilteredDTC
(
   uint16* u16NumberOfFilteredDTC
)
{
   Dem_ReturnGetNumberOfFilteredDTCType udtLocalOut;


   udtLocalOut = GDEXTINT_GetNumberOfFilteredDTC(u16NumberOfFilteredDTC);

   return(udtLocalOut);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_GetNextFilteredDTC                                     */
/* !Description :  Gets the next filtered DTC.                                */
/* !Number      :  API1.10                                                    */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Dem_ReturnGetNextFilteredDTCType                              */
/*  GDEXTINT_GetNextFilteredDTC(argin uint32 *u32DTC, argin uint8             */
/*  *u8DTCStatus);                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dem_ReturnGetNextFilteredDTCType Dem_GetNextFilteredDTC
(
   uint32* u32DTC,
   uint8* u8DTCStatus
)
{
   Dem_ReturnGetNextFilteredDTCType udtLocalOut;


   udtLocalOut = GDEXTINT_GetNextFilteredDTC(u32DTC, u8DTCStatus);

   return(udtLocalOut);
}
/*------------------------------- end of file --------------------------------*/