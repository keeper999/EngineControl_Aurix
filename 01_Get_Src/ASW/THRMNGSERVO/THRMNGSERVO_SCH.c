/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRMNGSERVO                                             */
/* !Description     : THRMNGSERVO Component                                   */
/*                                                                            */
/* !Module          : THRMNGSERVO                                             */
/* !Description     : Gestion de l’asservissement du papillon motorise        */
/*                                                                            */
/* !File            : THRMNGSERVO_SCH.C                                       */
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
/*   1 / Thr_EveRst_MngServo                                                  */
/*   2 / Thr_SdlMid_MngServo                                                  */
/*   3 / Thr_EveRstThr_MngServo                                               */
/*                                                                            */
/* !Reference   : V02 NT 08 04528 / 16                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRMNGSERVO/THRMNGSERVO_SCH.$*/
/* $Revision::   1.5      $$Author::   etsasson       $$Date::   20 Sep 2012 $*/
/* $Author::   etsasson                               $$Date::   20 Sep 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "THRMNGSERVO.h"
#include "THRMNGSERVO_L.h"
#include "THRMNGSERVO_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveRst_MngServo                                        */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_E_08_04528_001.01                                     */
/*                 VEMS_E_08_04528_002.01                                     */
/*                 VEMS_E_08_04528_003.01                                     */
/*                 VEMS_E_08_04528_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRMNGSERVO_vidInitOutput();                             */
/*  extf argret void THRMNGSERVO_vidManager();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveRst_MngServo                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRst_MngServo(void)
{
   THRMNGSERVO_vidInitOutput();
   THRMNGSERVO_vidManager();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_SdlMid_MngServo                                        */
/* !Description :  Moniteur moyen de la fonction papillon                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_E_08_04528_001.01                                     */
/*                 VEMS_E_08_04528_002.01                                     */
/*                 VEMS_E_08_04528_003.01                                     */
/*                 VEMS_E_08_04528_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRMNGSERVO_vidPowrLatchCountMng();                      */
/*  extf argret void THRMNGSERVO_vidManager();                                */
/*  extf argret void THRMNGSERVO_vidForceLrnRst();                            */
/*  extf argret void THRMNGSERVO_vidSrvTran();                                */
/*  input uint8 THRMNGSERVO_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_SdlMid_MngServo                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_SdlMid_MngServo(void)
{
   if (THRMNGSERVO_u8Inhib != 0x5A)
   {
      THRMNGSERVO_vidPowrLatchCountMng();
      THRMNGSERVO_vidManager();
      THRMNGSERVO_vidForceLrnRst();
      THRMNGSERVO_vidSrvTran();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveRstThr_MngServo                                     */
/* !Description :  Evèvenement de requête de recentrage des adaptatifs        */
/*                 papillon                                                   */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_E_08_04528_001.01                                     */
/*                 VEMS_E_08_04528_002.01                                     */
/*                 VEMS_E_08_04528_003.01                                     */
/*                 VEMS_E_08_04528_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRMNGSERVO_vidThrIniAftsStopLrn();                      */
/*  input uint8 THRMNGSERVO_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveRstThr_MngServo                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRstThr_MngServo(void)
{
   if (THRMNGSERVO_u8Inhib != 0x5A)
   {
      THRMNGSERVO_vidThrIniAftsStopLrn();
   }
}
/*------------------------------- end of file --------------------------------*/