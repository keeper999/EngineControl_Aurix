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
/* !File            : TIENGSTOP_FCT1.c                                        */
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
/*   1 / TIENGSTOP_vidInitOutput                                              */
/*   2 / TIENGSTOP_vidInitialisation                                          */
/*   3 / TIENGSTOP_vidEmfSaveLastAlarmClk                                     */
/*   4 / TIENGSTOP_vidAlarmClockCalc                                          */
/*   5 / TIENGSTOP_vidChangeOfMind                                            */
/*   6 / TIENGSTOP_vidDegradedPeriodEstim                                     */
/*   7 / TIENGSTOP_vidRazTimeSinceStall                                       */
/*   8 / TIENGSTOP_vidEmfSaveLastStopDate                                     */
/*   9 / TIENGSTOP_vidFrameTairCAN                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5329313 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ENGST/TIENGSTOP/TIENGSTOP_FCT1.C$*/
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
/* !Function    :  TIENGSTOP_vidInitOutput                                    */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean TIENGSTOP_bWkuMainPrev;                                    */
/*  output uint8 TIENGSTOP_u8CoPTStEngPrev;                                   */
/*  output uint16 TIENGSTOP_u16Ext_nEngPrev;                                  */
/*  output boolean EngSt_bAcvChangeOfMind;                                    */
/*  output uint32 Time_since_stall;                                           */
/*  output uint32 EOM_tiEngStopRst;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIENGSTOP_vidInitOutput(void)
{
   TIENGSTOP_bWkuMainPrev = 0;
   TIENGSTOP_u8CoPTStEngPrev = 1;
   TIENGSTOP_u16Ext_nEngPrev = 0;
   VEMS_vidSET(EngSt_bAcvChangeOfMind, 0);
   VEMS_vidSET(Time_since_stall, 0);
   VEMS_vidSET(EOM_tiEngStopRst, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIENGSTOP_vidInitialisation                                */
/* !Description :  A l’initialisation, on va lire en EEPROM les dates de      */
/*                 dernier réveil, de dernier arrêt et date de démarrage.On   */
/*                 met aussi à 0 l’indicateur de calcul de la date du         */
/*                 démarrage.                                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_12_01073_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint32 Ext_ctSec;                                                   */
/*  input uint16 Ext_ctDay;                                                   */
/*  input uint8 Ext_ctYr;                                                     */
/*  output boolean Date_emf_init_time_since_stall;                            */
/*  output boolean Date_emf_dem_calcule;                                      */
/*  output uint8 TIENGSTOP_u8CtTiIndex;                                       */
/*  output boolean EngSt_bDiagCohCtTi;                                        */
/*  output uint32 Date_emf_reveil_s;                                          */
/*  output uint16 Date_emf_reveil_j;                                          */
/*  output uint8 Date_emf_reveil_a;                                           */
/*  output boolean EngSt_bTramTairCANVal;                                     */
/*  output boolean EngSt_bDetEngStallSTT;                                     */
/*  output uint32 EngSt_ctSec_buff_0;                                         */
/*  output uint32 EngSt_ctSec_buff_1;                                         */
/*  output uint32 EngSt_ctSec_buff_2;                                         */
/*  output uint16 EngSt_ctDay_buff_0;                                         */
/*  output uint16 EngSt_ctDay_buff_1;                                         */
/*  output uint16 EngSt_ctDay_buff_2;                                         */
/*  output uint8 EngSt_ctYr_buff_0;                                           */
/*  output uint8 EngSt_ctYr_buff_1;                                           */
/*  output uint8 EngSt_ctYr_buff_2;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIENGSTOP_vidInitialisation(void)
{
   /*F01_initialisation*/
   uint8  u8LocalExt_ctYr;
   uint16 u16LocalExt_ctDay;
   uint32 u32LocalExt_ctSec;


   Date_emf_init_time_since_stall = 0;
   Date_emf_dem_calcule = 0;
   TIENGSTOP_u8CtTiIndex = 0;
   EngSt_bDiagCohCtTi = 0;
   Date_emf_reveil_s = 0;
   Date_emf_reveil_j = 0;
   Date_emf_reveil_a = 0;
   EngSt_bTramTairCANVal = 0;
   EngSt_bDetEngStallSTT = 1;

   VEMS_vidGET(Ext_ctSec, u32LocalExt_ctSec);
   VEMS_vidGET(Ext_ctDay, u16LocalExt_ctDay);
   VEMS_vidGET(Ext_ctYr, u8LocalExt_ctYr);

   EngSt_ctSec_buff_0 = MATHSRV_udtMIN(u32LocalExt_ctSec, 586639);
   EngSt_ctSec_buff_1 = MATHSRV_udtMIN(u32LocalExt_ctSec, 586639);
   EngSt_ctSec_buff_2 = MATHSRV_udtMIN(u32LocalExt_ctSec, 586639);

   EngSt_ctDay_buff_0 = (uint16)MATHSRV_udtMIN(u16LocalExt_ctDay, 365);
   EngSt_ctDay_buff_1 = (uint16)MATHSRV_udtMIN(u16LocalExt_ctDay, 365);
   EngSt_ctDay_buff_2 = (uint16)MATHSRV_udtMIN(u16LocalExt_ctDay, 365);

   EngSt_ctYr_buff_0 = (uint8)MATHSRV_udtMIN(u8LocalExt_ctYr, 100);
   EngSt_ctYr_buff_1 = (uint8)MATHSRV_udtMIN(u8LocalExt_ctYr, 100);
   EngSt_ctYr_buff_2 = (uint8)MATHSRV_udtMIN(u8LocalExt_ctYr, 100);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIENGSTOP_vidEmfSaveLastAlarmClk                           */
