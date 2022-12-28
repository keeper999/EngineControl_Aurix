/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CSTREFCRED                                              */
/* !Description     : CSTREFCRED component                                    */
/*                                                                            */
/* !Module          : CSTREFCRED                                              */
/* !Description     : DEGRADATION DE RENDEMENT AU RALENTI POUR LA PURGE       */
/*                                                                            */
/* !File            : CSTREFCRED_FCT1.C                                       */
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
/*   1 / CSTREFCRED_vidIni                                                    */
/*   2 / CSTREFCRED_vidTarClcn                                                */
/*   3 / CSTREFCRED_vidEfcRedClcn                                             */
/*   4 / CSTREFCRED_vidInhApplySlewRate                                       */
/*   5 / CSTREFCRED_vidIniIdlReq                                              */
/*   6 / CSTREFCRED_vidClcnIdlReq                                             */
/*   7 / CSTREFCRED_vidClcn                                                   */
/*                                                                            */
/* !Reference   : V02 NT 09 01759 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CSTR/CSTREFCRED/CSTREFCRED_FCT1.C_$*/
/* $Revision::   1.2      $$Author::   hmelloul       $$Date::   26 Aug 2010 $*/
/* $Author::   hmelloul                               $$Date::   26 Aug 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.H"
#include "CSTREFCRED.H"
#include "CSTREFCRED_L.H"
#include "CSTREFCRED_IM.H"
#include "MATHSRV.h"
#include "VEMS.H"
#include "GDGAR.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTREFCRED_vidIni                                          */
/* !Description :  Initialisation des variables produites du module           */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  R.GHORBEL                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 CanPurg_tqCanRes;                                           */
/*  output boolean CanPurg_bTarIdlCanPurg;                                    */
/*  output uint16 Av_dr_ralenti_purge_raw;                                    */
/*  output uint8 CanPurg_facTarIdlCanPurg;                                    */
/*  output uint16 CSTREFCRED_u16FilterSlewRate;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTREFCRED_vidIni(void)
{
   VEMS_vidSET(CanPurg_tqCanRes, 0);
   VEMS_vidSET(CanPurg_bTarIdlCanPurg, 1);
   Av_dr_ralenti_purge_raw = 0;
   VEMS_vidSET(CanPurg_facTarIdlCanPurg, 0);
   CSTREFCRED_u16FilterSlewRate = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTREFCRED_vidTarClcn                                      */
