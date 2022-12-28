/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRACTEST                                               */
/* !Description     : THRACTEST component.                                    */
/*                                                                            */
/* !Module          : THRACTEST                                               */
/* !Description     : TEST ACTIONNEUR PAPILLON MOTORISÉ.                      */
/*                                                                            */
/* !File            : THRACTEST_SCH.C                                         */
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
/*   1 / Thr_EveRst_ActrTstThr                                                */
/*   2 / Thr_SdlMid_ActrTstThr                                                */
/*                                                                            */
/* !Reference   : V02 NT 09 00783 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#056850                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/REF/MODULES/THR/THRACTEST/THRACTEST_SCH.C_v $*/
/* $Revision::   1.1      $$Author::   alaouni        $$Date::   06 Oct 2011 $*/
/* $Author::   alaouni                                $$Date::   06 Oct 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/



#include "STD_TYPES.h"
#include "THRACTEST.h"
#include "THRACTEST_L.h"
#include "THRACTEST_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveRst_ActrTstThr                                      */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  F.SARHAN                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRACTEST_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveRst_ActrTstThr                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRst_ActrTstThr(void)
{
   THRACTEST_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_SdlMid_ActrTstThr                                      */
/* !Description :  Moniteur moyen de la fonction Thr.                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  F.SARHAN                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRACTEST_vidThrTstSpChart();                            */
/*  extf argret void THRACTEST_vidDynTstSpeed();                              */
/*  extf argret void THRACTEST_vidGapTestMain();                              */
/*  input uint8 THRACTEST_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_SdlMid_ActrTstThr                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_SdlMid_ActrTstThr(void)
{
   if (THRACTEST_u8Inhib != 0x5A)
   {
      THRACTEST_vidThrTstSpChart();
      THRACTEST_vidDynTstSpeed();
      THRACTEST_vidGapTestMain();
   }
}
/*---------------------------- end of file -----------------------------------*/