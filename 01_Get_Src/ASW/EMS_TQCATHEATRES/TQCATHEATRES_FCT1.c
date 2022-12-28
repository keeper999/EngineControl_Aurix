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
/* !File            : TQCATHEATRES_FCT1.C                                     */
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
/*   1 / TQCATHEATRES_vidInitOutput                                           */
/*   2 / TQCATHEATRES_vidUnvectorizeMode                                      */
/*   3 / TQCATHEATRES_vidDeterminSetpoint                                     */
/*   4 / TQCATHEATRES_vidModeMask                                             */
/*   5 / TQCATHEATRES_vidCalibrations                                         */
/*   6 / TQCATHEATRES_vidUnvectActiveBool                                     */
/*   7 / TQCATHEATRES_vidCalibration1                                         */
/*   8 / TQCATHEATRES_vidCalibration2                                         */
/*   9 / TQCATHEATRES_vidCalibration3                                         */
/*   10 / TQCATHEATRES_vidCalibration4                                        */
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
/* !Function    :  TQCATHEATRES_vidInitOutput                                 */
/* !Description :  Fonction d'initialisation                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 TqRes_tqEOMRes;                                             */
/*  output uint16 TqRes_tqEOMResMod1;                                         */
/*  output uint16 TqRes_tqEOMResMod2;                                         */
/*  output uint16 TqRes_tqEOMResMod3;                                         */
/*  output uint16 TqRes_tqEOMResMod4;                                         */
/*  output uint16 TqRes_tqEOMResMod5;                                         */
/*  output uint16 TqRes_tqEOMResMod6;                                         */
/*  output uint16 TqRes_tqEOMResMod7;                                         */
/*  output uint16 TqRes_tqEOMResMod8;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCATHEATRES_vidInitOutput(void)
{
   VEMS_vidSET(TqRes_tqEOMRes, 0);
   TqRes_tqEOMResMod1 = 0;
   TqRes_tqEOMResMod2 = 0;
   TqRes_tqEOMResMod3 = 0;
   TqRes_tqEOMResMod4 = 0;
   TqRes_tqEOMResMod5 = 0;
   TqRes_tqEOMResMod6 = 0;
   TqRes_tqEOMResMod7 = 0;
   TqRes_tqEOMResMod8 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCATHEATRES_vidUnvectorizeMode                            */
