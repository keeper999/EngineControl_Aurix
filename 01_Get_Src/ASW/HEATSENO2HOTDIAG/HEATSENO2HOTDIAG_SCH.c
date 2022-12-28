/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2HOTDIAG                                        */
/* !Description     : HEATSENO2HOTDIAG component                              */
/*                                                                            */
/* !Module          : HEATSENO2HOTDIAG                                        */
/* !Description     : DIAGNOSTIC FONCTIONNEL CHAUFFAGE SONDE AMONT ET AVAL    */
/*                                                                            */
/* !File            : HEATSENO2HOTDIAG_SCH.C                                  */
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
/*   1 / HeatSenO2_EveRst_HeatSenO2Mon                                        */
/*   2 / HeatSenO2_SdlFast_HeatSenO2Mon                                       */
/*                                                                            */
/* !Reference   : V02 NT 12 00470 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/HEATSENO2/HEATSENO2HOTDIAG/HEATS$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   26 Sep 2013 $*/
/* $Author::   etsasson                               $$Date::   26 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "HEATSENO2HOTDIAG.h"
#include "HEATSENO2HOTDIAG_L.h"
#include "HEATSENO2HOTDIAG_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_EveRst_HeatSenO2Mon                              */
/* !Description :  Evènement reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_00470_001.01                                     */
/*                 VEMS_R_12_00470_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2HOTDIAG_vidInitOutput();                        */
/*  extf argret void HEATSENO2HOTDIAG_vidInit();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_EveRst_HeatSenO2Mon                                  */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_EveRst_HeatSenO2Mon(void)
{
   HEATSENO2HOTDIAG_vidInitOutput();
   HEATSENO2HOTDIAG_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlFast_HeatSenO2Mon                             */
/* !Description :  Moniteur rapide pour la fonction HeatSenO2                 */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_00470_001.01                                     */
/*                 VEMS_R_12_00470_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2HOTDIAG_vidUsheat();                            */
/*  extf argret void HEATSENO2HOTDIAG_vidDsheat();                            */
/*  extf argret void HEATSENO2HOTDIAG_vidUsHeat_Euro6();                      */
/*  extf argret void HEATSENO2HOTDIAG_vidDsHeat_Euro6();                      */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft,argin boolean        */
/* bDgo,argin boolean bMonRun,argin boolean Ns_bMonWait);                     */
/*  extf argret void HEATSENO2HOTDIAG_vidTgInitCbMdTn();                      */
/*  input uint8 HEATSENO2HOTDIAG_u8Inhib;                                     */
/*  input boolean HeatSenO2_bDgoORng_UsHeat;                                  */
/*  input boolean HeatSenO2_bMonRunORng_UsHeat;                               */
/*  input boolean HeatSenO2_bDgoORng_DsHeat;                                  */
/*  input boolean HeatSenO2_bMonRunORng_DsHeat;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_SdlFast_HeatSenO2Mon                                 */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlFast_HeatSenO2Mon(void)
{
   if (HEATSENO2HOTDIAG_u8Inhib != 0x5A)
   {
      HEATSENO2HOTDIAG_vidUsheat();
      HEATSENO2HOTDIAG_vidDsheat();
      HEATSENO2HOTDIAG_vidUsHeat_Euro6();
      HEATSENO2HOTDIAG_vidDsHeat_Euro6();
      GDGAR_vidGdu(GD_DFT_ORNG_USHEAT,
                   HeatSenO2_bDgoORng_UsHeat,
                   HeatSenO2_bMonRunORng_UsHeat,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNG_DSHEAT,
                   HeatSenO2_bDgoORng_DsHeat,
                   HeatSenO2_bMonRunORng_DsHeat,
                   DIAG_DISPO);
      HEATSENO2HOTDIAG_vidTgInitCbMdTn();
   }
}

/*------------------------------- end of file --------------------------------*/