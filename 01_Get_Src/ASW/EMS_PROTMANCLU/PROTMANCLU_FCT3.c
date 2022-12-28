/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PROTMANCLU                                              */
/* !Description     : PROTMANCLU Component                                    */
/*                                                                            */
/* !Module          : PROTMANCLU                                              */
/* !Description     : Clutch protection for manual gearbox                    */
/*                                                                            */
/* !File            : PROTMANCLU_FCT3.C                                       */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / PROTMANCLU_vidEstimClutchTemp                                        */
/*   2 / PROTMANCLU_vidEstimClutchPlatTmp                                     */
/*   3 / PROTMANCLU_vidEstimTempOfClutch                                      */
/*   4 / PROTMANCLU_vidEstimClutchBellTmp                                     */
/*   5 / PROTMANCLU_vidEstimHousClutchTmp                                     */
/*   6 / PROTMANCLU_vidEstimGearboxTemp                                       */
/*   7 / PROTMANCLU_vidCalculPreviousTemp                                     */
/*   8 / PROTMANCLU_vidCalculPrevTempInit                                     */
/*   9 / PROTMANCLU_vidActivationProtect                                      */
/*   10 / PROTMANCLU_vidCalcGradclutchTemp                                    */
/*                                                                            */
/* !Reference   : V02 NT 11 04687 / 01                                        */
/* !OtherRefs   : 01460_10_03770/1.1                                          */
/* !OtherRefs   : VEMS V02 ECU#056597                                         */
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
#include "PROTMANCLU.h"
#include "PROTMANCLU_l.h"
#include "PROTMANCLU_IM.h"
#include "STD_LIMITS.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidEstimClutchTemp                              */
/* !Description :  This function  estimates the temperature of clutch friction*/
/*                 pad.                                                       */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_019.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PROTMANCLU_vidEstimClutchPlatTmp();                      */
/*  extf argret void PROTMANCLU_vidEstimTempOfClutch();                       */
/*  extf argret void PROTMANCLU_vidEstimClutchBellTmp();                      */
/*  extf argret void PROTMANCLU_vidEstimHousClutchTmp();                      */
/*  extf argret void PROTMANCLU_vidEstimGearboxTemp();                        */
/*  extf argret void PROTMANCLU_vidCalculPreviousTemp();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidEstimClutchTemp(void)
{
   PROTMANCLU_vidEstimClutchPlatTmp();
   PROTMANCLU_vidEstimTempOfClutch();
   PROTMANCLU_vidEstimClutchBellTmp();
   PROTMANCLU_vidEstimHousClutchTmp();
   PROTMANCLU_vidEstimGearboxTemp();
   PROTMANCLU_vidCalculPreviousTemp();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidEstimClutchPlatTmp                           */
/* !Description :  This function estimates the temperature of the clutch      */
/*                 plate.                                                     */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 PtLim_tItAirCluEstim;                                        */
/*  input uint16 PtLim_tWhlCluEstim;                                          */
/*  input uint16 PtLim_facTWhlCluItAir;                                       */
/*  input sint16 PtLim_pwrDeltaWhlCluSel;                                     */
/*  input uint16 PtLim_arCluWhlClu_C;                                         */
/*  input uint16 PtLim_tCluEstim;                                             */
/*  input uint16 PtLim_facTCluWhlClu_C;                                       */
/*  input uint8 PtLim_facMassWhlClu_C;                                        */
/*  input uint16 PtLim_facTWhlClu_C;                                          */
/*  input uint8 PtLim_facTThermoWhlClu_C;                                     */
/*  input uint16 PtLim_tWhlCluEstimGrd_MP;                                    */
/*  output uint16 PtLim_tWhlCluEstimGrd_MP;                                   */
/*  output uint16 PROTMANCLU_u16WhlCluEstimPrev2;                             */
/*  output uint16 PtLim_tWhlCluEstim;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidEstimClutchPlatTmp(void)
{
   /*F03_03_01_Estimation_of_clutch_plate_temperature */
   sint8  s8LocalSigElem3;
   sint8  s8LocalSigNum;
   uint16 u16LocalCalcDen22;
   uint32 u32LocalCalcDen1;
   uint32 u32LocalElem1;
   uint32 u32LocalElem3;
   uint32 u32LocalModElem3;
   uint32 u32LocalModElem3_3;
   uint32 u32LocalComp;
   uint32 u32LocalModDiv;
   uint32 u32LocalModDen2;
   uint32 u32LocalCalcDen2;
   uint32 u32LocalNum;
   uint32 u32LocalOut;
   uint32 u32LocalCalcDiv;
   uint32 u32LocalMod1;
   uint32 u32LocalMod2;
   uint32 u32LocalMod3;
   sint32 s32LocalElem1;
   sint32 s32LocalElem2;
   sint32 s32LocalModElem1;
   sint32 s32LocalNum;
   sint32 s32LocalOut;
   sint32 s32LocalModElem1_3;
   sint32 s32LocalElem3;


   /*PtLim_tWhlCluEstimGrd_MP = ((Elem1 + Elem2 + Elem3) * Denom2) / Denom1   */

   /*Elem1 = ( ( PtLim_tItAirCluEstim - PtLim_tWhlCluEstim)
             * PtLim_facTWhlCluItAir) / 256 */
   s32LocalElem1 = (sint32)( PtLim_tItAirCluEstim - PtLim_tWhlCluEstim);
   if (s32LocalElem1 >= 0)
   {
      u32LocalElem1    = (uint32)(s32LocalElem1 * PtLim_facTWhlCluItAir);
      s32LocalElem1    = (sint32)(u32LocalElem1 / 256);
      s32LocalModElem1 = (sint32)(u32LocalElem1 % 256);
   }
   else
   {
      u32LocalElem1    =  (uint32)((-s32LocalElem1) * PtLim_facTWhlCluItAir);
      s32LocalElem1    = -(sint32)(u32LocalElem1 / 256);
      s32LocalModElem1 = -(sint32)(u32LocalElem1 % 256);
   }
   /*Elem2 = PtLim_pwrDeltaWhlCluSel * 256 */
   s32LocalElem2 = (sint32)(PtLim_pwrDeltaWhlCluSel * 256);
   /*Elem3 = ( (PtLim_tCluEstim - PtLim_tWhlCluEstim)
             * PtLim_arCluWhlClu_C * PtLim_facTCluWhlClu_C) / 262144 */
   if (PtLim_arCluWhlClu_C == 0)
   {
      u32LocalElem3      = 0;
      s8LocalSigElem3    = 1;
      u32LocalModElem3_3 = 0;
   }
   else
   {
      s32LocalElem3 = (PtLim_tCluEstim - PtLim_tWhlCluEstim);
      if (s32LocalElem3 < 0)
      {
         s8LocalSigElem3 = -1;
         u32LocalElem3   = (uint32)(-s32LocalElem3);
      }
      else
      {
         s8LocalSigElem3 = 1;
         u32LocalElem3   = (uint32)(s32LocalElem3);
      }
      u32LocalElem3    = u32LocalElem3 * PtLim_facTCluWhlClu_C;
      u32LocalModElem3 = u32LocalElem3 % 262144;
      u32LocalElem3    = (u32LocalElem3 / 262144) * PtLim_arCluWhlClu_C;
      u32LocalComp     = UINT32_MAX / (uint32)PtLim_arCluWhlClu_C;
      if (u32LocalModElem3 < u32LocalComp)
      {
         u32LocalModElem3   = u32LocalModElem3 * PtLim_arCluWhlClu_C;
         u32LocalModElem3_3 = u32LocalModElem3 % 262144;
         u32LocalModElem3   = u32LocalModElem3 / 262144;
      }
      else
      {
         u32LocalModElem3   = ((u32LocalModElem3 + 2) / 4)* PtLim_arCluWhlClu_C;
         u32LocalModElem3_3 = (u32LocalModElem3 % 65536) * 4;
         u32LocalModElem3   = u32LocalModElem3 / 65536;
      }
      u32LocalElem3 = u32LocalElem3 + u32LocalModElem3;
   }
   s32LocalNum = (s32LocalElem1 + s32LocalElem2)
               + (s8LocalSigElem3 * (sint32)u32LocalElem3);

   if (s32LocalNum < 0)
   {
      s8LocalSigNum = -1;
      u32LocalNum   = (uint32)(-s32LocalNum);
   }
   else
   {
      s8LocalSigNum = 1;
      u32LocalNum   = (uint32)(s32LocalNum);
   }
   /*----------------------------------------------------------*/
   /* Variable         |      Min Value     |     Max Value    */
   /*----------------------------------------------------------*/
   /*s32LocalElem1     |     -16776704      |     16776704     */
   /*s32LocalModElem1  |         0          |          255     */
   /*s32LocalElem2     |     -8388608       |      8388352     */
   /*u32LocalElem3     |         0          |   1073692672     */
   /*u32LocalModElem3_3|         0          |       262143     */
   /*s32LocalNum       |    -1098857728     |   1098857728     */
   /*u32LocalNum       |         0          |   1098857728     */
   /*----------------------------------------------------------*/

   /*Denominator = ( ( (512 * PtLim_facTWhlClu_C)
                     + (PtLim_facTThermoWhlClu_C * PtLim_tWhlCluEstim))
                   * PtLim_facMassWhlClu_C)
                 / 512 */
   if (  ( PtLim_facMassWhlClu_C == 0)
      || (  (PtLim_facTWhlClu_C == 0)
         && ((PtLim_facTThermoWhlClu_C == 0) || (PtLim_tWhlCluEstim == 0))))
   {
      /*If (Denominator = 0) --> (Output = Numerator)*/
      if (u32LocalNum < 131070)
      {
         /*Recup loss in Elem1 & Elem3*/
         s32LocalModElem1   = (s32LocalModElem1 * 2);
         u32LocalModElem3_3 = (u32LocalModElem3_3 + 256) / 512;
         s32LocalOut = ((s32LocalNum * 512) + s32LocalModElem1)
                     + (s8LocalSigElem3 * (sint32)u32LocalModElem3_3);
      }
      else
      {
         s32LocalOut = s8LocalSigNum * 65535;
      }
   }
   else
   {
      u32LocalCalcDen1  =
         (uint32)( (PtLim_facTThermoWhlClu_C * PtLim_tWhlCluEstim)
                 + (512 * PtLim_facTWhlClu_C));
      u16LocalCalcDen22 = (uint16)(512 / PtLim_facMassWhlClu_C);
      u32LocalCalcDen2  = 262144 / (uint32)PtLim_facMassWhlClu_C;
      u32LocalModDen2   = 262144 % (uint32)PtLim_facMassWhlClu_C;
      /*----------------------------------------------------------*/
      /* Variable         |      Min Value     |     Max Value    */
      /*----------------------------------------------------------*/
      /*u32LocalCalcDen1  |         1          |     50265345     */
      /*u32LocalCalcDen2  |       1028         |       262144     */
      /*u16LocalCalcDen22 |         2          |          512     */
      /*u32LocalModDen2   |         0          |          255     */
      /*----------------------------------------------------------*/

      /*If (Denom1 / Denom2 < 1) --> (Output = Numerator)*/
      if (u32LocalCalcDen1 <= (uint32)u16LocalCalcDen22)
      {
         if (u32LocalNum < 131070)
         {
            /*Recup loss in Elem1 & Elem3*/
            s32LocalModElem1   = (s32LocalModElem1 * 2);
            u32LocalModElem3_3 = (u32LocalModElem3_3 + 256) / 512;
            s32LocalOut = ((s32LocalNum * 512) + s32LocalModElem1)
                        + (s8LocalSigElem3 * (sint32)u32LocalModElem3_3);
         }
         else
         {
            s32LocalOut = s8LocalSigNum * 65535;
         }
      }
      else
      {
         /*If (Denominator != 0) --> (Output = (Num * Denom2) / Denom1)*/
         u32LocalModDiv  = u32LocalNum % u32LocalCalcDen1;
         u32LocalCalcDiv = u32LocalNum / u32LocalCalcDen1;
         /*!QAC Msg(2:0584): u32LocalCalcDen1 > u16LocalCalcDen22 >=2*/
         u32LocalComp    = UINT32_MAX / u32LocalCalcDen2;
         if (u32LocalCalcDiv < u32LocalComp)
         {
            u32LocalNum = u32LocalCalcDiv * u32LocalCalcDen2;
            if (u32LocalNum < 131070)
            {
               /*Recup loss in Elem1 & Elem3*/
               s32LocalModElem1_3 = ( s8LocalSigElem3
                                    * (sint32)u32LocalModElem3_3)
                                  + (s32LocalModElem1 * 1024);
               /*----------------------------------------------------------*/
               /* Variable         |      Min Value     |     Max Value    */
               /*----------------------------------------------------------*/
               /*s32LocalModElem1_3|       -523263      |       523263     */
               /*u32LocalModDiv    |          0         |     50265345     */
               /*u32LocalCalcDiv   |          0         |          128     */
               /*----------------------------------------------------------*/
               s32LocalModElem1   = s32LocalModElem1_3 % 64;
               s32LocalModElem1_3 =
                  (s32LocalModElem1_3 / 64) * (sint32)u32LocalCalcDen2;

               s32LocalModElem1   = ( s32LocalModElem1
                                    * (sint32)u32LocalCalcDen2)
                                  / 64;
               s32LocalModElem1_3 = (s32LocalModElem1_3 + s32LocalModElem1)
                                  / 4096;
               s32LocalModElem1_3 = s32LocalModElem1_3
                                  / (sint32)u32LocalCalcDen1;
               /*Recup loss in Den2*/
               u32LocalModDen2 = (u32LocalModDen2 * u32LocalCalcDiv)
                               / PtLim_facMassWhlClu_C;
               /*Recup loss in Div(Num , Den1)*/
               if (u32LocalModDiv < u32LocalComp)
               {
                  u32LocalModDiv =
                     (u32LocalModDiv * u32LocalCalcDen2) / u32LocalCalcDen1;
               }
               else
               {
                  u32LocalMod1   = u32LocalModDiv % 3072;
                  u32LocalModDiv = (u32LocalModDiv / 3072) * u32LocalCalcDen2;
                  u32LocalMod1   = u32LocalMod1 * u32LocalCalcDen2;
                  u32LocalMod3   = ((u32LocalMod1 % 3072) * 3072)
                                 / u32LocalCalcDen1;
                  u32LocalMod1   = u32LocalMod1 / 3072;
                  u32LocalModDiv = u32LocalModDiv + u32LocalMod1;
                  u32LocalMod1   = u32LocalModDiv % u32LocalCalcDen1;
                  u32LocalModDiv = u32LocalModDiv / u32LocalCalcDen1;
                  u32LocalMod1   = u32LocalMod1 * 64;
                  u32LocalMod2   = u32LocalMod1 % u32LocalCalcDen1;
                  u32LocalMod1   = (u32LocalMod1 / u32LocalCalcDen1) * 48;
                  u32LocalMod2   = (u32LocalMod2 * 48) / u32LocalCalcDen1;
                  u32LocalMod1   = u32LocalMod1 + u32LocalMod2 + u32LocalMod3;
                  u32LocalModDiv = (u32LocalModDiv * 3072) + u32LocalMod1;
               }
               u32LocalNum = u32LocalNum + u32LocalModDiv + u32LocalModDen2;
               s32LocalOut = ((sint32)u32LocalNum * s8LocalSigNum)
                           + s32LocalModElem1_3;
            }
            else
            {
               s32LocalOut = s8LocalSigNum * 65535;
            }
         }
         else
         {
            s32LocalOut = s8LocalSigNum * 65535;
         }
      }
   }
   PtLim_tWhlCluEstimGrd_MP = (uint16)MATHSRV_udtCLAMP(s32LocalOut, 0, 65535);
   PROTMANCLU_u16WhlCluEstimPrev2 =
      (uint16)MATHSRV_udtCLAMP(PtLim_tWhlCluEstim, 3568, 20368);
   /* Production of PtLim_tWhlCluEstim */
   u32LocalOut =
      (uint32)( ( (PtLim_tWhlCluEstim * 16000)
                + (PtLim_tWhlCluEstimGrd_MP * PtLim_tiSdlManCluTEstim_SC)
                + 8000) / 16000);
   PtLim_tWhlCluEstim = (uint16)MATHSRV_udtCLAMP(u32LocalOut, 3568, 20368);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidEstimTempOfClutch                            */
