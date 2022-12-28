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
/* !File            : HEATSENO2HOTDIAG_FCT1.C                                 */
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
/*   1 / HEATSENO2HOTDIAG_vidInitOutput                                       */
/*   2 / HEATSENO2HOTDIAG_vidTgInitCbMdTn                                     */
/*   3 / HEATSENO2HOTDIAG_vidInitCbModTrn                                     */
/*   4 / HEATSENO2HOTDIAG_vidInit                                             */
/*   5 / HEATSENO2HOTDIAG_vidUsheat                                           */
/*   6 / HEATSENO2HOTDIAG_vidUsHDiagCond                                      */
/*   7 / HEATSENO2HOTDIAG_vidUsHDiagCalc                                      */
/*   8 / HEATSENO2HOTDIAG_vidDsheat                                           */
/*   9 / HEATSENO2HOTDIAG_vidDsHDiagCond                                      */
/*   10 / HEATSENO2HOTDIAG_vidDsHDiagCalc                                     */
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
#include "MATHSRV.h"
#include "HEATSENO2HOTDIAG.h"
#include "HEATSENO2HOTDIAG_L.h"
#include "HEATSENO2HOTDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2HOTDIAG_vidInitOutput                             */
/* !Description :  Initialization of module outputs                           */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 HEATSENO2HOTDIAG_u8ExtStSsGasPrv;                            */
/*  output uint16 HeatSenO2_UsFacMes_Obd6Mod;                                 */
/*  output uint16 HeatSenO2_UsFacMax_Obd6Mod;                                 */
/*  output uint16 HeatSenO2_DsFacMes_Obd6Mod;                                 */
/*  output uint16 HeatSenO2_DsFacMax_Obd6Mod;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2HOTDIAG_vidInitOutput(void)
{
   HEATSENO2HOTDIAG_u8ExtStSsGasPrv = 0;
   VEMS_vidSET(HeatSenO2_UsFacMes_Obd6Mod, 0);
   VEMS_vidSET(HeatSenO2_UsFacMax_Obd6Mod, 0);
   VEMS_vidSET(HeatSenO2_DsFacMes_Obd6Mod, 0);
   VEMS_vidSET(HeatSenO2_DsFacMax_Obd6Mod, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2HOTDIAG_vidTgInitCbMdTn                           */
/* !Description :  Cette fonction permet la réinitialisation du diagnostic    */
/*                 lors des transitions essence ver gaz, ou gaz vers essence  */
/*                 (lorsque l’application gaz est applicable)                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2HOTDIAG_vidInitCbModTrn();                      */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint8 HEATSENO2HOTDIAG_u8ExtStSsGasPrv;                             */
/*  output uint8 HEATSENO2HOTDIAG_u8ExtStSsGasPrv;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2HOTDIAG_vidTgInitCbMdTn(void)
{
   uint8 u8LocalExt_stSysGas;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (  (  (u8LocalExt_stSysGas == Ext_stTranGslGas_SC)
         && (HEATSENO2HOTDIAG_u8ExtStSsGasPrv == Ext_stGslMod_SC))
      || (  (u8LocalExt_stSysGas == Ext_stTranGasGsl_SC)
         && (HEATSENO2HOTDIAG_u8ExtStSsGasPrv == Ext_stGasMod_SC)))
   {
      HEATSENO2HOTDIAG_vidInitCbModTrn();
   }
   HEATSENO2HOTDIAG_u8ExtStSsGasPrv = u8LocalExt_stSysGas;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2HOTDIAG_vidInitCbModTrn                           */
/* !Description :  Initialisation du diagnostic lors des transitions essence  */
/*                 vers gaz, ou gaz vers essence                              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 HeatSenO2_UsFacMesRaw;                                      */
/*  output uint16 HeatSenO2_UsFacMaxRaw;                                      */
/*  output uint16 HeatSenO2_DsFacMaxRaw;                                      */
/*  output uint16 HeatSenO2_DsFacMesRaw;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2HOTDIAG_vidInitCbModTrn(void)
{
   HeatSenO2_UsFacMesRaw = 0;
   HeatSenO2_UsFacMaxRaw = 0;
   HeatSenO2_DsFacMaxRaw = 0;
   HeatSenO2_DsFacMesRaw = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2HOTDIAG_vidInit                                   */
/* !Description :  Initialization of module outputs                           */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 HeatSenO2_UsFacMaxRaw;                                      */
/*  output uint16 HeatSenO2_UsFacMesRaw;                                      */
/*  output uint16 HeatSenO2_DsFacMaxRaw;                                      */
/*  output uint16 HeatSenO2_DsFacMesRaw;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2HOTDIAG_vidInit(void)
{
   HeatSenO2_UsFacMaxRaw = 0;
   HeatSenO2_UsFacMesRaw = 0;
   HeatSenO2_DsFacMaxRaw = 0;
   HeatSenO2_DsFacMesRaw = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2HOTDIAG_vidUsheat                                 */
