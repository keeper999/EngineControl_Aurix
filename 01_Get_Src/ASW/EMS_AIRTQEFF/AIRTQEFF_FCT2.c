/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AIRTQEFF                                                */
/* !Description     : AIRTQEFF component                                      */
/*                                                                            */
/* !Module          : AIRTQEFF                                                */
/* !Description     : Calcul du rendement pour la transformation couple /     */
/*                    masse d_air                                             */
/*                                                                            */
/* !File            : AIRTQEFF_FCT2.C                                         */
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
/*   1 / AIRTQEFF_vidUnvectorize_Mode                                         */
/*   2 / AIRTQEFF_vidMode_Mask                                                */
/*   3 / AIRTQEFF_vidCalibrations                                             */
/*   4 / AIRTQEFF_vidSelect_Modes                                             */
/*   5 / AIRTQEFF_vidInterpolation                                            */
/*   6 / AIRTQEFF_vidCoordination_1                                           */
/*   7 / AIRTQEFF_vidCalc_afr_efficiency                                      */
/*   8 / AIRTQEFF_vidCoordination_2                                           */
/*   9 / AIRTQEFF_vidCalc_egr_efficiency                                      */
/*   10 / AIRTQEFF_vidCoordination_3                                          */
/*                                                                            */
/* !Reference   : V02 NT 10 07791 / 02                                        */
/* !OtherRefs   : CSMT_CGMT09_0475_2 / 1.1                                    */
/* !OtherRefs   : VEMS V02 ECU#051747                                         */
/* !OtherRefs   : VEMS V02 ECU#058235                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/AIR/AIRTQEFF/AIRTQEFF_FCT2$*/
/* $Revision::   1.5.1.1  $$Author::   mbenfrad       $$Date::   05 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   05 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "AIRTQEFF.h"
#include "AIRTQEFF_L.h"
#include "AIRTQEFF_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidUnvectorize_Mode                               */
/* !Description :  Ce bloc permet de sélectionner les informations provenant  */
/*                 du gestionnaire de modes de fonctionnements                */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_009.01                                     */
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
/*  output uint8 AirSys_idxBas1ModCur;                                        */
/*  output uint8 AirSys_idxBas2ModCur;                                        */
/*  output uint8 AirSys_idxBas1ModTar;                                        */
/*  output uint8 AirSys_idxBas2ModTar;                                        */
/*  output uint8 AirSys_facBasModCur;                                         */
/*  output uint8 AirSys_facBasModTar;                                         */
/*  output uint8 AirSys_facTranMod;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidUnvectorize_Mode(void)
{
   uint8 u8LocalIndex_Bas1ModCur;
   uint8 u8LocalIndex_Bas2ModCur;
   uint8 u8LocalIndex_Bas1ModTar;
   uint8 u8LocalIndex_Bas2ModTar;
   uint8 u8LocalIndex_facBasModCur;
   uint8 u8LocalIndex_facBasModTar;
   uint8 u8LocalIndex_facTranMod;


   VEMS_vidGET1DArrayElement(EOM_prm_idxBas1ModCur,
                             11,
                             u8LocalIndex_Bas1ModCur);
   AirSys_idxBas1ModCur = (uint8)MATHSRV_udtCLAMP(u8LocalIndex_Bas1ModCur,
                                                  1,
                                                  14);

   VEMS_vidGET1DArrayElement(EOM_prm_idxBas2ModCur,
                             11,
                             u8LocalIndex_Bas2ModCur);
   AirSys_idxBas2ModCur = (uint8)MATHSRV_udtCLAMP(u8LocalIndex_Bas2ModCur,
                                                  1,
                                                  14);

   VEMS_vidGET1DArrayElement(EOM_prm_idxBas1ModTar,
                             11,
                             u8LocalIndex_Bas1ModTar);
   AirSys_idxBas1ModTar = (uint8)MATHSRV_udtCLAMP(u8LocalIndex_Bas1ModTar,
                                                  1,
                                                  14);

   VEMS_vidGET1DArrayElement(EOM_prm_idxBas2ModTar,
                             11,
                             u8LocalIndex_Bas2ModTar);
   AirSys_idxBas2ModTar = (uint8)MATHSRV_udtCLAMP(u8LocalIndex_Bas2ModTar,
                                                  1,
                                                  14);
   VEMS_vidGET1DArrayElement(EOM_prm_facBasModCur,
                             11,
                             u8LocalIndex_facBasModCur);
   u8LocalIndex_facBasModCur = (uint8)((u8LocalIndex_facBasModCur * 25) / 32);
   AirSys_facBasModCur = (uint8)MATHSRV_udtMIN(u8LocalIndex_facBasModCur, 100);

   VEMS_vidGET1DArrayElement(EOM_prm_facBasModTar,
                             11,
                             u8LocalIndex_facBasModTar);
   u8LocalIndex_facBasModTar = (uint8)((u8LocalIndex_facBasModTar * 25) / 32);
   AirSys_facBasModTar = (uint8)MATHSRV_udtMIN(u8LocalIndex_facBasModTar, 100);

   VEMS_vidGET1DArrayElement(EOM_prm_facTranMod, 11, u8LocalIndex_facTranMod);
   u8LocalIndex_facTranMod = (uint8)((u8LocalIndex_facTranMod * 25) / 32);
   AirSys_facTranMod = (uint8)MATHSRV_udtMIN(u8LocalIndex_facTranMod, 100);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidMode_Mask                                      */
