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
/* !File            : AIRTQEFF_FCT4.C                                         */
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
/*   1 / AIRTQEFF_vidCalibration_10                                           */
/*   2 / AIRTQEFF_vidCalibration_11                                           */
/*   3 / AIRTQEFF_vidCalibration_12                                           */
/*   4 / AIRTQEFF_vidCalibration_13                                           */
/*   5 / AIRTQEFF_vidCalibration_14                                           */
/*   6 / AIRTQEFF_vidVectorz_Calibrations                                     */
/*                                                                            */
/* !Reference   : V02 NT 10 07791 / 02                                        */
/* !OtherRefs   : CSMT_CGMT09_0475_2 / 1.1                                    */
/* !OtherRefs   : VEMS V02 ECU#051747                                         */
/* !OtherRefs   : VEMS V02 ECU#058235                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/AIR/AIRTQEFF/AIRTQEFF_FCT4$*/
/* $Revision::   1.4.1.1  $$Author::   mbenfrad       $$Date::   05 Jun 2013 $*/
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
/* !Function    :  AIRTQEFF_vidCalibration_10                                 */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AirSys_nEngEffCycShoIdl_A[8];                                */
/*  input uint16 AirSys_rAirLdEffCyc_A[8];                                    */
/*  input uint16 AirSys_tqIdcHPCal10_M[8][8];                                 */
/*  output uint16 AirSys_tqIdcHPCal10;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalibration_10(void)
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
   u16LocalInterp2d = MATHSRV_u16Interp2d(&AirSys_tqIdcHPCal10_M[0][0],
                                          u16LocalCalcParaX,
                                          u16LocalCalcParaY,
                                          8);
   AirSys_tqIdcHPCal10 = (uint16)MATHSRV_udtMIN(u16LocalInterp2d, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCalibration_11                                 */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AirSys_nEngEffCycShoIdl_A[8];                                */
/*  input uint16 AirSys_rAirLdEffCyc_A[8];                                    */
/*  input uint16 AirSys_tqIdcHPCal11_M[8][8];                                 */
/*  output uint16 AirSys_tqIdcHPCal11;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalibration_11(void)
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
   u16LocalInterp2d = MATHSRV_u16Interp2d(&AirSys_tqIdcHPCal11_M[0][0],
                                          u16LocalCalcParaX,
                                          u16LocalCalcParaY,
                                          8);
   AirSys_tqIdcHPCal11 = (uint16)MATHSRV_udtMIN(u16LocalInterp2d, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCalibration_12                                 */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_024.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AirSys_nEngEffCycShoIdl_A[8];                                */
/*  input uint16 AirSys_rAirLdEffCyc_A[8];                                    */
/*  input uint16 AirSys_tqIdcHPCal12_M[8][8];                                 */
/*  output uint16 AirSys_tqIdcHPCal12;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalibration_12(void)
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
   u16LocalInterp2d = MATHSRV_u16Interp2d(&AirSys_tqIdcHPCal12_M[0][0],
                                          u16LocalCalcParaX,
                                          u16LocalCalcParaY,
                                          8);
   AirSys_tqIdcHPCal12 = (uint16)MATHSRV_udtMIN(u16LocalInterp2d, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCalibration_13                                 */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_025.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AirSys_nEngEffCycShoIdl_A[8];                                */
/*  input uint16 AirSys_rAirLdEffCyc_A[8];                                    */
/*  input uint16 AirSys_tqIdcHPCal13_M[8][8];                                 */
/*  output uint16 AirSys_tqIdcHPCal13;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalibration_13(void)
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
   u16LocalInterp2d = MATHSRV_u16Interp2d(&AirSys_tqIdcHPCal13_M[0][0],
                                          u16LocalCalcParaX,
                                          u16LocalCalcParaY,
                                          8);
   AirSys_tqIdcHPCal13 = (uint16)MATHSRV_udtMIN(u16LocalInterp2d, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCalibration_14                                 */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AirSys_nEngEffCycSho_A[8];                                   */
/*  input uint16 AirSys_rAirLdEffCyc_A[8];                                    */
/*  input uint16 AirSys_tqIdcHPCal14_M[8][8];                                 */
/*  output uint16 AirSys_tqIdcHPCal14;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalibration_14(void)
{
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalInterp2d;


   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(AirSys_nEngEffCycSho_A,
                                                    u16LocalExt_nEng,
                                                    8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(AirSys_rAirLdEffCyc_A,
                                                    u16LocalEngM_rAirLdCor,
                                                    8);
   u16LocalInterp2d = MATHSRV_u16Interp2d(&AirSys_tqIdcHPCal14_M[0][0],
                                          u16LocalCalcParaX,
                                          u16LocalCalcParaY,
                                          8);
   AirSys_tqIdcHPCal14 = (uint16)MATHSRV_udtMIN(u16LocalInterp2d, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidVectorz_Calibrations                           */
