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
/* !File            : INMNFPRESDIAG_FCT2.C                                    */
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
/*   1 / INMNFPRESDIAG_vidDftPresStallRun                                     */
/*   2 / INMNFPRESDIAG_vidMnfPresDiagAuth                                     */
/*   3 / INMNFPRESDIAG_vidDiagFctStab                                         */
/*   4 / INMNFPRESDIAG_vidDftPresNormOper                                     */
/*   5 / INMNFPRESDIAG_vidMnfPresDiagLim                                      */
/*   6 / INMNFPRESDIAG_vidDftPres_PresLim                                     */
/*   7 / INMNFPRESDIAG_vidDiagAuthFulLoad                                     */
/*   8 / INMNFPRESDIAG_vidDftPresFullload                                     */
/*   9 / INMNFPRESDIAG_vidMnfPresDiagGrd                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_6539920 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/INMNFPRESDIAG/INMNFPRESDIAG_FCT2.C$*/
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
#include "INMNFPRESDIAG_L.h"
#include "INMNFPRESDIAG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidDftPresStallRun                           */
/* !Description :  Le diagnostic du capteur de pression collecteur au         */
/*                 démarrage revient à comparer la différence de pression     */
/*                 calculée avec un seuil minimale de pression.               */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03503_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ext_pDsThrStrt;                                              */
/*  input uint16 Diag_min_pressure_in_crank;                                  */
/*  input uint16 Diag_pressure_min_decrease;                                  */
/*  output boolean AirPres_bDgoCrkCoh_pDsThr;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidDftPresStallRun(void)
{
   sint32 s32LocalDifference;


   s32LocalDifference = (sint32)(Ext_pDsThrStrt - Diag_min_pressure_in_crank);

   if (s32LocalDifference < Diag_pressure_min_decrease)
   {
      AirPres_bDgoCrkCoh_pDsThr = 1;
   }
   else
   {
      AirPres_bDgoCrkCoh_pDsThr = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidMnfPresDiagAuth                           */