/* !Description :  Ce bloc permet de sélectionner le numéro des cartographies */
/*                 utiles                                                     */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 AirSys_idxBas1ModCur;                                         */
/*  input uint8 AirSys_idxBas2ModCur;                                         */
/*  input uint8 AirSys_idxBas1ModTar;                                         */
/*  input uint8 AirSys_idxBas2ModTar;                                         */
/*  output boolean AirSys_prm_bAcvEffCycCal[14];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidMode_Mask(void)
{
   uint8 u8LocalIndex;
   uint8 u8LocalIdx1ModCur;
   uint8 u8LocalIdx2ModCur;
   uint8 u8LocalIdx1ModTar;
   uint8 u8LocalIdx2ModTar;


   u8LocalIdx1ModCur = (uint8)MATHSRV_udtCLAMP(AirSys_idxBas1ModCur, 1, 14);

   u8LocalIdx2ModCur = (uint8)MATHSRV_udtCLAMP(AirSys_idxBas2ModCur, 1, 14);

   u8LocalIdx1ModTar = (uint8)MATHSRV_udtCLAMP(AirSys_idxBas1ModTar, 1, 14);

   u8LocalIdx2ModTar = (uint8)MATHSRV_udtCLAMP(AirSys_idxBas2ModTar, 1, 14);

   for(u8LocalIndex = 0; u8LocalIndex <= 13; u8LocalIndex++)
   {
      AirSys_prm_bAcvEffCycCal[u8LocalIndex] = 0;
   }

   AirSys_prm_bAcvEffCycCal[u8LocalIdx1ModCur - 1] = 1;
   AirSys_prm_bAcvEffCycCal[u8LocalIdx2ModCur - 1] = 1;
   AirSys_prm_bAcvEffCycCal[u8LocalIdx1ModTar - 1] = 1;
   AirSys_prm_bAcvEffCycCal[u8LocalIdx2ModTar - 1] = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCalibrations                                   */
/* !Description :  Ce bloc regroupe les différentes calibrations de la        */
/*                 fonction                                                   */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AIRTQEFF_vidUnvectorz_Activ_Bool();                      */
/*  extf argret void AIRTQEFF_vidCalibration_1();                             */
/*  extf argret void AIRTQEFF_vidCalibration_2();                             */
/*  extf argret void AIRTQEFF_vidCalibration_3();                             */
/*  extf argret void AIRTQEFF_vidCalibration_4();                             */
/*  extf argret void AIRTQEFF_vidCalibration_5();                             */
/*  extf argret void AIRTQEFF_vidCalibration_6();                             */
/*  extf argret void AIRTQEFF_vidCalibration_7();                             */
/*  extf argret void AIRTQEFF_vidCalibration_8();                             */
/*  extf argret void AIRTQEFF_vidCalibration_9();                             */
/*  extf argret void AIRTQEFF_vidCalibration_10();                            */
/*  extf argret void AIRTQEFF_vidCalibration_11();                            */
/*  extf argret void AIRTQEFF_vidCalibration_12();                            */
/*  extf argret void AIRTQEFF_vidCalibration_13();                            */
/*  extf argret void AIRTQEFF_vidCalibration_14();                            */
/*  extf argret void AIRTQEFF_vidVectorz_Calibrations();                      */
/*  input boolean AirSys_bAcvCycCal1;                                         */
/*  input boolean AirSys_bAcvCycCal2;                                         */
/*  input boolean AirSys_bAcvCycCal3;                                         */
/*  input boolean AirSys_bAcvCycCal4;                                         */
/*  input boolean AirSys_bAcvCycCal5;                                         */
/*  input boolean AirSys_bAcvCycCal6;                                         */
/*  input boolean AirSys_bAcvCycCal7;                                         */
/*  input boolean AirSys_bAcvCycCal8;                                         */
/*  input boolean AirSys_bAcvCycCal9;                                         */
/*  input boolean AirSys_bAcvCycCal10;                                        */
/*  input boolean AirSys_bAcvCycCal11;                                        */
/*  input boolean AirSys_bAcvCycCal12;                                        */
/*  input boolean AirSys_bAcvCycCal13;                                        */
/*  input boolean AirSys_bAcvCycCal14;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalibrations(void)
{
   AIRTQEFF_vidUnvectorz_Activ_Bool();

   if (AirSys_bAcvCycCal1 != 0)
   {
      AIRTQEFF_vidCalibration_1();
   }
   if (AirSys_bAcvCycCal2 != 0)
   {
      AIRTQEFF_vidCalibration_2();
   }
   if (AirSys_bAcvCycCal3 != 0)
   {
      AIRTQEFF_vidCalibration_3();
   }
   if (AirSys_bAcvCycCal4 != 0)
   {
      AIRTQEFF_vidCalibration_4();
   }
   if (AirSys_bAcvCycCal5 != 0)
   {
      AIRTQEFF_vidCalibration_5();
   }
   if (AirSys_bAcvCycCal6 != 0)
   {
      AIRTQEFF_vidCalibration_6();
   }
   if (AirSys_bAcvCycCal7 != 0)
   {
      AIRTQEFF_vidCalibration_7();
   }
   if (AirSys_bAcvCycCal8 != 0)
   {
      AIRTQEFF_vidCalibration_8();
   }
   if (AirSys_bAcvCycCal9 != 0)
   {
      AIRTQEFF_vidCalibration_9();
   }
   if (AirSys_bAcvCycCal10 != 0)
   {
      AIRTQEFF_vidCalibration_10();
   }
   if (AirSys_bAcvCycCal11 != 0)
   {
      AIRTQEFF_vidCalibration_11();
   }
   if (AirSys_bAcvCycCal12 != 0)
   {
      AIRTQEFF_vidCalibration_12();
   }
   if (AirSys_bAcvCycCal13 != 0)
   {
      AIRTQEFF_vidCalibration_13();
   }
   if (AirSys_bAcvCycCal14 != 0)
   {
      AIRTQEFF_vidCalibration_14();
   }

   AIRTQEFF_vidVectorz_Calibrations();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidSelect_Modes                                   */
