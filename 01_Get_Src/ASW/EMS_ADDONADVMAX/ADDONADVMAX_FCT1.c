/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ADDONADVMAX                                             */
/* !Description     : ADDONADVMAX component                                   */
/*                                                                            */
/* !Module          : ADDONADVMAX                                             */
/* !Description     : Offset d'avance limite cliquetis                        */
/*                                                                            */
/* !File            : ADDONADVMAX_FCT1.C                                      */
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
/*   1 / ADDONADVMAX_vidInitOutput                                            */
/*   2 / ADDONADVMAX_vidOffset_Aamaxi                                         */
/*   3 / ADDONADVMAX_vidUnvectorize_Mode                                      */
/*   4 / ADDONADVMAX_vidMode_Mask                                             */
/*   5 / ADDONADVMAX_vidCalibrations                                          */
/*   6 / ADDONADVMAX_vidUnvectrzActivBool                                     */
/*   7 / ADDONADVMAX_vidCalibration_1                                         */
/*   8 / ADDONADVMAX_vidCalibration_2                                         */
/*   9 / ADDONADVMAX_vidCalibration_3                                         */
/*   10 / ADDONADVMAX_vidCalibration_4                                        */
/*                                                                            */
/* !Reference   : V02 NT 11 01471 / 01                                        */
/* !OtherRefs   : 01460_10_01465_2 / 01                                       */
/* !OtherRefs   : VEMS V02 ECU#053830                                         */
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
#include "ADDONADVMAX.h"
#include "ADDONADVMAX_L.h"
#include "ADDONADVMAX_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidInitOutput                                  */
/* !Description :  Cette fonction initialise les sorties du module.           */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 IgSys_agIgCmbModOfsMax;                                      */
/*  output sint16 IgSys_ofsAgIgMaxCal1;                                       */
/*  output sint16 IgSys_ofsAgIgMaxCal2;                                       */
/*  output sint16 IgSys_ofsAgIgMaxCal3;                                       */
/*  output sint16 IgSys_ofsAgIgMaxCal4;                                       */
/*  output sint16 IgSys_ofsAgIgMaxCal5;                                       */
/*  output sint16 IgSys_ofsAgIgMaxCal6;                                       */
/*  output sint16 IgSys_ofsAgIgMaxCal7;                                       */
/*  output sint16 IgSys_ofsAgIgMaxCal8;                                       */
/*  output sint16 IgSys_ofsAgIgMaxCal9;                                       */
/*  output sint16 IgSys_ofsAgIgMaxCal10;                                      */
/*  output sint16 IgSys_ofsAgIgMaxCal11;                                      */
/*  output sint16 IgSys_ofsAgIgMaxCal12;                                      */
/*  output sint16 IgSys_ofsAgIgMaxCal13;                                      */
/*  output sint16 IgSys_ofsAgIgMaxCal14;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidInitOutput(void)
{
   VEMS_vidSET(IgSys_agIgCmbModOfsMax, 96);

   IgSys_ofsAgIgMaxCal1 = 0;
   IgSys_ofsAgIgMaxCal2 = 0;
   IgSys_ofsAgIgMaxCal3 = 0;
   IgSys_ofsAgIgMaxCal4 = 0;
   IgSys_ofsAgIgMaxCal5 = 0;
   IgSys_ofsAgIgMaxCal6 = 0;
   IgSys_ofsAgIgMaxCal7 = 0;
   IgSys_ofsAgIgMaxCal8 = 0;
   IgSys_ofsAgIgMaxCal9 = 0;
   IgSys_ofsAgIgMaxCal10 = 0;
   IgSys_ofsAgIgMaxCal11 = 0;
   IgSys_ofsAgIgMaxCal12 = 0;
   IgSys_ofsAgIgMaxCal13 = 0;
   IgSys_ofsAgIgMaxCal14 = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidOffset_Aamaxi                               */
