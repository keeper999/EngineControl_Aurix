/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AIRTHRARCRKSP                                           */
/* !Description     : AIRTHRARCRKSP component                                 */
/*                                                                            */
/* !Module          : AIRTHRARCRKSP                                           */
/* !Description     : CALCUL DE LA CONSIGNE D’AIRE PAPILLON HORS STRUCTURE    */
/*                    COUPLE                                                  */
/*                                                                            */
/* !File            : AIRTHRARCRKSP_FCT1.c                                    */
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
/*   1 / AIRTHRARCRKSP_vidInitOutput                                          */
/*   2 / AIRTHRARCRKSP_vidCompAirDenGain                                      */
/*   3 / AIRTHRARCRKSP_vidCompDtcFiCraOff                                     */
/*   4 / AIRTHRARCRKSP_vidInitDelay                                           */
/*   5 / AIRTHRARCRKSP_vidTimer                                               */
/*   6 / AIRTHRARCRKSP_vidCalcTqLoss                                          */
/*   7 / AIRTHRARCRKSP_vidCompDtcTrCoSurf                                     */
/*   8 / AIRTHRARCRKSP_vidCompDtcSection                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5074571 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/AIRTHRARCRKSP/AIRTHRARCRKSP_FCT1.C$*/
/* $Revision::   1.16     $$Author::   wbouach        $$Date::   04 Nov 2013 $*/
/* $Author::   wbouach                                $$Date::   04 Nov 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "AIRTHRARCRKSP.h"
#include "AIRTHRARCRKSP_L.h"
#include "AIRTHRARCRKSP_IM.h"
#include "VEMS.h"
#include "Std_Limits.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTHRARCRKSP_vidInitOutput                                */
/* !Description :  fonction d'initialisation des sorties                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean EngReqH_bEngRStrtAutnAvl;                                   */
/*  output uint16 Dtc_first_crank_offset;                                     */
/*  output uint16 Dtc_surf_hors_struc_couple;                                 */
/*  output uint16 Dtc_trans_couple_surf;                                      */
/*  output uint8 AIRTHRARCRKSP_u8SlewRateOutput;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTHRARCRKSP_vidInitOutput(void)
{
   boolean bLocalEngReqH_bEngRStrtAutnAvl;

   VEMS_vidSET(Dtc_first_crank_offset, 0);
   VEMS_vidSET(Dtc_surf_hors_struc_couple, 0);
   VEMS_vidSET(Dtc_trans_couple_surf, 0);
   VEMS_vidGET(EngReqH_bEngRStrtAutnAvl, bLocalEngReqH_bEngRStrtAutnAvl);
   if (bLocalEngReqH_bEngRStrtAutnAvl != 0)
   {
      AIRTHRARCRKSP_u8SlewRateOutput = 100;
   }
   else
   {
      AIRTHRARCRKSP_u8SlewRateOutput = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTHRARCRKSP_vidCompAirDenGain                            */
