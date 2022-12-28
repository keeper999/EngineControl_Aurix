/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ADDONADVMIN                                             */
/* !Description     : ADDONADVMIN component                                   */
/*                                                                            */
/* !Module          : ADDONADVMIN                                             */
/* !Description     : Offset d'avance minimale                                */
/*                                                                            */
/* !File            : ADDONADVMIN_FCT1.c                                      */
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
/*   1 / ADDONADVMIN_vidInitOutput                                            */
/*   2 / ADDONADVMIN_vidOffset_Aamini                                         */
/*   3 / ADDONADVMIN_vidUnvectorize_Mode                                      */
/*   4 / ADDONADVMIN_vidMode_Mask                                             */
/*   5 / ADDONADVMIN_vidCalibrations                                          */
/*   6 / ADDONADVMIN_vidUnvectrzActivBool                                     */
/*   7 / ADDONADVMIN_vidCalibration_1                                         */
/*   8 / ADDONADVMIN_vidCalibration_2                                         */
/*   9 / ADDONADVMIN_vidCalibration_3                                         */
/*   10 / ADDONADVMIN_vidCalibration_4                                        */
/*                                                                            */
/* !Reference   : V02 NT 11 01472 / 01                                        */
/* !OtherRefs   : 01460_10_01466_2 / 01                                       */
/* !OtherRefs   : VEMS V02 ECU#058205                                         */
/* !OtherRefs   : VEMS V02 ECU#053831                                         */
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
#include "ADDONADVMIN.h"
#include "ADDONADVMIN_L.h"
#include "ADDONADVMIN_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidInitOutput                                  */
/* !Description :  Cette fonction initialise les sorties du module.           */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output sint16 IgSys_agIgCmbModOfsMinCmb;                                  */
/*  output sint16 IgSys_ofsAgIgMinCal1;                                       */
/*  output sint16 IgSys_ofsAgIgMinCal2;                                       */
/*  output sint16 IgSys_ofsAgIgMinCal3;                                       */
/*  output sint16 IgSys_ofsAgIgMinCal4;                                       */
/*  output sint16 IgSys_ofsAgIgMinCal5;                                       */
/*  output sint16 IgSys_ofsAgIgMinCal6;                                       */
/*  output sint16 IgSys_ofsAgIgMinCal7;                                       */
/*  output sint16 IgSys_ofsAgIgMinCal8;                                       */
/*  output sint16 IgSys_ofsAgIgMinCal9;                                       */
/*  output sint16 IgSys_ofsAgIgMinCal10;                                      */
/*  output sint16 IgSys_ofsAgIgMinCal11;                                      */
/*  output sint16 IgSys_ofsAgIgMinCal12;                                      */
/*  output sint16 IgSys_ofsAgIgMinCal13;                                      */
/*  output sint16 IgSys_ofsAgIgMinCal14;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidInitOutput(void)
{
   VEMS_vidSET(IgSys_agIgCmbModOfsMinCmb, 0);

   IgSys_ofsAgIgMinCal1 = 0;
   IgSys_ofsAgIgMinCal2 = 0;
   IgSys_ofsAgIgMinCal3 = 0;
   IgSys_ofsAgIgMinCal4 = 0;
   IgSys_ofsAgIgMinCal5 = 0;
   IgSys_ofsAgIgMinCal6 = 0;
   IgSys_ofsAgIgMinCal7 = 0;
   IgSys_ofsAgIgMinCal8 = 0;
   IgSys_ofsAgIgMinCal9 = 0;
   IgSys_ofsAgIgMinCal10 = 0;
   IgSys_ofsAgIgMinCal11 = 0;
   IgSys_ofsAgIgMinCal12 = 0;
   IgSys_ofsAgIgMinCal13 = 0;
   IgSys_ofsAgIgMinCal14 = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidOffset_Aamini                               */
/* !Description :  La fonction est constituée de 5 blocs permettant de        */
/*                 calculer l’offset d’avance minimale.                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ADDONADVMIN_vidUnvectorize_Mode();                       */
/*  extf argret void ADDONADVMIN_vidMode_Mask();                              */
/*  extf argret void ADDONADVMIN_vidCalibrations();                           */
/*  extf argret void ADDONADVMIN_vidSelect_Modes();                           */
/*  extf argret void ADDONADVMIN_vidInterpolation();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidOffset_Aamini(void)
{
   ADDONADVMIN_vidUnvectorize_Mode();
   ADDONADVMIN_vidMode_Mask();
   ADDONADVMIN_vidCalibrations();
   ADDONADVMIN_vidSelect_Modes();
   ADDONADVMIN_vidInterpolation();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidUnvectorize_Mode                            */
