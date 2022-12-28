/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVINSPMGT                                              */
/* !Description     : VLVINSPMGT component                                    */
/*                                                                            */
/* !Module          : VLVINSPMGT                                              */
/* !Description     : Gestion de la consigne VVT admission                    */
/*                                                                            */
/* !File            : VLVINSPMGT_FCT3.C                                       */
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
/*   1 / VLVINSPMGT_vidCalibration_11                                         */
/*   2 / VLVINSPMGT_vidCalibration_12                                         */
/*   3 / VLVINSPMGT_vidCalibration_13                                         */
/*   4 / VLVINSPMGT_vidCalibration_14                                         */
/*   5 / VLVINSPMGT_vidCalibration_15                                         */
/*   6 / VLVINSPMGT_vidCalibration_16                                         */
/*   7 / VLVINSPMGT_vidCalibration_17                                         */
/*   8 / VLVINSPMGT_vidCalibration_18                                         */
/*   9 / VLVINSPMGT_vidVectorize_Calibs                                       */
/*                                                                            */
/* !Reference   : V02 NT 11 02166 / 01                                        */
/* !OtherRefs   : CSMT_CGMT09_2176_2 / 1                                      */
/* !OtherRefs   : VEMS V02 ECU#053818                                         */
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
#include "VLVINSPMGT.h"
#include "VLVINSPMGT_L.h"
#include "VLVINSPMGT_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVINSPMGT_vidCalibration_11                               */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 11.  Le calcul de ce bloc est effectué seulement si le mode*/
/*                 associé est activé.                                        */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02166_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd8_A[8];                                         */
/*  input uint16 VlvSys_nEng8_A[8];                                           */
/*  input uint8 VlvSys_agCkOpInCal11_M[8][8];                                 */
/*  output sint8 VlvSys_agCkOpInCal11;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVINSPMGT_vidCalibration_11(void)
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
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkOpInCal11_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   VlvSys_agCkOpInCal11 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVINSPMGT_vidCalibration_12                               */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 12.  Le calcul de ce bloc est effectué seulement si le mode*/
/*                 associé est activé.                                        */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02166_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd8_A[8];                                         */
/*  input uint16 VlvSys_nEng8_A[8];                                           */
/*  input uint8 VlvSys_agCkOpInCal12_M[8][8];                                 */
/*  output sint8 VlvSys_agCkOpInCal12;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVINSPMGT_vidCalibration_12(void)
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
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkOpInCal12_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   VlvSys_agCkOpInCal12 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVINSPMGT_vidCalibration_13                               */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 13.  Le calcul de ce bloc est effectué seulement si le mode*/
/*                 associé est activé.                                        */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02166_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd8_A[8];                                         */
/*  input uint16 VlvSys_nEng8_A[8];                                           */
/*  input uint8 VlvSys_agCkOpInCal13_M[8][8];                                 */
/*  output sint8 VlvSys_agCkOpInCal13;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVINSPMGT_vidCalibration_13(void)
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
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkOpInCal13_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   VlvSys_agCkOpInCal13 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVINSPMGT_vidCalibration_14                               */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 14.  Le calcul de ce bloc est effectué seulement si le mode*/
/*                 associé est activé.                                        */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02166_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd8_A[8];                                         */
/*  input uint16 VlvSys_nEng8_A[8];                                           */
/*  input uint8 VlvSys_agCkOpInCal14_M[8][8];                                 */
/*  output sint8 VlvSys_agCkOpInCal14;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVINSPMGT_vidCalibration_14(void)
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
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkOpInCal14_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   VlvSys_agCkOpInCal14 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVINSPMGT_vidCalibration_15                               */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 15.  Le calcul de ce bloc est effectué seulement si le mode*/
/*                 associé est activé.                                        */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02166_024.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd8_A[8];                                         */
/*  input uint16 VlvSys_nEng8_A[8];                                           */
/*  input uint8 VlvSys_agCkOpInCal15_M[8][8];                                 */
/*  output sint8 VlvSys_agCkOpInCal15;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVINSPMGT_vidCalibration_15(void)
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
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkOpInCal15_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   VlvSys_agCkOpInCal15 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVINSPMGT_vidCalibration_16                               */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 16.  Le calcul de ce bloc est effectué seulement si le mode*/
/*                 associé est activé.                                        */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02166_025.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd8_A[8];                                         */
/*  input uint16 VlvSys_nEng8_A[8];                                           */
/*  input uint8 VlvSys_agCkOpInCal16_M[8][8];                                 */
/*  output sint8 VlvSys_agCkOpInCal16;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVINSPMGT_vidCalibration_16(void)
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
   u8LocalInterp2d = MATHSRV_u8Interp2d(&VlvSys_agCkOpInCal16_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   VlvSys_agCkOpInCal16 = (sint8)(u8LocalInterp2d - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVINSPMGT_vidCalibration_17                               */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 17.  Le calcul de ce bloc est effectué seulement si le mode*/
