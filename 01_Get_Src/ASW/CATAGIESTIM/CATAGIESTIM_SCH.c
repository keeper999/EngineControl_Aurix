/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CATAGIESTIM                                             */
/* !Description     : CATAGIESTIM Component                                   */
/*                                                                            */
/* !Module          : CATAGIESTIM                                             */
/* !Description     : Estimation du vieillissement catalyseur                 */
/*                                                                            */
/* !File            : CATAGIESTIM_SCH.C                                       */
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
/*   1 / CATAGIESTIM_vidEntryInit                                             */
/*   2 / CatMdl_SdlSlow_EstimAgi                                              */
/*                                                                            */
/* !Reference   : V02 NT 08 07305 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CATAGIESTIM/CATAGIESTIM_SCH.C_v   $*/
/* $Revision::   1.2      $$Author::   ACHEBINO       $$Date::   28 Sep 2011 $*/
/* $Author::   ACHEBINO                               $$Date::   28 Sep 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "CATAGIESTIM.H"
#include "CATAGIESTIM_L.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CATAGIESTIM_vidEntryInit                                   */
/* !Description :  Initalisation des outputs                                  */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_01020_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CATAGIESTIM_vidInitOutput();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CATAGIESTIM_vidEntryInit                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CATAGIESTIM_vidEntryInit(void)
{
   CATAGIESTIM_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CatMdl_SdlSlow_EstimAgi                                    */
/* !Description :  Moniteur lent de la fonction estimation vieillissement cata*/
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_01020_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CATAGIESTIM_vidAgiCata();                                */
/*  input uint8 CATAGIESTIM_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CatMdl_SdlSlow_EstimAgi                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CatMdl_SdlSlow_EstimAgi(void)
{

   if (CATAGIESTIM_u8Inhib != 0x5A)
   {
      CATAGIESTIM_vidAgiCata();
   }
}
/*------------------------------ end of file ---------------------------------*/