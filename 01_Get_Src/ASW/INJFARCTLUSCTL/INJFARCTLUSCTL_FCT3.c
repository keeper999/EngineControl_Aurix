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
/* !File            : INJFARCTLUSCTL_FCT3.c                                   */
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
/*   1 / INJFARCTLUSCTL_vidMonitorFedSaf                                      */
/*   2 / INJFARCTLUSCTL_vidEdSafRqToSfEnl                                     */
/*   3 / INJFARCTLUSCTL_vidEdSfEnlToSfEnr                                     */
/*   4 / INJFARCTLUSCTL_vidEdSfEnrToSfEnl                                     */
/*   5 / INJFARCTLUSCTL_vidIniUplamMaxMin                                     */
/*   6 / INJFARCTLUSCTL_vidUplamMaxMinIni                                     */
/*   7 / INJFARCTLUSCTL_vidAdaplamfeebcal                                     */
/*   8 / INJFARCTLUSCTL_vidAdaplambdaMean                                     */
/*   9 / INJFARCTLUSCTL_vidIniAdap                                            */
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
#include "MATHSRV.H"
#include "INJFARCTLUSCTL.H"
#include "INJFARCTLUSCTL_L.H"
#include "INJFARCTLUSCTL_IM.H"
#include "SWFAIL.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidMonitorFedSaf                            */
/* !Description :  Les transitions sont évaluées à récurrence du moniteur     */
/*                 rapide de la régulation de richesse, si                    */
/*                 Moniteur_feedback_conds_state = FEEDBACK_FOR_SAF_ENABLED.  */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLUSCTL_vidEdSafRqToSfEnl();                      */
/*  extf argret void INJFARCTLUSCTL_vidEdSfEnlToSfEnr();                      */
/*  extf argret void INJFARCTLUSCTL_vidEdSfEnrToSfEnl();                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Sonde_riche_amont;                                          */
/*  input st31 Feedback_saf_diag_calc_state;                                  */
/*  input boolean Feedback_saf_inh_diag_req_C;                                */
/*  output st31 Feedback_saf_diag_calc_state;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidMonitorFedSaf(void)
{
   boolean bLocalSonde_riche_amont;


   VEMS_vidGET(Sonde_riche_amont, bLocalSonde_riche_amont);
   switch(Feedback_saf_diag_calc_state)
   {
      case WAITING_FOR_SAF_DIAG_REQUEST:
         if ((bLocalSonde_riche_amont != 0)&&(Feedback_saf_inh_diag_req_C == 0))
         {
            Feedback_saf_diag_calc_state = SAF_DIAG_ENLEANMENT;
            INJFARCTLUSCTL_vidEdSafRqToSfEnl();
         }
         break;

      case SAF_DIAG_ENLEANMENT:
         if (bLocalSonde_riche_amont == 0)
         {
            Feedback_saf_diag_calc_state=SAF_DIAG_ENRICHMENT;
            INJFARCTLUSCTL_vidEdSfEnlToSfEnr();
         }
         break;

      case SAF_DIAG_ENRICHMENT:
         if (bLocalSonde_riche_amont != 0)
         {
            Feedback_saf_diag_calc_state = SAF_DIAG_ENLEANMENT;
            INJFARCTLUSCTL_vidEdSfEnrToSfEnl();
         }
         break;

      default:
         Feedback_saf_diag_calc_state = WAITING_FOR_SAF_DIAG_REQUEST;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidEdSafRqToSfEnl                           */
