/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IDLMGR                                                  */
/* !Description     : IDLMGR component                                        */
/*                                                                            */
/* !Module          : IDLMGR                                                  */
/* !Description     : GESTION DU RALENTI                                      */
/*                                                                            */
/* !File            : IDLMGR_FCT1.C                                           */
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
/*   1 / IDLMGR_vidInitOutput                                                 */
/*   2 / IDLMGR_vidMainTraiter_les_info                                       */
/*   3 / IDLMGR_vidTraiter_les_info                                           */
/*   4 / IDLMGR_vidActiver_ralenti                                            */
/*   5 / IDLMGR_vidTraiter_informations                                       */
/*   6 / IDLMGR_vidCalculer_couple_pertes                                     */
/*   7 / IDLMGR_vidCalc_couple_perte_comp                                     */
/*   8 / IDLMGR_vidCalc_pertes_embr_BVMP                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5010777 / 02                                        */
/* !OtherRefs   : CSMT_CGMT08_0003 / 2.9                                      */
/* !OtherRefs   : VEMS V02 ECU#063158                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/IDLMGR/IDLMGR_FCT$*/
/* $Revision::   1.22     $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IDLMGR.h"
#include "IDLMGR_L.h"
#include "IDLMGR_IM.h"
#include "GDGAR.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidInitOutput                                       */
/* !Description :  Fonction d'initialisation des parametres produits          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_nEngClc0;                                                */
/*  input uint16 IdlSys_tiTranCll_C;                                          */
/*  input uint16 IdlSys_tqIncCll_C;                                           */
/*  input sint16 TqCmp_tqSumLossCmp;                                          */
/*  input sint16 CoPt_tqMaxClu;                                               */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint16 IdlSys_tqMaxClu_A[8];                                        */
/*  input uint16 IdlSys_spdVehTqClu_A[4];                                     */
/*  input uint16 IdlSys_tqMaxClu_M[4][8];                                     */
/*  input sint16 IdlSys_tqMaxCluFil_MP;                                       */
/*  input uint16 IDLMGR_u16MeasuredIdlSysSpdVeh;                              */
/*  input uint16 IDLMGR_u16MeasuredEngSpdFilt;                                */
/*  input uint16 IdlSys_rGearRaw_MP;                                          */
/*  input uint16 IdlSys_rGear_MP;                                             */
/*  output boolean IdlSys_bAcvBrk;                                            */
/*  output boolean IdlSys_bAcvIdlCtl;                                         */
/*  output boolean IdlSys_bAcvIgMinSpc;                                       */
/*  output boolean IdlSys_bAuthInjCutOff;                                     */
/*  output boolean IdlSys_bIniIdlCtl;                                         */
/*  output uint16 IdlSys_nTarIdlDyn;                                          */
/*  output uint8 IdlSys_noGear;                                               */
/*  output uint16 IdlSys_tiTranCll;                                           */
/*  output sint16 IdlSys_tqIdcIdlIni;                                         */
/*  output sint16 IdlSys_tqIdcIdlIniAir;                                      */
/*  output sint16 IdlSys_tqIdcIdlStab;                                        */
/*  output uint16 IdlSys_tqIncCll;                                            */
/*  output sint16 IdlSys_tqLoss;                                              */
/*  output boolean IdlSys_bEnaIdl;                                            */
/*  output boolean IdlSys_bIniIdl;                                            */
/*  output boolean IDLMGR_bHystveh;                                           */
/*  output boolean IdlSys_bEngNOnIdl;                                         */
/*  output boolean IdlSys_bAuthInjCutOffTqMin;                                */
/*  output boolean IDLMGR_bNegHysVeh;                                         */
/*  output boolean IDLMGR_bTurnOffDelayOut;                                   */
/*  output boolean IDLMGR_bAcvAntiStallFilPrev;                               */
/*  output boolean IDLMGR_bAcvAntiStallFilSecPrev;                            */
/*  output uint16 IDLMGR_u16TurnOffDlyCnt;                                    */
/*  output boolean IDLMGR_bTurnOffDelayOut2;                                  */
/*  output boolean IDLMGR_bAcvIdlCtlPrev;                                     */
/*  output boolean IDLMGR_bAcvIdlCtlSecPrev;                                  */
/*  output uint16 IDLMGR_u16TurnOffDlyCnt2;                                   */
/*  output sint16 IdlSys_tqLossCmp;                                           */
/*  output sint32 IDLMGR_s32FiltredIdlSpdVehMem;                              */
/*  output sint16 IdlSys_tqMaxCluFil_MP;                                      */
/*  output sint32 IDLMGR_s32FiltredMaxCluFilMem;                              */
/*  output uint16 IdlSys_nEngFil1;                                            */
/*  output uint16 IdlSys_nEngFil2;                                            */
/*  output uint32 IDLMGR_u32FiltreEngFil1Mem;                                 */
/*  output uint32 IDLMGR_u32FiltreEngFil2Mem;                                 */
/*  output uint16 IDLMGR_u16MeasuredIdlSysSpdVeh;                             */
/*  output uint32 IDLMGR_u32FiltredIdlSpdVehMem;                              */
/*  output uint16 IDLMGR_u16MeasuredEngSpdFilt;                               */
/*  output uint32 IDLMGR_u32FiltredEngSpdMem;                                 */
/*  output uint16 IdlSys_rGearRaw_MP;                                         */
/*  output uint16 IdlSys_rGear_MP;                                            */
/*  output uint32 IDLMGR_u32FiltredSysRGearMem;                               */
/*  output sint16 IdlSys_nGrdRaw_MP;                                          */
/*  output sint16 IdlSys_nGrdEng;                                             */
/*  output sint32 IDLMGR_s32FiltredIdlSysaEngMem;                             */
/*  output boolean IdlSys_bAcvIdlCtlDyn;                                      */
/*  output uint8 IdlSys_idxFilGain;                                           */
/*  output boolean IdlSys_bAuthIdlCtlStEng;                                   */
/*  output boolean IdlSys_bSpcTarIdlDyn_MP;                                   */
/*  output boolean IDLMGR_bBasculeRS;                                         */
/*  output boolean IDLMGR_bAcvIdlCrawlPrev;                                   */
/*  output boolean IDLMGR_bAcvIdlCtlDynPrev;                                  */
/*  output sint32 IDLMGR_s32nEngAddPrev[2];                                   */
/*  output uint16 IDLMGR_u16FilAEngInPrev;                                    */
/*  output uint16 IDLMGR_u16InputFilNEng1Prev;                                */
/*  output uint16 IDLMGR_u16InputFilNEng2Prev;                                */
/*  output uint16 IDLMGR_u16InputLossCmpMapPrev;                              */
/*  output uint16 IDLMGR_u16SwitchPrev;                                       */
/*  output uint16 IDLMGR_u16TiFilTqMaxCluPrev;                                */
/*  output uint8 IdlSys_noGearPrev;                                           */
/*  output uint8 IDLMGR_u8IdxIdlCtlModPrev;                                   */
/*  output uint16 IdlSys_nTarIdlDynPrev;                                      */
/*  output uint16 IDLMGR_u16MltpSwRmpTranStep;                                */
/*  output uint16 IDLMGR_u16MltpSwRmpTrFilGrdStep;                            */
/*  output uint16 IDLMGR_u16InTarIdlPrev;                                     */
/*  output uint16 IDLMGR_IdlSys_nTarIdlDynPrev;                               */
/*  output boolean IDLMGR_bIniIdlReqPrev;                                     */
/*  output boolean IDLMGR_bTqSysAcvPrev;                                      */
/*  output boolean IDLMGR_bAcvStrtTqSysPrev;                                  */
/*  output st1600 IDLMGR_stCutInj;                                            */
/*  output uint16 IdlSys_nAuthInjCutOff;                                      */
/*  output st14 IDLMGR_stRegSup;                                              */
/*  output uint16 IdlSys_rTranIdlDyn_MP;                                      */
/*  output uint16 IdlSys_nEngEstim[2];                                        */
/*  output uint8 IDLMGR_u8IdlSysIdxFilGainPrev;                               */
/*  output uint8 IDLMGR_u8OldIdxFilGainPrev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidInitOutput(void)
{
   uint16 u16LocalExt_nEngClc0;
   uint16 u16LocalMeasValue;
   uint16 u16LocalCalcPara1;
   uint16 u16LocalCoPt_tqMaxClu;
   uint16 u16LocalCoPTqMaxCluInterp;
   uint16 u16LocalVeh_spdVeh;
   uint16 u16LocalIdlSys_tqIncCll;
   uint16 u16LocalIdlSys_tiTranCll;
   uint16 u16LocalCalcPara2;
   sint16 s16LocalTqCmp_tqSumLossCmp;
   sint16 s16LocalCoPttqMaxClu;
   sint16 s16LocalCoPt_tqMaxClu;
   sint32 s32LocalMeasValue;
   uint32 u32LocalIdlSys_rGearRaw_MP;


   VEMS_vidGET(Ext_nEngClc0, u16LocalExt_nEngClc0);
  /* initialisations des sorties */
   VEMS_vidSET(IdlSys_bAcvBrk, 0);
   VEMS_vidSET(IdlSys_bAcvIdlCtl, 0);
   VEMS_vidSET(IdlSys_bAcvIgMinSpc, 0);
   VEMS_vidSET(IdlSys_bAuthInjCutOff, 0);
   VEMS_vidSET(IdlSys_bIniIdlCtl, 0);
   VEMS_vidSET(IdlSys_nTarIdlDyn, 0);
   VEMS_vidSET(IdlSys_noGear, 0);
   u16LocalIdlSys_tiTranCll = (uint16)MATHSRV_udtMIN(IdlSys_tiTranCll_C, 500);
   VEMS_vidSET(IdlSys_tiTranCll, u16LocalIdlSys_tiTranCll);
   VEMS_vidSET(IdlSys_tqIdcIdlIni, 0);
   VEMS_vidSET(IdlSys_tqIdcIdlIniAir, 0);
   VEMS_vidSET(IdlSys_tqIdcIdlStab, 0);
   u16LocalIdlSys_tqIncCll = (uint16)MATHSRV_udtMIN(IdlSys_tqIncCll_C, 32000);
   VEMS_vidSET(IdlSys_tqIncCll, u16LocalIdlSys_tqIncCll);
   VEMS_vidSET(IdlSys_tqLoss, 0);

   /*initialisation hyst*/
   VEMS_vidSET(IdlSys_bEnaIdl, 1);
   IdlSys_bIniIdl = 0;
   IDLMGR_bHystveh = 1;
   IdlSys_bEngNOnIdl = 0;
   IdlSys_bAuthInjCutOffTqMin = 1;
   IDLMGR_bNegHysVeh = 1;

  /*initialisation turnoff*/
   IDLMGR_bTurnOffDelayOut = 0;
   IDLMGR_bAcvAntiStallFilPrev = 0;
   IDLMGR_bAcvAntiStallFilSecPrev = 0;
   IDLMGR_u16TurnOffDlyCnt = 0;
   IDLMGR_bTurnOffDelayOut2 = 0;
   IDLMGR_bAcvIdlCtlPrev = 0;
   IDLMGR_bAcvIdlCtlSecPrev = 0;
   IDLMGR_u16TurnOffDlyCnt2 = 0;

   /*initialisation filter*/
   VEMS_vidGET(TqCmp_tqSumLossCmp, s16LocalTqCmp_tqSumLossCmp);
   s16LocalTqCmp_tqSumLossCmp =
      (sint16)MATHSRV_udtCLAMP(s16LocalTqCmp_tqSumLossCmp, -32000, 32000);
   IdlSys_tqLossCmp = s16LocalTqCmp_tqSumLossCmp;
   IDLMGR_s32FiltredIdlSpdVehMem = (sint32)(s16LocalTqCmp_tqSumLossCmp * 65536);
   VEMS_vidGET(CoPt_tqMaxClu, s16LocalCoPt_tqMaxClu);
   s16LocalCoPttqMaxClu = (sint16)((sint32)(s16LocalCoPt_tqMaxClu + 32000) / 4);
   u16LocalCoPt_tqMaxClu = (uint16)MATHSRV_udtMAX(s16LocalCoPttqMaxClu, 0);
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
   u16LocalVeh_spdVeh = (uint16)((u16LocalVeh_spdVeh + 16) / 32);
   u16LocalCalcPara2 = MATHSRV_u16CalcParaIncAryU16(IdlSys_tqMaxClu_A,
                                                    u16LocalCoPt_tqMaxClu,
                                                    8);
   u16LocalCalcPara1 = MATHSRV_u16CalcParaIncAryU16(IdlSys_spdVehTqClu_A,
                                                    u16LocalVeh_spdVeh,
                                                    4);
   u16LocalCoPTqMaxCluInterp = MATHSRV_u16Interp2d(&IdlSys_tqMaxClu_M[0][0],
                                                   u16LocalCalcPara1,
                                                   u16LocalCalcPara2,
                                                   8);
   s32LocalMeasValue = (sint32)(u16LocalCoPTqMaxCluInterp - 8000);
   IdlSys_tqMaxCluFil_MP = (sint16)MATHSRV_udtMIN(s32LocalMeasValue, 32000);
   IDLMGR_s32FiltredMaxCluFilMem = (sint32)(65536 * IdlSys_tqMaxCluFil_MP);

   u16LocalMeasValue = (uint16)MATHSRV_udtMIN(u16LocalExt_nEngClc0, 32000);
   IdlSys_nEngFil1 = u16LocalMeasValue;
   IdlSys_nEngFil2 = u16LocalMeasValue;
   IDLMGR_u32FiltreEngFil1Mem = (uint32)(u16LocalMeasValue * 65536);
   IDLMGR_u32FiltreEngFil2Mem = (uint32)(u16LocalMeasValue * 65536);
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
   IDLMGR_u16MeasuredIdlSysSpdVeh =
      (uint16)MATHSRV_udtMIN(u16LocalVeh_spdVeh, 64000);
   IDLMGR_u32FiltredIdlSpdVehMem =
      (IDLMGR_u16MeasuredIdlSysSpdVeh * (uint32)65536);
   IDLMGR_u16MeasuredEngSpdFilt =
      (uint16)MATHSRV_udtMIN(u16LocalExt_nEngClc0, 32000);
   IDLMGR_u32FiltredEngSpdMem = (IDLMGR_u16MeasuredEngSpdFilt * (uint32)65536);
   if (IDLMGR_u16MeasuredEngSpdFilt != 0)
   {
      u32LocalIdlSys_rGearRaw_MP =(uint32)( ( IDLMGR_u16MeasuredIdlSysSpdVeh
                                            * 256)
                                          / IDLMGR_u16MeasuredEngSpdFilt);
   }
   else
   {
      u32LocalIdlSys_rGearRaw_MP = 820;
   }
   IdlSys_rGearRaw_MP = (uint16)MATHSRV_udtMIN(u32LocalIdlSys_rGearRaw_MP, 820);
   IdlSys_rGear_MP = IdlSys_rGearRaw_MP;
   IDLMGR_u32FiltredSysRGearMem = (uint32)(IdlSys_rGear_MP * 65536);
   IdlSys_nGrdRaw_MP = 0;
   IdlSys_nGrdEng = 0;
   IDLMGR_s32FiltredIdlSysaEngMem = 0;
  /*basculeRS*/
   IdlSys_bAcvIdlCtlDyn = 0;
   IdlSys_idxFilGain = 0;
   IdlSys_bAuthIdlCtlStEng = 0;
   IdlSys_bSpcTarIdlDyn_MP = 0;
   IDLMGR_bBasculeRS = 0;
  /* Internal variables previous */
   IDLMGR_bAcvIdlCrawlPrev = 0;
   IDLMGR_bAcvIdlCtlDynPrev = 0;
   IDLMGR_s32nEngAddPrev[0] = 0;
   IDLMGR_s32nEngAddPrev[1] = 0;
   IDLMGR_u16FilAEngInPrev = 8000;
   IDLMGR_u16InputFilNEng1Prev = 0;
   IDLMGR_u16InputFilNEng2Prev = 0;
   IDLMGR_u16InputLossCmpMapPrev = 8000;
   IDLMGR_u16SwitchPrev = 0;
   IDLMGR_u16TiFilTqMaxCluPrev = 8000;
   IdlSys_noGearPrev = 0;
   IDLMGR_u8IdxIdlCtlModPrev = 1;
   IdlSys_nTarIdlDynPrev = 0;
   IDLMGR_u16MltpSwRmpTranStep = 0;
   IDLMGR_u16MltpSwRmpTrFilGrdStep = 0;
   IDLMGR_u16InTarIdlPrev = 3000;
   IDLMGR_IdlSys_nTarIdlDynPrev = 3000;
   IDLMGR_bIniIdlReqPrev = 0;
   IDLMGR_bTqSysAcvPrev = 0;
   IDLMGR_bAcvStrtTqSysPrev = 0;

   /* States machines initialization's */
   IDLMGR_stCutInj = IDLMGR_u8INHIB_CUT_INJ;
   IdlSys_nAuthInjCutOff = 8000;
   IDLMGR_stRegSup = REGULATOR_OFF;

   /*rate limiter */
   IdlSys_rTranIdlDyn_MP = 0;
   IdlSys_nEngEstim[0] = 0;
   IdlSys_nEngEstim[1] = 0;
   IDLMGR_u8IdlSysIdxFilGainPrev = 0;
   IDLMGR_u8OldIdxFilGainPrev = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidMainTraiter_les_info                             */