/* !Description :  En fonction de la température d’air et de la pression      */
/*                 atmosphérique, on calcule une correction à apporter sur la */
/*                 section papillon en mode débouclé.                         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Cf_bInhFlex;                                                */
/*  input uint16 UsThrM_pUsThrCor;                                            */
/*  input uint8 Temperature_air;                                              */
/*  input uint16 Air_density_gain_crk_pond_flex;                              */
/*  input uint8 Air_density_gain_pres_crk_flex;                               */
/*  input uint16 Air_density_gain_pres_map_bkpt[17];                          */
/*  input uint8 Air_density_gain_pres_map[17];                                */
/*  input uint8 Air_density_gain_temp_map_bkpt[17];                           */
/*  input uint8 Air_density_gain_temp_map[17];                                */
/*  output uint16 Air_density_gain;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTHRARCRKSP_vidCompAirDenGain(void)
 {
   boolean bLocalCf_bInhFlex;
   uint8   u8Localinterp1;
   uint8   u8Localinterp2;
   uint8   u8LocalTemperature_air;
   uint8   u8LocalAirDensGainPresCrkFlex;
   uint8   u8LocalFlex;
   uint16  u16LocalUsThrM_pUsThrCor;
   uint16  u16LocalAirDensGainCrkPondFlex;
   uint16  u16LocalPara;
   sint16  s16LocalGain;
   sint32  s32LocalCalc;


   VEMS_vidGET(Cf_bInhFlex, bLocalCf_bInhFlex);
   VEMS_vidGET(UsThrM_pUsThrCor, u16LocalUsThrM_pUsThrCor);
   VEMS_vidGET(Temperature_air, u8LocalTemperature_air);
   VEMS_vidGET(Air_density_gain_crk_pond_flex, u16LocalAirDensGainCrkPondFlex);
   VEMS_vidGET(Air_density_gain_pres_crk_flex, u8LocalAirDensGainPresCrkFlex);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU16(Air_density_gain_pres_map_bkpt,
                                               u16LocalUsThrM_pUsThrCor,
                                               17);
   u8Localinterp1 = MATHSRV_u8Interp1d(Air_density_gain_pres_map,
                                       u16LocalPara);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU8(Air_density_gain_temp_map_bkpt,
                                              u8LocalTemperature_air,
                                              17);
   u8Localinterp2 = MATHSRV_u8Interp1d(Air_density_gain_temp_map,
                                       u16LocalPara);
   if (bLocalCf_bInhFlex != 0)
   {
      u8LocalFlex = u8Localinterp1;
   }
   else
   {
      /*Barycentre 4*/
      if (u16LocalAirDensGainCrkPondFlex < 256)
      {
         s32LocalCalc =
            (sint32)(u8LocalAirDensGainPresCrkFlex - u8Localinterp1);
         if (s32LocalCalc >= 0)
         {
            s32LocalCalc =
               ((s32LocalCalc * u16LocalAirDensGainCrkPondFlex) + 128) / 256;
         }
         else
         {
            s32LocalCalc =
               ((s32LocalCalc * u16LocalAirDensGainCrkPondFlex) - 128) / 256;
         }
         s32LocalCalc = s32LocalCalc + u8Localinterp1;
         u8LocalFlex = (uint8)s32LocalCalc;
      }
      else
      {
         u8LocalFlex = u8LocalAirDensGainPresCrkFlex;
      }
   }
   s16LocalGain = (sint16)( ( ( (u8LocalFlex + 128) * (u8Localinterp2 + 128))
                                / 256)
                             - 128);
   Air_density_gain = (uint16)MATHSRV_udtMAX(s16LocalGain, 0);
 }

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTHRARCRKSP_vidCompDtcFiCraOff                           */
/* !Description :  Pour obtenir un profil de démarrage correct, on applique un*/
/*                 offset de section Dtc_first_crank_offset.                  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  PTS_R_507471_002.01                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void AIRTHRARCRKSP_vidInitDelay();                            */
/*  extf argret void AIRTHRARCRKSP_vidTimer();                                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Cf_bInhFlex;                                                */
/*  input uint8 Temperature_eau;                                              */
/*  input boolean CoPTSt_bRStrtSTT;                                           */
/*  input boolean Throttle_cranking_retry;                                    */
/*  input st23 Vehicle_active_state;                                          */
/*  input uint16 Dtc_trans_couple_surf;                                       */
/*  input uint16 Dtc_first_crank_offset;                                      */
/*  input uint16 Dtc_STT_crank_decay_retry_flex;                              */
/*  input uint16 Dtc_first_crank_decay_retry_flex;                            */
/*  input uint16 Dtc_first_crank_decay_flex;                                  */
/*  input sint16 Dtc_STT_crank_offset_retry_flex;                             */
/*  input sint16 Dtc_first_crank_offset_rtry_flex;                            */
/*  input sint16 Dtc_first_crank_offset_flex;                                 */
/*  input uint16 Dtc_crank_offset_pond_flex;                                  */
/*  input uint16 Dtc_crank_decay_pond_flex;                                   */
/*  input uint8 Temperature_eau_bkpt_map[16];                                 */
/*  input uint8 Dtc_first_crank_offset_delay;                                 */
/*  input uint16 Dtc_STT_crank_offset_retry_map[16];                          */
/*  input uint16 Dtc_STT_crank_decay_retry_map[16];                           */
/*  input uint16 Dtc_first_crank_offset_retry_map[16];                        */
/*  input uint16 Dtc_first_crank_decay_retry_map[16];                         */
/*  input uint16 Dtc_first_crank_offset_map[16];                              */
/*  input uint16 Dtc_first_crank_decay_map[16];                               */
/*  input uint16 Dtc_first_crank_decay_step;                                  */
/*  output uint16 Dtc_first_crank_decay_step;                                 */
/*  output uint8 Dtc_first_crank_offset_torque;                               */
/*  output uint16 Dtc_first_crank_offset;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTHRARCRKSP_vidCompDtcFiCraOff(void)
 {
   boolean bLocalThrottle_cranking_retry;
   boolean bLocalCoPTSt_bRStrtSTT;
   boolean bLocalCf_bInhFlex;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalVehicle_active_state;
   uint16  u16LocalPara;
   uint16  u16LocalDtc_first_crank_offset;
   uint16  u16LocalDtc_trans_couple_surf;
   uint16  u16LocalDtcSTTCrankDecayRetFlex;
   uint16  u16LocalDtcFstCrkDecayRetryFlex;
   uint16  u16LocalDtcFirstCrankDecayFlex;
   uint16  u16LocalDtcCrkOffsetPondFlex;
   uint16  u16LocalDtcCrankDecayPondFlex;
   uint16  u16LocalInterp1;
   uint16  u16LocalInterp2;
   uint16  u16LocalBary1Rate;
   uint16  u16LocalBary2Rate;
   sint16  s16LocalDtcFirstCrankOffsetFlex;
   sint16  s16LocalDtcSTTCrankOffsetRetFlex;
   sint16  s16LocalDtcFirstCrankOffRtryFlex;
   uint32  u32LocalOffsetTorque;
   sint32  s32LocalCrank;
   sint32  s32LocalBary1In1;
   sint32  s32LocalBary2In1;
   sint32  s32LocalCalc;


   VEMS_vidGET(Cf_bInhFlex, bLocalCf_bInhFlex);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(CoPTSt_bRStrtSTT, bLocalCoPTSt_bRStrtSTT);
   VEMS_vidGET(Throttle_cranking_retry, bLocalThrottle_cranking_retry);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Dtc_trans_couple_surf, u16LocalDtc_trans_couple_surf);
   VEMS_vidGET(Dtc_first_crank_offset, u16LocalDtc_first_crank_offset);
   VEMS_vidGET(Dtc_STT_crank_decay_retry_flex, u16LocalDtcSTTCrankDecayRetFlex);
   VEMS_vidGET(Dtc_first_crank_decay_retry_flex
              ,u16LocalDtcFstCrkDecayRetryFlex);
   VEMS_vidGET(Dtc_first_crank_decay_flex, u16LocalDtcFirstCrankDecayFlex);
   VEMS_vidGET(Dtc_STT_crank_offset_retry_flex
              ,s16LocalDtcSTTCrankOffsetRetFlex);
   VEMS_vidGET(Dtc_first_crank_offset_rtry_flex
              ,s16LocalDtcFirstCrankOffRtryFlex);
   VEMS_vidGET(Dtc_first_crank_offset_flex, s16LocalDtcFirstCrankOffsetFlex);
   VEMS_vidGET(Dtc_crank_offset_pond_flex, u16LocalDtcCrkOffsetPondFlex);
   VEMS_vidGET(Dtc_crank_decay_pond_flex, u16LocalDtcCrankDecayPondFlex);
   if (u8LocalVehicle_active_state == VS_CRANKING )
   {
      AIRTHRARCRKSP_vidInitDelay();
   }
   if (u8LocalVehicle_active_state == VS_RUNNING)
   {
      AIRTHRARCRKSP_vidTimer();
   }
   u16LocalPara = MATHSRV_u16CalcParaIncAryU8(Temperature_eau_bkpt_map,
                                              u8LocalTemperature_eau,16);

   u16LocalBary1Rate = u16LocalDtcCrkOffsetPondFlex;
   u16LocalBary2Rate = u16LocalDtcCrankDecayPondFlex;

   if (Dtc_first_crank_offset_delay != 0)
   {
      if (bLocalCoPTSt_bRStrtSTT != 0)
      {
         u16LocalInterp1 =  MATHSRV_u16Interp1d(Dtc_STT_crank_offset_retry_map,
                                                u16LocalPara);
         s32LocalBary1In1 = (sint32)s16LocalDtcSTTCrankOffsetRetFlex;
         u16LocalInterp2 =  MATHSRV_u16Interp1d(Dtc_STT_crank_decay_retry_map,
                                                u16LocalPara);
         s32LocalBary2In1 = (sint32)u16LocalDtcSTTCrankDecayRetFlex;
      }
      else
      {
         if (bLocalThrottle_cranking_retry != 0)
         {
            u16LocalInterp1 =
               MATHSRV_u16Interp1d(Dtc_first_crank_offset_retry_map,
                                   u16LocalPara);
            s32LocalBary1In1 = (sint32)s16LocalDtcFirstCrankOffRtryFlex;
            u16LocalInterp2 =
               MATHSRV_u16Interp1d(Dtc_first_crank_decay_retry_map,
                                   u16LocalPara);
            s32LocalBary2In1 = (sint32)u16LocalDtcFstCrkDecayRetryFlex;
         }
         else
         {
            u16LocalInterp1 =  MATHSRV_u16Interp1d(Dtc_first_crank_offset_map,
                                                u16LocalPara);
            s32LocalBary1In1 = (sint32)s16LocalDtcFirstCrankOffsetFlex;
            u16LocalInterp2 =  MATHSRV_u16Interp1d(Dtc_first_crank_decay_map,
                                                   u16LocalPara);
            s32LocalBary2In1 = (sint32)u16LocalDtcFirstCrankDecayFlex;
         }
      }

      if (bLocalCf_bInhFlex != 0)
      {
         s32LocalCalc = (sint32)u16LocalInterp1;
      }
      else
      {
         /*Barycentre 1 */
         if (u16LocalBary1Rate < 256)
         {
            s32LocalCalc = s32LocalBary1In1 - u16LocalInterp1;
            if (s32LocalCalc >= 0)
            {
               s32LocalCalc = (( s32LocalCalc
                              * u16LocalBary1Rate) + 128) / 256;
            }
            else
            {
               s32LocalCalc = (( s32LocalCalc
                              * u16LocalBary1Rate) - 128) / 256;
            }
            s32LocalCalc = s32LocalCalc + u16LocalInterp1;
         }
         else
         {
            s32LocalCalc = s32LocalBary1In1;
         }
      }
      u16LocalDtc_first_crank_offset = (uint16)MATHSRV_udtMAX(s32LocalCalc, 0);

      if (bLocalCf_bInhFlex != 0)
      {
         s32LocalCalc = (sint32)u16LocalInterp2;
      }
      else
      {
         /*Barycentre 2 */
         if (u16LocalBary2Rate < 256)
         {
            s32LocalCalc = s32LocalBary2In1 - u16LocalInterp2;
            if (s32LocalCalc >= 0)
            {
               s32LocalCalc = (( s32LocalCalc
                              * u16LocalBary2Rate) + 128) / 256;
            }
            else
            {
               s32LocalCalc = (( s32LocalCalc
                              * u16LocalBary2Rate) - 128) / 256;
            }
            s32LocalCalc = s32LocalCalc + u16LocalInterp2;
         }
         else
         {
            s32LocalCalc = s32LocalBary2In1;
         }
      }
      Dtc_first_crank_decay_step = (uint16)s32LocalCalc;
   }
   else
   {
      if (bLocalCoPTSt_bRStrtSTT != 0)
      {
         u16LocalInterp2 =  MATHSRV_u16Interp1d(Dtc_STT_crank_decay_retry_map,
                                                u16LocalPara);
         s32LocalBary2In1 = (sint32)u16LocalDtcSTTCrankDecayRetFlex;
      }
      else
      {
         if (bLocalThrottle_cranking_retry != 0)
         {
            u16LocalInterp2 =
               MATHSRV_u16Interp1d(Dtc_first_crank_decay_retry_map,
                                   u16LocalPara);
            s32LocalBary2In1 = (sint32)u16LocalDtcFstCrkDecayRetryFlex;
         }
         else
         {
            u16LocalInterp2 =  MATHSRV_u16Interp1d(Dtc_first_crank_decay_map,
                                                   u16LocalPara);
            s32LocalBary2In1 = (sint32)u16LocalDtcFirstCrankDecayFlex;
         }
      }

      if (bLocalCf_bInhFlex != 0)
      {
         s32LocalCalc = (sint32)u16LocalInterp2;
      }
      else
      {
         /*Barycentre 2 */
         if (u16LocalBary2Rate < 256)
         {
            s32LocalCalc = s32LocalBary2In1 - u16LocalInterp2;
            if (s32LocalCalc >= 0)
            {
               s32LocalCalc = (( s32LocalCalc
                              * u16LocalBary2Rate) + 128) / 256;
            }
            else
            {
               s32LocalCalc = (( s32LocalCalc
                              * u16LocalBary2Rate) - 128) / 256;
            }
            s32LocalCalc = s32LocalCalc + u16LocalInterp2;
         }
         else
         {
            s32LocalCalc = s32LocalBary2In1;
         }
      }
      Dtc_first_crank_decay_step = (uint16)s32LocalCalc;

      s32LocalCrank = (sint32)(u16LocalDtc_first_crank_offset
                              - Dtc_first_crank_decay_step);
      u16LocalDtc_first_crank_offset =(uint16)MATHSRV_udtMAX(s32LocalCrank, 0);
   }

   if (u16LocalDtc_trans_couple_surf == 0)
   {
      Dtc_first_crank_offset_torque = 0XFF;
   }
   else
   {
      u32LocalOffsetTorque =(uint32)((u16LocalDtc_first_crank_offset * 2048)
                                    /u16LocalDtc_trans_couple_surf);
      Dtc_first_crank_offset_torque =(uint8)MATHSRV_udtMIN(u32LocalOffsetTorque,
                                                           255);
   }
   VEMS_vidSET(Dtc_first_crank_offset, u16LocalDtc_first_crank_offset);
 }

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTHRARCRKSP_vidInitDelay                                 */
/* !Description :  initialisation.                                            */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Cf_bInhFlex;                                                */
/*  input uint8 Temperature_eau;                                              */
/*  input boolean CoPTSt_bRStrtSTT;                                           */
/*  input boolean Throttle_cranking_retry;                                    */
/*  input uint16 Dtc_crank_delay_pond_flex;                                   */
/*  input uint8 Dtc_first_crank_delay_flex;                                   */
/*  input uint8 Dtc_first_crank_delay_retry_flex;                             */
/*  input uint8 Dtc_STT_crank_delay_retry_flex;                               */
/*  input uint16 UsThrM_pUsThrCor;                                            */
/*  input uint8 Temperature_eau_bkpt_map[16];                                 */
/*  input uint16 Air_density_gain_pres_map_bkpt[17];                          */
/*  input uint16 EngSt_rGainSpThrFctPAir_M[17];                               */
/*  input uint8 Dtc_STT_crank_delay_retry_map[16];                            */
/*  input uint8 Dtc_first_crank_delay_retry_map[16];                          */
/*  input uint8 Dtc_first_crank_delay_map[16];                                */
/*  input uint16 EngSt_rGainSpThrFctPAir;                                     */
/*  output uint16 EngSt_rGainSpThrFctPAir;                                    */
/*  output uint8 Dtc_first_crank_offset_delay;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTHRARCRKSP_vidInitDelay(void)
{
   boolean bLocalThrottle_cranking_retry;
   boolean bLocalCoPTSt_bRStrtSTT;
   boolean bLocalCf_bInhFlex;
   boolean bLocalSwitch;
   uint8   u8Localinterp;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalDtcSTTCrankDelayRetryFlex;
   uint8   u8LocalDtcFirstCrkDlyRetryFlex;
   uint8   u8LocalDtcFirstCrankDelayFlex;
   uint8   u8LocalFlex;
   uint8   u8LocalBarycentreIn1;
   uint16  u16LocalDtcCrankDelayPondFlex;
   uint16  u16LocalPara;
   uint16  u16LocalUsThrM_pUsThrCor;
   uint16  u16LocalPara1;
   uint16  u16Localinterp1;
   uint32  u32LocalBarycentreIn2;
   sint32  s32LocalCalc;


   bLocalSwitch = 1;
   VEMS_vidGET(Cf_bInhFlex, bLocalCf_bInhFlex);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(CoPTSt_bRStrtSTT, bLocalCoPTSt_bRStrtSTT);
   VEMS_vidGET(Throttle_cranking_retry, bLocalThrottle_cranking_retry);
   VEMS_vidGET(Dtc_crank_delay_pond_flex, u16LocalDtcCrankDelayPondFlex);
   VEMS_vidGET(Dtc_first_crank_delay_flex, u8LocalDtcFirstCrankDelayFlex);
   VEMS_vidGET(Dtc_first_crank_delay_retry_flex
               , u8LocalDtcFirstCrkDlyRetryFlex);
   VEMS_vidGET(Dtc_STT_crank_delay_retry_flex
               , u8LocalDtcSTTCrankDelayRetryFlex);
   VEMS_vidGET(UsThrM_pUsThrCor, u16LocalUsThrM_pUsThrCor);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU8(Temperature_eau_bkpt_map,
                                              u8LocalTemperature_eau,
                                              16);

   u16LocalPara1 = MATHSRV_u16CalcParaIncAryU16(Air_density_gain_pres_map_bkpt,
                                                u16LocalUsThrM_pUsThrCor,
                                                17);
   u16Localinterp1 =
      MATHSRV_u16Interp1d(EngSt_rGainSpThrFctPAir_M, u16LocalPara1);
   EngSt_rGainSpThrFctPAir = (uint16)MATHSRV_udtCLAMP(u16Localinterp1 , 1, 256);

   if (bLocalCoPTSt_bRStrtSTT != 0)
   {
      u8Localinterp = MATHSRV_u8Interp1d(Dtc_STT_crank_delay_retry_map,
                                         u16LocalPara);
      u8LocalBarycentreIn1 = u8LocalDtcSTTCrankDelayRetryFlex;
   }
   else
   {
      if (bLocalThrottle_cranking_retry !=0 )
      {
         u8Localinterp = MATHSRV_u8Interp1d(Dtc_first_crank_delay_retry_map,
                                            u16LocalPara);
         u8LocalBarycentreIn1 = u8LocalDtcFirstCrkDlyRetryFlex;
      }
      else
      {
         bLocalSwitch = 0;

         u8Localinterp = MATHSRV_u8Interp1d(Dtc_first_crank_delay_map,
                                           u16LocalPara);
         u8LocalBarycentreIn1 = u8LocalDtcFirstCrankDelayFlex;
         u32LocalBarycentreIn2 =
            (uint32)( ((EngSt_rGainSpThrFctPAir * u8Localinterp * 5) + 64)
                    / 128);
      }
   }
   if (bLocalSwitch != 0)
   {
      if (bLocalCf_bInhFlex != 0)
      {
         u8LocalFlex = u8Localinterp;
      }
      else
      {
         if (u16LocalDtcCrankDelayPondFlex < 256)
         {
            s32LocalCalc =
               (sint32)(u8LocalBarycentreIn1 - u8Localinterp);
            if (s32LocalCalc >= 0)
            {
               s32LocalCalc =
                  ((s32LocalCalc * u16LocalDtcCrankDelayPondFlex) + 128) / 256;
            }
            else
            {
               s32LocalCalc =
                  ((s32LocalCalc * u16LocalDtcCrankDelayPondFlex) - 128) / 256;
            }
            s32LocalCalc = s32LocalCalc + u8Localinterp;
            u8LocalFlex = (uint8)s32LocalCalc;
         }
         else
         {
            u8LocalFlex = u8LocalBarycentreIn1;
         }
      }
   }
   else
   {
      if (bLocalCf_bInhFlex != 0)
      {
         /* Erreur QAC Msg(2:3353): u32LocalBarycentreIn2 n'est produite et
         consommée que si bLocalSwitch = 0*/
         u8LocalFlex = (uint8)MATHSRV_udtMIN(u32LocalBarycentreIn2, 255);
      }
      else
      {
         if (u16LocalDtcCrankDelayPondFlex < 256)
         {
            s32LocalCalc =
               (sint32)(u8LocalBarycentreIn1 - u32LocalBarycentreIn2);
            if (s32LocalCalc >= 0)
            {
               s32LocalCalc =
                  ( (s32LocalCalc * u16LocalDtcCrankDelayPondFlex) + 128)
                  / 256;
            }
            else
            {
               s32LocalCalc =
                  ( (s32LocalCalc * u16LocalDtcCrankDelayPondFlex) - 128)
                  / 256;
            }
            s32LocalCalc = s32LocalCalc + (sint32)u32LocalBarycentreIn2;
            u8LocalFlex = (uint8)MATHSRV_udtMIN(s32LocalCalc, 255);
         }
         else
         {
            u8LocalFlex = u8LocalBarycentreIn1;
         }
      }
   }
   Dtc_first_crank_offset_delay = (uint8)MATHSRV_udtMIN(u8LocalFlex, 250);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTHRARCRKSP_vidTimer                                     */
