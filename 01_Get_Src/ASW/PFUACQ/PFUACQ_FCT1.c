/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PFUACQ                                                  */
/* !Description     : PFUACQ Component                                        */
/*                                                                            */
/* !Module          : PFUACQ                                                  */
/* !Description     : PFuAcq: FUEL RAIL PRESSURE ACQUISITION (GDI)            */
/*                                                                            */
/* !File            : PFUACQ_FCT1.C                                           */
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
/*   1 / PFUACQ_vidInitOutputs                                                */
/*   2 / PFUACQ_vidInit                                                       */
/*   3 / PFUACQ_vidInj                                                        */
/*   4 / PFUACQ_vidSpill                                                      */
/*   5 / PFUACQ_vidRailPressureDiagnosis                                      */
/*   6 / PFUACQ_vidElectrical_Diagnosis                                       */
/*   7 / PFUACQ_vidRailInjPressureTreat                                       */
/*   8 / PFUACQ_vidRailSplPressureTreat                                       */
/*   9 / PFUACQ_vidPrevEveInjPressureVal                                      */
/*   10 / PFUACQ_vidPrevRailSplPressureVal                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_6851391 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUACQ/PFUACQ_FCT1.C_v          $*/
/* $Revision::   1.9      $$Author::   mbenfrad       $$Date::   01 Sep 2014 $*/
/* $Author::   mbenfrad                               $$Date::   01 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "PFUACQ.h"
#include "PFUACQ_L.h"
#include "PFUACQ_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFUACQ_vidInitOutputs                                      */
/* !Description :  output's initialization                                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 PFuAcq_pFuRailFilt;                                          */
/*  input uint16 PFuAcq_pFuRailSplFilt;                                       */
/*  input uint16 PFuAcq_pFuRailMes;                                           */
/*  input uint16 PFuAcq_pFuRailSplMes;                                        */
/*  output uint16 Ext_pFuRailMesRef;                                          */
/*  output uint16 Ext_pFuMesFineResl;                                         */
/*  output uint16 PFuAcq_pFuRailMesRaw;                                       */
/*  output uint16 PFuAcq_pFuRailFilt;                                         */
/*  output uint32 PFUACQ_u32RailFilt_Mem;                                     */
/*  output uint16 PFuAcq_pFuRailSplFilt;                                      */
/*  output uint32 PFUACQ_u32RailSplFilt_Mem;                                  */
/*  output uint16 PFuAcq_pFuRailMesPrev;                                      */
/*  output uint16 PFuAcq_pFuRailMesSplPrev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFUACQ_vidInitOutputs(void)
{
   uint16 u16LocalOutput;


   VEMS_vidSET(Ext_pFuRailMesRef , 0);
   VEMS_vidSET(Ext_pFuMesFineResl , 0);
   VEMS_vidSET(PFuAcq_pFuRailMesRaw , 0);
   PFuAcq_pFuRailFilt = 0;
   PFUACQ_u32RailFilt_Mem = (uint32)(PFuAcq_pFuRailFilt * 65536);
   PFuAcq_pFuRailSplFilt = 0;
   PFUACQ_u32RailSplFilt_Mem = (uint32)(PFuAcq_pFuRailSplFilt * 65536);
   VEMS_vidGET(PFuAcq_pFuRailMes, u16LocalOutput);
   PFuAcq_pFuRailMesPrev = u16LocalOutput;
   VEMS_vidGET(PFuAcq_pFuRailSplMes, u16LocalOutput);
   PFuAcq_pFuRailMesSplPrev = u16LocalOutput;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFUACQ_vidInit                                             */
