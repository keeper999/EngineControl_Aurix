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
/* !File            : GDEXTINT_FCT2.C                                         */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / GDEXTINT_GetStatusOfDTC                                              */
/*   2 / GDEXTINT_GetSizeOfFrzeFrameByDTC                                     */
/*   3 / GDEXTINT_GetFreezeFrameDataByDTC                                     */
/*   4 / GDEXTINT_GetFreezeFrameDataByD1                                      */
/*   5 / GDEXTINT_GetDTCStatAvailbltyMask                                     */
/*   6 / GDEXTINT_GetTranslationType                                          */
/*   7 / GDEXTINT_GetDTCOfOBDFreezeFrame                                      */
/*   8 / GDEXTINT_ReadDataOfOBDFreezeFrame                                    */
/*   9 / GDEXTINT_DcmReadDataOfPID01                                          */
/*   10 / GDEXTINT_vidEveRst_GDExtInt                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_5075312 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GDEXTINT/GDEXTINT_FCT2.C_v   $*/
/* $Revision::   1.17     $$Author::   mbenfrad       $$Date::   27 Aug 2013 $*/
/* $Author::   mbenfrad                               $$Date::   27 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "MATHSRV.h"
#include "GDExtInt.h"
#include "GDExtInt_L.h"
#include "GDExtInt_IM.h"
#include "MEM_CONF.h"
#include "Rte_Type.h"
#include "GD_API.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_GetStatusOfDTC                                    */
/* !Description :  Gets the status of a DTC.                                  */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 GD_au8StFrfRecNoFrf[40];                                      */
/*  input uint16 GD_au16idxDftNoFrf[40];                                      */
/*  input uint32 GD_NoDTC[8];                                                 */
/*  input uint8 GD_prmDtcStatus[8];                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dem_ReturnGetStatusOfDTCType GDEXTINT_GetStatusOfDTC
(
   uint32 u32DTC,
   Dem_DTCKindType u8DTCKind,
   Dem_DTCOriginType u8DTCOrigin,
   uint8* u8DTCStatus
)
{
   boolean                      bLocalFlag;
   Dem_ReturnGetStatusOfDTCType udtLocalStatus;
   sint32                       s32LocalIdx;
   uint8                        u8LocalGD_prmDtcStatus;
   uint8                        u8LocalStFrfRec;
   uint16                       u16LocalIndPanne;
   uint32                       u32LocalGD_NoDTC;
   uint32                       u32LocalGDBitwise;
   uint32                       u32LocalDTCBitwise;


   udtLocalStatus = DEM_STATUS_OK;
   if (u8DTCKind == DEM_DTC_KIND_ALL_DTCS)
   {
      if (u8DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
      {
         bLocalFlag = 0;
         for (s32LocalIdx = 0;
              ((s32LocalIdx < GD_NB_DFTCXTMAX) && (bLocalFlag == 0));
              s32LocalIdx++)
         {
            VEMS_vidGET1DArrayElement(GD_au8StFrfRecNoFrf,s32LocalIdx,
                                      u8LocalStFrfRec);
            if (u8LocalStFrfRec == 2)
            {
               /* For a group of monitors identified by a same DTC where each
               monitor has its own StatusOfDTC, the StatusOfDTC of the DTC
               is a logical combination */
               VEMS_vidGET1DArrayElement(GD_au16idxDftNoFrf,s32LocalIdx,
                                         u16LocalIndPanne);
               if (u16LocalIndPanne < GD_DFT_NB)
               {
                  VEMS_vidGET1DArrayElement(GD_NoDTC,
                                            u16LocalIndPanne,
                                            u32LocalGD_NoDTC);
                  u32LocalGDBitwise = (u32LocalGD_NoDTC & 0x00FFFFFF);
                  u32LocalDTCBitwise = (u32DTC & 0x00FFFFFF);
                  if (u32LocalGDBitwise == u32LocalDTCBitwise)
                  {
                     VEMS_vidGET1DArrayElement(GD_prmDtcStatus,
                                               u16LocalIndPanne,
                                               u8LocalGD_prmDtcStatus);
                     *u8DTCStatus = (uint8)
                        (u8LocalGD_prmDtcStatus | *u8DTCStatus);
                     udtLocalStatus = DEM_STATUS_OK;
                     bLocalFlag = 1;
                  }
                  else
                  {
                     udtLocalStatus = DEM_STATUS_WRONG_DTC;
                  }
               }
               else
               {
                  udtLocalStatus = DEM_STATUS_WRONG_DTC;
                  SWFAIL_vidSoftwareErrorHook();
               }
            }
         }

         if ( (*u8DTCStatus & 0x20) == 0x20)
         {
            *u8DTCStatus = (uint8)(*u8DTCStatus & 0xEF);
         }

         if ( (*u8DTCStatus & 0x02) == 0x02)
         {
            *u8DTCStatus = (uint8)(*u8DTCStatus & 0xBF);
         }
      }
      else
      {
         udtLocalStatus = DEM_STATUS_WRONG_DTCORIGIN;
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      udtLocalStatus = DEM_STATUS_WRONG_DTCKIND;
      SWFAIL_vidSoftwareErrorHook();
   }

   return (udtLocalStatus);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_GetSizeOfFrzeFrameByDTC                           */
