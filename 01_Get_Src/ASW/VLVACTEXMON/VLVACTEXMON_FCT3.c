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
/* !File            : VLVACTEXMON_FCT3.C                                      */
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
/*   1 / VLVACTEXMON_vidHotStkDiagComp                                        */
/*   2 / VLVACTEXMON_vidHotStkDiagActCond                                     */
/*   3 / VLVACTEXMON_vidHotStkDiagCalc                                        */
/*   4 / VLVACTEXMON_vidHotStkDefServoDet                                     */
/*   5 / VLVACTEXMON_vidFstHotStkTempTest                                     */
/*   6 / VLVACTEXMON_vidPosStatErrorDiag                                      */
/*   7 / VLVACTEXMON_vidTime_index_reset                                      */
/*   8 / VLVACTEXMON_vidNegStatErrorDiag                                      */
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
/* !Function    :  VLVACTEXMON_vidHotStkDiagComp                              */
/* !Description :  Ce bloc vérifie si la VVT échappement est bloquée à chaud  */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXMON_vidHotStkDiagActCond();                      */
/*  extf argret void VLVACTEXMON_vidHotStkDiagCalc();                         */
/*  input boolean VlvAct_bAcvExHotStuckFctDg;                                 */
/*  input boolean VlvAct_bExVlvSpAmpVarldc;                                   */
/*  input boolean VlvAct_bMonRunExHotStuckFctDg;                              */
/*  input boolean VLVACTEXMON_bAcvExHotStuckFctDg;                            */
/*  output boolean VlvAct_bMonRunExHotStuckFctDg;                             */
/*  output boolean VLVACTEXMON_bAcvExHotStuckFctDg;                           */
/*  output boolean VLVACTEXMON_bAcvExHotStkFctDgPrv;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidHotStkDiagComp(void)
{
   VLVACTEXMON_vidHotStkDiagActCond();
   VlvAct_bMonRunExHotStuckFctDg = VlvAct_bAcvExHotStuckFctDg;
   if (  (VlvAct_bAcvExHotStuckFctDg != 0)
      && (VlvAct_bExVlvSpAmpVarldc != 0))
   {
      VLVACTEXMON_bAcvExHotStuckFctDg = 1;
   }
   else
   {
      VLVACTEXMON_bAcvExHotStuckFctDg = 0;
   }
   if (VlvAct_bMonRunExHotStuckFctDg != 0)
   {
      VLVACTEXMON_vidHotStkDiagCalc();
   }
   VLVACTEXMON_bAcvExHotStkFctDgPrv = VLVACTEXMON_bAcvExHotStuckFctDg;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidHotStkDiagActCond                           */
/* !Description :  Ce bloc calcule l’activation du diagnostic fonctionnel     */
/*                 déphaseur bloqué à chaud de la VVT échappement             */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_09_06481_008.02                                     */
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
/*  input uint8 VlvAct_agExVlvAmpThdMin_C;                                    */
/*  output boolean VlvAct_bAcvExHotStuckFctDg;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidHotStkDiagActCond(void)
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
      && (VlvAct_agExVlvAmp > VlvAct_agExVlvAmpThdMin_C)
      && (bLocalInhVlvActExMon == 0))
   {
      VlvAct_bAcvExHotStuckFctDg = 1;
   }
   else
   {
      VlvAct_bAcvExHotStuckFctDg = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidHotStkDiagCalc                              */
/* !Description :  Ce bloc calcule le diagnostic fonctionnel si la VVT        */
/*                 échappement est bloquée à chaud                            */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXMON_vidHotStkDefServoDet();                      */
/*  input boolean VlvAct_bExAgDftHStuck;                                      */
/*  input sint8 VlvAct_agExVlvThdMin_C;                                       */
/*  input sint8 VlvAct_agExVlvH;                                              */
/*  input sint8 VlvAct_agExVlvThdMax_C;                                       */
/*  output boolean VlvAct_bDgoStuckH1VlvActEx;                                */
/*  output boolean VlvAct_bDgoStuckH2VlvActEx;                                */
/*  output boolean VlvAct_bDgoStuckH3VlvActEx;                                */
/*  output boolean VlvAct_bDgoStuckHVlvActEx;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidHotStkDiagCalc(void)
{
   VLVACTEXMON_vidHotStkDefServoDet();
   if (  (VlvAct_bExAgDftHStuck != 0)
      && (VlvAct_agExVlvThdMin_C < VlvAct_agExVlvH))
   {
      VlvAct_bDgoStuckH1VlvActEx = 1;
   }
   else
   {
      VlvAct_bDgoStuckH1VlvActEx = 0;
   }

   if (  (VlvAct_bExAgDftHStuck != 0)
      && (VlvAct_agExVlvThdMin_C >= VlvAct_agExVlvH)
      && (VlvAct_agExVlvThdMax_C <= VlvAct_agExVlvH))
   {
      VlvAct_bDgoStuckH2VlvActEx = 1;
   }
   else
   {
      VlvAct_bDgoStuckH2VlvActEx = 0;
   }

   if (  (VlvAct_bExAgDftHStuck != 0)
      && (VlvAct_agExVlvThdMin_C >= VlvAct_agExVlvH)
      && (VlvAct_agExVlvThdMax_C > VlvAct_agExVlvH))
   {
      VlvAct_bDgoStuckH3VlvActEx = 1;
   }
   else
   {
      VlvAct_bDgoStuckH3VlvActEx = 0;
   }

   if (VlvAct_bExAgDftHStuck != 0)
   {
      VlvAct_bDgoStuckHVlvActEx = 1;
   }
   else
   {
      VlvAct_bDgoStuckHVlvActEx = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidHotStkDefServoDet                           */
