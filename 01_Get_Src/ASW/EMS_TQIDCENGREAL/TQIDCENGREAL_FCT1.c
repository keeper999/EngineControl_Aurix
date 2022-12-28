/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQIDCENGREAL                                            */
/* !Description     : TQIDCENGREAL Component                                  */
/*                                                                            */
/* !Module          : TQIDCENGREAL                                            */
/* !Description     : ESTIMER COUPLE REEL                                     */
/*                                                                            */
/* !File            : TQIDCENGREAL_FCT1.C                                     */
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
/*   1 / TQIDCENGREAL_vidInitOutput                                           */
/*   2 / TQIDCENGREAL_vidEstimCplIndiqRel                                     */
/*   3 / TQIDCENGREAL_vidEstimRmplissgAir                                     */
/*   4 / TQIDCENGREAL_vidEstimCpleOptimum                                     */
/*   5 / TQIDCENGREAL_vidEstimRendmAvance                                     */
/*   6 / TQIDCENGREAL_vidEstimAvcOptimal                                      */
/*   7 / TQIDCENGREAL_vidCalcRendmntAvanc                                     */
/*   8 / TQIDCENGREAL_vidEstimCplRelRdmnt                                     */
/*   9 / TQIDCENGREAL_vidEstimcpleminimum                                     */
/*                                                                            */
/* !Reference   : V02 NT 10 01238 / 03                                        */
/* !OtherRefs   : CSCT_CGMT09_2402 / 1.3                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQIDCENGREAL/TQIDCENGR$*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "STD_LIMITS.h"
#include "TQIDCENGREAL.H"
#include "TQIDCENGREAL_L.H"
#include "TQIDCENGREAL_IM.H"
#include "MATHSRV.H"
#include "VEMS.H"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQIDCENGREAL_vidInitOutput                                 */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_nCkFilBuf;                                           */
/*  input uint16 SftyMgt_pDsThrCor;                                           */
/*  input uint16 SftyMgt_nCkFil_rAirLdX_A[8];                                 */
/*  input uint16 SftyMgt_pDsThr_rAirLdY_A[8];                                 */
/*  input uint16 SftyMgt_rAirLdEstim_M[8][8];                                 */
/*  input uint16 SftyMgt_rAirLdEstimRaw_MP;                                   */
/*  input uint16 SftyMgt_rAirLdEstim;                                         */
/*  output uint16 SftyMgt_tqIdcEngCurEstim;                                   */
/*  output sint16 SftyMgt_tqIdcAgIgMin;                                       */
/*  output uint16 SftyMgt_rAirLdEstimRaw_MP;                                  */
/*  output uint16 SftyMgt_rAirLdEstim;                                        */
/*  output uint32 TQIDCENGREAL_u32FilterMem;                                  */
/*  output sint32 SftyMgt_rAirLdEstimGrd_MP;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQIDCENGREAL_vidInitOutput(void)
{
   uint16   u16Local_nCkFilBuf;
   uint16   u16Local_pDsThrCor;
   uint16   u16LocalParaX;
   uint16   u16LocalParaY;
   uint16   u16LocalrAirLdEstim;


   VEMS_vidSET(SftyMgt_tqIdcEngCurEstim, 0);
   VEMS_vidSET(SftyMgt_tqIdcAgIgMin, 0);

   VEMS_vidGET(SftyMgt_nCkFilBuf, u16Local_nCkFilBuf);
   VEMS_vidGET(SftyMgt_pDsThrCor, u16Local_pDsThrCor);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(SftyMgt_nCkFil_rAirLdX_A,
                                                u16Local_nCkFilBuf,
                                                8);

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(SftyMgt_pDsThr_rAirLdY_A,
                                                u16Local_pDsThrCor,
                                                8);

   u16LocalrAirLdEstim = MATHSRV_u16Interp2d(&SftyMgt_rAirLdEstim_M[0][0],
                                             u16LocalParaX,
                                             u16LocalParaY,
                                             8);
   SftyMgt_rAirLdEstimRaw_MP =
      (uint16)MATHSRV_udtMIN(u16LocalrAirLdEstim, 49152);
   SftyMgt_rAirLdEstim = SftyMgt_rAirLdEstimRaw_MP;
   TQIDCENGREAL_u32FilterMem = (SftyMgt_rAirLdEstim * (uint32)65536);
   SftyMgt_rAirLdEstimGrd_MP = (sint32)SftyMgt_rAirLdEstimRaw_MP;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQIDCENGREAL_vidEstimCplIndiqRel                           */
