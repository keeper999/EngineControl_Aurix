/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKCRITZONE                                             */
/* !Description     : KNKCRITZONE Component                                   */
/*                                                                            */
/* !Module          : KNKCRITZONE                                             */
/* !Description     : DETECTION DE ZONE CRITIQUE                              */
/*                                                                            */
/* !File            : KNKCRITZONE_SCH.C                                       */
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
/*   1 / IgLim_EveRst_CritZone                                                */
/*   2 / IgLim_EveCrTR_CritZone                                               */
/*   3 / IgLim_EveRTCr_CritZone                                               */
/*   4 / IgLim_EveBDC_CritZone                                                */
/*                                                                            */
/* !Reference   : V02 NT 08 05110 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/IGLIM/KNKCRITZONE/KNKCRITZONE_SCH.$*/
/* $Revision::   1.1      $$Author::   wbouach        $$Date::   14 Jan 2011 $*/
/* $Author::   wbouach                                $$Date::   14 Jan 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "KNKCRITZONE.H"
#include "KNKCRITZONE_L.H"
#include "KNKCRITZONE_IM.H"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgLim_EveRst_CritZone                                      */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Oussama Hidri                                              */
/* !Trace_To    :  VEMS_E_08_05110_001.01                                     */
/*                 VEMS_E_08_05110_002.01                                     */
/*                 VEMS_E_08_05110_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKCRITZONE_vidInitialization();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgLim_EveRst_CritZone                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_EveRst_CritZone(void)
{
   KNKCRITZONE_vidInitialization();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgLim_EveCrTR_CritZone                                     */
/* !Description :  Evénement CRANKING vers RUNNING                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Oussama Hidri                                              */
/* !Trace_To    :  VEMS_E_08_05110_003.01                                     */
/*                 VEMS_E_08_05110_002.01                                     */
/*                 VEMS_E_08_05110_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKCRITZONE_vidInitialization();                         */
/*  input uint8 KNKCRITZONE_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgLim_EveCrTR_CritZone                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_EveCrTR_CritZone(void)
{
   if (KNKCRITZONE_u8Inhib != 0x5A)
   {
      KNKCRITZONE_vidInitialization();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgLim_EveRTCr_CritZone                                     */
/* !Description :  Evénement RUNNING vers CRANKING                            */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Oussama Hidri                                              */
/* !Trace_To    :  VEMS_E_08_05110_003.01                                     */
/*                 VEMS_E_08_05110_002.01                                     */
/*                 VEMS_E_08_05110_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKCRITZONE_vidInitialization();                         */
/*  input uint8 KNKCRITZONE_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgLim_EveRTCr_CritZone                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_EveRTCr_CritZone(void)
{
   if (KNKCRITZONE_u8Inhib != 0x5A)
   {
      KNKCRITZONE_vidInitialization();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgLim_EveBDC_CritZone                                      */
/* !Description :  Interruption PMB                                           */
/* !Number      :  SCH.4                                                      */
/* !Author      :  Oussama Hidri                                              */
/* !Trace_To    :  VEMS_E_08_05110_001.01                                     */
/*                 VEMS_E_08_05110_002.01                                     */
/*                 VEMS_E_08_05110_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKCRITZONE_vidComputeCritZone();                        */
/*  input uint8 KNKCRITZONE_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgLim_EveBDC_CritZone                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_EveBDC_CritZone(void)
{
   if (KNKCRITZONE_u8Inhib != 0x5A)
   {
      KNKCRITZONE_vidComputeCritZone();
   }
}

/*------------------------------- end of file --------------------------------*/