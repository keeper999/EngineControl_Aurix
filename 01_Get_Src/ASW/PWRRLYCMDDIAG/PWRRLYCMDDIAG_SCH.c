/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PWRRLYCMDDIAG                                           */
/* !Description     : PWRRLYCMDDIAG component.                                */
/*                                                                            */
/* !Module          : PWRRLYCMDDIAG                                           */
/* !Description     : COMMANDE ET DIAGNOSTIC DE LA SORTIE LOGIQUE ACTIONNEURS */
/*                                                                            */
/* !File            : PWRRLYCMDDIAG_SCH.C                                     */
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
/*   1 / PwrRly_EveRst_IfCmdDiag                                              */
/*   2 / PwrRly_SdlMid_IfCmdDiag                                              */
/*   3 / PwrRly_EveKOn_IfCmdDiag                                              */
/*   4 / PwrRly_EveCkOn_IfCmdDiag                                             */
/*   5 / PwrRly_SdlFast_IfCmdDiag                                             */
/*   6 / PwrRly_SdlSlow_IfCmdDiag                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_6561228 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/RLY/PWRRLYCMDDIAG/PWRRLYCMDDIAG_SC$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   hmelloul                               $$Date::   19 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "PWRRLYCMDDIAG.h"
#include "PWRRLYCMDDIAG_l.h"
#include "PWRRLYCMDDIAG_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PwrRly_EveRst_IfCmdDiag                                    */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Ines Omezzine                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRRLYCMDDIAG_vidInitOutput();                           */
/*  extf argret void PWRRLYCMDDIAG_vidCmd();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PwrRly_EveRst_IfCmdDiag                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PwrRly_EveRst_IfCmdDiag(void)
{
   PWRRLYCMDDIAG_vidInitOutput();
   PWRRLYCMDDIAG_vidCmd();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PwrRly_SdlMid_IfCmdDiag                                    */
/* !Description :  Moniteur moyen du relais puissance                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Ines Omezzine                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRRLYCMDDIAG_vidCmd();                                  */
/*  input uint8 PWRRLYCMDDIAG_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PwrRly_SdlMid_IfCmdDiag                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PwrRly_SdlMid_IfCmdDiag(void)
{
   if (PWRRLYCMDDIAG_u8Inhib != 0x5A)
   {
      PWRRLYCMDDIAG_vidCmd();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PwrRly_EveKOn_IfCmdDiag                                    */
/* !Description :  Evénement associé au passage de clef OFF à clef ON         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Ines Omezzine                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRRLYCMDDIAG_vidCmd();                                  */
/*  input uint8 PWRRLYCMDDIAG_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PwrRly_EveKOn_IfCmdDiag                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PwrRly_EveKOn_IfCmdDiag(void)
{
   if (PWRRLYCMDDIAG_u8Inhib != 0x5A)
   {
      PWRRLYCMDDIAG_vidCmd();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PwrRly_EveCkOn_IfCmdDiag                                   */
/* !Description :  Evènement de détection rotation moteur                     */
/* !Number      :  SCH.4                                                      */
/* !Author      :  Ines Omezzine                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRRLYCMDDIAG_vidCmd();                                  */
/*  input uint8 PWRRLYCMDDIAG_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PwrRly_EveCkOn_IfCmdDiag                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PwrRly_EveCkOn_IfCmdDiag(void)
{
   if (PWRRLYCMDDIAG_u8Inhib != 0x5A)
   {
      PWRRLYCMDDIAG_vidCmd();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PwrRly_SdlFast_IfCmdDiag                                   */
/* !Description :  Moniteur rapide du relais puissance                        */
/* !Number      :  SCH.5                                                      */
/* !Author      :  Ines Omezzine                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRRLYCMDDIAG_vidDiagAct();                              */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 PWRRLYCMDDIAG_u8Inhib;                                        */
/*  input boolean PwrRlyHw_bDgoScp_PwrRly;                                    */
/*  input boolean PwrRlyHw_bMonRunScp_PwrRly;                                 */
/*  input boolean PwrRlyHw_bDgoOc_PwrRly;                                     */
/*  input boolean PwrRlyHw_bMonRunOc_PwrRly;                                  */
/*  input boolean PwrRlyHw_bDgoScg_PwrRly;                                    */
/*  input boolean PwrRlyHw_bMonRunScg_PwrRly;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PwrRly_SdlFast_IfCmdDiag                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PwrRly_SdlFast_IfCmdDiag(void)
{
   if (PWRRLYCMDDIAG_u8Inhib != 0x5A)
   {
      PWRRLYCMDDIAG_vidDiagAct();
      GDGAR_vidGdu(GD_DFT_SCP_PWRRLY,
                   PwrRlyHw_bDgoScp_PwrRly,
                   PwrRlyHw_bMonRunScp_PwrRly,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_OC_PWRRLY,
                   PwrRlyHw_bDgoOc_PwrRly,
                   PwrRlyHw_bMonRunOc_PwrRly,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCG_PWRRLY,
                   PwrRlyHw_bDgoScg_PwrRly,
                   PwrRlyHw_bMonRunScg_PwrRly,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PwrRly_SdlSlow_IfCmdDiag                                   */
/* !Description :  Moniteur lent du relais puissance                          */
/* !Number      :  SCH.6                                                      */
/* !Author      :  Ines Omezzine                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRRLYCMDDIAG_vidDiagExt();                              */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 PWRRLYCMDDIAG_u8Inhib;                                        */
/*  input boolean PwrRlyHw_bDgoStuck_PwrRly;                                  */
/*  input boolean PwrRlyHw_bMonRunStuck_PwrRly;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PwrRly_SdlSlow_IfCmdDiag                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PwrRly_SdlSlow_IfCmdDiag(void)
{
   if (PWRRLYCMDDIAG_u8Inhib != 0x5A)
   {
      PWRRLYCMDDIAG_vidDiagExt();
      GDGAR_vidGdu(GD_DFT_STUCK_PWRRLY,
                   PwrRlyHw_bDgoStuck_PwrRly,
                   PwrRlyHw_bMonRunStuck_PwrRly,
                   DIAG_DISPO);
   }
}

/*------------------------------- end of file --------------------------------*/