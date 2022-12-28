/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQDGOHAL                                               */
/* !Description     : ACQDGOHAL component.                                    */
/*                                                                            */
/* !Module          : ACQDGOHAL                                               */
/* !Description     : Spécification des acquisitions des états et résultats   */
/*                    des diagnostics                                         */
/*                                                                            */
/* !File            : ACQDGOHAL_SCH1.C                                        */
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
/*   1 / Ext_EveRst_OutPutCmdDiag                                             */
/*   2 / Oil_SdlSlow_CmdDiagBlowBy1                                           */
/*   3 / Oil_SdlSlow_CmdDiagBlowBy2                                           */
/*   4 / VlvAct_SdlFast_CmdDiagVlvActEx                                       */
/*   5 / VlvAct_SdlFast_CmdDiagVlvActIn                                       */
/*   6 / HeatSenO2_SdlFast_CmdDiagDrvO2Ds                                     */
/*   7 / HeatSenO2_SdlFast_CmdDiagDrvO2Us                                     */
/*   8 / EngSt_SdlFast_CmdDiagAuthStrtSTT                                     */
/*   9 / Cstr_SdlFast_CmdDiagCstr                                             */
/*   10 / EngSt_SdlFast_CmdDiagEngStOutIdc                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_6669624 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACQDGOHAL/ACQDGOHAL_SCH1.c_v      $*/
/* $Revision::   1.1      $$Author::   wbouach        $$Date::   17 Sep 2014 $*/
/* $Author::   wbouach                                $$Date::   17 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#define VEMS_H_AUTOCODE_H

#include "STD_TYPES.h"
#include "ACQDGOHAL.h"
#include "ACQDGOHAL_L.h"
#include "ACQDGOHAL_IM.h"
#include "GDGAR.h"
#include "DGOHAL.h"
#include "ACQDGOHAL_toRte.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_EveRst_OutPutCmdDiag                                   */
/* !Description :  Evènement Reset du calculateur                             */
/* !Number      :  SCH1.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQDGOHAL_vidInit_OutPutCmdDiag();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Ext_EveRst_OutPutCmdDiag                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_EveRst_OutPutCmdDiag(void)
{
   ACQDGOHAL_vidInit_OutPutCmdDiag();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_SdlSlow_CmdDiagBlowBy1                                 */
/* !Description :  Moniteur lent pour la comande du réchauffeur BlowBy        */
/* !Number      :  SCH1.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQDGOHAL_vidCmdDiagBlowBy1();                           */
/*  input boolean Ctrl_bAvc_BlowBy1;                                          */
/*  input uint8 ACQDGOHAL_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Oil_SdlSlow_CmdDiagBlowBy1                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_SdlSlow_CmdDiagBlowBy1(void)
{
   boolean bLocalCtrl_bAvc_BlowBy1;


   VEMS_vidGET(Ctrl_bAvc_BlowBy1, bLocalCtrl_bAvc_BlowBy1);
   if (ACQDGOHAL_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bAvc_BlowBy1 != 0)
      {
         ACQDGOHAL_vidCmdDiagBlowBy1();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_SdlSlow_CmdDiagBlowBy2                                 */
/* !Description :  Moniteur lent pour la comande du réchauffeur BlowBy.       */
/* !Number      :  SCH1.3                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQDGOHAL_vidCmdDiagBlowBy2();                           */
/*  input boolean Ctrl_bAvc_BlowBy2;                                          */
/*  input uint8 ACQDGOHAL_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Oil_SdlSlow_CmdDiagBlowBy2                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_SdlSlow_CmdDiagBlowBy2(void)
{
   boolean bLocalCtrl_bAvc_BlowBy2;


   VEMS_vidGET(Ctrl_bAvc_BlowBy2, bLocalCtrl_bAvc_BlowBy2);
   if (ACQDGOHAL_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bAvc_BlowBy2 != 0)
      {
         ACQDGOHAL_vidCmdDiagBlowBy2();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_CmdDiagVlvActEx                             */
