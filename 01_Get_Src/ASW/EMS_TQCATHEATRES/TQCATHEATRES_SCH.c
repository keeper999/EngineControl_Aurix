/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQCATHEATRES                                            */
/* !Description     : TQCATHEATRES Component                                  */
/*                                                                            */
/* !Module          : TQCATHEATRES                                            */
/* !Description     : Réserve de couple chauffe catalyseur                    */
/*                                                                            */
/* !File            : TQCATHEATRES_SCH.C                                      */
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
/*   1 / TQCATHEATRES_vidEntryInit                                            */
/*   2 / TqRes_Sdl10ms_tqEOMRes                                               */
/*                                                                            */
/* !Reference   : V02 NT 10 08577 / 02                                        */
/* !OtherRefs   : 01460_10_01305 / 1.1                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQCATHEATRES/TQCA$*/
/* $Revision::   1.2      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQCATHEATRES.h"
#include "TQCATHEATRES_L.h"
#include "TQCATHEATRES_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCATHEATRES_vidEntryInit                                  */
/* !Description :  Output initialization                                      */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08577_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCATHEATRES_vidInitOutput();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQCATHEATRES_vidEntryInit                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCATHEATRES_vidEntryInit(void)
{
   TQCATHEATRES_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqRes_Sdl10ms_tqEOMRes                                     */
/* !Description :  Moniteur rapide                                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08577_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCATHEATRES_vidUnvectorizeMode();                       */
/*  extf argret void TQCATHEATRES_vidDeterminSetpoint();                      */
/*  input uint8 TQCATHEATRES_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TqRes_Sdl10ms_tqEOMRes                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqRes_Sdl10ms_tqEOMRes(void)
{
/*QAC Warning : Msg(2:4152) : scheduler names are imposed by the specification*/
   if (TQCATHEATRES_u8Inhib != 0x5A)
   {
      TQCATHEATRES_vidUnvectorizeMode();
      TQCATHEATRES_vidDeterminSetpoint();
   }
}
/*------------------------------- end of file --------------------------------*/