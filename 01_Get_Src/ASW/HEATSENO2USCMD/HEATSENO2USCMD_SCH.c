/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2USCMD                                          */
/* !Description     : HEATSENO2USCMD Component                                */
/*                                                                            */
/* !Module          : HEATSENO2USCMD                                          */
/* !Description     : COMMANDE DU CHAUFFAGE SONDE O2 ON/OFF AMONT             */
/*                                                                            */
/* !File            : HEATSENO2USCMD_SCH.c                                    */
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
/*   1 / HEATSENO2USCMD_vidEntryInit                                          */
/*   2 / HeatSenO2_SdlMid_UsCmd                                               */
/*   3 / HeatSenO2_SdlFast_UsCmd                                              */
/*                                                                            */
/* !Reference   : V02 NT 09 04308 / 07                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/HEATSENO2/HEATSENO2USCMD/HEATSEN$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   26 Sep 2013 $*/
/* $Author::   etsasson                               $$Date::   26 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "HEATSENO2USCMD.H"
#include "HEATSENO2USCMD_L.h"
#include "HEATSENO2USCMD_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2USCMD_vidEntryInit                                */
/* !Description :  Fonction d'accroche à l'événement Reset                    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2USCMD_vidInitOutput();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HEATSENO2USCMD_vidEntryInit                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2USCMD_vidEntryInit(void)
{
   HEATSENO2USCMD_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlMid_UsCmd                                     */
/* !Description :  Moniteur moyen du module chauffage sondes O2               */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2USCMD_vidLsUsHeatRaw();                         */
/*  extf argret void HEATSENO2USCMD_vidLsUsHeatMan();                         */
/*  extf argret void HEATSENO2USCMD_vidLsUsHeatCor();                         */
/*  extf argret void HEATSENO2USCMD_vidLsUsHeatDiag();                        */
/*  input uint8 HEATSENO2USCMD_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_SdlMid_UsCmd                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlMid_UsCmd(void)
{
   if (HEATSENO2USCMD_u8Inhib != 0x5A)
   {
      HEATSENO2USCMD_vidLsUsHeatRaw();
      HEATSENO2USCMD_vidLsUsHeatMan();
      HEATSENO2USCMD_vidLsUsHeatCor();
      HEATSENO2USCMD_vidLsUsHeatDiag();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlFast_UsCmd                                    */
/* !Description :  Moniteur rapide du module chauffage sonde 02               */
/* !Number      :  SCH.3                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2USCMD_vidLsUsHeatReq();                         */
/*  extf argret void HEATSENO2USCMD_vidLsUsHeatCmd();                         */
/*  extf argret void HEATSENO2USCMD_vidLsUsHeatTst();                         */
/*  input uint8 HEATSENO2USCMD_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_SdlFast_UsCmd                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlFast_UsCmd(void)
{
   if (HEATSENO2USCMD_u8Inhib != 0x5A)
   {
      HEATSENO2USCMD_vidLsUsHeatReq();
      HEATSENO2USCMD_vidLsUsHeatCmd();
      HEATSENO2USCMD_vidLsUsHeatTst();
   }
}

/*------------------------------- end of file --------------------------------*/