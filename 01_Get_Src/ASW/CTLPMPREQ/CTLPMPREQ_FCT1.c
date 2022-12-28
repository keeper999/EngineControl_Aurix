/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CTLPMPREQ                                               */
/* !Description     : CTLPMPREQ component.                                    */
/*                                                                            */
/* !Module          : CTLPMPREQ                                               */
/* !Description     : OIL PUMP SOLENOID VALVE COMMAND AND DIAGNOSIS           */
/*                                                                            */
/* !File            : CTLPMPREQ_FCT1.C                                        */
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
/*   1 / CTLPMPREQ_vidInit                                                    */
/*   2 / CTLPMPREQ_vidInitOutput                                              */
/*   3 / CTLPMPREQ_vidCmdAndDiagEnable                                        */
/*   4 / CTLPMPREQ_vidCmd                                                     */
/*   5 / CTLPMPREQ_vidCmdAbs                                                  */
/*   6 / CTLPMPREQ_vidCmdCor                                                  */
/*   7 / CTLPMPREQ_vidCmdApp                                                  */
/*   8 / CTLPMPREQ_vidDrvCur                                                  */
/*   9 / CTLPMPREQ_vidDiag                                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_6851410 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OIL/CTLPMPREQ/CTLPMPREQ_FCT1.c_v$*/
/* $Revision::   1.7      $$Author::   mbenfrad       $$Date::   20 Oct 2014 $*/
/* $Author::   mbenfrad                               $$Date::   20 Oct 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customers                                  */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "CTLPMPREQ.h"
#include "CTLPMPREQ_L.h"
#include "CTLPMPREQ_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTLPMPREQ_vidInit                                          */
/* !Description :  The outputs variables are initialized on ECU reset.        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Ext_iMesOilPmp;                                             */
/*  output uint16 OilSysHw_CtlPmpReq;                                         */
/*  output uint16 Oil_rPmpCmdAppl;                                            */
/*  output uint16 OilSysHw_frqPmpCmd;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTLPMPREQ_vidInit(void)
{
   VEMS_vidSET(Ext_iMesOilPmp, 0);
   VEMS_vidSET(OilSysHw_CtlPmpReq, 0);
   VEMS_vidSET(Oil_rPmpCmdAppl, 0);
   VEMS_vidSET(OilSysHw_frqPmpCmd, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTLPMPREQ_vidInitOutput                                    */
/* !Description :  This function initializes the internal data of the module. */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_uBattMes;                                                */
/*  output sint16 CTLPMPREQ_s16ExtUBattMesPrev;                               */
/*  output uint16 Ext_iMesOilPmp_Prev;                                        */
/*  output uint32 CTLPMPREQ_u32ExtIMesOilPmpMEM;                              */
/*  output boolean CTLPMPREQ_bHysteresis1Output;                              */
/*  output boolean CTLPMPREQ_bHysteresis2Output;                              */
/*  output boolean CTLPMPREQ_bHysteresis3Output;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTLPMPREQ_vidInitOutput(void)
{
   sint16 s16LocalExt_uBattMes;


   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   CTLPMPREQ_s16ExtUBattMesPrev = (sint16)MATHSRV_udtCLAMP(s16LocalExt_uBattMes,
                                                           0,
                                                           3200);

   Ext_iMesOilPmp_Prev = 0;
   CTLPMPREQ_u32ExtIMesOilPmpMEM = 0;

   CTLPMPREQ_bHysteresis1Output = 0;
   CTLPMPREQ_bHysteresis2Output = 0;
   CTLPMPREQ_bHysteresis3Output = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTLPMPREQ_vidCmdAndDiagEnable                              */