/* !Description :  La fonction est constituée de 5 blocs permettant de        */
/*                 calculer l’offset d’avance maximale.                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ADDONADVMAX_vidUnvectorize_Mode();                       */
/*  extf argret void ADDONADVMAX_vidMode_Mask();                              */
/*  extf argret void ADDONADVMAX_vidCalibrations();                           */
/*  extf argret void ADDONADVMAX_vidSelect_Modes();                           */
/*  extf argret void ADDONADVMAX_vidInterpolation();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidOffset_Aamaxi(void)
{
   ADDONADVMAX_vidUnvectorize_Mode();
   ADDONADVMAX_vidMode_Mask();
   ADDONADVMAX_vidCalibrations();
   ADDONADVMAX_vidSelect_Modes();
   ADDONADVMAX_vidInterpolation();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidUnvectorize_Mode                            */
/* !Description :  Ce bloc permet de sélectionner les informations provenant  */
/*                 du gestionnaire de modes de combustion EOM.                */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_003.01                                     */
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
/*  output uint8 IgSys_idxOfsAgIgMaxBas1ModCur;                               */
/*  output uint8 IgSys_idxOfsAgIgMaxBas2ModCur;                               */
/*  output uint8 IgSys_idxOfsAgIgMaxBas1ModTar;                               */
/*  output uint8 IgSys_idxOfsAgIgMaxBas2ModTar;                               */
/*  output uint8 IgSys_facOfsAgIgMaxBasModCur;                                */
/*  output uint8 IgSys_facOfsAgIgMaxBasModTar;                                */
/*  output uint8 IgSys_facOfsAgIgMaxTranMod;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidUnvectorize_Mode(void)
{
   uint8 u8LocalIndex_Bas1ModCur;
   uint8 u8LocalIndex_Bas2ModCur;
   uint8 u8LocalIndex_Bas1ModTar;
   uint8 u8LocalIndex_Bas2ModTar;
   uint8 u8LocalIndex_facBasModCur;
   uint8 u8LocalIndex_facBasModTar;
   uint8 u8LocalIndex_facTranMod;


   VEMS_vidGET1DArrayElement(EOM_prm_idxBas1ModCur,
                             9,
                             u8LocalIndex_Bas1ModCur);
   IgSys_idxOfsAgIgMaxBas1ModCur =
      (uint8)MATHSRV_udtCLAMP(u8LocalIndex_Bas1ModCur, 1, 14);

   VEMS_vidGET1DArrayElement(EOM_prm_idxBas2ModCur,
                             9,
                             u8LocalIndex_Bas2ModCur);
   IgSys_idxOfsAgIgMaxBas2ModCur =
      (uint8)MATHSRV_udtCLAMP(u8LocalIndex_Bas2ModCur, 1, 14);

   VEMS_vidGET1DArrayElement(EOM_prm_idxBas1ModTar,
                             9,
                             u8LocalIndex_Bas1ModTar);
   IgSys_idxOfsAgIgMaxBas1ModTar =
      (uint8)MATHSRV_udtCLAMP(u8LocalIndex_Bas1ModTar, 1, 14);

   VEMS_vidGET1DArrayElement(EOM_prm_idxBas2ModTar,
                             9,
                             u8LocalIndex_Bas2ModTar);
   IgSys_idxOfsAgIgMaxBas2ModTar =
      (uint8)MATHSRV_udtCLAMP(u8LocalIndex_Bas2ModTar, 1, 14);

   VEMS_vidGET1DArrayElement(EOM_prm_facBasModCur,
                             9,
                             u8LocalIndex_facBasModCur);
   u8LocalIndex_facBasModCur = (uint8)((u8LocalIndex_facBasModCur * 25) / 32);
   IgSys_facOfsAgIgMaxBasModCur =
      (uint8)MATHSRV_udtMIN(u8LocalIndex_facBasModCur, 100);

   VEMS_vidGET1DArrayElement(EOM_prm_facBasModTar,
                             9,
                             u8LocalIndex_facBasModTar);
   u8LocalIndex_facBasModTar = (uint8)((u8LocalIndex_facBasModTar * 25) / 32);
   IgSys_facOfsAgIgMaxBasModTar =
      (uint8)MATHSRV_udtMIN(u8LocalIndex_facBasModTar, 100);

   VEMS_vidGET1DArrayElement(EOM_prm_facTranMod, 9, u8LocalIndex_facTranMod);
   u8LocalIndex_facTranMod = (uint8)((u8LocalIndex_facTranMod * 25) / 32);
   IgSys_facOfsAgIgMaxTranMod =
      (uint8)MATHSRV_udtMIN(u8LocalIndex_facTranMod, 100);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidMode_Mask                                   */
