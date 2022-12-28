/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FTPCTL                                                  */
/* !Description     : FTPCTL component                                        */
/*                                                                            */
/* !Module          : FTPCTL                                                  */
/* !Description     : Fuel Transfer Pump Control (FTPCtl)                     */
/*                                                                            */
/* !File            : FTPCTL_FCT1.C                                           */
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
/*   1 / FTPCTL_vidInitOutput                                                 */
/*   2 / FTPCTL_vidEngine_need_calculus                                       */
/*   3 / FTPCTL_vidFlow_optimum                                               */
/*   4 / FTPCTL_vidCorresponding_ratio                                        */
/*   5 / FTPCTL_vidHysteresis_filtering                                       */
/*   6 / FTPCTL_vidFalling_edge_filtering                                     */
/*   7 / FTPCTL_vidWorking_field                                              */
/*   8 / FTPCTL_vidVolt_Control_activ                                         */
/*   9 / FTPCTL_vidPriming_need                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5139357 / 02                                        */
/* !OtherRefs   : 01460_10_02425 / 3.3                                        */
/* !OtherRefs   : VEMS V02 ECU#067192                                         */
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
#include "FTPCTL.h"
#include "FTPCTL_L.h"
#include "FTPCTL_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FTPCTL_vidInitOutput                                       */
/* !Description :  initialization function for output                         */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean FTPCtl_bFirstCmdFuPmp_NV;                                   */
/*  input uint8 FTPCtl_rIniFlowFuFil_C;                                       */
/*  input boolean FTPCtl_bFirstFillFuMemOut_MP;                               */
/*  input boolean FTPCtl_bMemFirstFillFu;                                     */
/*  input boolean FTPCtl_bFirstCmdFuPmp;                                      */
/*  input uint16 FTPCtl_ctEngCutStallLdMem_C;                                 */
/*  input uint16 FTPCtl_rFilIncRatFlowFuFil_MP;                               */
/*  input uint16 FTPCtl_ctFirstCmdFuPmpTmr_NV;                                */
/*  input uint16 FTPCtl_ctFirstCmdTmrMem_MP;                                  */
/*  output boolean FTPCtl_bFirstFillFuMemOut_MP;                              */
/*  output boolean Afts_bRstMemFirstFillFuEng_MP;                             */
/*  output boolean FTPCtl_bFirstCmdFuPmpNxt_MP;                               */
/*  output uint16 FTPCtl_rFilIncRatFlowFuFil_MP;                              */
/*  output uint16 FTPCtl_rFilIncRatFlowFuNxt_MP;                              */
/*  output boolean FTPCtl_bFilDec_rFlowFuNxt_MP;                              */
/*  output boolean FTPCtl_bMemFirstFillFu;                                    */
/*  output boolean FTPCtl_bFirstFillFuNxt_MP;                                 */
/*  output uint16 FTPCtl_rFlowFuTnkPmp;                                       */
/*  output st123 FTPCtl_stEngCutStall;                                        */
/*  output boolean FTPCtl_bFirstCmdFuPmp;                                     */
/*  output boolean FTPCtl_bEngCutStallInter;                                  */
/*  output uint16 FTPCtl_ctCutStallLdMem;                                     */
/*  output st121 FTPCtl_stEng;                                                */
/*  output uint16 FTPCtl_rFlowFuDftProp;                                      */
/*  output uint16 FTPCtl_rFlowFuDftOnOff;                                     */
/*  output st122 FTPCtl_stCaseEngAlt;                                         */
/*  output uint32 FTPCTL_u32rFilDecrFlowFuFiltMem;                            */
/*  output boolean FTPCTL_bLogicalOrFlowFuPrev;                               */
/*  output uint16 FTPCTL_u16FlowFuCount;                                      */
/*  output uint16 FTPCtl_rFlowFuCutStall;                                     */
/*  output boolean FTPCTL_bECUbWkuPtEngStrtPrev;                              */
/*  output uint16 FTPCTL_u16ECUbWkuPtEngStrtCount;                            */
/*  output uint16 FTPCtl_rFlowFuEngStAfuHyb;                                  */
/*  output uint16 FTPCtl_ctFirstCmdTmrMem_MP;                                 */
/*  output uint16 FTPCTL_u16IniCdnOutput;                                     */
/*  output boolean FTPCTL_bMemFirstFillFuEngPrev1;                            */
/*  output boolean FTPCTL_bMemFirstFillFuEngPrev2;                            */
/*  output uint16 FTPCtl_ctFirstCmdFuPmpTmr;                                  */
/*  output uint16 FTPCTL_u16outputcounter;                                    */
/*  output boolean FTPCtl_bAcvPmpWkuPha;                                      */
/*  output boolean FTPCTL_bEOLStateTimerCond;                                 */
/*  output boolean FTPCtl_bFirstCmdFuPmpTmrMax;                               */
/*  output boolean FTPCTL_bEOL_inCdn;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FTPCTL_vidInitOutput(void)
{

   FTPCtl_bFirstFillFuMemOut_MP = FTPCtl_bFirstCmdFuPmp_NV;
   Afts_bRstMemFirstFillFuEng_MP = 0;
   FTPCtl_bFirstCmdFuPmpNxt_MP = 0;
   FTPCtl_rFilIncRatFlowFuFil_MP = FTPCtl_rIniFlowFuFil_C;
   FTPCtl_rFilIncRatFlowFuNxt_MP = 0;
   FTPCtl_bFilDec_rFlowFuNxt_MP = 0;
   VEMS_vidSET(FTPCtl_bMemFirstFillFu, FTPCtl_bFirstFillFuMemOut_MP);
   FTPCtl_bFirstFillFuNxt_MP = FTPCtl_bFirstFillFuMemOut_MP;
   VEMS_vidSET(FTPCtl_rFlowFuTnkPmp, 0);
   FTPCtl_stEngCutStall = ENGCUTSTALL_FIRST_PRIMING_MEMORY;
   VEMS_vidGET(FTPCtl_bMemFirstFillFu, FTPCtl_bFirstCmdFuPmp);
   FTPCtl_bEngCutStallInter = 0;
   FTPCtl_ctCutStallLdMem = (uint16)MATHSRV_udtMIN(FTPCtl_ctEngCutStallLdMem_C,
                                                   1000);
   FTPCtl_stEng = ENG_INITIALIZATION;
   FTPCtl_rFlowFuDftProp = 0;
   FTPCtl_rFlowFuDftOnOff = 0;
   FTPCtl_stCaseEngAlt = CASEENGALT_INITIALIZATION;
   FTPCTL_u32rFilDecrFlowFuFiltMem =
      (uint32)(FTPCtl_rFilIncRatFlowFuFil_MP * 256);
   FTPCTL_bLogicalOrFlowFuPrev = 0;
   FTPCTL_u16FlowFuCount = 0;
   FTPCtl_rFlowFuCutStall = 0;
   FTPCTL_bECUbWkuPtEngStrtPrev = 0;
   FTPCTL_u16ECUbWkuPtEngStrtCount =0;
   FTPCtl_rFlowFuEngStAfuHyb = 0;
   FTPCtl_ctFirstCmdTmrMem_MP = FTPCtl_ctFirstCmdFuPmpTmr_NV;
   FTPCTL_u16IniCdnOutput = FTPCtl_ctFirstCmdTmrMem_MP;
   FTPCTL_bMemFirstFillFuEngPrev1 = 0;
   FTPCTL_bMemFirstFillFuEngPrev2 = 0;
   FTPCtl_ctFirstCmdFuPmpTmr = 0;
   FTPCTL_u16outputcounter = 0;
   VEMS_vidSET(FTPCtl_bAcvPmpWkuPha, 0);
   FTPCTL_bEOLStateTimerCond = 0;
   FTPCtl_bFirstCmdFuPmpTmrMax = 0;
   FTPCTL_bEOL_inCdn = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FTPCTL_vidEngine_need_calculus                             */
