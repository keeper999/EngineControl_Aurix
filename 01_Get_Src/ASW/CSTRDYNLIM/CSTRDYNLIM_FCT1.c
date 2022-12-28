/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CSTRDYNLIM                                              */
/* !Description     : CSTRDYNLIM component.                                   */
/*                                                                            */
/* !Module          : CSTRDYNLIM                                              */
/* !Description     : BORNAGE DYNAMIQUE DE DEBIT PURGE                        */
/*                                                                            */
/* !File            : CSTRDYNLIM_FCT1.C                                       */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / CSTRDYNLIM_vidInitOutput                                             */
/*   2 / CSTRDYNLIM_vidDynLimClc                                              */
/*   3 / CSTRDYNLIM_vidCurPurgeRat                                            */
/*   4 / CSTRDYNLIM_vidFuMaxCta                                               */
/*   5 / CSTRDYNLIM_vidInjMinCta                                              */
/*   6 / CSTRDYNLIM_vidAirMaxCta                                              */
/*   7 / CSTRDYNLIM_vidLsclCta                                                */
/*   8 / CSTRDYNLIM_vidNullRat                                                */
/*   9 / CSTRDYNLIM_vidCurRat                                                 */
/*   10 / CSTRDYNLIM_vidPrgIncRat                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5205503 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CSTR/CSTRDYNLIM/CSTRDYNLIM_FCT1.$*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   22 May 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   22 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_Types.h"
#include "STD_limits.h"
#include "MATHSRV.h"
#include "CSTRDYNLIM.h"
#include "CSTRDYNLIM_L.h"
#include "CSTRDYNLIM_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRDYNLIM_vidInitOutput                                   */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 CSTRDYNLIM_u8CpcPurgCtrlStatPrev;                            */
/*  output boolean CSTRDYNLIM_bGsmPurgeClosingEntry;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRDYNLIM_vidInitOutput(void)
{
   CSTRDYNLIM_u8CpcPurgCtrlStatPrev = (uint8)CPC_PURGE_CLOSED;
   CSTRDYNLIM_bGsmPurgeClosingEntry = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRDYNLIM_vidDynLimClc                                    */
/* !Description :  Tous les calculs se font au réveil ECU                     */
/*                 (Cstr_EveRst_CstrDynLim) et à la récurrence du moniteur    */
/*                 moyen (Cstr_SdlMid_CstrDynLim).                            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CSTRDYNLIM_vidCurPurgeRat();                             */
/*  extf argret void CSTRDYNLIM_vidFuMaxCta();                                */
/*  extf argret void CSTRDYNLIM_vidInjMinCta();                               */
/*  extf argret void CSTRDYNLIM_vidAirMaxCta();                               */
/*  extf argret void CSTRDYNLIM_vidLsclCta();                                 */
/*  extf argret void CSTRDYNLIM_vidPurgeGblCta();                             */
/*  input st61 Cpc_purge_control_state;                                       */
/*  input boolean Purge_test_banc;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRDYNLIM_vidDynLimClc(void)
{
   boolean bLocalClcBornDynPurge;
   uint8   u8LocalCpc_purge_control_state;


   VEMS_vidGET(Cpc_purge_control_state, u8LocalCpc_purge_control_state);
   if (Purge_test_banc == 0)
   {
      CSTRDYNLIM_vidCurPurgeRat();
   }

   if (  (  (u8LocalCpc_purge_control_state == CPC_NORMAL_BOUNDING)
         || (u8LocalCpc_purge_control_state == CPC_GSM_PURGE_CLOSING))
      && (Purge_test_banc == 0))
   {
      bLocalClcBornDynPurge = 1;
   }
   else
   {
      bLocalClcBornDynPurge = 0;
   }

   if (bLocalClcBornDynPurge != 0)
   {
      CSTRDYNLIM_vidFuMaxCta();
      CSTRDYNLIM_vidInjMinCta();
      CSTRDYNLIM_vidAirMaxCta();
   }
   if (Purge_test_banc == 0)
   {
      CSTRDYNLIM_vidLsclCta();
   }
   if (  (bLocalClcBornDynPurge != 0)
      || (u8LocalCpc_purge_control_state == CPC_PURGE_CLOSED))
   {
      CSTRDYNLIM_vidPurgeGblCta();
   }

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRDYNLIM_vidCurPurgeRat                                  */
/* !Description :  Le taux de purge courant est calculé en fonction du débit  */
/*                 papillon et du débit gaz de la purge.                      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 InM_mfAirThrEstim;                                           */
/*  input uint16 InM_mfTotCanPurgEstim;                                       */
/*  output uint16 Cpc_current_purge_ratio;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRDYNLIM_vidCurPurgeRat(void)
{
   uint16 u16LocalInM_mfAirThrEstim;
   uint16 u16LocalInM_mfTotCanPurgEstim;
   uint16 u16LocalCpc_current_purge_ratio;
   uint32 u32LocalInM_mfTotCanPurgEstim;
   uint32 u32LocalDiv;


   VEMS_vidGET(InM_mfAirThrEstim, u16LocalInM_mfAirThrEstim);
   VEMS_vidGET(InM_mfTotCanPurgEstim, u16LocalInM_mfTotCanPurgEstim);
   u32LocalInM_mfTotCanPurgEstim = (uint32)( u16LocalInM_mfTotCanPurgEstim
                                           * 16384);
   if (u16LocalInM_mfAirThrEstim != 0)
   {
      u32LocalDiv = (u32LocalInM_mfTotCanPurgEstim / u16LocalInM_mfAirThrEstim);
      u16LocalCpc_current_purge_ratio = (uint16)MATHSRV_udtMIN(u32LocalDiv,
                                                               65535);
   }
   else
   {
      u16LocalCpc_current_purge_ratio = 0;
   }
   VEMS_vidSET(Cpc_current_purge_ratio, u16LocalCpc_current_purge_ratio);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRDYNLIM_vidFuMaxCta                                     */
