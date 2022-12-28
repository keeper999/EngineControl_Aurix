/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQESTMAX                                                */
/* !Description     : TQESTMAX component.                                     */
/*                                                                            */
/* !Module          : TQESTMAX                                                */
/* !Description     : Modèle d’estimation du couple Max                       */
/*                                                                            */
/* !File            : TQESTMAX_FCT1.C                                         */
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
/*   1 / TQESTMAX_vidInitOutput                                               */
/*   2 / TQESTMAX_vidModele_cpl_pot                                           */
/*   3 / TQESTMAX_vidCalcul_cpl_pot_brut                                      */
/*   4 / TQESTMAX_vidCalculCplPotDephase                                      */
/*   5 / TQESTMAX_vidAcvFiltrageProc                                          */
/*   6 / TQESTMAX_vidAcvFiltrageSIP_ESP                                       */
/*   7 / TQESTMAX_vidCalcul_gain_filtrage                                     */
/*   8 / TQESTMAX_vidActivation_Filtrage                                      */
/*   9 / TQESTMAX_vidCalculCplPotFiltre                                       */
/*   10 / TQESTMAX_vidCalculCplPotEstime                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5795522 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_0924 / 2.2                                      */
/* !OtherRefs   : VEMS V02 ECU#045173                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQESTMAX/TQESTMAX$*/
/* $Revision::   1.10     $$Author::   mbenfrad       $$Date::   25 Nov 2013 $*/
/* $Author::   mbenfrad                               $$Date::   25 Nov 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQESTMAX.h"
#include "TQESTMAX_L.h"
#include "TQESTMAX_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQESTMAX_vidInitOutput                                     */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output sint16 CoPt_tqEfcAirMaxEstim;                                      */
/*  output boolean CoPt_bAcvTqMaxEstim;                                       */
/*  output boolean CoPt_bAcvTqMaxEstimSIP;                                    */
/*  output sint16 CoPt_tqEfcAirEstimRaw;                                      */
/*  output sint16 CoPt_tqAirLimEstim;                                         */
/*  output sint16 CoPt_tqEfcAirEstimDly;                                      */
/*  output sint16 CoPt_tqEfcAirMaxFil;                                        */
/*  output sint16 CoPt_tqEfcAirMaxFil1;                                       */
/*  output boolean CoPt_bAcvTqMaxEstimTq_MP;                                  */
/*  output sint16 CoPt_stepFacTqMaxEstim_MP;                                  */
/*  output uint8 CoPt_facTqMaxEstim;                                          */
/*  output boolean CoPt_bASR;                                                 */
/*  output boolean TQESTMAX_bRSOutput;                                        */
/*  output boolean CoPt_bAuthTqMaxEstimSIP;                                   */
/*  output uint8 TQESTMAX_u8CoPtfacTqMaxEstimPrev;                            */
/*  output uint8 TQESTMAX_u8CoPfacTqMaxEstimPrev2;                            */
/*  output uint8 TQESTMAX_u8Cha_stTqReqPrev;                                  */
/*  output sint16 TQESTMAX_as16TqEfcAirEstimRaw[16];                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQESTMAX_vidInitOutput(void)
{
   uint8 u8Local;


   /* Init of outputs */
   VEMS_vidSET(CoPt_tqEfcAirMaxEstim, 0);
   VEMS_vidSET(CoPt_bAcvTqMaxEstim, 0);
   VEMS_vidSET(CoPt_bAcvTqMaxEstimSIP, 0);
   /* Init of intermediate variables */
   CoPt_tqEfcAirEstimRaw = 0;
   CoPt_tqAirLimEstim    = 0;
   CoPt_tqEfcAirEstimDly = 0;
   CoPt_tqEfcAirMaxFil   = 0;
   CoPt_tqEfcAirMaxFil1  = 0;
   CoPt_bAcvTqMaxEstimTq_MP = 0;
   CoPt_stepFacTqMaxEstim_MP = 0;
   CoPt_facTqMaxEstim = 0;
   CoPt_bASR = 0;
   TQESTMAX_bRSOutput = 0;
   CoPt_bAuthTqMaxEstimSIP = 0;
   /* Init of Prev values */
   TQESTMAX_u8CoPtfacTqMaxEstimPrev = 0;
   TQESTMAX_u8CoPfacTqMaxEstimPrev2 = 0;
   TQESTMAX_u8Cha_stTqReqPrev = 0;
   /* Init of created TAB */
   for(u8Local = 0; u8Local < 16; u8Local++)
   {
      TQESTMAX_as16TqEfcAirEstimRaw[u8Local] = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQESTMAX_vidModele_cpl_pot                                 */
/* !Description :  Cette fonction réalise une estimation du couple potentiel  */
/*                 moteur en excluant les réductions de couple demandées par  */
/*                 les BVA/BVMP et par l’ESP.                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_09_05545_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQESTMAX_vidCalcul_cpl_pot_brut();                       */
/*  extf argret void TQESTMAX_vidCalculCplPotDephase();                       */
/*  extf argret void TQESTMAX_vidAcvFiltrageProc();                           */
/*  extf argret void TQESTMAX_vidCalculCplPotFiltre();                        */
/*  extf argret void TQESTMAX_vidCalculCplPotEstime();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQESTMAX_vidModele_cpl_pot(void)
{
   TQESTMAX_vidCalcul_cpl_pot_brut();
   TQESTMAX_vidCalculCplPotDephase();
   TQESTMAX_vidAcvFiltrageProc();
   TQESTMAX_vidCalculCplPotFiltre();
   TQESTMAX_vidCalculCplPotEstime();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQESTMAX_vidCalcul_cpl_pot_brut                            */
/* !Description :  Le couple potentiel hors intervention boites et ASR est    */
/*                 basé sur la consigne de couple après intervention EasyMove,*/
/*                 coordonné avec les interventions MSR et auquel on ajoute   */
/*                 les réserves.                                              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_09_05545_002.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 TqSys_tqCkEfcAirFil;                                         */
/*  input sint16 TqLimEM_tqLimEMTrv;                                          */
/*  input uint8 Cha_stTqReq;                                                  */
/*  input sint16 Cha_tqAirMSRReq;                                             */
/*  input sint16 TqCha_tqAirTqIncReq;                                         */
/*  input sint16 TqRes_tqMaxRes;                                              */
/*  input sint16 EngLim_tqCkEfcChaLim;                                        */
/*  input sint16 EngLim_tqCkEfcGBxLimCordEL2;                                 */
/*  input boolean CoPt_bSelTqAirDrv_C;                                        */
/*  input boolean CoPt_bSelTqAirMSR_C;                                        */
/*  output sint16 CoPt_tqEfcAirEstimRaw;                                      */
/*  output sint16 CoPt_tqAirLimEstim;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQESTMAX_vidCalcul_cpl_pot_brut(void)
{
   uint8  u8LocalCha_stTqRe;
   sint16 s16LocalOutSwitch1;
   sint16 s16LocalOutSwitch2;
   sint16 s16LocalOutSwitch3;
   sint16 s16LocalTqLimEM_tqLimEMTrv;
   sint16 s16LocalTqCha_tqAirTqIncReq;
   sint16 s16LocalTqSys_tqCkEfcAirFil;
   sint16 s16LocalCha_tqAirMSRReq;
   sint16 s16LocalEngLimtqCkEfGBxLimCrdEL2;
   sint16 s16LocalTqRes_tqMaxRes;
   sint16 s16LocalEngLim_tqCkEfcChaLim;
   sint16 s16LocalMin;
   sint32 s32LocalSom;


   VEMS_vidGET(TqSys_tqCkEfcAirFil, s16LocalTqSys_tqCkEfcAirFil);
   VEMS_vidGET(TqLimEM_tqLimEMTrv, s16LocalTqLimEM_tqLimEMTrv);
   VEMS_vidGET(Cha_stTqReq, u8LocalCha_stTqRe);
   VEMS_vidGET(Cha_tqAirMSRReq, s16LocalCha_tqAirMSRReq);
   VEMS_vidGET(TqCha_tqAirTqIncReq, s16LocalTqCha_tqAirTqIncReq);
   VEMS_vidGET(TqRes_tqMaxRes, s16LocalTqRes_tqMaxRes);
   VEMS_vidGET(EngLim_tqCkEfcChaLim, s16LocalEngLim_tqCkEfcChaLim);
   VEMS_vidGET(EngLim_tqCkEfcGBxLimCordEL2,
               s16LocalEngLimtqCkEfGBxLimCrdEL2);

   if (CoPt_bSelTqAirDrv_C != 0)
   {
      s16LocalOutSwitch1 = s16LocalTqSys_tqCkEfcAirFil;
   }
   else
   {
      s16LocalOutSwitch1 = s16LocalTqLimEM_tqLimEMTrv;
   }

   if (u8LocalCha_stTqRe == 6)
   {
      if (CoPt_bSelTqAirMSR_C != 0)
      {
         s16LocalOutSwitch2 = s16LocalCha_tqAirMSRReq;
      }
      else
      {
         s16LocalOutSwitch2 = s16LocalTqCha_tqAirTqIncReq;
      }
      s16LocalOutSwitch3 = (sint16)MATHSRV_udtMAX(s16LocalOutSwitch1,
                                                  s16LocalOutSwitch2);
   }
   else
   {
      s16LocalOutSwitch3 = s16LocalOutSwitch1;
   }
   s32LocalSom = (sint32)(s16LocalTqRes_tqMaxRes + s16LocalOutSwitch3);

   if (u8LocalCha_stTqRe == 5)
   {
      s32LocalSom = MATHSRV_udtMIN(s32LocalSom, s16LocalEngLim_tqCkEfcChaLim);
      s16LocalMin = (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqCkEfcChaLim,
                                           s16LocalOutSwitch3);
   }
   else
   {
      s32LocalSom = MATHSRV_udtMIN(s32LocalSom,
                                   s16LocalEngLimtqCkEfGBxLimCrdEL2);
      s16LocalMin = (sint16)MATHSRV_udtMIN(s16LocalEngLimtqCkEfGBxLimCrdEL2,
                                           s16LocalOutSwitch3);
   }
   CoPt_tqEfcAirEstimRaw = (sint16)MATHSRV_udtCLAMP(s32LocalSom,
                                                    -32000,
                                                    32000);

   CoPt_tqAirLimEstim = (sint16)MATHSRV_udtCLAMP(s16LocalMin,
                                                 -32000,
                                                 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQESTMAX_vidCalculCplPotDephase                            */
/* !Description :  Le couple potentiel brut est déphasé via un retard variable*/
/*                 fonction du régime moteur.                                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_09_05545_003.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 Copt_nEngTqMaxEstimX_A[10];                                  */
/*  input uint8 CoPt_noDlyTqMax_T[10];                                        */
/*  input sint16 TQESTMAX_as16TqEfcAirEstimRaw[16];                           */
/*  input sint16 CoPt_tqEfcAirEstimRaw;                                       */
/*  input uint8 Cha_stTqReq;                                                  */
/*  input uint8 TQESTMAX_u8Cha_stTqReqPrev;                                   */
/*  input boolean CoPt_bAcvASRUp_C;                                           */
/*  output sint16 TQESTMAX_as16TqEfcAirEstimRaw[16];                          */
/*  output sint16 CoPt_tqEfcAirEstimDly;                                      */
/*  output uint8 TQESTMAX_u8Cha_stTqReqPrev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQESTMAX_vidCalculCplPotDephase(void)
{
   uint8  u8LocalIndex;
   uint8  u8LocalId;
   uint8  u8LocalCha_stTqReq;
   uint16 u16LocalCalcPara;
   uint16 u16LocalExt_nEng;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalExt_nEng = (uint16)(u16LocalExt_nEng / 10);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(Copt_nEngTqMaxEstimX_A,
                                                   u16LocalExt_nEng,
                                                   10);

   u8LocalIndex = MATHSRV_u8Interp1d(CoPt_noDlyTqMax_T, u16LocalCalcPara);
   u8LocalIndex = (uint8)MATHSRV_udtMIN(u8LocalIndex, 15);
   /* The previous values of CoPt_tqEfcAirEstimRaw are ranged in a table */
   for (u8LocalId = 15; u8LocalId > 0; u8LocalId--)
   {
      TQESTMAX_as16TqEfcAirEstimRaw[u8LocalId] =
         TQESTMAX_as16TqEfcAirEstimRaw[u8LocalId - 1];
   }
   TQESTMAX_as16TqEfcAirEstimRaw[0] = CoPt_tqEfcAirEstimRaw;

   /* Calcul of the output */
   VEMS_vidGET(Cha_stTqReq, u8LocalCha_stTqReq);
   if (  (u8LocalCha_stTqReq == 5)
      && (TQESTMAX_u8Cha_stTqReqPrev != 5)
      && (CoPt_bAcvASRUp_C != 0))
   {
      if (u8LocalIndex != 0)
      {
         u8LocalIndex = 1;
      }
   }
   CoPt_tqEfcAirEstimDly =
      (sint16)MATHSRV_udtCLAMP(TQESTMAX_as16TqEfcAirEstimRaw[u8LocalIndex],
                               -32000,
                               32000);
   TQESTMAX_u8Cha_stTqReqPrev = (uint8)MATHSRV_udtMIN(u8LocalCha_stTqReq, 7);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQESTMAX_vidAcvFiltrageProc                                */
/* !Description :  Le calcul de l’activation du filtrage du couple potentiel  */
/*                 est divisé en trois sous-fonctions.                        */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_04747_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQESTMAX_vidAcvFiltrageSIP_ESP();                        */
/*  extf argret void TQESTMAX_vidCalcul_gain_filtrage();                      */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TQESTMAX_vidActivation_Filtrage();                       */
/*  input uint8 Ext_stTraTypCf;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQESTMAX_vidAcvFiltrageProc(void)
{
   uint8 u8LocalExt_stTraTypCf;


   TQESTMAX_vidAcvFiltrageSIP_ESP();
   TQESTMAX_vidCalcul_gain_filtrage();

   VEMS_vidGET(Ext_stTraTypCf, u8LocalExt_stTraTypCf);
   if (u8LocalExt_stTraTypCf == 1)
   {
      TQESTMAX_vidActivation_Filtrage();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQESTMAX_vidAcvFiltrageSIP_ESP                             */
/* !Description :  Le filtrage en changement de rapport et en intervention ASR*/
/*                 sera activé si la consigne de couple air après intervention*/
/*                 boite est inférieure à la consigne de couple air avant     */
/*                 intervention BV/ESP pendant un SIP ou une régulation ASR.  */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_04747_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoPt_bSIPBuf;                                               */
/*  input sint16 CoPt_tqIdcAirCord_nCross;                                    */
/*  input sint16 TqCmp_tqSumLossCmp;                                          */
/*  input boolean CoPt_bAcvTqMaxEstimSIP;                                     */
/*  input uint8 Cha_stTqReq;                                                  */
/*  input boolean CoPt_bAuthTqMaxEstimSIP_C;                                  */
/*  input sint16 CoPt_tqThdAcvTqMaxEstim_C;                                   */
/*  input sint16 CoPt_tqAirLimEstim;                                          */
/*  input boolean CoPt_bAcvTqMaxEstimTq_MP;                                   */
/*  input boolean CoPt_bAuthTqMaxEstimSIP;                                    */
/*  input boolean CoPt_bASR;                                                  */
/*  input uint8 TQESTMAX_u8CoPtfacTqMaxEstimPrev;                             */
/*  input uint8 TQESTMAX_u8CoPfacTqMaxEstimPrev2;                             */
/*  input uint8 CoPt_facTqMaxEstim;                                           */
/*  output boolean CoPt_bAuthTqMaxEstimSIP;                                   */
/*  output boolean CoPt_bAcvTqMaxEstimTq_MP;                                  */
/*  output boolean CoPt_bASR;                                                 */
/*  output boolean CoPt_bAcvTqMaxEstimSIP;                                    */
/*  output uint8 TQESTMAX_u8CoPfacTqMaxEstimPrev2;                            */
/*  output uint8 TQESTMAX_u8CoPtfacTqMaxEstimPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQESTMAX_vidAcvFiltrageSIP_ESP(void)
{
   boolean bLocalCoPt_bSIPBuf;
   boolean bLocalSet;
   boolean bLocalReset;
   boolean bLocalCoPt_bAcvTqMaxEstimSIP;
   uint8   u8LocalCha_stTqReq;
   sint32  s32LocalFirstDiff;
   sint32  s32LocalSecondDiff;
   sint16  s16LocalCoPt_tqIdcAirCord_nCross;
   sint16  s16LocalTqCmp_tqSumLossCmp;


   VEMS_vidGET(CoPt_bSIPBuf, bLocalCoPt_bSIPBuf);
   VEMS_vidGET(CoPt_tqIdcAirCord_nCross, s16LocalCoPt_tqIdcAirCord_nCross);
   VEMS_vidGET(TqCmp_tqSumLossCmp, s16LocalTqCmp_tqSumLossCmp);
   VEMS_vidGET(CoPt_bAcvTqMaxEstimSIP, bLocalCoPt_bAcvTqMaxEstimSIP);
   VEMS_vidGET(Cha_stTqReq, u8LocalCha_stTqReq);

   CoPt_bAuthTqMaxEstimSIP = CoPt_bAuthTqMaxEstimSIP_C;
   s32LocalFirstDiff = (sint32)( s16LocalCoPt_tqIdcAirCord_nCross
                               - s16LocalTqCmp_tqSumLossCmp);

   s32LocalSecondDiff = (sint32)(CoPt_tqThdAcvTqMaxEstim_C * 16);
   s32LocalSecondDiff = CoPt_tqAirLimEstim - s32LocalSecondDiff;

   if (s32LocalFirstDiff <= s32LocalSecondDiff)
   {
      CoPt_bAcvTqMaxEstimTq_MP = 1;
   }
   else
   {
      CoPt_bAcvTqMaxEstimTq_MP = 0;
   }

   /* Pilotage du couple ESP en ASR */
   if (u8LocalCha_stTqReq == 5)
   {
      CoPt_bASR = 1;
   }
   else
   {
      CoPt_bASR = 0;
   }

   if (  (CoPt_bAcvTqMaxEstimTq_MP != 0)
      && (  (  (bLocalCoPt_bSIPBuf != 0)
            && (CoPt_bAuthTqMaxEstimSIP != 0))
         || (CoPt_bASR != 0)))
   {
      bLocalSet = 1;
   }
   else
   {
      bLocalSet = 0;
   }

   if (  (TQESTMAX_u8CoPtfacTqMaxEstimPrev == 0)
      && (TQESTMAX_u8CoPfacTqMaxEstimPrev2 != 0))
   {
      bLocalReset = 1;
   }
   else
   {
      bLocalReset = 0;
   }

   if (  (bLocalReset == 0)
      && (  (bLocalSet != 0)
         || (bLocalCoPt_bAcvTqMaxEstimSIP != 0)))
   {
      VEMS_vidSET(CoPt_bAcvTqMaxEstimSIP, 1);
   }
   else
   {
      VEMS_vidSET(CoPt_bAcvTqMaxEstimSIP, 0);
   }
   TQESTMAX_u8CoPfacTqMaxEstimPrev2 =
      (uint8)MATHSRV_udtMIN(TQESTMAX_u8CoPtfacTqMaxEstimPrev, 200);
   TQESTMAX_u8CoPtfacTqMaxEstimPrev = (uint8)MATHSRV_udtMIN(CoPt_facTqMaxEstim,
                                                            200);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQESTMAX_vidCalcul_gain_filtrage                           */
/* !Description :  A l’activation de la demande de filtrage, le facteur       */
/*                 converge vers 1 via une rampe calibrable. Lorsque les      */
/*                 interventions BV et ESP sont terminées, le facteur converge*/
/*                 vers 0 via une rampe calibrable.                           */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_04747_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoPt_bAcvTqMaxEstimSIP;                                     */
/*  input boolean CoPt_bSIPBuf;                                               */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 Copt_nEngTqMaxEstimX_A[10];                                  */
/*  input boolean CoPt_bAuthTqMaxEstimSIP;                                    */
/*  input boolean CoPt_bASR;                                                  */
/*  input boolean TQESTMAX_bRSOutput;                                         */
/*  input uint8 CoPt_facAcvTqMaxEstim_T[10];                                  */
/*  input uint8 CoPt_facDeacTqMaxEstim_T[10];                                 */
/*  input sint16 CoPt_stepFacTqMaxEstim_MP;                                   */
/*  input uint8 CoPt_facTqMaxEstim;                                           */
/*  output boolean TQESTMAX_bRSOutput;                                        */
/*  output sint16 CoPt_stepFacTqMaxEstim_MP;                                  */
/*  output uint8 CoPt_facTqMaxEstim;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQESTMAX_vidCalcul_gain_filtrage(void)
{
   boolean bLocalCoPt_bAcvTqMaxEstimSIP;
   boolean bLocalCoPt_bSIPBuf;
   uint8   u8LocalCoPt_facDeacTqMaxEstim;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalCalcPara;
   sint16  s16LocalSum;
   sint16  s16LocalCoPtStepFacTqMaxEstimMP;


   VEMS_vidGET(CoPt_bAcvTqMaxEstimSIP, bLocalCoPt_bAcvTqMaxEstimSIP);
   VEMS_vidGET(CoPt_bSIPBuf, bLocalCoPt_bSIPBuf);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalExt_nEng = (uint16)(u16LocalExt_nEng / 10);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(Copt_nEngTqMaxEstimX_A,
                                                   u16LocalExt_nEng,
                                                   10);
   if (  (  (  (bLocalCoPt_bSIPBuf != 0)
            && (CoPt_bAuthTqMaxEstimSIP != 0))
         || (CoPt_bASR != 0))
      && (  (bLocalCoPt_bAcvTqMaxEstimSIP != 0)
         || (TQESTMAX_bRSOutput != 0)))
   {
      TQESTMAX_bRSOutput = 1;
      s16LocalCoPtStepFacTqMaxEstimMP =
         (sint16)MATHSRV_u8Interp1d(CoPt_facAcvTqMaxEstim_T, u16LocalCalcPara);
   }
   else
   {
      TQESTMAX_bRSOutput = 0;
      u8LocalCoPt_facDeacTqMaxEstim =
         MATHSRV_u8Interp1d(CoPt_facDeacTqMaxEstim_T, u16LocalCalcPara);
      s16LocalCoPtStepFacTqMaxEstimMP =
         (sint16)(u8LocalCoPt_facDeacTqMaxEstim - 200);
   }
   CoPt_stepFacTqMaxEstim_MP =
      (sint16)MATHSRV_udtMIN(s16LocalCoPtStepFacTqMaxEstimMP, 200);

   s16LocalSum = (sint16)(CoPt_stepFacTqMaxEstim_MP + CoPt_facTqMaxEstim);
   CoPt_facTqMaxEstim = (uint8)MATHSRV_udtCLAMP(s16LocalSum, 0, 200);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQESTMAX_vidActivation_Filtrage                            */
/* !Description :  Le filtrage hors changement de rapport sera activé sous    */
/*                 trois conditions.                                          */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_09_05545_007.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 CoPt_tqAirMaxGBx;                                            */
/*  input sint16 TqSys_tqCkEfcFilTrv;                                         */
/*  input boolean CoPt_bSIPBuf;                                               */
/*  input boolean CoPt_bPrepSIP;                                              */
/*  input sint16 TqRes_tqMaxRes;                                              */
/*  input sint16 CoPt_tqThdAcvEstim1_C;                                       */
/*  input sint16 CoPt_tqAirLimEstim;                                          */
/*  input sint16 CoPt_tqThdAcvEstim2_C;                                       */
/*  input boolean CoPt_bAcvTqResEstim_C;                                      */
/*  input boolean CoPt_bDeacInhPrepSIP_C;                                     */
/*  output boolean CoPt_bAcvTqMaxEstim;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQESTMAX_vidActivation_Filtrage(void)
{
   boolean bLocalCoPt_bSIPBuf;
   boolean bLocalCoPt_bPrepSIP;
   sint16  s16LocalCoPt_tqAirMaxGBx;
   sint16  s16LocalTqSys_tqCkEfcFilTrv;
   sint16  s16LocalTqRes_tqMaxRes;
   sint32  s32LocalSum;
   sint32  s32LocalDiff;


   VEMS_vidGET(CoPt_tqAirMaxGBx, s16LocalCoPt_tqAirMaxGBx);
   VEMS_vidGET(TqSys_tqCkEfcFilTrv, s16LocalTqSys_tqCkEfcFilTrv);
   VEMS_vidGET(CoPt_bSIPBuf, bLocalCoPt_bSIPBuf);
   VEMS_vidGET(CoPt_bPrepSIP, bLocalCoPt_bPrepSIP);
   VEMS_vidGET(TqRes_tqMaxRes, s16LocalTqRes_tqMaxRes);

   s32LocalDiff = (CoPt_tqThdAcvEstim1_C * 16);
   s32LocalDiff = (CoPt_tqAirLimEstim - s32LocalDiff);

   s32LocalSum = (CoPt_tqThdAcvEstim2_C * 16);
   s32LocalSum = (s16LocalTqSys_tqCkEfcFilTrv + s32LocalSum);

   if (CoPt_bAcvTqResEstim_C != 0)
   {
      s32LocalSum = (s32LocalSum - s16LocalTqRes_tqMaxRes);
   }
   if (  (s16LocalCoPt_tqAirMaxGBx <= s32LocalDiff)
      && (s16LocalCoPt_tqAirMaxGBx <= s32LocalSum)
      && (bLocalCoPt_bSIPBuf == 0)
      && (  (CoPt_bDeacInhPrepSIP_C != 0)
         || (bLocalCoPt_bPrepSIP == 0)))
   {
      VEMS_vidSET(CoPt_bAcvTqMaxEstim, 1);
   }
   else
   {
      VEMS_vidSET(CoPt_bAcvTqMaxEstim, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQESTMAX_vidCalculCplPotFiltre                             */
/* !Description :  Le couple potentiel déphasé est filtré en fonction du      */
/*                 régime moteur.                                             */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_09_05545_008.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoPt_bAcvTqMaxEstimSIP;                                     */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 CoPt_tqEfcAirMaxFil;                                         */
/*  input uint16 Copt_nEngTqMaxEstimX_A[10];                                  */
/*  input sint16 CoPt_tqEfcAirMaxFil1;                                        */
/*  input uint16 CoPt_tqFilTqMaxEstimY_A[10];                                 */
/*  input uint8 CoPt_facFilTqMaxEstim_M[10][10];                              */
/*  input sint16 CoPt_tqEfcAirEstimDly;                                       */
/*  input sint16 EngLim_tqEfcEngCurMax;                                       */
/*  output sint16 CoPt_tqEfcAirMaxFil1;                                       */
/*  output sint16 CoPt_tqEfcAirMaxFil;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQESTMAX_vidCalculCplPotFiltre(void)
{
   boolean bLocalCoPt_bAcvTqMaxEstimSIP;
   uint8   u8LocalInterp2DOutput;
   uint16  u16LocalCalcParaX;
   uint16  u16LocalCalcParaY;
   uint16  u16LocalExt_nEng;
   sint16  s16LocalCoPtTqEfcAirMaxFil;
   sint16  s16LocalEngLim_tqEfcEngCurMax;
   sint32  s32LocalCoPtTqEfcAirMaxFil;


   VEMS_vidGET(CoPt_bAcvTqMaxEstimSIP, bLocalCoPt_bAcvTqMaxEstimSIP);

   if (bLocalCoPt_bAcvTqMaxEstimSIP != 0)
   {
      VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

      CoPt_tqEfcAirMaxFil1 = (sint16)MATHSRV_udtCLAMP(CoPt_tqEfcAirMaxFil,
                                                      -32000,
                                                      32000);

      u16LocalExt_nEng = (uint16)(u16LocalExt_nEng / 10);
      u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(Copt_nEngTqMaxEstimX_A,
                                                       u16LocalExt_nEng,
                                                       10);

      u16LocalCalcParaY = (uint16)((CoPt_tqEfcAirMaxFil1 + 32000) / 16);
      u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(CoPt_tqFilTqMaxEstimY_A,
                                                       u16LocalCalcParaY,
                                                       10);

      u8LocalInterp2DOutput = MATHSRV_u8Interp2d(&CoPt_facFilTqMaxEstim_M[0][0],
                                                 u16LocalCalcParaX,
                                                 u16LocalCalcParaY,
                                                 10);

      s32LocalCoPtTqEfcAirMaxFil = CoPt_tqEfcAirEstimDly - CoPt_tqEfcAirMaxFil1;
      s32LocalCoPtTqEfcAirMaxFil = s32LocalCoPtTqEfcAirMaxFil
                                 * u8LocalInterp2DOutput;

      s32LocalCoPtTqEfcAirMaxFil = s32LocalCoPtTqEfcAirMaxFil / 200;
      s32LocalCoPtTqEfcAirMaxFil = s32LocalCoPtTqEfcAirMaxFil
                                 + CoPt_tqEfcAirMaxFil1;

      CoPt_tqEfcAirMaxFil = (sint16)MATHSRV_udtCLAMP(s32LocalCoPtTqEfcAirMaxFil,
                                                     -32000,
                                                     32000);
   }
   else
   {
      VEMS_vidGET(EngLim_tqEfcEngCurMax, s16LocalEngLim_tqEfcEngCurMax);

      s16LocalCoPtTqEfcAirMaxFil =
         (sint16)MATHSRV_udtCLAMP(s16LocalEngLim_tqEfcEngCurMax,
                                  -32000,
                                  32000);
      CoPt_tqEfcAirMaxFil  = s16LocalCoPtTqEfcAirMaxFil;
      CoPt_tqEfcAirMaxFil1 = s16LocalCoPtTqEfcAirMaxFil;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQESTMAX_vidCalculCplPotEstime                             */
/* !Description :  Le couple max pris en compte dans la stratégie d’agrément  */
/*                 préventif transite entre le couple max moteur courant et   */
/*                 l’estimation de couple max avec le facteur de transition   */
/*                 calculé dans les fonctions précédentes.                    */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_09_05545_009.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 EngLim_tqEfcEngCurMax;                                       */
/*  input sint16 CoPt_tqEfcAirMaxFil;                                         */
/*  input uint8 CoPt_facTqMaxEstim;                                           */
/*  output sint16 CoPt_tqEfcAirMaxEstim;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQESTMAX_vidCalculCplPotEstime(void)
{
   sint16 s16LocalEngLim_tqEfcEngCurMax;
   sint16 s16LocalCoPtTqEfcAirMaxEstim;
   sint16 s16LocalMaxEstim;
   sint32 s32LocalFstProduct;
   sint32 s32LocalSndProduct;


   VEMS_vidGET(EngLim_tqEfcEngCurMax, s16LocalEngLim_tqEfcEngCurMax);

   s32LocalFstProduct = CoPt_tqEfcAirMaxFil * CoPt_facTqMaxEstim * 5;

   s16LocalMaxEstim = (sint16)(1000 - (CoPt_facTqMaxEstim * 5));
   s32LocalSndProduct = s16LocalMaxEstim * s16LocalEngLim_tqEfcEngCurMax;
   s32LocalSndProduct = (s32LocalFstProduct + s32LocalSndProduct) / 1000;

   s16LocalCoPtTqEfcAirMaxEstim = (sint16)MATHSRV_udtCLAMP(s32LocalSndProduct,
                                                           -32000,
                                                           32000);

   VEMS_vidSET(CoPt_tqEfcAirMaxEstim, s16LocalCoPtTqEfcAirMaxEstim);
}
/*------------------------------- end of file --------------------------------*/