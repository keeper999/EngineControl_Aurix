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
**  $FILENAME   : FlsLoader_Platform.c $                                     **
**                                                                           **
**  $CC VERSION : \main\dev_tc29x\13 $                                       **
**                                                                           **
**  $DATE       : 2013-12-13 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains AURIX derivative (platform specific)    **
**                functionality of FlsLoader driver.                         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
    TRACEABILITY : [cover parentID=] [/cover]
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
#include "FlsLoader_Local.h"
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define FLSLOADER_PFLASH0_OFFSETEND     (0x001FFFFFU)
#define FLSLOADER_PFLASH1_OFFSETEND     (0x003FFFFFU)
#define FLSLOADER_PFLASH2_OFFSETEND     (0x005FFFFFU)
#define FLSLOADER_PFLASH3_OFFSETEND     (0x007FFFFFU)
#define FLSLOADER_PF0_SEGMENT_0         (0xA00U)
#define FLSLOADER_PF0_SEGMENT_1         (0xA01U)
#define FLSLOADER_PF1_SEGMENT_0         (0xA02U)
#define FLSLOADER_PF1_SEGMENT_1         (0xA03U)
#define FLSLOADER_PF2_SEGMENT_0         (0xA04U)
#define FLSLOADER_PF2_SEGMENT_1         (0xA05U)
#define FLSLOADER_PF3_SEGMENT_0         (0xA06U)
#define FLSLOADER_PF3_SEGMENT_1         (0xA07U)

#define FLSLOADER_ADDRESS_HI_5_MASK     ((FlsLoader_AddressType)(0x000FFFFFU))
#define FLSLOADER_PFLASH_ADDRESS_MASK   ((FlsLoader_AddressType)(0x00FFFFFFU))

#define FLSLOADER_NUM_UCB_SECTORS       (1U)
#define FLSLOADER_NUM_UCB_PAGES         (17U)
#define FLSLOADER_PAGE_SIZE             (8U)
#define FLSLOADER_SHIFT_BY_12           (12U)
#define FLSLOADER_ADDRESS_MASK          ((FlsLoader_AddressType)(0x0000FFFFU))

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
#define FLSLOADER_START_SEC_CONST_32BIT
#include "MemMap.h"

/* UCB_PFLASH Content */
#if ((FLSLOADER_PF0_PROT == WRITE_PROTECTION)||\
       (FLSLOADER_PF1_PROT == WRITE_PROTECTION)||\
       (FLSLOADER_PF2_PROT == WRITE_PROTECTION)||\
       (FLSLOADER_PF3_PROT == WRITE_PROTECTION)||\
     (FLSLOADER_PF0_PROT == READ_PROTECTION)||\
       (FLSLOADER_PF1_PROT == READ_PROTECTION)||\
       (FLSLOADER_PF2_PROT == READ_PROTECTION)||\
       (FLSLOADER_PF3_PROT == READ_PROTECTION))

/* UCB_PFLASH
  page 0 -bytes 0-3: FLASH0_PROCONP0
          bytes 4-7: FLASH0_PROCONP1
  page 1 -bytes 8-11 : all zeroes
          bytes 12-15 : all zeroes
  page 2 -bytes 16-19: copy of FLASH0_PROCONP0
          bytes 20-23: copy of FLASH0_PROCONP1
  page 3 -bytes 24-27 : all zeroes
          bytes 28-31 : all zeroes
  page 4 -bytes 32-39: PW0
  page 5 -bytes 40-47: PW1
  page 6 -bytes 48-55: PW2
  page 7 -bytes 56-63: PW3
  page 8 -bytes 64-71: PW0
  page 9  -bytes 72-79: PW1
  page 10 -bytes 80-87: PW2
  page 11 -bytes 88-95: PW3
  page 12 -bytes 96-103: all zeroes
  page 13 -bytes 104-111: all zeroes
  page 14 -bytes 112-115: confirmation code
           bytes 116-119: zeroes
  page 15 -bytes 120-123: confirmation code
           bytes 124-127: zeroes
*/

const uint8 FlsLoader_UcbPFlashPage0[FLSLOADER_UCB_SIZE] =
{
FLSLOADER_PROCONP0_BYTE0,FLSLOADER_PROCONP0_BYTE1,
FLSLOADER_PROCONP0_BYTE2,FLSLOADER_PROCONP0_BYTE3,
FLSLOADER_PROCONP1_BYTE0,FLSLOADER_PROCONP1_BYTE1,
FLSLOADER_PROCONP1_BYTE2,FLSLOADER_PROCONP1_BYTE3,
FLSLOADER_PROCONP2_BYTE0,FLSLOADER_PROCONP2_BYTE1,
FLSLOADER_PROCONP2_BYTE2,FLSLOADER_PROCONP2_BYTE3,
FLSLOADER_PROCONP3_BYTE0,FLSLOADER_PROCONP3_BYTE1,
FLSLOADER_PROCONP3_BYTE2,FLSLOADER_PROCONP3_BYTE3,
FLSLOADER_PROCONP0_BYTE0,FLSLOADER_PROCONP0_BYTE1,
FLSLOADER_PROCONP0_BYTE2,FLSLOADER_PROCONP0_BYTE3,
FLSLOADER_PROCONP1_BYTE0,FLSLOADER_PROCONP1_BYTE1,
FLSLOADER_PROCONP1_BYTE2,FLSLOADER_PROCONP1_BYTE3,
FLSLOADER_PROCONP2_BYTE0,FLSLOADER_PROCONP2_BYTE1,
FLSLOADER_PROCONP2_BYTE2,FLSLOADER_PROCONP2_BYTE3,
FLSLOADER_PROCONP3_BYTE0,FLSLOADER_PROCONP3_BYTE1,
FLSLOADER_PROCONP3_BYTE2,FLSLOADER_PROCONP3_BYTE3,
FLSLOADER_P0_PW00_B0,FLSLOADER_P0_PW00_B1,
FLSLOADER_P0_PW00_B2,FLSLOADER_P0_PW00_B3,
FLSLOADER_P0_PW01_B0,FLSLOADER_P0_PW01_B1,
FLSLOADER_P0_PW01_B2,FLSLOADER_P0_PW01_B3,
FLSLOADER_P0_PW10_B0,FLSLOADER_P0_PW10_B1,
FLSLOADER_P0_PW10_B2,FLSLOADER_P0_PW10_B3,
FLSLOADER_P0_PW11_B0,FLSLOADER_P0_PW11_B1,
FLSLOADER_P0_PW11_B2,FLSLOADER_P0_PW11_B3,
FLSLOADER_P0_PW20_B0,FLSLOADER_P0_PW20_B1,
FLSLOADER_P0_PW20_B2,FLSLOADER_P0_PW20_B3,
FLSLOADER_P0_PW21_B0,FLSLOADER_P0_PW21_B1,
FLSLOADER_P0_PW21_B2,FLSLOADER_P0_PW21_B3,
FLSLOADER_P0_PW30_B0,FLSLOADER_P0_PW30_B1,
FLSLOADER_P0_PW30_B2,FLSLOADER_P0_PW30_B3,
FLSLOADER_P0_PW31_B0,FLSLOADER_P0_PW31_B1,
FLSLOADER_P0_PW31_B2,FLSLOADER_P0_PW31_B3,
FLSLOADER_P0_PW00_B0,FLSLOADER_P0_PW00_B1,
FLSLOADER_P0_PW00_B2,FLSLOADER_P0_PW00_B3,
FLSLOADER_P0_PW01_B0,FLSLOADER_P0_PW01_B1,
FLSLOADER_P0_PW01_B2,FLSLOADER_P0_PW01_B3,
FLSLOADER_P0_PW10_B0,FLSLOADER_P0_PW10_B1,
FLSLOADER_P0_PW10_B2,FLSLOADER_P0_PW10_B3,
FLSLOADER_P0_PW11_B0,FLSLOADER_P0_PW11_B1,
FLSLOADER_P0_PW11_B2,FLSLOADER_P0_PW11_B3,
FLSLOADER_P0_PW20_B0,FLSLOADER_P0_PW20_B1,
FLSLOADER_P0_PW20_B2,FLSLOADER_P0_PW20_B3,
FLSLOADER_P0_PW21_B0,FLSLOADER_P0_PW21_B1,
FLSLOADER_P0_PW21_B2,FLSLOADER_P0_PW21_B3,
FLSLOADER_P0_PW30_B0,FLSLOADER_P0_PW30_B1,
FLSLOADER_P0_PW30_B2,FLSLOADER_P0_PW30_B3,
FLSLOADER_P0_PW31_B0,FLSLOADER_P0_PW31_B1,
FLSLOADER_P0_PW31_B2,FLSLOADER_P0_PW31_B3,
0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,
0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,
FLSLOADER_CONFIRMATION_CODE_B0,FLSLOADER_CONFIRMATION_CODE_B1,
FLSLOADER_CONFIRMATION_CODE_B2,FLSLOADER_CONFIRMATION_CODE_B3,
0x00U,0x00U,0x00U,0x00U,
FLSLOADER_CONFIRMATION_CODE_B0,FLSLOADER_CONFIRMATION_CODE_B1,
FLSLOADER_CONFIRMATION_CODE_B2,FLSLOADER_CONFIRMATION_CODE_B3,
0x00U,0x00U,0x00U,0x00U
};
#endif
/*#if ((FLSLOADER_PF0_PROT == WRITE_PROTECTION)||...*/