/* !Description :  Ce bloc permet de sélectionner le numéro des cartographies */
/*                 utiles.                                                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 IgSys_idxOfsAgIgMaxBas1ModCur;                                */
/*  input uint8 IgSys_idxOfsAgIgMaxBas2ModCur;                                */
/*  input uint8 IgSys_idxOfsAgIgMaxBas1ModTar;                                */
/*  input uint8 IgSys_idxOfsAgIgMaxBas2ModTar;                                */
/*  output boolean IgSys_prm_bAcvOfsAgIgMaxCal[14];                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidMode_Mask(void)
{
   boolean bLocalTempTab[IGSYS_PRM_BACVOFSAGIGMAXCAL_COLS];
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
      (uint8)MATHSRV_udtCLAMP(IgSys_idxOfsAgIgMaxBas1ModCur, 1, 14);

   u8LocalIdx2ModCur =
      (uint8)MATHSRV_udtCLAMP(IgSys_idxOfsAgIgMaxBas2ModCur, 1, 14);

   u8LocalIdx1ModTar =
      (uint8)MATHSRV_udtCLAMP(IgSys_idxOfsAgIgMaxBas1ModTar, 1, 14);

   u8LocalIdx2ModTar =
      (uint8)MATHSRV_udtCLAMP(IgSys_idxOfsAgIgMaxBas2ModTar, 1, 14);

   bLocalTempTab[u8LocalIdx1ModCur - 1] = 1;
   bLocalTempTab[u8LocalIdx2ModCur - 1] = 1;
   bLocalTempTab[u8LocalIdx1ModTar - 1] = 1;
   bLocalTempTab[u8LocalIdx2ModTar - 1] = 1;

   for(u8LocalIndex = 0; u8LocalIndex < 14; u8LocalIndex++)
   {
      IgSys_prm_bAcvOfsAgIgMaxCal[u8LocalIndex] = bLocalTempTab[u8LocalIndex];
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidCalibrations                                */
/* !Description :  Ce bloc regroupe les différentes calibrations de la        */
/*                 fonction.                                                  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ADDONADVMAX_vidUnvectrzActivBool();                      */
/*  extf argret void ADDONADVMAX_vidCalibration_1();                          */
/*  extf argret void ADDONADVMAX_vidCalibration_2();                          */
/*  extf argret void ADDONADVMAX_vidCalibration_3();                          */
/*  extf argret void ADDONADVMAX_vidCalibration_4();                          */
/*  extf argret void ADDONADVMAX_vidCalibration_5();                          */
/*  extf argret void ADDONADVMAX_vidCalibration_6();                          */
/*  extf argret void ADDONADVMAX_vidCalibration_7();                          */
/*  extf argret void ADDONADVMAX_vidCalibration_8();                          */
/*  extf argret void ADDONADVMAX_vidCalibration_9();                          */
/*  extf argret void ADDONADVMAX_vidCalibration_10();                         */
/*  extf argret void ADDONADVMAX_vidCalibration_11();                         */
/*  extf argret void ADDONADVMAX_vidCalibration_12();                         */
/*  extf argret void ADDONADVMAX_vidCalibration_13();                         */
/*  extf argret void ADDONADVMAX_vidCalibration_14();                         */
/*  extf argret void ADDONADVMAX_vidVectorizeCalibs();                        */
/*  input boolean IgSys_bAcvOfsAgIgMaxCal1;                                   */
/*  input boolean IgSys_bAcvOfsAgIgMaxCal2;                                   */
/*  input boolean IgSys_bAcvOfsAgIgMaxCal3;                                   */
/*  input boolean IgSys_bAcvOfsAgIgMaxCal4;                                   */
/*  input boolean IgSys_bAcvOfsAgIgMaxCal5;                                   */
/*  input boolean IgSys_bAcvOfsAgIgMaxCal6;                                   */
/*  input boolean IgSys_bAcvOfsAgIgMaxCal7;                                   */
/*  input boolean IgSys_bAcvOfsAgIgMaxCal8;                                   */
/*  input boolean IgSys_bAcvOfsAgIgMaxCal9;                                   */
/*  input boolean IgSys_bAcvOfsAgIgMaxCal10;                                  */
/*  input boolean IgSys_bAcvOfsAgIgMaxCal11;                                  */
/*  input boolean IgSys_bAcvOfsAgIgMaxCal12;                                  */
/*  input boolean IgSys_bAcvOfsAgIgMaxCal13;                                  */
/*  input boolean IgSys_bAcvOfsAgIgMaxCal14;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidCalibrations(void)
{
   ADDONADVMAX_vidUnvectrzActivBool();

   if (IgSys_bAcvOfsAgIgMaxCal1 != 0)
   {
      ADDONADVMAX_vidCalibration_1();
   }
   if (IgSys_bAcvOfsAgIgMaxCal2 != 0)
   {
      ADDONADVMAX_vidCalibration_2();
   }
   if (IgSys_bAcvOfsAgIgMaxCal3 != 0)
   {
      ADDONADVMAX_vidCalibration_3();
   }
   if (IgSys_bAcvOfsAgIgMaxCal4 != 0)
   {
      ADDONADVMAX_vidCalibration_4();
   }
   if (IgSys_bAcvOfsAgIgMaxCal5 != 0)
   {
      ADDONADVMAX_vidCalibration_5();
   }
   if (IgSys_bAcvOfsAgIgMaxCal6 != 0)
   {
      ADDONADVMAX_vidCalibration_6();
   }
   if (IgSys_bAcvOfsAgIgMaxCal7 != 0)
   {
      ADDONADVMAX_vidCalibration_7();
   }
   if (IgSys_bAcvOfsAgIgMaxCal8 != 0)
   {
      ADDONADVMAX_vidCalibration_8();
   }
   if (IgSys_bAcvOfsAgIgMaxCal9 != 0)
   {
      ADDONADVMAX_vidCalibration_9();
   }
   if (IgSys_bAcvOfsAgIgMaxCal10 != 0)
   {
      ADDONADVMAX_vidCalibration_10();
   }
   if (IgSys_bAcvOfsAgIgMaxCal11 != 0)
   {
      ADDONADVMAX_vidCalibration_11();
   }
   if (IgSys_bAcvOfsAgIgMaxCal12 != 0)
   {
      ADDONADVMAX_vidCalibration_12();
   }
   if (IgSys_bAcvOfsAgIgMaxCal13 != 0)
   {
      ADDONADVMAX_vidCalibration_13();
   }
   if (IgSys_bAcvOfsAgIgMaxCal14 != 0)
   {
      ADDONADVMAX_vidCalibration_14();
   }

   ADDONADVMAX_vidVectorizeCalibs();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidUnvectrzActivBool                           */
