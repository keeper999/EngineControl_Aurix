/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CSTRMGR                                                 */
/* !Description     : CSTRMGR Component                                       */
/*                                                                            */
/* !Module          : CSTRMGR                                                 */
/* !Description     : Calcul de la consigne d_ouverture de la purge.          */
/*                                                                            */
/* !File            : CSTRMGR_FCT1.C                                          */
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
/*   1 / CSTRMGR_vidInitOutput                                                */
/*   2 / CSTRMGR_vidInit                                                      */
/*   3 / CSTRMGR_vidMgr                                                       */
/*   4 / CSTRMGR_vidPurgeNormalMod                                            */
/*   5 / CSTRMGR_vidCalcRcoDemandPurge                                        */
/*   6 / CSTRMGR_vidPurgeBenchMod                                             */
/*   7 / CSTRMGR_vidConsolidation                                             */
/*   8 / CSTRMGR_vidCalcRcoPurgeApplique                                      */
/*   9 / CSTRMGR_vidOutputInterface                                           */
/*                                                                            */
/* !Reference   : V02 NT 09 01858 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CSTR/CSTRMGR/CSTRMGR_FCT1.C_v     $*/
/* $Revision::   1.3      $$Author::   achebino       $$Date::   19 Dec 2012 $*/
/* $Author::   achebino                               $$Date::   19 Dec 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "CSTRMGR.H"
#include "CSTRMGR_L.H"
#include "CSTRMGR_IM.H"
#include "MATHSRV.H"
#include "GDGAR.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRMGR_vidInitOutput                                      */
/* !Description :  Fonction d'initialisation.                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mariem BOUATTOUR                                           */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output st66 Cpc_purge_control_state;                                      */
/*  output boolean OxC_bMonIntrPurgeCdn;                                      */
/*  output boolean Demande_purge_dormant_nom;                                 */
/*  output uint8 Rco_demande_purge_nom;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRMGR_vidInitOutput(void)
{
   VEMS_vidSET(Cpc_purge_control_state, CPC_PURGE_CLOSED);
   VEMS_vidSET(OxC_bMonIntrPurgeCdn, 1);
   Demande_purge_dormant_nom = 1;
   Rco_demande_purge_nom = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRMGR_vidInit                                            */
/* !Description :  Fonction d'initialisation au Reset                         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mariem BOUATTOUR                                           */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Demande_purge_dormant;                                     */
/*  output uint8 Rco_applique_purge;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRMGR_vidInit(void)
{
   VEMS_vidSET(Demande_purge_dormant, 1);
   VEMS_vidSET(Rco_applique_purge, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRMGR_vidMgr                                             */
/* !Description :  Fonction du manager de la gestion de la purge              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mariem BOUATTOUR                                           */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CSTRMGR_vidPurgeNormalMod();                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CSTRMGR_vidPurgeBenchMod();                              */
/*  extf argret void CSTRMGR_vidCalcRcoDemandPurge();                         */
/*  extf argret void CSTRMGR_vidConsolidation();                              */
/*  input st66 Cpc_purge_control_state;                                       */
/*  input boolean Purge_test_banc;                                            */
/*  input boolean CSTRMGR_cdn_rco_ctld;                                       */
/*  output boolean CSTRMGR_cdn_rco_ctld;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRMGR_vidMgr(void)
{
   uint8 u8LocalCpcPurgeControlState;


   CSTRMGR_vidPurgeNormalMod();
   VEMS_vidGET(Cpc_purge_control_state, u8LocalCpcPurgeControlState);
   if (  (u8LocalCpcPurgeControlState == CPC_NORMAL_BOUNDING)
      || (u8LocalCpcPurgeControlState == CPC_PURGE_HOLDING)
      || (u8LocalCpcPurgeControlState == CPC_LAMBDA_PURGE_CLOSING)
      || (u8LocalCpcPurgeControlState == CPC_GSM_PURGE_CLOSING))
   {
      CSTRMGR_cdn_rco_ctld = 1;
   }
   else
   {
      CSTRMGR_cdn_rco_ctld = 0;
   }
   if (Purge_test_banc != 0)
   {
      CSTRMGR_vidPurgeBenchMod();
   }
   else
   {
      if (CSTRMGR_cdn_rco_ctld != 0)
      {
         CSTRMGR_vidCalcRcoDemandPurge();
      }
   }
   CSTRMGR_vidConsolidation();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRMGR_vidPurgeNormalMod                                  */
