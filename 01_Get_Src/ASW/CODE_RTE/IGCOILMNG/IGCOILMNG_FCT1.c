/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IGCOILMNG                                               */
/* !Description     : IGCOILMNG component.                                    */
/*                                                                            */
/* !Module          : IGCOILMNG                                               */
/* !Description     : COMMANDE ET DIAGNOSTIC DES BOBINES D’ALLUMAGE           */
/*                                                                            */
/* !File            : IGCOILMNG_FCT1.C                                        */
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
/*   1 / IGCOILMNG_vidInitOutput                                              */
/*   2 / IGCOILMNG_vidEnable                                                  */
/*   3 / IGCOILMNG_vidInitilization                                           */
/*   4 / IGCOILMNG_vidCalcIcdState                                            */
/*   5 / IGCOILMNG_vidCalcIcdRatioEnergy                                      */
/*   6 / IGCOILMNG_vidDiagCoil                                                */
/*   7 / IGCOILMNG_vidCalcDwellTime                                           */
/*   8 / IGCOILMNG_vidDwellTime                                               */
/*   9 / IGCOILMNG_vidIcdRatioEnergy                                          */
/*   10 / IGCOILMNG_vidAgIgMng                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_6668934 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/IGCOILMNG/IGCOILMNG_FCT1.C_v      $*/
/* $Revision::   1.18     $$Author::   achebino       $$Date::   02 Jul 2014 $*/
/* $Author::   achebino                               $$Date::   02 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IGCOILMNG.h"
#include "IGCOILMNG_L.h"
#include "IGCOILMNG_IM.h"
#include "DGOHAL.h"
#include "IGNHAL.h"
#include "SWFAIL.h"
#include "IGCOILMNG_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidInitOutput                                    */
/* !Description :  Initialisation of the output                               */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_bobine1;                                           */
/*  output boolean Dena_oc_bobine2;                                           */
/*  output boolean Dena_oc_bobine3;                                           */
/*  output boolean Dena_oc_bobine4;                                           */
/*  output boolean Dena_scg_bobine1;                                          */
/*  output boolean Dena_scg_bobine2;                                          */
/*  output boolean Dena_scg_bobine3;                                          */
/*  output boolean Dena_scg_bobine4;                                          */
/*  output boolean Dena_scp_bobine1;                                          */
/*  output boolean Dena_scp_bobine2;                                          */
/*  output boolean Dena_scp_bobine3;                                          */
/*  output boolean Dena_scp_bobine4;                                          */
/*  output boolean Dft_oc_bobine1;                                            */
/*  output boolean Dft_oc_bobine2;                                            */
/*  output boolean Dft_oc_bobine3;                                            */
/*  output boolean Dft_oc_bobine4;                                            */
/*  output boolean Dft_scg_bobine1;                                           */
/*  output boolean Dft_scg_bobine2;                                           */
/*  output boolean Dft_scg_bobine3;                                           */
/*  output boolean Dft_scg_bobine4;                                           */
/*  output boolean Dft_scp_bobine1;                                           */
/*  output boolean Dft_scp_bobine2;                                           */
/*  output boolean Dft_scp_bobine3;                                           */
/*  output boolean Dft_scp_bobine4;                                           */
/*  output boolean IGCOILMNG_bIGBTAcqOuthyst;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidInitOutput(void)
{
   VEMS_vidSET(Dena_oc_bobine1, 0);
   VEMS_vidSET(Dena_oc_bobine2, 0);
   VEMS_vidSET(Dena_oc_bobine3, 0);
   VEMS_vidSET(Dena_oc_bobine4, 0);
   VEMS_vidSET(Dena_scg_bobine1, 0);
   VEMS_vidSET(Dena_scg_bobine2, 0);
   VEMS_vidSET(Dena_scg_bobine3, 0);
   VEMS_vidSET(Dena_scg_bobine4, 0);
   VEMS_vidSET(Dena_scp_bobine1, 0);
   VEMS_vidSET(Dena_scp_bobine2, 0);
   VEMS_vidSET(Dena_scp_bobine3, 0);
   VEMS_vidSET(Dena_scp_bobine4, 0);
   VEMS_vidSET(Dft_oc_bobine1, 0);
   VEMS_vidSET(Dft_oc_bobine2, 0);
   VEMS_vidSET(Dft_oc_bobine3, 0);
   VEMS_vidSET(Dft_oc_bobine4, 0);
   VEMS_vidSET(Dft_scg_bobine1, 0);
   VEMS_vidSET(Dft_scg_bobine2, 0);
   VEMS_vidSET(Dft_scg_bobine3, 0);
   VEMS_vidSET(Dft_scg_bobine4, 0);
   VEMS_vidSET(Dft_scp_bobine1, 0);
   VEMS_vidSET(Dft_scp_bobine2, 0);
   VEMS_vidSET(Dft_scp_bobine3, 0);
   VEMS_vidSET(Dft_scp_bobine4, 0);
   IGCOILMNG_bIGBTAcqOuthyst = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidEnable                                        */