/* !Description :  Afin  de  préserver  l’autorité  de  la  régulation  de    */
/*                 richesse,  tout  en  purgeant  au maximum  le  canister,   */
/*                 on  veut limiter la contribution en essence de la purge à  */
/*                 Cpc_fuel_constraint_max .                                  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 Required_fuel_flow_rate;                                     */
/*  input uint16 Cpc_fuel_vapour_concentration;                               */
/*  input uint8 Regime_moteur_2_bkpt_map[9];                                  */
/*  input uint16 EngM_rAirLdCor_2_A[9];                                       */
/*  input uint8 Cpc_fuel_constraint_max_map[9][9];                            */
/*  input uint8 Cpc_fuel_constraint_max;                                      */
/*  input uint16 Required_fuel_flow_rate_si;                                  */
/*  output uint8 Cpc_fuel_constraint_max;                                     */
/*  output uint16 Required_fuel_flow_rate_si;                                 */
/*  output uint16 Cpc_fuel_constraint_max_mfr;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRDYNLIM_vidFuMaxCta(void)
{
   uint8  u8LocalRegime_moteur_32;
   uint16 u16LocalRegime_moteur;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalEngM_rAirLd;
   uint16 u16LocalRequired_fuel_flow_rate;
   uint16 u16LocalCpc_fuel_vapour_concentr;
   uint32 u32LocalProduit;
   uint32 u32LocalDiv;


   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLd);
   VEMS_vidGET(Required_fuel_flow_rate, u16LocalRequired_fuel_flow_rate);
   VEMS_vidGET(Cpc_fuel_vapour_concentration, u16LocalCpc_fuel_vapour_concentr);
   u16LocalRegime_moteur = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_2_bkpt_map,
                                                       u8LocalRegime_moteur_32,
                                                       9);
   u16LocalEngM_rAirLdCor = MATHSRV_u16CalcParaIncAryU16(EngM_rAirLdCor_2_A,
                                                         u16LocalEngM_rAirLd,
                                                         9);

   Cpc_fuel_constraint_max =
      MATHSRV_u8Interp2d(&Cpc_fuel_constraint_max_map[0][0],
                         u16LocalRegime_moteur,
                         u16LocalEngM_rAirLdCor,
                         9);

   Required_fuel_flow_rate_si = u16LocalRequired_fuel_flow_rate;
   u32LocalProduit = (uint32)( Cpc_fuel_constraint_max
                             * Required_fuel_flow_rate_si
                             * 256);
   if (u16LocalCpc_fuel_vapour_concentr != 0)
   {
      u32LocalDiv = (u32LocalProduit / u16LocalCpc_fuel_vapour_concentr);
      Cpc_fuel_constraint_max_mfr = (uint16)MATHSRV_udtMIN(u32LocalDiv, 65535);
   }
   else
   {
      Cpc_fuel_constraint_max_mfr =
         (uint16)MATHSRV_udtMIN(u32LocalProduit, 65535);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRDYNLIM_vidInjMinCta                                    */
