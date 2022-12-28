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
/* !File            : GDEXTINT_API2.C                                         */
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
/*   1 / Dem_GetStatusOfDTC                                                   */
/*   2 / Dem_GetSizeOfFreezeFrameByDTC                                        */
/*   3 / Dem_GetFreezeFrameDataByDTC                                          */
/*   4 / Dem_GetDTCStatusAvailabilityMask                                     */
/*   5 / Dem_GetTranslationType                                               */
/*   6 / Dem_GetDTCOfOBDFreezeFrame                                           */
/*   7 / Dem_ReadDataOfOBDFreezeFrame                                         */
/*   8 / Dem_DcmReadDataOfPID01                                               */
/*   9 / GD_SetEventSt                                                        */
/*   10 / Dem_DcmCancelOperation                                              */
/*   11 / GD_SetEventSt_reinit                                                */
/*   12 / GD_RstEventSt                                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5075312 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GDEXTINT/GDEXTINT_API2.C_v   $*/
/* $Revision::   1.13     $$Author::   mbenfrad       $$Date::   27 Aug 2013 $*/
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
/* !Function    :  Dem_GetStatusOfDTC                                         */
/* !Description :  Gets the status of a DTC.                                  */
/* !Number      :  API2.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Dem_ReturnGetStatusOfDTCType  GDEXTINT_GetStatusOfDTC(argin   */
/*  uint32 u32DTC, argin Dem_DTCKindType u8DTCKind, argin Dem_DTCOriginType   */
/*  u8DTCOrigin, argin uint8 *u8DTCStatus);                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dem_ReturnGetStatusOfDTCType Dem_GetStatusOfDTC
(
   uint32 u32DTC,
   Dem_DTCKindType u8DTCKind,
   Dem_DTCOriginType u8DTCOrigin,
   uint8* u8DTCStatus
)
{
   Dem_ReturnGetStatusOfDTCType udtLocalOut;


   udtLocalOut = GDEXTINT_GetStatusOfDTC(u32DTC,
                                         u8DTCKind,
                                         u8DTCOrigin,
                                         u8DTCStatus);

   return(udtLocalOut);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_GetSizeOfFreezeFrameByDTC                              */
/* !Description :  Gets the size of freeze frame data by DTC.                 */
/* !Number      :  API2.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Dem_ReturnGetSizeOfFreezeFrameByDTCType                       */
/*  GDEXTINT_GetSizeOfFrzeFrameByDTC(argin uint32 u32DTC, argin               */
/*  Dem_DTCKindType u8DTCKind, argin Dem_DTCOriginType u8DTCOrigin, argin     */
/*  uint8 u8RecordNumber, argin uint16 *u16SizeOfFreezeFrame);                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dem_ReturnGetSizeOfFreezeFrameByDTCType Dem_GetSizeOfFreezeFrameByDTC
(
   uint32 u32DTC,
   Dem_DTCKindType u8DTCKind,
   Dem_DTCOriginType u8DTCOrigin,
   uint8 u8RecordNumber,
   uint16* u16SizeOfFreezeFrame
)

{
   Dem_ReturnGetSizeOfFreezeFrameByDTCType udtLocalOut;


   udtLocalOut = GDEXTINT_GetSizeOfFrzeFrameByDTC(u32DTC,
                                                  u8DTCKind,
                                                  u8DTCOrigin,
                                                  u8RecordNumber,
                                                  u16SizeOfFreezeFrame);

   return(udtLocalOut);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_GetFreezeFrameDataByDTC                                */
/* !Description :  Gets freeze frame data by DTC. The function stores the data*/
/*                 in the provided  DestBuffer.                               */
/* !Number      :  API2.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Dem_ReturnGetFreezeFrameDataByDTCType                         */
/*  GDEXTINT_GetFreezeFrameDataByDTC(argin uint32 u32DTC, argin               */
/*  Dem_DTCKindType u8DTCKind, argin Dem_DTCOriginType u8DTCOrigin, argin     */
/*  uint8 u8RecordNumber, argin uint8 *u8DestBuffer, argin uint16             */
/*  *u16BufSize);                                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dem_ReturnGetFreezeFrameDataByDTCType Dem_GetFreezeFrameDataByDTC
(
   uint32 u32DTC,
   Dem_DTCKindType u8DTCKind,
   Dem_DTCOriginType u8DTCOrigin,
   uint8 u8RecordNumber,
   uint8* u8DestBuffer,
   uint16* u16BufSize
)

{
   Dem_ReturnGetFreezeFrameDataByDTCType udtLocalOut;


   udtLocalOut = GDEXTINT_GetFreezeFrameDataByDTC(u32DTC,
                                                  u8DTCKind,
                                                  u8DTCOrigin,
                                                  u8RecordNumber,
                                                  u8DestBuffer,
                                                  u16BufSize);

   return(udtLocalOut);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_GetDTCStatusAvailabilityMask                           */