/* !Description :  Gets the size of freeze frame data by DTC.                 */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 GD_au8StFrfRecNoFrf[40];                                      */
/*  input uint16 GD_au16idxDftNoFrf[40];                                      */
/*  input uint32 GD_NoDTC[8];                                                 */
/*  input uint8 GD_au8idxFltToCxtNoFrf[40];                                   */
/*  input uint8 GD_au8IdxClasFrf[8];                                          */
/*  input GD_tstrClasFrf GD_astrClasFrf[60];                                  */
/*  input uint8 GD_au8SizeParam[147];                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dem_ReturnGetSizeOfFreezeFrameByDTCType GDEXTINT_GetSizeOfFrzeFrameByDTC
(
   uint32 u32DTC,
   Dem_DTCKindType u8DTCKind,
   Dem_DTCOriginType u8DTCOrigin,
   uint8 u8RecordNumber,
   uint16* u16SizeOfFreezeFrame
)
{
   Dem_ReturnGetSizeOfFreezeFrameByDTCType udtLocalStatus;
   sint32                                  s32LocalIdx;
   uint8                                   u8LocalGDidxClasFrfC;
   uint8                                   u8LocalGDidx;
   uint8                                   u8LocalStFrfRec;
   uint8                                   u8localGD_au8idxFltToCxt;
   uint8                                   u8LocalArrayPrm1;
   uint8                                   u8LocalArrayPrm2;
   uint8                                   u8LocalArrayPrm3;
   uint8                                   u8LocalArrayPrm4;
   uint8                                   u8LocalArrayPrm5;
   uint8                                   u8LocalArrayPrm6;
   uint8                                   u8LocalArrayPrm7;
   uint8                                   u8LocalArrayPrm8;
   uint8                                   u8LocalArrayPrm9;
   uint16                                  u16LocalFltToCxt_prev;
   uint16                                  u16LocalIndPanne;
   uint16                                  u16LocalInd;
   uint16                                  u16LocalGDidxDftNoFrf;
   uint32                                  u32LocalGD_NoDTC;
   uint32                                  u32LocalGDBitwise;
   uint32                                  u32LocalDTCBitwise;


   udtLocalStatus = DEM_GET_SIZEOFFF_OK;
   /*QAC Warning : Msg(3:3198) --> this affectation is made to avoid
   compilmation warning*/
   if (u8DTCKind == DEM_DTC_KIND_ALL_DTCS)
   {
      if (u8DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
      {
         switch(u8RecordNumber)
         {
            case 0x00:
            /* The Record Number 0x00 corresponds to an empty freeze frame*/
            *u16SizeOfFreezeFrame = 0;
            udtLocalStatus = DEM_GET_SIZEOFFF_OK;
            break;

            case 0x01:
            case 0xFF:
            /*The Record Number 0x01 corresponds to the only freeze frame
            available and the record number 0xFF corresponds to the total size
            of every freeze frame */

            u16LocalIndPanne = 0xFFFF;
            u16LocalFltToCxt_prev = 0xFFFF;
            for (s32LocalIdx = 0;
                 s32LocalIdx < GD_NB_DFTCXTMAX;
                 s32LocalIdx++)
            {
               VEMS_vidGET1DArrayElement(GD_au8StFrfRecNoFrf,
                                         s32LocalIdx,
                                         u8LocalStFrfRec);
               if (u8LocalStFrfRec == 2)
               {
                  VEMS_vidGET1DArrayElement(GD_au16idxDftNoFrf,
                                            s32LocalIdx,
                                            u16LocalGDidxDftNoFrf);
                  u16LocalInd =
                     (uint16)MATHSRV_udtMIN(u16LocalGDidxDftNoFrf,
                                            GD_DFT_NB-1);
                  VEMS_vidGET1DArrayElement(GD_NoDTC,
                                            u16LocalInd,
                                            u32LocalGD_NoDTC);
                  u32LocalGDBitwise = (u32LocalGD_NoDTC & 0x00FFFFFF);
                  u32LocalDTCBitwise = (u32DTC & 0x00FFFFFF);
                  if (u32LocalGDBitwise == u32LocalDTCBitwise)
                  {
                     /* The rank of the oldest context parameters is saved into
                     a temporary variable */
                     VEMS_vidGET1DArrayElement(GD_au8idxFltToCxtNoFrf,
                                               s32LocalIdx,
                                               u8localGD_au8idxFltToCxt);
                     if (u8localGD_au8idxFltToCxt < u16LocalFltToCxt_prev)
                     {
                        u16LocalFltToCxt_prev = u8localGD_au8idxFltToCxt;
                        u16LocalIndPanne = u16LocalGDidxDftNoFrf;
                     }
                  }
               }
            }
            if (u16LocalIndPanne != 0xFFFF)
            {
               *u16SizeOfFreezeFrame = 33;
               /*For each additionnal parameter, we consider 2 bytes for its
               DID and the size for its own value is given by the table
               NS_prmClasFrf*/
               u16LocalIndPanne =
                           (uint16)MATHSRV_udtMIN(u16LocalIndPanne,
                                                  GD_DFT_NB-1);
               u8LocalGDidx = GD_au8IdxClasFrf[u16LocalIndPanne];
               u8LocalGDidxClasFrfC =
                 (uint8)MATHSRV_udtMIN(u8LocalGDidx, GD_CLAS_FRF-1);
               u8LocalArrayPrm1 =
                        GD_astrClasFrf[u8LocalGDidxClasFrfC].u8ClasFrfParam1;

               u8LocalArrayPrm1 = (uint8)MATHSRV_udtMIN(u8LocalArrayPrm1,
                                                        NB_PARAM-1);
               if (u8LocalArrayPrm1 != 0)
               {
                  *u16SizeOfFreezeFrame =
                     (uint16)( *u16SizeOfFreezeFrame
                             + GD_au8SizeParam[u8LocalArrayPrm1]
                             + 2);
               }
               u8LocalArrayPrm2 =
                        GD_astrClasFrf[u8LocalGDidxClasFrfC].u8ClasFrfParam2;
               u8LocalArrayPrm2 = (uint8)MATHSRV_udtMIN(u8LocalArrayPrm2,
                                                        NB_PARAM-1);
               if (u8LocalArrayPrm2 != 0)
               {
                  *u16SizeOfFreezeFrame =
                     (uint16)( *u16SizeOfFreezeFrame
                             + GD_au8SizeParam[u8LocalArrayPrm2]
                             + 2);
               }
               u8LocalArrayPrm3 =
                        GD_astrClasFrf[u8LocalGDidxClasFrfC].u8ClasFrfParam3;
               u8LocalArrayPrm3 = (uint8)MATHSRV_udtMIN(u8LocalArrayPrm3,
                                                        NB_PARAM-1);
               if (u8LocalArrayPrm3 != 0)
               {
                  *u16SizeOfFreezeFrame =
                     (uint16)( *u16SizeOfFreezeFrame
                             + GD_au8SizeParam[u8LocalArrayPrm3]
                             + 2);
               }
               u8LocalArrayPrm4 =
                        GD_astrClasFrf[u8LocalGDidxClasFrfC].u8ClasFrfParam4;
               u8LocalArrayPrm4 = (uint8)MATHSRV_udtMIN(u8LocalArrayPrm4,
                                                        NB_PARAM-1);
               if (u8LocalArrayPrm4 != 0)
               {
                  *u16SizeOfFreezeFrame =
                     (uint16)( *u16SizeOfFreezeFrame
                             + GD_au8SizeParam[u8LocalArrayPrm4]
                             + 2);
               }
               u8LocalArrayPrm5 =
                        GD_astrClasFrf[u8LocalGDidxClasFrfC].u8ClasFrfParam5;
               u8LocalArrayPrm5 = (uint8)MATHSRV_udtMIN(u8LocalArrayPrm5,
                                                        NB_PARAM-1);
               if (u8LocalArrayPrm5 != 0)
               {
                  *u16SizeOfFreezeFrame =
                     (uint16)( *u16SizeOfFreezeFrame
                             + GD_au8SizeParam[u8LocalArrayPrm5]
                             + 2);
               }
               u8LocalArrayPrm6 =
                        GD_astrClasFrf[u8LocalGDidxClasFrfC].u8ClasFrfParam6;
               u8LocalArrayPrm6 = (uint8)MATHSRV_udtMIN(u8LocalArrayPrm6,
                                                        NB_PARAM-1);
               if (u8LocalArrayPrm6 != 0)
               {
                  *u16SizeOfFreezeFrame =
                     (uint16)( *u16SizeOfFreezeFrame
                             + GD_au8SizeParam[u8LocalArrayPrm6]
                             + 2);
               }
               u8LocalArrayPrm7 =
                        GD_astrClasFrf[u8LocalGDidxClasFrfC].u8ClasFrfParam7;
               u8LocalArrayPrm7 = (uint8)MATHSRV_udtMIN(u8LocalArrayPrm7,
                                                        NB_PARAM-1);
               if (u8LocalArrayPrm7 != 0)
               {
                  *u16SizeOfFreezeFrame =
                     (uint16)( *u16SizeOfFreezeFrame
                             + GD_au8SizeParam[u8LocalArrayPrm7]
                             + 2);
               }
               u8LocalArrayPrm8 =
                        GD_astrClasFrf[u8LocalGDidxClasFrfC].u8ClasFrfParam8;
               u8LocalArrayPrm8 = (uint8)MATHSRV_udtMIN(u8LocalArrayPrm8,
                                                        NB_PARAM-1);
               if (u8LocalArrayPrm8 != 0)
               {
                  *u16SizeOfFreezeFrame =
                     (uint16)( *u16SizeOfFreezeFrame
                             + GD_au8SizeParam[u8LocalArrayPrm8]
                             + 2);
               }
               u8LocalArrayPrm9 =
                        GD_astrClasFrf[u8LocalGDidxClasFrfC].u8ClasFrfParam9;
               u8LocalArrayPrm9 = (uint8)MATHSRV_udtMIN(u8LocalArrayPrm9,
                                                        NB_PARAM-1);
               if (u8LocalArrayPrm9 != 0)
               {
                  *u16SizeOfFreezeFrame =
                     (uint16)(*u16SizeOfFreezeFrame
                             + GD_au8SizeParam[u8LocalArrayPrm9]
                             + 2);
               }
               udtLocalStatus = DEM_GET_SIZEOFFF_OK;
            }
            else
            {
               udtLocalStatus = DEM_GET_SIZEOFFF_WRONG_DTC;
            }
            break;

            default:
            udtLocalStatus = DEM_GET_SIZEOFFF_WRONG_RNUM;
            SWFAIL_vidSoftwareErrorHook();
            break;
         }
      }
      else
      {
         udtLocalStatus = DEM_GET_SIZEOFFF_WRONG_DTCOR;
      }
   }
   else
   {
      udtLocalStatus = DEM_GET_SIZEOFFF_WRONG_DTCKIND;
      SWFAIL_vidSoftwareErrorHook();
   }

   return (udtLocalStatus);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_GetFreezeFrameDataByDTC                           */
/* !Description :  Gets freeze frame data by DTC. The function stores the data*/
/*                 in the provided  DestBuffer.                               */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf argret Dem_ReturnGetSizeOfFreezeFrameByDTCType                       */
/* GDEXTINT_GetSizeOfFrzeFrameByDTC(argin uint32 u32DTC, argin Dem_DTCKindType*/
/* u8DTCKind, argin Dem_DTCOriginType u8DTCOrigin, argin uint8 u8RecordNumber,*/
/* argin uint16 *u16SizeOfFreezeFrame);                                       */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDEXTINT_GetFreezeFrameDataByD1(argin uint8 u8LocalIdx,  */
/* argin uint16 u16LocalIndPanne, argin uint8 *u8DestBuffer);                 */
/*  input uint8 GD_au8StFrfRecNoFrf[40];                                      */
/*  input uint16 GD_au16idxDftNoFrf[40];                                      */
/*  input uint32 GD_NoDTC[8];                                                 */
/*  input uint8 GD_au8idxFltToCxtNoFrf[40];                                   */
/*  input sint16 GD_as16tCoMesNoFrf[40];                                      */
/*  input uint16 GD_au16nEngNoFrf[40];                                        */
/*  input uint16 GD_spdVeh_NoFrf[40];                                         */
/*  input uint16 GD_uBattMes_NoFrf[40];                                       */
/*  input uint32 GD_au32dstAbsKmNoFrf[40];                                    */
/*  input uint32 GD_tiCurVehTmr_NoFrf[40];                                    */
/*  input uint16 GD_rAccP_NoFrf[40];                                          */
/*  input uint16 GD_DID_dstAbsKm;                                             */
/*  input uint16 GD_DID_tiCurVehTmr;                                          */
/*  input uint16 GD_DID_nEng;                                                 */
/*  input uint16 GD_DID_rAccP;                                                */
/*  input uint16 GD_DID_spdVeh;                                               */
/*  input uint16 GD_DID_tCoMes;                                               */
/*  input uint16 GD_DID_uBattMes;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dem_ReturnGetFreezeFrameDataByDTCType GDEXTINT_GetFreezeFrameDataByDTC
(
   uint32 u32DTC,
   Dem_DTCKindType u8DTCKind,
   Dem_DTCOriginType u8DTCOrigin,
   uint8 u8RecordNumber,
   uint8* u8DestBuffer,
   uint16* u16BufSize
)
{
   boolean                               bLocalFlag;
   Dem_ReturnGetFreezeFrameDataByDTCType udtLocalStatus;
   sint32                                s32LocalIdx;
   uint8                                 u8LocalCxt;
   uint8                                 u8LocalStFrfRec;
   uint8                                 u8localGD_au8idxFltToCxt;
   uint16                                u16LocalFltToCxt_prev;
   uint16                                u16LocalIndPanne;
   uint16                                u16FFSize;
   uint16                                u16LocalGD_uBattMesNoFrf;
   uint16                                u16LocalGD_au16nEngNoFrf;
   uint16                                u16LocalGD_au16GD_rAccP_NoFrf;
   uint16                                u16LocalGD_SpdVehNoFrf;
   uint16                                u16LocalGD_DID_dstAbsKm;
   uint16                                u16LocalGD_DID_tiCurVehTmr;
   uint16                                u16LocalGD_DID_nEng;
   uint16                                u16LocalGD_DID_rAccP;
   uint16                                u16LocalGD_DID_spdVeh;
   uint16                                u16LocalGD_DID_tCoMes;
   uint16                                u16LocalGD_DID_uBattMes;
   uint32                                u32LocalGD_NoDTC;
   uint32                                u32LocalGD_au32dstAbsKmNoFrf;
   uint32                                u32LocalGDBitwise;
   uint32                                u32LocalGD_au32tiCurVehTmrNoFrf;
   sint16                                s16LocalGD_as16tCoMesNoFrf;


   udtLocalStatus = DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE;
   u16FFSize = 0x0000;
   if (u8DTCKind == DEM_DTC_KIND_ALL_DTCS)
   {
      if (u8DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
      {
         switch(u8RecordNumber)
         {
            case 0x00:
            /* The Freeze frame number 0 is empty */
            udtLocalStatus = DEM_GET_FFDATABYDTC_OK;
            *u16BufSize = 0;
            break;

            case 0x01:
            u8DestBuffer[0] = 0x01;
            u8LocalCxt = 0xFF;
            u16LocalFltToCxt_prev = 0xFFFF;
            for (s32LocalIdx = 0;
                 s32LocalIdx < GD_NB_DFTCXTMAX;
                 s32LocalIdx++)
            {
               bLocalFlag = 0;
               VEMS_vidGET1DArrayElement(GD_au8StFrfRecNoFrf,s32LocalIdx,
                                         u8LocalStFrfRec);
               if (u8LocalStFrfRec == 2)
               {
                  VEMS_vidGET1DArrayElement(GD_au16idxDftNoFrf,s32LocalIdx,
                                            u16LocalIndPanne);
                  if (u16LocalIndPanne < GD_DFT_NB)
                  {
                     VEMS_vidGET1DArrayElement(GD_NoDTC,
                                               u16LocalIndPanne,
                                               u32LocalGD_NoDTC);
                     u32LocalGDBitwise = (u32LocalGD_NoDTC & 0x00FFFFFF);
                     if (u32LocalGDBitwise == u32DTC)
                     {
                        bLocalFlag = 1;
                     }
                  }
                  else
                  {
                     udtLocalStatus = DEM_GET_FFDATABYDTC_WRONG_DTC;
                     SWFAIL_vidSoftwareErrorHook();
                  }
               }
               if (bLocalFlag != 0)
               {
                  /* The rank of the oldest context parameters is saved
                  into a temporary variable  */
                  VEMS_vidGET1DArrayElement(GD_au8idxFltToCxtNoFrf,s32LocalIdx,
                                            u8localGD_au8idxFltToCxt);
                  if (u8localGD_au8idxFltToCxt < u16LocalFltToCxt_prev)
                  {
                     u16LocalFltToCxt_prev = u8localGD_au8idxFltToCxt;
                     u8LocalCxt = (uint8)s32LocalIdx;
                  }
               }
            }
            if (u8LocalCxt != 0xFF)
            {
               /* The number of data bytes to write is given by the
               service GDEXTINT_GetSizeOfFrzeFrameByDTC*/
               GDEXTINT_GetSizeOfFrzeFrameByDTC(u32DTC,
                                                u8DTCKind,
                                                u8DTCOrigin,
                                                u8RecordNumber,
                                                &u16FFSize);
               /*Msg(2:3200) 'GDEXTINT_GetSizeOfFrzeFrameByDTC'
               returns a value which is not being used.*/
               if (u16FFSize > *u16BufSize)
               {
                  udtLocalStatus =
                     DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE;
               }
               else
               {
                  /* The oldest freeze frame associated with the specified
                  DTC is saved into the output buffer */
                  VEMS_vidGET1DArrayElement(GD_au16idxDftNoFrf,
                                            u8LocalCxt,
                                            u16LocalIndPanne);
                  *u16BufSize = u16FFSize;

                  VEMS_vidGET1DArrayElement
                                 (GD_as16tCoMesNoFrf,
                                  u8LocalCxt,
                                  s16LocalGD_as16tCoMesNoFrf);
                  VEMS_vidGET1DArrayElement
                                 (GD_au16nEngNoFrf,
                                  u8LocalCxt,
                                  u16LocalGD_au16nEngNoFrf);
                  VEMS_vidGET1DArrayElement
                                 (GD_spdVeh_NoFrf,
                                  u8LocalCxt,
                                  u16LocalGD_SpdVehNoFrf);
                  VEMS_vidGET1DArrayElement
                                 (GD_uBattMes_NoFrf,
                                  u8LocalCxt,
                                  u16LocalGD_uBattMesNoFrf);
                  VEMS_vidGET1DArrayElement
                                 (GD_au32dstAbsKmNoFrf,
                                  u8LocalCxt,
                                  u32LocalGD_au32dstAbsKmNoFrf);
                  VEMS_vidGET1DArrayElement
                                 (GD_tiCurVehTmr_NoFrf,
                                  u8LocalCxt,
                                  u32LocalGD_au32tiCurVehTmrNoFrf);
                  VEMS_vidGET1DArrayElement
                                 (GD_rAccP_NoFrf,
                                  u8LocalCxt,
                                  u16LocalGD_au16GD_rAccP_NoFrf);

                  VEMS_vidGET(GD_DID_dstAbsKm, u16LocalGD_DID_dstAbsKm);
                  u8DestBuffer[2] = (uint8)( ( u16LocalGD_DID_dstAbsKm
                                           & 0xFF00) >> 8);
                  u8DestBuffer[3] = (uint8)(u16LocalGD_DID_dstAbsKm & 0x00FF);
                  u8DestBuffer[4] =
                     (uint8)( ( u32LocalGD_au32dstAbsKmNoFrf
                            & 0xFF0000) >> 16);
                  u8DestBuffer[5] =
                     (uint8)( ( u32LocalGD_au32dstAbsKmNoFrf
                            & 0x00FF00) >> 8);
                  u8DestBuffer[6] =
                     (uint8)(u32LocalGD_au32dstAbsKmNoFrf & 0x0000FF);
                  VEMS_vidGET(GD_DID_tiCurVehTmr, u16LocalGD_DID_tiCurVehTmr);
                  u8DestBuffer[7] = (uint8)( ( u16LocalGD_DID_tiCurVehTmr
                                           & 0xFF00) >> 8);
                  u8DestBuffer[8] = (uint8)( u16LocalGD_DID_tiCurVehTmr
                                           & 0x00FF);
                  u8DestBuffer[9] = (uint8)( ( u32LocalGD_au32tiCurVehTmrNoFrf
                                           & 4278190080UL) >> 24);
                  u8DestBuffer[10] = (uint8)( ( u32LocalGD_au32tiCurVehTmrNoFrf
                                            & 0x00FF0000) >> 16);
                  u8DestBuffer[11] = (uint8)( ( u32LocalGD_au32tiCurVehTmrNoFrf
                                            & 0x0000FF00) >> 8);
                  u8DestBuffer[12] = (uint8)( u32LocalGD_au32tiCurVehTmrNoFrf
                                            & 0x000000FF);
                  VEMS_vidGET(GD_DID_nEng, u16LocalGD_DID_nEng);
                  u8DestBuffer[13] = (uint8)( ( u16LocalGD_DID_nEng
                                            & 0xFF00) >> 8);
                  u8DestBuffer[14] = (uint8)( u16LocalGD_DID_nEng & 0x00FF);
                  u8DestBuffer[15] = (uint8)( ( u16LocalGD_au16nEngNoFrf
                                            & 0xFF00) >> 8);
                  u8DestBuffer[16] = (uint8)(u16LocalGD_au16nEngNoFrf & 0x00FF);
                  VEMS_vidGET(GD_DID_rAccP, u16LocalGD_DID_rAccP);
                  u8DestBuffer[17] = (uint8)( ( u16LocalGD_DID_rAccP
                                            & 0xFF00) >> 8);
                  u8DestBuffer[18] = (uint8)(u16LocalGD_DID_rAccP & 0x00FF);
                  u8DestBuffer[19] = (uint8)( ( u16LocalGD_au16GD_rAccP_NoFrf
                                            & 0xFF00) >> 8);
                  u8DestBuffer[20] = (uint8)( u16LocalGD_au16GD_rAccP_NoFrf
                                            & 0x00FF);
                  VEMS_vidGET(GD_DID_spdVeh, u16LocalGD_DID_spdVeh);
                  u8DestBuffer[21] = (uint8)( (u16LocalGD_DID_spdVeh
                                            & 0xFF00) >> 8);
                  u8DestBuffer[22] = (uint8)(u16LocalGD_DID_spdVeh & 0x00FF);
                  u8DestBuffer[23] = (uint8)( ( u16LocalGD_SpdVehNoFrf
                                            & 0xFF00) >> 8);
                  u8DestBuffer[24] = (uint8)( u16LocalGD_SpdVehNoFrf
                                            & 0x00FF);
                  VEMS_vidGET(GD_DID_tCoMes, u16LocalGD_DID_tCoMes);
                  u8DestBuffer[25] = (uint8)( (u16LocalGD_DID_tCoMes
                                            & 0xFF00) >> 8);
                  u8DestBuffer[26] = (uint8)(u16LocalGD_DID_tCoMes & 0x00FF);
                  u8DestBuffer[27] = (uint8)( (s16LocalGD_as16tCoMesNoFrf
                                            & 0xFF00) >> 8);
                  u8DestBuffer[28] = (uint8)( s16LocalGD_as16tCoMesNoFrf
                                            & 0x00FF);
                  VEMS_vidGET(GD_DID_uBattMes, u16LocalGD_DID_uBattMes);
                  u8DestBuffer[29] = (uint8)( ( u16LocalGD_DID_uBattMes
                                            & 0xFF00) >> 8);
                  u8DestBuffer[30] = (uint8)(u16LocalGD_DID_uBattMes & 0x00FF);
                  u8DestBuffer[31] = (uint8)( (u16LocalGD_uBattMesNoFrf
                                            & 0xFF00) >> 8);
                  u8DestBuffer[32] = (uint8)( u16LocalGD_uBattMesNoFrf
                                            & 0x00FF);
                  /* u8DestBuffer(1) represents the number of DIDs into
                  the buffer*/
                  u8DestBuffer[1] = 7;
                  GDEXTINT_GetFreezeFrameDataByD1(u8LocalCxt,
                                                  u16LocalIndPanne,
                                                  u8DestBuffer);
                  udtLocalStatus = DEM_GET_FFDATABYDTC_OK;
               }
            }
            else
            {
               udtLocalStatus = DEM_GET_FFDATABYDTC_WRONG_DTC;
            }
            break;

            case 0xFF:
            udtLocalStatus = DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER;
            break;
            default:
            /*The service returns a positive answer if the record number
            asked is not supportedand the Buffer size is defined to 0*/
            udtLocalStatus = DEM_GET_FFDATABYDTC_WRONG_DTC;
            *u16BufSize = 0;
            SWFAIL_vidSoftwareErrorHook();
            break;
         }
      }
      else
      {
         udtLocalStatus = DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN;
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      udtLocalStatus = DEM_GET_FFDATABYDTC_WRONG_DTCKIND;
      SWFAIL_vidSoftwareErrorHook();
   }

   return (udtLocalStatus);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_GetFreezeFrameDataByD1                            */