/* !Description :  Le débit maximal pour permettre un temps d'injection Tmin  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint16 Injector_constant;                                           */
/*  input uint16 Cpc_fuel_vapour_concentration;                               */
/*  input sint16 InjrM_prm_tiInjOfsInj[4];                                    */
/*  input uint8 Cpc_min_fuel_pulse_width;                                     */
/*  input uint16 Required_fuel_flow_rate_si;                                  */
/*  input uint16 Cpc_min_inj_time_fuel_flow_rate;                             */
/*  output uint16 Cpc_min_inj_time_fuel_flow_rate;                            */
/*  output uint16 Cpc_fpw_constraint_max_mfr;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRDYNLIM_vidInjMinCta(void)
{
   uint8   u8LocalExt_noCylEng;
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalInjectorConstant;
   uint16  u16LocalCpcFuelVapourConc;
   uint32  u32LocalDiff;
   uint32  u32LocalDivi;
   sint16  s16LocalTiInjOfsInj;
   sint32  s32LocalDiff;
   float32 f32LocalNum;
   float32 f32LocalDenum;
   float32 f32LocalDiv;


   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
   VEMS_vidGET(Injector_constant, u16LocalInjectorConstant);
   VEMS_vidGET(Cpc_fuel_vapour_concentration, u16LocalCpcFuelVapourConc);
   VEMS_vidGET1DArrayElement(InjrM_prm_tiInjOfsInj,0,s16LocalTiInjOfsInj);

   f32LocalNum = (float32)( (Cpc_min_fuel_pulse_width * 78125)
                          - (s16LocalTiInjOfsInj * 16384));
   f32LocalNum = ( f32LocalNum
                 * (float32)u16LocalRegime_moteur
                 * (float32)u8LocalExt_noCylEng
                 * (float32)128);
   f32LocalDenum = (float32)(u16LocalInjectorConstant + 1) * (float32)1171875;
   f32LocalDiv = f32LocalNum / f32LocalDenum;

   Cpc_min_inj_time_fuel_flow_rate = (uint16)MATHSRV_udtCLAMP(f32LocalDiv,
                                                              (float32)0,
                                                              (float32)65535);
   s32LocalDiff = (sint32)( Required_fuel_flow_rate_si
                          - Cpc_min_inj_time_fuel_flow_rate);
   if (Required_fuel_flow_rate_si >= Cpc_min_inj_time_fuel_flow_rate)
   {
      if (u16LocalCpcFuelVapourConc != 0)
      {
         u32LocalDiff =(uint32)(s32LocalDiff * 65536);
         u32LocalDivi = ( u32LocalDiff / u16LocalCpcFuelVapourConc);
         Cpc_fpw_constraint_max_mfr =
            (uint16)MATHSRV_udtMIN(u32LocalDivi, 65535);
      }
      else
      {
         Cpc_fpw_constraint_max_mfr = (uint16)(CPC_FPW_LIM_MAX_MFR_MAX_VAL);
      }
   }
   else
   {
      if (u16LocalCpcFuelVapourConc != 0)
      {
         Cpc_fpw_constraint_max_mfr = 0;
      }
      else
      {
         Cpc_fpw_constraint_max_mfr = (uint16)(CPC_FPW_LIM_MAX_MFR_MAX_VAL);
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRDYNLIM_vidAirMaxCta                                    */
/* !Description :  Pour  ne  pas  avoir  de  surrégime  sur  lâcher  de  pied,*/
/*                  on  veut  limiter  la  contribution  de  la  purge à      */
/*                 Cpc_max_amfr_thresh du débit d'air entrant dans le         */
/*                 papillon.                                                  */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 InM_mfAirThrEstim;                                           */
/*  input uint16 Cpc_fuel_vapour_concentration;                               */
/*  input uint8 Cpc_max_amfr_thresh;                                          */
/*  input uint16 Cpc_max_air_mfr;                                             */
/*  output uint16 Cpc_max_air_mfr;                                            */
/*  output uint16 Cpc_air_constraint_max_mfr;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRDYNLIM_vidAirMaxCta(void)
{
   uint16 u16LocalCpcMaxAmfrThresh;
   uint16 u16LocalInM_mfAirThrEstim;
   uint16 u16LocalCpc_fuel_vapour_concentr;
   uint32 u32LocalProduit;
   uint32 u32LocalCpcFuelVapourConcent;
   uint32 u32LocalCpc_max_air_mfr;
   uint32 u32LocalDivi;
   uint32 u32LocalDiv;


   VEMS_vidGET(InM_mfAirThrEstim, u16LocalInM_mfAirThrEstim);
   VEMS_vidGET(Cpc_fuel_vapour_concentration, u16LocalCpc_fuel_vapour_concentr);
   u32LocalProduit = u16LocalInM_mfAirThrEstim * Cpc_max_amfr_thresh;
   u16LocalCpcMaxAmfrThresh = (uint16)(256 - Cpc_max_amfr_thresh);
   u32LocalCpcFuelVapourConcent =
   (uint32)(65536 - u16LocalCpc_fuel_vapour_concentr);

   u32LocalDivi = ( u32LocalProduit / u16LocalCpcMaxAmfrThresh);
   Cpc_max_air_mfr = (uint16)MATHSRV_udtMIN(u32LocalDivi, 65535);
   if(Cpc_max_air_mfr >= 4096)
   {
      Cpc_air_constraint_max_mfr = 65535;
   }
   else
   {
      u32LocalCpc_max_air_mfr = (uint32)(Cpc_max_air_mfr * 1048576);
      u32LocalDiv = (u32LocalCpc_max_air_mfr / u32LocalCpcFuelVapourConcent);
      Cpc_air_constraint_max_mfr = (uint16)MATHSRV_udtMIN(u32LocalDiv, 65535);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRDYNLIM_vidLsclCta                                      */
