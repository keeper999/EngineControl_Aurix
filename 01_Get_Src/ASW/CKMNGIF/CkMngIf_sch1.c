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
/* !File            : CKMNGIF_SCH1.C                                          */
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
/*   1 / Sync_EveRst_CkMngIf                                                  */
/*   2 / Sync_EveRTSt_CkMngIf                                                 */
/*   3 / Sync_EveStTR_CkMngIf                                                 */
/*   4 / Sync_SdlMid_CkMngIf                                                  */
/*   5 / Sync_EveCkSnOn_CkMngIf                                               */
/*   6 / Sync_EveTDC_CkMngIf                                                  */
/*   7 / Sync_SdlFast_CkMngIf                                                 */
/*   8 / Sync_EveBDC_CkMngIf                                                  */
/*   9 / Sync_EveTDC_CkMngIf3                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6884590 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#069167                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNC/CKMNGIF/CkMngIf_sch1.c_v     $*/
/* $Revision::   1.5      $$Author::   wbouach        $$Date::   31 Jul 2014 $*/
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
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveRst_CkMngIf                                        */
/* !Description :  Fonction reset calculateur                                 */
/* !Number      :  SCH1.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03007_001.01                                     */
/*                 VEMS_E_11_03007_002.01                                     */
/*                 VEMS_E_11_03007_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CKMNGIF_vidInitOutput();                                 */
/*  extf argret void CKMNGIF_vidPeriodeCyl();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveRst_CkMngIf                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRst_CkMngIf(void)
{
   CKMNGIF_vidInitOutput();
   CKMNGIF_vidPeriodeCyl();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveRTSt_CkMngIf                                       */
