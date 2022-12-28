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
/* !File            : HEATSENO2DSFONCDIAG_FCT4.C                              */
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
/*   1 / HEATSENO2DSFONCDIAG_vidDgIntrBva                                     */
/*   2 / HEATSENO2DSFONCDIAG_vidDgCntBva                                      */
/*   3 / HEATSENO2DSFONCDIAG_vidDsDgOKBva                                     */
/*   4 / HEATSENO2DSFONCDIAG_vidIsDgOKBva                                     */
/*   5 / HEATSENO2DSFONCDIAG_vidIsDgNOKBv                                     */
/*   6 / HEATSENO2DSFONCDIAG_vidAcvDgBva                                      */
/*   7 / HEATSENO2DSFONCDIAG_vidInMod6Bva                                     */
/*   8 / HEATSENO2DSFONCDIAG_vidDgInDnBva                                     */
/*   9 / HEATSENO2DSFONCDIAG_vidItrsvFld                                      */
/*   10 / HEATSENO2DSFONCDIAG_vidItrsvFco                                     */
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
/* !Function    :  HEATSENO2DSFONCDIAG_vidDgIntrBva                           */
/* !Description :  Ce bloc correspond à la mise à jour du diagnostic « Sonde  */
/*                 aval bloquée riche », pour l’application Euro 5+ avec IUPR.*/
/* !Number      :  FCT4.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2DSFONCDIAG_vidDgCntBva();                       */
/*  extf argret void HEATSENO2DSFONCDIAG_vidDsDgOKBva();                      */
/*  extf argret void HEATSENO2DSFONCDIAG_vidItrsvFco();                       */
/*  extf argret void HEATSENO2DSFONCDIAG_vidAcvDgBva();                       */
/*  extf argret void HEATSENO2DSFONCDIAG_vidIsDgOKBva();                      */
/*  extf argret void HEATSENO2DSFONCDIAG_vidIsDgNOKBv();                      */
/*  extf argret void HEATSENO2DSFONCDIAG_vidInMod6Bva();                      */
/*  extf argret void HEATSENO2DSFONCDIAG_vidChMCyBva();                       */
/*  extf argret void HEATSENO2DSFONCDIAG_vidtrsvCtBva();                      */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input st70 LsMon_stItrsvSenO2DsDiag;                                      */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint32 Objectif_richesse_global;                                    */
/*  input uint16 LsMon_uThdSenO2DsDiagFcoGas_C;                               */
/*  input uint16 LsMon_uThdSenO2DsDiagFco_C;                                  */
/*  input boolean HEATSENO2DSFONCDIAG_bAvItDsDgBva;                           */
/*  input boolean LsMon_bAcvItrsvSenO2DsDiag;                                 */
/*  input boolean LsMon_bThdSenO2DsDiagFco;                                   */
/*  input uint16 LsMon_tiCfmSenO2DsDiagFco;                                   */
/*  input uint16 LsMon_tiRStrtItrsvFco;                                       */
/*  input boolean LsMon_bAcvChkRMixtItrsv_C;                                  */
/*  input boolean LsMon_bCaseItrsvSenO2DsDiag;                                */
/*  input boolean SenO2Ds_bDgoORng_DsPlausFco;                                */
/*  input boolean Ldsd_av_fco_no_failure;                                     */
/*  input uint32 LsMon_rMixtMaxItrsvSenO2Ds_C;                                */
/*  output boolean LsMon_bThdSenO2DsDiagFco;                                  */
/*  output boolean HEATSENO2DSFONCDIAG_bAvItDsDgBva;                          */
/*  output boolean Ldsd_av_fco_no_failure;                                    */
/*  output boolean SenO2Ds_bMonWaitRaw_DsPlausFco;                            */
/*  output boolean LsMon_bItrsvSenO2DsDiagDoneFco;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidDgIntrBva(void)
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
      if (u16LocalTension_sonde_aval <= LsMon_uThdSenO2DsDiagFcoGas_C)
      {
         bLocalThdSenO2DsDiag = 1;
      }
   }
   else
   {
      if (u16LocalTension_sonde_aval <= LsMon_uThdSenO2DsDiagFco_C)
      {
         bLocalThdSenO2DsDiag = 1;
      }
   }
   LsMon_bThdSenO2DsDiagFco = bLocalThdSenO2DsDiag;

   HEATSENO2DSFONCDIAG_vidDgCntBva();

   bLocalAcvItDsDiagPrev = HEATSENO2DSFONCDIAG_bAvItDsDgBva;
   VEMS_vidGET(LsMon_bAcvItrsvSenO2DsDiag, bLocalAcvItrsvSenO2DsDiagPrev);
   if (LsMon_bThdSenO2DsDiagFco != 0)
   {
      HEATSENO2DSFONCDIAG_vidDsDgOKBva();
      HEATSENO2DSFONCDIAG_bAvItDsDgBva = 0;
   }
   else
   {
      HEATSENO2DSFONCDIAG_vidItrsvFco();
      if (  (LsMon_tiCfmSenO2DsDiagFco == 0)
         && (  (LsMon_tiRStrtItrsvFco == 0)
            || (LsMon_bAcvChkRMixtItrsv_C == 0)))
      {
         HEATSENO2DSFONCDIAG_bAvItDsDgBva = 1;
         if (bLocalAcvItDsDiagPrev == 0)
         {
            HEATSENO2DSFONCDIAG_vidAcvDgBva();
         }
      }
      else
      {
         HEATSENO2DSFONCDIAG_bAvItDsDgBva = 0;
      }
   }

   VEMS_vidGET(LsMon_bCaseItrsvSenO2DsDiag, bLocalLsMon_bCasItrsvSenO2DsDiag);

   if (bLocalLsMon_bCasItrsvSenO2DsDiag == 0)
   {
      if (u8LocalLsMon_stItrsvSenO2DsDiag == LSMON_ITRSV_SENO2DS_DIAG_OK)
      {
         HEATSENO2DSFONCDIAG_vidIsDgOKBva();
      }
      else
      {
         Ldsd_av_fco_no_failure = 0;
         if (u8LocalLsMon_stItrsvSenO2DsDiag == LSMON_ITRSV_SENO2DS_DIAG_NOK)
         {
            HEATSENO2DSFONCDIAG_vidIsDgNOKBv();
         }
      }
   }

   if (  (LsMon_bThdSenO2DsDiagFco != 0)
      || (SenO2Ds_bDgoORng_DsPlausFco != 0)
      || (Ldsd_av_fco_no_failure != 0))
   {
      SenO2Ds_bMonWaitRaw_DsPlausFco = 0;
      HEATSENO2DSFONCDIAG_vidInMod6Bva();
   }
   else
   {
      SenO2Ds_bMonWaitRaw_DsPlausFco = 1;
   }
   if (  (bLocalAcvItrsvSenO2DsDiagPrev != 0)
      && (LsMon_bAcvChkRMixtItrsv_C != 0)
      && (u32LocalObjectif_richesse_global > LsMon_rMixtMaxItrsvSenO2Ds_C))
   {
      HEATSENO2DSFONCDIAG_vidChMCyBva();
   }
   if (LsMon_bAcvChkRMixtItrsv_C != 0)
   {
      HEATSENO2DSFONCDIAG_vidtrsvCtBva();
   }
   LsMon_bItrsvSenO2DsDiagDoneFco = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidDgCntBva                            */
