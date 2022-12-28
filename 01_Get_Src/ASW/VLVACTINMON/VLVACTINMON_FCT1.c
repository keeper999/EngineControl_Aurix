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
/* !File            : VLVACTINMON_FCT1.C                                      */
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
/*   1 / VLVACTINMON_vidInitialization                                        */
/*   2 / VLVACTINMON_vidOffsetSetPtComp                                       */
/*   3 / VLVACTINMON_vidInitOffValComp                                        */
/*   4 / VLVACTINMON_vidColdDiagComp                                          */
/*   5 / VLVACTINMON_vidColdDiagActCond                                       */
/*   6 / VLVACTINMON_vidColdDiagCalc                                          */
/*   7 / VLVACTINMON_vidColdDefServoDet                                       */
/*   8 / VLVACTINMON_vidFstColdTempTest                                       */
/*   9 / VLVACTINMON_vidSndColdTempTest                                       */
/*   10 / VLVACTINMON_vidThrdColdTemp                                         */
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
/* !Function    :  VLVACTINMON_vidInitialization                              */
/* !Description :  Initialisation des variables                               */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean VLVACTINMON_bSetPointInPrev;                               */
/*  output uint8 VLVACTINMON_u8CkOpInVlvRef0Prev;                             */
/*  output boolean VLVACTINMON_bAcvInServoPrev;                               */
/*  output boolean VlvAct_bAcvInColdFctDg1AgRead;                             */
/*  output boolean VlvAct_bAcvInColdFctDg2AgRead;                             */
/*  output boolean VlvAct_bAcvInColdFctDg3AgRead;                             */
/*  output boolean VlvAct_bAcvInHotFctDg1AgRead;                              */
/*  output boolean VlvAct_bAcvInHotFctDg2AgRead;                              */
/*  output boolean VlvAct_bAcvInHotFctDg3AgRead;                              */
/*  output boolean VlvAct_bAcvInHotStuckFctDgAgRead;                          */
/*  output boolean VLVACTINMON_bAcvInColdFctDgPrev;                           */
/*  output boolean VLVACTINMON_bAcvInHotFctDgPrev;                            */
/*  output boolean VLVACTINMON_bAcvInHotStkFctDgPrv;                          */
/*  output uint8 VLVACTINMON_u8Timer1;                                        */
/*  output uint8 VLVACTINMON_u8Timer2;                                        */
/*  output uint8 VLVACTINMON_u8Timer3;                                        */
/*  output uint8 VLVACTINMON_u8Timer4;                                        */
/*  output uint8 VLVACTINMON_u8Timer5;                                        */
/*  output uint8 VLVACTINMON_u8Timer6;                                        */
/*  output uint8 VLVACTINMON_u8Timer7;                                        */
/*  output sint8 VlvSys_agCkOpInVlvReqRef0_int;                               */
/*  output uint16 VlvAct_tiInVlvPosStat;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidInitialization(void)
{
   VLVACTINMON_bSetPointInPrev = 0;
   VLVACTINMON_u8CkOpInVlvRef0Prev = 0;
   VLVACTINMON_bAcvInServoPrev = 0;
   VlvAct_bAcvInColdFctDg1AgRead = 0;
   VlvAct_bAcvInColdFctDg2AgRead = 0;
   VlvAct_bAcvInColdFctDg3AgRead = 0;
   VlvAct_bAcvInHotFctDg1AgRead = 0;
   VlvAct_bAcvInHotFctDg2AgRead = 0;
   VlvAct_bAcvInHotFctDg3AgRead = 0;
   VlvAct_bAcvInHotStuckFctDgAgRead = 0;
   VLVACTINMON_bAcvInColdFctDgPrev = 0;
   VLVACTINMON_bAcvInHotFctDgPrev = 0;
   VLVACTINMON_bAcvInHotStkFctDgPrv = 0;
   VLVACTINMON_u8Timer1 = 0;
   VLVACTINMON_u8Timer2 = 0;
   VLVACTINMON_u8Timer3 = 0;
   VLVACTINMON_u8Timer4 = 0;
   VLVACTINMON_u8Timer5 = 0;
   VLVACTINMON_u8Timer6 = 0;
   VLVACTINMON_u8Timer7 = 0;
   VlvSys_agCkOpInVlvReqRef0_int = 0;
   VlvAct_tiInVlvPosStat = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidOffsetSetPtComp                             */
