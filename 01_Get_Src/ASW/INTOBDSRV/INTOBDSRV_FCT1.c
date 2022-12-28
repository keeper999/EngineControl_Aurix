/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INTOBDSRV                                               */
/* !Description     : INTOBDSRV component                                     */
/*                                                                            */
/* !Module          : INTOBDSRV                                               */
/* !Description     : Définition des PID supportés pour le diagnostic OBD et  */
/*                    les services constructeurs                              */
/*                                                                            */
/* !File            : INTOBDSRV_FCT1.C                                        */
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
/*   1 / INTOBDSRV_vidIni_PID4F                                               */
/*   2 / INTOBDSRV_vidInitOutput                                              */
/*   3 / INTOBDSRV_vidFast_Pid                                                */
/*   4 / INTOBDSRV_vidMid_Pid1                                                */
/*   5 / INTOBDSRV_vidMid_Pid2                                                */
/*   6 / INTOBDSRV_vidMid_Pid3                                                */
/*   7 / INTOBDSRV_vid14PMH_Pid                                               */
/*   8 / INTOBDSRV_vidPMH_Pid                                                 */
/*   9 / INTOBDSRV_vidPMB_PID                                                 */
/*                                                                            */
/* !Reference   : V02 NT 11 05149 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#065271                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OBD_HAT/INTOBDSRV/INTOBDSRV_FCT1$*/
/* $Revision::   1.4      $$Author::   pbakabad       $$Date::   Mar 14 2013 $*/
/* $Author::   pbakabad                               $$Date::   Mar 14 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "INTOBDSRV.h"
#include "INTOBDSRV_L.h"
#include "INTOBDSRV_IM.h"
#include "MATHSRV.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INTOBDSRV_vidIni_PID4F                                     */
/* !Description :  Le PID 4F est un PID de configuration, il est égal à 0.    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint32 Srv_MaxValEqRatio_Pid4F;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INTOBDSRV_vidIni_PID4F(void)
{
   VEMS_vidSET(Srv_MaxValEqRatio_Pid4F, 0x0000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INTOBDSRV_vidInitOutput                                    */
