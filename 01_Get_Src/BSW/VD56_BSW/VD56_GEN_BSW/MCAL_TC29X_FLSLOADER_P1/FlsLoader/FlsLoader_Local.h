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
**  $FILENAME   : FlsLoader_Local.h $                                        **
**                                                                           **
**  $CC VERSION : \main\7 $                                                  **
**                                                                           **
**  $DATE       : 2013-12-09 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains local functionality of FLSLOADRE driver.**
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/* TRACEABILITY :  [cover parentID=]
                   [/cover]                                                   */
#ifndef FLSLOADER_LOCAL_H
#define FLSLOADER_LOCAL_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"

#include "Mcal.h"

/* Inclusion of Flash header file */
#include "FlsLoader.h"

#include "IfxCpu_reg.h"

/* Inclusion of SchM Header File */
#include "SchM_FlsLoader.h"

/* Conditional Inclusion of Developement Error Tracer File */
#if  ( FLSLOADER_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif
/*******************************************************************************
**                      Global Macro Definitions                             **
*******************************************************************************/
/* Sector Nos */
#define FLSLOADER_S0      ((uint32)(0U))
#define FLSLOADER_S1      ((uint32)(1U))
#define FLSLOADER_S2      ((uint32)(2U))
#define FLSLOADER_S3      ((uint32)(3U))
#define FLSLOADER_S4      ((uint32)(4U))
#define FLSLOADER_S5      ((uint32)(5U))
#define FLSLOADER_S6      ((uint32)(6U))
#define FLSLOADER_S7      ((uint32)(7U))
#define FLSLOADER_S8      ((uint32)(8U))
#define FLSLOADER_S9      ((uint32)(9U))
#define FLSLOADER_S10     ((uint32)(10U))
#define FLSLOADER_S11     ((uint32)(11U))
#define FLSLOADER_S12     ((uint32)(12U))
#define FLSLOADER_S13     ((uint32)(13U))
#define FLSLOADER_S14     ((uint32)(14U))
#define FLSLOADER_S15     ((uint32)(15U))
#define FLSLOADER_S16     ((uint32)(16U))
#define FLSLOADER_S17     ((uint32)(17U))
#define FLSLOADER_S18     ((uint32)(18U))
#define FLSLOADER_S19     ((uint32)(19U))
#define FLSLOADER_S20     ((uint32)(20U))
#define FLSLOADER_S21     ((uint32)(21U))
#define FLSLOADER_S22     ((uint32)(22U))
#define FLSLOADER_S23     ((uint32)(23U))
#define FLSLOADER_S24     ((uint32)(24U))
#define FLSLOADER_S25     ((uint32)(25U))
#define FLSLOADER_S26     ((uint32)(26U))
#define FLSLOADER_INV     ((uint32)(0xFFU))

#define FLSLOADER_MOD_256               ((uint32)(0x000000FFU))
#define FLSLOADER_MOD_32                ((uint32)(0x0000001FU))
#define FLSLOADER_PFLASH_MASK           (uint32)(0x0000000FU)
/* Confirmation code is 0x57B5327F */
#define FLSLOADER_CONFIRMATION_CODE_B0  (0x34U)
#define FLSLOADER_CONFIRMATION_CODE_B1  (0x12U)
#define FLSLOADER_CONFIRMATION_CODE_B2  (0x21U)
#define FLSLOADER_CONFIRMATION_CODE_B3  (0x43U)

/* The following macros are used in the command cycles. */
#define FLSLOADER_CYCLE_5554           ((FlsLoader_AddressType)(0x00005554U))
#define FLSLOADER_CYCLE_55F0           ((FlsLoader_AddressType)(0x000055F0U))
#define FLSLOADER_CYCLE_AA50           ((FlsLoader_AddressType)(0x0000AA50U))
#define FLSLOADER_CYCLE_AA58           ((FlsLoader_AddressType)(0x0000AA58U))
#define FLSLOADER_CYCLE_AAA8           ((FlsLoader_AddressType)(0x0000AAA8U))
#define FLSLOADER_CYCLE_553C           ((FlsLoader_AddressType)(0x0000553CU))
#define FLSLOADER_MASK_HIGHER4_NIBBLES ((FlsLoader_AddressType)(0xFFFF0000U))
#define FLSLOADER_POSITION_0           ((FlsLoader_AddressType)0U)

