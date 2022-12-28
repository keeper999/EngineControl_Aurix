/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ISLIN                                                   */
/* !Description     : ISLIN component                                         */
/*                                                                            */
/* !Module          : ISLIN                                                   */
/* !Description     : INTER SYSTEM LIN                                        */
/*                                                                            */
/* !File            : ISLIN_SCH.C                                             */
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
/*   1 / ISLIN_vidEveRst                                                      */
/*   2 / ISLIN_vidSdlFast                                                     */
/*   3 / ISLIN_vidSdlMid                                                      */
/*   4 / ISLIN_vidEveRxnEtatAlt1                                              */
/*   5 / ISLIN_vidEveRxnEtatAlt2                                              */
/*   6 / ISLIN_vidCmdeAlt                                                     */
/*                                                                            */
/* !Reference   : V02 NT 09 03043 / 09                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ISLIN/ISLIN_SCH.C_v               $*/
/* $Revision::   1.12     $$Author::   cbanchie       $$Date::   26 Dec 2011 $*/
/* $Author::   cbanchie                               $$Date::   26 Dec 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "Std_Types.h"
#include "ISLIN.H"
#include "ISLIN_L.H"
#include "ISLIN_im.h"
#include "GDGAR.h"
#include "VEMS.h"

#define ISLIN_START_SEC_CODE
#include "Memmap.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ISLIN_vidEveRst                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ISLIN_vidInitCons();                                     */
/*  extf argret void ISLIN_vidInitProd();                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : ISLIN_vidEveRst                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ISLIN_vidEveRst(void)
{
   ISLIN_vidInitCons();
   ISLIN_vidInitProd();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ISLIN_vidSdlFast                                           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ISLIN_vidLinStatus();                                    */
/*  extf argret void ISLIN_vidWakeUp();                                       */
/*  extf argret void ISLIN_vidShutDown();                                     */
/*  extf argret void ISLIN_vidEtatAlt1();                                     */
/*  extf argret void ISLIN_vidEtatAlt2();                                     */
/*  input uint8 ISLIN_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : ISLIN_vidSdlFast                                               */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ISLIN_vidSdlFast(void)
{
   if (ISLIN_u8Inhib != 0x5A)
   {
      ISLIN_vidLinStatus();
      ISLIN_vidWakeUp();
      ISLIN_vidShutDown();
      ISLIN_vidEtatAlt1();
      ISLIN_vidEtatAlt2();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ISLIN_vidSdlMid                                            */
/* !Number      :  SCH.3                                                      */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ISLIN_vidFreeze();                                       */
/*  extf argret void ISLIN_vidDiagEna();                                      */
/*  input uint8 ISLIN_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : ISLIN_vidSdlMid                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ISLIN_vidSdlMid(void)
{
   if (ISLIN_u8Inhib != 0x5A)
   {
      ISLIN_vidFreeze();
      ISLIN_vidDiagEna();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ISLIN_vidEveRxnEtatAlt1                                    */
/* !Description :  Fonction appelée lors de la reception de la trame ETAT_ALT1*/
/* !Number      :  SCH.4                                                      */
/* !Author      :  GANNOUN                                                    */
/* !Trace_To    :  VEMS_R_09_03043_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 ISLIN_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : ISLIN_vidEveRxnEtatAlt1                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ISLIN_vidEveRxnEtatAlt1(void)
{
   if (ISLIN_u8Inhib != 0x5A)
   {
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ISLIN_vidEveRxnEtatAlt2                                    */
/* !Description :  Fonction appelée lors de la reception de la trame ETAT_ALT2*/
/* !Number      :  SCH.5                                                      */
/* !Author      :  GANNOUN                                                    */
/* !Trace_To    :  VEMS_R_09_03043_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 ISLIN_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : ISLIN_vidEveRxnEtatAlt2                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ISLIN_vidEveRxnEtatAlt2(void)
{
   if (ISLIN_u8Inhib != 0x5A)
   {
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ISLIN_vidCmdeAlt                                           */
/* !Number      :  SCH.6                                                      */
/* !Author      :  GANNOUN                                                    */
/* !Trace_To    :  VEMS_R_09_03043_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void vidSendTrame();                                          */
/*  input uint8 ISLIN_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : ISLIN_vidCmdeAlt                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ISLIN_vidCmdeAlt(void)
{
   if (ISLIN_u8Inhib != 0x5A)
   {
      vidSendTrame();
   }
}

#define ISLIN_STOP_SEC_CODE
#include "Memmap.h"
/*QAC Warning Msg(2:0838): Due to the multiple inclusion of MemMap.h file  */
/*-------------------------------- end of file -------------------------------*/
/*QAC Warning Msg(2:0862): Due to Inclusion of MemMap.h                    */

