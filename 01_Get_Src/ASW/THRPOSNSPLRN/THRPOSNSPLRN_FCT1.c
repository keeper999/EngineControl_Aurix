/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRPOSNSPLRN                                            */
/* !Description     : ThrPosnSpLrn component                                  */
/*                                                                            */
/* !Module          : THRPOSNSPLRN                                            */
/* !Description     : CALCUL DES CONSIGNES SPECIFIQUES DE POSITION PAPILLON   */
/*                    MOTORISE EN BOUCLE FERMEE                               */
/*                                                                            */
/* !File            : THRPOSNSPLRN_FCT1.C                                     */
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
/*   1 / THRPOSNSPLRN_vidInit                                                 */
/*   2 / THRPOSNSPLRN_vidMobiltRestorat                                       */
/*   3 / THRPOSNSPLRN_vidResMblitFuncEnb                                      */
/*   4 / THRPOSNSPLRN_vidRstRstrMblitSetP                                     */
/*   5 / THRPOSNSPLRN_vidRstrMblitSetPnt                                      */
/*   6 / THRPOSNSPLRN_vidCmptTemps                                            */
/*   7 / THRPOSNSPLRN_vidSglPapilBrisGlac                                     */
/*   8 / THRPOSNSPLRN_vidRawSpRstrMoblit                                      */
/*   9 / THRPOSNSPLRN_vidCntrndRstrMbilit                                     */
/*                                                                            */
/* !Reference   : V02 NT 11 00303 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRPOSNSPLRN/THRPOSNSPLRN_FC$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   01 Jul 2013 $*/
/* $Author::   etsasson                               $$Date::   01 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THRPOSNSPLRN.h"
#include "THRPOSNSPLRN_L.h"
#include "THRPOSNSPLRN_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSNSPLRN_vidInit                                       */
/* !Description :  Fonction initialisant les paramètres du module.            */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Thr_bFClnInProgs;                                           */
/*  input boolean Tpac_FCln_enable;                                           */
/*  input uint16 Thr_FClnClCtl_posnIniLoThruSp_C;                             */
/*  input uint16 Thr_FClnClCtl_vIniLoThru_C;                                  */
/*  input uint16 Thr_FLrnClCtl_posnIniLoThruSp_C;                             */
/*  input uint16 Thr_FLrnClCtl_vIniLoThru_C;                                  */
/*  input uint16 Thr_FMobRstor_tiMaxAuth_C;                                   */
/*  output boolean Thr_FLrnClCtl_bAcv;                                        */
/*  output uint8 Thr_FLrnClCtl_titempo;                                       */
/*  output boolean Thr_FLrnClCtl_bTempoEnd;                                   */
/*  output boolean Thr_FClnClCtl_bAcv;                                        */
/*  output boolean Thr_FSpcReqClCtl_bAcv;                                     */
/*  output uint16 Thr_FSpcReqClCtl_posnSp;                                    */
/*  output boolean Thr_bMblRstorAcv;                                          */
/*  output uint16 Thr_FLrnClCtl_posnTar;                                      */
/*  output uint16 Thr_FLrnClCtl_vTar;                                         */
/*  output uint8 ThrPosnSpLrn_u8State;                                        */
/*  output uint16 THRPOSNSPLRN_u16TimerCount;                                 */
/*  output uint16 THRPOSNSPLRN_u16SlewOut;                                    */
/*  output uint16 Thr_FLrnClCtl_posnSp;                                       */
/*  output uint16 Thr_FClnClCtl_posnSp;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSNSPLRN_vidInit(void)
{
   boolean  bLocalThr_bFClnInProgs;
   boolean  bLocalTpac_FCln_enable;


   VEMS_vidGET(Thr_bFClnInProgs, bLocalThr_bFClnInProgs);
   VEMS_vidGET(Tpac_FCln_enable, bLocalTpac_FCln_enable);
   VEMS_vidSET(Thr_FLrnClCtl_bAcv, 0);
   Thr_FLrnClCtl_titempo = 0;
   Thr_FLrnClCtl_bTempoEnd = 0;
   VEMS_vidSET(Thr_FClnClCtl_bAcv, 0);
   VEMS_vidSET(Thr_FSpcReqClCtl_bAcv, 0);
   VEMS_vidSET(Thr_FSpcReqClCtl_posnSp, 0);
   VEMS_vidSET(Thr_bMblRstorAcv, 0);
   if (  (bLocalThr_bFClnInProgs != 0)
      && (bLocalTpac_FCln_enable != 0))
   {
      Thr_FLrnClCtl_posnTar =
         (uint16)MATHSRV_udtMIN(Thr_FClnClCtl_posnIniLoThruSp_C, 1024);
      Thr_FLrnClCtl_vTar =
         (uint16)MATHSRV_udtMIN(Thr_FClnClCtl_vIniLoThru_C, 1024);
   }
   else
   {
      Thr_FLrnClCtl_posnTar =
         (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_posnIniLoThruSp_C, 1024);
      Thr_FLrnClCtl_vTar =
         (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_vIniLoThru_C, 1024);
   }
   ThrPosnSpLrn_u8State = THRPOSNSPLRN_INIT;
   THRPOSNSPLRN_u16TimerCount = Thr_FMobRstor_tiMaxAuth_C;
   THRPOSNSPLRN_u16SlewOut = 0;
   Thr_FLrnClCtl_posnSp = 0;
   Thr_FClnClCtl_posnSp = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSNSPLRN_vidMobiltRestorat                             */
