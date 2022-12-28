/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COHCAN                                                  */
/* !Description     : COHCAN Component                                        */
/*                                                                            */
/* !Module          : COHCAN                                                  */
/* !Description     : COHERENCE CAN INFOS_EOBD_BSI                            */
/*                                                                            */
/* !File            : COHCAN_FCT1.C                                           */
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
/*   1 / COHCAN_vidInitOutput                                                 */
/*   2 / COHCAN_vidDiagOBD1                                                   */
/*   3 / COHCAN_vidWindowOBD                                                  */
/*   4 / COHCAN_vidDiagOBD2                                                   */
/*   5 / COHCAN_vidDiagBattSys                                                */
/*   6 / COHCAN_vidWindowChkBattSys                                           */
/*   7 / COHCAN_vidDiagChkBattSys                                             */
/*   8 / COHCAN_vidDiagModSpd_FuLvl                                           */
/*   9 / COHCAN_vidWindowModSpt_FuLvl                                         */
/*   10 / COHCAN_vidDiagModSptReq                                             */
/*                                                                            */
/* !Reference   : V02 NT 12 00919 / 02                                        */
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
#include "COHCAN.h"
#include "COHCAN_L.h"
#include "COHCAN_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COHCAN_vidInitOutput                                       */
/* !Description :  Initialisation des variables                               */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Ext_bDgoCohBit2_stDftOBD;                                  */
/*  output boolean Ext_bDgoCohBit3_stDftOBD;                                  */
/*  output boolean Ext_bDgoCohBit4_stDftOBD;                                  */
/*  output boolean Ext_bDgoCohBit7_stDftOBD;                                  */
/*  output boolean Ext_bDgoChkBattSys_iBattMes;                               */
/*  output boolean Ext_bDgoChkBattSys_tBattMes;                               */
/*  output boolean Ext_bDgoChkBattSys_uBattClc;                               */
/*  output boolean Ext_bDgoStFuLvlDft;                                        */
/*  output boolean Ext_bDgoCoh_bModSptReq;                                    */
/*  output boolean Ext_bDgoCoh_stCluAC;                                       */
/*  output boolean Ext_bDgoCoh_stPwrAC;                                       */
/*  output uint8 Ext_tiACClu;                                                 */
/*  output boolean COHCAN_bTimeOut;                                           */
/*  output boolean COHCAN_bAC_bACClu_prev;                                    */
/*  output boolean COHCAN_bTimerInit_prev;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COHCAN_vidInitOutput(void)
{
   Ext_bDgoCohBit2_stDftOBD = 0;
   Ext_bDgoCohBit3_stDftOBD = 0;
   Ext_bDgoCohBit4_stDftOBD = 0;
   Ext_bDgoCohBit7_stDftOBD = 0;
   Ext_bDgoChkBattSys_iBattMes = 0;
   Ext_bDgoChkBattSys_tBattMes = 0;
   Ext_bDgoChkBattSys_uBattClc = 0;
   Ext_bDgoStFuLvlDft = 0;
   Ext_bDgoCoh_bModSptReq = 0;
   Ext_bDgoCoh_stCluAC = 0;
   Ext_bDgoCoh_stPwrAC = 0;
   Ext_tiACClu = 0;
   COHCAN_bTimeOut = 0;
   COHCAN_bAC_bACClu_prev = 0;
   COHCAN_bTimerInit_prev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COHCAN_vidDiagOBD1                                         */
/* !Description :  Cette fonction, appelée sur réception de la trame 5B2 et   */
/*                 7F2, spécifie les conditions d’activation ainsi que        */
/*                 l’activation elle-même, du diagnostic de cohérence         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COHCAN_vidWindowOBD();                                   */
/*  extf argret void COHCAN_vidDiagOBD2();                                    */
/*  input boolean Ext_bMonRunCoh_stDftOBD;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COHCAN_vidDiagOBD1(void)
{
   COHCAN_vidWindowOBD();
   if (Ext_bMonRunCoh_stDftOBD != 0)
   {
      COHCAN_vidDiagOBD2();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COHCAN_vidWindowOBD                                        */
/* !Description :  Le moniteur de diagnostic OBD                              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean UCE_bWkuMain;                                               */
/*  output boolean Ext_bMonRunCoh_stDftOBD;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COHCAN_vidWindowOBD(void)
{
   boolean bLocalUCE_bWkuMain;
   boolean bLocalInhDiag_stDftOBD;


   VEMS_vidGET(UCE_bWkuMain, bLocalUCE_bWkuMain);
   bLocalInhDiag_stDftOBD = GDGAR_bGetFRM(FRM_FRM_INHDIAG_STDFTOBD);

   if (  (bLocalUCE_bWkuMain != 0)
      && (bLocalInhDiag_stDftOBD == 0))
   {
      Ext_bMonRunCoh_stDftOBD = 1;
   }
   else
   {
      Ext_bMonRunCoh_stDftOBD = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COHCAN_vidDiagOBD2                                         */
