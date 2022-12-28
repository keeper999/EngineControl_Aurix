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
**  $FILENAME   : Can_17_MCanP_PBCfg.c $                                     **
**                                                                            **
**  $CC VERSION : \main\22 $                                                 **
**                                                                            **
**  DATE, TIME: 2014-09-30, 16:07:53                                      **
**                                                                            **
**  GENERATOR : Build b131017-0205                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : CAN configuration generated out of ECU configuration       **
**                   file(Can_17_MCanP.bmd)                                   **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

/**  TRACEABILITY: [cover parentID=DS_NAS_PR69_PR469_PR122,DS_NAS_PR446]                      
                     [/cover]                                              **/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include CAN Driver Header File */
#include "Can_17_MCanP.h"

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

#define CAN_17_MCANP_START_SEC_POSTBUILDCFG
#include "MemMap.h"

/******************************************************************************/
                /* CAN Controller Baudrate Configurations */
/******************************************************************************/
                          /* Baudrate Setting */
   /* (uint16)((DIV8 << 15)|(TSEG2 << 12)|(TSEG1 << 8)|(SJW << 6)|(BRP)) */
   /* SJW   -> CanControllerSyncJumpWidth - 1                            */
   /* TSEG1 -> CanControllerPropSeg + CanControllerSeg1 - 1              */
   /* TSEG2 -> CanControllerSeg2 - 1                                     */
/******************************************************************************/


/* CanConfigSet_0 -> CAN_2 Baudrate Configuration */

static const Can_17_MCanP_ControllerBaudrateConfigType Can_kBaudrateConfig_0_0[] = 
{
  {
    /* Configured Baudrate -> 1000 kbps */
    /* Actual Baudrate     -> 1000.0 kbps */
    /* BRP   -> 9 */
    /* SJW   -> 1  */
    /* TSEG1 -> 6  */
    /* TSEG2 -> 1  */
    /* DIV8  -> 0  */
    0x1649U,
    1000U
  },
  {
    /* Configured Baudrate -> 500 kbps */
    /* Actual Baudrate     -> 500.0 kbps */
    /* BRP   -> 19 */
    /* SJW   -> 1  */
    /* TSEG1 -> 6  */
    /* TSEG2 -> 1  */
    /* DIV8  -> 0  */
    0x1653U,
    500U
  }
};

/* CanConfigSet_0 -> CAN_1 Baudrate Configuration */

static const Can_17_MCanP_ControllerBaudrateConfigType Can_kBaudrateConfig_0_1[] = 
{
  {
    /* Configured Baudrate -> 1000 kbps */
    /* Actual Baudrate     -> 1000.0 kbps */
    /* BRP   -> 9 */
    /* SJW   -> 1  */
    /* TSEG1 -> 6  */
    /* TSEG2 -> 1  */
    /* DIV8  -> 0  */
    0x1649U,
    1000U
  },
  {
    /* Configured Baudrate -> 500 kbps */
    /* Actual Baudrate     -> 500.0 kbps */
    /* BRP   -> 19 */
    /* SJW   -> 1  */
    /* TSEG1 -> 6  */
    /* TSEG2 -> 1  */
    /* DIV8  -> 0  */
    0x1653U,
    500U
  }
};

/* CanConfigSet_0 -> CAN_DEVAID Baudrate Configuration */

static const Can_17_MCanP_ControllerBaudrateConfigType Can_kBaudrateConfig_0_2[] = 
{
  {
    /* Configured Baudrate -> 1000 kbps */
    /* Actual Baudrate     -> 1000.0 kbps */
    /* BRP   -> 9 */
    /* SJW   -> 1  */
    /* TSEG1 -> 6  */
    /* TSEG2 -> 1  */
    /* DIV8  -> 0  */
    0x1649U,
    1000U
  },
  {
    /* Configured Baudrate -> 500 kbps */
    /* Actual Baudrate     -> 500.0 kbps */
    /* BRP   -> 19 */
    /* SJW   -> 1  */
    /* TSEG1 -> 6  */
    /* TSEG2 -> 1  */
    /* DIV8  -> 0  */
    0x1653U,
    500U
  }
};

