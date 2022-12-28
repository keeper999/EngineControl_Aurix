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
/* !File            : VLVEXSPMGT_FCT3.C                                       */
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
/*   1 / VLVEXSPMGT_vidCalibration_11                                         */
/*   2 / VLVEXSPMGT_vidCalibration_12                                         */
/*   3 / VLVEXSPMGT_vidCalibration_13                                         */
/*   4 / VLVEXSPMGT_vidCalibration_14                                         */
/*   5 / VLVEXSPMGT_vidCalibration_15                                         */
/*   6 / VLVEXSPMGT_vidCalibration_16                                         */
/*   7 / VLVEXSPMGT_vidCalibration_17                                         */
/*   8 / VLVEXSPMGT_vidCalibration_18                                         */
/*   9 / VLVEXSPMGT_vidVectorize_Calibs                                       */
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
/* !Function    :  VLVEXSPMGT_vidCalibration_11                               */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 11.  Le calcul de ce bloc est effectué seulement si le mode*/
/*                 associé est activé.                                        */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd8_A[8];                                         */
/*  input uint16 VlvSys_nEng8_A[8];                                           */
/*  input uint8 VlvSys_agCkClsExCal11_M[8][8];                                */
/*  output sint8 VlvSys_agCkClsExCal11;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidCalibration_11(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalVlvSys_rAirLdAltiCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   VEMS_vidGET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(VlvSys_rAirLd8_A,
                                   u16LocalVlvSys_rAirLdAltiCor,
                                   8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng8_A,
                                                    u16LocalExt_nEng,
                                                    8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkClsExCal11_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   VlvSys_agCkClsExCal11 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidCalibration_12                               */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 12.  Le calcul de ce bloc est effectué seulement si le mode*/
/*                 associé est activé.                                        */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd8_A[8];                                         */
/*  input uint16 VlvSys_nEng8_A[8];                                           */
/*  input uint8 VlvSys_agCkClsExCal12_M[8][8];                                */
/*  output sint8 VlvSys_agCkClsExCal12;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidCalibration_12(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalVlvSys_rAirLdAltiCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   VEMS_vidGET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(VlvSys_rAirLd8_A,
                                    u16LocalVlvSys_rAirLdAltiCor,
                                    8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng8_A,
                                                    u16LocalExt_nEng,
                                                    8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkClsExCal12_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   VlvSys_agCkClsExCal12 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidCalibration_13                               */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 13.  Le calcul de ce bloc est effectué seulement si le mode*/
/*                 associé est activé.                                        */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd8_A[8];                                         */
/*  input uint16 VlvSys_nEng8_A[8];                                           */
/*  input uint8 VlvSys_agCkClsExCal13_M[8][8];                                */
/*  output sint8 VlvSys_agCkClsExCal13;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidCalibration_13(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalVlvSys_rAirLdAltiCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   VEMS_vidGET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(VlvSys_rAirLd8_A,
                                   u16LocalVlvSys_rAirLdAltiCor,
                                   8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng8_A,
                                                    u16LocalExt_nEng,
                                                    8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkClsExCal13_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   VlvSys_agCkClsExCal13 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidCalibration_14                               */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 14.  Le calcul de ce bloc est effectué seulement si le mode*/
/*                 associé est activé.                                        */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd8_A[8];                                         */
/*  input uint16 VlvSys_nEng8_A[8];                                           */
/*  input uint8 VlvSys_agCkClsExCal14_M[8][8];                                */
/*  output sint8 VlvSys_agCkClsExCal14;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidCalibration_14(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalVlvSys_rAirLdAltiCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   VEMS_vidGET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(VlvSys_rAirLd8_A,
                                   u16LocalVlvSys_rAirLdAltiCor,
                                   8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng8_A,
                                                    u16LocalExt_nEng,
                                                    8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkClsExCal14_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   VlvSys_agCkClsExCal14 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidCalibration_15                               */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 15.  Le calcul de ce bloc est effectué seulement si le mode*/
/*                 associé est activé.                                        */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_024.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd8_A[8];                                         */
/*  input uint16 VlvSys_nEng8_A[8];                                           */
/*  input uint8 VlvSys_agCkClsExCal15_M[8][8];                                */
/*  output sint8 VlvSys_agCkClsExCal15;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidCalibration_15(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalVlvSys_rAirLdAltiCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   VEMS_vidGET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(VlvSys_rAirLd8_A,
                                   u16LocalVlvSys_rAirLdAltiCor,
                                   8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng8_A,
                                                    u16LocalExt_nEng,
                                                    8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkClsExCal15_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   VlvSys_agCkClsExCal15 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidCalibration_16                               */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 16.  Le calcul de ce bloc est effectué seulement si le mode*/
