/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Wdg_17_Scu_Safe.c $                                        **
**                                                                           **
**  $CC VERSION : \main\17 $                                                 **
**                                                                           **
**  $DATE       : 2013-11-08 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains functionality of WDG driver with safety **
**                                                                           **
**  MAY BE CHANGED BY USER [yes or no]: No                                   **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Traceability : [cover parentID=SAS_MCAL_SWSC_WDG_0508][/cover]            */
  /* Inclusion of controller sfr file */
#include "IfxScu_reg.h"

/* Global functions like Set/Reset END INIT protection bit,
  Enable/Disable interrupts, Automic write function */
#include "Mcal.h"

/* Include WDG header file */
#include "Wdg_17_Scu.h"
/* Include Safe WDG header file */
#include "Wdg_17_Scu_Safe.h"
/* Include SchM_Wdg header file to export EA access functions */

#include "SchM_17_McalCfg.h"
#include SCHM_WDG_17_SCU_HEADER

/** Traceability : [cover parentID=SAS_AS_WDG062, DS_AS_WDG110][/cover]  */
#if( (WDG_DISABLE_REJECT_DEM_REPORT == ENABLE_DEM_REPORT) ||\
     (WDG_MODE_FAIL_DEM_REPORT == ENABLE_DEM_REPORT) )
#include "Dem.h"
#endif


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/* Masks the 16bit WDT reload value */
#define WDG_MASK_WDTREL                (0xFFFF0000U)
/* Sets the WDTHPW1 and ENDINIT bit in WDTCON0 */
#define WDG_SET_WDTHPW1_ENDINIT        (0x000000F1U)
/* Sets the WDTHPW1, ENDINIT and WDTLCK bit in WDTCON0 */
#define WDG_SET_WDTHPW1_ENDINIT_WDTLCK (0x000000F3U)
/* Sets the WDTIR bit and enables the watchdog by resetting WDTDR
   bit in WDTCON1 */
#define WDG_SET_WDTIR_RESET_WDTDR      (0x00000004U)
/* Resets the WDTIR bit and enables the watchdog by resetting WDTDR
   bit in WDTCON1 */
#define WDG_RESET_WDTIR_RESET_WDTDR    (0x00000000U)
/* Defines modify access value for WDTCON0 */
#define WDG_MODIFY_ACCESS              (0x000000F3U)
/* Clear WDTIR and WDTDR bits in SCU_WDTCPU0_CON0 as this field must
   be written with
   0’s during a modify access to SCU_WDTCPU0_CON0.*/
#define WDG_CLEAR_WDTHPW0              (0xFFFFFFF3U)
/* Mask for Watchdog status in WDTSR*/
#define WDG_STATUS_MASK                 (0x0000003CU)
/* Watchdog Input Clock Status Flag Mask in WDTSR*/
#define WDG_INPUT_CLOCK_STATUS         (0x04U)
/* Password field in CON0 */
#define WDG_MASK_WDTPW                 (0x0000FF00U)
/* Shift value of REL in WDTCPU0CON0 SFR*/
#define WDG_REL_SHIFT_VALUE             (16U)

/* To disable WDTx timer and safety */
#define WDT_DISABLE_REQ (0x00000008U)
/* To mask password */
#define WDT_PASS_MASK (0x0000FFFCU)

#if (WDG_ENABLE_TIME_CHECK == STD_OFF)
/* PAR =1, TCR = 0, UR = 1, IR0 =0, IR1 =0 */
#define WDT_SLOW_TOLERANCE_DIS (0x000000C0U) 
/* PAR =1, TCR = 0, UR = 1, IR0 =1, IR1 =0 */
#define WDT_FAST_TOLERANCE_DIS (0x000000C4U)
#else
/* PAR =1, TCR = 1, UR = 1, IR0 =0, IR1 =0 */
#define WDT_SLOW_TOLERANCE_REQ (0x000001C0U)
/* PAR =1, TCR = 1, UR = 1, IR0 = 1, IR1 =0 */
#define WDT_FAST_TOLERANCE_REQ (0x000001C4U) 
#endif
#if (WDG_ENABLE_TIME_CHECK == STD_ON)
#define WDT_SLOW_TOLERANCE    (WDT_SLOW_TOLERANCE_REQ)
#define WDT_FAST_TOLERANCE    (WDT_FAST_TOLERANCE_REQ)
#else
#define WDT_SLOW_TOLERANCE    (WDT_SLOW_TOLERANCE_DIS)
#define WDT_FAST_TOLERANCE    (WDT_FAST_TOLERANCE_DIS)
#endif 
/* To mask upper bits of SR register */
#define WDG_SAFE_STATUS_MASK (0x000001FCU)