/* !Description :  Appel des fonctions HEATSENO2HOTDIAG_vidUsHDiagCond et     */
/*                 HEATSENO2HOTDIAG_vidUsHDiagCalc                            */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2HOTDIAG_vidUsHDiagCond();                       */
/*  extf argret void HEATSENO2HOTDIAG_vidUsHDiagCalc();                       */
/*  input boolean Autorise_diag_us_heat;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2HOTDIAG_vidUsheat(void)
{
   HEATSENO2HOTDIAG_vidUsHDiagCond();
   if (Autorise_diag_us_heat != 0)
   {
      HEATSENO2HOTDIAG_vidUsHDiagCalc();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2HOTDIAG_vidUsHDiagCond                            */
/* !Description :  Le diagnostique ne se lance qu’a la fin d’une temporisation*/
/*                 Us_heat_transit_count après le passage de OFF à ON de la   */
/*                 commande de chauffage de la sonde amont.                   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_00470_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input boolean Chauf_o2_amont_demande_on;                                  */
/*  input boolean Ext_bPresGaz;                                               */
/*  input uint16 Us_heat_transit_count;                                       */
/*  input uint16 Us_heat_transit_delay_c;                                     */
/*  input uint32 HeatSenO2_tiInhUsDiag;                                       */
/*  input uint32 HeatSenO2_tiInhUsDiag_C;                                     */
/*  output uint16 Us_heat_transit_count;                                      */
/*  output uint32 HeatSenO2_tiInhUsDiag;                                      */
/*  output boolean HeatSenO2_bMonRunORng_UsHeat;                              */
/*  output boolean Autorise_diag_us_heat;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2HOTDIAG_vidUsHDiagCond(void)
{
   boolean  bLocalChauf_o2_amont_demande_on;
   boolean  bLocalExt_bPresGaz;
   boolean  bLocalInhUsHeat;
   boolean  bLocalCond;
   uint8    u8LocalExt_stSysGas;
   uint32   u32LocalCounter;
   sint32   s32LocalCounter;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   VEMS_vidGET(Chauf_o2_amont_demande_on, bLocalChauf_o2_amont_demande_on);
   VEMS_vidGET(Ext_bPresGaz, bLocalExt_bPresGaz);
   bLocalInhUsHeat = GDGAR_bGetFRM(FRM_FRM_INHUSHEAT);

   if (bLocalChauf_o2_amont_demande_on != 0)
   {
      s32LocalCounter = (sint32)(Us_heat_transit_count - 1);
      Us_heat_transit_count = (uint16)MATHSRV_udtCLAMP(s32LocalCounter, 0, 400);
   }
   else
   {
      Us_heat_transit_count =
         (uint16)MATHSRV_udtMIN(Us_heat_transit_delay_c, 400);
   }

   if (  (u8LocalExt_stSysGas != Ext_stTranGslGas_SC)
      && (u8LocalExt_stSysGas != Ext_stTranGasGsl_SC))
   {
      if (HeatSenO2_tiInhUsDiag > 0)
      {
         u32LocalCounter = HeatSenO2_tiInhUsDiag - 1;
      }
      else
      {
         u32LocalCounter = 0;
      }
      HeatSenO2_tiInhUsDiag = MATHSRV_udtMIN(u32LocalCounter, 200000);
      bLocalCond = 1;
   }
   else
   {
      HeatSenO2_tiInhUsDiag = MATHSRV_udtMIN(HeatSenO2_tiInhUsDiag_C, 200000);
      bLocalCond = 0;
   }

   if (  (bLocalInhUsHeat == 0)
      && (bLocalChauf_o2_amont_demande_on != 0)
      && (Us_heat_transit_count == 0)
      && ( (bLocalExt_bPresGaz == 0)
         || (  (bLocalCond != 0)
            && (HeatSenO2_tiInhUsDiag == 0))))
   {
      HeatSenO2_bMonRunORng_UsHeat = 1;
      Autorise_diag_us_heat = 1;
   }
   else
   {
      HeatSenO2_bMonRunORng_UsHeat = 0;
      Autorise_diag_us_heat = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2HOTDIAG_vidUsHDiagCalc                            */
