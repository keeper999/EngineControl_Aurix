/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFDET                                                 */
/* !Description     : MISFDET component                                       */
/*                                                                            */
/* !Module          : MISFDET                                                 */
/* !Description     : Algorithmes de détection de misfire                     */
/*                                                                            */
/* !File            : MISFDET_FCT1.C                                          */
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
/*   1 / MISFDET_vidInitOutput                                                */
/*   2 / MISFDET_vidMisfDet                                                   */
/*   3 / MISFDET_vidMisfStabCond                                              */
/*   4 / MISFDET_vidAlgoDetCalc                                               */
/*   5 / MISFDET_vidPfiltAlgo                                                 */
/*   6 / MISFDET_vidCombAlgo                                                  */
/*   7 / MISFDET_vidAlgoOutput                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5158467 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#068493                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFDET/MISFDET_FCT1.C_v     $*/
/* $Revision::   1.11     $$Author::   wbouach        $$Date::   27 Mar 2014 $*/
/* $Author::   wbouach                                $$Date::   27 Mar 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "MISFDET.h"
#include "MISFDET_L.h"
#include "MISFDET_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDET_vidInitOutput                                      */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Mf_algo_cond_ok_uavb0;                                     */
/*  output uint16 Mf_comb_algo_thresh_uavn0;                                  */
/*  output sint16 Mf_comb_algo_trust_uavn0;                                   */
/*  output sint16 Mf_comb_crite_next_uavn0;                                   */
/*  output sint16 Mf_comb_crite_prev_prev_uavn0;                              */
/*  output sint16 Mf_comb_crite_prev_uavn0;                                   */
/*  output sint16 Mf_comb_crite_uavn0;                                        */
/*  output uint16 Mf_p_filt_algo_thresh_uavn0;                                */
/*  output sint16 Mf_p_filt_algo_trust_uavn0;                                 */
/*  output sint16 Mf_p_filt_crite_next_uavn0;                                 */
/*  output sint16 Mf_p_filt_crite_prev_prev_uavn0;                            */
/*  output sint16 Mf_p_filt_crite_prev_uavn0;                                 */
/*  output sint16 Mf_p_filt_crite_uavn0;                                      */
/*  output boolean Flex_bEnaDiagMisfAlcEst;                                   */
/*  output boolean Mf_algo_Norm_cond_ok;                                      */
/*  output boolean Mf_algo_idle_cond_ok;                                      */
/*  output boolean Mf_bAcvCondIdle;                                           */
/*  output boolean Mf_bAcvCondIdleRaw;                                        */
/*  output boolean Mf_bAcvCondNorm;                                           */
/*  output boolean Mf_bAcvCondNormRaw;                                        */
/*  output uint16 Mf_duree_demi_tour_n_less_3;                                */
/*  output uint16 Mf_duree_demi_tour_n_less_2;                                */
/*  output uint16 Mf_duree_demi_tour_n_less_1;                                */
/*  output uint16 Mf_duree_demi_tour_n;                                       */
/*  output uint32 Misf_tiDlyLongWinAdpPrev;                                   */
/*  output boolean MISFDET_bOutMinHyst;                                       */
/*  output boolean MISFDET_bOutMinIdleHyst;                                   */
/*  output boolean MISFDET_bTimeOut1;                                         */
/*  output boolean MISFDET_bTimeOut;                                          */
/*  output boolean MISFDET_bAcvCondNormPrev;                                  */
/*  output boolean MISFDET_bAcvCondIdlePrev;                                  */
/*  output uint8 MISFDET_u8CounternoTDCIdleAcv;                               */
/*  output uint8 MISFDET_u8CounternoTDCAcv;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDET_vidInitOutput(void)
{
   VEMS_vidSET(Mf_algo_cond_ok_uavb0, 0);
   VEMS_vidSET(Mf_comb_algo_thresh_uavn0, 0);
   VEMS_vidSET(Mf_comb_algo_trust_uavn0, 0);
   VEMS_vidSET(Mf_comb_crite_next_uavn0, 0);
   VEMS_vidSET(Mf_comb_crite_prev_prev_uavn0, 0);
   VEMS_vidSET(Mf_comb_crite_prev_uavn0, 0);
   VEMS_vidSET(Mf_comb_crite_uavn0, 0);
   VEMS_vidSET(Mf_p_filt_algo_thresh_uavn0, 0);
   VEMS_vidSET(Mf_p_filt_algo_trust_uavn0, 0);
   VEMS_vidSET(Mf_p_filt_crite_next_uavn0, 0);
   VEMS_vidSET(Mf_p_filt_crite_prev_prev_uavn0, 0);
   VEMS_vidSET(Mf_p_filt_crite_prev_uavn0, 0);
   VEMS_vidSET(Mf_p_filt_crite_uavn0, 0);
   VEMS_vidSET(Flex_bEnaDiagMisfAlcEst, 0);
   VEMS_vidSET(Mf_algo_Norm_cond_ok, 0);
   VEMS_vidSET(Mf_algo_idle_cond_ok, 0);
   VEMS_vidSET(Mf_bAcvCondIdle, 0);
   VEMS_vidSET(Mf_bAcvCondIdleRaw, 0);
   VEMS_vidSET(Mf_bAcvCondNorm, 0);
   VEMS_vidSET(Mf_bAcvCondNormRaw, 0);
   Mf_duree_demi_tour_n_less_3 = 0;
   Mf_duree_demi_tour_n_less_2 = 0;
   Mf_duree_demi_tour_n_less_1 = 0;
   Mf_duree_demi_tour_n = 0;
   Misf_tiDlyLongWinAdpPrev = 0;
   MISFDET_bOutMinHyst = 0;
   MISFDET_bOutMinIdleHyst = 0;
   MISFDET_bTimeOut1 = 0;
   MISFDET_bTimeOut = 0;
   MISFDET_bAcvCondNormPrev = 0;
   MISFDET_bAcvCondIdlePrev = 0;
   MISFDET_u8CounternoTDCIdleAcv = 0;
   MISFDET_u8CounternoTDCAcv = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDET_vidMisfDet                                         */