/* The following values are used in the command cycles */
#define FLSLOADER_VALUE_80             ((FlsLoader_AddressType)(0x00000080U))
#define FLSLOADER_VALUE_F0             ((FlsLoader_AddressType)(0x000000F0U))
#define FLSLOADER_VALUE_A0             ((FlsLoader_AddressType)(0x000000A0U))
#define FLSLOADER_VALUE_5D             ((FlsLoader_AddressType)(0x0000005DU))
#define FLSLOADER_VALUE_7A             ((FlsLoader_AddressType)(0x0000007AU))
#define FLSLOADER_VALUE_00             ((FlsLoader_AddressType)(0x00000000U))
#define FLSLOADER_VALUE_FA             ((FlsLoader_AddressType)(0x000000FAU))
#define FLSLOADER_VALUE_50             ((FlsLoader_AddressType)(0x00000050U))
#define FLSLOADER_VALUE_AA             ((FlsLoader_AddressType)(0x000000AAU))
#define FLSLOADER_VALUE_F5             ((FlsLoader_AddressType)(0x000000F5U))
#define FLSLOADER_VALUE_08             ((FlsLoader_AddressType)(0x00000008U))
#define FLSLOADER_VALUE_5E             ((FlsLoader_AddressType)(0x0000005EU))

/* Command Cycle information*/
#define FLSLOADER_GET_CYCLE_5554(Address) \
           (((Address) & FLSLOADER_MASK_HIGHER4_NIBBLES) + FLSLOADER_CYCLE_5554)
#define FLSLOADER_GET_CYCLE_AA50(Address) \
           (((Address) & FLSLOADER_MASK_HIGHER4_NIBBLES) + FLSLOADER_CYCLE_AA50)
#define FLSLOADER_GET_CYCLE_AA58(Address) \
           (((Address) & FLSLOADER_MASK_HIGHER4_NIBBLES) + FLSLOADER_CYCLE_AA58)
#define FLSLOADER_GET_CYCLE_AAA8(Address) \
           (((Address) & FLSLOADER_MASK_HIGHER4_NIBBLES) + FLSLOADER_CYCLE_AAA8)
#define FLSLOADER_GET_CYCLE_55F0(Address) \
           (((Address) & FLSLOADER_MASK_HIGHER4_NIBBLES) + FLSLOADER_CYCLE_55F0)
#define FLSLOADER_GET_CYCLE_553C(Address) \
           (((Address) & FLSLOADER_MASK_HIGHER4_NIBBLES) + FLSLOADER_CYCLE_553C)

#define FLSLOADER_UCB_SIZE              (136U)
#define FLSLOADER_SHIFT_BY_15           (15U)
#define FLSLOADER_NUM_2                 (2U)
#define FLSLOADER_CMDCYCLE_TIMEOUT      (0x000FFFFFU)
#define FLSLOADER_BIT_SET               (1U)
#define FLSLOADER_DFLASH_BANK0          ((uint32)(0x00000002U))
#define FLSLOADER_PFLASH_BANK0          ((uint32)(0x00000008U))
#define FLSLOADER_PFLASH_BANK1          ((uint32)(0x00000010U))
#define FLSLOADER_PFLASH_BANK2          ((uint32)(0x00000020U))
#define FLSLOADER_PFLASH_BANK3          ((uint32)(0x00000040U))
#define FLSLOADER_SHIFT_BY_20           (uint32)(20U)
#define FLSLOADER_DFLASH_VAL            ((FlsLoader_AddressType)(0x0000005DU))
/* Protection,sequence and operation errors */
#define FLSLOADER_PROER_SQER_OPER_ERROR (0x00003800U)
#define FLSLOADER_OPER_ERROR            (0x00000800U)
#define FLSLOADER_SQER_ERROR            (0x00001000U)
#define FLSLOADER_PROER_ERROR           (0x00002000U)
#define FLSLOADER_INITIALIZED           (1U)
#define FLSLOADER_NUM_4                 (4U)
#define FLSLOADER_NUM_6                 (6U)

