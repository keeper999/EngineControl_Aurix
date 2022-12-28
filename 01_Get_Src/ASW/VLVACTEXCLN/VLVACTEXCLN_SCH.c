/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXCLN                                             */
/* !Description     : VLVACTEXCLN component.                                  */
/*                                                                            */
/* !Module          : VLVACTEXCLN                                             */
/* !Description     : NETTOYAGE DE L’ELECTROVANNE DE LA VVT ECHAPPEMENT       */
/*                                                                            */
/* !File            : VLVACTEXCLN_SCH.C                                       */
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
/*   1 / VlvAct_EveRst_ExCln                                                  */
/*   2 / VlvAct_SdlFast_ExCln                                                 */
/*   3 / VlvAct_EveKOf_ExCln                                                  */
/*                                                                            */
/* !Reference   : V02 NT 08 08235 / 12                                        */
/* !OtherRefs   : VEMS V02 ECU#055441                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXCLN/VLVACTEXCLN$*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   12 Jul 2013 $*/
/* $Author::   mbenfrad                               $$Date::   12 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "VLVACTEXCLN.h"
#include "VLVACTEXCLN_L.h"
#include "VLVACTEXCLN_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveRst_ExCln                                        */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_08_08235_001.01                                     */
/*                 VEMS_R_08_08235_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXCLN_vidhealClnMngTimeRst();                      */
/*  extf argret void VLVACTEXCLN_vidInitOutput();                             */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveRst_ExCln                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveRst_ExCln(void)
{
   if (VlvAct_bAcvVlvActExStr_C !=0)
   {
      VLVACTEXCLN_vidhealClnMngTimeRst();
   }
   VLVACTEXCLN_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_ExCln                                       */
/* !Description :  Moniteur rapide de la fonction VVT                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_08_08235_001.01                                     */
/*                 VEMS_R_08_08235_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXCLN_vidClnAlgCalc();                             */
/*  extf argret void VLVACTEXCLN_vidRctClnUdt();                              */
/*  extf argret void VLVACTEXCLN_vidClnIndTiCnt();                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 VLVACTEXCLN_u8Inhib;                                          */
/*  input boolean VlvAct_bExMngServoStEna;                                    */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*  input boolean VlvAct_bDgoClnErrVlvActEx;                                  */
/*  input boolean VlvAct_bMonRunClnErrVlvActEx;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_ExCln                                           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_ExCln(void)
{
   boolean bLocalVlvAct_bExMngServoStEna;


   if (VLVACTEXCLN_u8Inhib != 0x5A)
   {
      VEMS_vidGET(VlvAct_bExMngServoStEna, bLocalVlvAct_bExMngServoStEna);
      if (  (VlvAct_bAcvVlvActExStr_C != 0)
         && (bLocalVlvAct_bExMngServoStEna != 0))
      {
         VLVACTEXCLN_vidClnAlgCalc();
         VLVACTEXCLN_vidRctClnUdt();
         VLVACTEXCLN_vidClnIndTiCnt();
         GDGAR_vidGdu(GD_DFT_CLNERRVLVACTEX,
                      VlvAct_bDgoClnErrVlvActEx,
                      VlvAct_bMonRunClnErrVlvActEx,
                      DIAG_DISPO);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveKOf_ExCln                                        */
/* !Description :  Evénement associé au passage de clef ON à clef OFF         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_08_08235_001.01                                     */
/*                 VEMS_R_08_08235_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXCLN_vidErrCountRst();                            */
/*  input uint8 VLVACTEXCLN_u8Inhib;                                          */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveKOf_ExCln                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveKOf_ExCln(void)
{
   if (VLVACTEXCLN_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         VLVACTEXCLN_vidErrCountRst();
      }
   }
}
/*---------------------------- end of file -----------------------------------*/