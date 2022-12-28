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
/* !File            : INJFARCTLUSCTL_FCT6.c                                   */
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
/*   1 / INJFARCTLUSCTL_vidCalcLFB                                            */
/*   2 / INJFARCTLUSCTL_vidCalLFBLean                                         */
/*   3 / INJFARCTLUSCTL_vidCalLFBRich                                         */
/*   4 / INJFARCTLUSCTL_vidCallbdSafDiag                                      */
/*   5 / INJFARCTLUSCTL_vidCalcLFBFilt                                        */
/*   6 / INJFARCTLUSCTL_vidFCallbdLdDerv                                      */
/*   7 / INJFARCTLUSCTL_vidResetLFB                                           */
/*   8 / INJFARCTLUSCTL_vidInitFeedParam                                      */
/*   9 / INJFARCTLUSCTL_vidInitClosedLoop                                     */
/*   10 / INJFARCTLUSCTL_vidInitLambdaFB                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5215083 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/INJCTLSYS/INJFARCTLUSCTL/INJFARC$*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   18 Apr 2014 $*/
/* $Author::   mbenfrad                               $$Date::   18 Apr 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "INJFARCTLUSCTL.H"
#include "INJFARCTLUSCTL_L.H"
#include "INJFARCTLUSCTL_IM.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidCalcLFB                                  */
/* !Description :  Cette fonction permet de déterminer le correcteur de       */
/*                 richesse de la régulation de richesse.                     */
/* !Number      :  FCT6.1                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLUSCTL_vidCalLFBLean();                          */
/*  extf argret void INJFARCTLUSCTL_vidCalLFBRich();                          */
/*  extf argret void INJFARCTLUSCTL_vidCallbdSafDiag();                       */
/*  input boolean Lambda_waiting;                                             */
/*  input uint16 Lambda_feedback_lump;                                        */
/*  input uint16 Lambda_feedback_step;                                        */
/*  input st26 Feedback_calculations_state;                                   */
/*  input st31 Feedback_saf_diag_calc_state;                                  */
/*  input boolean Manu_inh_clamp_lambda_feedback;                             */
/*  input boolean Lambda_for_saf_diag_active;                                 */
/*  output uint16 Lambda_feedback_delta;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidCalcLFB(void)
{
   boolean bLocalLambda_for_saf_diag_active;
   uint8   u8LocalFeedbackCalculationsState;


   if (Lambda_waiting != 0)
   {
      Lambda_feedback_delta = Lambda_feedback_lump;
   }
   else
   {
      Lambda_feedback_delta = Lambda_feedback_step;
   }
   VEMS_vidGET(Feedback_calculations_state, u8LocalFeedbackCalculationsState);
   if (  (u8LocalFeedbackCalculationsState == FEEDBACK_SYSTEM_LEAN)
      || (Feedback_saf_diag_calc_state == SAF_DIAG_ENRICHMENT)
      || (  (u8LocalFeedbackCalculationsState == FEEDBACK_MOVING_LEAN_TO_RICH)
         && (Manu_inh_clamp_lambda_feedback != 0) )
      )
   {
      INJFARCTLUSCTL_vidCalLFBLean();
   }
   if (  (u8LocalFeedbackCalculationsState == FEEDBACK_SYSTEM_RICH )
      || (Feedback_saf_diag_calc_state == SAF_DIAG_ENLEANMENT)
      || (  ( u8LocalFeedbackCalculationsState == FEEDBACK_MOVING_RICH_TO_LEAN )
         && (Manu_inh_clamp_lambda_feedback != 0))
      )
   {
      INJFARCTLUSCTL_vidCalLFBRich();
   }
   VEMS_vidGET(Lambda_for_saf_diag_active, bLocalLambda_for_saf_diag_active);
   if (bLocalLambda_for_saf_diag_active != 0)
   {
      INJFARCTLUSCTL_vidCallbdSafDiag();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidCalLFBLean                               */
/* !Description :  Cette fonction permet de déterminer le correcteur richesse */
/*                 de la régulation de la richesse pour le cas pauvre.        */
/* !Number      :  FCT6.2                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Lambda_feedback;                                             */
/*  input uint16 Lambda_feedback_delta;                                       */
/*  output sint16 Lambda_feedback;                                            */
/*  output uint16 AFReg_facCorRich;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidCalLFBLean(void)
{
   uint16 u16LocalAFRegFacCorRich;
   sint16 s16LocalLambda_feedback;
   sint32 s32LocalSum;


   VEMS_vidGET(Lambda_feedback, s16LocalLambda_feedback);
   s32LocalSum = (sint32)(s16LocalLambda_feedback + Lambda_feedback_delta);
   s16LocalLambda_feedback = (sint16)MATHSRV_udtMIN(s32LocalSum, 32767);

   u16LocalAFRegFacCorRich = (uint16)((s16LocalLambda_feedback / 1024) + 128);

   VEMS_vidSET(Lambda_feedback, s16LocalLambda_feedback);
   VEMS_vidSET(AFReg_facCorRich, u16LocalAFRegFacCorRich);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidCalLFBRich                               */