/* !Description :  Cette fonction contient le traitement ,lecalcul et la      */
/*                 gestion du ralenti.                                        */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_001.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IDLMGR_vidTraiter_les_info();                            */
/*  extf argret void IDLMGR_vidCalculer_ralenti();                            */
/*  extf argret void IDLMGR_vidCalculer_valeurs_replis();                     */
/*  extf argret void IDLMGR_vidBoucler_stuct_couple();                        */
/*  input uint8 IdlSys_idxIdlCtlMod;                                          */
/*  input boolean IdlSys_bEnaIdl;                                             */
/*  input uint16 IdlSys_nTarIdlDyn;                                           */
/*  input boolean IdlSys_bAcvIdlCtl;                                          */
/*  input boolean IDLMGR_bAcvIdlCtlPrev;                                      */
/*  output uint8 IDLMGR_u8IdxIdlCtlModPrev;                                   */
/*  output uint16 IdlSys_nTarIdlDynPrev;                                      */
/*  output uint16 IDLMGR_IdlSys_nTarIdlDynPrev;                               */
/*  output boolean IDLMGR_bAcvIdlCtlSecPrev;                                  */
/*  output boolean IDLMGR_bAcvIdlCtlPrev;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidMainTraiter_les_info(void)
{
   boolean bLocalIdlSys_bEnaIdl;
   boolean bLocalIdlSys_bAcvIdlCtl;
   uint8   u8LocalIdlSys_idxIdlCtlMod;
   uint16  u16LocalIdlSys_nTarIdlDyn;


   VEMS_vidGET(IdlSys_idxIdlCtlMod, u8LocalIdlSys_idxIdlCtlMod);
   IDLMGR_vidTraiter_les_info();
   VEMS_vidGET(IdlSys_bEnaIdl, bLocalIdlSys_bEnaIdl);
   if (bLocalIdlSys_bEnaIdl != 0)
   {
      IDLMGR_vidCalculer_ralenti();
   }
   else
   {
      IDLMGR_vidCalculer_valeurs_replis();
   }
   IDLMGR_u8IdxIdlCtlModPrev =
      (uint8)MATHSRV_udtCLAMP(u8LocalIdlSys_idxIdlCtlMod, 1, 4);

   /*calc previous of IdlSys_nTarIdlDyn */
   VEMS_vidGET(IdlSys_nTarIdlDyn, u16LocalIdlSys_nTarIdlDyn);
   u16LocalIdlSys_nTarIdlDyn =
      (uint16)MATHSRV_udtMIN(u16LocalIdlSys_nTarIdlDyn, 32000);
   IdlSys_nTarIdlDynPrev = u16LocalIdlSys_nTarIdlDyn;
   IDLMGR_IdlSys_nTarIdlDynPrev = u16LocalIdlSys_nTarIdlDyn;

   /*calc previous Trigger of timer  */
   VEMS_vidGET(IdlSys_bAcvIdlCtl, bLocalIdlSys_bAcvIdlCtl);
   IDLMGR_bAcvIdlCtlSecPrev = IDLMGR_bAcvIdlCtlPrev;
   IDLMGR_bAcvIdlCtlPrev = bLocalIdlSys_bAcvIdlCtl;
   IDLMGR_vidBoucler_stuct_couple();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidTraiter_les_info                                 */
