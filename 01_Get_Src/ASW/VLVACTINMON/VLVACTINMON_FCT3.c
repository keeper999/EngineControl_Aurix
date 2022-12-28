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
/* !File            : VLVACTINMON_FCT3.C                                      */
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
/*   1 / VLVACTINMON_vidHotStkDiagComp                                        */
/*   2 / VLVACTINMON_vidHotStkDiagActCond                                     */
/*   3 / VLVACTINMON_vidHotStkDiagCalc                                        */
/*   4 / VLVACTINMON_vidHotStkDefServoDet                                     */
/*   5 / VLVACTINMON_vidFstHotStkTempTest                                     */
/*   6 / VLVACTINMON_vidPosStatErrorDiag                                      */
/*   7 / VLVACTINMON_vidTime_index_reset                                      */
/*   8 / VLVACTINMON_vidNegStatErrorDiag                                      */
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
/* !Function    :  VLVACTINMON_vidHotStkDiagComp                              */
/* !Description :  Ce bloc vérifie si la VVT admission est bloquée à chaud    */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINMON_vidHotStkDiagActCond();                      */
/*  extf argret void VLVACTINMON_vidHotStkDiagCalc();                         */
/*  input boolean VlvAct_bAcvInHotStuckFctDg;                                 */
/*  input boolean VlvAct_bInVlvSpAmpVarldc;                                   */
/*  input boolean VlvAct_bMonRunInHotStuckFctDg;                              */
/*  input boolean VLVACTINMON_bAcvInHotStuckFctDg;                            */
/*  output boolean VlvAct_bMonRunInHotStuckFctDg;                             */
/*  output boolean VLVACTINMON_bAcvInHotStuckFctDg;                           */
/*  output boolean VLVACTINMON_bAcvInHotStkFctDgPrv;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidHotStkDiagComp(void)
{
   VLVACTINMON_vidHotStkDiagActCond();
   VlvAct_bMonRunInHotStuckFctDg = VlvAct_bAcvInHotStuckFctDg;
   if (  (VlvAct_bAcvInHotStuckFctDg != 0)
      && (VlvAct_bInVlvSpAmpVarldc != 0))
   {
      VLVACTINMON_bAcvInHotStuckFctDg = 1;
   }
   else
   {
      VLVACTINMON_bAcvInHotStuckFctDg = 0;
   }
   if (VlvAct_bMonRunInHotStuckFctDg != 0)
   {
      VLVACTINMON_vidHotStkDiagCalc();
   }
   VLVACTINMON_bAcvInHotStkFctDgPrv = VLVACTINMON_bAcvInHotStuckFctDg;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidHotStkDiagActCond                           */
/* !Description :  Ce bloc calcule l’activation du diagnostic fonctionnel     */
/*                 déphaseur bloqué à chaud de la VVT admission               */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_09_06381_008.02                                     */
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
/*  input uint8 VlvAct_agInVlvAmpThdMin_C;                                    */
/*  output boolean VlvAct_bAcvInHotStuckFctDg;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidHotStkDiagActCond(void)
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
      && (VlvAct_agInVlvAmp > VlvAct_agInVlvAmpThdMin_C)
      && (bLocalInhVlvActInMon == 0))
   {
      VlvAct_bAcvInHotStuckFctDg = 1;
   }
   else
   {
      VlvAct_bAcvInHotStuckFctDg = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidHotStkDiagCalc                              */
/* !Description :  Ce bloc calcule le diagnostic fonctionnel si la VVT        */
/*                 admission est bloquée à chaud                              */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINMON_vidHotStkDefServoDet();                      */
/*  input boolean VlvAct_bInAgDftHStuck;                                      */
/*  input sint8 VlvAct_agInVlvThdMin_C;                                       */
/*  input sint8 VlvAct_agInVlvH;                                              */
/*  input sint8 VlvAct_agInVlvThdMax_C;                                       */
/*  output boolean VlvAct_bDgoStuckH1VlvActIn;                                */
/*  output boolean VlvAct_bDgoStuckH2VlvActIn;                                */
/*  output boolean VlvAct_bDgoStuckH3VlvActIn;                                */
/*  output boolean VlvAct_bDgoStuckHVlvActIn;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidHotStkDiagCalc(void)
{
   VLVACTINMON_vidHotStkDefServoDet();
   if (  (VlvAct_bInAgDftHStuck != 0)
      && (VlvAct_agInVlvThdMin_C < VlvAct_agInVlvH))
   {
      VlvAct_bDgoStuckH1VlvActIn = 1;
   }
   else
   {
      VlvAct_bDgoStuckH1VlvActIn = 0;
   }

   if (  (VlvAct_bInAgDftHStuck != 0)
      && (VlvAct_agInVlvThdMin_C >= VlvAct_agInVlvH)
      && (VlvAct_agInVlvThdMax_C <= VlvAct_agInVlvH))
   {
      VlvAct_bDgoStuckH2VlvActIn = 1;
   }
   else
   {
      VlvAct_bDgoStuckH2VlvActIn = 0;
   }

   if (  (VlvAct_bInAgDftHStuck != 0)
      && (VlvAct_agInVlvThdMin_C >= VlvAct_agInVlvH)
      && (VlvAct_agInVlvThdMax_C > VlvAct_agInVlvH))
   {
      VlvAct_bDgoStuckH3VlvActIn = 1;
   }
   else
   {
      VlvAct_bDgoStuckH3VlvActIn = 0;
   }

   if (VlvAct_bInAgDftHStuck != 0)
   {
      VlvAct_bDgoStuckHVlvActIn = 1;
   }
   else
   {
      VlvAct_bDgoStuckHVlvActIn = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidHotStkDefServoDet                           */
