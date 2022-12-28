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
/* !File            : GDEXTINT_FCT1.C                                         */
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
/*   1 / GDEXTINT_SetEventStatus                                              */
/*   2 / GDEXTINT_GetEventStatus                                              */
/*   3 / GDEXTINT_DisableDTCSetting                                           */
/*   4 / GDEXTINT_EnableDTCSetting                                            */
/*   5 / GDEXTINT_DisableDTCRecordUpdate                                      */
/*   6 / GDEXTINT_EnableDTCRecordUpdate                                       */
/*   7 / GDEXTINT_ClearDTC                                                    */
/*   8 / GDEXTINT_SetDTCFilter                                                */
/*   9 / GDEXTINT_GetNumberOfFilteredDTC                                      */
/*   10 / GDEXTINT_GetNextFilteredDTC                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_5075312 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GDEXTINT/GDEXTINT_FCT1.C_v   $*/
/* $Revision::   1.22     $$Author::   mbenfrad       $$Date::   27 Aug 2013 $*/
/* $Author::   mbenfrad                               $$Date::   27 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "GDExtInt.h"
#include "GDExtInt_L.h"
#include "GDExtInt_IM.h"
#include "Rte_Type.h"
#include "VEMS.h"
#include "dem.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_SetEventStatus                                    */
/* !Description :  Set the status of an Event                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf argret void GDU_vidGdu(argin uint16 u16DftIdx);                      */
/*  input boolean GD_bInhDft;                                                 */
/*  output uint8 GD_stEventStatus[8];                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GDEXTINT_SetEventStatus
(
   uint16 u16DftIdx,
   uint8 u8EventStatus
)
{
   Std_ReturnType udtLocalStatus;


   if (GD_bInhDft == 0)
   {
      if (u16DftIdx < GD_DFT_NB)
      {
         switch (u8EventStatus)
         {
            case DEM_EVENT_STATUS_PASSED:
               VEMS_vidSET1DArrayElement(GD_stEventStatus,
                                         u16DftIdx,
                                         GD_PASSED);
               udtLocalStatus = E_OK;
               break;

            case DEM_EVENT_STATUS_FAILED:
               VEMS_vidSET1DArrayElement(GD_stEventStatus,
                                         u16DftIdx,
                                         GD_FAILED);
               udtLocalStatus = E_OK;
               break;

            case DEM_EVENT_STATUS_PREPASSED:
               VEMS_vidSET1DArrayElement(GD_stEventStatus,
                                         u16DftIdx,
                                         GD_PRE_PASSED);
               udtLocalStatus = E_OK;
               break;

            case DEM_EVENT_STATUS_PREFAILED:
               VEMS_vidSET1DArrayElement(GD_stEventStatus,
                                         u16DftIdx,
                                         GD_PRE_FAILED);
               udtLocalStatus = E_OK;
               break;

            case DEM_EVENT_STATUS_INIT:
               VEMS_vidSET1DArrayElement(GD_stEventStatus,
                                         u16DftIdx,
                                         GD_INIT);
               udtLocalStatus = E_OK;
               break;

            default:
               udtLocalStatus = E_NOT_OK;
               SWFAIL_vidSoftwareErrorHook();
               break;
         }

         GDU_vidGdu(u16DftIdx);
      }
      else
      {
         udtLocalStatus = E_NOT_OK;
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      udtLocalStatus = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }
   return(udtLocalStatus);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_GetEventStatus                                    */
/* !Description :  Gets the current extended event status of an event         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 GD_prmDtcStatus[8];                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GDEXTINT_GetEventStatus
(
   uint16 u16DftIdx,
   uint8* u8EventStatusExtended
)
{
   Std_ReturnType udtLocalStatus;
   uint8          u8LocalGD_prmDtcStatus;


   if (u16DftIdx < GD_DFT_NB)
   {
      VEMS_vidGET1DArrayElement(GD_prmDtcStatus,
                                u16DftIdx,
                                u8LocalGD_prmDtcStatus);
      *u8EventStatusExtended = u8LocalGD_prmDtcStatus;
      udtLocalStatus = E_OK;
   }
   else
   {
      udtLocalStatus = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return(udtLocalStatus);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_DisableDTCSetting                                 */
