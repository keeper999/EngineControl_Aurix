/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFDETIDLE                                             */
/* !Description     : MISFDETIDLE component                                   */
/*                                                                            */
/* !Module          : MISFDETIDLE                                             */
/* !Description     : ALGORITHMES DE DETECTION DE MISFIRE EN IDLE             */
/*                                                                            */
/* !File            : MISFDETIDLE_FCT1.C                                      */
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
/*   1 / MISFDETIDLE_vidInitOutput                                            */
/*   2 / MISFDETIDLE_vidInit                                                  */
/*   3 / MISFDETIDLE_vidMisfDetIdleDet                                        */
/*   4 / MISFDETIDLE_vidDetection                                             */
/*   5 / MISFDETIDLE_vidDetIdleAlgo                                           */
/*   6 / MISFDETIDLE_vidDetAlgoOutIdle                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5198626 / 06                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/MISFDETIDLE/MISFDETIDLE_FCT1.C_v  $*/
/* $Revision::   1.3      $$Author::   achebino       $$Date::   13 Dec 2013 $*/
/* $Author::   achebino                               $$Date::   13 Dec 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MISFDETIDLE.h"
#include "MISFDETIDLE_L.h"
#include "MISFDETIDLE_IM.h"
#include "MATHSRV.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDETIDLE_vidInitOutput                                  */
/* !Description :  Initialisation des variables internes                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint32 MISFDETIDLE_u32tiDlyWinAdpPrev1;                            */
/*  output uint32 MISFDETIDLE_u32tiDlyWinAdpPrev2;                            */
/*  output uint16 MISFDETIDLE_u16ResultPrev3;                                 */
/*  output uint16 MISFDETIDLE_u16ResultPrev4;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDETIDLE_vidInitOutput(void)
{
   MISFDETIDLE_u32tiDlyWinAdpPrev1 = 0;
   MISFDETIDLE_u32tiDlyWinAdpPrev2 = 0;
   MISFDETIDLE_u16ResultPrev3 = 0;
   MISFDETIDLE_u16ResultPrev4 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDETIDLE_vidInit                                        */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Mf_Idle_det_single_output_uavb0;                             */
/*  output uint16 Mf_idle_algo_thresh_uavn0;                                  */
/*  output sint16 Mf_idle_crite_next_uavn0;                                   */
/*  output sint16 Mf_idle_crite_uavn0;                                        */
/*  output sint16 Mf_idle_crite_prev_uavn0;                                   */
/*  output sint16 Mf_idle_crite_prev_prev_uavn0;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDETIDLE_vidInit(void)
{
   VEMS_vidSET(Mf_Idle_det_single_output_uavb0, 0);
   VEMS_vidSET(Mf_idle_algo_thresh_uavn0, 0);
   VEMS_vidSET(Mf_idle_crite_next_uavn0, 0);
   VEMS_vidSET(Mf_idle_crite_uavn0, 0);
   VEMS_vidSET(Mf_idle_crite_prev_uavn0, 0);
   VEMS_vidSET(Mf_idle_crite_prev_prev_uavn0, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDETIDLE_vidMisfDetIdleDet                              */
/* !Description :  Cette Fonction permet d'activer l’algorithme IDLE quand le */
/*                 moteur est au ralenti et au point neutre.                  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFDETIDLE_vidDetection();                              */
/*  input boolean Mf_bAcvCondIdle;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDETIDLE_vidMisfDetIdleDet(void)
{
   boolean bLocalMf_bAcvCondIdle;


   VEMS_vidGET(Mf_bAcvCondIdle, bLocalMf_bAcvCondIdle);

   if (bLocalMf_bAcvCondIdle != 0)
   {
      MISFDETIDLE_vidDetection();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDETIDLE_vidDetection                                   */
/* !Description :  Cette Fonction permet de Calculer  la sortie de            */
/*                 l’algorithme IDLE et de faire une comparaison entre seuils */
/*                 et sorties de l’algorithme.                                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDETIDLE_vidDetIdleAlgo();                            */
/*  extf argret void MISFDETIDLE_vidDetAlgoOutIdle();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDETIDLE_vidDetection(void)
{
   MISFDETIDLE_vidDetIdleAlgo();
   MISFDETIDLE_vidDetAlgoOutIdle();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDETIDLE_vidDetIdleAlgo                                 */
