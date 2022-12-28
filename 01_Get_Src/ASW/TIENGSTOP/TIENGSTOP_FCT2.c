/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TIENGSTOP                                               */
/* !Description     : TIENGSTOP Component                                     */
/*                                                                            */
/* !Module          : TIENGSTOP                                               */
/* !Description     : DUREE D’ARRET MOTEUR                                    */
/*                                                                            */
/* !File            : TIENGSTOP_FCT2.c                                        */
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
/*   1 / TIENGSTOP_vidEmfDate                                                 */
/*   2 / TIENGSTOP_vidEmfDateCalc                                             */
/*   3 / TIENGSTOP_vidTimeBuffer                                              */
/*   4 / TIENGSTOP_vidInitTimeSinceStall                                      */
/*   5 / TIENGSTOP_vidEmfDateSinceStall                                       */
/*   6 / TIENGSTOP_vidEmfActiveDate                                           */
/*   7 / TIENGSTOP_vidEmfValidCrankDate                                       */
/*   8 / TIENGSTOP_vidEmfDateCoh                                              */
/*   9 / TIENGSTOP_vidEmfInvalidCrankDate                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5329313 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ENGST/TIENGSTOP/TIENGSTOP_FCT2.C$*/
/* $Revision::   1.7      $$Author::   HHAMLAOU       $$Date::   02 Jul 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   02 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TIENGSTOP.h"
#include "TIENGSTOP_L.h"
#include "TIENGSTOP_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIENGSTOP_vidEmfDate                                       */
/* !Description :  Si  l'information  temporelle provenant du véhicule est    */
/*                 invalide, La durée d'arrêt ne pourra pas être évaluée de   */
/*                 manière nominale. Par conséquent, la valeur " durée d'arrêt*/
/*                 moteur " aura en  interne de  la fonction une valeur       */
/*                 invalide                                                   */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_12_01073_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void TIENGSTOP_vidEmfDateCalc();                              */
/*  extf argret void TIENGSTOP_vidEmfInvalidCrankDate();                      */
/*  input boolean Date_emf_available_mux;                                     */
/*  input uint16 Ext_nEng;                                                    */
/*  output boolean EOM_bMonRunORng_tiEngStop;                                 */
/*  output boolean EOM_bMonRunCoh_tiEngStop;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIENGSTOP_vidEmfDate(void)
{
   /*F04_date_emf*/
   boolean bLocalDate_emf_available_mux;
   boolean bLocalFRMAcvEstimTiEngStop;
   uint16  u16LocalExt_nEng;


   VEMS_vidGET(Date_emf_available_mux, bLocalDate_emf_available_mux);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   bLocalFRMAcvEstimTiEngStop = GDGAR_bGetFRM(FRM_FRM_ACVESTIMTIENGSTOP);

   if (  (bLocalDate_emf_available_mux != 0)
      && (bLocalFRMAcvEstimTiEngStop == 0))
   {
      EOM_bMonRunORng_tiEngStop = 1;
      EOM_bMonRunCoh_tiEngStop = 1;
      /*F01_calcul_date_emf*/
      TIENGSTOP_vidEmfDateCalc();
   }
   else
   {
      EOM_bMonRunORng_tiEngStop = 0;
      EOM_bMonRunCoh_tiEngStop = 0;
      if (u16LocalExt_nEng > 0)
      {
         /*F02_date_emf_invalide_demarrage*/
         TIENGSTOP_vidEmfInvalidCrankDate();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIENGSTOP_vidEmfDateCalc                                   */
/* !Description :  A partir de l'arrêt moteur (N=0), le CMM évalue en temps   */
/*                 réel la durée écoulée entre le  dernier arrêt moteur (suite*/
/*                 à un calage, une demande conducteur, ou une demande STT) et*/
/*                 le nouveau passage de dents vilebrequin.                   */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_12_01073_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TIENGSTOP_vidTimeBuffer();                               */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void TIENGSTOP_vidEmfActiveDate();                            */
/*  extf argret void TIENGSTOP_vidInitTimeSinceStall();                       */
/*  extf argret void TIENGSTOP_vidEmfDateSinceStall();                        */
/*  extf argret void TIENGSTOP_vidEmfDateCoh();                               */
/*  input uint8 ISCAN_u8Compteur_RX_552;                                      */
/*  input uint8 TIENGSTOP_u8CtTiIndex;                                        */
/*  input uint8 EngSt_ctCohRx552Thd_C;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean Date_emf_init_time_since_stall;                             */
/*  input uint16 TIENGSTOP_u16Ext_nEngPrev;                                   */
/*  input uint32 Time_since_stall;                                            */
/*  input uint32 EOM_tiEngStopRst;                                            */
/*  input boolean EngSt_bDiagCohCtTi;                                         */
/*  output boolean Date_emf_init_time_since_stall;                            */
/*  output uint16 TIENGSTOP_u16Ext_nEngPrev;                                  */
/*  output uint32 Time_since_stall;                                           */
/*  output uint32 EOM_tiEngStop;                                              */
/*  output uint32 EOM_tiEngStopRst;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIENGSTOP_vidEmfDateCalc(void)
{
   /*F01_calcul_date_emf*/
   uint8  u8LocalISCAN_u8Compteur_RX_552;
   uint16 u16LocalExt_nEng;
   uint32 u32LocalTime_since_stall;
   uint32 u32LocalEOM_tiEngStopRst;

   VEMS_vidGET(ISCAN_u8Compteur_RX_552, u8LocalISCAN_u8Compteur_RX_552);
   if (  (TIENGSTOP_u8CtTiIndex <= 2)
      && (u8LocalISCAN_u8Compteur_RX_552 >= EngSt_ctCohRx552Thd_C))
   {
      /*F01_time_buffer*/
      TIENGSTOP_vidTimeBuffer();
   }

   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   if( Date_emf_init_time_since_stall == 0)
   {
      if ( (TIENGSTOP_u16Ext_nEngPrev == 0)
         &&(u16LocalExt_nEng > 0))
      {
         Date_emf_init_time_since_stall = 1;
      }
   }
   TIENGSTOP_u16Ext_nEngPrev = u16LocalExt_nEng;
   if (u16LocalExt_nEng != 0)
   {
      VEMS_vidGET(Time_since_stall, u32LocalTime_since_stall);
      VEMS_vidGET(EOM_tiEngStopRst, u32LocalEOM_tiEngStopRst);
      u32LocalTime_since_stall =
         MATHSRV_udtMIN(u32LocalTime_since_stall, 864000);
      u32LocalEOM_tiEngStopRst =
         MATHSRV_udtMIN(u32LocalEOM_tiEngStopRst, 864000);
      VEMS_vidSET(Time_since_stall, u32LocalTime_since_stall);
      VEMS_vidSET(EOM_tiEngStop, u32LocalTime_since_stall);
      VEMS_vidSET(EOM_tiEngStopRst, u32LocalEOM_tiEngStopRst);
      /*F04_date_emf_actif*/
      TIENGSTOP_vidEmfActiveDate();
   }
   else
   {
      if (Date_emf_init_time_since_stall == 0)
      {
         /*F02_init_time_since_stall*/
         TIENGSTOP_vidInitTimeSinceStall();
      }
      else
      {
         /*F03_date_emf_depuis_cale*/
         TIENGSTOP_vidEmfDateSinceStall();
      }
   }

   if (  (EngSt_bDiagCohCtTi == 0)
      && (TIENGSTOP_u8CtTiIndex == 3))
   {
      /*F05_coh_date_emf*/
      TIENGSTOP_vidEmfDateCoh();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIENGSTOP_vidTimeBuffer                                    */
/* !Description :  Cette fonction permet d'enregistrer la date dans les       */
/*                 buffeurs de sauvegarde.                                    */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint32 Ext_ctSec;                                                   */
/*  input uint16 Ext_ctDay;                                                   */
/*  input uint8 Ext_ctYr;                                                     */
/*  input uint8 TIENGSTOP_u8CtTiIndex;                                        */
/*  input uint32 EngSt_ctSec_buff_0;                                          */
/*  input uint16 EngSt_ctDay_buff_0;                                          */
/*  input uint8 EngSt_ctYr_buff_0;                                            */
/*  input uint32 EngSt_ctSec_buff_1;                                          */
/*  input uint16 EngSt_ctDay_buff_1;                                          */
/*  input uint8 EngSt_ctYr_buff_1;                                            */
/*  input uint32 EngSt_ctSec_buff_2;                                          */
/*  input uint16 EngSt_ctDay_buff_2;                                          */
/*  input uint8 EngSt_ctYr_buff_2;                                            */
/*  output uint32 EngSt_ctSec_buff_0;                                         */
/*  output uint16 EngSt_ctDay_buff_0;                                         */
/*  output uint8 EngSt_ctYr_buff_0;                                           */
/*  output uint32 EngSt_ctSec_buff_1;                                         */
/*  output uint16 EngSt_ctDay_buff_1;                                         */
/*  output uint8 EngSt_ctYr_buff_1;                                           */
/*  output uint32 EngSt_ctSec_buff_2;                                         */
/*  output uint16 EngSt_ctDay_buff_2;                                         */
/*  output uint8 EngSt_ctYr_buff_2;                                           */
/*  output uint8 TIENGSTOP_u8CtTiIndex;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIENGSTOP_vidTimeBuffer(void)
{
   /*F01_time_buffer*/
   uint8  u8LocalExt_ctYr;
   uint16 u16LocalExt_ctDay;
   uint32 u32LocalExt_ctSec;


   VEMS_vidGET(Ext_ctSec, u32LocalExt_ctSec);
   VEMS_vidGET(Ext_ctDay, u16LocalExt_ctDay);
   VEMS_vidGET(Ext_ctYr, u8LocalExt_ctYr);

   if (TIENGSTOP_u8CtTiIndex == 0)
   {
      EngSt_ctSec_buff_0 = u32LocalExt_ctSec;
      EngSt_ctDay_buff_0 = u16LocalExt_ctDay;
      EngSt_ctYr_buff_0 = u8LocalExt_ctYr;
   }
   else
   {
      if (TIENGSTOP_u8CtTiIndex == 1)
      {
         EngSt_ctSec_buff_1 = u32LocalExt_ctSec;
         EngSt_ctDay_buff_1 = u16LocalExt_ctDay;
         EngSt_ctYr_buff_1 = u8LocalExt_ctYr;
      }
      else
      {
         if (TIENGSTOP_u8CtTiIndex == 2)
         {
            EngSt_ctSec_buff_2 = u32LocalExt_ctSec;
            EngSt_ctDay_buff_2 = u16LocalExt_ctDay;
            EngSt_ctYr_buff_2 = u8LocalExt_ctYr;
         }
      }
   }

   EngSt_ctSec_buff_0 = MATHSRV_udtMIN(EngSt_ctSec_buff_0, 586639);
   EngSt_ctDay_buff_0 = (uint16)MATHSRV_udtMIN(EngSt_ctDay_buff_0, 365);
   EngSt_ctYr_buff_0 = (uint8)MATHSRV_udtMIN(EngSt_ctYr_buff_0, 100);
   EngSt_ctSec_buff_1 = MATHSRV_udtMIN(EngSt_ctSec_buff_1, 586639);
   EngSt_ctDay_buff_1 = (uint16)MATHSRV_udtMIN(EngSt_ctDay_buff_1, 365);
   EngSt_ctYr_buff_1 = (uint8)MATHSRV_udtMIN(EngSt_ctYr_buff_1, 100);
   EngSt_ctSec_buff_2 = MATHSRV_udtMIN(EngSt_ctSec_buff_2, 586639);
   EngSt_ctDay_buff_2 = (uint16)MATHSRV_udtMIN(EngSt_ctDay_buff_2, 365);
   EngSt_ctYr_buff_2 = (uint8)MATHSRV_udtMIN(EngSt_ctYr_buff_2, 100);

   if (TIENGSTOP_u8CtTiIndex < 3)
   {
      TIENGSTOP_u8CtTiIndex = (uint8)(TIENGSTOP_u8CtTiIndex + 1);
   }
   else
   {
      TIENGSTOP_u8CtTiIndex = 3;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIENGSTOP_vidInitTimeSinceStall                            */
/* !Description :  Après le réveil du CMM et jusqu'au passage des premières   */
/*                 dents vilebrequin, on déduit  la durée d'arrêt moteur,     */
/*                 nommée " durée d'arrêt moteur ", calculée ainsi : " date   */
/*                 actuelle " - " date arrêt NON volatile ".                  */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_12_01073_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_ctYr;                                                     */
/*  input uint16 Ext_ctDay;                                                   */
/*  input uint32 Ext_ctSec;                                                   */
/*  input uint8 Date_emf_dernier_arret_a;                                     */
/*  input uint16 Date_emf_dernier_arret_j;                                    */
/*  input uint32 Date_emf_dernier_arret_s;                                    */
/*  output boolean EOM_bDgoCoh_tiEngStop;                                     */
/*  output uint32 Time_since_stall;                                           */
/*  output uint32 EOM_tiEngStopRst;                                           */
/*  output uint32 EOM_tiEngStop;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIENGSTOP_vidInitTimeSinceStall(void)
{
   /*F02_init_time_since_stall*/
   boolean bLocalEOMbDgoCohTiEngStop;
   uint8   u8LocalExt_ctYr;
   uint8   u8LocalCtYr;
   uint16  u16LocalExt_ctDay;
   uint32  u32LocalTemp;
   uint32  u32LocalExt_ctSec;
   uint32  u32LocalTime_since_stall;
   uint32  u32LocalCtSecMinusDateSinceStall;
   uint32  u32LocalTimeSinceStall;
   uint32  u32LocalDateSinceStallMinuCtSec;
   uint32  u32LocalComp1;
   uint32  u32LocalComp2;
   uint32  u32LocalTimeSincStl;
   sint32  s32LocalCtDay;


   VEMS_vidGET(Ext_ctYr, u8LocalExt_ctYr);
   VEMS_vidGET(Ext_ctDay, u16LocalExt_ctDay);
   VEMS_vidGET(Ext_ctSec, u32LocalExt_ctSec);

   u32LocalTime_since_stall = 864000;
   bLocalEOMbDgoCohTiEngStop = 1;

   if (u8LocalExt_ctYr >= Date_emf_dernier_arret_a)
   {
      bLocalEOMbDgoCohTiEngStop = 0;
      u8LocalCtYr = (uint8)(u8LocalExt_ctYr - Date_emf_dernier_arret_a);
      s32LocalCtDay = (sint32)(u16LocalExt_ctDay - Date_emf_dernier_arret_j);
      s32LocalCtDay = ((sint32)(u8LocalCtYr * 365) + s32LocalCtDay);

      if (s32LocalCtDay >= 0)
      {
         u32LocalTime_since_stall = 863999;

         if (u32LocalExt_ctSec > Date_emf_dernier_arret_s)
         {
            u32LocalCtSecMinusDateSinceStall =
               (u32LocalExt_ctSec - Date_emf_dernier_arret_s);
            if (u32LocalCtSecMinusDateSinceStall < 863999)
            {
               if (s32LocalCtDay < 10)
               {
                  u32LocalTimeSinceStall = ( u32LocalCtSecMinusDateSinceStall
                                           + (uint32)(s32LocalCtDay * 86400));
                  u32LocalTime_since_stall =
                     MATHSRV_udtMIN(u32LocalTimeSinceStall, 863999);
               }
            }
         }
         else
         {
            u32LocalDateSinceStallMinuCtSec =
               Date_emf_dernier_arret_s - u32LocalExt_ctSec;
            u32LocalComp1 = u32LocalDateSinceStallMinuCtSec / 86400;

            if ((uint32)s32LocalCtDay < u32LocalComp1)
            {
               u32LocalTime_since_stall = 864000;
               bLocalEOMbDgoCohTiEngStop = 1;
            }
            else
            {
               u32LocalComp2 = u32LocalComp1 + 10;

               if ((uint32)s32LocalCtDay < u32LocalComp2)
               {
                  u32LocalTemp = 0;
                  if (s32LocalCtDay <= 49710)
                  {
                     u32LocalTimeSincStl = (uint32)(s32LocalCtDay * 86400);
                  }
                  else
                  {
                     u32LocalTemp = (uint32)(s32LocalCtDay - 49710);
                     u32LocalTimeSincStl = 4294944000UL;
                  }

                  if (  (u32LocalTimeSincStl >= u32LocalDateSinceStallMinuCtSec)
                     || (u32LocalTemp > 0))
                  {
                     u32LocalTemp = (u32LocalTemp * 86400);
                     u32LocalTime_since_stall =
                        u32LocalTimeSincStl - u32LocalDateSinceStallMinuCtSec;
                     u32LocalTime_since_stall =
                        u32LocalTime_since_stall + u32LocalTemp;
                  }
                  else
                  {
                     u32LocalTime_since_stall = 864000;
                     bLocalEOMbDgoCohTiEngStop = 1;
                  }
               }
            }
         }
      }
      else
      {
         bLocalEOMbDgoCohTiEngStop = 1;
      }
   }
   EOM_bDgoCoh_tiEngStop = bLocalEOMbDgoCohTiEngStop;
   VEMS_vidSET(Time_since_stall, u32LocalTime_since_stall);
   VEMS_vidSET(EOM_tiEngStopRst, u32LocalTime_since_stall);
   VEMS_vidSET(EOM_tiEngStop, u32LocalTime_since_stall);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIENGSTOP_vidEmfDateSinceStall                             */
/* !Description :  A partir de l'arrêt moteur (N=0), le CMM évalue en temps   */
/*                 réel la durée écoulée entre le  dernier arrêt moteur (suite*/
/*                 à un calage, une demande conducteur, ou une demande STT) et*/
/*                 le nouveau passage de dents vilebrequin.                   */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_12_01073_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_ctYr;                                                     */
/*  input uint16 Ext_ctDay;                                                   */
/*  input uint32 Ext_ctSec;                                                   */
/*  input uint8 Date_emf_arret_a;                                             */
/*  input uint16 Date_emf_arret_j;                                            */
/*  input uint32 Date_emf_arret_s;                                            */
/*  output boolean EOM_bDgoCoh_tiEngStop;                                     */
/*  output uint32 Time_since_stall;                                           */
/*  output uint32 EOM_tiEngStopRst;                                           */
/*  output uint32 EOM_tiEngStop;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIENGSTOP_vidEmfDateSinceStall(void)
{
   /*F03_date_emf_depuis_cale*/
   boolean bLocalEOMbDgoCohTiEngStop;
   uint8   u8LocalExt_ctYr;
   uint8   u8LocalCtYr;
   uint16  u16LocalExt_ctDay;
   uint32  u32LocalTemp;
   uint32  u32LocalExt_ctSec;
   uint32  u32LocalTime_since_stall;
   uint32  u32LocalCtSecMinusDateSinceStall;
   uint32  u32LocalTimeSinceStall;
   uint32  u32LocalDateSinceStallMinuCtSec;
   uint32  u32LocalComp1;
   uint32  u32LocalComp2;
   uint32  u32LocalTimeSincStl;
   sint32  s32LocalCtDay;


   VEMS_vidGET(Ext_ctYr, u8LocalExt_ctYr);
   VEMS_vidGET(Ext_ctDay, u16LocalExt_ctDay);
   VEMS_vidGET(Ext_ctSec, u32LocalExt_ctSec);

   u32LocalTime_since_stall = 864000;
   bLocalEOMbDgoCohTiEngStop = 1;

   if (u8LocalExt_ctYr >= Date_emf_arret_a)
   {
      bLocalEOMbDgoCohTiEngStop = 0;
      u8LocalCtYr = (uint8)(u8LocalExt_ctYr - Date_emf_arret_a);
      s32LocalCtDay = (sint32)(u16LocalExt_ctDay - Date_emf_arret_j);
      s32LocalCtDay = ((sint32)(u8LocalCtYr * 365) + s32LocalCtDay);

      if (s32LocalCtDay >= 0)
      {
         u32LocalTime_since_stall = 863999;

         if (u32LocalExt_ctSec > Date_emf_arret_s)
         {
            u32LocalCtSecMinusDateSinceStall =
               (u32LocalExt_ctSec - Date_emf_arret_s);
            if (u32LocalCtSecMinusDateSinceStall < 863999)
            {
               if (s32LocalCtDay < 10)
               {
                  u32LocalTimeSinceStall = ( u32LocalCtSecMinusDateSinceStall
                                           + (uint32)(s32LocalCtDay * 86400));
                  u32LocalTime_since_stall =
                     MATHSRV_udtMIN(u32LocalTimeSinceStall, 863999);
               }
            }
         }
         else
         {
            u32LocalDateSinceStallMinuCtSec =
               Date_emf_arret_s - u32LocalExt_ctSec;
            u32LocalComp1 = u32LocalDateSinceStallMinuCtSec / 86400;

            if ((uint32)s32LocalCtDay < u32LocalComp1)
            {
               u32LocalTime_since_stall = 864000;
               bLocalEOMbDgoCohTiEngStop = 1;
            }
            else
            {
               u32LocalComp2 = u32LocalComp1 + 10;

               if ((uint32)s32LocalCtDay < u32LocalComp2)
               {
                  u32LocalTemp = 0;
                  if (s32LocalCtDay <= 49710)
                  {
                     u32LocalTimeSincStl = (uint32)(s32LocalCtDay * 86400);
                  }
                  else
                  {
                     u32LocalTemp = (uint32)(s32LocalCtDay - 49710);
                     u32LocalTimeSincStl = 4294944000UL;
                  }

                  if (  (u32LocalTimeSincStl >= u32LocalDateSinceStallMinuCtSec)
                     || (u32LocalTemp > 0))
                  {
                     u32LocalTemp = (u32LocalTemp * 86400);
                     u32LocalTime_since_stall =
                        u32LocalTimeSincStl - u32LocalDateSinceStallMinuCtSec;
                     u32LocalTime_since_stall =
                        u32LocalTime_since_stall + u32LocalTemp;
                  }
                  else
                  {
                     u32LocalTime_since_stall = 864000;
                     bLocalEOMbDgoCohTiEngStop = 1;
                  }
               }
            }
         }
      }
      else
      {
         bLocalEOMbDgoCohTiEngStop = 1;
      }
   }
   EOM_bDgoCoh_tiEngStop = bLocalEOMbDgoCohTiEngStop;
   VEMS_vidSET(Time_since_stall, u32LocalTime_since_stall);
   VEMS_vidSET(EOM_tiEngStopRst, u32LocalTime_since_stall);
   VEMS_vidSET(EOM_tiEngStop, u32LocalTime_since_stall);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIENGSTOP_vidEmfActiveDate                                 */
/* !Description :  Quand le régime moteur devient non nul le CMM met à zéro " */
/*                 date arrêt volatile " et fige " durée d'arrêt moteur ".    */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_12_01073_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TIENGSTOP_vidEmfValidCrankDate();                        */
/*  input boolean Date_emf_dem_calcule;                                       */
/*  output uint32 Date_emf_arret_s;                                           */
/*  output uint16 Date_emf_arret_j;                                           */
/*  output uint8 Date_emf_arret_a;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIENGSTOP_vidEmfActiveDate(void)
{
   /*F04_date_emf_actif*/
   Date_emf_arret_s = 0;
   Date_emf_arret_j = 0;
   Date_emf_arret_a = 0;

   if (Date_emf_dem_calcule == 0)
   {
      /*F01_date_emf_valide_demarrage*/
      TIENGSTOP_vidEmfValidCrankDate();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIENGSTOP_vidEmfValidCrankDate                             */
/* !Description :  Cette fonction permet le sauvegarde de la date de le       */
/*                 dernier démarrage "Date valide"                            */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_12_01073_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint32 Ext_ctSec;                                                   */
/*  input uint16 Ext_ctDay;                                                   */
/*  input uint8 Ext_ctYr;                                                     */
/*  output uint32 Date_emf_demarrage_s;                                       */
/*  output uint16 Date_emf_demarrage_j;                                       */
/*  output uint8 Date_emf_demarrage_a;                                        */
/*  output boolean Date_emf_dem_calcule;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIENGSTOP_vidEmfValidCrankDate(void)
{
   /*F01_date_emf_valide_demarrage*/
   uint8  u8LocalExt_ctYr;
   uint16 u16LocalExt_ctDay;
   uint32 u32LocalExt_ctSec;


   VEMS_vidGET(Ext_ctSec, u32LocalExt_ctSec);
   VEMS_vidGET(Ext_ctDay, u16LocalExt_ctDay);
   VEMS_vidGET(Ext_ctYr, u8LocalExt_ctYr);

   Date_emf_demarrage_s = MATHSRV_udtMIN(u32LocalExt_ctSec, 586639);
   Date_emf_demarrage_j = (uint16)MATHSRV_udtMIN(u16LocalExt_ctDay, 365);
   Date_emf_demarrage_a = (uint8)MATHSRV_udtMIN(u8LocalExt_ctYr, 100);
   Date_emf_dem_calcule = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIENGSTOP_vidEmfDateCoh                                    */
/* !Description :  Le CMM validera l'information sur les 3 premières valeurs  */
/*                 de cette information temporelle qui devront être           */
/*                 successives et cohérentes. En cas d'incohérence sur ces 3  */
/*                 valeurs de l'information temporelle reçue, la valeur       */
/*                 retenue sera invalide.                                     */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_12_01073_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint32 EngSt_ctSec_buff_0;                                          */
/*  input uint32 EngSt_ctSec_buff_1;                                          */
/*  input uint32 EngSt_ctSec_buff_2;                                          */
/*  input uint16 EngSt_ctDay_buff_0;                                          */
/*  input uint16 EngSt_ctDay_buff_1;                                          */
/*  input uint16 EngSt_ctDay_buff_2;                                          */
/*  input uint8 EngSt_ctYr_buff_0;                                            */
/*  input uint8 EngSt_ctYr_buff_1;                                            */
/*  input uint8 EngSt_ctYr_buff_2;                                            */
/*  output boolean EngSt_bDiagCohCtTi;                                        */
/*  output boolean EOM_bDgoORng_tiEngStop;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIENGSTOP_vidEmfDateCoh(void)
{
   /*F05_coh_date_emf*/
   EngSt_bDiagCohCtTi = 1;

   if (  (  (EngSt_ctSec_buff_0 >= EngSt_ctSec_buff_1)
         && (EngSt_ctSec_buff_1 >= EngSt_ctSec_buff_2))
      || (  (EngSt_ctDay_buff_0 > EngSt_ctDay_buff_1)
         && (EngSt_ctDay_buff_1 > EngSt_ctDay_buff_2))
      || (  (EngSt_ctYr_buff_0 > EngSt_ctYr_buff_1)
         && (EngSt_ctYr_buff_1 > EngSt_ctYr_buff_2)))
   {
      EOM_bDgoORng_tiEngStop = 1;
   }
   else
   {
      EOM_bDgoORng_tiEngStop = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIENGSTOP_vidEmfInvalidCrankDate                           */
/* !Description :  Cette fonction permet le sauvegarde de la date de le       */
/*                 dernier démarrage "Date valide".                           */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint32 Date_emf_demarrage_s;                                       */
/*  output uint16 Date_emf_demarrage_j;                                       */
/*  output uint8 Date_emf_demarrage_a;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIENGSTOP_vidEmfInvalidCrankDate(void)
{
   /*F02_date_emf_invalide_demarrage*/
   Date_emf_demarrage_s = 586639;
   Date_emf_demarrage_j = 365;
   Date_emf_demarrage_a = 100;
}

/*-------------------------------End Of File----------------------------------*/