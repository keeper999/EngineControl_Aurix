/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INAIRFLOWDIAG                                           */
/* !Description     : INAIRFLOWDIAG Component.                                */
/*                                                                            */
/* !Module          : INAIRFLOWDIAG                                           */
/* !Description     : Diagnostic fonctionnel du debit d’air d’admission.      */
/*                                                                            */
/* !File            : INAIRFLOWDIAG_FCT1.C                                    */
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
/*   1 / INAIRFLOWDIAG_vidInit                                                */
/*   2 / INAIRFLOWDIAG_vidLowAirflow                                          */
/*   3 / INAIRFLOWDIAG_vidDgPrLwAirfl                                         */
/*   4 / INAIRFLOWDIAG_vidLeak                                                */
/*   5 / INAIRFLOWDIAG_vidDgPrLeak                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5198333 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/INAIRFLOWDIAG/INAIRFLOWDIAG_FCT1$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   15 May 2013 $*/
/* $Author::   etsasson                               $$Date::   15 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "INAIRFLOWDIAG.h"
#include "INAIRFLOWDIAG_L.h"
#include "INAIRFLOWDIAG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INAIRFLOWDIAG_vidInit                                      */
/* !Description :  Fonction d'initialisation                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean AirSys_bDgoBoost1_pDsThr;                                  */
/*  output boolean AirSys_bMonRunBoost1_pDsThr;                               */
/*  output boolean AirSys_bDgoBoost2_pDsThr;                                  */
/*  output boolean AirSys_bMonRunBoost2_pDsThr;                               */
/*  output boolean AirSys_bDgoBoost3_pDsThr;                                  */
/*  output boolean AirSys_bMonRunBoost3_pDsThr;                               */
/*  output boolean AirSys_bDgoBoost4_pDsThr;                                  */
/*  output boolean AirSys_bMonRunBoost4_pDsThr;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INAIRFLOWDIAG_vidInit(void)
{
   AirSys_bDgoBoost1_pDsThr = 0;
   AirSys_bMonRunBoost1_pDsThr = 0;
   AirSys_bDgoBoost2_pDsThr = 0;
   AirSys_bMonRunBoost2_pDsThr = 0;
   AirSys_bDgoBoost3_pDsThr = 0;
   AirSys_bMonRunBoost3_pDsThr = 0;
   AirSys_bDgoBoost4_pDsThr = 0;
   AirSys_bMonRunBoost4_pDsThr = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INAIRFLOWDIAG_vidLowAirflow                                */
/* !Description :  Ce diagnostic permet de détecter une baisse du débit d'air */
/*                 à l'admission de X g/s en aval du BPM en mode sural.       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INAIRFLOWDIAG_vidDgPrLwAirfl();                          */
/*  input boolean TrbAct_bBoostPresClCtlAcv;                                  */
/*  output boolean AirSys_bMonRunBoost1_pDsThr;                               */
/*  output boolean AirSys_bMonRunBoost2_pDsThr;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INAIRFLOWDIAG_vidLowAirflow(void)
{
   boolean bLocalFRM_bInhInAirflowDiag;
   boolean bLocalTrbAct_bBoostPresClCtlAcv;


   bLocalFRM_bInhInAirflowDiag = GDGAR_bGetFRM(FRM_FRM_INHINAIRFLOWDIAG);
   VEMS_vidGET(TrbAct_bBoostPresClCtlAcv, bLocalTrbAct_bBoostPresClCtlAcv);

   if (  (bLocalFRM_bInhInAirflowDiag == 0)
      && (bLocalTrbAct_bBoostPresClCtlAcv != 0))
   {
      INAIRFLOWDIAG_vidDgPrLwAirfl();
      AirSys_bMonRunBoost1_pDsThr = 1;
      AirSys_bMonRunBoost2_pDsThr = 1;
   }
   else
   {
      AirSys_bMonRunBoost1_pDsThr = 0;
      AirSys_bMonRunBoost2_pDsThr = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INAIRFLOWDIAG_vidDgPrLwAirfl                               */