/* !Description :  La composante 7 relative à la réserve de couple chauffe    */
/*                 catalyseur est sélectionnée pour chaque vecteur d’entrée   */
/*                 EOM.                                                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08577_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input uint8 EOM_prm_idxBas1ModCur[16];                                    */
/*  input uint8 EOM_prm_idxBas2ModCur[16];                                    */
/*  input uint8 EOM_prm_idxBas1ModTar[16];                                    */
/*  input uint8 EOM_prm_idxBas2ModTar[16];                                    */
/*  input uint8 EOM_prm_facBasModCur[16];                                     */
/*  input uint8 EOM_prm_facBasModTar[16];                                     */
/*  input uint8 EOM_prm_facTranMod[16];                                       */
/*  output uint8 TqRes_idxBas1ModCur;                                         */
/*  output uint8 TqRes_idxBas2ModCur;                                         */
/*  output uint8 TqRes_idxBas1ModTar;                                         */
/*  output uint8 TqRes_idxBas2ModTar;                                         */
/*  output uint8 TqRes_facBasModCur;                                          */
/*  output uint8 TqRes_facBasModTar;                                          */
/*  output uint8 TqRes_facTranMod;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCATHEATRES_vidUnvectorizeMode(void)
{
   uint8 u8LocalEOM_prm_idxBas1ModCur;
   uint8 u8LocalEOM_prm_idxBas2ModCur;
   uint8 u8LocalEOM_prm_idxBas1ModTar;
   uint8 u8LocalEOM_prm_idxBas2ModTar;
   uint8 u8LocalEOM_prm_facBasModCur;
   uint8 u8LocalEOM_prm_facBasModTar;
   uint8 u8LocalEOM_prm_facTranMod;


   VEMS_vidGET1DArrayElement(EOM_prm_idxBas1ModCur,
                             6,
                             u8LocalEOM_prm_idxBas1ModCur);
   TqRes_idxBas1ModCur = (uint8)MATHSRV_udtCLAMP(u8LocalEOM_prm_idxBas1ModCur,
                                                 1,
                                                 8);
   VEMS_vidGET1DArrayElement(EOM_prm_idxBas2ModCur,
                             6,
                             u8LocalEOM_prm_idxBas2ModCur);
   TqRes_idxBas2ModCur = (uint8)MATHSRV_udtCLAMP(u8LocalEOM_prm_idxBas2ModCur,
                                                 1,
                                                 8);
   VEMS_vidGET1DArrayElement(EOM_prm_idxBas1ModTar,
                             6,
                             u8LocalEOM_prm_idxBas1ModTar);
   TqRes_idxBas1ModTar = (uint8)MATHSRV_udtCLAMP(u8LocalEOM_prm_idxBas1ModTar,
                                                 1,
                                                 8);
   VEMS_vidGET1DArrayElement(EOM_prm_idxBas2ModTar,
                             6,
                             u8LocalEOM_prm_idxBas2ModTar);
   TqRes_idxBas2ModTar = (uint8)MATHSRV_udtCLAMP(u8LocalEOM_prm_idxBas2ModTar,
                                                 1,
                                                 8);
   VEMS_vidGET1DArrayElement(EOM_prm_facBasModCur,
                             6,
                             u8LocalEOM_prm_facBasModCur);

   TqRes_facBasModCur = (uint8)MATHSRV_udtMIN(u8LocalEOM_prm_facBasModCur, 128);
   VEMS_vidGET1DArrayElement(EOM_prm_facBasModTar,
                             6,
                             u8LocalEOM_prm_facBasModTar);
   TqRes_facBasModTar = (uint8)MATHSRV_udtMIN(u8LocalEOM_prm_facBasModTar, 128);
   VEMS_vidGET1DArrayElement(EOM_prm_facTranMod,
                             6,
                             u8LocalEOM_prm_facTranMod);
   TqRes_facTranMod = (uint8)MATHSRV_udtMIN(u8LocalEOM_prm_facTranMod, 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCATHEATRES_vidDeterminSetpoint                           */
/* !Description :  La réserve de couple chauffe catalyseur est calculée en 4  */
/*                 étapes en prenant en compte les entrées                    */
/*                 EOM:Mode_Mask,Calibrations,Select_Modes,Interpolation.     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08577_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCATHEATRES_vidModeMask();                              */
/*  extf argret void TQCATHEATRES_vidCalibrations();                          */
/*  extf argret void TQCATHEATRES_vidSelectModes();                           */
/*  extf argret void TQCATHEATRES_vidInterpolation();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCATHEATRES_vidDeterminSetpoint(void)
{
   TQCATHEATRES_vidModeMask();
   TQCATHEATRES_vidCalibrations();
   TQCATHEATRES_vidSelectModes();
   TQCATHEATRES_vidInterpolation();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCATHEATRES_vidModeMask                                   */
