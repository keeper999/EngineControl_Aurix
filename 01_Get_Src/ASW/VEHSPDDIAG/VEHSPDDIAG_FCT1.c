/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VEHSPDDIAG                                              */
/* !Description     : VEHSPDDIAG component                                    */
/*                                                                            */
/* !Module          : VEHSPDDIAG                                              */
/* !Description     : DIAGNOSTIC FONCTIONNEL DE LA VITESSE VEHICULE           */
/*                                                                            */
/* !File            : VEHSPDDIAG_FCT1.C                                       */
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
/*   1 / VEHSPDDIAG_vidInit                                                   */
/*   2 / VEHSPDDIAG_vidConsistency_Test                                       */
/*   3 / VEHSPDDIAG_vidRunDiag                                                */
/*   4 / VEHSPDDIAG_vidCheckStabilityCond                                     */
/*   5 / VEHSPDDIAG_vidActivateDiag                                           */
/*   6 / VEHSPDDIAG_vidConsistDetectActiv                                     */
/*   7 / VEHSPDDIAG_vidMaxValueTested                                         */
/*   8 / VEHSPDDIAG_vidMaxValDetectActiv                                      */
/*   9 / VEHSPDDIAG_vidSafetyLev2                                             */
/*                                                                            */
/* !Reference   : V02 NT 09 01664 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VEHSPDDIAG/VEHSPDDIAG_FCT1.C_v  $*/
/* $Revision::   1.0      $$Author::   PBAKABAD       $$Date::   04 Oct 2011 $*/
/* $Author::   PBAKABAD                               $$Date::   04 Oct 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VEHSPDDIAG.h"
#include "VEHSPDDIAG_L.h"
#include "VEHSPDDIAG_IM.h"
#include "LIBSFTYLVL2.h"
#include "GDGAR.H"
#include "VEMS.H"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDDIAG_vidInit                                         */
/* !Description :  Au reset, on initialise les compteurs de points de mesures */
/*                 sur les conditions de stabilités du régime et de la charge.*/
/* !Number      :  FCT1.1                                                     */
/* !Author      :  GHADDAB                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean VehSpd_bCnd1Coh_spdVeh;                                    */
/*  output boolean VehSpd_bCnd2Coh_spdVeh;                                    */
/*  output boolean VehSpd_bDgoCoh_spdVeh;                                     */
/*  output boolean VehSpd_bMonRunCoh_spdVeh;                                  */
/*  output uint8 VehSpd_ctEngSpdMesPoint;                                     */
/*  output uint8 VehSpd_ctIdcReqMesPoint;                                     */
/*  output uint16 VEHSPDDIAG_Regime_moteurPrev;                               */
/*  output sint16 VEHSPDDIAG_TqSys_tqIdcReqPrev;                              */
/*  output boolean VehSpd_bMonRunORng_spdVeh;                                 */
/*  output boolean VehSpd_bDgoORng_spdVeh;                                    */
/*  output uint8 VehSpd_ctDftSftyORng_spdVeh;                                 */
/*  output uint8 VEHSPDDIAG_u8CntFilt_1;                                      */
/*  output boolean VehSpd_bDftSftyORng_spdVeh;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDDIAG_vidInit(void)
{
   VehSpd_bCnd1Coh_spdVeh = 0;
   VehSpd_bCnd2Coh_spdVeh = 0;
   VehSpd_bDgoCoh_spdVeh = 0;
   VehSpd_bMonRunCoh_spdVeh = 0;
   VehSpd_ctEngSpdMesPoint = 0;
   VehSpd_ctIdcReqMesPoint = 0;
   VEHSPDDIAG_Regime_moteurPrev = 0;
   VEHSPDDIAG_TqSys_tqIdcReqPrev = 0;
   VehSpd_bMonRunORng_spdVeh = 0;
   VehSpd_bDgoORng_spdVeh = 0;
   VehSpd_ctDftSftyORng_spdVeh = 0;
   VEHSPDDIAG_u8CntFilt_1 = 0;
   VEMS_vidSET(VehSpd_bDftSftyORng_spdVeh, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDDIAG_vidConsistency_Test                             */
