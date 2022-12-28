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
/* !File            : CSTRFUCONCESTIM_FCT1.C                                  */
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
/*   1 / CSTRFUCONCESTIM_vidInitialization                                    */
/*   2 / CSTRFUCONCESTIM_vidStallTi                                           */
/*   3 / CSTRFUCONCESTIM_vidCrk2RunIni                                        */
/*   4 / CSTRFUCONCESTIM_vidEstimMng                                          */
/*   5 / CSTRFUCONCESTIM_vidFuEstim                                           */
/*   6 / CSTRFUCONCESTIM_vidOplConc                                           */
/*   7 / CSTRFUCONCESTIM_vidOplConcEstim                                      */
/*   8 / CSTRFUCONCESTIM_NVMSRV_vidInit                                       */
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
/* !Function    :  CSTRFUCONCESTIM_vidInitialization                          */
/* !Description :  Fonction d'initialisation au reset.                        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_E_09_01206_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Cpc_fuel_vapour_conc_err_init;                                */
/*  output uint16 Cpc_fuel_vapour_conc_err;                                   */
/*  output uint32 CSTRFUCONCESTIM_u32FuelFilterMem;                           */
/*  output uint16 Cpc_fuel_mass_flow_rate;                                    */
/*  output uint16 CanPurg_mFuEstim;                                           */
/*  output uint8 Cpc_init_after_stall_count;                                  */
/*  output uint16 Cpc_conc_open_loop_step;                                    */
/*  output boolean CSTRFUCONCESTIM_CalresetPrev;                              */
/*  output boolean CSTRFUCONCESTIM_CalreseterPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRFUCONCESTIM_vidInitialization(void)
{
   uint16  u16LocalCpcfuelvapconcerr;


   u16LocalCpcfuelvapconcerr = (uint16)(256 * Cpc_fuel_vapour_conc_err_init);
   VEMS_vidSET(Cpc_fuel_vapour_conc_err, u16LocalCpcfuelvapconcerr);
   CSTRFUCONCESTIM_u32FuelFilterMem =
      (uint32)(u16LocalCpcfuelvapconcerr * 65536);

   VEMS_vidSET(Cpc_fuel_mass_flow_rate, 0);
   VEMS_vidSET(CanPurg_mFuEstim, 0);
   Cpc_init_after_stall_count = 0;
   Cpc_conc_open_loop_step = 0;
   CSTRFUCONCESTIM_CalresetPrev = 0;
   CSTRFUCONCESTIM_CalreseterPrev = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRFUCONCESTIM_vidStallTi                                 */
/* !Description :  Fonction agissant sur le compteur                          */
/*                 Cpc_init_after_stall_count selon l'état de VS.             */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st23 Vehicle_active_state;                                          */
/*  input uint8 Cpc_init_after_stall_delay;                                   */
/*  input uint8 Cpc_init_after_stall_count;                                   */
/*  output uint8 Cpc_init_after_stall_count;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRFUCONCESTIM_vidStallTi(void)
{
   uint8   u8LocalVehicle_active_state;
   sint16  s16LocalMax;


   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   if (u8LocalVehicle_active_state == VS_RUNNING)
   {
      Cpc_init_after_stall_count =
         (uint8)MATHSRV_udtMIN(Cpc_init_after_stall_delay, 249);
   }
   else
   {
      s16LocalMax = (sint16)(Cpc_init_after_stall_count - 1);
      Cpc_init_after_stall_count =
         (uint8)((sint16)MATHSRV_udtMAX(s16LocalMax, 0));
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRFUCONCESTIM_vidCrk2RunIni                              */
/* !Description :  Fonction d'affectation des valeurs du calculateur lors d'un*/
/*                 calage.                                                    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Cpc_init_after_stall_count;                                   */
/*  input uint8 Cpc_fuel_vapour_conc_err_init;                                */
/*  output uint16 Cpc_fuel_vapour_conc_err;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRFUCONCESTIM_vidCrk2RunIni(void)
{
   uint16  u16LocalCpc_fuel_vapour_conc_err;


   if (Cpc_init_after_stall_count == 0)
   {
      u16LocalCpc_fuel_vapour_conc_err =
         (uint16)(256 * Cpc_fuel_vapour_conc_err_init);
      VEMS_vidSET(Cpc_fuel_vapour_conc_err, u16LocalCpc_fuel_vapour_conc_err);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRFUCONCESTIM_vidEstimMng                                */
