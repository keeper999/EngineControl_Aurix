/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2DSFONCDIAG                                     */
/* !Description     : HEATSENO2DSFONCDIAG Component                           */
/*                                                                            */
/* !Module          : HEATSENO2DSFONCDIAG                                     */
/* !Description     : DIAGNOSTIC FONCTIONNEL SONDE AVAL                       */
/*                                                                            */
/* !File            : HEATSENO2DSFONCDIAG_FCT3.C                              */
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
/*   1 / HEATSENO2DSFONCDIAG_vidDiagIntru                                     */
/*   2 / HEATSENO2DSFONCDIAG_vidDiagCount                                     */
/*   3 / HEATSENO2DSFONCDIAG_vidDsDiagOK                                      */
/*   4 / HEATSENO2DSFONCDIAG_vidItsDiaOK                                      */
/*   5 / HEATSENO2DSFONCDIAG_vidItsDiaNOK                                     */
/*   6 / HEATSENO2DSFONCDIAG_vidAcvDiag                                       */
/*   7 / HEATSENO2DSFONCDIAG_vidIntrMode6                                     */
/*   8 / HEATSENO2DSFONCDIAG_vidDiagInDon                                     */
/*   9 / HEATSENO2DSFONCDIAG_vidDiagInInh                                     */
/*                                                                            */
/* !Reference   : V02 NT 11 07942 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHI_SENO2DS/HEATSENO2DSFONCDIA$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   24 Sep 2012 $*/
/* $Author::   etsasson                               $$Date::   24 Sep 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "HEATSENO2DSFONCDIAG.h"
#include "HEATSENO2DSFONCDIAG_L.h"
#include "HEATSENO2DSFONCDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidDiagIntru                           */
/* !Description :  Lancement des fonctions de diagnostic.                     */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2DSFONCDIAG_vidDiagCount();                      */
/*  extf argret void HEATSENO2DSFONCDIAG_vidDsDiagOK();                       */
/*  extf argret void HEATSENO2DSFONCDIAG_vidItrsvFld();                       */
/*  extf argret void HEATSENO2DSFONCDIAG_vidAcvDiag();                        */
/*  extf argret void HEATSENO2DSFONCDIAG_vidItsDiaOK();                       */
/*  extf argret void HEATSENO2DSFONCDIAG_vidItsDiaNOK();                      */
/*  extf argret void HEATSENO2DSFONCDIAG_vidIntrMode6();                      */
/*  extf argret void HEATSENO2DSFONCDIAG_vidCheckrMCy();                      */
/*  extf argret void HEATSENO2DSFONCDIAG_vidtrsvCount();                      */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input st70 LsMon_stItrsvSenO2DsDiag;                                      */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint32 Objectif_richesse_global;                                    */
/*  input uint16 LsMon_uThdSenO2DsDiagFldGas_C;                               */
/*  input uint16 LsMon_uThdSenO2DsDiagFld_C;                                  */
/*  input boolean HEATSENO2DSFONCDIAG_bAcvItDsDiag;                           */
/*  input boolean LsMon_bAcvItrsvSenO2DsDiag;                                 */
/*  input boolean LsMon_bThdSenO2DsDiagFld;                                   */
/*  input uint16 LsMon_tiCfmSenO2DsDiagFld;                                   */
/*  input uint16 LsMon_tiRStrtItrsvFld;                                       */
/*  input boolean LsMon_bAcvChkRMixtItrsv_C;                                  */
/*  input boolean LsMon_bCaseItrsvSenO2DsDiag;                                */
/*  input boolean Ldsd_av_fld_failure;                                        */
/*  input boolean Ldsd_av_fld_no_failure;                                     */
/*  input uint32 LsMon_rMixtMinItrsvSenO2Ds_C;                                */
/*  output boolean LsMon_bThdSenO2DsDiagFld;                                  */
/*  output boolean HEATSENO2DSFONCDIAG_bAcvItDsDiag;                          */
/*  output boolean Ldsd_av_fld_no_failure;                                    */
/*  output boolean Ldsd_av_fld_confirm;                                       */
/*  output boolean LsMon_bItrsvSenO2DsDiagDoneFld;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidDiagIntru(void)
{
   boolean bLocalThdSenO2DsDiag;
   boolean bLocalAcvItDsDiagPrev;
   boolean bLocalLsMon_bCasItrsvSenO2DsDiag;
   boolean bLocalAcvItrsvSenO2DsDiagPrev;
   uint8   u8LocalExt_stSysGas;
   uint8   u8LocalLsMon_stItrsvSenO2DsDiag;
   uint16  u16LocalTension_sonde_aval;
   uint32  u32LocalObjectif_richesse_global;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   VEMS_vidGET(LsMon_stItrsvSenO2DsDiag, u8LocalLsMon_stItrsvSenO2DsDiag);
   VEMS_vidGET(Tension_sonde_aval, u16LocalTension_sonde_aval);
   VEMS_vidGET(Objectif_richesse_global, u32LocalObjectif_richesse_global);

   bLocalThdSenO2DsDiag = 0;
   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      if (u16LocalTension_sonde_aval > LsMon_uThdSenO2DsDiagFldGas_C)
      {
         bLocalThdSenO2DsDiag = 1;
      }
   }
   else
   {
      if (u16LocalTension_sonde_aval > LsMon_uThdSenO2DsDiagFld_C)
      {
         bLocalThdSenO2DsDiag = 1;
      }
   }
   LsMon_bThdSenO2DsDiagFld = bLocalThdSenO2DsDiag;

   HEATSENO2DSFONCDIAG_vidDiagCount();

   bLocalAcvItDsDiagPrev = HEATSENO2DSFONCDIAG_bAcvItDsDiag;
   VEMS_vidGET(LsMon_bAcvItrsvSenO2DsDiag, bLocalAcvItrsvSenO2DsDiagPrev);
   if (LsMon_bThdSenO2DsDiagFld != 0)
   {
      HEATSENO2DSFONCDIAG_vidDsDiagOK();
      HEATSENO2DSFONCDIAG_bAcvItDsDiag = 0;
   }
   else
   {
      HEATSENO2DSFONCDIAG_vidItrsvFld();
      if (  (LsMon_tiCfmSenO2DsDiagFld == 0)
         && (  (LsMon_tiRStrtItrsvFld == 0)
            || (LsMon_bAcvChkRMixtItrsv_C == 0)))
      {
         HEATSENO2DSFONCDIAG_bAcvItDsDiag = 1;
         if (bLocalAcvItDsDiagPrev == 0)
         {
            HEATSENO2DSFONCDIAG_vidAcvDiag();
         }
      }
      else
      {
         HEATSENO2DSFONCDIAG_bAcvItDsDiag = 0;
      }
   }

   VEMS_vidGET(LsMon_bCaseItrsvSenO2DsDiag, bLocalLsMon_bCasItrsvSenO2DsDiag);

   if (  (u8LocalLsMon_stItrsvSenO2DsDiag == LSMON_ITRSV_SENO2DS_DIAG_OK)
      && (bLocalLsMon_bCasItrsvSenO2DsDiag != 0))
   {
      HEATSENO2DSFONCDIAG_vidItsDiaOK();
   }
   else
   {
      Ldsd_av_fld_no_failure = 0;
      if (  (u8LocalLsMon_stItrsvSenO2DsDiag == LSMON_ITRSV_SENO2DS_DIAG_NOK)
         && (bLocalLsMon_bCasItrsvSenO2DsDiag != 0))
      {
         HEATSENO2DSFONCDIAG_vidItsDiaNOK();
      }
   }
   if (  (LsMon_bThdSenO2DsDiagFld != 0)
      || (Ldsd_av_fld_failure != 0)
      || (Ldsd_av_fld_no_failure != 0))
   {
      Ldsd_av_fld_confirm = 1;
      HEATSENO2DSFONCDIAG_vidIntrMode6();
   }
   else
   {
      Ldsd_av_fld_confirm = 0;
   }
   if (  (bLocalAcvItrsvSenO2DsDiagPrev != 0)
      && (LsMon_bAcvChkRMixtItrsv_C != 0)
      && (u32LocalObjectif_richesse_global < LsMon_rMixtMinItrsvSenO2Ds_C))
   {
      HEATSENO2DSFONCDIAG_vidCheckrMCy();
   }
   if (LsMon_bAcvChkRMixtItrsv_C != 0)
   {
      HEATSENO2DSFONCDIAG_vidtrsvCount();
   }
   LsMon_bItrsvSenO2DsDiagDoneFld = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidDiagCount                           */