/* !Description :  Cette fonction permet de restaurer la mobilité du papillon */
/*                 lors du réveil partiel du CMM.                             */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRPOSNSPLRN_vidResMblitFuncEnb();                       */
/*  extf argret void THRPOSNSPLRN_vidRstrMblitSetPnt();                       */
/*  extf argret void THRPOSNSPLRN_vidRstRstrMblitSetP();                      */
/*  input boolean Thr_bMblRstorEna;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSNSPLRN_vidMobiltRestorat(void)
{
   THRPOSNSPLRN_vidResMblitFuncEnb();
   if (Thr_bMblRstorEna != 0)
   {
      THRPOSNSPLRN_vidRstrMblitSetPnt();
   }
   else
   {
      THRPOSNSPLRN_vidRstRstrMblitSetP();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSNSPLRN_vidResMblitFuncEnb                            */
/* !Description :  Cette fonction permet d’activer la fonction de la          */
/*                 restauration de la mobilité du papillon si toutes les      */
/*                 conditions nécessaires sont réunies.                       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_batterie_brute;                                      */
/*  input uint8 Temperature_air;                                              */
/*  input uint8 Temperature_eau;                                              */
/*  input boolean Moteur_tournant;                                            */
/*  input boolean Thr_bCdnAcvCll;                                             */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  input boolean Thr_bMblRstorAcv_C;                                         */
/*  input uint16 Thr_uBattMaxStopsMblRstor_C;                                 */
/*  input uint16 Thr_uBattMinStopsMblRstor_C;                                 */
/*  input uint8 Tpac_MblRstor_air_temp_mini;                                  */
/*  input uint8 Tpac_MblRstor_water_temp_mini;                                */
/*  output boolean Thr_bMblRstorAcv;                                          */
/*  output boolean Thr_bMblRstorEna;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSNSPLRN_vidResMblitFuncEnb(void)
{
   boolean  bLocalThr_bMblRstorAcv;
   boolean  bLocalInhThrMobRstor;
   boolean  bLocalMoteurTournant;
   boolean  bLocalThr_bCdnAcvCll;
   uint8    u8LocalTemperatureAir;
   uint8    u8LocalTemperatureEau;
   uint8    u8LocalTpacThrottleControlState;
   uint16   u16LocalTensionBatterieBrute;


   bLocalInhThrMobRstor = GDGAR_bGetFRM(FRM_FRM_INHTHRMOBRSTOR);
   VEMS_vidGET(Tension_batterie_brute, u16LocalTensionBatterieBrute);
   VEMS_vidGET(Temperature_air, u8LocalTemperatureAir);
   VEMS_vidGET(Temperature_eau, u8LocalTemperatureEau);
   VEMS_vidGET(Moteur_tournant, bLocalMoteurTournant);
   VEMS_vidGET(Thr_bCdnAcvCll, bLocalThr_bCdnAcvCll);
   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpacThrottleControlState);

   if (  (Thr_bMblRstorAcv_C != 0)
      && (bLocalInhThrMobRstor == 0)
      && (u16LocalTensionBatterieBrute < Thr_uBattMaxStopsMblRstor_C)
      && (u16LocalTensionBatterieBrute > Thr_uBattMinStopsMblRstor_C)
      && (u8LocalTemperatureAir < Tpac_MblRstor_air_temp_mini)
      && (u8LocalTemperatureEau < Tpac_MblRstor_water_temp_mini)
      && (bLocalMoteurTournant == 0)
      && (bLocalThr_bCdnAcvCll != 0))
   {
      bLocalThr_bMblRstorAcv = 1;
   }
   else
   {
      bLocalThr_bMblRstorAcv = 0;
   }
   VEMS_vidSET(Thr_bMblRstorAcv, bLocalThr_bMblRstorAcv);
   if (  (bLocalThr_bMblRstorAcv != 0)
      && (u8LocalTpacThrottleControlState == TPAC_RESTOR_MOBILITY))
   {
      Thr_bMblRstorEna = 1;
   }
   else
   {
      Thr_bMblRstorEna = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSNSPLRN_vidRstRstrMblitSetP                           */
