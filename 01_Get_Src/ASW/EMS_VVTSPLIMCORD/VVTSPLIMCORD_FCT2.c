/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VVTSPLIMCORD                                            */
/* !Description     : VVTSPLIMCORD component.                                 */
/*                                                                            */
/* !Module          : VVTSPLIMCORD                                            */
/* !Description     : OFFSET T3 SOUPAPE                                       */
/*                                                                            */
/* !File            : VVTSPLIMCORD_FCT2.C                                     */
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
/*   1 / VVTSPLIMCORD_vidCalibration_5                                        */
/*   2 / VVTSPLIMCORD_vidCalibration_6                                        */
/*   3 / VVTSPLIMCORD_vidCalibration_7                                        */
/*   4 / VVTSPLIMCORD_vidCalibration_8                                        */
/*   5 / VVTSPLIMCORD_vidCalibration_9                                        */
/*   6 / VVTSPLIMCORD_vidCalibration_10                                       */
/*   7 / VVTSPLIMCORD_vidCalibration_11                                       */
/*   8 / VVTSPLIMCORD_vidCalibration_12                                       */
/*   9 / VVTSPLIMCORD_vidCalibration_13                                       */
/*   10 / VVTSPLIMCORD_vidCalibration_14                                      */
/*                                                                            */
/* !Reference   : V02 NT 11 02903 / 01                                        */
/* !OtherRefs   : 01460_10_01471_2 / 1                                        */
/* !OtherRefs   : VEMS V02 ECU#053815                                         */
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
#include "VVTSPLIMCORD.h"
#include "VVTSPLIMCORD_L.h"
#include "VVTSPLIMCORD_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidCalibration_5                              */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 ExM_nEngCorX_A[8];                                           */
/*  input uint16 ExM_nEngCor;                                                 */
/*  input uint16 ExM_rAirCorY_A[8];                                           */
/*  input uint16 ExM_rAirLdCor;                                               */
/*  input uint8 ExM_tExOfsCal5_M[8][8];                                       */
/*  output sint16 ExM_tExOfsCal5;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidCalibration_5(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(ExM_nEngCorX_A,
                                                    ExM_nEngCor,
                                                    8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(ExM_rAirCorY_A,
                                                    ExM_rAirLdCor,
                                                    8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&ExM_tExOfsCal5_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   ExM_tExOfsCal5 = (sint16)((u8LocalInterp2d - 128) * 32);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidCalibration_6                              */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 ExM_nEngCorX_A[8];                                           */
/*  input uint16 ExM_nEngCor;                                                 */
/*  input uint16 ExM_rAirCorY_A[8];                                           */
/*  input uint16 ExM_rAirLdCor;                                               */
/*  input uint8 ExM_tExOfsCal6_M[8][8];                                       */
/*  output sint16 ExM_tExOfsCal6;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidCalibration_6(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(ExM_nEngCorX_A,
                                                    ExM_nEngCor,
                                                    8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(ExM_rAirCorY_A,
                                                    ExM_rAirLdCor,
                                                    8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&ExM_tExOfsCal6_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   ExM_tExOfsCal6 = (sint16)((u8LocalInterp2d - 128) * 32);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidCalibration_7                              */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 ExM_nEngCorX_A[8];                                           */
/*  input uint16 ExM_nEngCor;                                                 */
/*  input uint16 ExM_rAirCorY_A[8];                                           */
/*  input uint16 ExM_rAirLdCor;                                               */
/*  input uint8 ExM_tExOfsCal7_M[8][8];                                       */
/*  output sint16 ExM_tExOfsCal7;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidCalibration_7(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(ExM_nEngCorX_A,
                                                    ExM_nEngCor,
                                                    8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(ExM_rAirCorY_A,
                                                    ExM_rAirLdCor,
                                                    8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&ExM_tExOfsCal7_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   ExM_tExOfsCal7 = (sint16)((u8LocalInterp2d - 128) * 32);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidCalibration_8                              */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 ExM_nEngCorX_A[8];                                           */
/*  input uint16 ExM_nEngCor;                                                 */
/*  input uint16 ExM_rAirCorY_A[8];                                           */
/*  input uint16 ExM_rAirLdCor;                                               */
/*  input uint8 ExM_tExOfsCal8_M[8][8];                                       */
/*  output sint16 ExM_tExOfsCal8;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidCalibration_8(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(ExM_nEngCorX_A,
                                                    ExM_nEngCor,
                                                    8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(ExM_rAirCorY_A,
                                                    ExM_rAirLdCor,
                                                    8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&ExM_tExOfsCal8_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   ExM_tExOfsCal8 = (sint16)((u8LocalInterp2d - 128) * 32);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidCalibration_9                              */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 ExM_nEngCorX_A[8];                                           */