/* !Description :  Fonction de gestion de la purge en mode normal             */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mariem BOUATTOUR                                           */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CSTRMGR_vidPurgeControlState();                          */
/*  input uint8 Coupure_decel_progr_inj;                                      */
/*  output boolean CSTRMGR_open_loop_min_purge_req;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRMGR_vidPurgeNormalMod(void)
{
   boolean bLocalInhInjFarCtlMgrLbdFb;
   uint8   u8LocalCoupure_decel_progr_inj;


   bLocalInhInjFarCtlMgrLbdFb = GDGAR_bGetFRM(FRM_FRM_INHINJFARCTLMGRLBDFB);
   VEMS_vidGET(Coupure_decel_progr_inj, u8LocalCoupure_decel_progr_inj);
   if (  (bLocalInhInjFarCtlMgrLbdFb != 0)
      || ( (u8LocalCoupure_decel_progr_inj & 0x01) == 0x01)
      || ( (u8LocalCoupure_decel_progr_inj & 0x02) == 0x02)
      || ( (u8LocalCoupure_decel_progr_inj & 0x04) == 0x04)
      || ( (u8LocalCoupure_decel_progr_inj & 0x08) == 0x08))
   {
      CSTRMGR_open_loop_min_purge_req = 1;
   }
   else
   {
      CSTRMGR_open_loop_min_purge_req = 0;
   }

   CSTRMGR_vidPurgeControlState();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRMGR_vidCalcRcoDemandPurge                              */
/* !Description :  Fonction de calcul du RCO de commande d'ouverture de la    */
/*                 purge en mode controlé.                                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mariem BOUATTOUR                                           */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st66 Cpc_purge_control_state;                                       */
/*  input uint16 Cpc_control_purge_ratio;                                     */
/*  input uint16 Cpc_constraints_max_purge_ratio;                             */
/*  input uint16 InM_arEffAdpThr;                                             */
/*  input uint8 InM_facCfeCanPurgCor;                                         */
/*  input uint16 Cpc_effective_area_map[11];                                  */
/*  input uint16 CSTRMGR_u16EffectiveArea;                                    */
/*  input uint8 Cpc_purge_dc_map[11];                                         */
/*  output uint16 CSTRMGR_u16EffectiveArea;                                   */
/*  output uint8 Rco_demande_purge_ctld;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRMGR_vidCalcRcoDemandPurge(void)
{
   uint8  u8LocalInM_facCfeCanPurgCor;
   uint8  u8LocalCpc_purge_control_state;
   uint16 u16LocalCpc_purge_ratio;
   uint16 u16LocalInM_arEffAdpThr;
   uint16 u16LocalAreaDenum;
   uint16 u16LocalCalcPara;
   uint32 u32LocalAreaNum;
   uint32 u32LocalArea;


   VEMS_vidGET(Cpc_purge_control_state, u8LocalCpc_purge_control_state);
   if (  (u8LocalCpc_purge_control_state == CPC_PURGE_HOLDING)
      || (u8LocalCpc_purge_control_state == CPC_LAMBDA_PURGE_CLOSING))
   {
      u16LocalCpc_purge_ratio = Cpc_control_purge_ratio;
   }
   else
   {
      VEMS_vidGET(Cpc_constraints_max_purge_ratio, u16LocalCpc_purge_ratio);
   }

   VEMS_vidGET(InM_arEffAdpThr, u16LocalInM_arEffAdpThr);
   VEMS_vidGET(InM_facCfeCanPurgCor, u8LocalInM_facCfeCanPurgCor);

   u32LocalAreaNum =
      (uint32)(u16LocalInM_arEffAdpThr * u16LocalCpc_purge_ratio);
   u16LocalAreaDenum = (uint16)(u8LocalInM_facCfeCanPurgCor + 256);
   u16LocalAreaDenum = (uint16)(u16LocalAreaDenum * 64);
   u32LocalArea = (u32LocalAreaNum / u16LocalAreaDenum);
   CSTRMGR_u16EffectiveArea = (uint16)MATHSRV_udtMIN(u32LocalArea, 65535);

   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(Cpc_effective_area_map,
                                          CSTRMGR_u16EffectiveArea,
                                          11);
   Rco_demande_purge_ctld = MATHSRV_u8Interp1d(Cpc_purge_dc_map,
                                               u16LocalCalcPara);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRMGR_vidPurgeBenchMod                                   */
/* !Description :  Fonction de la gestion de la purge en mode banc            */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Mariem BOUATTOUR                                           */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Cpc_test_bed_purge_rco;                                       */
/*  output boolean Demande_purge_dormant_banc;                                */
/*  output uint8 Rco_demande_purge_banc;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRMGR_vidPurgeBenchMod(void)
{
   Demande_purge_dormant_banc = 0;
   Rco_demande_purge_banc = Cpc_test_bed_purge_rco;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRMGR_vidConsolidation                                   */