/* !Description :  Cette fonction estime le couple réel                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQIDCENGREAL_vidEstimRmplissgAir();                      */
/*  extf argret void TQIDCENGREAL_vidEstimCpleOptimum();                      */
/*  extf argret void TQIDCENGREAL_vidEstimRendmAvance();                      */
/*  extf argret void TQIDCENGREAL_vidEstimCplRelRdmnt();                      */
/*  extf argret void TQIDCENGREAL_vidEstimcpleminimum();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQIDCENGREAL_vidEstimCplIndiqRel(void)
{
   TQIDCENGREAL_vidEstimRmplissgAir();
   TQIDCENGREAL_vidEstimCpleOptimum();
   TQIDCENGREAL_vidEstimRendmAvance();
   TQIDCENGREAL_vidEstimCplRelRdmnt();
   TQIDCENGREAL_vidEstimcpleminimum();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQIDCENGREAL_vidEstimRmplissgAir                           */
/* !Description :  Cette fonction estime le remplissage en air frais à partir */
/*                 d’une cartographie Régime / Pression admission.            */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01238_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_nCkFilBuf;                                           */
/*  input uint16 SftyMgt_pDsThrCor;                                           */
/*  input uint16 SftyMgt_rAirLdEstimRaw_MP;                                   */
/*  input uint16 SftyMgt_nCkFil_rAirLdX_A[8];                                 */
/*  input uint16 SftyMgt_pDsThr_rAirLdY_A[8];                                 */
/*  input uint16 SftyMgt_rAirLdEstim_M[8][8];                                 */
/*  input sint32 SftyMgt_rAirLdEstimGrd_MP;                                   */
/*  input uint16 SftyMgt_rAirLdGrdThd_C;                                      */
/*  input uint8 SftyMgt_tiAirLdTauFilUp_C;                                    */
/*  input uint8 SftyMgt_tiAirLdTauFilDown_C;                                  */
/*  input uint32 TQIDCENGREAL_u32FilterMem;                                   */
/*  output uint16 SftyMgt_rAirLdEstimRaw_MP;                                  */
/*  output sint32 SftyMgt_rAirLdEstimGrd_MP;                                  */
/*  output uint32 TQIDCENGREAL_u32FilterMem;                                  */
/*  output uint16 SftyMgt_rAirLdEstim;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQIDCENGREAL_vidEstimRmplissgAir(void)
{
   uint8    u8LocalAirLdTauFil;
   uint16   u16Local_nCkFilBuf;
   uint16   u16Local_pDsThrCor;
   uint16   u16LocalParaX;
   uint16   u16LocalParaY;
   uint16   u16LocalrAirLdEstim;
   uint16   u16LocalrAirLdEstimRawPrev;
   uint16   u16LocalFilterOutput;
   uint32   u32LocalFilterGain;
   sint32   s32LocalAirLdEstimGrd;


   VEMS_vidGET(SftyMgt_nCkFilBuf, u16Local_nCkFilBuf);
   VEMS_vidGET(SftyMgt_pDsThrCor, u16Local_pDsThrCor);

   u16LocalrAirLdEstimRawPrev = SftyMgt_rAirLdEstimRaw_MP;

   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(SftyMgt_nCkFil_rAirLdX_A,
                                                u16Local_nCkFilBuf,
                                                8);

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(SftyMgt_pDsThr_rAirLdY_A,
                                                u16Local_pDsThrCor,
                                                8);

   u16LocalrAirLdEstim = MATHSRV_u16Interp2d(&SftyMgt_rAirLdEstim_M[0][0],
                                             u16LocalParaX,
                                             u16LocalParaY,
                                             8);
   SftyMgt_rAirLdEstimRaw_MP =
      (uint16)MATHSRV_udtMIN(u16LocalrAirLdEstim, 49152);

   s32LocalAirLdEstimGrd =
      (sint32)(SftyMgt_rAirLdEstimRaw_MP - u16LocalrAirLdEstimRawPrev);
   SftyMgt_rAirLdEstimGrd_MP = MATHSRV_udtMAX(s32LocalAirLdEstimGrd, -49152);

   if (SftyMgt_rAirLdEstimGrd_MP >= SftyMgt_rAirLdGrdThd_C)
   {
      u8LocalAirLdTauFil = SftyMgt_tiAirLdTauFilUp_C;
   }
   else
   {
      u8LocalAirLdTauFil = SftyMgt_tiAirLdTauFilDown_C;
   }
   u32LocalFilterGain = (uint32)( ( SftyMgt_tiSdlTqIdcEngReal_SC
                                  * 65536)
                                / ( SftyMgt_tiSdlTqIdcEngReal_SC
                                  + ( u8LocalAirLdTauFil
                                    * 50)));
   if (u32LocalFilterGain < 65536)
   {
      u16LocalFilterOutput =
         MATHSRV_u16FirstOrderFilterGu16((uint16)u32LocalFilterGain,
                                         &TQIDCENGREAL_u32FilterMem,
                                         SftyMgt_rAirLdEstimRaw_MP);
   }
   else
   {
      u16LocalFilterOutput = SftyMgt_rAirLdEstimRaw_MP;
      TQIDCENGREAL_u32FilterMem = (SftyMgt_rAirLdEstimRaw_MP * (uint32)65536);
   }

   SftyMgt_rAirLdEstim = (uint16)MATHSRV_udtMIN(u16LocalFilterOutput, 49152);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQIDCENGREAL_vidEstimCpleOptimum                           */
