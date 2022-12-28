/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FARSTRAMON                                              */
/* !Description     : FARSTRAMON component                                    */
/*                                                                            */
/* !Module          : FARSTRAMON                                              */
/* !Description     : Superviseur de stratégies liées à la Richesse           */
/*                                                                            */
/* !File            : FARSTRAMON_FCT2.C                                       */
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
/*   1 / FARSTRAMON_vidEnableManagement                                       */
/*   2 / FARSTRAMON_vidIninTmrEnaPurgEng                                      */
/*   3 / FARSTRAMON_vidTmrEnaPurgEng                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5147156 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/INJCTLSYS/FARSTRAMON/FARSTRAMON_$*/
/* $Revision::   1.5      $$Author::   HHAMLAOU       $$Date::   20 Aug 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   20 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "FARSTRAMON.h"
#include "FARSTRAMON_L.h"
#include "FARSTRAMON_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FARSTRAMON_vidEnableManagement                             */
/* !Description :  Fonction qui gere les Les requêtes des diagnostics  et     */
/*                 d’adaptation d’air/essence. Il sont gérées par priorité à  */
/*                 condition qu’il n’y ait plus d’effets issus  de la purge   */
/*                 canister, d’EGR ou d’apprentissage de taux d’alcool(       */
/*                 FlexFuel)..                                                */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_00524_005.01                                     */
/*                 VEMS_R_10_00524_006.01                                     */
/*                 VEMS_R_10_00524_007.01                                     */
/*                 VEMS_R_10_00524_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Flex_alc_rate_est_needed_uavb0;                             */
/*  input boolean Flex_alc_rate_diag_run_uavb0;                               */
/*  input boolean Saf_diag_request;                                           */
/*  input boolean Lambda_for_saf_diag_active;                                 */
/*  input boolean OxC_bAcvPrioMgt;                                            */
/*  input boolean OxC_bMonORngIntrAcvCdn;                                     */
/*  input uint16 CanPurg_concFuStmEstim;                                      */
/*  input boolean Lfbk_mon_diag_test_enable;                                  */
/*  input boolean Gsm_saf_diag_enable;                                        */
/*  input boolean GSM_bAcvAFAAdp;                                             */
/*  input boolean Lambda_for_saf_diag_request;                                */
/*  input boolean FARSTRAMON_bCounter_On_Off;                                 */
/*  input uint8 StraMon_tiDlyAftDiagItrsv;                                    */
/*  input uint8 StraMon_tiDlyAftDiagItrsv_C;                                  */
/*  input uint16 StraMon_concFuStmEstimThd_C;                                 */
/*  input boolean Gsm_cpc_no_effect;                                          */
/*  input boolean Gsm_egr_no_effect;                                          */
/*  input boolean Lfbk_mon_diag_test_request;                                 */
/*  input boolean AFAMgt_bAuthAdpReq;                                         */
/*  input boolean EngReqH_bInhLrnAFA;                                         */
/*  input boolean Flev_low_fuel_level;                                        */
/*  input boolean GSM_Misf_OBD_fail;                                          */
/*  output uint8 StraMon_tiDlyAftDiagItrsv;                                   */
/*  output boolean FARSTRAMON_bCounter_On_Off;                                */
/*  output boolean OxC_bAcvPrioMgt;                                           */
/*  output boolean Lambda_for_saf_diag_request;                               */
/*  output boolean GSM_bAcvAFAAdp;                                            */
/*  output boolean Lfbk_mon_diag_test_enable;                                 */
/*  output boolean Gsm_saf_diag_enable;                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FARSTRAMON_vidEnableManagement(void)
{
   boolean bLocalSaf_diag_request;
   boolean bLocalLfbk_mon_diag_test_request;
   boolean bLocalLambda_for_saf_diag_active;
   boolean bLocalFlexAlcRateEstNeededUavb0;
   boolean bLocalFlexAlcRateDiagRun_uavb0;
   boolean bLocalAFAMgt_bAuthAdpReq;
   boolean bLocalEngReqH_bInhLrnAFA;
   boolean bLocalFlev_low_fuel_level;
   boolean bLocalOxC_bAcvPrioMgt;
   boolean bLocalOxC_bMonORngItrsvAcvCdn;
   boolean bLocalLfbk_mon_diag_test_enable;
   boolean bLocalGsm_saf_diag_enable;
   boolean bLocalGSM_bAcvAFAAdp;
   boolean bLocalLambda_for_safdiag_request;
   uint8   u8LocalCount;
   uint16  u16LocalCanPurg_concFuStmEstim;


   VEMS_vidGET(Flex_alc_rate_est_needed_uavb0, bLocalFlexAlcRateEstNeededUavb0);
   VEMS_vidGET(Flex_alc_rate_diag_run_uavb0, bLocalFlexAlcRateDiagRun_uavb0);
   VEMS_vidGET(Saf_diag_request, bLocalSaf_diag_request);
   VEMS_vidGET(Lambda_for_saf_diag_active, bLocalLambda_for_saf_diag_active);
   VEMS_vidGET(OxC_bAcvPrioMgt, bLocalOxC_bAcvPrioMgt);
   VEMS_vidGET(OxC_bMonORngIntrAcvCdn, bLocalOxC_bMonORngItrsvAcvCdn);
   VEMS_vidGET(CanPurg_concFuStmEstim, u16LocalCanPurg_concFuStmEstim);
   VEMS_vidGET(Lfbk_mon_diag_test_enable, bLocalLfbk_mon_diag_test_enable);
   VEMS_vidGET(Gsm_saf_diag_enable, bLocalGsm_saf_diag_enable);
   VEMS_vidGET(GSM_bAcvAFAAdp, bLocalGSM_bAcvAFAAdp);
   VEMS_vidGET(Lambda_for_saf_diag_request, bLocalLambda_for_safdiag_request);

   if (FARSTRAMON_bCounter_On_Off != 0)
   {
      if (StraMon_tiDlyAftDiagItrsv != 0)
      {
         /*Counter_DiagItrsv_on_to_off */
         u8LocalCount = (uint8)(StraMon_tiDlyAftDiagItrsv - 1);
         StraMon_tiDlyAftDiagItrsv = (uint8)MATHSRV_udtMIN(u8LocalCount ,50);
      }
      else
      {
         /*DiagItrsv_off */
         FARSTRAMON_bCounter_On_Off = 0;
         VEMS_vidSET(OxC_bAcvPrioMgt, 0);
         StraMon_tiDlyAftDiagItrsv =
            (uint8)MATHSRV_udtMIN(StraMon_tiDlyAftDiagItrsv_C, 50);
      }
   }
   else
   {
      if (  (bLocalOxC_bMonORngItrsvAcvCdn != 0)
         && (u16LocalCanPurg_concFuStmEstim <= StraMon_concFuStmEstimThd_C)
         && (bLocalLfbk_mon_diag_test_enable == 0)
         && (bLocalGsm_saf_diag_enable == 0)
         && (bLocalGSM_bAcvAFAAdp == 0)
         && (bLocalLambda_for_safdiag_request == 0))
      {
         /*DiagItrsv_on */
         VEMS_vidSET(OxC_bAcvPrioMgt, 1);
      }
      else
      {
         if (bLocalOxC_bAcvPrioMgt != 0)
         {
            if (bLocalOxC_bMonORngItrsvAcvCdn == 0)
            {
               /*Counter_DiagItrsv_on_to_off */
               FARSTRAMON_bCounter_On_Off = 1;
            }
         }
         else
         {
            if (bLocalSaf_diag_request != 0)
            {
               VEMS_vidSET(Lambda_for_saf_diag_request, 1);
               VEMS_vidSET(GSM_bAcvAFAAdp, 0);
               VEMS_vidSET(Lfbk_mon_diag_test_enable, 0);
               if (  (bLocalLambda_for_saf_diag_active != 0)
                  && (Gsm_cpc_no_effect != 0)
                  && (Gsm_egr_no_effect != 0)
                  && (bLocalFlexAlcRateEstNeededUavb0 == 0)
                  && (bLocalFlexAlcRateDiagRun_uavb0 == 0))
               {
                  /*Saf_diag_on */
                  VEMS_vidSET(Gsm_saf_diag_enable, 1);
               }
               else
               {
                  /*Saf_diag_off */
                  VEMS_vidSET(Gsm_saf_diag_enable, 0);
               }
            }
            else
            {
               VEMS_vidSET(Lambda_for_saf_diag_request, 0);
               VEMS_vidSET(Gsm_saf_diag_enable, 0);
               VEMS_vidGET(Lfbk_mon_diag_test_request,
                           bLocalLfbk_mon_diag_test_request);
               if (bLocalLfbk_mon_diag_test_request != 0)
               {
                  VEMS_vidSET(GSM_bAcvAFAAdp, 0);
                  if(  (Gsm_cpc_no_effect != 0)
                    && (Gsm_egr_no_effect != 0)
                    && (bLocalFlexAlcRateEstNeededUavb0 == 0)
                    && (bLocalFlexAlcRateDiagRun_uavb0 == 0))
                  {
                     /*Lfbk_mon_diag_test_on */
                     VEMS_vidSET(Lfbk_mon_diag_test_enable, 1);
                  }
                  else
                  {
                     /*Lfbk_mon_diag_test_off*/
                     VEMS_vidSET(Lfbk_mon_diag_test_enable, 0);
                  }
               }
               else
               {
                  VEMS_vidSET(Lfbk_mon_diag_test_enable, 0);
                  VEMS_vidGET(AFAMgt_bAuthAdpReq, bLocalAFAMgt_bAuthAdpReq);
                  VEMS_vidGET(EngReqH_bInhLrnAFA, bLocalEngReqH_bInhLrnAFA);
                  VEMS_vidGET(Flev_low_fuel_level, bLocalFlev_low_fuel_level);
                  if (  (bLocalAFAMgt_bAuthAdpReq != 0)
                     && (bLocalEngReqH_bInhLrnAFA == 0)
                     && (Gsm_cpc_no_effect != 0)
                     && (bLocalFlexAlcRateEstNeededUavb0 == 0)
                     && (bLocalFlexAlcRateDiagRun_uavb0 == 0)
                     && (bLocalFlev_low_fuel_level == 0)
                     && (GSM_Misf_OBD_fail == 0))
                  {
                     /*Adaptation_on*/
                     VEMS_vidSET(GSM_bAcvAFAAdp, 1);
                  }
                  else
                  {
                     /*End_test */
                     VEMS_vidSET(GSM_bAcvAFAAdp, 0);
                  }
               }
            }
         }
      }
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FARSTRAMON_vidIninTmrEnaPurgEng                            */
/* !Description :  Cette fonction initialise le delai d'autorisation de la    */
/*                 purge canister sur démarrage/redémarrage.                  */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_00524_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoPTSt_bRStrtSTT;                                           */
/*  input uint8 Cstr_TiEnaPurgEngRstrtSTT_C;                                  */
/*  input uint8 Cstr_TiEnaPurgEngStrt_C;                                      */
/*  output boolean Cstr_bEnaPurgEngStrtRstrt;                                 */
/*  output uint8 Cstr_ctTiEnaPurgEng;                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FARSTRAMON_vidIninTmrEnaPurgEng(void)
{
   boolean bLocalCoPTSt_bRStrtSTT;
   uint8   u8LocalCstrCtTiEnaPurgEng;


   Cstr_bEnaPurgEngStrtRstrt = 0;
   VEMS_vidGET(CoPTSt_bRStrtSTT, bLocalCoPTSt_bRStrtSTT);
   if (bLocalCoPTSt_bRStrtSTT != 0)
   {
      u8LocalCstrCtTiEnaPurgEng = Cstr_TiEnaPurgEngRstrtSTT_C;
   }
   else
   {
      u8LocalCstrCtTiEnaPurgEng = Cstr_TiEnaPurgEngStrt_C;
   }
   Cstr_ctTiEnaPurgEng = (uint8)MATHSRV_udtMIN(u8LocalCstrCtTiEnaPurgEng, 50);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FARSTRAMON_vidTmrEnaPurgEng                                */
/* !Description :  Cette fonction calcule le delai d'autorisation de la purge */
/*                 canister sur démarrage/redémarrage                         */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_00524_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Cstr_ctTiEnaPurgEng;                                          */
/*  input boolean Moteur_tournant;                                            */
/*  input uint8 Cstr_ctTiEnaPurgEngPrev;                                      */
/*  output uint8 Cstr_ctTiEnaPurgEngPrev;                                     */
/*  output uint8 Cstr_ctTiEnaPurgEng;                                         */
/*  output boolean Cstr_bEnaPurgEngStrtRstrt;                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FARSTRAMON_vidTmrEnaPurgEng(void)
{
   boolean bLocalMoteur_tournant;
   sint16  s16LocalCounter;


   Cstr_ctTiEnaPurgEngPrev = Cstr_ctTiEnaPurgEng;
   VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);
   if (bLocalMoteur_tournant != 0)
   {
      s16LocalCounter = (sint16)(Cstr_ctTiEnaPurgEngPrev - 1);
      Cstr_ctTiEnaPurgEng = (uint8)MATHSRV_udtCLAMP(s16LocalCounter, 0, 50);
      if (Cstr_ctTiEnaPurgEng != 0)
      {
         Cstr_bEnaPurgEngStrtRstrt = 0;
      }
      else
      {
         Cstr_bEnaPurgEngStrtRstrt = 1;
      }
   }
}
/*------------------------------- end of file --------------------------------*/