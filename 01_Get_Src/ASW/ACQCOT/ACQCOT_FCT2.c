/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQCOT                                                  */
/* !Description     : ACQCOT Component                                        */
/*                                                                            */
/* !Module          : ACQCOT                                                  */
/* !Description     : ACQUISITION DE LA TEMPERATURE D’EAU                     */
/*                                                                            */
/* !File            : ACQCOT_FCT2.C                                           */
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
/*   1 / ACQCOT_vidCrTRunWaterTemp                                            */
/*   2 / ACQCOT_vidRunWaterTemp                                               */
/*   3 / ACQCOT_vidStallWaterTemp                                             */
/*   4 / ACQCOT_vidWaterCalTemp                                               */
/*   5 / ACQCOT_vidStoragetCoPwrl                                             */
/*   6 / ACQCOT_NVMSRV_vidInit                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_6529851 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ACQCOT/ACQCOT_FCT2.C_v            $*/
/* $Revision::   1.6      $$Author::   wbouach        $$Date::   14 May 2014 $*/
/* $Author::   wbouach                                $$Date::   14 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ACQCOT.h"
#include "ACQCOT_L.h"
#include "ACQCOT_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCOT_vidCrTRunWaterTemp                                  */
/* !Description :  Fonction de production de Crank_to_run_water_temp          */
/*                 représentant la température à l'événement crank to run.    */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(uint16 index)boolean;                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Cts_raw_range_temp;                                          */
/*  input boolean Ext_bDgoScp_tCoMes;                                         */
/*  input boolean Ext_bDgoScg_tCoMes;                                         */
/*  input boolean Ext_bDgoOc_tCoMes;                                          */
/*  input boolean Ext_bDgoGrd_tCoMes;                                         */
/*  input uint8 Temperature_eau;                                              */
/*  output sint16 Ext_tCoStrtMes;                                             */
/*  output uint8 Crank_to_run_water_temp;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCOT_vidCrTRunWaterTemp(void)
{
   boolean bLocalAcvMod_TCoMes;
   uint8   u8LocalCrankToRunWaterTemp;
   uint8   u8LocalTemperature_eau;
   uint16  u16LocalCts_raw_range_temp;
   sint16  s16LocalExtTCoStrtMes;


   VEMS_vidGET(Cts_raw_range_temp, u16LocalCts_raw_range_temp);
   bLocalAcvMod_TCoMes = GDGAR_bGetFRM(FRM_FRM_ACVMOD_TCOMES);
   if (  (Ext_bDgoScp_tCoMes == 0)
      && (Ext_bDgoScg_tCoMes == 0)
      && (Ext_bDgoOc_tCoMes == 0)
      && (bLocalAcvMod_TCoMes == 0)
      && (Ext_bDgoGrd_tCoMes == 0))
   {
      s16LocalExtTCoStrtMes = (sint16)( (u16LocalCts_raw_range_temp / 128)
                                      - 256);
      if (u16LocalCts_raw_range_temp > 27648)
      {
         u16LocalCts_raw_range_temp = (uint16)( ( ( u16LocalCts_raw_range_temp
                                                  - 27648)
                                                + 40)
                                              / 80);
         u8LocalCrankToRunWaterTemp =
            (uint8)MATHSRV_udtMIN(u16LocalCts_raw_range_temp, 255);
      }
      else
      {
         u8LocalCrankToRunWaterTemp = 0;
      }
   }
   else
   {
      VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
      u8LocalCrankToRunWaterTemp = u8LocalTemperature_eau;
      s16LocalExtTCoStrtMes = (sint16)(((u8LocalTemperature_eau * 5) / 8) - 40);
   }
   s16LocalExtTCoStrtMes =
      (sint16)MATHSRV_udtCLAMP( s16LocalExtTCoStrtMes, -40, 214);
   VEMS_vidSET(Ext_tCoStrtMes, s16LocalExtTCoStrtMes);
   VEMS_vidSET(Crank_to_run_water_temp, u8LocalCrankToRunWaterTemp);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCOT_vidRunWaterTemp                                     */
/* !Description :  Fonction de production de la variable                      */
/*                 Temperature_eau_a_stall.                                   */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQCOT_vidWaterCalTemp();                                */
/*  input st23 Vehicle_active_state;                                          */
/*  input st08 Power_conditions_state;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCOT_vidRunWaterTemp(void)
{
   uint8 u8LocalVehActiveState;
   uint8 u8LocalPowerCndState;


   VEMS_vidGET(Vehicle_active_state, u8LocalVehActiveState);
   VEMS_vidGET(Power_conditions_state, u8LocalPowerCndState);
   if (  (u8LocalVehActiveState == VS_STALL)
      && (u8LocalPowerCndState == POWER_ON))
   {
      ACQCOT_vidWaterCalTemp();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCOT_vidStallWaterTemp                                   */
