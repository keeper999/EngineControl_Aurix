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
/* !File            : AIRTQEFF_FCT3.C                                         */
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
/*   1 / AIRTQEFF_vidUnvectorz_Activ_Bool                                     */
/*   2 / AIRTQEFF_vidCalibration_1                                            */
/*   3 / AIRTQEFF_vidCalibration_2                                            */
/*   4 / AIRTQEFF_vidCalibration_3                                            */
/*   5 / AIRTQEFF_vidCalibration_4                                            */
/*   6 / AIRTQEFF_vidCalibration_5                                            */
/*   7 / AIRTQEFF_vidCalibration_6                                            */
/*   8 / AIRTQEFF_vidCalibration_7                                            */
/*   9 / AIRTQEFF_vidCalibration_8                                            */
/*   10 / AIRTQEFF_vidCalibration_9                                           */
/*                                                                            */
/* !Reference   : V02 NT 10 07791 / 02                                        */
/* !OtherRefs   : CSMT_CGMT09_0475_2 / 1.1                                    */
/* !OtherRefs   : VEMS V02 ECU#051747                                         */
/* !OtherRefs   : VEMS V02 ECU#058235                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/AIR/AIRTQEFF/AIRTQEFF_FCT3$*/
/* $Revision::   1.3.1.1  $$Author::   mbenfrad       $$Date::   05 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   05 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "AIRTQEFF.h"
#include "AIRTQEFF_L.h"
#include "AIRTQEFF_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidUnvectorz_Activ_Bool                           */
/* !Description :  Ce bloc permet de démultiplexer le flux de sélection des   */
/*                 cartographies utiles                                       */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean AirSys_prm_bAcvEffCycCal[14];                               */
/*  output boolean AirSys_bAcvCycCal1;                                        */
/*  output boolean AirSys_bAcvCycCal2;                                        */
/*  output boolean AirSys_bAcvCycCal3;                                        */
/*  output boolean AirSys_bAcvCycCal4;                                        */
/*  output boolean AirSys_bAcvCycCal5;                                        */
/*  output boolean AirSys_bAcvCycCal6;                                        */
/*  output boolean AirSys_bAcvCycCal7;                                        */
/*  output boolean AirSys_bAcvCycCal8;                                        */
/*  output boolean AirSys_bAcvCycCal9;                                        */
/*  output boolean AirSys_bAcvCycCal10;                                       */
/*  output boolean AirSys_bAcvCycCal11;                                       */
/*  output boolean AirSys_bAcvCycCal12;                                       */
/*  output boolean AirSys_bAcvCycCal13;                                       */
/*  output boolean AirSys_bAcvCycCal14;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidUnvectorz_Activ_Bool(void)
{
   AirSys_bAcvCycCal1 = AirSys_prm_bAcvEffCycCal[0];
   AirSys_bAcvCycCal2 = AirSys_prm_bAcvEffCycCal[1];
   AirSys_bAcvCycCal3 = AirSys_prm_bAcvEffCycCal[2];
   AirSys_bAcvCycCal4 = AirSys_prm_bAcvEffCycCal[3];
   AirSys_bAcvCycCal5 = AirSys_prm_bAcvEffCycCal[4];
   AirSys_bAcvCycCal6 = AirSys_prm_bAcvEffCycCal[5];
   AirSys_bAcvCycCal7 = AirSys_prm_bAcvEffCycCal[6];
   AirSys_bAcvCycCal8 = AirSys_prm_bAcvEffCycCal[7];
   AirSys_bAcvCycCal9 = AirSys_prm_bAcvEffCycCal[8];
   AirSys_bAcvCycCal10 = AirSys_prm_bAcvEffCycCal[9];
   AirSys_bAcvCycCal11 = AirSys_prm_bAcvEffCycCal[10];
   AirSys_bAcvCycCal12 = AirSys_prm_bAcvEffCycCal[11];
   AirSys_bAcvCycCal13 = AirSys_prm_bAcvEffCycCal[12];
   AirSys_bAcvCycCal14 = AirSys_prm_bAcvEffCycCal[13];
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCalibration_1                                  */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AirSys_nEngEffCyc_A[16];                                     */
/*  input uint16 AirSys_rAirLdEffCyc_A[8];                                    */
/*  input uint16 AirSys_tqIdcHPCal1_M[16][8];                                 */
/*  output uint16 AirSys_tqIdcHPCal1;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalibration_1(void)
{
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalInterp2d;


   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(AirSys_nEngEffCyc_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(AirSys_rAirLdEffCyc_A,
                                                    u16LocalEngM_rAirLdCor,
                                                    8);
   u16LocalInterp2d = MATHSRV_u16Interp2d(&AirSys_tqIdcHPCal1_M[0][0],
                                          u16LocalCalcParaX,
                                          u16LocalCalcParaY,
                                          8);
   AirSys_tqIdcHPCal1 = (uint16)MATHSRV_udtMIN(u16LocalInterp2d, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCalibration_2                                  */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AirSys_nEngEffCyc_A[16];                                     */
