/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQADC                                                  */
/* !Description     : ACQADC component.                                       */
/*                                                                            */
/* !Module          : ACQADC                                                  */
/* !Description     : Spécification des acquisitions analogiques (AdcHal)     */
/*                                                                            */
/* !File            : ACQADC_SCH4.C                                           */
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
/*   1 / Thr_EveClcnServo_AcqAdcThr                                           */
/*   2 / Thr_EveRst_AcqAdcThr                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6669203 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACQADC/ACQADC_SCH4.C_v            $*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   31 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   31 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.H"
#include "ACQADC.H"
#include "ACQADC_L.H"
#include "ACQADC_IM.H"
#include "ACQADC_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveClcnServo_AcqAdcThr                                 */
/* !Description :  Evenement de calcul de l'asservissement papillon motorisé  */
/*                 (front montant du signal PWM de commande).                 */
/* !Number      :  SCH4.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidAcqAdcThr();                                   */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveClcnServo_AcqAdcThr                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveClcnServo_AcqAdcThr(void)
{
   if (ACQADC_u8Inhib != 0x5A)
   {
      ACQADC_vidAcqAdcThr();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveRst_AcqAdcThr                                       */
/* !Description :  Evènement reset de la fonction Thr.                        */
/* !Number      :  SCH4.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidAcqAdcThr();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveRst_AcqAdcThr                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRst_AcqAdcThr(void)
{
   ACQADC_vidAcqAdcThr();
}

/*------------------------------- end of file --------------------------------*/