/* !Description :  Lorsque la fonction de restauration de la mobilité du      */
/*                 papillon est inactive, Thr_bMblRstorInProgs prend la valeur*/
/*                 0 et la consigne de position correspond à un retour au     */
/*                 limp-home.                                                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Thr_FMblRstor_posnReturnLihSp_C;                             */
/*  output uint16 Thr_FMblRstorClCtl_posnSp;                                  */
/*  output boolean Thr_bMblRstorInProgs;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSNSPLRN_vidRstRstrMblitSetP(void)
{
   uint16   u16LocalThr_FMblRstorClCtl_posnS;


   u16LocalThr_FMblRstorClCtl_posnS =
      (uint16)MATHSRV_udtMIN(Thr_FMblRstor_posnReturnLihSp_C, 1024);
   Thr_FMblRstorClCtl_posnSp = u16LocalThr_FMblRstorClCtl_posnS;
   VEMS_vidSET(Thr_bMblRstorInProgs, 0);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSNSPLRN_vidRstrMblitSetPnt                            */
/* !Description :  Cette fonction permet de calibrer le profil du signal de   */
/*                 commande du papillon permettant la restauration de sa      */
/*                 mobilité.                                                  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRPOSNSPLRN_vidCmptTemps();                             */
/*  extf argret void THRPOSNSPLRN_vidSglPapilBrisGlac();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSNSPLRN_vidRstrMblitSetPnt(void)
{
   THRPOSNSPLRN_vidCmptTemps();
   THRPOSNSPLRN_vidSglPapilBrisGlac();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSNSPLRN_vidCmptTemps                                  */
/* !Description :  Au-delà d’un durée maximale autorisée, la fonction de      */
/*                 restauration de la mobilité du papillon est arrêtée par    */
/*                 l’envoi d’un flag au gestionnaire de l’asservissement      */
/*                 papillon.                                                  */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 THRPOSNSPLRN_u16TimerCount;                                  */
/*  input uint16 Thr_FMobRstor_tiMaxAuth_C;                                   */
/*  output uint16 THRPOSNSPLRN_u16TimerCount;                                 */
/*  output uint16 Thr_FMblRstor_tiMblRstor;                                   */
/*  output boolean Thr_bMblRstorInProgs;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSNSPLRN_vidCmptTemps(void)
{
   sint32   s32LocalThr_FMblRstorTMblRstor;


   if (THRPOSNSPLRN_u16TimerCount > 0)
   {
      THRPOSNSPLRN_u16TimerCount = (uint16)( THRPOSNSPLRN_u16TimerCount - 1);
   }
   s32LocalThr_FMblRstorTMblRstor = (sint32)( ( Thr_FMobRstor_tiMaxAuth_C
                                              + 1)
                                            - THRPOSNSPLRN_u16TimerCount);
   Thr_FMblRstor_tiMblRstor =
      (uint16)MATHSRV_udtCLAMP(s32LocalThr_FMblRstorTMblRstor,0 , 12000);
   if (THRPOSNSPLRN_u16TimerCount == 0)
   {
      VEMS_vidSET(Thr_bMblRstorInProgs, 0);
   }
   else
   {
      VEMS_vidSET(Thr_bMblRstorInProgs, 1);
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSNSPLRN_vidSglPapilBrisGlac                           */
/* !Description :  Cette fonction permet de calibrer le profil du signal de   */
/*                 commande du papillon permettant la restauration de sa      */
/*                 mobilité.                                                  */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRPOSNSPLRN_vidRawSpRstrMoblit();                       */
/*  extf argret void THRPOSNSPLRN_vidCntrndRstrMbilit();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSNSPLRN_vidSglPapilBrisGlac(void)
{
   THRPOSNSPLRN_vidRawSpRstrMoblit();
   THRPOSNSPLRN_vidCntrndRstrMbilit();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSNSPLRN_vidRawSpRstrMoblit                            */
