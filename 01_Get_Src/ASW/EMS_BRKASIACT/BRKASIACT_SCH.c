/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : BRKASIACT                                               */
/* !Description     : BRKASIACT Component.                                    */
/*                                                                            */
/* !Module          : BRKASIACT                                               */
/* !Description     : FONCTION ASSISTANCE DE FREINAGE                         */
/*                                                                            */
/* !File            : BRKASIACT_SCH.C                                         */
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
/*   1 / BRKASIACT_vidEntryInit                                               */
/*   2 / TqSys_Sdl10ms_BrkAsi                                                 */
/*                                                                            */
/* !Reference   : V02 NT 10 03258 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#047998                                         */
/* !OtherRefs   : VEMS V02 ECU#060255                                         */
/* !OtherRefs   : 01460_10_00034 / 02                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/BRK/BRKASIACT/BRKASIACT_SC$*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   04 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   04 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BRKASIACT.h"
#include "BRKASIACT_L.h"
#include "BRKASIACT_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACT_vidEntryInit                                     */
/* !Description :  evenement d'initialisation                                 */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_03258_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BRKASIACT_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : BRKASIACT_vidEntryInit                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACT_vidEntryInit(void)
{
   BRKASIACT_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_Sdl10ms_BrkAsi                                       */
/* !Description :  accroche moniteur chaque 10 ms                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_03258_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BRKASIACT_vidActiv_Cond_Veh();                           */
/*  extf argret void BRKASIACT_vidActiv_Cond_Couple();                        */
/*  extf argret void BRKASIACT_vidSuperviseur();                              */
/*  input uint8 BRKASIACT_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TqSys_Sdl10ms_BrkAsi                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_Sdl10ms_BrkAsi(void)
{
   /* Msg(2:4152) The name 'TqSys_Sdl10ms_BrkAsi' may cause confusion
      because it contains both the characters 'l' and '1'.*/
   if (BRKASIACT_u8Inhib != 0x5A)
   {
      BRKASIACT_vidActiv_Cond_Veh();
      BRKASIACT_vidActiv_Cond_Couple();
      BRKASIACT_vidSuperviseur();
   }
}

/*--------------------------------- end of file ------------------------------*/