/* !Description :  Cette fonction permet de traiter les signaux d’entrée pour */
/*                 le ralenti en cas de défaut et de calculer des signaux     */
/*                 nécessaires à la gestion du ralenti.                       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IDLMGR_vidActiver_ralenti();                             */
/*  extf argret void IDLMGR_vidTraiter_informations();                        */
/*  extf argret void IDLMGR_vidCalculer_couple_pertes();                      */
/*  extf argret void IDLMGR_vidCalculer_info_regime();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidTraiter_les_info(void)
{
   IDLMGR_vidActiver_ralenti();
   IDLMGR_vidTraiter_informations();
   IDLMGR_vidCalculer_couple_pertes();
   IDLMGR_vidCalculer_info_regime();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidActiver_ralenti                                  */
/* !Description :  Cette fonctiondétermine l’activation des calculs des       */
/*                 fonctions de la gestion ralenti suivant des seuils de      */
/*                 régime.Au dessus d’un seuil de régime, les calculs sont    */
/*                 stoppés pour économiser de la charge sur le calculateur.   */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_nEngClc0;                                                */
/*  input boolean IdlSys_bEnaIdl;                                             */
/*  input uint16 IdlSys_nThdHiEnaIdl_C;                                       */
/*  input uint16 IdlSys_nThdLoEnaIdl_C;                                       */
/*  output boolean IdlSys_bIniIdl;                                            */
/*  output boolean IdlSys_bEnaIdl;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidActiver_ralenti(void)
{
   boolean bLocalIdlSys_bEnaIdl;
   boolean bLocalIdlSys_bEnaIdlPrev;
   uint16  u16LocalExt_nEngClc0;
   uint32  u32LocalnThdHiEnaIdl;
   uint32  u32LocalnThdLoEnaIdl;


   VEMS_vidGET(Ext_nEngClc0, u16LocalExt_nEngClc0);
   VEMS_vidGET(IdlSys_bEnaIdl, bLocalIdlSys_bEnaIdlPrev);
   /*SchmittTrigger*/

   u32LocalnThdHiEnaIdl = (uint32)(IdlSys_nThdHiEnaIdl_C * 4);
   u32LocalnThdLoEnaIdl = (uint32)(IdlSys_nThdLoEnaIdl_C * 4);

   if (u16LocalExt_nEngClc0 >= u32LocalnThdHiEnaIdl)
   {
      bLocalIdlSys_bEnaIdl = 0;
   }
   else
   {
      if (u16LocalExt_nEngClc0 <= u32LocalnThdLoEnaIdl)
      {
         bLocalIdlSys_bEnaIdl = 1;
      }
      else
      {
         bLocalIdlSys_bEnaIdl = bLocalIdlSys_bEnaIdlPrev;
      }
   }
   if (  (bLocalIdlSys_bEnaIdl != 0)
      && (bLocalIdlSys_bEnaIdlPrev == 0))
   {
      IdlSys_bIniIdl = 1;
   }
   else
   {
      IdlSys_bIniIdl = 0;
   }
   VEMS_vidSET(IdlSys_bEnaIdl, bLocalIdlSys_bEnaIdl);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidTraiter_informations                             */
