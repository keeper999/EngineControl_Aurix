/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJCUTOFFBVMP                                           */
/* !Description     : INJCUTOFFBVMP Component                                 */
/*                                                                            */
/* !Module          : INJCUTOFFBVMP                                           */
/* !Description     : Gestion de la demande de coupure injection pour la BVMP */
/*                                                                            */
/* !File            : INJCUTOFFBVMP_SCH.C                                     */
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
/*   1 / InjCutOff_EveRst_InjCutOffBvmp                                       */
/*   2 / InjCutOff_SdlFast_InjCutOffBvmp                                      */
/*                                                                            */
/* !Reference   : V02 NT 11 07837 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/INJCUTOFFBVMP/INJCUTOFFBVMP_SCH.C_$*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   12 Dec 2011 $*/
/* $Author::   wbouach                                $$Date::   12 Dec 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "INJCUTOFFBVMP.h"
#include "INJCUTOFFBVMP_l.h"
#include "INJCUTOFFBVMP_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCutOff_EveRst_InjCutOffBvmp                             */
/* !Description :  Evènement de reset du calculateur.                         */
/* !Number      :  SCH.1                                                      */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCUTOFFBVMP_vidInitBVMPFCO();                          */
/*  extf argret void INJCUTOFFBVMP_vidInitOutput();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCutOff_EveRst_InjCutOffBvmp                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCutOff_EveRst_InjCutOffBvmp(void)
{
   INJCUTOFFBVMP_vidInitBVMPFCO();
   INJCUTOFFBVMP_vidInitOutput();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCutOff_SdlFast_InjCutOffBvmp                            */
/* !Description :  Moniteur rapide pour la fonction coupure d'injection.      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCUTOFFBVMP_vidCalcBVMPFCO();                          */
/*  input uint8 INJCUTOFFBVMP_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCutOff_SdlFast_InjCutOffBvmp                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCutOff_SdlFast_InjCutOffBvmp(void)
{
   if (INJCUTOFFBVMP_u8Inhib != 0x5A)
   {
      INJCUTOFFBVMP_vidCalcBVMPFCO();
   }
}
/*------------------------------- end of file --------------------------------*/