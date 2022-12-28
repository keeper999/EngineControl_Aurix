/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HOTSENO2FLG                                             */
/* !Description     : HOTSENO2FLG Component                                   */
/*                                                                            */
/* !Module          : HOTSENO2FLG                                             */
/* !Description     : Determination des sondes lambda chaudes                 */
/*                                                                            */
/* !File            : HOTSENO2FLG_FCT2.C                                      */
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
/*   1 / HOTSENO2FLG_vidDetSenO2UsHot                                         */
/*   2 / HOTSENO2FLG_vidDetSenO2UsCold                                        */
/*   3 / HOTSENO2FLG_vidDetSenO2Ds                                            */
/*   4 / HOTSENO2FLG_vidDetSenO2DsCold                                        */
/*   5 / HOTSENO2FLG_vidDetSenO2DsHot                                         */
/*   6 / HOTSENO2FLG_vidHotSenO2Heatst                                        */
/*   7 / HOTSENO2FLG_vidSenO2UsHot                                            */
/*   8 / HOTSENO2FLG_vidSenO2DsHot                                            */
/*   9 / HOTSENO2FLG_vidDetHotLsUS                                            */
/*   10 / HOTSENO2FLG_vidDetHotLsDs                                           */
/*                                                                            */
/* !Reference   : V02 NT 08 06204 / 07                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/HEATSENO2/HOTSENO2FLG/HOTSENO2FLG_$*/
/* $Revision::   1.5      $$Author::   wbouach        $$Date::   10 Aug 2011 $*/
/* $Author::   wbouach                                $$Date::   10 Aug 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "HOTSENO2FLG.H"
#include "HOTSENO2FLG_L.H"
#include "HOTSENO2FLG_IM.H"
#include "GDGAR.H"
#include "SWFAIL.h"
#include "VEMS.H"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HOTSENO2FLG_vidDetSenO2UsHot                               */
/* !Description :  Le signal utilisé est le signal sonde filtré afin d’éviter */
/*                 de fausses détections de sonde chaude dues à des           */
/*                 perturbations des signaux bruts                            */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Lshd_voltage_upstr_sens_filtered;                            */
/*  input uint16 Lshd_upstr_volt_low_thresh;                                  */
/*  input uint16 Lshd_upstr_volt_high_thresh;                                 */
/*  output boolean Lshd_up_stream_lbda_sensor_hot;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HOTSENO2FLG_vidDetSenO2UsHot(void)
{
   uint16  u16LocalLshd_voltage_upstr_sens;


   VEMS_vidGET(Lshd_voltage_upstr_sens_filtered,
               u16LocalLshd_voltage_upstr_sens);
   if (  (u16LocalLshd_voltage_upstr_sens < Lshd_upstr_volt_low_thresh)
      || (u16LocalLshd_voltage_upstr_sens > Lshd_upstr_volt_high_thresh) )
   {
      VEMS_vidSET(Lshd_up_stream_lbda_sensor_hot, 1);
   }
   else
   {
      VEMS_vidSET(Lshd_up_stream_lbda_sensor_hot, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HOTSENO2FLG_vidDetSenO2UsCold                              */
