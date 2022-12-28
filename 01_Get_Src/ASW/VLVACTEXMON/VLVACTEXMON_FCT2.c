/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXMON                                             */
/* !Description     : VLVACTEXMON component                                   */
/*                                                                            */
/* !Module          : VLVACTEXMON                                             */
/* !Description     : DIAGNOSTIC FONCTIONNEL DE LA VVT ÉCHAPPEMENT            */
/*                                                                            */
/* !File            : VLVACTEXMON_FCT2.C                                      */
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
/*   1 / VLVACTEXMON_vidHotDiagComp                                           */
/*   2 / VLVACTEXMON_vidHotDiagActCond                                        */
/*   3 / VLVACTEXMON_vidHotDiagCalc                                           */
/*   4 / VLVACTEXMON_vidHotDefServoDet                                        */
/*   5 / VLVACTEXMON_vidFstHotTempTest                                        */
/*   6 / VLVACTEXMON_vidSndHotTempTest                                        */
/*   7 / VLVACTEXMON_vidThrdHotTemp                                           */
/*                                                                            */
/* !Reference   : V02 NT 09 06481 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#055118                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXMON/VLVACTEXMON$*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   05 Jul 2011 $*/
/* $Author::   HHAMLAOU                               $$Date::   05 Jul 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTEXMON.h"
#include "VLVACTEXMON_L.h"
#include "VLVACTEXMON_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidHotDiagComp                                 */
/* !Description :  Ce bloc vérifie le temps de réponse de la VVT échappement à*/
/*                 chaud                                                      */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXMON_vidHotDiagActCond();                         */
/*  extf argret void VLVACTEXMON_vidHotDiagCalc();                            */
/*  input boolean VlvAct_bAcvExHotFctDg;                                      */
/*  input boolean VlvAct_bExVlvSpAmpVarldc;                                   */
/*  input boolean VlvAct_bMonRunExHotFctDg;                                   */
/*  input boolean VLVACTEXMON_bAcvExHotFctDg;                                 */
/*  output boolean VlvAct_bMonRunExHotFctDg;                                  */
/*  output boolean VLVACTEXMON_bAcvExHotFctDg;                                */
/*  output boolean VLVACTEXMON_bAcvExHotFctDgPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidHotDiagComp(void)
{
   VLVACTEXMON_vidHotDiagActCond();
   VlvAct_bMonRunExHotFctDg = VlvAct_bAcvExHotFctDg;
   if (  (VlvAct_bAcvExHotFctDg != 0)
      && (VlvAct_bExVlvSpAmpVarldc != 0))
   {
      VLVACTEXMON_bAcvExHotFctDg = 1;
   }
   else
   {
      VLVACTEXMON_bAcvExHotFctDg = 0;
   }
   if (VlvAct_bMonRunExHotFctDg != 0)
   {
      VLVACTEXMON_vidHotDiagCalc();
   }
   VLVACTEXMON_bAcvExHotFctDgPrev = VLVACTEXMON_bAcvExHotFctDg;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidHotDiagActCond                              */
/* !Description :  Ce bloc calcule l’activation du diagnostic fonctionnel     */
/*                 temps de réponse à chaud de la VVT échappement             */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_09_06481_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean VlvAct_bAcvExServo;                                         */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input uint16 VlvAct_nEngMinExVlv_C;                                       */
/*  input sint16 VlvAct_tOilMinExVlv_C;                                       */
/*  input uint8 VlvAct_agExVlvAmp;                                            */
/*  input uint8 VlvAct_agExVlvAmpThdMinH_C;                                   */
/*  output boolean VlvAct_bAcvExHotFctDg;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidHotDiagActCond(void)
{
   boolean bLocalVlvAct_bAcvExServo;
   boolean bLocalInhVlvActExMon;
   uint16  u16LocalExt_nEng;
   sint16  s16LocalEng_tOilEstim;


   VEMS_vidGET(VlvAct_bAcvExServo, bLocalVlvAct_bAcvExServo);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);
   s16LocalEng_tOilEstim = (sint16)(s16LocalEng_tOilEstim / 4);
   bLocalInhVlvActExMon = GDGAR_bGetFRM(FRM_FRM_INHVLVACTEXMON);
   if (  (bLocalVlvAct_bAcvExServo != 0)
      && (u16LocalExt_nEng > VlvAct_nEngMinExVlv_C)
      && (s16LocalEng_tOilEstim > VlvAct_tOilMinExVlv_C)
      && (VlvAct_agExVlvAmp > VlvAct_agExVlvAmpThdMinH_C)
      && (bLocalInhVlvActExMon == 0))
   {
      VlvAct_bAcvExHotFctDg = 1;
   }
   else
   {
      VlvAct_bAcvExHotFctDg = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidHotDiagCalc                                 */
