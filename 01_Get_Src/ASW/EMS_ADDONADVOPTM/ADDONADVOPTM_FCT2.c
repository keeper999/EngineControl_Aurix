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
/* !File            : ADDONADVOPTM_FCT2.C                                     */
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
/*   1 / ADDONADVOPTM_vidCalibration_5                                        */
/*   2 / ADDONADVOPTM_vidCalibration_6                                        */
/*   3 / ADDONADVOPTM_vidCalibration_7                                        */
/*   4 / ADDONADVOPTM_vidCalibration_8                                        */
/*   5 / ADDONADVOPTM_vidCalibration_9                                        */
/*   6 / ADDONADVOPTM_vidCalibration_10                                       */
/*   7 / ADDONADVOPTM_vidCalibration_11                                       */
/*   8 / ADDONADVOPTM_vidCalibration_12                                       */
/*   9 / ADDONADVOPTM_vidCalibration_13                                       */
/*   10 / ADDONADVOPTM_vidCalibration_14                                      */
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
/* !Function    :  ADDONADVOPTM_vidCalibration_5                              */
/* !Description :  Cette fonction contient une des cartographies de la        */
/*                 fonction. Il n’est calculé que lorsque le mode de          */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie                      */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgOptm_A[16];                                 */
/*  input uint16 IgSys_rAirLdOfsAgIgOptm_A[16];                               */
/*  input uint8 IgSys_ofsAgIgOptmCal5_M[16][16];                              */
/*  output sint16 IgSys_ofsAgIgOptmCal5;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidCalibration_5(void)
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

   u8LocalInterp2 = MATHSRV_u8Interp2d(&IgSys_ofsAgIgOptmCal5_M[0][0],
                                       u16LocalParaX,
                                       u16LocalParaY,
                                       16);

   IgSys_ofsAgIgOptmCal5 = (sint16)(u8LocalInterp2 - 96);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidCalibration_6                              */
/* !Description :  Cette fonction  contient une des cartographies de la       */
/*                 fonction. Il n’est calculé que lorsque le mode de          */
/*                 fonctionnement  courant ou celui de consigne nécessite une */
/*                 interpolation dans cette cartographie                      */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgOptm_A[16];                                 */
/*  input uint16 IgSys_rAirLdOfsAgIgOptm_A[16];                               */
/*  input uint8 IgSys_ofsAgIgOptmCal6_M[16][16];                              */
/*  output sint16 IgSys_ofsAgIgOptmCal6;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidCalibration_6(void)
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

   u8LocalInterp2 = MATHSRV_u8Interp2d(&IgSys_ofsAgIgOptmCal6_M[0][0],
                                       u16LocalParaX,
                                       u16LocalParaY,
                                       16);

   IgSys_ofsAgIgOptmCal6 = (sint16)(u8LocalInterp2 - 96);
}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidCalibration_7                              */
/* !Description :  Cette  contient une des cartographies de la fonction. Il   */
/*                 n’est calculé que lorsque le mode de fonctionnement        */
/*                 courant ou celui de consigne nécessite une interpolation   */
/*                 dans cette cartographie                                    */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgOptm_A[16];                                 */
/*  input uint16 IgSys_rAirLdOfsAgIgOptm_A[16];                               */
/*  input uint8 IgSys_ofsAgIgOptmCal7_M[16][16];                              */
/*  output sint16 IgSys_ofsAgIgOptmCal7;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidCalibration_7(void)
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

   u8LocalInterp2 = MATHSRV_u8Interp2d(&IgSys_ofsAgIgOptmCal7_M[0][0],
                                       u16LocalParaX,
                                       u16LocalParaY,
                                       16);

   IgSys_ofsAgIgOptmCal7 = (sint16)(u8LocalInterp2 - 96);
}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidCalibration_8                              */
/* !Description :  Cette  contient une des cartographies de la fonction. Il   */
/*                 n’est calculé que lorsque le mode de fonctionnement        */
/*                 courant ou celui de consigne nécessite une interpolation   */
/*                 dans cette cartographie                                    */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgOptm_A[16];                                 */
/*  input uint16 IgSys_rAirLdOfsAgIgOptm_A[16];                               */
/*  input uint8 IgSys_ofsAgIgOptmCal8_M[16][16];                              */
/*  output sint16 IgSys_ofsAgIgOptmCal8;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidCalibration_8(void)
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

   u8LocalInterp2 = MATHSRV_u8Interp2d(&IgSys_ofsAgIgOptmCal8_M[0][0],
                                       u16LocalParaX,
                                       u16LocalParaY,
                                       16);

   IgSys_ofsAgIgOptmCal8 = (sint16)(u8LocalInterp2 - 96);
}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidCalibration_9                              */
/* !Description :  Cette fonction  contient une des cartographies de la       */
/*                 fonction. Il n’est calculé que lorsque le mode de          */
/*                 fonctionnement  courant ou celui de consigne nécessite une */
/*                 interpolation dans cette cartographie                      */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgOptm_A[16];                                 */
/*  input uint16 IgSys_rAirLdOfsAgIgOptm_A[16];                               */
/*  input uint8 IgSys_ofsAgIgOptmCal9_M[16][16];                              */
/*  output sint16 IgSys_ofsAgIgOptmCal9;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidCalibration_9(void)
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

   u8LocalInterp2 = MATHSRV_u8Interp2d(&IgSys_ofsAgIgOptmCal9_M[0][0],
                                       u16LocalParaX,
                                       u16LocalParaY,
                                       16);

   IgSys_ofsAgIgOptmCal9 = (sint16)(u8LocalInterp2 - 96);
}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidCalibration_10                             */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement        */
/*                 courant ou celui de consigne nécessite une interpolation   */
/*                 dans cette cartographie                                    */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgOptm_A[16];                                 */
/*  input uint16 IgSys_rAirLdOfsAgIgOptm_A[16];                               */
/*  input uint8 IgSys_ofsAgIgOptmCal10_M[16][16];                             */
/*  output sint16 IgSys_ofsAgIgOptmCal10;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidCalibration_10(void)
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

   u8LocalInterp2 = MATHSRV_u8Interp2d(&IgSys_ofsAgIgOptmCal10_M[0][0],
                                       u16LocalParaX,
                                       u16LocalParaY,
                                       16);

   IgSys_ofsAgIgOptmCal10 = (sint16)(u8LocalInterp2 - 96);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidCalibration_11                             */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnemen courant */
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie                                               */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgOptmShoIdl_A[8];                            */
/*  input uint16 IgSys_rAirLdOfsAgIgOptmShoIdl_A[8];                          */
/*  input uint8 IgSys_ofsAgIgOptmCal11_M[8][8];                               */
/*  output sint16 IgSys_ofsAgIgOptmCal11;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidCalibration_11(void)
{
   uint8   u8LocalInterp2;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalEngM_rAirLdCor;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);


   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgOptmShoIdl_A,
                                                u16LocalExt_nEng,
                                                8);


   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgOptmShoIdl_A,
                                                u16LocalEngM_rAirLdCor,
                                                8);

   u8LocalInterp2 = MATHSRV_u8Interp2d(&IgSys_ofsAgIgOptmCal11_M[0][0],
                                       u16LocalParaX,
                                       u16LocalParaY,
                                       8);
   IgSys_ofsAgIgOptmCal11 = (sint16)(u8LocalInterp2 - 96);

}




/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidCalibration_12                             */
/* !Description :  Cette fonction  contient une des cartographies de la       */
/*                 fonction. Il n’est calculé que lorsque le mode de          */
/*                 fonctionnement courant ou celui de consigne nécessite une  */
/*                 interpolation dans cette cartographie                      */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgOptmShoIdl_A[8];                            */
/*  input uint16 IgSys_rAirLdOfsAgIgOptmShoIdl_A[8];                          */
/*  input uint8 IgSys_ofsAgIgOptmCal12_M[8][8];                               */
/*  output sint16 IgSys_ofsAgIgOptmCal12;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidCalibration_12(void)
{
   uint8   u8LocalInterp2;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalEngM_rAirLdCor;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);


   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgOptmShoIdl_A,
                                                u16LocalExt_nEng,
                                                8);


   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgOptmShoIdl_A,
                                                u16LocalEngM_rAirLdCor,
                                                8);

   u8LocalInterp2 = MATHSRV_u8Interp2d(&IgSys_ofsAgIgOptmCal12_M[0][0],
                                       u16LocalParaX,
                                       u16LocalParaY,
                                       8);

   IgSys_ofsAgIgOptmCal12 = (sint16)(u8LocalInterp2 - 96);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidCalibration_13                             */
