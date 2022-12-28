/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRSERVODIAG                                            */
/* !Description     : THRSERVODIAG Component                                  */
/*                                                                            */
/* !Module          : THRSERVODIAG                                            */
/* !Description     : Diagnostic de l'asservissement de la position du        */
/*                    Papillon Motorisé                                       */
/*                                                                            */
/* !File            : THRSERVODIAG_SCH.C                                      */
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
/*   1 / THRSERVODIAG_vidEntryInit                                            */
/*   2 / Thr_EveClcnServo_Diag                                                */
/*                                                                            */
/* !Reference   : V02 NT 08 04530 / 5                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRSERVODIAG/THRSERVODIAG_SC$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   02 Apr 2013 $*/
/* $Author::   etsasson                               $$Date::   02 Apr 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "THRSERVODIAG.h"
#include "THRSERVODIAG_L.h"
#include "THRSERVODIAG_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVODIAG_vidEntryInit                                  */
/* !Description :  Evénement Reset ECU                                        */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSERVODIAG_vidInitOutput();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : THRSERVODIAG_vidEntryInit                                      */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVODIAG_vidEntryInit(void)
{
   THRSERVODIAG_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveClcnServo_Diag                                      */
/* !Description :  Evénement de calcul de l'asservissement papillon  motorisé */
/*                 (front montant du signal PWM de commande)                  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSERVODIAG_vidSerFailDetection();                      */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait);                                             */
/*  input uint8 THRSERVODIAG_u8Inhib;                                         */
/*  input boolean Thr_bDgoORngServo;                                          */
/*  input boolean Thr_bMonRunORngServo;                                       */
/*  input boolean Thr_bDgoORngServoDifPos;                                    */
/*  input boolean Thr_bDgoORngServoDifNeg;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveClcnServo_Diag                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveClcnServo_Diag(void)
{
   if (THRSERVODIAG_u8Inhib != 0x5A)
   {
      THRSERVODIAG_vidSerFailDetection();
      GDGAR_vidGdu(GD_DFT_ORNGSERVO,
                   Thr_bDgoORngServo,
                   Thr_bMonRunORngServo,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNGSERVODIFPOS,
                   Thr_bDgoORngServoDifPos,
                   Thr_bMonRunORngServo,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNGSERVODIFNEG,
                   Thr_bDgoORngServoDifNeg,
                   Thr_bMonRunORngServo,
                   DIAG_DISPO);
   }
}
/*----------------------------- end of file ----------------------------------*/