/* !Description :  Ce bloc calcule la valeur de l'offset initiale             */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINMON_vidInitOffValComp();                         */
/*  input uint8 VlvSys_agCkOpInVlvReqRef0;                                    */
/*  input uint8 VLVACTINMON_u8CkOpInVlvRef0Prev;                              */
/*  input boolean VLVACTINMON_bSetPointInPrev;                                */
/*  input sint8 VlvAct_agInVlvIni;                                            */
/*  output boolean VlvAct_bInVlvSpAmpVarldc;                                  */
/*  output uint8 VlvAct_agInVlvAmp;                                           */
/*  output boolean VLVACTINMON_bSetPointInPrev;                               */
/*  output uint8 VLVACTINMON_u8CkOpInVlvRef0Prev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidOffsetSetPtComp(void)
{
   boolean bLocalCall;
   uint8   u8LocalVlvSys_agCkOpInVlvReqRef0;
   sint16  s16LoaclDiff;


   VEMS_vidGET(VlvSys_agCkOpInVlvReqRef0, u8LocalVlvSys_agCkOpInVlvReqRef0);

   if (u8LocalVlvSys_agCkOpInVlvReqRef0 == VLVACTINMON_u8CkOpInVlvRef0Prev)
   {
      bLocalCall = 0;
      VlvAct_bInVlvSpAmpVarldc = 0;
   }
   else
   {
      bLocalCall = 1;
      if (VLVACTINMON_bSetPointInPrev == 0)
      {
         VlvAct_bInVlvSpAmpVarldc = 1;
         VLVACTINMON_vidInitOffValComp();
      }
      else
      {
         VlvAct_bInVlvSpAmpVarldc = 0;
      }
   }

   s16LoaclDiff =
      (sint16)(VlvAct_agInVlvIni - (u8LocalVlvSys_agCkOpInVlvReqRef0 - 128));
   VlvAct_agInVlvAmp = (uint8)MATHSRV_udtABS(s16LoaclDiff);

   VLVACTINMON_bSetPointInPrev = bLocalCall;
   VLVACTINMON_u8CkOpInVlvRef0Prev = u8LocalVlvSys_agCkOpInVlvReqRef0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidInitOffValComp                              */
/* !Description :  Ce bloc met à jour la valeur initiale de l'offset          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VLVACTINMON_u8CkOpInVlvRef0Prev;                              */
/*  output sint8 VlvAct_agInVlvIni;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidInitOffValComp(void)
{
   VlvAct_agInVlvIni = (sint8)(VLVACTINMON_u8CkOpInVlvRef0Prev - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidColdDiagComp                                */
/* !Description :  Ce bloc vérifie le temps de réponse de la VVT admission à  */
/*                 froid                                                      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINMON_vidColdDiagActCond();                        */
/*  extf argret void VLVACTINMON_vidColdDiagCalc();                           */
/*  input boolean VlvAct_bAcvInColdFctDg;                                     */
/*  input boolean VlvAct_bInVlvSpAmpVarldc;                                   */
/*  input boolean VlvAct_bMonRunInColdFctDg;                                  */
/*  input boolean VLVACTINMON_bAcvInColdFctDg;                                */
/*  output boolean VlvAct_bMonRunInColdFctDg;                                 */
/*  output boolean VLVACTINMON_bAcvInColdFctDg;                               */
/*  output boolean VLVACTINMON_bAcvInColdFctDgPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidColdDiagComp(void)
{
   VLVACTINMON_vidColdDiagActCond();
   VlvAct_bMonRunInColdFctDg = VlvAct_bAcvInColdFctDg;
   if (  (VlvAct_bAcvInColdFctDg != 0)
      && (VlvAct_bInVlvSpAmpVarldc != 0))
   {
      VLVACTINMON_bAcvInColdFctDg = 1;
   }
   else
   {
      VLVACTINMON_bAcvInColdFctDg = 0;
   }
   if (VlvAct_bMonRunInColdFctDg != 0)
   {
      VLVACTINMON_vidColdDiagCalc();
   }
   VLVACTINMON_bAcvInColdFctDgPrev = VLVACTINMON_bAcvInColdFctDg;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidColdDiagActCond                             */