/* !Description :  Ce bloc permet de sélectionner les informations provenant  */
/*                 du gestionnaire de modes de combustion EOM.                */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_003.01                                     */
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
/*  output uint8 IgSys_idxOfsAgIgMinBas1ModCur;                               */
/*  output uint8 IgSys_idxOfsAgIgMinBas2ModCur;                               */
/*  output uint8 IgSys_idxOfsAgIgMinBas1ModTar;                               */
/*  output uint8 IgSys_idxOfsAgIgMinBas2ModTar;                               */
/*  output uint8 IgSys_facOfsAgIgMinBasModCur;                                */
/*  output uint8 IgSys_facOfsAgIgMinBasModTar;                                */
/*  output uint8 IgSys_facOfsAgIgMinTranMod;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidUnvectorize_Mode(void)
{
   uint8 u8LocalIndex_Bas1ModCur;
   uint8 u8LocalIndex_Bas2ModCur;
   uint8 u8LocalIndex_Bas1ModTar;
   uint8 u8LocalIndex_Bas2ModTar;
   uint8 u8LocalIndex_facBasModCur;
   uint8 u8LocalIndex_facBasModTar;
   uint8 u8LocalIndex_facTranMod;


   VEMS_vidGET1DArrayElement(EOM_prm_idxBas1ModCur,
                             10,
                             u8LocalIndex_Bas1ModCur);
   IgSys_idxOfsAgIgMinBas1ModCur =
      (uint8)MATHSRV_udtCLAMP(u8LocalIndex_Bas1ModCur, 1, 14);

   VEMS_vidGET1DArrayElement(EOM_prm_idxBas2ModCur,
                             10,
                             u8LocalIndex_Bas2ModCur);
   IgSys_idxOfsAgIgMinBas2ModCur =
      (uint8)MATHSRV_udtCLAMP(u8LocalIndex_Bas2ModCur, 1, 14);

   VEMS_vidGET1DArrayElement(EOM_prm_idxBas1ModTar,
                             10,
                             u8LocalIndex_Bas1ModTar);
   IgSys_idxOfsAgIgMinBas1ModTar =
      (uint8)MATHSRV_udtCLAMP(u8LocalIndex_Bas1ModTar, 1, 14);

   VEMS_vidGET1DArrayElement(EOM_prm_idxBas2ModTar,
                             10,
                             u8LocalIndex_Bas2ModTar);
   IgSys_idxOfsAgIgMinBas2ModTar =
      (uint8)MATHSRV_udtCLAMP(u8LocalIndex_Bas2ModTar, 1, 14);

   VEMS_vidGET1DArrayElement(EOM_prm_facBasModCur,
                             10,
                             u8LocalIndex_facBasModCur);
   u8LocalIndex_facBasModCur = (uint8)((u8LocalIndex_facBasModCur * 25) / 32);
   IgSys_facOfsAgIgMinBasModCur =
      (uint8)MATHSRV_udtMIN(u8LocalIndex_facBasModCur, 100);

   VEMS_vidGET1DArrayElement(EOM_prm_facBasModTar,
                             10,
                             u8LocalIndex_facBasModTar);
   u8LocalIndex_facBasModTar = (uint8)((u8LocalIndex_facBasModTar * 25) / 32);
   IgSys_facOfsAgIgMinBasModTar =
      (uint8)MATHSRV_udtMIN(u8LocalIndex_facBasModTar, 100);

   VEMS_vidGET1DArrayElement(EOM_prm_facTranMod, 10, u8LocalIndex_facTranMod);
   u8LocalIndex_facTranMod = (uint8)((u8LocalIndex_facTranMod * 25) / 32);
   IgSys_facOfsAgIgMinTranMod =
      (uint8)MATHSRV_udtMIN(u8LocalIndex_facTranMod, 100);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidMode_Mask                                   */
