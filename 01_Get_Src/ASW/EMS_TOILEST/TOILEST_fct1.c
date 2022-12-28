/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TOILEST                                                 */
/* !Description     : TOILEST Component                                       */
/*                                                                            */
/* !Module          : TOILEST                                                 */
/* !Description     : ESTIMATION DE LA TEMPERATURE D'HUILE                    */
/*                                                                            */
/* !File            : TOILEST_fct1.c                                          */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / TOILEST_vidInitOutput                                                */
/*   2 / TOILEST_vidInitialiser                                               */
/*   3 / TOILEST_vidCalculerThuile                                            */
/*   4 / TOILEST_vidCalcThuileMotTournant                                     */
/*   5 / TOILEST_vidCalcThuilBruteMotTour                                     */
/*   6 / TOILEST_vidCalcThuileMoteurCoupe                                     */
/*   7 / TOILEST_vidSelectionnerThuile                                        */
/*   8 / TOILEST_vidReconfigurerThuile                                        */
/*   9 / TOILEST_vidPowerLatch                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5050596 / 02                                        */
/* !OtherRefs   : CSMT_CGMT08_2341 / 2.7                                      */
/* !OtherRefs   : VEMS V02 ECU#050185                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TOILEST_im.h"
#include "TOILEST.h"
#include "TOILEST_l.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TOILEST_vidInitOutput                                      */
/* !Description :  Initialisation des sorties du module.                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Eng_tOilEstimIni;                                            */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input sint16 Eng_tOilEstimPrec;                                           */
/*  input sint32 Eng_tOilEstimEngStop;                                        */
/*  input sint32 Eng_tOilEngRunFil_MP;                                        */
/*  output sint16 Eng_tOilEstimIni;                                           */
/*  output sint16 Eng_tOilEstimRaw;                                           */
/*  output sint16 Eng_tOilEstimPrec;                                          */
/*  output sint32 Eng_tOilEstimEngStop;                                       */
/*  output sint32 Eng_tOilEngRunFil_MP;                                       */
/*  output sint32 TOILEST_s32tOilEstEngStopFiltMem;                           */
/*  output sint32 TOILEST_s32tOilEngRunFiltMem;                               */
/*  output uint8 Eng_stTOilCalc;                                              */
/*  output boolean Eng_bIniTOil;                                              */
/*  output uint8 Eng_tiInvldTAir;                                             */
/*  output boolean TOILEST_btOilEstEngRunRstPrev;                             */
/*  output boolean TOILEST_btOilEstEngStopRstPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TOILEST_vidInitOutput(void)
{
   sint16 s16LocalEng_tOilEstim;
   sint32 s32LocalEng_tOil;


   /* Initializing internal variables */
   Eng_tOilEstimIni = 0;
   Eng_tOilEstimRaw = Eng_tOilEstimIni;
   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);
   Eng_tOilEstimPrec =
      (sint16)MATHSRV_udtCLAMP(s16LocalEng_tOilEstim, -200, 800);
   s32LocalEng_tOil = (sint32)(1024 * Eng_tOilEstimPrec);
   Eng_tOilEstimEngStop = s32LocalEng_tOil;
   Eng_tOilEngRunFil_MP = s32LocalEng_tOil;
   TOILEST_s32tOilEstEngStopFiltMem = Eng_tOilEstimEngStop * 64;
   TOILEST_s32tOilEngRunFiltMem = Eng_tOilEngRunFil_MP * 64;
   /* FSM Outputs Initialization*/
   Eng_stTOilCalc = 0;
   Eng_bIniTOil = 0;
   Eng_tiInvldTAir = 0;
   /* Lowpass filter's reset Initialization */
   TOILEST_btOilEstEngRunRstPrev = 1;
   TOILEST_btOilEstEngStopRstPrev = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TOILEST_vidInitialiser                                     */
/* !Description :  Cette sous-fonction positionne la température d’huile à une*/
/*                 valeur calibrable à l’initialisation du calculateur        */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Eng_tOilIni_C;                                               */
/*  output sint16 Eng_tOilEstim;                                              */
/*  output boolean Eng_bDgoORngHiTOilEstim;                                   */
/*  output boolean Eng_bTOilChk;                                              */
/*  output boolean Eng_bMonRunORngTOilEstim;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TOILEST_vidInitialiser(void)
{
   sint16 s16LocalEng_tOilEstim;
   sint32 s32LocalEng_tOilEstim;


   s32LocalEng_tOilEstim = (sint32)(Eng_tOilIni_C * 4);
   s16LocalEng_tOilEstim =
      (sint16)MATHSRV_udtCLAMP(s32LocalEng_tOilEstim, -200, 800);
   VEMS_vidSET(Eng_tOilEstim, s16LocalEng_tOilEstim);
   VEMS_vidSET(Eng_bDgoORngHiTOilEstim, 0);
   VEMS_vidSET(Eng_bTOilChk, 1);
   VEMS_vidSET(Eng_bMonRunORngTOilEstim, 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TOILEST_vidCalculerThuile                                  */