/*                 associé est activé.                                        */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02166_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint8 VlvSys_agCkOpInCal17_C;                                       */
/*  output sint8 VlvSys_agCkOpInCal17;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVINSPMGT_vidCalibration_17(void)
{
   VlvSys_agCkOpInCal17 = VlvSys_agCkOpInCal17_C;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVINSPMGT_vidCalibration_18                               */
/* !Description :  Ce bloc contient la calibration des consignes VVT du mode  */
/*                 18.  Le calcul de ce bloc est effectué seulement si le mode*/
/*                 associé est activé.                                        */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02166_027.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint8 VlvSys_agCkOpInCal18_C;                                       */
/*  output sint8 VlvSys_agCkOpInCal18;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVINSPMGT_vidCalibration_18(void)
{
   VlvSys_agCkOpInCal18 = VlvSys_agCkOpInCal18_C;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVINSPMGT_vidVectorize_Calibs                             */
/* !Description :  Ce bloc permet de concaténer sur un seul flux l'ensemble   */
/*                 des consignes VVT issues des cartographies.                */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02166_028.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint8 VlvSys_agCkOpInCal1;                                          */
/*  input sint8 VlvSys_agCkOpInCal2;                                          */
/*  input sint8 VlvSys_agCkOpInCal3;                                          */
/*  input sint8 VlvSys_agCkOpInCal4;                                          */
/*  input sint8 VlvSys_agCkOpInCal5;                                          */
/*  input sint8 VlvSys_agCkOpInCal6;                                          */
/*  input sint8 VlvSys_agCkOpInCal7;                                          */
/*  input sint8 VlvSys_agCkOpInCal8;                                          */
/*  input sint8 VlvSys_agCkOpInCal9;                                          */
/*  input sint8 VlvSys_agCkOpInCal10;                                         */
/*  input sint8 VlvSys_agCkOpInCal11;                                         */
/*  input sint8 VlvSys_agCkOpInCal12;                                         */
/*  input sint8 VlvSys_agCkOpInCal13;                                         */
/*  input sint8 VlvSys_agCkOpInCal14;                                         */
/*  input sint8 VlvSys_agCkOpInCal15;                                         */
/*  input sint8 VlvSys_agCkOpInCal16;                                         */
/*  input sint8 VlvSys_agCkOpInCal17;                                         */
/*  input sint8 VlvSys_agCkOpInCal18;                                         */
/*  output sint8 VlvSys_prm_agCkOpInCal[18];                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVINSPMGT_vidVectorize_Calibs(void)
{
   VlvSys_prm_agCkOpInCal[0] = VlvSys_agCkOpInCal1;
   VlvSys_prm_agCkOpInCal[1] = VlvSys_agCkOpInCal2;
   VlvSys_prm_agCkOpInCal[2] = VlvSys_agCkOpInCal3;
   VlvSys_prm_agCkOpInCal[3] = VlvSys_agCkOpInCal4;
   VlvSys_prm_agCkOpInCal[4] = VlvSys_agCkOpInCal5;
   VlvSys_prm_agCkOpInCal[5] = VlvSys_agCkOpInCal6;
   VlvSys_prm_agCkOpInCal[6] = VlvSys_agCkOpInCal7;
   VlvSys_prm_agCkOpInCal[7] = VlvSys_agCkOpInCal8;
   VlvSys_prm_agCkOpInCal[8] = VlvSys_agCkOpInCal9;
   VlvSys_prm_agCkOpInCal[9] = VlvSys_agCkOpInCal10;
   VlvSys_prm_agCkOpInCal[10] = VlvSys_agCkOpInCal11;
   VlvSys_prm_agCkOpInCal[11] = VlvSys_agCkOpInCal12;
   VlvSys_prm_agCkOpInCal[12] = VlvSys_agCkOpInCal13;
   VlvSys_prm_agCkOpInCal[13] = VlvSys_agCkOpInCal14;
   VlvSys_prm_agCkOpInCal[14] = VlvSys_agCkOpInCal15;
   VlvSys_prm_agCkOpInCal[15] = VlvSys_agCkOpInCal16;
   VlvSys_prm_agCkOpInCal[16] = VlvSys_agCkOpInCal17;
   VlvSys_prm_agCkOpInCal[17] = VlvSys_agCkOpInCal18;
}

/*---------------------------------end of file--------------------------------*/