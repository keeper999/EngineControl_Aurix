/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : STARTUP                                                 */
/* !Description     : Start-up                                                */
/*                                                                            */
/* !File            : STARTUP_Core1.c                                         */
/* !Description     : Start-up software of Core 1                             */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A111669.A-SRC;4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "DEVHAL.h"
#include "IfxCpu.h"
#include "IfxCpu_reg.h"
#include "IfxScuWdt.h"
#include "IfxScu_reg.h"
#include "Ifx_Cfg.h"
#include "Isr_Cfg.h"
#include "MAIN.h"
#include "MCAL.h"
#include "STARTUP.h"
#include "Wdg.h"

#define STARTUP_START_SEC_CODE
#include "STARTUP_MemMap.h"

/******************************************************************************/
/* !FuncName    : STARTUP_Core1_start                                         */
/* !Description : Startup Function of Core 1                                  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void STARTUP_Core1_start(void)
{
   uint16 u16LocalWdtPassword =
      IfxScuWdt_getCpuWatchdogPasswordInline(&MODULE_SCU.WDTCPU[1]);
   sint32 *ps32LocalPrevCsa;
   sint32 s32LocalLoopCount;
   sint32 s32LocalNnOfCsas;
   uint32 u32LocalPcxi;
   uint32 u32LocalSegmentNr, u32LocalSegmentIdx, u32LocalPcxiVal = 0;

   /* Initialization of SDA base pointers */
   __setareg(a0, __SDATA1_1);
   __setareg(a1, __SDATA2_1);
   __setareg(a8, __SDATA3_1);
   __setareg(a9, __SDATA4_1);

   /* Load user stack pointer */
   __setareg(sp, __USTACK1);
   __dsync();

   /* Set the PSW to its reset value in case of a warm start,clear PSW.IS */
   __mtcr(CPU_PSW, STARTUP_CORE1_PSW_DEFAULT);
   __isync() ;

   /* Set the PCXS and PCXO to its reset value in case of a warm start */
   u32LocalPcxi  = __mfcr(CPU_PCXI);
   u32LocalPcxi &= STARTUP_CORE1_PCX_O_S_DEFAULT; /*0xfff00000; */
   __mtcr(CPU_PCXI, u32LocalPcxi);

   /* Setup the context save area linked list. */
   /* First calculate nr of CSAs in this area  */
   s32LocalNnOfCsas = ((sint32 *) __CSA1_END - (sint32 *) __CSA1) >> 4;
   ps32LocalPrevCsa = (sint32 *) __CSA1;

   for (s32LocalLoopCount = 0;
        s32LocalLoopCount < s32LocalNnOfCsas;
        s32LocalLoopCount++)
   {
      /* Store null pointer in last CSA (= very first time!) */
      *ps32LocalPrevCsa = u32LocalPcxiVal;
      /* get segment number */
      u32LocalSegmentNr = EXTRACT((sint32)ps32LocalPrevCsa, 28, 4) << 16;
      /* get idx number */
      u32LocalSegmentIdx = EXTRACT((sint32)ps32LocalPrevCsa, 6, 16);
      /* calculate valid pcxi value */
      u32LocalPcxiVal = u32LocalSegmentNr | u32LocalSegmentIdx;
      /* if this is the last csa, then we store the new pcxi value to LCX */
      if (s32LocalLoopCount == 0)
        __mtcr (CPU_LCX, u32LocalPcxiVal);
      /* next CSA */
      ps32LocalPrevCsa += 16;
   }
   /* Store actual pcxi value to the FCX (this is our first free context) */
   __mtcr (CPU_FCX, u32LocalPcxiVal);
   __isync() ;

   // Mcal_ResetENDINIT();
   /* Clear the ENDINIT bit in the WDT_CON0 register */
   IfxScuWdt_clearCpuEndinitInline(&MODULE_SCU.WDTCPU[1], u16LocalWdtPassword);

   /* Load Base Address of Trap Vector Table               */
   __mtcr(CPU_BTV, (uint32)__TRAPTAB);

   /* Load interupt stack pointer                          */
   __mtcr(CPU_ISP, (uint32)__ISTACK1);

   /* Enable Program Cache */
   IfxCpu_setProgramCache(STARTUP_CORE1_ENA_PCACHE);

   /* Enable Data Cache if Configured */
   IfxCpu_setDataCache(STARTUP_CORE1_ENA_DCACHE);

   /* Set the ENDINIT bit in the WDT_CON0 register again to enable the write-protection and to prevent a time-out. */
   // Mcal_SetENDINIT();
   IfxScuWdt_setCpuEndinitInline(&MODULE_SCU.WDTCPU[1], u16LocalWdtPassword);

   /* Disable of internal Core 1 Watchdog */
   IfxScuWdt_disableCpuWatchdog(u16LocalWdtPassword);

   Mcal_u8CpuInitCompletedSem[1] = 1;

   /* This is to wait until basic initializations are completed by CPU0. Other*/
   /* initializations can be started by other cores from now on.              */
   while(Mcal_u8CpuInitCompletedSem[0] != 1);
   Wdg_Init(&Wdg_ConfigRoot[0]);

   /* Call main function of Cpu1 */
   __non_return_call(MAIN_core1_main);
}

#define STARTUP_STOP_SEC_CODE
#include "STARTUP_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