/* !Description :  Cette fonction permet de déterminer le correcteur richesse */
/*                 de la régulation de la richesse pour le cas riche.         */
/* !Number      :  FCT6.3                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Lambda_feedback;                                             */
/*  input uint16 Lambda_feedback_delta;                                       */
/*  output sint16 Lambda_feedback;                                            */
/*  output uint16 AFReg_facCorRich;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidCalLFBRich(void)
{
   sint32 s32LocalAFRegFacCorRich;
   sint16 s16LocalLambda_feedback;
   sint32 s32LocalDiff;


   VEMS_vidGET(Lambda_feedback, s16LocalLambda_feedback);
   s32LocalDiff = (sint32)(s16LocalLambda_feedback - Lambda_feedback_delta);
   s16LocalLambda_feedback = (sint16) MATHSRV_udtMAX (s32LocalDiff , - 32768);
   s32LocalAFRegFacCorRich = (s16LocalLambda_feedback / 1024) + 128;

   VEMS_vidSET(Lambda_feedback, s16LocalLambda_feedback);
   VEMS_vidSET(AFReg_facCorRich, (uint16)s32LocalAFRegFacCorRich);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidCallbdSafDiag                            */
/* !Description :  Cette fonction est appelée si Indicateur d' activation de  */
/*                 la régulation de richesse  pour l' IAE est active.         */
/* !Number      :  FCT6.4                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Lambda_fb_for_saf_diag_thresh;                                */
/*  input sint16 Lambda_feedback;                                             */
/*  output sint16 Lambda_feedback;                                            */
/*  output uint16 AFReg_facCorRich;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidCallbdSafDiag(void)
{
   uint8  u8LocalLambdaFbForSafDiagThresh;
   uint16 u16LocalAFRegFacCorRich;
   sint16 s16LocalLambda_feedback;
   sint32 s32LocalMin;


   VEMS_vidGET(Lambda_fb_for_saf_diag_thresh, u8LocalLambdaFbForSafDiagThresh);
   s32LocalMin = -(sint32)(u8LocalLambdaFbForSafDiagThresh) * 256;

   VEMS_vidGET(Lambda_feedback, s16LocalLambda_feedback);
   s16LocalLambda_feedback = (sint16)MATHSRV_udtMAX(s16LocalLambda_feedback,
                                                    s32LocalMin);
   u16LocalAFRegFacCorRich = (uint16)((s16LocalLambda_feedback / 1024) + 128);

   VEMS_vidSET(Lambda_feedback, s16LocalLambda_feedback);
   VEMS_vidSET(AFReg_facCorRich, u16LocalAFRegFacCorRich);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidCalcLFBFilt                              */
/* !Description :  Cette fonction est appelé si l'indicateur de prise en      */
/*                 compte des sauts de  richesse est mis à "1"                */
/* !Number      :  FCT6.5                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLUSCTL_vidSetlbdFltMdDly();                      */
/*  input sint16 Lambda_feedback;                                             */
/*  input sint16 Lambda_feedback_previous;                                    */
/*  output boolean Lambda_waiting;                                            */
/*  output sint16 Lambda_feedback_mean;                                       */
/*  output sint16 Lambda_feedback_previous;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidCalcLFBFilt(void)
{
   sint16 s16LocalLambda_feedback;


   VEMS_vidGET(Lambda_feedback, s16LocalLambda_feedback);

   Lambda_waiting = 0;
   Lambda_feedback_mean =
      (sint16)( (Lambda_feedback_previous + s16LocalLambda_feedback) / 2 );
   Lambda_feedback_previous = s16LocalLambda_feedback;
   INJFARCTLUSCTL_vidSetlbdFltMdDly();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidFCallbdLdDerv                            */
/* !Description :  Cette fonction permet de déterminer la dérivée de la charge*/
/*                 moteur entre deux PMH                                      */
/* !Number      :  FCT6.6                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Engine_air_load;                                             */
/*  input uint16 Lbda_engine_air_load_prev;                                   */
/*  input uint16 Periode_moteur;                                              */
/*  output sint8 Engine_air_load_derivate;                                    */
/*  output uint16 Lbda_engine_air_load_prev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidFCallbdLdDerv(void)
{
   uint16 u16LocalPeriode_moteur;
   uint16 u16LocalEngine_air_load;
   sint32 s32Local;


   VEMS_vidGET(Engine_air_load, u16LocalEngine_air_load);
   s32Local = (sint32)( u16LocalEngine_air_load - Lbda_engine_air_load_prev)
                      * 191;
   VEMS_vidGET(Periode_moteur, u16LocalPeriode_moteur);
   if (u16LocalPeriode_moteur == 0)
   {
      if (s32Local > 0)
      {
         Engine_air_load_derivate = 127;
      }
      else
      {
         Engine_air_load_derivate = -128;
      }
   }
   else
   {
      Engine_air_load_derivate =
         (sint8)MATHSRV_udtCLAMP((s32Local / u16LocalPeriode_moteur),
                                 -128,
                                 127);
   }
   Lbda_engine_air_load_prev = u16LocalEngine_air_load;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidResetLFB                                 */
