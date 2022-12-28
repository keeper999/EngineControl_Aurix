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
/* !File            : VLVACTEXMON_FCT1.C                                      */
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
/*   1 / VLVACTEXMON_vidInitialization                                        */
/*   2 / VLVACTEXMON_vidOffsetSetPtComp                                       */
/*   3 / VLVACTEXMON_vidInitOffValComp                                        */
/*   4 / VLVACTEXMON_vidColdDiagComp                                          */
/*   5 / VLVACTEXMON_vidColdDiagActCond                                       */
/*   6 / VLVACTEXMON_vidColdDiagCalc                                          */
/*   7 / VLVACTEXMON_vidColdDefServoDet                                       */
/*   8 / VLVACTEXMON_vidFstColdTempTest                                       */
/*   9 / VLVACTEXMON_vidSndColdTempTest                                       */
/*   10 / VLVACTEXMON_vidThrdColdTemp                                         */
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
/* !Function    :  VLVACTEXMON_vidInitialization                              */
/* !Description :  Initialisation des variables                               */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean VLVACTEXMON_bSetPointExPrev;                               */
/*  output uint8 VLVACTEXMON_u8CkClsExVlvRef0Prev;                            */
/*  output boolean VLVACTEXMON_bAcvExServoPrev;                               */
/*  output boolean VlvAct_bAcvExColdFctDg1AgRead;                             */
/*  output boolean VlvAct_bAcvExColdFctDg2AgRead;                             */
/*  output boolean VlvAct_bAcvExColdFctDg3AgRead;                             */
/*  output boolean VlvAct_bAcvExHotFctDg1AgRead;                              */
/*  output boolean VlvAct_bAcvExHotFctDg2AgRead;                              */
/*  output boolean VlvAct_bAcvExHotFctDg3AgRead;                              */
/*  output boolean VlvAct_bAcvExHotStuckFctDgAgRead;                          */
/*  output boolean VLVACTEXMON_bAcvExColdFctDgPrev;                           */
/*  output boolean VLVACTEXMON_bAcvExHotFctDgPrev;                            */
/*  output boolean VLVACTEXMON_bAcvExHotStkFctDgPrv;                          */
/*  output uint8 VLVACTEXMON_u8Timer1;                                        */
/*  output uint8 VLVACTEXMON_u8Timer2;                                        */
/*  output uint8 VLVACTEXMON_u8Timer3;                                        */
/*  output uint8 VLVACTEXMON_u8Timer4;                                        */
/*  output uint8 VLVACTEXMON_u8Timer5;                                        */
/*  output uint8 VLVACTEXMON_u8Timer6;                                        */
/*  output uint8 VLVACTEXMON_u8Timer7;                                        */
/*  output sint8 VlvSys_agCkClsExVlvReqRef0_int;                              */
/*  output uint16 VlvAct_tiExVlvPosStat;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidInitialization(void)
{
   VLVACTEXMON_bSetPointExPrev = 0;
   VLVACTEXMON_u8CkClsExVlvRef0Prev = 0;
   VLVACTEXMON_bAcvExServoPrev = 0;
   VlvAct_bAcvExColdFctDg1AgRead = 0;
   VlvAct_bAcvExColdFctDg2AgRead = 0;
   VlvAct_bAcvExColdFctDg3AgRead = 0;
   VlvAct_bAcvExHotFctDg1AgRead = 0;
   VlvAct_bAcvExHotFctDg2AgRead = 0;
   VlvAct_bAcvExHotFctDg3AgRead = 0;
   VlvAct_bAcvExHotStuckFctDgAgRead = 0;
   VLVACTEXMON_bAcvExColdFctDgPrev = 0;
   VLVACTEXMON_bAcvExHotFctDgPrev = 0;
   VLVACTEXMON_bAcvExHotStkFctDgPrv = 0;
   VLVACTEXMON_u8Timer1 = 0;
   VLVACTEXMON_u8Timer2 = 0;
   VLVACTEXMON_u8Timer3 = 0;
   VLVACTEXMON_u8Timer4 = 0;
   VLVACTEXMON_u8Timer5 = 0;
   VLVACTEXMON_u8Timer6 = 0;
   VLVACTEXMON_u8Timer7 = 0;
   VlvSys_agCkClsExVlvReqRef0_int = 0;
   VlvAct_tiExVlvPosStat = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidOffsetSetPtComp                             */