/* UCB_DPFLASH Content */
#if (FLSLOADER_DF0_PROT != NO_PROTECTION)
/* UCB_DFLASH
  page 0 -bytes 0-3: PROCOND
          bytes 4-7: all zeroes
  page 1 -bytes 8-11 : all zeroes
          bytes 12-15 : all zeroes
  page 2 -bytes 16-19: copy of PROCOND
          bytes 20-23: all zeroes
  page 3 -bytes 24-27 : all zeroes
          bytes 28-31 : all zeroes
  page 4 -bytes 32-39: PW0
  page 5 -bytes 40-47: PW1
  page 6 -bytes 48-55: PW2
  page 7 -bytes 56-63: PW3
  page 8 -bytes 64-71: PW0
  page 9  -bytes 72-79: PW1
  page 10 -bytes 80-87: PW2
  page 11 -bytes 88-95: PW3
  page 12 -bytes 96-103: all zeroes
  page 13 -bytes 104-111: all zeroes
  page 14 -bytes 112-115: confirmation code
           bytes 116-119: zeroes
  page 15 -bytes 120-123: confirmation code
           bytes 124-127: zeroes*/

const uint8 FlsLoader_UcbDFlashPage0[FLSLOADER_UCB_SIZE] = {
FLSLOADER_PROCOND_BYTE0,FLSLOADER_PROCOND_BYTE1,
FLSLOADER_PROCOND_BYTE2,FLSLOADER_PROCOND_BYTE3,
0x00U,0x00U,0x00U,0x00U,
0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,
FLSLOADER_PROCOND_BYTE0,FLSLOADER_PROCOND_BYTE1,
FLSLOADER_PROCOND_BYTE2,FLSLOADER_PROCOND_BYTE3,
0x00U,0x00U,0x00U,0x00U,
0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,
FLSLOADER_DF0_PW00_B0,FLSLOADER_DF0_PW00_B1,
FLSLOADER_DF0_PW00_B2,FLSLOADER_DF0_PW00_B3,
FLSLOADER_DF0_PW01_B0,FLSLOADER_DF0_PW01_B1,
FLSLOADER_DF0_PW01_B2,FLSLOADER_DF0_PW01_B3,
FLSLOADER_DF0_PW10_B0,FLSLOADER_DF0_PW10_B1,
FLSLOADER_DF0_PW10_B2,FLSLOADER_DF0_PW10_B3,
FLSLOADER_DF0_PW11_B0,FLSLOADER_DF0_PW11_B1,
FLSLOADER_DF0_PW11_B2,FLSLOADER_DF0_PW11_B3,
FLSLOADER_DF0_PW20_B0,FLSLOADER_DF0_PW20_B1,
FLSLOADER_DF0_PW20_B2,FLSLOADER_DF0_PW20_B3,
FLSLOADER_DF0_PW21_B0,FLSLOADER_DF0_PW21_B1,
FLSLOADER_DF0_PW21_B2,FLSLOADER_DF0_PW21_B3,
FLSLOADER_DF0_PW30_B0,FLSLOADER_DF0_PW30_B1,
FLSLOADER_DF0_PW30_B2,FLSLOADER_DF0_PW30_B3,
FLSLOADER_DF0_PW31_B0,FLSLOADER_DF0_PW31_B1,
FLSLOADER_DF0_PW31_B2,FLSLOADER_DF0_PW31_B3,
FLSLOADER_DF0_PW00_B0,FLSLOADER_DF0_PW00_B1,
FLSLOADER_DF0_PW00_B2,FLSLOADER_DF0_PW00_B3,
FLSLOADER_DF0_PW01_B0,FLSLOADER_DF0_PW01_B1,
FLSLOADER_DF0_PW01_B2,FLSLOADER_DF0_PW01_B3,
FLSLOADER_DF0_PW10_B0,FLSLOADER_DF0_PW10_B1,
FLSLOADER_DF0_PW10_B2,FLSLOADER_DF0_PW10_B3,
FLSLOADER_DF0_PW11_B0,FLSLOADER_DF0_PW11_B1,
FLSLOADER_DF0_PW11_B2,FLSLOADER_DF0_PW11_B3,
FLSLOADER_DF0_PW20_B0,FLSLOADER_DF0_PW20_B1,
FLSLOADER_DF0_PW20_B2,FLSLOADER_DF0_PW20_B3,
FLSLOADER_DF0_PW21_B0,FLSLOADER_DF0_PW21_B1,
FLSLOADER_DF0_PW21_B2,FLSLOADER_DF0_PW21_B3,
FLSLOADER_DF0_PW30_B0,FLSLOADER_DF0_PW30_B1,
FLSLOADER_DF0_PW30_B2,FLSLOADER_DF0_PW30_B3,
FLSLOADER_DF0_PW31_B0,FLSLOADER_DF0_PW31_B1,
FLSLOADER_DF0_PW31_B2,FLSLOADER_DF0_PW31_B3,
0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,
0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,
FLSLOADER_CONFIRMATION_CODE_B0,FLSLOADER_CONFIRMATION_CODE_B1,
FLSLOADER_CONFIRMATION_CODE_B2,FLSLOADER_CONFIRMATION_CODE_B3,
0x00U,0x00U,0x00U,0x00U,
FLSLOADER_CONFIRMATION_CODE_B0,FLSLOADER_CONFIRMATION_CODE_B1,
FLSLOADER_CONFIRMATION_CODE_B2,FLSLOADER_CONFIRMATION_CODE_B3,
0x00U,0x00U,0x00U,0x00U
};
#endif
/*#if (FLSLOADER_PF0_PROT != NO_PROTECTION)*/

/* UCB OTP FLASH content */
#if ((FLSLOADER_PF0_PROT == OTP_PROTECTION)||\
     (FLSLOADER_PF0_PROT == WOP_PROTECTION)||\
     (FLSLOADER_PF1_PROT == OTP_PROTECTION)||\
     (FLSLOADER_PF1_PROT == WOP_PROTECTION)||\
     (FLSLOADER_PF2_PROT == OTP_PROTECTION)||\
     (FLSLOADER_PF2_PROT == WOP_PROTECTION)||\
     (FLSLOADER_PF3_PROT == OTP_PROTECTION)||\
     (FLSLOADER_PF3_PROT == WOP_PROTECTION))