/* !Description :  On mémorisera, l'information temporelle envoyée par le     */
/*                 véhicule contenue dans la  dernière trame reçue valide en  */
/*                 mémoire non volatile, c'est la " Date de dernier Réveil ". */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_12_01073_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TIENGSTOP_vidAlarmClockCalc();                           */
/*  input boolean Cranking_retry;                                             */
/*  input boolean Date_emf_available_mux;                                     */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean TIENGSTOP_bWkuMainPrev;                                     */
/*  output boolean TIENGSTOP_bWkuMainPrev;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIENGSTOP_vidEmfSaveLastAlarmClk(void)
{
   /*F02_sauve_dernier_reveil_emf*/
   boolean bLocalCranking_retry;
   boolean bLocalDate_emf_available_mux;
   boolean bLocalECU_bWkuMain;


   VEMS_vidGET(Cranking_retry, bLocalCranking_retry);
   VEMS_vidGET(Date_emf_available_mux, bLocalDate_emf_available_mux);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   if (  (bLocalCranking_retry == 0)
      && (bLocalDate_emf_available_mux != 0)
      && (bLocalECU_bWkuMain != 0)
      && (TIENGSTOP_bWkuMainPrev == 0))
   {
      /*F01_calcul_reveil*/
      TIENGSTOP_vidAlarmClockCalc();
   }
   TIENGSTOP_bWkuMainPrev = bLocalECU_bWkuMain;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIENGSTOP_vidAlarmClockCalc                                */