/* !Description :  Ce bloc calcule la valeur absolue de la différence entre   */
/*                 l'angle mesurée et l’angle de départ si la VVT échappement */
/*                 est bloquée à chaud                                        */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_09_06481_007.02                                     */
/*                 VEMS_R_09_06481_009.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXMON_vidFstHotStkTempTest();                      */
/*  input boolean VlvAct_bAcvExHotStuckFctDgAgRead;                           */
/*  input uint8 VlvAct_nExVlvAmpH_C;                                          */
/*  input uint8 VlvAct_agExVlvAmp;                                            */
/*  input uint8 VlvAct_tiOfsExVlvH_C;                                         */
/*  input boolean VLVACTEXMON_bAcvExHotStkFctDgPrv;                           */
/*  input boolean VLVACTEXMON_bAcvExHotStuckFctDg;                            */
/*  input uint8 VlvAct_tiDlyExVlvH;                                           */
/*  input uint8 VLVACTEXMON_u8Timer7;                                         */
/*  output uint8 VlvAct_tiDlyExVlvH;                                          */
/*  output uint8 VLVACTEXMON_u8Timer7;                                        */
/*  output boolean VlvAct_bAcvExHotStuckFctDgAgRead;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidHotStkDefServoDet(void)
{
   boolean bLocalTimeOut1Prev;
   uint32  u32LocalTimer7;


   bLocalTimeOut1Prev = VlvAct_bAcvExHotStuckFctDgAgRead;
   if (VlvAct_nExVlvAmpH_C == 0)
   {
      VlvAct_tiDlyExVlvH = 255;
   }
   else
   {
      u32LocalTimer7 = ( (VlvAct_agExVlvAmp * 75)
                       / VlvAct_nExVlvAmpH_C)
                     + (VlvAct_tiOfsExVlvH_C * 3);
      VlvAct_tiDlyExVlvH = (uint8)(MATHSRV_udtMIN(u32LocalTimer7, 255));
   }
   if (  (VLVACTEXMON_bAcvExHotStkFctDgPrv == 0)
      && (VLVACTEXMON_bAcvExHotStuckFctDg != 0))
   {
      VLVACTEXMON_u8Timer7 = VlvAct_tiDlyExVlvH;
      if (VLVACTEXMON_u8Timer7 == 0)
      {
         VlvAct_bAcvExHotStuckFctDgAgRead = 1;
         if (bLocalTimeOut1Prev == 0)
         {
            VLVACTEXMON_vidFstHotStkTempTest();
         }
      }
      else
      {
         VlvAct_bAcvExHotStuckFctDgAgRead = 0;
      }
   }
   else
   {
      if (VLVACTEXMON_u8Timer7 > 0)
      {
         VLVACTEXMON_u8Timer7 = (uint8)(VLVACTEXMON_u8Timer7 - 1);
         if (VLVACTEXMON_u8Timer7 == 0)
         {
            VlvAct_bAcvExHotStuckFctDgAgRead = 1;
            if (bLocalTimeOut1Prev == 0)
            {
               VLVACTEXMON_vidFstHotStkTempTest();
            }
         }
         else
         {
            VlvAct_bAcvExHotStuckFctDgAgRead = 0;
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidFstHotStkTempTest                           */
/* !Description :  Ce bloc compare la différence entre l'angle mesurée et     */
/*                 l'angle de départ à un seuil minimum d'écart de boucle pour*/
/*                 le premier test de temporisation si la VVT échappement est */
/*                 bloquée à chaud                                            */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_agCkClsExVlvEstimRef0;                                   */
/*  input sint8 VlvAct_agExVlvH;                                              */
/*  input sint8 VlvAct_agExVlvIni;                                            */
/*  input uint8 VlvAct_agExVlvDifH;                                           */
/*  input sint8 VlvAct_agExVlvDifThdMin_C;                                    */
/*  output sint8 VlvAct_agExVlvH;                                             */
/*  output uint8 VlvAct_agExVlvDifH;                                          */
/*  output boolean VlvAct_bExAgDftHStuck;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidFstHotStkTempTest(void)
{
   sint16 s16LocalDiff;
   sint16 s16LocalExt_agCkClsExVlvEstimRf0;
   sint16 s16LocalVlvAct_agExVlvH;


   VEMS_vidGET(Ext_agCkClsExVlvEstimRef0, s16LocalExt_agCkClsExVlvEstimRf0);

   if (s16LocalExt_agCkClsExVlvEstimRf0 >= 0)
   {
      s16LocalVlvAct_agExVlvH =
         (sint16)((s16LocalExt_agCkClsExVlvEstimRf0 + 4) / 8);
   }
   else
   {
      s16LocalVlvAct_agExVlvH =
         (sint16)((s16LocalExt_agCkClsExVlvEstimRf0 - 4) / 8);
   }
   VlvAct_agExVlvH =
      (sint8)MATHSRV_udtCLAMP(s16LocalVlvAct_agExVlvH, -128, 127);

   s16LocalDiff = (sint16)(VlvAct_agExVlvH - VlvAct_agExVlvIni);
   VlvAct_agExVlvDifH = (uint8)MATHSRV_udtABS(s16LocalDiff);


   if (VlvAct_agExVlvDifH < VlvAct_agExVlvDifThdMin_C)
   {
      VlvAct_bExAgDftHStuck = 1;
   }
   else
   {
      VlvAct_bExAgDftHStuck = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidPosStatErrorDiag                            */