/* !Description :  Ce bloc calcule l’activation du diagnostic fonctionnel     */
/*                 temps de réponse à froid de la VVT admission               */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_09_06381_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean VlvAct_bAcvInServo;                                         */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input uint16 VlvAct_nEngMinInVlv_C;                                       */
/*  input sint16 VlvAct_tOilMaxInVlv_C;                                       */
/*  input uint8 VlvAct_agInVlvAmp;                                            */
/*  input uint8 VlvAct_agInVlvAmpThdMinC_C;                                   */
/*  output boolean VlvAct_bAcvInColdFctDg;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidColdDiagActCond(void)
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
      && (s16LocalEng_tOilEstim < VlvAct_tOilMaxInVlv_C)
      && (VlvAct_agInVlvAmp > VlvAct_agInVlvAmpThdMinC_C)
      && (bLocalInhVlvActInMon == 0))
   {
      VlvAct_bAcvInColdFctDg = 1;
   }
   else
   {
      VlvAct_bAcvInColdFctDg = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidColdDiagCalc                                */
/* !Description :  Ce bloc calcule le diagnostic fonctionnel temps de réponse */
/*                 à froid de la VVT admission                                */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINMON_vidColdDefServoDet();                        */
/*  input boolean VlvAct_bIn1AgDftC;                                          */
/*  input boolean VlvAct_bIn2AgDftC;                                          */
/*  input boolean VlvAct_bIn3AgDftC;                                          */
/*  output boolean VlvAct_bDgoDftCVlvActIn;                                   */
/*  output boolean VlvAct_bDgoSlowC1VlvActIn;                                 */
/*  output boolean VlvAct_bDgoSlowC2VlvActIn;                                 */
/*  output boolean VlvAct_bDgoORngCVlvActIn;                                  */
/*  output boolean VlvAct_bDgoCmdCVlvActIn;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidColdDiagCalc(void)
{
   VLVACTINMON_vidColdDefServoDet();
   if (  (VlvAct_bIn1AgDftC != 0)
      || (VlvAct_bIn2AgDftC != 0)
      || (VlvAct_bIn3AgDftC != 0))
   {
      VlvAct_bDgoDftCVlvActIn = 1;
   }
   else
   {
      VlvAct_bDgoDftCVlvActIn = 0;
   }

   if (  (VlvAct_bIn1AgDftC != 0)
      && (VlvAct_bIn2AgDftC == 0)
      && (VlvAct_bIn3AgDftC == 0))
   {
      VlvAct_bDgoSlowC1VlvActIn = 1;
   }
   else
   {
      VlvAct_bDgoSlowC1VlvActIn = 0;
   }

   if (  (VlvAct_bIn1AgDftC != 0)
      && (VlvAct_bIn2AgDftC != 0)
      && (VlvAct_bIn3AgDftC == 0))
   {
      VlvAct_bDgoSlowC2VlvActIn = 1;
   }
   else
   {
      VlvAct_bDgoSlowC2VlvActIn = 0;
   }

   if (VlvAct_bIn3AgDftC != 0)
   {
      VlvAct_bDgoORngCVlvActIn = 1;
   }
   else
   {
      VlvAct_bDgoORngCVlvActIn = 0;
   }

   if (  (VlvAct_bIn1AgDftC == 0)
      && (VlvAct_bIn2AgDftC != 0)
      && (VlvAct_bIn3AgDftC == 0))
   {
      VlvAct_bDgoCmdCVlvActIn = 1;
   }
   else
   {
      VlvAct_bDgoCmdCVlvActIn = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidColdDefServoDet                             */