/* !Description :  Une fois le calculateur initialisé, le calcul est effectué */
/*                 dans 2 situations distinctes : 1. Moteur tournant, 2.      */
/*                 Moteur coupé.                                              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06089_012.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TOILEST_vidCalculEtatEstimateur();                       */
/*  extf argret void TOILEST_vidCalcThuileInit();                             */
/*  extf argret void TOILEST_vidCalcThuileMotTournant();                      */
/*  extf argret void TOILEST_vidCalcThuileMoteurCoupe();                      */
/*  extf argret void TOILEST_vidSelectionnerThuile();                         */
/*  extf argret void TOILEST_vidReconfigurerThuile();                         */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input boolean Eng_bIniTOil;                                               */
/*  output sint16 Eng_tOilEstimPrec;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TOILEST_vidCalculerThuile(void)
{
   sint16 s16LocalEng_tOilEstim;


   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);
   Eng_tOilEstimPrec =
      (sint16)MATHSRV_udtCLAMP(s16LocalEng_tOilEstim, -200, 800);
   TOILEST_vidCalculEtatEstimateur();
   if (Eng_bIniTOil != 0)
   {
      TOILEST_vidCalcThuileInit();
   }
   TOILEST_vidCalcThuileMotTournant();
   TOILEST_vidCalcThuileMoteurCoupe();
   TOILEST_vidSelectionnerThuile();
   TOILEST_vidReconfigurerThuile();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TOILEST_vidCalcThuileMotTournant                           */