/* !Description :  Ce bloc calcule la valeur de l'offset initiale             */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXMON_vidInitOffValComp();                         */
/*  input uint8 VlvSys_agCkClsExVlvReqRef0;                                   */
/*  input uint8 VLVACTEXMON_u8CkClsExVlvRef0Prev;                             */
/*  input boolean VLVACTEXMON_bSetPointExPrev;                                */
/*  input sint8 VlvAct_agExVlvIni;                                            */
/*  output boolean VlvAct_bExVlvSpAmpVarldc;                                  */
/*  output uint8 VlvAct_agExVlvAmp;                                           */
/*  output boolean VLVACTEXMON_bSetPointExPrev;                               */
/*  output uint8 VLVACTEXMON_u8CkClsExVlvRef0Prev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidOffsetSetPtComp(void)
{
   boolean bLocalCall;
   uint8   u8LocalVlvSys_CkClsExVlvReqRef0;
   sint16  s16LoaclDiff;


   VEMS_vidGET(VlvSys_agCkClsExVlvReqRef0, u8LocalVlvSys_CkClsExVlvReqRef0);

   if (u8LocalVlvSys_CkClsExVlvReqRef0 == VLVACTEXMON_u8CkClsExVlvRef0Prev)
   {
      bLocalCall = 0;
      VlvAct_bExVlvSpAmpVarldc = 0;
   }
   else
   {
      bLocalCall = 1;
      if (VLVACTEXMON_bSetPointExPrev == 0)
      {
         VlvAct_bExVlvSpAmpVarldc = 1;
         VLVACTEXMON_vidInitOffValComp();
      }
      else
      {
         VlvAct_bExVlvSpAmpVarldc = 0;
      }
   }

   s16LoaclDiff =
      (sint16)(VlvAct_agExVlvIni - (u8LocalVlvSys_CkClsExVlvReqRef0 - 128));
   VlvAct_agExVlvAmp = (uint8)MATHSRV_udtABS(s16LoaclDiff);

   VLVACTEXMON_bSetPointExPrev = bLocalCall;
   VLVACTEXMON_u8CkClsExVlvRef0Prev = u8LocalVlvSys_CkClsExVlvReqRef0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidInitOffValComp                              */
/* !Description :  Ce bloc met à jour la valeur initiale de l'offset          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VLVACTEXMON_u8CkClsExVlvRef0Prev;                             */
/*  output sint8 VlvAct_agExVlvIni;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidInitOffValComp(void)
{
   VlvAct_agExVlvIni = (sint8)(VLVACTEXMON_u8CkClsExVlvRef0Prev - 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidColdDiagComp                                */
/* !Description :  Ce bloc vérifie le temps de réponse de la VVT échappement à*/
/*                 froid                                                      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXMON_vidColdDiagActCond();                        */
/*  extf argret void VLVACTEXMON_vidColdDiagCalc();                           */
/*  input boolean VlvAct_bAcvExColdFctDg;                                     */
/*  input boolean VlvAct_bExVlvSpAmpVarldc;                                   */
/*  input boolean VlvAct_bMonRunExColdFctDg;                                  */
/*  input boolean VLVACTEXMON_bAcvExColdFctDg;                                */
/*  output boolean VlvAct_bMonRunExColdFctDg;                                 */
/*  output boolean VLVACTEXMON_bAcvExColdFctDg;                               */
/*  output boolean VLVACTEXMON_bAcvExColdFctDgPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidColdDiagComp(void)
{
   VLVACTEXMON_vidColdDiagActCond();
   VlvAct_bMonRunExColdFctDg = VlvAct_bAcvExColdFctDg;

   if (  (VlvAct_bAcvExColdFctDg != 0)
      && (VlvAct_bExVlvSpAmpVarldc != 0))
   {
      VLVACTEXMON_bAcvExColdFctDg = 1;
   }
   else
   {
      VLVACTEXMON_bAcvExColdFctDg = 0;
   }
   if (VlvAct_bMonRunExColdFctDg != 0)
   {
      VLVACTEXMON_vidColdDiagCalc();
   }
   VLVACTEXMON_bAcvExColdFctDgPrev = VLVACTEXMON_bAcvExColdFctDg;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidColdDiagActCond                             */