/* !Description :  Ce bloc calcule le diagnostic fonctionnel temps de réponse */
/*                 à chaud de la VVT échappement                              */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXMON_vidHotDefServoDet();                         */
/*  input boolean VlvAct_bEx1AgDftH;                                          */
/*  input boolean VlvAct_bEx2AgDftH;                                          */
/*  input boolean VlvAct_bEx3AgDftH;                                          */
/*  output boolean VlvAct_bDgoDftHVlvActEx;                                   */
/*  output boolean VlvAct_bDgoSlowH1VlvActEx;                                 */
/*  output boolean VlvAct_bDgoSlowH2VlvActEx;                                 */
/*  output boolean VlvAct_bDgoORngHVlvActEx;                                  */
/*  output boolean VlvAct_bDgoCmdHVlvActEx;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidHotDiagCalc(void)
{
   VLVACTEXMON_vidHotDefServoDet();
   if (  (VlvAct_bEx1AgDftH != 0)
      || (VlvAct_bEx2AgDftH != 0)
      || (VlvAct_bEx3AgDftH != 0))
   {
      VlvAct_bDgoDftHVlvActEx = 1;
   }
   else
   {
      VlvAct_bDgoDftHVlvActEx = 0;
   }

   if (  (VlvAct_bEx1AgDftH != 0)
      && (VlvAct_bEx2AgDftH == 0)
      && (VlvAct_bEx3AgDftH == 0))
   {
      VlvAct_bDgoSlowH1VlvActEx = 1;
   }
   else
   {
      VlvAct_bDgoSlowH1VlvActEx = 0;
   }

   if (  (VlvAct_bEx1AgDftH != 0)
      && (VlvAct_bEx2AgDftH != 0)
      && (VlvAct_bEx3AgDftH == 0))
   {
      VlvAct_bDgoSlowH2VlvActEx = 1;
   }
   else
   {
      VlvAct_bDgoSlowH2VlvActEx = 0;
   }

   if (VlvAct_bEx3AgDftH != 0)
   {
      VlvAct_bDgoORngHVlvActEx = 1;
   }
   else
   {
      VlvAct_bDgoORngHVlvActEx = 0;
   }

   if (  (VlvAct_bEx1AgDftH == 0)
      && (VlvAct_bEx2AgDftH != 0)
      && (VlvAct_bEx3AgDftH == 0))
   {
      VlvAct_bDgoCmdHVlvActEx = 1;
   }
   else
   {
      VlvAct_bDgoCmdHVlvActEx = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidHotDefServoDet                              */