/* !Description :  Ce bloc permet d’imposer les rendements de cycle en        */
/*                 indexant les vecteurs des rendements de cycle au mode de   */
/*                 fonctionnement appliqué.                                   */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_028.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 AirSys_idxBas1ModCur;                                         */
/*  input uint16 AirSys_prm_effCyc[14];                                       */
/*  input uint8 AirSys_idxBas2ModCur;                                         */
/*  input uint8 AirSys_idxBas1ModTar;                                         */
/*  input uint8 AirSys_idxBas2ModTar;                                         */
/*  output uint16 AirSys_effEffCycBas1ModCur;                                 */
/*  output uint16 AirSys_effEffCycBas2ModCur;                                 */
/*  output uint16 AirSys_effEffCycBas1ModTar;                                 */
/*  output uint16 AirSys_effEffCycBas2ModTar;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidSelect_Modes(void)
{
   uint8  u8LocalIndex;
   uint8  u8LocalAirSys_idxBas1ModCur;
   uint8  u8LocalAirSys_idxBas2ModCur;
   uint8  u8LocalAirSys_idxBas1ModTar;
   uint8  u8LocalAirSys_idxBas2ModTar;


   u8LocalAirSys_idxBas1ModCur = (uint8)MATHSRV_udtCLAMP(AirSys_idxBas1ModCur,
                                                         1,
                                                         14);
   u8LocalIndex = (uint8)(u8LocalAirSys_idxBas1ModCur - 1);
   AirSys_effEffCycBas1ModCur = AirSys_prm_effCyc[u8LocalIndex];

   u8LocalAirSys_idxBas2ModCur = (uint8)MATHSRV_udtCLAMP(AirSys_idxBas2ModCur,
                                                         1,
                                                         14);
   u8LocalIndex = (uint8)(u8LocalAirSys_idxBas2ModCur - 1);
   AirSys_effEffCycBas2ModCur = AirSys_prm_effCyc[u8LocalIndex];

   u8LocalAirSys_idxBas1ModTar = (uint8)MATHSRV_udtCLAMP(AirSys_idxBas1ModTar,
                                                         1,
                                                         14);
   u8LocalIndex = (uint8)(u8LocalAirSys_idxBas1ModTar - 1);
   AirSys_effEffCycBas1ModTar = AirSys_prm_effCyc[u8LocalIndex];

   u8LocalAirSys_idxBas2ModTar = (uint8)MATHSRV_udtCLAMP(AirSys_idxBas2ModTar,
                                                         1,
                                                         14);
   u8LocalIndex = (uint8)(u8LocalAirSys_idxBas2ModTar - 1);
   AirSys_effEffCycBas2ModTar = AirSys_prm_effCyc[u8LocalIndex];
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidInterpolation                                  */
/* !Description :  Ce bloc calcul le rendement de cycle final à partir des 4  */
/*                 rendements de cycle correspondants à différents modes. Le  */
/*                 calcul se fait à l’aide de 3 barycentres pilotés par des   */
/*                 facteurs issus du gestionnaire de modes de combustion.     */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_029.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 AirSys_effEffCycBas1ModTar;                                  */
/*  input uint16 AirSys_effEffCycBas2ModTar;                                  */
/*  input uint8 AirSys_facBasModTar;                                          */
/*  input uint16 AirSys_effEffCycBas1ModCur;                                  */
/*  input uint16 AirSys_effEffCycBas2ModCur;                                  */
/*  input uint8 AirSys_facBasModCur;                                          */
/*  input uint16 AIRTQEFF_u16Barycentre1;                                     */
/*  input uint16 AIRTQEFF_u16Barycentre2;                                     */
/*  input uint8 AirSys_facTranMod;                                            */
/*  output uint16 AIRTQEFF_u16Barycentre1;                                    */
/*  output uint16 AIRTQEFF_u16Barycentre2;                                    */
/*  output uint16 AirSys_effCycTran;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidInterpolation(void)
{
   uint8  u8LocalRate;
   sint32 s32LocalCalc;


   /*Barycentre 1 */
   s32LocalCalc = (sint32)( AirSys_effEffCycBas1ModTar
                          - AirSys_effEffCycBas2ModTar);
   u8LocalRate = (uint8)MATHSRV_udtMIN(AirSys_facBasModTar, 100);

   if (s32LocalCalc >= 0)
   {
      s32LocalCalc = ((s32LocalCalc * u8LocalRate) + 50) / 100;
   }
   else
   {
      s32LocalCalc = ((s32LocalCalc * u8LocalRate) - 50) / 100;
   }
   AIRTQEFF_u16Barycentre1 = (uint16)( s32LocalCalc
                                     + AirSys_effEffCycBas2ModTar);

   /* Barycentre 2 */
   s32LocalCalc = (sint32)( AirSys_effEffCycBas1ModCur
                          - AirSys_effEffCycBas2ModCur);
   u8LocalRate = (uint8)MATHSRV_udtMIN(AirSys_facBasModCur, 100);

   if (s32LocalCalc >= 0)
   {
      s32LocalCalc = ((s32LocalCalc * u8LocalRate) + 50) / 100;
   }
   else
   {
      s32LocalCalc = ((s32LocalCalc * u8LocalRate) - 50) / 100;
   }
   AIRTQEFF_u16Barycentre2 = (uint16)( s32LocalCalc
                                     + AirSys_effEffCycBas2ModCur);

   /* Barycentre 3 */
   s32LocalCalc = (sint32)(AIRTQEFF_u16Barycentre1 - AIRTQEFF_u16Barycentre2);
   u8LocalRate = (uint8)MATHSRV_udtMIN(AirSys_facTranMod, 100);

   if (s32LocalCalc >= 0)
   {
      s32LocalCalc = ((s32LocalCalc * u8LocalRate) + 50) / 100;
   }
   else
   {
      s32LocalCalc = ((s32LocalCalc * u8LocalRate) - 50) / 100;
   }
   AirSys_effCycTran = (uint16)(s32LocalCalc + AIRTQEFF_u16Barycentre2);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCoordination_1                                 */