/* !Description :  Ce bloc permet de sélectionner le numéro des cartographies */
/*                 utiles.                                                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 IgSys_idxOfsAgIgMinBas1ModCur;                                */
/*  input uint8 IgSys_idxOfsAgIgMinBas2ModCur;                                */
/*  input uint8 IgSys_idxOfsAgIgMinBas1ModTar;                                */
/*  input uint8 IgSys_idxOfsAgIgMinBas2ModTar;                                */
/*  output boolean IgSys_prm_bAcvOfsAgIgMinCal[14];                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidMode_Mask(void)
{
   boolean bLocalTempTab[IGSYS_PRM_BACVOFSAGIGMINCAL_COLS];
   uint8   u8LocalIndex;
   uint8   u8LocalIdx1ModCur;
   uint8   u8LocalIdx2ModCur;
   uint8   u8LocalIdx1ModTar;
   uint8   u8LocalIdx2ModTar;


   for (u8LocalIndex = 0; u8LocalIndex < 14; u8LocalIndex++)
   {
      bLocalTempTab[u8LocalIndex] = 0;
   }

   u8LocalIdx1ModCur =
      (uint8)MATHSRV_udtCLAMP(IgSys_idxOfsAgIgMinBas1ModCur, 1, 14);

   u8LocalIdx2ModCur =
      (uint8)MATHSRV_udtCLAMP(IgSys_idxOfsAgIgMinBas2ModCur, 1, 14);

   u8LocalIdx1ModTar =
      (uint8)MATHSRV_udtCLAMP(IgSys_idxOfsAgIgMinBas1ModTar, 1, 14);

   u8LocalIdx2ModTar =
      (uint8)MATHSRV_udtCLAMP(IgSys_idxOfsAgIgMinBas2ModTar, 1, 14);

   bLocalTempTab[u8LocalIdx1ModCur - 1] = 1;
   bLocalTempTab[u8LocalIdx2ModCur - 1] = 1;
   bLocalTempTab[u8LocalIdx1ModTar - 1] = 1;
   bLocalTempTab[u8LocalIdx2ModTar - 1] = 1;

   for(u8LocalIndex = 0; u8LocalIndex <= 13; u8LocalIndex++)
   {
      IgSys_prm_bAcvOfsAgIgMinCal[u8LocalIndex] = bLocalTempTab[u8LocalIndex];
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidCalibrations                                */
/* !Description :  Ce bloc regroupe les différentes calibrations de la        */
/*                 fonction.                                                  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ADDONADVMIN_vidUnvectrzActivBool();                      */
/*  extf argret void ADDONADVMIN_vidCalibration_1();                          */
/*  extf argret void ADDONADVMIN_vidCalibration_2();                          */
/*  extf argret void ADDONADVMIN_vidCalibration_3();                          */
/*  extf argret void ADDONADVMIN_vidCalibration_4();                          */
/*  extf argret void ADDONADVMIN_vidCalibration_5();                          */
/*  extf argret void ADDONADVMIN_vidCalibration_6();                          */
/*  extf argret void ADDONADVMIN_vidCalibration_7();                          */
/*  extf argret void ADDONADVMIN_vidCalibration_8();                          */
/*  extf argret void ADDONADVMIN_vidCalibration_9();                          */
/*  extf argret void ADDONADVMIN_vidCalibration_10();                         */
/*  extf argret void ADDONADVMIN_vidCalibration_11();                         */
/*  extf argret void ADDONADVMIN_vidCalibration_12();                         */
/*  extf argret void ADDONADVMIN_vidCalibration_13();                         */
/*  extf argret void ADDONADVMIN_vidCalibration_14();                         */
/*  extf argret void ADDONADVMIN_vidVectorizeCalibs();                        */
/*  input boolean IgSys_bAcvOfsAgIgMinCal1;                                   */
/*  input boolean IgSys_bAcvOfsAgIgMinCal2;                                   */
/*  input boolean IgSys_bAcvOfsAgIgMinCal3;                                   */
/*  input boolean IgSys_bAcvOfsAgIgMinCal4;                                   */
/*  input boolean IgSys_bAcvOfsAgIgMinCal5;                                   */
/*  input boolean IgSys_bAcvOfsAgIgMinCal6;                                   */
/*  input boolean IgSys_bAcvOfsAgIgMinCal7;                                   */
/*  input boolean IgSys_bAcvOfsAgIgMinCal8;                                   */
/*  input boolean IgSys_bAcvOfsAgIgMinCal9;                                   */
/*  input boolean IgSys_bAcvOfsAgIgMinCal10;                                  */
/*  input boolean IgSys_bAcvOfsAgIgMinCal11;                                  */
/*  input boolean IgSys_bAcvOfsAgIgMinCal12;                                  */
/*  input boolean IgSys_bAcvOfsAgIgMinCal13;                                  */
/*  input boolean IgSys_bAcvOfsAgIgMinCal14;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidCalibrations(void)
{
   ADDONADVMIN_vidUnvectrzActivBool();

   if (IgSys_bAcvOfsAgIgMinCal1 != 0)
   {
      ADDONADVMIN_vidCalibration_1();
   }
   if (IgSys_bAcvOfsAgIgMinCal2 != 0)
   {
      ADDONADVMIN_vidCalibration_2();
   }
   if (IgSys_bAcvOfsAgIgMinCal3 != 0)
   {
      ADDONADVMIN_vidCalibration_3();
   }
   if (IgSys_bAcvOfsAgIgMinCal4 != 0)
   {
      ADDONADVMIN_vidCalibration_4();
   }
   if (IgSys_bAcvOfsAgIgMinCal5 != 0)
   {
      ADDONADVMIN_vidCalibration_5();
   }
   if (IgSys_bAcvOfsAgIgMinCal6 != 0)
   {
      ADDONADVMIN_vidCalibration_6();
   }
   if (IgSys_bAcvOfsAgIgMinCal7 != 0)
   {
      ADDONADVMIN_vidCalibration_7();
   }
   if (IgSys_bAcvOfsAgIgMinCal8 != 0)
   {
      ADDONADVMIN_vidCalibration_8();
   }
   if (IgSys_bAcvOfsAgIgMinCal9 != 0)
   {
      ADDONADVMIN_vidCalibration_9();
   }
   if (IgSys_bAcvOfsAgIgMinCal10 != 0)
   {
      ADDONADVMIN_vidCalibration_10();
   }
   if (IgSys_bAcvOfsAgIgMinCal11 != 0)
   {
      ADDONADVMIN_vidCalibration_11();
   }
   if (IgSys_bAcvOfsAgIgMinCal12 != 0)
   {
      ADDONADVMIN_vidCalibration_12();
   }
   if (IgSys_bAcvOfsAgIgMinCal13 != 0)
   {
      ADDONADVMIN_vidCalibration_13();
   }
   if (IgSys_bAcvOfsAgIgMinCal14 != 0)
   {
      ADDONADVMIN_vidCalibration_14();
   }

   ADDONADVMIN_vidVectorizeCalibs();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidUnvectrzActivBool                           */
