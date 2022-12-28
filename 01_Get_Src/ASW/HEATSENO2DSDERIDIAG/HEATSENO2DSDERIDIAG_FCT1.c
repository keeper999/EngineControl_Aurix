/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2DSDERIDIAG                                     */
/* !Description     : HEATSENO2DSDERIDIAG component.                          */
/*                                                                            */
/* !Module          : HEATSENO2DSDERIDIAG                                     */
/* !Description     : DIAGNOSTIC DERIVEE TENSION SONDE A OXYGENE AVAL.        */
/*                                                                            */
/* !File            : HEATSENO2DSDERIDIAG_FCT1.C                              */
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
/*   1 / HEATSENO2DSDERIDIAG_vidIniOutput                                     */
/*   2 / HEATSENO2DSDERIDIAG_vidInitTran                                      */
/*   3 / HEATSENO2DSDERIDIAG_vidGslGas                                        */
/*   4 / HEATSENO2DSDERIDIAG_vidGasGsl                                        */
/*   5 / HEATSENO2DSDERIDIAG_vidTrkInit                                       */
/*   6 / HEATSENO2DSDERIDIAG_vidTrkCond                                       */
/*   7 / HEATSENO2DSDERIDIAG_vidTrkMgr                                        */
/*   8 / HEATSENO2DSDERIDIAG_vidTrkDiag                                       */
/*   9 / HEATSENO2DSDERIDIAG_vidCalcAvg                                       */
/*   10 / HEATSENO2DSDERIDIAG_vidAvgPnd                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5012852 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHI_SENO2DS/HEATSENO2DSDERIDIA$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   18 Jan 2013 $*/
/* $Author::   etsasson                               $$Date::   18 Jan 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "HEATSENO2DSDERIDIAG.h"
#include "HEATSENO2DSDERIDIAG_L.h"
#include "HEATSENO2DSDERIDIAG_IM.h"
#include "GDGAR.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidIniOutput                           */
/* !Description :  Fonction d'initialisation                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input bool LDSD_TRK_DIAG_DISABLE;                                         */
/*  output uint16 Ldsd_trk_ewma_failure;                                      */
/*  output uint16 Ldsd_trk_ewma_no_fail;                                      */
/*  output boolean SenO2Ds_bAcvSeqMemSigGrdDiag;                              */
/*  output boolean SenO2Ds_bAcvSeqSigGrdDiag;                                 */
/*  output uint16 SenO2Ds_SigGrdFacMes_Obd6Mod;                               */
/*  output uint16 SenO2Ds_SigGrdFacMin_Obd6Mod;                               */
/*  output uint16 Ldsd_trk_ewma_eep;                                          */
/*  output uint16 Ldsd_trk_tension_s_av_prec;                                 */
/*  output uint8 HEATSENO2DSDERIDIAG_u8DiagStPrev;                            */
/*  output uint8 HEATSENO2DSDERIDIAG_u8StGasPrev;                             */
/*  output boolean HEATSENO2DSDERIDIAG_bCondEnaPrev;                          */
/*  output st68 Ldsd_trk_diag_state;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidIniOutput(void)
{
   uint16 u16LocalTension_sonde_aval;


   VEMS_vidSET(Ldsd_trk_ewma_failure, 0);
   VEMS_vidSET(Ldsd_trk_ewma_no_fail, 0);
   VEMS_vidSET(SenO2Ds_bAcvSeqMemSigGrdDiag, 0);
   VEMS_vidSET(SenO2Ds_bAcvSeqSigGrdDiag, 0);
   VEMS_vidGET(Tension_sonde_aval, u16LocalTension_sonde_aval);
   VEMS_vidSET(SenO2Ds_SigGrdFacMes_Obd6Mod, 0);
   VEMS_vidSET(SenO2Ds_SigGrdFacMin_Obd6Mod, 0);
   VEMS_vidSET(Ldsd_trk_ewma_eep, 0);
   Ldsd_trk_tension_s_av_prec = u16LocalTension_sonde_aval;
   HEATSENO2DSDERIDIAG_u8DiagStPrev = LDSD_TRK_DIAG_DISABLE;
   HEATSENO2DSDERIDIAG_u8StGasPrev = Ext_stGasMod_SC;
   HEATSENO2DSDERIDIAG_bCondEnaPrev = 0;
   /* State machine initialization */
   Ldsd_trk_diag_state = LDSD_TRK_DIAG_DISABLE;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidInitTran                            */
