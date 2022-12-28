/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : WgCmdSp                                                 */
/* !Description     : WgCmdSp component.                                      */
/*                                                                            */
/* !Module          : WgCmdSp                                                 */
/* !Description     : WASTEGATE SOLENOID VALVE COMMAND SETPOINT               */
/*                                                                            */
/* !File            : WGCMDSP_FCT2.C                                          */
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
/*   1 / WgCmdSp_vidInit                                                      */
/*   2 / WgCmdSp_vidClcPID                                                    */
/*   3 / WgCmdSp_vidClcElm_P                                                  */
/*   4 / WgCmdSp_vidClcElm_A                                                  */
/*   5 / WgCmdSp_vidMemrSdl                                                   */
/*   6 / WgCmdSp_vidFmtAdpv                                                   */
/*   7 / WgCmdSp_vidClcAdpv                                                   */
/*   8 / WgCmdSp_vidClcElm_I                                                  */
/*   9 / WgCmdSp_vidClcElm_D                                                  */
/*   10 / WgCmdSp_vidSumElmPIDA                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5070689 / 02                                        */
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
#include "VEMS.h"
#include "WgCmdSp.h"
#include "WgCmdSp_L.h"
#include "WgCmdSp_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgCmdSp_vidInit                                            */
/* !Description :  This module set the initial values of some variables, to be*/
/*                 updated on Reset event of the ECU.                         */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Wg_nrSampleTiClcAdpv_C;                                       */
/*  input sint16 Wg_rWgCmdSpIni_C;                                            */
/*  output uint8 Wg_ctDownSampleTiClcAdpv;                                    */
/*  output sint16 Wg_rWgCmdSp;                                                */
/*  output sint16 Wg_rWgCmdSpIni_C;                                           */
/*  output sint16 Wg_rWgCmdSpPrev;                                            */
/*  output sint16 Ext_rCtlTestMod;                                            */
/*  output sint32 Wg_pDervFiltSpgPresErrMem;                                  */
/*  output sint16 Wg_pDervFiltSpgPresErr;                                     */
/*  output sint16 Wg_pSpgPresErrPrev;                                         */
/*  output sint16 Wg_rWgServoElmAdpvCmdPrev;                                  */
/*  output sint16 Wg_rWgServoElmIntglCmdPrev;                                 */
/*  output uint16 Wg_rEngineLoadPrev;                                         */
/*  output boolean WGCMDSP_bBoostPresClCtlAcvPrev;                            */
/*  output sint16 WGCMDSP_s16Ext_rCtlIntTestMod;                              */
/*  output boolean Ext_bAcvCtlExt;                                            */
/*  output sint16 Ext_rCtlIntTestMod;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgCmdSp_vidInit(void)
{
   sint16 s16LocalWg_rWgCmdSp;


   Wg_ctDownSampleTiClcAdpv = Wg_nrSampleTiClcAdpv_C;
   VEMS_vidSET(Wg_rWgCmdSp, Wg_rWgCmdSpIni_C);
   Wg_rWgCmdSpPrev = Wg_rWgCmdSpIni_C;
   s16LocalWg_rWgCmdSp = (sint16)MATHSRV_udtMAX(Wg_rWgCmdSpIni_C, -32767);
   VEMS_vidSET(Ext_rCtlTestMod, s16LocalWg_rWgCmdSp);
   Wg_pDervFiltSpgPresErrMem = 0;
   Wg_pDervFiltSpgPresErr = 0;
   Wg_pSpgPresErrPrev = 0;
   Wg_rWgServoElmAdpvCmdPrev = 0;
   Wg_rWgServoElmIntglCmdPrev = 0;
   Wg_rEngineLoadPrev = 0;
   WGCMDSP_bBoostPresClCtlAcvPrev = 0;
   WGCMDSP_s16Ext_rCtlIntTestMod = 0;
   VEMS_vidSET(Ext_bAcvCtlExt, 0);
   VEMS_vidSET(Ext_rCtlIntTestMod, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgCmdSp_vidClcPID                                          */
