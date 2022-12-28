/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : STARTUP                                                 */
/* !Description     : Start-up                                                */
/*                                                                            */
/* !File            : STARTUP_Core0.c                                         */
/* !Description     : Start-up software of Core 0                             */
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
 * %PID: P2017_BSW:0A111710.A-SRC;4 %
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
#include "Mcal.h"
#include "Os.h"
#include "Os_Cfg.h"
#include "STARTUP.h"
#include "Wdg.h"

#define STARTUP_START_SEC_BMHD_0
#include "STARTUP_MemMap.h"

/******************************************************************************/
/* !FuncName    : Boot Mode Headers                                           */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
/* Boot Mode Header 0 sections to inform linker to locate them at 0x80000000  */
/* STADBM has to be initialized if Alternate Boot Mode is used.               */
/* Else first user code has to be placed at 0x80000020                        */
const uint32 STARTUP_BootModeHeader_0[] =
{
   0x00000000,   /* STADBM:first user code in Alternate Boot Mode */
   0xB3590070,   /* BMI = 0070h BMHDID = B359h */
   0x00000000,   /* ChkStart */
   0x00000000,   /* ChkEnd */
   0x00000000,   /* CRCrange */
   0x00000000,   /* !CRCrange */
   0x791EB864,   /* CRChead */
   0x86E1479B    /* !CRChead */
};

#define STARTUP_STOP_SEC_BMHD_0
#include "STARTUP_MemMap.h"


/* Boot Mode Header 1 sections to inform linker to locate them at 0x80020000  */
#define STARTUP_START_SEC_BMHD_1
#include "STARTUP_MemMap.h"

/* STADBM has to be initialized if Alternate Boot Mode is used.               */
/* Else first user code has to be placed at 0x80000020                        */
const uint32 STARTUP_BootModeHeader_1[] =
{
   0x00000000,   /* STADBM:first user code in Alternate Boot Mode */
   0xB3590070,   /* BMI = 0070h BMHDID = B359h */
   0x00000000,   /* ChkStart */
   0x00000000,   /* ChkEnd */
   0x00000000,   /* CRCrange */
   0x00000000,   /* !CRCrange */
   0x791EB864,   /* CRChead */
   0x86E1479B    /* !CRChead */
};

#define STARTUP_STOP_SEC_BMHD_1
#include "STARTUP_MemMap.h"


#define STARTUP_START_SEC_RESET_CODE
#include "STARTUP_MemMap.h"

/******************************************************************************/
/* !FuncName    : STARTUP_START                                               */
/* !Description : Reset function                                              */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void STARTUP_START(void)
{
   __non_return_call(STARTUP_Core0_start);
}

#define STARTUP_STOP_SEC_RESET_CODE
#include "STARTUP_MemMap.h"


#define STARTUP_START_SEC_CODE
#include "STARTUP_MemMap.h"

/******************************************************************************/
/* !FuncName    : STARTUP_Core0_start                                         */
/* !Description : Startup Function of Core 0                                  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void STARTUP_Core0_start(void)
{
   uint16 u16LocalWdtPassword =
      IfxScuWdt_getCpuWatchdogPasswordInline(&MODULE_SCU.WDTCPU[0]);
   sint32 *ps32LocalPrevCsa;
   sint32 s32LocalLoopCount;
   sint32 s32LocalNnOfCsas;
   uint32 u32LocalPcxi;
   uint32 u32LocalSegmentNr, u32LocalSegmentIdx, u32LocalPcxiVal = 0;
   StatusType udtLocalstatus;

   /* Initialization of SDA base pointers */
   __setareg(a0, __SDATA1_0);
   __setareg(a1, __SDATA2_0);
   __setareg(a8, __SDATA3_0);
   __setareg(a9, __SDATA4_0);

   /* Load user stack pointer */
   __setareg(sp, __USTACK0);
   __dsync();

   /* Set the PSW to its reset value in case of a warm start,clear PSW.IS */
   __mtcr(CPU_PSW, STARTUP_CORE0_PSW_DEFAULT);
   __isync() ;

   /* Set the PCXS and PCXO to its reset value in case of a warm start */
   u32LocalPcxi  = __mfcr(CPU_PCXI);
   u32LocalPcxi &= STARTUP_CORE0_PCX_O_S_DEFAULT; /*0xfff00000; */
   __mtcr(CPU_PCXI, u32LocalPcxi);

   /* Setup the context save area linked list. */
   /* First calculate nr of CSAs in this area  */
   s32LocalNnOfCsas = ((sint32 *) __CSA0_END - (sint32 *) __CSA0) >> 4;
   ps32LocalPrevCsa = (sint32 *) __CSA0;

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
   IfxScuWdt_clearCpuEndinitInline(&MODULE_SCU.WDTCPU[0], u16LocalWdtPassword);

   /* Load Base Address of Trap Vector Table               */
   __mtcr(CPU_BTV, (uint32)__TRAPTAB);

   /* Load interupt stack pointer                          */
   __mtcr(CPU_ISP, (uint32)__ISTACK0);

   /* Enable Program Cache */
   IfxCpu_setProgramCache(STARTUP_CORE0_ENA_PCACHE);

   /* Enable Data Cache if Configured */
   IfxCpu_setDataCache(STARTUP_CORE0_ENA_DCACHE);

   /* Set the ENDINIT bit in the WDT_CON0 register again to enable the write-protection and to prevent a time-out. */
   // Mcal_SetENDINIT();
   IfxScuWdt_setCpuEndinitInline(&MODULE_SCU.WDTCPU[0], u16LocalWdtPassword);

   /* Disable of internal Core0 Watchdog and internal Safety Watgdog          */
   IfxScuWdt_disableCpuWatchdog(u16LocalWdtPassword);
   IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());

   /* Initialization of C runtime variables excepting the uncleared RAM which */
   /* is initialized in KRN component regarding reset Type                     */
   Mcal_Gnu_CopyTable((uint32)&__clear_table, (uint32)&__copy_table);

   /*Start remaining cores */
   /*core 0 shall also be started ! */
   StartCore(OS_CORE_ID_0, &udtLocalstatus);
   StartCore(OS_CORE_ID_1, &udtLocalstatus);
   StartCore(OS_CORE_ID_2, &udtLocalstatus);

   /* EcuM Init will be done only after all the other cores startup is        */
   /* completed. This is because, if any of Core0's code accesses information */
   /* belonging to other cores, then this information will not hold correct   */
   /* value until copy table is initialized. Also, if Core 0 updates a        */
   /* variable that resides in the memory allocated to other cores, then this */
   /* data will  vanish during the copy table/clear table routine of the other*/
   /* cores. Hence it is safe to wait for the completion of the startup of the*/
   /*  other cores before starting the application                            */
   while (  (Mcal_u8CpuInitCompletedSem[1] != 1)
         && (Mcal_u8CpuInitCompletedSem[2] != 1));
   Mcal_EcuMInit();

   /* This line will signify basic initializations are completed by CPU0.     */
   /* Other initializations can be started by other cores from now on         */
   Mcal_u8CpuInitCompletedSem[0] = 1;

   /* Call main function of Cpu0 */
   __non_return_call(MAIN_core0_main);
}

#define STARTUP_STOP_SEC_CODE
#include "STARTUP_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