/* !Description :  Si le mélange oscille entre riche et pauvre, la tension va */
/*                 bagotter. La tension devra se trouver en dehors d’un       */
/*                 intervalle de tensions pour que la sonde puisse être       */
/*                 déclarée chaude.                                           */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Lshd_voltage_upstr_sens_filtered;                            */
/*  input uint16 Lshd_up_lbda_sens_heat_count;                                */
/*  input uint16 Lshd_upstr_volt_low_limit;                                   */
/*  input uint16 Lshd_upstr_volt_high_limit;                                  */
/*  input uint16 Lshd_up_lbda_sens_heat_delay;                                */
/*  output uint16 Lshd_up_lbda_sens_heat_count;                               */
/*  output boolean Lshd_up_stream_lbda_sensor_hot;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HOTSENO2FLG_vidDetSenO2UsCold(void)
{
   uint16 u16LocalLshd_voltage_upstr_sens;
   uint16 u16LocalLshd_up_sens_heat_cnt;


   VEMS_vidGET(Lshd_voltage_upstr_sens_filtered,
               u16LocalLshd_voltage_upstr_sens);
   VEMS_vidGET(Lshd_up_lbda_sens_heat_count,
               u16LocalLshd_up_sens_heat_cnt);
   if (  (u16LocalLshd_voltage_upstr_sens > Lshd_upstr_volt_low_limit)
      && (u16LocalLshd_voltage_upstr_sens < Lshd_upstr_volt_high_limit) )
   {
      if (u16LocalLshd_up_sens_heat_cnt > 0)
      {
         u16LocalLshd_up_sens_heat_cnt = (uint16)( u16LocalLshd_up_sens_heat_cnt
                                                 - 1);
      }
      else
      {
         u16LocalLshd_up_sens_heat_cnt = 0;
      }
   }
   else
   {
      u16LocalLshd_up_sens_heat_cnt = Lshd_up_lbda_sens_heat_delay;
   }
   u16LocalLshd_up_sens_heat_cnt =
      (uint16)MATHSRV_udtMIN(u16LocalLshd_up_sens_heat_cnt, 20470);
   VEMS_vidSET(Lshd_up_lbda_sens_heat_count, u16LocalLshd_up_sens_heat_cnt);
   if (u16LocalLshd_up_sens_heat_cnt == 0)
   {
      VEMS_vidSET(Lshd_up_stream_lbda_sensor_hot, 0);
   }
   else
   {
      VEMS_vidSET(Lshd_up_stream_lbda_sensor_hot, 1);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HOTSENO2FLG_vidDetSenO2Ds                                  */
/* !Description :  vérification que  la  tension de  la sonde à oxygène se    */
/*                 trouve hors d’une plage de  tension.                       */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HOTSENO2FLG_vidDetSenO2DsCold();                         */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void HOTSENO2FLG_vidDetSenO2DsHot();                          */
/*  input boolean Lshd_down_stream_lbda_sensor_hot;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HOTSENO2FLG_vidDetSenO2Ds(void)
{
   boolean bLocalInhHotSenO2FlgDs;
   boolean bLocalLshd_dwn_stream_sensor_hot;


   VEMS_vidGET(Lshd_down_stream_lbda_sensor_hot,
               bLocalLshd_dwn_stream_sensor_hot);

   if (bLocalLshd_dwn_stream_sensor_hot != 0)
   {
      HOTSENO2FLG_vidDetSenO2DsCold();
   }
   else
   {
      bLocalInhHotSenO2FlgDs = GDGAR_bGetFRM(FRM_FRM_INHHOTSENO2FLGDS);
      if (bLocalInhHotSenO2FlgDs == 0)
      {
         HOTSENO2FLG_vidDetSenO2DsHot();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HOTSENO2FLG_vidDetSenO2DsCold                              */
/* !Description :  Si le mélange oscille entre riche et pauvre, la tension va */
/*                 bagotter. La tension devra se trouver en dehors d’un       */
/*                 intervalle de tensions pour que la sonde puisse être       */
/*                 déclarée chaude.                                           */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Lshd_voltage_dnstr_sens_filtered;                            */
/*  input uint16 Lshd_dwn_lbda_sens_heat_count;                               */
/*  input uint16 Lshd_dwnstr_volt_low_limit;                                  */
/*  input uint16 Lshd_dwnstr_volt_high_limit;                                 */
/*  input uint16 Lshd_dwn_lbda_sens_heat_delay;                               */
/*  output uint16 Lshd_dwn_lbda_sens_heat_count;                              */
/*  output boolean Lshd_down_stream_lbda_sensor_hot;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HOTSENO2FLG_vidDetSenO2DsCold(void)
{
   uint16 u16LocalLshd_voltage_dnstr_sens;
   uint16 u16LocalLshd_dn_sens_heat_cnt;


   VEMS_vidGET(Lshd_voltage_dnstr_sens_filtered,
               u16LocalLshd_voltage_dnstr_sens);
   VEMS_vidGET(Lshd_dwn_lbda_sens_heat_count,
               u16LocalLshd_dn_sens_heat_cnt);
   if (  (u16LocalLshd_voltage_dnstr_sens > Lshd_dwnstr_volt_low_limit)
      && (u16LocalLshd_voltage_dnstr_sens < Lshd_dwnstr_volt_high_limit) )
   {
      if (u16LocalLshd_dn_sens_heat_cnt > 0)
      {
         u16LocalLshd_dn_sens_heat_cnt = (uint16)(u16LocalLshd_dn_sens_heat_cnt
                                                  - 1);
      }
      else
      {
         u16LocalLshd_dn_sens_heat_cnt = 0;
      }
   }
   else
   {
      u16LocalLshd_dn_sens_heat_cnt = Lshd_dwn_lbda_sens_heat_delay;
   }
   u16LocalLshd_dn_sens_heat_cnt =
      (uint16)MATHSRV_udtMIN(u16LocalLshd_dn_sens_heat_cnt, 20470);
   VEMS_vidSET(Lshd_dwn_lbda_sens_heat_count, u16LocalLshd_dn_sens_heat_cnt);
   if (u16LocalLshd_dn_sens_heat_cnt == 0)
   {
      VEMS_vidSET(Lshd_down_stream_lbda_sensor_hot, 0);
   }
   else
   {
      VEMS_vidSET(Lshd_down_stream_lbda_sensor_hot, 1);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HOTSENO2FLG_vidDetSenO2DsHot                               */