/* Register Mapping for WDG */
#define WDG_REGMAP              ((Ifx_SCU_WDTCPU *)(void *) &(SCU_WDTCPU0_CON0))
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define WDG_17_SCU_START_SEC_CODE
#include "MemMap.h"

/* Function to Access password before accessing ENDINIT registers */
static _INLINE_ uint32 Wdg_lAccessPassword(uint32 WdtCon0);

/* Wdg_lSafeTrigger used to trigger WDGx in safe mode */
static  void Wdg_lSafeTrigger (uint16 SeqPassword,
                                   uint16 ResetPassword,
                                    uint16 TimerCheckValue);


/* WDGx mode and safety features initialization   */
static Std_ReturnType Wdg_lEnableSafety(const Wdg_17_Scu_ConfigType* ConfigPtr);
                  

                  
#define WDG_17_SCU_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/




/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

#define WDG_17_SCU_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Syntax           :inline uint32 Wdg_lAccessPassword(uint32 WdtCon0)        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : WDTCON0 register                                        **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Function to Access password before accessing ENDINIT    **
**                      registers                                             **
**                      Password Access:                                      **
**       - (Bits[15:8])Set Hardware password WDTHPW1 TO 0                     **
**       - (Bits[7:4])Set Hardware password TO 1111                           **
**       - (Bits[3:2]) This field must be written with 0’s during a password  **
**                   access to SCU_WDTCPU0_CON0.                              **
**       - (Bit[1]) Set WDTLCK to '0' to unlock SCU_WDTCPUx_CON0              **
**       - (Bit[0]) Set ENDINIT bit while password access                     **
*******************************************************************************/
static _INLINE_ uint32 Wdg_lAccessPassword(uint32 WdtCon0)
{
  return (uint32)((WdtCon0 & WDG_MASK_WDTREL) | WDG_SET_WDTHPW1_ENDINIT);
}
#if(WDG_MAXSAFE_TIMERS != 0U)
/*******************************************************************************
** Traceability     :[cover parentID=DS_MCAL_SWSC_WDG051,DS_MCAL_SWSC_WDG052] **
**                                                                            **
** Syntax           : void Wdg_17_Scu_SafeTrigger                             **
**                         (                                                  **
**                            uint16 SeqPassword,                             **
**                            uint16 ResetPassword,                           **
**                            uint16 TimerCheckValue                          **
**                          )                                                 **
**                                                                            **
**                    [/cover]                                                **
**                                                                            **
**                                                                            **
** Service ID       : 0x06                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : SeqPassord - password to unlock WDTCON0 register        **
**                    ResetPassword - password to be written in password      **
**                                    field during modify access              **
**                    TimerCheckValue - Current timer value                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Triggers the watchdog hardware.                         **
**                    It has to be called cyclically by some upper layer      **
**                    function (usually the watchdog manager) in order to     **
**                    prevent the watchdog hardware from expiring.            **
**                                                                            **
*******************************************************************************/
void Wdg_17_Scu_SafeTrigger
(
  uint16 SeqPassword,
  uint16 ResetPassword,
  uint16 TimerCheckValue
)
{ 
  /* Enter the critical section */
  Wdg_lSchMTriggerEnter();
  /* Service the Watchdog hardware */
  Wdg_lSafeTrigger(SeqPassword,ResetPassword,TimerCheckValue);
  /* Exit the critical section */
  Wdg_lSchMTriggerExit();
  
}

