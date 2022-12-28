/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GDU                                                     */
/* !Description     : GDU Component.                                          */
/*                                                                            */
/* !Module          : GDU                                                     */
/* !Description     : SINGLE FAILURE MANAGER                                  */
/*                                                                            */
/* !File            : GDU_FCT1.c                                              */
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
/*   1 / GDU_vidF01_CntDet                                                    */
/*   2 / GDU_vidF02_IniCntDet                                                 */
/*   3 / GDU_vidF03_IniCntDetScanTool                                         */
/*   4 / GDU_vidF04_IniCntDetGlbDCStrt                                        */
/*   5 / GDU_vidF01_EndDiag                                                   */
/*   6 / GDU_vidF02_IniEndDiag                                                */
/*   7 / GDU_vidF03_IniEndDiagScanTool                                        */
/*   8 / GDU_vidF06_CntDetEvents                                              */
/*   9 / GDU_vidF04_IniCntDetGlbDCStrt_opt                                    */
/*   10 / GDU_vidF06_ClearCntDetEvents                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5444560 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GDU/GDU_FCT1.c_v             $*/
/* $Revision::   1.14     $$Author::   mbenfrad       $$Date::   27 Aug 2013 $*/
/* $Author::   mbenfrad                               $$Date::   27 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "MATHSRV.h"
#include "GDU.h"
#include "GDU_L.h"
#include "GDU_IM.h"
#include "GD_api.h"
#include "GDU_callback.h"



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidF01_CntDet                                          */
/* !Description :  This function manages state of GDU manager                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint16 GDU_au16CtInc[8];                                            */
/*  input uint16 GDU_au16CtDec[8];                                            */
/*  input Std_ReturnType GD_stEventStatus[8];                                 */
/*  input GDU_tstrDft GDU_astrDftUnit[8];                                     */
/*  input uint8 GD_au8IdxClassDet[8];                                         */
/*  input GD_strClasDet GD_astrClasDet[21];                                   */
/*  input boolean GD_abThdUp;                                                 */
/*  input boolean GD_abThdDown;                                               */
/*  output GDU_tstrDft GDU_astrDftUnit[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidF01_CntDet
(
   uint16 u16DftIdx
)
{
   boolean bLocalCond1;
   boolean bLocalCond2;
   uint8   u8LocalIdxClassDet;
   uint8   u8LocalDivision;
   uint8   u8LocalRatio;
   uint16  u16LocalCtInc;
   uint16  u16LocalCtDec;
   uint16  u16LocalClasDet0;
   sint16  s16LocalMax;
   sint32  s32LocalMax;
   sint32  s32LocalInput;


   u16LocalCtInc = GDU_au16CtInc[u16DftIdx];
   u16LocalCtDec = GDU_au16CtDec[u16DftIdx];
   switch (GD_stEventStatus[u16DftIdx])
   {
      case (GD_FAILED):
         s32LocalInput = (sint32)GDU_DFT_THD;
         break;

      case (GD_PASSED):
         s32LocalInput = (sint32)(-GDU_DFT_THD);
         break;

      case (GD_PRE_FAILED):
         s16LocalMax = GDU_astrDftUnit[u16DftIdx].s16ctDet;
         s16LocalMax = (sint16)MATHSRV_udtMAX(s16LocalMax, 0);
         s32LocalInput = s16LocalMax + u16LocalCtInc;
         break;

      case (GD_PRE_PASSED):
         u8LocalIdxClassDet = GD_au8IdxClassDet[u16DftIdx];
         u16LocalClasDet0 = GD_astrClasDet[u8LocalIdxClassDet].bUpDownClasDet;
         s32LocalMax = GDU_astrDftUnit[u16DftIdx].s16ctDet;
         if (u16LocalClasDet0 == 0)
         {
            s32LocalMax = MATHSRV_udtMIN(s32LocalMax, 0);
         }
         s32LocalInput = s32LocalMax - u16LocalCtDec;
         break;

      case (GD_INIT):
         u8LocalIdxClassDet = GD_au8IdxClassDet[u16DftIdx];
         u16LocalClasDet0 = GD_astrClasDet[u8LocalIdxClassDet].bRstCntClasDet;

         if (u16LocalClasDet0 == 1)
         {
            s32LocalInput = 0;
         }
         else
         {
            s32LocalInput = (sint32)GDU_astrDftUnit[u16DftIdx].s16ctDet;
         }
         break;

      default:
         s32LocalInput = (sint32)GDU_astrDftUnit[u16DftIdx].s16ctDet;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   bLocalCond1 = 1;
   bLocalCond2 = 0;
   u8LocalDivision = (uint8)(u16DftIdx / 8);
   u8LocalRatio = (uint8)(u16DftIdx % 8);

   if (s32LocalInput >= GDU_DFT_THD)
   {
      GD_vidBitWrite(GD_abThdUp[u8LocalDivision],
                     u8LocalRatio,
                     bLocalCond1);
      GD_vidBitWrite(GD_abThdDown[u8LocalDivision],
                     u8LocalRatio,
                     bLocalCond2);
      GDU_astrDftUnit[u16DftIdx].s16ctDet = (sint16)GDU_DFT_THD;
   }
   else
   {
      if (s32LocalInput <= -GDU_DFT_THD)
      {
         GD_vidBitWrite(GD_abThdUp[u8LocalDivision],
                        u8LocalRatio,
                        bLocalCond2);
         GD_vidBitWrite(GD_abThdDown[u8LocalDivision],
                        u8LocalRatio,
                        bLocalCond1);
         GDU_astrDftUnit[u16DftIdx].s16ctDet = (sint16)(-GDU_DFT_THD);
      }
      else
      {
         GD_vidBitWrite(GD_abThdUp[u8LocalDivision],
                        u8LocalRatio,
                        bLocalCond2);
         GD_vidBitWrite(GD_abThdDown[u8LocalDivision],
                        u8LocalRatio,
                        bLocalCond2);
         GDU_astrDftUnit[u16DftIdx].s16ctDet = (sint16)s32LocalInput;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidF02_IniCntDet                                       */