/* UCB_OTP
  page 0 -bytes 0-3: PROCONOTP0
          bytes 4-7: PROCONOTP1
  page 1 -bytes 8-15 : all zeroes
  page 2 -bytes 16-19: copy of PROCONOTP0
          bytes 20-23: copy of PROCONOTP1
  page 3 -bytes 24-31 : all zeroes
  page 4 -bytes 32-35: PROCONWOP0
          bytes 36-39: PROCONWOP1
  page 5  -bytes 40-47: all zeroes
  page 6  -bytes 48-51: copy of PROCONWOP0
  page    -bytes 52-55: copy of ROCONWOP1
  page 7   -bytes 56-63: all zeroes
  page 8   -bytes 64-71: all zeroes
  page 9  -bytes 72-79: all zeroes
  page 10  -bytes 80-87: all zeroes
  page 11  -bytes 88-95: all zeroes
  page 12  -bytes 96-103: all zeroes
  page 13  -bytes 104-111 : all zeroes
  page 14   bytes 112-115: confirmation code
           -bytes 116-119: all zeroes
  page 15  -bytes 120-123: copy of confirmation code
            bytes 124-127: all zeroes
*/


const uint8 FlsLoader_UcbOTPFlashPage0[FLSLOADER_UCB_SIZE] = {
FLSLOADER_PROCONOTP0_BYTE0,FLSLOADER_PROCONOTP0_BYTE1,
FLSLOADER_PROCONOTP0_BYTE2,FLSLOADER_PROCONOTP0_BYTE3,
FLSLOADER_PROCONOTP1_BYTE0,FLSLOADER_PROCONOTP1_BYTE1,
FLSLOADER_PROCONOTP1_BYTE2,FLSLOADER_PROCONOTP1_BYTE3,
FLSLOADER_PROCONOTP2_BYTE0,FLSLOADER_PROCONOTP2_BYTE1,
FLSLOADER_PROCONOTP2_BYTE2,FLSLOADER_PROCONOTP2_BYTE3,
FLSLOADER_PROCONOTP3_BYTE0,FLSLOADER_PROCONOTP3_BYTE1,
FLSLOADER_PROCONOTP3_BYTE2,FLSLOADER_PROCONOTP3_BYTE3,
FLSLOADER_PROCONOTP0_BYTE0,FLSLOADER_PROCONOTP0_BYTE1,
FLSLOADER_PROCONOTP0_BYTE2,FLSLOADER_PROCONOTP0_BYTE3,
FLSLOADER_PROCONOTP1_BYTE0,FLSLOADER_PROCONOTP1_BYTE1,
FLSLOADER_PROCONOTP1_BYTE2,FLSLOADER_PROCONOTP1_BYTE3,
FLSLOADER_PROCONOTP2_BYTE0,FLSLOADER_PROCONOTP2_BYTE1,
FLSLOADER_PROCONOTP2_BYTE2,FLSLOADER_PROCONOTP2_BYTE3,
FLSLOADER_PROCONOTP3_BYTE0,FLSLOADER_PROCONOTP3_BYTE1,
FLSLOADER_PROCONOTP3_BYTE2,FLSLOADER_PROCONOTP3_BYTE3,
FLSLOADER_PROCONWOP0_BYTE0,FLSLOADER_PROCONWOP0_BYTE1,
FLSLOADER_PROCONWOP0_BYTE2,FLSLOADER_PROCONWOP0_BYTE3,
FLSLOADER_PROCONWOP1_BYTE0,FLSLOADER_PROCONWOP1_BYTE1,
FLSLOADER_PROCONWOP1_BYTE2,FLSLOADER_PROCONWOP1_BYTE3,
FLSLOADER_PROCONWOP2_BYTE0,FLSLOADER_PROCONWOP2_BYTE1,
FLSLOADER_PROCONWOP2_BYTE2,FLSLOADER_PROCONWOP2_BYTE3,
FLSLOADER_PROCONWOP3_BYTE0,FLSLOADER_PROCONWOP3_BYTE1,
FLSLOADER_PROCONWOP3_BYTE2,FLSLOADER_PROCONWOP3_BYTE3,
FLSLOADER_PROCONWOP0_BYTE0,FLSLOADER_PROCONWOP0_BYTE1,
FLSLOADER_PROCONWOP0_BYTE2,FLSLOADER_PROCONWOP0_BYTE3,
FLSLOADER_PROCONWOP1_BYTE0,FLSLOADER_PROCONWOP1_BYTE1,
FLSLOADER_PROCONWOP1_BYTE2,FLSLOADER_PROCONWOP1_BYTE3,
FLSLOADER_PROCONWOP2_BYTE0,FLSLOADER_PROCONWOP2_BYTE1,
FLSLOADER_PROCONWOP2_BYTE2,FLSLOADER_PROCONWOP2_BYTE3,
FLSLOADER_PROCONWOP3_BYTE0,FLSLOADER_PROCONWOP3_BYTE1,
FLSLOADER_PROCONWOP3_BYTE2,FLSLOADER_PROCONWOP3_BYTE3,
0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,
0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,
0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,
0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,
0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,
0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,
FLSLOADER_CONFIRMATION_CODE_B0,FLSLOADER_CONFIRMATION_CODE_B1,
FLSLOADER_CONFIRMATION_CODE_B2,FLSLOADER_CONFIRMATION_CODE_B3,
0x00U,0x00U,0x00U,0x00U,
FLSLOADER_CONFIRMATION_CODE_B0,FLSLOADER_CONFIRMATION_CODE_B1,
FLSLOADER_CONFIRMATION_CODE_B2,FLSLOADER_CONFIRMATION_CODE_B3,
0x00U,0x00U,0x00U,0x00U};

#endif
/*  #if ((FLSLOADER_PF0_PROT == OTP_PROTECTION)...*/

#define FLSLOADER_STOP_SEC_CONST_32BIT
#include "MemMap.h"


/*******************************************************************************
**                      Private Macro like functions                          **
*******************************************************************************/
/*
Function Like FlsLoader_lDFlashCheck
Input Parameters: TargetAddress
*/
#define FlsLoader_lDFlashCheck(TargetAddress) \
     (((TargetAddress)  >= FLSLOADER_DFLASH0_START_ADDRESS) && \
       ((TargetAddress) <= FLSLOADER_DFLASH0_END))

#define FlsLoader_lPFlashCheck(TargetAddress) \
     ((((TargetAddress)  >= FLSLOADER_PFLASH0_START_ADDRESS) && \
       ((TargetAddress)  <= FLSLOADER_PFLASH0_END)) ||\
       (((TargetAddress)  >= FLSLOADER_PFLASH1_START_ADDRESS)&&\
       ((TargetAddress)  <= FLSLOADER_PFLASH1_END))||\
       (((TargetAddress)  >= FLSLOADER_PFLASH2_START_ADDRESS) && \
       ((TargetAddress)  <= FLSLOADER_PFLASH2_END)) ||\
       (((TargetAddress)  >= FLSLOADER_PFLASH3_START_ADDRESS)&&\
       ((TargetAddress)  <= FLSLOADER_PFLASH3_END)))

/*
Function Like FlsLoader_lDFlashPageCheck
Input Parameters: TargetAddress,Length
*/
#define FlsLoader_lDFlashPageCheck(TargetAddress,Length) \
  (((Length) == (FlsLoader_LengthType)0U) || \
  (((Length) & ((FlsLoader_LengthType)FLSLOADER_MOD_32)) != 0U) || \
  (((FlsLoader_LengthType)(Length) + ((TargetAddress) & \
  (FlsLoader_AddressType)FLSLOADER_ADDRESS_MASK))> \
  (FlsLoader_AddressType)FLSLOADER_DFLASH_BANK_SIZE))

/*******************************************************************************
**                    Prototypes Of Local Functions                           **
*******************************************************************************/
#if (FLSLOADER_DEV_ERROR_DETECT == STD_ON)
static _INLINE_ uint8 FlsLoader_lAddressPageCheck(
                                         FlsLoader_AddressType TargetAddress);

#endif

#if (FLSLOADER_LOCK_UNLOCK_API == STD_ON)
static _INLINE_ FlsLoader_ReturnType  FlsLoader_lLockCmdCycles(
                         FlsLoader_AddressType StartAddress,
                         FlsLoader_AddressType UcbSectorAddress,
                         const FlashLoader_DataType *PdataPtr);
