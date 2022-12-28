/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJFARCTLDSCTL                                          */
/* !Description     : INJFARCTLDSCTL Component                                */
/*                                                                            */
/* !Module          : INJFARCTLDSCTL                                          */
/* !Description     : REGULATION DE RICHESSE PAR LA SONDE A OXYGENE AVAL      */
/*                    (DOUBLE BOUCLE)                                         */
/*                                                                            */
/* !File            : INJFARCTLDSCTL_FCT2.C                                   */
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
/*   1 / INJFARCTLDSCTL_WaitCtrlCondTrans                                     */
/*   2 / INJFARCTLDSCTL_WaitOffDlyTrans                                       */
/*   3 / INJFARCTLDSCTL_DownStrmSenTrans                                      */
/*   4 / INJFARCTLDSCTL_PurgeCataTrans                                        */
/*   5 / INJFARCTLDSCTL_vidInitParam                                          */
/*   6 / INJFARCTLDSCTL_vidResetOffset                                        */
/*   7 / INJFARCTLDSCTL_vidSaveFeedbackCr                                     */
/*   8 / INJFARCTLDSCTL_vidResetOffsetVal                                     */
/*   9 / INJFARCTLDSCTL_vidInitEntryDly                                       */
/*   10 / INJFARCTLDSCTL_vidInitSetlingDly                                    */
/*                                                                            */
/* !Reference   : V02 NT 08 05886 / 09                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/INJ/INJCTL/INJFARCTLDSCTL/INJFARCT$*/
/* $Revision::   1.8      $$Author::   ACHEBINO       $$Date::   16 Jan 2012 $*/
/* $Author::   ACHEBINO                               $$Date::   16 Jan 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "GDGAR.h"
#include "INJFARCTLDSCTL.h"
#include "INJFARCTLDSCTL_L.h"
#include "INJFARCTLDSCTL_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_WaitCtrlCondTrans                           */
/* !Description :  Transition de WAITING_FOR_DNSTR_CTRL_CONDS vers            */
/*                 WAITING_FOR_OFFSET_DELAY                                   */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void INJFARCTLDSCTL_vidInitSetlingDly();                      */
/*  input boolean Lshd_down_stream_lbda_sensor_hot;                           */
/*  input boolean Manu_inh_lambda_feedback;                                   */
/*  input boolean Dnstr_conds_met;                                            */
/*  input uint16 Dnstr_entry_delay;                                           */
/*  output st49 Current_dnstr_correction_state;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_WaitCtrlCondTrans(void)
{
   boolean bLocalINHINJFARCTLDSCTLDBLLOOP;
   boolean bLocalLshdDownStrmLbdaSensorHot;
   boolean bLocalDnstr_conds_met;


   bLocalINHINJFARCTLDSCTLDBLLOOP =
                              GDGAR_bGetFRM(FRM_FRM_INHINJFARCTLDSCTLDBLLOOP);

   VEMS_vidGET(Lshd_down_stream_lbda_sensor_hot,
               bLocalLshdDownStrmLbdaSensorHot);
   if (  (bLocalINHINJFARCTLDSCTLDBLLOOP != 0)
      || (Manu_inh_lambda_feedback != 0)
      || (bLocalLshdDownStrmLbdaSensorHot == 0) )
   {
      VEMS_vidSET(Current_dnstr_correction_state, WAITING_DNSTR_GENERAL_CONDS);
   }
   else
   {
      VEMS_vidGET(Dnstr_conds_met, bLocalDnstr_conds_met);
      if (  (bLocalDnstr_conds_met != 0)
         && (Dnstr_entry_delay == 0))
      {
         VEMS_vidSET(Current_dnstr_correction_state, WAITING_FOR_OFFSET_DELAY);
         /*InjCtl_EveSetlingDly_FarCtlDsCtl*/
         INJFARCTLDSCTL_vidInitSetlingDly();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_WaitOffDlyTrans                             */
