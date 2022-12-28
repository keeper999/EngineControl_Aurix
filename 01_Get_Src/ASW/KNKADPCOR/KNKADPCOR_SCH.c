/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKADPCOR                                               */
/* !Description     : KNKADPCOR component.                                    */
/*                                                                            */
/* !Module          : KNKADPCOR                                               */
/* !Description     : CORRECTION AUTO-ADAPTATIVE DU CLIQUETIS.                */
/*                                                                            */
/* !File            : KNKADPCOR_SCH.C                                         */
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
/*   1 / IgLim_EveBDC_KnkAdpCor                                               */
/*   2 / IgLim_EveRst_KnkAdpCor                                               */
/*   3 / IgLim_SdlFast_KnkAdpCor                                              */
/*   4 / IgLim_SdlMid_KnkAdpCor                                               */
/*   5 / IgLim_SdlSlow_KnkAdpCor                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5154831 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/IGLIM/KNKADPCOR/KNKADPCOR_SCH.C_v $*/
/* $Revision::   1.11     $$Author::   wbouach        $$Date::   09 May 2012 $*/
/* $Author::   wbouach                                $$Date::   09 May 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "KNKADPCOR.h"
#include "KNKADPCOR_L.h"
#include "KNKADPCOR_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgLim_EveBDC_KnkAdpCor                                     */
/* !Description :  Evènement point mort bas admission                         */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_09_00105_001.01                                     */
/*                 VEMS_E_09_00105_002.01                                     */
/*                 VEMS_E_09_00105_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKADPCOR_vidFuelDetection();                            */
/*  extf argret void KNKADPCOR_vidAdaptativeCompute();                        */
/*  extf argret void KNKADPCOR_vidCylAdaptation();                            */
/*  extf argret void KNKADPCOR_vidAdaptativeReading();                        */
/*  extf argret void KNKADPCOR_vidCounterReset();                             */
/*  extf argret void KNKADPCOR_vidAntiKnockPrevention();                      */
/*  extf argret void KNKADPCOR_vidFiltering();                                */
/*  extf argret void KNKADPCOR_vidEngSpdEngLoadSaving();                      */
/*  input uint8 KNKADPCOR_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgLim_EveBDC_KnkAdpCor                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_EveBDC_KnkAdpCor(void)
{
   if (KNKADPCOR_u8Inhib != 0x5A)
   {
      KNKADPCOR_vidFuelDetection();
      KNKADPCOR_vidAdaptativeCompute();
      KNKADPCOR_vidCylAdaptation();
      KNKADPCOR_vidAdaptativeReading();
      KNKADPCOR_vidCounterReset();
      KNKADPCOR_vidAntiKnockPrevention();
      KNKADPCOR_vidFiltering();
      KNKADPCOR_vidEngSpdEngLoadSaving();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgLim_EveRst_KnkAdpCor                                     */
/* !Description :  Evènement reset                                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_09_00105_001.01                                     */
/*                 VEMS_E_09_00105_002.01                                     */
/*                 VEMS_E_09_00105_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKADPCOR_vidInitOutput();                               */
/*  extf argret void KNKADPCOR_vidInitMaxAdvance();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :IgLim_EveRst_KnkAdpCor                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_EveRst_KnkAdpCor(void)
{
   KNKADPCOR_vidInitOutput();
   KNKADPCOR_vidInitMaxAdvance();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgLim_SdlFast_KnkAdpCor                                    */
/* !Description :  Moniteur rapide de la fonction IgLim                       */
/* !Number      :  SCH.3                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_09_00105_001.01                                     */
/*                 VEMS_E_09_00105_002.01                                     */
/*                 VEMS_E_09_00105_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKADPCOR_vidAdaptWriteCond();                           */
/*  input uint8 KNKADPCOR_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgLim_SdlFast_KnkAdpCor                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_SdlFast_KnkAdpCor(void)
{
   if (KNKADPCOR_u8Inhib != 0x5A)
   {
      KNKADPCOR_vidAdaptWriteCond();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgLim_SdlMid_KnkAdpCor                                     */
/* !Description :  Moniteur moyen de la fonction IgLim                        */
/* !Number      :  SCH.4                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_09_00105_001.01                                     */
/*                 VEMS_E_09_00105_002.01                                     */
/*                 VEMS_E_09_00105_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKADPCOR_vidEngLoadStable();                            */
/*  input uint8 KNKADPCOR_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgLim_SdlMid_KnkAdpCor                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_SdlMid_KnkAdpCor(void)
{
   if (KNKADPCOR_u8Inhib != 0x5A)
   {
      KNKADPCOR_vidEngLoadStable();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgLim_SdlSlow_KnkAdpCor                                    */
/* !Description :  Moniteur lent de la fonction IgLim                         */
/* !Number      :  SCH.5                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_09_00105_003.01                                     */
/*                 VEMS_E_09_00105_001.01                                     */
/*                 VEMS_E_09_00105_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKADPCOR_vidEngSpdStable();                             */
/*  input uint8 KNKADPCOR_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgLim_SdlSlow_KnkAdpCor                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_SdlSlow_KnkAdpCor(void)
{
   if (KNKADPCOR_u8Inhib != 0x5A)
   {
      KNKADPCOR_vidEngSpdStable();
   }
}
/*---------------------------- end of file -----------------------------------*/