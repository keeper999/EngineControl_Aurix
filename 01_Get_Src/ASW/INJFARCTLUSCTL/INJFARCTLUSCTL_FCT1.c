/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJFARCTLUSCTL                                          */
/* !Description     : INJFARCTLUSCTL component                                */
/*                                                                            */
/* !Module          : INJFARCTLUSCTL                                          */
/* !Description     : CALCUL DE LA BOUCLE FERMEE DE LA REGULATION DE RICHESSE */
/*                    AVEC SONDE AMONT                                        */
/*                                                                            */
/* !File            : INJFARCTLUSCTL_FCT1.c                                   */
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
/*   1 / INJFARCTLUSCTL_vidInitOutput                                         */
/*   2 / INJFARCTLUSCTL_vidInit                                               */
/*   3 / INJFARCTLUSCTL_vidInitFedSaf                                         */
/*   4 / INJFARCTLUSCTL_vidInitFeedState                                      */
/*   5 / INJFARCTLUSCTL_vidFuncCalLFbFilt                                     */
/*   6 / INJFARCTLUSCTL_vidLFbFilSDiagCta                                     */
/*   7 / INJFARCTLUSCTL_vidCalLFbDelayOk                                      */
/*   8 / INJFARCTLUSCTL_vidLFbDelayNok                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5215083 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/INJCTLSYS/INJFARCTLUSCTL/INJFARC$*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   18 Apr 2014 $*/
/* $Author::   mbenfrad                               $$Date::   18 Apr 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "INJFARCTLUSCTL.H"
#include "INJFARCTLUSCTL_L.H"
#include "INJFARCTLUSCTL_IM.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidInitOutput                               */
/* !Description :  Fonction d'initialisation des variables de sortie          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Lbda_transitoire_detectPrev;                               */
/*  output boolean Lambda_slow_mode;                                          */
/*  output uint8 Lambda_filtered_fdbk_mode_delay;                             */
/*  output uint32 INJFARCTLUSCTL_u32AregulFiltMem;                            */
/*  output uint32 Lambda_feedback_can;                                        */
/*  output sint32 INJFARCTLUSCTL_s32LamFeedCanMem;                            */
/*  output uint16 Aregulation;                                                */
/*  output sint16 Moyenne_Lambda_feedback;                                    */
/*  output sint16 INJFARCTLUSCTL_s16LamFeedCanFilt;                           */
/*  output uint16 Dnstr_modifier_time_scale;                                  */
/*  output sint16 InjCtl_rlamAdaptMv;                                         */
/*  output boolean INJFARCTLUSCTL_bRlamAdpReqPrev;                            */
/*  output boolean INJFARCTLUSCTL_bLocalDetinitprev;                          */
/*  output uint8 InjCtl_tiDlyClcrlamAdapt;                                    */
/*  output boolean INJFARCTLUSCTL_bMnRnORngIntrPrev;                          */
/*  output boolean INJFARCTLUSCTL_bMnRnORgItrPrev;                            */
/*  output boolean INJFARCTLUSCTL_bECUReset;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidInitOutput(void)
{
   Lbda_transitoire_detectPrev = 0;
   VEMS_vidSET(Lambda_slow_mode, 0);
   VEMS_vidSET(Lambda_filtered_fdbk_mode_delay, 0);
   INJFARCTLUSCTL_u32AregulFiltMem = 0;
   VEMS_vidSET(Lambda_feedback_can, 0);
   INJFARCTLUSCTL_s32LamFeedCanMem = 0;
   Aregulation = 0;
   Moyenne_Lambda_feedback = 0;
   INJFARCTLUSCTL_s16LamFeedCanFilt = 0;
   VEMS_vidSET(Dnstr_modifier_time_scale, 0);
   InjCtl_rlamAdaptMv = 0;
   INJFARCTLUSCTL_bRlamAdpReqPrev = 0;
   INJFARCTLUSCTL_bLocalDetinitprev =0;
   InjCtl_tiDlyClcrlamAdapt = 0;
   INJFARCTLUSCTL_bMnRnORngIntrPrev = 0;
   INJFARCTLUSCTL_bMnRnORgItrPrev = 0;
   INJFARCTLUSCTL_bECUReset = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidInit                                     */