/* !Description :  Moniteur rapide pour la fonction VVT échappement.          */
/* !Number      :  SCH1.4                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQDGOHAL_vidCmdDiagVlvActEx();                          */
/*  input uint8 ACQDGOHAL_u8Inhib;                                            */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_CmdDiagVlvActEx                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_CmdDiagVlvActEx(void)
{
   if (ACQDGOHAL_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         ACQDGOHAL_vidCmdDiagVlvActEx();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_CmdDiagVlvActIn                             */
/* !Description :  Moniteur rapide pour la fonction VVT admission.            */
/* !Number      :  SCH1.5                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQDGOHAL_vidCmdDiagVlvActIn();                          */
/*  input uint8 ACQDGOHAL_u8Inhib;                                            */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_CmdDiagVlvActIn                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_CmdDiagVlvActIn(void)
{
   if (ACQDGOHAL_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C != 0)
      {
         ACQDGOHAL_vidCmdDiagVlvActIn();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlFast_CmdDiagDrvO2Ds                           */
/* !Description :  Récurrence rapide de la fonction HeatSenO2 aval            */
/* !Number      :  SCH1.6                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void ACQDGOHAL_vidCmdDiagDrvO2Ds();                           */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint8 ACQDGOHAL_u8Inhib;                                            */
/*  input uint16 Lshd_min_voltage_diag_thresh;                                */
/*  input uint16 Lshd_max_voltage_diag_thresh;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_SdlFast_CmdDiagDrvO2Ds                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlFast_CmdDiagDrvO2Ds(void)
{
   boolean bLocalInhDrvrSenO2DsElDiag;
   boolean bLocalInhDrvrSenO2Ds;
   sint16  s16LocalExt_uBattMes;


   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   bLocalInhDrvrSenO2Ds = GDGAR_bGetFRM(FRM_FRM_INHDRVRSENO2DS);
   bLocalInhDrvrSenO2DsElDiag = GDGAR_bGetFRM(FRM_FRM_INHDRVRSENO2DSELDIAG);
   s16LocalExt_uBattMes = (sint16)((sint32)(s16LocalExt_uBattMes * 100) / 236);

   if (ACQDGOHAL_u8Inhib != 0x5A)
   {
      if (  (s16LocalExt_uBattMes > Lshd_min_voltage_diag_thresh)
         && (s16LocalExt_uBattMes < Lshd_max_voltage_diag_thresh)
         && (bLocalInhDrvrSenO2Ds == 0)
         && (bLocalInhDrvrSenO2DsElDiag == 0))
      {
         ACQDGOHAL_vidCmdDiagDrvO2Ds();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlFast_CmdDiagDrvO2Us                           */
/* !Description :  Récurrence rapide de la fonction HeatSenO2 amont.          */
/* !Number      :  SCH1.7                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void ACQDGOHAL_vidCmdDiagDrvO2Us();                           */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint8 ACQDGOHAL_u8Inhib;                                            */
/*  input uint16 Lshd_min_voltage_diag_thresh;                                */
/*  input uint16 Lshd_max_voltage_diag_thresh;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_SdlFast_CmdDiagDrvO2Us                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlFast_CmdDiagDrvO2Us(void)
{
   boolean bLocalInhDrvrSenO2UsElDiag;
   boolean bLocalInhDrvrSenO2Us;
   sint16  s16LocalExt_uBattMes;


   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   bLocalInhDrvrSenO2Us = GDGAR_bGetFRM(FRM_FRM_INHDRVRSENO2US);
   bLocalInhDrvrSenO2UsElDiag = GDGAR_bGetFRM(FRM_FRM_INHDRVRSENO2USELDIAG);
   s16LocalExt_uBattMes = (sint16)((sint32)(s16LocalExt_uBattMes * 100) / 236);

   if (ACQDGOHAL_u8Inhib != 0x5A)
   {
      if (  (s16LocalExt_uBattMes > Lshd_min_voltage_diag_thresh)
         && (s16LocalExt_uBattMes < Lshd_max_voltage_diag_thresh)
         && (bLocalInhDrvrSenO2Us == 0)
         && (bLocalInhDrvrSenO2UsElDiag == 0))
      {
         ACQDGOHAL_vidCmdDiagDrvO2Us();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_SdlFast_CmdDiagAuthStrtSTT                           */
/* !Description :  Monitoring rapide de la fonction EngSt.                    */
/* !Number      :  SCH1.8                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQDGOHAL_vidCmdDiagAuthStrtSTT();                       */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input boolean EngSt_bAcvAuthStrtSTTAcq;                                   */
/*  input uint8 ACQDGOHAL_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_SdlFast_CmdDiagAuthStrtSTT                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_SdlFast_CmdDiagAuthStrtSTT(void)
{
   boolean bLocalECU_bWkuMain;
   boolean bLocalIntegratioElectronique;
   boolean bLocalEngSt_bAcvAuthStrtSTTAcq;


   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalIntegratioElectronique);
   VEMS_vidGET(EngSt_bAcvAuthStrtSTTAcq, bLocalEngSt_bAcvAuthStrtSTTAcq);

   if (ACQDGOHAL_u8Inhib != 0x5A)
   {
      if (  (bLocalECU_bWkuMain != 0)
         && (bLocalIntegratioElectronique == 0)
         && (bLocalEngSt_bAcvAuthStrtSTTAcq != 0))
      {
         ACQDGOHAL_vidCmdDiagAuthStrtSTT();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cstr_SdlFast_CmdDiagCstr                                   */
/* !Description :  Moniteur rapide pour la fonction purge canister.           */
/* !Number      :  SCH1.9                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQDGOHAL_vidCmdDiagCstr();                              */
/*  input uint8 ACQDGOHAL_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cstr_SdlFast_CmdDiagCstr                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_SdlFast_CmdDiagCstr(void)
{
   if (ACQDGOHAL_u8Inhib != 0x5A)
   {
      ACQDGOHAL_vidCmdDiagCstr();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_SdlFast_CmdDiagEngStOutIdc                           */
/* !Description :  Moniteur rapide pour la fonction état moteur               */
/* !Number      :  SCH1.10                                                    */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQDGOHAL_vidCmdDiagEngStOutIdc();                       */
/*  input boolean Ctrl_bEngRunr;                                              */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean UCE_bPwrlAcv;                                               */
/*  input boolean ECU_bImmoUnlockWkuSt;                                       */
/*  input uint8 ACQDGOHAL_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_SdlFast_CmdDiagEngStOutIdc                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_SdlFast_CmdDiagEngStOutIdc(void)
{
   boolean bLocalCtrl_bEngRunr;
   boolean bLocalECU_bWkuMain;
   boolean bLocalUCE_bPwrlAcv;
   boolean bLocalECU_bImmoUnlockWkuSt;


   VEMS_vidGET(Ctrl_bEngRunr, bLocalCtrl_bEngRunr);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidGET(UCE_bPwrlAcv, bLocalUCE_bPwrlAcv);
   VEMS_vidGET(ECU_bImmoUnlockWkuSt, bLocalECU_bImmoUnlockWkuSt);
   if (ACQDGOHAL_u8Inhib != 0x5A)
   {
      if (  (bLocalCtrl_bEngRunr != 0)
         && (  (bLocalECU_bWkuMain != 0)
            || (bLocalUCE_bPwrlAcv != 0)
            || (bLocalECU_bImmoUnlockWkuSt != 0)))
      {
         ACQDGOHAL_vidCmdDiagEngStOutIdc();
      }
   }
}
/*------------------------------- end of file --------------------------------*/