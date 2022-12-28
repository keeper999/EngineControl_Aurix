/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKFASTCOR                                              */
/* !Description     : KNKFASTCOR Component                                    */
/*                                                                            */
/* !Module          : KNKFASTCOR                                              */
/* !Description     : Correction rapide d’avance anti-cliquetis               */
/*                                                                            */
/* !File            : KNKFASTCOR_SCH.C                                        */
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
/*   1 / IgLim_EveRst_FastCor                                                 */
/*   2 / IgLim_EveCrTR_FastCor                                                */
/*   3 / IgLim_EveRTCr_FastCor                                                */
/*   4 / IgLim_EveBDC_FastCor                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_5059533 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/IGLIM/KNKFASTCOR/KNKFASTCOR_SCH.C_$*/
/* $Revision::   1.2      $$Author::   wbouach        $$Date::   25 Mar 2011 $*/
/* $Author::   wbouach                                $$Date::   25 Mar 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "KNKFASTCOR.h"
#include "KNKFASTCOR_L.h"
#include "KNKFASTCOR_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgLim_EveRst_FastCor                                       */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_08_07418_002.01                                     */
/*                 VEMS_E_08_07418_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKFASTCOR_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgLim_EveRst_FastCor                                           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_EveRst_FastCor(void)
{
   KNKFASTCOR_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgLim_EveCrTR_FastCor                                      */
/* !Description :  Evénement CRANKING vers RUNNING                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_08_07418_002.01                                     */
/*                 VEMS_E_08_07418_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKFASTCOR_vidInitOutput();                              */
/*  input uint8 KNKFASTCOR_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgLim_EveCrTR_FastCor                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_EveCrTR_FastCor(void)
{
   if (KNKFASTCOR_u8Inhib != 0x5A)
   {
      KNKFASTCOR_vidInitOutput();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgLim_EveRTCr_FastCor                                      */
/* !Description :  Evénement RUNNING vers CRANKING                            */
/* !Number      :  SCH.3                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_08_07418_002.01                                     */
/*                 VEMS_E_08_07418_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKFASTCOR_vidInitOutput();                              */
/*  input uint8 KNKFASTCOR_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgLim_EveRTCr_FastCor                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_EveRTCr_FastCor(void)
{
   if (KNKFASTCOR_u8Inhib != 0x5A)
   {
      KNKFASTCOR_vidInitOutput();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgLim_EveBDC_FastCor                                       */
/* !Description :  Interruption PMB                                           */
/* !Number      :  SCH.4                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_08_07418_002.01                                     */
/*                 VEMS_E_08_07418_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKFASTCOR_vidFastCorrectionCalc();                      */
/*  input uint8 KNKFASTCOR_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgLim_EveBDC_FastCor                                           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_EveBDC_FastCor(void)
{
   if (KNKFASTCOR_u8Inhib != 0x5A)
   {
      KNKFASTCOR_vidFastCorrectionCalc();
   }
}
/*--------------------------------- end of file ------------------------------*/