/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQCATHEATRES                                            */
/* !Description     : TQCATHEATRES Component                                  */
/*                                                                            */
/* !Module          : TQCATHEATRES                                            */
/* !Description     : Réserve de couple chauffe catalyseur                    */
/*                                                                            */
/* !File            : TQCATHEATRES_FCT2.C                                     */
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
/*   1 / TQCATHEATRES_vidCalibration5                                         */
/*   2 / TQCATHEATRES_vidCalibration6                                         */
/*   3 / TQCATHEATRES_vidCalibration7                                         */
/*   4 / TQCATHEATRES_vidCalibration8                                         */
/*   5 / TQCATHEATRES_vidVectCalibrations                                     */
/*   6 / TQCATHEATRES_vidSelectModes                                          */
/*   7 / TQCATHEATRES_vidInterpolation                                        */
/*                                                                            */
/* !Reference   : V02 NT 10 08577 / 02                                        */
/* !OtherRefs   : 01460_10_01305 / 1.1                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQCATHEATRES/TQCA$*/
/* $Revision::   1.2      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.H"
#include "TQCATHEATRES.h"
#include "TQCATHEATRES_L.h"
#include "TQCATHEATRES_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCATHEATRES_vidCalibration5                               */
/* !Description :  Cette réserve de couple est calculée si et seulement si le */
/*                 booléen TqRes_bAcvEOMResMod5 le demande.                   */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08577_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input sint16 TqSys_tqIdcAirLimCordWoutRes;                                */
/*  input uint16 TqRes_nEngEOMResMod5_A[16];                                  */
/*  input uint16 TqRes_tqIdcAirEOMResMod5_A[16];                              */
/*  input uint16 TqRes_tqEOMResMod5_M[16][16];                                */
/*  output uint16 TqRes_tqEOMResMod5;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCATHEATRES_vidCalibration5(void)
{
   uint16 u16LocalEng_nCkFil;
   uint16 u16LocalTqSys_tqIdcAirCordWotRes;
   uint16 u16LocalTqResTqEOMResMod5;
   uint16 u16LocalCalcParaEngNCkFil;
   uint16 u16LocalCalcParaWoutRes;
   sint16 s16LocalTqSys_tqIdcAirCordWotRes;


   VEMS_vidGET(Eng_nCkFil , u16LocalEng_nCkFil);
   VEMS_vidGET(TqSys_tqIdcAirLimCordWoutRes , s16LocalTqSys_tqIdcAirCordWotRes);
   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   u16LocalCalcParaEngNCkFil =
      MATHSRV_u16CalcParaIncAryU16(TqRes_nEngEOMResMod5_A,
                                   u16LocalEng_nCkFil,
                                   16);
   s16LocalTqSys_tqIdcAirCordWotRes =
     (sint16)MATHSRV_udtCLAMP(s16LocalTqSys_tqIdcAirCordWotRes , -32000, 32000);
   u16LocalTqSys_tqIdcAirCordWotRes = (uint16)( s16LocalTqSys_tqIdcAirCordWotRes
                                              + 32000);
   u16LocalCalcParaWoutRes =
      MATHSRV_u16CalcParaIncAryU16(TqRes_tqIdcAirEOMResMod5_A,
                                   u16LocalTqSys_tqIdcAirCordWotRes,
                                   16);
   u16LocalTqResTqEOMResMod5 = MATHSRV_u16Interp2d(&TqRes_tqEOMResMod5_M[0][0],
                                                   u16LocalCalcParaEngNCkFil,
                                                   u16LocalCalcParaWoutRes,
                                                   16);
   TqRes_tqEOMResMod5 = (uint16)MATHSRV_udtMIN(u16LocalTqResTqEOMResMod5, 8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCATHEATRES_vidCalibration6                               */