/* !Description :  Le test compare le rapport de cohérence entre les débits   */
/*                 entrant et sortant du collecteur (InM_rCohMnfMf) avec 1, sa*/
/*                 valeur d'équilibre : => AirSys_rCohMnfMfBoost =            */
/*                 InM_rCohMnfMf - 1                                          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_E_11_03601_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 InM_rCohMnfMf;                                               */
/*  input uint16 AirSys_rCohMnfMfBoost;                                       */
/*  input uint16 AirSys_pDsThrLeak3_C;                                        */
/*  input uint16 AirSys_pDsThrLeak4_C;                                        */
/*  output uint16 AirSys_rCohMnfMfBoost;                                      */
/*  output boolean AirSys_bDgoBoost1_pDsThr;                                  */
/*  output boolean AirSys_bDgoBoost2_pDsThr;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INAIRFLOWDIAG_vidDgPrLwAirfl(void)
{
   uint16 u16LocalInM_rCohMnfMf;


   VEMS_vidGET(InM_rCohMnfMf, u16LocalInM_rCohMnfMf);
   if (u16LocalInM_rCohMnfMf <= 16384)
   {
      AirSys_rCohMnfMfBoost = 0;
   }
   else
   {
      AirSys_rCohMnfMfBoost = (uint16)(u16LocalInM_rCohMnfMf - 16384);
   }

   if (AirSys_rCohMnfMfBoost > AirSys_pDsThrLeak3_C)
   {
      if (AirSys_rCohMnfMfBoost > AirSys_pDsThrLeak4_C)
      {
         AirSys_bDgoBoost1_pDsThr = 0;
         AirSys_bDgoBoost2_pDsThr = 1;
      }
      else
      {
         AirSys_bDgoBoost1_pDsThr = 1;
         AirSys_bDgoBoost2_pDsThr = 0;
      }
   }
   else
   {
      AirSys_bDgoBoost1_pDsThr = 0;
      AirSys_bDgoBoost2_pDsThr = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INAIRFLOWDIAG_vidLeak                                      */
/* !Description :  Ce diagnostic permet de détecter une fuite ou une          */
/*                 augmentation du débit dans le répartiteur (aval BPM) de    */
/*                 plus de X g/s en situation de vie "moteur atmosphérique".  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INAIRFLOWDIAG_vidDgPrLeak();                             */
/*  input boolean TrbAct_bBoostPresClCtlAcv;                                  */
/*  input uint16 Ext_pDsThrMesSI;                                             */
/*  input uint16 Ext_pUsThrMesSI;                                             */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint8 Corrected_throttle_position;                                  */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint8 AirSys_rpDsUsThr_C;                                           */
/*  input uint16 AirSys_nEng_C;                                               */
/*  input uint8 AirSys_rClsThdThr_C;                                          */
/*  input sint16 AirSys_tCoMes_C;                                             */
/*  output boolean AirSys_bMonRunBoost4_pDsThr;                               */
/*  output boolean AirSys_bMonRunBoost3_pDsThr;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INAIRFLOWDIAG_vidLeak(void)
{
   boolean bLocalInhInAirflowDiag;
   boolean bLocalTrbAct_bBoostPresClCtlAcv;
   boolean bLocalcomp1;
   uint8   u8LocalCorrectthrottleposition;
   uint16  u16LocalExt_pDsThrMesSI;
   uint16  u16LocalExt_pUsThrMesSI;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalExt_pDsThrMes;
   sint16  s16LocalExt_tCoMes;
   uint32  u32LocalDiv;


   bLocalInhInAirflowDiag = GDGAR_bGetFRM(FRM_FRM_INHINAIRFLOWDIAG);
   VEMS_vidGET(TrbAct_bBoostPresClCtlAcv, bLocalTrbAct_bBoostPresClCtlAcv);
   VEMS_vidGET(Ext_pDsThrMesSI, u16LocalExt_pDsThrMesSI);
   VEMS_vidGET(Ext_pUsThrMesSI, u16LocalExt_pUsThrMesSI);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Corrected_throttle_position, u8LocalCorrectthrottleposition);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);

   if (u16LocalExt_pUsThrMesSI != 0)
   {
      u32LocalDiv = ((u16LocalExt_pDsThrMesSI * 1000)/ u16LocalExt_pUsThrMesSI);
      u16LocalExt_pDsThrMes = (uint16)(AirSys_rpDsUsThr_C * 5);
      if (u32LocalDiv < u16LocalExt_pDsThrMes)
      {
         bLocalcomp1 = 1;
      }
      else
      {
         bLocalcomp1 = 0;
      }
   }
   else
   {
      bLocalcomp1 = 0;
   }
   if (  (bLocalInhInAirflowDiag == 0)
      && (bLocalTrbAct_bBoostPresClCtlAcv == 0)
      && (bLocalcomp1 != 0)
      && (u16LocalExt_nEng < AirSys_nEng_C)
      && (u8LocalCorrectthrottleposition < AirSys_rClsThdThr_C)
      && (s16LocalExt_tCoMes > AirSys_tCoMes_C))
   {
      INAIRFLOWDIAG_vidDgPrLeak();
      AirSys_bMonRunBoost4_pDsThr = 1;
      AirSys_bMonRunBoost3_pDsThr = 1;
   }
   else
   {
      AirSys_bMonRunBoost4_pDsThr = 0;
      AirSys_bMonRunBoost3_pDsThr = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INAIRFLOWDIAG_vidDgPrLeak                                  */
