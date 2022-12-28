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
/* !File            : FTPCTL_FCT2.C                                           */
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
/*   1 / FTPCTL_vidEOLMemorisation                                            */
/*   2 / FTPCTL_vidEOLStateTimer                                              */
/*   3 / FTPCTL_vidPressHoldCaseCutStall                                      */
/*   4 / FTPCTL_vidPressHoldEngineActive                                      */
/*   5 / FTPCTL_vidPressure_hold_in_gas                                       */
/*   6 / FTPCTL_vidFlowSetpointSynthesis                                      */
/*   7 / FTPCTL_vidRecovryModesActivation                                     */
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
/* !Function    :  FTPCTL_vidEOLMemorisation                                  */
/* !Description :  This subfunction memorizes if a first priming was done in  */
/*                 end of line or not. It’s possible to re-activate it if     */
/*                 needed via an aftersales’ request. It also provides first  */
/*                 priming  done flag” for Afts tool.                         */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_11_02548_011.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Afts_bRstMemFirstFillFuEng;                                 */
/*  input boolean Afts_bRstMemFirstFillFuEng_MP;                              */
/*  input boolean FTPCtl_bFirstCmdFuPmpNxt_MP;                                */
/*  input boolean FTPCtl_bMemFirstCmdFuPmpRst_C;                              */
/*  input boolean FTPCtl_bFirstCmdFuPmp_NV;                                   */
/*  input boolean FTPCtl_bFirstCmdFuPmp;                                      */
/*  input boolean FTPCtl_bFirstFillFuNxt_MP;                                  */
/*  output boolean FTPCtl_bFirstCmdFuPmp_NV;                                  */
/*  output boolean FTPCtl_bFirstFillFuMemOut_MP;                              */
/*  output boolean Afts_bRstMemFirstFillFuEng_MP;                             */
/*  output boolean FTPCtl_bFirstCmdFuPmpNxt_MP;                               */
/*  output boolean FTPCtl_bMemFirstFillFu;                                    */
/*  output boolean FTPCtl_bFirstFillFuNxt_MP;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FTPCTL_vidEOLMemorisation(void)
{
   boolean bLocalRstNVM;
   boolean bLocalAftsbRstMemFirstFillFuEng;


   VEMS_vidGET(Afts_bRstMemFirstFillFuEng, bLocalAftsbRstMemFirstFillFuEng);
   if (  (bLocalAftsbRstMemFirstFillFuEng != 0)
      || (Afts_bRstMemFirstFillFuEng_MP != 0))
   {
      bLocalRstNVM = 1;
   }
   else
   {
      bLocalRstNVM = 0;
   }

   if (bLocalRstNVM == 0)
   {
      FTPCtl_bFirstCmdFuPmp_NV = FTPCtl_bFirstCmdFuPmpNxt_MP;
   }
   else
   {
      FTPCtl_bFirstCmdFuPmp_NV = FTPCtl_bMemFirstCmdFuPmpRst_C;
   }

   if (  (bLocalRstNVM != 0)
      && (Afts_bRstMemFirstFillFuEng_MP == 0))
   {
      FTPCtl_bFirstFillFuMemOut_MP = FTPCtl_bMemFirstCmdFuPmpRst_C;
   }
   else
   {
      FTPCtl_bFirstFillFuMemOut_MP = FTPCtl_bFirstCmdFuPmp_NV;
   }
   Afts_bRstMemFirstFillFuEng_MP = bLocalRstNVM;
   FTPCtl_bFirstCmdFuPmpNxt_MP = FTPCtl_bFirstCmdFuPmp;
   VEMS_vidSET(FTPCtl_bMemFirstFillFu, FTPCtl_bFirstFillFuNxt_MP);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FTPCTL_vidEOLStateTimer                                    */
/* !Description :  This subfunction memorizes the accumulated time spend in   */
/*                 End Of Line mode in case of Key Off action while priming.  */
/*                 At the end of the timer this function outputs a flag.      */
/*                 Counter is cleared when priming is done.                   */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_11_02548_012.05                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 FTPCTL_u16outputcounter;                                     */
/*  input boolean FTPCTL_bMemFirstFillFuEngPrev1;                             */
/*  input boolean FTPCTL_bMemFirstFillFuEngPrev2;                             */
/*  input uint16 FTPCtl_ctFirstCmdFuPmpTmr_NV;                                */
/*  input boolean FTPCtl_bFirstCmdFuPmpTmrMax;                                */
/*  input uint16 FTPCTL_u16IniCdnOutput;                                      */
/*  input boolean FTPCTL_bEOLStateTimerCond;                                  */
/*  input st123 FTPCtl_stEngCutStall;                                         */
/*  input uint8 FTPCtl_stFirst_C;                                             */
/*  input boolean FTPCTL_bEOL_inCdn;                                          */
/*  input boolean FTPCTL_bEOL_outCdn;                                         */
/*  input uint16 FTPCtl_ctFirstCmdTmrInc_MP;                                  */
/*  input uint16 FTPCtl_ctFirstCmdFuPmpTmr;                                   */
/*  input uint16 FTPCtl_ctFirstAcvFuPmp_C;                                    */
/*  input boolean Afts_bRstMemFirstFillFuEng;                                 */
/*  output uint16 FTPCtl_ctFirstCmdFuPmpTmr_NV;                               */
/*  output uint16 FTPCtl_ctFirstCmdTmrMem_MP;                                 */
/*  output uint16 FTPCtl_ctFirstCmdTmrInc_MP;                                 */
/*  output boolean FTPCTL_bEOL_inCdn;                                         */
/*  output boolean FTPCTL_bEOL_outCdn;                                        */
/*  output uint16 FTPCTL_u16outputcounter;                                    */
/*  output boolean FTPCtl_bFirstCmdFuPmpTmrMax;                               */
/*  output boolean FTPCTL_bMemFirstFillFuEngPrev2;                            */
/*  output boolean FTPCTL_bMemFirstFillFuEngPrev1;                            */
/*  output uint16 FTPCtl_ctFirstCmdFuPmpTmr;                                  */
/*  output uint16 FTPCTL_u16IniCdnOutput;                                     */
/*  output boolean FTPCTL_bEOLStateTimerCond;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FTPCTL_vidEOLStateTimer(void)
{
   uint32 u32LocalInc;


   FTPCtl_ctFirstCmdFuPmpTmr_NV = FTPCTL_u16outputcounter;
   if (  (FTPCTL_bMemFirstFillFuEngPrev1 != 0)
      && (FTPCTL_bMemFirstFillFuEngPrev2 == 0))
   {
      FTPCtl_ctFirstCmdTmrMem_MP = 0;
   }
   else
   {
      FTPCtl_ctFirstCmdTmrMem_MP = FTPCtl_ctFirstCmdFuPmpTmr_NV;
   }
   if (FTPCtl_bFirstCmdFuPmpTmrMax != 0)
   {
      FTPCtl_ctFirstCmdTmrInc_MP = 0;
   }
   else
   {
      FTPCtl_ctFirstCmdTmrInc_MP = FTPCTL_u16IniCdnOutput;
   }

   if (FTPCTL_bEOLStateTimerCond == 0)
   {
      FTPCTL_bEOL_inCdn = 1;
   }
   else
   {
      if (FTPCtl_stEngCutStall == FTPCtl_stFirst_C)
      {
         FTPCTL_bEOL_inCdn = 1;
      }
      else
      {
         FTPCTL_bEOL_inCdn = 0;
      }
   }
   FTPCTL_bEOL_outCdn = FTPCTL_bEOL_inCdn;

   if (  (FTPCTL_bMemFirstFillFuEngPrev1 != 0)
      && (FTPCTL_bMemFirstFillFuEngPrev2 == 0))
   {
      FTPCTL_u16outputcounter = 0;
   }
   else
   {
      if (FTPCTL_bEOL_outCdn != 0)
      {
         u32LocalInc = (uint32)( FTPCTL_u16outputcounter
                               + FTPCtl_ctFirstCmdTmrInc_MP);
         FTPCTL_u16outputcounter = (uint16)MATHSRV_udtMIN(u32LocalInc, 65535);
      }
   }

   if (FTPCtl_ctFirstCmdFuPmpTmr >= FTPCtl_ctFirstAcvFuPmp_C)
   {
      FTPCtl_bFirstCmdFuPmpTmrMax = 1;
   }
   else
   {
      FTPCtl_bFirstCmdFuPmpTmrMax = 0;
   }
   FTPCTL_bMemFirstFillFuEngPrev2 = FTPCTL_bMemFirstFillFuEngPrev1;
   VEMS_vidGET(Afts_bRstMemFirstFillFuEng, FTPCTL_bMemFirstFillFuEngPrev1);
   FTPCtl_ctFirstCmdFuPmpTmr = FTPCTL_u16outputcounter;
   FTPCTL_u16IniCdnOutput = 1;
   FTPCTL_bEOLStateTimerCond = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FTPCTL_vidPressHoldCaseCutStall                            */
