/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DIAGTAB                                                 */
/* !Description     : DIAGTAB component.                                      */
/*                                                                            */
/* !Module          : DIAGTAB                                                 */
/* !Description     : Failures Buffer for development tool                    */
/*                                                                            */
/* !File            : DIAGTAB_SCH.C                                           */
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
/*   1 / GD_EveRst_DiagTab                                                    */
/*   2 / GD_SdlSlow_DiagTab                                                   */
/*                                                                            */
/* !Reference   : V02 NT 11 00293 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/DIAGTAB/DIAGTAB_SCH.C_v      $*/
/* $Revision::   1.2      $$Author::   alaouni        $$Date::   04 Apr 2012 $*/
/* $Author::   alaouni                                $$Date::   04 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "DIAGTAB.h"
#include "DIAGTAB_L.h"
#include "DIAGTAB_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRst_DiagTab                                          */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  AMIRA HAMDOUN                                              */
/* !Trace_To    :  VEMS_R_11_00293_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGTAB_vidInitFailuresBuffer();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : GD_EveRst_DiagTab                                              */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRst_DiagTab(void)
{
   DIAGTAB_vidInitFailuresBuffer();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_SdlSlow_DiagTab                                         */
/* !Description :  Moniteur lent pour la fonction DIAGTAB.                    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  AMIRA HAMDOUN                                              */
/* !Trace_To    :  VEMS_R_11_00293_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGTAB_vidFillingFailuresBuffer();                      */
/*  input uint8 DIAGTAB_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : GD_SdlSlow_DiagTab                                             */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_SdlSlow_DiagTab(void)
{
   if (DIAGTAB_u8Inhib != 0x5A)
   {
      DIAGTAB_vidFillingFailuresBuffer();
   }
}

/*------------------------------- end of file --------------------------------*/