/* !Description :  Le test compare le rapport de cohérence entre les débits   */
/*                 entrant et sortant du collecteur (InM_rCohMnfMf) avec 1, sa*/
/*                 valeur d'équilibre : => AirSys_rCohMnfMfBoostDeac = 1 -    */
/*                 InM_rCohMnfMf                                              */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_E_11_03601_005.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 InM_rCohMnfMf;                                               */
/*  input uint16 EngM_mfTotExCor_A[9];                                        */
/*  input uint16 EngM_mfTotExCor;                                             */
/*  input uint16 AirSys_pDsThrLeak1_T[9];                                     */
/*  input uint16 AirSys_pDsThrLeak2_T[9];                                     */
/*  input uint16 AirSys_rCohMnfMfBoostDeac;                                   */
/*  input uint16 AirSys_pDsThrLeak1;                                          */
/*  input uint16 AirSys_pDsThrLeak2;                                          */
/*  output uint16 AirSys_rCohMnfMfBoostDeac;                                  */
/*  output uint16 AirSys_pDsThrLeak1;                                         */
/*  output uint16 AirSys_pDsThrLeak2;                                         */
/*  output boolean AirSys_bDgoBoost4_pDsThr;                                  */
/*  output boolean AirSys_bDgoBoost3_pDsThr;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INAIRFLOWDIAG_vidDgPrLeak(void)
{
   uint16 u16LocalInM_rCohMnfMf;
   uint16 u16LocalAiSypDsThLeak;
   uint16 u16LocalEngM_mfTotExCor;


   VEMS_vidGET(InM_rCohMnfMf, u16LocalInM_rCohMnfMf);
   VEMS_vidGET(EngM_mfTotExCor, u16LocalEngM_mfTotExCor);
   if (u16LocalInM_rCohMnfMf >= 16384)
   {
      AirSys_rCohMnfMfBoostDeac = 0;
   }
   else
   {
      AirSys_rCohMnfMfBoostDeac = (uint16)(16384 - u16LocalInM_rCohMnfMf);
   }

   u16LocalAiSypDsThLeak =
      MATHSRV_u16CalcParaIncAryU16(EngM_mfTotExCor_A,
                                   u16LocalEngM_mfTotExCor,
                                   9);
   AirSys_pDsThrLeak1 = MATHSRV_u16Interp1d(AirSys_pDsThrLeak1_T,
                                            u16LocalAiSypDsThLeak);
   AirSys_pDsThrLeak2 = MATHSRV_u16Interp1d(AirSys_pDsThrLeak2_T,
                                            u16LocalAiSypDsThLeak);

   if (AirSys_rCohMnfMfBoostDeac > AirSys_pDsThrLeak1)
   {
      if (AirSys_rCohMnfMfBoostDeac > AirSys_pDsThrLeak2)
      {
         AirSys_bDgoBoost4_pDsThr = 1;
         AirSys_bDgoBoost3_pDsThr = 0;
      }
      else
      {
         AirSys_bDgoBoost4_pDsThr = 0;
         AirSys_bDgoBoost3_pDsThr = 1;
      }
   }
   else
   {
      AirSys_bDgoBoost4_pDsThr = 0;
      AirSys_bDgoBoost3_pDsThr = 0;
   }
}
/*-------------------------------- end of file -------------------------------*/