/* !Description :  L'objectif de ce processus est de calculer 'au mieux'      */
/*                 l'évolution du taux de purge                               */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CSTRDYNLIM_vidNullRat();                                 */
/*  extf argret void CSTRDYNLIM_vidCurRat();                                  */
/*  extf argret void CSTRDYNLIM_vidPrgIncRat();                               */
/*  extf argret void CSTRDYNLIM_vidPrgDecRat();                               */
/*  input st61 Cpc_purge_control_state;                                       */
/*  input uint16 Cpc_fuel_mass_flow_rate;                                     */
/*  input uint16 InM_mfAirThrEstim;                                           */
/*  input uint16 Required_fuel_flow_rate_si;                                  */
/*  input uint8 Cpc_purge_fuel_ratio;                                         */
/*  input uint16 Cpc_purge_rate_gain_map[9];                                  */
/*  input uint16 Cpc_purge_rate_gain_stt_map[9];                              */
/*  input uint8 CSTRDYNLIM_u8CpcPurgCtrlStatPrev;                             */
/*  input uint16 Cpc_max_purge_ratio;                                         */
/*  output uint8 Cpc_purge_fuel_ratio;                                        */
/*  output uint16 Cpc_purge_rate_gain;                                        */
/*  output uint16 Cpc_purge_rate_gain_stt;                                    */
/*  output boolean CSTRDYNLIM_bGsmPurgeClosingEntry;                          */
/*  output uint16 Cpc_lambda_constraint_max_mfr;                              */
/*  output uint8 CSTRDYNLIM_u8CpcPurgCtrlStatPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRDYNLIM_vidLsclCta(void)
{
   uint8  u8LocalCpc_purge_control_state;
   uint16 u16LocalCpc_purge_fuel_ratio;
   uint16 u16LocalCpc_fuel_mass_flow_rate;
   uint16 u16LocalInM_mfAirThrEstim;
   uint32 u32LocalDiv;
   uint32 u32LocalDivi;


   VEMS_vidGET(Cpc_purge_control_state, u8LocalCpc_purge_control_state);
   VEMS_vidGET(Cpc_fuel_mass_flow_rate, u16LocalCpc_fuel_mass_flow_rate);
   VEMS_vidGET(InM_mfAirThrEstim, u16LocalInM_mfAirThrEstim);
   if (Required_fuel_flow_rate_si != 0)
   {
      u32LocalDiv = ( (uint32)( u16LocalCpc_fuel_mass_flow_rate * 256)
                    / Required_fuel_flow_rate_si);
      Cpc_purge_fuel_ratio = (uint8)MATHSRV_udtMIN(u32LocalDiv, 255);
   }
   else
   {
      Cpc_purge_fuel_ratio = 0;
   }
   u16LocalCpc_purge_fuel_ratio = (uint16)(Cpc_purge_fuel_ratio * 8);
   Cpc_purge_rate_gain = MATHSRV_u16Interp1d(Cpc_purge_rate_gain_map,
                                             u16LocalCpc_purge_fuel_ratio);
   Cpc_purge_rate_gain_stt = MATHSRV_u16Interp1d(Cpc_purge_rate_gain_stt_map,
                                                 u16LocalCpc_purge_fuel_ratio);
   if (  (u8LocalCpc_purge_control_state == CPC_PURGE_MIN)
      || (u8LocalCpc_purge_control_state == CPC_PURGE_CLOSED)
      || (u8LocalCpc_purge_control_state == CPC_FULL_LOAD))
   {
      CSTRDYNLIM_vidNullRat();
   }
   if (  (u8LocalCpc_purge_control_state == CPC_PURGE_HOLDING)
      || (u8LocalCpc_purge_control_state == CPC_LAMBDA_PURGE_CLOSING))
   {
      CSTRDYNLIM_vidCurRat();
   }
   if (u8LocalCpc_purge_control_state == CPC_NORMAL_BOUNDING)
   {
      CSTRDYNLIM_vidPrgIncRat();
   }

   if (  (CSTRDYNLIM_u8CpcPurgCtrlStatPrev == CPC_NORMAL_BOUNDING)
      || (CSTRDYNLIM_u8CpcPurgCtrlStatPrev == CPC_FULL_LOAD))
   {
      CSTRDYNLIM_bGsmPurgeClosingEntry = 1;
   }
   else
   {
      CSTRDYNLIM_bGsmPurgeClosingEntry = 0;
   }

   if (u8LocalCpc_purge_control_state == CPC_GSM_PURGE_CLOSING)
   {
      CSTRDYNLIM_vidPrgDecRat();
   }
   u32LocalDivi = ( (uint32)( ( u16LocalInM_mfAirThrEstim * Cpc_max_purge_ratio)
                            + 8192)
                  / 16384);
   Cpc_lambda_constraint_max_mfr = (uint16)MATHSRV_udtMIN(u32LocalDivi, 65535);
   CSTRDYNLIM_u8CpcPurgCtrlStatPrev = u8LocalCpc_purge_control_state;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRDYNLIM_vidNullRat                                      */
