/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : WGCCMD                                                  */
/* !Description     : WGCCMD Component                                        */
/*                                                                            */
/* !Module          : WGCCMD                                                  */
/* !Description     : WASTEGATE COMMAND AND DIAGNOSIS                         */
/*                                                                            */
/* !File            : WGCCMD_FCT1.C                                           */
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
/*   1 / WgcCmd_vidInitOutput                                                 */
/*   2 / WgcCmd_vidWgcTreatment                                               */
/*   3 / WgcCmd_vidBat_Volt_Filtering                                         */
/*   4 / WgcCmd_vidP_Trb_PwrSup_calcul                                        */
/*   5 / WgcCmd_vidRequest_CorrecLimit                                        */
/*   6 / WgcCmd_vidDuty_cycle_conversion                                      */
/*   7 / WgcCmd_vidWgcCmdApplication                                          */
/*   8 / WgcCmd_vidDiagnostic                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6851415 / 01                                        */
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
#include "WGCCMD.h"
#include "WGCCMD_L.h"
#include "WGCCMD_IM.h"
#include "GDGAR.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgcCmd_vidInitOutput                                       */
/* !Description :  Init function                                              */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_uBattMes;                                                */
/*  output sint16 WGCCMD_s16Ext_uBattMesPrev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgcCmd_vidInitOutput(void)
{
   sint16   s16LocalExt_uBattMes;


   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   WGCCMD_s16Ext_uBattMesPrev = (sint16)MATHSRV_udtCLAMP(s16LocalExt_uBattMes,
                                                         0,
                                                         3200);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgcCmd_vidWgcTreatment                                     */
/* !Description :  The main function of the bloc is the processing of the     */
/*                 wastegate control signal (PWM signal frequency and duty    */
/*                 cycle).                                                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WgcCmd_vidBat_Volt_Filtering();                          */
/*  extf argret void WgcCmd_vidP_Trb_PwrSup_calcul();                         */
/*  extf argret void WgcCmd_vidRequest_CorrecLimit();                         */
/*  extf argret void WgcCmd_vidDuty_cycle_conversion();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgcCmd_vidWgcTreatment(void)
{
   WgcCmd_vidBat_Volt_Filtering();
   WgcCmd_vidP_Trb_PwrSup_calcul();
   WgcCmd_vidRequest_CorrecLimit();
   WgcCmd_vidDuty_cycle_conversion();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgcCmd_vidBat_Volt_Filtering                               */
/* !Description :  The battery voltage is filtered on the two last values     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_10_01186_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_uBattMes;                                                */
/*  input sint16 WGCCMD_s16Ext_uBattMesPrev;                                  */
/*  output uint8 Ext_uBattMes_Filt;                                           */
/*  output sint16 WGCCMD_s16Ext_uBattMesPrev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgcCmd_vidBat_Volt_Filtering(void)
{
   sint16 s16LocalExt_uBattMes;
   sint32 s32LocalSum;


   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   s32LocalSum =
      (sint32)((s16LocalExt_uBattMes + WGCCMD_s16Ext_uBattMesPrev ) + 10) / 20;
   Ext_uBattMes_Filt = (uint8)MATHSRV_udtCLAMP(s32LocalSum, 0, 200);
   WGCCMD_s16Ext_uBattMesPrev = (sint16)MATHSRV_udtCLAMP(s16LocalExt_uBattMes,
                                                        0,
                                                        3200);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgcCmd_vidP_Trb_PwrSup_calcul                              */
/* !Description :  According to the chosen calibrations the power supply      */
/*                 received by the wastegate ( Ext_uTrbAct ) will be : -      */
/*                 Filtered in voltage -  Filtered in current -  Filtered in  */
/*                 voltage and current -  Filtered on the two last values of  */
/*                 the battery voltage measured                               */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_10_01186_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_TrbAct_rCtl_CurMes;                                       */
/*  input boolean Ext_bAcv_Trb_rCtlBattCor_C;                                 */
/*  input boolean Ext_bAcv_Trb_rCtlCurCor_C;                                  */
/*  input uint16 Ext_resLoSideTrb_C;                                          */
/*  input uint8 Ext_uBattMes_Filt;                                            */
/*  input uint8 Ext_uBattMes_Nom;                                             */
/*  output uint16 Ext_uTrbAct;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgcCmd_vidP_Trb_PwrSup_calcul(void)
{
   uint8   u8LocalExt_TrbAct_rCtl_CurMes;
   sint32  s32LocalExt_uTrbAct;


   VEMS_vidGET(Ext_TrbAct_rCtl_CurMes, u8LocalExt_TrbAct_rCtl_CurMes);
   if( Ext_bAcv_Trb_rCtlBattCor_C != 0)
   {
      if( Ext_bAcv_Trb_rCtlCurCor_C != 0)
      {
         s32LocalExt_uTrbAct = ( ( Ext_uBattMes_Filt
                                 - ( u8LocalExt_TrbAct_rCtl_CurMes
                                   * Ext_resLoSideTrb_C))
                               * 10);
         Ext_uTrbAct = (uint16)MATHSRV_udtMAX(s32LocalExt_uTrbAct, 0);
      }
      else
      {
         Ext_uTrbAct = (uint16)(Ext_uBattMes_Filt * 10);
      }
   }
   else
   {
      s32LocalExt_uTrbAct = ( ( Ext_uBattMes_Nom
                              - ( u8LocalExt_TrbAct_rCtl_CurMes
                                * Ext_resLoSideTrb_C))
                            * 10);
      Ext_uTrbAct = (uint16)MATHSRV_udtMAX(s32LocalExt_uTrbAct, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgcCmd_vidRequest_CorrecLimit                              */