/* !Description :  Le driver allumage est activé sur validation de la         */
/*                 synchronisation précise et sur sens de rotation avant.     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_03142_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IgnHALEnable();                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidEnable(void)
{
   IgnHALEnable();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidInitilization                                 */
/* !Description :  Initialisation de l'automate de commande des bobines       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret uint8  IgnHALWriteMode(argin uint8 u8Mode);                   */
/*  output st24 Icd_state;                                                    */
/*  output uint8 Ign_mode_status;                                             */
/*  output uint8 Icd_ratio_energy;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidInitilization(void)
{
   VEMS_vidSET(Icd_state, IGNHAL_udtMODE_FIXED);

   Ign_mode_status = IgnHALWriteMode(IGNHAL_udtMODE_FIXED);

   VEMS_vidSET(Icd_ratio_energy, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidCalcIcdState                                  */
/* !Description :  Cet automate détermine le mode de fonctionnement des       */
/*                 bobines: Phase de démarrage ou normale où l’énergie        */
/*                 d’allumage nommée Icd_max_current_coils bénéficiera de     */
/*                 l’adaptation via le ratio nommé Icd_ratio_energy.          */
/*                 Initialement, l’énergie d’allumage sera fixe.              */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret uint8  IgnHALWriteMode(argin uint8 u8Mode);                   */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Regime_dwell_demarrage_hyst_haut;                             */
/*  input uint8 Regime_dwell_demarrage_hyst_bas;                              */
/*  input st24 Icd_state;                                                     */
/*  input uint8 Ign_mode_status;                                              */
/*  output st24 Icd_state;                                                    */
/*  output uint8 Ign_mode_status;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidCalcIcdState(void)
{
   uint8 u8LocalRegime_moteur_32;
   uint8 u8LocalIcd_state;

   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);

   if (u8LocalRegime_moteur_32 > Regime_dwell_demarrage_hyst_haut)
   {
      u8LocalIcd_state = IGNHAL_udtMODE_ADAP;
      VEMS_vidSET(Icd_state, u8LocalIcd_state);
      Ign_mode_status = IgnHALWriteMode(IGNHAL_udtMODE_ADAP);
   }
   else
   {
      if (u8LocalRegime_moteur_32 < Regime_dwell_demarrage_hyst_bas)
      {
         u8LocalIcd_state = IGNHAL_udtMODE_FIXED;
         VEMS_vidSET(Icd_state, u8LocalIcd_state);
         Ign_mode_status = IgnHALWriteMode(IGNHAL_udtMODE_FIXED);
      }
      else
      {
         VEMS_vidGET(Icd_state, u8LocalIcd_state);
         if (  (u8LocalIcd_state == IGNHAL_udtMODE_ADAP)
            && (Ign_mode_status == IGNHAL_udtMODE_FIXED) )
         {
            Ign_mode_status = IgnHALWriteMode(IGNHAL_udtMODE_ADAP);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidCalcIcdRatioEnergy                            */
