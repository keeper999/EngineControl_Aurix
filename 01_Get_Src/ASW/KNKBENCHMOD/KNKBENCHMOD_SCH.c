/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKBENCHMOD                                             */
/* !Description     : KNKBENCHMOD Component                                   */
/*                                                                            */
/* !Module          : KNKBENCHMOD                                             */
/* !Description     : MODE BANC POUR LA CALIBRATION DE LA STRATEGIE DE        */
/*                    DETECTION DE CLIQUETIS                                  */
/*                                                                            */
/* !File            : KNKBENCHMOD_SCH.C                                       */
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
/*   1 / KNKBENCHMOD_vidEntryInit                                             */
/*   2 / KnkTreat_EveKnk_BenchMod                                             */
/*                                                                            */
/* !Reference   : V02 NT 09 00486 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/KNKTREAT/KNKBENCHMOD/KNKBENCHMOD_S$*/
/* $Revision::   1.3      $$Author::   wbouach        $$Date::   26 Oct 2010 $*/
/* $Author::   wbouach                                $$Date::   26 Oct 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "KNKBENCHMOD.h"
#include "KNKBENCHMOD_L.h"
#include "KNKBENCHMOD_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKBENCHMOD_vidEntryInit                                   */
/* !Description :  Fonction moniteur Reset                                    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKBENCHMOD_vidInitialization();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KNKBENCHMOD_vidEntryInit                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKBENCHMOD_vidEntryInit(void)
{
   KNKBENCHMOD_vidInitialization();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveKnk_BenchMod                                   */
/* !Description :  Tâche de calcul du niveau de cliquetis pour le cylindre en */
/*                 cours                                                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKBENCHMOD_vidTestBed();                                */
/*  input uint8 KNKBENCHMOD_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveKnk_BenchMod                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveKnk_BenchMod(void)
{
   if (KNKBENCHMOD_u8Inhib != 0x5A)
   {
      KNKBENCHMOD_vidTestBed();
   }
}

/*------------------------------- end of file --------------------------------*/