/* !Description :  This function aims at evaluating the real need from the    */
/*                 engine in pump flow.                                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_11_02548_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FTPCTL_vidFlow_optimum();                                */
/*  extf argret void FTPCTL_vidCorresponding_ratio();                         */
/*  extf argret void FTPCTL_vidHysteresis_filtering();                        */
/*  extf argret void FTPCTL_vidFalling_edge_filtering();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FTPCTL_vidEngine_need_calculus(void)
{
   FTPCTL_vidFlow_optimum();
   FTPCTL_vidCorresponding_ratio();
   FTPCTL_vidHysteresis_filtering();
   FTPCTL_vidFalling_edge_filtering();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FTPCTL_vidFlow_optimum                                     */
/* !Description :  The mass flow set point for the engine’s injectors         */
/*                 corresponds to the product of the number of cylinders by   */
/*                 the injection setpoint.                                    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_11_02548_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 InjSys_mFuSp;                                                */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint8 Ext_noCylEng_C;                                               */
/*  input uint32 FTPCtl_noMassFuInj_nEng_MP;                                  */
/*  input uint32 FTPCtl_mFuInjX_A[11];                                        */
/*  input uint16 FTPCtl_nEngY_A[13];                                          */
/*  input uint16 FTPCtl_volfDynFlowFuAd_M[11][13];                            */
/*  input uint16 FTPCtl_volfFlowFuEng_M[11][13];                              */
/*  input uint16 FTPCtl_volfDynFlowFuAd_MP;                                   */
/*  input uint16 FTPCtl_volfFlowFu_MP;                                        */
/*  output uint32 FTPCtl_noMassFuInj_nEng_MP;                                 */
/*  output uint16 FTPCtl_volfDynFlowFuAd_MP;                                  */
/*  output uint16 FTPCtl_volfFlowFu_MP;                                       */
/*  output uint16 FTPCtl_volfSumFlowFu;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FTPCTL_vidFlow_optimum(void)
{
   uint8  u8LocalIndex;
   uint16 u16LocalInjSys_mFuSp;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   uint16 u16LocalCalcinterp;
   uint16 u16LocalFTPCtl_noMaFuInj_nEng_MP;
   uint16 u16LocalFTPCtl_mFuInjX_A[11];
   /*QAC Msg(2:3132): No impact*/
   uint16 u16LocalCalc;
   uint32 u32LocalCalc;
   uint32 u32LocalFTPCtl_noMaFuInj_nEng_MP;


   VEMS_vidGET(InjSys_mFuSp, u16LocalInjSys_mFuSp);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   u32LocalFTPCtl_noMaFuInj_nEng_MP =
      (uint32)(Ext_noCylEng_C * u16LocalInjSys_mFuSp);
   FTPCtl_noMassFuInj_nEng_MP =
      MATHSRV_udtMIN(u32LocalFTPCtl_noMaFuInj_nEng_MP, 2684354);
   u32LocalFTPCtl_noMaFuInj_nEng_MP =
      MATHSRV_udtMIN(FTPCtl_noMassFuInj_nEng_MP, 262140);
   u16LocalFTPCtl_noMaFuInj_nEng_MP =
      (uint16)((u32LocalFTPCtl_noMaFuInj_nEng_MP + 2) / 4);
   for(u8LocalIndex = 0; u8LocalIndex < 11; u8LocalIndex++)
   {
      u32LocalCalc = MATHSRV_udtMIN(FTPCtl_mFuInjX_A[u8LocalIndex], 262142);
      u32LocalCalc = (u32LocalCalc + 2) / 4;
      u16LocalCalc = (uint16)MATHSRV_udtMIN(u32LocalCalc, 65535);
      u16LocalFTPCtl_mFuInjX_A[u8LocalIndex] = u16LocalCalc;
   }
   u16LocalParaX =
      MATHSRV_u16CalcParaIncAryU16(u16LocalFTPCtl_mFuInjX_A,
                                   u16LocalFTPCtl_noMaFuInj_nEng_MP,
                                   11);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(FTPCtl_nEngY_A,
                                                u16LocalExt_nEng,
                                                13);
   /*Production of FTPCtl_volfDynFlowFuAd_MP*/
   u16LocalCalcinterp = MATHSRV_u16Interp2d(&FTPCtl_volfDynFlowFuAd_M[0][0],
                                            u16LocalParaX,
                                            u16LocalParaY,
                                            13);
   FTPCtl_volfDynFlowFuAd_MP = (uint16)MATHSRV_udtMIN(u16LocalCalcinterp, 2000);
   /*Production of FTPCtl_volfFlowFu_MP*/
   u16LocalCalcinterp = MATHSRV_u16Interp2d(&FTPCtl_volfFlowFuEng_M[0][0],
                                            u16LocalParaX,
                                            u16LocalParaY,
                                            13);
   FTPCtl_volfFlowFu_MP = (uint16)MATHSRV_udtMIN(u16LocalCalcinterp, 2000);
   FTPCtl_volfSumFlowFu = (uint16)( FTPCtl_volfDynFlowFuAd_MP
                                  + FTPCtl_volfFlowFu_MP);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FTPCTL_vidCorresponding_ratio                              */
