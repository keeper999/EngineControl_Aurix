/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKACQFILT                                              */
/* !Description     : KNKACQFILT Component                                    */
/*                                                                            */
/* !Module          : KNKACQFILT                                              */
/* !Description     :  KNOCK SIGNAL PROCESSING WITH A BAND-PASS FILTER AND    */
/*                    INTERFACE WITH BSW                                      */
/*                                                                            */
/* !File            : KNKACQFILT_FCT2.C                                       */
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
/*   1 / KNKACQFILT_vidOfsPmpHPNKnkcalc                                       */
/*   2 / KNKACQFILT_vidKnkMesWin                                              */
/*   3 / KNKACQFILT_vidInterfaceBSW                                           */
/*   4 / KNKACQFILT_vidCheckCondition                                         */
/*   5 / KNKACQFILT_vidOfsInjrNKnkcalc                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5066552 / 07                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/Projets/EB_DT_6_2/LOG/ASW/Ref/PATCH/KNKACQFILT_FCT2.c_v   $*/
/* $Revision::   1.0      $$Author::   ynicaise       $$Date::   10 Oct 2014 $*/
/* $Author::   ynicaise                               $$Date::   10 Oct 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "KNKACQFILT.h"
#include "KNKACQFILT_L.h"
#include "KNKACQFILT_IM.h"
#include "KNWHAL.h"
#include "PMPHAL.h"
#include "VEMS.h"
#include "SWFAIL.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKACQFILT_vidOfsPmpHPNKnkcalc                             */
/* !Description :  Ce bloc calcule la valeur à retrancher dans le bruit       */
/*                 instantané cliquetis lorsque la commande de la pompe HP    */
/*                 tombe dans la fenêtre cliquetis.                           */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ctrl_bAcv_HpPmp;                                            */
/*  input uint16 PFuCtl_agPmpCmdEfcReq;                                       */
/*  input uint16 Periode_angulaire;                                           */
/*  input uint16 PFuCtl_tiPmpCmdReq;                                          */
/*  input uint16 PMPHAL_ku16SpillEventAngleRqstd;                             */
/*  input uint8 KNKACQFILT_u8DebfencliquetisPrev;                             */
/*  input uint8 KNKACQFILT_u8DurfencliquetisPrev;                             */
/*  input sint16 knk_agPmpHPnoiseThd_C;                                       */
/*  input uint16 knk_agPmpHPnoiseEndThd_C;                                    */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint8 PFuCtl_NrProfCmd;                                             */
/*  input uint16 KnkMgt_nEng_A[9];                                            */
/*  input uint8 KnkMgt_NrProfCmd_A[15];                                       */
/*  input uint16 KnkAcqFilt_OfsSommeClq_M[9][15];                             */
/*  output uint16 Knk_OfsPmpHPNoiseKnk;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKACQFILT_vidOfsPmpHPNKnkcalc(void)
{
   boolean  bLocalCtrl_bAcv_HpPmp;
   uint8    u8LocalPFuCtl_NrProfCmd;
   uint16   u16LocalPFuCtl_agPmpCmdEfcReq;
   uint16   u16LocalPeriode_angulaire;
   uint16   u16LocalPFuCtl_tiPmpCmdReq;
   uint16   u16LocalExt_nEng;
   uint16   u16LocalParaExt_nEng;
   uint16   u16LocalParaPFuCtl_NrProfCmd;
   uint32   u32LocalExt_nEng;
   sint32   s32LocalknkagPmpHPnoiseThd;
   sint32   s32LocalknkagPmpHPnoiseEndThd;
   sint32   s32LocalPmpHPnoiseThd;
   sint32   s32LocalPmpHPnoiseEndThd;


   VEMS_vidGET(Ctrl_bAcv_HpPmp, bLocalCtrl_bAcv_HpPmp);
   VEMS_vidGET(PFuCtl_agPmpCmdEfcReq, u16LocalPFuCtl_agPmpCmdEfcReq);
   VEMS_vidGET(Periode_angulaire, u16LocalPeriode_angulaire);
   VEMS_vidGET(PFuCtl_tiPmpCmdReq, u16LocalPFuCtl_tiPmpCmdReq);

   s32LocalknkagPmpHPnoiseThd =
      (sint32)( ( ( (5 * PMPHAL_ku16SpillEventAngleRqstd)
                  + (30 * u16LocalPFuCtl_agPmpCmdEfcReq)
                  + 10240)
                - ( (320 * u16LocalPeriode_angulaire)
                  + (160 * KNKACQFILT_u8DebfencliquetisPrev))));
   s32LocalknkagPmpHPnoiseEndThd = ( (160 * KNKACQFILT_u8DurfencliquetisPrev)
                                   - s32LocalknkagPmpHPnoiseThd);
   s32LocalPmpHPnoiseThd = (sint32)(32 * knk_agPmpHPnoiseThd_C);
   s32LocalPmpHPnoiseEndThd = (sint32)(32 * knk_agPmpHPnoiseEndThd_C);
   if (  (bLocalCtrl_bAcv_HpPmp != 0)
      && (s32LocalknkagPmpHPnoiseThd >= s32LocalPmpHPnoiseThd)
      && (s32LocalknkagPmpHPnoiseEndThd >= s32LocalPmpHPnoiseEndThd)
      && (u16LocalPFuCtl_tiPmpCmdReq > 0))
   {
      VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
      VEMS_vidGET(PFuCtl_NrProfCmd, u8LocalPFuCtl_NrProfCmd);
      u32LocalExt_nEng = 8 * u16LocalExt_nEng;
      u16LocalExt_nEng = (uint16)MATHSRV_udtMIN(u32LocalExt_nEng, 65535);
      u16LocalParaExt_nEng = MATHSRV_u16CalcParaIncAryU16(KnkMgt_nEng_A,
                                                          u16LocalExt_nEng,
                                                          9);
      u16LocalParaPFuCtl_NrProfCmd =
         MATHSRV_u16CalcParaIncAryU8(KnkMgt_NrProfCmd_A,
                                     u8LocalPFuCtl_NrProfCmd,
                                     15);
      Knk_OfsPmpHPNoiseKnk =
         MATHSRV_u16Interp2d(&KnkAcqFilt_OfsSommeClq_M[0][0],
                             u16LocalParaExt_nEng,
                             u16LocalParaPFuCtl_NrProfCmd,
                             15);
   }
   else
   {
      Knk_OfsPmpHPNoiseKnk = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKACQFILT_vidKnkMesWin                                    */
