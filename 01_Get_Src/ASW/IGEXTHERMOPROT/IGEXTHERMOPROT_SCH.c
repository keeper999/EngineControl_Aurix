/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IGEXTHERMOPROT                                          */
/* !Description     : IGEXTHERMOPROT component.                               */
/*                                                                            */
/* !Module          : IGEXTHERMOPROT                                          */
/* !Description     : PROTECTION THERMIQUE DE LA LIGNE D’ECHAPPEMENT.         */
/*                                                                            */
/* !File            : IGEXTHERMOPROT_SCH.C                                    */
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
/*   1 / IGEXTHERMOPROT_vidEntryInit                                          */
/*   2 / IgSys_SdlMid_IgExThermoProt                                          */
/*   3 / IgSys_EveBDC_IgExThermoProt                                          */
/*                                                                            */
/* !Reference   : V02 NT 08 06151 / 08                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/IGEXTHERMOPROT/IGEXTHERMOPROT_SCH.$*/
/* $Revision::   1.9      $$Author::   wbouach        $$Date::   13 Jun 2012 $*/
/* $Author::   wbouach                                $$Date::   13 Jun 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "IGEXTHERMOPROT.h"
#include "IGEXTHERMOPROT_l.h"
#include "IGEXTHERMOPROT_IM.h"
#include "SWFAIL.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGEXTHERMOPROT_vidEntryInit                                */
/* !Description :  Fonction d'accroche au reset                               */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_08_06151_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGEXTHERMOPROT_vidInitOutput();                          */
/*  extf argret void IGEXTHERMOPROT_vidResetProtTherm();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Reset                                                          */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGEXTHERMOPROT_vidEntryInit(void)
{
   IGEXTHERMOPROT_vidInitOutput();
   IGEXTHERMOPROT_vidResetProtTherm();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgSys_SdlMid_IgExThermoProt                                */
/* !Description :  Fonction d'accroche au moniteur IgSys_SdlMid_IgExThermoProt*/
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_08_06151_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGEXTHERMOPROT_vidProtAdvCalc();                         */
/*  extf argret void IGEXTHERMOPROT_vidYieldAdvCalc();                        */
/*  extf argret void IGEXTHERMOPROT_vidThermProt();                           */
/*  input uint8 IGEXTHERMOPROT_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgSys_SdlMid_IgExThermoProt                                    */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgSys_SdlMid_IgExThermoProt(void)
{
   if (IGEXTHERMOPROT_u8Inhib != 0x5A)
   {
      IGEXTHERMOPROT_vidProtAdvCalc();
      IGEXTHERMOPROT_vidYieldAdvCalc();
      IGEXTHERMOPROT_vidThermProt();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgSys_EveBDC_IgExThermoProt                                */
/* !Description :  Fonction d'accroche au moniteur IgSys_EveBDC_IgExThermoProt*/
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_08_06151_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGEXTHERMOPROT_vidAdvCalc();                             */
/*  input uint8 IGEXTHERMOPROT_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgSys_EveBDC_IgExThermoProt                                    */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgSys_EveBDC_IgExThermoProt(void)
{
   if (IGEXTHERMOPROT_u8Inhib != 0x5A)
   {
      IGEXTHERMOPROT_vidAdvCalc();
   }
}
/*------------------------------- end of file --------------------------------*/