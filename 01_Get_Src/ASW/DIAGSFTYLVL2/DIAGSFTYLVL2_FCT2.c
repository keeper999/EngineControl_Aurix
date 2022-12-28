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
/* !File            : DIAGSFTYLVL2_FCT2.C                                     */
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
/*   1 / DIAGSFTYLVL2_vidF34DDiag                                             */
/*   2 / DIAGSFTYLVL2_vidF34D_ProcCnt                                         */
/*   3 / DIAGSFTYLVL2_vidF34DSecu                                             */
/*   4 / DIAGSFTYLVL2_vidF38DSftyLevel2                                       */
/*   5 / DIAGSFTYLVL2_vidF38DDiag                                             */
/*   6 / DIAGSFTYLVL2_vidF38D_ProcCnt                                         */
/*   7 / DIAGSFTYLVL2_vidF38DSecu                                             */
/*   8 / DIAGSFTYLVL2_vidSensDiagSftyLvl2                                     */
/*   9 / DIAGSFTYLVL2_vidAccPDiagSftyLvl2                                     */
/*   10 / DIAGSFTYLVL2_vidAccPDiag                                            */
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
#include "MATHSRV.h"
#include "DIAGSFTYLVL2.h"
#include "DIAGSFTYLVL2_L.h"
#include "DIAGSFTYLVL2_IM.h"
#include "CANSECUCHKDATA.h"
#include "LIBSFTYLVL2.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidF34DDiag                                   */
/* !Description :  Ce bloc décrit les diagnostiques pour le Safety niveau 2   */
/*                 pour la Trame 34D                                          */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  LDHI                                                       */
/* !Trace_To    :  VEMS_R_12_04117_01.01                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGSFTYLVL2_vidF34D_ProcCnt();                          */
/*  extf argret void DIAGSFTYLVL2_vidF34DTqCoh();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidF34DDiag(void)
{
   DIAGSFTYLVL2_vidF34D_ProcCnt();
   DIAGSFTYLVL2_vidF34DTqCoh();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidF34D_ProcCnt                               */
/* !Description :  Cette fonction décrit les diagnostiques d’un défaut        */
/*                 compteur du processus pour la trame 34D                    */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 ISCAN_u8N4F34DP157;                                           */
/*  input uint8 DIAGSFTYLVL2_u8F34DP157Prev;                                  */
/*  input uint8 SftyMgt_ctDftMinProcCntF34D_C;                                */
/*  input uint8 SftyMgt_ctDftMaxProcCntF34D_C;                                */
/*  input uint8 DIAGSFTYLVL2_u8EspProcMax_Prev;                               */
/*  input uint8 Esp_proc_false_max;                                           */
/*  output boolean SftyMgt_bDftProcCnt_F34D;                                  */
/*  output uint8 DIAGSFTYLVL2_u8EspProcMax_Prev;                              */
/*  output uint8 DIAGSFTYLVL2_u8F34DP157Prev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidF34D_ProcCnt(void)
{
   boolean bLocalProcCnt;
   uint8   u8LocalF34DP157;
   uint8   u8LocalEspProcMax;
   sint16  s16LocalP157;


   VEMS_vidGET(ISCAN_u8N4F34DP157, u8LocalF34DP157);

   s16LocalP157 = (sint16)(u8LocalF34DP157 - DIAGSFTYLVL2_u8F34DP157Prev);

   if (s16LocalP157 == 0)
   {
      bLocalProcCnt = 1;
   }
   else
   {
      if (s16LocalP157 < 0)
      {
         s16LocalP157 = (sint16)(s16LocalP157 + 16);
      }

      if (  (s16LocalP157 < SftyMgt_ctDftMinProcCntF34D_C)
         || (s16LocalP157 > SftyMgt_ctDftMaxProcCntF34D_C))
      {
         bLocalProcCnt = 1;
      }
      else
      {
         bLocalProcCnt = 0;
      }
   }

   if (bLocalProcCnt == 0)
   {
      SftyMgt_bDftProcCnt_F34D = 0;
      u8LocalEspProcMax = 0;
   }
   else
   {
      if (DIAGSFTYLVL2_u8EspProcMax_Prev == 255)
      {
         u8LocalEspProcMax = 255;
      }
      else
      {
         u8LocalEspProcMax = (uint8)(DIAGSFTYLVL2_u8EspProcMax_Prev + 1);
      }

      if (u8LocalEspProcMax > Esp_proc_false_max)
      {
         SftyMgt_bDftProcCnt_F34D = 1;
      }
      else
      {
         SftyMgt_bDftProcCnt_F34D = 0;
      }
   }

   DIAGSFTYLVL2_u8EspProcMax_Prev = u8LocalEspProcMax;
   DIAGSFTYLVL2_u8F34DP157Prev = (uint8)MATHSRV_udtMIN(u8LocalF34DP157, 15);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidF34DSecu                                   */
