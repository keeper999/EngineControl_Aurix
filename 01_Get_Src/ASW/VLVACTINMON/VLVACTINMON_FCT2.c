/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINMON                                             */
/* !Description     : VLVACTINMON component                                   */
/*                                                                            */
/* !Module          : VLVACTINMON                                             */
/* !Description     : DIAGNOSTIC FONCTIONNEL DE LA VVT ADMISSION              */
/*                                                                            */
/* !File            : VLVACTINMON_FCT2.C                                      */
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
/*   1 / VLVACTINMON_vidHotDiagComp                                           */
/*   2 / VLVACTINMON_vidHotDiagActCond                                        */
/*   3 / VLVACTINMON_vidHotDiagCalc                                           */
/*   4 / VLVACTINMON_vidHotDefServoDet                                        */
/*   5 / VLVACTINMON_vidFstHotTempTest                                        */
/*   6 / VLVACTINMON_vidSndHotTempTest                                        */
/*   7 / VLVACTINMON_vidThrdHotTemp                                           */
/*                                                                            */
/* !Reference   : V02 NT 09 06381 / 05                                        */
/* !OtherRefs   : VEMS V02 ECU#055138                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINMON/VLVACTINMON$*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   04 Jul 2011 $*/
/* $Author::   HHAMLAOU                               $$Date::   04 Jul 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTINMON.h"
#include "VLVACTINMON_L.h"
#include "VLVACTINMON_IM.h"
#include "GDGAR.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidHotDiagComp                                 */
/* !Description :  Ce bloc vérifie le temps de réponse de la VVT admission à  */
/*                 chaud                                                      */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINMON_vidHotDiagActCond();                         */
/*  extf argret void VLVACTINMON_vidHotDiagCalc();                            */
/*  input boolean VlvAct_bAcvInHotFctDg;                                      */
/*  input boolean VlvAct_bInVlvSpAmpVarldc;                                   */
/*  input boolean VlvAct_bMonRunInHotFctDg;                                   */
/*  input boolean VLVACTINMON_bAcvInHotFctDg;                                 */
/*  output boolean VlvAct_bMonRunInHotFctDg;                                  */
/*  output boolean VLVACTINMON_bAcvInHotFctDg;                                */
/*  output boolean VLVACTINMON_bAcvInHotFctDgPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidHotDiagComp(void)
{
   VLVACTINMON_vidHotDiagActCond();
   VlvAct_bMonRunInHotFctDg = VlvAct_bAcvInHotFctDg;
   if (  (VlvAct_bAcvInHotFctDg != 0)
      && (VlvAct_bInVlvSpAmpVarldc != 0))
   {
      VLVACTINMON_bAcvInHotFctDg = 1;
   }
   else
   {
      VLVACTINMON_bAcvInHotFctDg = 0;
   }
   if (VlvAct_bMonRunInHotFctDg != 0)
   {
      VLVACTINMON_vidHotDiagCalc();
   }
   VLVACTINMON_bAcvInHotFctDgPrev = VLVACTINMON_bAcvInHotFctDg;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidHotDiagActCond                              */
/* !Description :  Ce bloc calcule l’activation du diagnostic fonctionnel     */
/*                 temps de réponse à chaud de la VVT admission               */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_09_06381_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean VlvAct_bAcvInServo;                                         */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input uint16 VlvAct_nEngMinInVlv_C;                                       */
/*  input sint16 VlvAct_tOilMinInVlv_C;                                       */
/*  input uint8 VlvAct_agInVlvAmp;                                            */
/*  input uint8 VlvAct_agInVlvAmpThdMinH_C;                                   */
/*  output boolean VlvAct_bAcvInHotFctDg;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidHotDiagActCond(void)
{
   boolean bLocalVlvAct_bAcvInServo;
   boolean bLocalInhVlvActInMon;
   uint16  u16LocalExt_nEng;
   sint16  s16LocalEng_tOilEstim;


   VEMS_vidGET(VlvAct_bAcvInServo, bLocalVlvAct_bAcvInServo);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);
   s16LocalEng_tOilEstim = (sint16)(s16LocalEng_tOilEstim / 4);
   bLocalInhVlvActInMon = GDGAR_bGetFRM(FRM_FRM_INHVLVACTINMON);
   if (  (bLocalVlvAct_bAcvInServo != 0)
      && (u16LocalExt_nEng > VlvAct_nEngMinInVlv_C)
      && (s16LocalEng_tOilEstim > VlvAct_tOilMinInVlv_C)
      && (VlvAct_agInVlvAmp > VlvAct_agInVlvAmpThdMinH_C)
      && (bLocalInhVlvActInMon == 0))
   {
      VlvAct_bAcvInHotFctDg = 1;
   }
   else
   {
      VlvAct_bAcvInHotFctDg = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidHotDiagCalc                                 */
