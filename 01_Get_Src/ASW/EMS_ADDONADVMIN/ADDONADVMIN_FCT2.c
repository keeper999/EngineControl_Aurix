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
/* !File            : ADDONADVMIN_FCT2.c                                      */
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
/*   1 / ADDONADVMIN_vidCalibration_5                                         */
/*   2 / ADDONADVMIN_vidCalibration_6                                         */
/*   3 / ADDONADVMIN_vidCalibration_7                                         */
/*   4 / ADDONADVMIN_vidCalibration_8                                         */
/*   5 / ADDONADVMIN_vidCalibration_9                                         */
/*   6 / ADDONADVMIN_vidCalibration_10                                        */
/*   7 / ADDONADVMIN_vidCalibration_11                                        */
/*   8 / ADDONADVMIN_vidCalibration_12                                        */
/*   9 / ADDONADVMIN_vidCalibration_13                                        */
/*   10 / ADDONADVMIN_vidCalibration_14                                       */
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
/* !Function    :  ADDONADVMIN_vidCalibration_5                               */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMin_A[16];                                  */
/*  input uint16 IgSys_rAirLdOfsAgIgMin_A[16];                                */
/*  input uint8 IgSys_ofsAgIgMinCal5_M[16][16];                               */
/*  output sint16 IgSys_ofsAgIgMinCal5;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidCalibration_5(void)
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
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMinCal5_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);

   s16IgSys_ofsAgIgMinCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMinCal5 = s16IgSys_ofsAgIgMinCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidCalibration_6                               */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMin_A[16];                                  */
/*  input uint16 IgSys_rAirLdOfsAgIgMin_A[16];                                */
/*  input uint8 IgSys_ofsAgIgMinCal6_M[16][16];                               */
/*  output sint16 IgSys_ofsAgIgMinCal6;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidCalibration_6(void)
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
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMinCal6_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);

   s16IgSys_ofsAgIgMinCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMinCal6 = s16IgSys_ofsAgIgMinCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidCalibration_7                               */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMin_A[16];                                  */
/*  input uint16 IgSys_rAirLdOfsAgIgMin_A[16];                                */
/*  input uint8 IgSys_ofsAgIgMinCal7_M[16][16];                               */
/*  output sint16 IgSys_ofsAgIgMinCal7;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidCalibration_7(void)
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
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMinCal7_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);

   s16IgSys_ofsAgIgMinCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMinCal7 = s16IgSys_ofsAgIgMinCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidCalibration_8                               */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMin_A[16];                                  */
/*  input uint16 IgSys_rAirLdOfsAgIgMin_A[16];                                */
/*  input uint8 IgSys_ofsAgIgMinCal8_M[16][16];                               */
/*  output sint16 IgSys_ofsAgIgMinCal8;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidCalibration_8(void)
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
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMinCal8_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);

   s16IgSys_ofsAgIgMinCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMinCal8 = s16IgSys_ofsAgIgMinCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidCalibration_9                               */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMinShoIdl_A[8];                             */
/*  input uint16 IgSys_rAirLdOfsAgIgMinShoIdl_A[8];                           */
/*  input uint8 IgSys_ofsAgIgMinCal9_M[8][8];                                 */
/*  output sint16 IgSys_ofsAgIgMinCal9;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidCalibration_9(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   sint16 s16IgSys_ofsAgIgMinCal;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgMinShoIdl_A,
                                   u16LocalExt_nEng,
                                   8);
   u16LocalCalcParaY =
      MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgMinShoIdl_A,
                                   u16LocalEngM_rAirLdCor,
                                   8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMinCal9_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);

   s16IgSys_ofsAgIgMinCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMinCal9 = s16IgSys_ofsAgIgMinCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidCalibration_10                              */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMinShoIdl_A[8];                             */
/*  input uint16 IgSys_rAirLdOfsAgIgMinShoIdl_A[8];                           */
/*  input uint8 IgSys_ofsAgIgMinCal10_M[8][8];                                */
/*  output sint16 IgSys_ofsAgIgMinCal10;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidCalibration_10(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   sint16 s16IgSys_ofsAgIgMinCal;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgMinShoIdl_A,
                                   u16LocalExt_nEng,
                                   8);
   u16LocalCalcParaY =
      MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgMinShoIdl_A,
                                   u16LocalEngM_rAirLdCor,
                                   8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMinCal10_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);

   s16IgSys_ofsAgIgMinCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMinCal10 = s16IgSys_ofsAgIgMinCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidCalibration_11                              */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMinShoIdl_A[8];                             */
/*  input uint16 IgSys_rAirLdOfsAgIgMinShoIdl_A[8];                           */
/*  input uint8 IgSys_ofsAgIgMinCal11_M[8][8];                                */
/*  output sint16 IgSys_ofsAgIgMinCal11;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidCalibration_11(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   sint16 s16IgSys_ofsAgIgMinCal;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgMinShoIdl_A,
                                   u16LocalExt_nEng,
                                   8);
   u16LocalCalcParaY =
      MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgMinShoIdl_A,
                                   u16LocalEngM_rAirLdCor,
                                   8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMinCal11_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);

   s16IgSys_ofsAgIgMinCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMinCal11 = s16IgSys_ofsAgIgMinCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidCalibration_12                              */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMinShoIdl_A[8];                             */
/*  input uint16 IgSys_rAirLdOfsAgIgMinShoIdl_A[8];                           */
/*  input uint8 IgSys_ofsAgIgMinCal12_M[8][8];                                */
/*  output sint16 IgSys_ofsAgIgMinCal12;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidCalibration_12(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   sint16 s16IgSys_ofsAgIgMinCal;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgMinShoIdl_A,
                                   u16LocalExt_nEng,
                                   8);
   u16LocalCalcParaY =
      MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgMinShoIdl_A,
                                   u16LocalEngM_rAirLdCor,
                                   8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMinCal12_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);

   s16IgSys_ofsAgIgMinCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMinCal12 = s16IgSys_ofsAgIgMinCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidCalibration_13                              */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_019.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMinShoIdl_A[8];                             */
/*  input uint16 IgSys_rAirLdOfsAgIgMinShoIdl_A[8];                           */
/*  input uint8 IgSys_ofsAgIgMinCal13_M[8][8];                                */
/*  output sint16 IgSys_ofsAgIgMinCal13;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidCalibration_13(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   sint16 s16IgSys_ofsAgIgMinCal;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgMinShoIdl_A,
                                   u16LocalExt_nEng,
                                   8);
   u16LocalCalcParaY =
      MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgMinShoIdl_A,
                                   u16LocalEngM_rAirLdCor,
                                   8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMinCal13_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);

   s16IgSys_ofsAgIgMinCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMinCal13 = s16IgSys_ofsAgIgMinCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidCalibration_14                              */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint16 IgSys_ofsAgIgMinCal14_C;                                     */
/*  output sint16 IgSys_ofsAgIgMinCal14;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidCalibration_14(void)
{
   IgSys_ofsAgIgMinCal14 = (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMinCal14_C,
                                                    -96,
                                                    159);
}
/*---------------------------------end of file--------------------------------*/