/* !Description :  Affecter lla valeur du pas de richesse IAE riche à la      */
/*                 valeur du pas de Lambda_feedback.                          */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Lambda_for_saf_diag_step_rich;                                */
/*  output uint16 Lambda_feedback_step;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidEdSafRqToSfEnl(void)
{
   Lambda_feedback_step = (uint16)( Lambda_for_saf_diag_step_rich );
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidEdSfEnlToSfEnr                           */
/* !Description :  Affecter la valeur du pas de richesse IAE pauvre à la      */
/*                 valeur du pas Lambda_Feedback , la valeur du saut de       */
/*                 richesse IAE pauvre à la valeur du saut de Lambda_feedback */
/*                 et mettre Indicateur de prise en compte des sauts de       */
/*                 richesse à "1".                                            */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Lambda_for_saf_diag_step_lean;                                */
/*  input uint8 Lambda_for_saf_diag_lump_lean;                                */
/*  output uint16 Lambda_feedback_step;                                       */
/*  output uint16 Lambda_feedback_lump;                                       */
/*  output boolean Lambda_waiting;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidEdSfEnlToSfEnr(void)
{
   Lambda_feedback_step = (uint16)(Lambda_for_saf_diag_step_lean);
   Lambda_feedback_lump = (uint16)(Lambda_for_saf_diag_lump_lean * 64);
   Lambda_waiting = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidEdSfEnrToSfEnl                           */
/* !Description :  Affecter la valeur d u pas de richesse IAE riche  à la     */
/*                 valeur du pas de Lambda_Feedback , la valeur du saut de    */
/*                 richesse IAE riche à  la valeur du saut de Lambda_feedback */
/*                 et mettre Indicateur de prise en compte des sauts de       */
/*                 richesse à "1".                                            */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Lambda_for_saf_diag_step_rich;                                */
/*  input uint8 Lambda_for_saf_diag_lump_rich;                                */
/*  output uint16 Lambda_feedback_step;                                       */
/*  output uint16 Lambda_feedback_lump;                                       */
/*  output boolean Lambda_waiting;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidEdSfEnrToSfEnl(void)
{
   Lambda_feedback_step = (uint16)( Lambda_for_saf_diag_step_rich );
   Lambda_feedback_lump = (uint16)( Lambda_for_saf_diag_lump_rich * 64);
   Lambda_waiting = 1;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidIniUplamMaxMin                           */
/* !Description :  Cette fonction permet de tester l'initialisation des       */
/*                 Indicateurs de calcul du Lambda feedback max et min.       */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLUSCTL_vidUplamMaxMinIni();                      */
/*  input boolean OxC_bRlamAdpReq;                                            */
/*  input boolean OxC_bMonRunORngIntr;                                        */
/*  input boolean INJFARCTLUSCTL_bRlamAdpReqPrev;                             */
/*  input boolean INJFARCTLUSCTL_bMnRnORngIntrPrev;                           */
/*  output boolean INJFARCTLUSCTL_bRlamAdpReqPrev;                            */
/*  output boolean INJFARCTLUSCTL_bMnRnORngIntrPrev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidIniUplamMaxMin(void)
{
   boolean bLocalOxC_bRlamAdpReq;
   boolean bLocalOxCbMnRnORng;


   VEMS_vidGET(OxC_bRlamAdpReq, bLocalOxC_bRlamAdpReq);
   VEMS_vidGET(OxC_bMonRunORngIntr, bLocalOxCbMnRnORng);

   if ( (  (bLocalOxC_bRlamAdpReq != 0)
        && (INJFARCTLUSCTL_bRlamAdpReqPrev == 0))
      ||(  (bLocalOxCbMnRnORng == 0)
        && (INJFARCTLUSCTL_bMnRnORngIntrPrev != 0)))
   {
      INJFARCTLUSCTL_vidUplamMaxMinIni();
   }
   INJFARCTLUSCTL_bRlamAdpReqPrev = bLocalOxC_bRlamAdpReq;
   INJFARCTLUSCTL_bMnRnORngIntrPrev = bLocalOxCbMnRnORng;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidUplamMaxMinIni                           */
/* !Description :  Cette fonction permet d'initialiser les Indicateurs de     */
/*                 calcul du Lambda feedback max et min.                      */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean InjCtl_bUpdlamMax;                                         */
/*  output boolean InjCtl_bUpdlamMin;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidUplamMaxMinIni(void)
{
   InjCtl_bUpdlamMax = 0;
   InjCtl_bUpdlamMin = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidAdaplamfeebcal                           */
