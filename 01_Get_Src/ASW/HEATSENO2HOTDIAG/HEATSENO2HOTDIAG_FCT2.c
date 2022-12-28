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
/* !File            : HEATSENO2HOTDIAG_FCT2.C                                 */
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
/*   1 / HEATSENO2HOTDIAG_vidUsHeat_Euro6                                     */
/*   2 / HEATSENO2HOTDIAG_vidDsHeat_Euro6                                     */
/*                                                                            */
/* !Reference   : V02 NT 12 00470 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                 */
/* $Revision::                                                                */
/* $Author::                                                                  */
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
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2HOTDIAG_vidUsHeat_Euro6                           */
/* !Description :  Les variables finales envoyées au Mode06 (FacMes, FacMax)  */
/*                 sont gelées lorsque la panne est présente mais non  encore */
/*                 confirmée par le GD/GAR. Si on calibre                     */
/*                 HeatSenO2_bAcvEuro6UsHeat_C à 0, on revient sur le         */
/*                 fonctionnel  d’origine (EB).                               */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_00470_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean HeatSenO2_bAcvEuro6UsHeat_C;                                */
/*  input boolean HeatSenO2_bDgoORng_UsHeat;                                  */
/*  input uint16 HeatSenO2_UsFacMesRaw;                                       */
/*  input uint16 HeatSenO2_UsFacMaxRaw;                                       */
/*  output uint16 HeatSenO2_UsFacMes_Obd6Mod;                                 */
/*  output uint16 HeatSenO2_UsFacMax_Obd6Mod;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2HOTDIAG_vidUsHeat_Euro6(void)
{
   boolean  bLocalFRM_bCfmHeatSenO2UsDftRes;
   uint16   u16LocalHeatSenO2_UsMes_Obd6Mod;
   uint16   u16LocalHeatSenO2_UsMax_Obd6Mod;


   bLocalFRM_bCfmHeatSenO2UsDftRes =
      GDGAR_bGetFRM(FRM_FRM_CFMHEATSENO2USDFTRES);
   if (  (bLocalFRM_bCfmHeatSenO2UsDftRes != 0)
      || (  (HeatSenO2_bAcvEuro6UsHeat_C == 0)
         || (HeatSenO2_bDgoORng_UsHeat == 0)))
   {
      u16LocalHeatSenO2_UsMes_Obd6Mod = HeatSenO2_UsFacMesRaw;
      u16LocalHeatSenO2_UsMax_Obd6Mod = HeatSenO2_UsFacMaxRaw;
      VEMS_vidSET(HeatSenO2_UsFacMes_Obd6Mod, u16LocalHeatSenO2_UsMes_Obd6Mod);
      VEMS_vidSET(HeatSenO2_UsFacMax_Obd6Mod, u16LocalHeatSenO2_UsMax_Obd6Mod);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2HOTDIAG_vidDsHeat_Euro6                           */
/* !Description :  Les variables finales envoyées au Mode06 (FacMes, FacMax)  */
/*                 sont gelées lorsque la panne est présente mais non encore  */
/*                 confirmée par le GD/GAR. Si on                             */
/*                 calibreHeatSenO2_bAcvEuro6DsHeat_C à 0, on revient sur le  */
/*                 fonctionnel d’origine (EB).                                */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean HeatSenO2_bAcvEuro6DsHeat_C;                                */
/*  input boolean HeatSenO2_bDgoORng_DsHeat;                                  */
/*  input uint16 HeatSenO2_DsFacMesRaw;                                       */
/*  input uint16 HeatSenO2_DsFacMaxRaw;                                       */
/*  output uint16 HeatSenO2_DsFacMes_Obd6Mod;                                 */
/*  output uint16 HeatSenO2_DsFacMax_Obd6Mod;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2HOTDIAG_vidDsHeat_Euro6(void)
{
   boolean  bLocalFRM_bCfmHeatSenO2DsDftRes;
   uint16   u16LocalHeatSenO2_DsMes_Obd6Mod;
   uint16   u16LocalHeatSenO2_DsMax_Obd6Mod;


   bLocalFRM_bCfmHeatSenO2DsDftRes =
      GDGAR_bGetFRM(FRM_FRM_CFMHEATSENO2DSDFTRES);
   if (  (bLocalFRM_bCfmHeatSenO2DsDftRes != 0)
      || (  (HeatSenO2_bAcvEuro6DsHeat_C == 0)
         || (HeatSenO2_bDgoORng_DsHeat == 0)))
   {
      u16LocalHeatSenO2_DsMes_Obd6Mod = HeatSenO2_DsFacMesRaw;
      u16LocalHeatSenO2_DsMax_Obd6Mod = HeatSenO2_DsFacMaxRaw;
      VEMS_vidSET(HeatSenO2_DsFacMes_Obd6Mod, u16LocalHeatSenO2_DsMes_Obd6Mod);
      VEMS_vidSET(HeatSenO2_DsFacMax_Obd6Mod, u16LocalHeatSenO2_DsMax_Obd6Mod);
   }
}
/*------------------------------- end of file --------------------------------*/