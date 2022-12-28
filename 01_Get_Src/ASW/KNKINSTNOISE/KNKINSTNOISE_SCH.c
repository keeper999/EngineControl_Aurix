/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKINSTNOISE                                            */
/* !Description     : KNKINSTNOISE Component                                  */
/*                                                                            */
/* !Module          : KNKINSTNOISE                                            */
/* !Description     : CALCUL DU BRUIT INSTANTANE POUR LA STRATEGIE DE         */
/*                    DETECTION DE CLIQUETIS                                  */
/*                                                                            */
/* !File            : KNKINSTNOISE_SCH.C                                      */
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
/*   1 / KnkTreat_EveRst_InstNoise                                            */
/*   2 / KnkTreat_EveCkSnOn_InstNoise                                         */
/*   3 / KnkTreat_EveKnk_InstNoise                                            */
/*                                                                            */
/* !Reference   : V02 NT 08 05345 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#050451                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/KNKTREAT/KNKINSTNOISE/KNKINSTNOISE$*/
/* $Revision::   1.4      $$Author::   wbouach        $$Date::   19 Oct 2010 $*/
/* $Author::   wbouach                                $$Date::   19 Oct 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "KNKINSTNOISE.h"
#include "KNKINSTNOISE_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveRst_InstNoise                                  */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  W.AKKARI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKINSTNOISE_vidInitInstantNoise();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveRst_InstNoise                                      */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveRst_InstNoise(void)
{
   KNKINSTNOISE_vidInitInstantNoise();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveCkSnOn_InstNoise                               */
/* !Description :  Evénement correspondant au passage à 1 de la variable      */
/*                 Moteur_synchronise                                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  W.AKKARI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKINSTNOISE_vidInitInstantNoise();                      */
/*  input uint8 KNKINSTNOISE_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveCkSnOn_InstNoise                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveCkSnOn_InstNoise(void)
{
   if (KNKINSTNOISE_u8Inhib != 0x5A)
   {
      KNKINSTNOISE_vidInitInstantNoise();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveKnk_InstNoise                                  */
/* !Description :  Tâche de calcul du niveau de cliquetis pour le cylindre en */
/*                 cours                                                      */
/* !Number      :  SCH.3                                                      */
/* !Author      :  W.AKKARI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKINSTNOISE_vidCalcInstantNoise();                      */
/*  input uint8 KNKINSTNOISE_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveKnk_InstNoise                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveKnk_InstNoise(void)
{
   if (KNKINSTNOISE_u8Inhib != 0x5A)
   {
      KNKINSTNOISE_vidCalcInstantNoise();
   }
}

/*--------------------------------- end of file ------------------------------*/