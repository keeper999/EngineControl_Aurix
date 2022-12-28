/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJCTL_INJFARCTLMGR                                     */
/* !Description     : INJCTL_INJFARCTLMGR component.                          */
/*                                                                            */
/* !Module          : INJCTL_INJFARCTLMGR                                     */
/* !Description     : MANAGER DE GESTION DE LA REGULATION DE RICHESSE         */
/*                                                                            */
/* !File            : INJCTL_INJFARCTLMGR_FCT2.C                              */
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
/*   1 / INJCTL_INJFARCTLMGR_vidFdRichCnd                                     */
/*   2 / INJCTL_INJFARCTLMGR_vidFdRegCnd                                      */
/*   3 / INJCTL_INJFARCTLMGR_vidGlobalCnd                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5147287 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/INJCTLSYS/INJCTL_INJFARCTLMGR/IN$*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   08 Apr 2014 $*/
/* $Author::   mbenfrad                               $$Date::   08 Apr 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "INJCTL_INJFARCTLMGR.h"
#include "INJCTL_INJFARCTLMGR_L.h"
#include "INJCTL_INJFARCTLMGR_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCTL_INJFARCTLMGR_vidFdRichCnd                           */
/* !Description :  Cette fonction permet de gérer les conditions de bouclage/ */
/*                 débouclage de la régulation de richesse pour une           */
/*                 configuration utilisant les modules FAR Valéo en injection */
/*                 indirecte.                                                 */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Obj_rich_charge_partielle;                                   */
/*  input uint16 Objectif_richesse_anti_k;                                    */
/*  input uint16 Eng_rlamRstrtSTT;                                            */
/*  input uint16 Obj_rich_pleine_charge;                                      */
/*  input uint16 Obj_rich_temperature_air;                                    */
/*  input uint32 OxC_rlamOxCHeatPhaReq;                                       */
/*  input uint8 Lambda_adapt_cond_thresh_low;                                 */
/*  input uint8 Lambda_adapt_cond_thresh_high;                                */
/*  input uint16 Lambda_disable_counter;                                      */
/*  input uint16 Lambda_disable_delay;                                        */
/*  input uint8 Lambda_adapt_cond_knk_thr_low;                                */
/*  input uint8 Lambda_adapt_cond_knk_thr_high;                               */
/*  input uint16 Lambda_disable_knk_counter;                                  */
/*  input uint16 Lambda_disable_knk_delay;                                    */
/*  input uint8 Lambda_adapt_cond_stt_thr_low;                                */
/*  input uint8 Lambda_adapt_cond_stt_thr_high;                               */
/*  input uint16 Lambda_disable_stt_counter;                                  */
/*  input uint16 Lambda_disable_stt_delay;                                    */
/*  output uint16 Lambda_disable_counter;                                     */
/*  output uint16 Lambda_disable_knk_counter;                                 */
/*  output uint16 Lambda_disable_stt_counter;                                 */
/*  output boolean InjCtl_bAcvLbCll;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCTL_INJFARCTLMGR_vidFdRichCnd(void)
{
   uint16  u16LocalThreshLow;
   uint16  u16LocalThreshHigh;
   uint16  u16LocalObj_rich_chrge_partielle;
   uint16  u16LocalObjectif_richesse_anti_k;
   uint16  u16LocalEng_rlamRstrtSTT;
   uint16  u16LocalObj_rich_pleine_charge;
   uint16  u16LocalObj_rich_temperature_air;
   uint16  u16LocalLambdaCounter;
   uint16  u16LocalLambdaKnkCounter;
   uint16  u16LocalLambdaDsbleSttCntr;
   uint32  u32LocalOxC_rlamOxCHeatPhaReq;


   VEMS_vidGET(Obj_rich_charge_partielle, u16LocalObj_rich_chrge_partielle);
   VEMS_vidGET(Objectif_richesse_anti_k, u16LocalObjectif_richesse_anti_k);
   VEMS_vidGET(Eng_rlamRstrtSTT, u16LocalEng_rlamRstrtSTT);
   VEMS_vidGET(Obj_rich_pleine_charge, u16LocalObj_rich_pleine_charge);
   VEMS_vidGET(Obj_rich_temperature_air, u16LocalObj_rich_temperature_air);
   VEMS_vidGET(OxC_rlamOxCHeatPhaReq, u32LocalOxC_rlamOxCHeatPhaReq);

   u16LocalThreshLow = (uint16)( ( (uint32)(Lambda_adapt_cond_thresh_low + 512)
                                 * 2560)
                               / 147);
   u16LocalThreshHigh = (uint16)( ( (uint32)( Lambda_adapt_cond_thresh_high
                                            + 512)
                                  * 2560)
                                / 147);

   u16LocalLambdaCounter = Lambda_disable_counter;
   if (  (  (Lambda_disable_counter != Lambda_disable_delay)
         && (u16LocalObj_rich_chrge_partielle > u16LocalThreshLow))
      || (  (Lambda_disable_counter == Lambda_disable_delay)
         && (u16LocalObj_rich_chrge_partielle > u16LocalThreshHigh))
      )
   {
      if ( Lambda_disable_counter > 0 )
      {
         u16LocalLambdaCounter = (uint16)(u16LocalLambdaCounter - 1);
      }
   }
   else
   {
      u16LocalLambdaCounter = Lambda_disable_delay;
   }
   Lambda_disable_counter = (uint16)MATHSRV_udtMIN(u16LocalLambdaCounter,
                                                   52428);

   u16LocalThreshLow = (uint16)( ( (uint32)(Lambda_adapt_cond_knk_thr_low + 512)
                                 * 2560)
                               / 147);
   u16LocalThreshHigh = (uint16)( ( (uint32)( Lambda_adapt_cond_knk_thr_high
                                            + 512)
                                  * 2560)
                                / 147);

   u16LocalLambdaKnkCounter = Lambda_disable_knk_counter;
   if (  (  (Lambda_disable_knk_counter != Lambda_disable_knk_delay)
         && (u16LocalObjectif_richesse_anti_k > u16LocalThreshLow))
      || (  (Lambda_disable_knk_counter == Lambda_disable_knk_delay)
         && (u16LocalObjectif_richesse_anti_k > u16LocalThreshHigh))
      )
   {
      if ( Lambda_disable_knk_counter > 0 )
      {
         u16LocalLambdaKnkCounter = (uint16)(u16LocalLambdaKnkCounter - 1);
      }
   }
   else
   {
      u16LocalLambdaKnkCounter = Lambda_disable_knk_delay;
   }
   Lambda_disable_knk_counter =
      (uint16)MATHSRV_udtMIN(u16LocalLambdaKnkCounter, 52428);

   u16LocalThreshLow = (uint16)( ( (uint32)( Lambda_adapt_cond_stt_thr_low
                                           * 2560)
                                 + 1310720)
                               / 147);
   u16LocalThreshHigh = (uint16)( ( (uint32)( Lambda_adapt_cond_stt_thr_high
                                            * 2560)
                                  + 1310720)
                                / 147);

   u16LocalLambdaDsbleSttCntr = Lambda_disable_stt_counter;
   if (  (  (Lambda_disable_stt_counter != Lambda_disable_stt_delay)
         && (u16LocalEng_rlamRstrtSTT > u16LocalThreshLow))
      || (  (Lambda_disable_stt_counter == Lambda_disable_stt_delay)
         && (u16LocalEng_rlamRstrtSTT > u16LocalThreshHigh))
      )
   {
      if ( Lambda_disable_stt_counter > 0 )
      {
         u16LocalLambdaDsbleSttCntr = (uint16)(u16LocalLambdaDsbleSttCntr - 1);
      }
   }
   else
   {
      u16LocalLambdaDsbleSttCntr = Lambda_disable_stt_delay;
   }
   Lambda_disable_stt_counter =
      (uint16)MATHSRV_udtMIN(u16LocalLambdaDsbleSttCntr,52428);

   if (  (Lambda_disable_counter != 0)
      && (Lambda_disable_knk_counter != 0)
      && (u16LocalObj_rich_pleine_charge <= RICHESSE_1)
      && (u16LocalObj_rich_temperature_air <= RICHESSE_1)
      && (Lambda_disable_stt_counter != 0)
      && (u32LocalOxC_rlamOxCHeatPhaReq == 8916) )
   {
      InjCtl_bAcvLbCll = 1;
   }
   else
   {
      InjCtl_bAcvLbCll = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCTL_INJFARCTLMGR_vidFdRegCnd                            */