/* !Description :  According to the chosen calibrations, the duty cycle signal*/
/*                 of the wastegate actuator is corrected or not, and bounded */
/*                 between 0 and 100 percent.                                 */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_10_01186_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Wg_rAcvWgcCmdAppld;                                          */
/*  input boolean Ext_bAcv_Trb_rCtlBattCor_C;                                 */
/*  input boolean Ext_bAcv_Trb_rCtlCurCor_C;                                  */
/*  input uint16 Ext_uTrbAct;                                                 */
/*  input uint8 Ext_uBattMes_Nom;                                             */
/*  input sint16 Ext_TrbAct_rCtlCor;                                          */
/*  output sint16 Ext_TrbAct_rCtlCor;                                         */
/*  output uint16 Ext_TrbAct_rCtlLim;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgcCmd_vidRequest_CorrecLimit(void)
{
   uint16 u16LocalWg_rAcvWgcCmdAppld;
   uint32 u32LocalExt_TrbAct_rCtlCor;
   uint32 u32LocalCalc;
   sint32 s32LocalLim;


   VEMS_vidGET(Wg_rAcvWgcCmdAppld, u16LocalWg_rAcvWgcCmdAppld);
   if (  (Ext_bAcv_Trb_rCtlBattCor_C != 0)
      || (Ext_bAcv_Trb_rCtlCurCor_C != 0))
   {
      if (Ext_uTrbAct != 0)
      {
         u32LocalCalc =
            (uint32)((u16LocalWg_rAcvWgcCmdAppld * Ext_uBattMes_Nom * 5) / 2);
         u32LocalExt_TrbAct_rCtlCor = u32LocalCalc / Ext_uTrbAct;
      }
      else
      {
         u32LocalExt_TrbAct_rCtlCor = 0;
      }
   }
   else
   {
      u32LocalExt_TrbAct_rCtlCor = (uint32)(u16LocalWg_rAcvWgcCmdAppld / 4);
   }
   Ext_TrbAct_rCtlCor =
      (sint16)MATHSRV_udtMIN(u32LocalExt_TrbAct_rCtlCor, 16384);
   s32LocalLim = (sint32)(Ext_TrbAct_rCtlCor * 4);
   Ext_TrbAct_rCtlLim =
      (uint16)MATHSRV_udtMIN(s32LocalLim, 32768);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgcCmd_vidDuty_cycle_conversion                            */
