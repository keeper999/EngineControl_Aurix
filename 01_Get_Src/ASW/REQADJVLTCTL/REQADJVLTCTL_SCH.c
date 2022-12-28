/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : REQADJVLTCTL                                            */
/* !Description     : REQADJVLTCTL Component                                  */
/*                                                                            */
/* !Module          : REQADJVLTCTL                                            */
/* !Description     : GESTION CHAUFFAGE SONDE AVAL                            */
/*                                                                            */
/* !File            : REQADJVLTCTL_SCH.C                                      */
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
/*   1 / HeatSenO2_EveRst_ReqAdjVltCtl                                        */
/*   2 / HeatSenO2_SdlMid_ReqAdjVltCtl                                        */
/*                                                                            */
/* !Reference   : V02 NT 11 03742 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/HEATSENO2/REQADJVLTCTL/REQADJVLT$*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   25 Jun 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   25 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "REQADJVLTCTL.h"
#include "REQADJVLTCTL_L.h"
#include "REQADJVLTCTL_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_EveRst_ReqAdjVltCtl                              */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void REQADJVLTCTL_vidInitReqAdjVltCtl();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : HeatSenO2_EveRst_ReqAdjVltCtl                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_EveRst_ReqAdjVltCtl(void)
{
   REQADJVLTCTL_vidInitReqAdjVltCtl();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlMid_ReqAdjVltCtl                              */
/* !Description :  Moniteur moyen pour le module chauffage sonde O2           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void REQADJVLTCTL_vidTraitReqAdjVltCt();                      */
/*  input uint8 REQADJVLTCTL_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : HeatSenO2_SdlMid_ReqAdjVltCtl                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlMid_ReqAdjVltCtl(void)
{
   if (REQADJVLTCTL_u8Inhib != 0x5A)
   {
      REQADJVLTCTL_vidTraitReqAdjVltCt();
   }
}
/*------------------------------- end of file --------------------------------*/