/* !Description :  Set the meter detection to zero                            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean GD_abThdUp;                                                 */
/*  input boolean GD_abThdDown;                                               */
/*  output GDU_tstrDft GDU_astrDftUnit[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidF02_IniCntDet(void)
{
   sint32      s32LocalIdx;
   uint8       u8LocalDivision;
   uint8       u8LocalRatio;
   boolean     bLocalInit;

   bLocalInit = 0;
   for (s32LocalIdx=0; s32LocalIdx < GD_DFT_NB; s32LocalIdx++)
   {

      GDU_astrDftUnit[s32LocalIdx].s16ctDet = 0;

      u8LocalDivision = (uint8)(s32LocalIdx / 8);
      u8LocalRatio = (uint8)(s32LocalIdx % 8);
      GD_vidBitWrite(GD_abThdUp[u8LocalDivision],
                     u8LocalRatio,
                     bLocalInit);
      GD_vidBitWrite(GD_abThdDown[u8LocalDivision],
                     u8LocalRatio,
                     bLocalInit);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidF03_IniCntDetScanTool                               */
/* !Description :  This function initializes the parameter s16ctDet which     */
/*                 detect meter for default                                   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 GD_au8IdxClasObd[8];                                          */
/*  input GD_strClasObd GD_astrClasObd[40];                                   */
/*  input boolean GD_abThdUp;                                                 */
/*  input boolean GD_abThdDown;                                               */
/*  output GDU_tstrDft GDU_astrDftUnit[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidF03_IniCntDetScanTool(void)
{
   uint8    u8LocalIdxClassObd;
   uint16   u16LocalClasObd;
   sint32   s32LocalIdx;
   uint8    u8LocalDivision;
   uint8    u8LocalRatio;
   boolean  bLocalInit;

   bLocalInit = 0;

   for (s32LocalIdx=0; s32LocalIdx < GD_DFT_NB; s32LocalIdx++)
   {
      u8LocalIdxClassObd = GD_au8IdxClasObd[s32LocalIdx];
      u16LocalClasObd    = GD_astrClasObd[u8LocalIdxClassObd].bEnaSctl;

      if (u16LocalClasObd == 1)
      {
         GDU_astrDftUnit[s32LocalIdx].s16ctDet = 0;

         u8LocalDivision = (uint8)(s32LocalIdx / 8);
         u8LocalRatio = (uint8)(s32LocalIdx % 8);
         GD_vidBitWrite(GD_abThdUp[u8LocalDivision],
                        u8LocalRatio,
                        bLocalInit);
         GD_vidBitWrite(GD_abThdDown[u8LocalDivision],
                        u8LocalRatio,
                        bLocalInit);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidF04_IniCntDetGlbDCStrt                              */
