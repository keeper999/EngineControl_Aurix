/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : DEVHAL                                                  */
/* !Description     : DEVHAL Component                                        */
/*                                                                            */
/* !File            : DEVHAL_Api.c                                            */
/* !Description     : APIs of DEVHAL Component                                */
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
 * %PID: %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "DEVHAL.h"
#include "DEVHAL_FlsLoader.h"
#include "DEVHAL_Cfg.h"
#include "DEVHAL_Def.h"
#include "DEVHAL_I.h"
#include "IfxOvc_reg.h"
#include "IfxScu_reg.h"
#include "IfxScuWdt.h"
#include "Isr_Cfg.h"
#include "Mcal.h"
#include "Mcu.h"
#include "Os.h"
#include "Os_DisableInterrupts.h"
#include "RSTSRV.h"


#define DEVHAL_START_SEC_CODE
#include "DEVHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : DEVHAL_vidInit                                              */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : K. Rungasamy                                                */
/******************************************************************************/
void DEVHAL_vidInit(void)
{
   boolean bLocalEmulationExtension;

   bLocalEmulationExtension = DEVHAL_bCheckEmulCard();
   
   DEVHAL_bIsFlsLoaderErasing = FALSE;

   if (bLocalEmulationExtension == TRUE)
   {
      /* !Comment: Unlock of the EMEM                                         */
      DEVHAL_vidUnlockEMEM();
      /* !Comment: Initialization of the Overlay RAM                          */
      DEVHAL_vidCopyCalibToERAM();
      DEVHAL_vidInitEmuCalib();
      /* !Comment: Initialization of FlsLoader component                      */
      DEVHAL_vidInitFlsLoader();
     
      DEVHAL_bIsInitialized = TRUE;
   }
   else
   {
      DEVHAL_bIsInitialized = FALSE;
   }
}

/******************************************************************************/
/* !FuncName    : DEVHAL_bCheckEmulCard                                       */
/* !Description : Checks if emulation extension is available                  */
/*                                                                            */
/* !LastAuthor  : K. Rungasamy                                                */
/******************************************************************************/
boolean DEVHAL_bCheckEmulCard(void)
{
   volatile Ifx_SCU_CHIPID *pudtLocalChipIdReg = &SCU_CHIPID;

   if ((pudtLocalChipIdReg->B.EEA) == 0x01u)
   {
      return (TRUE);
   }
   else
   {
      return (FALSE);
   }
}

/******************************************************************************/
/* !FuncName    : DEVHAL_vidEnableOverlay                                     */
/* !Description : Enable Overlay on all Cores                                 */
/*                                                                            */
/* !LastAuthor  : K. Rungasamy                                                */
/******************************************************************************/
void DEVHAL_vidEnableOverlay(void)
{
   uint16 u16LocalPassword;
   volatile Ifx_SCU_OVCENABLE *pudtLocalOvcEnableReg;

   if (DEVHAL_bCheckEmulCard() == TRUE)
   {
      /* !Comment: Overlay Registers are Safety Endinit Protected                */
      u16LocalPassword = IfxScuWdt_getSafetyWatchdogPassword();
      IfxScuWdt_clearSafetyEndinit(u16LocalPassword);

      /* !Comment: Enable Overlay on all Cores                                   */
      pudtLocalOvcEnableReg          = &SCU_OVCENABLE;
      pudtLocalOvcEnableReg->B.OVEN0 = 0x1u;
      pudtLocalOvcEnableReg->B.OVEN1 = 0x1u;
      pudtLocalOvcEnableReg->B.OVEN2 = 0x1u;

      IfxScuWdt_setSafetyEndinit(u16LocalPassword);

      DEVHAL_vidInvalidateDataCache();
   }
}

/******************************************************************************/
/* !FuncName    : DEVHAL_vidDisableOverlay                                    */
/* !Description : Disable Overlay on all Cores                                */
/*                                                                            */
/* !LastAuthor  : K. Rungasamy                                                */
/******************************************************************************/
void DEVHAL_vidDisableOverlay(void)
{
   uint16 u16LocalPassword;
   volatile Ifx_SCU_OVCENABLE *pudtLocalOvcEnableReg;

   if (DEVHAL_bCheckEmulCard() == TRUE)
   {
      /* !Comment: Overlay Registers are Safety Endinit Protected                */
      u16LocalPassword = IfxScuWdt_getSafetyWatchdogPassword();
      IfxScuWdt_clearSafetyEndinit(u16LocalPassword);

      /* !Comment: Disable Overlay on all Cores                                  */
      pudtLocalOvcEnableReg          = &SCU_OVCENABLE;
      pudtLocalOvcEnableReg->B.OVEN0 = 0x0u;
      pudtLocalOvcEnableReg->B.OVEN1 = 0x0u;
      pudtLocalOvcEnableReg->B.OVEN2 = 0x0u;

      IfxScuWdt_setSafetyEndinit(u16LocalPassword);

      DEVHAL_vidInvalidateDataCache();
   }
}

/******************************************************************************/
/* !FuncName    : DEVHAL_vidTrapDevaidPowerDown                               */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : K. Rungasamy                                                */
/******************************************************************************/
void DEVHAL_vidTrapDevaidPowerDown(
   uint8 u8Arg    /* !Comment : Devaid power-down treatment identification    */
                  /* !Range   : DEVHAL_u8TRAP_PWD_INACTIVE,                   */
                  /*            DEVHAL_u8TRAP_PWD_ACTIVE,                     */
                  /*            DEVHAL_u8TRAP_PWD_END                         */
)
{
   COMPILER_UNUSED_PARAMETER(u8Arg);
}

