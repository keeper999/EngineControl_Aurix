/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2DSCMD                                          */
/* !Description     : HEATSENO2DSCMD Component                                */
/*                                                                            */
/* !Module          : HEATSENO2DSCMD                                          */
/* !Description     : COMMANDE DU CHAUFFAGE SONDE O2 ON/OFF AVAL              */
/*                                                                            */
/* !File            : HEATSENO2DSCMD_SCH.C                                    */
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
/*   1 / HEATSENO2DSCMD_vidEntryInit                                          */
/*   2 / HeatSenO2_SdlMid_DsCmd                                               */
/*   3 / HeatSenO2_SdlFast_DsCmd                                              */
/*                                                                            */
/* !Reference   : V02 NT 09 04727 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/HEATSENO2/HEATSENO2DSCMD/HEATSENO2$*/
/* $Revision::   1.4      $$Author::   wbouach        $$Date::   24 Apr 2012 $*/
/* $Author::   wbouach                                $$Date::   24 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "HEATSENO2DSCMD.H"
#include "HEATSENO2DSCMD_l.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSCMD_vidEntryInit                                */
/* !Description :  Fonction d'accroche à l'événement Reset                    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2DSCMD_vidInitOutput();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HEATSENO2DSCMD_vidEntryInit                                    */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSCMD_vidEntryInit(void)
{
   HEATSENO2DSCMD_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlMid_DsCmd                                     */
/* !Description :  Moniteur moyen du module chauffage sondes O2               */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2DSCMD_vidLsUsHeatRaw();                         */
/*  extf argret void HEATSENO2DSCMD_vidLsUsHeatMan();                         */
/*  extf argret void HEATSENO2DSCMD_vidLsUsHeatCor();                         */
/*  extf argret void HEATSENO2DSCMD_vidLsUsHeatDiag();                        */
/*  input uint8 HEATSENO2DSCMD_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_SdlMid_DsCmd                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlMid_DsCmd(void)
{
   if (HEATSENO2DSCMD_u8Inhib != 0x5A)
   {
      HEATSENO2DSCMD_vidLsUsHeatRaw();
      HEATSENO2DSCMD_vidLsUsHeatMan();
      HEATSENO2DSCMD_vidLsUsHeatCor();
      HEATSENO2DSCMD_vidLsUsHeatDiag();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlFast_DsCmd                                    */
/* !Description :  Moniteur rapide du module chauffage sonde 02               */
/* !Number      :  SCH.3                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2DSCMD_vidLsUsHeatReq();                         */
/*  extf argret void HEATSENO2DSCMD_vidLsUsHeatCmd();                         */
/*  extf argret void HEATSENO2DSCMD_vidLsUsHeatTst();                         */
/*  input uint8 HEATSENO2DSCMD_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_SdlFast_DsCmd                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlFast_DsCmd(void)
{
   if (HEATSENO2DSCMD_u8Inhib != 0x5A)
   {
      HEATSENO2DSCMD_vidLsUsHeatReq();
      HEATSENO2DSCMD_vidLsUsHeatCmd();
      HEATSENO2DSCMD_vidLsUsHeatTst();
   }
}

/*------------------------------- end of file --------------------------------*/