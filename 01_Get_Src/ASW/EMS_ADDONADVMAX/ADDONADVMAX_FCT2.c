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
/* !File            : ADDONADVMAX_FCT2.C                                      */
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
/*   1 / ADDONADVMAX_vidCalibration_5                                         */
/*   2 / ADDONADVMAX_vidCalibration_6                                         */
/*   3 / ADDONADVMAX_vidCalibration_7                                         */
/*   4 / ADDONADVMAX_vidCalibration_8                                         */
/*   5 / ADDONADVMAX_vidCalibration_9                                         */
/*   6 / ADDONADVMAX_vidCalibration_10                                        */
/*   7 / ADDONADVMAX_vidCalibration_11                                        */
/*   8 / ADDONADVMAX_vidCalibration_12                                        */
/*   9 / ADDONADVMAX_vidCalibration_13                                        */
/*   10 / ADDONADVMAX_vidCalibration_14                                       */
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
/* !Function    :  ADDONADVMAX_vidCalibration_5                               */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMax_A[16];                                  */
/*  input uint16 IgSys_rAirLdOfsAgIgMax_A[16];                                */
/*  input uint8 IgSys_ofsAgIgMaxCal5_M[16][16];                               */
/*  output sint16 IgSys_ofsAgIgMaxCal5;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidCalibration_5(void)
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
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMaxCal5_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);

   s16IgSys_ofsAgIgMaxCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMaxCal5 = s16IgSys_ofsAgIgMaxCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidCalibration_6                               */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMax_A[16];                                  */
/*  input uint16 IgSys_rAirLdOfsAgIgMax_A[16];                                */
/*  input uint8 IgSys_ofsAgIgMaxCal6_M[16][16];                               */
/*  output sint16 IgSys_ofsAgIgMaxCal6;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidCalibration_6(void)
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
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMaxCal6_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);

   s16IgSys_ofsAgIgMaxCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMaxCal6 = s16IgSys_ofsAgIgMaxCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidCalibration_7                               */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMax_A[16];                                  */
/*  input uint16 IgSys_rAirLdOfsAgIgMax_A[16];                                */
/*  input uint8 IgSys_ofsAgIgMaxCal7_M[16][16];                               */
/*  output sint16 IgSys_ofsAgIgMaxCal7;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidCalibration_7(void)
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
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMaxCal7_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);

   s16IgSys_ofsAgIgMaxCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMaxCal7 = s16IgSys_ofsAgIgMaxCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidCalibration_8                               */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMax_A[16];                                  */
/*  input uint16 IgSys_rAirLdOfsAgIgMax_A[16];                                */
/*  input uint8 IgSys_ofsAgIgMaxCal8_M[16][16];                               */
/*  output sint16 IgSys_ofsAgIgMaxCal8;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidCalibration_8(void)
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
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMaxCal8_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);

   s16IgSys_ofsAgIgMaxCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMaxCal8 = s16IgSys_ofsAgIgMaxCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidCalibration_9                               */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMaxShoIdl_A[8];                             */
/*  input uint16 IgSys_rAirLdOfsAgIgMaxShoIdl_A[8];                           */
/*  input uint8 IgSys_ofsAgIgMaxCal9_M[8][8];                                 */
/*  output sint16 IgSys_ofsAgIgMaxCal9;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidCalibration_9(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   sint16 s16IgSys_ofsAgIgMaxCal;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgMaxShoIdl_A,
                                   u16LocalExt_nEng,
                                   8);
   u16LocalCalcParaY =
      MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgMaxShoIdl_A,
                                   u16LocalEngM_rAirLdCor,
                                   8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMaxCal9_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);

   s16IgSys_ofsAgIgMaxCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMaxCal9 = s16IgSys_ofsAgIgMaxCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidCalibration_10                              */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMaxShoIdl_A[8];                             */
/*  input uint16 IgSys_rAirLdOfsAgIgMaxShoIdl_A[8];                           */
/*  input uint8 IgSys_ofsAgIgMaxCal10_M[8][8];                                */
/*  output sint16 IgSys_ofsAgIgMaxCal10;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidCalibration_10(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   sint16 s16IgSys_ofsAgIgMaxCal;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgMaxShoIdl_A,
                                   u16LocalExt_nEng,
                                   8);
   u16LocalCalcParaY =
      MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgMaxShoIdl_A,
                                   u16LocalEngM_rAirLdCor,
                                   8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMaxCal10_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);

   s16IgSys_ofsAgIgMaxCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMaxCal10 = s16IgSys_ofsAgIgMaxCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidCalibration_11                              */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMaxShoIdl_A[8];                             */
/*  input uint16 IgSys_rAirLdOfsAgIgMaxShoIdl_A[8];                           */
/*  input uint8 IgSys_ofsAgIgMaxCal11_M[8][8];                                */
/*  output sint16 IgSys_ofsAgIgMaxCal11;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidCalibration_11(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   sint16 s16IgSys_ofsAgIgMaxCal;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgMaxShoIdl_A,
                                   u16LocalExt_nEng,
                                   8);
   u16LocalCalcParaY =
      MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgMaxShoIdl_A,
                                   u16LocalEngM_rAirLdCor,
                                   8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMaxCal11_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);

   s16IgSys_ofsAgIgMaxCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMaxCal11 = s16IgSys_ofsAgIgMaxCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidCalibration_12                              */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMaxShoIdl_A[8];                             */
/*  input uint16 IgSys_rAirLdOfsAgIgMaxShoIdl_A[8];                           */
/*  input uint8 IgSys_ofsAgIgMaxCal12_M[8][8];                                */
/*  output sint16 IgSys_ofsAgIgMaxCal12;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidCalibration_12(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   sint16 s16IgSys_ofsAgIgMaxCal;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgMaxShoIdl_A,
                                   u16LocalExt_nEng,
                                   8);
   u16LocalCalcParaY =
      MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgMaxShoIdl_A,
                                   u16LocalEngM_rAirLdCor,
                                   8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMaxCal12_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);

   s16IgSys_ofsAgIgMaxCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMaxCal12 = s16IgSys_ofsAgIgMaxCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidCalibration_13                              */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_019.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgMaxShoIdl_A[8];                             */
/*  input uint16 IgSys_rAirLdOfsAgIgMaxShoIdl_A[8];                           */
/*  input uint8 IgSys_ofsAgIgMaxCal13_M[8][8];                                */
/*  output sint16 IgSys_ofsAgIgMaxCal13;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidCalibration_13(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   sint16 s16IgSys_ofsAgIgMaxCal;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgMaxShoIdl_A,
                                   u16LocalExt_nEng,
                                   8);
   u16LocalCalcParaY =
      MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgMaxShoIdl_A,
                                   u16LocalEngM_rAirLdCor,
                                   8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&IgSys_ofsAgIgMaxCal13_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);

   s16IgSys_ofsAgIgMaxCal = (sint16)(u8LocalInterp2d - 96);
   IgSys_ofsAgIgMaxCal13 = s16IgSys_ofsAgIgMaxCal;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidCalibration_14                              */
/* !Description :  Ce  bloc  contient  une  des  cartographies  de  la        */
/*                 fonction.  Il  n’est  calculé  que  lorsque  le mode  de   */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie.                     */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint16 IgSys_ofsAgIgMaxCal14_C;                                     */
/*  output sint16 IgSys_ofsAgIgMaxCal14;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidCalibration_14(void)
{
   IgSys_ofsAgIgMaxCal14 = (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMaxCal14_C,
                                                    -96,
                                                    159);
}
/*---------------------------------end of file--------------------------------*/