/* !Description :  Le diagnostic de cohérence peut être inhibé manuellement si*/
/*                 VehSpd_bInhMonVehSpd_C = 1.                                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  GHADDAB                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHSPDDIAG_vidRunDiag();                                 */
/*  input boolean VehSpd_bInhMonVehSpd_C;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDDIAG_vidConsistency_Test(void)
{
   if (VehSpd_bInhMonVehSpd_C == 0)
   {
      VEHSPDDIAG_vidRunDiag();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDDIAG_vidRunDiag                                      */
/* !Description :  Le diagnostic du capteur de vitesse est activé si les      */
/*                 conditions de stabilité du régime dans une zone spécifique */
/*                 et celles de la charge dans une zone spécifique sont       */
/*                 remplies. Il sera inhibé par une demande spécifique du GAR */
/*                 via FRM_bInhMonVehSpd.                                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  GHADDAB                                                    */
/* !Trace_To    :  VEMS_R_09_01664_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHSPDDIAG_vidCheckStabilityCond();                      */
/*  extf argret void VEHSPDDIAG_vidActivateDiag();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDDIAG_vidRunDiag(void)
{
   VEHSPDDIAG_vidCheckStabilityCond();
   VEHSPDDIAG_vidActivateDiag();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDDIAG_vidCheckStabilityCond                           */
/* !Description :  Vérifie les conditions de stabilité du régime véhicule et  */
/*                 celles la stabilité de la charge.                          */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  GHADDAB                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 VEHSPDDIAG_Regime_moteurPrev;                                */
/*  input uint16 VehSpd_nEngThdMax_C;                                         */
/*  input uint16 VehSpd_nEngThdMin_C;                                         */
/*  input uint16 VehSpd_nEngThdGrd_C;                                         */
/*  input uint8 VehSpd_ctEngSpdMesPoint;                                      */
/*  input uint8 VehSpd_noEngSpdMaxMesPoint_C;                                 */
/*  input sint16 TqSys_tqIdcReq;                                              */
/*  input sint16 VEHSPDDIAG_TqSys_tqIdcReqPrev;                               */
/*  input uint16 VehSpd_tqIdcReqThdMax_C;                                     */
/*  input uint16 VehSpd_tqIdcReqThdMin_C;                                     */
/*  input uint16 VehSpd_tqIdcReqGrd_C;                                        */
/*  input uint8 VehSpd_ctIdcReqMesPoint;                                      */
/*  input uint8 VehSpd_noIdcReqMaxMesPoint_C;                                 */
/*  output uint8 VehSpd_ctEngSpdMesPoint;                                     */
/*  output uint8 VehSpd_ctIdcReqMesPoint;                                     */
/*  output boolean VehSpd_bCnd1Coh_spdVeh;                                    */
/*  output boolean VehSpd_bCnd2Coh_spdVeh;                                    */
/*  output uint16 VEHSPDDIAG_Regime_moteurPrev;                               */
/*  output sint16 VEHSPDDIAG_TqSys_tqIdcReqPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDDIAG_vidCheckStabilityCond(void)
{
   uint8  u8LocalCounter;
   sint16 s16LocalTqSys_tqIdcReq;
   uint16 u16LocalAbsValue;
   uint16 u16LocalRegime_moteur;


   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   u16LocalAbsValue = (uint16)MATHSRV_udtABS( u16LocalRegime_moteur
                                            - VEHSPDDIAG_Regime_moteurPrev);
   if (  (u16LocalRegime_moteur < VehSpd_nEngThdMax_C)
      && (u16LocalRegime_moteur > VehSpd_nEngThdMin_C)
      && (u16LocalAbsValue < VehSpd_nEngThdGrd_C))
   {
      if (VehSpd_ctEngSpdMesPoint < 255)
      {
         u8LocalCounter = (uint8)(VehSpd_ctEngSpdMesPoint + 1);
      }
      else
      {
         u8LocalCounter = 255;
      }
      VehSpd_ctEngSpdMesPoint = (uint8)MATHSRV_udtMIN(
                                       u8LocalCounter,
                                       VehSpd_noEngSpdMaxMesPoint_C);
   }
   else
   {
      VehSpd_ctEngSpdMesPoint = 0;
   }

   VEMS_vidGET(TqSys_tqIdcReq, s16LocalTqSys_tqIdcReq);
   u16LocalAbsValue = (uint16)MATHSRV_udtABS( s16LocalTqSys_tqIdcReq
                                            - VEHSPDDIAG_TqSys_tqIdcReqPrev);
   if (  (s16LocalTqSys_tqIdcReq < (16 * VehSpd_tqIdcReqThdMax_C))
      && (s16LocalTqSys_tqIdcReq > (16 * VehSpd_tqIdcReqThdMin_C))
      && ( u16LocalAbsValue < (16 * VehSpd_tqIdcReqGrd_C)))
   {
      if (VehSpd_ctIdcReqMesPoint < 255)
      {
         u8LocalCounter = (uint8)(VehSpd_ctIdcReqMesPoint + 1);
      }
      else
      {
         u8LocalCounter = 255;
      }
      VehSpd_ctIdcReqMesPoint = (uint8)MATHSRV_udtMIN(
                                       u8LocalCounter,
                                       VehSpd_noIdcReqMaxMesPoint_C);
   }
   else
   {
      VehSpd_ctIdcReqMesPoint = 0;
   }

   if (VehSpd_ctEngSpdMesPoint >= VehSpd_noEngSpdMaxMesPoint_C)
   {
      VehSpd_bCnd1Coh_spdVeh = 1;
   }
   else
   {
      VehSpd_bCnd1Coh_spdVeh = 0;
   }

   if (VehSpd_ctIdcReqMesPoint >= VehSpd_noIdcReqMaxMesPoint_C)
   {
      VehSpd_bCnd2Coh_spdVeh = 1;
   }
   else
   {
      VehSpd_bCnd2Coh_spdVeh = 0;
   }

   VEHSPDDIAG_Regime_moteurPrev = u16LocalRegime_moteur;
   VEHSPDDIAG_TqSys_tqIdcReqPrev = s16LocalTqSys_tqIdcReq;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDDIAG_vidActivateDiag                                 */