/* !Description :  Ce bloc permet la réinitialisation du diagnostic lors des  */
/*                 transitions essence ver gaz, ou gaz vers essence lorsque   */
/*                 l’application gaz est applicable.                          */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2DSDERIDIAG_vidGslGas();                         */
/*  extf argret void HEATSENO2DSDERIDIAG_vidGasGsl();                         */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint8 HEATSENO2DSDERIDIAG_u8StGasPrev;                              */
/*  output uint8 HEATSENO2DSDERIDIAG_u8StGasPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidInitTran(void)
{
   uint8 u8LocalExt_stSysGas;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (  (u8LocalExt_stSysGas == Ext_stTranGslGas_SC)
      && (HEATSENO2DSDERIDIAG_u8StGasPrev == Ext_stGslMod_SC))
   {
      HEATSENO2DSDERIDIAG_vidGslGas();
   }
   if (  (u8LocalExt_stSysGas == Ext_stTranGasGsl_SC)
      && (HEATSENO2DSDERIDIAG_u8StGasPrev == Ext_stGasMod_SC))
   {
      HEATSENO2DSDERIDIAG_vidGasGsl();
   }
   HEATSENO2DSDERIDIAG_u8StGasPrev = u8LocalExt_stSysGas;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidGslGas                              */
/* !Description :  La valeur de la moyenne des pente enregistrée en EEPROM    */
/*                 Ldsd_trk_ewma_eep est initialisée à sa valeur maximum 5000 */
/*                 (FFFF en Hexadécimal) afin de différencier le premier cycle*/
/*                 de roulage.                                                */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ldsd_trk_ewma_eep;                                           */
/*  output uint8 Ldsd_trk_iteration;                                          */
/*  output uint8 Ldsd_trk_sonde_ok;                                           */
/*  output uint16 Ldsd_trk_ewma_first_diag;                                   */
/*  output boolean Ldsd_trk_first_diag;                                       */
/*  output uint16 Ldsd_trk_ewma_essence_eep;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidGslGas(void)
{
   uint16 u16LocalLdsd_trk_ewma_eep;


   Ldsd_trk_iteration = 0;
   Ldsd_trk_sonde_ok = 0;
   Ldsd_trk_ewma_first_diag = 65535;
   VEMS_vidGET(Ldsd_trk_ewma_eep, u16LocalLdsd_trk_ewma_eep);
   if (u16LocalLdsd_trk_ewma_eep == 65535)
   {
      Ldsd_trk_first_diag = 1;
   }
   else
   {
      Ldsd_trk_first_diag = 0;
   }
   Ldsd_trk_ewma_essence_eep = u16LocalLdsd_trk_ewma_eep;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidGasGsl                              */
/* !Description :  La valeur de la moyenne des pente enregistrée en EEPROM    */
/*                 Ldsd_trk_ewma_eep est initialisée à sa valeur maximum 5000 */
/*                 (FFFF en Hexadécimal) afin de différencier le premier cycle*/
/*                 de roulage.                                                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ldsd_trk_ewma_eep;                                           */
/*  output uint8 Ldsd_trk_iteration;                                          */
/*  output uint8 Ldsd_trk_sonde_ok;                                           */
/*  output uint16 Ldsd_trk_ewma_first_diag;                                   */
/*  output boolean Ldsd_trk_first_diag;                                       */
/*  output uint16 Ldsd_trk_ewma_gaz_eep;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidGasGsl(void)
{
   uint16 u16LocalLdsd_trk_ewma_eep;


   Ldsd_trk_iteration = 0;
   Ldsd_trk_sonde_ok = 0;
   Ldsd_trk_ewma_first_diag = 65535;
   VEMS_vidGET(Ldsd_trk_ewma_eep, u16LocalLdsd_trk_ewma_eep);
   if (u16LocalLdsd_trk_ewma_eep == 65535)
   {
      Ldsd_trk_first_diag = 1;
   }
   else
   {
      Ldsd_trk_first_diag = 0;
   }
   Ldsd_trk_ewma_gaz_eep = u16LocalLdsd_trk_ewma_eep;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidTrkInit                             */
