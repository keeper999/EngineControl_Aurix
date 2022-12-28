/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DGOHALACQINJ                                            */
/* !Description     : DGOHALACQINJ component.                                 */
/*                                                                            */
/* !Module          : DGOHALACQINJ                                            */
/* !Description     : Acquisition of Diagnoses States and results for         */
/*                    injectors                                               */
/*                                                                            */
/* !File            : DGOHALACQINJ_SCH.C                                      */
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
/*   1 / Inj_SdlFast_DgoHalAcqInj                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_6913684 / 01                                        */
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
#include "DGOHALACQINJ.h"
#include "DGOHALACQINJ_L.h"
#include "DGOHALACQINJ_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Inj_SdlFast_DgoHalAcqInj                                   */
/* !Description :  Moniteur rapide pour la commande des injecteurs            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  M.Boubakri                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DGOHALACQINJ_vidInjectorsDiag();                         */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 DGOHALACQINJ_u8Inhib;                                         */
/*  input boolean Ext_bDgoScp_Inj1Cmd;                                        */
/*  input boolean Ext_bMonRunScp_Inj1Cmd;                                     */
/*  input boolean Ext_bDgoOc_Inj1Cmd;                                         */
/*  input boolean Ext_bMonRunOc_Inj1Cmd;                                      */
/*  input boolean Ext_bDgoScg_Inj1Cmd;                                        */
/*  input boolean Ext_bMonRunScg_Inj1Cmd;                                     */
/*  input boolean Ext_bDgoOvld_Inj1Cmd;                                       */
/*  input boolean Ext_bMonRunOvld_Inj1Cmd;                                    */
/*  input boolean Ext_bDgoScp_Inj3Cmd;                                        */
/*  input boolean Ext_bMonRunScp_Inj3Cmd;                                     */
/*  input boolean Ext_bDgoOc_Inj3Cmd;                                         */
/*  input boolean Ext_bMonRunOc_Inj3Cmd;                                      */
/*  input boolean Ext_bDgoScg_Inj3Cmd;                                        */
/*  input boolean Ext_bMonRunScg_Inj3Cmd;                                     */
/*  input boolean Ext_bDgoOvld_Inj3Cmd;                                       */
/*  input boolean Ext_bMonRunOvld_Inj3Cmd;                                    */
/*  input boolean Ext_bDgoScp_Inj2Cmd;                                        */
/*  input boolean Ext_bMonRunScp_Inj2Cmd;                                     */
/*  input boolean Ext_bDgoOc_Inj2Cmd;                                         */
/*  input boolean Ext_bMonRunOc_Inj2Cmd;                                      */
/*  input boolean Ext_bDgoScg_Inj2Cmd;                                        */
/*  input boolean Ext_bMonRunScg_Inj2Cmd;                                     */
/*  input boolean Ext_bDgoOvld_Inj2Cmd;                                       */
/*  input boolean Ext_bMonRunOvld_Inj2Cmd;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Inj_SdlFast_DgoHalAcqInj                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Inj_SdlFast_DgoHalAcqInj(void)
{
   if (DGOHALACQINJ_u8Inhib != 0x5A)
   {
      DGOHALACQINJ_vidInjectorsDiag();
      /* INJ1 */
      GDGAR_vidGdu(GD_DFT_SCP_INJ1CMD,
                   Ext_bDgoScp_Inj1Cmd,
                   Ext_bMonRunScp_Inj1Cmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_OC_INJ1CMD,
                   Ext_bDgoOc_Inj1Cmd,
                   Ext_bMonRunOc_Inj1Cmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCG_INJ1CMD,
                   Ext_bDgoScg_Inj1Cmd,
                   Ext_bMonRunScg_Inj1Cmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_OVLD_INJ1CMD,
                   Ext_bDgoOvld_Inj1Cmd,
                   Ext_bMonRunOvld_Inj1Cmd ,
                   DIAG_DISPO);
      /* INJ3 */
      GDGAR_vidGdu(GD_DFT_SCP_INJ3CMD,
                   Ext_bDgoScp_Inj3Cmd,
                   Ext_bMonRunScp_Inj3Cmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_OC_INJ3CMD,
                   Ext_bDgoOc_Inj3Cmd,
                   Ext_bMonRunOc_Inj3Cmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCG_INJ3CMD,
                   Ext_bDgoScg_Inj3Cmd,
                   Ext_bMonRunScg_Inj3Cmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_OVLD_INJ3CMD,
                   Ext_bDgoOvld_Inj3Cmd,
                   Ext_bMonRunOvld_Inj3Cmd ,
                   DIAG_DISPO);
      /* INJ2 */
      GDGAR_vidGdu(GD_DFT_SCP_INJ2CMD,
                   Ext_bDgoScp_Inj2Cmd,
                   Ext_bMonRunScp_Inj2Cmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_OC_INJ2CMD,
                   Ext_bDgoOc_Inj2Cmd,
                   Ext_bMonRunOc_Inj2Cmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCG_INJ2CMD,
                   Ext_bDgoScg_Inj2Cmd,
                   Ext_bMonRunScg_Inj2Cmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_OVLD_INJ2CMD,
                   Ext_bDgoOvld_Inj2Cmd,
                   Ext_bMonRunOvld_Inj2Cmd ,
                   DIAG_DISPO);
   }
}
/*------------------------------- end of file --------------------------------*/