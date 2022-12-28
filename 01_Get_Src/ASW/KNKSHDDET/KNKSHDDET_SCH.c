/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKSHDDET                                               */
/* !Description     : KNKSHDDET Component.                                    */
/*                                                                            */
/* !Module          : KNKSHDDET                                               */
/* !Description     : Détection palliative de cliquetis.                      */
/*                                                                            */
/* !File            : KNKSHDDET_SCH.C                                         */
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
/*   1 / KnkTreat_EveRst_ShdDet                                               */
/*   2 / KnkTreat_EveCkSnOn_ShdDet                                            */
/*   3 / KnkTreat_EveKnk_ShdDet                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5145312 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/KNKRBLTREATSYS/KNKSHDDET/KNKSHDD$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   02 May 2013 $*/
/* $Author::   etsasson                               $$Date::   02 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "KNKSHDDET.h"
#include "KNKSHDDET_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveRst_ShdDet                                     */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKSHDDET_vidInitOutput();                               */
/*  extf argret void KNKSHDDET_vidInitialization();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : KnkTreat_EveRst_ShdDet                                         */
/* !Trigger  : KnkTreat_EveRst_ShdDet                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveRst_ShdDet(void)
{
   KNKSHDDET_vidInitOutput();
   KNKSHDDET_vidInitialization();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveCkSnOn_ShdDet                                  */
/* !Description :  Evénement correspondant au passage à 1 de la variable      */
/*                 Moteur_synchronise                                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKSHDDET_vidInitialization();                           */
/*  input uint8 KNKSHDDET_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : KnkTreat_EveCkSnOn_ShdDet                                      */
/* !Trigger  : KnkTreat_EveCkSnOn_ShdDet                                      */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveCkSnOn_ShdDet(void)
{
   if (KNKSHDDET_u8Inhib != 0x5A)
   {
      KNKSHDDET_vidInitialization();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveKnk_ShdDet                                     */
/* !Description :  Tâche de calcul du niveau de cliquetis pour le cylindre en */
/*                 cours.                                                     */
/* !Number      :  SCH.3                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKSHDDET_vidDetManager();                               */
/*  input uint8 KNKSHDDET_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : KnkTreat_EveKnk_ShdDet                                         */
/* !Trigger  : KnkTreat_EveKnk_ShdDet                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveKnk_ShdDet(void)
{
   if (KNKSHDDET_u8Inhib != 0x5A)
   {
      KNKSHDDET_vidDetManager();
   }
}

/*------------------------------- end of file --------------------------------*/