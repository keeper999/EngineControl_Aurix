/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : WUC                                                     */
/* !Description     : WUC Component                                           */
/*                                                                            */
/* !Module          : WUC                                                     */
/* !Description     : WARM UP CYCLE                                           */
/*                                                                            */
/* !File            : WUC_SCH.C                                               */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / WUC_vidMngEveSldSlow                                                 */
/*   2 / WUC_vidMngEveRst                                                     */
/*                                                                            */
/* !Reference   : V02 NT 08 04191 / 4                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/GDGAR/WUC/WUC_SCH.c_v             $*/
/* $Revision::   1.4      $$Author::   sbiet          $$Date::   06 Jul 2009 $*/
/* $Author::   sbiet                                  $$Date::   06 Jul 2009 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "WUC.h"
#include "WUC_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WUC_vidMngEveSldSlow                                       */
/* !Description :  API calls on the event which occurs every 1024 ms. Launch  */
/*                 all actions which must be done by the module on the event. */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_08_04191_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WUC_vidF03_WupPrmUpd();                                  */
/*  input uint8 WUC_u8Inhib;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : WUC_vidMngEveSldSlow                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WUC_vidMngEveSldSlow(void)
{
   if(WUC_u8Inhib != 0x5A)
   {
      WUC_vidF03_WupPrmUpd ();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WUC_vidMngEveRst                                           */
/* !Description :  Load the parameter WUC_tCoRefEep save in EEPROM in the     */
/*                 working parameter WUC_tCoRef.                              */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_08_04191_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WUC_vidWupInit();                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : WUC_vidMngEveRst                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WUC_vidMngEveRst(void)
{
   WUC_vidWupInit();
}

/*------------------------------- end of file --------------------------------*/