/*                 associé est activé.                                        */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_025.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd8_A[8];                                         */
/*  input uint16 VlvSys_nEng8_A[8];                                           */
/*  input uint8 VlvSys_agCkClsExCal16_M[8][8];                                */
/*  output sint8 VlvSys_agCkClsExCal16;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidCalibration_16(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalVlvSys_rAirLdAltiCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   VEMS_vidGET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(VlvSys_rAirLd8_A,
                                   u16LocalVlvSys_rAirLdAltiCor,
                                   8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng8_A,
                                                    u16LocalExt_nEng,
                                                    8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkClsExCal16_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   VlvSys_agCkClsExCal16 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidCalibration_17                               */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 17.  Le calcul de ce bloc est effectué seulement si le mode*/
/*                 associé est activé.                                        */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint8 VlvSys_agCkClsExCal17_C;                                      */
/*  output sint8 VlvSys_agCkClsExCal17;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidCalibration_17(void)
{
   VlvSys_agCkClsExCal17 = VlvSys_agCkClsExCal17_C;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidCalibration_18                               */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 18.  Le calcul de ce bloc est effectué seulement si le mode*/
/*                 associé est activé.                                        */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_027.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint8 VlvSys_agCkClsExCal18_C;                                      */
/*  output sint8 VlvSys_agCkClsExCal18;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidCalibration_18(void)
{
   VlvSys_agCkClsExCal18 = VlvSys_agCkClsExCal18_C;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidVectorize_Calibs                             */
/* !Description :  Ce bloc permet de concaténer sur un seul flux l'ensemble   */
/*                 des consignes VVT issues des cartographies.                */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_028.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint8 VlvSys_agCkClsExCal1;                                         */
/*  input sint8 VlvSys_agCkClsExCal2;                                         */
/*  input sint8 VlvSys_agCkClsExCal3;                                         */
/*  input sint8 VlvSys_agCkClsExCal4;                                         */
/*  input sint8 VlvSys_agCkClsExCal5;                                         */
/*  input sint8 VlvSys_agCkClsExCal6;                                         */
/*  input sint8 VlvSys_agCkClsExCal7;                                         */
/*  input sint8 VlvSys_agCkClsExCal8;                                         */
/*  input sint8 VlvSys_agCkClsExCal9;                                         */
/*  input sint8 VlvSys_agCkClsExCal10;                                        */
/*  input sint8 VlvSys_agCkClsExCal11;                                        */
/*  input sint8 VlvSys_agCkClsExCal12;                                        */
/*  input sint8 VlvSys_agCkClsExCal13;                                        */
/*  input sint8 VlvSys_agCkClsExCal14;                                        */
/*  input sint8 VlvSys_agCkClsExCal15;                                        */
/*  input sint8 VlvSys_agCkClsExCal16;                                        */
/*  input sint8 VlvSys_agCkClsExCal17;                                        */
/*  input sint8 VlvSys_agCkClsExCal18;                                        */
/*  output sint8 VlvSys_prm_agCkClsExCal[18];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidVectorize_Calibs(void)
{
   VlvSys_prm_agCkClsExCal[0] = VlvSys_agCkClsExCal1;
   VlvSys_prm_agCkClsExCal[1] = VlvSys_agCkClsExCal2;
   VlvSys_prm_agCkClsExCal[2] = VlvSys_agCkClsExCal3;
   VlvSys_prm_agCkClsExCal[3] = VlvSys_agCkClsExCal4;
   VlvSys_prm_agCkClsExCal[4] = VlvSys_agCkClsExCal5;
   VlvSys_prm_agCkClsExCal[5] = VlvSys_agCkClsExCal6;
   VlvSys_prm_agCkClsExCal[6] = VlvSys_agCkClsExCal7;
   VlvSys_prm_agCkClsExCal[7] = VlvSys_agCkClsExCal8;
   VlvSys_prm_agCkClsExCal[8] = VlvSys_agCkClsExCal9;
   VlvSys_prm_agCkClsExCal[9] = VlvSys_agCkClsExCal10;
   VlvSys_prm_agCkClsExCal[10] = VlvSys_agCkClsExCal11;
   VlvSys_prm_agCkClsExCal[11] = VlvSys_agCkClsExCal12;
   VlvSys_prm_agCkClsExCal[12] = VlvSys_agCkClsExCal13;
   VlvSys_prm_agCkClsExCal[13] = VlvSys_agCkClsExCal14;
   VlvSys_prm_agCkClsExCal[14] = VlvSys_agCkClsExCal15;
   VlvSys_prm_agCkClsExCal[15] = VlvSys_agCkClsExCal16;
   VlvSys_prm_agCkClsExCal[16] = VlvSys_agCkClsExCal17;
   VlvSys_prm_agCkClsExCal[17] = VlvSys_agCkClsExCal18;
}

/*---------------------------------end of file--------------------------------*/