/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : WGCCMD                                                  */
/* !Description     : WGCCMD Component                                        */
/*                                                                            */
/* !Module          : WGCCMD                                                  */
/* !Description     : WASTEGATE COMMAND AND DIAGNOSIS                         */
/*                                                                            */
/* !File            : WGCCMD_SCH.C                                            */
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
/*   1 / Wg_EveRst_WgcCmd                                                     */
/*   2 / Wg_SdlMid_WgcCmd                                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_6851415 / 01                                        */
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
#include "WGCCMD.h"
#include "WGCCMD_L.h"
#include "WGCCMD_IM.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Wg_EveRst_WgcCmd                                           */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_10_01186_001.01                                     */
/*                 VEMS_E_10_01186_002.01                                     */
/*                 VEMS_E_10_01186_003.01                                     */
/*                 VEMS_E_10_01186_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void WgcCmd_vidInitOutput();                                  */
/*  extf argret void WgcCmd_vidWgcTreatment();                                */
/*  extf argret void WgcCmd_vidWgcCmdApplication();                           */
/*  extf argret void WgcCmd_vidDiagnostic();                                  */
/*  input boolean Ctrl_bTrbAct_rCtl;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Wg_EveRst_WgcCmd                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Wg_EveRst_WgcCmd(void)
{
   boolean bLocalCtrl_bTrbAct_rCtl;

   VEMS_vidGET(Ctrl_bTrbAct_rCtl, bLocalCtrl_bTrbAct_rCtl);
   WgcCmd_vidInitOutput();
   if (bLocalCtrl_bTrbAct_rCtl != 0)
   {
      WgcCmd_vidWgcTreatment();
      WgcCmd_vidWgcCmdApplication();
      WgcCmd_vidDiagnostic();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Wg_SdlMid_WgcCmd                                           */
/* !Description :  Moniteur moyen pour la fonction AirPres                    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_10_01186_001.01                                     */
/*                 VEMS_E_10_01186_002.01                                     */
/*                 VEMS_E_10_01186_003.01                                     */
/*                 VEMS_E_10_01186_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void WgcCmd_vidWgcTreatment();                                */
/*  extf argret void WgcCmd_vidWgcCmdApplication();                           */
/*  extf argret void WgcCmd_vidDiagnostic();                                  */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input boolean Ctrl_bTrbAct_rCtl;                                          */
/*  input uint8 WgcCmd_u8Inhib;                                               */
/*  input boolean Wg_bDgoLo_WgcCmd;                                           */
/*  input boolean Wg_bMonRunLo_WgcCmd;                                        */
/*  input boolean Wg_bDgoHi_WgcCmd;                                           */
/*  input boolean Wg_bMonRunHi_WgcCmd;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Wg_SdlMid_WgcCmd                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Wg_SdlMid_WgcCmd(void)
{
   boolean bLocalCtrl_bTrbAct_rCtl;

   VEMS_vidGET(Ctrl_bTrbAct_rCtl, bLocalCtrl_bTrbAct_rCtl);
   if (WgcCmd_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bTrbAct_rCtl != 0)
      {
         WgcCmd_vidWgcTreatment();
         WgcCmd_vidWgcCmdApplication();
         WgcCmd_vidDiagnostic();
         GDGAR_vidGdu(GD_DFT_LO_WGCCMD,
                      Wg_bDgoLo_WgcCmd,
                      Wg_bMonRunLo_WgcCmd,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_HI_WGCCMD,
                      Wg_bDgoHi_WgcCmd,
                      Wg_bMonRunHi_WgcCmd,
                      DIAG_DISPO);
      }
   }
}
/*------------------------------ End of file ---------------------------------*/