/* !Description :  This stateflow manages the different life situation of the */
/*                 vehicle where the engine feeding of fuel shall be prepared.*/
/* !Number      :  FCT2.3                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_11_02548_014.02                                     */
/*                 VEMS_R_11_02548_015.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint32 EOM_tiEngStop;                                               */
/*  input boolean FTPCtl_bAcvPmpWkuPha;                                       */
/*  input st123 FTPCtl_stEngCutStall;                                         */
/*  input uint16 FTPCtl_ctCutStallLdMem;                                      */
/*  input uint16 FTPCtl_rFlowNom_C;                                           */
/*  input boolean FTPCtl_bEngCutStall;                                        */
/*  input boolean FTPCtl_bMemFirstFillFu;                                     */
/*  input boolean FTPCtl_bFirstCmdFuPmp;                                      */
/*  input uint16 FTPCtl_rFlowWait_C;                                          */
/*  input boolean FTPCtl_bEngCutStallInter;                                   */
/*  input uint32 FTPCtl_tiVehStop_C;                                          */
/*  input uint16 FTPCtl_rFlowShoStop_C;                                       */
/*  input uint16 FTPCtl_ctAcvShoStopFuPmp_C;                                  */
/*  input uint16 FTPCtl_rFlowLgStop_C;                                        */
/*  input uint16 FTPCtl_ctAcvPmpEngCut_C;                                     */
/*  input uint16 FTPCtl_rFlowAcvPrim_C;                                       */
/*  input uint16 FTPCtl_ctAcvPmpCutStall;                                     */
/*  input uint16 FTPCtl_rFlowDeacCyc_C;                                       */
/*  input uint16 FTPCtl_ctWaitAcvPmpCyc_C;                                    */
/*  input boolean FTPCtl_bFirstCmdFuPmpTmrMax;                                */
/*  input uint16 FTPCtl_rFlowFuCutStall;                                      */
/*  input uint16 FTPCtl_rFlowAcvCyc_C;                                        */
/*  input uint16 FTPCtl_ctAcvShoFlowFuPmp_C;                                  */
/*  input uint16 FTPCtl_ctStopPmpCutStall;                                    */
/*  input uint16 FTPCtl_ctEngCutStallLdMem_C;                                 */
/*  output st123 FTPCtl_stEngCutStall;                                        */
/*  output uint16 FTPCtl_ctAcvPmpCutStall;                                    */
/*  output uint16 FTPCtl_rFlowFuCutStall;                                     */
/*  output boolean FTPCtl_bEngCutStallInter;                                  */
/*  output boolean FTPCtl_bFirstCmdFuPmp;                                     */
/*  output uint16 FTPCtl_ctCutStallLdMem;                                     */
/*  output uint16 FTPCtl_ctStopPmpCutStall;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FTPCTL_vidPressHoldCaseCutStall(void)
{
   boolean bLocalFTPCtl_bMemFirstFillFu;
   boolean bLocalFTPCtl_bAcvPmpWkuPha;
   uint8   u8LocalCoPTSt_stEng;
   uint16  u16LocalFTPCtl_ctCutStallLdMem;
   uint16  u16LocalFTPCtl_ctAcvPmpCutStall;
   uint16  u16LocalFTPCtl_ctStopPmpCutStall;
   uint32  u32LocalEOM_tiEngStop;


   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(EOM_tiEngStop, u32LocalEOM_tiEngStop);
   VEMS_vidGET(FTPCtl_bAcvPmpWkuPha, bLocalFTPCtl_bAcvPmpWkuPha);
   switch (FTPCtl_stEngCutStall)
   {
      case ENGCUTSTALL_FIRST_PRIMING_MEMORY:
         if (  (FTPCtl_ctCutStallLdMem == 0)
            && (bLocalFTPCtl_bAcvPmpWkuPha == 0))
         {
            FTPCtl_stEngCutStall = ENGCUTSTALL_WAIT_FOR_WAKE_UP;
         }
         else
         {
            if (  (FTPCtl_ctCutStallLdMem == 0)
               && (bLocalFTPCtl_bAcvPmpWkuPha != 0)
               && (u8LocalCoPTSt_stEng == Coupe_cale))
            {
               FTPCtl_stEngCutStall = ENGCUTSTALL_NOMINAL_PRE_REQUEST;
               FTPCtl_ctAcvPmpCutStall = 0;
               FTPCtl_rFlowFuCutStall =
                  (uint16)MATHSRV_udtMIN(FTPCtl_rFlowNom_C, 1000);
               FTPCtl_bEngCutStallInter = FTPCtl_bEngCutStall;
            }
            else
            {
               VEMS_vidGET(FTPCtl_bMemFirstFillFu, FTPCtl_bFirstCmdFuPmp);
               FTPCtl_bEngCutStallInter = 0;
               if (FTPCtl_ctCutStallLdMem > 0)
               {
                  u16LocalFTPCtl_ctCutStallLdMem =
                     (uint16)(FTPCtl_ctCutStallLdMem - 1);
               }
               else
               {
                  u16LocalFTPCtl_ctCutStallLdMem = 0;
               }
               FTPCtl_ctCutStallLdMem =
                  (uint16)MATHSRV_udtMIN(u16LocalFTPCtl_ctCutStallLdMem, 1000);
            }
         }
         break;

      case ENGCUTSTALL_WAIT_FOR_WAKE_UP:
         if (  (bLocalFTPCtl_bAcvPmpWkuPha != 0)
            && (u8LocalCoPTSt_stEng == Coupe_cale))
         {
            FTPCtl_stEngCutStall = ENGCUTSTALL_NOMINAL_PRE_REQUEST;
            FTPCtl_ctAcvPmpCutStall = 0;
            FTPCtl_rFlowFuCutStall =
               (uint16)MATHSRV_udtMIN(FTPCtl_rFlowNom_C, 1000);
            FTPCtl_bEngCutStallInter = FTPCtl_bEngCutStall;
         }
         else
         {
            FTPCtl_rFlowFuCutStall =
               (uint16)MATHSRV_udtMIN(FTPCtl_rFlowWait_C, 1000);
         }
         break;

      case ENGCUTSTALL_NOMINAL_PRE_REQUEST:
         if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
         {
            FTPCtl_stEngCutStall = ENGCUTSTALL_WAIT_FOR_WAKE_UP;
         }
         else
         {
            if (u8LocalCoPTSt_stEng != Coupe_cale)
            {
               FTPCtl_stEngCutStall = ENGCUTSTALL_WAIT_FOR_WAKE_UP;
            }
            else
            {
               if (  (FTPCtl_bEngCutStallInter == 0)
                  && (u32LocalEOM_tiEngStop < FTPCtl_tiVehStop_C)
                  && (FTPCtl_bFirstCmdFuPmp != 0))
               {
                  FTPCtl_stEngCutStall = ENGCUTSTALL_SHORT_STOP_STATE;
                  FTPCtl_rFlowFuCutStall =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowShoStop_C, 1000);
                  FTPCtl_ctAcvPmpCutStall =
                     (uint16)MATHSRV_udtMIN(FTPCtl_ctAcvShoStopFuPmp_C, 60000);
               }
               else
               {
                  if (  (FTPCtl_bFirstCmdFuPmp != 0)
                     && (  (FTPCtl_bEngCutStallInter != 0)
                        || (  (FTPCtl_bEngCutStall == 0)
                           && (u32LocalEOM_tiEngStop >= FTPCtl_tiVehStop_C))))
                  {
                     FTPCtl_stEngCutStall = ENGCUTSTALL_LONG_STOP_STATE;
                     FTPCtl_rFlowFuCutStall =
                        (uint16)MATHSRV_udtMIN(FTPCtl_rFlowLgStop_C, 1000);
                     FTPCtl_ctAcvPmpCutStall =
                        (uint16)MATHSRV_udtMIN(FTPCtl_ctAcvPmpEngCut_C, 60000);
                     FTPCtl_bEngCutStallInter = 0;
                  }
                  else
                  {
                     VEMS_vidGET(FTPCtl_bMemFirstFillFu,
                                                  bLocalFTPCtl_bMemFirstFillFu);
                     if (bLocalFTPCtl_bMemFirstFillFu == 0)
                     {
                        FTPCtl_stEngCutStall = ENGCUTSTALL_FIRST_PRIMING_STATE;
                        FTPCtl_rFlowFuCutStall =
                           (uint16)MATHSRV_udtMIN(FTPCtl_rFlowAcvPrim_C, 1000);
                     }
                     else
                     {
                        FTPCtl_bEngCutStallInter = FTPCtl_bEngCutStall;
                        FTPCtl_rFlowFuCutStall =
                           (uint16)MATHSRV_udtMIN(FTPCtl_rFlowNom_C, 1000);
                     }
                  }
               }
            }
         }
         break;

      case ENGCUTSTALL_SHORT_STOP_STATE:
         if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
         {
            FTPCtl_stEngCutStall = ENGCUTSTALL_WAIT_FOR_WAKE_UP;
         }
         else
         {
            if (u8LocalCoPTSt_stEng != Coupe_cale)
            {
               FTPCtl_stEngCutStall = ENGCUTSTALL_WAIT_FOR_WAKE_UP;
            }
            else
            {
               if (FTPCtl_ctAcvPmpCutStall == 0)
               {
                  FTPCtl_stEngCutStall = ENGCUTSTALL_PERIODIC_DEACT;
                  FTPCtl_ctStopPmpCutStall = 0;
                  FTPCtl_bFirstCmdFuPmp = 1;
                  FTPCtl_rFlowFuCutStall =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowDeacCyc_C, 1000);
                  FTPCtl_ctAcvPmpCutStall =
                     (uint16)MATHSRV_udtMIN(FTPCtl_ctWaitAcvPmpCyc_C, 60000);
               }
               else
               {
                  FTPCtl_rFlowFuCutStall =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowShoStop_C, 1000);
                  u16LocalFTPCtl_ctAcvPmpCutStall =
                     (uint16)(FTPCtl_ctAcvPmpCutStall - 1);
                  FTPCtl_ctAcvPmpCutStall =
                     (uint16)MATHSRV_udtMIN(u16LocalFTPCtl_ctAcvPmpCutStall,
                                            60000);
               }
            }
         }
         break;

      case ENGCUTSTALL_LONG_STOP_STATE:
         if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
         {
            FTPCtl_stEngCutStall = ENGCUTSTALL_WAIT_FOR_WAKE_UP;
         }
         else
         {
            if (u8LocalCoPTSt_stEng != Coupe_cale)
            {
               FTPCtl_stEngCutStall = ENGCUTSTALL_WAIT_FOR_WAKE_UP;
            }
            else
            {
               if (FTPCtl_ctAcvPmpCutStall == 0 )
               {
                  FTPCtl_stEngCutStall = ENGCUTSTALL_PERIODIC_DEACT;
                  FTPCtl_ctStopPmpCutStall = 0;
                  FTPCtl_bFirstCmdFuPmp = 1;
                  FTPCtl_rFlowFuCutStall =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowDeacCyc_C, 1000);
                  FTPCtl_ctAcvPmpCutStall =
                     (uint16)MATHSRV_udtMIN(FTPCtl_ctWaitAcvPmpCyc_C, 60000);
               }
               else
               {
                  FTPCtl_rFlowFuCutStall =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowLgStop_C, 1000);
                  u16LocalFTPCtl_ctAcvPmpCutStall =
                     (uint16)(FTPCtl_ctAcvPmpCutStall - 1);
                  FTPCtl_ctAcvPmpCutStall =
                     (uint16)MATHSRV_udtMIN(u16LocalFTPCtl_ctAcvPmpCutStall,
                                            60000);
                  FTPCtl_bEngCutStallInter = 0;
               }
            }
         }
         break;

      case ENGCUTSTALL_FIRST_PRIMING_STATE:
         if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
         {
            FTPCtl_stEngCutStall = ENGCUTSTALL_WAIT_FOR_WAKE_UP;
         }
         else
         {
            if (u8LocalCoPTSt_stEng != Coupe_cale)
            {
               FTPCtl_stEngCutStall = ENGCUTSTALL_WAIT_FOR_WAKE_UP;
            }
            else
            {
               VEMS_vidGET(FTPCtl_bMemFirstFillFu,
                           bLocalFTPCtl_bMemFirstFillFu);
               if ( (FTPCtl_bFirstCmdFuPmpTmrMax != 0)
                  ||(bLocalFTPCtl_bMemFirstFillFu != 0))
               {
                  FTPCtl_stEngCutStall = ENGCUTSTALL_PERIODIC_DEACT;
                  FTPCtl_ctStopPmpCutStall = 0;
                  FTPCtl_bFirstCmdFuPmp = 1;
                  FTPCtl_rFlowFuCutStall =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowDeacCyc_C, 1000);
                  FTPCtl_ctAcvPmpCutStall =
                     (uint16)MATHSRV_udtMIN(FTPCtl_ctWaitAcvPmpCyc_C, 60000);
               }
               else
               {
                  FTPCtl_rFlowFuCutStall =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuCutStall, 1000);
               }
            }
         }
         break;

      case ENGCUTSTALL_PERIODIC_DEACT:
         if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
         {
            FTPCtl_stEngCutStall = ENGCUTSTALL_WAIT_FOR_WAKE_UP;
         }
         else
         {
            if (u8LocalCoPTSt_stEng != Coupe_cale)
            {
               FTPCtl_stEngCutStall = ENGCUTSTALL_WAIT_FOR_WAKE_UP;
            }
            else
            {
               if (FTPCtl_ctAcvPmpCutStall == 0)
               {
                  FTPCtl_stEngCutStall = ENGCUTSTALL_PERIODIC_ACT;
                  FTPCtl_ctAcvPmpCutStall = 0;
                  FTPCtl_rFlowFuCutStall =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowAcvCyc_C, 1000);
                  FTPCtl_ctStopPmpCutStall =
                     (uint16)MATHSRV_udtMIN(FTPCtl_ctAcvShoFlowFuPmp_C, 60000);
               }
               else
               {
                  FTPCtl_rFlowFuCutStall =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowDeacCyc_C, 1000);
                  u16LocalFTPCtl_ctAcvPmpCutStall =
                     (uint16)(FTPCtl_ctAcvPmpCutStall - 1);
                  FTPCtl_ctAcvPmpCutStall =
                     (uint16)MATHSRV_udtMIN(u16LocalFTPCtl_ctAcvPmpCutStall,
                                            60000);
               }
            }
         }
         break;

      case ENGCUTSTALL_PERIODIC_ACT:
         if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
         {
            FTPCtl_stEngCutStall = ENGCUTSTALL_WAIT_FOR_WAKE_UP;
         }
         else
         {
            if (u8LocalCoPTSt_stEng != Coupe_cale)
            {
               FTPCtl_stEngCutStall = ENGCUTSTALL_WAIT_FOR_WAKE_UP;
            }
            else
            {
               if (FTPCtl_ctStopPmpCutStall <= 0)
               {
                  FTPCtl_stEngCutStall = ENGCUTSTALL_PERIODIC_DEACT;
                  FTPCtl_ctStopPmpCutStall = 0;
                  FTPCtl_bFirstCmdFuPmp = 1;
                  FTPCtl_rFlowFuCutStall =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowDeacCyc_C, 1000);
                  FTPCtl_ctAcvPmpCutStall =
                     (uint16)MATHSRV_udtMIN(FTPCtl_ctWaitAcvPmpCyc_C, 60000);
               }
               else
               {
                  FTPCtl_rFlowFuCutStall =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowAcvCyc_C, 1000);
                  u16LocalFTPCtl_ctStopPmpCutStall =
                        (uint16)(FTPCtl_ctStopPmpCutStall - 1);
                  FTPCtl_ctStopPmpCutStall =
                     (uint16)MATHSRV_udtMIN(u16LocalFTPCtl_ctStopPmpCutStall,
                                            60000);
               }
            }
         }
         break;

      default:
         FTPCtl_stEngCutStall = ENGCUTSTALL_FIRST_PRIMING_MEMORY;

         VEMS_vidGET(FTPCtl_bMemFirstFillFu, FTPCtl_bFirstCmdFuPmp);
         FTPCtl_bEngCutStallInter = 0;
         FTPCtl_ctCutStallLdMem =
            (uint16)MATHSRV_udtMIN(FTPCtl_ctEngCutStallLdMem_C, 1000);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FTPCTL_vidPressHoldEngineActive                            */