/* !Description :  Cette fonction permet de définir la forme brute du signal  */
/*                 de consigne de commande du papillon pour la restauration de*/
/*                 sa mobilité.                                               */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf MATHSRV_u16CalcParaIncAryU16(????);                                  */
/*  extf MATHSRV_u16Interp1d(????);                                           */
/*  input uint16 Thr_FMblRstor_ti_bkpt_map[16];                               */
/*  input uint16 Thr_FMblRstor_tiMblRstor;                                    */
/*  input uint16 Thr_FMblRstorClCtl_Sp_map[16];                               */
/*  output uint16 Thr_FMblRstorClCtl_SpRaw;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSNSPLRN_vidRawSpRstrMoblit(void)
{
   uint16 u16LocalCalcPara;
   uint16 u16LocalInterp1D;


   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(Thr_FMblRstor_ti_bkpt_map,
                                                   Thr_FMblRstor_tiMblRstor,
                                                   16);
   u16LocalInterp1D =
      MATHSRV_u16Interp1d(Thr_FMblRstorClCtl_Sp_map, u16LocalCalcPara);
   Thr_FMblRstorClCtl_SpRaw = (uint16)MATHSRV_udtMIN(u16LocalInterp1D, 1024);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSNSPLRN_vidCntrndRstrMbilit                           */
/* !Description :  Des contraintes d’amplitude et de dynamique (pentes) sont  */
/*                 appliquées au signal de consigne brute de commande du      */
/*                 papillon pour la restauration de sa mobilité.              */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf MATHSRV_u16SlewFilter(????);                                         */
/*  input uint16 Thr_FMblRstorClCtl_SpRaw;                                    */
/*  input uint16 Thr_FMblRstorClCtl_HithruThd_C;                              */
/*  input uint16 Thr_FMblRstorClCtl_vHithru_C;                                */
/*  input uint16 Thr_FMblRstorClCtl_vTar_C;                                   */
/*  input uint16 THRPOSNSPLRN_u16SlewOut;                                     */
/*  input uint16 Thr_FMblRstorClCtl_LihSp_C;                                  */
/*  input uint16 Thr_FMblRstorClCtl_SpMax_C;                                  */
/*  output uint16 THRPOSNSPLRN_u16SlewOut;                                    */
/*  output uint16 Thr_FMblRstorClCtl_posnSp;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSNSPLRN_vidCntrndRstrMbilit(void)
{
   uint16   u16LocalSlewRateIncDecValue;
   uint16   u16LocalSwitchOut;
   uint16   u16LocalThrFMblRstorClCtlPosnSp;


   if (Thr_FMblRstorClCtl_SpRaw >= Thr_FMblRstorClCtl_HithruThd_C)
   {
      u16LocalSwitchOut = Thr_FMblRstorClCtl_vHithru_C;
   }
   else
   {
      u16LocalSwitchOut = Thr_FMblRstorClCtl_vTar_C;
   }
   u16LocalSlewRateIncDecValue =  (uint16)( ( u16LocalSwitchOut
                                         * Thr_SampleTiMid_SC)
                                       / 1000);
   THRPOSNSPLRN_u16SlewOut = MATHSRV_u16SlewFilter(THRPOSNSPLRN_u16SlewOut,
                                                   Thr_FMblRstorClCtl_SpRaw,
                                                   u16LocalSlewRateIncDecValue,
                                                   u16LocalSlewRateIncDecValue);
   u16LocalThrFMblRstorClCtlPosnSp =
      (uint16)MATHSRV_udtCLAMP(THRPOSNSPLRN_u16SlewOut,
                               Thr_FMblRstorClCtl_LihSp_C,
                               Thr_FMblRstorClCtl_SpMax_C);
   Thr_FMblRstorClCtl_posnSp =
      (uint16)MATHSRV_udtMIN(u16LocalThrFMblRstorClCtlPosnSp, 1024);
}
/*----------------------------- end of file ----------------------------------*/