/* !Description :  All rail pressure information are initialized to           */
/*                 atmospheric pressure.                                      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Atmospheric_pressure;                                        */
/*  input uint16 Ext_pFuMesWRV_C;                                             */
/*  output uint16 PFuAcq_pFuRailMes;                                          */
/*  output uint16 Ext_pFuRailMes;                                             */
/*  output uint16 PFuAcq_pFuRailSplMes;                                       */
/*  output uint16 Ext_pFuRailSplMes;                                          */
/*  output uint16 Ext_pFuMesWRV;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFUACQ_vidInit(void)
{
   uint16 u16LocalAtmospheric_Pressure;
   uint16 u16LocalOutput;
   uint16 u16LocalExt_pFuMesWRV;


   VEMS_vidGET(Atmospheric_pressure, u16LocalAtmospheric_Pressure);
   u16LocalOutput = (uint16)( (uint32)(u16LocalAtmospheric_Pressure * 32)
                             / 3125);
   VEMS_vidSET(PFuAcq_pFuRailMes, u16LocalOutput);
   VEMS_vidSET(Ext_pFuRailMes, u16LocalOutput);
   VEMS_vidSET(PFuAcq_pFuRailSplMes, u16LocalOutput);
   VEMS_vidSET(Ext_pFuRailSplMes, u16LocalOutput);
   u16LocalExt_pFuMesWRV = Ext_pFuMesWRV_C;
   u16LocalExt_pFuMesWRV = (uint16)MATHSRV_udtMIN(u16LocalExt_pFuMesWRV, 2500);
   VEMS_vidSET(Ext_pFuMesWRV, u16LocalExt_pFuMesWRV);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFUACQ_vidInj                                              */