/* !Description :  Cette Fonction permet de calculer  la sortie brute de      */
/*                 l’algorithme « IDLE ».                                     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Misf_tiDlyExpWinAdp;                                         */
/*  input uint32 Misf_tiDlyBdcWinAdp;                                         */
/*  input sint16 Mf_idle_crite_next_uavn0;                                    */
/*  input sint16 Mf_idle_crite_uavn0;                                         */
/*  input sint16 Mf_idle_crite_prev_uavn0;                                    */
/*  input uint32 MISFDETIDLE_u32tiDlyWinAdpPrev2;                             */
/*  input uint32 MISFDETIDLE_u32tiDlyWinAdpPrev1;                             */
/*  input uint8 MisfDet_noDelaySync_C;                                        */
/*  input uint16 MISFDETIDLE_u16ResultPrev3;                                  */
/*  input uint16 MISFDETIDLE_u16ResultPrev4;                                  */
/*  output sint16 Mf_idle_algo_out_uavn0;                                     */
/*  output sint16 Mf_idle_crite_next_uavn0;                                   */
/*  output sint16 Mf_idle_crite_uavn0;                                        */
/*  output sint16 Mf_idle_crite_prev_uavn0;                                   */
/*  output sint16 Mf_idle_crite_prev_prev_uavn0;                              */
/*  output uint16 MISFDETIDLE_u16ResultPrev4;                                 */
/*  output uint16 MISFDETIDLE_u16ResultPrev3;                                 */
/*  output uint32 MISFDETIDLE_u32tiDlyWinAdpPrev2;                            */
/*  output uint32 MISFDETIDLE_u32tiDlyWinAdpPrev1;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDETIDLE_vidDetIdleAlgo(void)
{
   uint8  u8LocalReste;
   uint16 u16LocalMisfDetIdleDiv2Max;
   uint16 u16LocalMisfDetIdleSwitch;
   sint16 s16LocalMf_idle_crite_next_uavn0;
   sint16 s16LocalMf_idle_crite_uavn0;
   sint16 s16LocalMf_idle_crite_prev_uavn0;
   sint16 s16LocalSwitchout;
   uint32 u32LocalMisfDetIdleDiv1;
   uint32 u32LocalMisf_tiDlyExpWinAdp;
   uint32 u32LocalMisf_tiDlyBdcWinAdp;
   uint32 u32LocalMisfDetIdleDiv3;
   uint32 u32LocalNumerateur1;
   uint32 u32LocalNumerateur2;
   uint32 u32LocalMisfDetIdleDiv2Max2;
   uint32 u32LocalMisfDetIdleDiv2Max;
   uint32 u32LocalMoy;
   uint32 u32Localdiff;


   VEMS_vidGET(Misf_tiDlyExpWinAdp, u32LocalMisf_tiDlyExpWinAdp);
   VEMS_vidGET(Misf_tiDlyBdcWinAdp, u32LocalMisf_tiDlyBdcWinAdp);
   VEMS_vidGET(Mf_idle_crite_next_uavn0, s16LocalMf_idle_crite_next_uavn0);
   VEMS_vidGET(Mf_idle_crite_uavn0, s16LocalMf_idle_crite_uavn0);
   VEMS_vidGET(Mf_idle_crite_prev_uavn0, s16LocalMf_idle_crite_prev_uavn0);

   if (  (u32LocalMisf_tiDlyExpWinAdp > 199998)
      || (u32LocalMisf_tiDlyBdcWinAdp > 199998))
   {
      u32LocalMisfDetIdleDiv3 = 99999;
      u8LocalReste = 0;
   }
   else
   {
      u32LocalMisfDetIdleDiv3 = ( ( u32LocalMisf_tiDlyExpWinAdp
                                  + u32LocalMisf_tiDlyBdcWinAdp) / 2);
      u8LocalReste = (uint8) ( ( u32LocalMisf_tiDlyExpWinAdp
                             + u32LocalMisf_tiDlyBdcWinAdp) % 2);
      u32LocalMisfDetIdleDiv3 = MATHSRV_udtMIN(u32LocalMisfDetIdleDiv3, 99999);
   }

   u32Localdiff = (4294967295uL - MISFDETIDLE_u32tiDlyWinAdpPrev2);
   if (MISFDETIDLE_u32tiDlyWinAdpPrev1 < u32Localdiff)
   {
      u32LocalMisfDetIdleDiv1 = ( MISFDETIDLE_u32tiDlyWinAdpPrev1
                                + MISFDETIDLE_u32tiDlyWinAdpPrev2);
      u32Localdiff = (4294967295uL - u32LocalMisfDetIdleDiv1);
      if (u32LocalMisfDetIdleDiv3 < u32Localdiff)
      {
         u32LocalMisfDetIdleDiv1 = ( u32LocalMisfDetIdleDiv3
                                   + u32LocalMisfDetIdleDiv1);
      }
      else
      {
         u32LocalMisfDetIdleDiv1 = 4294967295uL;
      }
   }
   else
   {
      u32LocalMisfDetIdleDiv1 = 4294967295uL;
   }

   if (u32LocalMisfDetIdleDiv1 == 0)
   {
      u16LocalMisfDetIdleDiv2Max = 0;
   }
   else
   {
      u32LocalNumerateur1 = ( (u32LocalMisfDetIdleDiv3 * 24576)
                            + (uint32)(u8LocalReste * 12288));
      u32LocalNumerateur2 = (MISFDETIDLE_u32tiDlyWinAdpPrev1 * 24576);

      if (u32LocalNumerateur1 > u32LocalNumerateur2)
      {
         if (u8LocalReste != 0)
         {
            u32LocalMisfDetIdleDiv2Max = ( ( u32LocalNumerateur1
                                            - u32LocalNumerateur2)
                                         / u32LocalMisfDetIdleDiv1);
            if (u32LocalMisfDetIdleDiv1 < 4294967295uL)
            {
               u32LocalMisfDetIdleDiv2Max2 = ( ( u32LocalNumerateur1
                                               - u32LocalNumerateur2)
                                             / (u32LocalMisfDetIdleDiv1 + 1));
            }
            else
            {
               u32LocalMisfDetIdleDiv2Max2 = ( ( u32LocalNumerateur1
                                               - u32LocalNumerateur2)
                                             / 4294967295uL);
            }
            u32LocalMoy =
               ( (u32LocalMisfDetIdleDiv2Max - u32LocalMisfDetIdleDiv2Max2)
               / 2);
            u16LocalMisfDetIdleDiv2Max =
                  (uint16)(u32LocalMisfDetIdleDiv2Max2 + u32LocalMoy);
         }
         else
         {
            u16LocalMisfDetIdleDiv2Max =
               (uint16)( (u32LocalNumerateur1 - u32LocalNumerateur2)
                       / u32LocalMisfDetIdleDiv1);
         }
      }
      else
      {
         u16LocalMisfDetIdleDiv2Max = 0;
      }
   }

   switch (MisfDet_noDelaySync_C)
   {
   case 0:
      u16LocalMisfDetIdleSwitch = u16LocalMisfDetIdleDiv2Max;
      break;
   case 1:
      u16LocalMisfDetIdleSwitch = MISFDETIDLE_u16ResultPrev3;
      break;
   case 2:
      u16LocalMisfDetIdleSwitch = MISFDETIDLE_u16ResultPrev4;
      break;
   default:
      u16LocalMisfDetIdleSwitch = u16LocalMisfDetIdleDiv2Max;
      break;
   }

   s16LocalSwitchout =
      (sint16)MATHSRV_udtMIN(u16LocalMisfDetIdleSwitch, 32767);
   Mf_idle_algo_out_uavn0 = s16LocalMf_idle_crite_next_uavn0;
   VEMS_vidSET(Mf_idle_crite_next_uavn0, s16LocalSwitchout);
   VEMS_vidSET(Mf_idle_crite_uavn0, s16LocalMf_idle_crite_next_uavn0);
   VEMS_vidSET(Mf_idle_crite_prev_uavn0, s16LocalMf_idle_crite_uavn0);
   VEMS_vidSET(Mf_idle_crite_prev_prev_uavn0, s16LocalMf_idle_crite_prev_uavn0);

   MISFDETIDLE_u16ResultPrev4 = MISFDETIDLE_u16ResultPrev3;
   MISFDETIDLE_u16ResultPrev3 = u16LocalMisfDetIdleDiv2Max;
   MISFDETIDLE_u32tiDlyWinAdpPrev2 =
      MATHSRV_udtMIN(MISFDETIDLE_u32tiDlyWinAdpPrev1, 99999);
   MISFDETIDLE_u32tiDlyWinAdpPrev1 = u32LocalMisfDetIdleDiv3;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDETIDLE_vidDetAlgoOutIdle                              */