/*  input uint16 ExM_nEngCor;                                                 */
/*  input uint16 ExM_rAirCorY_A[8];                                           */
/*  input uint16 ExM_rAirLdCor;                                               */
/*  input uint8 ExM_tExOfsCal9_M[8][8];                                       */
/*  output sint16 ExM_tExOfsCal9;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidCalibration_9(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(ExM_nEngCorX_A,
                                                    ExM_nEngCor,
                                                    8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(ExM_rAirCorY_A,
                                                    ExM_rAirLdCor,
                                                    8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&ExM_tExOfsCal9_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   ExM_tExOfsCal9 = (sint16)((u8LocalInterp2d - 128) * 32);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidCalibration_10                             */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 ExM_nEngCorX_A[8];                                           */
/*  input uint16 ExM_nEngCor;                                                 */
/*  input uint16 ExM_rAirCorY_A[8];                                           */
/*  input uint16 ExM_rAirLdCor;                                               */
/*  input uint8 ExM_tExOfsCal10_M[8][8];                                      */
/*  output sint16 ExM_tExOfsCal10;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidCalibration_10(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(ExM_nEngCorX_A,
                                                    ExM_nEngCor,
                                                    8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(ExM_rAirCorY_A,
                                                    ExM_rAirLdCor,
                                                    8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&ExM_tExOfsCal10_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   ExM_tExOfsCal10 = (sint16)((u8LocalInterp2d - 128) * 32);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidCalibration_11                             */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 ExM_nEngCorX_A[8];                                           */
/*  input uint16 ExM_nEngCor;                                                 */
/*  input uint16 ExM_rAirCorY_A[8];                                           */
/*  input uint16 ExM_rAirLdCor;                                               */
/*  input uint8 ExM_tExOfsCal11_M[8][8];                                      */
/*  output sint16 ExM_tExOfsCal11;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidCalibration_11(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(ExM_nEngCorX_A,
                                                    ExM_nEngCor,
                                                    8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(ExM_rAirCorY_A,
                                                    ExM_rAirLdCor,
                                                    8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&ExM_tExOfsCal11_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   ExM_tExOfsCal11 = (sint16)((u8LocalInterp2d - 128) * 32);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidCalibration_12                             */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 ExM_nEngCorX_A[8];                                           */
/*  input uint16 ExM_nEngCor;                                                 */
/*  input uint16 ExM_rAirCorY_A[8];                                           */
/*  input uint16 ExM_rAirLdCor;                                               */
/*  input uint8 ExM_tExOfsCal12_M[8][8];                                      */
/*  output sint16 ExM_tExOfsCal12;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidCalibration_12(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(ExM_nEngCorX_A,
                                                    ExM_nEngCor,
                                                    8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(ExM_rAirCorY_A,
                                                    ExM_rAirLdCor,
                                                    8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&ExM_tExOfsCal12_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   ExM_tExOfsCal12 = (sint16)((u8LocalInterp2d - 128) * 32);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidCalibration_13                             */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_019.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 ExM_nEngCorX_A[8];                                           */
/*  input uint16 ExM_nEngCor;                                                 */
/*  input uint16 ExM_rAirCorY_A[8];                                           */
/*  input uint16 ExM_rAirLdCor;                                               */
/*  input uint8 ExM_tExOfsCal13_M[8][8];                                      */
/*  output sint16 ExM_tExOfsCal13;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidCalibration_13(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(ExM_nEngCorX_A,
                                                    ExM_nEngCor,
                                                    8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(ExM_rAirCorY_A,
                                                    ExM_rAirLdCor,
                                                    8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&ExM_tExOfsCal13_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   ExM_tExOfsCal13 = (sint16)((u8LocalInterp2d - 128) * 32);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidCalibration_14                             */
/* !Description :  Ce bloc contient une des calibrations de la fonction. Ce   */
/*                 scalaire n’est calculé que lorsque le mode de              */
/*                 fonctionnement courant ou celui de consigne nécessite un   */
/*                 appel de cette calibration.                                */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint8 ExM_tExOfsCal14_C;                                            */
/*  output sint16 ExM_tExOfsCal14;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidCalibration_14(void)
{
   ExM_tExOfsCal14 = (sint16)(ExM_tExOfsCal14_C * 32);
}
/*---------------------------------end of file--------------------------------*/