/* CanConfigSet_0 -> CAN_3 Baudrate Configuration */

static const Can_17_MCanP_ControllerBaudrateConfigType Can_kBaudrateConfig_0_3[] = 
{
  {
    /* Configured Baudrate -> 1000 kbps */
    /* Actual Baudrate     -> 1000.0 kbps */
    /* BRP   -> 9 */
    /* SJW   -> 1  */
    /* TSEG1 -> 6  */
    /* TSEG2 -> 1  */
    /* DIV8  -> 0  */
    0x1649U,
    1000U
  },
  {
    /* Configured Baudrate -> 500 kbps */
    /* Actual Baudrate     -> 500.0 kbps */
    /* BRP   -> 19 */
    /* SJW   -> 1  */
    /* TSEG1 -> 6  */
    /* TSEG2 -> 1  */
    /* DIV8  -> 0  */
    0x1653U,
    500U
  }
};

static const Can_BaudrateConfigPtrType Can_kBaudrateConfig_0[] = 
{
  { &Can_kBaudrateConfig_0_0[0] },
  { &Can_kBaudrateConfig_0_1[0] },
  { &Can_kBaudrateConfig_0_2[0] },
  { &Can_kBaudrateConfig_0_3[0] },
};



/******************************************************************************/
            /* Loopback and receive input pin selection setting */
/******************************************************************************/

/* Config 0 */
static const struct Can_NPCRValueType Can_kNPCR_0[] = 
{
  /* LoopBack Disabled, RXDCANxB */
  { 1U },
  /* LoopBack Disabled, RXDCANxB */
  { 1U },
  /* LoopBack Disabled, RXDCANxC */
  { 2U },
  /* LoopBack Disabled, RXDCANxB */
  { 1U },
};


/*******************************************************************************
               Transmit / Receive Hardware Object Configurations
********************************************************************************
 Tx Object -> { HW MO Id, [No. of Multiplexed MOs,] Hw Controller Id, Id Type }
        Rx Object -> { Mask, Msg Id, HW MO Id, Hw Controller Id, [Id Type] }
********************************************************************************
       Note: [1] If the associated CAN Controller is not activated then,
                   Hw Controller Id -> 255
             [2] If CanFilterMaskRef is not configured then, 
                   Mask -> 0x7ff - for STANDARD Msg Id Type
                           0x1fffffff - for EXTENDED/MIXED Msg Id Type
*******************************************************************************/

/* CanConfigSet_0 -> Transmit Hardware Object Configuration */
static const Can_TxHwObjectConfigType Can_kTxHwObjectConfig_0[] = 
{ 
  { 46U, 1U },
  { 47U, 1U },
  { 48U, 1U },
  { 49U, 1U },
  { 50U, 1U },
  { 51U, 1U },
  { 52U, 1U },
  { 53U, 1U },
  { 54U, 1U },
  { 55U, 1U },
  { 56U, 1U },
  { 57U, 1U },
  { 58U, 1U },
  { 59U, 1U },
  { 60U, 1U },
  { 61U, 1U },
  { 62U, 1U },
  { 63U, 1U },
  { 64U, 1U },
  { 65U, 1U },
  { 66U, 1U },
  { 67U, 1U },
  { 68U, 1U },
  { 69U, 1U },
  { 70U, 1U },
  { 71U, 1U },
  { 72U, 1U },
  { 73U, 1U },
  { 74U, 1U },
  { 75U, 1U },
  { 76U, 2U },
  { 77U, 2U },
  { 78U, 2U },
  { 79U, 2U },
  { 80U, 2U }
};

