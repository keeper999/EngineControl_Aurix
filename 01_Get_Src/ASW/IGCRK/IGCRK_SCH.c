/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IGCRK                                                   */
/* !Description     : IGCRK component.                                        */
/*                                                                            */
/* !Module          : IGCRK                                                   */
/* !Description     : CALCUL DE L’AVANCE A L’ALLUMAGE SOUS DEMARREUR.         */
/*                                                                            */
/* !File            : IGCRK_SCH.C                                             */
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
/*   1 / IgSys_EveRst_IgCrk                                                   */
/*   2 / IgSys_EveBDC_IgCrk                                                   */
/*   3 / IgSys_EveRTSt_IgCrk                                                  */
/*                                                                            */
/* !Reference   : V02 NT 09 04922 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/IGCRK/IGCRK_SCH.C_v               $*/
/* $Revision::   1.4      $$Author::   achebino       $$Date::   22 Nov 2012 $*/
/* $Author::   achebino                               $$Date::   22 Nov 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "IGCRK.h"
#include "IGCRK_L.h"
#include "IGCRK_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgSys_EveRst_IgCrk                                         */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_09_04922_001.02                                     */
/*                 VEMS_R_09_04922_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCRK_vidInitOutput();                                   */
/*  extf argret void IGCRK_vidCalcAdvanceCranking();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgSys_EveRst_IgCrk                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgSys_EveRst_IgCrk(void)
{
   IGCRK_vidInitOutput();
   IGCRK_vidCalcAdvanceCranking();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgSys_EveBDC_IgCrk                                         */
/* !Description :  Evénement PMB admission                                    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_09_04922_001.02                                     */
/*                 VEMS_R_09_04922_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCRK_vidCalcAdvanceCranking();                          */
/*  input uint8 IGCRK_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgSys_EveBDC_IgCrk                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgSys_EveBDC_IgCrk(void)
{
   if (IGCRK_u8Inhib != 0x5A)
   {
      IGCRK_vidCalcAdvanceCranking();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgSys_EveRTSt_IgCrk                                        */
/* !Description :  Evénement correspondant au passage à 0 de la variable      */
/*                 Moteur_tournant                                            */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_09_04922_001.02                                     */
/*                 VEMS_R_09_04922_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCRK_vidCalcAdvanceCranking();                          */
/*  input uint8 IGCRK_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgSys_EveRTSt_IgCrk                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgSys_EveRTSt_IgCrk(void)
{
   if (IGCRK_u8Inhib != 0x5A)
   {
      IGCRK_vidCalcAdvanceCranking();
   }
}

/*------------------------------- end of file --------------------------------*/