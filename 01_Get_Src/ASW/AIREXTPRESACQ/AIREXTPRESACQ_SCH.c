/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AIREXTPRESACQ                                           */
/* !Description     : AIREXTPRESACQ Component.                                */
/*                                                                            */
/* !Module          : AIREXTPRESACQ                                           */
/* !Description     : Atmospheric Pressure Acquisition.                       */
/*                                                                            */
/* !File            : AIREXTPRESACQ_SCH.C                                     */
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
/*   1 / AirPres_EveRst_AirExtPresAcq                                         */
/*   2 / AirPres_SdlFast_AirExtPresAcq                                        */
/*   3 / AirPres_SdlSlow_AirExtPresAcq                                        */
/*   4 / AirPres_SdlMid_AirExtPresAcq                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_6525166 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#065883                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/AIREXTPRESACQ/AIREXTPRESACQ_SCH.C_$*/
/* $Revision::   1.0      $$Author::   achebino       $$Date::   26 May 2014 $*/
/* $Author::   achebino                               $$Date::   26 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "AIREXTPRESACQ.h"
#include "AIREXTPRESACQ_L.h"
#include "AIREXTPRESACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_EveRst_AirExtPresAcq                               */
/* !Description :  EveRst for AirExtPresAcq                                   */
/* !Number      :  SCH.1                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_11_03695_001.01                                     */
/*                 VEMS_E_11_03695_002.01                                     */
/*                 VEMS_E_11_03695_003.01                                     */
/*                 VEMS_E_11_03695_004.01                                     */
/*                 VEMS_E_11_03695_005.01                                     */
/*                 VEMS_E_11_03695_006.01                                     */
/*                 VEMS_E_11_03695_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AIREXTPRESACQ_vidInit();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_EveRst_AirExtPresAcq                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_EveRst_AirExtPresAcq(void)
{
   AIREXTPRESACQ_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlFast_AirExtPresAcq                              */
/* !Description :  Fast monitor for AirExtPresAcq                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_11_03695_001.01                                     */
/*                 VEMS_E_11_03695_002.01                                     */
/*                 VEMS_E_11_03695_003.01                                     */
/*                 VEMS_E_11_03695_004.01                                     */
/*                 VEMS_E_11_03695_005.01                                     */
/*                 VEMS_E_11_03695_006.01                                     */
/*                 VEMS_E_11_03695_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void AIREXTPRESACQ_vidCalc();                                 */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 AIREXTPRESACQ_u8Inhib;                                        */
/*  input boolean Ctrl_bAcv_pAirExtMes;                                       */
/*  input boolean Ext_bRun;                                                   */
/*  input boolean Ext_bDgoScp_AirExtPresAcq;                                  */
/*  input boolean Ext_bMonRunScp_AirExtPresAcq;                               */
/*  input boolean Ext_bDgoScg_AirExtPresAcq;                                  */
/*  input boolean Ext_bMonRunScg_AirExtPresAcq;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlFast_AirExtPresAcq                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlFast_AirExtPresAcq(void)
{
   boolean bLocalCtrl_bAcv_pAirExtMes;
   boolean bLocalExt_bRun;


   if (AIREXTPRESACQ_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_pAirExtMes, bLocalCtrl_bAcv_pAirExtMes);
      VEMS_vidGET(Ext_bRun, bLocalExt_bRun);
      if (  (bLocalCtrl_bAcv_pAirExtMes != 0)
         && (bLocalExt_bRun == 0))
      {
         AIREXTPRESACQ_vidCalc();
         GDGAR_vidGdu(GD_DFT_SCP_AIREXTPRESACQ,
                      Ext_bDgoScp_AirExtPresAcq,
                      Ext_bMonRunScp_AirExtPresAcq ,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_SCG_AIREXTPRESACQ,
                      Ext_bDgoScg_AirExtPresAcq,
                      Ext_bMonRunScg_AirExtPresAcq ,
                      DIAG_DISPO);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlSlow_AirExtPresAcq                              */
/* !Description :  Slow monitor for AirExtPresAcq                             */
/* !Number      :  SCH.3                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_11_03695_001.01                                     */
/*                 VEMS_E_11_03695_002.01                                     */
/*                 VEMS_E_11_03695_003.01                                     */
/*                 VEMS_E_11_03695_004.01                                     */
/*                 VEMS_E_11_03695_005.01                                     */
/*                 VEMS_E_11_03695_006.01                                     */
/*                 VEMS_E_11_03695_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void AIREXTPRESACQ_vidCalc();                                 */
/*  extf argret void AIREXTPRESACQ_vidInterfacage();                          */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 AIREXTPRESACQ_u8Inhib;                                        */
/*  input boolean Ctrl_bAcv_pAirExtMes;                                       */
/*  input boolean Ext_bRun;                                                   */
/*  input boolean Ext_bDgoScp_AirExtPresAcq;                                  */
/*  input boolean Ext_bMonRunScp_AirExtPresAcq;                               */
/*  input boolean Ext_bDgoScg_AirExtPresAcq;                                  */
/*  input boolean Ext_bMonRunScg_AirExtPresAcq;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlSlow_AirExtPresAcq                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlSlow_AirExtPresAcq(void)
{
   boolean bLocalCtrl_bAcv_pAirExtMes;
   boolean bLocalExt_bRun;


   if (AIREXTPRESACQ_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_pAirExtMes, bLocalCtrl_bAcv_pAirExtMes);
      VEMS_vidGET(Ext_bRun, bLocalExt_bRun);
      if (  (bLocalCtrl_bAcv_pAirExtMes != 0)
         && (bLocalExt_bRun != 0))
      {
         AIREXTPRESACQ_vidCalc();
         AIREXTPRESACQ_vidInterfacage();
         GDGAR_vidGdu(GD_DFT_SCP_AIREXTPRESACQ,
                      Ext_bDgoScp_AirExtPresAcq,
                      Ext_bMonRunScp_AirExtPresAcq ,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_SCG_AIREXTPRESACQ,
                      Ext_bDgoScg_AirExtPresAcq,
                      Ext_bMonRunScg_AirExtPresAcq ,
                      DIAG_DISPO);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlMid_AirExtPresAcq                               */
/* !Description :  Mid monitor for AirExtPresAcq                              */
/* !Number      :  SCH.4                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_11_03695_001.01                                     */
/*                 VEMS_E_11_03695_002.01                                     */
/*                 VEMS_E_11_03695_003.01                                     */
/*                 VEMS_E_11_03695_004.01                                     */
/*                 VEMS_E_11_03695_005.01                                     */
/*                 VEMS_E_11_03695_006.01                                     */
/*                 VEMS_E_11_03695_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void AIREXTPRESACQ_vidInterfacage();                          */
/*  input uint8 AIREXTPRESACQ_u8Inhib;                                        */
/*  input boolean Ctrl_bAcv_pAirExtMes;                                       */
/*  input boolean Ext_bRun;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlMid_AirExtPresAcq                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlMid_AirExtPresAcq(void)
{
   boolean bLocalCtrl_bAcv_pAirExtMes;
   boolean bLocalExt_bRun;


   if (AIREXTPRESACQ_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_pAirExtMes, bLocalCtrl_bAcv_pAirExtMes);
      VEMS_vidGET(Ext_bRun, bLocalExt_bRun);
      if (  (bLocalCtrl_bAcv_pAirExtMes != 0)
         && (bLocalExt_bRun == 0))
      {
         AIREXTPRESACQ_vidInterfacage();
      }
   }
}

/*------------------------------- end of file --------------------------------*/