/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CKMNGIF                                                 */
/* !Description     : CKMNGIF component.                                      */
/*                                                                            */
/* !Module          : CKMNGIF                                                 */
/* !Description     : Interface Gestion Roue Dentée Vilebrequin.              */
/*                                                                            */
/* !File            : CKMNGIF_FCT1.C                                          */
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
/*   1 / CKMNGIF_vidInitOutput                                                */
/*   2 / CKMNGIF_vidRunToStall                                                */
/*   3 / CKMNGIF_vidStallToRun                                                */
/*   4 / CKMNGIF_vidEngineRotDetection                                        */
/*   5 / CKMNGIF_vidEngineRotNoDetection                                      */
/*   6 / CKMNGIF_vidAcqui_duree_dent                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_6884590 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#069167                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNC/CKMNGIF/CkMngIf_fct1.c_v     $*/
/* $Revision::   1.21     $$Author::   wbouach        $$Date::   31 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   31 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "CKMNGIF.h"
#include "CKMNGIF_L.h"
#include "CKMNGIF_IM.h"
#include "GDGAR.h"
#include "VEMS.h"
#include "MATHSRV.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidInitOutput                                      */
/* !Description :  La recherche de la singularité de la roue dentée par le    */
/*                 composant LDB CRKHAL doit être activée au reset            */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_04457_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_noCylEng;                                                 */
/*  output boolean Moteur_tournant;                                           */
/*  output uint16 Duree_dent;                                                 */
/*  output uint16 Periode_moteur;                                             */
/*  output uint16 Compteur_de_pmh;                                            */
/*  output sint16 Ext_aEng;                                                   */
/*  output sint8 Engine_speed_derivate;                                       */
/*  output uint16 Periode_moteur_calc;                                        */
/*  output uint8 Ext_tiTDC;                                                   */
/*  output uint16 Ext_agCkPosnCurRef2;                                        */
/*  output uint8 Eng_noExCyl;                                                 */
/*  output uint8 Eng_noExNxtCyl;                                              */
/*  output uint16 Periode_moteur_hold;                                        */
/*  output uint16 Ext_tiHldPerEng;                                            */
/*  output uint8 Eng_noCmbCyl;                                                */
/*  output uint8 Eng_noCmbNxtCyl;                                             */
/*  output uint8 Eng_noCmprCyl;                                               */
/*  output uint8 Eng_noCmprNxtCyl;                                            */
/*  output uint16 Regime_moteur_filtre;                                       */
/*  output uint16 Regime_moteur;                                              */
/*  output uint8 Regime_moteur_32;                                            */
/*  output uint16 Regime_moteur_0_125;                                        */
/*  output uint8 Ext_ctTDC;                                                   */
/*  output uint16 Periode_moteur_calc_prev;                                   */
/*  output uint16 Ext_nEng;                                                   */
/*  output uint16 Ext_nEngFineResl;                                           */
/*  output uint16 Ext_ctInj;                                                  */
/*  output uint16 Sync_agCkPosnRef1;                                          */
/*  output boolean Sync_bRotDetEng;                                           */
/*  output uint16 Ext_nEngBDC;                                                */
/*  output uint16 Ext_nEngTDC;                                                */
/*  output uint32 CKMNGIF_u32FiltredEngSpdMem;                                */
/*  output uint16 CKMNGIF_u16RegimeMoteurPrev[3];                             */
/*  output uint16 Offset_reperes_ang;                                         */
/*  output uint16 Periode_angulaire;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidInitOutput(void)
{
   uint8  u8LocalExt_noCylEng;
   uint8  u8LocalIndex;
   uint16 u16LocalOffset_reperes_ang;
   uint16 u16LocalPeriode_angulaire;


   VEMS_vidSET(Moteur_tournant, 0);
   VEMS_vidSET(Duree_dent, 0);
   VEMS_vidSET(Periode_moteur, 0);
   VEMS_vidSET(Compteur_de_pmh, 0);
   VEMS_vidSET(Ext_aEng, 0);
   VEMS_vidSET(Engine_speed_derivate, 0);
   Periode_moteur_calc = 0;
   VEMS_vidSET(Ext_tiTDC, 0);
   VEMS_vidSET(Ext_agCkPosnCurRef2, 0);
   VEMS_vidSET(Eng_noExCyl, 1);
   VEMS_vidSET(Eng_noExNxtCyl, 1);
   VEMS_vidSET(Periode_moteur_hold, 0);
   VEMS_vidSET(Ext_tiHldPerEng, 0);
   VEMS_vidSET(Eng_noCmbCyl, 1);
   VEMS_vidSET(Eng_noCmbNxtCyl, 1);
   VEMS_vidSET(Eng_noCmprCyl, 1);
   VEMS_vidSET(Eng_noCmprNxtCyl, 1);
   VEMS_vidSET(Regime_moteur_filtre, 0);
   VEMS_vidSET(Regime_moteur, 0);
   VEMS_vidSET(Regime_moteur_32, 0);
   VEMS_vidSET(Regime_moteur_0_125, 0);
   VEMS_vidSET(Ext_ctTDC, 0);
   Periode_moteur_calc_prev = 0;
   VEMS_vidSET(Ext_nEng, 0);
   VEMS_vidSET(Ext_nEngFineResl, 0);
   VEMS_vidSET(Ext_ctInj, 0);
   VEMS_vidSET(Sync_agCkPosnRef1 ,0);
   VEMS_vidSET(Sync_bRotDetEng, 0);
   VEMS_vidSET(Ext_nEngBDC, 0);
   VEMS_vidSET(Ext_nEngTDC, 0);
   CKMNGIF_u32FiltredEngSpdMem = 8388608; /* 256 * 32768 */

   for (u8LocalIndex = 0; u8LocalIndex < NB_INJ_SPD_PREV; u8LocalIndex++)
   {
      CKMNGIF_u16RegimeMoteurPrev[u8LocalIndex] = 0;
   }

   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
   if (u8LocalExt_noCylEng != 0)
   {
      u16LocalPeriode_angulaire = (uint16)(720 / u8LocalExt_noCylEng);
   }
   else
   {
      u16LocalPeriode_angulaire = 720;
   }
   u16LocalOffset_reperes_ang = (uint16)(720 - u16LocalPeriode_angulaire);
   VEMS_vidSET(Offset_reperes_ang , u16LocalOffset_reperes_ang);
   VEMS_vidSET(Periode_angulaire, u16LocalPeriode_angulaire);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidRunToStall                                      */