/* !Description :  Ce bloc calcule le diagnostic fonctionnel temps de réponse */
/*                 à chaud de la VVT admission                                */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINMON_vidHotDefServoDet();                         */
/*  input boolean VlvAct_bIn1AgDftH;                                          */
/*  input boolean VlvAct_bIn2AgDftH;                                          */
/*  input boolean VlvAct_bIn3AgDftH;                                          */
/*  output boolean VlvAct_bDgoDftHVlvActIn;                                   */
/*  output boolean VlvAct_bDgoSlowH1VlvActIn;                                 */
/*  output boolean VlvAct_bDgoSlowH2VlvActIn;                                 */
/*  output boolean VlvAct_bDgoORngHVlvActIn;                                  */
/*  output boolean VlvAct_bDgoCmdHVlvActIn;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidHotDiagCalc(void)
{
   VLVACTINMON_vidHotDefServoDet();
   if (  (VlvAct_bIn1AgDftH != 0)
      || (VlvAct_bIn2AgDftH != 0)
      || (VlvAct_bIn3AgDftH != 0))
   {
      VlvAct_bDgoDftHVlvActIn = 1;
   }
   else
   {
      VlvAct_bDgoDftHVlvActIn = 0;
   }

   if (  (VlvAct_bIn1AgDftH != 0)
      && (VlvAct_bIn2AgDftH == 0)
      && (VlvAct_bIn3AgDftH == 0))
   {
      VlvAct_bDgoSlowH1VlvActIn = 1;
   }
   else
   {
      VlvAct_bDgoSlowH1VlvActIn = 0;
   }

   if (  (VlvAct_bIn1AgDftH != 0)
      && (VlvAct_bIn2AgDftH != 0)
      && (VlvAct_bIn3AgDftH == 0))
   {
      VlvAct_bDgoSlowH2VlvActIn = 1;
   }
   else
   {
      VlvAct_bDgoSlowH2VlvActIn = 0;
   }

   if (VlvAct_bIn3AgDftH != 0)
   {
      VlvAct_bDgoORngHVlvActIn = 1;
   }
   else
   {
      VlvAct_bDgoORngHVlvActIn = 0;
   }

   if (  (VlvAct_bIn1AgDftH == 0)
      && (VlvAct_bIn2AgDftH != 0)
      && (VlvAct_bIn3AgDftH == 0))
   {
      VlvAct_bDgoCmdHVlvActIn = 1;
   }
   else
   {
      VlvAct_bDgoCmdHVlvActIn = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidHotDefServoDet                              */
