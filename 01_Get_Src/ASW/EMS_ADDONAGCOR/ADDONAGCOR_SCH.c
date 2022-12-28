/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ADDONAGCOR                                              */
/* !Description     : ADDONAGCOR Component                                    */
/*                                                                            */
/* !Module          : ADDONAGCOR                                              */
/* !Description     : DEFORMATION DE LA COURBE UNIQUE                         */
/*                                                                            */
/* !File            : ADDONAGCOR_SCH.C                                        */
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
/*   1 / ADDONAGCOR_vidEntryInit                                              */
/*   2 / IgSys_EveTDC_AddOnAgCor                                              */
/*                                                                            */
/* !Reference   : V02 NT 11 01473 / 01                                        */
/* !OtherRefs   : 01460_10_01467_2 / 01                                       */
/* !OtherRefs   : VEMS V02 ECU#054464                                         */
/* !OtherRefs   : VEMS V02 ECU#053827                                         */
/* !OtherRefs   : VEMS V02 ECU#058132                                         */
/* !OtherRefs   : VEMS V02 ECU#058205                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "ADDONAGCOR.h"
#include "ADDONAGCOR_L.h"
#include "ADDONAGCOR_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONAGCOR_vidEntryInit                                    */
/* !Description :  Evénement Reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01473_001.01                                     */
/*                 VEMS_R_11_01473_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ADDONAGCOR_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : ADDONAGCOR_vidEntryInit                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONAGCOR_vidEntryInit(void)
{
   ADDONAGCOR_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgSys_EveTDC_AddOnAgCor                                    */
/* !Description :  Occurrence de calcul de la fonction AddOnAgCor             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01473_001.01                                     */
/*                 VEMS_R_11_01473_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ADDONAGCOR_vidUnvectorize_Mode();                        */
/*  extf argret void ADDONAGCOR_vidMode_Mask();                               */
/*  extf argret void ADDONAGCOR_vidCalibrations();                            */
/*  extf argret void ADDONAGCOR_vidSelect_Modes();                            */
/*  extf argret void ADDONAGCOR_vidInterpolation();                           */
/*  extf argret void ADDONAGCOR_vidCoordination();                            */
/*  input uint8 ADDONAGCOR_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgSys_EveTDC_AddOnAgCor                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgSys_EveTDC_AddOnAgCor(void)
{
   if (ADDONAGCOR_u8Inhib != 0x5A)
   {
      ADDONAGCOR_vidUnvectorize_Mode();
      ADDONAGCOR_vidMode_Mask();
      ADDONAGCOR_vidCalibrations();
      ADDONAGCOR_vidSelect_Modes();
      ADDONAGCOR_vidInterpolation();
      ADDONAGCOR_vidCoordination();
   }
}

/*------------------------------- end of file --------------------------------*/