/* !Description :  The input corresponds to the necessary flow for the pump   */
/*                 calculted into L/h.                                        */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_11_02548_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 FTPCtl_volfSumFlowFu;                                        */
/*  input uint8 FTPCtl_noFlowFuPerc_C;                                        */
/*  input uint16 FTPCtl_volfFlowFuMax_C;                                      */
/*  output uint16 FTPCtl_rNormFlowRat;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FTPCTL_vidCorresponding_ratio(void)
{
   uint32 u32LocalProduct;
   uint32 u32LocalFTPCtl_rNormFlowRat;


   u32LocalProduct = (uint32)(FTPCtl_volfSumFlowFu * FTPCtl_noFlowFuPerc_C);
   u32LocalProduct = u32LocalProduct * 10;
   if (FTPCtl_volfFlowFuMax_C != 0)
   {
      u32LocalFTPCtl_rNormFlowRat = u32LocalProduct / FTPCtl_volfFlowFuMax_C;
   }
   else
   {
      u32LocalFTPCtl_rNormFlowRat = 65535;
   }
   FTPCtl_rNormFlowRat = (uint16)MATHSRV_udtMIN(u32LocalFTPCtl_rNormFlowRat,
                                                1000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FTPCTL_vidHysteresis_filtering                             */
/* !Description :  This elementary function realizing an hysteresis filter of */
/*                 the flow ratio                                             */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_11_02548_005.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 FTPCtl_rThdHysRatFlowFu_C;                                    */
/*  input uint8 FTPCtl_mfHysWide;                                             */
/*  input uint16 FTPCtl_rFilIncRatFlowFuNxt_MP;                               */
/*  input uint16 FTPCtl_rNormFlowRat;                                         */
/*  input uint16 FTPCtl_rFilIncRat_MP;                                        */
/*  output uint8 FTPCtl_mfHysWide;                                            */
/*  output uint16 FTPCtl_rFilIncRat_MP;                                       */
/*  output uint16 FTPCtl_rFilIncRatFlowFu;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FTPCTL_vidHysteresis_filtering(void)
{
   uint16 u16LocalProd;
   uint32 u32LocalSum;
   sint32 s32LocalDiff;

   FTPCtl_mfHysWide = (uint8)MATHSRV_udtMIN(FTPCtl_rThdHysRatFlowFu_C, 100);
   u16LocalProd = (uint16)(FTPCtl_mfHysWide * 10);
   s32LocalDiff = (sint32)(FTPCtl_rFilIncRatFlowFuNxt_MP - u16LocalProd);
   u32LocalSum = (uint32)(FTPCtl_rNormFlowRat + u16LocalProd);
   if (FTPCtl_rNormFlowRat >= s32LocalDiff)
   {
      FTPCtl_rFilIncRat_MP =
         (uint16)MATHSRV_udtMIN(FTPCtl_rFilIncRatFlowFuNxt_MP, 1000);
   }
   else
   {
      FTPCtl_rFilIncRat_MP = (uint16)MATHSRV_udtMIN(u32LocalSum, 1000);
   }
   if (FTPCtl_rNormFlowRat > FTPCtl_rFilIncRatFlowFuNxt_MP)
   {
      FTPCtl_rFilIncRatFlowFu = (uint16)MATHSRV_udtMIN(FTPCtl_rNormFlowRat,
                                                       1000);
   }
   else
   {
      FTPCtl_rFilIncRatFlowFu = FTPCtl_rFilIncRat_MP;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FTPCTL_vidFalling_edge_filtering                           */
