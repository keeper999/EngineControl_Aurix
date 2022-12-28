/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ENGSTRTSTOP                                             */
/* !Description     : ENGSTRTSTOP Component                                   */
/*                                                                            */
/* !Module          : ENGSTRTSTOP                                             */
/* !Description     : DEMARRAGE ET ARRET MOTEUR                               */
/*                                                                            */
/* !File            : ENGSTRTSTOP_FCT2.C                                      */
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
/*   1 / ENGSTRTSTOP_vidTransEngine                                           */
/*   2 / ENGSTRTSTOP_vidKeyOffOn                                              */
/*   3 / ENGSTRTSTOP_vidTransToCranking                                       */
/*   4 / ENGSTRTSTOP_vidComputeCrankRetry                                     */
/*   5 / ENGSTRTSTOP_vidStallRunning                                          */
/*   6 / ENGSTRTSTOP_vidFirstCrank                                            */
/*   7 / ENGSTRTSTOP_vidMajFirstCrank                                         */
/*   8 / ENGSTRTSTOP_vidKeyOnOff                                              */
/*   9 / ENGSTRTSTOP_vidEnaTransitToCrank                                     */
/*   10 / ENGSTRTSTOP_vidMemrTransStEng                                       */
/*                                                                            */
/* !Reference   : V02 NT 08 05182 / 14                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ENGSTRTSTOP/ENGSTRTSTOP_FCT2.c_v  $*/
/* $Revision::   1.13     $$Author::   achebino       $$Date::   24 Aug 2012 $*/
/* $Author::   achebino                               $$Date::   24 Aug 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ENGSTRTSTOP.h"
#include "ENGSTRTSTOP_L.h"
#include "ENGSTRTSTOP_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTRTSTOP_vidTransEngine                                 */
/* !Description :  Fonction qui permet de redémarrer le moteur.               */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Cranking_retry;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTRTSTOP_vidTransEngine(void)
{
   VEMS_vidSET(Cranking_retry, 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTRTSTOP_vidKeyOffOn                                    */
/* !Description :  Fonction qui indique le calage du moteur.                  */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Clef_off_on_sans_dem;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTRTSTOP_vidKeyOffOn(void)
{
   VEMS_vidSET(Clef_off_on_sans_dem,1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTRTSTOP_vidTransToCranking                             */
/* !Description :  Fonction qui permet de tourner le moteur.                  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_05182_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ENGSTRTSTOP_vidMemrTransStEng();                         */
/*  extf argret void ENGSTRTSTOP_vidEnaTransitToCrank();                      */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 ENGSTRTSTOP_u8CoPTStstEngPrev;                                */
/*  input uint16 GOBD_nObdStrtThd_C;                                          */
/*  input boolean EngSt_bMemrTrans_stEng;                                     */
/*  output uint8 ENGSTRTSTOP_u8CoPTStstEngPrev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTRTSTOP_vidTransToCranking(void)
{
   uint8  u8LocalCoPTSt_stEng;
   uint16 u16LocalRegime_moteur;

   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);

   if (  (u8LocalCoPTSt_stEng == Engine_Running)
      && (ENGSTRTSTOP_u8CoPTStstEngPrev != Engine_Running))
   {
      ENGSTRTSTOP_vidMemrTransStEng();
   }
   if (  (u16LocalRegime_moteur > GOBD_nObdStrtThd_C)
      && (EngSt_bMemrTrans_stEng != 0))
   {
      ENGSTRTSTOP_vidEnaTransitToCrank();
   }
   ENGSTRTSTOP_u8CoPTStstEngPrev =
      (uint8)MATHSRV_udtCLAMP(u8LocalCoPTSt_stEng,1,15);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTRTSTOP_vidComputeCrankRetry                           */
/* !Description :  Fonction qui indique le redémarrage (le moteur a déjà été  */
/*                 entraîné).                                                 */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Time_since_stall;                                            */
/*  input boolean Date_emf_available_mux;                                     */
/*  input boolean Moteur_tournant;                                            */
/*  input boolean Throttle_cranking_retry;                                    */
/*  input uint16 Date_emf_retry_thresh_delay;                                 */
/*  input boolean Manu_inh_retry_emf;                                         */
/*  output boolean Throttle_cranking_retry;                                   */
/*  output boolean Ext_bEngReStrt;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTRTSTOP_vidComputeCrankRetry(void)
{
   boolean bLocalDate_emf_available_mux;
   boolean bLocalMoteur_tournant;
   boolean bLocalThrottle_cranking_retry;
   uint32  u32LocalTime_since_stall;


   VEMS_vidGET(Time_since_stall,u32LocalTime_since_stall);
   VEMS_vidGET(Date_emf_available_mux,bLocalDate_emf_available_mux);
   VEMS_vidGET(Moteur_tournant,bLocalMoteur_tournant);
   VEMS_vidGET(Throttle_cranking_retry,bLocalThrottle_cranking_retry);

   if (u32LocalTime_since_stall >= Date_emf_retry_thresh_delay)
   {
      VEMS_vidSET(Throttle_cranking_retry, 0);
      VEMS_vidSET(Ext_bEngReStrt, 0);
   }
   else
   {
      if (  (bLocalDate_emf_available_mux != 0)
         && (bLocalMoteur_tournant == 0)
         && (bLocalThrottle_cranking_retry == 0)
         && (Manu_inh_retry_emf == 0))
      {
         VEMS_vidSET(Throttle_cranking_retry, 1);
         VEMS_vidSET(Ext_bEngReStrt, 1);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTRTSTOP_vidStallRunning                                */
/* !Description :  Fonction qui permet de passer à l'état running.            */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Throttle_cranking_retry;                                   */
/*  output boolean Ext_bEngReStrt;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTRTSTOP_vidStallRunning(void)
{
   VEMS_vidSET(Throttle_cranking_retry, 1);
   VEMS_vidSET(Ext_bEngReStrt, 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTRTSTOP_vidFirstCrank                                  */
/* !Description :  Fonction qui fait appel à ENGSTRTSTOP_vidMajFirstCrank.    */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ENGSTRTSTOP_vidMajFirstCrank();                          */
/*  input boolean First_crank;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTRTSTOP_vidFirstCrank(void)
{
   boolean bLocalFirst_crank;


   VEMS_vidGET(First_crank,bLocalFirst_crank);
   if (bLocalFirst_crank != 0)
   {
      ENGSTRTSTOP_vidMajFirstCrank();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTRTSTOP_vidMajFirstCrank                               */
/* !Description :  Fonction qui indique le tout premier démarrage sauvegardé  */
/*                 en eeprom.                                                 */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Fuel_pump_eng_speed_first_crank;                              */
/*  output boolean First_crank;                                               */
/*  output boolean Ext_bFirstStrt;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTRTSTOP_vidMajFirstCrank(void)
{
   uint8 u8LocalRegime_moteur_32;


   VEMS_vidGET(Regime_moteur_32,u8LocalRegime_moteur_32);
   if (u8LocalRegime_moteur_32 > Fuel_pump_eng_speed_first_crank)
   {
      VEMS_vidSET(First_crank,0);
      VEMS_vidSET(Ext_bFirstStrt,0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTRTSTOP_vidKeyOnOff                                    */
/* !Description :  Fonction qui indique le calage du moteur.                  */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Clef_off_on_sans_dem;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTRTSTOP_vidKeyOnOff(void)
{
   VEMS_vidSET(Clef_off_on_sans_dem, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTRTSTOP_vidEnaTransitToCrank                           */
/* !Description :  Fonction qui permet de tourner le moteur                   */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Clef_off_on_sans_dem;                                      */
/*  output boolean EngSt_bMemrTrans_stEng;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTRTSTOP_vidEnaTransitToCrank(void)
{
   VEMS_vidSET(Clef_off_on_sans_dem, 0);
   EngSt_bMemrTrans_stEng = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTRTSTOP_vidMemrTransStEng                              */
/* !Description :  fonction déterminant la valeur de mémorisation de la       */
/*                 transition de CoPTSt_stEng vers Engine_Running             */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean EngSt_bMemrTrans_stEng;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTRTSTOP_vidMemrTransStEng(void)
{
   EngSt_bMemrTrans_stEng = 1;
}
/*----------------------------- end of file ----------------------------------*/