/* !Description :  Gère l'activation et l'inhibition du diagnostic du capteur */
/*                 de vitesse véhicule.                                       */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  GHADDAB                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void VEHSPDDIAG_vidConsistDetectActiv();                      */
/*  input boolean VehSpd_bCnd1Coh_spdVeh;                                     */
/*  input boolean VehSpd_bCnd2Coh_spdVeh;                                     */
/*  output boolean VehSpd_bMonRunCoh_spdVeh;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDDIAG_vidActivateDiag(void)
{
   boolean bLocalInhMonVehSpd;


   bLocalInhMonVehSpd = GDGAR_bGetFRM(FRM_FRM_INHMONVEHSPD);
   if (  (bLocalInhMonVehSpd == 0)
      && (VehSpd_bCnd1Coh_spdVeh != 0)
      && (VehSpd_bCnd2Coh_spdVeh != 0))
   {
      VehSpd_bMonRunCoh_spdVeh = 1;
      VEHSPDDIAG_vidConsistDetectActiv();
   }
   else
   {
      VehSpd_bMonRunCoh_spdVeh = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDDIAG_vidConsistDetectActiv                           */
/* !Description :  La détection du défaut revient à tester si la vitesse est  */
/*                 insuffisante par rapport aux conditions de fonctionnement  */
/*                 moteur.                                                    */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  GHADDAB                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input uint8 VehSpd_spdThdDiagCoh_C;                                       */
/*  output boolean VehSpd_bDgoCoh_spdVeh;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDDIAG_vidConsistDetectActiv(void)
{
   uint8  u8LocalVitesse_vehicule;


   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);
   if (u8LocalVitesse_vehicule < VehSpd_spdThdDiagCoh_C)
   {
      VehSpd_bDgoCoh_spdVeh = 1;
   }
   else
   {
      VehSpd_bDgoCoh_spdVeh = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDDIAG_vidMaxValueTested                               */
