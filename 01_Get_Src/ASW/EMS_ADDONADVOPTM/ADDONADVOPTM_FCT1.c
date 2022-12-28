/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ADDONADVOPTM                                            */
/* !Description     : ADDONADVOPTM component                                  */
/*                                                                            */
/* !Module          : ADDONADVOPTM                                            */
/* !Description     : TRAITEMENT TRAME 34DH                                   */
/*                                                                            */
/* !File            : ADDONADVOPTM_FCT1.C                                     */
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
/*   1 / ADDONADVOPTM_vidInitOutput                                           */
/*   2 / ADDONADVOPTM_vidOffset_AAO                                           */
/*   3 / ADDONADVOPTM_vidUnvectorize_Mode                                     */
/*   4 / ADDONADVOPTM_vidMode_Mask                                            */
/*   5 / ADDONADVOPTM_vidCalibrations                                         */
/*   6 / ADDONADVOPTM_vidUnvectorActvBool                                     */
/*   7 / ADDONADVOPTM_vidCalibration_1                                        */
/*   8 / ADDONADVOPTM_vidCalibration_2                                        */
/*   9 / ADDONADVOPTM_vidCalibration_3                                        */
/*   10 / ADDONADVOPTM_vidCalibration_4                                       */
/*                                                                            */
/* !Reference   : V02 NT 11 01474 / 01                                        */
/* !OtherRefs   : 01460_10_04403_2 / 01                                       */
/* !OtherRefs   : VEMS V02 ECU#053829                                         */
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
#include "ADDONADVOPTM.h"
#include "ADDONADVOPTM_L.h"
#include "ADDONADVOPTM_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidInitOutput                                 */
/* !Description :  Fonction pour initialiser les sorties                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 IgSys_agIgCmbModOfs;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidInitOutput(void)
{
   VEMS_vidSET(IgSys_agIgCmbModOfs, 96);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidOffset_AAO                                 */