/* !Description :  Le signal utilisé est le signal sonde filtré afin d’éviter */
/*                 de fausses détections de sonde chaude dues à des           */
/*                 perturbations des signaux bruts.                           */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Lshd_voltage_dnstr_sens_filtered;                            */
/*  input uint16 Lshd_dwnstr_volt_low_thresh;                                 */
/*  input uint16 Lshd_dwnstr_volt_high_thresh;                                */
/*  output boolean Lshd_down_stream_lbda_sensor_hot;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HOTSENO2FLG_vidDetSenO2DsHot(void)
{
   uint16  u16LocalLshd_voltage_dnstr_sens;


   VEMS_vidGET(Lshd_voltage_dnstr_sens_filtered,
               u16LocalLshd_voltage_dnstr_sens);
   if (  (u16LocalLshd_voltage_dnstr_sens < Lshd_dwnstr_volt_low_thresh)
      || (u16LocalLshd_voltage_dnstr_sens > Lshd_dwnstr_volt_high_thresh) )
   {
      VEMS_vidSET(Lshd_down_stream_lbda_sensor_hot, 1);
   }
   else
   {
      VEMS_vidSET(Lshd_down_stream_lbda_sensor_hot, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HOTSENO2FLG_vidHotSenO2Heatst                              */
/* !Description :   Les sondes sont considérées chaudes lorsqu'une durée      */
/*                 calibrable s'est écoulée depuis que l'automate de chauffage*/
/*                 est rentré en phase E en passant par les phases (C1 ou C2) */
/*                 ou D, ou lorsque l'on a quitté la phase A pour la phase E  */
/*                 directement.                                               */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HOTSENO2FLG_vidSenO2UsHot();                             */
/*  extf argret void HOTSENO2FLG_vidSenO2DsHot();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HOTSENO2FLG_vidHotSenO2Heatst(void)
{
   HOTSENO2FLG_vidSenO2UsHot();
   HOTSENO2FLG_vidSenO2DsHot();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HOTSENO2FLG_vidSenO2UsHot                                  */