/* !Description :  Cette sous fonction réalise le diagnostic OBD              */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoRegVeh_stDftOBD;                                            */
/*  input boolean Ext_bCfDiagBit7StDftOBD;                                    */
/*  input boolean Ext_bCfDiagBit4StDftOBD;                                    */
/*  input boolean Ext_bCfDiagBit3StDftOBD;                                    */
/*  input boolean Ext_bCfDiagBit2StDftOBD;                                    */
/*  output boolean Ext_bDgoCohBit7_stDftOBD;                                  */
/*  output boolean Ext_bDgoCohBit4_stDftOBD;                                  */
/*  output boolean Ext_bDgoCohBit3_stDftOBD;                                  */
/*  output boolean Ext_bDgoCohBit2_stDftOBD;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COHCAN_vidDiagOBD2(void)
{
   boolean bLocalExt_bCfDiagBit7StDftOBD;
   boolean bLocalExt_bCfDiagBit4StDftOBD;
   boolean bLocalExt_bCfDiagBit3StDftOBD;
   boolean bLocalExt_bCfDiagBit2StDftOBD;
   uint8   u8LocalMaskResult;
   uint8   u8LocalCoRegVeh_stDftOBD;


   VEMS_vidGET(CoRegVeh_stDftOBD, u8LocalCoRegVeh_stDftOBD);
   VEMS_vidGET(Ext_bCfDiagBit7StDftOBD, bLocalExt_bCfDiagBit7StDftOBD);
   VEMS_vidGET(Ext_bCfDiagBit4StDftOBD, bLocalExt_bCfDiagBit4StDftOBD);
   VEMS_vidGET(Ext_bCfDiagBit3StDftOBD, bLocalExt_bCfDiagBit3StDftOBD);
   VEMS_vidGET(Ext_bCfDiagBit2StDftOBD, bLocalExt_bCfDiagBit2StDftOBD);


   u8LocalMaskResult = (uint8)(u8LocalCoRegVeh_stDftOBD & 0x80);
   if (  (bLocalExt_bCfDiagBit7StDftOBD != 0)
      && (u8LocalMaskResult == 0x80))
   {
      Ext_bDgoCohBit7_stDftOBD = 1;
   }
   else
   {
      Ext_bDgoCohBit7_stDftOBD = 0;
   }


   u8LocalMaskResult = (uint8)(u8LocalCoRegVeh_stDftOBD & 0x10);
   if (  (bLocalExt_bCfDiagBit4StDftOBD != 0)
      && (u8LocalMaskResult == 0x10))
   {
      Ext_bDgoCohBit4_stDftOBD = 1;
   }
   else
   {
      Ext_bDgoCohBit4_stDftOBD = 0;
   }


   u8LocalMaskResult = (uint8)(u8LocalCoRegVeh_stDftOBD & 0x08);
   if (  (bLocalExt_bCfDiagBit3StDftOBD != 0)
      && (u8LocalMaskResult == 0x08))
   {
      Ext_bDgoCohBit3_stDftOBD = 1;
   }
   else
   {
      Ext_bDgoCohBit3_stDftOBD = 0;
   }


   u8LocalMaskResult = (uint8)(u8LocalCoRegVeh_stDftOBD & 0x04);
   if (  (bLocalExt_bCfDiagBit2StDftOBD != 0)
      && (u8LocalMaskResult == 0x04))
   {
      Ext_bDgoCohBit2_stDftOBD = 1;
   }
   else
   {
      Ext_bDgoCohBit2_stDftOBD = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COHCAN_vidDiagBattSys                                      */
/* !Description :  Cette fonction, appelée sur réception de la trame 572,     */
/*                 spécifie les conditions d’activation ainsi que l’activation*/
/*                 elle-même, du diagnostic de cohérence.                     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COHCAN_vidWindowChkBattSys();                            */
/*  extf argret void COHCAN_vidDiagChkBattSys();                              */
/*  input boolean Ext_bMonRunChkBattSys;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COHCAN_vidDiagBattSys(void)
{
   COHCAN_vidWindowChkBattSys();
   if (Ext_bMonRunChkBattSys != 0)
   {
      COHCAN_vidDiagChkBattSys();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COHCAN_vidWindowChkBattSys                                 */
/* !Description :  Le moniteur de diagnostic de la batterie                   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean UCE_bWkuMain;                                               */
/*  output boolean Ext_bMonRunChkBattSys;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COHCAN_vidWindowChkBattSys(void)
{
   boolean bLocalUCE_bWkuMain;
   boolean bLocalInhDiagChkBattSys;


   VEMS_vidGET(UCE_bWkuMain, bLocalUCE_bWkuMain);
   bLocalInhDiagChkBattSys = GDGAR_bGetFRM(FRM_FRM_INHDIAGCHKBATTSYS);

   if (  (bLocalUCE_bWkuMain != 0)
      && (bLocalInhDiagChkBattSys == 0))
   {
      Ext_bMonRunChkBattSys = 1;
   }
   else
   {
      Ext_bMonRunChkBattSys = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COHCAN_vidDiagChkBattSys                                   */
