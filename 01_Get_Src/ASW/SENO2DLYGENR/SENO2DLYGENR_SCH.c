/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SENO2DLYGENR                                            */
/* !Description     : SENO2DLYGENR Component                                  */
/*                                                                            */
/* !Module          : SENO2DLYGENR                                            */
/* !Description     : TEST BED MODE FOR THE UPSTREAM OXYGEN SENSOR VOLTAGE    */
/*                                                                            */
/* !File            : SENO2DLYGENR_SCH.C                                      */
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
/*   1 / SENO2DLYGENR_vidEntryInit                                            */
/*   2 / SenO2Us_SdlFast_SenO2DlyGenr                                         */
/*                                                                            */
/* !Reference   : V02 NT 09 06150 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SENO2DLYGENR/SENO2DLYGENR_SCH.C_v $*/
/* $Revision::   1.2      $$Author::   wbouach        $$Date::   15 Dec 2010 $*/
/* $Author::   wbouach                                $$Date::   15 Dec 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SENO2DLYGENR.h"
#include "SENO2DLYGENR_L.h"
#include "SENO2DLYGENR_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SENO2DLYGENR_vidEntryInit                                  */
/* !Description :  Evenement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  BKBO                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SENO2DLYGENR_vidInitOutput();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : SENO2DLYGENR_vidEntryInit                                      */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SENO2DLYGENR_vidEntryInit(void)
{
   SENO2DLYGENR_vidInitOutput();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Us_SdlFast_SenO2DlyGenr                               */
/* !Description :  Moniteur rapide de la fonction SenO2DlyGenr                */
/* !Number      :  SCH.2                                                      */
/* !Author      :  BKBO                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SENO2DLYGENR_vidUpOxyTestBed();                          */
/*  input uint8 SENO2DLYGENR_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : SenO2Us_SdlFast_SenO2DlyGenr                                   */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Us_SdlFast_SenO2DlyGenr(void)
{
   if (SENO2DLYGENR_u8Inhib != 0x5A)
   {
      SENO2DLYGENR_vidUpOxyTestBed();
   }
}

/*------------------------------- end of file --------------------------------*/