/* !Description :  Ce bloc de traitement des informations permet de traiter   */
/*                 les signaux d’entrée pour le ralenti en cas de défaut et de*/
/*                 calculer des signaux nécessaires à la gestion du ralenti   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_004.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoPt_bAcvIdlCrawl;                                          */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input boolean CoPt_bAcvAntiStallFil;                                      */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input uint8 IdlSys_noGear;                                                */
/*  input uint8 CoPt_stCpl;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input boolean IDLMGR_bAcvAntiStallFilPrev;                                */
/*  input boolean IDLMGR_bAcvAntiStallFilSecPrev;                             */
/*  input uint8 IdlSys_tiAuthAntiStallAT_C;                                   */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input uint16 IDLMGR_u16TurnOffDlyCnt;                                     */
/*  input boolean IDLMGR_bTurnOffDelayOut;                                    */
/*  input uint8 IdlSys_spdVehThdLo_C;                                         */
/*  input uint8 IdlSys_spdVehThdHi_C;                                         */
/*  input boolean IDLMGR_bHystveh;                                            */
/*  input boolean IdlSys_bBrkDftVal_C;                                        */
/*  input boolean CoBrk_bAcvBrk;                                              */
/*  input boolean IdlSys_bAcvIdlCrawl;                                        */
/*  input uint8 IdlSys_spdVehRvsThdHi_C;                                      */
/*  input uint8 IdlSys_spdVehRvsThdLo_C;                                      */
/*  input boolean IDLMGR_bNegHysVeh;                                          */
/*  input boolean CoPt_bTqTx;                                                 */
/*  input uint8 CoPt_stGSTyp;                                                 */
/*  input uint8 IdlSys_stGSTyp_T[6];                                          */
/*  input uint8 CoPt_stGearRat;                                               */
/*  input boolean IdlSys_bStDriv_M[3][4];                                     */
/*  input boolean IdlSys_bStCpl_T[4];                                         */
/*  input uint8 IdlSys_noGear_T[8];                                           */
/*  input uint16 IdlSys_jVeh_T[8];                                            */
/*  input boolean IdlSys_bRvs_MP;                                             */
/*  input boolean IdlSys_bCfTEng_C;                                           */
/*  input sint16 Ext_tOilMes;                                                 */
/*  input sint16 Ext_tCoMes;                                                  */
/*  output boolean IDLMGR_bTurnOffDelayOut;                                   */
/*  output uint16 IDLMGR_u16TurnOffDlyCnt;                                    */
/*  output boolean IdlSys_bAcvAntiStallAT;                                    */
/*  output boolean IDLMGR_bHystveh;                                           */
/*  output boolean IdlSys_bAcvBrk;                                            */
/*  output boolean IDLMGR_bAcvIdlCrawlPrev;                                   */
/*  output boolean IdlSys_bAcvIdlCrawl;                                       */
/*  output uint8 IdlSys_noGearPrev;                                           */
/*  output boolean IDLMGR_bNegHysVeh;                                         */
/*  output boolean IdlSys_bRvs_MP;                                            */
/*  output uint8 IdlSys_noGear;                                               */
/*  output uint16 IdlSys_jVeh;                                                */
/*  output sint16 IdlSys_tEng;                                                */
/*  output boolean IDLMGR_bAcvAntiStallFilSecPrev;                            */
/*  output boolean IDLMGR_bAcvAntiStallFilPrev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidTraiter_informations(void)
{
   boolean bLocalAcvBrk;
   boolean bLocalCoBrk_bAcvBrk;
   boolean bLocalCoPt_bTqTx;
   boolean bLocalCoPt_bAcvIdlCrawl;
   boolean bLocalCoPt_bAcvAntiStallFil;
   boolean bLocalIdlSys_bAcvBrk;
   boolean bLocalnoEgdGearCord;
   uint8   u8LocalCoPt_noEgdGearCord;
   uint8   u8LocalExt_stGBxCf;
   uint8   u8LocalCoPt_stCpl;
   uint8   u8LocalIdlSys_noGear;
   uint8   u8LocalExt_tiTDC;
   uint8   u8LocalCoPt_stGSTyp;
   uint8   u8LocalCoPt_stGearRat;
   uint8   u8LocalIdlSys_stGSTyp;
   uint16  u16LocalIdlSys_jVeh;
   uint16  u16LocalTurnOffDlyCnt;
   uint16  u16LocalVeh;
   uint16  u16LocalspdVeh;
   uint16  u16LocalVeh_spdVeh;
   sint16  s16LocalExt_tCoMes;
   sint16  s16LocalExt_tOilMes;
   sint32  s32LocalIdlSys_tEng;


   /*calculer IdlSys_bAcvAntiStallAT*/
   VEMS_vidGET(CoPt_bAcvIdlCrawl, bLocalCoPt_bAcvIdlCrawl);
   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   VEMS_vidGET(CoPt_bAcvAntiStallFil, bLocalCoPt_bAcvAntiStallFil);
   VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);
   VEMS_vidGET(IdlSys_noGear, u8LocalIdlSys_noGear);
   VEMS_vidGET(CoPt_stCpl, u8LocalCoPt_stCpl);
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);

   if (  (bLocalCoPt_bAcvAntiStallFil != 0)
      && (IDLMGR_bAcvAntiStallFilPrev == 0))
   {
      IDLMGR_bTurnOffDelayOut = 1;
   }
   else
   {
      if (  (IDLMGR_bAcvAntiStallFilPrev != 0)
         && (IDLMGR_bAcvAntiStallFilSecPrev == 0))
      {
         u16LocalTurnOffDlyCnt = (uint16)( ( IdlSys_tiAuthAntiStallAT_C
                                           * 125)
                                         / 4);
         IDLMGR_u16TurnOffDlyCnt =
            (uint16)MATHSRV_udtMIN(u16LocalTurnOffDlyCnt, 5000);
      }
      else
      {
         VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
         if (IDLMGR_u16TurnOffDlyCnt > u8LocalExt_tiTDC)
         {
            u16LocalTurnOffDlyCnt = (uint16)( IDLMGR_u16TurnOffDlyCnt
                                            - u8LocalExt_tiTDC);
            IDLMGR_u16TurnOffDlyCnt =
               (uint16)MATHSRV_udtMIN(u16LocalTurnOffDlyCnt, 5000);
         }
         else
         {
            IDLMGR_u16TurnOffDlyCnt = 0;
         }
      }
      if (IDLMGR_u16TurnOffDlyCnt != 0)
      {
         IDLMGR_bTurnOffDelayOut = 1;
      }
      else
      {
         IDLMGR_bTurnOffDelayOut = 0;
      }
   }
   if (  (u8LocalExt_stGBxCf != 0)
      && (bLocalCoPt_bAcvAntiStallFil != 0)
      && (IDLMGR_bTurnOffDelayOut != 0))
   {
      IdlSys_bAcvAntiStallAT = 1;
   }
   else
   {
      IdlSys_bAcvAntiStallAT = 0;
   }
   /*calculer IdlSys_bAcvBrk*/

   u16LocalVeh = (uint16)(32 * IdlSys_spdVehThdLo_C);
   if (u16LocalVeh_spdVeh <= u16LocalVeh)
   {
      IDLMGR_bHystveh = 0;
   }
   else
   {
      u16LocalVeh = (uint16)(32 * IdlSys_spdVehThdHi_C);
      if (u16LocalVeh_spdVeh >= u16LocalVeh)
      {
         IDLMGR_bHystveh = 1;
      }
   }

   if (IDLMGR_bHystveh != 0)
   {
      bLocalAcvBrk = GDGAR_bGetFRM(FRM_FRM_ACVBRK);
      if (bLocalAcvBrk != 0)
      {
         bLocalIdlSys_bAcvBrk = IdlSys_bBrkDftVal_C;
         VEMS_vidSET(IdlSys_bAcvBrk, bLocalIdlSys_bAcvBrk);
      }
      else
      {
         VEMS_vidGET(CoBrk_bAcvBrk, bLocalCoBrk_bAcvBrk);
         VEMS_vidSET(IdlSys_bAcvBrk, bLocalCoBrk_bAcvBrk);
      }
   }
   else
   {
      VEMS_vidSET(IdlSys_bAcvBrk, 0);
   }/*2emme */
   IDLMGR_bAcvIdlCrawlPrev = IdlSys_bAcvIdlCrawl;
   if (  (bLocalCoPt_bAcvIdlCrawl != 0)
      && (u8LocalExt_stGBxCf == 2))
   {
      IdlSys_bAcvIdlCrawl = 1;
   }
   else
   {
      IdlSys_bAcvIdlCrawl = 0;
   }/*3emme */

   IdlSys_noGearPrev = u8LocalIdlSys_noGear;

   if (u8LocalCoPt_stCpl > 3 )
   {
      u8LocalCoPt_stCpl = 3;
   }
   /* NegHys */
   u16LocalspdVeh = (uint16)(32 * IdlSys_spdVehRvsThdHi_C);
   if (u16LocalVeh_spdVeh >= u16LocalspdVeh)
   {
      IDLMGR_bNegHysVeh = 0;
   }
   else
   {
      u16LocalspdVeh = (uint16)(32 * IdlSys_spdVehRvsThdLo_C);
      if (u16LocalVeh_spdVeh <= u16LocalspdVeh)
      {
         IDLMGR_bNegHysVeh = 1;
      }
   }
   /* Fin NegHys */
   if (  (u8LocalCoPt_noEgdGearCord == 7)
      && (IDLMGR_bNegHysVeh != 0))
   {
      IdlSys_bRvs_MP = 1;
   }
   else
   {
      IdlSys_bRvs_MP = 0;
   }

   if (u8LocalCoPt_noEgdGearCord > 7)
   {
      u8LocalCoPt_noEgdGearCord = 7;
   }

   if (u8LocalExt_stGBxCf != 0)
   {
      VEMS_vidGET(CoPt_bTqTx, bLocalCoPt_bTqTx);

      if (bLocalCoPt_bTqTx != 0)
      {
         VEMS_vidGET(CoPt_stGSTyp, u8LocalCoPt_stGSTyp);
         u8LocalCoPt_stGSTyp = (uint8)MATHSRV_udtMIN(u8LocalCoPt_stGSTyp, 5);
         u8LocalIdlSys_stGSTyp = IdlSys_stGSTyp_T[u8LocalCoPt_stGSTyp];
         switch(u8LocalIdlSys_stGSTyp)
         {
            case 0:
               bLocalnoEgdGearCord = 0;
               break;

            case 1:
               VEMS_vidGET(CoPt_stGearRat, u8LocalCoPt_stGearRat);
               u8LocalCoPt_stGearRat =
                  (uint8)MATHSRV_udtMIN(u8LocalCoPt_stGearRat, 2);
               bLocalnoEgdGearCord =
                  IdlSys_bStDriv_M[u8LocalCoPt_stGearRat][u8LocalCoPt_stCpl];
               break;

            case 2:
               bLocalnoEgdGearCord = IdlSys_bStCpl_T[u8LocalCoPt_stCpl];
               break;

            default :
               bLocalnoEgdGearCord = IdlSys_bStCpl_T[u8LocalCoPt_stCpl];
               break;
         }
      }
      else
      {
         bLocalnoEgdGearCord = 0;
      }

      if (bLocalnoEgdGearCord != 0)
      {
         u8LocalIdlSys_noGear = IdlSys_noGear_T[u8LocalCoPt_noEgdGearCord];
         u16LocalIdlSys_jVeh = IdlSys_jVeh_T[u8LocalCoPt_noEgdGearCord];
      }
      else
      {
         u8LocalIdlSys_noGear = IdlSys_noGear_T[0];
         u16LocalIdlSys_jVeh = IdlSys_jVeh_T[0];
      }
   }
   else
   {
      if (IdlSys_bRvs_MP != 0)
      {
         u8LocalIdlSys_noGear = IdlSys_noGear_T[0];
         u16LocalIdlSys_jVeh = IdlSys_jVeh_T[0];
      }
      else
      {
         u8LocalIdlSys_noGear = IdlSys_noGear_T[u8LocalCoPt_noEgdGearCord];
         u16LocalIdlSys_jVeh = IdlSys_jVeh_T[u8LocalCoPt_noEgdGearCord];
      }
   }
   u8LocalIdlSys_noGear = (uint8)MATHSRV_udtMIN(u8LocalIdlSys_noGear, 3);
   VEMS_vidSET(IdlSys_noGear, u8LocalIdlSys_noGear);
   IdlSys_jVeh = (uint16)MATHSRV_udtMIN(u16LocalIdlSys_jVeh, 6399);

   if (IdlSys_bCfTEng_C != 0)
   {
      VEMS_vidGET(Ext_tOilMes, s16LocalExt_tOilMes);
      s32LocalIdlSys_tEng = (sint32)((2 * s16LocalExt_tOilMes) / 5);
   }
   else
   {
      VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
      s32LocalIdlSys_tEng = (sint32)(4 * s16LocalExt_tCoMes);
   }
   IdlSys_tEng = (sint16)MATHSRV_udtCLAMP(s32LocalIdlSys_tEng, -200, 800);
   IDLMGR_bAcvAntiStallFilSecPrev = IDLMGR_bAcvAntiStallFilPrev;
   IDLMGR_bAcvAntiStallFilPrev = bLocalCoPt_bAcvAntiStallFil;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalculer_couple_pertes                           */