/* !Description :  Fonction d'initialisation au reset                         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output sint16 Lambda_feedback;                                            */
/*  output sint16 Lambda_feedback_max;                                        */
/*  output sint16 Lambda_feedback_min;                                        */
/*  output boolean Lambda_feedback_max_calc;                                  */
/*  output boolean Lambda_feedback_min_calc;                                  */
/*  output uint16 Lbda_engine_air_load_prev;                                  */
/*  output boolean Lbda_active_gain_attenu_rich;                              */
/*  output uint16 Lbda_maintien_attenuation_count;                            */
/*  output boolean Lbda_transitoire_detect;                                   */
/*  output uint16 Lambda_feedback_step;                                       */
/*  output uint16 Lambda_feedback_lump;                                       */
/*  output boolean Lambda_waiting;                                            */
/*  output sint16 Lambda_feedback_mean;                                       */
/*  output sint16 Lambda_feedback_previous;                                   */
/*  output sint16 Lambda_feedback_filtered;                                   */
/*  output sint16 AFReg_rFbLsclFil;                                           */
/*  output uint16 AFReg_facCorRich;                                           */
/*  output boolean InjCtl_bUpdlamMax;                                         */
/*  output boolean InjCtl_bUpdlamMin;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidInit(void)
{
   VEMS_vidSET(Lambda_feedback, 0);
   Lambda_feedback_max =0;
   Lambda_feedback_min =0;
   Lambda_feedback_max_calc =0;
   Lambda_feedback_min_calc =0;
   Lbda_engine_air_load_prev =0;
   Lbda_active_gain_attenu_rich = 0;
   Lbda_maintien_attenuation_count = 0;
   Lbda_transitoire_detect = 0;
   Lambda_feedback_step = 0;
   Lambda_feedback_lump = 0;
   Lambda_waiting = 0;
   Lambda_feedback_mean = 0;
   Lambda_feedback_previous = 0;
   VEMS_vidSET(Lambda_feedback_filtered, 0);
   VEMS_vidSET(AFReg_rFbLsclFil, 0);
   VEMS_vidSET(AFReg_facCorRich, 128);
   InjCtl_bUpdlamMax = 0;
   InjCtl_bUpdlamMin = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidInitFedSaf                               */