/* !Description :  Fonction de dégradation du rendement par l'avance pour la  */
/*                 purge avant slew rate                                      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  R.GHORBEL                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void CSTREFCRED_vidEfcRedClcn();                              */
/*  input uint8 Coupure_decel_progr_inj;                                      */
/*  input uint16 Cpc_fuel_vapour_concentration;                               */
/*  input uint16 Cpc_fuel_vapour_conc_err;                                    */
/*  input st07 Engine_running_state;                                          */
/*  input uint16 Av_dr_ralenti_purge_sp;                                      */
/*  output uint16 Cpc_fuel_vapour_conc_finale;                                */
/*  output uint8 CanPurg_facTarIdlCanPurg;                                    */
/*  output uint16 Av_dr_ralenti_purge_raw;                                    */
/*  output boolean CanPurg_bTarIdlCanPurg;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTREFCRED_vidTarClcn(void)
{
   boolean  bLocalInhrIgEfcRedCstr;
   boolean  bLocalCanPurg_bTarIdlCanPurg;
   uint8    u8LocalCoupure_decel_progr_inj;
   uint8    u8LocalEngine_running_state;
   uint8    u8LocalCanPurg_facTarIdlCanPurg;
   uint16   u16LocalCpc_fuel_vapour_ctr;
   uint16   u16LocalCpc_fuel_vapour_conc_err;
   uint32   u32LocalDiff;
   uint32   u32LocalProd;


   bLocalInhrIgEfcRedCstr = GDGAR_bGetFRM(FRM_FRM_INH_RIGEFCREDCSTR);
   VEMS_vidGET(Coupure_decel_progr_inj, u8LocalCoupure_decel_progr_inj);
   if (  (bLocalInhrIgEfcRedCstr != 0)
      || ( (u8LocalCoupure_decel_progr_inj & 0x01 )== 0x01)
      || ( (u8LocalCoupure_decel_progr_inj & 0x02 )== 0x02)
      || ( (u8LocalCoupure_decel_progr_inj & 0x04 )== 0x04)
      || ( (u8LocalCoupure_decel_progr_inj & 0x08 )== 0x08))
   {
      bLocalCanPurg_bTarIdlCanPurg = 1;
   }
   else
   {
      bLocalCanPurg_bTarIdlCanPurg = 0;
   }

   VEMS_vidGET(Cpc_fuel_vapour_concentration, u16LocalCpc_fuel_vapour_ctr);
   VEMS_vidGET(Cpc_fuel_vapour_conc_err, u16LocalCpc_fuel_vapour_conc_err);

   u32LocalDiff = (uint32)(65536 - u16LocalCpc_fuel_vapour_conc_err);
   u32LocalProd = u32LocalDiff * (uint32)u16LocalCpc_fuel_vapour_ctr;
   u32LocalProd = u32LocalProd / 65536;
   Cpc_fuel_vapour_conc_finale = (uint16)(u32LocalProd);
   u32LocalProd = u32LocalProd * 100;
   u8LocalCanPurg_facTarIdlCanPurg = (uint8)(u32LocalProd / 65536);

   VEMS_vidSET(CanPurg_facTarIdlCanPurg, u8LocalCanPurg_facTarIdlCanPurg);

   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   if ( (u8LocalEngine_running_state != ERUN_ON_IDLE)
      || (bLocalCanPurg_bTarIdlCanPurg != 0))
   {
      Av_dr_ralenti_purge_raw = 0;
   }
   else
   {
      CSTREFCRED_vidEfcRedClcn();
      Av_dr_ralenti_purge_raw = (uint16)MATHSRV_udtMIN(Av_dr_ralenti_purge_sp,
                                                       1000);
   }
   VEMS_vidSET(CanPurg_bTarIdlCanPurg, bLocalCanPurg_bTarIdlCanPurg);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTREFCRED_vidEfcRedClcn                                   */
/* !Description :  Fonction de production de la consigne de dégradation de    */
/*                 rendement par l'avance pour la purge.                      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  R.GHORBEL                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Cpc_fuel_vapour_conc_finale;                                 */
/*  input uint8 Av_dr_ralenti_purge_bkpt_map[9];                              */
/*  input uint16 Av_dr_ralenti_purge_map[9];                                  */
/*  output uint16 Av_dr_ralenti_purge_sp;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTREFCRED_vidEfcRedClcn(void)
{
   uint8  u8Local;
   uint16 u16LocalPara;
   uint16 u16LocalInter;


   u8Local = (uint8)(Cpc_fuel_vapour_conc_finale / 256);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU8(Av_dr_ralenti_purge_bkpt_map,
                                              u8Local,
                                              9);
   u16LocalInter =
      MATHSRV_u16Interp1d(Av_dr_ralenti_purge_map, u16LocalPara);
   Av_dr_ralenti_purge_sp = (uint16)MATHSRV_udtMIN(u16LocalInter, 1000);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTREFCRED_vidInhApplySlewRate                             */
