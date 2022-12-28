/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AccP                                                    */
/* !Description     : AccP component.                                         */
/*                                                                            */
/* !Module          : ACCPACQPOS                                              */
/* !Description     : Acquisition de la position pedale                       */
/*                                                                            */
/* !File            : ACCPACQPOS_SCH.c                                        */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / AccP_EveRst_AcqPosn                                                  */
/*   2 / AccP_SdlFast_AcqPosn                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6601121 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ACCP/ACCPACQPOS/ACCPACQPOS_SCH.c_v$*/
/* $Revision::   1.9      $$Author::   achebino       $$Date::   23 Sep 2014 $*/
/* $Author::   achebino                               $$Date::   23 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "ACCPACQPOS.h"
#include "ACCPACQPOS_L.h"
#include "ACCPACQPOS_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_EveRst_AcqPosn                                        */
/* !Description :  Fonction d'accroche à l'evenement AccP_EveRst_AcqPosn      */
/* !Number      :  SCH.1                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_5197989_001.01                                      */
/*                 VEMS_E_5197989_002.01                                      */
/*                 VEMS_E_5197989_003.01                                      */
/*                 VEMS_R_5197989_007.02                                      */
/*                 PTS_R_6601121_001.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPACQPOS_vidInitOutput();                              */
/*  extf argret void ACCPACQPOS_vidInit();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :  AccP_EveRst_AcqPosn                                           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_EveRst_AcqPosn(void)
{
   ACCPACQPOS_vidInitOutput();
   ACCPACQPOS_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_SdlFast_AcqPosn                                       */
/* !Description :  Fonction d'accroche à l'evenement AccP_SdlFast_AcqPosn     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_5197989_001.01                                      */
/*                 VEMS_E_5197989_002.01                                      */
/*                 VEMS_E_5197989_003.01                                      */
/*                 VEMS_R_5197989_007.02                                      */
/*                 PTS_R_6601121_001.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPACQPOS_vidPosPedalAcquisition();                     */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 ACCPACQPOS_u8Inhib;                                           */
/*  input boolean Ext_bDgoCoh_Ped;                                            */
/*  input boolean Ext_bMonRunCoh_Ped;                                         */
/*  input boolean Ext_bDgoScpOc_Ped2;                                         */
/*  input boolean Ext_bMonRunScpOc_Ped2;                                      */
/*  input boolean Ext_bDgoScg_Ped2;                                           */
/*  input boolean Ext_bMonRunScg_Ped2;                                        */
/*  input boolean Ext_bDgoScpOc_Ped1;                                         */
/*  input boolean Ext_bMonRunScpOc_Ped1;                                      */
/*  input boolean Ext_bDgoScg_Ped1;                                           */
/*  input boolean Ext_bMonRunScg_Ped1;                                        */
/*  input boolean Ext_bDgoDftSenr_AccP;                                       */
/*  input boolean Ext_bMonRunDftSenr_AccP;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :  AccP_SdlFast_AcqPosn                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_SdlFast_AcqPosn(void)
{
   if (ACCPACQPOS_u8Inhib != 0x5A)
   {
      ACCPACQPOS_vidPosPedalAcquisition();
      GDGAR_vidGdu(GD_DFT_COH_PED,
                   Ext_bDgoCoh_Ped,
                   Ext_bMonRunCoh_Ped,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCPOC_PED2,
                   Ext_bDgoScpOc_Ped2,
                   Ext_bMonRunScpOc_Ped2,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCG_PED2,
                   Ext_bDgoScg_Ped2,
                   Ext_bMonRunScg_Ped2,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCPOC_PED1,
                   Ext_bDgoScpOc_Ped1,
                   Ext_bMonRunScpOc_Ped1,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCG_PED1,
                   Ext_bDgoScg_Ped1,
                   Ext_bMonRunScg_Ped1,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_DFTSENR_ACCP,
                   Ext_bDgoDftSenr_AccP,
                   Ext_bMonRunDftSenr_AccP,
                   DIAG_DISPO);
   }
}
/*---------------------------- end of file -----------------------------------*/