/* !Description :  Initialization of the outputs                              */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Srv_AccP_Pos1_Pid49;                                         */
/*  output uint8 Srv_AccP_Pos2_Pid4A;                                         */
/*  output uint8 Srv_Cstr_Pid2E;                                              */
/*  output uint8 Srv_Diag_trim_Pid07;                                         */
/*  output uint16 Srv_EngRunMilOn_Pid4D;                                      */
/*  output uint8 Srv_Engine_load_Pid04;                                       */
/*  output uint8 Srv_Fuel_System_Pid03;                                       */
/*  output uint8 Srv_IgCmd_Pid0E;                                             */
/*  output uint8 Srv_Lfbk_Pid06;                                              */
/*  output uint8 Srv_ObdMod_Pid1C;                                            */
/*  output uint8 Srv_SensO2_Pos_Pid13;                                        */
/*  output uint8 Srv_Thr_Pos1_Pid11;                                          */
/*  output uint8 Srv_Thr_Pos2_Pid47;                                          */
/*  output uint8 Srv_WUCDftClr_Pid30;                                         */
/*  output uint16 Srv_dstKmMilOn_Pid21;                                       */
/*  output uint16 Srv_nEng_Pid0C;                                             */
/*  output uint8 Srv_pAtm_Pid33;                                              */
/*  output uint8 Srv_pDsThrMes_Pid0B;                                         */
/*  output uint8 Srv_spdVeh_Pid0D;                                            */
/*  output uint8 Srv_tAirMes_Pid0F;                                           */
/*  output uint8 Srv_tCoMes_Pid05;                                            */
/*  output uint16 Srv_uBattMes_Pid42;                                         */
/*  output uint8 Srv_uDsLs_Pid15;                                             */
/*  output uint8 Srv_uUpLs_Pid14;                                             */
/*  output uint8 AFAStl_rSlowFuCor;                                           */
/*  output uint8 AFRegStl_lamFb;                                              */
/*  output uint8 AFRegStl_stCllRich;                                          */
/*  output uint8 BoostActStl_rDuCyReqCplm;                                    */
/*  output uint16 FARSpStl_lamSp;                                             */
/*  output uint16 Srv_AstTot_Pid1F;                                           */
/*  output uint8 Srv_OpThr_Pid4C;                                             */
/*  output uint16 Srv_OxCEstim_Pid3C;                                         */
/*  output uint16 Srv_dstKmRstDft_Pid31;                                      */
/*  output uint8 Srv_mfAirScvLimMaxCor_Pid50;                                 */
/*  output uint16 Srv_pFuMes_Pid23;                                           */
/*  output uint16 Srv_tiMinsEngrunRstDft_Pid4E;                               */
/*  output uint8 TrbActStl_rOpTrbAct;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INTOBDSRV_vidInitOutput(void)
{
   VEMS_vidSET(Srv_AccP_Pos1_Pid49, 0);
   VEMS_vidSET(Srv_AccP_Pos2_Pid4A, 0);
   VEMS_vidSET(Srv_Cstr_Pid2E, 0);
   VEMS_vidSET(Srv_Diag_trim_Pid07, 128);
   VEMS_vidSET(Srv_EngRunMilOn_Pid4D, 0);
   VEMS_vidSET(Srv_Engine_load_Pid04, 0);
   VEMS_vidSET(Srv_Fuel_System_Pid03, 0);
   VEMS_vidSET(Srv_IgCmd_Pid0E, 128);
   VEMS_vidSET(Srv_Lfbk_Pid06, 128);
   VEMS_vidSET(Srv_ObdMod_Pid1C, 0);
   VEMS_vidSET(Srv_SensO2_Pos_Pid13, 0);
   VEMS_vidSET(Srv_Thr_Pos1_Pid11, 0);
   VEMS_vidSET(Srv_Thr_Pos2_Pid47, 0);
   VEMS_vidSET(Srv_WUCDftClr_Pid30, 0);
   VEMS_vidSET(Srv_dstKmMilOn_Pid21, 0);
   VEMS_vidSET(Srv_nEng_Pid0C, 0);
   VEMS_vidSET(Srv_pAtm_Pid33, 0);
   VEMS_vidSET(Srv_pDsThrMes_Pid0B, 0);
   VEMS_vidSET(Srv_spdVeh_Pid0D, 0);
   VEMS_vidSET(Srv_tAirMes_Pid0F, 40);
   VEMS_vidSET(Srv_tCoMes_Pid05, 40);
   VEMS_vidSET(Srv_uBattMes_Pid42, 0);
   VEMS_vidSET(Srv_uDsLs_Pid15, 0);
   VEMS_vidSET(Srv_uUpLs_Pid14, 0);
   VEMS_vidSET(AFAStl_rSlowFuCor, 128);
   VEMS_vidSET(AFRegStl_lamFb, 128);
   VEMS_vidSET(AFRegStl_stCllRich, 0);
   VEMS_vidSET(BoostActStl_rDuCyReqCplm, 0);
   VEMS_vidSET(FARSpStl_lamSp, 0);
   VEMS_vidSET(Srv_AstTot_Pid1F, 0);
   VEMS_vidSET(Srv_OpThr_Pid4C, 0);
   VEMS_vidSET(Srv_OxCEstim_Pid3C, 400);
   VEMS_vidSET(Srv_dstKmRstDft_Pid31, 0);
   VEMS_vidSET(Srv_mfAirScvLimMaxCor_Pid50, 0);
   VEMS_vidSET(Srv_pFuMes_Pid23, 0);
   VEMS_vidSET(Srv_tiMinsEngrunRstDft_Pid4E, 0);
   VEMS_vidSET(TrbActStl_rOpTrbAct, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INTOBDSRV_vidFast_Pid                                      */
/* !Description :  Les PID concernant la position papillon sont produits à    */
/*                 récurrence rapide.                                         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tps_1_ratio_meas_position;                                   */
/*  input uint16 Tps_2_ratio_meas_position;                                   */
/*  output uint8 Srv_Thr_Pos1_Pid11;                                          */
/*  output uint8 Srv_Thr_Pos2_Pid47;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INTOBDSRV_vidFast_Pid(void)
{
   uint8  u8LocalSrv_Thr_Pos1_Pid11;
   uint8  u8LocalSrv_Thr_Pos2_Pid47;
   uint16 u16LocalTps1_ratio_meas_position;
   uint16 u16LocalTps2_ratio_meas_position;
   uint16 u16LocalSrv_Thr_Pos1_Pid11;
   uint16 u16LocalSrv_Thr_Pos2_Pid47;

   VEMS_vidGET(Tps_1_ratio_meas_position, u16LocalTps1_ratio_meas_position);
   VEMS_vidGET(Tps_2_ratio_meas_position, u16LocalTps2_ratio_meas_position);
   u16LocalSrv_Thr_Pos1_Pid11 =
      (uint16)(((255 * u16LocalTps1_ratio_meas_position) + 512) / 1024);
   u8LocalSrv_Thr_Pos1_Pid11 =
      (uint8)MATHSRV_udtMIN(u16LocalSrv_Thr_Pos1_Pid11, 255);
   VEMS_vidSET(Srv_Thr_Pos1_Pid11, u8LocalSrv_Thr_Pos1_Pid11);

   u16LocalSrv_Thr_Pos2_Pid47 =
      (uint16)(((255 * u16LocalTps2_ratio_meas_position) + 512) / 1024);
   u8LocalSrv_Thr_Pos2_Pid47 =
      (uint8)MATHSRV_udtMIN(u16LocalSrv_Thr_Pos2_Pid47, 255);
   VEMS_vidSET(Srv_Thr_Pos2_Pid47, u8LocalSrv_Thr_Pos2_Pid47);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INTOBDSRV_vidMid_Pid1                                      */
