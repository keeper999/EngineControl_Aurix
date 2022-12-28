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
/* !File            : KNKACQFILT_FCT1.C                                       */
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
/*   1 / KNKACQFILT_vidInitOutput                                             */
/*   2 / KNKACQFILT_vidConfigParamInit                                        */
/*   3 / KNKACQFILT_vidInitializationRbl                                      */
/*   4 / KNKACQFILT_vidFilterEnergyCalc                                       */
/*   5 / KNKACQFILT_vidSignalSampleFilter                                     */
/*   6 / KNKACQFILT_vidReadKnkRblEnergy                                       */
/*   7 / KNKACQFILT_vidReadingRblEnergy                                       */
/*   8 / KNKACQFILT_vidReadingKnkEnergy                                       */
/*   9 / KNKACQFILT_vidDefKnkWindows                                          */
/*   10 / KNKACQFILT_vidSigConvGainCalc                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5066552 / 07                                        */
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
#include "STD_limits.h"
#include "MATHSRV.h"
#include "KNKACQFILT.h"
#include "KNKACQFILT_L.h"
#include "KNKACQFILT_IM.h"
#include "KNWHAL.h"
#include "VEMS.h"
#include "SWFAIL.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKACQFILT_vidInitOutput                                   */
/* !Description :  Fonction d'initialisation des sorties.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint32 somme_rbl[16];                                              */
/*  output uint16 Somme_clq_rbl_cyl[16][4];                                   */
/*  output uint16 Somme_clq_cyl[4];                                           */
/*  output uint16 KnkAcqFilt_rSigConvGainApp;                                 */
/*  output uint8 KnkAcqFilt_noKnkMesWin;                                      */
/*  output uint8 KnkRbl_noCyl;                                                */
/*  output boolean Acq_knk_rbl_cfg_win_status_upvb0;                          */
/*  output uint8 Knk_noCyl;                                                   */
/*  output uint8 KNKACQFILT_u8DebfencliquetisPrev;                            */
/*  output uint8 KNKACQFILT_u8DurfencliquetisPrev;                            */
/*  output boolean KNKACQFILT_bAcvCalSdlFastPrev;                             */
/*  output uint16 Knk_OfsInjrNoiseKnk;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKACQFILT_vidInitOutput(void)
{
   uint8  u8LocalIndexRow0;
   uint8  u8LocalIndexColumn;


   for (u8LocalIndexRow0 = 0; u8LocalIndexRow0 < 16; u8LocalIndexRow0++)
   {
      somme_rbl[u8LocalIndexRow0] = 0;
      for (u8LocalIndexColumn = 0; u8LocalIndexColumn < 4; u8LocalIndexColumn++)
      {
         Somme_clq_rbl_cyl[u8LocalIndexRow0][u8LocalIndexColumn] = 0;
      }
   }

   for (u8LocalIndexRow0 = 0; u8LocalIndexRow0 < 4; u8LocalIndexRow0++)
   {
      VEMS_vidSET1DArrayElement(Somme_clq_cyl, u8LocalIndexRow0, 0);
   }

   KnkAcqFilt_rSigConvGainApp = 32768 / 5;
   KnkAcqFilt_noKnkMesWin = 2;
   VEMS_vidSET(KnkRbl_noCyl, 0);
   VEMS_vidSET(Acq_knk_rbl_cfg_win_status_upvb0, 0);
   VEMS_vidSET(Knk_noCyl, 0);
   KNKACQFILT_u8DebfencliquetisPrev = 0;
   KNKACQFILT_u8DurfencliquetisPrev = 0;
   KNKACQFILT_bAcvCalSdlFastPrev = 0;
   Knk_OfsInjrNoiseKnk = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKACQFILT_vidConfigParamInit                              */