#endif

static _INLINE_ FlsLoader_ReturnType FlsLoader_lSectorProtCheck(
                               uint32 FlashType,
                               uint32 SectorNumber,
                               FlsLoader_LengthType Length );

static _INLINE_ uint32 FlsLoader_lSectorNumber(uint32 Offset);

/******************************************************************************
**                      Private Variable Definitions                         **
******************************************************************************/
#ifdef IFX_FLSLOADER_DEBUG
  #define FLSLOADER_START_SEC_VAR_32BIT
  #include "MemMap.h"
    extern volatile uint32 TestFlsloader_DebugMask01;
  #define FLSLOADER_STOP_SEC_VAR_32BIT
  #include "MemMap.h"
#endif

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*Memory Map of the FlsLoader Code*/
#define FLSLOADER_START_SEC_CODE
#include "MemMap.h"

#if (FLSLOADER_LOCK_UNLOCK_API == STD_ON)
/*******************************************************************************
** Syntax           : FlsLoader_ReturnType FlsLoader_lLock(void)              **
**                                                                            **
** Service ID       :   NA                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) :                                                         **
** Return value     : FlsLoader_ReturnType                                    **
**                                                                            **
** Description      : This function Locks the required profile and called     **
**                    from Lock Sync API.                                     **
**                                                                            **
*******************************************************************************/
 FlsLoader_ReturnType FlsLoader_lLock(void)
{

  FlsLoader_ReturnType RetError;
  FlsLoader_AddressType StartAddress;
  FlsLoader_AddressType UcbSectorAddress;
  const FlashLoader_DataType *PdataPtr ;


  StartAddress = FLSLOADER_DFLASH0_START_ADDRESS;
  #if ((FLSLOADER_PF0_PROT == NO_PROTECTION)&&\
       (FLSLOADER_PF1_PROT == NO_PROTECTION)&&\
     (FLSLOADER_PF2_PROT == NO_PROTECTION)&&\
       (FLSLOADER_PF3_PROT == NO_PROTECTION))
  RetError = FLSLOADER_E_OK;
  #endif

  /* Call the LOCK function for each typr of protection*/
  /* Check if write or Read protection is Enabled on PF0/PF1 configuration*/
  #if ((FLSLOADER_PF0_PROT == WRITE_PROTECTION)||\
       (FLSLOADER_PF1_PROT == WRITE_PROTECTION)||\
       (FLSLOADER_PF2_PROT == WRITE_PROTECTION)||\
       (FLSLOADER_PF3_PROT == WRITE_PROTECTION)||\
     (FLSLOADER_PF0_PROT == READ_PROTECTION)||\
       (FLSLOADER_PF1_PROT == READ_PROTECTION)||\
       (FLSLOADER_PF2_PROT == READ_PROTECTION)||\
       (FLSLOADER_PF3_PROT == READ_PROTECTION))
    /*PFLASH protection */
    UcbSectorAddress = FLSLOADER_UCB_PFLASH;
    PdataPtr = (FlashLoader_DataType*)(void*)(&FlsLoader_UcbPFlashPage0[0]);
    RetError = FlsLoader_lLockCmdCycles(StartAddress,UcbSectorAddress,PdataPtr);

  #endif
   /* End of Check for WR or READ protection on PF0/PF1 '*/

    /* Check for DF0 write or Read protection  */
#if (FLSLOADER_DF0_PROT != NO_PROTECTION)
  if (RetError == (FlsLoader_ReturnType)FLSLOADER_E_OK)
  {
    /* DFLASH protection */
    UcbSectorAddress = FLSLOADER_UCB_DFLASH;
    PdataPtr = (FlashLoader_DataType*)((void*)FlsLoader_UcbDFlashPage0);
    RetError = FlsLoader_lLockCmdCycles(StartAddress,UcbSectorAddress,PdataPtr);
  }
#endif
 /* Check for DF0 write or Read protection  */

    /* Check for OTP or WOP protection  */
  #if ((FLSLOADER_PF0_PROT == OTP_PROTECTION)||\
       (FLSLOADER_PF0_PROT == WOP_PROTECTION)||\
       (FLSLOADER_PF1_PROT == OTP_PROTECTION)||\
       (FLSLOADER_PF1_PROT == WOP_PROTECTION)||\
       (FLSLOADER_PF2_PROT == OTP_PROTECTION)||\
       (FLSLOADER_PF2_PROT == WOP_PROTECTION)||\
       (FLSLOADER_PF3_PROT == OTP_PROTECTION)||\
       (FLSLOADER_PF3_PROT == WOP_PROTECTION))
  if (RetError == (FlsLoader_ReturnType)FLSLOADER_E_OK)
  {
    /* One Time Programming and Write Once protection ; */
    UcbSectorAddress = FLSLOADER_UCB_OTP;
    PdataPtr = (FlashLoader_DataType*)(void*)(&FlsLoader_UcbOTPFlashPage0[0]);
    RetError = FlsLoader_lLockCmdCycles(StartAddress,UcbSectorAddress,PdataPtr);
  }
#endif

  return RetError;
}

