/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVEXSPMGT                                              */
/* !Description     : VLVEXSPMGT component                                    */
/*                                                                            */
/* !Module          : VLVEXSPMGT                                              */
/* !Description     : Gestion de la consigne VVT échappement                  */
/*                                                                            */
/* !File            : VLVEXSPMGT_FCT2.C                                       */
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
/*   1 / VLVEXSPMGT_vidCalibration_1                                          */
/*   2 / VLVEXSPMGT_vidCalibration_2                                          */
/*   3 / VLVEXSPMGT_vidCalibration_3                                          */
/*   4 / VLVEXSPMGT_vidCalibration_4                                          */
/*   5 / VLVEXSPMGT_vidCalibration_5                                          */
/*   6 / VLVEXSPMGT_vidCalibration_6                                          */
/*   7 / VLVEXSPMGT_vidCalibration_7                                          */
/*   8 / VLVEXSPMGT_vidCalibration_8                                          */
/*   9 / VLVEXSPMGT_vidCalibration_9                                          */
/*   10 / VLVEXSPMGT_vidCalibration_10                                        */
/*                                                                            */
/* !Reference   : V02 NT 11 02167 / 02                                        */
/* !OtherRefs   : CSMT_CGMT09_2177_2 / 1.1                                    */
/* !OtherRefs   : VEMS V02 ECU#053820                                         */
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
#include "VLVEXSPMGT.h"
#include "VLVEXSPMGT_L.h"
#include "VLVEXSPMGT_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidCalibration_1                                */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 1.  Le calcul de ce bloc est effectué seulement si le mode */
/*                 associé est activé.                                        */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd16_A[16];                                       */
/*  input uint16 VlvSys_nEng16_A[16];                                         */
/*  input uint8 VlvSys_agCkClsExCal1_M[16][16];                               */
/*  output sint8 VlvSys_agCkClsExCal1;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidCalibration_1(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalVlvSys_rAirLdAltiCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   VEMS_vidGET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(VlvSys_rAirLd16_A,
                                   u16LocalVlvSys_rAirLdAltiCor,
                                   16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng16_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkClsExCal1_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);
   VlvSys_agCkClsExCal1 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidCalibration_2                                */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 2.  Le calcul de ce bloc est effectué seulement si le mode */
/*                 associé est activé.                                        */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd16_A[16];                                       */
/*  input uint16 VlvSys_nEng16_A[16];                                         */
/*  input uint8 VlvSys_agCkClsExCal2_M[16][16];                               */
/*  output sint8 VlvSys_agCkClsExCal2;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidCalibration_2(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalVlvSys_rAirLdAltiCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   VEMS_vidGET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(VlvSys_rAirLd16_A,
                                   u16LocalVlvSys_rAirLdAltiCor,
                                   16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng16_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkClsExCal2_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);
   VlvSys_agCkClsExCal2 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidCalibration_3                                */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 3.  Le calcul de ce bloc est effectué seulement si le mode */
/*                 associé est activé.                                        */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd16_A[16];                                       */
/*  input uint16 VlvSys_nEng16_A[16];                                         */
/*  input uint8 VlvSys_agCkClsExCal3_M[16][16];                               */
/*  output sint8 VlvSys_agCkClsExCal3;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidCalibration_3(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalVlvSys_rAirLdAltiCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   VEMS_vidGET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(VlvSys_rAirLd16_A,
                                   u16LocalVlvSys_rAirLdAltiCor,
                                   16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng16_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkClsExCal3_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);
   VlvSys_agCkClsExCal3 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidCalibration_4                                */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 4.  Le calcul de ce bloc est effectué seulement si le mode */
/*                 associé est activé.                                        */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd16_A[16];                                       */
/*  input uint16 VlvSys_nEng16_A[16];                                         */
/*  input uint8 VlvSys_agCkClsExCal4_M[16][16];                               */
/*  output sint8 VlvSys_agCkClsExCal4;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidCalibration_4(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalVlvSys_rAirLdAltiCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   VEMS_vidGET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(VlvSys_rAirLd16_A,
                                   u16LocalVlvSys_rAirLdAltiCor,
                                   16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng16_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkClsExCal4_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);
   VlvSys_agCkClsExCal4 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidCalibration_5                                */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 5.  Le calcul de ce bloc est effectué seulement si le mode */
