/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DIAGSFTYLVL2                                            */
/* !Description     : DIAGSFTYLVL2 Component.                                 */
/*                                                                            */
/* !Module          : DIAGSFTYLVL2                                            */
/* !Description     : SAFETY TMS: Diagnostics des capteurs/Trames CAN pour le */
/*                    safety niveau 2.                                        */
/*                                                                            */
/* !File            : DIAGSFTYLVL2_FCT4.C                                     */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / DIAGSFTYLVL2_vidCluDiagSftyLvl2                                      */
/*   2 / DIAGSFTYLVL2_vidCluDiag                                              */
/*   3 / DIAGSFTYLVL2_vidCluSecu                                              */
/*   4 / DIAGSFTYLVL2_vidNeutPosDiagSftyLvl2                                  */
/*   5 / DIAGSFTYLVL2_vidNeutPosnDiag                                         */
/*   6 / DIAGSFTYLVL2_vidNeutPosnSecu                                         */
/*   7 / DIAGSFTYLVL2_vidF34DTqCoh                                            */
/*   8 / DIAGSFTYLVL2_vidReinitCounter                                        */
/*   9 / DIAGSFTYLVL2_vidCalculcounter                                        */
/*   10 / DIAGSFTYLVL2_vidInit                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5147426 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "DIAGSFTYLVL2.h"
#include "DIAGSFTYLVL2_L.h"
#include "DIAGSFTYLVL2_IM.h"
#include "LIBSFTYLVL2.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidCluDiagSftyLvl2                            */
/* !Description :  Cette fonction effectue les diagnostiques du niveau 2 pour */
/*                 la pédale d’embrayage, qui se font en 2 étapes             */
/*                 :diagnostique et sécurisation des défauts                  */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGSFTYLVL2_vidCluDiag();                               */
/*  extf argret void DIAGSFTYLVL2_vidCluSecu();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidCluDiagSftyLvl2(void)
{
   DIAGSFTYLVL2_vidCluDiag();
   DIAGSFTYLVL2_vidCluSecu();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidCluDiag                                    */