/* !Description :  Cette fonction permet d'enregistrer la  " Date de dernier  */
/*                 Réveil ".                                                  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint32 Ext_ctSec;                                                   */
/*  input uint16 Ext_ctDay;                                                   */
/*  input uint8 Ext_ctYr;                                                     */
/*  output uint32 Date_emf_reveil_s;                                          */
/*  output uint32 Date_emf_dernier_reveil_s;                                  */
/*  output uint16 Date_emf_reveil_j;                                          */
/*  output uint16 Date_emf_dernier_reveil_j;                                  */
/*  output uint8 Date_emf_reveil_a;                                           */
/*  output uint8 Date_emf_dernier_reveil_a;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIENGSTOP_vidAlarmClockCalc(void)
{
   /*F01_calcul_reveil*/
   uint8  u8LocalExt_ctYr;
   uint16 u16LocalExt_ctDay;
   uint32 u32LocalExt_ctSec;


   VEMS_vidGET(Ext_ctSec, u32LocalExt_ctSec);
   VEMS_vidGET(Ext_ctDay, u16LocalExt_ctDay);
   VEMS_vidGET(Ext_ctYr, u8LocalExt_ctYr);

   Date_emf_reveil_s = MATHSRV_udtMIN(u32LocalExt_ctSec, 586639);
   Date_emf_dernier_reveil_s = MATHSRV_udtMIN(u32LocalExt_ctSec, 586639);
   Date_emf_reveil_j = (uint16)MATHSRV_udtMIN(u16LocalExt_ctDay, 365);
   Date_emf_dernier_reveil_j = (uint16)MATHSRV_udtMIN(u16LocalExt_ctDay, 365);
   Date_emf_reveil_a = (uint8)MATHSRV_udtMIN(u8LocalExt_ctYr, 100);
   Date_emf_dernier_reveil_a = (uint8)MATHSRV_udtMIN(u8LocalExt_ctYr, 100);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIENGSTOP_vidChangeOfMind                                  */
/* !Description :  " durée d'arrêt moteur avec Reset" se comportera de la même*/
/*                 manière que " durée  d'arrêt moteur ", sauf dans le cas    */
/*                 particulier, sur détection d'un " Change of Mind ", "durée */
/*                 d'arrêt moteur avec Reset" sera remis à zéro.              */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_12_01073_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean CoEs_bIntrSTTEsLoEngSpd;                                    */
/*  input boolean CoEs_bIntrSTTEsHiEngSpd;                                    */
/*  input uint32 EOM_tiEngStopRst;                                            */
/*  input boolean EngSt_bAcvChgMind_C;                                        */
/*  input uint8 EngSt_nThdHiChgMind_C;                                        */
/*  input uint8 TIENGSTOP_u8CoPTStEngPrev;                                    */
/*  output boolean EngSt_bAcvChangeOfMind;                                    */
/*  output uint32 EOM_tiEngStopRst;                                           */
/*  output uint8 TIENGSTOP_u8CoPTStEngPrev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIENGSTOP_vidChangeOfMind(void)
{
   /*F03_change_of_mind*/
   boolean bLocalCoEs_bIntrSTTEsLoEngSpd;
   boolean bLocalCoEs_bIntrSTTEsHiEngSpd;
   uint8   u8LocalCoPTSt_stEng;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalThdHiChgMind_C;
   uint32  u32LocalEOM_tiEngStopRst;


   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(CoEs_bIntrSTTEsLoEngSpd, bLocalCoEs_bIntrSTTEsLoEngSpd);
   VEMS_vidGET(CoEs_bIntrSTTEsHiEngSpd, bLocalCoEs_bIntrSTTEsHiEngSpd);
   VEMS_vidGET(EOM_tiEngStopRst, u32LocalEOM_tiEngStopRst);

   if (EngSt_bAcvChgMind_C != 0)
   {
      u16LocalThdHiChgMind_C = (uint16)(EngSt_nThdHiChgMind_C * 10);
      if (  (u8LocalCoPTSt_stEng == Driven_Restart)
         && (TIENGSTOP_u8CoPTStEngPrev == Stop)
         && (u16LocalExt_nEng > 0)
         && (u16LocalExt_nEng <= u16LocalThdHiChgMind_C))
      {
         u32LocalEOM_tiEngStopRst = 0;
         VEMS_vidSET(EngSt_bAcvChangeOfMind, 1);
      }
      else
      {
         u32LocalEOM_tiEngStopRst =
            MATHSRV_udtMIN(u32LocalEOM_tiEngStopRst, 864000);
         VEMS_vidSET(EngSt_bAcvChangeOfMind, 0);
      }
   }
   else
   {
      if (  (bLocalCoEs_bIntrSTTEsLoEngSpd != 0)
         || (bLocalCoEs_bIntrSTTEsHiEngSpd != 0))
      {
         u32LocalEOM_tiEngStopRst = 0;
         VEMS_vidSET(EngSt_bAcvChangeOfMind, 1);
      }
      else
      {
         u32LocalEOM_tiEngStopRst =
            MATHSRV_udtMIN(u32LocalEOM_tiEngStopRst, 864000);
         VEMS_vidSET(EngSt_bAcvChangeOfMind, 0);
      }
   }

   VEMS_vidSET(EOM_tiEngStopRst, u32LocalEOM_tiEngStopRst);
   TIENGSTOP_u8CoPTStEngPrev =
      (uint8)MATHSRV_udtMIN(u8LocalCoPTSt_stEng, 15);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIENGSTOP_vidDegradedPeriodEstim                           */
