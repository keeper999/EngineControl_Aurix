/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRSFTYMNG                                              */
/* !Description     : THRSFTYMNG Component                                    */
/*                                                                            */
/* !Module          : THRSFTYMNG                                              */
/* !Description     : GESTION DES DIVERSITES                                  */
/*                                                                            */
/* !File            : THRSFTYMNG_FCT1.C                                       */
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
/*   1 / THRSFTYMNG_vidInitOutput                                             */
/*   2 / THRSFTYMNG_vidMcwdgInit                                              */
/*   3 / THRSFTYMNG_vidMcwdgInhTestStrt                                       */
/*   4 / THRSFTYMNG_vidMcwdgInhTestCdn                                        */
/*   5 / THRSFTYMNG_vidMCWDGFuncTestRslt                                      */
/*   6 / THRSFTYMNG_vidDfltApplicLimpHome                                     */
/*   7 / THRSFTYMNG_vidDfltMCWDGFuncTest                                      */
/*   8 / THRSFTYMNG_vidMcwdgInhTestAbort                                      */
/*                                                                            */
/* !Reference   : V02 NT 11 03549 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#063742                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRSFTYMNG/THRSFTYMNG_FCT1.C$*/
/* $Revision::   1.12     $$Author::   etsasson       $$Date::   25 Oct 2012 $*/
/* $Author::   etsasson                               $$Date::   25 Oct 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THRSFTYMNG.h"
#include "THRSFTYMNG_L.h"
#include "THRSFTYMNG_IM.h"
#include "DGOHAL.h"
#include "GDGAR.h"
#include "MCWDG.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYMNG_vidInitOutput                                   */
/* !Description :  Setting Outputs at Reset                                   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean THRSFTYMNG_bInhMngThrServPrev;                             */
/*  output boolean THRSFTYMNG_bTimer2Prev;                                    */
/*  output boolean THRSFTYMNG_bTimeOut1;                                      */
/*  output boolean THRSFTYMNG_bTimeOut2;                                      */
/*  output uint16 THRSFTYMNG_u16Timer1;                                       */
/*  output uint16 THRSFTYMNG_u16Timer2;                                       */
/*  output boolean Sfty_bDgoElDiagInhPin0_Cpu;                                */
/*  output boolean Sfty_bMonRunElDiagInhPin0_Cpu;                             */
/*  output boolean Sfty_bDgoElDiagInhPin1_Cpu;                                */
/*  output boolean Sfty_bMonRunElDiagInhPin1_Cpu;                             */
/*  output boolean Sfty_bDgoMcpRAMTest_Cpu;                                   */
/*  output boolean Sfty_bMonRunMcpRAMTest_Cpu;                                */
/*  output boolean Sfty_bDgoMcpFlashCks_Cpu;                                  */
/*  output boolean Sfty_bMonRunMcpFlashCks_Cpu;                               */
/*  output boolean Sfty_bDgoMcwCksCalc_Cpu;                                   */
/*  output boolean Sfty_bMonRunMcwCksCalc_Cpu;                                */
/*  output boolean Sfty_bDgoMcwInitSftyRslt_Cpu;                              */
/*  output boolean Sfty_bMonRunMcwInitSftyRslt_Cpu;                           */
/*  output boolean Sfty_bDgoMcwFctTest_Cpu;                                   */
/*  output boolean Sfty_bMonRunMcwFctTest_Cpu;                                */
/*  output boolean Thr_bCdnTestInh_CpuSfty;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYMNG_vidInitOutput(void)
{
   THRSFTYMNG_bInhMngThrServPrev = 0;
   THRSFTYMNG_bTimer2Prev = 0;
   THRSFTYMNG_bTimeOut1 = 0;
   THRSFTYMNG_bTimeOut2 = 0;
   THRSFTYMNG_u16Timer1 = 0;
   THRSFTYMNG_u16Timer2 = 0;
   Sfty_bDgoElDiagInhPin0_Cpu = 0;
   Sfty_bMonRunElDiagInhPin0_Cpu = 0;
   Sfty_bDgoElDiagInhPin1_Cpu = 0;
   Sfty_bMonRunElDiagInhPin1_Cpu = 0;
   Sfty_bDgoMcpRAMTest_Cpu = 0;
   Sfty_bMonRunMcpRAMTest_Cpu = 0;
   Sfty_bDgoMcpFlashCks_Cpu = 0;
   Sfty_bMonRunMcpFlashCks_Cpu = 0;
   Sfty_bDgoMcwCksCalc_Cpu = 0;
   Sfty_bMonRunMcwCksCalc_Cpu = 0;
   Sfty_bDgoMcwInitSftyRslt_Cpu = 0;
   Sfty_bMonRunMcwInitSftyRslt_Cpu = 0;
   Sfty_bDgoMcwFctTest_Cpu = 0;
   Sfty_bMonRunMcwFctTest_Cpu = 0;
   VEMS_vidSET(Thr_bCdnTestInh_CpuSfty, 0);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYMNG_vidMcwdgInit                                    */