/* !Description :  This function estimates the temperature of the clutch      */
/*                 friction pad.                                              */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 PtLim_tItAirCluEstim;                                        */
/*  input uint16 PtLim_tCluEstim;                                             */
/*  input uint16 PtLim_facTCluItAir;                                          */
/*  input sint16 PtLim_pwrDeltaCluSel;                                        */
/*  input uint16 PtLim_arCluWhlClu_C;                                         */
/*  input uint16 PtLim_tWhlCluEstim;                                          */
/*  input uint16 PtLim_facTCluWhlClu_C;                                       */
/*  input uint16 PtLim_arCluEng_C;                                            */
/*  input uint16 PtLim_tOilEstim;                                             */
/*  input uint16 PtLim_facTCluEng_C;                                          */
/*  input uint8 PtLim_facMassClu_C;                                           */
/*  input uint16 PtLim_facTClu_C;                                             */
/*  input uint8 PtLim_facTThermoClu_C;                                        */
/*  input uint16 PtLim_tCluEstimGrd_MP;                                       */
/*  output uint16 PtLim_tCluEstimGrd_MP;                                      */
/*  output uint16 PROTMANCLU_u16CluEstimPrev2;                                */
/*  output uint16 PtLim_tCluEstim;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidEstimTempOfClutch(void)
{
 /*F03_03_02_Estimation_of_clutch_facing_temperature */
   sint8  s8LocalSigElem3;
   sint8  s8LocalSigElem4;
   sint8  s8LocalSigNum;
   uint16 u16LocalCalcDen22;
   uint32 u32LocalCalcDen1;
   uint32 u32LocalElem1;
   uint32 u32LocalElem3;
   uint32 u32LocalModElem3;
   uint32 u32LocalModElem3_3;
   uint32 u32LocalElem4;
   uint32 u32LocalModElem4;
   uint32 u32LocalModElem4_4;
   uint32 u32LocalComp;
   uint32 u32LocalModDiv;
   uint32 u32LocalModDen2;
   uint32 u32LocalCalcDen2;
   uint32 u32LocalNum;
   uint32 u32LocalMod1;
   uint32 u32LocalMod2;
   uint32 u32LocalMod3;
   uint32 u32LocalMod4;
   uint32 u32LocalOut;
   uint32 u32LocalCalcDiv;
   uint32 u32LocalMod;
   sint32 s32LocalElem1;
   sint32 s32LocalElem2;
   sint32 s32LocalModElem1;
   sint32 s32LocalOut;
   sint32 s32LocalModElem1_3;
   sint32 s32LocalElem3;
   sint32 s32LocalElem4;
   sint32 s32LocalNum;


   /*PtLim_tCluEstimGrd_MP=((Elem1 + Elem2 + Elem3 + Elem4) * Denom2) / Denom1*/
   /*Elem1 = ( (PtLim_tItAirCluEstim - PtLim_tCluEstim)
             * PtLim_facTCluItAir) / 1024 */
   s32LocalElem1 = (sint32)( PtLim_tItAirCluEstim - PtLim_tCluEstim);
   if (s32LocalElem1 >= 0)
   {
      u32LocalElem1    = (uint32)(s32LocalElem1 * PtLim_facTCluItAir);
      s32LocalElem1    = (sint32)(u32LocalElem1 / 1024);
      s32LocalModElem1 = (sint32)(u32LocalElem1 % 1024);
   }
   else
   {
      u32LocalElem1    =  (uint32)((-s32LocalElem1) * PtLim_facTCluItAir);
      s32LocalElem1    = -(sint32)(u32LocalElem1 / 1024);
      s32LocalModElem1 = -(sint32)(u32LocalElem1 % 1024);
   }
   /*Elem2 = PtLim_pwrDeltaCluSel * 64 */
   s32LocalElem2 = (sint32)(PtLim_pwrDeltaCluSel * 64);
   /*Elem3 = ( (PtLim_tWhlCluEstim - PtLim_tCluEstim)
             * PtLim_arCluWhlClu_C * PtLim_facTCluWhlClu_C) / 1048576 */
   if (PtLim_arCluWhlClu_C == 0)
   {
      u32LocalElem3      = 0;
      s8LocalSigElem3    = 1;
      u32LocalModElem3_3 = 0;
   }
   else
   {
      s32LocalElem3 = (PtLim_tWhlCluEstim - PtLim_tCluEstim);
      if (s32LocalElem3 < 0)
      {
         s8LocalSigElem3 = -1;
         u32LocalElem3   = (uint32)(-s32LocalElem3);
      }
      else
      {
         s8LocalSigElem3 = 1;
         u32LocalElem3   = (uint32)(s32LocalElem3);
      }
      u32LocalElem3    = u32LocalElem3 * PtLim_facTCluWhlClu_C;
      u32LocalModElem3 = (u32LocalElem3 % 1048576);
      u32LocalElem3    = (u32LocalElem3 / 1048576) * PtLim_arCluWhlClu_C;

      u32LocalComp = UINT32_MAX / (uint32)PtLim_arCluWhlClu_C;
      if (u32LocalModElem3 < u32LocalComp)
      {
         u32LocalModElem3   = u32LocalModElem3 * PtLim_arCluWhlClu_C;
         u32LocalModElem3_3 = u32LocalModElem3 % 1048576;
         u32LocalModElem3   = u32LocalModElem3 / 1048576;
      }
      else
      {
         u32LocalModElem3   = ((u32LocalModElem3 + 8)/16) * PtLim_arCluWhlClu_C;
         u32LocalModElem3_3 = (u32LocalModElem3 % 65536) * 16;
         u32LocalModElem3   = u32LocalModElem3 / 65536;
      }
      u32LocalElem3 = u32LocalElem3 + u32LocalModElem3;
   }
   /*Elem4 = ( ((4 * PtLim_tOilEstim) - PtLim_tCluEstim)
             * PtLim_facTCluEng_C * PtLim_arCluEng_C) / 1048576 */
   if (PtLim_arCluEng_C == 0)
   {
      u32LocalElem4      = 0;
      s8LocalSigElem4    = 1;
      u32LocalModElem4_4 = 0;
   }
   else
   {
      s32LocalElem4 = ((4 * PtLim_tOilEstim) - PtLim_tCluEstim);
      if (s32LocalElem4 < 0)
      {
         s8LocalSigElem4 = -1;
         u32LocalElem4   = (uint32)(-s32LocalElem4);
      }
      else
      {
         s8LocalSigElem4 = 1;
         u32LocalElem4   = (uint32)(s32LocalElem4);
      }
      u32LocalMod      = ((u32LocalElem4 % 4) * PtLim_facTCluEng_C) / 4;
      u32LocalElem4    = (u32LocalElem4 / 4) * PtLim_facTCluEng_C;
      u32LocalElem4    = u32LocalElem4 + u32LocalMod;
      u32LocalModElem4 = u32LocalElem4 % 262144;
      u32LocalElem4    = (u32LocalElem4 / 262144) * PtLim_arCluEng_C;
      u32LocalComp     = UINT32_MAX / (uint32)PtLim_arCluEng_C;
      if (u32LocalModElem4 < u32LocalComp)
      {
         u32LocalModElem4   = u32LocalModElem4 * PtLim_arCluEng_C;
         u32LocalModElem4_4 = u32LocalModElem4 % 262144;
         u32LocalModElem4   = u32LocalModElem4 / 262144;
      }
      else
      {
         u32LocalModElem4   = ((u32LocalModElem4 + 2) / 4) * PtLim_arCluEng_C;
         u32LocalModElem4_4 = (u32LocalModElem4 % 65536) * 4;
         u32LocalModElem4   = u32LocalModElem4 / 65536;
      }
      u32LocalElem4 = u32LocalElem4 + u32LocalModElem4;
   }
   s32LocalNum = (s32LocalElem1 + s32LocalElem2)
               + (s8LocalSigElem3 * (sint32)u32LocalElem3)
               + (s8LocalSigElem4 * (sint32)u32LocalElem4);
   if (s32LocalNum < 0)
   {
      s8LocalSigNum   = -1;
      u32LocalNum = (uint32)(-s32LocalNum);
   }
   else
   {
      s8LocalSigNum   = 1;
      u32LocalNum = (uint32)(s32LocalNum);
   }
   /*----------------------------------------------------------*/
   /* Variable         |      Min Value     |     Max Value    */
   /*----------------------------------------------------------*/
   /*s32LocalElem1     |     -4194176       |     4194176      */
   /*s32LocalModElem1  |         0          |        1023      */
   /*s32LocalElem2     |     -2097152       |     2097088      */
   /*u32LocalElem3     |         0          |   268423168      */
   /*u32LocalModElem3_3|         0          |     1048575      */
   /*u32LocalElem4     |         0          |  1073692672      */
   /*u32LocalModElem4_4|         0          |      262144      */
   /*s32LocalNum       |    -1348407104     |  1348407104      */
   /*u32LocalNum       |         0          |  1348407104      */
   /*----------------------------------------------------------*/

   /*Denominator = ( ( (512 * PtLim_facTClu_C)
                     + (PtLim_facTThermoClu_C * PtLim_tCluEstim))
                   * PtLim_facMassClu_C) / 512 */
   if (  ( PtLim_facMassClu_C == 0)
      || (  (PtLim_facTClu_C == 0)
         && ((PtLim_facTThermoClu_C == 0) || (PtLim_tCluEstim == 0))))
   {
      /*If (Denominator = 0) --> (Output = Numerator)*/
      if (u32LocalNum < 131070)
      {
         /*Recup loss in Elem1 & Elem3 & Elem4*/
         s32LocalModElem1   = (s32LocalModElem1 * 2);
         u32LocalModElem3_3 = (u32LocalModElem3_3 + 256) / 512;
         u32LocalModElem4_4 = (u32LocalModElem4_4 + 64) / 128;
         s32LocalOut = ((s32LocalNum * 2048) + s32LocalModElem1)
                     + (s8LocalSigElem3 * (sint32)u32LocalModElem3_3)
                     + (s8LocalSigElem4 * (sint32)u32LocalModElem4_4);
      }
      else
      {
         s32LocalOut = s8LocalSigNum * 65535;
      }
   }
   else
   {
      u32LocalCalcDen1  =
         (uint32)( (PtLim_facTThermoClu_C * PtLim_tCluEstim)
                 + (512 * PtLim_facTClu_C));
      u16LocalCalcDen22 = (uint16)(512 / PtLim_facMassClu_C);
      u32LocalCalcDen2  = 1048576 / (uint32)PtLim_facMassClu_C;
      u32LocalModDen2   = 1048576 % (uint32)PtLim_facMassClu_C;
      /*----------------------------------------------------------*/
      /* Variable         |      Min Value     |     Max Value    */
      /*----------------------------------------------------------*/
      /*u32LocalCalcDen1  |         1          |     50265345     */
      /*u32LocalCalcDen2  |       4112         |      1048576     */
      /*u16LocalCalcDen22 |         2          |          512     */
      /*u32LocalModDen2   |         0          |          255     */
      /*----------------------------------------------------------*/

      /*If (Denom1 / Denom2 < 1) --> (Output = Numerator)*/
      if (u32LocalCalcDen1 <= (uint32)u16LocalCalcDen22)
      {
         if (u32LocalNum < 131070)
         {
            /*Recup loss in Elem1 & Elem3 & Elem4*/
            s32LocalModElem1   = (s32LocalModElem1 * 2);
            u32LocalModElem3_3 = (u32LocalModElem3_3 + 256) / 512;
            u32LocalModElem4_4 = (u32LocalModElem4_4 + 64) / 128;
            s32LocalOut = ((s32LocalNum * 2048) + s32LocalModElem1)
                        + (s8LocalSigElem3 * (sint32)u32LocalModElem3_3)
                        + (s8LocalSigElem4 * (sint32)u32LocalModElem4_4);
         }
         else
         {
            s32LocalOut = s8LocalSigNum * 65535;
         }
      }
      else
      {
         /*If (Denominator != 0) --> (Output = (Num * Denom2) / Denom1)*/
         u32LocalModDiv  = u32LocalNum % u32LocalCalcDen1;
         u32LocalCalcDiv = u32LocalNum / u32LocalCalcDen1;
         /*!QAC Msg(2:0584): u32LocalCalcDen1 > u16LocalCalcDen22 >=2*/
         u32LocalComp    = UINT32_MAX / u32LocalCalcDen2;
         if (u32LocalCalcDiv < u32LocalComp)
         {
            u32LocalNum = u32LocalCalcDiv * u32LocalCalcDen2;
            if (u32LocalNum < 131070)
            {
               /*Recup loss in Elem1 & Elem3 & Elem4 */
               s32LocalModElem1_3 = ( s8LocalSigElem3
                                    * (sint32)u32LocalModElem3_3)
                                  + ( s8LocalSigElem4
                                    * (sint32)(4 * u32LocalModElem4_4))
                                  + (s32LocalModElem1 * 1024);
               /*----------------------------------------------------------*/
               /* Variable         |      Min Value     |     Max Value    */
               /*----------------------------------------------------------*/
               /*s32LocalModElem1_3|       -2097152     |       2097152    */
               /*u32LocalModDiv    |          0         |      50265344    */
               /*u32LocalCalcDiv   |          0         |            32    */
               /*----------------------------------------------------------*/
               s32LocalModElem1   = s32LocalModElem1_3 % 1024;
               s32LocalModElem1_3 = (s32LocalModElem1_3 / 1024)
                                  * (sint32)u32LocalCalcDen2;
               s32LocalModElem1   = ( s32LocalModElem1
                                    * (sint32)u32LocalCalcDen2)
                                  / 1024;
               s32LocalModElem1_3 = (s32LocalModElem1_3 + s32LocalModElem1)
                                  / 1024;
               s32LocalModElem1_3 = s32LocalModElem1_3
                                  / (sint32)u32LocalCalcDen1;
               /*Recup loss in Den2*/
               u32LocalModDen2 = (u32LocalModDen2 * u32LocalCalcDiv)
                               / PtLim_facMassClu_C;
               /*Recup loss in Div(Num , Den1)*/
               if (u32LocalModDiv < u32LocalComp)
               {
                  u32LocalModDiv =
                     (u32LocalModDiv * u32LocalCalcDen2) / u32LocalCalcDen1;
               }
               else
               {
                  u32LocalMod1   = u32LocalModDiv % 12288;
                  u32LocalModDiv = (u32LocalModDiv / 12288) * u32LocalCalcDen2;
                  u32LocalMod2   = ((u32LocalMod1 % 3) * u32LocalCalcDen2) / 3;
                  u32LocalMod1   = ((u32LocalMod1 / 3) * u32LocalCalcDen2)
                                 + u32LocalMod2;
                  u32LocalMod4   = ((u32LocalMod1 % 4096) * 3)/u32LocalCalcDen1;
                  u32LocalMod1   = u32LocalMod1 / 4096;
                  u32LocalModDiv = u32LocalModDiv + u32LocalMod1;
                  u32LocalMod1   = u32LocalModDiv % u32LocalCalcDen1;
                  u32LocalModDiv = u32LocalModDiv / u32LocalCalcDen1;
                  u32LocalMod1   = u32LocalMod1 * 64;
                  u32LocalMod2   = u32LocalMod1 % u32LocalCalcDen1;
                  u32LocalMod1   = (u32LocalMod1 / u32LocalCalcDen1) * 192;
                  u32LocalMod2   = u32LocalMod2 * 64;
                  u32LocalMod3   = u32LocalMod2 % u32LocalCalcDen1;
                  u32LocalMod2   = ( u32LocalMod2 / u32LocalCalcDen1) * 3;
                  u32LocalMod3   = (u32LocalMod3 * 3) / u32LocalCalcDen1;
                  u32LocalMod1   = (u32LocalMod1 + u32LocalMod2)
                                 + (u32LocalMod3 + u32LocalMod4);
                  u32LocalModDiv = (u32LocalModDiv * 12288) + u32LocalMod1;
               }
               u32LocalNum = u32LocalNum + u32LocalModDiv + u32LocalModDen2;
               s32LocalOut = ((sint32)u32LocalNum * s8LocalSigNum)
                           + s32LocalModElem1_3;
            }
            else
            {
               s32LocalOut = s8LocalSigNum * 65535;
            }
         }
         else
         {
            s32LocalOut = s8LocalSigNum * 65535;
         }
      }
   }
   PtLim_tCluEstimGrd_MP = (uint16)MATHSRV_udtCLAMP(s32LocalOut, 0, 65535);
   PROTMANCLU_u16CluEstimPrev2 =
      (uint16)MATHSRV_udtCLAMP(PtLim_tCluEstim, 3568, 20368);
   /* Production of PtLim_tCluEstim */
   u32LocalOut =
      (uint32)( ( (PtLim_tCluEstim * 16000)
                + (PtLim_tCluEstimGrd_MP * PtLim_tiSdlManCluTEstim_SC)
                + 8000) / 16000);
   PtLim_tCluEstim = (uint16)MATHSRV_udtCLAMP(u32LocalOut, 3568, 20368);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidEstimClutchBellTmp                           */