/* !Description :  ce bloc calcule la différence entre la position du         */
/*                 déphaseur AAC échappement mesurée et la consigne et en     */
/*                 fonction de la valeur de la différence par rapport à l’un  */
/*                 ou l’autre des seuils les diagnostics sont levés.          */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_09_06481_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void VLVACTEXMON_vidTime_index_reset();                       */
/*  input boolean VlvAct_bAcvExServo;                                         */
/*  input uint8 VlvSys_agCkClsExVlvReqRef0;                                   */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean VLVACTEXMON_bAcvExServoPrev;                                */
/*  input uint16 VlvAct_nEngMinExVlv_C;                                       */
/*  input uint16 VlvAct_tiExVlvPosStatThd_C;                                  */
/*  input sint8 VlvSys_agCkClsExVlvReqRef0_int;                               */
/*  input uint16 VlvAct_nExSpPosSpd;                                          */
/*  input uint16 VlvAct_nExVlvPosStatThd_C;                                   */
/*  input boolean VlvAct_bMonRunDifPos1VlvActEx;                              */
/*  input uint16 VlvAct_tiExVlvPosStat;                                       */
/*  input boolean VlvAct_bExAcvDifDg;                                         */
/*  input sint16 Ext_agCkClsExVlvEstimRef0;                                   */
/*  input sint16 VlvAct_agExVlvPosDif;                                        */
/*  input sint16 VlvAct_agExVlvPosDif1_C;                                     */
/*  input sint16 VlvAct_agExVlvPosDif2_C;                                     */
/*  output sint8 VlvSys_agCkClsExVlvReqRef0_int;                              */
/*  output boolean VlvAct_bMonRunDifPos1VlvActEx;                             */
/*  output boolean VlvAct_bMonRunDifPos2VlvActEx;                             */
/*  output boolean VlvAct_bMonRunDifNeg1VlvActEx;                             */
/*  output boolean VlvAct_bMonRunDifNeg2VlvActEx;                             */
/*  output uint16 VlvAct_nExSpPosSpd;                                         */
/*  output boolean VlvAct_bExAcvDifDg;                                        */
/*  output boolean VlvAct_bExAcvDifNegDg;                                     */
/*  output sint16 VlvAct_agExVlvPosDif;                                       */
/*  output boolean VlvAct_bDgoDifPos1VlvActEx;                                */
/*  output boolean VlvAct_bDgoDifPos2VlvActEx;                                */
/*  output uint16 VlvAct_tiExVlvPosStat;                                      */
/*  output boolean VLVACTEXMON_bAcvExServoPrev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidPosStatErrorDiag(void)
{
   boolean bLocalVlvAct_bAcvExServo;
   boolean bLocalInhVlvActExMon;
   uint8   u8LocalVlvSys_agCkClsExVlvReqRf0;
   uint16  u16LocalExt_nEng;
   sint16  s16LocalExt_agCkClsExVlvEstimRf0;
   sint16  s16Localdiff;
   sint16  s16Localdiv;
   uint32  u32LocalVlvAct_tiExVlvPosStat;
   sint32  s32LocalVlvAct_agExVlvPosDif;


   VEMS_vidGET(VlvAct_bAcvExServo, bLocalVlvAct_bAcvExServo);
   VEMS_vidGET(VlvSys_agCkClsExVlvReqRef0, u8LocalVlvSys_agCkClsExVlvReqRf0);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   if (  (VLVACTEXMON_bAcvExServoPrev == 0)
      && (bLocalVlvAct_bAcvExServo != 0))
   {
      VlvSys_agCkClsExVlvReqRef0_int =
         (sint8)(u8LocalVlvSys_agCkClsExVlvReqRf0 - 128);
   }

   bLocalInhVlvActExMon = GDGAR_bGetFRM(FRM_FRM_INHVLVACTEXMON);
   if (  (bLocalVlvAct_bAcvExServo != 0)
      && (u16LocalExt_nEng > VlvAct_nEngMinExVlv_C)
      && (bLocalInhVlvActExMon == 0))
   {
      VlvAct_bMonRunDifPos1VlvActEx = 1;
      VlvAct_bMonRunDifPos2VlvActEx = 1;
      VlvAct_bMonRunDifNeg1VlvActEx = 1;
      VlvAct_bMonRunDifNeg2VlvActEx = 1;
   }
   else
   {
      VlvAct_bMonRunDifPos1VlvActEx = 0;
      VlvAct_bMonRunDifPos2VlvActEx = 0;
      VlvAct_bMonRunDifNeg1VlvActEx = 0;
      VlvAct_bMonRunDifNeg2VlvActEx = 0;
   }
   if (VlvAct_tiExVlvPosStatThd_C != 0)
   {
      s16Localdiff =
         (sint16)( (u8LocalVlvSys_agCkClsExVlvReqRf0 - 128)
                 - VlvSys_agCkClsExVlvReqRef0_int);
      s16Localdiv = (sint16)((s16Localdiff * 75) / VlvAct_tiExVlvPosStatThd_C);
      VlvAct_nExSpPosSpd = (uint16)MATHSRV_udtABS(s16Localdiv);
   }
   else
   {
      VlvAct_nExSpPosSpd = 65535;
   }
   if (VlvAct_nExSpPosSpd < VlvAct_nExVlvPosStatThd_C)
   {
      VlvAct_bExAcvDifDg = 1;
   }
   else
   {
      VlvAct_bExAcvDifDg = 0;
   }

   if (VlvAct_bMonRunDifPos1VlvActEx != 0)
   {
      u32LocalVlvAct_tiExVlvPosStat = (uint32)(VlvAct_tiExVlvPosStat + 1);
   }
   else
   {
      u32LocalVlvAct_tiExVlvPosStat = 0;
   }
   if (  (VlvAct_tiExVlvPosStatThd_C <= u32LocalVlvAct_tiExVlvPosStat)
      && (VlvAct_bExAcvDifDg != 0))
   {
      VEMS_vidGET(Ext_agCkClsExVlvEstimRef0, s16LocalExt_agCkClsExVlvEstimRf0);
      VlvAct_bExAcvDifNegDg = 1;
      s32LocalVlvAct_agExVlvPosDif =
         (sint32)( s16LocalExt_agCkClsExVlvEstimRf0
                 - ( ( u8LocalVlvSys_agCkClsExVlvReqRf0 * 8) - 1024));
      VlvAct_agExVlvPosDif =
         (sint16)MATHSRV_udtCLAMP(s32LocalVlvAct_agExVlvPosDif, -1024, 1023);
   }
   else
   {
      VlvAct_bExAcvDifNegDg = 0;
      VlvAct_agExVlvPosDif = 0;
   }
   if (VlvAct_agExVlvPosDif > VlvAct_agExVlvPosDif1_C)
   {
      if (VlvAct_agExVlvPosDif > VlvAct_agExVlvPosDif2_C)
      {
         VlvAct_bDgoDifPos1VlvActEx = 0;
         VlvAct_bDgoDifPos2VlvActEx = 1;
      }
      else
      {
         VlvAct_bDgoDifPos1VlvActEx = 1;
         VlvAct_bDgoDifPos2VlvActEx = 0;
      }
   }
   else
   {
      VlvAct_bDgoDifPos1VlvActEx = 0;
      VlvAct_bDgoDifPos2VlvActEx = 0;
   }

   VlvAct_tiExVlvPosStat = (uint16)MATHSRV_udtMIN(u32LocalVlvAct_tiExVlvPosStat,
                                                  65535);
   if (  (VlvAct_tiExVlvPosStatThd_C < VlvAct_tiExVlvPosStat)
      || (VlvAct_bExAcvDifDg == 0))
   {
      VLVACTEXMON_vidTime_index_reset();
   }
   VLVACTEXMON_bAcvExServoPrev = bLocalVlvAct_bAcvExServo;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidTime_index_reset                            */
