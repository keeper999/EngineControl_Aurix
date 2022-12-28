/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQCRWLRES                                               */
/* !Description     : TQCRWLRES Component.                                    */
/*                                                                            */
/* !Module          : TQCRWLRES                                               */
/* !Description     : Reserve de couple rampage BVMP.                         */
/*                                                                            */
/* !File            : TQCRWLRES_FCT1.C                                        */
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
/*   1 / TQCRWLRES_vidInitOutput                                              */
/*   2 / TQCRWLRES_vidReserveRampBVMP                                         */
/*   3 / TQCRWLRES_vidFilterCplBVMP                                           */
/*   4 / TQCRWLRES_vidCalcResRampageDyn                                       */
/*   5 / TQCRWLRES_vidCalcResRampageStat                                      */
/*                                                                            */
/* !Reference   : V02 NT 10 04975 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2909 / 2                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQCRWLRES/TQCRWLR$*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQCRWLRES.h"
#include "TQCRWLRES_L.h"
#include "TQCRWLRES_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCRWLRES_vidInitOutput                                    */
/* !Description :  Fonction d'initialisation des sorties                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 CoPt_tqMaxClu;                                               */
/*  input uint16 TqRes_tqMaxClu_A[8];                                         */
/*  input uint16 TqRes_tqMaxClu_T[8];                                         */
/*  input sint16 CoPt_tqReqClu;                                               */
/*  input uint16 TqRes_tqReqClu_A[8];                                         */
/*  input uint16 TqRes_tqReqClu_T[8];                                         */
/*  input uint16 TqRes_tqIdlRes;                                              */
/*  input uint16 TqRes_tqCrwlResPrev;                                         */
/*  output uint16 TqRes_tqCrwlRes;                                            */
/*  output uint16 TqRes_tqCrwlResPrev;                                        */
/*  output uint32 TQCRWLRES_u32Filtre1Mem;                                    */
/*  output sint16 TqRes_tqMaxClu;                                             */
/*  output uint32 TQCRWLRES_u32Filtre2Mem;                                    */
/*  output sint16 TqRes_tqReqClu;                                             */
/*  output sint16 TqRes_tqCrwlResDyn;                                         */
/*  output sint16 TqRes_tqCrwlResStat;                                        */
/*  output boolean TQCRWLRES_bCPtAcvDyTqResCrwlPrev;                          */
/*  output boolean TQCRWLRES_bCPtAcvStTqResCrwlPrev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCRWLRES_vidInitOutput(void)
{
   uint16 u16LocalInputBkpt;
   uint16 u16LocalCalcPara;
   uint16 u16LocalInterp;
   uint16 u16LocalTqRes_tqIdlRes;
   uint16 u16LocalInitValue;
   sint16 s16LocalCoPt_tqMaxClu;
   sint16 s16LocalCoPt_tqReqClu;
   sint16 s16LocalInitValue;
   sint32 s32LocalVar;


   /*Outputs and Internals Initialization*/
   VEMS_vidSET(TqRes_tqCrwlRes, 0);
   TqRes_tqCrwlResPrev = 0;

   /*F11_01_Filtrer_couples_BVMP */
   /*TqRes_tqMaxClu*/
   VEMS_vidGET(CoPt_tqMaxClu, s16LocalCoPt_tqMaxClu);
   s32LocalVar = (sint32)(s16LocalCoPt_tqMaxClu + 1600);
   u16LocalInputBkpt = (uint16)MATHSRV_udtCLAMP(s32LocalVar, 0, 3200);

   u16LocalCalcPara =
      MATHSRV_u16CalcParaIncAryU16(TqRes_tqMaxClu_A, u16LocalInputBkpt, 8);
   u16LocalInterp = MATHSRV_u16Interp1d(TqRes_tqMaxClu_T, u16LocalCalcPara);

   u16LocalInterp = (uint16)MATHSRV_udtMIN(u16LocalInterp, 3200);
   TQCRWLRES_u32Filtre1Mem = (uint32)(u16LocalInterp * 256);
   TqRes_tqMaxClu = (sint16)(u16LocalInterp - 1600);

   /*TqRes_tqReqClu*/
   VEMS_vidGET(CoPt_tqReqClu, s16LocalCoPt_tqReqClu);
   s32LocalVar = (sint32)(s16LocalCoPt_tqReqClu + 1600);
   u16LocalInputBkpt = (uint16)MATHSRV_udtCLAMP(s32LocalVar, 0, 3200);

   u16LocalCalcPara =
      MATHSRV_u16CalcParaIncAryU16(TqRes_tqReqClu_A, u16LocalInputBkpt, 8);
   u16LocalInterp = MATHSRV_u16Interp1d(TqRes_tqReqClu_T, u16LocalCalcPara);

   u16LocalInterp = (uint16)MATHSRV_udtMIN(u16LocalInterp, 3200);
   TQCRWLRES_u32Filtre2Mem = (uint32)(u16LocalInterp * 256);
   TqRes_tqReqClu = (sint16)(u16LocalInterp - 1600);

   /*F11_02_Calculer_.._dynamique & F11_03_Calculer_.._statique*/
   VEMS_vidGET(TqRes_tqIdlRes, u16LocalTqRes_tqIdlRes);
   u16LocalInitValue =
      (uint16)MATHSRV_udtMAX(TqRes_tqCrwlResPrev, u16LocalTqRes_tqIdlRes);
   s16LocalInitValue = (sint16)MATHSRV_udtMIN(u16LocalInitValue, 1600);

   TqRes_tqCrwlResDyn = s16LocalInitValue;
   TqRes_tqCrwlResStat = s16LocalInitValue;

   TQCRWLRES_bCPtAcvDyTqResCrwlPrev = 0;
   TQCRWLRES_bCPtAcvStTqResCrwlPrev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCRWLRES_vidReserveRampBVMP                               */