/* !Description :  This function estimates the temperature of the clutch bell.*/
/* !Number      :  FCT3.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input uint16 PtLim_tWhlCluEstim;                                          */
/*  input uint16 PtLim_tItAirCluEstim;                                        */
/*  input uint16 PtLim_facTWhlCluItAir;                                       */
/*  input uint16 PtLim_tCluEstim;                                             */
/*  input uint16 PtLim_facTCluItAir;                                          */
/*  input uint16 PtLim_tCaseCluEstim;                                         */
/*  input uint16 PtLim_facTCaseItAir;                                         */
/*  input uint16 PtLim_tOilEstim;                                             */
/*  input uint16 PtLim_facTEngItAir;                                          */
/*  input uint16 PtLim_tGearCluEstim;                                         */
/*  input uint16 PtLim_facTGearItAir;                                         */
/*  input uint16 PtLim_tAirExtMes;                                            */
/*  input uint8 PtLim_facMassItAir_C;                                         */
/*  input uint16 PtLim_facTItAir_C;                                           */
/*  input uint8 PtLim_facTThermoItAir_C;                                      */
/*  input uint16 PtLim_pPAirRef_C;                                            */
/*  input uint16 PtLim_tItAirCluEstimGrd_MP;                                  */
/*  output uint16 PtLim_tItAirCluEstimGrd_MP;                                 */
/*  output uint16 PROTMANCLU_u16AirCluEstimPrev2;                             */
/*  output uint16 PtLim_tItAirCluEstim;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidEstimClutchBellTmp(void)
{
   /*F03_03_03_Estimation_of_the_clutch_bell_temperature */
   uint16  u16LocalPAirRef_C;
   uint16  u16LocalExt_pAirExtMes;
   uint16  u16LocalItAirCluEstim;
   uint32  u32LocalOut;
   float32 f32LocalCalcNum;
   float32 f32LocalCalcDen;
   float32 f32LocalCalcOut;


   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   f32LocalCalcNum = ( (float32)( PtLim_tWhlCluEstim - PtLim_tItAirCluEstim)
                     * (float32)PtLim_facTWhlCluItAir);

   f32LocalCalcNum = ( f32LocalCalcNum
                     + ( (float32)( PtLim_tCluEstim - PtLim_tItAirCluEstim)
                       * (float32)PtLim_facTCluItAir));

   f32LocalCalcNum = ( f32LocalCalcNum
                     + ( (float32)( PtLim_tCaseCluEstim - PtLim_tItAirCluEstim)
                       * (float32)PtLim_facTCaseItAir));

   f32LocalCalcNum = ( f32LocalCalcNum
                     + ( ( (float32)(4 * PtLim_tOilEstim)
                         - (float32)PtLim_tItAirCluEstim)
                       * (float32)PtLim_facTEngItAir));

   f32LocalCalcNum = ( f32LocalCalcNum
                     + ( (float32)( PtLim_tGearCluEstim - PtLim_tItAirCluEstim)
                       * (float32)PtLim_facTGearItAir));

   f32LocalCalcNum = (f32LocalCalcNum / (float32)4);

   if (f32LocalCalcNum < (float32)1)
   {
      PtLim_tItAirCluEstimGrd_MP = 0;
   }
   else
   {
      if (  (PtLim_tAirExtMes == 0)
         || (PtLim_facMassItAir_C == 0)
         || (u16LocalExt_pAirExtMes == 0)
         || (  (PtLim_facTItAir_C == 0)
            && (  (PtLim_facTThermoItAir_C == 0)
               || (PtLim_tItAirCluEstim == 0))))
      {
         f32LocalCalcOut = f32LocalCalcNum;
      }
      else
      {
         u16LocalPAirRef_C     = (uint16)MATHSRV_udtMAX(PtLim_pPAirRef_C, 1);
         u16LocalItAirCluEstim = (uint16)MATHSRV_udtMAX(PtLim_tItAirCluEstim,1);
         /*----------------------------------------------------------*/
         /* Variable      |      Min Value   |     Max Value         */
         /*----------------------------------------------------------*/
         /*f32LocalCalcDen|    1             |   3.35997090239693E15 */
         /*f32LocalCalcNum|    0             |     34358689800       */
         /*----------------------------------------------------------*/
         f32LocalCalcDen = ( (float32)( PtLim_facTThermoItAir_C
                                      * PtLim_tItAirCluEstim)
                           + (float32)( 512
                                      * PtLim_facTItAir_C));

         f32LocalCalcDen =  (f32LocalCalcDen * (float32)PtLim_facMassItAir_C);

         f32LocalCalcDen = (f32LocalCalcDen * (float32)u16LocalExt_pAirExtMes);
         f32LocalCalcDen = (f32LocalCalcDen * (float32)PtLim_tAirExtMes);

         f32LocalCalcDen = ( f32LocalCalcDen
                           / ( ( (float32)u16LocalItAirCluEstim
                               * (float32)u16LocalPAirRef_C)
                             * (float32)16384));

         if (f32LocalCalcDen < (float32)1)
         {
            f32LocalCalcOut = f32LocalCalcNum;
         }
         else
         {
            f32LocalCalcOut = (f32LocalCalcNum / f32LocalCalcDen);
         }
      }
      if (f32LocalCalcOut > (float32)65535)
      {
         PtLim_tItAirCluEstimGrd_MP = (uint16)65535;
      }
      else
      {
         PtLim_tItAirCluEstimGrd_MP = (uint16)f32LocalCalcOut;
      }
   }

   PROTMANCLU_u16AirCluEstimPrev2 =
      (uint16)MATHSRV_udtCLAMP(PtLim_tItAirCluEstim, 3568, 20368);
   /* Production of PtLim_tItAirCluEstim */
   u32LocalOut =
      (uint32)( ( (PtLim_tItAirCluEstim * 16000)
                + (PtLim_tItAirCluEstimGrd_MP * PtLim_tiSdlManCluTEstim_SC)
                + 8000) / 16000);
   PtLim_tItAirCluEstim = (uint16)MATHSRV_udtCLAMP(u32LocalOut, 3568, 20368);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidEstimHousClutchTmp                           */
