/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKDET                                                  */
/* !Description     : KNKDET Component                                        */
/*                                                                            */
/* !Module          : KNKDET                                                  */
/* !Description     : DÉTECTION DE CLIQUETIS                                  */
/*                                                                            */
/* !File            : KNKDET_SCH.C                                            */
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
/*   1 / KnkTreat_EveRst_KnkDet                                               */
/*   2 / KnkTreat_EveKnk_KnkDet                                               */
/*   3 / KnkTreat_EveCkSnOn_KnkDet                                            */
/*   4 / KnkTreat_SdlMid_KnkDet                                               */
/*   5 / KnkTreat_SdlSlow_KnkDet                                              */
/*   6 / KnkTreat_SdlFast_KnkDet                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5068282 / 05                                        */
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

#include "STD_TYPES.H"
#include "KNKDET.h"
#include "KNKDET_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveRst_KnkDet                                     */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKDET_vidInitOutput();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveRst_KnkDet                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveRst_KnkDet(void)
{
   KNKDET_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveKnk_KnkDet                                     */
/* !Description :  Tâche de calcul du niveau de cliquetis pour le cylindre en */
/*                 cours.                                                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKDET_vidFactorFilterCalcFreq();                        */
/*  extf argret void KNKDET_vidFactorFilterCalcFinal();                       */
/*  extf argret void KNKDET_vidCylTreatment();                                */
/*  extf argret void KNKDET_vidPairCylTreatment();                            */
/*  extf argret void KNKDET_vidCylAverageNoiseCalc();                         */
/*  extf argret void KNKDET_vidAverageNoiseReset();                           */
/*  input uint8 KNKDET_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveKnk_KnkDet                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveKnk_KnkDet(void)
{
   if (KNKDET_u8Inhib != 0x5A)
   {
      KNKDET_vidFactorFilterCalcFreq();
      KNKDET_vidFactorFilterCalcFinal();
      KNKDET_vidCylTreatment();
      KNKDET_vidPairCylTreatment();
      KNKDET_vidCylAverageNoiseCalc();
      KNKDET_vidAverageNoiseReset();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveCkSnOn_KnkDet                                  */
/* !Description :  Evénement correspondant au passage à 1 de la variable      */
/*                 Moteur_synchronise                                         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKDET_vidInitStrategy();                                */
/*  input uint8 KNKDET_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveCkSnOn_KnkDet                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveCkSnOn_KnkDet(void)
{
   if (KNKDET_u8Inhib != 0x5A)
   {
      KNKDET_vidInitStrategy();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_SdlMid_KnkDet                                     */
/* !Description :  Moniteur moyen                                             */
/* !Number      :  SCH.4                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKDET_vidFactorFilterCalcLoad();                        */
/*  input uint8 KNKDET_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_SdlMid_KnkDet                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_SdlMid_KnkDet(void)
{
   if (KNKDET_u8Inhib != 0x5A)
   {
      KNKDET_vidFactorFilterCalcLoad();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_SdlSlow_KnkDet                                    */
/* !Description :  Moniteur lent                                              */
/* !Number      :  SCH.5                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKDET_vidFactorFilterCalcN();                           */
/*  input uint8 KNKDET_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_SdlSlow_KnkDet                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_SdlSlow_KnkDet(void)
{
   if (KNKDET_u8Inhib != 0x5A)
   {
      KNKDET_vidFactorFilterCalcN();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_SdlFast_KnkDet                                    */
/* !Description :  Moniteur rapide KnkTreat                                   */
/* !Number      :  SCH.6                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKDET_vidInhibitionCorrection();                        */
/*  input uint8 KNKDET_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_SdlFast_KnkDet                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_SdlFast_KnkDet(void)
{
   if (KNKDET_u8Inhib != 0x5A)
   {
      KNKDET_vidInhibitionCorrection();
   }
}
/*------------------------------- end of file --------------------------------*/