/* !Description :  Ce bloc calcule l’activation du diagnostic fonctionnel     */
/*                 temps de réponse à froid de la VVT échappement             */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_09_06481_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean VlvAct_bAcvExServo;                                         */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input uint16 VlvAct_nEngMinExVlv_C;                                       */
/*  input sint16 VlvAct_tOilMaxExVlv_C;                                       */
/*  input uint8 VlvAct_agExVlvAmp;                                            */
/*  input uint8 VlvAct_agExVlvAmpThdMinC_C;                                   */
/*  output boolean VlvAct_bAcvExColdFctDg;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidColdDiagActCond(void)
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
      && (s16LocalEng_tOilEstim < VlvAct_tOilMaxExVlv_C)
      && (VlvAct_agExVlvAmp > VlvAct_agExVlvAmpThdMinC_C)
      && (bLocalInhVlvActExMon == 0))
   {
      VlvAct_bAcvExColdFctDg = 1;
   }
   else
   {
      VlvAct_bAcvExColdFctDg = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidColdDiagCalc                                */
/* !Description :  Ce bloc calcule le diagnostic fonctionnel temps de réponse */
/*                 à froid de la VVT échappement                              */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXMON_vidColdDefServoDet();                        */
/*  input boolean VlvAct_bEx1AgDftC;                                          */
/*  input boolean VlvAct_bEx2AgDftC;                                          */
/*  input boolean VlvAct_bEx3AgDftC;                                          */
/*  output boolean VlvAct_bDgoDftCVlvActEx;                                   */
/*  output boolean VlvAct_bDgoSlowC1VlvActEx;                                 */
/*  output boolean VlvAct_bDgoSlowC2VlvActEx;                                 */
/*  output boolean VlvAct_bDgoORngCVlvActEx;                                  */
/*  output boolean VlvAct_bDgoCmdCVlvActEx;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidColdDiagCalc(void)
{
   VLVACTEXMON_vidColdDefServoDet();
   if (  (VlvAct_bEx1AgDftC != 0)
      || (VlvAct_bEx2AgDftC != 0)
      || (VlvAct_bEx3AgDftC != 0))
   {
      VlvAct_bDgoDftCVlvActEx = 1;
   }
   else
   {
      VlvAct_bDgoDftCVlvActEx = 0;
   }

   if (  (VlvAct_bEx1AgDftC != 0)
      && (VlvAct_bEx2AgDftC == 0)
      && (VlvAct_bEx3AgDftC == 0))
   {
      VlvAct_bDgoSlowC1VlvActEx = 1;
   }
   else
   {
      VlvAct_bDgoSlowC1VlvActEx = 0;
   }

   if (  (VlvAct_bEx1AgDftC != 0)
      && (VlvAct_bEx2AgDftC != 0)
      && (VlvAct_bEx3AgDftC == 0))
   {
      VlvAct_bDgoSlowC2VlvActEx = 1;
   }
   else
   {
      VlvAct_bDgoSlowC2VlvActEx = 0;
   }

   if (VlvAct_bEx3AgDftC != 0)
   {
      VlvAct_bDgoORngCVlvActEx = 1;
   }
   else
   {
      VlvAct_bDgoORngCVlvActEx = 0;
   }

   if (  (VlvAct_bEx1AgDftC == 0)
      && (VlvAct_bEx2AgDftC != 0)
      && (VlvAct_bEx3AgDftC == 0))
   {
      VlvAct_bDgoCmdCVlvActEx = 1;
   }
   else
   {
      VlvAct_bDgoCmdCVlvActEx = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidColdDefServoDet                             */
