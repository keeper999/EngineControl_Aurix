/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFSUCDET                                              */
/* !Description     : MISFSUCDET Component                                    */
/*                                                                            */
/* !Module          : MISFSUCDET                                              */
/* !Description     : ALGORITHMES DE DÉTECTION DE 2 MISFIRES SUCCESSIFS       */
/*                                                                            */
/* !File            : MISFSUCDET_FCT2.C                                       */
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
/*   1 / MISFSUCDET_vidFirstMisfDetection                                     */
/*   2 / MISFSUCDET_vidSndMisfDetection                                       */
/*   3 / MISFSUCDET_vidFstMisfDecision                                        */
/*   4 / MISFSUCDET_vidSndMisfDecision                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5198660 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFSUCDET/MISFSUCDET_FCT2.C_$*/
/* $Revision::   1.1      $$Author::   fsanchez2      $$Date::   15 Jan 2010 $*/
/* $Author::   fsanchez2                              $$Date::   15 Jan 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "MISFSUCDET.h"
#include "MISFSUCDET_L.h"
#include "MISFSUCDET_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidFirstMisfDetection                           */
/* !Description :  Ce bloc calcule : La sortie des algorithmes. Les indices de*/
/*                 confiance correspondant                                    */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFSUCDET_vidFirstFilterMain();                         */
/*  extf argret void MISFSUCDET_vidFirstAlgoTrust();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidFirstMisfDetection(void)
{
   MISFSUCDET_vidFirstFilterMain();
   MISFSUCDET_vidFirstAlgoTrust();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidSndMisfDetection                             */
/* !Description :  Ce bloc calcule : La sortie des algorithmes. Les indices de*/
/*                 confiance correspondant du 2ième misfire                   */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFSUCDET_vidSndFilterMain();                           */
/*  extf argret void MISFSUCDET_vidSndAlgoTrust();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidSndMisfDetection(void)
{
   MISFSUCDET_vidSndFilterMain();
   MISFSUCDET_vidSndAlgoTrust();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidFstMisfDecision                              */
/* !Description :  Ce bloc décide si le 1er misfire a effectivement eu lieu   */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint16 Indicated_torque_3_bkpt_map[7];                              */
/*  input uint8 Regime_moteur_3_bkpt_map[16];                                 */
/*  input uint8 Mf_p_filt_decision_map_uacn2[7][16];                          */
/*  input sint16 Mf_p_filt1_algo_trust_uavn0;                                 */
/*  input sint16 Mf_comb1_algo_trust_uavn0;                                   */
/*  input uint8 Mf_misfire_detected_thresh_uacn0;                             */
/*  output boolean Mf_misfire1_detected_uavb0;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidFstMisfDecision(void)
{
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalInterp2d;
   uint16  u16LocalIndicatedTorque;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   sint16  s16LocalEngLim_tqIdcEngCur;
   sint32  s32LocalMf_msf_det;
   sint32  s32LocalIndicatedTorque;
   sint32  s32LocalTemp;


   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);

   s32LocalIndicatedTorque = (sint32)(s16LocalEngLim_tqIdcEngCur + 32000);
   u16LocalIndicatedTorque = (uint16)MATHSRV_udtMAX(s32LocalIndicatedTorque, 0);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Indicated_torque_3_bkpt_map,
                                                u16LocalIndicatedTorque,
                                                7);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_3_bkpt_map,
                                               u8LocalRegime_moteur_32,
                                               16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&Mf_p_filt_decision_map_uacn2[0][0],
                                        u16LocalParaX,
                                        u16LocalParaY,
                                        16);

   s32LocalMf_msf_det =
      (sint32)( (Mf_p_filt1_algo_trust_uavn0 * u8LocalInterp2d)
              + (Mf_comb1_algo_trust_uavn0 * (256 - u8LocalInterp2d)));

   s32LocalTemp = (sint32)(Mf_misfire_detected_thresh_uacn0 * 16384);
   if (s32LocalMf_msf_det > s32LocalTemp)
   {
      Mf_misfire1_detected_uavb0 = 1;
   }
   else
   {
      Mf_misfire1_detected_uavb0 = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidSndMisfDecision                              */
/* !Description :  Ce bloc décide si le 2ème misfire a effectivement eu lieu  */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint16 Indicated_torque_3_bkpt_map[7];                              */
/*  input uint8 Regime_moteur_3_bkpt_map[16];                                 */
/*  input uint8 Mf_p_filt_decision_map_uacn2[7][16];                          */
/*  input sint16 Mf_p_filt2_algo_trust_uavn0;                                 */
/*  input sint16 Mf_comb2_algo_trust_uavn0;                                   */
/*  input uint8 Mf_misfire_detected_thresh_uacn0;                             */
/*  output boolean Mf_misfire2_detected_uavb0;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidSndMisfDecision(void)
{
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalInterp2d;
   uint16  u16LocalIndicatedTorque;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   sint16  s16LocalEngLim_tqIdcEngCur;
   sint32  s32LocalMf_msf_det;
   sint32  s32LocalIndicatedTorque;
   sint32  s32LocalTemp;


   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);

   s32LocalIndicatedTorque = (sint32)(s16LocalEngLim_tqIdcEngCur + 32000);
   u16LocalIndicatedTorque = (uint16)MATHSRV_udtMAX(s32LocalIndicatedTorque, 0);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Indicated_torque_3_bkpt_map,
                                                u16LocalIndicatedTorque,
                                                7);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_3_bkpt_map,
                                               u8LocalRegime_moteur_32,
                                               16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&Mf_p_filt_decision_map_uacn2[0][0],
                                        u16LocalParaX,
                                        u16LocalParaY,
                                        16);

   s32LocalMf_msf_det =
     (sint32)( (Mf_p_filt2_algo_trust_uavn0 * u8LocalInterp2d)
             + (Mf_comb2_algo_trust_uavn0 * (256 - u8LocalInterp2d)));

   s32LocalTemp = (sint32)(Mf_misfire_detected_thresh_uacn0 * 16384);
   if (s32LocalMf_msf_det > s32LocalTemp)
   {
      Mf_misfire2_detected_uavb0 = 1;
   }
   else
   {
      Mf_misfire2_detected_uavb0 = 0;
   }
}
/*------------------------------- end of file --------------------------------*/