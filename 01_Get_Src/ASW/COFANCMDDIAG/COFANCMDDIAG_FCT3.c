/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COFANCMDDIAG                                            */
/* !Description     : COFANCMDDIAG component.                                 */
/*                                                                            */
/* !Module          : COFANCMDDIAG                                            */
/* !Description     : COMMANDE ET DIAGNOSTICS DES GMV.                        */
/*                                                                            */
/* !File            : COFANCMDDIAG_FCT3.C                                     */
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
/*   1 / COFANCMDDIAG_vidDiagCoFan                                            */
/*   2 / COFANCMDDIAG_vidDiagCoFanEna                                         */
/*   3 / COFANCMDDIAG_vidDgoCoFanB1                                           */
/*   4 / COFANCMDDIAG_vidDgoCohCoFanB1                                        */
/*   5 / COFANCMDDIAG_vidDgoCoFanB2                                           */
/*   6 / COFANCMDDIAG_vidDgoCohB2                                             */
/*   7 / COFANCMDDIAG_vidDgCohCoFB2NoSpd                                      */
/*   8 / COFANCMDDIAG_vidMngTimer                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_6722439 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/COFANCMDDIAG/COFANCMDDIAG_FCT3.C_v$*/
/* $Revision::   1.20     $$Author::   wbouach        $$Date::   24 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   24 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "COFANCMDDIAG_IM.H"
#include "COFANCMDDIAG_L.H"
#include "COFANCMDDIAG.H"
#include "SWFAIL.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidDiagCoFan                                  */
/* !Description :  Cette fonction gère l’ensemble des diagnostics GMV pour les*/
/*                 3 équipements.                                             */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00032_006.01                                     */
/*                 VEMS_R_09_00032_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COFANCMDDIAG_vidMngTimer();                              */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void COFANCMDDIAG_vidDiagBMonRun();                           */
/*  extf argret void COFANCMDDIAG_vidDiagCoFanEna();                          */
/*  input uint16 Tension_batterie;                                            */
/*  input uint16 CoFan_max_voltage_diag_thresh;                               */
/*  input uint16 CoFan_min_voltage_diag_thresh;                               */
/*  input uint8 COFANCMDDIAG_u8LocalcountTimer1;                              */
/*  output boolean CoFan_bMonRunUnVld_StFanC;                                 */
/*  output boolean CoFan_bMonRunCritSc_StFanC;                                */
/*  output boolean CoFan_bMonRunECI_StFanC;                                   */
/*  output boolean COFANCMDDIAG_bMonRunCoFan;                                 */
/*  output boolean CoFan_bMonRunEl_StFanC;                                    */
/*  output boolean CoFan_bMonRunClsdRly_StFanC;                               */
/*  output boolean CoFan_bMonRunCoh_StFanB1;                                  */
/*  output boolean CoFan_bMonRunCoh_StFanB2LoSpd;                             */
/*  output boolean CoFan_bMonRunCoh_StFanB2NoSpd;                             */
/*  output boolean CoFan_bMonRunCoh_StFanB2HiSpd;                             */
/*  output boolean CoFan_bMonRunOc_DrvrFan1;                                  */
/*  output boolean CoFan_bMonRunLo_DrvrFan1;                                  */
/*  output boolean CoFan_bMonRunHi_DrvrFan1;                                  */
/*  output boolean CoFan_bMonRunOc_DrvrFan2;                                  */
/*  output boolean CoFan_bMonRunLo_DrvrFan2;                                  */
/*  output boolean CoFan_bMonRunHi_DrvrFan2;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidDiagCoFan(void)
{
   boolean bLocalInhCofanDiag;
   uint16  u16LocalTensionbatterie;


   COFANCMDDIAG_vidMngTimer();
   VEMS_vidGET(Tension_batterie, u16LocalTensionbatterie);
   bLocalInhCofanDiag = GDGAR_bGetFRM(FRM_FRM_INHCOFANDIAG);
   if (  (bLocalInhCofanDiag == 0)
      && (u16LocalTensionbatterie < CoFan_max_voltage_diag_thresh)
      && (u16LocalTensionbatterie > CoFan_min_voltage_diag_thresh))
   {
      CoFan_bMonRunUnVld_StFanC = 1;
      CoFan_bMonRunCritSc_StFanC = 1;
      CoFan_bMonRunECI_StFanC = 1;
      COFANCMDDIAG_bMonRunCoFan = 1;
      if (COFANCMDDIAG_u8LocalcountTimer1 == 0)
      {
         CoFan_bMonRunEl_StFanC = 1;
      }
      else
      {
         CoFan_bMonRunEl_StFanC = 0;
      }
      COFANCMDDIAG_vidDiagBMonRun();
      COFANCMDDIAG_vidDiagCoFanEna();
   }
   else
   {
      COFANCMDDIAG_bMonRunCoFan = 0;
      CoFan_bMonRunUnVld_StFanC = 0;
      CoFan_bMonRunCritSc_StFanC = 0;
      CoFan_bMonRunECI_StFanC = 0;
      CoFan_bMonRunEl_StFanC = 0;
      CoFan_bMonRunClsdRly_StFanC = 0;
      CoFan_bMonRunCoh_StFanB1 = 0;
      CoFan_bMonRunCoh_StFanB2LoSpd =0;
      CoFan_bMonRunCoh_StFanB2NoSpd = 0;
      CoFan_bMonRunCoh_StFanB2HiSpd = 0;
      CoFan_bMonRunOc_DrvrFan1 = 0;
      CoFan_bMonRunLo_DrvrFan1 = 0;
      CoFan_bMonRunHi_DrvrFan1 = 0;
      CoFan_bMonRunOc_DrvrFan2 = 0;
      CoFan_bMonRunLo_DrvrFan2 = 0;
      CoFan_bMonRunHi_DrvrFan2 = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidDiagCoFanEna                               */