/* !Description :  This function estimates the temperature of the clutch      */
/*                 housing.                                                   */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 PtLim_tItAirCluEstim;                                        */
/*  input uint16 PtLim_tCaseCluEstim;                                         */
/*  input uint16 PtLim_facTCaseItAir;                                         */
/*  input uint16 PtLim_facTCoMesAirExt;                                       */
/*  input uint16 PtLim_facTCaseExtAir;                                        */
/*  input uint16 PtLim_arCaseGear_C;                                          */
/*  input uint16 PtLim_tGearCluEstim;                                         */
/*  input uint16 PtLim_facTCaseGear_C;                                        */
/*  input uint16 PtLim_arCaseEng_C;                                           */
/*  input uint16 PtLim_tOilEstim;                                             */
/*  input uint16 PtLim_facTCaseEng_C;                                         */
/*  input uint8 PtLim_facMassCluCase_C;                                       */
/*  input uint16 PtLim_facTCluCase_C;                                         */
/*  input uint8 PtLim_facTThermoCluCase_C;                                    */
/*  input uint16 PtLim_tCaseCluEstimGrd_MP;                                   */
/*  output uint16 PtLim_tCaseCluEstimGrd_MP;                                  */
/*  output uint16 PROTMANCLU_u16CaseCluEstimPrev2;                            */
/*  output uint16 PtLim_tCaseCluEstim;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidEstimHousClutchTmp(void)
{
   /*  F03_03_04_Estimation_of_the_housing_clutch_temperature */
   sint8  s8LocalSigElem3;
   sint8  s8LocalSigElem4;
   sint8  s8LocalSigNum;
   uint16 u16LocalCalcDen22;
   uint32 u32LocalCalcDen1;
   uint32 u32LocalElem1;
   uint32 u32LocalElem2;
   uint32 u32LocalElem3;
   uint32 u32LocalModElem3;
   uint32 u32LocalModElem3_3;
   uint32 u32LocalElem4;
   uint32 u32LocalModElem4;
   uint32 u32LocalModElem4_4;
   uint32 u32LocalComp;
   uint32 u32LocalModDiv;
   uint32 u32LocalModDen2;
   uint32 u32LocalCalcDen2;
   uint32 u32LocalNum;
   uint32 u32LocalMod1;
   uint32 u32LocalMod2;
   uint32 u32LocalMod3;
   uint32 u32LocalMod4;
   uint32 u32LocalOut;
   uint32 u32LocalCalcDiv;
   uint32 u32LocalMod;
   sint32 s32LocalComp;
   sint32 s32LocalElem1;
   sint32 s32LocalElem2;
   sint32 s32LocalModElem1;
   sint32 s32LocalModElem2;
   sint32 s32LocalOut;
   sint32 s32LocalModElem1_3;
   sint32 s32LocalElem3;
   sint32 s32LocalElem4;
   sint32 s32LocalNum;


   /*PtLim_tCaseCluEstimGrd_MP=((Elem1 + Elem2 + Elem3 + Elem4)*Denom2)/Denom1*/
   /*Elem1 = ( (PtLim_tItAirCluEstim - PtLim_tCaseCluEstim)
             * PtLim_facTCaseItAir) / 4096 */
   s32LocalElem1 = (sint32)( PtLim_tItAirCluEstim - PtLim_tCaseCluEstim);
   if (s32LocalElem1 >= 0)
   {
      u32LocalElem1    = (uint32)(s32LocalElem1 * PtLim_facTCaseItAir);
      s32LocalElem1    = (sint32)(u32LocalElem1 / 4096);
      s32LocalModElem1 = (sint32)(u32LocalElem1 % 4096);
   }
   else
   {
      u32LocalElem1    =  (uint32)((-s32LocalElem1) * PtLim_facTCaseItAir);
      s32LocalElem1    = -(sint32)(u32LocalElem1 / 4096);
      s32LocalModElem1 = -(sint32)(u32LocalElem1 % 4096);
   }
   /*Elem2 = ( (PtLim_facTCoMesAirExt - PtLim_tCaseCluEstim)
             * PtLim_facTCaseExtAir) / 4096 */
   s32LocalElem2 = (sint32)( PtLim_facTCoMesAirExt - PtLim_tCaseCluEstim);
   if (s32LocalElem2 >= 0)
   {
      u32LocalElem2    = (uint32)(s32LocalElem2 * PtLim_facTCaseExtAir);
      s32LocalElem2    = (sint32)(u32LocalElem2 / 4096);
      s32LocalModElem2 = (sint32)(u32LocalElem2 % 4096);
   }
   else
   {
      u32LocalElem2    =  (uint32)((-s32LocalElem2) * PtLim_facTCaseExtAir);
      s32LocalElem2    = -(sint32)(u32LocalElem2 / 4096);
      s32LocalModElem2 = -(sint32)(u32LocalElem2 % 4096);
   }
   /*Elem3 = ( (PtLim_tGearCluEstim - PtLim_tCaseCluEstim)
             * PtLim_arCaseGear_C * PtLim_facTCaseGear_C) / 1048576 */
   if (PtLim_arCaseGear_C == 0)
   {
      u32LocalElem3      = 0;
      s8LocalSigElem3    = 1;
      u32LocalModElem3_3 = 0;
   }
   else
   {
      s32LocalElem3 = (PtLim_tGearCluEstim - PtLim_tCaseCluEstim);
      if (s32LocalElem3 < 0)
      {
         s8LocalSigElem3 = -1;
         u32LocalElem3   = (uint32)(-s32LocalElem3);
      }
      else
      {
         s8LocalSigElem3 = 1;
         u32LocalElem3   = (uint32)(s32LocalElem3);
      }
      u32LocalElem3    = u32LocalElem3 * PtLim_facTCaseGear_C;
      u32LocalModElem3 = u32LocalElem3 % 1048576;
      u32LocalElem3    = (u32LocalElem3 / 1048576) * PtLim_arCaseGear_C;
      u32LocalComp     = UINT32_MAX / (uint32)PtLim_arCaseGear_C;
      if (u32LocalModElem3 < u32LocalComp)
      {
         u32LocalModElem3   = u32LocalModElem3 * PtLim_arCaseGear_C;
         u32LocalModElem3_3 = u32LocalModElem3 % 1048576;
         u32LocalModElem3   = u32LocalModElem3 / 1048576;
      }
      else
      {
         u32LocalModElem3   = ((u32LocalModElem3 + 8) / 16)* PtLim_arCaseGear_C;
         u32LocalModElem3_3 = (u32LocalModElem3 % 65536) * 16;
         u32LocalModElem3   = u32LocalModElem3 / 65536;
      }
      u32LocalElem3 = u32LocalElem3 + u32LocalModElem3;
   }
   /*Elem4 = ( ((4 * PtLim_tOilEstim) - PtLim_tCaseCluEstim)
             * PtLim_facTCaseEng_C * PtLim_arCaseEng_C) / 1048576 */
   if (PtLim_arCaseEng_C == 0)
   {
      u32LocalElem4      = 0;
      s8LocalSigElem4    = 1;
      u32LocalModElem4_4 = 0;
   }
   else
   {
      s32LocalElem4 = ((4 * PtLim_tOilEstim) - PtLim_tCaseCluEstim);
      if (s32LocalElem4 < 0)
      {
         s8LocalSigElem4 = -1;
         u32LocalElem4   = (uint32)(-s32LocalElem4);
      }
      else
      {
         s8LocalSigElem4 = 1;
         u32LocalElem4   = (uint32)(s32LocalElem4);
      }
      u32LocalMod      = ((u32LocalElem4 % 4) * PtLim_facTCaseEng_C) / 4;
      u32LocalElem4    = (u32LocalElem4 / 4) * PtLim_facTCaseEng_C;
      u32LocalElem4    = u32LocalElem4 + u32LocalMod;
      u32LocalModElem4 = u32LocalElem4 % 262144;
      u32LocalElem4    = (u32LocalElem4 / 262144) * PtLim_arCaseEng_C;
      u32LocalComp     = UINT32_MAX / (uint32)PtLim_arCaseEng_C;
      if (u32LocalModElem4 < u32LocalComp)
      {
         u32LocalModElem4   = u32LocalModElem4 * PtLim_arCaseEng_C;
         u32LocalModElem4_4 = u32LocalModElem4 % 262144;
         u32LocalModElem4   = u32LocalModElem4 / 262144;
      }
      else
      {
         u32LocalModElem4   = ((u32LocalModElem4 + 2) / 4) * PtLim_arCaseEng_C;
         u32LocalModElem4_4 = (u32LocalModElem4 % 65536) * 4;
         u32LocalModElem4   = u32LocalModElem4 / 65536;
      }
      u32LocalElem4 = u32LocalElem4 + u32LocalModElem4;
   }
   s32LocalNum = (s32LocalElem1 + s32LocalElem2)
               + (s8LocalSigElem3 * (sint32)u32LocalElem3)
               + (s8LocalSigElem4 * (sint32)u32LocalElem4);
   if (s32LocalNum < 0)
   {
      s8LocalSigNum = -1;
      u32LocalNum   = (uint32)(-s32LocalNum);
   }
   else
   {
      s8LocalSigNum = 1;
      u32LocalNum   = (uint32)(s32LocalNum);
   }
   /*----------------------------------------------------------*/
   /* Variable         |      Min Value     |     Max Value    */
   /*----------------------------------------------------------*/
   /*s32LocalElem1     |     -1048544       |     1048544      */
   /*s32LocalModElem1  |         0          |        4095      */
   /*s32LocalElem2     |     -1048544       |     1048544      */
   /*s32LocalModElem2  |         0          |        4095      */
   /*u32LocalElem3     |         0          |   268423168      */
   /*u32LocalModElem3_3|         0          |     1048575      */
   /*u32LocalElem4     |         0          |  1073692672      */
   /*u32LocalModElem4_4|         0          |     1048575      */
   /*s32LocalNum       |    -1344212928     |  1344212928      */
   /*u32LocalNum       |         0          |  1344212928      */
   /*----------------------------------------------------------*/

   /*Denominator = ( ( (512 * PtLim_facTCluCase_C)
                     + (PtLim_facTThermoCluCase_C * PtLim_tCaseCluEstim))
                   * PtLim_facMassCluCase_C) / 512 */
   if (  ( PtLim_facMassCluCase_C == 0)
      || (  (PtLim_facTCluCase_C == 0)
         && ((PtLim_facTThermoCluCase_C == 0) || (PtLim_tCaseCluEstim == 0))))
   {
      /*If (Denominator = 0) --> (Output = Numerator)*/
      if (u32LocalNum < 131070)
      {
         /*Recup loss in Elem1 & Elem3 & Elem4*/
         s32LocalModElem1   = ((s32LocalModElem1 + s32LocalModElem2) * 2);
         u32LocalModElem3_3 = (u32LocalModElem3_3 + 64) / 128;
         u32LocalModElem4_4 = (u32LocalModElem4_4 + 16) / 32;
         s32LocalOut = ((s32LocalNum * 8192) + s32LocalModElem1)
                     + (s8LocalSigElem3 * (sint32)u32LocalModElem3_3)
                     + (s8LocalSigElem4 * (sint32)u32LocalModElem4_4);
      }
      else
      {
         s32LocalOut = s8LocalSigNum * 65535;
      }
   }
   else
   {
      u32LocalCalcDen1  =
         (uint32)( (PtLim_facTThermoCluCase_C * PtLim_tCaseCluEstim)
                 + (512 * PtLim_facTCluCase_C));
      u16LocalCalcDen22 = (uint16)(512 / PtLim_facMassCluCase_C);
      u32LocalCalcDen2  = 4194304 / (uint32)PtLim_facMassCluCase_C;
      u32LocalModDen2   = 4194304 % (uint32)PtLim_facMassCluCase_C;
      /*----------------------------------------------------------*/
      /* Variable         |      Min Value     |     Max Value    */
      /*----------------------------------------------------------*/
      /*u32LocalCalcDen1  |         1          |     50265345     */
      /*u32LocalCalcDen2  |       16448        |      4194304     */
      /*u16LocalCalcDen22 |         2          |          512     */
      /*u32LocalModDen2   |         0          |          255     */
      /*----------------------------------------------------------*/

      /*If (Denom1 / Denom2 < 1) --> (Output = Numerator)*/
      if (u32LocalCalcDen1 <= (uint32)u16LocalCalcDen22)
      {
         if (u32LocalNum < 131070)
         {
            /*Recup loss in Elem1 & Elem2 & Elem3 & Elem4*/
            s32LocalModElem1   = ((s32LocalModElem1 + s32LocalModElem2) * 2);
            u32LocalModElem3_3 = (u32LocalModElem3_3 + 64) / 128;
            u32LocalModElem4_4 = (u32LocalModElem4_4 + 16) / 32;
            s32LocalOut = ((s32LocalNum * 8192) + s32LocalModElem1)
                        + (s8LocalSigElem3 * (sint32)u32LocalModElem3_3)
                        + (s8LocalSigElem4 * (sint32)u32LocalModElem4_4);
         }
         else
         {
            s32LocalOut = s8LocalSigNum * 65535;
         }
      }
      else
      {
         /*If (Denominator != 0) --> (Output = (Num * Denom2) / Denom1)*/
         u32LocalModDiv  = u32LocalNum % u32LocalCalcDen1;
         u32LocalCalcDiv = u32LocalNum / u32LocalCalcDen1;
         /*!QAC Msg(2:0584): u32LocalCalcDen1 > u16LocalCalcDen22 >=2*/
         u32LocalComp    = UINT32_MAX / u32LocalCalcDen2;
         if (u32LocalCalcDiv < u32LocalComp)
         {
            u32LocalNum = u32LocalCalcDiv * u32LocalCalcDen2;
            if (u32LocalNum < 131070)
            {
               /*Recup loss in Elem1 & Elem2 &Elem3 & Elem4 */
               s32LocalModElem1_3 = ( s8LocalSigElem3
                                    * (sint32)u32LocalModElem3_3)
                                  + ( s8LocalSigElem4
                                    * (sint32)(4 * u32LocalModElem4_4))
                                  + ( (s32LocalModElem1 + s32LocalModElem2)
                                    * 256);
               /*----------------------------------------------------------*/
               /* Variable         |      Min Value     |     Max Value    */
               /*----------------------------------------------------------*/
               /*s32LocalModElem1_3|       -4194304     |       4194304    */
               /*u32LocalModDiv    |          0         |      50265344    */
               /*u32LocalCalcDiv   |          0         |             8    */
               /*----------------------------------------------------------*/
               s32LocalModElem1   = s32LocalModElem1_3 % 8192;
               s32LocalModElem1_3 = s32LocalModElem1_3 / 8192;
               s32LocalModElem1_3 = s32LocalModElem1_3
                                  * (sint32)u32LocalCalcDen2;
               s32LocalElem1 = MATHSRV_udtABS(s32LocalModElem1);
               s32LocalComp  = SINT32_MAX / (sint32)u32LocalCalcDen2;
               if (s32LocalElem1 < s32LocalComp)
               {
                  s32LocalModElem1 =
                     (s32LocalModElem1 * (sint32)u32LocalCalcDen2) / 8192;
               }
               else
               {
                  s32LocalModElem2 = s32LocalModElem1 % 16;
                  s32LocalModElem1 = s32LocalModElem1 / 16;
                  s32LocalModElem2 = ( s32LocalModElem2
                                     * (sint32)u32LocalCalcDen2)
                                   / 16;

                  s32LocalModElem1 = ( ( s32LocalModElem1
                                       * (sint32)u32LocalCalcDen2)
                                     + s32LocalModElem2)
                                   / 512;
               }
               s32LocalModElem1_3 =
                  (s32LocalModElem1_3 + s32LocalModElem1) / 128;
               s32LocalModElem1_3 = s32LocalModElem1_3/(sint32)u32LocalCalcDen1;
               /*Recup loss in Den2*/
               u32LocalModDen2 = (u32LocalModDen2 * u32LocalCalcDiv)
                               / PtLim_facMassCluCase_C;
               /*Recup loss in Div(Num , Den1)*/
               if (u32LocalModDiv < u32LocalComp)
               {
                  u32LocalModDiv =
                     (u32LocalModDiv * u32LocalCalcDen2) / u32LocalCalcDen1;
               }
               else
               {
                  u32LocalMod1   = u32LocalModDiv % 49152;
                  u32LocalModDiv = (u32LocalModDiv / 49152) * u32LocalCalcDen2;
                  u32LocalMod2   = ((u32LocalMod1 % 48) * u32LocalCalcDen2)/ 48;
                  u32LocalMod1   = ((u32LocalMod1 / 48) * u32LocalCalcDen2)
                                 + u32LocalMod2;
                  u32LocalMod4   = ((u32LocalMod1 % 1024) * 48)
                                 / u32LocalCalcDen1;
                  u32LocalMod1   = u32LocalMod1 / 1024;
                  u32LocalModDiv = u32LocalModDiv + u32LocalMod1;
                  u32LocalMod1   = u32LocalModDiv % u32LocalCalcDen1;
                  u32LocalModDiv = u32LocalModDiv / u32LocalCalcDen1;
                  u32LocalMod1   = u32LocalMod1 * 64;
                  u32LocalMod2   = u32LocalMod1 % u32LocalCalcDen1;
                  u32LocalMod1   = (u32LocalMod1 / u32LocalCalcDen1) * 768;
                  u32LocalMod2   = u32LocalMod2 * 64;
                  u32LocalMod3   = u32LocalMod2 % u32LocalCalcDen1;
                  u32LocalMod2   = ( u32LocalMod2 / u32LocalCalcDen1) * 12;
                  u32LocalMod3   = (u32LocalMod3 * 12) / u32LocalCalcDen1;
                  u32LocalMod1   = (u32LocalMod1 + u32LocalMod2)
                                 + (u32LocalMod3 + u32LocalMod4);
                  u32LocalModDiv = (u32LocalModDiv * 49152) + u32LocalMod1;
               }
               u32LocalNum = u32LocalNum + u32LocalModDiv + u32LocalModDen2;
               s32LocalOut = ((sint32)u32LocalNum * s8LocalSigNum)
                           + s32LocalModElem1_3;
            }
            else
            {
               s32LocalOut = s8LocalSigNum * 65535;
            }
         }
         else
         {
            s32LocalOut = s8LocalSigNum * 65535;
         }
      }
   }
   PtLim_tCaseCluEstimGrd_MP = (uint16)MATHSRV_udtCLAMP(s32LocalOut, 0, 65535);
   PROTMANCLU_u16CaseCluEstimPrev2 =
      (uint16)MATHSRV_udtCLAMP(PtLim_tCaseCluEstim, 3568, 20368);
   /* Production of PtLim_tCaseCluEstim */
   u32LocalOut =
      (uint32)( ( (PtLim_tCaseCluEstim * 16000)
                + (PtLim_tCaseCluEstimGrd_MP * PtLim_tiSdlManCluTEstim_SC)
                + 8000) / 16000);
   PtLim_tCaseCluEstim = (uint16)MATHSRV_udtCLAMP(u32LocalOut, 3568, 20368);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidEstimGearboxTemp                             */