/* !Description :  Fonction de supervision du calcul de l'estimateur.         */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bEngTrbMode;                                            */
/*  input uint16 Io_map_manifold_press_measured;                              */
/*  input uint16 Atmospheric_pressure;                                        */
/*  input boolean Conditions_for_feedback;                                    */
/*  input uint16 InM_rAirPres;                                                */
/*  input uint16 Cpc_current_purge_ratio;                                     */
/*  input uint16 Obj_rich_en_regulation_richesse;                             */
/*  input st23 Vehicle_active_state;                                          */
/*  input uint16 Cpc_estim_inh_pres_ratio_thresh;                             */
/*  input uint16 Cpc_purge_ratio_estim_min;                                   */
/*  input uint16 Cstr_rMixtSpMaxThd_C;                                        */
/*  input uint16 Cstr_rMixtSpMinThd_C;                                        */
/*  input uint16 CanPurg_rAirPresPurgVlv;                                     */
/*  input uint16 Cstr_rAirPresBoostZoneThd_C;                                 */
/*  input boolean Cstr_bOplPurgeCdn;                                          */
/*  input boolean Cstr_bBoostPresZone;                                        */
/*  input boolean Cstr_bAcvBoostPresCond_C;                                   */
/*  output boolean Cstr_bOplPurgeCdn;                                         */
/*  output uint16 CanPurg_rAirPresPurgVlv;                                    */
/*  output boolean Cstr_bBoostPresZone;                                       */
/*  output boolean Cstr_bEnaOplConcEstim;                                     */
/*  output boolean Cstr_bEnaCllConcEstim;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRFUCONCESTIM_vidEstimMng(void)
{
   boolean bLocalConditions_for_feedback;
   boolean bLocalExt_bEngTrbMode;
   boolean bLocalCstrEnaCllConcEstim;
   uint8   u8LocalVehicleactivestate;
   uint16  u16LocalInM_rAirPres;
   uint16  u16LocalCpc_current_purge_ratio;
   uint16  u16LocalObj_rich_en_regulation;
   uint16  u16LocalAtmospheric_pressure;
   uint16  u16LocalIoMapManifoldPressMeas;
   uint32  u32LocalAirPresPurgVlv;
   uint32  u32LocalCalc;


   VEMS_vidGET(Ext_bEngTrbMode, bLocalExt_bEngTrbMode);
   VEMS_vidGET(Io_map_manifold_press_measured, u16LocalIoMapManifoldPressMeas);
   VEMS_vidGET(Atmospheric_pressure, u16LocalAtmospheric_pressure);
   VEMS_vidGET(Conditions_for_feedback, bLocalConditions_for_feedback);
   VEMS_vidGET(InM_rAirPres, u16LocalInM_rAirPres);
   VEMS_vidGET(Cpc_current_purge_ratio, u16LocalCpc_current_purge_ratio);
   VEMS_vidGET(Obj_rich_en_regulation_richesse, u16LocalObj_rich_en_regulation);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicleactivestate);

   u32LocalCalc = (uint32)(Cpc_estim_inh_pres_ratio_thresh * 256);
   if (  (bLocalConditions_for_feedback == 0)
      || (u16LocalCpc_current_purge_ratio < Cpc_purge_ratio_estim_min)
      || (u16LocalObj_rich_en_regulation > Cstr_rMixtSpMaxThd_C)
      || (u16LocalObj_rich_en_regulation < Cstr_rMixtSpMinThd_C)
      || (u16LocalInM_rAirPres > u32LocalCalc))
   {
      Cstr_bOplPurgeCdn = 1;
   }
   else
   {
      Cstr_bOplPurgeCdn = 0;
   }

   if (u16LocalAtmospheric_pressure != 0)
   {
      u32LocalAirPresPurgVlv = (uint32)( ( ( 256
                                           * u16LocalIoMapManifoldPressMeas)
                                         + (u16LocalAtmospheric_pressure / 2))
                                       /  u16LocalAtmospheric_pressure);
      CanPurg_rAirPresPurgVlv = (uint16)MATHSRV_udtMIN(u32LocalAirPresPurgVlv,
                                                       65535);
   }
   else
   {
      CanPurg_rAirPresPurgVlv = 65535;
   }

   if (  (bLocalExt_bEngTrbMode != 0)
      && (CanPurg_rAirPresPurgVlv > Cstr_rAirPresBoostZoneThd_C))
   {
      Cstr_bBoostPresZone = 1;
   }
   else
   {
      Cstr_bBoostPresZone = 0;
   }

   if (u8LocalVehicleactivestate != VS_RUNNING)
   {
      Cstr_bEnaOplConcEstim = 0;
      bLocalCstrEnaCllConcEstim = 0;
   }
   else
   {
      if (Cstr_bOplPurgeCdn != 0)
      {
         Cstr_bEnaOplConcEstim = 1;
         bLocalCstrEnaCllConcEstim = 0;
      }
      else
      {
         Cstr_bEnaOplConcEstim = 0;
         bLocalCstrEnaCllConcEstim = 1;
      }
   }
   if (Cstr_bBoostPresZone == 0)
   {
      Cstr_bEnaCllConcEstim = bLocalCstrEnaCllConcEstim;
   }
   else
   {
      if (  (bLocalCstrEnaCllConcEstim != 0)
         && (Cstr_bAcvBoostPresCond_C != 0))
      {
         Cstr_bEnaCllConcEstim = 1;
      }
      else
      {
         Cstr_bEnaCllConcEstim = 0;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRFUCONCESTIM_vidFuEstim                                 */