/*******************************************************************************
** Syntax           : void FlsLoader_lLockCmdCycles(                          **
**                      FlsLoader_AddressType TargetAddress ,
                        FlsLoader_AddressType UcbSectorAddress,
                        FlashLoader_DataType* PdataPtr                        **
**                    )                                                       **
**                                                                            **
** Service ID       :   NA                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) :                                                         **
** Return value     : FlsLoader_ReturnType                                    **
**                                                                            **
** Description      : This function Locks the required profile and called     **
**                    from Lock Sync API.                                     **
**                                                                            **
*******************************************************************************/
static _INLINE_ FlsLoader_ReturnType FlsLoader_lLockCmdCycles(
                         FlsLoader_AddressType StartAddress,
                         FlsLoader_AddressType UcbSectorAddress,
                         const FlashLoader_DataType *PdataPtr)
{


  FlsLoader_ReturnType  RetError;
  uint32 Count;
  uint32 InCount;
  uint32 InnerCount;
  sint32 Icr;
  /* Enter Critical Section */
  Icr = FlsLoader_lDisableInts();
  /* Erase the corresponding User Configuraiton Block */
    /* cycle 1 */
  *((FlsLoader_AddressType*)FLSLOADER_GET_CYCLE_AA50(StartAddress))  = \
                                                             UcbSectorAddress;
  /* cycle 2 */
  *((FlsLoader_AddressType*)FLSLOADER_GET_CYCLE_AA58(StartAddress))  = \
                                                    FLSLOADER_NUM_UCB_SECTORS;
  /* cycle 3 */
  *((FlsLoader_AddressType*)FLSLOADER_GET_CYCLE_AAA8(StartAddress))  = \
                                                           FLSLOADER_VALUE_80;
  /* cycle 4 */
  *((FlsLoader_AddressType*)FLSLOADER_GET_CYCLE_AAA8(StartAddress))  = \
                                                           FLSLOADER_VALUE_50;

  InnerCount = 0U;
  while((FLASH0_FSR.B.ERASE != FLSLOADER_BIT_SET) &&\
         (InnerCount < FLSLOADER_CMDCYCLE_TIMEOUT))
  {
    InnerCount++;
  }

 while((FLASH0_FSR.U & FLSLOADER_NUM_2) != 0U)
 {
 }

  /* This check makes sure that  erase operation is requested,
     No protection error and no sequence error has occurred. */

  /* Enter Critical Section */
  FlsLoader_lEnableInts(Icr);

  /* This check makes sure No protection error and no sequence error
  and No operation error has occurred.*/
  RetError = FlsLoader_lProtSeqOperErrorCheck();

  if (RetError == (FlsLoader_ReturnType)FLSLOADER_E_OK)
  {
  /* Clear the status if the operation is successful.*/
   *((FlsLoader_AddressType*)FlsLoader_lClearStatus(StartAddress)) = \
                                                           FLSLOADER_VALUE_FA;
  }

  /* Erase is completed now program 16 pages of UCB in Page mode. */
  if (RetError == (FlsLoader_ReturnType)FLSLOADER_E_OK)
  {

         /* Enter Critical Section */
        Icr = FlsLoader_lDisableInts();

        for (Count = 0U; Count < FLSLOADER_NUM_UCB_PAGES; Count++)
        {

          /* Enter the Page Mode */
          *((FlsLoader_AddressType*)FlsLoader_lEnterPageMode(StartAddress)) =
                                               FLSLOADER_DFLASH_VAL;
          InCount = 0U;
          /* Check if Program Flash is in page mode */
          while((FLASH0_FSR.B.DFPAGE != FLSLOADER_BIT_SET) && \
                (InCount < FLSLOADER_CMDCYCLE_TIMEOUT))
          {
            InCount++;
          }

          /* Check PFPAGE/DFPAGE bit was SET */
          if(InCount < FLSLOADER_CMDCYCLE_TIMEOUT)
          {

              /* Load the data */
              *((FlashLoader_DataType*) FlsLoader_lLoadPage(StartAddress))
                                        = *PdataPtr;
              PdataPtr++;
              /* Load Page register gets incremented automatically. */
            /* cycle 1 */
            *((FlsLoader_AddressType*)FLSLOADER_GET_CYCLE_AA50(StartAddress))
                                         = UcbSectorAddress;
            /* cycle 2 */
            *((FlsLoader_AddressType*)FLSLOADER_GET_CYCLE_AA58(StartAddress))
                                         =  FLSLOADER_VALUE_00;
            /* cycle 3 */
            *((FlsLoader_AddressType*)FLSLOADER_GET_CYCLE_AAA8(StartAddress))
                                         =  FLSLOADER_VALUE_A0;
            /*cycle 4 */
            *((FlsLoader_AddressType*)FLSLOADER_GET_CYCLE_AAA8(StartAddress))
                                         = FLSLOADER_VALUE_AA;

            InCount = 0U;
            while((FLASH0_FSR.B.PROG != FLSLOADER_BIT_SET) &&\
   (InCount < FLSLOADER_CMDCYCLE_TIMEOUT))
            {
              InCount++;
            }

            InCount = 0U;
            while(((FLASH0_FSR.U & FLSLOADER_NUM_2) != 0U) &&
                  (InCount < FLSLOADER_CMDCYCLE_TIMEOUT))
              {
                InCount++;
              }


            /* This check makes sure No protection error and no sequence error
            and No operation error has occurred.*/
            RetError = FlsLoader_lProtSeqOperErrorCheck();

            if (RetError == (FlsLoader_ReturnType)FLSLOADER_E_OK)
            {
              /* Clear the status if the operation is successful.*/
              *((FlsLoader_AddressType*)FlsLoader_lClearStatus(StartAddress))
                                                        =  FLSLOADER_VALUE_FA;
              /* Iterate the TargetAddress to the next page Address */
              UcbSectorAddress = UcbSectorAddress + FLSLOADER_PAGE_SIZE;
           } /* End of FlsLoader_lErrorCheck */
          }  /* End of InCount < FLSLOADER_CMDCYCLE_TIMEOUT*/
         }  /* End of For Loop */
                     /* Exit Crtical Section */
         FlsLoader_lEnableInts(Icr);
  }
  return(RetError);
}

#endif
   /* #if (FLSLOADER_LOCK_UNLOCK_API == STD_ON)*/

/*******************************************************************************
** Syntax           :  FlsLoader_ReturnType  FlsLoader_lCheckSectorProt(      **
**                      uint32 TargetAddress ,Length                          **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : TargetAddress: PFLASHx Target address                   **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : SectorNumber                                            **
**                                                                            **
** Description      : This function will retrun if the sector is protected    **
*******************************************************************************/
FlsLoader_ReturnType FlsLoader_lCheckSectorProt(uint32 TargetAddress,
                                   FlsLoader_LengthType Length )
{
  FlsLoader_ReturnType RetError;
  uint32  SectorNumber;
  uint32 Offset;
  uint16 PfSegment;
  uint8  FlashType;


  PfSegment = (uint16)(TargetAddress >> FLSLOADER_SHIFT_BY_20);
  /*   Compute Sector Number from the TargetAddress */
  if ((PfSegment == (uint16)FLSLOADER_PF0_SEGMENT_0)||
      (PfSegment == (uint16)FLSLOADER_PF0_SEGMENT_1))
  {
    FlashType = (uint8)FLSLOADER_PFLASH_BANK0;
    Offset = TargetAddress - FLSLOADER_PFLASH0_START_ADDRESS;
    SectorNumber = FlsLoader_lSectorNumber(Offset);
    /* Check if any of the 26 sectors of PF0 are locked for
    write/OTP/WOP protection */
    RetError =
    FlsLoader_lSectorProtCheck((uint32)FlashType, SectorNumber, Length);

  } /* PFLASH0 */
  else
  if ((PfSegment == (uint16)FLSLOADER_PF1_SEGMENT_0)||
      (PfSegment == (uint16)FLSLOADER_PF1_SEGMENT_1))
  {
    FlashType = (uint8)FLSLOADER_PFLASH_BANK1;
    Offset = TargetAddress - FLSLOADER_PFLASH1_START_ADDRESS;
    SectorNumber = FlsLoader_lSectorNumber(Offset);
    /* Check if any of the 26 sectors of PF1 are locked for
     write/OTP/WOP protection */
    RetError =
    FlsLoader_lSectorProtCheck((uint32)FlashType, SectorNumber, Length);
  } /* PFLASH1 */
  else
  if ((PfSegment == (uint16)FLSLOADER_PF2_SEGMENT_0)||
      (PfSegment == (uint16)FLSLOADER_PF2_SEGMENT_1))
  {
    FlashType = (uint8)FLSLOADER_PFLASH_BANK2;
    Offset = TargetAddress - FLSLOADER_PFLASH2_START_ADDRESS;
    SectorNumber = FlsLoader_lSectorNumber(Offset);
    /* Check if any of the 26 sectors of PF1 are locked for
     write/OTP/WOP protection */
    RetError =
    FlsLoader_lSectorProtCheck((uint32)FlashType, SectorNumber, Length);
  } /* PFLASH2 */
  else
  {
    FlashType = (uint8)FLSLOADER_PFLASH_BANK3;
    Offset = TargetAddress - FLSLOADER_PFLASH3_START_ADDRESS;
    SectorNumber = FlsLoader_lSectorNumber(Offset);
    /* Check if any of the 26 sectors of PF1 are locked for
     write/OTP/WOP protection */
    RetError =
    FlsLoader_lSectorProtCheck((uint32)FlashType, SectorNumber, Length);
  } /* PFLASH3 */

  return RetError;

}

