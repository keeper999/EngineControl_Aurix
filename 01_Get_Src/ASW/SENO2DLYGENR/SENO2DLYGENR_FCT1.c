/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SENO2DLYGENR                                            */
/* !Description     : SENO2DLYGENR Component                                  */
/*                                                                            */
/* !Module          : SENO2DLYGENR                                            */
/* !Description     : TEST BED MODE FOR THE UPSTREAM OXYGEN SENSOR VOLTAGE    */
/*                                                                            */
/* !File            : SENO2DLYGENR_FCT1.C                                     */
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
/*   1 / SENO2DLYGENR_vidInitOutput                                           */
/*   2 / SENO2DLYGENR_vidUpOxyTestBed                                         */
/*   3 / SENO2DLYGENR_vidUpOxyTestBedMode                                     */
/*   4 / SENO2DLYGENR_vidLeanRichInitDly                                      */
/*   5 / SENO2DLYGENR_vidRichLeanInitDly                                      */
/*   6 / SENO2DLYGENR_vidStatusRich                                           */
/*   7 / SENO2DLYGENR_vidStatusLean                                           */
/*                                                                            */
/* !Reference   : V02 NT 09 06150 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SENO2DLYGENR/SENO2DLYGENR_FCT1.C_v$*/
/* $Revision::   1.2      $$Author::   wbouach        $$Date::   15 Dec 2010 $*/
/* $Author::   wbouach                                $$Date::   15 Dec 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "SENO2DLYGENR.h"
#include "SENO2DLYGENR_L.h"
#include "SENO2DLYGENR_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SENO2DLYGENR_vidInitOutput                                 */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  BKBO                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Up_oxy_test_bed_voltage_v;                                  */
/*  output boolean Up_oxy_tb_rich_state_v;                                    */
/*  output uint32 Up_oxy_tb_rich_vs_lean_count_v;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SENO2DLYGENR_vidInitOutput(void)
{
   VEMS_vidSET(Up_oxy_test_bed_voltage_v, 0);
   Up_oxy_tb_rich_state_v = 0;
   Up_oxy_tb_rich_vs_lean_count_v = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SENO2DLYGENR_vidUpOxyTestBed                               */
/* !Description :  The strategy is activated in case the Boolean calibration  */
/*                 ‘Up_oxy_cfg_test_bed_enable_c0’ is set to ‘1’              */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  BKBO                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SENO2DLYGENR_vidUpOxyTestBedMode();                      */
/*  input boolean Up_oxy_cfg_test_bed_enable_c0;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SENO2DLYGENR_vidUpOxyTestBed(void)
{
   if (Up_oxy_cfg_test_bed_enable_c0 != 0)
   {
      SENO2DLYGENR_vidUpOxyTestBedMode();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SENO2DLYGENR_vidUpOxyTestBedMode                           */
/* !Description :  From the original upstream oxygen sensor voltage, we create*/
/*                 a new square signal that we can delay. The maximum delay   */
/*                 corresponds to one signal period.                          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  BKBO                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SENO2DLYGENR_vidLeanRichInitDly();                       */
/*  extf argret void SENO2DLYGENR_vidRichLeanInitDly();                       */
/*  extf argret void SENO2DLYGENR_vidStatusRich();                            */
/*  extf argret void SENO2DLYGENR_vidStatusLean();                            */
/*  input boolean Up_oxy_tb_rich_state_v;                                     */
/*  input uint16 Tension_sonde_amont_filtree;                                 */
/*  input uint16 Up_oxy_tb_low_rich_thresh_c0;                                */
/*  input uint16 Up_oxy_tb_high_rich_thresh_c0;                               */
/*  input uint32 Up_oxy_tb_lean_vs_rich_count_v;                              */
/*  input uint32 Up_oxy_tb_rich_vs_lean_count_v;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SENO2DLYGENR_vidUpOxyTestBedMode(void)
{
   boolean bLocalUpOxyTbRichStateVPrev;
   uint16  u16LocalTensionSondeAmontFiltree;


   bLocalUpOxyTbRichStateVPrev = Up_oxy_tb_rich_state_v;
   VEMS_vidGET(Tension_sonde_amont_filtree, u16LocalTensionSondeAmontFiltree);
   MATHSRV_vidSchmittTriggerU16(u16LocalTensionSondeAmontFiltree,
                                Up_oxy_tb_low_rich_thresh_c0,
                                Up_oxy_tb_high_rich_thresh_c0,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &Up_oxy_tb_rich_state_v);
   if (  (Up_oxy_tb_rich_state_v != 0)
      && (bLocalUpOxyTbRichStateVPrev == 0))
   {
      SENO2DLYGENR_vidLeanRichInitDly();
   }
   if (  (Up_oxy_tb_rich_state_v == 0)
      && (bLocalUpOxyTbRichStateVPrev != 0))
   {
      SENO2DLYGENR_vidRichLeanInitDly();
   }
   if (Up_oxy_tb_lean_vs_rich_count_v != 0)
   {
      SENO2DLYGENR_vidStatusRich();
   }
   if (Up_oxy_tb_rich_vs_lean_count_v != 0)
   {
      SENO2DLYGENR_vidStatusLean();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SENO2DLYGENR_vidLeanRichInitDly                            */