/* !Description :  Fonction de calcul de temporisation de confirmation du     */
/*                 seuil minimum atteint.                                     */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean LsMon_bThdSenO2DsDiagFco;                                   */
/*  input uint16 LsMon_tiCfmSenO2DsDiagFco_C;                                 */
/*  input uint16 LsMon_tiCfmSenO2DsDiagFco;                                   */
/*  output uint16 LsMon_tiCfmSenO2DsDiagFco;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidDgCntBva(void)
{
   sint32  s32LocalStep;


   if (LsMon_bThdSenO2DsDiagFco != 0)
   {
      LsMon_tiCfmSenO2DsDiagFco = LsMon_tiCfmSenO2DsDiagFco_C;
   }
   else
   {
      s32LocalStep = (sint32)(LsMon_tiCfmSenO2DsDiagFco - 1);
      LsMon_tiCfmSenO2DsDiagFco = (uint16)MATHSRV_udtMAX(s32LocalStep, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidDsDgOKBva                           */
/* !Description :  Fonction de calcul résultat du diagnostic sonde aval       */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean SenO2Ds_bDgoORng_DsPlausFco;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidDsDgOKBva(void)
{
   SenO2Ds_bDgoORng_DsPlausFco = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidIsDgOKBva                           */
/* !Description :  Demande diagnostic intrusif pour la sonde aval             */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean LsMon_bAcvItrsvSenO2DsDiag;                                */
/*  output boolean SenO2Ds_bDgoORng_DsPlausFco;                               */
/*  output boolean Ldsd_av_fco_no_failure;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidIsDgOKBva(void)
{
   VEMS_vidSET(LsMon_bAcvItrsvSenO2DsDiag, 0);
   SenO2Ds_bDgoORng_DsPlausFco = 0;
   Ldsd_av_fco_no_failure = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidIsDgNOKBv                           */
/* !Description :  Demande diagnostic intrusif pour la sonde aval             */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean LsMon_bAcvItrsvSenO2DsDiag;                                */
/*  output boolean SenO2Ds_bDgoORng_DsPlausFco;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidIsDgNOKBv(void)
{
   VEMS_vidSET(LsMon_bAcvItrsvSenO2DsDiag, 0);
   SenO2Ds_bDgoORng_DsPlausFco = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidAcvDgBva                            */
/* !Description :  Demande diagnostic intrusif pour la sonde aval             */
/* !Number      :  FCT4.6                                                     */
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
void HEATSENO2DSFONCDIAG_vidAcvDgBva(void)
{
   VEMS_vidSET(LsMon_bAcvItrsvSenO2DsDiag, 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidInMod6Bva                           */
/* !Description :  Fonction de renvoie de valeur minimale au mode $06 du      */
/*                 scantool .                                                 */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 LsMon_uThdSenO2DsDiagFcoGas_C;                               */
/*  input uint16 LsMon_uThdSenO2DsDiagFco_C;                                  */
/*  output uint16 SenO2Ds_FcoPlausFacMesRaw;                                  */
/*  output uint16 SenO2Ds_FcoPlausFacMaxRaw;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidInMod6Bva(void)
{
   uint8   u8LocalExt_stSysGas;
   uint16  u16LocalTension_sonde_aval;


   VEMS_vidGET(Tension_sonde_aval, u16LocalTension_sonde_aval);
   SenO2Ds_FcoPlausFacMesRaw =
      (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_aval, 1024);

   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      SenO2Ds_FcoPlausFacMaxRaw =
         (uint16)MATHSRV_udtMIN(LsMon_uThdSenO2DsDiagFcoGas_C, 1024);
   }
   else
   {
      SenO2Ds_FcoPlausFacMaxRaw =
         (uint16)MATHSRV_udtMIN(LsMon_uThdSenO2DsDiagFco_C, 1024);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidDgInDnBva                           */
/* !Description :  Mise de LsMon_bItrsvSenO2DsDiagDoneFco à 1                 */
/* !Number      :  FCT4.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean LsMon_bItrsvSenO2DsDiagDoneFco;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidDgInDnBva(void)
{
   LsMon_bItrsvSenO2DsDiagDoneFco = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidItrsvFld                            */
/* !Description :  La valeur du créneau de richesse est remise à jour         */
/*                 uniquement lorsque le défaut est en cours de confirmation  */
/*                 afin que les diagnostics « bloqué riche » et « bloqué      */
/*                 pauvre »  ne demandent pas simultanément un créneau à des  */
/*                 valeurs antagonistes.                                      */
/* !Number      :  FCT4.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean LsMon_bCaseItrsvSenO2DsDiag;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidItrsvFld(void)
{
   VEMS_vidSET(LsMon_bCaseItrsvSenO2DsDiag, 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidItrsvFco                            */
/* !Description :  La valeur du créneau de richesse est remise à jour         */
/*                 uniquement lorsque le défaut est en cours de confirmation, */
/*                 afin que les diagnostics « bloqué riche » et « bloqué      */
/*                 pauvre »  ne demandent pas simultanément un créneau à des  */
/*                 valeurs antagonistes.                                      */
/* !Number      :  FCT4.10                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean LsMon_bCaseItrsvSenO2DsDiag;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidItrsvFco(void)
{
   VEMS_vidSET(LsMon_bCaseItrsvSenO2DsDiag, 0);
}
/*-------------------------------- end of file -------------------------------*/