/* !Description :  La sonde est considérée chaude  et prête pour le diagnostic*/
/*                 losrque  LsSys_b[LsUsMainOxCHeatOkDiag==1                  */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_R_08_06204_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HOTSENO2FLG_vidDetHotLsUS();                             */
/*  input st71 LsSys_stLsUsMainOxCHeat;                                       */
/*  input uint8 HOTSENO2FLG_u8UsMainOxCHeatPrev;                              */
/*  input uint8 LsSys_tiLsUsDlyHeatNotOk_C;                                   */
/*  input uint8 LsSys_tiLsUsDlyHeatOkHotStrt_C;                               */
/*  input uint8 LsSys_tiLsUsDlyHeatOkColdStrt_C;                              */
/*  input boolean LsSys_bLsUsHeatOk;                                          */
/*  input boolean HOTSENO2FLG_bInitTimer3Prev;                                */
/*  input uint16 LsSys_tiLsUsDlyHeat;                                         */
/*  output uint16 LsSys_tiLsUsDlyHeat;                                        */
/*  output boolean LsSys_bLsUsHeatOk;                                         */
/*  output uint8 HOTSENO2FLG_u8UsMainOxCHeatPrev;                             */
/*  output boolean HOTSENO2FLG_bInitTimer3Prev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HOTSENO2FLG_vidSenO2UsHot(void)
{
   boolean bLocalTimerInit;
   boolean bLocalLsSys_bLsUsHeatOkPrev;
   uint8   u8LocalLsSys_stLsUsMainOxCHeat;
   uint16  u16LocalDuration;
   uint16  u16LocalLsSys_tiLsUsDlyHeat;


   VEMS_vidGET(LsSys_stLsUsMainOxCHeat, u8LocalLsSys_stLsUsMainOxCHeat);
   /*bLocalTimerInit*/
   if (  ( (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_E)
         &&( (HOTSENO2FLG_u8UsMainOxCHeatPrev == LSUSMAINOXCHEAT_PHASE_C1)
           ||(HOTSENO2FLG_u8UsMainOxCHeatPrev == LSUSMAINOXCHEAT_PHASE_C2)))
      || (  (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_E)
         && (HOTSENO2FLG_u8UsMainOxCHeatPrev == LSUSMAINOXCHEAT_PHASE_D) )
      || (  (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_E)
         && (HOTSENO2FLG_u8UsMainOxCHeatPrev == LSUSMAINOXCHEAT_PHASE_A) )
      || (  (  (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_A)
            || (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_F)
            || (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_G) )
         && (  (HOTSENO2FLG_u8UsMainOxCHeatPrev != LSUSMAINOXCHEAT_PHASE_A)
            && (HOTSENO2FLG_u8UsMainOxCHeatPrev != LSUSMAINOXCHEAT_PHASE_F)
            && (HOTSENO2FLG_u8UsMainOxCHeatPrev != LSUSMAINOXCHEAT_PHASE_G) )))
   {
      bLocalTimerInit = 1;
   }
   else
   {
      bLocalTimerInit = 0;
   }

   /*Duration*/
   switch (u8LocalLsSys_stLsUsMainOxCHeat)
   {
      case LSUSMAINOXCHEAT_PHASE_A :
      case LSUSMAINOXCHEAT_PHASE_F :
      case LSUSMAINOXCHEAT_PHASE_G :
         u16LocalDuration = (uint16)(LsSys_tiLsUsDlyHeatNotOk_C * 10);
         break;

      case LSUSMAINOXCHEAT_PHASE_E :
         if (HOTSENO2FLG_u8UsMainOxCHeatPrev == LSUSMAINOXCHEAT_PHASE_A)
         {
            u16LocalDuration = (uint16)(LsSys_tiLsUsDlyHeatOkHotStrt_C * 10);
         }
         else
         {
            u16LocalDuration = (uint16)(LsSys_tiLsUsDlyHeatOkColdStrt_C * 10);
         }
         break;

      default:
         u16LocalDuration = 0;
         break;
   }

   bLocalLsSys_bLsUsHeatOkPrev = LsSys_bLsUsHeatOk;
   /*timer*/
   if (  (HOTSENO2FLG_bInitTimer3Prev == 0)
      && (bLocalTimerInit != 0))
   {
      LsSys_tiLsUsDlyHeat = u16LocalDuration;
      if (LsSys_tiLsUsDlyHeat == 0)
      {
         LsSys_bLsUsHeatOk = 1;
      }
      else
      {
         LsSys_bLsUsHeatOk = 0;
      }
   }
   else
   {
      if (LsSys_tiLsUsDlyHeat > 0)
      {
         u16LocalLsSys_tiLsUsDlyHeat = (uint16)(LsSys_tiLsUsDlyHeat - 1);
         LsSys_tiLsUsDlyHeat =
            (uint16)MATHSRV_udtMIN(u16LocalLsSys_tiLsUsDlyHeat, 2559);
         if (LsSys_tiLsUsDlyHeat == 0)
         {
            LsSys_bLsUsHeatOk = 1;
         }
         else
         {
            LsSys_bLsUsHeatOk = 0;
         }
      }
   }

   if (  (bLocalLsSys_bLsUsHeatOkPrev == 0)
      && (LsSys_bLsUsHeatOk != 0))
   {
      HOTSENO2FLG_vidDetHotLsUS();
   }
   /*** End Bloc TIMER ***/
   HOTSENO2FLG_u8UsMainOxCHeatPrev = u8LocalLsSys_stLsUsMainOxCHeat;
   HOTSENO2FLG_bInitTimer3Prev = bLocalTimerInit;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HOTSENO2FLG_vidSenO2DsHot                                  */
