/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : KRN                                                     */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : KRN_2.c                                                 */
/* !Description     : RAM, manual reset and OS initializations                */
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
 * %PID: P2017_BSW:0A192567.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "KRN.h"
#include "KRN_Private.h"
#include "MCAL.h"
#include "Mcal_WdgLib.h"
#include "MCU.h"
#include "NvM.h"
#include "NvMIf.h"
#include "Os.h"
#include "RSTSRV.h"
#include "SWFAIL.h"
#include "Wdg.h"

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

#define KRN_START_SEC_CODE
#include "KRN_MemMap.h"

/******************************************************************************/
/* !FuncName    : KRN_vidSaveManualResetContext                               */
/* !Description : If not manual reset clears the uncleared ram                */
/*                else saves the manual reset context in EEPROM               */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidSaveManualResetContext(void)
{
   /* SWFAIL_tudtStackIdxType udtLocalStackIdx;  */
   SWFAIL_tbfErrorType     bfLocalErrorType;
   uint16                  u16LocalExceptionsErrorCnt;
   uint16                  u16LocalStackErrorCnt;
   void *                  pfvidLocalErrorAddress;
   RSTSRV_tudtResetType    udtResetType;
   NvM_RequestResultType   udtLocStatus;
   boolean                 bSaveNvMBlock;

   bSaveNvMBlock = FALSE;

   /* For winades viewing */
   Type_de_defaut_eep         = KRN_strExceptionRegs.bfLocalErrorType;
   Compteur_defaut_except_eep = KRN_strExceptionRegs.u16LocalExceptionsErrorCnt;
   Compteur_defaut_pile_eep   = KRN_strExceptionRegs.u16LocalStackErrorCnt;
   ErrorAddress_eep           = (uint32)(KRN_strExceptionRegs.pfvidLocalErrorAddress);

   /* Test if the Tresos Configuration Block size is well configured */
   if(sizeof(KRN_strExceptionRegs) != KRN_NVM_SIZE_OF_EXCEPTION_REGS)
   {
      SWFAIL_vidSoftwareErrorHook();
   }
   else
   {
      /* !Comment : Saves the manual reset context in EEPROM                  */
      bfLocalErrorType           = SWFAIL_bfReadErrorType();
      u16LocalExceptionsErrorCnt = SWFAIL_u16Read(SWFAIL_u8EXCEPTIONS_ERROR);
      u16LocalStackErrorCnt      = SWFAIL_u16Read(SWFAIL_u8STACK_ERROR);
      pfvidLocalErrorAddress     = SWFAIL_pfvidReadErrorAddress();
/*      udtLocalStackIdx           = SWFAIL_udtReadStackIdx(); */
   
      udtResetType = RSTSRV_udtReadResetState();
      if (udtResetType != RSTSRV_udtSOFTWARE_RESET)
      {
         SWFAIL_vidErase();
      }
      else
      {
         if (  (Type_de_defaut_eep != (uint16)bfLocalErrorType)
            || (Compteur_defaut_except_eep != u16LocalExceptionsErrorCnt)
            || (Compteur_defaut_pile_eep   != u16LocalStackErrorCnt)
            || (ErrorAddress_eep           != (uint32)pfvidLocalErrorAddress)
         /* || (ErrorStackIdx_eep          != udtLocalStackIdx) */ )
         {
            Type_de_defaut_eep         = (uint16)bfLocalErrorType;
            Compteur_defaut_except_eep = u16LocalExceptionsErrorCnt;
            Compteur_defaut_pile_eep   = u16LocalStackErrorCnt;
            ErrorAddress_eep           = (uint32)pfvidLocalErrorAddress;
            /* ErrorStackIdx_eep          = udtLocalStackIdx; */
            KRN_strExceptionRegs.bfLocalErrorType           = Type_de_defaut_eep;
            KRN_strExceptionRegs.u16LocalExceptionsErrorCnt = Compteur_defaut_except_eep;
            KRN_strExceptionRegs.u16LocalStackErrorCnt      = Compteur_defaut_pile_eep;
            KRN_strExceptionRegs.pfvidLocalErrorAddress     = (void *)ErrorAddress_eep;
            
            bSaveNvMBlock = TRUE;
         }
      }
   }

   (void)NvM_GetErrorStatus((NvM_BlockIdType)NvM_BSW_BLOCK_EXCEPTIONS, &udtLocStatus);
   if(udtLocStatus != NVM_REQ_OK)
   {
      bSaveNvMBlock = TRUE;
   }
   
   
   /* Equivalent to a Write Now */
   if(bSaveNvMBlock == TRUE)
   {
      (void)NvM_WritePRAMBlock(NvM_BSW_BLOCK_EXCEPTIONS);
   }
}