/*  input uint16 AirSys_rAirLdEffCyc_A[8];                                    */
/*  input uint16 AirSys_tqIdcHPCal2_M[16][8];                                 */
/*  output uint16 AirSys_tqIdcHPCal2;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalibration_2(void)
{
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalInterp2d;


   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(AirSys_nEngEffCyc_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(AirSys_rAirLdEffCyc_A,
                                                    u16LocalEngM_rAirLdCor,
                                                    8);
   u16LocalInterp2d = MATHSRV_u16Interp2d(&AirSys_tqIdcHPCal2_M[0][0],
                                          u16LocalCalcParaX,
                                          u16LocalCalcParaY,
                                          8);
   AirSys_tqIdcHPCal2 = (uint16)MATHSRV_udtMIN(u16LocalInterp2d, 32000);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCalibration_3                                  */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AirSys_nEngEffCyc_A[16];                                     */
/*  input uint16 AirSys_rAirLdEffCyc_A[8];                                    */
/*  input uint16 AirSys_tqIdcHPCal3_M[16][8];                                 */
/*  output uint16 AirSys_tqIdcHPCal3;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalibration_3(void)
{
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalInterp2d;


   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(AirSys_nEngEffCyc_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(AirSys_rAirLdEffCyc_A,
                                                    u16LocalEngM_rAirLdCor,
                                                    8);
   u16LocalInterp2d = MATHSRV_u16Interp2d(&AirSys_tqIdcHPCal3_M[0][0],
                                          u16LocalCalcParaX,
                                          u16LocalCalcParaY,
                                          8);
   AirSys_tqIdcHPCal3 = (uint16)MATHSRV_udtMIN(u16LocalInterp2d, 32000);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCalibration_4                                  */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AirSys_nEngEffCyc_A[16];                                     */
/*  input uint16 AirSys_rAirLdEffCyc_A[8];                                    */
/*  input uint16 AirSys_tqIdcHPCal4_M[16][8];                                 */
/*  output uint16 AirSys_tqIdcHPCal4;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalibration_4(void)
{
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalInterp2d;


   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(AirSys_nEngEffCyc_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(AirSys_rAirLdEffCyc_A,
                                                    u16LocalEngM_rAirLdCor,
                                                    8);
   u16LocalInterp2d = MATHSRV_u16Interp2d(&AirSys_tqIdcHPCal4_M[0][0],
                                          u16LocalCalcParaX,
                                          u16LocalCalcParaY,
                                          8);
   AirSys_tqIdcHPCal4 = (uint16)MATHSRV_udtMIN(u16LocalInterp2d, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCalibration_5                                  */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AirSys_nEngEffCyc_A[16];                                     */
/*  input uint16 AirSys_rAirLdEffCyc_A[8];                                    */
/*  input uint16 AirSys_tqIdcHPCal5_M[16][8];                                 */
/*  output uint16 AirSys_tqIdcHPCal5;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalibration_5(void)
{
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalInterp2d;


   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(AirSys_nEngEffCyc_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(AirSys_rAirLdEffCyc_A,
                                                    u16LocalEngM_rAirLdCor,
                                                    8);
   u16LocalInterp2d = MATHSRV_u16Interp2d(&AirSys_tqIdcHPCal5_M[0][0],
                                          u16LocalCalcParaX,
                                          u16LocalCalcParaY,
                                          8);
   AirSys_tqIdcHPCal5 = (uint16)MATHSRV_udtMIN(u16LocalInterp2d, 32000);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCalibration_6                                  */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AirSys_nEngEffCyc_A[16];                                     */
