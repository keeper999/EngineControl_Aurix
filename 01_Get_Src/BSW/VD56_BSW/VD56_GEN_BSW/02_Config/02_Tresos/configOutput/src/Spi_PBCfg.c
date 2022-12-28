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
**  FILENAME  : Spi_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\72 $                                                 **
**                                                                            **
**  DATE, TIME: 2014-11-07, 12:35:27                                         **
**                                                                            **
**  GENERATOR : Build b131017-0205                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SPI configuration generated out of ECU configuration       **
**                 file                                                       **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include SPI Module File */
/* [cover parentID=DS_NAS_SPI_PR699,DS_NAS_SPI_PR709] */

#include "Spi.h"
/* Inclusion of Mcal Specific Global Header File */
#include "Mcal.h"

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
/* Violates MISRA Required Rule 16.9,
            function identifier used without '&' or parenthisized parameter list
           when using function pointer in configurations
*/

/*
                     Container: SpiChannelConfiguration
*/
#define SPI_START_SEC_POSTBUILDCFG
/*
 * To be used for global or static constants (unspecified size)
*/
#include "MemMap.h"
/*
Configuration : Channel Configuration Constant Structure.
The IB Channels are configured first followed by EB.
*/
static const Spi_ChannelConfigType Spi_kChannelConfig0[] =
{
/* IB Channel: L9781_ASIC_1_CH Configuration */
  {
    /*IB Channels : Number of IB Buffers*/
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000,
    /* Data Configuration */
    Spi_DataConfig(32U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
    (Spi_NumberOfDataType)4,
        /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_IB_BUFFER,
  },
/* IB Channel: L9781_ASIC_2_CH Configuration */
  {
    /*IB Channels : Number of IB Buffers*/
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000,
    /* Data Configuration */
    Spi_DataConfig(32U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
    (Spi_NumberOfDataType)4,
        /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_IB_BUFFER,
  },
/* IB Channel: CJ135_U2450_SPI_CHANNEL Configuration */
  {
    /*IB Channels : Number of IB Buffers*/
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
    (Spi_NumberOfDataType)2,
        /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_IB_BUFFER,
  },
/* IB Channel: TLF35584_CH Configuration */
  {
    /*IB Channels : Number of IB Buffers*/
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
    (Spi_NumberOfDataType)2,
        /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_IB_BUFFER,
  },
/* IB Channel: L9960_U2000_CH Configuration */
  {
    /*IB Channels : Number of IB Buffers*/
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
    (Spi_NumberOfDataType)2,
        /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_IB_BUFFER,
  },
/* IB Channel: L9960_U2001_CH Configuration */
  {
    /*IB Channels : Number of IB Buffers*/
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
    (Spi_NumberOfDataType)2,
        /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_IB_BUFFER,
  },
/* IB Channel: L9960_U2002_CH Configuration */
  {
    /*IB Channels : Number of IB Buffers*/
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
    (Spi_NumberOfDataType)2,
        /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_IB_BUFFER,
  },

};

/*
                    Container: SpiJobConfiguration
*/
/* Notification Function of CJ135_U2450_SPI_JOB is NULL_PTR */
/* Notification Function of TLF35584_JOB is NULL_PTR */
/* Notification Function of L9960_U2000_SPI_JOB is NULL_PTR */
/* Notification Function of L9960_U2001_SPI_JOB is NULL_PTR */
/* Notification Function of L9960_U2002_SPI_JOB is NULL_PTR */
/* Notification Function of L9781_ASIC_1_JOB is NULL_PTR */
/* Notification Function of L9781_ASIC_2_JOB is NULL_PTR */


/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: CJ135_U2450_SPI_JOB*/
static const Spi_ChannelType CJ135_U2450_SPI_JOB_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_CJ135_U2450_SPI_CHANNEL,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: TLF35584_JOB*/
static const Spi_ChannelType TLF35584_JOB_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_TLF35584_CH,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: L9960_U2000_SPI_JOB*/
static const Spi_ChannelType L9960_U2000_SPI_JOB_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_L9960_U2000_CH,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: L9960_U2001_SPI_JOB*/
static const Spi_ChannelType L9960_U2001_SPI_JOB_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_L9960_U2001_CH,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: L9960_U2002_SPI_JOB*/
static const Spi_ChannelType L9960_U2002_SPI_JOB_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_L9960_U2002_CH,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: L9781_ASIC_1_JOB*/
static const Spi_ChannelType L9781_ASIC_1_JOB_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_L9781_ASIC_1_CH,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: L9781_ASIC_2_JOB*/
static const Spi_ChannelType L9781_ASIC_2_JOB_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_L9781_ASIC_2_CH,
  SPI_CHANNEL_LINK_DELIMITER
};

/*
Configuration: Job Configuration Constant Structure.
*/
static const Spi_JobConfigType Spi_kJobConfig0[] =
{

/* Job: CJ135_U2450_SPI_JOB Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    CJ135_U2450_SPI_JOB_ChannelLinkPtr,
    /* Baud Rate (2000000 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x0U), /*Q*/(0x0U),
              /*A*/(0x3U), /*B*/(0x3U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x00,/*IDLE*/ 0x01,
        /*LPRE*/0x01, /*LEAD*/0x04,
        /*TPRE*/0x00, /*TRAIL*/0x03),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL8 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    	
  },
/* Job: TLF35584_JOB Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    TLF35584_JOB_ChannelLinkPtr,
    /* Baud Rate (625000 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x0U), /*Q*/(0x3U),
              /*A*/(0x3U), /*B*/(0x1U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x00,/*IDLE*/ 0x01,
        /*LPRE*/0x01, /*LEAD*/0x07,
        /*TPRE*/0x01, /*TRAIL*/0x07),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_TRAIL),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL10 << 4U) | (SPI_QSPI0_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    	
  },