/* !Description :  Ce bloc calcule la valeur absolue de la différence entre   */
/*                 l'angle mesurée et l’angle de départ si la VVT admission   */
/*                 est bloquée à chaud                                        */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_09_06381_007.02                                     */
/*                 VEMS_R_09_06381_009.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINMON_vidFstHotStkTempTest();                      */
/*  input boolean VlvAct_bAcvInHotStuckFctDgAgRead;                           */
/*  input uint8 VlvAct_nInVlvAmpH_C;                                          */
/*  input uint8 VlvAct_agInVlvAmp;                                            */
/*  input uint8 VlvAct_tiOfsInVlvH_C;                                         */
/*  input boolean VLVACTINMON_bAcvInHotStkFctDgPrv;                           */
/*  input boolean VLVACTINMON_bAcvInHotStuckFctDg;                            */
/*  input uint8 VlvAct_tiDlyInVlvH;                                           */
/*  input uint8 VLVACTINMON_u8Timer7;                                         */
/*  output uint8 VlvAct_tiDlyInVlvH;                                          */
/*  output uint8 VLVACTINMON_u8Timer7;                                        */
/*  output boolean VlvAct_bAcvInHotStuckFctDgAgRead;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidHotStkDefServoDet(void)
{
   boolean bLocalTimeOut1Prev;
   uint32  u32LocalTimer7;


   bLocalTimeOut1Prev = VlvAct_bAcvInHotStuckFctDgAgRead;
   if (VlvAct_nInVlvAmpH_C == 0)
   {
      VlvAct_tiDlyInVlvH = 255;
   }
   else
   {
      u32LocalTimer7 = ( (VlvAct_agInVlvAmp * 75)
                       / VlvAct_nInVlvAmpH_C)
                     + (VlvAct_tiOfsInVlvH_C * 3);
      VlvAct_tiDlyInVlvH = (uint8)(MATHSRV_udtMIN(u32LocalTimer7, 255));
   }
   if (  (VLVACTINMON_bAcvInHotStkFctDgPrv == 0)
      && (VLVACTINMON_bAcvInHotStuckFctDg != 0))
   {
      VLVACTINMON_u8Timer7 = VlvAct_tiDlyInVlvH;
      if (VLVACTINMON_u8Timer7 == 0)
      {
         VlvAct_bAcvInHotStuckFctDgAgRead = 1;
         if (bLocalTimeOut1Prev == 0)
         {
            VLVACTINMON_vidFstHotStkTempTest();
         }
      }
      else
      {
         VlvAct_bAcvInHotStuckFctDgAgRead = 0;
      }
   }
   else
   {
      if (VLVACTINMON_u8Timer7 > 0)
      {
         VLVACTINMON_u8Timer7 = (uint8)(VLVACTINMON_u8Timer7 - 1);
         if (VLVACTINMON_u8Timer7 == 0)
         {
            VlvAct_bAcvInHotStuckFctDgAgRead = 1;
            if (bLocalTimeOut1Prev == 0)
            {
               VLVACTINMON_vidFstHotStkTempTest();
            }
         }
         else
         {
            VlvAct_bAcvInHotStuckFctDgAgRead = 0;
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidFstHotStkTempTest                           */
/* !Description :  Ce bloc compare la différence entre l'angle mesurée et     */
/*                 l'angle de départ à un seuil minimum d'écart de boucle pour*/
/*                 le premier test de temporisation si la VVT admission est   */
/*                 bloquée à chaud                                            */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_agCkOpInVlvEstimRef0;                                    */
/*  input sint8 VlvAct_agInVlvH;                                              */
/*  input sint8 VlvAct_agInVlvIni;                                            */
/*  input uint8 VlvAct_agInVlvDifH;                                           */
/*  input sint8 VlvAct_agInVlvDifThdMin_C;                                    */
/*  output sint8 VlvAct_agInVlvH;                                             */
/*  output uint8 VlvAct_agInVlvDifH;                                          */
/*  output boolean VlvAct_bInAgDftHStuck;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidFstHotStkTempTest(void)
{
   sint16 s16LocalDiff;
   sint16 s16LocalExt_agCkOpInVlvEstimRef0;
   sint16 s16LocalVlvAct_agInVlvH;


   VEMS_vidGET(Ext_agCkOpInVlvEstimRef0, s16LocalExt_agCkOpInVlvEstimRef0);

   if (s16LocalExt_agCkOpInVlvEstimRef0 >= 0)
   {
      s16LocalVlvAct_agInVlvH =
         (sint16)((s16LocalExt_agCkOpInVlvEstimRef0 + 4) / 8);
   }
   else
   {
      s16LocalVlvAct_agInVlvH =
         (sint16)((s16LocalExt_agCkOpInVlvEstimRef0 - 4) / 8);
   }
   VlvAct_agInVlvH =
      (sint8)MATHSRV_udtCLAMP(s16LocalVlvAct_agInVlvH, -128, 127);

   s16LocalDiff = (sint16)(VlvAct_agInVlvH - VlvAct_agInVlvIni);
   VlvAct_agInVlvDifH = (uint8)MATHSRV_udtABS(s16LocalDiff);

   if (VlvAct_agInVlvDifH < VlvAct_agInVlvDifThdMin_C)
   {
      VlvAct_bInAgDftHStuck = 1;
   }
   else
   {
      VlvAct_bInAgDftHStuck = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidPosStatErrorDiag                            */
