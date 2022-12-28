/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TARIDLSTA                                               */
/* !Description     : TARIDLSTA component.                                    */
/*                                                                            */
/* !Module          : TARIDLSTA                                               */
/* !Description     : Consigne de Ralenti Statique                            */
/*                                                                            */
/* !File            : TARIDLSTA_SCH.C                                         */
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
/*   1 / TARIDLSTA_vidEntryInit                                               */
/*   2 / TqSys_Sdl10ms_nTarIdl                                                */
/*                                                                            */
/* !Reference   : V02 NT 10 08533 / 02                                        */
/* !OtherRefs   : CSMT_CGMT06_2104 / 10.3                                     */
/* !OtherRefs   : VEMS V02 ECU#051848                                         */
/* !OtherRefs   : VEMS V02 ECU#059717                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TARIDLSTA/TARIDLS$*/
/* $Revision::   1.9      $$Author::   mbenfrad       $$Date::   11 Jul 2013 $*/
/* $Author::   mbenfrad                               $$Date::   11 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TARIDLSTA.h"
#include "TARIDLSTA_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidEntryInit                                     */
/* !Description :  Fonction Reset                                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TARIDLSTA_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TARIDLSTA_vidEntryInit                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidEntryInit(void)
{
   TARIDLSTA_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_Sdl10ms_nTarIdl                                      */
/* !Description :  Fonction scheduler de récurrence 10ms.                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TARIDLSTA_vidCalc_Idlle_target();                        */
/*  input uint8 TARIDLSTA_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger     : TqSys_Sdl10ms_nTarIdl                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_Sdl10ms_nTarIdl(void)
{
   /*QAC Msg(2:4152): Name imposed by specification*/
   if (TARIDLSTA_u8Inhib != 0x5A)
   {
      TARIDLSTA_vidCalc_Idlle_target();
   }
}

/*-------------------------------- End of file -------------------------------*/