/* CanConfigSet_0 -> Receive Hardware Object Configuration */
static const Can_RxHwObjectConfigType Can_kRxHwObjectConfig_0[] = 
{
  { 0x7ffU, 0x572U, 0U, 1U },
  { 0x7ffU, 0x552U, 1U, 1U },
  { 0x7ffU, 0x495U, 2U, 1U },
  { 0x7ffU, 0x4f2U, 3U, 1U },
  { 0x7ffU, 0x3c9U, 4U, 1U },
  { 0x7ffU, 0x7f2U, 5U, 1U },
  { 0x7ffU, 0x4c8U, 6U, 1U },
  { 0x7ffU, 0x532U, 7U, 1U },
  { 0x7ffU, 0x55fU, 8U, 1U },
  { 0x7ffU, 0x492U, 9U, 1U },
  { 0x7ffU, 0x489U, 10U, 1U },
  { 0x7ffU, 0x50dU, 11U, 1U },
  { 0x7ffU, 0x5b2U, 12U, 1U },
  { 0x7ffU, 0x592U, 13U, 1U },
  { 0x7ffU, 0x0U, 14U, 1U },
  { 0x7ffU, 0x34dU, 15U, 1U },
  { 0x7ffU, 0x792U, 16U, 1U },
  { 0x7ffU, 0x30dU, 17U, 1U },
  { 0x7ffU, 0x92U, 18U, 1U },
  { 0x7ffU, 0x7dfU, 19U, 1U },
  { 0x7ffU, 0x7ffU, 20U, 1U },
  { 0x7ffU, 0x44dU, 21U, 1U },
  { 0x7ffU, 0x305U, 22U, 1U },
  { 0x7ffU, 0x6a8U, 23U, 1U },
  { 0x7ffU, 0x48eU, 24U, 1U },
  { 0x7ffU, 0xa8U, 25U, 1U },
  { 0x7ffU, 0xe0U, 26U, 1U },
  { 0x7ffU, 0x329U, 27U, 1U },
  { 0x7ffU, 0x3cdU, 28U, 1U },
  { 0x7ffU, 0x772U, 29U, 1U },
  { 0x7ffU, 0x349U, 30U, 1U },
  { 0x7ffU, 0x3adU, 31U, 1U },
  { 0x7ffU, 0x4d2U, 32U, 1U },
  { 0x7ffU, 0x57cU, 33U, 1U },
  { 0x7ffU, 0x612U, 34U, 1U },
  { 0x7ffU, 0x4b2U, 35U, 1U },
  { 0x7ffU, 0x38dU, 36U, 1U },
  { 0x7ffU, 0x7e0U, 37U, 1U },
  { 0x7ffU, 0x412U, 38U, 1U },
  { 0x7ffU, 0x432U, 39U, 1U },
  { 0x7ffU, 0x0U, 40U, 1U },
  { 0x7ffU, 0x0U, 41U, 1U },
  { 0x7ffU, 0x0U, 42U, 1U },
  { 0x7ffU, 0x50eU, 43U, 1U },
  { 0x7ffU, 0x708U, 44U, 1U },
  { 0x7ffU, 0x100U, 45U, 2U }
};


/*******************************************************************************
              CAN Controller <-> CAN Hardware Object Mapping
********************************************************************************
        { First Rx Hardware Object, No. of Rx Hardware Objects, 
          First Tx Hardware Object, No. of Tx Hardware Objects }
********************************************************************************
           Note: If the CAN controller is not activated then,
                 { 0U, 0U, 0U, 0U } will be generated
*******************************************************************************/

/* CanConfigSet_0 -> CAN Controller - CAN Hardware Object Mapping */
static const Can_ControllerMOMapConfigType Can_kControllerMOMapConfig_0[] = 
{
  { { 0U, 0U, 0U, 0U } },
  { { 0U, 45U, 46U, 30U } },
  { { 45U, 1U, 76U, 5U } },
  { { 0U, 0U, 0U, 0U } }
};



/*******************************************************************************
              CAN Controller Handling of Events : Interrupt/Polling
********************************************************************************
        { CanBusoffProcessing, CanRxProcessing, 
          CanTxProcessing, CanWakeupProcessing }
********************************************************************************
           Note: If the CAN controller is not activated then,
                 { 0U, 0U, 0U, 0U } will be generated
*******************************************************************************/

