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
/* !File            : MISFSUCDET_FCT3.C                                       */
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
/*   1 / MISFSUCDET_vidFirstFilterMain                                        */
/*   2 / MISFSUCDET_vidFirstFilter                                            */
/*   3 / MISFSUCDET_vidFirstAlgoTrust                                         */
/*   4 / MISFSUCDET_vidFirstCombDetection                                     */
/*   5 / MISFSUCDET_vidFstPfiltDetection                                      */
/*   6 / MISFSUCDET_vidSndFilterMain                                          */
/*   7 / MISFSUCDET_vidSecondFilter                                           */
/*   8 / MISFSUCDET_vidSndAlgoTrust                                           */
/*   9 / MISFSUCDET_vidSndCombDetection                                       */
/*   10 / MISFSUCDET_vidSndPfiltDetect                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5198660 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFSUCDET/MISFSUCDET_FCT3.C_$*/
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
/* !Function    :  MISFSUCDET_vidFirstFilterMain                              */
/* !Description :  Ce bloc calcule les sorties des algorithmes dédiés à la    */
/*                 détection du 1er des 2 misfires                            */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFSUCDET_vidFirstFilter();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidFirstFilterMain(void)
{
   MISFSUCDET_vidFirstFilter();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidFirstFilter                                  */
/* !Description :  Les algorithmes combustions adaptés à la détection de 2    */
/*                 misfires successifs sont calculés selon deux équations.    */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Mf_p_filt_crite_next_uavn0;                                  */
/*  input sint16 Mf_p_filt_crite_prev_uavn0;                                  */
/*  input sint16 Mf_p_filt_crite_prev_prev_uavn0;                             */
/*  input sint16 Mf_comb_crite_next_uavn0;                                    */
/*  input sint16 Mf_comb_crite_prev_uavn0;                                    */
/*  input sint16 Mf_comb_crite_prev_prev_uavn0;                               */
/*  output sint16 Mf_p_filt1_algo_out_uavn0;                                  */
/*  output sint16 Mf_comb1_algo_out_corr_uavn0;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidFirstFilter(void)
{
   sint16 s16LocalMf_p_filt_crite_next_uav;
   sint16 s16LocalMf_p_filt_crite_prev_uav;
   sint16 s16LocalMf_p_filt_crite_prev_pre;
   sint16 s16LocalMf_comb_crite_next_uavn0;
   sint16 s16LocalMf_comb_crite_prev_uavn0;
   sint16 s16LocalMf_comb_crite_prev_prev;
   sint32 s32LocalPfilt1AlgoOut;
   sint32 s32LocalComb1AlgoOut;


   VEMS_vidGET(Mf_p_filt_crite_next_uavn0, s16LocalMf_p_filt_crite_next_uav);
   VEMS_vidGET(Mf_p_filt_crite_prev_uavn0, s16LocalMf_p_filt_crite_prev_uav);
   VEMS_vidGET(Mf_p_filt_crite_prev_prev_uavn0,
               s16LocalMf_p_filt_crite_prev_pre);
   VEMS_vidGET(Mf_comb_crite_next_uavn0, s16LocalMf_comb_crite_next_uavn0);
   VEMS_vidGET(Mf_comb_crite_prev_uavn0, s16LocalMf_comb_crite_prev_uavn0);
   VEMS_vidGET(Mf_comb_crite_prev_prev_uavn0, s16LocalMf_comb_crite_prev_prev);

   s32LocalPfilt1AlgoOut = (sint32)( (s16LocalMf_p_filt_crite_prev_uav * 2)
                                   - ( s16LocalMf_p_filt_crite_next_uav
                                     + s16LocalMf_p_filt_crite_prev_pre));
   Mf_p_filt1_algo_out_uavn0 = (sint16)(s32LocalPfilt1AlgoOut / 4);

   s32LocalComb1AlgoOut = (sint32)( (s16LocalMf_comb_crite_prev_uavn0 * 2)
                                  - ( s16LocalMf_comb_crite_next_uavn0
                                    + s16LocalMf_comb_crite_prev_prev));
   Mf_comb1_algo_out_corr_uavn0 = (sint16)(s32LocalComb1AlgoOut / 4);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidFirstAlgoTrust                               */
/* !Description :  Ce bloc calcule : l’indice de confiance appliqué au « 1er  */
/*                 misfire » scruté et l’indice de confiance appliqué au «    */
/*                 2ième misfire » scruté                                     */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFSUCDET_vidFirstCombDetection();                      */
/*  extf argret void MISFSUCDET_vidFstPfiltDetection();                       */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Mf_comb_algo_n_max_uacn0;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidFirstAlgoTrust(void)
{
   uint8   u8LocalRegime_moteur_32;


   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   if (u8LocalRegime_moteur_32 <= Mf_comb_algo_n_max_uacn0)
   {
      MISFSUCDET_vidFirstCombDetection();
   }
   MISFSUCDET_vidFstPfiltDetection();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidFirstCombDetection                           */
/* !Description :  Calcul de l’indice de confiance appliqué au « 1er misfire »*/
/*                 scruté                                                     */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Mf_comb_algo_thresh_uavn0;                                   */
/*  input sint16 Mf_comb1_algo_out_corr_uavn0;                                */
/*  output sint16 Mf_comb1_algo_trust_uavn0;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidFirstCombDetection(void)
{
   uint16 u16LocalMf_comb_algo_thresh_uavn;
   sint32 s32LocalProd;
   sint32 s32LocalQuot;


   VEMS_vidGET(Mf_comb_algo_thresh_uavn0, u16LocalMf_comb_algo_thresh_uavn);
   if (u16LocalMf_comb_algo_thresh_uavn != 0)
   {
      s32LocalProd = (sint32)(Mf_comb1_algo_out_corr_uavn0 * 8192);
      s32LocalQuot = (s32LocalProd / u16LocalMf_comb_algo_thresh_uavn);
      Mf_comb1_algo_trust_uavn0 = (sint16)MATHSRV_udtCLAMP(s32LocalQuot,
                                                           -32768,
                                                           32767);
   }
   else
   {
      Mf_comb1_algo_trust_uavn0 = 32767;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidFstPfiltDetection                            */
/* !Description :  Calcul de l’indice de confiance appliqué au « 2ème misfire */
/*                 » scruté                                                   */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Mf_p_filt_algo_thresh_uavn0;                                 */
/*  input sint16 Mf_p_filt1_algo_out_uavn0;                                   */
/*  output sint16 Mf_p_filt1_algo_trust_uavn0;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidFstPfiltDetection(void)
{
   uint16 u16LocalMf_p_filt_algo_thresh_ua;
   sint32 s32LocalProd;
   sint32 s32LocalQuot;


   VEMS_vidGET(Mf_p_filt_algo_thresh_uavn0, u16LocalMf_p_filt_algo_thresh_ua);
   if (u16LocalMf_p_filt_algo_thresh_ua != 0)
   {
      s32LocalProd = (sint32)(Mf_p_filt1_algo_out_uavn0 * 8192);
      s32LocalQuot = (s32LocalProd / u16LocalMf_p_filt_algo_thresh_ua);
      Mf_p_filt1_algo_trust_uavn0 = (sint16)MATHSRV_udtCLAMP(s32LocalQuot,
                                                             -32768,
                                                             32767);
   }
   else
   {
      Mf_p_filt1_algo_trust_uavn0 = 32767;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidSndFilterMain                                */
/* !Description :  Ce bloc calcule les sorties des algorithmes dédiés à la    */
/*                 détection du 2ième misfire                                 */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFSUCDET_vidSecondFilter();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidSndFilterMain(void)
{
   MISFSUCDET_vidSecondFilter();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidSecondFilter                                 */
/* !Description :  Les algorithmes combustions adaptés à la détection du 2ième*/
/*                 misfire sont calculés selon deux équations                 */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Mf_p_filt_crite_next_uavn0;                                  */
/*  input sint16 Mf_p_filt_crite_uavn0;                                       */
/*  input sint16 Mf_p_filt_crite_prev_prev_uavn0;                             */
/*  input sint16 Mf_comb_crite_next_uavn0;                                    */
/*  input sint16 Mf_comb_crite_uavn0;                                         */
/*  input sint16 Mf_comb_crite_prev_prev_uavn0;                               */
/*  output sint16 Mf_p_filt2_algo_out_uavn0;                                  */
/*  output sint16 Mf_comb2_algo_out_corr_uavn0;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidSecondFilter(void)
{
   sint16 s16LocalMf_p_filt_crite_next_uav;
   sint16 s16LocalMf_p_filt_crite_uavn0;
   sint16 s16LocalMf_p_filt_crite_prev_pre;
   sint16 s16LocalMf_comb_crite_next_uavn0;
   sint16 s16LocalMf_comb_crite_uavn0;
   sint16 s16LocalMf_comb_crite_prev_prev;
   sint32 s32LocalPfilt2AlgoOut;
   sint32 s32LocalComb2AlgoOut;


   VEMS_vidGET(Mf_p_filt_crite_next_uavn0, s16LocalMf_p_filt_crite_next_uav);
   VEMS_vidGET(Mf_p_filt_crite_uavn0, s16LocalMf_p_filt_crite_uavn0);
   VEMS_vidGET(Mf_p_filt_crite_prev_prev_uavn0,
               s16LocalMf_p_filt_crite_prev_pre);
   VEMS_vidGET(Mf_comb_crite_next_uavn0, s16LocalMf_comb_crite_next_uavn0);
   VEMS_vidGET(Mf_comb_crite_uavn0, s16LocalMf_comb_crite_uavn0);
   VEMS_vidGET(Mf_comb_crite_prev_prev_uavn0, s16LocalMf_comb_crite_prev_prev);

   s32LocalPfilt2AlgoOut = (sint32)( (s16LocalMf_p_filt_crite_uavn0 * 2)
                                   - ( s16LocalMf_p_filt_crite_next_uav
                                     + s16LocalMf_p_filt_crite_prev_pre));
   Mf_p_filt2_algo_out_uavn0 = (sint16)(s32LocalPfilt2AlgoOut / 4);

   s32LocalComb2AlgoOut = (sint32)( (s16LocalMf_comb_crite_uavn0 * 2)
                                  - ( s16LocalMf_comb_crite_next_uavn0
                                    + s16LocalMf_comb_crite_prev_prev));
   Mf_comb2_algo_out_corr_uavn0 = (sint16)(s32LocalComb2AlgoOut / 4);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidSndAlgoTrust                                 */
/* !Description :  Ce bloc calcule : l’indice de confiance appliqué au « 1er  */
/*                 misfire » scruté et l’indice de confiance appliqué au «    */
/*                 2ième misfire » scruté                                     */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFSUCDET_vidSndCombDetection();                        */
/*  extf argret void MISFSUCDET_vidSndPfiltDetect();                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Mf_comb_algo_n_max_uacn0;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidSndAlgoTrust(void)
{
   uint8   u8LocalRegime_moteur_32;


   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   if (u8LocalRegime_moteur_32 <= Mf_comb_algo_n_max_uacn0)
   {
      MISFSUCDET_vidSndCombDetection();
   }
   MISFSUCDET_vidSndPfiltDetect();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidSndCombDetection                             */
/* !Description :  Calcul de l’indice de confiance appliqué au « 1er misfire »*/
/*                 scruté                                                     */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Mf_comb_algo_thresh_uavn0;                                   */
/*  input sint16 Mf_comb2_algo_out_corr_uavn0;                                */
/*  output sint16 Mf_comb2_algo_trust_uavn0;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidSndCombDetection(void)
{
   uint16 u16LocalMf_comb_algo_thresh_uavn;
   sint32 s32LocalProd;
   sint32 s32LocalQuot;


   VEMS_vidGET(Mf_comb_algo_thresh_uavn0, u16LocalMf_comb_algo_thresh_uavn);
   if (u16LocalMf_comb_algo_thresh_uavn != 0)
   {
      s32LocalProd = (sint32)(Mf_comb2_algo_out_corr_uavn0 * 8192);
      s32LocalQuot = (s32LocalProd / u16LocalMf_comb_algo_thresh_uavn);
      Mf_comb2_algo_trust_uavn0 = (sint16)MATHSRV_udtCLAMP(s32LocalQuot,
                                                           -32768,
                                                           32767);
   }
   else
   {
      Mf_comb2_algo_trust_uavn0 = 32767;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidSndPfiltDetect                               */
/* !Description :  Calcul de l’indice de confiance appliqué au « 2ème misfire */
/*                 » scruté                                                   */
/* !Number      :  FCT3.10                                                    */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Mf_p_filt_algo_thresh_uavn0;                                 */
/*  input sint16 Mf_p_filt2_algo_out_uavn0;                                   */
/*  output sint16 Mf_p_filt2_algo_trust_uavn0;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidSndPfiltDetect(void)
{
   uint16 u16LocalMf_p_filt_algo_thresh_ua;
   sint32 s32LocalProd;
   sint32 s32LocalQuot;


   VEMS_vidGET(Mf_p_filt_algo_thresh_uavn0, u16LocalMf_p_filt_algo_thresh_ua);
   if (u16LocalMf_p_filt_algo_thresh_ua != 0)
   {
      s32LocalProd = (sint32)(Mf_p_filt2_algo_out_uavn0 * 8192);
      s32LocalQuot = (s32LocalProd / u16LocalMf_p_filt_algo_thresh_ua);
      Mf_p_filt2_algo_trust_uavn0 = (sint16)MATHSRV_udtCLAMP(s32LocalQuot,
                                                             -32768,
                                                             32767);
   }
   else
   {
      Mf_p_filt2_algo_trust_uavn0 = 32767;
   }
}
/*------------------------------- end of file --------------------------------*/