/* !Description :  The stategy consists of the two major functions: 1.        */
/*                 Calculation of the oil pump solenoid valve controlling, 2. */
/*                 Oil pump solenoid diagnosis. Command and diagnosis could be*/
/*                 inhibited using the boolean "Ctrl_bOilPmpCmd".             */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CTLPMPREQ_vidCmd();                                      */
/*  extf argret void CTLPMPREQ_vidDiag();                                     */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input boolean Ctrl_bOilPmpCmd;                                            */
/*  input boolean OilSysHw_bDgoOc_CtlPmpReq;                                  */
/*  input boolean OilSysHw_bMonRunOc_CtlPmpReq;                               */
/*  input boolean OilSysHw_bDgoScg_CtlPmpReq;                                 */
/*  input boolean OilSysHw_bMonRunScg_CtlPmpReq;                              */
/*  input boolean OilSysHw_bDgoScp_CtlPmpReq;                                 */
/*  input boolean OilSysHw_bMonRunScp_CtlPmpReq;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTLPMPREQ_vidCmdAndDiagEnable(void)
{
   boolean bLocalCtrl_bOilPmpCmd;


   VEMS_vidGET(Ctrl_bOilPmpCmd,bLocalCtrl_bOilPmpCmd);
   if (bLocalCtrl_bOilPmpCmd != 0)
   {
      CTLPMPREQ_vidCmd();
      CTLPMPREQ_vidDiag();
      GDGAR_vidGdu(GD_DFT_OC_CTLPMPREQ,
                   OilSysHw_bDgoOc_CtlPmpReq,
                   OilSysHw_bMonRunOc_CtlPmpReq,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCG_CTLPMPREQ,
                   OilSysHw_bDgoScg_CtlPmpReq,
                   OilSysHw_bMonRunScg_CtlPmpReq,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCP_CTLPMPREQ,
                   OilSysHw_bDgoScp_CtlPmpReq,
                   OilSysHw_bMonRunScp_CtlPmpReq,
                   DIAG_DISPO);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTLPMPREQ_vidCmd                                           */
/* !Description :  Controlling the solenoid valve consists of: 1. Absolute    */
/*                 value of the setpoint and filtering the battery voltage, 2.*/
/*                 Correction of the duty cycle and limitation between 0 and  */
/*                 100pc, 3.Sending the duty cycle to BSW, 4. Filtering the   */
/*                 current in the solenoid.                                   */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CTLPMPREQ_vidCmdAbs();                                   */
/*  extf argret void CTLPMPREQ_vidCmdCor();                                   */
/*  extf argret void CTLPMPREQ_vidCmdApp();                                   */
/*  extf argret void CTLPMPREQ_vidDrvCur();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTLPMPREQ_vidCmd(void)
{
   CTLPMPREQ_vidCmdAbs();
   CTLPMPREQ_vidCmdCor();
   CTLPMPREQ_vidCmdApp();
   CTLPMPREQ_vidDrvCur();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTLPMPREQ_vidCmdAbs                                        */
/* !Description :  The main function of this block is obtaining the absolute  */
/*                 value of application setpoint and filtering the battery    */
/*                 voltage.                                                   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 OilSys_rCtlPmpReq;                                           */
/*  input sint16 Ext_uBattMes;                                                */
/*  input sint16 CTLPMPREQ_s16ExtUBattMesPrev;                                */
/*  output uint16 OilSys_CtlPmpReq_Abs;                                       */
/*  output uint8 Ext_uBattMes_Fil;                                            */
/*  output sint16 CTLPMPREQ_s16ExtUBattMesPrev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTLPMPREQ_vidCmdAbs(void)
{
   uint16 u16LocalOilSys_rCtlPmpReq;
   sint16 s16LocalExt_uBattMes;
   sint32 s32LocalExt_uBattMes_SUM;


   VEMS_vidGET(OilSys_rCtlPmpReq, u16LocalOilSys_rCtlPmpReq);
   OilSys_CtlPmpReq_Abs = (uint16)MATHSRV_udtMIN(u16LocalOilSys_rCtlPmpReq,
                                                 1000);

   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   s32LocalExt_uBattMes_SUM = (sint32)( s16LocalExt_uBattMes
                                      + CTLPMPREQ_s16ExtUBattMesPrev);
   s32LocalExt_uBattMes_SUM = (s32LocalExt_uBattMes_SUM + 10) / 20;
   Ext_uBattMes_Fil = (uint8)MATHSRV_udtCLAMP(s32LocalExt_uBattMes_SUM, 0, 200);

   CTLPMPREQ_s16ExtUBattMesPrev = (sint16)MATHSRV_udtCLAMP(s16LocalExt_uBattMes,
                                                           0,
                                                           3200);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTLPMPREQ_vidCmdCor                                        */