/* !Description :  Cette fonction permet de gérer les conditions de bouclage/ */
/*                 débouclage de la régulation de richesse pour une           */
/*                 configuration utilisant les module FAR fournit par PSA ou  */
/*                 les moteurs de type injection directe.                     */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Obj_rich_en_regulation_richesse;                             */
/*  input uint8 InjCtl_rMixtSenO2CalcRichLoThd_C;                             */
/*  input uint8 InjCtl_rMixtSenO2CalcRichHiThd_C;                             */
/*  input uint16 InjCtl_ctLbDiRMixtSenO2Calc;                                 */
/*  input uint16 InjCtl_ctLbDiRMixtSenO2Calc_C;                               */
/*  input uint8 InjCtl_rMixtSenO2CalcLeanLoThd_C;                             */
/*  input uint8 InjCtl_rMixtSenO2CalcLeanHiThd_C;                             */
/*  output uint16 InjCtl_ctLbDiRMixtSenO2Calc;                                */
/*  output boolean InjCtl_bAcvLbCll;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCTL_INJFARCTLMGR_vidFdRegCnd(void)
{
   uint16  u16LocalThreshLow;
   uint16  u16LocalThreshHigh;
   uint16  u16LocalObj_rich_regulation;
   uint16  u16LocalLbDiRMixtSenO2Calc1;
   uint16  u16LocalLbDiRMixtSenO2Calc2;


   VEMS_vidGET(Obj_rich_en_regulation_richesse, u16LocalObj_rich_regulation);

   u16LocalThreshLow = (uint16)( ( (uint32)( InjCtl_rMixtSenO2CalcRichLoThd_C
                                           + 512)
                                 * 2560)
                               / 147);
   u16LocalThreshHigh = (uint16)( ( (uint32)( InjCtl_rMixtSenO2CalcRichHiThd_C
                                            + 512)
                                  * 2560)
                                / 147);

   if (  (  (InjCtl_ctLbDiRMixtSenO2Calc != InjCtl_ctLbDiRMixtSenO2Calc_C)
         && (u16LocalObj_rich_regulation > u16LocalThreshLow))
      || (  (InjCtl_ctLbDiRMixtSenO2Calc == InjCtl_ctLbDiRMixtSenO2Calc_C)
         && (u16LocalObj_rich_regulation > u16LocalThreshHigh))
      )
   {
      if ( InjCtl_ctLbDiRMixtSenO2Calc > 0 )
      {
         u16LocalLbDiRMixtSenO2Calc1 = (uint16)( InjCtl_ctLbDiRMixtSenO2Calc
                                               - 1);
      }
      else
      {
         u16LocalLbDiRMixtSenO2Calc1 = InjCtl_ctLbDiRMixtSenO2Calc;
      }
   }
   else
   {
      u16LocalLbDiRMixtSenO2Calc1 = InjCtl_ctLbDiRMixtSenO2Calc_C;
   }
   u16LocalLbDiRMixtSenO2Calc1 =
      (uint16)MATHSRV_udtMIN(u16LocalLbDiRMixtSenO2Calc1,52428);

   u16LocalThreshLow = (uint16)( ( (uint32)( InjCtl_rMixtSenO2CalcLeanLoThd_C
                                           + 256)
                                 * 2560)
                               / 147);
   u16LocalThreshHigh = (uint16)( ( (uint32)( InjCtl_rMixtSenO2CalcLeanHiThd_C
                                            + 256)
                                  * 2560)
                                / 147);

   if (  (  (InjCtl_ctLbDiRMixtSenO2Calc != InjCtl_ctLbDiRMixtSenO2Calc_C)
         && (u16LocalObj_rich_regulation < u16LocalThreshHigh))
      || (  (InjCtl_ctLbDiRMixtSenO2Calc == InjCtl_ctLbDiRMixtSenO2Calc_C)
         && (u16LocalObj_rich_regulation < u16LocalThreshLow))
      )
   {
      if ( InjCtl_ctLbDiRMixtSenO2Calc > 0 )
      {
         u16LocalLbDiRMixtSenO2Calc2 = (uint16)( InjCtl_ctLbDiRMixtSenO2Calc
                                                - 1);
      }
      else
      {
         u16LocalLbDiRMixtSenO2Calc2 = InjCtl_ctLbDiRMixtSenO2Calc;
      }
   }
   else
   {
      u16LocalLbDiRMixtSenO2Calc2 = InjCtl_ctLbDiRMixtSenO2Calc_C;
   }
   u16LocalLbDiRMixtSenO2Calc2 =
      (uint16)MATHSRV_udtMIN(u16LocalLbDiRMixtSenO2Calc2,52428);

   if (u16LocalObj_rich_regulation > 8916)
   {
      InjCtl_ctLbDiRMixtSenO2Calc = u16LocalLbDiRMixtSenO2Calc1;
   }
   else
   {
      InjCtl_ctLbDiRMixtSenO2Calc = u16LocalLbDiRMixtSenO2Calc2;
   }
   if (InjCtl_ctLbDiRMixtSenO2Calc != 0)
   {
      InjCtl_bAcvLbCll = 1;
   }
   else
   {
      InjCtl_bAcvLbCll = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCTL_INJFARCTLMGR_vidGlobalCnd                           */
