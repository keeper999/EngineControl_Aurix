/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRBENCHAUT                                             */
/* !Description     : THRBENCHAUT Component                                   */
/*                                                                            */
/* !Module          : THRBENCHAUT                                             */
/* !Description     : MODE BANC AUTOMATIQUE PAPILLON MOTORISE                 */
/*                                                                            */
/* !File            : THRBENCHAUT_FCT2.C                                      */
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
/*   1 / THRBENCHAUT_vidComputeReference                                      */
/*   2 / THRBENCHAUT_vidDynMode_2                                             */
/*   3 / THRBENCHAUT_vidDynMode_3                                             */
/*   4 / THRBENCHAUT_vidSelectFrequency                                       */
/*   5 / THRBENCHAUT_vidComputeSignal                                         */
/*   6 / THRBENCHAUT_vidGenerateSignal                                        */
/*   7 / THRBENCHAUT_vidCompSinAngleEval                                      */
/*   8 / THRBENCHAUT_vidIncSinTime                                            */
/*   9 / THRBENCHAUT_vidCalcAngleEval                                         */
/*                                                                            */
/* !Reference   : V02 NT 08 04529 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#055915                                         */
/* !OtherRefs   : VEMS V02 ECU#056022                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRBENCHAUT/THRBENCHAUT_FCT2$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   01 Jul 2013 $*/
/* $Author::   etsasson                               $$Date::   01 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THRBENCHAUT.h"
#include "THRBENCHAUT_L.h"
#include "THRBENCHAUT_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidComputeReference                            */
/* !Description :  Ce sous-système calcule  la consigne toutes  les 8 ms, à   */
/*                 partir de  la valeur de consigne absolue de l’index en     */
/*                 cours.                                                     */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Tpac_compute_ref_enab;                                      */
/*  input uint16 Ssm_closed_throttle_pos;                                     */
/*  input uint16 Ssm_open_throttle_pos;                                       */
/*  input boolean Tpac_dyn_test_bed_type_ref;                                 */
/*  input sint32 Tpac_dyn_test_bed_increment;                                 */
/*  input uint16 THRBENCHAUT_u16DtcThrPosTestBed1;                            */
/*  output uint16 THRBENCHAUT_u16DtcThrPosTestBed1;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidComputeReference(void)
{
   uint16 u16LocalSsm_clos_thr_pos;
   uint16 u16LocalSsm_open_thr_pos;
   sint32 s32LocalThPos;
   sint32 s32LocalDiff;


   /* Compute_reference */
   if (Tpac_compute_ref_enab != 0)
   {
      VEMS_vidGET(Ssm_closed_throttle_pos, u16LocalSsm_clos_thr_pos);
      VEMS_vidGET(Ssm_open_throttle_pos, u16LocalSsm_open_thr_pos);

      if (Tpac_dyn_test_bed_type_ref != 0)
      {
         s32LocalThPos = (sint32)THRBENCHAUT_u16DtcThrPosTestBed1
                       + (Tpac_dyn_test_bed_increment / 2097152);
      }
      else
      {
         s32LocalThPos = (sint32)THRBENCHAUT_u16DtcThrPosTestBed1;
      }
      s32LocalDiff = (sint32)( u16LocalSsm_open_thr_pos
                             - u16LocalSsm_clos_thr_pos);
      s32LocalThPos = MATHSRV_udtMIN(s32LocalThPos, s32LocalDiff);

      THRBENCHAUT_u16DtcThrPosTestBed1 =
         (uint16)MATHSRV_udtCLAMP(s32LocalThPos, 0, 1024);
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidDynMode_2                                   */
/* !Description :  Ce sous-système réalise la recopie brute sur la consigne du*/
/*                 signal de tension présent sur l’entrée pédale 1.           */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ssm_closed_throttle_pos;                                     */
/*  input uint16 Ssm_open_throttle_pos;                                       */
/*  input uint16 Aps_1_raw_position;                                          */
/*  output uint16 THRBENCHAUT_u16DtcThrPosTestBed2;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidDynMode_2(void)
{
   /* Dyn_mode_2 */
   uint16 u16LocalAps_raw_pos;
   uint16 u16LocalSsm_clos_thr_pos;
   uint16 u16LocalSsm_open_thr_pos;
   uint16 u16LocalThrPos;
   sint32 s32LocalCompThrPos;


   VEMS_vidGET(Ssm_closed_throttle_pos, u16LocalSsm_clos_thr_pos);
   VEMS_vidGET(Ssm_open_throttle_pos, u16LocalSsm_open_thr_pos);
   VEMS_vidGET(Aps_1_raw_position, u16LocalAps_raw_pos);

   s32LocalCompThrPos = (sint32)( u16LocalSsm_open_thr_pos
                                - u16LocalSsm_clos_thr_pos);
   u16LocalThrPos = (uint16)MATHSRV_udtMAX(s32LocalCompThrPos, 0);
   u16LocalThrPos = (uint16)MATHSRV_udtMIN(u16LocalAps_raw_pos, u16LocalThrPos);
   THRBENCHAUT_u16DtcThrPosTestBed2 = (uint16)MATHSRV_udtMIN(u16LocalThrPos,
                                                             1024);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidDynMode_3                                   */
/* !Description :  Génération de consignes en sinus paramétrables             */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRBENCHAUT_vidSelectFrequency();                        */
/*  extf argret void THRBENCHAUT_vidComputeSignal();                          */
/*  extf argret void THRBENCHAUT_vidIncrGenTimeCount();                       */
/*  extf argret void THRBENCHAUT_vidIncrSignalCount();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidDynMode_3(void)
{
   /* Dyn_mode_3 */
   THRBENCHAUT_vidSelectFrequency();
   THRBENCHAUT_vidComputeSignal();
   THRBENCHAUT_vidIncrGenTimeCount();
   THRBENCHAUT_vidIncrSignalCount();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidSelectFrequency                             */
/* !Description :  Ce bloc sélectionne la fréquence utilisée pour générer le  */
/*                 signal sinusoïdal.                                         */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Tpac_sin_signal_count;                                        */
/*  input uint8 Tpac_sin_freq_map[8];                                         */
/*  output uint8 Tpac_sin_freq;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidSelectFrequency(void)
{
   uint8 u8LocalTpacSinSigIndex;


   /* select_frequency */
   u8LocalTpacSinSigIndex = (uint8)MATHSRV_udtMIN(Tpac_sin_signal_count, 7);
   Tpac_sin_freq = Tpac_sin_freq_map[u8LocalTpacSinSigIndex];
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidComputeSignal                               */
/* !Description :  Ce bloc calcule le signal sinusoïdal brut à la fréquence   */
/*                 désirée, le multiplie par l'amplitude associée et ajoute   */
/*                 l'amplitude et un offset calibrable au signal final.       */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRBENCHAUT_vidGenerateSignal();                         */
/*  input uint8 Tpac_sin_signal_count;                                        */
/*  input uint16 Tpac_sin_amplitude_map[8];                                   */
/*  input uint16 Tpac_sin_amplitude;                                          */
/*  input uint16 Tpac_sin_signal_offset;                                      */
/*  input sint16 Tpac_sin_signal_raw;                                         */
/*  output uint16 Tpac_sin_amplitude;                                         */
/*  output uint16 THRBENCHAUT_u16DtcThrPosTestBed3;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidComputeSignal(void)
{
   uint8  u8LocalTpacSinAmpIndex;
   sint32 s32LocalDtcThPosTestBed;


   /* compute_signal */
   u8LocalTpacSinAmpIndex = (uint8)MATHSRV_udtMIN(Tpac_sin_signal_count, 7);

   Tpac_sin_amplitude =
      (uint16)MATHSRV_udtMIN(Tpac_sin_amplitude_map[u8LocalTpacSinAmpIndex],
                             512);

   THRBENCHAUT_vidGenerateSignal();

   s32LocalDtcThPosTestBed = (sint32)( Tpac_sin_amplitude
                                     + Tpac_sin_signal_offset
                                     + (  ( Tpac_sin_amplitude
                                          * Tpac_sin_signal_raw * 2) / 65535));
   THRBENCHAUT_u16DtcThrPosTestBed3 =
      (uint16)MATHSRV_udtMIN(s32LocalDtcThPosTestBed, 1024);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidGenerateSignal                              */
/* !Description :  A partir du temps Tpac_sin_time, on va calculer sin        */
/*                 (Tpac_sin_time) d'après une cartographie à 7 points        */
/*                 d'appuis.                                                  */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRBENCHAUT_vidCompSinAngleEval();                       */
/*  extf MATHSRV_u16CalcParaIncAryU16(????);                                  */
/*  extf MATHSRV_u16Interp1d(????);                                           */
/*  input uint16 Tpac_sin_bkpt_map[7];                                        */
/*  input uint16 Tpac_sin_func_entry;                                         */
/*  input boolean Tpac_sin_inverse_output;                                    */
/*  input uint16 Tpac_sin_map[7];                                             */
/*  output sint16 Tpac_sin_signal_raw;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidGenerateSignal(void)
{
   uint16 u16LocalCalcPara;
   sint32 s32LocalValInterp;


   /* generate_signal */
   THRBENCHAUT_vidCompSinAngleEval();
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(Tpac_sin_bkpt_map,
                                                   Tpac_sin_func_entry,
                                                   7);
   if (Tpac_sin_inverse_output != 0)
   {
      s32LocalValInterp = (-1)*MATHSRV_u16Interp1d(Tpac_sin_map,
                                                   u16LocalCalcPara);
   }
   else
   {
      s32LocalValInterp = (sint32)MATHSRV_u16Interp1d(Tpac_sin_map,
                                                      u16LocalCalcPara);
   }
   Tpac_sin_signal_raw = (sint16)MATHSRV_udtCLAMP(s32LocalValInterp,
                                                  -32768,
                                                  32767);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidCompSinAngleEval                            */
/* !Description :  A partir du temps Tpac_sin_time, on va calculer sin        */
/*                 (Tpac_sin_time) d'après une cartographie à 7 points        */
/*                 d'appuis.                                                  */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRBENCHAUT_vidIncSinTime();                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRBENCHAUT_vidCalcAngleEval();                          */
/*  input boolean Tpac_open_loop_control;                                     */
/*  input boolean THRBENCHAUT_bTpacOpenLpCtrlPrev;                            */
/*  output uint16 Tpac_sin_time;                                              */
/*  output uint16 Tpac_sin_func_entry;                                        */
/*  output boolean THRBENCHAUT_bTpacOpenLpCtrlPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidCompSinAngleEval(void)
{
   /* compute_sinus_angle_eval */
   boolean bLocalTpac_loop_ctrl;


   THRBENCHAUT_vidIncSinTime();
   VEMS_vidGET(Tpac_open_loop_control, bLocalTpac_loop_ctrl);
   if (  (THRBENCHAUT_bTpacOpenLpCtrlPrev != 0)
      && (bLocalTpac_loop_ctrl == 0))
   {
      Tpac_sin_time = 0;
      Tpac_sin_func_entry = 512;
   }
   THRBENCHAUT_vidCalcAngleEval();
   THRBENCHAUT_bTpacOpenLpCtrlPrev = bLocalTpac_loop_ctrl;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidIncSinTime                                  */
/* !Description :  Ce bloc incrémente la valeur Tpac_sin_time après que       */
/*                 celle-ci ait été utilisée pour la génération de            */
/*                 Tpac_sin_func_entry.                                       */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Tpac_sin_time;                                               */
/*  output uint16 Tpac_sin_time;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidIncSinTime(void)
{
   uint32 u32LocalTpac_sin_time;


   u32LocalTpac_sin_time = Tpac_sin_time + 1;
   Tpac_sin_time = (uint16)MATHSRV_udtMIN(u32LocalTpac_sin_time, 52427);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidCalcAngleEval                               */
/* !Description :  Calcul de l'angle eval                                     */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRBENCHAUT_vidSinTimeFourthQuad();                      */
/*  extf argret void THRBENCHAUT_vidSinTimeFirstQuad();                       */
/*  extf argret void THRBENCHAUT_vidSinTimeSecondQuad();                      */
/*  extf argret void THRBENCHAUT_vidSinTimeThirdQuad();                       */
/*  extf argret void THRBENCHAUT_vidResetSinTime();                           */
/*  input uint8 Tpac_sin_freq;                                                */
/*  input uint16 Tpac_sin_time;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidCalcAngleEval(void)
{
   uint32 u32LocalQuatFreq;
   uint32 u32LocalHalfFreq;
   uint32 u32LocalTQuatFreq;
   uint32 u32LocalFreq;

   u32LocalQuatFreq =
      (((4096) / (uint32)(Thr_SampleTiMid_SC)) / (Tpac_sin_freq + 1));
   u32LocalHalfFreq =
      (((8192) / (uint32)(Thr_SampleTiMid_SC)) / (Tpac_sin_freq + 1));
   u32LocalTQuatFreq =
      (((12288) / (uint32)(Thr_SampleTiMid_SC)) / (Tpac_sin_freq + 1));
   u32LocalFreq =
      (((16384) / (uint32)(Thr_SampleTiMid_SC)) / (Tpac_sin_freq + 1));

   if (Tpac_sin_time <= u32LocalQuatFreq)
   {
      THRBENCHAUT_vidSinTimeFourthQuad();
   }
   else
   {
      if(Tpac_sin_time <= u32LocalHalfFreq)
      {
         THRBENCHAUT_vidSinTimeFirstQuad();
      }
      else
      {
         if(Tpac_sin_time <= u32LocalTQuatFreq)
         {
            THRBENCHAUT_vidSinTimeSecondQuad();
         }
         else
         {
            if(Tpac_sin_time < u32LocalFreq)
            {
               THRBENCHAUT_vidSinTimeThirdQuad();
            }
            else
            {
               THRBENCHAUT_vidResetSinTime();
            }
         }
      }
   }
}
/*------------------------------- end of file --------------------------------*/