/* Job: L9960_U2000_SPI_JOB Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    L9960_U2000_SPI_JOB_ChannelLinkPtr,
    /* Baud Rate (625000 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x0U), /*Q*/(0x3U),
              /*A*/(0x3U), /*B*/(0x2U), /*C*/(0x2U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x00,/*IDLE*/ 0x01,
        /*LPRE*/0x01, /*LEAD*/0x04,
        /*TPRE*/0x01, /*TRAIL*/0x04),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL4 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    	
  },
/* Job: L9960_U2001_SPI_JOB Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    L9960_U2001_SPI_JOB_ChannelLinkPtr,
    /* Baud Rate (625000 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x0U), /*Q*/(0x3U),
              /*A*/(0x3U), /*B*/(0x2U), /*C*/(0x2U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x00,/*IDLE*/ 0x01,
        /*LPRE*/0x01, /*LEAD*/0x04,
        /*TPRE*/0x01, /*TRAIL*/0x04),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL9 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    	
  },
/* Job: L9960_U2002_SPI_JOB Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    L9960_U2002_SPI_JOB_ChannelLinkPtr,
    /* Baud Rate (625000 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x0U), /*Q*/(0x3U),
              /*A*/(0x3U), /*B*/(0x2U), /*C*/(0x2U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x00,/*IDLE*/ 0x01,
        /*LPRE*/0x01, /*LEAD*/0x04,
        /*TPRE*/0x01, /*TRAIL*/0x04),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL7 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    	
  },
/* Job: L9781_ASIC_1_JOB Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    L9781_ASIC_1_JOB_ChannelLinkPtr,
    /* Baud Rate (5000000 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x0U), /*Q*/(0x0U),
              /*A*/(0x1U), /*B*/(0x0U), /*C*/(0x2U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x00,/*IDLE*/ 0x05,
        /*LPRE*/0x01, /*LEAD*/0x02,
        /*TPRE*/0x00, /*TRAIL*/0x05),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_HIGH,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL7 << 4U) | (SPI_QSPI4_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    	
  },
/* Job: L9781_ASIC_2_JOB Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    L9781_ASIC_2_JOB_ChannelLinkPtr,
    /* Baud Rate (5000000 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x0U), /*Q*/(0x0U),
              /*A*/(0x1U), /*B*/(0x0U), /*C*/(0x2U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x00,/*IDLE*/ 0x05,
        /*LPRE*/0x01, /*LEAD*/0x02,
        /*TPRE*/0x00, /*TRAIL*/0x05),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_HIGH,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL3 << 4U) | (SPI_QSPI4_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    	
  }
};