/* !Description :  Ce bloc calcule la valeur absolue de la différence entre   */
/*                 l'angle mesurée et l’angle de consigne à chaud de la VVT   */
/*                 admission                                                  */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_09_06381_006.01                                     */
/*                 VEMS_R_09_06381_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINMON_vidFstHotTempTest();                         */
/*  extf argret void VLVACTINMON_vidSndHotTempTest();                         */
/*  extf argret void VLVACTINMON_vidThrdHotTemp();                            */
/*  input boolean VlvAct_bAcvInHotFctDg1AgRead;                               */
/*  input boolean VlvAct_bAcvInHotFctDg2AgRead;                               */
/*  input boolean VlvAct_bAcvInHotFctDg3AgRead;                               */
/*  input uint8 VlvAct_nInVlvAmpH_C;                                          */
/*  input uint8 VlvAct_agInVlvAmp;                                            */
/*  input uint8 VlvAct_tiOfsInVlvH_C;                                         */
/*  input boolean VLVACTINMON_bAcvInHotFctDgPrev;                             */
/*  input boolean VLVACTINMON_bAcvInHotFctDg;                                 */
/*  input uint8 VlvAct_tiDlyInVlvH1;                                          */
/*  input uint8 VLVACTINMON_u8Timer4;                                         */
/*  input uint8 VlvAct_tiDlyInVlvH2;                                          */
/*  input uint8 VLVACTINMON_u8Timer5;                                         */
/*  input uint8 VlvAct_tiDlyInVlvH3;                                          */
/*  input uint8 VLVACTINMON_u8Timer6;                                         */
/*  output uint8 VlvAct_tiDlyInVlvH1;                                         */
/*  output uint8 VLVACTINMON_u8Timer4;                                        */
/*  output boolean VlvAct_bAcvInHotFctDg1AgRead;                              */
/*  output uint8 VlvAct_tiDlyInVlvH2;                                         */
/*  output uint8 VLVACTINMON_u8Timer5;                                        */
/*  output boolean VlvAct_bAcvInHotFctDg2AgRead;                              */
/*  output uint8 VlvAct_tiDlyInVlvH3;                                         */
/*  output uint8 VLVACTINMON_u8Timer6;                                        */
/*  output boolean VlvAct_bAcvInHotFctDg3AgRead;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidHotDefServoDet(void)
{
   boolean bLocalTimeOut1Prev;
   boolean bLocalTimeOut2Prev;
   boolean bLocalTimeOut3Prev;
   uint16  u16LocalTimer5;
   uint16  u16LocalTimer6;
   uint32  u32LocalTimer4;


   bLocalTimeOut1Prev = VlvAct_bAcvInHotFctDg1AgRead;
   bLocalTimeOut2Prev = VlvAct_bAcvInHotFctDg2AgRead;
   bLocalTimeOut3Prev = VlvAct_bAcvInHotFctDg3AgRead;
   if (VlvAct_nInVlvAmpH_C == 0)
   {
      VlvAct_tiDlyInVlvH1 = 255;
   }
   else
   {
      u32LocalTimer4 = ( (VlvAct_agInVlvAmp * 75)
                       / VlvAct_nInVlvAmpH_C)
                     + VlvAct_tiOfsInVlvH_C;
      VlvAct_tiDlyInVlvH1 = (uint8)(MATHSRV_udtMIN(u32LocalTimer4, 255));
   }
   if (  (VLVACTINMON_bAcvInHotFctDgPrev == 0)
      && (VLVACTINMON_bAcvInHotFctDg != 0))
   {
      VLVACTINMON_u8Timer4 = VlvAct_tiDlyInVlvH1;
      if (VLVACTINMON_u8Timer4 == 0)
      {
         VlvAct_bAcvInHotFctDg1AgRead = 1;
         if (bLocalTimeOut1Prev == 0)
         {
            VLVACTINMON_vidFstHotTempTest();
         }
      }
      else
      {
         VlvAct_bAcvInHotFctDg1AgRead = 0;
      }
   }
   else
   {
      if (VLVACTINMON_u8Timer4 > 0)
      {
         VLVACTINMON_u8Timer4 = (uint8)(VLVACTINMON_u8Timer4 - 1);
         if (VLVACTINMON_u8Timer4 == 0)
         {
            VlvAct_bAcvInHotFctDg1AgRead = 1;
            if (bLocalTimeOut1Prev == 0)
            {
               VLVACTINMON_vidFstHotTempTest();
            }
         }
         else
         {
            VlvAct_bAcvInHotFctDg1AgRead = 0;
         }
      }
   }

   u16LocalTimer5 = (uint16)(VlvAct_tiOfsInVlvH_C + VlvAct_tiDlyInVlvH1);
   VlvAct_tiDlyInVlvH2 = (uint8)(MATHSRV_udtMIN(u16LocalTimer5, 255));
   if (  (VLVACTINMON_bAcvInHotFctDgPrev == 0)
      && (VLVACTINMON_bAcvInHotFctDg != 0))
   {
      VLVACTINMON_u8Timer5 = VlvAct_tiDlyInVlvH2;
      if (VLVACTINMON_u8Timer5 == 0)
      {
         VlvAct_bAcvInHotFctDg2AgRead = 1;
         if (bLocalTimeOut2Prev == 0)
         {
            VLVACTINMON_vidSndHotTempTest();
         }
      }
      else
      {
         VlvAct_bAcvInHotFctDg2AgRead = 0;
      }
   }
   else
   {
      if (VLVACTINMON_u8Timer5 > 0)
      {
         VLVACTINMON_u8Timer5 = (uint8)(VLVACTINMON_u8Timer5 - 1);
         if (VLVACTINMON_u8Timer5 == 0)
         {
            VlvAct_bAcvInHotFctDg2AgRead = 1;
            if (bLocalTimeOut2Prev == 0)
            {
               VLVACTINMON_vidSndHotTempTest();
            }
         }
         else
         {
            VlvAct_bAcvInHotFctDg2AgRead = 0;
         }
      }
   }

   u16LocalTimer6 = (uint16)(VlvAct_tiOfsInVlvH_C + VlvAct_tiDlyInVlvH2);
   VlvAct_tiDlyInVlvH3 = (uint8)(MATHSRV_udtMIN(u16LocalTimer6, 255));
   if (  (VLVACTINMON_bAcvInHotFctDgPrev == 0)
      && (VLVACTINMON_bAcvInHotFctDg != 0))
   {
      VLVACTINMON_u8Timer6 = VlvAct_tiDlyInVlvH3;
      if (VLVACTINMON_u8Timer6 == 0)
      {
         VlvAct_bAcvInHotFctDg3AgRead = 1;
         if (bLocalTimeOut3Prev == 0)
         {
            VLVACTINMON_vidThrdHotTemp();
         }
      }
      else
      {
         VlvAct_bAcvInHotFctDg3AgRead = 0;
      }
   }
   else
   {
      if (VLVACTINMON_u8Timer6 > 0)
      {
         VLVACTINMON_u8Timer6 = (uint8)(VLVACTINMON_u8Timer6 - 1);
         if (VLVACTINMON_u8Timer6 == 0)
         {
            VlvAct_bAcvInHotFctDg3AgRead = 1;
            if (bLocalTimeOut3Prev == 0)
            {
               VLVACTINMON_vidThrdHotTemp();
            }
         }
         else
         {
            VlvAct_bAcvInHotFctDg3AgRead = 0;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidFstHotTempTest                              */
