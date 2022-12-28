/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQADC                                                  */
/* !Description     : ACQADC component.                                       */
/*                                                                            */
/* !Module          : ACQADC                                                  */
/* !Description     : Spécification des acquisitions analogiques (AdcHal)     */
/*                                                                            */
/* !File            : ACQADC_SCH2.C                                           */
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
/*   1 / HeatSenO2_SdlFast_DrvrSenO2DsAdc                                     */
/*   2 / HeatSenO2_SdlFast_DrvrSenO2UsAdc                                     */
/*   3 / AirPres_Eve14TDC_InMnfPresAcqAdc                                     */
/*   4 / AirPres_SdlMid_InMnfPresAcqAdc                                       */
/*   5 / AirPres_SdlSlow_AirExtPresAcqAdc                                     */
/*   6 / AirPres_SdlFast_AirExtPresAcqAdc                                     */
/*   7 / AirPres_SdlFast_BrkAsiAcqAdc                                         */
/*   8 / AirPres_SdlFast_InMnfPresDiagAdc                                     */
/*   9 / AirPres_SdlFast_RelBrkAsiAcqAdc                                      */
/*   10 / EngSt_SdlFast_DftStaCmdAdc                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_6669203 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACQADC/ACQADC_SCH2.C_v            $*/
/* $Revision::   1.3      $$Author::   wbouach        $$Date::   31 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   31 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.H"
#include "ACQADC.H"
#include "ACQADC_L.H"
#include "ACQADC_IM.H"
#include "ACQADC_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlFast_DrvrSenO2DsAdc                           */
/* !Description :  Récurrence rapide de la fonction HeatSenO2                 */
/* !Number      :  SCH2.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidHeatSenO2Ds();                                 */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_SdlFast_DrvrSenO2DsAdc                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlFast_DrvrSenO2DsAdc(void)
{
   if (ACQADC_u8Inhib != 0x5A)
   {
      ACQADC_vidHeatSenO2Ds();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlFast_DrvrSenO2UsAdc                           */
/* !Description :  Récurrence rapide de la fonction HeatSenO2                 */
/* !Number      :  SCH2.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidHeatSenO2Us();                                 */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_SdlFast_DrvrSenO2UsAdc                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlFast_DrvrSenO2UsAdc(void)
{
   if (ACQADC_u8Inhib != 0x5A)
   {
      ACQADC_vidHeatSenO2Us();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_Eve14TDC_InMnfPresAcqAdc                           */
/* !Description :  Evénement d'appel de tâche "quart de PMH" du CMM           */
/* !Number      :  SCH2.3                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQADC_vidInMnfPresAcq();                                */
/*  input boolean CoPTSt_bEngRun;                                             */
/*  input boolean Ctrl_bAcv_pDsThr;                                           */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_Eve14TDC_InMnfPresAcqAdc                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_Eve14TDC_InMnfPresAcqAdc(void)
{
   boolean bLocalCoPTSt_bEngRun;
   boolean bLocalCtrl_bAcv_pDsThr;


   VEMS_vidGET(CoPTSt_bEngRun, bLocalCoPTSt_bEngRun);
   VEMS_vidGET(Ctrl_bAcv_pDsThr, bLocalCtrl_bAcv_pDsThr);
   if (ACQADC_u8Inhib != 0x5A)
   {
      if (  (bLocalCoPTSt_bEngRun != 0)
         && (bLocalCtrl_bAcv_pDsThr != 0))
      {
         ACQADC_vidInMnfPresAcq();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlMid_InMnfPresAcqAdc                             */
/* !Description :  Moniteur moyen                                             */
/* !Number      :  SCH2.4                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQADC_vidInMnfPresAcq();                                */
/*  input boolean CoPTSt_bEngRun;                                             */
/*  input boolean Ctrl_bAcv_pDsThr;                                           */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlMid_InMnfPresAcqAdc                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlMid_InMnfPresAcqAdc(void)
{
   boolean bLocalCoPTSt_bEngRun;
   boolean bLocalCtrl_bAcv_pDsThr;


   VEMS_vidGET(CoPTSt_bEngRun, bLocalCoPTSt_bEngRun);
   VEMS_vidGET(Ctrl_bAcv_pDsThr, bLocalCtrl_bAcv_pDsThr);
   if (ACQADC_u8Inhib != 0x5A)
   {
      if (  (bLocalCoPTSt_bEngRun == 0)
         && (bLocalCtrl_bAcv_pDsThr != 0))
      {
         ACQADC_vidInMnfPresAcq();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlSlow_AirExtPresAcqAdc                           */
/* !Description :  Moniteur lent                                              */
/* !Number      :  SCH2.5                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQADC_vidAirExtPresAcq();                               */
/*  input boolean Ext_bRun;                                                   */
/*  input boolean Ctrl_bAcv_pAirExtMes;                                       */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlSlow_AirExtPresAcqAdc                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlSlow_AirExtPresAcqAdc(void)
{
   boolean bLocalExt_bRun;
   boolean bLocalCtrl_bAcv_pAirExtMes;


   VEMS_vidGET(Ext_bRun, bLocalExt_bRun);
   VEMS_vidGET(Ctrl_bAcv_pAirExtMes, bLocalCtrl_bAcv_pAirExtMes);
   if (ACQADC_u8Inhib != 0x5A)
   {
      if (  (bLocalExt_bRun != 0)
         && (bLocalCtrl_bAcv_pAirExtMes != 0))
      {
         ACQADC_vidAirExtPresAcq();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlFast_AirExtPresAcqAdc                           */
/* !Description :  Monitoring rapide de la fonction AirPres                   */
/* !Number      :  SCH2.6                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQADC_vidAirExtPresAcq();                               */
/*  input boolean Ext_bRun;                                                   */
/*  input boolean Ctrl_bAcv_pAirExtMes;                                       */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlFast_AirExtPresAcqAdc                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlFast_AirExtPresAcqAdc(void)
{
   boolean bLocalExt_bRun;
   boolean bLocalCtrl_bAcv_pAirExtMes;


   VEMS_vidGET(Ext_bRun, bLocalExt_bRun);
   VEMS_vidGET(Ctrl_bAcv_pAirExtMes, bLocalCtrl_bAcv_pAirExtMes);
   if (ACQADC_u8Inhib != 0x5A)
   {
      if (  (bLocalExt_bRun == 0)
         && (bLocalCtrl_bAcv_pAirExtMes != 0))
      {
         ACQADC_vidAirExtPresAcq();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlFast_BrkAsiAcqAdc                               */
/* !Description :  Monitoring rapide de la fonction AirPres                   */
/* !Number      :  SCH2.7                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQADC_vidBrkAsiAcq();                                   */
/*  input boolean AirPres_bAcvBrkAsiAcq;                                      */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlFast_BrkAsiAcqAdc                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlFast_BrkAsiAcqAdc(void)
{
   boolean bLocalAirPres_bAcvBrkAsiAcq;
   boolean bLocalDIAGCAN_bIntegElec;


   VEMS_vidGET(AirPres_bAcvBrkAsiAcq, bLocalAirPres_bAcvBrkAsiAcq);
   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalDIAGCAN_bIntegElec);
   if (ACQADC_u8Inhib != 0x5A)
   {
      if (  (bLocalAirPres_bAcvBrkAsiAcq != 0)
         && (bLocalDIAGCAN_bIntegElec == 0))
      {
         ACQADC_vidBrkAsiAcq();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlFast_InMnfPresDiagAdc                           */
/* !Description :  Moniteur rapide                                            */
/* !Number      :  SCH2.8                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16channel)boolean;                 */
/*  extf argret void ACQADC_vidInMnfPresAcq();                                */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlFast_InMnfPresDiagAdc                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlFast_InMnfPresDiagAdc(void)
{
   boolean bLocalFRM_bInhInMnfPresDiag;


   bLocalFRM_bInhInMnfPresDiag = GDGAR_bGetFRM(FRM_FRM_INHINMNFPRESDIAG);
   if (ACQADC_u8Inhib != 0x5A)
   {
      if (bLocalFRM_bInhInMnfPresDiag == 0)
      {
         ACQADC_vidInMnfPresAcq();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlFast_RelBrkAsiAcqAdc                            */
/* !Description :  Moniteur rapide de la fonction AirPres                     */
/* !Number      :  SCH2.9                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQADC_vidRelBrkAsiAcq();                                */
/*  input boolean Ctrl_bAcv_pRelBrkAsi;                                       */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean ECU_bImmoUnlockWkuSt;                                       */
/*  input boolean UCE_bPwrlAcv;                                               */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlFast_RelBrkAsiAcqAdc                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlFast_RelBrkAsiAcqAdc(void)
{
   boolean bLocalCtrl_bAcv_pRelBrkAsi;
   boolean bLocalECU_bWkuMain;
   boolean bLocalECU_bImmoUnlockWkuSt;
   boolean bLocalUCE_bPwrlAcv;


   VEMS_vidGET(Ctrl_bAcv_pRelBrkAsi, bLocalCtrl_bAcv_pRelBrkAsi);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidGET(ECU_bImmoUnlockWkuSt, bLocalECU_bImmoUnlockWkuSt);
   VEMS_vidGET(UCE_bPwrlAcv, bLocalUCE_bPwrlAcv);
   if (ACQADC_u8Inhib != 0x5A)
   {
      if (  (bLocalCtrl_bAcv_pRelBrkAsi != 0)
         && (  (bLocalECU_bWkuMain != 0)
            || (bLocalECU_bImmoUnlockWkuSt != 0)
            || (bLocalUCE_bPwrlAcv != 0)))
      {
         ACQADC_vidRelBrkAsiAcq();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_SdlFast_DftStaCmdAdc                                 */
/* !Description :  Monitoring rapide                                          */
/* !Number      :  SCH2.10                                                    */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQADC_vidAcqAdcEngSt();                                 */
/*  input boolean EngSt_bAcvDftStaCmdAcq;                                     */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_SdlFast_DftStaCmdAdc                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_SdlFast_DftStaCmdAdc(void)
{
   boolean bLocalEngSt_bAcvDftStaCmdAcq;
   boolean bLocalDIAGCAN_bIntegElec;


   VEMS_vidGET(EngSt_bAcvDftStaCmdAcq, bLocalEngSt_bAcvDftStaCmdAcq);
   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalDIAGCAN_bIntegElec);
   if (ACQADC_u8Inhib != 0x5A)
   {
      if (  (bLocalEngSt_bAcvDftStaCmdAcq != 0)
         && (bLocalDIAGCAN_bIntegElec == 0))
      {
         ACQADC_vidAcqAdcEngSt();
      }
   }
}

/*------------------------------- end of file --------------------------------*/