/* CanConfigSet_0 -> CAN Controller - Handling of Events */
static const Can_EventHandlingType Can_kEventHandlingConfig_0[] = 
{
 { { (CAN_POLLING),(CAN_POLLING),(CAN_POLLING),(CAN_INTERRUPT)} },
 { { (CAN_POLLING),(CAN_POLLING),(CAN_POLLING),(CAN_INTERRUPT)} },
 { { (CAN_INTERRUPT),(CAN_INTERRUPT),(CAN_INTERRUPT),(CAN_INTERRUPT)} },
 { { (CAN_POLLING),(CAN_POLLING),(CAN_POLLING),(CAN_INTERRUPT)} }
};



/*******************************************************************************
              CAN Controller <-> Default Baudrate Mapping
********************************************************************************
          { NBTR Register Settings, Default Baudrate in kbps }
*******************************************************************************/

/* CanConfigSet_0 -> CAN Controller - default baudrate mapping */
static const Can_17_MCanP_ControllerBaudrateConfigType Can_kDefaultBaudrateConfig_0[] = 
{
  /* CAN Controller 0 :
     Configured Baudrate -> 500 kbps
     Actual Baudrate     -> 500.0 kbps */
  { 0x1653U, 500U },
  /* CAN Controller 1 :
     Configured Baudrate -> 500 kbps
     Actual Baudrate     -> 500.0 kbps */
  { 0x1653U, 500U },
  /* CAN Controller 2 :
     Configured Baudrate -> 1000 kbps
     Actual Baudrate     -> 1000.0 kbps */
  { 0x1649U, 1000U },
  /* CAN Controller 3 :
     Configured Baudrate -> 500 kbps
     Actual Baudrate     -> 500.0 kbps */
  { 0x1653U, 500U }
};




/******************************************************************************/
                      /* CAN Configuration Pointer */
/******************************************************************************/
      /* Over all CAN configurations in the array, pointer to one of the 
           configuration is passed as parameter to Can_Init API */   
/******************************************************************************/

const Can_17_MCanP_ConfigType Can_17_MCanP_ConfigRoot[] = 
{
  {
    /* Pointer to Loopback and receive input pin selection setting */
    &Can_kNPCR_0[0],

    /* Pointer to CAN Controller <-> Hardware Objects Mapping */
    &Can_kControllerMOMapConfig_0[0],

    /* Pointer to CAN Controller Handling of Events : Interrupt/Polling */
    &Can_kEventHandlingConfig_0[0],

    /* Pointer to Controller Baudrate Configuration */
    &Can_kBaudrateConfig_0[0],

    /* Pointer to default baudrate configuration */
    &Can_kDefaultBaudrateConfig_0[0],

    /* Pointer to Configuration of transmit hardware objects */
    &Can_kTxHwObjectConfig_0[0],

    /* Pointer to Configuration of receive hardware objects */
    &Can_kRxHwObjectConfig_0[0],


    /* CAN Module clock configuration : Fractional Divider Register setting */
    /* NORMAL_DIVIDER - Bit 14 is set */
    /* CanClockStepValue 1023 (0x3ff) is assigned to bit 0-9. */
    0x43ffU,

    /* Number of configured CAN controllers */
    4U,
  
    /* CanControllerId --> CanHwControllerId (MultiCAN+ Controller Id) */
    { 0U, 1U, 2U, 3U },
 
    /* CAN Controller-wise number of baudrate configurations */
    { 2U, 2U, 2U, 2U },

    /* Total number of Transmit Hardware Objects */
    35U,
  
    /* Total number of Receive Hardware Objects */
    46U,
  
    /* Number of Receive Rx MOs + Rx FIFO MOs */
    46U,

    /* Transmit Hardware Objects Offset Kernel wise */
    { 46U, 0U },

    /* Receive Hardware Objects Offset Kernel wise */
    { 0U, 46U },

    /* Number of Rx FIFO MOs Kernel wise*/
    { 0U, 0U },

    /* Last MSPND register to be scanned for Rx MOs */
    1U,
  
    /* First MSPND register to be scanned for Tx MOs */
    1U,
  
    /* Last MSPND register to be scanned for Tx MOs */
    2U,

  }
};

#define CAN_17_MCANP_STOP_SEC_POSTBUILDCFG
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