/* !Description :  Cette fonction permet de calculer la température d’huile   */
/*                 moteur tournant.                                           */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06089_007.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TOILEST_vidCalcThuilBruteMotTour();                      */
/*  input sint8 Ext_tAir;                                                     */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint8 Eng_tOilCorEngRun_A[8];                                       */
/*  input uint8 Eng_tOilCorEngRun_T[8];                                       */
/*  input uint16 Eng_tiFilTOilEngRun_A[16];                                   */
/*  input uint16 Eng_tiFilTOilEngRun_T[16];                                   */
/*  input boolean TOILEST_btOilEstEngRunRstPrev;                              */
/*  input sint16 Eng_tOilEstimPrec;                                           */
/*  input uint16 Eng_tiFilTOilEngRun_MP;                                      */
/*  input sint16 Eng_tOilEstimEngRunRaw;                                      */
/*  input sint32 TOILEST_s32tOilEngRunFiltMem;                                */
/*  input sint16 Eng_tOilCorEngRun_MP;                                        */
/*  input uint8 Eng_stTOilCalc;                                               */
/*  output sint16 Eng_tOilCorEngRun_MP;                                       */
/*  output uint16 Eng_tiFilTOilEngRun_MP;                                     */
/*  output sint32 TOILEST_s32tOilEngRunFiltMem;                               */
/*  output sint32 Eng_tOilEngRunFil_MP;                                       */
/*  output sint16 Eng_tOilEstimEngRun;                                        */
/*  output boolean TOILEST_btOilEstEngRunRstPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TOILEST_vidCalcThuileMotTournant(void)
{
   uint8   u8LocalInterp;
   uint8   u8LocalExt_tAir;
   sint8   s8LocalExt_tAir;
   uint16  u16LocalEng_nCkFil;
   uint16  u16LocalPara;
   uint16  u16LocalInterp;
   uint16  u16LocalFilterGain;
   sint16  s16LocalExt_tAir;
   sint16  s16LocaltOilEstimEngRun;
   sint16  s16LocalEng_tOilCorEngRun;
   sint16  s16LocalEng_tOilEngRunFil_MP;
   uint32  u32LocalEng_tiFilTOilEngRun_MP;
   uint32  u32LocalFilterGainDen;


   VEMS_vidGET(Ext_tAir, s8LocalExt_tAir);
   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);

   /* Oil temperature correction according to ambient temperature */
   s16LocalExt_tAir = (sint16)(s8LocalExt_tAir + 40);
   u8LocalExt_tAir = (uint8)MATHSRV_udtMAX(s16LocalExt_tAir, 0);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU8(Eng_tOilCorEngRun_A,
                                              u8LocalExt_tAir,
                                              8);
   u8LocalInterp = MATHSRV_u8Interp1d(Eng_tOilCorEngRun_T, u16LocalPara);
   s16LocalEng_tOilCorEngRun = (sint16)((u8LocalInterp - 50) * 4);
   Eng_tOilCorEngRun_MP = (sint16)MATHSRV_udtMIN(s16LocalEng_tOilCorEngRun,
                                                 800);

   /* Computing lowpass filter's gain according to engine's speed */
   u16LocalEng_nCkFil = (uint16)(((uint32)(u16LocalEng_nCkFil + 2)) / 4);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU16(Eng_tiFilTOilEngRun_A,
                                               u16LocalEng_nCkFil,
                                               16);
   u16LocalInterp = MATHSRV_u16Interp1d(Eng_tiFilTOilEngRun_T, u16LocalPara);
   u32LocalEng_tiFilTOilEngRun_MP = (uint32)(u16LocalInterp * 8);
   Eng_tiFilTOilEngRun_MP =
      (uint16)MATHSRV_udtMIN(u32LocalEng_tiFilTOilEngRun_MP, 16000);

   /* Computing raw oil temperature */
   TOILEST_vidCalcThuilBruteMotTour();

   /* Filtering oil temperature (T-Type Lowpass Filter) */
   if (TOILEST_btOilEstEngRunRstPrev != 0)
   {
      /* Resetting lowpass filter's output */
      s16LocalEng_tOilEngRunFil_MP = Eng_tOilEstimPrec;
      TOILEST_s32tOilEngRunFiltMem = (sint32)( s16LocalEng_tOilEngRunFil_MP
                                             * 65536);
   }
   else
   {
      /* Computing lowpass filter's output */
      if (Eng_tiFilTOilEngRun_MP == 0)
      {
         /* Filter Gain = 100% */
         s16LocalEng_tOilEngRunFil_MP = Eng_tOilEstimEngRunRaw;
         TOILEST_s32tOilEngRunFiltMem = (sint32)( s16LocalEng_tOilEngRunFil_MP
                                                * 65536);
      }
      else
      {
         /* Filter Gain < 100% */
         /* Eng_tiFilTOilEngRun_MP: Res = 1/8 [s] = 10/8 [100ms] */
         u32LocalFilterGainDen = (uint32)(8 + (10 * Eng_tiFilTOilEngRun_MP));
         u16LocalFilterGain = (uint16)( ( 524288UL
                                        + (u32LocalFilterGainDen / 2))
                                      / u32LocalFilterGainDen);
         s16LocalEng_tOilEngRunFil_MP =
            MATHSRV_s16FirstOrderFilterGu16(u16LocalFilterGain,
                                            &TOILEST_s32tOilEngRunFiltMem,
                                            Eng_tOilEstimEngRunRaw);
      }
   }
   s16LocalEng_tOilEngRunFil_MP =
      (sint16)MATHSRV_udtCLAMP(s16LocalEng_tOilEngRunFil_MP, -200, 800);
   Eng_tOilEngRunFil_MP = (sint32)(s16LocalEng_tOilEngRunFil_MP * 1024);

   /* Computing oil temperature when engine is running */
   s16LocaltOilEstimEngRun = (sint16)( Eng_tOilCorEngRun_MP
                                     + s16LocalEng_tOilEngRunFil_MP);
   Eng_tOilEstimEngRun = (sint16)MATHSRV_udtCLAMP(s16LocaltOilEstimEngRun,
                                                  -200,
                                                  800);

   /* Updating lowpass filter's reset */
   if (Eng_stTOilCalc != 3)
   {
      TOILEST_btOilEstEngRunRstPrev = 1;
   }
   else
   {
      TOILEST_btOilEstEngRunRstPrev = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TOILEST_vidCalcThuilBruteMotTour                           */
/* !Description :  La température d’huile estimée moteur tournant est fonction*/
/*                 de la température d’eau, selon l’activation ou non de la   */
/*                 pompe à eau pilotée. Ensuite, cette température est        */
/*                 corrigée en fonction de la charge du moteur et des         */
/*                 conditions extérieures.                                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06089_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean WaPmp_bAcvWaPmp;                                            */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input sint8 Ext_tAir;                                                     */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 Eng_tOilWaPmp_A[16];                                          */
/*  input uint8 Eng_tOilWaPmpOff_T[16];                                       */
/*  input uint8 Eng_tOilWaPmpOn_T[16];                                        */
/*  input uint16 Eng_nEngTOilCorEngCh_A[12];                                  */
/*  input uint16 Eng_rAirLdTOilCorEngCh_A[12];                                */
/*  input uint8 Eng_tOilCorEngCh_M[12][12];                                   */
/*  input sint16 Eng_tOilEstimPrec;                                           */
/*  input uint8 Eng_tDeltaTOilCorExtCnd_A[8];                                 */
/*  input uint8 TOILEST_u8DeltaEngTOilExtTAir;                                */
/*  input uint8 Eng_spdVehTOilCorExtCnd_A[8];                                 */
/*  input uint8 Eng_tOilCorExtCnd_M[8][8];                                    */
/*  input sint16 Eng_tOilWaPmpOff_MP;                                         */
/*  input sint16 Eng_tOilCorEngCh_MP;                                         */
/*  input sint16 Eng_tOilCorExtCnd_MP;                                        */
/*  input sint16 Eng_tOilWaPmpOn_MP;                                          */
/*  output sint16 Eng_tOilWaPmpOff_MP;                                        */
/*  output sint16 Eng_tOilWaPmpOn_MP;                                         */
/*  output sint16 Eng_tOilCorEngCh_MP;                                        */
/*  output uint8 TOILEST_u8DeltaEngTOilExtTAir;                               */
/*  output sint16 Eng_tOilCorExtCnd_MP;                                       */
/*  output sint16 Eng_tOilEstimEngRunRaw;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TOILEST_vidCalcThuilBruteMotTour(void)
{
   boolean bLocalWaPmp_bAcvWaPmp;
   uint8   u8LocalExt_tCoMes;
   uint8   u8LocalVeh_spdVeh;
   sint8   s8LocalExt_tAir;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalEngM_rAirLdCor;
   uint16  u16LocalEng_nCkFil;
   uint16  u16LocalVeh_spdVeh;
   sint16  s16LocalInterp;
   sint16  s16LocalExt_tCoMes;
   sint16  s16LocalDeltaEngTOilExtTAir;
   sint16  s16LocalRawOilTemp;
   sint32  s32LocalExt_tCoMes;


   VEMS_vidGET(WaPmp_bAcvWaPmp, bLocalWaPmp_bAcvWaPmp);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   VEMS_vidGET(Ext_tAir, s8LocalExt_tAir);
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);

   /* Oil temperature correction according to water pump state */
   s32LocalExt_tCoMes = (sint32)(s16LocalExt_tCoMes + 40);
   u8LocalExt_tCoMes = (uint8)MATHSRV_udtCLAMP(s32LocalExt_tCoMes, 0, 254);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU8(Eng_tOilWaPmp_A,
                                               u8LocalExt_tCoMes,
                                               16);

   s16LocalInterp = (sint16)MATHSRV_u8Interp1d(Eng_tOilWaPmpOff_T,
                                               u16LocalParaX);
   s16LocalInterp = (sint16)((s16LocalInterp - 50) * 4);
   Eng_tOilWaPmpOff_MP = (sint16)MATHSRV_udtMIN(s16LocalInterp, 800);

   s16LocalInterp = (sint16)MATHSRV_u8Interp1d(Eng_tOilWaPmpOn_T,
                                               u16LocalParaX);
   s16LocalInterp = (sint16)((s16LocalInterp - 50) * 4);
   Eng_tOilWaPmpOn_MP = (sint16)MATHSRV_udtMIN(s16LocalInterp, 800);

   /* Oil temperature correction according to engine load */
   u16LocalEng_nCkFil = (uint16)(((uint32)(u16LocalEng_nCkFil + 2)) / 4);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Eng_nEngTOilCorEngCh_A,
                                                u16LocalEng_nCkFil,
                                                12);
   u16LocalEngM_rAirLdCor = (uint16)( ((uint32)( u16LocalEngM_rAirLdCor
                                               + 8))
                                    / 16);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(Eng_rAirLdTOilCorEngCh_A,
                                                u16LocalEngM_rAirLdCor,
                                                12);
   s16LocalInterp = (sint16)MATHSRV_u8Interp2d(&Eng_tOilCorEngCh_M[0][0],
                                               u16LocalParaX,
                                               u16LocalParaY,
                                               12);
   s16LocalInterp = (sint16)((s16LocalInterp - 50) * 4);
   Eng_tOilCorEngCh_MP = (sint16)MATHSRV_udtMIN(s16LocalInterp, 800);

   /* Oil temperature correction according to external conditions */
   s16LocalDeltaEngTOilExtTAir = (sint16)( ( (Eng_tOilEstimPrec / 4)
                                           - s8LocalExt_tAir)
                                         + 50);
   TOILEST_u8DeltaEngTOilExtTAir =
      (uint8)MATHSRV_udtCLAMP(s16LocalDeltaEngTOilExtTAir, 0, 250);

   u16LocalParaX = MATHSRV_u16CalcParaIncAryU8(Eng_tDeltaTOilCorExtCnd_A,
                                               TOILEST_u8DeltaEngTOilExtTAir,
                                               8);
   u16LocalVeh_spdVeh = (uint16)(((uint32)(u16LocalVeh_spdVeh + 64)) / 128);
   u8LocalVeh_spdVeh = (uint8)MATHSRV_udtMIN(u16LocalVeh_spdVeh, 250);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Eng_spdVehTOilCorExtCnd_A,
                                               u8LocalVeh_spdVeh,
                                               8);
   s16LocalInterp = (sint16)MATHSRV_u8Interp2d(&Eng_tOilCorExtCnd_M[0][0],
                                               u16LocalParaX,
                                               u16LocalParaY,
                                               8);
   s16LocalInterp = (sint16)((s16LocalInterp - 100) * 4);
   Eng_tOilCorExtCnd_MP = (sint16)MATHSRV_udtMIN(s16LocalInterp, 400);

   /* Computing raw oil temperature when engine is running */
   if (bLocalWaPmp_bAcvWaPmp == 0)
   {
      s16LocalRawOilTemp = (sint16)( Eng_tOilWaPmpOff_MP
                                   + Eng_tOilCorEngCh_MP
                                   + Eng_tOilCorExtCnd_MP);
   }
   else
   {
      s16LocalRawOilTemp = (sint16)( Eng_tOilWaPmpOn_MP
                                   + Eng_tOilCorEngCh_MP
                                   + Eng_tOilCorExtCnd_MP);
   }

   Eng_tOilEstimEngRunRaw = (sint16)MATHSRV_udtCLAMP(s16LocalRawOilTemp,
                                                     -200,
                                                     800);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TOILEST_vidCalcThuileMoteurCoupe                           */