/* !Description :  La valeur de la moyenne des pente enregistrée en EEPROM    */
/*                 Ldsd_trk_ewma_eep est initialisée à sa valeur maximum 5000 */
/*                 afin de différencier le premier cycle de roulage.          */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 Ldsd_trk_iteration;                                          */
/*  output uint8 Ldsd_trk_sonde_ok;                                           */
/*  output uint16 Ldsd_trk_ewma_first_diag;                                   */
/*  output boolean Ldsd_trk_init_fait;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidTrkInit(void)
{
   Ldsd_trk_iteration = 0;
   Ldsd_trk_sonde_ok = 0;
   Ldsd_trk_ewma_first_diag = 65535;
   Ldsd_trk_init_fait = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidTrkCond                             */
/* !Description :  Ce bloc regroupe les conditions d’activation à vérifier    */
/*                 pour valider le démarrage de la fonction diagnostic        */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_11_07985_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input st23 Vehicle_active_state;                                          */
/*  input st07 Engine_running_state;                                          */
/*  input boolean LsSys_bLsDsMainOxCHeatOkdiag;                               */
/*  input uint16 Cat_temperature;                                             */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input boolean Ext_bPresGaz;                                               */
/*  input boolean VlvAct_bInhDiagPresScav;                                    */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint16 SenO2Ds_tiInhSigGrdDiag;                                     */
/*  input uint16 SenO2Ds_tiInhSigGrdDiag_C;                                   */
/*  input boolean Ldsd_trk_cond_enable;                                       */
/*  input uint16 Ldsd_trk_min_temp_cata_gas;                                  */
/*  input uint16 Ldsd_trk_min_temp_cata;                                      */
/*  input boolean Manu_inh_ldsd_trk_diag_so2_av;                              */
/*  input boolean SenO2Ds_bInhSigGrdDiagPresScav_C;                           */
/*  output uint16 SenO2Ds_tiInhSigGrdDiag;                                    */
/*  output boolean HEATSENO2DSDERIDIAG_bCondEnaPrev;                          */
/*  output boolean Ldsd_trk_cond_enable;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidTrkCond(void)
{
   boolean bLocalInhSigGrdDiag;
   boolean bLocalLsSys_bLsDsMainOxCHtOkdiag;
   boolean bLocalVlvAct_bInhDiagPresScav;
   boolean bLocalExt_bPresGaz;
   boolean bLocalCond;
   uint8   u8LocalVehicle_active_state;
   uint8   u8LocalEngine_running_state;
   uint8   u8LocalExt_stSysGas;
   uint8   u8LocalCoPTSt_stEng;
   uint16  u16LocalCat_temperature;
   sint32  s32LocalCounter;


   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   VEMS_vidGET(LsSys_bLsDsMainOxCHeatOkdiag,
               bLocalLsSys_bLsDsMainOxCHtOkdiag);
   VEMS_vidGET(Cat_temperature, u16LocalCat_temperature);
   bLocalInhSigGrdDiag = GDGAR_bGetFRM(FRM_FRM_INHSIGGRDDIAG);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   VEMS_vidGET(Ext_bPresGaz, bLocalExt_bPresGaz);
   VEMS_vidGET(VlvAct_bInhDiagPresScav, bLocalVlvAct_bInhDiagPresScav);
   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);

   if (  (u8LocalExt_stSysGas != Ext_stTranGslGas_SC)
      && (u8LocalExt_stSysGas != Ext_stTranGasGsl_SC))
   {
      s32LocalCounter = (sint32)(SenO2Ds_tiInhSigGrdDiag - 1);
      SenO2Ds_tiInhSigGrdDiag =
         (uint16)MATHSRV_udtCLAMP(s32LocalCounter, 0, 50000);
      bLocalCond = 1;
   }
   else
   {
      SenO2Ds_tiInhSigGrdDiag =
         (uint16)MATHSRV_udtMIN(SenO2Ds_tiInhSigGrdDiag_C, 50000);
      bLocalCond = 0;
   }
   HEATSENO2DSDERIDIAG_bCondEnaPrev = Ldsd_trk_cond_enable;
   if (  (u8LocalVehicle_active_state == VS_RUNNING)
      && (u8LocalEngine_running_state == ERUN_ENGINE_OVERRUN_FCO)
      && (bLocalLsSys_bLsDsMainOxCHtOkdiag != 0)
      && (  (  (u8LocalExt_stSysGas == Ext_stGasMod_SC)
            && (u16LocalCat_temperature >= Ldsd_trk_min_temp_cata_gas))
         || (  (u8LocalExt_stSysGas != Ext_stGasMod_SC)
            && (u16LocalCat_temperature >= Ldsd_trk_min_temp_cata)))
      && (Manu_inh_ldsd_trk_diag_so2_av == 0)
      && (bLocalInhSigGrdDiag == 0)
      && (  (bLocalExt_bPresGaz == 0)
         || (  (bLocalCond != 0)
            && (SenO2Ds_tiInhSigGrdDiag == 0)))
      && (  (SenO2Ds_bInhSigGrdDiagPresScav_C != 0)
         || (bLocalVlvAct_bInhDiagPresScav == 0))
      && (u8LocalCoPTSt_stEng != Coupe_cale))
   {
      Ldsd_trk_cond_enable = 1;
   }
   else
   {
      Ldsd_trk_cond_enable = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidTrkMgr                              */