/* !Description :  Cette fonction permet d’évaluer le couple optimum en       */
/*                 fonction du régime et du  remplissage en air estimé.       */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01238_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_nCkFilBuf;                                           */
/*  input uint16 SftyMgt_nCkFil_TqIdcOptmX_A[8];                              */
/*  input uint16 SftyMgt_rAirLdEstim_TqIdcOptmY_A[8];                         */
/*  input uint16 SftyMgt_rAirLdEstim;                                         */
/*  input uint16 SftyMgt_tqIdcOptmEstim_M[8][8];                              */
/*  output uint16 SftyMgt_tqIdcOptmEngCurEstim;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQIDCENGREAL_vidEstimCpleOptimum(void)
{
   uint16   u16Local_nCkFilBuf;
   uint16   u16LocalParaX;
   uint16   u16LocalParaY;
   uint16   u16LocaltqIdcOptmEngCurEstim;


   VEMS_vidGET(SftyMgt_nCkFilBuf, u16Local_nCkFilBuf);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(SftyMgt_nCkFil_TqIdcOptmX_A,
                                                u16Local_nCkFilBuf,
                                                8);

   u16LocalParaY =
      MATHSRV_u16CalcParaIncAryU16(SftyMgt_rAirLdEstim_TqIdcOptmY_A,
                                   SftyMgt_rAirLdEstim,
                                   8);

   u16LocaltqIdcOptmEngCurEstim =
      MATHSRV_u16Interp2d(&SftyMgt_tqIdcOptmEstim_M[0][0],
                          u16LocalParaX,
                          u16LocalParaY,
                          8);
   SftyMgt_tqIdcOptmEngCurEstim =
      (uint16)MATHSRV_udtMIN(u16LocaltqIdcOptmEngCurEstim, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQIDCENGREAL_vidEstimRendmAvance                           */
/* !Description :  Cette fonction calcul l’avance optimale en fonction du     */
/*                 régime et de la pression admission. Puis à partir de       */
/*                 l’avance appliquée par l’ACS, elle calcule le rendement    */
/*                 d’avance à appliquer dans le calcul du couple indiqué      */
/*                 estimé par la TMS.                                         */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01238_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQIDCENGREAL_vidEstimAvcOptimal();                       */
/*  extf argret void TQIDCENGREAL_vidCalcRendmntAvanc();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQIDCENGREAL_vidEstimRendmAvance(void)
{
   TQIDCENGREAL_vidEstimAvcOptimal();
   TQIDCENGREAL_vidCalcRendmntAvanc();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQIDCENGREAL_vidEstimAvcOptimal                            */
/* !Description :  Cette fonction estime l’avance optimale appliquée pour le  */
/*                 point de régime et de pression admission courant.          */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01238_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_nCkFilBuf;                                           */
/*  input uint16 SftyMgt_pDsThrCor;                                           */
/*  input uint16 SftyMgt_nCkFil_agIgOptmX_A[8];                               */
/*  input uint16 SftyMgt_pDsThr_agIgOptmY_A[8];                               */
/*  input uint16 SftyMgt_agIgOptmEstim_M[8][8];                               */
/*  output sint16 SftyMgt_agIgAdvOptmEstim;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQIDCENGREAL_vidEstimAvcOptimal(void)
{
   uint16   u16Local_nCkFilBuf;
   uint16   u16Local_pDsThrCor;
   uint16   u16Local_SftyMgtAgIgAdvOptmEstim;
   sint16   s16Local_SftyMgtAgIgAdvOptmEstim;
   uint16   u16LocalParaX;
   uint16   u16LocalParaY;

   VEMS_vidGET(SftyMgt_nCkFilBuf, u16Local_nCkFilBuf);
   VEMS_vidGET(SftyMgt_pDsThrCor, u16Local_pDsThrCor);

   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(SftyMgt_nCkFil_agIgOptmX_A,
                                                u16Local_nCkFilBuf,
                                                8);

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(SftyMgt_pDsThr_agIgOptmY_A,
                                                u16Local_pDsThrCor,
                                                8);

   u16Local_SftyMgtAgIgAdvOptmEstim =
      MATHSRV_u16Interp2d(&SftyMgt_agIgOptmEstim_M[0][0],
                          u16LocalParaX,
                          u16LocalParaY,
                          8);
   s16Local_SftyMgtAgIgAdvOptmEstim =
      (sint16)(u16Local_SftyMgtAgIgAdvOptmEstim - 96);
   SftyMgt_agIgAdvOptmEstim =
      (sint16)MATHSRV_udtMIN(s16Local_SftyMgtAgIgAdvOptmEstim, 160);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQIDCENGREAL_vidCalcRendmntAvanc                           */