/* !Description :  Le diagnostic du capteur de vitesse véhicule est activé si */
/*                 : -  Auncune demande d’inhibition provenant du GAR  -  Pas */
/*                 d’inhibition manuelle                                      */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  GHADDAB                                                    */
/* !Trace_To    :  VEMS_R_09_01664_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void VEHSPDDIAG_vidMaxValDetectActiv();                       */
/*  input boolean VehSpd_bInhMonVehSpd_C;                                     */
/*  output boolean VehSpd_bMonRunORng_spdVeh;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDDIAG_vidMaxValueTested(void)
{
   boolean bLocalInhMonVehSpd;


   bLocalInhMonVehSpd = GDGAR_bGetFRM(FRM_FRM_INHMONVEHSPD);
   if (  (bLocalInhMonVehSpd == 0)
      && (VehSpd_bInhMonVehSpd_C == 0)
      )
   {
      VehSpd_bMonRunORng_spdVeh = 1;
      VEHSPDDIAG_vidMaxValDetectActiv();
   }
   else
   {
      VehSpd_bMonRunORng_spdVeh = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDDIAG_vidMaxValDetectActiv                            */
/* !Description :  La détection du défaut revient à tester si la vitesse est  */
/*                 supérieur à un seuil calibrable.                           */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  GHADDAB                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input uint16 VehSpd_spdVehThdMax_C;                                       */
/*  output boolean VehSpd_bDgoORng_spdVeh;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDDIAG_vidMaxValDetectActiv(void)
{
   uint8  u8LocalVitesse_vehicule;


   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);
   if (u8LocalVitesse_vehicule > VehSpd_spdVehThdMax_C)
   {
      VehSpd_bDgoORng_spdVeh = 1;
   }
   else
   {
      VehSpd_bDgoORng_spdVeh = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDDIAG_vidSafetyLev2                                   */
/* !Description :   Le but de cette stratégie est de sécuriser l’entrée de    */
/*                 mesure (vitesse véhicule) via une stratégie de niveau 2    */
/*                 afin de se prémunir contre les fautes latentes. Cette      */
/*                 stratégie est appliquée sur le Test avec un seuil max de   */
/*                 vitesse véhicule.                                          */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  GHADDAB                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean VehSpd_bDgoORng_spdVeh;                                     */
/*  input uint8 VehSpd_nUpTranThd_SpdVeh_C;                                   */
/*  input uint8 VehSpd_nDownTranThd_SpdVeh_C;                                 */
/*  input uint8 VehSpd_nInitCptConf_SpdVeh_C;                                 */
/*  input uint8 VehSpd_nDecCpt_SpdVeh_C;                                      */
/*  input uint8 VEHSPDDIAG_u8CntFilt_1;                                       */
/*  input boolean VEHSPDDIAG_bFilSig_1;                                       */
/*  input uint8 VehSpd_ctDftSftyORng_spdVeh;                                  */
/*  input boolean VEHSPDDIAG_bORng_spdVeh;                                    */
/*  output boolean VehSpd_bDftSftyORng_spdVeh;                                */
/*  output boolean VEHSPDDIAG_bORng_spdVeh;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDDIAG_vidSafetyLev2(void)
{
   LIBSFTYLVL2_U8_Safety_Level2(VehSpd_bDgoORng_spdVeh,
                                VehSpd_nUpTranThd_SpdVeh_C,
                                VehSpd_nDownTranThd_SpdVeh_C,
                                VehSpd_nInitCptConf_SpdVeh_C,
                                VehSpd_nDecCpt_SpdVeh_C,
                                &VEHSPDDIAG_u8CntFilt_1,
                                &VEHSPDDIAG_bFilSig_1,
                                &VehSpd_ctDftSftyORng_spdVeh,
                                &VEHSPDDIAG_bORng_spdVeh);
   VEMS_vidSET(VehSpd_bDftSftyORng_spdVeh, VEHSPDDIAG_bORng_spdVeh);
}
/*--------------------------- end of file ----------------------------------*/