/* !Description :  This stateflow manages the different life situations for   */
/*                 all the engine states except cut/stall.                    */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_11_02548_016.01                                     */
/*                 VEMS_R_11_02548_017.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean FTPCtl_bAcvPmpWkuPha;                                       */
/*  input st121 FTPCtl_stEng;                                                 */
/*  input boolean FTPCtl_bAcvPmpStrt_C;                                       */
/*  input uint16 FTPCtl_rFlowFuEngStrt_C;                                     */
/*  input uint16 FTPCtl_rFlowFuEngPrep_C;                                     */
/*  input uint16 FTPCtl_rFilDec_rFlowFu;                                      */
/*  input uint16 FTPCtl_rFlowFuEngStopPmpStrt_C;                              */
/*  input uint16 FTPCtl_ctAcvPmpSTTStop_C;                                    */
/*  input uint16 FTPCtl_rFlowFuEngRstrt_C;                                    */
/*  input uint16 FTPCtl_ctTmrStopPmpCaseEs;                                   */
/*  input uint16 FTPCtl_rFlowFuEngStopPmpOff_C;                               */
/*  input uint16 FTPCtl_ctWaitAcvPmpSTTStop_C;                                */
/*  input uint16 FTPCtl_ctTmrAcvPmpCaseEs;                                    */
/*  output st121 FTPCtl_stEng;                                                */
/*  output boolean FTPCtl_bEngCutStall;                                       */
/*  output uint16 FTPCtl_rFlowFuDftOnOff;                                     */
/*  output uint16 FTPCtl_rFlowFuDftProp;                                      */
/*  output uint16 FTPCtl_ctTmrStopPmpCaseEs;                                  */
/*  output uint16 FTPCtl_ctTmrAcvPmpCaseEs;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FTPCTL_vidPressHoldEngineActive(void)
{
   boolean bLocalFTPCtl_bAcvPmpWkuPha;
   uint8   u8LocalCoPTSt_stEng;
   uint16  u16LocalFTPCtl_ctTmrStopPmpCaseE;
   uint16  u16LocalFTPCtl_ctTmrAcvPmpCaseE;

   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(FTPCtl_bAcvPmpWkuPha, bLocalFTPCtl_bAcvPmpWkuPha);
   switch (FTPCtl_stEng)
   {
      case ENG_INITIALIZATION:
         if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
         {
            FTPCtl_stEng = ENG_WAIT_FOR_WAKE_UP;
            FTPCtl_bEngCutStall = 0;
         }
         else
         {
            if (u8LocalCoPTSt_stEng == Coupe_cale)
            {
               FTPCtl_stEng = ENG_CUT;
               FTPCtl_rFlowFuDftOnOff = 0;
               FTPCtl_rFlowFuDftProp = 0;
            }
            else
            {
               FTPCtl_rFlowFuDftProp = 0;
               FTPCtl_rFlowFuDftOnOff = 0;
            }
         }
         break;

      case ENG_WAIT_FOR_WAKE_UP:
         if (bLocalFTPCtl_bAcvPmpWkuPha != 0)
         {
            if (u8LocalCoPTSt_stEng == Coupe_cale)
            {
               FTPCtl_stEng = ENG_CUT;
               FTPCtl_rFlowFuDftOnOff = 0;
               FTPCtl_rFlowFuDftProp = 0;
            }
            else
            {
               if (FTPCtl_bAcvPmpStrt_C != 0)
               {
                  FTPCtl_stEng = ENG_DRIVEN_START;
                  FTPCtl_bEngCutStall = 0;
                  FTPCtl_rFlowFuDftProp =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngStrt_C, 1000);
                  FTPCtl_rFlowFuDftOnOff = 1000;
               }
               else
               {
                  FTPCtl_bEngCutStall = 0;
                  FTPCtl_rFlowFuDftProp = 0;
                  FTPCtl_rFlowFuDftOnOff = 0;
               }
            }
         }
         else
         {
            FTPCtl_bEngCutStall = 0;
            FTPCtl_rFlowFuDftProp = 0;
            FTPCtl_rFlowFuDftOnOff = 0;
         }
         break;

      case ENG_STALLED:
         if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
         {
            FTPCtl_stEng = ENG_WAIT_FOR_WAKE_UP;
            FTPCtl_bEngCutStall = 0;
         }
         else
         {
            if (u8LocalCoPTSt_stEng != Coupe_cale)
            {
               FTPCtl_stEng = ENG_DRIVEN_START;
               FTPCtl_bEngCutStall = 0;
               FTPCtl_rFlowFuDftProp =
                  (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngStrt_C, 1000);
               FTPCtl_rFlowFuDftOnOff = 1000;
            }
            else
            {
               FTPCtl_bEngCutStall = 1;
               FTPCtl_rFlowFuDftOnOff = 0;
               FTPCtl_rFlowFuDftProp = 0;
            }
         }
         break;

      case ENG_CUT:
         if (u8LocalCoPTSt_stEng == Preparation)
         {
            FTPCtl_stEng = ENG_PREPARATION;
            FTPCtl_bEngCutStall = 0;
            FTPCtl_rFlowFuDftProp =
               (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngPrep_C, 1000);
            FTPCtl_rFlowFuDftOnOff = 1000;
         }
         else
         {
            if (u8LocalCoPTSt_stEng == Driven_Start)
            {
               FTPCtl_stEng = ENG_DRIVEN_START;
               FTPCtl_bEngCutStall = 0;
               FTPCtl_rFlowFuDftProp =
                  (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngStrt_C, 1000);
               FTPCtl_rFlowFuDftOnOff = 1000;
            }
            else
            {
               if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
               {
                  FTPCtl_stEng = ENG_WAIT_FOR_WAKE_UP;
                  FTPCtl_bEngCutStall = 0;
               }
               else
               {
                  FTPCtl_rFlowFuDftOnOff = 0;
                  FTPCtl_rFlowFuDftProp = 0;
               }
            }
         }
         break;

      case ENG_DRIVEN_START:
         if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
         {
            FTPCtl_stEng = ENG_WAIT_FOR_WAKE_UP;
            FTPCtl_bEngCutStall = 0;
         }
         else
         {
            if (u8LocalCoPTSt_stEng == Coupe_cale)
            {
               FTPCtl_stEng = ENG_STALLED;
               FTPCtl_bEngCutStall = 1;
               FTPCtl_rFlowFuDftOnOff = 0;
               FTPCtl_rFlowFuDftProp = 0;
            }
            else
            {
               if (u8LocalCoPTSt_stEng == Engine_Running)
               {
                  FTPCtl_stEng = ENG_ENGINE_RUNNING;
                  FTPCtl_ctTmrStopPmpCaseEs = 0;
                  FTPCtl_rFlowFuDftProp =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFilDec_rFlowFu, 1000);
                  FTPCtl_rFlowFuDftOnOff = 1000;
               }
               else
               {
                  FTPCtl_rFlowFuDftProp =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngStrt_C, 1000);
                  FTPCtl_rFlowFuDftOnOff = 1000;
                  FTPCtl_bEngCutStall = 0;
               }
            }
         }
         break;

      case ENG_PREPARATION:
         if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
         {
            FTPCtl_stEng = ENG_WAIT_FOR_WAKE_UP;
            FTPCtl_bEngCutStall = 0;
         }
         else
         {
            if (u8LocalCoPTSt_stEng == Coupe_cale)
            {
               FTPCtl_stEng = ENG_STALLED;
               FTPCtl_bEngCutStall = 1;
               FTPCtl_rFlowFuDftOnOff = 0;
               FTPCtl_rFlowFuDftProp = 0;
            }
            else
            {
               if (u8LocalCoPTSt_stEng == Driven_Start)
               {
                  FTPCtl_stEng = ENG_DRIVEN_START;
                  FTPCtl_rFlowFuDftProp =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngStrt_C, 1000);
                  FTPCtl_rFlowFuDftOnOff = 1000;
               }
               else
               {
                  FTPCtl_rFlowFuDftProp =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngPrep_C, 1000);
                  FTPCtl_rFlowFuDftOnOff = 1000;
                  FTPCtl_bEngCutStall = 0;
               }
            }
         }
         break;

      case ENG_ENGINE_RUNNING:
         if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
         {
            FTPCtl_stEng = ENG_WAIT_FOR_WAKE_UP;
            FTPCtl_bEngCutStall = 0;
         }
         else
         {
            if (u8LocalCoPTSt_stEng == Coupe_cale)
            {
               FTPCtl_stEng = ENG_STALLED;
               FTPCtl_bEngCutStall = 1;
               FTPCtl_rFlowFuDftOnOff = 0;
               FTPCtl_rFlowFuDftProp = 0;
            }
            else
            {
               if (u8LocalCoPTSt_stEng == Driven_Start)
               {
                  FTPCtl_stEng = ENG_DRIVEN_START;
                  FTPCtl_rFlowFuDftProp =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngStrt_C, 1000);
                  FTPCtl_rFlowFuDftOnOff = 1000;
               }
               else
               {
                  if (u8LocalCoPTSt_stEng == Stop)
                  {
                     FTPCtl_stEng = ENG_STOP_ACTIVATION;
                     FTPCtl_rFlowFuDftProp =
                        (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngStopPmpStrt_C,
                                               1000);
                     FTPCtl_rFlowFuDftOnOff = 1000;
                     FTPCtl_ctTmrStopPmpCaseEs =
                        (uint16)MATHSRV_udtMIN(FTPCtl_ctAcvPmpSTTStop_C, 60000);
                  }
                  else
                  {
                     FTPCtl_rFlowFuDftProp =
                        (uint16)MATHSRV_udtMIN(FTPCtl_rFilDec_rFlowFu, 1000);
                     FTPCtl_rFlowFuDftOnOff = 1000;
                     FTPCtl_bEngCutStall = 0;
                  }
               }
            }
         }
         break;

      case ENG_DRIVE_RESTART:
         if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
         {
            FTPCtl_stEng = ENG_WAIT_FOR_WAKE_UP;
            FTPCtl_bEngCutStall = 0;
         }
         else
         {
            if (u8LocalCoPTSt_stEng == Coupe_cale)
            {
               FTPCtl_stEng = ENG_STALLED;
               FTPCtl_bEngCutStall = 1;
               FTPCtl_rFlowFuDftOnOff = 0;
               FTPCtl_rFlowFuDftProp = 0;
            }
            else
            {
               if (u8LocalCoPTSt_stEng == Stop )
               {
                  FTPCtl_stEng = ENG_STOP_ACTIVATION;
                  FTPCtl_rFlowFuDftProp =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngStopPmpStrt_C,
                                            1000);
                  FTPCtl_rFlowFuDftOnOff = 1000;
                  FTPCtl_ctTmrStopPmpCaseEs =
                     (uint16)MATHSRV_udtMIN(FTPCtl_ctAcvPmpSTTStop_C, 60000);
               }
               else
               {
                  if (u8LocalCoPTSt_stEng == Engine_Running)
                  {
                     FTPCtl_stEng = ENG_ENGINE_RUNNING;
                     FTPCtl_ctTmrStopPmpCaseEs = 0;
                     FTPCtl_rFlowFuDftProp =
                        (uint16)MATHSRV_udtMIN(FTPCtl_rFilDec_rFlowFu, 1000);
                     FTPCtl_rFlowFuDftOnOff = 1000;
                  }
                  else
                  {
                     FTPCtl_rFlowFuDftProp =
                        (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngRstrt_C, 1000);
                     FTPCtl_rFlowFuDftOnOff = 1000;
                     FTPCtl_bEngCutStall = 0;
                  }
               }
            }
         }
         break;

      case ENG_STOP_ACTIVATION:
         if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
         {
            FTPCtl_stEng = ENG_WAIT_FOR_WAKE_UP;
            FTPCtl_bEngCutStall = 0;
         }
         else
         {
            if (u8LocalCoPTSt_stEng == Coupe_cale)
            {
               FTPCtl_stEng = ENG_STALLED;
               FTPCtl_bEngCutStall = 1;
               FTPCtl_rFlowFuDftOnOff = 0;
               FTPCtl_rFlowFuDftProp = 0;
            }
            else
            {
               if (u8LocalCoPTSt_stEng == Driven_Restart)
               {
                  FTPCtl_stEng = ENG_DRIVE_RESTART;
                  FTPCtl_ctTmrStopPmpCaseEs = 0;
                  FTPCtl_rFlowFuDftProp =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngRstrt_C, 1000);
                  FTPCtl_rFlowFuDftOnOff = 1000;
               }
               else
               {
                  if (FTPCtl_ctTmrStopPmpCaseEs <= 0)
                  {
                     FTPCtl_stEng = ENG_STOP_WAIT;
                     FTPCtl_ctTmrStopPmpCaseEs = 0;
                     FTPCtl_rFlowFuDftProp =
                        (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngStopPmpOff_C,
                                               1000);
                     FTPCtl_rFlowFuDftOnOff = 0;
                     FTPCtl_ctTmrAcvPmpCaseEs =
                        (uint16)MATHSRV_udtMIN(FTPCtl_ctWaitAcvPmpSTTStop_C,
                                               60000);
                  }
                  else
                  {
                     u16LocalFTPCtl_ctTmrStopPmpCaseE =
                           (uint16)(FTPCtl_ctTmrStopPmpCaseEs - 1);
                     FTPCtl_ctTmrStopPmpCaseEs =
                        (uint16)MATHSRV_udtMIN(u16LocalFTPCtl_ctTmrStopPmpCaseE,
                                               60000);
                     FTPCtl_rFlowFuDftProp =
                        (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngStopPmpStrt_C,
                                               1000);
                     FTPCtl_rFlowFuDftOnOff = 1000;
                     FTPCtl_bEngCutStall = 0;
                  }
               }
            }
         }
         break;

      case ENG_STOP_WAIT:
         if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
         {
            FTPCtl_stEng = ENG_WAIT_FOR_WAKE_UP;
            FTPCtl_bEngCutStall = 0;
         }
         else
         {
            if (u8LocalCoPTSt_stEng == Coupe_cale)
            {
               FTPCtl_stEng = ENG_STALLED;
               FTPCtl_bEngCutStall = 1;
               FTPCtl_rFlowFuDftOnOff = 0;
               FTPCtl_rFlowFuDftProp = 0;
            }
            else
            {
               if (u8LocalCoPTSt_stEng == Driven_Restart)
               {
                  FTPCtl_stEng = ENG_DRIVE_RESTART;
                  FTPCtl_ctTmrStopPmpCaseEs = 0;
                  FTPCtl_rFlowFuDftProp =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngRstrt_C, 1000);
                  FTPCtl_rFlowFuDftOnOff = 1000;
               }
               else
               {
                  if (FTPCtl_ctTmrAcvPmpCaseEs <= 0)
                  {
                     FTPCtl_stEng = ENG_STOP_ACTIVATION;
                     FTPCtl_rFlowFuDftProp =
                        (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngStopPmpStrt_C,
                                               1000);
                     FTPCtl_rFlowFuDftOnOff = 1000;
                     FTPCtl_ctTmrStopPmpCaseEs =
                        (uint16)MATHSRV_udtMIN(FTPCtl_ctAcvPmpSTTStop_C, 60000);
                  }
                  else
                  {
                     u16LocalFTPCtl_ctTmrAcvPmpCaseE =
                        (uint16)(FTPCtl_ctTmrAcvPmpCaseEs - 1);
                     FTPCtl_ctTmrAcvPmpCaseEs =
                        (uint16)MATHSRV_udtMIN(u16LocalFTPCtl_ctTmrAcvPmpCaseE,
                                               60000);
                     FTPCtl_rFlowFuDftProp =
                        (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngStopPmpOff_C,
                                               1000);
                     FTPCtl_rFlowFuDftOnOff = 0;
                     FTPCtl_bEngCutStall = 0;
                  }
               }
            }
         }
         break;

      default:
         FTPCtl_stEng = ENG_INITIALIZATION;
         FTPCtl_rFlowFuDftProp = 0;
         FTPCtl_rFlowFuDftOnOff = 0;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FTPCTL_vidPressure_hold_in_gas                             */