/* !Description :  La détection de la sonde se basant sur les états de        */
/*                 l’automate de chauffage estime qu’au bout d’une certaine   */
/*                 durée la sonde est suffisamment chauffée                   */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_R_08_06204_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HOTSENO2FLG_vidDetHotLsDs();                             */
/*  input st70 LsSys_stLsDsMainOxCHeat;                                       */
/*  input uint8 HOTSENO2FLG_u8DsMainOxCHeatPrev;                              */
/*  input uint8 LsSys_tiLsDsDlyHeatNotOk_C;                                   */
/*  input uint8 LsSys_tiLsDsDlyHeatOkHotStrt_C;                               */
/*  input uint8 LsSys_tiLsDsDlyHeatOkColdStrt_C;                              */
/*  input boolean LsSys_bLsDsHeatOk;                                          */
/*  input boolean HOTSENO2FLG_bInitTimer2Prev;                                */
/*  input uint16 LsSys_tiLsDsDlyHeat;                                         */
/*  output uint16 LsSys_tiLsDsDlyHeat;                                        */
/*  output boolean LsSys_bLsDsHeatOk;                                         */
/*  output uint8 HOTSENO2FLG_u8DsMainOxCHeatPrev;                             */
/*  output boolean HOTSENO2FLG_bInitTimer2Prev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HOTSENO2FLG_vidSenO2DsHot(void)
{
   boolean bLocalInitTimer;
   boolean bLocalLsSys_bLsDsHeatOkPrev;
   uint8   u8LocalLsSys_stLsDsMainOxCHeat;
   uint16  u16LocalLsSys_tiLsDsDlyHeat;
   uint16  u16LocalDuration;


   VEMS_vidGET(LsSys_stLsDsMainOxCHeat, u8LocalLsSys_stLsDsMainOxCHeat);

   if (  ( (u8LocalLsSys_stLsDsMainOxCHeat == LSDSMAINOXCHEAT_PHASE_E)
         &&( (HOTSENO2FLG_u8DsMainOxCHeatPrev == LSDSMAINOXCHEAT_PHASE_C1)
           ||(HOTSENO2FLG_u8DsMainOxCHeatPrev == LSDSMAINOXCHEAT_PHASE_C2)))
      || (   (u8LocalLsSys_stLsDsMainOxCHeat == LSDSMAINOXCHEAT_PHASE_E)
         && (HOTSENO2FLG_u8DsMainOxCHeatPrev == LSDSMAINOXCHEAT_PHASE_D) )
      || (  (u8LocalLsSys_stLsDsMainOxCHeat == LSDSMAINOXCHEAT_PHASE_E)
         && (HOTSENO2FLG_u8DsMainOxCHeatPrev == LSDSMAINOXCHEAT_PHASE_A) )
      || (  (  (u8LocalLsSys_stLsDsMainOxCHeat == LSDSMAINOXCHEAT_PHASE_A)
            || (u8LocalLsSys_stLsDsMainOxCHeat == LSDSMAINOXCHEAT_PHASE_F)
            || (u8LocalLsSys_stLsDsMainOxCHeat == LSDSMAINOXCHEAT_PHASE_G) )
         && (  (HOTSENO2FLG_u8DsMainOxCHeatPrev != LSDSMAINOXCHEAT_PHASE_A)
            && (HOTSENO2FLG_u8DsMainOxCHeatPrev != LSDSMAINOXCHEAT_PHASE_F)
            && (HOTSENO2FLG_u8DsMainOxCHeatPrev != LSDSMAINOXCHEAT_PHASE_G) )))
   {
      bLocalInitTimer = 1;
   }
   else
   {
      bLocalInitTimer = 0;
   }

   switch (u8LocalLsSys_stLsDsMainOxCHeat)
   {
      case LSDSMAINOXCHEAT_PHASE_A :
      case LSDSMAINOXCHEAT_PHASE_F :
      case LSDSMAINOXCHEAT_PHASE_G :
         u16LocalDuration = (uint16)(LsSys_tiLsDsDlyHeatNotOk_C * 10);
         break;

      case LSDSMAINOXCHEAT_PHASE_E :
         if (HOTSENO2FLG_u8DsMainOxCHeatPrev == LSDSMAINOXCHEAT_PHASE_A)
         {
            u16LocalDuration = (uint16)(LsSys_tiLsDsDlyHeatOkHotStrt_C * 10);
         }
         else
         {
            u16LocalDuration = (uint16)(LsSys_tiLsDsDlyHeatOkColdStrt_C * 10);
         }
         break;
      default:
         u16LocalDuration = 0;
         break;
   }
   bLocalLsSys_bLsDsHeatOkPrev = LsSys_bLsDsHeatOk;
   /*timer*/
   if (  (HOTSENO2FLG_bInitTimer2Prev == 0)
      && (bLocalInitTimer != 0) )
   {
      LsSys_tiLsDsDlyHeat = u16LocalDuration;
      if (LsSys_tiLsDsDlyHeat == 0)
      {
         LsSys_bLsDsHeatOk = 1;
      }
      else
      {
         LsSys_bLsDsHeatOk = 0;
      }
   }
   else
   {
      if (LsSys_tiLsDsDlyHeat > 0)
      {
         u16LocalLsSys_tiLsDsDlyHeat = (uint16)(LsSys_tiLsDsDlyHeat - 1);
         LsSys_tiLsDsDlyHeat =
            (uint16)MATHSRV_udtMIN(u16LocalLsSys_tiLsDsDlyHeat, 2559);
         if (LsSys_tiLsDsDlyHeat == 0)
         {
            LsSys_bLsDsHeatOk = 1;
         }
         else
         {
            LsSys_bLsDsHeatOk = 0;
         }
      }
   }

   if (  (bLocalLsSys_bLsDsHeatOkPrev == 0)
      && (LsSys_bLsDsHeatOk != 0) )
   {
      HOTSENO2FLG_vidDetHotLsDs();
   }

   HOTSENO2FLG_u8DsMainOxCHeatPrev = u8LocalLsSys_stLsDsMainOxCHeat;
   HOTSENO2FLG_bInitTimer2Prev = bLocalInitTimer;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HOTSENO2FLG_vidDetHotLsUS                                  */