/* !Description :  La valeur donnée par Rchauff_SO2Us est la résistance de    */
/*                 chauffage de la sonde amont. Enfin  on   compare           */
/*                 Rchauff_SO2Us à un seuil qui dépend de la température des  */
/*                 gazes d’échappement.                                       */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Rchauff_SO2Us;                                               */
/*  input uint16 Exhaust_gas_temp_real;                                       */
/*  input uint16 Exhaust_gas_temp_bkpt_map[10];                               */
/*  input uint16 Us_heat_seuil_ex_gas_temp_g_map[10];                         */
/*  input uint16 Us_heat_seuil_ex_gas_temp_map[10];                           */
/*  output uint16 HeatSenO2_UsFacMesRaw;                                      */
/*  output uint16 HeatSenO2_UsFacMaxRaw;                                      */
/*  output boolean HeatSenO2_bDgoORng_UsHeat;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2HOTDIAG_vidUsHDiagCalc(void)
{
   uint8  u8LocalExt_stSysGas;
   uint16 u16LocalRchauff_SO2Us;
   uint16 u16LocalHeatThreshExGasTInterp;
   uint16 u16LocalExhaustGasTempPara;
   uint16 u16LocalExhaust_gas_temp_real;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   VEMS_vidGET(Rchauff_SO2Us, u16LocalRchauff_SO2Us);
   VEMS_vidGET(Exhaust_gas_temp_real, u16LocalExhaust_gas_temp_real);

   HeatSenO2_UsFacMesRaw = u16LocalRchauff_SO2Us;

   u16LocalExhaust_gas_temp_real = (uint16)(u16LocalExhaust_gas_temp_real / 32);
   u16LocalExhaustGasTempPara =
      MATHSRV_u16CalcParaIncAryU16(Exhaust_gas_temp_bkpt_map,
                                   u16LocalExhaust_gas_temp_real,
                                   10);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u16LocalHeatThreshExGasTInterp =
         MATHSRV_u16Interp1d(Us_heat_seuil_ex_gas_temp_g_map,
                             u16LocalExhaustGasTempPara);
   }
   else
   {
      u16LocalHeatThreshExGasTInterp =
         MATHSRV_u16Interp1d(Us_heat_seuil_ex_gas_temp_map,
                             u16LocalExhaustGasTempPara);
   }

   HeatSenO2_UsFacMaxRaw = u16LocalHeatThreshExGasTInterp;

   if (u16LocalRchauff_SO2Us > u16LocalHeatThreshExGasTInterp)
   {
      HeatSenO2_bDgoORng_UsHeat = 1;
   }
   else
   {
      HeatSenO2_bDgoORng_UsHeat = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2HOTDIAG_vidDsheat                                 */
/* !Description :  Appel des fonctions HEATSENO2HOTDIAG_vidDsHDiagCond et     */
/*                 HEATSENO2HOTDIAG_vidDsHDiagCalc                            */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2HOTDIAG_vidDsHDiagCond();                       */
/*  extf argret void HEATSENO2HOTDIAG_vidDsHDiagCalc();                       */
/*  input boolean Autorise_diag_ds_heat;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2HOTDIAG_vidDsheat(void)
{
   HEATSENO2HOTDIAG_vidDsHDiagCond();
   if (Autorise_diag_ds_heat != 0)
   {
      HEATSENO2HOTDIAG_vidDsHDiagCalc();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2HOTDIAG_vidDsHDiagCond                            */