/* !Description :  This function initializes s16ctDet at start of a global    */
/*                 driving cycle                                              */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input GDU_tstrDft GDU_astrDftUnit[8];                                     */
/*  input boolean GD_abThdUp;                                                 */
/*  input boolean GD_abThdDown;                                               */
/*  output GDU_tstrDft GDU_astrDftUnit[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidF04_IniCntDetGlbDCStrt(void)
{
   sint32   s32LocalIdx;
   sint16   s16LocalctDet;
   uint8    u8LocalDivision;
   uint8    u8LocalRatio;
   boolean  bLocalInit;

   bLocalInit = 0;

   for (s32LocalIdx=0; s32LocalIdx < GD_DFT_NB; s32LocalIdx++)
   {
      s16LocalctDet = GDU_astrDftUnit[s32LocalIdx].s16ctDet;
      if (  (s16LocalctDet == GDU_DFT_THD)
         || (s16LocalctDet == -GDU_DFT_THD))
      {
         GDU_astrDftUnit[s32LocalIdx].s16ctDet = 0;

          u8LocalDivision = (uint8)(s32LocalIdx / 8);
      u8LocalRatio = (uint8)(s32LocalIdx % 8);
      GD_vidBitWrite(GD_abThdUp[u8LocalDivision],
                     u8LocalRatio,
                     bLocalInit);
      GD_vidBitWrite(GD_abThdDown[u8LocalDivision],
                     u8LocalRatio,
                     bLocalInit);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidF01_EndDiag                                         */
