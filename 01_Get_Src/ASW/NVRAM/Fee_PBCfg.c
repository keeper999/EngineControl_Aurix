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
**  $FILENAME   : Fee_PBCfg.c $                                              **
**                                                                           **
**  $CC VERSION : \main\14 $                                                 **
**                                                                           **
**  DATE, TIME: 2014-09-19, 14:17:23                                         **
**                                                                           **
**  GENERATOR : Build b131017-0205                                           **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : FEE configuration generated out of ECU configuration      **
**                   file (Fee.bmd)                                          **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include Fee Module Header File */
#include "Fee.h"

/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/* Allocate space for state data variables in RAM */
#define FEE_START_SEC_VAR_FAST_UNSPECIFIED
#include "MemMap.h"

/* Fee State Variable structure */
static Fee_StateDataType Fee_StateVar;

#define FEE_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "MemMap.h"


/* User configured logical block initialization structure */
#define FEE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

static const Fee_BlockType Fee_BlockConfig[] =
{
  {
    100000U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    2U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    100000U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    3U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    4U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    6U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    8U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    10U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    12U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    14U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    16U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    18U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    20U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    22U, /* Block number */
    32U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    24U, /* Block number */
    32U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    26U, /* Block number */
    32U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    28U, /* Block number */
    32U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    30U, /* Block number */
    32U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    32U, /* Block number */
    32U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    34U, /* Block number */
    32U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    36U, /* Block number */
    32U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    38U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    40U, /* Block number */
    128U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    42U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    43U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    44U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    45U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    46U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    47U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    48U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    50U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    52U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    54U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    56U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    58U, /* Block number */
    24U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    60U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    62U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    64U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    66U, /* Block number */
    24U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    68U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    70U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    72U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    74U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    76U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    78U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    80U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    82U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    84U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    86U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    88U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    90U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    92U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    94U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    96U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    98U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    100U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    102U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    104U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    106U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    108U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    110U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    112U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    114U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    116U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    118U, /* Block number */
    56U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    120U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    122U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    124U, /* Block number */
    24U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    126U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    128U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    130U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    132U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    134U, /* Block number */
    736U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    136U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    138U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    140U, /* Block number */
    96U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    142U, /* Block number */
    2944U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    144U, /* Block number */
    408U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    146U, /* Block number */
    168U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    148U, /* Block number */
    168U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    150U, /* Block number */
    168U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    152U, /* Block number */
    168U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    154U, /* Block number */
    168U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    156U, /* Block number */
    168U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    158U, /* Block number */
    168U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    160U, /* Block number */
    168U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    162U, /* Block number */
    168U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    164U, /* Block number */
    168U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    166U, /* Block number */
    88U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    168U, /* Block number */
    88U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    170U, /* Block number */
    88U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    172U, /* Block number */
    88U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    174U, /* Block number */
    88U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    176U, /* Block number */
    48U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    178U, /* Block number */
    48U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    180U, /* Block number */
    24U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    182U, /* Block number */
    744U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    184U, /* Block number */
    88U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    186U, /* Block number */
    88U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    188U, /* Block number */
    88U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    190U, /* Block number */
    88U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    192U, /* Block number */
    88U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    194U, /* Block number */
    88U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    196U, /* Block number */
    88U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    198U, /* Block number */
    88U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    200U, /* Block number */
    88U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    202U, /* Block number */
    48U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    204U, /* Block number */
    48U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    206U, /* Block number */
    48U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    208U, /* Block number */
    88U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    210U, /* Block number */
    48U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    212U, /* Block number */
    48U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    214U, /* Block number */
    88U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    216U, /* Block number */
    48U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    218U, /* Block number */
    88U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    220U, /* Block number */
    168U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    222U, /* Block number */
    88U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    224U, /* Block number */
    48U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    226U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    228U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    230U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    232U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    234U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    236U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    238U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    240U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    242U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    244U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    246U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    248U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    250U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    252U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    254U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    256U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    258U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    260U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    262U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    264U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    266U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    268U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    270U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    272U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    274U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    276U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    278U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    280U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    282U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    284U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    286U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    288U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    290U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    292U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    294U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    296U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    298U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    300U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    302U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    304U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    306U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    308U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    310U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    312U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    314U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    316U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    318U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    320U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    322U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    324U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    326U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    328U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    330U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    332U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    334U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    336U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    338U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    340U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    342U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    344U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    346U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    348U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    350U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    352U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    354U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    356U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    358U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    360U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    362U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    364U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    366U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    368U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    370U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    372U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    374U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    376U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    378U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    380U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    382U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    384U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    386U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    388U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    390U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    392U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    394U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    396U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    398U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    400U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    402U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    404U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    406U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    408U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    410U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    412U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    414U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    416U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    418U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    420U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    422U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    424U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    426U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    428U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    430U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    432U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    434U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    436U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    438U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    440U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    442U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    444U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    446U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    448U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    450U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    452U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    454U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    456U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    458U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    460U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    462U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    464U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    466U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    468U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    470U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    472U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    474U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    476U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    478U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    480U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    482U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    484U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    486U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    488U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    490U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    492U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    494U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    496U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    498U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    500U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    502U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    504U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    506U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    508U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    510U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    512U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    514U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    516U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    518U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    520U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    522U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    524U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    526U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    528U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    530U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    532U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    534U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    536U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    538U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    540U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    542U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    544U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    546U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    548U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    550U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    552U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    554U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    556U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    558U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    560U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    562U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    564U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    566U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    568U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    570U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    572U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    574U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    576U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    578U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    580U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    582U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    584U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    586U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    588U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    590U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    592U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    594U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    596U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    598U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    600U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    602U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    604U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    606U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    608U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    610U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    612U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    614U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    616U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    618U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    620U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    622U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    624U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    626U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    628U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    630U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    632U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    634U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    636U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    638U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    640U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    642U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    644U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    646U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    648U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    650U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    652U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    654U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    656U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    658U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    660U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    662U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    664U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    666U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    668U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    670U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    672U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    674U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    676U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    678U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    680U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    682U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    684U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    686U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    688U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    690U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    692U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    694U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    696U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    698U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    700U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    702U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    704U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    706U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    708U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    710U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    712U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    714U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    716U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    718U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    720U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    722U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    724U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    726U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    728U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    730U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    732U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    734U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    736U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    738U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    740U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    742U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    744U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    746U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    748U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    750U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    752U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    754U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    756U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    758U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    760U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    762U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    764U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    766U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    768U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    770U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    772U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    774U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    776U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    778U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    780U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    782U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    784U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    786U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    788U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    790U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    792U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    794U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    796U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    798U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    800U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    802U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    804U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    806U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    808U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    810U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    812U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    814U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    816U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    818U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    820U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    822U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    824U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    826U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    828U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    830U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    832U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    834U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    836U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    838U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    840U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    842U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    844U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    846U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    848U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    850U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    852U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    854U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    856U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    858U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    860U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    862U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    864U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    866U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    868U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    870U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    872U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    874U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    876U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    878U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    880U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    882U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    884U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    886U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    888U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    890U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    892U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    894U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    896U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    898U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    900U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    902U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    904U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    906U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    908U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    910U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    912U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    914U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    916U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    918U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    920U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    922U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    924U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    926U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    928U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    930U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    932U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    934U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    936U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    938U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    940U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    942U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    944U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    946U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    948U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    950U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    952U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    954U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    956U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    958U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    960U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    962U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    964U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    966U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    968U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    970U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    972U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    974U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    976U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    978U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    980U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    982U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    984U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    986U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    988U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    990U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    992U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    994U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    996U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    998U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1000U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1002U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1004U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1006U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1008U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1010U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1012U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1014U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1016U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1018U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1020U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1022U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1024U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1026U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1028U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1030U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1032U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1034U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1036U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1038U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1040U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1042U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1044U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1046U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1048U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1050U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1052U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1054U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1056U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1058U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1060U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1062U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1064U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1066U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1068U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1070U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1072U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1074U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1076U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1078U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1080U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1082U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1084U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1086U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1088U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1090U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1092U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1094U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1096U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1098U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1100U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1102U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1104U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1106U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1108U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1110U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1112U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1114U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1116U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1118U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1120U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1122U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1124U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1126U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1128U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1130U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1132U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1134U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1136U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1138U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1140U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1142U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1144U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1146U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1148U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1150U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1152U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1154U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1156U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1158U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1160U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1162U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1164U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1166U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1168U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1170U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1172U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1174U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1176U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1178U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1180U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1182U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1184U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1186U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1188U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1190U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1192U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1194U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1196U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1198U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1200U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1202U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1204U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1206U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1208U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1210U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1212U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1214U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1216U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1218U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1220U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1222U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1224U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1226U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1228U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1230U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1232U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1234U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1236U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1238U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1240U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1242U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1244U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1246U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1248U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1250U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1252U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1254U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1256U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1258U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1260U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1262U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1264U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1266U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1268U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1270U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1272U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1274U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1276U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1278U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1280U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1282U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1284U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1286U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1288U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1290U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1292U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1294U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1296U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1298U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1300U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1302U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1304U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1306U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1308U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1310U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1312U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1314U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1316U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1318U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1320U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1322U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1324U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1326U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1328U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1330U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1332U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1334U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1336U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1338U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1340U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1342U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1344U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1346U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1348U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1350U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1352U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1354U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1356U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1358U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1360U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1362U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1364U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1366U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1368U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1370U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1372U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1374U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1376U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1378U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1380U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1382U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1384U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1386U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1388U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1390U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1392U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1394U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1396U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1398U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1400U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1402U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1404U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1406U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1408U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1410U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1412U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1414U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1416U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1418U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1420U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1422U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1424U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1426U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1428U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1430U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1432U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1434U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1436U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1438U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1440U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1442U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1444U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1446U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1448U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1450U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1452U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1454U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1456U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1458U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1460U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1462U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1464U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1466U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1468U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1470U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1472U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1474U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1476U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1478U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1480U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1482U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1484U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1486U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1488U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1490U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1492U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1494U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1496U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1498U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1500U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1502U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1504U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1506U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1508U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1510U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1512U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1514U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1516U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1518U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1520U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1522U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1524U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1526U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1528U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1530U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1532U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1534U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1536U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1538U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1540U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1542U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1544U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1546U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1548U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1550U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1552U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1554U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1556U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1558U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1560U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1562U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1564U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1566U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1568U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1570U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1572U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1574U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1576U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1578U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1580U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1582U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1584U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1586U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1588U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1590U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1592U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1594U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1596U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1598U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1600U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1602U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1604U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1606U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1608U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1610U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1612U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1614U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1616U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1618U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1620U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1622U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1624U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1626U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1628U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1630U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1632U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1634U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1636U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1638U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1640U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1642U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1644U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1646U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1648U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1650U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1652U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1654U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1656U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1658U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1660U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1662U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1664U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1666U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1668U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1670U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1672U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1674U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1676U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1678U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1680U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1682U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1684U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1686U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1688U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1690U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1692U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1694U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1696U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1698U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1700U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1702U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1704U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1706U, /* Block number */
    344U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1708U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1710U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1712U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1714U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1716U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1718U, /* Block number */
    48U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1720U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1722U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1724U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1726U, /* Block number */
    32U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1728U, /* Block number */
    32U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1730U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1732U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1734U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1736U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1738U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1740U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1742U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1744U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1746U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1748U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1750U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1752U, /* Block number */
    40U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1754U, /* Block number */
    32U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1756U, /* Block number */
    48U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1758U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1760U, /* Block number */
    24U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1762U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1764U, /* Block number */
    88U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1766U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1768U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1770U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1772U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1774U, /* Block number */
    32U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1776U, /* Block number */
    24U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1778U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1780U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1782U, /* Block number */
    40U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1784U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1786U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1788U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1790U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1792U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1794U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1796U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1798U, /* Block number */
    128U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1800U, /* Block number */
    8U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1802U, /* Block number */
    16U /* Fee Block Size */
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
    1804U, /* Block number */
    8U /* Fee Block Size */
  }
};

