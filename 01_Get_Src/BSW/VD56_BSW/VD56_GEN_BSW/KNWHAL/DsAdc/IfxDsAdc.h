/******************************************************************************/
/* !Layer          : HAL                                                      */
/* !Component      : DSADC                                                    */
/* !Description    : DSADC driver                                             */
/*                                                                            */
/* !File           : IfxDsAdc.h                                               */
/* !Description    : DSADC driver defines and prototypes                      */
/*                                                                            */
/* !Reference      :                                                          */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A170703.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IFXDSADC_H_
#define IFXDSADC_H_

#include "IfxDsadc_reg.h"
#include "IfxDsadc_bf.h"
#include "Mcal_DmaLib.h"

#define IFX_DSADC_SRC_SRM_SRPN_MASK ~(IFX_SRC_SRCR_SRPN_MSK << IFX_SRC_SRCR_SRPN_OFF)
#define IFX_DSADC_SRC_SRM_TOS_MASK  ~(IFX_SRC_SRCR_TOS_MSK << IFX_SRC_SRCR_TOS_OFF)
#define IFX_DSADC_CH_SRGM_MASK      ~(IFX_DSADC_CH_FCFGC_SRGM_MSK << IFX_DSADC_CH_FCFGC_SRGM_OFF)
#define IFX_DSADC_CH_DIVM_MASK      ~(IFX_DSADC_CH_MODCFG_DIVM_MSK << IFX_DSADC_CH_MODCFG_DIVM_OFF)
#define IFX_DSADC_CH_CFMDF_MASK     ~(IFX_DSADC_CH_FCFGC_CFMDF_MSK << IFX_DSADC_CH_FCFGC_CFMDF_OFF)

#define IFXDSADC_TRG_DIS            (0U)
#define IFXDSADC_TRG_ENA            (1U)

/* ADC module responds to the sleep mode request from MCU driver */
#define IFXDSADC_SLEEP_MODE_ACCEPT  (0U)
/* Sleep mode request from MCU driver is rejected, module remains in its current
   state */
#define IFXDSADC_SLEEP_MODE_REJECT  (1U)
#define IFXDSADC_CFMSV_DECIMATION   (4U)

#define IfxDSADC_GLOBCFG_MASK(DsAdcMcSel, DsAdcLosup) \
   (uint32)( (uint32)(DsAdcMcSel)                     \
             | (uint32)( (uint32)DsAdcLosup << 20U)   \
           )


/* Notification Enable / Disable */
#define IFXDSADC_NOTIF_DIS     (0U)
#define IFXDSADC_NOTIF_ENA     (1U)

#define  IFXDSADCFIRSHIFT_NONE (0U)
#define  IFXDSADCFIRSHIFT_1    (1U)


typedef enum
{
   IfxDsadcSts_uninit     = 0U, /* adc not initialised */
   IfxDsadcSts_busy       = 1U, /* the resource is busy */
   IfxDsadcSts_idle       = 2U, /* the resource is idle waiting for next request*/
   IfxDsadcSts_sampling   = 3U, /* the channel is being sampled */
   IfxDsadcSts_conversion = 4U, /* the channel is being converted */
   IfxDsadcSts_completed  = 5U  /* the channel group conversion is completed */
} IfxDsadcSts;

/** \brief Channels */
typedef enum
{
   IfxDsadc_ChannelId_0 = 0U,            /**< \brief Channel 0 */
   IfxDsadc_ChannelId_1 = 1U,            /**< \brief Channel 1 */
   IfxDsadc_ChannelId_2 = 2U,            /**< \brief Channel 2 */
   IfxDsadc_ChannelId_3 = 3U,            /**< \brief Channel 3 */
   IfxDsadc_ChannelId_4 = 4U,            /**< \brief Channel 4 */
   IfxDsadc_ChannelId_5 = 5U,            /**< \brief Channel 5 */
   IfxDsadc_ChannelId_6 = 6U,            /**< \brief Channel 6 */
   IfxDsadc_ChannelId_7 = 7U,            /**< \brief Channel 7 */
   IfxDsadc_ChannelId_8 = 8U,            /**< \brief Channel 8 */
   IfxDsadc_ChannelId_9 = 9U             /**< \brief Channel 9 */
} IfxDsadc_ChannelId;

#define     IFXDSADC_MODULARCLK_NOSOURCE   (0U)
#define     IFXDSADC_MODULARCLK_FDSD       (1U)
#define     IFXDSADC_MODULARCLK_FPLLFR     (2U)
#define     IFXDSADC_MODULARCLK_FOSC0      (3U)

#define     IFXDSADC_LOWSUPVOLTAGE_5V      (0U)
#define     IFXDSADC_LOWSUPVOLTAGE_33V     (1U)

