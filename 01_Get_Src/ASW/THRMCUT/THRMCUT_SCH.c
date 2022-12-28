/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRMCUT                                                 */
/* !Description     : THRMCUT Component                                       */
/*                                                                            */
/* !Module          : THRMCUT                                                 */
/* !Description     : DETECTION DE MICRO-COUPURES CMM/BPM ET MODE PALLIATIF   */
/*                                                                            */
/* !File            : THRMCUT_SCH.C                                           */
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
/*   1 / Thr_EveRst_mCut                                                      */
/*   2 / Thr_EveClcnServo_mCut                                                */
/*                                                                            */
/* !Reference: V02 NT 08 04513 / 05                                           */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRMCUT/THRMCUT_SCH.C_v       $*/
/* $Revision::   1.3      $$Author::   acabresp       $$Date::   31 Mar 2010 $*/
/* $Author::   acabresp                               $$Date::   31 Mar 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "THRMCUT.h"
#include "THRMCUT_l.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : Thr_EveRst_mCut                                             */
/* !Description : Evénement reset du calculateur                              */
/* !Number      : SCH.1                                                       */
/* !Author      : B.KBOUBI                                                    */
/* !Trace_To    : VEMS_R_07_05348_002.01                                      */
/*                                                                            */
/******************************************************************************/
/*   extf argret void THRMCUT_vidInit();                                      */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Thr_EveRst_mCut                                                */
/* !Trigger  : Thr_EveRst_mCut                                                */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRst_mCut(void)
{
   THRMCUT_vidInit();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : Thr_EveClcnServo_mCut                                       */
/* !Description : Evénement de calcul de l'asservissement papillon motorisé   */
/*                (front montant du signal PWM de commande)                   */
/* !Number      : SCH.2                                                       */
/* !Author      : B.KBOUBI                                                    */
/* !Trace_To    : VEMS_R_07_05348_002.01                                      */
/*                                                                            */
/******************************************************************************/
/*   extf argret void THRMCUT_vidMicroCutBmpFuncInhib();                      */
/*   extf argret void THRMCUT_vidDetection();                                 */
/*   extf argret void THRMCUT_vidManager();                                   */
/*   extf argret void THRMCUT_vidThrSpLrnDeac();                              */
/*   input uint8 THRMCUT_u8Inhib;                                             */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Thr_EveClcnServo_mCut                                          */
/* !Trigger  : Thr_EveClcnServo_mCut                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveClcnServo_mCut(void)
{
   if (THRMCUT_u8Inhib != 0x5A)
   {
      THRMCUT_vidMicroCutBmpFuncInhib();
      THRMCUT_vidDetection();
      THRMCUT_vidManager();
      THRMCUT_vidThrSpLrnDeac();
   }
}
/*------------------------------ End of file ---------------------------------*/