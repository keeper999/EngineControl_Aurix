/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : ADCBSL                                                  */
/* !Description     : Analog digital converter                                */
/*                                                                            */
/* !File            : ADCBSL.c                                                */
/* !Description     :                                                         */
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
 * %PID: P2017_BSW:A17859.A-SRC;6 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "ADCBSL.h"
#include "ADCBSL_Cfg.h"
#include "IfxVadc_reg.h"
#include "IfxVadc_bf.h"
#include "Mcal.h"
#include "SWFAIL.h"


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/

#define ADCBSL_START_SEC_CODE
#include "ADCBSL_MemMap.h"

/******************************************************************************/
/* !FuncName    : ADCBSL_vidInit                                              */
/* !Description : Initialization of the ADCBSL registers and start of first   */
/*                conversion of configured channels                           */
/*                                                                            */
/* !LastAuthor  : TBOU                                                        */
/******************************************************************************/
void ADCBSL_vidInit(void)
{
   volatile uint32 ReadBack;
   uint32 u32LocalLoopIndex;

   Mcal_ResetENDINIT();
   /* Enable the ADC Module                                                   */
   ADC_MODULE_GLOB.CLC.U = 0x00000008;
   /* DISR = 0x0; DISS = 0x0; EDIS = 0x1;                                     */
   /* Kernel Reset Status Clear Register set to reset value                   */
   ADC_MODULE_GLOB.KRSTCLR.U = 0x00000000;
   Mcal_SetENDINIT();

   /* Read back the CLC register                                              */
   ReadBack = ADC_MODULE_GLOB.CLC.U;
   if (ReadBack != 0x00000008)
   {
      SWFAIL_vidSoftwareErrorHook();
   }

   /* Enabling of the converter. Shall be done before start-up calibration    */
   ADC_MODULE_GLOB.G[0].ARBCFG.U = 0x0;
   ADC_MODULE_GLOB.G[1].ARBCFG.U = 0x0;
   ADC_MODULE_GLOB.G[2].ARBCFG.U = 0x0;
   ADC_MODULE_GLOB.G[3].ARBCFG.U = 0x0;
   ADC_MODULE_GLOB.G[4].ARBCFG.U = 0x0;
   ADC_MODULE_GLOB.G[5].ARBCFG.U = 0x0;
   /* ANONC = 0x0; ARBRND = 0x0; ARBM =0x0                                    */
   ADC_MODULE_GLOB.G[6].ARBCFG.U = 0x0;
   ADC_MODULE_GLOB.G[7].ARBCFG.U = 0x0;

   /* Synchronization Control Register, Group  */
   ADC_MODULE_GLOB.G[0].SYNCTR.U = 0x00000070;
   ADC_MODULE_GLOB.G[1].SYNCTR.U = 0x00000071;
   ADC_MODULE_GLOB.G[2].SYNCTR.U = 0x00000071;
   ADC_MODULE_GLOB.G[3].SYNCTR.U = 0x00000071;
   ADC_MODULE_GLOB.G[4].SYNCTR.U = 0x00000011;
   ADC_MODULE_GLOB.G[5].SYNCTR.U = 0x00000010;
   ADC_MODULE_GLOB.G[6].SYNCTR.U = 0x00000000;
   ADC_MODULE_GLOB.G[7].SYNCTR.U = 0x00000000;
   /* STSEL = 0x0 for masters ; STSEL = 0x1 for slaves                        */
   /* Groups 0,1,2,3 : EVALR1 = 0x1 ; EVALR2 = 0x1 ; EVALR3 = 0x1             */
   /* Groups 4,5 : EVALR1 = 0x1 ; EVALR2 = 0x0 ; EVALR3 = 0x0                 */

   /* Master shall be initialized last                                        */
   ADC_MODULE_GLOB.G[0].ARBCFG.U = 0x3;
   ADC_MODULE_GLOB.G[5].ARBCFG.U = 0x3;
   /* ANONC = 0x3; ARBRND = 0x0; ARBM = 0x0                                   */

   /* Global Configuration Register                                           */
   ADC_MODULE_GLOB.GLOBCFG.U = 0x8000800B;
   /* DIVA = 0xB (fVADC = 100 MHz, fADCl = 8.33 Mhz); DCMSB = 0x0; DIVD = 0x0 */
   /* (fVADCD = 100 MHz); DIVWC = 0x1; DPCAL(0-7) = 0x0; SUCAL = 0x1;         */
   /* Hardware calibration are activated and initial calibration are launched */

   /* Background Request Source Pending Register set to reset value           */
   ADC_MODULE_GLOB.BRSPND[u32LocalLoopIndex].U= 0x00000000;

   /* Background Request Source Channel Select Register, selects which        */
   /* channels are part of the background sequence                            */
   ADC_MODULE_GLOB.BRSSEL[0].U = 0x000000FF;
   ADC_MODULE_GLOB.BRSSEL[1].U = 0x00000000;
   ADC_MODULE_GLOB.BRSSEL[2].U = 0x00000000;
   ADC_MODULE_GLOB.BRSSEL[3].U = 0x00000000;
   ADC_MODULE_GLOB.BRSSEL[4].U = 0x00000000;
   ADC_MODULE_GLOB.BRSSEL[5].U = 0x000000FF;
   ADC_MODULE_GLOB.BRSSEL[6].U = 0x00000000;
   ADC_MODULE_GLOB.BRSSEL[7].U = 0x00000000;

   /* Autoscan Source Pending Register set to reset value                     */
   ADC_MODULE_GLOB.G[0].ASPND.U = 0x00000000;
   ADC_MODULE_GLOB.G[1].ASPND.U = 0x00000000;
   ADC_MODULE_GLOB.G[2].ASPND.U = 0x00000000;
   ADC_MODULE_GLOB.G[3].ASPND.U = 0x00000000;
   ADC_MODULE_GLOB.G[4].ASPND.U = 0x00000000;
   ADC_MODULE_GLOB.G[5].ASPND.U = 0x00000000;
   ADC_MODULE_GLOB.G[6].ASPND.U = 0x00000000;
   ADC_MODULE_GLOB.G[7].ASPND.U = 0x00000000;

   /* Channel Assignment Register, selects which channels are background      */
   /* or priority channels                                                    */
   ADC_MODULE_GLOB.G[0].CHASS.U = 0x00000000;
   ADC_MODULE_GLOB.G[1].CHASS.U = 0x00000000;
   ADC_MODULE_GLOB.G[2].CHASS.U = 0x00000000;
   ADC_MODULE_GLOB.G[3].CHASS.U = 0x00000000;
   ADC_MODULE_GLOB.G[4].CHASS.U = 0x00000000;
   ADC_MODULE_GLOB.G[5].CHASS.U = 0x00000000;
   ADC_MODULE_GLOB.G[6].CHASS.U = 0x00000000;
   ADC_MODULE_GLOB.G[7].CHASS.U = 0x00000000;

   /* Result Assignment Register, selects which result registers can be       */
   /* written by background source                                            */
   ADC_MODULE_GLOB.G[0].RRASS.U = 0x00000000;
   ADC_MODULE_GLOB.G[1].RRASS.U = 0x00000000;
   ADC_MODULE_GLOB.G[2].RRASS.U = 0x00000000;
   ADC_MODULE_GLOB.G[3].RRASS.U = 0x00000000;
   ADC_MODULE_GLOB.G[4].RRASS.U = 0x00000000;
   ADC_MODULE_GLOB.G[5].RRASS.U = 0x00000000;
   ADC_MODULE_GLOB.G[6].RRASS.U = 0x00000000;
   ADC_MODULE_GLOB.G[7].RRASS.U = 0x00000000;

   /* Arbitration Priority Register, enables background and scan sources and  */
   /* sets priorities                                                         */
   ADC_MODULE_GLOB.G[0].ARBPR.U = 0x04000000;
   ADC_MODULE_GLOB.G[1].ARBPR.U = 0x04000000;
   ADC_MODULE_GLOB.G[2].ARBPR.U = 0x04000000;
   ADC_MODULE_GLOB.G[3].ARBPR.U = 0x04000000;
   ADC_MODULE_GLOB.G[4].ARBPR.U = 0x04000000;
   ADC_MODULE_GLOB.G[5].ARBPR.U = 0x04000000;
   ADC_MODULE_GLOB.G[6].ARBPR.U = 0x00000000;
   ADC_MODULE_GLOB.G[7].ARBPR.U = 0x00000000;

   /* Background Request Source Mode Register, configures the background      */
   /* source                                                                  */
   ADC_MODULE_GLOB.BRSMR.U = 0x00000011;
   /* ENGT = 0x1; ENTR = 0x0; ENSI = 0x0; SCAN = 0x1; LDM = 0x0; REQGT = 0x0; */
   /* CLRPND = 0x0; LDEV = 0x0; RPTDIS = 0x0;                                 */

   /* Configuration of GyCHCTRx : conversion result of channel x of Hw unit y */
   /* is put in register GyRESx. To do so, RESTBS = 0x0; RESREG = x;          */
   /* RESPOS =0x1;                                                            */
   /* SYNC = 0x1 for all G0RESx and G5RESx (masters of parallel mode)         */
   /* SYNC = 0x0 for G5RES4 and G5RES5                                        */
   /* All groups have REFSEL = 0x0 (VREF)                                     */
   for (u32LocalLoopIndex = 0; u32LocalLoopIndex < 8; u32LocalLoopIndex ++)
   {
      ADC_MODULE_GLOB.G[0].CHCTR[u32LocalLoopIndex].U = (0x00200000 
                                                 | (u32LocalLoopIndex << 0x10)
                                                 | (0x1 << 0xA));
      ADC_MODULE_GLOB.G[1].CHCTR[u32LocalLoopIndex].U = (0x00200000 
                                                 | (u32LocalLoopIndex << 0x10));
      ADC_MODULE_GLOB.G[2].CHCTR[u32LocalLoopIndex].U = (0x00200000 
                                                 | (u32LocalLoopIndex << 0x10));
      ADC_MODULE_GLOB.G[3].CHCTR[u32LocalLoopIndex].U = (0x00200000 
                                                 | (u32LocalLoopIndex << 0x10));
      ADC_MODULE_GLOB.G[4].CHCTR[u32LocalLoopIndex].U = (0x00200000 
                                                 | (u32LocalLoopIndex << 0x10));
      ADC_MODULE_GLOB.G[5].CHCTR[u32LocalLoopIndex].U = (0x00200000 
                                                   | (u32LocalLoopIndex << 0x10)
                                                 | (0x1 << 0xA));
      ADC_MODULE_GLOB.G[6].CHCTR[u32LocalLoopIndex].U = 0x00000000;
      ADC_MODULE_GLOB.G[7].CHCTR[u32LocalLoopIndex].U = 0x00000000;
   }

   /***************************************************************************/
   /* Following registers are not used in our application, so they are        */
   /* initialized with their reset value.                                     */
   /***************************************************************************/

   Mcal_ResetSafetyENDINIT();
   ADC_MODULE_GLOB.ACCEN0.U = 0xFFFFFFFF; /* Access Enable Register 0 */
   ADC_MODULE_GLOB.ACCPROT0.U = 0x00000000; /* Access Protection Register */
   ADC_MODULE_GLOB.ACCPROT1.U = 0x00000000; /* Access Protection Register */
   Mcal_SetSafetyENDINIT();

   ADC_MODULE_GLOB.OCS.U = 0x10000008; /* OCDS Control and Status Register */
   ADC_MODULE_GLOB.GLOBICLASS[0].U = 0x00000000; /* Input Class Register */
   ADC_MODULE_GLOB.GLOBICLASS[1].U = 0x00000000; /* Input Class Register */
   ADC_MODULE_GLOB.GLOBBOUND.U = 0x00000000; /* Global Boundary Select Register */
   ADC_MODULE_GLOB.GLOBEFLAG.U = 0x00000000; /* Global Event Flag Register */
   ADC_MODULE_GLOB.GLOBEVNP.U = 0x00000000; /* Global Event Node Pointer Register */
   ADC_MODULE_GLOB.GLOBTF.U = 0x00808000; /* Global Test Functions Register */
   ADC_MODULE_GLOB.GLOBRCR.U = 0x00000000; /* Global Result Control Register */
   ADC_MODULE_GLOB.BRSCTRL.U = 0x00808000; /* Background Request Source Control Register */
   ADC_MODULE_GLOB.EMUXSEL.U = 0x00000000; /* External Multiplexer Select Register */

   for (u32LocalLoopIndex = 0 ; u32LocalLoopIndex < 8; u32LocalLoopIndex ++)
   {
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].ASCTRL.U = 0x80808000; /* Autoscan Source Control Register, Group */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].ASMR.U = 0x00000000; /* Autoscan Source Mode Register */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].ASSEL.U = 0x00000000; /* Autoscan Source Channel Select Register */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].ICLASS[0].U = 0x00000000; /* Input Class Register */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].ICLASS[1].U = 0x00000000; /* Input Class Register */ 
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].ALIAS.U = 0x00000100; /* Alias Register, Group  */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].BOUND.U = 0x00000000; /* Boundary Select Register, Group  */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].BFL.U = 0x00000000; /* Boundary Flag Register, Group  */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].BFLS.U = 0x00000000; /* Boundary Flag Software Register, Group  */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].BFLC.U = 0x00000000; /* Boundary Flag Control Register, Group  */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].BFLNP.U = 0x0000FFFF; /* Boundary Flag Node Pointer Register, Group  */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].QCTRL0.U = 0x80808000; /* Queue 0 Source Control Register, Group  */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].QMR0.U = 0x00000000; /* Queue 0 Mode Register, Group  */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].QBUR_QINR0.U = 0x00000000; /* Queue 0 Input Register, Group  */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].CEFCLR.U = 0x00000000; /* Channel Event Flag Clear Register, Group  */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].REFCLR.U = 0x00000000; /* Result Event Flag Clear Register, Group  */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].SEFCLR.U = 0x00000000; /* Source Event Flag Clear Register, Group  */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].CEVNP0.U = 0x00000000; /* Channel Event Node Pointer Register 0, Group  */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].REVNP0.U = 0x00000000; /* Result Event Node Pointer Register 0, Group  */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].REVNP1.U = 0x00000000; /* Result Event Node Pointer Register 1, Group  */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].SEVNP.U = 0x00000000; /* Source Event Node Pointer Register, Group  */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].SRACT.U = 0x00000000; /* Service Request Software Activation Trigger, Group  */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].EMUXCTR.U = 0x80000000; /* External Multiplexer Control Register, Group x */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].VFR.U = 0x00000000; /* Valid Flag Register, Group  */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].RCR[0].U = 0x00000000; /* Group Result Control Reg. */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].RCR[1].U = 0x00000000; /* Group Result Control Reg. */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].RCR[2].U = 0x00000000; /* Group Result Control Reg. */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].RCR[3].U = 0x00000000; /* Group Result Control Reg. */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].RCR[4].U = 0x00000000; /* Group Result Control Reg. */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].RCR[5].U = 0x00000000; /* Group Result Control Reg. */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].RCR[6].U = 0x00000000; /* Group Result Control Reg. */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].RCR[7].U = 0x00000000; /* Group Result Control Reg. */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].RCR[8].U = 0x00000000; /* Group Result Control Reg. */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].RCR[9].U = 0x00000000; /* Group Result Control Reg. */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].RCR[10].U = 0x00000000; /* Group Result Control Reg. */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].RCR[11].U = 0x00000000; /* Group Result Control Reg. */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].RCR[12].U = 0x00000000; /* Group Result Control Reg. */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].RCR[13].U = 0x00000000; /* Group Result Control Reg. */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].RCR[14].U = 0x00000000; /* Group Result Control Reg. */
      ADC_MODULE_GLOB.G[u32LocalLoopIndex].RCR[15].U = 0x00000000; /* Group Result Control Reg. */
   }

   /***************************************************************************/
   /* All registers are configured.                                           */
   /***************************************************************************/

   /* wait until start-up calibration is done(CALS = 1, CAL = 0: calibr done) */
   /* timeout of 10000 loop is implemented (approximatively 300 us)           */
   u32LocalLoopIndex = 0;

   while (  (  ((VADC_G0ARBCFG.U & 0x30000000) != 0x20000000)
            || ((VADC_G1ARBCFG.U & 0x30000000) != 0x20000000)
            || ((VADC_G2ARBCFG.U & 0x30000000) != 0x20000000)
            || ((VADC_G3ARBCFG.U & 0x30000000) != 0x20000000)
            || ((VADC_G4ARBCFG.U & 0x30000000) != 0x20000000)
            || ((VADC_G5ARBCFG.U & 0x30000000) != 0x20000000)
/*            || ((VADC_G6ARBCFG.U & 0x30000000) != 0x20000000)*/
/*            || ((VADC_G7ARBCFG.U & 0x30000000) != 0x20000000)*/
            )
         && (u32LocalLoopIndex < 10000))
   {
      u32LocalLoopIndex++;
   }
   if (u32LocalLoopIndex >= 10000)
   {
      SWFAIL_vidSoftwareErrorHook();
   }

   /*Launch conversions (background)*/
   ADC_MODULE_GLOB.BRSMR.B.LDEV = 0x1;

}

