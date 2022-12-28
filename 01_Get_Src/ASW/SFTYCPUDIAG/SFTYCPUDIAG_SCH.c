/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SFTYCPUDIAG                                             */
/* !Description     : SFTYCPUDIAG Component                                   */
/*                                                                            */
/* !Module          : SFTYCPUDIAG                                             */
/* !Description     : Diagnostics réalisés par le driver  Watchdog            */
/*                                                                            */
/* !File            : SFTYCPUDIAG_SCH.C                                       */
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
/*   1 / Sfty_EveRst_DiagCpuSfty                                              */
/*   2 / Sfty_SdlFast_DiagCpuSfty                                             */
/*   3 / Sfty_SdlSlow_DiagCpuSfty                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5711967 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/SFTYCPUDIAG/SFTYCPUDIAG_SCH.C_v   $*/
/* $Revision::   1.2      $$Author::   lthibaud       $$Date::   29 Mar 2010 $*/
/* $Author::   lthibaud                               $$Date::   29 Mar 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "SFTYCPUDIAG.h"
#include "SFTYCPUDIAG_L.h"
#include "SFTYCPUDIAG_IM.h"
#include "VEMS.h"
#include "GDGAR.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sfty_EveRst_DiagCpuSfty                                    */
/* !Description :  Evenement Reset.                                           */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_11_05806_001.01                                     */
/*                 VEMS_E_11_05806_002.01                                     */
/*                 VEMS_E_11_05806_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYCPUDIAG_vidMcwdgSampleCheck();                       */
/*  extf argret void SFTYCPUDIAG_vidDiagRomChecksum();                        */
/*  extf argret void SFTYCPUDIAG_vidInitOutput();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sfty_EveRst_DiagCpuSfty                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sfty_EveRst_DiagCpuSfty(void)
{
   /*01_Mcwdg_Sample_Check*/
   SFTYCPUDIAG_vidMcwdgSampleCheck();

   /*02_DiagRomChecksum*/
   SFTYCPUDIAG_vidDiagRomChecksum();

   /*Initialisation des sorties*/
   SFTYCPUDIAG_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sfty_SdlFast_DiagCpuSfty                                   */