/* !Description :  Transition WAITING_FOR_OFFSET_DELAY  vers les différentes  */
/*                 états                                                      */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLDSCTL_vidResetOffset();                         */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void INJFARCTLDSCTL_vidInitEntryDly();                        */
/*  extf argret void INJFARCTLDSCTL_vidInitPurgeCata();                       */
/*  extf argret void INJFARCTLDSCTL_vidPurgeCata();                           */
/*  extf argret void INJFARCTLDSCTL_vidCalcErrTension();                      */
/*  extf argret void INJFARCTLDSCTL_vidCalcErrTenGain();                      */
/*  extf argret void INJFARCTLDSCTL_vidFeedbackCorr();                        */
/*  input boolean Lshd_down_stream_lbda_sensor_hot;                           */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint16 Dnstr_down_stream_ref_voltage;                               */
/*  input uint16 Dnstr_fenetre_activation_bas;                                */
/*  input uint16 Dnstr_fenetre_activation_haut;                               */
/*  input boolean Manu_inh_lambda_feedback;                                   */
/*  input boolean Dnstr_conds_met;                                            */
/*  input uint16 Dnstr_settling_delay;                                        */
/*  input boolean Dnstr_purge_cata_low;                                       */
/*  input boolean Dnstr_purge_cata_rich;                                      */
/*  output boolean Dnstr_purge_cata_low;                                      */
/*  output boolean Dnstr_purge_cata_rich;                                     */
/*  output st49 Current_dnstr_correction_state;                               */
/*  output boolean INJFARCTLDSCTL_bEnableCalcModif;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_WaitOffDlyTrans(void)
{
   boolean bLocalINHINJFARCTLDSCTLDBLLOOP;
   boolean bLocalLshdDownStrmLbdaSensorHot;
   boolean bLocalDnstr_conds_met;
   boolean bLocalDnstr_purge_cata_low;
   boolean bLocalDnstr_purge_cata_rich;
   uint16  u16LocalTensionSondeAval;
   uint32  u32LocalAdd;
   sint32  s32LocalDiff;


   bLocalINHINJFARCTLDSCTLDBLLOOP =
                              GDGAR_bGetFRM(FRM_FRM_INHINJFARCTLDSCTLDBLLOOP);

   VEMS_vidGET(Lshd_down_stream_lbda_sensor_hot,
               bLocalLshdDownStrmLbdaSensorHot);
   VEMS_vidGET(Tension_sonde_aval, u16LocalTensionSondeAval);
   s32LocalDiff = (sint32)(Dnstr_down_stream_ref_voltage
                          - Dnstr_fenetre_activation_bas);
   u32LocalAdd = (uint32)(Dnstr_down_stream_ref_voltage
                         + Dnstr_fenetre_activation_haut);

   if (  (bLocalINHINJFARCTLDSCTLDBLLOOP != 0)
      || (Manu_inh_lambda_feedback != 0)
      || (bLocalLshdDownStrmLbdaSensorHot == 0) )
   {
      /*InjCtl_EveRstOfsRich_FarCtlDsCtl*/
      INJFARCTLDSCTL_vidResetOffset();
      VEMS_vidSET(Dnstr_purge_cata_low, 0);
      VEMS_vidSET(Dnstr_purge_cata_rich, 0);
      VEMS_vidSET(Current_dnstr_correction_state, WAITING_DNSTR_GENERAL_CONDS);
   }
   else
   {
      VEMS_vidGET(Dnstr_conds_met, bLocalDnstr_conds_met);
      if (bLocalDnstr_conds_met == 0)
      {
         /*InjCtl_EveRstOfsRich_FarCtlDsCtl*/
         INJFARCTLDSCTL_vidResetOffset();
         VEMS_vidSET(Dnstr_purge_cata_low, 0);
         VEMS_vidSET(Dnstr_purge_cata_rich, 0);
         VEMS_vidSET(Current_dnstr_correction_state,
                     WAITING_FOR_DNSTR_CTRL_CONDS);
         /*InjCtl_EveEntryDly_FarCtlDsCtl*/
         INJFARCTLDSCTL_vidInitEntryDly();
         INJFARCTLDSCTL_bEnableCalcModif = 1;
      }
      else
      {
         if (Dnstr_settling_delay == 0)
         {
            if (u16LocalTensionSondeAval < s32LocalDiff)
            {
               VEMS_vidSET(Dnstr_purge_cata_low, 1);
            }
            else
            {
               VEMS_vidSET(Dnstr_purge_cata_low, 0);
            }
            if ( u16LocalTensionSondeAval > u32LocalAdd)
            {
               VEMS_vidSET(Dnstr_purge_cata_rich, 1);
            }
            else
            {
               VEMS_vidSET(Dnstr_purge_cata_rich, 0);
            }
            VEMS_vidGET(Dnstr_purge_cata_low, bLocalDnstr_purge_cata_low);
            VEMS_vidGET(Dnstr_purge_cata_rich, bLocalDnstr_purge_cata_rich);
            if (  (bLocalDnstr_purge_cata_low != 0)
               || (bLocalDnstr_purge_cata_rich != 0)
               )
            {
               VEMS_vidSET(Current_dnstr_correction_state, DNSTR_PURGE_CATA);
               /*InjCtl_EveIniPurgCat_FarCtlDsCtl*/
               INJFARCTLDSCTL_vidInitPurgeCata();
               /*InjCtl_EvePurgCat_FarCtlDsCtl*/
               INJFARCTLDSCTL_vidPurgeCata();
            }
            else
            {
               VEMS_vidSET(Current_dnstr_correction_state,
                          DOWNSTREAM_SENSOR_CTRL);
               /* InjCtl_EveChgPiFbCor_FarCtlDsCtl */
               INJFARCTLDSCTL_vidCalcErrTension();
               INJFARCTLDSCTL_vidCalcErrTenGain();
               INJFARCTLDSCTL_vidFeedbackCorr();
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_DownStrmSenTrans                            */
/* !Description :  Transition DOWNSTREAM_SENSOR_CTRL                          */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLDSCTL_vidResetOffset();                         */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void INJFARCTLDSCTL_vidInitEntryDly();                        */
/*  extf argret void INJFARCTLDSCTL_vidInitPurgeCata();                       */
/*  extf argret void INJFARCTLDSCTL_vidPurgeCata();                           */
/*  extf argret void INJFARCTLDSCTL_vidCalcErrTension();                      */
/*  extf argret void INJFARCTLDSCTL_vidCalcErrTenGain();                      */
/*  extf argret void INJFARCTLDSCTL_vidFeedbackCorr();                        */
/*  input boolean Lshd_down_stream_lbda_sensor_hot;                           */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint16 Dnstr_down_stream_ref_voltage;                               */
/*  input uint16 Dnstr_fenetre_activation_bas;                                */
/*  input uint16 Dnstr_fenetre_activation_haut;                               */
/*  input boolean Manu_inh_lambda_feedback;                                   */
/*  input boolean Dnstr_conds_met;                                            */
/*  input boolean Dnstr_purge_cata_done_wo_result;                            */
/*  input boolean Dnstr_purge_cata_low;                                       */
/*  input boolean Dnstr_purge_cata_rich;                                      */
/*  output boolean Dnstr_purge_cata_low;                                      */
/*  output boolean Dnstr_purge_cata_rich;                                     */
/*  output st49 Current_dnstr_correction_state;                               */
/*  output boolean INJFARCTLDSCTL_bEnableCalcModif;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_DownStrmSenTrans(void)
{
   boolean  bLocalINHINJFARCTLDSCTLDBLLOOP;
   boolean  bLocalLshdDownStrmLbdaSensorHot;
   boolean  bLocalDnstr_conds_met;
   boolean  bLocalDnstr_purge_cata_low;
   boolean  bLocalDnstr_purge_cata_rich;
   uint16   u16LocalTensionSondeAval;
   sint32   s32LocalDiff1;
   uint32   u32LocalAdd1;


   bLocalINHINJFARCTLDSCTLDBLLOOP =
      GDGAR_bGetFRM(FRM_FRM_INHINJFARCTLDSCTLDBLLOOP);

   VEMS_vidGET(Lshd_down_stream_lbda_sensor_hot,
               bLocalLshdDownStrmLbdaSensorHot);
   VEMS_vidGET(Tension_sonde_aval, u16LocalTensionSondeAval);
   s32LocalDiff1 = (sint32)(Dnstr_down_stream_ref_voltage
                          - Dnstr_fenetre_activation_bas);
   u32LocalAdd1 = (uint32)(Dnstr_down_stream_ref_voltage
                         + Dnstr_fenetre_activation_haut);
   if (  (bLocalINHINJFARCTLDSCTLDBLLOOP != 0)
      || (Manu_inh_lambda_feedback != 0)
      || (bLocalLshdDownStrmLbdaSensorHot == 0))
   {
      /*InjCtl_EveRstOfsRich_FarCtlDsCtl*/
      INJFARCTLDSCTL_vidResetOffset();
      VEMS_vidSET(Dnstr_purge_cata_low, 0);
      VEMS_vidSET(Dnstr_purge_cata_rich, 0);
      VEMS_vidSET(Current_dnstr_correction_state, WAITING_DNSTR_GENERAL_CONDS);
   }
   else
   {
      VEMS_vidGET(Dnstr_conds_met, bLocalDnstr_conds_met);
      if (bLocalDnstr_conds_met == 0)
      {
         /*InjCtl_EveRstOfsRich_FarCtlDsCtl*/
         INJFARCTLDSCTL_vidResetOffset();
         VEMS_vidSET(Dnstr_purge_cata_low, 0);
         VEMS_vidSET(Dnstr_purge_cata_rich, 0);
         VEMS_vidSET(Current_dnstr_correction_state,
                    WAITING_FOR_DNSTR_CTRL_CONDS);
         /*InjCtl_EveEntryDly_FarCtlDsCtl*/
         INJFARCTLDSCTL_vidInitEntryDly();
         INJFARCTLDSCTL_bEnableCalcModif = 1;
      }
      else
      {
         if (Dnstr_purge_cata_done_wo_result == 0)
         {
            if ( u16LocalTensionSondeAval < s32LocalDiff1)
            {
               /*InjCtl_EveRstOfsRich_FarCtlDsCtl*/
               INJFARCTLDSCTL_vidResetOffset();
               VEMS_vidSET(Dnstr_purge_cata_low, 1);
            }
            else
            {
               VEMS_vidSET(Dnstr_purge_cata_low, 0);
            }

            if ( u16LocalTensionSondeAval > u32LocalAdd1)
            {
               /*InjCtl_EveRstOfsRich_FarCtlDsCtl*/
               INJFARCTLDSCTL_vidResetOffset();
               VEMS_vidSET(Dnstr_purge_cata_rich, 1);
            }
            else
            {
               VEMS_vidSET(Dnstr_purge_cata_rich, 0);
            }
            VEMS_vidGET(Dnstr_purge_cata_low, bLocalDnstr_purge_cata_low);
            VEMS_vidGET(Dnstr_purge_cata_rich, bLocalDnstr_purge_cata_rich);
            if (  (bLocalDnstr_purge_cata_low != 0)
               || (bLocalDnstr_purge_cata_rich != 0))
            {
               VEMS_vidSET(Current_dnstr_correction_state, DNSTR_PURGE_CATA);
               /*InjCtl_EveIniPurgCat_FarCtlDsCtl*/
               INJFARCTLDSCTL_vidInitPurgeCata();
               /*InjCtl_EvePurgCat_FarCtlDsCtl*/
               INJFARCTLDSCTL_vidPurgeCata();
            }
            else
            {
               /* InjCtl_EveChgPiFbCor_FarCtlDsCtl */
               INJFARCTLDSCTL_vidCalcErrTension();
               INJFARCTLDSCTL_vidCalcErrTenGain();
               INJFARCTLDSCTL_vidFeedbackCorr();
            }
         }
         else
         {
            /* InjCtl_EveChgPiFbCor_FarCtlDsCtl */
            INJFARCTLDSCTL_vidCalcErrTension();
            INJFARCTLDSCTL_vidCalcErrTenGain();
            INJFARCTLDSCTL_vidFeedbackCorr();
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_PurgeCataTrans                              */
/* !Description :  Transition  DNSTR_PURGE_CATA                               */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLDSCTL_vidResetOffset();                         */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void INJFARCTLDSCTL_vidResetPurgeCata();                      */
/*  extf argret void INJFARCTLDSCTL_vidInitEntryDly();                        */
/*  extf argret void INJFARCTLDSCTL_vidCalcErrTension();                      */
/*  extf argret void INJFARCTLDSCTL_vidCalcErrTenGain();                      */
/*  extf argret void INJFARCTLDSCTL_vidFeedbackCorr();                        */
/*  extf argret void INJFARCTLDSCTL_vidPurgeCata();                           */
/*  input boolean Lshd_down_stream_lbda_sensor_hot;                           */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input boolean Manu_inh_lambda_feedback;                                   */
/*  input boolean Dnstr_conds_met;                                            */
/*  input uint16 Dnstr_down_stream_ref_voltage;                               */
/*  input uint16 Dnstr_fenetre_activation_haut;                               */
/*  input uint16 Dnstr_seuil_tension_av_haut_hyst;                            */
/*  input uint16 Dnstr_fenetre_activation_bas;                                */
/*  input uint16 Dnstr_seuil_tension_av_bas_hyst;                             */
/*  input boolean Dnstr_purge_cata_rich;                                      */
/*  input boolean Dnstr_purge_cata_low;                                       */
/*  input uint16 Dnstr_time_in_high_volt_count;                               */
/*  input uint16 Dnstr_time_in_low_volt_count;                                */
/*  output boolean Dnstr_purge_cata_low;                                      */
/*  output boolean Dnstr_purge_cata_rich;                                     */
/*  output st49 Current_dnstr_correction_state;                               */
/*  output boolean INJFARCTLDSCTL_bEnableCalcModif;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_PurgeCataTrans(void)
{
   boolean bLocalINHINJFARCTLDSCTLDBLLOOP;
   boolean bLocalLshdDownStrmLbdaSensorHot;
   boolean bLocalDnstr_conds_met;
   boolean bLocalDnstr_purge_cata_low;
   boolean bLocalDnstr_purge_cata_rich;
   uint16  u16LocalTensionSondeAval;
   uint32  u32Local;
   uint32  u32Local2;
   sint32  s32Local;

   bLocalINHINJFARCTLDSCTLDBLLOOP =
                              GDGAR_bGetFRM(FRM_FRM_INHINJFARCTLDSCTLDBLLOOP);

   VEMS_vidGET(Lshd_down_stream_lbda_sensor_hot,
               bLocalLshdDownStrmLbdaSensorHot);
   VEMS_vidGET(Tension_sonde_aval, u16LocalTensionSondeAval);
   if (  (bLocalINHINJFARCTLDSCTLDBLLOOP != 0)
      || (Manu_inh_lambda_feedback != 0)
      || (bLocalLshdDownStrmLbdaSensorHot == 0))
   {
      /*InjCtl_EveRstOfsRich_FarCtlDsCtl*/
      INJFARCTLDSCTL_vidResetOffset();
      VEMS_vidSET(Dnstr_purge_cata_low, 0);
      VEMS_vidSET(Dnstr_purge_cata_rich, 0);
      /*InjCtl_EveRstPurgCat_FarCtlDsCtl*/
      INJFARCTLDSCTL_vidResetPurgeCata();
      VEMS_vidSET(Current_dnstr_correction_state, WAITING_DNSTR_GENERAL_CONDS);
   }
   else
   {
      VEMS_vidGET(Dnstr_conds_met, bLocalDnstr_conds_met);
      if (bLocalDnstr_conds_met == 0)
      {
         /*InjCtl_EveRstOfsRich_FarCtlDsCtl*/
         INJFARCTLDSCTL_vidResetOffset();
         VEMS_vidSET(Dnstr_purge_cata_low, 0);
         VEMS_vidSET(Dnstr_purge_cata_rich, 0);
         /*InjCtl_EveRstPurgCat_FarCtlDsCtl*/
         INJFARCTLDSCTL_vidResetPurgeCata();
         VEMS_vidSET(Current_dnstr_correction_state,
                    WAITING_FOR_DNSTR_CTRL_CONDS);
         /*InjCtl_EveEntryDly_FarCtlDsCtl*/
         INJFARCTLDSCTL_vidInitEntryDly();
         INJFARCTLDSCTL_bEnableCalcModif = 1;
      }
      else
      {
         s32Local = (sint32)( ( Dnstr_down_stream_ref_voltage
                              + Dnstr_fenetre_activation_haut)
                            - Dnstr_seuil_tension_av_haut_hyst);
         u32Local = (uint32)MATHSRV_udtMAX(s32Local, 0);

         s32Local = (sint32)( ( Dnstr_down_stream_ref_voltage
                              - Dnstr_fenetre_activation_bas)
                            + Dnstr_seuil_tension_av_bas_hyst);
         u32Local2 = (uint32)MATHSRV_udtMAX(s32Local, 0);
         VEMS_vidGET(Dnstr_purge_cata_rich, bLocalDnstr_purge_cata_rich);
         VEMS_vidGET(Dnstr_purge_cata_low, bLocalDnstr_purge_cata_low);
         if ( (  (bLocalDnstr_purge_cata_rich != 0)
              && (  (u16LocalTensionSondeAval < u32Local)
                 || (Dnstr_time_in_high_volt_count == 0)
                 )
              )
            || (  (bLocalDnstr_purge_cata_low != 0)
               && (  (u16LocalTensionSondeAval > u32Local2)
                  || (Dnstr_time_in_low_volt_count == 0)
                  )
               )
            )
         {
            /*InjCtl_EveRstOfsRich_FarCtlDsCtl*/
            INJFARCTLDSCTL_vidResetOffset();
            VEMS_vidSET(Dnstr_purge_cata_low, 0);
            VEMS_vidSET(Dnstr_purge_cata_rich, 0);
            /*InjCtl_EveRstPurgCat_FarCtlDsCtl*/
            INJFARCTLDSCTL_vidResetPurgeCata();
            VEMS_vidSET(Current_dnstr_correction_state, DOWNSTREAM_SENSOR_CTRL);
            /* InjCtl_EveChgPiFbCor_FarCtlDsCtl */
            INJFARCTLDSCTL_vidCalcErrTension();
            INJFARCTLDSCTL_vidCalcErrTenGain();
            INJFARCTLDSCTL_vidFeedbackCorr();
         }
         else
         {
            /*InjCtl_EvePurgCat_FarCtlDsCtl*/
            INJFARCTLDSCTL_vidPurgeCata();
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidInitParam                                */
/* !Description :  initialiser les différents paramètres de la double boucle  */
/*                 de régulation                                              */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean EEPROM_Feedback_correction_C;                               */
/*  input sint16 Feedback_correction_Tmp;                                     */
/*  input sint16 Init_Calib_Feedback_correction_C;                            */
/*  output boolean Dnstr_conds_met;                                           */
/*  output sint16 Feedback_correction_int;                                    */
/*  output uint16 Dnstr_retard_purge_riche;                                   */
/*  output uint16 Dnstr_retard_purge_pauvre;                                  */
/*  output sint16 Feedback_correction;                                        */
/*  output sint16 Feedback_correction_Tmp;                                    */
/*  output sint16 Init_Calib_Feedback_correction_C;                           */
/*  output uint16 Dnstr_time_in_low_volt_count;                               */
/*  output uint16 Dnstr_time_in_high_volt_count;                              */
/*  output uint16 Dnstr_entry_delay;                                          */
/*  output uint16 Dnstr_settling_delay;                                       */
/*  output uint16 Dnstr_retard_s_purge_riche;                                 */
/*  output uint16 Dnstr_retard_s_purge_pauvre;                                */
/*  output boolean INJFARCTLDSCTL_bEnableCalcModif;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidInitParam(void)
{
   VEMS_vidSET(Dnstr_conds_met, 0);
   Feedback_correction_int = 0;
   VEMS_vidSET(Dnstr_retard_purge_riche, 0);
   VEMS_vidSET(Dnstr_retard_purge_pauvre, 0);
   if (EEPROM_Feedback_correction_C != 0)
   {
      VEMS_vidSET(Feedback_correction, Feedback_correction_Tmp);
   }
   else
   {
      VEMS_vidSET(Feedback_correction, Init_Calib_Feedback_correction_C);
      Feedback_correction_Tmp = Init_Calib_Feedback_correction_C;
   }
   Dnstr_time_in_low_volt_count = 0;
   Dnstr_time_in_high_volt_count = 0;
   Dnstr_entry_delay = 0;
   Dnstr_settling_delay = 0;
   Dnstr_retard_s_purge_riche = 0;
   Dnstr_retard_s_purge_pauvre = 0;
   INJFARCTLDSCTL_bEnableCalcModif = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidResetOffset                              */
/* !Description :  Lorsque la purge du catalyser est réalisée, et lorsque     */
/*                 qu’on sort de la boucle de régulation, les paramètres du   */
/*                 délai d’attente sont réinitialisés.                        */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLDSCTL_vidSaveFeedbackCr();                      */
/*  extf argret void INJFARCTLDSCTL_vidResetOffsetVal();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidResetOffset(void)
{
   INJFARCTLDSCTL_vidSaveFeedbackCr();
   INJFARCTLDSCTL_vidResetOffsetVal();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidSaveFeedbackCr                           */
/* !Description :  Enregistrement de Feedback_correction dans une Variable    */
/*                 temporaire                                                 */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Feedback_correction;                                         */
/*  output sint16 Feedback_correction_Tmp;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidSaveFeedbackCr(void)
{
   sint16 s16LocalFeedbackcorrection ;


   VEMS_vidGET(Feedback_correction, s16LocalFeedbackcorrection);
   Feedback_correction_Tmp = s16LocalFeedbackcorrection;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidResetOffsetVal                           */
/* !Description :  Initialisation des paramètres du délai d’attente           */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Dnstr_add_pmh_modifier;                                      */
/*  output uint8 Dnstr_substract_pmh_modifier;                                */
/*  output sint16 Feedback_correction_int;                                    */
/*  output sint16 Feedback_correction;                                        */
/*  output uint16 Dnstr_retard_purge_riche;                                   */
/*  output uint16 Dnstr_retard_purge_pauvre;                                  */
/*  output uint16 Dnstr_retard_s_purge_riche;                                 */
/*  output uint16 Dnstr_retard_s_purge_pauvre;                                */
/*  output uint16 Dnstr_add_s_modifier;                                       */
/*  output uint16 Dnstr_substract_s_modifier;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidResetOffsetVal(void)
{
   VEMS_vidSET(Dnstr_add_pmh_modifier, 0);
   VEMS_vidSET(Dnstr_substract_pmh_modifier, 0);
   Feedback_correction_int = 0;
   VEMS_vidSET(Feedback_correction, 0);
   VEMS_vidSET(Dnstr_retard_purge_riche, 0);
   VEMS_vidSET(Dnstr_retard_purge_pauvre, 0);
   Dnstr_retard_s_purge_riche = 0;
   Dnstr_retard_s_purge_pauvre = 0;
   VEMS_vidSET(Dnstr_add_s_modifier, 0);
   VEMS_vidSET(Dnstr_substract_s_modifier, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidInitEntryDly                             */
/* !Description :  réinitialiser le délai d’attente après l’obtention de      */
/*                 toutes les conditions dynamiques d’adaptation.             */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Dnstr_entry_delay_c;                                         */
/*  output uint16 Dnstr_entry_delay;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidInitEntryDly(void)
{
   Dnstr_entry_delay = (uint16)MATHSRV_udtMIN(Dnstr_entry_delay_c, 400);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidInitSetlingDly                           */
/* !Description :  réinitialiser le délai d’attente après application de      */
/*                 l’offset de biais de richesse du à la régulation de        */
/*                 richesse.                                                  */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Dnstr_settling_delay_c;                                      */
/*  output uint16 Dnstr_settling_delay;                                       */
/*  output boolean Dnstr_purge_cata_done_wo_result;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidInitSetlingDly(void)
{
   Dnstr_settling_delay = (uint16)MATHSRV_udtMIN(Dnstr_settling_delay_c, 1000);
   Dnstr_purge_cata_done_wo_result = 0;
}
/*------------------------------- end of file --------------------------------*/