/* !Description :  La fonction est constituée de 5 sous fonctions  permettant */
/*                 de calculer l’offset d’avance optimale                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ADDONADVOPTM_vidUnvectorize_Mode();                      */
/*  extf argret void ADDONADVOPTM_vidMode_Mask();                             */
/*  extf argret void ADDONADVOPTM_vidCalibrations();                          */
/*  extf argret void ADDONADVOPTM_vidSelect_Modes();                          */
/*  extf argret void ADDONADVOPTM_vidInterpolation();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidOffset_AAO(void)
{
   ADDONADVOPTM_vidUnvectorize_Mode();
   ADDONADVOPTM_vidMode_Mask();
   ADDONADVOPTM_vidCalibrations();
   ADDONADVOPTM_vidSelect_Modes();
   ADDONADVOPTM_vidInterpolation();

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidUnvectorize_Mode                           */
/* !Description :  Cette fonction  bloc permet de sélectionner les            */
/*                 informations provenant du gestionnaire de modes de         */
/*                 fonctionnements                                            */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_003.01                                     */
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
/*  output uint8 IgSys_idxOfsAgIgOpBas1ModCur;                                */
/*  output uint8 IgSys_idxOfsAgIgOpBas2ModCur;                                */
/*  output uint8 IgSys_idxOfsAgIgOpBas1ModTar;                                */
/*  output uint8 IgSys_idxOfsAgIgOpBas2ModTar;                                */
/*  output uint8 IgSys_facOfsAgIgOpBasModCur;                                 */
/*  output uint8 IgSys_facOfsAgIgOpBasModTar;                                 */
/*  output uint8 IgSys_facOfsAgIgOpTranMod;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidUnvectorize_Mode(void)
{
   uint8  u8LocalIdxOfsAgIgOpBas1ModCur;
   uint8  u8LocalIdxOfsAgIgOpBas2ModCur;
   uint8  u8LocalIdxOfsAgIgOpBas1ModTar;
   uint8  u8LocalIdxOfsAgIgOpBas2ModTar;
   uint8  u8LocalfacOfsAgIgOpBasModCur;
   uint8  u8LocalfacOfsAgIgOpBasModTar;
   uint8  u8LocalfacOfsAgIgOpTranMod;


   VEMS_vidGET1DArrayElement(EOM_prm_idxBas1ModCur,
                             8,
                             u8LocalIdxOfsAgIgOpBas1ModCur);
   IgSys_idxOfsAgIgOpBas1ModCur =
      (uint8)MATHSRV_udtCLAMP(u8LocalIdxOfsAgIgOpBas1ModCur, 1, 17);

   VEMS_vidGET1DArrayElement(EOM_prm_idxBas2ModCur,
                             8,
                             u8LocalIdxOfsAgIgOpBas2ModCur);
   IgSys_idxOfsAgIgOpBas2ModCur =
      (uint8)MATHSRV_udtCLAMP(u8LocalIdxOfsAgIgOpBas2ModCur, 1, 17);

   VEMS_vidGET1DArrayElement(EOM_prm_idxBas1ModTar,
                             8,
                             u8LocalIdxOfsAgIgOpBas1ModTar);
   IgSys_idxOfsAgIgOpBas1ModTar =
      (uint8)MATHSRV_udtCLAMP(u8LocalIdxOfsAgIgOpBas1ModTar, 1, 17);

   VEMS_vidGET1DArrayElement(EOM_prm_idxBas2ModTar,
                             8,
                             u8LocalIdxOfsAgIgOpBas2ModTar);
   IgSys_idxOfsAgIgOpBas2ModTar =
      (uint8)MATHSRV_udtCLAMP(u8LocalIdxOfsAgIgOpBas2ModTar, 1, 17);

   VEMS_vidGET1DArrayElement(EOM_prm_facBasModCur,
                             8,
                             u8LocalfacOfsAgIgOpBasModCur);
   u8LocalfacOfsAgIgOpBasModCur =
      (uint8)((u8LocalfacOfsAgIgOpBasModCur * 25) / 32);
   IgSys_facOfsAgIgOpBasModCur =
      (uint8)MATHSRV_udtMIN(u8LocalfacOfsAgIgOpBasModCur, 100);

   VEMS_vidGET1DArrayElement(EOM_prm_facBasModTar,
                             8,
                             u8LocalfacOfsAgIgOpBasModTar);
   u8LocalfacOfsAgIgOpBasModTar =
      (uint8)((u8LocalfacOfsAgIgOpBasModTar * 25) / 32);
   IgSys_facOfsAgIgOpBasModTar =
      (uint8)MATHSRV_udtMIN(u8LocalfacOfsAgIgOpBasModTar, 100);

   VEMS_vidGET1DArrayElement(EOM_prm_facTranMod, 8, u8LocalfacOfsAgIgOpTranMod);
   u8LocalfacOfsAgIgOpTranMod = (uint8)((u8LocalfacOfsAgIgOpTranMod * 25) / 32);
   IgSys_facOfsAgIgOpTranMod =
      (uint8)MATHSRV_udtMIN(u8LocalfacOfsAgIgOpTranMod, 100);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidMode_Mask                                  */