#define     IFXDSADC_COMMONMODEVOL_A_1P65  (0U)
#define     IFXDSADC_COMMONMODEVOL_B_2P0   (1U)
#define     IFXDSADC_COMMONMODEVOL_C_2P5   (2U)

#define     IFXDSADC_MODULATORCFG_NORMAL   (0U)
#define     IFXDSADC_MODULATORCFG_UNKNOWN  (1U)

#define     IFXDSADC_INPUTPINSEL_A         (0U)
#define     IFXDSADC_INPUTPINSEL_B         (1U)
#define     IFXDSADC_INPUTPINSEL_C         (2U)
#define     IFXDSADC_INPUTPINSEL_D         (3U)


#define   IFXDSADC_MUXCTRL_SOFTWARE        (0U)
#define   IFXDSADC_MUXCTRL_FALLING_TRIGGER (1U)
#define   IFXDSADC_MUXCTRL_RISING_TRIGGER  (2U)
#define   IFXDSADC_MUXCTRL_ANY             (3U)

#define   IFXDSADC_MUXACTIONCTRL_PRESET    (0U)
#define   IFXDSADC_MUXACTIONCTRL_SINGLE    (1U)

#define   IFXDSADC_GAINSEL_1               (0U)
#define   IFXDSADC_GAINSEL_2               (1U)
#define   IFXDSADC_GAINSEL_4               (2U)
#define   IFXDSADC_GAINSEL_8               (3U)
#define   IFXDSADC_GAINSEL_16              (4U)

#define   IFXDSADC_DEMODINPUTSEL_SINGLE    (0U)
#define   IFXDSADC_DEMODINPUTSEL_COMBINE   (1U)
#define   IFXDSADC_DEMODINPUTSEL_A_DIRECT  (2U)
#define   IFXDSADC_DEMODINPUTSEL_A_INVERT  (3U)
#define   IFXDSADC_DEMODINPUTSEL_B_DIRECT  (4U)
#define   IFXDSADC_DEMODINPUTSEL_B_INVERT  (5U)


#define   IFXDSADC_TRIGGERSEL_DSADC_TRIG0  (0U)
#define   IFXDSADC_TRIGGERSEL_DSADC_TRIG1  (1U)
#define   IFXDSADC_TRIGGERSEL_ADC_TRIG0    (2U)
#define   IFXDSADC_TRIGGERSEL_ADC_TRIG1    (3U)
#define   IFXDSADC_TRIGGERSEL_INPUTE       (4U)
#define   IFXDSADC_TRIGGERSEL_INPUTF       (5U)
#define   IFXDSADC_TRIGGERSEL_INPUTG       (6U)
#define   IFXDSADC_TRIGGERSEL_INPUTH       (7U)

/* Channel and Filter Configuration */
#define   IFXDSADC_DATASHIFTCTRL_NONE      (0U)
#define   IFXDSADC_DATASHIFTCTRL_SHIFT1    (1U)
#define   IFXDSADC_DATASHIFTCTRL_SHIFT2    (2U)
#define   IFXDSADC_DATASHIFTCTRL_SHIFT3    (3U)


#define   IFXDSADC_COMBFILTERCFG_COMB1     (0U)
#define   IFXDSADC_COMBFILTERCFG_COMB2     (1U)
#define   IFXDSADC_COMBFILTERCFG_COMB3     (2U)
#define   IFXDSADC_COMBFILTERCFG_COMBF     (3U)


#define   IFXDSADC_SRCGEN_NEVER            (0U)
#define   IFXDSADC_SRCGEN_GATEHIGH         (1U)
#define   IFXDSADC_SRCGEN_GATELOW          (2U)
#define   IFXDSADC_SRCGEN_ALWAYS           (3U)


/* Type definition for ADC notification function pointer */
typedef void (*IfxDsadc_NotifFctPtrType)(IfxDsadc_ChannelId Id);

#define   IFXDSADC_INPUTLINECFG_INPUT      (0U)
#define   IFXDSADC_INPUTLINECFG_DISCONNECT (1U)
#define   IFXDSADC_INPUTLINECFG_VCM        (2U)
#define   IFXDSADC_INPUTLINECFG_REFGND     (3U)

#define    IFXDSADC_SAMPLECLK_INTERNAL     (0U)
#define    IFXDSADC_SAMPLECLK_INP_A        (1U)
#define    IFXDSADC_SAMPLECLK_INP_B        (2U)
#define    IFXDSADC_SAMPLECLK_INP_C        (3U)


