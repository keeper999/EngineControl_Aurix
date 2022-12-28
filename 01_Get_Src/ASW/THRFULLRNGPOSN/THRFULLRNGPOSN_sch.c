/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRFULLRNGPOSN                                          */
/* !Description     : THRFULLRNGPOSN component.                               */
/*                                                                            */
/* !Module          : THRFULLRNGPOSN                                          */
/* !Description     : THROTTLE FULL RANGE POSITION                            */
/*                                                                            */
/* !File            : THRFULLRNGPOSN_SCH.C                                    */
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
/*   1 / THRFULLRNGPOSN_vidEntryInit                                          */
/*   2 / Thr_SdlMid_FullRngPosn                                               */
/*                                                                            */
/* !Reference   : V02 NT 09 08266 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/

#include "STD_TYPES.h"
#include "THRFULLRNGPOSN.h"
#include "THRFULLRNGPOSN_L.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRFULLRNGPOSN_vidEntryInit                                */
/* !Description :  Reset event management                                     */
/* !Number      :  SCH.1                                                      */
/* !Author      :  N.ABIDI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRFULLRNGPOSN_vidInitOutput();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : THRFULLRNGPOSN_vidEntryInit                                    */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRFULLRNGPOSN_vidEntryInit(void)
{
   THRFULLRNGPOSN_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_SdlMid_FullRngPosn                                     */
/* !Description :  Middle monitor function for throttle                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  N.ABIDI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRFULLRNGPOSN_vidComput();                              */
/*  input uint8 THRFULLRNGPOSN_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_SdlMid_FullRngPosn                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_SdlMid_FullRngPosn(void)
{
   if(THRFULLRNGPOSN_u8Inhib != 0x5A)
   {
      THRFULLRNGPOSN_vidComput();
   }
}
/*-------------------------------- end of file -------------------------------*/