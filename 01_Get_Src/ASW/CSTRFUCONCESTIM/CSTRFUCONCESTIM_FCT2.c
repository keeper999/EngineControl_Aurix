/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CSTRFUCONCESTIM                                         */
/* !Description     : CSTRFUCONCESTIM Component.                              */
/*                                                                            */
/* !Module          : CSTRFUCONCESTIM                                         */
/* !Description     : ESTIMATEUR DE LA CONCENTRATION EN VAPEURS D_ESSENCE DES */
/*                    GAZ ISSUS DE LA PURGE CANISTER                          */
/*                                                                            */
/* !File            : CSTRFUCONCESTIM_FCT2.C                                  */
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
/*   1 / CSTRFUCONCESTIM_vidCllConc                                           */
/*   2 / CSTRFUCONCESTIM_vidCllConcEstim                                      */
/*   3 / CSTRFUCONCESTIM_vidConcFuErr                                         */
/*   4 / CSTRFUCONCESTIM_vidConcFuEstim                                       */
/*   5 / CSTRFUCONCESTIM_vidOutIf                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5066966 / 07                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CSTR/CSTRFUCONCESTIM/CSTRFUCONCE$*/
/* $Revision::   1.11     $$Author::   etsasson       $$Date::   28 Apr 2014 $*/
/* $Author::   etsasson                               $$Date::   28 Apr 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "CSTRFUCONCESTIM.h"
#include "CSTRFUCONCESTIM_L.h"
#include "CSTRFUCONCESTIM_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRFUCONCESTIM_vidCllConc                                 */
/* !Description :  Fonction d'estimation  de  la  proportion  de  vapeurs     */
/*                 d'essence  dans  le mélange  gazeux issu de la purge       */
/*                 canister et de détermination du pas d’incrémentation  de la*/
/*                 concentration.                                             */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CSTRFUCONCESTIM_vidCllConcEstim();                       */
/*  input boolean Cstr_bEnaCllConcEstim;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRFUCONCESTIM_vidCllConc(void)
{
   if (Cstr_bEnaCllConcEstim != 0)
   {
      CSTRFUCONCESTIM_vidCllConcEstim();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRFUCONCESTIM_vidCllConcEstim                            */
/* !Description :  Fonction de régultion de la richesse.                      */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CSTRFUCONCESTIM_vidConcFuErr();                          */
/*  extf argret void CSTRFUCONCESTIM_vidConcFuEstim();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRFUCONCESTIM_vidCllConcEstim(void)
{
   CSTRFUCONCESTIM_vidConcFuErr();
   CSTRFUCONCESTIM_vidConcFuEstim();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRFUCONCESTIM_vidConcFuErr                               */
