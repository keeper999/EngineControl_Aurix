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
/* !File            : DIAGSFTYLVL2_FCT1.C                                     */
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
/*   1 / DIAGSFTYLVL2_vidInitOutput                                           */
/*   2 / DIAGSFTYLVL2_vidF329SftyLevel2                                       */
/*   3 / DIAGSFTYLVL2_vidF329Diag                                             */
/*   4 / DIAGSFTYLVL2_vidF329_ProcCnt                                         */
/*   5 / DIAGSFTYLVL2_vidF329Secu                                             */
/*   6 / DIAGSFTYLVL2_vidF349SftyLevel2                                       */
/*   7 / DIAGSFTYLVL2_vidF349Diag                                             */
/*   8 / DIAGSFTYLVL2_vidF349_ProcCnt                                         */
/*   9 / DIAGSFTYLVL2_vidF349Secu                                             */
/*   10 / DIAGSFTYLVL2_vidF34DSftyLevel2                                      */
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
/* !Function    :  DIAGSFTYLVL2_vidInitOutput                                 */
/* !Description :  Initialisation des variables.                              */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 SftyMgt_spdVehIniLvl2_C;                                     */
/*  output uint8 DIAGSFTYLVL2_u8F349P230Prev;                                 */
/*  output uint8 DIAGSFTYLVL2_u8F329P230bisPrev;                              */
/*  output uint8 DIAGSFTYLVL2_u8F34DP157Prev;                                 */
/*  output uint8 DIAGSFTYLVL2_u8EspProcMax_Prev;                              */
/*  output uint8 DIAGSFTYLVL2_u8F38DP606Prev;                                 */
/*  output boolean DIAGSFTYLVL2_bTimerInputPrev;                              */
/*  output uint8 DIAGSFTYLVL2_u8CntFilt_F329;                                 */
/*  output boolean DIAGSFTYLVL2_bFilSig_F329;                                 */
/*  output uint8 DIAGSFTYLVL2_u8CountNiv2_F329;                               */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_F329;                                */
/*  output uint8 DIAGSFTYLVL2_u8CntFilt_F349;                                 */
/*  output boolean DIAGSFTYLVL2_bFilSig_F349;                                 */
/*  output uint8 DIAGSFTYLVL2_u8CountNiv2_F349;                               */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_F349;                                */
/*  output uint8 DIAGSFTYLVL2_u8CntFilt_F34D;                                 */
/*  output boolean DIAGSFTYLVL2_bFilSig_F34D;                                 */
/*  output uint8 DIAGSFTYLVL2_u8CountNiv2_F34D;                               */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_F34D;                                */
/*  output uint8 DIAGSFTYLVL2_u8CntFilt_Coh;                                  */
/*  output boolean DIAGSFTYLVL2_bFilSig_Coh;                                  */
/*  output uint8 DIAGSFTYLVL2_u8CountNiv2_Coh;                                */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_Coh;                                 */
/*  output uint8 DIAGSFTYLVL2_u8CntFilt_F38D;                                 */
/*  output boolean DIAGSFTYLVL2_bFilSig_F38D;                                 */
/*  output uint8 DIAGSFTYLVL2_u8CountNiv2_F38D;                               */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_F38D;                                */
/*  output uint8 DIAGSFTYLVL2_u8CntFilt_AccP;                                 */
/*  output boolean DIAGSFTYLVL2_bFilSig_AccP;                                 */
/*  output uint8 DIAGSFTYLVL2_u8CountNiv2_AccP;                               */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_AccP;                                */
/*  output boolean DIAGSFTYLVL2_bTimeOut;                                     */
/*  output uint8 DIAGSFTYLVL2_u8CountTimer;                                   */
/*  output uint8 DIAGSFTYLVL2_u8CntFilt_BrkPed;                               */
/*  output boolean DIAGSFTYLVL2_bFilSig_BrkPed;                               */
/*  output uint8 DIAGSFTYLVL2_u8CountNiv2_BrkPed;                             */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_BrkPed;                              */
/*  output uint16 DIAGSFTYLVL2_u16N16F30DP263;                                */
/*  output uint16 DIAGSFTYLVL2_u16N16F30DP264;                                */
/*  output uint16 DIAGSFTYLVL2_u16N16F30DP265;                                */
/*  output uint16 DIAGSFTYLVL2_u16N16F30DP266;                                */
/*  output uint32 DIAGSFTYLVL2_u32N16F30DP263Mem;                             */
/*  output uint32 DIAGSFTYLVL2_u32N16F30DP264Mem;                             */
/*  output uint32 DIAGSFTYLVL2_u32N16F30DP265Mem;                             */
/*  output uint32 DIAGSFTYLVL2_u32N16F30DP266Mem;                             */
/*  output boolean DIAGSFTYLVL2_bPosHys;                                      */
/*  output boolean DIAGSFTYLVL2_bPosHys1;                                     */
/*  output boolean DIAGSFTYLVL2_bPosHys2;                                     */
/*  output boolean DIAGSFTYLVL2_bPosHys3;                                     */
/*  output boolean SftyMgt_bDftCoh_SpdVeh;                                    */
/*  output uint8 DIAGSFTYLVL2_u8CntFilt_VehSpd;                               */
/*  output boolean DIAGSFTYLVL2_bFilSig_VehSpd;                               */
/*  output uint8 DIAGSFTYLVL2_u8CountNiv2_VehSpd;                             */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_VehSpd;                              */
/*  output uint8 DIAGSFTYLVL2_u8CntFilt_Thr;                                  */
/*  output boolean DIAGSFTYLVL2_bFilSig_Thr;                                  */
/*  output uint8 DIAGSFTYLVL2_u8CountNiv2_Thr;                                */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_Thr;                                 */
/*  output uint8 DIAGSFTYLVL2_u8CntFilt_CluPed;                               */
/*  output boolean DIAGSFTYLVL2_bFilSig_CluPed;                               */
/*  output uint8 DIAGSFTYLVL2_u8CountNiv2_CluPed;                             */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_CluPed;                              */
/*  output uint8 DIAGSFTYLVL2_u8CntFilt_Neut;                                 */
/*  output boolean DIAGSFTYLVL2_bFilSig_Neut;                                 */
/*  output uint8 DIAGSFTYLVL2_u8CountNiv2_Neut;                               */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_Neut;                                */
/*  output boolean DIAGSFTYLVL2_bECUWkuMainPrev;                              */
/*  output boolean DIAGSFTYLVL2_bEngRStrtReqPrev;                             */
/*  output boolean DIAGSFTYLVL2_bSftyBattMesRanPrev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidInitOutput(void)
{
   uint16 u16LocalClc;
   uint32 u32LocalMem;


   /*Previous Variables*/
   DIAGSFTYLVL2_u8F349P230Prev = 0;
   DIAGSFTYLVL2_u8F329P230bisPrev = 0;
   DIAGSFTYLVL2_u8F34DP157Prev = 0;
   DIAGSFTYLVL2_u8EspProcMax_Prev = 0;
   DIAGSFTYLVL2_u8F38DP606Prev = 0;
   DIAGSFTYLVL2_bTimerInputPrev = 0;

   /*F02_F329Secu*/
   DIAGSFTYLVL2_u8CntFilt_F329 = 0;
   DIAGSFTYLVL2_bFilSig_F329 = 0;
   DIAGSFTYLVL2_u8CountNiv2_F329 = 0;
   DIAGSFTYLVL2_bDgoNiv2_F329 = 0;

   /*F02_F349Secu*/
   DIAGSFTYLVL2_u8CntFilt_F349 = 0;
   DIAGSFTYLVL2_bFilSig_F349 = 0;
   DIAGSFTYLVL2_u8CountNiv2_F349 = 0;
   DIAGSFTYLVL2_bDgoNiv2_F349 = 0;

   /*F02_F34DSecu*/
   DIAGSFTYLVL2_u8CntFilt_F34D = 0;
   DIAGSFTYLVL2_bFilSig_F34D = 0;
   DIAGSFTYLVL2_u8CountNiv2_F34D = 0;
   DIAGSFTYLVL2_bDgoNiv2_F34D = 0;
   DIAGSFTYLVL2_u8CntFilt_Coh = 0;
   DIAGSFTYLVL2_bFilSig_Coh = 0;
   DIAGSFTYLVL2_u8CountNiv2_Coh = 0;
   DIAGSFTYLVL2_bDgoNiv2_Coh = 0;

   /*F02_F38DSecu*/
   DIAGSFTYLVL2_u8CntFilt_F38D = 0;
   DIAGSFTYLVL2_bFilSig_F38D = 0;
   DIAGSFTYLVL2_u8CountNiv2_F38D = 0;
   DIAGSFTYLVL2_bDgoNiv2_F38D = 0;

   /*F02_AccPSecu*/
   DIAGSFTYLVL2_u8CntFilt_AccP = 0;
   DIAGSFTYLVL2_bFilSig_AccP = 0;
   DIAGSFTYLVL2_u8CountNiv2_AccP = 0;
   DIAGSFTYLVL2_bDgoNiv2_AccP = 0;

   /*F01_BrkDiag*/
   DIAGSFTYLVL2_bTimeOut = 0;
   DIAGSFTYLVL2_u8CountTimer = 0;

   /*F02_BrkSecu*/
   DIAGSFTYLVL2_u8CntFilt_BrkPed = 0;
   DIAGSFTYLVL2_bFilSig_BrkPed = 0;
   DIAGSFTYLVL2_u8CountNiv2_BrkPed = 0;
   DIAGSFTYLVL2_bDgoNiv2_BrkPed = 0;

   /*F01_VehSpdDiag*/
   u16LocalClc = (uint16)((SftyMgt_spdVehIniLvl2_C * 25) / 32);
   DIAGSFTYLVL2_u16N16F30DP263 = u16LocalClc;
   DIAGSFTYLVL2_u16N16F30DP264 = u16LocalClc;
   DIAGSFTYLVL2_u16N16F30DP265 = u16LocalClc;
   DIAGSFTYLVL2_u16N16F30DP266 = u16LocalClc;

   u32LocalMem = (uint32)(u16LocalClc * 65536);
   DIAGSFTYLVL2_u32N16F30DP263Mem = u32LocalMem;
   DIAGSFTYLVL2_u32N16F30DP264Mem = u32LocalMem;
   DIAGSFTYLVL2_u32N16F30DP265Mem = u32LocalMem;
   DIAGSFTYLVL2_u32N16F30DP266Mem = u32LocalMem;
   DIAGSFTYLVL2_bPosHys = 0;
   DIAGSFTYLVL2_bPosHys1 = 0;
   DIAGSFTYLVL2_bPosHys2 = 0;
   DIAGSFTYLVL2_bPosHys3 = 0;
   SftyMgt_bDftCoh_SpdVeh = 0;

   /*F02_VehSpdSecu*/
   DIAGSFTYLVL2_u8CntFilt_VehSpd = 0;
   DIAGSFTYLVL2_bFilSig_VehSpd = 0;
   DIAGSFTYLVL2_u8CountNiv2_VehSpd = 0;
   DIAGSFTYLVL2_bDgoNiv2_VehSpd = 0;

   /*F02_ThrSecu*/
   DIAGSFTYLVL2_u8CntFilt_Thr = 0;
   DIAGSFTYLVL2_bFilSig_Thr = 0;
   DIAGSFTYLVL2_u8CountNiv2_Thr = 0;
   DIAGSFTYLVL2_bDgoNiv2_Thr = 0;

   /*F02_CluSecu*/
   DIAGSFTYLVL2_u8CntFilt_CluPed = 0;
   DIAGSFTYLVL2_bFilSig_CluPed = 0;
   DIAGSFTYLVL2_u8CountNiv2_CluPed = 0;
   DIAGSFTYLVL2_bDgoNiv2_CluPed = 0;

   /*F02_NeutPosnSecu*/
   DIAGSFTYLVL2_u8CntFilt_Neut = 0;
   DIAGSFTYLVL2_bFilSig_Neut = 0;
   DIAGSFTYLVL2_u8CountNiv2_Neut = 0;
   DIAGSFTYLVL2_bDgoNiv2_Neut = 0;

   /*F01_ActivationDiagCanSftyNiv2*/
   DIAGSFTYLVL2_bECUWkuMainPrev = 0;
   DIAGSFTYLVL2_bEngRStrtReqPrev = 0;
   DIAGSFTYLVL2_bSftyBattMesRanPrev = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidF329SftyLevel2                             */