/* !Description :  Ce bloc calcule la valeur absolue de la différence entre   */
/*                 l'angle mesurée et l’angle de consigne à chaud de la VVT   */
/*                 échappement                                                */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_09_06481_004.02                                     */
/*                 VEMS_R_09_06481_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXMON_vidFstHotTempTest();                         */
/*  extf argret void VLVACTEXMON_vidSndHotTempTest();                         */
/*  extf argret void VLVACTEXMON_vidThrdHotTemp();                            */
/*  input boolean VlvAct_bAcvExHotFctDg1AgRead;                               */
/*  input boolean VlvAct_bAcvExHotFctDg2AgRead;                               */
/*  input boolean VlvAct_bAcvExHotFctDg3AgRead;                               */
/*  input uint8 VlvAct_nExVlvAmpH_C;                                          */
/*  input uint8 VlvAct_agExVlvAmp;                                            */
/*  input uint8 VlvAct_tiOfsExVlvH_C;                                         */
/*  input boolean VLVACTEXMON_bAcvExHotFctDgPrev;                             */
/*  input boolean VLVACTEXMON_bAcvExHotFctDg;                                 */
/*  input uint8 VlvAct_tiDlyExVlvH1;                                          */
/*  input uint8 VLVACTEXMON_u8Timer4;                                         */
/*  input uint8 VlvAct_tiDlyExVlvH2;                                          */
/*  input uint8 VLVACTEXMON_u8Timer5;                                         */
/*  input uint8 VlvAct_tiDlyExVlvH3;                                          */
/*  input uint8 VLVACTEXMON_u8Timer6;                                         */
/*  output uint8 VlvAct_tiDlyExVlvH1;                                         */
/*  output uint8 VLVACTEXMON_u8Timer4;                                        */
/*  output boolean VlvAct_bAcvExHotFctDg1AgRead;                              */
/*  output uint8 VlvAct_tiDlyExVlvH2;                                         */
/*  output uint8 VLVACTEXMON_u8Timer5;                                        */
/*  output boolean VlvAct_bAcvExHotFctDg2AgRead;                              */
/*  output uint8 VlvAct_tiDlyExVlvH3;                                         */
/*  output uint8 VLVACTEXMON_u8Timer6;                                        */
/*  output boolean VlvAct_bAcvExHotFctDg3AgRead;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidHotDefServoDet(void)
{
   boolean bLocalTimeOut1Prev;
   boolean bLocalTimeOut2Prev;
   boolean bLocalTimeOut3Prev;
   uint16  u16LocalTimer5;
   uint16  u16LocalTimer6;
   uint32  u32LocalTimer4;


   bLocalTimeOut1Prev = VlvAct_bAcvExHotFctDg1AgRead;
   bLocalTimeOut2Prev = VlvAct_bAcvExHotFctDg2AgRead;
   bLocalTimeOut3Prev = VlvAct_bAcvExHotFctDg3AgRead;
   if (VlvAct_nExVlvAmpH_C == 0)
   {
      VlvAct_tiDlyExVlvH1 = 255;
   }
   else
   {
      u32LocalTimer4 = ( (VlvAct_agExVlvAmp * 75)
                       / VlvAct_nExVlvAmpH_C)
                     + VlvAct_tiOfsExVlvH_C;
      VlvAct_tiDlyExVlvH1 = (uint8)(MATHSRV_udtMIN(u32LocalTimer4, 255));
   }
   if (  (VLVACTEXMON_bAcvExHotFctDgPrev == 0)
      && (VLVACTEXMON_bAcvExHotFctDg != 0))
   {
      VLVACTEXMON_u8Timer4 = VlvAct_tiDlyExVlvH1;
      if (VLVACTEXMON_u8Timer4 == 0)
      {
         VlvAct_bAcvExHotFctDg1AgRead = 1;
         if (bLocalTimeOut1Prev == 0)
         {
            VLVACTEXMON_vidFstHotTempTest();
         }
      }
      else
      {
         VlvAct_bAcvExHotFctDg1AgRead = 0;
      }
   }
   else
   {
      if (VLVACTEXMON_u8Timer4 > 0)
      {
         VLVACTEXMON_u8Timer4 = (uint8)(VLVACTEXMON_u8Timer4 - 1);
         if (VLVACTEXMON_u8Timer4 == 0)
         {
            VlvAct_bAcvExHotFctDg1AgRead = 1;
            if (bLocalTimeOut1Prev == 0)
            {
               VLVACTEXMON_vidFstHotTempTest();
            }
         }
         else
         {
            VlvAct_bAcvExHotFctDg1AgRead = 0;
         }
      }
   }

   u16LocalTimer5 = (uint16)(VlvAct_tiOfsExVlvH_C + VlvAct_tiDlyExVlvH1);
   VlvAct_tiDlyExVlvH2 = (uint8)(MATHSRV_udtMIN(u16LocalTimer5, 255));
   if (  (VLVACTEXMON_bAcvExHotFctDgPrev == 0)
      && (VLVACTEXMON_bAcvExHotFctDg != 0))
   {
      VLVACTEXMON_u8Timer5 = VlvAct_tiDlyExVlvH2;
      if (VLVACTEXMON_u8Timer5 == 0)
      {
         VlvAct_bAcvExHotFctDg2AgRead = 1;
         if (bLocalTimeOut2Prev == 0)
         {
            VLVACTEXMON_vidSndHotTempTest();
         }
      }
      else
      {
         VlvAct_bAcvExHotFctDg2AgRead = 0;
      }
   }
   else
   {
      if (VLVACTEXMON_u8Timer5 > 0)
      {
         VLVACTEXMON_u8Timer5 = (uint8)(VLVACTEXMON_u8Timer5 - 1);
         if (VLVACTEXMON_u8Timer5 == 0)
         {
            VlvAct_bAcvExHotFctDg2AgRead = 1;
            if (bLocalTimeOut2Prev == 0)
            {
               VLVACTEXMON_vidSndHotTempTest();
            }
         }
         else
         {
            VlvAct_bAcvExHotFctDg2AgRead = 0;
         }
      }
   }

   u16LocalTimer6 = (uint16)(VlvAct_tiOfsExVlvH_C + VlvAct_tiDlyExVlvH2);
   VlvAct_tiDlyExVlvH3 = (uint8)(MATHSRV_udtMIN(u16LocalTimer6, 255));
   if (  (VLVACTEXMON_bAcvExHotFctDgPrev == 0)
      && (VLVACTEXMON_bAcvExHotFctDg != 0))
   {
      VLVACTEXMON_u8Timer6 = VlvAct_tiDlyExVlvH3;
      if (VLVACTEXMON_u8Timer6 == 0)
      {
         VlvAct_bAcvExHotFctDg3AgRead = 1;
         if (bLocalTimeOut3Prev == 0)
         {
            VLVACTEXMON_vidThrdHotTemp();
         }
      }
      else
      {
         VlvAct_bAcvExHotFctDg3AgRead = 0;
      }
   }
   else
   {
      if (VLVACTEXMON_u8Timer6 > 0)
      {
         VLVACTEXMON_u8Timer6 = (uint8)(VLVACTEXMON_u8Timer6 - 1);
         if (VLVACTEXMON_u8Timer6 == 0)
         {
            VlvAct_bAcvExHotFctDg3AgRead = 1;
            if (bLocalTimeOut3Prev == 0)
            {
               VLVACTEXMON_vidThrdHotTemp();
            }
         }
         else
         {
            VlvAct_bAcvExHotFctDg3AgRead = 0;
         }
      }
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidFstHotTempTest                              */
/* !Description :  Ce bloc compare la différence entre l'angle mesurée et     */
/*                 l'angle de consigne à un seuil maximal d'écart de boucle   */
/*                 pour le premier test de temporisation à chaud              */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_agCkClsExVlvEstimRef0;                                   */
/*  input uint8 VlvSys_agCkClsExVlvReqRef0;                                   */
/*  input sint8 VlvAct_agExVlvH1;                                             */
/*  input uint8 VlvAct_agExVlvDifH1;                                          */
/*  input uint8 VlvAct_agExVlvDifThdMax_C;                                    */
/*  output sint8 VlvAct_agExVlvH1;                                            */
/*  output uint8 VlvAct_agExVlvDifH1;                                         */
/*  output boolean VlvAct_bEx1AgDftH;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidFstHotTempTest(void)
{
   uint8  u8LocalVlvSys_agCkClsExVlvReqRf0;
   sint8  s8LocalCalc;
   sint16 s16LocalDiff;
   sint16 s16LocalExt_agCkClsExVlvEstimRf0;
   sint16 s16LocalVlvAct_agExVlvH1;


   VEMS_vidGET(Ext_agCkClsExVlvEstimRef0, s16LocalExt_agCkClsExVlvEstimRf0);
   VEMS_vidGET(VlvSys_agCkClsExVlvReqRef0, u8LocalVlvSys_agCkClsExVlvReqRf0);

   if (s16LocalExt_agCkClsExVlvEstimRf0 >= 0)
   {
      s16LocalVlvAct_agExVlvH1 =
         (sint16)((s16LocalExt_agCkClsExVlvEstimRf0 + 4) / 8);
   }
   else
   {
      s16LocalVlvAct_agExVlvH1 =
         (sint16)((s16LocalExt_agCkClsExVlvEstimRf0 - 4) / 8);
   }
   VlvAct_agExVlvH1 =
      (sint8)MATHSRV_udtCLAMP(s16LocalVlvAct_agExVlvH1, -128, 127);

   s8LocalCalc = (sint8)(u8LocalVlvSys_agCkClsExVlvReqRf0 - 128);
   s16LocalDiff = (sint16)(VlvAct_agExVlvH1 - s8LocalCalc);
   VlvAct_agExVlvDifH1 = (uint8)MATHSRV_udtABS(s16LocalDiff);

   if (VlvAct_agExVlvDifH1 > VlvAct_agExVlvDifThdMax_C)
   {
      VlvAct_bEx1AgDftH = 1;
   }
   else
   {
      VlvAct_bEx1AgDftH = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidSndHotTempTest                              */