/* !Description :  Cette fonction  contient une des cartographies de la       */
/*                 fonction. Il n’est calculé que lorsque le mode de          */
/*                 fonctionnement  courant ou celui de consigne nécessite une */
/*                 interpolation dans cette cartographie                      */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_019.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgOptmShoIdl_A[8];                            */
/*  input uint16 IgSys_rAirLdOfsAgIgOptmShoIdl_A[8];                          */
/*  input uint8 IgSys_ofsAgIgOptmCal13_M[8][8];                               */
/*  output sint16 IgSys_ofsAgIgOptmCal13;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidCalibration_13(void)
{
   uint8   u8LocalInterp2;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalEngM_rAirLdCor;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);


   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgOptmShoIdl_A,
                                                u16LocalExt_nEng,
                                                8);


   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgOptmShoIdl_A,
                                                u16LocalEngM_rAirLdCor,
                                                8);

   u8LocalInterp2 = MATHSRV_u8Interp2d(&IgSys_ofsAgIgOptmCal13_M[0][0],
                                       u16LocalParaX,
                                       u16LocalParaY,
                                       8);

   IgSys_ofsAgIgOptmCal13 = (sint16)(u8LocalInterp2 - 96);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidCalibration_14                             */
/* !Description :  Cette fonction contient une des cartographies de la        */
/*                 fonction. Il n’est calculé que lorsque le mode de          */
/*                 fonctionnement  courant ou celui de consigne nécessite une */
/*                 interpolation dans cette cartographie                      */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgOptmShoIdl_A[8];                            */
/*  input uint16 IgSys_rAirLdOfsAgIgOptmShoIdl_A[8];                          */
/*  input uint8 IgSys_ofsAgIgOptmCal14_M[8][8];                               */
/*  output sint16 IgSys_ofsAgIgOptmCal14;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidCalibration_14(void)
{
   uint8   u8LocalInterp2;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalEngM_rAirLdCor;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);


   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgOptmShoIdl_A,
                                                u16LocalExt_nEng,
                                                8);

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgOptmShoIdl_A,
                                                u16LocalEngM_rAirLdCor,
                                                8);

   u8LocalInterp2 = MATHSRV_u8Interp2d(&IgSys_ofsAgIgOptmCal14_M[0][0],
                                       u16LocalParaX,
                                       u16LocalParaY,
                                       8);

   IgSys_ofsAgIgOptmCal14 = (sint16)(u8LocalInterp2 - 96);
}

/*------------------------------end of file-----------------------------------*/