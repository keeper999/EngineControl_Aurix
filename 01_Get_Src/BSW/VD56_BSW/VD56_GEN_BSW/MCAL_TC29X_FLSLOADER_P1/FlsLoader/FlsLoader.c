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
**  $FILENAME   : FlsLoader.c $                                              **
**                                                                           **
**  $CC VERSION : \main\54 $                                                 **
**                                                                           **
**  $DATE       : 2013-12-09 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                functionality of Flsloader driver.                         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
    TRACEABILITY : [cover parentID=DS_NAS_PR647,DS_NAS_PR127,DS_NAS,PR761,PR760,
    DS_NAS_PR647_1,DS_NAS_PR123,DS_NAS_PR761,DS_NAS_PR760,
    DS_NAS_PR1597_PR1598_PR1599_PR1600_PR1686_PR1687_PR11XX_PR22XX,
    DS_NAS_PR1604_PR1605_PR1606_PR1607_PR1688_PR1689_PR33XX_PR44XX]
    [/cover]
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Global Misra Violation and Suppression */
/*
MISRA Rule 11.3 (45) VIOLATION: The Pointers are converted to uint32 for address
comparison/calculation purpose. (lint#:923)

MISRA Rule 12.8, Excessive shift value (Ex: precision 9 shifted right by 16)
*/

/* Inclusion of Tasking sfr file */
#include "IfxFlash_reg.h"

#include "IfxSrc_reg.h"

/* Inclusion of Mcal Specific Global Header File */
#include "Mcal.h"

/* Inclusion of SchM Header File */
#include "SchM_FlsLoader.h"

/* Inclusion of Flash header file */
#include "FlsLoader.h"

/* Inclusion of Flash header file */
#include "FlsLoader_Local.h"

#include "IfxCpu_reg.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
#ifndef FLSLOADER_SW_MAJOR_VERSION
  #error "FLSLOADER_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef FLSLOADER_SW_MINOR_VERSION
  #error "FLSLOADER_SW_MINOR_VERSION is not defined. "
#endif

#ifndef FLSLOADER_SW_PATCH_VERSION
  #error "FLSLOADER_SW_PATCH_VERSION is not defined. "
#endif

#if ( FLSLOADER_SW_MAJOR_VERSION != 2U )
  #error "FLSLOADER_SW_MAJOR_VERSION does not match. "
#endif

#if ( FLSLOADER_SW_MINOR_VERSION != 1U )
  #error "FLSLOADER_SW_MINOR_VERSION does not match. "
#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* To differentiate between PFLASH and DFLASH the following value is written
   in the command cycle. */
#define FLSLOADER_PFLASH_VAL            ((FlsLoader_AddressType)(0x00000050U))

/* The flash bank are assigned with values with respect to location in
   FLASH_FLASH0_FSR register. */

#define FLSLOADER_PROG_MASK             ((uint32)(0x00000080U))
#define FLSLOADER_ERASE_MASK            ((uint32)(0x00000100U))
/*The following to macros are used to determine the status of Flash. */
#define FLSLOADER_NORMAL                (0U)
#define FLSLOADER_SUSPEND               (1U)
#define FLSLOADER_UNINTIALIZED          (0U)

/* Flash NULL */
#define FLSLOADER_NULL                  ((void *) 0)
#define FLSLOADER_DATA_NULL             ((FlashLoader_DataType *) 0)
#define FLSLOADER_ZERO_DATA             (0x00000000U)
#define FLSLOADER_PROCON_CHECK          ((uint32)(0x7FFFFFFU))
#define FLSLOADER_PFLASH_ADDRESS_MASK   ((FlsLoader_AddressType)(0x00FFFFFFU))
#define FLSLOADER_ADDRESS_HI_5_MASK     ((FlsLoader_AddressType)(0x000FFFFFU))
#define FLSLOADER_SHIFT_BY_16           (16U)
#define FLSLOADER_SHIFT_BY_8            (8U)
#define FLSLOADER_SHIFT_BY_15           (15U)
#define FLSLOADER_NUM_5                 (5U)
#define FLSLOADER_NUM_2                 (2U)
#define FLSLOADER_NUM_32                (32U)
#define FLSLOADER_NUM_256               (256U)
#define FLSLOADER_NUM_4                 (4U)
#define FLSLOADER_UCB0                  (0U)
#define FLSLOADER_UCB1                  (1U)
#define FLSLOADER_PWD                   (8U)
/* (17*8)bytes UCB <P/D>FLASH content*/
#define FLSLOADER_FLASH_TRAP_DIS        (0x00008000U)
#define FLSLOADER_FLASH_TRAP_EN         (0xFFFF7FFFU)

/* Program Verify Error */
#define FLS_PVER_ERROR                  (0x02000000U)
/* Erase Verify Error */
#define FLS_EVER_ERROR                  (0x04000000U)

/* Flash command should point this Address */
#define FLSLOADER_CMD_BASE  ((FlsLoader_AddressType)(0xAF000000U))

#define FLASH_HW_MODULE  ((volatile Ifx_FLASH *)(void *) &(MODULE_FLASH0))
#define FLASH0_PROCONP ((volatile Ifx_FLASH_PROCONP*)(void *)(&FLASH0_PROCONP0))
#define FLASH0_PROCONOTP \
         ((volatile Ifx_FLASH_PROCONOTP*)(void *)(&FLASH0_PROCONOTP0))
#define FLASH0_PROCONWOP \
         ((volatile Ifx_FLASH_PROCONWOP*)(void *)(&FLASH0_PROCONWOP0))

/*******************************************************************************
**                      Private function like Macros                          **
*******************************************************************************/

/*
Function Like Macro:FlsLoader_lGetMode
macro to get the kind of flash
Input Parameters: FlashType
*/
#define FlsLoader_lGetMode(FlashType) (((FlashType)!=(FLSLOADER_DFLASH_BANK0)) \
                             ? (FLSLOADER_PFLASH_VAL) : (FLSLOADER_DFLASH_VAL))

/******************************************************************************
**                      Global Type Definitions                              **
******************************************************************************/
/******************************************************************************
**                      Private Type Definitions                             **
******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/******************************************************************************
**                      Private Variable Definitions                         **
******************************************************************************/

#ifdef IFX_FLSLOADER_DEBUG
  #define FLSLOADER_START_SEC_VAR_32BIT
  #include "MemMap.h"
    extern volatile uint32 TestFlsloader_DebugMask00;
    extern volatile uint32 TestFlsloader_DebugMask01;
    extern volatile uint32 TestFlsloader_DebugMask02;
    extern volatile uint32 TestFlsloader_DebugMask03;
    extern volatile uint32 TestFlsloader_DebugMask04;
    extern volatile uint32 TestFlsloader_DebugMask05;
    extern volatile uint32 TestFlsloader_DebugMask06;
    extern volatile uint32 TestFlsloader_DebugMask07;
    extern volatile uint32 TestFlsloader_DebugMask08;
    extern volatile uint32 TestFlsloader_DebugMask09;
    extern volatile uint32 TestFlsloader_DebugMask10;
    
  #define FLSLOADER_STOP_SEC_VAR_32BIT
  #include "MemMap.h"