/* !Description :  Cette fonction décrit la sécurisation des diagnostiques    */
/*                 pour le Safety niveau 2 de la Trame 34D.                   */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDftProcCnt_F34D;                                   */
/*  input uint8 SftyMgt_nUpThd_F34DProcFaild_C;                               */
/*  input uint8 SftyMgt_nDownThd_F34DProcFaild_C;                             */
/*  input uint8 SftyMgt_nInitCpt_F34DProcFaild_C;                             */
/*  input uint8 SftyMgt_nDecCpt_F34DProcFaild_C;                              */
/*  input uint8 DIAGSFTYLVL2_u8CntFilt_F34D;                                  */
/*  input boolean DIAGSFTYLVL2_bFilSig_F34D;                                  */
/*  input uint8 DIAGSFTYLVL2_u8CountNiv2_F34D;                                */
/*  input boolean DIAGSFTYLVL2_bDgoNiv2_F34D;                                 */
/*  input boolean SftyMgt_bDftTqCoh_F34D;                                     */
/*  input uint8 SftyMgt_nUpThd_F34DTqCohFaild_C;                              */
/*  input uint8 SftyMgt_nDownThd_34DTqCohFaild_C;                             */
/*  input uint8 SftyMgt_nIniCpt_F34DTqCohFaild_C;                             */
/*  input uint8 SftyMgt_nDecCpt_F34DTqCohFaild_C;                             */
/*  input uint8 DIAGSFTYLVL2_u8CntFilt_Coh;                                   */
/*  input boolean DIAGSFTYLVL2_bFilSig_Coh;                                   */
/*  input uint8 DIAGSFTYLVL2_u8CountNiv2_Coh;                                 */
/*  input boolean DIAGSFTYLVL2_bDgoNiv2_Coh;                                  */
/*  output boolean SftyMgt_bDftSftyPrcFaild_F34D;                             */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_F34D;                                */
/*  output boolean SftyMgt_bDftSftyTqCoh_F34D;                                */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_Coh;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidF34DSecu(void)
{
   LIBSFTYLVL2_U8_Safety_Level2(SftyMgt_bDftProcCnt_F34D,
                                SftyMgt_nUpThd_F34DProcFaild_C,
                                SftyMgt_nDownThd_F34DProcFaild_C,
                                SftyMgt_nInitCpt_F34DProcFaild_C,
                                SftyMgt_nDecCpt_F34DProcFaild_C,
                                &DIAGSFTYLVL2_u8CntFilt_F34D,
                                &DIAGSFTYLVL2_bFilSig_F34D,
                                &DIAGSFTYLVL2_u8CountNiv2_F34D,
                                &DIAGSFTYLVL2_bDgoNiv2_F34D);

   VEMS_vidSET(SftyMgt_bDftSftyPrcFaild_F34D, DIAGSFTYLVL2_bDgoNiv2_F34D);

   LIBSFTYLVL2_U8_Safety_Level2(SftyMgt_bDftTqCoh_F34D,
                                SftyMgt_nUpThd_F34DTqCohFaild_C,
                                SftyMgt_nDownThd_34DTqCohFaild_C,
                                SftyMgt_nIniCpt_F34DTqCohFaild_C,
                                SftyMgt_nDecCpt_F34DTqCohFaild_C,
                                &DIAGSFTYLVL2_u8CntFilt_Coh,
                                &DIAGSFTYLVL2_bFilSig_Coh,
                                &DIAGSFTYLVL2_u8CountNiv2_Coh,
                                &DIAGSFTYLVL2_bDgoNiv2_Coh);

   VEMS_vidSET(SftyMgt_bDftSftyTqCoh_F34D, DIAGSFTYLVL2_bDgoNiv2_Coh);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidF38DSftyLevel2                             */
/* !Description :  Cette fonction fait les diagnostiques du niveau 2 pour la  */
/*                 Trame 38D, qui se font en 2 étapes : Diagnostique et       */
/*                 Sécurisation des défauts                                   */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGSFTYLVL2_vidF38DDiag();                              */
/*  extf argret void DIAGSFTYLVL2_vidF38DSecu();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidF38DSftyLevel2(void)
{
   DIAGSFTYLVL2_vidF38DDiag();
   DIAGSFTYLVL2_vidF38DSecu();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidF38DDiag                                   */
/* !Description :  Cette fonctiondécrit les diagnostiques pour le Safety      */
/*                 niveau 2 pour la Trame 38D.                                */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CanSecuChkData(argin uint8 CHKini, argin const uint8     */
/* DataFrame[], argin uint8 Size, argout uint8 *Result, argout boolean        */
/* *Chk_ok);                                                                  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void DIAGSFTYLVL2_vidF38D_ProcCnt();                          */
/*  input uint8 SftyMgt_F38DMsgData[8];                                       */
/*  input uint8 SftyMgt_F38DLocalLength;                                      */
/*  input uint8 Can_38DChkInit_C;                                             */
/*  output boolean SftyMgt_bDftCks_F38D;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidF38DDiag(void)
{
   boolean bLocalSecuChkOKF;
   uint8   u8LocalSecuResult;
   uint8   u8LocalF38DLocalLength;
   uint8   au8LocalF38DMsgData[8];
   /*QAC Msg(2:3132): No impact in the code*/

   VEMS_vidGET1DArray(SftyMgt_F38DMsgData, 8, au8LocalF38DMsgData);
   VEMS_vidGET(SftyMgt_F38DLocalLength, u8LocalF38DLocalLength);
   CanSecuChkData(Can_38DChkInit_C,
                  &au8LocalF38DMsgData[0],
                  u8LocalF38DLocalLength,
                  &u8LocalSecuResult,
                  &bLocalSecuChkOKF);

   if (bLocalSecuChkOKF != 0)
   {
      VEMS_vidSET(SftyMgt_bDftCks_F38D, 0);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bDftCks_F38D, 1);
   }

   DIAGSFTYLVL2_vidF38D_ProcCnt();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidF38D_ProcCnt                               */
/* !Description :  Cette fonction décrit les diagnostiques d’un défaut        */
/*                 compteur du processus pour la trame 38D                    */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 ISCAN_u8N4F38DP606;                                           */
/*  input uint8 DIAGSFTYLVL2_u8F38DP606Prev;                                  */
/*  input uint8 SftyMgt_ctDftMinProcCntF38D_C;                                */
/*  input uint8 SftyMgt_ctDftMaxProcCntF38D_C;                                */
/*  output boolean SftyMgt_bDftProcCnt_F38D;                                  */
/*  output uint8 DIAGSFTYLVL2_u8F38DP606Prev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidF38D_ProcCnt(void)
{
   uint8  u8LocalF38DP606;
   sint16 s16LocalP606;


   VEMS_vidGET(ISCAN_u8N4F38DP606, u8LocalF38DP606);

   s16LocalP606 =
      (sint16)(u8LocalF38DP606 - DIAGSFTYLVL2_u8F38DP606Prev);

   if (s16LocalP606 < 0)
   {
      s16LocalP606 = (sint16)(s16LocalP606 + 16);
   }

   if (  (s16LocalP606 < SftyMgt_ctDftMinProcCntF38D_C)
      || (s16LocalP606 > SftyMgt_ctDftMaxProcCntF38D_C))
   {
      SftyMgt_bDftProcCnt_F38D = 1;
   }
   else
   {
      SftyMgt_bDftProcCnt_F38D = 0;
   }
   DIAGSFTYLVL2_u8F38DP606Prev = (uint8)MATHSRV_udtMIN(u8LocalF38DP606, 15);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidF38DSecu                                   */
/* !Description :  Cette fonction décrit la sécurisation des diagnostiques    */
/*                 pour le Safety niveau 2 de la Trame 38D                    */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDftProcCnt_F38D;                                   */
/*  input uint8 SftyMgt_nUpThd_F38DProcFaild_C;                               */
/*  input uint8 SftyMgt_nDownThd_F38DProcFaild_C;                             */
/*  input uint8 SftyMgt_nInitCpt_F38DProcFaild_C;                             */
/*  input uint8 SftyMgt_nDecCpt_F38DProcFaild_C;                              */
/*  input uint8 DIAGSFTYLVL2_u8CntFilt_F38D;                                  */
/*  input boolean DIAGSFTYLVL2_bFilSig_F38D;                                  */
/*  input uint8 DIAGSFTYLVL2_u8CountNiv2_F38D;                                */
/*  input boolean DIAGSFTYLVL2_bDgoNiv2_F38D;                                 */
/*  output boolean SftyMgt_bDftSftyPrcFaild_F38D;                             */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_F38D;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidF38DSecu(void)
{
   LIBSFTYLVL2_U8_Safety_Level2(SftyMgt_bDftProcCnt_F38D,
                                SftyMgt_nUpThd_F38DProcFaild_C,
                                SftyMgt_nDownThd_F38DProcFaild_C,
                                SftyMgt_nInitCpt_F38DProcFaild_C,
                                SftyMgt_nDecCpt_F38DProcFaild_C,
                                &DIAGSFTYLVL2_u8CntFilt_F38D,
                                &DIAGSFTYLVL2_bFilSig_F38D,
                                &DIAGSFTYLVL2_u8CountNiv2_F38D,
                                &DIAGSFTYLVL2_bDgoNiv2_F38D);

   VEMS_vidSET(SftyMgt_bDftSftyPrcFaild_F38D, DIAGSFTYLVL2_bDgoNiv2_F38D);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidSensDiagSftyLvl2                           */
/* !Description :  Cette fonction décrit les diagnostiques pour le Safety     */
/*                 niveau 2 pour les capteurs Pédale d'accélération, Pédale de*/
/*                 frein, Vitesse Véhicule, Papillon, Pédale d'embrayage et   */
/*                 Position Point Mort.                                       */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGSFTYLVL2_vidAccPDiagSftyLvl2();                      */
/*  extf argret void DIAGSFTYLVL2_vidThrDiagSftyLvl2();                       */
/*  extf argret void DIAGSFTYLVL2_vidBrkDiagSftyLvl2();                       */
/*  extf argret void DIAGSFTYLVL2_vidCluDiagSftyLvl2();                       */
/*  extf argret void DIAGSFTYLVL2_vidVehSpdDiagSftyLvl2();                    */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIAGSFTYLVL2_vidNeutPosDiagSftyLvl2();                   */
/*  input boolean Ext_bAcv_AccPSftyLvl2_C;                                    */
/*  input boolean Ext_bAcv_ThrSftyLvl2_C;                                     */
/*  input boolean Ext_bAcv_BrkSftyLvl2_C;                                     */
/*  input boolean Ext_bAcv_CluSftyLvl2_C;                                     */
/*  input boolean Ext_bAcv_VehSpdSftyLvl2_C;                                  */
/*  input boolean Gear_bAcvNeutPosnAcq;                                       */
/*  input boolean Ext_bAcv_NeutPosSftyLvl2_C;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidSensDiagSftyLvl2(void)
{
   boolean bLocalGear_bAcvNeutPosnAcq;


   if (Ext_bAcv_AccPSftyLvl2_C != 0)
   {
      DIAGSFTYLVL2_vidAccPDiagSftyLvl2();
   }

   if (Ext_bAcv_ThrSftyLvl2_C != 0)
   {
      DIAGSFTYLVL2_vidThrDiagSftyLvl2();
   }

   if (Ext_bAcv_BrkSftyLvl2_C != 0)
   {
      DIAGSFTYLVL2_vidBrkDiagSftyLvl2();
   }

   if (Ext_bAcv_CluSftyLvl2_C != 0)
   {
      DIAGSFTYLVL2_vidCluDiagSftyLvl2();
   }

   if (Ext_bAcv_VehSpdSftyLvl2_C != 0)
   {
      DIAGSFTYLVL2_vidVehSpdDiagSftyLvl2();
   }

   VEMS_vidGET(Gear_bAcvNeutPosnAcq, bLocalGear_bAcvNeutPosnAcq);
   if (  (bLocalGear_bAcvNeutPosnAcq != 0)
      && (Ext_bAcv_NeutPosSftyLvl2_C != 0))
   {
      DIAGSFTYLVL2_vidNeutPosDiagSftyLvl2();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidAccPDiagSftyLvl2                           */
/* !Description :  Cette fonction effectue les diagnostiques du niveau 2 pour */
/*                 la pédale accélération, qui se font en 2 étapes :          */
/*                 diagnostique et sécurisation des défauts                   */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGSFTYLVL2_vidAccPDiag();                              */
/*  extf argret void DIAGSFTYLVL2_vidAccPSecu();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidAccPDiagSftyLvl2(void)
{
   DIAGSFTYLVL2_vidAccPDiag();
   DIAGSFTYLVL2_vidAccPSecu();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidAccPDiag                                   */
/* !Description :  Cette fonction décrit les diagnostiques pour le Safety     */
/*                 niveau 2 pour la pédale d'accélération.                    */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_uAccPSen1;                                           */
/*  input uint16 SftyMgt_uAccPSen2;                                           */
/*  input uint16 SftyMgt_uAccPCohMax_C;                                       */
/*  output boolean SftyMgt_bDftCoh_AccP;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidAccPDiag(void)
{
   uint16  u16LocalAccPSen1;
   uint16  u16LocalAccPSen2;
   uint32  u32LocalMulAccPSen2;
   sint32  s32LocalCalcAccPSen;

   VEMS_vidGET(SftyMgt_uAccPSen1, u16LocalAccPSen1);
   VEMS_vidGET(SftyMgt_uAccPSen2, u16LocalAccPSen2);

   u32LocalMulAccPSen2 = (uint32)(u16LocalAccPSen2 * 2);
   s32LocalCalcAccPSen =
      (sint32)((uint32)(u16LocalAccPSen1) - u32LocalMulAccPSen2);

   u32LocalMulAccPSen2 = (uint32)MATHSRV_udtABS(s32LocalCalcAccPSen);
   /*QAC Msg(3:3356): All cases are covered in the unit test*/

   if (u32LocalMulAccPSen2 > SftyMgt_uAccPCohMax_C)
   {
      SftyMgt_bDftCoh_AccP = 1;
   }
   else
   {
      SftyMgt_bDftCoh_AccP = 0;
   }
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"

/*-------------------------------- end of file -------------------------------*/