/* !Description :  Fonction de calcul de la concentartion en vapeur d'essence */
/*                 et du débit courant issus de la purge.                     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_09_01206_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 InM_mfTotCanPurgEstim;                                       */
/*  input uint16 Cpc_fuel_vapour_concentration;                               */
/*  output uint16 Cpc_fuel_mass_flow_rate;                                    */
/*  output uint16 CanPurg_mFuEstim;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRFUCONCESTIM_vidFuEstim(void)
{
   uint16  u16LocalCpc_fuel_mass_flow_rate;
   uint16  u16LocalInM_mfTotCanPurgEstim;
   uint16  u16LocalCpc_fuel_vapour_concentr;
   uint16  u16LocalCanPurg_mFuEstim;
   uint32  u32LocalCanPurg_mFuEstim;
   uint32  u32LocalCpcfuelmas;
   uint32  u32LocalCpcfuelmassflowrate;


   VEMS_vidGET(InM_mfTotCanPurgEstim, u16LocalInM_mfTotCanPurgEstim);
   VEMS_vidGET(Cpc_fuel_vapour_concentration, u16LocalCpc_fuel_vapour_concentr);

   u32LocalCpcfuelmas =
      u16LocalInM_mfTotCanPurgEstim * u16LocalCpc_fuel_vapour_concentr;
   u32LocalCpcfuelmassflowrate = u32LocalCpcfuelmas / 65536;
   u16LocalCpc_fuel_mass_flow_rate = (uint16)(u32LocalCpcfuelmassflowrate);

   u32LocalCanPurg_mFuEstim =
      (uint32)( ( u16LocalCpc_fuel_mass_flow_rate
                * Cstr_SampleTiFast_SC
                * 125)
              / 1116);

   u16LocalCanPurg_mFuEstim =
      (uint16)MATHSRV_udtMIN(u32LocalCanPurg_mFuEstim, (uint32)65535);
   VEMS_vidSET(Cpc_fuel_mass_flow_rate, u16LocalCpc_fuel_mass_flow_rate);
   VEMS_vidSET(CanPurg_mFuEstim, u16LocalCanPurg_mFuEstim);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRFUCONCESTIM_vidOplConc                                 */
/* !Description :  Fonction de réinitialisation des estimations de le         */
/*                 concentration en vapeurs d'essence dans le canister et de  */
/*                 l'erreur sur la concentration en vapeurs d'essence dans le */
/*                 canister.                                                  */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CSTRFUCONCESTIM_vidOplConcEstim();                       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Cstr_bEnaOplConcEstim;                                      */
/*  input boolean Cal_reset_fuel_vapour_conc;                                 */
/*  input boolean CSTRFUCONCESTIM_CalresetPrev;                               */
/*  input uint8 Cpc_fuel_vapour_conc_init;                                    */
/*  input boolean Cal_reset_fuel_vapour_conc_err;                             */
/*  input boolean CSTRFUCONCESTIM_CalreseterPrev;                             */
/*  input uint8 Cpc_fuel_vapour_conc_err_init;                                */
/*  output uint16 Cpc_fuel_vapour_concentration;                              */
/*  output uint16 Cpc_fuel_vapour_conc_err;                                   */
/*  output boolean CSTRFUCONCESTIM_CalresetPrev;                              */
/*  output boolean CSTRFUCONCESTIM_CalreseterPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRFUCONCESTIM_vidOplConc(void)
{
   uint16  u16LocalCpc_fuel_vapour_concentr;
   uint16  u16LocalCpc_fuel_vapour_conc_err;


   if (Cstr_bEnaOplConcEstim != 0)
   {
      CSTRFUCONCESTIM_vidOplConcEstim();
   }

   if (  (Cal_reset_fuel_vapour_conc != 0)
      && (CSTRFUCONCESTIM_CalresetPrev == 0))
   {
      u16LocalCpc_fuel_vapour_concentr =
         (uint16)(Cpc_fuel_vapour_conc_init * 256);
      VEMS_vidSET(Cpc_fuel_vapour_concentration,
                  u16LocalCpc_fuel_vapour_concentr);
   }

   if (  (Cal_reset_fuel_vapour_conc_err != 0)
      && (CSTRFUCONCESTIM_CalreseterPrev == 0))
   {
      u16LocalCpc_fuel_vapour_conc_err =
         (uint16) (Cpc_fuel_vapour_conc_err_init * 256);

      VEMS_vidSET(Cpc_fuel_vapour_conc_err, u16LocalCpc_fuel_vapour_conc_err);
   }
   CSTRFUCONCESTIM_CalresetPrev = Cal_reset_fuel_vapour_conc;
   CSTRFUCONCESTIM_CalreseterPrev = Cal_reset_fuel_vapour_conc_err;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRFUCONCESTIM_vidOplConcEstim                            */