/* !Description :  ce bloc calcule la différence entre la position du         */
/*                 déphaseur AAC admission mesurée et la consigne et en       */
/*                 fonction de la valeur de la différence par rapport à l’un  */
/*                 ou l’autre des seuils les diagnostics sont levés.          */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_09_06381_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void VLVACTINMON_vidTime_index_reset();                       */
/*  input boolean VlvAct_bAcvInServo;                                         */
/*  input uint8 VlvSys_agCkOpInVlvReqRef0;                                    */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean VLVACTINMON_bAcvInServoPrev;                                */
/*  input uint16 VlvAct_nEngMinInVlv_C;                                       */
/*  input uint16 VlvAct_tiInVlvPosStatThd_C;                                  */
/*  input sint8 VlvSys_agCkOpInVlvReqRef0_int;                                */
/*  input uint16 VlvAct_nInSpPosSpd;                                          */
/*  input uint16 VlvAct_nInVlvPosStatThd_C;                                   */
/*  input boolean VlvAct_bMonRunDifPos1VlvActIn;                              */
/*  input uint16 VlvAct_tiInVlvPosStat;                                       */
/*  input boolean VlvAct_bInAcvDifDg;                                         */
/*  input sint16 Ext_agCkOpInVlvEstimRef0;                                    */
/*  input sint16 VlvAct_agInVlvPosDif;                                        */
/*  input sint16 VlvAct_agInVlvPosDif1_C;                                     */
/*  input sint16 VlvAct_agInVlvPosDif2_C;                                     */
/*  output sint8 VlvSys_agCkOpInVlvReqRef0_int;                               */
/*  output boolean VlvAct_bMonRunDifPos1VlvActIn;                             */
/*  output boolean VlvAct_bMonRunDifPos2VlvActIn;                             */
/*  output boolean VlvAct_bMonRunDifNeg1VlvActIn;                             */
/*  output boolean VlvAct_bMonRunDifNeg2VlvActIn;                             */
/*  output uint16 VlvAct_nInSpPosSpd;                                         */
/*  output boolean VlvAct_bInAcvDifDg;                                        */
/*  output boolean VlvAct_bInAcvDifNegDg;                                     */
/*  output sint16 VlvAct_agInVlvPosDif;                                       */
/*  output boolean VlvAct_bDgoDifPos1VlvActIn;                                */
/*  output boolean VlvAct_bDgoDifPos2VlvActIn;                                */
/*  output uint16 VlvAct_tiInVlvPosStat;                                      */
/*  output boolean VLVACTINMON_bAcvInServoPrev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidPosStatErrorDiag(void)
{
   boolean bLocalVlvAct_bAcvInServo;
   boolean bLocalInhVlvActInMon;
   uint8   u8LocalVlvSys_agCkOpInVlvReqRf0;
   uint16  u16LocalExt_nEng;
   sint16  s16LocalExt_agCkOpInVlvEstimRf0;
   sint16  s16Localdiff;
   sint16  s16Localdiv;
   uint32  u32LocalVlvAct_tiInVlvPosStat;
   sint32  s32LocalVlvAct_agInVlvPosDif;


   VEMS_vidGET(VlvAct_bAcvInServo, bLocalVlvAct_bAcvInServo);
   VEMS_vidGET(VlvSys_agCkOpInVlvReqRef0, u8LocalVlvSys_agCkOpInVlvReqRf0);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   if (  (VLVACTINMON_bAcvInServoPrev == 0)
      && (bLocalVlvAct_bAcvInServo != 0))
   {
      VlvSys_agCkOpInVlvReqRef0_int = (sint8)( u8LocalVlvSys_agCkOpInVlvReqRf0
                                             - 128);
   }

   bLocalInhVlvActInMon = GDGAR_bGetFRM(FRM_FRM_INHVLVACTINMON);
   if (  (bLocalVlvAct_bAcvInServo != 0)
      && (u16LocalExt_nEng > VlvAct_nEngMinInVlv_C)
      && (bLocalInhVlvActInMon == 0))
   {
      VlvAct_bMonRunDifPos1VlvActIn = 1;
      VlvAct_bMonRunDifPos2VlvActIn = 1;
      VlvAct_bMonRunDifNeg1VlvActIn = 1;
      VlvAct_bMonRunDifNeg2VlvActIn = 1;
   }
   else
   {
      VlvAct_bMonRunDifPos1VlvActIn = 0;
      VlvAct_bMonRunDifPos2VlvActIn = 0;
      VlvAct_bMonRunDifNeg1VlvActIn = 0;
      VlvAct_bMonRunDifNeg2VlvActIn = 0;
   }
   if (VlvAct_tiInVlvPosStatThd_C != 0)
   {
      s16Localdiff = (sint16)( (u8LocalVlvSys_agCkOpInVlvReqRf0 - 128)
                             - VlvSys_agCkOpInVlvReqRef0_int);
      s16Localdiv = (sint16)((s16Localdiff * 75) / VlvAct_tiInVlvPosStatThd_C);
      VlvAct_nInSpPosSpd = (uint16)MATHSRV_udtABS(s16Localdiv);
   }
   else
   {
      VlvAct_nInSpPosSpd = 65535;
   }
   if (VlvAct_nInSpPosSpd < VlvAct_nInVlvPosStatThd_C)
   {
      VlvAct_bInAcvDifDg = 1;
   }
   else
   {
      VlvAct_bInAcvDifDg =0;
   }

   if (VlvAct_bMonRunDifPos1VlvActIn != 0)
   {
      u32LocalVlvAct_tiInVlvPosStat = (uint32)(VlvAct_tiInVlvPosStat + 1);
   }
   else
   {
      u32LocalVlvAct_tiInVlvPosStat = 0;
   }
   if (  (VlvAct_tiInVlvPosStatThd_C < u32LocalVlvAct_tiInVlvPosStat)
      && (VlvAct_bInAcvDifDg != 0))
   {
      VEMS_vidGET(Ext_agCkOpInVlvEstimRef0, s16LocalExt_agCkOpInVlvEstimRf0);
      VlvAct_bInAcvDifNegDg = 1;
      s32LocalVlvAct_agInVlvPosDif =
         (sint32)( s16LocalExt_agCkOpInVlvEstimRf0
                 - ( (u8LocalVlvSys_agCkOpInVlvReqRf0 * 8)
                   - 1024));
      VlvAct_agInVlvPosDif =
         (sint16)MATHSRV_udtCLAMP(s32LocalVlvAct_agInVlvPosDif, -1024, 1023);
   }
   else
   {
      VlvAct_bInAcvDifNegDg = 0;
      VlvAct_agInVlvPosDif = 0;
   }
   if (VlvAct_agInVlvPosDif > VlvAct_agInVlvPosDif1_C)
   {
      if (VlvAct_agInVlvPosDif > VlvAct_agInVlvPosDif2_C)
      {
         VlvAct_bDgoDifPos1VlvActIn = 0;
         VlvAct_bDgoDifPos2VlvActIn = 1;
      }
      else
      {
         VlvAct_bDgoDifPos1VlvActIn = 1;
         VlvAct_bDgoDifPos2VlvActIn = 0;
      }
   }
   else
   {
      VlvAct_bDgoDifPos1VlvActIn = 0;
      VlvAct_bDgoDifPos2VlvActIn = 0;
   }
   VlvAct_tiInVlvPosStat =
      (uint16)MATHSRV_udtMIN(u32LocalVlvAct_tiInVlvPosStat, 65535);
   if (  (VlvAct_tiInVlvPosStatThd_C < VlvAct_tiInVlvPosStat)
      || (VlvAct_bInAcvDifDg == 0))
   {
      VLVACTINMON_vidTime_index_reset();
   }
   VLVACTINMON_bAcvInServoPrev = bLocalVlvAct_bAcvInServo;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidTime_index_reset                            */