/* !Description :  Initialisation des sorties sur passage de l'etat tournant  */
/*                 cale                                                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Moteur_tournant;                                           */
/*  output uint16 Periode_moteur;                                             */
/*  output uint8 Ext_tiTDC;                                                   */
/*  output uint16 Periode_moteur_calc;                                        */
/*  output uint16 Regime_moteur;                                              */
/*  output uint8 Regime_moteur_32;                                            */
/*  output uint16 Regime_moteur_0_125;                                        */
/*  output uint16 Periode_moteur_calc_prev;                                   */
/*  output uint16 Ext_nEng;                                                   */
/*  output uint16 Ext_nEngFineResl;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidRunToStall(void)
{
   VEMS_vidSET(Moteur_tournant, 0);
   VEMS_vidSET(Periode_moteur, 65535);
   VEMS_vidSET(Ext_tiTDC, 100);
   Periode_moteur_calc = 65535;
   VEMS_vidSET(Regime_moteur, 0);
   VEMS_vidSET(Regime_moteur_32, 0);
   VEMS_vidSET(Regime_moteur_0_125, 0);
   Periode_moteur_calc_prev = 0;
   VEMS_vidSET(Ext_nEng, 0);
   VEMS_vidSET(Ext_nEngFineResl, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidStallToRun                                      */
/* !Description :  Initialisation des sorties sur passage de l'etat cale      */
/*                 tournant                                                   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Moteur_tournant;                                           */
/*  output uint16 Compteur_de_pmh;                                            */
/*  output uint8 Ext_ctTDC;                                                   */
/*  output uint16 Ext_ctInj;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidStallToRun(void)
{
   VEMS_vidSET(Moteur_tournant, 1);
   VEMS_vidSET(Compteur_de_pmh, 0);
   VEMS_vidSET(Ext_ctTDC, 0);
   VEMS_vidSET(Ext_ctInj, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidEngineRotDetection                              */
/* !Description :  Mettre la variable Sync_bRotDetEng à 1                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Sync_bRotDetEng;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidEngineRotDetection(void)
{
   VEMS_vidSET(Sync_bRotDetEng, 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidEngineRotNoDetection                            */
/* !Description :  Mettre la variable Sync_bRotDetEng à 0                     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Sync_bRotDetEng;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidEngineRotNoDetection(void)
{
   VEMS_vidSET(Sync_bRotDetEng, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidAcqui_duree_dent                                */
/* !Description :  La durée dent est utilisée pour le calcul des angles de    */
/*                 phasage des injections. Elle est calculée sur événement    */
/*                 PMH, moteur  calé vers moteur tournant ou sur moteur       */
/*                 synchro.                                                   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Acqui_duree_dent;                                            */
/*  output uint16 Duree_dent;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidAcqui_duree_dent(void)
{
   uint16 u16LocalDuree_dent;
   uint32 u32LocalAcqui_duree_dent;


   VEMS_vidGET(Acqui_duree_dent, u32LocalAcqui_duree_dent);
   u32LocalAcqui_duree_dent = u32LocalAcqui_duree_dent / 32;
   u16LocalDuree_dent = (uint16)MATHSRV_udtMIN(u32LocalAcqui_duree_dent, 65535);
   VEMS_vidSET(Duree_dent, u16LocalDuree_dent);
}

/*------------------------------- end of file --------------------------------*/