#endif


#define FLSLOADER_START_SEC_VAR_8BIT
#include "MemMap.h"
static uint8 FlsLoader_Status;
#if (FLSLOADER_DEV_ERROR_DETECT == STD_ON)
uint8  FlsLoader_InitStatus;
#endif
#define FLSLOADER_STOP_SEC_VAR_8BIT
#include "MemMap.h"


/*******************************************************************************
**                    Prototypes Of Local Functions                           **
*******************************************************************************/
/* funtion to check program verification error */
static _INLINE_ FlsLoader_ReturnType FlsLoader_lPverCheck(void);

/* funtion to check Erase verification error */
static _INLINE_ FlsLoader_ReturnType FlsLoader_lEverCheck(void);


/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/* Mapping the code */
#define FLSLOADER_START_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1623]                              **
**            [/cover]                                                        **
** Syntax           :  FlsLoader_ReturnType FlsLoader_Init(                   **
**                      const FlsLoader_ConfigType* Address)                  **
**                                                                            **
** Service ID       : 0x00                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Address :NULL Expected                                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : FlsLoader_ReturnType:(If DET is not enabled)            **
**                    1.FLSLOADER_E_OK                                        **
**                    2.FLSLOADER_E_ROMVERSION                                **
**                    1.FLSLOADER_E_NOT_OK                                    **
**                                                                            **
** Description      : This function initilizes the flash module and checks    **
**                    if all the flash sectors is configured as ROM           **
**                                                                            **
*******************************************************************************/
/*
CD_FlsLoader028: This is the initialization function for FlsLoader.
*/
FlsLoader_ReturnType FlsLoader_Init(const FlsLoader_ConfigType* Address)
{
  FlsLoader_ReturnType  RetError;
  uint32 Fls0Check;
  uint32 Fls1Check;
  uint32 Fls0WOPCheck;
  uint32 Fls1WopCheck;

  UNUSED_PARAMETER(Address)

  /* Init RetError to OK */
  RetError = (FlsLoader_ReturnType)FLSLOADER_E_OK;

/*
 Check if Passed Address is NULL
*/

#if (FLSLOADER_DEV_ERROR_DETECT == STD_ON)
  if ( Address != FLSLOADER_NULL )
  {
    /* Report FLSLOADER_E_PARAM_IGNORED DET */
    Det_ReportError(
                    (uint16)FLSLOADER_MODULE_ID,
                    FLSLOADER_INSTANCE_ID,
                    FLSLOADER_SID_INIT,
                    FLSLOADER_E_PARAM_IGNORED);
    /*lint -e904  */
    return ((FlsLoader_ReturnType)FLSLOADER_E_NOT_OK);
    /*lint +e904  */
  }
#endif
  /* Check whether all the sectors have been protected under OTP and WOP */

#ifdef IFX_FLSLOADER_DEBUG
 Fls0Check = TestFlsloader_DebugMask00;
 Fls1Check = TestFlsloader_DebugMask00;
 Fls0WOPCheck = TestFlsloader_DebugMask00;
 Fls1WopCheck = TestFlsloader_DebugMask00;
#else
 Fls0Check = (uint32)(FLASH0_PROCONOTP0.U & FLSLOADER_PROCON_CHECK);
 Fls1Check = (FLASH0_PROCONOTP1.U & FLSLOADER_PROCON_CHECK );
 Fls0WOPCheck = (FLASH0_PROCONWOP0.U & FLSLOADER_PROCON_CHECK);
 Fls1WopCheck = (FLASH0_PROCONWOP1.U & FLSLOADER_PROCON_CHECK);
#endif/*#ifdef IFX_FLSLOADER_DEBUG*/
 if (((Fls0Check == FLSLOADER_PROCON_CHECK) && \
     (Fls1Check == FLSLOADER_PROCON_CHECK))||
    ((Fls0WOPCheck == FLSLOADER_PROCON_CHECK) && \
     (Fls1WopCheck == FLSLOADER_PROCON_CHECK)))

  {
    RetError = (FlsLoader_ReturnType)FLSLOADER_E_ROMVERSION;
  }

/* FLASH_FCON register will be initialized in the start up. */
  FlsLoader_Status = FLSLOADER_NORMAL;
  #if (FLSLOADER_DEV_ERROR_DETECT == STD_ON)
  FlsLoader_InitStatus = FLSLOADER_INITIALIZED;
  #endif

  Mcal_ResetENDINIT();
    /* Disable traps on Uncorrectable errors */
  FLASH0_MARP.U |= FLSLOADER_FLASH_TRAP_DIS;
   /* Set End Init Protection */
  Mcal_SetENDINIT();
    /* Disable traps on Uncorrectable errors */
  FLASH0_MARD.U |= FLSLOADER_FLASH_TRAP_DIS;

  return (RetError);

} /* End of Fls_Loader_Init */

/* Preprocessor switch to enable/disable the API to deinitialze
                FlsLoader. */
#if (FLSLOADER_DEINIT_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1624]                              **

** Syntax           :  FlsLoader_ReturnType FlsLoader_DeInit()                **
**            [/cover]                                                        **
** Service ID       : 0x01                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : void                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : FlsLoader_ReturnType:(If DET is not enabled)            **
**                    1. FLSLOADER_E_OK                                       **
**                    2. FLSLOADER_E_BUSY                                     **
**                    1.FLSLOADER_E_BUSY                                      **
**                                                                            **
** Description      : This function deinitilizes the flash module.            **
**                    This Function sets the registers to their default       **
**                    state and executes the reset to read command.           **
**                                                                            **
*******************************************************************************/
/*
CD_FlsLoader030: Service for FlsLaderDeInitialization
*/
FlsLoader_ReturnType FlsLoader_DeInit(void)
{
  FlsLoader_ReturnType  RetError;
  uint32 Fls0FsrCheck;
  /* Init RetError to OK */
  RetError    = (FlsLoader_ReturnType)FLSLOADER_E_OK;

  #if (FLSLOADER_DEV_ERROR_DETECT == STD_ON)
  if (FlsLoader_InitStatus != FLSLOADER_INITIALIZED)
  {
    /* CD_FlsLoader032: FlsLoader not initialized,Report to DET*/
    Det_ReportError(
                      (uint16)FLSLOADER_MODULE_ID,
                      FLSLOADER_INSTANCE_ID,
                      FLSLOADER_SID_DEINIT,
                      FLSLOADER_E_UNINIT);
    /*lint -e904  */
    return (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
    /*lint +e904  */
  }
  #endif

  /* Check for Flash Busy*/
#ifdef IFX_FLSLOADER_DEBUG
  Fls0FsrCheck = ((FLASH0_FSR.U & ((uint32)FLSLOADER_FLASH_BUSY_MASK)) |\
                      TestFlsloader_DebugMask01);
#else /*#ifdef IFX_FLSLOADER_DEBUG*/
  Fls0FsrCheck = (FLASH0_FSR.U & (uint32)(FLSLOADER_FLASH_BUSY_MASK));
#endif  /*#ifdef IFX_FLSLOADER_DEBUG*/
  if (Fls0FsrCheck)
  {
    /* Report FLSLOADER_E_BUSY DET */
    RetError = (FlsLoader_ReturnType)FLSLOADER_E_BUSY;
    #if (FLSLOADER_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError(
                    (uint16)FLSLOADER_MODULE_ID,
                     FLSLOADER_INSTANCE_ID,
                     FLSLOADER_SID_DEINIT,
                     (uint8)FLSLOADER_E_BUSY);
    #endif
  }
  else
  {
    FlsLoader_Status = FLSLOADER_NORMAL;

    #if (FLSLOADER_DEV_ERROR_DETECT == STD_ON)
    FlsLoader_InitStatus = FLSLOADER_UNINTIALIZED;
    #endif

    /* Reset to Read PFLASH, DFLASH (both banks) */
*((FlsLoader_AddressType*)FlsLoader_lResetRead(FLSLOADER_DFLASH0_START_ADDRESS))
                                   = FLSLOADER_VALUE_F0;
  }

  /* Reset EndInit protection */
  Mcal_ResetENDINIT();
    /* Enable traps on Uncorrectable errors */
  FLASH0_MARP.U &= FLSLOADER_FLASH_TRAP_EN;
   /* Set End Init Protection */
  Mcal_SetENDINIT();
    /* Enable traps on Uncorrectable errors */
  FLASH0_MARD.U &= FLSLOADER_FLASH_TRAP_EN;

  return (RetError);
} /*  End of function FlsLoader_DeInit */