/* !Description :  Gestion de l'autorisation du diagnostic de la pression     */
/*                 collecteur.                                                */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03503_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INMNFPRESDIAG_vidThrCohAuth();                           */
/*  extf argret void INMNFPRESDIAG_vidDiagFctStab();                          */
/*  extf argret void INMNFPRESDIAG_vidDftPresNormOper();                      */
/*  extf argret void INMNFPRESDIAG_vidThrCohDiag();                           */
/*  input boolean AirPres_bMonRunStabCoh_pDsThr;                              */
/*  input boolean AirPres_bMonRunThrCoh_pDsThr;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidMnfPresDiagAuth(void)
{
   /*00_ThrCohAuth*/
   INMNFPRESDIAG_vidThrCohAuth();

   /*01_Diag_fct_stabilise*/
   INMNFPRESDIAG_vidDiagFctStab();

   /*02_DftPres_NormOper*/
   if (AirPres_bMonRunStabCoh_pDsThr != 0)
   {
      INMNFPRESDIAG_vidDftPresNormOper();
   }

   /*03_ThrCohDiag*/
   if (AirPres_bMonRunThrCoh_pDsThr != 0)
   {
      INMNFPRESDIAG_vidThrCohDiag();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidDiagFctStab                               */
/* !Description :  Le diagnostic revient à vérifier que la pression collecteur*/
/*                 est comprise entre un seuil min et un seuil max lorsque la */
/*                 position papillon est comprise entre un seuil min et un    */
/*                 seuil max depuis un certain temps.                         */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Corrected_throttle_position;                                  */
/*  input sint16 Ext_pDsThrMes;                                               */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint8 Diag_map_bounds_lower_throttle[16];                           */
/*  input uint16 Diag_map_bounds_lower_pressure;                              */
/*  input uint8 Diag_map_pressure_counter;                                    */
/*  input uint8 Diag_map_under_threshold;                                     */
/*  input uint8 Diag_map_bounds_upper_throttle[16];                           */
/*  input uint16 Diag_map_bounds_upper_pressure;                              */
/*  input uint8 Diag_map_upper_threshold;                                     */
/*  output boolean INMNFPRESDIAG_bAirPresDgoStabCoh;                          */
/*  output uint8 Diag_map_pressure_counter;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidDiagFctStab(void)
{
   uint8  u8LocalCalcInterp;
   uint8  u8LocalCorrected_throttle_pos;
   uint16 u16LocalRegime_moteur;
   uint16 u16LocalCalcPara;
   uint32 u32LocalRegMot;
   sint16 s16LocalExt_pDsThrMes;


   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(Corrected_throttle_position, u8LocalCorrected_throttle_pos);
   VEMS_vidGET(Ext_pDsThrMes, s16LocalExt_pDsThrMes);

   u32LocalRegMot = (uint32)(u16LocalRegime_moteur * 8);
   u16LocalRegime_moteur = (uint16)MATHSRV_udtMIN(u32LocalRegMot, 65535);

   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                                   u16LocalRegime_moteur,
                                                   16);
   u8LocalCalcInterp = MATHSRV_u8Interp1d(Diag_map_bounds_lower_throttle,
                                          u16LocalCalcPara);

   if (u8LocalCorrected_throttle_pos >= u8LocalCalcInterp)
   {
      if (s16LocalExt_pDsThrMes < Diag_map_bounds_lower_pressure)
      {
         if (Diag_map_pressure_counter >= Diag_map_under_threshold)
         {
            INMNFPRESDIAG_bAirPresDgoStabCoh = 1;
            Diag_map_pressure_counter = Diag_map_under_threshold;
         }
         else
         {
            INMNFPRESDIAG_bAirPresDgoStabCoh = 0;
            Diag_map_pressure_counter = (uint8)(Diag_map_pressure_counter + 1);
         }
      }
      else
      {
         INMNFPRESDIAG_bAirPresDgoStabCoh = 0;
         Diag_map_pressure_counter = 0;
      }
   }
   else
   {
      u8LocalCalcInterp = MATHSRV_u8Interp1d(Diag_map_bounds_upper_throttle,
                                             u16LocalCalcPara);
      if (u8LocalCorrected_throttle_pos < u8LocalCalcInterp)
      {
         if (s16LocalExt_pDsThrMes >= Diag_map_bounds_upper_pressure)
         {
            if (Diag_map_pressure_counter >= Diag_map_upper_threshold)
            {
               INMNFPRESDIAG_bAirPresDgoStabCoh = 1;
               Diag_map_pressure_counter = Diag_map_upper_threshold;
            }
            else
            {
               INMNFPRESDIAG_bAirPresDgoStabCoh = 0;
               Diag_map_pressure_counter =
                  (uint8)(Diag_map_pressure_counter + 1);
            }
         }
         else
         {
            INMNFPRESDIAG_bAirPresDgoStabCoh = 0;
            Diag_map_pressure_counter = 0;
         }
      }
      else
      {
         INMNFPRESDIAG_bAirPresDgoStabCoh = 0;
         Diag_map_pressure_counter = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidDftPresNormOper                           */
/* !Description :  Résultat du diagnostic de cohérence entre la position      */
/*                 papillon et la pression d'admission                        */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean INMNFPRESDIAG_bAirPresDgoStabCoh;                           */
/*  output boolean AirPres_bDgoStabCoh_pDsThr;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidDftPresNormOper(void)
{
   AirPres_bDgoStabCoh_pDsThr = INMNFPRESDIAG_bAirPresDgoStabCoh;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidMnfPresDiagLim                            */
/* !Description :  Le diagnostic « hors zone » de la pression collecteur est  */
/*                 activé seulement si :   -  Le diagnostic n’est pas inhibé, */
/*                 -  La vanne canister est fermée depuis suffisamment        */
/*                 longtemps.                                                 */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void INMNFPRESDIAG_vidDftPres_PresLim();                      */
/*  input boolean AirPres_bCanPurgOk;                                         */
/*  output boolean AirPres_bMonRunORng_pDsThr;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidMnfPresDiagLim(void)
{
   boolean bLocalInhInMnfPresDiag;


   bLocalInhInMnfPresDiag = GDGAR_bGetFRM(FRM_FRM_INHINMNFPRESDIAG);
   if (  (bLocalInhInMnfPresDiag == 0)
      && (AirPres_bCanPurgOk != 0))
   {
      AirPres_bMonRunORng_pDsThr = 1;
      /*01_DftPres_PresLim*/
      INMNFPRESDIAG_vidDftPres_PresLim();
   }
   else
   {
      AirPres_bMonRunORng_pDsThr = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidDftPres_PresLim                           */
/* !Description :  La détection du défaut revient à tester avec 2 seuils      */
/*                 calibrables (seuil Mini et seuil Maxi) si la valeur mesurée*/
/*                 se  trouve hors de la zone de fonctionnement normale.      */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03503_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_pDsThrMes;                                               */
/*  input uint16 AirPres_pDsThrThdORngMax_C;                                  */
/*  input uint16 AirPres_pDsThrThdORngMin_C;                                  */
/*  output boolean AirPres_bDgoORng_pDsThr;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidDftPres_PresLim(void)
{
   sint16 s16LocalExt_pDsThrMes;


   VEMS_vidGET(Ext_pDsThrMes, s16LocalExt_pDsThrMes);
   if (  (s16LocalExt_pDsThrMes > AirPres_pDsThrThdORngMax_C)
      || (s16LocalExt_pDsThrMes < AirPres_pDsThrThdORngMin_C))
   {
      AirPres_bDgoORng_pDsThr = 1;
   }
   else
   {
      AirPres_bDgoORng_pDsThr = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidDiagAuthFulLoad                           */
/* !Description :  Gestion de l'autorisation du diagnostic de la pression     */
/*                 collecteur en pleine charge.                               */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void INMNFPRESDIAG_vidDftPresFullload();                      */
/*  input uint8 Corrected_throttle_position;                                  */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 AirPres_rOpThdMin_C;                                          */
/*  input uint16 AirPres_nEngThdMin_C;                                        */
/*  input boolean AirPres_bCanPurgOk;                                         */
/*  output boolean AirPres_bMonRunFldCoh_pDsThr;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidDiagAuthFulLoad(void)
{
   boolean bLocalInhInMnfPresDiag;
   uint8   u8LocalCorrected_throttle_pos;
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalOpThdMin;


   VEMS_vidGET(Corrected_throttle_position, u8LocalCorrected_throttle_pos);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   bLocalInhInMnfPresDiag = GDGAR_bGetFRM(FRM_FRM_INHINMNFPRESDIAG);

   u16LocalOpThdMin = (uint16)((AirPres_rOpThdMin_C * 256) / 100);
   if (  (bLocalInhInMnfPresDiag == 0)
      && (u8LocalCorrected_throttle_pos > u16LocalOpThdMin)
      && (u16LocalRegime_moteur > AirPres_nEngThdMin_C)
      && (AirPres_bCanPurgOk != 0))
   {
      AirPres_bMonRunFldCoh_pDsThr = 1;
      /*01_DftPres_PleineCharge*/
      INMNFPRESDIAG_vidDftPresFullload();
   }
   else
   {
      AirPres_bMonRunFldCoh_pDsThr = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidDftPresFullload                           */
/* !Description :  Fonction qui lancer un diagnostic suivant la valeur d'une  */
/*                 booléene.                                                  */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INMNFPRESDIAG_vidAirPressSens();                         */
/*  extf argret void INMNFPRESDIAG_vidNoAirPressSens();                       */
/*  input boolean Cf_bPresPAirExtSens;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidDftPresFullload(void)
{
   boolean bLocalCf_bPresPAirExtSens;


   VEMS_vidGET(Cf_bPresPAirExtSens, bLocalCf_bPresPAirExtSens);
   if (bLocalCf_bPresPAirExtSens != 0)
   {
      INMNFPRESDIAG_vidAirPressSens();
   }
   else
   {
      INMNFPRESDIAG_vidNoAirPressSens();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidMnfPresDiagGrd                            */
/* !Description :  Le diagnostic du gradient de la pression collecteur est    */
/*                 activé seulement si : -  Le diagnostic n’est pas inhibé,  -*/
/*                  La vanne canister est fermée depuis suffisamment          */
/*                 longtemps.                                                 */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03503_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void INMNFPRESDIAG_vidDftPres_GrdPres();                      */
/*  extf argret void INMNFPRESDIAG_vidDftPres_Reinit();                       */
/*  input boolean AirPres_bMonRunGrd_pDsThr;                                  */
/*  input boolean AirPres_bCanPurgOk;                                         */
/*  output boolean AirPres_bMonRunGrd_pDsThr;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidMnfPresDiagGrd(void)
{
   boolean bLocalInhInMnfPresDiag;
   boolean bLocalAirPres_bMonRunGrd_pDsThr;


   bLocalInhInMnfPresDiag = GDGAR_bGetFRM(FRM_FRM_INHINMNFPRESDIAG);
   bLocalAirPres_bMonRunGrd_pDsThr = AirPres_bMonRunGrd_pDsThr;
   if (  (bLocalInhInMnfPresDiag == 0)
      && (AirPres_bCanPurgOk != 0))
   {
      AirPres_bMonRunGrd_pDsThr = 1;
      /*01_DftPres_GrdPres*/
      INMNFPRESDIAG_vidDftPres_GrdPres();
   }
   else
   {
      AirPres_bMonRunGrd_pDsThr = 0;
   }
   if (  (AirPres_bMonRunGrd_pDsThr != 0)
      && (bLocalAirPres_bMonRunGrd_pDsThr == 0))
   {
      /*02_DftPres_Reinit*/
      INMNFPRESDIAG_vidDftPres_Reinit();
   }
}
/************************************* end of file ****************************/