/* !Description :  Les numéros de calibrations à calculer définissent les     */
/*                 indices du vecteur TqRes_prm_bAcvEOMResMod qui doivent     */
/*                 valoir « true ».                                           */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08577_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 TqRes_idxBas1ModCur;                                          */
/*  input uint8 TqRes_idxBas2ModCur;                                          */
/*  input uint8 TqRes_idxBas1ModTar;                                          */
/*  input uint8 TqRes_idxBas2ModTar;                                          */
/*  output boolean TqRes_prm_bAcvEOMResMod[8];                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCATHEATRES_vidModeMask(void)
{
   uint8 u8LocalTemp;
   uint8 u8LocalTqResIdxBas1ModCur;
   uint8 u8LocalTqResIdxBas2ModCur;
   uint8 u8LocalTqResIdxBas1ModTar;
   uint8 u8LocalTqResIdxBas2ModTar;
   uint8 u8LocalTabBas1ModCur[TQCATHEATRES_u8Table];
   uint8 u8LocalTabBas2ModCur[TQCATHEATRES_u8Table];
   uint8 u8LocalTabBas1ModTar[TQCATHEATRES_u8Table];


   u8LocalTqResIdxBas1ModCur = (uint8)MATHSRV_udtCLAMP(TqRes_idxBas1ModCur, 1,
                                                       8);
   u8LocalTqResIdxBas2ModCur = (uint8)MATHSRV_udtCLAMP(TqRes_idxBas2ModCur, 1,
                                                       8);
   u8LocalTqResIdxBas1ModTar = (uint8)MATHSRV_udtCLAMP(TqRes_idxBas1ModTar, 1,
                                                       8);
   u8LocalTqResIdxBas2ModTar = (uint8)MATHSRV_udtCLAMP(TqRes_idxBas2ModTar, 1,
                                                       8);
   for (u8LocalTemp = 0 ; u8LocalTemp < TQCATHEATRES_u8Table ; u8LocalTemp++)
   {
      if (u8LocalTemp != (uint8)(u8LocalTqResIdxBas1ModCur - 1))
      {
         u8LocalTabBas1ModCur[u8LocalTemp] = 0;
      }
      else
      {
         u8LocalTabBas1ModCur[u8LocalTemp] = 1;
      }
      if (u8LocalTemp != (uint8)(u8LocalTqResIdxBas2ModCur - 1))
      {
         u8LocalTabBas2ModCur[u8LocalTemp] = u8LocalTabBas1ModCur[u8LocalTemp];
      }
      else
      {
         u8LocalTabBas2ModCur[u8LocalTemp] = 1;
      }

      if (u8LocalTemp != (uint8)(u8LocalTqResIdxBas1ModTar - 1))
      {
         u8LocalTabBas1ModTar[u8LocalTemp] = u8LocalTabBas2ModCur[u8LocalTemp];
      }
      else
      {
         u8LocalTabBas1ModTar[u8LocalTemp] = 1;
      }
      if (u8LocalTemp != (uint8)(u8LocalTqResIdxBas2ModTar - 1))
      {
         TqRes_prm_bAcvEOMResMod[u8LocalTemp] =
            u8LocalTabBas1ModTar[u8LocalTemp];
      }
      else
      {
         TqRes_prm_bAcvEOMResMod[u8LocalTemp] = 1;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCATHEATRES_vidCalibrations                               */
/* !Description :  D’après le vecteur TqRes_prm_bAcvEOMResMod les calibrations*/
/*                 strictement nécessaires sont calculées.                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08577_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCATHEATRES_vidUnvectActiveBool();                      */
/*  extf argret void TQCATHEATRES_vidCalibration1();                          */
/*  extf argret void TQCATHEATRES_vidCalibration2();                          */
/*  extf argret void TQCATHEATRES_vidCalibration3();                          */
/*  extf argret void TQCATHEATRES_vidCalibration4();                          */
/*  extf argret void TQCATHEATRES_vidCalibration5();                          */
/*  extf argret void TQCATHEATRES_vidCalibration6();                          */
/*  extf argret void TQCATHEATRES_vidCalibration7();                          */
/*  extf argret void TQCATHEATRES_vidCalibration8();                          */
/*  extf argret void TQCATHEATRES_vidVectCalibrations();                      */
/*  input boolean TqRes_bAcvEOMResMod1;                                       */
/*  input boolean TqRes_bAcvEOMResMod2;                                       */
/*  input boolean TqRes_bAcvEOMResMod3;                                       */
/*  input boolean TqRes_bAcvEOMResMod4;                                       */
/*  input boolean TqRes_bAcvEOMResMod5;                                       */
/*  input boolean TqRes_bAcvEOMResMod6;                                       */
/*  input boolean TqRes_bAcvEOMResMod7;                                       */
/*  input boolean TqRes_bAcvEOMResMod8;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCATHEATRES_vidCalibrations(void)
{
   TQCATHEATRES_vidUnvectActiveBool();
   if (TqRes_bAcvEOMResMod1 != 0)
   {
      TQCATHEATRES_vidCalibration1();
   }
   if (TqRes_bAcvEOMResMod2 != 0)
   {
      TQCATHEATRES_vidCalibration2();
   }
   if (TqRes_bAcvEOMResMod3 != 0)
   {
      TQCATHEATRES_vidCalibration3();
   }
   if (TqRes_bAcvEOMResMod4 != 0)
   {
      TQCATHEATRES_vidCalibration4();
   }
   if (TqRes_bAcvEOMResMod5 != 0)
   {
      TQCATHEATRES_vidCalibration5();
   }
   if (TqRes_bAcvEOMResMod6 != 0)
   {
      TQCATHEATRES_vidCalibration6();
   }
   if (TqRes_bAcvEOMResMod7 != 0)
   {
      TQCATHEATRES_vidCalibration7();
   }
   if (TqRes_bAcvEOMResMod8 != 0)
   {
      TQCATHEATRES_vidCalibration8();
   }
   TQCATHEATRES_vidVectCalibrations();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCATHEATRES_vidUnvectActiveBool                           */