/* !Description :  Ce bloc calcule la valeur absolue de la différence entre   */
/*                 l'angle mesurée et l’angle de consigne à froid de la VVT   */
/*                 admission                                                  */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_09_06381_001.02                                     */
/*                 VEMS_R_09_06381_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINMON_vidFstColdTempTest();                        */
/*  extf argret void VLVACTINMON_vidSndColdTempTest();                        */
/*  extf argret void VLVACTINMON_vidThrdColdTemp();                           */
/*  input boolean VlvAct_bAcvInColdFctDg1AgRead;                              */
/*  input boolean VlvAct_bAcvInColdFctDg2AgRead;                              */
/*  input boolean VlvAct_bAcvInColdFctDg3AgRead;                              */
/*  input uint8 VlvAct_nInVlvAmpC_C;                                          */
/*  input uint8 VlvAct_agInVlvAmp;                                            */
/*  input uint8 VlvAct_tiOfsInVlvC_C;                                         */
/*  input boolean VLVACTINMON_bAcvInColdFctDgPrev;                            */
/*  input boolean VLVACTINMON_bAcvInColdFctDg;                                */
/*  input uint8 VlvAct_tiDlyInVlvC1;                                          */
/*  input uint8 VLVACTINMON_u8Timer1;                                         */
/*  input uint8 VlvAct_tiDlyInVlvC2;                                          */
/*  input uint8 VLVACTINMON_u8Timer2;                                         */
/*  input uint8 VlvAct_tiDlyInVlvC3;                                          */
/*  input uint8 VLVACTINMON_u8Timer3;                                         */
/*  output uint8 VlvAct_tiDlyInVlvC1;                                         */
/*  output uint8 VLVACTINMON_u8Timer1;                                        */
/*  output boolean VlvAct_bAcvInColdFctDg1AgRead;                             */
/*  output uint8 VlvAct_tiDlyInVlvC2;                                         */
/*  output uint8 VLVACTINMON_u8Timer2;                                        */
/*  output boolean VlvAct_bAcvInColdFctDg2AgRead;                             */
/*  output uint8 VlvAct_tiDlyInVlvC3;                                         */
/*  output uint8 VLVACTINMON_u8Timer3;                                        */
/*  output boolean VlvAct_bAcvInColdFctDg3AgRead;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidColdDefServoDet(void)
{
   boolean bLocalTimeOut1Prev;
   boolean bLocalTimeOut2Prev;
   boolean bLocalTimeOut3Prev;
   uint16  u16LocalTimer2;
   uint16  u16LocalTimer3;
   uint32  u32LocalTimer1;


   bLocalTimeOut1Prev = VlvAct_bAcvInColdFctDg1AgRead;
   bLocalTimeOut2Prev = VlvAct_bAcvInColdFctDg2AgRead;
   bLocalTimeOut3Prev = VlvAct_bAcvInColdFctDg3AgRead;
   if (VlvAct_nInVlvAmpC_C == 0)
   {
      VlvAct_tiDlyInVlvC1 = 255;
   }
   else
   {
      u32LocalTimer1 = ( (VlvAct_agInVlvAmp * 75)
                       / VlvAct_nInVlvAmpC_C)
                     + VlvAct_tiOfsInVlvC_C;
      VlvAct_tiDlyInVlvC1 = (uint8)(MATHSRV_udtMIN(u32LocalTimer1, 255));
   }
   if (  (VLVACTINMON_bAcvInColdFctDgPrev == 0)
      && (VLVACTINMON_bAcvInColdFctDg != 0))
   {
      VLVACTINMON_u8Timer1 = VlvAct_tiDlyInVlvC1;
      if (VLVACTINMON_u8Timer1 == 0)
      {
         VlvAct_bAcvInColdFctDg1AgRead = 1;
         if (bLocalTimeOut1Prev == 0)
         {
            VLVACTINMON_vidFstColdTempTest();
         }
      }
      else
      {
         VlvAct_bAcvInColdFctDg1AgRead = 0;
      }
   }
   else
   {
      if (VLVACTINMON_u8Timer1 > 0)
      {
         VLVACTINMON_u8Timer1 = (uint8)(VLVACTINMON_u8Timer1 - 1);
         if (VLVACTINMON_u8Timer1 == 0)
         {
            VlvAct_bAcvInColdFctDg1AgRead = 1;
            if (bLocalTimeOut1Prev == 0)
            {
               VLVACTINMON_vidFstColdTempTest();
            }
         }
         else
         {
            VlvAct_bAcvInColdFctDg1AgRead = 0;
         }
      }
   }

   u16LocalTimer2 = (uint16)(VlvAct_tiOfsInVlvC_C + VlvAct_tiDlyInVlvC1);
   VlvAct_tiDlyInVlvC2 = (uint8)(MATHSRV_udtMIN(u16LocalTimer2, 255));
   if (  (VLVACTINMON_bAcvInColdFctDgPrev == 0)
      && (VLVACTINMON_bAcvInColdFctDg != 0))
   {
      VLVACTINMON_u8Timer2 = VlvAct_tiDlyInVlvC2;
      if (VLVACTINMON_u8Timer2 == 0)
      {
         VlvAct_bAcvInColdFctDg2AgRead = 1;
         if (bLocalTimeOut2Prev == 0)
         {
            VLVACTINMON_vidSndColdTempTest();
         }
      }
      else
      {
         VlvAct_bAcvInColdFctDg2AgRead = 0;
      }
   }
   else
   {
      if (VLVACTINMON_u8Timer2 > 0)
      {
         VLVACTINMON_u8Timer2 = (uint8)(VLVACTINMON_u8Timer2 - 1);
         if (VLVACTINMON_u8Timer2 == 0)
         {
            VlvAct_bAcvInColdFctDg2AgRead = 1;
            if (bLocalTimeOut2Prev == 0)
            {
               VLVACTINMON_vidSndColdTempTest();
            }
         }
         else
         {
            VlvAct_bAcvInColdFctDg2AgRead = 0;
         }
      }
   }

   u16LocalTimer3 = (uint16)(VlvAct_tiOfsInVlvC_C + VlvAct_tiDlyInVlvC2);
   VlvAct_tiDlyInVlvC3 = (uint8)(MATHSRV_udtMIN(u16LocalTimer3, 255));
   if (  (VLVACTINMON_bAcvInColdFctDgPrev == 0)
      && (VLVACTINMON_bAcvInColdFctDg != 0))
   {
      VLVACTINMON_u8Timer3 = VlvAct_tiDlyInVlvC3;
      if (VLVACTINMON_u8Timer3 == 0)
      {
         VlvAct_bAcvInColdFctDg3AgRead = 1;
         if (bLocalTimeOut3Prev == 0)
         {
            VLVACTINMON_vidThrdColdTemp();
         }
      }
      else
      {
         VlvAct_bAcvInColdFctDg3AgRead = 0;
      }
   }
   else
   {
      if (VLVACTINMON_u8Timer3 > 0)
      {
         VLVACTINMON_u8Timer3 = (uint8)(VLVACTINMON_u8Timer3 - 1);
         if (VLVACTINMON_u8Timer3 == 0)
         {
            VlvAct_bAcvInColdFctDg3AgRead = 1;
            if (bLocalTimeOut3Prev == 0)
            {
               VLVACTINMON_vidThrdColdTemp();
            }
         }
         else
         {
            VlvAct_bAcvInColdFctDg3AgRead = 0;
         }
      }
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidFstColdTempTest                             */
/* !Description :  Ce bloc compare la différence entre l'angle mesurée et     */
/*                 l'angle de consigne à un seuil maximal d'écart de boucle   */
/*                 pour le premier test de temporisation à froid              */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_agCkOpInVlvEstimRef0;                                    */
/*  input uint8 VlvSys_agCkOpInVlvReqRef0;                                    */
/*  input sint8 VlvAct_agInVlvC1;                                             */
/*  input uint8 VlvAct_agInVlvDifC1;                                          */
/*  input uint8 VlvAct_agInVlvDifThdMax_C;                                    */
/*  output sint8 VlvAct_agInVlvC1;                                            */
/*  output uint8 VlvAct_agInVlvDifC1;                                         */
/*  output boolean VlvAct_bIn1AgDftC;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidFstColdTempTest(void)
{
   uint8  u8LocalVlvSys_agCkOpInVlvReqRef0;
   sint8  s8LocalCalc;
   sint16 s16LocalDiff;
   sint16 s16LocalExt_agCkOpInVlvEstimRef0;
   sint16 s16LocalVlvAct_agInVlvC1;


   VEMS_vidGET(Ext_agCkOpInVlvEstimRef0, s16LocalExt_agCkOpInVlvEstimRef0);
   VEMS_vidGET(VlvSys_agCkOpInVlvReqRef0, u8LocalVlvSys_agCkOpInVlvReqRef0);

   if (s16LocalExt_agCkOpInVlvEstimRef0 >= 0)
   {
      s16LocalVlvAct_agInVlvC1 =
         (sint16)((s16LocalExt_agCkOpInVlvEstimRef0 + 4) / 8);
   }
   else
   {
      s16LocalVlvAct_agInVlvC1 =
         (sint16)((s16LocalExt_agCkOpInVlvEstimRef0 - 4) / 8);
   }

   VlvAct_agInVlvC1 =
      (sint8)MATHSRV_udtCLAMP(s16LocalVlvAct_agInVlvC1, -128, 127);

   s8LocalCalc = (sint8)(u8LocalVlvSys_agCkOpInVlvReqRef0 - 128);
   s16LocalDiff = (sint16)(VlvAct_agInVlvC1 - s8LocalCalc);
   VlvAct_agInVlvDifC1 = (uint8)MATHSRV_udtABS(s16LocalDiff);

   if (VlvAct_agInVlvDifC1 > VlvAct_agInVlvDifThdMax_C)
   {
      VlvAct_bIn1AgDftC = 1;
   }
   else
   {
      VlvAct_bIn1AgDftC = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidSndColdTempTest                             */