/* !Description :  This function calculates the temperature of the gearbox.   */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_024.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 PtLim_tItAirCluEstim;                                        */
/*  input uint16 PtLim_tGearCluEstim;                                         */
/*  input uint16 PtLim_facTGearItAir;                                         */
/*  input sint16 PtLim_pwrDeltaGearSel;                                       */
/*  input uint16 PtLim_arCaseGear_C;                                          */
/*  input uint16 PtLim_tCaseCluEstim;                                         */
/*  input uint16 PtLim_facTCaseGear_C;                                        */
/*  input uint16 PtLim_facTCoMesAirExt;                                       */
/*  input uint16 PtLim_facTExtAirGear;                                        */
/*  input uint16 PtLim_facMassGear_C;                                         */
/*  input uint16 PtLim_facTGear_C;                                            */
/*  input uint8 PtLim_facTThermoGear_C;                                       */
/*  input uint16 PtLim_tGearCluEstimGrd_MP;                                   */
/*  output uint16 PtLim_tGearCluEstimGrd_MP;                                  */
/*  output uint16 PROTMANCLU_u16GearCluEstimPrev2;                            */
/*  output uint16 PtLim_tGearCluEstim;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidEstimGearboxTemp(void)
{
   /* F03_03_05_Estimation_of_the_gearbox_temperature */
   sint8  s8LocalSigElem3;
   sint8  s8LocalSigNum;
   uint16 u16LocalCalcDen22;
   uint32 u32LocalCalcDen1;
   uint32 u32LocalElem1;
   uint32 u32LocalElem4;
   uint32 u32LocalElem3;
   uint32 u32LocalModElem3;
   uint32 u32LocalModElem3_3;
   uint32 u32LocalComp;
   uint32 u32LocalModDiv;
   uint32 u32LocalModDen2;
   uint32 u32LocalCalcDen2;
   uint32 u32LocalNum;
   uint32 u32LocalOut;
   uint32 u32LocalCalcDiv;
   uint32 u32LocalMod1;
   uint32 u32LocalMod2;
   uint32 u32LocalMod3;
   uint32 u32LocalMod4;
   sint32 s32LocalElem1;
   sint32 s32LocalElem4;
   sint32 s32LocalElem2;
   sint32 s32LocalModElem1;
   sint32 s32LocalModElem4;
   sint32 s32LocalNum;
   sint32 s32LocalOut;
   sint32 s32LocalModElem1_3;
   sint32 s32LocalElem3;


   /*PtLim_tGearCluEstimGrd_MP=((Elem1 + Elem2 + Elem3 + Elem4)*Denom2)/Denom1*/

   /*Elem1 = ( (PtLim_tItAirCluEstim - PtLim_tGearCluEstim)
             * PtLim_facTGearItAir) / 1024 */
   s32LocalElem1 = (sint32)( PtLim_tItAirCluEstim - PtLim_tGearCluEstim);
   if (s32LocalElem1 >= 0)
   {
      u32LocalElem1    = (uint32)(s32LocalElem1 * PtLim_facTGearItAir);
      s32LocalElem1    = (sint32)(u32LocalElem1 / 1024);
      s32LocalModElem1 = (sint32)(u32LocalElem1 % 1024);
   }
   else
   {
      u32LocalElem1    =  (uint32)((-s32LocalElem1) * PtLim_facTGearItAir);
      s32LocalElem1    = -(sint32)(u32LocalElem1 / 1024);
      s32LocalModElem1 = -(sint32)(u32LocalElem1 % 1024);
   }
   /*Elem2 = PtLim_pwrDeltaGearSel * 64 */
   s32LocalElem2 = (sint32)(PtLim_pwrDeltaGearSel * 64);
   /*Elem3 = ( (PtLim_tCaseCluEstim - PtLim_tGearCluEstim)
             * PtLim_arCaseGear_C * PtLim_facTCaseGear_C)  / 262144 */
   if (PtLim_arCaseGear_C == 0)
   {
      u32LocalElem3      = 0;
      s8LocalSigElem3    = 1;
      u32LocalModElem3_3 = 0;
   }
   else
   {
      s32LocalElem3 = (PtLim_tCaseCluEstim - PtLim_tGearCluEstim);
      if (s32LocalElem3 < 0)
      {
         s8LocalSigElem3 = -1;
         u32LocalElem3   = (uint32)(-s32LocalElem3);
      }
      else
      {
         s8LocalSigElem3 = 1;
         u32LocalElem3   = (uint32)(s32LocalElem3);
      }
      u32LocalElem3 = u32LocalElem3 * PtLim_facTCaseGear_C;
      u32LocalComp  = UINT32_MAX / (uint32)PtLim_arCaseGear_C;
      if (u32LocalElem3 < u32LocalComp)
      {
         u32LocalElem3      = u32LocalElem3 * PtLim_arCaseGear_C;
         u32LocalModElem3_3 = u32LocalElem3 % 262144;
         u32LocalElem3      = u32LocalElem3 / 262144;
      }
      else
      {
         u32LocalModElem3 = u32LocalElem3 % 262144;
         u32LocalElem3    = u32LocalElem3 / 262144;
         u32LocalElem3    = u32LocalElem3 * PtLim_arCaseGear_C;

         if (u32LocalModElem3 < u32LocalComp)
         {
            u32LocalModElem3   = u32LocalModElem3 * PtLim_arCaseGear_C;
            u32LocalModElem3_3 = u32LocalModElem3 % 262144;
            u32LocalModElem3   = u32LocalModElem3 / 262144;
         }
         else
         {
            u32LocalModElem3   = ((u32LocalModElem3 + 2) / 4)
                               * PtLim_arCaseGear_C;
            u32LocalModElem3_3 = (u32LocalModElem3 % 65536) * 4;
            u32LocalModElem3   = u32LocalModElem3 / 65536;
         }
         u32LocalElem3 = u32LocalElem3 + u32LocalModElem3;
      }
   }
   /*Elem4 = ( (PtLim_facTCoMesAirExt - PtLim_tGearCluEstim)
             * PtLim_facTExtAirGear) / 1024 */
   s32LocalElem4 = (sint32)( PtLim_facTCoMesAirExt - PtLim_tGearCluEstim);
   if (s32LocalElem4 >= 0)
   {
      u32LocalElem4    = (uint32)(s32LocalElem4 * PtLim_facTExtAirGear);
      s32LocalElem4    = (sint32)(u32LocalElem4 / 1024);
      s32LocalModElem4 = (sint32)(u32LocalElem4 % 1024);
   }
   else
   {
      u32LocalElem4    =  (uint32)((-s32LocalElem4) * PtLim_facTExtAirGear);
      s32LocalElem4    = -(sint32)(u32LocalElem4 / 1024);
      s32LocalModElem4 = -(sint32)(u32LocalElem4 % 1024);
   }
   s32LocalNum = (s32LocalElem1 + s32LocalElem2)
               + ((s8LocalSigElem3 * (sint32)u32LocalElem3) + s32LocalElem4);
   if (s32LocalNum < 0)
   {
      s8LocalSigNum = -1;
      u32LocalNum   = (uint32)(-s32LocalNum);
   }
   else
   {
      s8LocalSigNum = 1;
      u32LocalNum   = (uint32)(s32LocalNum);
   }
   /*----------------------------------------------------------*/
   /* Variable         |      Min Value     |     Max Value    */
   /*----------------------------------------------------------*/
   /*s32LocalElem1     |     -4194176       |      4194176     */
   /*s32LocalModElem1  |         0          |         1023     */
   /*s32LocalElem2     |     -2097152       |      2097088     */
   /*u32LocalElem3     |         0          |   1073692673     */
   /*u32LocalModElem3_3|         0          |       262143     */
   /*s32LocalElem4     |     -4194176       |      4194176     */
   /*s32LocalModElem4  |         0          |         1023     */
   /*s32LocalNum       |    -1084178113     |   1084178113     */
   /*u32LocalNum       |         0          |   1084178113     */
   /*----------------------------------------------------------*/

   /*Denominator = ( ( (512 * PtLim_facTGear_C)
                     + (PtLim_facTThermoGear_C * PtLim_tGearCluEstim))
                   * PtLim_facMassGear_C) / 512 */
   if (  ( PtLim_facMassGear_C == 0)
      || ((PtLim_facTGear_C == 0)
         && ((PtLim_facTThermoGear_C == 0) || (PtLim_tGearCluEstim == 0))))
   {
      /*If (Denominator = 0) --> (Output = Numerator)*/
      if (u32LocalNum < 131070)
      {
         /*Recup loss in Elem1 & Elem3*/
         s32LocalModElem1   = ((s32LocalModElem1 + s32LocalModElem4) * 2);
         u32LocalModElem3_3 = (u32LocalModElem3_3 + 64) / 128;
         s32LocalOut = ((s32LocalNum * 2048) + s32LocalModElem1)
                     + (s8LocalSigElem3 * (sint32)u32LocalModElem3_3);
      }
      else
      {
         s32LocalOut = s8LocalSigNum * 65535;
      }
   }
   else
   {
      u32LocalCalcDen1  =
         (uint32)( (PtLim_facTThermoGear_C * PtLim_tGearCluEstim)
                 + (512 * PtLim_facTGear_C));
      u16LocalCalcDen22 = (uint16)(512 / PtLim_facMassGear_C );
      u32LocalCalcDen2  = 1048576 / (uint32)PtLim_facMassGear_C ;
      u32LocalModDen2   = 1048576 % (uint32)PtLim_facMassGear_C ;
      /*----------------------------------------------------------*/
      /* Variable         |      Min Value     |     Max Value    */
      /*----------------------------------------------------------*/
      /*u32LocalCalcDen1  |         1          |      50265345    */
      /*u32LocalCalcDen2  |        16          |       1048576    */
      /*u16LocalCalcDen22 |         0          |           512    */
      /*u32LocalModDen2   |         0          |         65535    */
      /*----------------------------------------------------------*/

      /*If (Denom1 / Denom2 < 1) --> (Output = Numerator)*/
      if (u32LocalCalcDen1 <= (uint32)u16LocalCalcDen22)
      {
         if (u32LocalNum < 131070)
         {
            /*Recup loss in Elem1 & Elem3*/
            s32LocalModElem1   = ((s32LocalModElem1 + s32LocalModElem4) * 2);
            u32LocalModElem3_3 = (u32LocalModElem3_3 + 64) / 128;
            s32LocalOut = ((s32LocalNum * 2048) + s32LocalModElem1)
                        + (s8LocalSigElem3 * (sint32)u32LocalModElem3_3);
         }
         else
         {
            s32LocalOut = s8LocalSigNum * 65535;
         }
      }
      else
      {
         /*If (Denominator != 0) --> (Output = (Num * Denom2) / Denom1)*/
         u32LocalModDiv  = u32LocalNum % u32LocalCalcDen1;
         u32LocalCalcDiv = u32LocalNum / u32LocalCalcDen1;
         /*!QAC Msg(2:0584): u32LocalCalcDen1 > u16LocalCalcDen22 >= 0*/
         u32LocalComp    = UINT32_MAX / u32LocalCalcDen2;
         if (u32LocalCalcDiv < u32LocalComp)
         {
            u32LocalNum = u32LocalCalcDiv * u32LocalCalcDen2;
            if (u32LocalNum < 131070)
            {
               /*Recup loss in Elem1 & Elem3*/
               s32LocalModElem1_3 = ( s8LocalSigElem3
                                    * (sint32)u32LocalModElem3_3)
                                  + ( (s32LocalModElem1 + s32LocalModElem4)
                                    * 256);
               /*----------------------------------------------------------*/
               /* Variable         |      Min Value     |     Max Value    */
               /*----------------------------------------------------------*/
               /*s32LocalModElem1_3|       -786432      |       786432     */
               /*u32LocalModDiv    |          0         |     50265344     */
               /*u32LocalCalcDiv   |          0         |         8191     */
               /*----------------------------------------------------------*/
               s32LocalModElem1   = s32LocalModElem1_3 % 512;
               s32LocalModElem1_3 =
                  (s32LocalModElem1_3 / 512) * ((sint32)u32LocalCalcDen2);
               s32LocalModElem1   =
                  (s32LocalModElem1 * (sint32)u32LocalCalcDen2) / 512;
               s32LocalModElem1_3 = (s32LocalModElem1_3 + s32LocalModElem1)
                                  / 512;
               s32LocalModElem1_3 = s32LocalModElem1_3
                                  / (sint32)u32LocalCalcDen1;
               /*Recup loss in Den2*/
               u32LocalModDen2 = (u32LocalModDen2 * u32LocalCalcDiv)
                               / PtLim_facMassGear_C;
               /*Recup loss in Div(Num , Den1)*/
               if (u32LocalModDiv < u32LocalComp)
               {
                  u32LocalModDiv =
                     (u32LocalModDiv * u32LocalCalcDen2) / u32LocalCalcDen1;
               }
               else
               {
                  u32LocalMod1   = u32LocalModDiv % 12288;
                  u32LocalModDiv = (u32LocalModDiv / 12288) * u32LocalCalcDen2;
                  u32LocalMod2   = ((u32LocalMod1 % 3) * u32LocalCalcDen2) / 3;
                  u32LocalMod1   = ((u32LocalMod1 / 3) * u32LocalCalcDen2)
                                 + u32LocalMod2;

                  u32LocalMod4   = ((u32LocalMod1 % 4096) * 3)
                                 / u32LocalCalcDen1;
                  u32LocalMod1   = u32LocalMod1 / 4096;
                  u32LocalModDiv = u32LocalModDiv + u32LocalMod1;
                  u32LocalMod1   = u32LocalModDiv % u32LocalCalcDen1;
                  u32LocalModDiv = u32LocalModDiv / u32LocalCalcDen1;
                  u32LocalMod1   = u32LocalMod1 * 64;
                  u32LocalMod2   = u32LocalMod1 % u32LocalCalcDen1;
                  u32LocalMod1   = (u32LocalMod1 / u32LocalCalcDen1) * 192;
                  u32LocalMod2   = u32LocalMod2 * 64;
                  u32LocalMod3   = u32LocalMod2 % u32LocalCalcDen1;
                  u32LocalMod2   = ( u32LocalMod2 / u32LocalCalcDen1) * 3;
                  u32LocalMod3   = (u32LocalMod3 * 3) / u32LocalCalcDen1;
                  u32LocalMod1   = (u32LocalMod1 + u32LocalMod2)
                                 + (u32LocalMod3 + u32LocalMod4);
                  u32LocalModDiv = (u32LocalModDiv * 12288) + u32LocalMod1;
               }
               u32LocalNum = u32LocalNum + u32LocalModDiv + u32LocalModDen2;
               s32LocalOut = ((sint32)u32LocalNum * s8LocalSigNum)
                           + s32LocalModElem1_3;
            }
            else
            {
               s32LocalOut = s8LocalSigNum * 65535;
            }
         }
         else
         {
            s32LocalOut = s8LocalSigNum * 65535;
         }
      }
   }
   PtLim_tGearCluEstimGrd_MP = (uint16)MATHSRV_udtCLAMP(s32LocalOut, 0, 65535);
   PROTMANCLU_u16GearCluEstimPrev2 =
      (uint16)MATHSRV_udtCLAMP(PtLim_tGearCluEstim, 3568, 20368);
   /* Production of PtLim_tGearCluEstim */
   u32LocalOut =
      (uint32)( ( (PtLim_tGearCluEstim * 16000)
                + (PtLim_tGearCluEstimGrd_MP * PtLim_tiSdlManCluTEstim_SC)
                + 8000) / 16000);
   PtLim_tGearCluEstim = (uint16)MATHSRV_udtCLAMP(u32LocalOut, 3568, 20368);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidCalculPreviousTemp                           */