/* !Description :  Cette fonction permet de mettre en oeuvre une stratégie    */
/*                 rapide d'adaptation capable d'assurer la cohérence entre le*/
/*                 créneau de richesse demandé par le diag KTA et le lambda   */
/*                 réel.                                                      */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_R_08_05829_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLUSCTL_vidAdaplambdaMean();                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean OxC_bRlamAdpReq;                                            */
/*  input boolean OxC_bRlamAdaptFrz;                                          */
/*  input boolean OxC_bMonRunORngIntr;                                        */
/*  input boolean InjCtl_bUpdlamMax;                                          */
/*  input boolean InjCtl_bUpdlamMin;                                          */
/*  input boolean INJFARCTLUSCTL_bECUReset;                                   */
/*  input sint16 InjCtl_rlamAdaptMv;                                          */
/*  input boolean INJFARCTLUSCTL_bLocalDetinitprev;                           */
/*  input uint8 InjCtl_facFillamAdapt_C;                                      */
/*  input sint32 INJFARCTLUSCTL_s32lamAdaptIntMem;                            */
/*  input boolean INJFARCTLUSCTL_bMnRnORgItrPrev;                             */
/*  input uint8 InjCtl_tiDlyClcrlamAdapt;                                     */
/*  input uint8 InjCtl_tiDlyClcrlamAdapt_C;                                   */
/*  input sint16 InjCtl_rlamAdaptIntery;                                      */
/*  input uint16 InjCtl_rlamAdaptminThd_C;                                    */
/*  output sint16 InjCtl_rlamAdaptIntery;                                     */
/*  output sint32 INJFARCTLUSCTL_s32lamAdaptIntMem;                           */
/*  output boolean INJFARCTLUSCTL_bECUReset;                                  */
/*  output uint8 InjCtl_tiDlyClcrlamAdapt;                                    */
/*  output boolean OxC_bRlamAdaptFrz;                                         */
/*  output sint16 InjCtl_rlamAdapt;                                           */
/*  output boolean INJFARCTLUSCTL_bLocalDetinitprev;                          */
/*  output boolean INJFARCTLUSCTL_bMnRnORgItrPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidAdaplamfeebcal(void)
{
   boolean bLocalDet_init;
   boolean bLocalOxC_bRlamAdpReq;
   boolean bLocalOxC_bRlamAdaptFrz;
   boolean bLocalOxC_bRlamAdaptFrz_Prev;
   boolean bLocalOxC_bMonRunORngIntr;
   uint8   u8LocalInjCtl_tiDlyClcrlamAdapt;
   uint16  u16LocalInjCtl_rlamAdaptIntery;
   sint16  s16LocalInjCtl_tiDlyClcrlamAdapt;
   sint32  s32LocalInjCtl_rlamAdaptIntery;


   VEMS_vidGET(OxC_bRlamAdpReq, bLocalOxC_bRlamAdpReq);
   VEMS_vidGET(OxC_bRlamAdaptFrz, bLocalOxC_bRlamAdaptFrz_Prev);
   VEMS_vidGET(OxC_bMonRunORngIntr, bLocalOxC_bMonRunORngIntr);

   if (  (InjCtl_bUpdlamMax != 0)
      && (InjCtl_bUpdlamMin != 0))
   {
      INJFARCTLUSCTL_vidAdaplambdaMean();
      bLocalDet_init = 1;
   }
   else
   {
      bLocalDet_init = 0;
   }
   if(INJFARCTLUSCTL_bECUReset != 0)
   {
      InjCtl_rlamAdaptIntery = InjCtl_rlamAdaptMv;
      INJFARCTLUSCTL_s32lamAdaptIntMem = (sint32)(InjCtl_rlamAdaptMv * 256);
      INJFARCTLUSCTL_bECUReset = 0;
   }
   else
   {
      if (  (INJFARCTLUSCTL_bLocalDetinitprev == 0)
         && (bLocalDet_init != 0))
      {
         InjCtl_rlamAdaptIntery = InjCtl_rlamAdaptMv;
         INJFARCTLUSCTL_s32lamAdaptIntMem = (sint32)(InjCtl_rlamAdaptMv * 256);
      }
      else
      {
         InjCtl_rlamAdaptIntery =
            MATHSRV_s16FirstOrderFilterGu8(InjCtl_facFillamAdapt_C,
                                           &INJFARCTLUSCTL_s32lamAdaptIntMem,
                                           InjCtl_rlamAdaptMv);
      }
   }
   if (  (bLocalOxC_bRlamAdpReq != 0)
      && (  (bLocalOxC_bMonRunORngIntr != 0)
         || (INJFARCTLUSCTL_bMnRnORgItrPrev == 0)))
   {
      s16LocalInjCtl_tiDlyClcrlamAdapt =
         (sint16)(InjCtl_tiDlyClcrlamAdapt - 1);
      u8LocalInjCtl_tiDlyClcrlamAdapt =
         (uint8)MATHSRV_udtMAX(s16LocalInjCtl_tiDlyClcrlamAdapt, 0);
   }
   else
   {
      u8LocalInjCtl_tiDlyClcrlamAdapt = InjCtl_tiDlyClcrlamAdapt_C;
   }
   InjCtl_tiDlyClcrlamAdapt =
         (uint8)MATHSRV_udtMIN(u8LocalInjCtl_tiDlyClcrlamAdapt, 200);
   /*** Begin Bloc BasculeRS ***/
   if (  (bLocalOxC_bRlamAdpReq == 0)
      || (  (INJFARCTLUSCTL_bMnRnORgItrPrev != 0)
         && (bLocalOxC_bMonRunORngIntr == 0)))
   {
      VEMS_vidSET(OxC_bRlamAdaptFrz, 0);
   }
   else
   {
      s32LocalInjCtl_rlamAdaptIntery =
         (sint32)(InjCtl_rlamAdaptMv - InjCtl_rlamAdaptIntery);
      u16LocalInjCtl_rlamAdaptIntery =
         (uint16)MATHSRV_udtABS(s32LocalInjCtl_rlamAdaptIntery);
      if (  (u16LocalInjCtl_rlamAdaptIntery <= InjCtl_rlamAdaptminThd_C)
         && (InjCtl_tiDlyClcrlamAdapt == 0))
      {
         VEMS_vidSET(OxC_bRlamAdaptFrz, 1);
      }
   }
   /*** End Bloc BasculeRS ***/
   VEMS_vidGET(OxC_bRlamAdaptFrz, bLocalOxC_bRlamAdaptFrz);
   if (  (bLocalOxC_bRlamAdaptFrz != 0)
      && (bLocalOxC_bRlamAdaptFrz_Prev == 0))
   {
      VEMS_vidSET(InjCtl_rlamAdapt, InjCtl_rlamAdaptIntery);
   }
   INJFARCTLUSCTL_bLocalDetinitprev = bLocalDet_init;
   INJFARCTLUSCTL_bMnRnORgItrPrev = bLocalOxC_bMonRunORngIntr;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidAdaplambdaMean                           */
/* !Description :  Cette fonction permet de calculer la valeur moyenne du     */
/*                 correcteur de richesse de la régulation de richesse.       */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint16 Lambda_feedback_max;                                         */
/*  input sint16 Lambda_feedback_min;                                         */
/*  output sint16 InjCtl_rlamAdaptMv;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidAdaplambdaMean(void)
{
   InjCtl_rlamAdaptMv =
      (sint16)((Lambda_feedback_max + Lambda_feedback_min) / 2);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidIniAdap                                  */
/* !Description :  cette fonction permet d'initialiser les variables de       */
/*                 l'Adaptation de la correction de régulation de richesse    */
/*                 moyennée.                                                  */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean OxC_bRlamAdaptFrz;                                         */
/*  output sint16 InjCtl_rlamAdapt;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidIniAdap(void)
{
   VEMS_vidSET(OxC_bRlamAdaptFrz, 0);
   VEMS_vidSET(InjCtl_rlamAdapt, 0);
}
/*------------------------------- end of file --------------------------------*/