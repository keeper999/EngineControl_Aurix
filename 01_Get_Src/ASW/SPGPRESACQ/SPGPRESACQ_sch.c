/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SPGPRESACQ                                              */
/* !Description     : SPGPRESACQ Component.                                   */
/*                                                                            */
/* !Module          : SPGPRESACQ                                              */
/* !Description     : ACQUISITION DE LA PRESSION DE SURALIMENTATION           */
/*                                                                            */
/* !File            : SPGPRESACQ_SCH.C                                        */
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
/*   1 / AirPres_EveRst_SpgPresAcq                                            */
/*   2 / AirPres_SdlMid_SpgPresAcq                                            */
/*   3 / AirPres_Eve14TDC_SpgPresAcq                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_6851381 / 01                                        */
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

#include "SPGPRESACQ.H"
#include "SPGPRESACQ_L.H"
#include "SPGPRESACQ_IM.H"
#include "STD_TYPES.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_EveRst_SpgPresAcq                                  */
/* !Description :  Evènement_reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_R_10_01081_001.03                                     */
/*                 VEMS_R_10_01081_007.02                                     */
/*                 VEMS_E_10_01081_008.01                                     */
/*                 VEMS_E_10_01081_009.01                                     */
/*                 VEMS_E_10_01081_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SpgPresAcq_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_EveRst_SpgPresAcq                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_EveRst_SpgPresAcq(void)
{
   SpgPresAcq_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlMid_SpgPresAcq                                  */
/* !Description :  Moniteur moyen pour la fonction AirPres                    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_R_10_01081_001.03                                     */
/*                 VEMS_R_10_01081_007.02                                     */
/*                 VEMS_E_10_01081_008.01                                     */
/*                 VEMS_E_10_01081_009.01                                     */
/*                 VEMS_E_10_01081_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SpgPresAcq_vidBoost_Pressure_Acq();                      */
/*  extf argret void SpgPresAcq_vidBoostPressureDiag();                       */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  extf argret void SpgPresAcq_vidBoostPressureForm();                       */
/*  extf argret void SpgPresAcq_vidBoost_Pressure_Arb();                      */
/*  input uint8 SpgPresAcq_u8Inhib;                                           */
/*  input boolean CoPTSt_bEngRun;                                             */
/*  input boolean Ctrl_bAcv_pUsThr;                                           */
/*  input boolean Ext_bDgoScp_pSpgPres;                                       */
/*  input boolean Ext_bMonRunScp_pSpgPres;                                    */
/*  input boolean Ext_bDgoScg_pSpgPres;                                       */
/*  input boolean Ext_bMonRunScg_pSpgPres;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlMid_SpgPresAcq                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlMid_SpgPresAcq(void)
{
   boolean bLocalCoPTSt_bEngRun;
   boolean bLocalCtrl_bAcv_pUsThr;


   if (SpgPresAcq_u8Inhib != 0x5A)
   {
      VEMS_vidGET(CoPTSt_bEngRun, bLocalCoPTSt_bEngRun);
      if (bLocalCoPTSt_bEngRun == 0)
      {
         VEMS_vidGET(Ctrl_bAcv_pUsThr, bLocalCtrl_bAcv_pUsThr);
         if (bLocalCtrl_bAcv_pUsThr != 0)
         {
            SpgPresAcq_vidBoost_Pressure_Acq();
            SpgPresAcq_vidBoostPressureDiag();
            GDGAR_vidGdu(GD_DFT_SCP_PSPGPRES,
                         Ext_bDgoScp_pSpgPres,
                         Ext_bMonRunScp_pSpgPres,
                         DIAG_DISPO);
            GDGAR_vidGdu(GD_DFT_SCG_PSPGPRES,
                         Ext_bDgoScg_pSpgPres,
                         Ext_bMonRunScg_pSpgPres,
                         DIAG_DISPO);
            SpgPresAcq_vidBoostPressureForm();
            SpgPresAcq_vidBoost_Pressure_Arb();
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_Eve14TDC_SpgPresAcq                                */
/* !Description :  Evénement d'appel de tâche "quart de PMH" du CMM           */
/* !Number      :  SCH.3                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_R_10_01081_001.03                                     */
/*                 VEMS_R_10_01081_007.02                                     */
/*                 VEMS_E_10_01081_008.01                                     */
/*                 VEMS_E_10_01081_009.01                                     */
/*                 VEMS_E_10_01081_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SpgPresAcq_vidBoost_Pressure_Acq();                      */
/*  extf argret void SpgPresAcq_vidBoostPressureDiag();                       */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  extf argret void SpgPresAcq_vidBoostPressureForm();                       */
/*  extf argret void SpgPresAcq_vidBoost_Pressure_Arb();                      */
/*  input uint8 SpgPresAcq_u8Inhib;                                           */
/*  input boolean CoPTSt_bEngRun;                                             */
/*  input boolean Ctrl_bAcv_pUsThr;                                           */
/*  input boolean Ext_bDgoScp_pSpgPres;                                       */
/*  input boolean Ext_bMonRunScp_pSpgPres;                                    */
/*  input boolean Ext_bDgoScg_pSpgPres;                                       */
/*  input boolean Ext_bMonRunScg_pSpgPres;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_Eve14TDC_SpgPresAcq                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_Eve14TDC_SpgPresAcq(void)
{
   boolean bLocalCoPTSt_bEngRun;
   boolean bLocalCtrl_bAcv_pUsThr;


   if (SpgPresAcq_u8Inhib != 0x5A)
   {
      VEMS_vidGET(CoPTSt_bEngRun, bLocalCoPTSt_bEngRun);
      if (bLocalCoPTSt_bEngRun != 0)
      {
         VEMS_vidGET(Ctrl_bAcv_pUsThr, bLocalCtrl_bAcv_pUsThr);
         if (bLocalCtrl_bAcv_pUsThr != 0)
         {
            SpgPresAcq_vidBoost_Pressure_Acq();
            SpgPresAcq_vidBoostPressureDiag();
            GDGAR_vidGdu(GD_DFT_SCP_PSPGPRES,
                         Ext_bDgoScp_pSpgPres,
                         Ext_bMonRunScp_pSpgPres,
                         DIAG_DISPO);
            GDGAR_vidGdu(GD_DFT_SCG_PSPGPRES,
                         Ext_bDgoScg_pSpgPres,
                         Ext_bMonRunScg_pSpgPres,
                         DIAG_DISPO);
            SpgPresAcq_vidBoostPressureForm();
            SpgPresAcq_vidBoost_Pressure_Arb();
         }
      }
   }
}
/*-------------------------------- end of file -------------------------------*/