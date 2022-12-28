/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COTDIAG                                                 */
/* !Description     : COTDIAG Component.                                      */
/*                                                                            */
/* !Module          : COTDIAG                                                 */
/* !Description     : Diagnostic fonctionnel de la température d’eau.         */
/*                                                                            */
/* !File            : COTDIAG_SCH.C                                           */
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
/*   1 / COTDIAG_vidEntryInit                                                 */
/*   2 / CoT_EveRst_FctDiagCoT                                                */
/*   3 / CoT_EveCrTR_FctDiagCoT                                               */
/*   4 / CoT_SdlSlow_FctDiagCoT                                               */
/*                                                                            */
/* !Reference   : V02 NT 09 00859 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/COTDIAG/COTDIAG_SCH.C_v           $*/
/* $Revision::   1.4      $$Author::   croche2        $$Date::   15 Oct 2012 $*/
/* $Author::   croche2                                $$Date::   15 Oct 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "GDGAR.h"
#include "COTDIAG.h"
#include "COTDIAG_L.h"
#include "COTDIAG_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COTDIAG_vidEntryInit                                       */
/* !Description :  Fonction d'accroche au moniteur RESET.                     */
/* !Number      :  SCH.1                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COTDIAG_vidInitOutput();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : COTDIAG_vidEntryInit                                           */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COTDIAG_vidEntryInit(void)
{
   COTDIAG_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoT_EveRst_FctDiagCoT                                      */
/* !Description :  Evènement reset de l'ECU                                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COTDIAG_vidFunctDiagCoTempInit();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoT_EveRst_FctDiagCoT                                          */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoT_EveRst_FctDiagCoT(void)
{
   /*F01_FctDiagCoT_Init*/
   COTDIAG_vidFunctDiagCoTempInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoT_EveCrTR_FctDiagCoT                                     */
/* !Description :  Evènement Crank To Run.                                    */
/* !Number      :  SCH.3                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COTDIAG_vidFunctDiagCoTempInit();                        */
/*  input uint8 COTDIAG_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoT_EveCrTR_FctDiagCoT                                         */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoT_EveCrTR_FctDiagCoT(void)
{
   if (COTDIAG_u8Inhib != 0x5A)
   {
      /*F01_FctDiagCoT_Init*/
      COTDIAG_vidFunctDiagCoTempInit();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoT_SdlSlow_FctDiagCoT                                     */
/* !Description :  Moniteur lent                                              */
/* !Number      :  SCH.4                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COTDIAG_vidFunctDiagCoTemp();                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 COTDIAG_u8Inhib;                                              */
/*  input boolean CoT_bDgoWup_tCoMes;                                         */
/*  input boolean CoT_bMonRunWup_tCoMes;                                      */
/*  input boolean CoT_bMonWaitWup_tCoMes;                                     */
/*  input boolean CoT_bDgoTrck_tCoMes;                                        */
/*  input boolean CoT_bMonRunTrck_tCoMes;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoT_SdlSlow_FctDiagCoT                                         */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoT_SdlSlow_FctDiagCoT(void)
{
   if (COTDIAG_u8Inhib != 0x5A)
   {
      /*F02_FctDiagCoT_Diag*/
      COTDIAG_vidFunctDiagCoTemp();

      /*Wup_tCoMes*/
      GDGAR_vidGdu(GD_DFT_WUP_TCOMES,
                   CoT_bDgoWup_tCoMes,
                   CoT_bMonRunWup_tCoMes,
                   CoT_bMonWaitWup_tCoMes);

      /*Trck_tCoMes*/
      GDGAR_vidGdu(GD_DFT_TRCK_TCOMES,
                   CoT_bDgoTrck_tCoMes,
                   CoT_bMonRunTrck_tCoMes,
                   DIAG_DISPO);
   }
}

/************************************* end of file ****************************/