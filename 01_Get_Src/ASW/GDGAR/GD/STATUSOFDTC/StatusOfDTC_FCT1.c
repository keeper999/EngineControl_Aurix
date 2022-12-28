/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GDGAR                                                   */
/* !Description     : This is the default manager component                   */
/*                                                                            */
/* !Module          : StatusOfDTC                                             */
/* !Description     : StatusOfDTC module                                      */
/*                                                                            */
/* !File            : STATUSOFDTC_FCT1.C                                      */
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
/*   1 / SODTC_EveRst_StatusOfDTC                                             */
/*   2 / SODTC_StGDU                                                          */
/*   3 / SODTC_StGOBD                                                         */
/*   4 / SODTC_CDThd                                                          */
/*   5 / SODTC_GlbDCStrt                                                      */
/*   6 / SODTC_EveRstDft_StatusOfDTC                                          */
/*   7 / SODTC_EveRstDftObd_StatusOfDTC                                       */
/*   8 / SODTC_DftClr                                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_5446103 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/STATUSOFDTC/StatusOfDTC_FCT1.$*/
/* $Revision::   1.10     $$Author::   mbenfrad       $$Date::   27 Aug 2013 $*/
/* $Author::   mbenfrad                               $$Date::   27 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "StatusOfDTC.h"
#include "StatusOfDTC_L.h"
#include "StatusOfDTC_IM.h"
#include "GDEXTINT.h"
#include "GD_api.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SODTC_EveRst_StatusOfDTC                                   */
/* !Description :  |                                                          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDU_tenuGetStDgo(argin uint16 u16DftIdx); */
/*  extf argret GDFRM_tenuGOBDState  GOBD_tenuGetStDgo(argin uint16           */
/* u16DftIdx);                                                                */
/*  input uint8 GD_prmDtcStatus[8];                                           */
/*  input uint8 GD_au8IdxClasObd[8];                                          */
/*  input GD_strClasObd GD_astrClasObd[40];                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SODTC_EveRst_StatusOfDTC(void)
{
   uint16               u16LocalIndex;
   uint8                u8LocalIdxClasObd;
   boolean              bLocalEnaMil;
   GDFRM_tenuGDUState   enuLocalGDUGetStDgo;
   GDFRM_tenuGOBDState  enuLocalGOBDGetStDgo;

   for (u16LocalIndex = 0; u16LocalIndex < GD_DFT_NB; u16LocalIndex++)
   {
      enuLocalGDUGetStDgo = GDU_tenuGetStDgo(u16LocalIndex);
      if (enuLocalGDUGetStDgo == GDU_ETAT_FUGITIF)
      {
         GD_vidBitWrite(GD_prmDtcStatus[u16LocalIndex],0,0);
      }

      enuLocalGOBDGetStDgo = GOBD_tenuGetStDgo(u16LocalIndex);
      if (enuLocalGOBDGetStDgo == GOBD_ETAT_HISTORIQUE_OFF)
      {
         u8LocalIdxClasObd = GD_au8IdxClasObd[u16LocalIndex];
         bLocalEnaMil = GD_astrClasObd[u8LocalIdxClasObd].bEnaMIL;

         if (bLocalEnaMil == TRUE)
         {
            GD_vidBitWrite(GD_prmDtcStatus[u16LocalIndex],7,0);
         }

         GD_vidBitWrite(GD_prmDtcStatus[u16LocalIndex],2,0);
         /* Unset Bit 2 again( only in case if EvenId is calibrated with
         OBD class containing noHealDC = 0) */
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SODTC_StGDU                                                */
/* !Description :  |                                                          */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDU_tenuGetStDgo(argin uint16 u16DftIdx); */
/*  extf argret void GD_SetEventSt(argin uint16 u16DftIdx);                   */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 GD_prmDtcStatus[8];                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SODTC_StGDU
(
   uint16 u16DftIdx
)
{
   GDFRM_tenuGDUState   enuLocalGDUGetStDgo;


   enuLocalGDUGetStDgo = GDU_tenuGetStDgo(u16DftIdx);
   switch (enuLocalGDUGetStDgo)
   {
      case GDU_ETAT_PRESENT:
         GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],0,1);
         GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],1,1);
         GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],2,1);
         GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],5,1);
         GD_SetEventSt(u16DftIdx);
         break;

      case GDU_ETAT_FUGITIF:
         GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],0,0);
         GD_SetEventSt(u16DftIdx);
         break;

      case GDU_ETAT_DEVALIDATION:
         break;

      case GDU_ETAT_PCTL_ABSENT:
         break;

      case GDU_ETAT_PCTL_PRESENT:
         break;

      case GDU_ETAT_ABSENT:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SODTC_StGOBD                                               */
