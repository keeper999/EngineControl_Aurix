/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKDIAG                                                 */
/* !Description     : KNKDIAG component.                                      */
/*                                                                            */
/* !Module          : KNKDIAG                                                 */
/* !Description     : DIAGNOSTIC DU CAPTEUR CLIQUETIS.                        */
/*                                                                            */
/* !File            : KNKDIAG_SCH.C                                           */
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
/*   1 / KNKDIAG_vidEntryInit                                                 */
/*   2 / KnkTreat_EveKnk_KnkDiag                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5307525 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/KNKTREAT/KNKDIAG/KNKDIAG_SCH.C_v  $*/
/* $Revision::   1.4      $$Author::   wbouach        $$Date::   04 Apr 2012 $*/
/* $Author::   wbouach                                $$Date::   04 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "KNKDIAG.h"
#include "KNKDIAG_L.h"
#include "KNKDIAG_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDIAG_vidEntryInit                                       */
/* !Description :  Evènement RESET de scheduler.                              */
/* !Number      :  SCH.1                                                      */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKDIAG_vidInitOutput();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KNKDIAG_vidEntryInit                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDIAG_vidEntryInit(void)
{
   KNKDIAG_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveKnk_KnkDiag                                    */
/* !Description :  Tâche de cacul du niveau de cliquetis pour le cylindre en  */
/*                 cours.                                                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKDIAG_vidTreatment();                                  */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean bDiagStWait);                         */
/*  input uint8 KNKDIAG_u8Inhib;                                              */
/*  input boolean KnkTreat_bDgoORng_KnkDiag;                                  */
/*  input boolean KnkTreat_bMonRun_KnkDiag;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveKnk_KnkDiag                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveKnk_KnkDiag(void)
{
   if(KNKDIAG_u8Inhib != 0x5A)
   {
      KNKDIAG_vidTreatment();
      GDGAR_vidGdu(GD_DFT_ORNG_KNKDIAG,
                   KnkTreat_bDgoORng_KnkDiag,
                   KnkTreat_bMonRun_KnkDiag,
                   DIAG_DISPO);
   }
}
/*-------------------------------- End of file -------------------------------*/