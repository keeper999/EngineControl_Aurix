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
/* !File            : DIAGSFTYLVL2_FCT5.C                                     */
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
/*   1 / DIAGSFTYLVL2_vidActDiagCanSftyL2                                     */
/*   2 / DIAGSFTYLVL2_vidActDiagCanSftyNv                                     */
/*   3 / DIAGSFTYLVL2_vidReinitCounter1                                       */
/*   4 / DIAGSFTYLVL2_vidReinitCounter2                                       */
/*   5 / DIAGSFTYLVL2_vidReinitCounter3                                       */
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
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidActDiagCanSftyL2                           */
/* !Description :  Cette fonction permet d'activater le diagnostic CAN Safety */
/*                 level 2.                                                   */
/* !Number      :  FCT5.1                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGSFTYLVL2_vidActDiagCanSftyNv();                      */
/*  input uint8 SftyMgt_counterWkuMain;                                       */
/*  input uint8 SftyMgt_counterEngStrtReq;                                    */
/*  input uint8 SftyMgt_counterBattMes;                                       */
/*  output uint8 SftyMgt_counterWkuMain;                                      */
/*  output uint8 SftyMgt_counterEngStrtReq;                                   */
/*  output uint8 SftyMgt_counterBattMes;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidActDiagCanSftyL2(void)
{
   uint16 u16LocalSftyMgt_counterWkuMain;
   uint16 u16LocalSftyMgt_countEngStrtReq;
   uint16 u16LocalSftyMgt_counterBattMes;


   DIAGSFTYLVL2_vidActDiagCanSftyNv();

   u16LocalSftyMgt_counterWkuMain = (uint16)(SftyMgt_counterWkuMain + 1);
   SftyMgt_counterWkuMain =
      (uint8)MATHSRV_udtMIN(u16LocalSftyMgt_counterWkuMain, 127);

   u16LocalSftyMgt_countEngStrtReq = (uint16)(SftyMgt_counterEngStrtReq + 1);
   SftyMgt_counterEngStrtReq =
      (uint8)MATHSRV_udtMIN(u16LocalSftyMgt_countEngStrtReq, 127);

   u16LocalSftyMgt_counterBattMes = (uint16)(SftyMgt_counterBattMes + 1);
   SftyMgt_counterBattMes =
      (uint8)MATHSRV_udtMIN(u16LocalSftyMgt_counterBattMes, 127);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidActDiagCanSftyNv                           */