/* !Description :  The duty cycle of oil pump solenoid valve is corrected and */
/*                 bounded between 0 and 100 per cent.                        */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bAcv_OilPmp_rCtlBattCor_C;                              */
/*  input uint8 Ext_uBattMes_Fil;                                             */
/*  input uint16 OilSys_CtlPmpReq_Abs;                                        */
/*  input uint8 Ext_uBattMes_Nom;                                             */
/*  input uint16 OilSysHw_CtlPmpReq_Cor;                                      */
/*  input sint16 Ext_tOil;                                                    */
/*  input uint16 OilSysHw_tOil_frqPmpCmd_A[5];                                */
/*  input uint16 OilSysHw_frqBaseFrqPmpCmd_T[5];                              */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input uint16 OilSysHw_frqBaseFrqPmpCmd;                                   */
/*  input uint16 OilSysHw_frqInjFreq;                                         */
/*  input uint8 OilSysHw_noFacFrqCmdOilPmp;                                   */
/*  input uint16 OilSysHw_frqCmdFreqZone;                                     */
/*  input uint16 OilSysHw_frqThdDZone1_C;                                     */
/*  input uint16 OilSysHw_frqOfsThdDZone1_C;                                  */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 OilSysHw_nEngOfsThdZone1_C;                                  */
/*  input uint16 OilSysHw_nEngThdZone1_C;                                     */
/*  input uint16 OilSysHw_frqThdDZone2_C;                                     */
/*  input uint16 OilSysHw_frqOfsThdDZone2_C;                                  */
/*  input boolean CTLPMPREQ_bHysteresis1Output;                               */
/*  input boolean CTLPMPREQ_bHysteresis2Output;                               */
/*  input uint16 OilSysHw_frqRetDZone1_C;                                     */
/*  input boolean CTLPMPREQ_bHysteresis3Output;                               */
/*  input uint16 OilSysHw_frqRetDZone2_C;                                     */
/*  output uint16 OilSysHw_CtlPmpReq_Cor;                                     */
/*  output uint16 OilSysHw_CtlPmpReq_Lim;                                     */
/*  output uint16 OilSysHw_frqBaseFrqPmpCmd;                                  */
/*  output uint16 OilSysHw_frqInjFreq;                                        */
/*  output uint8 OilSysHw_noFacFrqCmdOilPmp;                                  */
/*  output uint16 OilSysHw_frqCmdFreqZone;                                    */
/*  output boolean CTLPMPREQ_bHysteresis2Output;                              */
/*  output boolean CTLPMPREQ_bHysteresis1Output;                              */
/*  output boolean CTLPMPREQ_bHysteresis3Output;                              */
/*  output uint16 OilSysHw_frqPmpCmdRaw;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTLPMPREQ_vidCmdCor(void)
{
   uint8  u8LocalROUNDING;
   uint8  u8LocalExt_tiTDC;
   uint16 u16LocalExt_tOil;
   uint16 u16LocalPara;
   uint16 u16LocalOilSysHwnoFcFrqCmdOilPmp;
   uint16 u16LocalExt_nEng;
   uint32 u32LocalBattVoltReq;
   uint32 u32LocalCtlPmpReq_PWM;
   uint32 u32LocalCalc;
   uint32 u32LocalSomcal;
   uint32 u32LocalMul;
   sint16 s16LocalExt_tOil;
   sint32 s32LocalExt_tOil;
   sint32 s32LocalDiffcal;
   sint32 s32LocalDiffcal3;
   sint32 s32LocalDiffHys2;
   sint32 s32LocalDiffHys3;
   sint32 s32LocalDiff;


   if (Ext_bAcv_OilPmp_rCtlBattCor_C != 0)
   {
      if (Ext_uBattMes_Fil != 0)
      {
         u32LocalBattVoltReq = (uint32)( OilSys_CtlPmpReq_Abs
                                       * Ext_uBattMes_Nom);
         u8LocalROUNDING = (uint8)(Ext_uBattMes_Fil / 2);
         u32LocalCtlPmpReq_PWM = ( ( u32LocalBattVoltReq
                                   + u8LocalROUNDING)
                                 / Ext_uBattMes_Fil);
         OilSysHw_CtlPmpReq_Cor = (uint16)MATHSRV_udtMIN(u32LocalCtlPmpReq_PWM,
                                                         1000);
      }
      else
      {
         OilSysHw_CtlPmpReq_Cor = 0;
      }
   }
   else
   {
      OilSysHw_CtlPmpReq_Cor = (uint16)MATHSRV_udtMIN(OilSys_CtlPmpReq_Abs,
                                                      1000);
   }
   OilSysHw_CtlPmpReq_Lim = OilSysHw_CtlPmpReq_Cor;

   /* OilSysHw_frqBaseFrqPmpCmd */
   VEMS_vidGET(Ext_tOil, s16LocalExt_tOil);
   s32LocalExt_tOil = (sint32)(s16LocalExt_tOil + 200);
   u16LocalExt_tOil = (uint16)MATHSRV_udtMAX(s32LocalExt_tOil, 0);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU16(OilSysHw_tOil_frqPmpCmd_A,
                                               u16LocalExt_tOil,
                                               5);
   OilSysHw_frqBaseFrqPmpCmd =
      MATHSRV_u16Interp1d(OilSysHw_frqBaseFrqPmpCmd_T, u16LocalPara);

   /* OilSysHw_frqInjFreq */
   VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
   if (u8LocalExt_tiTDC != 0)
   {
      OilSysHw_frqInjFreq = (uint16)(20000 / u8LocalExt_tiTDC);
   }
   else
   {
      OilSysHw_frqInjFreq = 1;
   }

   /* OilSysHw_noFacFrqCmdOilPmp */
   u16LocalOilSysHwnoFcFrqCmdOilPmp = (uint16)( OilSysHw_frqBaseFrqPmpCmd
                                              / OilSysHw_frqInjFreq);
   OilSysHw_noFacFrqCmdOilPmp =
      (uint8)MATHSRV_udtCLAMP(u16LocalOilSysHwnoFcFrqCmdOilPmp, 1, 100);

   /* OilSysHw_frqCmdFreqZone */
   u32LocalCalc = (uint32)(OilSysHw_frqInjFreq * OilSysHw_noFacFrqCmdOilPmp);
   s32LocalDiff = (sint32)(OilSysHw_frqBaseFrqPmpCmd - u32LocalCalc);
   OilSysHw_frqCmdFreqZone = (uint16)MATHSRV_udtABS(s32LocalDiff);
   /*Msg(3:3356) : The different cases of this logical operation
   have been fully covered.*/

   /* Output hystérisis 2 */
   if (OilSysHw_frqCmdFreqZone > OilSysHw_frqThdDZone1_C)
   {
      CTLPMPREQ_bHysteresis2Output = 1;
   }
   else
   {
      s32LocalDiffcal = (sint32)( OilSysHw_frqThdDZone1_C
                                - OilSysHw_frqOfsThdDZone1_C);
      if (OilSysHw_frqCmdFreqZone <= s32LocalDiffcal)
      {
         CTLPMPREQ_bHysteresis2Output = 0;
      }
   }

   /* Output hystérisis 1 */
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   u32LocalSomcal = (uint32)( OilSysHw_nEngOfsThdZone1_C
                            + OilSysHw_nEngThdZone1_C);
   if (u16LocalExt_nEng > u32LocalSomcal)
   {
      CTLPMPREQ_bHysteresis1Output = 0;
   }
   else
   {
      if (u16LocalExt_nEng <= OilSysHw_nEngThdZone1_C)
      {
         CTLPMPREQ_bHysteresis1Output = 1;
      }
   }

   /* Output hystérisis 3 */
   u32LocalMul = (20 * OilSysHw_frqThdDZone2_C);
   if (OilSysHw_frqCmdFreqZone > u32LocalMul)
   {
      CTLPMPREQ_bHysteresis3Output = 1;
   }
   else
   {
      s32LocalDiff = (sint32)( OilSysHw_frqThdDZone2_C
                             - OilSysHw_frqOfsThdDZone2_C);
      s32LocalDiffcal3 = (s32LocalDiff * 20);
      if (OilSysHw_frqCmdFreqZone <= s32LocalDiffcal3)
      {
         CTLPMPREQ_bHysteresis3Output = 0;
      }
   }

   /* OilSysHw_frqPmpCmdRaw */
   if (CTLPMPREQ_bHysteresis1Output != 0)
   {
      if (CTLPMPREQ_bHysteresis2Output != 0)
      {
         OilSysHw_frqPmpCmdRaw = OilSysHw_frqBaseFrqPmpCmd;
      }
      else
      {
         s32LocalDiffHys2 = (sint32)( OilSysHw_frqBaseFrqPmpCmd
                                    - OilSysHw_frqRetDZone1_C);
         OilSysHw_frqPmpCmdRaw = (uint16)MATHSRV_udtMAX(s32LocalDiffHys2, 0);
      }
   }
   else
   {
      if (CTLPMPREQ_bHysteresis3Output != 0)
      {
         OilSysHw_frqPmpCmdRaw = OilSysHw_frqBaseFrqPmpCmd;
      }
      else
      {
         s32LocalDiffHys3 = (sint32)( OilSysHw_frqBaseFrqPmpCmd
                                    - OilSysHw_frqRetDZone2_C);
         OilSysHw_frqPmpCmdRaw = (uint16)MATHSRV_udtMAX(s32LocalDiffHys3, 0);
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTLPMPREQ_vidCmdApp                                        */
/* !Description :  The oil pump solenoid valve load (PWM frequency and duty   */
/*                 cycle) is transmitted through the basic layer via the      */
/*                 PWDHAL service.                                            */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 OilSysHw_CtlPmpReq_DrvMax_C;                                 */
/*  input uint16 OilSysHw_CtlPmpReq_DrvMin_C;                                 */
/*  input uint16 OilSysHw_CtlPmpReq_Lim;                                      */
/*  input uint16 OilSysHw_CtlPmpReq_Drv;                                      */
/*  input boolean Oil_bActrTstInProgs;                                        */
/*  input uint8 Oil_rSpPosnActrTst;                                           */
/*  input boolean OilSysHw_bSelCmdFreq_C;                                     */
/*  input uint16 OilSysHw_frqPmpCmdRaw;                                       */
/*  input uint16 OilSysHw_CtlPmpReq_CmdFreq_C;                                */
/*  output uint16 OilSysHw_CtlPmpReq_Drv;                                     */
/*  output uint16 OilSysHw_CtlPmpReq;                                         */
/*  output uint16 Oil_rPmpCmdAppl;                                            */
/*  output uint16 OilSysHw_frqPmpCmd;                                         */
/*  output uint16 OilSysHw_frqPmpCmdRaw;                                      */
/*  output uint16 OilSysHw_CtlPmpReq_CmdFreq_C;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTLPMPREQ_vidCmdApp(void)
{
   boolean bLocalOil_bActrTstInProgs;
   uint8   u8LocalOil_bActrTstInProgs;
   uint16  u16LocalOil_rPmpCmdAppl;
   uint16  u16LocalCtlPmpReq_Drv_DELTA;
   uint32  u32LocalCtlPmpReq_Drv_PROD;
   sint32  s32LocalCtlPmpReq_Drv_PWM;


   if (OilSysHw_CtlPmpReq_DrvMax_C > OilSysHw_CtlPmpReq_DrvMin_C)
   {
      u16LocalCtlPmpReq_Drv_DELTA = (uint16)( OilSysHw_CtlPmpReq_DrvMax_C
                                            - OilSysHw_CtlPmpReq_DrvMin_C);
      u32LocalCtlPmpReq_Drv_PROD = (uint32)( OilSysHw_CtlPmpReq_Lim
                                           * u16LocalCtlPmpReq_Drv_DELTA);
      s32LocalCtlPmpReq_Drv_PWM = (sint32)( OilSysHw_CtlPmpReq_DrvMin_C
                                          + ( ( u32LocalCtlPmpReq_Drv_PROD
                                              + 500)
                                            / 1000));
   }
   else
   {
      u16LocalCtlPmpReq_Drv_DELTA = (uint16)( OilSysHw_CtlPmpReq_DrvMin_C
                                            - OilSysHw_CtlPmpReq_DrvMax_C);
      u32LocalCtlPmpReq_Drv_PROD = (uint32)( OilSysHw_CtlPmpReq_Lim
                                           * u16LocalCtlPmpReq_Drv_DELTA);
      s32LocalCtlPmpReq_Drv_PWM = (sint32)( OilSysHw_CtlPmpReq_DrvMin_C
                                          - ( ( u32LocalCtlPmpReq_Drv_PROD
                                              + 500)
                                            / 1000));
   }
   OilSysHw_CtlPmpReq_Drv =
         (uint16)MATHSRV_udtCLAMP(s32LocalCtlPmpReq_Drv_PWM, 0, 1000);
   /*Msg(3:3356) : The different cases of this logical operation
   have been fully covered.*/

   VEMS_vidSET(OilSysHw_CtlPmpReq, OilSysHw_CtlPmpReq_Drv);

   /* compute Oil_rPmpCmdAppl output,
   adapt resolution 100/256E(%) = 0.1S(%)*/
   VEMS_vidGET(Oil_bActrTstInProgs, bLocalOil_bActrTstInProgs);
   VEMS_vidGET(Oil_rSpPosnActrTst, u8LocalOil_bActrTstInProgs);

   if (bLocalOil_bActrTstInProgs != 0)
   {
      u16LocalOil_rPmpCmdAppl = (uint16)( ( ( u8LocalOil_bActrTstInProgs
                                       * 125)
                                     + 16)
                                   / 32);

      VEMS_vidSET(Oil_rPmpCmdAppl, u16LocalOil_rPmpCmdAppl);
   }
   else
   {
      VEMS_vidSET(Oil_rPmpCmdAppl, OilSysHw_CtlPmpReq_Drv);
   }

   if (OilSysHw_bSelCmdFreq_C != 0)
   {
      VEMS_vidSET(OilSysHw_frqPmpCmd, OilSysHw_frqPmpCmdRaw);
   }
   else
   {
      VEMS_vidSET(OilSysHw_frqPmpCmd, OilSysHw_CtlPmpReq_CmdFreq_C);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTLPMPREQ_vidDrvCur                                        */
/* !Description :  The acquisition sends information to the current           */
/*                 application Ext_iMesOilPmp by using  low pass first order  */
/*                 filter of  Ext_iBrutMesOilPmp.                             */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_iBrutMesOilPmp;                                          */
/*  input uint8 OilSysHw_iMesOilPmpGain_C;                                    */
/*  input uint32 CTLPMPREQ_u32ExtIMesOilPmpMEM;                               */
/*  input uint16 Ext_iMesOilPmp;                                              */
/*  output uint16 Ext_iMesOilPmp_Prev;                                        */
/*  output uint16 Ext_iMesOilPmp;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTLPMPREQ_vidDrvCur(void)
{
   uint16 u16LocalExt_iBrutMesOilPmp;
   uint16 u16LocalExt_iMesOilPmp;
   uint16 u16LocalExt_iMesOilPmp_Prev;


   VEMS_vidGET(Ext_iBrutMesOilPmp, u16LocalExt_iBrutMesOilPmp);
   u16LocalExt_iMesOilPmp =
   MATHSRV_u16FirstOrderFilterGu8(OilSysHw_iMesOilPmpGain_C,
                                  &CTLPMPREQ_u32ExtIMesOilPmpMEM,
                                  u16LocalExt_iBrutMesOilPmp);

   VEMS_vidGET(Ext_iMesOilPmp, u16LocalExt_iMesOilPmp_Prev);
   Ext_iMesOilPmp_Prev = (uint16)MATHSRV_udtMIN(u16LocalExt_iMesOilPmp_Prev,
                                                500);

   u16LocalExt_iMesOilPmp =  (uint16)MATHSRV_udtMIN(u16LocalExt_iMesOilPmp,
                                                    500);
   VEMS_vidSET(Ext_iMesOilPmp, u16LocalExt_iMesOilPmp);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTLPMPREQ_vidDiag                                          */
/* !Description :  The input Boolean Ctrl_bOilPmpCmd activates the diagnosis  */
/*                 of solenoid strategy.                                      */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean Dena_oc_CtlPmpReq;                                          */
/*  input boolean Dena_scg_CtlPmpReq;                                         */
/*  input boolean Dena_scp_CtlPmpReq;                                         */
/*  input boolean Dft_oc_CtlPmpReq;                                           */
/*  input boolean Dft_scg_CtlPmpReq;                                          */
/*  input boolean Dft_scp_CtlPmpReq;                                          */
/*  output boolean OilSysHw_bDgoOc_CtlPmpReq;                                 */
/*  output boolean OilSysHw_bDgoScg_CtlPmpReq;                                */
/*  output boolean OilSysHw_bDgoScp_CtlPmpReq;                                */
/*  output boolean OilSysHw_bMonRunOc_CtlPmpReq;                              */
/*  output boolean OilSysHw_bMonRunScg_CtlPmpReq;                             */
/*  output boolean OilSysHw_bMonRunScp_CtlPmpReq;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTLPMPREQ_vidDiag(void)
{
   boolean blocalDena_oc_CtlPmpReq;
   boolean blocalDena_scg_CtlPmpReq;
   boolean blocalDena_scp_CtlPmpReq;
   boolean blocalDft_oc_CtlPmpReq;
   boolean blocalDft_scg_CtlPmpReq;
   boolean blocalDft_scp_CtlPmpReq;
   boolean bLocalInhDiag_CtlPmpReq;


   VEMS_vidGET(Dena_oc_CtlPmpReq, blocalDena_oc_CtlPmpReq);
   VEMS_vidGET(Dena_scg_CtlPmpReq, blocalDena_scg_CtlPmpReq);
   VEMS_vidGET(Dena_scp_CtlPmpReq, blocalDena_scp_CtlPmpReq);
   VEMS_vidGET(Dft_oc_CtlPmpReq, blocalDft_oc_CtlPmpReq);
   VEMS_vidGET(Dft_scg_CtlPmpReq, blocalDft_scg_CtlPmpReq);
   VEMS_vidGET(Dft_scp_CtlPmpReq, blocalDft_scp_CtlPmpReq);

   bLocalInhDiag_CtlPmpReq = GDGAR_bGetFRM(FRM_FRM_INHDIAG_CTLPMPREQ);

   OilSysHw_bDgoOc_CtlPmpReq = blocalDft_oc_CtlPmpReq;
   OilSysHw_bDgoScg_CtlPmpReq = blocalDft_scg_CtlPmpReq;
   OilSysHw_bDgoScp_CtlPmpReq = blocalDft_scp_CtlPmpReq;

   if (bLocalInhDiag_CtlPmpReq == 0)
   {
      if (blocalDena_oc_CtlPmpReq == 1)
      {
         OilSysHw_bMonRunOc_CtlPmpReq  = 1;
      }
      else
      {
         OilSysHw_bMonRunOc_CtlPmpReq  = 0;
      }

      if (blocalDena_scg_CtlPmpReq == 1)
      {
         OilSysHw_bMonRunScg_CtlPmpReq  = 1;
      }
      else
      {
         OilSysHw_bMonRunScg_CtlPmpReq  = 0;
      }

      if (blocalDena_scp_CtlPmpReq == 1)
      {
         OilSysHw_bMonRunScp_CtlPmpReq  = 1;
      }
      else
      {
         OilSysHw_bMonRunScp_CtlPmpReq  = 0;
      }
   }
   else
   {
      OilSysHw_bMonRunOc_CtlPmpReq  = 0;
      OilSysHw_bMonRunScg_CtlPmpReq = 0;
      OilSysHw_bMonRunScp_CtlPmpReq = 0;
   }
}
/*-------------------------------- end of file -------------------------------*/