/* !Description :  Inversement lorsque l’automate retourne dans les phases de */
/*                 chauffage reduit ou nulle (A, F ou G) la sonde est déclarée*/
/*                 froide au bout d’une certaine duree.                       */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st71 LsSys_stLsUsMainOxCHeat;                                       */
/*  output boolean LsSys_bLsUsMainOxCHeatOkdiag;                              */
/*  output boolean LsSys_bLsUsMainOxCHeatOk;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HOTSENO2FLG_vidDetHotLsUS(void)
{
   uint8   u8LocalLsSys_stLsUsMainOxCHeat;


   VEMS_vidGET(LsSys_stLsUsMainOxCHeat, u8LocalLsSys_stLsUsMainOxCHeat);

   if (  (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_A)
      || (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_F)
      || (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_G))
   {
      VEMS_vidSET(LsSys_bLsUsMainOxCHeatOkdiag, 0);
      VEMS_vidSET(LsSys_bLsUsMainOxCHeatOk, 0);
   }
   else
   {
      VEMS_vidSET(LsSys_bLsUsMainOxCHeatOkdiag, 1);
      VEMS_vidSET(LsSys_bLsUsMainOxCHeatOk, 1);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HOTSENO2FLG_vidDetHotLsDs                                  */
/* !Description :  Inversement lorsque l’automate retourne dans les phases de */
/*                 chauffage réduit ou nulle (A, F ou G) la sonde est déclarée*/
/*                 froide au bout d’une certaine durée.                       */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st70 LsSys_stLsDsMainOxCHeat;                                       */
/*  output boolean LsSys_bLsDsMainOxCHeatOkdiag;                              */
/*  output boolean LsSys_bLsDsMainOxCHeatOk;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HOTSENO2FLG_vidDetHotLsDs(void)
{
   uint8   u8LocalLsSys_stLsDsMainOxCHeat;


   VEMS_vidGET(LsSys_stLsDsMainOxCHeat, u8LocalLsSys_stLsDsMainOxCHeat);

   if ( (u8LocalLsSys_stLsDsMainOxCHeat == LSDSMAINOXCHEAT_PHASE_A)
      ||(u8LocalLsSys_stLsDsMainOxCHeat == LSDSMAINOXCHEAT_PHASE_F)
      ||(u8LocalLsSys_stLsDsMainOxCHeat == LSDSMAINOXCHEAT_PHASE_G) )
   {
      VEMS_vidSET(LsSys_bLsDsMainOxCHeatOkdiag, 0);
      VEMS_vidSET(LsSys_bLsDsMainOxCHeatOk, 0);
   }
   else
   {
      VEMS_vidSET(LsSys_bLsDsMainOxCHeatOkdiag, 1);
      VEMS_vidSET(LsSys_bLsDsMainOxCHeatOk, 1);
   }
}
/*------------------------------- end of file --------------------------------*/