/* !Description :  decrementer la de delai du crank offset                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Dtc_first_crank_offset_delay;                                 */
/*  output uint8 Dtc_first_crank_offset_delay;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTHRARCRKSP_vidTimer(void)
{
   if (Dtc_first_crank_offset_delay !=0)
   {
      Dtc_first_crank_offset_delay = (uint8)(Dtc_first_crank_offset_delay - 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTHRARCRKSP_vidCalcTqLoss                                */
/* !Description :  Les pertes de couple suivantes sont transformés en surface */
/*                 papillon et prises en compte en structure couple débouclée */
/*                 : pertes accessoires, Pertes BVA, réserve de couple,       */
/*                 adaptatif frottement.                                      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 TqRes_tqMaxRes;                                              */
/*  input sint16 TqCmp_tqSumLossCmp;                                          */
/*  input uint16 TqSys_tqCkEngLoss;                                           */
/*  input boolean CrkMgt_bInhCkEngLoss_C;                                     */
/*  output sint16 CrkMgt_tqLoss_ThrArCrkAdp;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTHRARCRKSP_vidCalcTqLoss(void)
{
   uint16 u16LocalTqSys_tqCkEngLoss;
   sint16 s16LocalTqRes_tqMaxRes;
   sint16 s16LocalTqCmp_tqSumLossCmp;
   sint32 s32LocalCalcTqLoss;


   VEMS_vidGET(TqRes_tqMaxRes, s16LocalTqRes_tqMaxRes);
   VEMS_vidGET(TqCmp_tqSumLossCmp, s16LocalTqCmp_tqSumLossCmp);
   VEMS_vidGET(TqSys_tqCkEngLoss, u16LocalTqSys_tqCkEngLoss);

   s32LocalCalcTqLoss = (sint32)( s16LocalTqCmp_tqSumLossCmp
                                + s16LocalTqRes_tqMaxRes);
   if (CrkMgt_bInhCkEngLoss_C == 0)
   {
      CrkMgt_tqLoss_ThrArCrkAdp = (sint16)MATHSRV_udtCLAMP(s32LocalCalcTqLoss,
                                                           -32000,
                                                           32000);
   }
   else
   {
      s32LocalCalcTqLoss = s32LocalCalcTqLoss - u16LocalTqSys_tqCkEngLoss;
      CrkMgt_tqLoss_ThrArCrkAdp = (sint16)MATHSRV_udtCLAMP(s32LocalCalcTqLoss,
                                                           -32000,
                                                           32000);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTHRARCRKSP_vidCompDtcTrCoSurf                           */