/* !Description :  Ce bloc compare la différence entre l'angle mesurée et     */
/*                 l'angle de consigne à un seuil maximal d'écart de boucle   */
/*                 pour le deuxième test de temporisation à froid             */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_agCkOpInVlvEstimRef0;                                    */
/*  input uint8 VlvSys_agCkOpInVlvReqRef0;                                    */
/*  input sint8 VlvAct_agInVlvC2;                                             */
/*  input uint8 VlvAct_agInVlvDifC2;                                          */
/*  input uint8 VlvAct_agInVlvDifThdMax_C;                                    */
/*  output sint8 VlvAct_agInVlvC2;                                            */
/*  output uint8 VlvAct_agInVlvDifC2;                                         */
/*  output boolean VlvAct_bIn2AgDftC;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidSndColdTempTest(void)
{
   uint8  u8LocalVlvSys_agCkOpInVlvReqRef0;
   sint8  s8LocalCalc;
   sint16 s16LocalDiff;
   sint16 s16LocalExt_agCkOpInVlvEstimRef0;
   sint16 s16LocalVlvAct_agInVlvC2;


   VEMS_vidGET(Ext_agCkOpInVlvEstimRef0, s16LocalExt_agCkOpInVlvEstimRef0);
   VEMS_vidGET(VlvSys_agCkOpInVlvReqRef0, u8LocalVlvSys_agCkOpInVlvReqRef0);

   if (s16LocalExt_agCkOpInVlvEstimRef0 >= 0)
   {
      s16LocalVlvAct_agInVlvC2 =
         (sint16)((s16LocalExt_agCkOpInVlvEstimRef0 + 4) / 8);
   }
   else
   {
      s16LocalVlvAct_agInVlvC2 =
         (sint16)((s16LocalExt_agCkOpInVlvEstimRef0 - 4) / 8);
   }
   VlvAct_agInVlvC2 =
      (sint8)MATHSRV_udtCLAMP(s16LocalVlvAct_agInVlvC2, -128, 127);

   s8LocalCalc = (sint8)(u8LocalVlvSys_agCkOpInVlvReqRef0 - 128);
   s16LocalDiff = (sint16)(VlvAct_agInVlvC2 - s8LocalCalc);
   VlvAct_agInVlvDifC2 = (uint8)MATHSRV_udtABS(s16LocalDiff);

   if (VlvAct_agInVlvDifC2 > VlvAct_agInVlvDifThdMax_C)
   {
      VlvAct_bIn2AgDftC = 1;
   }
   else
   {
      VlvAct_bIn2AgDftC = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidThrdColdTemp                                */