/* !Description :  Cette Fonction permet de calculer le seuil de l’algorithme */
/*                 IDLE (dépend du régime et du couple indiqué ).             */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean Mf_adap_shrt_no_rlzd_uavb0;                                 */
/*  input uint16 MisfDet_tqEngCurIdle_X[7];                                   */
/*  input uint16 MisfDet_nEngCurIdle_Y[7];                                    */
/*  input uint16 Mf_idle_algo_thresh_map_uacn2[7][7];                         */
/*  input boolean Mf_adap_no_rlzd_UT_uavb0;                                   */
/*  input uint16 Mf_idle_gain_thresh_map_uacn1[7];                            */
/*  input uint16 Mf_idle_gain_thresh_map_UT_uacn1[7];                         */
/*  input sint16 Mf_idle_algo_out_uavn0;                                      */
/*  output uint16 Mf_idle_algo_thresh_uavn0;                                  */
/*  output uint8 Mf_Idle_det_single_output_uavb0;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDETIDLE_vidDetAlgoOutIdle(void)
{
   boolean bLocalMf_adap_shrt_no_rlzd_uavb0;
   boolean bLocalFRM_bLimMisfDetShoWinThd;
   boolean bLocalMf_adap_no_rlzd_UT_uavb0;
   uint8   u8LocalMf_Idle_det_output;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalInterp2d;
   uint16  u16LocalIndicatedTorque;
   uint16  u16LocalMfidlealgothreshuavn0;
   uint16  u16LocalInterp1d;
   sint16  s16LocalEngLim_tqIdcEngCur;
   uint32  u32LocalCalc;
   uint32  u32LocalMf_Idle_det_output;
   uint32  u32LocalDiv;
   sint32  s32LocalIndicatedTorque;


   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Mf_adap_shrt_no_rlzd_uavb0, bLocalMf_adap_shrt_no_rlzd_uavb0);
   bLocalFRM_bLimMisfDetShoWinThd = GDGAR_bGetFRM(FRM_FRM_LIMMISFDETSHOWINTHD);

   s32LocalIndicatedTorque = (s16LocalEngLim_tqIdcEngCur + 32000);
   u16LocalIndicatedTorque = (uint16)MATHSRV_udtMAX(s32LocalIndicatedTorque, 0);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(MisfDet_tqEngCurIdle_X,
                                                u16LocalIndicatedTorque,
                                                7);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(MisfDet_nEngCurIdle_Y,
                                                u16LocalExt_nEng,
                                                7);
   u16LocalInterp2d = MATHSRV_u16Interp2d(&Mf_idle_algo_thresh_map_uacn2[0][0],
                                          u16LocalParaX,
                                          u16LocalParaY,
                                          7);

   if (  (bLocalMf_adap_shrt_no_rlzd_uavb0 != 0)
      || (bLocalFRM_bLimMisfDetShoWinThd != 0))
   {
      VEMS_vidGET(Mf_adap_no_rlzd_UT_uavb0, bLocalMf_adap_no_rlzd_UT_uavb0);
      if (bLocalMf_adap_no_rlzd_UT_uavb0 != 0)
      {
         u16LocalInterp1d = MATHSRV_u16Interp1d(Mf_idle_gain_thresh_map_uacn1,
                                                u16LocalParaY);
      }
      else
      {
         u16LocalInterp1d =
            MATHSRV_u16Interp1d(Mf_idle_gain_thresh_map_UT_uacn1,
                                u16LocalParaY);
      }
      u32LocalCalc = (uint32)( ((u16LocalInterp2d * u16LocalInterp1d) + 128)
                             / 256);
   }
   else
   {
      u32LocalCalc = (uint32)((u16LocalInterp2d + 1) / 2);
   }
   u16LocalMfidlealgothreshuavn0 = (uint16)MATHSRV_udtMIN(u32LocalCalc, 65535);
   VEMS_vidSET(Mf_idle_algo_thresh_uavn0, u16LocalMfidlealgothreshuavn0);

   if (u32LocalCalc == 0)
   {
      u32LocalMf_Idle_det_output = 0;
   }
   else
   {
      if (Mf_idle_algo_out_uavn0 > 0)
      {
         u32LocalDiv = u32LocalCalc / 2;
         u32LocalMf_Idle_det_output = ( ( (uint32)(Mf_idle_algo_out_uavn0 * 128)
                                        + u32LocalDiv)
                                      / u32LocalCalc);
      }
      else
      {
         u32LocalMf_Idle_det_output = 0;
      }
   }

   u8LocalMf_Idle_det_output = (uint8)MATHSRV_udtMIN(u32LocalMf_Idle_det_output,
                                                     255);
   VEMS_vidSET(Mf_Idle_det_single_output_uavb0, u8LocalMf_Idle_det_output);
}
/*------------------------------- end of file --------------------------------*/