/* !Description :  Cette fonction décrit les diagnostiques pour le Safety     */
/*                 niveau 2 pour la pédale d’embrayage                        */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_rCluPedSen;                                          */
/*  input uint16 SftyMgt_rDftMaxCluPed_C;                                     */
/*  input uint16 SftyMgt_rDftMinCluPed_C;                                     */
/*  output boolean SftyMgt_bDftSc_CluPed;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidCluDiag(void)
{
   uint16 u16LocalSftyMgt_rCluPedSen;
   uint32 u32LocalSftyMgt_rCluPedSen;
   uint32 u32LocalMaxCluPed;
   uint32 u32LocalMinCluPed;


   VEMS_vidGET(SftyMgt_rCluPedSen, u16LocalSftyMgt_rCluPedSen);
   u32LocalSftyMgt_rCluPedSen = u16LocalSftyMgt_rCluPedSen * 1000;
   u32LocalMaxCluPed = SftyMgt_rDftMaxCluPed_C * 1024;
   u32LocalMinCluPed = SftyMgt_rDftMinCluPed_C * 1024;

   if (  (u32LocalSftyMgt_rCluPedSen > u32LocalMaxCluPed)
      || (u32LocalSftyMgt_rCluPedSen < u32LocalMinCluPed))
   {
      SftyMgt_bDftSc_CluPed = 1;
   }
   else
   {
      SftyMgt_bDftSc_CluPed = 0;
   }

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidCluSecu                                    */
/* !Description :  Cette fonction décrit la sécurisation des diagnostiques    */
/*                 pour le Safety niveau 2 la pédale d’embrayage.             */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDftSc_CluPed;                                      */
/*  input uint8 SftyMgt_nUpTranThd_CluPedSc_C;                                */
/*  input uint8 SftyMgt_nDownTranThd_CluPedSc_C;                              */
/*  input uint8 SftyMgt_nInitCptConf_CluPedSc_C;                              */
/*  input uint8 SftyMgt_nDecCpt_CluPedSc_C;                                   */
/*  input uint8 DIAGSFTYLVL2_u8CntFilt_CluPed;                                */
/*  input boolean DIAGSFTYLVL2_bFilSig_CluPed;                                */
/*  input uint8 DIAGSFTYLVL2_u8CountNiv2_CluPed;                              */
/*  input boolean DIAGSFTYLVL2_bDgoNiv2_CluPed;                               */
/*  output boolean SftyMgt_bDftSftySc_CluPed;                                 */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_CluPed;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidCluSecu(void)
{
   LIBSFTYLVL2_U8_Safety_Level2(SftyMgt_bDftSc_CluPed,
                                SftyMgt_nUpTranThd_CluPedSc_C,
                                SftyMgt_nDownTranThd_CluPedSc_C,
                                SftyMgt_nInitCptConf_CluPedSc_C,
                                SftyMgt_nDecCpt_CluPedSc_C,
                                &DIAGSFTYLVL2_u8CntFilt_CluPed,
                                &DIAGSFTYLVL2_bFilSig_CluPed,
                                &DIAGSFTYLVL2_u8CountNiv2_CluPed,
                                &DIAGSFTYLVL2_bDgoNiv2_CluPed);

   VEMS_vidSET(SftyMgt_bDftSftySc_CluPed, DIAGSFTYLVL2_bDgoNiv2_CluPed);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidNeutPosDiagSftyLvl2                        */
/* !Description :  Cette fonction effectue les diagnostiques du niveau 2 pour */
/*                 la position point mort, qui se font en 2 étapes            */
/*                 :diagnostique et sécurisation des défauts                  */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGSFTYLVL2_vidNeutPosnDiag();                          */
/*  extf argret void DIAGSFTYLVL2_vidNeutPosnSecu();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidNeutPosDiagSftyLvl2(void)
{
   DIAGSFTYLVL2_vidNeutPosnDiag();
   DIAGSFTYLVL2_vidNeutPosnSecu();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidNeutPosnDiag                               */
/* !Description :  Cette fonction décrit les diagnostiques pour le Safety     */
/*                 niveau 2 pour la position point mort                       */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_rNeutSen;                                            */
/*  input uint16 SftyMgt_rDftMaxNeut_C;                                       */
/*  input uint16 SftyMgt_rDftMinNeut_C;                                       */
/*  output boolean SftyMgt_bDftSc_Neut;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidNeutPosnDiag(void)
{
   uint16 u16LocalSftyMgt_rNeutSen;


   VEMS_vidGET(SftyMgt_rNeutSen, u16LocalSftyMgt_rNeutSen);

   if (  (u16LocalSftyMgt_rNeutSen > SftyMgt_rDftMaxNeut_C)
      || (u16LocalSftyMgt_rNeutSen < SftyMgt_rDftMinNeut_C))
   {
      SftyMgt_bDftSc_Neut = 1;
   }
   else
   {
      SftyMgt_bDftSc_Neut = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidNeutPosnSecu                               */
/* !Description :  Cette fonction décrit la sécurisation des diagnostiques    */
/*                 pour le Safety niveau 2 la position point mort.            */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDftSc_Neut;                                        */
/*  input uint8 SftyMgt_nUpTranThd_NeutSc_C;                                  */
/*  input uint8 SftyMgt_nDownTranThd_NeutSc_C;                                */
/*  input uint8 SftyMgt_nInitCptConf_NeutSc_C;                                */
/*  input uint8 SftyMgt_nDecCpt_NeutSc_C;                                     */
/*  input uint8 DIAGSFTYLVL2_u8CntFilt_Neut;                                  */
/*  input boolean DIAGSFTYLVL2_bFilSig_Neut;                                  */
/*  input uint8 DIAGSFTYLVL2_u8CountNiv2_Neut;                                */
/*  input boolean DIAGSFTYLVL2_bDgoNiv2_Neut;                                 */
/*  output boolean SftyMgt_bDftSftySc_Neut;                                   */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_Neut;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidNeutPosnSecu(void)
{
   LIBSFTYLVL2_U8_Safety_Level2(SftyMgt_bDftSc_Neut,
                                SftyMgt_nUpTranThd_NeutSc_C,
                                SftyMgt_nDownTranThd_NeutSc_C,
                                SftyMgt_nInitCptConf_NeutSc_C,
                                SftyMgt_nDecCpt_NeutSc_C,
                                &DIAGSFTYLVL2_u8CntFilt_Neut,
                                &DIAGSFTYLVL2_bFilSig_Neut,
                                &DIAGSFTYLVL2_u8CountNiv2_Neut,
                                &DIAGSFTYLVL2_bDgoNiv2_Neut);

   VEMS_vidSET(SftyMgt_bDftSftySc_Neut, DIAGSFTYLVL2_bDgoNiv2_Neut);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidF34DTqCoh                                  */
/* !Description :  Le diagnostic de cohérence entre les paramètres teste les  */
/*                 configurations:ISCAN_u8N8F34DP047, ISCAN_u8N8F34DP043,     */
/*                 ISCAN_u8N8F34DP044 et ISCAN_u8N8F34DP045.                  */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 ISCAN_u8N3F34DP047;                                           */
/*  input uint8 ISCAN_u8N8F34DP045;                                           */
/*  input uint8 ISCAN_u8N8F34DP044;                                           */
/*  input uint8 ISCAN_u8N8F34DP043;                                           */
/*  output boolean SftyMgt_bDftTqCoh_F34D;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidF34DTqCoh(void)
{
   boolean bLocalSwitch;
   uint8   u8LocalISCAN_N3F34DP047;
   uint8   u8LocalISCAN_N8F34DP045;
   uint8   u8LocalISCAN_N8F34DP044;
   uint8   u8LocalISCAN_N8F34DP043;
   uint16  u16LocalISCAN_N8F34DP0453;
   uint16  u16LocalISCAN_N8F34DP0454;


   VEMS_vidGET(ISCAN_u8N3F34DP047, u8LocalISCAN_N3F34DP047);
   VEMS_vidGET(ISCAN_u8N8F34DP045, u8LocalISCAN_N8F34DP045);
   VEMS_vidGET(ISCAN_u8N8F34DP044, u8LocalISCAN_N8F34DP044);
   VEMS_vidGET(ISCAN_u8N8F34DP043, u8LocalISCAN_N8F34DP043);

   u16LocalISCAN_N8F34DP0453 =
      (uint16)(u8LocalISCAN_N8F34DP045 + u8LocalISCAN_N8F34DP043);
   u16LocalISCAN_N8F34DP0454 =
      (uint16)(u8LocalISCAN_N8F34DP045 + u8LocalISCAN_N8F34DP044);

   if (u8LocalISCAN_N3F34DP047 == 0)
   {
      if (  (u8LocalISCAN_N8F34DP045 != 0)
         || (u8LocalISCAN_N8F34DP044 != 250)
         || (u8LocalISCAN_N8F34DP043 != 250))
      {
         bLocalSwitch = 1;
      }
      else
      {
         bLocalSwitch = 0;
      }
   }
   else
   {
      if (u8LocalISCAN_N3F34DP047 == 5)
      {
         if (  (u8LocalISCAN_N8F34DP043 > 250)
            || (u8LocalISCAN_N8F34DP044 > 250)
            || (u16LocalISCAN_N8F34DP0453 != 255))
         {
            bLocalSwitch = 1;
         }
         else
         {
            bLocalSwitch = 0;
         }
      }
      else
      {
         if (u8LocalISCAN_N3F34DP047 == 6)
         {
            if (  (u8LocalISCAN_N8F34DP045 > 250)
               || (u16LocalISCAN_N8F34DP0454 != 255)
               || (u8LocalISCAN_N8F34DP043 != 250))
            {
               bLocalSwitch = 1;
            }
            else
            {
               bLocalSwitch = 0;
            }
         }
         else
         {
            bLocalSwitch = 1;
         }
      }
   }
   if (bLocalSwitch != 0)
   {
      SftyMgt_bDftTqCoh_F34D = 1;
   }
   else
   {
      SftyMgt_bDftTqCoh_F34D = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidReinitCounter                              */
/* !Description :  Cette fonction permet de reinitialiser la valeur du        */
/*                 compteur SftyMgt_tiCohSpdVehLvl2 à la valeur du calibration*/
/*                 SftyMgt_tiSpdVehInit_C.                                    */
/* !Number      :  FCT4.8                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 SftyMgt_tiSpdVehInit_C;                                       */
/*  output uint8 SftyMgt_tiCohSpdVehLvl2;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidReinitCounter(void)
{
   uint16 u16LocalSftyMgt_tiSpdVehInit;


   u16LocalSftyMgt_tiSpdVehInit = (uint16)((SftyMgt_tiSpdVehInit_C * 5) / 2);
   SftyMgt_tiCohSpdVehLvl2 =
      (uint8)MATHSRV_udtMIN(u16LocalSftyMgt_tiSpdVehInit, 50);

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidCalculcounter                              */
/* !Description :  Cette fonction permet de reconverger les entrées vitesse   */
/*                 roues vers des valeurs cohérentes.                         */
/* !Number      :  FCT4.9                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 SftyMgt_tiCohSpdVehLvl2;                                      */
/*  output uint8 SftyMgt_tiCohSpdVehLvl2;                                     */
/*  output boolean SftyMgt_bEndtiCohSpdVehLvl2;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidCalculcounter(void)
{
   uint8  u8LocalSftyMgt_tiCohSpdVehLvl2;
   sint16 s16LocalSftyMgt_tiCohSpdVehLvl2;


   s16LocalSftyMgt_tiCohSpdVehLvl2 = (sint16)(SftyMgt_tiCohSpdVehLvl2 - 1);
   u8LocalSftyMgt_tiCohSpdVehLvl2 =
      (uint8)MATHSRV_udtCLAMP(s16LocalSftyMgt_tiCohSpdVehLvl2, 0, 50);
   SftyMgt_tiCohSpdVehLvl2 = u8LocalSftyMgt_tiCohSpdVehLvl2;
   if (u8LocalSftyMgt_tiCohSpdVehLvl2 == 0)
   {
      SftyMgt_bEndtiCohSpdVehLvl2 = 1;
   }
   else
   {
      SftyMgt_bEndtiCohSpdVehLvl2 = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidInit                                       */
/* !Description :  Cette fonction permet d'initialiser les différents         */
/*                 compteurs temporels.                                       */
/* !Number      :  FCT4.10                                                    */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 SftyMgt_ticounterWkuMain_C;                                   */
/*  input uint8 SftyMgt_ticounterEngStrtReq_C;                                */
/*  input uint8 SftyMgt_ticounterBattMes_C;                                   */
/*  output uint8 SftyMgt_counterWkuMain;                                      */
/*  output uint8 SftyMgt_counterEngStrtReq;                                   */
/*  output uint8 SftyMgt_counterBattMes;                                      */
/*  output uint8 SftyMgt_tiCohSpdVehLvl2;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidInit(void)
{
   uint16 u16LocalSftyMgt_counterWkuMain;
   uint16 u16LocalSftyMgt_countEngStrtReq;
   uint16 u16LocalSftyMgt_counterBattMes;


   u16LocalSftyMgt_counterWkuMain =
      (uint16)((SftyMgt_ticounterWkuMain_C * 5) / 2);
   SftyMgt_counterWkuMain =
      (uint8)MATHSRV_udtMIN(u16LocalSftyMgt_counterWkuMain, 127);

   u16LocalSftyMgt_countEngStrtReq =
      (uint16)((SftyMgt_ticounterEngStrtReq_C * 5) / 2);
   SftyMgt_counterEngStrtReq =
      (uint8)MATHSRV_udtMIN(u16LocalSftyMgt_countEngStrtReq, 127);

   u16LocalSftyMgt_counterBattMes =
      (uint16)((SftyMgt_ticounterBattMes_C * 5) / 2);
   SftyMgt_counterBattMes =
      (uint8)MATHSRV_udtMIN(u16LocalSftyMgt_counterBattMes, 127);

   SftyMgt_tiCohSpdVehLvl2 = 0;
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*-------------------------------- end of file -------------------------------*/