/* !Description :  Cette réserve de couple est calculée si et seulement si le */
/*                 booléen TqRes_bAcvEOMResMod6 le demande.                   */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08577_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input sint16 TqSys_tqIdcAirLimCordWoutRes;                                */
/*  input uint16 TqRes_nEngEOMResMod6_A[16];                                  */
/*  input uint16 TqRes_tqIdcAirEOMResMod6_A[16];                              */
/*  input uint16 TqRes_tqEOMResMod6_M[16][16];                                */
/*  output uint16 TqRes_tqEOMResMod6;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCATHEATRES_vidCalibration6(void)
{
   uint16 u16LocalEng_nCkFil;
   uint16 u16LocalTqSys_tqIdcAirCordWotRes;
   uint16 u16LocalTqResTqEOMResMod6;
   uint16 u16LocalCalcParaEngNCkFil;
   uint16 u16LocalCalcParaWoutRes;
   sint16 s16LocalTqSys_tqIdcAirCordWotRes;


   VEMS_vidGET(Eng_nCkFil , u16LocalEng_nCkFil);
   VEMS_vidGET(TqSys_tqIdcAirLimCordWoutRes , s16LocalTqSys_tqIdcAirCordWotRes);
   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   u16LocalCalcParaEngNCkFil =
      MATHSRV_u16CalcParaIncAryU16(TqRes_nEngEOMResMod6_A,
                                   u16LocalEng_nCkFil,
                                   16);
   s16LocalTqSys_tqIdcAirCordWotRes =
     (sint16)MATHSRV_udtCLAMP(s16LocalTqSys_tqIdcAirCordWotRes , -32000, 32000);
   u16LocalTqSys_tqIdcAirCordWotRes = (uint16)( s16LocalTqSys_tqIdcAirCordWotRes
                                              + 32000);
   u16LocalCalcParaWoutRes =
      MATHSRV_u16CalcParaIncAryU16(TqRes_tqIdcAirEOMResMod6_A,
                                   u16LocalTqSys_tqIdcAirCordWotRes,
                                   16);
   u16LocalTqResTqEOMResMod6 = MATHSRV_u16Interp2d(&TqRes_tqEOMResMod6_M[0][0],
                                                   u16LocalCalcParaEngNCkFil,
                                                   u16LocalCalcParaWoutRes,
                                                   16);
   TqRes_tqEOMResMod6 = (uint16)MATHSRV_udtMIN(u16LocalTqResTqEOMResMod6, 8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCATHEATRES_vidCalibration7                               */
/* !Description :  Cette réserve de couple est calculée si et seulement si le */
/*                 booléen TqRes_bAcvEOMResMod7 le demande.                   */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08577_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input sint16 TqSys_tqIdcAirLimCordWoutRes;                                */
/*  input uint16 TqRes_nEngEOMResMod7_A[16];                                  */
/*  input uint16 TqRes_tqIdcAirEOMResMod7_A[16];                              */
/*  input uint16 TqRes_tqEOMResMod7_M[16][16];                                */
/*  output uint16 TqRes_tqEOMResMod7;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCATHEATRES_vidCalibration7(void)
{
   uint16 u16LocalEng_nCkFil;
   uint16 u16LocalTqSys_tqIdcAirCordWotRes;
   uint16 u16LocalTqResTqEOMResMod7;
   uint16 u16LocalCalcParaEngNCkFil;
   uint16 u16LocalCalcParaWoutRes;
   sint16 s16LocalTqSys_tqIdcAirCordWotRes;


   VEMS_vidGET(Eng_nCkFil , u16LocalEng_nCkFil);
   VEMS_vidGET(TqSys_tqIdcAirLimCordWoutRes , s16LocalTqSys_tqIdcAirCordWotRes);
   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   u16LocalCalcParaEngNCkFil =
      MATHSRV_u16CalcParaIncAryU16(TqRes_nEngEOMResMod7_A,
                                   u16LocalEng_nCkFil,
                                   16);
   s16LocalTqSys_tqIdcAirCordWotRes =
     (sint16)MATHSRV_udtCLAMP(s16LocalTqSys_tqIdcAirCordWotRes , -32000, 32000);
   u16LocalTqSys_tqIdcAirCordWotRes = (uint16)( s16LocalTqSys_tqIdcAirCordWotRes
                                              + 32000);
   u16LocalCalcParaWoutRes =
      MATHSRV_u16CalcParaIncAryU16(TqRes_tqIdcAirEOMResMod7_A,
                                   u16LocalTqSys_tqIdcAirCordWotRes,
                                   16);
   u16LocalTqResTqEOMResMod7 = MATHSRV_u16Interp2d(&TqRes_tqEOMResMod7_M[0][0],
                                                   u16LocalCalcParaEngNCkFil,
                                                   u16LocalCalcParaWoutRes,
                                                   16);
   TqRes_tqEOMResMod7 = (uint16)MATHSRV_udtMIN(u16LocalTqResTqEOMResMod7, 8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCATHEATRES_vidCalibration8                               */