/* !Description :  This stateflow manages the transitions to the gas fuel for */
/*                 vehicle that need it.  It works in case of mono or         */
/*                 bi-fueling.                                                */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_11_02548_018.01                                     */
/*                 VEMS_R_11_02548_019.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input boolean FTPCtl_bAcvPmpWkuPha;                                       */
/*  input st122 FTPCtl_stCaseEngAlt;                                          */
/*  input uint16 FTPCtl_rFilDec_rFlowFu;                                      */
/*  input uint16 FTPCtl_rFlowFuEngrunFuChgGas_C;                              */
/*  input uint16 FTPCtl_ctTranForcGasChgFu;                                   */
/*  input uint16 FTPCtl_rFlowFuForcGasChgFu_C;                                */
/*  input uint16 FTPCtl_rFlowFuEngrunGas_C;                                   */
/*  input uint16 FTPCtl_ctAcvPmpEngrunGas_C;                                  */
/*  input uint16 FTPCtl_ctWaitPmpEngrunGasFu_C;                               */
/*  input uint16 FTPCtl_rFlowFuEngrunGasChgFu_C;                              */
/*  input uint16 FTPCtl_ctAcvPmpEngRunCaseAfu;                                */
/*  input uint16 FTPCtl_rFlowFuEngrunGasWait_C;                               */
/*  input uint16 FTPCtl_ctWaitPmpEngrunGas_C;                                 */
/*  input uint16 FTPCtl_ctStopPmpEngRunAfu;                                   */
/*  output st122 FTPCtl_stCaseEngAlt;                                         */
/*  output uint16 FTPCtl_rFlowFuEngRunEngAfu;                                 */
/*  output uint16 FTPCtl_ctTranForcGasChgFu;                                  */
/*  output uint16 FTPCtl_ctStopPmpEngRunAfu;                                  */
/*  output uint16 FTPCtl_ctAcvPmpEngRunCaseAfu;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FTPCTL_vidPressure_hold_in_gas(void)
{
   boolean bLocalFTPCtl_bAcvPmpWkuPha;
   uint8   u8LocalCoPTSt_stEng;
   uint8   u8LocalExt_stSysGas;
   uint16  u16LocalFTPCtl_ctTranForcGasChgF;
   uint16  u16LocalFTPCtl_ctAcvPmpEngRunCas;
   uint16  u16LocalFTPCtl_ctStopPmpEngRunAf;

   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   VEMS_vidGET(FTPCtl_bAcvPmpWkuPha, bLocalFTPCtl_bAcvPmpWkuPha);
   switch (FTPCtl_stCaseEngAlt)
   {
      case CASEENGALT_INITIALIZATION:
         if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
         {
            FTPCtl_stCaseEngAlt = CASEENGALT_WAIT_FOR_WAKE_UP;
         }
         else
         {
            FTPCtl_stCaseEngAlt = CASEENGALT_ENGINE_RUNNING_PETROL;
            FTPCtl_rFlowFuEngRunEngAfu =
               (uint16)MATHSRV_udtMIN(FTPCtl_rFilDec_rFlowFu, 1000);
         }
         break;

      case CASEENGALT_WAIT_FOR_WAKE_UP:
         if (bLocalFTPCtl_bAcvPmpWkuPha != 0)
         {
            FTPCtl_stCaseEngAlt = CASEENGALT_ENGINE_RUNNING_PETROL;
            FTPCtl_rFlowFuEngRunEngAfu =
               (uint16)MATHSRV_udtMIN(FTPCtl_rFilDec_rFlowFu, 1000);
         }
         else
         {
            FTPCtl_rFlowFuEngRunEngAfu = 0;
         }
         break;

      case CASEENGALT_ENGINE_RUNNING_PETROL:
         if (  (u8LocalCoPTSt_stEng == Engine_Running)
            && (u8LocalExt_stSysGas == essence_vers_gaz))
         {
            FTPCtl_stCaseEngAlt = CASEENGALT_TO_GAS;
            FTPCtl_rFlowFuEngRunEngAfu =
               (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngrunFuChgGas_C, 1000);
         }
         else
         {
            if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
            {
               FTPCtl_stCaseEngAlt = CASEENGALT_WAIT_FOR_WAKE_UP;
            }
            else
            {
               FTPCtl_rFlowFuEngRunEngAfu =
                  (uint16)MATHSRV_udtMIN(FTPCtl_rFilDec_rFlowFu, 1000);
            }
         }
         break;

      case CASEENGALT_FORCED_TO_PETROL:
         if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
         {
            FTPCtl_stCaseEngAlt = CASEENGALT_WAIT_FOR_WAKE_UP;
         }
         else
         {
            if (u8LocalCoPTSt_stEng != Engine_Running)
            {
               FTPCtl_stCaseEngAlt = CASEENGALT_ENGINE_RUNNING_PETROL;
               FTPCtl_rFlowFuEngRunEngAfu =
                  (uint16)MATHSRV_udtMIN(FTPCtl_rFilDec_rFlowFu, 1000);
            }
            else
            {
               if (FTPCtl_ctTranForcGasChgFu == 0)
               {
                  FTPCtl_stCaseEngAlt = CASEENGALT_ENGINE_RUNNING_PETROL;
                  FTPCtl_rFlowFuEngRunEngAfu =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFilDec_rFlowFu, 1000);
               }
               else
               {
                  if (u8LocalExt_stSysGas == essence_vers_gaz)
                  {
                     FTPCtl_stCaseEngAlt = CASEENGALT_TO_GAS;
                     FTPCtl_rFlowFuEngRunEngAfu =
                        (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngrunFuChgGas_C,
                                               1000);
                  }
                  else
                  {
                     FTPCtl_rFlowFuEngRunEngAfu =
                        (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuForcGasChgFu_C,
                                               1000);
                     u16LocalFTPCtl_ctTranForcGasChgF =
                        (uint16)(FTPCtl_ctTranForcGasChgFu - 1);
                     FTPCtl_ctTranForcGasChgFu =
                        (uint16)MATHSRV_udtMIN(u16LocalFTPCtl_ctTranForcGasChgF,
                                               1000);
                  }
               }
            }
         }
         break;
      case CASEENGALT_TO_GAS:
         if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
         {
            FTPCtl_stCaseEngAlt = CASEENGALT_WAIT_FOR_WAKE_UP;
         }
         else
         {
            if (u8LocalCoPTSt_stEng != Engine_Running)
            {
               FTPCtl_stCaseEngAlt = CASEENGALT_ENGINE_RUNNING_PETROL;
               FTPCtl_rFlowFuEngRunEngAfu =
                  (uint16)MATHSRV_udtMIN(FTPCtl_rFilDec_rFlowFu, 1000);
            }
            else
            {
               if (u8LocalExt_stSysGas==gaz)
               {
                  FTPCtl_stCaseEngAlt = CASEENGALT_GAS_ACTIVATION;
                  FTPCtl_ctStopPmpEngRunAfu = 0;
                  FTPCtl_rFlowFuEngRunEngAfu =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngrunGas_C, 1000);
                  FTPCtl_ctAcvPmpEngRunCaseAfu =
                     (uint16)MATHSRV_udtMIN(FTPCtl_ctAcvPmpEngrunGas_C, 60000);
               }
               else
               {
                  if (u8LocalExt_stSysGas == essence)
                  {
                     FTPCtl_stCaseEngAlt = CASEENGALT_FORCED_TO_PETROL;
                     FTPCtl_rFlowFuEngRunEngAfu =
                        (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuForcGasChgFu_C,
                                               1000);
                     FTPCtl_ctTranForcGasChgFu =
                        (uint16)MATHSRV_udtMIN(FTPCtl_ctWaitPmpEngrunGasFu_C,
                                               1000);
                  }
                  else
                  {
                     if (u8LocalExt_stSysGas == gaz_vers_essence)
                     {
                        FTPCtl_stCaseEngAlt = CASEENGALT_NOMINAL_TO_PETROL;
                        FTPCtl_rFlowFuEngRunEngAfu =
                           (uint16)MATHSRV_udtMIN(
                              FTPCtl_rFlowFuEngrunGasChgFu_C, 1000);
                     }
                     else
                     {
                        FTPCtl_rFlowFuEngRunEngAfu =
                           (uint16)MATHSRV_udtMIN(
                              FTPCtl_rFlowFuEngrunFuChgGas_C, 1000);
                     }
                  }
               }
            }
         }
         break;

      case CASEENGALT_NOMINAL_TO_PETROL:
         if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
         {
            FTPCtl_stCaseEngAlt = CASEENGALT_WAIT_FOR_WAKE_UP;
         }
         else
         {
            if (u8LocalCoPTSt_stEng != Engine_Running)
            {
               FTPCtl_stCaseEngAlt = CASEENGALT_ENGINE_RUNNING_PETROL;
               FTPCtl_rFlowFuEngRunEngAfu =
                  (uint16)MATHSRV_udtMIN(FTPCtl_rFilDec_rFlowFu, 1000);
            }
            else
            {
               if (u8LocalExt_stSysGas == essence)
               {
                  FTPCtl_stCaseEngAlt = CASEENGALT_ENGINE_RUNNING_PETROL;
                  FTPCtl_rFlowFuEngRunEngAfu =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFilDec_rFlowFu, 1000);
               }
               else
               {
                  if (u8LocalExt_stSysGas == essence_vers_gaz)
                  {
                     FTPCtl_stCaseEngAlt = CASEENGALT_TO_GAS;
                     FTPCtl_rFlowFuEngRunEngAfu =
                        (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngrunFuChgGas_C,
                                               1000);
                  }
                  else
                  {
                     FTPCtl_rFlowFuEngRunEngAfu =
                        (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngrunGasChgFu_C,
                                               1000);
                  }
               }
            }
         }
         break;

      case CASEENGALT_GAS_ACTIVATION:
         if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
         {
            FTPCtl_stCaseEngAlt = CASEENGALT_WAIT_FOR_WAKE_UP;
         }
         else
         {
            if (u8LocalCoPTSt_stEng != Engine_Running)
            {
               FTPCtl_stCaseEngAlt = CASEENGALT_ENGINE_RUNNING_PETROL;
               FTPCtl_rFlowFuEngRunEngAfu =
                  (uint16)MATHSRV_udtMIN(FTPCtl_rFilDec_rFlowFu, 1000);
            }
            else
            {
               if (u8LocalExt_stSysGas == essence)
               {
                  FTPCtl_stCaseEngAlt = CASEENGALT_FORCED_TO_PETROL;
                  FTPCtl_rFlowFuEngRunEngAfu =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuForcGasChgFu_C, 1000);
                  FTPCtl_ctTranForcGasChgFu =
                     (uint16)MATHSRV_udtMIN(FTPCtl_ctWaitPmpEngrunGasFu_C,
                                            1000);
               }
               else
               {
                  if (u8LocalExt_stSysGas == gaz_vers_essence)
                  {
                     FTPCtl_stCaseEngAlt = CASEENGALT_NOMINAL_TO_PETROL;
                     FTPCtl_rFlowFuEngRunEngAfu =
                        (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngrunGasChgFu_C,
                                               1000);
                  }
                  else
                  {
                     if (FTPCtl_ctAcvPmpEngRunCaseAfu <= 0)
                     {
                        FTPCtl_stCaseEngAlt = CASEENGALT_GAS_WAIT;
                        FTPCtl_ctAcvPmpEngRunCaseAfu = 0;
                        FTPCtl_rFlowFuEngRunEngAfu =
                           (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngrunGasWait_C,
                                                  1000);
                        FTPCtl_ctStopPmpEngRunAfu =
                           (uint16)MATHSRV_udtMIN(FTPCtl_ctWaitPmpEngrunGas_C,
                                                  60000);
                     }
                     else
                     {
                        FTPCtl_rFlowFuEngRunEngAfu =
                           (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngrunGas_C,
                                                  1000);
                        u16LocalFTPCtl_ctAcvPmpEngRunCas =
                           (uint16)(FTPCtl_ctAcvPmpEngRunCaseAfu - 1);
                        FTPCtl_ctAcvPmpEngRunCaseAfu =
                           (uint16)MATHSRV_udtMIN(
                              u16LocalFTPCtl_ctAcvPmpEngRunCas,
                              60000);
                     }
                  }
               }
            }
         }
         break;

      case CASEENGALT_GAS_WAIT:
         if (bLocalFTPCtl_bAcvPmpWkuPha == 0)
         {
            FTPCtl_stCaseEngAlt = CASEENGALT_WAIT_FOR_WAKE_UP;
         }
         else
         {
            if (u8LocalCoPTSt_stEng != Engine_Running)
            {
               FTPCtl_stCaseEngAlt = CASEENGALT_ENGINE_RUNNING_PETROL;
               FTPCtl_rFlowFuEngRunEngAfu =
                  (uint16)MATHSRV_udtMIN(FTPCtl_rFilDec_rFlowFu, 1000);
            }
            else
            {
               if (u8LocalExt_stSysGas == essence)
               {
                  FTPCtl_stCaseEngAlt = CASEENGALT_FORCED_TO_PETROL;
                  FTPCtl_rFlowFuEngRunEngAfu =
                     (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuForcGasChgFu_C, 1000);
                  FTPCtl_ctTranForcGasChgFu =
                     (uint16)MATHSRV_udtMIN(FTPCtl_ctWaitPmpEngrunGasFu_C,
                                            1000);
               }
               else
               {
                  if (u8LocalExt_stSysGas == gaz_vers_essence)
                  {
                     FTPCtl_stCaseEngAlt = CASEENGALT_NOMINAL_TO_PETROL;
                     FTPCtl_rFlowFuEngRunEngAfu =
                        (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngrunGasChgFu_C,
                                               1000);
                  }
                  else
                  {
                     if (FTPCtl_ctStopPmpEngRunAfu <= 0)
                     {
                        FTPCtl_stCaseEngAlt = CASEENGALT_GAS_ACTIVATION;
                        FTPCtl_ctStopPmpEngRunAfu = 0;
                        FTPCtl_rFlowFuEngRunEngAfu =
                           (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngrunGas_C,
                                                  1000);
                        FTPCtl_ctAcvPmpEngRunCaseAfu =
                           (uint16)MATHSRV_udtMIN(FTPCtl_ctAcvPmpEngrunGas_C,
                                                  60000);
                     }
                     else
                     {
                        FTPCtl_rFlowFuEngRunEngAfu =
                           (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngrunGasWait_C,
                                                  1000);
                        u16LocalFTPCtl_ctStopPmpEngRunAf =
                              (uint16)(FTPCtl_ctStopPmpEngRunAfu - 1);
                        FTPCtl_ctStopPmpEngRunAfu =
                           (uint16)MATHSRV_udtMIN(
                              u16LocalFTPCtl_ctStopPmpEngRunAf,
                              60000);
                     }
                  }
               }
            }
         }
         break;

         default:
         FTPCtl_stCaseEngAlt = CASEENGALT_INITIALIZATION;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FTPCTL_vidFlowSetpointSynthesis                            */