/* !Description :  Cette fonction estime la température d'huile moteur coupé. */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06089_009.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint8 Ext_rSpdFanAct;                                               */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 Eng_tOilEngStopTCo_A[8];                                      */
/*  input uint8 Eng_tOilEngStopTCo_T[8];                                      */
/*  input uint8 Eng_tDeltaTOilEngStop_A[8];                                   */
/*  input uint8 TOILEST_u8DeltaEngTOilExtTAir;                                */
/*  input uint8 Eng_rSpdFanTOilEngStop_A[8];                                  */
/*  input uint8 Eng_tOilEngStopSpdFan_M[8][8];                                */
/*  input uint8 Eng_spdVehTOilEngStop_A[8];                                   */
/*  input uint8 Eng_tOilEngStopSpdVeh_M[8][8];                                */
/*  input boolean TOILEST_btOilEstEngStopRstPrev;                             */
/*  input sint16 Eng_tOilEstimPrec;                                           */
/*  input uint16 Eng_tiFilTOilEngStop_C;                                      */
/*  input sint16 Eng_tOilEstimEngStopRaw_MP;                                  */
/*  input sint32 TOILEST_s32tOilEstEngStopFiltMem;                            */
/*  input uint8 Eng_stTOilCalc;                                               */
/*  output sint16 Eng_tOilEstimEngStopRaw_MP;                                 */
/*  output sint32 TOILEST_s32tOilEstEngStopFiltMem;                           */
/*  output sint32 Eng_tOilEstimEngStop;                                       */
/*  output boolean TOILEST_btOilEstEngStopRstPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TOILEST_vidCalcThuileMoteurCoupe(void)
{
   uint8   u8LocalExt_tCoMes;
   uint8   u8LocalVeh_spdVeh;
   uint8   u8LocalExt_rSpdFanAct;
   uint16  u16LocalExt_rSpdFanAct;
   uint16  u16LocalVeh_spdVeh;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalFilterGain;
   sint16  s16LocalExt_tCoMes;
   sint16  s16LocaltOilEngStopTCo;
   sint16  s16LocaltOilEngStopSpdFan;
   sint16  s16LocaltOilEngStopSpdVeh;
   sint16  s16LocalEng_tOilEstimEngStopRaw;
   sint16  s16LocalEng_tOilEstimEngStop;
   uint32  u32LocalFilterGainDen;
   sint32  s32LocalExt_tCoMes;


   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(Ext_rSpdFanAct, u8LocalExt_rSpdFanAct);
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);

   /* Oil temperature correction according to coolant's temperature */
   s32LocalExt_tCoMes = (sint32)(s16LocalExt_tCoMes + 40);
   u8LocalExt_tCoMes = (uint8)MATHSRV_udtCLAMP(s32LocalExt_tCoMes, 0, 254);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU8(Eng_tOilEngStopTCo_A,
                                               u8LocalExt_tCoMes,
                                               8);
   s16LocaltOilEngStopTCo = (sint16)MATHSRV_u8Interp1d(Eng_tOilEngStopTCo_T,
                                                       u16LocalParaX);
   s16LocaltOilEngStopTCo = (sint16)((s16LocaltOilEngStopTCo - 40) * 4);

   /* TOILEST_u8DeltaEngTOilExtTAir computed in FCT1.5, line 487 */
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU8(Eng_tDeltaTOilEngStop_A,
                                               TOILEST_u8DeltaEngTOilExtTAir,
                                               8);

   /* Oil temperature correction according to fan's speed */
   u16LocalExt_rSpdFanAct = (uint16)(u8LocalExt_rSpdFanAct * 2);
   u8LocalExt_rSpdFanAct = (uint8)MATHSRV_udtMIN(u16LocalExt_rSpdFanAct, 110);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Eng_rSpdFanTOilEngStop_A,
                                               u8LocalExt_rSpdFanAct,
                                               8);
   s16LocaltOilEngStopSpdFan =
      (sint16)MATHSRV_u8Interp2d(&Eng_tOilEngStopSpdFan_M[0][0],
                                 u16LocalParaX,
                                 u16LocalParaY,
                                 8);
   s16LocaltOilEngStopSpdFan = (sint16)((s16LocaltOilEngStopSpdFan - 100) * 4);

   /* Oil temperature correction according to engine's speed */
   u16LocalVeh_spdVeh = (uint16)(((uint32)(u16LocalVeh_spdVeh + 64)) / 128);
   u8LocalVeh_spdVeh = (uint8)MATHSRV_udtMIN(u16LocalVeh_spdVeh, 250);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Eng_spdVehTOilEngStop_A,
                                               u8LocalVeh_spdVeh,
                                               8);
   s16LocaltOilEngStopSpdVeh =
      (sint16)MATHSRV_u8Interp2d(&Eng_tOilEngStopSpdVeh_M[0][0],
                                 u16LocalParaX,
                                 u16LocalParaY,
                                 8);
   s16LocaltOilEngStopSpdVeh = (sint16)((s16LocaltOilEngStopSpdVeh - 100) * 4);

   s16LocalEng_tOilEstimEngStopRaw = (sint16)( s16LocaltOilEngStopTCo
                                             + s16LocaltOilEngStopSpdFan
                                             + s16LocaltOilEngStopSpdVeh);
   Eng_tOilEstimEngStopRaw_MP =
      (sint16)MATHSRV_udtCLAMP(s16LocalEng_tOilEstimEngStopRaw, -200, 800);

   /* Filtering oil temperature (T-Type Lowpass Filter) */
   if (TOILEST_btOilEstEngStopRstPrev != 0)
   {
      /* Resetting lowpass filter's output */
      s16LocalEng_tOilEstimEngStop = Eng_tOilEstimPrec;
      TOILEST_s32tOilEstEngStopFiltMem =
         (sint32)(s16LocalEng_tOilEstimEngStop * 65536);
   }
   else
   {
      /* Computing lowpass filter's output */
      if (Eng_tiFilTOilEngStop_C == 0 )
      {
         s16LocalEng_tOilEstimEngStop = Eng_tOilEstimEngStopRaw_MP;
         TOILEST_s32tOilEstEngStopFiltMem =
            (sint32)(s16LocalEng_tOilEstimEngStop * 65536);
      }
      else
      {
         /* Computing lowpass filter's gain */
         /* Eng_tiFilTOilEngStop_C: Res = 1 [s] = 10 [100ms] */
         u32LocalFilterGainDen = (uint32)(1 + (10 * Eng_tiFilTOilEngStop_C));
         u16LocalFilterGain = (uint16)( ( 65536
                                        + (u32LocalFilterGainDen / 2))
                                      / u32LocalFilterGainDen);
         s16LocalEng_tOilEstimEngStop =
            MATHSRV_s16FirstOrderFilterGu16(u16LocalFilterGain,
                                            &TOILEST_s32tOilEstEngStopFiltMem,
                                            Eng_tOilEstimEngStopRaw_MP);
      }
   }
   s16LocalEng_tOilEstimEngStop =
      (sint16)MATHSRV_udtCLAMP(s16LocalEng_tOilEstimEngStop, -200, 800);
   Eng_tOilEstimEngStop = (sint32)(s16LocalEng_tOilEstimEngStop * 1024);

   /* Updating lowpass filter's reset */
   if (Eng_stTOilCalc != 2)
   {
      TOILEST_btOilEstEngStopRstPrev = 1;
   }
   else
   {
      TOILEST_btOilEstEngStopRstPrev = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TOILEST_vidSelectionnerThuile                              */
/* !Description :  Cette sous-fonction permet de sélectionner la température  */
/*                 d’huile correspondant à l’état du moteur.                  */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06089_010.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Eng_stTOilCalc;                                               */
/*  input sint16 Eng_tOilEstimPrec;                                           */
/*  input sint16 Eng_tOilEstimIni;                                            */
/*  input sint32 Eng_tOilEstimEngStop;                                        */
/*  input sint16 Eng_tOilEstimEngRun;                                         */
/*  output sint16 Eng_tOilEstimRaw;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TOILEST_vidSelectionnerThuile(void)
{
   sint32 s32LocalEng_tOilEstimRaw;


   switch (Eng_stTOilCalc)
   {
      case 0:
         s32LocalEng_tOilEstimRaw = Eng_tOilEstimPrec;
         break;

      case 1:
         s32LocalEng_tOilEstimRaw = Eng_tOilEstimIni;
         break;

      case 2:
         s32LocalEng_tOilEstimRaw = Eng_tOilEstimEngStop / 1024;
         break;

      case 3:
         s32LocalEng_tOilEstimRaw = Eng_tOilEstimEngRun;
         break;

      default:
         s32LocalEng_tOilEstimRaw = Eng_tOilEstimEngRun;
         break;
   }

   Eng_tOilEstimRaw = (sint16)MATHSRV_udtCLAMP(s32LocalEng_tOilEstimRaw,
                                               -200,
                                               800);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TOILEST_vidReconfigurerThuile                              */
/* !Description :  Cette fonction permet de saturer et/ou de reconfigurer la  */
/*                 température d’huile estimée. Si elle atteint le maximum    */
/*                 admissible, elle est saturée et un défaut est remonté au   */
/*                 GD-GAR. Si on ne peut l'estimer correctement, elle bascule */
/*                 sur une valeur de repli.                                   */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06089_011.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input sint16 Eng_tOilEstimMax_C;                                          */
/*  input sint16 Eng_tOilEstimRaw;                                            */
/*  input uint32 Ext_tiAstTot;                                                */
/*  input uint16 Eng_tOilEstimDft_A[8];                                       */
/*  input uint16 Eng_tOilEstimDft_T[8];                                       */
/*  input uint8 Eng_stTOilCalc;                                               */
/*  input uint8 Eng_tOilEstimIncMax_C;                                        */
/*  input sint16 Eng_tOilEstimDecMax_C;                                       */
/*  output boolean Eng_bMonRunORngTOilEstim;                                  */
/*  output boolean Eng_bDgoORngHiTOilEstim;                                   */
/*  output boolean Eng_bTOilChk;                                              */
/*  output sint16 Eng_tOilEstim;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TOILEST_vidReconfigurerThuile(void)
{
   boolean bLocalAcvTOilDftMdl;
   boolean bLocalEng_bDgoORngHiTOilEstim;
   uint16  u16LocalPara;
   uint16  u16LocalInterp;
   uint16  u16LocalExt_tiAstTot;
   uint16  u16LocalEng_tOilEstimIncMax;
   uint16  u16LocalEng_tOilEstimDecMax;
   sint16  s16LocalEng_tOilEstimDecMax;
   sint16  s16LocalSlewFilterInput;
   sint16  s16LocalSlewFilterOutput;
   uint32  u32LocalExt_tiAstTot;
   sint32  s32LocaltOilEstimRaw;
   sint32  s32LocalEng_tOilEstimMax;
   sint32  s32LocalSlewFilterInput;


   VEMS_vidGET(Eng_tOilEstim, s16LocalSlewFilterOutput);

   VEMS_vidSET(Eng_bMonRunORngTOilEstim, 1);

   s32LocalEng_tOilEstimMax = (sint32)(Eng_tOilEstimMax_C * 4);
   /* Securing comparison in case Eng_tOilEstimMax_C < -50°C */
   s32LocalEng_tOilEstimMax = MATHSRV_udtMAX(s32LocalEng_tOilEstimMax, -200);
   if (Eng_tOilEstimRaw >= s32LocalEng_tOilEstimMax)
   {
      s32LocaltOilEstimRaw = s32LocalEng_tOilEstimMax;
      bLocalEng_bDgoORngHiTOilEstim = 1;
   }
   else
   {
      if (Eng_tOilEstimRaw <= -200)
      {
         s32LocaltOilEstimRaw = -200;
         bLocalEng_bDgoORngHiTOilEstim = 0;
      }
      else
      {
         s32LocaltOilEstimRaw = Eng_tOilEstimRaw;
         bLocalEng_bDgoORngHiTOilEstim = 0;
      }
   }
   VEMS_vidSET(Eng_bDgoORngHiTOilEstim, bLocalEng_bDgoORngHiTOilEstim);

   bLocalAcvTOilDftMdl = GDGAR_bGetFRM(FRM_FRM_ACVTOILDFTMDL);
   if (bLocalAcvTOilDftMdl != 0)
   {
      VEMS_vidSET(Eng_bTOilChk, 0);

      VEMS_vidGET(Ext_tiAstTot, u32LocalExt_tiAstTot);
      u16LocalExt_tiAstTot = (uint16)MATHSRV_udtMIN(u32LocalExt_tiAstTot,
                                                    65535);
      u16LocalPara = MATHSRV_u16CalcParaIncAryU16(Eng_tOilEstimDft_A,
                                                  u16LocalExt_tiAstTot,
                                                  8);
      u16LocalInterp = MATHSRV_u16Interp1d(Eng_tOilEstimDft_T, u16LocalPara);

      /* In this case, "s32LocalSlewFilterInput" within [0...261940] (DEC) */
      s32LocalSlewFilterInput = (sint32)((u16LocalInterp - 50) * 4);
   }
   else
   {
      if (bLocalEng_bDgoORngHiTOilEstim == 0)
      {
         VEMS_vidSET(Eng_bTOilChk, 1);
      }
      else
      {
         VEMS_vidSET(Eng_bTOilChk, 0);
      }
      /* In this case, "s32LocalSlewFilterInput" within [-200...131068] (DEC) */
      s32LocalSlewFilterInput = s32LocaltOilEstimRaw;
   }

   if (Eng_stTOilCalc > 1)
   {
      /* Eng_tOilEstimIncMax_C: Res = 1; Unit = °C/s = 1/10 * °C/100ms */
      u16LocalEng_tOilEstimIncMax = (uint16)( ( Eng_tOilEstimIncMax_C
                                              * 4)
                                            / 10);

      /* Eng_tOilEstimDecMax_C: Res = -1; Unit = °C/s = 1/10 * °C/100ms */
      s16LocalEng_tOilEstimDecMax = (sint16)( ( (-Eng_tOilEstimDecMax_C)
                                              * 4)
                                            / 10);
      u16LocalEng_tOilEstimDecMax =
         (uint16)MATHSRV_udtMAX(s16LocalEng_tOilEstimDecMax, 0);

      s16LocalSlewFilterInput =
         (sint16)MATHSRV_udtMIN(s32LocalSlewFilterInput, 32767);

      s16LocalSlewFilterOutput =
         MATHSRV_s16SlewFilter(s16LocalSlewFilterOutput,
                               s16LocalSlewFilterInput,
                               u16LocalEng_tOilEstimIncMax,
                               u16LocalEng_tOilEstimDecMax);

      s16LocalSlewFilterOutput =
         (sint16)MATHSRV_udtCLAMP(s16LocalSlewFilterOutput, -200, 800);
   }
   else
   {
      s16LocalSlewFilterOutput = (sint16)MATHSRV_udtMIN(s32LocalSlewFilterInput,
                                                        800);
   }
   VEMS_vidSET(Eng_tOilEstim, s16LocalSlewFilterOutput);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TOILEST_vidPowerLatch                                      */
/* !Description :  Cette sous-fonction permet de recopier les dernières       */
/*                 valeurs de la température d’huile estimée, de la           */
/*                 température d’eau et de la température extérieure de l'air */
/*                 avant leur sauvegarde en EEPROM lors du power-latch.       */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06089_013.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint8 Ext_tAir;                                                     */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint16 Eng_tOilEstimPrec;                                           */
/*  output sint8 Ext_tAir_NV;                                                 */
/*  output sint16 Ext_tCoMes_NV;                                              */
/*  output sint16 Eng_tOilEstim_NV;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TOILEST_vidPowerLatch(void)
{
   sint8  s8LocalExt_tAir;
   sint16 s16LocalEng_tOilEstimPrec;
   sint16 s16LocalExt_tCoMes;


   VEMS_vidGET(Ext_tAir, s8LocalExt_tAir);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);

   Ext_tAir_NV = (sint8)MATHSRV_udtCLAMP(s8LocalExt_tAir, -40, 100);
   Ext_tCoMes_NV = (sint16)MATHSRV_udtCLAMP(s16LocalExt_tCoMes, -40, 214);

   s16LocalEng_tOilEstimPrec = (sint16)(Eng_tOilEstimPrec / 4);
   Eng_tOilEstim_NV = (sint16)MATHSRV_udtCLAMP(s16LocalEng_tOilEstimPrec,
                                               -50,
                                               200);
}
/*--------------------------------- end of file ------------------------------*/