/* !Description :  Ce bloc compare la différence entre l'angle mesurée et     */
/*                 l'angle de consigne à un seuil maximal d'écart de boucle   */
/*                 pour le premier test de temporisation à chaud              */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_agCkOpInVlvEstimRef0;                                    */
/*  input uint8 VlvSys_agCkOpInVlvReqRef0;                                    */
/*  input sint8 VlvAct_agInVlvH1;                                             */
/*  input uint8 VlvAct_agInVlvDifH1;                                          */
/*  input uint8 VlvAct_agInVlvDifThdMax_C;                                    */
/*  output sint8 VlvAct_agInVlvH1;                                            */
/*  output uint8 VlvAct_agInVlvDifH1;                                         */
/*  output boolean VlvAct_bIn1AgDftH;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidFstHotTempTest(void)
{
   uint8  u8LocalVlvSys_agCkOpInVlvReqRef0;
   sint8  s8LocalCalc;
   sint16 s16LocalDiff;
   sint16 s16LocalExt_agCkOpInVlvEstimRef0;
   sint16 s16LocalVlvAct_agInVlvH1;


   VEMS_vidGET(Ext_agCkOpInVlvEstimRef0, s16LocalExt_agCkOpInVlvEstimRef0);
   VEMS_vidGET(VlvSys_agCkOpInVlvReqRef0, u8LocalVlvSys_agCkOpInVlvReqRef0);

   if (s16LocalExt_agCkOpInVlvEstimRef0 >= 0)
   {
      s16LocalVlvAct_agInVlvH1 =
         (sint16)((s16LocalExt_agCkOpInVlvEstimRef0 + 4) / 8);
   }
   else
   {
      s16LocalVlvAct_agInVlvH1 =
         (sint16)((s16LocalExt_agCkOpInVlvEstimRef0 - 4) / 8);
   }
   VlvAct_agInVlvH1 =
      (sint8)MATHSRV_udtCLAMP(s16LocalVlvAct_agInVlvH1, -128, 127);

   s8LocalCalc = (sint8)(u8LocalVlvSys_agCkOpInVlvReqRef0 - 128);
   s16LocalDiff = (sint16)(VlvAct_agInVlvH1 - s8LocalCalc);
   VlvAct_agInVlvDifH1 = (uint8)MATHSRV_udtABS(s16LocalDiff);

   if (VlvAct_agInVlvDifH1 > VlvAct_agInVlvDifThdMax_C)
   {
      VlvAct_bIn1AgDftH = 1;
   }
   else
   {
      VlvAct_bIn1AgDftH = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidSndHotTempTest                              */