/* !Description :  At transition from lean to rich of the original signal, we */
/*                 initialise the delay before transition from lean to rich of*/
/*                 the generated signal.While the previous delay is not       */
/*                 elapsed, the transition is not carried out.                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  BKBO                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SENO2DLYGENR_vidLeanRichInit();                          */
/*  input uint32 Up_oxy_tb_lean_vs_rich_delay_c0;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SENO2DLYGENR_vidLeanRichInitDly(void)
{
   if (Up_oxy_tb_lean_vs_rich_delay_c0 != 0)
   {
      SENO2DLYGENR_vidLeanRichInit();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SENO2DLYGENR_vidRichLeanInitDly                            */
/* !Description :  At transition from rich to lean of the original signal, we */
/*                 initialise the delay before transition from rich to lean of*/
/*                 the generated signal. While the previous delay is not      */
/*                 elapsed, the transition is not carried out.                */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  BKBO                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SENO2DLYGENR_vidRichLeanInit();                          */
/*  input uint32 Up_oxy_tb_rich_vs_lean_delay_c0;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SENO2DLYGENR_vidRichLeanInitDly(void)
{
   if (Up_oxy_tb_rich_vs_lean_delay_c0 != 0)
   {
      SENO2DLYGENR_vidRichLeanInit();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SENO2DLYGENR_vidStatusRich                                 */
/* !Description :  function of status Rich                                    */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  BKBO                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SENO2DLYGENR_vidRichStatus();                            */
/*  input uint32 Up_oxy_tb_lean_vs_rich_count_v;                              */
/*  output uint32 Up_oxy_tb_lean_vs_rich_count_v;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SENO2DLYGENR_vidStatusRich(void)
{
   uint32 u32LocalLeanVsRichCountVPrev;
   uint32 u32LocalLeanVsRichCountV;


   u32LocalLeanVsRichCountVPrev = Up_oxy_tb_lean_vs_rich_count_v;
   if (Up_oxy_tb_lean_vs_rich_count_v > 0)
   {
      u32LocalLeanVsRichCountV = Up_oxy_tb_lean_vs_rich_count_v - 1;
      Up_oxy_tb_lean_vs_rich_count_v = MATHSRV_udtMIN(u32LocalLeanVsRichCountV,
                                                      204000);
   }
   else
   {
      Up_oxy_tb_lean_vs_rich_count_v = 0;
   }

   if (  (Up_oxy_tb_lean_vs_rich_count_v == 0)
      && (u32LocalLeanVsRichCountVPrev != 0))
   {
      SENO2DLYGENR_vidRichStatus();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SENO2DLYGENR_vidStatusLean                                 */
/* !Description :  function of status Lean                                    */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  BKBO                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SENO2DLYGENR_vidLeanStatus();                            */
/*  input uint32 Up_oxy_tb_rich_vs_lean_count_v;                              */
/*  output uint32 Up_oxy_tb_rich_vs_lean_count_v;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SENO2DLYGENR_vidStatusLean(void)
{
   uint32 u32LocalRichVsLeanCountVPrev;
   uint32 u32LocalRichVsLeanCountV;


   u32LocalRichVsLeanCountVPrev = Up_oxy_tb_rich_vs_lean_count_v;
   if (Up_oxy_tb_rich_vs_lean_count_v > 0)
   {
      u32LocalRichVsLeanCountV = Up_oxy_tb_rich_vs_lean_count_v - 1;
      Up_oxy_tb_rich_vs_lean_count_v = MATHSRV_udtMIN(u32LocalRichVsLeanCountV,
                                                      204000);
   }
   else
   {
      Up_oxy_tb_rich_vs_lean_count_v = 0;
   }

   if (  (Up_oxy_tb_rich_vs_lean_count_v == 0)
      && (u32LocalRichVsLeanCountVPrev != 0))
   {
      SENO2DLYGENR_vidLeanStatus();
   }
}

/*------------------------------- end of file --------------------------------*/