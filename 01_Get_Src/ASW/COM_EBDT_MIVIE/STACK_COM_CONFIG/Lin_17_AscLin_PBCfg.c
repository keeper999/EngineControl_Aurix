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
**  FILENAME  : Lin_17_AscLin_PBCfg.c                                         **
**                                                                            **
**  $CC VERSION : \main\29 $                                                 **
**                                                                            **
**  DATE, TIME: 2014-09-30, 16:07:51                                          **
**                                                                            **
**  GENERATOR : Build b131017-0205                                            **
**                                                                            **
**  MODULE DECRIPTION : Lin_17_AscLin.bmd/.xdm                                **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Lin configuration generated out of ECU configuration       **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_LIN_Driver, Release 4.0.3                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
  TRACEABILITY : [cover parentID= DS_NAS_PR446
] [/cover]      
*******************************************************************************/
/*******************************************************************************
**                            Includes                                        **
*******************************************************************************/

/* Include LIN Module File */
#include "Lin_17_AscLin.h"
    
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/* MISRA RULE 87 VIOLATION: Inclusion of MemMap.h in between the code can't 
   be avoided as it is required for mapping global variables, constants 
   and code
*/ 


/*
                     Container: LinChannelConfiguration
*/
#define LIN_17_ASCLIN_START_SEC_POSTBUILDCFG
/*
 * To be used for global or static constants (unspecified size)
*/
#include "MemMap.h"



/* Lin_Channel: User configured channel initialization structure. */

static const Lin_17_AscLin_ChannelType  Lin_kChannelConfig0[1] = 
{
  /* LIN Channel ID: 0 Configuration */
  {
    /* BaudRate : 9600 Hz  */
    {
       2U,  /* BRG.NUMERATOR value */
       651U,    /* BRG.DENOMINATOR value */
       1U,  /* BITCON.PRESCALAR value */
       0U, /* Inter byte or response space value */
       63U, /* IOCR DEPTH value for wakeup detection */
       234U  /* Prescalar value for wakeup detection */
    },
    0U,          /* EcuM Wakeup Source ID */
    LIN_ASCLIN3,                   /* Hw Module used */
    LIN_CHANNEL_WAKEUP_DISABLED,   /* Wakeup Support */
    /* Wakeup value to be programmed for wakeup generation (250us to 5ms) */
    3U,
    /*Rx alternate pin select */
    0U,
    /* Logical Channel ID configured by user */
    0U
  },
};


/* 
   The over all initialization data for the LIN driver. 
   The user configured Lin driver initialization structure.
*/
const Lin_17_AscLin_ConfigType  Lin_ConfigRoot[1] = 
 {
   {
      Lin_kChannelConfig0,
      1U,
   }  
 };

#define LIN_17_ASCLIN_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"



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
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