/* !Description :  Sub function of GDEXTINT_GetFreezeFrameDataByDTC           */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 GD_au8IdxClasFrf[8];                                          */
/*  input GD_tstrClasFrf GD_astrClasFrf[60];                                  */
/*  input uint32 GD_au32prmClasFrf1NoFrf[40];                                 */
/*  input uint16 GD_au16prmClasDID1[40];                                      */
/*  input uint8 GD_au8SizeParam[147];                                         */
/*  input uint32 GD_au32prmClasFrf2NoFrf[40];                                 */
/*  input uint16 GD_au16prmClasDID2[40];                                      */
/*  input uint32 GD_au32prmClasFrf3NoFrf[40];                                 */
/*  input uint16 GD_au16prmClasDID3[40];                                      */
/*  input uint32 GD_au32prmClasFrf4NoFrf[40];                                 */
/*  input uint16 GD_au16prmClasDID4[40];                                      */
/*  input uint32 GD_au32prmClasFrf5NoFrf[40];                                 */
/*  input uint16 GD_au16prmClasDID5[40];                                      */
/*  input uint32 GD_au32prmClasFrf6NoFrf[40];                                 */
/*  input uint16 GD_au16prmClasDID6[40];                                      */
/*  input uint32 GD_au32prmClasFrf7NoFrf[40];                                 */
/*  input uint16 GD_au16prmClasDID7[40];                                      */
/*  input uint32 GD_au32prmClasFrf8NoFrf[40];                                 */
/*  input uint16 GD_au16prmClasDID8[40];                                      */
/*  input uint32 GD_au32prmClasFrf9NoFrf[40];                                 */
/*  input uint16 GD_au16prmClasDID9[40];                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDEXTINT_GetFreezeFrameDataByD1
(
   uint8 u8LocalIdx,
   uint16 u16LocalIndPanne,
   uint8* u8DestBuffer
)
{
   uint8  u8LocalBuf;
   uint8  u8LocalPos;
   uint8  u8LocalMask;
   uint8  u8LocalShift;
   uint8  u8LocalGDidxPrmClasFrf1T;
   uint8  u8LocalGDidxPrmClasFrf2T;
   uint8  u8LocalGDidxPrmClasFrf3T;
   uint8  u8LocalGDidxPrmClasFrf4T;
   uint8  u8LocalGDidxPrmClasFrf5T;
   uint8  u8LocalGDidxPrmClasFrf6T;
   uint8  u8LocalGDidxPrmClasFrf7T;
   uint8  u8LocalGDidxPrmClasFrf8T;
   uint8  u8LocalGDidxPrmClasFrf9T;
   uint8  u8LocalIndxPanne;
   uint8  u8LocalLong;
   uint32 u32LocalId;
   uint16 u16LocalGD_au16prmClasDID;
   uint32 u32LocalGD_au32prmClasFrf1NoFrf;
   uint32 u32LocalGD_au32prmClasFrf2NoFrf;
   uint32 u32LocalGD_au32prmClasFrf3NoFrf;
   uint32 u32LocalGD_au32prmClasFrf4NoFrf;
   uint32 u32LocalGD_au32prmClasFrf5NoFrf;
   uint32 u32LocalGD_au32prmClasFrf6NoFrf;
   uint32 u32LocalGD_au32prmClasFrf7NoFrf;
   uint32 u32LocalGD_au32prmClasFrf8NoFrf;
   uint32 u32LocalGD_au32prmClasFrf9NoFrf;


   u8LocalBuf = 33;
   /*Depending on the additional Freeze Frame parameters, the buffer size will
   be different. The recovery of the right byte is done by a mask. This mask is
   shifted once to select the right byte and the result is shifted again to fit
   into the single byte of the Destbuffer. This action is generalized for the
   additional parameters*/
   u8LocalIndxPanne = GD_au8IdxClasFrf[u16LocalIndPanne];
   if (u8LocalIndxPanne < GD_CLAS_FRF)
   {
      u8LocalGDidxPrmClasFrf1T =
                     GD_astrClasFrf[u8LocalIndxPanne].u8ClasFrfParam1;
      if (u8LocalGDidxPrmClasFrf1T != 0)
      {
         VEMS_vidGET1DArrayElement(GD_au32prmClasFrf1NoFrf,
                                   u8LocalIdx,
                                   u32LocalGD_au32prmClasFrf1NoFrf);
         VEMS_vidGET1DArrayElement(GD_au16prmClasDID1,
                                   u8LocalIdx,
                                   u16LocalGD_au16prmClasDID);
         u8DestBuffer[u8LocalBuf] = (uint8)(( u16LocalGD_au16prmClasDID
                                            & 0xFF00) >> 8);
         u8DestBuffer[u8LocalBuf + 1] = (uint8)( u16LocalGD_au16prmClasDID
                                               & 0x00FF);
         if (u8LocalGDidxPrmClasFrf1T < NB_PARAM)
         {
            u8LocalLong = GD_au8SizeParam[u8LocalGDidxPrmClasFrf1T];
            u8LocalLong = (uint8)MATHSRV_udtMIN(u8LocalLong, 4);
            for (u32LocalId = 1; u32LocalId <= u8LocalLong; u32LocalId++)
            {
               u8LocalPos = (uint8)((u8LocalBuf + 1) + u32LocalId);
               u8LocalMask = (uint8)(8 * ((3 + u32LocalId) - u8LocalLong));
               u8LocalShift = (uint8)(8 * (u8LocalLong - u32LocalId));
               u8DestBuffer[u8LocalPos] =
                  (uint8)(( u32LocalGD_au32prmClasFrf1NoFrf
                          & (4278190080UL >> u8LocalMask)) >> u8LocalShift);
            }
            u8LocalBuf = (uint8)((u8LocalBuf + 2) + u8LocalLong);
         }
         u8DestBuffer[1] = (uint8)(u8DestBuffer[1] + 1);
      }
      u8LocalGDidxPrmClasFrf2T =
                     GD_astrClasFrf[u8LocalIndxPanne].u8ClasFrfParam2;
      if (u8LocalGDidxPrmClasFrf2T != 0)
      {
         VEMS_vidGET1DArrayElement(GD_au32prmClasFrf2NoFrf,
                                   u8LocalIdx,
                                   u32LocalGD_au32prmClasFrf2NoFrf);
         VEMS_vidGET1DArrayElement(GD_au16prmClasDID2,
                                   u8LocalIdx,
                                   u16LocalGD_au16prmClasDID);
         u8DestBuffer[u8LocalBuf] = (uint8)(( u16LocalGD_au16prmClasDID
                                            & 0xFF00) >> 8);
         u8DestBuffer[u8LocalBuf + 1] = (uint8)( u16LocalGD_au16prmClasDID
                                               & 0x00FF);
         if (u8LocalGDidxPrmClasFrf2T < NB_PARAM)
         {
            u8LocalLong = GD_au8SizeParam[u8LocalGDidxPrmClasFrf2T];
            u8LocalLong = (uint8)MATHSRV_udtMIN(u8LocalLong, 4);
            for (u32LocalId = 1; u32LocalId <= u8LocalLong; u32LocalId++)
            {
               u8LocalPos = (uint8)((u8LocalBuf + 1) + u32LocalId);
               u8LocalMask = (uint8)(8 * ((3 + u32LocalId) - u8LocalLong));
               u8LocalShift = (uint8)(8 * (u8LocalLong - u32LocalId));
               u8DestBuffer[u8LocalPos] =
                  (uint8)(( u32LocalGD_au32prmClasFrf2NoFrf
                          & (4278190080UL >> u8LocalMask)) >> u8LocalShift);
            }
            u8LocalBuf = (uint8)((u8LocalBuf + 2) + u8LocalLong);
         }
         u8DestBuffer[1] = (uint8)(u8DestBuffer[1] + 1);
      }
      u8LocalGDidxPrmClasFrf3T =
                     GD_astrClasFrf[u8LocalIndxPanne].u8ClasFrfParam3;
      if (u8LocalGDidxPrmClasFrf3T != 0)
      {
         VEMS_vidGET1DArrayElement(GD_au32prmClasFrf3NoFrf,
                                   u8LocalIdx,
                                   u32LocalGD_au32prmClasFrf3NoFrf);
         VEMS_vidGET1DArrayElement(GD_au16prmClasDID3,
                                   u8LocalIdx,
                                   u16LocalGD_au16prmClasDID);
         u8DestBuffer[u8LocalBuf] = (uint8)(( u16LocalGD_au16prmClasDID
                                            & 0xFF00) >> 8);
         u8DestBuffer[u8LocalBuf + 1] = (uint8)( u16LocalGD_au16prmClasDID
                                               & 0x00FF);
         if (u8LocalGDidxPrmClasFrf3T < NB_PARAM)
         {
            u8LocalLong = GD_au8SizeParam[u8LocalGDidxPrmClasFrf3T];
            u8LocalLong = (uint8)MATHSRV_udtMIN(u8LocalLong, 4);
            for (u32LocalId = 1; u32LocalId <= u8LocalLong; u32LocalId++)
            {
               u8LocalPos = (uint8)((u8LocalBuf + 1) + u32LocalId);
               u8LocalMask = (uint8)(8 * ((3 + u32LocalId) - u8LocalLong));
               u8LocalShift = (uint8)(8 * (u8LocalLong - u32LocalId));
               u8DestBuffer[u8LocalPos] =
                  (uint8)(( u32LocalGD_au32prmClasFrf3NoFrf
                          & (4278190080UL >> u8LocalMask)) >> u8LocalShift);
            }
            u8LocalBuf = (uint8)((u8LocalBuf + 2) + u8LocalLong);
         }
         u8DestBuffer[1] = (uint8)(u8DestBuffer[1] + 1);
      }
      u8LocalGDidxPrmClasFrf4T =
                     GD_astrClasFrf[u8LocalIndxPanne].u8ClasFrfParam4;
      if (u8LocalGDidxPrmClasFrf4T != 0)
      {
         VEMS_vidGET1DArrayElement(GD_au32prmClasFrf4NoFrf,
                                   u8LocalIdx,
                                   u32LocalGD_au32prmClasFrf4NoFrf);
         VEMS_vidGET1DArrayElement(GD_au16prmClasDID4,
                                   u8LocalIdx,
                                   u16LocalGD_au16prmClasDID);
         u8DestBuffer[u8LocalBuf] = (uint8)(( u16LocalGD_au16prmClasDID
                                            & 0xFF00) >> 8);
         u8DestBuffer[u8LocalBuf + 1] = (uint8)( u16LocalGD_au16prmClasDID
                                               & 0x00FF);
         if (u8LocalGDidxPrmClasFrf4T < NB_PARAM)
         {
            u8LocalLong = GD_au8SizeParam[u8LocalGDidxPrmClasFrf4T];
            u8LocalLong = (uint8)MATHSRV_udtMIN(u8LocalLong, 4);
            for (u32LocalId = 1; u32LocalId <= u8LocalLong; u32LocalId++)
            {
               u8LocalPos = (uint8)((u8LocalBuf + 1) + u32LocalId);
               u8LocalMask = (uint8)(8 * ((3 + u32LocalId) - u8LocalLong));
               u8LocalShift = (uint8)(8 * (u8LocalLong - u32LocalId));
               u8DestBuffer[u8LocalPos] =
                  (uint8)(( u32LocalGD_au32prmClasFrf4NoFrf
                          & (4278190080UL >> u8LocalMask)) >> u8LocalShift);
            }
            u8LocalBuf = (uint8)((u8LocalBuf + 2) + u8LocalLong);
         }
         u8DestBuffer[1] = (uint8)(u8DestBuffer[1] + 1);
      }
      u8LocalGDidxPrmClasFrf5T =
                     GD_astrClasFrf[u8LocalIndxPanne].u8ClasFrfParam5;
      if (u8LocalGDidxPrmClasFrf5T != 0)
      {
         VEMS_vidGET1DArrayElement(GD_au32prmClasFrf5NoFrf,
                                   u8LocalIdx,
                                   u32LocalGD_au32prmClasFrf5NoFrf);
         VEMS_vidGET1DArrayElement(GD_au16prmClasDID5,
                                   u8LocalIdx,
                                   u16LocalGD_au16prmClasDID);
         u8DestBuffer[u8LocalBuf] = (uint8)(( u16LocalGD_au16prmClasDID
                                            & 0xFF00) >> 8);
         u8DestBuffer[u8LocalBuf + 1] = (uint8)( u16LocalGD_au16prmClasDID
                                               & 0x00FF);
         if (u8LocalGDidxPrmClasFrf5T < NB_PARAM)
         {
            u8LocalLong = GD_au8SizeParam[u8LocalGDidxPrmClasFrf5T];
            u8LocalLong = (uint8)MATHSRV_udtMIN(u8LocalLong, 4);
            for (u32LocalId = 1; u32LocalId <= u8LocalLong; u32LocalId++)
            {
               u8LocalPos = (uint8)((u8LocalBuf + 1) + u32LocalId);
               u8LocalMask = (uint8)(8 * ((3 + u32LocalId) - u8LocalLong));
               u8LocalShift = (uint8)(8 * (u8LocalLong - u32LocalId));
               u8DestBuffer[u8LocalPos] =
                  (uint8)(( u32LocalGD_au32prmClasFrf5NoFrf
                          & (4278190080UL >> u8LocalMask)) >> u8LocalShift);
            }
            u8LocalBuf = (uint8)((u8LocalBuf + 2) + u8LocalLong);
         }
         u8DestBuffer[1] = (uint8)(u8DestBuffer[1] + 1);
      }
      u8LocalGDidxPrmClasFrf6T =
                     GD_astrClasFrf[u8LocalIndxPanne].u8ClasFrfParam6;
      if (u8LocalGDidxPrmClasFrf6T != 0)
      {
         VEMS_vidGET1DArrayElement(GD_au32prmClasFrf6NoFrf,
                                   u8LocalIdx,
                                   u32LocalGD_au32prmClasFrf6NoFrf);
         VEMS_vidGET1DArrayElement(GD_au16prmClasDID6,
                                   u8LocalIdx,
                                   u16LocalGD_au16prmClasDID);
         u8DestBuffer[u8LocalBuf] = (uint8)(( u16LocalGD_au16prmClasDID
                                            & 0xFF00) >> 8);
         u8DestBuffer[u8LocalBuf + 1] = (uint8)( u16LocalGD_au16prmClasDID
                                               & 0x00FF);
         if (u8LocalGDidxPrmClasFrf6T < NB_PARAM)
         {
            u8LocalLong = GD_au8SizeParam[u8LocalGDidxPrmClasFrf6T];
            u8LocalLong = (uint8)MATHSRV_udtMIN(u8LocalLong, 4);
            for (u32LocalId = 1; u32LocalId <= u8LocalLong; u32LocalId++)
            {
               u8LocalPos = (uint8)((u8LocalBuf + 1) + u32LocalId);
               u8LocalMask = (uint8)(8 * ((3 + u32LocalId) - u8LocalLong));
               u8LocalShift = (uint8)(8 * (u8LocalLong - u32LocalId));
               u8DestBuffer[u8LocalPos] =
                  (uint8)(( u32LocalGD_au32prmClasFrf6NoFrf
                          & (4278190080UL >> u8LocalMask)) >> u8LocalShift);
            }
            u8LocalBuf = (uint8)((u8LocalBuf + 2) + u8LocalLong);
         }
         u8DestBuffer[1] = (uint8)(u8DestBuffer[1] + 1);
      }
      u8LocalGDidxPrmClasFrf7T =
                     GD_astrClasFrf[u8LocalIndxPanne].u8ClasFrfParam7;
      if (u8LocalGDidxPrmClasFrf7T != 0)
      {
         VEMS_vidGET1DArrayElement(GD_au32prmClasFrf7NoFrf,
                                   u8LocalIdx,
                                   u32LocalGD_au32prmClasFrf7NoFrf);
         VEMS_vidGET1DArrayElement(GD_au16prmClasDID7,
                                   u8LocalIdx,
                                   u16LocalGD_au16prmClasDID);
         u8DestBuffer[u8LocalBuf] = (uint8)(( u16LocalGD_au16prmClasDID
                                            & 0xFF00) >> 8);
         u8DestBuffer[u8LocalBuf + 1] = (uint8)( u16LocalGD_au16prmClasDID
                                               & 0x00FF);
         if (u8LocalGDidxPrmClasFrf7T < NB_PARAM)
         {
            u8LocalLong = GD_au8SizeParam[u8LocalGDidxPrmClasFrf7T];
            u8LocalLong = (uint8)MATHSRV_udtMIN(u8LocalLong, 4);
            for (u32LocalId = 1; u32LocalId <= u8LocalLong; u32LocalId++)
            {
               u8LocalPos = (uint8)((u8LocalBuf + 1) + u32LocalId);
               u8LocalMask = (uint8)(8 * ((3 + u32LocalId) - u8LocalLong));
               u8LocalShift = (uint8)(8 * (u8LocalLong - u32LocalId));
               u8DestBuffer[u8LocalPos] =
                  (uint8)(( u32LocalGD_au32prmClasFrf7NoFrf
                          & (4278190080UL >> u8LocalMask)) >> u8LocalShift);
            }
            u8LocalBuf = (uint8)((u8LocalBuf + 2) + u8LocalLong);
         }
         u8DestBuffer[1] = (uint8)(u8DestBuffer[1] + 1);
      }
      u8LocalGDidxPrmClasFrf8T =
                     GD_astrClasFrf[u8LocalIndxPanne].u8ClasFrfParam8;
      if (u8LocalGDidxPrmClasFrf8T != 0)
      {
         VEMS_vidGET1DArrayElement(GD_au32prmClasFrf8NoFrf,
                                   u8LocalIdx,
                                   u32LocalGD_au32prmClasFrf8NoFrf);
         VEMS_vidGET1DArrayElement(GD_au16prmClasDID8,
                                   u8LocalIdx,
                                   u16LocalGD_au16prmClasDID);
         u8DestBuffer[u8LocalBuf] = (uint8)(( u16LocalGD_au16prmClasDID
                                            & 0xFF00) >> 8);
         u8DestBuffer[u8LocalBuf + 1] = (uint8)( u16LocalGD_au16prmClasDID
                                               & 0x00FF);
         if (u8LocalGDidxPrmClasFrf8T < NB_PARAM)
         {
            u8LocalLong = GD_au8SizeParam[u8LocalGDidxPrmClasFrf8T];
            u8LocalLong = (uint8)MATHSRV_udtMIN(u8LocalLong, 4);
            for (u32LocalId = 1; u32LocalId <= u8LocalLong; u32LocalId++)
            {
               u8LocalPos = (uint8)((u8LocalBuf + 1) + u32LocalId);
               u8LocalMask = (uint8)(8 * ((3 + u32LocalId) - u8LocalLong));
               u8LocalShift = (uint8)(8 * (u8LocalLong - u32LocalId));
               u8DestBuffer[u8LocalPos] =
                  (uint8)(( u32LocalGD_au32prmClasFrf8NoFrf
                          & (4278190080UL >> u8LocalMask)) >> u8LocalShift);
            }
            u8LocalBuf = (uint8)((u8LocalBuf + 2) + u8LocalLong);
         }
         u8DestBuffer[1] = (uint8)(u8DestBuffer[1] + 1);
      }
      u8LocalGDidxPrmClasFrf9T =
                     GD_astrClasFrf[u8LocalIndxPanne].u8ClasFrfParam9;
      if (u8LocalGDidxPrmClasFrf9T != 0)
      {
         VEMS_vidGET1DArrayElement(GD_au32prmClasFrf9NoFrf,
                                   u8LocalIdx,
                                   u32LocalGD_au32prmClasFrf9NoFrf);
         VEMS_vidGET1DArrayElement(GD_au16prmClasDID9,
                                   u8LocalIdx,
                                   u16LocalGD_au16prmClasDID);
         u8DestBuffer[u8LocalBuf] = (uint8)(( u16LocalGD_au16prmClasDID
                                            & 0xFF00) >> 8);
         u8DestBuffer[u8LocalBuf + 1] = (uint8)( u16LocalGD_au16prmClasDID
                                               & 0x00FF);
         if (u8LocalGDidxPrmClasFrf9T < NB_PARAM)
         {
            u8LocalLong = GD_au8SizeParam[u8LocalGDidxPrmClasFrf9T];
            u8LocalLong = (uint8)MATHSRV_udtMIN(u8LocalLong, 4);
            for (u32LocalId = 1; u32LocalId <= u8LocalLong; u32LocalId++)
            {
               u8LocalPos = (uint8)((u8LocalBuf + 1) + u32LocalId);
               u8LocalMask = (uint8)(8 * ((3 + u32LocalId) - u8LocalLong));
               u8LocalShift = (uint8)(8 * (u8LocalLong - u32LocalId));
               u8DestBuffer[u8LocalPos] =
                  (uint8)(( u32LocalGD_au32prmClasFrf9NoFrf
                          & (4278190080UL >> u8LocalMask)) >> u8LocalShift);
            }
            u8LocalBuf = (uint8)((u8LocalBuf + 2) + u8LocalLong);
         }
        /*Msg(3:3199) The value of 'u8LocalBuf' is never used following this
        assignment.*/
         u8DestBuffer[1] = (uint8)(u8DestBuffer[1] + 1);
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_GetDTCStatAvailbltyMask                           */
/* !Description :  Gets the DTC Status availability mask.                     */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GDEXTINT_GetDTCStatAvailbltyMask
(
   uint8* u8DTCStatusMask
)
{
   Std_ReturnType udtLocalStatus;
   /*Msg(2:3204) The variable 'udtLocalStatus' is only set once - the use of
   'const' should be considered to indicate that it never changes.*/


   *u8DTCStatusMask = 0xFF;
   udtLocalStatus = E_OK;

   return (udtLocalStatus);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_GetTranslationType                                */
/* !Description :  Gets the supported DTC formats of the ECU. The supported   */
/*                 formats are  configured via DemTypeOfDTCSupported.         */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
uint8 GDEXTINT_GetTranslationType(void)
{
   uint8 udtLocalStatus;
   /*Msg(2:3204) The variable 'udtLocalStatus' is only set once - the use of
   'const' should be considered to indicate that it never changes.*/


   udtLocalStatus = DEM_TYPE_OF_DTC_SUPPORTED ;

   return (udtLocalStatus);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_GetDTCOfOBDFreezeFrame                            */
/* !Description :  Gets DTC by freeze frame record number.                    */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Fault_context_eep_eobd[16];                                   */
/*  input uint8 Free_context_eobd;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GDEXTINT_GetDTCOfOBDFreezeFrame
(
   uint8 u8FrameNumber,
   uint32* u32DTC
)
{
   Std_ReturnType udtLocalStatus;
   uint8          u8LocalFault_context_eep_eobd[FAULT_CONTEXT_EEP_EOBD_COLS];
   uint8          u8LocalFree_context_eobd;


   VEMS_vidGET1DArray(Fault_context_eep_eobd,
                      FAULT_CONTEXT_EEP_EOBD_COLS,
                      u8LocalFault_context_eep_eobd);
   if (u8FrameNumber == 0x00)
   {
      VEMS_vidGET(Free_context_eobd, u8LocalFree_context_eobd);
      if (u8LocalFree_context_eobd != 0x01)
      {
         *u32DTC = (uint32)( (u8LocalFault_context_eep_eobd[0] * 65536)
                           + (u8LocalFault_context_eep_eobd[1] * 256)
                           + u8LocalFault_context_eep_eobd[2]);
      }
      else
      {
         *u32DTC = 0x000000;
      }
      udtLocalStatus = E_OK;
   }
   else
   {
      udtLocalStatus = E_NOT_OK;
   }
   return (udtLocalStatus);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_ReadDataOfOBDFreezeFrame                          */
/* !Description :  Gets data element per PID and index of the most important  */
/*                 freeze frame being selected for the output of service $02. */
/*                 The function stores the data in the provided  DestBuffer.  */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Free_context_eobd;                                            */
/*  input uint8 Fault_context_eep_eobd[16];                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GDEXTINT_ReadDataOfOBDFreezeFrame
(
   uint8 u8PID,
   uint8 u8DataElementIndexOfPID,
   uint8* u8DestBuffer,
   uint8* u8BufSize
)
{
   boolean        bLocalTest;
   Std_ReturnType udtLocalStatus;
   uint8          u8LocalFault_context_eep_eobd[FAULT_CONTEXT_EEP_EOBD_COLS];
   uint8          u8LocalFree_context_eobd;


   VEMS_vidGET(Free_context_eobd, u8LocalFree_context_eobd);
   if (u8LocalFree_context_eobd == 0x01)
   {
      *u8BufSize = 0;
      udtLocalStatus = E_OK;
   }
   else
   {
      VEMS_vidGET1DArray(Fault_context_eep_eobd,
                         FAULT_CONTEXT_EEP_EOBD_COLS,
                         u8LocalFault_context_eep_eobd);
      if (  (*u8BufSize > 0)
         && (u8DataElementIndexOfPID == 0))
      {
         bLocalTest = 1;
      }
      else
      {
         bLocalTest = 0;
      }
      switch(u8PID)
      {
         case 0x03:
         if (  (*u8BufSize > 1)
            && (u8DataElementIndexOfPID == 0))
         {
            u8DestBuffer[0] = u8LocalFault_context_eep_eobd[3];
            u8DestBuffer[1] = 0x00;
            *u8BufSize = 2;
            udtLocalStatus = E_OK;
         }
         else
         {
            udtLocalStatus = E_NOT_OK;
         }
         break;

         case 0x04:
         if (bLocalTest != 0)
         {
            u8DestBuffer[0] = u8LocalFault_context_eep_eobd[4];
            *u8BufSize = 1;
            udtLocalStatus = E_OK;
         }
         else
         {
            udtLocalStatus = E_NOT_OK;
         }
         break;

         case 0x05:
         if (bLocalTest != 0)
         {
            u8DestBuffer[0] = u8LocalFault_context_eep_eobd[5];
            *u8BufSize = 1;
            udtLocalStatus = E_OK;
         }
         else
         {
            udtLocalStatus = E_NOT_OK;
         }
         break;

         case 0x06:
         if (bLocalTest != 0)
         {
            u8DestBuffer[0] = u8LocalFault_context_eep_eobd[6];
            *u8BufSize = 1;
            udtLocalStatus = E_OK;
         }
         else
         {
            udtLocalStatus = E_NOT_OK;
         }
         break;

         case 0x07:
         if (bLocalTest != 0)
         {
            u8DestBuffer[0] = u8LocalFault_context_eep_eobd[7];
            *u8BufSize = 1;
            udtLocalStatus = E_OK;
         }
         else
         {
            udtLocalStatus = E_NOT_OK;
         }
         break;

         case 0x0B:
         if (bLocalTest != 0)
         {
            u8DestBuffer[0] = u8LocalFault_context_eep_eobd[8];
            *u8BufSize = 1;
            udtLocalStatus = E_OK;
         }
         else
         {
            udtLocalStatus = E_NOT_OK;
         }
         break;

         case 0x0C:
         if (  (*u8BufSize > 1)
            && (u8DataElementIndexOfPID == 0))
         {
            u8DestBuffer[0] = u8LocalFault_context_eep_eobd[9];
            u8DestBuffer[1] = u8LocalFault_context_eep_eobd[10];
            *u8BufSize = 2;
            udtLocalStatus = E_OK;
         }
         else
         {
            udtLocalStatus = E_NOT_OK;
         }
         break;

         case 0x0D:
         if (bLocalTest != 0)
         {
            u8DestBuffer[0] = u8LocalFault_context_eep_eobd[11];
            *u8BufSize = 1;
            udtLocalStatus = E_OK;
         }
         else
         {
            udtLocalStatus = E_NOT_OK;
         }
         break;

         case 0x23:
         if (  (*u8BufSize > 1)
            && (u8DataElementIndexOfPID == 0))
         {
            u8DestBuffer[0] = u8LocalFault_context_eep_eobd[12];
            u8DestBuffer[1] = u8LocalFault_context_eep_eobd[13];
            *u8BufSize = 2;
            udtLocalStatus = E_OK;
         }
         else
         {
            udtLocalStatus = E_NOT_OK;
         }
         break;

         case 0x42:
         if (  (*u8BufSize > 1)
            && (u8DataElementIndexOfPID == 0))
         {
            u8DestBuffer[0] = u8LocalFault_context_eep_eobd[14];
            u8DestBuffer[1] = u8LocalFault_context_eep_eobd[15];
            *u8BufSize = 2;
            udtLocalStatus = E_OK;
         }
         else
         {
            udtLocalStatus = E_NOT_OK;
         }
         break;

         default:
         udtLocalStatus = E_NOT_OK;
         SWFAIL_vidSoftwareErrorHook();
         break;
      }
   }
   return (udtLocalStatus);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_DcmReadDataOfPID01                                */
/* !Description :  Service to report the value of PID $01 computed by the Dem.*/
/* !Number      :  FCT2.9                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 GD_au8StFrfRecNoFrf[40];                                      */
/*  input uint16 GD_au16idxDftNoFrf[40];                                      */
/*  input uint8 GD_prmDtcStatus[8];                                           */
/*  input GD_strClasObd GD_astrClasObd[40];                                   */
/*  input boolean GMIL_bWarnSt;                                               */
/*  input uint16 Rdy_u16ClasRdy_EEPROM;                                       */
/*  input uint8 GD_bfAvlRdy_C;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GDEXTINT_DcmReadDataOfPID01
(
   uint8* u8PID01value
)
{
   boolean        bLocalGMIL_bWarnSt;
   boolean        bLocalRdy_bMisf;
   boolean        bLocalRdy_bLfbk;
   boolean        bLocalRdy_bCpt;
   boolean        bLocalRdy_bCat;
   boolean        bLocalRdy_bHeatCat;
   boolean        bLocalRdy_bEVAP;
   boolean        bLocalRdy_bIAE;
   boolean        bLocalRdy_bClim;
   boolean        bLocalRdy_bO2S;
   boolean        bLocalRdy_bHeatO2;
   boolean        bLocalRdy_bVVT;
   Std_ReturnType udtLocalStatus;
   uint8          u8LocalCount_rec;
   uint8          u8LocalStFrfRec;
   uint8          u8LocalGD_prmDtcStatus;
   uint8          u8LocalBitSum;
   uint8          u8LocalBitSum1;
   uint8          u8LocalBitSum2;
   uint16         u16LocalTabSize;
   uint16         u16LocalIndPanne;
   sint32         s32LocalIdx;

   /* The bits 0 to 6 of PID $01’s A byte represents the number of OBD confirmed
   failures (available to the OBD mode $03) */
   u8LocalCount_rec = 0;
   for (s32LocalIdx = 0;
        s32LocalIdx < GD_NB_DFTCXTMAX;
        s32LocalIdx++)
   {
      VEMS_vidGET1DArrayElement(GD_au8StFrfRecNoFrf,s32LocalIdx,
                                u8LocalStFrfRec);
      if (u8LocalStFrfRec == 2)
      {
         VEMS_vidGET1DArrayElement(GD_au16idxDftNoFrf,s32LocalIdx,
                                   u16LocalIndPanne);

         u16LocalTabSize = (uint16)(GD_DFT_NB - 1);
         if (u16LocalIndPanne <= u16LocalTabSize)
         {
            VEMS_vidGET1DArrayElement(GD_prmDtcStatus,
                                      u16LocalIndPanne,
                                      u8LocalGD_prmDtcStatus);
            if (  ( (u8LocalGD_prmDtcStatus & 0x08) == 0x08)
               && (GD_astrClasObd[GD_au8IdxClasObd
                                       [u16LocalIndPanne]].bEnaSctl != 0))
            {
               u8LocalCount_rec = (uint8)(u8LocalCount_rec + 1);
            }
         }
         else
         {
            SWFAIL_vidSoftwareErrorHook();
         }
      }
   }

   /* The C byte of the PID $01 represents the supported tests run at least once
   per trip */
   u8LocalBitSum = (uint8)(u8LocalCount_rec & 0x7F);

   VEMS_vidGET(GMIL_bWarnSt, bLocalGMIL_bWarnSt);
   bLocalRdy_bMisf = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM, MISF);
   bLocalRdy_bLfbk = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM, LFBK);
   bLocalRdy_bCpt = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM, CPT);

   if (bLocalGMIL_bWarnSt != 0)
   {
      u8LocalBitSum = (uint8)(u8LocalBitSum | 0x80);
   }
   u8PID01value[0] = u8LocalBitSum;

   u8LocalBitSum1 = 7;
   if (bLocalRdy_bMisf == 0)
   {
      u8LocalBitSum1 = (uint8)(u8LocalBitSum1 | 0x10);
   }
   if (bLocalRdy_bLfbk == 0)
   {
      u8LocalBitSum1 = (uint8)(u8LocalBitSum1 | 0x20);
   }
   if (bLocalRdy_bCpt == 0)
   {
      u8LocalBitSum1 = (uint8)(u8LocalBitSum1 | 0x40);
   }
   u8PID01value[1] = u8LocalBitSum1;

   /* The C byte of the PID $01 represents the supported tests run at least once
   per trip */

   u8PID01value[2] = GD_bfAvlRdy_C;

   /* The D byte of the PID $01 represents the status of tests run at least once
   per trip */
   bLocalRdy_bCat = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM, CAT);
   bLocalRdy_bHeatCat = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM, HEATCAT);
   bLocalRdy_bEVAP = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM, EVAP);
   bLocalRdy_bIAE = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM, IAE);
   bLocalRdy_bClim = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM, CLIM);
   bLocalRdy_bO2S = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM, O2S);
   bLocalRdy_bHeatO2 = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM, HEATO2);
   bLocalRdy_bVVT = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM, VVTRC01);

   u8LocalBitSum2 = 0;
   if (  ((GD_bfAvlRdy_C & 0x01) != 0)
      && (bLocalRdy_bCat == 0))
   {
      u8LocalBitSum2 = (uint8)(u8LocalBitSum2 + 1);
   }
   if (  ((GD_bfAvlRdy_C & 0x02) != 0)
      && (bLocalRdy_bHeatCat == 0))
   {
      u8LocalBitSum2 = (uint8)(u8LocalBitSum2 + 2);
   }
   if (  ((GD_bfAvlRdy_C & 0x04) != 0)
      && (bLocalRdy_bEVAP == 0))
   {
      u8LocalBitSum2 = (uint8)(u8LocalBitSum2 + 4);
   }
   if (  ((GD_bfAvlRdy_C & 0x08) != 0)
      && (bLocalRdy_bIAE == 0))
   {
      u8LocalBitSum2 = (uint8)(u8LocalBitSum2 + 8);
   }
   if (  ((GD_bfAvlRdy_C & 0x10) != 0)
      && (bLocalRdy_bClim == 0))
   {
      u8LocalBitSum2 = (uint8)(u8LocalBitSum2 + 16);
   }
   if (  ((GD_bfAvlRdy_C & 0x20) != 0)
      && (bLocalRdy_bO2S == 0))
   {
      u8LocalBitSum2 = (uint8)(u8LocalBitSum2 + 32);
   }
   if (  ((GD_bfAvlRdy_C & 0x40) != 0)
      && (bLocalRdy_bHeatO2 == 0))
   {
      u8LocalBitSum2 = (uint8)(u8LocalBitSum2 + 64);
   }
   if (  ((GD_bfAvlRdy_C & 0x80) != 0)
      && (bLocalRdy_bVVT == 0))
   {
      u8LocalBitSum2 = (uint8)(u8LocalBitSum2 + 128);
   }
   u8PID01value[3] = u8LocalBitSum2;
   udtLocalStatus = E_OK;
   return (udtLocalStatus);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_vidEveRst_GDExtInt                                */