/* !Description :  Cete fonction calcule le couple de pertes déjà compensées  */
/*                 pour le ralenti.                                           */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IDLMGR_vidCalc_couple_perte_comp();                      */
/*  extf argret void IDLMGR_vidCalc_pertes_embr_BVMP();                       */
/*  extf argret void IDLMGR_vidCalc_pertes_convr_BVA();                       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 IdlSys_tqLossCmp;                                            */
/*  input sint16 IdlSys_tqMaxClu;                                             */
/*  input uint16 IdlSys_tqCnvLoss;                                            */
/*  output sint16 IdlSys_tqLoss;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalculer_couple_pertes(void)
{
   sint16 s16LocalIdlSysTqLoss;
   sint32 s32LocalIdlSysTqLoss;


   IDLMGR_vidCalc_couple_perte_comp();
   IDLMGR_vidCalc_pertes_embr_BVMP();
   IDLMGR_vidCalc_pertes_convr_BVA();

   s32LocalIdlSysTqLoss = (sint32)( IdlSys_tqLossCmp
                                  + IdlSys_tqMaxClu
                                  + IdlSys_tqCnvLoss);
   s16LocalIdlSysTqLoss =
      (sint16)MATHSRV_udtCLAMP(s32LocalIdlSysTqLoss, -32000, 32000);
   VEMS_vidSET(IdlSys_tqLoss, s16LocalIdlSysTqLoss);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalc_couple_perte_comp                           */