/*******************************************************************************
** Syntax           :  uint32  FlsLoader_lSectorNumber(                       **
**                      uint32 Offset                                         **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : offset: PFLASH0/1 Offset address                        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : SectorNumber                                            **
**                                                                            **
** Description      : This function will retrun the sector number             **
*******************************************************************************/
static _INLINE_ uint32 FlsLoader_lSectorNumber(uint32 Offset)
{
  uint32 SectorNumber;

  SectorNumber = FLSLOADER_INV;
  switch (Offset)
  {
    case FLSLOADER_PF_S0 :
                           SectorNumber = FLSLOADER_S0;
                           break;
    case FLSLOADER_PF_S1 :
                           SectorNumber = FLSLOADER_S1;
                           break;
    case FLSLOADER_PF_S2 :
                           SectorNumber = FLSLOADER_S2;
                           break;
    case FLSLOADER_PF_S3 :
                           SectorNumber = FLSLOADER_S3;
                           break;
    case FLSLOADER_PF_S4 :
                           SectorNumber = FLSLOADER_S4;
                           break;
    case FLSLOADER_PF_S5 :
                           SectorNumber = FLSLOADER_S5;
                           break;
    case FLSLOADER_PF_S6 :
                           SectorNumber = FLSLOADER_S6;
                           break;
    case FLSLOADER_PF_S7 :
                           SectorNumber = FLSLOADER_S7;
                           break;
    case FLSLOADER_PF_S8 :
                           SectorNumber = FLSLOADER_S8;
                           break;
    case FLSLOADER_PF_S9 :
                           SectorNumber = FLSLOADER_S9;
                           break;
    case FLSLOADER_PF_S10:
                           SectorNumber = FLSLOADER_S10;
                           break;
    case FLSLOADER_PF_S11:
                           SectorNumber = FLSLOADER_S11;
                           break;
    case FLSLOADER_PF_S12:
                           SectorNumber = FLSLOADER_S12;
                           break;
    case FLSLOADER_PF_S13:
                           SectorNumber = FLSLOADER_S13;
                           break;
    case FLSLOADER_PF_S14:
                           SectorNumber = FLSLOADER_S14;
                           break;
    case FLSLOADER_PF_S15:
                           SectorNumber = FLSLOADER_S15;
                           break;
    case FLSLOADER_PF_S16:
                           SectorNumber = FLSLOADER_S16;
                           break;
    case FLSLOADER_PF_S17:
                           SectorNumber = FLSLOADER_S17;
                           break;
    case FLSLOADER_PF_S18:
                           SectorNumber = FLSLOADER_S18;
                           break;
    case FLSLOADER_PF_S19:
                           SectorNumber = FLSLOADER_S19;
                           break;
    case FLSLOADER_PF_S20:
                           SectorNumber = FLSLOADER_S20;
                           break;
    case FLSLOADER_PF_S21:
                           SectorNumber = FLSLOADER_S21;
                           break;
    case FLSLOADER_PF_S22:
                           SectorNumber = FLSLOADER_S22;
                           break;
    case FLSLOADER_PF_S23:
                           SectorNumber = FLSLOADER_S23;
                           break;
    case FLSLOADER_PF_S24:
                           SectorNumber = FLSLOADER_S24;
                           break;
    case FLSLOADER_PF_S25:
                           SectorNumber = FLSLOADER_S25;
                           break;
    case FLSLOADER_PF_S26:
                           SectorNumber = FLSLOADER_S26;
                           break;
     default:
            break ;
    }

    return (SectorNumber);
}


