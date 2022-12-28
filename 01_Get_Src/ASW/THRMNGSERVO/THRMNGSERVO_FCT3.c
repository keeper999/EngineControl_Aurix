/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRMNGSERVO                                             */
/* !Description     : THRMNGSERVO Component                                   */
/*                                                                            */
/* !Module          : THRMNGSERVO                                             */
/* !Description     : Gestion de l’asservissement du papillon motorise        */
/*                                                                            */
/* !File            : THRMNGSERVO_FCT3.C                                      */
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
/*   1 / THRMNGSERVO_vidTreatHighThSearch                                     */
/*   2 / THRMNGSERVO_vidTreatClosingRamp                                      */
/*   3 / THRMNGSERVO_vidTreatExitLowThrus                                     */
/*   4 / THRMNGSERVO_vidTreatLimpHome                                         */
/*   5 / THRMNGSERVO_vidDownThrustEnable                                      */
/*   6 / THRMNGSERVO_vidThrIniAftsStopLrn                                     */
/*   7 / THRMNGSERVO_vidEndThrLrn                                             */
/*   8 / THRMNGSERVO_vidForceLrnRst                                           */
/*   9 / THRMNGSERVO_vidThrIniAftsStopCln                                     */
/*   10 / THRMNGSERVO_vidFClnReset                                            */
/*                                                                            */
/* !Reference   : V02 NT 08 04528 / 16                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRMNGSERVO/THRMNGSERVO_FCT3$*/
/* $Revision::   1.5      $$Author::   etsasson       $$Date::   20 Sep 2012 $*/
/* $Author::   etsasson                               $$Date::   20 Sep 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "THRMNGSERVO.h"
#include "THRMNGSERVO_L.h"
#include "THRMNGSERVO_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidTreatHighThSearch                           */
/* !Description :  During de l'etat TPAC_HIGH_THRUST_SEARCH                   */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Tpac_thrust_search_tempo;                                    */
/*  output uint16 Tpac_thrust_search_tempo;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidTreatHighThSearch(void)
{
   if (Tpac_thrust_search_tempo > 0)
   {
      Tpac_thrust_search_tempo = (uint16)(Tpac_thrust_search_tempo - 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidTreatClosingRamp                            */
/* !Description :  During de l'etat TPAC_CLOSING_RAMP                         */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Tpac_thrust_search_tempo;                                    */
/*  output uint16 Tpac_thrust_search_tempo;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidTreatClosingRamp(void)
{
   if (Tpac_thrust_search_tempo > 0)
   {
      Tpac_thrust_search_tempo = (uint16)(Tpac_thrust_search_tempo - 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidTreatExitLowThrus                           */
/* !Description :  During de l'etat TPAC_EXIT_LOW_THRUST                      */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Tpac_thrust_search_tempo;                                    */
/*  output uint16 Tpac_thrust_search_tempo;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidTreatExitLowThrus(void)
{
   if (Tpac_thrust_search_tempo > 0)
   {
      Tpac_thrust_search_tempo = (uint16)(Tpac_thrust_search_tempo - 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidTreatLimpHome                               */
/* !Description :  During de l'etat TPAC_LIMP_HOME                            */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Tpac_store_limp_home_tempo;                                  */
/*  output uint16 Tpac_store_limp_home_tempo;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidTreatLimpHome(void)
{
   if (Tpac_store_limp_home_tempo > 0)
   {
      Tpac_store_limp_home_tempo = (uint16)(Tpac_store_limp_home_tempo - 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidDownThrustEnable                            */