/* !Description :  Ce bloc mesure les paramètres nécessaires au calcul de la  */
/*                 dérivée de la décroissance de la tension sonde aval        */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_11_07985_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Ldsd_trk_diag_thresh_voltage_gas;                            */
/*  input uint16 Ldsd_trk_max_voltage_gas;                                    */
/*  input uint16 Ldsd_trk_min_voltage_gas;                                    */
/*  input uint16 Ldsd_trk_diag_thresh_voltage;                                */
/*  input uint16 Ldsd_trk_max_voltage;                                        */
/*  input uint16 Ldsd_trk_min_voltage;                                        */
/*  input st68 Ldsd_trk_diag_state;                                           */
/*  input boolean Ldsd_trk_cond_enable;                                       */
/*  input uint16 Ldsd_trk_diag_thd_voltage_temp;                              */
/*  input bool LDSD_TRK_DIAG_DISABLE;                                         */
/*  input uint16 Ldsd_trk_max_voltage_temp;                                   */
/*  input uint16 Ldsd_trk_tension_s_av_prec;                                  */
/*  input uint16 Ldsd_trk_diag_count;                                         */
/*  input uint16 Ldsd_trk_min_voltage_temp;                                   */
/*  input uint16 Ldsd_trk_diag_count_delta_high;                              */
/*  input uint16 Ldsd_trk_diag_count_delta_low;                               */
/*  input uint16 EngM_mfTotExCor;                                             */
/*  input uint16 Ldsd_trk_high_voltage;                                       */
/*  input uint16 Ldsd_trk_low_voltage;                                        */
/*  output uint16 Ldsd_trk_diag_thd_voltage_temp;                             */
/*  output uint16 Ldsd_trk_max_voltage_temp;                                  */
/*  output uint16 Ldsd_trk_min_voltage_temp;                                  */
/*  output uint16 Ldsd_trk_diag_count;                                        */
/*  output st68 Ldsd_trk_diag_state;                                          */
/*  output uint16 Ldsd_trk_high_voltage;                                      */
/*  output uint16 Ldsd_trk_diag_count_delta_high;                             */
/*  output uint16 Ldsd_trk_low_voltage;                                       */
/*  output uint16 Ldsd_trk_diag_count_delta_low;                              */
/*  output uint16 Ldsd_trk_pumped_gas_mfr;                                    */
/*  output uint16 Ldsd_trk_tension_s_av_prec;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidTrkMgr(void)
{
   uint8  u8LocalExt_stSysGas;
   uint16 u16LocalEngM_mfTotExCor;
   uint16 u16LocalTension_sonde_aval;
   sint32 s32LocalLdsd_trk_diag_count;
   sint32 s32LocalTension_sonde_aval;
   uint32 u32LocalLdsdTrkDiagCount;


   VEMS_vidGET(Tension_sonde_aval, u16LocalTension_sonde_aval);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      Ldsd_trk_diag_thd_voltage_temp =
         (uint16)MATHSRV_udtMIN(Ldsd_trk_diag_thresh_voltage_gas, 1024);
      Ldsd_trk_max_voltage_temp =
         (uint16)MATHSRV_udtMIN(Ldsd_trk_max_voltage_gas, 1024);
      Ldsd_trk_min_voltage_temp =
         (uint16)MATHSRV_udtMIN(Ldsd_trk_min_voltage_gas, 1024);
   }
   else
   {
      Ldsd_trk_diag_thd_voltage_temp =
         (uint16)MATHSRV_udtMIN(Ldsd_trk_diag_thresh_voltage, 1024);
      Ldsd_trk_max_voltage_temp =
         (uint16)MATHSRV_udtMIN(Ldsd_trk_max_voltage, 1024);
      Ldsd_trk_min_voltage_temp =
         (uint16)MATHSRV_udtMIN(Ldsd_trk_min_voltage, 1024);
   }

   switch(Ldsd_trk_diag_state)
   {
      case LDSD_TRK_DIAG_DISABLE:
         if (  (Ldsd_trk_cond_enable != 0)
            && (u16LocalTension_sonde_aval > Ldsd_trk_diag_thd_voltage_temp))
         {
            Ldsd_trk_diag_count = 0;
            Ldsd_trk_diag_state = LDSD_TRK_DIAG_INIT;
         }
         break;

      case LDSD_TRK_DIAG_INIT:
         if (Ldsd_trk_cond_enable == 0)
         {
            Ldsd_trk_diag_state = LDSD_TRK_DIAG_DISABLE;
         }
         else
         {
            if (u16LocalTension_sonde_aval < Ldsd_trk_max_voltage_temp)
            {
               Ldsd_trk_high_voltage = Ldsd_trk_max_voltage_temp;
               Ldsd_trk_diag_state = LDSD_TRK_DIAG_THRESH_MAX;
               s32LocalTension_sonde_aval =
                  (sint32)( Ldsd_trk_tension_s_av_prec
                          - u16LocalTension_sonde_aval);
               if (s32LocalTension_sonde_aval == 0)
               {
                  Ldsd_trk_diag_count_delta_high = 65535;
               }
               else
               {
                  if (s32LocalTension_sonde_aval < 0)
                  {
                     Ldsd_trk_diag_count_delta_high = 0;
                  }
                  else
                  {
                     Ldsd_trk_diag_count_delta_high =
                        (uint16)( SenO2Ds_SampleTiFast_SC
                                * (  Ldsd_trk_max_voltage_temp
                                  -  u16LocalTension_sonde_aval)
                                / s32LocalTension_sonde_aval);
                  }
               }

               u32LocalLdsdTrkDiagCount = (uint32)( Ldsd_trk_diag_count
                                                  + SenO2Ds_SampleTiFast_SC);
               Ldsd_trk_diag_count =
                  (uint16)MATHSRV_udtMIN(u32LocalLdsdTrkDiagCount, 65535);
            }
         }
         break;

      case LDSD_TRK_DIAG_THRESH_MAX:
         if (Ldsd_trk_cond_enable == 0)
         {
            Ldsd_trk_diag_state = LDSD_TRK_DIAG_DISABLE;
         }
         else
         {
            if (u16LocalTension_sonde_aval >= Ldsd_trk_tension_s_av_prec)
            {
               Ldsd_trk_diag_state = LDSD_TRK_DIAG_STOP;
            }
            else
            {
               if (u16LocalTension_sonde_aval < Ldsd_trk_min_voltage_temp)
               {
                  Ldsd_trk_low_voltage = Ldsd_trk_min_voltage_temp;

                  Ldsd_trk_diag_count_delta_low =
                     (uint16)(   ( SenO2Ds_SampleTiFast_SC
                             *   ( Ldsd_trk_min_voltage_temp
                                 - u16LocalTension_sonde_aval))
                             /   ( Ldsd_trk_tension_s_av_prec
                                 - u16LocalTension_sonde_aval));
                  /* !Deviation: Violation of QAC_0584 rule.                  */
                  /* !Reason : Ldsd_trk_tension_s_av_prec is always different */
                  /*  from Tension_sonde_aval so the denominator can't be 0   */
                  s32LocalLdsd_trk_diag_count =
                     (sint32)( Ldsd_trk_diag_count
                             + ( Ldsd_trk_diag_count_delta_high
                               - Ldsd_trk_diag_count_delta_low));
                  Ldsd_trk_diag_count =
                     (uint16)MATHSRV_udtCLAMP(s32LocalLdsd_trk_diag_count,
                                              0,
                                              65535);
                  VEMS_vidGET(EngM_mfTotExCor, u16LocalEngM_mfTotExCor);
                  Ldsd_trk_pumped_gas_mfr = u16LocalEngM_mfTotExCor;
                  Ldsd_trk_diag_state = LDSD_TRK_DIAG_THRESH_MIN;
               }
               else
               {
                  u32LocalLdsdTrkDiagCount = (uint32)( Ldsd_trk_diag_count
                                                     + SenO2Ds_SampleTiFast_SC);
                  Ldsd_trk_diag_count =
                     (uint16)MATHSRV_udtMIN(u32LocalLdsdTrkDiagCount, 65535);
               }
            }
         }
         break;

      case LDSD_TRK_DIAG_STOP:
         if (Ldsd_trk_cond_enable == 0)
         {
            Ldsd_trk_diag_state = LDSD_TRK_DIAG_DISABLE;
         }
         break;

      case LDSD_TRK_DIAG_THRESH_MIN:
         if (Ldsd_trk_cond_enable == 0)
         {
            Ldsd_trk_diag_state = LDSD_TRK_DIAG_DISABLE;
         }
         break;

      default:
         Ldsd_trk_diag_state = LDSD_TRK_DIAG_DISABLE;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   Ldsd_trk_tension_s_av_prec =
      (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_aval, 1024);
   Ldsd_trk_high_voltage =(uint16)MATHSRV_udtMIN(Ldsd_trk_high_voltage, 1024);
   Ldsd_trk_low_voltage = (uint16)MATHSRV_udtMIN(Ldsd_trk_low_voltage, 1024);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidTrkDiag                             */