/* !Description :  Fonction de calcul de l'erreur commise sur l'estimateur de */
/*                 concentration de vapeur  d'essence dans le canister en     */
/*                 boucle fermée.                                             */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  PTS_R_5066966_010.02                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Temperature_air;                                              */
/*  input uint8 FuConcEstim_tAirFuConcThd_A[8];                               */
/*  input uint16 FuConcEstim_concFuVapThd_M[8];                               */
/*  input uint8 FuConcEstim_tAirRlamThd_A[8];                                 */
/*  input uint16 FuConcEstim_rLamThd_M[8];                                    */
/*  input uint16 Cpc_fuel_vapour_concentration;                               */
/*  input sint16 Lambda_feedback_filtered;                                    */
/*  input uint16 FuConcEstim_concFuVapThd;                                    */
/*  input sint16 FuConcEstim_rLamThd;                                         */
/*  input uint16 Cpc_fuel_mass_flow_rate;                                     */
/*  input uint16 InM_mfAirThrEstim;                                           */
/*  input uint8 Cstr_facAfs_C;                                                */
/*  input uint16 Cpc_fuel_vapour_conc_err;                                    */
/*  input boolean Cpc_fuel_vapour_conc_err_near_0;                            */
/*  input uint16 Cpc_conc_err_filter_gain;                                    */
/*  input uint32 CSTRFUCONCESTIM_u32FuelFilterMem;                            */
/*  input uint16 Cpc_fuel_vap_conc_err_close_loop;                            */
/*  output uint16 FuConcEstim_concFuVapThd;                                   */
/*  output sint16 FuConcEstim_rLamThd;                                        */
/*  output boolean Cpc_fuel_vapour_conc_err_near_0;                           */
/*  output uint16 Cpc_fuel_vap_conc_err_close_loop;                           */
/*  output uint32 CSTRFUCONCESTIM_u32FuelFilterMem;                           */
/*  output uint16 Cpc_fuel_vapour_conc_err;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRFUCONCESTIM_vidConcFuErr(void)
{
   uint8   u8LocalTemperature_air;
   uint16  u16LocalPara1;
   uint16  u16LocalPara2;
   uint16  u16LocalInterp;
   uint16  u16LocalCpc_fuel_vapour_concentr;
   uint16  u16LocalInM_mfAirThrEstim;
   uint16  u16LocalCpc_fuel_mass_flow_rate;
   uint16  u16LocalCpc_fuel_vapour_conc_err;
   uint16  u16Localconst;
   uint32  u32LocalNumcalc;
   uint32  u32LocalDencalc;
   uint32  u32LocalResultcalc;
   sint16  s16LocalLambda_feedback_filtered;


   VEMS_vidGET(Temperature_air, u8LocalTemperature_air);
   u16LocalPara1 = MATHSRV_u16CalcParaIncAryU8(FuConcEstim_tAirFuConcThd_A,
                                               u8LocalTemperature_air,
                                               8);
   FuConcEstim_concFuVapThd = MATHSRV_u16Interp1d(FuConcEstim_concFuVapThd_M,
                                                  u16LocalPara1);

   u16LocalPara2 = MATHSRV_u16CalcParaIncAryU8(FuConcEstim_tAirRlamThd_A,
                                               u8LocalTemperature_air,
                                               8);
   u16LocalInterp = MATHSRV_u16Interp1d(FuConcEstim_rLamThd_M, u16LocalPara2);

   FuConcEstim_rLamThd = (sint16)(u16LocalInterp - 32768);
   VEMS_vidGET(Cpc_fuel_vapour_concentration, u16LocalCpc_fuel_vapour_concentr);
   VEMS_vidGET(Lambda_feedback_filtered, s16LocalLambda_feedback_filtered);

   if (  (u16LocalCpc_fuel_vapour_concentr <= FuConcEstim_concFuVapThd)
      && (s16LocalLambda_feedback_filtered > FuConcEstim_rLamThd))
   {
      Cpc_fuel_vapour_conc_err_near_0 = 1;
   }
   else
   {
      if (  (u16LocalCpc_fuel_vapour_concentr == CPC_CONC_100_PERC)
         && (s16LocalLambda_feedback_filtered < 0))
      {
         Cpc_fuel_vapour_conc_err_near_0 = 1;
      }
      else
      {
         Cpc_fuel_vapour_conc_err_near_0 = 0;
      }
   }

   VEMS_vidGET(Cpc_fuel_mass_flow_rate, u16LocalCpc_fuel_mass_flow_rate);
   VEMS_vidGET(InM_mfAirThrEstim, u16LocalInM_mfAirThrEstim);

   u32LocalNumcalc =
      (uint32)(u16LocalInM_mfAirThrEstim
               * (MATHSRV_udtABS(s16LocalLambda_feedback_filtered)));
   if (u32LocalNumcalc > 53687091)
   {
      u32LocalDencalc = (uint32)( ( ( u16LocalCpc_fuel_mass_flow_rate
                                    * ( Cstr_facAfs_C
                                      + 1))
                                  + 40)
                                / 80);
   }
   else
   {
      u32LocalDencalc =
         (uint32)(u16LocalCpc_fuel_mass_flow_rate * (Cstr_facAfs_C + 1));
      u32LocalNumcalc = u32LocalNumcalc * 80;
   }
   if (u32LocalDencalc != 0)
   {
      u32LocalResultcalc = u32LocalNumcalc / u32LocalDencalc;
   }
   else
   {
      u32LocalResultcalc = CPC_CONC_ERR_100_PERC;
   }
   Cpc_fuel_vap_conc_err_close_loop =
      (uint16)MATHSRV_udtMIN(u32LocalResultcalc, CPC_CONC_ERR_100_PERC);

   VEMS_vidGET(Cpc_fuel_vapour_conc_err, u16LocalCpc_fuel_vapour_conc_err);
   CSTRFUCONCESTIM_u32FuelFilterMem =
      (uint32)(u16LocalCpc_fuel_vapour_conc_err * 65536);
   if (Cpc_fuel_vapour_conc_err_near_0 == 0)
   {
      u16LocalCpc_fuel_vapour_conc_err =
      MATHSRV_u16FirstOrderFilterGu16(Cpc_conc_err_filter_gain,
                                     &CSTRFUCONCESTIM_u32FuelFilterMem,
                                     Cpc_fuel_vap_conc_err_close_loop);
   }
   else
   {
      u16Localconst = (uint16)(CPC_CONC_ERR_5_PERC);
      u16LocalCpc_fuel_vapour_conc_err =
      MATHSRV_u16FirstOrderFilterGu16(Cpc_conc_err_filter_gain,
                                     &CSTRFUCONCESTIM_u32FuelFilterMem,
                                     u16Localconst);
   }

   VEMS_vidSET(Cpc_fuel_vapour_conc_err, u16LocalCpc_fuel_vapour_conc_err);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRFUCONCESTIM_vidConcFuEstim                             */