/* !Description :  Fonction de calcul de la reserve de couple rampage         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_00181_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TQCRWLRES_vidFilterCplBVMP();                            */
/*  extf argret void TQCRWLRES_vidCalcResRampageDyn();                        */
/*  extf argret void TQCRWLRES_vidCalcResRampageStat();                       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input uint16 TqRes_tqCrwlRes;                                             */
/*  input sint16 TqRes_tqCrwlResDyn;                                          */
/*  input sint16 TqRes_tqCrwlResStat;                                         */
/*  input sint16 TqRes_tqCrwlResSat_MP;                                       */
/*  output uint16 TqRes_tqCrwlResPrev;                                        */
/*  output sint16 TqRes_tqCrwlResSat_MP;                                      */
/*  output uint16 TqRes_tqCrwlRes;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCRWLRES_vidReserveRampBVMP(void)
{
   uint8  u8LocalExt_stGBxCf;
   uint16 u16LocalTqRes_tqCrwlRes;
   sint16 s16LocalTqRes_tqCrwlResSat_MP;


   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   if (u8LocalExt_stGBxCf == 2)
   {
      VEMS_vidGET(TqRes_tqCrwlRes, u16LocalTqRes_tqCrwlRes);
      TqRes_tqCrwlResPrev =
         (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqCrwlRes, 1600);
      TQCRWLRES_vidFilterCplBVMP();
      TQCRWLRES_vidCalcResRampageDyn();
      TQCRWLRES_vidCalcResRampageStat();
      s16LocalTqRes_tqCrwlResSat_MP =
         (sint16)MATHSRV_udtMAX(TqRes_tqCrwlResDyn,TqRes_tqCrwlResStat);
      TqRes_tqCrwlResSat_MP =
         (sint16)MATHSRV_udtCLAMP(s16LocalTqRes_tqCrwlResSat_MP, -1600, 1600);
      u16LocalTqRes_tqCrwlRes =
         (uint16)MATHSRV_udtMAX(TqRes_tqCrwlResSat_MP, 0);
      VEMS_vidSET(TqRes_tqCrwlRes, u16LocalTqRes_tqCrwlRes);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCRWLRES_vidFilterCplBVMP                                 */