/* !Description :  calcul de la variable Cpc_max_purge_ratio                  */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Cpc_max_purge_ratio;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRDYNLIM_vidNullRat(void)
{
   Cpc_max_purge_ratio = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRDYNLIM_vidCurRat                                       */
/* !Description :  calcul de la variable Cpc_max_purge_ratio                  */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Cpc_current_purge_ratio;                                     */
/*  output uint16 Cpc_max_purge_ratio;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRDYNLIM_vidCurRat(void)
{
   uint16 u16LocalCpc_current_purge_ratio;


   VEMS_vidGET(Cpc_current_purge_ratio, u16LocalCpc_current_purge_ratio);
   Cpc_max_purge_ratio = u16LocalCpc_current_purge_ratio;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRDYNLIM_vidPrgIncRat                                    */
/* !Description :  calcul de la variable Cpc_max_purge_ratio                  */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Cpc_fuel_vapour_conc_err;                                    */
/*  input uint16 Cpc_purge_rate_gain;                                         */
/*  input uint8 Cpc_max_purge_ratio_max_step;                                 */
/*  input uint16 Cpc_max_purge_ratio;                                         */
/*  output uint16 Cpc_max_purge_ratio;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRDYNLIM_vidPrgIncRat(void)
{
   uint16 u16LocalCpc_fuel_vapour_conc_err;
   uint16 u16LocalDiv;
   uint32 u32LocalCpc_purge_rate_gain;
   uint32 u32LocalCpc_max_purge_ratio;
   uint32 u32LocalCpc_max_purge_rat;
   uint32 u32LocalSom;
   uint32 u32LocalDivi;


   VEMS_vidGET(Cpc_fuel_vapour_conc_err, u16LocalCpc_fuel_vapour_conc_err);
   u32LocalCpc_purge_rate_gain = (uint32)(Cpc_purge_rate_gain * 49152);

   if (u16LocalCpc_fuel_vapour_conc_err != 0)
   {
      u32LocalCpc_max_purge_ratio =
         (((u32LocalCpc_purge_rate_gain + 3125) / 6250));
      if (u32LocalCpc_max_purge_ratio >= 491528)
      {
      /*Msg(3:3356)/Msg(3:3359)/Msg(3:3201):Pas d'impact: cette condition
      est couverte dans le rtrt*/
         u32LocalCpc_max_purge_rat = UINT32_MAX;
      }
      else
      {
         u32LocalCpc_max_purge_rat = ( u32LocalCpc_max_purge_ratio
                                     * 8738);
      }

      u32LocalDivi = ( u32LocalCpc_max_purge_rat
                     / u16LocalCpc_fuel_vapour_conc_err);
      u16LocalDiv = (uint16)MATHSRV_udtMIN(u32LocalDivi, 65535);
   }

   else
   {
      u16LocalDiv = (uint16)(Cpc_max_purge_ratio_max_step * 256);
   }
   u32LocalSom = (uint32)( u16LocalDiv + Cpc_max_purge_ratio);
   Cpc_max_purge_ratio =
      (uint16)MATHSRV_udtMIN(u32LocalSom, 65535);
}
/*------------------------------- end of file --------------------------------*/