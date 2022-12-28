/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFDETCFM                                              */
/* !Description     : MISFDETCFM component.                                   */
/*                                                                            */
/* !Module          : MISFDETCFM                                              */
/* !Description     : ALGORITHME DE DECISION POUR LA DETECTION MISFIRE        */
/*                                                                            */
/* !File            : MISFDETCFM_FCT1.C                                       */
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
/*   1 / MISFDETCFM_vidInitOutput                                             */
/*   2 / MISFDETCFM_vidDecision                                               */
/*   3 / MISFDETCFM_vidDecisionAlgorithm                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5198655 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFDETCFM/MISFDETCFM_FCT1.C_$*/
/* $Revision::   1.1      $$Author::   wbouach        $$Date::   06 Dec 2010 $*/
/* $Author::   wbouach                                $$Date::   06 Dec 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include"STD_TYPES.h"
#include"MATHSRV.h"
#include"MISFDETCFM.h"
#include"MISFDETCFM_L.h"
#include"MISFDETCFM_IM.h"
#include"VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDETCFM_vidInitOutput                                   */
/* !Description :  Cette fonction initialise les sorties du module.           */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output sint16 Mf_comb_wght_uavn0;                                         */
/*  output uint8 Mf_det_single_output_uavn0;                                  */
/*  output boolean Mf_misfire_detected_uavb0;                                 */
/*  output sint16 Mf_p_filt_wght_uavn0;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDETCFM_vidInitOutput(void)
{
   VEMS_vidSET(Mf_comb_wght_uavn0, 0);
   VEMS_vidSET(Mf_det_single_output_uavn0, 0);
   VEMS_vidSET(Mf_misfire_detected_uavb0, 0);
   VEMS_vidSET(Mf_p_filt_wght_uavn0, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDETCFM_vidDecision                                     */
/* !Description :  Ce bloc permet de calculer à récurrence PMH une sortie     */
/*                 représentative de l’état (misfire ou non) de la combustion */
/*                 scrutée. Il n’est activé que si les algorithmes ont bien   */
/*                 été calculés (condition de détection active) et si la      */
/*                 stratégie est autorisée.                                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFDETCFM_vidDecisionAlgorithm();                       */
/*  input boolean Mf_algo_cond_ok_uavb0;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDETCFM_vidDecision(void)
{
   boolean bLocalMf_algo_cond_ok_uavb0;


   VEMS_vidGET(Mf_algo_cond_ok_uavb0, bLocalMf_algo_cond_ok_uavb0);
   if (bLocalMf_algo_cond_ok_uavb0 != 0)
   {
      MISFDETCFM_vidDecisionAlgorithm();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDETCFM_vidDecisionAlgorithm                            */