/* !Description :  The rail pressure is realized on SdlFast if the engine is  */
/*                 not running or at INJ event when the engine is running. The*/
/*                 voltage sent by the sensor is normalized and converted in  */
/*                 pressure                                                   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_upFuMes;                                                 */
/*  input uint16 Ext_uPfuSenPwr;                                              */
/*  input uint16 PFuAcq_uPFuMes_A[2];                                         */
/*  input uint16 Ext_pFuMes_T[2];                                             */
/*  input uint16 Ext_upFuMesNorm;                                             */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 PFuAcq_nEng_A[16];                                           */
/*  input uint16 PFuAcq_rFilGainPFuRailMes_T[16];                             */
/*  input uint16 PFuAcq_pFuRailMesPrev;                                       */
/*  input uint32 PFUACQ_u32RailFilt_Mem;                                      */
/*  output uint16 Ext_upFuMesNorm;                                            */
/*  output uint16 PFuAcq_pFuRailMesRaw;                                       */
/*  output uint32 PFUACQ_u32RailFilt_Mem;                                     */
/*  output uint16 PFuAcq_pFuRailFilt;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFUACQ_vidInj(void)
{
   uint16 u16LocalExt_upFuMes;
   uint16 u16LocalExt_uPfuSenPwr;
   uint16 u16LocalExt_nEng;
   uint16 u16Local;
   uint16 u16LocalCalcParaEng;
   uint16 u16LocalrFilGainPFuRailMes;
   uint16 u16LocalSiteInterpolation;
   uint16 u16LocalInterpolation;
   uint16 u16LocalBKPTSup;
   uint16 u16LocalBKPTInf;
   uint16 u16LocalMapSup;
   uint16 u16LocalMapInf;
   uint16 u16LocalPFuAcq_pFuRailMesRaw;
   uint32 u32LocalrFilGainPFuRailMes;
   uint32 u32LocalExt_upFuMesNorm;
   uint32 u32LocalDeltaValue;
   uint32 u32LocalResultValue;
   uint32 u32LocalInterpolation;
   sint32 s32LocalInterpolation;


   u16LocalPFuAcq_pFuRailMesRaw = 0;
   VEMS_vidGET(Ext_upFuMes, u16LocalExt_upFuMes);
   VEMS_vidGET(Ext_uPfuSenPwr, u16LocalExt_uPfuSenPwr);

   if (u16LocalExt_uPfuSenPwr != 0)
   {
      u32LocalExt_upFuMesNorm = (uint32)(u16LocalExt_upFuMes * 4096)
                              / u16LocalExt_uPfuSenPwr;
      Ext_upFuMesNorm =
         (uint16)MATHSRV_udtMIN(u32LocalExt_upFuMesNorm, 4095);
   }
   else
   {
      Ext_upFuMesNorm = 0;
   }
   if (PFuAcq_uPFuMes_A[1] >= PFuAcq_uPFuMes_A[0])
   {
      u16LocalBKPTSup = PFuAcq_uPFuMes_A[1];
      u16LocalBKPTInf = PFuAcq_uPFuMes_A[0];
      u16LocalMapSup = Ext_pFuMes_T[1];
      u16LocalMapInf = Ext_pFuMes_T[0];
   }
   else
   {
      u16LocalBKPTSup = PFuAcq_uPFuMes_A[0];
      u16LocalBKPTInf = PFuAcq_uPFuMes_A[1];
      u16LocalMapSup = Ext_pFuMes_T[0];
      u16LocalMapInf = Ext_pFuMes_T[1];
   }
   if (PFuAcq_uPFuMes_A[1] != PFuAcq_uPFuMes_A[0])
   {
      if (Ext_upFuMesNorm >= u16LocalBKPTSup)
      {
         u16LocalPFuAcq_pFuRailMesRaw = u16LocalMapSup;
      }
      if (Ext_upFuMesNorm < u16LocalBKPTInf)
      {
         u16LocalPFuAcq_pFuRailMesRaw = u16LocalMapInf;
      }
      if (  (Ext_upFuMesNorm < u16LocalBKPTSup)
         && (Ext_upFuMesNorm >= u16LocalBKPTInf))
      {
         /* Calculate the "Para" value of Ext_upFuMesNorm with
            PFuAcq_uPFuMes_A */

         u32LocalDeltaValue =
            (uint32)MATHSRV_udtABS(Ext_upFuMesNorm - PFuAcq_uPFuMes_A[0]);
         u32LocalDeltaValue = u32LocalDeltaValue << 16;
         u16LocalInterpolation =(uint16)(u16LocalBKPTSup - u16LocalBKPTInf);
         u16LocalSiteInterpolation =
            (uint16)(u32LocalDeltaValue / u16LocalInterpolation);
         /* Calculate the interpolation value on Ext_pFuMes_T */

         s32LocalInterpolation = (sint32)Ext_pFuMes_T[1] -
                                 (sint32)Ext_pFuMes_T[0];
         u16Local = (uint16)MATHSRV_udtABS(s32LocalInterpolation);
         if (s32LocalInterpolation > 0)
         {
            u32LocalInterpolation = u16Local * u16LocalSiteInterpolation;
            s32LocalInterpolation = (sint32)(u32LocalInterpolation / 65536);
         }
         else
         {
            u32LocalInterpolation = u16Local * u16LocalSiteInterpolation;
            s32LocalInterpolation = (sint32)(u32LocalInterpolation / 65536);
            s32LocalInterpolation = ((-1) * s32LocalInterpolation);
         }

         u32LocalResultValue =
            (uint32)((sint32)Ext_pFuMes_T[0] + s32LocalInterpolation);
         u16LocalPFuAcq_pFuRailMesRaw = (uint16)u32LocalResultValue;
      }
   }
   else
   {
      u16LocalPFuAcq_pFuRailMesRaw = Ext_pFuMes_T[0];
   }
   VEMS_vidSET(PFuAcq_pFuRailMesRaw, u16LocalPFuAcq_pFuRailMesRaw);

   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   u16LocalCalcParaEng = MATHSRV_u16CalcParaIncAryU16(PFuAcq_nEng_A,
                                                      u16LocalExt_nEng,
                                                      16);
   u16LocalrFilGainPFuRailMes = MATHSRV_u16Interp1d(PFuAcq_rFilGainPFuRailMes_T,
                                                    u16LocalCalcParaEng);

   u32LocalrFilGainPFuRailMes = (uint32)(u16LocalrFilGainPFuRailMes + 1);
   PFUACQ_u32RailFilt_Mem = (uint32)(PFuAcq_pFuRailMesPrev * 65536);
   if (u32LocalrFilGainPFuRailMes < 65536)
   {
      PFuAcq_pFuRailFilt =
         MATHSRV_u16FirstOrderFilterGu16((uint16)u32LocalrFilGainPFuRailMes,
                                         &PFUACQ_u32RailFilt_Mem,
                                         u16LocalPFuAcq_pFuRailMesRaw);
   }
   else
   {
      PFuAcq_pFuRailFilt = u16LocalPFuAcq_pFuRailMesRaw;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFUACQ_vidSpill                                            */
/* !Description :  The rail pressure is realized on SdlFast if the engine is  */
/*                 not synchronized or at “spill event” when the engine is    */
/*                 synchronized. The voltage sent by the sensor is normalized */
/*                 and converted in pressure                                  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/* !Trace_To    :  VEMS_R_10_04228_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_upFuMes;                                                 */
/*  input uint16 Ext_uPfuSenPwr;                                              */
/*  input uint16 PFuAcq_uPFuMes_A[2];                                         */
/*  input uint16 Ext_pFuMesSpl_T[2];                                          */
/*  input uint16 Ext_upFuMesSplNorm;                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 PFuAcq_nEng_A[16];                                           */
/*  input uint16 PFuAcq_rFilGainPFuRailSplMes_T[16];                          */
/*  input uint16 PFuAcq_pFuRailMesSplPrev;                                    */
/*  input uint32 PFUACQ_u32RailSplFilt_Mem;                                   */
/*  input uint16 PFuAcq_pFuRailSplMesRaw;                                     */
/*  output uint16 Ext_upFuMesSplNorm;                                         */
/*  output uint16 PFuAcq_pFuRailSplMesRaw;                                    */
/*  output uint32 PFUACQ_u32RailSplFilt_Mem;                                  */
/*  output uint16 PFuAcq_pFuRailSplFilt;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFUACQ_vidSpill(void)
{
   uint16 u16LocalExt_upFuMes;
   uint16 u16LocalExt_uPfuSenPwr;
   uint16 u16LocalExt_nEng;
   uint16 u16Local;
   uint16 u16LocalCalcParaEng;
   uint16 u16LocalrFilGainPFuRailSplMes;
   uint16 u16LocalSiteInterpolation;
   uint16 u16LocalInterpolation;
   uint16 u16LocalBKPTSup;
   uint16 u16LocalBKPTInf;
   uint16 u16LocalMapSup;
   uint16 u16LocalMapInf;
   uint32 u32LocalrFilGainPFuRailSplMes;
   uint32 u32LocalExt_upFuMesSplNorm;
   uint32 u32LocalInterpolation;
   uint32 u32LocalResultValue;
   uint32 u32LocalDeltaValue;
   sint32 s32LocalInterpolation;


   VEMS_vidGET(Ext_upFuMes, u16LocalExt_upFuMes);
   VEMS_vidGET(Ext_uPfuSenPwr, u16LocalExt_uPfuSenPwr);

   if (u16LocalExt_uPfuSenPwr != 0)
   {
      u32LocalExt_upFuMesSplNorm = (uint32)(u16LocalExt_upFuMes * 4096)
                                 / u16LocalExt_uPfuSenPwr;
      Ext_upFuMesSplNorm =
         (uint16)MATHSRV_udtMIN(u32LocalExt_upFuMesSplNorm, 4095);
   }
   else
   {
      Ext_upFuMesSplNorm = 0;
   }

   if (PFuAcq_uPFuMes_A[1] >= PFuAcq_uPFuMes_A[0])
   {
      u16LocalBKPTSup = PFuAcq_uPFuMes_A[1];
      u16LocalBKPTInf = PFuAcq_uPFuMes_A[0];
      u16LocalMapSup = Ext_pFuMesSpl_T[1];
      u16LocalMapInf = Ext_pFuMesSpl_T[0];
   }
   else
   {
      u16LocalBKPTSup = PFuAcq_uPFuMes_A[0];
      u16LocalBKPTInf = PFuAcq_uPFuMes_A[1];
      u16LocalMapSup = Ext_pFuMesSpl_T[0];
      u16LocalMapInf = Ext_pFuMesSpl_T[1];
   }

   if ( PFuAcq_uPFuMes_A[1] != PFuAcq_uPFuMes_A[0])
   {
      if (Ext_upFuMesSplNorm >= u16LocalBKPTSup)
      {
         PFuAcq_pFuRailSplMesRaw = u16LocalMapSup;
      }
      if (Ext_upFuMesSplNorm < u16LocalBKPTInf)
      {
         PFuAcq_pFuRailSplMesRaw = u16LocalMapInf;
      }
      if (  (Ext_upFuMesSplNorm < u16LocalBKPTSup)
         && (Ext_upFuMesSplNorm >= u16LocalBKPTInf))
      {
         /* Calculate the "Para" value of Ext_upFuMesSplNorm with
            PFuAcq_uPFuMes_A */

         u32LocalDeltaValue =
            (uint32)MATHSRV_udtABS(Ext_upFuMesSplNorm - PFuAcq_uPFuMes_A[0]);
         u32LocalDeltaValue = u32LocalDeltaValue << 16;
         u16LocalInterpolation =(uint16)(u16LocalBKPTSup - u16LocalBKPTInf);
         u16LocalSiteInterpolation =
            (uint16)(u32LocalDeltaValue / u16LocalInterpolation);
         /* Calculate the interpolation value on Ext_pFuMesSpl_T */

         s32LocalInterpolation = (sint32)Ext_pFuMesSpl_T[1] -
                                 (sint32)Ext_pFuMesSpl_T[0];
         u16Local = (uint16)MATHSRV_udtABS(s32LocalInterpolation);
         if (s32LocalInterpolation > 0)
         {
            u32LocalInterpolation = u16Local * u16LocalSiteInterpolation;
            s32LocalInterpolation = (sint32)(u32LocalInterpolation / 65536);
         }
         else
         {
            u32LocalInterpolation = u16Local * u16LocalSiteInterpolation;
            s32LocalInterpolation = (sint32)(u32LocalInterpolation / 65536);
            s32LocalInterpolation = ((-1) * s32LocalInterpolation);
         }

         u32LocalResultValue =
            (uint32)((sint32)Ext_pFuMesSpl_T[0] + s32LocalInterpolation);
         PFuAcq_pFuRailSplMesRaw = (uint16)u32LocalResultValue;
      }
   }
   else
   {
      PFuAcq_pFuRailSplMesRaw = Ext_pFuMesSpl_T[0];
   }

   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   u16LocalCalcParaEng = MATHSRV_u16CalcParaIncAryU16(PFuAcq_nEng_A,
                                                      u16LocalExt_nEng,
                                                      16);
   u16LocalrFilGainPFuRailSplMes =
      MATHSRV_u16Interp1d(PFuAcq_rFilGainPFuRailSplMes_T,
                          u16LocalCalcParaEng);

   u32LocalrFilGainPFuRailSplMes = (uint32)(u16LocalrFilGainPFuRailSplMes + 1);
   PFUACQ_u32RailSplFilt_Mem = (uint32)(PFuAcq_pFuRailMesSplPrev * 65536);

   if (u32LocalrFilGainPFuRailSplMes < 65536)
   {
      PFuAcq_pFuRailSplFilt =
         MATHSRV_u16FirstOrderFilterGu16((uint16)u32LocalrFilGainPFuRailSplMes,
                                         &PFUACQ_u32RailSplFilt_Mem,
                                         PFuAcq_pFuRailSplMesRaw);
   }
   else
   {
      PFuAcq_pFuRailSplFilt = PFuAcq_pFuRailSplMesRaw;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFUACQ_vidRailPressureDiagnosis                            */
/* !Description :  The rail pressure sensor is realized if there is no        */
/*                 confirmed failure on the rail pressure.                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/* !Trace_To    :  VEMS_R_10_04228_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void PFUACQ_vidElectrical_Diagnosis();                        */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PFUACQ_vidCoherencyDiagnosis();                          */
/*  input uint16 Ext_nEng;                                                    */
/*  output boolean Ext_bMonRunScp_PFuAcq;                                     */
/*  output boolean Ext_bMonRunScg_PFuAcq;                                     */
/*  output boolean Ext_bMonRunCoh_PFuAcq;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFUACQ_vidRailPressureDiagnosis(void)
{
   boolean bLocalInhDiag_pFuMes;
   boolean bLocalInhDiagCoh_pFuMes;
   uint16  u16LocalExt_nEng;


   bLocalInhDiag_pFuMes = GDGAR_bGetFRM(FRM_FRM_INHDIAG_PFUMES);
   if (bLocalInhDiag_pFuMes == 0)
   {
      Ext_bMonRunScp_PFuAcq = 1;
      Ext_bMonRunScg_PFuAcq = 1;
      PFUACQ_vidElectrical_Diagnosis();
   }
   else
   {
      Ext_bMonRunScp_PFuAcq = 0;
      Ext_bMonRunScg_PFuAcq = 0;
   }

   bLocalInhDiagCoh_pFuMes = GDGAR_bGetFRM(FRM_FRM_INHDIAGCOH_PFUMES);
   if (bLocalInhDiagCoh_pFuMes == 0)
   {
      VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
      if (u16LocalExt_nEng > 0)
      {
         Ext_bMonRunCoh_PFuAcq = 1;
      }
      else
      {
         Ext_bMonRunCoh_PFuAcq = 0;
      }
      PFUACQ_vidCoherencyDiagnosis();
   }
   else
   {
      Ext_bMonRunCoh_PFuAcq = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFUACQ_vidElectrical_Diagnosis                             */
/* !Description :  The raw voltage sent by the rail pressure sensor is        */
/*                 compared to a high and a low thresholds. If this voltage is*/
/*                 not included between these two thresholds, a failure flag  */
/*                 is sent.                                                   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_upFuMes;                                                 */
/*  input uint16 Ext_uDgoScp_pFuMes_C;                                        */
/*  input uint16 Ext_uDgoScg_pFuMes_C;                                        */
/*  output boolean Ext_bDgoScp_PFuAcq;                                        */
/*  output boolean Ext_bDgoScg_PFuAcq;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFUACQ_vidElectrical_Diagnosis(void)
{
   uint16   u16LocalExt_upFuMes;


   VEMS_vidGET(Ext_upFuMes, u16LocalExt_upFuMes);
   if (u16LocalExt_upFuMes > Ext_uDgoScp_pFuMes_C)
   {
      Ext_bDgoScp_PFuAcq = 1;
   }
   else
   {
      Ext_bDgoScp_PFuAcq = 0;
   }

   if (u16LocalExt_upFuMes < Ext_uDgoScg_pFuMes_C)
   {
      Ext_bDgoScg_PFuAcq = 1;
   }
   else
   {
      Ext_bDgoScg_PFuAcq = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFUACQ_vidRailInjPressureTreat                             */
/* !Description :  When there is no failure, the strategy sends the measured  */
/*                 and filtered value.  If a failure is detected on the rail  */
/*                 pressure information, the acquisition is frozen. The       */
/*                 pressure value return by the strategy is the last correct  */
/*                 value.                                                     */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_pFuRcv_C;                                                */
/*  input boolean Ext_bDgoScg_PFuAcq;                                         */
/*  input boolean Ext_bDgoScp_PFuAcq;                                         */
/*  input boolean Ext_bDgoCoh_PFuAcq;                                         */
/*  input uint16 PFuAcq_pFuRailMesPrev;                                       */
/*  input uint16 PFuAcq_pFuRailFilt;                                          */
/*  output uint16 Ext_pFuRailMesRef;                                          */
/*  output uint16 Ext_pFuRailMes;                                             */
/*  output uint16 PFuAcq_pFuRailMes;                                          */
/*  output uint16 Ext_pFuMesWRV;                                              */
/*  output uint16 Ext_pFuMesFineResl;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFUACQ_vidRailInjPressureTreat(void)
{
   boolean bLocalAcvDftMod_pFuMes;
   uint16  u16LocalExt_pFuMesWRV;
   uint16  u16LocalExt_pFu;
   uint16  u16LocalCalcul;


   bLocalAcvDftMod_pFuMes = GDGAR_bGetFRM(FRM_FRM_ACVDFTMOD_PFUMES);

   if (bLocalAcvDftMod_pFuMes != 0)
   {
      u16LocalExt_pFu = Ext_pFuRcv_C;
   }
   else
   {
      if (  (Ext_bDgoScg_PFuAcq != 0)
         || (Ext_bDgoScp_PFuAcq != 0)
         || (Ext_bDgoCoh_PFuAcq != 0))
      {
         u16LocalExt_pFu = PFuAcq_pFuRailMesPrev;
      }
      else
      {
         u16LocalExt_pFu = PFuAcq_pFuRailFilt;
      }
   }
   VEMS_vidSET(Ext_pFuRailMesRef, u16LocalExt_pFu);
   VEMS_vidSET(Ext_pFuRailMes, u16LocalExt_pFu);
   VEMS_vidSET(PFuAcq_pFuRailMes, u16LocalExt_pFu);
   u16LocalExt_pFuMesWRV = (uint16)( (uint32)(u16LocalExt_pFu * 10)
                                   / 128);
   u16LocalExt_pFuMesWRV =
      (uint16)MATHSRV_udtMIN(u16LocalExt_pFuMesWRV, 2500);
   VEMS_vidSET(Ext_pFuMesWRV, u16LocalExt_pFuMesWRV);

   u16LocalCalcul = (uint16)(((uint32)(u16LocalExt_pFu * 5) + 32) / 64);
   u16LocalCalcul = (uint16)MATHSRV_udtMIN(u16LocalCalcul, 3000);
   VEMS_vidSET(Ext_pFuMesFineResl, u16LocalCalcul);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFUACQ_vidRailSplPressureTreat                             */
/* !Description :  When there is no failure, the strategy sends the measured  */
/*                 and filtered value.  If a failure is detected on the rail  */
/*                 pressure information, the acquisition is frozen. The       */
/*                 pressure value return by the strategy is the last correct  */
/*                 value.                                                     */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_pFuRcv_C;                                                */
/*  input boolean Ext_bDgoScg_PFuAcq;                                         */
/*  input boolean Ext_bDgoScp_PFuAcq;                                         */
/*  input boolean Ext_bDgoCoh_PFuAcq;                                         */
/*  input uint16 PFuAcq_pFuRailMesSplPrev;                                    */
/*  input uint16 PFuAcq_pFuRailSplFilt;                                       */
/*  output uint16 Ext_pFuRailSplMes;                                          */
/*  output uint16 PFuAcq_pFuRailSplMes;                                       */
/*  output uint16 Ext_pFuRailMesRef;                                          */
/*  output uint16 Ext_pFuMesFineResl;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFUACQ_vidRailSplPressureTreat(void)
{
   boolean bLocalAcvDftMod_pFuMes;
   uint16  u16LocalExt_pFu;
   uint16  u16LocalCalcul;


   bLocalAcvDftMod_pFuMes = GDGAR_bGetFRM(FRM_FRM_ACVDFTMOD_PFUMES);

   if (bLocalAcvDftMod_pFuMes != 0)
   {
      u16LocalExt_pFu = Ext_pFuRcv_C;
   }
   else
   {
      if (  (Ext_bDgoScg_PFuAcq != 0)
         || (Ext_bDgoScp_PFuAcq != 0)
         || (Ext_bDgoCoh_PFuAcq != 0))
      {
         u16LocalExt_pFu = PFuAcq_pFuRailMesSplPrev;
      }
      else
      {
         u16LocalExt_pFu = PFuAcq_pFuRailSplFilt;
      }
   }
   VEMS_vidSET(Ext_pFuRailSplMes, u16LocalExt_pFu);
   VEMS_vidSET(PFuAcq_pFuRailSplMes, u16LocalExt_pFu);
   VEMS_vidSET(Ext_pFuRailMesRef, u16LocalExt_pFu);

   u16LocalCalcul = (uint16)(((uint32)(u16LocalExt_pFu * 5) + 32) / 64);
   u16LocalCalcul = (uint16)MATHSRV_udtMIN(u16LocalCalcul, 3000);
   VEMS_vidSET(Ext_pFuMesFineResl, u16LocalCalcul);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFUACQ_vidPrevEveInjPressureVal                            */
/* !Description :  We calculate the previous value of the rail pressure at INJ*/
/*                 event and on SdlFast if the engine is not running.         */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 PFuAcq_pFuRailMes;                                           */
/*  input uint16 PFuAcq_pFuRailMesPrev;                                       */
/*  output uint16 PFuAcq_pFuRailMesPrev;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFUACQ_vidPrevEveInjPressureVal(void)
{
   VEMS_vidGET(PFuAcq_pFuRailMes, PFuAcq_pFuRailMesPrev);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFUACQ_vidPrevRailSplPressureVal                           */
/* !Description :  We calculate the previous value of the rail pressure at «  */
/*                 spill event » and on SdlFast if the engine is not          */
/*                 synchronized.                                              */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 PFuAcq_pFuRailSplMes;                                        */
/*  input uint16 PFuAcq_pFuRailMesSplPrev;                                    */
/*  output uint16 PFuAcq_pFuRailMesSplPrev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFUACQ_vidPrevRailSplPressureVal(void)
{
   VEMS_vidGET(PFuAcq_pFuRailSplMes, PFuAcq_pFuRailMesSplPrev);
}
/*---------------------------- end of file -----------------------------------*/