/* !Description :  Cette fonction fait les diagnostiques du niveau 2 pour la  */
/*                 Trame 329, qui se font en 2 étapes : Diagnostique et       */
/*                 Sécurisation des défauts                                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGSFTYLVL2_vidF329Diag();                              */
/*  extf argret void DIAGSFTYLVL2_vidF329Secu();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidF329SftyLevel2(void) /*F01_F329SftyLevel2*/
{
   DIAGSFTYLVL2_vidF329Diag();
   DIAGSFTYLVL2_vidF329Secu();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidF329Diag                                   */
/* !Description :  Cette fonction décrit les diagnostiques pour le Safety     */
/*                 niveau 2 pour la Trame 329 .                               */
/* !Number      :  FCT1.3                                                     */
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
/*  extf argret void DIAGSFTYLVL2_vidF329_ProcCnt();                          */
/*  input uint8 SftyMgt_F329MsgData[8];                                       */
/*  input uint8 SftyMgt_F329LocalLength;                                      */
/*  input uint8 Can_329ChkInit_C;                                             */
/*  output boolean SftyMgt_bDftCks_F329;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidF329Diag(void)/*F01_F329Diag*/
{
   boolean bLocalSecuChkOKF;
   uint8   u8LocalSecuResult;
   uint8   u8LocalF329LocalLength;
   uint8   au8LocalF329MsgData[8];
   /*QAC Msg(2:3132): No impact in the code*/

   VEMS_vidGET1DArray(SftyMgt_F329MsgData, 8, au8LocalF329MsgData);
   VEMS_vidGET(SftyMgt_F329LocalLength, u8LocalF329LocalLength);

   CanSecuChkData(Can_329ChkInit_C,
                  &au8LocalF329MsgData[0],
                  u8LocalF329LocalLength,
                  &u8LocalSecuResult,
                  &bLocalSecuChkOKF);

   if (bLocalSecuChkOKF != 0)
   {
      VEMS_vidSET(SftyMgt_bDftCks_F329, 0);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bDftCks_F329, 1);
   }

   DIAGSFTYLVL2_vidF329_ProcCnt();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidF329_ProcCnt                               */
/* !Description :  Ce bloc décrit les diagnostiques d’un défaut compteur du   */
/*                 processus pour la trame 329.                               */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 ISCAN_u8N4F329P230bis;                                        */
/*  input uint8 DIAGSFTYLVL2_u8F329P230bisPrev;                               */
/*  input uint8 SftyMgt_ctDftMinProcCntF329_C;                                */
/*  input uint8 SftyMgt_ctDftMaxProcCntF329_C;                                */
/*  output boolean SftyMgt_bDftProcCnt_F329;                                  */
/*  output uint8 DIAGSFTYLVL2_u8F329P230bisPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidF329_ProcCnt(void)
{
   uint8  u8LocalF329P230bis;
   sint16 s16LocalP230bis;


   VEMS_vidGET(ISCAN_u8N4F329P230bis, u8LocalF329P230bis);

   s16LocalP230bis =
      (sint16)(u8LocalF329P230bis - DIAGSFTYLVL2_u8F329P230bisPrev);

   if (s16LocalP230bis == 0)
   {
      SftyMgt_bDftProcCnt_F329 = 1;
   }
   else
   {
      if (s16LocalP230bis < 0)
      {
         s16LocalP230bis = (sint16)(s16LocalP230bis + 16);
      }

      if (  (s16LocalP230bis < SftyMgt_ctDftMinProcCntF329_C)
         || (s16LocalP230bis > SftyMgt_ctDftMaxProcCntF329_C))
      {
         SftyMgt_bDftProcCnt_F329 = 1;
      }
      else
      {
         SftyMgt_bDftProcCnt_F329 = 0;
      }
   }
   DIAGSFTYLVL2_u8F329P230bisPrev =
      (uint8)MATHSRV_udtMIN(u8LocalF329P230bis, 15);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidF329Secu                                   */
/* !Description :  Ce bloc décrit la sécurisation des diagnostiques pour le   */
/*                 Safety niveau 2 de la Trame 329                            */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDftProcCnt_F329;                                   */
/*  input uint8 SftyMgt_nUpThd_F329ProcFaild_C;                               */
/*  input uint8 SftyMgt_nDownThd_F329ProcFaild_C;                             */
/*  input uint8 SftyMgt_nInitCpt_F329ProcFaild_C;                             */
/*  input uint8 SftyMgt_nDecCpt_F329ProcFaild_C;                              */
/*  input uint8 DIAGSFTYLVL2_u8CntFilt_F329;                                  */
/*  input boolean DIAGSFTYLVL2_bFilSig_F329;                                  */
/*  input uint8 DIAGSFTYLVL2_u8CountNiv2_F329;                                */
/*  input boolean DIAGSFTYLVL2_bDgoNiv2_F329;                                 */
/*  output boolean SftyMgt_bDftSftyPrcFaild_F329;                             */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_F329;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidF329Secu(void)
{
   LIBSFTYLVL2_U8_Safety_Level2(SftyMgt_bDftProcCnt_F329,
                                SftyMgt_nUpThd_F329ProcFaild_C,
                                SftyMgt_nDownThd_F329ProcFaild_C,
                                SftyMgt_nInitCpt_F329ProcFaild_C,
                                SftyMgt_nDecCpt_F329ProcFaild_C,
                                &DIAGSFTYLVL2_u8CntFilt_F329,
                                &DIAGSFTYLVL2_bFilSig_F329,
                                &DIAGSFTYLVL2_u8CountNiv2_F329,
                                &DIAGSFTYLVL2_bDgoNiv2_F329);

   VEMS_vidSET(SftyMgt_bDftSftyPrcFaild_F329, DIAGSFTYLVL2_bDgoNiv2_F329);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidF349SftyLevel2                             */
/* !Description :  Cette fonction fait les diagnostiques du niveau 2 pour la  */
/*                 Trame 349, qui se font en 2 étapes : Diagnostique et       */
/*                 Sécurisation des défauts                                   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGSFTYLVL2_vidF349Diag();                              */
/*  extf argret void DIAGSFTYLVL2_vidF349Secu();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidF349SftyLevel2(void)
{
   DIAGSFTYLVL2_vidF349Diag();
   DIAGSFTYLVL2_vidF349Secu();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidF349Diag                                   */
/* !Description :  Cette fonction décrit les diagnostiques pour le Safety     */
/*                 niveau 2 pour la Trame 349                                 */
/* !Number      :  FCT1.7                                                     */
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
/*  extf argret void DIAGSFTYLVL2_vidF349_ProcCnt();                          */
/*  input uint8 SftyMgt_F349MsgData[8];                                       */
/*  input uint8 SftyMgt_F349LocalLength;                                      */
/*  input uint8 Can_349ChkInit_C;                                             */
/*  output boolean SftyMgt_bDftCks_F349;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidF349Diag(void)
{
   boolean bLocalSecuChkOKF;
   uint8   u8LocalSecuResult;
   uint8   u8LocalF349LocalLength;
   uint8   au8LocalF349MsgData[8];
   /*QAC Msg(2:3132): No impact in the code*/

   VEMS_vidGET1DArray(SftyMgt_F349MsgData, 8, au8LocalF349MsgData);
   VEMS_vidGET(SftyMgt_F349LocalLength, u8LocalF349LocalLength);

   CanSecuChkData(Can_349ChkInit_C,
                  &au8LocalF349MsgData[0],
                  u8LocalF349LocalLength,
                  &u8LocalSecuResult,
                  &bLocalSecuChkOKF);

   if (bLocalSecuChkOKF != 0)
   {
      VEMS_vidSET(SftyMgt_bDftCks_F349, 0);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bDftCks_F349, 1);
   }

   DIAGSFTYLVL2_vidF349_ProcCnt();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidF349_ProcCnt                               */
/* !Description :  Cette fonction décrit les diagnostiques d’un défaut        */
/*                 compteur du processus pour la trame 349                    */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 ISCAN_u8N4F349P230;                                           */
/*  input uint8 DIAGSFTYLVL2_u8F349P230Prev;                                  */
/*  input uint8 SftyMgt_ctDftMinProcCntF349_C;                                */
/*  input uint8 SftyMgt_ctDftMaxProcCntF349_C;                                */
/*  output boolean SftyMgt_bDftProcCnt_F349;                                  */
/*  output uint8 DIAGSFTYLVL2_u8F349P230Prev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidF349_ProcCnt(void)
{
   uint8  u8LocalF349P230;
   sint16 s16LocalP230;


   VEMS_vidGET(ISCAN_u8N4F349P230, u8LocalF349P230);

   s16LocalP230 =
      (sint16)(u8LocalF349P230 - DIAGSFTYLVL2_u8F349P230Prev);

   if (s16LocalP230 < 0)
   {
      s16LocalP230 = (sint16)(s16LocalP230 + 16);
   }

   if (  (s16LocalP230 < SftyMgt_ctDftMinProcCntF349_C)
      || (s16LocalP230 > SftyMgt_ctDftMaxProcCntF349_C))
   {
      SftyMgt_bDftProcCnt_F349 = 1;
   }
   else
   {
      SftyMgt_bDftProcCnt_F349 = 0;
   }
   DIAGSFTYLVL2_u8F349P230Prev = (uint8)MATHSRV_udtMIN(u8LocalF349P230, 15);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidF349Secu                                   */
/* !Description :  Cette fonction décrit la sécurisation des diagnostiques    */
/*                 pour le Safety niveau 2 de la Trame 349.                   */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDftProcCnt_F349;                                   */
/*  input uint8 SftyMgt_nUpThd_F349ProcFaild_C;                               */
/*  input uint8 SftyMgt_nDownThd_F349ProcFaild_C;                             */
/*  input uint8 SftyMgt_nInitCpt_F349ProcFaild_C;                             */
/*  input uint8 SftyMgt_nDecCpt_F349ProcFaild_C;                              */
/*  input uint8 DIAGSFTYLVL2_u8CntFilt_F349;                                  */
/*  input boolean DIAGSFTYLVL2_bFilSig_F349;                                  */
/*  input uint8 DIAGSFTYLVL2_u8CountNiv2_F349;                                */
/*  input boolean DIAGSFTYLVL2_bDgoNiv2_F349;                                 */
/*  output boolean SftyMgt_bDftSftyPrcFaild_F349;                             */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_F349;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidF349Secu(void)
{
   LIBSFTYLVL2_U8_Safety_Level2(SftyMgt_bDftProcCnt_F349,
                                SftyMgt_nUpThd_F349ProcFaild_C,
                                SftyMgt_nDownThd_F349ProcFaild_C,
                                SftyMgt_nInitCpt_F349ProcFaild_C,
                                SftyMgt_nDecCpt_F349ProcFaild_C,
                                &DIAGSFTYLVL2_u8CntFilt_F349,
                                &DIAGSFTYLVL2_bFilSig_F349,
                                &DIAGSFTYLVL2_u8CountNiv2_F349,
                                &DIAGSFTYLVL2_bDgoNiv2_F349);

   VEMS_vidSET(SftyMgt_bDftSftyPrcFaild_F349, DIAGSFTYLVL2_bDgoNiv2_F349);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidF34DSftyLevel2                             */
/* !Description :  Cette fonction fait les diagnostiques du niveau 2 pour la  */
/*                 Trame 34D, qui se font en 2 étapes : Diagnostique et       */
/*                 Sécurisation des défauts                                   */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGSFTYLVL2_vidF34DDiag();                              */
/*  extf argret void DIAGSFTYLVL2_vidF34DSecu();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidF34DSftyLevel2(void)
{
   DIAGSFTYLVL2_vidF34DDiag();
   DIAGSFTYLVL2_vidF34DSecu();
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"

/*-------------------------------- end of file -------------------------------*/