/* !Description :  Cette fontion filtre le couple de pertes compensées.       */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 TqCmp_tqSumLossCmp;                                          */
/*  input sint16 IdlSys_tqLossCmp;                                            */
/*  input uint16 IdlSys_tiFilTqLossCmp_A[4];                                  */
/*  input uint16 IDLMGR_u16InputLossCmpMapPrev;                               */
/*  input uint16 IdlSys_tiFilTqLossCmp_T[4];                                  */
/*  input boolean IdlSys_bEnaIdl;                                             */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input uint16 IdlSys_tiFilTqLossCmp_MP;                                    */
/*  input sint32 IDLMGR_s32FiltredIdlSpdVehMem;                               */
/*  output uint16 IdlSys_tiFilTqLossCmp_MP;                                   */
/*  output uint16 IDLMGR_u16InputLossCmpMapPrev;                              */
/*  output sint32 IDLMGR_s32FiltredIdlSpdVehMem;                              */
/*  output sint16 IdlSys_tqLossCmp;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalc_couple_perte_comp(void)
{
   boolean  bLocalIdlSys_bEnaIdl;
   uint8    u8LocalExt_tiTDC;
   uint16   u16LocalInputLossCmpMapPrev;
   uint16   u16LocalCalcPara;
   uint16   u16LocalCoPTqMaxCluInterp;
   sint16   s16LocalInputLossMapPrev;
   sint16   s16LocalTqCmp_tqSumLossCmp;
   sint16   s16LocalFiltredValue;
   sint16   s16LocalFiltredValuemem;
   uint32   u32LocalFilterGain;


   VEMS_vidGET(TqCmp_tqSumLossCmp, s16LocalTqCmp_tqSumLossCmp);
   s16LocalInputLossMapPrev = (sint16)( ( (sint32)( s16LocalTqCmp_tqSumLossCmp
                                                  - IdlSys_tqLossCmp)
                                        + 32000)
                                      / 4);
   u16LocalInputLossCmpMapPrev =
      (uint16)MATHSRV_udtMAX(s16LocalInputLossMapPrev, 0);

   u16LocalCalcPara =
      MATHSRV_u16CalcParaIncAryU16(IdlSys_tiFilTqLossCmp_A,
                                   IDLMGR_u16InputLossCmpMapPrev,
                                   4);
   u16LocalCoPTqMaxCluInterp = MATHSRV_u16Interp1d(IdlSys_tiFilTqLossCmp_T,
                                                   u16LocalCalcPara);
   IdlSys_tiFilTqLossCmp_MP =
      (uint16)MATHSRV_udtMIN(u16LocalCoPTqMaxCluInterp, 2048);
   IDLMGR_u16InputLossCmpMapPrev = u16LocalInputLossCmpMapPrev;
   VEMS_vidGET(IdlSys_bEnaIdl, bLocalIdlSys_bEnaIdl);

   if (bLocalIdlSys_bEnaIdl != 0)
   {
      VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
      u32LocalFilterGain =
         (uint32)((128 * u8LocalExt_tiTDC) + (IdlSys_tiFilTqLossCmp_MP * 125));
      if (  (u32LocalFilterGain == 0)
         || (IdlSys_tiFilTqLossCmp_MP == 0))
      {
         s16LocalFiltredValue = s16LocalTqCmp_tqSumLossCmp;
         s16LocalFiltredValuemem =
            (sint16)MATHSRV_udtCLAMP(s16LocalTqCmp_tqSumLossCmp, -32000, 32000);
         IDLMGR_s32FiltredIdlSpdVehMem =
            (sint32)(s16LocalFiltredValuemem * 65536);
      }
      else
      {
         u32LocalFilterGain = (uint32)( 8388608 * u8LocalExt_tiTDC)
                                      / u32LocalFilterGain;
         s16LocalFiltredValue =
            MATHSRV_s16FirstOrderFilterGu16((uint16)u32LocalFilterGain,
                                            &IDLMGR_s32FiltredIdlSpdVehMem,
                                            s16LocalTqCmp_tqSumLossCmp);
      }
   }
   else
   {
      s16LocalFiltredValue = s16LocalTqCmp_tqSumLossCmp;
      s16LocalFiltredValuemem =
         (sint16)MATHSRV_udtCLAMP(s16LocalTqCmp_tqSumLossCmp, -32000, 32000);
      IDLMGR_s32FiltredIdlSpdVehMem = (sint32)(65536 * s16LocalFiltredValuemem);
   }
   IdlSys_tqLossCmp =
      (sint16)MATHSRV_udtCLAMP(s16LocalFiltredValue, -32000, 32000);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalc_pertes_embr_BVMP                            */