/* !Description :  Return old value of the GAR upon changes of the event      */
/*                 status                                                     */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 GD_prmDtcStatus[8];                                           */
/*  output uint8 u8StatusOld[8];                                              */
/*  output uint8 GD_idxDftFilt[30][2];                                        */
/*  output uint8 GD_ctDftFilt;                                                */
/*  output uint8 GD_ctDftNxtFilt;                                             */
/*  output boolean GD_bInhDft;                                                */
/*  output boolean GD_bInhFrfRec;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDEXTINT_vidEveRst_GDExtInt(void)
{
   uint8  u8LocalDtcStatusElmnt;
   sint32 s32LocalIndex;
   sint32 s32LocalIndex2;


   for (s32LocalIndex = 0; s32LocalIndex < GD_DFT_NB; s32LocalIndex++)
   {
      VEMS_vidGET1DArrayElement(GD_prmDtcStatus,
                                s32LocalIndex,
                                u8LocalDtcStatusElmnt);
      u8StatusOld[s32LocalIndex] = u8LocalDtcStatusElmnt;
   }
   for (s32LocalIndex2 = 0; s32LocalIndex2 < GD_NB_DFTMEMMAX; s32LocalIndex2++)
   {
      GD_idxDftFilt[s32LocalIndex2][0] = 0;
      GD_idxDftFilt[s32LocalIndex2][1] = 0;
   }
   GD_ctDftFilt = 0;
   GD_ctDftNxtFilt = 0;
   GD_bInhDft = 0;
   VEMS_vidSET(GD_bInhFrfRec, 0);
}

/*------------------------------- end of file --------------------------------*/