/* !Description :  Fonction ded égradation du rendement par l'avance pour la  */
/*                 purge.                                                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :   R.GHORBEL                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 CSTREFCRED_u16FilterSlewRate;                                */
/*  input uint16 Av_dr_ralenti_purge_raw;                                     */
/*  input uint16 Av_dr_ralenti_purge_inc_dec;                                 */
/*  input boolean CanPurg_bTarIdlCanPurg;                                     */
/*  output uint16 CSTREFCRED_u16FilterSlewRate;                               */
/*  output uint16 CanPurg_rCanRes;                                            */
/*  output uint8 Av_dr_ralenti_purge;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTREFCRED_vidInhApplySlewRate(void)
{
   boolean  bLocalCanPurg_bTarIdlCanPurg;
   uint8    u8LocalAv_dr_ralenti_purge;
   uint16   u16LocalCanPurg_rCanRes;
   uint16   u16LocalFilterSlewRate;


   u16LocalFilterSlewRate =
         MATHSRV_u16SlewFilter(CSTREFCRED_u16FilterSlewRate,
                               Av_dr_ralenti_purge_raw,
                               Av_dr_ralenti_purge_inc_dec,
                               Av_dr_ralenti_purge_inc_dec);

   CSTREFCRED_u16FilterSlewRate =
         (uint16)MATHSRV_udtMIN(u16LocalFilterSlewRate, 1000);
   VEMS_vidGET(CanPurg_bTarIdlCanPurg, bLocalCanPurg_bTarIdlCanPurg);
   if (bLocalCanPurg_bTarIdlCanPurg != 0)
   {
      u16LocalCanPurg_rCanRes = 0;
   }
   else
   {
      u16LocalCanPurg_rCanRes = CSTREFCRED_u16FilterSlewRate;
   }

   VEMS_vidSET(CanPurg_rCanRes, u16LocalCanPurg_rCanRes);
   u16LocalCanPurg_rCanRes = (uint16)((u16LocalCanPurg_rCanRes * 8) / 10);
   u8LocalAv_dr_ralenti_purge =
      (uint8)MATHSRV_udtMIN(u16LocalCanPurg_rCanRes, 255);
   VEMS_vidSET(Av_dr_ralenti_purge, u8LocalAv_dr_ralenti_purge);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTREFCRED_vidIniIdlReq                                    */
/* !Description :  Au réveil calculateur, à chaque démarrage ou chaque        */
/*                 redémarrage, le booléen de demande de ralenti pour réaliser*/
/*                 la purge du canister doit être remis à zéro.               */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  R.GHORBEL                                                  */
/* !Trace_To    :  VEMS_R_09_01759_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean CanPurg_bEngStopAuth;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTREFCRED_vidIniIdlReq(void)
{
   VEMS_vidSET(CanPurg_bEngStopAuth, 1);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTREFCRED_vidClcnIdlReq                                   */
/* !Description :  Cette stratégie est applicable à l’ensemble des moteurs    */
/*                 essence pourvus de la fonctionnalité STOP & START.Le calcul*/
/*                 du booléen est donc conditionné par Ext_bSTTCf = ON.       */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  R.GHORBEL                                                  */
/* !Trace_To    :  VEMS_R_09_01759_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CSTREFCRED_vidClcn();                                    */
/*  input boolean Ext_bSTTCf;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTREFCRED_vidClcnIdlReq(void)
{
   boolean bLocalExt_bSTTCf;


   VEMS_vidGET(Ext_bSTTCf, bLocalExt_bSTTCf);
   if (bLocalExt_bSTTCf != 0)
   {
      CSTREFCRED_vidClcn();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTREFCRED_vidClcn                                         */