/* !Description :  Cette réserve de couple est calculée si et seulement si le */
/*                 booléen TqRes_bAcvEOMResMod8 le demande.                   */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08577_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 TqRes_tqEOMResMod8;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCATHEATRES_vidCalibration8(void)
{
   TqRes_tqEOMResMod8 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCATHEATRES_vidVectCalibrations                           */
/* !Description :  Cette fonction crée un vecteur de réserves de couple       */
/*                 applicables.                                               */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08577_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 TqRes_tqEOMResMod1;                                          */
/*  input uint16 TqRes_tqEOMResMod2;                                          */
/*  input uint16 TqRes_tqEOMResMod3;                                          */
/*  input uint16 TqRes_tqEOMResMod4;                                          */
/*  input uint16 TqRes_tqEOMResMod5;                                          */
/*  input uint16 TqRes_tqEOMResMod6;                                          */
/*  input uint16 TqRes_tqEOMResMod7;                                          */
/*  input uint16 TqRes_tqEOMResMod8;                                          */
/*  output uint16 TqRes_prm_tqEOMRes[8];                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCATHEATRES_vidVectCalibrations(void)
{
   uint8  u8LocalTemp;
   uint16 u16LocalTqResPrmTqEOMRes[TQCATHEATRES_u8Table];


   u16LocalTqResPrmTqEOMRes[0] = TqRes_tqEOMResMod1;
   u16LocalTqResPrmTqEOMRes[1] = TqRes_tqEOMResMod2;
   u16LocalTqResPrmTqEOMRes[2] = TqRes_tqEOMResMod3;
   u16LocalTqResPrmTqEOMRes[3] = TqRes_tqEOMResMod4;
   u16LocalTqResPrmTqEOMRes[4] = TqRes_tqEOMResMod5;
   u16LocalTqResPrmTqEOMRes[5] = TqRes_tqEOMResMod6;
   u16LocalTqResPrmTqEOMRes[6] = TqRes_tqEOMResMod7;
   u16LocalTqResPrmTqEOMRes[7] = TqRes_tqEOMResMod8;
   for (u8LocalTemp = 0 ; u8LocalTemp < TQCATHEATRES_u8Table ; u8LocalTemp++)
   {
      TqRes_prm_tqEOMRes[u8LocalTemp] =
         (uint16)MATHSRV_udtMIN(u16LocalTqResPrmTqEOMRes[u8LocalTemp], 8000);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCATHEATRES_vidSelectModes                                */
/* !Description :  Les calibrations actives sont utilisées d’après les flux en*/
/*                 provenance du manager de mode de fonctionnement EOM pour   */
/*                 chacun des quatre modes.                                   */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08577_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 TqRes_idxBas1ModCur;                                          */
/*  input uint8 TqRes_idxBas2ModCur;                                          */
/*  input uint8 TqRes_idxBas1ModTar;                                          */
/*  input uint8 TqRes_idxBas2ModTar;                                          */
/*  input uint16 TqRes_prm_tqEOMRes[8];                                       */
/*  output uint16 TqRes_tqBas1ModCur;                                         */
/*  output uint16 TqRes_tqBas2ModCur;                                         */
/*  output uint16 TqRes_tqBas1ModTar;                                         */
/*  output uint16 TqRes_tqBas2ModTar;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCATHEATRES_vidSelectModes(void)
{
   uint8 u8LocalTqResIdxBas1ModCur;
   uint8 u8LocalTqResIdxBas2ModCur;
   uint8 u8LocalTqResIdxBas1ModTar;
   uint8 u8LocalTqResIdxBas2ModTar;


   u8LocalTqResIdxBas1ModCur = (uint8)MATHSRV_udtCLAMP(TqRes_idxBas1ModCur,
                                                       1,
                                                       8);
   u8LocalTqResIdxBas2ModCur = (uint8)MATHSRV_udtCLAMP(TqRes_idxBas2ModCur,
                                                       1,
                                                       8);
   u8LocalTqResIdxBas1ModTar = (uint8)MATHSRV_udtCLAMP(TqRes_idxBas1ModTar,
                                                       1,
                                                       8);
   u8LocalTqResIdxBas2ModTar = (uint8)MATHSRV_udtCLAMP(TqRes_idxBas2ModTar,
                                                       1,
                                                       8);
   u8LocalTqResIdxBas1ModCur = (uint8)(u8LocalTqResIdxBas1ModCur - 1);
   TqRes_tqBas1ModCur =
      (uint16)MATHSRV_udtMIN(TqRes_prm_tqEOMRes[u8LocalTqResIdxBas1ModCur],
                             8000);
   u8LocalTqResIdxBas2ModCur = (uint8)(u8LocalTqResIdxBas2ModCur - 1);
   TqRes_tqBas2ModCur =
      (uint16)MATHSRV_udtMIN(TqRes_prm_tqEOMRes[u8LocalTqResIdxBas2ModCur],
                             8000);
   u8LocalTqResIdxBas1ModTar = (uint8)(u8LocalTqResIdxBas1ModTar - 1);
   TqRes_tqBas1ModTar =
      (uint16)MATHSRV_udtMIN(TqRes_prm_tqEOMRes[u8LocalTqResIdxBas1ModTar],
                             8000);
   u8LocalTqResIdxBas2ModTar = (uint8)(u8LocalTqResIdxBas2ModTar - 1);
   TqRes_tqBas2ModTar =
      (uint16)MATHSRV_udtMIN(TqRes_prm_tqEOMRes[u8LocalTqResIdxBas2ModTar],
                             8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCATHEATRES_vidInterpolation                              */
/* !Description :  Deux interpolations successives permettent de calculer la  */
/*                 réserve de couple finale à appliquer pour la chauffe       */
/*                 catalyseur.                                                */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08577_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 TqRes_facBasModTar;                                           */
/*  input uint16 TqRes_tqBas1ModTar;                                          */
/*  input uint16 TqRes_tqBas2ModTar;                                          */
/*  input uint8 TqRes_facBasModCur;                                           */
/*  input uint16 TqRes_tqBas1ModCur;                                          */
/*  input uint16 TqRes_tqBas2ModCur;                                          */
/*  input uint8 TqRes_facTranMod;                                             */
/*  output uint16 TqRes_tqEOMRes;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCATHEATRES_vidInterpolation(void)
{
   uint8  u8LocalFacBasModTar;
   uint8  u8LocalFacBasModCur;
   uint8  u8LocalFacTranMod;
   uint16 u16LocalTqRes_tqEOMRes;
   uint32 u32LocalBary1;
   uint32 u32LocalBary2;
   uint32 u32LocalTqResTqEOMRes;


   u8LocalFacBasModTar = (uint8)MATHSRV_udtMIN(TqRes_facBasModTar, 128);
   u32LocalBary1 = ( ( (TqRes_tqBas1ModTar * u8LocalFacBasModTar)
                     + ((128 - u8LocalFacBasModTar) * TqRes_tqBas2ModTar))
                   + 64) / 128;
   u8LocalFacBasModCur = (uint8)MATHSRV_udtMIN(TqRes_facBasModCur, 128);
   u32LocalBary2 = ( ( (TqRes_tqBas1ModCur * u8LocalFacBasModCur)
                     + ((128 - u8LocalFacBasModCur) * TqRes_tqBas2ModCur))
                   + 64) / 128;
   /*Barycentre3*/
   u8LocalFacTranMod = (uint8)MATHSRV_udtMIN(TqRes_facTranMod, 128);
   u32LocalTqResTqEOMRes = ( ( (u32LocalBary1 * u8LocalFacTranMod)
                             + ( (uint32)(128 - u8LocalFacTranMod)
                               * u32LocalBary2))
                           + 64) / 128;
   u16LocalTqRes_tqEOMRes = (uint16)MATHSRV_udtMIN(u32LocalTqResTqEOMRes, 8000);
   VEMS_vidSET(TqRes_tqEOMRes, u16LocalTqRes_tqEOMRes);
}
/*------------------------------- end of file --------------------------------*/