/* !Description :  Un traitement des couples issues de la BVMP est réalisée,  */
/*                 ceci afin d’éviter d’introduire du bruit sur le couple de  */
/*                 réserve rampage.                                           */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_00181_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 CoPt_tqMaxClu;                                               */
/*  input uint16 TqRes_tqMaxClu_A[8];                                         */
/*  input uint16 TqRes_tqMaxClu_T[8];                                         */
/*  input uint8 TqRes_facFilTqMaxClu_C;                                       */
/*  input uint32 TQCRWLRES_u32Filtre1Mem;                                     */
/*  input sint16 CoPt_tqReqClu;                                               */
/*  input uint16 TqRes_tqReqClu_A[8];                                         */
/*  input uint16 TqRes_tqReqClu_T[8];                                         */
/*  input uint8 TqRes_facFilTqReqClu_C;                                       */
/*  input uint32 TQCRWLRES_u32Filtre2Mem;                                     */
/*  output uint32 TQCRWLRES_u32Filtre1Mem;                                    */
/*  output sint16 TqRes_tqMaxClu;                                             */
/*  output uint32 TQCRWLRES_u32Filtre2Mem;                                    */
/*  output sint16 TqRes_tqReqClu;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCRWLRES_vidFilterCplBVMP(void)
{
   uint8  u8LocalFilterGain2;
   uint8  u8LocalFilterGain;
   uint16 u16LocalTqResTqMaxClu;
   uint16 u16LocalTqRestqReqClu;
   uint16 u16LocalTQCRWLRES_Interpolation;
   uint16 u16LocalCalcPara;
   uint16 u16LocalCoPt_tqMaxClu;
   uint16 u16LocalCoPt_tqReqClu;
   uint16 u16LocalCalcPara2;
   uint16 u16LocalTQCRWLRES_Interpolation2;
   sint16 s16LocalCoPt_tqMaxClu;
   sint16 s16LocalCoPt_tqReqClu;
   sint32 s32LocalCoPt_tqReqClu;
   sint32 s32LocalCoPt_tqMaxClu;
   sint32 s32LocalTqResTqMaxClu;
   sint32 s32LocalTqRes_tqReqClu;


   VEMS_vidGET(CoPt_tqMaxClu, s16LocalCoPt_tqMaxClu);
   s32LocalCoPt_tqMaxClu = (sint32)(s16LocalCoPt_tqMaxClu + 1600);
   u16LocalCoPt_tqMaxClu =
      (uint16)MATHSRV_udtCLAMP(s32LocalCoPt_tqMaxClu, 0, 3200);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(TqRes_tqMaxClu_A,
                                                   u16LocalCoPt_tqMaxClu,
                                                   8);
   u16LocalTQCRWLRES_Interpolation =
      MATHSRV_u16Interp1d(TqRes_tqMaxClu_T, u16LocalCalcPara);
   if (TqRes_facFilTqMaxClu_C < 128)
   {
      u8LocalFilterGain = (uint8)(TqRes_facFilTqMaxClu_C * 2);
      u16LocalTqResTqMaxClu =
         MATHSRV_u16FirstOrderFilterGu8(u8LocalFilterGain,
                                        &TQCRWLRES_u32Filtre1Mem,
                                        u16LocalTQCRWLRES_Interpolation);
   }
   else
   {
      u16LocalTqResTqMaxClu = u16LocalTQCRWLRES_Interpolation;
      TQCRWLRES_u32Filtre1Mem =
         (uint32)(u16LocalTQCRWLRES_Interpolation * 256);
   }
   s32LocalTqResTqMaxClu = (sint32)(u16LocalTqResTqMaxClu - 1600);
   TqRes_tqMaxClu = (sint16) MATHSRV_udtMIN(s32LocalTqResTqMaxClu, 1600);
   VEMS_vidGET(CoPt_tqReqClu, s16LocalCoPt_tqReqClu);
   s32LocalCoPt_tqReqClu = (sint32)(s16LocalCoPt_tqReqClu + 1600);
   u16LocalCoPt_tqReqClu = (uint16)MATHSRV_udtMAX(s32LocalCoPt_tqReqClu, 0);
   u16LocalCalcPara2 = MATHSRV_u16CalcParaIncAryU16(TqRes_tqReqClu_A,
                                                    u16LocalCoPt_tqReqClu,
                                                    8);
   u16LocalTQCRWLRES_Interpolation2 =
      MATHSRV_u16Interp1d(TqRes_tqReqClu_T, u16LocalCalcPara2);
   if (TqRes_facFilTqReqClu_C < 128)
   {
      u8LocalFilterGain2 = (uint8)(TqRes_facFilTqReqClu_C * 2);
      u16LocalTqRestqReqClu =
         MATHSRV_u16FirstOrderFilterGu8(u8LocalFilterGain2,
                                        &TQCRWLRES_u32Filtre2Mem,
                                        u16LocalTQCRWLRES_Interpolation2);
   }
   else
   {
      u16LocalTqRestqReqClu = u16LocalTQCRWLRES_Interpolation2;
      TQCRWLRES_u32Filtre2Mem =
         (uint32)(u16LocalTQCRWLRES_Interpolation2 * 256);
   }
   s32LocalTqRes_tqReqClu = (sint32)(u16LocalTqRestqReqClu - 1600);
   TqRes_tqReqClu = (sint16) MATHSRV_udtMIN(s32LocalTqRes_tqReqClu,1600);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCRWLRES_vidCalcResRampageDyn                             */