/* !Description :  Le rapport « Icd_ratio_energy » est géré entre l’énergie   */
/*                 souhaitée et nominale  (cf. déterminé en fonction de       */
/*                 caractéristiques hardware) de la commande des bobines, Deux*/
/*                 cas peuvent se présenter:  cas où le moteur est froid/cas  */
/*                 où le moteur est chaud                                     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IGCOILMNG_vidIcdRatioEnergy();                           */
/*  input boolean IgCmd_bPwrRlyCmd;                                           */
/*  input uint16 IMMO_stEcuLockStTyp;                                         */
/*  input boolean Clef_de_contact;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidCalcIcdRatioEnergy(void)
{
   boolean bLocalIgCmd_bPwrRlyCmd;
   boolean bLocalClef_de_contact;
   uint16  u16LocalIMMO_stEcuLockStTyp;


   VEMS_vidGET(IgCmd_bPwrRlyCmd, bLocalIgCmd_bPwrRlyCmd);
   VEMS_vidGET(IMMO_stEcuLockStTyp, u16LocalIMMO_stEcuLockStTyp);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);

   if (  (bLocalIgCmd_bPwrRlyCmd == 0)
      && (u16LocalIMMO_stEcuLockStTyp == IMMO_ECU_UNLOCKED)
      && (bLocalClef_de_contact != 0) )
   {
      IGCOILMNG_vidIcdRatioEnergy();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidDiagCoil                                      */
/* !Description :  En cas de procédure « Test actionneurs » active, aucunes de*/
/*                 ces deux pannes ne seront comptées, mais les booléens «    */
/*                 Defaut_cc_plus » et « Defaut_circuit_ouvert » seront mis à */
/*                 jour.                                                      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidDiagCoil
(
   uint32 udtChannel,
   boolean* bDgoOc,
   boolean* bMonRunOc,
   boolean* bDgoScg,
   boolean* bMonRunScg,
   boolean* bDgoScp,
   boolean* bMonRunScp
)
{
   DGOHAL_tbfStatus bfLocalFault;

   *bDgoOc     = 0;
   *bMonRunOc  = 0;
   *bDgoScg    = 0;
   *bMonRunScg = 0;
   *bDgoScp    = 0;
   *bMonRunScp = 0;

   bfLocalFault = DGOHAL_bfRead(udtChannel);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      *bMonRunOc = 1;
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         *bDgoOc = 1;
      }
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      *bMonRunScg = 1;
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         *bDgoScg = 1;
      }
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      *bMonRunScp = 1;
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         *bDgoScp = 1;
      }
   }
}
/*QAC Warning(2:4700): complexity accepted                                    */

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidCalcDwellTime                                 */
/* !Description :  Calcul du seuil temporel du diagnostic du circuit ouvert   */
/*                 c’est à dire du temps de Dwell                             */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IGCOILMNG_vidDwellTime();                                */
/*  input st24 Icd_state;                                                     */
/*  input boolean Clef_de_contact;                                            */
/*  input uint8 Ign_mode_status;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidCalcDwellTime(void)
{
   boolean bLocalClef_de_contact;
   uint8   u8LocalIcd_state;


   VEMS_vidGET(Icd_state, u8LocalIcd_state);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);

   if (  (  (u8LocalIcd_state == IGNHAL_udtMODE_FIXED)
         || (Ign_mode_status == IGNHAL_udtMODE_FIXED))
      && (bLocalClef_de_contact != 0) )
   {
      IGCOILMNG_vidDwellTime();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidDwellTime                                     */
