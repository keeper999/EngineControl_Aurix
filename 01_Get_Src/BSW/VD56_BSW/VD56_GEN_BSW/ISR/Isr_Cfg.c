/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : ISR                                                     */
/* !Description     : ISR Management                                          */
/*                                                                            */
/* !File            : Isr_Cfg.c                                               */
/* !Description     : ISR definition                                          */
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
 * %PID: P2017_BSW:0A192448.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "ISR_Cfg.h"
#include "Os.h"
#include "Os_Cfg.h"
#include "SWFAIL_Cfg.h"

#define GEN_BSW_START_SEC_CODE
#include "GEN_BSW_MemMap.h"

CAT1_ISR(SWFAIL_vidNotHandledISR)
{
   SWFAIL_vidNotHandledISRHook();
   OsDrvIsrEndHook();
}


void DMADRV_vidInit(void)
{
   __disable();  /* sufficient because only 1 cpu manages ITs */

   INTBSL_vidCONFIG_SRC(QSPI_QSPI0_RX);
   INTBSL_vidCONFIG_SRC(QSPI_QSPI0_TX);
   INTBSL_vidCONFIG_SRC(QSPI_QSPI2_RX);
   INTBSL_vidCONFIG_SRC(QSPI_QSPI2_TX);
   INTBSL_vidCONFIG_SRC(QSPI_QSPI4_RX);
   INTBSL_vidCONFIG_SRC(QSPI_QSPI4_TX);
   INTBSL_vidCONFIG_SRC(MSC_MSC0_SR1);
   INTBSL_vidCONFIG_SRC(DSADC_DSADC3_SRM);
}

void DMADRV_vidDeInit(void)
{
   INTBSL_vidRESET_SRC(QSPI_QSPI0_RX);
   INTBSL_vidRESET_SRC(QSPI_QSPI0_TX);
   INTBSL_vidRESET_SRC(QSPI_QSPI2_RX);
   INTBSL_vidRESET_SRC(QSPI_QSPI2_TX);
   INTBSL_vidRESET_SRC(QSPI_QSPI4_RX);
   INTBSL_vidRESET_SRC(QSPI_QSPI4_TX);
   INTBSL_vidRESET_SRC(MSC_MSC0_SR1);
   INTBSL_vidRESET_SRC(DSADC_DSADC3_SRM);
}

#define GEN_BSW_STOP_SEC_CODE
#include "GEN_BSW_MemMap.h"

/*-------------------------------- end of file -------------------------------*/