/* !Description :  Fonction de Calcul de la reserve de rampage dynamique      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_04975_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoPt_bAcvDynTqResCrawl;                                     */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint8 TqRes_spdVehCrwlRes_A[8];                                     */
/*  input uint16 TqRes_tqCrwlResDyn_M[8][8];                                  */
/*  input uint8 TqRes_tCo_A[8];                                               */
/*  input uint8 TqRes_facCorTqCrwlResDyn_T[8];                                */
/*  input boolean TqRes_bCfTqReqCluDyn_C;                                     */
/*  input sint16 TqRes_tqReqClu;                                              */
/*  input boolean TqRes_bCfTqMaxCluDyn_C;                                     */
/*  input sint16 TqRes_tqMaxClu;                                              */
/*  input uint16 TqRes_tqIncMaxCrwlResDyn_C;                                  */
/*  input sint16 TqRes_tqDecMaxCrwlResDyn_C;                                  */
/*  input boolean TQCRWLRES_bCPtAcvDyTqResCrwlPrev;                           */
/*  input sint16 TqRes_tqCrwlResDyn;                                          */
/*  input sint16 TqRes_tqCrwlResDynNoSat_MP;                                  */
/*  input uint16 TqRes_tqIdlRes;                                              */
/*  input uint16 TqRes_tqCrwlResPrev;                                         */
/*  output sint16 TqRes_tqCrwlResDynNoSat_MP;                                 */
/*  output sint16 TqRes_tqCrwlResDyn;                                         */
/*  output boolean TQCRWLRES_bCPtAcvDyTqResCrwlPrev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCRWLRES_vidCalcResRampageDyn(void)
{
   boolean bLocalCoPt_bAcvDynTqResCrawl;
   uint8   u8LocalCoPt_noEgdGearCord;
   uint8   u8LocalVeh_spdVeh;
   uint8   u8LocalTQCRWLRES_Interpolation2;
   uint8   u8LocalExt_tCoMes1;
   uint16  u16LocalTqRes_tqDecMax;
   uint16  u16LocalTqRes_tqIncMax;
   uint16  u16LocalCalcParaX;
   uint16  u16LocalCalcParaY;
   uint16  u16LocalVeh_spdVeh;
   uint16  u16LocalTQCRWLRES_Interpolation1;
   uint16  u16LocalCalcPara;
   uint16  u16LocalInitValue;
   uint16  u16LocalTqRes_tqIdlRes;
   sint16  s16LocalExt_tCoMes;
   sint16  s16LocalTqRes_tqDecMax1;
   sint16  s16LocalReqClu;
   sint16  s16LocalMaxClu;
   sint16  s16LocalTqRes_tqCrwlResDyn;
   sint32  s32LocalOutputSum;
   sint32  s32LocalExt_tCoMes1;


   VEMS_vidGET(CoPt_bAcvDynTqResCrawl, bLocalCoPt_bAcvDynTqResCrawl);

   if (bLocalCoPt_bAcvDynTqResCrawl == 0)
   {
      TqRes_tqCrwlResDynNoSat_MP = 0;
   }
   else
   {
      VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
      VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);
      VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);

      u16LocalVeh_spdVeh = (uint16)(u16LocalVeh_spdVeh / 32);

      u8LocalVeh_spdVeh = (uint8)MATHSRV_udtMIN(u16LocalVeh_spdVeh, 255);

      u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU8(TqRes_spdVehCrwlRes_A,
                                                      u8LocalVeh_spdVeh,
                                                      8);
      u16LocalCalcParaY = (uint16)(u8LocalCoPt_noEgdGearCord * 256);
      u16LocalCalcParaY = (uint16)MATHSRV_udtMIN(u16LocalCalcParaY, 1792);
      u16LocalTQCRWLRES_Interpolation1 =
         MATHSRV_u16Interp2d(&TqRes_tqCrwlResDyn_M[0][0],
                             u16LocalCalcParaX,
                             u16LocalCalcParaY,
                             8);

      s32LocalExt_tCoMes1 = (sint32)(s16LocalExt_tCoMes + 40);
      u8LocalExt_tCoMes1 = (uint8)MATHSRV_udtCLAMP(s32LocalExt_tCoMes1, 0, 254);
      u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(TqRes_tCo_A,
                                                     u8LocalExt_tCoMes1,
                                                     8);

      u8LocalTQCRWLRES_Interpolation2 =
         MATHSRV_u8Interp1d(TqRes_facCorTqCrwlResDyn_T, u16LocalCalcPara);

      if (TqRes_bCfTqReqCluDyn_C == 0)
      {
         s16LocalReqClu = 0;
      }
      else
      {
         s16LocalReqClu = TqRes_tqReqClu;
      }
      if (TqRes_bCfTqMaxCluDyn_C == 0)
      {
         s16LocalMaxClu = 0;
      }
      else
      {
         s16LocalMaxClu = TqRes_tqMaxClu;
      }
      s32LocalOutputSum = (sint32)( ( ( ( ( u16LocalTQCRWLRES_Interpolation1
                                          * u8LocalTQCRWLRES_Interpolation2)
                                        + 16)
                                      / 32)
                                    + s16LocalReqClu)
                                  - s16LocalMaxClu);
      TqRes_tqCrwlResDynNoSat_MP =
         (sint16)MATHSRV_udtCLAMP(s32LocalOutputSum, -1600, 1600);
   }

   u16LocalTqRes_tqIncMax = (uint16)(TqRes_tqIncMaxCrwlResDyn_C / 25);
   s16LocalTqRes_tqDecMax1 = (sint16)(((-1)* TqRes_tqDecMaxCrwlResDyn_C)/ 25);
   u16LocalTqRes_tqDecMax = (uint16)MATHSRV_udtMAX(s16LocalTqRes_tqDecMax1, 0);

   if ( (bLocalCoPt_bAcvDynTqResCrawl == 0)
      ||(TQCRWLRES_bCPtAcvDyTqResCrwlPrev != 0))
   {
      s16LocalTqRes_tqCrwlResDyn =
         MATHSRV_s16SlewFilter(TqRes_tqCrwlResDyn,
                               TqRes_tqCrwlResDynNoSat_MP,
                               u16LocalTqRes_tqIncMax,
                               u16LocalTqRes_tqDecMax);
      TqRes_tqCrwlResDyn =
         (sint16)MATHSRV_udtCLAMP(s16LocalTqRes_tqCrwlResDyn, -1600, 1600);
   }
   else
   {
      VEMS_vidGET(TqRes_tqIdlRes, u16LocalTqRes_tqIdlRes);
      u16LocalInitValue =
         (uint16)MATHSRV_udtMAX(TqRes_tqCrwlResPrev, u16LocalTqRes_tqIdlRes);
      TqRes_tqCrwlResDyn = (sint16)MATHSRV_udtMIN(u16LocalInitValue, 1600);
   }
   TQCRWLRES_bCPtAcvDyTqResCrwlPrev = bLocalCoPt_bAcvDynTqResCrawl;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCRWLRES_vidCalcResRampageStat                            */