/* !Description :  Le temps de Dwell est calculé via la cartographie          */
/*                 Table_dwell_dem puis envoyé au Ldb par l’API               */
/*                 IgnHALWriteDwellTime                                       */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IgnHALWriteDwellTime(argin uint16 u16DwellTime);         */
/*  input boolean IgSys_bIgBenchModEna;                                       */
/*  input uint16 IgSys_tiDwellSpBenchMod;                                     */
/*  input uint8 Temperature_eau;                                              */
/*  input uint16 Tension_batterie_filt;                                       */
/*  input uint8 Temperature_eau_2_bkpt_map[6];                                */
/*  input uint16 Tension_batterie_bkpt_16pts[16];                             */
/*  input uint16 Table_dwell_dem[6][16];                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidDwellTime(void)
{
   boolean bLocalIgSys_bIgBenchModEna;
   uint8   u8LocalTemperature_eau;
   uint16  u16LocalTension_batterie_filt;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalTDwell;


   VEMS_vidGET(IgSys_bIgBenchModEna, bLocalIgSys_bIgBenchModEna);

   if (bLocalIgSys_bIgBenchModEna != 0)
   {
      VEMS_vidGET(IgSys_tiDwellSpBenchMod, u16LocalTDwell);
   }
   else
   {
      VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
      VEMS_vidGET(Tension_batterie_filt, u16LocalTension_batterie_filt);

      u16LocalParaX = MATHSRV_u16CalcParaIncAryU8(Temperature_eau_2_bkpt_map,
                                                  u8LocalTemperature_eau,
                                                  6);
      u16LocalParaY =
         MATHSRV_u16CalcParaIncAryU16(Tension_batterie_bkpt_16pts,
                                      u16LocalTension_batterie_filt,
                                      16);
      u16LocalTDwell = MATHSRV_u16Interp2d(&Table_dwell_dem[0][0],
                                           u16LocalParaX,
                                           u16LocalParaY,
                                           16);
   }
   IgnHALWriteDwellTime(u16LocalTDwell);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidIcdRatioEnergy                                */