/* !Description :  Ce bloc compare la différence entre l'angle mesurée et     */
/*                 l'angle de consigne à un seuil maximal d'écart de boucle   */
/*                 pour le troisième test de temporisation à froid            */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_agCkOpInVlvEstimRef0;                                    */
/*  input uint8 VlvSys_agCkOpInVlvReqRef0;                                    */
/*  input sint8 VlvAct_agInVlvC3;                                             */
/*  input uint8 VlvAct_agInVlvDifC3;                                          */
/*  input uint8 VlvAct_agInVlvDifThdMax_C;                                    */
/*  output sint8 VlvAct_agInVlvC3;                                            */
/*  output uint8 VlvAct_agInVlvDifC3;                                         */
/*  output boolean VlvAct_bIn3AgDftC;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidThrdColdTemp(void)
{
   uint8  u8LocalVlvSys_agCkOpInVlvReqRef0;
   sint8  s8LocalCalc;
   sint16 s16LocalDiff;
   sint16 s16LocalExt_agCkOpInVlvEstimRef0;
   sint16 s16LocalVlvAct_agInVlvC3;


   VEMS_vidGET(Ext_agCkOpInVlvEstimRef0, s16LocalExt_agCkOpInVlvEstimRef0);
   VEMS_vidGET(VlvSys_agCkOpInVlvReqRef0, u8LocalVlvSys_agCkOpInVlvReqRef0);

   if (s16LocalExt_agCkOpInVlvEstimRef0 >= 0)
   {
      s16LocalVlvAct_agInVlvC3 =
         (sint16)((s16LocalExt_agCkOpInVlvEstimRef0 + 4 ) / 8);
   }
   else
   {
      s16LocalVlvAct_agInVlvC3 =
         (sint16)((s16LocalExt_agCkOpInVlvEstimRef0 - 4) / 8);
   }
   VlvAct_agInVlvC3 =
      (sint8)MATHSRV_udtCLAMP(s16LocalVlvAct_agInVlvC3, -128, 127);

   s8LocalCalc = (sint8)(u8LocalVlvSys_agCkOpInVlvReqRef0 - 128);
   s16LocalDiff =(sint16)(VlvAct_agInVlvC3 - s8LocalCalc);
   VlvAct_agInVlvDifC3 = (uint8)MATHSRV_udtABS(s16LocalDiff);

   if (VlvAct_agInVlvDifC3 > VlvAct_agInVlvDifThdMax_C)
   {
      VlvAct_bIn3AgDftC = 1;
   }
   else
   {
      VlvAct_bIn3AgDftC = 0;
   }
}
/*--------------------------------- end of file ------------------------------*/