/* !Description :  ce module initialise l'intervalle de temps pour le         */
/*                 déclenchement des diagnostics.                             */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 VlvSys_agCkClsExVlvReqRef0;                                   */
/*  output sint8 VlvSys_agCkClsExVlvReqRef0_int;                              */
/*  output uint16 VlvAct_tiExVlvPosStat;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidTime_index_reset(void)
{
   uint8  u8LocalVlvSys_agCkClsExVlvReqRf0;


   VEMS_vidGET(VlvSys_agCkClsExVlvReqRef0, u8LocalVlvSys_agCkClsExVlvReqRf0);
   VlvSys_agCkClsExVlvReqRef0_int = (sint8)( u8LocalVlvSys_agCkClsExVlvReqRf0
                                           - 128);
   VlvAct_tiExVlvPosStat = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidNegStatErrorDiag                            */
/* !Description :  ce module calcule la différence entre la consigne et la    */
/*                 position du déphaseur cette différence est ensuite comparée*/
/*                 à deux seuils et en fonction de la valeur de la différence */
/*                 par rapport aux seuils les diagnostics sont levés.         */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_09_06481_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 VlvSys_agCkClsExVlvReqRef0;                                   */
/*  input sint16 Ext_agCkClsExVlvEstimRef0;                                   */
/*  input boolean VlvAct_bExAcvDifNegDg;                                      */
/*  input sint16 VlvAct_agExVlvNegDif;                                        */
/*  input sint16 VlvAct_agExVlvNegDif1_C;                                     */
/*  input sint16 VlvAct_agExVlvNegDif2_C;                                     */
/*  output sint16 VlvAct_agExVlvNegDif;                                       */
/*  output boolean VlvAct_bDgoDifNeg1VlvActEx;                                */
/*  output boolean VlvAct_bDgoDifNeg2VlvActEx;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidNegStatErrorDiag(void)
{
   uint8  u8LocalVlvSys_agCkClsExVlvReqRf0;
   sint16 s16LocalExt_agCkClsExVlvEstimRf0;
   sint32 s32LocalVlvAct_agExVlvNegDif;


   VEMS_vidGET(VlvSys_agCkClsExVlvReqRef0, u8LocalVlvSys_agCkClsExVlvReqRf0);
   VEMS_vidGET(Ext_agCkClsExVlvEstimRef0, s16LocalExt_agCkClsExVlvEstimRf0);
   if (VlvAct_bExAcvDifNegDg != 0)
   {
      s32LocalVlvAct_agExVlvNegDif =
         (sint32)( (u8LocalVlvSys_agCkClsExVlvReqRf0 * 8)
                 - (s16LocalExt_agCkClsExVlvEstimRf0 + 1024));
      VlvAct_agExVlvNegDif =
         (sint16)MATHSRV_udtCLAMP(s32LocalVlvAct_agExVlvNegDif, -1024, 1023);
   }
   else
   {
      VlvAct_agExVlvNegDif = 0;
   }
   if (VlvAct_agExVlvNegDif > VlvAct_agExVlvNegDif1_C)
   {
      if (VlvAct_agExVlvNegDif > VlvAct_agExVlvNegDif2_C)
      {
         VlvAct_bDgoDifNeg1VlvActEx = 0;
         VlvAct_bDgoDifNeg2VlvActEx = 1;
      }
      else
      {
         VlvAct_bDgoDifNeg1VlvActEx = 1;
         VlvAct_bDgoDifNeg2VlvActEx = 0;
      }
   }
   else
   {
      VlvAct_bDgoDifNeg1VlvActEx = 0;
      VlvAct_bDgoDifNeg2VlvActEx = 0;
   }
}
/*--------------------------------- end of file ------------------------------*/