/* !Description :  Le vecteur TqRes_prm_bAcvEOMResMod définissant les         */
/*                 calibrations à calculer définit les flux d’activation de   */
/*                 calcul.                                                    */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08577_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean TqRes_prm_bAcvEOMResMod[8];                                 */
/*  output boolean TqRes_bAcvEOMResMod1;                                      */
/*  output boolean TqRes_bAcvEOMResMod2;                                      */
/*  output boolean TqRes_bAcvEOMResMod3;                                      */
/*  output boolean TqRes_bAcvEOMResMod4;                                      */
/*  output boolean TqRes_bAcvEOMResMod5;                                      */
/*  output boolean TqRes_bAcvEOMResMod6;                                      */
/*  output boolean TqRes_bAcvEOMResMod7;                                      */
/*  output boolean TqRes_bAcvEOMResMod8;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCATHEATRES_vidUnvectActiveBool(void)
{
   TqRes_bAcvEOMResMod1 = TqRes_prm_bAcvEOMResMod[0];
   TqRes_bAcvEOMResMod2 = TqRes_prm_bAcvEOMResMod[1];
   TqRes_bAcvEOMResMod3 = TqRes_prm_bAcvEOMResMod[2];
   TqRes_bAcvEOMResMod4 = TqRes_prm_bAcvEOMResMod[3];
   TqRes_bAcvEOMResMod5 = TqRes_prm_bAcvEOMResMod[4];
   TqRes_bAcvEOMResMod6 = TqRes_prm_bAcvEOMResMod[5];
   TqRes_bAcvEOMResMod7 = TqRes_prm_bAcvEOMResMod[6];
   TqRes_bAcvEOMResMod8 = TqRes_prm_bAcvEOMResMod[7];
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCATHEATRES_vidCalibration1                               */
/* !Description :  Cette réserve de couple est calculée si et seulement si le */
/*                 booléen TqRes_bAcvEOMResMod1 le demande.                   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08577_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input sint16 TqSys_tqIdcAirLimCordWoutRes;                                */
/*  input uint16 TqRes_nEngEOMResMod1_A[8];                                   */
/*  input uint16 TqRes_tqIdcAirEOMResMod1_A[8];                               */
/*  input uint16 TqRes_tqEOMResMod1_M[8][8];                                  */
/*  output uint16 TqRes_tqEOMResMod1;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCATHEATRES_vidCalibration1(void)
{
   uint16 u16LocalEng_nCkFil;
   uint16 u16LocalTqSys_tqIdcAirCordWotRes;
   uint16 u16LocalTqResTqEOMResMod1;
   uint16 u16LocalCalcParaEngNCkFil;
   uint16 u16LocalCalcParaWoutRes;
   sint16 s16LocalTqSys_tqIdcAirCordWotRes;


   VEMS_vidGET(Eng_nCkFil , u16LocalEng_nCkFil);
   VEMS_vidGET(TqSys_tqIdcAirLimCordWoutRes , s16LocalTqSys_tqIdcAirCordWotRes);
   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   u16LocalCalcParaEngNCkFil =
      MATHSRV_u16CalcParaIncAryU16(TqRes_nEngEOMResMod1_A,
                                   u16LocalEng_nCkFil,
                                   8);
   s16LocalTqSys_tqIdcAirCordWotRes =
     (sint16)MATHSRV_udtCLAMP(s16LocalTqSys_tqIdcAirCordWotRes , -32000, 32000);
   u16LocalTqSys_tqIdcAirCordWotRes = (uint16)( s16LocalTqSys_tqIdcAirCordWotRes
                                              + 32000);
   u16LocalCalcParaWoutRes =
      MATHSRV_u16CalcParaIncAryU16(TqRes_tqIdcAirEOMResMod1_A,
                                   u16LocalTqSys_tqIdcAirCordWotRes,
                                   8);
   u16LocalTqResTqEOMResMod1 = MATHSRV_u16Interp2d(&TqRes_tqEOMResMod1_M[0][0],
                                                   u16LocalCalcParaEngNCkFil,
                                                   u16LocalCalcParaWoutRes,
                                                   8);
   TqRes_tqEOMResMod1 = (uint16)MATHSRV_udtMIN(u16LocalTqResTqEOMResMod1, 8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCATHEATRES_vidCalibration2                               */