/* !Description :  Ce bloc permet de démultiplexer le flux de sélection des   */
/*                 cartographies utiles.                                      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean IgSys_prm_bAcvOfsAgIgMinCal[14];                            */
/*  output boolean IgSys_bAcvOfsAgIgMinCal1;                                  */
/*  output boolean IgSys_bAcvOfsAgIgMinCal2;                                  */
/*  output boolean IgSys_bAcvOfsAgIgMinCal3;                                  */
/*  output boolean IgSys_bAcvOfsAgIgMinCal4;                                  */
/*  output boolean IgSys_bAcvOfsAgIgMinCal5;                                  */
/*  output boolean IgSys_bAcvOfsAgIgMinCal6;                                  */
/*  output boolean IgSys_bAcvOfsAgIgMinCal7;                                  */
/*  output boolean IgSys_bAcvOfsAgIgMinCal8;                                  */
/*  output boolean IgSys_bAcvOfsAgIgMinCal9;                                  */
/*  output boolean IgSys_bAcvOfsAgIgMinCal10;                                 */
/*  output boolean IgSys_bAcvOfsAgIgMinCal11;                                 */
/*  output boolean IgSys_bAcvOfsAgIgMinCal12;                                 */
/*  output boolean IgSys_bAcvOfsAgIgMinCal13;                                 */
/*  output boolean IgSys_bAcvOfsAgIgMinCal14;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidUnvectrzActivBool(void)
{
   IgSys_bAcvOfsAgIgMinCal1 = IgSys_prm_bAcvOfsAgIgMinCal[0];
   IgSys_bAcvOfsAgIgMinCal2 = IgSys_prm_bAcvOfsAgIgMinCal[1];
   IgSys_bAcvOfsAgIgMinCal3 = IgSys_prm_bAcvOfsAgIgMinCal[2];
   IgSys_bAcvOfsAgIgMinCal4 = IgSys_prm_bAcvOfsAgIgMinCal[3];
   IgSys_bAcvOfsAgIgMinCal5 = IgSys_prm_bAcvOfsAgIgMinCal[4];
   IgSys_bAcvOfsAgIgMinCal6 = IgSys_prm_bAcvOfsAgIgMinCal[5];
   IgSys_bAcvOfsAgIgMinCal7 = IgSys_prm_bAcvOfsAgIgMinCal[6];
   IgSys_bAcvOfsAgIgMinCal8 = IgSys_prm_bAcvOfsAgIgMinCal[7];
   IgSys_bAcvOfsAgIgMinCal9 = IgSys_prm_bAcvOfsAgIgMinCal[8];
   IgSys_bAcvOfsAgIgMinCal10 = IgSys_prm_bAcvOfsAgIgMinCal[9];
   IgSys_bAcvOfsAgIgMinCal11 = IgSys_prm_bAcvOfsAgIgMinCal[10];
   IgSys_bAcvOfsAgIgMinCal12 = IgSys_prm_bAcvOfsAgIgMinCal[11];
   IgSys_bAcvOfsAgIgMinCal13 = IgSys_prm_bAcvOfsAgIgMinCal[12];
   IgSys_bAcvOfsAgIgMinCal14 = IgSys_prm_bAcvOfsAgIgMinCal[13];
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidCalibration_1                               */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMin_A[16];                                  */
/*  input uint16 IgSys_rAirLdOfsAgIgMin_A[16];                                */
/*  input uint8 IgSys_ofsAgIgMinCal1_M[16][16];                               */
/*  output sint16 IgSys_ofsAgIgMinCal1;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidCalibration_1(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   sint16 s16IgSys_ofsAgIgMinCal;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgMin_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgMin_A,
                                                    u16LocalEngM_rAirLdCor,
                                                    16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMinCal1_M[0][0],
                                         u16LocalCalcParaX,
                                         u16LocalCalcParaY,
                                         16);

   s16IgSys_ofsAgIgMinCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMinCal1 = s16IgSys_ofsAgIgMinCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidCalibration_2                               */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMin_A[16];                                  */