/* !Description :  This function calculates 5 previous estimated temperatures.*/
/* !Number      :  FCT3.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint32 EOM_tiEngStop;                                               */
/*  input uint16 PtLim_tCluEstim;                                             */
/*  input uint16 PROTMANCLU_u16WhlCluEstimPrev2;                              */
/*  input uint16 PROTMANCLU_u16CluEstimPrev2;                                 */
/*  input uint16 PROTMANCLU_u16AirCluEstimPrev2;                              */
/*  input uint16 PROTMANCLU_u16CaseCluEstimPrev2;                             */
/*  input uint16 PROTMANCLU_u16GearCluEstimPrev2;                             */
/*  input uint16 PtLim_tWhlCluEstimPrev;                                      */
/*  input uint16 PtLim_tCluEstimPrev;                                         */
/*  input uint16 PtLim_tItAirCluEstimPrev;                                    */
/*  input uint16 PtLim_tCaseCluEstimPrev;                                     */
/*  input uint16 PtLim_tGearCluEstimPrev;                                     */
/*  output uint32 CoPt_tiEngStopMem_NV;                                       */
/*  output sint16 CoPt_tManCluEstimBfCord;                                    */
/*  output uint16 PtLim_tWhlCluEstimPrev;                                     */
/*  output uint16 PtLim_tCluEstimPrev;                                        */
/*  output uint16 PtLim_tItAirCluEstimPrev;                                   */
/*  output uint16 PtLim_tCaseCluEstimPrev;                                    */
/*  output uint16 PtLim_tGearCluEstimPrev;                                    */
/*  output uint16 CoPt_prm_tCluEstimMem_NV[5];                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidCalculPreviousTemp(void)
{
   /* F03_03_07_Calculation_of_the_previous_temperatures */
   uint32 u32LocalEOM_tiEngStop;
   sint32 s32LocalCoPt_tManCluEstimBfCord;


   /*Saving CoPt_tiEngStopMem_NV*/
   VEMS_vidGET(EOM_tiEngStop, u32LocalEOM_tiEngStop);
   CoPt_tiEngStopMem_NV = MATHSRV_udtMIN(u32LocalEOM_tiEngStop, 864000);
   /*Production of CoPt_tManCluEstimBfCord*/
   s32LocalCoPt_tManCluEstimBfCord = (sint32)(PtLim_tCluEstim - 4368);
   CoPt_tManCluEstimBfCord =
      (sint16)MATHSRV_udtCLAMP(s32LocalCoPt_tManCluEstimBfCord, -800, 16000);
   PtLim_tWhlCluEstimPrev =
      (uint16)MATHSRV_udtCLAMP(PROTMANCLU_u16WhlCluEstimPrev2, 3568, 20368);
   PtLim_tCluEstimPrev =
      (uint16)MATHSRV_udtCLAMP(PROTMANCLU_u16CluEstimPrev2, 3568, 20368);
   PtLim_tItAirCluEstimPrev =
      (uint16)MATHSRV_udtCLAMP(PROTMANCLU_u16AirCluEstimPrev2, 3568, 20368);
   PtLim_tCaseCluEstimPrev =
      (uint16)MATHSRV_udtCLAMP(PROTMANCLU_u16CaseCluEstimPrev2, 3568, 20368);
   PtLim_tGearCluEstimPrev =
      (uint16)MATHSRV_udtCLAMP(PROTMANCLU_u16GearCluEstimPrev2, 3568, 20368);
   CoPt_prm_tCluEstimMem_NV[0] = PtLim_tWhlCluEstimPrev;
   CoPt_prm_tCluEstimMem_NV[1] = PtLim_tCluEstimPrev;
   CoPt_prm_tCluEstimMem_NV[2] = PtLim_tItAirCluEstimPrev;
   CoPt_prm_tCluEstimMem_NV[3] = PtLim_tCaseCluEstimPrev;
   CoPt_prm_tCluEstimMem_NV[4] = PtLim_tGearCluEstimPrev;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidCalculPrevTempInit                           */