/* !Description :  Cette fonction réalise les diagnostics électriques sur les */
/*                 commandes.                                                 */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void COFANCMDDIAG_vidDgoCoFanB1();                            */
/*  extf argret void COFANCMDDIAG_vidDgoCoFanB2();                            */
/*  extf argret void COFANCMDDIAG_vidDgoCoFanC();                             */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st45 Cf_cooling_fan_equipment;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidDiagCoFanEna(void)
{
   uint8 u8LocalCfEqu;


   VEMS_vidGET(Cf_cooling_fan_equipment, u8LocalCfEqu);
   switch(u8LocalCfEqu)
   {
      case EQUIPMENT_B1:
         COFANCMDDIAG_vidDgoCoFanB1();
         break;
      case EQUIPMENT_B2:
         COFANCMDDIAG_vidDgoCoFanB2();
         break;
      case EQUIPMENT_C:
         COFANCMDDIAG_vidDgoCoFanC();
         break;
      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidDgoCoFanB1                                 */
/* !Description :  ette fonction réalise l’acquisition d’ETAT_GMV et des      */
/*                 diagnostics électriques de la commande CMD_GMV1 provenant  */
/*                 du LdB en équipement B1.                                   */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void COFANCMDDIAG_vidDgoCohCoFanB1();                         */
/*  input boolean Acquisition_etat_gmvB1_brut;                                */
/*  input boolean Ext_bStFanFil;                                              */
/*  input uint8 CoFan_noStFanDownThd_C;                                       */
/*  input uint8 CoFan_noStFanUpThd_C;                                         */
/*  input uint8 COFANCMDDIAG_u8LocalCount;                                    */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input uint8 CoFan_noSpdVehFanB1LoThd_C;                                   */
/*  input uint8 CoFan_noSpdVehFanB1HiThd_C;                                   */
/*  input boolean COFANCMDDIAG_bMonRunCoh_Output;                             */
/*  input boolean COFANCMDDIAG_bDgoHiDrvrFan1;                                */
/*  input boolean COFANCMDDIAG_bFaultGround1;                                 */
/*  input boolean COFANCMDDIAG_bFaultOpen1;                                   */
/*  input boolean CoFan_bDgoHi_DrvrFan1;                                      */
/*  output boolean Ext_bStFanB1Raw;                                           */
/*  output uint8 COFANCMDDIAG_u8LocalCount;                                   */
/*  output boolean Ext_bStFanFil;                                             */
/*  output boolean CoFan_bDgoHi_DrvrFan1;                                     */
/*  output boolean COFANCMDDIAG_bMonRunCoh_StFanB1;                           */
/*  output boolean CoFan_bDgoLo_DrvrFan1;                                     */
/*  output boolean CoFan_bDgoOc_DrvrFan1;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidDgoCoFanB1(void)
{
   boolean bLocalAcquisitionEtatGmvB1Brut;
   boolean bLocalExt_bStFanFil;
   uint8   u8LocalTranThd;
   uint8   u8LocalVitesse_vehicule;
   uint16  u16LocalCnt;


   VEMS_vidGET(Acquisition_etat_gmvB1_brut, bLocalAcquisitionEtatGmvB1Brut);
   VEMS_vidSET(Ext_bStFanB1Raw, bLocalAcquisitionEtatGmvB1Brut);
   VEMS_vidGET(Ext_bStFanFil, bLocalExt_bStFanFil);
   if (bLocalAcquisitionEtatGmvB1Brut != bLocalExt_bStFanFil)
   {
      if (bLocalAcquisitionEtatGmvB1Brut == 0)
      {
         u8LocalTranThd = CoFan_noStFanDownThd_C;
      }
      else
      {
         u8LocalTranThd = CoFan_noStFanUpThd_C;
      }
      u16LocalCnt = (uint16)(COFANCMDDIAG_u8LocalCount + 1);
      COFANCMDDIAG_u8LocalCount = (uint8)MATHSRV_udtMIN(u16LocalCnt, 255);
      if (COFANCMDDIAG_u8LocalCount >= u8LocalTranThd)
      {
         VEMS_vidSET(Ext_bStFanFil, bLocalAcquisitionEtatGmvB1Brut);
         COFANCMDDIAG_u8LocalCount = 0;
      }
   }
   else
   {
      COFANCMDDIAG_u8LocalCount = 0;
   }

   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);
   MATHSRV_vidSchmittTriggerU16((uint16)u8LocalVitesse_vehicule,
                                (uint16)CoFan_noSpdVehFanB1LoThd_C,
                                (uint16)CoFan_noSpdVehFanB1HiThd_C,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &COFANCMDDIAG_bMonRunCoh_Output);
   CoFan_bDgoHi_DrvrFan1 = COFANCMDDIAG_bDgoHiDrvrFan1;
   if (  (COFANCMDDIAG_bFaultGround1 != 0)
      || (COFANCMDDIAG_bFaultOpen1 != 0))
   {
      COFANCMDDIAG_bMonRunCoh_StFanB1 = 0;
      VEMS_vidGET(Ext_bStFanFil, bLocalExt_bStFanFil);
      if (bLocalExt_bStFanFil != 0)
      {
         CoFan_bDgoLo_DrvrFan1 = 1;
         CoFan_bDgoOc_DrvrFan1 = 0;
      }
      else
      {
         CoFan_bDgoLo_DrvrFan1 = 0;
         CoFan_bDgoOc_DrvrFan1 = 1;
      }
   }
   else
   {
      CoFan_bDgoLo_DrvrFan1 = 0;
      CoFan_bDgoOc_DrvrFan1 = 0;
      if (CoFan_bDgoHi_DrvrFan1 != 0)
      {
         COFANCMDDIAG_bMonRunCoh_StFanB1 = 0;
      }
      else
      {
         if (COFANCMDDIAG_bMonRunCoh_Output != 0)
         {
            COFANCMDDIAG_bMonRunCoh_StFanB1 = 1;
            COFANCMDDIAG_vidDgoCohCoFanB1();
         }
         else
         {
            COFANCMDDIAG_bMonRunCoh_StFanB1 = 0;
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidDgoCohCoFanB1                              */
/* !Description :  Cette fionction réalise la Cohérence vitesse ou ETAT_GMVX  */
/*                 en défaut électrique en Fric B1.                           */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00032_008.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoFan_bAcvCoFan1CmdAppld;                                   */
/*  input boolean Ext_bStFanFil;                                              */
/*  output boolean CoFan_bDgoCoh_StFanB1;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidDgoCohCoFanB1(void)
{
   boolean bLocalCoFan_bAcvCoFan1CmdAppld;
   boolean bLocalExt_bStFanFil;


   VEMS_vidGET(CoFan_bAcvCoFan1CmdAppld, bLocalCoFan_bAcvCoFan1CmdAppld);
   VEMS_vidGET(Ext_bStFanFil, bLocalExt_bStFanFil);
   if (bLocalCoFan_bAcvCoFan1CmdAppld != bLocalExt_bStFanFil)
   {
      CoFan_bDgoCoh_StFanB1 = 1;
   }
   else
   {
      CoFan_bDgoCoh_StFanB1 = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidDgoCoFanB2                                 */
/* !Description :  Cette fonction réalise l’acquisition d’ETAT_GMV et des     */
/*                 diagnostics électriques des commandes CMD_GMV1 et CMD_GMV2 */
/*                 provenant du LdB en équipement B2.                         */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void COFANCMDDIAG_vidDgoCohB2();                              */
/*  input boolean Ext_bStFanFil;                                              */
/*  input boolean Acquisition_etat_gmvB2_brut;                                */
/*  input uint8 CoFan_noStFanDownThd_C;                                       */
/*  input uint8 CoFan_noStFanUpThd_C;                                         */
/*  input uint8 COFANCMDDIAG_u8LocalCount;                                    */
/*  input boolean COFANCMDDIAG_bDgoHiDrvrFan1;                                */
/*  input boolean COFANCMDDIAG_bDgoHiDrvrFan2;                                */
/*  input boolean COFANCMDDIAG_bFaultOpen1;                                   */
/*  input boolean COFANCMDDIAG_bFaultGround1;                                 */
/*  input boolean CoFan_bAcvCoFan2CmdAppld;                                   */
/*  input boolean COFANCMDDIAG_bFaultOpen2;                                   */
/*  input boolean COFANCMDDIAG_bFaultGround2;                                 */
/*  input boolean CoFan_bDgoLo_DrvrFan1;                                      */
/*  input boolean CoFan_bDgoOc_DrvrFan1;                                      */
/*  input boolean CoFan_bDgoHi_DrvrFan1;                                      */
/*  input boolean CoFan_bDgoLo_DrvrFan2;                                      */
/*  input boolean CoFan_bDgoOc_DrvrFan2;                                      */
/*  input boolean CoFan_bDgoHi_DrvrFan2;                                      */
/*  output boolean Ext_bStFanB2Raw;                                           */
/*  output uint8 COFANCMDDIAG_u8LocalCount;                                   */
/*  output boolean Ext_bStFanFil;                                             */
/*  output boolean CoFan_bDgoHi_DrvrFan1;                                     */
/*  output boolean CoFan_bDgoHi_DrvrFan2;                                     */
/*  output boolean CoFan_bDgoLo_DrvrFan1;                                     */
/*  output boolean CoFan_bDgoOc_DrvrFan1;                                     */
/*  output boolean CoFan_bDgoLo_DrvrFan2;                                     */
/*  output boolean CoFan_bDgoOc_DrvrFan2;                                     */
/*  output boolean COFANCMDDIAG_bMonRunCoh_StFanB2;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidDgoCoFanB2(void)
{
   boolean bLocalAcquisitionEtatGmvB2Brut;
   boolean bLocalExt_bStFanFil;
   boolean bLocalCoFan_bAcvCoFan2CmdAppld;
   uint8   u8LocalTranThd;
   uint16  u16LocalCnt;


   VEMS_vidGET(Ext_bStFanFil, bLocalExt_bStFanFil);
   VEMS_vidGET(Acquisition_etat_gmvB2_brut, bLocalAcquisitionEtatGmvB2Brut);
   VEMS_vidSET(Ext_bStFanB2Raw, bLocalAcquisitionEtatGmvB2Brut);
   if (bLocalAcquisitionEtatGmvB2Brut != bLocalExt_bStFanFil)
   {
      if (bLocalAcquisitionEtatGmvB2Brut == 0)
      {
         u8LocalTranThd = CoFan_noStFanDownThd_C;
      }
      else
      {
         u8LocalTranThd = CoFan_noStFanUpThd_C;
      }
      u16LocalCnt = (uint16)(COFANCMDDIAG_u8LocalCount + 1);
      COFANCMDDIAG_u8LocalCount = (uint8)MATHSRV_udtMIN(u16LocalCnt, 255);
      if (COFANCMDDIAG_u8LocalCount >= u8LocalTranThd)
      {
         VEMS_vidSET(Ext_bStFanFil, bLocalAcquisitionEtatGmvB2Brut);
         COFANCMDDIAG_u8LocalCount = 0;
      }
   }
   else
   {
      COFANCMDDIAG_u8LocalCount = 0;
   }
   CoFan_bDgoHi_DrvrFan1 = COFANCMDDIAG_bDgoHiDrvrFan1;
   CoFan_bDgoHi_DrvrFan2 = COFANCMDDIAG_bDgoHiDrvrFan2;
   VEMS_vidGET(Ext_bStFanFil, bLocalExt_bStFanFil);
   if (  (COFANCMDDIAG_bFaultOpen1 != 0)
      || (COFANCMDDIAG_bFaultGround1 != 0))
   {
      VEMS_vidGET(CoFan_bAcvCoFan2CmdAppld, bLocalCoFan_bAcvCoFan2CmdAppld);
      if (bLocalCoFan_bAcvCoFan2CmdAppld != 0)
      {
         CoFan_bDgoLo_DrvrFan1 = 1;
         CoFan_bDgoOc_DrvrFan1 = 1;
      }
      else
      {
         if (bLocalExt_bStFanFil != 0)
         {
            CoFan_bDgoLo_DrvrFan1 = 1;
            CoFan_bDgoOc_DrvrFan1 = 0;
         }
         else
         {
            CoFan_bDgoLo_DrvrFan1 = 0;
            CoFan_bDgoOc_DrvrFan1 = 1;
         }
      }
   }
   else
   {
      CoFan_bDgoLo_DrvrFan1 = 0;
      CoFan_bDgoOc_DrvrFan1 = 0;
   }

   if (  (COFANCMDDIAG_bFaultOpen2 != 0)
      || (COFANCMDDIAG_bFaultGround2 != 0))
   {
      if (bLocalExt_bStFanFil != 0)
      {
         CoFan_bDgoLo_DrvrFan2 = 1;
         CoFan_bDgoOc_DrvrFan2 = 0;
      }
      else
      {
         CoFan_bDgoLo_DrvrFan2 = 0;
         CoFan_bDgoOc_DrvrFan2 = 1;
      }
   }
   else
   {
      CoFan_bDgoLo_DrvrFan2 = 0;
      CoFan_bDgoOc_DrvrFan2 = 0;
   }

   if (  (CoFan_bDgoLo_DrvrFan1 != 0)
      || (CoFan_bDgoOc_DrvrFan1 != 0)
      || (CoFan_bDgoHi_DrvrFan1 != 0)
      || (CoFan_bDgoLo_DrvrFan2 != 0)
      || (CoFan_bDgoOc_DrvrFan2 != 0)
      || (CoFan_bDgoHi_DrvrFan2 != 0))
   {
      COFANCMDDIAG_bMonRunCoh_StFanB2 = 0;
   }
   else
   {
      COFANCMDDIAG_vidDgoCohB2();
      COFANCMDDIAG_bMonRunCoh_StFanB2 = 1;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidDgoCohB2                                   */
/* !Description :  Cette fonction calcule les résultats des diagnostics de    */
/*                 cohérence pour les 3 états Petite Vitesse, Grande Vitesse  */
/*                 et Vitesse nulle en équipement B2.                         */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void COFANCMDDIAG_vidDgCohCoFB2NoSpd();                       */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input uint8 CoFan_noSpdVehFanB2LoThd_C;                                   */
/*  input uint8 CoFan_noSpdVehFanB2HiThd_C;                                   */
/*  input boolean COFANCMDDIAG_bMonRunCoh_B2NoSpd;                            */
/*  input boolean CoFan_bAcvCoFan2CmdAppld;                                   */
/*  input boolean Ext_bStFanFil;                                              */
/*  input boolean CoFan_bAcvCoFan1CmdAppld;                                   */
/*  output boolean CoFan_bDgoCoh_StFanB2LoSpd;                                */
/*  output boolean CoFan_bDgoCoh_StFanB2HiSpd;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidDgoCohB2(void)
{
   boolean bLocalCoFan_bAcvCoFan1CmdAppld;
   boolean bLocalCoFan_bAcvCoFan2CmdAppld;
   boolean bLocalExt_bStFanFil;
   uint8   u8LocalVitesse_vehicule;


   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);
   MATHSRV_vidSchmittTriggerU16((uint16)u8LocalVitesse_vehicule,
                                (uint16)CoFan_noSpdVehFanB2LoThd_C,
                                (uint16)CoFan_noSpdVehFanB2HiThd_C,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &COFANCMDDIAG_bMonRunCoh_B2NoSpd);
   VEMS_vidGET(CoFan_bAcvCoFan2CmdAppld, bLocalCoFan_bAcvCoFan2CmdAppld);
   VEMS_vidGET(Ext_bStFanFil, bLocalExt_bStFanFil);
   if (  (bLocalCoFan_bAcvCoFan2CmdAppld != 0)
      && (bLocalExt_bStFanFil == 0))
   {
      VEMS_vidGET(CoFan_bAcvCoFan1CmdAppld, bLocalCoFan_bAcvCoFan1CmdAppld);
      if (bLocalCoFan_bAcvCoFan1CmdAppld != 0)
      {
        CoFan_bDgoCoh_StFanB2LoSpd = 0;
        CoFan_bDgoCoh_StFanB2HiSpd = 1;
      }
      else
      {
        CoFan_bDgoCoh_StFanB2LoSpd = 1;
        CoFan_bDgoCoh_StFanB2HiSpd = 0;
      }
   }
   else
   {
      CoFan_bDgoCoh_StFanB2LoSpd = 0;
      CoFan_bDgoCoh_StFanB2HiSpd = 0;
   }
   if (COFANCMDDIAG_bMonRunCoh_B2NoSpd != 0)
   {
      COFANCMDDIAG_vidDgCohCoFB2NoSpd();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidDgCohCoFB2NoSpd                            */
/* !Description :  ette fonction réalise la Cohérence petite vitesse, grande  */
/*                 vitesse et absence de commande en Fric B2.                 */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoFan_bAcvCoFan1CmdAppld;                                   */
/*  input boolean CoFan_bAcvCoFan2CmdAppld;                                   */
/*  input boolean Ext_bStFanFil;                                              */
/*  output boolean CoFan_bDgoCoh_StFanB2NoSpd;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidDgCohCoFB2NoSpd(void)
{
   boolean bLocalCoFan_bAcvCoFan1CmdAppld;
   boolean bLocalCoFan_bAcvCoFan2CmdAppld;
   boolean bLocalExt_bStFanFil;


   VEMS_vidGET(CoFan_bAcvCoFan1CmdAppld, bLocalCoFan_bAcvCoFan1CmdAppld);
   VEMS_vidGET(CoFan_bAcvCoFan2CmdAppld, bLocalCoFan_bAcvCoFan2CmdAppld);
   VEMS_vidGET(Ext_bStFanFil, bLocalExt_bStFanFil);
   if (  (bLocalExt_bStFanFil != 0)
      && (bLocalCoFan_bAcvCoFan2CmdAppld == 0)
      && (bLocalCoFan_bAcvCoFan1CmdAppld == 0))
   {
      CoFan_bDgoCoh_StFanB2NoSpd = 1;
   }
   else
   {
      CoFan_bDgoCoh_StFanB2NoSpd = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidMngTimer                                   */
/* !Description :  Fonction qui permet de calculer les cinq valeurs du        */
/*                 compteur.                                                  */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoFan_bAcvCoFan2CmdAppld;                                   */
/*  input boolean COFANCMDDIAG_bLocalCoFan2Cmdprev;                           */
/*  input boolean COFANCMDDIAG_bLocalInpTimer1prev;                           */
/*  input uint8 CoFan_tiChgDlyStFanC_C;                                       */
/*  input uint8 CoFan_tiChgDlyStFanB2_C;                                      */
/*  input uint8 COFANCMDDIAG_u8LocalcountTimer1;                              */
/*  input uint8 COFANCMDDIAG_u8LocalcountTimer3;                              */
/*  input boolean COFANCMDDIAG_bLocalInpTimer2prev;                           */
/*  input uint8 COFANCMDDIAG_u8LocalcountTimer2;                              */
/*  input uint8 COFANCMDDIAG_u8LocalcountTimer4;                              */
/*  input boolean CoFan_bAcvCoFan1CmdAppld;                                   */
/*  input boolean COFANCMDDIAG_bLocalCoFan1Cmdprev;                           */
/*  input boolean COFANCMDDIAG_bLocalInpTimer5prev;                           */
/*  input uint8 CoFan_tiChgDlyStFanB1_C;                                      */
/*  input uint8 COFANCMDDIAG_u8LocalcountTimer5;                              */
/*  output uint8 COFANCMDDIAG_u8LocalcountTimer1;                             */
/*  output uint8 COFANCMDDIAG_u8LocalcountTimer3;                             */
/*  output uint8 COFANCMDDIAG_u8LocalcountTimer2;                             */
/*  output uint8 COFANCMDDIAG_u8LocalcountTimer4;                             */
/*  output uint8 COFANCMDDIAG_u8LocalcountTimer5;                             */
/*  output boolean COFANCMDDIAG_bLocalInpTimer1prev;                          */
/*  output boolean COFANCMDDIAG_bLocalInpTimer2prev;                          */
/*  output boolean COFANCMDDIAG_bLocalInpTimer5prev;                          */
/*  output boolean COFANCMDDIAG_bLocalCoFan2Cmdprev;                          */
/*  output boolean COFANCMDDIAG_bLocalCoFan1Cmdprev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidMngTimer(void)
{
   boolean bLocalInputTimer1and3;
   boolean bLocalInputTimer2and4;
   boolean bLocalInputTimer5;
   boolean bLocalCoFan_bAcvCoFan1CmdAppld;
   boolean bLocalCoFan_bAcvCoFan2CmdAppld;


   bLocalInputTimer1and3 = 0;
   bLocalInputTimer2and4 = 0;
   bLocalInputTimer5 = 0;

   VEMS_vidGET(CoFan_bAcvCoFan2CmdAppld, bLocalCoFan_bAcvCoFan2CmdAppld);
   if (bLocalCoFan_bAcvCoFan2CmdAppld != 0)
   {
      if (COFANCMDDIAG_bLocalCoFan2Cmdprev == 0)
      {
         bLocalInputTimer1and3 = 1;
      }
   }
   else
   {
      if (COFANCMDDIAG_bLocalCoFan2Cmdprev != 0)
      {
         bLocalInputTimer2and4 = 1;
      }
   }

   if (  (bLocalInputTimer1and3 != 0)
      && (COFANCMDDIAG_bLocalInpTimer1prev == 0))
   {
      COFANCMDDIAG_u8LocalcountTimer1 =
         (uint8)(((CoFan_tiChgDlyStFanC_C * 100) + 128) / 256);
      COFANCMDDIAG_u8LocalcountTimer3 =
         (uint8)(((CoFan_tiChgDlyStFanB2_C * 100) + 128) / 256);
   }
   else
   {
      if (COFANCMDDIAG_u8LocalcountTimer1 > 0)
      {
         COFANCMDDIAG_u8LocalcountTimer1 =
            (uint8)(COFANCMDDIAG_u8LocalcountTimer1 - 1);
      }
      if (COFANCMDDIAG_u8LocalcountTimer3 > 0)
      {
         COFANCMDDIAG_u8LocalcountTimer3 =
               (uint8)(COFANCMDDIAG_u8LocalcountTimer3 - 1);
      }
   }

   if (  (bLocalInputTimer2and4 != 0)
      && (COFANCMDDIAG_bLocalInpTimer2prev == 0))
   {
      COFANCMDDIAG_u8LocalcountTimer2 =
         (uint8)(((CoFan_tiChgDlyStFanC_C * 100) + 128) /256);
      COFANCMDDIAG_u8LocalcountTimer4 =
         (uint8)(((CoFan_tiChgDlyStFanB2_C * 100) + 128) /256);
   }
   else
   {
      if (COFANCMDDIAG_u8LocalcountTimer2 > 0)
      {
         COFANCMDDIAG_u8LocalcountTimer2 =
            (uint8)(COFANCMDDIAG_u8LocalcountTimer2 - 1);
      }
      if (COFANCMDDIAG_u8LocalcountTimer4 > 0)
      {
         COFANCMDDIAG_u8LocalcountTimer4 =
            (uint8)(COFANCMDDIAG_u8LocalcountTimer4 - 1);
      }
   }
   VEMS_vidGET(CoFan_bAcvCoFan1CmdAppld, bLocalCoFan_bAcvCoFan1CmdAppld);
   if (bLocalCoFan_bAcvCoFan1CmdAppld != 0)
   {
      if(COFANCMDDIAG_bLocalCoFan1Cmdprev == 0)
      {
         bLocalInputTimer5 = 1;
      }
   }
   else
   {
      if(COFANCMDDIAG_bLocalCoFan1Cmdprev != 0)
      {
         bLocalInputTimer5 = 1;
      }
   }
   if (  (bLocalInputTimer5 != 0)
      && (COFANCMDDIAG_bLocalInpTimer5prev == 0))
   {
      COFANCMDDIAG_u8LocalcountTimer5 =
         (uint8)(((CoFan_tiChgDlyStFanB1_C * 100) + 128) / 256);
   }
   else
   {
      if (COFANCMDDIAG_u8LocalcountTimer5 > 0)
      {
         COFANCMDDIAG_u8LocalcountTimer5 =
            (uint8)(COFANCMDDIAG_u8LocalcountTimer5 - 1);
      }
   }
   COFANCMDDIAG_bLocalInpTimer1prev = bLocalInputTimer1and3;
   COFANCMDDIAG_bLocalInpTimer2prev = bLocalInputTimer2and4;
   COFANCMDDIAG_bLocalInpTimer5prev = bLocalInputTimer5;
   COFANCMDDIAG_bLocalCoFan2Cmdprev = bLocalCoFan_bAcvCoFan2CmdAppld;
   COFANCMDDIAG_bLocalCoFan1Cmdprev = bLocalCoFan_bAcvCoFan1CmdAppld;
}
/*----------------------------------end of file-------------------------------*/