/*  input uint16 IgSys_rAirLdOfsAgIgMin_A[16];                                */
/*  input uint8 IgSys_ofsAgIgMinCal2_M[16][16];                               */
/*  output sint16 IgSys_ofsAgIgMinCal2;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidCalibration_2(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   sint16 s16IgSys_ofsAgIgMinCal;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgMin_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgMin_A,
                                                    u16LocalEngM_rAirLdCor,
                                                    16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMinCal2_M[0][0],
                                         u16LocalCalcParaX,
                                         u16LocalCalcParaY,
                                         16);

   s16IgSys_ofsAgIgMinCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMinCal2 = s16IgSys_ofsAgIgMinCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidCalibration_3                               */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMin_A[16];                                  */
/*  input uint16 IgSys_rAirLdOfsAgIgMin_A[16];                                */
/*  input uint8 IgSys_ofsAgIgMinCal3_M[16][16];                               */
/*  output sint16 IgSys_ofsAgIgMinCal3;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidCalibration_3(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   sint16 s16IgSys_ofsAgIgMinCal;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgMin_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgMin_A,
                                                    u16LocalEngM_rAirLdCor,
                                                    16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMinCal3_M[0][0],
                                         u16LocalCalcParaX,
                                         u16LocalCalcParaY,
                                         16);

   s16IgSys_ofsAgIgMinCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMinCal3 = s16IgSys_ofsAgIgMinCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidCalibration_4                               */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMin_A[16];                                  */
/*  input uint16 IgSys_rAirLdOfsAgIgMin_A[16];                                */
/*  input uint8 IgSys_ofsAgIgMinCal4_M[16][16];                               */
/*  output sint16 IgSys_ofsAgIgMinCal4;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidCalibration_4(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   sint16 s16IgSys_ofsAgIgMinCal;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgMin_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgMin_A,
                                                    u16LocalEngM_rAirLdCor,
                                                    16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMinCal4_M[0][0],
                                         u16LocalCalcParaX,
                                         u16LocalCalcParaY,
                                         16);

   s16IgSys_ofsAgIgMinCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMinCal4 = s16IgSys_ofsAgIgMinCal;
}
/*---------------------------------end of file--------------------------------*/