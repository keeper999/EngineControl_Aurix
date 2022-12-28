/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQADVMIN                                                */
/* !Description     : TQADVMIN component.                                     */
/*                                                                            */
/* !Module          : TQADVMIN                                                */
/* !Description     : CLOSED LOOP REQUEST FOR LOW TORQUE                      */
/*                                                                            */
/* !File            : TQADVMIN_SCH.c                                          */
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
/*   1 / TQADVMIN_vidEntryInit                                                */
/*   2 / TqSys_Sdl20ms_TqAdvMin                                               */
/*                                                                            */
/* !Reference   : V02 NT 11 05439 / 01                                        */
/* !OtherRefs   : 01460_11_03421 / 1                                          */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQADVMIN/TQADVMIN$*/
/* $Revision::   1.2      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQADVMIN.h"
#include "TQADVMIN_L.h"
#include "TQADVMIN_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQADVMIN_vidEntryInit                                      */
/* !Description :  Fonction moniteur Reset                                    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_05439_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQADVMIN_vidInitOutput();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger     : TQADVMIN_vidEntryInit                                       */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQADVMIN_vidEntryInit(void)
{
   TQADVMIN_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_Sdl20ms_TqAdvMin                                     */
/* !Description :  Trigger of the function                                    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_05439_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQADVMIN_vidRqestClosedLopTqmin1();                      */
/*  extf argret void TQADVMIN_vidRqestClosedLopTqmin2();                      */
/*  input uint8 TQADVMIN_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger     : TqSys_Sdl20ms_TqAdvMin                                      */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_Sdl20ms_TqAdvMin(void)
{
   if (TQADVMIN_u8Inhib !=0x5A)
   {
      TQADVMIN_vidRqestClosedLopTqmin1();
      TQADVMIN_vidRqestClosedLopTqmin2();
   }
}
/*------------------------------- end of file --------------------------------*/