/* !Description :  Ce bloc calcule la valeur absolue de la différence entre   */
/*                 l'angle mesurée et l’angle de consigne à froid de la VVT   */
/*                 échappement                                                */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_09_06481_001.02                                     */
/*                 VEMS_R_09_06481_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXMON_vidFstColdTempTest();                        */
/*  extf argret void VLVACTEXMON_vidSndColdTempTest();                        */
/*  extf argret void VLVACTEXMON_vidThrdColdTemp();                           */
/*  input boolean VlvAct_bAcvExColdFctDg1AgRead;                              */
/*  input boolean VlvAct_bAcvExColdFctDg2AgRead;                              */
/*  input boolean VlvAct_bAcvExColdFctDg3AgRead;                              */
/*  input uint8 VlvAct_nExVlvAmpC_C;                                          */
/*  input uint8 VlvAct_agExVlvAmp;                                            */
/*  input uint8 VlvAct_tiOfsExVlvC_C;                                         */
/*  input boolean VLVACTEXMON_bAcvExColdFctDgPrev;                            */
/*  input boolean VLVACTEXMON_bAcvExColdFctDg;                                */
/*  input uint8 VlvAct_tiDlyExVlvC1;                                          */
/*  input uint8 VLVACTEXMON_u8Timer1;                                         */
/*  input uint8 VlvAct_tiDlyExVlvC2;                                          */
/*  input uint8 VLVACTEXMON_u8Timer2;                                         */
/*  input uint8 VlvAct_tiDlyExVlvC3;                                          */
/*  input uint8 VLVACTEXMON_u8Timer3;                                         */
/*  output uint8 VlvAct_tiDlyExVlvC1;                                         */
/*  output uint8 VLVACTEXMON_u8Timer1;                                        */
/*  output boolean VlvAct_bAcvExColdFctDg1AgRead;                             */
/*  output uint8 VlvAct_tiDlyExVlvC2;                                         */
/*  output uint8 VLVACTEXMON_u8Timer2;                                        */
/*  output boolean VlvAct_bAcvExColdFctDg2AgRead;                             */
/*  output uint8 VlvAct_tiDlyExVlvC3;                                         */
/*  output uint8 VLVACTEXMON_u8Timer3;                                        */
/*  output boolean VlvAct_bAcvExColdFctDg3AgRead;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidColdDefServoDet(void)
{
   boolean bLocalTimeOut1Prev;
   boolean bLocalTimeOut2Prev;
   boolean bLocalTimeOut3Prev;
   uint16  u16LocalTimer2;
   uint16  u16LocalTimer3;
   uint32  u32LocalTimer1;


   bLocalTimeOut1Prev = VlvAct_bAcvExColdFctDg1AgRead;
   bLocalTimeOut2Prev = VlvAct_bAcvExColdFctDg2AgRead;
   bLocalTimeOut3Prev = VlvAct_bAcvExColdFctDg3AgRead;
   if (VlvAct_nExVlvAmpC_C == 0)
   {
      VlvAct_tiDlyExVlvC1 = 255;
   }
   else
   {
      u32LocalTimer1 = ( (VlvAct_agExVlvAmp * 75)
                       / VlvAct_nExVlvAmpC_C)
                     + VlvAct_tiOfsExVlvC_C;
      VlvAct_tiDlyExVlvC1 = (uint8)(MATHSRV_udtMIN(u32LocalTimer1, 255));
   }

   if (  (VLVACTEXMON_bAcvExColdFctDgPrev == 0)
      && (VLVACTEXMON_bAcvExColdFctDg != 0))
   {
      VLVACTEXMON_u8Timer1 = VlvAct_tiDlyExVlvC1;
      if (VLVACTEXMON_u8Timer1 == 0)
      {
         VlvAct_bAcvExColdFctDg1AgRead = 1;
         if (bLocalTimeOut1Prev == 0)
         {
            VLVACTEXMON_vidFstColdTempTest();
         }
      }
      else
      {
         VlvAct_bAcvExColdFctDg1AgRead = 0;
      }
   }
   else
   {
      if (VLVACTEXMON_u8Timer1 > 0)
      {
         VLVACTEXMON_u8Timer1 = (uint8)(VLVACTEXMON_u8Timer1 - 1);
         if (VLVACTEXMON_u8Timer1 == 0)
         {
            VlvAct_bAcvExColdFctDg1AgRead = 1;
            if (bLocalTimeOut1Prev == 0)
            {
               VLVACTEXMON_vidFstColdTempTest();
            }
         }
         else
         {
            VlvAct_bAcvExColdFctDg1AgRead = 0;
         }
      }
   }

   u16LocalTimer2 = (uint16)(VlvAct_tiOfsExVlvC_C + VlvAct_tiDlyExVlvC1);
   VlvAct_tiDlyExVlvC2 = (uint8)(MATHSRV_udtMIN(u16LocalTimer2, 255));
   if (  (VLVACTEXMON_bAcvExColdFctDgPrev == 0)
      && (VLVACTEXMON_bAcvExColdFctDg != 0))
   {
      VLVACTEXMON_u8Timer2 = VlvAct_tiDlyExVlvC2;
      if (VLVACTEXMON_u8Timer2 == 0)
      {
         VlvAct_bAcvExColdFctDg2AgRead = 1;
         if (bLocalTimeOut2Prev == 0)
         {
            VLVACTEXMON_vidSndColdTempTest();
         }
      }
      else
      {
         VlvAct_bAcvExColdFctDg2AgRead = 0;
      }
   }
   else
   {
      if (VLVACTEXMON_u8Timer2 > 0)
      {
         VLVACTEXMON_u8Timer2 = (uint8)(VLVACTEXMON_u8Timer2 - 1);
         if (VLVACTEXMON_u8Timer2 == 0)
         {
            VlvAct_bAcvExColdFctDg2AgRead = 1;
            if (bLocalTimeOut2Prev == 0)
            {
               VLVACTEXMON_vidSndColdTempTest();
            }
         }
         else
         {
            VlvAct_bAcvExColdFctDg2AgRead = 0;
         }
      }
   }

   u16LocalTimer3 = (uint16)(VlvAct_tiOfsExVlvC_C + VlvAct_tiDlyExVlvC2);
   VlvAct_tiDlyExVlvC3 = (uint8)(MATHSRV_udtMIN(u16LocalTimer3, 255));
   if (  (VLVACTEXMON_bAcvExColdFctDgPrev == 0)
      && (VLVACTEXMON_bAcvExColdFctDg != 0))
   {
      VLVACTEXMON_u8Timer3 = VlvAct_tiDlyExVlvC3;
      if (VLVACTEXMON_u8Timer3 == 0)
      {
         VlvAct_bAcvExColdFctDg3AgRead = 1;
         if (bLocalTimeOut3Prev == 0)
         {
            VLVACTEXMON_vidThrdColdTemp();
         }
      }
      else
      {
         VlvAct_bAcvExColdFctDg3AgRead = 0;
      }
   }
   else
   {
      if (VLVACTEXMON_u8Timer3 > 0)
      {
         VLVACTEXMON_u8Timer3 = (uint8)(VLVACTEXMON_u8Timer3 - 1);
         if (VLVACTEXMON_u8Timer3 == 0)
         {
            VlvAct_bAcvExColdFctDg3AgRead = 1;
            if (bLocalTimeOut3Prev == 0)
            {
               VLVACTEXMON_vidThrdColdTemp();
            }
         }
         else
         {
            VlvAct_bAcvExColdFctDg3AgRead = 0;
         }
      }
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidFstColdTempTest                             */
/* !Description :  Ce bloc compare la différence entre l'angle mesurée et     */
/*                 l'angle de consigne à un seuil maximal d'écart de boucle   */
/*                 pour le premier test de temporisation à froid              */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_agCkClsExVlvEstimRef0;                                   */
/*  input uint8 VlvSys_agCkClsExVlvReqRef0;                                   */
/*  input sint8 VlvAct_agExVlvC1;                                             */
/*  input uint8 VlvAct_agExVlvDifC1;                                          */
/*  input uint8 VlvAct_agExVlvDifThdMax_C;                                    */
/*  output sint8 VlvAct_agExVlvC1;                                            */
/*  output uint8 VlvAct_agExVlvDifC1;                                         */
/*  output boolean VlvAct_bEx1AgDftC;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidFstColdTempTest(void)
{
   uint8  u8LocalVlvSys_agCkClsExVlvReqRf0;
   sint8  s8LocalCalc;
   sint16 s16LocalDiff;
   sint16 s16LocalExt_agCkOpExVlvEstimRef0;
   sint16 s16LocalVlvAct_agExVlvC1;


   VEMS_vidGET(Ext_agCkClsExVlvEstimRef0, s16LocalExt_agCkOpExVlvEstimRef0);
   VEMS_vidGET(VlvSys_agCkClsExVlvReqRef0, u8LocalVlvSys_agCkClsExVlvReqRf0);

   if (s16LocalExt_agCkOpExVlvEstimRef0 >= 0)
   {
      s16LocalVlvAct_agExVlvC1 =
         (sint16)((s16LocalExt_agCkOpExVlvEstimRef0 + 4) / 8);
   }
   else
   {
      s16LocalVlvAct_agExVlvC1 =
         (sint16)((s16LocalExt_agCkOpExVlvEstimRef0 - 4) / 8);
   }
   VlvAct_agExVlvC1 =
      (sint8)MATHSRV_udtCLAMP(s16LocalVlvAct_agExVlvC1, -128, 127);

   s8LocalCalc = (sint8)(u8LocalVlvSys_agCkClsExVlvReqRf0 - 128);
   s16LocalDiff = (sint16)(VlvAct_agExVlvC1 - s8LocalCalc);
   VlvAct_agExVlvDifC1 = (uint8)MATHSRV_udtABS(s16LocalDiff);

   if (VlvAct_agExVlvDifC1 > VlvAct_agExVlvDifThdMax_C)
   {
      VlvAct_bEx1AgDftC = 1;
   }
   else
   {
      VlvAct_bEx1AgDftC = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidSndColdTempTest                             */
