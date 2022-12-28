/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : KNWHAL                                                  */
/* !Description     : Knock Window Layer                                      */
/*                                                                            */
/* !File            : KNWHAL_I.h                                              */
/* !Description     : Contains internal variables functions and defines of    */
/*                    the KNWHAL component                                    */
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
 * %PID: P2017_BSW:0A170699.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/
#ifndef KNWHAL_I_H
#define KNWHAL_I_H

#include "Std_Types.h"
#include "CRKHAL.h"
#include "KNWHAL_CFG.h"
#include "KNWHAL_dsadc_cfg.h"

/*lint -esym(960,8.8) */
/*-------------------------------------------------------------------------
    Defines
   -------------------------------------------------------------------------*/

#define KNWHAL_u8DEF_INP_STAGE_GAIN_IDX   (0U)                         /* 0x00 */
#define KNWHAL_u16_1_DEG_FOR_MOD_ON       CRKHAL_u16COMMON_ANGLE_RESOL /* 64 */
#define KNWHAL_u16ENGINE_CYCLE            CRKHAL_u16ENGINE_CYCLE /* 46080U */

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

extern volatile boolean KNWHAL_bDigitalWindow;
extern volatile boolean KNWHAL_bKnwAcquisitionRunning;
extern boolean          KNWHAL_bKnwInitialized;
extern boolean          KNWHAL_bKnwModulatorOnWindow;

#define KNWHAL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "KNWHAL_MemMap.h"

#define KNWHAL_START_SEC_VAR_CLEARED_32BIT
#include "KNWHAL_MemMap.h"

extern uint32          KNWHAL_u32SampleTblAddress;
extern volatile uint32 KNWHAL_u32SampleTblMaxSize;
extern volatile uint32 KNWHAL_u32SamplingWinIdxTblAddr;
extern volatile uint32 KNWHAL_u32SamplingWinTblAddress;


#define KNWHAL_STOP_SEC_VAR_CLEARED_32BIT
#include "KNWHAL_MemMap.h"


#define KNWHAL_START_SEC_VAR_CLEARED_16BIT
#include "KNWHAL_MemMap.h"

extern uint16          KNWHAL_u16KnockSamplePeriod;

#define KNWHAL_STOP_SEC_VAR_CLEARED_16BIT
#include "KNWHAL_MemMap.h"


#define KNWHAL_START_SEC_VAR_CLEARED_8BIT
#include "KNWHAL_MemMap.h"

extern volatile uint8 KNWHAL_u8SamplingWinIdx;
extern volatile uint8 KNWHAL_u8SamplingWinNr;
extern uint8          KNWHAL_u8KnockClockDividor;
extern uint8          KNWHAL_u8KnockOverSamplingRate;

#define KNWHAL_STOP_SEC_VAR_CLEARED_8BIT
#include "KNWHAL_MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
   -------------------------------------------------------------------------*/
#define KNWHAL_START_SEC_CODE
#include "KNWHAL_MemMap.h"

void   KNWHAL_vidDeactivateResources(void);
void   KNWHAL_vidInitSamplePeriod(void);
void   KNWHAL_vidItKnockWindow(void);
void   KNWHAL_vidWriteGainOutputLevel(uint8 u8GainValue);
uint32 KNWHAL_u32GetOsrFromTbl(const IfxDsadc_OsrTbl *Tbl, uint8 u8Count,
                               uint32 u32Period, uint32 *pu32Index);
void KNWHAL_vidInitDma(Dma_ChannelType Channel);

#define KNWHAL_STOP_SEC_CODE
#include "KNWHAL_MemMap.h"


#endif /* KNWHAL_I_H */

/*-------------------------------- end of file -------------------------------*/