/*
                     Container: Spi_SequenceConfiguration
*/
/* Notification Function of Sequence: CJ135_U2450_SPI_SEQ */
extern void CJ135_vidTxConfirmation_U2450(void);
/* Notification Function of Sequence: TLF35584_SEQ */
extern void TLF35584_vidSpiEndNotification(void);
/* Notification Function of Sequence: L9960_U2000_SPI_SEQ */
extern void L9960_vidTxConfirmation_U2000(void);
/* Notification Function of Sequence: L9960_U2001_SPI_SEQ is NULL_PTR */
/* Notification Function of Sequence: L9960_U2002_SPI_SEQ is NULL_PTR */
/* Notification Function of Sequence: L9781_ASIC_1_SEQ */
extern void L9781_vidSpiRx_ST1(void);
/* Notification Function of Sequence: L9781_ASIC_2_SEQ */
extern void L9781_vidSpiRx_ST2(void);

/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: CJ135_U2450_SPI_SEQ */
static const Spi_JobType CJ135_U2450_SPI_SEQ_JobLinkPtr[] =
{
  SpiConf_SpiJob_CJ135_U2450_SPI_JOB,
  SPI_JOB_LINK_DELIMITER
};
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: TLF35584_SEQ */
static const Spi_JobType TLF35584_SEQ_JobLinkPtr[] =
{
  SpiConf_SpiJob_TLF35584_JOB,
  SPI_JOB_LINK_DELIMITER
};
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: L9960_U2000_SPI_SEQ */
static const Spi_JobType L9960_U2000_SPI_SEQ_JobLinkPtr[] =
{
  SpiConf_SpiJob_L9960_U2000_SPI_JOB,
  SPI_JOB_LINK_DELIMITER
};
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: L9960_U2001_SPI_SEQ */
static const Spi_JobType L9960_U2001_SPI_SEQ_JobLinkPtr[] =
{
  SpiConf_SpiJob_L9960_U2001_SPI_JOB,
  SPI_JOB_LINK_DELIMITER
};
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: L9960_U2002_SPI_SEQ */
static const Spi_JobType L9960_U2002_SPI_SEQ_JobLinkPtr[] =
{
  SpiConf_SpiJob_L9960_U2002_SPI_JOB,
  SPI_JOB_LINK_DELIMITER
};
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: L9781_ASIC_1_SEQ */
static const Spi_JobType L9781_ASIC_1_SEQ_JobLinkPtr[] =
{
  SpiConf_SpiJob_L9781_ASIC_1_JOB,
  SPI_JOB_LINK_DELIMITER
};
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: L9781_ASIC_2_SEQ */
static const Spi_JobType L9781_ASIC_2_SEQ_JobLinkPtr[] =
{
  SpiConf_SpiJob_L9781_ASIC_2_JOB,
  SPI_JOB_LINK_DELIMITER
};







/*
Configuration: Sequence Configuration Constant Structure.
*/
static const Spi_SequenceConfigType Spi_kSequenceConfig0[] =
{   /* Sequence: CJ135_U2450_SPI_SEQ Configuration */
  {
    /* Spi_SeqEndNotification */
    &CJ135_vidTxConfirmation_U2450,
    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    CJ135_U2450_SPI_SEQ_JobLinkPtr,
    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    NULL_PTR,
     /* This holds the total number of jobs linked to this sequence */
    1U,
  },
  /* Sequence: TLF35584_SEQ Configuration */
  {
    /* Spi_SeqEndNotification */
    &TLF35584_vidSpiEndNotification,
    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    TLF35584_SEQ_JobLinkPtr,
    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    NULL_PTR,
     /* This holds the total number of jobs linked to this sequence */
    1U,
  },
  /* Sequence: L9960_U2000_SPI_SEQ Configuration */
  {
    /* Spi_SeqEndNotification */
    &L9960_vidTxConfirmation_U2000,
    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    L9960_U2000_SPI_SEQ_JobLinkPtr,
    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    NULL_PTR,
     /* This holds the total number of jobs linked to this sequence */
    1U,
  },
  /* Sequence: L9960_U2001_SPI_SEQ Configuration */
  {
    /* Spi_SeqEndNotification */
    NULL_PTR,
    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    L9960_U2001_SPI_SEQ_JobLinkPtr,
    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    NULL_PTR,
     /* This holds the total number of jobs linked to this sequence */
    1U,
  },
  /* Sequence: L9960_U2002_SPI_SEQ Configuration */
  {
    /* Spi_SeqEndNotification */
    NULL_PTR,
    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    L9960_U2002_SPI_SEQ_JobLinkPtr,
    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    NULL_PTR,
     /* This holds the total number of jobs linked to this sequence */
    1U,
  },
  /* Sequence: L9781_ASIC_1_SEQ Configuration */
  {
    /* Spi_SeqEndNotification */
    &L9781_vidSpiRx_ST1,
    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    L9781_ASIC_1_SEQ_JobLinkPtr,
    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    NULL_PTR,
     /* This holds the total number of jobs linked to this sequence */
    1U,
  },
  /* Sequence: L9781_ASIC_2_SEQ Configuration */
  {
    /* Spi_SeqEndNotification */
    &L9781_vidSpiRx_ST2,
    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    L9781_ASIC_2_SEQ_JobLinkPtr,
    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    NULL_PTR,
     /* This holds the total number of jobs linked to this sequence */
    1U,
  }
};