/* !Description :  Le diagnostic s’active lorsque l’on est dans l’état        */
/*                 LDSD_TRK_DIAG_THRESH_MIN, ce qui correspond à la fin d’une */
/*                 pente, la valeur de la pente sera alors rajoutée à la      */
/*                 moyenne générale et au bout d’un certain nombre de pentes  */
/*                 calculées.                                                 */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2DSDERIDIAG_vidCalcAvg();                        */
/*  input st68 Ldsd_trk_diag_state;                                           */
/*  input uint8 HEATSENO2DSDERIDIAG_u8DiagStPrev;                             */
/*  output uint8 HEATSENO2DSDERIDIAG_u8DiagStPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidTrkDiag(void)
{
   if (  (Ldsd_trk_diag_state == LDSD_TRK_DIAG_THRESH_MIN)
      && (HEATSENO2DSDERIDIAG_u8DiagStPrev != LDSD_TRK_DIAG_THRESH_MIN))
   {
      HEATSENO2DSDERIDIAG_vidCalcAvg();
   }
   HEATSENO2DSDERIDIAG_u8DiagStPrev = Ldsd_trk_diag_state;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidCalcAvg                             */
/* !Description :  Pour chaque mesure réussie de la décroissance de la tension*/
/*                 sonde aval, le bloc de calcul s’active une fois et effectue*/
/*                 le calcul des moyennes et la synthése de diagnostic.       */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2DSDERIDIAG_vidAvgPnd();                         */
/*  extf argret void HEATSENO2DSDERIDIAG_vidAvgEwma();                        */
/*  extf argret void HEATSENO2DSDERIDIAG_vidDiag();                           */
/*  input boolean Ldsd_trk_diag_end;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidCalcAvg(void)
{
   HEATSENO2DSDERIDIAG_vidAvgPnd();
   HEATSENO2DSDERIDIAG_vidAvgEwma();
   if (Ldsd_trk_diag_end != 0)
   {
      HEATSENO2DSDERIDIAG_vidDiag();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidAvgPnd                              */