/* !Description :  Fonction d'accroche à l'evenement Sync_EveRTSt_CkMngIf     */
/* !Number      :  SCH1.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03007_001.01                                     */
/*                 VEMS_E_11_03007_002.01                                     */
/*                 VEMS_E_11_03007_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CKMNGIF_vidRunToStall();                                 */
/*  input uint8 CKMNGIF_u8Inhib;                                              */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveRTSt_CkMngIf                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRTSt_CkMngIf(void)
{
   boolean bLocalCtrl_bAcv_EngMes;


   if (CKMNGIF_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcv_EngMes);
      if (bLocalCtrl_bAcv_EngMes != 0)
      {
         CKMNGIF_vidRunToStall();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveStTR_CkMngIf                                       */
/* !Description :  Fonction d'accroche à l'evenement Sync_EveStTR_CkMngIf     */
/* !Number      :  SCH1.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03007_001.01                                     */
/*                 VEMS_E_11_03007_002.01                                     */
/*                 VEMS_E_11_03007_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CKMNGIF_vidStallToRun();                                 */
/*  extf argret void CKMNGIF_vidAcqui_duree_dent();                           */
/*  input uint8 CKMNGIF_u8Inhib;                                              */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveStTR_CkMngIf                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveStTR_CkMngIf(void)
{
   boolean bLocalCtrl_bAcv_EngMes;


   if (CKMNGIF_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcv_EngMes);
      if (bLocalCtrl_bAcv_EngMes != 0)
      {
         CKMNGIF_vidStallToRun();
         CKMNGIF_vidAcqui_duree_dent();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_SdlMid_CkMngIf                                        */
/* !Description :  Fonction d'accroche à l'evenement Sync_SdlMid_CkMngIf      */
/* !Number      :  SCH1.4                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03007_001.01                                     */
/*                 VEMS_E_11_03007_002.01                                     */
/*                 VEMS_E_11_03007_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CKMNGIF_vidDiagEngFail();                                */
/*  extf argret void GDGAR_vidGdu(argin uint16 indexDefaut, argin boolean     */
/* bDgo, argin boolean bMonRun, argin boolean Ns_bMonWait);                   */
/*  input uint8 CKMNGIF_u8Inhib;                                              */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*  input boolean Ext_bDgoHi_nEng;                                            */
/*  input boolean Ext_bMonRunHi_nEng;                                         */
/*  input boolean Ext_bDgoHi_aEng;                                            */
/*  input boolean Ext_bMonRunHi_aEng;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_SdlMid_CkMngIf                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_SdlMid_CkMngIf(void)
{
   boolean bLocalCtrl_bAcv_EngMes;


   if (CKMNGIF_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcv_EngMes);
      if (bLocalCtrl_bAcv_EngMes != 0)
      {
         CKMNGIF_vidDiagEngFail();
         GDGAR_vidGdu(GD_DFT_HI_NENG,
                      Ext_bDgoHi_nEng,
                      Ext_bMonRunHi_nEng,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_HI_AENG,
                      Ext_bDgoHi_aEng,
                      Ext_bMonRunHi_aEng,
                      DIAG_DISPO);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkSnOn_CkMngIf                                     */
/* !Description :  Fonction d'accroche à l'evenement Sync_EveCkSnOn_CkMngIf   */
/* !Number      :  SCH1.5                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03007_001.01                                     */
/*                 VEMS_E_11_03007_002.01                                     */
/*                 VEMS_E_11_03007_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CKMNGIF_vidSynchroFound();                               */
/*  extf argret void CKMNGIF_vidEngineSpeedCalc();                            */
/*  extf argret void CKMNGIF_vidEnginePeriodFind();                           */
/*  extf argret void CKMNGIF_vidPeriodeCyl();                                 */
/*  extf argret void CKMNGIF_vidPhaseCylEch();                                */
/*  extf argret void CKMNGIF_vidBdcTreatment();                               */
/*  extf argret void CKMNGIF_vidAcqui_duree_dent();                           */
/*  input uint8 CKMNGIF_u8Inhib;                                              */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*  input boolean Cranking_retry;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkSnOn_CkMngIf                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkSnOn_CkMngIf(void)
{
   boolean bLocalCtrl_bAcv_EngMes;
   boolean bLocalCrankingRetry;


   if (CKMNGIF_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcv_EngMes);
      if (bLocalCtrl_bAcv_EngMes != 0)
      {
         VEMS_vidGET(Cranking_retry, bLocalCrankingRetry);
         CKMNGIF_vidSynchroFound();
         CKMNGIF_vidEngineSpeedCalc();
         CKMNGIF_vidEnginePeriodFind();
         if (bLocalCrankingRetry == 0)
         {
            CKMNGIF_vidPeriodeCyl();
         }
         CKMNGIF_vidPhaseCylEch();
         CKMNGIF_vidBdcTreatment();
         CKMNGIF_vidAcqui_duree_dent();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveTDC_CkMngIf                                        */
/* !Description :  Fonction d'accroche à l'evenement Sync_EveTDC_CkMngIf      */
/* !Number      :  SCH1.6                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03007_001.01                                     */
/*                 VEMS_E_11_03007_002.01                                     */
/*                 VEMS_E_11_03007_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CKMNGIF_vidTDCTreatment();                               */
/*  input uint8 CKMNGIF_u8Inhib;                                              */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveTDC_CkMngIf                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveTDC_CkMngIf(void)
{
   boolean bLocalCtrl_bAcv_EngMes;


   if (CKMNGIF_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcv_EngMes);
      if (bLocalCtrl_bAcv_EngMes != 0)
      {
         CKMNGIF_vidTDCTreatment();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_SdlFast_CkMngIf                                       */
/* !Description :  Fonction d'accroche à l'evenement Sync_SdlFast_CkMngIf     */
/* !Number      :  SCH1.7                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03007_001.01                                     */
/*                 VEMS_E_11_03007_002.01                                     */
/*                 VEMS_E_11_03007_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CKMNGIF_vidPhaseCylEch();                                */
/*  input uint8 CKMNGIF_u8Inhib;                                              */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_SdlFast_CkMngIf                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_SdlFast_CkMngIf(void)
{
   boolean bLocalCtrl_bAcv_EngMes;


   if (CKMNGIF_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcv_EngMes);
      if (bLocalCtrl_bAcv_EngMes != 0)
      {
         CKMNGIF_vidPhaseCylEch();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveBDC_CkMngIf                                        */
/* !Description :  Fonction d'accroche à l'evenement Sync_EveBDC_CkMngIf      */
/* !Number      :  SCH1.8                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03007_001.01                                     */
/*                 VEMS_E_11_03007_002.01                                     */
/*                 VEMS_E_11_03007_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CKMNGIF_vidPeriodeCyl();                                 */
/*  extf argret void CKMNGIF_vidBdcTreatment();                               */
/*  input uint8 CKMNGIF_u8Inhib;                                              */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveBDC_CkMngIf                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveBDC_CkMngIf(void)
{
   boolean bLocalCtrl_bAcv_EngMes;


   if (CKMNGIF_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcv_EngMes);
      if (bLocalCtrl_bAcv_EngMes != 0)
      {
         CKMNGIF_vidPeriodeCyl();
         CKMNGIF_vidBdcTreatment();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveTDC_CkMngIf3                                       */
/* !Description :  Interruption PMH après calcul durée dent                   */
/* !Number      :  SCH1.9                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03007_001.01                                     */
/*                 VEMS_E_11_03007_002.01                                     */
/*                 VEMS_E_11_03007_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CKMNGIF_vidEngineSpeedCalc();                            */
/*  extf argret void CKMNGIF_vidEnginePeriodFind();                           */
/*  extf argret void CKMNGIF_vidAcqui_duree_dent();                           */
/*  input uint8 CKMNGIF_u8Inhib;                                              */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveTDC_CkMngIf3                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveTDC_CkMngIf3(void)
{
   boolean bLocalCtrl_bAcv_EngMes;


   if (CKMNGIF_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcv_EngMes);
      if (bLocalCtrl_bAcv_EngMes != 0)
      {
         CKMNGIF_vidEngineSpeedCalc();
         CKMNGIF_vidEnginePeriodFind();
         CKMNGIF_vidAcqui_duree_dent();
      }
   }
}
/*------------------------------- end of file --------------------------------*/