/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HOTSENO2FLG                                             */
/* !Description     : HOTSENO2FLG Component                                   */
/*                                                                            */
/* !Module          : HOTSENO2FLG                                             */
/* !Description     : Determination des sondes lambda chaudes                 */
/*                                                                            */
/* !File            : HOTSENO2FLG_SCH.C                                       */
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
/*   1 / HeatSenO2_EveRst_HotSenO2Flg                                         */
/*   2 / HeatSenO2_EveCrTR_HotSenO2Flg                                        */
/*   3 / HeatSenO2_SdlMid_HotSenO2Flg                                         */
/*                                                                            */
/* !Reference   : V02 NT 08 06204 / 07                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/HEATSENO2/HOTSENO2FLG/HOTSENO2FLG_$*/
/* $Revision::   1.5      $$Author::   wbouach        $$Date::   10 Aug 2011 $*/
/* $Author::   wbouach                                $$Date::   10 Aug 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "HOTSENO2FLG.H"
#include "HOTSENO2FLG_L.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_EveRst_HotSenO2Flg                               */
/* !Description :  Evenement Reset.                                           */
/* !Number      :  SCH.1                                                      */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HOTSENO2FLG_vidInitEveRst();                             */
/*  extf argret void HOTSENO2FLG_vidInitOutput();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_EveRst_HotSenO2Flg                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_EveRst_HotSenO2Flg(void)
{
   HOTSENO2FLG_vidInitEveRst();
   HOTSENO2FLG_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_EveCrTR_HotSenO2Flg                              */
/* !Description :  Evénement Cranking -> Running                              */
/* !Number      :  SCH.2                                                      */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HOTSENO2FLG_vidInitCrTR();                               */
/*  input uint8 HOTSENO2FLG_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_EveCrTR_HotSenO2Flg                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_EveCrTR_HotSenO2Flg(void)
{
   if (HOTSENO2FLG_u8Inhib != 0x5A)
   {
      HOTSENO2FLG_vidInitCrTR();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlMid_HotSenO2Flg                               */
/* !Description :  Moniteur intermédiaire de la fonction HeatSenO2            */
/* !Number      :  SCH.3                                                      */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HOTSENO2FLG_vidHotSenO2Volt();                           */
/*  extf argret void HOTSENO2FLG_vidHotSenO2Heatst();                         */
/*  input uint8 HOTSENO2FLG_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_SdlMid_HotSenO2Flg                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlMid_HotSenO2Flg(void)
{
   if (HOTSENO2FLG_u8Inhib != 0x5A)
   {
      HOTSENO2FLG_vidHotSenO2Volt();
      HOTSENO2FLG_vidHotSenO2Heatst();
   }
}

/*------------------------------- end of file --------------------------------*/