/* !Description :  Après un reste, il est impératif de s’assurer que le test  */
/*                 ne commence pas avant la fin de l’initialisation du hard.  */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Thr_bTestStart_ThrSftyMng;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYMNG_vidMcwdgInit(void)
{
   VEMS_vidSET(Thr_bTestStart_ThrSftyMng, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYMNG_vidMcwdgInhTestStrt                             */
/* !Description :  La fin de l’initialisation du hard est détectée pour       */
/*                 autoriser le commencement du test.                         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Thr_bTestStart_ThrSftyMng;                                 */
/*  output boolean Thr_bTestAbort_ThrSftyMng;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYMNG_vidMcwdgInhTestStrt(void)
{
   VEMS_vidSET(Thr_bTestStart_ThrSftyMng, 1);
   VEMS_vidSET(Thr_bTestAbort_ThrSftyMng, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYMNG_vidMcwdgInhTestCdn                              */
/* !Description :  Ce block définit les conditions de réalisation du          */
/*                 diagnostic.  Le diagnostic peut être désactivé en cas de   */
/*                 défaut système ou de reset à chaud (on se protège contre   */
/*                 une fermeture papillon en roulage).                        */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean EcuSt_bDetHotRst;                                           */
/*  input boolean Thr_bAcvHotRstCdn_CpuSfty;                                  */
/*  output boolean Thr_bCdnTestInh_CpuSfty;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYMNG_vidMcwdgInhTestCdn(void)
{
   boolean bLocalEcuSt_bDetHotRst;
   boolean bLocalInhDiagInhCdnThrCpuSfty;

   VEMS_vidGET(EcuSt_bDetHotRst, bLocalEcuSt_bDetHotRst);
   bLocalInhDiagInhCdnThrCpuSfty =
      GDGAR_bGetFRM(FRM_FRM_INHDIAG_INHCDNTHRCPUSFTY);

   if (  (  (Thr_bAcvHotRstCdn_CpuSfty != 0)
         || (bLocalEcuSt_bDetHotRst == 0))
      && (bLocalInhDiagInhCdnThrCpuSfty == 0))
   {
      VEMS_vidSET(Thr_bCdnTestInh_CpuSfty, 1);
   }
   else
   {
      VEMS_vidSET(Thr_bCdnTestInh_CpuSfty, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYMNG_vidMCWDGFuncTestRslt                            */
/* !Description :  Ce bloc est inhibé si FRM_bInhDiag_inhThrCpuSfty=1.        */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void MCWDG_vidFunctionalTestExchange(argin Std_ReturnType     */
/* stdTestStatus);                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYMNG_vidMCWDGFuncTestRslt(void)
{
   boolean bLocalInhDiagInhThrCpuSfty;

   bLocalInhDiagInhThrCpuSfty = GDGAR_bGetFRM(FRM_FRM_INHDIAG_INHTHRCPUSFTY);

   if (bLocalInhDiagInhThrCpuSfty == 0)
   {
      MCWDG_vidFunctionalTestExchange(E_OK);
   }
   else
   {
      MCWDG_vidFunctionalTestExchange(E_NOT_OK);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYMNG_vidDfltApplicLimpHome                           */
/* !Description :  Cette fonction permet de diagnostiquer une éventuelle non  */
/*                 application d’un demande de retour à la position limp-home */
/*                 du BPM.                                                    */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_R_11_03549_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Thr_bInhMngThrServo;                                        */
/*  input boolean THRSFTYMNG_bInhMngThrServPrev;                              */
/*  input uint16 Tpac_tiDlyDiagDftRetLih;                                     */
/*  input uint16 THRSFTYMNG_u16Timer1;                                        */
/*  input boolean THRSFTYMNG_bTimeOut1;                                       */
/*  input uint16 Tpac_corrected_throttle_position;                            */
/*  input uint16 Ssm_limp_home_throttle_pos;                                  */
/*  input uint8 Ssm_throttle_pos_sensing_status;                              */
/*  input uint16 Thr_posnDriftLihMeasThd1_C;                                  */
/*  input boolean Thr_bMonRunORngSftyDftLih;                                  */
/*  input boolean THRSFTYMNG_bTimer2Prev;                                     */
/*  input uint16 Tpac_tiDlyDetDftRetLih;                                      */
/*  input uint16 THRSFTYMNG_u16Timer2;                                        */
/*  input boolean THRSFTYMNG_bTimeOut2;                                       */
/*  output uint16 THRSFTYMNG_u16Timer1;                                       */
/*  output boolean THRSFTYMNG_bTimeOut1;                                      */
/*  output boolean THRSFTYMNG_bInhMngThrServPrev;                             */
/*  output boolean Thr_bMonRunORngSftyDftLih;                                 */
/*  output boolean ThrSftyMng_bThrPosnLihDrift;                               */
/*  output uint16 THRSFTYMNG_u16Timer2;                                       */
/*  output boolean THRSFTYMNG_bTimeOut2;                                      */
/*  output boolean THRSFTYMNG_bTimer2Prev;                                    */
/*  output boolean Thr_bDgoORngSftyDftLih;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYMNG_vidDfltApplicLimpHome(void)
{
   boolean bLocalInhDiagDftLihCdnThrSfty;
   boolean bLocalThrbInhMngThrServo;
   boolean bLocalCompare;
   boolean bLocalInit;
   boolean bLocalThrSftyMngbThrPosnLihDrift;
   uint16  u16LocalTpaCorrecThrottlePos;
   uint16  u16LocalSsmLimpHomeThrottlePos;
   uint16  u16LocalSsmThlPosSensingStatus;
   uint16  u16LocalXAbsVal;
   sint32  s32LocalXVal;

   VEMS_vidGET(Thr_bInhMngThrServo ,bLocalThrbInhMngThrServo);

   if (  (THRSFTYMNG_bInhMngThrServPrev == 0)
      && (bLocalThrbInhMngThrServo != 0))
   {
      THRSFTYMNG_u16Timer1 = Tpac_tiDlyDiagDftRetLih;
      if (THRSFTYMNG_u16Timer1 == 0)
      {
         THRSFTYMNG_bTimeOut1 = 1;
      }
      else
      {
         THRSFTYMNG_bTimeOut1 = 0;
      }
   }
   else
   {
      if (THRSFTYMNG_u16Timer1 > 0)
      {
         THRSFTYMNG_u16Timer1 =  (uint16)(THRSFTYMNG_u16Timer1 - 1);
         if (THRSFTYMNG_u16Timer1 == 0)
         {
            THRSFTYMNG_bTimeOut1 = 1;
         }
         else
         {
            THRSFTYMNG_bTimeOut1 = 0;
         }
      }
   }
   THRSFTYMNG_bInhMngThrServPrev = bLocalThrbInhMngThrServo;

   bLocalInhDiagDftLihCdnThrSfty =
      GDGAR_bGetFRM(FRM_FRM_INHDIAG_DFTLIHCDNTHRSFTY);

   if (  (bLocalInhDiagDftLihCdnThrSfty == 0)
      && (bLocalThrbInhMngThrServo != 0)
      && (THRSFTYMNG_bTimeOut1 != 0))
   {
      Thr_bMonRunORngSftyDftLih = 1;
   }
   else
   {
      Thr_bMonRunORngSftyDftLih = 0;
   }

   VEMS_vidGET(Tpac_corrected_throttle_position, u16LocalTpaCorrecThrottlePos);
   VEMS_vidGET(Ssm_limp_home_throttle_pos, u16LocalSsmLimpHomeThrottlePos);
   VEMS_vidGET(Ssm_throttle_pos_sensing_status,
      u16LocalSsmThlPosSensingStatus);

   s32LocalXVal = (sint32)( u16LocalTpaCorrecThrottlePos
                          - u16LocalSsmLimpHomeThrottlePos);
   u16LocalXAbsVal = (uint16)MATHSRV_udtABS(s32LocalXVal);

   if (u16LocalXAbsVal >= Thr_posnDriftLihMeasThd1_C)
   {
      bLocalThrSftyMngbThrPosnLihDrift = 1;
   }
   else
   {
      bLocalThrSftyMngbThrPosnLihDrift = 0;
   }
   VEMS_vidSET(ThrSftyMng_bThrPosnLihDrift, bLocalThrSftyMngbThrPosnLihDrift);

   if (  (u16LocalXAbsVal >= Thr_posnDriftLihMeasThd1_C)
      && (u16LocalSsmThlPosSensingStatus != SSM_THROTTLE_POS_FAILURE))
   {
      bLocalCompare = 1;
   }
   else
   {
      bLocalCompare = 0;
   }
   if (  (Thr_bMonRunORngSftyDftLih != 0)
      && (bLocalCompare != 0))
   {
      bLocalInit = 1;
   }
   else
   {
      bLocalInit = 0;
   }

   if (  (THRSFTYMNG_bTimer2Prev == 0)
      && (bLocalInit!= 0))
   {
      THRSFTYMNG_u16Timer2 = Tpac_tiDlyDetDftRetLih;
      if (THRSFTYMNG_u16Timer2 == 0)
      {
         THRSFTYMNG_bTimeOut2 = 1;
      }
      else
      {
         THRSFTYMNG_bTimeOut2 = 0;
      }
   }
   else
   {
      if (THRSFTYMNG_u16Timer2 > 0)
      {
         THRSFTYMNG_u16Timer2 = (uint16)(THRSFTYMNG_u16Timer2 - 1);
         if (THRSFTYMNG_u16Timer2 == 0)
         {
            THRSFTYMNG_bTimeOut2 = 1;
         }
         else
         {
            THRSFTYMNG_bTimeOut2 = 0;
         }
      }
   }
   THRSFTYMNG_bTimer2Prev = bLocalInit;

   if (  (bLocalInit != 0)
      && (THRSFTYMNG_bTimeOut2 != 0))
   {
      Thr_bDgoORngSftyDftLih = 1;
   }
   else
   {
      Thr_bDgoORngSftyDftLih = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYMNG_vidDfltMCWDGFuncTest                            */
/* !Description :  Ce bloc permet la transmission des pannes à l'application  */
/*                 via le composant DGOHAL.                                   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  output boolean Sfty_bMonRunElDiagInhPin0_Cpu;                             */
/*  output boolean Sfty_bDgoElDiagInhPin0_Cpu;                                */
/*  output boolean Sfty_bMonRunElDiagInhPin1_Cpu;                             */
/*  output boolean Sfty_bDgoElDiagInhPin1_Cpu;                                */
/*  output boolean Sfty_bMonRunMcpRAMTest_Cpu;                                */
/*  output boolean Sfty_bDgoMcpRAMTest_Cpu;                                   */
/*  output boolean Sfty_bMonRunMcpFlashCks_Cpu;                               */
/*  output boolean Sfty_bDgoMcpFlashCks_Cpu;                                  */
/*  output boolean Sfty_bMonRunMcwCksCalc_Cpu;                                */
/*  output boolean Sfty_bDgoMcwCksCalc_Cpu;                                   */
/*  output boolean Sfty_bMonRunMcwInitSftyRslt_Cpu;                           */
/*  output boolean Sfty_bDgoMcwInitSftyRslt_Cpu;                              */
/*  output boolean Sfty_bMonRunMcwFctTest_Cpu;                                */
/*  output boolean Sfty_bDgoMcwFctTest_Cpu;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYMNG_vidDfltMCWDGFuncTest(void)
{
   DGOHAL_tbfStatus bfLocalFaultValue;

   bfLocalFaultValue = DGOHAL_bfRead(DGOHAL_udtMCWDG_ELEC_TESTS);

   if ( ( bfLocalFaultValue
        & (DGOHAL_tbfStatus)(DGOHAL_bfVALID_MCW_OUT1_DIAG_ELEC)) != 0)
   {
      Sfty_bMonRunElDiagInhPin0_Cpu = 1;
      if ( ( bfLocalFaultValue
           & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_MCW_OUT1_DIAG_ELEC)) != 0)
      {
         Sfty_bDgoElDiagInhPin0_Cpu = 1;
      }
      else
      {
         Sfty_bDgoElDiagInhPin0_Cpu = 0;
      }
   }
   else
   {
      Sfty_bMonRunElDiagInhPin0_Cpu = 0;
   }

   if ( ( bfLocalFaultValue
        & (DGOHAL_tbfStatus)(DGOHAL_bfVALID_MCW_OUT2_DIAG_ELEC)) != 0)
   {
      Sfty_bMonRunElDiagInhPin1_Cpu = 1;
      if ( ( bfLocalFaultValue
           & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_MCW_OUT2_DIAG_ELEC)) != 0)
      {
         Sfty_bDgoElDiagInhPin1_Cpu = 1;
      }
      else
      {
         Sfty_bDgoElDiagInhPin1_Cpu = 0;
      }
   }
   else
   {
      Sfty_bMonRunElDiagInhPin1_Cpu = 0;
   }

   bfLocalFaultValue = DGOHAL_bfRead(DGOHAL_udtMCWDG_INIT_SAFETY);

   if ( ( bfLocalFaultValue
        & (DGOHAL_tbfStatus)(DGOHAL_bfVALID_MCP_RAM_TEST)) != 0)
   {
      Sfty_bMonRunMcpRAMTest_Cpu = 1;
      if ( ( bfLocalFaultValue
           & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_MCP_RAM_TEST)) != 0)
      {
         Sfty_bDgoMcpRAMTest_Cpu = 1;
      }
      else
      {
         Sfty_bDgoMcpRAMTest_Cpu = 0;
      }
   }
   else
   {
      Sfty_bMonRunMcpRAMTest_Cpu = 0;
   }

   if ( ( bfLocalFaultValue
        & (DGOHAL_tbfStatus)(DGOHAL_bfVALID_MCP_FLASH_CKS)) != 0)
   {
      Sfty_bMonRunMcpFlashCks_Cpu = 1;
      if ( ( bfLocalFaultValue
           & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_MCP_FLASH_CKS)) != 0)
      {
         Sfty_bDgoMcpFlashCks_Cpu = 1;
      }
      else
      {
         Sfty_bDgoMcpFlashCks_Cpu = 0;
      }
   }
   else
   {
      Sfty_bMonRunMcpFlashCks_Cpu = 0;
   }

   if ( ( bfLocalFaultValue
        & (DGOHAL_tbfStatus)(DGOHAL_bfVALID_MCW_COMPUTED_CKS)) != 0)
   {
      Sfty_bMonRunMcwCksCalc_Cpu = 1;
      if ( ( bfLocalFaultValue
           & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_MCW_COMPUTED_CKS)) != 0)
      {
         Sfty_bDgoMcwCksCalc_Cpu = 1;
      }
      else
      {
         Sfty_bDgoMcwCksCalc_Cpu = 0;
      }
   }
   else
   {
      Sfty_bMonRunMcwCksCalc_Cpu = 0;
   }

   if ( ( bfLocalFaultValue
        & (DGOHAL_tbfStatus)(DGOHAL_bfVALID_MCW_INIT_SAFETY_RESULTS)) != 0)
   {
      Sfty_bMonRunMcwInitSftyRslt_Cpu = 1;
      if ( ( bfLocalFaultValue
           & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_MCW_INIT_SAFETY_RESULTS)) != 0)
      {
         Sfty_bDgoMcwInitSftyRslt_Cpu = 1;
      }
      else
      {
         Sfty_bDgoMcwInitSftyRslt_Cpu = 0;
      }
   }
   else
   {
      Sfty_bMonRunMcwInitSftyRslt_Cpu = 0;
   }

   bfLocalFaultValue = DGOHAL_bfRead(DGOHAL_udtMCWDG_FUNCTIONAL_TESTS);

   if ( ( bfLocalFaultValue
        & (DGOHAL_tbfStatus)(DGOHAL_bfVALID_MCW_FUNCTIONAL_TESTS)) != 0)
   {
      Sfty_bMonRunMcwFctTest_Cpu = 1;
      if ( ( bfLocalFaultValue
           & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_MCW_FUNCTIONAL_TESTS)) != 0)
      {
         Sfty_bDgoMcwFctTest_Cpu = 1;
      }
      else
      {
         Sfty_bDgoMcwFctTest_Cpu = 0;
      }
   }
   else
   {
      Sfty_bMonRunMcwFctTest_Cpu = 0;
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYMNG_vidMcwdgInhTestAbort                            */
/* !Description :  abandon du Test d'inhibition pour retourner à l'état intial*/
/* !Number      :  FCT1.8                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Thr_bTestAbort_ThrSftyMng;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYMNG_vidMcwdgInhTestAbort(void)
{
   VEMS_vidSET(Thr_bTestAbort_ThrSftyMng, 1);
}
/*----------------------------- end of file ----------------------------------*/