/* !Description :  Ce bloc permet de démultiplexer le flux de sélection des   */
/*                 cartographies utiles.                                      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean IgSys_prm_bAcvOfsAgIgMaxCal[14];                            */
/*  output boolean IgSys_bAcvOfsAgIgMaxCal1;                                  */
/*  output boolean IgSys_bAcvOfsAgIgMaxCal2;                                  */
/*  output boolean IgSys_bAcvOfsAgIgMaxCal3;                                  */
/*  output boolean IgSys_bAcvOfsAgIgMaxCal4;                                  */
/*  output boolean IgSys_bAcvOfsAgIgMaxCal5;                                  */
/*  output boolean IgSys_bAcvOfsAgIgMaxCal6;                                  */
/*  output boolean IgSys_bAcvOfsAgIgMaxCal7;                                  */
/*  output boolean IgSys_bAcvOfsAgIgMaxCal8;                                  */
/*  output boolean IgSys_bAcvOfsAgIgMaxCal9;                                  */
/*  output boolean IgSys_bAcvOfsAgIgMaxCal10;                                 */
/*  output boolean IgSys_bAcvOfsAgIgMaxCal11;                                 */
/*  output boolean IgSys_bAcvOfsAgIgMaxCal12;                                 */
/*  output boolean IgSys_bAcvOfsAgIgMaxCal13;                                 */
/*  output boolean IgSys_bAcvOfsAgIgMaxCal14;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidUnvectrzActivBool(void)
{
   IgSys_bAcvOfsAgIgMaxCal1 = IgSys_prm_bAcvOfsAgIgMaxCal[0];
   IgSys_bAcvOfsAgIgMaxCal2 = IgSys_prm_bAcvOfsAgIgMaxCal[1];
   IgSys_bAcvOfsAgIgMaxCal3 = IgSys_prm_bAcvOfsAgIgMaxCal[2];
   IgSys_bAcvOfsAgIgMaxCal4 = IgSys_prm_bAcvOfsAgIgMaxCal[3];
   IgSys_bAcvOfsAgIgMaxCal5 = IgSys_prm_bAcvOfsAgIgMaxCal[4];
   IgSys_bAcvOfsAgIgMaxCal6 = IgSys_prm_bAcvOfsAgIgMaxCal[5];
   IgSys_bAcvOfsAgIgMaxCal7 = IgSys_prm_bAcvOfsAgIgMaxCal[6];
   IgSys_bAcvOfsAgIgMaxCal8 = IgSys_prm_bAcvOfsAgIgMaxCal[7];
   IgSys_bAcvOfsAgIgMaxCal9 = IgSys_prm_bAcvOfsAgIgMaxCal[8];
   IgSys_bAcvOfsAgIgMaxCal10 = IgSys_prm_bAcvOfsAgIgMaxCal[9];
   IgSys_bAcvOfsAgIgMaxCal11 = IgSys_prm_bAcvOfsAgIgMaxCal[10];
   IgSys_bAcvOfsAgIgMaxCal12 = IgSys_prm_bAcvOfsAgIgMaxCal[11];
   IgSys_bAcvOfsAgIgMaxCal13 = IgSys_prm_bAcvOfsAgIgMaxCal[12];
   IgSys_bAcvOfsAgIgMaxCal14 = IgSys_prm_bAcvOfsAgIgMaxCal[13];
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidCalibration_1                               */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMax_A[16];                                  */
/*  input uint16 IgSys_rAirLdOfsAgIgMax_A[16];                                */
/*  input uint8 IgSys_ofsAgIgMaxCal1_M[16][16];                               */
/*  output sint16 IgSys_ofsAgIgMaxCal1;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidCalibration_1(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   sint16 s16IgSys_ofsAgIgMaxCal;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgMax_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgMax_A,
                                                    u16LocalEngM_rAirLdCor,
                                                    16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMaxCal1_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);

   s16IgSys_ofsAgIgMaxCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMaxCal1 = s16IgSys_ofsAgIgMaxCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidCalibration_2                               */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMax_A[16];                                  */