/* !Description :  This function calculates 5 estimated initial temperatures. */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint32 EOM_tiEngStop;                                               */
/*  input uint32 CoPt_tiEngStopMem_NV;                                        */
/*  input uint16 PtLim_tCoMes;                                                */
/*  input uint16 PROTMANCLU_u16PtLim_tiEngStopCf;                             */
/*  input uint16 PtLim_tiThdSelIniTClu_C;                                     */
/*  input boolean PtLim_bSelIniTClu_C;                                        */
/*  input uint8 PtLim_rWhlCluTIni_C;                                          */
/*  input uint8 PtLim_rCluTIni_C;                                             */
/*  input uint8 PtLim_rItAirTIni_C;                                           */
/*  input uint8 PtLim_rCaseCluTIni_C;                                         */
/*  input uint8 PtLim_rGearCluTIni_C;                                         */
/*  input uint16 PtLim_tiEngStopX_A[8];                                       */
/*  input uint16 CoPt_prm_tCluEstimMem_NV[5];                                 */
/*  input uint8 PtLim_tTCluEstimMemY_A[8];                                    */
/*  input uint8 PtLim_tTIniAfterStop_M[8][8];                                 */
/*  input uint16 PtLim_tiThermoExgAfterStop_A[8];                             */
/*  input uint8 PtLim_facThermoExgAfterStop_T[8];                             */
/*  input uint16 PtLim_prm_tTIniAfterStop_MP[5];                              */
/*  output uint16 PROTMANCLU_u16PtLim_tiEngStopCf;                            */
/*  output uint16 PtLim_prm_tTIniAfterStop_MP[5];                             */
/*  output uint16 PtLim_tWhlCluEstimPrev;                                     */
/*  output uint16 PtLim_tCluEstimPrev;                                        */
/*  output uint16 PtLim_tItAirCluEstimPrev;                                   */
/*  output uint16 PtLim_tCaseCluEstimPrev;                                    */
/*  output uint16 PtLim_tGearCluEstimPrev;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidCalculPrevTempInit(void)
{
   /*F03_03_07_Calculation_of_the_previous_temperatures */
   uint8  u8LocalInterp1d;
   uint8  u8LocalIndex;
   uint8  u8LocalInput;
   uint8  u8LocalCalibTIni[5];
   /*Msg(2:3132): the array is local, so the size can't be declared as define */
   sint8  s8Localsig;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint32 u32LocalEOM_tiEngStop;
   uint32 u32LocalCalc;
   uint32 u32LocalPtLim_tiEngStopCf;
   sint32 s32LocalPtLim_tCoMes;
   sint32 s32LocalInput;
   sint32 s32LocalPtLim_tiEngStopCf;
   sint32 s32LocalCalc;


   VEMS_vidGET(EOM_tiEngStop, u32LocalEOM_tiEngStop);
   if (u32LocalEOM_tiEngStop >= CoPt_tiEngStopMem_NV)
   {
      u32LocalPtLim_tiEngStopCf = u32LocalEOM_tiEngStop - CoPt_tiEngStopMem_NV;
      s8Localsig = 1;
   }
   else
   {
      u32LocalPtLim_tiEngStopCf = CoPt_tiEngStopMem_NV - u32LocalEOM_tiEngStop;
      s8Localsig = -1;
   }
   u32LocalPtLim_tiEngStopCf = (u32LocalPtLim_tiEngStopCf / (uint32)16);
   s32LocalPtLim_tiEngStopCf = s8Localsig * (sint32)u32LocalPtLim_tiEngStopCf;
   PROTMANCLU_u16PtLim_tiEngStopCf =
      (uint16)MATHSRV_udtCLAMP(s32LocalPtLim_tiEngStopCf, 0, 65535);
   s32LocalPtLim_tCoMes = (sint32)(PtLim_tCoMes * 16);
   if (PROTMANCLU_u16PtLim_tiEngStopCf >= PtLim_tiThdSelIniTClu_C)
   {
      for (u8LocalIndex = 0; u8LocalIndex < 5; u8LocalIndex++)
      {
         PtLim_prm_tTIniAfterStop_MP[u8LocalIndex] =
            (uint16)MATHSRV_udtCLAMP(s32LocalPtLim_tCoMes, 3568, 20368);
      }
   }
   else
   {
      if (PtLim_bSelIniTClu_C != 0)
      {
         u8LocalCalibTIni[0] = PtLim_rWhlCluTIni_C;
         u8LocalCalibTIni[1] = PtLim_rCluTIni_C;
         u8LocalCalibTIni[2] = PtLim_rItAirTIni_C;
         u8LocalCalibTIni[3] = PtLim_rCaseCluTIni_C;
         u8LocalCalibTIni[4] = PtLim_rGearCluTIni_C;
         u16LocalCalcParaX =
            MATHSRV_u16CalcParaIncAryU16(PtLim_tiEngStopX_A,
                                         PROTMANCLU_u16PtLim_tiEngStopCf,
                                         8);
         for (u8LocalIndex = 0; u8LocalIndex < 5; u8LocalIndex++)
         {
            s32LocalInput =
               (sint32)(CoPt_prm_tCluEstimMem_NV[u8LocalIndex] - 3568) / 64;
            u8LocalInput = (uint8)MATHSRV_udtCLAMP(s32LocalInput, 0, 255);
            u16LocalCalcParaY =
               MATHSRV_u16CalcParaIncAryU8(PtLim_tTCluEstimMemY_A,
                                           u8LocalInput,
                                           8);
            u8LocalInterp1d =
               MATHSRV_u8Interp2d(&PtLim_tTIniAfterStop_M[0][0],
                                  u16LocalCalcParaX,
                                  u16LocalCalcParaY,
                                  8);
            u32LocalCalc = (uint32)( ( ((4 * u8LocalInterp1d) + 223)
                                     * u8LocalCalibTIni[u8LocalIndex]) / 2);
            PtLim_prm_tTIniAfterStop_MP[u8LocalIndex] =
               (uint16)MATHSRV_udtCLAMP(u32LocalCalc, 3568, 20368);
         }
      }
      else
      {
         u16LocalCalcParaX =
            MATHSRV_u16CalcParaIncAryU16(PtLim_tiThermoExgAfterStop_A,
                                         PROTMANCLU_u16PtLim_tiEngStopCf, 8);
         u8LocalInterp1d =
            MATHSRV_u8Interp1d(PtLim_facThermoExgAfterStop_T,u16LocalCalcParaX);
         for (u8LocalIndex = 0; u8LocalIndex < 5; u8LocalIndex++)
         {
            s32LocalCalc = s32LocalPtLim_tCoMes
                         - (sint32)CoPt_prm_tCluEstimMem_NV[u8LocalIndex];
            s32LocalCalc = s32LocalCalc * u8LocalInterp1d;
            u32LocalCalc = 256 * CoPt_prm_tCluEstimMem_NV[u8LocalIndex];
            u32LocalCalc = (uint32)(s32LocalCalc + (sint32)u32LocalCalc);
            u32LocalCalc = (u32LocalCalc + 128) / (uint32)256;
            PtLim_prm_tTIniAfterStop_MP[u8LocalIndex] =
               (uint16)MATHSRV_udtCLAMP(u32LocalCalc, 3568, 20368);
         }
      }
   }
   PtLim_tWhlCluEstimPrev   = PtLim_prm_tTIniAfterStop_MP[0];
   PtLim_tCluEstimPrev      = PtLim_prm_tTIniAfterStop_MP[1];
   PtLim_tItAirCluEstimPrev = PtLim_prm_tTIniAfterStop_MP[2];
   PtLim_tCaseCluEstimPrev  = PtLim_prm_tTIniAfterStop_MP[3];
   PtLim_tGearCluEstimPrev  = PtLim_prm_tTIniAfterStop_MP[4];
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidActivationProtect                            */
/* !Description :  This function enables some clutch protections.             */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_027.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PROTMANCLU_vidCalcGradclutchTemp();                      */
/*  extf argret void PROTMANCLU_vidCalculationOffsets();                      */
/*  extf argret void PROTMANCLU_vidDeactvEngRotSpdctr();                      */
/*  extf argret void PROTMANCLU_vidActivProtections();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidActivationProtect(void)
{
   /* F04_Activation_of_protections */
   PROTMANCLU_vidCalcGradclutchTemp();
   PROTMANCLU_vidCalculationOffsets();
   PROTMANCLU_vidDeactvEngRotSpdctr();
   PROTMANCLU_vidActivProtections();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidCalcGradclutchTemp                           */