/* !Description :  Fonction de consolidation de la commande de la purge       */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Mariem BOUATTOUR                                           */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Purge_test_banc;                                            */
/*  input uint8 Rco_demande_purge_banc;                                       */
/*  input boolean Demande_purge_dormant_banc;                                 */
/*  input boolean CSTRMGR_cdn_rco_ctld;                                       */
/*  input uint8 Rco_demande_purge_ctld;                                       */
/*  input uint8 Rco_demande_purge_nom;                                        */
/*  input boolean Demande_purge_dormant_nom;                                  */
/*  output uint8 Rco_demande_purge;                                           */
/*  output uint8 Rco_demande_purge_banc;                                      */
/*  output boolean Demande_purge_dormant_raw;                                 */
/*  output uint8 Rco_demande_purge_ctld;                                      */
/*  output uint8 Rco_demande_purge_nom;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRMGR_vidConsolidation(void)
{
   if (Purge_test_banc != 0)
   {
      VEMS_vidSET(Rco_demande_purge, Rco_demande_purge_banc);
      Demande_purge_dormant_raw = Demande_purge_dormant_banc;
   }
   else
   {
      if (CSTRMGR_cdn_rco_ctld != 0)
      {
         VEMS_vidSET(Rco_demande_purge, Rco_demande_purge_ctld);
      }
      else
      {
         VEMS_vidSET(Rco_demande_purge, Rco_demande_purge_nom);
      }
      Demande_purge_dormant_raw = Demande_purge_dormant_nom;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRMGR_vidCalcRcoPurgeApplique                            */
/* !Description :  Fonction de calcul de la requête de RCO effectivement      */
/*                 transmise au driver                                        */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Mariem BOUATTOUR                                           */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Cstr_bPwrRlyCmd;                                            */
/*  input uint8 Cstr_rSpPosnActrTst;                                          */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean Demande_purge_dormant_raw;                                  */
/*  input uint8 Rco_demande_purge;                                            */
/*  output uint8 Rco_applique_purge;                                          */
/*  output boolean Demande_purge_dormant;                                     */
/*  output boolean Demande_purge_dormant_raw;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRMGR_vidCalcRcoPurgeApplique(void)
{
   boolean bLocalCstr_bPwrRlyCmd;
   boolean bLocalClef_de_contact;
   uint8   u8LocalCstr_rSpPosnActrTst;
   uint8   u8LocalRco_demande_purge;


   VEMS_vidGET(Cstr_bPwrRlyCmd, bLocalCstr_bPwrRlyCmd);
   if (bLocalCstr_bPwrRlyCmd != 0)
   {
      VEMS_vidGET(Cstr_rSpPosnActrTst, u8LocalCstr_rSpPosnActrTst);
      VEMS_vidSET(Rco_applique_purge, u8LocalCstr_rSpPosnActrTst);

      if (u8LocalCstr_rSpPosnActrTst == 0)
      {
         VEMS_vidSET(Demande_purge_dormant, 1);
      }
      else
      {
         VEMS_vidSET(Demande_purge_dormant, 0);
      }
   }
   else
   {
      VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
      if (  (bLocalClef_de_contact != 0)
         && (Demande_purge_dormant_raw == 0))
      {
         VEMS_vidGET(Rco_demande_purge, u8LocalRco_demande_purge);
         VEMS_vidSET(Rco_applique_purge, u8LocalRco_demande_purge);
      }
      else
      {
         VEMS_vidSET(Rco_applique_purge, 0);
      }
      VEMS_vidSET(Demande_purge_dormant, Demande_purge_dormant_raw);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRMGR_vidOutputInterface                                 */
/* !Description :  Fonction de production de l'indicateur de demande de       */
/*                 fermeture de la purge                                      */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Mariem BOUATTOUR                                           */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Rco_applique_purge;                                           */
/*  input boolean Demande_purge_dormant;                                      */
/*  output uint8 CanPurg_rOpCanPurgReq;                                       */
/*  output boolean CanPurg_bAcvClsPurgReq;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRMGR_vidOutputInterface(void)
{
   boolean bLocalDemande_purge_dormant;
   uint8   u8LocalRco_applique_purge;


   VEMS_vidGET(Rco_applique_purge, u8LocalRco_applique_purge);
   VEMS_vidSET(CanPurg_rOpCanPurgReq, u8LocalRco_applique_purge);

   VEMS_vidGET(Demande_purge_dormant, bLocalDemande_purge_dormant);
   VEMS_vidSET(CanPurg_bAcvClsPurgReq, bLocalDemande_purge_dormant);
}
/*------------------------------- end of file --------------------------------*/