/*******************************************************************************
** Syntax           :  FlsLoader_ReturnType  FlsLoader_lSectorProtCheck(      **
**                      uint32 FlashType,uint32 SectorNumber,                 **
**                      FlsLoader_LengthType Length )                         **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   :                                                         **
**                    SectorNumber : Sector Number                            **
**                    FlashType : PFLASH0 / PFLASH1                           **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : value: RetError                                         **
**                                                                            **
** Description      : This function returns sector locked or not.             **
*******************************************************************************/
static _INLINE_ FlsLoader_ReturnType FlsLoader_lSectorProtCheck(
                               uint32 FlashType,
                               uint32 SectorNumber,FlsLoader_LengthType Length )
{
  FlsLoader_ReturnType RetError;
  uint32 FlsProcon0;
  uint32 FlsProConP0;
  uint32 FlsProConOTP0;
  uint32 FlsProConWOP0;
  uint32 FlsProConP1;
  uint32 FlsProConOTP1;
  uint32 FlsProConWOP1;
  uint32 FlsProCon1;
  uint32 FlsProConP2;
  uint32 FlsProConOTP2;
  uint32 FlsProConWOP2;
  uint32 FlsProCon2;
  uint32 FlsProConP3;
  uint32 FlsProConOTP3;
  uint32 FlsProConWOP3;
  uint32 FlsProCon3;
  uint8  Shift;

  /* Init RetError to OK */
  RetError = (FlsLoader_ReturnType)FLSLOADER_E_OK;
  FlsProConP0 = 0U;
  FlsProConP1 = 0U;
  FlsProConP2 = 0U;
  FlsProConP3 = 0U;
  if(SectorNumber != FLSLOADER_INV)
  {
  for( Shift = (uint8)SectorNumber; Shift < (SectorNumber + Length); Shift++ )
  {
    if (FlashType == FLSLOADER_PFLASH_BANK0)
    {
      FlsProcon0 = (uint32)((((uint32)FLASH0_PROCONP0.U) >> (Shift))
                   & FLSLOADER_BIT_SET);
      if ((FLASH0_FPRO.B.PRODISP != 1U) && (FlsProcon0 == 1U))
      {
          FlsProConP0 = 1U;
      }
      FlsProConOTP0 = (uint32)((((uint32)FLASH0_PROCONOTP0.U) >> (Shift))
                         & FLSLOADER_BIT_SET);
      FlsProConWOP0 = (uint32)(((((uint32)FLASH0_PROCONWOP0.U) >> (Shift))
                         & FLSLOADER_BIT_SET));
      if((FlsProConP0 != 0U) || (FlsProConOTP0 != 0U) || (FlsProConWOP0 != 0U))
      {
        RetError = (FlsLoader_ReturnType)FLSLOADER_E_LOCKED;
      }
    }
    else
      if (FlashType == FLSLOADER_PFLASH_BANK1)
      {
        FlsProCon1 = (uint32)((((uint32)FLASH0_PROCONP1.U) >> (Shift))
                              & FLSLOADER_BIT_SET);
        if((FLASH0_FPRO.B.PRODISP != 1U) && (FlsProCon1 == 1U))
        {
          FlsProConP1 = 1U;
        }
        FlsProConOTP1 = (uint32)(((((uint32)FLASH0_PROCONOTP1.U) >> (Shift))
                                 & FLSLOADER_BIT_SET));
        FlsProConWOP1 = (uint32)(((((uint32)FLASH0_PROCONWOP1.U) >> (Shift))
                                 & FLSLOADER_BIT_SET));
        if((FlsProConP1 != 0U) || (FlsProConOTP1 != 0U) || (FlsProConWOP1 != 0U))
        {
          RetError = (FlsLoader_ReturnType)FLSLOADER_E_LOCKED;
        }
      }
      else
        if (FlashType == FLSLOADER_PFLASH_BANK2)
        {
          FlsProCon2 = (uint32)((((uint32)FLASH0_PROCONP2.U) >> (Shift))
                                & FLSLOADER_BIT_SET);
          if((FLASH0_FPRO.B.PRODISP != 1U) && (FlsProCon2 == 1U))
          {
            FlsProConP2 = 1U;
          }
          FlsProConOTP2 = (uint32)(((((uint32)FLASH0_PROCONOTP2.U) >> (Shift))
                                   & FLSLOADER_BIT_SET));
          FlsProConWOP2 = (uint32)(((((uint32)FLASH0_PROCONWOP2.U) >> (Shift))
                                   & FLSLOADER_BIT_SET));
          if((FlsProConP2 != 0U) || (FlsProConOTP2 != 0U) ||
             (FlsProConWOP2 != 0U))
          {
            RetError = (FlsLoader_ReturnType)FLSLOADER_E_LOCKED;
          }
        }
        else
          if (FlashType == FLSLOADER_PFLASH_BANK3)
          {
            FlsProCon3 = (uint32)((((uint32)FLASH0_PROCONP3.U) >> (Shift))
                                  & FLSLOADER_BIT_SET);
            if((FLASH0_FPRO.B.PRODISP != 1U) && (FlsProCon3 == 1U))
            {
              FlsProConP3 = 1U;
            }
            FlsProConOTP3 = (uint32)(((((uint32)FLASH0_PROCONOTP3.U) >> (Shift))
                                     & FLSLOADER_BIT_SET));
            FlsProConWOP3 = (uint32)(((((uint32)FLASH0_PROCONWOP3.U) >> (Shift))
                                     & FLSLOADER_BIT_SET));
            if((FlsProConP3 != 0U) || (FlsProConOTP3 != 0U) ||
               (FlsProConWOP3 != 0U))
            {
              RetError = (FlsLoader_ReturnType)FLSLOADER_E_LOCKED;
            }
          }
          else
            {
              /*MISRA warning*/
            }
   }
 }
 else
 {
   RetError = (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
  }
  return (RetError);
}

#if (FLSLOADER_DEV_ERROR_DETECT == STD_ON)
/*******************************************************************************
** Syntax           :  FlsLoader_ReturnType FlsLoader_lWriteDetCheck(         **
**                      FlsLoader_LengthType Length,                          **
**                      FlsLoader_AddressType TargetAddress                   **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Length :Length of the data                              **
**                    TargetAddress :Destination Address in Flash             **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : RetError                                                **
**                                                                            **
** Description      : This function is DET Check function for                 **
**                    FlsLoader_lWrite                                   **
*******************************************************************************/

FlsLoader_ReturnType FlsLoader_lWriteDetCheck(
                                           FlsLoader_LengthType Length,
                                           FlsLoader_AddressType TargetAddress)
{
  uint8                     ErrorHook;
  FlsLoader_ReturnType      RetError;
  uint32                    NibbleValue;
  FlsLoader_AddressType TargetEndAddress;
  uint32 Fls0FsrCheck;
  /* Init RetError to OK */
  RetError = (FlsLoader_ReturnType)FLSLOADER_E_OK;

  /* check for Init DET */
  if (FlsLoader_InitStatus != FLSLOADER_INITIALIZED)
  {
    /* CD_FlsLoader034 :Report missing initialization DET */
    Det_ReportError(
                    (uint16)FLSLOADER_MODULE_ID,
                     FLSLOADER_INSTANCE_ID,
                     FLSLOADER_SID_WRITE,
                     FLSLOADER_E_UNINIT);
    RetError = (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
  }
  /* Check of TargetAddress
     TargetAddress can be multiple of 256 bytes in caseof PFLASH or 32 bytes.
     incase of DFLASH. */
  /* Report Invalid TargetAddress to DET */

  if ( RetError != (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK)
  {
    ErrorHook = FlsLoader_lAddressPageCheck(TargetAddress);
    if  (0U == ErrorHook)
    {
      Det_ReportError(
                      (uint16)FLSLOADER_MODULE_ID,
                       FLSLOADER_INSTANCE_ID,
                       FLSLOADER_SID_WRITE,
                       FLSLOADER_E_PARAM_ADDRESS);
      RetError = (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
    }
  }

  if ( RetError != (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK)
  {
    /* Returns true if, position is DFLASH address */
    if (FlsLoader_lCheckFlashType(TargetAddress))
    {
      /* Given TargetAddress and Length should not exceed the flash boundary */
      /* Its Data Flash assign,
      Report invalid Length to DET */
       if (FlsLoader_lDFlashPageCheck(TargetAddress,Length))
       {
         Det_ReportError(
                        (uint16)FLSLOADER_MODULE_ID,
                         FLSLOADER_INSTANCE_ID,
                         FLSLOADER_SID_WRITE,
                         FLSLOADER_E_PARAM_LENGTH);
         RetError = (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
       }
    }
    else /*PFlash*/
    {
      NibbleValue = (TargetAddress >> FLSLOADER_SHIFT_BY_20)
                    & FLSLOADER_PFLASH_MASK;
      TargetEndAddress = ((FlsLoader_LengthType)Length + (TargetAddress &
                      (FlsLoader_AddressType)FLSLOADER_PFLASH_ADDRESS_MASK))-1U;
      if (NibbleValue >= FLSLOADER_NUM_6)
      {
          /*PFLASH3*/
        if ((Length == (FlsLoader_LengthType)0U) ||
           ((Length & ((FlsLoader_LengthType)FLSLOADER_MOD_256)) != 0U) ||
         (TargetEndAddress > (FlsLoader_LengthType)FLSLOADER_PFLASH3_OFFSETEND))
         {
           Det_ReportError(
                          (uint16)FLSLOADER_MODULE_ID,
                           FLSLOADER_INSTANCE_ID,
                           FLSLOADER_SID_WRITE,
                           FLSLOADER_E_PARAM_LENGTH);

           RetError = (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
         }
      }
      else
        if (NibbleValue >= FLSLOADER_NUM_4)
        {
          /*PFLASH2*/
        if ((Length == (FlsLoader_LengthType)0U) ||
           ((Length & ((FlsLoader_LengthType)FLSLOADER_MOD_256)) != 0U) ||
         (TargetEndAddress > (FlsLoader_LengthType)FLSLOADER_PFLASH2_OFFSETEND))
         {
           Det_ReportError(
                          (uint16)FLSLOADER_MODULE_ID,
                           FLSLOADER_INSTANCE_ID,
                           FLSLOADER_SID_WRITE,
                           FLSLOADER_E_PARAM_LENGTH);

           RetError = (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
         }
      }
      else if (NibbleValue >= FLSLOADER_NUM_2)
        {
          /*PFLASH1*/
        if ((Length == (FlsLoader_LengthType)0U) ||
           ((Length & ((FlsLoader_LengthType)FLSLOADER_MOD_256)) != 0U) ||
         (TargetEndAddress > (FlsLoader_LengthType)FLSLOADER_PFLASH1_OFFSETEND))
         {
           Det_ReportError(
                          (uint16)FLSLOADER_MODULE_ID,
                           FLSLOADER_INSTANCE_ID,
                           FLSLOADER_SID_WRITE,
                           FLSLOADER_E_PARAM_LENGTH);

           RetError = (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
         }
      }
      else
      {
        /*PFLASH0*/
       if ((Length == (FlsLoader_LengthType)0U) ||
          ((Length & ((FlsLoader_LengthType)FLSLOADER_MOD_256))!= 0U) ||
         (TargetEndAddress > (FlsLoader_LengthType)FLSLOADER_PFLASH0_OFFSETEND))
        {
          Det_ReportError(
                        (uint16)FLSLOADER_MODULE_ID,
                         FLSLOADER_INSTANCE_ID,
                         FLSLOADER_SID_WRITE,
                         FLSLOADER_E_PARAM_LENGTH);

          RetError = (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
       }
      }
    }
  }

  if (RetError != (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK)
  {
    /* Check for Busy state of FLASH Registers differ between Checking of
       Busy state of PFlash and DFlash */
 /* Check for Flash Busy*/
 #ifdef IFX_FLSLOADER_DEBUG
  Fls0FsrCheck = ((FLASH0_FSR.U & ((uint32)FLSLOADER_FLASH_BUSY_MASK))
                      | TestFlsloader_DebugMask01);
#else /*#ifdef IFX_FLSLOADER_DEBUG*/
  Fls0FsrCheck = (FLASH0_FSR.U & ((uint32)FLSLOADER_FLASH_BUSY_MASK));
#endif  /*#ifdef IFX_FLSLOADER_DEBUG*/
  if( Fls0FsrCheck )
     {
      #if (FLSLOADER_DEV_ERROR_DETECT == STD_ON)
      /* Report FLSLOADER_E_BUSY to DET */
      Det_ReportError(
                     (uint16)FLSLOADER_MODULE_ID,
                      FLSLOADER_INSTANCE_ID,
                      FLSLOADER_SID_WRITE,
                      FLSLOADER_E_BUSY);
      #endif
      RetError = (FlsLoader_ReturnType)FLSLOADER_E_BUSY;
    }
  }
  return (RetError);
}

/*******************************************************************************
** Syntax           :  FlsLoader_ReturnType FlsLoader_lEraseDetCheck(         **
**                      FlsLoader_LengthType Length,                          **
**                      FlsLoader_AddressType TargetAddress                   **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Length :Length of the data                              **
**                    TargetAddress :Destination Address in Flash             **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : RetError                                                **
**                                                                            **
** Description      : This function is DET Check  for FlsLoader_Erase    **
*******************************************************************************/
FlsLoader_ReturnType FlsLoader_lEraseDetCheck(
                                      FlsLoader_LengthType Length,
                                      FlsLoader_AddressType TargetAddress)
{
  FlsLoader_ReturnType RetError;
  uint32               TempAddr;
  uint16               PfSegment;
  uint32               Offset;

  RetError = FLSLOADER_E_OK;
  if (FlsLoader_InitStatus != FLSLOADER_INITIALIZED)
  {
    /* CD_FlsLoader039: Report missing initilization to DET */
    Det_ReportError(
                   (uint16)FLSLOADER_MODULE_ID,
                           FLSLOADER_INSTANCE_ID,
                           FLSLOADER_SID_ERASE,
                           FLSLOADER_E_UNINIT
                  );

    RetError = (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
  }
  else
  {
      /* CD_FlsLoader041: Report invalid TargetAddress to DET */
      if (FlsLoader_lCheckFlashType(TargetAddress))
      { /* Check for DFLASH Address*/
        if ((TargetAddress & 1U) != 0U)
        {
          Det_ReportError((uint16)FLSLOADER_MODULE_ID,
                     FLSLOADER_INSTANCE_ID,
                     FLSLOADER_SID_ERASE,
                     FLSLOADER_E_PARAM_ADDRESS);
          RetError = (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
        }


        TempAddr = ((TargetAddress >> FLSLOADER_SHIFT_BY_12)
                    & FLSLOADER_ADDRESS_HI_5_MASK);
        if ((TempAddr & 1U) == 1U)
        {
          Det_ReportError((uint16)FLSLOADER_MODULE_ID,
                     FLSLOADER_INSTANCE_ID,
                     FLSLOADER_SID_ERASE,
                     FLSLOADER_E_PARAM_ADDRESS);
          RetError = (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
        }

        if (RetError != (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK)
        {
          if ((Length == 0U)||(Length > (uint32)FLSLOADER_NUM_OF_DF_SECTORS))
          {
            Det_ReportError((uint16)FLSLOADER_MODULE_ID,
                     FLSLOADER_INSTANCE_ID,
                     FLSLOADER_SID_ERASE,
                     FLSLOADER_E_PARAM_LENGTH);
            RetError = (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
          }
        }
      }
      else
      {
        /* Check for PFLASH Address.*/
        PfSegment = (uint16)(TargetAddress >> FLSLOADER_SHIFT_BY_20);
        if (( PfSegment != FLSLOADER_PF0_SEGMENT_0 )&&
            ( PfSegment != FLSLOADER_PF0_SEGMENT_1 )&&
            ( PfSegment != FLSLOADER_PF1_SEGMENT_0 )&&
            ( PfSegment != FLSLOADER_PF1_SEGMENT_1 )&&
            ( PfSegment != FLSLOADER_PF2_SEGMENT_0 )&&
            ( PfSegment != FLSLOADER_PF2_SEGMENT_1 )&&
            ( PfSegment != FLSLOADER_PF3_SEGMENT_0 )&&
            ( PfSegment != FLSLOADER_PF3_SEGMENT_1 ))
        {
           Det_ReportError((uint16)FLSLOADER_MODULE_ID,
                     FLSLOADER_INSTANCE_ID,
                     FLSLOADER_SID_ERASE,
                     FLSLOADER_E_PARAM_ADDRESS);
           RetError = (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
        }
        else
        {
          if (( PfSegment == FLSLOADER_PF0_SEGMENT_0 )||
              ( PfSegment == FLSLOADER_PF0_SEGMENT_1 ))
          {
            Offset = TargetAddress - FLSLOADER_PFLASH0_START_ADDRESS;
          }
          else
            if (( PfSegment == FLSLOADER_PF1_SEGMENT_0 )||
               (PfSegment == FLSLOADER_PF1_SEGMENT_1 ))
            {
              Offset = TargetAddress - FLSLOADER_PFLASH1_START_ADDRESS;
            }
            else
               if (( PfSegment == FLSLOADER_PF2_SEGMENT_0 )||
                   (PfSegment == FLSLOADER_PF2_SEGMENT_1 ))
               {
                 Offset = TargetAddress - FLSLOADER_PFLASH2_START_ADDRESS;
               }
               else
               {
                 Offset = TargetAddress - FLSLOADER_PFLASH3_START_ADDRESS;
               }

        if ((Offset!= FLSLOADER_PF_S0) && (Offset != FLSLOADER_PF_S1)
          &&(Offset!= FLSLOADER_PF_S2) && (Offset != FLSLOADER_PF_S3)
          &&(Offset!= FLSLOADER_PF_S4) && (Offset != FLSLOADER_PF_S5)
          &&(Offset!= FLSLOADER_PF_S6) && (Offset != FLSLOADER_PF_S7)
          &&(Offset!= FLSLOADER_PF_S8) && (Offset != FLSLOADER_PF_S9)
          &&(Offset!= FLSLOADER_PF_S10) && (Offset != FLSLOADER_PF_S11)
          &&(Offset!= FLSLOADER_PF_S12) && (Offset != FLSLOADER_PF_S13)
          &&(Offset!= FLSLOADER_PF_S14) && (Offset != FLSLOADER_PF_S15)
          &&(Offset!= FLSLOADER_PF_S16) && (Offset != FLSLOADER_PF_S17)
          &&(Offset!= FLSLOADER_PF_S18) && (Offset != FLSLOADER_PF_S19)
          &&(Offset!= FLSLOADER_PF_S20) && (Offset != FLSLOADER_PF_S21)
          &&(Offset!= FLSLOADER_PF_S22) && (Offset != FLSLOADER_PF_S23)
          &&(Offset!= FLSLOADER_PF_S24) && (Offset != FLSLOADER_PF_S25)
          &&(Offset!= FLSLOADER_PF_S26))
        {
          Det_ReportError((uint16)FLSLOADER_MODULE_ID,
                     FLSLOADER_INSTANCE_ID,
                     FLSLOADER_SID_ERASE,
                     FLSLOADER_E_PARAM_ADDRESS);
          RetError = (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
        }
        if (RetError != (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK)
        {
          if ((Length == 0U)||(Length > FLSLOADER_NUM_OF_PF0_SECTORS))
          {
            Det_ReportError((uint16)FLSLOADER_MODULE_ID,
                     FLSLOADER_INSTANCE_ID,
                     FLSLOADER_SID_ERASE,
                     FLSLOADER_E_PARAM_LENGTH);
            RetError = (FlsLoader_ReturnType)FLSLOADER_E_NOT_OK;
          }
        }
      }
    } /* end of if check FlashType */
  }
  return (RetError);
}


/*******************************************************************************
** Syntax           :  uint8   FlsLoader_lAddressPageCheck(                   **
**                      FlsLoader_AddressType TargetAddress                   **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : TargetAddress : Address passed                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : value: ErrorHook                                        **
**                                                                            **
** Description      : This function returns the give TargetAddress last two   **
**                    nibbles are zero value                                  **
*******************************************************************************/
static _INLINE_ uint8 FlsLoader_lAddressPageCheck(
                                           FlsLoader_AddressType TargetAddress)
{
  uint8     RetVal;
  /* Init ErrorHook to false */
  RetVal = 0U;
  /* Check of TargetAddress
     TargetAddress can be multiple of 256 bytes or 32 bytes. */
  /* CD_FlsLoader036 :Report Invalid TargetAddress to DET */
    if (FlsLoader_lPFlashCheck(TargetAddress))
    {
      /* First byte is already checked, last two nibbles must be zero.*/
      if ((TargetAddress & (FlsLoader_AddressType)FLSLOADER_MOD_256) == \
                                                          FLSLOADER_POSITION_0 )
      {
        RetVal = 1U; /* valid sector Address */
      }
    }
    else
    {
      if (FlsLoader_lDFlashCheck(TargetAddress))
      {
        if ( (TargetAddress & (FlsLoader_AddressType)FLSLOADER_MOD_32) == \
                                                          FLSLOADER_POSITION_0 )
        {
          RetVal = 1U;
        }
      }
    } /* end of if TargetAddress check */

  return (RetVal);
}

#endif /* #if (FLSLOADER_DEV_ERROR_DETECT == STD_ON) */


#define FLSLOADER_STOP_SEC_CODE
#include "MemMap.h"