/******************************************************************************/
/* !FuncName    : DEVHAL_udtCheckEngineState                                  */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : J. Soufflet                                                 */
/******************************************************************************/
Std_ReturnType DEVHAL_udtCheckEngineState(void)
{
   boolean bLocalReprogCondOk;
   boolean bLocalProtectionCondOk;
   Std_ReturnType udtLocalRetValue;


   bLocalReprogCondOk = DEVHAL_bCheckReprogCond();
   if (bLocalReprogCondOk != FALSE)
   {
      bLocalProtectionCondOk = DEVHAL_bWaitProtectionCond();
      if (bLocalProtectionCondOk == FALSE)
      {
         DEVHAL_u8CheckEngineState = DEVHAL_u8ENG_STATE_IN_PROGRESS;
         udtLocalRetValue = E_NOT_OK;
      }
      else
      {
         DEVHAL_u8CheckEngineState = DEVHAL_u8ENG_STATE_AUTHORISED;
         udtLocalRetValue = E_OK;
      }
   }
   else
   {
      DEVHAL_u8CheckEngineState = DEVHAL_u8ENG_STATE_DENIED;
      udtLocalRetValue = E_NOT_OK;
   }
   return(udtLocalRetValue);
}

#define DEVHAL_STOP_SEC_CODE
#include "DEVHAL_MemMap.h"

#define DEVHAL_START_SEC_CODE_COPY_CALIB
#include "DEVHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : DEVHAL_vidCopyCalibrationInFlash                            */
/* !Description : Erase then Copy of calibrations in flash                    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void DEVHAL_vidCopyCalibrationInFlash(void)
{
   if (DEVHAL_bCheckEmulCard() == TRUE)
   {
      SuspendAllInterrupts();
      /* Clear of all pending IT SRCs */
      Os_DisableAllConfiguredInterrupts();

      /* Clear of all pending DMA SRCs */
      DMADRV_vidDeInit();

      /* Disable all reset except software reset */
      Mcal_ResetSafetyENDINIT_Timed(MCU_SAFETY_ENDINT_TIMEOUT);
      SCU_RSTCON.U = (uint32_t)MCU_SW_RESET_CONFIG;
      Mcal_SetSafetyENDINIT_Timed();

      Mcal_ResetENDINIT();
      /* Disables Trap generation by SCU module: disable of NMI trap generation when a watchdog is triggered */
      SCU_TRAPDIS.B.SMUT = 1U;
      Mcal_SetENDINIT();

      /* Send CPU 0 To Idle */
      Mcal_ResetSafetyENDINIT();
      SCU_PMCSR0.B.REQSLP = 1U;
      Mcal_SetSafetyENDINIT();

      /* Send CPU 2 To Idle */
      Mcal_ResetSafetyENDINIT();
      SCU_PMCSR2.B.REQSLP = 1U;
      Mcal_SetSafetyENDINIT();

      DEVHAL_vidEraseCalibrationInFlash();
      DEVHAL_vidCopyFromRamToFlash();
      RSTSRV_vidPerformReset(RSTSRV_udtHARDWARE_RESET);
   }
}

/******************************************************************************/
/* !FuncName    : DEVHAL_vidEraseCalibrationInFlash                           */
/* !Description : Erase calibrations in flash                                 */
/*                                                                            */
/* !LastAuthor  : K. Rungasamy                                                */
/******************************************************************************/
void DEVHAL_vidEraseCalibrationInFlash(void)
{
   DEVHAL_bIsFlsLoaderErasing = TRUE;
   
   if (DEVHAL_u32NUM_OF_LOGICAL_SECT_PS0 != 0)
   {
      DEVHAL_vidEraseCalib(DEVHAL_u32CALIB_START_ADDR_PS0, DEVHAL_u32NUM_OF_LOGICAL_SECT_PS0);
   }
   if (DEVHAL_u32NUM_OF_LOGICAL_SECT_PS1 != 0)
   {
      DEVHAL_vidEraseCalib(DEVHAL_u32CALIB_START_ADDR_PS1, DEVHAL_u32NUM_OF_LOGICAL_SECT_PS1);
   }
   if (DEVHAL_u32NUM_OF_LOGICAL_SECT_PS2 != 0)
   {
      DEVHAL_vidEraseCalib(DEVHAL_u32CALIB_START_ADDR_PS2, DEVHAL_u32NUM_OF_LOGICAL_SECT_PS2);
   }
   if (DEVHAL_u32NUM_OF_LOGICAL_SECT_PS3 != 0)
   {
      DEVHAL_vidEraseCalib(DEVHAL_u32CALIB_START_ADDR_PS3, DEVHAL_u32NUM_OF_LOGICAL_SECT_PS3);
   }
}

/******************************************************************************/
/* !FuncName    : DEVHAL_vidCopyFromRamToFlash                                */
/* !Description : Copy calibration from RAM to flash                          */
/*                                                                            */
/* !LastAuthor  : K. Rungasamy                                                */
/******************************************************************************/
void DEVHAL_vidCopyFromRamToFlash(void)
{
   DEVHAL_vidCopyCalib(DEVHAL_u32EMEM_START_ADDR, DEVHAL_u32CALIB_START_ADDRESS, DEVHAL_u32SIZE_OF_CALIB);
}

/******************************************************************************/
/* !FuncName    : DEVHAL_bIsErasing                                           */
/* !Description : return the state of DEVHAL                                  */
/*                                                                            */
/* !LastAuthor  : K. Rungasamy                                                */
/******************************************************************************/
boolean DEVHAL_bIsErasing(void)
{
   return (DEVHAL_bIsFlsLoaderErasing);
}

#define DEVHAL_STOP_SEC_CODE_COPY_CALIB
#include "DEVHAL_MemMap.h"


/*-------------------------------- end of file -------------------------------*/