/* !Description :  Le diagnostique ne se lance qu’a la fin d’une temporisation*/
/*                 Ds_heat_transit_count après le passage de OFF à ON de la   */
/*                 commande de chauffage de la sonde aval.                    */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input boolean Chauf_o2_aval_demande_on;                                   */
/*  input boolean Ext_bPresGaz;                                               */
/*  input uint16 Ds_heat_transit_count;                                       */
/*  input uint16 Ds_heat_transit_delay_c;                                     */
/*  input uint32 HeatSenO2_tiInhDsDiag;                                       */
/*  input uint32 HeatSenO2_tiInhDsDiag_C;                                     */
/*  output uint16 Ds_heat_transit_count;                                      */
/*  output uint32 HeatSenO2_tiInhDsDiag;                                      */
/*  output boolean HeatSenO2_bMonRunORng_DsHeat;                              */
/*  output boolean Autorise_diag_ds_heat;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2HOTDIAG_vidDsHDiagCond(void)
{
   boolean  bLocalChauf_o2_aval_demande_on;
   boolean  bLocalExt_bPresGaz;
   boolean  bLocalInhDsHeat;
   boolean  bLocalCond;
   uint8    u8LocalExt_stSysGas;
   uint32   u32LocalCounter;
   sint32   s32LocalCounter;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   VEMS_vidGET(Chauf_o2_aval_demande_on, bLocalChauf_o2_aval_demande_on);
   VEMS_vidGET(Ext_bPresGaz, bLocalExt_bPresGaz);
   bLocalInhDsHeat = GDGAR_bGetFRM(FRM_FRM_INHDSHEAT);

   if (bLocalChauf_o2_aval_demande_on != 0)
   {
      s32LocalCounter = (sint32)(Ds_heat_transit_count - 1);
      Ds_heat_transit_count = (uint16)MATHSRV_udtCLAMP(s32LocalCounter, 0, 400);
   }
   else
   {
      Ds_heat_transit_count =
         (uint16)MATHSRV_udtMIN(Ds_heat_transit_delay_c, 400);
   }

   if (  (u8LocalExt_stSysGas != Ext_stTranGslGas_SC)
      && (u8LocalExt_stSysGas != Ext_stTranGasGsl_SC))
   {
      if (HeatSenO2_tiInhDsDiag > 0)
      {
         u32LocalCounter = HeatSenO2_tiInhDsDiag - 1;
      }
      else
      {
         u32LocalCounter = HeatSenO2_tiInhDsDiag;
      }
      HeatSenO2_tiInhDsDiag = MATHSRV_udtMIN(u32LocalCounter, 200000);
      bLocalCond = 1;
   }
   else
   {
      HeatSenO2_tiInhDsDiag = MATHSRV_udtMIN(HeatSenO2_tiInhDsDiag_C, 200000);
      bLocalCond = 0;
   }

   if (  (bLocalInhDsHeat == 0)
      && (bLocalChauf_o2_aval_demande_on != 0)
      && (Ds_heat_transit_count == 0)
      && ( (bLocalExt_bPresGaz == 0)
         || (  (bLocalCond != 0)
            && (HeatSenO2_tiInhDsDiag == 0))))
   {
      HeatSenO2_bMonRunORng_DsHeat = 1;
      Autorise_diag_ds_heat = 1;
   }
   else
   {
      HeatSenO2_bMonRunORng_DsHeat = 0;
      Autorise_diag_ds_heat = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2HOTDIAG_vidDsHDiagCalc                            */
/* !Description :  La valeur donnée par Rchauff_SO2Ds est la résistance de    */
/*                 chauffage de la sonde aval. Enfin on compare Rchauff_SO2Ds */
/*                 à un seuil qui dépend de la température du catalyseur.     */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Rchauff_SO2Ds;                                               */
/*  input sint16 Ext_tOxCEstim;                                               */
/*  input uint16 Cata_temp_bkpt_map[10];                                      */
/*  input uint16 Ds_heat_seuil_cata_temp_g_map[10];                           */
/*  input uint16 Ds_heat_seuil_cata_temp_map[10];                             */
/*  output uint16 HeatSenO2_DsFacMesRaw;                                      */
/*  output uint16 HeatSenO2_DsFacMaxRaw;                                      */
/*  output boolean HeatSenO2_bDgoORng_DsHeat;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2HOTDIAG_vidDsHDiagCalc(void)
{
   uint8  u8LocalExt_stSysGas;
   uint16 u16LocalRchauff_SO2Ds;
   uint16 u16LocalHtThreshCataTempInterp;
   uint16 u16LocalCataTempPara;
   uint16 u16LocalExt_tOxCEstim;
   sint16 s16LocalExt_tOxCEstim;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   VEMS_vidGET(Rchauff_SO2Ds, u16LocalRchauff_SO2Ds);
   VEMS_vidGET(Ext_tOxCEstim, s16LocalExt_tOxCEstim);
   HeatSenO2_DsFacMesRaw = u16LocalRchauff_SO2Ds;

   u16LocalExt_tOxCEstim = (uint16)MATHSRV_udtMAX(s16LocalExt_tOxCEstim, 0);

   u16LocalCataTempPara =
      MATHSRV_u16CalcParaIncAryU16(Cata_temp_bkpt_map,
                                   u16LocalExt_tOxCEstim,
                                   10);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u16LocalHtThreshCataTempInterp =
         MATHSRV_u16Interp1d(Ds_heat_seuil_cata_temp_g_map,
                             u16LocalCataTempPara);
   }
   else
   {
      u16LocalHtThreshCataTempInterp =
         MATHSRV_u16Interp1d(Ds_heat_seuil_cata_temp_map,
                             u16LocalCataTempPara);
   }

   HeatSenO2_DsFacMaxRaw = u16LocalHtThreshCataTempInterp;

   if (u16LocalRchauff_SO2Ds > u16LocalHtThreshCataTempInterp)
   {
      HeatSenO2_bDgoORng_DsHeat = 1;
   }
   else
   {
      HeatSenO2_bDgoORng_DsHeat = 0;
   }
}
/*------------------------------- end of file --------------------------------*/