/* !Description :  Ce bloc compare la différence entre l'angle mesurée et     */
/*                 l'angle de consigne à un seuil maximal d'écart de boucle   */
/*                 pour le deuxième test de temporisation à froid             */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_agCkClsExVlvEstimRef0;                                   */
/*  input uint8 VlvSys_agCkClsExVlvReqRef0;                                   */
/*  input sint8 VlvAct_agExVlvC2;                                             */
/*  input uint8 VlvAct_agExVlvDifC2;                                          */
/*  input uint8 VlvAct_agExVlvDifThdMax_C;                                    */
/*  output sint8 VlvAct_agExVlvC2;                                            */
/*  output uint8 VlvAct_agExVlvDifC2;                                         */
/*  output boolean VlvAct_bEx2AgDftC;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidSndColdTempTest(void)
{
   uint8  u8LocalVlvSys_agCkClsExVlvReqRf0;
   sint8  s8LocalCalc;
   sint16 s16LocalDiff;
   sint16 s16LocalExt_agCkOpExVlvEstimRef0;
   sint16 s16LocalVlvAct_agExVlvC2;


   VEMS_vidGET(Ext_agCkClsExVlvEstimRef0, s16LocalExt_agCkOpExVlvEstimRef0);
   VEMS_vidGET(VlvSys_agCkClsExVlvReqRef0, u8LocalVlvSys_agCkClsExVlvReqRf0);

   if (s16LocalExt_agCkOpExVlvEstimRef0 >= 0)
   {
      s16LocalVlvAct_agExVlvC2 =
         (sint16)((s16LocalExt_agCkOpExVlvEstimRef0 + 4) / 8);
   }
   else
   {
      s16LocalVlvAct_agExVlvC2 =
         (sint16)((s16LocalExt_agCkOpExVlvEstimRef0 - 4) / 8);
   }
   VlvAct_agExVlvC2 =
      (sint8)MATHSRV_udtCLAMP(s16LocalVlvAct_agExVlvC2, -128, 127);

   s8LocalCalc = (sint8)(u8LocalVlvSys_agCkClsExVlvReqRf0 - 128);
   s16LocalDiff = (sint16)(VlvAct_agExVlvC2 - s8LocalCalc);
   VlvAct_agExVlvDifC2 = (uint8)MATHSRV_udtABS(s16LocalDiff);

   if (VlvAct_agExVlvDifC2 > VlvAct_agExVlvDifThdMax_C)
   {
      VlvAct_bEx2AgDftC = 1;
   }
   else
   {
      VlvAct_bEx2AgDftC = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidThrdColdTemp                                */