/******************************************************************************/
/* !FuncName    : ADCBSL_vidWaitInitCompletion                                */
/* !Description : Wait until first conversion is done                         */
/*                                                                            */
/* !LastAuthor  : TBOU                                                        */
/******************************************************************************/
void ADCBSL_vidWaitInitCompletion(void)
{
   uint32 u32LocalLoopIndex;

   /* wait until first conversion is done (VFR written when result available) */
   /* timeout of 10000 loop is implemented (approximatively 300 us)           */
   u32LocalLoopIndex = 0;

   while (  (  (VADC_G0_VFR.U != 0x000000FF)
            || (VADC_G1_VFR.U != 0x000000FF)
            || (VADC_G2_VFR.U != 0x000000FF)
            || (VADC_G3_VFR.U != 0x000000FF)
            || (VADC_G4_VFR.U != 0x000000FF)
            || (VADC_G5_VFR.U != 0x000000FF)
/*            || (VADC_G6_VFR.U != 0x000000FF)*/
/*            || (VADC_G7_VFR.U != 0x000000FF)*/
            )
         && (u32LocalLoopIndex < 10000))
   {
      u32LocalLoopIndex++;
   }
   if (u32LocalLoopIndex >= 10000)
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

#define ADCBSL_STOP_SEC_CODE
#include "ADCBSL_MemMap.h"

/*------------------------------ end of file ---------------------------------*/