/* !Description :  Fonction de Calcul de la reserve de rampage statique       */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_04975_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoPt_bAcvStatTqResCrawl;                                    */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint8 TqRes_spdVehCrwlRes_A[8];                                     */
/*  input uint16 TqRes_tqCrwlResStat_M[8][8];                                 */
/*  input uint8 TqRes_tCo_A[8];                                               */
/*  input uint8 TqRes_facCorTqCrwlResStat_T[8];                               */
/*  input boolean TqRes_bCfTqReqCluStat_C;                                    */
/*  input sint16 TqRes_tqReqClu;                                              */
/*  input boolean TqRes_bCfTqMaxCluStat_C;                                    */
/*  input sint16 TqRes_tqMaxClu;                                              */
/*  input uint16 TqRes_tqIncMaxCrwlResStat_C;                                 */
/*  input sint16 TqRes_tqDecMaxCrwlResStat_C;                                 */
/*  input boolean TQCRWLRES_bCPtAcvStTqResCrwlPrev;                           */
/*  input sint16 TqRes_tqCrwlResStat;                                         */
/*  input sint16 TqRes_tqCrwlResStatNoSat_MP;                                 */
/*  input uint16 TqRes_tqIdlRes;                                              */
/*  input uint16 TqRes_tqCrwlResPrev;                                         */
/*  output sint16 TqRes_tqCrwlResStatNoSat_MP;                                */
/*  output sint16 TqRes_tqCrwlResStat;                                        */
/*  output boolean TQCRWLRES_bCPtAcvStTqResCrwlPrev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCRWLRES_vidCalcResRampageStat(void)
{
   boolean bLocalCoPt_bAcvStatTqResCrawl;
   uint8   u8LocalCoPt_noEgdGearCord;
   uint8   u8LocalVeh_spdVeh;
   uint8   u8LocalTQCRWLRES_Interpolation2;
   uint8   u8LocalExt_tCoMes1;
   uint16  u16LocalTqRes_tqDecMax;
   uint16  u16LocalTqRes_tqIncMax;
   uint16  u16LocalCalcParaX;
   uint16  u16LocalCalcParaY;
   uint16  u16LocalVeh_spdVeh;
   uint16  u16LocalTQCRWLRES_Interpolation1;
   uint16  u16LocalCalcPara;
   uint16  u16LocalInitValue;
   uint16  u16LocalTqRes_tqIdlRes;
   sint16  s16LocalExt_tCoMes;
   sint16  s16LocalTqRes_tqDecMax1;
   sint16  s16LocalReqClu;
   sint16  s16LocalMaxClu;
   sint16  s16LocalTqRes_tqCrwlResStat;
   sint32  s32LocalOutputSum;
   sint32  s32LocalExt_tCoMes1;


   VEMS_vidGET(CoPt_bAcvStatTqResCrawl, bLocalCoPt_bAcvStatTqResCrawl);

   if (bLocalCoPt_bAcvStatTqResCrawl == 0)
   {
      TqRes_tqCrwlResStatNoSat_MP = 0;
   }
   else
   {
      VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
      VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);
      VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);

      u16LocalVeh_spdVeh = (uint16)(u16LocalVeh_spdVeh / 32);

      u8LocalVeh_spdVeh = (uint8)MATHSRV_udtMIN(u16LocalVeh_spdVeh, 255);

      u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU8(TqRes_spdVehCrwlRes_A,
                                                      u8LocalVeh_spdVeh,
                                                      8);
      u16LocalCalcParaY = (uint16)(u8LocalCoPt_noEgdGearCord * 256);
      u16LocalCalcParaY = (uint16)MATHSRV_udtMIN(u16LocalCalcParaY, 1792);
      u16LocalTQCRWLRES_Interpolation1 =
         MATHSRV_u16Interp2d(&TqRes_tqCrwlResStat_M[0][0],
                             u16LocalCalcParaX,
                             u16LocalCalcParaY,
                             8);

      s32LocalExt_tCoMes1 = (sint32)(s16LocalExt_tCoMes + 40);
      u8LocalExt_tCoMes1 = (uint8)MATHSRV_udtCLAMP(s32LocalExt_tCoMes1, 0, 254);
      u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(TqRes_tCo_A,
                                                     u8LocalExt_tCoMes1,
                                                     8);

      u8LocalTQCRWLRES_Interpolation2 =
         MATHSRV_u8Interp1d(TqRes_facCorTqCrwlResStat_T, u16LocalCalcPara);

      if (TqRes_bCfTqReqCluStat_C == 0)
      {
         s16LocalReqClu = 0;
      }
      else
      {
         s16LocalReqClu = TqRes_tqReqClu;
      }
      if (TqRes_bCfTqMaxCluStat_C == 0)
      {
         s16LocalMaxClu = 0;
      }
      else
      {
         s16LocalMaxClu = TqRes_tqMaxClu;
      }
      s32LocalOutputSum = (sint32)( ( ( ( ( u16LocalTQCRWLRES_Interpolation1
                                          * u8LocalTQCRWLRES_Interpolation2)
                                        + 16)
                                      / 32)
                                    + s16LocalReqClu)
                                  - s16LocalMaxClu);
      TqRes_tqCrwlResStatNoSat_MP =
         (sint16)(MATHSRV_udtCLAMP(s32LocalOutputSum, -1600, 1600));
   }

   u16LocalTqRes_tqIncMax = (uint16)(TqRes_tqIncMaxCrwlResStat_C / 25);
   s16LocalTqRes_tqDecMax1 = (sint16)(((-1)* TqRes_tqDecMaxCrwlResStat_C) / 25);
   u16LocalTqRes_tqDecMax = (uint16)MATHSRV_udtMAX(s16LocalTqRes_tqDecMax1, 0);

   if ( (bLocalCoPt_bAcvStatTqResCrawl == 0)
      ||(TQCRWLRES_bCPtAcvStTqResCrwlPrev != 0))
   {
      s16LocalTqRes_tqCrwlResStat =
         MATHSRV_s16SlewFilter(TqRes_tqCrwlResStat,
                               TqRes_tqCrwlResStatNoSat_MP,
                               u16LocalTqRes_tqIncMax,
                               u16LocalTqRes_tqDecMax);
      TqRes_tqCrwlResStat =
         (sint16)MATHSRV_udtCLAMP(s16LocalTqRes_tqCrwlResStat, -1600, 1600);
   }
   else
   {
      VEMS_vidGET(TqRes_tqIdlRes, u16LocalTqRes_tqIdlRes);
      u16LocalInitValue =
         (uint16)MATHSRV_udtMAX(TqRes_tqCrwlResPrev, u16LocalTqRes_tqIdlRes);
      TqRes_tqCrwlResStat = (sint16)MATHSRV_udtMIN(u16LocalInitValue, 1600);
   }
   TQCRWLRES_bCPtAcvStTqResCrwlPrev = bLocalCoPt_bAcvStatTqResCrawl;
}

/*------------------------------- end of file --------------------------------*/