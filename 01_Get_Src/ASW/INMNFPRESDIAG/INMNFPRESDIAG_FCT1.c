/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INMNFPRESDIAG                                           */
/* !Description     : INMNFPRESDIAG Component.                                */
/*                                                                            */
/* !Module          : INMNFPRESDIAG                                           */
/* !Description     : Diagnostic fonctionnel de la pression collecteur.       */
/*                                                                            */
/* !File            : INMNFPRESDIAG_FCT1.C                                    */
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
/*   1 / INMNFPRESDIAG_vidInitOutput                                          */
/*   2 / INMNFPRESDIAG_vidMnfPresDiagInit                                     */
/*   3 / INMNFPRESDIAG_vidCanPurgVerif                                        */
/*   4 / INMNFPRESDIAG_vidMfPrDiagBfStart                                     */
/*   5 / INMNFPRESDIAG_vidUpdtMnfPresStll                                     */
/*   6 / INMNFPRESDIAG_vidDftPres_Stall                                       */
/*   7 / INMNFPRESDIAG_vidMfPrDiagDrStart                                     */
/*   8 / INMNFPRESDIAG_vidUpdtMnfPresCrnk                                     */
/*   9 / INMNFPRESDIAG_vidDetectInCrank                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_6539920 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/INMNFPRESDIAG/INMNFPRESDIAG_FCT1.C$*/
/* $Revision::   1.10     $$Author::   achebino       $$Date::   26 May 2014 $*/
/* $Author::   achebino                               $$Date::   26 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "INMNFPRESDIAG.h"
#include "INMNFPRESDIAG_L.H"
#include "INMNFPRESDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidInitOutput                                */
/* !Description :  Fonction d'initialisation des variables internes.          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 AirPres_tiDly_CanPurg;                                       */
/*  output boolean AirPres_bMonRunStallCoh_pDsThr;                            */
/*  output boolean AirPres_bDgoStallCoh_pDsThr;                               */
/*  output boolean AirPres_bDetFirstSt;                                       */
/*  output boolean INMNFPRESDIAG_bDiagActIndicator;                           */
/*  output boolean AirPres_bDgoCrkCoh_pDsThr;                                 */
/*  output boolean AirPres_bMonRunCrkCoh_pDsThr;                              */
/*  output uint16 Diag_min_pressure_in_crank;                                 */
/*  output boolean INMNFPRESDIAG_bAirPresDgoStabCoh;                          */
/*  output uint8 Diag_map_pressure_counter;                                   */
/*  output boolean AirPres_bMonRunStabCoh_pDsThr;                             */
/*  output boolean AirPres_bDgoStabCoh_pDsThr;                                */
/*  output boolean AirPres_bMonRunThrCoh_pDsThr;                              */
/*  output boolean AirPres_bDgoThrCoh_pDsThr;                                 */
/*  output boolean AirPres_bMonRunORng_pDsThr;                                */
/*  output boolean AirPres_bDgoORng_pDsThr;                                   */
/*  output boolean AirPres_bMonRunFldCoh_pDsThr;                              */
/*  output boolean AirPres_bDgoFldCoh_pDsThr;                                 */
/*  output boolean AirPres_bMonRunGrd_pDsThr;                                 */
/*  output boolean AirPres_bDgoGrd_pDsThr;                                    */
/*  output uint16 AirPres_pFrzDsThrDiagGrd;                                   */
/*  output uint16 AirPres_Manifold_PresAcq;                                   */
/*  output boolean INMNFPRESDIAG_bDetFirstStPrev;                             */
/*  output boolean INMNFPRESDIAG_bWkuMainPrev;                                */
/*  output boolean AirPres_bAuthUpdPres;                                      */
/*  output boolean AirPres_bDiagAftStall;                                     */
/*  output boolean AirPres_bDetFirstStTCk;                                    */
/*  output boolean AirPres_bDetFirstRun;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidInitOutput(void)
{
   /*F02_InMnfPresDiag_CanPurg*/
   AirPres_tiDly_CanPurg = 0;

   /*F03_InMnfPresDiag_AvantDemarrage */
   AirPres_bMonRunStallCoh_pDsThr = 0;
   AirPres_bDgoStallCoh_pDsThr = 0;
   AirPres_bDetFirstSt = 0;

   /*F04_InMnfPresDiag_AuDemarrage*/
   INMNFPRESDIAG_bDiagActIndicator = 0;
   AirPres_bDgoCrkCoh_pDsThr = 0;
   AirPres_bMonRunCrkCoh_pDsThr = 0;

   /*01_diag_min_pressure_update*/
   Diag_min_pressure_in_crank = 1310;

   /*F05_InMnfPresDiag_EnStabilise*/
   INMNFPRESDIAG_bAirPresDgoStabCoh = 0;
   Diag_map_pressure_counter = 0;
   AirPres_bMonRunStabCoh_pDsThr = 0;
   AirPres_bDgoStabCoh_pDsThr = 0;
   AirPres_bMonRunThrCoh_pDsThr = 0;
   AirPres_bDgoThrCoh_pDsThr = 0;

   /*F06_InMnfPresDiag_PresLim */
   AirPres_bMonRunORng_pDsThr = 0;
   AirPres_bDgoORng_pDsThr = 0;

   /*F07_InMnfPresDiag_PleineCharge*/
   AirPres_bMonRunFldCoh_pDsThr = 0;
   AirPres_bDgoFldCoh_pDsThr = 0;

   /*F08_InMnfPresDiag_GrdPres */
   AirPres_bMonRunGrd_pDsThr = 0;
   AirPres_bDgoGrd_pDsThr = 0;

   /*01_DftPres_GrdPres*/
   AirPres_pFrzDsThrDiagGrd = 0;

   /*01_DftPres_GrdPres*/
   AirPres_Manifold_PresAcq = 0;

   /*F00_InMnfPresDiag_GestionActivation_demarrage*/
   INMNFPRESDIAG_bDetFirstStPrev = 0;
   INMNFPRESDIAG_bWkuMainPrev = 0;
   AirPres_bAuthUpdPres = 0;
   AirPres_bDiagAftStall = 0;
   AirPres_bDetFirstStTCk = 0;
   AirPres_bDetFirstRun = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidMnfPresDiagInit                           */