/* !Description :  Dès que les acquisitions de température d'air et d'eau sont*/
/*                 réalisées et que toutes les  informations nécessaires au   */
/*                 calcul sont disponibles, on appelle la fonction            */
/*                 d'estimation du temps d'arrêt dégradée.                    */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_12_01073_012.01                                     */
/*                 VEMS_R_12_01073_011.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint8 TqCmp_tAir;                                                   */
/*  input sint16 Ext_tCoMesPwrl;                                              */
/*  input sint16 Ext_tDsThrMes;                                               */
/*  input boolean EngSt_bAcvTairCANModDftSel_C;                               */
/*  input boolean EngSt_bTramTairCANVal;                                      */
/*  input sint16 EngSt_tAirMesSel;                                            */
/*  input uint8 EngSt_tAir_AX[10];                                            */
/*  input sint16 TIENGSTOP_s16TCoMesDelta;                                    */
/*  input uint8 EngSt_tCoMes_AY[10];                                          */
/*  input uint16 EngSt_tiEngStopDft_M[10][10];                                */
/*  input sint16 EngSt_tDeltaThd_C;                                           */
/*  input uint16 EngSt_tiEngStopDft;                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint32 Time_since_stall;                                            */
/*  input uint32 EOM_tiEngStopRst;                                            */
/*  input boolean Date_emf_available_mux;                                     */
/*  input boolean EngSt_bDetEngStallSTT;                                      */
/*  input uint32 Date_emf_dernier_reveil_s;                                   */
/*  input uint16 Date_emf_dernier_reveil_j;                                   */
/*  input uint8 Date_emf_dernier_reveil_a;                                    */
/*  output sint16 TIENGSTOP_s16TCoMesDelta;                                   */
/*  output sint16 EngSt_tAirMesSel;                                           */
/*  output uint16 EngSt_tiEngStopDft;                                         */
/*  output uint32 EOM_tiEngStopDft;                                           */
/*  output uint32 Time_since_stall;                                           */
/*  output uint32 EOM_tiEngStop;                                              */
/*  output uint32 EOM_tiEngStopRst;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIENGSTOP_vidDegradedPeriodEstim(void)
{
   /*F05_estimation_duree_degradee*/
   boolean bLocalFRMInhEstimTiEngStop;
   boolean bLocalFRMbAcvEstimTiEngStop;
   boolean bLocalInhTairCANModDftSel;
   boolean bLocalDate_emf_available_mux;
   uint8   u8LocalTCoMesDelta;
   uint8   u8LocalEngSt_tAirMesSel;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalEngStTAirParaX;
   uint16  u16LocalEngStTCoMesParaY;
   uint16  u16LocalEngSt_tiEngStopDft;
   uint32  u32LocalEOM_tiEngStopDft;
   uint32  u32LocalTime_since_stall;
   uint32  u32LocalEOM_tiEngStopRst;
   sint8   s8LocalTqCmp_tAir;
   sint16  s16LocalExt_tCoMes;
   sint16  s16LocalExt_tCoMesPwrl;
   sint16  s16LocalExt_tDsThrMes;
   sint16  s16LocalEngSt_tAirMesSel;
   sint32  s32LocalTCoMesDelta;
   sint32  s32LocaltCoMesMinustAir;


   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(TqCmp_tAir, s8LocalTqCmp_tAir);
   VEMS_vidGET(Ext_tCoMesPwrl, s16LocalExt_tCoMesPwrl);
   s32LocalTCoMesDelta = (sint32)( ( s16LocalExt_tCoMesPwrl
                                   - s16LocalExt_tCoMes));
   TIENGSTOP_s16TCoMesDelta =
      (sint16)MATHSRV_udtCLAMP(s32LocalTCoMesDelta, -40, 214);

   bLocalInhTairCANModDftSel = GDGAR_bGetFRM(FRM_FRM_INHTAIRCANMODDFTSEL);
   VEMS_vidGET(Ext_tDsThrMes, s16LocalExt_tDsThrMes);

   if (  (EngSt_bAcvTairCANModDftSel_C != 0)
      && (bLocalInhTairCANModDftSel == 0)
      && (EngSt_bTramTairCANVal != 0))
   {
      s16LocalEngSt_tAirMesSel = (sint16)s8LocalTqCmp_tAir;
   }
   else
   {
      s16LocalEngSt_tAirMesSel = s16LocalExt_tDsThrMes;
   }
   EngSt_tAirMesSel =
      (sint16)MATHSRV_udtCLAMP(s16LocalEngSt_tAirMesSel, -50, 200);
   s16LocalEngSt_tAirMesSel = (sint16)(EngSt_tAirMesSel + 40);
   u8LocalEngSt_tAirMesSel = (uint8)MATHSRV_udtMAX(s16LocalEngSt_tAirMesSel, 0);
   u16LocalEngStTAirParaX =
      MATHSRV_u16CalcParaIncAryU8(EngSt_tAir_AX,
                                  u8LocalEngSt_tAirMesSel,
                                  10);
   u8LocalTCoMesDelta = (uint8)(TIENGSTOP_s16TCoMesDelta + 40);
   u16LocalEngStTCoMesParaY =
      MATHSRV_u16CalcParaIncAryU8(EngSt_tCoMes_AY,
                                  u8LocalTCoMesDelta,
                                  10);
   u16LocalEngSt_tiEngStopDft =
      MATHSRV_u16Interp2d(&EngSt_tiEngStopDft_M[0][0],
                          u16LocalEngStTAirParaX,
                          u16LocalEngStTCoMesParaY,
                          10);
   EngSt_tiEngStopDft =
      (uint16)MATHSRV_udtMIN(u16LocalEngSt_tiEngStopDft, 54000);
   bLocalFRMInhEstimTiEngStop = GDGAR_bGetFRM(FRM_FRM_INHESTIMTIENGSTOP);

   if (bLocalFRMInhEstimTiEngStop != 0)
   {
      u32LocalEOM_tiEngStopDft = 864000;
   }
   else
   {
      s32LocaltCoMesMinustAir = (sint32)(s16LocalExt_tCoMes - EngSt_tAirMesSel);
      if (s32LocaltCoMesMinustAir < (sint32)(EngSt_tDeltaThd_C))
      {
         u32LocalEOM_tiEngStopDft = 864000;
      }
      else
      {
         u32LocalEOM_tiEngStopDft = (uint32)(EngSt_tiEngStopDft * 16);
      }
   }
   VEMS_vidSET(EOM_tiEngStopDft, u32LocalEOM_tiEngStopDft);

   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   bLocalFRMbAcvEstimTiEngStop = GDGAR_bGetFRM(FRM_FRM_ACVESTIMTIENGSTOP);
   VEMS_vidGET(Time_since_stall, u32LocalTime_since_stall);
   VEMS_vidGET(EOM_tiEngStopRst, u32LocalEOM_tiEngStopRst);
   VEMS_vidGET(Date_emf_available_mux, bLocalDate_emf_available_mux);

   if (  (  (bLocalFRMbAcvEstimTiEngStop != 0)
         || (bLocalDate_emf_available_mux == 0))
      && (u16LocalExt_nEng == 0))
   {
      if (EngSt_bDetEngStallSTT != 0)
      {
         if (  (Date_emf_dernier_reveil_s == 0)
            && (Date_emf_dernier_reveil_j == 0)
            && (Date_emf_dernier_reveil_a == 0))
         {
            u32LocalTime_since_stall = 864000;
            u32LocalEOM_tiEngStopRst = 864000;
         }
         else
         {
            u32LocalTime_since_stall = u32LocalEOM_tiEngStopDft;
            u32LocalEOM_tiEngStopRst = u32LocalEOM_tiEngStopDft;
         }
      }
      else
      {
         if (u32LocalTime_since_stall < 863999)
         {
            u32LocalTime_since_stall = u32LocalTime_since_stall + 1;
         }
         else
         {
            u32LocalTime_since_stall = 863999;
         }
         u32LocalEOM_tiEngStopRst = u32LocalTime_since_stall;
      }
   }
   else
   {
      u32LocalTime_since_stall =
         MATHSRV_udtMIN(u32LocalTime_since_stall, 864000);
      u32LocalEOM_tiEngStopRst =
         MATHSRV_udtMIN(u32LocalEOM_tiEngStopRst, 864000);
   }

   VEMS_vidSET(Time_since_stall, u32LocalTime_since_stall);
   VEMS_vidSET(EOM_tiEngStop, u32LocalTime_since_stall);
   VEMS_vidSET(EOM_tiEngStopRst, u32LocalEOM_tiEngStopRst);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIENGSTOP_vidRazTimeSinceStall                             */