/* !Description :  Le booleen Tpac_thrusts_enable passe à OFF lorsqu’un       */
/*                 apprentissage des butées a été réalisé avec succès         */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Tpac_thrusts_enable;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidDownThrustEnable(void)
{
   VEMS_vidSET(Tpac_thrusts_enable, 0);
   /* Msg(2:4700) Metric value out of threshold range:
   THRMNGSERVO_vidDownThrustEnable() : STAV1 = 9 : Average Statement Size
   exceeds 8 but we can’t modify the function while process requires one
   function by block */
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidThrIniAftsStopLrn                           */
/* !Description :  Un service APV permet de placer la fonction dans le même   */
/*                 état qu’au premier Key-on                                  */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Thr_bRstStopsLrnReq;                                       */
/*  output boolean Tpac_thrusts_enable;                                       */
/*  output boolean Tpac_FCln_enable;                                          */
/*  output uint8 Tpac_thrusts_powerlatch_counter;                             */
/*  output uint8 Tpac_FCln_powerlatch_counter;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidThrIniAftsStopLrn(void)
{
   VEMS_vidSET(Thr_bRstStopsLrnReq, 1);
   VEMS_vidSET(Tpac_thrusts_enable, 0);
   VEMS_vidSET(Tpac_FCln_enable, 0);
   Tpac_thrusts_powerlatch_counter = 0;
   Tpac_FCln_powerlatch_counter = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidEndThrLrn                                   */
/* !Description :  En cas de détection d’une dérive de position Limp Home, il */
/*                 est possible de forcer un apprentissage des butées basses  */
/*                 au prochain power-latch.                                   */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Thr_FLrn_bAcv_PwrOn;                                        */
/*  input boolean Thr_bStopsLrnInProgs;                                       */
/*  input boolean Thr_bAcvThrLrnKeyOn_drf_C;                                  */
/*  output boolean Tpac_thrusts_enable;                                       */
/*  output uint8 Tpac_thrusts_powerlatch_counter;                             */
/*  output boolean Thr_bRstStopsLrnReq;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidEndThrLrn(void)
{
   boolean bLocalThr_bStopsLrnInProgs;
   boolean bLocalThr_FLrn_bAcv_PwrOn;


   VEMS_vidGET(Thr_FLrn_bAcv_PwrOn, bLocalThr_FLrn_bAcv_PwrOn);
   VEMS_vidGET(Thr_bStopsLrnInProgs, bLocalThr_bStopsLrnInProgs);
   if (  (bLocalThr_FLrn_bAcv_PwrOn != 0)
      && (Thr_bAcvThrLrnKeyOn_drf_C == 0))
   {
      VEMS_vidSET(Tpac_thrusts_enable, 1);
      Tpac_thrusts_powerlatch_counter = 0;
   }
   if (  (bLocalThr_FLrn_bAcv_PwrOn != 0)
      && (Thr_bAcvThrLrnKeyOn_drf_C != 0))
   {
      VEMS_vidSET(Thr_bRstStopsLrnReq, 1);
   }
   else
   {
      if (bLocalThr_bStopsLrnInProgs != 0)
      {
         VEMS_vidSET(Thr_bRstStopsLrnReq, 0);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidForceLrnRst                                 */
/* !Description :  En cas de détection d’une dérive de position Limp Home ou  */
/*                 en cas de défaillance système, il est possible de forcer un*/
/*                 apprentissage des butées basses au prochain Reset.         */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  output boolean Thr_bRstStopsLrnReq;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidForceLrnRst(void)
{
   boolean bLocalAcvThrLrnKeyOn;
   uint8   u8LocalTpac_throttle_control_st;


   bLocalAcvThrLrnKeyOn = GDGAR_bGetFRM(FRM_FRM_ACVTHRLRNKEYON);
   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpac_throttle_control_st);
   if (  (u8LocalTpac_throttle_control_st == TPAC_LIMP_HOME)
      && (bLocalAcvThrLrnKeyOn != 0))

   {
      VEMS_vidSET(Thr_bRstStopsLrnReq, 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidThrIniAftsStopCln                           */
/* !Description :  Commande de l'initialisation de                            */
/*                 Tpac_FCln_powerlatch_counter et Tpac_FCln_enable à la fin  */
/*                 de du cycle de nettoyage.                                  */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRMNGSERVO_vidFClnReset();                              */
/*  input boolean Thr_bFClnInProgs;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidThrIniAftsStopCln(void)
{
   boolean bLocalThr_bFClnInProgs;


   VEMS_vidGET(Thr_bFClnInProgs, bLocalThr_bFClnInProgs);
   if( bLocalThr_bFClnInProgs != 0)
   {
      THRMNGSERVO_vidFClnReset();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidFClnReset                                   */
/* !Description :  A la fin du cycle de nettoyage, le booléen d’activation de */
/*                 cette fonction ainsi que le compteur de cycles de roulage  */
/*                 sont remis à zéro.                                         */
/* !Number      :  FCT3.10                                                    */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Tpac_FCln_powerlatch_counter;                                */
/*  output boolean Tpac_FCln_enable;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidFClnReset(void)
{
   Tpac_FCln_powerlatch_counter = 0;
   VEMS_vidSET(Tpac_FCln_enable, 0);
}
/*------------------------------- end of file --------------------------------*/