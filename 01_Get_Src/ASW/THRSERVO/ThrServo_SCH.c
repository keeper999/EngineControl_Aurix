/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRSERVO                                                */
/* !Description     : THRSERVO component.                                     */
/*                                                                            */
/* !Module          : THRSERVO                                                */
/* !Description     : ASSERVISSEMENT PAR RETOUR D’ETAT DE LA POSITION DU      */
/*                    PAPILLON MOTORISE                                       */
/*                                                                            */
/* !File            : THRSERVO_SCH.C                                          */
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
/*   1 / Thr_EveRst_Servo                                                     */
/*   2 / Thr_SdlMid_Servo                                                     */
/*   3 / Thr_EveClcnServo_Servo                                               */
/*                                                                            */
/* !Reference   : V02 NT 08 04514 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRSERVO/THRSERVO_SCH.C_v     $*/
/* $Revision::   1.4      $$Author::   acabresp       $$Date::   02 Jun 2010 $*/
/* $Author::   acabresp                               $$Date::   02 Jun 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "THRSERVO.h"
#include "THRSERVO_L.h"
#include "THRSERVO_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveRst_Servo                                           */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSERVO_vidInitOutput();                                */
/*  extf argret void THRSERVO_vidComputeInitTasks();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Thr_EveRst_Servo                                               */
/* !Trigger  : Thr_EveRst_Servo                                               */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRst_Servo(void)
{
   THRSERVO_vidInitOutput();
   THRSERVO_vidComputeInitTasks();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_SdlMid_Servo                                           */
/* !Description :  Moniteur moyen pour le papillon                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSERVO_vidBatteryVoltageGain();                        */
/*  input uint8 THRSERVO_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Thr_SdlMid_Servo                                               */
/* !Trigger  : Thr_SdlMid_Servo                                               */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_SdlMid_Servo(void)
{
   if (THRSERVO_u8Inhib != 0x5A)
   {
      THRSERVO_vidBatteryVoltageGain();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveClcnServo_Servo                                     */
/* !Description :  Evenement de calcul de l'asservissement papillon motorisé  */
/*                 (front montant du signal PWM de commande)                  */
/* !Number      :  SCH.3                                                      */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSERVO_vidDecTempo();                                  */
/*  extf argret void THRSERVO_vidComputeInnerLoop();                          */
/*  extf argret void THRSERVO_vidComputeOutterLoop();                         */
/*  input uint8 THRSERVO_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Thr_EveClcnServo_Servo                                         */
/* !Trigger  : Thr_EveClcnServo_Servo                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveClcnServo_Servo(void)
{
   if (THRSERVO_u8Inhib != 0x5A)
   {
      THRSERVO_vidDecTempo();
      THRSERVO_vidComputeInnerLoop();
      THRSERVO_vidComputeOutterLoop();
   }
}
/*------------------------------- end of file --------------------------------*/