/* !Description :  La fonction permet de prendre en compte le mélange entre un*/
/*                 carburant classique et du « Flex Fuel » ou du gaz. La      */
/*                 fonction permet entre autre la gestion des différents modes*/
/*                 de combustion par application d’un décalage/recalage       */
/*                 (offset).                                                  */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_030.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 AirSys_effCycFlex;                                           */
/*  input boolean AirSys_bFlexEffCyc_C;                                       */
/*  input uint16 AirSys_effCycTran;                                           */
/*  input uint8 IgSys_prm_facFlex[10];                                        */
/*  input uint16 AirSys_effCycGas;                                            */
/*  input boolean AirSys_bGasEffCyc_C;                                        */
/*  input uint16 AirSys_effCycWiFlexCor_MP;                                   */
/*  input uint8 IgSys_prm_facGas[10];                                         */
/*  output uint16 AirSys_effCycWiFlexCor_MP;                                  */
/*  output uint16 AirSys_effCyc;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCoordination_1(void)
{
   uint8  u8LocalRate1;
   uint8  u8LocalRate2;
   uint16 u16LocalCalc;
   uint16 u16LocalAirSys_effCycFlex;
   uint16 u16LocalAirSys_effCycGas;
   uint32 u32LocalBaryInput1;
   uint32 u32LocalBaryInput2;
   sint32 s32LocalCalc;


   /*-- Calc Barycentre 1 --*/
   VEMS_vidGET(AirSys_effCycFlex, u16LocalAirSys_effCycFlex);

   if (AirSys_bFlexEffCyc_C != 0)
   {
      u32LocalBaryInput1 = u16LocalAirSys_effCycFlex;
   }
   else
   {
      u32LocalBaryInput1 = u16LocalAirSys_effCycFlex
                         + AirSys_effCycTran
                         + 12288;
   }

   VEMS_vidGET1DArrayElement(IgSys_prm_facFlex, 5, u8LocalRate1);
   u8LocalRate1 = (uint8)MATHSRV_udtMIN(u8LocalRate1, 128);

   s32LocalCalc = (sint32)(u32LocalBaryInput1 - AirSys_effCycTran);
   if (u32LocalBaryInput1 >= AirSys_effCycTran)
   {
      s32LocalCalc = ((s32LocalCalc * u8LocalRate1) + 64) / 128;
   }
   else
   {
      s32LocalCalc = ((s32LocalCalc * u8LocalRate1) - 64) / 128;
   }

   s32LocalCalc = s32LocalCalc + AirSys_effCycTran;
   AirSys_effCycWiFlexCor_MP = (uint16)MATHSRV_udtMIN(s32LocalCalc, 65535);

   /*-- Calc Barycentre 2 --*/
   VEMS_vidGET(AirSys_effCycGas, u16LocalAirSys_effCycGas);

   if (AirSys_bGasEffCyc_C != 0)
   {
      u32LocalBaryInput2 = u16LocalAirSys_effCycGas;
   }
   else
   {
      u32LocalBaryInput2 = u16LocalAirSys_effCycGas
                         + AirSys_effCycWiFlexCor_MP
                         + 12288;
   }

   VEMS_vidGET1DArrayElement(IgSys_prm_facGas, 5, u8LocalRate2);
   u8LocalRate2 = (uint8)MATHSRV_udtMIN(u8LocalRate2, 128);

   s32LocalCalc = (sint32)(u32LocalBaryInput2 - AirSys_effCycWiFlexCor_MP);
   if (u32LocalBaryInput2 >= AirSys_effCycWiFlexCor_MP)
   {
      s32LocalCalc = ((s32LocalCalc * u8LocalRate2) + 64) / 128;

   }
   else
   {
      s32LocalCalc = ((s32LocalCalc * u8LocalRate2) - 64) / 128;

   }
   s32LocalCalc = s32LocalCalc + AirSys_effCycWiFlexCor_MP;
   u16LocalCalc = (uint16)MATHSRV_udtMIN(s32LocalCalc, 65535);

   VEMS_vidSET(AirSys_effCyc, u16LocalCalc);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCalc_afr_efficiency                            */