/* !Description :  Cette sous fonction réalise le diagnostic de la batterie   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bDgo_iBattMes;                                          */
/*  input boolean Ext_bDgo_tBattMes;                                          */
/*  input boolean Ext_bDgo_uBattClc;                                          */
/*  output boolean Ext_bDgoChkBattSys_iBattMes;                               */
/*  output boolean Ext_bDgoChkBattSys_tBattMes;                               */
/*  output boolean Ext_bDgoChkBattSys_uBattClc;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COHCAN_vidDiagChkBattSys(void)
{
   boolean bLocalExt_bDgo_iBattMes;
   boolean bLocalExt_bDgo_tBattMes;
   boolean bLocalExt_bDgo_uBattClc;


   VEMS_vidGET(Ext_bDgo_iBattMes, bLocalExt_bDgo_iBattMes);
   VEMS_vidGET(Ext_bDgo_tBattMes, bLocalExt_bDgo_tBattMes);
   VEMS_vidGET(Ext_bDgo_uBattClc, bLocalExt_bDgo_uBattClc);

   Ext_bDgoChkBattSys_iBattMes = bLocalExt_bDgo_iBattMes;
   Ext_bDgoChkBattSys_tBattMes = bLocalExt_bDgo_tBattMes;
   Ext_bDgoChkBattSys_uBattClc = bLocalExt_bDgo_uBattClc;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COHCAN_vidDiagModSpd_FuLvl                                 */
/* !Description :  Cette fonction, appelée sur réception de la trame 412,     */
/*                 spécifie les conditions d’activation ainsi que l’activation*/
/*                 elle-même, du diagnostic de cohérence.                     */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COHCAN_vidWindowModSpt_FuLvl();                          */
/*  extf argret void COHCAN_vidDiagModSptReq();                               */
/*  extf argret void COHCAN_vidDiagFuLvlDft();                                */
/*  input boolean Ext_bMonRunCoh_bModSptReq;                                  */
/*  input boolean Ext_bMonRunStFuLvlDft;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COHCAN_vidDiagModSpd_FuLvl(void)
{
   COHCAN_vidWindowModSpt_FuLvl();

   if (Ext_bMonRunCoh_bModSptReq != 0)
   {
      COHCAN_vidDiagModSptReq();
   }

   if (Ext_bMonRunStFuLvlDft != 0)
   {
      COHCAN_vidDiagFuLvlDft();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COHCAN_vidWindowModSpt_FuLvl                               */
/* !Description :  Le moniteur de diagnostic fuel low et de la fonction       */
/*                 d’activation                                               */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean UCE_bWkuMain;                                               */
/*  output boolean Ext_bMonRunStFuLvlDft;                                     */
/*  output boolean Ext_bMonRunCoh_bModSptReq;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COHCAN_vidWindowModSpt_FuLvl(void)
{
   boolean bLocalUCE_bWkuMain;
   boolean bLocalInhDiag_stFuLvlDft;
   boolean bLocalInhDiag_bModSptReq;



   Ext_bMonRunStFuLvlDft = 0;
   Ext_bMonRunCoh_bModSptReq = 0;

   VEMS_vidGET(UCE_bWkuMain, bLocalUCE_bWkuMain);
   if (bLocalUCE_bWkuMain != 0)
   {
      bLocalInhDiag_stFuLvlDft = GDGAR_bGetFRM(FRM_FRM_INHDIAG_STFULVLDFT);
      bLocalInhDiag_bModSptReq = GDGAR_bGetFRM(FRM_FRM_INHDIAG_BMODSPTREQ);
      if (bLocalInhDiag_stFuLvlDft == 0)
      {
         Ext_bMonRunStFuLvlDft = 1;
      }
      if (bLocalInhDiag_bModSptReq == 0)
      {
         Ext_bMonRunCoh_bModSptReq = 1;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COHCAN_vidDiagModSptReq                                    */
/* !Description :  Cette sous fonction réalise le diagnostic de la fonction   */
/*                 d’activation                                               */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bModSptReq;                                             */
/*  input boolean Ext_bDynFctAcvCplm;                                         */
/*  output boolean Ext_bDgoCoh_bModSptReq;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COHCAN_vidDiagModSptReq(void)
{
   boolean bLocalExt_bModSptReq;
   boolean bLocalExt_bDynFctAcvCplm;


   VEMS_vidGET(Ext_bModSptReq, bLocalExt_bModSptReq);
   VEMS_vidGET(Ext_bDynFctAcvCplm, bLocalExt_bDynFctAcvCplm);

   if (bLocalExt_bModSptReq == bLocalExt_bDynFctAcvCplm)
   {
      Ext_bDgoCoh_bModSptReq = 1;
   }
   else
   {
      Ext_bDgoCoh_bModSptReq = 0;
   }
}
/*----------------------------------end of file-------------------------------*/