/* !Description :  Les autres PID sont produits à currence moyenne (suite1).  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Temperature_eau_mesuree;                                      */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input uint8 Temperature_air_mesuree;                                      */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint16 Aps_1_filtered_position;                                     */
/*  input uint16 Aps_2_formated_position;                                     */
/*  input uint16 Tension_sonde_amont;                                         */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint16 GMIL_dstKmMilOn;                                             */
/*  input uint8 WUC_ctWupDftClr;                                              */
/*  input uint16 GMIL_tiMinsEngrunMilOn;                                      */
/*  input uint8 TqSys_rLdEngRef;                                              */
/*  input uint8 CanPurg_rOpCanPurgReq;                                        */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input uint32 Ext_tiAstTot;                                                */
/*  input uint16 Ext_pFuMesWRV;                                               */
/*  input sint16 Ext_tOxCEstim;                                               */
/*  input uint8 Srv_Pos_SenO2_C;                                              */
/*  input uint8 Srv_Obd_Mode_C;                                               */
/*  output uint8 Srv_Engine_load_Pid04;                                       */
/*  output uint8 Srv_tCoMes_Pid05;                                            */
/*  output uint8 Srv_spdVeh_Pid0D;                                            */
/*  output uint8 Srv_tAirMes_Pid0F;                                           */
/*  output uint16 Srv_uBattMes_Pid42;                                         */
/*  output uint8 Srv_AccP_Pos1_Pid49;                                         */
/*  output uint8 Srv_AccP_Pos2_Pid4A;                                         */
/*  output uint8 Srv_SensO2_Pos_Pid13;                                        */
/*  output uint8 Srv_Pos_SenO2_C;                                             */
/*  output uint8 Srv_uUpLs_Pid14;                                             */
/*  output uint8 Srv_uDsLs_Pid15;                                             */
/*  output uint8 Srv_ObdMod_Pid1C;                                            */
/*  output uint8 Srv_Obd_Mode_C;                                              */
/*  output uint16 Srv_dstKmMilOn_Pid21;                                       */
/*  output uint8 Srv_Cstr_Pid2E;                                              */
/*  output uint8 Srv_WUCDftClr_Pid30;                                         */
/*  output uint16 Srv_EngRunMilOn_Pid4D;                                      */
/*  output uint8 Srv_pAtm_Pid33;                                              */
/*  output uint16 Srv_AstTot_Pid1F;                                           */
/*  output uint16 Srv_pFuMes_Pid23;                                           */
/*  output uint16 Srv_OxCEstim_Pid3C;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INTOBDSRV_vidMid_Pid1(void)
{
   uint8    u8LocalTemperature_eau_mesuree;
   uint8    u8LocalVitesse_vehicule;
   uint8    u8LocalTemperature_air_mesuree;
   uint8    u8LocalWUC_ctWupDftClr;
   uint8    u8LocalSrv_Engine_load_Pid04;
   uint8    u8LocalSrv_tCoMes_Pid05;
   uint8    u8LocalSrv_tAirMes_Pid0F;
   uint8    u8LocalSrv_AccP_Pos1_Pid49;
   uint8    u8LocalSrv_AccP_Pos2_Pid4A;
   uint8    u8LocalSrv_uUpLs_Pid14;
   uint8    u8LocalSrv_uDsLs_Pid15;
   uint8    u8LocalSrv_Cstr_Pid2E;
   uint8    u8LocalSrv_pAtm_Pid33;
   uint8    u8LocalTqSys_rLdEngRef;
   uint8    u8LocalCanPurg_rOpCanPurgReq;
   uint16   u16LocalAps_1_filtered_position;
   uint16   u16LocalAps_2_formated_position;
   uint16   u16LocalTension_sonde_amont;
   uint16   u16LocalTension_sonde_aval;
   uint16   u16LocalGMIL_dstKmMilOn;
   uint16   u16LocalGMIL_tiMinsEngrunMilOn;
   uint16   u16LocalSrv_Engine_load_Pid04;
   uint16   u16LocalSrv_uBattMes_Pid42;
   uint16   u16LocalSrv_AccP_Pos1_Pid49;
   uint16   u16LocalSrv_AccP_Pos2_Pid4A;
   uint16   u16LocalSrv_uUpLs_Pid14;
   uint16   u16LocalSrv_uDsLs_Pid15;
   uint16   u16LocalSrv_pAtm_Pid33;
   uint16   u16LocalExt_pAirExtMes;
   uint16   u16LocalSrv_AstTot_Pid1F;
   uint16   u16LocalExt_pFuMesWRV;
   uint16   u16LocalSrv_OxCEstim_Pid3C;
   uint32   u32LocalExt_tiAstTot;
   sint16   s16LocalExt_uBattMes;
   sint16   s16LocalExt_tOxCEstim;
   sint32   s32LocalSrv_uBattMes_Pid42;
   sint32   s32LocalSrv_OxCEstim_Pid3C;


   VEMS_vidGET(Temperature_eau_mesuree, u8LocalTemperature_eau_mesuree);
   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);
   VEMS_vidGET(Temperature_air_mesuree, u8LocalTemperature_air_mesuree);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   VEMS_vidGET(Aps_1_filtered_position, u16LocalAps_1_filtered_position);
   VEMS_vidGET(Aps_2_formated_position, u16LocalAps_2_formated_position);
   VEMS_vidGET(Tension_sonde_amont, u16LocalTension_sonde_amont);
   VEMS_vidGET(Tension_sonde_aval, u16LocalTension_sonde_aval);
   VEMS_vidGET(GMIL_dstKmMilOn, u16LocalGMIL_dstKmMilOn);
   VEMS_vidGET(WUC_ctWupDftClr, u8LocalWUC_ctWupDftClr);
   VEMS_vidGET(GMIL_tiMinsEngrunMilOn, u16LocalGMIL_tiMinsEngrunMilOn);
   VEMS_vidGET(TqSys_rLdEngRef, u8LocalTqSys_rLdEngRef);
   VEMS_vidGET(CanPurg_rOpCanPurgReq, u8LocalCanPurg_rOpCanPurgReq);
   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   VEMS_vidGET(Ext_tiAstTot, u32LocalExt_tiAstTot);
   VEMS_vidGET(Ext_pFuMesWRV, u16LocalExt_pFuMesWRV);
   VEMS_vidGET(Ext_tOxCEstim, s16LocalExt_tOxCEstim);


   u16LocalSrv_Engine_load_Pid04 = (uint16)( ( (u8LocalTqSys_rLdEngRef * 51)
                                             + 10)
                                           / 20);
   u8LocalSrv_Engine_load_Pid04 =
      (uint8)MATHSRV_udtMIN(u16LocalSrv_Engine_load_Pid04, 255);
   VEMS_vidSET(Srv_Engine_load_Pid04,u8LocalSrv_Engine_load_Pid04);

   u8LocalSrv_tCoMes_Pid05 = (uint8)( ( (u8LocalTemperature_eau_mesuree * 5)
                                      + 4)
                                    / 8);
   VEMS_vidSET(Srv_tCoMes_Pid05, u8LocalSrv_tCoMes_Pid05);

   VEMS_vidSET(Srv_spdVeh_Pid0D, u8LocalVitesse_vehicule);

   u8LocalSrv_tAirMes_Pid0F = (uint8)( ( (u8LocalTemperature_air_mesuree * 5)
                                       + 4)
                                     / 8);
   VEMS_vidSET(Srv_tAirMes_Pid0F, u8LocalSrv_tAirMes_Pid0F);

   s32LocalSrv_uBattMes_Pid42 = (sint32)(s16LocalExt_uBattMes * 10);
   u16LocalSrv_uBattMes_Pid42 =
      (uint16)MATHSRV_udtCLAMP(s32LocalSrv_uBattMes_Pid42, 0, 65535);
   VEMS_vidSET(Srv_uBattMes_Pid42, u16LocalSrv_uBattMes_Pid42);

   u16LocalSrv_AccP_Pos1_Pid49 = (uint16)( ( ( u16LocalAps_1_filtered_position
                                             * 255)
                                           + 512)
                                         / 1024);
   u8LocalSrv_AccP_Pos1_Pid49 =
      (uint8)MATHSRV_udtMIN(u16LocalSrv_AccP_Pos1_Pid49, 255);
   VEMS_vidSET(Srv_AccP_Pos1_Pid49, u8LocalSrv_AccP_Pos1_Pid49);

   u16LocalSrv_AccP_Pos2_Pid4A = (uint16)( ( ( u16LocalAps_2_formated_position
                                             * 255)
                                           + 512)
                                         / 1024);
   u8LocalSrv_AccP_Pos2_Pid4A =
      (uint8)MATHSRV_udtMIN(u16LocalSrv_AccP_Pos2_Pid4A, 255);
   VEMS_vidSET(Srv_AccP_Pos2_Pid4A, u8LocalSrv_AccP_Pos2_Pid4A);

   VEMS_vidSET(Srv_SensO2_Pos_Pid13, Srv_Pos_SenO2_C);

   u16LocalSrv_uUpLs_Pid14 = (uint16)( ( (u16LocalTension_sonde_amont * 125)
                                       + 64)
                                     / 128);
   u8LocalSrv_uUpLs_Pid14 = (uint8)MATHSRV_udtMIN(u16LocalSrv_uUpLs_Pid14, 255);
   VEMS_vidSET(Srv_uUpLs_Pid14, u8LocalSrv_uUpLs_Pid14);

   u16LocalSrv_uDsLs_Pid15 = (uint16)( ( (u16LocalTension_sonde_aval * 125)
                                       + 64)
                                     / 128);
   u8LocalSrv_uDsLs_Pid15 = (uint8)MATHSRV_udtMIN(u16LocalSrv_uDsLs_Pid15, 255);
   VEMS_vidSET(Srv_uDsLs_Pid15, u8LocalSrv_uDsLs_Pid15);

   VEMS_vidSET(Srv_ObdMod_Pid1C, Srv_Obd_Mode_C);
   VEMS_vidSET(Srv_dstKmMilOn_Pid21, u16LocalGMIL_dstKmMilOn);

   u8LocalSrv_Cstr_Pid2E = (uint8)( ( (u8LocalCanPurg_rOpCanPurgReq * 255)
                                    + 128)
                                  / 256);
   VEMS_vidSET(Srv_Cstr_Pid2E, u8LocalSrv_Cstr_Pid2E);

   VEMS_vidSET(Srv_WUCDftClr_Pid30, u8LocalWUC_ctWupDftClr);
   VEMS_vidSET(Srv_EngRunMilOn_Pid4D, u16LocalGMIL_tiMinsEngrunMilOn);

   u16LocalSrv_pAtm_Pid33 = (uint16)((u16LocalExt_pAirExtMes + 5) / 10);
   u8LocalSrv_pAtm_Pid33 = (uint8)MATHSRV_udtMIN(u16LocalSrv_pAtm_Pid33, 255);
   VEMS_vidSET(Srv_pAtm_Pid33, u8LocalSrv_pAtm_Pid33);

   u16LocalSrv_AstTot_Pid1F = (uint16)MATHSRV_udtMIN(u32LocalExt_tiAstTot,
                                                     65535);
   VEMS_vidSET(Srv_AstTot_Pid1F, u16LocalSrv_AstTot_Pid1F);

   VEMS_vidSET(Srv_pFuMes_Pid23, u16LocalExt_pFuMesWRV);

   s32LocalSrv_OxCEstim_Pid3C = (sint32)((s16LocalExt_tOxCEstim + 40) * 10);
   u16LocalSrv_OxCEstim_Pid3C =
      (uint16)MATHSRV_udtCLAMP(s32LocalSrv_OxCEstim_Pid3C, 0, 65535);
   VEMS_vidSET(Srv_OxCEstim_Pid3C, u16LocalSrv_OxCEstim_Pid3C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INTOBDSRV_vidMid_Pid2                                      */