/* !Description :  Le rendement de richesse est issu d’une cartographie       */
/*                 fonction de la richesse.                                   */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_032.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 AirSys_rGradAfrReqLim_C;                                      */
/*  input uint16 AirSys_tiSdlFastAirTqEff_C;                                  */
/*  input uint16 FARSp_rMixtCylSp;                                            */
/*  input uint16 Inj_rlamEng_A[9];                                            */
/*  input uint16 AirSys_effAfr_T[9];                                          */
/*  input uint16 AirSys_prm_effAfrClc[3];                                     */
/*  input uint16 IgSys_rlamClc;                                               */
/*  input uint16 FARSp_rMixtFullLdSpRaw;                                      */
/*  output uint16 AirSys_prm_effAfrClc[3];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalc_afr_efficiency(void)
{
   uint16 u16LocalFARSp_rMixtCylSp;
   uint16 u16LocalInput;
   uint16 u16LocalRateLimInc;
   uint16 u16LocalRateLimDec;
   uint16 u16localCalcPara;
   uint16 u16LocalRateLimInput;
   uint16 u16LocalRateLimOutElmnt;
   uint16 u16LocalIgSys_rlamClc;
   uint16 u16LocalFARSp_rMixtFullLdSpRaw;
   uint32 u32LocalProd;


   /*Production of Inc and Dec parameters*/
   u32LocalProd = (uint32)( AirSys_rGradAfrReqLim_C
                          * AirSys_tiSdlFastAirTqEff_C
                          * 16);
   u32LocalProd = (u32LocalProd / 125);
   u16LocalRateLimInc = (uint16)MATHSRV_udtMIN(u32LocalProd, 65535);

   u16LocalRateLimDec = u16LocalRateLimInc;

   /* -- First element of the table -- */
   VEMS_vidGET(FARSp_rMixtCylSp, u16LocalFARSp_rMixtCylSp);
   if (u16LocalFARSp_rMixtCylSp <= 60128)
   {
      u16LocalInput = (uint16)((u16LocalFARSp_rMixtCylSp * 400) / 367);
   }
   else
   {
      u16LocalInput = 65535;
   }

   u16localCalcPara = MATHSRV_u16CalcParaIncAryU16(Inj_rlamEng_A,
                                                   u16LocalInput,
                                                   9);
   u16LocalRateLimInput = MATHSRV_u16Interp1d(AirSys_effAfr_T,
                                              u16localCalcPara);

   u16LocalRateLimOutElmnt = (AirSys_prm_effAfrClc[0]);
   u16LocalRateLimOutElmnt = MATHSRV_u16SlewFilter(u16LocalRateLimOutElmnt,
                                                   u16LocalRateLimInput,
                                                   u16LocalRateLimInc,
                                                   u16LocalRateLimDec);
   AirSys_prm_effAfrClc[0] = u16LocalRateLimOutElmnt;

   /* -- Second element of the Table -- */
   VEMS_vidGET(IgSys_rlamClc, u16LocalIgSys_rlamClc);
   u16localCalcPara = MATHSRV_u16CalcParaIncAryU16(Inj_rlamEng_A,
                                                   u16LocalIgSys_rlamClc,
                                                   9);
   u16LocalRateLimInput = MATHSRV_u16Interp1d(AirSys_effAfr_T,
                                              u16localCalcPara);

   u16LocalRateLimOutElmnt = (AirSys_prm_effAfrClc[1]);
   u16LocalRateLimOutElmnt = MATHSRV_u16SlewFilter(u16LocalRateLimOutElmnt,
                                                   u16LocalRateLimInput,
                                                   u16LocalRateLimInc,
                                                   u16LocalRateLimDec);
   AirSys_prm_effAfrClc[1] = u16LocalRateLimOutElmnt;

   /* -- Third element of the table -- */
   VEMS_vidGET(FARSp_rMixtFullLdSpRaw, u16LocalFARSp_rMixtFullLdSpRaw);
   if (u16LocalFARSp_rMixtFullLdSpRaw <= 60128)
   {
      u16LocalInput = (uint16)((u16LocalFARSp_rMixtFullLdSpRaw * 400) / 367);
   }
   else
   {
      u16LocalInput = 65535;
   }
   u16localCalcPara = MATHSRV_u16CalcParaIncAryU16(Inj_rlamEng_A,
                                                   u16LocalInput,
                                                   9);
   u16LocalRateLimInput = MATHSRV_u16Interp1d(AirSys_effAfr_T,
                                              u16localCalcPara);

   u16LocalRateLimOutElmnt = AirSys_prm_effAfrClc[2];
   u16LocalRateLimOutElmnt = MATHSRV_u16SlewFilter(u16LocalRateLimOutElmnt,
                                                   u16LocalRateLimInput,
                                                   u16LocalRateLimInc,
                                                   u16LocalRateLimDec);
   AirSys_prm_effAfrClc[2] = u16LocalRateLimOutElmnt;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCoordination_2                                 */
