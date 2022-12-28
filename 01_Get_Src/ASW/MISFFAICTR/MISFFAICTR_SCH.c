/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFFAICTR                                              */
/* !Description     : MISFFAICTR component.                                   */
/*                                                                            */
/* !Module          : MISFFAICTR                                              */
/* !Description     : Comptage Des Misfires Pour Les Emissions De Polluants Et*/
/*                    La Protection Composants .                              */
/*                                                                            */
/* !File            : MISFFAICTR_SCH.C                                        */
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
/*   1 / Misf_EveRst_MisfFaiCtr                                               */
/*   2 / Misf_EveMisf_MisfFaiCtr                                              */
/*   3 / Misf_SdlSlow_MisfFaiCtr                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5069596 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFFAICTR/MISFFAICTR_SCH.C_v$*/
/* $Revision::   1.14     $$Author::   wbouach        $$Date::   19 Jun 2012 $*/
/* $Author::   wbouach                                $$Date::   19 Jun 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MISFFAICTR.h"
#include "MISFFAICTR_L.h"
#include "MISFFAICTR_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveRst_MisfFaiCtr                                     */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_09_00890_001.01                                     */
/*                 VEMS_R_09_00890_002.01                                     */
/*                 VEMS_R_09_00890_003.01                                     */
/*                 VEMS_R_09_00890_012.01                                     */
/*                 VEMS_R_09_00890_013.01                                     */
/*                 VEMS_R_09_00890_014.01                                     */
/*                 VEMS_R_09_00890_016.01                                     */
/*                 VEMS_R_09_00890_022.02                                     */
/*                 VEMS_R_09_00890_023.01                                     */
/*                 VEMS_R_09_00890_024.01                                     */
/*                 VEMS_R_09_00890_025.01                                     */
/*                 VEMS_R_09_00890_026.01                                     */
/*                 VEMS_R_09_00890_030.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFFAICTR_vidInitOutput();                              */
/*  extf argret void MISFFAICTR_vidInit();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_EveRst_MisfFaiCtr                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveRst_MisfFaiCtr(void)
{
   MISFFAICTR_vidInitOutput();
   MISFFAICTR_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveMisf_MisfFaiCtr                                    */
/* !Description :  Evènement lié à l'interruption logicielle de fin           */
/*                 d'acquisition de la fenêtre misfire.                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_09_00890_001.01                                     */
/*                 VEMS_R_09_00890_002.01                                     */
/*                 VEMS_R_09_00890_003.01                                     */
/*                 VEMS_R_09_00890_012.01                                     */
/*                 VEMS_R_09_00890_013.01                                     */
/*                 VEMS_R_09_00890_014.01                                     */
/*                 VEMS_R_09_00890_016.01                                     */
/*                 VEMS_R_09_00890_022.02                                     */
/*                 VEMS_R_09_00890_023.01                                     */
/*                 VEMS_R_09_00890_024.01                                     */
/*                 VEMS_R_09_00890_025.01                                     */
/*                 VEMS_R_09_00890_026.01                                     */
/*                 VEMS_R_09_00890_030.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFFAICTR_vidFailDetCatDam();                           */
/*  extf argret void MISFFAICTR_vidFailDetEmiss();                            */
/*  extf argret void MISFFAICTR_vidMisfireDefault();                          */
/*  extf argret void MISFFAICTR_vidMisfFaiCtrEnable();                        */
/*  input uint8 MISFFAICTR_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_EveMisf_MisfFaiCtr                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveMisf_MisfFaiCtr(void)
{
   if (MISFFAICTR_u8Inhib != 0x5A)
   {
      MISFFAICTR_vidFailDetCatDam();
      MISFFAICTR_vidFailDetEmiss();
      MISFFAICTR_vidMisfireDefault();
      MISFFAICTR_vidMisfFaiCtrEnable();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_SdlSlow_MisfFaiCtr                                    */
/* !Description :  Moniteur lent de la fonction MisfFaiCtr.                   */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_09_00890_001.01                                     */
/*                 VEMS_R_09_00890_002.01                                     */
/*                 VEMS_R_09_00890_003.01                                     */
/*                 VEMS_R_09_00890_012.01                                     */
/*                 VEMS_R_09_00890_013.01                                     */
/*                 VEMS_R_09_00890_014.01                                     */
/*                 VEMS_R_09_00890_016.01                                     */
/*                 VEMS_R_09_00890_022.02                                     */
/*                 VEMS_R_09_00890_023.01                                     */
/*                 VEMS_R_09_00890_024.01                                     */
/*                 VEMS_R_09_00890_025.01                                     */
/*                 VEMS_R_09_00890_026.01                                     */
/*                 VEMS_R_09_00890_030.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFFAICTR_vidFuelLowLevelComput();                      */
/*  input boolean Moteur_tournant;                                            */
/*  input uint8 MISFFAICTR_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_SdlSlow_MisfFaiCtr                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_SdlSlow_MisfFaiCtr(void)
{
   boolean bLocalMoteurTournant;


   VEMS_vidGET(Moteur_tournant, bLocalMoteurTournant);

   if (  (MISFFAICTR_u8Inhib != 0x5A)
      && (bLocalMoteurTournant != 0))
   {
      MISFFAICTR_vidFuelLowLevelComput();
   }
}
/*------------------------------end of file-----------------------------------*/