/* !Description :  Fonction permet de calculer Le courant primaire  définie   */
/*                 par une cartographie Régime Charge.                        */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  PTS_R_6668934_002.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void IGNHAL_vidWriteEnergy(argin uint16 u16MaxCurrent);       */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 SenAct_tIGBTAcq;                                              */
/*  input uint8 SenAct_tIGBTAcqMax_C;                                         */
/*  input uint8 SenAct_tIGBTAcqHyst_C;                                        */
/*  input boolean IGCOILMNG_bIGBTAcqOuthyst;                                  */
/*  input uint8 Icd_water_temp_thresh;                                        */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Tension_batterie_filt;                                       */
/*  input uint16 Ext_rTotLd;                                                  */
/*  input uint16 Regime_moteur_bkpt_bobine[9];                                */
/*  input uint16 Tension_batterie_bkpt_bobine[6];                             */
/*  input uint8 Icd_ratio_energy_map[9][6];                                   */
/*  input uint8 Icd_ratio_energy_map_2[9][6];                                 */
/*  input uint16 Regime_moteur_bkpt_2_bobine[11];                             */
/*  input uint16 Engine_load_bkpt_bobine[12];                                 */
/*  input uint8 Icd_ratio_energy_map_RegLd[11][12];                           */
/*  input uint8 Icd_energy_ratio_nom;                                         */
/*  input boolean IgSys_bIgBenchModEna;                                       */
/*  input uint16 IgSys_iESpBenchMod;                                          */
/*  input uint16 Icd_desired_current;                                         */
/*  input uint16 Icd_max_current_coils;                                       */
/*  output boolean IGCOILMNG_bIGBTAcqOuthyst;                                 */
/*  output uint8 Icd_ratio_energy;                                            */
/*  output uint16 Icd_desired_current;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidIcdRatioEnergy(void)
{
   boolean bLocalIgSys_bIgBenchModEna;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalIcd_ratio_energy;
   uint8   u8LocalIcd_ratio_energyR;
   uint8   u8LocalIcd_ratio_energy1;
   uint8   u8LocalIcd_ratio_energy2;
   uint8   u8LocalSenAct_tIGBTAcq;
   uint8   u8LocalOutSelect;
   uint16  u16LocalTension_batterie_filt;
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalExt_rTotLd;
   uint16  u16LocalTensionBattFiltPara;
   uint16  u16LocalEngineloadFiltPara;
   uint16  u16LocalRegimeMoteurPara;
   uint16  u16LocalRegimeMoteur2Para;
   uint16  u16Localcomp;
   uint16  u16LocalSomme;


   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(SenAct_tIGBTAcq, u8LocalSenAct_tIGBTAcq);
   u16LocalSomme = (uint16)( (  SenAct_tIGBTAcqMax_C
                              + SenAct_tIGBTAcqHyst_C)
                           * 15);
   u16Localcomp = (uint16)((u8LocalSenAct_tIGBTAcq * 15) + 640);
   /*** Begin Bloc Hysteresis ***/
   if (IGCOILMNG_bIGBTAcqOuthyst == 0)
   {
      if (u16Localcomp >= u16LocalSomme)
      {
         IGCOILMNG_bIGBTAcqOuthyst = 1;
      }
      else
      {
         IGCOILMNG_bIGBTAcqOuthyst = 0;
      }
   }
   else
   {
      if (u8LocalSenAct_tIGBTAcq <= SenAct_tIGBTAcqMax_C)
      {
         IGCOILMNG_bIGBTAcqOuthyst = 0;
      }
      else
      {
         IGCOILMNG_bIGBTAcqOuthyst = 1;
      }
   }
   /*** End Bloc Hysteresis ***/
   if (u8LocalTemperature_eau > Icd_water_temp_thresh)
   {
      VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
      VEMS_vidGET(Tension_batterie_filt, u16LocalTension_batterie_filt);
      VEMS_vidGET(Ext_rTotLd, u16LocalExt_rTotLd);

      u16LocalRegimeMoteurPara =
         MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_bobine,
                                      u16LocalRegime_moteur,
                                      9);
      u16LocalTensionBattFiltPara =
         MATHSRV_u16CalcParaIncAryU16(Tension_batterie_bkpt_bobine,
                                      u16LocalTension_batterie_filt,
                                      6);
      u8LocalIcd_ratio_energy1 = MATHSRV_u8Interp2d(&Icd_ratio_energy_map[0][0],
                                                   u16LocalRegimeMoteurPara,
                                                   u16LocalTensionBattFiltPara,
                                                   6);
      u8LocalIcd_ratio_energy2 =
         MATHSRV_u8Interp2d(&Icd_ratio_energy_map_2[0][0],
                           u16LocalRegimeMoteurPara,
                           u16LocalTensionBattFiltPara,
                           6);
      if (IGCOILMNG_bIGBTAcqOuthyst != 0)
      {
         u8LocalOutSelect = u8LocalIcd_ratio_energy2;
      }
      else
      {
         u8LocalOutSelect = u8LocalIcd_ratio_energy1;
      }
      u16LocalRegimeMoteur2Para =
         MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_2_bobine,
                                      u16LocalRegime_moteur,
                                      11);
      u16LocalEngineloadFiltPara =
         MATHSRV_u16CalcParaIncAryU16(Engine_load_bkpt_bobine,
                                      u16LocalExt_rTotLd,
                                      12);
      u8LocalIcd_ratio_energyR =
         MATHSRV_u8Interp2d(&Icd_ratio_energy_map_RegLd[0][0],
                            u16LocalRegimeMoteur2Para,
                            u16LocalEngineloadFiltPara,
                            12);
      u8LocalIcd_ratio_energy = (uint8)MATHSRV_udtMIN(u8LocalOutSelect,
                                                      u8LocalIcd_ratio_energyR);
   }
   else
   {
      u8LocalIcd_ratio_energy = Icd_energy_ratio_nom;
   }
   VEMS_vidSET(Icd_ratio_energy, u8LocalIcd_ratio_energy);

   VEMS_vidGET(IgSys_bIgBenchModEna, bLocalIgSys_bIgBenchModEna);
   if (bLocalIgSys_bIgBenchModEna != 0)
   {
      VEMS_vidGET(IgSys_iESpBenchMod, Icd_desired_current);
   }
   else
   {
      Icd_desired_current = (uint16)( ( (uint32)u8LocalIcd_ratio_energy
                                      * Icd_max_current_coils )
                                    / 256);
   }
   IGNHAL_vidWriteEnergy(Icd_desired_current);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidAgIgMng                                       */