/* !Description :  Fonction d'incrémentation à un pas calibrable de           */
/*                 l'estimateur lors de la fermeture de la purge ou au        */
/*                 débouclage du lambda feedback.                             */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Temperature_air;                                              */
/*  input uint16 Cpc_conc_open_loop_step_map[5];                              */
/*  input uint16 Cpc_fuel_vapour_concentration;                               */
/*  input uint16 Cpc_conc_open_loop_step;                                     */
/*  input uint16 Cpc_fuel_vapour_conc_err;                                    */
/*  input uint16 Cpc_err_open_loop_step;                                      */
/*  output uint16 Cpc_conc_open_loop_step;                                    */
/*  output uint16 Cpc_fuel_vapour_concentration;                              */
/*  output uint16 Cpc_fuel_vapour_conc_err;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRFUCONCESTIM_vidOplConcEstim(void)
{
   uint8   u8LocalTemperature_air;
   uint16  u16LocalVtaIntakeProp;
   uint16  u16LocalCpc_fuel_vapour_concentr;
   uint16  u16LocalCpc_fuel_vapour_conc_err;
   uint16  u16LocalTemperatureair;
   uint32  u32LocalCpccalcul;
   uint32  u32LocalCpcerrcalc;
   uint32  u32LocalCpcfuelvapconerr;


   VEMS_vidGET(Temperature_air, u8LocalTemperature_air);


   u16LocalTemperatureair = (uint16)(u8LocalTemperature_air * 4);
   u16LocalVtaIntakeProp = MATHSRV_u16Interp1d(Cpc_conc_open_loop_step_map,
                                                u16LocalTemperatureair);

   Cpc_conc_open_loop_step =
      (uint16)MATHSRV_udtMIN(u16LocalVtaIntakeProp, 15990);

   VEMS_vidGET(Cpc_fuel_vapour_concentration, u16LocalCpc_fuel_vapour_concentr);

   u32LocalCpccalcul = (uint32)(u16LocalCpc_fuel_vapour_concentr
                               + Cpc_conc_open_loop_step);

   u16LocalCpc_fuel_vapour_concentr =
    (uint16)MATHSRV_udtMIN(u32LocalCpccalcul, (uint32)CPC_CONC_100_PERC);

   VEMS_vidSET(Cpc_fuel_vapour_concentration, u16LocalCpc_fuel_vapour_concentr);

   VEMS_vidGET(Cpc_fuel_vapour_conc_err, u16LocalCpc_fuel_vapour_conc_err);

   u32LocalCpcerrcalc =
     (uint32)(u16LocalCpc_fuel_vapour_conc_err + Cpc_err_open_loop_step);
   u32LocalCpcfuelvapconerr =
    MATHSRV_udtMIN(u32LocalCpcerrcalc, (uint32)(CPC_CONC_ERR_100_PERC));

   u16LocalCpc_fuel_vapour_conc_err = (uint16)(u32LocalCpcfuelvapconerr);
   VEMS_vidSET(Cpc_fuel_vapour_conc_err, u16LocalCpc_fuel_vapour_conc_err);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRFUCONCESTIM_NVMSRV_vidInit                             */
/* !Description :  Initialisation des variables Eeprom.                       */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_E_09_01206_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Cpc_fuel_vapour_conc_init;                                    */
/*  output uint16 Cpc_fuel_vapour_concentration;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRFUCONCESTIM_NVMSRV_vidInit(void)
{
   uint16  u16LocalCpc_fuel_vapour_concent;


   u16LocalCpc_fuel_vapour_concent = (uint16)(256 * Cpc_fuel_vapour_conc_init);
   VEMS_vidSET(Cpc_fuel_vapour_concentration, u16LocalCpc_fuel_vapour_concent);
}
/*------------------------------- end of file --------------------------------*/