/*******************************************************************************
** Traceability     : [cover parentID=DS_MCAL_SWSC_WDG053]                    **
**                                                                            **
** Syntax          : void Wdg_17_Scu_SetOffMode                               **
**                   (                                                        **
**                       uint16 SeqPassword1,                                 **
**                        uint16 SeqPassword2                                 **
**                     )                                                      **
**                                                                            **
**                    [/cover]                                                **
**                                                                            **
**                                                                            **
** Service ID      : 7                                                        **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non-reentrant                                            **
**                                                                            **
** Parameters (in) : SeqPassword1 - Password to unlock WDTCON0,               **
**                                    to write ENDINIT = 0                    **
**                   SeqPassword2 - Password to unlock WDTCON0,               **
**                                    to write ENDINIT = 1                    **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : sets WDT in OFF mode and disables safety features       **
*******************************************************************************/
#if(WDG_SET_OFF_MODE_API == STD_ON)
void Wdg_17_Scu_SetOffMode(uint16 SeqPassword1,uint16 SeqPassword2)
{

  uint32 PasswordAccess;
  uint32 Password1;
  uint32 Password2;
  uint32 ModifyAccess;
  /* Local variable to hold the value of Watchdog Timer Control Register */
  uint32 WdtCon0;
  uint8 CoreId;
  #if(WDG_ENABLE_TIME_CHECK == STD_ON)
  uint32 TimerValue;
  uint32 Time;
  #endif
  /* Get the current core id  */
  CoreId = Mcal_GetCoreId();
  /* Shift password by 2 bit places */
  Password1 = ((uint32)SeqPassword1 << 2U);
  Password2 = ((uint32)SeqPassword2 << 2U);
  /* enter crtical section*/
  Wdg_lSchMOffModeEnter();
  /* Read WDTCON0 register */
  WdtCon0 = WDG_REGMAP[CoreId].CON0.U;
      
  #if(WDG_ENABLE_TIME_CHECK == STD_OFF)  
  
  /* Password access  */
  PasswordAccess = (uint32)((Password1)|1U|(WdtCon0 & WDG_MASK_WDTREL));
  WDG_REGMAP[CoreId].CON0.U = PasswordAccess;
 
  /* Modify access, ENDINIT = 0*/
  ModifyAccess = (uint32)((WdtCon0 & WDG_MASK_WDTREL)|
                             (Password1 & WDT_PASS_MASK)|2U);
                            
  WDG_REGMAP[CoreId].CON0.U = ModifyAccess;
                          
  /* Disable WDT and safety features  */ 
  WDG_REGMAP[CoreId].CON1.U = WDT_DISABLE_REQ;
      
  /* password access to set ENDINIT bit */
  PasswordAccess = (uint32)((Password2)|1U|(WdtCon0 & WDG_MASK_WDTREL));
  WDG_REGMAP[CoreId].CON0.U = PasswordAccess;

  /* Modify access ENDINIT = 1*/
  ModifyAccess = (uint32)((WdtCon0 & WDG_MASK_WDTREL)|
                             (Password2 & WDT_PASS_MASK)|3U);
  WDG_REGMAP[CoreId].CON0.U = ModifyAccess;
  
  
  #else
  
  /* Password access  */
  /* Get the current WDG1 timer value */
  Time = (uint32)WDG_REGMAP[CoreId].SR.B.TIM;
  
  /* Shift left by 16 bits and mask upper 16 bits */
  TimerValue = ((~Time) << 16U) & WDG_MASK_WDTREL;
  PasswordAccess = (uint32)(Password1 |(TimerValue|1U));
  
  /* Perform password access */
  WDG_REGMAP[CoreId].CON0.U = PasswordAccess;
     
  /* Modify access, ENDINIT = 0*/
  ModifyAccess = (uint32)((WdtCon0 & WDG_MASK_WDTREL)|
                             (Password1 & WDT_PASS_MASK)|2U);
                            
  WDG_REGMAP[CoreId].CON0.U = ModifyAccess;
           
  /* Disable WDT and safety features  */ 
  WDG_REGMAP[CoreId].CON1.U = WDT_DISABLE_REQ;
   
  
    /* Get the current WDG1 timer value */
  Time = (uint32)WDG_REGMAP[CoreId].SR.B.TIM;
  
  /* Shift left by 16 bits and mask upper 16 bits */
  TimerValue = ((~Time) << 16U) & WDG_MASK_WDTREL;
  PasswordAccess = (uint32)(Password2 |(TimerValue|0x00000001U));
  /* Perform password access */
  WDG_REGMAP[CoreId].CON0.U = PasswordAccess;
  
  /* Modify access ENDINIT = 1*/
  ModifyAccess = (uint32)((WdtCon0 & WDG_MASK_WDTREL)|
                             (Password2 & WDT_PASS_MASK)|3U);
  WDG_REGMAP[CoreId].CON0.U = ModifyAccess;
    
  #endif
    
  /* Exit critical section */
  Wdg_lSchMOffModeExit();
}/* End of Wdg_17_Scu__SetMode */
#endif

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                                                                            **
** Syntax         :  void Wdg_lSafetyInit(const Wdg_17_Scu_ConfigType*        **
**                                            ConfigPtr)                      **
**                                                                            **
** Service ID     : None                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : Non-reentrant                                             **
**                                                                            **
** Parameters(in) : ConfigPtr (Pointer to configuration set)                  **
**                                                                            **
** Parameters(out) : None                                                     **
**                                                                            **
** Return value   : None                                                      **
**                                                                            **
** Description    : This function initializes WDGx with safety                **
**                                                                            **
*******************************************************************************/
void Wdg_lSafetyInit(const Wdg_17_Scu_ConfigType* ConfigPtr)
{
  /*Enter if Wdg_lInitDetCheck returns E_OK  */
  /* local variable to return */
  Std_ReturnType ReturnValue;
  
  
  /* Set WDG to the given Mode and enable safety features */
  ReturnValue = Wdg_lEnableSafety(ConfigPtr);

  /* Check if there was an error during mode switching */
  if (ReturnValue != E_OK)
  {
    #if (WDG_MODE_FAIL_DEM_REPORT == ENABLE_DEM_REPORT)
    /* Report Production errors to DEM - WDG010: WDG012:
                                           WDG016: WDG173*/
    Dem_ReportErrorStatus((Dem_EventIdType)WDG_E_MODE_FAILED,
                                  DEM_EVENT_STATUS_FAILED);
    #endif  /* #if (WDG_MODE_FAIL_DEM_REPORT == ENABLE_DEM_REPORT) */

    #if (WDG_DEV_ERROR_DETECT == STD_ON)
    /*Initialisation is unsuccessfull and Report to DET - WDG010: WDG045:
              WDG003: WDG066: WDG064: WDG090:*/
    Det_ReportError( WDG_17_SCU_MODULE_ID,WDG_17_SCU_INSTANCE_ID,
                     WDG_SID_INIT,WDG_E_PARAM_CONFIG );
    #endif /* #if (WDG_DEV_ERROR_DETECT == STD_ON) */
  } /* End of '(ReturnValue != E_OK)'*/
  /* If init is done successfuly calculate Timeout counter*/
  else
  {
    /* Do nothing */
  } /*ReturnValue == E_OK */
  return;
} /* End of Wdg_lSafetyInit */ 