#endif  /* (FLSLOADER_DEINIT_API == STD_ON) */
#define FLSLOADER_STOP_SEC_CODE
#include "MemMap.h"

#define FLSLOADER_START_SEC_WRITE_CODE
#include "MemMap.h"
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1625]                              **
**            [/cover]                                                        **
** Syntax           :  FlsLoader_ReturnType FlsLoader_Write(                  **
**                      FlsLoader_AddressType TargetAddress,                  **
**                      FlsLoader_LengthType Length,                          **
**                      const uint8 *SourceAddressPtr                         **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x02                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Address:Source data Address                             **
**                    Length :Length of the data in bytes                     **
**                    - multiple of 256 bytes(8 pages)for PFLASH              **
**                    - multiple of 32 bytes (4 pages)for DFLASH              **
**                    TargetAddress :Destination Address in Flash             **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : FlsLoader_ReturnType                                    **
**                    1.FLSLOADER_E_OK                                        **
**                    2.FLSLOADER_E_BUSY                                      **
**                    3.FLSLOADER_E_NOT_OK                                    **
**                    4.FLSLOADER_E_LOCKED                                    **
**                    5.FLSLOADER_E_SUSPENDED                                 **
**                    1.FLSLOADER_E_NOT_OK for all errors                     **
**                                                                            **
** Description      : This function is used to program a page of internal     **
**                    flash using Burst mode of programming                   **
**                    This function does not check whether the TargetAddress  **
**                    crosses the boundry from one sector to another          **
*******************************************************************************/
FlsLoader_ReturnType FlsLoader_Write(FlsLoader_AddressType TargetAddress,
                                     FlsLoader_LengthType Length,
                                     const uint8 *SourceAddressPtr)
{
  FlsLoader_ReturnType  RetError;
  uint32                FlashType;
  volatile FlsLoader_AddressType  StartAddress;
  uint32                NumberOfBursts;
  uint32                Count;
  uint32                InCount;
  uint8                 NumberOfPages;
  FlsLoader_AddressType OffSet;
  uint8                 PfSegment;
  sint32                Icr;
  uint8                 FlashBusyStat;

#if (FLSLOADER_ENABLE_LOCKCHECK == STD_ON)
  uint32                FlsProconp;
  uint8                 SectorIndex;
  uint8                 BankIndex;
  uint32                FlsFpro;
  uint32                FlsFprod;
  uint32                FlsProconp1;
  uint32                FlsProcond1;
  uint32                FlsProcondrpro1;
#endif

  FlashLoader_DataType *PdataPtr;



  /* Block 1: DET Check */
#if (FLSLOADER_DEV_ERROR_DETECT == STD_ON)

    RetError = FlsLoader_lWriteDetCheck(Length,TargetAddress);
    if (RetError != (FlsLoader_ReturnType)FLSLOADER_E_OK)
    {
      /*lint -e904  */
      return (RetError);
      /*lint +e904  */
    }
#endif

/*PFLASH1*/
  /* Block 2: check the Flash Type DFLASH/PFLASH .
     If the Flash type is PFLASH then check PMU0/PMU1. */

    if (FlsLoader_lCheckFlashType(TargetAddress))
    {
      /* Given Address belongs to DFLASH */
      /* Data Flash Bank 0 or Bank 1 is assigned */
      FlashType = FLSLOADER_DFLASH_BANK0;
    }
    else
    {
      /* Given Address belongs to PFLASH */
      /* Program Flash Bank 0 or Bank 1 is assigned */
      PfSegment = (uint8)((TargetAddress >> FLSLOADER_SHIFT_BY_20)
                           & FLSLOADER_PFLASH_MASK);
      if (PfSegment >= FLSLOADER_NUM_2)
      {
        FlashType = FLSLOADER_PFLASH_BANK1;
      }
      else
      {
        FlashType = FLSLOADER_PFLASH_BANK0;
      }
    }

  /* Protection Installation check  */
  /* Preprocessor switch to enable/disable the lockcheck functionality */
    #if (FLSLOADER_ENABLE_LOCKCHECK == STD_ON)
    RetError = (FlsLoader_ReturnType)FLSLOADER_E_OK;
    if (FlashType != FLSLOADER_DFLASH_BANK0)
    {
      /* Check if global write protection is installed */
      #ifdef  IFX_FLSLOADER_DEBUG
      FlsFpro = TestFlsloader_DebugMask06;
      #else
      FlsFpro = FLASH0_FPRO.B.PRODISP;
      #endif
      if (FlsFpro != 1U)
      {
        for (BankIndex = 0U; BankIndex <FLSLOADER_PF_BANKS; BankIndex++)
        {
          #ifdef  IFX_FLSLOADER_DEBUG
          FlsProconp1 = TestFlsloader_DebugMask09;
          #else
          FlsProconp1 = FLASH0_PROCONP[BankIndex].B.RPRO;
          #endif

          if (FlsProconp1 == 1U)
          {
            RetError = (FlsLoader_ReturnType)FLSLOADER_E_LOCKED;
          }
          else
          {
            FlsProconp = FLASH0_PROCONP[BankIndex].U;
            for (SectorIndex = 0U; SectorIndex < FLSLOADER_NUM_OF_PF0_SECTORS;
                                                                  SectorIndex++)
            {
              if ((FlsProconp & 1U) == 1U)
              {
                RetError = (FlsLoader_ReturnType)FLSLOADER_E_LOCKED;
              }
              FlsProconp = FlsProconp >> 1U;
            }
          }
        }
      }
    }
    else
    {
      /* Check if global write protection is installed in DFLASH*/
      #ifdef  IFX_FLSLOADER_DEBUG
      FlsFprod =  TestFlsloader_DebugMask09;
      FlsProcond1 =  TestFlsloader_DebugMask06;
      FlsProcondrpro1 = TestFlsloader_DebugMask06;
      #else
      FlsFprod = FLASH0_FPRO.B.PRODISD;
      FlsProcond1 = FLASH0_PROCOND.B.L;
      FlsProcondrpro1 = FLASH0_PROCOND.B.RPRO;
      #endif

      if(FlsFprod != 1U)
      {
        if(FlsProcond1 == 1U)
        {
          RetError = (FlsLoader_ReturnType)FLSLOADER_E_LOCKED;
        }
        if(FlsProcondrpro1 == 1U)
        {
            RetError = (FlsLoader_ReturnType)FLSLOADER_E_LOCKED;
        }
      }
    }
    #endif
     /* #if (FLSLOADER_ENABLE_LOCKCHECK == STD_ON)*/

    #if (FLSLOADER_ENABLE_LOCKCHECK == STD_ON)
    if (RetError == (FlsLoader_ReturnType)FLSLOADER_E_OK)
    #endif
    {
      /* Count the number of loops */
      if (FlashType != FLSLOADER_DFLASH_BANK0)
      {
        NumberOfBursts  = Length >> FLSLOADER_SHIFT_BY_8; /* Divide by 256 */
        NumberOfPages  = FLSLOADER_NUM_32; /* 32 * 8 bytes ( 256 bytes) */
        OffSet       = (FlsLoader_AddressType)FLSLOADER_NUM_256;
      }
      else
      {
        NumberOfBursts  = Length >> FLSLOADER_NUM_5; /* Divide by 32 */
        NumberOfPages  = FLSLOADER_NUM_4;  /* 4 * 8 bytes ( 32 bytes) */
        OffSet       = (FlsLoader_AddressType)FLSLOADER_NUM_32;
      }

      /* Block 5: Execute the command sequence . */
      RetError = (FlsLoader_ReturnType)FLSLOADER_E_OK;
      if ( SourceAddressPtr != FLSLOADER_NULL)
      {
        StartAddress = FLSLOADER_CMD_BASE;
        FlsLoader_Status = FLSLOADER_NORMAL; /*Initiating the state to normal*/
        /* Disable and restore interrupts for critical
           command cycles. As there are 2 critical command cycles, the entire
           write operation is protected. */

        /* copy the Address to local variable*/
        PdataPtr = (FlashLoader_DataType*)(void *)(SourceAddressPtr);


        Icr = FlsLoader_lDisableInts();

        for (Count = 0U; Count < NumberOfBursts; Count++)
        {
          if (FlashType != FLSLOADER_DFLASH_BANK0)
          {
            Mcal_ResetSafetyENDINIT();
          }

          /* Enter the Page Mode */
          *((FlsLoader_AddressType*)FlsLoader_lEnterPageMode(StartAddress)) =
                                               FlsLoader_lGetMode(FlashType);

          DSYNC();
          InCount = 0U;

          /* Check if Program Flash is in page mode */
          if (FlashType != FLSLOADER_DFLASH_BANK0)
          {
          #ifdef  IFX_FLSLOADER_DEBUG
            FlashBusyStat = (uint8)TestFlsloader_DebugMask04;
          #else
            FlashBusyStat = FLASH0_FSR.B.PFPAGE;
          #endif
            while((FlashBusyStat != FLSLOADER_BIT_SET) &&
                  (InCount < FLSLOADER_CMDCYCLE_TIMEOUT))
            {
              InCount++;
              FlashBusyStat = FLASH0_FSR.B.PFPAGE;
            }
          }
          else
          {
          #ifdef  IFX_FLSLOADER_DEBUG
            FlashBusyStat = (uint8)TestFlsloader_DebugMask04;
            InCount = TestFlsloader_DebugMask07;
          #else
            FlashBusyStat = FLASH0_FSR.B.DFPAGE;
          #endif
            while((FlashBusyStat != FLSLOADER_BIT_SET) &&
                  (InCount < FLSLOADER_CMDCYCLE_TIMEOUT))
            {
              InCount++;
              FlashBusyStat = FLASH0_FSR.B.DFPAGE;
            }
          }

          /* Check PFPAGE/DFPAGE bit was SET */
          if(InCount < FLSLOADER_CMDCYCLE_TIMEOUT)
          {
            for (InCount=0U; InCount < NumberOfPages; InCount++)
            {
              /* Load the data */
              *((FlashLoader_DataType*) FlsLoader_lLoadPage(StartAddress)) =
                               *PdataPtr;
              PdataPtr++;
              /* Load Page register gets incremented automatically. */
            }
            /* cycle 1 */
            *((FlsLoader_AddressType*)FLSLOADER_GET_CYCLE_AA50(StartAddress))
                                   = TargetAddress;
            /* cycle 2 */
            *((FlsLoader_AddressType*)FLSLOADER_GET_CYCLE_AA58(StartAddress))
                                   = FLSLOADER_VALUE_00;
            /* cycle 3 */
            *((FlsLoader_AddressType*)FLSLOADER_GET_CYCLE_AAA8(StartAddress))
                                   = FLSLOADER_VALUE_A0;
            /*cycle 4 */
            *((FlsLoader_AddressType*)FLSLOADER_GET_CYCLE_AAA8(StartAddress))
                                   = FLSLOADER_VALUE_7A;
            DSYNC();

            /* Wait till the PROG bit is set */
            InCount = 0U;
            while((FLASH0_FSR.B.PROG != FLSLOADER_BIT_SET) &&
                  (InCount < FLSLOADER_CMDCYCLE_TIMEOUT))
            {
              InCount++;
            }

            /* Check for FLASH BUSY flag */
            /* PnBUSY and D0BUSY */
            while((FLASH0_FSR.U & FLSLOADER_FLASH_BUSY_MASK) != 0U)
            {
              /*Do Nothing */
            }

            /* This check makes sure No protection error and no sequence error
            and No operation error has occurred.*/
            RetError = FlsLoader_lProtSeqOperErrorCheck();

            if(RetError == (FlsLoader_ReturnType)FLSLOADER_E_OK)
            {
              /* This check makes sure No program verification error */
              RetError = (FlsLoader_ReturnType)FlsLoader_lPverCheck();
            }

            /* Check if the operation is suspended */
            #ifdef IFX_FLSLOADER_DEBUG
            FlsLoader_Status = (uint8)TestFlsloader_DebugMask03;
            #endif/*#ifdef IFX_FLSLOADER_DEBUG */

            if (RetError == (FlsLoader_ReturnType)FLSLOADER_E_OK)
            {
              /* Clear the status if the operation is successful.*/
              *((FlsLoader_AddressType*)FlsLoader_lClearStatus(StartAddress))
                                             = FLSLOADER_VALUE_FA;
              /* Iterate the TargetAddress to the next page Address */
              TargetAddress = TargetAddress + OffSet;
            } /* End of FlsLoader_lErrorCheck */
          }  /* End of InCount < FLSLOADER_CMDCYCLE_TIMEOUT*/

          if ((FlashType != FLSLOADER_DFLASH_BANK0))
          {
            Mcal_SetSafetyENDINIT();
          }
        }  /*Number of Bursts For loop*/
        FlsLoader_lEnableInts(Icr);
    } /* End of if SourceAddressPtr != FLSLOADER_NULL */
  }
     return (RetError);
} /*  End of function OCFLS_Write */
#define FLSLOADER_STOP_SEC_WRITE_CODE
#include "MemMap.h"


#define FLSLOADER_START_SEC_ERASE_CODE
#include "MemMap.h"
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1626]                              **
**            [/cover]                                                        **
** Syntax           :  FlsLoader_ReturnType FlsLoader_Erase(                  **
**                      FlsLoader_AddressType TargetAddress,                  **
**                      FlsLoader_LengthType Length                           **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x03                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Length - Number of sectors                              **
**                    TargetAddress - Starting Address of the sector          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     :  FlsLoader_ReturnType(DET is not enabled)               **
**                     1.FLSLOADER_E_OK                                       **
**                     2.FLSLOADER_E_BUSY                                     **
**                     4.FLSLOADER_E_LOCKED                                   **
**                     5.FLSLOADER_E_SUSPENDED                                **
**                     1.FLSLOADER_E_NOT_OK for all errors but for busy.      **
**                       For busy state FLSLOADER_E_BUSY is returned          **
**                                                                            **
** Description      : This function erases the sector of the internal flash.  **
*******************************************************************************/
/* Service to Erase a sector of Flash */
FlsLoader_ReturnType FlsLoader_Erase(FlsLoader_AddressType TargetAddress,
                                     FlsLoader_LengthType Length )
{
  FlsLoader_ReturnType  RetError;
  volatile FlsLoader_AddressType StartAddress;
  uint32                FlsFsrCheck;
  uint32                FlsFSRErase;
  uint32                Fls0Proconp3;
  uint32                Fls0Proconwop;
  uint32                InnerCount;
  sint32                Icr;
  uint8                 BankIndex;

  #if (FLSLOADER_ENABLE_LOCKCHECK == STD_ON)
  uint32                FlsFproD;
  uint32                FlsProcond2;
  uint32                FlsProcondrpro2;
  uint32                FlsFpro;
  uint32                FlsProconp2;
  #endif

/* Block 1: check DET */
#if (FLSLOADER_DEV_ERROR_DETECT == STD_ON)
  RetError = FlsLoader_lEraseDetCheck(Length,TargetAddress);
  if(RetError != (FlsLoader_ReturnType)FLSLOADER_E_OK)
  {
    /*lint -e904  */
    return(RetError);
    /*lint +e904  */
  }
#endif
#ifdef IFX_FLSLOADER_DEBUG
  FlsFsrCheck = ((FLASH0_FSR.U & ((uint32)FLSLOADER_FLASH_BUSY_MASK)) |
                      TestFlsloader_DebugMask01);
#else /*#ifdef IFX_FLSLOADER_DEBUG*/
    /* Check for Busy state of FLASH
     Registers differ between Checking of Busy state of PFlash and DFlash */
  FlsFsrCheck = (FLASH0_FSR.U & ((uint32)FLSLOADER_FLASH_BUSY_MASK));
#endif /*#ifdef IFX_FLSLOADER_DEBUG*/
  if ( FlsFsrCheck )
  {
    /* Report FLSLOADER_E_BUSY DET */
    #if (FLSLOADER_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError(
                    (uint16)FLSLOADER_MODULE_ID,
                     FLSLOADER_INSTANCE_ID,
                     FLSLOADER_SID_ERASE,
                     (uint8)FLSLOADER_E_BUSY);
    #endif
    RetError = (FlsLoader_ReturnType)FLSLOADER_E_BUSY;
  }
  else
  {
    RetError = FLSLOADER_E_OK;
  }

  /* Extract the flash type */
  if (FlsLoader_lCheckFlashType(TargetAddress))
  {
        /* Given Address belongs to Data FLASH */
      /*Check if the Target Address passed is UCB protected */
     #if (FLSLOADER_ENABLE_LOCKCHECK == STD_ON)
        /* Check if global write protection is installed in DFLASH*/
      #ifdef  IFX_FLSLOADER_DEBUG
      FlsFproD =  TestFlsloader_DebugMask09;
      FlsProcond2 =  TestFlsloader_DebugMask06;
      FlsProcondrpro2 =  TestFlsloader_DebugMask06;
      #else
      FlsFproD = FLASH0_FPRO.B.PRODISD;
      FlsProcond2 = FLASH0_PROCOND.B.L;
      FlsProcondrpro2 = FLASH0_PROCOND.B.RPRO;
      #endif
        if (FlsFproD != 1U)
        {
          if(FlsProcond2 == 1U)
          {
            RetError = (FlsLoader_ReturnType)FLSLOADER_E_LOCKED;
          }
          if(FlsProcondrpro2 == 1U)
          {
            RetError = (FlsLoader_ReturnType)FLSLOADER_E_LOCKED;
          }
        }
     #endif    /* #if (FLSLOADER_ENABLE_LOCKCHECK == STD_ON) */

  }
  else
  {
    /*Check if the Target Address passed is UCB protected */
    #if (FLSLOADER_ENABLE_LOCKCHECK == STD_ON)
          /* Protection Check Algorithm */
      /* Preprocessor switch to enable/disable the lockcheck functionality */
      /* Check if global write protection is installed */
      #ifdef  IFX_FLSLOADER_DEBUG
      FlsFpro =  TestFlsloader_DebugMask09;
      #else
      FlsFpro = FLASH0_FPRO.B.PRODISP;
      #endif

      if(FlsFpro != 1U)
      {
        for (BankIndex = 0U; BankIndex < FLSLOADER_PF_BANKS; BankIndex++)
        {
          #ifdef  IFX_FLSLOADER_DEBUG
          FlsProconp2 =  TestFlsloader_DebugMask06;
          #else
          FlsProconp2 = FLASH0_PROCONP[BankIndex].B.RPRO;
          #endif

          if (FlsProconp2 == 1U)
          {
            RetError = (FlsLoader_ReturnType)FLSLOADER_E_LOCKED;
          }
        }
      }
    #endif    /* #if (FLSLOADER_ENABLE_LOCKCHECK == STD_ON) */

      for (BankIndex = 0U; BankIndex < FLSLOADER_PF_BANKS; BankIndex++)
      {
        #ifdef  IFX_FLSLOADER_DEBUG
        Fls0Proconp3 =   TestFlsloader_DebugMask09;
        Fls0Proconwop = TestFlsloader_DebugMask07;
        #else
        Fls0Proconp3 =FLASH0_PROCONP[BankIndex].U ;
        Fls0Proconwop = FLASH0_PROCONWOP[BankIndex].U ;
        #endif

       if (RetError == (FlsLoader_ReturnType)FLSLOADER_E_OK)
       {
        if ((Fls0Proconp3 != 0U))
        {
          RetError = FlsLoader_lCheckSectorProt(TargetAddress, Length);
        }
        else if (Fls0Proconwop != 0U)
        {
          RetError = FlsLoader_lCheckSectorProt(TargetAddress, Length);
        }
        else
          /* (FLASH0_PROCONOTP[BankIndex].U != 0U) */
        {
          RetError = FlsLoader_lCheckSectorProt(TargetAddress, Length);
        }
       }
     }
   }

  StartAddress = FLSLOADER_CMD_BASE;
  Icr = FlsLoader_lDisableInts();

  Mcal_ResetSafetyENDINIT();

  DSYNC();

  /* Block 3: Execute the Erase command sequence. */
  if (RetError == (FlsLoader_ReturnType)FLSLOADER_E_OK)
  {
    FlsLoader_Status = FLSLOADER_NORMAL; /* Initiating the state to normal */

  /* Safety Reset Endinit is required for PFlash */

   /* Enter Critical Section */

    /* cycle 1 */
    *((FlsLoader_AddressType*)FLSLOADER_GET_CYCLE_AA50(StartAddress))  = \
                                                            TargetAddress;
    /* cycle 2 */
    *((FlsLoader_AddressType*)FLSLOADER_GET_CYCLE_AA58(StartAddress))  = \
                                                             Length;
    /* cycle 3 */
    *((FlsLoader_AddressType*)FLSLOADER_GET_CYCLE_AAA8(StartAddress))  = \
                                                             FLSLOADER_VALUE_80;
    /* cycle 4 */
    *((FlsLoader_AddressType*)FLSLOADER_GET_CYCLE_AAA8(StartAddress))  = \
                                                             FLSLOADER_VALUE_50;
    /* Exit Critical Section */
    Mcal_SetSafetyENDINIT();

    DSYNC();

    /*InnerCount = 0U;*/
    #ifdef  IFX_FLSLOADER_DEBUG
    InnerCount = TestFlsloader_DebugMask07;
    FlsFSRErase =  TestFlsloader_DebugMask06;
    #else
    InnerCount = 0U;
    FlsFSRErase = FLASH0_FSR.B.ERASE;
    #endif

    while((FlsFSRErase != FLSLOADER_BIT_SET) &&
          (InnerCount < FLSLOADER_CMDCYCLE_TIMEOUT))
    {
      InnerCount++;
    }

    /* Check for FLASH BUSY flag */
    /* PnBUSY and D0BUSY */
    while((FLASH0_FSR.U & FLSLOADER_FLASH_BUSY_MASK) != 0U)
    {
      /*Do Nothing */
    }

    FlsLoader_lEnableInts(Icr);

    /* This check makes sure No protection error and no sequence error
    and No operation error has occurred.*/
    #ifdef  IFX_FLSLOADER_DEBUG
    RetError = TestFlsloader_DebugMask08;
    #else
    RetError = FlsLoader_lProtSeqOperErrorCheck();
    #endif


    if(RetError == (FlsLoader_ReturnType)FLSLOADER_E_OK)
    {
      /* This check makes sure No erase verification error */
      RetError = FlsLoader_lEverCheck();
    }

    /* Check if Suspend command is requested */
#ifdef IFX_FLSLOADER_DEBUG
    FlsLoader_Status = (uint8)TestFlsloader_DebugMask02;
#endif/*#ifdef IFX_FLSLOADER_DEBUG */

    if (RetError == (FlsLoader_ReturnType)FLSLOADER_E_OK)
    {
    /* Clear the status if the operation is successful.*/
     *((FlsLoader_AddressType*)FlsLoader_lClearStatus(StartAddress))
                        = FLSLOADER_VALUE_FA;
    }
  }
  else
  {
      Mcal_SetSafetyENDINIT();
      FlsLoader_lEnableInts(Icr);
  }

  return(RetError);

} /* End of Function */