/* !Description :  Le booléen de demande de ralenti pour purger le canister   */
/*                 est à ON                                                   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  R.GHORBEL                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Ext_tAirExtMes;                                              */
/*  input uint16 Cpc_fuel_vapour_concentration;                               */
/*  input boolean Cpc_ena_conc_corrn;                                         */
/*  input uint16 Cpc_fuel_vapour_conc_err;                                    */
/*  input uint8 CanPurg_tAirAmbX_A[5];                                        */
/*  input uint16 CanPurg_ConcLoCanLdEngStopAllw_T[5];                         */
/*  input uint16 CanPurg_ConcHiCanLdEngStopAllw_T[5];                         */
/*  input uint16 Cpc_fuel_vapour_conc_corrd;                                  */
/*  input uint16 CanPurg_ConcLoCanLdEngStopAllw;                              */
/*  input uint16 CanPurg_ConcHiCanLdEngStopAllw;                              */
/*  input ???? MATHSRV_RISING_SCHMITT_TRIGGER;                                */
/*  input boolean CanPurg_bEngStopInh;                                        */
/*  input uint8 Temperature_eau;                                              */
/*  input sint16 Cpc_water_temp_thresh;                                       */
/*  output uint16 Cpc_fuel_vapour_conc_corrd;                                 */
/*  output uint16 CanPurg_ConcLoCanLdEngStopAllw;                             */
/*  output uint16 CanPurg_ConcHiCanLdEngStopAllw;                             */
/*  output boolean CanPurg_bEngStopAuth;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTREFCRED_vidClcn(void)
{
   boolean bLocalInhIdlReqCstr;
   boolean bLocalCanPurg_bEngStopAuth;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalExt_tAirExtMes;
   uint16  u16LocalCpc_fuel_vapour_ctr;
   uint16  u16LocalCpc_fuel_vapour_conc_err;
   uint16  u16LocalPara;
   sint16  s16LocalTemperature_eau;
   sint16  s16LocalExt_tAirExtMes;
   uint32  u32LocalProd;
   uint32  u32LocalDiff;
   sint32  s32LocalExt_tAirExtMes;


   VEMS_vidGET(Ext_tAirExtMes, s16LocalExt_tAirExtMes);
   VEMS_vidGET(Cpc_fuel_vapour_concentration, u16LocalCpc_fuel_vapour_ctr);
   if (Cpc_ena_conc_corrn != 0)
   {
      VEMS_vidGET(Cpc_fuel_vapour_conc_err, u16LocalCpc_fuel_vapour_conc_err);
      u32LocalDiff = (uint32)(65536 - u16LocalCpc_fuel_vapour_conc_err);
      u32LocalProd = u32LocalDiff * (uint32)u16LocalCpc_fuel_vapour_ctr;
      Cpc_fuel_vapour_conc_corrd = (uint16)(u32LocalProd / 65536);
   }
   else
   {
      Cpc_fuel_vapour_conc_corrd = u16LocalCpc_fuel_vapour_ctr;
   }

   s32LocalExt_tAirExtMes = (sint32)(s16LocalExt_tAirExtMes + 50);
   u8LocalExt_tAirExtMes = (uint8)MATHSRV_udtCLAMP(s32LocalExt_tAirExtMes,
                                                    0,
                                                    250);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU8(CanPurg_tAirAmbX_A,
                                              u8LocalExt_tAirExtMes,
                                              5);
   CanPurg_ConcLoCanLdEngStopAllw =
      MATHSRV_u16Interp1d(CanPurg_ConcLoCanLdEngStopAllw_T, u16LocalPara);
   CanPurg_ConcHiCanLdEngStopAllw =
      MATHSRV_u16Interp1d(CanPurg_ConcHiCanLdEngStopAllw_T, u16LocalPara);

   MATHSRV_vidSchmittTriggerU16(Cpc_fuel_vapour_conc_corrd,
                                CanPurg_ConcLoCanLdEngStopAllw,
                                CanPurg_ConcHiCanLdEngStopAllw,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &CanPurg_bEngStopInh);

   bLocalInhIdlReqCstr = GDGAR_bGetFRM(FRM_FRM_INHIDLREQCSTR);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   s16LocalTemperature_eau = (sint16)(u8LocalTemperature_eau - 64);
   if (  (CanPurg_bEngStopInh != 0)
      && (bLocalInhIdlReqCstr == 0)
      && (s16LocalTemperature_eau > Cpc_water_temp_thresh))
   {
      bLocalCanPurg_bEngStopAuth = 0;
   }
   else
   {
      bLocalCanPurg_bEngStopAuth = 1;
   }
   VEMS_vidSET(CanPurg_bEngStopAuth, bLocalCanPurg_bEngStopAuth);
}

/*-------------------------- end of file -------------------------------------*/