/*******************************************************************************
**                                                                            **
** Syntax       :  Std_ReturnType Wdg_lEnableSafety(                          **
**                               const Wdg_17_Scu_ConfigType*  ConfigPtr)     **
**                                                                            **
** Service ID     : None                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : Non-reentrant                                             **
**                                                                            **
** Parameters(in) : ConfigPtr (Pointer to configuration set)                  **
**                                                                            **
** Parameters(out) : None                                                     **
**                                                                            **
** Return value   : E_OK or E_NOT_OK                                          **
**                                                                            **
** Description    : This function enables safety features                     **
**                                                                            **
*******************************************************************************/
static Std_ReturnType Wdg_lEnableSafety(const Wdg_17_Scu_ConfigType* ConfigPtr)
{
  Std_ReturnType ChangeModeDone;
  uint32 WdtCon0;
  uint32 ClockDivider;
  uint32 ReloadValue;
  uint32 TimerToleranceVal; 
  uint32 TimerToleranceShift;
  uint32 Password;
  uint32 PasswordInit;
  uint32 ModifyAccess;
  uint8 SafeArrayIdx;
  uint8 CoreId;
  WdgIf_ModeType Mode;

  CoreId = Mcal_GetCoreId();
  /* Get the index value for Initial password and TimerTlerance */
  SafeArrayIdx = (uint8)ConfigPtr->WdgSafeIndex[CoreId];

  /* get initial password, timertolerance and mode*/
  PasswordInit = (uint32)ConfigPtr->InitialPassword[SafeArrayIdx];
  #if (WDG_ENABLE_TIME_CHECK == STD_ON)
  TimerToleranceVal = (uint32)ConfigPtr->TimerTolerance[SafeArrayIdx];
  #else
  TimerToleranceVal = 0U;
  #endif
  Mode = ConfigPtr->DefaultMode[CoreId];
  /* Shift TimerToleranceVal 9 bits */
  TimerToleranceShift = TimerToleranceVal << 9U;

  /* Mode is WDGIF_SLOW_MODE*/
  if (Mode == WDGIF_SLOW_MODE)
  {
    /*Slow mode with time tolerance value and time check enabled  */
    ClockDivider = TimerToleranceShift | WDT_SLOW_TOLERANCE;
  }
  else /* WDGIF_FAST_MODE */
  {
    /*Fast mode with time tolerance value and time check enabled  */
    ClockDivider = TimerToleranceShift | WDT_FAST_TOLERANCE;
  }

  /*********** To set new password *********/

  /* Get the Reload value for WDGx mode */
  ReloadValue  = (uint32)ConfigPtr->ReloadValue[SafeArrayIdx];
  /* Enter critical section - WDG040:*/
  Wdg_lSchMInitEnter();
 
  /* Read the WDTCON0 reg */
  WdtCon0 = (uint32)WDG_REGMAP[CoreId].CON0.U;
  /* Get the password (auto sequencing disabled)*/
  Password = Wdg_lAccessPassword(WdtCon0);
  /* Password access  */
  WDG_REGMAP[CoreId].CON0.U = Password;
  /*  modify access: set new password   */
  ModifyAccess = (uint32)(((ReloadValue << 16U) & WDG_MASK_WDTREL)|
                                            (PasswordInit << 2U)|3U);
  WDG_REGMAP[CoreId].CON0.U = ModifyAccess;

  /**** End set new password *****/
  
  /* Reset ENDINIT bit in SCU_WDTCPU0_CON0 to modify SCU_WDTCPU0_CON1 */
  Mcal_ResetENDINIT();
  /* Set the clock divider */
  WDG_REGMAP[CoreId].CON1.U = (uint32)ClockDivider;
  /* Set ENDINIT bit in SCU_WDTCPU0_CON0 to lock SCU_WDTCPU0_CON1 */
  Mcal_SetENDINIT();

  /* Exit critical section - */
  Wdg_lSchMInitExit();
  
  /* Check for successful change mode */
  
    /* If time check is disabled */
    if(Mode == WDGIF_SLOW_MODE)
    {
      if (((uint32)WDG_REGMAP[CoreId].SR.U & WDG_SAFE_STATUS_MASK) ==
                                                  WDT_SLOW_TOLERANCE)
      {
         ChangeModeDone = E_OK; 
      }
      else
      {
        ChangeModeDone = E_NOT_OK; /* WDG safety features not enabled */
      }
    }
    else
    {
      if (((uint32)WDG_REGMAP[CoreId].SR.U & WDG_SAFE_STATUS_MASK) ==
                                                  WDT_FAST_TOLERANCE)
      {
         ChangeModeDone = E_OK; 
      }
      else
      {
        ChangeModeDone = E_NOT_OK; /* WDG safety features not enabled */
      }
    }
  
  return(ChangeModeDone); 
}

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : static  void Wdg_lSafeTrigger (uint16 SeqPassword,      **
**                                        uint16 ResetPassword,               **
**                                       uint16 TimerCheckValue)              **
**                                                                            **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : SeqPassord - password to unlock WDTCON0 register        **
**                    ResetPassword - password to be written in password      **
**                                    field during modify access              **
**                    TimerCheckValue - Current timer value                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This routine triggers the watchdog hardware.            **
*******************************************************************************/
static void Wdg_lSafeTrigger(uint16 SeqPassword,
                             uint16 ResetPassword,
                             uint16 TimerCheckValue)
{
  uint32 PasswordAccess;
  #if(WDG_ENABLE_TIME_CHECK == STD_OFF)
   /* Local variable to hold the value of Watchdog Timer Control Register */
  uint32 WdtCon0;
  #endif
  uint32 Password;
  uint32 ModifyAccess;
  
  #if(WDG_ENABLE_TIME_CHECK == STD_ON)
  uint32 TimerValue;
  uint32 Time;
  #endif
  uint32 ReloadValue;
  uint8 CoreId;
  uint8 SafeArrayIdx;
  CoreId = Mcal_GetCoreId();
  /* Get the index value for Initial password and TimerTlerance */
  SafeArrayIdx = (uint8)Wdg_kConfigPtr->WdgSafeIndex[CoreId];
  /* Password Access: WDG037:
   - (Bits[7:4])Set Hardware password to WDTHPW1 TO 1111.
   - (Bits[3:2])This field must be written with the value of the bits
                SCU_WDTCPU0_CON1.WDTDR and SCU_WDTCPU0_CON1.WDTIR.
   - (Bit[1])Set WDTLCK to '0' to unlock SCU_WDTCPU0_CON0.
   - (Bit[0])Write back the read ENDINIT bit.
  */
  /* Enter critical section - WDG040:*/
  /* Shift SeqPassword by 2 bits */
  
  Password = ((uint32)SeqPassword << 2U);
  /* Get the Reload value for WDGx mode */
  ReloadValue  = (uint32)Wdg_kConfigPtr->ReloadValue[SafeArrayIdx];
     /* Password Access: WDG037:  
     - (Bits[15:8])Set Hardware password WDTHPW1 TO 0
     - (Bits[7:4])Set Hardware password TO 1111
     - (Bits[3:2]) This field must be written with 0’s during a password
                   access to SCU_WDTCPU0_CON0.
     - (Bit[1]) Set WDTLCK to '0' to unlock SCU_WDTCPUx_CON0
     - (Bit[0]) Set ENDINIT bit while password access
     DS_SWSC_WDG052   */
  
  /* PASSWORD ACCESS */
  #if(WDG_ENABLE_TIME_CHECK == STD_OFF)
  /* Timer check disabled */
  /*Get current value of WDTCON0 register  */
  WdtCon0 = (uint32)WDG_REGMAP[CoreId].CON0.U;
  /* Value to be written into WDTCON0 for password access */  
  PasswordAccess = (uint32)((Password)|1U|(WdtCon0 & WDG_MASK_WDTREL));
  /* Perform password access */
  WDG_REGMAP[CoreId].CON0.U = PasswordAccess;
  UNUSED_PARAMETER(TimerCheckValue)
  #else
  /* Get timer value to perform password access*/
  Time = (uint32)TimerCheckValue;
  /* Shift left by 16 bits and mask upper 16 bits */
  TimerValue = (Time << 16U) & WDG_MASK_WDTREL;
  PasswordAccess = (uint32)(Password |(TimerValue|0x00000001U));
  /* Perform password access */
  WDG_REGMAP[CoreId].CON0.U = PasswordAccess;
  #endif

  /* Modify access*/
  /*  Write ResetPassword into password field,
              reload value into upper 16bits, 
               set BITS 0 and 1 to 1 */
  ModifyAccess = (uint32)(((ReloadValue << WDG_REL_SHIFT_VALUE)& 
              WDG_MASK_WDTREL)|((((uint32)ResetPassword) << 2U)& WDT_PASS_MASK)
                                                                        |3U);
    /* Perform Modify access */
  WDG_REGMAP[CoreId].CON0.U = ModifyAccess; 
  return ;
} /* End of Wdg_lSafeTrigger */


#define WDG_17_SCU_STOP_SEC_CODE
#include "MemMap.h"
#endif