/* !Description :  Fonction d'actualisation de la variable                    */
/*                 Temperature_eau_a_stall lors d'un démarrage.               */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void GDGAR_bGetFRM(uint16 index)boolean;                      */
/*  input uint16 Acq_tension_capt_temp_eau;                                   */
/*  input uint16 Cts_range_conv_bkpt_map[33];                                 */
/*  input uint16 Cts_range_conv_map[33];                                      */
/*  input boolean Ext_bDgoScp_tCoMes;                                         */
/*  input boolean Ext_bDgoScg_tCoMes;                                         */
/*  input boolean Ext_bDgoOc_tCoMes;                                          */
/*  input boolean Ext_bDgoGrd_tCoMes;                                         */
/*  input uint8 Temperature_eau;                                              */
/*  output uint16 Cts_range_voltage;                                          */
/*  output uint8 Temperature_eau_a_stall;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCOT_vidStallWaterTemp(void)
{
   boolean bLocalAcvMod_TCoMes;
   uint8   u8LocalTemperature_eau_a_stall;
   uint8   u8LocalTemperature_eau;
   uint16  u16LocalCalcPara;
   uint16  u16LocalCalcInterp;
   uint16  u16LocalCts_range_voltage;
   uint16  u16LocalAcqtensioncapt_temp_eau;
   uint16  u16LocalData;


   VEMS_vidGET(Acq_tension_capt_temp_eau, u16LocalAcqtensioncapt_temp_eau);

   u16LocalData = (uint16)((uint32)(u16LocalAcqtensioncapt_temp_eau + 2) / 4);
   u16LocalCts_range_voltage = (uint16)MATHSRV_udtMIN(u16LocalData, 1024);
   VEMS_vidSET(Cts_range_voltage, u16LocalCts_range_voltage);

   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(Cts_range_conv_bkpt_map,
                                                   u16LocalCts_range_voltage,
                                                   33);
   u16LocalCalcInterp = MATHSRV_u16Interp1d(Cts_range_conv_map,
                                            u16LocalCalcPara);
   bLocalAcvMod_TCoMes = GDGAR_bGetFRM(FRM_FRM_ACVMOD_TCOMES);
   if (  (Ext_bDgoScp_tCoMes == 0)
      && (Ext_bDgoScg_tCoMes == 0)
      && (Ext_bDgoOc_tCoMes == 0)
      && (bLocalAcvMod_TCoMes == 0)
      && (Ext_bDgoGrd_tCoMes == 0))
   {
      if (u16LocalCalcInterp > 27648)
      {
         u16LocalCalcInterp = (uint16)((u16LocalCalcInterp - 27648) / 80);
         u8LocalTemperature_eau_a_stall =
            (uint8)MATHSRV_udtMIN(u16LocalCalcInterp, 255);
      }
      else
      {
         u8LocalTemperature_eau_a_stall = 0;
      }
   }
   else
   {
      VEMS_vidGET(Temperature_eau,  u8LocalTemperature_eau);
      u8LocalTemperature_eau_a_stall = u8LocalTemperature_eau;
   }
   VEMS_vidSET (Temperature_eau_a_stall, u8LocalTemperature_eau_a_stall);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCOT_vidWaterCalTemp                                     */
/* !Description :  Fonction de mise à jour de la variable                     */
/*                 Temperature_eau_a_stall.                                   */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Temperature_eau;                                              */
/*  output uint8 Temperature_eau_a_stall;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCOT_vidWaterCalTemp(void)
{
   uint8 u8LocalTemperature_eau;


   VEMS_vidGET (Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidSET (Temperature_eau_a_stall, u8LocalTemperature_eau);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCOT_vidStoragetCoPwrl                                   */
/* !Description :  la variable Ext_tCoMesPwrl est rafraîchie sur l’évènement  */
/*                 powerlatch                                                 */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Ext_tCoMes;                                                  */
/*  output sint16 Ext_tCoMesPwrl;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCOT_vidStoragetCoPwrl(void)
{
   sint16 s16LocalExt_tCoMes;
   sint16 s16LocalExt_tCoMesPwrl;


   VEMS_vidGET (Ext_tCoMes, s16LocalExt_tCoMes);
   s16LocalExt_tCoMesPwrl =
      (sint16)MATHSRV_udtCLAMP (s16LocalExt_tCoMes, -40, 214);
   VEMS_vidSET (Ext_tCoMesPwrl, s16LocalExt_tCoMesPwrl);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCOT_NVMSRV_vidInit                                      */
/* !Description :  La variable Ext_tCoMesPwrl est initialisée à la            */
/*                 réinitialisation  de l' EEPROM avec la calibration         */
/*                 Ext_tCoMesPwrl_C.                                          */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Ext_tCoMesPwrl_C;                                            */
/*  output sint16 Ext_tCoMesPwrl;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCOT_NVMSRV_vidInit(void)
{
   sint16 s16LocalExt_tCoMesPwrl;


   s16LocalExt_tCoMesPwrl =
     (sint16)MATHSRV_udtCLAMP (Ext_tCoMesPwrl_C, -40, 214);
   VEMS_vidSET (Ext_tCoMesPwrl, s16LocalExt_tCoMesPwrl);
}
/*------------------------------- end of file --------------------------------*/