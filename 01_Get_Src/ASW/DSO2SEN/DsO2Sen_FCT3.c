/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DSO2SEN                                                 */
/* !Description     : DSO2SEN Component                                       */
/*                                                                            */
/* !Module          : DSO2SEN                                                 */
/* !Description     : ACQUISITION DE LA SONDE A OXYGENE AVAL                  */
/*                                                                            */
/* !File            : DSO2SEN_FCT3.C                                          */
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
/*   1 / DSO2SEN_vidDefaultOCSO2                                              */
/*   2 / DSO2SEN_vidBenchModeDownStream                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_6563982 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/DSO2SEN/DSO2SEN_FCT3.C_v          $*/
/* $Revision::   1.3                                                         $*/
/* $Author::   wbouach                                $$Date::   14 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "DSO2SEN.h"
#include "DSO2SEN_L.h"
#include "DSO2SEN_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DSO2SEN_vidDefaultOCSO2                                    */
/* !Description :  Ce bloc permet de détecter l’absence de sonde aval ou la   */
/*                 mauvaise connexion.                                        */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_05194_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Plus_sonde_o2_av_result_ad_conv;                             */
/*  input uint16 Ldsd_sensor_dead_zone_lo_thresh;                             */
/*  input uint16 Ldsd_sensor_dead_zone_hi_thresh;                             */
/*  input uint16 Ldsd_sensor_dead_zone_count;                                 */
/*  input uint8 Ldsd_sensor_dead_zone_inc_step;                               */
/*  input uint8 Ldsd_sensor_dead_zone_dec_step;                               */
/*  input boolean Ext_bMonRunOc_uDsLs;                                        */
/*  input uint16 Ldsd_sensor_dead_zone_thresh;                                */
/*  output uint16 Ldsd_sensor_dead_zone_count;                                */
/*  output boolean Ext_bDgoOc_uDsLs;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DSO2SEN_vidDefaultOCSO2(void)
{
   uint32  u32LocalCounterMaxCalc;


   if (  (Plus_sonde_o2_av_result_ad_conv > Ldsd_sensor_dead_zone_lo_thresh)
      && (Plus_sonde_o2_av_result_ad_conv < Ldsd_sensor_dead_zone_hi_thresh))
   {
      u32LocalCounterMaxCalc =
         (uint32)(Ldsd_sensor_dead_zone_count + Ldsd_sensor_dead_zone_inc_step);
      Ldsd_sensor_dead_zone_count =
         (uint16)MATHSRV_udtMIN(u32LocalCounterMaxCalc, 65535);
   }
   else
   {
      if (Ldsd_sensor_dead_zone_count > Ldsd_sensor_dead_zone_dec_step)
      {
         Ldsd_sensor_dead_zone_count =
         (uint16)(Ldsd_sensor_dead_zone_count - Ldsd_sensor_dead_zone_dec_step);
      }
      else
      {
         Ldsd_sensor_dead_zone_count = 0;
      }
   }

   if (Ext_bMonRunOc_uDsLs != 0)
   {
      if (Ldsd_sensor_dead_zone_count >= Ldsd_sensor_dead_zone_thresh)
      {
         Ext_bDgoOc_uDsLs = 1;
      }
      else
      {
         Ext_bDgoOc_uDsLs = 0;
      }
   }
   else
   {
      Ext_bDgoOc_uDsLs = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DSO2SEN_vidBenchModeDownStream                             */
/* !Description :  Fonction de simulation du comportement d’une sonde viellie */
/*                 permettant la calibration du diagnostic dérivée de la sonde*/
/*                 aval.                                                      */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint16 Tension_sonde_aval_int;                                      */
/*  input uint16 Sonde_aval_slew_rate;                                        */
/*  output uint16 Tension_sonde_aval;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DSO2SEN_vidBenchModeDownStream(void)
{
   uint16 u16LocalSlewRateOut;
   uint16 u16LocalTension_sonde_aval;


   VEMS_vidGET(Tension_sonde_aval, u16LocalTension_sonde_aval);
   u16LocalSlewRateOut = MATHSRV_u16SlewFilter(u16LocalTension_sonde_aval,
                                               Tension_sonde_aval_int,
                                               Sonde_aval_slew_rate,
                                               Sonde_aval_slew_rate);

   u16LocalSlewRateOut = (uint16)MATHSRV_udtMIN(u16LocalSlewRateOut, 1023);
   VEMS_vidSET(Tension_sonde_aval, u16LocalSlewRateOut);
}
/*-------------------------------- end of file -------------------------------*/