/* !Description :  Cette réserve de couple est calculée si et seulement si le */
/*                 booléen TqRes_bAcvEOMResMod2 le demande.                   */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08577_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input sint16 TqSys_tqIdcAirLimCordWoutRes;                                */
/*  input uint16 TqRes_nEngEOMResMod2_A[8];                                   */
/*  input uint16 TqRes_tqIdcAirEOMResMod2_A[8];                               */
/*  input uint16 TqRes_tqEOMResMod2_M[8][8];                                  */
/*  output uint16 TqRes_tqEOMResMod2;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCATHEATRES_vidCalibration2(void)
{
   uint16 u16LocalEng_nCkFil;
   uint16 u16LocalTqSys_tqIdcAirCordWotRes;
   uint16 u16LocalTqResTqEOMResMod2;
   uint16 u16LocalCalcParaEngNCkFil;
   uint16 u16LocalCalcParaWoutRes;
   sint16 s16LocalTqSys_tqIdcAirCordWotRes;


   VEMS_vidGET(Eng_nCkFil , u16LocalEng_nCkFil);
   VEMS_vidGET(TqSys_tqIdcAirLimCordWoutRes , s16LocalTqSys_tqIdcAirCordWotRes);
   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   u16LocalCalcParaEngNCkFil =
      MATHSRV_u16CalcParaIncAryU16(TqRes_nEngEOMResMod2_A,
                                   u16LocalEng_nCkFil,
                                   8);
   s16LocalTqSys_tqIdcAirCordWotRes =
     (sint16)MATHSRV_udtCLAMP(s16LocalTqSys_tqIdcAirCordWotRes , -32000, 32000);
   u16LocalTqSys_tqIdcAirCordWotRes = (uint16)( s16LocalTqSys_tqIdcAirCordWotRes
                                              + 32000);
   u16LocalCalcParaWoutRes =
      MATHSRV_u16CalcParaIncAryU16(TqRes_tqIdcAirEOMResMod2_A,
                                   u16LocalTqSys_tqIdcAirCordWotRes,
                                   8);
   u16LocalTqResTqEOMResMod2 = MATHSRV_u16Interp2d(&TqRes_tqEOMResMod2_M[0][0],
                                                   u16LocalCalcParaEngNCkFil,
                                                   u16LocalCalcParaWoutRes,
                                                   8);
   TqRes_tqEOMResMod2 = (uint16)MATHSRV_udtMIN(u16LocalTqResTqEOMResMod2, 8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCATHEATRES_vidCalibration3                               */
