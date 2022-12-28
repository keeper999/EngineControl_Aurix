/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINCLN                                             */
/* !Description     : VLVACTINCLN component.                                  */
/*                                                                            */
/* !Module          : VLVACTINCLN                                             */
/* !Description     : NETTOYAGE DE L’ELECTROVANNE DE LA VVT ADMISSION         */
/*                                                                            */
/* !File            : VLVACTINCLN_SCH.C                                       */
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
/*   1 / VlvAct_EveRst_InCln                                                  */
/*   2 / VlvAct_SdlFast_InCln                                                 */
/*   3 / VlvAct_EveKOf_InCln                                                  */
/*                                                                            */
/* !Reference   : V02 NT 08 08234 / 13                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINCLN/VLVACTINCLN$*/
/* $Revision::   1.1      $$Author::   mbenfrad       $$Date::   18 Mar 2013 $*/
/* $Author::   mbenfrad                               $$Date::   18 Mar 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "VLVACTINCLN.h"
#include "VLVACTINCLN_L.h"
#include "VLVACTINCLN_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveRst_InCln                                        */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  M.ZIDI                                                     */
/* !Trace_To    :  VEMS_R_08_08234_001.01                                     */
/*                 VEMS_R_08_08234_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINCLN_vidhealClnMngTimeRst();                      */
/*  extf argret void VLVACTINCLN_vidInitOutput();                             */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveRst_InCln                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveRst_InCln(void)
{
   if (VlvAct_bAcvVlvActInStr_C != 0)
   {
      VLVACTINCLN_vidhealClnMngTimeRst();
   }
   VLVACTINCLN_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_InCln                                       */
/* !Description :  Moniteur rapide de la fonction VVT                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  M.ZIDI                                                     */
/* !Trace_To    :  VEMS_R_08_08234_001.01                                     */
/*                 VEMS_R_08_08234_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINCLN_vidClnAlgCalc();                             */
/*  extf argret void VLVACTINCLN_vidRctClnUdt();                              */
/*  extf argret void VLVACTINCLN_vidClnIndTiCnt();                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 VLVACTINCLN_u8Inhib;                                          */
/*  input boolean VlvAct_bInMngServoStEna;                                    */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*  input boolean VlvAct_bDgoClnErrVlvActIn;                                  */
/*  input boolean VlvAct_bMonRunClnErrVlvActIn;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_InCln                                           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_InCln(void)
{
   boolean bLocalVlvActbInMngServoStEna;


   if (VLVACTINCLN_u8Inhib != 0x5A)
   {
      VEMS_vidGET(VlvAct_bInMngServoStEna, bLocalVlvActbInMngServoStEna);
      if (  (VlvAct_bAcvVlvActInStr_C != 0)
         && (bLocalVlvActbInMngServoStEna != 0))
      {
         VLVACTINCLN_vidClnAlgCalc();
         VLVACTINCLN_vidRctClnUdt();
         VLVACTINCLN_vidClnIndTiCnt();
         GDGAR_vidGdu(GD_DFT_CLNERRVLVACTIN,
                      VlvAct_bDgoClnErrVlvActIn,
                      VlvAct_bMonRunClnErrVlvActIn,
                      DIAG_DISPO);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveKOf_InCln                                        */
/* !Description :  Evénement associé au passage de clef ON à clef OFF         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  M.ZIDI                                                     */
/* !Trace_To    :  VEMS_R_08_08234_001.01                                     */
/*                 VEMS_R_08_08234_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINCLN_vidErrCountRst();                            */
/*  input uint8 VLVACTINCLN_u8Inhib;                                          */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveKOf_InCln                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveKOf_InCln(void)
{
   if (VLVACTINCLN_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C != 0)
      {
         VLVACTINCLN_vidErrCountRst();
      }
   }
}
/*---------------------------- end of file -----------------------------------*/