#define FLSLOADER_STOP_SEC_ERASE_CODE
#include "MemMap.h"

#define FLSLOADER_START_SEC_CODE
#include "MemMap.h"

/* Preprocessor switch to enable/disable the FlsLoader_Lock API */
#if (FLSLOADER_LOCK_UNLOCK_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1627]                              **
**            [/cover]                                                        **
** Syntax           :  FlsLoader_ReturnType FlsLoader_Write(                  **

** Syntax           :  FlsLoader_ReturnType FlsLoader_Lock(                   **
**                      FlsLoader_AddressType TargetAddress,                  **
**                      FlsLoader_LengthType Length                           **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x04                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : FlsLoader_AddressType TargetAddress,                    **                                                       **
**                    FlsLoader_LengthType Length                             **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     :  FlsLoader_ReturnType:(DET is not enabled)              **
**                     1.FLSLOADER_E_OK                                       **
**                     2.FLSLOADER_E_BUSY                                     **
**                     3.FLSLOADER_E_LOCKED                                   **
**                     4.FLSLOADER_E_NOT_OK for all errors but for busy.      **
**                       For busy state FLSLOADER_E_BUSY is returned          **
**                                                                            **
** Description      : This function is used to  Apply the sector protection to**
**                    the internal  Flash of the microcontroller.             **
**                    If any sector is previously locked FLSLOADER_E_LOCKED   **
**                    is returned.                                            **
**                    No valid parameters are expected here.                  **
**                    This API cannot be suspended                            **
**                    Service to Lock the internal flash of the microcontroller.
**                    Locking is dependent on the parameters given and not the**
**                    passsed parameters.                                     **
*******************************************************************************/
FlsLoader_ReturnType FlsLoader_Lock(void)
{
  uint32 FlashBusy;
  FlsLoader_ReturnType RetError ;
    uint32                FlsFpro;
    uint32                FlsFproinp;
    uint32                FlsFproind;
    uint32                FlsFproinotp;

  RetError = (FlsLoader_ReturnType)FLSLOADER_E_OK ;

#if (FLSLOADER_DEV_ERROR_DETECT == STD_ON)
  if (FlsLoader_InitStatus != FLSLOADER_INITIALIZED)
  {
    /* Report missing initialization to DET */
    Det_ReportError( (uint16)FLSLOADER_MODULE_ID,
                    FLSLOADER_INSTANCE_ID,
                    FLSLOADER_SID_LOCK,
                    FLSLOADER_E_UNINIT);
    RetError = (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
  }

#endif
   /* (FLSLOADER_DEV_ERROR_DETECT == STD_ON) */

 /* Check if PFLASH0/1 or DFLASH is busy */
#ifdef IFX_FLSLOADER_DEBUG
FlashBusy = TestFlsloader_DebugMask01;
#else
FlashBusy = (uint32)(FLASH0_FSR.U & FLSLOADER_FLASH_BUSY_MASK);
#endif/*#ifdef IFX_FLSLOADER_DEBUG*/
  if (FlashBusy != FLSLOADER_ZERO_DATA)
  {
    /* Report Flash Busy to DET */
    RetError = (FlsLoader_ReturnType)FLSLOADER_E_BUSY;
    #if (FLSLOADER_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError(
                    (uint16)FLSLOADER_MODULE_ID,
                    FLSLOADER_INSTANCE_ID,
                    FLSLOADER_SID_LOCK,
                    (uint8)FLSLOADER_E_BUSY);
    #endif
      /*(FLSLOADER_DEV_ERROR_DETECT == STD_ON)*/
  }

  /* Protection should not be installed for the corresponding user level.*/
  if (RetError == (FlsLoader_ReturnType)FLSLOADER_E_OK)
  {
    /* Check if read/write/OTP/WOP is installled in PFLASH or DFLASH */

      #ifdef  IFX_FLSLOADER_DEBUG
      FlsFpro       = TestFlsloader_DebugMask06;
      FlsFproinp    = TestFlsloader_DebugMask07;
      FlsFproind    = TestFlsloader_DebugMask07;
      FlsFproinotp  = TestFlsloader_DebugMask07;
      #else
      FlsFpro = FLASH0_FPRO.B.PRODISP;
      FlsFproinp = FLASH0_FPRO.B.PROINP;
      FlsFproind = FLASH0_FPRO.B.PROIND;
      FlsFproinotp =  FLASH0_FPRO.B.PROINOTP;
      #endif

    if(FlsFpro != 1U)
    {
      if(FlsFproinp == 1U)
      {
        RetError = (FlsLoader_ReturnType)FLSLOADER_E_LOCKED;
      }
      if(FlsFproind == 1U)
      {
        RetError = (FlsLoader_ReturnType)FLSLOADER_E_LOCKED;
      }
    }
    if(FlsFproinotp == 1U)
    {
      RetError = (FlsLoader_ReturnType)FLSLOADER_E_LOCKED;
    }
  }

  if (RetError == (FlsLoader_ReturnType)FLSLOADER_E_OK)
  {
    RetError = FlsLoader_lLock();
  }

 return (RetError);

} /* End of function FlsLoader_Lock */
#endif /*(FLSLOADER_LOCK_UNLOCK_API == STD_ON) */


#if (FLSLOADER_LOCK_UNLOCK_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1629]                **
**            [/cover]                                                        **
** Syntax           :  FlsLoader_ReturnType FlsLoader_Write(                  **

** Syntax           :  FlsLoader_ReturnType FlsLoader_UnLock(                 **
**                       FlsLoader_ValueType Mode,                            **
**                       FlsLoader_ValueType* Password,                       **
**                       FlsLoader_AddressType TargetAddress                  **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x05                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   :                                                         **
**                    Password: pointer to the 4 double word(256 bit)         **
**                               Password for UCB protection                  **
**                    TargetAddress: Target address of user config block.     **
**                    Possible values are 0xAF100000, 0xAF100400.             **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : FlsLoader_ReturnType:(DET is not enabled)               **
**                    1.FLSLOADER_E_OK                                        **
**                    2.FLSLOADER_E_BUSY                                      **
**                    3.FLSLOADER_E_NOT_OK                                    **
**                                                                            **
** Description      : This function is used to  unlock(protect) the protection
                      in                                PFLASH and DFLASH     **
                      protection.                                             **
**                    A wrong password will result in Protection Error        **
**                    This API needs to be called twice if the user needs to  **
**                    unlock both PFLASH and DFLASH protection                **
**                    This API cannot be suspended                            **
*******************************************************************************/
FlsLoader_ReturnType FlsLoader_UnLock(
                                    FlsLoader_AddressType TargetAddress,
                                    FlsLoader_ValueType* Password
                                    )
{
  FlsLoader_ReturnType RetError ;
  volatile FlsLoader_AddressType StartAddress;
  volatile FlsLoader_ValueType* Passwordptr;
  volatile uint32 FlsErrCheck;
  volatile uint32  FlsBusyStat;
  volatile uint32  FlsFpro;
  volatile uint32  FlsFprodisd;
  volatile uint8 UserConfig;
  volatile uint8    Index;


  /* Init RetError to OK */
  RetError = (FlsLoader_ReturnType)FLSLOADER_E_OK ;
  Passwordptr = Password;

#if (FLSLOADER_DEV_ERROR_DETECT == STD_ON)
  if (FlsLoader_InitStatus != FLSLOADER_INITIALIZED)
  {
    /*  Report missing initialization to DET */
    Det_ReportError(
                    (uint16)FLSLOADER_MODULE_ID,
                    FLSLOADER_INSTANCE_ID,
                    FLSLOADER_SID_UNLOCK,
                    FLSLOADER_E_UNINIT);
    RetError = (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
  }
  else
  {
    if ((TargetAddress != FLSLOADER_UCB_PFLASH)&&
        (TargetAddress != FLSLOADER_UCB_DFLASH))
    {
      Det_ReportError(
                     (uint16)FLSLOADER_MODULE_ID,
                     FLSLOADER_INSTANCE_ID,
                     FLSLOADER_SID_UNLOCK,
                     FLSLOADER_E_PARAM_ADDRESS);
      RetError = (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
    }
  }
#endif
   /* #if (FLSLOADER_DEV_ERROR_DETECT == STD_ON) */

  /* PROTECTION in PFLASH  */
  if ( TargetAddress == FLSLOADER_UCB_PFLASH )
  {
    /* PROTECTION in PFLASH  */
    UserConfig = FLSLOADER_UCB0;
  }
  else
  {
    /* PROTECTION in DFLASH  */
    UserConfig = FLSLOADER_UCB1;
  }

  /* Start address for the command cycle */
  StartAddress = FLSLOADER_DFLASH0_START_ADDRESS;

#ifdef IFX_FLSLOADER_DEBUG
  FlsBusyStat = TestFlsloader_DebugMask01;
#else
  FlsBusyStat = (uint32)(FLASH0_FSR.U & (uint32)FLSLOADER_FLASH_BUSY_MASK);
#endif/*#ifdef IFX_FLSLOADER_DEBUG*/

  if (FlsBusyStat != 0U)
  {
    /* Report Pflash busy to DET */
    #if (FLSLOADER_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError(
                    (uint16)FLSLOADER_MODULE_ID,
                    FLSLOADER_INSTANCE_ID,
                    FLSLOADER_SID_UNLOCK,
                    (uint8)FLSLOADER_E_BUSY);
    #endif
    /*lint -e904  */
    return (FlsLoader_ReturnType)FLSLOADER_E_BUSY;
    /*lint +e904  */
  }

  /* cycle 1 */
  *((FlsLoader_AddressType*)FLSLOADER_GET_CYCLE_553C(StartAddress))  = \
                                                            UserConfig;
  /* Cycle 2 to Cycle 9 : Passwords for disabling protection */
  for(Index =(uint8)0U; Index < FLSLOADER_PWD; Index++)
  {
   /* provide 8 passwords */
   *((FlsLoader_AddressType*)FLSLOADER_GET_CYCLE_553C(StartAddress))  = \
                                                           Passwordptr[Index];
  }



    if (UserConfig == FLSLOADER_UCB0)
    {
          /*Check if there are no protection and sequence errors*/
    FlsErrCheck = FlsLoader_lProtSeqOperErrorCheck();

      /* Check if PFlash Protection is Disabled*/
      #ifdef  IFX_FLSLOADER_DEBUG
      FlsFpro     = TestFlsloader_DebugMask06;
      #else
      FlsFpro     = FLASH0_FPRO.B.PRODISP;
      #endif

      if ((FlsFpro == 0U) || (FlsErrCheck == FLSLOADER_E_NOT_OK))
      {
        /* return if protection is not disabled or if there are errors */
        RetError = (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
      }
    }
    else
    {
          /*Check if there are no protection and sequence errors*/
    FlsErrCheck = FlsLoader_lProtSeqOperErrorCheck();
      /* Check if DFlash Protection is Disabled*/
      #ifdef  IFX_FLSLOADER_DEBUG
      FlsFprodisd = TestFlsloader_DebugMask06;
      #else
      FlsFprodisd = FLASH0_FPRO.B.PRODISD;
      #endif

      if ((FlsFprodisd == 0U) || (FlsErrCheck == FLSLOADER_E_NOT_OK))
      {
        /* return if protection is not disabled or if there are errors */
        RetError = (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
      }
    }

  if (RetError == (FlsLoader_ReturnType)FLSLOADER_E_OK)
  {
      *((FlsLoader_AddressType*)FlsLoader_lClearStatus(StartAddress)) = \
                                                            FLSLOADER_VALUE_FA;
  }

  return (RetError) ;
}
#endif /* if (FLSLOADER_LOCK_UNLOCK_API == STD_ON)    */

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1628]                              **
**            [/cover]                                                        **
** Syntax           :  FlsLoader_ReturnType FlsLoader_Write(                  **

** Syntax           :  FlsLoader_ReturnType FlsLoader_Suspend(                **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x06                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : void                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : FLSLOADER_E_OK - API excecuted succesffully             **
**                    FLSLOADER_E_NOT_OK - DET errors occured                 **
**                                                                            **
**                                                                            **
** Description      : This function is used to  suspend flash write or        **
                      erase operation.                                        **
*******************************************************************************/
FlsLoader_ReturnType FlsLoader_Suspend (void)
{
  #if (FLSLOADER_DEV_ERROR_DETECT == STD_ON)

  if (FlsLoader_InitStatus != FLSLOADER_INITIALIZED)
  {
    /* Report missing initialization to DET */
    Det_ReportError(
                    (uint16)FLSLOADER_MODULE_ID,
                    FLSLOADER_INSTANCE_ID,
                    FLSLOADER_SID_SUSPEND,
                    FLSLOADER_E_UNINIT);
    /*lint -e904  */
    return (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
    /*lint +e904  */
  }
  #endif

  FlsLoader_Status = FLSLOADER_SUSPEND;

  return((FlsLoader_ReturnType)FLSLOADER_E_OK);
} /*End of suspend function */


#define FLSLOADER_STOP_SEC_CODE
#include "MemMap.h"
/* Inline Functions */


#define FLSLOADER_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1629]                              **
**            [/cover]                                                        **
** Syntax           :  FlsLoader_ReturnType FlsLoader_Write(                  **

** Syntax           : FlsLoader_ReturnType  FlsLoader_lPverCheck(             **
**                      uint32 Module, uint32 FlashType                       **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   :                                                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : value: RetError                                         **
**                                                                            **
** Description      : This function checks for Program Verify Error           **
*******************************************************************************/
static _INLINE_ FlsLoader_ReturnType FlsLoader_lPverCheck()
{
  volatile uint32 FlsPeverErr ;
  FlsLoader_ReturnType  RetError;

  RetError = FLSLOADER_E_OK;

  #ifdef  IFX_FLSLOADER_DEBUG
  FlsPeverErr = (FLASH0_FSR.U & FLS_PVER_ERROR)||TestFlsloader_DebugMask06;
  #else
  FlsPeverErr = (uint32)(FLASH0_FSR.U & FLS_PVER_ERROR);
  #endif

  if (FlsPeverErr)
  {
    RetError = FLSLOADER_E_NOT_OK;
  }
  return (RetError);
}


/*******************************************************************************
** Syntax           : FlsLoader_ReturnType  FlsLoader_lEverCheck(void)        **
**                                                                            **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   :                                                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : value: RetError                                         **
**                                                                            **
** Description      : This function checks for Erase Verify Error             **
*******************************************************************************/
static _INLINE_ FlsLoader_ReturnType FlsLoader_lEverCheck(void)
{
  volatile uint32 FlsEverError;
  FlsLoader_ReturnType  RetError;

  RetError = FLSLOADER_E_OK;
  #ifdef  IFX_FLSLOADER_DEBUG
  FlsEverError = TestFlsloader_DebugMask09;
  #else
  FlsEverError = (uint32)(FLASH0_FSR.U & FLS_EVER_ERROR);
  #endif

  if (FlsEverError)
  {
    RetError = FLSLOADER_E_NOT_OK;
  }
  return (RetError);
}

/*******************************************************************************
** Syntax           : void FlsLoader_lDisableInts                             **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       :   NA                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) :                                                         **
** Return value     : sint32                                                  **
**                                                                            **
** Description      : This function disables the global interrupt flag.       **
**                                                                            **
*******************************************************************************/
sint32 FlsLoader_lDisableInts(void)
{
  /*lint -esym(*,__mfcr) */
  sint32 Icr;
  /* read interrupt control register */
  ISYNC(); /* execute isync */
  Icr = MFCR(CPU_ICR);
  /* disable interrupts */
  DISABLE();
  return (Icr);

}

/*******************************************************************************
** Syntax           : void FlsLoader_lEnableInts                              **
**                    (                                                       **
**                      sint32 Icr                                            **
**                    )                                                       **
**                                                                            **
** Service ID       :   NA                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) :                                                         **
** Return value     : sint32                                                  **
**                                                                            **
** Description      : This function restores the global interrupt flag.       **
**                                                                            **
*******************************************************************************/
void FlsLoader_lEnableInts(sint32 Icr)
{
  #ifdef IFX_FLSLOADER_DEBUG
  Icr = TestFlsloader_DebugMask05;
  #endif/*#ifdef IFX_FLSLOADER_DEBUG*/
  if ((uint32)Icr & ((uint32)1U << (uint32)FLSLOADER_SHIFT_BY_15))
  {
    /* interrupts were enabled, enable again */
    ENABLE();
  }
}

/* Memory Map of the FLSLOADER Code */
#define FLSLOADER_STOP_SEC_CODE
#include "MemMap.h"