/* !Description :  This function calculates the gradient of the clutch        */
/*                 friction pad temperature.                                  */
/* !Number      :  FCT3.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_028.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 PROTMANCLU_u8PtLim_stManCluPrev;                              */
/*  input uint8 PtLim_stManClu;                                               */
/*  input sint16 CoPt_tManCluEstimBfCord;                                     */
/*  input sint16 PROTMANCLU_s16CoPt_tManCluPrev4;                             */
/*  input sint16 PROTMANCLU_s16CoPt_tManCluPrev3;                             */
/*  input sint16 PROTMANCLU_s16CoPt_tManCluPrev2;                             */
/*  input sint16 PROTMANCLU_s16CoPt_tManCluPrev1;                             */
/*  output sint16 PtLim_tGrdDynCluT;                                          */
/*  output sint16 PROTMANCLU_s16CoPt_tManCluPrev4;                            */
/*  output sint16 PROTMANCLU_s16CoPt_tManCluPrev3;                            */
/*  output sint16 PROTMANCLU_s16CoPt_tManCluPrev2;                            */
/*  output sint16 PROTMANCLU_s16CoPt_tManCluPrev1;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidCalcGradclutchTemp(void)
{
   /*F04_01_Calculation_of_the_gradient_of_the_clutch_facing_temperature */
   sint32 s32LocalPtLim_tGrdDynCluT;


   if ((PROTMANCLU_u8PtLim_stManCluPrev != 2) && (PtLim_stManClu == 2))
   {
      s32LocalPtLim_tGrdDynCluT = 0;
   }
   else
   {
      s32LocalPtLim_tGrdDynCluT =
         (sint32)( (125 * ( CoPt_tManCluEstimBfCord
                          - PROTMANCLU_s16CoPt_tManCluPrev4))
                 / (8 * PtLim_tiSdlManCluTEstim_SC));
   }
   PtLim_tGrdDynCluT =
      (sint16)MATHSRV_udtCLAMP(s32LocalPtLim_tGrdDynCluT, -3000, 3000);
   PROTMANCLU_s16CoPt_tManCluPrev4 =
      (sint16)MATHSRV_udtCLAMP(PROTMANCLU_s16CoPt_tManCluPrev3, -800, 16000);
   PROTMANCLU_s16CoPt_tManCluPrev3 =
      (sint16)MATHSRV_udtCLAMP(PROTMANCLU_s16CoPt_tManCluPrev2, -800, 16000);
   PROTMANCLU_s16CoPt_tManCluPrev2 =
      (sint16)MATHSRV_udtCLAMP(PROTMANCLU_s16CoPt_tManCluPrev1, -800, 16000);
   PROTMANCLU_s16CoPt_tManCluPrev1 =
      (sint16)MATHSRV_udtCLAMP(CoPt_tManCluEstimBfCord, -800, 16000);
}
/*---------------------------------End Of File--------------------------------*/