/* !Description :  Cette réserve de couple est calculée si et seulement si le */
/*                 booléen TqRes_bAcvEOMResMod3 le demande.                   */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08577_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input sint16 TqSys_tqIdcAirLimCordWoutRes;                                */
/*  input uint16 TqRes_nEngEOMResMod3_A[8];                                   */
/*  input uint16 TqRes_tqIdcAirEOMResMod3_A[8];                               */
/*  input uint16 TqRes_tqEOMResMod3_M[8][8];                                  */
/*  output uint16 TqRes_tqEOMResMod3;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCATHEATRES_vidCalibration3(void)
{
   uint16 u16LocalEng_nCkFil;
   uint16 u16LocalTqSys_tqIdcAirCordWotRes;
   uint16 u16LocalTqResTqEOMResMod3;
   uint16 u16LocalCalcParaEngNCkFil;
   uint16 u16LocalCalcParaWoutRes;
   sint16 s16LocalTqSys_tqIdcAirCordWotRes;


   VEMS_vidGET(Eng_nCkFil , u16LocalEng_nCkFil);
   VEMS_vidGET(TqSys_tqIdcAirLimCordWoutRes , s16LocalTqSys_tqIdcAirCordWotRes);
   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   u16LocalCalcParaEngNCkFil =
      MATHSRV_u16CalcParaIncAryU16(TqRes_nEngEOMResMod3_A,
                                   u16LocalEng_nCkFil,
                                   8);
   s16LocalTqSys_tqIdcAirCordWotRes =
     (sint16)MATHSRV_udtCLAMP(s16LocalTqSys_tqIdcAirCordWotRes , -32000, 32000);
   u16LocalTqSys_tqIdcAirCordWotRes = (uint16)( s16LocalTqSys_tqIdcAirCordWotRes
                                              + 32000);
   u16LocalCalcParaWoutRes =
      MATHSRV_u16CalcParaIncAryU16(TqRes_tqIdcAirEOMResMod3_A,
                                   u16LocalTqSys_tqIdcAirCordWotRes,
                                   8);
   u16LocalTqResTqEOMResMod3 = MATHSRV_u16Interp2d(&TqRes_tqEOMResMod3_M[0][0],
                                                   u16LocalCalcParaEngNCkFil,
                                                   u16LocalCalcParaWoutRes,
                                                   8);
   TqRes_tqEOMResMod3 = (uint16)MATHSRV_udtMIN(u16LocalTqResTqEOMResMod3, 8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCATHEATRES_vidCalibration4                               */
/* !Description :  Cette réserve de couple est calculée si et seulement si le */
/*                 booléen TqRes_bAcvEOMResMod4 le demande.                   */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08577_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input sint16 TqSys_tqIdcAirLimCordWoutRes;                                */
/*  input uint16 TqRes_nEngEOMResMod4_A[16];                                  */
/*  input uint16 TqRes_tqIdcAirEOMResMod4_A[16];                              */
/*  input uint16 TqRes_tqEOMResMod4_M[16][16];                                */
/*  output uint16 TqRes_tqEOMResMod4;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCATHEATRES_vidCalibration4(void)
{
   uint16 u16LocalEng_nCkFil;
   uint16 u16LocalTqSys_tqIdcAirCordWotRes;
   uint16 u16LocalTqResTqEOMResMod4;
   uint16 u16LocalCalcParaEngNCkFil;
   uint16 u16LocalCalcParaWoutRes;
   sint16 s16LocalTqSys_tqIdcAirCordWotRes;


   VEMS_vidGET(Eng_nCkFil , u16LocalEng_nCkFil);
   VEMS_vidGET(TqSys_tqIdcAirLimCordWoutRes , s16LocalTqSys_tqIdcAirCordWotRes);
   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   u16LocalCalcParaEngNCkFil =
      MATHSRV_u16CalcParaIncAryU16(TqRes_nEngEOMResMod4_A,
                                   u16LocalEng_nCkFil,
                                   16);
   s16LocalTqSys_tqIdcAirCordWotRes =
     (sint16)MATHSRV_udtCLAMP(s16LocalTqSys_tqIdcAirCordWotRes , -32000, 32000);
   u16LocalTqSys_tqIdcAirCordWotRes = (uint16)( s16LocalTqSys_tqIdcAirCordWotRes
                                              + 32000);
   u16LocalCalcParaWoutRes =
      MATHSRV_u16CalcParaIncAryU16(TqRes_tqIdcAirEOMResMod4_A,
                                   u16LocalTqSys_tqIdcAirCordWotRes,
                                   16);
   u16LocalTqResTqEOMResMod4 = MATHSRV_u16Interp2d(&TqRes_tqEOMResMod4_M[0][0],
                                                   u16LocalCalcParaEngNCkFil,
                                                   u16LocalCalcParaWoutRes,
                                                   16);
   TqRes_tqEOMResMod4 = (uint16)MATHSRV_udtMIN(u16LocalTqResTqEOMResMod4, 8000);
}
/*------------------------------- end of file --------------------------------*/