/*  input uint16 IgSys_rAirLdOfsAgIgMax_A[16];                                */
/*  input uint8 IgSys_ofsAgIgMaxCal2_M[16][16];                               */
/*  output sint16 IgSys_ofsAgIgMaxCal2;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidCalibration_2(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   sint16 s16IgSys_ofsAgIgMaxCal;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgMax_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgMax_A,
                                                    u16LocalEngM_rAirLdCor,
                                                    16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMaxCal2_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);

   s16IgSys_ofsAgIgMaxCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMaxCal2 = s16IgSys_ofsAgIgMaxCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidCalibration_3                               */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMax_A[16];                                  */
/*  input uint16 IgSys_rAirLdOfsAgIgMax_A[16];                                */
/*  input uint8 IgSys_ofsAgIgMaxCal3_M[16][16];                               */
/*  output sint16 IgSys_ofsAgIgMaxCal3;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidCalibration_3(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   sint16 s16IgSys_ofsAgIgMaxCal;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgMax_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgMax_A,
                                                    u16LocalEngM_rAirLdCor,
                                                    16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMaxCal3_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);

   s16IgSys_ofsAgIgMaxCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMaxCal3 = s16IgSys_ofsAgIgMaxCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidCalibration_4                               */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMax_A[16];                                  */
/*  input uint16 IgSys_rAirLdOfsAgIgMax_A[16];                                */
/*  input uint8 IgSys_ofsAgIgMaxCal4_M[16][16];                               */
/*  output sint16 IgSys_ofsAgIgMaxCal4;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidCalibration_4(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   sint16 s16IgSys_ofsAgIgMaxCal;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgMax_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgMax_A,
                                                    u16LocalEngM_rAirLdCor,
                                                    16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMaxCal4_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);

   s16IgSys_ofsAgIgMaxCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMaxCal4 = s16IgSys_ofsAgIgMaxCal;
}
/*---------------------------------end of file--------------------------------*/