/* !Description :  ce module initialise l'intervalle de temps pour le         */
/*                 déclenchement des diagnostics.                             */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 VlvSys_agCkOpInVlvReqRef0;                                    */
/*  output sint8 VlvSys_agCkOpInVlvReqRef0_int;                               */
/*  output uint16 VlvAct_tiInVlvPosStat;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidTime_index_reset(void)
{
   uint8  u8LocalVlvSys_agCkOpInVlvReqRf0;


   VEMS_vidGET(VlvSys_agCkOpInVlvReqRef0, u8LocalVlvSys_agCkOpInVlvReqRf0);
   VlvSys_agCkOpInVlvReqRef0_int = (sint8)( u8LocalVlvSys_agCkOpInVlvReqRf0
                                          - 128);
   VlvAct_tiInVlvPosStat = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidNegStatErrorDiag                            */
/* !Description :  ce module calcule la différence entre la consigne et la    */
/*                 position du déphaseur cette différence est ensuite comparée*/
/*                 à deux seuils et en fonction de la valeur de la différence */
/*                 par rapport aux seuils les diagnostics sont levés.         */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_09_06381_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean VlvAct_bInAcvDifNegDg;                                      */
/*  input uint8 VlvSys_agCkOpInVlvReqRef0;                                    */
/*  input sint16 Ext_agCkOpInVlvEstimRef0;                                    */
/*  input sint16 VlvAct_agInVlvNegDif;                                        */
/*  input sint16 VlvAct_agInVlvNegDif1_C;                                     */
/*  input sint16 VlvAct_agInVlvNegDif2_C;                                     */
/*  output sint16 VlvAct_agInVlvNegDif;                                       */
/*  output boolean VlvAct_bDgoDifNeg1VlvActIn;                                */
/*  output boolean VlvAct_bDgoDifNeg2VlvActIn;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidNegStatErrorDiag(void)
{
   uint8  u8LocalVlvSys_agCkOpInVlvReqRf0;
   sint16 s16LocalExt_agCkOpInVlvEstimRf0;
   sint32 s32LocalVlvAct_agInVlvNegDif;


   if (VlvAct_bInAcvDifNegDg != 0)
   {
      VEMS_vidGET(VlvSys_agCkOpInVlvReqRef0, u8LocalVlvSys_agCkOpInVlvReqRf0);
      VEMS_vidGET(Ext_agCkOpInVlvEstimRef0, s16LocalExt_agCkOpInVlvEstimRf0);
      s32LocalVlvAct_agInVlvNegDif =
         (sint32)( (u8LocalVlvSys_agCkOpInVlvReqRf0 * 8)
                 - (s16LocalExt_agCkOpInVlvEstimRf0 + 1024));
      VlvAct_agInVlvNegDif =
         (sint16)MATHSRV_udtCLAMP(s32LocalVlvAct_agInVlvNegDif, -1024, 1023);
   }
   else
   {
      VlvAct_agInVlvNegDif = 0;
   }
   if (VlvAct_agInVlvNegDif > VlvAct_agInVlvNegDif1_C)
   {
      if (VlvAct_agInVlvNegDif > VlvAct_agInVlvNegDif2_C)
      {
         VlvAct_bDgoDifNeg1VlvActIn = 0;
         VlvAct_bDgoDifNeg2VlvActIn = 1;
      }
      else
      {
         VlvAct_bDgoDifNeg1VlvActIn = 1;
         VlvAct_bDgoDifNeg2VlvActIn = 0;
      }
   }
   else
   {
      VlvAct_bDgoDifNeg1VlvActIn = 0;
      VlvAct_bDgoDifNeg2VlvActIn = 0;
   }
}
/*--------------------------------- end of file ------------------------------*/