/* !Description :  A four-part correction is added to the open loop PWM       */
/*                 command                                                    */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WgCmdSp_vidClcElm_P();                                   */
/*  extf argret void WgCmdSp_vidClcElm_A();                                   */
/*  extf argret void WgCmdSp_vidClcElm_I();                                   */
/*  extf argret void WgCmdSp_vidClcElm_D();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgCmdSp_vidClcPID(void)
{
   WgCmdSp_vidClcElm_P();
   WgCmdSp_vidClcElm_A();
   WgCmdSp_vidClcElm_I();
   WgCmdSp_vidClcElm_D();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgCmdSp_vidClcElm_P                                        */
/* !Description :  The computation of the proportional part is not null until */
/*                 the boost pressure is regulated. This part is the boost    */
/*                 pressure error multiplied by a gain; however, the error is */
/*                 considered as null inside an adjustable dead zone.         */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Regime_moteur;                                               */
/*  input sint16 Wg_pSpgFilPresErr;                                           */
/*  input uint16 Wg_nEngBkpt_A[9];                                            */
/*  input uint16 Wg_pSpgFilPresErr_A[9];                                      */
/*  input uint16 Wg_ServoPIDCoeffProp_M[9][9];                                */
/*  input boolean Wg_bEnaApplServoCmd;                                        */
/*  input sint16 Wg_pDbndThdEnaElmProp_C;                                     */
/*  output sint16 Wg_rWgServoElmPropCmd;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgCmdSp_vidClcElm_P(void)
{
   uint16 u16LocalInterp2d;
   uint16 u16LocalWg_pSpgFilPresErr;
   uint16 u16LocalRegime_moteur;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalPosDiff;
   sint16 s16ServoElmPropCmd;
   uint32 u32LocalWg_rWgServoElmPropCmd;
   sint32 s32LocalDiv;
   sint32 s32LocalSum;


   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   u16LocalWg_pSpgFilPresErr = (uint16)(Wg_pSpgFilPresErr + 32768);
   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(Wg_nEngBkpt_A,
                                   u16LocalRegime_moteur,
                                   9);
   u16LocalCalcParaY =
      MATHSRV_u16CalcParaIncAryU16(Wg_pSpgFilPresErr_A,
                                   u16LocalWg_pSpgFilPresErr,
                                   9);
   u16LocalInterp2d =
      MATHSRV_u16Interp2d(&Wg_ServoPIDCoeffProp_M[0][0],
                          u16LocalCalcParaX,
                          u16LocalCalcParaY,
                          9);
   if (Wg_bEnaApplServoCmd != 0)
   {
      if (  (Wg_pSpgFilPresErr <= Wg_pDbndThdEnaElmProp_C)
         && (Wg_pSpgFilPresErr >= (-Wg_pDbndThdEnaElmProp_C)))
      {
         Wg_rWgServoElmPropCmd = 0;
      }
      else
      {
         if (Wg_pSpgFilPresErr > Wg_pDbndThdEnaElmProp_C)
         {
            u16LocalPosDiff = (uint16)( Wg_pSpgFilPresErr
                                      - Wg_pDbndThdEnaElmProp_C);
            u32LocalWg_rWgServoElmPropCmd =
               (uint32)((u16LocalPosDiff * u16LocalInterp2d) / 1250);
            Wg_rWgServoElmPropCmd =
               (sint16)MATHSRV_udtMIN(u32LocalWg_rWgServoElmPropCmd, 32767);
         }
         else
         {
            s32LocalSum = (sint32)( Wg_pSpgFilPresErr
                                  + Wg_pDbndThdEnaElmProp_C);
            if (u16LocalInterp2d != 0)
            {
               s32LocalDiv = (-40960000 / u16LocalInterp2d);
               if (s32LocalSum >= s32LocalDiv)
               {
                  s16ServoElmPropCmd =
                     (sint16)((s32LocalSum * u16LocalInterp2d) / 1250);
               }
               else
               {
                  s16ServoElmPropCmd = -32768;
               }
            }
            else
            {
               s16ServoElmPropCmd = 0;
            }
            Wg_rWgServoElmPropCmd = s16ServoElmPropCmd;
         }
      }
   }
   else
   {
      Wg_rWgServoElmPropCmd = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgCmdSp_vidClcElm_A                                        */
