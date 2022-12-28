/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : KNWHAL                                                  */
/* !Description     : Knock Window Layer                                      */
/*                                                                            */
/* !File            : KNWHAL.h                                                */
/* !Description     : KNWHAL component defines and prototypes                 */
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
 * %PID: P2017_BSW:0A170698.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef KNWHAL_H
#define KNWHAL_H

#include "STD_TYPES.h"
#include "KNWHAL_I.h"
#include "KNWHAL_CFG.h"

/*-------------------------------------------------------------------------
    Defines
   -------------------------------------------------------------------------*/

#define KNWHAL_u8INPUT_STAGE_IDX_0        (0U)    /* 0 */
#define KNWHAL_u8INPUT_STAGE_IDX_1        (1U)    /* 1 */
#define KNWHAL_u8INPUT_STAGE_IDX_10       (10U)   /* 10 */
#define KNWHAL_u8INPUT_STAGE_IDX_11       (11U)   /* 11 */
#define KNWHAL_u8INPUT_STAGE_IDX_12       (12U)   /* 12 */
#define KNWHAL_u8INPUT_STAGE_IDX_13       (13U)   /* 13 */
#define KNWHAL_u8INPUT_STAGE_IDX_14       (14U)   /* 14 */
#define KNWHAL_u8INPUT_STAGE_IDX_15       (15U)   /* 15 */
#define KNWHAL_u8INPUT_STAGE_IDX_2        (2U)    /* 2 */
#define KNWHAL_u8INPUT_STAGE_IDX_3        (3U)    /* 3 */
#define KNWHAL_u8INPUT_STAGE_IDX_4        (4U)    /* 4 */
#define KNWHAL_u8INPUT_STAGE_IDX_5        (5U)    /* 5 */
#define KNWHAL_u8INPUT_STAGE_IDX_6        (6U)    /* 6 */
#define KNWHAL_u8INPUT_STAGE_IDX_7        (7U)    /* 7 */
#define KNWHAL_u8INPUT_STAGE_IDX_8        (8U)    /* 8 */
#define KNWHAL_u8INPUT_STAGE_IDX_9        (9U)    /* 9 */

#define IFX_KNWHAL_DMA_PROAT_ONE_TRANSFER /*(0xFFF7FFFFU)*/ (~( (uint32)IFX_DMA_CH_CHCFGR_RROAT_MSK \
                                                                << (uint8)IFX_DMA_CH_CHCFGR_RROAT_OFF) )
#define IFX_KNWHAL_DMA_PERIPHERAL         /*(0xEFFFFFFFU)*/ (~( (uint32)IFX_DMA_CH_CHCFGR_PRSEL_MSK \
                                                                << (uint8)IFX_DMA_CH_CHCFGR_PRSEL_OFF) )
#define IFX_KNWHAL_DMA_PRIORITY           /*(0x3FFFFFFFU)*/ (~( (uint32)IFX_DMA_CH_CHCFGR_DMAPRIO_MSK \
                                                                << (uint8)IFX_DMA_CH_CHCFGR_DMAPRIO_OFF) )
#define IFX_KNWHAL_DMA_MODE_CONTINUOUS    /*(0xFFEFFFFFU)*/ (~( (uint32)IFX_DMA_CH_CHCFGR_CHMODE_MSK \
                                                                << (uint8)IFX_DMA_CH_CHCFGR_CHMODE_OFF) )
/*-------------------------------------------------------------------------
    Prototypes
   -------------------------------------------------------------------------*/
#define KNWHAL_START_SEC_CODE
#include "KNWHAL_MemMap.h"

void           KNWHAL_vidCrkSyncLostEntry(void);
void           KNWHAL_vidInit(void);
void           KNWHAL_vidSetSampleTblPrms(uint16 *pau16SampleTbl, uint32 u32SampleTblMaxSize);
void           KNWHAL_vidSetSamplingWinIdxTbl(uint32 *pau32SamplingWinIdxTbl);
void           KNWHAL_vidWriteSamplePeriod(uint16 u16SamplePeriod);
Std_ReturnType KNWHAL_udtSetSamplingWinPrms(uint16 *pau16SamplingWinTbl, uint8 u8SamplingWinNr);
Std_ReturnType KNWHAL_udtWriteInputStageGain(uint8 u8InputStageGainIdx);
Std_ReturnType KNWHAL_udtSamplingWinTrigger(void);

#define KNWHAL_STOP_SEC_CODE
#include "KNWHAL_MemMap.h"


#endif /* KNWHAL_H */

/*-------------------------------- end of file -------------------------------*/