/* !Description :  Fonction d' estimation  de  la  proportion  de  vapeurs    */
/*                 d'essence  dans  le mélange  gazeux issu de la purge       */
/*                 canister.                                                  */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Cpc_fuel_vapour_conc_err;                                    */
/*  input uint16 Cpc_conc_closed_loop_step_map[5];                            */
/*  input sint16 Lambda_feedback_filtered;                                    */
/*  input uint16 Cpc_fuel_vapour_concentration;                               */
/*  input uint8 Cpc_dead_zone_thresh;                                         */
/*  input uint16 Cpc_conc_closed_loop_step;                                   */
/*  output uint16 Cpc_conc_closed_loop_step;                                  */
/*  output uint16 Cpc_fuel_vapour_concentration;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRFUCONCESTIM_vidConcFuEstim(void)
{
   uint16  u16LocalCpc_fuel_vapour_conc_err;
   uint16  u16LocalCpc_fuel_vapour_concentr;
   uint16  u16LocalClacinter;
   uint16  u16LocalCpcfuelvapourconcerr;
   uint16  u16LocalCpcconcclosed;
   uint32  u32LocalCpcfuelvapcon;
   sint16  s16LocalClacinter;
   sint16  s16LocalLambda_feedback_filtered;
   sint32  s32LocalCpcfuelvapcon;


   VEMS_vidGET(Cpc_fuel_vapour_conc_err, u16LocalCpc_fuel_vapour_conc_err);

   u16LocalCpcfuelvapourconcerr =
      (uint16)(u16LocalCpc_fuel_vapour_conc_err / 64);
   u16LocalCpcconcclosed =
      MATHSRV_u16Interp1d(Cpc_conc_closed_loop_step_map,
                          u16LocalCpcfuelvapourconcerr);
   Cpc_conc_closed_loop_step =
      (uint16)MATHSRV_udtMIN(u16LocalCpcconcclosed, 7995);

   VEMS_vidGET(Lambda_feedback_filtered, s16LocalLambda_feedback_filtered);
   VEMS_vidGET(Cpc_fuel_vapour_concentration, u16LocalCpc_fuel_vapour_concentr);

   u16LocalClacinter = (uint16)((uint32)(Cpc_dead_zone_thresh * 32768) / 255);

   if (s16LocalLambda_feedback_filtered > u16LocalClacinter)
   {
      s32LocalCpcfuelvapcon =
         (sint32)(u16LocalCpc_fuel_vapour_concentr - Cpc_conc_closed_loop_step);
      u16LocalCpc_fuel_vapour_concentr =
         (uint16)MATHSRV_udtMAX(s32LocalCpcfuelvapcon,
                                  0);
   }
   else
   {
      s16LocalClacinter = (sint16)(u16LocalClacinter * (-1));
      if (s16LocalLambda_feedback_filtered < s16LocalClacinter)
      {
         u32LocalCpcfuelvapcon =
         (uint32)(u16LocalCpc_fuel_vapour_concentr + Cpc_conc_closed_loop_step);
         u16LocalCpc_fuel_vapour_concentr =
         (uint16)MATHSRV_udtMIN(u32LocalCpcfuelvapcon,
                               (uint32)CPC_CONC_100_PERC);
      }
   }

   VEMS_vidSET(Cpc_fuel_vapour_concentration, u16LocalCpc_fuel_vapour_concentr);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRFUCONCESTIM_vidOutIf                                   */