/* !Description :  Cette fonction permet de désactiver le bouclage,lorsque un */
/*                 diagnostic intrusif pour la sonde aval est demandé, pour   */
/*                 permettre l’utilisation du créneau de richesse.            */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(uint16 u16Channel)boolean;                 */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Coupure_decel_progr_inj;                                      */
/*  input boolean FARSp_bEnaAntiStall;                                        */
/*  input boolean OxC_bMonRunORngIntr;                                        */
/*  input boolean LsMon_bAcvItrsvSenO2DsDiag;                                 */
/*  input boolean Test_bed_pulse;                                             */
/*  input boolean Manu_inh_lambda_feedback;                                   */
/*  input boolean InjCtl_bAcvLbCll;                                           */
/*  input boolean InjCtl_bAcvObjRichRegul_C;                                  */
/*  output boolean Lambda_cond_for_feedback;                                  */
/*  output boolean Lambda_cond_for_adaptation;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCTL_INJFARCTLMGR_vidGlobalCnd(void)
{
   boolean bLocalInhInjFarCtlMgrLbdFb;
   boolean bLocalCoupure_decel_progr_inj;
   boolean bLocalFARSp_bEnaAntiStall;
   boolean bLocalLambda_cond_for_feedback;
   boolean bLocalOxC_bMonRunORngIntr;
   boolean bLocalLsMon_bAcvItrsvSenO2DsDiag;
   uint8   u8LocalCoupure_decel_progr_inj;


   VEMS_vidGET(Coupure_decel_progr_inj, u8LocalCoupure_decel_progr_inj);
   VEMS_vidGET(FARSp_bEnaAntiStall, bLocalFARSp_bEnaAntiStall);
   VEMS_vidGET(OxC_bMonRunORngIntr, bLocalOxC_bMonRunORngIntr);
   VEMS_vidGET(LsMon_bAcvItrsvSenO2DsDiag, bLocalLsMon_bAcvItrsvSenO2DsDiag);

   bLocalInhInjFarCtlMgrLbdFb = GDGAR_bGetFRM(FRM_FRM_INHINJFARCTLMGRLBDFB);

   if (  ((u8LocalCoupure_decel_progr_inj & 0x01) == 0x01)
      || ((u8LocalCoupure_decel_progr_inj & 0x02) == 0x02)
      || ((u8LocalCoupure_decel_progr_inj & 0x04) == 0x04)
      || ((u8LocalCoupure_decel_progr_inj & 0x08) == 0x08))
   {
      bLocalCoupure_decel_progr_inj = 1;
   }
   else
   {
      bLocalCoupure_decel_progr_inj = 0;
   }
   if (  (bLocalCoupure_decel_progr_inj == 0)
      && (Test_bed_pulse == 0)
      && (Manu_inh_lambda_feedback == 0)
      && (bLocalInhInjFarCtlMgrLbdFb == 0)
      && (bLocalFARSp_bEnaAntiStall == 0)
      && (  (InjCtl_bAcvLbCll != 0)
         || (  (InjCtl_bAcvObjRichRegul_C != 0)
            && (bLocalOxC_bMonRunORngIntr != 0))))
   {
      VEMS_vidSET(Lambda_cond_for_feedback, 1);
      bLocalLambda_cond_for_feedback = 1;
   }
   else
   {
      VEMS_vidSET(Lambda_cond_for_feedback, 0);
      bLocalLambda_cond_for_feedback = 0;
   }
   if (  (bLocalLambda_cond_for_feedback != 0)
      && (bLocalOxC_bMonRunORngIntr == 0)
      && (bLocalLsMon_bAcvItrsvSenO2DsDiag == 0))
   {
      VEMS_vidSET(Lambda_cond_for_adaptation, 1);
   }
   else
   {
      VEMS_vidSET(Lambda_cond_for_adaptation, 0);
   }
}
/*------------------------------ end of file ---------------------------------*/