/* !Description :  Fonction reset de correcteur de richesse .                 */
/* !Number      :  FCT6.7                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output sint16 Lambda_feedback;                                            */
/*  output uint16 AFReg_facCorRich;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidResetLFB(void)
{
   VEMS_vidSET(Lambda_feedback, 0);
   VEMS_vidSET(AFReg_facCorRich, 128);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidInitFeedParam                            */
/* !Description :  Fonction d'initialisation des paramètres Feedback.         */
/* !Number      :  FCT6.8                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Lambda_feedback_step;                                       */
/*  output uint16 Lambda_feedback_lump;                                       */
/*  output boolean Lambda_waiting;                                            */
/*  output sint16 Lambda_feedback_mean;                                       */
/*  output sint16 Lambda_feedback_previous;                                   */
/*  output sint16 Lambda_feedback_filtered;                                   */
/*  output sint16 AFReg_rFbLsclFil;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidInitFeedParam(void)
{
   Lambda_feedback_step = 0;
   Lambda_feedback_lump = 0;
   Lambda_waiting = 0;
   Lambda_feedback_mean = 0;
   Lambda_feedback_previous = 0;
   VEMS_vidSET(Lambda_feedback_filtered, 0);
   VEMS_vidSET(AFReg_rFbLsclFil, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidInitClosedLoop                           */
/* !Description :  Sur la première activation de l' automate                  */
/*                 Feedback_calculations_state après démarrage, on initialise */
/*                 la valeur  du Lambda_feedback à partir des corrections de  */
/*                 richesse en cours d' application pour éviter un saut de    */
/*                 richesse important .                                       */
/* !Number      :  FCT6.9                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Obj_rich_depart;                                             */
/*  input uint16 Obj_rich_en_regulation_richesse;                             */
/*  output sint16 Lambda_feedback;                                            */
/*  output uint16 AFReg_facCorRich;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidInitClosedLoop(void)
{
   uint16 u16LocalObjRichRegRichesse;
   uint16 u16LocalAFRegFacCorRich;
   uint32 u32Localdiff;
   uint32 u32LocalObj_rich_depart;
   sint16 s16LocalLambda_feedback;


   VEMS_vidGET(Obj_rich_depart, u32LocalObj_rich_depart);
   VEMS_vidGET(Obj_rich_en_regulation_richesse, u16LocalObjRichRegRichesse);
   if (u32LocalObj_rich_depart > u16LocalObjRichRegRichesse)
   {
      u32Localdiff = ( u32LocalObj_rich_depart
                     - u16LocalObjRichRegRichesse);
      if ((((u32Localdiff * 32768) / (uint32)RICHESSE_1) * 4) > 32767)
      {
         VEMS_vidSET(Lambda_feedback, 32767);
         VEMS_vidSET(AFReg_facCorRich, 159);
      }
      else
      {
         s16LocalLambda_feedback = (sint16)( ( (u32Localdiff * 32768)
                                             / (uint32)RICHESSE_1)
                                           * 4);
         u16LocalAFRegFacCorRich = (uint16)( (s16LocalLambda_feedback / 1024)
                                           + 128);
         VEMS_vidSET(Lambda_feedback, s16LocalLambda_feedback);
         VEMS_vidSET(AFReg_facCorRich, u16LocalAFRegFacCorRich);
      }
   }
   else
   {
      VEMS_vidSET(Lambda_feedback, 0);
      VEMS_vidSET(AFReg_facCorRich, 128);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidInitLambdaFB                             */
/* !Description :  Si l’autorisation de bouclage est nulle, le correcteur de  */
/*                 richesse est mis à zéro.                                   */
/* !Number      :  FCT6.10                                                    */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLUSCTL_vidResetLFB();                            */
/*  input boolean Lambda_cond_for_adaptation;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidInitLambdaFB(void)
{
   boolean bLocalLambda_cond_for_adaptation;


   VEMS_vidGET(Lambda_cond_for_adaptation, bLocalLambda_cond_for_adaptation);
   if (bLocalLambda_cond_for_adaptation == 0)
   {
      INJFARCTLUSCTL_vidResetLFB();
   }
}

/*------------------------------- end of file --------------------------------*/