/*                 associé est activé.                                        */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd16_A[16];                                       */
/*  input uint16 VlvSys_nEng16_A[16];                                         */
/*  input uint8 VlvSys_agCkClsExCal5_M[16][16];                               */
/*  output sint8 VlvSys_agCkClsExCal5;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidCalibration_5(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalVlvSys_rAirLdAltiCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   VEMS_vidGET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(VlvSys_rAirLd16_A,
                                   u16LocalVlvSys_rAirLdAltiCor,
                                   16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng16_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkClsExCal5_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);
   VlvSys_agCkClsExCal5 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidCalibration_6                                */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 6.  Le calcul de ce bloc est effectué seulement si le mode */
/*                 associé est activé.                                        */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd16_A[16];                                       */
/*  input uint16 VlvSys_nEng16_A[16];                                         */
/*  input uint8 VlvSys_agCkClsExCal6_M[16][16];                               */
/*  output sint8 VlvSys_agCkClsExCal6;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidCalibration_6(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalVlvSys_rAirLdAltiCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   VEMS_vidGET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(VlvSys_rAirLd16_A,
                                   u16LocalVlvSys_rAirLdAltiCor,
                                   16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng16_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkClsExCal6_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);
   VlvSys_agCkClsExCal6 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidCalibration_7                                */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 7.  Le calcul de ce bloc est effectué seulement si le mode */
/*                 associé est activé.                                        */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd16_A[16];                                       */
/*  input uint16 VlvSys_nEng16_A[16];                                         */
/*  input uint8 VlvSys_agCkClsExCal7_M[16][16];                               */
/*  output sint8 VlvSys_agCkClsExCal7;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidCalibration_7(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalVlvSys_rAirLdAltiCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   VEMS_vidGET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(VlvSys_rAirLd16_A,
                                   u16LocalVlvSys_rAirLdAltiCor,
                                   16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng16_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkClsExCal7_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);
   VlvSys_agCkClsExCal7 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidCalibration_8                                */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 8.  Le calcul de ce bloc est effectué seulement si le mode */
/*                 associé est activé.                                        */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd16_A[16];                                       */
/*  input uint16 VlvSys_nEng16_A[16];                                         */
/*  input uint8 VlvSys_agCkClsExCal8_M[16][16];                               */
/*  output sint8 VlvSys_agCkClsExCal8;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidCalibration_8(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalVlvSys_rAirLdAltiCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   VEMS_vidGET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(VlvSys_rAirLd16_A,
                                   u16LocalVlvSys_rAirLdAltiCor,
                                   16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng16_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkClsExCal8_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);
   VlvSys_agCkClsExCal8 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidCalibration_9                                */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 9.  Le calcul de ce bloc est effectué seulement si le mode */
/*                 associé est activé.                                        */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd16_A[16];                                       */
/*  input uint16 VlvSys_nEng16_A[16];                                         */
/*  input uint8 VlvSys_agCkClsExCal9_M[16][16];                               */
/*  output sint8 VlvSys_agCkClsExCal9;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidCalibration_9(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalVlvSys_rAirLdAltiCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   VEMS_vidGET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(VlvSys_rAirLd16_A,
                                   u16LocalVlvSys_rAirLdAltiCor,
                                   16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng16_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkClsExCal9_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);
   VlvSys_agCkClsExCal9 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidCalibration_10                               */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 10.  Le calcul de ce bloc est effectué seulement si le mode*/
/*                 associé est activé.                                        */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_019.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdPrfMod;                                         */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd16_A[16];                                       */
/*  input uint16 VlvSys_nEng16_A[16];                                         */
/*  input uint8 VlvSys_agCkClsExCal10_M[16][16];                              */
/*  output sint8 VlvSys_agCkClsExCal10;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidCalibration_10(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalVlvSys_rAirLdPrfMod;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   VEMS_vidGET(VlvSys_rAirLdPrfMod, u16LocalVlvSys_rAirLdPrfMod);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(VlvSys_rAirLd16_A,
                                   u16LocalVlvSys_rAirLdPrfMod,
                                   16);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng16_A,
                                                    u16LocalExt_nEng,
                                                    16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkClsExCal10_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        16);
   VlvSys_agCkClsExCal10 = (sint8)(u8LocalInterp2d - 128);
}

/*---------------------------------end of file--------------------------------*/