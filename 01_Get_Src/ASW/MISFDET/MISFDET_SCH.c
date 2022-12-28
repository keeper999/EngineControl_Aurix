/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFDET                                                 */
/* !Description     : MISFDET component                                       */
/*                                                                            */
/* !Module          : MISFDET                                                 */
/* !Description     : Algorithmes de détection de misfire                     */
/*                                                                            */
/* !File            : MISFDET_SCH.C                                           */
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
/*   1 / MISFDET_vidEntryInit                                                 */
/*   2 / Misf_EveMisf_MisfDet                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_5158467 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#068493                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFDET/MISFDET_SCH.C_v      $*/
/* $Revision::   1.11     $$Author::   wbouach        $$Date::   27 Mar 2014 $*/
/* $Author::   wbouach                                $$Date::   27 Mar 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MISFDET.h"
#include "MISFDET_L.h"
#include "MISFDET_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDET_vidEntryInit                                       */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDET_vidInitOutput();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : MISFDET_vidEntryInit                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDET_vidEntryInit(void)
{
   MISFDET_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveMisf_MisfDet                                       */
/* !Description :  Evènement lié à l'interruption logicielle de fin           */
/*                 d'acquisition de la fenêtre misfire                        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDET_vidMisfDet();                                    */
/*  input uint8 MISFDET_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_EveMisf_MisfDet                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveMisf_MisfDet(void)
{
   if (MISFDET_u8Inhib != 0x5A)
   {
      MISFDET_vidMisfDet();
   }
}
/*------------------------------- end of file --------------------------------*/