/* !Description :  Moniteur rapide de la fonction Sfty                        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_11_05806_001.01                                     */
/*                 VEMS_E_11_05806_002.01                                     */
/*                 VEMS_E_11_05806_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYCPUDIAG_vidMcwdgDiagnosesMCP();                      */
/*  extf argret void SFTYCPUDIAG_vidMcwdgReadMCWFltSt();                      */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  extf argret void SFTYCPUDIAG_vidMcwdgWritMCPFltSt();                      */
/*  input uint8 SFTYCPUDIAG_u8Inhib;                                          */
/*  input boolean Sfty_bDgoComSpi_CpuSfty;                                    */
/*  input boolean Sfty_bMonRunComSpi_CpuSfty;                                 */
/*  input boolean Sfty_bDgoComTout_CpuSfty;                                   */
/*  input boolean Sfty_bMonRunComTout_CpuSfty;                                */
/*  input boolean Sfty_bDgoSyncMon_CpuSfty;                                   */
/*  input boolean Sfty_bMonRunSyncMon_CpuSfty;                                */
/*  input boolean Sfty_bDgoClk_CpuSfty;                                       */
/*  input boolean Sfty_bMonRunClk_CpuSfty;                                    */
/*  input boolean Sfty_bDgoAlgo_CpuSfty;                                      */
/*  input boolean Sfty_bMonRunAlgo_CpuSfty;                                   */
/*  input boolean Sfty_bDgoComSpi_Cpu;                                        */
/*  input boolean Sfty_bMonRunComSpi_Cpu;                                     */
/*  input boolean Sfty_bDgoComTout_Cpu;                                       */
/*  input boolean Sfty_bMonRunComTout_Cpu;                                    */
/*  input boolean Sfty_bDgoSyncMon_Cpu;                                       */
/*  input boolean Sfty_bMonRunSyncMon_Cpu;                                    */
/*  input boolean Sfty_bDgoAccP_Cpu;                                          */
/*  input boolean Sfty_bMonRunAccP_Cpu;                                       */
/*  input boolean Sfty_bDgoThr_Cpu;                                           */
/*  input boolean Sfty_bMonRunThr_Cpu;                                        */
/*  input boolean Sfty_bDgoClk_Cpu;                                           */
/*  input boolean Sfty_bMonRunClk_Cpu;                                        */
/*  input boolean Sfty_bDgoAlgo_Cpu;                                          */
/*  input boolean Sfty_bMonRunAlgo_Cpu;                                       */
/*  input boolean Sfty_bDgoDegMod_CpuSfty;                                    */
/*  input boolean Sfty_bMonRunDegMod_CpuSfty;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sfty_SdlFast_DiagCpuSfty                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sfty_SdlFast_DiagCpuSfty(void)
{
   boolean bLocalDgo;
   boolean bLocalMonRun;


   if (SFTYCPUDIAG_u8Inhib != 0x5A)
   {
      /*02_Mcwdg_Diagnoses_MCP*/
      SFTYCPUDIAG_vidMcwdgDiagnosesMCP();

      /*03_Mcwdg_Read_MCW_Fault_State*/
      SFTYCPUDIAG_vidMcwdgReadMCWFltSt();

      /*06_Mcwdg_Deb_MCP_Fault*/
      VEMS_vidGET(Sfty_bDgoComSpi_CpuSfty, bLocalDgo);
      VEMS_vidGET(Sfty_bMonRunComSpi_CpuSfty, bLocalMonRun);
      GDGAR_vidGdu(GD_DFT_COMSPI_CPUSFTY, bLocalDgo, bLocalMonRun, DIAG_DISPO);

      VEMS_vidGET(Sfty_bDgoComTout_CpuSfty, bLocalDgo);
      VEMS_vidGET(Sfty_bMonRunComTout_CpuSfty, bLocalMonRun);
      GDGAR_vidGdu(GD_DFT_COMTOUT_CPUSFTY, bLocalDgo, bLocalMonRun, DIAG_DISPO);

      VEMS_vidGET(Sfty_bDgoSyncMon_CpuSfty, bLocalDgo);
      VEMS_vidGET(Sfty_bMonRunSyncMon_CpuSfty, bLocalMonRun);
      GDGAR_vidGdu(GD_DFT_SYNCMON_CPUSFTY, bLocalDgo, bLocalMonRun, DIAG_DISPO);

      VEMS_vidGET(Sfty_bDgoClk_CpuSfty, bLocalDgo);
      VEMS_vidGET(Sfty_bMonRunClk_CpuSfty, bLocalMonRun);
      GDGAR_vidGdu(GD_DFT_CLK_CPUSFTY, bLocalDgo, bLocalMonRun, DIAG_DISPO);

      VEMS_vidGET(Sfty_bDgoAlgo_CpuSfty, bLocalDgo);
      VEMS_vidGET(Sfty_bMonRunAlgo_CpuSfty, bLocalMonRun);
      GDGAR_vidGdu(GD_DFT_ALGO_CPUSFTY, bLocalDgo, bLocalMonRun, DIAG_DISPO);

      VEMS_vidGET(Sfty_bDgoComSpi_Cpu, bLocalDgo);
      VEMS_vidGET(Sfty_bMonRunComSpi_Cpu, bLocalMonRun);
      GDGAR_vidGdu(GD_DFT_COMSPI_CPU, bLocalDgo, bLocalMonRun, DIAG_DISPO);

      VEMS_vidGET(Sfty_bDgoComTout_Cpu, bLocalDgo);
      VEMS_vidGET(Sfty_bMonRunComTout_Cpu, bLocalMonRun);
      GDGAR_vidGdu(GD_DFT_COMTOUT_CPU, bLocalDgo, bLocalMonRun, DIAG_DISPO);

      VEMS_vidGET(Sfty_bDgoSyncMon_Cpu, bLocalDgo);
      VEMS_vidGET(Sfty_bMonRunSyncMon_Cpu, bLocalMonRun);
      GDGAR_vidGdu(GD_DFT_SYNCMON_CPU, bLocalDgo, bLocalMonRun, DIAG_DISPO);

      VEMS_vidGET(Sfty_bDgoAccP_Cpu, bLocalDgo);
      VEMS_vidGET(Sfty_bMonRunAccP_Cpu, bLocalMonRun);
      GDGAR_vidGdu(GD_DFT_ACCP_CPU, bLocalDgo, bLocalMonRun, DIAG_DISPO);

      VEMS_vidGET(Sfty_bDgoThr_Cpu, bLocalDgo);
      VEMS_vidGET(Sfty_bMonRunThr_Cpu, bLocalMonRun);
      GDGAR_vidGdu(GD_DFT_THR_CPU, bLocalDgo, bLocalMonRun, DIAG_DISPO);

      VEMS_vidGET(Sfty_bDgoClk_Cpu, bLocalDgo);
      VEMS_vidGET(Sfty_bMonRunClk_Cpu, bLocalMonRun);
      GDGAR_vidGdu(GD_DFT_CLK_CPU, bLocalDgo, bLocalMonRun, DIAG_DISPO);

      VEMS_vidGET(Sfty_bDgoAlgo_Cpu, bLocalDgo);
      VEMS_vidGET(Sfty_bMonRunAlgo_Cpu, bLocalMonRun);
      GDGAR_vidGdu(GD_DFT_ALGO_CPU, bLocalDgo, bLocalMonRun, DIAG_DISPO);

      /*04_Mcwdg_Write_MCP_Fault_State*/
      SFTYCPUDIAG_vidMcwdgWritMCPFltSt();
      GDGAR_vidGdu(GD_DFT_DEGMOD_CPUSFTY,
                   Sfty_bDgoDegMod_CpuSfty,
                   Sfty_bMonRunDegMod_CpuSfty,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sfty_SdlSlow_DiagCpuSfty                                   */
/* !Description :  Moniteur lent de la fonction Safety.                       */
/* !Number      :  SCH.3                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_11_05806_001.01                                     */
/*                 VEMS_E_11_05806_002.01                                     */
/*                 VEMS_E_11_05806_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYCPUDIAG_vidDiagRomChecksum();                        */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 SFTYCPUDIAG_u8Inhib;                                          */
/*  input boolean Sfty_bDgoCksRom_CpuSfty;                                    */
/*  input boolean Sfty_bMonRunCksRom_CpuSfty;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sfty_SdlSlow_DiagCpuSfty                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sfty_SdlSlow_DiagCpuSfty(void)
{
   if (SFTYCPUDIAG_u8Inhib != 0x5A)
   {
      SFTYCPUDIAG_vidDiagRomChecksum();
      GDGAR_vidGdu(GD_DFT_CKSROM_CPUSFTY,
                   Sfty_bDgoCksRom_CpuSfty,
                   Sfty_bMonRunCksRom_CpuSfty,
                   DIAG_DISPO);
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*--------------------------------- end of file ------------------------------*/