/* !Description :  This subfunction synthesizes ratio setpoints, depending on */
/*                 the engine state. It takes also into account the on/off    */
/*                 pump to be generic.                                        */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_11_02548_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint8 FTPCtl_noStEngAdpNbEng_C;                                     */
/*  input uint16 FTPCtl_rFlowFuCutStall;                                      */
/*  input uint16 FTPCtl_rFlowFuEngRunEngAfu;                                  */
/*  input boolean FTPCtl_bCfPmpOnOff_C;                                       */
/*  input uint16 FTPCtl_rFlowFuDftOnOff;                                      */
/*  input uint16 FTPCtl_rFlowFuDftProp;                                       */
/*  output uint16 FTPCtl_rFlowFuEngStAfuHyb;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FTPCTL_vidFlowSetpointSynthesis(void)
{
   uint8  u8LocalCoPTSt_stEng;
   sint16 s16LocalSwitch;


   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   s16LocalSwitch = (sint16)(u8LocalCoPTSt_stEng - FTPCtl_noStEngAdpNbEng_C);
   switch (s16LocalSwitch)
   {
      case 0:
         FTPCtl_rFlowFuEngStAfuHyb =
            (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuCutStall, 1000);
         break;
      case 4:
         FTPCtl_rFlowFuEngStAfuHyb =
            (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngRunEngAfu, 1000);
         break;

      case 1:
      case 2:
      case 3:
      case 5:
      case 6:
      case 7:
         if (FTPCtl_bCfPmpOnOff_C != 0)
         {
            FTPCtl_rFlowFuEngStAfuHyb =
               (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuDftOnOff, 1000);
         }
         else
         {
            FTPCtl_rFlowFuEngStAfuHyb =
               (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuDftProp, 1000);
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FTPCTL_vidRecovryModesActivation                           */
/* !Description :  This subfunction manages the applications of diverse       */
/*                 recovery modes concerning the fuel pump.                   */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_11_02548_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean FTPCtl_bAcvPmpWkuPha;                                       */
/*  input uint16 FTPCtl_rFlowFuHiDft_C;                                       */
/*  input uint16 FTPCtl_rFlowFuLoDft_C;                                       */
/*  input uint16 FTPCtl_rFlowFuEngStAfuHyb;                                   */
/*  output uint16 FTPCtl_rFlowFuTnkPmp;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FTPCTL_vidRecovryModesActivation(void)
{
   boolean bLocalFTPCtl_bAcvPmpWkuPha;
   boolean bLocalRatFuPmpHiCaseDft;
   boolean bLocalRatFuPmpLoCaseDft;
   boolean bLocalInputXor1;
   boolean bLocalInputXor2;
   uint16  u16LocalFTPCtl_rFlowFuTnkPmp;

   VEMS_vidGET(FTPCtl_bAcvPmpWkuPha, bLocalFTPCtl_bAcvPmpWkuPha);

   bLocalRatFuPmpHiCaseDft = GDGAR_bGetFRM(FRM_FRM_RATFUPMPHICASEDFT);
   bLocalRatFuPmpLoCaseDft = GDGAR_bGetFRM(FRM_FRM_RATFUPMPLOCASEDFT);

   if (  (bLocalRatFuPmpHiCaseDft != 0)
      && (bLocalFTPCtl_bAcvPmpWkuPha != 0))
   {
      u16LocalFTPCtl_rFlowFuTnkPmp = FTPCtl_rFlowFuHiDft_C;
      bLocalInputXor1 = 1;
   }
   else
   {
      u16LocalFTPCtl_rFlowFuTnkPmp = FTPCtl_rFlowFuLoDft_C;
      bLocalInputXor1 = 0;
   }
   if (  (bLocalRatFuPmpLoCaseDft != 0)
      && (bLocalFTPCtl_bAcvPmpWkuPha != 0))
   {
      bLocalInputXor2 = 1;
   }
   else
   {
      bLocalInputXor2 = 0;
   }

   if (  (  (bLocalInputXor1 != 0)
         && (bLocalInputXor2 == 0))
      || (  (bLocalInputXor1 == 0)
         && (bLocalInputXor2 != 0)))
   {
      u16LocalFTPCtl_rFlowFuTnkPmp =
         (uint16)MATHSRV_udtMIN(u16LocalFTPCtl_rFlowFuTnkPmp, 1000);
   }
   else
   {
      u16LocalFTPCtl_rFlowFuTnkPmp =
         (uint16)MATHSRV_udtMIN(FTPCtl_rFlowFuEngStAfuHyb, 1000);
   }
   VEMS_vidSET(FTPCtl_rFlowFuTnkPmp, u16LocalFTPCtl_rFlowFuTnkPmp);
}

/*---------------------------------end of file--------------------------------*/