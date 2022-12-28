/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : ECUM                                                    */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : EcuM_Callout_Stubs.c                                    */
/* !Description     : This file provides ECUM callout definitions             */
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
 * %PID: P2017_BSW:0A111736.A-SRC;3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : EcuM_Callout_Stubs.c                                          **
**                                                                            **
**  VERSION   : 0.1.4                                                         **
**                                                                            **
**  DATE      : 2013-03-19                                                    **
**                                                                            **
**  VARIANT   : NA                                                            **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Independant                                                   **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file provides ECUM callout definitions                **
**                 This file is for Evaluation Purpose Only                   **
**                                                                            **
**  SPECIFICATION(S) : ECUM State Manager                                     **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** VS         Vinod Shankar                                                   **
** SKB        Sai Kiran B                                                     **
** AT         Angeswaran Thangaswamy                                          **
** SV         Shivashankara V                                                 **
** SGN        Gururaj Nath S                                                  **
** AK         Ashish Kumar                                                    **
** SS         Srinivas Shenoy                                                 **
** DNS        Deepak Nair S                                                   **
**  KP        Kaushal Purohit                                                 **
********************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* 
 * V0.1.4: 2013-03-19,  KP  : updated for VendoApiInfix for LIN
 * V0.1.3: 2013-03-11, SGN  : updated for VendoApiInfix for CAN
 * V0.1.2: 2013-02-28, DNS  : updated for VendoApiInfix for PWM.
 * V0.1.2: 2013-02-26, Vani  : updated for VendoApiInfix for FLS.
 * V0.1.2: 2013-02-15, SS  : VendorApiInfix changes
 * V0.1.1: 2012-11-29, AT  : Unuse param warning removed.
 * V0.1.0: 2012-11-23, basavath: Support for IOM
 * V0.0.9: 2012-10-19, AK  : Support for SENT
 * V0.0.8: 2012-09-10, VS  : Included IRQ for CCU6x. UTP AI00066335
 * V0.0.7: 2012.08.03, PB  : Ethernet IRQInit has been included.
 * V0.0.6: 2012.08.02, MK  : SMU reset enabled only for CPU0_WDG and Safety_WDG
 * V0.0.5: 2012.04.27, Can.h changed to Can_17.h
 * V0.0.4: 2011.10.24, SV: Workaround for  system reset on WDG overflow
 * V0.0.3: 2011.09.19, Ravi: Updated Fls to Fls_17
 * V0.0.2: 2011.03.24, AT  : Included Dio
 * V0.0.1: 2011.03.07, SKB : Initial version
*/

#include "Std_Types.h"
#include "EcuM.h"
#include "EcuM_Cbk.h"
#include "Os.h"
#include "Os_DisableInterrupts.h"
#include "Mcu.h"
/* Inclusion of controller sfr file */
#include "IfxScu_reg.h"
#include "IfxSmu_reg.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

#define ECUM_START_SEC_CODE
#include "ECUM_MemMap.h"

/*******************************************************************************
** Syntax           : void EcuM_AL_DriverInitOne(const EcuM_ConfigType        **
                                                 *configptr)                  **
**                                                                            **
** Description      : initializes clock and interrupts                        **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
void EcuM_AL_DriverInitOne(const EcuM_ConfigType *configptr) 
{
   /* Initialize MCU Clock */
   /* parameter 0 is chosen here by default, the first clock configuration */
   Mcu_InitClock(0);    
   /* wait till PLL lock */
   while(Mcu_GetPllStatus() == 0);
   /* distribute the clock */
   Mcu_DistributePllClock();  
  
   /* Below piece of code is a workaround due to the hardware bug for 
      system reset on WDG overflow */
   Mcal_ResetSafetyENDINIT();
   SMU_KEYS.U    = 0xbc; /* Allow SMU configuration */
   SMU_CMD.U     = 0x00;
   /* Enable NMI trap in case of watchdog trigger */
   SMU_AGCF3_0.U = 0x001E0000;
   SMU_AGCF3_1.U = 0x00000000;
   SMU_AGCF3_2.U = 0x001E0000;
   Mcal_SetSafetyENDINIT();

   Mcal_ResetENDINIT();
   /* Allows Trap generation by SCU module: used to generate an NMI trap when a watchdog is triggered */
   SCU_TRAPDIS.B.SMUT = 0U;
   Mcal_SetENDINIT();

   /* Clear of all pending SRC ITs */
   Os_DisableAllConfiguredInterrupts();

   /* Initialization of Interrupt Priorities */
   /* INTBSL_vidInit(); */

   /* This is a macro defined in the EcuM_Cfg.h. The body of this call is 
      generated from the configuration tool */
   EcuM_DriverInitListOneConfig(configptr);  
}

/*******************************************************************************
** Syntax           : void EcuM_AL_DriverInitTwo(const EcuM_ConfigType        **
**                                               *configptr)                  **
**                                                                            **
**                                                                            **
** Description      : list two driver intialization                           **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
void EcuM_AL_DriverInitTwo(const EcuM_ConfigType *configptr) 
{
   /* This is a macro defined in the EcuM_Cfg.h. The body of this call is 
      generated from the configuration tool */
   EcuM_DriverInitListTwoConfig(configptr);
   /* unused param warning removal for GNU */
   COMPILER_UNUSED_PARAMETER(configptr);
}

/*******************************************************************************
** Syntax           : void EcuM_AL_DriverInitThree(const EcuM_ConfigType      **
**                                                 *configptr)                **
**                                                                            **
**                                                                            **
** Description      : List three intialization                                **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
void EcuM_AL_DriverInitThree(const EcuM_ConfigType *configptr) 
{
   /* This is a macro defined in the EcuM_Cfg.h. The body of this call is 
      generated from the configuration tool */
   EcuM_DriverInitListThreeConfig(configptr);
   /* unused param warning removal for GNU */
   COMPILER_UNUSED_PARAMETER(configptr);
}

/*******************************************************************************
** Syntax           : void EcuM_AL_DriverInitZero()                           **
**                                                                            **
** Service ID       : 0                                                       **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : List zero, modules like DET can be initialized          **
**                    post build modules cannot be loaded from here           **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
void EcuM_AL_DriverInitZero() 
{
   /* This is a macro defined in the EcuM_Cfg.h. The body of this call is
      generated from the configuration tool */
   EcuM_DriverInitListZeroConfig();

}

#define ECUM_STOP_SEC_CODE
#include "ECUM_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