/* !Description :  Fonction de calcul de temporisation de confirmation du     */
/*                 seuil minimum atteint.                                     */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean LsMon_bThdSenO2DsDiagFld;                                   */
/*  input uint16 LsMon_tiCfmSenO2DsDiagFld_C;                                 */
/*  input uint16 LsMon_tiCfmSenO2DsDiagFld;                                   */
/*  output uint16 LsMon_tiCfmSenO2DsDiagFld;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidDiagCount(void)
{
   sint32  s32LocalStep;


   if (LsMon_bThdSenO2DsDiagFld != 0)
   {
      LsMon_tiCfmSenO2DsDiagFld = LsMon_tiCfmSenO2DsDiagFld_C;
   }
   else
   {
      s32LocalStep = (sint32)(LsMon_tiCfmSenO2DsDiagFld - 1);
      LsMon_tiCfmSenO2DsDiagFld = (uint16)MATHSRV_udtMAX(s32LocalStep, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidDsDiagOK                            */
/* !Description :  Fonction de calcul résultat du diagnostic sonde aval       */
/*                 bloquée pauvre                                             */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Ldsd_av_fld_failure;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidDsDiagOK(void)
{
   Ldsd_av_fld_failure = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidItsDiaOK                            */
/* !Description :  Demande diagnostic intrusif pour la sonde aval .           */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean LsMon_bAcvItrsvSenO2DsDiag;                                */
/*  output boolean Ldsd_av_fld_failure;                                       */
/*  output boolean Ldsd_av_fld_no_failure;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidItsDiaOK(void)
{
   VEMS_vidSET(LsMon_bAcvItrsvSenO2DsDiag, 0);
   Ldsd_av_fld_failure = 0;
   Ldsd_av_fld_no_failure = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidItsDiaNOK                           */
/* !Description :  Demande diagnostic intrusif pour la sonde aval             */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean LsMon_bAcvItrsvSenO2DsDiag;                                */
/*  output boolean Ldsd_av_fld_failure;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidItsDiaNOK(void)
{
   VEMS_vidSET(LsMon_bAcvItrsvSenO2DsDiag, 0);
   Ldsd_av_fld_failure = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidAcvDiag                             */
/* !Description :  Demande diagnostic intrusif pour la sonde aval             */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean LsMon_bAcvItrsvSenO2DsDiag;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidAcvDiag(void)
{
   VEMS_vidSET(LsMon_bAcvItrsvSenO2DsDiag, 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidIntrMode6                           */
/* !Description :  Fonction de renvoie de valeur minimale au mode $06 du      */
/*                 scantool .                                                 */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 LsMon_uThdSenO2DsDiagFldGas_C;                               */
/*  input uint16 LsMon_uThdSenO2DsDiagFld_C;                                  */
/*  output uint16 SenO2Ds_FldPlausFacMesRaw;                                  */
/*  output uint16 SenO2Ds_FldPlausFacMinRaw;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidIntrMode6(void)
{
   uint8   u8LocalExt_stSysGas;
   uint16  u16LocalTension_sonde_aval;


   VEMS_vidGET(Tension_sonde_aval, u16LocalTension_sonde_aval);
   SenO2Ds_FldPlausFacMesRaw =
      (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_aval, 1024);

   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      SenO2Ds_FldPlausFacMinRaw =
         (uint16)MATHSRV_udtMIN(LsMon_uThdSenO2DsDiagFldGas_C, 1024);
   }
   else
   {
      SenO2Ds_FldPlausFacMinRaw =
         (uint16)MATHSRV_udtMIN(LsMon_uThdSenO2DsDiagFld_C, 1024);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidDiagInDon                           */
/* !Description :  Mise de LsMon_bItrsvSenO2DsDiagDone à 1                    */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean LsMon_bItrsvSenO2DsDiagDoneFld;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidDiagInDon(void)
{
   LsMon_bItrsvSenO2DsDiagDoneFld = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidDiagInInh                           */
/* !Description :  Mise de LsMon_bAcvItrsvSenO2DsDiag à 0                     */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 LsMon_tiCfmSenO2DsDiagFld_C;                                 */
/*  output boolean LsMon_bAcvItrsvSenO2DsDiag;                                */
/*  output uint16 LsMon_tiCfmSenO2DsDiagFld;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidDiagInInh(void)
{
   VEMS_vidSET(LsMon_bAcvItrsvSenO2DsDiag, 0);
   LsMon_tiCfmSenO2DsDiagFld = LsMon_tiCfmSenO2DsDiagFld_C;
}
/*---------------------------- end of file -----------------------------------*/