/* !Description :  Cette fonction réalise la différence entre l’avance        */
/*                 optimale et l’avance appliquée puis en déduit le rendement */
/*                 d’avance à appliquer sur le couple optimum, pour prendre en*/
/*                 compte cet écart par rapport à l’avance optimale.          */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01238_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 SftyMgt_agIgAdvCur;                                          */
/*  input sint16 SftyMgt_agIgAdvOptmEstim;                                    */
/*  input sint16 TQIDCENGREAL_s16agIgAdvDifOptCur;                            */
/*  input uint16 SftyMgt_agIgAdvDifOptmCurX_A[8];                             */
/*  input uint16 SftyMgt_effIgOptEstim_T[8];                                  */
/*  output sint16 TQIDCENGREAL_s16agIgAdvDifOptCur;                           */
/*  output uint16 SftyMgt_effAdvTqIdcEstim;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQIDCENGREAL_vidCalcRendmntAvanc(void)
{
   uint16   u16LocalParam;
   uint16   u16LocalagIgAdvDifOptCur;
   uint16   u16LocaleffAdvTqIdcEstim;
   sint16   s16Local_agIgAdvCur;
   sint32   s32LocalParam;


   VEMS_vidGET(SftyMgt_agIgAdvCur, s16Local_agIgAdvCur);

   s32LocalParam = (sint32)(SftyMgt_agIgAdvOptmEstim - s16Local_agIgAdvCur);

   TQIDCENGREAL_s16agIgAdvDifOptCur =
      (sint16)MATHSRV_udtCLAMP(s32LocalParam, -256, 256);
   u16LocalagIgAdvDifOptCur =
      (uint16)MATHSRV_udtABS(TQIDCENGREAL_s16agIgAdvDifOptCur);
   u16LocalagIgAdvDifOptCur = (uint16)(u16LocalagIgAdvDifOptCur + 96);
   u16LocalParam = MATHSRV_u16CalcParaIncAryU16(SftyMgt_agIgAdvDifOptmCurX_A,
                                                u16LocalagIgAdvDifOptCur,
                                                8);

   u16LocaleffAdvTqIdcEstim = MATHSRV_u16Interp1d(SftyMgt_effIgOptEstim_T,
                                                  u16LocalParam);
   SftyMgt_effAdvTqIdcEstim =
      (uint16)MATHSRV_udtMIN(u16LocaleffAdvTqIdcEstim, 1024);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQIDCENGREAL_vidEstimCplRelRdmnt                           */
