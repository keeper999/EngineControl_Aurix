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
/* !File            : THRSFTYMNG_SCH.C                                        */
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
/*   1 / Thr_EveRst_ThrCpuSftyMng                                             */
/*   2 / Thr_SdlFast_ThrSftyMng                                               */
/*   3 / Thr_EveTestStart_ThrSftyMng                                          */
/*   4 / Thr_EveClcnServo_ThrSftyMng                                          */
/*   5 / Thr_EveChkLih_ThrSftyMng                                             */
/*   6 / Thr_EveTestAbort_ThrSftyMng                                          */
/*                                                                            */
/* !Reference   : V02 NT 11 03549 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#063742                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRSFTYMNG/THRSFTYMNG_SCH.C_$*/
/* $Revision::   1.10     $$Author::   etsasson       $$Date::   25 Oct 2012 $*/
/* $Author::   etsasson                               $$Date::   25 Oct 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "THRSFTYMNG.h"
#include "THRSFTYMNG_L.h"
#include "THRSFTYMNG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveRst_ThrCpuSftyMng                                   */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_E_11_03549_002.01                                     */
/*                 VEMS_E_11_03549_003.01                                     */
/*                 VEMS_E_11_03549_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSFTYMNG_vidMcwdgInit();                               */
/*  extf argret void THRSFTYMNG_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveRst_ThrCpuSftyMng                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRst_ThrCpuSftyMng(void)
{
   THRSFTYMNG_vidMcwdgInit();
   THRSFTYMNG_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_SdlFast_ThrSftyMng                                     */
/* !Description :  Moniteur rapide de la fonction papillon.                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_E_11_03549_002.01                                     */
/*                 VEMS_E_11_03549_003.01                                     */
/*                 VEMS_E_11_03549_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRSFTYMNG_vidMcwdgInhTestCdn();                         */
/*  extf argret void THRSFTYMNG_vidDfltMCWDGFuncTest();                       */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input boolean Thr_bEndTestInh_CpuSfty;                                    */
/*  input uint8 THRSFTYMNG_u8Inhib;                                           */
/*  input boolean Sfty_bDgoElDiagInhPin0_Cpu;                                 */
/*  input boolean Sfty_bMonRunElDiagInhPin0_Cpu;                              */
/*  input boolean Sfty_bDgoElDiagInhPin1_Cpu;                                 */
/*  input boolean Sfty_bMonRunElDiagInhPin1_Cpu;                              */
/*  input boolean Sfty_bDgoMcpRAMTest_Cpu;                                    */
/*  input boolean Sfty_bMonRunMcpRAMTest_Cpu;                                 */
/*  input boolean Sfty_bDgoMcpFlashCks_Cpu;                                   */
/*  input boolean Sfty_bMonRunMcpFlashCks_Cpu;                                */
/*  input boolean Sfty_bDgoMcwCksCalc_Cpu;                                    */
/*  input boolean Sfty_bMonRunMcwCksCalc_Cpu;                                 */
/*  input boolean Sfty_bDgoMcwInitSftyRslt_Cpu;                               */
/*  input boolean Sfty_bMonRunMcwInitSftyRslt_Cpu;                            */
/*  input boolean Sfty_bDgoMcwFctTest_Cpu;                                    */
/*  input boolean Sfty_bMonRunMcwFctTest_Cpu;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_SdlFast_ThrSftyMng                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_SdlFast_ThrSftyMng(void)
{
   boolean bLocalThr_bEndTestInh_CpuSfty;

   VEMS_vidGET(Thr_bEndTestInh_CpuSfty, bLocalThr_bEndTestInh_CpuSfty);

   if (THRSFTYMNG_u8Inhib != 0x5A)
   {
      if (bLocalThr_bEndTestInh_CpuSfty == 0)
      {
         THRSFTYMNG_vidMcwdgInhTestCdn();
         THRSFTYMNG_vidDfltMCWDGFuncTest();
      }
      GDGAR_vidGdu(GD_DFT_ELDIAGINHPIN0_CPU,
                   Sfty_bDgoElDiagInhPin0_Cpu,
                   Sfty_bMonRunElDiagInhPin0_Cpu,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ELDIAGINHPIN1_CPU,
                   Sfty_bDgoElDiagInhPin1_Cpu,
                   Sfty_bMonRunElDiagInhPin1_Cpu,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_MCPRAMTEST_CPU,
                   Sfty_bDgoMcpRAMTest_Cpu,
                   Sfty_bMonRunMcpRAMTest_Cpu,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_MCPFLASHCKS_CPU,
                   Sfty_bDgoMcpFlashCks_Cpu,
                   Sfty_bMonRunMcpFlashCks_Cpu,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_MCWCKSCALC_CPU,
                   Sfty_bDgoMcwCksCalc_Cpu,
                   Sfty_bMonRunMcwCksCalc_Cpu,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_MCWINITSFTYRSLT_CPU,
                   Sfty_bDgoMcwInitSftyRslt_Cpu,
                   Sfty_bMonRunMcwInitSftyRslt_Cpu,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_MCWFCTTEST_CPU,
                   Sfty_bDgoMcwFctTest_Cpu,
                   Sfty_bMonRunMcwFctTest_Cpu,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveTestStart_ThrSftyMng                                */