/* !Description :  |                                                          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGOBDState  GOBD_tenuGetStDgo(argin uint16           */
/*  u16DftIdx);                                                               */
/*  extf argret void GD_SetEventSt(argin uint16 u16DftIdx);                   */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 GD_prmDtcStatus[8];                                           */
/*  input uint8 GD_au8IdxClasObd[8];                                          */
/*  input GD_strClasObd GD_astrClasObd[40];                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SODTC_StGOBD
(
   uint16 u16DftIdx
)
{
   uint8                u8LocalIdxClasObd;
   boolean              bLocalEnaMil;
   GDFRM_tenuGOBDState  enuLocalGOBDGetStDgo;

   enuLocalGOBDGetStDgo = GOBD_tenuGetStDgo(u16DftIdx);
   switch (enuLocalGOBDGetStDgo)
   {
      case GOBD_ETAT_OK:
         GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],2,0);
         GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],3,0);
         GD_SetEventSt(u16DftIdx);
         break;

      case GOBD_ETAT_ENREGISTRE:
         GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],3,1);
         u8LocalIdxClasObd = GD_au8IdxClasObd[u16DftIdx];
         bLocalEnaMil = GD_astrClasObd[u8LocalIdxClasObd].bEnaMIL;
         if (bLocalEnaMil == TRUE)
         {
            GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],7,1);
         }
         GD_SetEventSt(u16DftIdx);
         break;

      case GOBD_ETAT_PENDING2:
         GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],3,1);
         u8LocalIdxClasObd = GD_au8IdxClasObd[u16DftIdx];
         bLocalEnaMil = GD_astrClasObd[u8LocalIdxClasObd].bEnaMIL;
         if (bLocalEnaMil == TRUE)
         {
            GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],7,1);
         }
         GD_SetEventSt(u16DftIdx);
         break;

      case GOBD_ETAT_HISTORIQUE_ON:
         GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],2,0);
         GD_SetEventSt(u16DftIdx);
         break;

      case GOBD_ETAT_HISTORIQUE_OFF:
         u8LocalIdxClasObd = GD_au8IdxClasObd[u16DftIdx];
         bLocalEnaMil = GD_astrClasObd[u8LocalIdxClasObd].bEnaMIL;
         if (bLocalEnaMil == TRUE)
         {
            GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],7,0);
         }
         GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],2,0);
         GD_SetEventSt(u16DftIdx);
         break;

      case GOBD_ETAT_PENDING1:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SODTC_CDThd                                                */
/* !Description :  |                                                          */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDU_tenuGetStDgo(argin uint16 u16DftIdx); */
/*  extf argret void GD_SetEventSt(argin uint16 u16DftIdx);                   */
/*  input uint8 GD_prmDtcStatus[8];                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SODTC_CDThd
(
   uint16 u16DftIdx
)
{
   GDFRM_tenuGDUState   enuLocalGDUGetStDgo;


   GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],4,0);
   GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],6,0);

   enuLocalGDUGetStDgo = GDU_tenuGetStDgo(u16DftIdx);
   if (enuLocalGDUGetStDgo == GDU_ETAT_PRESENT)
   {
      GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],1,1);
   }
   GD_SetEventSt(u16DftIdx);
}/* mettre a jour STATUSOFDTC_macro.h si cette fonction evolue*/

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SODTC_GlbDCStrt                                            */
/* !Description :  |                                                          */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*  extf argret void GD_SetEventSt_reinit(argin uint16 u16DftIdx);            */
/*  input uint8 GD_prmDtcStatus[8];                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SODTC_GlbDCStrt(void)
{
   uint16  u16LocalIndex;


   for (u16LocalIndex = 0; u16LocalIndex < GD_DFT_NB; u16LocalIndex++)
   {
      GD_vidBitWrite(GD_prmDtcStatus[u16LocalIndex],6,1);
      GD_vidBitWrite(GD_prmDtcStatus[u16LocalIndex],1,0);
      GD_SetEventSt_reinit(u16LocalIndex);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SODTC_EveRstDft_StatusOfDTC                                */
/* !Description :  |                                                          */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GD_RstEventSt();                                         */
/*  output uint8 GD_prmDtcStatus[8];                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SODTC_EveRstDft_StatusOfDTC(void)
{
   uint16  u16LocalIndex;


   for (u16LocalIndex = 0; u16LocalIndex < GD_DFT_NB; u16LocalIndex++)
   {
      GD_prmDtcStatus[u16LocalIndex] = 0x50;
   }
   GD_RstEventSt();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SODTC_EveRstDftObd_StatusOfDTC                             */
/* !Description :  |                                                          */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GD_SetEventSt_reinit(argin uint16 u16DftIdx);            */
/*  input uint8 GD_au8IdxClasObd[8];                                          */
/*  input GD_strClasObd GD_astrClasObd[40];                                   */
/*  output uint8 GD_prmDtcStatus[8];                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SODTC_EveRstDftObd_StatusOfDTC(void)
{
   uint8   u8LocalIdxClasObd;
   boolean bLocalEnaSctl;
   uint16  u16LocalIndex;


   for (u16LocalIndex = 0; u16LocalIndex < GD_DFT_NB; u16LocalIndex++)
   {
      u8LocalIdxClasObd = GD_au8IdxClasObd[u16LocalIndex];
      bLocalEnaSctl = GD_astrClasObd[u8LocalIdxClasObd].bEnaSctl;
      if (bLocalEnaSctl == TRUE)
      {
         GD_prmDtcStatus[u16LocalIndex] = 0x50;
         GD_SetEventSt_reinit(u16LocalIndex);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SODTC_DftClr                                               */
/* !Description :  |                                                          */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*  input boolean GD_bAcvReinitBit5_C;                                        */
/*  input uint8 GD_prmDtcStatus[8];                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SODTC_DftClr
(
   uint16 u16DftIdx
)
{
   if (GD_bAcvReinitBit5_C == 1)
   {
      GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],5,0);
   }
}
/*------------------------------- end of file --------------------------------*/