/* !Description :  Fonction d'initialisation de l'automate                    */
/*                 Feedback_saf_diag_calc_state                               */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output st31 Feedback_saf_diag_calc_state;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidInitFedSaf(void)
{
   Feedback_saf_diag_calc_state = WAITING_FOR_SAF_DIAG_REQUEST;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidInitFeedState                            */
/* !Description :  Fonction d'initialisation de l'automate                    */
/*                 Feedback_calculations_state                                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output st26 Feedback_calculations_state;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidInitFeedState(void)
{
   VEMS_vidSET(Feedback_calculations_state, FEEDBACK_CLOSED_LOOP_INIT);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidFuncCalLFbFilt                           */
/* !Description :  Figeage de Lambda_feedback_filtered en phase de diagnostic */
/*                 catalyseur intrusif                                        */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_R_08_05829_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLUSCTL_vidLFbFilSDiagCta();                      */
/*  input boolean OxC_bMonRunORngIntr;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidFuncCalLFbFilt(void)
{
   boolean bLocalOxC_bMonRunORngIntr;


   VEMS_vidGET(OxC_bMonRunORngIntr, bLocalOxC_bMonRunORngIntr);
   if (bLocalOxC_bMonRunORngIntr == 0)
   {
      INJFARCTLUSCTL_vidLFbFilSDiagCta();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidLFbFilSDiagCta                           */
/* !Description :  calcul de Lambda_feedback_filtered sans diagnostic         */
/*                 catalyseur                                                 */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLUSCTL_vidCalLFbDelayOk();                       */
/*  extf argret void INJFARCTLUSCTL_vidLFbDelayNok();                         */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Lambda_filtered_fdbk_mode_delay;                              */
/*  input sint16 Lambda_feedback_filtered;                                    */
/*  output sint16 AFReg_rFbLsclFil;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidLFbFilSDiagCta(void)
{
   uint8  u8LocalLambdaFilteredFbModeDelay;
   sint16 s16LocalLambda_feedback_filtered;

   VEMS_vidGET(Lambda_filtered_fdbk_mode_delay,
               u8LocalLambdaFilteredFbModeDelay);
   if (u8LocalLambdaFilteredFbModeDelay == 0)
   {
      INJFARCTLUSCTL_vidCalLFbDelayOk();
   }
   else
   {
      INJFARCTLUSCTL_vidLFbDelayNok();
   }
   VEMS_vidGET(Lambda_feedback_filtered, s16LocalLambda_feedback_filtered);
   VEMS_vidSET(AFReg_rFbLsclFil, s16LocalLambda_feedback_filtered);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidCalLFbDelayOk                            */
/* !Description :  Filtrage du premier ordre de Lambda_feedback lorsque le    */
/*                 mélange au niveau du capteur est resté riche ou pauvre     */
/*                 pendant un certain temps.                                  */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Lambda_feedback;                                             */
/*  input sint16 Lambda_feedback_filtered;                                    */
/*  input uint8 Lambda_fdbk_filter_fast_gain;                                 */
/*  output sint16 Lambda_feedback_filtered;                                   */
/*  output sint16 Lambda_feedback_previous;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidCalLFbDelayOk(void)
{
   sint16 s16LocalLambda_feedback;
   sint16 s16LocalLambda_feedback_filtered;
   sint32 s32Local;


   VEMS_vidGET(Lambda_feedback, s16LocalLambda_feedback);
   VEMS_vidGET(Lambda_feedback_filtered, s16LocalLambda_feedback_filtered);
   s32Local =
      (sint32)( ( (s16LocalLambda_feedback - s16LocalLambda_feedback_filtered)
                * Lambda_fdbk_filter_fast_gain)
              / 256);
   s16LocalLambda_feedback_filtered =
      (sint16)(s32Local + s16LocalLambda_feedback_filtered);

   VEMS_vidSET(Lambda_feedback_filtered, s16LocalLambda_feedback_filtered);
   Lambda_feedback_previous = s16LocalLambda_feedback;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidLFbDelayNok                              */
/* !Description :  Filtrage du premier ordre de Lambda_feedback lorsque le    */
/*                 mélange au niveau du capteur est resté riche ou pauvre     */
/*                 pendant un certain temps.                                  */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Lambda_feedback_filtered;                                    */
/*  input sint16 Lambda_feedback_mean;                                        */
/*  input uint8 Lambda_fdbk_filter_slow_gain;                                 */
/*  output sint16 Lambda_feedback_filtered;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidLFbDelayNok(void)
{
   sint16 s16LocalLambda_feedback_filtered;
   sint32 s32Local;


   VEMS_vidGET(Lambda_feedback_filtered, s16LocalLambda_feedback_filtered);
   s32Local = (sint32)( ( ( Lambda_feedback_mean
                          - s16LocalLambda_feedback_filtered)
                        * Lambda_fdbk_filter_slow_gain )
                      / 256);
   s16LocalLambda_feedback_filtered =
      (sint16)(s32Local + s16LocalLambda_feedback_filtered);

   VEMS_vidSET(Lambda_feedback_filtered, s16LocalLambda_feedback_filtered);
}
/*------------------------------- end of file --------------------------------*/