/* !Description :  Calcul de la moyenne pondérée de la tension sonde aval     */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ldsd_trk_diag_count;                                         */
/*  input uint16 Ldsd_trk_pumped_gas_mfr;                                     */
/*  input uint16 Ldsd_trk_high_voltage;                                       */
/*  input uint16 Ldsd_trk_low_voltage;                                        */
/*  output uint16 Ldsd_trk_voltage_pond;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidAvgPnd(void)
{
   uint16 u16LocalLdsdTrkVoltage;
   uint32 u32LocalVoltagePond;
   uint32 u32LocalMod1;
   uint32 u32LocalMod2;
   uint32 u32LocalRecup1;
   uint32 u32LocalRecup2;
   sint32 s32LocalLdsdTrkVoltage;


   if (  (Ldsd_trk_diag_count == 0)
      || (Ldsd_trk_pumped_gas_mfr == 0))
   {
      Ldsd_trk_voltage_pond = 65535;
   }
   else
   {
      s32LocalLdsdTrkVoltage = (sint32)( Ldsd_trk_high_voltage
                                       - Ldsd_trk_low_voltage);
      if (s32LocalLdsdTrkVoltage < 0)
      {
         Ldsd_trk_voltage_pond = 0;
      }
      else
      {
         u16LocalLdsdTrkVoltage =
            (uint16)MATHSRV_udtMIN(s32LocalLdsdTrkVoltage, 1024);
         if (u16LocalLdsdTrkVoltage <= 10)
         {
            u32LocalVoltagePond = (uint32)u16LocalLdsdTrkVoltage * 419430400;
            u32LocalVoltagePond = u32LocalVoltagePond
                                / (uint32)( Ldsd_trk_diag_count
                                          * Ldsd_trk_diag_count);
            u32LocalVoltagePond = u32LocalVoltagePond
                                / (uint32)Ldsd_trk_pumped_gas_mfr;
         }
         else
         {
            u32LocalVoltagePond = (uint32)419430400
                                / (uint32)Ldsd_trk_pumped_gas_mfr;
            u32LocalMod1 = (uint32)419430400
                         % (uint32)Ldsd_trk_pumped_gas_mfr;
            if (u32LocalVoltagePond < 4194304)
            {
               u32LocalVoltagePond =
                  u32LocalVoltagePond * u16LocalLdsdTrkVoltage;
               u32LocalRecup1 = ( u32LocalMod1 * u16LocalLdsdTrkVoltage)
                              / (uint32)Ldsd_trk_pumped_gas_mfr;
               u32LocalVoltagePond = u32LocalVoltagePond + u32LocalRecup1;
               u32LocalVoltagePond = u32LocalVoltagePond
                                   / (uint32)( Ldsd_trk_diag_count
                                             * Ldsd_trk_diag_count);
            }
            else
            {
               u32LocalVoltagePond = u32LocalVoltagePond
                                   / (uint32)(Ldsd_trk_diag_count);
               u32LocalMod2 = u32LocalVoltagePond
                            % (uint32)(Ldsd_trk_diag_count);
               if (u32LocalVoltagePond < 4194304)
               {
                  u32LocalVoltagePond = u32LocalVoltagePond
                                       * u16LocalLdsdTrkVoltage;
                  u32LocalRecup2 = ( u32LocalMod2
                                   * u16LocalLdsdTrkVoltage)
                                 / (uint32)(Ldsd_trk_diag_count);
                  u32LocalVoltagePond = ( u32LocalVoltagePond
                                        + u32LocalRecup2)
                                      / (uint32)Ldsd_trk_diag_count;
               }
               else
               {
                  u32LocalVoltagePond = 65535;
               }
            }
         }
         Ldsd_trk_voltage_pond = (uint16)MATHSRV_udtMIN(u32LocalVoltagePond,
                                                        65535);
      }
   }
}
/*------------------------------- end of file --------------------------------*/