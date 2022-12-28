/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINVLVBENCHMOD                                     */
/* !Description     : VLVACTINVLVBENCHMOD component.                          */
/*                                                                            */
/* !Module          : VLVACTINVLVBENCHMOD                                     */
/* !Description     : INTAKE VARIABLE VALVE TIMING SETPOINT IN BENCH MODE     */
/*                                                                            */
/* !File            : VLVACTINVLVBENCHMOD_FCT1.C                              */
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
/*   1 / VLVACTINVLVBENCHMOD_vidIniInVlv                                      */
/*   2 / VLVACTINVLVBENCHMOD_vidInVlv                                         */
/*   3 / VLVACTINVLVBENCHMOD_vidClcInVlv                                      */
/*                                                                            */
/* !Reference   : V02 NT 09 07770 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINVLVBENCHMOD/VLV$*/
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
                                      temp.mde producing this kind of error   */
#include "VLVACTINVLVBENCHMOD.h"
#include "VLVACTINVLVBENCHMOD_L.h"
#include "VLVACTINVLVBENCHMOD_IM.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINVLVBENCHMOD_vidIniInVlv                            */
/* !Description :  output initialization                                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvAct_agCkInVlvBenchModIniSp_C;                             */
/*  input uint16 Io_map_manifold_press_measured;                              */
/*  input uint16 VLVACTINVLVBENCHMOD_u16IoFldPrev;                            */
/*  output uint16 VlvAct_agCkInVlvSpBenchMod;                                 */
/*  output boolean VlvAct_bInVlvSpBenchModEna;                                */
/*  output uint16 VLVACTINVLVBENCHMOD_u16IoFldPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINVLVBENCHMOD_vidIniInVlv(void)
{
   uint16 u16LocalVlvAct_agCkInVlvSpBchMd;

   u16LocalVlvAct_agCkInVlvSpBchMd =
      (uint16)MATHSRV_udtMIN(VlvAct_agCkInVlvBenchModIniSp_C, 1066);
   VEMS_vidSET(VlvAct_agCkInVlvSpBenchMod, u16LocalVlvAct_agCkInVlvSpBchMd);

   VEMS_vidSET(VlvAct_bInVlvSpBenchModEna, 0);

   /* Initialize previous value of Io_map_manifold_press_measured */
   VEMS_vidGET(Io_map_manifold_press_measured,
               VLVACTINVLVBENCHMOD_u16IoFldPrev);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINVLVBENCHMOD_vidInVlv                               */
/* !Description :  Inhibit the calculation of the intake valve bench mode     */
/*                 setpoint when the bench mode is not enabled                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void VLVACTINVLVBENCHMOD_vidClcInVlv();                       */
/*  input boolean VlvAct_bInVlvSpBenchModEna_C;                               */
/*  output boolean VlvAct_bInVlvSpBenchModEna;                                */
/*  output boolean VlvAct_bInVlvSpBenchModEna_C;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINVLVBENCHMOD_vidInVlv(void)
{
   VEMS_vidSET(VlvAct_bInVlvSpBenchModEna, VlvAct_bInVlvSpBenchModEna_C);
   if (VlvAct_bInVlvSpBenchModEna_C != 0)
   {
      VLVACTINVLVBENCHMOD_vidClcInVlv();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINVLVBENCHMOD_vidClcInVlv                            */
