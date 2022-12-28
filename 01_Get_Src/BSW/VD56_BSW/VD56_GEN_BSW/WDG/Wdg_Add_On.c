/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : WDG                                                     */
/* !Description     : WDG Component                                           */
/*                                                                            */
/* !File            : Wdg_Add_On.c                                            */
/* !Description     : This file defines the add-on API of the WDG component.  */
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
 * %PID: P2017_BSW:0A111693.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"

#include "IfxScu_reg.h"
#include "Mcal.h"
#include "OS.h"
#include "SchM_Wdg_17_Scu.h"
#include "Wdg.h"
#include "Wdg_Cfg.h"

/******************************************************************************/
/*                      Private Macro Definitions                             */
/******************************************************************************/
/* Masks the 16bit WDT reload value */
#define WDG_MASK_WDTREL                (0xFFFF0000U)
/* Sets the WDTHPW1 and ENDINIT bit in WDTCON0 */
#define WDG_SET_WDTHPW1_ENDINIT        (0x000000F1U)
/* Sets the WDTHPW1, ENDINIT and WDTLCK bit in WDTCON0 */
#define WDG_SET_WDTHPW1_ENDINIT_WDTLCK (0x000000F3U)
/* Shift value of REL in WDTCPU0CON0 SFR*/
#define WDG_REL_SHIFT_VALUE            (16U)
/* Defines modify access value for WDTCON0 */
#define WDG_MODIFY_ACCESS              (0x000000F3U)
/* Shift value of REL in WDTCPU0CON0 SFR*/
#define WDG_REL_SHIFT_VALUE            (16U)
/* Register Mapping for WDG */
#define WDG_REGMAP              ((Ifx_SCU_WDTCPU *)(void *) &(SCU_WDTCPU0_CON0))

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

#define WDG_17_SCU_START_SEC_CODE
#include "WDG_17_SCU_MemMap.h"

/* Function to Access password before accessing ENDINIT registers */
static _INLINE_ uint32 Wdg_lAccessPassword(uint32 WdtCon0);

/* Function to Modify the ENDINIT registers */
static _INLINE_ uint32 Wdg_lReloadModifyAccess(uint16 ReloadValue);

/******************************************************************************/
/* !FuncName    : Wdg_lAccessPassword                                         */
/* !Description : Function to Access password before accessing ENDINIT        */
/*                      registers                                             */
/*                      Password Access:                                      */
/*       - (Bits[15:8])Set Hardware password WDTHPW1 TO 0                     */
/*       - (Bits[7:4])Set Hardware password TO 1111                           */
/*       - (Bits[3:2]) This field must be written with 0’s during a password  */
/*                   access to SCU_WDTCPU0_CON0.                              */
/*       - (Bit[1]) Set WDTLCK to '0' to unlock SCU_WDTCPUx_CON0              */
/*       - (Bit[0]) Set ENDINIT bit while password access                     */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
static _INLINE_ uint32 Wdg_lAccessPassword(uint32 WdtCon0)
{
  return (uint32)((WdtCon0 & WDG_MASK_WDTREL) | WDG_SET_WDTHPW1_ENDINIT);
}

/******************************************************************************/
/* !FuncName    : Wdg_lReloadModifyAccess                                     */
/* !Description : Function to Modify the ENDINIT registers                    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
static _INLINE_ uint32 Wdg_lReloadModifyAccess(uint16 ReloadValue)
{
  return(uint32)(((((uint32)(ReloadValue)) << WDG_REL_SHIFT_VALUE)&
                    WDG_MASK_WDTREL)|WDG_MODIFY_ACCESS);
}

/******************************************************************************/
/* !FuncName    : Wdg_vidRefreshCoreWatchdog                                  */
/* !Description : This function permits to refresh the wdg of specified core  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void Wdg_vidRefreshCoreWatchdog(uint8 u8CoreId)
{
   uint32 ModifyAccess;
   uint32 PasswordAccess;
   /* Local variable to hold the value of Watchdog Timer Control Register */
   uint32 WdtCon0;
   uint8 CoreId;
   CoreId = u8CoreId;
   
   /* Password Access: WDG037:
    - (Bits[7:4])Set Hardware password to WDTHPW1 TO 1111.
    - (Bits[3:2])This field must be written with the value of the bits
                 SCU_WDTCPU0_CON1.WDTDR and SCU_WDTCPU0_CON1.WDTIR.
    - (Bit[1])Set WDTLCK to '0' to unlock SCU_WDTCPU0_CON0.
    - (Bit[0])Write back the read ENDINIT bit.
   */
   /* Enter critical section - WDG040:*/
   SchM_Enter_Wdg_17_Scu_Trigger();
   WdtCon0 = WDG_REGMAP[CoreId].CON0.U;
   
   /* Password Access: WDG037:  
      - (Bits[15:8])Set Hardware password WDTHPW1 TO 0
      - (Bits[7:4])Set Hardware password TO 1111
      - (Bits[3:2]) This field must be written with 0’s during a password
                    access to SCU_WDTCPU0_CON0.
      - (Bit[1]) Set WDTLCK to '0' to unlock SCU_WDTCPUx_CON0
      - (Bit[0]) Set ENDINIT bit while password access
   */
   
   PasswordAccess = Wdg_lAccessPassword(WdtCon0);
   WDG_REGMAP[CoreId].CON0.U = (uint32)PasswordAccess;  /* PASSWORD ACCESS */
   /* Modify Access: WDG009:
      - (Bits[15:8])Set Hardware password WDTHPW1 TO 0
      - (Bits[7:4])Set Hardware password TO 1111
      - (Bits[3:2]) This field must be written with 0’s during a modify
                    access to SCU_WDTCPU0_CON0.
      - (Bit[1]) Set WDTLCK to '1' to unlock SCU_WDTCPUx_CON0
      - (Bit[0]) Set ENDINIT bit to '1' while modify access
   */
   ModifyAccess = PasswordAccess | WDG_SET_WDTHPW1_ENDINIT_WDTLCK;
   WDG_REGMAP[CoreId].CON0.U = (uint32)ModifyAccess;    /* MODIFY ACCESS */
   
   WdtCon0 =(uint32)WDG_REGMAP[CoreId].CON0.U;
   PasswordAccess = Wdg_lAccessPassword(WdtCon0);
   WDG_REGMAP[CoreId].CON0.U = (uint32)PasswordAccess;/* PASSWORD ACCESS */
   /* Update with the existing Reload Value */
   ModifyAccess = Wdg_lReloadModifyAccess(WDG_u16RELOAD_VALUE);
   WDG_REGMAP[CoreId].CON0.U = (uint32)ModifyAccess; /* RELOAD VALUE UPDATE */
   
   /* Exit critical section - WDG040: */
   SchM_Exit_Wdg_17_Scu_Trigger();
}

#define WDG_17_SCU_STOP_SEC_CODE
#include "WDG_17_SCU_MemMap.h"

/*-------------------------------- end of file -------------------------------*/