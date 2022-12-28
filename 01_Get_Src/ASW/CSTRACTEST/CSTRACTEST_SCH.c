/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CSTRACTEST                                              */
/* !Description     : CSTRACTEST component.                                   */
/*                                                                            */
/* !Module          : CSTRACTEST                                              */
/* !Description     : TEST ACTIONNEUR DE PURGE CANISTER.                      */
/*                                                                            */
/* !File            : CSTRACTEST_SCH.C                                        */
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
/*   1 / Cstr_EveRst_ActrTstCstr                                              */
/*   2 / Cstr_SdlMid_ActrTstCstr                                              */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CSTR/CSTRACTEST/CSTRACTEST_SCH.C_v$*/
/* $Revision::   1.2      $$Author::   wbouach        $$Date::   15 Dec 2009 $*/
/* $Author::   wbouach                                $$Date::   15 Dec 2009 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "CSTRACTEST.h"
#include "CSTRACTEST_L.h"
#include "CSTRACTEST_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Evénement reset du calculateur.                             */
/* !Number      : SCH.1                                                       */
/* !Reference   : V02 NT 09 00924 / 03                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf argret void CSTRACTEST_vidInitOutput();                             */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Cstr_EveRst_ActrTstCstr                                        */
/* !Trigger  : Cstr_EveRst_ActrTstCstr                                        */
/*                                                                            */
/* !LastAuthor  : M.BOUKADIDA                                                 */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_EveRst_ActrTstCstr(void)
{
   CSTRACTEST_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Moniteur moyen de la fonction commande purge canister       */
/* !Number      : SCH.2                                                       */
/* !Reference   : V02 NT 09 00924 / 03                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf argret void CSTRACTEST_vidCmdState();                               */
/*                                                                            */
/*   input uint8 CSTRACTEST_u8Inhib;                                          */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Cstr_SdlMid_ActrTstCstr                                        */
/* !Trigger  : Cstr_SdlMid_ActrTstCstr                                        */
/*                                                                            */
/* !LastAuthor  : M.BOUKADIDA                                                 */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_SdlMid_ActrTstCstr(void)
{
   if (CSTRACTEST_u8Inhib != 0x5A)
   {
      CSTRACTEST_vidCmdState();
   }
}

/*---------------------------- end of file -----------------------------------*/