/* !Description :  Les sorties des algorithmes seront calculés dans le cas où */
/*                 les conditions de détection de misfire sont ok ou dans le  */
/*                 cas où les conditions d’apprentissage de l’algorithme      */
/*                 combustion sont ok                                         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_09_00808_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDET_vidMisfStabCond();                               */
/*  extf argret void MISFDET_vidAlgoDetCalc();                                */
/*  input boolean Mf_pfilt_comb_ena_uacb0;                                    */
/*  input boolean Mf_algo_cond_ok_temp;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDET_vidMisfDet(void)
{
   if (Mf_pfilt_comb_ena_uacb0 != 0)
   {
      MISFDET_vidMisfStabCond();
      if (Mf_algo_cond_ok_temp != 0)
      {
         MISFDET_vidAlgoDetCalc();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDET_vidMisfStabCond                                    */
/* !Description :  Ce bloc vérifie si les conditions de fonctionnement(Tp eau,*/
/*                 Tp air, régime, CMI, vitesse véhicule...) et de stabilité  */
/*                 sont vérifiées pour que la stratégie de détection puisse   */
/*                 être activée                                               */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_09_00808_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDET_vidCondGlobalStab();                             */
/*  extf argret void MISFDET_vidCondStabNormal();                             */
/*  extf argret void MISFDET_vidCondStabIdle();                               */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void MISFDET_vidAlgoConTempo();                               */
/*  input boolean Mf_bAcvCondNormRaw;                                         */
/*  input boolean Mf_bAcvCondIdleRaw;                                         */
/*  input boolean Misf_bAcvAlgoIdle_C;                                        */
/*  output boolean Mf_bAcvCondNormRaw;                                        */
/*  output boolean Mf_bAcvCondIdleRaw;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDET_vidMisfStabCond(void)
{
   boolean bLocalMf_bAcvCondNormRaw;
   boolean bLocalMf_bAcvCondIdleRaw;


   MISFDET_vidCondGlobalStab();
   MISFDET_vidCondStabNormal();
   MISFDET_vidCondStabIdle();
   VEMS_vidGET(Mf_bAcvCondNormRaw, bLocalMf_bAcvCondNormRaw);
   VEMS_vidGET(Mf_bAcvCondIdleRaw, bLocalMf_bAcvCondIdleRaw);
   if (Misf_bAcvAlgoIdle_C == 0)
   {
      if (  (bLocalMf_bAcvCondNormRaw != 0)
         || (bLocalMf_bAcvCondIdleRaw != 0))
      {
         VEMS_vidSET(Mf_bAcvCondNormRaw, 1);
      }
      else
      {
         VEMS_vidSET(Mf_bAcvCondNormRaw, 0);
      }
      VEMS_vidSET(Mf_bAcvCondIdleRaw, 0);
   }
   MISFDET_vidAlgoConTempo();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDET_vidAlgoDetCalc                                     */