/* !Description :  Dans le souci de rendre la spécification générique, nous   */
/*                 avons dupliqué le bloc d’initialisation des APIs pour la   */
/*                 détection de cliquetis et la détection de rumble.          */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNWHAL_vidWriteAntiAliasingFreq(argin uint16             */
/*  u16Frequency);                                                            */
/*  extf argret void KNWHAL_vidSetSamplingWinIdxTbl(argio uint32              */
/* *pau32SamplingWinIdxTbl);                                                  */
/*  extf argret void KNWHAL_vidWriteSamplePeriod(argin uint16                 */
/* u16SamplePeriod);                                                          */
/*  extf argret void KNWHAL_vidSetSampleTblPrms(argio uint16                  */
/* *pau16SampleTbl,argin uint32 u32SampleTblMaxSize);                         */
/*  extf argret void KNKACQFILT_vidInitializationRbl();                       */
/*  input uint32 KnkAcqFilt_noKnkMesRawTblIdx[4];                             */
/*  input uint16 KnkAcqFilt_prm_uKnkMesRaw[2000];                             */
/*  input boolean Autorise_rbl_num;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKACQFILT_vidConfigParamInit(void)
{
   KNWHAL_vidWriteAntiAliasingFreq(25000);
   KNWHAL_vidSetSamplingWinIdxTbl((uint32*)&KnkAcqFilt_noKnkMesRawTblIdx[0]);
   /*QAC Msg(2:3212):The cast (uint32*) is recommended by the specification
                     of KNWHAL APIs*/
   KNWHAL_vidWriteSamplePeriod(1667);
   KNWHAL_vidSetSampleTblPrms((uint16*)&KnkAcqFilt_prm_uKnkMesRaw[0], 2000);
   /*QAC Msg(2:3212):The cast (uint16*) is recommended by the specification
                     of KNWHAL APIs*/
   if (Autorise_rbl_num != 0)
   {
      /*01_Initialisation_Rbl*/
      KNKACQFILT_vidInitializationRbl();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKACQFILT_vidInitializationRbl                            */
/* !Description :  Au reset calculateur, plusieurs paramètres sont envoyés au */
/*                 LdB via KNWHAL APIs KNWHAL_vidWriteAntiAliasingFreq,       */
/*                 KNWHAL_vidWriteSamplePeriod, KNWHAL_vidSetSampleTblPrms et */
/*                 KNWHAL_vidSetSamplingWinIdxTbl.                            */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Eng_noCmbCyl;                                                 */
/*  output uint8 KnkRbl_noCyl;                                                */
/*  output uint16 Somme_clq_rbl_cyl[16][4];                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKACQFILT_vidInitializationRbl(void)
{
   /*01_Initialisation_Rbl*/
   uint8  u8LocalEng_noCmbCyl;
   uint8  u8LocalKnkRbl_noCyl;
   uint8  u8LocalIndexRow;
   uint8  u8LocalIndexColumn;


   VEMS_vidGET(Eng_noCmbCyl, u8LocalEng_noCmbCyl);
   u8LocalKnkRbl_noCyl = (uint8)MATHSRV_udtCLAMP(u8LocalEng_noCmbCyl, 1, 4);
   u8LocalKnkRbl_noCyl = (uint8)(u8LocalKnkRbl_noCyl - 1);

   VEMS_vidSET(KnkRbl_noCyl, u8LocalKnkRbl_noCyl);

   for (u8LocalIndexRow = 0; u8LocalIndexRow < 16; u8LocalIndexRow++)
   {
      for (u8LocalIndexColumn = 0; u8LocalIndexColumn < 4; u8LocalIndexColumn++)
      {
         Somme_clq_rbl_cyl[u8LocalIndexRow][u8LocalIndexColumn] = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKACQFILT_vidFilterEnergyCalc                             */
/* !Description :  Ce bloc est divisé en trois sous-blocs :01_CalcParamFilt   */
/*                 calcule,  SignalSampleFilter et                            */
/*                 03_Lecture_energie_cliquetis.                              */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KNKACQFILT_vidSignalSampleFilter();                      */
/*  extf argret void KNKACQFILT_vidReadKnkRblEnergy();                        */
/*  input uint8 Frequence_centrale_passe_bande;                               */
/*  input boolean KnkAcqFilt_bAcvFreq6_C;                                     */
/*  input uint8 KnkAcqFilt_frqCalcParam6_A[21];                               */
/*  input uint8 KnkAcqFilt_CalcParam6_T[21];                                  */
/*  input uint8 KnkAcqFilt_frqCalcParam3_A[25];                               */
/*  input uint8 KnkAcqFilt_CalcParam3_T[25];                                  */
/*  input uint8 Debut_fenetre_cliquetis;                                      */
/*  input uint8 KNKACQFILT_u8DebfencliquetisPrev;                             */
/*  input uint8 Duree_fenetre_cliquetis;                                      */
/*  input uint8 KNKACQFILT_u8DurfencliquetisPrev;                             */
/*  output sint8 KnkAcqFilt_FiltParam;                                        */
/*  output uint8 KNKACQFILT_u8DebfencliquetisPrev;                            */
/*  output uint8 KNKACQFILT_u8DurfencliquetisPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKACQFILT_vidFilterEnergyCalc(void)
{
   uint8    u8LocalFreq_centrale_passe_bande;
   uint8    u8Localfrqindex;
   uint16   u16LocalCalcParam;
   sint16   s16LocalFiltParam;
   /*02_Knk_filter_energy_calc*/
 /*uint16  u16LocalIndexRow;*/
 /*uint32  u32LocalVar;*/


   VEMS_vidGET(Frequence_centrale_passe_bande,
               u8LocalFreq_centrale_passe_bande);

   if (KnkAcqFilt_bAcvFreq6_C != 0)
   {
      u16LocalCalcParam =
         MATHSRV_u16CalcParaIncAryU8(KnkAcqFilt_frqCalcParam6_A,
                                     u8LocalFreq_centrale_passe_bande,
                                     21);
      u8Localfrqindex = (uint8)(u16LocalCalcParam >> 8);
      s16LocalFiltParam =
         (sint16)(KnkAcqFilt_CalcParam6_T[u8Localfrqindex] - 10);
   }
   else
   {
      u16LocalCalcParam =
         MATHSRV_u16CalcParaIncAryU8(KnkAcqFilt_frqCalcParam3_A,
                                     u8LocalFreq_centrale_passe_bande,
                                     25);
      u8Localfrqindex = (uint8)(u16LocalCalcParam >> 8);
      s16LocalFiltParam =
         (sint16)(KnkAcqFilt_CalcParam3_T[u8Localfrqindex] - 12);
   }
   KnkAcqFilt_FiltParam =(sint8)MATHSRV_udtMIN(s16LocalFiltParam, 15);

   /*SignalSampleFilter*/
   KNKACQFILT_vidSignalSampleFilter();
   /*03_Lecture_energie_cliquetis*/
   KNKACQFILT_vidReadKnkRblEnergy();
   VEMS_vidGET(Debut_fenetre_cliquetis, KNKACQFILT_u8DebfencliquetisPrev);
   VEMS_vidGET(Duree_fenetre_cliquetis, KNKACQFILT_u8DurfencliquetisPrev);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKACQFILT_vidSignalSampleFilter                           */
/* !Description :  SignalSampleFilter est une s-function servant de filtre    */
/*                 passe bande.                                               */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint32 KnkAcqFilt_noKnkMesRawTblIdx[4];                             */
/*  input uint8 Longueur_table_sortie_rbl;                                    */
/*  input uint8 KnkAcqFilt_noKnkMesWin;                                       */
/*  input uint16 KnkAcqFilt_prm_uKnkMesRaw[2000];                             */
/*  input uint16 KnkAcqFilt_rSigConvGainApp;                                  */
/*  input boolean KnkAcqFilt_bAcvFreq6_C;                                     */
/*  input sint8 KnkAcqFilt_FiltParam;                                         */
/*  input boolean KnkAcqFilt_bInhFiltRbl_C;                                   */
/*  output uint32 somme_rbl[16];                                              */
/*  output uint32 somme_clq;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKACQFILT_vidSignalSampleFilter(void)
{
   uint8_least   u8LocalnbrWinRbl;
   uint8_least   u8LocalidRbl;
   uint16_least  u16Localidx_init;
   uint16_least  u16Localidx_knk;
   uint16_least  u16LocalIndexRow;
   uint16_least  u16LocalctSampleRbl;
   uint16_least  u16LocalnbrSamplePerWin;
   uint16_least  u16Localidx_rbl;
   uint16_least  u16LocalKnkAcqFilt_uKnk;
   uint16_least  u16LocalKnkAcqFilt_uKnkPrev;
   uint16_least  u16LocalKnkAcqFilt_uKnkPrev2;
   sint32        s32Localterme1;
 /*  sint32  s32Localterme2;*/
   sint32        s32Localterme3;
   sint32        s32LocalDiff;
   float32       f32Localterme4;
   float32       f32Localterme5;
   float32       f32LocalpassBandFilterNUM;
   float32       f32LocalScoreRblWinTmp;
   float32       f32LocalpassBandFiltOut1;
   float32       f32Localsomme_clq;
   float32       f32Localsomme_clq_Tmp;
   float32       f32localPassBandFiltOut;
   float32       f32localPassBandFiltOutPrev;
   float32       f32localPassBandFiltOutPrev2;
   uint32        u32LocalDenom;


   /*init nbre d'echantillons*/
   u16Localidx_init =
      MATHSRV_udtMIN(KnkAcqFilt_noKnkMesRawTblIdx[1], 2000);
   u16LocalnbrSamplePerWin = 20;

   u8LocalnbrWinRbl =
      MATHSRV_udtCLAMP(Longueur_table_sortie_rbl, 1, 16);

   /*selection indice Rbl et cliquetis selon la fenetre*/
   /* Selection selon nbre fenetre*/
   switch (KnkAcqFilt_noKnkMesWin)
   {
      case 3:
         u16Localidx_rbl =
            MATHSRV_udtMIN(KnkAcqFilt_noKnkMesRawTblIdx[2], 2000);
         u16Localidx_knk =
            MATHSRV_udtMIN(KnkAcqFilt_noKnkMesRawTblIdx[3], 2000);
         s32LocalDiff = (sint32)(u16Localidx_rbl - u16Localidx_init);
         if (s32LocalDiff <= 0)
         {
            u16LocalnbrSamplePerWin = 0;
         }
         else
         {
            u16LocalnbrSamplePerWin =
               (uint16)(s32LocalDiff / (sint32)u8LocalnbrWinRbl);
   /*QAC Warning : Msg(3:3892) :
    u16LocalnbrSamplePerWin does not exceed the type uint16*/
         }
         break;
      case 2:
         u16Localidx_rbl =
            MATHSRV_udtMIN(KnkAcqFilt_noKnkMesRawTblIdx[1], 2000);
         u16Localidx_knk =
            MATHSRV_udtMIN(KnkAcqFilt_noKnkMesRawTblIdx[2], 2000);
         break;
      default:
         u16Localidx_rbl = (uint16_least)3;
         u16Localidx_knk = (uint16_least)3;
         break;
   }
   /*initialisation des parametres du filtre*/
   f32localPassBandFiltOutPrev2 = (float32)0;
   /*QAC Warning : Msg(3:3198) : the variable must be initialized -> no impact*/
   f32localPassBandFiltOutPrev = (float32)0;
   f32localPassBandFiltOut = (float32)0;
   f32Localsomme_clq_Tmp = (float32)0;

   for (u16LocalIndexRow = 0;
        u16LocalIndexRow < u8LocalnbrWinRbl;
        u16LocalIndexRow++)
   {
      somme_rbl[u16LocalIndexRow] = 0;
   }

   u16LocalctSampleRbl = 0;
   f32LocalScoreRblWinTmp = (float32)0;
   u8LocalidRbl = 0;

   /*calcule numerateur filtre:*/
   /*(b(1)*uKnk+b(2)*uKnkPrev+b(3)*uKnkPrev2-a(2)*y(i-1)-a(3)*y(i-2))*/
   u16LocalKnkAcqFilt_uKnkPrev2 = KnkAcqFilt_prm_uKnkMesRaw[0] * 4;
   /*QAC Warning : Msg(3:3198) : the variable must be initialized -> no impact*/
   u16LocalKnkAcqFilt_uKnkPrev = KnkAcqFilt_prm_uKnkMesRaw[0] * 4;
   u16LocalKnkAcqFilt_uKnk = KnkAcqFilt_prm_uKnkMesRaw[1] * 4;

   /*calcul du denominateur des sommes*/
   u32LocalDenom = (uint32)(10 * KnkAcqFilt_rSigConvGainApp);

   for (u16LocalIndexRow = 2;
        u16LocalIndexRow < u16Localidx_knk;
        u16LocalIndexRow++)
   {
      u16LocalKnkAcqFilt_uKnkPrev2 = u16LocalKnkAcqFilt_uKnkPrev;
      u16LocalKnkAcqFilt_uKnkPrev = u16LocalKnkAcqFilt_uKnk;
      u16LocalKnkAcqFilt_uKnk = KnkAcqFilt_prm_uKnkMesRaw[u16LocalIndexRow] * 4;
      f32localPassBandFiltOutPrev2 = f32localPassBandFiltOutPrev;
      f32localPassBandFiltOutPrev = f32localPassBandFiltOut;

      if (KnkAcqFilt_bAcvFreq6_C != 0)
      {
         s32Localterme1 = (sint32)( 2 * u16LocalKnkAcqFilt_uKnk);/* b(1)=2 */
      /*   s32Localterme2 = (sint32)( 0 * u16LocalKnkAcqFilt_uKnkPrev);b(2)=0 */
         s32Localterme3 = (sint32)( -2 * u16LocalKnkAcqFilt_uKnkPrev2);
                                                                   /* b(3)=-2 */
         f32Localterme4 =
            ( (float32)KnkAcqFilt_FiltParam * f32localPassBandFiltOutPrev);
         f32Localterme5 = ( (float32)4 * f32localPassBandFiltOutPrev2);
      }
      else
      {
         s32Localterme1 = (sint32)( u16LocalKnkAcqFilt_uKnk);/* b(1)=1 */
      /* s32Localterme2 = (sint32)( 0 * u16LocalKnkAcqFilt_uKnkPrev); b(2)=0 */
         s32Localterme3 = (sint32)( (-1) * u16LocalKnkAcqFilt_uKnkPrev2);
                                                                   /* b(3)=-1 */
         f32Localterme4 =
            ( (float32)KnkAcqFilt_FiltParam * f32localPassBandFiltOutPrev);
         f32Localterme5 = ( (float32)6* f32localPassBandFiltOutPrev2);
      }

      f32LocalpassBandFilterNUM = ( ((float32)s32Localterme1
                                  /*+ (float32)s32Localterme2*/
                                  + (float32)s32Localterme3)
                                  - (f32Localterme4
                                  + f32Localterme5 ));

       /* dénominateur fixé à 8 */
      f32localPassBandFiltOut = ( f32LocalpassBandFilterNUM / (float32)8);

      if (  (u16Localidx_init <= u16LocalIndexRow)
         && (u16LocalIndexRow < u16Localidx_rbl))
      {
         u16LocalctSampleRbl = (u16LocalctSampleRbl + 1);
         /*if inhib filter*/
         if (KnkAcqFilt_bInhFiltRbl_C != 0)
         {
            f32LocalpassBandFiltOut1 =
               (float32)u16LocalKnkAcqFilt_uKnk;

         }
         else
         {
            f32LocalpassBandFiltOut1 =
               MATHSRV_udtABS(f32localPassBandFiltOut);
         }

         f32LocalScoreRblWinTmp = ( f32LocalpassBandFiltOut1
                                  + f32LocalScoreRblWinTmp);

         if (u8LocalidRbl < u8LocalnbrWinRbl)
         {
            if (u16LocalctSampleRbl == u16LocalnbrSamplePerWin)
            {
               f32LocalpassBandFiltOut1 =
                  (f32LocalScoreRblWinTmp * (float32)65536)
                     / (float32)u32LocalDenom;
               somme_rbl[u8LocalidRbl] =
                  (uint32)MATHSRV_udtMIN(f32LocalpassBandFiltOut1,
                                         (float32)4294967295U);
               u8LocalidRbl = (u8LocalidRbl + 1);
               u16LocalctSampleRbl = 0;
            }
         }
         if (u16LocalIndexRow == (u16Localidx_rbl - 1))
         {
            f32LocalpassBandFiltOut1 =
               (f32LocalScoreRblWinTmp * (float32)65536)
                  / (float32)u32LocalDenom;
            somme_rbl[u8LocalnbrWinRbl-1] =
               (uint32)MATHSRV_udtMIN(f32LocalpassBandFiltOut1,
                                      (float32)4294967295U);
         }
      }
      else
      {
         if (  (u16Localidx_rbl <= u16LocalIndexRow)
            && (u16LocalIndexRow < u16Localidx_knk))
         {
            f32Localsomme_clq = f32localPassBandFiltOut;
            f32Localsomme_clq = MATHSRV_udtABS(f32Localsomme_clq);
            f32Localsomme_clq_Tmp =
               f32Localsomme_clq_Tmp + f32Localsomme_clq;
         }
      }
   }
   f32Localsomme_clq = (f32Localsomme_clq_Tmp * (float32)65536)
      / (float32)u32LocalDenom;
   somme_clq = (uint32)MATHSRV_udtMIN(f32Localsomme_clq, (float32)4294967295U);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKACQFILT_vidReadKnkRblEnergy                             */
/* !Description :  03_Lecture_energie_cliquetis récupère les sommes de        */
/*                 cliquetis/rumble et les range dans une matrice en fonction */
/*                 de numéro de cylindre.                                     */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKACQFILT_vidReadingRblEnergy();                        */
/*  extf argret void KNKACQFILT_vidReadingKnkEnergy();                        */
/*  input boolean Autorise_rbl_num;                                           */
/*  input boolean Autorise_clq_num;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKACQFILT_vidReadKnkRblEnergy(void)
{
   /*03_Lecture_energie_cliquetis*/
   if (Autorise_rbl_num != 0)
   {
      /*Lecture_energie_rumble*/
      KNKACQFILT_vidReadingRblEnergy();
   }
   if (Autorise_clq_num != 0)
   {
      /*Lecture_energie_cliquetis*/
      KNKACQFILT_vidReadingKnkEnergy();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKACQFILT_vidReadingRblEnergy                             */
/* !Description :  La somme des échantillons filtrés durant la fenêtre        */
/*                 somme_rbl est récupérée puis rangée dans l’ordre physique  */
/*                 des cylindres dans la variable Somme_rbl_cyl.              */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Eng_noCmbCyl;                                                 */
/*  input uint8 KnkRbl_ScaEgyCoef_C;                                          */
/*  input uint32 somme_rbl[16];                                               */
/*  output uint8 KnkRbl_noCyl;                                                */
/*  output uint16 Somme_clq_rbl_cyl[16][4];                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKACQFILT_vidReadingRblEnergy(void)
{
   /*Lecture_energie_rumble*/
   uint8   u8LocalEng_noCmbCyl;
   uint8   u8LocalKnkRbl_noCyl;
   uint8   u8LocalIndexRow;
   uint8   u8LocalIdx;
   uint32  u32Localvar;


   VEMS_vidGET(Eng_noCmbCyl, u8LocalEng_noCmbCyl);
   u8LocalKnkRbl_noCyl = (uint8)MATHSRV_udtCLAMP(u8LocalEng_noCmbCyl, 1, 4);
   u8LocalKnkRbl_noCyl = (uint8)(u8LocalKnkRbl_noCyl - 1);
   VEMS_vidSET(KnkRbl_noCyl, u8LocalKnkRbl_noCyl);

   switch (u8LocalEng_noCmbCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalIdx = (uint8)(u8LocalEng_noCmbCyl - 1);
         for (u8LocalIndexRow = 0; u8LocalIndexRow < 16; u8LocalIndexRow++)
         {
            if (KnkRbl_ScaEgyCoef_C == 0)
            {
               u32Localvar = 0;

            }
            else
            {
               if (somme_rbl[u8LocalIndexRow] < 8388416)
               {
                  u32Localvar = ( ( ( somme_rbl[u8LocalIndexRow]
                                    * KnkRbl_ScaEgyCoef_C)
                                  + 64)
                                /  128);
               }
               else
               {
                  u32Localvar = 65535;
               }
            }

            Somme_clq_rbl_cyl[u8LocalIndexRow][u8LocalIdx] =
               (uint16)MATHSRV_udtMIN(u32Localvar, 65535);
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKACQFILT_vidReadingKnkEnergy                             */
/* !Description :  La somme des échantillons filtrés durant la fenêtre        */
/*                 somme_clq est récupérée puis rangée dans l’ordre physique  */
/*                 des cylindres dans la variable Somme_clq_cyl.              */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void KNKACQFILT_vidOfsPmpHPNKnkcalc();                        */
/*  extf argret void KNKACQFILT_vidOfsInjrNKnkcalc();                         */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Eng_noCmbCyl;                                                 */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 Knk_nEngThrOfsInjrNoise_C;                                   */
/*  input uint16 Knk_OfsInjrNoiseKnk;                                         */
/*  input uint8 Knk_ScaEgyCoef_C;                                             */
/*  input uint32 somme_clq;                                                   */
/*  input uint16 Knk_OfsPmpHPNoiseKnk;                                        */
/*  output uint8 Knk_noCyl;                                                   */
/*  output uint16 Somme_clq_cyl[4];                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKACQFILT_vidReadingKnkEnergy(void)
{
   /*Lecture_energie_cliquetis*/
   uint8     u8LocalEng_noCmbCyl;
   uint8     u8LocalKnk_noCyl;
   uint8     u8LocalIdx;
   uint16    u16LocalSomme_clq_cyl;
   uint16    u16LocalExt_nEng;
   uint16    u16LocalOut;
   uint32    u32LocalDiv;
   uint32    u32Localmul_1;
   uint32    u32Localmul_2;
   uint32    u32Localvar;


   VEMS_vidGET(Eng_noCmbCyl, u8LocalEng_noCmbCyl);
   u8LocalKnk_noCyl = (uint8)MATHSRV_udtCLAMP(u8LocalEng_noCmbCyl, 1, 4);
   u8LocalKnk_noCyl = (uint8)(u8LocalKnk_noCyl - 1);
   VEMS_vidSET(Knk_noCyl, u8LocalKnk_noCyl);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   KNKACQFILT_vidOfsPmpHPNKnkcalc();
   if (u16LocalExt_nEng <= Knk_nEngThrOfsInjrNoise_C)
   {
      KNKACQFILT_vidOfsInjrNKnkcalc();
      u16LocalOut = Knk_OfsInjrNoiseKnk;
   }
   else
   {
      u16LocalOut = 0;
   }
   switch (u8LocalEng_noCmbCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalIdx = (uint8)(u8LocalEng_noCmbCyl - 1);
         if (  (Knk_ScaEgyCoef_C == 0)
            || (somme_clq == 0))
         {
            u16LocalSomme_clq_cyl = 0;
         }
         else
         {
            u32LocalDiv = UINT32_MAX / (uint32)Knk_ScaEgyCoef_C;
            if (somme_clq < u32LocalDiv)
            {
               u32Localmul_1 = Knk_ScaEgyCoef_C * somme_clq;
               u32Localmul_2 =
                  (uint32)(128 * (Knk_OfsPmpHPNoiseKnk + u16LocalOut));
               if (u32Localmul_1 > u32Localmul_2)
               {
                  u32Localvar = ((u32Localmul_1 - u32Localmul_2) / 128);
                  u16LocalSomme_clq_cyl =
                     (uint16)MATHSRV_udtMIN(u32Localvar, 65535);
               }
               else
               {
                  u16LocalSomme_clq_cyl = 0;
               }
            }
            else
            {
               u16LocalSomme_clq_cyl = 65535;
            }
         }

         VEMS_vidSET1DArrayElement(Somme_clq_cyl,
                                   u8LocalIdx,
                                   u16LocalSomme_clq_cyl);
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKACQFILT_vidDefKnkWindows                                */
/* !Description :  Nous allons considérer ces 2 cas de figure:Détection de    */
/*                 cliquetis autorisée et détection de rumble autorisée et    */
/*                 détection de cliquetis autorisée et détection de rumble non*/
/*                 autorisée.                                                 */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKACQFILT_vidSigConvGainCalc();                         */
/*  extf argret void KNKACQFILT_vidKnkMesWin();                               */
/*  extf argret void KNKACQFILT_vidInterfaceBSW();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKACQFILT_vidDefKnkWindows(void)
{
   KNKACQFILT_vidSigConvGainCalc();
   KNKACQFILT_vidKnkMesWin();
   KNKACQFILT_vidInterfaceBSW();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKACQFILT_vidSigConvGainCalc                              */
/* !Description :  fonction de de correspondance entre le numéro de gain et la*/
/*                 valeur de gain physique                                    */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret Std_ReturnType  KNWHAL_udtWriteInputStageGain(argin uint8     */
/* u8InputStageGainIdx);                                                      */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 KnkAcqFilt_numSampleFiltInit_C;                               */
/*  input uint16 KnkAcqFilt_nEngSigConvGain_A[16];                            */
/*  input uint8 KnkAcqFilt_noSigConvGain_T[16];                               */
/*  input uint8 KnkAcqFilt_noSigConvGain;                                     */
/*  input uint8 KnkAcqFilt_noSigConvGainReq;                                  */
/*  input uint8 KnkAcqFilt_noSigConvGain_A[16];                               */
/*  input uint8 KnkAcqFilt_noSigConvGainApp;                                  */
/*  input uint16 KnkAcqFilt_rSigConvNom_C;                                    */
/*  input uint16 KnkAcqFilt_rSigConvGain_T[16];                               */
/*  output uint16 KnkAcqFilt_agWdWinFiltInit;                                 */
/*  output uint8 KnkAcqFilt_noSigConvGain;                                    */
/*  output uint8 KnkAcqFilt_noSigConvGainReq;                                 */
/*  output uint8 KnkAcqFilt_noSigConvGainApp;                                 */
/*  output uint16 KnkAcqFilt_rSigConvGainApp;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKACQFILT_vidSigConvGainCalc(void)
{
   uint8   u8LocalOutputStageGain;
   uint8   u8LocalnoSigindex;
   uint8   u8LocalrSigindex;
   uint16  u16LocalCalcParam1;
   uint16  u16LocalCalcParam2;
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalKnkAcqFilt_agWdWinInit;
   uint32  u32LocalKnkAcqFilt_rSigConvGain;


   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   u16LocalKnkAcqFilt_agWdWinInit =
      (uint16)( ( (uint32)( KnkAcqFilt_numSampleFiltInit_C
                          * u16LocalRegime_moteur)
                + 2500)
              / 5000);
   KnkAcqFilt_agWdWinFiltInit =
      (uint16)MATHSRV_udtMIN(u16LocalKnkAcqFilt_agWdWinInit, 1439);
   u16LocalCalcParam1 =
         MATHSRV_u16CalcParaIncAryU16(KnkAcqFilt_nEngSigConvGain_A,
                                      u16LocalRegime_moteur,
                                      16);
   u8LocalnoSigindex = (uint8)(u16LocalCalcParam1 >> 8);
   KnkAcqFilt_noSigConvGain =
      (uint8)MATHSRV_udtMIN(KnkAcqFilt_noSigConvGain_T[u8LocalnoSigindex], 15);

   switch (KnkAcqFilt_noSigConvGain)
   {
      case 0:
         KnkAcqFilt_noSigConvGainReq = KNWHAL_u8INPUT_STAGE_IDX_0;
         break;
      case 1:
         KnkAcqFilt_noSigConvGainReq = KNWHAL_u8INPUT_STAGE_IDX_1;
         break;
      case 2:
         KnkAcqFilt_noSigConvGainReq = KNWHAL_u8INPUT_STAGE_IDX_2;
         break;
      case 3:
         KnkAcqFilt_noSigConvGainReq = KNWHAL_u8INPUT_STAGE_IDX_3;
         break;
      case 4:
         KnkAcqFilt_noSigConvGainReq = KNWHAL_u8INPUT_STAGE_IDX_4;
         break;
      case 5:
         KnkAcqFilt_noSigConvGainReq = KNWHAL_u8INPUT_STAGE_IDX_5;
         break;
      case 6:
         KnkAcqFilt_noSigConvGainReq = KNWHAL_u8INPUT_STAGE_IDX_6;
         break;
      case 7:
         KnkAcqFilt_noSigConvGainReq = KNWHAL_u8INPUT_STAGE_IDX_7;
         break;
      case 8:
         KnkAcqFilt_noSigConvGainReq = KNWHAL_u8INPUT_STAGE_IDX_8;
         break;
      case 9:
         KnkAcqFilt_noSigConvGainReq = KNWHAL_u8INPUT_STAGE_IDX_9;
         break;
      case 10:
         KnkAcqFilt_noSigConvGainReq = KNWHAL_u8INPUT_STAGE_IDX_10;
         break;
      case 11:
         KnkAcqFilt_noSigConvGainReq = KNWHAL_u8INPUT_STAGE_IDX_11;
         break;
      case 12:
         KnkAcqFilt_noSigConvGainReq = KNWHAL_u8INPUT_STAGE_IDX_12;
         break;
      case 13:
         KnkAcqFilt_noSigConvGainReq = KNWHAL_u8INPUT_STAGE_IDX_13;
         break;
      case 14:
         KnkAcqFilt_noSigConvGainReq = KNWHAL_u8INPUT_STAGE_IDX_14;
         break;
      default:
         KnkAcqFilt_noSigConvGainReq = KNWHAL_u8INPUT_STAGE_IDX_15;
         break;
   }
   u8LocalOutputStageGain =
      KNWHAL_udtWriteInputStageGain(KnkAcqFilt_noSigConvGainReq);

   if (u8LocalOutputStageGain == E_OK)
   {
      KnkAcqFilt_noSigConvGainApp = KnkAcqFilt_noSigConvGain;
   }
   else
   {
      KnkAcqFilt_noSigConvGainApp = 0;
   }

   u16LocalCalcParam2 =
         MATHSRV_u16CalcParaIncAryU8(KnkAcqFilt_noSigConvGain_A,
                                     KnkAcqFilt_noSigConvGainApp,
                                     16);
   u8LocalrSigindex = (uint8)(u16LocalCalcParam2 >> 8);
   if (KnkAcqFilt_rSigConvNom_C == 0)
   {
      KnkAcqFilt_rSigConvGainApp = 32768 / 5;
   }
   else
   {
      u32LocalKnkAcqFilt_rSigConvGain =
         (uint32)( (32768 * KnkAcqFilt_rSigConvGain_T[u8LocalrSigindex])
                 / (5 * KnkAcqFilt_rSigConvNom_C));
      KnkAcqFilt_rSigConvGainApp =
         (uint16)MATHSRV_udtCLAMP (u32LocalKnkAcqFilt_rSigConvGain , 1, 65535);
   }
}
/*------------------------------- end of file --------------------------------*/