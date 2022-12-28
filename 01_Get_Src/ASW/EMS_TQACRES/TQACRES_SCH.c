/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQACRES                                                 */
/* !Description     : TQACRES Component                                       */
/*                                                                            */
/* !Module          : TQACRES                                                 */
/* !Description     : Réserve de couple climatisation                         */
/*                                                                            */
/* !File            : TQACRES_SCH.C                                           */
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
/*   1 / TQACRES_vidEntryInit                                                 */
/*   2 / TqRes_Sdl10ms_tqACRes                                                */
/*   3 / TqRes_Sdl20ms_tqACRes                                                */
/*                                                                            */
/* !Reference   : V02 NT 10 04980 / 02                                        */
/* !OtherRefs   : CSMT_CGMT08_0181 / 2.3                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQACRES/TQACRES_S$*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "TQACRES.h"
#include "TQACRES_L.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQACRES_vidEntryInit                                       */
/* !Description :  Fonction d'initialisation au Reset                         */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_04980_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQACRES_vidInitOutput();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQACRES_vidEntryInit                                           */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQACRES_vidEntryInit(void)
{
   TQACRES_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqRes_Sdl10ms_tqACRes                                      */
/* !Description :  Fonction d'accroche au moniteur 10 ms                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_04980_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQACRES_vidActivation_Calcul();                          */
/*  extf argret void TQACRES_vidReserveCoupleClim();                          */
/*  input uint8 TQACRES_u8Inhib;                                              */
/*  input boolean TqRes_bAcvOptmTqACRes;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQACRES_vidEntry_10ms                                          */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqRes_Sdl10ms_tqACRes(void)
{
   if (TQACRES_u8Inhib != 0x5A)
   {
      TQACRES_vidActivation_Calcul();
      if (TqRes_bAcvOptmTqACRes == 0)
      {
         TQACRES_vidReserveCoupleClim();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqRes_Sdl20ms_tqACRes                                      */
/* !Description :  Fonction d'accroche au moniteur 20 ms                      */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_04980_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQACRES_vidActivation_Calcul();                          */
/*  extf argret void TQACRES_vidReserveCoupleClim();                          */
/*  input uint8 TQACRES_u8Inhib;                                              */
/*  input boolean TqRes_bAcvOptmTqACRes;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQACRES_vidEntry_20ms                                          */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqRes_Sdl20ms_tqACRes(void)
{
   if (TQACRES_u8Inhib != 0x5A)
   {
      TQACRES_vidActivation_Calcul();
      if (TqRes_bAcvOptmTqACRes != 0)
      {
         TQACRES_vidReserveCoupleClim();
      }
   }
}
/*------------------------------- end of file --------------------------------*/