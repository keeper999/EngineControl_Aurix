/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXVLVBENCHMOD                                     */
/* !Description     : VLVACTEXVLVBENCHMOD component.                          */
/*                                                                            */
/* !Module          : VLVACTEXVLVBENCHMOD                                     */
/* !Description     : EXHAUST VARIABLE VALVE TIMING SETPOINT IN BENCH MODE    */
/*                                                                            */
/* !File            : VLVACTEXVLVBENCHMOD_FCT1.C                              */
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
/*   1 / VLVACTEXVLVBENCHMOD_vidIniExVlv                                      */
/*   2 / VLVACTEXVLVBENCHMOD_vidExVlv                                         */
/*   3 / VLVACTEXVLVBENCHMOD_vidCalcExVlv                                     */
/*                                                                            */
/* !Reference   : V02 NT 09 08224 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXVLVBENCHMOD/VLV$*/
/* $Revision::   1.1      $$Author::   mbenfrad       $$Date::   28 Mar 2013 $*/
/* $Author::   mbenfrad                               $$Date::   28 Mar 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
/*QAC Warning(2:0838): Std_Types.h is included in all files generated from
  temp.mde producing this kind of error                                      */
#include "VLVACTEXVLVBENCHMOD.h"
#include "VLVACTEXVLVBENCHMOD_L.h"
#include "VLVACTEXVLVBENCHMOD_IM.h"
#include "VEMS.H"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXVLVBENCHMOD_vidIniExVlv                            */
/* !Description :  Outputs Initialization                                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvAct_agCkExVlvBenchModIniSp_C;                             */
/*  input uint16 Io_map_manifold_press_measured;                              */
/*  input uint16 VLVACTEXVLVBENCHMOD_u16IoFldPrev;                            */
/*  output uint16 VlvAct_agCkExVlvSpBenchMod;                                 */
/*  output boolean VlvAct_bExVlvSpBenchModEna;                                */
/*  output uint16 VLVACTEXVLVBENCHMOD_u16IoFldPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXVLVBENCHMOD_vidIniExVlv(void)
{
   uint16 u16LocalVlvAct_agCkExVlvSpBchMd;

   u16LocalVlvAct_agCkExVlvSpBchMd =
      (uint16)MATHSRV_udtMIN(VlvAct_agCkExVlvBenchModIniSp_C, 1066);
   VEMS_vidSET(VlvAct_agCkExVlvSpBenchMod, u16LocalVlvAct_agCkExVlvSpBchMd);

   VEMS_vidSET(VlvAct_bExVlvSpBenchModEna, 0);

   /* Exitialize previous value of Io_map_manifold_press_measured */
   VEMS_vidGET(Io_map_manifold_press_measured,
               VLVACTEXVLVBENCHMOD_u16IoFldPrev);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXVLVBENCHMOD_vidExVlv                               */
/* !Description :  Inhibit the calculation of the exhaust valve bench mode    */
/*                 setpoint when the bench mode is not enabled                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void VLVACTEXVLVBENCHMOD_vidCalcExVlv();                      */
/*  input boolean VlvAct_bExVlvSpBenchModEna_C;                               */
/*  output boolean VlvAct_bExVlvSpBenchModEna;                                */
/*  output boolean VlvAct_bExVlvSpBenchModEna_C;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXVLVBENCHMOD_vidExVlv(void)
{
   VEMS_vidSET(VlvAct_bExVlvSpBenchModEna, VlvAct_bExVlvSpBenchModEna_C);
   if(VlvAct_bExVlvSpBenchModEna_C != 0)
   {
      VLVACTEXVLVBENCHMOD_vidCalcExVlv();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXVLVBENCHMOD_vidCalcExVlv                           */