/* !Description :  Gets the DTC Status availability mask.                     */
/* !Number      :  API2.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GDEXTINT_GetDTCStatAvailbltyMask(argin uint8  */
/*  *u8DTCStatusMask);                                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType Dem_GetDTCStatusAvailabilityMask
(
   uint8* u8DTCStatusMask
)

{
   Std_ReturnType udtLocalOut;


   udtLocalOut = GDEXTINT_GetDTCStatAvailbltyMask(u8DTCStatusMask);

   return(udtLocalOut);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_GetTranslationType                                     */
/* !Description :  Gets the supported DTC formats of the ECU. The supported   */
/*                 formats are  configured via DemTypeOfDTCSupported.         */
/* !Number      :  API2.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret uint8  GDEXTINT_GetTranslationType();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
uint8 Dem_GetTranslationType(void)
{
   uint8 udtLocalOut;


   udtLocalOut = GDEXTINT_GetTranslationType();
   return (udtLocalOut);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_GetDTCOfOBDFreezeFrame                                 */
/* !Description :  Gets DTC by freeze frame record number.                    */
/* !Number      :  API2.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDEXTINT_GetDTCOfOBDFreezeFrame(argin uint8              */
/*  u8FrameNumber, argin uint32* u32DTC)Std_ReturnType;                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType Dem_GetDTCOfOBDFreezeFrame
(
   uint8 u8FrameNumber,
   uint32* u32DTC
)
{
   Std_ReturnType udtLocalOut;


   udtLocalOut = GDEXTINT_GetDTCOfOBDFreezeFrame(u8FrameNumber, u32DTC);
   return (udtLocalOut);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_ReadDataOfOBDFreezeFrame                               */
/* !Description :  Gets data element per PID and index of the most important  */
/*                 freeze frame being selected for the output of service $02. */
/*                 The function stores the data in the provided  DestBuffer.  */
/* !Number      :  API2.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDEXTINT_ReadDataOfOBDFreezeFrame(argin uint8 u8PID,argin*/
/*  uint8 u8DataElementIndexOfPID,argin uint8* u8DestBuffer, argin uint8*     */
/*  u8BufSize)Std_ReturnType;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType Dem_ReadDataOfOBDFreezeFrame
(
   uint8 u8PID,
   uint8 u8DataElementIndexOfPID,
   uint8* u8DestBuffer,
   uint8* u8BufSize
)
{
   Std_ReturnType udtLocalOut;


   udtLocalOut = GDEXTINT_ReadDataOfOBDFreezeFrame(u8PID,
                                                   u8DataElementIndexOfPID,
                                                   u8DestBuffer,
                                                   u8BufSize);
   return (udtLocalOut);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_DcmReadDataOfPID01                                     */
/* !Description :  Service to report the value of PID $01 computed by the Dem.*/
/* !Number      :  API2.8                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDEXTINT_DcmReadDataOfPID01(argin uint8*                 */
/*  u8PID01value)Std_ReturnType;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType Dem_DcmReadDataOfPID01
(
   uint8* u8PID01value
)
{
   Std_ReturnType udtLocalOut;


   udtLocalOut = GDEXTINT_DcmReadDataOfPID01(u8PID01value);
   return (udtLocalOut);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_SetEventSt                                              */
/* !Description :  Update the GAR upon changes of the event status            */
/* !Number      :  API2.9                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDEXTINT_vidSetEventSt(argin uint16 u16IdxDft);          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_SetEventSt
(
   uint16 u16IdxDft
)
{
   if (u16IdxDft < GD_DFT_NB)
   {
      GDEXTINT_vidSetEventSt(u16IdxDft);
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_DcmCancelOperation                                     */
/* !Description :  Fonction vode créée pour le besoin du DCM                  */
/* !Number      :  API2.10                                                    */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Dem_DcmCancelOperation(void)
{
   /* empty API*/
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_SetEventSt_reinit                                       */
/* !Description :  Reinit the GAR upon changes of the event status            */
/* !Number      :  API2.11                                                    */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDEXTINT_vidSetEventSt_reinit(argin uint16 u16IdxDft);   */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_SetEventSt_reinit
(
   uint16 u16IdxDft
)
{
   if (u16IdxDft < GD_DFT_NB)
   {
      GDEXTINT_vidSetEventSt_reinit(u16IdxDft);
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_RstEventSt                                              */
/* !Description :  Event indicating an update of StatusOfDTC information on   */
/*                 failure clear                                              */
/* !Number      :  API2.12                                                    */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDEXTINT_vidRstEventSt();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_RstEventSt(void)
{
   GDEXTINT_vidRstEventSt();
}
/*------------------------------- end of file --------------------------------*/