/* !Description :  Cette fonction permet d'activer le diagnostic CAN safety   */
/*                 niveau 2.                                                  */
/* !Number      :  FCT5.2                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIAGSFTYLVL2_vidReinitCounter1();                        */
/*  extf argret void DIAGSFTYLVL2_vidReinitCounter2();                        */
/*  extf argret void DIAGSFTYLVL2_vidReinitCounter3();                        */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean CoPtUH_bEngRStrtReq;                                        */
/*  input sint16 Ext_uBattMes;                                                */
/*  input boolean DIAGSFTYLVL2_bECUWkuMainPrev;                               */
/*  input boolean DIAGSFTYLVL2_bEngRStrtReqPrev;                              */
/*  input uint16 SftyMgt_uBattMinUCFtoCMMLvl2;                                */
/*  input uint16 SftyMgt_uBattMaxUCFtoCMMLvl2;                                */
/*  input boolean DIAGSFTYLVL2_bSftyBattMesRanPrev;                           */
/*  input uint8 SftyMgt_ticounterWkuMain_C;                                   */
/*  input uint8 SftyMgt_counterWkuMain;                                       */
/*  input uint8 SftyMgt_ticounterEngStrtReq_C;                                */
/*  input uint8 SftyMgt_counterEngStrtReq;                                    */
/*  input uint8 SftyMgt_ticounterBattMes_C;                                   */
/*  input uint8 SftyMgt_counterBattMes;                                       */
/*  output boolean SftyMgt_bAcvDiagCanSftyLvl2;                               */
/*  output boolean DIAGSFTYLVL2_bECUWkuMainPrev;                              */
/*  output boolean DIAGSFTYLVL2_bEngRStrtReqPrev;                             */
/*  output boolean DIAGSFTYLVL2_bSftyBattMesRanPrev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidActDiagCanSftyNv(void)
{
   boolean bLocalECU_bWkuMain;
   boolean bLocalCoPtUH_bEngRStrtReq;
   boolean bLocalSftyMgt_BattMesRange;
   boolean bLocalAnd1;
   boolean bLocalAnd2;
   boolean bLocalAnd3;
   uint16  u16LocalSftyMgt_counterWkuMain;
   uint16  u16LocalSftyMgt_countEngStrtReq;
   uint16  u16LocalSftyMgt_counterBattMes;
   sint16  s16LocalExt_uBattMes;


   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidGET(CoPtUH_bEngRStrtReq, bLocalCoPtUH_bEngRStrtReq);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);

   if (  (bLocalECU_bWkuMain != 0)
      && (DIAGSFTYLVL2_bECUWkuMainPrev == 0))
   {
      DIAGSFTYLVL2_vidReinitCounter1();
   }
   if (  (bLocalCoPtUH_bEngRStrtReq == 0)
      && (DIAGSFTYLVL2_bEngRStrtReqPrev != 0))
   {
      DIAGSFTYLVL2_vidReinitCounter2();
   }

   if (  (s16LocalExt_uBattMes >= SftyMgt_uBattMinUCFtoCMMLvl2)
      && (s16LocalExt_uBattMes <= SftyMgt_uBattMaxUCFtoCMMLvl2))
   {
      bLocalSftyMgt_BattMesRange = 1;
   }
   else
   {
      bLocalSftyMgt_BattMesRange = 0;
   }
   if (  (bLocalSftyMgt_BattMesRange != 0)
      && (DIAGSFTYLVL2_bSftyBattMesRanPrev == 0))
   {
      DIAGSFTYLVL2_vidReinitCounter3();
   }

   u16LocalSftyMgt_counterWkuMain =
      (uint16)((SftyMgt_ticounterWkuMain_C * 5) / 2);
   if (  (bLocalECU_bWkuMain != 0)
      && (SftyMgt_counterWkuMain >= u16LocalSftyMgt_counterWkuMain))
   {
      bLocalAnd1 = 1;
   }
   else
   {
      bLocalAnd1 = 0;
   }

   u16LocalSftyMgt_countEngStrtReq =
      (uint16)((SftyMgt_ticounterEngStrtReq_C * 5) / 2);
   if (  (bLocalCoPtUH_bEngRStrtReq == 0)
      && (SftyMgt_counterEngStrtReq >= u16LocalSftyMgt_countEngStrtReq))
   {
      bLocalAnd2 = 1;
   }
   else
   {
      bLocalAnd2 = 0;
   }

   u16LocalSftyMgt_counterBattMes =
      (uint16)((SftyMgt_ticounterBattMes_C * 5) / 2);
   if (  (bLocalSftyMgt_BattMesRange != 0)
      && (SftyMgt_counterBattMes >= u16LocalSftyMgt_counterBattMes))
   {
      bLocalAnd3 = 1;
   }
   else
   {
      bLocalAnd3 = 0;
   }
   if (  (bLocalAnd1 != 0)
      && (bLocalAnd2 != 0)
      && (bLocalAnd3 != 0))
   {
      VEMS_vidSET(SftyMgt_bAcvDiagCanSftyLvl2, 1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bAcvDiagCanSftyLvl2, 0);
   }
   DIAGSFTYLVL2_bECUWkuMainPrev = bLocalECU_bWkuMain;
   DIAGSFTYLVL2_bEngRStrtReqPrev = bLocalCoPtUH_bEngRStrtReq;
   DIAGSFTYLVL2_bSftyBattMesRanPrev = bLocalSftyMgt_BattMesRange;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidReinitCounter1                             */
/* !Description :  Cette fonction permet de reinitialiser le compteur         */
/*                 SftyMgt_counterWkuMain.                                    */
/* !Number      :  FCT5.3                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 SftyMgt_counterWkuMain;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidReinitCounter1(void)
{
   SftyMgt_counterWkuMain = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidReinitCounter2                             */
/* !Description :  Cette fonction permet de reinitialiser le compteur         */
/*                 SftyMgt_counterEngStrtReq.                                 */
/* !Number      :  FCT5.4                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 SftyMgt_counterEngStrtReq;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidReinitCounter2(void)
{
   SftyMgt_counterEngStrtReq = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidReinitCounter3                             */
/* !Description :  Cette fonction permet de reinitialiser le compteur         */
/*                 SftyMgt_counterBattMes.                                    */
/* !Number      :  FCT5.5                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 SftyMgt_counterBattMes;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidReinitCounter3(void)
{
   SftyMgt_counterBattMes = 0;
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"

/*-------------------------------- end of file -------------------------------*/