/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRBOOSTSP                                              */
/* !Description     : THRBOOSTSP component.                                   */
/*                                                                            */
/* !Module          : THRBOOSTSP                                              */
/* !Description     : BOOST DE LA CONSIGNE DE POSITION PAPILLON MOTORISE      */
/*                                                                            */
/* !File            : THRBOOSTSP_SCH.c                                        */
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
/*   1 / Thr_EveRst_BoostSp                                                   */
/*   2 / Thr_SdlMid_BoostSp                                                   */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRBOOSTSP/THRBOOSTSP_SCH.C_v $*/
/* $Revision::   1.1      $$Author::   acabresp       $$Date::   20 Nov 2009 $*/
/* $Author::   acabresp                               $$Date::   20 Nov 2009 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "THRBOOSTSP.h"
#include "THRBOOSTSP_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Evénement reset du calculateur                              */
/* !Number      : SCH.1                                                       */
/* !Reference   : V02 NT 08 04489 / 2                                         */
/* !Requirement : VEMS_R_08_04489_001.01                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf argret void THRBOOSTSP_InitReset();                                 */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Thr_EveRst_BoostSp                                             */
/* !Trigger  : Thr_EveRst_BoostSp                                             */
/*                                                                            */
/* !LastAuthor  : M.MOALLA                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRst_BoostSp(void)
{
   THRBOOSTSP_InitReset();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Moniteur moyen pour la fonction papillon                    */
/* !Number      : SCH.2                                                       */
/* !Reference   : V02 NT 08 04489 / 2                                         */
/* !Requirement : VEMS_R_08_04489_001.01                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf argret void THRBOOSTSP_BoostSetPointStrategy();                     */
/*                                                                            */
/*   input uint8 THRBOOSTSP_u8Inhib;                                          */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Thr_SdlMid_BoostSp                                             */
/* !Trigger  : Thr_SdlMid_BoostSp                                             */
/*                                                                            */
/* !LastAuthor  : M.MOALLA                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_SdlMid_BoostSp(void)
{
   if (THRBOOSTSP_u8Inhib != 0x5A)
   {
      THRBOOSTSP_BoostSetPointStrategy();
   }
}
/*-------------------------------- end of file -------------------------------*/