/*  input uint16 AirSys_rAirLdEffCyc_A[8];                                    */
/*  input uint16 AirSys_tqIdcHPCal6_M[16][8];                                 */
/*  output uint16 AirSys_tqIdcHPCal6;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalibration_6(void)
{
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalInterp2d;


   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(AirSys_nEngEffCyc_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(AirSys_rAirLdEffCyc_A,
                                                    u16LocalEngM_rAirLdCor,
                                                    8);
   u16LocalInterp2d = MATHSRV_u16Interp2d(&AirSys_tqIdcHPCal6_M[0][0],
                                          u16LocalCalcParaX,
                                          u16LocalCalcParaY,
                                          8);
   AirSys_tqIdcHPCal6 = (uint16)MATHSRV_udtMIN(u16LocalInterp2d, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCalibration_7                                  */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_019.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AirSys_nEngEffCyc_A[16];                                     */
/*  input uint16 AirSys_rAirLdEffCyc_A[8];                                    */
/*  input uint16 AirSys_tqIdcHPCal7_M[16][8];                                 */
/*  output uint16 AirSys_tqIdcHPCal7;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalibration_7(void)
{
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalInterp2d;


   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(AirSys_nEngEffCyc_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(AirSys_rAirLdEffCyc_A,
                                                    u16LocalEngM_rAirLdCor,
                                                    8);
   u16LocalInterp2d = MATHSRV_u16Interp2d(&AirSys_tqIdcHPCal7_M[0][0],
                                          u16LocalCalcParaX,
                                          u16LocalCalcParaY,
                                          8);
   AirSys_tqIdcHPCal7 = (uint16)MATHSRV_udtMIN(u16LocalInterp2d, 32000);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCalibration_8                                  */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AirSys_nEngEffCyc_A[16];                                     */
/*  input uint16 AirSys_rAirLdEffCyc_A[8];                                    */
/*  input uint16 AirSys_tqIdcHPCal8_M[16][8];                                 */
/*  output uint16 AirSys_tqIdcHPCal8;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalibration_8(void)
{
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalInterp2d;


   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(AirSys_nEngEffCyc_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(AirSys_rAirLdEffCyc_A,
                                                    u16LocalEngM_rAirLdCor,
                                                    8);
   u16LocalInterp2d = MATHSRV_u16Interp2d(&AirSys_tqIdcHPCal8_M[0][0],
                                          u16LocalCalcParaX,
                                          u16LocalCalcParaY,
                                          8);
   AirSys_tqIdcHPCal8 = (uint16)MATHSRV_udtMIN(u16LocalInterp2d, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCalibration_9                                  */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT3.10                                                    */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AirSys_nEngEffCycShoIdl_A[8];                                */
/*  input uint16 AirSys_rAirLdEffCyc_A[8];                                    */
/*  input uint16 AirSys_tqIdcHPCal9_M[8][8];                                  */
/*  output uint16 AirSys_tqIdcHPCal9;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalibration_9(void)
{
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalInterp2d;


   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(AirSys_nEngEffCycShoIdl_A,
                                                    u16LocalExt_nEng,
                                                    8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(AirSys_rAirLdEffCyc_A,
                                                    u16LocalEngM_rAirLdCor,
                                                    8);
   u16LocalInterp2d = MATHSRV_u16Interp2d(&AirSys_tqIdcHPCal9_M[0][0],
                                          u16LocalCalcParaX,
                                          u16LocalCalcParaY,
                                          8);
   AirSys_tqIdcHPCal9 = (uint16)MATHSRV_udtMIN(u16LocalInterp2d, 32000);
}
/*---------------------------------end of file--------------------------------*/