/* Fee Global initialization structure. */
static const Fee_ConfigType Fee_ConfigRoot[] =
{
  {
    /* Fee State Data Structure */
    &Fee_StateVar,
    /* Pointer to logical block configurations */
    (Fee_BlockType *)(void *)&Fee_BlockConfig,
    /* Fee Job end notification API */
    &NvM_JobEndNotification,
    /* Fee Job error notification API */
    &NvM_JobErrorNotification,
    /* Fee threshold value */
    200U,
    /* Number of blocks configured */
    906U,

    {
       /* Ignore the unconfigured blocks */
       FEE_UNCONFIG_BLOCK_IGNORE,
       /* Restart Garbage Collection during initialization */
       FEE_GC_RESTART_INIT,
       /* Erase Suspend feature is enabled */
       FEE_ERASE_SUSPEND_ENABLED,
       /* Reserved */
       0U
    },

    /* Fee Illegal State notification */
    (Fee_NotifFunctionPtrType)NULL_PTR,
    /* Erase All feature is disabled */
    (boolean)FALSE
  }
};

#define FEE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define FEE_START_SEC_SPL_VAR_32BIT
#include "MemMap.h"
Fee_ConfigPtrType Fee_CfgPtr = (Fee_ConfigPtrType)(void *)&Fee_ConfigRoot[0];
#define FEE_STOP_SEC_SPL_VAR_32BIT
#include "MemMap.h"