/* !Description :  A l’initialisation du calculateur, le booléen lié à la     */
/*                 durée de la fermeture de la vanne canister est mis à 0, et */
/*                 le compteur pour le diagnostic de cohérence de la pression */
/*                 collecteur pendant le démarrage doit être réinitialisé.    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Diag_press_stall_to_run_delay;                                */
/*  output uint8 Diag_press_stall_to_run_counter;                             */
/*  output boolean AirPres_bCanPurgOk;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidMnfPresDiagInit(void)
{
   Diag_press_stall_to_run_counter = Diag_press_stall_to_run_delay;
   AirPres_bCanPurgOk = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidCanPurgVerif                              */
/* !Description :  La stratégie doit vérifier en continu que la vanne de purge*/
/*                 canister est restée fermée suffisamment longtemps afin     */
/*                 d’autoriser les diagnostics utilisant l’information.       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Demande_purge_dormant;                                      */
/*  input uint8 AirPres_tiDly_CanPurg;                                        */
/*  input uint8 AirPres_tiDly_CanPurg_C;                                      */
/*  output uint8 AirPres_tiDly_CanPurg;                                       */
/*  output boolean AirPres_bCanPurgOk;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidCanPurgVerif(void)
{
   boolean bLocalDemande_purge_dormant;


   VEMS_vidGET(Demande_purge_dormant, bLocalDemande_purge_dormant);

   if (bLocalDemande_purge_dormant !=0)
   {
      if (AirPres_tiDly_CanPurg > 0)
      {
         AirPres_tiDly_CanPurg = (uint8)(AirPres_tiDly_CanPurg - 1);
      }
   }
   else
   {
      AirPres_tiDly_CanPurg = AirPres_tiDly_CanPurg_C;
   }

   if (AirPres_tiDly_CanPurg == 0)
   {
      AirPres_bCanPurgOk = 1;
   }
   else
   {
      AirPres_bCanPurgOk = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidMfPrDiagBfStart                           */