/* !Description :  Ce bloc compare la différence entre l'angle mesurée et     */
/*                 l'angle de consigne à un seuil maximal d'écart de boucle   */
/*                 pour le deuxième test de temporisation à chaud             */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_agCkOpInVlvEstimRef0;                                    */
/*  input uint8 VlvSys_agCkOpInVlvReqRef0;                                    */
/*  input sint8 VlvAct_agInVlvH2;                                             */
/*  input uint8 VlvAct_agInVlvDifH2;                                          */
/*  input uint8 VlvAct_agInVlvDifThdMax_C;                                    */
/*  output sint8 VlvAct_agInVlvH2;                                            */
/*  output uint8 VlvAct_agInVlvDifH2;                                         */
/*  output boolean VlvAct_bIn2AgDftH;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidSndHotTempTest(void)
{
   uint8  u8LocalVlvSys_agCkOpInVlvReqRef0;
   sint8  s8LocalCalc;
   sint16 s16LocalDiff;
   sint16 s16LocalExt_agCkOpInVlvEstimRef0;
   sint16 s16LocalVlvAct_agInVlvH2;


   VEMS_vidGET(Ext_agCkOpInVlvEstimRef0, s16LocalExt_agCkOpInVlvEstimRef0);
   VEMS_vidGET(VlvSys_agCkOpInVlvReqRef0, u8LocalVlvSys_agCkOpInVlvReqRef0);

   if (s16LocalExt_agCkOpInVlvEstimRef0 >= 0)
   {
      s16LocalVlvAct_agInVlvH2 =
         (sint16)((s16LocalExt_agCkOpInVlvEstimRef0 + 4) / 8);
   }
   else
   {
      s16LocalVlvAct_agInVlvH2 =
         (sint16)((s16LocalExt_agCkOpInVlvEstimRef0 - 4) / 8);
   }
   VlvAct_agInVlvH2 =
      (sint8)MATHSRV_udtCLAMP(s16LocalVlvAct_agInVlvH2, -128, 127);

   s8LocalCalc = (sint8)(u8LocalVlvSys_agCkOpInVlvReqRef0 - 128);
   s16LocalDiff = (sint16)(VlvAct_agInVlvH2 - s8LocalCalc);
   VlvAct_agInVlvDifH2 = (uint8)MATHSRV_udtABS(s16LocalDiff);

   if (VlvAct_agInVlvDifH2 > VlvAct_agInVlvDifThdMax_C)
   {
      VlvAct_bIn2AgDftH = 1;
   }
   else
   {
      VlvAct_bIn2AgDftH = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidThrdHotTemp                                 */
/* !Description :  Ce bloc compare la différence entre l'angle mesurée et     */
/*                 l'angle de consigne à un seuil maximal d'écart de boucle   */
/*                 pour le troisième test de temporisation à froid            */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_agCkOpInVlvEstimRef0;                                    */
/*  input uint8 VlvSys_agCkOpInVlvReqRef0;                                    */
/*  input sint8 VlvAct_agInVlvH3;                                             */
/*  input uint8 VlvAct_agInVlvDifH3;                                          */
/*  input uint8 VlvAct_agInVlvDifThdMax_C;                                    */
/*  output sint8 VlvAct_agInVlvH3;                                            */
/*  output uint8 VlvAct_agInVlvDifH3;                                         */
/*  output boolean VlvAct_bIn3AgDftH;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidThrdHotTemp(void)
{
   uint8  u8LocalVlvSys_agCkOpInVlvReqRef0;
   sint8  s8LocalCalc;
   sint16 s16LocalDiff;
   sint16 s16LocalExt_agCkOpInVlvEstimRef0;
   sint16 s16LocalVlvAct_agInVlvH3;


   VEMS_vidGET(Ext_agCkOpInVlvEstimRef0, s16LocalExt_agCkOpInVlvEstimRef0);
   VEMS_vidGET(VlvSys_agCkOpInVlvReqRef0, u8LocalVlvSys_agCkOpInVlvReqRef0);

   if (s16LocalExt_agCkOpInVlvEstimRef0 >= 0)
   {
      s16LocalVlvAct_agInVlvH3 =
         (sint16)((s16LocalExt_agCkOpInVlvEstimRef0 + 4) / 8);
   }
   else
   {
      s16LocalVlvAct_agInVlvH3 =
         (sint16)((s16LocalExt_agCkOpInVlvEstimRef0 - 4) / 8);
   }

   VlvAct_agInVlvH3 =
      (sint8)MATHSRV_udtCLAMP(s16LocalVlvAct_agInVlvH3, -128, 127);

   s8LocalCalc = (sint8)(u8LocalVlvSys_agCkOpInVlvReqRef0 - 128);
   s16LocalDiff = (sint16)(VlvAct_agInVlvH3 - s8LocalCalc);
   VlvAct_agInVlvDifH3 = (uint8)MATHSRV_udtABS(s16LocalDiff);

   if (VlvAct_agInVlvDifH3 > VlvAct_agInVlvDifThdMax_C)
   {
      VlvAct_bIn3AgDftH = 1;
   }
   else
   {
      VlvAct_bIn3AgDftH = 0;
   }
}
/*--------------------------------- end of file ------------------------------*/