/* !Description :  The adaptive part is computed by filtering the integral    */
/*                 part every at the end of the down counter. Its value is    */
/*                 stored in EEPROM momory in order to be able to detect any  */
/*                 damage (soiling, excessive ageing…) of the solenoid valve  */
/*                 or of the Wastegate.                                       */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WgCmdSp_vidMemrSdl();                                    */
/*  extf argret void WgCmdSp_vidClcAdpv();                                    */
/*  input boolean Wg_bServoElmAdpvCmdEnaClc;                                  */
/*  input sint16 Wg_rWgServoElmAdpvCmd;                                       */
/*  output sint16 Wg_rWgServoElmAdpvCmdPrev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgCmdSp_vidClcElm_A(void)
{
   WgCmdSp_vidMemrSdl();
   if (Wg_bServoElmAdpvCmdEnaClc != 0)
   {
      WgCmdSp_vidClcAdpv();
   }
   Wg_rWgServoElmAdpvCmdPrev = Wg_rWgServoElmAdpvCmd;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgCmdSp_vidMemrSdl                                         */
/* !Description :  This module enables the strategy to update the integral    */
/*                 part at the end of the down counter                        */
/*                 Wg_ctDownSampleTiClcAdpv.                                  */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WgCmdSp_vidFmtAdpv();                                    */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Wg_ctDownSampleTiClcAdpv;                                     */
/*  input boolean Wg_bEnaApplAdpv;                                            */
/*  input sint16 Wg_rRawInctAdpv;                                             */
/*  input sint16 Wg_rWgServoElmAdpvCmdPrev;                                   */
/*  input sint16 Wg_rWgServoElmAdpvCmdThdMin_C;                               */
/*  input sint16 Wg_rWgServoElmAdpvCmdThdMax_C;                               */
/*  output uint8 Wg_ctDownSampleTiClcAdpv;                                    */
/*  output boolean Wg_bServoElmAdpvCmdEnaClc;                                 */
/*  output sint16 Wg_rWgServoUpdElmAdpvIntglCmd;                              */
/*  output boolean Ext_bAcvCtlExt;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgCmdSp_vidMemrSdl(void)
{
   Wg_ctDownSampleTiClcAdpv = (uint8)
                              MATHSRV_udtMAX((Wg_ctDownSampleTiClcAdpv - 1),0);
   WgCmdSp_vidFmtAdpv();
   if (Wg_ctDownSampleTiClcAdpv == 0)
   {
      Wg_bServoElmAdpvCmdEnaClc = 1;
      if (Wg_bEnaApplAdpv != 0)
      {
         if (  (  (Wg_rRawInctAdpv <= 0)
               && (Wg_rWgServoElmAdpvCmdPrev <= Wg_rWgServoElmAdpvCmdThdMin_C))
            || (  (Wg_rRawInctAdpv >= 0)
               && (Wg_rWgServoElmAdpvCmdPrev >= Wg_rWgServoElmAdpvCmdThdMax_C)))
         {
            Wg_rWgServoUpdElmAdpvIntglCmd = 0;
            VEMS_vidSET(Ext_bAcvCtlExt, 1);
         }
         else
         {
            Wg_rWgServoUpdElmAdpvIntglCmd = Wg_rRawInctAdpv;
            VEMS_vidSET(Ext_bAcvCtlExt, 0);
         }
      }
      else
      {
         Wg_rWgServoUpdElmAdpvIntglCmd = 0;
         VEMS_vidSET(Ext_bAcvCtlExt, 1);
      }
   }
   else
   {
      Wg_bServoElmAdpvCmdEnaClc = 0;
      Wg_rWgServoUpdElmAdpvIntglCmd = 0;
      VEMS_vidSET(Ext_bAcvCtlExt, 1);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgCmdSp_vidFmtAdpv                                         */