/* !Description :  cette fonction détermine le nombre et le vecteur de        */
/*                 fenetres disponibles pour l'acquisition de signal          */
/*                 cliquetis/rumble                                           */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret Std_ReturnType  KNWHAL_udtSetSamplingWinPrms(argio uint16     */
/* *pau16SamplingWinTbl, argin uint8 u8SamplingWinNr);                        */
/*  input uint8 Ext_ctTDC;                                                    */
/*  input uint16 Periode_angulaire;                                           */
/*  input uint8 Debut_fenetre_cliquetis;                                      */
/*  input uint8 Duree_fenetre_cliquetis;                                      */
/*  input uint8 Debut_fenetre_rumble;                                         */
/*  input boolean Autorise_detection_rbl;                                     */
/*  input boolean Autorise_detection_clq;                                     */
/*  input boolean Knk_sens_diag_dmd_uavb0;                                    */
/*  input uint8 Duree_fenetre_rumble_min;                                     */
/*  input boolean KnkTreat_bInhRblAcq;                                        */
/*  input uint16 KnkAcqFilt_agTDCOfs;                                         */
/*  input uint16 KnkAcqFilt_agWdWinFiltInit;                                  */
/*  input uint16 Fin_fenetre_cliquetis;                                       */
/*  input sint16 KnkAcqFilt_prm_agKnkMesWinRaw[4];                            */
/*  input uint16 KnkAcqFilt_prm_agKnkMesWin[4];                               */
/*  output uint16 KnkAcqFilt_agTDCOfs;                                        */
/*  output uint16 Fin_fenetre_cliquetis;                                      */
/*  output boolean KnkTreat_bInhRblAcq;                                       */
/*  output sint16 KnkAcqFilt_prm_agKnkMesWinRaw[4];                           */
/*  output uint8 KnkAcqFilt_noKnkMesWin;                                      */
/*  output uint16 KnkAcqFilt_prm_agKnkMesWin[4];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKACQFILT_vidKnkMesWin(void)
{
   /*03_Definition_knk_windows*/
   boolean        bLocalAutorise_detection_rbl;
   boolean        bLocalAutorise_detection_clq;
   boolean        bLocalKnk_sens_diag_dmd_uavb0;
   boolean        bLocalSelector;
   uint8          u8LocalExt_ctTDC;
   uint8          u8LocalDuree_fenetre_cliquetis;
   uint8          u8LocalDebut_fenetre_rumble;
   uint8          u8LocalDebut_fenetre_cliquetis;
   uint8          u8LocalIdxRow;
   uint8          u8LocalVar;
   uint16         u16LocalPeriode_angulaire;
   uint16         u16LocalKnkAcqFilt;
   sint16         s16LocalFin_fenetre_cliquetis;
   sint16         s16LocalDivision1;
   uint32         u32LocalMultiplication;
   uint32         u32LocalagKnkMesWinRaw;
   uint32         u32LocalMultip;
   sint32         s32LocalagKnkMesWinRaw;


   VEMS_vidGET(Ext_ctTDC, u8LocalExt_ctTDC);
   VEMS_vidGET(Periode_angulaire, u16LocalPeriode_angulaire);
   u32LocalMultiplication =
      (uint32)(u8LocalExt_ctTDC * u16LocalPeriode_angulaire);
   KnkAcqFilt_agTDCOfs = (uint16)MATHSRV_udtMIN(u32LocalMultiplication, 719);

   VEMS_vidGET(Debut_fenetre_cliquetis, u8LocalDebut_fenetre_cliquetis);
   VEMS_vidGET(Duree_fenetre_cliquetis, u8LocalDuree_fenetre_cliquetis);
   s16LocalFin_fenetre_cliquetis =
      (sint16)( ((uint32)( ( u8LocalDebut_fenetre_cliquetis
                           + u8LocalDuree_fenetre_cliquetis)
                         * 32))
              - 2048);
   Fin_fenetre_cliquetis =
      (uint16)MATHSRV_udtMAX(s16LocalFin_fenetre_cliquetis, 0);

   VEMS_vidGET(Debut_fenetre_rumble, u8LocalDebut_fenetre_rumble);
   s16LocalDivision1 =
      (sint16)(u8LocalDebut_fenetre_cliquetis - u8LocalDebut_fenetre_rumble);
   u8LocalVar = (uint8)MATHSRV_udtMAX(s16LocalDivision1, 0);

   VEMS_vidGET(Autorise_detection_rbl, bLocalAutorise_detection_rbl);
   VEMS_vidGET(Autorise_detection_clq, bLocalAutorise_detection_clq);
   VEMS_vidGET(Knk_sens_diag_dmd_uavb0, bLocalKnk_sens_diag_dmd_uavb0);
   if (  (u8LocalVar <= Duree_fenetre_rumble_min)
      || (bLocalKnk_sens_diag_dmd_uavb0 != 0))
   {
      KnkTreat_bInhRblAcq = 1;
   }
   else
   {
      KnkTreat_bInhRblAcq = 0;
   }
   if (  (KnkTreat_bInhRblAcq == 0)
      && (bLocalAutorise_detection_rbl != 0)
      && (bLocalAutorise_detection_clq != 0))
   {
      bLocalSelector = 1;
   }
   else
   {
      bLocalSelector = 0;
   }
   u32LocalMultip = (uint32)(KnkAcqFilt_agTDCOfs * 2);
   if (bLocalSelector != 0)
   {
      s32LocalagKnkMesWinRaw =
         (sint32)( ( u32LocalMultip
                   + u8LocalDebut_fenetre_rumble)
                 - ( KnkAcqFilt_agWdWinFiltInit
                   + 64));

      KnkAcqFilt_prm_agKnkMesWinRaw[0] =
         (sint16)MATHSRV_udtCLAMP(s32LocalagKnkMesWinRaw,
                                  -1440,
                                  1439);
      /*QAC Msg(3:3356): s32LocalagKnkMesWinRaw is between [-1503..1693]*/

      s32LocalagKnkMesWinRaw =
         (sint32)( ( u32LocalMultip
                   + u8LocalDebut_fenetre_rumble)
                 - 64);
      KnkAcqFilt_prm_agKnkMesWinRaw[1] =
         (sint16)MATHSRV_udtMIN(s32LocalagKnkMesWinRaw, 1439);

      s32LocalagKnkMesWinRaw =
         (sint32)( ( u32LocalMultip
                   + u8LocalDebut_fenetre_cliquetis)
                 - 64);
      KnkAcqFilt_prm_agKnkMesWinRaw[2] =
         (sint16)MATHSRV_udtMIN(s32LocalagKnkMesWinRaw, 1439);

      u32LocalagKnkMesWinRaw =
         (uint32)( ( (KnkAcqFilt_agTDCOfs * 64)
                   + Fin_fenetre_cliquetis
                   + 16)
                 / 32);
      KnkAcqFilt_prm_agKnkMesWinRaw[3] =
         (sint16)MATHSRV_udtMIN(u32LocalagKnkMesWinRaw, 1439);

      KnkAcqFilt_noKnkMesWin = 3;

      for (u8LocalIdxRow = 0; u8LocalIdxRow < 4; u8LocalIdxRow++)
      {
         u16LocalKnkAcqFilt =
            (uint16)((KnkAcqFilt_prm_agKnkMesWinRaw[u8LocalIdxRow] + 1440)
                     % 1440);
         KnkAcqFilt_prm_agKnkMesWin[u8LocalIdxRow] =
            (uint16)(u16LocalKnkAcqFilt * 32);
      }
      (void)KNWHAL_udtSetSamplingWinPrms(
         (uint16*)&KnkAcqFilt_prm_agKnkMesWin[0],
         3);
      /*QAC Msg(2:3212):The cast (uint16*) is recommended by the specification
                        of KNWHAL APIs*/
   }
   else
   {
      s32LocalagKnkMesWinRaw =
         (sint32)( ( u32LocalMultip
                   + u8LocalDebut_fenetre_cliquetis)
                 - (KnkAcqFilt_agWdWinFiltInit + 64));

      KnkAcqFilt_prm_agKnkMesWinRaw[0] =
         (sint16)MATHSRV_udtCLAMP(s32LocalagKnkMesWinRaw,
                                  -1440,
                                  1439);
   /*QAC Msg(3:3356): s32LocalagKnkMesWinRaw is between [-1503..1693]*/

      s32LocalagKnkMesWinRaw =
         (sint32)( ( u32LocalMultip
                   + u8LocalDebut_fenetre_cliquetis)
                 - 64);
      KnkAcqFilt_prm_agKnkMesWinRaw[1] =
         (sint16)MATHSRV_udtMIN(s32LocalagKnkMesWinRaw, 1439);

      u32LocalagKnkMesWinRaw =
         (uint32)( ( (KnkAcqFilt_agTDCOfs * 64)
                   + Fin_fenetre_cliquetis
                   + 16)
                 / 32);

      KnkAcqFilt_prm_agKnkMesWinRaw[2] =
         (sint16)MATHSRV_udtMIN(u32LocalagKnkMesWinRaw, 1439);

      KnkAcqFilt_prm_agKnkMesWinRaw[3] = 0;

      KnkAcqFilt_noKnkMesWin = 2;

      for (u8LocalIdxRow = 0; u8LocalIdxRow < 4; u8LocalIdxRow++)
      {
         u16LocalKnkAcqFilt =
            (uint16)((KnkAcqFilt_prm_agKnkMesWinRaw[u8LocalIdxRow] + 1440)
                     % 1440);
         KnkAcqFilt_prm_agKnkMesWin[u8LocalIdxRow] =
            (uint16)(u16LocalKnkAcqFilt * 32);
      }
      (void)KNWHAL_udtSetSamplingWinPrms(
         (uint16*)&KnkAcqFilt_prm_agKnkMesWin[0],
         2);
      /*QAC Msg(2:3212):The cast (uint16*) is recommended by the specification
                        of KNWHAL APIs*/
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKACQFILT_vidInterfaceBSW                                 */
/* !Description :  Fonction d'interfacage BSW.                                */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  KNWHAL_udtSamplingWinTrigger();               */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Acq_knk_rbl_cfg_win_status_upvb0;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKACQFILT_vidInterfaceBSW(void)
{
   Std_ReturnType udtLocalTrigStatus;


   udtLocalTrigStatus = KNWHAL_udtSamplingWinTrigger();
   if (udtLocalTrigStatus == E_OK)
   {
      VEMS_vidSET(Acq_knk_rbl_cfg_win_status_upvb0, 1);
   }
   else
   {
      VEMS_vidSET(Acq_knk_rbl_cfg_win_status_upvb0, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKACQFILT_vidCheckCondition                               */
/* !Description :  Production activation condition of block                   */
/*                 03_Definition_knk_windows                                  */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Autorise_detection_clq;                                     */
/*  input boolean Autorise_detection_rbl;                                     */
/*  input boolean KNKACQFILT_bAcvCalSdlFastPrev;                              */
/*  output boolean KnkRbl_bAcvCalSdlFast;                                     */
/*  output boolean KNKACQFILT_bAcvCalSdlFastPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKACQFILT_vidCheckCondition(void)
{
   boolean  bLocalAutorise_detection_clq;
   boolean  bLocalAutorise_detection_rbl;


   VEMS_vidGET(Autorise_detection_clq, bLocalAutorise_detection_clq);
   VEMS_vidGET(Autorise_detection_rbl, bLocalAutorise_detection_rbl);
   if (  (bLocalAutorise_detection_clq != 0)
      || (bLocalAutorise_detection_rbl != 0))
   {
      if (KNKACQFILT_bAcvCalSdlFastPrev == 0)
      {
         KnkRbl_bAcvCalSdlFast = 1;
      }
      else
      {
         KnkRbl_bAcvCalSdlFast = 0;
      }
      KNKACQFILT_bAcvCalSdlFastPrev = 1;
   }
   else
   {
      KnkRbl_bAcvCalSdlFast = 0;
      KNKACQFILT_bAcvCalSdlFastPrev = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKACQFILT_vidOfsInjrNKnkcalc                              */
/* !Description :  Ce bloc calcule la valeur à retrancher dans le bruit       */
/*                 instantané cliquetis lorsque le début des injections tombe */
/*                 dans la fenêtre cliquetis.                                 */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Eng_noCmprCyl;                                                */
/*  input uint16 InjSys_prm_agBegInjH1ReqCyl[6];                              */
/*  input uint32 InjrSys_prm_tiInjH1ReqCyl[6];                                */
/*  input uint16 InjSys_prm_agBegInjH2ReqCyl[6];                              */
/*  input uint32 InjrSys_prm_tiInjH2ReqCyl[6];                                */
/*  input uint16 InjSys_prm_agBegInjS1ReqCyl[6];                              */
/*  input uint32 InjrSys_prm_tiInjS1ReqCyl[6];                                */
/*  input uint16 InjSys_prm_agBegInjS2ReqCyl[6];                              */
/*  input uint32 InjrSys_prm_tiInjS2ReqCyl[6];                                */
/*  input uint8 KNKACQFILT_u8DebfencliquetisPrev;                             */
/*  input uint8 KNKACQFILT_u8DurfencliquetisPrev;                             */
/*  input sint16 knk_agInjrNoiseThd_C;                                        */
/*  input uint16 knk_agInjrNoiseEndThd_C;                                     */
/*  input uint8 InjSys_stTypElCmdInjrReq;                                     */
/*  input uint16 knk_agInjCnvTDCref_C;                                        */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint8 KnkMgt_tCoMes_A[9];                                           */
/*  input uint8 KnkMgt_stTypElCmdInjrReq_A[5];                                */
/*  input uint16 KnkAcqFilt_OfsInjrSommeClq_M[9][5];                          */
/*  input uint8 KnkMgt_noCmpr_A[6];                                           */
/*  input uint8 KnkAcqFilt_facCylOfsInjrNoise_T[6];                           */
/*  output uint16 Knk_OfsInjrNoiseKnk;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKACQFILT_vidOfsInjrNKnkcalc(void)
{

   uint8  u8LocalEng_noCmprCyl;
   uint8  u8LocalEng_noCmprCylidx;
   uint8  u8LocalCalcPara;
   uint8  u8LocalOutidx;
   uint8  u8LocalOut;
   uint8  u8LocalExt_tCoMes;
   uint8  u8LocalInjSys_stTypElCmdInjrReq;
   sint16 s16LocalExt_tCoMes;
   uint16 u16LocalCalcPara;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalInterp2d;
   uint16 u16LocalagBegInjH1ReqCyl;
   uint16 u16LocalagBegInjH2ReqCyl;
   uint16 u16LocalagBegInjS1ReqCyl;
   uint16 u16LocalagBegInjS2ReqCyl;
   uint32 u32LocaltiInjH1ReqCyl;
   uint32 u32LocaltiInjH2ReqCyl;
   uint32 u32LocaltiInjS1ReqCyl;
   uint32 u32LocaltiInjS2ReqCyl;
   uint32 u32LocalMult;
   sint32 s32LocalSomPrev;
   sint32 s32LocalDiff1;
   sint32 s32LocalDiff2;
   sint32 s32LocalDiff3;
   sint32 s32LocalNoiseEndThd_C;
   sint32 s32LocalNoiseThd_C;


   VEMS_vidGET(Eng_noCmprCyl, u8LocalEng_noCmprCyl);
   switch(u8LocalEng_noCmprCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      /*QAC : Msg(2:2215) due to the use of switch case*/
         u8LocalEng_noCmprCylidx = (uint8)(u8LocalEng_noCmprCyl - 1);
         VEMS_vidGET1DArrayElement(InjSys_prm_agBegInjH1ReqCyl,
                                   u8LocalEng_noCmprCylidx,
                                   u16LocalagBegInjH1ReqCyl);

         VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjH1ReqCyl,
                                   u8LocalEng_noCmprCylidx,
                                   u32LocaltiInjH1ReqCyl);

         VEMS_vidGET1DArrayElement(InjSys_prm_agBegInjH2ReqCyl,
                                   u8LocalEng_noCmprCylidx,
                                   u16LocalagBegInjH2ReqCyl);

         VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjH2ReqCyl,
                                   u8LocalEng_noCmprCylidx,
                                   u32LocaltiInjH2ReqCyl);

         VEMS_vidGET1DArrayElement(InjSys_prm_agBegInjS1ReqCyl,
                                   u8LocalEng_noCmprCylidx,
                                   u16LocalagBegInjS1ReqCyl);

         VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjS1ReqCyl,
                                   u8LocalEng_noCmprCylidx,
                                   u32LocaltiInjS1ReqCyl);

         VEMS_vidGET1DArrayElement(InjSys_prm_agBegInjS2ReqCyl,
                                   u8LocalEng_noCmprCylidx,
                                   u16LocalagBegInjS2ReqCyl);

         VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjS2ReqCyl,
                                   u8LocalEng_noCmprCylidx,
                                   u32LocaltiInjS2ReqCyl);

         s32LocalSomPrev =(sint32)( ( KNKACQFILT_u8DebfencliquetisPrev
                                    + KNKACQFILT_u8DurfencliquetisPrev)
                                  - 64);
         u8LocalOut = 0;
         s32LocalNoiseThd_C = (sint32)(knk_agInjrNoiseThd_C * 8);
         s32LocalNoiseEndThd_C = (sint32)(knk_agInjrNoiseEndThd_C * 8);
         VEMS_vidGET(InjSys_stTypElCmdInjrReq, u8LocalInjSys_stTypElCmdInjrReq);

         if (u32LocaltiInjH1ReqCyl > 0)
         {
            s32LocalDiff1 = (sint32)( (knk_agInjCnvTDCref_C * 16)
                                    - u16LocalagBegInjH1ReqCyl);
            s32LocalDiff2 = ( ( (5 * s32LocalDiff1)
                              - (40 * KNKACQFILT_u8DebfencliquetisPrev))
                            + 2560);
            s32LocalDiff3 = (40 * s32LocalSomPrev) - (5 * s32LocalDiff1);
            if (  (s32LocalDiff2 >= s32LocalNoiseThd_C)
               && (s32LocalDiff3 >= s32LocalNoiseEndThd_C))
            {
               u8LocalOut = (uint8)(u8LocalOut + 1);
            }
         }

         if (u32LocaltiInjH2ReqCyl > 0)
         {
            s32LocalDiff1 = (sint32)( (knk_agInjCnvTDCref_C * 16)
                                    - u16LocalagBegInjH2ReqCyl);
            s32LocalDiff2 = ( ( (5 * s32LocalDiff1)
                              - (40 * KNKACQFILT_u8DebfencliquetisPrev))
                            + 2560);
            s32LocalDiff3 = (40 * s32LocalSomPrev) - (5 * s32LocalDiff1);
            if (  (s32LocalDiff2 >= s32LocalNoiseThd_C)
               && (s32LocalDiff3 >= s32LocalNoiseEndThd_C))
            {
               u8LocalOut = (uint8)(u8LocalOut + 1);
            }
         }

         s32LocalNoiseThd_C = (sint32)(knk_agInjrNoiseThd_C * 16);
         s32LocalNoiseEndThd_C = (sint32)(knk_agInjrNoiseEndThd_C * 16);
         if (u32LocaltiInjS1ReqCyl > 0)
         {
            s32LocalDiff1 = ( (sint32)(knk_agInjCnvTDCref_C * 32)
                            - (sint32)(u16LocalagBegInjS1ReqCyl * 3));
            s32LocalDiff2 = ( ( (5 * s32LocalDiff1)
                              - (80 * KNKACQFILT_u8DebfencliquetisPrev))
                            + 5120);
            s32LocalDiff3 = (80 * s32LocalSomPrev) - (5 * s32LocalDiff1);
            if (  (s32LocalDiff2 >= s32LocalNoiseThd_C)
               && (s32LocalDiff3 >= s32LocalNoiseEndThd_C))
            {
               u8LocalOut = (uint8)(u8LocalOut + 1);
            }
         }

         if (u32LocaltiInjS2ReqCyl > 0)
         {
            s32LocalDiff1 = ( (sint32)(knk_agInjCnvTDCref_C * 32)
                            - (sint32)(u16LocalagBegInjS2ReqCyl * 3));
            s32LocalDiff2 = ( ( (5 * s32LocalDiff1)
                              - (80 * KNKACQFILT_u8DebfencliquetisPrev))
                            + 5120);
            s32LocalDiff3 = (80 * s32LocalSomPrev) - (5 * s32LocalDiff1);
            if (  (s32LocalDiff2 >= s32LocalNoiseThd_C)
               && (s32LocalDiff3 >= s32LocalNoiseEndThd_C))
            {
               u8LocalOut = (uint8)(u8LocalOut + 1);
            }
         }

         VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
         s16LocalExt_tCoMes =
            (sint16)MATHSRV_udtCLAMP(s16LocalExt_tCoMes, -40, 214);
         u8LocalExt_tCoMes = (uint8)(s16LocalExt_tCoMes + 40);
         u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU8(KnkMgt_tCoMes_A,
                                                         u8LocalExt_tCoMes,
                                                         9);
         u16LocalCalcParaY =
            MATHSRV_u16CalcParaIncAryU8(KnkMgt_stTypElCmdInjrReq_A,
                                        u8LocalInjSys_stTypElCmdInjrReq,
                                        5);
         u16LocalInterp2d =
            MATHSRV_u16Interp2d(&KnkAcqFilt_OfsInjrSommeClq_M[0][0],
                                u16LocalCalcParaX,
                                u16LocalCalcParaY,
                                5);
         u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(KnkMgt_noCmpr_A,
                                                        u8LocalEng_noCmprCyl,
                                                        6);
         u8LocalCalcPara = (uint8)(u16LocalCalcPara >> 8);
         u8LocalOutidx = KnkAcqFilt_facCylOfsInjrNoise_T[u8LocalCalcPara];
         u32LocalMult = (uint32)( ((u16LocalInterp2d * u8LocalOut)
                                  * u8LocalOutidx)
                                / 256);
         Knk_OfsInjrNoiseKnk = (uint16)MATHSRV_udtMIN(u32LocalMult, 65535);
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/*------------------------------- end of file --------------------------------*/