/* !Description :  La cartographie Dtc_trans_couple_surf_map doit être        */
/*                 calibrée précisément afin d’obtenir une régulation de      */
/*                 ralenti correcte en mode recopie pédale.                   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint16 Dtc_trans_couple_surf_map[16];                               */
/*  output uint16 Dtc_trans_couple_surf;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTHRARCRKSP_vidCompDtcTrCoSurf(void)
{
   uint16 u16LocalRegMot;
   uint16 u16LocalParaX;
   uint16 u16LocalRegime_moteur;
   uint16 u16LocalDtc_trans_couple_surf;


   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   u16LocalRegMot = (uint16)MATHSRV_udtMIN((u16LocalRegime_moteur * 8),65535);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                                u16LocalRegMot,
                                                16);
   u16LocalDtc_trans_couple_surf =
      MATHSRV_u16Interp1d(Dtc_trans_couple_surf_map, u16LocalParaX);
   VEMS_vidSET(Dtc_trans_couple_surf, u16LocalDtc_trans_couple_surf);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTHRARCRKSP_vidCompDtcSection                            */
/* !Description :  En fonction de la position pédale et de la température     */
/*                 d’eau et d’huile et des différents consommateurs, une      */
/*                 section efficace hors structure couple est calculée.       */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoEs_bAcvThrSysSTTEs;                                       */
/*  input uint16 Regime_moteur;                                               */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input uint8 Dv_position_pedale_relative;                                  */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 Temperature_eau_a_stall;                                      */
/*  input uint16 Dtc_first_crank_offset;                                      */
/*  input uint16 Dtc_trans_couple_surf;                                       */
/*  input boolean CoPTSt_bRStrtSTT;                                           */
/*  input boolean EngReqH_bEngRStrtAutnAvl;                                   */
/*  input boolean Clef_de_contact;                                            */
/*  input sint16 Dtc_first_crank_offset_crk;                                  */
/*  input boolean Dtc_deboucle_config_toil;                                   */
/*  input uint8 Dtc_facTranRStrtAuth_C;                                       */
/*  input uint8 AIRTHRARCRKSP_u8SlewRateOutput;                               */
/*  input boolean CrkMng_bAcvThrClsEngStop_C;                                 */
/*  input uint16 Dtc_surf_stop_nEng_bkpt_map[16];                             */
/*  input uint16 Dtc_surf_stop_map[16];                                       */
/*  input uint16 Dtc_surf_STT_nEng_bkpt_map[16];                              */
/*  input uint16 Dtc_surf_STT_stop_map[16];                                   */
/*  input uint16 Dtc_surf_STT_stop_RStrtInh_map[16];                          */
/*  input uint8 Dv_surf_pos_ped_bkpt_map[16];                                 */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint8 Temperature_eau_bkpt_map[16];                                 */
/*  input uint8 Toil_or_teau_bkpt_map[16];                                    */
/*  input uint8 Dtc_toil_or_teau;                                             */
/*  input uint16 Dtc_dv_surf_STT_map[16][16];                                 */
/*  input uint16 Dtc_teau_toil_surf_STT_map[16][16];                          */
/*  input uint16 Dtc_dv_surf_deboucle_map[16][16];                            */
/*  input uint16 Dtc_teau_toil_surf_deboucle_map[16][16];                     */
/*  input sint16 CrkMgt_tqLoss_ThrArCrkAdp;                                   */
/*  input uint16 Air_density_gain;                                            */
/*  output uint8 Dtc_toil_or_teau;                                            */
/*  output uint8 AIRTHRARCRKSP_u8SlewRateOutput;                              */
/*  output uint16 Dtc_surf_hors_struc_couple;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTHRARCRKSP_vidCompDtcSection(void)
{
   boolean bLocalCoPTSt_bRStrtSTT;
   boolean bLocalCoEs_bAcvThrSysSTTEs;
   boolean bLocalEngReqH_bEngRStrtAutnAvl;
   boolean bLocalEClef_de_contact;
   uint8   u8LocalDv_pos_pedale_relative;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalTemperature_eau_a_stall;
   uint8   u8LocalDiff;
   uint8   u8LocalMeasuredValue;
   uint8   u8LocalDtc_facTranRStrtAuth_C;
   uint8   u8LocalCalc;
   uint16  u16LocalPara;
   uint16  u16LocalRegMot;
   uint16  u16LocalParaX;
   uint16  u16LocalParaX2;
   uint16  u16LocalParaY;
   uint16  u16LocalParaY2;
   uint16  u16Localinterp1;
   uint16  u16Localinterp2;
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalDtc_first_crank_offset;
   uint16  u16LocalDtc_trans_couple_surf;
   uint16  u16LocalDtc_surf_hs_strc_cple;
   uint16  u16LocalDtcSurfSTT_stop;
   uint16  u16LocalDtcSurfSTT_stop_RStrtInh;
   sint16  s16LocalEng_tOilEstim;
   sint16  s16LocalDtcFirstCrankOffsetCrk;
   sint32  s32LocalData;
   uint32  u32LocalProd1;
   uint32  u32LocalProd2;
   uint32  u32LocalDtc_surf_hs_strc_cple;
   uint32  u32LocalSomme;
   uint32  u32LocalData;
   uint32  u32LocalDiv;


   VEMS_vidGET(CoEs_bAcvThrSysSTTEs, bLocalCoEs_bAcvThrSysSTTEs);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);
   VEMS_vidGET(Dv_position_pedale_relative, u8LocalDv_pos_pedale_relative);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(Temperature_eau_a_stall, u8LocalTemperature_eau_a_stall);
   VEMS_vidGET(Dtc_first_crank_offset, u16LocalDtc_first_crank_offset);
   VEMS_vidGET(Dtc_trans_couple_surf, u16LocalDtc_trans_couple_surf);
   VEMS_vidGET(CoPTSt_bRStrtSTT, bLocalCoPTSt_bRStrtSTT);
   VEMS_vidGET(EngReqH_bEngRStrtAutnAvl, bLocalEngReqH_bEngRStrtAutnAvl);
   VEMS_vidGET(Clef_de_contact, bLocalEClef_de_contact);
   VEMS_vidGET(Dtc_first_crank_offset_crk, s16LocalDtcFirstCrankOffsetCrk);

   if (Dtc_deboucle_config_toil != 0)
   {
      Dtc_toil_or_teau =
         (uint8)MATHSRV_udtCLAMP(((s16LocalEng_tOilEstim / 4) + 40),
                                 0,
                                 255);
   }
   else
   {
      Dtc_toil_or_teau = (uint8)((u8LocalTemperature_eau_a_stall * 160) / 256);
   }

   u16LocalRegMot = (uint16)MATHSRV_udtMIN((u16LocalRegime_moteur * 8), 65535);

   if (bLocalEngReqH_bEngRStrtAutnAvl != 0)
   {
      u8LocalMeasuredValue = 100;
   }
   else
   {
      u8LocalMeasuredValue = 0;
   }

   u8LocalDtc_facTranRStrtAuth_C =
      (uint8)(((Dtc_facTranRStrtAuth_C * 25) + 32) / 64);
   u8LocalCalc = MATHSRV_u8SlewFilter(AIRTHRARCRKSP_u8SlewRateOutput,
                                      u8LocalMeasuredValue,
                                      u8LocalDtc_facTranRStrtAuth_C,
                                      u8LocalDtc_facTranRStrtAuth_C);
   AIRTHRARCRKSP_u8SlewRateOutput = (uint8)MATHSRV_udtMIN(u8LocalCalc, 100);

   if (  (CrkMng_bAcvThrClsEngStop_C != 0)
      && (bLocalEClef_de_contact == 0))
   {
      u16LocalPara = MATHSRV_u16CalcParaIncAryU16(Dtc_surf_stop_nEng_bkpt_map,
                                                  u16LocalRegMot,
                                                  16);
      u16LocalDtc_surf_hs_strc_cple = MATHSRV_u16Interp1d(Dtc_surf_stop_map,
                                                          u16LocalPara);
   }
   else
   {
      if (bLocalCoEs_bAcvThrSysSTTEs != 0)
      {
         u16LocalPara = MATHSRV_u16CalcParaIncAryU16(Dtc_surf_STT_nEng_bkpt_map,
                                                     u16LocalRegMot,
                                                     16);
         u16LocalDtcSurfSTT_stop = MATHSRV_u16Interp1d(Dtc_surf_STT_stop_map,
                                                       u16LocalPara);
         u16LocalDtcSurfSTT_stop_RStrtInh =
            MATHSRV_u16Interp1d(Dtc_surf_STT_stop_RStrtInh_map, u16LocalPara);
         /*Barycentre */
         if (  (AIRTHRARCRKSP_u8SlewRateOutput > 0)
            && (AIRTHRARCRKSP_u8SlewRateOutput < 100))
         {
            u32LocalProd1 = (uint32)( u16LocalDtcSurfSTT_stop
                                    * AIRTHRARCRKSP_u8SlewRateOutput);
            u8LocalDiff = (uint8)(100 - AIRTHRARCRKSP_u8SlewRateOutput);
            u32LocalProd2 =
               (uint32)(u16LocalDtcSurfSTT_stop_RStrtInh * u8LocalDiff);
            u32LocalDtc_surf_hs_strc_cple = u32LocalProd1 + u32LocalProd2;
            u16LocalDtc_surf_hs_strc_cple =
               (uint16)((u32LocalDtc_surf_hs_strc_cple + 50) / 100);
         }
         else
         {
            if (AIRTHRARCRKSP_u8SlewRateOutput == 0)
            {
               u16LocalDtc_surf_hs_strc_cple = u16LocalDtcSurfSTT_stop_RStrtInh;
            }
            else
            {
               u16LocalDtc_surf_hs_strc_cple = u16LocalDtcSurfSTT_stop;
            }
         }
      }
      else
      {
         u16LocalParaY =
            MATHSRV_u16CalcParaIncAryU8(Dv_surf_pos_ped_bkpt_map,
                                        u8LocalDv_pos_pedale_relative,
                                        16);
         u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                                      u16LocalRegMot,
                                                      16);
         u16LocalParaX2 = MATHSRV_u16CalcParaIncAryU8(Temperature_eau_bkpt_map,
                                                      u8LocalTemperature_eau,
                                                      16);
         u16LocalParaY2 = MATHSRV_u16CalcParaIncAryU8(Toil_or_teau_bkpt_map,
                                                      Dtc_toil_or_teau,
                                                      16);
         if (bLocalCoPTSt_bRStrtSTT != 0)
         {
            u16Localinterp1 = MATHSRV_u16Interp2d(&Dtc_dv_surf_STT_map[0][0],
                                                  u16LocalParaX,
                                                  u16LocalParaY,
                                                  16);
            u16Localinterp2 =
               MATHSRV_u16Interp2d(&Dtc_teau_toil_surf_STT_map[0][0],
                                   u16LocalParaX2,
                                   u16LocalParaY2,
                                   16);
         }
         else
         {
            u16Localinterp1 =
               MATHSRV_u16Interp2d(&Dtc_dv_surf_deboucle_map[0][0],
                                   u16LocalParaX,
                                   u16LocalParaY,
                                   16);

            u16Localinterp2 =
               MATHSRV_u16Interp2d(&Dtc_teau_toil_surf_deboucle_map[0][0],
                                   u16LocalParaX2,
                                   u16LocalParaY2,
                                   16);
         }
         s32LocalData = (sint32)( u16LocalDtc_first_crank_offset
                                + ( ( CrkMgt_tqLoss_ThrArCrkAdp
                                    * u16LocalDtc_trans_couple_surf)
                                  / 4096));
         s32LocalData = s32LocalData + s16LocalDtcFirstCrankOffsetCrk;
         s32LocalData = (u16Localinterp1 + u16Localinterp2 + s32LocalData);

         u32LocalSomme = (uint32)(Air_density_gain + 128);
         if (s32LocalData < -4)
         {
            u32LocalData = 0;
         }
         else
         {
            if(s32LocalData < 0)
            {
               if(u32LocalSomme >= 512)
               {
                  u32LocalData = 0;
               }
               else
               {
                  s32LocalData = s32LocalData * (sint32)u32LocalSomme;
                  if (s32LocalData <= -512)
                  {
                     u32LocalData = 0;
                  }
                  else
                  {
                     u32LocalData =(uint32)( (s32LocalData + 512) / 256);
                  }
               }
            }
            else
            {
               u32LocalData = (uint32)s32LocalData;
               u32LocalDiv = 4294966783UL/ u32LocalSomme;
               if (u32LocalData > u32LocalDiv)
               {
                  u32LocalData = 65535;
               }
               else
               {
                  u32LocalData = ((u32LocalData * u32LocalSomme) + 512) / 256;
               }
            }
         }
         u16LocalDtc_surf_hs_strc_cple = (uint16)MATHSRV_udtMIN(u32LocalData,
                                                                  65535);
      }
   }
   VEMS_vidSET(Dtc_surf_hors_struc_couple, u16LocalDtc_surf_hs_strc_cple);
}
/*------------------------------- end of file --------------------------------*/