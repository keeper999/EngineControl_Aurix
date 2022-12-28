/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : STRTRCMDDIAG                                            */
/* !Description     : STRTRCMDDIAG component                                  */
/*                                                                            */
/* !Module          : STRTRCMDDIAG                                            */
/* !Description     : COMMANDE ET DIAGNOSTIC DE LA SORTIE LOGIQUE DML         */
/*                                                                            */
/* !File            : STRTRCMDDIAG_SCH.C                                      */
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
/*   1 / Strtr_EveRst_IfCmdDiag                                               */
/*   2 / Strtr_SdlMid_IfCmdDiag                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_6528767 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/STRTRCMDDIAG/STRTRCMDDIAG_SCH.C_v $*/
/* $Revision::   1.8                                                         $*/
/* $Author::   wbouach                                $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "STRTRCMDDIAG.H"
#include "STRTRCMDDIAG_L.H"
#include "STRTRCMDDIAG_IM.H"
#include "GDGAR.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Strtr_EveRst_IfCmdDiag                                     */
/* !Description :  Fonction d'accroche à l'événement reset du calculateur     */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  PTS_R_5603587_01.01                                        */
/*                 PTS_R_5603587_02.01                                        */
/*                 PTS_R_5603587_03.01                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void STRTRCMDDIAG_vidIni();                                   */
/*  extf argret void STRTRCMDDIAG_vidCmdStrtrRly();                           */
/*  extf argret void STRTRCMDDIAG_vidCondResetTempo();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Strtr_EveRst_IfCmdDiag                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Strtr_EveRst_IfCmdDiag(void)
{
   STRTRCMDDIAG_vidIni();
   STRTRCMDDIAG_vidCmdStrtrRly();
   STRTRCMDDIAG_vidCondResetTempo();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Strtr_SdlMid_IfCmdDiag                                     */
/* !Description :  Fonction d'accroche à l'événement Strtr_SdlMid_IfCmdDiag   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  PTS_R_5603587_01.01                                        */
/*                 PTS_R_5603587_02.01                                        */
/*                 PTS_R_5603587_03.01                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void STRTRCMDDIAG_vidCmdStrtrRly();                           */
/*  extf argret void STRTRCMDDIAG_vidDiagStrtrRly();                          */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 STRTRCMDDIAG_u8Inhib;                                         */
/*  input boolean Ext_bDgoScp_Dml;                                            */
/*  input boolean Ext_bMonRunScp_Dml;                                         */
/*  input boolean Ext_bMonWaitScp_Dml;                                        */
/*  input boolean Ext_bDgoOc_Dml;                                             */
/*  input boolean Ext_bMonRunOc_Dml;                                          */
/*  input boolean Ext_bMonWaitOc_Dml;                                         */
/*  input boolean Ext_bDgoScg_Dml;                                            */
/*  input boolean Ext_bMonRunScg_Dml;                                         */
/*  input boolean Ext_bMonWaitScg_Dml;                                        */
/*  input boolean Strtr_bDgoBlock_Strtr;                                      */
/*  input boolean Strtr_bMonRunBlock_Strtr;                                   */
/*  input boolean Strtr_bMonWaitBlock_Strtr;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Strtr_SdlMid_IfCmdDiag                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Strtr_SdlMid_IfCmdDiag(void)
{
   if (STRTRCMDDIAG_u8Inhib != 0x5A)
   {
      STRTRCMDDIAG_vidCmdStrtrRly();
      STRTRCMDDIAG_vidDiagStrtrRly();

      GDGAR_vidGdu(GD_DFT_SCP_DML,
                   Ext_bDgoScp_Dml,
                   Ext_bMonRunScp_Dml,
                   Ext_bMonWaitScp_Dml);
      GDGAR_vidGdu(GD_DFT_OC_DML,
                   Ext_bDgoOc_Dml,
                   Ext_bMonRunOc_Dml,
                   Ext_bMonWaitOc_Dml);
      GDGAR_vidGdu(GD_DFT_SCG_DML,
                   Ext_bDgoScg_Dml,
                   Ext_bMonRunScg_Dml,
                   Ext_bMonWaitScg_Dml);
      GDGAR_vidGdu(GD_DFT_BLOCK_STRTR,
                   Strtr_bDgoBlock_Strtr,
                   Strtr_bMonRunBlock_Strtr,
                   Strtr_bMonWaitBlock_Strtr);
   }
}
/*------------------------------- end of file --------------------------------*/