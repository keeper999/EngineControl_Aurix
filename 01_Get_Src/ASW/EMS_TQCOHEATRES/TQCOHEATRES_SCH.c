/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       :  TQCOHEATRES                                            */
/*                                                                            */
/* !Module          : TQCOHEATRES                                             */
/* !Description     : Réserve de couple chauffage habitacle                   */
/*                                                                            */
/* !File            : TQCOHEATRES_SCH.C                                       */
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
/*   1 / TQCOHEATRES_vidEntryInit                                             */
/*   2 / TqRes_Sdl10ms_tqCoHeatRes                                            */
/*                                                                            */
/* !Reference   : V02 NT 11 02653 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_2028 / 2.1                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQCOHEATRES/TQCOH$*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "TQCOHEATRES.H"
#include "TQCOHEATRES_L.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCOHEATRES_vidEntryInit                                   */
/* !Description :  évènement Reset ECU                                        */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_02653_001.01                                     */
/*                 VEMS_R_11_02653_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCOHEATRES_vidInitOutput();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQCOHEATRES_vidEntryInit                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCOHEATRES_vidEntryInit(void)
{
   TQCOHEATRES_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqRes_Sdl10ms_tqCoHeatRes                                  */
/* !Description :  Fonction d'accroche au moniteur 10ms                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_02653_001.01                                     */
/*                 VEMS_R_11_02653_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCOHEATRES_vidReserveThrmHabit();                       */
/*  input uint8 TQCOHEATRES_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TqRes_Sdl10ms_tqCoHeatRes                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqRes_Sdl10ms_tqCoHeatRes(void)
{
   /*QAC Msg(2:4152): Name imposed by specification*/
   if (TQCOHEATRES_u8Inhib != 0x5A)
   {
      TQCOHEATRES_vidReserveThrmHabit();
   }
}
/*------------------------------- end of file --------------------------------*/