/******************************************************************************/
/* !FuncName    : KRN_vidOsLaunch                                             */
/* !Description : Launches the OS                                             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidOsLaunch(void)
{
   Mcal_ResetENDINIT();
   Os_InitializeInterruptTable();
   Mcal_SetENDINIT();
   while (KRN_bPowerOnCopyPerformed != TRUE)
   {
      /* !Comment: 8 call to OS_NOP in order to flush the pipeline            */
      Wdg_vidRefreshWatchdog();
      OS_NOP();
      OS_NOP();
      OS_NOP();
      OS_NOP();
      OS_NOP();
      OS_NOP();
      OS_NOP();
      OS_NOP();
   }
   StartOS(OSDEFAULTAPPMODE);
}

/******************************************************************************/
/* !FuncName    : KRN_vidStartup                                              */
/* !Description : Initialize BUSBSL, De-initialize INBSL, read watchdog       */
/*                internal status, initialize RAM, initialize the watchdog,   */
/*                call RSTSRV Power-On reset entry and launch the OS.         */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidStartup(void)
{
   Mcu_ResetType        udtLocalResetIndicator; 
   RSTSRV_tudtResetType udtLocalResetType;

   Wdg_vidRefreshWatchdog();
   udtLocalResetIndicator = Mcu_GetResetReason();

   if (  (udtLocalResetIndicator == MCU_POWER_ON_RESET)
      || (udtLocalResetIndicator == MCU_EVR13_RESET)
      || (udtLocalResetIndicator == MCU_EVR33_RESET)
      || (udtLocalResetIndicator == MCU_SUPPLY_WDOG_RESET)
      || (udtLocalResetIndicator == MCU_RESET_UNDEFINED))
   {
      udtLocalResetType = RSTSRV_udtHARDWARE_RESET;
      Mcal_Gnu_CopyTable((uint32)&__power_on_clear_table,
                         (uint32)&__power_on_copy_table);
   }
   else
   {
      /* !Comment: udtLocalResetType may not be exactly hardware reset. It is */
      /*           needed to be different from software reset.                */
      udtLocalResetType = RSTSRV_udtSOFTWARE_RESET;
   }
   Wdg_vidRefreshWatchdog();

   RSTSRV_vidPowerOnResetEntry(udtLocalResetType);                                                                                                                                                                                                                                                                                                                                                                                                                           /* dbg */

   KRN_bPowerOnCopyPerformed = TRUE;

   KRN_vidOsLaunch();
}

/******************************************************************************/
/* !FuncName    : KRN_vidCheckInitTests                                       */
/* !Description : Check init safety tests : Flash & RAM                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidCheckInitTests(void)
{
   /*   MCWDG_tbfPrepInitStatus bfLocalFinalResult; //dbg: to be implemented next 

      bfLocalFinalResult = (MCWDG_tbfPrepInitStatus)( KRN_udtRAM_TEST_FAIL
    + KRN_udtFLASH_TEST_FAIL);

      if (KRN_u32TestRAMStatus == E_RAM_OK)
      {
         bfLocalFinalResult &= ~KRN_udtRAM_TEST_FAIL;
      }

      if (KRN_bInitTmsChecksumOK == TRUE)
      {
         bfLocalFinalResult &= ~KRN_udtFLASH_TEST_FAIL;
      }*/

      /* !Comment: If FLASH and RAM Tests are OK, bfLocalFinalResult          */
      /*           shall be 0x00                                              */
  /*    MCWDG_vidWritePrepInitStatus(bfLocalFinalResult); */                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          /* dbg */
}

/******************************************************************************/
/* !FuncName    : KRN_vidWaitForOsInitEnd                                     */
/* !Description : Wait For The End of Os Initialization                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidWaitForOsInitEnd(void)
{
   while (KRN_bReadOsAccessAuthorized() == FALSE)
   {
      Wdg_vidRefreshWatchdog();
      OS_NOP();
      OS_NOP();
      OS_NOP();
      OS_NOP();
      OS_NOP();
      OS_NOP();
      OS_NOP();
      OS_NOP();
   }
}

#define KRN_STOP_SEC_CODE
#include "KRN_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