/* !Description :  Fonction de centralisation des renommages des variables de */
/*                 sortie.                                                    */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_09_01206_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Cpc_fuel_mass_flow_rate;                                     */
/*  input uint16 Cpc_fuel_vapour_concentration;                               */
/*  input uint16 Cpc_fuel_vapour_conc_err;                                    */
/*  input boolean CanPurg_bAcvBypconcFuStmErr_C;                              */
/*  input uint16 CanPurg_concFuStmErr_BypC;                                   */
/*  output uint16 CanPurg_mfFuStmEstim;                                       */
/*  output uint16 CanPurg_concFuStmEstim;                                     */
/*  output uint16 CanPurg_ldGasFuCan;                                         */
/*  output uint16 CanPurg_concFuStmErr;                                       */
/*  output uint16 CanPurg_concFuStmErr_BypC;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRFUCONCESTIM_vidOutIf(void)
{
   uint16  u16LocalCpc_fuel_mass_flow_rate;
   uint16  u16LocalCpc_fuel_vapour_concentr;
   uint16  u16LocalCpc_fuel_vapour_conc_err;
   uint16  u16LocalCanPurg_ldGasFuCan;


   VEMS_vidGET(Cpc_fuel_mass_flow_rate, u16LocalCpc_fuel_mass_flow_rate);
   VEMS_vidGET(Cpc_fuel_vapour_concentration, u16LocalCpc_fuel_vapour_concentr);
   VEMS_vidGET(Cpc_fuel_vapour_conc_err, u16LocalCpc_fuel_vapour_conc_err);

   VEMS_vidSET(CanPurg_mfFuStmEstim, u16LocalCpc_fuel_mass_flow_rate);
   VEMS_vidSET(CanPurg_concFuStmEstim, u16LocalCpc_fuel_vapour_concentr);
   u16LocalCanPurg_ldGasFuCan =
     (uint16)((uint32)((u16LocalCpc_fuel_vapour_concentr * 625) + 2048) / 4096);
   VEMS_vidSET(CanPurg_ldGasFuCan, u16LocalCanPurg_ldGasFuCan);
   if (CanPurg_bAcvBypconcFuStmErr_C != 0)
   {
      VEMS_vidSET(CanPurg_concFuStmErr, CanPurg_concFuStmErr_BypC);
   }
   else
   {
      VEMS_vidSET(CanPurg_concFuStmErr, u16LocalCpc_fuel_vapour_conc_err);
   }
}
/*------------------------------- end of file --------------------------------*/