static const Spi_DmaConfigType Spi_kDmaConfig0[]=
{

  { /* QSPI0 Module Hw Dma Config */
    DMA_CHANNEL1,  /* Tx */    DMA_CHANNEL0   /* Rx */  },

  { /* QSPI1 Module Hw Dma Config */
    DMA_CHANNEL3,  /* Tx */    DMA_CHANNEL2   /* Rx */  },

  { /* QSPI2 Module Hw Dma Config */
    DMA_CHANNEL5,  /* Tx */    DMA_CHANNEL4   /* Rx */  },

  { /* QSPI3 Module Hw Dma Config */
    DMA_CHANNEL7,  /* Tx */    DMA_CHANNEL6   /* Rx */  },

  { /* QSPI4 Module Hw Dma Config */
    DMA_CHANNEL9,  /* Tx */    DMA_CHANNEL8   /* Rx */  },

};

static const Spi_HWModuleConfigType Spi_kModuleConfig0[]=
{
  /* QSPI0 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      SPI_CLK_SLEEP_DISABLE,
      SPI_QSPI0_MRIS_SEL,
      &Spi_kDmaConfig0[0],
  },
  /* QSPI1 Module */
  {
    SPI_1_NOT_CONFIGURED,
    SPI_1_NOT_CONFIGURED,
    NULL_PTR,
  },
  /* QSPI2 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      SPI_CLK_SLEEP_DISABLE,
      SPI_QSPI2_MRIS_SEL,
      &Spi_kDmaConfig0[2],
  },
  /* QSPI3 Module */
  {
    SPI_3_NOT_CONFIGURED,
    SPI_3_NOT_CONFIGURED,
    NULL_PTR,
  },
  /* QSPI4 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      SPI_CLK_SLEEP_DISABLE,
      SPI_QSPI4_MRIS_SEL,
      &Spi_kDmaConfig0[4],
  },
};


const Spi_ConfigType Spi_ConfigRoot[1] =
{
  {
    Spi_kChannelConfig0,
    Spi_kJobConfig0,
    Spi_kSequenceConfig0,
    {
      &Spi_kModuleConfig0[0],
      &Spi_kModuleConfig0[1],
      &Spi_kModuleConfig0[2],
      &Spi_kModuleConfig0[3],
      &Spi_kModuleConfig0[4],
    },
    (Spi_ChannelType)(sizeof(Spi_kChannelConfig0) / \
                      sizeof(Spi_ChannelConfigType)),
    (Spi_JobType)(sizeof(Spi_kJobConfig0) / sizeof(Spi_JobConfigType)),
    (Spi_SequenceType)(sizeof(Spi_kSequenceConfig0) / \
                                        sizeof(Spi_SequenceConfigType)),
  }
};


#define SPI_STOP_SEC_POSTBUILDCFG
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
/* General Notes */
/*
SPI095: The code file structure shall not be defined within this specification
completely. At this point it shall be pointed out that the code-file structure
shall include the following file named:
- Spi_Lcfg.c – for link time and for post-build configurable parameters and
- Spi_PBcfg.c – for post build time configurable parameters.
These files shall contain all link time and post-build time configurable
parameters.
This file shall contain all link time and post-build time configurable
parameters.
For the implementation of VariantPC, the implementation stores the
pre compile time parameters that have to be defined as constants in this file.

SPI123: In this configuration, all Sequences declared are considered as Non
Interruptible Sequences. That means, their dedicated parameter
SPI_INTERRUPTIBLE_SEQUENCE (see SPI064 & SPI106) could be omitted or the
FALSE value should be used as default.

*/