/* !Description :  Gestion du diagnostic de la pression collecteur avant      */
/*                 démarrage.                                                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void INMNFPRESDIAG_vidUpdtMnfPresStll();                      */
/*  extf argret void INMNFPRESDIAG_vidDftPres_Stall();                        */
/*  input uint32 Time_since_stall;                                            */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean AirPres_bAuthUpdPres;                                       */
/*  input boolean AirPres_bDetFirstStTCk;                                     */
/*  input uint8 Duree_arret_moteur_mini_diag;                                 */
/*  output boolean AirPres_bDetFirstSt;                                       */
/*  output boolean AirPres_bMonRunStallCoh_pDsThr;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidMfPrDiagBfStart(void)
{
   /*F03_InMnfPresDiag_AvantDemarrage*/
   boolean bLocalInhInMnfPresDiag;
   boolean bLocalInhDiagMnfPresStallCoh;
   uint8   u8LocalVehicle_active_state;
   uint32  u32LocalTime_since_stall;
   uint32  u32LocalTime_since_stall_2;


   VEMS_vidGET(Time_since_stall, u32LocalTime_since_stall);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   bLocalInhInMnfPresDiag = GDGAR_bGetFRM(FRM_FRM_INHINMNFPRESDIAG);
   bLocalInhDiagMnfPresStallCoh = GDGAR_bGetFRM(FRM_FRM_INHDIAGMNFPRESSTALLCOH);

   /*Production of AirPres_bDetFirstSt*/
   if (  (u8LocalVehicle_active_state == VS_STALL)
      && (AirPres_bAuthUpdPres != 0)
      && (bLocalInhInMnfPresDiag == 0))
   {
      /*01_Mise_a_jour_pression_stall*/
      INMNFPRESDIAG_vidUpdtMnfPresStll();
      AirPres_bDetFirstSt = 1;
   }
   else
   {
      AirPres_bDetFirstSt = 0;
   }

   /*Prouction of AirPres_bMonRunStallCoh_pDsThr*/
   u32LocalTime_since_stall_2 = ( u32LocalTime_since_stall
                                * (EngSt_SampleTiSlow_SC / 1000));
   if (  (AirPres_bDetFirstStTCk != 0)
      && (u32LocalTime_since_stall_2 >= Duree_arret_moteur_mini_diag)
      && (bLocalInhDiagMnfPresStallCoh == 0))
   {
      AirPres_bMonRunStallCoh_pDsThr = 1;
      /*02_DftPres_Stall*/
      INMNFPRESDIAG_vidDftPres_Stall();
   }
   else
   {
      AirPres_bMonRunStallCoh_pDsThr = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidUpdtMnfPresStll                           */
/* !Description :  La pression collecteur est recopiée dans la variable de    */
/*                 mémorisation de la pression collecteur « Moteur calé ».    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_pDsThrMes;                                               */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  output uint16 Ext_pDsThrStrt;                                             */
/*  output uint16 Ext_pAirExtStrt;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidUpdtMnfPresStll(void)
{
   uint16 u16LocalExt_pAirExtMes;
   sint16 s16LocalExt_pDsThrMes;


   VEMS_vidGET(Ext_pDsThrMes, s16LocalExt_pDsThrMes);
   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   Ext_pDsThrStrt = (uint16)MATHSRV_udtCLAMP(s16LocalExt_pDsThrMes,
                                             0,
                                             6000);
   Ext_pAirExtStrt = (uint16)MATHSRV_udtCLAMP(u16LocalExt_pAirExtMes,
                                              500,
                                              1500);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidDftPres_Stall                             */
/* !Description :  Fonction qui lancer un diagnostic suivant la valeur d'une  */
/*                 booléene.                                                  */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INMNFPRESDIAG_vidAirPressSens1();                        */
/*  extf argret void INMNFPRESDIAG_vidNoAirPressSens1();                      */
/*  input boolean Cf_bPresPAirExtSens;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidDftPres_Stall(void)
{
   boolean bLocalCf_bPresPAirExtSens;


   VEMS_vidGET(Cf_bPresPAirExtSens, bLocalCf_bPresPAirExtSens);
   if (bLocalCf_bPresPAirExtSens != 0)
   {
      INMNFPRESDIAG_vidAirPressSens1();
   }
   else
   {
      INMNFPRESDIAG_vidNoAirPressSens1();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidMfPrDiagDrStart                           */
/* !Description :  Gestion du diagnostic de la pression collecteur pendant le */
/*                 démarrage.                                                 */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03503_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void INMNFPRESDIAG_vidUpdtMnfPresCrnk();                      */
/*  extf argret void INMNFPRESDIAG_vidDetectInCrank();                        */
/*  input st07 Engine_running_state;                                          */
/*  input st23 Vehicle_active_state;                                          */
/*  input uint8 Temperature_eau;                                              */
/*  input boolean AirPres_bDetFirstRun;                                       */
/*  input uint8 Diag_press_stall_to_run_counter;                              */
/*  input uint8 Diag_press_stall_to_run_delay;                                */
/*  input boolean INMNFPRESDIAG_bDiagActIndicator;                            */
/*  input boolean AirPres_bMonWaitCrkCoh_pDsThr;                              */
/*  input boolean AirPres_bCanPurgOk;                                         */
/*  input uint8 Crank_to_run_water_temp_thres;                                */
/*  input boolean AirPres_bMonRunCrkCoh_pDsThr;                               */
/*  output uint8 Diag_press_stall_to_run_counter;                             */
/*  output boolean AirPres_bMonWaitCrkCoh_pDsThr;                             */
/*  output boolean AirPres_bMonRunCrkCoh_pDsThr;                              */
/*  output boolean INMNFPRESDIAG_bDiagActIndicator;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidMfPrDiagDrStart(void)
{
   /*F04_InMnfPresDiag_AuDemarrage*/
   boolean bLocalInhInMnfPresDiag;
   uint8   u8LocalEngine_running_state;
   uint8   u8LocalVehicle_active_state;
   uint8   u8LocalTemperature_eau;


   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   bLocalInhInMnfPresDiag = GDGAR_bGetFRM(FRM_FRM_INHINMNFPRESDIAG);

   if (AirPres_bDetFirstRun != 0)
   {
      if (Diag_press_stall_to_run_counter > 0)
      {
         Diag_press_stall_to_run_counter =
            (uint8)(Diag_press_stall_to_run_counter - 1);
      }
   }
   else
   {
      Diag_press_stall_to_run_counter = Diag_press_stall_to_run_delay;
   }

   if (  (Diag_press_stall_to_run_counter < Diag_press_stall_to_run_delay)
      && (Diag_press_stall_to_run_counter > 0))
   {
      AirPres_bMonWaitCrkCoh_pDsThr = 1;
   }
   else
   {
      AirPres_bMonWaitCrkCoh_pDsThr = 0;
   }

   AirPres_bMonRunCrkCoh_pDsThr = INMNFPRESDIAG_bDiagActIndicator;

   if (  (AirPres_bMonWaitCrkCoh_pDsThr != 0)
      && (AirPres_bCanPurgOk != 0)
      && (bLocalInhInMnfPresDiag == 0)
      && (u8LocalEngine_running_state == ERUN_ON_IDLE)
      && (u8LocalTemperature_eau >= Crank_to_run_water_temp_thres)
      && (u8LocalVehicle_active_state == VS_RUNNING))
   {
      /*01_diag_min_pressure_update*/
      INMNFPRESDIAG_vidUpdtMnfPresCrnk();
      INMNFPRESDIAG_bDiagActIndicator = 1;
   }
   else
   {
      INMNFPRESDIAG_bDiagActIndicator = 0;
   }
   if (AirPres_bMonRunCrkCoh_pDsThr != 0)
   {
      /*02_detection_in_cranking*/
      INMNFPRESDIAG_vidDetectInCrank();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidUpdtMnfPresCrnk                           */
/* !Description :  Pendant  le délai durant  le démarrage,  la  stratégie     */
/*                 vient mémoriser  la  valeur de  la pression  collecteur  la*/
/*                 plus  basse obtenue.                                       */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_pDsThrMes;                                               */
/*  input uint16 Diag_min_pressure_in_crank;                                  */
/*  output uint16 Diag_min_pressure_in_crank;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidUpdtMnfPresCrnk(void)
{
   sint16 s16LocalExt_pDsThrMes;


   VEMS_vidGET(Ext_pDsThrMes, s16LocalExt_pDsThrMes);
   if (s16LocalExt_pDsThrMes < Diag_min_pressure_in_crank)
   {
      Diag_min_pressure_in_crank =
         (uint16)MATHSRV_udtCLAMP(s16LocalExt_pDsThrMes,
                                  0,
                                  6000);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidDetectInCrank                             */
/* !Description :  Lorsque  le délai est écoulé,  la stratégie compare  la    */
/*                 pression collecteur mesurée  juste avant  le démarrage du  */
/*                 moteur avec la pression collecteur minimale mesurée pendant*/
/*                 le démarrage.                                              */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INMNFPRESDIAG_vidDftPresStallRun();                      */
/*  input boolean AirPres_bMonWaitCrkCoh_pDsThr;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidDetectInCrank(void)
{
   if (AirPres_bMonWaitCrkCoh_pDsThr == 0)
   {
      INMNFPRESDIAG_vidDftPresStallRun();
   }
}
/************************************* end of file ****************************/