/* !Description :  Ce bloc permet de calculer le rendement de cycle à partir  */
/*                 du couple calculé.                                         */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_027.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 EngM_mRef_C;                                                 */
/*  input uint16 AirSys_tqIdcHPCal1;                                          */
/*  input uint16 AirSys_tqIdcHPCal2;                                          */
/*  input uint16 AirSys_tqIdcHPCal3;                                          */
/*  input uint16 AirSys_tqIdcHPCal4;                                          */
/*  input uint16 AirSys_tqIdcHPCal5;                                          */
/*  input uint16 AirSys_tqIdcHPCal6;                                          */
/*  input uint16 AirSys_tqIdcHPCal7;                                          */
/*  input uint16 AirSys_tqIdcHPCal8;                                          */
/*  input uint16 AirSys_tqIdcHPCal9;                                          */
/*  input uint16 AirSys_tqIdcHPCal10;                                         */
/*  input uint16 AirSys_tqIdcHPCal11;                                         */
/*  input uint16 AirSys_tqIdcHPCal12;                                         */
/*  input uint16 AirSys_tqIdcHPCal13;                                         */
/*  input uint16 AirSys_tqIdcHPCal14;                                         */
/*  output uint16 AirSys_prm_effCyc[14];                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidVectorz_Calibrations(void)
{
   uint16 u16LocalEngM_rAirLdCor;
   uint32 u32LocalProd;
   uint32 u32LocalDiv;
   uint32 u32LocalDiv1;
   uint32 u32LocalEffCyc;


   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   u32LocalProd = (uint32)(u16LocalEngM_rAirLdCor * EngM_mRef_C);

   if (u32LocalProd < 733054)
   {
      u32LocalProd = (u32LocalProd * 1953);
      u32LocalDiv = ((u32LocalProd + 1024) / 2048);
   }
   else
   {
      u32LocalDiv = ((u32LocalProd + 1024) / 2048);
      u32LocalDiv = (u32LocalDiv * 1953);
   }

   if (AirSys_tqIdcHPCal1 != 0)
   {
      u32LocalDiv1 = (u32LocalDiv / AirSys_tqIdcHPCal1);
      if (u32LocalDiv1 > 12288)
      {
         u32LocalEffCyc = u32LocalDiv1 - 12288;
         AirSys_prm_effCyc[0] = (uint16)MATHSRV_udtMIN(u32LocalEffCyc, 65535);
      }
      else
      {
         AirSys_prm_effCyc[0] = 0;
      }
   }
   else
   {
      AirSys_prm_effCyc[0] = 65535;
   }

   if (AirSys_tqIdcHPCal2 != 0)
   {
      u32LocalDiv1 = (u32LocalDiv / AirSys_tqIdcHPCal2);
      if (u32LocalDiv1 > 12288)
      {
         u32LocalEffCyc = u32LocalDiv1 - 12288;
         AirSys_prm_effCyc[1] = (uint16)MATHSRV_udtMIN(u32LocalEffCyc, 65535);
      }
      else
      {
         AirSys_prm_effCyc[1] = 0;
      }
   }
   else
   {
      AirSys_prm_effCyc[1] = 65535;
   }

   if (AirSys_tqIdcHPCal3 != 0)
   {
      u32LocalDiv1 = (u32LocalDiv / AirSys_tqIdcHPCal3);
      if (u32LocalDiv1 > 12288)
      {
         u32LocalEffCyc = u32LocalDiv1 - 12288;
         AirSys_prm_effCyc[2] = (uint16)MATHSRV_udtMIN(u32LocalEffCyc, 65535);
      }
      else
      {
         AirSys_prm_effCyc[2] = 0;
      }
   }
   else
   {
      AirSys_prm_effCyc[2] = 65535;
   }

   if (AirSys_tqIdcHPCal4 != 0)
   {
      u32LocalDiv1 = (u32LocalDiv / AirSys_tqIdcHPCal4);
      if (u32LocalDiv1 > 12288)
      {
         u32LocalEffCyc = u32LocalDiv1 - 12288;
         AirSys_prm_effCyc[3] = (uint16)MATHSRV_udtMIN(u32LocalEffCyc, 65535);
      }
      else
      {
         AirSys_prm_effCyc[3] = 0;
      }
   }
   else
   {
      AirSys_prm_effCyc[3] = 65535;
   }

   if (AirSys_tqIdcHPCal5 != 0)
   {
      u32LocalDiv1 = (u32LocalDiv / AirSys_tqIdcHPCal5);
      if (u32LocalDiv1 > 12288)
      {
         u32LocalEffCyc = u32LocalDiv1 - 12288;
         AirSys_prm_effCyc[4] = (uint16)MATHSRV_udtMIN(u32LocalEffCyc, 65535);
      }
      else
      {
         AirSys_prm_effCyc[4] = 0;
      }
   }
   else
   {
      AirSys_prm_effCyc[4] = 65535;
   }

   if (AirSys_tqIdcHPCal6 != 0)
   {
      u32LocalDiv1 = (u32LocalDiv / AirSys_tqIdcHPCal6);
      if (u32LocalDiv1 > 12288)
      {
         u32LocalEffCyc = u32LocalDiv1 - 12288;
         AirSys_prm_effCyc[5] = (uint16)MATHSRV_udtMIN(u32LocalEffCyc, 65535);
      }
      else
      {
         AirSys_prm_effCyc[5] = 0;
      }
   }
   else
   {
      AirSys_prm_effCyc[5] = 65535;
   }

   if (AirSys_tqIdcHPCal7 != 0)
   {
      u32LocalDiv1 = (u32LocalDiv / AirSys_tqIdcHPCal7);
      if (u32LocalDiv1 > 12288)
      {
         u32LocalEffCyc = u32LocalDiv1 - 12288;
         AirSys_prm_effCyc[6] = (uint16)MATHSRV_udtMIN(u32LocalEffCyc, 65535);
      }
      else
      {
         AirSys_prm_effCyc[6] = 0;
      }
   }
   else
   {
      AirSys_prm_effCyc[6] = 65535;
   }

   if (AirSys_tqIdcHPCal8 != 0)
   {
      u32LocalDiv1 = (u32LocalDiv / AirSys_tqIdcHPCal8);
      if (u32LocalDiv1 > 12288)
      {
         u32LocalEffCyc = u32LocalDiv1 - 12288;
         AirSys_prm_effCyc[7] = (uint16)MATHSRV_udtMIN(u32LocalEffCyc, 65535);
      }
      else
      {
         AirSys_prm_effCyc[7] = 0;
      }
   }
   else
   {
      AirSys_prm_effCyc[7] = 65535;
   }

   if (AirSys_tqIdcHPCal9 != 0)
   {
      u32LocalDiv1 = (u32LocalDiv / AirSys_tqIdcHPCal9);
      if (u32LocalDiv1 > 12288)
      {
         u32LocalEffCyc = u32LocalDiv1 - 12288;
         AirSys_prm_effCyc[8] = (uint16)MATHSRV_udtMIN(u32LocalEffCyc, 65535);
      }
      else
      {
         AirSys_prm_effCyc[8] = 0;
      }
   }
   else
   {
      AirSys_prm_effCyc[8] = 65535;
   }

   if (AirSys_tqIdcHPCal10 != 0)
   {
      u32LocalDiv1 = (u32LocalDiv / AirSys_tqIdcHPCal10);
      if (u32LocalDiv1 > 12288)
      {
         u32LocalEffCyc = u32LocalDiv1 - 12288;
         AirSys_prm_effCyc[9] = (uint16)MATHSRV_udtMIN(u32LocalEffCyc, 65535);
      }
      else
      {
         AirSys_prm_effCyc[9] = 0;
      }
   }
   else
   {
      AirSys_prm_effCyc[9] = 65535;
   }

   if (AirSys_tqIdcHPCal11 != 0)
   {
      u32LocalDiv1 = (u32LocalDiv / AirSys_tqIdcHPCal11);
      if (u32LocalDiv1 > 12288)
      {
         u32LocalEffCyc = u32LocalDiv1 - 12288;
         AirSys_prm_effCyc[10] = (uint16)MATHSRV_udtMIN(u32LocalEffCyc, 65535);
      }
      else
      {
         AirSys_prm_effCyc[10] = 0;
      }
   }
   else
   {
      AirSys_prm_effCyc[10] = 65535;
   }

   if (AirSys_tqIdcHPCal12 != 0)
   {
      u32LocalDiv1 = (u32LocalDiv / AirSys_tqIdcHPCal12);
      if (u32LocalDiv1 > 12288)
      {
         u32LocalEffCyc = u32LocalDiv1 - 12288;
         AirSys_prm_effCyc[11] = (uint16)MATHSRV_udtMIN(u32LocalEffCyc, 65535);
      }
      else
      {
         AirSys_prm_effCyc[11] = 0;
      }
   }
   else
   {
      AirSys_prm_effCyc[11] = 65535;
   }

   if (AirSys_tqIdcHPCal13 != 0)
   {
      u32LocalDiv1 = (u32LocalDiv / AirSys_tqIdcHPCal13);
      if (u32LocalDiv1 > 12288)
      {
         u32LocalEffCyc = u32LocalDiv1 - 12288;
         AirSys_prm_effCyc[12] = (uint16)MATHSRV_udtMIN(u32LocalEffCyc, 65535);
      }
      else
      {
         AirSys_prm_effCyc[12] = 0;
      }
   }
   else
   {
      AirSys_prm_effCyc[12] = 65535;
   }

   if (AirSys_tqIdcHPCal14 != 0)
   {
      u32LocalDiv1 = (u32LocalDiv / AirSys_tqIdcHPCal14);
      if (u32LocalDiv1 > 12288)
      {
         u32LocalEffCyc = u32LocalDiv1 - 12288;
         AirSys_prm_effCyc[13] = (uint16)MATHSRV_udtMIN(u32LocalEffCyc, 65535);
      }
      else
      {
         AirSys_prm_effCyc[13] = 0;
      }
   }
   else
   {
      AirSys_prm_effCyc[13] = 65535;
   }
}
/*---------------------------------end of file--------------------------------*/