/* !Description :  Les autres PID sont produits à currence moyenne(suite2)    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input sint16 AFA_facIvsInjGain;                                           */
/*  input uint16 Injector_constant;                                           */
/*  input sint32 AFA_facSlopInjGain;                                          */
/*  input uint16 ThrSys_rOpThrReq;                                            */
/*  input uint8 Srv_prmPid07_C;                                               */
/*  input uint16 InjrM_prm_pDifInjr[4];                                       */
/*  output uint8 Srv_OpThr_Pid4C;                                             */
/*  output uint8 Srv_Diag_trim_Pid07;                                         */
/*  output uint8 AFAStl_rSlowFuCor;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INTOBDSRV_vidMid_Pid2(void)
{
   uint8   u8LocalSrv_Diag_trim_Pid07Div;
   uint8   u8LocalSrv_OpThr_Pid4C;
   uint16  u16LocalInjrM_prm_pDifInjr;
   uint16  u16LocalInjector_constant;
   uint16  u16LocalSrv_OpThr_Pid4C;
   uint16  u16LocalThrSys_rOpThrReq;
   sint16  s16LocalSrv_Diag_trim_Pid07;
   sint16  s16LocalAFAfacIvsInjGain;
   sint32  s32LocalAFA_facSlopInjGain;
   sint32  s32LocalDenom;
   float32 f32LocalCalcNum;
   float32 f32LocalCalcDen;
   float32 f32LocalCalcOut;


   VEMS_vidGET(AFA_facIvsInjGain, s16LocalAFAfacIvsInjGain);
   VEMS_vidGET(Injector_constant, u16LocalInjector_constant);
   VEMS_vidGET(AFA_facSlopInjGain , s32LocalAFA_facSlopInjGain );
   VEMS_vidGET(ThrSys_rOpThrReq, u16LocalThrSys_rOpThrReq);

   u16LocalSrv_OpThr_Pid4C = (uint16)( ( (u16LocalThrSys_rOpThrReq * 255) + 512)
                                     / 1024);
   u8LocalSrv_OpThr_Pid4C = (uint8)MATHSRV_udtMIN(u16LocalSrv_OpThr_Pid4C, 255);
   VEMS_vidSET(Srv_OpThr_Pid4C, u8LocalSrv_OpThr_Pid4C);

   if (Srv_prmPid07_C == 0)
   {
      s32LocalDenom = (sint32)( ( u16LocalInjector_constant
                                + s16LocalAFAfacIvsInjGain)
                              + 1);

      if (s32LocalDenom == 0)
      {
         s16LocalSrv_Diag_trim_Pid07 = 128;
      }
      else
      {
         s16LocalSrv_Diag_trim_Pid07 =
            (sint16)(128 - ( (128 * s16LocalAFAfacIvsInjGain)
                           / s32LocalDenom));
      }
      u8LocalSrv_Diag_trim_Pid07Div = (uint8)s16LocalSrv_Diag_trim_Pid07;
   }
   else
   {
      VEMS_vidGET1DArrayElement(InjrM_prm_pDifInjr,0,
         u16LocalInjrM_prm_pDifInjr);
      if (Srv_prmPid07_C == 1)
      {
         f32LocalCalcNum = ( ( (float32)s32LocalAFA_facSlopInjGain
                              * (float32)u16LocalInjrM_prm_pDifInjr
                              * (float32)3125) / (float32)268435456);

         f32LocalCalcDen  = ( f32LocalCalcNum
                            + (float32)u16LocalInjector_constant + (float32)1);

         if (f32LocalCalcDen == (float32)0)
         /*Msg(3:3341): due to the use of the egality = 0 to a floationg type*/
         {
            f32LocalCalcOut = (float32)128;
         }
         else
         {
            f32LocalCalcOut = ( (float32)128
                               - ( (f32LocalCalcNum * (float32)(128))
                                 / f32LocalCalcDen));
         }
         u8LocalSrv_Diag_trim_Pid07Div =
            (uint8)MATHSRV_udtCLAMP(f32LocalCalcOut,(float32)0 ,(float32)255);
      }
      else
      {
         f32LocalCalcNum = ( ( ( (float32)s32LocalAFA_facSlopInjGain
                                * (float32)u16LocalInjrM_prm_pDifInjr
                                * (float32)3125)
                              / (float32)268435456)
                            + (float32)s16LocalAFAfacIvsInjGain);

         f32LocalCalcDen = ( f32LocalCalcNum
                            + (float32)u16LocalInjector_constant + (float32)1);

         if (f32LocalCalcDen == (float32)0)
         /*Msg(3:3341): due to the use of the egality = 0 to a floationg type*/
         {
            f32LocalCalcOut = (float32)128;
         }
         else
         {
            f32LocalCalcOut = ( (float32)128
                               - ( (f32LocalCalcNum * (float32)(128))
                                 / f32LocalCalcDen));
         }
         u8LocalSrv_Diag_trim_Pid07Div =
            (uint8)MATHSRV_udtCLAMP(f32LocalCalcOut,(float32)0 ,(float32)255);
      }
   }
   VEMS_vidSET(Srv_Diag_trim_Pid07, u8LocalSrv_Diag_trim_Pid07Div);
   VEMS_vidSET(AFAStl_rSlowFuCor, u8LocalSrv_Diag_trim_Pid07Div);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INTOBDSRV_vidMid_Pid3                                      */