/* !Description :  Ce bloc compare la différence entre l'angle mesurée et     */
/*                 l'angle de consigne à un seuil maximal d'écart de boucle   */
/*                 pour le deuxième test de temporisation à chaud             */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_agCkClsExVlvEstimRef0;                                   */
/*  input uint8 VlvSys_agCkClsExVlvReqRef0;                                   */
/*  input sint8 VlvAct_agExVlvH2;                                             */
/*  input uint8 VlvAct_agExVlvDifH2;                                          */
/*  input uint8 VlvAct_agExVlvDifThdMax_C;                                    */
/*  output sint8 VlvAct_agExVlvH2;                                            */
/*  output uint8 VlvAct_agExVlvDifH2;                                         */
/*  output boolean VlvAct_bEx2AgDftH;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidSndHotTempTest(void)
{
   uint8  u8LocalVlvSys_agCkClsExVlvReqRf0;
   sint8  s8LocalCalc;
   sint16 s16LocalDiff;
   sint16 s16LocalExt_agCkClsExVlvEstimRf0;
   sint16 s16LocalVlvAct_agExVlvH2;


   VEMS_vidGET(Ext_agCkClsExVlvEstimRef0, s16LocalExt_agCkClsExVlvEstimRf0);
   VEMS_vidGET(VlvSys_agCkClsExVlvReqRef0, u8LocalVlvSys_agCkClsExVlvReqRf0);

   if (s16LocalExt_agCkClsExVlvEstimRf0 >= 0)
   {
      s16LocalVlvAct_agExVlvH2 =
         (sint16)((s16LocalExt_agCkClsExVlvEstimRf0 + 4) / 8);
   }
   else
   {
      s16LocalVlvAct_agExVlvH2 =
         (sint16)((s16LocalExt_agCkClsExVlvEstimRf0 - 4) / 8);
   }
   VlvAct_agExVlvH2 =
      (sint8)MATHSRV_udtCLAMP(s16LocalVlvAct_agExVlvH2, -128, 127);

   s8LocalCalc = (sint8)(u8LocalVlvSys_agCkClsExVlvReqRf0 - 128);
   s16LocalDiff = (sint16)(VlvAct_agExVlvH2 - s8LocalCalc);
   VlvAct_agExVlvDifH2 = (uint8)MATHSRV_udtABS(s16LocalDiff);

   if (VlvAct_agExVlvDifH2 > VlvAct_agExVlvDifThdMax_C)
   {
      VlvAct_bEx2AgDftH = 1;
   }
   else
   {
      VlvAct_bEx2AgDftH = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidThrdHotTemp                                 */