/* !Description :  This function manages the parameter bEndDiagStrt           */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output GDU_tstrDft GDU_astrDftUnit[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidF01_EndDiag
(
   uint16 u16DftIdx
)
{
   GDU_astrDftUnit[u16DftIdx].bEndDiagStrt = 1;
}/* mettre a jour GDU_callback.h si cette fonction evolue */

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidF02_IniEndDiag                                      */
/* !Description :  This function initializes the parameter bEndDiagStrt       */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output GDU_tstrDft GDU_astrDftUnit[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidF02_IniEndDiag(void)
{
   sint32      s32LocalIdx;

   for (s32LocalIdx=0; s32LocalIdx < GD_DFT_NB; s32LocalIdx++)
   {
      GDU_astrDftUnit[s32LocalIdx].bEndDiagStrt = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidF03_IniEndDiagScanTool                              */
/* !Description :  This function intializes the parameter bEndDiagStrt for an */
/*                 OBD type failure by an after-sale tool                     */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 GD_au8IdxClasObd[8];                                          */
/*  input GD_strClasObd GD_astrClasObd[40];                                   */
/*  output GDU_tstrDft GDU_astrDftUnit[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidF03_IniEndDiagScanTool(void)
{
   uint8       u8LocalIdxClassObd;
   uint16      u16LocalClasObd;
   sint32      s32LocalIdx;

   for (s32LocalIdx=0; s32LocalIdx < GD_DFT_NB; s32LocalIdx++)
   {
      u8LocalIdxClassObd = GD_au8IdxClasObd[s32LocalIdx];
      u16LocalClasObd    = GD_astrClasObd[u8LocalIdxClassObd].bEnaSctl;
      if (u16LocalClasObd == 1)
      {
         GDU_astrDftUnit[s32LocalIdx].bEndDiagStrt = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidF06_CntDetEvents                                    */
/* !Description :  This function is dedicated to the creation of various      */
/*                 events linked to the fault detection counter               */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDU_vidExitEveFrfRec(argin uint16 u16IdxDft);            */
/*  extf argret void GDU_vidExitEveCDThdUp(argin uint16 u16DftIdx);           */
/*  extf argret void GDU_vidExitEveCDThd(argin uint16 u16DftIdx);             */
/*  input GD_tstrDftEep GD_astrDftEep[8];                                     */
/*  input GDU_tstrDft GDU_astrDftUnit[8];                                     */
/*  input boolean GD_abctDetPrev;                                             */
/*  input boolean GD_abThdUp;                                                 */
/*  input boolean GD_abThdDown;                                               */
/*  input boolean GD_abThdUpPrev;                                             */
/*  input boolean GD_abThdDownPrev;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidF06_CntDetEvents
(
   uint16 u16DftIdx
)
{
   boolean  bLocalStPres;
   boolean  bLocalctDet;
   boolean  bLocalctDetPrev;
   boolean  bLocalMaxValueHit;
   boolean  bLocalMinValueHit;
   boolean  bLocalMaxValueHitPrev;
   boolean  bLocalMinValueHitPrev;
   uint8    u8LocalDivision;
   uint8    u8LocalRatio;


   u8LocalDivision = (uint8)(u16DftIdx / 8);
   u8LocalRatio = (uint8)(u16DftIdx % 8);
   bLocalStPres = GD_bBitRead(GD_astrDftEep[u16DftIdx].u8GduGobdManagement,
                              BSTPRES);

   if (GDU_astrDftUnit[u16DftIdx].s16ctDet > 0)
   {
      bLocalctDetPrev = GD_bBitRead(GD_abctDetPrev[u8LocalDivision],
                                    u8LocalRatio);
      bLocalctDet = 1;
      if (  (bLocalctDetPrev == 0)
         && (bLocalStPres == 0))
      {
         GDU_vidExitEveFrfRec(u16DftIdx);
      }
   }
   else
   {
      bLocalctDet = 0;
   }

   bLocalMaxValueHit = GD_bBitRead(GD_abThdUp[u8LocalDivision], u8LocalRatio);
   bLocalMinValueHit = GD_bBitRead(GD_abThdDown[u8LocalDivision], u8LocalRatio);
   bLocalMaxValueHitPrev = GD_bBitRead(GD_abThdUpPrev[u8LocalDivision],
                                       u8LocalRatio);
   bLocalMinValueHitPrev = GD_bBitRead(GD_abThdDownPrev[u8LocalDivision],
                                       u8LocalRatio);

   if (  (bLocalMaxValueHitPrev == FALSE)
      && (bLocalMaxValueHit == TRUE))
   {
      GDU_vidExitEveCDThdUp(u16DftIdx);
   }

   if (  (  (bLocalMinValueHitPrev == FALSE)
         && (bLocalMinValueHit == TRUE))
      || (  (bLocalMaxValueHitPrev == FALSE)
         && (bLocalMaxValueHit == TRUE)))
   {
      GDU_vidExitEveCDThd(u16DftIdx);
   }
   GD_vidBitWrite(GD_abThdDownPrev[u8LocalDivision],
                  u8LocalRatio,
                  bLocalMinValueHit);
   GD_vidBitWrite(GD_abThdUpPrev[u8LocalDivision],
                  u8LocalRatio,
                  bLocalMaxValueHit);
   GD_vidBitWrite(GD_abctDetPrev[u8LocalDivision],
                  u8LocalRatio,
                  bLocalctDet);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidF04_IniCntDetGlbDCStrt_opt                          */
/* !Description :  This function initializes s16ctDet at start of a global    */
/*                 driving cycle. Optimization of the function                */
/*                 GDU_vidF04_IniCntDetGlbDCStrt.                             */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input GDU_tstrDft GDU_astrDftUnit[8];                                     */
/*  input boolean GD_abThdUp;                                                 */
/*  input boolean GD_abThdDown;                                               */
/*  output GDU_tstrDft GDU_astrDftUnit[8];                                    */
/*  output boolean GD_abThdUp;                                                */
/*  output boolean GD_abThdDown;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidF04_IniCntDetGlbDCStrt_opt(void)    /*Optimisation GD*/
{
   sint32   s32LocalIdx,s32LocalIdxDft;
   uint32   u32LocalMask;
   sint16   s16LocalctDet;

   s32LocalIdxDft =0;
   for (s32LocalIdx=0; s32LocalIdx < ((GD_DFT_NB+7)/8); s32LocalIdx++)
   {
      for (u32LocalMask=1; u32LocalMask <256; u32LocalMask = u32LocalMask<<1)
      {
         s16LocalctDet = GDU_astrDftUnit[s32LocalIdxDft].s16ctDet;
         if (  (s16LocalctDet == GDU_DFT_THD)
            || (s16LocalctDet == -GDU_DFT_THD))
         {
            GDU_astrDftUnit[s32LocalIdxDft].s16ctDet = 0;

            GD_abThdUp[s32LocalIdx] = (uint8)(GD_abThdUp[s32LocalIdx] & ~(u32LocalMask));
            GD_abThdDown[s32LocalIdx] = (uint8)(GD_abThdDown[s32LocalIdx] & ~(u32LocalMask));
         }
         if ( s32LocalIdxDft<(GD_DFT_NB-1))
         {
            s32LocalIdxDft++;
         } else
         {
            u32LocalMask =256;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidF06_ClearCntDetEvents                               */
/* !Description :  Replace function GDU_vidF06_CntDetEvents on a Global DC    */
/*                 Start. This function is dedicated to the creation of       */
/*                 various events linked to the fault detection counter.      */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input GDU_tstrDft GDU_astrDftUnit[8];                                     */
/*  input GD_tstrDftEep GD_astrDftEep[8];                                     */
/*  input boolean GD_abctDetPrev;                                             */
/*  input boolean GD_abThdUp;                                                 */
/*  input boolean GD_abThdDown;                                               */
/*  input boolean GD_abThdUpPrev;                                             */
/*  input boolean GD_abThdDownPrev;                                           */
/*  output boolean GD_abThdDownPrev;                                          */
/*  output boolean GD_abThdUpPrev;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidF06_ClearCntDetEvents(void)  /*Optimisation GD*/
{
   boolean  bLocalStPres;
   boolean  bLocalctDet;
   boolean  bLocalctDetPrev;
   boolean  bLocalMaxValueHit;
   boolean  bLocalMinValueHit;
   boolean  bLocalMaxValueHitPrev;
   boolean  bLocalMinValueHitPrev;

   sint32   s32LocalDivision, s32DftIdx;
   uint32   u32LocalMask;

   s32DftIdx = 0;
   for (s32LocalDivision = 0; s32LocalDivision < ((GD_DFT_NB+7)/8); s32LocalDivision++)
   {
      for (u32LocalMask = 1; u32LocalMask < 256; u32LocalMask = u32LocalMask<< 1)
      {
         if (GDU_astrDftUnit[s32DftIdx].s16ctDet > 0)
         {
            bLocalStPres = GD_bBitRead(GD_astrDftEep[s32DftIdx].u8GduGobdManagement,
                         BSTPRES);

            bLocalctDetPrev =
               (boolean)GD_bBitCheck_opt_mask(GD_abctDetPrev[s32LocalDivision],
                                              u32LocalMask);

            bLocalctDet = 1;
            if (  (bLocalctDetPrev == 0)
               && (bLocalStPres == 0))
            {
               GDU_vidExitEveFrfRec_opt(s32DftIdx);
            }
         }
         else
         {
            bLocalctDet = 0;
         }

         bLocalMaxValueHit =
            (boolean)GD_bBitCheck_opt_mask(GD_abThdUp[s32LocalDivision],
                                           u32LocalMask);
         bLocalMinValueHit =
            (boolean)GD_bBitCheck_opt_mask(GD_abThdDown[s32LocalDivision],
                                           u32LocalMask);
         bLocalMaxValueHitPrev =
            (boolean)GD_bBitCheck_opt_mask(GD_abThdUpPrev[s32LocalDivision],
                                           u32LocalMask);
         bLocalMinValueHitPrev =
            (boolean)GD_bBitCheck_opt_mask(GD_abThdDownPrev[s32LocalDivision],
                                           u32LocalMask);
         if (  (bLocalMaxValueHitPrev == 0)
         && (bLocalMaxValueHit != 0))
         {
            GDU_vidExitEveCDThdUp_opt(s32DftIdx);
            GDU_vidExitEveCDThd_opt(s32LocalDivision,u32LocalMask,s32DftIdx); 
         } 
         else  {
            if (  (bLocalMinValueHitPrev == 0)
               && (bLocalMinValueHit != 0))
            {
               GDU_vidExitEveCDThd_opt(s32LocalDivision,u32LocalMask,s32DftIdx);
            }
         }

         GD_vidBitWrite_opt_mask(GD_abctDetPrev[s32LocalDivision],
                        u32LocalMask,
                        bLocalctDet);
         if ( s32DftIdx<(GD_DFT_NB-1))
         {
            s32DftIdx++;
         } else
         {
            u32LocalMask = 256;
         }
      }
      GD_abThdDownPrev[s32LocalDivision]=GD_abThdDown[s32LocalDivision];
      GD_abThdUpPrev[s32LocalDivision]=GD_abThdUp[s32LocalDivision];
   }
}

/*------------------------------- end of file --------------------------------*/