/* !Description :  Les autres PID sont produits à currence  moyenne (suite3)  */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint8 u16IndexFRM);              */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 FARSp_rMixtCylSp;                                            */
/*  input uint16 TrbAct_rOpTrbAct;                                            */
/*  input uint16 BoostAct_rDuCyReq;                                           */
/*  input uint16 TPM_mfAirScvLimMaxCor;                                       */
/*  input uint16 GMIL_tiMinsEngrunRstDft;                                     */
/*  input uint16 GMIL_dstKmRstDft;                                            */
/*  input uint8 Coupure_decel_progr_inj;                                      */
/*  input st30 Monitor_feedback_conds_state;                                  */
/*  input boolean Manu_inh_lambda_feedback;                                   */
/*  input boolean Test_bed_pulse;                                             */
/*  input bool WAITING_SENSOR_AND_TEMP_CONDS;                                 */
/*  input bool WAITING_FOR_POST_FCO_DELAY;                                    */
/*  input bool FEEDBACK_ENABLED;                                              */
/*  input uint8 Srv_prmByteAPid72_C;                                          */
/*  output uint16 FARSpStl_lamSp;                                             */
/*  output uint16 Srv_dstKmRstDft_Pid31;                                      */
/*  output uint16 Srv_tiMinsEngrunRstDft_Pid4E;                               */
/*  output uint8 Srv_mfAirScvLimMaxCor_Pid50;                                 */
/*  output uint8 Srv_Fuel_System_Pid03;                                       */
/*  output uint8 AFRegStl_stCllRich;                                          */
/*  output uint8 BoostActStl_rDuCyReqCplm;                                    */
/*  output uint8 TrbActStl_rOpTrbAct;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INTOBDSRV_vidMid_Pid3(void)
{
   boolean bLocalInhInjFarCtlMgrLbdFb;
   boolean bLocalInhCtlloopPID03;
   uint8   u8LocalSrvAirLimMaxCorPid50;
   uint8   u8LocalCoupure_decel_progr_inj;
   uint8   u8LocalMonitor_feedback_conds_st;
   uint8   u8LocalBoostActStlDuCyReqCplm;
   uint8   u8LocalTrbActStl_rOpTrbAct;
   uint16  u16LocalGMIL_dstKmRstDft;
   uint16  u16LocalGMILMinsEngrunRstDft;
   uint16  u16LocalTPM_mfAirScvLimMaxCor;
   uint16  u16LocalBoostAct_rDuCyReq;
   uint16  u16LocalTrbAct_rOpTrbAct;
   uint16  u16LocalFARSp_rMixtCylSp;
   uint16  u16LocalFARSpStl_lamSp;


   bLocalInhInjFarCtlMgrLbdFb = GDGAR_bGetFRM(FRM_FRM_INHINJFARCTLMGRLBDFB);
   bLocalInhCtlloopPID03 = GDGAR_bGetFRM(FRM_FRM_INHCTLLOOPPID03);
   VEMS_vidGET(FARSp_rMixtCylSp, u16LocalFARSp_rMixtCylSp);
   VEMS_vidGET(TrbAct_rOpTrbAct, u16LocalTrbAct_rOpTrbAct);
   VEMS_vidGET(BoostAct_rDuCyReq, u16LocalBoostAct_rDuCyReq);
   VEMS_vidGET(TPM_mfAirScvLimMaxCor, u16LocalTPM_mfAirScvLimMaxCor);
   VEMS_vidGET(GMIL_tiMinsEngrunRstDft, u16LocalGMILMinsEngrunRstDft);
   VEMS_vidGET(GMIL_dstKmRstDft, u16LocalGMIL_dstKmRstDft);
   VEMS_vidGET(Coupure_decel_progr_inj, u8LocalCoupure_decel_progr_inj);
   VEMS_vidGET(Monitor_feedback_conds_state, u8LocalMonitor_feedback_conds_st);

   if (u16LocalFARSp_rMixtCylSp != 0)
   {
      if (u16LocalFARSp_rMixtCylSp > 2048)
      {
         u16LocalFARSpStl_lamSp = (uint16)( (2048 * 65535)
                                          / u16LocalFARSp_rMixtCylSp);
      }
      else
      {
         u16LocalFARSpStl_lamSp = 65534;
      }
   }
   else
   {
      u16LocalFARSpStl_lamSp = 65534;
   }
   VEMS_vidSET(FARSpStl_lamSp, u16LocalFARSpStl_lamSp);

   VEMS_vidSET(Srv_dstKmRstDft_Pid31, u16LocalGMIL_dstKmRstDft);

   VEMS_vidSET(Srv_tiMinsEngrunRstDft_Pid4E, u16LocalGMILMinsEngrunRstDft);

   u8LocalSrvAirLimMaxCorPid50 = (uint8)( ( (u16LocalTPM_mfAirScvLimMaxCor * 25)
                                          + 8192)
                                        / 16384);
   VEMS_vidSET(Srv_mfAirScvLimMaxCor_Pid50, u8LocalSrvAirLimMaxCorPid50);

   if (  (bLocalInhInjFarCtlMgrLbdFb != 0)
      || (Manu_inh_lambda_feedback != 0)
      || (Test_bed_pulse != 0)
      || ((u8LocalCoupure_decel_progr_inj & 0x0F) != 0))
   {
      VEMS_vidSET(Srv_Fuel_System_Pid03, 0x08);
      VEMS_vidSET(AFRegStl_stCllRich, 0x08);
   }
   else
   {
      if (u8LocalMonitor_feedback_conds_st == WAITING_SENSOR_AND_TEMP_CONDS)
      {
         VEMS_vidSET(Srv_Fuel_System_Pid03, 0x01);
         VEMS_vidSET(AFRegStl_stCllRich, 0x01);
      }
      else
      {
         if (u8LocalMonitor_feedback_conds_st == WAITING_FOR_POST_FCO_DELAY)
         {
            VEMS_vidSET(Srv_Fuel_System_Pid03, 0x04);
            VEMS_vidSET(AFRegStl_stCllRich, 0x04);
         }
         else
         {
            if (u8LocalMonitor_feedback_conds_st == FEEDBACK_ENABLED)
            {
               if (bLocalInhCtlloopPID03 != 0)
               {
                  VEMS_vidSET(Srv_Fuel_System_Pid03, 0x10);
                  VEMS_vidSET(AFRegStl_stCllRich, 0x10);
               }
               else
               {
                  VEMS_vidSET(Srv_Fuel_System_Pid03, 0x02);
                  VEMS_vidSET(AFRegStl_stCllRich, 0x02);
               }
            }
            else
            {
               VEMS_vidSET(Srv_Fuel_System_Pid03, 0x00);
               VEMS_vidSET(AFRegStl_stCllRich, 0x00);
            }
         }
      }
   }

   if (  (Srv_prmByteAPid72_C == 1)
      || (Srv_prmByteAPid72_C == 3))
   {
      u8LocalBoostActStlDuCyReqCplm =
         (uint8)( (((65536 - u16LocalBoostAct_rDuCyReq) * 255) + 32768)
                / 65536);
   }
   else
   {
      u8LocalBoostActStlDuCyReqCplm = 0;
   }
   VEMS_vidSET(BoostActStl_rDuCyReqCplm, u8LocalBoostActStlDuCyReqCplm);

   if (  (Srv_prmByteAPid72_C == 2)
      || (Srv_prmByteAPid72_C == 3))
   {
      u8LocalTrbActStl_rOpTrbAct =
         (uint8)(((u16LocalTrbAct_rOpTrbAct * 255) + 32768) / 65536);
   }
   else
   {
      u8LocalTrbActStl_rOpTrbAct = 0;
   }
   VEMS_vidSET(TrbActStl_rOpTrbAct, u8LocalTrbActStl_rOpTrbAct);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INTOBDSRV_vid14PMH_Pid                                     */