/* !Description :  Evènement d'autorisation des tests fonctionnels            */
/*                 d'inhibition.                                              */
/* !Number      :  SCH.3                                                      */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_E_11_03549_002.01                                     */
/*                 VEMS_E_11_03549_003.01                                     */
/*                 VEMS_E_11_03549_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSFTYMNG_vidMcwdgInhTestStrt();                        */
/*  input uint8 THRSFTYMNG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveTestStart_ThrSftyMng                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveTestStart_ThrSftyMng(void)
{
   if (THRSFTYMNG_u8Inhib != 0x5A)
   {
      THRSFTYMNG_vidMcwdgInhTestStrt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveClcnServo_ThrSftyMng                                */
/* !Description :  Evénement de calcul de l'asservissement papillon motorisé. */
/* !Number      :  SCH.4                                                      */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_E_11_03549_002.01                                     */
/*                 VEMS_E_11_03549_003.01                                     */
/*                 VEMS_E_11_03549_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/*  argin boolean bMonRun, argin boolean Ns_bMonWait);                        */
/*  extf argret void THRSFTYMNG_vidDfltApplicLimpHome();                      */
/*  input uint8 THRSFTYMNG_u8Inhib;                                           */
/*  input boolean Thr_bDgoORngSftyDftLih;                                     */
/*  input boolean Thr_bMonRunORngSftyDftLih;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveClcnServo_ThrSftyMng                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveClcnServo_ThrSftyMng(void)
{
   if (THRSFTYMNG_u8Inhib != 0x5A)
   {
      GDGAR_vidGdu(GD_DFT_ORNGSFTYDFTLIH,
                   Thr_bDgoORngSftyDftLih,
                   Thr_bMonRunORngSftyDftLih,
                   DIAG_DISPO);
      THRSFTYMNG_vidDfltApplicLimpHome();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveChkLih_ThrSftyMng                                   */
/* !Description :  Demande de vérification de la position de repos du papillon*/
/* !Number      :  SCH.5                                                      */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_E_11_03549_002.01                                     */
/*                 VEMS_E_11_03549_003.01                                     */
/*                 VEMS_E_11_03549_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSFTYMNG_vidMCWDGFuncTestRslt();                       */
/*  input uint8 THRSFTYMNG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveChkLih_MngServo_ThrSftyMng                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveChkLih_ThrSftyMng(void)
{
   if (THRSFTYMNG_u8Inhib != 0x5A)
   {
      THRSFTYMNG_vidMCWDGFuncTestRslt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveTestAbort_ThrSftyMng                                */
/* !Description :  Evènement d'abandon des tests fonctionnels d'inhibition    */
/* !Number      :  SCH.6                                                      */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_E_11_03549_002.01                                     */
/*                 VEMS_E_11_03549_003.01                                     */
/*                 VEMS_E_11_03549_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSFTYMNG_vidMcwdgInit();                               */
/*  extf argret void THRSFTYMNG_vidMcwdgInhTestAbort();                       */
/*  input uint8 THRSFTYMNG_u8Inhib;                                           */
/*  input boolean Thr_bAcvTestAbortSfty_C;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveTestAbort_ThrSftyMng                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveTestAbort_ThrSftyMng(void)
{
   if (THRSFTYMNG_u8Inhib != 0x5A)
   {
      if (Thr_bAcvTestAbortSfty_C != 0)
      {
         THRSFTYMNG_vidMcwdgInit();
         THRSFTYMNG_vidMcwdgInhTestAbort();
      }
   }
}

/*----------------------------- end of file ----------------------------------*/