/* !Description :  Compute the intake valve setpoint in bench mode            */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 VlvAct_agCkInVlvSpBenchMod;                                  */
/*  input uint16 Io_map_manifold_press_measured;                              */
/*  input boolean VlvAct_bInVlvSpManSelTyp_C;                                 */
/*  input uint16 VlvAct_agCkInVlvManModSp_C;                                  */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 VlvAct_nEngY_A[24];                                          */
/*  input boolean VlvAct_bInVlvSpThrSelTyp_C;                                 */
/*  input uint16 Ssm_filt_throttle_position;                                  */
/*  input uint16 VlvAct_posnThrX_A[16];                                       */
/*  input uint16 VlvAct_agCkInSp_posnThrX_nEngY_M[16][24];                    */
/*  input boolean VlvAct_bInVlvSpTqSelTyp_C;                                  */
/*  input sint16 TqSys_tqIdcAirReq;                                           */
/*  input uint16 VlvAct_tqIdcAirX_A[16];                                      */
/*  input uint16 VlvAct_agCkInSp_tqAirX_nEngY_M[16][24];                      */
/*  input uint16 VlvAct_pInMnfX_A[16];                                        */
/*  input uint16 VlvAct_agCkInSp_pInMnfX_nEngY_M[16][24];                     */
/*  input uint16 VlvAct_agCkInVlvBenchModPrevSp;                              */
/*  input uint16 VlvAct_agCkInBenchModSpMaxRate_C;                            */
/*  input uint16 VlvAct_agCkInBenchModSpMinRate_C;                            */
/*  input uint16 VLVACTINVLVBENCHMOD_u16IoFldPrev;                            */
/*  input uint16 VlvAct_pInVlvAbsDifDB_C;                                     */
/*  output uint16 VlvAct_agCkInVlvBenchModPrevSp;                             */
/*  output uint16 VLVACTINVLVBENCHMOD_u16IoFldPrev;                           */
/*  output uint16 VlvAct_agCkInVlvSpBenchMod;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINVLVBENCHMOD_vidClcInVlv(void)
{
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   uint16 u16LocalSsm_filt_throttle_pos;
   uint16 u16Local_Regime_moteur;
   uint16 u16Local_TqSys_tqIdcAirReq;
   uint16 u16LocalIo_map_manifol_pres_meas;
   uint16 u16LocalRw_VlvAct_CkInVlvSpBchMd;
   uint16 u16LocalVlvAct_agCkInVlvSpBchMd;
   uint16 u16LocalVlvAct_agCkInSpBenchMod;
   uint16 u16LocalSlewRateOut;
   uint16 u16LocalABS;
   sint16 s16Local_TqSys_tqIdcAirReq;
   sint32 s32Local_TqSys_tqIdcAirReq;
   sint32 s32LocalDiff;


   VEMS_vidGET(VlvAct_agCkInVlvSpBenchMod, u16LocalVlvAct_agCkInSpBenchMod);
   VlvAct_agCkInVlvBenchModPrevSp =
      (uint16)MATHSRV_udtMIN(u16LocalVlvAct_agCkInSpBenchMod, 1066);

   VEMS_vidGET(Io_map_manifold_press_measured,
               u16LocalIo_map_manifol_pres_meas);
   if (VlvAct_bInVlvSpManSelTyp_C != 0)
   {
      u16LocalRw_VlvAct_CkInVlvSpBchMd = VlvAct_agCkInVlvManModSp_C;
   }
   else
   {
      VEMS_vidGET(Regime_moteur, u16Local_Regime_moteur);
      u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(VlvAct_nEngY_A,
                                                   u16Local_Regime_moteur,
                                                   24);
      if (VlvAct_bInVlvSpThrSelTyp_C != 0)
      {
         VEMS_vidGET(Ssm_filt_throttle_position,
                     u16LocalSsm_filt_throttle_pos);
         u16LocalParaX =
            MATHSRV_u16CalcParaIncAryU16(VlvAct_posnThrX_A,
                                         u16LocalSsm_filt_throttle_pos,
                                         16);
         u16LocalRw_VlvAct_CkInVlvSpBchMd =
            MATHSRV_u16Interp2d(&VlvAct_agCkInSp_posnThrX_nEngY_M[0][0],
                                u16LocalParaX,
                                u16LocalParaY,
                                24);
      }
      else
      {
         if (VlvAct_bInVlvSpTqSelTyp_C != 0)
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
            u16LocalRw_VlvAct_CkInVlvSpBchMd =
               MATHSRV_u16Interp2d(&VlvAct_agCkInSp_tqAirX_nEngY_M[0][0],
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
            u16LocalRw_VlvAct_CkInVlvSpBchMd =
               MATHSRV_u16Interp2d(&VlvAct_agCkInSp_pInMnfX_nEngY_M[0][0],
                                   u16LocalParaX,
                                   u16LocalParaY,
                                   24);
         }
      }
   }
   u16LocalSlewRateOut =
      MATHSRV_u16SlewFilter(VlvAct_agCkInVlvBenchModPrevSp,
                            u16LocalRw_VlvAct_CkInVlvSpBchMd,
                            VlvAct_agCkInBenchModSpMaxRate_C,
                            VlvAct_agCkInBenchModSpMinRate_C);

   s32LocalDiff = ( u16LocalIo_map_manifol_pres_meas
                  - VLVACTINVLVBENCHMOD_u16IoFldPrev);
   u16LocalABS = (uint16)MATHSRV_udtABS(s32LocalDiff);

   if (  (VlvAct_bInVlvSpManSelTyp_C !=0)
      || (VlvAct_bInVlvSpThrSelTyp_C !=0)
      || (VlvAct_bInVlvSpTqSelTyp_C!=0)
      || (u16LocalABS >= VlvAct_pInVlvAbsDifDB_C))
   {
      u16LocalVlvAct_agCkInVlvSpBchMd = u16LocalSlewRateOut;
   }
   else
   {
      u16LocalVlvAct_agCkInVlvSpBchMd = VlvAct_agCkInVlvBenchModPrevSp;
   }

   VLVACTINVLVBENCHMOD_u16IoFldPrev = u16LocalIo_map_manifol_pres_meas;

   u16LocalVlvAct_agCkInVlvSpBchMd =
      (uint16)MATHSRV_udtMIN(u16LocalVlvAct_agCkInVlvSpBchMd, 1066);

   VEMS_vidSET(VlvAct_agCkInVlvSpBenchMod, u16LocalVlvAct_agCkInVlvSpBchMd);
}
/*----------------------------end of file-------------------------------------*/