/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : KNWHAL                                                  */
/* !Description     : Knock Window Layer                                      */
/*                                                                            */
/* !File            : KNWHAL.c                                                */
/* !Description     : Knock Window Layer variables definition                 */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;
 * <Revision>
 * %PID: P2017_BSW:0A170695.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/
#include "STD_TYPES.h"
#include "KNWHAL_CFG.h"
#include "STD_TYPES.h"
#include "KNWHAL.h"
#include "KNWHAL_I.h"

/*-------------------------------------------------------------------------
    Defines
   -------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Typedef
   -------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
   -------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
   -------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
   -------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
   -------------------------------------------------------------------------*/
#define KNWHAL_START_SEC_VAR_CLEARED_BOOLEAN
#include "KNWHAL_MemMap.h"

volatile boolean KNWHAL_bDigitalWindow;
volatile boolean KNWHAL_bKnwAcquisitionRunning;
boolean          KNWHAL_bKnwInitialized;
boolean          KNWHAL_bKnwModulatorOnWindow;

#define KNWHAL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "KNWHAL_MemMap.h"

#define KNWHAL_START_SEC_VAR_CLEARED_8BIT
#include "KNWHAL_MemMap.h"

uint8 KNWHAL_u8KnockClockDividor;
uint8 KNWHAL_u8KnockOverSamplingRate;

volatile uint8 KNWHAL_u8SamplingWinIdx;
volatile uint8 KNWHAL_u8SamplingWinNr;
#define KNWHAL_STOP_SEC_VAR_CLEARED_8BIT
#include "KNWHAL_MemMap.h"

#define KNWHAL_START_SEC_VAR_CLEARED_32BIT
#include "KNWHAL_MemMap.h"

uint32          KNWHAL_u32SampleTblAddress;
volatile uint32 KNWHAL_u32SampleTblMaxSize;
volatile uint32 KNWHAL_u32SamplingWinIdxTblAddr;
volatile uint32 KNWHAL_u32SamplingWinTblAddress;

#define KNWHAL_STOP_SEC_VAR_CLEARED_32BIT
#include "KNWHAL_MemMap.h"

#define KNWHAL_START_SEC_VAR_CLEARED_16BIT
#include "KNWHAL_MemMap.h"

uint16          KNWHAL_u16KnockSamplePeriod;

#define KNWHAL_STOP_SEC_VAR_CLEARED_16BIT
#include "KNWHAL_MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
   -------------------------------------------------------------------------*/