/* !Description :  Ce bloc gère l’envoi de l’avance finale à appliquer et     */
/*                 l’avance finale suivante et la demande d’inhibition de     */
/*                 l’allumage pour les besoins de la stratégie Misfire.       */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf argret void IGCOILMNG_vidTestInhibIgn();                             */
/*  extf argret void IGCOILMNG_vidInhibIgn();                                 */
/*  extf argret void IGCOILMNG_vidProgAvance();                               */
/*  extf argret void IGCOILMNG_vidInhibIgnNext();                             */
/*  extf argret void IGCOILMNG_vidProgAvanceNext();                           */
/*  input uint8 Eng_noCmprCyl;                                                */
/*  input uint8 Eng_noCmprNxtCyl;                                             */
/*  input boolean IgCmd_bInhIgCoilCmd;                                        */
/*  input boolean IgCmd_bInhIgCoilNxtCmd;                                     */
/*  output uint8 IgCmd_stCurIgCoil;                                           */
/*  output uint8 IgCmd_stCurNxtIgCoil;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidAgIgMng(void)
{
   uint8 u8LocalEng_noCmprCyl;
   uint8 u8LocalEng_noCmprNxtCyl;

   VEMS_vidGET(Eng_noCmprCyl, u8LocalEng_noCmprCyl);
   VEMS_vidGET(Eng_noCmprNxtCyl, u8LocalEng_noCmprNxtCyl);

   switch (u8LocalEng_noCmprCyl)
   {
      case 1:
      IgCmd_stCurIgCoil = IGN_COIL_CYLINDER_1;
      break;

      case 2:
      IgCmd_stCurIgCoil = IGN_COIL_CYLINDER_2;
      break;

      case 3:
      IgCmd_stCurIgCoil = IGN_COIL_CYLINDER_3;
      break;

      case 4:
      IgCmd_stCurIgCoil = IGN_COIL_CYLINDER_4;
      break;

      default:
      SWFAIL_vidSoftwareErrorHook();
      break;
   }
   switch (u8LocalEng_noCmprNxtCyl)
   {
      case 1:
      IgCmd_stCurNxtIgCoil = IGN_COIL_CYLINDER_1;
      break;

      case 2:
      IgCmd_stCurNxtIgCoil = IGN_COIL_CYLINDER_2;
      break;

      case 3:
      IgCmd_stCurNxtIgCoil = IGN_COIL_CYLINDER_3;
      break;

      case 4:
      IgCmd_stCurNxtIgCoil = IGN_COIL_CYLINDER_4;
      break;

      default:
      SWFAIL_vidSoftwareErrorHook();
      break;
   }

   IGCOILMNG_vidTestInhibIgn();

   if (IgCmd_bInhIgCoilCmd != 0)
   {
      IGCOILMNG_vidInhibIgn();
   }
   else
   {
      IGCOILMNG_vidProgAvance();
   }
   if (IgCmd_bInhIgCoilNxtCmd != 0)
   {
      IGCOILMNG_vidInhibIgnNext();
   }
   else
   {
      IGCOILMNG_vidProgAvanceNext();
   }
}
/*QAC Warning(2:4700): complexity accepted                                    */

/*---------------------------------end of file--------------------------------*/