/* !Description :  Cette  fonction  permet de sélectionner le numéro des      */
/*                 cartographies utiles                                       */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 IgSys_idxOfsAgIgOpBas1ModCur;                                 */
/*  input uint8 IgSys_idxOfsAgIgOpBas2ModCur;                                 */
/*  input uint8 IgSys_idxOfsAgIgOpBas1ModTar;                                 */
/*  input uint8 IgSys_idxOfsAgIgOpBas2ModTar;                                 */
/*  output boolean IgSys_prm_bAcvOfsAgIgOptmCal[17];                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidMode_Mask(void)
{
   boolean bLocalTempTab[IGSYS_PRM_BACVOFSAGIGOPTMCAL_COLS];
   uint8   u8LocalTempComp;
   uint8   u8LocalIdxOfsAgIgOpBas1ModCur;
   uint8   u8LocalIdxOfsAgIgOpBas2ModCur;
   uint8   u8LocalIdxOfsAgIgOpBas1ModTar;
   uint8   u8LocalIdxOfsAgIgOpBas2ModTar;
   sint16  s16LocalIdxOfsAgIgOpBas1ModCur;
   sint16  s16LocalIdxOfsAgIgOpBas2ModCur;
   sint16  s16LocalIdxOfsAgIgOpBas2ModTar;
   sint16  s16LocalIdxOfsAgIgOpBas1ModTar;


   for (u8LocalTempComp = 0; u8LocalTempComp < 17; u8LocalTempComp++)
   {
      bLocalTempTab[u8LocalTempComp] = 0;
   }

   s16LocalIdxOfsAgIgOpBas1ModCur = (sint16)(IgSys_idxOfsAgIgOpBas1ModCur - 1);
   u8LocalIdxOfsAgIgOpBas1ModCur =
      (uint8)MATHSRV_udtCLAMP(s16LocalIdxOfsAgIgOpBas1ModCur, 0, 16);

   s16LocalIdxOfsAgIgOpBas2ModCur = (sint16)(IgSys_idxOfsAgIgOpBas2ModCur - 1);
   u8LocalIdxOfsAgIgOpBas2ModCur =
      (uint8)MATHSRV_udtCLAMP(s16LocalIdxOfsAgIgOpBas2ModCur, 0, 16);

   s16LocalIdxOfsAgIgOpBas1ModTar = (sint16)(IgSys_idxOfsAgIgOpBas1ModTar - 1);
   u8LocalIdxOfsAgIgOpBas1ModTar =
      (uint8)MATHSRV_udtCLAMP(s16LocalIdxOfsAgIgOpBas1ModTar, 0, 16);

   s16LocalIdxOfsAgIgOpBas2ModTar = (sint16)(IgSys_idxOfsAgIgOpBas2ModTar - 1);
   u8LocalIdxOfsAgIgOpBas2ModTar =
      (uint8)MATHSRV_udtCLAMP(s16LocalIdxOfsAgIgOpBas2ModTar, 0, 16);


   bLocalTempTab[u8LocalIdxOfsAgIgOpBas1ModCur] = 1;
   bLocalTempTab[u8LocalIdxOfsAgIgOpBas2ModCur] = 1;
   bLocalTempTab[u8LocalIdxOfsAgIgOpBas1ModTar] = 1;
   bLocalTempTab[u8LocalIdxOfsAgIgOpBas2ModTar] = 1;

   for (u8LocalTempComp = 0; u8LocalTempComp < 17; u8LocalTempComp++)
   {
      IgSys_prm_bAcvOfsAgIgOptmCal[u8LocalTempComp]=
         bLocalTempTab[u8LocalTempComp];
   }

}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidCalibrations                               */
/* !Description :  Cette  fonction  regroupe les différentes calibrations de  */
/*                 la fonction                                                */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ADDONADVOPTM_vidUnvectorActvBool();                      */
/*  extf argret void ADDONADVOPTM_vidCalibration_1();                         */
/*  extf argret void ADDONADVOPTM_vidCalibration_2();                         */
/*  extf argret void ADDONADVOPTM_vidCalibration_3();                         */
/*  extf argret void ADDONADVOPTM_vidCalibration_4();                         */
/*  extf argret void ADDONADVOPTM_vidCalibration_5();                         */
/*  extf argret void ADDONADVOPTM_vidCalibration_6();                         */
/*  extf argret void ADDONADVOPTM_vidCalibration_7();                         */
/*  extf argret void ADDONADVOPTM_vidCalibration_8();                         */
/*  extf argret void ADDONADVOPTM_vidCalibration_9();                         */
/*  extf argret void ADDONADVOPTM_vidCalibration_10();                        */
/*  extf argret void ADDONADVOPTM_vidCalibration_11();                        */
/*  extf argret void ADDONADVOPTM_vidCalibration_12();                        */
/*  extf argret void ADDONADVOPTM_vidCalibration_13();                        */
/*  extf argret void ADDONADVOPTM_vidCalibration_14();                        */
/*  extf argret void ADDONADVOPTM_vidCalibration_15();                        */
/*  extf argret void ADDONADVOPTM_vidCalibration_16();                        */
/*  extf argret void ADDONADVOPTM_vidCalibration_17();                        */
/*  extf argret void ADDONADVOPTM_vidVectorize_Calib();                       */
/*  input boolean IgSys_bAcvOfsAgIgOptmCal1;                                  */
/*  input boolean IgSys_bAcvOfsAgIgOptmCal2;                                  */
/*  input boolean IgSys_bAcvOfsAgIgOptmCal3;                                  */
/*  input boolean IgSys_bAcvOfsAgIgOptmCal4;                                  */
/*  input boolean IgSys_bAcvOfsAgIgOptmCal5;                                  */
/*  input boolean IgSys_bAcvOfsAgIgOptmCal6;                                  */
/*  input boolean IgSys_bAcvOfsAgIgOptmCal7;                                  */
/*  input boolean IgSys_bAcvOfsAgIgOptmCal8;                                  */
/*  input boolean IgSys_bAcvOfsAgIgOptmCal9;                                  */
/*  input boolean IgSys_bAcvOfsAgIgOptmCal10;                                 */
/*  input boolean IgSys_bAcvOfsAgIgOptmCal11;                                 */
/*  input boolean IgSys_bAcvOfsAgIgOptmCal12;                                 */
/*  input boolean IgSys_bAcvOfsAgIgOptmCal13;                                 */
/*  input boolean IgSys_bAcvOfsAgIgOptmCal14;                                 */
/*  input boolean IgSys_bAcvOfsAgIgOptmCal15;                                 */
/*  input boolean IgSys_bAcvOfsAgIgOptmCal16;                                 */
/*  input boolean IgSys_bAcvOfsAgIgOptmCal17;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidCalibrations(void)
{

   ADDONADVOPTM_vidUnvectorActvBool();

   if (IgSys_bAcvOfsAgIgOptmCal1 != 0)
   {
      ADDONADVOPTM_vidCalibration_1();
   }

   if (IgSys_bAcvOfsAgIgOptmCal2 != 0)
   {
      ADDONADVOPTM_vidCalibration_2();
   }

   if (IgSys_bAcvOfsAgIgOptmCal3 != 0)
   {
      ADDONADVOPTM_vidCalibration_3();
   }

   if (IgSys_bAcvOfsAgIgOptmCal4 != 0)
   {
      ADDONADVOPTM_vidCalibration_4();
   }

   if (IgSys_bAcvOfsAgIgOptmCal5 != 0)
   {
      ADDONADVOPTM_vidCalibration_5();
   }

   if (IgSys_bAcvOfsAgIgOptmCal6 != 0)
   {
      ADDONADVOPTM_vidCalibration_6();
   }

   if (IgSys_bAcvOfsAgIgOptmCal7 != 0)
   {
      ADDONADVOPTM_vidCalibration_7();
   }

   if (IgSys_bAcvOfsAgIgOptmCal8 != 0)
   {
      ADDONADVOPTM_vidCalibration_8();
   }

   if (IgSys_bAcvOfsAgIgOptmCal9 != 0)
   {
      ADDONADVOPTM_vidCalibration_9();
   }

   if (IgSys_bAcvOfsAgIgOptmCal10 != 0)
   {
      ADDONADVOPTM_vidCalibration_10();
   }

   if (IgSys_bAcvOfsAgIgOptmCal11 != 0)
   {
      ADDONADVOPTM_vidCalibration_11();
   }

   if (IgSys_bAcvOfsAgIgOptmCal12 != 0)
   {
      ADDONADVOPTM_vidCalibration_12();
   }
   if (IgSys_bAcvOfsAgIgOptmCal13 != 0)
   {
      ADDONADVOPTM_vidCalibration_13();
   }

   if (IgSys_bAcvOfsAgIgOptmCal14 != 0)
   {
      ADDONADVOPTM_vidCalibration_14();
   }

   if (IgSys_bAcvOfsAgIgOptmCal15 != 0)
   {
      ADDONADVOPTM_vidCalibration_15();
   }

   if (IgSys_bAcvOfsAgIgOptmCal16 != 0)
   {
      ADDONADVOPTM_vidCalibration_16();
   }

   if (IgSys_bAcvOfsAgIgOptmCal17 != 0)
   {
      ADDONADVOPTM_vidCalibration_17();
   }

   ADDONADVOPTM_vidVectorize_Calib();

}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidUnvectorActvBool                           */
/* !Description :  Cette fonction permet de démultiplexeur le flux de         */
/*                 sélection des cartographies utiles                         */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean IgSys_prm_bAcvOfsAgIgOptmCal[17];                           */
/*  output boolean IgSys_bAcvOfsAgIgOptmCal1;                                 */
/*  output boolean IgSys_bAcvOfsAgIgOptmCal2;                                 */
/*  output boolean IgSys_bAcvOfsAgIgOptmCal3;                                 */
/*  output boolean IgSys_bAcvOfsAgIgOptmCal4;                                 */
/*  output boolean IgSys_bAcvOfsAgIgOptmCal5;                                 */
/*  output boolean IgSys_bAcvOfsAgIgOptmCal6;                                 */
/*  output boolean IgSys_bAcvOfsAgIgOptmCal7;                                 */
/*  output boolean IgSys_bAcvOfsAgIgOptmCal8;                                 */
/*  output boolean IgSys_bAcvOfsAgIgOptmCal9;                                 */
/*  output boolean IgSys_bAcvOfsAgIgOptmCal10;                                */
/*  output boolean IgSys_bAcvOfsAgIgOptmCal11;                                */
/*  output boolean IgSys_bAcvOfsAgIgOptmCal12;                                */
/*  output boolean IgSys_bAcvOfsAgIgOptmCal13;                                */
/*  output boolean IgSys_bAcvOfsAgIgOptmCal14;                                */
/*  output boolean IgSys_bAcvOfsAgIgOptmCal15;                                */
/*  output boolean IgSys_bAcvOfsAgIgOptmCal16;                                */
/*  output boolean IgSys_bAcvOfsAgIgOptmCal17;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidUnvectorActvBool(void)
{

   IgSys_bAcvOfsAgIgOptmCal1 = IgSys_prm_bAcvOfsAgIgOptmCal[0];
   IgSys_bAcvOfsAgIgOptmCal2 = IgSys_prm_bAcvOfsAgIgOptmCal[1];
   IgSys_bAcvOfsAgIgOptmCal3 = IgSys_prm_bAcvOfsAgIgOptmCal[2];
   IgSys_bAcvOfsAgIgOptmCal4 = IgSys_prm_bAcvOfsAgIgOptmCal[3];
   IgSys_bAcvOfsAgIgOptmCal5 = IgSys_prm_bAcvOfsAgIgOptmCal[4];
   IgSys_bAcvOfsAgIgOptmCal6 = IgSys_prm_bAcvOfsAgIgOptmCal[5];
   IgSys_bAcvOfsAgIgOptmCal7 = IgSys_prm_bAcvOfsAgIgOptmCal[6];
   IgSys_bAcvOfsAgIgOptmCal8 = IgSys_prm_bAcvOfsAgIgOptmCal[7];
   IgSys_bAcvOfsAgIgOptmCal9 = IgSys_prm_bAcvOfsAgIgOptmCal[8];
   IgSys_bAcvOfsAgIgOptmCal10 = IgSys_prm_bAcvOfsAgIgOptmCal[9];
   IgSys_bAcvOfsAgIgOptmCal11 = IgSys_prm_bAcvOfsAgIgOptmCal[10];
   IgSys_bAcvOfsAgIgOptmCal12 = IgSys_prm_bAcvOfsAgIgOptmCal[11];
   IgSys_bAcvOfsAgIgOptmCal13 = IgSys_prm_bAcvOfsAgIgOptmCal[12];
   IgSys_bAcvOfsAgIgOptmCal14 = IgSys_prm_bAcvOfsAgIgOptmCal[13];
   IgSys_bAcvOfsAgIgOptmCal15 = IgSys_prm_bAcvOfsAgIgOptmCal[14];
   IgSys_bAcvOfsAgIgOptmCal16 = IgSys_prm_bAcvOfsAgIgOptmCal[15];
   IgSys_bAcvOfsAgIgOptmCal17 = IgSys_prm_bAcvOfsAgIgOptmCal[16];

}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidCalibration_1                              */
/* !Description :  Cette fonction  contient une des cartographies de la       */
/*                 fonction. Il n’est calculé que lorsque le mode de          */
/*                 fonctionnement  courant ou celui de consigne nécessite une */
/*                 interpolation dans cette cartographie                      */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgOptm_A[16];                                 */
/*  input uint16 IgSys_rAirLdOfsAgIgOptm_A[16];                               */
/*  input uint8 IgSys_ofsAgIgOptmCal1_M[16][16];                              */
/*  output sint16 IgSys_ofsAgIgOptmCal1;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidCalibration_1(void)
{
   uint8   u8LocalInterp2;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalEngM_rAirLdCor;
   uint16  u16LocalParaY;
   uint16  u16LocalParaX;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);


   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgOptm_A,
                                                u16LocalExt_nEng,
                                                16);


   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgOptm_A,
                                               u16LocalEngM_rAirLdCor,
                                               16);

   u8LocalInterp2 = MATHSRV_u8Interp2d(&IgSys_ofsAgIgOptmCal1_M[0][0],
                                       u16LocalParaX,
                                       u16LocalParaY,
                                       16);

   IgSys_ofsAgIgOptmCal1 = (sint16)(u8LocalInterp2 - 96);
}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidCalibration_2                              */
/* !Description :  Cette fonction  contient une des cartographies de la       */
/*                 fonction. Il n’est calculé que lorsque le mode de          */
/*                 fonctionnement  courant ou celui de consigne nécessite une */
/*                 interpolation dans cette cartographie                      */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgOptm_A[16];                                 */
/*  input uint16 IgSys_rAirLdOfsAgIgOptm_A[16];                               */
/*  input uint8 IgSys_ofsAgIgOptmCal2_M[16][16];                              */
/*  output sint16 IgSys_ofsAgIgOptmCal2;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidCalibration_2(void)
{
   uint8   u8LocalInterp2;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalEngM_rAirLdCor;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);


   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgOptm_A,
                                                u16LocalExt_nEng,
                                                16);


   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgOptm_A,
                                               u16LocalEngM_rAirLdCor,
                                               16);

   u8LocalInterp2 = MATHSRV_u8Interp2d(&IgSys_ofsAgIgOptmCal2_M[0][0],
                                       u16LocalParaX,
                                       u16LocalParaY,
                                       16);

   IgSys_ofsAgIgOptmCal2 = (sint16)(u8LocalInterp2 - 96);
}




/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidCalibration_3                              */
/* !Description :  Cette fonction contient une des cartographies de la        */
/*                 fonction. Il n’est calculé que lorsque le mode de          */
/*                 fonctionnement  courant ou celui de consigne nécessite une */
/*                 interpolation dans cette cartographie                      */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgOptm_A[16];                                 */
/*  input uint16 IgSys_rAirLdOfsAgIgOptm_A[16];                               */
/*  input uint8 IgSys_ofsAgIgOptmCal3_M[16][16];                              */
/*  output sint16 IgSys_ofsAgIgOptmCal3;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidCalibration_3(void)
{
   uint8   u8LocalInterp2;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalEngM_rAirLdCor;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;

   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);


   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgOptm_A,
                                                u16LocalExt_nEng,
                                                16);

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgOptm_A,
                                               u16LocalEngM_rAirLdCor,
                                               16);

   u8LocalInterp2 = MATHSRV_u8Interp2d(&IgSys_ofsAgIgOptmCal3_M[0][0],
                                       u16LocalParaX,
                                       u16LocalParaY,
                                       16);

   IgSys_ofsAgIgOptmCal3 = (sint16)(u8LocalInterp2 - 96);
}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidCalibration_4                              */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement        */
/*                 courant ou celui de consigne nécessite une interpolation   */
/*                 dans cette cartographie                                    */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgOptm_A[16];                                 */
/*  input uint16 IgSys_rAirLdOfsAgIgOptm_A[16];                               */
/*  input uint8 IgSys_ofsAgIgOptmCal4_M[16][16];                              */
/*  output sint16 IgSys_ofsAgIgOptmCal4;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidCalibration_4(void)
{
   uint8  u8LocalInterp2;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);


   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgOptm_A,
                                                u16LocalExt_nEng,
                                                16);


   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgOptm_A,
                                               u16LocalEngM_rAirLdCor,
                                               16);

   u8LocalInterp2 = MATHSRV_u8Interp2d(&IgSys_ofsAgIgOptmCal4_M[0][0],
                                       u16LocalParaX,
                                       u16LocalParaY,
                                       16);

   IgSys_ofsAgIgOptmCal4 = (sint16)(u8LocalInterp2 - 96);
}


/*------------------------------end of file-----------------------------------*/