/* !Description :  The duty cycle signal of the wastegate actuator            */
/*                 (Ext_TrbAct_rCtl) is clamped between these tow calibrations*/
/*                 (Minimum duty cycle control and Maximum duty cycle control)*/
/* !Number      :  FCT1.6                                                     */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_10_01186_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 WgcCmd_TrbAct_DrvMax_C;                                      */
/*  input uint16 WgcCmd_TrbAct_DrvMin_C;                                      */
/*  input uint16 Ext_TrbAct_rCtlLim;                                          */
/*  output uint16 Ext_TrbAct_rCtl;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgcCmd_vidDuty_cycle_conversion(void)
{
   uint32 u32LocalCalc;
   uint32 u32LocalProd;
   uint32 u32LocalDiffABS;
   sint32 s32LocalDiff;
   sint32 s32LocalResult;


   s32LocalDiff = (sint32)(WgcCmd_TrbAct_DrvMax_C - WgcCmd_TrbAct_DrvMin_C);
   u32LocalDiffABS = (uint32)MATHSRV_udtABS(s32LocalDiff);
   u32LocalProd = ((u32LocalDiffABS * Ext_TrbAct_rCtlLim) / 1000);
   u32LocalCalc = (uint32)(((WgcCmd_TrbAct_DrvMin_C * 32768) + 500) / 1000);

   if (s32LocalDiff < 0)
   {
      s32LocalResult = (sint32)(u32LocalCalc - u32LocalProd);
   }
   else
   {
      s32LocalResult = (sint32)(u32LocalCalc + u32LocalProd);
   }
   Ext_TrbAct_rCtl = (uint16)MATHSRV_udtCLAMP(s32LocalResult, 0, 32768);
   /*QAC Warning : no impact, code is entirely covered*/
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgcCmd_vidWgcCmdApplication                                */
/* !Description :  According to the chosen calibrations the wastegate actuator*/
/*                 is commanded on normal or bench mode. The wastegate signal */
/*                 command (PWM frequency and duty cycle) is transmitted      */
/*                 through the basic layer via the PWMHAL service.            */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_10_01186_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 WgcCmd_nEng_A[24];                                           */
/*  input uint16 WgcCmd_frqTrbAct_rCtl_T[24];                                 */
/*  input uint16 Ext_TrbAct_rCtl;                                             */
/*  output uint16 WgcCmd_frqTrbAct_rCtl;                                      */
/*  output uint16 WgCmd_DutyCycTrbAct_rCtl;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgcCmd_vidWgcCmdApplication(void)
{
   uint8  u8LocalIndex1d;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalWgcCmd_frqTrbAct_rCtl;
   uint16 u16LocalWgCmd_DutyCycTrbAct_rCtl;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(WgcCmd_nEng_A,
                                                    u16LocalExt_nEng,
                                                    24);
   u8LocalIndex1d = (uint8)(u16LocalCalcParaX / 256);
   u16LocalWgcCmd_frqTrbAct_rCtl = WgcCmd_frqTrbAct_rCtl_T[u8LocalIndex1d];
   VEMS_vidSET(WgcCmd_frqTrbAct_rCtl, u16LocalWgcCmd_frqTrbAct_rCtl);

   u16LocalWgCmd_DutyCycTrbAct_rCtl = (uint16)MATHSRV_udtMIN(Ext_TrbAct_rCtl,
                                                             32768);
   VEMS_vidSET(WgCmd_DutyCycTrbAct_rCtl, u16LocalWgCmd_DutyCycTrbAct_rCtl);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgcCmd_vidDiagnostic                                       */
/* !Description :  Diagnostic Function for wastegate command                  */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_10_01186_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean Dft_oc_WgcCmd;                                              */
/*  input boolean Dft_scg_WgcCmd;                                             */
/*  input boolean Dft_scp_WgcCmd;                                             */
/*  input boolean Dena_oc_WgcCmd;                                             */
/*  input boolean Dena_scg_WgcCmd;                                            */
/*  input boolean Dena_scp_WgcCmd;                                            */
/*  output boolean Wg_bDgoLo_WgcCmd;                                          */
/*  output boolean Wg_bDgoHi_WgcCmd;                                          */
/*  output boolean Wg_bMonRunLo_WgcCmd;                                       */
/*  output boolean Wg_bMonRunHi_WgcCmd;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgcCmd_vidDiagnostic(void)
{
   boolean          bLocalInhInWgcCmd;
   boolean          bLocalDft_oc_WgcCmd;
   boolean          bLocalDft_scg_WgcCmd;
   boolean          bLocalDft_scp_WgcCmd;
   boolean          bLocalDena_oc_WgcCmd;
   boolean          bLocalDena_scg_WgcCmd;
   boolean          bLocalDena_scp_WgcCmd;


   VEMS_vidGET(Dft_oc_WgcCmd, bLocalDft_oc_WgcCmd);
   VEMS_vidGET(Dft_scg_WgcCmd, bLocalDft_scg_WgcCmd);
   VEMS_vidGET(Dft_scp_WgcCmd, bLocalDft_scp_WgcCmd);
   VEMS_vidGET(Dena_oc_WgcCmd, bLocalDena_oc_WgcCmd);
   VEMS_vidGET(Dena_scg_WgcCmd, bLocalDena_scg_WgcCmd);
   VEMS_vidGET(Dena_scp_WgcCmd, bLocalDena_scp_WgcCmd);
   bLocalInhInWgcCmd = GDGAR_bGetFRM(FRM_FRM_INHINWGCCMD);

   if (  (bLocalDft_oc_WgcCmd != 0)
      || (bLocalDft_scg_WgcCmd != 0))
   {
      Wg_bDgoLo_WgcCmd = 1;
   }
   else
   {
      Wg_bDgoLo_WgcCmd = 0;
   }

   Wg_bDgoHi_WgcCmd = bLocalDft_scp_WgcCmd;

   if (bLocalInhInWgcCmd != 0)
   {
      Wg_bMonRunLo_WgcCmd = 0;
      Wg_bMonRunHi_WgcCmd = 0;
   }
   else
   {
      if (  (bLocalDena_oc_WgcCmd != 0)
         || (bLocalDena_scg_WgcCmd != 0))
      {
         Wg_bMonRunLo_WgcCmd = 1;
      }
      else
      {
         Wg_bMonRunLo_WgcCmd = 0;
      }

      Wg_bMonRunHi_WgcCmd = bLocalDena_scp_WgcCmd;
   }
}
/*------------------------------ End of file ---------------------------------*/