/* !Description :  Ce bloc compare la différence entre l'angle mesurée et     */
/*                 l'angle de consigne à un seuil maximal d'écart de boucle   */
/*                 pour le troisième test de temporisation à froid            */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_agCkClsExVlvEstimRef0;                                   */
/*  input uint8 VlvSys_agCkClsExVlvReqRef0;                                   */
/*  input sint8 VlvAct_agExVlvH3;                                             */
/*  input uint8 VlvAct_agExVlvDifH3;                                          */
/*  input uint8 VlvAct_agExVlvDifThdMax_C;                                    */
/*  output sint8 VlvAct_agExVlvH3;                                            */
/*  output uint8 VlvAct_agExVlvDifH3;                                         */
/*  output boolean VlvAct_bEx3AgDftH;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidThrdHotTemp(void)
{
   uint8  u8LocalVlvSys_agCkClsExVlvReqRf0;
   sint8  s8LocalCalc;
   sint16 s16LocalDiff;
   sint16 s16LocalExt_agCkClsExVlvEstimRf0;
   sint16 s16LocalVlvAct_agExVlvH3;


   VEMS_vidGET(Ext_agCkClsExVlvEstimRef0, s16LocalExt_agCkClsExVlvEstimRf0);
   VEMS_vidGET(VlvSys_agCkClsExVlvReqRef0, u8LocalVlvSys_agCkClsExVlvReqRf0);

   if (s16LocalExt_agCkClsExVlvEstimRf0 >= 0)
   {
      s16LocalVlvAct_agExVlvH3 =
         (sint16)((s16LocalExt_agCkClsExVlvEstimRf0 + 4) / 8);
   }
   else
   {
      s16LocalVlvAct_agExVlvH3 =
         (sint16)((s16LocalExt_agCkClsExVlvEstimRf0 - 4) / 8);
   }
   VlvAct_agExVlvH3 =
      (sint8)MATHSRV_udtCLAMP(s16LocalVlvAct_agExVlvH3, -128, 127);

   s8LocalCalc = (sint8)(u8LocalVlvSys_agCkClsExVlvReqRf0 - 128);
   s16LocalDiff = (sint16)(VlvAct_agExVlvH3 - s8LocalCalc);
   VlvAct_agExVlvDifH3 = (uint8)MATHSRV_udtABS(s16LocalDiff);

   if (VlvAct_agExVlvDifH3 > VlvAct_agExVlvDifThdMax_C)
   {
      VlvAct_bEx3AgDftH = 1;
   }
   else
   {
      VlvAct_bEx3AgDftH = 0;
   }
}
/*--------------------------------- end of file ------------------------------*/