/* !Description :  Ce bloc compare la différence entre l'angle mesurée et     */
/*                 l'angle de consigne à un seuil maximal d'écart de boucle   */
/*                 pour le troisième test de temporisation à froid            */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_agCkClsExVlvEstimRef0;                                   */
/*  input uint8 VlvSys_agCkClsExVlvReqRef0;                                   */
/*  input sint8 VlvAct_agExVlvC3;                                             */
/*  input uint8 VlvAct_agExVlvDifC3;                                          */
/*  input uint8 VlvAct_agExVlvDifThdMax_C;                                    */
/*  output sint8 VlvAct_agExVlvC3;                                            */
/*  output uint8 VlvAct_agExVlvDifC3;                                         */
/*  output boolean VlvAct_bEx3AgDftC;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidThrdColdTemp(void)
{
   uint8  u8LocalVlvSys_agCkClsExVlvReqRf0;
   sint8  s8LocalCalc;
   sint16 s16LocalDiff;
   sint16 s16LocalExt_agCkOpExVlvEstimRef0;
   sint16 s16LocalVlvAct_agExVlvC3;


   VEMS_vidGET(Ext_agCkClsExVlvEstimRef0, s16LocalExt_agCkOpExVlvEstimRef0);
   VEMS_vidGET(VlvSys_agCkClsExVlvReqRef0, u8LocalVlvSys_agCkClsExVlvReqRf0);

   if (s16LocalExt_agCkOpExVlvEstimRef0 >= 0)
   {
      s16LocalVlvAct_agExVlvC3 =
         (sint16)((s16LocalExt_agCkOpExVlvEstimRef0 + 4) / 8);
   }
   else
   {
      s16LocalVlvAct_agExVlvC3 =
         (sint16)((s16LocalExt_agCkOpExVlvEstimRef0 - 4) / 8);
   }
   VlvAct_agExVlvC3 =
      (sint8)MATHSRV_udtCLAMP(s16LocalVlvAct_agExVlvC3, -128, 127);

   s8LocalCalc = (sint8)(u8LocalVlvSys_agCkClsExVlvReqRf0 - 128);
   s16LocalDiff = (sint16)(VlvAct_agExVlvC3 - s8LocalCalc);
   VlvAct_agExVlvDifC3 = (uint8)MATHSRV_udtABS(s16LocalDiff);

   if (VlvAct_agExVlvDifC3 > VlvAct_agExVlvDifThdMax_C)
   {
      VlvAct_bEx3AgDftC = 1;
   }
   else
   {
      VlvAct_bEx3AgDftC = 0;
   }
}
/*--------------------------------- end of file ------------------------------*/