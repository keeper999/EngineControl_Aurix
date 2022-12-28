/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACCPSTUCKDIAG                                           */
/* !Description     : ACCPSTUCKDIAG component.                                */
/*                                                                            */
/* !Module          : ACCPSTUCKDIAG                                           */
/* !Description     : Diagnostic fonctionnel pedale accelerateur bloquée      */
/*                                                                            */
/* !File            : ACCPSTUCKDIAG_SCH.C                                     */
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
/*   1 / AccP_EveRst_MonStuckAccP                                             */
/*   2 / AccP_SdlFast_MonStuckAccP                                            */
/*                                                                            */
/* !Reference   : V02 NT 09 01550 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACCP/ACCPSTUCKDIAG/ACCPSTUCKDIAG_S$*/
/* $Revision::   1.4      $$Author::   ACHEBINO       $$Date::   09 Feb 2012 $*/
/* $Author::   ACHEBINO                               $$Date::   09 Feb 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "ACCPSTUCKDIAG.h"
#include "ACCPSTUCKDIAG_L.h"
#include "ACCPSTUCKDIAG_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_EveRst_MonStuckAccP                                   */
/* !Description :  Evènement reset de l'ECU                                   */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.JLIZI                                                    */
/* !Trace_To    :  VEMS_R_09_01550_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPSTUCKDIAG_vidInitOutput();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AccP_EveRst_MonStuckAccP                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_EveRst_MonStuckAccP(void)
{
   ACCPSTUCKDIAG_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_SdlFast_MonStuckAccP                                  */
/* !Description :  Moniteur rapide                                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.JLIZI                                                    */
/* !Trace_To    :  VEMS_R_09_01550_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPSTUCKDIAG_vidStuckAccPPdlin();                       */
/*  extf argret void ACCPSTUCKDIAG_vidStuckAccPMonRun();                      */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 ACCPSTUCKDIAG_u8Inhib;                                        */
/*  input boolean AccP_bDgoStuckAccP;                                         */
/*  input boolean AccP_bMonRunStuckAccP;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AccP_SdlFast_MonStuckAccP                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_SdlFast_MonStuckAccP(void)
{
   if (ACCPSTUCKDIAG_u8Inhib != 0x5A)
   {
      ACCPSTUCKDIAG_vidStuckAccPPdlin();
      ACCPSTUCKDIAG_vidStuckAccPMonRun();
      GDGAR_vidGdu(GD_DFT_STUCKACCP,
                   AccP_bDgoStuckAccP,
                   AccP_bMonRunStuckAccP,
                   DIAG_DISPO);
   }
}
/*------------------------------- end of file --------------------------------*/