/* !Description :  Ce bloc permet de coordonner les valeurs de rendement dans */
/*                 des cas de multi-carburation.                              */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_033.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 AirSys_prm_effAfrFlex[3];                                    */
/*  input uint8 IgSys_prm_facFlex[10];                                        */
/*  input uint16 AirSys_prm_effAfrGas[3];                                     */
/*  input uint8 IgSys_prm_facGas[10];                                         */
/*  input boolean AirSys_bFlexEffAfr_C;                                       */
/*  input uint16 AirSys_prm_effAfrClc[3];                                     */
/*  input boolean AirSys_bGasEffAfr_C;                                        */
/*  input uint16 AirSys_prm_effAfrFlexCor_MP[3];                              */
/*  output uint16 AirSys_prm_effAfrFlexCor_MP[3];                             */
/*  output uint16 AirSys_effAfr;                                              */
/*  output uint32 AirSys_rClcLamEfc;                                          */
/*  output uint32 AirSys_rFullLdLamEfc;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCoordination_2(void)
{
   uint8  u8LocalRate1;
   uint8  u8LocalRate2;
   uint8  u8LocalDiff;
   uint8  u8LocalIndex;
   uint16 u16LocalAirSys_prm_effAfrFlex[3];
   /*QAC message (Msg(2:3204)) : no impact*/
   uint16 u16LocalAirSys_prm_effAfrGas[3];
   /*QAC message (Msg(2:3204)) : no impact*/
   uint16 u16LocalAirSys_effAfr;
   uint32 u32LocalBaryInput1_1;
   uint32 u32LocalBaryInput1_2;
   uint32 u32LocalProd1;
   uint32 u32LocalProd2;
   uint32 u32LocalBarycentre1;
   uint32 u32LocalBarycentre2;
   uint32 u32LocalAirSys_rClcLamEfc;
   uint32 u32LocalAirSys_rFullLdLamEfc;


   VEMS_vidGET1DArray(AirSys_prm_effAfrFlex, 3, u16LocalAirSys_prm_effAfrFlex);

   VEMS_vidGET1DArrayElement(IgSys_prm_facFlex, 7, u8LocalRate1);

   VEMS_vidGET1DArray(AirSys_prm_effAfrGas, 3, u16LocalAirSys_prm_effAfrGas);

   VEMS_vidGET1DArrayElement(IgSys_prm_facGas, 7, u8LocalRate2);

   /*-- Calc Barycentre 1 --*/

   for (u8LocalIndex = 0; u8LocalIndex < 3; u8LocalIndex++)
   {
      if (AirSys_bFlexEffAfr_C != 0)
      {
         u32LocalBaryInput1_1 = u16LocalAirSys_prm_effAfrFlex[u8LocalIndex];
      }
      else
      {
         u32LocalBaryInput1_1 = ( AirSys_prm_effAfrClc[u8LocalIndex]
                                + u16LocalAirSys_prm_effAfrFlex[u8LocalIndex]);
      }

      u8LocalRate1 = (uint8)MATHSRV_udtMIN(u8LocalRate1, 128);

      u32LocalProd1 = (u32LocalBaryInput1_1 * u8LocalRate1);
      u32LocalProd1 = ((u32LocalProd1 + 64) / 128);

      u8LocalDiff = (uint8)(128 - u8LocalRate1);
      u32LocalProd2 = (AirSys_prm_effAfrClc[u8LocalIndex] * u8LocalDiff);
      u32LocalProd2 = ((u32LocalProd2 + 64) / 128);

      u32LocalBarycentre1 = (u32LocalProd1 + u32LocalProd2);

      AirSys_prm_effAfrFlexCor_MP[u8LocalIndex] =
         (uint16)MATHSRV_udtMIN(u32LocalBarycentre1, 65535);

      /*-- Calc Barycentre 2 --*/

      if (AirSys_bGasEffAfr_C != 0)
      {
         u32LocalBaryInput1_2 = u16LocalAirSys_prm_effAfrGas[u8LocalIndex];
      }
      else
      {
         u32LocalBaryInput1_2 = ( AirSys_prm_effAfrFlexCor_MP[u8LocalIndex]
                                + u16LocalAirSys_prm_effAfrGas[u8LocalIndex]);
      }

      u8LocalRate2 = (uint8)MATHSRV_udtMIN(u8LocalRate2, 128);
      u32LocalProd1 = ( (u32LocalBaryInput1_2 * u8LocalRate2)+ 64) / 128;

      u8LocalDiff = (uint8)(128 - u8LocalRate2);
      u32LocalProd2 = ( AirSys_prm_effAfrFlexCor_MP[u8LocalIndex]
                      * u8LocalDiff);
      u32LocalProd2 = ((u32LocalProd2 + 64) / 128);

      u32LocalBarycentre2 = (u32LocalProd1 + u32LocalProd2);

      if (u8LocalIndex == 0)
      {
         u16LocalAirSys_effAfr = (uint16)MATHSRV_udtMIN(u32LocalBarycentre2,
                                                        65535);
         VEMS_vidSET(AirSys_effAfr, u16LocalAirSys_effAfr);
      }
      else
      {
         if (u8LocalIndex == 1)
         {
            u32LocalAirSys_rClcLamEfc =
               MATHSRV_udtMIN(u32LocalBarycentre2, 65536);
            VEMS_vidSET(AirSys_rClcLamEfc, u32LocalAirSys_rClcLamEfc);
         }
         else
         {
            u32LocalAirSys_rFullLdLamEfc =
               MATHSRV_udtMIN(u32LocalBarycentre2, 65536);
            VEMS_vidSET(AirSys_rFullLdLamEfc, u32LocalAirSys_rFullLdLamEfc);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCalc_egr_efficiency                            */
/* !Description :  Le rendement d’EGR est issu d’une cartographie fonction du */
/*                 taux d’EGR                                                 */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_035.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 AirSys_rGradEGRReqLim_C;                                      */
/*  input uint16 AirSys_tiSdlFastAirTqEff_C;                                  */
/*  input uint16 EGRSys_rEGRReq;                                              */
/*  input uint16 AirSys_rEGR_A[9];                                            */
/*  input uint8 AirSys_effEGR_T[9];                                           */
/*  input uint8 AirSys_effEGRClc;                                             */
/*  output uint8 AirSys_effEGRClc;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalc_egr_efficiency(void)
{
   uint16 u16LocalEGRSys_rEGRReq;
   uint8  u8LocalRateLimInput;
   uint8  u8LocalRateLimDec;
   uint8  u8LocalRateLimInc;
   uint16 u16LocalRateLimInc;
   uint16 u16localCalcPara;
   uint32 u32LocalRateLimInc;


   /*Production of Inc and Dec parameters*/
   u32LocalRateLimInc = (uint32)( AirSys_rGradEGRReqLim_C
                                * AirSys_tiSdlFastAirTqEff_C);
   u16LocalRateLimInc = (uint16)((u32LocalRateLimInc + 250) / 500);

   u8LocalRateLimInc = (uint8)MATHSRV_udtMIN(u16LocalRateLimInc, 255);
   u8LocalRateLimDec = u8LocalRateLimInc;

   VEMS_vidGET(EGRSys_rEGRReq, u16LocalEGRSys_rEGRReq);

   u16localCalcPara = MATHSRV_u16CalcParaIncAryU16(AirSys_rEGR_A,
                                                   u16LocalEGRSys_rEGRReq,
                                                   9);
   u8LocalRateLimInput = MATHSRV_u8Interp1d(AirSys_effEGR_T, u16localCalcPara);

   AirSys_effEGRClc = MATHSRV_u8SlewFilter(AirSys_effEGRClc,
                                           u8LocalRateLimInput,
                                           u8LocalRateLimInc,
                                           u8LocalRateLimDec);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCoordination_3                                 */
/* !Description :  Ce bloc permet de coordonner les valeurs de rendement dans */
/*                 les cas de multi-carburation.                              */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_036.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 AirSys_effEGRFlex;                                            */
/*  input boolean AirSys_bFlexEffEGR_C;                                       */
/*  input uint8 AirSys_effEGRClc;                                             */
/*  input uint8 IgSys_prm_facFlex[10];                                        */
/*  input uint8 AirSys_effEGRGas;                                             */
/*  input boolean AirSys_bGasEffEGR_C;                                        */
/*  input uint8 AirSys_effEGRWiFlexCor_MP;                                    */
/*  input uint8 IgSys_prm_facGas[10];                                         */
/*  output uint8 AirSys_effEGRWiFlexCor_MP;                                   */
/*  output uint8 AirSys_effEGR;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCoordination_3(void)
{
   uint8  u8LocalRate1;
   uint8  u8LocalRate2;
   uint8  u8LocalAirSys_effEGRFlex;
   uint8  u8LocalAirSys_effEGRGas;
   uint8  u8LocalAirSys_effEGR;
   uint16 u16LocalBaryInput1_1;
   uint16 u16LocalBaryInput1_2;
   sint16 s16LocalCalc;


   /*-- Calc Barycentre 1 --*/
   VEMS_vidGET(AirSys_effEGRFlex, u8LocalAirSys_effEGRFlex);

   if (AirSys_bFlexEffEGR_C != 0)
   {
      u16LocalBaryInput1_1 = u8LocalAirSys_effEGRFlex;
   }
   else
   {
      u16LocalBaryInput1_1 = (uint16)( u8LocalAirSys_effEGRFlex
                                     + AirSys_effEGRClc
                                     + 384);
   }

   VEMS_vidGET1DArrayElement(IgSys_prm_facFlex, 6, u8LocalRate1);
   u8LocalRate1 = (uint8)MATHSRV_udtMIN(u8LocalRate1, 128);

   s16LocalCalc = (sint16)(u16LocalBaryInput1_1 - AirSys_effEGRClc);
   if (s16LocalCalc > 0)
   {
      s16LocalCalc = (sint16)(((s16LocalCalc * u8LocalRate1) + 64) / 128);
   }
   else
   {
      s16LocalCalc = (sint16)(((s16LocalCalc * u8LocalRate1) - 64) / 128);
   }
   s16LocalCalc = (sint16)(s16LocalCalc + AirSys_effEGRClc);

   AirSys_effEGRWiFlexCor_MP = (uint8)MATHSRV_udtMIN(s16LocalCalc, 255);

   /*-- Calc Barycentre 2 --*/
   VEMS_vidGET(AirSys_effEGRGas, u8LocalAirSys_effEGRGas);

   if (AirSys_bGasEffEGR_C != 0)
   {
      u16LocalBaryInput1_2 = u8LocalAirSys_effEGRGas;
   }
   else
   {
      u16LocalBaryInput1_2 = (uint16)( u8LocalAirSys_effEGRGas
                                     + AirSys_effEGRWiFlexCor_MP
                                     + 384);
   }

   VEMS_vidGET1DArrayElement(IgSys_prm_facGas, 6, u8LocalRate2);
   u8LocalRate2 = (uint8)MATHSRV_udtMIN(u8LocalRate2, 128);

   s16LocalCalc = (sint16)(u16LocalBaryInput1_2 - AirSys_effEGRWiFlexCor_MP);
   if (s16LocalCalc > 0)
   {
      s16LocalCalc = (sint16)(((s16LocalCalc * u8LocalRate2) + 64) / 128);
   }
   else
   {
      s16LocalCalc = (sint16)(((s16LocalCalc * u8LocalRate2) - 64) / 128);
   }
   s16LocalCalc = (sint16)(s16LocalCalc + AirSys_effEGRWiFlexCor_MP);

   u8LocalAirSys_effEGR = (uint8)MATHSRV_udtMIN(s16LocalCalc, 255);

   VEMS_vidSET(AirSys_effEGR, u8LocalAirSys_effEGR);
}
/*---------------------------------end of file--------------------------------*/