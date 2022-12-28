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
/* !File            : SFTYCPUDIAG_FCT1.C                                      */
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
/*   1 / SFTYCPUDIAG_vidInitOutput                                            */
/*   2 / SFTYCPUDIAG_vidMcwdgSampleCheck                                      */
/*   3 / SFTYCPUDIAG_vidMcwdgDiagnosesMCP                                     */
/*   4 / SFTYCPUDIAG_vidMcwdgReadMCWFltSt                                     */
/*   5 / SFTYCPUDIAG_vidMcwdgWritMCPFltSt                                     */
/*   6 / SFTYCPUDIAG_vidDiagRomChecksum                                       */
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

#include "STD_TYPES.h"
#include "SFTYCPUDIAG.h"
#include "SFTYCPUDIAG_L.h"
#include "SFTYCPUDIAG_IM.h"
#include "DGOHAL.h"
#include "MCWDG.h"
#include "GDGAR.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYCPUDIAG_vidInitOutput                                  */
/* !Description :  Initialisation des sorties du module SFTYCPUDIAG.          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Sfty_bDgoAccP_Cpu;                                         */
/*  output boolean Sfty_bDgoAlgo_Cpu;                                         */
/*  output boolean Sfty_bDgoAlgo_CpuSfty;                                     */
/*  output boolean Sfty_bDgoClk_Cpu;                                          */
/*  output boolean Sfty_bDgoClk_CpuSfty;                                      */
/*  output boolean Sfty_bDgoComSpi_Cpu;                                       */
/*  output boolean Sfty_bDgoComSpi_CpuSfty;                                   */
/*  output boolean Sfty_bDgoComTout_Cpu;                                      */
/*  output boolean Sfty_bDgoComTout_CpuSfty;                                  */
/*  output boolean Sfty_bDgoSyncMon_Cpu;                                      */
/*  output boolean Sfty_bDgoSyncMon_CpuSfty;                                  */
/*  output boolean Sfty_bDgoThr_Cpu;                                          */
/*  output boolean Sfty_bMonRunAccP_Cpu;                                      */
/*  output boolean Sfty_bMonRunAlgo_Cpu;                                      */
/*  output boolean Sfty_bMonRunAlgo_CpuSfty;                                  */
/*  output boolean Sfty_bMonRunClk_Cpu;                                       */
/*  output boolean Sfty_bMonRunClk_CpuSfty;                                   */
/*  output boolean Sfty_bMonRunComSpi_Cpu;                                    */
/*  output boolean Sfty_bMonRunComSpi_CpuSfty;                                */
/*  output boolean Sfty_bMonRunComTout_Cpu;                                   */
/*  output boolean Sfty_bMonRunComTout_CpuSfty;                               */
/*  output boolean Sfty_bMonRunSyncMon_Cpu;                                   */
/*  output boolean Sfty_bMonRunSyncMon_CpuSfty;                               */
/*  output boolean Sfty_bMonRunThr_Cpu;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYCPUDIAG_vidInitOutput(void)
{
   /*Initialisation des sorties*/
   VEMS_vidSET(Sfty_bDgoAccP_Cpu, 0);
   VEMS_vidSET(Sfty_bDgoAlgo_Cpu, 0);
   VEMS_vidSET(Sfty_bDgoAlgo_CpuSfty, 0);
   VEMS_vidSET(Sfty_bDgoClk_Cpu, 0);
   VEMS_vidSET(Sfty_bDgoClk_CpuSfty, 0);
   VEMS_vidSET(Sfty_bDgoComSpi_Cpu, 0);
   VEMS_vidSET(Sfty_bDgoComSpi_CpuSfty, 0);
   VEMS_vidSET(Sfty_bDgoComTout_Cpu, 0);
   VEMS_vidSET(Sfty_bDgoComTout_CpuSfty, 0);
   VEMS_vidSET(Sfty_bDgoSyncMon_Cpu, 0);
   VEMS_vidSET(Sfty_bDgoSyncMon_CpuSfty, 0);
   VEMS_vidSET(Sfty_bDgoThr_Cpu, 0);
   VEMS_vidSET(Sfty_bMonRunAccP_Cpu, 0);
   VEMS_vidSET(Sfty_bMonRunAlgo_Cpu, 0);
   VEMS_vidSET(Sfty_bMonRunAlgo_CpuSfty, 0);
   VEMS_vidSET(Sfty_bMonRunClk_Cpu, 0);
   VEMS_vidSET(Sfty_bMonRunClk_CpuSfty, 0);
   VEMS_vidSET(Sfty_bMonRunComSpi_Cpu, 0);
   VEMS_vidSET(Sfty_bMonRunComSpi_CpuSfty, 0);
   VEMS_vidSET(Sfty_bMonRunComTout_Cpu, 0);
   VEMS_vidSET(Sfty_bMonRunComTout_CpuSfty, 0);
   VEMS_vidSET(Sfty_bMonRunSyncMon_Cpu, 0);
   VEMS_vidSET(Sfty_bMonRunSyncMon_CpuSfty, 0);
   VEMS_vidSET(Sfty_bMonRunThr_Cpu, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYCPUDIAG_vidMcwdgSampleCheck                            */
/* !Description :  Ce block permet d’activer la surveillance des échantillons */
/*                 de test.                                                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MCWDG_vidResumeSampleCheck();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYCPUDIAG_vidMcwdgSampleCheck(void)
{
   MCWDG_vidResumeSampleCheck();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYCPUDIAG_vidMcwdgDiagnosesMCP                           */
/* !Description :  Ce block décrit la remontée du LDB vers le LDA des defauts */
/*                 qui sont détectés par le microcontrolleur principal.Le     */
/*                 service utilisé est DGOHAL.                                */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Sfty_bMonRunComSpi_Cpu;                                    */
/*  output boolean Sfty_bDgoComSpi_Cpu;                                       */
/*  output boolean Sfty_bMonRunComTout_Cpu;                                   */
/*  output boolean Sfty_bDgoComTout_Cpu;                                      */
/*  output boolean Sfty_bMonRunAlgo_Cpu;                                      */
/*  output boolean Sfty_bDgoAlgo_Cpu;                                         */
/*  output boolean Sfty_bMonRunSyncMon_Cpu;                                   */
/*  output boolean Sfty_bDgoSyncMon_Cpu;                                      */
/*  output boolean Sfty_bMonRunThr_Cpu;                                       */
/*  output boolean Sfty_bDgoThr_Cpu;                                          */
/*  output boolean Sfty_bMonRunAccP_Cpu;                                      */
/*  output boolean Sfty_bDgoAccP_Cpu;                                         */
/*  output boolean Sfty_bMonRunClk_Cpu;                                       */
/*  output boolean Sfty_bDgoClk_Cpu;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYCPUDIAG_vidMcwdgDiagnosesMCP(void)
{
   DGOHAL_tbfStatus bfLocalFaultValue;


   bfLocalFaultValue = DGOHAL_bfRead(DGOHAL_udtMCWDG_MICRO_CHECK);

   if ( ( bfLocalFaultValue
        & (DGOHAL_tbfStatus)(DGOHAL_bfVALID_MCWDG_COMSPI)) != 0)
   {
      VEMS_vidSET(Sfty_bMonRunComSpi_Cpu, 1);
      if ( ( bfLocalFaultValue
           & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_MCWDG_COMSPI)) != 0)
      {
         VEMS_vidSET(Sfty_bDgoComSpi_Cpu, 1);
      }
      else
      {
         VEMS_vidSET(Sfty_bDgoComSpi_Cpu, 0);
      }
   }
   else
   {
      VEMS_vidSET(Sfty_bMonRunComSpi_Cpu, 0);
   }

   if ( ( bfLocalFaultValue
        & (DGOHAL_tbfStatus)(DGOHAL_bfVALID_MCWDG_TIMEOUT)) != 0)
   {
      VEMS_vidSET(Sfty_bMonRunComTout_Cpu, 1);
      if ( ( bfLocalFaultValue
           & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_MCWDG_TIMEOUT)) != 0)
      {
         VEMS_vidSET(Sfty_bDgoComTout_Cpu, 1);
      }
      else
      {
         VEMS_vidSET(Sfty_bDgoComTout_Cpu, 0);
      }
   }
   else
   {
      VEMS_vidSET(Sfty_bMonRunComTout_Cpu, 0);
   }

   if ( ( bfLocalFaultValue
        & (DGOHAL_tbfStatus)(DGOHAL_bfVALID_MCWDG_ALGO)) != 0)
   {
      VEMS_vidSET(Sfty_bMonRunAlgo_Cpu, 1);
      if ( ( bfLocalFaultValue
           & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_MCWDG_ALGO)) != 0)
      {
         VEMS_vidSET(Sfty_bDgoAlgo_Cpu, 1);
      }
      else
      {
         VEMS_vidSET(Sfty_bDgoAlgo_Cpu, 0);
      }
   }
   else
   {
      VEMS_vidSET(Sfty_bMonRunAlgo_Cpu, 0);
   }

   bfLocalFaultValue = DGOHAL_bfRead(DGOHAL_udtMCWDG_DAC_CHECK);

   if ( ( bfLocalFaultValue
        & (DGOHAL_tbfStatus)(DGOHAL_bfVALID_MCWDG_MONIT)) != 0)
   {
      VEMS_vidSET(Sfty_bMonRunSyncMon_Cpu, 1);
      if ( ( bfLocalFaultValue
           & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_MCWDG_MONIT)) != 0)
      {
         VEMS_vidSET(Sfty_bDgoSyncMon_Cpu, 1);
      }
      else
      {
         VEMS_vidSET(Sfty_bDgoSyncMon_Cpu, 0);
      }
   }
   else
   {
      VEMS_vidSET(Sfty_bMonRunSyncMon_Cpu, 0);
   }

   if ( ( bfLocalFaultValue
        & (DGOHAL_tbfStatus)(DGOHAL_bfVALID_MCWDG_DACSIG2)) != 0)
   {
      VEMS_vidSET(Sfty_bMonRunThr_Cpu, 1);
      if ( ( bfLocalFaultValue
           & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_MCWDG_DACSIG2)) != 0)
      {
         VEMS_vidSET(Sfty_bDgoThr_Cpu, 1);
      }
      else
      {
         VEMS_vidSET(Sfty_bDgoThr_Cpu, 0);
      }
   }
   else
   {
      VEMS_vidSET(Sfty_bMonRunThr_Cpu, 0);
   }

   if ( ( bfLocalFaultValue
        & (DGOHAL_tbfStatus)(DGOHAL_bfVALID_MCWDG_DACSIG1)) != 0)
   {
      VEMS_vidSET(Sfty_bMonRunAccP_Cpu, 1);
      if ( ( bfLocalFaultValue
           & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_MCWDG_DACSIG1)) != 0)
      {
         VEMS_vidSET(Sfty_bDgoAccP_Cpu, 1);
      }
      else
      {
         VEMS_vidSET(Sfty_bDgoAccP_Cpu, 0);
      }
   }
   else
   {
      VEMS_vidSET(Sfty_bMonRunAccP_Cpu, 0);
   }

   if ( ( bfLocalFaultValue
        & (DGOHAL_tbfStatus)(DGOHAL_bfVALID_MCWDG_CLOCK)) != 0)
   {
      VEMS_vidSET(Sfty_bMonRunClk_Cpu, 1);
      if ( ( bfLocalFaultValue
           & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_MCWDG_CLOCK)) != 0)
      {
         VEMS_vidSET(Sfty_bDgoClk_Cpu, 1);
      }
      else
      {
         VEMS_vidSET(Sfty_bDgoClk_Cpu, 0);
      }
   }
   else
   {
      VEMS_vidSET(Sfty_bMonRunClk_Cpu, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYCPUDIAG_vidMcwdgReadMCWFltSt                           */
/* !Description :  L’appel à MCWDG_u8ReadMcwFaultState retourne le status des */
/*                 défaillance  côté Watchdog Microcontrolleur (filtré par le */
/*                 gestionnaire de defaut du microcontrolleur watchdog et     */
/*                 coherent avec la calibration du masque de configuration).  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret uint8  MCWDG_bfReadMcwFaultState();                           */
/*  output boolean Sfty_bMonRunClk_CpuSfty;                                   */
/*  output boolean Sfty_bMonRunSyncMon_CpuSfty;                               */
/*  output boolean Sfty_bMonRunComTout_CpuSfty;                               */
/*  output boolean Sfty_bMonRunComSpi_CpuSfty;                                */
/*  output boolean Sfty_bMonRunAlgo_CpuSfty;                                  */
/*  output boolean Sfty_bDgoComSpi_CpuSfty;                                   */
/*  output boolean Sfty_bDgoComTout_CpuSfty;                                  */
/*  output boolean Sfty_bDgoSyncMon_CpuSfty;                                  */
/*  output boolean Sfty_bDgoClk_CpuSfty;                                      */
/*  output boolean Sfty_bDgoAlgo_CpuSfty;                                     */
/*  output boolean Sfty_bAcvDegMod_CpuSfty;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYCPUDIAG_vidMcwdgReadMCWFltSt(void)
{
   uint8   u8LocalBuffer;


   VEMS_vidSET(Sfty_bMonRunClk_CpuSfty, 1);
   VEMS_vidSET(Sfty_bMonRunSyncMon_CpuSfty, 1);
   VEMS_vidSET(Sfty_bMonRunComTout_CpuSfty, 1);
   VEMS_vidSET(Sfty_bMonRunComSpi_CpuSfty, 1);
   VEMS_vidSET(Sfty_bMonRunAlgo_CpuSfty, 1);

   u8LocalBuffer = MCWDG_bfReadMcwFaultState();
   if ((u8LocalBuffer & MCWDG_COMSPI) != 0)
   {
      VEMS_vidSET(Sfty_bDgoComSpi_CpuSfty, 1);
   }
   else
   {
      VEMS_vidSET(Sfty_bDgoComSpi_CpuSfty, 0);
   }

   if ((u8LocalBuffer & MCWDG_TIMEOUT) != 0)
   {
      VEMS_vidSET(Sfty_bDgoComTout_CpuSfty, 1);
   }
   else
   {
      VEMS_vidSET(Sfty_bDgoComTout_CpuSfty, 0);
   }

   if ((u8LocalBuffer & MCWDG_MONIT) != 0)
   {
      VEMS_vidSET(Sfty_bDgoSyncMon_CpuSfty, 1);
   }
   else
   {
      VEMS_vidSET(Sfty_bDgoSyncMon_CpuSfty, 0);
   }

   if ((u8LocalBuffer & MCWDG_CLOCK) != 0)
   {
      VEMS_vidSET(Sfty_bDgoClk_CpuSfty, 1);
   }
   else
   {
      VEMS_vidSET(Sfty_bDgoClk_CpuSfty, 0);
   }

   if ((u8LocalBuffer & MCWDG_ALU) != 0)
   {
      VEMS_vidSET(Sfty_bDgoAlgo_CpuSfty, 1);
   }
   else
   {
      VEMS_vidSET(Sfty_bDgoAlgo_CpuSfty, 0);
   }

   if ((u8LocalBuffer & MCWDG_DEG_MOD) != 0)
   {
      Sfty_bAcvDegMod_CpuSfty = 1;
   }
   else
   {
      Sfty_bAcvDegMod_CpuSfty = 0;
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYCPUDIAG_vidMcwdgWritMCPFltSt                           */
/* !Description :  Ce service permet de transmettre au microcontrolleur       */
/*                 Watchdog les defaut safety remonté par le microcontrolleur */
/*                 principal.                                                 */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_tenuGetStDgo(argin uint16                          */
/*  u16IdxDft)GDFRM_tenuGDUState;                                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MCWDG_vidWriteMcpFaultState(uint8 bfFaultMask );         */
/*  input boolean SftyMgt_bRstHwReq;                                          */
/*  input boolean SftyMgt_bDgoRvLih;                                          */
/*  input boolean SftyMgt_bDgoIrvEngStop;                                     */
/*  input boolean SftyMgt_bRstSwReq;                                          */
/*  output boolean Sfty_bMonRunDegMod_CpuSfty;                                */
/*  output boolean Sfty_bDgoDegMod_CpuSfty;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYCPUDIAG_vidMcwdgWritMCPFltSt(void)
{
   uint8              bfFaultMask;
   boolean            bLocalSftyMgt_bRstHwReq;
   boolean            bLocalSftyMgt_bDgoRvLih;
   boolean            bLocalSftyMgt_bDgoIrvEngStop;
   boolean            bLocalSftyMgt_bRstSwReq;
   GDFRM_tenuGDUState LocalstDgoComSpi_Cpu;
   GDFRM_tenuGDUState LocalstDgoComTout_Cpu;
   GDFRM_tenuGDUState LocalstDgoSyncMon_Cpu;
   GDFRM_tenuGDUState LocalstDgoClk_Cpu;
   GDFRM_tenuGDUState LocalstDgoAlgo_Cpu;
   GDFRM_tenuGDUState LocalstDgoAccP_Cpu;
   GDFRM_tenuGDUState LocalstDgoThr_Cpu;


   bfFaultMask = 0;
   Sfty_bMonRunDegMod_CpuSfty = 1;

   LocalstDgoComSpi_Cpu  = GDGAR_tenuGetStDgo(GD_DFT_COMSPI_CPU);
   if(  (LocalstDgoComSpi_Cpu == GDU_ETAT_DEVALIDATION)
     || (LocalstDgoComSpi_Cpu == GDU_ETAT_PRESENT))
   {
      bfFaultMask = (uint8)(bfFaultMask | MCWDG_COMSPI);
   }

   LocalstDgoComTout_Cpu = GDGAR_tenuGetStDgo(GD_DFT_COMTOUT_CPU);
   if(  (LocalstDgoComTout_Cpu == GDU_ETAT_DEVALIDATION)
     || (LocalstDgoComTout_Cpu == GDU_ETAT_PRESENT))
   {
      bfFaultMask = (uint8)(bfFaultMask | MCWDG_TIMEOUT);
   }

   LocalstDgoSyncMon_Cpu = GDGAR_tenuGetStDgo(GD_DFT_SYNCMON_CPU);
   if(  (LocalstDgoSyncMon_Cpu == GDU_ETAT_DEVALIDATION)
     || (LocalstDgoSyncMon_Cpu == GDU_ETAT_PRESENT))
   {
      bfFaultMask = (uint8)(bfFaultMask | MCWDG_MONIT);
   }

   LocalstDgoClk_Cpu = GDGAR_tenuGetStDgo(GD_DFT_CLK_CPU);
   if(  (LocalstDgoClk_Cpu == GDU_ETAT_DEVALIDATION)
     || (LocalstDgoClk_Cpu == GDU_ETAT_PRESENT))
   {
      bfFaultMask = (uint8)(bfFaultMask | MCWDG_CLOCK);
   }

   LocalstDgoAlgo_Cpu = GDGAR_tenuGetStDgo(GD_DFT_ALGO_CPU);
   if(  (LocalstDgoAlgo_Cpu == GDU_ETAT_DEVALIDATION)
     || (LocalstDgoAlgo_Cpu == GDU_ETAT_PRESENT))
   {
      bfFaultMask = (uint8)(bfFaultMask | MCWDG_ALU);
   }

   LocalstDgoThr_Cpu = GDGAR_tenuGetStDgo(GD_DFT_THR_CPU);
   LocalstDgoAccP_Cpu = GDGAR_tenuGetStDgo(GD_DFT_ACCP_CPU);

   if( (  (LocalstDgoThr_Cpu == GDU_ETAT_DEVALIDATION)
       || (LocalstDgoThr_Cpu == GDU_ETAT_PRESENT))
     || (  (LocalstDgoAccP_Cpu == GDU_ETAT_DEVALIDATION)
        || (LocalstDgoAccP_Cpu == GDU_ETAT_PRESENT)))
   {
      bfFaultMask = (uint8)(bfFaultMask | MCWDG_MCP_ADC_VAL);
   }

   VEMS_vidGET(SftyMgt_bRstHwReq, bLocalSftyMgt_bRstHwReq);
   VEMS_vidGET(SftyMgt_bDgoRvLih, bLocalSftyMgt_bDgoRvLih);
   VEMS_vidGET(SftyMgt_bDgoIrvEngStop, bLocalSftyMgt_bDgoIrvEngStop);
   VEMS_vidGET(SftyMgt_bRstSwReq, bLocalSftyMgt_bRstSwReq);
   if(  (bLocalSftyMgt_bRstHwReq != 0)
     || (bLocalSftyMgt_bDgoRvLih != 0)
     || (bLocalSftyMgt_bDgoIrvEngStop != 0)
     || (bLocalSftyMgt_bRstSwReq != 0))
   {
      Sfty_bDgoDegMod_CpuSfty = 1;
      bfFaultMask = (uint8)(bfFaultMask | MCWDG_DEG_MOD);
   }
   else
   {
      Sfty_bDgoDegMod_CpuSfty = 0;
   }

   MCWDG_vidWriteMcpFaultState(bfFaultMask);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYCPUDIAG_vidDiagRomChecksum                             */
/* !Description :  Ce service permet de lire la valeur du checksum ROM du MCW.*/
/* !Number      :  FCT1.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/* udtChannel);                                                               */
/*  output boolean Sfty_bMonRunCksRom_CpuSfty;                                */
/*  output boolean Sfty_bDgoCksRom_CpuSfty;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYCPUDIAG_vidDiagRomChecksum(void)
{
   DGOHAL_tbfStatus bfLocalFaultValue;
   boolean          bLocalInhReadCksRomCpuSfty;


   bLocalInhReadCksRomCpuSfty = GDGAR_bGetFRM(FRM_FRM_INHREADCKSROMCPUSFTY);
   if (bLocalInhReadCksRomCpuSfty != 0)
   {
      Sfty_bMonRunCksRom_CpuSfty = 0;
   }
   else
   {
      Sfty_bMonRunCksRom_CpuSfty = 1;
      bfLocalFaultValue = DGOHAL_bfRead(DGOHAL_udtMCWDG_INIT_SAFETY);

      if ( ( bfLocalFaultValue
         & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_MCW_COMPUTED_CKS)) != 0)
      {
         Sfty_bDgoCksRom_CpuSfty = 1;
      }
      else
      {
         Sfty_bDgoCksRom_CpuSfty = 0;
      }
   }
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*--------------------------------- end of file ------------------------------*/