/* !Description :  La production du PID OB est réalisée sur ¼ PMH et sur      */
/*                 récurrence temporelle quand le moteur n’est pas tournant.  */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Io_map_manifold_press_measured;                              */
/*  output uint8 Srv_pDsThrMes_Pid0B;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INTOBDSRV_vid14PMH_Pid(void)
{
   uint8  u8LocalSrv_pDsThrMes_Pid0B;
   uint16 u16LocalIo_manifold_press_meas;
   uint16 u16LocalSrv_pDsThrMes_Pid0B;


   VEMS_vidGET(Io_map_manifold_press_measured, u16LocalIo_manifold_press_meas);

   u16LocalSrv_pDsThrMes_Pid0B = (uint16)( ( u16LocalIo_manifold_press_meas
                                           + 63 )
                                         / 125);
   u8LocalSrv_pDsThrMes_Pid0B =
      (uint8)MATHSRV_udtMIN(u16LocalSrv_pDsThrMes_Pid0B, 255);
   VEMS_vidSET(Srv_pDsThrMes_Pid0B, u8LocalSrv_pDsThrMes_Pid0B);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INTOBDSRV_vidPMH_Pid                                       */
/* !Description :  La production des PID 06 et OC est réalisée sur événement  */
/*                 PMH et sur récurrence temporelle quand le moteur n’est pas */
/*                 tournant.                                                  */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Lambda_feedback;                                             */
/*  input uint16 Ext_nEng;                                                    */
/*  output uint8 Srv_Lfbk_Pid06;                                              */
/*  output uint8 AFRegStl_lamFb;                                              */
/*  output uint16 Srv_nEng_Pid0C;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INTOBDSRV_vidPMH_Pid(void)
{
   uint8  u8LocalSrv_Lfbk_Pid06;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalSrv_nEng_Pid0C;
   uint32 u32LocalSrv_nEng_Pid0C;
   sint16 s16LocalLambda_feedback;


   VEMS_vidGET(Lambda_feedback, s16LocalLambda_feedback);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   if (s16LocalLambda_feedback < 0)
   {
      u8LocalSrv_Lfbk_Pid06 = (uint8)( (s16LocalLambda_feedback / 1024) + 128);
   }
   else
   {
      u8LocalSrv_Lfbk_Pid06 = (uint8)( ( (s16LocalLambda_feedback + 512)
                                       / 1024)
                                     + 128);
   }

   VEMS_vidSET(Srv_Lfbk_Pid06, u8LocalSrv_Lfbk_Pid06);
   VEMS_vidSET(AFRegStl_lamFb, u8LocalSrv_Lfbk_Pid06);
   u32LocalSrv_nEng_Pid0C = (uint32)(u16LocalExt_nEng * 4);
   u16LocalSrv_nEng_Pid0C = (uint16)MATHSRV_udtMIN(u32LocalSrv_nEng_Pid0C,
                                                   65535);
   VEMS_vidSET(Srv_nEng_Pid0C,u16LocalSrv_nEng_Pid0C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INTOBDSRV_vidPMB_PID                                       */
/* !Description :  La production du PID 0E est réalisée sur PMB et sur        */
/*                 récurrence temporelle quand le moteur n’est pas tournant.  */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 IgSys_prm_agIgSpCyl[6];                                       */
/*  output uint8 Srv_IgCmd_Pid0E;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INTOBDSRV_vidPMB_PID(void)
{
   uint8 u8LocalIgSys_prm_agIgSpCyl;
   uint8 u8LocalSrv_IgCmd_Pid0E;


   VEMS_vidGET1DArrayElement(IgSys_prm_agIgSpCyl,
                             0,
                             u8LocalIgSys_prm_agIgSpCyl);

   u8LocalSrv_IgCmd_Pid0E =
      (uint8)(((3 * u8LocalIgSys_prm_agIgSpCyl) / 4) + 56);
   VEMS_vidSET(Srv_IgCmd_Pid0E, u8LocalSrv_IgCmd_Pid0E);
}

/*------------------------------- end of file --------------------------------*/