/* !Description :  Ce bloc est actif dès lors que les conditions de stabilité */
/*                 et d’autres portant sur divers paramètres sont vérifiées,  */
/*                 le booléen Mf_algo_cond_ok_uavb0 étant alors à 1           */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDET_vidPfiltAlgo();                                  */
/*  extf argret void MISFDET_vidCombAlgo();                                   */
/*  extf argret void MISFDET_vidAlgoOutput();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDET_vidAlgoDetCalc(void)
{
   MISFDET_vidPfiltAlgo();
   MISFDET_vidCombAlgo();
   MISFDET_vidAlgoOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDET_vidPfiltAlgo                                       */
/* !Description :  Ce bloc calcul la sortie brute de l’algorithme « P_filtre »*/
/* !Number      :  FCT1.5                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void MISFDET_vidCalcHalfRev();                                */
/*  input sint16 Mf_p_filt_crite_prev_uavn0;                                  */
/*  input sint16 Mf_p_filt_crite_uavn0;                                       */
/*  input sint16 Mf_p_filt_crite_next_uavn0;                                  */
/*  input uint32 Misf_tiDlyLongWinAdp;                                        */
/*  input uint32 Misf_tiDlyLongWinAdpPrev;                                    */
/*  input uint16 Misf_HalfRevSum;                                             */
/*  output sint16 Mf_p_filt_crite_prev_prev_uavn0;                            */
/*  output sint16 Mf_p_filt_crite_prev_uavn0;                                 */
/*  output sint16 Mf_p_filt_crite_uavn0;                                      */
/*  output sint16 Mf_p_filt_algo_out_uavn0;                                   */
/*  output sint16 Mf_p_filt_crite_next_uavn0;                                 */
/*  output uint32 Misf_tiDlyLongWinAdpPrev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDET_vidPfiltAlgo(void)
{
   uint16 u16LocalPfiltCritNext;
   sint16 s16LocalMf_p_filt_crite_next_uav;
   sint16 s16LocalMf_p_filt_crite_uavn0;
   sint16 s16LocalMf_p_filt_crite_prev_uav;
   uint32 u32LocalMisf_tiDlyLongWinAdp;
   uint32 u32LocalTemp;
   uint32 u32LocalDiff;
   sint32 s32LocalPfiltAlgoOut;


   VEMS_vidGET(Mf_p_filt_crite_prev_uavn0, s16LocalMf_p_filt_crite_prev_uav);
   VEMS_vidGET(Mf_p_filt_crite_uavn0, s16LocalMf_p_filt_crite_uavn0);
   VEMS_vidGET(Mf_p_filt_crite_next_uavn0, s16LocalMf_p_filt_crite_next_uav);

   VEMS_vidSET(Mf_p_filt_crite_prev_prev_uavn0,
               s16LocalMf_p_filt_crite_prev_uav);
   VEMS_vidSET(Mf_p_filt_crite_prev_uavn0, s16LocalMf_p_filt_crite_uavn0);
   /*re-guetter la variable Mf_p_filt_crite_prev_uavn0 après la production*/
   VEMS_vidGET(Mf_p_filt_crite_prev_uavn0, s16LocalMf_p_filt_crite_prev_uav);
   VEMS_vidSET(Mf_p_filt_crite_uavn0, s16LocalMf_p_filt_crite_next_uav);
   /*re-guetter la variable Mf_p_filt_crite_uavn0 après la production*/
   VEMS_vidGET(Mf_p_filt_crite_uavn0, s16LocalMf_p_filt_crite_uavn0);

   MISFDET_vidCalcHalfRev();
   VEMS_vidGET(Misf_tiDlyLongWinAdp, u32LocalMisf_tiDlyLongWinAdp);

   if (u32LocalMisf_tiDlyLongWinAdp > Misf_tiDlyLongWinAdpPrev)
   {
      u32LocalDiff = (u32LocalMisf_tiDlyLongWinAdp - Misf_tiDlyLongWinAdpPrev);
      u32LocalTemp = MATHSRV_udtMIN(u32LocalDiff, 262143);
      if (Misf_HalfRevSum != 0)
      {
         u32LocalTemp = u32LocalTemp * 16384;
         u32LocalTemp = u32LocalTemp / 15625;
         u32LocalTemp = (u32LocalTemp * 8192) / (5 * Misf_HalfRevSum);
         s16LocalMf_p_filt_crite_next_uav = (sint16)MATHSRV_udtMIN(u32LocalTemp,
                                                                   32767);
      }
      else
      {
         s16LocalMf_p_filt_crite_next_uav = 32767;
      }
   }
   else
   {
      u32LocalDiff = (Misf_tiDlyLongWinAdpPrev - u32LocalMisf_tiDlyLongWinAdp);
      u32LocalTemp = MATHSRV_udtMIN(u32LocalDiff, 262143);
      if (Misf_HalfRevSum != 0)
      {
         u32LocalTemp = u32LocalTemp * 16384;
         u32LocalTemp = u32LocalTemp / 15625;
         u32LocalTemp = (u32LocalTemp * 8192) / (5 * Misf_HalfRevSum);
         u16LocalPfiltCritNext = (uint16)MATHSRV_udtMIN(u32LocalTemp, 32768);
         s16LocalMf_p_filt_crite_next_uav = (sint16)((-1) *
                                                     u16LocalPfiltCritNext);
      }
      else
      {
         s16LocalMf_p_filt_crite_next_uav = -32768;
      }
   }

   s32LocalPfiltAlgoOut = (sint32)( (s16LocalMf_p_filt_crite_uavn0 * 2)
                                  - ( s16LocalMf_p_filt_crite_next_uav
                                    + s16LocalMf_p_filt_crite_prev_uav));

   Mf_p_filt_algo_out_uavn0 = (sint16)(s32LocalPfiltAlgoOut / 4);
   VEMS_vidSET(Mf_p_filt_crite_next_uavn0, s16LocalMf_p_filt_crite_next_uav);
   Misf_tiDlyLongWinAdpPrev = MATHSRV_udtMIN(u32LocalMisf_tiDlyLongWinAdp,
                                             199999);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDET_vidCombAlgo                                        */