/* !Description :  Cette fonction  filtre le couple prélevé par l’embrayage en*/
/*                 BVMP.                                                      */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 CoPt_tqMaxClu;                                               */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint16 IdlSys_tqMaxClu_A[8];                                        */
/*  input uint16 IdlSys_spdVehTqClu_A[4];                                     */
/*  input uint16 IdlSys_tqMaxClu_M[4][8];                                     */
/*  input sint16 IdlSys_tqMaxCluFil_MP;                                       */
/*  input uint16 IdlSys_tiFilTqMaxClu_A[4];                                   */
/*  input uint16 IDLMGR_u16TiFilTqMaxCluPrev;                                 */
/*  input uint16 IdlSys_tiFilTqMaxClu_T[4];                                   */
/*  input boolean IdlSys_bAcvIdlCrawl;                                        */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input uint16 IdlSys_tiFilTqMaxClu_MP;                                     */
/*  input sint32 IDLMGR_s32FiltredMaxCluFilMem;                               */
/*  output uint16 IdlSys_tiFilTqMaxClu_MP;                                    */
/*  output uint16 IDLMGR_u16TiFilTqMaxCluPrev;                                */
/*  output sint32 IDLMGR_s32FiltredMaxCluFilMem;                              */
/*  output sint16 IdlSys_tqMaxClu;                                            */
/*  output sint16 IdlSys_tqMaxCluFil_MP;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalc_pertes_embr_BVMP(void)
{
   uint8  u8LocalExt_tiTDC;
   uint16 u16LocalCoPt_tqMaxClu;
   uint16 u16LocalVeh_spdVeh;
   uint16 u16LocalInputTiFilTqMaxClu;
   uint16 u16LocalCalcPara1;
   uint16 u16LocalCalcPara2;
   uint16 u16LocalCalcPara;
   uint16 u16LocalCoPTqMaxCluInterp;
   uint16 u16LocalCoPTqMaxCluMP;
   sint16 s16LocalCoPt_tqMaxClu;
   sint16 s16LocalMeasValue;
   sint16 s16LocalIdlSys_tqMaxClu;
   sint16 s16LocalFiltredValue;
   sint32 s32LocalMeasValue;
   sint32 s32LocalInputTiFilTqMaxClu;
   sint32 s32LocalFiltredMaxCluFilMem;
   uint32 u32LocalFilterGain;


   VEMS_vidGET(CoPt_tqMaxClu, s16LocalCoPt_tqMaxClu);
   if (s16LocalCoPt_tqMaxClu >= 0)
   {
      s16LocalCoPt_tqMaxClu = (sint16)( ((s16LocalCoPt_tqMaxClu + 32000) + 2)
                                      / 4);
   }
   else
   {
      s16LocalCoPt_tqMaxClu = (sint16)( ((s16LocalCoPt_tqMaxClu + 32000) - 2)
                                      / 4);
   }
   u16LocalCoPt_tqMaxClu = (uint16)MATHSRV_udtMAX(s16LocalCoPt_tqMaxClu, 0);

   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
   u16LocalVeh_spdVeh = (uint16)((u16LocalVeh_spdVeh + 16) / 32);
   u16LocalCalcPara1 = MATHSRV_u16CalcParaIncAryU16(IdlSys_tqMaxClu_A,
                                                    u16LocalCoPt_tqMaxClu,
                                                    8);
   u16LocalCalcPara2 = MATHSRV_u16CalcParaIncAryU16(IdlSys_spdVehTqClu_A,
                                                    u16LocalVeh_spdVeh,
                                                    4);
   u16LocalCoPTqMaxCluInterp = MATHSRV_u16Interp2d(&IdlSys_tqMaxClu_M[0][0],
                                                   u16LocalCalcPara2,
                                                   u16LocalCalcPara1,
                                                   8);
   s32LocalInputTiFilTqMaxClu =
      (sint32)( (((u16LocalCoPTqMaxCluInterp - IdlSys_tqMaxCluFil_MP) + 2) / 4)
              + 6000);
   u16LocalInputTiFilTqMaxClu =
       (uint16)MATHSRV_udtMAX(s32LocalInputTiFilTqMaxClu, 0);

   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(IdlSys_tiFilTqMaxClu_A,
                                                   IDLMGR_u16TiFilTqMaxCluPrev,
                                                   4);
   u16LocalCoPTqMaxCluMP = MATHSRV_u16Interp1d(IdlSys_tiFilTqMaxClu_T,
                                               u16LocalCalcPara);
   IdlSys_tiFilTqMaxClu_MP =
      (uint16)MATHSRV_udtMIN(u16LocalCoPTqMaxCluMP, 2048);

   IDLMGR_u16TiFilTqMaxCluPrev = u16LocalInputTiFilTqMaxClu;

   s32LocalMeasValue = (sint32)(u16LocalCoPTqMaxCluInterp - 8000);
   s16LocalMeasValue = (sint16)MATHSRV_udtMIN(s32LocalMeasValue, 32767);
   if (IdlSys_bAcvIdlCrawl != 0)
   {
      VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
      u32LocalFilterGain = (uint32)( (128 * u8LocalExt_tiTDC)
                                   + (IdlSys_tiFilTqMaxClu_MP * 125));

      if (  (u32LocalFilterGain == 0)
         || (IdlSys_tiFilTqMaxClu_MP == 0))
      {
         s16LocalFiltredValue = s16LocalMeasValue;
         s32LocalFiltredMaxCluFilMem = (sint32)(s16LocalMeasValue * 65536);
         IDLMGR_s32FiltredMaxCluFilMem =
            MATHSRV_udtMIN(s32LocalFiltredMaxCluFilMem, 2097152000);
      }
      else
      {
         u32LocalFilterGain = (uint32)( 8388608 * u8LocalExt_tiTDC)
                                      / u32LocalFilterGain;
         s16LocalFiltredValue =
            MATHSRV_s16FirstOrderFilterGu16((uint16)u32LocalFilterGain,
                                            &IDLMGR_s32FiltredMaxCluFilMem,
                                            s16LocalMeasValue);
      }
      s16LocalIdlSys_tqMaxClu =
         (sint16)MATHSRV_udtCLAMP(s16LocalFiltredValue, -32000, 32000);
      IdlSys_tqMaxClu = s16LocalIdlSys_tqMaxClu;
   }
   else
   {
      IdlSys_tqMaxClu = 0;
      s16LocalIdlSys_tqMaxClu = s16LocalMeasValue;
      s32LocalFiltredMaxCluFilMem = (sint32)(s16LocalMeasValue * 65536);
      IDLMGR_s32FiltredMaxCluFilMem =
         MATHSRV_udtMIN(s32LocalFiltredMaxCluFilMem, 2097152000);
   }
   IdlSys_tqMaxCluFil_MP =
      (sint16)MATHSRV_udtMIN(s16LocalIdlSys_tqMaxClu, 32000);
}
/*------------------------------- end of file --------------------------------*/