/* !Description :  Disables the DTC setting for a DTC group.                  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  output boolean GD_bInhDft;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dem_ReturnControlDTCSettingType GDEXTINT_DisableDTCSetting
(
   Dem_DTCGroupType u32DTCGroup,
   Dem_DTCKindType u8DTCKind
)
{
   Dem_ReturnControlDTCSettingType udtLocalStatus;


   if (  (u32DTCGroup == DEM_DTC_GROUP_ALL_DTCS)
      && (u8DTCKind == DEM_DTC_KIND_ALL_DTCS))
   {
      GD_bInhDft = 1;
      udtLocalStatus = DEM_CONTROL_DTC_SETTING_OK;
   }
   else
   {
      udtLocalStatus = DEM_CONTROL_DTC_WRONG_DTCGROUP;
      SWFAIL_vidSoftwareErrorHook();
   }

   return(udtLocalStatus);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_EnableDTCSetting                                  */
/* !Description :  Enables the DTC setting for a DTC group.                   */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  output boolean GD_bInhDft;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dem_ReturnControlDTCSettingType GDEXTINT_EnableDTCSetting
(
   Dem_DTCGroupType u32DTCGroup,
   Dem_DTCKindType u8DTCKind
)
{
   Dem_ReturnControlDTCSettingType udtLocalStatus;


   if (  (u32DTCGroup == DEM_DTC_GROUP_ALL_DTCS)
      && (u8DTCKind == DEM_DTC_KIND_ALL_DTCS))
   {
      GD_bInhDft = 0;
      udtLocalStatus = DEM_CONTROL_DTC_SETTING_OK;
   }
   else
   {
      udtLocalStatus = DEM_CONTROL_DTC_WRONG_DTCGROUP;
      SWFAIL_vidSoftwareErrorHook();
   }

   return (udtLocalStatus);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_DisableDTCRecordUpdate                            */
/* !Description :  Enables the DTC setting for a DTC group.                   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean GD_bInhFrfRec;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GDEXTINT_DisableDTCRecordUpdate(void)
{
   Std_ReturnType udtLocalStatus;
   /*Msg(2:3204) The variable 'udtLocalStatus' is only set once - the use of
   'const' should be considered to indicate that it never changes.*/


   VEMS_vidSET(GD_bInhFrfRec, 1);
   udtLocalStatus = E_OK;

   return(udtLocalStatus);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_EnableDTCRecordUpdate                             */
/* !Description :  Disables the DTC record update.                            */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean GD_bInhFrfRec;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GDEXTINT_EnableDTCRecordUpdate(void)
{
   Std_ReturnType udtLocalStatus;
   /*Msg(2:3204) The variable 'udtLocalStatus' is only set once - the use of
   'const' should be considered to indicate that it never changes.*/


   VEMS_vidSET(GD_bInhFrfRec, 0);
   udtLocalStatus = E_OK;

   return(udtLocalStatus);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_ClearDTC                                          */
/* !Description :  Clears single DTCs as well as groups of DTCs. This API can */
/*                 only be used  through the RTE, and therefore no declaration*/
/*                 is exported via Dem.h.                                     */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDEXTINT_EveRstDft();                                    */
/*  extf argret void SUPSRV_vidRstrtProtectedOutputs();                       */
/*  extf argret void GDEXTINT_EveRstDftObd();                                 */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean GD_bEnaRstProtOutObd_C;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dem_ReturnClearDTCType GDEXTINT_ClearDTC
(
   uint32 u32DTC,
   Dem_DTCKindType u8DTCKind,
   Dem_DTCOriginType u8DTCOrigin
)
{
   Dem_ReturnClearDTCType udtLocalStatus;
   boolean                bLocalTest;


   udtLocalStatus = 0;
   bLocalTest = 0;

   if (u8DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
   {
      if (u8DTCKind == DEM_DTC_KIND_ALL_DTCS)
      {
         if (u32DTC == 0x00FFFFFF)
         {
            /* A failure clear is generated */
            GDEXTINT_EveRstDft();
            /* The failure counter of the LdB protected outputs is reset */
            SUPSRV_vidRstrtProtectedOutputs();
            udtLocalStatus = DEM_CLEAR_OK;
         }
         else
         {
            udtLocalStatus = DEM_CLEAR_WRONG_DTC;
         }
      }
      else
      {
         if (u8DTCKind == DEM_DTC_KIND_EMISSION_REL_DTCS)
         {
            if (u32DTC == 0x00)
            {
               /*An OBD failure clear is generated */
               GDEXTINT_EveRstDftObd();
               /* The failure counter of the LdB protected outputs can be reset
               for an OBD failure clear also */
               if (GD_bEnaRstProtOutObd_C != 0)
               {
                  SUPSRV_vidRstrtProtectedOutputs();
               }
               udtLocalStatus = DEM_CLEAR_OK;
            }
            else
            {
               udtLocalStatus = DEM_CLEAR_WRONG_DTC;
               SWFAIL_vidSoftwareErrorHook();
            }
         }
         else
         {
            udtLocalStatus = DEM_CLEAR_WRONG_DTCKIND;
         }
      }
   }
   else
   {
      udtLocalStatus = DEM_CLEAR_WRONG_DTCORIGIN;
   }
   return (udtLocalStatus);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_SetDTCFilter                                      */
/* !Description :  The server shall perform a bit-wise logical AND-ing        */
/*                 operation between the mask specified in the client's       */
/*                 request and the actual status associated with each DTC     */
/*                 supported by the server.                                   */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 GD_au8StFrfRecNoFrf[40];                                      */
/*  input uint16 GD_au16idxDftNoFrf[40];                                      */
/*  input uint8 GD_prmDtcStatus[8];                                           */
/*  input uint8 GD_ctDftFilt;                                                 */
/*  input uint32 GD_NoDTC[8];                                                 */
/*  input uint8 GD_idxDftFilt[30][2];                                         */
/*  input uint8 GD_au8idxFltToCxtNoFrf[40];                                   */
/*  input uint8 GD_au8IdxClasObd[8];                                          */
/*  input GD_strClasObd GD_astrClasObd[40];                                   */
/*  input uint32 GD_tiCurVehTmr_NoFrf[40];                                    */
/*  output uint8 GD_idxDftFilt[30][2];                                        */
/*  output uint8 GD_ctDftFilt;                                                */
/*  output uint8 GD_ctDftNxtFilt;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dem_ReturnSetDTCFilterType GDEXTINT_SetDTCFilter
(
   uint8 u8DTCStatusMask,
   Dem_DTCKindType u8DTCKind,
   Dem_DTCOriginType u8DTCOrigin,
   Dem_FilterWithSeverityType u8FilterWithSeverity,
   Dem_DTCSeverityType u8DTCSeverityMask,
   Dem_FilterForFDCType u8FilterForFaultDetectionCounter
)
{
   Dem_ReturnSetDTCFilterType udtLocalStatus;
   sint32                     s32LocalIdx;
   sint32                     s32LocalIdx1;
   sint32                     s32LocalIdx2;
   uint8                      u8LocalGDIdxDftFilt;
   uint8                      u8LocalStFrfRec;
   uint8                      u8LocalGD_idxDftFilt;
   uint8                      u8LocalGD_prmDtcStatus;
   uint8                      u8LocalIndPrev;
   uint8                      u8LocalBitwise;
   uint8                      u8localRegroup;
   uint8                      u8localGD_au8idxFltToCxt;
   uint8                      u8localGD_au8idxFltToCxt1;
   uint8                      u8LocalDiffVar;
   uint8                      u8LocalIdxClassObd;
   uint8                      u8LocalStDTC_prev;
   uint8                      u8LocalInd;
   uint16                     u16LocalIndPanne;
   uint16                     u16LocalTabSize;
   uint16                     u16LocalVar;
   uint32                     u32LocalGD_NoDTC;
   uint32                     u32LocalGD_NoDTC1;
   uint32                     u32LocalGD_tiCurVehTmrPrv;
   uint32                     u32LocalGD_tiCurVehTmrIdx;
   sint32                     s32LocalNbSuprDTC;


   if (  (  (u8DTCKind == DEM_DTC_KIND_ALL_DTCS)
         || (u8DTCKind == DEM_DTC_KIND_EMISSION_REL_DTCS))
      && (u8DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
      && (u8FilterWithSeverity  == DEM_FILTER_WITH_SEVERITY_NO)
      && (u8DTCSeverityMask == DEM_SEVERITY_NO_SEVERITY)
      && (u8FilterForFaultDetectionCounter == DEM_FILTER_FOR_FDC_NO))
   {
      /*The filtered DTC buffer is reinitialized*/
      for (s32LocalIdx = 0; s32LocalIdx < GD_NB_DFTMEMMAX; s32LocalIdx++)
      {
         GD_idxDftFilt[s32LocalIdx][0] = 0;
         GD_idxDftFilt[s32LocalIdx][1] = 0;
      }
      GD_ctDftFilt = 0;
      GD_ctDftNxtFilt = 0;

      if (u8DTCKind == DEM_DTC_KIND_EMISSION_REL_DTCS)
      {
         /* CALL_List */
         /*The monitors are not regrouped by DTC and are listed into a new
         buffer*/
         for (s32LocalIdx1 = 0; s32LocalIdx1 < GD_NB_DFTCXTMAX; s32LocalIdx1++)
         {
            VEMS_vidGET1DArrayElement(GD_au8StFrfRecNoFrf,
                                      s32LocalIdx1,
                                      u8LocalStFrfRec);
            if (u8LocalStFrfRec == 2)
            {
               VEMS_vidGET1DArrayElement(GD_au16idxDftNoFrf,
                                         s32LocalIdx1,
                                         u16LocalIndPanne);

               u16LocalTabSize = (uint16)(GD_DFT_NB - 1);
               u16LocalIndPanne = (uint16)MATHSRV_udtMIN(u16LocalIndPanne,
                                                         u16LocalTabSize);
         /*If the DTC is added, the buffer grows*/
               VEMS_vidGET1DArrayElement(GD_prmDtcStatus,
                                         u16LocalIndPanne,
                                         u8LocalGD_prmDtcStatus);
               GD_idxDftFilt[GD_ctDftFilt][0] = (uint8)s32LocalIdx1;
               GD_idxDftFilt[GD_ctDftFilt][1] = u8LocalGD_prmDtcStatus;
               GD_ctDftFilt = (uint8)(GD_ctDftFilt + 1);
            }
         }
         /* End CALL_List */
      }
      else
      {
         /* CALL_Regroup */

         /* In order to handle a group of monitors identified by a same DTC
         the confirmed monitors are regrouped into a buffer. */
         for (s32LocalIdx1 = 0; s32LocalIdx1 < GD_NB_DFTCXTMAX; s32LocalIdx1++)
         {
            u8localRegroup = 0;

            VEMS_vidGET1DArrayElement(GD_au8StFrfRecNoFrf,
                                      s32LocalIdx1,
                                      u8LocalStFrfRec);
            if (u8LocalStFrfRec == 2)
            {
               VEMS_vidGET1DArrayElement(GD_au16idxDftNoFrf,
                                         s32LocalIdx1,
                                         u16LocalIndPanne);

               u16LocalTabSize = (uint16)(GD_DFT_NB - 1);
               u16LocalIndPanne = (uint16)MATHSRV_udtMIN(u16LocalIndPanne,
                                                         u16LocalTabSize);

               /* If the DTC added is not the first, we verify if it doesn’t
               already exists into the buffer */

               if (GD_ctDftFilt > 0)
               {
                  for (s32LocalIdx2 = 0;
                       (  (s32LocalIdx2 < GD_ctDftFilt)
                       && (u8localRegroup == 0));
                       s32LocalIdx2++)
                  {
                     VEMS_vidGET1DArrayElement(GD_NoDTC,
                                               u16LocalIndPanne,
                                               u32LocalGD_NoDTC);

                     u8LocalGD_idxDftFilt = GD_idxDftFilt[s32LocalIdx2][0];

                     VEMS_vidGET1DArrayElement(GD_au16idxDftNoFrf,
                                               u8LocalGD_idxDftFilt,
                                               u16LocalVar);
                     u16LocalVar = (uint16)MATHSRV_udtMIN(u16LocalVar,
                                                          u16LocalTabSize);
                     VEMS_vidGET1DArrayElement(GD_NoDTC,
                                               u16LocalVar,
                                               u32LocalGD_NoDTC1);

                     if (u32LocalGD_NoDTC == u32LocalGD_NoDTC1)
                     {
                        /* If the DTC already exists into the buffer */
                        /* if its context parameters are older, its index number
                        is overwritten */

                        u8LocalInd = (uint8)(s32LocalIdx1);
                        VEMS_vidGET1DArrayElement(GD_au8idxFltToCxtNoFrf,
                                                  u8LocalInd,
                                                  u8localGD_au8idxFltToCxt);

                        VEMS_vidGET1DArrayElement(GD_au8idxFltToCxtNoFrf,
                                                  u8LocalGD_idxDftFilt,
                                                  u8localGD_au8idxFltToCxt1);

                        if ( u8localGD_au8idxFltToCxt
                           < u8localGD_au8idxFltToCxt1)
                        {
                           GD_idxDftFilt[s32LocalIdx2][0] =
                             (uint8)s32LocalIdx1;
                        }

                        VEMS_vidGET1DArrayElement(GD_prmDtcStatus,
                                                  u16LocalIndPanne,
                                                  u8LocalGD_prmDtcStatus);

                        /* StatusOfDTC are combined */

                        GD_idxDftFilt[s32LocalIdx2][1] =
                           (uint8)( GD_idxDftFilt[s32LocalIdx2][1]
                                  | u8LocalGD_prmDtcStatus);

                        if ( (GD_idxDftFilt[s32LocalIdx2][1] &
                          0x20) == 0x20)
                        {
                           GD_idxDftFilt[s32LocalIdx2][1] =
                              (uint8)(GD_idxDftFilt[s32LocalIdx2][1] &
                               0xEF);
                        }

                        if ( (GD_idxDftFilt[s32LocalIdx2][1] &
                            0x02) == 0x02)
                        {
                              GD_idxDftFilt[s32LocalIdx2][1] =
                                 (uint8)(GD_idxDftFilt[s32LocalIdx2][1] &
                                   0xBF);
                        }
                        /* A flag says if the DTC is added or regrouped */
                        u8localRegroup = 1;
                     }
                  }
               }

               if (u8localRegroup == 0)
               {
                  /* If the DTC is added, the buffer grows */
                  VEMS_vidGET1DArrayElement(GD_prmDtcStatus,
                                            u16LocalIndPanne,
                                            u8LocalGD_prmDtcStatus);
                  GD_idxDftFilt[GD_ctDftFilt][0] = (uint8)s32LocalIdx1;
                  GD_idxDftFilt[GD_ctDftFilt][1] = u8LocalGD_prmDtcStatus;
                  GD_ctDftFilt = (uint8)(GD_ctDftFilt + 1);
               }
            }
         }
      }
      /* End Call Regroup */
      /* The filter defined by DTCKind and the DTCStatusMask is applied
      to the buffer that regroups functional DTCs */
     s32LocalNbSuprDTC = 0;
      for (s32LocalIdx = 0; s32LocalIdx < GD_ctDftFilt; s32LocalIdx++)
      {
         u8LocalGD_idxDftFilt =
            GD_idxDftFilt[s32LocalIdx - s32LocalNbSuprDTC][0];
         VEMS_vidGET1DArrayElement(GD_au16idxDftNoFrf,
                                   u8LocalGD_idxDftFilt,
                                   u16LocalIndPanne);
         u16LocalTabSize = (uint16)(GD_DFT_NB - 1);
         u16LocalIndPanne = (uint16)MATHSRV_udtMIN(u16LocalIndPanne,
                                                   u16LocalTabSize);
         u8LocalIdxClassObd = GD_au8IdxClasObd[u16LocalIndPanne];
         u8LocalBitwise =
            (uint8)( GD_idxDftFilt[s32LocalIdx - s32LocalNbSuprDTC][1]
                   & u8DTCStatusMask);

         if (  (  (u8LocalBitwise == 0x00)
               && (u8DTCStatusMask != 0x00))
            || (  (u8DTCKind != DEM_DTC_KIND_ALL_DTCS)
               && (  (GD_astrClasObd[u8LocalIdxClassObd].bEnaSctl == 0)
                  || (u8DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS))))
            /*QAC Warning : Msg(3:3356) --> test imposed by the specification*/
         {
            for (s32LocalIdx1 = s32LocalIdx - s32LocalNbSuprDTC;
                 s32LocalIdx1 < (GD_ctDftFilt - 1 - s32LocalNbSuprDTC);
                 s32LocalIdx1++)
            {
               GD_idxDftFilt[s32LocalIdx1][0] =
                  GD_idxDftFilt[s32LocalIdx1 + 1][0];

               GD_idxDftFilt[s32LocalIdx1][1] =
                  GD_idxDftFilt[s32LocalIdx1 + 1][1];
            }
      /* NbSuprDTC is a parameters that prevent from jumping a line when
      a DTC is suppressed, it represent the number of suppressed DTC */
           s32LocalNbSuprDTC = s32LocalNbSuprDTC + 1 ;
         }
      }
      GD_ctDftFilt = (uint8)(GD_ctDftFilt - s32LocalNbSuprDTC);

      /* CALL_Reorder */
      /* The filtered DTCs buffer is rearranged by chronological order */

      for (s32LocalIdx2 = 1; s32LocalIdx2 < GD_ctDftFilt; s32LocalIdx2++)
      {
         u8LocalIndPrev = GD_idxDftFilt[0][0];
         u8LocalDiffVar = (uint8)(GD_ctDftFilt - (uint8)s32LocalIdx2);
         for (s32LocalIdx1 = 1;
              s32LocalIdx1 <= u8LocalDiffVar;
              s32LocalIdx1++)
         {
            /* The DTCs’ chronological order is deduced by the vehicle timer */
            u8LocalGDIdxDftFilt = GD_idxDftFilt[s32LocalIdx1][0];

            VEMS_vidGET1DArrayElement(GD_tiCurVehTmr_NoFrf,
                                      u8LocalIndPrev,
                                      u32LocalGD_tiCurVehTmrPrv);

            VEMS_vidGET1DArrayElement(GD_tiCurVehTmr_NoFrf,
                                      u8LocalGDIdxDftFilt,
                                      u32LocalGD_tiCurVehTmrIdx);

            if (u32LocalGD_tiCurVehTmrPrv > u32LocalGD_tiCurVehTmrIdx)
            {
               u8LocalStDTC_prev = GD_idxDftFilt[s32LocalIdx1 - 1][1];
               GD_idxDftFilt[s32LocalIdx1 - 1][0] =
                  GD_idxDftFilt[s32LocalIdx1][0];
               GD_idxDftFilt[s32LocalIdx1 - 1][1] =
                  GD_idxDftFilt[s32LocalIdx1][1];
               GD_idxDftFilt[s32LocalIdx1][0] = u8LocalIndPrev;
               GD_idxDftFilt[s32LocalIdx1][1] = u8LocalStDTC_prev ;
            }
            u8LocalIndPrev = GD_idxDftFilt[s32LocalIdx1][0];
         }
      }
      /* End CALL_Reorder */
      udtLocalStatus = DEM_FILTER_ACCEPTED;
   }
   else
   {
      udtLocalStatus = DEM_WRONG_FILTER;
      SWFAIL_vidSoftwareErrorHook();
   }

   return(udtLocalStatus);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_GetNumberOfFilteredDTC                            */
/* !Description :  Gets the number of a filtered DTC.                         */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 GD_ctDftFilt;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dem_ReturnGetNumberOfFilteredDTCType GDEXTINT_GetNumberOfFilteredDTC
(
   uint16* u16NumberOfFilteredDTC
)
{
   Dem_ReturnGetNumberOfFilteredDTCType udtLocalStatus;


   *u16NumberOfFilteredDTC = GD_ctDftFilt;

   if (*u16NumberOfFilteredDTC <= GD_NB_DFTCXTMAX)
   {
      udtLocalStatus = DEM_NUMBER_OK;
   }
   else
   {
      udtLocalStatus = DEM_NUMBER_FAILED;
      SWFAIL_vidSoftwareErrorHook();
   }

   return (udtLocalStatus);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_GetNextFilteredDTC                                */
/* !Description :  Gets the next filtered DTC.                                */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 GD_ctDftNxtFilt;                                              */
/*  input uint8 GD_ctDftFilt;                                                 */
/*  input uint8 GD_idxDftFilt[30][2];                                         */
/*  input uint16 GD_au16idxDftNoFrf[40];                                      */
/*  input uint32 GD_NoDTC[8];                                                 */
/*  output uint8 GD_ctDftNxtFilt;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dem_ReturnGetNextFilteredDTCType GDEXTINT_GetNextFilteredDTC
(
   uint32* u32DTC,
   uint8* u8DTCStatus
)
{
   Dem_ReturnGetNextFilteredDTCType udtLocalStatus;
   uint8                            u8LocalIndDTC;
   uint16                           u16LocalIndGDNoDTC;
   uint32                           u32LocalGD_NoDTC;


   udtLocalStatus = DEM_FILTERED_NO_MATCHING_DTC;
   if (GD_ctDftNxtFilt >= GD_ctDftFilt)
   {
      udtLocalStatus = DEM_FILTERED_NO_MATCHING_DTC;
   }
   else
   {
      if (GD_ctDftNxtFilt < GD_NB_DFTCXTMAX)
      {
         if (GD_ctDftNxtFilt < GD_NB_DFTMEMMAX)
         {
            u8LocalIndDTC = GD_idxDftFilt[GD_ctDftNxtFilt][0];
            if (u8LocalIndDTC < GD_NB_DFTCXTMAX)
            {
               VEMS_vidGET1DArrayElement(GD_au16idxDftNoFrf,
                                         u8LocalIndDTC,
                                         u16LocalIndGDNoDTC);
               if (u16LocalIndGDNoDTC < GD_DFT_NB)
               {
                  VEMS_vidGET1DArrayElement(GD_NoDTC,
                                            u16LocalIndGDNoDTC,
                                            u32LocalGD_NoDTC);
                  if (u32LocalGD_NoDTC == 0x00FFFFFF)
                  {
                     *u32DTC = 0x00FFFFFF;
                     *u8DTCStatus = GD_idxDftFilt[GD_ctDftNxtFilt][1];
                     udtLocalStatus = DEM_FILTERED_NO_MATCHING_DTC;
                     /*Msg(3:3198) The value assigned to 'udtLocalStatus' is
                     always modified before being used.*/
                  }
                  else
                  {
                     *u32DTC = u32LocalGD_NoDTC;
                     *u8DTCStatus = GD_idxDftFilt[GD_ctDftNxtFilt][1];
                     udtLocalStatus = DEM_FILTERED_OK;
                  }

                  GD_ctDftNxtFilt = (uint8)(GD_ctDftNxtFilt + 1);
               }
               else
               {
                  udtLocalStatus = DEM_FILTERED_NO_MATCHING_DTC;
                  SWFAIL_vidSoftwareErrorHook();
               }
            }
            else
            {
               udtLocalStatus = DEM_FILTERED_NO_MATCHING_DTC;
               SWFAIL_vidSoftwareErrorHook();
            }
         }
         else
         {
            SWFAIL_vidSoftwareErrorHook();
         }
      }
      else
      {
         udtLocalStatus = DEM_FILTERED_NO_MATCHING_DTC;
         SWFAIL_vidSoftwareErrorHook();
      }
   }

   return (udtLocalStatus);
}
/*------------------------------- end of file --------------------------------*/