/* !Description :  Ce bloc calcule la sortie de l’algorithme « combustion »,  */
/*                 ainsi que l’erreur introduite par les défauts géométriques */
/*                 de la cible régime moteur                                  */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Mf_comb_crite_prev_uavn0;                                    */
/*  input sint16 Mf_comb_crite_uavn0;                                         */
/*  input sint16 Mf_comb_crite_next_uavn0;                                    */
/*  input uint32 Misf_tiDlyTDCWinAdp;                                         */
/*  input uint32 Misf_tiDlyExpWinAdp;                                         */
/*  input uint32 Misf_tiDlyBdcWinAdp;                                         */
/*  output sint16 Mf_comb_crite_prev_prev_uavn0;                              */
/*  output sint16 Mf_comb_crite_prev_uavn0;                                   */
/*  output sint16 Mf_comb_crite_uavn0;                                        */
/*  output sint16 Mf_comb_crite_next_uavn0;                                   */
/*  output sint16 Mf_comb_algo_out_uavn0;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDET_vidCombAlgo(void)
{
   uint16 u16LocalTemp;
   uint32 u32LocalMisf_tiDlyTDCWinAdp;
   uint32 u32LocalMisf_tiDlyExpWinAdp;
   uint32 u32LocalMisf_tiDlyBdcWinAdp;
   uint32 u32LocalCombCritNext;
   uint32 u32LocalTemp;
   uint32 u32LocalTemp1;
   uint32 u32LocalTemp2;
   sint16 s16LocalMf_comb_crite_next_uavn0;
   sint16 s16LocalMf_comb_crite_uavn0;
   sint16 s16LocalMf_comb_crite_prev_uavn0;
   sint16 s16LocalMf_next_uavn0;
   sint32 s32LocalCombAlgoOut;


   VEMS_vidGET(Mf_comb_crite_prev_uavn0, s16LocalMf_comb_crite_prev_uavn0);
   VEMS_vidGET(Mf_comb_crite_uavn0, s16LocalMf_comb_crite_uavn0);
   VEMS_vidGET(Mf_comb_crite_next_uavn0, s16LocalMf_comb_crite_next_uavn0);

   VEMS_vidGET(Misf_tiDlyTDCWinAdp, u32LocalMisf_tiDlyTDCWinAdp);
   VEMS_vidGET(Misf_tiDlyExpWinAdp, u32LocalMisf_tiDlyExpWinAdp);
   VEMS_vidGET(Misf_tiDlyBdcWinAdp, u32LocalMisf_tiDlyBdcWinAdp);

   if (u32LocalMisf_tiDlyExpWinAdp >= (UINT32_MAX / (uint32)2))
   {
      u32LocalTemp = UINT32_MAX;
   }
   else
   {
      u32LocalTemp = u32LocalMisf_tiDlyExpWinAdp * 2;
   }
   u32LocalTemp2 = UINT32_MAX - u32LocalMisf_tiDlyTDCWinAdp;
   if (u32LocalTemp2 >= u32LocalMisf_tiDlyBdcWinAdp)
   {
      u32LocalTemp1 = u32LocalMisf_tiDlyTDCWinAdp + u32LocalMisf_tiDlyBdcWinAdp;
   }
   else
   {
      u32LocalTemp1 = UINT32_MAX;
   }

   if (u32LocalMisf_tiDlyExpWinAdp != 0)
   {
      if (u32LocalTemp1 > u32LocalTemp)
      {
         u32LocalCombCritNext = u32LocalTemp1 - u32LocalTemp;

         if (u32LocalCombCritNext > (UINT32_MAX / (uint32)32768))
         {
            u32LocalCombCritNext = u32LocalCombCritNext
                                 / u32LocalMisf_tiDlyExpWinAdp;
            u32LocalCombCritNext = u32LocalCombCritNext * (uint32)32768;
         }
         else
         {
            u32LocalCombCritNext = u32LocalCombCritNext * (uint32)32768;
            u32LocalCombCritNext = u32LocalCombCritNext
                                 / u32LocalMisf_tiDlyExpWinAdp;
         }
         u16LocalTemp = (uint16)MATHSRV_udtMIN(u32LocalCombCritNext,
                                               32768);
         s16LocalMf_next_uavn0 = (sint16)((-1) * u16LocalTemp);
      }
      else
      {
         /* QAC justification: the result of operation is always positive*/
         u32LocalCombCritNext = u32LocalTemp - u32LocalTemp1;
         if (u32LocalCombCritNext > (UINT32_MAX / (uint32)32768))
         {
            u32LocalCombCritNext = (u32LocalCombCritNext
                                / u32LocalMisf_tiDlyExpWinAdp);
            u32LocalCombCritNext = u32LocalCombCritNext * (uint32)32768;
         }
         else
         {
            u32LocalCombCritNext = u32LocalCombCritNext * (uint32)32768;
            u32LocalCombCritNext = u32LocalCombCritNext
                                 / u32LocalMisf_tiDlyExpWinAdp;
         }
         u16LocalTemp = (uint16)MATHSRV_udtMIN(u32LocalCombCritNext,
                                               32767);
         s16LocalMf_next_uavn0 = (sint16)u16LocalTemp;
      }
   }
   else
   {
      s16LocalMf_next_uavn0 = 32767;
   }

   VEMS_vidSET(Mf_comb_crite_prev_prev_uavn0, s16LocalMf_comb_crite_prev_uavn0);
   VEMS_vidSET(Mf_comb_crite_prev_uavn0, s16LocalMf_comb_crite_uavn0);
   VEMS_vidSET(Mf_comb_crite_uavn0, s16LocalMf_comb_crite_next_uavn0);
   VEMS_vidSET(Mf_comb_crite_next_uavn0, s16LocalMf_next_uavn0);

   s32LocalCombAlgoOut = (sint32)( (s16LocalMf_comb_crite_next_uavn0 * 2)
                                 - ( s16LocalMf_next_uavn0
                                   + s16LocalMf_comb_crite_uavn0));
   Mf_comb_algo_out_uavn0 = (sint16)((s32LocalCombAlgoOut + 2)/ 4);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDET_vidAlgoOutput                                      */
/* !Description :  Ce bloc gère la stratégie de détection par l’algorithme    */
/*                 combustion selon le régime et la stratégie de détection par*/
/*                 l’algorithme P filtre                                      */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFDET_vidCombDet();                                    */
/*  extf argret void MISFDET_vidPfiltDet();                                   */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Mf_comb_algo_n_max_uacn0;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDET_vidAlgoOutput(void)
{
   uint8   u8LocalRegime_moteur_32;


   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   if (u8LocalRegime_moteur_32 <= Mf_comb_algo_n_max_uacn0)
   {
      MISFDET_vidCombDet();
   }
   MISFDET_vidPfiltDet();
}
/*------------------------------- end of file --------------------------------*/