/* !Description :  Ce bloc permet d’obtenir une sortie unique représentative  */
/*                 de la présence ou non d’un misfire sous forme d’un booléen */
/*                 Mf_stat_decision_uavb0. Ce bloc décrit les règles de       */
/*                 décision quant à la présence ou non d’un misfire.          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Gear_engaged;                                                 */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input boolean Mf_algo_idle_cond_ok;                                       */
/*  input uint16 Mf_cmi_neut_bkpt_uacn1[7];                                   */
/*  input uint8 Mf_eng_spd_neut_bkpt_uacn1[16];                               */
/*  input uint8 Mf_p_filt_dec_neut_map_uacn2[7][16];                          */
/*  input uint16 Indicated_torque_3_bkpt_map[7];                              */
/*  input uint8 Regime_moteur_3_bkpt_map[16];                                 */
/*  input uint8 Mf_p_filt_decision_map_uacn2[7][16];                          */
/*  input sint16 Mf_p_filt_algo_trust_uavn0;                                  */
/*  input sint16 Mf_comb_algo_trust_uavn0;                                    */
/*  input uint8 Mf_Idle_det_single_output_uavb0;                              */
/*  input uint8 Mf_misfire_detected_thresh_uacn0;                             */
/*  output sint16 Mf_p_filt_wght_uavn0;                                       */
/*  output sint16 Mf_comb_wght_uavn0;                                         */
/*  output uint8 Mf_det_single_output_uavn0;                                  */
/*  output boolean Mf_misfire_detected_uavb0;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDETCFM_vidDecisionAlgorithm(void)
{
   boolean bLocalMfAlgoIdleCondOk;
   uint8   u8LocalGear_engaged;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalMfIdleDetSngleOutUavb0;
   uint8   u8LocalInterp;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalEngLim_tqIdcEngCur;
   uint16  u16LocalMfDetSingleOutputUavn0;
   sint16  s16LocalMf_pFilt_algoTrust_uavn0;
   sint16  s16LocalMf_comb_algoTrust_uavn0;
   sint16  s16LocalMf_p_filt_wght_uavn0;
   sint16  s16LocalMf_comb_wght_uavn0;
   sint16  s16LocalEngLim_tqIdcEngCur;
   sint32  s32LocalTrustIndexSum;
   sint32  s32LocalMf_algo_wght_uavn0;


   VEMS_vidGET(Gear_engaged, u8LocalGear_engaged);
   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Mf_algo_idle_cond_ok, bLocalMfAlgoIdleCondOk);

   s16LocalEngLim_tqIdcEngCur =
      (sint16)MATHSRV_udtMAX(s16LocalEngLim_tqIdcEngCur, -32000);
   u16LocalEngLim_tqIdcEngCur = (uint16)(s16LocalEngLim_tqIdcEngCur + 32000);

   if (u8LocalGear_engaged == 0)
   {
      u16LocalParaX =
         MATHSRV_u16CalcParaIncAryU16(Mf_cmi_neut_bkpt_uacn1,
                                      u16LocalEngLim_tqIdcEngCur,
                                      7);
      u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Mf_eng_spd_neut_bkpt_uacn1,
                                                  u8LocalRegime_moteur_32,
                                                  16);
      u8LocalInterp = MATHSRV_u8Interp2d(&Mf_p_filt_dec_neut_map_uacn2[0][0],
                                         u16LocalParaX,
                                         u16LocalParaY,
                                         16);
   }
   else
   {
      u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Indicated_torque_3_bkpt_map,
                                                   u16LocalEngLim_tqIdcEngCur,
                                                   7);
      u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_3_bkpt_map,
                                                  u8LocalRegime_moteur_32,
                                                  16);
      u8LocalInterp = MATHSRV_u8Interp2d(&Mf_p_filt_decision_map_uacn2[0][0],
                                         u16LocalParaX,
                                         u16LocalParaY,
                                         16);
   }

   VEMS_vidGET(Mf_p_filt_algo_trust_uavn0, s16LocalMf_pFilt_algoTrust_uavn0);
   s32LocalMf_algo_wght_uavn0 = (sint32)( s16LocalMf_pFilt_algoTrust_uavn0
                                        * u8LocalInterp);
   s16LocalMf_p_filt_wght_uavn0 = (sint16)(s32LocalMf_algo_wght_uavn0 / 256);
   VEMS_vidSET(Mf_p_filt_wght_uavn0, s16LocalMf_p_filt_wght_uavn0);

   VEMS_vidGET(Mf_comb_algo_trust_uavn0, s16LocalMf_comb_algoTrust_uavn0);
   s32LocalMf_algo_wght_uavn0 = (sint32)( s16LocalMf_comb_algoTrust_uavn0
                                        * (256 - u8LocalInterp));
   s16LocalMf_comb_wght_uavn0 = (sint16)(s32LocalMf_algo_wght_uavn0 / 256);
   VEMS_vidSET(Mf_comb_wght_uavn0, s16LocalMf_comb_wght_uavn0);

   if (bLocalMfAlgoIdleCondOk != 0)
   {
      VEMS_vidGET(Mf_Idle_det_single_output_uavb0,
                  u8LocalMfIdleDetSngleOutUavb0);
      s32LocalTrustIndexSum = (sint32)(u8LocalMfIdleDetSngleOutUavb0 * 64);
   }
   else
   {
      s32LocalTrustIndexSum = (sint32)( s16LocalMf_p_filt_wght_uavn0
                                      + s16LocalMf_comb_wght_uavn0);
   }

   if (s32LocalTrustIndexSum > 0)
   {
      u16LocalMfDetSingleOutputUavn0 = (uint16)(s32LocalTrustIndexSum / 64);
      u8LocalMfIdleDetSngleOutUavb0 =
         (uint8)MATHSRV_udtMIN(u16LocalMfDetSingleOutputUavn0, 255);
      VEMS_vidSET(Mf_det_single_output_uavn0, u8LocalMfIdleDetSngleOutUavb0);
   }
   else
   {
      VEMS_vidSET(Mf_det_single_output_uavn0, 0);
   }
   u16LocalMfDetSingleOutputUavn0 =
      (uint16)(Mf_misfire_detected_thresh_uacn0 * 64);
   if (s32LocalTrustIndexSum > (sint32)u16LocalMfDetSingleOutputUavn0)
   {
      VEMS_vidSET(Mf_misfire_detected_uavb0, 1);
   }
   else
   {
      VEMS_vidSET(Mf_misfire_detected_uavb0, 0);
   }
}
/*------------------------------ end of file ---------------------------------*/