/* !Description :  Compute the exhaust valve setpoint in bench mode           */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 VlvAct_agCkExVlvSpBenchMod;                                  */
/*  input uint16 Io_map_manifold_press_measured;                              */
/*  input boolean VlvAct_bExVlvSpManSelTyp_C;                                 */
/*  input uint16 VlvAct_agCkExVlvManModSp_C;                                  */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 VlvAct_nEngY_A[24];                                          */
/*  input boolean VlvAct_bExVlvSpThrSelTyp_C;                                 */
/*  input uint16 Ssm_filt_throttle_position;                                  */
/*  input uint16 VlvAct_posnThrX_A[16];                                       */
/*  input uint16 VlvAct_agCkExSp_posnThrX_nEngY_M[16][24];                    */
/*  input boolean VlvAct_bExVlvSpTqSelTyp_C;                                  */
/*  input sint16 TqSys_tqIdcAirReq;                                           */
/*  input uint16 VlvAct_tqIdcAirX_A[16];                                      */
/*  input uint16 VlvAct_agCkExSp_tqAirX_nEngY_M[16][24];                      */
/*  input uint16 VlvAct_pInMnfX_A[16];                                        */
/*  input uint16 VlvAct_agCkExSp_pInMnfX_nEngY_M[16][24];                     */
/*  input uint16 VlvAct_agCkExVlvBenchModPrevSp;                              */
/*  input uint16 VlvAct_agCkExBenchModSpMaxRate_C;                            */
/*  input uint16 VlvAct_agCkExBenchModSpMinRate_C;                            */
/*  input uint16 VLVACTEXVLVBENCHMOD_u16IoFldPrev;                            */
/*  input uint16 VlvAct_pExVlvAbsDifDB_C;                                     */
/*  output uint16 VlvAct_agCkExVlvBenchModPrevSp;                             */
/*  output uint16 VLVACTEXVLVBENCHMOD_u16IoFldPrev;                           */
/*  output uint16 VlvAct_agCkExVlvSpBenchMod;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXVLVBENCHMOD_vidCalcExVlv(void)
{
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   uint16 u16LocalSsm_filt_throttle_pos;
   uint16 u16Local_Regime_moteur;
   uint16 u16Local_TqSys_tqIdcAirReq;
   uint16 u16LocalIo_map_manifol_pres_meas;
   uint16 u16LocalRw_VlvAct_CkExVlvSpBchMd;
   uint16 u16LocalVlvAct_agCkExVlvSpBchMd;
   uint16 u16LocalVlvAct_agCkExSpBenchMod;
   uint16 u16LocalSlewRateOut;
   uint16 u16LocalABS;
   sint16 s16Local_TqSys_tqIdcAirReq;
   sint32 s32Local_TqSys_tqIdcAirReq;
   sint32 s32LocalDiff;


   VEMS_vidGET(VlvAct_agCkExVlvSpBenchMod, u16LocalVlvAct_agCkExSpBenchMod);
   VlvAct_agCkExVlvBenchModPrevSp =
      (uint16)MATHSRV_udtMIN(u16LocalVlvAct_agCkExSpBenchMod, 1066);

   VEMS_vidGET(Io_map_manifold_press_measured,
               u16LocalIo_map_manifol_pres_meas);
   if (VlvAct_bExVlvSpManSelTyp_C != 0)
   {
      u16LocalRw_VlvAct_CkExVlvSpBchMd = VlvAct_agCkExVlvManModSp_C;
   }
   else
   {
      VEMS_vidGET(Regime_moteur, u16Local_Regime_moteur);
      u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(VlvAct_nEngY_A,
                                                   u16Local_Regime_moteur,
                                                   24);
      if (VlvAct_bExVlvSpThrSelTyp_C != 0)
      {
         VEMS_vidGET(Ssm_filt_throttle_position,
                     u16LocalSsm_filt_throttle_pos);
         u16LocalParaX =
            MATHSRV_u16CalcParaIncAryU16(VlvAct_posnThrX_A,
                                         u16LocalSsm_filt_throttle_pos,
                                         16);
         u16LocalRw_VlvAct_CkExVlvSpBchMd =
            MATHSRV_u16Interp2d(&VlvAct_agCkExSp_posnThrX_nEngY_M[0][0],
                                u16LocalParaX,
                                u16LocalParaY,
                                24);
      }
      else
      {
         if (VlvAct_bExVlvSpTqSelTyp_C != 0)
         {
            VEMS_vidGET(TqSys_tqIdcAirReq, s16Local_TqSys_tqIdcAirReq);
            s32Local_TqSys_tqIdcAirReq =
               (sint32)(s16Local_TqSys_tqIdcAirReq + 32000);
            u16Local_TqSys_tqIdcAirReq =
               (uint16)MATHSRV_udtCLAMP(s32Local_TqSys_tqIdcAirReq,
                                        0,
                                        64000);
            u16LocalParaX =
               MATHSRV_u16CalcParaIncAryU16(VlvAct_tqIdcAirX_A,
                                            u16Local_TqSys_tqIdcAirReq,
                                            16);
            u16LocalRw_VlvAct_CkExVlvSpBchMd =
               MATHSRV_u16Interp2d(&VlvAct_agCkExSp_tqAirX_nEngY_M[0][0],
                                   u16LocalParaX,
                                   u16LocalParaY,
                                   24);
         }
         else
         {
            u16LocalParaX =
               MATHSRV_u16CalcParaIncAryU16(VlvAct_pInMnfX_A,
                                            u16LocalIo_map_manifol_pres_meas,
                                            16);
            u16LocalRw_VlvAct_CkExVlvSpBchMd =
               MATHSRV_u16Interp2d(&VlvAct_agCkExSp_pInMnfX_nEngY_M[0][0],
                                   u16LocalParaX,
                                   u16LocalParaY,
                                   24);
         }
      }
   }
   u16LocalSlewRateOut =
      MATHSRV_u16SlewFilter(VlvAct_agCkExVlvBenchModPrevSp,
                            u16LocalRw_VlvAct_CkExVlvSpBchMd,
                            VlvAct_agCkExBenchModSpMaxRate_C,
                            VlvAct_agCkExBenchModSpMinRate_C);

   s32LocalDiff = ( u16LocalIo_map_manifol_pres_meas
                  - VLVACTEXVLVBENCHMOD_u16IoFldPrev);
   u16LocalABS = (uint16)MATHSRV_udtABS(s32LocalDiff);

   if (  (VlvAct_bExVlvSpManSelTyp_C !=0)
      || (VlvAct_bExVlvSpThrSelTyp_C !=0)
      || (VlvAct_bExVlvSpTqSelTyp_C!=0)
      || (u16LocalABS >= VlvAct_pExVlvAbsDifDB_C))
   {
      u16LocalVlvAct_agCkExVlvSpBchMd = u16LocalSlewRateOut;
   }
   else
   {
      u16LocalVlvAct_agCkExVlvSpBchMd = VlvAct_agCkExVlvBenchModPrevSp;
   }

   VLVACTEXVLVBENCHMOD_u16IoFldPrev = u16LocalIo_map_manifol_pres_meas;

   u16LocalVlvAct_agCkExVlvSpBchMd =
      (uint16)MATHSRV_udtMIN(u16LocalVlvAct_agCkExVlvSpBchMd, 1066);

   VEMS_vidSET(VlvAct_agCkExVlvSpBenchMod, u16LocalVlvAct_agCkExVlvSpBchMd);
}
/*----------------------------end of file-------------------------------------*/