/* !Description :  This module computes a lay-out of the integral part before */
/*                 computing the adaptive part. It enables the integral part  */
/*                 to converge (thanks to the adaptive part) to a setpoint    */
/*                 value comprised in a dead zone.                            */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint16 Wg_rWgServoElmIntglCmdPrev;                                  */
/*  input sint16 Wg_rWgCmdTarElmIntgl_C;                                      */
/*  input sint16 Wg_rDbndElmAdpvThdMax_C;                                     */
/*  input sint16 Wg_rDbndElmAdpvThdMin_C;                                     */
/*  input sint16 Wg_rFacFiltMidAdpv_C;                                        */
/*  output sint16 Wg_rRawInctAdpv;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgCmdSp_vidFmtAdpv(void)
{
   uint32 u32LocalDiff;
   uint32 u32LocalWg_rRawInctAdpv;
   sint32 s32LocalDeadZoneValue;
   sint32 s32LocalDiv;
   sint32 s32LocalDiff;


   s32LocalDeadZoneValue = ( Wg_rWgServoElmIntglCmdPrev
                           - Wg_rWgCmdTarElmIntgl_C);
   if (  (s32LocalDeadZoneValue <= (sint32)Wg_rDbndElmAdpvThdMax_C)
      && (s32LocalDeadZoneValue >= (sint32)Wg_rDbndElmAdpvThdMin_C))
   {
      Wg_rRawInctAdpv = 0;
   }
   else
   {
      if (s32LocalDeadZoneValue > (sint32)Wg_rDbndElmAdpvThdMax_C)
      {
         u32LocalDiff = (uint32)( s32LocalDeadZoneValue
                                - Wg_rDbndElmAdpvThdMax_C);
         if (Wg_rFacFiltMidAdpv_C != 0)
         {
            if (Wg_rFacFiltMidAdpv_C > 0)
            {
               u32LocalWg_rRawInctAdpv =
                  ((u32LocalDiff * (uint32)Wg_rFacFiltMidAdpv_C) / 32768);
               Wg_rRawInctAdpv =
                  (sint16)MATHSRV_udtMIN(u32LocalWg_rRawInctAdpv, 32767);
            }
            else
            {
               s32LocalDiv = (-1073741824 / Wg_rFacFiltMidAdpv_C);
               /*QAC Warning : Msg(2:0584) --> Wg_rFacFiltMidAdpv_C Could not be
               null here*/
               if (u32LocalDiff <= (uint32)s32LocalDiv)
               {
                  Wg_rRawInctAdpv =
                     (sint16)( ((sint32)u32LocalDiff * Wg_rFacFiltMidAdpv_C)
                             / 32768);
               }
               else
               {
                  Wg_rRawInctAdpv = -32768;
               }
            }
         }
         else
         {
            Wg_rRawInctAdpv = 0;
         }
      }
      else
      {
         s32LocalDiff = (s32LocalDeadZoneValue - Wg_rDbndElmAdpvThdMin_C);
         if (Wg_rFacFiltMidAdpv_C != 0)
         {
            if (Wg_rFacFiltMidAdpv_C > 0)
            {
               s32LocalDiv = (sint32)(-1073741824 / Wg_rFacFiltMidAdpv_C);
               if (s32LocalDiff >= s32LocalDiv)
               {
                  Wg_rRawInctAdpv =
                     (sint16)((s32LocalDiff * Wg_rFacFiltMidAdpv_C) / 32768);
               }
               else
               {
                  Wg_rRawInctAdpv = -32768;
               }
            }
            else
            {
               u32LocalWg_rRawInctAdpv =
                  (uint32)((s32LocalDiff * Wg_rFacFiltMidAdpv_C) / 32768);
               Wg_rRawInctAdpv =
                  (sint16)MATHSRV_udtMIN(u32LocalWg_rRawInctAdpv, 32767);
            }
         }
         else
         {
            Wg_rRawInctAdpv = 0;
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgCmdSp_vidClcAdpv                                         */
/* !Description :  The adaptive part is saturated thanks to minimum and       */
/*                 maximum adjustable thresholds.                             */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Wg_nrSampleTiClcAdpv_C;                                       */
/*  input sint16 Wg_rWgServoUpdElmAdpvIntglCmd;                               */
/*  input sint16 Wg_rWgServoElmAdpvCmdPrev;                                   */
/*  input sint16 Wg_rWgServoElmAdpvCmdThdMin_C;                               */
/*  input sint16 Wg_rWgServoElmAdpvCmdThdMax_C;                               */
/*  output uint8 Wg_ctDownSampleTiClcAdpv;                                    */
/*  output sint16 Wg_rWgServoElmAdpvCmd;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgCmdSp_vidClcAdpv(void)
{
   sint32 s32LocalClampInput;
   sint16 s16LocalWg_rWgServoElmAdpvCmd;


   Wg_ctDownSampleTiClcAdpv = Wg_nrSampleTiClcAdpv_C;
   s32LocalClampInput = (sint32)( Wg_rWgServoUpdElmAdpvIntglCmd
                                + Wg_rWgServoElmAdpvCmdPrev );
   s16LocalWg_rWgServoElmAdpvCmd =
            (sint16)MATHSRV_udtCLAMP( s32LocalClampInput,
                                      Wg_rWgServoElmAdpvCmdThdMin_C,
                                      Wg_rWgServoElmAdpvCmdThdMax_C);
   Wg_rWgServoElmAdpvCmd = s16LocalWg_rWgServoElmAdpvCmd;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgCmdSp_vidClcElm_I                                        */
/* !Description :  The computation of the integral part is preceded by a      */
/*                 detection of saturation; this detection avoids the integral*/
/*                 part from increasing when the valve is next to its thrusts.*/
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TrbAct_bInhICor;                                            */
/*  input sint16 Wg_pSpgFilPresErr;                                           */
/*  input sint16 Wg_rWgCmdSpPrev;                                             */
/*  input sint16 Wg_rWgCmdThdMinSp_C;                                         */
/*  input sint16 Wg_rWgCmdThdMaxSp_C;                                         */
/*  input boolean TrbAct_bInhICor_C;                                          */
/*  input sint16 Wg_rWgServoElmIntglCmdPrev;                                  */
/*  input sint16 Wg_rWgServoUpdElmAdpvIntglCmd;                               */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Wg_nEngBkpt_A[9];                                            */
/*  input uint16 Wg_pSpgFilPresErr_A[9];                                      */
/*  input uint16 Wg_ServoPIDCoeffIntgl_M[9][9];                               */
/*  input sint16 Wg_rWgServoElmIntglCmdMin_C;                                 */
/*  input sint16 Wg_rWgServoElmIntglCmdMax_C;                                 */
/*  input boolean Wg_bEnaApplServoCmd;                                        */
/*  input sint16 Wg_rWgServoElmIntglCmd;                                      */
/*  input boolean TrbAct_bBoostPresClCtlAcv;                                  */
/*  input boolean TrbAct_bInhICorRaw;                                         */
/*  input sint16 WGCMDSP_s16Ext_rCtlIntTestMod;                               */
/*  input boolean WGCMDSP_bBoostPresClCtlAcvPrev;                             */
/*  output boolean TrbAct_bInhICorRaw;                                        */
/*  output sint16 Wg_rWgServoElmIntglCmd;                                     */
/*  output sint16 Wg_rWgServoElmIntglCmdPrev;                                 */
/*  output sint16 WGCMDSP_s16Ext_rCtlIntTestMod;                              */
/*  output sint16 Ext_rCtlIntTestMod;                                         */
/*  output boolean WGCMDSP_bBoostPresClCtlAcvPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgCmdSp_vidClcElm_I(void)
{
   boolean  bLocalTrbAct_bInhICor;
   boolean  bLocalTrbAct_bBoostPresClCtlAcv;
   uint16   u16LocalInterp2d;
   uint16   u16LocalWg_pSpgFilPresErr;
   uint16   u16LocalRegime_moteur;
   uint16   u16LocalCalcParaX;
   uint16   u16LocalCalcParaY;
   sint16   s16LocalExt_rCtlIntTestMod;
   sint16   s16LocalOutputClamp;
   sint32   s32LocalMult;
   sint32   s32LocalinputClamp;


   VEMS_vidGET(TrbAct_bInhICor, bLocalTrbAct_bInhICor);
   if (  (  (Wg_pSpgFilPresErr <= 0)
         && (Wg_rWgCmdSpPrev   <= Wg_rWgCmdThdMinSp_C))
      || (  (Wg_pSpgFilPresErr >= 0)
         && (Wg_rWgCmdSpPrev   >= Wg_rWgCmdThdMaxSp_C))
      || (  (bLocalTrbAct_bInhICor != 0)
         && (TrbAct_bInhICor_C != 0)))
   {
      s32LocalinputClamp =
         (sint32)(Wg_rWgServoElmIntglCmdPrev - Wg_rWgServoUpdElmAdpvIntglCmd);
      TrbAct_bInhICorRaw = 1;
   }
   else
   {
      TrbAct_bInhICorRaw = 0;
      VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
      u16LocalWg_pSpgFilPresErr = (uint16)(Wg_pSpgFilPresErr + 32768);
      u16LocalCalcParaX =
         MATHSRV_u16CalcParaIncAryU16(Wg_nEngBkpt_A,
                                      u16LocalRegime_moteur,
                                      9);
      u16LocalCalcParaY =
         MATHSRV_u16CalcParaIncAryU16(Wg_pSpgFilPresErr_A,
                                      u16LocalWg_pSpgFilPresErr,
                                      9);
      u16LocalInterp2d =
         MATHSRV_u16Interp2d(&Wg_ServoPIDCoeffIntgl_M[0][0],
                            u16LocalCalcParaX,
                            u16LocalCalcParaY,
                            9);
      if (Wg_pSpgFilPresErr > 0)
      {
         s32LocalMult =
            (sint32)(((Wg_pSpgFilPresErr * u16LocalInterp2d) + 6250) / 12500);
      }
      else
      {
         s32LocalMult =
            (sint32)(((Wg_pSpgFilPresErr * u16LocalInterp2d) - 6250) / 12500);
      }
      s32LocalinputClamp =
         ( (s32LocalMult - (sint32)Wg_rWgServoUpdElmAdpvIntglCmd)
         + ((sint32)Wg_rWgServoElmIntglCmdPrev));
   }
   s16LocalOutputClamp = (sint16)MATHSRV_udtCLAMP(s32LocalinputClamp,
                                                  Wg_rWgServoElmIntglCmdMin_C,
                                                  Wg_rWgServoElmIntglCmdMax_C );
   if (Wg_bEnaApplServoCmd != 0)
   {
      Wg_rWgServoElmIntglCmd = s16LocalOutputClamp;
      Wg_rWgServoElmIntglCmdPrev = Wg_rWgServoElmIntglCmd;
   }
   else
   {
      Wg_rWgServoElmIntglCmd = 0;
      Wg_rWgServoElmIntglCmdPrev = 0;
   }
   VEMS_vidGET(TrbAct_bBoostPresClCtlAcv, bLocalTrbAct_bBoostPresClCtlAcv);
   if (  (bLocalTrbAct_bBoostPresClCtlAcv != 0)
      && (TrbAct_bInhICorRaw != 0))
   {
      WGCMDSP_s16Ext_rCtlIntTestMod =
         (sint16)MATHSRV_udtMAX(WGCMDSP_s16Ext_rCtlIntTestMod, -32767);
   }
   else
   {
      WGCMDSP_s16Ext_rCtlIntTestMod =
         (sint16)MATHSRV_udtMAX(Wg_rWgServoElmIntglCmd, -32767);
   }
   if (  (bLocalTrbAct_bBoostPresClCtlAcv != 0)
      && (WGCMDSP_bBoostPresClCtlAcvPrev == 0))
   {
      s16LocalExt_rCtlIntTestMod = 0;
   }
   else
   {
      s16LocalExt_rCtlIntTestMod = WGCMDSP_s16Ext_rCtlIntTestMod;
   }
   VEMS_vidSET(Ext_rCtlIntTestMod, s16LocalExt_rCtlIntTestMod);
   WGCMDSP_bBoostPresClCtlAcvPrev = bLocalTrbAct_bBoostPresClCtlAcv;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgCmdSp_vidClcElm_D                                        */
/* !Description :  The main aim of the derivative part is preventing the      */
/*                 supercharging pressure setpoint from overshooting. If the  */
/*                 first derivative of the raw feedback error is too          */
/*                 significant a correction is computed.                      */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Wg_pSpgPresErr;                                              */
/*  input sint16 Wg_pSpgPresErrPrev;                                          */
/*  input sint16 Wg_pSpgdervPresErrThdMin_C;                                  */
/*  input sint16 Wg_pSpgdervPresErrThdMax_C;                                  */
/*  input uint16 Wg_facFilSpgdervPresErr_C;                                   */
/*  input sint32 Wg_pDervFiltSpgPresErrMem;                                   */
/*  input uint16 Regime_moteur;                                               */
/*  input sint16 Wg_pSpgFilPresErr;                                           */
/*  input uint16 Wg_nEngBkpt_A[9];                                            */
/*  input uint16 Wg_pSpgFilPresErr_A[9];                                      */
/*  input uint16 Wg_ServoPIDCoeffDftl_M[9][9];                                */
/*  input boolean Wg_bEnaApplServoCmd;                                        */
/*  input sint16 Wg_pSpgHiThdPresErr_C;                                       */
/*  input sint16 Wg_pSpgLoThdPresErr_C;                                       */
/*  input sint16 Wg_pDervFiltSpgPresErr;                                      */
/*  output sint16 Wg_pDervFiltSpgPresErr;                                     */
/*  output sint16 Wg_rWgServoElmDftlCmd;                                      */
/*  output sint16 Wg_pSpgPresErrPrev;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgCmdSp_vidClcElm_D(void)
{
   uint16 u16LocalRegime_moteur;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalWg_pSpgFilPresErr;
   uint16 u16LocalInterp2d;
   sint16 s16LocalClampValue;
   uint32 u32LocalCalc;
   uint32 u32LocalResult;
   sint32 s32LocalClampValue;
   sint32 s32LocalMult;


   s32LocalClampValue = (sint32)(Wg_pSpgPresErr - Wg_pSpgPresErrPrev);
   s16LocalClampValue  = (sint16)MATHSRV_udtCLAMP(s32LocalClampValue,
                                                  Wg_pSpgdervPresErrThdMin_C,
                                                  Wg_pSpgdervPresErrThdMax_C);
   Wg_pDervFiltSpgPresErr =
      MATHSRV_s16FirstOrderFilterGu16(Wg_facFilSpgdervPresErr_C,
                                      &Wg_pDervFiltSpgPresErrMem,
                                      s16LocalClampValue);

   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   u16LocalWg_pSpgFilPresErr = (uint16)(Wg_pSpgFilPresErr + 32768);
   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(Wg_nEngBkpt_A,
                                   u16LocalRegime_moteur,
                                   9);
   u16LocalCalcParaY =
      MATHSRV_u16CalcParaIncAryU16(Wg_pSpgFilPresErr_A,
                                   u16LocalWg_pSpgFilPresErr,
                                   9);
   u16LocalInterp2d =
      MATHSRV_u16Interp2d(&Wg_ServoPIDCoeffDftl_M[0][0],
                          u16LocalCalcParaX,
                          u16LocalCalcParaY,
                          9);
   if (  (Wg_bEnaApplServoCmd != 0)
      && (Wg_pSpgPresErr <= Wg_pSpgHiThdPresErr_C)
      && (Wg_pSpgPresErr >= Wg_pSpgLoThdPresErr_C))
   {

      s32LocalMult = (sint32)(Wg_pDervFiltSpgPresErr * u16LocalInterp2d);
      if (s32LocalMult > 0)
      {
         u32LocalResult = (uint32)((s32LocalMult * 2) / 625);
         Wg_rWgServoElmDftlCmd = (sint16)MATHSRV_udtMIN(u32LocalResult, 32767);
      }
      else
      {
         u32LocalCalc = (uint32)MATHSRV_udtABS(s32LocalMult);
         u32LocalCalc = (u32LocalCalc * 2) / 625;
         if (u32LocalCalc > 32768)
         {
            Wg_rWgServoElmDftlCmd = -32768;
         }
         else
         {
            Wg_rWgServoElmDftlCmd = (sint16)((-1) * u32LocalCalc);
         }
      }
   }
   else
   {
      Wg_rWgServoElmDftlCmd = 0;
   }
   Wg_pSpgPresErrPrev = Wg_pSpgPresErr;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgCmdSp_vidSumElmPIDA                                      */
/* !Description :  The final PWM command is issued from the boost pressure    */
/*                 regulation.                                                */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Wg_bEnaApplOlpCmd;                                          */
/*  input sint16 Wg_rWgOplCmd;                                                */
/*  input sint16 Wg_rWgServoElmAdpvCmd;                                       */
/*  input sint16 Wg_rWgServoElmPropCmd;                                       */
/*  input sint16 Wg_rWgServoElmIntglCmd;                                      */
/*  input sint16 Wg_rWgServoElmDftlCmd;                                       */
/*  input sint16 Wg_rWgCmdThdMinSp_C;                                         */
/*  input sint16 Wg_rWgCmdThdMaxSp_C;                                         */
/*  output sint16 Wg_rWgCmdSpPrev;                                            */
/*  output sint16 Wg_rWgCmdSp;                                                */
/*  output sint16 Ext_rCtlTestMod;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgCmdSp_vidSumElmPIDA(void)
{
   sint16  s16LocalClampValue;
   sint32  s32LocalClampValue;


   if (Wg_bEnaApplOlpCmd != 0)
   {

      s32LocalClampValue = Wg_rWgOplCmd
                         + Wg_rWgServoElmAdpvCmd
                         + Wg_rWgServoElmPropCmd
                         + Wg_rWgServoElmIntglCmd
                         + Wg_rWgServoElmDftlCmd;
      s16LocalClampValue = (sint16)MATHSRV_udtCLAMP(s32LocalClampValue,
                                                    Wg_rWgCmdThdMinSp_C,
                                                    Wg_rWgCmdThdMaxSp_C );

   }
   else
   {
      s16LocalClampValue = Wg_rWgCmdThdMinSp_C;
   }
   Wg_rWgCmdSpPrev = s16LocalClampValue;
   VEMS_vidSET(Wg_rWgCmdSp, s16LocalClampValue);
   s16LocalClampValue = (sint16)MATHSRV_udtMAX(s16LocalClampValue, -32767);
   VEMS_vidSET(Ext_rCtlTestMod, s16LocalClampValue);
}
/*------------------------------- end of file --------------------------------*/