/*******************************************************************************
**                      Global function like Macros                          **
*******************************************************************************/
/*
Function Like Macro:FlsLoader_lCheckFlashType
macro to get wheter its PFLASH or DFLASH
Input Parameters:
Address: Address of the flash
*/
#define FlsLoader_lCheckFlashType(Address) \
          ((0xAFU ==(((Address) >> 24U) & 0xFFU)) ? 1U : 0U )

/*
Function Like Macro:FlsLoader_lEnterPageMode
Enters the Page Mode
Input Parameters: Address
*/
#define FlsLoader_lEnterPageMode(Address)    \
          (((Address) & FLSLOADER_MASK_HIGHER4_NIBBLES) + FLSLOADER_CYCLE_5554)
/*
Function Like Macro:FlsLoader_lClearStatus
Clears the status register
Input Parameters: Address
*/
#define FlsLoader_lClearStatus(Address)    \
          (((Address) & FLSLOADER_MASK_HIGHER4_NIBBLES) + FLSLOADER_CYCLE_5554)
/*
Function Like Macro:FlsLoader_lLoadPage
Loads the page in Write API
Input Parameters: Address
*/
#define FlsLoader_lLoadPage(Address)   \
          (((Address) & FLSLOADER_MASK_HIGHER4_NIBBLES) + FLSLOADER_CYCLE_55F0)
/*
Function Like Macro:FlsLoader_lResetRead
Resets to Read
Input Parameters: Address
*/
#define FlsLoader_lResetRead(Address)   \
          (((Address) & FLSLOADER_MASK_HIGHER4_NIBBLES) + FLSLOADER_CYCLE_5554)

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
#if (FLSLOADER_DEV_ERROR_DETECT == STD_ON)
#define FLSLOADER_START_SEC_VAR_8BIT
#include "MemMap.h"

extern uint8 FlsLoader_InitStatus;

#define FLSLOADER_STOP_SEC_VAR_8BIT
#include "MemMap.h"
#endif

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define FLSLOADER_START_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**                      Global Inline Function Declarations                   **
*******************************************************************************/
#if (FLSLOADER_LOCK_UNLOCK_API == STD_ON)
extern FlsLoader_ReturnType FlsLoader_lLock(void);
#endif

#if (FLSLOADER_DEV_ERROR_DETECT == STD_ON)
extern FlsLoader_ReturnType FlsLoader_lWriteDetCheck(
                                            FlsLoader_LengthType Length,\
                                        FlsLoader_AddressType TargetAddress);
                                        
extern FlsLoader_ReturnType FlsLoader_lEraseDetCheck(
                                     FlsLoader_LengthType Length,\
                                     FlsLoader_AddressType TargetAddress);

#endif

extern FlsLoader_ReturnType FlsLoader_lCheckSectorProt(
                      uint32 TargetAddress, FlsLoader_LengthType Length );


extern sint32 FlsLoader_lDisableInts(void);

extern void FlsLoader_lEnableInts(sint32 Icr);

/*******************************************************************************
** Syntax           : FlsLoader_ReturnType  FlsLoader_lProtSeqOperErrorCheck( **
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
** Description      : This function checks for protection, sequence, program, **
**                    and operational error occurred or not                   **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ FlsLoader_ReturnType FlsLoader_lProtSeqOperErrorCheck()
{
  FlsLoader_ReturnType  RetError;
  volatile uint32 FsrErrcheck;

  RetError = FLSLOADER_E_OK;
  FsrErrcheck = ((uint32)FLASH0_FSR.U &
                 ((uint32)FLSLOADER_PROER_SQER_OPER_ERROR));
  if (((FsrErrcheck & FLSLOADER_OPER_ERROR)== FLSLOADER_OPER_ERROR)||
      ((FsrErrcheck & FLSLOADER_SQER_ERROR)== FLSLOADER_SQER_ERROR))
  {
    RetError = FLSLOADER_E_NOT_OK;
  }
  else if ((FsrErrcheck & FLSLOADER_PROER_ERROR)== FLSLOADER_PROER_ERROR)
  {
    RetError = FLSLOADER_E_LOCKED;
  }
  else
  {
    /* do nothing */
  }
  return (RetError);
}


#define FLSLOADER_STOP_SEC_CODE
#include "MemMap.h"


#endif /* End of FLSLOADER_LOCAL_H */
