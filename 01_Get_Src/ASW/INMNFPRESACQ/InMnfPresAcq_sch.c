/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INMNFPRESACQ                                            */
/* !Description     : INMNFPRESACQ Component                                  */
/*                                                                            */
/* !Module          : INMNFPRESACQ                                            */
/* !Description     : ACQUISITION DE LA PRESSION COLLECTEUR                   */
/*                                                                            */
/* !File            : INMNFPRESACQ_SCH.C                                      */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / AirPres_EveRst_InMnfPresAcq                                          */
/*   2 / AirPres_Eve14TDC_InMnfPresAcq                                        */
/*   3 / AirPres_SdlMid_InMnfPresAcq                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_6525158 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/INMNFPRESACQ/InMnfPresAcq_sch.c_v $*/
/* $Revision::   1.5                                                         $*/
/* $Author::   achebino                               $$Date::   26 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "INMNFPRESACQ.h"
#include "INMNFPRESACQ_L.H"
#include "INMNFPRESACQ_IM.h"
#include "GDGAR.H"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_EveRst_InMnfPresAcq                                */
/* !Description :  Fonction d'accroche moniteur à l'evenement Reset du        */
/*                 calculateur                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_E_12_01656_008.01                                     */
/*                 VEMS_E_12_01656_009.01                                     */
/*                 VEMS_E_12_01656_010.01                                     */
/*                 VEMS_R_12_01656_001.02                                     */
/*                 VEMS_R_12_01656_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INMNFPRESACQ_vidInit();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_EveRst_InMnfPresAcq                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_EveRst_InMnfPresAcq(void)
{
   INMNFPRESACQ_vidInit();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_Eve14TDC_InMnfPresAcq                              */
/* !Description :  Fonction d'accroche moniteur à l'evenement 1/4TDC du CMM   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_E_12_01656_008.01                                     */
/*                 VEMS_E_12_01656_009.01                                     */
/*                 VEMS_E_12_01656_010.01                                     */
/*                 VEMS_R_12_01656_001.02                                     */
/*                 VEMS_R_12_01656_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INMNFPRESACQ_vidAcqPressManifld();                       */
/*  extf argret void INMNFPRESACQ_vidDiagPressManifld();                      */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait);                                             */
/*  extf argret void INMNFPRESACQ_vidFormPressManifld();                      */
/*  extf argret void INMNFPRESACQ_vidArbPressManifld();                       */
/*  input uint8 INMNFPRESACQ_u8Inhib;                                         */
/*  input boolean CoPTSt_bEngRun;                                             */
/*  input boolean Ctrl_bAcv_pDsThr;                                           */
/*  input boolean Ext_bDgoScp_pDsThrMes;                                      */
/*  input boolean Ext_bMonRunScp_pDsThrMes;                                   */
/*  input boolean Ext_bDgoScg_pDsThrMes;                                      */
/*  input boolean Ext_bMonRunScg_pDsThrMes;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_Eve14TDC_InMnfPresAcq                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_Eve14TDC_InMnfPresAcq(void)
{
   boolean bLocalCtrl_bAcv_pDsThr;
   boolean bLocalCoPTSt_bEngRun;


   if (INMNFPRESACQ_u8Inhib != 0x5A)
   {
      VEMS_vidGET(CoPTSt_bEngRun, bLocalCoPTSt_bEngRun);

      if (bLocalCoPTSt_bEngRun != 0)
      {
         VEMS_vidGET(Ctrl_bAcv_pDsThr, bLocalCtrl_bAcv_pDsThr);
         if (bLocalCtrl_bAcv_pDsThr != 0)
         {
            INMNFPRESACQ_vidAcqPressManifld();
            INMNFPRESACQ_vidDiagPressManifld();
            GDGAR_vidGdu(GD_DFT_SCP_PDSTHRMES,
                         Ext_bDgoScp_pDsThrMes ,
                         Ext_bMonRunScp_pDsThrMes,
                         DIAG_DISPO);
            GDGAR_vidGdu(GD_DFT_SCG_PDSTHRMES,
                         Ext_bDgoScg_pDsThrMes,
                         Ext_bMonRunScg_pDsThrMes,
                         DIAG_DISPO);
            INMNFPRESACQ_vidFormPressManifld();
            INMNFPRESACQ_vidArbPressManifld();
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlMid_InMnfPresAcq                                */
/* !Description :  Fonction d'accroche moniteur à l'evenement Moniteur moyen  */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_E_12_01656_008.01                                     */
/*                 VEMS_E_12_01656_009.01                                     */
/*                 VEMS_E_12_01656_010.01                                     */
/*                 VEMS_R_12_01656_001.02                                     */
/*                 VEMS_R_12_01656_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INMNFPRESACQ_vidAcqPressManifld();                       */
/*  extf argret void INMNFPRESACQ_vidDiagPressManifld();                      */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait);                                             */
/*  extf argret void INMNFPRESACQ_vidFormPressManifld();                      */
/*  extf argret void INMNFPRESACQ_vidArbPressManifld();                       */
/*  input uint8 INMNFPRESACQ_u8Inhib;                                         */
/*  input boolean CoPTSt_bEngRun;                                             */
/*  input boolean Ctrl_bAcv_pDsThr;                                           */
/*  input boolean Ext_bDgoScp_pDsThrMes;                                      */
/*  input boolean Ext_bMonRunScp_pDsThrMes;                                   */
/*  input boolean Ext_bDgoScg_pDsThrMes;                                      */
/*  input boolean Ext_bMonRunScg_pDsThrMes;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlMid_InMnfPresAcq                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlMid_InMnfPresAcq(void)
{
   boolean bLocalCtrl_bAcv_pDsThr;
   boolean bLocalCoPTSt_bEngRun;


   if (INMNFPRESACQ_u8Inhib != 0x5A)
   {
      VEMS_vidGET(CoPTSt_bEngRun, bLocalCoPTSt_bEngRun);

      if (bLocalCoPTSt_bEngRun == 0)
      {
         VEMS_vidGET(Ctrl_bAcv_pDsThr, bLocalCtrl_bAcv_pDsThr);
         if (bLocalCtrl_bAcv_pDsThr != 0)
         {
            INMNFPRESACQ_vidAcqPressManifld();
            INMNFPRESACQ_vidDiagPressManifld();
            GDGAR_vidGdu(GD_DFT_SCP_PDSTHRMES,
                         Ext_bDgoScp_pDsThrMes ,
                         Ext_bMonRunScp_pDsThrMes,
                         DIAG_DISPO);
            GDGAR_vidGdu(GD_DFT_SCG_PDSTHRMES,
                         Ext_bDgoScg_pDsThrMes,
                         Ext_bMonRunScg_pDsThrMes,
                         DIAG_DISPO);
            INMNFPRESACQ_vidFormPressManifld();
            INMNFPRESACQ_vidArbPressManifld();
         }
      }
   }
}
/*-------------------------------- end of file -------------------------------*/