/* !Description :  Quand le régime moteur devient nul le CMM enregistre la "  */
/*                 date actuelle " en mémoire  volatile, cette date est       */
/*                 appelée " date arrêt volatile ".                           */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_12_01073_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Ext_ctSec;                                                   */
/*  input uint16 Ext_ctDay;                                                   */
/*  input uint8 Ext_ctYr;                                                     */
/*  input boolean ECU_bWkuMain;                                               */
/*  output uint32 EOM_tiEngStopRst;                                           */
/*  output uint32 Time_since_stall;                                           */
/*  output uint32 EOM_tiEngStop;                                              */
/*  output boolean Date_emf_dem_calcule;                                      */
/*  output uint32 Date_emf_arret_s;                                           */
/*  output uint16 Date_emf_arret_j;                                           */
/*  output uint8 Date_emf_arret_a;                                            */
/*  output boolean EngSt_bDetEngStallSTT;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIENGSTOP_vidRazTimeSinceStall(void)
{
   /*F06_raz_time_since_stall*/
   boolean  bLocalECU_bWkuMain;
   uint8    u8LocalExt_ctYr;
   uint16   u16LocalExt_ctDay;
   uint32   u32LocalExt_ctSec;


   VEMS_vidGET(Ext_ctSec, u32LocalExt_ctSec);
   VEMS_vidGET(Ext_ctDay, u16LocalExt_ctDay);
   VEMS_vidGET(Ext_ctYr, u8LocalExt_ctYr);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidSET(EOM_tiEngStopRst, 0);
   VEMS_vidSET(Time_since_stall, 0);
   VEMS_vidSET(EOM_tiEngStop, 0);
   Date_emf_dem_calcule = 0;
   Date_emf_arret_s = MATHSRV_udtMIN(u32LocalExt_ctSec, 586639);
   Date_emf_arret_j = (uint16)MATHSRV_udtMIN(u16LocalExt_ctDay, 365);
   Date_emf_arret_a = (uint8)MATHSRV_udtMIN(u8LocalExt_ctYr, 100);
   if (bLocalECU_bWkuMain != 0)
   {
      EngSt_bDetEngStallSTT = 0;
   }
   else
   {
      EngSt_bDetEngStallSTT = 1;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIENGSTOP_vidEmfSaveLastStopDate                           */
/* !Description :  A la perte du réveil principal et si un démarrage a eu lieu*/
/*                 depuis la dernière apparition du réveil principal, le CMM  */
/*                 doit enregistrer en mémoire non volatile la valeur de "    */
/*                 date arrêt volatile " ou " date actuelle ".                */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_12_01073_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Date_emf_init_time_since_stall;                             */
/*  input uint32 Ext_ctSec;                                                   */
/*  input uint16 Ext_ctDay;                                                   */
/*  input uint8 Ext_ctYr;                                                     */
/*  input uint32 Date_emf_arret_s;                                            */
/*  input uint16 Date_emf_arret_j;                                            */
/*  input uint8 Date_emf_arret_a;                                             */
/*  input uint32 Date_emf_dernier_arret_s;                                    */
/*  input uint16 Date_emf_dernier_arret_j;                                    */
/*  input uint8 Date_emf_dernier_arret_a;                                     */
/*  output uint32 Date_emf_dernier_arret_s;                                   */
/*  output uint16 Date_emf_dernier_arret_j;                                   */
/*  output uint8 Date_emf_dernier_arret_a;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIENGSTOP_vidEmfSaveLastStopDate(void)
{
   /*F06_sauve_date_emf_dernier_arret*/
   uint8  u8LocalExt_ctYr;
   uint16 u16LocalExt_ctDay;
   uint32 u32LocalExt_ctSec;

   if (Date_emf_init_time_since_stall !=0)
   {
      VEMS_vidGET(Ext_ctSec, u32LocalExt_ctSec);
      VEMS_vidGET(Ext_ctDay, u16LocalExt_ctDay);
      VEMS_vidGET(Ext_ctYr, u8LocalExt_ctYr);
      if (Date_emf_arret_s == 0)
      {
         Date_emf_dernier_arret_s = MATHSRV_udtMIN(u32LocalExt_ctSec, 586639);
         Date_emf_dernier_arret_j = (uint16)MATHSRV_udtMIN(u16LocalExt_ctDay,
                                                           365);
         Date_emf_dernier_arret_a = (uint8)MATHSRV_udtMIN(u8LocalExt_ctYr,
                                                          100);
      }
      else
      {
         Date_emf_dernier_arret_s = MATHSRV_udtMIN(Date_emf_arret_s, 586639);
         Date_emf_dernier_arret_j = (uint16)MATHSRV_udtMIN(Date_emf_arret_j,
                                                           365);
         Date_emf_dernier_arret_a = (uint8)MATHSRV_udtMIN(Date_emf_arret_a,
                                                          100);
      }
   }
   else
   {
      Date_emf_dernier_arret_s = MATHSRV_udtMIN(Date_emf_dernier_arret_s,
                                                586639);
      Date_emf_dernier_arret_j =
         (uint16)MATHSRV_udtMIN(Date_emf_dernier_arret_j, 365);
      Date_emf_dernier_arret_a = (uint8)MATHSRV_udtMIN(Date_emf_dernier_arret_a,
                                                       100);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIENGSTOP_vidFrameTairCAN                                  */
/* !Description :  Cette fonction indique la réception de l'évènement CAN     */
/*                 relatif à la mesure de la température d'air.               */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean EngSt_bTramTairCANVal;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIENGSTOP_vidFrameTairCAN(void)
{
   EngSt_bTramTairCANVal = 1;
}

/*-------------------------------End Of File----------------------------------*/