/* !Description :  Cette fonction applique le rendement d’avance au couple    */
/*                 optimum calculé                                            */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01238_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 SftyMgt_noAcvCyl;                                             */
/*  input uint8 SftyMgt_noCyl_C;                                              */
/*  input uint16 SftyMgt_tqIdcOptmEngCurEstim;                                */
/*  input uint16 SftyMgt_effAdvTqIdcEstim;                                    */
/*  input uint16 SftyMgt_tqIdcEngRealMax_C;                                   */
/*  output uint16 SftyMgt_rAcvCyl;                                            */
/*  output uint16 SftyMgt_tqIdcEngCurEstim;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQIDCENGREAL_vidEstimCplRelRdmnt(void)
{
   /*F04_Estimer_couple_indiqu_reel_prise_en_compte_rendement*/
   uint8  u8LocalSftyMgt_noAcvCyl;
   uint16 u16LocalSftyMgt_rAcvCyl;
   uint16 u16LocalSftyMgt_tqIdcEngCurEstim;
   uint32 u32LocalMulti;
   uint32 u32LocalResult;


   VEMS_vidGET(SftyMgt_noAcvCyl, u8LocalSftyMgt_noAcvCyl);
   if (SftyMgt_noCyl_C == 0)
   {
      u16LocalSftyMgt_rAcvCyl = 1024;
      u32LocalResult = 32000;
   }
   else
   {
      u16LocalSftyMgt_rAcvCyl =
         (uint16)( (u8LocalSftyMgt_noAcvCyl * 1024) / SftyMgt_noCyl_C);
      u32LocalMulti =
         (uint32)(SftyMgt_tqIdcOptmEngCurEstim * SftyMgt_effAdvTqIdcEstim);
      if (u8LocalSftyMgt_noAcvCyl != 0)
      {
         if (u32LocalMulti <= (UINT32_MAX / (uint32)u8LocalSftyMgt_noAcvCyl))
         {
            u32LocalResult = u32LocalMulti * u8LocalSftyMgt_noAcvCyl;
            u32LocalResult = u32LocalResult / (uint32)(1024 * SftyMgt_noCyl_C);
         }
         else
         {
            u32LocalResult = u32LocalMulti / 256 ;
            u32LocalResult = ( (u32LocalResult * u8LocalSftyMgt_noAcvCyl)
                             / (4 * SftyMgt_noCyl_C));
         }
      }
      else
      {
         u32LocalResult = 0;
      }
   }
   SftyMgt_rAcvCyl = (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_rAcvCyl, 1024);

   u16LocalSftyMgt_tqIdcEngCurEstim =
      (uint16)MATHSRV_udtMIN(u32LocalResult,SftyMgt_tqIdcEngRealMax_C);
   u16LocalSftyMgt_tqIdcEngCurEstim =
      (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_tqIdcEngCurEstim,32000);
   VEMS_vidSET(SftyMgt_tqIdcEngCurEstim, u16LocalSftyMgt_tqIdcEngCurEstim);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQIDCENGREAL_vidEstimcpleminimum                           */
/* !Description :  Cette fonction estime le couple minimal réalisable du      */
/*                 régime moteur et de la pression d’admission.               */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01238_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 SftyMgt_nCkFilBuf;                                           */
/*  input uint16 SftyMgt_pDsThrCor;                                           */
/*  input uint16 SftyMgt_nCkFil_TqIdcAgIgMinX_A[8];                           */
/*  input uint16 SftyMgt_pDsThr_TqIdcAgIgMinY_A[8];                           */
/*  input uint16 SftyMgt_TqIdcAgIgMin_M[8][8];                                */
/*  input boolean SftyMgt_bTqIdcAgIgMinCor_C;                                 */
/*  input uint16 SftyMgt_rAcvCyl;                                             */
/*  output sint16 SftyMgt_tqIdcAgIgMin;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQIDCENGREAL_vidEstimcpleminimum(void)
{
   /*F05_Estimer_le_couple_minimum */
   uint16   u16Local_nCkFilBuf;
   uint16   u16Local_pDsThrCor;
   uint16   u16LocalParaX;
   uint16   u16LocalParaY;
   uint16   u16LocalResult;
   sint16   s16LocalTqIdcAgIgMin;
   sint32   s32LocalTqIdcAgIgMin;
   sint32   s32LocalResult;


   VEMS_vidGET(SftyMgt_nCkFilBuf, u16Local_nCkFilBuf);
   VEMS_vidGET(SftyMgt_pDsThrCor, u16Local_pDsThrCor);

   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(SftyMgt_nCkFil_TqIdcAgIgMinX_A,
                                                u16Local_nCkFilBuf,
                                                8);

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(SftyMgt_pDsThr_TqIdcAgIgMinY_A,
                                                u16Local_pDsThrCor,
                                                8);

   u16LocalResult = MATHSRV_u16Interp2d(&SftyMgt_TqIdcAgIgMin_M[0][0],
                                        u16LocalParaX,
                                        u16LocalParaY,
                                        8);
   s32LocalResult = (sint32)(u16LocalResult - 32000);
   if (SftyMgt_bTqIdcAgIgMinCor_C != 0)
   {
      s32LocalTqIdcAgIgMin = ((SftyMgt_rAcvCyl * s32LocalResult) / 1024);
   }
   else
   {
      s32LocalTqIdcAgIgMin = s32LocalResult;
   }
   s16LocalTqIdcAgIgMin = (sint16)MATHSRV_udtCLAMP(s32LocalTqIdcAgIgMin,
                                                   -32000,
                                                   32000);
   VEMS_vidSET(SftyMgt_tqIdcAgIgMin, s16LocalTqIdcAgIgMin);
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/******************************* <End_Of_File> ********************************/