#define   IFXDSADC_CLKDIVIDER_FCLK_2       (0U)
#define   IFXDSADC_CLKDIVIDER_FCLK_4       (1U)
#define   IFXDSADC_CLKDIVIDER_FCLK_6       (2U)
#define   IFXDSADC_CLKDIVIDER_FCLK_8       (3U)
#define   IFXDSADC_CLKDIVIDER_FCLK_10      (4U)
#define   IFXDSADC_CLKDIVIDER_FCLK_12      (5U)
#define   IFXDSADC_CLKDIVIDER_FCLK_14      (6U)
#define   IFXDSADC_CLKDIVIDER_FCLK_16      (7U)
#define   IFXDSADC_CLKDIVIDER_FCLK_18      (8U)
#define   IFXDSADC_CLKDIVIDER_FCLK_20      (9U)
#define   IFXDSADC_CLKDIVIDER_FCLK_22      (10U)
#define   IFXDSADC_CLKDIVIDER_FCLK_24      (11U)
#define   IFXDSADC_CLKDIVIDER_FCLK_26      (12U)
#define   IFXDSADC_CLKDIVIDER_FCLK_28      (13U)
#define   IFXDSADC_CLKDIVIDER_FCLK_30      (14U)
#define   IFXDSADC_CLKDIVIDER_FCLK_32      (15U)

#define    IFXDSADC_GAINCALIB_OFF          (0U)
#define    IFXDSADC_GAINCALIB_ON           (1U)

#define   IFXDSADC_POWERCTRL_OFF           (0U)
#define   IFXDSADC_POWERCTRL_ON            (1U)

#define   IFXDSADC_TRIG_0_TOM0_6           (0U)
#define   IFXDSADC_TRIG_0_TOM0_7           (1U)
#define   IFXDSADC_TRIG_0_TOM0_13          (2U)
#define   IFXDSADC_TRIG_0_TOM0_14          (3U)
#define   IFXDSADC_TRIG_0_ATOM0_4          (4U)
#define   IFXDSADC_TRIG_0_ATOM0_5          (5U)
#define   IFXDSADC_TRIG_0_ATOM0_6          (6U)
#define   IFXDSADC_TRIG_0_ATOM0_7          (7U)


#define   IFXDSADC_TRIG_1_TOM2_6           (0U)
#define   IFXDSADC_TRIG_1_TOM2_7           (1U)
#define   IFXDSADC_TRIG_1_TOM2_13          (2U)
#define   IFXDSADC_TRIG_1_TOM2_14          (3U)
#define   IFXDSADC_TRIG_1_ATOM2_4          (4U)
#define   IFXDSADC_TRIG_1_ATOM2_5          (5U)
#define   IFXDSADC_TRIG_1_ATOM2_6          (6U)
#define   IFXDSADC_TRIG_1_ATOM2_7          (7U)

typedef struct
{
   uint16 Tos;
   uint8  priority;
} IfxDsadc_IrqSrcCfg;


typedef struct
{
   /* CLC.EDIS */
   uint8  AdcSleepModeEnable;
   uint32 GlobCfg;
   uint32 ChRunMod;
   /* max number of physical DS ADC channels available in the package - 6 incase of TC27x */
   uint32 TotCh;
} IfxDsadc_InitConfig;

typedef  struct
{
   /* IfxDsadc_ChannelId       Channel ;   */    /**< \brief Specifies the channel and group index: */
   Ifx_DSADC_CH_MODCFG     *ModulatorCfg;
   Ifx_DSADC_CH_DICFG      *DemodulCfg;
   uint16                   trigSel;
   uint16                   HwExtTrigOpSel;
   Ifx_DSADC_CH_FCFGM      *MainFilCfg;
   Ifx_DSADC_CH_FCFGC      *CombiFilCfg;
   /*  Function Notification after channel is converted  */
   IfxDsadc_NotifFctPtrType IfxDsadcNotifFuncPtr;
   /*  linear(0) or circular(1) buffer */
   uint8                    LinCircBufType;
   uint8                    Dma_BufferStatus;
} IfxDsadc_ChCfg;


void  IfxDsadc_Reset(void);
uint8 IfxDsadc_Init(IfxDsadc_InitConfig *ConfigPtr);
void  IfxDsadc_SetGain(IfxDsadc_ChannelId Channel, uint8 Gain);
void  IfxDsadc_InitCh(IfxDsadc_ChCfg *ConfigPtr, uint8 Channel);
void  IfxDsadc_DisableInterrupt(IfxDsadc_ChannelId Dsadc_Channel);
void  IfxDsadc_SetServiceReq(IfxDsadc_ChannelId Channel, uint16 Value);
void  IfxDsadc_SetClockDivider(IfxDsadc_ChannelId Channel, uint32 u32localDivM);
void  IxDsadc_SetOverSamplingRate(IfxDsadc_ChannelId Channel, uint32 u32localOsr);
void  IfxDsadc_EnableInterrupt(IfxDsadc_ChannelId Dsadc_Channel, Dma_ChannelType Channel);
#endif /* ifndef IFXDSADC_H_ */
/* IFXDSADC_H_ */