/* !Description :  This subfunction aims at avoiding rough falling edges on   */
/*                 the flow ratio requests.                                   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_11_02548_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean FTPCtl_bRstFlowFuFil_C;                                     */
/*  input uint8 FTPCtl_rIniFlowFuFil_C;                                       */
/*  input uint16 FTPCtl_rFilIncRatFlowFuFil_MP;                               */
/*  input uint8 FTPCtl_facConTiFlowFuFil_C;                                   */
/*  input uint32 FTPCTL_u32rFilDecrFlowFuFiltMem;                             */
/*  input uint16 FTPCtl_rFilIncRatFlowFu;                                     */
/*  input uint16 FTPCtl_rFilIncRatFlowFuNxt_MP;                               */
/*  input sint16 FTPCtl_rDeltaCompLoFlowFu_C;                                 */
/*  input sint16 FTPCtl_rDeltaCompHiFlowFu_C;                                 */
/*  input boolean FTPCTL_bLogicalOrFlowFuPrev;                                */
/*  input uint16 FTPCtl_tiWaitAcvFil_C;                                       */
/*  input uint16 FTPCTL_u16FlowFuCount;                                       */
/*  input boolean FTPCtl_bFilDec_rSel_MP;                                     */
/*  output uint16 FTPCtl_rFilIncRatFlowFuFil_MP;                              */
/*  output uint32 FTPCTL_u32rFilDecrFlowFuFiltMem;                            */
/*  output uint16 FTPCTL_u16FlowFuCount;                                      */
/*  output boolean FTPCtl_bFilDec_rSel_MP;                                    */
/*  output boolean FTPCTL_bLogicalOrFlowFuPrev;                               */
/*  output uint16 FTPCtl_rFilDec_rFlowFu;                                     */
/*  output uint16 FTPCtl_rFilIncRatFlowFuNxt_MP;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FTPCTL_vidFalling_edge_filtering(void)
{
   boolean bLocalLogicalOrFlowFu;
   uint8   u8LocalFTPCtlrFilDecrFlowFu;
   uint16  u16LocalFTPCtl_rFilDec_rFlowFu;
   uint16  u16LocalrFilDec_rFlowFu;
   sint32  s32LocalIncRatFlowFu;


   /*Filter processing : Production of FTPCtl_rFilIncRatFlowFuFil_MP*/
   if (FTPCtl_bRstFlowFuFil_C != 0)
   {
      FTPCtl_rFilIncRatFlowFuFil_MP = FTPCtl_rIniFlowFuFil_C;
      FTPCTL_u32rFilDecrFlowFuFiltMem = (uint32)( FTPCtl_rFilIncRatFlowFuFil_MP
                                                * 256);
   }
   else
   {
      if(FTPCtl_facConTiFlowFuFil_C < 100)
      {
         u8LocalFTPCtlrFilDecrFlowFu =
            (uint8)(((FTPCtl_facConTiFlowFuFil_C * 640) + 125) / 250);
         u16LocalrFilDec_rFlowFu =
            MATHSRV_u16FirstOrderFilterGu8(u8LocalFTPCtlrFilDecrFlowFu,
                                           &FTPCTL_u32rFilDecrFlowFuFiltMem,
                                           FTPCtl_rFilIncRatFlowFu);
         FTPCtl_rFilIncRatFlowFuFil_MP =
                        (uint16)MATHSRV_udtMIN(u16LocalrFilDec_rFlowFu, 1000);
      }
      else
      {
         FTPCtl_rFilIncRatFlowFuFil_MP =
                  (uint16)MATHSRV_udtMIN(FTPCtl_rFilIncRatFlowFu, 1000);
         FTPCTL_u32rFilDecrFlowFuFiltMem =
                  (uint32)(FTPCtl_rFilIncRatFlowFuFil_MP * 256);

      }
   }

   /*Production of bLocalLogicalOrFlowFu*/
   s32LocalIncRatFlowFu = (sint32)( FTPCtl_rFilIncRatFlowFu
                                  - FTPCtl_rFilIncRatFlowFuNxt_MP);
   s32LocalIncRatFlowFu = s32LocalIncRatFlowFu * 10;
   if (  (s32LocalIncRatFlowFu > (sint32)FTPCtl_rDeltaCompLoFlowFu_C)
      || (  (s32LocalIncRatFlowFu < (sint32)FTPCtl_rDeltaCompLoFlowFu_C)
         && (s32LocalIncRatFlowFu >= (sint32)FTPCtl_rDeltaCompHiFlowFu_C)))
   {
      bLocalLogicalOrFlowFu = 1;
   }
   else
   {
      bLocalLogicalOrFlowFu = 0;
   }

   /*Turn_On_Delay*/
   if (bLocalLogicalOrFlowFu != 0)
   {
      if (FTPCTL_bLogicalOrFlowFuPrev == 0)
      {
         FTPCTL_u16FlowFuCount = FTPCtl_tiWaitAcvFil_C;
      }
      else
      {
         if (FTPCTL_u16FlowFuCount > 0)
         {
            FTPCTL_u16FlowFuCount = (uint16)(FTPCTL_u16FlowFuCount - 1);
         }
      }
      if (FTPCTL_u16FlowFuCount == 0)
      {
         FTPCtl_bFilDec_rSel_MP = 1;
      }
      else
      {
         FTPCtl_bFilDec_rSel_MP = 0;
      }
   }
   else
   {
      FTPCtl_bFilDec_rSel_MP = 0;
   }
   FTPCTL_bLogicalOrFlowFuPrev = bLocalLogicalOrFlowFu;

   /*Production of FTPCtl_rFilDec_rFlowFu*/
   if (FTPCtl_bFilDec_rSel_MP != 0)
   {
      u16LocalFTPCtl_rFilDec_rFlowFu = FTPCtl_rFilIncRatFlowFu;
   }
   else
   {
      u16LocalFTPCtl_rFilDec_rFlowFu = FTPCtl_rFilIncRatFlowFuFil_MP;
   }
   FTPCtl_rFilDec_rFlowFu =
      (uint16)MATHSRV_udtMIN(u16LocalFTPCtl_rFilDec_rFlowFu, 1000);

   FTPCtl_rFilIncRatFlowFuNxt_MP =
      (uint16)MATHSRV_udtMIN(FTPCtl_rFilIncRatFlowFu, 1000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FTPCTL_vidWorking_field                                    */
/* !Description :  This subfunction aims at initializing pump’s sequences at  */
/*                 the ECU’s wake up and defining the working field of the    */
/*                 pump                                                       */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_11_02548_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean ECU_bWkuPtEngStrt;                                          */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean Ext_bKeyOn;                                                 */
/*  input boolean Ext_bVehCollWarnFil;                                        */
/*  input boolean Ext_bUnBlsReq;                                              */
/*  input boolean FTPCTL_bECUbWkuPtEngStrtPrev;                               */
/*  input uint16 FTPCtl_tiHldVldWin_C;                                        */
/*  input uint16 FTPCTL_u16ECUbWkuPtEngStrtCount;                             */
/*  input boolean ECU_bWkuPtEngStrtDly_MP;                                    */
/*  output boolean ECU_bWkuPtEngStrtDly_MP;                                   */
/*  output uint16 FTPCTL_u16ECUbWkuPtEngStrtCount;                            */
/*  output boolean FTPCTL_bECUbWkuPtEngStrtPrev;                              */
/*  output boolean FTPCtl_bAcvPmpWkuPha;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FTPCTL_vidWorking_field(void)
{
   boolean bLocalECU_bWkuMain;
   boolean bLocalExt_bKeyOn;
   boolean bLocalExt_bVehCollWarnFil;
   boolean bLocalExt_bUnBlsReq;
   boolean bLocalECU_bWkuPtEngStrt;


   VEMS_vidGET(ECU_bWkuPtEngStrt, bLocalECU_bWkuPtEngStrt);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidGET(Ext_bKeyOn, bLocalExt_bKeyOn);
   VEMS_vidGET(Ext_bVehCollWarnFil, bLocalExt_bVehCollWarnFil);
   VEMS_vidGET(Ext_bUnBlsReq, bLocalExt_bUnBlsReq);
   /*Production of ECU_bWkuPtEngStrtDly_MP*/
   if (bLocalECU_bWkuPtEngStrt != 0)
   {
      ECU_bWkuPtEngStrtDly_MP = 1;
   }
   else
   {
      if (FTPCTL_bECUbWkuPtEngStrtPrev != 0)
      {
         FTPCTL_u16ECUbWkuPtEngStrtCount = FTPCtl_tiHldVldWin_C;
      }
      else
      {
         if (FTPCTL_u16ECUbWkuPtEngStrtCount > 0)
         {
            FTPCTL_u16ECUbWkuPtEngStrtCount =
               (uint16)(FTPCTL_u16ECUbWkuPtEngStrtCount - 1);
         }
      }
      if (FTPCTL_u16ECUbWkuPtEngStrtCount == 0)
      {
         ECU_bWkuPtEngStrtDly_MP = 0;
      }
      else
      {
         ECU_bWkuPtEngStrtDly_MP = 1;
      }
   }
   FTPCTL_bECUbWkuPtEngStrtPrev = bLocalECU_bWkuPtEngStrt;

   /*Production of FTPCtl_bAcvPmpWkuPha*/
   if (  (  (bLocalECU_bWkuPtEngStrt != 0)
         || (ECU_bWkuPtEngStrtDly_MP!= 0)
         || (bLocalECU_bWkuMain != 0)
         || (bLocalExt_bKeyOn != 0))
      && (bLocalExt_bVehCollWarnFil == 0)
      && (bLocalExt_bUnBlsReq == 0))
   {
      VEMS_vidSET(FTPCtl_bAcvPmpWkuPha, 1);
   }
   else
   {
      VEMS_vidSET(FTPCtl_bAcvPmpWkuPha, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FTPCTL_vidVolt_Control_activ                               */
/* !Description :  This subfunction aims at compelling the pump to provide    */
/*                 more flow in some life situations than in case of nominal  */
/*                 feeding. To manage it, a request is sent to the alternator,*/
/*                 so that it increases its output voltage.                   */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_11_02548_013.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint16 FTPCtl_rFilDec_rFlowFu;                                      */
/*  input uint16 FTPCtl_rFlowFuThdLo_C;                                       */
/*  input uint16 FTPCtl_rFlowFuThdHi_C;                                       */
/*  input boolean FTPCtl_bFilDec_rFlowFuNxt_MP;                               */
/*  input uint8 FTPCtl_stEngRun_C;                                            */
/*  output boolean FTPCtl_bFilDec_rFlowFuNxt_MP;                              */
/*  output boolean FTPCtl_bVoltCtlReq;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FTPCTL_vidVolt_Control_activ(void)
{
   boolean bLocalAcvFuPmpVoltCtlReq;
   uint8   u8LocalCoPTSt_stEng;


   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);

   /*HysPos*/
   if (FTPCtl_rFilDec_rFlowFu <= FTPCtl_rFlowFuThdLo_C)
   {
      FTPCtl_bFilDec_rFlowFuNxt_MP = 0;
   }
   else
   {
      if (FTPCtl_rFilDec_rFlowFu >= FTPCtl_rFlowFuThdHi_C)
      {
         FTPCtl_bFilDec_rFlowFuNxt_MP = 1;
      }
   }
   bLocalAcvFuPmpVoltCtlReq = GDGAR_bGetFRM(FRM_FRM_ACVFUPMPVOLTCTLREQ);
   if ( (bLocalAcvFuPmpVoltCtlReq !=0 )
      ||( (FTPCtl_bFilDec_rFlowFuNxt_MP != 0)
        &&(u8LocalCoPTSt_stEng == FTPCtl_stEngRun_C)))
   {
      VEMS_vidSET(FTPCtl_bVoltCtlReq, 1);
   }
   else
   {
      VEMS_vidSET(FTPCtl_bVoltCtlReq, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FTPCTL_vidPriming_need                                     */
/* !Description :  This function memorizes if a first priming was done in end */
/*                 of line or not. It’s possible to re-activate it if needed  */
/*                 (for example, after a change of the component in           */
/*                 aftersales) via an aftersales’ request.                    */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_11_02548_010.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FTPCTL_vidEOLMemorisation();                             */
/*  extf argret void FTPCTL_vidEOLStateTimer();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FTPCTL_vidPriming_need(void)
{
   FTPCTL_vidEOLMemorisation();
   FTPCTL_vidEOLStateTimer();
}
/*---------------------------------end of file--------------------------------*/